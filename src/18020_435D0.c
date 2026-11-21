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

extern u8 D_801EC7D2;
void func_80133900(u8 *arg0);
void func_80133BD0(u8 *arg0);
u32 func_80139CA0(u8 *arg0);
void func_8013A1F4(void);
extern s32 D_80269F68;
extern s32 D_8026A140;

#if 1 /* TEMP bisect */
/* Relocate one serialized model record and its child/sibling tree in stream order. */
s32 func_801425D0(s32 **nodeOut, s16 modelFlags) {
    s32 *relocationBase;
    s32 *record;
    s32 recordSize;
    s32 *mesh;
    s32 triangleOffset;

    record = (s32 *)D_80269F68;
    recordSize = record[0];
    D_8026A140 = (s32)((u8 *)record + MODEL_RECORD_NODE_OFFSET);
    *nodeOut = (s32 *)((u8 *)record + MODEL_RECORD_NODE_OFFSET);
    if (*((u8 *)record + MODEL_RECORD_RELOCATED_OFFSET) != 0) {
        return 0;
    }
    *(s16 *)((u8 *)record + MODEL_RECORD_FLAGS_OFFSET) = modelFlags;
    relocationBase = (s32 *)D_80269F68;
    ((s32 *)*nodeOut)[MODEL_NODE_MESH_WORD] = (s32)relocationBase + ((s32 *)*nodeOut)[MODEL_NODE_MESH_WORD];
    ((s32 *)*nodeOut)[MODEL_NODE_UNK1C_WORD] = (s32)relocationBase + ((s32 *)*nodeOut)[MODEL_NODE_UNK1C_WORD];
    ((s32 *)*nodeOut)[MODEL_NODE_UNK20_WORD] = (s32)relocationBase + ((s32 *)*nodeOut)[MODEL_NODE_UNK20_WORD];
    ((s32 *)*nodeOut)[MODEL_NODE_UNK24_WORD] = (s32)relocationBase + ((s32 *)*nodeOut)[MODEL_NODE_UNK24_WORD];
    ((s32 *)((s32 *)*nodeOut)[MODEL_NODE_MESH_WORD])[MODEL_MESH_POSITIONS_WORD] = (s32)relocationBase + ((s32 *)((s32 *)*nodeOut)[MODEL_NODE_MESH_WORD])[MODEL_MESH_POSITIONS_WORD];
    mesh = (s32 *)((s32 *)*nodeOut)[MODEL_NODE_MESH_WORD];
    triangleOffset = mesh[MODEL_MESH_TRIANGLES_WORD];
    D_80269F68 = (s32)relocationBase + recordSize;
    mesh[MODEL_MESH_TRIANGLES_WORD] = (s32)relocationBase + triangleOffset;
    if (((s32 *)*nodeOut)[ACTOR_MODEL_CHILD_WORD] != 0) {
        func_801425D0((s32 **)((u8 *)*nodeOut + MODEL_NODE_CHILD_OFFSET), modelFlags);
    }
    if (((s32 *)*nodeOut)[ACTOR_MODEL_SIBLING_WORD] != 0) {
        func_801425D0((s32 **)((u8 *)*nodeOut + MODEL_NODE_SIBLING_OFFSET), modelFlags);
    }
    *((u8 *)*nodeOut + MODEL_NODE_RELOCATED_OFFSET) = 1;
    return recordSize;
}

void func_80142700(void *objectData, s32 componentFlags) {
    u8 *object = objectData;
    s32 components = componentFlags;
    u8 allocationLabel[OBJECT_COMPONENT_LABEL_BYTES];
    s32 contactIndex;
    f32 unitScale = D_80105FB0;

    /* Initialize scale, requested object components, and default visibility. */
    *(f32 *)(object + OBJECT_SCALE_Z) = unitScale;
    *(f32 *)(object + OBJECT_SCALE_Y) = unitScale;
    *(f32 *)(object + OBJECT_SCALE_X) = unitScale;
    if (components & OBJECT_COMPONENT_PHYSICS) {
        u8 *physics;
        f32 defaultUnk2C;
        func_801D2150(allocationLabel, D_80105F74, D_801EC814++);
        physics = func_8013FCDC(OBJECT_PHYSICS_BYTES, 1, (s32 *)allocationLabel);
        defaultUnk2C = D_80105FB4;
        *(u8 **)(object + ACTOR_PHYSICS) = physics;
        *(f32 *)(physics + PHYSICS_UNK2C) = defaultUnk2C;
    }
    if (components & OBJECT_COMPONENT_COLLISION) {
        u8 *collision;
        func_801D2150(allocationLabel, D_80105F80, D_801EC810++);
        collision = func_8013FCDC(OBJECT_COLLISION_BYTES, 1, (s32 *)allocationLabel);
        *(u8 **)(object + ACTOR_MODEL_STATE) = collision;
        collision[COLLISION_SPHERE_COUNT] = 1;
        *(s16 *)(*(u8 **)(object + ACTOR_MODEL_STATE) + COLLISION_FIRST_SPHERE_FLAGS) = COLLISION_INITIAL_SPHERE_FLAGS;
        for (contactIndex = 0; contactIndex < COLLISION_CONTACT_SLOTS; contactIndex++) {
            *(s32 *)(*(u8 **)(object + ACTOR_MODEL_STATE) + contactIndex * 4) = 0;
            *(s32 *)(*(u8 **)(object + ACTOR_MODEL_STATE) + contactIndex * 4 + COLLISION_UNK044_SLOTS) = 0;
        }
    }
    if (components & OBJECT_COMPONENT_ANIMATION) {
        if (*(u8 **)(object + OBJECT_COMPONENT_MODEL) != 0 && *(s32 *)(*(u8 **)(object + OBJECT_COMPONENT_MODEL) + MODEL_ANIMATION_TEMPLATE) != 0) {
            *(void **)(object + ACTOR_ANIMATION) = func_8013FCDC(OBJECT_ANIMATION_BYTES, 1, (s32 *)D_80105F8C);
            func_80133900(object);
        }
    }
    if (components & OBJECT_COMPONENT_SHADOW) {
        u8 *shadow;
        *(void **)(object + SHADOW_OBJECT_STATE) = func_8013FCDC(OBJECT_SHADOW_BYTES, 1, (s32 *)D_80105F98);
        *(ObjectShadowQuadWords *)(*(u8 **)(object + SHADOW_OBJECT_STATE) + SHADOW_QUAD_OFFSET) = *(ObjectShadowQuadWords *)D_801F0238;
        shadow = *(u8 **)(object + SHADOW_OBJECT_STATE);
        shadow[SHADOW_UNK0C] = shadow[SHADOW_UNK0D] = 0xFF;
        *(*(u8 **)(object + SHADOW_OBJECT_STATE) + SHADOW_UNK0E) = SHADOW_INITIAL_UNK0E;
    }
    if (components & OBJECT_COMPONENT_STATS) {
        u8 *stats;
        f32 unitFactor;
        stats = func_8013FCDC(OBJECT_STATS_BYTES, 1, (s32 *)D_80105FA4);
        *(u8 **)(object + OBJECT_COMPONENT_STATS_OFFSET) = stats;
        *(s8 *)(stats + STATS_ACTOR_INDEX) = -1;
        unitFactor = D_80105FB8;
        *(s32 *)(*(u8 **)(object + OBJECT_COMPONENT_STATS_OFFSET) + STATS_UNK18) = 0;
        *(f32 *)(*(u8 **)(object + OBJECT_COMPONENT_STATS_OFFSET) + STATS_UNK10) = unitFactor;
        *(f32 *)(*(u8 **)(object + OBJECT_COMPONENT_STATS_OFFSET) + STATS_UNK14) = unitFactor;
    }
    object[ACTOR_ACTIVE_STATE] = 1;
    *(s16 *)(object + OBJECT_RENDER_OPACITY) = OBJECT_INITIAL_OPACITY;
}

