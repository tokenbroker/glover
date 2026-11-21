def apply(s):
    R=[]
    def rep(old,new,name):
        nonlocal s
        n=s.count(old); R.append((name,n)); s=s.replace(old,new)
    rep("_160 = _100;\nif (!(_160 < D_80108168)) {\nif (_160 < D_80108170) goto blk872;\nB4(f32,12) = D_8010817C;\n} else {\nblk872:\nif (!(_160 < D_80108168)) {\nB4(f32,12) = _100;\n} else {\nB4(f32,12) = D_80108178;\n}\n}",
        "if (_100 < D_80108170) {\nif (!(_100 < D_80108168)) {\nB4(f32,12) = _100;\n} else {\nB4(f32,12) = D_80108178;\n}\n} else {\nB4(f32,12) = D_8010817C;\n}",'clamp2 nested')
    rep("func_80148CC8(b, D_802900C8 + 0x34, a, _59);\nfunc_80148CC8(a, C8(s32,216) + 0x7C, a, _59);",
        "func_80148CC8(b, D_802900C8 + 0x34, a, ({ U32F32 u_; u_.f = _59; u_; }));\nfunc_80148CC8(a, C8(s32,216) + 0x7C, a, ({ U32F32 u_; u_.f = _59; u_; }));",'_59 union')
    for name,n in R:
        if n!=1: print('round19', name, 'applied', n, 'times')
    return s
