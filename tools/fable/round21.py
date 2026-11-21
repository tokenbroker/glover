def apply(s):
    old="_130 = -D_801ED680 * D_80108048 * ((_20 + (F(f32,D_8029FA48,0) / D_80108044)) / _20);"
    new="_130 = -D_801ED680 * D_80108048 * (((F(f32,D_8029FA48,0) / D_80108044) + A8(f32,0)) / A8(f32,0));"
    if s.count(old)!=1: print('round21 _130 expr applied', s.count(old))
    s=s.replace(old,new)
    return s