/*
 * Loads the model named `name` into obj->meshRef (looked up by its CRC hash) and, if found, creates
 * the object's `components` and places it at (x, y, z) with unit scale (D_80105FBC) and the
 * identity rotation D_801ED3D0.
 */
void func_80142928(void *object, s32 name, f32 x, f32 y, f32 z, s32 components) {
    typedef struct { s32 a, b, c, d; } Quad32;
    ObjectNode *obj;
    f32 scale;

    func_80151FD0((s32)object + 0xC8, func_80139CA0(name), name, 1);

    if (*(s32 *)((u8 *)object + 0xC8) != 0) {
        func_80142700(object, components);
        scale = D_80105FBC;
        obj = object;
        *(f32 *)&obj->posX = x;
        *(f32 *)&obj->posY = y;
        *(f32 *)&obj->posZ = z;
        *(f32 *)&obj->scaleZ = scale;
        *(f32 *)&obj->scaleY = scale;
        *(f32 *)&obj->scaleX = scale;
        *(Quad32 *)&obj->rotW = *(Quad32 *)&D_801ED3D0;
    }
}

extern u8 D_80105FC0[], D_80105FCC[], D_80105FD8[], D_80105FE8[], D_80105FF4[];
extern u8 D_80106004[], D_80106010[], D_8010601C[], D_8010602C[], D_80106038[], D_80106048[], D_80106054[];
extern const f32 D_80106060, D_80106064, D_80106068, D_8010606C, D_80106070;
extern volatile f32 D_80106074, D_80106078, D_8010607C;
extern const f32 D_80106080, D_80106084;

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

/*
 * Level start: build the player object (D_802902D8, special model on level
 * 0x28 and levels 0x2C/0x2D) and the ball (D_8029F978), load the shared
 * models by name, set up the 3 + 4 pooled effect objects and load every
 * not-yet-loaded model in the D_801F0330 table.
 */
void func_80142A10(void) {
    typedef struct {
        u8 name[0x10];
        s32 unk10;
        s16 unk14;
        u8 pad16[0xAA];
    } ModelTableEntry;
    extern Obj80142A10 D_80297940[];
    extern Obj80142A10 D_8029F5D8[];
    extern s32 D_8029F460, D_8029F0F0, D_802996E4;
    extern u8 D_8029FA60[];
    extern f32 D_8029FA3C, D_8029FA38, D_8029FA34;
    extern ModelTableEntry D_801F0330[];
    u8 modelName[0x10];
    u8 *object;
    Obj80142A10 *effect;
    f32 effectArg, effectScale, scale;
    s32 i;

    /* Player */
    object = (u8 *)&D_802902D8;
    *(s32 *)object = 0;
    D_80290300 |= 4;
    if (D_801E7531 == 0x28) {
        func_80142A10_init(object, (s32)D_80105FC0, 0.0f, 0.0f, 0.0f, -1, &D_80106060);
        scale = D_80106064;
        D_8029039C = scale;
        D_80290398 = scale;
        D_80290394 = scale;
        func_80191284(object, 0x26);
    } else {
        if ((u8)(D_801E7531 - 0x2C) < 2) {
            func_80142A10_init(object, (s32)D_80105FCC, 0.0f, 0.0f, 0.0f, -1, &D_80106068);
        } else {
            func_80142A10_init(object, (s32)D_80105FD8, 0.0f, 0.0f, 0.0f, -1, &D_80106068);
        }
        scale = D_8010606C;
        *(f32 *)(object + 0xC4) = scale;
        *(f32 *)(object + 0xC0) = scale;
        *(f32 *)(object + 0xBC) = scale;
    }
    func_8015C840(object);

    /* Ball */
    object = (u8 *)&D_8029F978;
    *(s32 *)object = 0;
    D_8029F9A0 |= 4;
    func_80142A10_init(object, (s32)D_80105FE8, 0.0f, 0.0f, 0.0f, 0x1A, &D_80106070);
    func_8015C840(object);

    effectArg = D_80106074;
    effectScale = D_80106078;
    D_8029FA34 = D_8029FA38 = D_8029FA3C = D_8010607C;
    /* Shared models, looked up by the CRC of their names. */
    func_801D2150(modelName, D_80105FF4);
    func_80151FD0((s32)&D_8029F5CC, func_80139CA0(modelName), (s32)modelName, 0);
    func_801D2150(modelName, D_80106004);
    func_80151FD0((s32)D_8029FA60, func_80139CA0(modelName), (s32)modelName, 0);
    func_801D2150(modelName, D_80106010);
    func_80151FD0((s32)&D_8029F460, func_80139CA0(modelName), (s32)modelName, 0);
    func_801D2150(modelName, D_8010601C);
    func_80151FD0((s32)&D_8029F43C, func_80139CA0(modelName), (s32)modelName, 0);
    func_801D2150(modelName, D_8010602C);
    func_80151FD0((s32)&D_8029F970, func_80139CA0(modelName), (s32)modelName, 0);
    func_801D2150(modelName, D_80106038);
    func_80151FD0((s32)&D_8029F0F0, func_80139CA0(modelName), (s32)modelName, 0);
    func_801D2150(modelName, D_80106048);
    func_80151FD0((s32)&D_802996E4, func_80139CA0(modelName), (s32)modelName, 0);
    for (i = 0; i < 3; i++) {
        effect = &D_80297940[i];
        effect->unk00 = 0;
        effect->flags |= 4;
        func_80142A10_setup(effect, (s32)D_80105FE8, 0.0f, 0.0f, 0.0f, 0, effectArg);
        effect->scaleZ = effectScale;
        effect->scaleY = effectScale;
        effect->scaleX = effectScale;
    }
    for (i = 0; i < 4; i++) {
        effect = &D_8029F5D8[i];
        effect->unk00 = 0;
        effect->flags |= 4;
        func_80142A10_setup(effect, (s32)D_80106054, 0.0f, 0.0f, 0.0f, 0x10, D_80106080);
        effect->scaleZ = D_80106084;
        effect->scaleY = D_80106084;
        effect->scaleX = D_80106084;
    }
    for (i = 0; i < 0x1E; i++) {
        if (D_801F0330[i].unk14 == 0) {
            func_80151FD0((s32)&D_801F0330[i].unk10, func_80139CA0(D_801F0330[i].name), (s32)D_801F0330[i].name, 0);
        }
    }
}

/* Rebuilds the cached fixed-point model matrix of every type-0x3C object:
 * translate * rotate (quaternion) * scale, converted into a fresh 0x40-byte
 * Mtx stored in displayList. Other objects get their cached matrix cleared. */
void func_8014308C(void) {
    ObjectNode *node;
    s32 rotation[16];
    s32 scale[16];
    s32 translation[16];

    for (node = D_8026A148.next; node != &D_8026A148; node = node->next) {
        if (node->type == 0x3C) {
            if (node->meshRef != 0) {
                func_80141720(&node->displayList);  /* free the old matrix */
            }
            node->displayList = (s32)func_8013FCDC(0x40, 1, &D_80106088);
        } else {
            node->displayList = 0;
            continue;
        }
        func_801C61A0(translation, node->posX, node->posY, node->posZ);  /* guTranslateF */
        func_80149834(translation);                                      /* push and multiply */
        func_801484F0(&node->rotW, rotation);                             /* quaternion to matrix */
        func_80149834(rotation);
        func_801C5F20(scale, node->scaleX, node->scaleY, node->scaleZ);   /* guScaleF */
        func_80149834(scale);
        func_80149940();
        func_801C5300(&D_80284D74, (u32 *)node->displayList);            /* guMtxF2L */
        func_801498CC();                                                 /* pop x3 */
        func_801498CC();
        func_801498CC();
    }
}

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

