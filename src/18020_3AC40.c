#include "common.h"
#include "structs.h"

static inline u8 func_80189224_f2u(f32 x, f32 lim) {
    u32 v;
    u8 r;
    if (!(x >= lim)) {
        v = (s32)x;
    } else {
        v = (s32)(x - lim);
        v |= 0x80000000;
    }
    r = v;
    return r;
}



extern u8 D_80109488[], D_80109494[], D_801094A0[], D_801094A8[], D_801094DC[];
extern s16 D_801EFD44;
extern s32 D_801EFCE8;
extern u8 *D_801EFCF0;
typedef struct { f32 v[4]; } Quat801488C0;
extern u8 D_80105F74[], D_80105F80[], D_80105F8C[], D_80105F98[], D_80105FA4[];
extern f32 D_80105FB0, D_80105FB4, D_80105FB8;
extern s32 D_801EC810, D_801EC814;
extern u8 D_801F0238[];
typedef struct { s32 w[16]; } Blk142700;
typedef struct { s16 start; s16 end; s32 unk4; s32 unk8; } AnimKey133BD0;
typedef struct {
    s16 unk0;
    s16 cur;
    s32 done;
    s32 hold;
    f32 speed;
    s16 next[5];
    s32 nextHold[5];
    f32 nextSpeed[5];
    s16 count;
    AnimKey133BD0 *keys;
    f32 time;
} Anim133BD0;
typedef struct { f32 x, y, z; s32 pad; s32 time; } Key143;
typedef struct Anim143 {
    u8 pad0[0xD];
    u8 opacity;
    s16 nScale;
    s16 nTrans;
    s16 nRot;
    s16 **unk14;
    s32 dlist;
    Key143 *scale;
    Key143 *trans;
    Key143 *rot;
    s32 nKids;
    u8 *kids;
    u8 pad30[2];
    u16 flags;
    struct Anim143 *child;
    struct Anim143 *sibling;
    u8 *att;
} Anim143;
typedef struct {
    /* 0x00 */ u8 pad0[0xD];
    /* 0x0D */ s8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 unk18[8];
    /* 0x20 */ u8 *unk20;
    /* 0x24 */ f32 unk24[3];
    /* 0x30 */ u8 pad30[5];
    /* 0x35 */ u8 unk35;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 unk37;
    /* 0x38 */ u8 pad38[2];
    /* 0x3A */ u8 unk3A;
    /* 0x3B */ u8 unk3B;
    /* 0x3C */ u8 pad3C[0x14];
    /* 0x50 */ f32 unk50;
} Obj80184FC0;
typedef struct Particle8014ED9C {
    /* 0x00 */ struct Particle8014ED9C *next;
    /* 0x04 */ struct Particle8014ED9C *prev;
    /* 0x08 */ s32 type;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20[3];
    /* 0x23 */ u8 unk23;
    /* 0x24 */ s32 unk24[20];
    /* 0x74 */ f32 vx;
    /* 0x78 */ f32 vy;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s16 unk80;
    /* 0x82 */ s16 unk82;
    /* 0x84 */ s16 unk84;
    /* 0x86 */ s16 unk86;
    /* 0x88 */ s16 unk88;
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ u8 unk8C;
    /* 0x8D */ u8 flags;
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 unk8F;
} Particle8014ED9C;
void *func_8013FCDC(s32, s32, s32 *);
extern f32 D_80101B38;
extern f64 D_80106360;
extern f32 D_80105934;
extern f32 D_80101B3C;
extern f32 D_80101B40;
extern f32 D_80101B44;
extern f32 D_80101B48;
extern f64 D_80101B50;
void func_80160728(u8 *arg0, f32 arg1);
extern f32 D_80107350;
extern f32 D_80107354;
extern f32 D_801062EC;
extern f32 D_801062F0;
extern s32 D_801EC818;
extern s32 D_80269F3C;
extern u8 D_8028D7E8[];
extern u8 D_8028D8D8[];
extern s16 D_801EC7DE;
extern f32 D_80106504;
extern u8 D_801F20F4[][3];
extern u8 D_801F20F5[];
extern u8 D_801F20F6[];
extern f32 D_8010BF38;
extern f32 D_8010BF3C;
extern f32 D_8028D914;
extern f32 D_8028D958;
extern f64 D_80106508;
extern f32 D_8010BD54;
void func_8013CEEC(void);
void func_8013A284(void);
void func_8013A6B0(void);
void func_801437E4(u8 *);
void func_8015C350(u8 *, u8 *);
f32 func_80148DB0(u8 *arg0, u8 *arg1);
extern s16 D_8029F482;
extern f32 D_8029F9A8;
extern f32 D_80290308;
extern f32 D_8029F9D4;
extern f32 D_8010AA74;
extern f32 D_8010AA78;
extern f32 D_8010AA7C;
extern f32 D_8010AA80;
extern f32 D_8010AA84;
extern f32 D_8010AA88;
extern f32 D_8010AA8C;
extern f32 D_8010AA90;
extern u8 D_80108328[];
extern f32 D_8010A268;
extern f32 D_80100DE4;
extern f32 D_80100DE8;
extern u8 D_802978E8[];
extern s8 D_801EC7EA;
extern f64 D_8010A26C;
extern f64 D_8010A274;
extern f32 D_8010A270;

void func_8012C2B0(u8 *, s32, s32);

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
} Unk801469E4Args;

typedef struct {
    /* 0x00 */ u8 pad0[0x48];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ u8 unk58;
    /* 0x59 */ u8 unk59;
    /* 0x5A */ u8 unk5A;
    /* 0x5B */ u8 unk5B;
    /* 0x5C */ s32 unk5C;
} Unk802847F8Node;

extern Unk802847F8Node *D_802847F8;
extern u8 D_8010614C[];
extern f32 D_801ED3BC;

typedef struct {
    /* 0x00 */ u8 unk0[8];
} Unk801BC43C;

extern u8 D_801F21A1;
extern s32 D_801F21A8;
extern f32 D_8010C014;
extern Unk801BC43C D_802AAFF0;
extern Unk801BC43C D_802AB000;

typedef struct { s32 w[4]; } Block16;

typedef struct {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ u8 pad4[0x4C];
} Unk50Elem;

typedef struct {
    /* 0x00 */ u8 pad0[0x70];
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;
} Unk70Pair;

typedef struct Unk8014B7F0 {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 pad1[0xC];
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u8 pad2[4];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad3[2];
    /* 0x24 */ u8 *unk24;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 unk2A;
    /* 0x2B */ u8 pad4;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ s16 unk32;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 unk37;
} Unk8014B7F0;

s32 func_801D0370(void *, s32, void *, s32);
void func_80132DFC(s32);
extern s16 D_801EA9E0;
extern s16 D_801E7502[];
extern u8 *D_8029FA50;
extern f32 D_801ED938[];
extern f64 D_8010BAB0;
extern s32 D_80290190;
extern s32 D_80284E08;
extern s32 D_801FB268;
extern u8 *D_801EAB2C;
extern u8 D_801EAB29;
extern struct { u8 f; u8 pad[399]; } D_801FAAC6[];
extern u8 D_801FAAC7[];
extern u8 D_801FAAC9[];
extern u8 D_801FBC80[];
extern u8 D_801FBC50[];
extern u8 D_801FFC98[];
extern u8 D_801EC7AC;
void func_801D0480(void *, void *, void *, s32);
void func_801C6550(void *, s32, void *, s32, void *, s32);
void func_801C7860(void *);
void func_801C76F0(void *, s32);
void func_8013EB18(void);
extern u8 D_80258EE0[];
extern s32 D_802586E8;
extern u8 D_801EFCA0;
extern u8 D_80296C64[10][0xA0];
extern u32 D_80296CB4[10][40];
extern u32 D_80296CDC[10][40];
extern f32 D_80201000;
extern f64 D_80105D00;
extern f64 D_80105D08;
f32 func_801C4040(f32);
f32 func_801C6000(f32);
extern f32 D_80290350;
extern f32 D_80290354;
extern f32 D_802900F8;
extern f32 D_802900FC;
extern f32 D_801ED3EC;
void func_801CD3C0(s32 *);
extern s32 D_801ED384;
extern s32 D_801ED388;
extern u8 D_801ED390;
extern u8 D_801ED391;
extern u8 D_801ED392;
extern u8 D_801ED393;
extern s32 D_801ED394;
extern s32 D_801ED398;
extern s32 D_801ED39C;
extern s32 D_801ED3A0;
extern f32 D_801ED3A8[2];
extern f32 D_801ED3B0[2];
extern f32 D_80106138[];
extern f32 D_80106140;
extern u8 D_8029FA14[];
extern f32 D_801E7648;
extern f32 D_801E7634;
extern f32 D_801E763C;
extern f32 D_801F83FC;
extern f32 D_801F8400;
extern s32 D_801F8404;
extern f32 D_801F8408;
extern f64 D_801015C8;
extern f64 D_801015D0;
extern f32 D_80106288;
extern f32 D_8010628C;
extern f32 D_80106290;
extern f32 D_80106298;
extern f32 D_801062B0;
extern f32 D_801062B8;
extern f32 D_801062C0;
extern f32 D_801062D0;
extern f32 D_801062D8;
extern f32 D_801062A4;
extern f32 D_801062A8[];
extern f32 D_801062AC;
extern f32 D_801062C4;
extern f32 D_801062C8[];
extern f32 D_801062CC;
extern f32 D_801062E4;
extern f32 D_801062E8;
extern f64 D_80106194;
extern f64 D_8010619C;
extern f64 D_801061A4;
extern f64 D_80105B88;
extern f64 D_80105B90;
extern f64 D_80105B98;
f32 func_801C4030(f32);
extern f32 D_801061AC;
extern f32 D_801061B0;
extern u8 D_80106184[];
extern u8 D_8010618C[];
extern u16 D_801D41D0;
void func_80139D94(void *);
extern u8 D_801061B4[];
extern u16 D_801D8FF0[];
typedef struct { s32 unk0; u8 *unk4; u8 pad8[0x8]; s32 unk10; } Unk802846F4;
extern Unk802846F4 *D_802846F4;
s32 func_801462E0(s32, u8);





extern Unk802904D4Node D_802904D4;
typedef struct { f32 x, y, z; } Vec3F;
typedef struct { Vec3F a; Vec3F b; } Vec3Pair;
extern Vec3F D_801ED68C[];
extern Vec3F D_801ED6EC[];
void func_8014915C(Vec3F *, Vec3F *, f32, s32);
extern f32 D_8010B3B4;

extern f32 D_8010B3B8;
extern f32 D_8010B378;
extern s32 D_8010B364;
extern f64 D_8010B36C;
extern f32 D_8010B374;
extern f64 D_8010B380;
extern f32 D_8010B384;
extern f32 D_8010B388;
extern Vec3F D_8010B4EC;
extern f32 D_8010B4F8;
extern f32 D_8010B4FC;
extern f32 D_8010B500;
extern f32 D_8010B504;
extern f64 D_8010B508;
void func_801499A0(s32, s32, s32);
s32 func_801A6844(void *, f32 *, f32 *, f32, f32, s32, s32, s32);
void func_801A69F8(u8 *);
typedef struct Obj8018315C {
    u8 pad0[0x20];
    struct Obj8018315C *parent;
    u8 pad24[0xB4 - 0x24];
    Vec3F pos;
    Vec3F prev;
} Obj8018315C;
void func_8017D21C(Obj8018315C *, f32);
extern u8 D_80108D34[];
extern u8 D_80108D40[];
extern u8 D_80108D4C[];
extern u8 D_80108D8C[];
extern u32 D_802904D0;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    s16 unkC;
} Entry80182F64;
typedef struct {
    Entry80182F64 *slot[0x14];
    s16 unk50;
    u8 pad52[2];
    u8 unk54;
    u8 cnt;
} List80182F64;
void func_8018315C(Obj8018315C *, Vec3F *, f32);
typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x20];
    s16 *unk3C;
    s32 unk40;
    u8 pad44[0x6E - 0x44];
    u16 unk6E;
    u8 pad70[0xA3 - 0x70];
    u8 unkA3;
    u8 padA4[2];
    s16 unkA6;
    s32 unkA8;
    u8 padAC[0xB4 - 0xAC];
    Vec3F pos;
    Vec3F prev;
    u8 padCC[0x164 - 0xCC];
    s32 unk164;
    s32 unk168;
    u8 pad16C[4];
    s16 unk170;
    s16 unk172;
    s16 unk174;
    s16 unk176;
} Obj8017CF00;
extern f64 D_80108888;
extern s32 D_802004E0;
void func_801785E0(s32 *, s16, s16, s32, s16);
void func_80178704(s32 *);
typedef struct {
    u8 pad0[0x28];
    void *unk28;
    u8 pad2C[0xC];
    List80182F64 *list;
} Obj80182F64;

typedef struct {
    s32 unk0;
    s32 a[10];
    s32 b[10];
    s32 c[10];
    u8 pad[0x80 - 0x7C];
    u8 unk80;
    u8 pad2[0x9F - 0x81];
    u8 unk9F;
} Unk802972A0;
extern Unk802972A0 D_802972A0[10];

extern s32 D_802972A4[][40];
extern u8 D_8029733F[][160];
extern Unk802972A0 D_80296C60[10];
extern s32 D_80296C30;
extern s32 D_8029731C[][40];
extern u8 D_80297320[][160];
extern s16 D_801E7586;
extern void *D_802AA91C;
extern u8 *D_802AA9D8;
extern u8 D_801EB538[];
extern u8 D_801EBB30[];
extern u8 D_801EC130[];

typedef union {
    s32 i;
    f32 f;
} U32F32;

extern f32 D_8010B544;
extern f64 D_8010B548;
extern f64 D_8010B550;
extern f64 D_8010B558;
extern f64 D_8010B560;


extern s32 D_80299250;
extern f32 D_801F1A78;
extern u16 D_80299202;
extern f32 D_8010951C;

typedef struct Unk8014A460Sub {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u8 pad10[0x8];
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ s32 unk1C;
} Unk8014A460Sub;

typedef struct Obj8014A460 {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ Unk8014A460Sub *unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u8 pad30[0xC];
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ u8 pad3E[0x12];
    /* 0x50 */ s16 unk50;
    /* 0x52 */ u8 pad52[6];
    /* 0x58 */ u8 unk58;
    /* 0x59 */ u8 unk59;
    /* 0x5A */ u8 pad5A[2];
    /* 0x5C */ s32 *unk5C;
    /* 0x60 */ u8 pad60[0xC];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
} Obj8014A460;

typedef struct Unk8014B110Tbl {
    /* 0x00 */ Unk8014A460Sub **unk0;
    /* 0x04 */ s16 unk4;
} Unk8014B110Tbl;
extern s32 D_8029928C;
extern s32 D_80299254;
extern s32 D_80299294;
void func_8011FF08(s32);
s32 func_801B70F8(u8 *, s32, f32, f32);
void func_80130620(Unk802904D4Node *, s32);
extern u8 *D_8028D8B0;

extern u8 D_8028DCD0[];
extern u8 D_8028DD58;
extern u8 D_8028DD5A[];
extern u8 D_80106548[];
extern u8 D_80106554[];
extern u8 D_80106564[];
extern u8 D_80106574[];
extern u8 D_80106580[];
extern u8 D_80106588[];
extern u8 D_8028D8CC[];
extern u8 D_80289394[];
extern u8 D_8028D7D8[];
extern u8 D_8028D8D0[];
extern u8 D_8028D8D4[];
extern u8 D_8028F3C8[];
void func_8014ED9C(u8 *);

extern s16 D_801EAB24;
extern u8 D_801EAA55[];
extern u8 D_801EAA48[];
extern u8 D_801EAA4C[];
extern u8 D_801EAA44;
extern u8 D_801EAA45;
extern u8 D_801EAA46;
extern u8 D_801FA9A9;
extern u8 D_801FA9AA;
extern s32 D_801EAA50;
extern u8 D_801EAA54;
extern s32 D_8029018C;
extern u8 D_80290193;
void func_80132CAC(void);
extern s8 D_801E7533;
extern s32 D_80297BEC;
extern u8 D_80108510[];
extern u8 D_8029970A[];
extern u8 *D_8029020C;
extern f32 D_8029039C;
extern f32 D_80290398;
extern f32 D_80290394;
extern f32 D_801EEC40;
extern f32 D_801EEC3C;
extern const f64 D_801083A0;
extern s32 D_802901AC;

void func_8011C810();
extern s32 D_801E76C0;
extern s32 D_801E76C4;
extern u16 D_801FA690;
extern u8 D_801F9690[];

void func_8014A9FC();
extern ObjectNode D_8028F350;
extern s32 D_8029F210;
extern s32 D_8029F214;
extern s32 D_8029F394;
extern ObjectNode *D_8028F354;
extern s32 D_8028F3C0;
extern s32 D_80284864;
extern s32 D_802903C0;
extern s32 D_802903C4;
extern s32 D_8029040C;
extern s32 D_8025D0C0;
void func_801C61F4(s32, s32, s32, s32);
extern s32 D_80299488[];
extern s32 D_8029948C;
extern s32 D_80299490;
extern s32 D_80106088;
extern s32 D_80284D74;

void func_801758D0(s32);
void func_801AE510(void);
void func_80162BE0(void);
s32 func_801D2150(void *, void *, ...);
extern u8 D_8010A4A4[];
extern u8 D_8010A4B0[];
void func_80139D70(s32);
void func_8015C924(void *);
void func_80182090(s32);
void *func_8017DBA0(s32);
void func_80133998(void *, s32, s32, s32, f32);
void func_801A7360(void);
u32 func_80139CA0(u8 *);
void func_8014FCF8(void *, s32, s32);
void func_80181A40(u8 *, u32, u32);
extern s32 D_80100DEC;
extern s32 D_80100DFC;
extern s32 D_80100E08;
extern s32 D_80100E14;
extern f32 D_80100E24;
extern u16 D_801DDE20;
extern u16 D_801DDE22;
extern s32 D_801EFCB8;
extern u16 D_80284DB4;
extern u16 D_80284DB6;
extern f32 D_801061D8;
#define atan_tab(x) ({ f32 _q = (x); u16 *_d = &D_801DDE20; if (_q > (f32)D_80284DB6) { _q = (f32)D_80284DB6; } _d += (s32)(_q * (f32)D_80284DB4) + 2; (f32)*_d; })
extern f32 D_801061DC;
extern f32 D_801061E0;
extern f32 D_801061E4;
extern f64 D_801061E8;
extern f32 D_801061F0;
extern f64 D_801061F4;
extern f32 D_801061FC;
extern f32 D_80106200;
extern f32 D_80106204;
extern s8 D_801E7531;
extern u16 D_8029999C[][0x180];
extern s16 D_80299CA0;
extern s16 D_80299FA0;
extern u8 *D_802997B8;
extern u8 *D_802997C0;
extern s16 D_802999A0;
extern u8 D_801E7532;
extern f32 D_801F03B8[][0x30];
extern u8 D_801EAA57;
extern s16 D_801EC7DA;
extern s32 D_8025D578;
extern u8 D_8025D690[];
extern u8 D_80105D84[];
extern u8 D_8010745C[];
extern f32 D_8010AEF0;
extern f32 D_8010AEF4;
extern f64 D_8010AEF8;
extern f32 D_801EFFC8;
extern s32 D_801EC740;
extern s32 D_8028FB98;
extern s32 D_8028FB6C;
extern f32 D_8028F95C;
extern f32 D_8028F958;
extern f32 D_8028F914;
extern f32 D_8028F918;
extern f32 D_8028F91C;
extern f32 D_8028FA00;
extern f32 D_8028FA04;
extern f32 D_8028FA08;
extern f32 D_8028FB84;
extern f32 D_8028FB88;
extern f64 D_801076FC;
extern f32 D_80107330;
extern f32 D_80107334;
extern f64 D_80107338;
extern f64 D_80107340;
extern f64 D_80107348;
extern f64 D_80107704;
extern f32 D_8028F968;
extern u8 *D_8028F9B0;
extern u8 *D_8028F9B8;
extern f32 D_80105964;
extern f32 D_80105968;
extern f32 D_801F1A94;
extern f32 D_801FAA1C;
extern u8 D_80109524[];
extern f32 D_80109520;
extern f64 D_80106338;
extern f64 D_80106340;
extern f64 D_80106348;
extern f64 D_80106350;
extern f64 D_80106358;
extern f64 D_80106368;
extern f64 D_80106370;
extern s32 D_802902D8;
extern s32 D_80297900;
extern s32 D_80297904;
extern s32 D_802988BC;
extern s32 D_8029F978;
extern s32 D_80299478;
extern s32 D_8029F970;
extern s32 D_8029F43C;
void func_801B362C(void *, s32, s32, f32);
extern s32 D_802901B0;
extern s8 D_8029F487;
extern s32 D_8029F5CC;
extern s32 D_8029FA40;
extern s32 D_802901B8[];
extern s32 D_8029F584;
extern s32 D_8029F588;
extern u8 *D_8029F440[];
extern f64 D_8010BA98;
extern f32 D_8010BAA0;
extern f32 D_8010BAA4;
extern const f32 D_8010BA70;
extern const f32 D_8010BA7C;
extern const f64 D_8010BA80;
extern const f32 D_8010BA88;
extern const f32 D_8010BA8C;
extern const f32 D_8010BA90;
extern const f32 D_8010BA94;
extern u8 D_80201008[];
extern s16 D_801F1A98[];
extern s32 D_801ED3E0[];
extern s32 D_8029FA24[];
typedef struct {
    s32 w[3];
} Words3;
typedef struct {
    s32 w[13];
} Words13;
extern f32 D_8010BBD0;
extern f32 D_8010BBD4;
extern f32 D_8010BBD8;
extern s32 D_8010BBC4[];
extern s32 D_80297BF0;
extern u8 D_8029F5C9;
typedef struct {
    Words3 a;
    u8 pad0[0x5C];
    Quat801488C0 q;
    Quat801488C0 q2;
    f32 x;
    f32 y;
    f32 z;
    u8 pad1[0x50];
} Elem8029F60C;
typedef struct {
    Words13 *ptr;
    u8 pad[0xE0];
} Elem8029F6AC;
extern Elem8029F60C D_8029F60C[];
extern Elem8029F6AC D_8029F6AC[];
extern Words13 *D_8029FA4C;
extern f32 D_801F1A90;
extern s32 D_8029F5C4;
extern s8 D_8029F5C8;
extern f32 D_8029FA30;
extern f32 D_8010BAA8;
extern f32 D_8029F9AC;
void func_801C62C0(void *, s32);
s32 func_801C7430(void *, void *, s32);
s32 func_801D1C50(u8 *, s32, s32, s32, s32, s32, s32);
extern f32 D_8010B8AC;
extern f32 D_8010B8B0;
extern f32 D_8010B38C;
f32 func_80148EBC(void *, s32);
void func_801B7344(s32, s32, f32);
extern f32 D_8010B8B4;
extern f32 D_8010B3A8;

void func_801C0A2C(s32, s32);
s32 func_801C0B00(s32);
void func_8011CD50(s32);
extern s16 D_801E753C;
extern u8 D_801E7540;
extern s16 D_801E753E;
extern s16 D_801E758E;
extern s16 D_801E758C;
extern s8 D_801ED400;
extern s8 D_801ED401;
extern s8 D_801ED402;
extern u8 D_801ED403;
extern f32 D_8010B89C;
extern f32 D_8010B8A0;
extern f32 D_8010B8A4;
extern f32 D_8010B8A8;
extern f32 D_8010A6F0;
extern f64 D_8010A6F8;
extern f64 D_8010A6F4;
extern s32 D_802AA794;
void func_801B889C(Unk802AA7A0Node *);


void func_8012ACC0();
void func_8014A9D8();
void func_8014ABEC();
void func_8015C758();
void func_801779F0();
void func_80179EAC();
void func_80188F90();
void func_80188FB4();
void func_8018A9D0();
void func_8018B3B8();
void func_8018B3D8();
void func_8018E5F0();
void func_8018E6F8();
void func_801A6820();
void func_801A8E30();
void func_801B4010();
void func_801B7B40();
void func_801B87C4();
void func_801B9140();
extern u32 D_802AAF60;
extern u32 *D_802AAF64;
extern u32 D_802AAFD0;
extern s16 D_802AAFD8;
extern s16 D_802AAFDA;
extern s16 D_802AAFDC;
extern s16 D_802AAFDE;
extern s16 D_80284D70;
extern f32 D_80106378;
extern f32 D_80284870;
extern f32 D_80284884;
extern f32 D_80284898;
extern f32 D_802848AC;
extern u8 D_8010637C[];
extern u8 D_80106394[];
extern u8 D_802AAFE4;
extern u8 D_802AAFE5;
extern u8 D_802AAFE6;
extern u8 D_802AAFE8;
extern u8 D_802AAFE9;
extern u8 D_802AAFEA;
void func_801BAF6C();

void func_8014AAB8();
void func_80141720(s32 *);
extern u8 D_8028DCF8[];
extern s32 D_801F0198;
extern u8 D_802994CC[];
extern u8 D_8010A4E8[];
extern u8 D_8010A508[];
extern u8 D_8010A52C[];

void func_80155A44(s32 *);
void func_80145680(s32);
void func_8011FD80();

extern s16 D_8028FBF8;
extern s32 D_802901E0;
void func_8011F9F4();
extern s32 D_801E65C0;
extern s32 D_801E65C4;
extern u8 D_801E7535[];
extern s32 D_801EFD00;
extern s32 D_80299398;
extern f32 D_801EFCE0;
extern f32 D_801EFCDC;
extern f32 D_801EFCD8;
extern s16 D_801EAA5C[];
extern s16 D_801EAA5E[];
extern u8 D_801EAA56[];
extern u8 D_801E7534;
extern u8 D_801E7500[];
extern f32 D_80101140;
void func_8011FF40(s32);
void func_80177A14(s32);
void func_8014D548();
extern s32 D_80101938;
extern s8 D_801E7584;
extern s8 D_801EC748;
extern s32 D_801EC7F0;
extern s32 D_802004E0;
extern s32 D_801EC860;
extern u8 *D_80269F40[];
void func_80144F0C();
void func_80144AF8(u8 *, f32, f32);
extern s32 D_80201004;
extern s32 D_8028FB7C;

extern Gfx *D_80202240;
extern Gfx D_801ED4A8[];
extern Gfx D_801ED430[];
extern s32 D_8028DA34;
extern u8 D_801EC7D9;
void func_8014B110(ObjectNode *);
extern Gfx D_801ED4C0[];
extern Gfx D_801ED538[];
typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
} Unk8014B4A4Info;
void func_801C6270(u8 *arg0, s32 arg1, s32 arg2, u16 arg3, u16 arg4, u16 arg5, s16 arg6, s16 arg7, u16 arg8, u16 arg9);
void func_8014B4A4(ObjectNode *);
extern u8 *D_802903A4;
extern u8 *D_8029FA44;
extern f32 D_8028FBCC;
extern f32 D_80290348;
void func_80175388(u8 *, f32);

extern s32 D_8029030C;
extern u8 *D_802903AC;
extern u8 D_8028FBFB;
extern u16 D_80290118[];
extern s32 D_801F19B4;
extern s32 D_8029019C[];
extern s32 D_802900E8;
extern f32 D_8010A91C;
extern f32 D_8010A920;
extern f64 D_8010A924;

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s16 type;
    /* 0x04 */ u8 pad1[0x4C - 4];
    /* 0x4C */ f32 val;
} Func8019BF64Inner;

typedef struct {
    /* 0x00 */ u8 pad0[0x58];
    /* 0x58 */ f32 vx, vy, vz;
    /* 0x64 */ u8 pad1[0xDC - 0x64];
    /* 0xDC */ Func8019BF64Inner *ptr;
} Func8019BF64Obj;

typedef struct {
    s32 x, y, z;
} TrailVec;

typedef struct {
    /* 0x00 */ TrailVec a;
    /* 0x0C */ TrailVec b;
    /* 0x18 */ u8 c;
    /* 0x19 */ u8 d;
    /* 0x1A */ u8 pad[2];
} TrailEntry; /* 0x1C */

typedef struct {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ TrailEntry entries[15];
    /* 0x1AC */ u8 pad1[0x571 - 0x1AC];
    /* 0x571 */ u8 unk571;
    /* 0x572 */ u8 unk572;
    /* 0x573 */ u8 pad2[2];
    /* 0x575 */ u8 idx;
} TrailBuf;
s32 func_8018FF50(s32 *);
extern s32 D_80299378[];
extern s32 D_80299508[];
extern f64 D_801099B8;
extern s32 D_801EFCFC;
void func_80149318(void *, void *);
void func_80167604(s32);
void func_801B7764(void *, s32, s32);

void func_80114740();
extern s32 D_80101F58;
extern f32 D_801EE8E4;
extern f32 D_801EE8EC;

s32 func_801D20F8();
extern u32 D_801FB2A0[];


void func_80151FD0(s32, s32, s32, s32);
void func_80142700(void *, s32);
f32 func_8015B524(void *, s32, void *, s32);
f32 func_8015B878(f32 *, f32 *, f32 *, f32);
extern f32 D_80101DDC;
extern f32 D_8028FB28;
extern s32 D_80299244;
s32 *func_801B5458(s32);
extern f32 D_80105FBC;
extern s32 D_801ED3D0;

void func_80162694();
f32 func_80147460(f32, f32);
f32 func_801496C8(f32);
extern f32 D_8010AA1C;
extern f64 D_8010AA20;
extern f32 D_8010AA28;
typedef struct Obj80189BE8 {
    /* 0x00 */ struct Obj80189BE8 *next;
    /* 0x04 */ u8 pad04[4];
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 pad09[0x3C - 0x09];
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
} Obj80189BE8;
f32 func_8014944C(f32, f32);
void func_801B7494(void *, s32, f32);

extern s32 D_801ED3C4;
typedef struct { s32 a; u16 b; s16 c; f32 d; f32 e; s32 pad; } SpawnTab_801B66D4;
typedef struct { s32 v; s32 p[4]; } SpawnS32_801B66D4;
typedef struct { u16 v; u8 p[18]; } SpawnU16_801B66D4;
typedef struct { s16 v; u8 p[18]; } SpawnS16_801B66D4;
typedef struct { f32 v; s32 p[4]; } SpawnF32_801B66D4;
extern u16 D_801EEC10;
s32 func_801B66D4();
extern s32 D_801EF468;
extern u8 D_801EF46C;
extern u8 D_801EF46D;
extern u8 D_801EF46E;
extern u8 D_801EF46F;
extern u8 D_801EF470;
extern u8 D_801EF471;
extern f32 D_8029F9E8;
void func_8014ACB4();
void func_8014AC1C();

extern s32 D_801EEBEC;

extern s32 D_801EF480;
extern s32 D_801EF488;
s32 func_801783A8(s16, s32, s16, s16, f32);
extern f64 D_801086EC;
void func_801C0B70();

void func_80181FC4();

void func_8015CB44();
extern s32 D_801F1F14[];
extern s32 D_802900F0;
void func_8015C840();

void func_801D211C();

void func_8018B650();
void func_8018BFA4();
extern s32 D_801EFD08[];
extern u8 D_8028FDD0[];
extern u8 D_8029F488[];
extern s32 D_8029F550;
extern s32 D_8028FE98;
extern f32 D_8029F504;
extern f32 D_8028FE4C;
extern f64 D_801096A4;
extern f64 D_801096AC;
extern f32 D_8010B460;
extern f32 D_8010B464;
extern f64 D_8010B468;
extern f32 D_8010B470;
extern f32 D_8010B474;
extern f64 D_8010B478;
extern f32 D_801F1A7C;

void func_8018D39C();

extern s32 D_802994B4;
extern u8 D_801EEBAC;
s32 func_8018FE98();
void func_8018E914();
extern u8 D_80299940[];
extern u8 D_802999E8[];
extern u8 D_802996E8[];
extern u8 D_80299708[];
extern u8 D_801ED934[];
extern u8 D_802997B0[];
void func_80195224(s32);
extern s32 D_802999B0[][0xC0];
extern u8 D_802999B8[];
extern u8 D_802999C0[];
extern u8 D_802999C2[];
extern u8 D_802999C4[];
extern u8 D_80299962[];
void func_80197794(u8 *arg0, s32 arg1, s32 arg2);
extern f32 D_801F01A0;
extern f32 D_8010A468;
extern f32 D_8010A474;
extern f32 D_8010A478;
void func_8018E888();

void func_80195CD4(s32, s32);
f32 func_801C4030(f32);
f32 sqrtf(f32);
extern f32 D_8010A8B4;
extern f32 D_8010A8B8;
extern f32 D_8010A8BC;
extern f32 D_8010A8C0;
extern f64 D_8010A8C8;
extern f32 D_801F01B0;
extern f32 D_801F01B4;
extern f32 D_80290314;
extern s32 D_801F0198;
extern u8 D_802994CC[];
extern u8 D_8010A4E8[];
extern u8 D_8010A518[];

