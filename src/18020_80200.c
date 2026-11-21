#include "common.h"
#include "structs.h"
#include "math_types.h"
#include "effect_visuals.h"

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

#if 1 /* TEMP bisect */
extern s32 D_80000300;
extern s16 D_801E753C;
extern u8 D_801FFC98[];
extern u8 D_801FFE60[];
extern s16 D_8028D80E;
extern s32 D_80290424;
extern s32 D_80296C30;
void func_8014D4D0(void);
void func_801C0B70();
void func_801C6550(void *, s32, void *, s32, void *, s32);
void func_801C7860(void *);
s32 func_801C7430(void *, void *, s32);
void func_801D211C();

/* Re-register the scheduler's retrace event so it fires once every retraceCount vertical retraces (osViSetEvent). */
void func_8017F200(SchedulerContext *scheduler, u8 retraceCount) {
    func_801CEE00((u8 *)scheduler + SCHED_EVENT_QUEUE, SCHED_EVENT_RETRACE, retraceCount);
}

void func_8017FAF4(u8 *, s32);
void func_801C7980(void *);
void func_801CF020(f32);
extern const f32 D_80108984;
extern const f32 D_80108988;
extern s32 D_801EC7C8;
extern u8 D_801EFC90;
extern u8 D_801EFC91;
extern u8 D_801EFC92;
extern u8 D_801EFC94[];
extern u16 D_801EFC98[];
extern u8 D_801F4790[][0x50];
extern u8 D_801F47B8[][0x50];
extern u8 D_80200168[];
extern u8 D_80202060[];
extern u8 D_8025CF00[];
extern u8 D_80292C10;
extern u8 D_80292C18[];
extern s32 D_80294C30;
void func_8017F6D0(u8 *);
void func_8017FB70(u8 *);
void func_8017FD8C(u8 *);

/* Initialize scheduler queues and video timing, then start the event, audio-task, and graphics-task threads. */
void func_8017F25C(SchedulerContext *scheduler, u8 viModeIndex, u8 retraceCount) {
    u8 palField[SCHED_VI_FIELD_BYTES];
    s16 verticalStart = SCHED_PAL_VSTART;
    s16 verticalEnd = SCHED_PAL_VEND;
    f32 verticalScale = D_80108984;

    scheduler->graphicsTask = 0;
    scheduler->audioTask = 0;
    scheduler->waitingGraphicsTask = 0;
    scheduler->clients = 0;
    scheduler->firstFrame = 1;
    scheduler->retraceMessageType = SCHED_CLIENT_RETRACE;
    scheduler->preNmiMessageType = SCHED_CLIENT_PRE_NMI;

    func_801C6520((OSMesgQueue *)((u8 *)scheduler + SCHED_EVENT_QUEUE), (void **)((u8 *)scheduler + SCHED_EVENT_MESSAGES), SCHED_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)((u8 *)scheduler + SCHED_SP_QUEUE), (void **)((u8 *)scheduler + SCHED_SP_MESSAGES), SCHED_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)((u8 *)scheduler + SCHED_DP_QUEUE), (void **)((u8 *)scheduler + SCHED_DP_MESSAGES), SCHED_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)((u8 *)scheduler + SCHED_GRAPHICS_QUEUE), (void **)((u8 *)scheduler + SCHED_GRAPHICS_MESSAGES), SCHED_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)((u8 *)scheduler + SCHED_AUDIO_QUEUE), (void **)((u8 *)scheduler + SCHED_AUDIO_MESSAGES), SCHED_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)((u8 *)scheduler + SCHED_RESUME_QUEUE), (void **)((u8 *)scheduler + SCHED_RESUME_MESSAGES), SCHED_QUEUE_CAPACITY);

    func_801CEAA0(SCHED_VI_MANAGER_PRIORITY);
    func_801CEE60(D_801F4790[viModeIndex]);
    func_801CF3B0(1);

    if (D_80000300 == SCHED_TV_PAL) {
        func_801D211C(palField, D_801F47B8[viModeIndex], SCHED_VI_FIELD_BYTES);
        func_801D211C(D_80292C18, D_801F47B8[viModeIndex], SCHED_VI_FIELD_BYTES);
        *(s32 *)&palField[SCHED_VI_VSTART_OFFSET] = (verticalStart << 16) + verticalEnd;
        func_801D211C(D_801F47B8[viModeIndex], palField, SCHED_VI_FIELD_BYTES);
        func_801CF020(verticalScale);
        D_80292C10 = viModeIndex;
    }

    func_801CEE00((u8 *)scheduler + SCHED_EVENT_QUEUE, SCHED_EVENT_RETRACE, retraceCount);
    func_801C7690(SCHED_OS_EVENT_SP, (u8 *)scheduler + SCHED_SP_QUEUE, SCHED_EVENT_SP_DONE);
    func_801C7690(SCHED_OS_EVENT_DP, (u8 *)scheduler + SCHED_DP_QUEUE, SCHED_EVENT_DP_DONE);
    func_801C7690(SCHED_OS_EVENT_PRE_NMI, (u8 *)scheduler + SCHED_EVENT_QUEUE, SCHED_EVENT_PRE_NMI);

    func_801C6550((u8 *)scheduler + SCHED_EVENT_THREAD, SCHED_EVENT_THREAD_ID, func_8017F6D0, (s32)scheduler, &D_80296C30, SCHED_EVENT_PRIORITY);
    func_801C7860((u8 *)scheduler + SCHED_EVENT_THREAD);
    func_801C6550((u8 *)scheduler + SCHED_AUDIO_THREAD, SCHED_AUDIO_THREAD_ID, func_8017FB70, (s32)scheduler, &D_80294C30, SCHED_AUDIO_PRIORITY);
    func_801C7860((u8 *)scheduler + SCHED_AUDIO_THREAD);
    func_801C6550((u8 *)scheduler + SCHED_GRAPHICS_THREAD, SCHED_GRAPHICS_THREAD_ID, func_8017FD8C, (s32)scheduler, &D_80292C10, SCHED_GRAPHICS_PRIORITY);
    func_801C7860((u8 *)scheduler + SCHED_GRAPHICS_THREAD);
}