/* Sort scene objects by distance, draw their render passes and effects, then finish the graphics task. */
void func_801431AC(void) {
    extern u8 D_80106090[];
    extern s32 D_8026A054;
    extern s32 D_80269F84;
    extern s32 D_80269F80;
    extern u8 D_801EC7F4;
    extern s32 D_801EC86C;
    extern u8 D_801EC7E6;
    extern u8 D_80263AC0[];
    extern u8 D_801EC7D1;
    extern u8 D_801EC7EB;
    extern s16 D_801ED404[];
    extern s16 D_801ED406[];
    extern RenderObjectSlot D_802A2000[];
    extern RenderObjectActiveSlot D_802A20E4[];
    extern RenderObjectMeshSlot D_802A20C8[];
    extern s32 D_80289310;
    extern s8 D_801E7530;
    extern u8 D_801EC7E4;
    extern u8 D_801EC7EC;
    void func_801804A0(s32, void *);
    void func_80180534(s32);
    void func_801B3D60(void);
    void func_8015C7C4(ObjectNode *);
    void func_8013A874(void);
    void func_80189224(u8 *);
    void func_8014BB90(void);
    void func_8014BE1C(u8 *);
    void func_801A8794(void);
    void func_801A7AC4(u32);
    void func_801A7B8C(void);
    void func_801A6C24(void);
    void func_80189C9C(void);
    void func_801BB0A4(void);
    void func_8013D624(s32, s32);
    ObjectNode *object;
    u8 *linkedObject;
    u8 *remainingEffects;
    s32 objectIndex;
    u16 modelFlags;

    func_801804A0(SCENE_RENDER_PROFILE, D_80106090);
    if (D_8029F5C9 != 0) {
        func_801B3D60();
    }
    object = D_8026A148.next;
    {
        s32 *sortCount = &D_8026A054;
        *sortCount = 0;
        sortCount = (s32 *)((u8 *)sortCount - 0xE4);
        D_80269F84 = (s32)sortCount;
        D_80269F80 = (s32)sortCount;
    }
    for (; object != &D_8026A148; object = object->next) {
        *(f32 *)&object->unk018 = func_80148EBC(&object->posX, (s32)&D_8028F914);
        func_8015C7C4(object);
    }
    func_80180534(SCENE_RENDER_PROFILE);
    D_801EC86C = 0;
    D_801EC7E6 = 1;
    D_801EC866 = 0;
    D_80269F3C = (s32)&D_80263AC0[D_801EC7F4 * RENDER_WORK_BUFFER_SIZE];
    func_801804A0(SCENE_RENDER_PROFILE, D_80106090);
    D_801EC7EB = D_801EC7D1;
    func_8013CEEC();
    func_8013A874();
    func_8013A284();
    func_8013A1F4();
    if (D_801ED403 != 0) {
        { Gfx *command = D_80202240++; command->w0 = GFX_CMD_FOG_COLOR; command->w1 = (((RenderStateByte *)&D_801ED400)->value << 24) | (((RenderStateByte *)&D_801ED401)->value << 16) | (((RenderStateByte *)&D_801ED402)->value << 8) | 0xFF; } { Gfx *command = D_80202240++; command->w0 = GFX_CMD_FOG_POSITION; command->w1 = ((FOG_SCALE_NUMERATOR / (D_801ED406[0] - D_801ED404[0])) << 16) | ((((FOG_OFFSET_BIAS - D_801ED404[0]) << 8) / (D_801ED406[0] - D_801ED404[0])) & 0xFFFF); }
    }
    {
        s32 *sortLink = &D_80269F80;
        for (object = (ObjectNode *)*sortLink; object != (ObjectNode *)((u8 *)sortLink - 0x10); object = (ObjectNode *)object->unk010) {
            u8 *model = *(u8 **)(object->meshRef + 0xC);
            if (!(*(s32 *)(model + 0x30) & (MODEL_RENDER_TRANSLUCENT | MODEL_RENDER_LATE_PASS))) {
                if (!(*(u16 *)(model + 0x32) & MODEL_RENDER_SKIP_LIGHTS)) {
                    func_80189224((u8 *)object);
                }
                func_801437E4((u8 *)object);
            }
        }
    }
    for (objectIndex = 0; objectIndex < RENDER_OBJECT_SLOT_COUNT; objectIndex++) {
        if (D_802A20E4[objectIndex].active != 0 && D_802A20C8[objectIndex].meshRef != 0) {
            func_80189224(D_802A2000[objectIndex].bytes);
            func_801437E4(D_802A2000[objectIndex].bytes);
        }
    }
    for (linkedObject = *(u8 **)&D_8029F210; linkedObject != (u8 *)&D_8029F210; linkedObject = *(u8 **)linkedObject) {
        if (*(u8 **)(linkedObject + 0xD0) != 0 && !(*(u16 *)(*(u8 **)(*(u8 **)(linkedObject + 0xD0) + 0xC) + 0x32) & MODEL_RENDER_TRANSLUCENT)) {
            func_80189224(linkedObject + 8);
            func_801437E4(linkedObject + 8);
        }
    }
    if (D_80289310 != 0) {
        remainingEffects = ((u8 *(*)(void))func_8014BB90)();
        D_801EC7EB = D_801EC7D1;
        { Gfx *command = D_80202240++; command->w0 = GFX_CMD_PIPE_SYNC; command->w1 = 0; }
        func_8013CEEC();
        func_8013A874();
        func_8013A284();
        func_8013A1F4();
    }
    {
        s32 *sortLink = &D_80269F84;
        for (object = (ObjectNode *)*sortLink; object != (ObjectNode *)((u8 *)sortLink - 0x14); object = (ObjectNode *)object->unk014) {
            u8 *model = *(u8 **)(object->meshRef + 0xC);
            if ((*(s32 *)(model + 0x30) & (MODEL_RENDER_TRANSLUCENT | MODEL_RENDER_LATE_PASS)) == MODEL_RENDER_TRANSLUCENT) {
                if (!(*(u16 *)(model + 0x32) & MODEL_RENDER_SKIP_LIGHTS)) {
                    func_80189224((u8 *)object);
                }
                func_801437E4((u8 *)object);
            }
        }
    }
    for (linkedObject = *(u8 **)&D_8029F210; linkedObject != (u8 *)&D_8029F210; linkedObject = *(u8 **)linkedObject) {
        if (*(u8 **)(linkedObject + 0xD0) != 0 && (*(u16 *)(*(u8 **)(*(u8 **)(linkedObject + 0xD0) + 0xC) + 0x32) & MODEL_RENDER_TRANSLUCENT)) {
            func_80189224(linkedObject + 8);
            func_801437E4(linkedObject + 8);
        }
    }
    if (D_80289310 != 0) {
        func_8014BE1C(remainingEffects);
    }
    if ((u32)((u8)D_801E7530 - 4) < 2) {
        func_801A8794();
        {
            s32 *sortLink = &D_80269F80;
            object = (ObjectNode *)*sortLink;
            D_801EC7E4 = 1;
            for (; object != (ObjectNode *)((u8 *)sortLink - 0x10); object = (ObjectNode *)object->unk010) {
                modelFlags = *(u16 *)(*(u8 **)(object->meshRef + 0xC) + 0x32);
                if (modelFlags & MODEL_RENDER_LATE_PASS) {
                    if (!(modelFlags & MODEL_RENDER_SKIP_LIGHTS)) {
                        func_80189224((u8 *)object);
                    }
                    func_801A7AC4(((u8 *)object)[0x27]);
                    func_801437E4((u8 *)object);
                }
            }
        }
        D_801EC7E4 = 0;
        D_801EC7EC = 1;
        func_801A7B8C();
        func_801A6C24();
        func_80189C9C();
        func_801BB0A4();
        D_801EC7EC = 0;
    }
    func_8013A6B0();
    D_801EC866 = 1;
    func_8013A874();
    for (objectIndex = 0; objectIndex < D_801EC860; objectIndex++) {
        *(s32 *)(D_80269F40[objectIndex] + 0x18) = 0;
        if (!(*(u16 *)(*(u8 **)(*(s32 *)(D_80269F40[objectIndex] + 0xC8) + 0xC) + 0x32) & MODEL_RENDER_SKIP_LIGHTS)) {
            func_80189224(D_80269F40[objectIndex]);
        }
        func_801437E4(D_80269F40[objectIndex]);
    }
    func_8013D624(0, 0);
    func_80180534(SCENE_RENDER_PROFILE);
    { Gfx *command = D_80202240++; command->w0 = GFX_CMD_PIPE_SYNC; command->w1 = 0; }
    { Gfx *command = D_80202240++; command->w0 = GFX_CMD_SET_CYCLE_TYPE; command->w1 = 0; }
}

