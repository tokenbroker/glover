if (D_801EFCFC < 2) {
a[0] = D_8029F9AC - F(f32,&PC,0);
a[1] = D_8029F9B0 - D_80290310;
a[2] = D_8029F9B4 - D_80290314;
if (!(D_80297BEC & 0x80) && (F(u8,&D_801FAACB,(D_80202218 * 0x190)) != 0) && (D_8029F5C4 <= F(f64,&D_80108158,4)) && ((D_8029F46C == 0) || (_184 = F(s16,D_8029F46C,32), (((_184 == 0x1C) | (_184 == 0x1E)) != 0)))) {
_176 = &D_801F1A98[D_8029F487];
D_802901E4 = *_176;
D_8029012E = -1;
D_802901E8 = *_176;
func_80167604(0x20);
break;
}
if (0) {
found_806:
a[0] = F(f32,_2,180) - F(f32,&PC,0);
a[1] = F(f32,_2,184) - D_80290310;
a[2] = F(f32,_2,188) - D_80290314;
}
} else {
_2 = D_802904D4.next;
if (_2 != &D_802904D4) {
s32 type; u8 wu; s8 *w = (s8 *)&D_801E7531; s8 *q7 = w + 7, *q9 = w + 9;
do {
if ((D_801EFD00 == 8) && (F(s32,_2,24) == 0xC)) goto found_806;
type = F(s32,_2,24);
if (D_801EFD00 == type + 0x24) goto found_806;
if (w[0] == 8) {
if (type != 0) goto keep_806;
} else if (w[0] == 0x2A) {
s32 bits, sh;
if ((u32)(D_801EFD00 - 1) < 6) {
if (type == 0xD) goto found_806;
}
{ s32 idx = D_801EAB24 * 0x1C; bits = *(s32 *)&D_801EAA48[idx]; }
sh = (D_801E7533 - 1) * 5;
if (!((bits >> sh) & 1)) {
if (type == 0x10) goto keep_806;
} else if (!((bits >> (sh + 1)) & 1)) {
if (type == 0x11) goto keep_806;
} else if (!((bits >> (sh + 2)) & 1)) {
if (type == 0x12) goto keep_806;
} else if (!((bits >> (sh + 3)) & 1)) {
if (type == 0x13) goto keep_806;
} else if (type == 0x14) {
goto keep_806;
}
} else if ((type == 6) && (w[0] == 1)) {
goto keep_806;
} else {
#define TYPEV (*(volatile s32 *)((u8 *)_2 + 24))
wu = ((volatile u8 *)w)[0];
if ((u32)(wu - 2) < 2) {
if ((TYPEV == 8) && ((w[6] != 0) || ((w[7] == 0) && !(((s16)*(u16 *)&FB % 60) < 0x1E)))) goto stop_806;
if (TYPEV != 7) continue;
if (q7[0] != 0) goto stop_806;
if (q7[-1] != 0) continue;
if (!(((s16)*(u16 *)&FB % 60) < 0x1E)) continue;
goto stop_806;
} else if ((u32)(wu - 4) < 2) {
if ((TYPEV == 0xA) && ((w[8] != 0) || ((w[9] == 0) && !(((s16)*(u16 *)&FB % 60) < 0x1E)))) goto stop_806;
if (TYPEV != 9) continue;
if (q9[0] != 0) goto stop_806;
if (q9[-1] != 0) continue;
if (!(((s16)*(u16 *)&FB % 60) < 0x1E)) continue;
goto stop_806;
} else {
if (0) {
stop_806:
a[0] = F(f32,_2,180) - PCX;
a[1] = F(f32,_2,184) - D_80290310;
a[2] = F(f32,_2,188) - D_80290314;
break;
}
if (TYPEV == 0xB) if ((s8)wu == 6) {
keep_806:
a[0] = F(f32,_2,180) - PCX;
a[1] = F(f32,_2,184) - D_80290310;
a[2] = F(f32,_2,188) - D_80290314;
}
}
}
} while ((_2 = _2->next) != &D_802904D4);
}
