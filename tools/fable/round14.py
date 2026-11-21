import re
def apply(s):
    R=[]
    def rep(old,new,name):
        nonlocal s
        n=s.count(old); R.append((name,n)); s=s.replace(old,new)
    rep("func_80177910();\nfunc_80167604(0x2B);\nbreak;\n","func_80177910();\nblk99:\nfunc_80167604(0x2B);\nbreak;\n",'0x2B label')
    rep("} else {\nfunc_80167604(0x2B);\n}","} else {\ngoto blk99;\n}",'0x2B goto')
    rep("V(f32,D_80290334) = V(f32,D_80290334) * F(f64,&D_80107D28,4);","D_80290334 = D_80290334 * F(f64,&D_80107D28,4);",'334 D28')
    rep("V(f32,P3) /= D_80107E1C;","P3 /= D_80107E1C;",'P3 E1C')
    rep("V(f32,D_80290334) = V(f32,D_80290334) + (V(f32,D_802900E4) * (F(f64,&D_80108028,4)","D_80290334 = D_80290334 + (V(f32,D_802900E4) * (F(f64,&D_80108028,4)",'334 8028')
    rep("V(f32,D_80290334) = _34 * (A8(f32,0) / D_80107DA8);","D_80290334 = _34 * (A8(f32,0) / D_80107DA8);",'334 DA8')
    rep("F(f32,&P3,0) = F(f32,&D_80290334,0) = F(f32,&D_80290338,0) = 0.0f;","F(f32,&P3,0) = F(f32,&P3,4) = F(f32,&P3,8) = 0.0f;",'zero chain')
    rep("D_8029F485 = 1;\nblock_471:\nif (D_802901D0 != 0) {\nblock_472:\nD_8029F482 = 1;\n}\n}\n} else {\n_255 = B4(s32,4);\n_253 = 0x48;\nblock_893:\nif (_255 != _253) {\n} else {\nblock_443:\nfunc_8017797C();\n}\n}",
        "D_8029F485 = 1;\nif (D_802901D0 != 0) {\nD_8029F482 = 1;\n}\n}\n} else {\nif (B4(s32,4) == 0x48) {\nfunc_8017797C();\n}\n}",'block_471 def')
    rep("if (D_802901D0 != 0) {\ngoto block_472;\n}","if (D_802901D0 != 0) {\nD_8029F482 = 1;\n}",'goto 472')
    rep("} else {\ngoto block_443;\n}\n} else {\nblock_372:\nfunc_80167604(3);\n}","} else {\nfunc_8017797C();\n}\n} else {\nfunc_80167604(3);\n}",'372 def')
    rep("goto block_372;","func_80167604(3);",'goto 372')
    rep("if (B4(s32,4) != 0) {\ngoto block_443;\n}","if (B4(s32,4) != 0) {\nfunc_8017797C();\n}",'goto 443 case17')
    rep("_255 = B4(s32,4);\n_253 = 0x23;\ngoto block_893;\n","if (B4(s32,4) == 0x23) {\nfunc_8017797C();\n}\nbreak;\n",'893 0x23')
    rep("V(s16,D_802900DC) = 0xA;\ngoto block_471;\n","V(s16,D_802900DC) = 0xA;\nif (D_802901D0 != 0) {\nD_8029F482 = 1;\n}\nbreak;\n",'goto 471')
    rep("V(s32,D_8029F9A4) = 0;\ngoto block_443;\n","V(s32,D_8029F9A4) = 0;\nfunc_8017797C();\nbreak;\n",'goto 443 493')
    rep("_255 = B4(s32,4);\n_253 = 0x33;\ngoto block_893;\n","if (B4(s32,4) == 0x33) {\nfunc_8017797C();\n}\n",'893 0x33')
    rep("_205 = &PD;\n_233 = 0x48;\n_121 = D_80107D78;\nblock_708:\nfunc_80133998(_205, _233, 0, 0, _121);","func_80133998(&PD, 0x48, 0, 0, D_80107D78);",'708 def')
    rep("_205 = ((u8 *)&P3 - 0x58);\n_233 = 0x44;\n_121 = D_80107D84;\ngoto block_708;","func_80133998(((u8 *)&P3 - 0x58), 0x44, 0, 0, D_80107D84);",'708 b')
    rep("_205 = ((u8 *)&D_80290334 - 0x5C);\n_233 = 0x44;\n_121 = D_80107D90;\ngoto block_708;","func_80133998(((u8 *)&D_80290334 - 0x5C), 0x44, 0, 0, D_80107D90);",'708 c')
    rep("_233 = 0xF;\nif (B4(s32,4) != 0) {\n_205 = &PD;\n_121 = -B4(f32,12);\ngoto block_708;\n}","if (B4(s32,4) != 0) {\nfunc_80133998(&PD, 0xF, 0, 0, -B4(f32,12));\n}",'708 d')
    rep("_207 = ((u8 *)&PC - 0x34);\n_1 = 0;\nblock_516:\nfunc_801A9054(_207, _1, 1);\nD_80290360 = V(f32,D_80290354);\n}","_207 = ((u8 *)&PC - 0x34);\n_1 = 0;\ngoto block_516;\n}",'516 a')
    rep("_207 = &PD;\n_1 = 1;\ngoto block_516;\n}","_207 = &PD;\n_1 = 1;\nblock_516:\nfunc_801A9054(_207, _1, 1);\nD_80290360 = V(f32,D_80290354);\n}",'516 c')
    rep("var_condition_bit_2 = _70 < D_80107FA4;\nV(s32,D_8029016C) = _256;\nif (!(_70 < D_80107FA4)) {\n_229 = 0xC8;\nif (_70 < D_80107F9C) {\nvar_condition_bit_2 = _70 < D_80107FA4;\ngoto block_522;\n}\n} else {\nblock_522:\n_229 = 0xA;\nif (!var_condition_bit_2) {\n_229 = _70;\n}\n}\nF(s32,&D_8029016C,12) = _229;",
        "V(s32,D_8029016C) = _256;\nF(s32,&D_8029016C,12) = (_70 < D_80107FA4) ? 0xA : ((_70 < D_80107F9C) ? (s32)_70 : 0xC8);",'clamp')
    rep("_270 = D_802996E8;\n_239 = 0;\ndo {\nif (!(F(s32,D_80299964 + _239,0) & 0x400)) {\n_270 += 0x300;\n} else {\nfunc_80195D50(_270);\n_270 += 0x300;\nfunc_8018DF4C(0);",
        "_270 = D_802996E8;\n_239 = 0;\ndo {\nif (F(s32,D_80299964 + _239,0) & 0x400) {\nfunc_80195D50(_270);\nfunc_8018DF4C(0);",'loop 0x400 head')
    rep("D_8029039C = D_8029039C * _155;\n}\n_246 += 1;\n_239 += 0x300;\n} while (_246 < D_801F0198);","D_8029039C = D_8029039C * _155;\n}\n_270 += 0x300;\n_246 += 1;\n_239 += 0x300;\n} while (_246 < D_801F0198);",'loop 0x400 tail')
    rep("_213 = D_801EEBD4;\nif (_213 == 0) {\nD_801EEBD4 = func_8013FCDC(0x578, 1, &D_80107B90);\n} else if (F(s32,_213,0) != 0) {\nfunc_801BB064(_213);\n}\nfunc_801BAF8C(_213);",
        "if (D_801EEBD4 == 0) {\nD_801EEBD4 = func_8013FCDC(0x578, 1, &D_80107B90);\n} else if (F(s32,D_801EEBD4,0) != 0) {\nfunc_801BB064(D_801EEBD4);\n}\nfunc_801BAF8C(D_801EEBD4);",'_213')
    n=len(re.findall(r'func_8016536C\((\w+), 0\)', s)); s=re.sub(r'func_8016536C\((\w+), 0\)', r'((s32 (*)(s32))func_8016536C)(\1)', s); R.append(('8016536C casts',n))
    rep("if (D_80107E0C < *(f32 *)D_8029FA44) {\n_122 = D_80107E10;\n} else {\n_122 = D_80107E14;\n}\nfunc_80133998(&PD, 0x1B, 0, 0, _122);","if (D_80107E0C < *(f32 *)D_8029FA44) {\nfunc_80133998(&PD, 0x1B, 0, 0, D_80107E10);\n} else {\nfunc_80133998(&PD, 0x1B, 0, 0, D_80107E14);\n}",'E10/E14')
    rep("if (F(s32,_211,204) < _24) {\nF(s32,_211,204) = _24;","if (F(f32,_211,204) < _24) {\nF(f32,_211,204) = _24;",'211 f32')
    for name,n in R:
        if n!=1: print('round14', name, 'applied', n, 'times')
    return s