/* Draw the object's animated model tree, applying its transform and optional deformation. */
void func_801437E4(u8 *object) {
    void func_801C61A0(f32 *, s32, s32, s32);
    void func_801C5F20(f32 *, s32, s32, s32);
    void func_801C5580(f32 *, f32 *, f32 *);
    f32 rotationMatrix[16];
    f32 deformationMatrix[16];
    f32 placementMatrix[16];
    f32 inverseDeformationRotation[4];
    f32 animationFrame = 0.0f;
    u8 *model;
    u8 *animation;
    s32 rootNode;
    u16 opacity;

    D_80263ABC = *(s32 *)(object + OBJECT_CACHED_MATRICES);
    if (D_80263ABC != 0 && D_801EC87C == 0) {
        D_8026A144 = 1;
    } else {
        D_8026A144 = 0;
    }
    if (D_801EC866 == 0 && !func_80145258(object)) {
        return;
    }
    if (D_801EC7D2 == 0 && D_8025D0B0 != 0) {
        if (*(u8 **)(object + ACTOR_TYPE_DATA) == 0 || (*(s8 **)(object + ACTOR_TYPE_DATA))[ACTOR_TYPE_SLOT] == -1
            || (s16)D_8029999C[(*(s8 **)(object + ACTOR_TYPE_DATA))[ACTOR_TYPE_SLOT]][0] == 0) {
            func_80133BD0(object);
        }
    }
    if (*(s16 *)(object + OBJECT_RENDER_OPACITY) == 0) {
        return;
    }
    D_801EC870 = 0;
    if (D_801EC87C == 1 || D_8026A144 == 0) {
        func_801C61A0(placementMatrix, *(s32 *)(object + ACTOR_POSITION), *(s32 *)(object + ACTOR_POSITION_Y), *(s32 *)(object + ACTOR_POSITION_Z));
        func_80149834((s32 *)placementMatrix);
        if (*(u8 **)(object + ACTOR_TYPE_DATA) != 0 && *(f32 *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_AMOUNT) != 0.0f) {
            func_801C5F20(deformationMatrix, *(s32 *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_SCALE_XZ), *(s32 *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_SCALE_Y), *(s32 *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_SCALE_XZ));
            func_801484F0((f32 *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_ORIENTATION), rotationMatrix);
            func_801C5580(deformationMatrix, rotationMatrix, deformationMatrix);
            func_80149834((s32 *)deformationMatrix);
            *(RenderQuaternionWords *)inverseDeformationRotation = *(RenderQuaternionWords *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_ORIENTATION);
            inverseDeformationRotation[3] = -inverseDeformationRotation[3];
            func_801484F0(inverseDeformationRotation, placementMatrix);
            func_80149834((s32 *)placementMatrix);
        }
        func_801484F0((f32 *)(object + ACTOR_ORIENTATION), rotationMatrix);
        func_80149834((s32 *)rotationMatrix);
        D_80263AB0 = *(f32 *)(object + OBJECT_SCALE_X);
        D_80263AB4 = *(f32 *)(object + OBJECT_SCALE_Y);
        D_80263AB8 = *(f32 *)(object + OBJECT_SCALE_Z);
        D_80269EC0 = D_80269EC4 = D_80269EC8 = D_80106098;
        animation = *(u8 **)(object + ACTOR_ANIMATION);
        animationFrame = 0.0f;
        D_801EC868 = 0;
        if (animation != 0 && *(s32 *)(animation + ANIM_PLAYBACK_CLIPS) != 0) {
            animationFrame = *(f32 *)(animation + ANIM_PLAYBACK_FRAME);
        }
    }
    model = *(u8 **)(object + ACTOR_MESH);
    opacity = *(u16 *)(object + OBJECT_RENDER_OPACITY);
    rootNode = *(s32 *)(model + ACTOR_MESH_ROOT);
    D_80269F38 = object;
    D_801EC87A = opacity;
    if (rootNode != 0) {
        func_80143AFC(rootNode, animationFrame, 0, 0);
    }
    if (D_801EC87C == 1 || D_8026A144 == 0) {
        func_801498CC();
        func_801498CC();
        if (*(u8 **)(object + ACTOR_TYPE_DATA) != 0 && *(f32 *)(*(u8 **)(object + ACTOR_TYPE_DATA) + TYPE_DEFORM_AMOUNT) != 0.0f) {
            func_801498CC();
            func_801498CC();
        }
    }
}

extern f32 D_8010609C, D_801060A0, D_801060A4, D_801060A8, D_801060AC, D_801060B0;
extern u8 D_801EC7E2, D_801EC7E3, D_801EC7E4, D_801EC8E4;
extern s16 D_801EC878;
extern s32 D_801EC86C;
void func_80147704(f32 *, f32 *, f32, f32 *);
void func_801488C0(Quat801488C0 *, f32 *, f32 *);
void func_801C565C(void *, f32, f32, f32, f32 *, f32 *, f32 *);
/* drawModelNode: sample this node's translation, scale and rotation keyframe
 * tracks at `time` (binary search, then lerp / quaternion slerp), push the node
 * matrix, emit its display list or mesh, place its sprites and attachment, then
 * recurse into the child (one hierarchy level deeper) and the sibling. */
