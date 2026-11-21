import re
def apply(s):
    R=[]
    def rep(old,new,name):
        nonlocal s
        n=s.count(old); R.append((name,n)); s=s.replace(old,new)
    c17="case 17:\nif (B4(s32,4) != 0) {\nfunc_8017797C();\n}\nbreak;\n"
    rep(c17,"",'case17 remove')
    rep("break;\ncase 27:\n","break;\n"+c17+"case 27:\n",'case17 insert')
    rep("if (_136 != _136) {\n_136 = func_801C4030(_49);\n}\n","",'sqrt fallback')
    rep("do {\n_281 = *_280;\nif (_281 != NULL) {\nfunc_80149374(_281 + 0xC, &PC, a);\nF(s16,(*_280),16) = D_80290310 + _54;\n}\n_248 += 1;\n_280 += 4;\n} while (_248 < 2);",
        "for (; _248 < 2; _248++, _280 += 4) {\n_281 = *_280;\nif (_281 == NULL) continue;\nfunc_80149374(_281 + 0xC, &PC, a);\nF(s16,(*_280),16) = D_80290310 + _54;\n}",'loop 280')
    m=re.search(r"_279 = &D_80290140;\ndo \{\n_286 = \*_279;\nif \(_286 != NULL\) \{\n(.*?)\n\}\n_249 \+= 1;\n_279 \+= 4;\n\} while \(_249 < 2\);", s, re.S)
    if m:
        s=s.replace(m.group(0),"_279 = &D_80290140;\nfor (; _249 < 2; _249++, _279 += 4) {\n_286 = *_279;\nif (_286 == NULL) continue;\n"+m.group(1)+"\n}"); R.append(('loop 279',1))
    else: R.append(('loop 279',0))
    rep("if ((_225 & 0x40) && !(_225 & 0x80)) {","if (_225 & 0x40) if (!(_225 & 0x80)) {",'0x40/0x80')
    rep("_160 = _100;\nvar_condition_bit_3 = _160 < D_80108168;\nif (!(_160 < D_80108168)) {\nif (_160 < D_80108170) {\nvar_condition_bit_3 = _160 < D_80108168;\ngoto block_872;\n}\nB4(f32,12) = D_8010817C;\n} else {\nblock_872:\nif (!var_condition_bit_3) {\nB4(f32,12) = _100;\n} else {\nB4(f32,12) = D_80108178;\n}\n}",
        "B4(f32,12) = (_100 < D_80108168) ? D_80108178 : ((_100 < D_80108170) ? _100 : D_8010817C);",'clamp2')
    rep("if (D_801EEBD4 == 0) {\nD_801EEBD4 = func_8013FCDC(0x578, 1, &D_80107B90);\n} else if (F(s32,D_801EEBD4,0) != 0) {\nfunc_801BB064(D_801EEBD4);\n}",
        "if (D_801EEBD4 != 0) {\nif (F(s32,D_801EEBD4,0) != 0) {\nfunc_801BB064(D_801EEBD4);\n}\n} else {\nD_801EEBD4 = func_8013FCDC(0x578, 1, &D_80107B90);\n}",'EEBD4 swap')
    rep("F(s32,&D_8029016C,12) = (_70 < D_80107FA4) ? 0xA : ((_70 < D_80107F9C) ? (s32)_70 : 0xC8);",
        "F(s32,&D_8029016C,12) = (((_70 < D_80107FA4) ? D_80107FA4 : _70) < D_80107F9C) ? ((_70 < D_80107FA4) ? 0xA : (s32)_70) : 0xC8;",'clamp1 minmax')
    rep("} else {\nfunc_8017797C();\n}\n} else {\nfunc_80167604(3);\n}","} else {\nfunc_8017797C();\n}\n} else {\ngoto blk372;\n}",'372 goto')
    rep("(F(u8,&D_801FAACA,IDX) != 0) && (D_801EC740 == 1)) {\nfunc_80167604(3);\n}","(F(u8,&D_801FAACA,IDX) != 0) && (D_801EC740 == 1)) {\nblk372:\nfunc_80167604(3);\nbreak;\n}",'372 label')
    for name,n in R:
        if n!=1: print('round15', name, 'applied', n, 'times')
    return s
