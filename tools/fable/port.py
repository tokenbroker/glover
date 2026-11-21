import os
ROOT=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))  # the repo
SCR=os.environ.get('SCRATCH','/tmp/fable-scratch')  # where the pipeline's intermediate files go
import re, sys
sys.path.insert(0,SCR)
sys.path.insert(0,ROOT+'/tools'); import m2c_draft as M
from pathlib import Path
out=Path(ROOT+'/permuter_results/drafts'); fn='func_8016A058'
s=(out/f'{fn}.draft.c').read_text()
s=re.sub(r'\(\*\((const f32|f32|f64|s32|s16|u8) \*\)\(\(u8 \*\)\(\(u8 \*\)&(D_[0-9A-F]{8}) \+ (\d+)\)\)\)', r'F(\1,&\2,\3)', s)
s=re.sub(r'\(\*\((const f32|f32|f64|s32|s16|u8) \*\)\(\(u8 \*\)&(D_[0-9A-F]{8}) \+ (\d+)\)\)', r'F(\1,&\2,\3)', s)
macros={'D_802903B4':'B4','D_802903B0':'B0','D_802903AC':'AC','D_8029FA50':'FA','D_802900C8':'C8','D_802903A8':'A8'}
for sym,mac in macros.items():
    s=re.sub(r'F\((\w+),'+sym+r',', mac+r'(\1,', s)
s=s.replace('#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))\n', '#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))\n'+''.join(f'#define {m}(t,o) F(t,{sym},o)\n' for sym,m in macros.items()),1)
cut=s.index('\nif (D_802901B0 >= 0x28) {'); pre, code = s[:cut], s[cut:]
pre=re.sub(r'(?m)^s16 (_\d+);$', r's32 \1;', pre)
for old,new in [('&sp28','a'),('&sp38','b'),('&sp48','c'),('sp28','a[0]'),('sp2C','a[1]'),('sp30','a[2]'),('sp38','b[0]'),('sp3C','b[1]'),('sp40','b[2]'),('sp48','c[0]'),('sp4C','c[1]'),('sp50','c[2]'),('sp54','c[3]')]:
    code=re.sub(r'(?<![\w&])'+re.escape(old)+r'\b', new, code)