void func_80143AFC(s32 node, f32 time, s32 passA, s32 passB)
{
  void func_801C61A0(f32 *, s32, s32, s32);
  s16 passA16;
  s16 passB16;
  void func_801C5F20(f32 *, s32, s32, s32);
  typedef struct 
  {
    Gfx *v;
  } GBox;
  typedef struct 
  {
    u8 pad[0x34];
    s32 child;
    s32 next;
  } Link;
  typedef struct 
  {
    u8 pad[0x18];
    s16 x;
    s16 y;
  } Spr;
  typedef u8 Bone[0x18];
  f32 q[4];
  f32 rot[16];
  f32 scale[16];
  f32 trans[16];
  f32 v[3];
  f32 tx;
  f32 ty;
  f32 tz;
  f32 sx;
  f32 sy;
  f32 sz;
  f32 frac;
  s16 prev;
  s16 next;
  s16 lo;
  s16 hi;
  s32 i;
  s32 range;
  s32 opacity;
  u8 *p;
  u8 *obj;
  next = -1;
  passA16 = (s16) passA;
  passB16 = (s16) passB;
  sz = (sx = (sy = D_8010609C));
  if ((D_801EC87C == 1) || (D_8026A144 == 0))
  {
    /* translation track */
    if ((*((s16 *) (((u8 *) node) + NODE_TRANS_KEY_COUNT))) >= 2)
    {
      prev = -1;
      hi = (*((s16 *) (((u8 *) node) + NODE_TRANS_KEY_COUNT))) - 1;
      lo = 0;
      while (lo <= hi)
      {
        i = (lo + hi) >> 1;
        if (((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_TRANS_KEYS)))[i][4])))) == time)
        {
          break;
        }
        if (time < ((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_TRANS_KEYS)))[i][4])))))
        {
          hi = i - 1;
        }
        else
        {
          lo = i + 1;
        }
      }

      if (lo > 0)
      {
        lo--;
      }
      for (i = lo; i < (*((s16 *) (((u8 *) node) + NODE_TRANS_KEY_COUNT))); i++)
      {
        if (time < ((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_TRANS_KEYS)))[i][4])))))
        {
          next = i;
          prev = i - 1;
          break;
        }
      }

      if (prev != (-1))
      {
        f32 d;
        range = (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_TRANS_KEYS)))[next][4]))) - (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_TRANS_KEYS)))[prev][4])));
        d = time - (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_TRANS_KEYS)))[prev][4])));
        frac = abs(range);
        frac = d / frac;
      }
      else
      {
        prev = (next = (*((s16 *) (((u8 *) node) + NODE_TRANS_KEY_COUNT))) - 1);
        frac = D_801060A0;
      }
      v[0] = (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (prev * 20)) + 0))) + (((*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (next * 20)) + 0))) - (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (prev * 20)) + 0)))) * frac);
      v[1] = (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (prev * 20)) + 4))) + (((*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (next * 20)) + 4))) - (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (prev * 20)) + 4)))) * frac);
      v[2] = (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (prev * 20)) + 8))) + (((*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (next * 20)) + 8))) - (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_TRANS_KEYS))) + (prev * 20)) + 8)))) * frac);
      tx = v[0];
      ty = v[1];
      tz = v[2];
    }
    else
    {
      tx = (*((f32 **) (((u8 *) node) + NODE_TRANS_KEYS)))[0];
      ty = (*((f32 **) (((u8 *) node) + NODE_TRANS_KEYS)))[1];
      tz = (*((f32 **) (((u8 *) node) + NODE_TRANS_KEYS)))[2];
    }
    {
      f64 dd = tz;
      tz = dd;
    }
    /* scale track */
    next = -1;
    if ((*((s16 *) (((u8 *) node) + NODE_SCALE_KEY_COUNT))) >= 2)
    {
      prev = -1;
      hi = (*((s16 *) (((u8 *) node) + NODE_SCALE_KEY_COUNT))) - 1;
      lo = 0;
      while (lo <= hi)
      {
        i = (lo + hi) >> 1;
        if (((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_SCALE_KEYS)))[i][4])))) == time)
        {
          break;
        }
        if (time < ((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_SCALE_KEYS)))[i][4])))))
        {
          hi = i - 1;
        }
        else
        {
          lo = i + 1;
        }
      }

      if (lo > 0)
      {
        lo--;
      }
      for (i = lo; i < (*((s16 *) (((u8 *) node) + NODE_SCALE_KEY_COUNT))); i++)
      {
        if (time < ((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_SCALE_KEYS)))[i][4])))))
        {
          next = i;
          prev = i - 1;
          break;
        }
      }

      if (prev != (-1))
      {
        f32 d;
        range = (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_SCALE_KEYS)))[next][4]))) - (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_SCALE_KEYS)))[prev][4])));
        d = time - (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_SCALE_KEYS)))[prev][4])));
        frac = abs(range);
        frac = d / frac;
      }
      else
      {
        prev = (next = (*((s16 *) (((u8 *) node) + NODE_SCALE_KEY_COUNT))) - 1);
        frac = D_801060A4;
      }
      v[0] = (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (prev * 20)) + 0))) + (((*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (next * 20)) + 0))) - (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (prev * 20)) + 0)))) * frac);
      v[1] = (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (prev * 20)) + 4))) + (((*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (next * 20)) + 4))) - (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (prev * 20)) + 4)))) * frac);
      v[2] = (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (prev * 20)) + 8))) + (((*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (next * 20)) + 8))) - (*((f32 *) (((*((u8 **) (((u8 *) node) + NODE_SCALE_KEYS))) + (prev * 20)) + 8)))) * frac);
      sx = v[0];
      sy = v[1];
      sz = v[2];
    }
    else
    {
      sx = (*((f32 **) (((u8 *) node) + NODE_SCALE_KEYS)))[0];
      sy = (*((f32 **) (((u8 *) node) + NODE_SCALE_KEYS)))[1];
      sz = (*((f32 **) (((u8 *) node) + NODE_SCALE_KEYS)))[2];
    }
    /* rotation track (quaternions) */
    if ((*((s16 *) (((u8 *) node) + NODE_ROT_KEY_COUNT))) >= 2)
    {
      if ((*((u16 *) (((u8 *) node) + NODE_FLAGS))) & NODE_FLAG_LOOP_ROTATION)
      {
        time = (D_802004E0 % 40) + 1;
      }
      next = -1;
      prev = -1;
      hi = (*((s16 *) (((u8 *) node) + NODE_ROT_KEY_COUNT))) - 1;
      lo = 0;
      while (lo <= hi)
      {
        i = (lo + hi) >> 1;
        if (((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_ROT_KEYS)))[i][4])))) == time)
        {
          break;
        }
        if (time < ((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_ROT_KEYS)))[i][4])))))
        {
          hi = i - 1;
        }
        else
        {
          lo = i + 1;
        }
      }

      if (lo > 0)
      {
        lo--;
      }
      for (i = lo; i < (*((s16 *) (((u8 *) node) + NODE_ROT_KEY_COUNT))); i++)
      {
        if (time < ((f32) (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_ROT_KEYS)))[i][4])))))
        {
          next = i;
          prev = i - 1;
          break;
        }
      }

      if (prev != (-1))
      {
        f32 d;
        range = (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_ROT_KEYS)))[next][4]))) - (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_ROT_KEYS)))[prev][4])));
        d = time - (*((s32 *) (&(*((f32 (**)[5]) (((u8 *) node) + NODE_ROT_KEYS)))[prev][4])));
        frac = abs(range);
        frac = d / frac;
      }
      else
      {
        prev = (next = (*((s16 *) (((u8 *) node) + NODE_ROT_KEY_COUNT))) - 1);
        frac = D_801060A8;
      }
      func_80147704((f32 *) ((*((u8 **) (((u8 *) node) + NODE_ROT_KEYS))) + (prev * 20)), (f32 *) ((*((u8 **) (((u8 *) node) + NODE_ROT_KEYS))) + (next * 20)), frac, q);
      func_801484F0(q, rot);
      if ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) && (*((u8 *) ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) + 0x21))))
      {
        obj = func_8017DBA0(*((u8 *) ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) + 0x21)));
        func_801488C0((Quat801488C0 *) (obj + 0x11C), (f32 *) (D_80269F38 + 0x9C), q);
      }
    }
    else
    {
      func_801484F0(*((f32 **) (((u8 *) node) + NODE_ROT_KEYS)), rot);
      if ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) && (*((u8 *) ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) + 0x21))))
      {
        obj = func_8017DBA0(*((u8 *) ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) + 0x21)));
        func_801488C0((Quat801488C0 *) (obj + 0x11C), (f32 *) (D_80269F38 + 0x9C), *((f32 **) (((u8 *) node) + NODE_ROT_KEYS)));
      }
    }
    /* node matrix: rotation with translation (scaled by object and parent scale), then scale */
    {
      f32 *objScale = &D_80263AB0;
      ((void (*)(f32 *, f32, f32, f32)) func_801C61A0)(trans, (tx * objScale[0]) * (&D_80269EC0)[D_801EC868 * 3], (ty * objScale[1]) * (&D_80269EC4)[D_801EC868 * 3], (tz * objScale[2]) * (&D_80269EC8)[D_801EC868 * 3]);
      {
        f32 a = trans[12];
        f32 b = trans[13];
        f32 c = trans[14];
        f32 d = trans[15];
        rot[12] = a;
        rot[13] = b;
        rot[14] = c;
        rot[15] = d;
      }
      func_80149834((s32 *) rot);
      ((void (*)(f32 *, f32, f32, f32)) func_801C5F20)(scale, sx * objScale[0], sy * objScale[1], sz * objScale[2]);
    }
    func_80149834((s32 *) scale);
  }
  /* render mode changes force a combiner/mode refresh */
  D_801EC8E4 = 0;
  if (!D_801EC7E4)
  {
    if ((*((u16 *) (((u8 *) node) + NODE_FLAGS))) & NODE_FLAG_ALT_RENDER_MODE)
    {
      if (!D_801EC7E2)
      {
        D_801EC7E2 = 1;
        D_801EC8E4 = 1;
      }
    }
    else
      if (D_801EC7E2 == 1)
    {
      D_801EC7E2 = 0;
      D_801EC8E4 = 1;
    }
    if ((*((u16 *) (((u8 *) node) + NODE_FLAGS))) & NODE_FLAG_ENV_EFFECT)
    {
      s32 alpha;
      if (!D_801EC7E3)
      {
        D_801EC7E3 = 1;
        D_801EC8E4 = 1;
      }
      if (!(*((s32 *) (((u8 *) node) + NODE_DISPLAY_LIST))))
      {
        D_801EC7E3 = 1;
      }
      frac = ((f32) ((s16) D_801EC87A)) / D_801060AC;
      frac *= *((u8 *) (((u8 *) node) + NODE_OPACITY));
      if (D_801060B0 < frac)
      {
        frac = D_801060B0;
      }
      alpha = frac;
      if (alpha != D_801EC878)
      {
        D_801EC8E4 = 1;
      }
      D_801EC878 = alpha;
    }
    else
      if (D_801EC7E3 == 1)
    {
      D_801EC7E3 = 0;
      D_801EC8E4 = 1;
    }
    if (D_801EC8E4)
    {
      func_8013A874();
    }
  }
  else
  {
    /* gDPSetPrimColor-style: white with the node's opacity */
    {
      Gfx *g = D_80202240;
      D_80202240 = g + 1;
      g->w0 = 0xFA000000;
      g->w1 = (*((u8 *) (((u8 *) node) + NODE_OPACITY))) | 0xFFFFFF00;
    }
  }
  /* store the modelview matrix (fresh, or reused from the object's cache) */
  if ((D_801EC87C == 1) || (!D_8026A144))
  {
    s32 o;
    func_80149940();
    func_801C5300(&D_80284D74, D_8025D0C0 + (o = (D_801EC86C * 64) + 0x80));
    if ((D_801EC87C == 1) && D_80263ABC)
    {
      func_801C5300(&D_80284D74, D_80263ABC);
    }
  }
  else
  {
    *((Blk142700 *) (D_8025D0C0 + ((D_801EC86C * 64) + 0x80))) = *((Blk142700 *) D_80263ABC);
  }
  /* gSPMatrix(push, load, modelview) */
  {
    Gfx *g = D_80202240;
    s32 o;
    D_80202240 = g + 1;
    g->w0 = 0x01040040;
    o = ((D_801EC86C++) * 64) + 0x80;
    g->w1 = (D_8025D0C0 + o) - 0x80000000;
  }
  D_801EC870++;
  if (*((s32 *) (((u8 *) node) + NODE_DISPLAY_LIST)))
  {
    /* gSPDisplayList */
    {
      Gfx *g = ((GBox *) (&D_80202240))->v;
      g->w0 = 0x06000000;
      g->w1 = *((s32 *) (((u8 *) node) + NODE_DISPLAY_LIST));
      D_80202240 = g + 1;
    }
  }
  else
    if (*(*((s16 **) (((u8 *) node) + NODE_MESH))))
  {
    /* gSPClearGeometryMode / gSPSetGeometryMode(G_LIGHTING), then draw the mesh */
    if ((*((u16 *) (((u8 *) node) + NODE_FLAGS))) & NODE_FLAG_ALT_MESH_DRAW)
    {
      if (!((*((u16 *) (((u8 *) node) + NODE_FLAGS))) & NODE_FLAG_NO_LIGHTING))
      {
        {
          Gfx *g = ((GBox *) (&D_80202240))->v;
          D_80202240 = g + 1;
          g->w0 = 0xB7000000;
          g->w1 = 0x20000;
        }
      }
      else
      {
        {
          Gfx *g = ((GBox *) (&D_80202240))->v;
          D_80202240 = g + 1;
          g->w0 = 0xB6000000;
          g->w1 = 0x20000;
        }
      }
      func_80153588((u8 *) node);
    }
    else
    {
      if (!((*((u16 *) (((u8 *) node) + NODE_FLAGS))) & NODE_FLAG_NO_LIGHTING))
      {
        {
          Gfx *g = ((GBox *) (&D_80202240))->v;
          D_80202240 = g + 1;
          g->w0 = 0xB7000000;
          g->w1 = 0x20000;
        }
      }
      else
      {
        {
          Gfx *g = ((GBox *) (&D_80202240))->v;
          D_80202240 = g + 1;
          g->w0 = 0xB6000000;
          g->w1 = 0x20000;
        }
      }
      func_801528E0((u8 *) node);
    }
  }
  /* sprites: size, opacity and world position from the current matrix */
  if ((*((s32 *) (((u8 *) node) + NODE_SPRITE_COUNT))) > 0)
  {
    i = 0;
    if (i < (*((s32 *) (((u8 *) node) + NODE_SPRITE_COUNT))))
    {
      f32 *objScale = &D_80263AB0;
      do
      {
        u8 *sprite = *((u8 **) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 4));
        if (sprite)
        {
          *((s16 *) (sprite + 0x18)) = ((*((s16 *) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 0xE))) * objScale[0]) * sx;
          (*((Spr **) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 4)))->y = ((*((s16 *) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 0x10))) * objScale[1]) * sy;
          opacity = ((*((u8 *) (((u8 *) node) + NODE_OPACITY))) * (*((s16 *) (D_80269F38 + 0x26)))) / 100;
          *((u8 *) ((*((u8 **) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 4))) + 0x20)) = (opacity < 256) ? (opacity) : (255);
          if (opacity >= 255)
          {
            (*((u8 **) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 4)))[0x21] &= 0xFE;
          }
          else
          {
            (*((u8 **) ((*((Bone **) (((u8 *) node) + NODE_SPRITES)))[i] + 4)))[0x21] |= 1;
          }
          {
            u8 *slots = *((u8 **) (((u8 *) node) + NODE_SPRITES));
            func_801C565C(&D_80284D74, (f32) (*((s16 *) (slots + 8))), (f32) (*((s16 *) (slots + 10))), (f32) (*((s16 *) (slots + 12))), &v[0], &v[1], &v[2]);
          }
          *((Vec3F *) (sprite + 0xC)) = *((Vec3F *) v);
        }
        i++;
      }
      while (i < (*((s32 *) (((u8 *) node) + NODE_SPRITE_COUNT))));
    }
  }
  /* attachment: keep previous and current world position, move the linked object */
  if (*((s32 *) (((u8 *) node) + NODE_ATTACHMENT)))
  {
    func_801C565C(&D_80284D74, 0.0f, 0.0f, 0.0f, &v[0], &v[1], &v[2]);
    p = *((u8 **) (((u8 *) node) + NODE_ATTACHMENT));
    *((Vec3F *) (p + 0xC)) = *((Vec3F *) p);
    *((Vec3F *) (*((u8 **) (((u8 *) node) + NODE_ATTACHMENT)))) = *((Vec3F *) v);
    if (*((u8 *) ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) + 0x20)))
    {
      obj = func_8017DBA0(*((u8 *) ((*((u8 **) (((u8 *) node) + NODE_ATTACHMENT))) + 0x20)));
      *((Vec3F *) (obj + 0xB4)) = *((Vec3F *) v);
    }
  }
  /* gSPPopMatrix */
  {
    Gfx *g = D_80202240;
    D_80202240 = g + 1;
    g->w0 = 0xBD000000;
    g->w1 = 0;
  }
  D_801EC870--;
  if ((D_801EC87C == 1) || (!D_8026A144))
  {
    func_801498CC();
    if (*((s32 *) (((u8 *) node) + NODE_CHILD)))
    {
      s32 depth = D_801EC868 + 1;
      (&D_80269EC0)[depth * 3] = sx;
      (&D_80269EC4)[depth * 3] = sy;
      (&D_80269EC8)[depth * 3] = sz;
      D_801EC868 = depth;
      func_80143AFC(((Link *) node)->child, time, passA16, passB16);
      D_801EC868--;
    }
    func_801498CC();
    if (*((s32 *) (((u8 *) node) + NODE_SIBLING)))
    {
      func_80143AFC(*((s32 *) (((u8 *) node) + NODE_SIBLING)), time, passA16, passB16);
    }
  }
}