#pragma GCC optimize "O0"
/* scheduler_get_audio_queue: returns the address of the scheduler's audio task queue. */
s32 func_8017F660(s32 scheduler) {
    return scheduler + SCHED_AUDIO_QUEUE;
}
/* scheduler_get_graphics_queue: returns the address of the scheduler's graphics task queue. */
s32 func_8017F698(s32 scheduler) {
    return scheduler + SCHED_GRAPHICS_QUEUE;
}

/* scheduler_event_thread: broadcast retraces and fade out, stop threads, and restore PAL timing before reset. */
void func_8017F6D0(u8 *scheduler) {
    s32 eventMessage = 0;

    while (1) {
        func_801C7430(scheduler + SCHED_EVENT_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
        switch (eventMessage) {
        case SCHED_EVENT_RETRACE:
            D_801EFC98[SCHED_PACED_COUNTER]++;
            D_801EFC98[SCHED_REGULAR_COUNTER]++;
            if ((s16)D_801EFC98[SCHED_PACED_COUNTER] >= D_801EFC91 && D_801EC7C8 == 0) {
                D_801EFC91 = D_801EFC92;
                D_801EFC98[SCHED_PACED_COUNTER] = 0;
                func_8017FAF4(scheduler, (s32)D_801EFC94);
            } else if (D_801EC7C8 != 0 && (s16)D_801EFC98[SCHED_PACED_COUNTER] >= D_801EFC91) {
                D_801EFC98[SCHED_PACED_COUNTER] = D_801EFC91 - 1;
            }
            if ((s16)D_801EFC98[SCHED_REGULAR_COUNTER] >= SCHED_REGULAR_RETRACE_INTERVAL) {
                D_801EFC98[SCHED_REGULAR_COUNTER] = 0;
                func_8017FAF4(scheduler, (s32)scheduler);
            }
            if (D_801EFC90 != 0) {
                D_801EFC90--;
                if (D_801EFC90 < SCHED_RESET_FORCE_TRANSITION_BELOW) {
                    D_8028D80E = 0xFF;
                    D_801E753C = SCHED_RESET_TRANSITION_EXTENT;
                }
                if (D_801EFC90 == 0) {
                    func_801C7980(D_801FFC98);
                    func_801C7980(D_8025CF00);
                    func_801C7980(D_80202060);
                    func_801C7980(D_80200168);
                    if (D_80000300 == SCHED_TV_PAL) {
                        func_801D211C(D_801F47B8[D_80292C10], D_80292C18, SCHED_VI_FIELD_BYTES);
                        func_801CF020(D_80108988);
                    }
                }
            }
            break;
        case SCHED_EVENT_PRE_NMI:
            func_8017FAF4(scheduler, (s32)(scheduler + SCHED_PRE_NMI_MESSAGE_OFFSET));
            func_801C0B70(D_80290424, SCHED_RESET_AUDIO_FADE);
            D_801EFC90 = SCHED_RESET_RETRACES;
            func_8014D4D0();
            break;
        }
    }
}

/* Adds a client to the front of the scheduler's client list, with interrupts
 * masked; its message queue then receives every scheduler event. */
void func_8017F9A4(u8 *scheduler, u8 *client, u8 *queue) {
    s32 savedMask;

    savedMask = func_801C63D0(OS_IM_NONE);
    ((SchedulerClient *)client)->queue = (OSMesgQueue *)queue;
    ((SchedulerClient *)client)->next = (SchedulerClient *)((SchedulerContext *)scheduler)->clients;
    ((SchedulerContext *)scheduler)->clients = (s32)client;
    func_801C63D0(savedMask);
}

s32 func_801C63D0(s32);
void func_8017FA1C(u8 *scheduler, s32 *client) {
    typedef struct { u8 pad0[0x668]; s32 clientList; } SchedClients;
    s32 cur;
    s32 prev;
    s32 savedMask;

    /* Unlink a client from the scheduler's client list, with interrupts masked. */
    cur = ((SchedClients *)scheduler)->clientList;
    prev = 0;
    savedMask = func_801C63D0(1);
    while (cur != 0) {
        if (cur == (s32)client) {
            if (prev != 0) {
                *(s32 *)prev = *client;
            } else {
                ((SchedClients *)scheduler)->clientList = *client;
            }
            break;
        }
        prev = cur;
        cur = *(s32 *)cur;
    }
    func_801C63D0(savedMask);
}

/* Sends `message` without blocking (osSendMesg, func_801C7560) to every message
 * queue on the listener list at offset 0x668 of `owner`. */
void func_8017FAF4(u8 *owner, s32 message) {
    struct QueueNode { struct QueueNode *next; u8 *queue; } *node;
    struct QueueOwner { u8 pad[0x668]; struct QueueNode *listeners; };

    node = ((struct QueueOwner *)owner)->listeners;
    while (node != NULL) {
        func_801C7560(node->queue, message, 0);
        node = node->next;
    }
}

/* Run queued audio RSP tasks, yielding graphics work and resuming it afterward. */
void func_8017FB70(u8 *scheduler) {
    s32 func_801C7430(void *, void *, s32);
    void func_801C64F0(void);
    void func_801CE890(void);
    s32 func_801CE8B0(void *);
    void func_801804A0(s32, void *);
    void func_801CE4F0(void *);
    void func_801CE6FC(void *);
    void func_80180534(s32);
    void func_801C7560(void *, void *, s32);
    extern u8 D_8010898C[];
    void *eventMessage = NULL;
    void *audioTask = NULL;
    void *graphicsTask = NULL;
    s32 graphicsState = SCHED_GRAPHICS_IDLE;

    while (1) {
        func_801C7430(scheduler + SCHED_AUDIO_QUEUE, &audioTask, SCHED_MESSAGE_BLOCK);
        func_801C64F0();
        graphicsState = SCHED_GRAPHICS_IDLE;
        graphicsTask = (void *)((SchedulerContext *)scheduler)->graphicsTask;
        if (graphicsTask != NULL) {
            func_801CE890();
            func_801C7430(scheduler + SCHED_SP_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
            if (func_801CE8B0((u8 *)graphicsTask + SCHED_TASK_STORAGE_OFFSET)) {
                graphicsState = SCHED_GRAPHICS_YIELDED;
            } else {
                graphicsState = SCHED_GRAPHICS_FINISHED;
            }
        }
        func_801804A0(SCHED_PROFILE_AUDIO_RSP, D_8010898C);
        ((SchedulerContext *)scheduler)->audioTask = (s32)audioTask;
        func_801CE4F0((u8 *)audioTask + SCHED_TASK_STORAGE_OFFSET);
        func_801CE6FC((u8 *)audioTask + SCHED_TASK_STORAGE_OFFSET);
        func_801C7430(scheduler + SCHED_SP_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
        ((SchedulerContext *)scheduler)->audioTask = (s32)NULL;
        func_80180534(SCHED_PROFILE_AUDIO_RSP);
        if (((SchedulerContext *)scheduler)->waitingGraphicsTask) {
            func_801C7560(scheduler + SCHED_RESUME_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
        }
        if (graphicsState == SCHED_GRAPHICS_YIELDED) {
            func_801CE4F0((u8 *)graphicsTask + SCHED_TASK_STORAGE_OFFSET);
            func_801CE6FC((u8 *)graphicsTask + SCHED_TASK_STORAGE_OFFSET);
        } else if (graphicsState == SCHED_GRAPHICS_FINISHED) {
            func_801C7560(scheduler + SCHED_SP_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
        }
        func_801C7560(((SchedulerTaskMessage *)audioTask)->completionQueue, ((SchedulerTaskMessage *)audioTask)->completionMessage, SCHED_MESSAGE_BLOCK);
    }
}

void func_8017FD8C(u8 *scheduler) {
    /* Run graphics tasks after audio, wait for RSP/RDP completion, and present frames. */
    s32 func_801C7430(void *, void *, s32);
    void func_8017FF5C(u8 *, void *);
    void func_801804A0(s32, void *);
    void func_80180534(s32);
    void func_801CE4F0(void *);
    void func_801CE6FC(void *);
    void func_801CF3B0(s32);
    void func_801CF070(void *);
    void func_801C7560(void *, void *, s32);
    extern u8 D_80108994[], D_80108998[];
    void *eventMessage = NULL;
    void *graphicsTask;

    while (1) {
        func_801C7430(scheduler + SCHED_GRAPHICS_QUEUE, &graphicsTask, SCHED_MESSAGE_BLOCK);
        func_8017FF5C(scheduler, graphicsTask);
        if (((SchedulerContext *)scheduler)->audioTask) {
            ((SchedulerContext *)scheduler)->waitingGraphicsTask = (s32)graphicsTask;
            func_801C7430(scheduler + SCHED_RESUME_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
            ((SchedulerContext *)scheduler)->waitingGraphicsTask = (s32)NULL;
        }
        ((SchedulerContext *)scheduler)->graphicsTask = (s32)graphicsTask;
        func_801CE4F0((u8 *)graphicsTask + SCHED_TASK_STORAGE_OFFSET);
        func_801CE6FC((u8 *)graphicsTask + SCHED_TASK_STORAGE_OFFSET);
        func_801804A0(SCHED_PROFILE_GRAPHICS_RSP, D_80108994);
        func_801804A0(SCHED_PROFILE_GRAPHICS_RDP, D_80108998);
        func_801C7430(scheduler + SCHED_SP_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
        ((SchedulerContext *)scheduler)->graphicsTask = (s32)NULL;
        func_80180534(SCHED_PROFILE_GRAPHICS_RSP);
        func_801C7430(scheduler + SCHED_DP_QUEUE, &eventMessage, SCHED_MESSAGE_BLOCK);
        func_80180534(SCHED_PROFILE_GRAPHICS_RDP);
        if (((SchedulerContext *)scheduler)->firstFrame) {
            func_801CF3B0(0);
            ((SchedulerContext *)scheduler)->firstFrame = (s32)NULL;
        }
        if (((SchedulerTaskMessage *)graphicsTask)->flags & SCHED_TASK_SWAP_FRAMEBUFFER) {
            func_801CF070(((SchedulerTaskMessage *)graphicsTask)->framebuffer);
        }
        func_801C7560(((SchedulerTaskMessage *)graphicsTask)->completionQueue, ((SchedulerTaskMessage *)graphicsTask)->completionMessage, SCHED_MESSAGE_BLOCK);
    }
}

/* scheduler_wait_framebuffer_available: while the task's framebuffer is still
 * the current or next VI buffer (osViGetCurrentFramebuffer / osViGetNextFramebuffer),
 * register a temporary client on the scheduler's resume queue, wait for one
 * retrace message (osRecvMesg, blocking) and unregister it again. */
void func_8017FF5C(u8 *scheduler, u8 *task) {
    s32 message;
    SchedulerClient client;
    s32 framebuffer;

    message = 0;
    framebuffer = (s32)((SchedulerTaskMessage *)task)->framebuffer;
    while (func_801CE910() == framebuffer || func_801CEA60() == framebuffer) {
        func_8017F9A4(scheduler, (u8 *)&client, scheduler + SCHED_RESUME_QUEUE);
        func_801C7430(scheduler + SCHED_RESUME_QUEUE, &message, OS_MESG_BLOCK);
        func_8017FA1C(scheduler, (u8 *)&client);
    }
}

void func_801C6520(OSMesgQueue *, void **, s32);
void func_801C77C0(void *, u64, u64, OSMesgQueue *, s32);
extern u64 D_801F43D0;
extern u16 D_801EFC9C[];
/* Broadcast paced and regular scheduler messages from periodic timer ticks. */
void func_80180024(u8 *schedulerArg) {
    OSMesgQueue messageQueue;
    void *messageSlots[SCHED_QUEUE_CAPACITY];
    u8 schedulerClient[SCHED_CLIENT_BYTES];
    u8 timerStorage[SCHED_TIMER_BYTES];
    s32 message = 0;
    u8 *scheduler = schedulerArg;
    register u8 *timer;

    func_801C6520(&messageQueue, messageSlots, SCHED_QUEUE_CAPACITY);
    func_8017F9A4(D_801FFE60, schedulerClient, (u8 *)&messageQueue);
    timer = timerStorage;
    func_801C77C0(timer, 0ULL, D_801F43D0 * (u64)SCHED_TIMER_PERIOD_USEC / (u64)SCHED_MICROSECONDS_PER_SECOND, &messageQueue, SCHED_TIMER_MESSAGE);

    while (1) {
        func_801C7430(&messageQueue, &message, SCHED_MESSAGE_BLOCK);
        if (message == SCHED_TIMER_MESSAGE) {
            D_801EFC9C[SCHED_PACED_COUNTER]++;
            D_801EFC9C[SCHED_REGULAR_COUNTER]++;
            if ((s16)D_801EFC9C[SCHED_PACED_COUNTER] >= D_801EFC91 && D_801EC7C8 == 0) {
                D_801EFC91 = D_801EFC92;
                D_801EFC9C[SCHED_PACED_COUNTER] = 0;
                func_8017FAF4(scheduler, (s32)D_801EFC94);
            } else if (D_801EC7C8 != 0 && (s16)D_801EFC9C[SCHED_PACED_COUNTER] >= D_801EFC91) {
                D_801EFC9C[SCHED_PACED_COUNTER] = D_801EFC91 - 1;
            }
            if ((s16)D_801EFC9C[SCHED_REGULAR_COUNTER] >= SCHED_REGULAR_RETRACE_INTERVAL) {
                D_801EFC9C[SCHED_REGULAR_COUNTER] = 0;
                func_8017FAF4(scheduler, (s32)scheduler);
            }
        }
    }
}

/* Original compiler padding. */
const u32 D_801802D8_padding[] __attribute__((section(".text"))) = {
    0x20202020, 0x37323920
};

#endif /* TEMP bisect */
