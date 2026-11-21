import os
ROOT=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))  # the repo
SCR=os.environ.get('SCRATCH','/tmp/fable-scratch')  # where the pipeline's intermediate files go
# second-stage edits applied to the ported draft (called from port.py before writing)
import re, json
S=SCR
def apply(s):
    pool=json.load(open(S+'/pooltypes.json'))
    # 1. pool constant types from the target's load widths
    def fix(m):
        t,sym,off=m.group(1),m.group(2),int(m.group(3))
        k=pool.get(f'{sym}+{off}')
        if not k: return m.group(0)
        k=k[0]
        if k in ('f64','f32','s32'): return f'F({k},&{sym},{off})'
        return m.group(0)
    s=re.sub(r'F\((\w+),&(D_8010[0-9A-F]{4}),(\d+)\)', fix, s)
    def fixdecl(m):
        t,sym=m.group(1),m.group(2); k=pool.get(f'{sym}+0')
        if k and k[0] in ('f64','f32','s32') and k[0]!=t: return f'extern {k[0]} {sym};'
        return m.group(0)
    s=re.sub(r'extern (\w+) (D_8010[0-9A-F]{4});', fixdecl, s)
    # 2. misc types
    s=s.replace('D_8029970A[_240] == 1','((s8 *)D_8029970A)[_240] == 1').replace('(_260 == 1)','(_260 == 1)')
    s=re.sub(r'(?<![\w&])D_80299718\[(\w+)\]', r'(*(f32 *)&D_80299718[\1])', s)
    s=s.replace('F(u8,&D_801FAA94,_223) != 0.0f','F(f32,&D_801FAA94,_223) != 0.0f')
    s=s.replace('*D_8029FA44','*(f32 *)D_8029FA44')
    s=s.replace('_146 = D_802900DC / D_801EF45C;','_146 = (f32)D_802900DC / D_801EF45C;')
    # 3. region A: per-frame deltas as float stores through locals
    old=re.search(r'F\(f32,&D_8029F398,\(FB \* 0xC\)\) = .*?\n_196 = FB;\n', s, re.S).group(0)
    new='''{ u8 *o = D_8029020C; s16 *fb = (s16 *)&FB;
F(f32,&D_8029F398,*fb * 0xC) = F(f32,o,60) - *(f32 *)&PC;
F(f32,&D_8029F39C,*fb * 0xC) = F(f32,o,64) - D_80290310;
F(f32,&D_8029F3A0,*fb * 0xC) = F(f32,o,68) - D_80290314;
F(f32,&D_8029F3A4,*fb * 0xC) = F(f32,o,60) - *(f32 *)&PC;
F(f32,&D_8029F3A8,*fb * 0xC) = F(f32,o,64) - D_80290310;
F(f32,&D_8029F3AC,*fb * 0xC) = F(f32,o,68) - D_80290314;
_196 = *fb; }
'''
    s=s.replace(old,new)
    s=s.replace('''F(s32,D_8029020C,356) = 0;
F(f32,D_8029020C,104) = 0.0f;
F(f32,D_8029020C,100) = 0.0f;
F(f32,D_8029020C,96) = 0.0f;''','''F(s32,D_8029020C,356) = 0;
F(f32,D_8029020C,96) = F(f32,D_8029020C,100) = F(f32,D_8029020C,104) = 0.0f;''')
    s=s.replace('f32 unused_[20];','f32 unused_[20];')
    s=s.replace('''_173 = D_80107F00;
if (D_80107EF4 < _98) {
_173 = _98;
}
F(s32,&D_8029F9A0,52) = (A8(f32,0) * D_80107EF8) / _173;''','''F(s32,&D_8029F9A0,52) = (A8(f32,0) * D_80107EF8) / ((D_80107EF4 < _98) ? (f64)_98 : D_80107F00);''')
    s=s.replace('*(f32 *)&PC','F(f32,&PC,0)')
    # round 3
    s=re.sub(r'(?m)^P3 = P3 \* (D_80107D58|D_80107D60|D_80107D70|F\(f64,&D_801080E8,4\));$', r'F(f32,&P3,0) = F(f32,&P3,0) * \1;', s)
    s=s.replace('_293 = (D_802900D8 * 0x24) + C8(s32,216);','_293 = C8(s32,216) + (D_802900D8 * 0x24);')
    s=s.replace('D_8029F9B0 += D_801EF458;','F(f32,&D_8029F9B0,0) += D_801EF458;')
    s=s.replace('D_8029F9A0 &= 0xFEFFFFFF;','F(s32,&D_8029F9A0,0) &= 0xFEFFFFFF;')
    s=re.sub(r'(?m)^s8 (_\d+);$', r's32 \1;', s)
    s=re.sub(r'(func_8016049C\([^;]*), A8\(s32,8\)\);', r'\1, A8(f32,8));', s)
    s=s.replace('F(s32,_294,12) * _139','F(f32,_294,12) * _139')
    s=s.replace('FA(f64,112)','FA(f32,112)')
    old=re.search(r'_243 = 0;\nloop_563:.*?F\(s32,&D_8029F9AC,-8\) = 0;\n\}\n\}\n', s, re.S).group(0)
    new=r"""for (_243 = 0; _243 < 4; _243++) {
_288 = *(s32 *)(D_802903B0 + _243 * 4);
if (_288 != NULL) {
_107 = F(f32,_288,0);
_110 = F(f32,_288,4);
_38 = F(f32,_288,8);
_21 = F(f32,_288,12);
if (((F(f32,&PC,0) * _107) + (D_80290310 * _110) + (D_80290314 * _38) + _21) * ((F(f32,&D_8029F9AC,0) * _107) + (D_8029F9B0 * _110) + (D_8029F9B4 * _38) + _21) < 0.0f) {
func_8017797C();
if (F(s32,&D_8029F9AC,-8) == (s32)((u8 *)&PC - 0x34)) {
F(s32,&D_8029F9AC,-8) = 0;
}
break;
}
}
}
"""
    s=s.replace(old,new)
    # round 4
    s=s.replace('(((D_8029F9A8 + B0(f32,112) + D_80107E90) < (D_80290310 - D_8029F9B0))','(((D_80290310 - D_8029F9B0) > (D_8029F9A8 + B0(f32,112) + D_80107E90))')
    s=re.sub(r'a\[2\] = 0\.0f;\na\[1\] = 0\.0f;\na\[0\] = 0\.0f;\nfunc_8015F910\(', 'a[0] = a[1] = a[2] = 0.0f;\nfunc_8015F910(', s)
    s=re.sub(r'func_8015F910\((.*), (D_80290094|D_802900A8), \2\);', r'func_8015F910(\1, *(volatile s32 *)&\2, *(volatile s32 *)&\2);', s)
    s=s.replace('F(f32,D_80290304,96) = 0.0f;\nF(f32,D_80290304,92) = 0.0f;\nF(f32,D_80290304,88) = 0.0f;','F(f32,D_80290304,88) = F(f32,D_80290304,92) = F(f32,D_80290304,96) = 0.0f;')
    s=s.replace('((_129 + F(f64,&D_80107C88,4)) < func_80148DB0(&PC, &D_8029F9AC))','(func_80148DB0(&PC, &D_8029F9AC) > (_129 + F(f64,&D_80107C88,4)))')
    s=s.replace("""switch (D_8028FBEC) {
case 0:
_232 = 0x18;
block_211:
func_80133998(&PD, _232, 1, 0, 0);
break;
case 2:
_232 = 0x3A;
goto block_211;
case 1:
_232 = 0xC;
goto block_211;
}""","""switch (D_8028FBEC) {
case 0:
func_80133998(&PD, 0x18, 1, 0, 0);
break;
case 2:
func_80133998(&PD, 0x3A, 1, 0, 0);
break;
case 1:
func_80133998(&PD, 0xC, 1, 0, 0);
break;
}""")
    # shared level index inside cases 33 and 36
    def hoist(s, start_marker, end_marker, var):
        i=s.index(start_marker); j=s.index(end_marker, i)
        blk=s[i:j]
        n=blk.count('(D_80202218 * 0x190)')+blk.count('D_80202218 * 0x190')
        blk=blk.replace('(D_80202218 * 0x190)', var).replace(var+' = '+var+';\n','')
        blk=blk.replace('_228 = D_80202218 * 0x190;\n','')
        blk=blk.replace(start_marker, start_marker+var+' = D_80202218 * 0x190;\n',1)
        print('hoisted', var, n)
        return s[:i]+blk+s[j:]
    s=hoist(s,'case 33:\n','case 34:\n','_228')
    s=hoist(s,'case 36:\n','case 44:\n','_i36')
    s=s.replace('\nu8 sp58;\n','\nu8 sp58;\n') 
    s=s.replace('s32 _228;\n','s32 _228;\ns32 _i36;\n',1)
    # round 5
    s=s.replace('D_8028FBDA -= 1;\nD_80290338 = 0.0f;\nD_80290334 = 0.0f;\nP3 = 0.0f;\n','F(s16,&D_8028FBDA,0) -= 1;\nF(f32,&P3,0) = D_80290334 = D_80290338 = 0.0f;\n')
    s=s.replace('if (F(f64,&D_80107DC0,4) < (D_80290310 - D_8029F9B0)) {','if (F(f64,&D_80107DC0,4) < (F(f32,&D_80290310,0) - F(f32,&D_8029F9B0,0))) {')
    s=s.replace('if (func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C) < (_73 * _73)) {','if ((_73 * _73) > func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C)) {')
    # round 6
    old=re.search(r'_94 = F\(f32,D_8029FA48,0\);\nvar_condition_bit = D_80107DF4 < _94;\n.*?D_8029F9D4 = _175;\n\} else \{\nD_8029F9D4 = \(D_801EEC40 \* D_80107E08\) / _151;\n\}\n', s, re.S).group(0)
    new="""_94 = F(f32,D_8029FA48,0);
_163 = (D_801EEC40 * F(f64,&D_80107DE8,4)) / _151;
if ((D_80107DF4 < _94) && !(_94 < D_80107DF8)) {
F(f32,&D_8029F9D4,0) = _163 / D_80107DF8;
} else if (D_80107DF4 < _94) {
F(f32,&D_8029F9D4,0) = _163 / _94;
} else {
F(f32,&D_8029F9D4,0) = _163 / D_80107E00;
}
} else {
F(f32,&D_8029F9D4,0) = (D_801EEC40 * D_80107E08) / _151;
}
"""
    s=s.replace(old,new)
    s=s.replace('F(f32,&P3,0) = D_80290334 = D_80290338 = 0.0f;\nD_8029F9D0 = P3;\nF(f32,&D_8029F9D0,4) = F(f32,&P3,4);\nF(f32,&D_8029F9D0,8) = F(f32,&P3,8);\nif (D_8028FBDA == 0) {','F(f32,&P3,0) = D_80290334 = D_80290338 = 0.0f;\n*(Words3 *)&D_8029F9D0 = *(Words3 *)&P3;\nif (F(s16,&D_8028FBDA,0) == 0) {')
    s=s.replace('f32 unused_[18];','f32 unused_[20];')
    # round 7
    s=s.replace("""_94 = F(f32,D_8029FA48,0);
_163 = (D_801EEC40 * F(f64,&D_80107DE8,4)) / _151;
if ((D_80107DF4 < _94) && !(_94 < D_80107DF8)) {
F(f32,&D_8029F9D4,0) = _163 / D_80107DF8;
} else if (D_80107DF4 < _94) {
F(f32,&D_8029F9D4,0) = _163 / _94;""","""_163 = (D_801EEC40 * F(f64,&D_80107DE8,4)) / _151;
if ((D_80107DF4 < F(f32,D_8029FA48,0)) && !(F(f32,D_8029FA48,0) < D_80107DF8)) {
F(f32,&D_8029F9D4,0) = _163 / D_80107DF8;
} else if (D_80107DF4 < F(f32,D_8029FA48,0)) {
F(f32,&D_8029F9D4,0) = _163 / F(f32,D_8029FA48,0);""")
    s=s.replace("""if (AC(s16,6) == 0x18) {
_113 = 4.0f;
} else {
_113 = -4.0f;
}
func_8016049C(((u8 *)&D_802903B0 - 0xD8), _113, A8(f32,8));""","""func_8016049C(((u8 *)&D_802903B0 - 0xD8), (AC(s16,6) == 0x18) ? 4.0f : -4.0f, A8(f32,8));""")
    s=s.replace("""F(s32,&D_8029F9A0,52) = (A8(f32,0) * D_80107EF8) / ((D_80107EF4 < _98) ? (f64)_98 : D_80107F00);""","""{ f64 t_ = A8(f32,0) * D_80107EF8; f64 dv_ = D_80107F00; if (D_80107EF4 < _98) dv_ = _98; F(s32,&D_8029F9A0,52) = t_ / dv_; }""")
    s=s.replace("func_80145298(F(s32,F(s32,C8(s32,200),12),52), F(f32,_285,76), F(s32,_292,0), F(s16,_292,2), F(s32,_285,12));","func_80145298(F(s32,F(s32,C8(s32,200),12),52), F(s32,_285,76), F(s16,_292,0), F(s16,_292,2), F(f32,_285,12));")
    s=s.replace("""_73 = (*(f32 *)&D_80299718[_238]) + D_801080C4;
if ((_73 * _73) > func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C)) {""","""if (func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C) < (((*(f32 *)&D_80299718[_238]) + D_801080C4) * ((*(f32 *)&D_80299718[_238]) + D_801080C4))) {""")
    # round 8
    s=s.replace("""if (func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C) < (((*(f32 *)&D_80299718[_238]) + D_801080C4) * ((*(f32 *)&D_80299718[_238]) + D_801080C4))) {""","""_73 = (*(f32 *)&D_80299718[_238]) + D_801080C4;
if (func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C) < (_73 * _73)) {""")
    s=s.replace("""func_8016049C(((u8 *)&D_802903B0 - 0xD8), (AC(s16,6) == 0x18) ? 4.0f : -4.0f, A8(f32,8));""","""if (AC(s16,6) == 0x18) {
func_8016049C(((u8 *)&D_802903B0 - 0xD8), 4.0f, A8(f32,8));
} else {
func_8016049C(((u8 *)&D_802903B0 - 0xD8), -4.0f, A8(f32,8));
}""")
    s=s.replace("""_163 = (D_801EEC40 * F(f64,&D_80107DE8,4)) / _151;
if ((D_80107DF4 < F(f32,D_8029FA48,0)) && !(F(f32,D_8029FA48,0) < D_80107DF8)) {
F(f32,&D_8029F9D4,0) = _163 / D_80107DF8;
} else if (D_80107DF4 < F(f32,D_8029FA48,0)) {
F(f32,&D_8029F9D4,0) = _163 / F(f32,D_8029FA48,0);
} else {
F(f32,&D_8029F9D4,0) = _163 / D_80107E00;
}""","""_94 = F(f32,D_8029FA48,0);
_163 = (D_801EEC40 * F(f64,&D_80107DE8,4)) / _151;
F(f32,&D_8029F9D4,0) = _163 / ((D_80107DF4 < _94) ? ((_94 < D_80107DF8) ? (f64)_94 : D_80107DF8) : D_80107E00);""")
    # case 36: struct copy, byte index, no hoisted index
    s=s.replace("""F(s32,D_80290304,132) = D_8029035C;
F(s32,D_80290304,136) = F(f32,&D_8029035C,4);
F(s32,D_80290304,140) = F(f32,&D_8029035C,8);""","""*(Words3 *)(D_80290304 + 132) = *(Words3 *)&D_8029035C;""")
    s=s.replace("F(s16,&D_80299960,(F(s16,F(s32,D_80290304,212),2) * 0x300)) = 0xA;","F(s16,&D_80299960,(F(s8,F(s32,D_80290304,212),2) * 0x300)) = 0xA;")
    i=s.index('case 36:\n'); j=s.index('case 44:\n', i)
    blk=s[i:j].replace('_i36 = D_80202218 * 0x190;\n','').replace('_i36','(D_80202218 * 0x190)')
    s=s[:i]+blk+s[j:]
    # round 9
    TAIL='if ((F(u8,&D_801FAAC8,(D_80202218 * 0x190)) != 0) && (D_801EC740 == 1)) {\nfunc_801764A8();\n}\n'
    s=s.replace('block_743:\n'+TAIL,TAIL)
    s=s.replace('goto block_743;\ncase 41:', TAIL+'break;\ncase 41:')
    i=s.index('case 44:\n'); j=s.index('case 37:\n', i)
    blk=s[i:j]
    if blk.endswith('break;\n'): blk=blk[:-len('break;\n')]+TAIL+'break;\n'; print('tail added to case 44')
    else: print('case 44 ends with:', repr(blk[-80:]))
    s=s[:i]+blk+s[j:]
    s=s.replace('F(s32,&D_8029F9A0,52) = t_ / dv_;','F(f32,&D_8029F9A0,52) = t_ / dv_;')
    s=s.replace('D_8029F9D8 = 0.0f;\nD_8029F9D0 = 0.0f;\n','F(f32,&D_8029F9D0,0) = D_8029F9D8 = 0.0f;\n')
    # round 10: globals the target addresses through a register are struct members in the original: cast every access
    import os
    GROUPS={'A':['D_802900DC','D_8028FBF8','D_8028FBFB','D_8028FBDA','D_8028FBEC','D_8028FBFA','D_8028FBEE','D_8029016C','D_802900E4','D_801ED3EC'],
            'B':['D_80290330','D_80290334','D_80290338','D_80290340','D_80290348','D_80290350','D_80290354'],
            'C':['D_8029F9A0','D_8029F9A4','D_8029F9AC','D_8029F9B0','D_8029F9B4','D_8029F9D0','D_8029F9D4','D_8029F9D8']}
    GROUPS['D']=GROUPS['A']+['D_80290330','D_80290334','D_80290348','D_80290350','D_80290354','D_8029F9A0','D_8029F9A4','D_8029F9AC','D_8029F9B0','D_8029F9B4','D_8029F9D4']
    STRUCTED=[x for g in os.environ.get('STRUCT_GROUPS','D') for x in GROUPS.get(g,[])]+[x for x in os.environ.get('STRUCT_EXTRA','').split(',') if x]
    s=s.replace('#define G(op,v)', '#define V(t,s) F(t,&s,0)\n#define G(op,v)',1)
    _old=['D_802900DC','D_8028FBF8','D_8028FBFB','D_8028FBDA','D_8028FBEC','D_8028FBFA','D_8028FBEE','D_80290330','D_80290334','D_80290338','D_80290340','D_80290348','D_80290350','D_80290354','D_8029F9A0','D_8029F9A4','D_8029F9AC','D_8029F9B0','D_8029F9B4','D_8029F9D0','D_8029F9D4','D_8029F9D8','D_8029016C','D_802900E4','D_801ED3EC']
    unit=open(ROOT+'/src/18020_1D7F0.c').read()
    def typeof(sym):
        for src in (s, unit):
            m=re.search(r'extern (\w+) [^;{}]*\b'+sym+r'\b[^;]*;', src)
            if m: return m.group(1)
        return None
    head,body=s[:s.index('\nif (D_802901B0 >= 0x28) {')], s[s.index('\nif (D_802901B0 >= 0x28) {'):]
    for sym in STRUCTED:
        t=typeof(sym)
        if t is None or t in ('Words3','Words13'): print('skip',sym,t); continue
        name='P3' if sym=='D_80290330' else sym
        n=len(re.findall(r'(?<![&\w])'+name+r'\b', body))
        body=re.sub(r'(?<![&\w])'+name+r'\b', f'V({t},{name})', body)
        body=body.replace(f'V({t},{name})(', name+'(')  # never a call
        print('structed',sym,t,n)
    s=head+body
    # round 11
    for k in ('D_80107D38','D_80107D40','D_80107D50'):
        s=s.replace(f'V(f32,P3) = V(f32,P3) * {k};', f'P3 = P3 * {k};')
    s=s.replace("{ f64 t_ = A8(f32,0) * D_80107EF8; f64 dv_ = D_80107F00; if (D_80107EF4 < _98) dv_ = _98; F(f32,&D_8029F9A0,52) = t_ / dv_; }",
                "{ f64 t_ = A8(f32,0) * D_80107EF8; f64 dv_ = D_80107F00; dv_ = (D_80107EF4 < _98) ? (f64)_98 : dv_; F(f32,&D_8029F9A0,52) = t_ / dv_; }")
    s=s.replace('f32 unused_[20];','f32 unused_[20];')
    head,body=s[:s.index('\nif (D_802901B0 >= 0x28) {')], s[s.index('\nif (D_802901B0 >= 0x28) {'):]
    body=body.replace('F(f32,&PC,0)','PCX').replace('(D_80202218 * 0x190)','IDX')
    head=head.replace('#define G(op,v)','#define PCX F(f32,&PC,0)\n#define IDX (D_80202218 * 0x190)\n#define G(op,v)',1)
    s=head+body
    # round 12: the position x is an f32 scalar in the unit now; read it plainly and let cse pick the form
    import os
    if os.environ.get('PC_SCALAR','0')=='1':
        s=s.replace('extern s32 PC;','extern f32 PC;')
        head,body=s[:s.index('\nif (D_802901B0 >= 0x28) {')], s[s.index('\nif (D_802901B0 >= 0x28) {'):]
        body=body.replace('PCX','PC')
        s=head+body
    # round 13: duplicated tails instead of m2c's shared goto blocks; abs-compare loop; polarity
    s=s.replace("} else if ((D_8028FBF6 == 0) && (_178 != 0x29)) {\nG(|=,0x18)\n}", "} else if (D_8028FBF6 == 0) {\nif (_178 != 0x29) {\nG(|=,0x18)\n}\n}")
    s=s.replace("func_80177910();\ngoto block_99;\n", "func_80177910();\nfunc_80167604(0x2B);\nbreak;\n")
    s=s.replace("} else {\nblock_99:\nfunc_80167604(0x2B);\n}", "} else {\nfunc_80167604(0x2B);\n}")
    s=s.replace("_204 = &PD;\nif (func_80147000(10) < 5) {\n_230 = 0x1A;\nblock_698:\nfunc_80133998(_204, _230, 0, 1, 0);\n}", "if (func_80147000(10) < 5) {\nfunc_80133998(&PD, 0x1A, 0, 1, 0);\n}")
    s=s.replace("case 28:\nif (B4(s32,4) != 0x2A) {\n} else {\nblock_237:\nAC(s16,4) = 2;\n}\nbreak;", "case 28:\nif (B4(s32,4) == 0x2A) {\nAC(s16,4) = 2;\n}\nbreak;")
    s=s.replace("if (((D_80290300 & 0x1000) || (AC(u8,9) != 0)) && (D_8028FBD8 == 0)) {\ngoto block_237;\n}", "if (((D_80290300 & 0x1000) || (AC(u8,9) != 0)) && (D_8028FBD8 == 0)) {\nAC(s16,4) = 2;\n}")
    s=s.replace("if (func_801B1580() != 0) {\n_111 = 11.0f;\n} else {\n_111 = 13.0f;\n}\nfunc_80175388(D_802903B0 + 0x74, _111);", "if (func_801B1580() != 0) {\nfunc_80175388(D_802903B0 + 0x74, 11.0f);\n} else {\nfunc_80175388(D_802903B0 + 0x74, 13.0f);\n}")
    s=s.replace("if (FB < 0xB) {\n_112 = -0.2f;\n} else {\n_112 = 0.2f;\n}\nfunc_8016049C(&PD, _112, A8(f32,8));", "if (FB < 0xB) {\nfunc_8016049C(&PD, -0.2f, A8(f32,8));\n} else {\nfunc_8016049C(&PD, 0.2f, A8(f32,8));\n}")
    s=s.replace("if (B4(s16,2) == 0x2A) {\nfunc_80133998(&PD, 2, 0, 0, D_80107EA8);\n_235 = 1;\n} else {\n_235 = 0;\n}\nfunc_80133998(&PD, 0, 1, _235, 0);", "if (B4(s16,2) == 0x2A) {\nfunc_80133998(&PD, 2, 0, 0, D_80107EA8);\nfunc_80133998(&PD, 0, 1, 1, 0);\n} else {\nfunc_80133998(&PD, 0, 1, 0, 0);\n}")
    s=s.replace("if (!(_97 < -_89)) {\n_124 = _87 + _97;\n} else {\n_124 = _87 - _89;\n}", "if (_97 < -_89) {\n_124 = _87 - _89;\n} else {\n_124 = _87 + _97;\n}")
    s=s.replace("((_94 < D_80107DF8) ? (f64)_94 : D_80107DF8)", "(!(_94 < D_80107DF8) ? D_80107DF8 : (f64)_94)")
    s=s.replace("F(f32,&P3,0) = V(f32,D_80290334) = D_80290338 = 0.0f;", "F(f32,&P3,0) = F(f32,&D_80290334,0) = F(f32,&D_80290338,0) = 0.0f;")
    old=re.search(r"_273 = D_802903B0;\n_241 = 0;\ndo \{\n_297 = \*_273;\n.*?\} while \(_241 < 4\);\n", s, re.S).group(0)
    new="""_273 = D_802903B0;
_241 = 0;
do {
_297 = *(u8 **)_273;
if (_297 != NULL) {
_31 = F(f32,_297,4);
if (_31 > 0.0f) {
if (_31 < _132) goto block_183;
} else {
if (-_31 < _132) {
block_183:
_132 = F(f32,*(u8 **)_273,4);
_252 = _241;
if (!(_132 > 0.0f)) {
_132 = -_132;
}
}
}
}
_241 += 1;
_273 += 4;
} while (_241 < 4);
"""
    s=s.replace(old,new)
    s=s.replace("_204 = ((u8 *)&D_80290348 - 0x70);\n_230 = 8;\ngoto block_698;", "func_80133998(((u8 *)&D_80290348 - 0x70), 8, 0, 1, 0);")
    import round14; s=round14.apply(s)
    import round15; s=round15.apply(s)
    import round16; s=round16.apply(s)
    import round17; s=round17.apply(s)
    import round18; s=round18.apply(s)
    import round19; s=round19.apply(s)
    import round20; s=round20.apply(s)
    import round21; s=round21.apply(s)
    return s