/*
 * Scrolls a mesh's texture coordinates. For every triangle the UV step is
 * uScroll / vScroll scaled by the triangle's texel span over its world
 * span in X/Z (times the object's scale at +0xBC / +0xC4 when set); a
 * coordinate that passes 0x7FFF is wrapped back by one span.
 * Geometry at mesh +0x14: s16 triangle count, +4 vertices (12 bytes each),
 * +8 s16 vertex indices (3 per triangle), +0x10 u16 UVs (s,t per corner).
 */
void func_80144AF8(u8 *obj, f32 uScroll, f32 vScroll) {
    u8 *mesh = *(u8 **)(*(u8 **)(obj + 0xC8) + 0xC);
    u16 *triUV;
    u16 *uv;
    f32 *vtx[3];
    u16 sSpan, tSpan;
    s32 span, extentX, extentZ;
    f32 d;
    s32 tri, j;
    s32 sStep, tStep;
    s32 tWrapped;

    uv = *(u16 **)(*(u8 **)(mesh + 0x14) + 0x10);
    if (uv != 0) {
        triUV = uv;
        for (tri = 0; tri < **(s16 **)(mesh + 0x14); tri++) {
            vtx[0] = (f32 *)(*(u8 **)(*(u8 **)(mesh + 0x14) + 4) + (*(s16 **)(*(u8 **)(mesh + 0x14) + 8))[tri * 3] * 12);
            vtx[1] = (f32 *)(*(u8 **)(*(u8 **)(mesh + 0x14) + 4) + (*(s16 **)(*(u8 **)(mesh + 0x14) + 8))[tri * 3 + 1] * 12);
            vtx[2] = (f32 *)(*(u8 **)(*(u8 **)(mesh + 0x14) + 4) + (*(s16 **)(*(u8 **)(mesh + 0x14) + 8))[tri * 3 + 2] * 12);
            /* Largest texel span from corner 0 in s and in t. */
            sSpan = abs(triUV[0] - triUV[2]);
            span = abs(triUV[0] - triUV[4]);
            if ((u16)span > sSpan) sSpan = span;
            tSpan = abs(triUV[1] - triUV[3]);
            span = abs(triUV[1] - triUV[5]);
            if ((u16)span > tSpan) tSpan = span;
            triUV += 6;
            /* Largest world extent from vertex 0 in X and in Z. */
            d = vtx[0][0] - vtx[1][0];
            extentX = (0 < d) ? (s32)d : (s32)-d;
            d = vtx[0][0] - vtx[2][0];
            sStep = (0 < d) ? (s32)d : (s32)-d;
            if (extentX < sStep) extentX = sStep;
            d = vtx[0][2] - vtx[1][2];
            extentZ = (0 < d) ? (s32)d : (s32)-d;
            d = vtx[0][2] - vtx[2][2];
            tStep = (0 < d) ? (s32)d : (s32)-d;
            if (extentZ < tStep) extentZ = tStep;
            if (*(f32 *)(obj + 0xBC) != 0) extentX = extentX * *(f32 *)(obj + 0xBC);
            if (*(f32 *)(obj + 0xC4) != 0) extentZ = extentZ * *(f32 *)(obj + 0xC4);
            if (extentZ != 0) sStep = uScroll * sSpan / extentZ;
            if (extentX != 0) tStep = vScroll * tSpan / extentX;
            /* extentX is reused from here on as the "s wrapped" flag. */
            extentX = 0;
            tWrapped = 0;
            for (j = 0; j < 3; uv += 2, j++) {
                if ((u16)(uv[0] += sStep) > 0x7FFF) extentX = 1;
                if ((u16)(uv[1] += tStep) > 0x7FFF) tWrapped = 1;
            }
            if (extentX) {
                if (sStep > 0) {
                    for (j = 1; j < 4; j++) uv[-2 * j] -= sSpan;
                } else {
                    for (j = 1; j < 4; j++) uv[-2 * j] += sSpan;
                }
            }
            if (tWrapped) {
                if (tStep > 0) {
                    for (j = 1; j < 4; j++) uv[-2 * j + 1] -= tSpan;
                } else {
                    for (j = 1; j < 4; j++) uv[-2 * j + 1] += tSpan;
                }
            }
        }
    }
}

