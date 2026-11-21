import re
def apply(s):
    R=[]
    def rep(old,new,name):
        nonlocal s
        n=s.count(old); R.append((name,n)); s=s.replace(old,new)
    rep("{ f64 t_ = A8(f32,0) * D_80107EF8; f64 dv_ = D_80107F00; dv_ = (D_80107EF4 < _98) ? (f64)_98 : dv_; F(f32,&D_8029F9A0,52) = t_ / dv_; }",
        "{ f64 t_ = D_80107EF8; f64 dv_; t_ = ({ A8(f32,0) * t_; }); dv_ = D_80107F00; dv_ = (D_80107EF4 < _98) ? (f64)_98 : dv_; F(f32,&D_8029F9A0,52) = t_ / dv_; }",'t_ spelling')
    rep("F(s32,&D_8029016C,12) = (((_70 < D_80107FA4) ? D_80107FA4 : _70) < D_80107F9C) ? ((_70 < D_80107FA4) ? 0xA : (s32)_70) : 0xC8;",
        "if (!(_70 < D_80107FA4)) {\n_229 = 0xC8;\nif (_70 < D_80107F9C) goto blk522;\n} else {\nblk522:\n_229 = 0xA;\nif (!(_70 < D_80107FA4)) _229 = _70;\n}\nF(s32,&D_8029016C,12) = _229;",'clamp1 m2c')
    rep("B4(f32,12) = (_100 < D_80108168) ? D_80108178 : ((_100 < D_80108170) ? _100 : D_8010817C);",
        "_160 = _100;\nif (!(_160 < D_80108168)) {\nif (_160 < D_80108170) goto blk872;\nB4(f32,12) = D_8010817C;\n} else {\nblk872:\nif (!(_160 < D_80108168)) {\nB4(f32,12) = _100;\n} else {\nB4(f32,12) = D_80108178;\n}\n}",'clamp2 m2c')
    rep("_73 = (*(f32 *)&D_80299718[_238]) + D_801080C4;\nif (func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C) < (_73 * _73)) {",
        "if (func_80148EBC(&D_8029971C[_238], D_8029020C + 0x3C) < ({ _73 = (*(f32 *)&D_80299718[_238]) + D_801080C4; _73 * _73; })) {",'_73 stmt-expr')
    n=len(re.findall(r'F\(s32,_211,(184|192|196|200)\)', s)); s=re.sub(r'F\(s32,_211,(184|192|196|200)\)', r'F(f32,_211,\1)', s); R.append(('211 f32',n))
    n=len(re.findall(r'F\(s32,_301,(36|40|44)\)', s)); s=re.sub(r'F\(s32,_301,(36|40|44)\)', r'F(f32,_301,\1)', s); R.append(('301 f32',n))
    rep("_59 = D_80108124;","_59 = *(f32 *)&D_80108124;",'_59 f32')
    rep("for (_243 = 0; _243 < 4; _243++) {\n_288 = *(s32 *)(D_802903B0 + _243 * 4);\nif (_288 != NULL) {\n",
        "for (_243 = 0; _243 < 4; _243++) {\n_288 = *(s32 *)(D_802903B0 + _243 * 4);\nif (_288 == NULL) continue;\n{\n",'plane continue')
    for name,n in R:
        if n!=1 and name not in ('211 f32','301 f32'): print('round16', name, 'applied', n, 'times')
        elif name in ('211 f32','301 f32'): print('round16', name, n)
    return s