extern s32 D_801ED8F0;
void func_80191284();
extern s32 D_801F00A8[];
void func_80191794(u8 *, f32, f32, f32, s32, f32, s32);
extern f32 D_801EFDE8[][3];
extern f32 D_80109D3C;
void func_80133900();
void func_801919F4();

s32 func_80178134(s16, f32 *, s16, s16);
void *func_801A9054();

void func_801AA8D4();

extern s16 D_8029011E;
void func_80176AFC();

extern s16 D_802900DC;
extern s32 D_802901DC;
extern s16 D_802902FE;
extern s32 D_8029F468;
extern s16 D_8028FBD8;
extern s32 D_80290300;
extern s32 D_8029F46C;
typedef struct { f32 x, y, z; } Vec3i_B1344;
typedef struct { u8 pad[0x44]; s32 unk44; } Unk_B1344;
extern f32 D_8029F9D0;
extern Vec3i_B1344 D_8029F470;
extern Unk_B1344 *D_8029FA48;
extern u8 D_8029F486;
extern s16 D_8029F47E;
extern s32 D_8029F9A0;
extern s32 D_8029F9A4;
extern s32 D_802900C8;
s32 func_8015C4C8();
s32 func_80198310(u8 *arg0, u8 *arg1);
void func_801963AC();
void func_801964B0();

extern u8 *D_802903B0;
extern s32 *D_802993A4;
extern s32 D_802993A0[];
extern u8 D_801EFD64[];
extern const f32 D_80109624;




/* Tail of func_801C6CEC (overlaid by func_801C6DD4). */

/* 0x801F4764: current render object used by the 0x801D00xx wrappers. */




typedef struct { s32 unk0; s32 count; struct { s32 unk0; s32 unk4; } *items; s32 unkC; } Unk8011CAF8List;
extern Unk8011CAF8List D_8028F82C[];
extern struct { struct { s32 unk0; s32 unk4; } *items; s32 pad[3]; } D_8028F834[];
extern s32 D_8028F7DC[][3];
extern s32 D_801F1B24[][4];
extern u8 D_8028F8E0[];
extern u8 D_8028F9CC[];
extern u8 D_802B0D10[];
extern u8 D_80100E28[];
extern ObjectNode *D_8028D9C0;
void func_80145E30(void);
void func_8014F38C(void);
void func_801456DC(void);
void func_80150EA4(s32);
void func_801627AC(s32);

void func_8011C7F0(void);

void func_8011C810(void);

void func_8011C870(void);

void func_8011C8F4(s32 arg0);

void func_8011CAF8(void);

void func_8011CCF0(void);

/* func_8011CD50 — full game-state reset. Several of the pools below sit next
   to each other in the original binary and are reached through their
   predecessor's symbol here. */
extern u8 D_801ED408;
extern s16 D_801E765A;
extern s16 D_801E7658;
extern s16 D_8028FBF4;
extern s32 D_8029014C;
extern u8 D_8029F58C[];
extern u8 D_80100E30[];
extern u8 D_801EC7D2;
extern Vec3F D_801EC7B0;
extern Vec3F D_801EC7BC;
extern u8 *D_801E76B0;
extern s16 D_801EC7E0;
extern s32 D_8028F814;
extern s32 D_8028FAF4;
extern u8 D_801EC7F4;
extern u8 D_80284E98[];
extern u8 D_80289398[];
extern u8 *D_8028DA38;
extern s16 D_801E7542;
extern u8 D_80100E3C[];
extern u8 D_80289320[];
extern u8 D_8028F5A0[];
extern u8 D_8028F618[];
extern u8 D_8028F708[];
extern u8 D_8028DA40[];
extern u8 D_8028F3D0[];
extern u8 D_801F8BD0[];
extern u8 D_802AA720[];
extern u8 D_802AA828[];
extern u8 D_802AA8A0[];
extern u8 D_801F92F8[];
extern u8 D_802997CC[];
extern u8 D_802996E8[];
extern u8 D_80299708[];
extern s32 D_802999CC[][0xC0];
extern u32 D_802AA9E0[];
extern u8 D_802AA918[];
extern u8 D_802AA7A0[];
extern u8 D_802991A8[];
extern u8 D_8028FC08[];
extern u8 D_802892D8[];
extern s32 D_80299290;

void func_8011CD50(s32 arg0);
static inline void split_externs_8011CD50(void) { extern s16 D_801E753C; }

void func_8011D88C(s32 arg0);
static inline void split_externs_8011D88C(void) { extern u8 D_80100E54[]; extern u8 D_80100E60[]; extern u8 D_80100EA4[]; extern u8 D_80100EB4[]; extern u8 D_80100EC4[]; extern u8 D_80100ED4[]; extern u8 D_80100EE4[]; extern u8 D_80100EF4[]; extern u8 D_80100F04[]; extern u8 D_80100F14[]; extern u8 D_80100F24[]; extern u8 D_80100F34[]; extern u8 D_80100F40[]; extern u8 D_80100F50[]; extern u8 D_80100F60[]; extern u8 D_80100F70[]; extern u8 D_80100F80[]; extern u8 D_80100F8C[]; extern u8 D_80100F98[]; extern u8 D_80100FA4[]; extern u8 D_80100FB4[]; extern f32 D_80101078; extern u8 D_801EC7A4; extern s16 D_801E7468; extern s32 *D_8029F5D0; extern s32 *D_8029F968; extern u8 *D_801F0124; extern u8 D_801EFC92; extern s16 D_801EEB78; extern s32 D_80297908; extern s32 D_80297910; extern s32 D_8029790C; extern s32 D_802AA798; extern s32 D_8029793C; extern s8 D_801E7390[]; extern s8 D_801E7391[]; extern s32 D_801EF494; extern s32 D_801EF894; extern s32 D_801E7590; extern u8 D_801E6938[]; extern s32 D_801EC7CC; extern s8 D_801E7530; extern u8 D_801E6945[]; extern f32 D_801EC7A0; extern u8 D_80202218; s32 func_801A67E4(void); void func_801C066C(s32, s32); void func_80191260(void); void func_8014F510(s32); void func_8014A460(Obj8014A460 *, u8 *, s32, s32, s32, s32); s32 func_80124F2C(s32); void func_80179468(s32); void func_80142A10(void); void func_80177A14(s32); }

