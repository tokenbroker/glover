def apply(s):
    R=[]
    def rep(old,new,name):
        nonlocal s
        n=s.count(old); R.append((name,n)); s=s.replace(old,new)
    rep("if (D_801EF454 < _35) {\n_234 = 1;\nif (_191 != 1) {\ngoto block_408;\n}\n}","if (D_801EF454 < _35) {\nif (_191 != 1) {\n_234 = 1;\ngoto block_408;\n}\n}",'_234 after test')
    rep("F(f32,&D_8029F9D4,0) = _163 / ((D_80107DF4 < _94) ? (!(_94 < D_80107DF8) ? D_80107DF8 : (f64)_94) : D_80107E00);",
        "if (D_80107DF4 < _94) {\nif (!(_94 < D_80107DF8)) {\nF(f32,&D_8029F9D4,0) = _163 / D_80107DF8;\n} else {\ngoto blk302;\n}\n} else {\nblk302:\nif (D_80107DF4 < _94) {\nF(f32,&D_8029F9D4,0) = _163 / _94;\n} else {\nF(f32,&D_8029F9D4,0) = _163 / D_80107E00;\n}\n}",'D4 m2c form')
    for name,n in R:
        if n!=1: print('round18', name, 'applied', n, 'times')
    return s
