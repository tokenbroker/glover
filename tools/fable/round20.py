def apply(s):
    R=[]
    def rep(old,new,name):
        nonlocal s
        n=s.count(old); R.append((name,n)); s=s.replace(old,new)
    rep("if (D_801EF454 < _35) {\nif (_191 != 1) {\n_234 = 1;\ngoto block_408;\n}\n}\nif (_35 <= D_801EF454) {\n_234 = 0;\nif (B4(s16,2) != 0) {\nblock_408:\nfunc_80133998(&PD, _234, 1, 0, 0);\ngoto block_409;\n}\ngoto block_410;\n}",
        "if (D_801EF454 < _35) {\nif (_191 != 1) {\nfunc_80133998(&PD, 1, 1, 0, 0);\ngoto block_409;\n}\n}\nif (_35 <= D_801EF454) {\nif (B4(s16,2) != 0) {\nfunc_80133998(&PD, 0, 1, 0, 0);\ngoto block_409;\n}\ngoto block_410;\n}",'_234 full calls')
    rep("_195 = _84;","_195 = (s16)_84;",'_195 s16')
    for name,n in R:
        if n!=1: print('round20', name, 'applied', n, 'times')
    return s