void func_8011DF60(void);
static inline void split_externs_8011DF60(void) { extern s8 D_801E7530; extern s32 D_801E747C; extern u8 D_801E7598; extern u8 D_801E7599; extern s32 D_801E7594; extern u8 *D_8028FAC8; extern s32 D_801F7D90[]; extern s32 D_801F7D94; extern s32 D_801F7D98; extern s32 D_801F7DC4; extern f32 D_80101088; extern f32 D_8010108C; extern f32 D_80101090; extern f32 D_80101094; extern s32 D_801EACE0; extern s32 D_801EAD20[]; extern s32 D_801EAD2C[]; extern s32 D_801EAD38[]; extern u8 D_8010107C[]; extern u8 D_80202218; void func_80155AE4(void *); void func_80125040(void); void func_8012643C(void); void func_80145CEC(s32); void func_80145680(s32); void func_8011FD80(void); void func_8011D88C(s32); s32 func_801399EC(s32); void func_8014D4D0(void); s32 func_8014D5E0(void); void func_8011C810(void); void func_801C0A2C(s32, s32); s32 func_801C0B00(s32); void func_8011CD50(s32); void func_8011F9F4(void); void func_8011FB8C(void); void func_8011FF40(s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

void func_8011E51C(void);
static inline void split_externs_8011E51C(void) { extern s16 D_801EAB24; extern u8 D_801EAAEC[]; extern s32 D_801E747C; extern u8 D_80101098[]; extern s32 D_801F7DCC[]; extern f32 D_801010D0; extern f32 D_801010D4; extern f32 D_801010D8; extern u8 D_801010A4[]; extern u8 D_801010B4[]; extern u8 D_801010C0[]; extern u8 D_801010C4[]; extern s32 D_801F7DF8; extern s32 D_801E75A0; extern s32 D_801E75A4; extern s32 D_801E75A8; extern s32 D_801F7DC8; extern u8 D_801E6945[]; extern u8 D_802846F8[]; extern u8 D_80202218; extern s32 D_8028FAF4; extern s32 D_801EFD00; void func_80155AE4(void *); void func_80125040(void); void func_80145CEC(s32); void func_80145680(s32); void func_801C066C(s32, s32); void func_80177A14(s32); void func_8010E6AC(void); s32 func_801399EC(s32); void func_8014D4D0(void); s32 func_8014D5E0(void); void func_8011C810(void); void func_801C0A2C(s32, s32); s32 func_801C0B00(s32); void func_8011CD50(s32); void func_8011F9F4(void); void func_8011FF40(s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

void func_8011EAB8(void);
static inline void split_externs_8011EAB8(void) { extern s16 D_801EAB24; extern u8 D_801EAAEC[]; extern s32 D_801E747C; extern u8 D_801010DC[]; extern u8 D_801010E8[]; extern u8 D_801010F0[]; extern s32 D_801F7E04; extern s32 D_801F7E08; extern s32 D_801F7E0C[][3]; extern s32 D_801F7E90; extern s32 D_801F7E9C; extern s32 D_801F7EA8; extern s32 D_801F7EB4[]; extern s32 D_801F7F74; extern s32 D_801F7F78; extern s32 D_801E75AC; extern s32 D_801E75B0; extern s32 D_801E75B4; extern f32 D_801010F8; extern f32 D_801010FC; extern const f32 D_80101100; extern const f32 D_80101104; extern f32 D_80101108; extern f32 D_8010110C; extern f32 D_80101110; extern f32 D_80101114; extern f32 D_80101118; extern f32 D_8010111C; extern f32 D_80101120; extern f32 D_80101124; extern f32 D_80101128; extern f32 D_8010112C; extern f32 D_80101130; extern f32 D_80101134; extern f32 D_80101138; extern f32 D_8010113C; extern s32 D_801EADA4[]; extern s32 D_801EADC8[]; extern s32 D_801EAE70[]; extern s32 D_801EAE94[]; extern s32 D_801EAEAC[][3]; extern s32 D_801E693C[][14]; extern u8 D_802846F8[]; extern u8 D_80202218; extern u8 D_801EC7D2; extern s32 D_8028FAF4; extern s32 D_801EFD00; extern s8 D_801E7530; extern s32 D_801E58A8; extern s32 D_801E58B4; void func_80155AE4(void *); void func_80125040(void); void func_8012643C(void); void func_80145CEC(s32); void func_80145680(s32); s32 func_8012ABFC(s32); s32 func_8012AC54(s32); s16 func_80145928(u8 *, f32, s32); f32 func_80149724(f32, f32, s32); s32 func_801793DC(s32, u8, u8, u8); void func_8010E6AC(void); void func_8014D4D0(void); s32 func_8014D5E0(void); void func_8011C810(void); void func_801C0A2C(s32, s32); s32 func_801C0B00(s32); void func_8011CD50(s32); void func_80132C04(void); void func_80132DA8(void); void func_8011F9F4(void); void func_8011FF40(s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

void func_8011F9F4(void);
static inline void split_externs_8011F9F4(void) { extern f32 D_8028FB24; extern u8 *D_8028FAC8; extern s32 D_80290194; extern s32 D_80290188; extern u8 D_801E753B; }

void func_8011FB8C(void);
static inline void split_externs_8011FB8C(void) { extern f32 D_8028FB24; extern u8 *D_8028FAC8; extern s32 D_80290188; extern u8 D_801E7536[]; extern f32 D_80101144; extern u8 D_801FA9A8; }

void func_8011FD64(void);

void func_8011FD80(void);

void func_8011FE48(void);

void func_8011FF08(s32 arg0);

void func_8011FF40(s32 level);
static inline void split_externs_8011FF40(void) { extern u8 D_80101148[]; extern u8 D_80101154[]; extern u8 D_8010115C[]; extern u8 D_8010116C[]; extern u8 D_8010117C[]; extern u8 D_80101188[]; extern u8 D_80101194[]; extern u8 D_801011A4[]; extern u8 D_801011B4[]; extern const f32 D_801011B8; extern const f32 D_801011BC; extern const f32 D_801011C0; extern const f32 D_801011C4; extern const f32 D_801011C8; extern const f32 D_80101240; extern s32 D_801ED670; extern s16 D_801E7464; extern s32 D_801EFDC0; extern s16 D_801E7620; extern s16 D_801E7460; extern s32 D_801EC7CC; extern f32 D_801ED680; extern u8 *D_8028FAC8; extern s32 D_801E6940[][14]; extern s32 D_801E693C[][14]; extern s32 D_801EF480; extern s32 D_801EF484; extern s32 D_801EC768; extern u8 *D_801FB260; extern s32 D_801ED3C4; extern f32 D_802978EC; extern f32 D_802978F4; extern f32 D_802978F8; extern f32 D_802978FC; extern u8 D_8028DA60, D_8028DA61, D_8028DA62; extern u8 D_8028DAD4, D_8028DAD5, D_8028DAD6; extern u8 D_8028DB48, D_8028DB49, D_8028DB4A; extern u8 D_8028DBBC, D_8028DBBD, D_8028DBBE; extern u8 D_8028DC30, D_8028DC31, D_8028DC32; extern u8 D_8028F3F3[]; extern u8 *D_80289390; extern u8 D_801F1BE4[]; extern s32 D_80284DC4[][6]; extern s32 D_80284DCC[][6]; extern u8 D_80284DE3; extern u8 D_80284E13; extern s32 D_80284DEC; extern s32 D_80284E1C; extern s32 D_80284DD4; extern s32 D_80290198; extern s8 D_801E7530; extern u8 D_801EAA58[]; void func_8014707C(void); void func_80155A44(s32 *); void func_80145E30(void); s32 func_801526C4(s32); void func_80141874(void); void func_8011D88C(s32); void *func_8017DBA0(s32); s32 func_80128D34(void); void func_8014E760(void); void func_8014A460(Obj8014A460 *, u8 *, s32, s32, s32, s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); void func_801BB554(); void func_80178A58(s32, s32, s32); void func_8014D548(void); }

extern u8 D_801E7480[];
extern void *D_80297934;
extern s16 D_80297924, D_80297926, D_80297928, D_8029792A, D_80297930, D_80297932;
extern u8 D_80101244[];
extern u8 D_80101254[];
extern f32 D_80101264, D_80101268, D_8010126C, D_80101270, D_80101274, D_80101278;
extern f32 D_8028D864, D_8028D868, D_8028D8A4, D_8028D8A8, D_8028D8AC;
extern f32 D_8028D950, D_8028D954, D_8028D90C, D_8028D910, D_8028D994, D_8028D998, D_8028D99C;
extern s16 D_8028D80E, D_8028D8FE;
extern u8 *D_8028D9A0[];
extern u8 D_8028D974[];
void func_80142928(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);

void func_80120A90(void);

extern s16 D_801F91A8;
void func_80120D18(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
static inline void split_externs_80120D18(void) { extern void *volatile D_80269F58; extern void *volatile D_80269F5C; }

void func_80121FCC(void);

void func_80121FF4(void);
static inline void split_externs_80121FF4(void) { extern s32 D_801E7474; extern s16 D_801E75F4; extern s16 D_801E760C; extern s16 D_801E7600; extern f32 D_801E7604; extern f32 D_801E7608; extern f32 D_801E75F8; extern f32 D_801E75FC; extern f32 D_801E75D0; extern f32 D_801E75D4; extern f32 D_801E75D8; extern s32 D_801E75DC[]; extern s32 D_801E75E8[]; extern f32 D_801F7F88[]; extern f32 D_801F8118[]; extern f32 D_801F7FD4; extern f32 D_801F7FC4; extern s16 D_801F8310[]; extern u8 D_801F830C; extern u8 D_801F82A8[]; extern u8 D_801F82A9[]; extern u8 *D_801F83D8; extern u8 *D_80269F48; extern s32 D_801EAB9C[]; extern s32 D_801EAC2C[]; extern s32 D_801EAC50[]; extern s32 D_801EAC38[]; extern s32 D_801E7398; extern u8 D_801F91B0[]; extern u8 D_802991A0[]; extern s32 D_801013BC[]; extern s32 D_8010127C[]; extern s32 D_801012B0; extern s32 D_801012C0; extern s32 D_801013C4; extern u8 D_801EFC92; extern u8 D_801EC7D2; extern s16 D_801EC7DA; extern u8 D_80202218; extern u8 D_801E7534; extern s16 D_801E7586; extern s8 D_801ED400; extern s8 D_801ED401; extern s8 D_801ED402; extern s8 D_801E7584; extern s32 D_801EC860; extern u8 *D_80269F40[]; extern s8 D_801E7531; extern u8 D_802978E8[]; extern const f32 D_801013D0, D_801013D4, D_801013D8, D_801013DC, D_801013E0, D_801013E4, D_801013E8, D_801013EC, D_801013F0, D_801013F4, D_801013F8, D_801013FC, D_80101400, D_80101404, D_80101408, D_8010140C, D_80101410, D_80101414, D_80101418, D_8010141C, D_80101438, D_8010143C, D_80101440, D_80101444, D_80101448, D_8010144C; extern const f64 D_80101420, D_80101428, D_80101450, D_80101458, D_80101460, D_80101468, D_80101470, D_80101478, D_80101480, D_80101488, D_80101490, D_80101498; void func_8010EEF8(char *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32); void func_8010F94C(void); void func_8011CAF8(void); void func_8011FF40(s32); void func_8012643C(void); s32 func_8012801C(void); s32 func_80128D34(void); void func_8012A738(u8, u8, u8); void func_80133998(void *, s32, s32, s32, f32); s32 func_801399EC(u8); u32 func_80139CA0(u8 *); void *func_8013FCDC(s32, s32, s32 *); void func_80142700(void *, s32); void func_80145680(s32); s16 func_80145928(u8 *, f32, s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); s32 func_80147000(s32); f32 func_80149724(f32, f32, s32); void func_8014AA20(ObjectNode *); void func_8014D4D0(void); void func_8014D548(void); s32 func_8014D5E0(void); void func_8014E760(void); void func_8014E8B4(s32, s32, s32, s32); void func_8014ED2C(void); void func_8014F510(s32); void func_8014FCF8(void *, s32, s32); void func_80150EA4(s32); void func_80155A44(s32 *); void func_80155AE4(void *); void func_8015C350(u8 *, u8 *); void func_80177A14(s32); void func_80188FD8(u8 *); void func_801890EC(u8 *, u8, u8, u8, u8, u8, u8, f32, f32, f32); void func_801891E4(u8 *, u8, u8, u8); f32 func_801C6000(f32); }

void func_80122D68(void);

void func_80122D90(void);
static inline void split_externs_80122D90(void) { extern s32 D_801E7478; extern u8 D_801E760E; extern u8 D_80202218; extern u8 D_801E7544[]; extern u8 D_801014A0[]; extern u8 D_801014AC[]; extern f32 D_801014C0; extern s8 D_801E7530; void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

extern s32 D_801E7614;
extern s32 D_801E7610;

void func_80122F9C(void);

void func_801230A8(void);
static inline void split_externs_801230A8(void) { extern s16 D_801E7468; extern s16 D_801E7618; extern f32 D_801F83E0; extern f32 D_801014C8; extern f32 D_801014CC; extern f32 D_801014D0; extern f32 D_801014D4; extern f32 D_801014D8; extern f32 D_801014DC; extern f32 D_801014E0; extern f32 D_801014E4; extern f32 D_801014E8; extern u8 D_801010E8[]; extern s32 D_801EAB78[]; extern s32 D_801EAB84[]; extern s32 D_801E747C; extern u8 D_80202218; extern s32 D_80290188; void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); void func_8014E8B4(s32, s32, s32, s32); void func_8014ED2C(void); void func_8011CAF8(void); void func_80132648(void); }

void func_80123514(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))

void func_801246AC(void *arg0);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

s32 func_80124F2C(s32 arg0);

extern s8 D_801E7530;

s32 func_80124FF8(void);

void func_80125040(void);
static inline void split_externs_80125040(void) { extern f32 D_801E762C; extern f32 D_801015A8; extern f32 D_801015AC; extern f64 D_801015B0; extern f32 D_801015B8; extern f32 D_801015BC; extern f64 D_801015C0; extern s32 D_801F83E4; extern f32 D_801F83E8; extern f32 D_801F83EC; extern f32 D_801F83F0; extern f32 D_801F83F4; extern f32 D_801F83F8; void func_801490AC(Vec3F *, Vec3F *, f32); void func_80162EAC(f32, f32, s32, s32, s32, s32, s32); }

void func_8012519C(void);
static inline void split_externs_8012519C(void) { void func_801490AC(Vec3F *, Vec3F *, f32); void func_80162EAC(f32, f32, f32, void *, void *, s32, s32); }

void func_80125294(void);
static inline void split_externs_80125294(void) { extern s32 D_801E7470; extern u8 D_801EC7D2; extern s16 D_802902FE; extern s16 D_80299960; extern s32 D_801ED3D0; extern f32 D_801F1A6C; extern s32 D_801EAB54[]; extern s32 D_801EAB60[]; extern s32 D_801F8414; extern s32 D_801F8418; extern f32 D_801F841C; extern f32 D_801F8420; extern f32 D_801F8424; extern f32 D_801015D8; extern f32 D_801015DC; extern f32 D_801015E0; extern f32 D_801015EC; extern const f32 D_801015F0; extern const f32 D_801015F4; extern f64 D_801015F8; extern u8 D_801E764C; extern u8 D_80202218; extern s8 D_801E7530; extern s32 D_80290188; extern f32 D_80290310; void func_8010F94C(void); u8 *func_801AA5BC(s16); void func_801A8E54(u8 *); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

void func_80125794(void);
static inline void split_externs_80125794(void) { extern const f32 D_80101600; extern const f32 D_80101604; extern const f32 D_80101608; extern const f32 D_8010160C; extern const f32 D_80101610; extern const f32 D_80101614; extern const f32 D_80101618; extern const f32 D_8010161C; extern const f32 D_80101620; extern const f32 D_80101624; extern const f32 D_80101628; extern const f32 D_8010162C; extern const f32 D_80101630; extern const f32 D_80101634; extern const f32 D_80101638; extern const f32 D_8010163C; extern const f32 D_80101640; extern const f32 D_8010164C; extern const f32 D_80101650; extern const f32 D_80101654; extern s32 D_802004E0; extern s16 D_801E7468; extern s16 D_801EAB24; extern u8 D_801EAA57; extern u8 D_801EAA56[]; extern f32 D_80290360; extern f32 D_80290354; extern u8 *D_8029F458; extern s32 *D_8029F45C; extern s32 *D_8029FA5C; extern u8 *D_802903B4; extern s32 D_802902D8; extern s32 D_801EEB74; extern s32 D_802901CC; extern s32 D_801F842C; extern s32 D_801F8428; extern s32 D_801F8430; extern u8 D_801E7585; extern f32 D_8029F9AC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern f32 D_8029F9D0; extern f32 D_8029F9D4; extern f32 D_8029F9D8; extern f32 D_801E761C; extern f32 D_8028F95C; extern s32 D_801EFCF8; extern s32 D_801EFCCC; extern s32 D_8029F9A0; extern s32 D_8029F9A4; extern u8 *D_8029FA50; extern s32 D_8029030C; extern u8 *D_802903AC; extern s16 D_8028FBD8; extern s16 D_8029F47E; extern s16 D_8028FBF4; extern u8 D_8028FBFB; extern s32 D_801ED3C4; extern s32 D_801EFCFC; void func_801B392C(s32); void func_801B39DC(s32, s32, f32); void func_80173CE8(s32); void func_8012AD30(s32); void func_80178760(void *); void func_80160228(); void func_8015C350(u8 *, u8 *); void func_80128DF8(s32, s32, s32); void func_80148D0C(f32 *, f32 *, f32); void func_80149568(f32 *); void func_801570AC(u8 *, u8 *, u8 *, u8 *, u8 *, s32); f32 func_80149724(f32, f32, s32); s32 func_80147000(s32); void *func_8017DBA0(s32); void func_801490AC(Vec3F *, Vec3F *, f32); void func_801785E0(s32 *, s16, s16, s32, s16); void func_80178704(s32 *); void func_80149318(void *, void *); void func_80167604(s32); s32 func_80178134(s16, f32 *, s16, s16); void func_80133998(void *, s32, s32, s32, f32); f32 func_801496C8(f32); void func_80189E78(f32 *, f32 *, u8, u8, u8, u8, u16, u16, f32, f32); void func_8018C700(s32, s32); void func_8014D61C(s32, s32, s32, s32, s32); }

void func_8012643C(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

s32 func_8012801C(void);
static inline void split_externs_8012801C(void) { extern s32 D_801E693C[][14]; extern f32 D_801F94CC; extern s32 D_80299394; extern s32 D_80290188; extern u8 D_801FA9A8; }

void func_801282BC(void);
static inline void split_externs_801282BC(void) { extern s32 D_801E747C; extern s16 D_801EC7E0; extern s16 D_801E7668; extern s16 D_801E766A; extern u8 D_801EC7D8; extern u8 D_80202218; extern u8 D_80101720[]; extern s32 D_8028FAC8; void func_8011D88C(s32); void func_8014F510(s32); void func_80155AE4(void *); void func_80125040(); void func_8010F9C0(s32 *); }

void func_8012860C(void);
static inline void split_externs_8012860C(void) { extern s32 D_80000300; extern s32 D_801E7678; extern u8 D_801E7674; extern f32 D_801E766C; extern f32 D_801E7670; extern u8 *D_801F6098; extern u8 D_801EC749; extern u8 D_801F9370[]; extern s8 D_801E7530; extern u8 D_80202218; extern char D_80101728[]; extern char D_80101730[]; extern char D_8010173C[]; extern char D_80101748[]; extern u8 D_80101754[]; extern s32 D_8010127C[]; extern const f32 D_80101760; extern const f32 D_80101764; extern const f32 D_80101768; extern const f32 D_8010176C; extern const f64 D_80101770; extern const f32 D_80101778; extern const f32 D_80101780; void func_8010EEF8(char *, f32, f32, f32, s32, f32, s32, f32, f32, f32, s32); f32 func_80149724(f32, f32, s32); void func_8014AA20(ObjectNode *); void func_8014F510(s32); void func_8014E760(void); void func_8014ED2C(void); void func_80155AE4(void *); void func_801C066C(s32, s32); s32 func_801399EC(u8); void func_8014D4D0(void); s32 func_801793DC(s32, u8, u8, u8); void func_8010F94C(void); void func_8012BEE0(void); }

s32 func_80128D34(void);

extern f64 D_80101788;
extern f32 D_80101794;
extern s32 D_80000300;
extern s32 D_80290198;
extern f32 D_801F94CC;
extern u8 D_801E7541;
extern u8 D_801EC7D2;
extern s32 D_80290188;
extern s32 D_801E746C;

void func_80128DF8(s32 arg0, s32 arg1, s32 arg2);

s32 func_80128F0C(void);

void func_80128F74(void);
static inline void split_externs_80128F74(void) { extern s16 D_801E7468; extern s32 D_802004E0; extern ObjectNode D_8028F350; extern u8 D_8028F8E0[]; extern u8 D_802892D8[]; extern s32 D_8010127C[]; extern s8 D_801ED400; extern s8 D_801ED401; extern s8 D_801ED402; extern s32 D_801ED3C4; extern u8 *D_801F8468; extern s32 D_801E768C; extern u8 *D_801F8478; extern s16 D_801E767C; extern f32 D_801E7680; extern f32 D_801E7684; extern f32 D_801E7688; extern u8 D_8028D7E0; extern u8 D_8028D7E1; extern u8 D_8028D7E2; extern u8 D_80101798[]; extern const f32 D_801017A4; extern const f32 D_801017A8; extern const f32 D_801017AC; extern const f32 D_801017B0; extern const f32 D_801017B4; extern const f32 D_801017B8; extern const f32 D_801017BC; extern const f32 D_801017C0; extern const f32 D_801017C4; extern const f32 D_801017C8; extern const f32 D_801017CC; extern const f32 D_801017D0; extern const f32 D_801017D4; extern const f32 D_801017D8; extern const f32 D_801017DC; extern const f32 D_801017E0; extern const f32 D_801017E4; extern const f32 D_801017E8; extern const f32 D_801017EC; extern const f32 D_801017F0; extern const f32 D_801017F4; extern const f64 D_801017F8; extern const f64 D_80101800; extern const f64 D_80101808; extern const f64 D_80101810; extern const f64 D_80101818; extern const f32 D_80101820; extern const f32 D_80101824; s32 func_80147000(s32); void func_8014AA20(ObjectNode *); void func_8014D61C(s32, s32, s32, s32, s32); void func_80149568(f32 *); void func_801499EC(); void func_801A41B4(Vec3F *, Vec3F *, s16, f32, f32); u8 *func_801AA5BC(s16); void func_801A96A8(); void func_801A8E54(); void func_801A8EF8(); void func_801AE348(u8 *); }

void func_80129AFC(void);
static inline void split_externs_80129AFC(void) { extern s16 D_801E76A4; extern u8 *D_801F847C; extern u8 *D_801F8480[]; extern u8 *D_801F8484; extern u8 *D_801F8488; extern s32 D_801F848C; extern s16 D_801E743C; extern s16 D_801E743E[]; extern s32 D_801EAC68[][3]; extern s16 D_801E7586; extern s16 D_801EC7DA; extern u8 D_8028D7E0; extern u8 D_80101828[]; extern u8 D_801E76A0; extern u8 D_801E76A1; extern u8 D_801E76A2; extern s32 D_801E7690; extern s32 D_801E7694; extern f32 D_801E7698; extern u8 D_802988B8; extern u8 D_802988B9; extern u8 D_802988BA; extern u8 D_802991A0[]; extern u8 D_802991A4; extern u8 D_802991A5; extern u8 D_802991A6; extern u8 D_801F19C0; extern u8 D_801F19C1; extern u8 D_801F19C2; extern s32 D_801ED3C4; extern const f32 D_80101834; extern const f32 D_80101838; extern const f32 D_8010183C; extern const f32 D_80101840; extern const f32 D_80101844; extern const f32 D_80101848; extern const f32 D_8010184C; extern const f32 D_80101850; extern const f32 D_80101854; extern const f32 D_80101858; extern const f32 D_8010185C; extern const f32 D_80101860; extern const f32 D_80101864; extern const f32 D_80101868; extern const f32 D_8010186C; extern const f32 D_80101870; extern const f32 D_80101874; extern const f32 D_80101878; extern const f32 D_8010187C; extern const f32 D_80101880; extern const f32 D_80101884; extern const f32 D_80101888; s32 func_801A2944(f32, u8 *); void func_8014D61C(s32, s32, s32, s32, s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); void func_80145CEC(ObjectNode *); void func_80148CC8(f32 *, f32 *, f32 *, U32F32); s32 func_80147000(s32); u8 *func_801AA5BC(s16); void func_801A96A8(); void func_801A8E54(); void func_801A8EF8(); void func_801AE348(u8 *); void func_801B7344(s32, s32, f32); }

#include "save_data.h"
extern HighScoreEntry D_801EA9E4[];
extern u8 D_801FA9A8;
void func_80132B5C(void);
void func_80132DA8(void);

void func_8012A738(u8 arg0, u8 arg1, u8 arg2);

void func_8012A77C(s32 arg0);

void func_8012A850(void);
static inline void split_externs_8012A850(void) { extern u8 D_802AA7A0[]; extern u8 D_8029F58C[]; extern u8 D_8029F594[]; extern u8 D_80290154[]; extern s32 D_8029014C; extern s16 D_801E765A; }

typedef struct {
    s8 v;
    s8 pad[0x17];
} Unk18;
extern Unk18 D_801E7392[];
extern Unk18 D_801E7394[];

s32 func_8012ABFC(s32 arg0);

s32 func_8012AC54(s32 arg0);
static inline void split_externs_8012AC54(void) { extern u8 D_801E693C[]; }

extern s32 D_801F9628;
extern s32 D_801F962C;
extern s32 D_801F9688;
extern s16 D_801E7542;
void func_8012AE8C(s32 *);


void func_8012ACC0(void);

void func_8012ACE4(s32 *arg0);

void func_8012AD30(s32 arg0);

void func_8012AE00(void);

void func_8012B048(s32 *arg0, s16 *arg1);

void func_8012AE8C(s32 *arg0);

void func_80148D0C(f32 *, f32 *, f32);
void func_80165230(void);
extern u8 D_802993E8[];
extern u8 D_8029941C[];
extern Vec3F D_801F9618;
extern struct { u8 *obj; u8 pad[0x2FC]; } D_80299714[];
extern u8 *D_8028FFC4[];
extern u8 D_80299A1C[];
extern s32 D_801E7588;
extern f32 D_8028FAB0;
extern u8 *D_801F95C0;
extern u8 *D_801F95C4;
extern const u8 D_801018D0[];
extern const f32 D_80101900;
extern const f32 D_80101904;
extern const f64 D_80101908;
extern const f64 D_80101910;
extern const f64 D_80101918;
extern const f64 D_80101920;
extern const f64 D_80101928;
extern const f64 D_80101930;

void func_8012B048(s32 *arg0, s16 *arg1);
static inline void split_externs_8012B048(void) { extern u8 *volatile D_8028FAC8; extern u8 *D_8028FAD0; extern u8 *D_80290304; extern s16 D_802900DA; extern s16 D_801E7620; extern f32 D_8028F938; extern f32 D_8028F93C; extern f32 D_8028F940; extern f32 D_8028FAB4; extern u8 D_802AAFE7; }

s32 func_8012BCA8(void);

extern u8 *D_802903AC;
extern s16 D_8028FBEA;
extern u8 D_80101940[];
extern f32 D_8010194C;
extern f32 D_80101950;
extern f32 D_8029F9B0;
extern f32 D_8029F9B4;
extern f32 D_80290310;
extern f32 D_80290314;
void func_8018C700(s32, s32);

void func_8012BD44(void);

extern s32 D_801EAB30[];
void func_8012BEE0(void);
static inline void split_externs_8012BEE0(void) { extern s32 D_80101954; extern u8 D_801F92F8[]; extern u8 D_80101960[]; extern f32 D_8010196C; extern f32 D_80101970; extern f32 D_80101974; extern u8 D_801EC749; extern s32 D_801EAB30[]; extern s32 D_801EAB3C; extern s32 D_801EAB40; extern s32 D_801EAB44; extern s32 D_801ED62C; extern s32 D_801ED630; extern s32 D_801ED634; void func_8014A50C(void *, u8 *, s32, s32, s32, s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

void func_8012C124(void);
static inline void split_externs_8012C124(void) { extern f32 *D_802997B4; extern u8 D_8029971C[]; extern u8 *D_8028FAC8; extern f32 D_80299744; extern f32 D_80101978; extern f32 D_8010197C; extern f64 D_80101980; extern f32 D_80101988[]; extern f32 D_80101994; extern u8 D_801EC749; extern u8 D_80202218; }



void func_8012C32C(u8 arg0);



extern s16 D_801E6946[];
extern s16 D_801FA754;
extern s16 D_801FA6A0;
extern f32 D_801E76D0;
extern s16 D_801E76D4;
extern s16 D_801E76D6;
extern s16 D_801E76D8;
extern s16 D_801E76DA;
extern s16 D_801E76DC;
extern s32 D_801F7D84;
extern s32 D_801F7D88;
extern u8 D_801019F4[];
extern u8 D_801019FC[];
extern u8 D_80101A08[];
extern u8 D_80101A10[];
extern s32 D_801EAEF4[];
extern s32 D_801EAB9C[];
extern s16 D_801E7460;
extern s16 D_801E7620;
extern f32 D_80101A9C;
extern f32 D_80101AA0;
extern f32 D_80101AA4;
extern f32 D_80101AA8;
extern f32 D_80101AAC;
extern f32 D_80101AB4;
extern f32 D_80101AB8;
extern f32 D_80101ABC;
extern f32 D_80101AC0;
extern f32 D_80101AC4;
extern f32 D_80101AC8;
extern f32 D_80101ACC;
extern f32 D_80101AD0;
extern f32 D_80101AD8;
extern f32 D_80101AE4;
extern f32 D_80101AE8;
extern f32 D_80101AEC;
extern f32 D_80101AF4;
extern f32 D_80101AF8;
extern f32 D_80101AFC;
extern f32 D_80101B00;
extern f32 D_80101B04;
extern f64 D_80101B08;
extern f64 D_80101B10;
extern f32 D_80101B18;
extern f32 D_80101B20;
extern f32 D_80101B2C;
extern f32 D_80101AB0;
extern f32 D_80101AD4;
extern f32 D_80101AF0;
void func_8012C5E0(void);
static inline void split_externs_8012C5E0(void) { extern s32 D_80000300; extern s32 D_80290428; extern u8 D_801EC7D2; extern u8 D_801F92F8[]; extern s32 D_801E693C[][14]; extern u8 D_801E6790[]; void func_8014A50C(void *, u8 *, s32, s32, s32, s32); void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); s32 func_801793DC(s32, u8, u8, u8); }

void func_8012D22C(void);
static inline void split_externs_8012D22C(void) { extern f32 D_80101B30; extern f32 D_80101B34; extern s32 D_80299954; extern f32 D_801E76E0[]; }

void func_8012D3D4(u8 *arg0, s32 arg1);

void func_8012D478(void);
static inline void split_externs_8012D478(void) { extern const f32 D_80101B80; extern const f32 D_80101B84; extern const f32 D_80101B88; extern const f32 D_80101B8C; extern s32 D_80101B54; extern s32 D_80101B60; extern u8 D_80101B6C; extern u8 D_80101B78; extern const f32 D_80101B90; extern const f32 D_80101B9C; extern const f32 D_80101BA0; extern const f32 D_80101BA4; extern const f32 D_80101BA8; extern const f32 D_80101BAC; extern const f32 D_80101BB0; extern const f32 D_80101BB4; extern const f32 D_80101BB8; extern const f32 D_80101BC4; extern const f32 D_80101BC8; extern const f32 D_80101BCC; extern const f64 D_80101BD0; extern const f64 D_80101BD8; extern const f32 D_80101BE0; extern const f32 D_80101BE4; extern const f32 D_80101BE8; extern const f32 D_80101BEC; extern const f32 D_80101BF0; extern const f32 D_80101BF4; extern const f32 D_80101BF8; extern const f32 D_80101BFC; extern const f32 D_80101C00; extern const f32 D_80101C0C; extern const f32 D_80101C10; extern const f32 D_80101C1C; extern const f32 D_80101C20; extern const f32 D_80101C2C; extern const f32 D_80101C30; extern const f32 D_80101C34; extern const f32 D_80101C38; extern const f32 D_80101C3C; extern const f32 D_80101C40; extern const f32 D_80101C44; extern const f32 D_80101C48; extern const f32 D_80101C4C; extern const f32 D_80101C50; extern const f32 D_80101C54; extern const f32 D_80101C58; extern const f32 D_80101C5C; extern const f64 D_80101C60; extern const f32 D_80101C68; extern const f32 D_80101C6C; extern const f32 D_80101C70; extern const f32 D_80101C74; extern const f32 D_80101C78; extern const f32 D_80101C7C; extern const f64 D_80101C80; extern const f32 D_80101C88; extern const f32 D_80101C8C; extern const f32 D_80101C90; extern const f32 D_80101C94; extern const f64 D_80101C98; extern const f32 D_80101CA0; extern const f32 D_80101CA4; extern const f64 D_80101CA8; extern const f32 D_80101CB0; extern const f32 D_80101CB4; extern const f64 D_80101CB8; extern const f32 D_80101CC0; extern const f32 D_80101CC4; extern const f32 D_80101CC8; extern const f32 D_80101CCC; extern const f32 D_80101CD0; extern const f32 D_80101CD4; extern const f32 D_80101CD8; extern const f32 D_80101CDC; extern const f32 D_80101CE0; extern const f32 D_80101CE4; extern const f32 D_80101CE8; extern const f32 D_80101CEC; extern const f32 D_80101CF0; extern const f32 D_80101CF4; extern const f64 D_80101CF8; extern const f32 D_80101D00; extern const f32 D_80101D04; extern const f32 D_80101D08; extern const f32 D_80101D0C; extern const f32 D_80101D10; extern const f32 D_80101D1C; extern const f64 D_80101D20; extern const f32 D_80101D28; extern u8 D_801E76F0; extern u8 D_801E76F1; extern u8 D_801E76F2; extern u8 D_801E76F3; extern s32 D_801FA780; extern s32 D_801FA78C; extern f32 D_801FA790; extern f32 D_801FA814; extern f32 D_801FA818; extern f32 D_801FA81C; extern u8 D_801FA840; extern s32 D_801FA868; extern f32 D_801FA874; extern f32 D_801FA878; extern f32 D_801FA87C; extern f32 D_801FA898; extern f32 D_801FA89C; extern f32 D_801FA8A0; extern f32 D_801FA8B0; extern f32 D_801FA8B8; extern f32 D_801FA8BC; extern f32 D_801FA8C8; extern f32 D_801FA8D0; extern f32 D_801FA8D4; extern s32 D_801FA8DC; extern f32 D_801FA8FC; extern f32 D_801FA900; extern f32 D_801FA904; extern s32 D_801FA908; extern f32 D_801FA930; extern f32 D_801FA934; extern f32 D_801FA938; extern f32 D_8025D678; extern f32 D_8025D67C; extern f32 D_8025D680; extern u8 *D_8028FAC8; extern s32 D_8028FB94; extern s32 D_8028FB14; extern s32 D_8028FB74; extern f32 D_8028FB18; extern f32 D_8028FB1C; extern f32 D_8028FB24; extern u8 *D_802997BC; extern f32 D_8029F9D8; s32 func_80133E24(u8 *, f32); s32 func_80147000(s32); f32 func_80148E48(f32 *a, f32 *b); void func_801490AC(Vec3F *, Vec3F *, f32); void func_80149428(f32 *arg0, f32 *arg1, f32 *arg2); void func_80149568(f32 *); void func_8014D61C(s32, s32, s32, s32, s32); void *func_80152220(s32, u32); void func_8015CC70(f32 *arg0, f32 *arg1); void func_8015D020(u8 *); void func_8016049C(u8 *arg0, f32 arg1, f32 arg2); void func_801743A8(s32 arg0, s16 arg1); Unk802904D4Node *func_8017DBD8(Unk802904D4Node *arg0, s32 arg1); void func_80195D50(); s32 func_801A2944(f32, u8 *); void func_801B0DDC(void); void func_801B9974(u8 *, s32, f32, f32, s32, s32); }

void func_8012EFD0(void);
static inline void split_externs_8012EFD0(void) { extern u8 D_80101D2C; extern s32 D_80101D3C; extern const f32 D_80101D4C; extern const f32 D_80101D50; extern const f32 D_80101D54; extern const f32 D_80101D58; extern const f32 D_80101D5C; extern const f32 D_80101D60; extern const f32 D_80101D64; extern const f32 D_80101D68; extern const f32 D_80101D6C; extern const f32 D_80101D70; extern const f32 D_80101D74; extern const f32 D_80101D78; extern const f32 D_80101D84; extern const f64 D_80101D88; extern const f32 D_80101D90; extern const f32 D_80101D94; extern const f32 D_80101D98; extern const f32 D_80101D9C; extern const f32 D_80101DA0; extern const f32 D_80101DA4; extern const f32 D_80101DA8; extern const f32 D_80101DAC; extern const f32 D_80101DB0; extern const f32 D_80101DB4; extern const f32 D_80101DB8; extern const f32 D_80101DBC; extern const f32 D_80101DC0; extern const f32 D_80101DC4; extern const f32 D_80101DC8; extern const f32 D_80101DCC; extern const f32 D_80101DD0; extern const f32 D_80101DD4; extern const f32 D_80101DD8; extern s16 D_801E76F8; extern u8 D_801E76FA; extern u8 D_801E76FC; extern u8 D_801E76FD; extern s32 D_801E7700; extern s32 D_801E7704; extern u8 D_801E7708; extern Unk802904D4Node *D_801FA6A4; extern f32 D_801FA6A8; extern f32 D_801FA6AC; extern f32 D_801FA6B4; extern f32 D_801FA6B8; extern s32 D_801FA780; extern s32 D_801FA78C; extern s32 D_801FA7F4; extern void *D_801FA928; extern s32 D_801FA92C; extern f32 D_801FA930; extern f32 D_801FA934; extern f32 D_801FA938; extern u8 *D_8028FAC8; extern s32 D_8028FB94; extern s32 D_8028FB14; extern s32 D_8028FB74; extern f32 D_8028FB18; extern f32 D_8028FB1C; extern f32 D_8028FB24; extern u8 *D_802900A8; extern f32 D_80290330; extern f32 D_80290334; extern f32 D_80290338; extern s32 D_80299710; extern u8 D_8029971C[]; extern f32 D_80299740; extern f32 D_80299744; extern f32 D_80299748; extern u8 *D_802997C4[]; extern s32 D_802997D0; extern s8 D_8029993C; extern s8 D_8029993D; extern s32 D_80299944; extern s16 D_80299960; extern f32 D_8029F9D8; void func_801305D8(s32 arg0, s32 arg1); s32 func_80133E24(u8 *, f32); s32 func_80147000(s32); extern void func_8014932C(void *, void *); void func_80149428(f32 *arg0, f32 *arg1, f32 *arg2); void func_8014D61C(s32, s32, s32, s32, s32); void func_801743A8(s32 arg0, s16 arg1); void func_80178A58(s32, s32, s32); s32 func_801793DC(s32, u8, u8, u8); Unk802904D4Node *func_8017DBD8(Unk802904D4Node *arg0, s32 arg1); void func_80189E78(f32 *, f32 *, u8, u8, u8, u8, u16, u16, f32, f32); void func_8019321C(u8 *arg0); void func_80196610(u8 *); void func_8019787C(u8 *arg0); s32 func_801A2944(f32, u8 *); void func_801B0DDC(void); void func_801B9974(u8 *, s32, f32, f32, s32, s32); }

void func_801305D8(s32 arg0, s32 arg1);

void func_80130620(Unk802904D4Node *arg0, s32 arg1);

void func_8013067C(void);

void func_8013072C(void);

void func_801308A4(void);
static inline void split_externs_801308A4(void) { extern const f32 D_80101DE0; extern const f32 D_80101DE4; extern const f32 D_80101DE8; extern const f32 D_80101DEC; extern const f32 D_80101DF0; extern const f32 D_80101DF4; extern const f32 D_80101DF8; extern const f32 D_80101DFC; extern const f32 D_80101E00; extern const f32 D_80101E04; extern const f32 D_80101E08; extern const f32 D_80101E0C; extern const f32 D_80101E10; extern const f32 D_80101E14; extern const f32 D_80101E18; extern const f32 D_80101E1C; extern const f32 D_80101E20; extern const f32 D_80101E24; extern const f32 D_80101E28; extern const f32 D_80101E34; extern const f32 D_80101E38; extern const f32 D_80101E44; extern const f32 D_80101E48; extern const f32 D_80101E4C; extern const f32 D_80101E50; extern const f32 D_80101E54; extern const f64 D_80101E58; extern const f32 D_80101E60; extern const f32 D_80101E64; extern const f32 D_80101E68; extern const f32 D_80101E6C; extern const f32 D_80101E70; extern const f32 D_80101E74; extern s32 D_801EEB70; extern s32 D_801EEB74; extern s32 D_8028F908; extern s32 D_8028FB80; extern s32 D_8028FAF8; extern s32 D_8028FAC0; extern s32 D_8028FB74; extern s32 D_8028FAFC; extern f32 D_8028FB00; extern f32 D_8028FB04; extern s16 D_8028FBF6; extern s32 D_8029F460; extern s32 D_8029F0F0; extern s32 D_802996E4; extern f32 D_8029F9D8; s32 func_80133E24(u8 *, f32); s32 func_80147000(s32); s32 func_80148F10(f32 *a, f32 *p); void func_8014D61C(s32, s32, s32, s32, s32); Unk802904D4Node *func_8017DBD8(Unk802904D4Node *arg0, s32 arg1); void func_8019321C(u8 *arg0); void func_801982F0(u8 *a0); void func_801A8E54(u8 *); void func_801A96A8(); u8 *func_801AA5BC(s16); void func_801B760C(u8 *); }

void func_80131424(void);
static inline void split_externs_80131424(void) { extern s32 D_802004E0; extern s32 D_801FA700; extern f32 D_801FA6CC; extern f32 D_801FA6D0; extern f32 D_801FA6D4; extern s32 D_8028F908; extern s32 D_801FA73C; extern s32 D_801FA6FC; extern f32 D_801FA6F0; extern f32 D_801FA6F4; extern f32 D_801FA6F8; extern f32 D_801E7740; extern u8 D_801FA738; extern char D_80101E78[]; extern const f32 D_80101E88; extern const f32 D_80101E8C; extern const f32 D_80101E90; extern const f32 D_80101E94; extern const f32 D_80101E98; extern const f32 D_80101E9C; extern const f32 D_80101EA0; extern const f32 D_80101EA8; extern const f32 D_80101EB0; extern const f32 D_80101EB8; extern const f32 D_80101EC0; extern const f32 D_80101EC8; extern const f32 D_80101ED0; extern const f32 D_80101ED8; extern const f32 D_80101EE4; extern const f32 D_80101EE8; extern const f32 D_80101EF0; extern const f32 D_80101EFC; extern const f32 D_80101F00; extern const f32 D_80101F04; extern const f32 D_80101F08; extern const f32 D_80101F0C; extern const f32 D_80101F10; extern const f32 D_80101F14; extern const f32 D_80101F18; extern s16 D_802902FE; extern f32 D_80290314; extern f32 D_8028F914; extern f32 D_8028F918; extern f32 D_8028F91C; extern f32 D_801E7748; extern s32 D_801EC860; extern u8 *D_80269F40[]; extern u8 *D_802900E0; extern f32 D_80290330; extern f32 D_80290334; extern f32 D_80290338; extern s32 D_8029030C; extern f32 D_80290310; extern s16 D_801E7542; extern s32 D_802901DC; extern s32 D_801F0320; extern u8 *D_801FA708; extern u8 D_801FA71D; extern u8 D_801FA71E; extern u8 D_801FA71F; extern u8 D_801FA720; extern u8 D_801FA722; extern u8 D_801FA723; extern u8 D_801E7744; extern u8 *D_802903AC; extern u8 D_801EC7D2; extern u8 D_80202218; extern f32 D_801E7738; extern f32 D_801E7734; extern u8 D_80290374; extern f32 D_801FA6D8; extern f32 D_801FA6DC; extern f32 D_801FA6E0; extern f32 D_801FA6E4; extern f32 D_801FA70C; extern f32 D_801E772C; extern f32 D_801E7730; extern s32 D_802AA708; extern u8 *D_8028FAC8; extern s32 D_801ED3C4; extern s32 D_801FA750; extern s32 D_801F19B8; extern s32 D_801E773C; extern s32 D_802902D8; void func_8013FBC0(u8 *, s32); void func_8010EEF8(char *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32); void func_8014B7F0(u8 *, s32 *, s16); void func_80149398(void *, void *, f32, void *, f32); void func_80162EAC(f32, f32, f32, s32, s32, s32, s32); f32 func_80149724(f32, f32, s32); void func_80165230(void); }

void func_801320E8(void);
static inline void split_externs_801320E8(void) { extern s32 D_801FA740; extern s32 D_801FA744; extern f32 D_801FA748; extern s32 D_801FA74C; extern u8 D_801FA747; extern u8 D_801F2198[]; extern u8 D_801F21DC[][44]; extern u8 D_801F21BC[]; extern f32 D_80101F1C; extern f32 D_80101F20; extern f32 D_80101F24; extern f32 D_80101F28; extern f32 D_80101F2C; extern const f32 D_80101F30; extern f32 D_80101F34; extern f32 *D_802997B4; extern f32 D_80299744; extern f32 D_80101F38; extern f32 D_80101F3C; extern f64 D_80101F40; extern f32 D_80101F48; extern f64 D_80101F50; extern f32 D_80101F54; extern u8 D_801EC749; extern u8 D_80202218; extern u16 D_801FB280[]; extern s32 D_801F6CB0; extern u8 *D_801EAF00[]; void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); }

s32 func_80132648(void);


extern u8 D_80077070[];
extern u8 D_B04D58A0[];
extern u8 D_B04DA9A0[];
extern u8 D_B04E3EE0[];
extern u8 D_B0607280[];
extern u8 D_801FFE60[];
extern u8 D_8002DC90[];
extern u8 D_801E9CB4[];
extern u8 D_801EA344[];
extern u8 *D_80290418;
extern u8 *D_80290410;
extern u8 D_801EC7AB;
extern s32 D_801E7750;
extern s32 D_801FA940;
extern s32 D_801FA944;
extern s32 D_801FA948;
extern s32 D_801FA94C;
extern s32 D_801FA950;
extern s32 D_801FA954;
extern s32 D_801FA958;
extern s32 D_801FA95C;
extern s32 D_801FA960;
extern s32 D_801FA964;
extern s32 D_801FA970;
extern s32 D_801FA974;
extern s32 D_801FA978;
extern s32 D_801FA97C;
extern s32 D_801FA980;
extern s32 D_801FA984;
void func_80141DD8(u8 *, u8 *, u8 *);
s32 func_801C0300(void *, s32, u8 *);
void func_801C0EC0(u8 *, u8 *);

void func_801326F0(void);

void func_80132880(s32 arg0, s32 arg1, s32 arg2);














extern u8 D_801FA9B0;
void func_80132940(s32);
void func_80132DA8(void);


void func_80132FF4(void);




#pragma GCC optimize ("O0")
void func_80133194(void);

void func_80133264(void);




void func_80133558(s16 arg0);

void func_80133580(s16 arg0);

void func_801335A8(volatile u8 arg0, s32 arg1);

void func_801336E8(void);
static inline void split_externs_801336E8(void) { extern u32 D_801FA9B8[]; extern s32 D_801FA9D0; extern s32 D_801FA9D4; extern u8 D_801EAB08[]; extern u8 D_801EAA14[]; extern u8 D_801E6790[]; extern u8 D_801E6850[]; extern u8 D_801E67AE[]; extern u8 D_801E686E[]; extern u8 D_801E67CC[]; extern u8 D_801E688C[]; extern u8 D_801E67EA[]; extern u8 D_801E68AA[]; extern u8 D_801E6808[]; extern u8 D_801E68C8[]; extern u8 D_801E6826[]; extern u8 D_801E68E6[]; u32 func_80139D14(u8 *arg0, s32 arg1); }


void func_80133900(u8 *arg0);

void func_80133998(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

void func_80133B90(u8 *arg0, s32 arg1);

void func_80133B9C(u8 *arg0);

void func_80133BD0(u8 *arg0);











void func_8013640C(void);




s32 func_801399EC(u8 arg0);

void func_80139ACC(u8 *volatile arg0, volatile f32 arg1, volatile f32 arg2);


/* Builds the 256-entry MSB-first CRC-32 lookup table (polynomial 0x04C11DB7) in D_801FB2A0. */
void func_80139C40(void) {
    s32 byte;
    s32 bit;
    u32 crc;

    for (byte = 0; byte < 0x100; byte++) {
        crc = byte << 24;
        for (bit = 7; bit >= 0; bit--) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ 0x4C11DB7;
            } else {
                crc = crc << 1;
            }
        }
        D_801FB2A0[byte] = crc;
    }
}

/* CRC-32 (MSB-first, poly 0x04C11DB7, table D_801FB2A0) of a NUL-terminated
 * string; used to hash asset names. func_801D20F8 is strlen. */
u32 func_80139CA0(u8 *str) {
    s32 length;
    s32 i;
    u32 crc;
    char pad[4];

    length = func_801D20F8(str);
    i = 0;
    crc = 0;
    if (length > 0) {
        do {
            u32 entry = D_801FB2A0[(crc >> 24) ^ *str];
            do { } while (0);
            i++;
            crc = (crc << 8) ^ entry;
            str++;
        } while (i < length);
    }
    return crc;
}

/* crc32_buffer: CRC-32 (MSB-first, poly 0x04C11DB7, zero seed, table D_801FB2A0
 * built by func_80139C40) of `length` bytes at `data`. Used to checksum save data. */
u32 func_80139D14(u8 *data, s32 length) {
    s32 i;
    u32 crc;
    char pad[4];

    i = 0;
    crc = 0;
    if (length > 0) {
        do {
            u32 entry = D_801FB2A0[(crc >> 24) ^ *data];
            do { } while (0);
            i++;
            crc = (crc << 8) ^ entry;
            data++;
        } while (i < length);
    }
    return crc;
}

/* Original compiler padding. */
const u32 D_80139D6C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

void func_80139D70(s32 arg0);



void func_80139ED4(volatile s32 arg0);

void func_80139F80(void);
static inline void split_externs_80139F80(void) { extern u8 D_80201008[], D_802586EC[], D_80201C40[], D_80258EF8[], D_80201C28[], D_802586F0[], D_801FFE48[], D_8020226C[]; }


void func_8013A1F4(void);





#if 1 /* TEMP bisect */
void func_8013C9BC(void);
static inline void split_externs_8013C9BC(void) { extern s32 D_80105C18; extern s32 D_801EFD50; extern u8 D_8025D0B0; void func_801804A0(s32, void *); void func_80180534(s32); void func_801431AC(void); }












void func_8013E90C(void);





void func_8013FBC0(u8 *arg0, s32 arg1);

void func_8013FC38(s32 arg0, s32 arg1);












extern s32 D_80269F68;
extern s32 D_8026A140;


s32 func_801425D0(s32 **arg0, s16 arg1);

void func_80142700(void *a0, s32 a1);

void func_80142928(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);

extern u8 D_80105FC0[], D_80105FCC[], D_80105FD8[], D_80105FE8[], D_80105FF4[];
extern u8 D_80106004[], D_80106010[], D_8010601C[], D_8010602C[], D_80106038[], D_80106048[], D_80106054[];
extern const f32 D_80106060, D_80106064, D_80106068, D_8010606C, D_80106070;
extern f32 D_80106074, D_80106078;
extern const f32 D_8010607C, D_80106080, D_80106084;

static inline void func_80142A10_load(u8 *p, u8 *name) {
    func_80151FD0((s32)p + 0xC8, func_80139CA0(name), (s32)name, 1);
}

static inline void func_80142A10_init(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, const f32 *scale) {
    typedef struct { s32 a, b, c, d; } Quad32;
    f32 val;

    func_80151FD0((s32)arg0 + 0xC8, func_80139CA0(arg1), arg1, 1);

    if (*(s32 *)((u8 *)arg0 + 0xC8) != 0) {
        func_80142700(arg0, arg5);
        val = *scale;
        *(f32 *)((u8 *)arg0 + 0x34) = arg2;
        *(f32 *)((u8 *)arg0 + 0x38) = arg3;
        *(f32 *)((u8 *)arg0 + 0x3C) = arg4;
        *(f32 *)((u8 *)arg0 + 0xC4) = val;
        *(f32 *)((u8 *)arg0 + 0xC0) = val;
        *(f32 *)((u8 *)arg0 + 0xBC) = val;
        *(Quad32 *)((u8 *)arg0 + 0x9C) = *(Quad32 *)&D_801ED3D0;
    }
}

typedef struct {
    s32 a, b, c, d;
} Quad80142A10;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[0x24];
    /* 0x28 */ s32 flags;
    /* 0x2C */ u8 pad2C[0x8];
    /* 0x34 */ f32 x;
    /* 0x38 */ f32 y;
    /* 0x3C */ f32 z;
    /* 0x40 */ u8 pad40[0x5C];
    /* 0x9C */ Quad80142A10 rot;
    /* 0xAC */ u8 padAC[0x10];
    /* 0xBC */ f32 scaleX;
    /* 0xC0 */ f32 scaleY;
    /* 0xC4 */ f32 scaleZ;
    /* 0xC8 */ s32 model;
    /* 0xCC */ u8 padCC[0x18];
} Obj80142A10; /* size = 0xE4 */

static inline void func_80142A10_setup(Obj80142A10 *obj, s32 name, f32 x, f32 y, f32 z, s32 anim, f32 scale) {
    func_80151FD0((s32)&obj->model, func_80139CA0(name), name, 1);

    if (obj->model != 0) {
        func_80142700(obj, anim);
        obj->x = x;
        obj->y = y;
        obj->z = z;
        obj->scaleZ = scale;
        obj->scaleY = scale;
        obj->scaleX = scale;
        obj->rot = *(Quad80142A10 *)&D_801ED3D0;
    }
}

void func_80142A10(void);
static inline void split_externs_80142A10(void) { extern s32 D_8029F460, D_8029F0F0, D_802996E4; extern u8 D_8029FA60[]; extern f32 D_8029FA3C, D_8029FA38, D_8029FA34; }

void func_8014308C(void);

extern s32 D_80263ABC;
extern u8 D_801EC87C;
extern u8 D_8026A144;
extern u8 D_801EC866;
extern u8 D_801EC7D2;
extern u8 D_8025D0B0;
extern s32 D_801EC870;
extern f32 D_80263AB0;
extern f32 D_80263AB4;
extern f32 D_80263AB8;
extern f32 D_80106098;
extern f32 D_80269EC0;
extern f32 D_80269EC4;
extern f32 D_80269EC8;
extern s32 D_801EC868;
extern u8 *D_80269F38;
extern u16 D_801EC87A;
void func_80143AFC(s32, f32, s32, s32);

void func_801431AC(void);
static inline void split_externs_801431AC(void) { extern u8 D_80106090[]; extern s32 D_8026A054; extern s32 D_80269F84; extern s32 D_80269F80; extern u8 D_801EC7F4; extern s32 D_801EC86C; extern u8 D_801EC7E6; extern u8 D_80263AC0[]; extern u8 D_801EC7D1; extern u8 D_801EC7EB; extern s16 D_801ED404[]; extern s16 D_801ED406[]; extern s32 D_80289310; extern s8 D_801E7530; extern u8 D_801EC7E4; extern u8 D_801EC7EC; void func_801804A0(s32, void *); void func_80180534(s32); void func_801B3D60(void); void func_8015C7C4(ObjectNode *); void func_8013A874(void); void func_80189224(u8 *); void func_8014BB90(void); void func_8014BE1C(u8 *); void func_801A8794(void); void func_801A7AC4(u32); void func_801A7B8C(void); void func_801A6C24(void); void func_80189C9C(void); void func_801BB0A4(void); void func_8013D624(s32, s32); }

void func_801437E4(u8 *arg0);
static inline void split_externs_801437E4(void) { void func_801C61A0(f32 *, s32, s32, s32); void func_801C5F20(f32 *, s32, s32, s32); void func_801C5580(f32 *, f32 *, f32 *); }

extern f32 D_8010609C, D_801060A0, D_801060A4, D_801060A8, D_801060AC, D_801060B0;
extern u8 D_801EC7E2, D_801EC7E3, D_801EC7E4, D_801EC8E4;
extern s16 D_801EC878;
extern s32 D_801EC86C;
void func_80147704(f32 *, f32 *, f32, f32 *);
void func_801488C0(Quat801488C0 *, f32 *, f32 *);
void func_801C565C(void *, f32, f32, f32, f32 *, f32 *, f32 *);
void func_80143AFC(s32 arg0, f32 time, s32 arg2, s32 arg3);
static inline void split_externs_80143AFC(void) { void func_801C61A0(f32 *, s32, s32, s32); void func_801C5F20(f32 *, s32, s32, s32); }

void func_80144AF8(u8 *obj, f32 arg1, f32 arg2);

void func_80144F0C(u8 *arg0);
static inline void split_externs_80144F0C(void) { extern const f32 D_801060B4, D_801060B8, D_801060BC, D_801060C0, D_801060C4, D_801060D0; extern const f64 D_801060C8; extern f32 D_801EC8E8, D_801EC8EC; extern s32 D_801EC8F0; extern s32 D_802004E0; f32 func_80149724(f32, f32, s32); }

s32 func_80145258(u8 *arg0);

extern const f32 D_801060D4, D_801060D8;
void func_80145298(u8 *anim, f32 arg1, s16 arg2, s16 arg3, f32 arg4);
static inline void split_externs_80145298(void) { extern u8 D_80290374; void func_801C61A0(f32 *, f32, f32, f32); void func_801C5B90(f32 *, f32, f32, f32, f32); }




void func_801458E8(void);
static inline void split_externs_801458E8(void) { extern ObjectNode D_80284800; }

s16 func_80145928(u8 *arg0, f32 arg1, s32 arg2);



void func_80145CEC(ObjectNode *arg0);


void func_80145E30(void);
static inline void split_externs_80145E30(void) { extern ObjectNode D_80284800; void func_80145CEC(ObjectNode *); }




void func_80146380(s32 *arg0);


void func_801464BC(s32 arg0, s32 arg1);

void func_801464FC(s32 arg0, s32 arg1);
static inline void split_externs_801464FC(void) { extern s32 D_801ED394; extern s32 D_801ED398; }


void func_80146594(u8 arg0, u8 arg1, u8 arg2, u8 arg3);



void func_801468EC(u8 *dst, u8 *src);

void *func_801469E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, s32 arg8, s32 arg9, s32 arg10);
static inline void split_externs_801469E4(void) { void *func_8013FCDC(s32, s32, s32 *); void func_801468EC(u8 *, u8 *); void func_80145B98(void *, s32); }




s32 func_80147000(s32 arg0);
static inline void split_externs_80147000(void) { extern s32 D_801ED3F0; }

void func_8014707C(void);
static inline void split_externs_8014707C(void) { extern s32 D_801ED3F0; }

void func_80147094(f32 *arg0, f32 *arg1, f32 *arg2);

void func_801470F8(f32 *arg0, f32 *arg1);

f32 func_80147114(f32 arg0);

extern f32 D_801061C0;
extern f32 D_801061C4;
extern f32 D_801061C8[];
extern f32 D_801061D0;
extern f32 D_801061D4;
f32 func_80147260(f32 x);

void func_801473BC(void);

f32 func_801473F8(f32 arg0);

f32 func_80147460(f32 arg0, f32 arg1);

static inline f32 acos_inl(f32 arg0) {
    u8 *data;
    s32 idx;

    data = (u8 *)&D_801D41D0;
    if (D_80106194 < arg0) {
        func_80139D70(func_801D2150(&D_8025D578, D_80106184, (f64)arg0));
        func_80139D94(D_8010618C);
    }
    if (arg0 < D_8010619C) {
        func_80139D70(func_801D2150(&D_8025D578, D_80106184, (f64)arg0));
        func_80139D94(D_8010618C);
    }
    if (arg0 == D_801061A4) {
        return 0.0f;
    }
    idx = (s32)(arg0 * D_801061AC);
    data += idx * 2 + 0x4E20;
    return (f32)*(u16 *)data / D_801061B0;
}

void func_80147704(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3);
static inline void split_externs_80147704(void) { extern f32 D_80106208; extern f32 D_8010620C; extern f32 D_80106210[]; extern f32 D_8010621C; extern f32 D_80106220; extern f32 D_80106224; extern f32 D_80106228; }

s32 func_80147B10(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3);

s32 func_80148000(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3);

void func_801484F0(f32 *q, f32 *m);

void func_80148654(f32 *m, f32 *q);
static inline void split_externs_80148654(void) { extern f32 D_801062F4; extern f32 D_801062F8; extern f32 D_801062FC; extern f32 D_80106300; }

void func_801488C0(Quat801488C0 *out, f32 *a, f32 *b);

void func_801489F0(f32 *arg0, f32 *arg1);

f32 func_801C6000(f32);
f32 func_801C4040(f32);

void func_80148C3C(f32 *arg0, f32 *arg1);
static inline void split_externs_80148C3C(void) { extern f32 D_80106324; }

void func_80148CC8(f32 *arg0, f32 *arg1, f32 *arg2, U32F32 arg3);

void func_80148D0C(f32 *arg0, f32 *arg1, f32 arg2);

void func_80148D50(f32 *arg0, f32 *arg1, f32 arg2);

void func_80148D80(f32 *arg0, f32 *arg1, f32 *arg2, U32F32 arg3);

f32 func_80148DB0(u8 *arg0, u8 *arg1);

f32 func_80148E0C(f32 *arg0, f32 *arg1);

f32 func_80148E48(f32 *a, f32 *b);

f32 func_80148EBC(void *arg0, s32 arg1);

s32 func_80148F10(f32 *a, f32 *p);

s32 func_80148FA8(f32 *arg0, f32 *arg1, f32 arg2);

s32 func_80149044(f32 *arg0, f32 *arg1);

void func_801490AC(Vec3F *arg0, Vec3F *arg1, f32 arg2);


void func_801492D4(f32 *arg0);

void func_801492FC(void *arg0);

void func_80149318(void *arg0, void *arg1);

void func_8014932C(void *arg0, void *arg1);

void func_80149350(f32 *arg0, f32 *arg1);

void func_80149374(f32 *arg0, f32 *arg1, f32 *arg2);

void func_80149398(void *arg0, void *arg1, f32 arg2, void *arg3, f32 arg4);

void func_801493EC(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3, f32 arg4);

void func_80149428(f32 *arg0, f32 *arg1, f32 *arg2);

f32 func_8014944C(f32 a, f32 b);
static inline void split_externs_8014944C(void) { extern f64 D_80106328; extern f64 D_80106330; }

f32 func_801494CC(f32 arg0, f32 arg1);

extern f32 D_80106EC4;

void func_80149568(f32 *arg0);

void func_80149604(f32 *arg0);

void func_80149688(f32 *arg0);

f32 func_801496C8(f32 arg0);

f32 func_80149724(f32 arg0, f32 arg1, s32 arg2);

void func_80149750(void);

void func_801497D4(void *arg0);

void func_80149834(s32 *arg0);

void func_801498CC(void);

void func_80149940(void);

void func_801499A0(s32 arg0, s32 arg1, s32 arg2);

void func_801499EC(Vec3F *out, Vec3F *v, f32 *axis);

void func_80149C4C(f32 *arg0, f32 *arg1);
static inline void split_externs_80149C4C(void) { extern f32 D_801063A0; extern f64 D_801063A4; extern f64 D_801063AC; extern f64 D_801063B4; extern f32 D_801063BC; extern f32 D_801063C0; extern f32 D_801063C4; extern f64 D_801063C8; extern f64 D_801063D0; extern f64 D_801063D8; extern f32 D_801063E0; extern f32 D_801063E4; extern f32 D_801063E8; extern f32 D_801063EC; extern f32 D_801063F0; }

void func_8014A040(u8 *arg0, f32 *arg1, f32 *arg2);
static inline void split_externs_8014A040(void) { extern f32 D_801063F4; extern f64 D_801063F8; extern f64 D_80106400; extern f32 D_80106408; extern f32 D_8010640C; extern f64 D_80106410; extern f64 D_80106418; extern f64 D_80106420; extern f32 D_80106428; extern f32 D_8010642C; extern f32 D_80106430; extern f32 D_801ED3E4; extern f32 D_801ED3E8; }

void func_8014A460(Obj8014A460 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_8014A50C(Obj8014A460 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

typedef struct Unk8014A5C0Tpl {
    /* 0x00 */ s32 unk00[0x11];
} Unk8014A5C0Tpl;

extern s32 D_801ED628;
extern u8 D_80106464[];
extern u8 D_801ED34C[];
void func_8014A760(Obj8014A460 *);

typedef struct Tile8014A760 {
    u16 w;
    u16 fullw;
    u16 xoff;
    u16 z0;
    u8 *ptr;
    u16 h;
    u16 z1;
} Tile8014A760;

void func_8014A5C0(Obj8014A460 *arg0);

void func_8014A760(Obj8014A460 *self);

extern s32 D_8028D9C4;
void func_8014A9D8(void);

void func_8014A9FC(void);

void func_8014AA20(ObjectNode *arg0);

void func_8014AAB8(ObjectNode *arg0);

extern u8 D_8010646C[];

void func_8014AB20(ObjectNode *arg0);

extern u8 D_802892D8[];
extern u8 *D_802892DC;
extern u8 D_802892F9;
extern s32 D_80289310;

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    u8 pad008[0x14];
    u8 unk01C;
    u8 pad01D[0x4];
    u8 flags;
} ListNode;

void func_8014ABEC(void);

void func_8014AC1C(ListNode *arg0, ListNode *arg1);

void func_8014ACB4(u8 *arg0);

void func_8014AD0C(void);
static inline void split_externs_8014AD0C(void) { extern f32 D_80106478; extern f32 D_8010647C; extern f32 D_80106480; extern f32 D_80106484; extern f32 D_80106488; extern f32 D_8010648C; extern f32 D_80106490; extern f32 D_80106494; extern f32 D_80106498; extern f32 D_8010649C; extern f32 D_801064A0; extern f32 D_801064A4; extern f32 D_801064A8; extern f32 D_801064AC; extern f32 D_801064B0; extern f32 D_801064B4; extern f32 D_801064B8; extern f32 D_801064BC; extern s32 D_801ED62C; extern s32 D_801ED630; extern s32 D_801ED634; extern s8 D_801E7530; void func_8014D66C(void); }

extern u8 D_801EC7F4;
extern u8 D_80289218[];
extern u8 D_8028D718[];
extern u8 *D_8028DA38;
extern f32 D_801064C0;
extern f32 D_801064C4;
void func_801CC0E8(u8 *, s32, s32);
void func_801CC010(u8 *, u8, u8, u8, u8);
void func_801CC050(u8 *, f32, f32);
void func_801CD578(u8 *);
void func_801CE22C(Gfx **);

void func_8014B03C(void);

void func_8014B110(ObjectNode *node);

void func_8014B360(void);

void func_8014B4A4(ObjectNode *node);

void func_8014B7F0(u8 *arg0, s32 *arg1, s16 arg2);

void func_8014B8F8(u8 *arg0);

u8 *func_8014BB90(void);

void func_8014BE1C(u8 *arg0);

extern s16 D_801EC7DC;
extern s16 D_80202270;
extern s16 D_80202272;
extern s16 D_80202274;
extern s16 D_80202278;
extern s16 D_8020227A;
extern s16 D_8020227C;
extern f32 D_801064C8;
extern f32 D_801064CC;
extern f32 D_801064D0;
extern f32 D_801064D4;
extern f32 D_801064D8;
void func_8014C6B0(Gfx **, u8 *, f32, f32, s32, s32, s32);
extern f32 D_8028DC8C;
extern f32 D_8028DC90;
extern f32 D_8028DC94;
extern f32 D_8028DC98;
extern f32 D_8028DC9C;
extern f32 D_8028DCA0;
extern f32 D_8028DCA4;
extern f32 D_8028DCA8;
extern f32 D_8028DCAC;
extern f32 D_8028DCB0;
extern f32 D_8028DCB4;
extern f32 D_8028DCB8;
extern f32 D_8028DCBC;
extern f32 D_8028DCC0;
extern f32 D_8028DCC4;
extern f32 D_801064DC;
void func_8014C054(u8 *arg0);
static inline void split_externs_8014C054(void) { extern s32 D_80289314; extern s32 D_80289318; extern f32 D_8028DCC8; extern f32 D_8028DC88[4][4]; }

void func_8014C6B0(Gfx **arg0, u8 *arg1, f32 x, f32 y, s32 z, s32 dsdx, s32 dtdy);
static inline void split_externs_8014C6B0(void) { extern s32 D_80289318; extern f32 D_801064E0; }

extern f32 D_801064E4;
extern f64 D_801064E8;
extern f32 D_801064F0;
extern f32 D_801064F4;
extern f32 D_801064F8;
extern f32 D_801064FC;
extern f32 D_80106500;
extern s32 D_801ED638;
void func_801C5398(f32 mf[4][4], u32 *m);
void func_801C5710(u8 *, u8 *, u8 *);
void func_8014CF98(void);

void func_8014D3AC(void);

void func_8014D4D0(void);

void func_8014D548(void);

s32 func_8014D5E0(void);

s32 func_8014D60C(void);

extern s16 D_801FAA90;
extern s32 D_80290188, D_80290194;
extern s32 D_80284DC0, D_80284DEC, D_80284E1C, D_80284DD4;
extern s32 D_801ED640, D_801ED644, D_801ED648, D_801ED64C;
extern s16 D_801ED650, D_801ED658, D_801ED65A;
extern f32 D_801ED654;
extern f32 D_801F8FF0, D_801F8FF4;
extern f32 D_801F8BDC, D_801F8BE0;
extern u8 *D_802997BC;
extern u8 D_80202218;
extern s8 D_8029F5C8;
extern u8 D_801F19C0;
extern const f64 D_80106520, D_80106528;
extern const f32 D_80106530, D_80106534, D_80106538, D_8010653C, D_80106540, D_80106544;
extern char D_80106510[], D_80106514[], D_80106518[];
extern Gfx D_801ED4A8[], D_801ED430[];
s32 func_801D20F8(u8 *);
s32 func_80147000(s32);


void func_8014D66C(void);
static inline void split_externs_8014D66C(void) { extern s16 D_801FAA92; extern u8 D_801FAAAA, D_801FAAAB, D_801FAAAC, D_801FAAB6, D_801FAAB7, D_801FAAB4, D_801FAAB5, D_801FAAAF; extern s32 D_801FAB70, D_801FAB74, D_801FAB78, D_801FABA0, D_801FABA4, D_801FAB98, D_801FAB9C, D_801FAB84; extern u8 D_801F8CDA, D_801F8CD9, D_801F8CD8, D_801F8D4E, D_801F8D4D, D_801F8D4C; extern u8 D_801F8DC2, D_801F8DC1, D_801F8DC0, D_801F8E36, D_801F8E35, D_801F8E34; extern u8 D_801F8EAA, D_801F8EA9, D_801F8EA8, D_801F8F1E, D_801F8F1D, D_801F8F1C; extern u8 D_801F8F92, D_801F8F91, D_801F8F90, D_801F907A, D_801F9079, D_801F9078; }

void func_8014E760(void);

void func_8014E8B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void split_externs_8014E8B4(void) { extern f64 D_80106590; extern f32 D_80106598; void func_8014E9F4(s32, s32, f32, f32, s32, s32); }

void *func_8014E9F4(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
static inline void split_externs_8014E9F4(void) { extern u8 D_801065A4[]; }

void func_8014ED2C(void);

extern f32 D_8028F938;
extern f32 D_8028F940;
extern const f32 D_801065B4;
extern const f32 D_801065B8;
extern const f32 D_801065BC;
extern const f32 D_801065C0;
extern const f32 D_801065C4;
extern const f32 D_801065C8;
extern const f64 D_801065CC;
extern const f64 D_801065D4;
extern const f32 D_801065DC;
extern const f64 D_801065E0;
extern const f64 D_801065E8;
extern const f32 D_801065F0;
extern const f32 D_801ED65C;
extern const f32 D_801ED660;
extern const f32 D_801ED664;
extern const f32 D_801ED668;

void func_8014ED9C(u8 *arg0);

void func_8014F38C(void);






















void func_80155B90(u8 *arg0, f32 *arg1, f32 arg2);

void func_80155D54(u8 *arg0);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

f32 func_801570AC(u8 *arg0, f32 *arg1, u8 *arg2, f32 *arg3, f32 *arg4, s32 arg5);
static inline void split_externs_801570AC(void) { void func_80147094(f32 *, f32 *, f32 *); void func_8015BA6C(f32 *); void func_8015739C(s16, u8 *, s32); }

void func_8015739C(u32 arg0, u8 *arg1, u32 arg2);
static inline void split_externs_8015739C(void) { extern const f32 D_80106F3C; extern const f64 D_80106F40; extern const f32 D_80106F48; }

typedef struct Phys157708 {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 pad14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ s32 pad1C;
    /* 0x20 */ f32 unk20;
} Phys157708;

typedef struct MeshData157708 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s16 *count;
} MeshData157708;

typedef struct Mesh157708 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ MeshData157708 *data;
} Mesh157708;

typedef struct CollRec157708 {
    /* 0x00 */ f32 radius;
    /* 0x04 */ u8 pad04[0x20];
} CollRec157708; /* size = 0x24 */

typedef struct Coll157708 {
    /* 0x000 */ f32 *plane[4];
    /* 0x010 */ u8 pad010[0x30];
    /* 0x040 */ u8 planeIdx[4];
    /* 0x044 */ s32 count[4];
    /* 0x054 */ u8 pad054[0x1C];
    /* 0x070 */ CollRec157708 rec[4];
    /* 0x100 */ u8 pad100[0x88];
    /* 0x188 */ u8 unk188;
} Coll157708;

/* Physics body: D_8028F8E0, D_8028FCEC and D_8029F978 are instances; also embedded at +0x80 of an actor. */
typedef struct Body157708 {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ struct Body157708 *next;
    /* 0x0C */ u8 pad0C[0x14];
    /* 0x20 */ s16 type;
    /* 0x22 */ u8 pad22[0x4];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s32 flags;
    /* 0x2C */ s32 pad2C;
    /* 0x30 */ f32 radius;
    /* 0x34 */ Vec3F pos;
    /* 0x40 */ Vec3F prev;
    /* 0x4C */ u8 pad4C[0xC];
    /* 0x58 */ Vec3F vel;
    /* 0x64 */ u8 pad64[0xC];
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ u8 pad78[0x50];
    /* 0xC8 */ Mesh157708 *mesh;
    /* 0xCC */ s32 padCC;
    /* 0xD0 */ Phys157708 *phys;
    /* 0xD4 */ u8 *unkD4;
    /* 0xD8 */ Coll157708 *coll;
    /* 0xDC */ s32 padDC;
    /* 0xE0 */ u8 *tris;
} Body157708;

typedef struct Actor157708 {
    /* 0x00 */ struct Actor157708 *next;
    /* 0x04 */ u8 pad04[0x10];
    /* 0x14 */ s32 flags;
    /* 0x18 */ u8 pad18[0x56];
    /* 0x6E */ u16 unk6E;
    /* 0x70 */ u8 pad70[0x10];
    /* 0x80 */ Body157708 body;
} Actor157708;

#define ABSF157708(x) ((x) > 0.0f ? (x) : -(x))
#define DOT157708(a, p) ((a).x * (p)[0] + (a).y * (p)[1] + (a).z * (p)[2])
#define DEPTH157708(i) (ABSF157708(DOT157708(self->vel, self->coll->plane[i])) * D_80106F78)
/* Pool doubles that sit 4 bytes past their label, and the unsigned-to-float fixup the target spells out with one. */
#define FD157708(sym) (*(const f64 *)((const u8 *)&(sym) + 4))
#define UTOF157708(n, two32) ((f32)((s32)(n) < 0 ? (f64)(s32)(n) + (two32) : (f64)(s32)(n)))

void func_80157708(void *arg0);
static inline void split_externs_80157708(void) { extern u8 D_80106F4C[]; extern const f32 D_80106F78; extern const f32 D_80106F7C; extern const f32 D_80106F80; extern const s32 D_80106FA0; extern const f32 D_80106FA8; extern const f32 D_80106FB0; extern const f32 D_80106FB8; extern const f32 D_80106FC0; extern const f32 D_80106FCC; extern const f32 D_80106FD0; extern const f32 D_80106FD8; extern const f64 D_80106FE0; extern const f64 D_80106FE8; extern const f64 D_80106FF0; extern const f32 D_80106FF8; extern const f32 D_80107000; extern const f32 D_80107008; extern const f32 D_80107010; extern const f32 D_80107018; extern const f32 D_80107020; extern f32 D_801ED680; extern u8 D_801ED684; extern f32 D_801ED688; extern s32 D_801ED8D4; extern s32 D_801ED8D8; extern s32 D_801ED8DC; extern s32 D_801ED8E0; extern u8 D_801EEB60; extern s32 D_8028F880; extern s32 D_8028F890; extern f32 *D_8028F89C; extern f32 D_8028F8A0; extern f32 D_8028F8B0; extern f32 D_8028F8B4; extern f32 D_8028F8B8; extern f32 *D_8028F8BC; extern f32 D_8028F8C0; extern f32 D_8028F8C4; extern s32 D_8028F8C8; extern s32 D_8028FCEC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern f32 D_8029F9D4; extern f32 D_8029F9D8; s32 func_80147000(s32); void func_80149568(f32 *); void func_8015CC70(f32 *, f32 *); s32 func_80158F84(u8 *, f32 *, void *); f32 func_80158DC4(f32 *, f32 *, f32, f32 *); s32 func_80178134(s16, f32 *, s16, s16); void func_8017D7B8(u8 *); }

extern f32 D_80107028;

void func_80158D44(f32 *arg0, f32 *arg1);

f32 func_80158DC4(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3);

extern f32 D_8010717C;
extern f64 D_80107180;
extern f64 D_80107188;
extern f64 D_80107190;
extern f64 D_80107198;
extern f64 D_801071A0;
extern f64 D_801071A8;
extern f32 D_801071B0;

s32 func_80158F84(u8 *arg0, f32 *arg1, void *arg2);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
static inline void split_externs_80158F84(void) { extern const f32 D_8010702C; extern const f32 D_80107030; extern const f32 D_80107038; extern const f32 D_80107040; extern const f32 D_80107048; extern const f32 D_80107050; extern const f32 D_80107058; extern const f32 D_80107060; extern const f32 D_80107068; extern const f32 D_80107070; extern const f32 D_80107078; extern const f32 D_80107084; extern const f32 D_80107088; extern const f32 D_8010708C; extern const f32 D_80107090; extern const f32 D_80107094; extern const f32 D_80107098; extern const f32 D_8010709C; extern const f32 D_801070A0; extern const f32 D_801070A4; extern const f32 D_801070A8; extern const f32 D_801070AC; extern const f32 D_801070B0; extern const f32 D_801070B4; extern const f32 D_801070B8; extern const f32 D_801070BC; extern const f32 D_801070C0; extern const f32 D_801070C4; extern const f32 D_801070C8; extern const f32 D_801070CC; extern const f64 D_801070D0; extern const f32 D_801070D8; extern const f32 D_801070DC; extern const f32 D_801070E0; extern const f32 D_801070E4; extern const f32 D_801070E8; extern const f32 D_801070EC; extern const f32 D_801070F0; extern const f32 D_801070F4; extern const f32 D_801070F8; extern const f32 D_801070FC; extern const f32 D_80107100; extern const f32 D_80107104; extern const f32 D_80107108; extern const f32 D_8010710C; extern const f32 D_80107110; extern const f32 D_80107114; extern const f64 D_80107118; extern const f64 D_80107120; extern const f32 D_80107128; extern const f32 D_8010712C; extern const f32 D_80107130; extern const f32 D_80107138; extern const f32 D_80107140; extern const f32 D_80107148; extern const f32 D_80107154; extern const f64 D_80107158; extern u8 D_801ED684; extern f32 D_801ED750[][7]; extern s32 D_801ED8D4; extern s32 D_801ED8D8; extern s32 D_801ED8DC; extern s32 D_801ED8E0; extern f32 *D_8028F880[4]; extern f32 *D_8028F89C; extern f32 D_8028F8A0; extern f32 D_8028F8B0; extern f32 D_8028F8B4; extern f32 D_8028F8B8; extern f32 *D_8028F8BC; extern f32 D_8028F8C0; extern f32 D_8028F8C4; extern f32 D_8028FB4C[]; extern s32 D_80297910; extern f32 D_8029F9B8; extern f32 D_8029F9BC; extern f32 D_8029F9C0; extern f32 D_8029F9D8; extern f32 D_8029F9EC; extern f32 D_801ED680; extern u8 *D_802903B4; f32 func_80158DC4(f32 *, f32 *, f32, f32 *); void func_80149568(f32 *); void func_8015C1D4(u8 *arg0); void func_8015CE38(Vec3F *arg0, u8 *arg1, f32 *arg2, s32 arg3); s32 func_8016225C(u8 *obj, u8 *arg1); void func_801743A8(s32 arg0, s16 arg1); void func_80195D50(); void func_801B0DDC(void); void func_801B10B8(u8 *, f32 *, f32, f32); void func_801B3408(void); void func_801B48DC(f32 arg0, void *arg1, s32 arg2, s16 arg3); void func_801B52BC(f32, f32, f32, f32, s32, f32 *, s32, s16); void func_801B614C(f32 *, f32 *, s32, f32, f32, s32 *); void func_80148C3C(f32 *, f32 *); void func_801489F0(f32 *, f32 *); }

f32 func_8015B524(void *arg0, s32 arg1, void *arg2, s32 arg3);

f32 func_8015B878(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);

void func_8015BA6C(f32 *f);

void func_8015BE58(f32 *f);

void func_8015C1D4(u8 *arg0);

extern s32 D_8026A22C;
extern s32 D_8026A14C;
extern s32 D_8026A13C;
extern s32 D_8026A064;
extern s32 D_8026A060;
extern s32 D_8026A054;
extern s32 D_80269F84;
extern s32 D_80269F80;
extern s32 D_80269F88;


extern const f32 D_801071E4;
extern s8 D_801EFC80[];

void func_8015C350(u8 *arg0, u8 *arg1);

s32 func_8015C4C8(void);

typedef struct TexInfo {
    u8 pad00[0xC];
    u16 w;
    u16 h;
} TexInfo;

typedef struct SprEntry {
    /* 0x00 */ TexInfo *tex;
    /* 0x04 */ u8 *node;
    /* 0x08 */ u8 pad08[6];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 pad12[4];
    /* 0x16 */ u16 flags;
} SprEntry;

typedef struct SprGroup {
    /* 0x00 */ u8 pad00[0xD];
    /* 0x0D */ u8 unk0D;
    /* 0x0E */ u8 pad0E[0x1A];
    /* 0x28 */ s32 count;
    /* 0x2C */ SprEntry *entries;
    /* 0x30 */ u8 pad30[4];
    /* 0x34 */ struct SprGroup *next;
    /* 0x38 */ struct SprGroup *next2;
} SprGroup;

typedef struct SprNode {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ TexInfo *tex;
    /* 0x0C */ s32 v[3];
    /* 0x18 */ u8 pad18[5];
    /* 0x1D */ u8 b, g, r, a;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ s8 ox;
    /* 0x23 */ s8 oy;
} SprNode;

extern u8 D_801071E8[];

typedef struct Obj801B5F74 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u32 flags;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ f32 radius;
    /* 0x34 */ f32 posX;
    /* 0x38 */ f32 posY;
    /* 0x3C */ u8 pad3C[8];
    /* 0x44 */ f32 unk44;
    /* 0x48 */ u8 pad48[0x10];
    /* 0x58 */ f32 velX;
    /* 0x5C */ u8 pad5C[4];
    /* 0x60 */ f32 velZ;
    /* 0x64 */ u8 pad64[0x70];
    /* 0xD4 */ u8 *unkD4;
    /* 0xD8 */ u8 *unkD8;
} Obj801B5F74;

s32 func_80148FA8(f32 *, f32 *, f32);
void func_801B52BC(f32, f32, f32, f32, s32, f32 *, s32, s16);
extern f32 D_8010BB7C, D_8010BB80, D_8010BB84, D_8010BB88, D_8010BB8C, D_8010BB90;
extern f32 D_8010BB94, D_8010BB98, D_8010BB9C, D_8010BBA0, D_8010BBA4, D_8010BBA8;
void func_801B614C(f32 *, f32 *, s32, f32, f32, s32 *);

void func_8015C580(SprGroup *arg0);

static inline s32 *func_8015C758_clear(s32 *p) {
    *p = 0;
    return p - 0x39;
}

void func_8015C758(void);

void func_8015C7C4(ObjectNode *arg0);

void func_8015C840(ObjectNode *arg0);

void func_8015C924(void *arg);

void func_8015CA7C(s32 arg0, s32 arg1);

void func_8015CB44(ObjectNode *arg0);

void func_8015CC70(f32 *arg0, f32 *arg1);

void func_8015CD4C(f32 *arg0, f32 *arg1);

extern f32 D_801071F4;

void func_8015CE38(Vec3F *arg0, u8 *arg1, f32 *arg2, s32 arg3);

void func_8015D020(u8 * arg0);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define DD ((F(f32,F(s32,arg0,216) + _57 * 0x24,116) - F(f32,F(s32,arg0,216) + _57 * 0x24,112)) / D_80107228)
#define LL F(f32,F(s32,arg0,208),76)
#define IN (DD < -LL ? -LL : DD)

s32 func_8015E0A0(void *arg0);
static inline void split_externs_8015E0A0(void) { extern s32 D_802902D8; extern s32 D_8029F978; extern s32 D_8029F9A4; extern u8 *D_8029FA50; extern u8 *D_802903B0; extern u8 *D_802903AC; extern u8 *D_80290090; extern f32 D_80290088; extern u8 *D_80290094; extern u8 *D_802900A8; extern s32 D_802900BC; extern s32 D_80290300; extern f32 D_80290330; extern u8 D_8029F486; extern f32 D_8029F9AC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern f32 D_8029F9D0; extern f32 D_8029F9D8; extern f32 D_801ED680; extern s32 D_801ED3C4; extern s32 D_801ED758; extern u8 D_801ED75C[]; extern u8 D_801FAA94[]; extern u8 D_80202218; extern u8 D_801EEB60; extern s32 D_801EEB64; extern f32 D_8010727C; extern f32 D_80107280; extern f32 D_8010728C; extern f32 D_80107290; extern f32 D_80107294; extern f64 D_80107298; extern const f32 D_801072A0; extern const f32 D_801072A4; extern f32 D_801072A8; extern f32 D_801072AC; extern f32 D_801072B0; extern f32 D_801072B8; extern f32 D_801072C0; void func_801B2B58(s32, f32, f32); void func_801B31A8(s32); void func_80157708(void *); extern void func_8014932C(void *, void *); }

void func_8015EE6C(s32 arg0);
static inline void split_externs_8015EE6C(void) { extern const f32 D_801072CC; extern const f32 D_801072D0; extern u8 D_801EEB60; void func_80160228(); }


extern f32 D_801072D0, D_801072D8, D_801072E4, D_80107328;
extern f64 D_801072E8, D_801072F0, D_801072F8, D_80107300, D_80107308, D_80107310, D_80107318, D_80107320;
s32 func_8015F098(u8 *arg0);
static inline void split_externs_8015F098(void) { extern f32 D_8029FA3C; extern f32 D_8029FA38; extern f32 D_8029FA34; extern u8 *D_8028FAC8; void func_801490AC(Vec3F *, Vec3F *, f32); }

extern f32 D_8010732C;
void func_8015F910(Vec3F *arg0, Vec3F *arg1, f32 *arg2, Vec3F *arg3, Vec3F *arg4, Quat801488C0 *arg5, u8 arg6, s32 arg7, u8 *arg8, u8 *arg9);
static inline void split_externs_8015F910(void) { void func_801490AC(Vec3F *, Vec3F *, f32); }

void func_80160228(s32 arg0, s32 arg1);

void func_8016049C(u8 *arg0, f32 arg1, f32 arg2);

void func_80160610(u8 *arg0, f32 arg1, f32 arg2);

void func_80160728(u8 *arg0, f32 arg1);

void func_80160830(u8 *arg0, f32 arg1);

void func_80160920(s32 arg0, f32 arg1, f32 arg2, void *arg3, s32 arg4);

void func_80160B6C(u8 *arg0, void *arg1, f32 arg2, f32 arg3);

void func_80160CC4(u8 *arg0, u8 *arg1, f32 arg2, f32 arg3);

s32 func_80160E00(u8 *arg0, u8 *arg1, f32 arg2);

s32 func_80160E80(u8 *arg0, f32 *arg1, f32 arg2);

static inline s32 func_8016225C_check(void) {
    s16 s;
    if (D_8028FBFB != 0) {
        return 0;
    }
    if (D_8029F9A4 != (s32)&D_802902D8) {
        return 0;
    }
    s = *(s16 *)(D_802903AC + 4);
    if (s == 3 || s == 5) {
        return 1;
    }
    if ((u16)(s - 0xb) < 2) {
        return 1;
    }
    if ((u16)(s - 0xe) < 2) {
        return 1;
    }
    if (s == 0x10 || s == 0x2b || s == 0x21) {
        return 1;
    }
    return 0;
}

void func_80160EFC(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))

s32 func_8016225C(u8 *obj, u8 *arg1);

void func_801625F0(s32 arg0, s32 flags);

void func_80162694(s32 arg0);

void func_801626EC(s32 arg0);

void func_801627AC(s32 arg0);

void func_801628F4(s32 arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);

void func_80162A38(s32 arg0, f32 *arg1, f32 arg2, f32 arg3, f32 *arg4, s32 arg5);
static inline void split_externs_80162A38(void) { extern f32 D_8010748C; extern f32 D_80107490; extern f32 D_80107494; f32 func_80147114(f32); void func_80160920(s32, f32, f32, void *, s32); }

void func_80162B60(u8 *arg0);


void func_80162BE0(void);
static inline void split_externs_80162BE0(void) { extern u8 D_8028F8E0[], D_8028F9CC[]; extern s16 D_8028F900; extern f32 D_801074C4, D_801074C8, D_801074CC, D_801074D0, D_801074D4; extern f32 D_8028FA3C; extern s32 D_801EEB70, D_801EEB74; extern s16 D_801EEB78; extern f32 D_801EEB7C[], D_8028FB24; extern u8 *D_8028FAC8; void func_80162D18(void); }

void func_80162D18(void);
static inline void split_externs_80162D18(void) { extern const f32 D_801074D8, D_801074DC, D_801074E0, D_801074E4, D_801074E8, D_801074EC, D_801074F0, D_801074F4, D_801074F8; extern s32 D_801EEB70, D_801EEB74, D_8028F908, D_8028FB80, D_8028FAF8, D_8028FAC0, D_8028FB74; extern u8 D_8028F902; extern f32 D_8028F9C8, D_8028FB3C; extern u8 D_80290330[]; extern u8 *D_8028FAD0; extern u8 D_8028F8E0[]; }

extern s32 D_8028FB08, D_8028FAD8;
void func_80162EAC(f32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
static inline void split_externs_80162EAC(void) { extern u8 *D_8028FAC8; extern u8 *D_8028FAD0; extern s32 D_8028FACC; extern s32 D_8028FAD4; extern s32 D_8028FAE4; extern s32 D_8028FAF4; extern s32 D_8028FAF8; extern s32 D_8028FB94; extern f32 D_8028FAB4; extern f32 D_8028FAB8; extern f32 D_8028F93C; extern f32 D_8028F938; extern f32 D_8028F940; }

void func_80162FF8(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define CAM ((Cam *)D_8028F8E0)
#define ABSF(x) ((x) > 0.0f ? (x) : -(x))

s32 func_80164428(void);
static inline void split_externs_80164428(void) { extern f32 D_8028FB60, D_8028FB64, D_8028F938, D_8028F93C, D_8028F940, D_8028F9C8; extern f32 D_80107678, D_80107690, D_8010769C, D_801076A0, D_801076A4; extern const f32 D_8010767C; extern f64 D_80107680, D_80107688, D_80107698; }

extern Vec3F D_8028FAFC;
extern f32 D_80290310;
extern f32 D_8028FB24;
extern s32 D_801EEB70;
extern s32 D_8028FAF8;

void func_801648E0(void);
static inline void split_externs_801648E0(void) { extern u8 D_80202218; extern s32 D_8028FB94, D_8028FB14, D_8028FB74; extern s16 D_8028FB90; extern f32 D_80290330, D_80290334, D_80290338, D_8029F9D4, D_8029F9D8; extern f32 D_8028FB20, D_8028F938, D_8028F93C, D_8028F940; extern u8 D_801EEBC8; extern u8 D_801FAAB4[], D_801FAAB5[], D_801FAAFA[], D_801FAAFB[]; extern u8 *D_8028FAC8; extern f32 D_801076A8, D_801076AC, D_801076B8, D_801076BC, D_801076E8, D_801076F4, D_801076F8; extern const f64 D_801076B0, D_801076C0, D_801076C8, D_801076D0, D_801076D8, D_801076E0; }

void func_80165140(f32 *arg0);

void func_80165230(void);


static inline void cpy3_8016536C(Vec3F *d, Vec3F *s) { *d = *s; }
s32 func_8016536C(s32 arg0, u8 *arg1);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define P(t,sym) F(t, &sym, D_80202218 * 0x190)
#define PD(sym) (*(const f64 *)&sym[1])

void func_80167604(s32 arg0);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define D4(x) (*(const f64 *)((const u8 *)&(x) + 4))
#define W3(x) (*(Words3 *)&(x))

void func_8016A058(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define V(t,s) F(t,&s,0)
#define PCX F(f32,&PC,0)
#define IDX (D_80202218 * 0x190)
#define G(op,v) { s32 *g_ = &D_80290300; *g_ op v; }
#define PD D_802902D8
#define P3 D_80290330
#define PC D_8029030C
#define FB D_8028FBEA
#define B4(t,o) F(t,D_802903B4,o)
#define B0(t,o) F(t,D_802903B0,o)
#define AC(t,o) F(t,D_802903AC,o)
#define FA(t,o) F(t,D_8029FA50,o)
#define C8(t,o) F(t,D_802900C8,o)
#define A8(t,o) F(t,D_802903A8,o)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define TYPEV (*(volatile s32 *)((u8 *)_2 + 24))

void func_80171924(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define DB(x) (*(f64 *)((u8 *)&(x) + 4))

void func_80160B6C(u8 *arg0, void *arg1, f32 arg2, f32 arg3);
void func_8016049C(u8 *arg0, f32 arg1, f32 arg2);
f32 func_80148E48(f32 *a, f32 *b);
void func_8017797C(void);
void func_801B182C(void);
void func_801B1E48(void);
void func_801735E8(void);
static inline void split_externs_801735E8(void) { extern u8 *volatile D_80290090; extern f32 D_8029035C; extern f32 D_80290360; extern f32 D_80290334; extern const f32 D_801082FC; extern const f32 D_80108300; extern const f32 D_80108304; extern const f32 D_80108308; extern const f32 D_8010830C; extern const f64 D_80108310; extern char D_801082E8[]; }

void func_80173CE8(s32 arg0);
static inline void split_externs_80173CE8(void) { extern s16 D_8028FBF4; }

extern s32 D_80290194;
extern f32 D_8028F714;
extern f32 D_8028F718;
extern s32 D_801E7470;
extern s32 D_802900E0;
extern s16 D_8028FBF4;
extern s16 D_8028FBF6;
extern s16 D_8028FB90;
extern s32 D_8028FC04;
extern s8 D_8028FBEC;
extern s32 D_8029014C;
extern f32 D_8010831C;
extern f32 D_80108320;
void func_8017479C(void);
s32 func_80128F0C(void);
void *func_8014E9F4(s32, s32, f32, f32, s32, s32);
void func_801364D0(void);

void func_80149398(void *, void *, f32, void *, f32);

s32 func_80173D28(u8 *arg0, f32 *arg1);
static inline void split_externs_80173D28(void) { extern f32 D_80108318; extern u8 D_80290200[]; }

void func_80173F6C(s16 arg0);
static inline void split_externs_80173F6C(void) { extern s16 D_8028FBEE; extern s16 D_802900DA; extern s32 D_8028FAF4; extern s8 D_801E7530; extern u8 *D_8028FAC8; extern u8 *D_8028FAD0; }

void func_80174058(s16 arg0);

void func_801743A8(s32 arg0, s16 arg1);
static inline void split_externs_801743A8(void) { extern f32 D_80108324; extern s32 D_802901DC; extern s32 D_80284DF0; extern f32 D_80290334; extern f32 D_80290330; extern s32 D_802900A4; extern u8 *D_802903A8; extern s8 D_801E7530; }

void func_8017479C(void);

void func_801748D0(void);

extern s16 D_801E7462;
s32 func_80133E24(u8 *, f32);
void func_801A87CC(s32);

s32 func_80174B58(void);

extern const f32 D_80108334;
extern s32 D_801EF464;
extern const f32 D_80108338;
extern const f32 D_8010833C;
extern const f64 D_80108340;
extern f32 D_8028FE04;
extern f32 D_8028FE08;
extern f32 D_8028FE0C;
extern s16 D_8028FDF0;
extern s32 D_8028F1FC[];
extern const f64 D_80108348;
extern f32 D_8028FE90;
extern const f64 D_80108350;
extern f32 D_8028FE94;
extern const f64 D_80108358;
extern const f32 D_80108360;
extern const f32 D_80108364;
extern const f32 D_80108368;
extern const f32 D_8010836C;
extern const f64 D_80108370;
extern f32 D_8028FEEC;
extern f32 D_8028FEF0;
extern f32 D_8028FF30;
extern s16 D_8028FED4;
extern f32 D_8028FF70;
extern const f64 D_80108378;
extern f32 D_8028FF74;
extern f32 D_8028FF78;
extern const f32 D_80108380;
extern const f32 D_80108384;
extern const f32 D_80108388;
extern const f32 D_8010838C;
extern f32 D_8028FFCC;
extern f32 D_80290014;
extern f32 D_802900E4;
extern const f32 D_80108390;
extern const f32 D_8010839C;
extern void func_801AE2E8(s16, s32, void *);
void func_80174D4C(void);
static inline void split_externs_80174D4C(void) { extern const f32 D_80108334; extern s32 D_801EF464; extern const f32 D_80108338; extern const f32 D_8010833C; extern const f64 D_80108340; extern f32 D_8028FE04; extern f32 D_8028FE08; extern f32 D_8028FE0C; extern s16 D_8028FDF0; extern s32 D_8028F1FC[]; extern const f64 D_80108348; extern f32 D_8028FE90; extern const f64 D_80108350; extern f32 D_8028FE94; extern const f64 D_80108358; extern const f32 D_80108360; extern const f32 D_80108364; extern const f32 D_80108368; extern const f32 D_8010836C; extern const f64 D_80108370; extern f32 D_8028FEEC; extern f32 D_8028FEF0; extern f32 D_8028FF30; extern s16 D_8028FED4; extern f32 D_8028FF70; extern const f64 D_80108378; extern f32 D_8028FF74; extern f32 D_8028FF78; extern s32 D_8028FF7C; extern s32 D_80290060; extern const f32 D_80108380; extern const f32 D_80108384; extern const f32 D_80108388; extern const f32 D_8010838C; extern f32 D_8028FFCC; extern f32 D_80290014; extern f32 D_802900E4; extern const f32 D_80108390; extern const f32 D_8010839C; extern void func_801AE2E8(s16, s32, void *); }

void func_80175388(u8 *arg0, f32 arg1);

void func_8017541C(u8 *arg0);
static inline void split_externs_8017541C(void) { extern u8 D_80290330[]; extern f32 *D_802903A8; extern f32 D_801083A8; void func_80160B6C(u8 *, void *, f32, f32); }

void func_801754C0(u8 *arg0);
static inline void split_externs_801754C0(void) { extern u8 D_80290330[]; extern f32 *D_802903A8; extern f64 D_801083AC; extern f64 D_801083B4; void func_80160B6C(u8 *, void *, f32, f32); }

void func_80175560(void);
static inline void split_externs_80175560(void) { extern volatile s32 D_802900F0; extern u8 *volatile D_8029FA50; }

extern f32 D_801083BC;
extern f64 D_801083C0;
extern f64 D_801083C8;
extern u8 D_801ED75C[];
extern u8 D_801ED764[];
extern f32 D_801EF474;
extern f32 D_80290310;
extern f32 D_80290314;
extern f32 D_80290318;
extern f32 D_8029031C;
extern f32 D_80290320;
extern s16 D_80290148;
extern s16 D_80290108;

void func_8017574C(f32 *arg0);

void func_801758D0(s32 arg0);
static inline void split_externs_801758D0(void) { extern s16 D_802902F8; extern s32 D_801EEBD0; extern s32 D_801EEBD4; extern u8 D_801083D0[]; extern u8 D_801083DC[]; extern u8 D_801083EC[]; extern u8 D_801083F8[]; extern u8 D_80108404[]; extern u8 D_80108410[]; extern u8 D_8010841C[]; extern s32 D_8028FBB8[]; extern u8 *volatile D_802903A8; extern u8 *D_802903A0; extern f32 D_8010842C; extern f32 D_80108430; extern f32 D_80108434; extern f32 D_80108438; extern f32 D_8010843C; extern f32 D_80108440; extern f64 D_80108444; extern f64 D_8010844C; extern f64 D_80108454; extern f32 D_8010845C; extern f32 D_80108460; extern f32 D_80108464; extern f32 D_80108468; extern f32 D_8010846C; extern f32 D_80108470; extern f32 D_80108474; extern f32 D_80108478; extern f32 D_8010847C; extern f32 D_80108480; extern f32 D_80108484; extern u8 D_802902FA; extern f32 D_80290364; extern f32 D_80290358; extern f32 D_8029035C; extern f32 D_80290338; extern f32 D_80290334; extern f32 D_80290330; extern s32 D_80290140[]; extern s32 D_80290144; extern f32 *D_8028FDC4; extern f32 D_8028FD1C; extern s32 D_802901E8; extern s32 D_802901E4; extern s16 D_8028FBEE; extern Blk50 D_801EE4D0; }

void func_80175EC0(void);
static inline void split_externs_80175EC0(void) { extern u8 *D_80290304; extern f32 D_80108488; extern f32 D_8010848C; extern f32 D_80108490; extern f32 D_80108494; extern f32 D_80108498; extern f64 D_8010849C; extern f32 D_801084A4; extern f64 D_801084A8; extern u8 D_80299964[]; extern s16 D_8028FBEA; extern f32 D_80290310; extern f32 D_80290314; }

extern f64 D_801084B0;
extern f32 D_801084B8;
extern f64 D_801084BC;
extern s16 D_80299930;
extern s16 D_8028FBEE;
extern f32 D_80290334;
extern u8 D_801FAAC8[];
extern u8 D_80202218;
extern s16 D_80299960;
extern u8 *D_8028FAC8;
extern u8 *D_8028FAD0;
extern u8 *D_802903A8;

void func_801764A8(void);

void func_801766C0(void);

extern s16 D_8029011C;
extern u8 *D_802903A0;
extern u8 *D_802903A4;
extern u8 *D_802903A8;
extern u8 *D_802903AC;
extern u8 *D_802903B0;
extern s32 D_80290300;
extern s16 D_8028FBD8;
extern f32 D_8028FBCC;
extern f32 D_80290348;
extern f32 D_801F00A0;
extern f32 D_801084DC;
extern f64 D_801084E0;
extern f64 D_801084E8;
extern f64 D_801084F0;
extern u8 D_801084C0[];
extern u8 D_801084C8[];
extern u8 D_801084D0[];
extern f32 D_801084F8;
extern u8 D_80108500[];
extern f32 D_8010850C;
extern s32 D_802996E4;

void func_80176758(void);
static inline void split_externs_80176758(void) { extern Blk50 D_801EEB10; }

void func_80176AFC(void);

extern f32 D_80290310;
extern f32 D_80290314;
extern f32 D_8029F9B0;
extern f32 D_8029F9B4;
extern f32 D_80108554;

s32 func_80176C3C(void);

void func_80176C70(void);
static inline void split_externs_80176C70(void) { extern s32 D_80108520[]; extern s32 D_802901AC; extern s32 D_80297910; extern f64 D_80108530; extern const f32 D_80108534; extern s16 D_8029012C; extern s32 D_80290120[]; extern ObjectNode *D_80290130; void func_801B33A0(u8 *, u8 **, s32 *); void func_801B9974(u8 *, s32, f32, f32, s32, s32); }

void func_80176E9C(void);
static inline void split_externs_80176E9C(void) { extern s16 D_8029012C; extern ObjectNode *D_80290130; extern s32 D_80290120[]; extern f32 D_801EF478; extern f32 D_80108538; extern f32 D_8010853C; extern f32 D_80108540; extern f32 D_80108544; extern f32 D_80108548; extern f32 D_8010854C; extern f32 D_80108550; extern u8 D_80299964[]; extern u8 D_8029970A[]; extern u8 D_80299710[]; extern u8 D_80299720[]; extern u8 D_80299718[]; extern u8 D_8029971C[]; extern u8 D_802997B4[]; }

s32 func_8017723C(void);

void func_80177390(s32 *arg0);
static inline void split_externs_80177390(void) { extern u8 *D_80290140[2]; extern u8 D_80108558[]; extern u8 D_8010855C[]; }

void func_8017753C(void);

void func_80177888(s32 arg0);

void func_80177910(void);

void func_8017797C(void);




void func_801779C0(UnkList *arg0);

void func_801779F0(void);

s32 func_801C08E4(s32, s32, s32, s32, s32);
void func_801C0D40(s32, f32);
void func_801C0DAC(s32, s32);
void func_801C0E3C(s32, s32);
extern f32 D_801086E0;
extern f64 D_801086C8;
extern f64 D_801086D0;
extern f64 D_801086D8;
extern f64 D_801086E4;
extern s32 D_801EF484;
extern u8 *D_8028F9B4;

extern u8 D_B06F8720[], D_B06FB420[], D_B06FE820[], D_B0701460[], D_B0706220[], D_B070C5E0[];
extern u8 D_B07126C0[], D_B07187E0[], D_B071D800[], D_B07245A0[], D_B07282E0[], D_B072DDC0[];
extern u8 D_B07318E0[], D_B07356A0[], D_B07371E0[], D_B073B320[], D_B073E7A0[], D_B07437C0[];
extern u8 D_B0747080[], D_B074C440[], D_B074F5C0[], D_B0752EC0[], D_B0756920[], D_B0758340[];
extern u8 D_B0758CE0[], D_B075C440[], D_B07630A0[], D_B0763DA0[], D_B0765980[], D_B07669C0[];
extern u8 D_B07683A0[], D_B0768D40[], D_B076A8A0[], D_B076D5A0[], D_B076D820[], D_B076DB00[];
extern u8 D_B076DF20[], D_B076E440[], D_B076E700[], D_B076EA80[], D_B076EDC0[], D_B076F0E0[];
extern u8 D_B076F340[], D_B076F540[], D_B076F7C0[], D_B076FB00[], D_B076FD80[], D_B076FF00[];
extern u8 D_B0770200[], D_B0770540[], D_B0770900[], D_B0770CA0[], D_B0771020[], D_B0771340[];
extern u8 D_B07717E0[], D_B0771A60[], D_B0771D60[], D_B0772040[], D_B0775580[], D_B0777420[];
extern u8 D_B077BBE0[];
extern s32 D_80290420;
extern s32 D_80290424;
extern s32 D_80290428;
extern s32 D_80108594;
s32 func_801C0C1C(s32);
s32 func_801C0EE0(s32, s32);
void func_801C0C70(s32, s32);

void func_80177A14(s32 arg0);

extern f64 D_801086A0, D_801086A8, D_801086B0, D_801086C0;
extern f32 D_801086B8, D_801086BC;
s32 func_80178134(s16 arg0, f32 *arg1, s16 arg2, s16 arg3);

s32 func_801783A8(s16 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4);

void func_801785E0(s32 *arg0, s16 arg1, s16 arg2, s32 arg3, s16 arg4);

void func_80178704(s32 *arg0);

void func_80178760(void *arg0);
static inline void split_externs_80178760(void) { extern f64 D_801086F0; extern f64 D_801086F8; extern f64 D_80108700; extern f64 D_80108708; }

void func_80178A48(s32 arg0);

s32 func_801C08E4(s32, s32, s32, s32, s32);
void func_801C0D40(s32, f32);
void func_801C0DAC(s32, s32);
extern f64 D_80108758;

void func_80178A58(s32 arg0, s32 arg1, s32 arg2);
static inline void split_externs_80178A58(void) { extern u8 D_8010870C[]; extern const f64 D_80108714; }

static inline void func_801785E0_inline(s32 *arg0, s16 arg1, s16 arg2, s32 arg3, s16 arg4) {
    extern const f64 D_80108718;
    if (arg1 != 0) {
        s32 h;
        s16 v;
        if (arg0[0] != 0) {
            func_80178704(arg0);
        }
        h = func_801783A8(arg1, arg3, arg2, arg4, *(f32 *)&arg0[6]);
        arg0[0] = h;
        v = (s32)((f32)arg2 * *(f64 *)((u8 *)&D_80108718 + 4));
        if (v > 255) {
            v = 255;
        }
        arg0[1] = v;
        arg0[5] = arg3;
        ((s16 *)arg0)[9] = arg1;
        ((s16 *)arg0)[8] = arg4;
        if (arg0[0] != 0) {
            D_801EF488++;
        }
    }
}

void func_80178B6C(s32 arg0, s32 arg1, s32 *arg2, s16 arg3, u16 arg4, s16 arg5, u16 arg6, s32 arg7, u16 arg8, f32 arg9);
static inline void split_externs_80178B6C(void) { extern u8 D_8010870C[]; extern const f64 D_80108718; }

void func_80178E04(void);

extern const f32 D_80108724, D_80108728, D_8010872C, D_80108730, D_80108738, D_8010873C, D_80108740, D_80108748;
void func_80178E98(void);

s32 func_801793DC(s32 arg0, u8 arg1, u8 arg2, u8 arg3);

extern s16 D_801EF48C;
extern s32 D_801EF490;

void func_80179468(s32 arg0);

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
    /* 0xC */ s32 unkC;
} SoundEntry;

extern s32 D_801EF494;
extern f64 D_80108760;
extern f64 D_80108768;
extern f64 D_80108770;
extern f64 D_80108778;


s32 func_80179480(s16 arg0, s16 arg1);

static __inline__ s32 check_sound1(s16 arg0, s16 arg1) {
    if (D_801EF490 == (s32)&D_801EF494) {
        if (D_802004E0 != arg0 + 4) {
            goto fail;
        }
        return 1;
    }
    if (D_802004E0 != (s16)((s16)(arg0 * 5 << 2) + (f32)((f32)arg1 * *(f64 *)((u8 *)&D_80108760 + 4)))) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}

static __inline__ s32 check_sound2(s16 t, s16 id) {
    if (D_801EF490 == (s32)&D_801EF494) {
        if (D_802004E0 != id + 4) {
            goto fail;
        }
        return 1;
    }
    if (D_802004E0 != (s16)((s16)(id * 5 << 2) + (f32)(*(const f64 *)((const u8 *)&D_80108768 + 4) * (f32)t))) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}

void func_80179524(void);


typedef struct Vec3I179F5C {
    s32 a;
    s32 b;
    s32 c;
} Vec3I179F5C;
typedef struct Sub179F5C {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0xC];
    s32 unk28;
    u8 pad2C[0x48];
    s32 unk74;
} Sub179F5C;
typedef struct Actor179F5C {
    struct Actor179F5C *next;
    struct Actor179F5C *prev;
    u8 pad8[0x1C];
    s32 unk24;
    Sub179F5C *unk28;
    Sub179F5C *unk2C;
    s32 unk30;
    s32 unk34;
    s32 *unk38;
    Sub179F5C *unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 pad5C[0x58];
    f32 x;
    f32 y;
    f32 z;
    u8 padC0[0x5C];
    s32 unk11C;
    u8 pad120[0x40];
    s32 unk160;
    s32 unk164;
} Actor179F5C;
typedef struct Holder179F5C {
    u8 pad0[0x178];
    Actor179F5C *slot[4];
} Holder179F5C;
typedef struct Node179F5C {
    struct Node179F5C *next;
    u8 pad4[8];
    Actor179F5C *unkC;
    s32 *unk10;
    f32 x;
    f32 y;
    f32 z;
    s32 u20;
    s32 u24;
    s32 u28;
    u8 pad2C[0xAC];
    Holder179F5C *holder;
    u8 padDC[8];
    u8 flag;
    u8 padE5[0x3B];
} Node179F5C;

extern u32 D_802904D0;

extern f64 D_801087A8;
extern f32 D_801087B0;
extern f32 D_801087B4;
extern f64 D_801087B8;
extern f32 D_801087A4;
void func_80179810(void);

void func_80179EAC(void);

extern s32 *volatile D_802904D8;

void func_80179ECC(s32 *arg0);

void func_80179F1C(ObjectNode *arg0);

void func_80179F5C(Actor179F5C *arg0, s32 arg1);
static inline void split_externs_80179F5C(void) { extern ObjectNode *D_80290130; }

void func_8017A38C(u8 *arg0);
static inline void split_externs_8017A38C(void) { extern f64 D_801087C0; }

void func_8017A514(u8 *arg0);
static inline void split_externs_8017A514(void) { extern s32 D_802900E0; extern f32 D_801ED680; }

typedef struct { f32 x, y, z; u16 unk0C; s16 unk0E; u8 pad10[0x2]; s16 unk12; s16 unk14; s16 unk16; } Wp6B8;
typedef struct { Wp6B8 *wp[20]; s16 timer; u8 pad52[2]; s8 dir; u8 count; u8 cur; u8 prev; f32 accel; } Path6B8;
typedef struct { u8 pad0[0x38]; f32 unk38; f32 unk3C; u8 pad40[0x20]; f32 unk60; } Rot6B8;
typedef struct { u8 pad0[0x20]; f32 scale; s16 id; u8 pad26[2]; f32 x, y, z; } Link6B8;
typedef struct Obj6B8 { u8 pad0[0x14]; s32 flags; u8 pad18[4]; f32 maxSpeed; struct Obj6B8 *parent; u8 pad24[8]; Rot6B8 *rot; u8 pad30[4]; Link6B8 *link; Path6B8 *path; u8 pad3C[0x3C]; u16 unk78; u8 pad7A[0x3A]; Vec3F pos; u8 padC0[0x18]; f32 vx, vy, vz; u8 padE4[0xC]; f32 damp; f32 speed; } Obj6B8;

void func_8017A6B8(Obj6B8 *o, Vec3F *arg1);

void func_8017AE0C(u8 *arg0, Vec3F *arg1);

void func_8017B178(u8 *arg0);
static inline void split_externs_8017B178(void) { extern f64 D_801087C8; extern f64 D_801087D0; extern const f64 D_801087D8; }

void func_8017B780(u8 *arg0);
static inline void split_externs_8017B780(void) { extern f64 D_801087E0; extern f64 D_801087E8; }

void func_8017BDD0(u8 *arg0);
static inline void split_externs_8017BDD0(void) { extern f64 D_801087F0; extern f32 D_801087F8; extern f64 D_80108800; extern f64 D_80108808; extern f32 D_801EFC84; extern f32 D_801ED680; }

void func_8017C17C(void *arg0);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

void func_8017CF00(Obj8017CF00 *arg0);

extern f32 D_801ED680;
void func_801B4078(s32 *, u8 *, s32);

void func_8017D0FC(u8 *arg0);
static inline void split_externs_8017D0FC(void) { extern f32 D_801ED680; void func_801B4078(s32 *, u8 *, s32); }

void func_8017D21C(Obj8018315C *arg0, f32 arg1);
static inline void split_externs_8017D21C(void) { void func_8017D558(u8 *, f32); }

void func_8017D558(u8 *arg0, f32 arg1);
static inline void split_externs_8017D558(void) { void func_80147094(f32 *, f32 *, f32 *); void func_8015BA6C(f32 *); }

extern f32 D_8010888C;

void func_8017D7B8(u8 *arg0);
static inline void split_externs_8017D7B8(void) { extern f32 D_8010888C; void func_80147094(f32 *, f32 *, f32 *); }

void *func_8017DBA0(s32 arg0);

Unk802904D4Node *func_8017DBD8(Unk802904D4Node *arg0, s32 arg1);

extern f32 D_80108898;
extern f32 D_8029F9B0;
extern f32 D_8029F9BC;
extern s32 D_802900E0;

static inline Unk802904D4Node *findNodeFrom(Unk802904D4Node *list, s32 id) {
    Unk802904D4Node *node;

    node = D_802904D4.next;
    if (node != list) {
        do {
            if (node->unk06C == id)
                return node;
            node = node->next;
        } while (node != &D_802904D4);
    }
    return NULL;
}

static inline Unk802904D4Node *findNodeById(s32 id) {
    Unk802904D4Node *node;
    Unk802904D4Node *head;

    node = D_802904D4.next;
    if (node != &D_802904D4) {
        head = &D_802904D4;
        do {
            if (node->unk06C == id)
                return node;
            node = node->next;
        } while (node != head);
    }
    return NULL;
}

static inline Unk802904D4Node *findNodeW(s32 id) {
    Unk802904D4Node *node = D_802904D4.next;

    while (node != &D_802904D4) {
        if (node->unk06C == id) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void func_8017DC10(void);
static inline void split_externs_8017DC10(void) { extern s32 D_80290430; extern s32 D_80290434; extern f32 D_80290438; extern s32 D_8029043C; extern f64 D_80108890; }

void func_8017E324(s32 arg0);
static inline void split_externs_8017E324(void) { void func_801BB5C4(s32, s32, f32); }

typedef struct { s16 v; u8 pad[0x2FE]; } S16Slot;
extern S16Slot D_80299968[];

void func_8017E49C(void);
static inline void split_externs_8017E49C(void) { extern s8 D_801E7530; extern s32 D_801EFCF8; extern u8 *D_80290304; extern s32 D_8029F574; extern s32 D_8029F56C; extern s32 D_802901E4; extern s32 D_802901E8; extern f32 D_80290330; extern f32 D_80290360; extern f32 D_80290364; extern f32 D_80290358; extern f32 D_80290370; extern f32 D_8029FA34; extern f32 D_8029FA38; extern f32 D_8029FA3C; extern f32 D_8028FB3C; extern f32 D_8028FB44; extern f32 D_8028FB4C; extern f32 D_8028F93C; extern f32 D_8028F9C8; extern f32 D_8029F9D8; extern s16 D_8029F480; extern s16 D_8028FC00; extern const f32 D_8010889C; extern const f64 D_801088A0; extern const f32 D_801088A8; extern const f32 D_801088AC; extern const f64 D_801088B0; extern const f64 D_801088B8; extern const f32 D_801088C0; extern const f32 D_801088CC; extern const f32 D_801088D0; extern const f32 D_801088D4; extern const f32 D_801088D8; extern const f32 D_801088DC; extern const f32 D_801088E0; extern const f32 D_801088E4; extern const f32 D_801088E8; extern const f32 D_801088EC; extern const f64 D_801088F0; extern const f32 D_801088F8; extern const f32 D_801088FC; extern const f32 D_80108900; extern const f32 D_80108904; extern const f32 D_80108908; extern const f32 D_80108914; extern const f32 D_80108918; extern const f32 D_80108920; extern const f32 D_80108928; extern const f32 D_80108930; extern const f32 D_80108938; extern const f32 D_80108944; extern const f32 D_80108948; void func_80160EFC(void); void func_80162FF8(void); void func_801AE244(void); void func_801AE204(s16); void func_801B101C(s32); void func_8015D020(u8 *); void func_80162B60(u8 *); void func_80173CE8(s32); void func_801490AC(Vec3F *, Vec3F *, f32); void func_801BB5C4(s32, s32, f32); }

void func_8017F200(s32 arg0, u8 arg1);


#pragma GCC optimize "O0"
s32 func_8017F660(s32 arg0);




void func_8017FAF4(u8 *arg0, s32 arg1);






void func_801802E0(void);

void func_80180370(void);

void func_801804A0(s32 arg0, void *arg1);
static inline void split_externs_801804A0(void) { extern s32 func_801C62B0(); }

void func_80180534(s32 arg0);
static inline void split_externs_80180534(void) { extern s32 func_801C62B0(); }

void func_80180644(void);


extern f32 D_8028F958;
extern f32 D_801089F4;
extern f32 D_8028F914;
extern f32 D_8028F918;
extern f32 D_8028F91C;
extern f32 D_8028FA00;
extern f32 D_8028FA04;
extern f32 D_8028FA08;
extern u8 D_801EC7D2;
extern u8 D_80297C18[];
extern f32 D_80108DB8;
typedef struct { s32 a, b, c, d; } Quad32;
void func_80180B78(void);
void func_8012643C(void);
void func_801BC43C(void);
void func_8011BCB8(void);
void func_8014915C(Vec3F *arg0, Vec3F *arg1, f32 arg2, s32 arg3);

void func_80180A80(void);

extern s32 D_802902D8, D_8029F978, D_8029030C, D_801ED3C4, D_80297BEC, D_80290428, D_8029F9A0, D_8029F9A4, D_801EFCFC, D_801EC7F0, D_8028F814;
extern u8 *D_802903AC, *D_802903A8;
extern f32 D_8029F9AC, D_8029F9B0, D_8029F9A8, D_8029F9D0, D_8029F9D4, D_8029F9D8, D_801ED680;
extern f32 D_8028F914, D_8028F918, D_8028F91C, D_8028FA00, D_8028FA04, D_8028FA08;
extern u8 D_80202218, D_801EFCA0, D_801EEB60;
extern s8 D_801E7530, D_801E7531, D_8029F487;
extern u8 D_801EAA48[], D_801EAA4C[], D_802991A0[], D_801ED934[], D_802846F8[], D_801E6910[];
s32 func_8015C4C8(void);
void func_801963AC(void);
extern u8 *D_801EFCB4;
extern u8 D_801FB110, D_801FB111, D_801FB10A, D_801FB108, D_801FB0EC, D_801FB0EB, D_801FB0EA, D_801FB10C, D_801FB0F1, D_801FB10D, D_801FB0F2, D_801FB0F3, D_801FB10B, D_801FB107, D_801FB0F6, D_801FB0F7, D_801FB109;
extern s16 D_801FB0D0, D_801FB0D2;
extern f32 D_802978F4, D_802978F8, D_802978FC, D_802978EC, D_802978F0;
extern f32 D_80290308, D_80290310, D_80290314;
extern f32 D_8028F920, D_8028FA0C, D_8029F9B8;
extern u8 D_801FAACA[];
extern s32 D_801EC768, D_801FAA18;
extern u8 *D_801FB260;
extern u8 D_801089F8[];
void func_80189BE8(u8 *, s32, f32, f32);
void func_801B760C(u8 *);
s32 func_8010D4DC(u8 *, s32);
void func_8010D728(s32, void *, s32);
void func_8010D5FC(s32);
extern f32 D_80108A20;
extern f32 D_80108A24;
extern f32 D_80108A80;
extern f32 D_80108A84;
extern f32 D_80108A88;
extern f32 D_80108A8C;
extern f32 D_80108A90;
extern f32 D_80108A94;
extern f32 D_80108A98;
extern f32 D_80108A9C;
extern f64 D_80108A28;
extern f64 D_80108A30;
extern f64 D_80108A38;
extern f64 D_80108A40;
extern f64 D_80108A48;
extern f64 D_80108A50;
extern f64 D_80108A58;
extern f64 D_80108A60;
extern f64 D_80108A68;
extern f64 D_80108A70;
extern f64 D_80108A78;
void func_80180B78(void);

void func_80181A40(u8 *buf, u32 w, u32 h);

void func_80181B4C(void);
static inline void split_externs_80181B4C(void) { extern u8 D_80108AD8[], D_80108AE0[], D_80108AF4[], D_80108B08[], D_80108B18[], D_80108B20[], D_80108B40[]; extern u16 D_80092030[]; extern u8 D_801EC7A8; extern s32 D_801EFCBC; extern s32 func_8010D4DC(u8 *, s32); extern void func_8010D728(s32, void *, s32); extern void func_8010D5FC(s32); }

void func_80181DC8(u8 *arg0, u8 *arg1, u8 *arg2);
static inline void split_externs_80181DC8(void) { extern f32 D_80108B44; extern f32 D_80108B48; extern f32 D_80108B50; extern f32 D_80108B5C; extern f32 D_80108B60; extern f32 D_80108B64; extern f32 D_80108B68; extern f32 D_80108B74; extern f32 D_80108B78; extern f32 D_80108B7C; extern f32 D_80108B80; extern f32 D_80108B88; extern f32 D_80108B94; extern f32 D_80108B98; }

void func_80181FC4(s32 arg0);

void func_80182018(s32 arg0);

/* Level resource loader follows. */
extern ObjectFlagSlot D_80299964[];
extern s16 D_80297C10;
extern u8 *D_801EFDD0;
extern s32 D_801F19BC;
extern s32 D_801F19B8;
extern s32 D_801EFCD4;
extern f32 D_801EFCD0;
extern f32 D_801EFCF4;
extern s32 D_80290430;
extern u8 D_80299678[];
extern ObjectFloatSlot D_80299984[];
extern LevelModelInfo D_801EFDE4[];
extern u8 D_80108C6C[], D_80108C88[], D_80108C90[], D_80108C9C[], D_80108CAC[], D_80108CB8[], D_80108CC4[];
extern const f32 D_80108CE4, D_80108D14, D_80108D18, D_80108D1C, D_80108D20, D_80108D24, D_80108D28, D_80108D2C, D_80108D30;

extern s16 D_80297C12;
extern s16 D_80297C22;
extern s32 D_801EFCF8;
extern s32 D_801EFCCC;
extern f32 D_8029F9B0;
extern f32 D_8029F9B4;
extern u8 D_802993E8[];
extern s8 D_801E7530;

s32 func_80152498(s32);
s32 func_801831FC(s32, s32 *, s32);
s32 func_801835F4(s16, s32 *);
s32 func_80183340(s16, s32 *);
s32 func_80184814(s16, s32 *);
s32 func_80184FC0(s16, s32 *);
s32 func_801852EC(s16, s32 *, u8 *);
s32 func_80186420(s16, s32 *, u8 *);
s32 func_80187444(s16, s32 *, u8 *);
s32 func_801877C0(s16, s32 *, u8 *);
s32 func_801884A4(s16, s32 *, u8 *);
s32 func_80188A5C(s16, s32 *, u8 *);
s32 func_801857D4(s16, s32 *);
void func_8018B3B8(void);
void func_801B6370(void);
void func_8018B44C(s32 *);
void func_80191640(s32, f32, f32, f32, s32, f32);
void func_80182F0C(s32, u8);
void func_801975A8(s32);
void func_8019764C(s32);
void func_801976F0(s32);
void func_80182090(s32 arg0);

void func_80182EB4(s32 arg0, u8 arg1);

void func_80182F0C(s32 arg0, u8 arg1);

void func_80182F64(Obj80182F64 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);

void func_8018315C(Obj8018315C *arg0, Vec3F *arg1, f32 arg2);

extern u8 D_80108DBC[];
extern u8 D_80108DC4[];
extern u8 *D_801EFCEC;

s32 func_801831FC(s32 arg0, s32 *arg1, s32 arg2);

void func_80183240(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);

typedef struct {
    /* 0x00 */ u8 pad0[0xD];
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 sub[0x8];
    /* 0x20 */ u8 *unk20;
    /* 0x24 */ Vec3F pos;
    /* 0x30 */ u8 pad30[5];
    /* 0x35 */ u8 unk35;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 unk37;
    /* 0x38 */ u8 pad38[2];
    /* 0x3A */ u8 unk3A;
    /* 0x3B */ u8 unk3B;
    /* 0x3C */ u8 pad3C[0x14];
    /* 0x50 */ f32 unk50;
} Func80184FC0Obj;

extern u8 *D_80297C0C;
extern u8 D_80109024[];
extern u8 D_80109040[];
extern u8 D_8010904C[];
extern u8 D_80109080[];
extern u8 D_801090B8[];
extern u8 D_80109030[];
extern const f32 D_80109038;
extern const f32 D_8010903C;
extern u8 D_801EFD94[];
void func_8018B3FC(u8 *);
void func_8018B47C(s32 *);
void func_8018B48C(s32 *, s32 *);

s32 func_80183340(s16 arg0, s32 *arg1);

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ u8 sub8[0x14];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u8 sub20[4];
} Func80184814Obj;

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 *unkC;
} Func80184814Obj8;

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14[6];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 *unk24;
} Func80184814Obj4;

s32 func_801835F4(s16 arg0, s32 * arg1);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

extern Func80184814Obj *D_80297C00;
extern Func80184814Obj4 *D_80297C04;
extern Func80184814Obj8 *D_80297C08;
extern u8 D_80108E68[];
extern u8 D_80108E98[];
extern u8 D_80108EC8[];
extern u8 D_80108EFC[];
extern u8 D_80108F2C[];
extern u8 D_80108F38[];
extern u8 D_80108F40[];
extern u8 D_80108F74[];
extern u8 D_80108F7C[];
extern u8 D_80108F88[];
s32 *func_8018E738(void);
void func_8018E660(s32 *arg0, s32 *arg1);
void func_8018E698(ObjectNode *arg0, ObjectNode *arg1);
s32 func_80191024(s32 arg0);
s32 func_801910AC(s32 arg0);
s32 func_80184814(s16 arg0, s32 *arg1);

s32 func_80184FC0(s16 arg0, s32 *arg1);

s32 func_801852EC(s16 arg0, s32 *arg1, u8 *arg2);

s32 func_801857D4(s16 arg0, s32 *arg1);
static inline void split_externs_801857D4(void) { extern s32 D_80290430; extern s32 D_80290434; extern f32 D_80290438; extern s32 D_8029043C; extern s16 D_80297C12; extern s16 D_80297C22; extern u8 D_801090C4[]; extern u8 D_801090D0[]; extern u8 D_801090E8[]; extern u8 D_801090F4[]; extern u8 D_80109100[]; extern u8 D_80108CAC[]; extern f32 D_8010910C; extern f32 D_80109110; extern f32 D_80109114; }

extern u8 *D_801EFD04;
extern u8 D_80109118[];
void func_801B87E8(s32 *);
extern u8 D_80109120[];
extern u8 D_8010912C[];
extern u8 D_80109138[];
extern u8 D_80109178[];
extern u8 D_80109184[];
extern u8 D_80109190[];
extern u8 D_8010919C[];
extern u8 D_801091A8[];
extern u8 D_801091B4[];
extern const f64 D_801091C0;
extern const f32 D_801091C8;
extern const f32 D_801091CC;
extern const f32 D_801091E8;
extern const f32 D_801091EC;
extern const f32 D_801091F0;
extern const f32 D_801091F4;
extern const f32 D_801091F8;
extern const f32 D_801091FC;
extern const f32 D_80109200;
extern const f32 D_80109204;
extern const f32 D_80109208;
extern const f32 D_8010920C;
extern const f32 D_80109210;
extern const f32 D_80109214;
extern const f32 D_80109218;
extern const f32 D_8010921C;
extern const f32 D_80109220;
extern const f32 D_80109224;
extern const f32 D_80109228;
extern const f32 D_8010922C;
extern const f32 D_80109230;
s32 func_80186420(s16 arg0, s32 *arg1, u8 *arg2);
static inline void split_externs_80186420(void) { extern u8 D_801090D0[]; }

s32 func_80187444(s16 arg0, s32 *arg1, u8 *arg2);
static inline void split_externs_80187444(void) { extern u8 D_80109100[]; extern u8 D_80109234[]; extern u8 D_80109278[]; extern u8 D_801092C0[]; }

void func_801BA644(TrailBuf *buf, TrailVec *a, TrailVec *b, u8 c, u8 d, u8 e, u8 f);
void func_801BAF8C(u8 *arg0);
s32 func_801877C0(s16 arg0, s32 *arg1, u8 *arg2);
static inline void split_externs_801877C0(void) { extern u8 D_801090B8[]; extern u8 D_801090D0[]; extern u8 D_80109308[]; extern u8 D_80109350[]; extern u8 D_80109398[]; extern u8 D_801093CC[]; extern u8 D_80109400[]; extern const f32 D_80109408; extern const f32 D_8010940C; extern const f64 D_80109410; extern const f64 D_80109418; }

s32 func_801884A4(s16 arg0, s32 *arg1, u8 *arg2);
static inline void split_externs_801884A4(void) { extern u8 D_801090D0[]; extern u8 D_80109420[]; extern u8 D_80109454[]; extern f32 D_801EFCF4; }

s32 func_80188A5C(s16 arg0, s32 *arg1, u8 *arg2);

extern u8 *D_802991AC;
extern u8 D_802991A8[];
extern u16 D_80299200;

extern u8 *D_802988CC;
extern u8 D_802988C8[];
extern u16 D_80298920;


void func_80188F90(void);

void func_80188FB4(void);

void func_80188FD8(u8 *arg0);

inline void func_80189040(UnkList *arg0);

void func_80189098(u8 *arg0);

void func_801890EC(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, f32 arg7, f32 arg8, f32 arg9);

void func_801891A4(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);

extern u8 D_802988B8;
extern u8 D_802988B9;
extern u8 D_802988BA;

void func_801891E4(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

extern const f32 D_80109514, D_80109518;
void func_80189224(u8 *arg0);
static inline void split_externs_80189224(void) { extern s32 D_801EFD50; extern u8 D_80297C38[], D_802991A0[]; extern s32 D_80297C30; }

void func_8018978C(void);

void func_80189908(u8 *arg0);

void func_80189A58(f32 *arg0);

void func_80189B50(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4);

void func_80189BE8(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);

extern u8 D_802989E8[];
extern u8 D_802989E9[];
extern u8 D_802989EA[];
extern u8 D_802989EB[];
extern u8 D_802989EE[];
extern u8 D_802989F0[];
extern u8 D_802989F4[];
extern u8 D_802991BC[];
void func_80154300(s32);
void func_8018A050(Vec3F *, Vec3F *, u8, u8, u8, s16, s16, f32, f32);

void func_80189C9C(void);
static inline void split_externs_80189C9C(void) { extern u8 D_802989D0[]; }

void func_80189E78(void *arg0, Vec3F *arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 arg8, f32 arg9);
static inline void split_externs_80189E78(void) { extern void func_80149398(void *, void *, f32, void *, f32); extern f32 D_80109540; extern s16 D_801EC7DA; extern u8 D_802989D0[]; extern u8 D_802989E8[]; extern u8 D_802989E9[]; extern u8 D_802989EA[]; extern u8 D_802989EB[]; extern u8 D_802989EC[]; extern u8 D_802989EE[]; extern u8 D_802989F0[]; extern u8 D_802989F4[]; }

extern Vec3F D_80298928[];
extern Vec3F D_8029892C[];
extern Vec3F D_80298930[];
extern f32 D_80109544;
extern f64 D_80109548;
extern f32 D_80109550;
extern f32 D_80109554;
extern f64 D_80109558;
extern f64 D_80109560;
extern f64 D_80109568;
extern f64 D_80109570;
extern f64 D_80109578;
extern f32 D_80109580;
extern const f32 D_80109544;
extern const f64 D_80109548;
extern const f32 D_80109550;
extern const f32 D_80109554;
extern const f64 D_80109558;
extern const f64 D_80109560;
extern const f64 D_80109568;
extern const f64 D_80109570;
extern const f64 D_80109578;
extern const f32 D_80109580;
void func_8018A050(Vec3F *start, Vec3F *end, u8 r, u8 g, u8 b, s16 count, s16 flags, f32 jitter, f32 width);
#define U32F(a) ({ u32 _r; if (!(a >= (*(const f32 *)&D_80109550))) { _r = (s32)a; } else { _r = (s32)(a - (*(const f32 *)&D_80109550)); _r |= 0x80000000; } _r; })

extern s32 D_80299244;
extern s32 D_80299248;
extern f32 D_801095DC;
extern f32 D_801095E0;
extern f64 D_801095E8;
extern f32 D_801095EC;
extern f32 D_801095F0;
extern f32 D_801095F4;
extern f64 D_801095F8;
extern s32 D_8029924C;



extern Unk80299210Node D_80299210;


void func_8018A9D0(void);

void func_8018A9F8(s32 *arg0);

typedef struct {
    Vec3F dir;
    s16 unkC;
    u8 padE[2];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    U32F32 unk1C;
} Struct8018AA60_48;

typedef struct {
    u8 pad0[0x2C];
    u8 *unk2C;
    u8 pad30[0x18];
    Struct8018AA60_48 *unk48;
    u8 pad4C[0x68];
    Vec3F pos;
} Struct8018AA60;

extern const u8 D_801095B0[];
extern const f32 D_801095BC;
extern const f32 D_801095C0;
extern const f32 D_801095C4;
extern const f64 D_801095C8;
extern const f64 D_801095D0;
extern const f32 D_801095D8;
f32 sqrtf(f32);
void func_8018AA60(Struct8018AA60 *arg0);

void func_8018AE5C(void);

Unk80299210Node *func_8018B2D4(Unk80299210Node *arg0, s32 arg1);


extern s32 D_80299290;
extern s32 D_80299390;

void func_8018B310(s32 *arg0);

inline void func_8018B358(ObjectNode *arg0);

void func_8018B3B8(void);

void func_8018B3D8(void);

void func_8018B3FC(u8 *arg0);

void func_8018B44C(s32 *arg0);

void func_8018B47C(s32 *arg0);

void func_8018B48C(s32 *arg0, s32 *arg1);

void func_8018B4C4(s16 arg0, f32 arg1);

extern s16 D_801EFDB4;
extern s16 D_801EFDB6;
extern const f32 D_80109628, D_80109634, D_80109648, D_8010964C;
extern const f32 D_80109658, D_8010965C, D_80109670, D_80109674;
extern const f64 D_80109638, D_80109640, D_80109650, D_80109660, D_80109668;
extern f32 D_801EFDA4[];
extern s16 D_801EFDB8, D_801EFD60, D_801EFD62;
extern f32 D_8028932C[];
extern s32 D_80284DC0;
void func_8018E260(s32);
void func_8018DF4C(u8 *);
void func_8018DFAC(s32, s16, s16);


extern s32 D_80284DC0, D_80284DF0, D_80290194;
void func_8018B650(void);

extern s32 D_802901E4;

extern const f64 D_80109678;
extern const f64 D_80109680;
extern const f32 D_80109688;
extern const f32 D_8010968C;
extern f64 D_80109690;
extern f64 D_80109698;
extern f32 D_801096A0;
extern s16 D_801EFD60;
void func_8018E260(s32);
extern int D_802901E4;
void func_8018BFA4(void);

void func_8018C55C(void);

void func_8018C584(u8 *arg0, s32 arg1, f32 arg2);

void func_8018C700(s32 arg0, s32 arg1);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))

extern s32 *D_8029F438;
extern s32 *D_8029F96C;
extern s32 *D_8029F45C;
extern s32 *D_8029FA5C;
extern s32 *D_8029F968;
extern s32 *D_8029F5D0;
extern s32 D_8029F56C;
extern s32 D_8028FBB8[];
extern s32 *D_802902D0;
extern s32 *D_802902D4;
extern s32 D_802900EC;

void func_8018D39C(s32 arg0);
static inline void split_externs_8018D39C(void) { extern s32 *D_8028FBB0; extern s32 *D_8028FBB4; extern s32 D_802900BC; extern f32 D_80290358; extern f32 D_80290364; extern s32 D_8028FF7C; extern s32 D_80290060; extern f32 D_8029035C; extern u8 D_801FAAF0[]; extern u8 D_801FAAF1[]; extern u8 *D_8029F458; extern s32 D_802901B4; extern f32 D_8029F9DC; extern f32 D_8029F9B8; extern f32 D_8029F9C4; extern u8 D_8029F5FE[]; extern f32 D_80109780; extern f32 D_80109784; extern f32 D_80109788; extern f32 D_8010978C; extern f32 D_80109790; extern f32 D_80109794; extern f64 D_80109798; extern f32 D_801097A0; extern f32 D_801097A4; extern f64 D_801097A8; extern f32 D_801097B0; }

extern s32 D_801097B4;
extern f32 D_801097BC;
extern f32 D_801097C0;
extern f32 D_801097C4;

void func_8018DD18(void);

u8 *func_8018DD54(u8 arg0, Vec3F *arg1, s16 arg2, s16 arg3);

void func_8018DF4C(u8 *arg0);

extern u8 D_801E7501[];

void func_8018DFAC(s32 arg0, s16 arg1, s16 arg2);
static inline void split_externs_8018DFAC(void) { extern s32 D_80290194; extern s32 D_80284DF0; extern s32 D_80284DC0; extern u8 D_801E7501[]; extern s32 D_80290304; extern f32 D_80290360; extern f32 D_80290330; extern f32 D_80290334; extern f32 D_80290338; extern f64 D_801097C8; }

void func_8018E260(s32 arg0);

extern const f64 D_801097F4;
extern f64 D_801097FC;
extern f64 D_80109804;
extern s32 D_801EFDC0;


void func_8018E380(void);
static inline void split_externs_8018E380(void) { extern f32 D_80290330, D_80290338; void func_801B0DDC(void); }

void func_8018E5F0(void);

void func_8018E610(s32 *arg0);


void func_8018E660(s32 *arg0, s32 *arg1);

void func_8018E698(ObjectNode *arg0, ObjectNode *arg1);

void func_8018E6D0(s32 *arg0);

void func_8018E6E8(s32 *arg0);

extern s32 D_80299500;
extern s32 D_80299694;

void func_8018E6F8(void);

extern s32 D_80109834;
void *func_8013FCDC(s32, s32, s32 *);
void func_8018E7A4(s32 *);

s32 *func_8018E738(void);

void func_8018E7A4(s32 *arg0);

void func_8018E7F4(void);

void func_8018E888(s32 *arg0);

void func_8018E914(s32 *arg0);

void func_8018E9AC(void *arg0);
static inline void split_externs_8018E9AC(void) { extern const f32 D_8010983C; extern const f32 D_80109840; extern f32 D_80109960; extern f32 D_80109964; extern f32 D_80109968; extern s16 D_801ED404; extern s32 D_801EEB74; extern u8 D_8028D7E0; extern f32 D_8028F950; extern f32 D_8028F9C8; extern f32 D_8028FB3C; extern s32 D_8028FB94; extern s32 D_8028FB14; extern s32 D_8028FB74; extern f32 D_8028FB18; extern f32 D_8028FB1C; extern f32 D_8028FB20; extern f32 D_8028F938; extern f32 D_8028F93C; extern f32 D_8028F940; extern s32 D_8028FB30; extern s16 D_8028FB34; extern s32 D_8028FB68; extern s32 D_8028FB78; extern s32 D_802994A0; extern f32 D_802994A4; extern f32 D_802994A8; extern s32 D_802994AC; extern s32 D_802997A4; void func_80149568(f32 *); void func_8014D61C(s32, s32, s32, s32, s32); u32 *func_801B97EC(u32 *arg0, s32 arg1); s32 *func_801B9824(s32 *arg0, s32 arg1); Unk802AA7A0Node *func_801B985C(Unk802AA7A0Node *arg0, s32 arg1); void func_801B9894(s16, s16, s16, s16, s32); }

s32 func_8018FE98(s32 *arg0);

s32 func_8018FF50(s32 *arg0);

s32 func_80191024(s32 arg0);

s32 func_801910AC(s32 arg0);


extern u8 D_802996E2;

typedef struct UnkTreeItem {
    /* 0x00 */ s32 unk0[6];
} UnkTreeItem; /* size 0x18 */

typedef struct UnkTreeNode {
    /* 0x00 */ u8 unk0[0x28];
    /* 0x28 */ s32 itemCount;
    /* 0x2C */ UnkTreeItem *items[2];
    /* 0x34 */ struct UnkTreeNode *left;
    /* 0x38 */ struct UnkTreeNode *right;
    /* 0x3C */ s32 unk3C;
} UnkTreeNode; /* size 0x40 */

extern s32 D_80109D04;
extern s32 D_80109D0C;
extern s32 D_80109D14;
extern s32 D_80109D20;

typedef struct UnkBlk1C {
    s32 w[7];
} UnkBlk1C;

UnkTreeNode *func_80191120(UnkTreeNode *src);

void func_80191260(void);


void func_8019149C(s32 *arg0);

void func_80191548(s32 *arg0, s32 arg1);
static inline void split_externs_80191548(void) { extern u8 D_802996A8[]; }

void func_80191640(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, f32 arg5);

void func_80191794(u8 *p, f32 x, f32 y, f32 z, s32 arg4, f32 arg5, s32 idx);

void func_801919F4(u8 *arg0, s32 arg1);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))

s32 func_80192F84(u8 *arg0);
static inline void split_externs_80192F84(void) { extern f32 D_8010A0F4; extern f64 D_8010A0F8; extern f64 D_8010A100; extern f64 D_8010A108; extern void func_8014932C(void *, void *); }

void func_8019321C(u8 *arg0);
static inline void split_externs_8019321C(void) { extern u8 D_8010A110[]; }

extern f64 D_8010A190;

s32 func_80193298(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
static inline void split_externs_80193298(void) { extern f64 D_8010A138; extern f64 D_8010A140; extern f32 D_8010A148; extern f32 D_8010A14C; extern f64 D_8010A150; extern f64 D_8010A158; extern f64 D_8010A160; extern f64 D_8010A168; extern f64 D_8010A170; }

s32 func_801936CC(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
static inline void split_externs_801936CC(void) { extern f64 D_8010A178; extern f64 D_8010A180; extern f64 D_8010A188; }

void func_80193988(u8 *arg0);

s32 func_80193B14(ObjectNode *arg0, Vec3F *arg1);
static inline void split_externs_80193B14(void) { extern f32 D_8010A198; }

void func_80193C2C(u8 *arg0);

void func_80193D60(u8 *arg0);
static inline void split_externs_80193D60(void) { extern f32 D_8010A1A4; }

s32 func_80193FC8(ObjectNode *arg0, s32 flags);
static inline void split_externs_80193FC8(void) { extern u8 D_8010A1A8[]; extern f32 D_8010A1D4; extern f64 D_8010A1D8; }

s32 func_8019418C(u8 *arg0);
static inline void split_externs_8019418C(void) { extern s16 D_8028FBF6; extern u8 D_8010A1E0[]; }

s32 func_80194354(u8 *arg0);
static inline void split_externs_80194354(void) { extern u8 D_8010A20C[]; extern f32 D_8010A238; s32 func_80193298(u8 *, f32 *, f32, s32); s32 func_801936CC(u8 *, f32 *, f32, s32); }

void func_80194548(u8 *arg0);
static inline void split_externs_80194548(void) { extern u8 D_8010A23C[]; extern f32 D_8010A264; s32 func_80193298(u8 *, f32 *, f32, s32); s32 func_801936CC(u8 *, f32 *, f32, s32); }

void func_80194754(u8 *arg0);

extern f32 D_8010A27C;
extern f32 D_8010A280;
extern f32 D_8010A284;
extern f32 D_8010A288;
extern f64 D_8010A28C;
extern f32 D_8010A294;
extern f32 D_8010A298;
extern f64 D_8010A29C;
extern f32 D_8010A2A4;
extern f64 D_8010A2A8;
extern f32 D_8010A2B0;
extern f32 D_8010A2B4;
extern f32 D_8010A2B8;

s32 func_801948C8(u8 *arg0);

extern u8 *D_8028FAC8;
extern u8 *D_8028FAD0;
extern f64 D_8010A2BC;
extern s16 D_8028FBEE;
extern s16 D_802900D8;
extern s16 D_802900DA;
extern s16 D_8029F47C;
extern Vec3i_B1344 D_8029F578;
extern Vec3i_B1344 D_802900CC;

void func_80194CC8(u8 *arg0);

void func_80194D30(u8 *arg0, Vec3i_B1344 *arg1, s32 arg2, u32 arg3);
static inline void split_externs_80194D30(void) { extern s32 D_80290304; }

void func_80194FE8(void);

extern const u8 D_8010A2C0[];
extern const f32 D_8010A2CC;
extern const f32 D_8010A2D0;
extern const f32 D_8010A2D4;
extern const f32 D_8010A2D8;

extern u8 D_802997A0[];
extern s32 D_80299938;
extern s16 D_8029999E;
extern u8 *D_802997BC;
extern f32 D_8029F9EC;

void func_801AE0CC(s32, s16);
void func_80196610(u8 *);
void func_801966D8(u8 *);
void func_80198C20(u8 *);
void func_80195794(u8 *);
void func_801971A8(f32 *);

void func_80195224(s32 arg0);
static inline void split_externs_80195224(void) { extern u8 D_80299710[]; extern u8 D_80299718[]; extern u8 D_8029971C[]; extern u8 D_80299720[]; extern f32 D_80290310; extern u8 *D_80290304; }

void func_80195794(u8 *arg0);
static inline void split_externs_80195794(void) { extern u8 D_802996A8[]; extern u8 D_8010A2E0[]; extern u8 D_8010A308[]; extern f32 D_8010A2EC; extern f64 D_8010A2F0; extern f64 D_8010A2F8; extern f32 D_8010A300; extern f32 D_801EEB58; f32 func_8019655C(ObjectNode *); }

void func_80195CD4(s32 arg0, s32 arg1);

void func_80195D50();
static inline void split_externs_80195D50(void) { extern u8 D_801EFDEC[]; extern u8 *D_801EFDD0; extern u8 *D_802997BC; extern u8 D_8010A314[]; extern u8 D_8010A320[]; extern const f32 D_8010A328; extern const f32 D_8010A32C; extern const f32 D_8010A330; extern const f32 D_8010A334; extern const f64 D_8010A3C0; extern const f32 D_8010A3CC; extern f32 D_801F1A6C; void func_801B1344(s16); u8 *func_801AA5BC(s16); void func_8010F94C(void); void func_801A8E54(u8 *); }

void func_801963AC(void);

void func_801964B0(void);

f32 func_8019655C(ObjectNode *arg0);

void func_80196610(u8 *arg0);

extern f32 D_8010A430;
extern f32 D_8010A438;
extern f32 D_8010A440;
extern f32 D_8010A44C;
extern f64 D_8010A450;
extern f64 D_8010A458;
extern f64 D_8010A460;
extern u8 D_801EFDD4;
extern u8 D_801EFDD5;
extern u8 D_801EFDD6;
extern u8 D_801EFDD7;
extern u8 D_801EFDD8;
extern u8 D_801EFDD9;
extern f32 D_801EFDDC;
extern f32 D_801EFDE0;
extern const f32 D_8010A430;
extern const f32 D_8010A438;
extern const f32 D_8010A440;
extern const f32 D_8010A44C;
extern const f64 D_8010A450;
extern const f64 D_8010A458;
extern const f64 D_8010A460;
void func_801966D8(u8 *arg0);

void func_801971A8(f32 *arg0);


void func_80197360(s32 *arg0, u8 **arg1);

void func_801975A8(s32 arg0);

void func_8019764C(s32 arg0);

typedef struct {
    s32 words[18];
} Unk48Block; /* size = 0x48 */

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x44];
    s32 unk48;
    u8 unk4C[0x120];
    u8 **unk16C;
    u8 unk170;
    u8 unk171;
    u8 unk172;
    u8 unk173;
    u8 pad174[4];
    s32 unk178;
    u8 pad17C[0x1A];
    s16 unk196;
} ScriptState; /* at ObjectNode + 0xE4 */

void func_801976F0(s32 arg0);

void func_80197794(u8 *arg0, s32 arg1, s32 arg2);

void func_8019787C(u8 *arg0);
static inline void split_externs_8019787C(void) { extern f32 D_80290310; extern f32 D_80290314; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern s32 D_8029F100; extern u8 D_8010A5A0[]; extern f32 D_8010A5AC; extern u8 *D_80290304; extern f32 D_8029035C; }

void func_801982F0(u8 *a0);

extern u8 *D_80290304;
extern u8 D_8010A5B0[];
extern u8 D_8010A620[];

s32 func_80198310(u8 *arg0, u8 *arg1);

static inline void func_80198A58_set2(u8 *arg0, s16 arg1, s32 arg2) {
    u8 *s = arg0 + 0xE4;

    if (*(s16 *)(arg0 + 0xE4) == 13) {
        *(s32 *)(arg0 + 0x84) = 0;
    }
    if (arg2 == 0) {
        while (func_80198310(arg0, (*(u8 ***)(s + 0x16C))[(s16)arg1]) == 0) {
            arg1++;
        }
    }
    s[0x170] = arg1;
    *(Unk48Block *)s = *(*(Unk48Block ***)(s + 0x16C))[(s16)arg1];
    *(s32 *)(s + 0x178) = 0;
    *(s16 *)(s + 0x196) = *(s16 *)(s + 2);
}

s32 func_80198A58(u8 *arg0);

void func_80198C20(u8 *arg0);
static inline void split_externs_80198C20(void) { extern s32 D_8029F100; }

extern f32 D_8010A8D8;
extern f32 D_8010A8DC;
void func_8014D61C(s32, s32, s32, s32, s32);
void func_801BA0E0(u8 *, f32, f32, u8 *, f32, f32);
void func_801B9974(u8 *, s32, f32, f32, s32, s32);

s32 func_801A2944(f32, u8 *);
void func_80198F60(u8 *arg0);

void func_80199008(u8 *arg0);

extern f32 D_8010A740;
extern f64 D_8010A744;
extern f32 D_8010A7CC;
extern f64 D_8010A7D0;
extern f32 D_8010A7D8;
extern f64 D_8010A7DC;
extern f32 D_8010A704;
extern f32 D_8010A708;
extern f32 D_8010A70C;
extern f32 D_8010A710;
extern f32 D_8010A714;
extern f32 D_8010A718;
extern f64 D_8010A720;
extern f32 D_8010A724;
extern f32 D_8010A730;
extern f32 D_8010A734;
extern f64 D_8010A738;
s32 func_801A2944(f32, u8 *);
extern u8 *D_80290304;
void func_801B10B8(u8 *, f32 *, f32, f32);
extern f64 D_8010A6FC;
s32 func_80133E24(u8 *, f32);

void func_801990D4(u8 *arg0);

void func_801992E0(u8 *arg0);

void func_80199500(u8 *arg0);
static inline void split_externs_80199500(void) { extern f32 D_8010A728; extern f32 D_8010A72C; s32 func_801B70F8(u8 *, s32, f32, f32); void func_801A02A0(f32 *, s32, f32, f32); }

void func_80199758(u8 *arg0);

void func_8019993C(u8 *arg0);

extern f32 D_8010A79C;
extern f32 D_8010A7A0;
extern f32 D_8010A7A4;
extern f32 D_8010A7A8;
extern f32 D_8010A7AC;
extern f32 D_8010A7B0;
extern f32 D_802978F4;
extern f32 D_802978F8;
extern f32 D_802978FC;

void func_80199A9C(u8 *arg0);
static inline void split_externs_80199A9C(void) { extern f32 D_8010A74C; extern f64 D_8010A750; extern f64 D_8010A758; extern f64 D_8010A760; extern f64 D_8010A768; extern f64 D_8010A770; extern f32 D_8010A778; extern f32 D_8010A77C; extern f32 D_8010A780; extern f32 D_8010A784; extern f64 D_8010A788; extern f32 D_8010A790; extern f32 D_8029F9D0; extern f32 D_8029F9D8; extern f32 D_8029F9B0; extern f32 D_8029F9B4; void func_801B2B58(s32, f32, f32); }

void func_8019A018(u8 *arg0);

extern f32 D_8010A7BC;
extern f32 D_8010A7C0;
extern f32 D_8010A7C8;
extern f32 D_801ED680;

void func_8019A2C8(u8 *arg0);

void func_8019A47C(u8 *arg0);

void func_8019A668(u8 *arg0);
static inline void split_externs_8019A668(void) { extern f32 D_8010A7E4, D_8010A7E8, D_8010A7EC, D_8010A7F0, D_8010A7F4, D_8010A7F8; extern f32 D_8010A7FC, D_8010A800, D_8010A804, D_8010A808, D_8010A80C, D_8010A810; extern f32 D_8010A814, D_8010A818, D_8010A81C, D_8010A820, D_8010A824, D_8010A828; extern s32 D_802AA708; s32 func_801A2944(f32, u8 *); }


void func_8019A990(u8 *o);
static inline void split_externs_8019A990(void) { extern f32 D_8010A854, D_8010A858, D_8010A85C, D_8010A860, D_8010A864, D_8010A868; extern f32 D_8010A86C, D_8010A870, D_8010A874, D_8010A878, D_8010A87C, D_8010A880; extern f32 D_8010A884, D_8010A890, D_8010A894, D_8010A898, D_8010A89C; extern f64 D_8010A888; extern f32 D_801EF444; extern s16 D_8028FBEE, D_802900D8, D_802900DA; extern u8 *D_8028FAC8; extern u8 *D_8028FAD0; }

void func_8019B02C(u8 *arg0, f32 arg1);
static inline void split_externs_8019B02C(void) { extern f32 D_8010A8A0; }

void func_8019B078(u8 *o);
static inline void split_externs_8019B078(void) { extern f32 D_8010A8A0; extern f32 D_8010A8A8; extern f32 D_80290310, D_80290314, D_8029F9B0, D_8029F9B4; }

void func_8019B3DC(u8 *p);

void func_8019B658(u8 *a);
static inline void split_externs_8019B658(void) { extern const f32 D_8010A8CC; extern const f32 D_8010A8D0; extern const f32 D_8010A8D4; }

void func_8019B7AC(u8 *arg0);

extern f32 D_8010A8E0, D_8010A8E4, D_8010A8E8, D_8010A8EC;
void func_8019B968(s32 p);
static inline void split_externs_8019B968(void) { extern f64 D_8010A8F0; extern f32 D_8010A8F8, D_8010A90C, D_8010A910, D_8010A914, D_8010A918; extern f32 D_8010A900; extern f32 D_8029F9B0, D_8029F9B4, D_8029F9D8; extern s32 D_802901CC; }

void func_8019BF64(Func8019BF64Obj *arg0);

extern f32 D_8010A92C;
extern f32 D_8010A930;
extern f32 D_8010A934;
extern f32 D_8010A938;
extern f32 D_8010A944;
extern f32 D_8010A948;
void func_8019C020(u8 *arg0);

extern f32 D_8010A94C;
extern f64 D_8010A990;
extern s16 D_801F01B8;
extern f32 D_801F01C0;
extern f32 D_8010A950;
extern f32 D_8010A954;
extern f32 D_8010A958;
extern s16 D_801F01BA;
extern s16 D_801F01BC;
extern s16 D_801F01BE;
extern f32 D_8010A970;
extern f32 D_8010A974;
extern f32 D_8010A978;
extern f32 D_8010A97C;
extern f32 D_8010A980;
extern f32 D_8010A984;
extern f32 D_8010A988;
extern f32 D_8010A98C;
extern f32 D_8010A998;
extern f32 D_8010A99C;
extern f32 D_8010A9A0;
extern f32 D_8010A9A4;
extern f32 D_8010A9A8;
extern f32 D_8010A9AC;
extern f32 D_8010A9B0;
extern const f32 D_8010A94C;
extern const f32 D_8010A950;
extern const f32 D_8010A954;
extern const f32 D_8010A958;
extern const f32 D_8010A960;
extern const f32 D_8010A964;
extern const f32 D_8010A968;
extern const f32 D_8010A96C;
extern const f32 D_8010A970;
extern const f32 D_8010A974;
extern const f32 D_8010A978;
extern const f32 D_8010A97C;
extern const f32 D_8010A980;
extern const f32 D_8010A984;
extern const f32 D_8010A988;
extern const f32 D_8010A98C;
extern const f64 D_8010A990;
extern const f32 D_8010A998;
extern const f32 D_8010A99C;
extern const f32 D_8010A9A0;
extern const f32 D_8010A9A4;
extern const f32 D_8010A9A8;
extern const f32 D_8010A9AC;
extern const f32 D_8010A9B0;
extern const f32 D_8010A95C;
extern u8 D_8029F5CA;
void func_801AEC14(void);
void func_801AEB0C(s32);

void func_8019C52C(u8 *arg0);

void func_8019D294(u8 *arg0);
static inline void split_externs_8019D294(void) { extern f32 D_8010A9B4, D_8010A9B8, D_8010A9BC, D_8010A9C0, D_8010A9C4, D_8010A9C8; extern f32 D_8010A9CC, D_8010A9D0, D_8010A9D4, D_8010A9D8, D_8010A9DC, D_8010A9E0; extern f32 D_8010A9E4, D_8010A9E8; extern s32 D_802AA708; s32 func_801A2944(f32, u8 *); }

extern f32 D_8010A9E8;
extern f32 D_8010A9F0;
extern f32 D_8010A9FC;
extern f32 D_8010AA00;
extern f32 D_8010AA0C;
extern f32 D_8010AA10;
extern f32 D_8010AA14;
extern f32 D_8010AA18;
extern f32 D_8029F474;
extern f32 D_8029F478;
extern s32 D_8029F574;
void func_801B1344(s16);
void func_8019D58C(u8 *arg0);
static inline void split_externs_8019D58C(void) { extern f32 D_8029F9D8; }

void func_8019DB7C(u8 *arg0);
static inline void split_externs_8019DB7C(void) { s32 func_801A2944(f32, u8 *); }

void func_8019DCE4(u8 *arg0);
static inline void split_externs_8019DCE4(void) { extern f32 D_8010AA2C; void func_80160228(); }

void func_8019DEE8(u8 *arg0);
static inline void split_externs_8019DEE8(void) { extern f32 D_8010AA30; extern f32 D_8010AA34; extern f32 D_8010AA38; extern f32 D_8010AA3C; extern f32 D_8010AA40; extern f32 D_8010AA44; extern f32 D_8010AA48; extern f32 D_8010AA4C; extern f32 D_8010AA50; extern f32 D_8010AA54; void func_801B7984(u8 *, f32); void func_801A02A0(f32 *, s32, f32, f32); }

void func_8019E248(u8 *arg0);
static inline void split_externs_8019E248(void) { extern f64 D_8010AA58; extern f64 D_8010AA60; extern f64 D_8010AA68; extern f32 D_8010AA70; }

void func_8019E538(u8 *arg0);
static inline void split_externs_8019E538(void) { s32 func_801A2944(f32, u8 *); void func_80160B6C(u8 *, void *, f32, f32); }

void func_8019E7E8(u8 *arg0);
static inline void split_externs_8019E7E8(void) { extern f32 D_8010AA94; extern f32 D_8010AA98; extern f32 D_8010AA9C; extern f32 D_8010AAA0; extern f32 D_8010AAA4; extern f32 D_8010AAA8; extern f32 D_8010AAAC; extern f64 D_8010AAB0; extern f32 D_8010AAB8; extern f32 D_8010AABC; extern f64 D_8010AAC0; extern f64 D_8010AAC8; extern f32 D_8010AAD0; extern f32 D_8010AAD4; extern f32 D_8010AAD8; extern const f32 D_8010AADC; extern const f32 D_8010AAE0; extern f32 D_8010AAE4; extern f32 D_8010AAE8; extern f32 D_8010AAF4; extern f32 D_8010AAF8; extern f32 D_8010AAFC; extern f32 D_801F0DA0; extern s32 D_80299A10; extern u8 *D_80299ABC; extern s32 D_80299C54; extern s32 D_80299D10; extern s32 D_80299F54; extern s16 D_80299F30; extern s16 D_8028FBF6; s32 func_801A2944(f32, u8 *); void func_801490AC(Vec3F *, Vec3F *, f32); void func_801B614C(f32 *, f32 *, s32, f32, f32, s32 *); void func_801A02A0(f32 *, s32, f32, f32); void func_801B9974(u8 *, s32, f32, f32, s32, s32); void func_801B9894(s16, s16, s16, s16, s32); }

void func_8019F0B8(u8 *arg0);
static inline void split_externs_8019F0B8(void) { extern const f32 D_8010AB00; extern const f32 D_8010AB04; extern const f32 D_8010AB08; extern const f32 D_8010AB0C; extern const f32 D_8010AB10; extern const f32 D_8010AB14; extern const f32 D_8010AB18; extern const f32 D_8010AB1C; extern const f32 D_8010AB20; extern const f32 D_8010AB24; extern const f32 D_8010AB28; extern const f32 D_8010AB2C; extern const f32 D_8010AB30; extern const f32 D_8010AB34; extern const f32 D_8010AB38; extern const f32 D_8010AB3C; extern const f32 D_8010AB40; extern const f32 D_8010AB44; extern const f32 D_8010AB48; extern const f32 D_8010AB4C; extern const f32 D_8010AB50; extern const f32 D_8010AB54; extern const f32 D_8010AB58; extern const f32 D_8010AB5C; extern const f32 D_8010AB60; extern const f32 D_8010AB64; extern const f64 D_8010AB68; extern const f32 D_8010AB70; extern const f32 D_8010AB78; extern const f32 D_8010AB80; extern const f32 D_8010AB8C; extern const f64 D_8010AB90; extern const f32 D_8010AB98; extern const f32 D_8010AB9C; extern const f32 D_8010ABA0; extern f32 D_80299764; extern f32 D_8029F9EC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern f32 D_80290330; extern f32 D_80290338; extern s32 D_80290134; extern s32 D_80299F54; extern s32 D_80299F40; extern s16 D_80299F30; extern u8 D_80299CE8[]; extern u8 *D_802997C4[]; s32 func_801A2944(f32, u8 *); void func_801490AC(Vec3F *, Vec3F *, f32); }

void func_8019F9F4(u8 *arg0);
static inline void split_externs_8019F9F4(void) { extern f32 D_8010ABA4; extern f32 D_8010ABA8; extern f32 D_8010ABAC; extern f32 D_8010ABB0; extern f32 D_8010ABB4; extern f32 D_8010ABB8; extern f32 D_8010ABBC; extern f64 D_8010ABC0; extern f32 D_8010ABC8[]; extern f32 D_8010ABD0[]; extern f32 D_8010ABDC; extern f32 D_8010ABE0[]; extern f32 D_8010ABEC; extern f32 D_8010ABF0[]; extern f32 D_8010ABFC; extern f32 D_80299764; extern s32 D_801F19B8; extern s32 D_801F19BC; extern f32 D_80290310; extern u8 *D_802997C4[]; void func_801A02A0(f32 *, s32, f32, f32); }

void func_801A0064(u8 *arg0);
static inline void split_externs_801A0064(void) { extern f32 D_8010AC00[]; extern f32 D_8010AC0C; extern f32 D_8010AC10; extern f32 D_8010AC14; extern f32 D_8010AC18; extern f32 D_8010AC1C; extern s32 D_80290134; extern s32 D_802901DC; extern f32 D_80290334; extern s16 D_8028FBF6; }

extern f32 D_80290334;
void func_801B7984(f32 *, f32);
extern f32 D_8010ACC8;
extern f32 D_8010ACCC;
extern f32 D_8010ACD0;
extern f32 D_8010ACD4;
extern f32 D_8010ACD8;
extern f32 D_8010ACE0;
extern f32 D_8010ACEC;
extern f32 D_8010ACF0;
extern f32 D_8010ACF4;
extern f32 D_8010AD00;
extern f32 D_8010AD04;
extern f32 D_8010AD08;
extern f32 D_8010AD0C;
extern f32 D_8010AD10;
extern f32 D_8010AD14;
extern f32 D_8010AD18;
extern f32 D_8010AD1C;
extern f32 D_8010AD20;
extern f32 D_8010AD24;
extern f32 D_8010AD28;
extern f32 D_8010AD2C;
extern f32 D_8010AD40;
extern f32 D_8010AD44;
extern f32 D_8010AD48;
extern f32 D_8010AD4C;
extern f32 D_8010AD50;
extern f32 D_8010AD54;
extern f32 D_8010AD58;
extern f32 D_8010AD5C;
extern f32 D_8010AD60;
extern f32 D_8010AD64;
extern f32 D_8010AD68;
extern f64 D_8010ACF8;
extern f64 D_8010AD30;
extern f64 D_8010AD38;
extern f32 D_801F01D0, D_801F01D4, D_801F01D8, D_801F01DC, D_801F01E0, D_801F01E4, D_801F01E8;
extern f32 D_8029F9D8, D_80290338;
void func_801A28AC(void);


void func_801A02A0(f32 *arg0, s32 arg1, f32 arg2, f32 arg3);
static inline void split_externs_801A02A0(void) { extern s32 D_8010AC20[]; extern s32 D_80297910; extern f64 D_8010AC30; extern f32 D_8010AC34; extern f32 D_8010AC38; }

void func_801A0444(u8 *arg0);
static inline void split_externs_801A0444(void) { extern s32 D_802004E0; extern s32 D_801F01CC; extern s32 D_801F01C8; extern f32 D_801F01C4; extern s32 D_8029F9A4; extern s32 D_802902D8; extern f32 D_8029F9AC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern s16 D_801E7460; extern s32 D_8029030C; extern s32 D_801E7588; extern s16 D_8028FBD8; extern f32 D_8028F95C; extern u8 D_801E7541; extern f32 D_80290360; extern s32 D_8029F9A0; extern f32 D_801EFFB0; extern u8 *D_8028F9B8; extern s32 D_8028F908; extern u8 *D_802903B0; extern s32 D_80290300; extern f32 D_80290330; extern f32 D_80290334; extern f32 D_80290338; extern s16 D_8028FBF6; extern f32 D_80290310; extern u8 *D_8029FA50; extern s32 D_8029F394; extern s32 D_8029F210; extern s32 D_801EEB70; extern const f32 D_8010AC3C; extern const f32 D_8010AC40; extern const f32 D_8010AC4C; extern const f64 D_8010AC50; extern const f64 D_8010AC58; extern const f64 D_8010AC60; extern const f64 D_8010AC68; extern const f32 D_8010AC70; extern const f32 D_8010AC74; extern const f32 D_8010AC78; extern const f32 D_8010AC7C; extern const f32 D_8010AC80; extern const f32 D_8010AC84; extern const f64 D_8010AC88; extern const f64 D_8010AC90; extern const f32 D_8010AC98; extern const f32 D_8010AC9C; extern const f32 D_8010ACA0; extern const f32 D_8010ACA4; extern const f32 D_8010ACA8; extern const f32 D_8010ACB4; extern const f32 D_8010ACB8; extern const f32 D_8010ACBC; extern const f32 D_8010ACC0; extern const f32 D_8010ACC4; void func_80149568(f32 *); void func_80148D0C(f32 *, f32 *, f32); void func_80173CE8(s32); void func_80167604(s32); s32 func_80178134(s16, f32 *, s16, s16); void func_801B9974(u8 *, s32, f32, f32, s32, s32); void func_80174058(s16); void func_801B0DDC(void); f32 func_80148DB0(u8 *, u8 *); void func_80165140(f32 *); s32 func_801936CC(u8 *, f32 *, f32, s32); s32 func_801A2944(f32, u8 *); void *func_801A9054(); void func_80133998(void *, s32, s32, s32, f32); f32 func_801496C8(f32); s32 func_80147000(s32); void *func_8017DBA0(s32); void func_801490AC(Vec3F *, Vec3F *, f32); }

void func_801A1558(u8 *arg0);

void func_801A21B8(u8 *arg0);
static inline void split_externs_801A21B8(void) { extern s32 D_80299954; extern s32 D_80299938; extern f32 D_801F01EC; extern f32 D_8010AD6C; extern f32 D_8010AD70; extern f32 D_8010AD74; extern f32 D_8010AD78; extern f32 D_8010AD7C; extern f32 D_8010AD80; extern f32 D_8010AD84; extern f32 D_8010AD88; extern f32 D_8010AD8C; }

void func_801A28AC(void);


void func_801A297C(ObjectNode *arg0);

extern f32 D_801F01F4;
extern s32 D_801F01F8;

static inline f32 func_801A29F0_sway(f32 f) {
    s32 n = -D_801F01F8;
    f32 x = D_802004E0;
    f32 r = func_80149724(f, x, n);
    s32 e = D_802004E0 - 0x82;
    s32 t = D_801F01F8 - e;

    if (t < 0xF) {
        t = 0xF;
    }
    return r * t * D_801F01F4;
}

void func_801A29F0(u8 *arg0);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define S(t,p,o) (((struct { t v; } *)((u8 *)(p)+(o)))->v)
#define CAM(t,o) S(t,&D_801FA840,o)
#define LEVEL ((&D_801E7530)[1])
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define SWAY() func_801A29F0_sway(f)

extern f32 D_8010AF00;
extern f32 D_8010AF04;
extern f32 D_8010AF08;
extern f32 D_8010AF0C;
extern f64 D_8010BEAC;
extern f32 D_8010BEB4;
extern f32 D_8010BEB8;
extern f32 D_8010BEBC;
extern f32 D_8010BEC0;
extern f32 D_8010BEC4;
extern f32 D_8010BEC8;
extern f64 D_8010BECC;
extern f64 D_8010BED4;
extern f64 D_8010BEDC;
extern s32 D_802AA708;
extern s16 D_802AA70C;
extern s16 D_802AA70E;
extern s32 D_802AA710;
extern f32 D_802AA714;
extern s32 D_802AA718;
u8 *func_801AA5BC(s16);
void func_801A96A8();
void func_801A8E54();

void func_801A40F4(u8 *arg0);

void func_801A41B4(Vec3F *arg0, Vec3F *arg1, s16 arg2, f32 arg3, f32 arg4);
static inline void split_externs_801A41B4(void) { extern f32 D_8010AF00; extern f32 D_8010AF04; extern f32 D_8010AF08; extern f32 D_8010AF0C; }

void func_801A446C(ObjectNode *arg0);

void func_801A44F8(void *arg0);
static inline void split_externs_801A44F8(void) { extern s32 D_8010AF10; extern const f32 D_8010AF1C; extern const f64 D_8010AF20; extern const f32 D_8010AF28; extern const f32 D_8010AF2C; extern const f32 D_8010AF30; extern const f32 D_8010AF34; extern const f32 D_8010AF38; extern const f32 D_8010AF3C; extern const f32 D_8010AF40; extern const f32 D_8010AF44; extern const f32 D_8010AF48; extern const f32 D_8010AF4C; extern const f32 D_8010AF50; extern const f32 D_8010AF54; extern const f64 D_8010AF58; extern const f64 D_8010AF60; extern const f32 D_8010AF68; extern const f32 D_8010AF6C; extern const f32 D_8010AF70; extern const f32 D_8010AF74; extern const f32 D_8010AF78; extern const f32 D_8010AF7C; extern const f32 D_8010AF80; extern const f32 D_8010AF84; extern const f64 D_8010AF88; extern const f32 D_8010AF90; extern const f32 D_8010AF94; extern const f64 D_8010AF98; extern const f64 D_8010AFA0; extern const f32 D_8010AFA8; extern const f32 D_8010AFB4; extern const f32 D_8010AFB8; extern const f32 D_8010AFBC; extern const f32 D_8010AFC0; extern const f32 D_8010AFC4; extern const f32 D_8010AFC8; extern const f32 D_8010AFCC; extern const f32 D_8010AFD0; extern const f32 D_8010AFDC; extern const f32 D_8010AFE0; extern const f32 D_8010AFE4; extern const f32 D_8010AFE8; extern const f32 D_8010AFEC; extern const f32 D_8010AFF0; extern const f32 D_8010B02C; extern const f32 D_8010B030; extern const f32 D_8010B034; extern const f32 D_8010B038; extern const f32 D_8010B03C; extern const f64 D_8010B040; extern const f32 D_8010B048; extern const f32 D_8010B04C; extern const f32 D_8010B050; extern u8 D_801F020C[]; extern s32 D_801F021C; extern s32 D_801F0220; extern f32 D_801F0224; extern s32 D_8028F780; extern u8 *D_802997C4[]; extern u8 D_8029F140[]; extern u8 D_8029F144; extern u8 D_8029F148; extern s32 D_8029F14C; extern s32 D_8029F150; extern s32 D_8029F154; void func_8010EEF8(char *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32); void func_80195D50(); }

void func_801A5EDC(u8 *arg0, s32 arg1);
static inline void split_externs_801A5EDC(void) { extern f32 D_801F01FC, D_801F0200, D_8010B054, D_8010B058, D_8010B05C, D_8010B060; }

void func_801A6170(u8 *arg0);
static inline void split_externs_801A6170(void) { extern s32 D_8029F158; extern s32 D_8029F160; extern char D_8010B064[]; extern s16 D_801F0228[]; extern const f32 D_8010B070, D_8010B074, D_8010B078; extern const f32 D_8010B0A0, D_8010B0A4, D_8010B0A8, D_8010B0AC, D_8010B0B0, D_8010B0B4, D_8010B0B8; extern const f32 D_8010B0BC, D_8010B0C0, D_8010B0C4, D_8010B0C8, D_8010B0CC, D_8010B0D0, D_8010B0D4, D_8010B0D8; extern u8 D_801FAAAB[]; extern u8 D_801FAAF1[]; extern u8 D_801FAB74[]; extern s16 D_801F21AE[]; extern s32 D_80284DF0; extern s32 D_802004E0; extern u8 D_80202218; extern u8 D_801F21DC[]; extern u8 D_801F21AC[]; extern u8 D_801FAAC7[]; extern s8 D_801E7531; extern s32 D_8029030C; extern s32 D_80290194; }

s32 func_801A67E4(void);


extern s32 D_8029F170;
extern s32 D_8029F174;
extern s32 D_8029F200;
extern ObjectNode *D_80290130;
void func_801A76CC(ObjectNode *arg0);
void func_801A6FC0(u8 *arg0);
void func_801A6FD0(u8 *arg0);

void func_801A6820(void);

s32 func_801A6844(void *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7);
static inline void split_externs_801A6844(void) { extern f32 D_8010B104; extern f32 D_8010B108; }

void func_801A6FC0(u8 *);
void func_801A69F8(u8 *arg0);
static inline void split_externs_801A69F8(void) { extern s32 D_8029F170; extern s32 D_8029F200; }

inline void func_801A6AEC(ObjectNode *arg0);

void func_801A6B5C(void);

void func_801A6C24(void);
static inline void split_externs_801A6C24(void) { extern f32 D_8010B10C; extern f32 D_8010B110; extern s32 D_80297910; extern u8 D_801ED403; void func_80154300(s32); }

void func_801A6FC0(u8 *arg0);

void func_801A6FD0(u8 *arg0);
static inline void split_externs_801A6FD0(void) { extern u16 D_801F0232; extern s32 D_801EC86C; void func_801499A0(s32, s32, s32); void func_80149C4C(f32 *, f32 *); void func_801484F0(f32 *, f32 *); void func_801C61A0(f32 *, s32, s32, s32); void func_801C5F20(f32 *, s32, f32, s32); void func_801C5580(f32 *, f32 *, f32 *); void func_801C5300(f32 *, s32); void func_8017D7B8(u8 *); }

static inline s32 func_801A7360_init(void *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    extern f32 D_8010B12C;
    extern f32 D_8010B130;
    u8 *o = (u8 *)arg0;
    f32 tmp[4];

    if (*(u8 **)(o + 0xC) != 0 && arg2 == 0) {
        return 0;
    }
    *(s16 *)(o + 0x88) = arg7;
    *(s32 *)(o + 0x8) = arg5;
    *(f32 *)(o + 0x38) = arg3;
    *(f32 *)(o + 0x3C) = arg3;
    *(f32 *)(o + 0x34) = D_8010B12C;
    {
        s32 a = ((s32 *)arg1)[0];
        s32 b = ((s32 *)arg1)[1];
        s32 c = ((s32 *)arg1)[2];
        ((s32 *)(o + 0x14))[0] = a;
        ((s32 *)(o + 0x14))[1] = b;
        ((s32 *)(o + 0x14))[2] = c;
    }
    if (arg2 != 0) {
        s32 a = ((s32 *)arg2)[0];
        s32 b = ((s32 *)arg2)[1];
        s32 c = ((s32 *)arg2)[2];
        ((s32 *)(o + 0x20))[0] = a;
        ((s32 *)(o + 0x20))[1] = b;
        ((s32 *)(o + 0x20))[2] = c;
    } else {
        *(s32 *)(o + 0x20) = 0;
        *(f32 *)(o + 0x24) = D_8010B130;
        *(s32 *)(o + 0x28) = 0;
    }
    *(u8 *)(o + 0x31) = arg6;
    *(s16 *)(o + 0x40) = (s32)arg4;
    *(s16 *)(o + 0x42) = 0;
    *(u8 *)(o + 0x8A) = 5;
    if (*(u8 *)(o + 0x31) & 4) {
        *(u8 *)(o + 0x30) = 0x50;
    } else {
        *(u8 *)(o + 0x30) = 0xFA;
    }
    if (*(u8 *)(o + 0x31) & 0x10) {
        *(u8 *)(o + 0x2F) = 0;
    } else {
        *(u8 *)(o + 0x2F) = *(u8 *)(o + 0x30);
    }
    *(u8 *)(o + 0x2C) = 0xFF;
    *(u8 *)(o + 0x2D) = 0xFF;
    *(u8 *)(o + 0x2E) = 0xFF;
    if (*(u8 **)(o + 0xC) != 0) {
        *(f32 *)(o + 0x14) -= *(f32 *)(*(u8 **)(o + 0xC) + 0xB4);
        *(f32 *)(o + 0x18) -= *(f32 *)(*(u8 **)(o + 0xC) + 0xB8);
        *(f32 *)(o + 0x1C) -= *(f32 *)(*(u8 **)(o + 0xC) + 0xBC);
        *(f32 **)(o + 0x10) = arg2;
        tmp[3] = *(f32 *)(*(u8 **)(o + 0xC) + 0x128);
        tmp[0] = -*(f32 *)(*(u8 **)(o + 0xC) + 0x11C);
        tmp[1] = -*(f32 *)(*(u8 **)(o + 0xC) + 0x120);
        tmp[2] = -*(f32 *)(*(u8 **)(o + 0xC) + 0x124);
        func_801499A0((s32)(o + 0x14), (s32)(o + 0x14), (s32)tmp);
    }
    return 1;
}

static inline void func_801A7360_set(u8 *o, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, void *parent) {
    extern f32 D_8010B12C;
    extern f32 D_8010B130;
    f32 tmp[4];
    f32 k;

    if (*(u8 **)(o + 0xC) != 0 && arg2 == 0) {
        goto end;
    }
    k = D_8010B12C;
    *(s16 *)(o + 0x88) = arg7;
    *(s32 *)(o + 0x8) = arg5;
    *(f32 *)(o + 0x38) = arg3;
    *(f32 *)(o + 0x3C) = arg3;
    *(f32 *)(o + 0x34) = k;
    *(Vec3F *)(o + 0x14) = *(Vec3F *)arg1;
    if (arg2 != 0) {
        *(Vec3F *)(o + 0x20) = *(Vec3F *)arg2;
    } else {
        *(s32 *)(o + 0x20) = 0;
        *(f32 *)(o + 0x24) = D_8010B130;
        *(s32 *)(o + 0x28) = 0;
    }
    *(u8 *)(o + 0x31) = arg6;
    *(s16 *)(o + 0x40) = (s32)arg4;
    *(s16 *)(o + 0x42) = 0;
    *(u8 *)(o + 0x8A) = 5;
    if (*(u8 *)(o + 0x31) & 4) {
        *(u8 *)(o + 0x30) = 0x50;
    } else {
        *(u8 *)(o + 0x30) = 0xFA;
    }
    if (*(u8 *)(o + 0x31) & 0x10) {
        *(u8 *)(o + 0x2F) = 0;
    } else {
        *(u8 *)(o + 0x2F) = *(u8 *)(o + 0x30);
    }
    *(u8 *)(o + 0x2C) = 0xFF;
    *(u8 *)(o + 0x2D) = 0xFF;
    *(u8 *)(o + 0x2E) = 0xFF;
    if (*(u8 **)(o + 0xC) != 0) {
        *(f32 *)(o + 0x14) -= *(f32 *)(*(u8 **)(o + 0xC) + 0xB4);
        *(f32 *)(o + 0x18) -= *(f32 *)(*(u8 **)(o + 0xC) + 0xB8);
        *(f32 *)(o + 0x1C) -= *(f32 *)(*(u8 **)(o + 0xC) + 0xBC);
        *(f32 **)(o + 0x10) = arg2;
        tmp[3] = *(f32 *)(*(u8 **)(o + 0xC) + 0x128);
        tmp[0] = -*(f32 *)(*(u8 **)(o + 0xC) + 0x11C);
        tmp[1] = -*(f32 *)(*(u8 **)(o + 0xC) + 0x120);
        tmp[2] = -*(f32 *)(*(u8 **)(o + 0xC) + 0x124);
        func_801499A0((s32)(o + 0x14), (s32)(o + 0x14), (s32)tmp);
    }
end:
    *(void **)(o + 0xC) = parent;
    *(u8 *)(o + 0x30) = 0xC8;
    *(u8 *)(o + 0x2F) = 0xC8;
    *(u8 *)(o + 0x2E) = 0;
    *(u8 *)(o + 0x2D) = 0;
    *(u8 *)(o + 0x2C) = 0;
}

void func_801A7360(void);
static inline void split_externs_801A7360(void) { extern f64 D_8010B120; extern f32 D_8010B128; extern u8 D_8010B114[]; extern s32 D_80297908; extern s32 D_8029F170; extern s32 D_8029F200; }

void func_801A76CC(ObjectNode *arg0);
static inline void split_externs_801A76CC(void) { extern f32 D_8010B13C; extern f32 D_8010B140; extern f32 D_8010B14C; extern f64 D_8010B134; }

void func_801A77D8(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, u16 arg4, u8 *arg5, f32 *arg6);
static inline void split_externs_801A77D8(void) { extern s32 D_801EC86C; extern f32 D_8010B150; extern f32 D_8010B154; extern f32 D_8010B158; void func_801C61A0(f32 *, s32, s32, s32); void func_801C5F20(f32 *, f32, f32, f32); void func_801C5580(f32 *, f32 *, f32 *); void func_801C5300(f32 *, s32); }

void func_801A7AC4(u32 arg0);

extern const f32 D_8010B19C;
extern const f32 D_8010B1A0;
extern const f32 D_8010B1A4;

extern f32 D_8010B164;
extern f32 D_8010B168;
extern f32 D_8010B16C;
extern f32 D_8010B170;
extern f32 D_8010B174;
extern f32 D_8010B178;
extern f32 D_8010B17C;
extern f32 D_8010B180;
extern f32 D_8010B184;
extern f64 D_8010B188;
extern f32 D_8010B190;
void func_801A7B8C(void);
static inline void split_externs_801A7B8C(void) { extern s32 D_802900BC; extern f32 D_80290310; extern s32 D_802900F0; extern u8 *D_802903A4; extern s32 D_8029030C; extern s32 D_802004E0; extern s8 D_801E7531; extern s32 D_80297908; }

void func_801A8528(void);

void func_801A8794(void);

void func_801A87CC(s32 arg0);
static inline void split_externs_801A87CC(void) { extern const f64 D_8010B1A8; extern const f64 D_8010B1B8; extern const f64 D_8010B1C0; extern const f64 D_8010B1C8; extern const f64 D_8010B1D0; extern const f64 D_8010B1D8; extern const f32 D_8010B1B0; extern const f32 D_8010B1B4; extern const f32 D_8010B1E0; extern const f32 D_8010B1E4; extern const f32 D_8010B1E8; extern const f32 D_8010B1EC; extern const f32 D_8010B1F0; extern f32 D_80290330; extern f32 D_80290338; extern f32 D_8029034C; extern u8 D_8010B114[]; extern u8 D_801F0278; extern u8 D_801F0279; extern s16 D_8029014A; extern s32 D_8029793C; extern s32 D_8029F170; extern s32 D_8029F200; }

typedef struct ListNode801A8E54 {
    struct ListNode801A8E54 *next;
    struct ListNode801A8E54 *prev;
    u8 pad08[0x161 - 0x8];
    u8 type;
} ListNode801A8E54;
extern s32 D_801F19B8;
extern s32 D_801F19BC;


void func_801A8E30(void);

void func_801A8E54(ListNode801A8E54 *arg0);

void func_801A8EF8(ListNode801A8E54 *arg0);
static inline void split_externs_801A8EF8(void) { extern s32 D_8029F394; void func_8014ACB4(); void func_80178704(s32 *); void func_801625F0(s32, s32); void func_80141720(s32 *); }

static inline void split_externs_801A9054(void) { extern u8 D_801F0482; extern s32 D_802901E4; extern s32 D_802901E8; extern s16 D_8029012E; extern u8 D_801F19C1[][8]; extern u8 D_801F19C2[][8]; extern s32 D_801F19B8, D_801F19BC; extern const f32 D_8010B224; extern const f64 D_8010B228; extern const f32 D_8010B230; extern const f32 D_8010B234; u8 *func_801AA5BC(s16); void func_801ADAF8(); void func_801AE348(u8 *); }

u8 *func_801AA5BC(s16);
extern u8 *D_802997BC;
extern s16 D_801F0344[][0x60];
extern s32 D_801F0340[];
extern s32 D_801F0348[];
extern u8 D_801F034C[], D_801F034D[], D_801F034E[];
extern f32 D_801EFE48, D_801ED90C, D_801F1760, D_801F1A4C;
extern const f32 D_8010B284;
extern const f32 D_8010B288;
extern const f32 D_8010B28C;
extern const f32 D_8010B290;
extern const f32 D_8010B29C;
extern const f32 D_8010B2A0;
extern const f32 D_8010B2A4;
extern const f32 D_8010B2A8;
extern const f32 D_8010B2B0;
extern const f32 D_8010B2BC;
extern const f32 D_8010B2C0;
extern const f32 D_8010B2C4;
extern const f32 D_8010B2D8;
extern const f32 D_8010B2DC;
extern const f32 D_8010B2E0;
extern const f32 D_8010B2E4;
extern const f32 D_8010B2E8;
extern const f32 D_8010B2EC;
extern const f32 D_8010B2F0;
extern const f32 D_8010B2F4;
extern const f32 D_8010B2F8;
extern const f32 D_8010B2FC;
extern const f32 D_8010B300;
extern const f32 D_8010B30C;
extern const f32 D_8010B310;
extern const f32 D_8010B314;
extern const f32 D_8010B318;
extern const f32 D_8010B31C;
extern const f32 D_8010B320;
extern const f32 D_8010B324;
extern const f32 D_8010B328;
extern const f32 D_8010B334;
extern const f32 D_8010B338;
extern const f32 D_8010B33C;
extern const f32 D_8010B340;
extern const f32 D_8010B344;
extern const f32 D_8010B348;
extern const f32 D_8010B34C;
extern const f32 D_8010B350;
extern const f32 D_8010B354;
extern const f32 D_8010B358;
extern const f32 D_8010B35C;
extern const f32 D_8010B360;
extern const f64 D_8010B2C8, D_8010B2D0;
void func_801A96A8(u8 *o, u8 *arg1, s32 arg2);

u8 *func_801AA5BC(s16 arg0);
static inline void split_externs_801AA5BC(void) { extern u8 D_801F0330[]; void *func_8013FCDC(s32, s32, s32 *); }

void func_801AA74C(ObjectNode *arg0);

void func_801AA8A8(u8 *arg0);


void func_801AAA98(s32 arg0);

extern s16 D_8028FBF4;
extern u8 *D_8028FAC8;
extern u8 *D_8028FAD0;
extern s32 D_8029F460;

void func_801AAB10(void *arg0);

void func_801AAB3C(u8 *arg0);

void func_801AAB88(s32 arg0);

void func_801AABD0(void *arg0);

void func_801AAC00(void *arg0);

void func_801AAC30(s32 arg0);

void func_801AACD4(s32 arg0);

void func_801AAD50(s32 arg0);

void func_801AADDC(void);

extern f64 D_8010B390;
extern f32 D_8010B398;
extern f32 D_8010B39C;
extern f32 D_8010B3A0;
extern f32 D_8010B3A4;
extern f32 D_801F1A50;
extern f32 D_801F1A54;

void func_801AADFC(u8 *arg0);

s32 func_801AAFC8(u8 *arg0);

s32 func_801AB0A4(void);

s32 func_801AB0AC(s32 arg0);

s32 func_801AB140(u8 *arg0);
static inline void split_externs_801AB140(void) { extern f32 D_8010B3AC; extern f32 D_8010B3B0; }

typedef struct ListNode801AB2F0 {
    struct ListNode801AB2F0 *next;
    u8 pad04[0x2C - 0x4];
    s16 unk2C;
    u8 pad2E[0x38 - 0x2E];
    f32 unk38;
    u8 pad3C[0xDC - 0x3C];
    s8 *unkDC;
    u8 padE0[0x161 - 0xE0];
    u8 type;
} ListNode801AB2F0;

s32 func_801AB2F0(s32 arg0);

s32 func_801AB404(u8 *arg0);

s32 func_801AB58C(u8 *self);
static inline void split_externs_801AB58C(void) { extern volatile s32 D_802900C8; extern f32 D_8010B3BC, D_8010B3C0, D_8010B3C4, D_8010B3C8; extern f32 D_8029F9D4, D_8029F9D8, D_8029F9DC, D_8029F9E0, D_8029F9E4; extern f32 D_802900D4; extern s32 D_802900D0; extern u8 *D_802903B4; extern s32 D_80290300; extern u8 *volatile D_8028FAC8; extern u8 *volatile D_8028FAD0; extern void func_801B13CC(void); extern void func_8018C700(s32, s32); }

extern const f32 D_8010B3CC;
extern const f32 D_8010B3D0;
extern const f32 D_8010B3D4;
extern const f32 D_8010B3D8;
extern const f32 D_8010B3E4;
extern const f32 D_8010B3E8;
extern const f32 D_8010B3F4;
extern const f32 D_8010B3F8;
extern const f32 D_8010B3FC;
extern const f32 D_8010B400;
extern const f32 D_8010B404;
extern s16 D_801F18CE;
extern f32 D_801F1A58;
extern f32 D_801F1A5C;
extern f32 D_801F1A60;
s32 func_801AB88C(u8 *self);

extern const f32 D_801F1A70;
extern const f32 D_801F1A64;
extern const f32 D_801F1A68;
extern const f32 D_801F1A74;
extern const f32 D_8010B408;
extern const f32 D_8010B40C;
extern const f32 D_8010B410;
extern const f32 D_8010B414;
extern const f32 D_8010B418;
extern const f32 D_8010B41C;
extern const f64 D_8010B420;
extern const f64 D_8010B428;
extern const f32 D_8010B430;
extern const f32 D_8010B434;
extern const f32 D_8010B438;
extern const f32 D_8010B43C;
extern const f32 D_8010B440;
extern const f32 D_8010B444;
extern const f64 D_8010B448;
extern const f64 D_8010B450;
extern const f32 D_8010B458;
extern const f32 D_8010B45C;
extern s16 D_801F0F0C;
extern f32 D_8010B424;
s32 func_801ABD38(u8 *arg0);
static inline void split_externs_801ABD38(void) { extern f32 D_801F1A6C; extern f32 D_801F1A70; extern f32 D_801F1A64; extern f32 D_801F1A68; extern f32 D_8010B408; extern f32 D_8010B40C; extern f32 D_8010B410; extern f32 D_8010B414; extern f32 D_8010B418; extern f32 D_8010B41C; extern f64 D_8010B420; extern f64 D_8010B428; extern f32 D_8010B430; extern f32 D_8010B434; extern f32 D_8010B438; extern f32 D_8010B43C; extern f32 D_8010B440; extern f32 D_8010B444; extern f64 D_8010B448; extern f64 D_8010B450; extern f32 D_8010B458; extern f32 D_8010B45C; extern s16 D_801F0F0C; extern s32 D_8029F0F0; extern s8 D_801E7531; extern s32 D_8029030C; extern f32 D_80290310; extern f32 D_80290314; extern f32 D_8028FBCC; extern f32 D_8029F9AC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern s16 D_8028FBF6; extern f32 D_8029F9D0; }

extern f32 D_8010B540;
extern f32 D_801EEC14;
extern s16 D_801F19B0;
extern f32 D_801F1998;
extern u8 D_80299718[];
extern u8 D_8029971C[];

s32 func_801AC2F4(u8 *arg0);

s32 func_801AC398(f32 *arg0);

s32 func_801AC518(u8 *o);
static inline void split_externs_801AC518(void) { extern s32 D_80290134; extern s16 D_8028FBEA; extern f32 D_80290334; extern f32 D_80290338; extern f32 D_801F1A80; extern f32 D_801F1A84; extern const f32 D_8010B480; extern const f32 D_8010B484; extern const f64 D_8010B488; extern const f32 D_8010B490; extern const f32 D_8010B494; extern const f32 D_8010B498; extern const f32 D_8010B49C; extern const f64 D_8010B4A0; extern const f32 D_8010B4A8; extern const f32 D_8010B4AC; extern const f64 D_8010B4B0; extern const f64 D_8010B4B8; extern const f64 D_8010B4C0; extern const f32 D_8010B4C8; extern const f32 D_8010B4D4; extern const f32 D_8010B4D8; extern const f32 D_8010B4E0; }

s32 func_801ACBD0(u8 *arg0);

void func_801ACDFC(void);
static inline void split_externs_801ACDFC(void) { extern u8 D_801F19C4[][8]; extern u8 D_801F19C5[][8]; extern u8 D_801F19C6[][8]; extern s32 D_80290138; extern f32 D_8010B510; extern f32 D_8010B514; extern f32 D_8010B518; void func_8015D020(u8 *); void func_801ADAF8(u8 *); void func_801AE2E8(s16, s32, void *); void func_801AD764(u8 *, u8 *); void func_801B0DDC(void); void func_801AEC14(void); }

void func_801AD764(u8 *arg0, u8 *arg1);
static inline void split_externs_801AD764(void) { extern s32 D_801FA750; extern s32 D_8010B51C[]; extern f32 D_8010B528; extern f32 D_8010B530; extern f32 D_8010B53C; extern s32 D_80297910; extern s16 D_801F19B6; void func_801B9894(s16, s16, s16, s16, s32); void func_801ADFC8(s16); void func_801B0DDC(void); void func_801AEC14(void); }

void func_801ADAF8(u8 *arg0);

void func_801ADDC4(u8 *arg0, s16 arg1, s32 arg2);

void func_801ADFC8(s16 arg0);

void func_801AE0CC(s32 arg0, s16 arg1);

void func_801AE204(s16 arg0);

void func_801AE244(void);

void func_801AE2E8(s16 arg0, s32 arg1, void *arg2);

void func_801AE348(u8 *arg0);


void func_801AE510(void);
static inline void split_externs_801AE510(void) { extern u8 D_8029F5CB; extern u8 D_8029F5D8[]; extern s32 D_8029F934; extern u8 D_8029F684[]; extern f32 D_8029F688, D_8029F68C, D_8029F690; extern f32 D_8029F768, D_8029F76C, D_8029F770, D_8029F774; extern f32 D_8029F84C, D_8029F850, D_8029F854, D_8029F858; extern f32 D_8029F930, D_8029F938, D_8029F93C; extern f32 D_8010B5EC, D_8010B5F0, D_8010B5F4, D_8010B5F8, D_8010B5FC, D_8010B600, D_8010B604; extern f32 D_8010B608, D_8010B60C, D_8010B610, D_8010B614, D_8010B618, D_8010B61C, D_8010B620; extern f32 D_8010B628; extern const f32 D_8010B634, D_8010B638, D_8010B63C, D_8010B640, D_8010B644, D_8010B648, D_8010B64C; extern const f32 D_8010B650, D_8010B654; extern f32 D_8010B660; extern const f64 D_8010B658; extern u8 D_8010B594[], D_8010B5A4[], D_8010B5B0[], D_8010B5BC[], D_8010B5C8[], D_8010B5D4[], D_8010B5E0[]; extern s16 D_8029F998; extern u8 D_8029F99A; extern u8 D_8029F99E; extern f32 D_8029F9D8; }

extern u8 D_80297940[];
extern u8 *D_8029FA50;
extern s32 D_8029F56C;
extern s32 D_8029F570;
extern s32 *D_8029F438;
extern s32 *D_8029F96C;
extern s32 *D_8029F45C;
extern s32 *D_8029FA5C;
extern s32 *D_8029F968;
extern s32 *D_8029F5D0;

void func_801AEB0C(s32 arg0);

void func_801AEC14(void);
static inline void split_externs_801AEC14(void) { extern u8 D_8029F5CA; extern u8 D_8029F5CB; extern u8 D_8029F5D8[]; extern f64 D_8010B664; extern f32 D_8010B66C; extern f32 D_8010B670; extern f32 D_8010B674; extern f32 D_8010B678; void func_801B3EF4(f32, f32, f32); void func_801B0DDC(void); }

void func_801AEE04(void);
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

void func_801B0DDC(void);
static inline void split_externs_801B0DDC(void) { extern u8 D_8010B848[]; extern s32 D_8029014C; extern s16 D_8028FBF6; extern s32 D_8029013C; extern f32 D_80290330; extern f32 D_80290334; extern f32 D_80290338; extern u8 D_8029F5CA; void func_801B3408(void); }

extern f32 D_8029F9D8;
extern f32 D_8010B864;
extern f32 D_8010B868;
extern f32 D_8010B86C;
extern f32 D_8010B870;
extern f32 D_8010B874;
extern f32 D_8010B878;
extern f32 D_8010B87C;
void func_801B101C(s32 arg0);

void func_801B10B8(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3);

void func_801B1344(s16 arg0);

void func_801B13CC(void);

f32 func_801B1498(void);

f32 func_801B150C(void);

extern s32 D_802901D4;
extern s16 D_8029010A;
extern f64 D_8010B8B8;
extern f64 D_8010B8C0;
extern f64 D_8010B8C8;

s32 func_801B1580(void);

void func_801B182C(void);
static inline void split_externs_801B182C(void) { extern s32 D_80290300; extern s32 D_80290090; extern s32 D_8029030C; extern f32 D_80290310; extern f32 D_80290314; extern f32 D_80290334; extern f32 D_8029F9D0; extern f32 D_8029F9D8; extern f32 D_8029F9B0; extern f32 D_801F1AE8; extern f32 D_801F1AEC; extern f32 D_8010B8D0; extern f32 D_8010B8D4; extern f32 D_8010B8D8; extern f32 D_8010B8DC; extern f32 D_8010B8E0; extern f32 D_8010B8EC; extern f32 D_8010B8F0; extern u8 D_80202218; extern u8 *D_802903AC; extern u8 *D_8029FA50; extern s8 D_8029F487; }

s32 func_801B1B4C(f32 *arg0, f32 *arg1);

void func_801B1E48(void);

void func_801B1E70(void);
static inline void split_externs_801B1E70(void) { extern f32 D_801F1AF0; extern f32 D_801F1AF4; extern f32 D_8029F430; extern f32 D_8029F434; extern u8 *D_802903B4; extern f32 D_8010B934; extern f32 D_8010B938; extern f32 D_8010B944; extern f64 D_8010B948; extern f64 D_8010B950; extern f64 D_8010B958; extern f32 D_8010B960; extern f32 D_8010B964; extern f64 D_8010B968; extern f64 D_8010B970; extern f64 D_8010B978; extern f64 D_8010B980; extern f32 D_8010B988; extern f32 D_8010B98C; extern f32 D_8010B990; extern f32 D_8010B99C; extern f32 D_8010B9A0; extern f32 D_8010B9AC; extern f32 D_8010B9B0; extern f32 D_8010B9B8; extern f32 D_8010B9C0; extern f32 D_8010B9CC; extern f64 D_8010B9D0; extern f64 D_8010B9D8; extern f64 D_8010B9E0; extern f32 D_8010B9E8; extern f32 D_8010B9EC; extern f64 D_8010B9F0; extern f32 D_8010B9F8; extern f32 D_8010BA00; extern f32 D_8010BA08; extern f32 D_8010BA14; extern f32 D_8010BA18; extern f32 D_8010BA20; extern f32 D_8010BA28; extern f32 D_8010BA34; extern f32 D_8010BA38; extern f32 D_80290334; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern f32 D_80290310; extern f32 D_80290314; }

void func_801B2A1C(void);

s32 func_801B2AF0(void);

void func_801B2B58(s32 arg0, f32 x, f32 z);
static inline void split_externs_801B2B58(void) { extern f32 D_8010BA44; extern f32 D_8010BA48; extern f32 D_8010BA4C; extern f32 D_8010BA50; extern f32 D_8010BA58; extern f32 D_8010BA60; extern s32 D_801ED3D0; extern s32 D_8029F978; extern u8 *D_802903AC; }

void func_801B31A8(s32 arg0);
static inline void split_externs_801B31A8(void) { extern const f32 D_8010BA6C; void func_801B2B58(s32, f32, f32); }

void func_801B33A0(u8 *arg0, u8 **arg1, s32 *arg2);

extern f32 D_8029FA34;
extern f32 D_8029FA38;
extern f32 D_8029FA3C;
extern u8 *D_8029FA60;
extern u8 D_8029F99E;
extern s32 D_8029014C;

void func_801B3408(void);

void func_801B362C(void *arg0, s32 arg1, s32 arg2, f32 arg3);

void func_801B392C(s32 arg0);

void func_801B39DC(s32 arg0, s32 arg1, f32 arg2);

void func_801B3BB8(s32 arg0);

void func_801B3CA8(void);

void func_801B3D60(void);

void func_801B3EF4(f32 arg0, f32 arg1, f32 arg2);

void func_801B4010(void);

void func_801B4030(s32 *arg0);

extern f32 D_8010BAE4, D_8010BAE8, D_8010BAEC, D_8010BB08, D_8010BB0C, D_8010BB10, D_8010BB14, D_8010BB18;
extern f32 D_8010BB34, D_8010BB60, D_8010BB64, D_8010BB78;
extern f64 D_8010BAF0, D_8010BAF8, D_8010BB00, D_8010BB20, D_8010BB28, D_8010BB38, D_8010BB40, D_8010BB48;
extern f64 D_8010BB50, D_8010BB58, D_8010BB68, D_8010BB70;
extern f32 D_801F1B00, D_8029F9EC;
void func_801B4078(s32 *arg0, u8 *arg1, s32 arg2);

void func_801B48D4(void);

void func_801B48DC(f32 arg0, void *arg1, s32 arg2, s16 arg3);

void func_801BB1DC(void);
void func_801B5490(void);
void func_801B4078(s32 *, u8 *, s32);
void func_801B6A78(u8 *);
extern s32 D_801F1B04;
extern f32 D_801F1B08;
extern f32 D_8010BBB4;
extern f32 D_8010BBB8;
extern f32 D_8010BBBC;
extern f32 D_8010BBC0;
extern u8 D_802A2000[];
extern u8 D_802A20E4[];

typedef struct V3_801B4D90 {
    f32 x, y, z;
} V3_801B4D90;
typedef struct Tab_801B4D90 {
    u8 pad[0x10];
    V3_801B4D90 rows[1][10];
} Tab_801B4D90;

void func_801B4BBC(void);

void func_801B4D90(void);

void func_801B52BC(f32 x, f32 y, f32 z, f32 scale, s32 count, f32 *arg5, s32 arg6, s16 arg7);

s32 *func_801B5458(s32 arg0);

extern s32 D_801F1B14;
extern u16 D_801F1B10;
extern u8 D_8028D7E0;
extern u8 D_8028D7E1;
extern u8 D_8028D7E2;
extern u16 D_8028D7E4;
extern u8 D_801ED427;
extern u8 D_802991A4;
extern u8 D_802991A5;
extern u8 D_802991A6;
extern s32 D_8029FA70;
extern f32 D_8010BBDC, D_8010BBE0, D_8010BBE4, D_8010BBE8;
extern f32 D_8010BBEC, D_8010BBF0, D_8010BBF4, D_8010BBF8;
extern f32 D_8010BBFC, D_8010BC00, D_8010BC04, D_8010BC08;
extern f32 D_8010BC0C, D_8010BC10, D_8010BC14;
extern f32 D_8010BC18, D_8010BC1C, D_8010BC20, D_8010BC24;
extern f32 D_8010BC3C, D_8010BC40, D_8010BC48, D_8010BC54;
extern f32 D_8010BC58, D_8010BC5C, D_8010BC60, D_8010BC64, D_8010BC68;
extern f32 D_8010BC6C, D_8010BC70, D_8010BC74, D_8010BC78, D_8010BC7C;
extern f32 D_8010BC80, D_8010BC84, D_8010BC88, D_8010BC8C, D_8010BC90;
void func_801B5490(void);
static inline void split_externs_801B5490(void) { extern s32 D_801F1B14; extern u16 D_801F1B10; extern u8 D_8028D7E0; extern u8 D_8028D7E1; extern u8 D_8028D7E2; extern u16 D_8028D7E4; extern u8 D_801ED427; extern s16 D_801ED404; extern u8 D_802991A0[]; extern u8 D_802991A4; extern u8 D_802991A5; extern u8 D_802991A6; extern s32 D_8029FA70; extern f32 D_8010BBDC, D_8010BBE0, D_8010BBE4, D_8010BBE8; extern f32 D_8010BBEC, D_8010BBF0, D_8010BBF4, D_8010BBF8; extern f32 D_8010BBFC, D_8010BC00, D_8010BC04, D_8010BC08; extern f32 D_8010BC0C, D_8010BC10, D_8010BC14; extern f32 D_8010BC18, D_8010BC1C, D_8010BC20, D_8010BC24; extern f32 D_8010BC3C, D_8010BC40, D_8010BC48, D_8010BC54; extern f32 D_8010BC58, D_8010BC5C, D_8010BC60, D_8010BC64, D_8010BC68; extern f32 D_8010BC6C, D_8010BC70, D_8010BC74, D_8010BC78, D_8010BC7C; extern f32 D_8010BC80, D_8010BC84, D_8010BC88, D_8010BC8C, D_8010BC90; }

s32 func_801B5F74(Obj801B5F74 *o, s32 *arg1, s32 arg2);

void func_801B614C(f32 *arg0, f32 *arg1, s32 arg2, f32 arg3, register f32 arg4, s32 *arg5);
static inline void split_externs_801B614C(void) { extern f32 D_801EC7A0; extern f64 D_8010BC94, D_8010BC9C, D_8010BCA4; extern f32 D_8010BCAC, D_8010BCB0, D_8010BCB4, D_8010BCB8; extern s32 D_8029790C; }


void func_801B6370(void);
static inline void split_externs_801B6370(void) { extern u8 D_8010BCE4[], D_8010BCF0[]; extern f32 D_8010BCF8, D_8010BCFC, D_8010BD00, D_8010BD04, D_8010BD08, D_8010BD0C; extern u8 D_8029FA80[]; extern u8 D_802A2000[]; extern u8 D_802A2020[]; extern u8 D_802A2028[]; extern u8 D_802A20BC[]; extern u8 D_802A20C0[]; extern u8 D_802A20C4[]; extern u8 D_802A20E4[]; extern u8 D_802A20E8[]; extern u8 D_801F1B2A[]; extern u8 D_801F1B2C[]; extern s16 D_801F1B18; }

s32 func_801B66D4(s32 id, f32 *pos, f32 *vec, s32 arg3, u8 *slot);
static inline void split_externs_801B66D4(void) { extern s32 D_801F1B20; extern f32 D_8010BD10; extern f32 D_8010BD14; extern f32 D_8010BD18; extern s32 D_801F1D84[][4]; extern u8 D_802A2000[]; }

inline void func_801B6A78(u8 *arg0);

void func_801B6B3C(void);
static inline void split_externs_801B6B3C(void) { extern f32 D_8010BD18[]; extern f32 D_8010BD20[]; extern f32 D_8010BD2C; extern f32 D_8010BD30; extern f32 D_8010BD34; extern f32 D_8010BD38; extern u8 D_801F1D84[]; extern u8 D_802A2024[]; extern u8 D_802A2028[]; extern u8 D_802A2034[]; extern u8 D_802A2058[]; extern u8 D_802A2060[]; extern u8 D_802A20BC[]; extern u8 D_802A20E5[]; extern u8 D_802A20F0[]; extern u8 D_802A2100[]; extern u8 D_802A2102[]; extern u8 D_802A2105[]; extern u8 D_802A2106[]; extern u8 D_802A2107[]; extern s32 D_802900F0; }

s32 func_801B70F8(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
static inline void split_externs_801B70F8(void) { extern f64 D_8010BD3C; extern const f32 D_8010BD44; extern const f32 D_8010BD48; }

void func_801B7344(s32 arg0, s32 arg1, f32 arg2);
static inline void split_externs_801B7344(void) { extern f32 D_8010BD48[]; }

void func_801B7494(void *arg0, s32 arg1, f32 arg2);
static inline void split_externs_801B7494(void) { extern f64 D_8010BD58; extern f32 D_8010BD60; }

void func_801B760C(u8 *arg0);
static inline void split_externs_801B760C(void) { extern f32 D_8010BD64; extern f32 D_8010BD68; extern f32 D_8010BD6C; void func_801BB5C4(s32, s32, f32); }

extern f64 D_8010BD70, D_8010BD78;
extern f32 D_8010BD80, D_8010BD88, D_8010BD8C, D_8010BD90, D_8010BD94;
extern const f32 D_8010BD84;
void func_801B7764(void *arg0, s32 arg1, s32 arg2);

void func_801B7984(f32 *arg0, f32 arg1);
static inline void split_externs_801B7984(void) { extern f32 D_8010BD98; extern f32 D_8010BD9C[]; extern f32 D_8010BDA4; }


extern u8 D_802AA7A0[];
extern u8 D_802AA7A4[];
extern u32 D_802AA820;
extern u8 D_802AA918[];
extern u32 D_802AA9D0;

void func_801B7B40(void);
static inline void split_externs_801B7B40(void) { extern u8 D_802AA918[]; extern u32 D_802AA9D0; }

extern u8 D_801F20F0;
extern u8 D_80202218;
extern u8 D_801EC7D2;
extern u16 D_802AA700;
extern s32 D_802AA798;
extern s32 D_802AA79C;
extern const f32 D_8010BDD4, D_8010BDD8, D_8010BDDC, D_8010BDE0, D_8010BDE4, D_8010BDE8;
extern const f32 D_8010BDEC, D_8010BDF0, D_8010BDF4, D_8010BDF8, D_8010BDFC;
extern const f32 D_8010BE00, D_8010BE04, D_8010BE08, D_8010BE0C;
void func_801B80A4(u8 *);

typedef struct Obj801B7C0C {
    struct Obj801B7C0C *next;
    u8 pad04[4];
    Vec3F pos;
    u8 state;
    u8 mode;
    s16 unk16;
    u16 unk18;
    u8 pad1A[0x12];
    u8 unk2C;
    u8 unk2D;
    u8 pad2E[0x52];
    s32 unk80;
    Vec3F unk84;
    s16 unk90;
    s16 unk92;
    u8 pad94[4];
    u8 unk98;
    u8 pad99[0x17];
    u16 unkB0;
} Obj801B7C0C;

void func_801B7BD0(s32 *arg0);

void func_801B7C0C(void);

extern f32 D_802AA834;
extern f32 D_802AA838;
extern f32 D_802AA72C;
extern f32 D_802AA730;
extern f32 D_802AA8AC;
extern f32 D_802AA8B0;
extern s32 D_802AA738;
extern s32 D_802AA73C;
extern u8 D_802AA743;
extern s32 D_802AA840;
extern s32 D_802AA844;
extern s32 D_802AA8B8;
extern s32 D_802AA8BC;
extern u8 D_802AA848;
extern u8 D_802AA849;
extern u8 D_802AA84A;
extern u8 D_802AA84B;
extern u8 D_802AA8C0;
extern u8 D_802AA8C1;
extern u8 D_802AA8C2;
extern s32 D_801F2104;
extern f32 D_801F2108;
extern u8 D_801F210C;
extern u8 D_801FAAF0[];
extern s32 D_801EAB6C[];
extern const char D_8010BE10[];
extern const f32 D_8010BE14, D_8010BE18, D_8010BE1C, D_8010BE20, D_8010BE24, D_8010BE28, D_8010BE2C;
extern const f32 D_8010BE30, D_8010BE34, D_8010BE38, D_8010BE3C;
void func_801B80A4(u8 *arg0);

void func_801B87C4(void);

void func_801B87E8(s32 *arg0);

void func_801B8824(void);

extern const f64 D_8010BE40, D_8010BE48, D_8010BE50, D_8010BE58, D_8010BE60, D_8010BE68;
extern const f32 D_8010BE70, D_8010BE74, D_8010BE78;
s32 func_801B8F84(u8 *, Vec3F *, Vec3F *);
void func_801B889C(Unk802AA7A0Node *arg0);

s32 func_801B8F84(u8 *arg0, Vec3F *arg1, Vec3F *arg2);
static inline void split_externs_801B8F84(void) { extern f32 D_8010BE7C; }

void func_801B9140(void);

void func_801B9164(s32 *arg0);

void func_801B91A0(ObjectNode *arg0);

void func_801B91D0(void);

void func_801B922C(u8 *arg0);
static inline void split_externs_801B922C(void) { extern const f32 D_8010BE80; extern const f32 D_8010BE84; extern const f32 D_8010BE88; extern const f32 D_8010BE8C; extern const f32 D_8010BE90; }

u32 *func_801B97EC(u32 *arg0, s32 arg1);

s32 *func_801B9824(s32 *arg0, s32 arg1);

Unk802AA7A0Node *func_801B985C(Unk802AA7A0Node *arg0, s32 arg1);

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
} Unk801F2120Blk;

extern s32 D_801F2120[];
extern s32 D_801F2124;
extern s32 D_801F2128;
extern s32 D_801F212C;
extern u32 D_802AAF58;
extern u32 D_802AA9E0[];

extern f64 D_8010BE94;
extern f64 D_8010BE9C;
extern f64 D_8010BEA4;

void func_801B9894(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4);


extern f64 D_8010BEE8;
extern f64 D_8010BEF0;
extern f32 D_8010BEF4;
extern f32 D_8010BEF8;
extern f32 D_8010BEFC;
extern f32 D_8010BF00;
extern f32 D_8010BF04;
extern f32 D_8010BF08;
extern f32 D_8010BF0C;
extern f32 D_8010BF10;
extern f32 D_801F2110;
extern f32 D_801F2114;
extern f32 D_801F2118;
extern f32 D_801F211C;
extern Vec3F D_801EC7B0;
extern Vec3F D_801EC7BC;
extern f32 D_8028F938;
extern f32 D_80290330;

extern const f32 D_8010BEE0;
void func_801B9C44(void);

s32 func_801BA030(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3, f32 *arg4);

extern f32 D_8010BF14;
extern f32 D_8010BF18;
extern f32 D_8010BF1C;
extern f32 D_8010BF20;
extern f32 D_8010BF24;
extern f32 D_80290334;
extern f32 D_80290338;
extern f32 D_8029035C;
extern f32 D_80290360;
void func_801BA0E0(u8 *arg0, f32 arg1, f32 arg2, u8 *arg3, f32 arg4, f32 arg5);

void func_801BA5BC(u8 *arg0);

void func_801BA644(TrailBuf *buf, TrailVec *a, TrailVec *b, u8 c, u8 d, u8 e, u8 f);

void func_801BA700(TrailBuf *buf, TrailVec *a, TrailVec *b);

void func_801BA7B8(u8 *arg0);

void func_801BA84C(void *arg0);

void func_801BAF6C(void);
static inline void split_externs_801BAF6C(void) { extern u32 D_802AA9E4; }

void func_801BAF8C(u8 *arg0);

extern u32 D_802AAF58;
extern u32 D_802AA9E0[];

extern Gfx D_801F2130[];
void func_801BA84C(void *);

void func_801BB064(ObjectNode *arg0);

void func_801BB0A4(void);

void func_801BB128(void);

void func_801BB1DC(void);
static inline void split_externs_801BB1DC(void) { extern s32 D_802AAFE0; extern u8 D_802AAFE7; extern u8 D_801F2180; extern const f64 D_8010BF28; extern const f64 D_8010BF30; }

void func_801BB554(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u16 arg9);

void func_801BB5C4(s32 arg0, s32 arg1, f32 arg2);


extern u8 D_801F2198[];
extern u8 D_801F21DC[];
extern s32 D_801F2190;
extern u8 D_801F2197[];
extern u8 D_801F21AC[];
extern u8 D_801F21AF[];
extern u8 D_801FAAC8[];
extern u8 D_801FAAD0[];
extern u8 D_801FAAD1[];
extern u8 D_801FAAD2[];
extern u8 D_801FAAD3[];
extern u8 D_80202218;
extern s32 D_802AAFFC;
s32 func_801BB8D4(void);
s8 func_801BB938(void);
s32 func_801793DC(s32, u8, u8, u8);

s32 func_801BB710(void);

s32 func_801BB8D4(void);
static inline void split_externs_801BB8D4(void) { extern u8 D_801FAAD0[]; extern u8 D_801FAAD1[]; extern u8 D_801FAAD2[]; }

s8 func_801BB938(void);

void func_801BB9AC(u8 arg0, u8 arg1);
static inline void split_externs_801BB9AC(void) { extern s32 func_801BC5E4(u8); extern void func_8018C700(s32, s32); extern void func_8011BD60(void); extern void func_8014D61C(s32, s32, s32, s32, s32); extern void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); extern u8 D_801F21E4[]; extern u8 D_801F21BC[]; extern u8 D_801F21A0; extern f32 D_8029FA3C, D_8029FA38, D_8029FA34; extern u8 D_8029F5FE[]; extern f32 D_801ED680; extern f32 D_8010BFFC, D_8010C000, D_8010C004, D_8010C008, D_8010C00C; extern u8 D_8010BFF0[]; extern u8 D_8010BF64[]; extern char D_8010BF70[], D_8010BF78[]; extern s32 D_802901A0, D_802901A4, D_802901AC, D_802901B0, D_802901D0, D_802901D4; extern s16 D_8029011C; }

extern Unk802847F8Node *D_801F21A4;
extern s32 D_801F2638;
extern s32 D_801F2194;
extern f32 D_8010C010;

void func_801BC240(void);

void func_801BC43C(void);

s32 func_801BC5E4(s32 arg0);

#endif /* TEMP bisect */