void func_80144F0C(u8 *model) {
    /* Distort each triangle corner's UVs with cumulative drift or waves from saved UVs. */
    extern const f32 D_801060B4, D_801060B8, D_801060BC, D_801060C0, D_801060C4, D_801060D0;
    extern const f64 D_801060C8;
    extern f32 D_801EC8E8, D_801EC8EC;
    extern s32 D_801EC8F0;
    extern s32 D_802004E0;
    f32 func_80149724(f32, f32, s32);
    u16 *texCoord = ((ModelNodeRelocView *)model)->mesh->texCoords;
    u16 *sourceCoord = ((ModelNodeRelocView *)model)->mesh->savedTexCoords;
    s32 triangleIndex;
    s32 cornerIndex;
    f32 *position;
    f32 animatedCoord;
    u32 coordBits;
    s32 drift;
    s16 (*triangles)[MODEL_TRIANGLE_VERTICES];

    if (D_801EC8F0 == 0) {
        for (triangleIndex = 0; triangleIndex < ((ModelNodeRelocView *)model)->mesh->triangleCount; triangleIndex++) {
            for (cornerIndex = 0, sourceCoord = texCoord + 1; cornerIndex < MODEL_TRIANGLE_VERTICES; cornerIndex++, texCoord += MODEL_TEXCOORD_COMPONENTS, sourceCoord += MODEL_TEXCOORD_COMPONENTS) {
                triangles = ((ModelNodeRelocView *)model)->mesh->triangles;
                position = (f32 *)((u8 *)((ModelNodeRelocView *)model)->mesh->positions +
                            triangles[triangleIndex][cornerIndex] * MODEL_POSITION_BYTES);

                drift = (s32)(func_80149724(D_801060B4, (f32)(s16)(s32)(position[0] + position[1] + position[2]), D_802004E0) * D_801060B8);
                texCoord[0] += drift;
                drift = (s32)(func_80149724(D_801060B4, (f32)((s16)(s32)(position[0] + position[1] + position[2]) / 2), D_802004E0) * D_801060B8);
                sourceCoord[0] += drift;
            }
        }
    } else {
        for (triangleIndex = 0; triangleIndex < ((ModelNodeRelocView *)model)->mesh->triangleCount; triangleIndex++) {
            for (cornerIndex = 0; cornerIndex < MODEL_TRIANGLE_VERTICES; texCoord += MODEL_TEXCOORD_COMPONENTS, cornerIndex++, sourceCoord += MODEL_TEXCOORD_COMPONENTS) {
                triangles = ((ModelNodeRelocView *)model)->mesh->triangles;
                position = (f32 *)((u8 *)((ModelNodeRelocView *)model)->mesh->positions +
                            triangles[triangleIndex][cornerIndex] * MODEL_POSITION_BYTES);
                animatedCoord = sourceCoord[0] + func_80149724(D_801060C4, (position[0] + position[2]) / D_801EC8E8, D_802004E0) * D_801060BC;
                if (!(animatedCoord >= D_801060C0)) { coordBits = (s32)animatedCoord; } else { coordBits = (s32)(animatedCoord - D_801060C0); coordBits |= 0x80000000; }
                texCoord[0] = coordBits;
                animatedCoord = sourceCoord[1] + func_80149724(D_801060D0, (position[0] + position[2]) / D_801EC8EC + D_801060C8, D_802004E0) * D_801060BC;
                if (!(animatedCoord >= D_801060C0)) { coordBits = (s32)animatedCoord; } else { coordBits = (s32)(animatedCoord - D_801060C0); coordBits |= 0x80000000; }
                texCoord[1] = coordBits;
            }
        }
    }
}

