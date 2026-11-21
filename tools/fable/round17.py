def apply(s):
    n=s.count("D_8029F9D0 = V(f32,P3);\nF(f32,&D_8029F9D0,4) = F(f32,&P3,4);\nF(f32,&D_8029F9D0,8) = F(f32,&P3,8);")
    s=s.replace("D_8029F9D0 = V(f32,P3);\nF(f32,&D_8029F9D0,4) = F(f32,&P3,4);\nF(f32,&D_8029F9D0,8) = F(f32,&P3,8);","*(Words3 *)&D_8029F9D0 = *(Words3 *)&P3;")
    print('round17 triple copies', n)
    s=s.replace("V(s32,D_8029F9A0) &= ~1;\n*(Words3 *)&D_8029F9D0 = *(Words3 *)&P3;","D_8029F9A0 &= ~1;\n*(Words3 *)&D_8029F9D0 = *(Words3 *)&P3;")
    return s