pre=re.sub(r'(?m)^f32 (sp28|sp2C|sp30|sp38|sp3C|sp40|sp48|sp4C|sp50|sp54);\n', '', pre)
pre=pre.replace('\nu8 sp58;\n','\nf32 a[3];\nf32 b[3];\nf32 c[4];\nf32 q[4];\nf32 unused_[20];\n',1); code=code.replace('&sp58','q')
m=re.search(r'_\d+ = D_80290310 \+ b\[1\];.*?_\d+ = func_80147000\(5\) - 2;', code, re.S)
if m:
    blk=m.group(0); last=blk[blk.rindex('_'):]
    code=code.replace(blk, '''{ f32 px = *(f32 *)&D_8029030C, py = D_80290310, pz = D_80290314;
f32 t0 = px + b[0], t1 = py + b[1], t2 = pz + b[2];
f32 u0 = px - b[0], u1 = py - b[1], u2 = pz - b[2];
a[0] = t0; a[1] = t1; a[2] = t2; b[0] = u0; b[1] = u1; b[2] = u2; }
'''+last); print('vector block ported')
i=code.find('D_8029016C = 0x64;')
if i>=0:
    j=code.index('} else if (D_80290168 != 0) {', i)
    code=code[:i]+'''{ s32 *p = (s32 *)&D_8029016C; s16 *h; *p = 0x64;
if (p[-1] == 0) {
func_801785E0(&p[-1], 0x81, 0x64, &D_8029030C, 0xB4);
} else if (D_802004E0 == ((D_802004E0 / 10) * 0xA)) {
h = (s16 *)((u8 *)p + 0xC);
*h = MIN(MAX(*h + func_80147000(13) - 6, 0xA0), 0xC8);
}
}
'''+code[j:]; print('D_8029016C block ported')
m=re.search(r'(_\d+) = AC\(s16,4\);\nswitch \(\1\) \{\ncase 41:.*?\nbreak;\n\}\n', code, re.S)
if m:
    t=m.group(1)
    code=code.replace(m.group(0), f'''{t} = AC(s16,4);
if ((({t} == 0x29) && (D_801E7460 == 0)) || ((({t} == 0xB) || (({t} == 0x2A) && (B4(s16,2) != 0x32))) && (B0(u8,392) == 0))) {{
s32 *g_ = &D_80290300; *g_ &= ~1;
}} else {{
s32 *g_ = &D_80290300; *g_ |= 1;
}}
'''); print('flag chain ported')
code=re.sub(r'(?m)^D_80290300 (\|=|&=) ([^;]+);$', r'{ s32 *g_ = &D_80290300; *g_ \1 \2; }', code)
code=re.sub(r'(?m)^D_80290300 = D_80290300 ([|&]) ([^;]+);$', r'{ s32 *g_ = &D_80290300; *g_ \1= \2; }', code)
code=code.replace('if (F(f32,&D_8029F9AC,-8) == (((u8 *)&D_8029030C - 0x34))) {\nF(f32,&D_8029F9AC,-8) = 0;', 'if (F(s32,&D_8029F9AC,-8) == (s32)&D_802902D8) {\nF(s32,&D_8029F9AC,-8) = 0;')
s=pre+code
code=re.sub(r'\{ s32 \*g_ = &D_80290300; \*g_ (\|=|&=) ([^;]+); \}', r'G(\1,\2)', s[len(pre):]); s=pre+code
names={'D_802902D8':'PD','D_80290330':'P3','D_8029030C':'PC','D_8028FBEA':'FB'}
for sym,nm in names.items(): s=re.sub(r'\b'+sym+r'\b', nm, s)
s=s.replace('#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))\n', '#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))\n#define G(op,v) { s32 *g_ = &D_80290300; *g_ op v; }\n'+''.join(f'#define {nm} {sym}\n' for sym,nm in names.items()),1)
pre2,code2=s[:s.index('\nif (D_802901B0 >= 0x28) {')], s[s.index('\nif (D_802901B0 >= 0x28) {'):]
code2=code2.replace('P3 = D_801ED3C4;\nF(f32,&P3,4) = F(s32,&D_801ED3C4,4);\nF(f32,&P3,8) = F(s32,&D_801ED3C4,8);\n','*(Words3 *)&P3 = *(Words3 *)&D_801ED3C4;\n')
code2=code2.replace('a[0] = PC;\na[1] = F(s32,&PC,4);\na[2] = F(s32,&PC,8);\n','*(Words3 *)a = *(Words3 *)&PC;\n')
code2=re.sub(r'PC = F\(f32,(\w+),(\d+)\);\nF\(s32,&PC,4\) = F\(f32,\1,(\d+)\);\nF\(s32,&PC,8\) = F\(f32,\1,(\d+)\);\n', lambda m: f'*(Words3 *)&PC = *(Words3 *)({m.group(1)} + {m.group(2)});\n', code2)
code2=re.sub(r'(\w+)\[0\] = F\(s32,([^;]+?),(\d+)\);\n\1\[1\] = F\(s32,\2,(\d+)\);\n\1\[2\] = F\(s32,\2,(\d+)\);\n', lambda m: f'*(Words3 *){m.group(1)} = *(Words3 *)((u8 *){m.group(2)} + {m.group(3)});\n' if int(m.group(4))==int(m.group(3))+4 and int(m.group(5))==int(m.group(3))+8 else m.group(0), code2)
code2=re.sub(r'(?<![&\w])PC\b', 'F(f32,&PC,0)', code2)
s=pre2+code2
i=s.index('\nif (D_801EFCFC < 2) {\na[0] = D_8029F9AC')+1; j=s.index('block_859:', i)
s=s[:i]+open(SCR+'/loop1.c').read()+s[j:]
print('Words3 copies:', s.count('(Words3 *)'))
import port2; s=port2.apply(s)
(out/f'{fn}.C.c').write_text(s); print('size', len(s))
errs=M.compile_unit('18020_1D7F0', fn, s, out)
print(len(errs), 'errors'); lines=s.split('\n')
for e in errs[:8]:
    mm=re.match(r'\[(-?\d+)\] (.*)', e); n=int(mm.group(1)); print(f'  [{n}] {mm.group(2)}'); print('      ', lines[n-1][:160] if 0<n<=len(lines) else '?')
if not errs: print('score', M.score('18020_1D7F0', fn, out))