/* Return whether an object is within draw distance: its squared camera distance
 * is below (bounding radius + the global draw margin D_801EC7DA)^2. */
s32 func_80145258(u8 *object) {
    u8 unusedStack[0x40];
    f32 reach;

    reach = *(f32 *)(object + OBJECT_BOUNDING_RADIUS) + (f32)D_801EC7DA;
    reach = reach * reach;
    if (reach < *(f32 *)(object + OBJECT_CAMERA_DISTANCE_SQUARED)) {
        return 0;
    }
    return 1;
}

extern const f32 D_801060D4, D_801060D8;
void func_80145298(u8 *track, f32 frame, s16 startFrame, s16 endFrame, f32 frameOffset) {
    /* Sample animation tracks and convert the player orientation to its world basis. */
    extern u8 D_80290374;
    void func_801C61A0(f32 *, f32, f32, f32);
    void func_801C5B90(f32 *, f32, f32, f32, f32);
    int abs(int);
    f32 quaternion[4], rotation[16], basisRotation[16], translationMatrix[16], translation[3];
    f32 translationX, translationY, translationZ, fraction;
    f32 sampleFrame = frame + frameOffset;
    s16 previousKey = ANIM_KEY_NOT_FOUND, nextKey = ANIM_KEY_NOT_FOUND;
    s32 keyIndex;

    if ((f32)endFrame < sampleFrame) sampleFrame = startFrame;
    if (*(s16 *)(track + ANIM_TRANSLATION_KEY_COUNT) >= ANIM_INTERPOLATION_MIN_KEYS) {
        for (keyIndex = 0; keyIndex < *(s16 *)(track + ANIM_TRANSLATION_KEY_COUNT); keyIndex++) {
            if (sampleFrame < (f32)(*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[keyIndex].frame) {
                nextKey = keyIndex; previousKey = keyIndex - 1; break;
            }
        }
        if (previousKey != ANIM_KEY_NOT_FOUND) {
            fraction = abs((*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[nextKey].frame - (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].frame);
            fraction = (sampleFrame - (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].frame) / fraction;
        } else {
            previousKey = nextKey = *(s16 *)(track + ANIM_TRANSLATION_KEY_COUNT) - 1;
            fraction = D_801060D4;
        }
        translation[0] = (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].components[0] + ((*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[nextKey].components[0] - (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].components[0]) * fraction;
        translation[1] = (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].components[1] + ((*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[nextKey].components[1] - (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].components[1]) * fraction;
        translation[2] = (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].components[2] + ((*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[nextKey].components[2] - (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))[previousKey].components[2]) * fraction;
        translationX = translation[0]; translationY = translation[1]; translationZ = translation[2];
    } else {
        translationX = (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))->components[0];
        translationY = (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))->components[1];
        translationZ = (*(AnimationTransformKey **)(track + ANIM_TRANSLATION_KEYS))->components[2];
    }
    nextKey = ANIM_KEY_NOT_FOUND;
    if (*(s16 *)(track + ANIM_ROTATION_KEY_COUNT) >= ANIM_INTERPOLATION_MIN_KEYS) {
        previousKey = ANIM_KEY_NOT_FOUND;
        for (keyIndex = 0; keyIndex < *(s16 *)(track + ANIM_ROTATION_KEY_COUNT); keyIndex++) {
            if (sampleFrame < (f32)(*(AnimationTransformKey **)(track + ANIM_ROTATION_KEYS))[keyIndex].frame) {
                nextKey = keyIndex; previousKey = keyIndex - 1; break;
            }
        }
        if (previousKey != ANIM_KEY_NOT_FOUND) {
            fraction = abs((*(AnimationTransformKey **)(track + ANIM_ROTATION_KEYS))[nextKey].frame - (*(AnimationTransformKey **)(track + ANIM_ROTATION_KEYS))[previousKey].frame);
            fraction = (sampleFrame - (*(AnimationTransformKey **)(track + ANIM_ROTATION_KEYS))[previousKey].frame) / fraction;
        } else {
            previousKey = nextKey = *(s16 *)(track + ANIM_ROTATION_KEY_COUNT) - 1;
            fraction = D_801060D8;
        }
        func_80147704((f32 *)(*(AnimationTransformKey **)(track + ANIM_ROTATION_KEYS) + previousKey), (f32 *)(*(AnimationTransformKey **)(track + ANIM_ROTATION_KEYS) + nextKey), fraction, quaternion);
        func_801484F0(quaternion, rotation);
    } else func_801484F0(*(f32 **)(track + ANIM_ROTATION_KEYS), rotation);
    func_801C61A0(translationMatrix, translationX * *(const f64 *)((const u8 *)&D_801060D8 + 4),
                  translationY * *(const f64 *)((const u8 *)&D_801060D8 + 4),
                  translationZ * *(const f64 *)((const u8 *)&D_801060D8 + 4));
    func_801C5B90(basisRotation, 180.0f, 0.0f, 1.0f, 0.0f);
    func_801C5580(rotation, basisRotation, rotation);
    func_801C5580(basisRotation, rotation, rotation);
    func_80148654(rotation, (f32 *)&D_80290374);
}

/* Original compiler padding. */
const u32 D_80145674_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000600, 0x00003E01
};

#endif /* TEMP bisect */
