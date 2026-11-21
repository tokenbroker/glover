#include "common.h"
#include "structs.h"

extern s16 D_8029012E;
extern f32 D_8029F9D4, D_8029F9D8, D_8029F9DC, D_8029F9E0, D_8029F9E4;
void func_8016A058(void);

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
extern u8 *D_802903A4;
typedef struct { u8 *unk0; u8 *unk4; u8 *unk8; u8 *unkC; u8 *unk10; } ObjPtrBlk;
extern s16 D_801EFD44;
extern s32 D_801EFCE8;
extern u8 *D_801EFCF0;
#include "effect_visuals.h"
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
typedef PlatformUpdateState Obj8017CF00;
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
extern volatile s8 D_801E7533;
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


void func_80139C40(void);

u32 func_80139CA0(u8 *arg0);

u32 func_80139D14(u8 *arg0, s32 arg1);


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






















/* Confine the object inside a sphere, cancelling outward velocity and adding inward correction. */
void func_80155B90(u8 *object, f32 *sphereCenter, f32 sphereRadius) {
    f32 inwardDirection[3];
    f32 centerDistance;
    f32 inwardSpeed;

    inwardDirection[0] = sphereCenter[0] - *(f32 *)(object + ACTOR_POSITION);
    inwardDirection[1] = sphereCenter[1] - *(f32 *)(object + ACTOR_POSITION_Y);
    inwardDirection[2] = sphereCenter[2] - *(f32 *)(object + ACTOR_POSITION_Z);
    centerDistance = sqrtf(inwardDirection[0] * inwardDirection[0] + inwardDirection[1] * inwardDirection[1] + inwardDirection[2] * inwardDirection[2]);
    if (centerDistance != 0.0f) {
        inwardDirection[0] *= D_80106EC4 / centerDistance;
        inwardDirection[1] *= D_80106EC4 / centerDistance;
        inwardDirection[2] *= D_80106EC4 / centerDistance;
        if (sphereRadius - *(f32 *)(object + OBJECT_CONTAINMENT_RADIUS) < centerDistance) {
            if (*(f32 *)(object + ACTOR_POSITION_Y) < sphereCenter[1]) {
                *(u8 *)(*(s32 *)(object + ACTOR_MODEL_STATE) + ACTOR_MODEL_CONTACT_COUNT) = 1;
            }
            func_80148D0C((f32 *)(object + ACTOR_POSITION), inwardDirection, centerDistance + *(f32 *)(object + OBJECT_CONTAINMENT_RADIUS) - sphereRadius);
            inwardSpeed = *(f32 *)(object + OBJECT_VELOCITY_X) * inwardDirection[0] + *(f32 *)(object + OBJECT_VELOCITY_Y) * inwardDirection[1] + *(f32 *)(object + OBJECT_VELOCITY_Z) * inwardDirection[2];
            if (inwardSpeed < 0.0f) {
                func_80148D0C((f32 *)(object + OBJECT_VELOCITY_X), inwardDirection, -inwardSpeed);
            }
            func_80148D0C((f32 *)(object + OBJECT_VELOCITY_X), inwardDirection, centerDistance + *(f32 *)(object + OBJECT_CONTAINMENT_RADIUS) - sphereRadius);
        }
    }
}

void func_80155D54(u8 *actor) { /* Collides actor with every other solid object in the object list: bounding-sphere test, then per collision-sphere overlap, contact flags/events, and an elastic impulse plus separation push. */
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define FL964(i) F(s32,D_80299964,({ s32 o_ = (i) * 768; o_; }))
extern const f32 D_80106EC8;
extern const f32 D_80106ECC;
extern const f32 D_80106ED0;
extern const f32 D_80106EDC;
extern const f64 D_80106EE0;
extern const f32 D_80106EE8;
extern const f32 D_80106EEC;
extern const f32 D_80106EF0;
extern const f32 D_80106EF4;
extern const f64 D_80106EF8;
extern const f64 D_80106F00;
extern const f32 D_80106F08;
extern const f32 D_80106F10;
extern const f32 D_80106F1C;
extern const f64 D_80106F20;
extern const f64 D_80106F28;
extern f32 D_801ED680;
extern s32 D_801ED690;
extern s32 D_801ED694;
extern s32 D_801ED6F0;
extern s32 D_801ED6F4;
extern s16 D_8029010A;
extern u8 D_80299964[];
extern s32 D_8029F574;
void func_801743A8(s32 arg0, s16 arg1);
void func_80195D50();
void func_80196610(u8 *);
void func_801AEC14(void);
void func_801B0DDC(void);
void func_801B10B8(u8 *, f32 *, f32, f32);
f32 delta[3];
f32 negDelta[3];
f32 relVel[3];
f32 actorImpulse[3];
f32 otherImpulse[3];
f32 actorSpherePos[3];
f32 otherSpherePos[3];
f32 actorSphereOffset[3];
f32 otherSphereOffset[3];
s32 deathMode;
ObjectNode *other;
f32 boundSum;
f32 impulse;
f32 actorVelY;
f32 otherVelY;
f32 actorPush;
f32 otherPush;
f32 dx2;
f32 distSq2;
f32 _10;
f32 z2;
f32 relSpeedSq;
f32 relSpeedSq2;
f32 scaledVelX;
f32 massSum;
f32 radiusSum;
f32 dz;
f32 y2;
f32 dy2;
f32 _19;
f32 invDist;
f32 dx;
f32 dz2;
f32 dy;
f32 sdz;
f32 sdy;
f32 x2;
f32 _27;
f32 dist2;
f32 relSpeed;
f32 dist;
s32 respond;
f32 relSpeed2;
f64 _33;
f64 _34;
f32 actorPushLen;
f32 otherPushLen;
s32 playerOffset;
s32 _38;
s32 playerFlags;
s32 otherFlags;
s32 otherFlags2;
s32 actorFlags;
s32 actorFlags2;
s32 isCandidate;
s32 otherSphereOfs;
s32 noPush;
s32 actorSphereOfs;
s32 _48;
s32 otherPlayer;
s32 actorPlayer;
s32 enemyPlayer;
s8 actorPlayer2;
s8 otherPlayer3;
s8 actorPlayer3;
s8 otherPlayer4;
s8 actorPlayer4;
s8 otherPlayer2;
s32 player;
u16 sphereFlags;
u32 j;
u32 i;
void *otherColl;
void *otherSphere;
void *otherSpheres;
void *otherColl2;
void *actorColl3;
void *otherColl3;
void *actorColl2;
void *otherColl4;
void *actorColl4;
void *otherColl5;
void *actorSpheres;
void *otherSpheres2;
void *enemyColl;
s32 slot;
respond = 1;
if ((F(f32,F(s32,actor,208),0) != 0.0f) && (other = D_8026A148.next, (other != &D_8026A148))) {
do {
isCandidate = 0;
if ((F(s32,other,40) & 8) && (F(f32,F(s32,other,208),0) != 0.0f) && ((other->type != 0) & (other != actor))) {
otherColl2 = F(s32,other,212);
isCandidate = 1;
if ((otherColl2 != NULL) && (F(s32,otherColl2,12) != 0)) {
if ((((actor == &D_802902D8) && (other == &D_8029F978)) || ((actor == &D_8029F978) && (other == &D_802902D8))) && (func_80148E48(&D_8029030C, &D_8029F9AC) <= (D_80290308 + F(f32,D_8029FA50,112)))) {
D_8029010A = 1;
}
goto block_211;
}
if ((F(s32,other,44) != actor) && (other != F(s32,actor,44))) {
goto block_16;
}
goto block_211;
}
block_16:
if (isCandidate != 0) {
dx = F(f32,actor,52) - F(f32,other,52);
delta[0] = dx;
dy = F(f32,actor,56) - F(f32,other,56);
delta[1] = dy;
dz = F(f32,actor,60) - F(f32,other,60);
delta[2] = dz;
boundSum = F(f32,actor,48) + F(f32,other,48);
if (!((boundSum * boundSum) < ((dx * dx) + (dy * dy) + (dz * dz)))) {
for (i = 0; i < F(u8,F(s32,actor,216),395); i++) {
actorSphereOfs = i * 0x24;
_48 = 0;
if (((other != &D_8029F978) || !(F(u16,(F(s32,actor,216) + actorSphereOfs),122) & 2)) && ((other != &D_802902D8) || ((F(u16,(F(s32,actor,216) + actorSphereOfs),122) & 1) == 0))) {
_48 = i * 2;
_38 = (_48 + i) * 4;
*(Vec3F *)actorSpherePos = *(Vec3F *)((u8 *)D_801ED6EC + _38);
*(Vec3F *)actorSphereOffset = *(Vec3F *)((u8 *)D_801ED68C + _38);
for (j = 0; j < F(u8,F(s32,other,216),395); j++) {
otherSphereOfs = j * 0x24;
noPush = 0;
if (((actor != &D_8029F978) || !(F(u16,(F(s32,other,216) + otherSphereOfs),122) & 2)) && ((actor != &D_802902D8) || !(F(u16,(F(s32,other,216) + otherSphereOfs),122) & 1))) {
if (F(u16,(F(s32,actor,216) + actorSphereOfs),122) & 8) {
noPush = 1;
}
otherSpheres = F(s32,other,216);
otherSphere = otherSpheres + otherSphereOfs;
sphereFlags = F(u16,otherSphere,122);
if (sphereFlags & 8) {
noPush = 1;
}
if (sphereFlags & 0x10) {
do { *(Vec3F *)otherSpherePos = *(Vec3F *)((u8 *)otherSphere + 88); } while (0);
otherSphereOffset[0] = otherSpherePos[0] - F(f32,other,52);
otherSphereOffset[1] = otherSpherePos[1] - F(f32,other,56);
otherSphereOffset[2] = otherSpherePos[2] - F(f32,other,60);
} else if (sphereFlags & 0x20) {
otherSphereOffset[0] = otherSphereOffset[1] = otherSphereOffset[2] = 0.0f;
do { *(Vec3F *)otherSpherePos = *(Vec3F *)((u8 *)other + 52); } while (0);
} else {
func_801499A0(otherSphereOffset, otherSpheres + (otherSphereOfs + 0x58), (f32 *)((u8 *)other + 0x9C));
otherSpherePos[0] = F(f32,other,52) + otherSphereOffset[0];
otherSpherePos[1] = F(f32,other,56) + otherSphereOffset[1];
otherSpherePos[2] = F(f32,other,60) + otherSphereOffset[2];
}
dx2 = actorSpherePos[0] - otherSpherePos[0];
sdy = actorSpherePos[1] - otherSpherePos[1];
sdz = actorSpherePos[2] - otherSpherePos[2];
radiusSum = F(f32,(F(s32,actor,216) + actorSphereOfs),112); radiusSum += F(f32,(F(s32,other,216) + otherSphereOfs),112);
delta[0] = dx2;
delta[1] = sdy;
delta[2] = sdz;
dist = sqrtf((dx2 * dx2) + (sdy * sdy) + (sdz * sdz));
if (dist <= radiusSum) { { f64 d = radiusSum; radiusSum = d; }
if ((radiusSum / D_80106EC8) <= (F(f32,actor,116) + F(f32,other,116))) {
((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)((f32 *)(actor + 0x34), (f32 *)(actor + 0x40), (f32 *)(actor + 0x58), 0.5f);
x2 = F(f32,actor,52) + actorSphereOffset[0];
actorSpherePos[0] = x2;
y2 = F(f32,actor,56) + actorSphereOffset[1];
_27 = x2 - otherSpherePos[0];
actorSpherePos[1] = y2;
_19 = y2 - otherSpherePos[1];
z2 = F(f32,actor,60) + actorSphereOffset[2];
dz2 = z2 - otherSpherePos[2];
distSq2 = (_27 * _27) + (_19 * _19) + (dz2 * dz2);
delta[0] = _27;
delta[1] = _19;
actorSpherePos[2] = z2;
delta[2] = dz2;
dist2 = sqrtf(distSq2);
dist = dist2;
}
otherColl = F(s32,other,212);
F(u8,otherColl,0) = F(u8,otherColl,0) - F(u8,F(s32,actor,212),1);
actorSpheres = F(s32,actor,216);
F(u8,actorSpheres,394) = F(u8,actorSpheres,394) | 8;
otherSpheres2 = F(s32,other,216);
F(u8,otherSpheres2,394) = F(u8,otherSpheres2,394) | 8;
if (F(s32,actor,40) & 0x80) {
F(s16,actor,36) = 1;
}
if (F(s32,other,40) & 0x80) {
F(s16,other,36) = 1;
}
if (F(s16,D_802903AC,4) == 0x12) {
player = -1;
if (actor == &D_802902D8) {
otherPlayer = F(s8,F(s32,other,212),2);
if (otherPlayer != -1) {
player = otherPlayer;
} else { if (other != &D_8029F978) goto block_62; goto block_61; }
} else if (other == &D_802902D8) {
actorPlayer = F(s8,F(s32,actor,212),2);
if (actorPlayer != -1) {
player = actorPlayer;
} else if (actor == &D_8029F978) {
block_61:
{ s32 *p = &D_8029F574; *p |= 8; }
if (D_8029F46C != 0) {
enemyColl = F(s32,D_8029F46C,212);
if (enemyColl != NULL) {
enemyPlayer = F(s8,enemyColl,2);
if (enemyPlayer != player) {
s32 o_ = enemyPlayer * 768;
F(s32,D_80299964,o_) = F(s32,D_80299964,o_) | 8;
}
}
}
}
}
block_62:
if (player != -1) {
playerOffset = player * 0x300;
if (F(s8,D_8029970A + playerOffset,0) != 2) {
playerFlags = F(s32,D_80299964,playerOffset) | 8;
F(s32,D_80299964,playerOffset) = playerFlags;
if (!(playerFlags & 0x20)) {
func_80196610(playerOffset + D_802996E8);
}
if ((F(s32,D_80299964,playerOffset) & 1) || (F(s16,&D_802999A0,playerOffset) != 0)) {
playerOffset += (s32)D_802996E8; func_80195D50(playerOffset);
return;
}
goto block_73;
}
}
goto block_73;
}
block_73:
if (noPush == 0) {
if ((actor == &D_802902D8) && (F(s32,other,40) & 0x80000) && ((otherColl4 = F(s32,other,212), (otherColl4 == NULL)) || (otherPlayer3 = F(s8,otherColl4,2), (otherPlayer3 == -1)) || (!(FL964(otherPlayer3) & 0x400) && ((s16)D_8029999C[otherPlayer3][0] == 0)))) {
deathMode = 0;
if ((F(s32,other,40) < 0) && (F(u8,D_802903B0,392) != 0)) {
deathMode = 3;
if (F(f32,other,92) < -D_801ED680) {
} else {
goto block_93;
}
}
goto block_94;
}
if ((other == &D_802902D8) && (F(s32,actor,40) & 0x80000) && ((actorColl4 = F(s32,actor,212), (actorColl4 == NULL)) || (actorPlayer3 = F(s8,actorColl4,2), (actorPlayer3 == -1)) || (!(FL964(actorPlayer3) & 0x400) && ((s16)D_8029999C[actorPlayer3][0] == 0)))) {
deathMode = 0;
if ((F(s32,actor,40) < 0) && (F(u8,D_802903B0,392) != 0)) {
deathMode = 3;
if (!(F(f32,actor,92) < -D_801ED680)) {
block_93:
deathMode = 0;
}
}
block_94:
func_801743A8(deathMode, -1);
return;
}
if ((F(s16,D_802903AC,4) != 0x12) && ((F(s16,D_802903AC,6) != 0x12) || (D_8028FBEA >= 6))) {
if ((actor == &D_802902D8) && (F(s32,other,40) & 0x20000)) {
otherColl5 = F(s32,other,212);
if (otherColl5 != NULL) {
otherPlayer4 = F(s8,otherColl5,2);
if (otherPlayer4 != -1) {
if ((FL964(otherPlayer4) & 0x400) || ((s16)D_8029999C[otherPlayer4][0] != 0)) {
goto block_104;
}
goto block_111;
}
}
goto block_110;
}
block_104:
if ((other == &D_802902D8) && (F(s32,actor,40) & 0x20000) && ((actorColl3 = F(s32,actor,212), (actorColl3 == NULL)) || (actorPlayer4 = F(s8,actorColl3,2), (actorPlayer4 == -1)) || (!(FL964(actorPlayer4) & 0x400) && ((s16)D_8029999C[actorPlayer4][0] == 0)))) {
block_110:
block_111:
func_801743A8(0, 1);
return;
}
goto block_112;
}
goto block_112;
}
block_112:
if (F(s16,actor,32) == 2) {
F(s32,other,40) |= 0x04000000;
if (noPush == 0) {
if ((D_801E7531 == 0x28) && (F(s8,F(s32,other,212),0) == 1)) {
F(s16,actor,36) = 1;
func_801AA8D4(actor);
}
otherColl3 = F(s32,other,212);
if ((otherColl3 == NULL) || (otherPlayer2 = F(s8,otherColl3,2), (otherPlayer2 == -1)) || ((s16)D_8029999C[otherPlayer2][0] == 0)) {
otherFlags = F(s32,other,40);
if (!(otherFlags & 0x100000)) {
if (otherFlags & 0x40000) {
func_801AEC14();
}
if (F(s32,other,40) & 0x080A0000) {
if (func_8015C4C8() != 0) {
otherFlags2 = F(s32,other,40);
if (otherFlags2 & 0x80000) {
func_801743A8(0, -1);
} else if (otherFlags2 & 0x20000) {
func_801743A8(0, 1);
} else {
func_80167604(9);
}
}
if ((other->type == 8) && (F(f32,other,116) > D_80106ECC)) {
slot = F(s8,F(s32,other,212),2);
goto block_155;
}
}
goto block_156;
}
goto block_142;
}
goto block_156;
}
goto block_156;
}
if (other->type == 2) {
F(s32,actor,40) = F(s32,actor,40) | 0x04000000;
if (noPush == 0) {
if ((D_801E7531 == 0x28) && (F(s8,F(s32,actor,212),0) == 1)) {
F(s16,other,36) = 1;
func_801AA8D4(other);
}
actorColl2 = F(s32,actor,212);
if ((actorColl2 == NULL) || (actorPlayer2 = F(s8,actorColl2,2), (actorPlayer2 == -1)) || ((s16)D_8029999C[actorPlayer2][0] == 0)) {
actorFlags = F(s32,actor,40);
if (actorFlags & 0x100000) {
block_142:
func_801B0DDC();
return;
}
if (actorFlags & 0x40000) {
func_801AEC14();
}
if (F(s32,actor,40) & 0x080A0000) {
if (func_8015C4C8() != 0) {
actorFlags2 = F(s32,actor,40);
if (actorFlags2 & 0x80000) {
func_801743A8(0, -1);
} else if (actorFlags2 & 0x20000) {
func_801743A8(0, 1);
} else {
func_80167604(9);
}
}
if ((F(s16,actor,32) == 8) && (F(f32,actor,116) > D_80106ED0)) {
slot = F(s8,F(s32,actor,212),2);
block_155:
D_8029999C[slot][0] = 0x32;
}
}
goto block_156;
}
goto block_156;
}
}
block_156:
if (actor == &D_802902D8) {
F(s32,other,40) |= 0x40000000;
} else if (other == &D_802902D8) {
F(s32,actor,40) = F(s32,actor,40) | 0x40000000;
}
if (respond != 0) {
if (other->type == 0x1D) {
if ((actor == &D_8029F978) || (actor == &D_802902D8)) {
if (F(f32,other,92) < (-D_801ED680 * F(f64,&D_80106ED0,4))) {
F(f32,actor,88) = F(f32,actor,92) = F(f32,actor,96) = 0.0f;
F(f32,actor,88) = F(f32,actor,52) - F(f32,other,52);
F(f32,actor,92) = F(f32,actor,56) - F(f32,other,56);
F(f32,actor,96) = F(f32,actor,60) - F(f32,other,60);
F(f32,actor,88) = F(f32,actor,88) * D_80106EDC;
F(f32,actor,92) = F(f32,actor,92) * D_80106EDC;
F(f32,actor,96) = F(f32,actor,96) * D_80106EDC;
F(f32,actor,92) = 2.0f * -F(f32,other,92);
}
}
}
if (((actor == &D_8029F978) && (other == &D_802902D8)) || ((actor == &D_802902D8) && (other == &D_8029F978))) {
D_8029010A = 1;
}
massSum = F(f32,F(s32,actor,208),0) + F(f32,F(s32,other,208),0);
{ f64 d = massSum; massSum = d; }
{ f64 d = dist; dist = d; }
if (dist < D_80106EE0) {
dist = D_80106EE8;
}
invDist = D_80106EEC / dist;
delta[0] *= invDist;
delta[1] *= invDist;
delta[2] *= invDist;
relVel[0] = F(f32,actor,88) - F(f32,other,88);
relVel[1] = F(f32,actor,92) - F(f32,other,92);
relVel[2] = F(f32,actor,96) - F(f32,other,96);
*(Vec3F *)otherImpulse = *(Vec3F *)delta;
if (F(f32,F(s32,actor,208),48) != 0.0f) {
relSpeedSq = (relVel[0] * relVel[0]) + (relVel[1] * relVel[1]) + (relVel[2] * relVel[2]);
relSpeed = sqrtf(relSpeedSq);
func_801B10B8(actor, delta, (relSpeed * F(f32,F(s32,other,208),0)) / D_80106EF0, F(f32,F(s32,actor,208),48));
}
if (F(f32,F(s32,other,208),48) != 0.0f) {
relSpeedSq2 = (relVel[0] * relVel[0]) + (relVel[1] * relVel[1]) + (relVel[2] * relVel[2]);
negDelta[0] = -delta[0];
negDelta[1] = -delta[1];
negDelta[2] = -delta[2];
relSpeed2 = sqrtf(relSpeedSq2);
func_801B10B8(other, negDelta, (relSpeed2 * F(f32,F(s32,actor,208),0)) / D_80106EF4, F(f32,F(s32,other,208),48));
}
impulse = (2.0f * F(f32,F(s32,actor,208),0) * ((otherImpulse[0] * relVel[0]) + (otherImpulse[1] * relVel[1]) + (otherImpulse[2] * relVel[2]))) / massSum;
scaledVelX = otherImpulse[0] * impulse;
otherImpulse[0] = scaledVelX;
otherImpulse[1] *= impulse;
otherImpulse[2] *= impulse;
((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(actorImpulse, relVel, otherImpulse, -F(f32,F(s32,other,208),0) / F(f32,F(s32,actor,208),0));
if (other->type == 4) {
actorImpulse[0] *= 2.0f;
actorImpulse[1] *= 2.0f;
actorImpulse[2] *= 2.0f;
if (F(s32,other,40) & 0x80) {
F(s32,other,44) = actor;
}
}
if (F(s16,actor,32) == 4) {
otherImpulse[0] *= 2.0f;
otherImpulse[1] *= 2.0f;
otherImpulse[2] *= 2.0f;
if (F(s32,actor,40) & 0x80) {
F(s32,actor,44) = other;
}
}
F(f32,actor,88) = actorImpulse[0] + F(f32,other,88);
F(f32,actor,92) = actorImpulse[1] + F(f32,other,92);
F(f32,actor,96) = actorImpulse[2] + F(f32,other,96);
F(f32,other,88) = otherImpulse[0] + F(f32,other,88);
F(f32,other,92) = otherImpulse[1] + F(f32,other,92);
F(f32,other,96) = otherImpulse[2] + F(f32,other,96);
if (F(u8,F(s32,actor,216),392) != 0) {
actorVelY = F(f32,actor,92);
if (actorVelY < 0.0f) {
F(f32,actor,92) = actorVelY * D_80106EF8;
}
}
if (F(u8,F(s32,other,216),392) != 0) {
otherVelY = F(f32,other,92);
if (otherVelY < 0.0f) {
F(f32,other,92) = otherVelY * D_80106F00;
}
}
if (!(F(s32,actor,40) & 0x80) && !(F(s32,other,40) & 0x80)) {
if (F(f32,F(s32,actor,208),0) != D_80106F08) {
actorPush = ((radiusSum - dist) * F(f32,F(s32,other,208),0)) / massSum;
if (actorPush > 0.0f) {
actorPushLen = actorPush + F(f64,&D_80106F08,4);
} else {
actorPushLen = actorPush - F(f64,&D_80106F10,4);
}
func_80148D0C(actor + 0x34, delta, actorPushLen);
}
if (F(f32,F(s32,other,208),0) != D_80106F1C) {
otherPush = ((dist - radiusSum) * F(f32,F(s32,actor,208),0)) / massSum;
if (otherPush > 0.0f) {
otherPushLen = otherPush + D_80106F20;
} else {
otherPushLen = otherPush - D_80106F28;
}
func_80148D0C((f32 *)((u8 *)other + 0x34), delta, otherPushLen);
}
}
}
if (F(s8,F(s32,other,212),0) < 0) {
F(s32,other,40) |= 2;
}
}
}
}
}
}
}
}
block_211:
other = other->next;
} while (other != &D_8026A148);
}
}

/* Transform mesh vertices, return their radius, and optionally prepare world-space collision. */
f32 func_801570AC(u8 *mesh, f32 *position, u8 *triangleData, f32 *scale, f32 *orientation, s32 prepareCollision) {
    void func_80147094(f32 *, f32 *, f32 *);
    void func_8015BA6C(f32 *);
    void func_8015739C(s16, u8 *, s32);
    f32 sqrtf(f32);
    f32 edge01[4];
    f32 edge02[4];
    f32 rotation[16];
    f32 radius;
    s32 triangleIndex;
    s32 vertexIndex;
    f32 *triangle;

    func_801484F0(orientation, rotation);
    radius = 0.0f;
    for (triangleIndex = 0; triangleIndex < *(s16 *)mesh; triangleIndex++) {
        triangle = (f32 *)(triangleData + triangleIndex * COLLISION_TRIANGLE_BYTES);
        for (vertexIndex = 0; vertexIndex < COLLISION_TRIANGLE_VERTEX_COUNT; vertexIndex++) {
            u8 *indices = (u8 *)(triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_INDICES));
            s32 sourceIndex = *(s16 *)(indices + vertexIndex * 2);
            f32 *vertex = (f32 *)(sourceIndex * COLLISION_VERTEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_VERTICES));
            f32 scaledX = scale[0] * vertex[0];
            f32 scaledY = scale[1] * vertex[1];
            f32 scaledZ = scale[2] * vertex[2];
            f32 distance;
            triangle[TRI_VERTEX0_X + vertexIndex * 3] = rotation[0] * scaledX + rotation[4] * scaledY + rotation[8] * scaledZ;
            triangle[TRI_VERTEX0_Y + vertexIndex * 3] = rotation[1] * scaledX + rotation[5] * scaledY + rotation[9] * scaledZ;
            triangle[TRI_VERTEX0_Z + vertexIndex * 3] = rotation[2] * scaledX + rotation[6] * scaledY + rotation[10] * scaledZ;
            distance = sqrtf(triangle[TRI_VERTEX0_X + vertexIndex * 3] * triangle[TRI_VERTEX0_X + vertexIndex * 3] + triangle[TRI_VERTEX0_Y + vertexIndex * 3] * triangle[TRI_VERTEX0_Y + vertexIndex * 3] + triangle[TRI_VERTEX0_Z + vertexIndex * 3] * triangle[TRI_VERTEX0_Z + vertexIndex * 3]);
            if (radius < distance) {
                radius = distance;
            }
        }
        if (prepareCollision != 0) {
            edge01[0] = triangle[TRI_VERTEX1_X] - triangle[TRI_VERTEX0_X];
            edge01[1] = triangle[TRI_VERTEX1_X + 1] - triangle[TRI_VERTEX0_Y];
            edge01[2] = triangle[TRI_VERTEX1_X + 2] - triangle[TRI_VERTEX0_Z];
            edge02[0] = triangle[TRI_VERTEX2_X] - triangle[TRI_VERTEX0_X];
            edge02[1] = triangle[TRI_VERTEX2_X + 1] - triangle[TRI_VERTEX0_Y];
            edge02[2] = triangle[TRI_VERTEX2_X + 2] - triangle[TRI_VERTEX0_Z];
            func_80147094(triangle, edge01, edge02);
            func_80149568(triangle);
            for (vertexIndex = 0; vertexIndex < COLLISION_TRIANGLE_VERTEX_COUNT; vertexIndex++) {
                triangle[TRI_VERTEX0_X + vertexIndex * 3] += position[0];
                triangle[TRI_VERTEX0_Y + vertexIndex * 3] += position[1];
                triangle[TRI_VERTEX0_Z + vertexIndex * 3] += position[2];
            }
            func_8015BA6C(triangle);
        }
    }
    if (prepareCollision != 0) {
        for (triangleIndex = 0; triangleIndex < *(s16 *)mesh; triangleIndex++) {
            func_8015739C(*(s16 *)mesh, triangleData, triangleIndex);
        }
    }
    return radius;
}

/* Disable all edges of degenerate triangles and shared edges of coplanar triangles. */
void func_8015739C(u32 triangleCount, u8 *triangleData, u32 triangleIndex)
{
  int nextVertex;
  extern CollisionEdgeLookup D_80106F30;
  extern const f32 D_80106F3C;
  extern const f64 D_80106F40;
  extern const f32 D_80106F48;
  CollisionEdgeLookup edgeLookup = D_80106F30;
  CollisionTriangle *triangle = (CollisionTriangle *) (triangleData + (triangleIndex * COLLISION_TRIANGLE_BYTES));
  u32 otherIndex;
  u32 vertexIndex;
  u32 otherStartVertex;
  u32 otherEndVertex;
  s32 outsidePlane;
  f32 planeDistance;
  f64 minVertexSeparation = *((f64 *) (((u8 *) (&D_80106F30)) + 4));
  if (((func_80148E48(triangle->vertices[0], triangle->vertices[1]) < minVertexSeparation) || (func_80148E48(triangle->vertices[0], triangle->vertices[2]) < minVertexSeparation)) || (func_80148E48(triangle->vertices[2], triangle->vertices[1]) < minVertexSeparation))
  {
    triangle->edgeLengths[0] = (triangle->edgeLengths[1] = (triangle->edgeLengths[2] = D_80106F3C));
    return;
  }
  for (otherIndex = triangleIndex + 1; otherIndex < triangleCount; otherIndex++)
  {
    outsidePlane = 0;
 for (vertexIndex = 0; vertexIndex < COLLISION_TRIANGLE_VERTEX_COUNT; vertexIndex++) { CollisionTriangle *otherTriangle = (CollisionTriangle *) (triangleData + (otherIndex * COLLISION_TRIANGLE_BYTES)); planeDistance = (((otherTriangle->vertices[vertexIndex][0] * triangle->normal[0]) + (otherTriangle->vertices[vertexIndex][1] * triangle->normal[1])) + (otherTriangle->vertices[vertexIndex][2] * triangle->normal[2])) + triangle->planeDistance; if (!(planeDistance > 0.0f)) { do { planeDistance = -planeDistance; } while (0); } if (planeDistance > D_80106F40) { outsidePlane = 1; } } if (outsidePlane != 1) { for (vertexIndex = 0; vertexIndex < COLLISION_TRIANGLE_VERTEX_COUNT; vertexIndex++) { for (otherStartVertex = 0; otherStartVertex < COLLISION_TRIANGLE_VERTEX_COUNT; otherStartVertex++) { if (func_80148E48((f32 *) (((u8 *) triangle) + ((vertexIndex * COLLISION_VERTEX_BYTES) + COLLISION_TRIANGLE_VERTICES_OFFSET)), ((CollisionTriangle *) (triangleData + (otherIndex * COLLISION_TRIANGLE_BYTES)))->vertices[otherStartVertex]) < D_80106F40) { nextVertex = (vertexIndex + 1) % COLLISION_TRIANGLE_VERTEX_COUNT;
            for (otherEndVertex = 0; otherEndVertex < COLLISION_TRIANGLE_VERTEX_COUNT; otherEndVertex++)
            {
              if (func_80148E48((f32 *) (((u8 *) triangle) + ((s32) ((nextVertex * COLLISION_VERTEX_BYTES) + COLLISION_TRIANGLE_VERTICES_OFFSET))), ((CollisionTriangle *) (triangleData + (otherIndex * COLLISION_TRIANGLE_BYTES)))->vertices[otherEndVertex]) < D_80106F40)
              {
                triangle->edgeLengths[vertexIndex] = D_80106F48;
                ((CollisionTriangle *) (triangleData + (otherIndex * COLLISION_TRIANGLE_BYTES)))->edgeLengths[edgeLookup.edgeIndex[(otherStartVertex + otherEndVertex) - 1]] = D_80106F48;
              }
            }

          }
        }

      }

    }
  }

}

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

/* Collides a moving body against every other body (D_8026A058 list) and every actor (D_802904D4 list),
 * plays an impact sound scaled by the deepest contact, then rebuilds its velocity from the contact
 * planes (bounce/slide), clamps horizontal speed, and pushes it out of planes it still penetrates. */
void func_80157708(void *body) {
    extern Body157708 D_8026A058;
    extern u8 D_80106F4C[];
    extern const f32 D_80106F78;
    extern const f32 D_80106F7C;
    extern const f32 D_80106F80;
    extern const s32 D_80106FA0;
    extern const f32 D_80106FA8;
    extern const f32 D_80106FB0;
    extern const f32 D_80106FB8;
    extern const f32 D_80106FC0;
    extern const f32 D_80106FCC;
    extern const f32 D_80106FD0;
    extern const f32 D_80106FD8;
    extern const f64 D_80106FE0;
    extern const f64 D_80106FE8;
    extern const f64 D_80106FF0;
    extern const f32 D_80106FF8;
    extern const f32 D_80107000;
    extern const f32 D_80107008;
    extern const f32 D_80107010;
    extern const f32 D_80107018;
    extern const f32 D_80107020;
    extern f32 D_801ED680;
    extern u8 D_801ED684;
    extern f32 D_801ED688;
    extern s32 D_801ED8D4;
    extern s32 D_801ED8D8;
    extern s32 D_801ED8DC;
    extern s32 D_801ED8E0;
    extern u8 D_801EEB60;
    extern s32 D_8028F880;
    extern s32 D_8028F890;
    extern f32 *D_8028F89C;
    extern f32 D_8028F8A0;
    extern f32 D_8028F8B0;
    extern f32 D_8028F8B4;
    extern f32 D_8028F8B8;
    extern f32 *D_8028F8BC;
    extern f32 D_8028F8C0;
    extern f32 D_8028F8C4;
    extern s32 D_8028F8C8;
    extern s32 D_8028FCEC;
    extern f32 D_8029F9B0;
    extern f32 D_8029F9B4;
    extern f32 D_8029F9D4;
    extern f32 D_8029F9D8;
    f32 sqrtf(f32);
    s32 func_80147000(s32);
    void func_80149568(f32 *);
    void func_8015CC70(f32 *, f32 *);
    s32 func_80158F84(u8 *, f32 *, void *);
    f32 func_80158DC4(f32 *, f32 *, f32, f32 *);
    s32 func_80178134(s16, f32 *, s16, s16);
    void func_8017D7B8(u8 *);
    Body157708 *self = body;
    f32 startVelY = self->vel.y;
    u32 j;
    u32 i;
    s32 flag;
    s32 hitFlags;
    f32 impact;
    f32 len;
    f32 reachSq;
    f32 rad;
    u8 idx;
    Body157708 *other;
    Actor157708 *actor;
    f32 *plane;
    Vec3F *dir;
    Vec3F hit;
    Vec3F moved;
    Vec3F away;
    Vec3F v;
    Vec3F center;

    D_801ED8E0 = 0;
    D_801ED8D8 = 0;
    D_801ED8D4 = 0;
    D_8028F89C = NULL;
    ((Vec3F *)&D_8028F8C8)->x = ((Vec3F *)&D_8028F8C8)->y = ((Vec3F *)&D_8028F8C8)->z = D_8028F8C0 = 0.0f;
    D_8028F8B0 = D_8028F8B4 = D_8028F8B8 = 0.0f;
    *(Vec3F *)&D_8028F8A0 = self->pos;
    D_8028F8C4 = sqrtf(self->vel.x * self->vel.x + self->vel.z * self->vel.z);
    for (j = 0; j < 4; j++) {
        ((f32 **)&D_8028F880)[j] = self->coll->plane[j];
        self->coll->plane[j] = NULL;
    }
    if (self == (Body157708 *)D_8028F8E0 || self == (Body157708 *)&D_8028FCEC) {
        D_801ED684 = 1;
    } else {
        D_801ED684 = 0;
    }

    for (other = D_8026A058.next; other != &D_8026A058; other = other->next) {
        if (other == self) {
            continue;
        }
        reachSq = self->radius + other->radius;
        reachSq = reachSq * reachSq;
        if (self == (Body157708 *)D_8028F8E0 && (other->flags & 0x20000000)) {
            continue;
        }
        if (reachSq < func_80148EBC(&self->pos.x, (s32)&other->pos.x)) {
            continue;
        }
        for (i = 0; i < *other->mesh->data->count; i++) {
            hitFlags = func_80158F84((u8 *)self, (f32 *)(other->tris + i * 0x78), NULL);
            if (hitFlags & 1) {
                return;
            }
            if (hitFlags & 2) {
                goto respond;
            }
            if (hitFlags & 4) {
                other->unk26 = 0xD2;
            }
        }
    }

    for (actor = (Actor157708 *)D_802904D4.next; actor != (Actor157708 *)&D_802904D4; actor = actor->next) {
        if (actor->flags & 0x84) {
            continue;
        }
        if (self == (Body157708 *)D_8028F8E0 && (actor->body.flags & 0x20000000)) {
            continue;
        }
        v.x = self->pos.x - actor->body.pos.x;
        v.y = self->pos.y - actor->body.pos.y;
        v.z = self->pos.z - actor->body.pos.z;
        if ((self->radius + actor->body.radius) * (self->radius + actor->body.radius) < v.x * v.x + v.y * v.y + v.z * v.z) {
            continue;
        }
        if (actor->unk6E < D_802004E0) {
            func_8017D7B8((u8 *)actor);
        }
        for (i = 0; i < *actor->body.mesh->data->count; i++) {
            hitFlags = func_80158F84((u8 *)self, (f32 *)(actor->body.tris + i * 0x78), actor);
            if (hitFlags & 1) {
                return;
            }
            if (hitFlags & 2) {
                goto respond;
            }
            if (hitFlags & 4) {
                actor->body.unk26 = 0xD2;
            }
        }
    }
    if (D_801ED684 != 0) {
        return;
    }

respond:
    if ((self->type == 2 || D_801E7531 == 0x13)
        && (D_801ED8E0 != 0 || (self->coll->plane[0] != NULL && D_8028F880 == 0))) {
        impact = 0.0f;
        for (j = 0; j < D_801ED8D4; j++) {
            if (impact < (DEPTH157708(j) < D_80106F7C ? DEPTH157708(j) : D_80106F7C)) {
                impact = (DEPTH157708(j) < D_80106F7C) ? DEPTH157708(j) : D_80106F80;
            }
        }
        if (self == (Body157708 *)&D_8029F978) {
            if (*(f32 *)&D_8029F5C4 != 0.0f) {
                func_80178134(0x88, &self->pos.x, impact, func_80147000(0x38) + 0x64);
            } else {
                switch (D_8029F487) {
                case 0:
                    func_80178134(0x83, &D_8029F9AC, impact, func_80147000(0x38) + 0x64);
                    break;
                case 1:
                    func_80178134(0x84, &D_8029F9AC, impact, func_80147000(0x28) + 0x14);
                    break;
                case 2:
                    func_80178134(0x85, &D_8029F9AC, impact, func_80147000(0x38) + 0x64);
                    break;
                case 3:
                    func_80178134(0x86, &D_8029F9AC, impact, func_80147000(0x24) + 0x6E);
                    break;
                case 4:
                    func_80178134(0x87, &D_8029F9AC, impact, func_80147000(0x38) + 0x64);
                    break;
                case 6:
                    func_80178134(0x89, &D_8029F9AC, impact, func_80147000(0x24) + 0x6E);
                    break;
                }
            }
        } else {
            func_80178134(0x83, &self->pos.x, impact, 0x80);
        }
    }

    if (D_801ED8D8 != 0) {
        if (self->vel.y < FD157708(D_80106FA0)) {
            self->unk70 = self->phys->unk18;
        }
        dir = (Vec3F *)&D_8028F8B0;
        dir->x *= (self->unk74 * self->phys->unk20) / UTOF157708(D_801ED8D8, FD157708(D_80106FA8));
        dir->y *= (self->unk74 * self->phys->unk20) / UTOF157708(D_801ED8D8, FD157708(D_80106FB0));
        dir->z *= (self->unk74 * self->phys->unk20) / UTOF157708(D_801ED8D8, FD157708(D_80106FB8));
        self->vel = *dir;
    } else {
        if (self->flags & 1) {
            self->vel.x = self->pos.x - self->prev.x;
            self->vel.y = self->pos.y - self->prev.y;
            self->vel.z = self->pos.z - self->prev.z;
        } else {
            func_80149428(&self->vel.x, &self->pos.x, &self->prev.x);
        }
        if (D_801EEB60 != 0 && (self->flags & 1)) {
            if (ABSF157708(self->vel.y) < FD157708(D_80106FC0)) {
                self->vel.y -= D_801ED680 / D_80106FCC;
            }
        }
        len = sqrtf(self->vel.x * self->vel.x + self->vel.z * self->vel.z);
        if (len != 0.0f && D_8028F8C4 < len) {
            self->vel.x *= D_8028F8C4 / len;
            self->vel.z *= D_8028F8C4 / len;
        }
        if (self->unkD4 != NULL && self->unkD4[8] != 0) {
            func_80149568(&self->vel.x);
            self->vel.x *= self->unk74;
            self->vel.y *= self->unk74;
            self->vel.z *= self->unk74;
        }
    }

    moved.x = self->pos.x - self->prev.x;
    moved.y = self->pos.y - self->prev.y;
    moved.z = self->pos.z - self->prev.z;
    if (sqrtf(moved.x * moved.x + moved.z * moved.z) < self->phys->unk10) {
        self->vel.x = self->vel.z = 0.0f;
    }
    func_8015CC70(&self->vel.x, (f32 *)&D_8028F8C8);

    if (D_8028F8C0 != 0.0f) {
        flag = 0;
        if (D_8028F89C != NULL) {
            flag = 1;
            if ((D_801ED8D4 == 0 || self->coll->unk188 == 0) && self->vel.y < *(const f64 *)&D_80106FD0
                && (D_801ED8D4 == 0 || (D_801ED8D4 == 1 && self->coll->plane[0] == D_8028F89C))) {
                for (i = 0; UTOF157708(i, *(const f64 *)&D_80106FD8) <= D_801ED688; i++) {
                    func_80149398(&v, &self->pos, UTOF157708(i, *(const f64 *)&D_80106FD8) / D_801ED688, &self->prev,
                                  D_80106FE0 - UTOF157708(i, *(const f64 *)&D_80106FD8) / D_801ED688);
                    {
                        Vec3F *b = D_801ED68C; Vec3F *d = &b[D_801ED8DC];
                        v.x += d->x;
                        v.y += d->y;
                        v.z += d->z;
                    }
                    if (func_80158DC4(&v.x, D_8028F89C, self->coll->rec[D_801ED8DC].radius, &hit.x) != 0.0f) {
                        flag = 0;
                        *(Vec3F *)&D_8028F890 = hit;
                        self->pos = v;
                        break;
                    }
                }
            }
        }
        for (j = 0; j < 4; j++) {
            plane = self->coll->plane[j];
            if (plane == NULL) {
                continue;
            }
            if (D_8028F8BC == plane) {
                continue;
            }
            if (D_80106FE8 < D_8028F8BC[0] * plane[0] + D_8028F8BC[1] * plane[1] + D_8028F8BC[2] * plane[2]) {
                if (ABSF157708(D_8028F8BC[3] - plane[3]) <= D_80106FF0) {
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            hit = self->pos;
            away.x = self->pos.x - ((Vec3F *)&D_8028F890)->x;
            away.y = self->pos.y - ((Vec3F *)&D_8028F890)->y;
            away.z = self->pos.z - ((Vec3F *)&D_8028F890)->z;
            if (self == (Body157708 *)&D_8029F978 && D_801ED8D4 == 0 && away.y < 0.0f && D_8029F9D4 < 0.0f) {
                center = *(Vec3F *)&D_8028F8BC[4];
                center.x += D_8028F8BC[7];
                center.y += D_8028F8BC[8];
                center.z += D_8028F8BC[9];
                center.x += D_8028F8BC[10];
                center.y += D_8028F8BC[11];
                center.z += D_8028F8BC[12];
                center.x *= *(const f64 *)&D_80106FF8;
                center.y *= *(const f64 *)&D_80106FF8;
                center.z *= *(const f64 *)&D_80106FF8; center.x -= D_8029F9AC; center.y -= D_8029F9B0; center.z -= D_8029F9B4; if (0.0f < away.x * center.x + away.y * center.y + away.z * center.z && 0.0f < D_8029F9D0 * center.x + D_8029F9D4 * center.y + D_8029F9D8 * center.z) {
                    func_80139D70(func_801D2150(&D_8025D578, D_80106F4C));
                    func_801492D4(&away.x);
                }
            }
            if (D_801ED8D4 == 0 || self->coll->unk188 == 0) {
                if (self->vel.y < *(const f64 *)&D_80107000) {
                    self->prev = self->pos;
                }
            }
            {
                Vec3F *d = &D_801ED68C[D_801ED8DC];
                away.x += d->x;
                away.y += d->y;
                away.z += d->z;
            }
            func_80149568(&away.x);
            ((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(&self->pos.x, (f32 *)&D_8028F890, &away.x, self->coll->rec[D_801ED8DC].radius);
            {
                Vec3F *d = &D_801ED68C[D_801ED8DC];
                self->pos.x -= d->x;
                self->pos.y -= d->y;
                self->pos.z -= d->z;
            }
            if (D_8028F89C != NULL) {
                self->vel.x = v.x - ((Vec3F *)&D_8028F890)->x;
                self->vel.y = v.y - ((Vec3F *)&D_8028F890)->y;
                self->vel.z = v.z - ((Vec3F *)&D_8028F890)->z;
                func_80149568(&self->vel.x);
                self->vel.x *= self->unk74 * self->phys->unk20;
                self->vel.y *= self->unk74 * self->phys->unk20;
                self->vel.z *= self->unk74 * self->phys->unk20;
            } else {
                self->vel.x = self->pos.x - self->prev.x;
                self->vel.y = self->pos.y - self->prev.y;
                self->vel.z = self->pos.z - self->prev.z;
                if ((D_801ED8D4 == 0 || self->coll->unk188 == 0) && startVelY < *(const f64 *)&D_80107008) {
                    func_80149568(&self->vel.x);
                    self->vel.x *= self->unk74 * self->phys->unk20;
                    self->vel.y *= self->unk74 * self->phys->unk20;
                    self->vel.z *= self->unk74 * self->phys->unk20;
                }
                len = sqrtf(self->vel.x * self->vel.x + self->vel.z * self->vel.z);
                if (len != 0.0f && D_8028F8C4 < len) {
                    self->vel.x *= D_8028F8C4 / len;
                    self->vel.z *= D_8028F8C4 / len;
                }
            }
        }
    }

    if (D_801ED8D4 == 0) {
        if (D_8028F880 != 0) {
            self->coll->count[0] = 0;
        } else {
            self->coll->count[0]++;
        }
    }
    for (i = 0; i < D_801ED8D4; i++) {
        for (j = 0; j < 4; j++) {
            if (self->coll->plane[i] != ((f32 **)&D_8028F880)[j]) {
                continue;
            }
            if (self->coll->plane[i] == NULL) {
                continue;
            }
            self->coll->count[i]++;
            break;
        }
        if (j == 4) {
            self->coll->count[i] = 0;
        }
    }

    flag = 1;
    if ((u32)D_801ED8D4 > 1) {
        for (i = 0; i < D_801ED8D4; i++) {
            f32 *q;
            idx = self->coll->planeIdx[i];
            q = self->coll->plane[i];
            {
                Vec3F *d = &D_801ED6EC[idx];
                len = DOT157708(*d, q) + q[3];
            }
            rad = self->coll->rec[idx].radius;
            if (len < rad - *(const f64 *)&D_80107018) {
                flag = 0;
                len = (rad - len) - *(const f64 *)&D_80107018 + *(const f64 *)&D_80107010;
                break;
            }
        }
        if (flag == 0) {
            v.x = v.y = v.z = 0.0f;
            for (i = 0; i < D_801ED8D4; i++) {
                v.x += self->coll->plane[i][0];
                v.y += self->coll->plane[i][1];
                v.z += self->coll->plane[i][2];
            }
            func_80149568(&v.x);
            func_80148D0C(&self->pos.x, &v.x, len);
            func_80148D0C(&self->vel.x, &v.x, len / *(const f64 *)&D_80107020);
        }
    }
}

extern f32 D_80107028;

/* vec3_reflect: reflects direction dir off a plane with unit normal normal,
 * dir = normalize(dir); dir += normal * -2 * dot(dir, normal); then renormalizes dir.
 * func_80149568 is vec3_normalize, func_80148D0C adds normal * scale to dir. */
void func_80158D44(f32 *dir, f32 *normal) {
    f32 negDot;
    func_80149568(dir);
    negDot = -(dir[0] * normal[0] + dir[1] * normal[1] + dir[2] * normal[2]);
    func_80148D0C(dir, normal, negDot * 2.0f);
    func_80149568(dir);
}

/* Return the first in-radius triangle-edge distance and write its projected point. */
f32 func_80158DC4(f32 *point, f32 *triangle, f32 radius, f32 *edgePoint) {
    s16 edgeIndex;
    f32 offset[3];
    f32 distanceSquared;
    f32 distanceAlongEdge;
    f32 edgeLength;

    for (edgeIndex = 0; edgeIndex < COLLISION_TRIANGLE_VERTEX_COUNT; edgeIndex++) {
        edgeLength = triangle[TRI_EDGE_LENGTHS + edgeIndex];
        if (edgeLength == D_80107028) {
            continue;
        }
        distanceAlongEdge = triangle[edgeIndex * 3 + TRI_EDGE_X] * point[0] + triangle[edgeIndex * 3 + TRI_EDGE_Y] * point[1] + triangle[edgeIndex * 3 + TRI_EDGE_Z] * point[2]
             - (triangle[edgeIndex * 3 + TRI_VERTEX0_X] * triangle[edgeIndex * 3 + TRI_EDGE_X] + triangle[edgeIndex * 3 + TRI_VERTEX0_Y] * triangle[edgeIndex * 3 + TRI_EDGE_Y] + triangle[edgeIndex * 3 + TRI_VERTEX0_Z] * triangle[edgeIndex * 3 + TRI_EDGE_Z]);
        if (distanceAlongEdge < 0.0f) {
            continue;
        }
        if (edgeLength < distanceAlongEdge) {
            continue;
        }
        ((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(edgePoint, &triangle[edgeIndex * 3 + TRI_VERTEX0_X], &triangle[edgeIndex * 3 + TRI_EDGE_X], distanceAlongEdge);
        offset[0] = point[0] - edgePoint[0];
        offset[1] = point[1] - edgePoint[1];
        offset[2] = point[2] - edgePoint[2];
        distanceSquared = offset[0] * offset[0] + offset[1] * offset[1] + offset[2] * offset[2];
        if (distanceSquared < radius * radius) {
            return sqrtf(distanceSquared);
        }
    }
    return 0.0f;
}

extern f32 D_8010717C;
extern f64 D_80107180;
extern f64 D_80107188;
extern f64 D_80107190;
extern f64 D_80107198;
extern f64 D_801071A0;
extern f64 D_801071A8;
extern f32 D_801071B0;

s32 func_80158F84(u8 *obj, f32 *poly, void *owner) {
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define OF(t,off) (*(t *)(obj + (off)))
#define AF(t,off) (*(t *)((u8 *)owner + (off)))
#define TF(t,off) (*(t *)((u8 *)poly + (off)))
#define CF(t,off) (*(t *)(OF(u8 *, 0xD8) + (off)))
#define PF(off) (*(f32 *)(OF(u8 *, 0xD0) + (off)))
#define VDOT(p) (OF(f32, 0x58) * (p)[0] + OF(f32, 0x5C) * (p)[1] + OF(f32, 0x60) * (p)[2])
#define FD8(sym) (*(const f64 *)((const u8 *)&(sym) + 4))
#define TB(k) (D_801ED750[TF(u8, 0x74)][k])
    /* Collide each of obj's collision spheres with one polygon (poly: plane normal, distance, vertex, edges, surface type at +0x74) owned by
       owner (a platform, or NULL): push obj out, record contacts in its collision state (+0xD8), bounce its velocity (+0x58), play surface
       sounds and effects, and apply the platform's push and spin. Returns flags: 1 = stop/obj handled, 2 = contact slots full, 4 = sound played. */
    extern const f32 D_8010702C;
    extern const f32 D_80107030;
    extern const f32 D_80107038;
    extern const f32 D_80107040;
    extern const f32 D_80107048;
    extern const f32 D_80107050;
    extern const f32 D_80107058;
    extern const f32 D_80107060;
    extern const f32 D_80107068;
    extern const f32 D_80107070;
    extern const f32 D_80107078;
    extern const f32 D_80107084;
    extern const f32 D_80107088;
    extern const f32 D_8010708C;
    extern const f32 D_80107090;
    extern const f32 D_80107094;
    extern const f32 D_80107098;
    extern const f32 D_8010709C;
    extern const f32 D_801070A0;
    extern const f32 D_801070A4;
    extern const f32 D_801070A8;
    extern const f32 D_801070AC;
    extern const f32 D_801070B0;
    extern const f32 D_801070B4;
    extern const f32 D_801070B8;
    extern const f32 D_801070BC;
    extern const f32 D_801070C0;
    extern const f32 D_801070C4;
    extern const f32 D_801070C8;
    extern const f32 D_801070CC;
    extern const f64 D_801070D0;
    extern const f32 D_801070D8;
    extern const f32 D_801070DC;
    extern const f32 D_801070E0;
    extern const f32 D_801070E4;
    extern const f32 D_801070E8;
    extern const f32 D_801070EC;
    extern const f32 D_801070F0;
    extern const f32 D_801070F4;
    extern const f32 D_801070F8;
    extern const f32 D_801070FC;
    extern const f32 D_80107100;
    extern const f32 D_80107104;
    extern const f32 D_80107108;
    extern const f32 D_8010710C;
    extern const f32 D_80107110;
    extern const f32 D_80107114;
    extern const f64 D_80107118;
    extern const f64 D_80107120;
    extern const f32 D_80107128;
    extern const f32 D_8010712C;
    extern const f32 D_80107130;
    extern const f32 D_80107138;
    extern const f32 D_80107140;
    extern const f32 D_80107148;
    extern const f32 D_80107154;
    extern const f64 D_80107158;
    extern u8 D_801ED684;
    extern f32 D_801ED750[][7];
    extern s32 D_801ED8D4;
    extern s32 D_801ED8D8;
    extern s32 D_801ED8DC;
    extern s32 D_801ED8E0;
    extern f32 *D_8028F880[4];
    extern Vec3F D_8028F890;
    extern f32 *D_8028F89C;
    extern f32 D_8028F8A0;
    extern f32 D_8028F8B0;
    extern f32 D_8028F8B4;
    extern f32 D_8028F8B8;
    extern f32 *D_8028F8BC;
    extern f32 D_8028F8C0;
    extern f32 D_8028F8C4;
    extern Vec3F D_8028F8C8;
    extern f32 D_8028FB4C[];
    extern s32 D_80297910;
    extern f32 D_8029F9B8;
    extern f32 D_8029F9BC;
    extern f32 D_8029F9C0;
    extern f32 D_8029F9D8;
    extern f32 D_8029F9EC;
    extern f32 D_801ED680;
    extern u8 *D_802903B4;
    f32 func_80158DC4(f32 *, f32 *, f32, f32 *);
    void func_80149568(f32 *);
    void func_8015C1D4(u8 *arg0);
    void func_8015CE38(Vec3F *arg0, u8 *arg1, f32 *arg2, s32 arg3);
    s32 func_8016225C(u8 *obj, u8 *arg1);
    void func_801743A8(s32 arg0, s16 arg1);
    void func_80195D50();
    void func_801B0DDC(void);
    void func_801B10B8(u8 *, f32 *, f32, f32);
    void func_801B3408(void);
    void func_801B48DC(f32 arg0, void *arg1, s32 arg2, s16 arg3);
    void func_801B52BC(f32, f32, f32, f32, s32, f32 *, s32, s16);
    void func_801B614C(f32 *, f32 *, s32, f32, f32, s32 *);
    void func_80148C3C(f32 *, f32 *);
    void func_801489F0(f32 *, f32 *);
    f32 center[3];
    f32 hit[3];
    f32 hp[3];
    f32 v50[3];
    f32 vels[10][3];
    f32 d[3];
    f32 e[3];
    f32 fv[3];
    f32 g[3];
    f32 savedVel[3];
    f32 w[3];
    s32 ax[3];
    f32 q0[4];
    f32 q1[4];
    f32 q2[4];
    u32 j;
    s32 bounced;
    s32 result;
    s32 i;
    f32 *normal;
    u32 k;
    f32 depth;
    f32 radius;
    f32 du;
    f32 dv;
    f32 s;
    f32 t;
    f32 r;
    f32 dd;
    f32 h;
    s32 up;

    bounced = 0; result = 0; if ((TF(f32, 0x6C) == 0.0f && TF(f32, 0x70) == 0.0f) || (TF(f32, 0x64) == 0.0f && TF(f32, 0x68) == 0.0f)) {
        return 0;
    }
    normal = poly;
    for (i = CF(u8, 0x18B) - 1; i >= 0; i--) {
        s32 off = i * 0x24;
        if (*(u16 *)(OF(u8 *, 0xD8) + off + 0x7A) & 4) {
            continue;
        }
        if (result & 2) {
            return result;
        }
        if (bounced != 0) {
            *(Vec3F *)(obj + 0x58) = *(Vec3F *)savedVel;
        }
        *(Vec3F *)center = D_801ED6EC[i];
        depth = -(center[0] * normal[0] + center[1] * normal[1] + center[2] * normal[2] + poly[3]);
        radius = *(f32 *)(OF(u8 *, 0xD8) + off + 0x70); if (depth > 0.0f) {
            if (!(-(OF(f32, 0x40) * normal[0] + OF(f32, 0x44) * normal[1] + OF(f32, 0x48) * normal[2] + poly[3]) <= 0.0f)) {
                continue;
            }
            j = 0;
            if (depth > 0.0f) {
                do {
                    dd = 0.0f;
                    func_80149398(center, center, 0.9f, obj + 0x40, D_8010702C);
                    depth = -(center[0] * normal[0] + center[1] * normal[1] + center[2] * normal[2] + poly[3]);
                    if (++j == 20) {
                        *(Vec3F *)center = *(Vec3F *)(obj + 0x40);
                        depth = -(center[0] * normal[0] + center[1] * normal[1] + center[2] * normal[2] + poly[3]);
                        break;
                    }
                } while (depth > dd);
            }
        }
        if (radius < -depth) {
            continue;
        }
        ((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(hit, center, normal, depth);
        du = hit[TF(u8, 0x75)] - poly[TF(u8, 0x75) + 4];
        dv = hit[TF(u8, 0x76)] - poly[TF(u8, 0x76) + 4]; s = D_80107030; if (TF(f32, 0x64) == 0.0f) {
            t = du / TF(f32, 0x68);
            if (FD8(D_80107030) <= t && t <= FD8(D_80107038)) {
                s = (dv - t * TF(f32, 0x70)) / TF(f32, 0x6C);
            }
        } else {
            t = (dv * TF(f32, 0x64) - du * TF(f32, 0x6C)) / (TF(f32, 0x70) * TF(f32, 0x64) - TF(f32, 0x68) * TF(f32, 0x6C));
            if (FD8(D_80107040) <= t && t <= FD8(D_80107048)) {
                s = (du - t * TF(f32, 0x68)) / TF(f32, 0x64);
            }
        }
        if (s < FD8(D_80107050) || s + t > FD8(D_80107058)) {
            r = func_80158DC4(center, poly, radius, hp);
            if (r == 0.0f) {
                continue;
            }
            if (normal[1] > FD8(D_80107060) && OF(f32, 0x5C) < 0.0f) {
                CF(u8, 0x18A) |= 2;
            } else {
                CF(u8, 0x18A) |= 4;
            }
            D_8028F890 = *(Vec3F *)hp;
            D_8028F8C0 = r;
            D_8028F8BC = poly;
            D_8028F89C = NULL;
            D_801ED8DC = i;
            if (owner != NULL && AF(u8 *, 0x38) != NULL && *(s16 *)(AF(u8 *, 0x38) + 0x50) == -3 && OF(s16, 0x20) == 2) {
                if (D_801E7531 == 0x13) {
                    func_80178134(0x6E, (f32 *)(obj + 0x34), 0x64, 0x80);
                } else if (D_801E7531 == 0x28) {
                    func_801AA8D4(obj);
                    OF(s16, 0x24) = 1;
                }
                if (obj != (u8 *)&D_8029F978) {
                    OF(s16, 0x20) = 4;
                }
                *(s16 *)(AF(u8 *, 0x38) + 0x50) = 1;
                AF(s16, 0x78) = 2;
            }
            if (OF(s32, 0x28) & 0x80) {
                OF(s16, 0x24) = 1;
                result |= 1;
            }
            bounced = 0;
        } else {
            r = func_80158DC4(&D_8028F8A0, poly, radius, hp);
            if (r != 0.0f) {
                D_8028F890 = *(Vec3F *)hp;
                D_8028F8C0 = r;
                D_8028F8BC = poly;
                D_801ED8DC = i;
                if (D_8028F89C == NULL || D_8028F89C[1] > poly[1]) {
                    D_8028F89C = poly;
                }
            }
            CF(f32 *, D_801ED8D4 * 4) = poly;
            CF(u8, 0x18A) |= 1;
            *(Vec3F *)(OF(u8 *, 0xD8) + D_801ED8D4 * 12 + 0x10) = *(Vec3F *)hit;
            (D_801ED8D4 + OF(u8 *, 0xD8))[0x40] = i;
            if (normal[1] > 0.0f) {
                (D_801ED8D4 + OF(u8 *, 0xD8))[0x54] = 1;
            }
            if (++D_801ED8D4 == 4) {
                result |= 2;
            }
            if (D_801ED684 != 0) {
                if (obj == D_8028F8E0) {
                    D_8028FB4C[D_801ED8D4] = -depth;
                }
                return result;
            }
            ((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)((f32 *)(obj + 0x34), hit, normal, radius);
            { Vec3F *q = &D_801ED68C[i];
            OF(f32, 0x34) -= q->x;
            OF(f32, 0x38) -= q->y;
            OF(f32, 0x3C) -= q->z; }
            if (OF(s32, 0x28) & 0x80) {
                OF(s16, 0x24) = 1;
                bounced = 0;
                result |= 1;
            } else {
                *(Vec3F *)vels[D_801ED8D8] = *(Vec3F *)(obj + 0x58);
                if (owner != NULL) {
                    ((Vec3F *)vels)[D_801ED8D8].x -= AF(f32, 0xD8);
                    ((Vec3F *)vels)[D_801ED8D8].y -= AF(f32, 0xDC);
                    ((Vec3F *)vels)[D_801ED8D8].z -= AF(f32, 0xE0);
                }
                {
                    f32 *v = (f32 *)(D_801ED8D8 * 12 + (s32)center); v = (f32 *)((u8 *)v + 0x40);
                    func_80149568(v);
                    func_80148D0C(v, normal, -(v[0] * normal[0] + v[1] * normal[1] + v[2] * normal[2]) * 2.0f);
                    func_80149568(v);
                }
                if (D_8028F8C0 == 0.0f) {
                    f32 vy = OF(f32, 0x5C);
                    if ((vy > 0.0f ? vy : -vy) < FD8(D_80107068)) {
                        if (vy < 0.0f) {
                            vels[D_801ED8D8][1] = 0.0f;
                        }
                    }
                }
                bounced = 1;
                if ((OF(s32, 0x28) & 1) && (OF(f32, 0x5C) > 0.0f ? OF(f32, 0x5C) < D_801ED680 : -OF(f32, 0x5C) < D_801ED680)
                    && OF(f32, 0x74) < D_801ED680 * 2.0f) {
                    bounced = 0;
                } else {
                    if (D_8028F880[0] != NULL) {
                        for (j = 0; j < 4; j++) {
                            if (D_8028F880[j] == poly && CF(s32, j * 4 + 0x44) > 0) {
                                bounced = 0;
                            }
                        }
                    }
                    *(Vec3F *)d = *(Vec3F *)(obj + 0x58);
                    func_80149568(d);
                    dd = d[0] * normal[0] + d[1] * normal[1] + d[2] * normal[2];
                    if (dd > FD8(D_80107070) || (dd > FD8(D_80107078) && (PF(0x20) <= 0.0f || CF(u8, 0x188) != 0))) {
                        bounced = 0;
                    }
                }
                if (bounced == 1) {
                    if (TF(u8, 0x74) == 5) {
                        func_801B48DC(center[1] + depth + D_80107084, obj, (s32)poly, 1);
                    }
                    if (TF(u8, 0x74) == 12) {
                        f32 x, y, z, vol, vd;
                        x = hit[0] + poly[0]; y = hit[1] + poly[1]; z = hit[2] + poly[2]; vol = ((VDOT(poly) > 0.0f ? VDOT(poly) / D_80107088 > D_8010708C : -VDOT(poly) / D_80107090 > D_80107094) ? (VDOT(poly) > 0.0f ? VDOT(poly) / D_80107098 < D_8010709C : (-VDOT(poly) / D_801070A0 < D_801070A4 ? 1 : ({ goto la4; 0; }))) : 1) ? ((VDOT(poly) > 0.0f ? VDOT(poly) / D_801070A8 > D_801070AC : (-VDOT(poly) / D_801070B0 > D_801070B4 ? 1 : ({ goto lb4; 0; }))) ? (VDOT(poly) > 0.0f ? VDOT(poly) / D_801070B8 : -VDOT(poly) / D_801070BC) : D_801070C0) : D_801070C4;
                        goto done1; do { } while (0);
                        la4: vol = D_801070A4; goto done1; do { } while (0);
                        lb4: vol = D_801070B4;
                        done1:
                        func_801B52BC(x, y, z, vol, 2, poly, D_80297910, 0x800);
                        result |= 4;
                    }
                    if (PF(0x30) != 0.0f && !(OF(s32, 0x28) & 0x2000000)) {
                        func_801B10B8(obj, normal, -(OF(f32, 0x58) * normal[0] + OF(f32, 0x5C) * normal[1] + OF(f32, 0x60) * normal[2]) / D_801070C8, PF(0x30));
                    }
                    if (owner != NULL) {
                        if (AF(s32, 0x14) & 0x200) {
                            func_8015CE38(&D_8028F8C8, owner, (f32 *)(obj + 0x34), 0);
                        }
                        for (k = 0; k < 3; k++) {
                            if (*((u8 *)owner + k + 0x74) != 0) {
                                func_80178134(0x12, (f32 *)(obj + 0x34), 0x64, func_80147000(0x32) + 0x64);
                                { f32 *row = vels[D_801ED8D8]; row[k] *= AF(f32, 0x70); }
                            }
                        }
                    }
                    if (PF(0x20) >= 0.0f) {
                        *(Vec3F *)savedVel = *(Vec3F *)vels[D_801ED8D8];
                        savedVel[0] *= OF(f32, 0x74) * TB(0);
                        savedVel[1] *= OF(f32, 0x74) * TB(0);
                        savedVel[2] *= OF(f32, 0x74) * TB(0);
                        (D_801ED8D4 + OF(u8 *, 0xD8))[0x53] = 0;
                        func_80148D0C(&D_8028F8B0, vels[D_801ED8D8], TB(0));
                        D_801ED8D8++;
                        D_801ED8E0++;
                    } else {
                        bounced = 0;
                        D_801ED8E0++;
                    }
                }
                if (bounced == 0 || PF(0x20) <= 0.0f) {
                    if (TF(u8, 0x74) == 5) {
                        func_801B614C(center, (f32 *)(obj + 0x58), (s32)owner, center[1] + depth + D_801070CC, D_8028F8C4, (s32 *)poly);
                    }
                    if (TF(u8, 0x74) == 12) {
                        f32 vd;
                        vd = VDOT(poly);
                        if (vd < D_801070D0) {
                            f32 x, y, z, vol, nv;
                            x = hit[0] + poly[0]; y = hit[1] + poly[1]; z = hit[2] + poly[2]; if ((vd > 0.0f ? vd / D_801070D8 > D_801070DC : -vd / D_801070E0 > D_801070E4)
                                && (vd > 0.0f ? !(vd / D_801070E8 < D_801070EC) : ((nv = -vd, nv = nv / D_801070F0, !(nv < (vol = D_801070F4))) ? ({  goto done2; 0; }) : 0))) goto five2;
                            if (vd > 0.0f ? !(vd / D_801070F8 > D_801070FC) : ((nv = -vd, nv = nv / D_80107100, !(nv > (vol = D_80107104))) ? ({  goto done2; 0; }) : 0)) goto one2;
                            vol = vd > 0.0f ? vd / D_80107108 : -vd / D_8010710C;
                            goto done2;
                        one2:
                            vol = D_80107110;
                            goto done2;
                        five2:
                            vol = D_80107114;
                        done2:
                            func_801B52BC(x, y, z, vol, 1, poly, D_80297910, 0x800);
                            result |= 4;
                        }
                    }
                    if (poly[1] > D_80107118 || (OF(s32, 0x28) & 0x8000)) {
                        CF(void *, 0x178) = owner;
                    }
                }
            }
        }
        if (obj == (u8 *)&D_8029F978 && D_8029F487 == 6 && *(s16 *)(D_802903B4 + 2) != 0x41 && D_801E7620 == 0) {
            w[0] = D_8029F9AC - D_8029F9B8;
            w[1] = D_8029F9B0 - D_8029F9BC;
            w[2] = D_8029F9B4 - D_8029F9C0;
#define DOTW (w[0] * poly[0] + w[1] * poly[1] + w[2] * poly[2])
            dd = DOTW > 0.0f ? DOTW : -DOTW;
#define DOT9D0 (D_8029F9D0 * poly[0] + D_8029F9D4 * poly[1] + D_8029F9D8 * poly[2])
#define ABS9D0 (DOT9D0 > 0.0f ? DOT9D0 : -DOT9D0)
            dd = (ABS9D0 < dd) ? dd : ABS9D0;
            { f32 tt = TB(4);
            if (tt < dd || (tt < D_8029F9EC && tt / D_80107120 < dd)) {
                func_801B3408();
                result |= 1;
                break;
            } }
        }
        func_8015C1D4(obj);
        if (TF(u8, 0x74) == 6 && (OF(s32, 0x28) & 0x400000)) {
            OF(s16, 0x24) = 1;
            if (obj == (u8 *)&D_8029F978) {
                func_801B0DDC();
                result |= 1;
                break;
            }
            if (obj == (u8 *)&D_802902D8) {
                func_801743A8(0, -1);
                break;
            }
            if (OF(s8 *, 0xD4)[2] != -1) {
                func_80195D50(D_802996E8 + OF(s8 *, 0xD4)[2] * 0x300);
                break;
            }
        } else if (TF(u8, 0x74) == 9
                   && (obj == (u8 *)&D_802902D8
                       || (obj == (u8 *)&D_8029F978 && D_8029F9A4 == (s32)&D_802902D8 && D_8028FBFB == 0))) {
            func_801743A8(0, 1);
            break;
        }
        if (owner == NULL) {
            continue;
        }
        if ((AF(s32, 0x14) & 0x100) && (OF(s32, 0x28) & 0x200)) {
            if (OF(f32, 0x74) > D_80107128 || (OF(s16, 0x20) == 0x10 && i != 0)) {
                AF(s32, 0x14) |= 2;
            }
        }
        if ((AF(s32, 0x14) & 0x40000) && obj == (u8 *)&D_8029F978 && D_8029F487 == 1 && D_8029F9EC > D_8010712C) {
            if (D_8029F9A4 == 0 || (D_8029F9A4 == (s32)&D_802902D8 && D_8028FBFB != 0)) {
                AF(s32, 0x14) |= 2;
            }
        }
        if ((OF(s32, 0x28) & 0x400) && (AF(s32, 0xA8) & 0x400)) {
            CF(void *, 0x178) = owner;
        }
        CF(void *, 0x180) = owner;
        if (AF(s32, 0x14) & 8) {
            OF(u8 *, 0xD4)[0xB] = 1;
        }
        if (AF(s32, 0x14) & 0x4000) {
            if (obj == (u8 *)&D_802902D8) {
                func_801743A8(1, 1);
                result |= 1;
                break;
            }
            if (obj == (u8 *)&D_8029F978) {
                func_801B0DDC();
                result |= 1;
                break;
            }
        }
        if (func_8016225C(obj, owner) != 0) {
            bounced = 0;
            result |= 1;
            break;
        }
        {
            s16 *p = AF(s16 *, 0x3C);
            if (p != NULL && p[1] > 0 && p[0] == 0 && !(OF(s32, 0x28) & 0x40000000)) {
                p[0] = 1;
            }
        }
        if (owner != NULL && AF(u8 *, 0x38) != NULL && *(s16 *)(AF(u8 *, 0x38) + 0x50) == -3 && OF(s16, 0x20) == 2) {
            if (D_801E7531 == 0x13) {
                func_80178134(0x6E, (f32 *)(obj + 0x34), 0x64, 0x80);
            } else if (D_801E7531 == 0x28) {
                func_801AA8D4(obj);
                OF(s16, 0x24) = 1;
            }
            if (obj != (u8 *)&D_8029F978) {
                OF(s16, 0x20) = 4;
            }
            *(s16 *)(AF(u8 *, 0x38) + 0x50) = 1;
            AF(s16, 0x78) = 2;
        }
        if (AF(u8 *, 0x2C) != NULL) {
            u32 nn;
            u32 kk;
            *(Vec3F *)e = *(Vec3F *)(AF(u8 *, 0x2C) + 0x50);
            j = 0;
            for (kk = 0, nn = 0; kk < 3; kk++) {
                if (*(s8 *)(AF(u8 *, 0x2C) + kk + 4) == 0) {
                    ax[nn++] = kk;
                } else {
                    j = kk;
                }
            }
        }
        if (PF(0) != 0.0f) {
            if (AF(u8 *, 0x40) == NULL || *(f32 *)(AF(u8 *, 0x40) + 4) == 0.0f || (OF(s32, 0x28) & 0x40000000)
                || (obj == (u8 *)&D_802902D8
                    && (*(s16 *)(D_802903AC + 4) == 3 || *(s16 *)(D_802903AC + 4) == 5 || *(s16 *)(D_802903AC + 4) == 11))) {
            } else {
                fv[0] = OF(f32, 0x58) - AF(f32, 0xD8);
                fv[1] = OF(f32, 0x5C) - AF(f32, 0xDC);
                fv[2] = OF(f32, 0x60) - AF(f32, 0xE0);
                up = 0;
                if (CF(void *, 0x178) == owner || CF(void *, 0x17C) == owner) {
                    up = 1;
                    if (AF(f32, 0xDC) <= 0.0f) {
                        fv[1] = -D_801ED680;
                    } else {
                        fv[1] = -AF(f32, 0xDC) - D_801ED680;
                    }
                    if ((AF(s32, 0xA8) & 0x200000) && (OF(s32, 0x28) & 0x200000)) {
                        up = 0;
                        if (OF(u8 *, 0xD4)[9] != 0) {
                            fv[1] = fv[1] / D_80107130;
                        } else {
                            AF(f32, 0xDC) = AF(f32, 0xDC) * FD8(D_80107130);
                            fv[1] = fv[1] / FD8(D_80107138);
                        }
                    }
                }
                fv[0] *= PF(0) / *(f32 *)(AF(u8 *, 0x40) + 4);
                fv[1] *= PF(0) / *(f32 *)(AF(u8 *, 0x40) + 4);
                fv[2] *= PF(0) / *(f32 *)(AF(u8 *, 0x40) + 4);
                if (up == 0) {
                    h = -(normal[0] * fv[0] + normal[1] * fv[1] + normal[2] * fv[2]) - FD8(D_80107140);
                } else {
                    h = -fv[1];
                }
                if (h > 0.0f) {
                    *(Vec3F *)v50 = *(Vec3F *)normal;
                    v50[0] *= -h;
                    v50[1] *= -h;
                    v50[2] *= -h;
                    {
                        u32 kk;
                        for (kk = 0; kk < 3; kk++) {
                            if (*(s8 *)(AF(u8 *, 0x40) + kk) == 0) {
                                v50[kk] = 0.0f;
                            }
                        }
                    }
                    AF(f32, 0xD8) += v50[0];
                    AF(f32, 0xDC) += v50[1];
                    AF(f32, 0xE0) += v50[2];
                    AF(f32, 0xF4) = sqrtf(AF(f32, 0xD8) * AF(f32, 0xD8) + AF(f32, 0xDC) * AF(f32, 0xDC) + AF(f32, 0xE0) * AF(f32, 0xE0));
                    if (AF(f32, 0x1C) < AF(f32, 0xF4)) {
                        AF(f32, 0xD8) *= AF(f32, 0x1C) / AF(f32, 0xF4);
                        AF(f32, 0xDC) *= AF(f32, 0x1C) / AF(f32, 0xF4);
                        AF(f32, 0xE0) *= AF(f32, 0x1C) / AF(f32, 0xF4);
                        AF(f32, 0xF4) = AF(f32, 0x1C);
                    }
                }
            }
        if (AF(s32, 0x14) & 0x10000) {
            func_80149428(g, (f32 *)(obj + 0x34), (f32 *)((u8 *)owner + 0xB4));
            dd = sqrtf(g[0] * g[0] + g[2] * g[2]);
            if (dd != 0.0f) {
                q0[1] = 0.0f;
                q0[2] = g[0] / dd;
                q0[0] = -g[2] / dd;
                q0[3] = PF(0) * OF(f32, 0x5C) * dd / *(f32 *)(AF(u8 *, 0x2C) + 0x70);
                func_80148C3C(q2, q0);
                func_80148C3C(q1, (f32 *)((u8 *)owner + 0x12C));
                ((void (*)(f32 *, f32 *, f32 *))func_801488C0)(q0, q1, q2);
                func_801489F0((f32 *)((u8 *)owner + 0x12C), q0);
            }
        }
        if ((AF(s32, 0x14) & 0x10) && !(OF(s32, 0x28) & 0x40000000)) {
            v50[0] = OF(f32, 0x58) - AF(f32, 0xD8);
            v50[1] = OF(f32, 0x5C) - AF(f32, 0xDC);
            v50[2] = OF(f32, 0x60) - AF(f32, 0xE0);
            if (OF(s32, 0x28) & 1) {
                v50[1] -= D_801ED680;
            }
            dd = sqrtf(v50[ax[0]] * v50[ax[0]] + v50[ax[1]] * v50[ax[1]]);
            if (dd != 0.0f) {
                v50[ax[0]] /= dd;
                v50[ax[1]] /= dd;
            }
            h = v50[ax[0]] * poly[ax[0]] + v50[ax[1]] * poly[ax[1]];
            if (!(h >= 0.0f)) {
                d[0] = hit[0] - AF(f32, 0xB4);
                d[1] = hit[1] - AF(f32, 0xB8);
                d[2] = hit[2] - AF(f32, 0xBC);
                if (*(f32 *)(AF(u8 *, 0x2C) + 0x3C) != 0.0f) {
                    func_801490AC((Vec3F *)d, (Vec3F *)d, -*(f32 *)(AF(u8 *, 0x2C) + 0x3C));
                }
                r = sqrtf(d[ax[0]] * d[ax[0]] + d[ax[1]] * d[ax[1]]);
                depth = r * (-h * dd); h = v50[ax[0]] * d[ax[1]] - v50[ax[1]] * d[ax[0]]; if (!((h > 0.0f ? h : -h) < FD8(D_80107148))) {
                    *(s32 *)(AF(u8 *, 0x2C) + 0x20) = 0;
                    depth *= h; depth *= PF(0); depth /= *(f32 *)(AF(u8 *, 0x2C) + 0x70) * D_80107154;
                    if (j == 1) {
                        *(f32 *)(AF(u8 *, 0x2C) + 0x54) += depth;
                    } else {
                        ((f32 *)(AF(u8 *, 0x2C) + 0x50))[j] -= depth;
                    }
                }
            }
        }
        }
        if (AF(u8 *, 0x2C) == NULL || (AF(s32, 0x14) & 0x10000)) {
            continue;
        }
        if ((u32)ax[0] >= 3 || (u32)ax[1] >= 3) {
            if (result & 1) {
                break;
            }
            continue;
        }
        if (e[j] == 0.0f) {
            continue;
        }
        if (CF(void *, 0x184) == owner) {
            continue;
        }
        hp[0] = hit[0] - AF(f32, 0xB4);
        hp[1] = hit[1] - AF(f32, 0xB8);
        hp[2] = hit[2] - AF(f32, 0xBC);
        hp[j] = 0.0f;
        depth = sqrtf(hp[0] * hp[0] + hp[1] * hp[1] + hp[2] * hp[2]);
        dd = func_80147460(hp[ax[1]], hp[ax[0]]);
        if (j == 1) {
            dd += e[1];
        } else {
            dd -= e[j];
        }
        d[ax[0]] = hp[ax[0]] - depth * ({ func_801C4040(dd); });
        d[ax[1]] = hp[ax[1]] - depth * ({ func_801C6000(dd); });
        d[j] = 0.0f;
        func_80149568(d);
        hp[0] = OF(f32, 0x34) - hit[0];
        hp[1] = OF(f32, 0x38) - hit[1];
        hp[2] = OF(f32, 0x3C) - hit[2];
        { Vec3F *q = &D_801ED68C[i];
        hp[0] += q->x;
        hp[1] += q->y;
        hp[2] += q->z; }
        if (e[j] != 0.0f && (AF(s32, 0x14) & 0x10)) {
            for (k = 0; CF(f32 *, k * 4) != NULL; k++) {
                f32 *p = CF(f32 *, k * 4);
                if (poly != p && d[0] * p[0] + d[1] * p[1] + d[2] * p[2] < D_80107158) {
                    ((f32 *)(AF(u8 *, 0x2C) + 0x50))[j] = -((f32 *)(AF(u8 *, 0x2C) + 0x50))[j] * PF(0x20);
                }
            }
        }
        if (j == 1) {
            continue;
        }
        d[0] *= depth * (e[j] > 0.0f ? e[j] : -e[j]);
        d[1] *= depth * (e[j] > 0.0f ? e[j] : -e[j]);
        d[2] *= depth * (e[j] > 0.0f ? e[j] : -e[j]);
        OF(f32, 0x58) += d[0];
        OF(f32, 0x5C) += d[1];
        OF(f32, 0x60) += d[2];
        ((f32 *)obj)[0x40 / 4] -= d[0];
        ((f32 *)obj)[0x44 / 4] -= d[1];
        ((f32 *)obj)[0x48 / 4] -= d[2];
        if (D_801ED8D8 != 0) {
            f32 *acc = &D_8028F8B0;
            u8 *pv = (u8 *)vels - 12;
            s32 o;
            savedVel[0] += d[0];
            savedVel[1] += d[1];
            savedVel[2] += d[2];
            o = D_801ED8D8 * 12;
            *acc -= *(f32 *)((s32)pv + o + 0);
            D_8028F8B4 -= *(f32 *)((s32)pv + o + 4);
            D_8028F8B8 -= *(f32 *)((s32)pv + o + 8);
            func_80148D0C(d, vels[D_801ED8D8 - 1], OF(f32, 0x74));
            func_80149568(d);
            *acc += d[0];
            D_8028F8B4 += d[1];
            D_8028F8B8 += d[2];
        }
        OF(f32, 0x74) = sqrtf(OF(f32, 0x58) * OF(f32, 0x58) + OF(f32, 0x5C) * OF(f32, 0x5C) + OF(f32, 0x60) * OF(f32, 0x60));
    }
    if (bounced != 0) {
        *(Vec3F *)(obj + 0x58) = *(Vec3F *)savedVel;
    }
    return result;
#undef OF
#undef AF
#undef TF
#undef CF
#undef PF
#undef VDOT
#undef TB
#undef FD8
#undef DOT9D0
#undef ABS9D0
#undef DOTW
}

f32 func_8015B524(void *position, s32 outTriangle, void *outPlatform, s32 supportContact) { /* Find the ground below a point, returning its distance, triangle and platform. */
    extern f32 D_80107160;
    extern f64 D_80107164;
    extern const f32 D_8010716C;
    extern const f32 D_80107170;
    extern f32 D_80107174;
    extern f32 D_80107178;
    extern Body157708 D_8026A058;
    f32 nearestDistance = D_80107160, hitDistance;
    f32 horizontalOffset[4];
    Vec3F hitPosition;
    Body157708 *body;
    Actor157708 *platform;
    u32 triangleIndex;
    hitPosition = *(Vec3F *)position;
    *(s32 *)outTriangle = 0;
    *(s32 *)outPlatform = 0;
    if (supportContact != 0 && *(s32 *)supportContact != 0 && (f64)*(f32 *)(*(u8 **)supportContact + GROUND_NORMAL_Y_OFFSET) >= D_80107164 && *(f32 *)((u8 *)position + GROUND_POSITION_Y_OFFSET) >= *(f32 *)(supportContact + GROUND_CONTACT_HEIGHT_OFFSET)) {
        *(s32 *)outTriangle = *(s32 *)supportContact;
        *(s32 *)outPlatform = *(s32 *)(supportContact + GROUND_CONTACT_PLATFORM_OFFSET);
        return *(f32 *)((u8 *)position + GROUND_POSITION_Y_OFFSET) - *(f32 *)(supportContact + GROUND_CONTACT_HEIGHT_OFFSET);
    }
    for (body = D_8026A058.next; body != &D_8026A058; body = body->next) {
        func_80149428(horizontalOffset, (f32 *)position, &body->pos.x);
        if (!(body->radius * body->radius < horizontalOffset[0] * horizontalOffset[0] + horizontalOffset[2] * horizontalOffset[2]) && !(nearestDistance < *(f32 *)((u8 *)position + GROUND_POSITION_Y_OFFSET) - body->pos.y - body->radius)) {
            for (triangleIndex = 0; triangleIndex < *body->mesh->data->count; triangleIndex++) {
                hitDistance = func_8015B878((f32 *)position, (f32 *)(body->tris + triangleIndex * COLLISION_TRIANGLE_BYTES), &hitPosition.x, nearestDistance);
                if (hitDistance != D_8010716C) {
                    nearestDistance = hitDistance;
                    *(s32 *)outTriangle = (s32)(body->tris + triangleIndex * COLLISION_TRIANGLE_BYTES);
                }
            }
        }
    }
    for (platform = (Actor157708 *)D_802904D4.next; platform != (Actor157708 *)&D_802904D4; platform = platform->next) {
        if ((platform->flags & GROUND_QUERY_SKIP_PLATFORM_MASK) == 0 && !(nearestDistance < *(f32 *)((u8 *)position + GROUND_POSITION_Y_OFFSET) - platform->body.pos.y - platform->body.radius)) {
            func_80149428(horizontalOffset, (f32 *)position, &platform->body.pos.x);
            if (!(platform->body.radius * platform->body.radius < horizontalOffset[0] * horizontalOffset[0] + horizontalOffset[2] * horizontalOffset[2])) {
                if (platform->unk6E < D_802004E0) func_8017D7B8(platform);
                for (triangleIndex = 0; triangleIndex < *platform->body.mesh->data->count; triangleIndex++) {
                    hitDistance = func_8015B878((f32 *)position, (f32 *)(platform->body.tris + triangleIndex * COLLISION_TRIANGLE_BYTES), &hitPosition.x, nearestDistance);
                    if (hitDistance != D_80107170) {
                        nearestDistance = hitDistance;
                        *(s32 *)outTriangle = (s32)(platform->body.tris + triangleIndex * COLLISION_TRIANGLE_BYTES);
                        *(s32 *)outPlatform = (s32)platform;
                    }
                }
            }
        }
    }
    hitDistance = D_80107178; if (nearestDistance != D_80107174) hitDistance = nearestDistance;
    return hitDistance;
}

/* Return the downward hit distance for an upward-facing triangle, or the no-hit sentinel. */
f32 func_8015B878(f32 *origin, f32 *triangle, f32 *hitPosition, f32 maxDistance)
{
    f32 distance;
    f32 barycentricU;
    f32 barycentricV;
    f32 projectedU;
    f32 projectedV;
    s32 axisU;
    s32 axisV;

    if (triangle[TRI_NORMAL_Y] <= 0.0f) {
        return D_801071B0;
    }
    distance = origin[0] * triangle[TRI_NORMAL_X] + origin[1] * triangle[TRI_NORMAL_Y] + origin[2] * triangle[TRI_NORMAL_Z] + triangle[TRI_PLANE_DISTANCE];
    distance /= triangle[TRI_NORMAL_Y];
    if ((0.0f < distance) & (distance < maxDistance)) {
        hitPosition[1] = origin[1] - distance;
        axisU = ((u8 *)triangle)[TRI_PROJECTION_AXIS_U];
        axisV = ((u8 *)triangle)[TRI_PROJECTION_AXIS_V];
        projectedU = hitPosition[axisU] - triangle[TRI_VERTEX0_X + axisU];
        projectedV = hitPosition[axisV] - triangle[TRI_VERTEX0_X + axisV];
        barycentricU = D_8010717C;
        if (triangle[TRI_EDGE01_U] == 0.0f) {
            barycentricV = projectedU / triangle[TRI_EDGE02_U];
            if (D_80107180 <= barycentricV && barycentricV <= D_80107188) {
                barycentricU = (projectedV - barycentricV * triangle[TRI_EDGE02_V]) / triangle[TRI_EDGE01_V];
            }
        } else {
            barycentricV = (projectedV * triangle[TRI_EDGE01_U] - projectedU * triangle[TRI_EDGE01_V]) / (triangle[TRI_EDGE02_V] * triangle[TRI_EDGE01_U] - triangle[TRI_EDGE02_U] * triangle[TRI_EDGE01_V]);
            if (D_80107190 <= barycentricV && barycentricV <= D_80107198) {
                barycentricU = (projectedU - barycentricV * triangle[TRI_EDGE02_U]) / triangle[TRI_EDGE01_U];
            }
        }
        if (!(barycentricU < D_801071A0) && !(D_801071A8 < barycentricU + barycentricV)) {
            return distance;
        }
    }
    return D_801071B0;
}

/* Prepare the plane equation, projection axes, and unit edges for triangle collision tests. */
void func_8015BA6C(f32 *triangle) {
    f32 maxNormalComponent;
    f32 edgeLength;
    u32 edgeIndex;
    u32 nextVertex;

    triangle[TRI_PLANE_DISTANCE] = -(triangle[TRI_VERTEX0_X] * triangle[TRI_NORMAL_X] + triangle[TRI_VERTEX0_Y] * triangle[TRI_NORMAL_Y] + triangle[TRI_VERTEX0_Z] * triangle[TRI_NORMAL_Z]); maxNormalComponent = (triangle[TRI_NORMAL_X] > 0.0f ? triangle[TRI_NORMAL_X] : -triangle[TRI_NORMAL_X]) > ((triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) > (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z]) ? (triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) : (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z])) ? (triangle[TRI_NORMAL_X] > 0.0f ? triangle[TRI_NORMAL_X] : -triangle[TRI_NORMAL_X]) : ((triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) > (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z]) ? (triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) : (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z]));
    if (triangle[TRI_NORMAL_X] > 0.0f ? maxNormalComponent == triangle[TRI_NORMAL_X] : maxNormalComponent == -triangle[TRI_NORMAL_X]) {
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_U] = 1;
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_V] = 2;
    } else if (triangle[TRI_NORMAL_Y] > 0.0f ? maxNormalComponent == triangle[TRI_NORMAL_Y] : maxNormalComponent == -triangle[TRI_NORMAL_Y]) {
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_U] = 2;
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_V] = 0;
    } else {
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_U] = 0;
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_V] = 1;
    }
    triangle[TRI_EDGE01_U] = triangle[TRI_VERTEX1_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]];
    triangle[TRI_EDGE02_U] = triangle[TRI_VERTEX2_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]];
    triangle[TRI_EDGE01_V] = triangle[TRI_VERTEX1_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]];
    triangle[TRI_EDGE02_V] = triangle[TRI_VERTEX2_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]];
    edgeIndex = 0;
    do {
        nextVertex = edgeIndex + 1;
        triangle[edgeIndex * 3 + TRI_EDGE_X] = triangle[(nextVertex % 3) * 3 + TRI_VERTEX0_X] - triangle[edgeIndex * 3 + TRI_VERTEX0_X];
        triangle[edgeIndex * 3 + TRI_EDGE_Y] = triangle[(nextVertex % 3) * 3 + TRI_VERTEX0_Y] - triangle[edgeIndex * 3 + TRI_VERTEX0_Y];
        triangle[edgeIndex * 3 + TRI_EDGE_Z] = triangle[(nextVertex % 3) * 3 + TRI_VERTEX0_Z] - triangle[edgeIndex * 3 + TRI_VERTEX0_Z];
        edgeLength = sqrtf(triangle[edgeIndex * 3 + TRI_EDGE_X] * triangle[edgeIndex * 3 + TRI_EDGE_X] + triangle[edgeIndex * 3 + TRI_EDGE_Y] * triangle[edgeIndex * 3 + TRI_EDGE_Y] + triangle[edgeIndex * 3 + TRI_EDGE_Z] * triangle[edgeIndex * 3 + TRI_EDGE_Z]); triangle[TRI_EDGE_LENGTHS + edgeIndex] = edgeLength; if (edgeLength != 0.0f) {
            triangle[edgeIndex * 3 + TRI_EDGE_X] /= edgeLength;
            triangle[edgeIndex * 3 + TRI_EDGE_Y] /= triangle[TRI_EDGE_LENGTHS + edgeIndex];
            triangle[edgeIndex * 3 + TRI_EDGE_Z] /= triangle[TRI_EDGE_LENGTHS + edgeIndex];
        }
        edgeIndex = nextVertex;
    } while (edgeIndex < 3);
}

/* Refresh collision plane, projection axes and edge directions using cached edge lengths. */
void func_8015BE58(f32 *triangle) {
    f32 maxNormalComponent;
    u32 edgeIndex;

    triangle[TRI_PLANE_DISTANCE] = -(triangle[TRI_VERTEX0_X] * triangle[TRI_NORMAL_X] + triangle[TRI_VERTEX0_Y] * triangle[TRI_NORMAL_Y] + triangle[TRI_VERTEX0_Z] * triangle[TRI_NORMAL_Z]); maxNormalComponent = (triangle[TRI_NORMAL_X] > 0.0f ? triangle[TRI_NORMAL_X] : -triangle[TRI_NORMAL_X]) > ((triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) > (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z]) ? (triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) : (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z])) ? (triangle[TRI_NORMAL_X] > 0.0f ? triangle[TRI_NORMAL_X] : -triangle[TRI_NORMAL_X]) : ((triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) > (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z]) ? (triangle[TRI_NORMAL_Y] > 0.0f ? triangle[TRI_NORMAL_Y] : -triangle[TRI_NORMAL_Y]) : (triangle[TRI_NORMAL_Z] > 0.0f ? triangle[TRI_NORMAL_Z] : -triangle[TRI_NORMAL_Z]));
    if (triangle[TRI_NORMAL_X] > 0.0f ? maxNormalComponent == triangle[TRI_NORMAL_X] : maxNormalComponent == -triangle[TRI_NORMAL_X]) {
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_U] = 1;
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_V] = 2;
    } else if (triangle[TRI_NORMAL_Y] > 0.0f ? maxNormalComponent == triangle[TRI_NORMAL_Y] : maxNormalComponent == -triangle[TRI_NORMAL_Y]) {
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_U] = 2;
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_V] = 0;
    } else {
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_U] = 0;
        ((u8 *)triangle)[TRI_PROJECTION_AXIS_V] = 1;
    }
    triangle[TRI_EDGE01_U] = triangle[TRI_VERTEX1_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]];
    triangle[TRI_EDGE02_U] = triangle[TRI_VERTEX2_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_U]];
    triangle[TRI_EDGE01_V] = triangle[TRI_VERTEX1_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]];
    triangle[TRI_EDGE02_V] = triangle[TRI_VERTEX2_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]] - triangle[TRI_VERTEX0_X + ((u8 *)triangle)[TRI_PROJECTION_AXIS_V]];
    edgeIndex = 0;
    do {
        u32 nextVertex = edgeIndex + 1;
        triangle[edgeIndex * 3 + TRI_EDGE_X] = triangle[(nextVertex % 3) * 3 + TRI_VERTEX0_X] - triangle[edgeIndex * 3 + TRI_VERTEX0_X];
        triangle[edgeIndex * 3 + TRI_EDGE_Y] = triangle[(nextVertex % 3) * 3 + TRI_VERTEX0_Y] - triangle[edgeIndex * 3 + TRI_VERTEX0_Y];
        triangle[edgeIndex * 3 + TRI_EDGE_Z] = triangle[(nextVertex % 3) * 3 + TRI_VERTEX0_Z] - triangle[edgeIndex * 3 + TRI_VERTEX0_Z];
        if (triangle[TRI_EDGE_LENGTHS + edgeIndex] != 0.0f) {
            triangle[edgeIndex * 3 + TRI_EDGE_X] /= triangle[TRI_EDGE_LENGTHS + edgeIndex];
            triangle[edgeIndex * 3 + TRI_EDGE_Y] /= triangle[TRI_EDGE_LENGTHS + edgeIndex];
            triangle[edgeIndex * 3 + TRI_EDGE_Z] /= triangle[TRI_EDGE_LENGTHS + edgeIndex];
        }
        edgeIndex = nextVertex;
    } while (edgeIndex < 3);
}

void func_8015C1D4(u8 *object)
{
    /* Compute each collision sphere's world center and offset from the object. */
    f32 unusedPadding[2];
    s32 sphereByteOffset;
    s32 centerByteOffset;
    u8 *collision;
    u8 *sphereBase;
    f32 zero;
    u16 flags;
    Vec3F *worldCenters;
    Vec3F *worldOffsets;
    u32 sphereIndex;

    collision = *((u8 **) (object + COLLISION_OBJECT_STATE));
    if ((*((u8 *) (collision + COLLISION_SPHERE_COUNT))) != 0)
    {
        zero = 0.0f;
        do { sphereIndex = 0; worldCenters = D_801ED6EC; } while (0);
        worldOffsets = D_801ED68C;
        do
        {
            Vec3F *worldCenter = (Vec3F *) (((u8 *) worldCenters) + (sphereIndex * sizeof(Vec3F)));
            Vec3F *worldOffset = (Vec3F *) (((u8 *) worldOffsets) + (sphereIndex * sizeof(Vec3F)));
            centerByteOffset = (sphereIndex * sizeof(ObjectCollisionSphere)) + COLLISION_SPHERES_START;
            sphereByteOffset = sphereIndex * sizeof(ObjectCollisionSphere);
            sphereBase = collision + sphereByteOffset;
            flags = *((u16 *) (sphereBase + COLLISION_FIRST_SPHERE_FLAGS));
            if (flags & COLLISION_SPHERE_AT_OBJECT_ORIGIN)
            {
                *worldCenter = *((Vec3F *) (object + COLLISION_OBJECT_POSITION_X));
                worldOffset->z = zero;
                worldOffset->y = zero;
                worldOffset->x = zero;
            }
            else
                if (flags & COLLISION_SPHERE_WORLD_CENTER)
            {
                *worldCenter = *((Vec3F *) (sphereBase + COLLISION_SPHERES_START));
                worldOffset->x = worldCenter->x - (*((f32 *) (object + COLLISION_OBJECT_POSITION_X)));
                worldOffset->y = worldCenter->y - (*((f32 *) (object + COLLISION_OBJECT_POSITION_Y)));
                worldOffset->z = worldCenter->z - (*((f32 *) (object + COLLISION_OBJECT_POSITION_Z)));
            }
            else
            {
                func_801499A0((s32) worldOffset, (s32) (collision + centerByteOffset), (s32) (object + COLLISION_OBJECT_QUATERNION));
                worldCenter->x = worldOffset->x + (*((f32 *) (object + COLLISION_OBJECT_POSITION_X)));
                worldCenter->y = worldOffset->y + (*((f32 *) (object + COLLISION_OBJECT_POSITION_Y)));
                worldCenter->z = worldOffset->z + (*((f32 *) (object + COLLISION_OBJECT_POSITION_Z)));
            }
            sphereIndex++;
            collision = *((u8 **) (object + COLLISION_OBJECT_STATE));
        }
        while (sphereIndex < (*((u8 *) (collision + COLLISION_SPHERE_COUNT))));
    }
}

extern s32 D_8026A22C;
extern s32 D_8026A14C;
extern s32 D_8026A13C;
extern s32 D_8026A064;
extern s32 D_8026A060;
extern s32 D_8026A054;
extern s32 D_80269F84;
extern s32 D_80269F80;
extern s32 D_80269F88;

/* Original compiler padding. */
const u32 D_8015C34C_padding[] __attribute__((section(".text"))) = {
    0x00001700
};

extern const f32 D_801071E4;
extern s8 D_801EFC80[];

/* Build a quaternion from Euler angles in the configured axis order. */
void func_8015C350(u8 *outQuaternion, u8 *eulerAngles) {
    AxisAngle axisAngle;
    QuaternionComponents axisQuaternion;
    s32 rotationIndex;

    *(Quaternion *)outQuaternion = *(Quaternion *)&D_801ED3D0;
    for (rotationIndex = 0; rotationIndex < EULER_AXIS_COUNT; rotationIndex++) {
        if (((f32 *)eulerAngles)[D_801EFC80[rotationIndex]] != 0.0f) {
            switch (D_801EFC80[rotationIndex]) {
                case AXIS_ANGLE_X:
                    axisAngle[AXIS_ANGLE_X] = D_801071E4;
                    axisAngle[AXIS_ANGLE_Y] = 0.0f;
                    axisAngle[AXIS_ANGLE_Z] = 0.0f;
                    break;
                case AXIS_ANGLE_Y:
                    axisAngle[AXIS_ANGLE_X] = 0.0f;
                    axisAngle[AXIS_ANGLE_Y] = D_801071E4;
                    axisAngle[AXIS_ANGLE_Z] = 0.0f;
                    break;
                case AXIS_ANGLE_Z:
                    axisAngle[AXIS_ANGLE_X] = 0.0f;
                    axisAngle[AXIS_ANGLE_Y] = 0.0f;
                    axisAngle[AXIS_ANGLE_Z] = D_801071E4;
                    break;
            }
            axisAngle[AXIS_ANGLE_RADIANS] = ((f32 *)eulerAngles)[D_801EFC80[rotationIndex]];
            func_80148C3C(axisQuaternion, axisAngle);
            func_801488C0((Quaternion *)outQuaternion, (f32 *)outQuaternion, axisQuaternion);
        }
    }
}

/* Returns 1 when D_8028FBFB is clear, D_8029F9A4 points at the player actor (D_802902D8), and the player's
 * current animation (s16 at D_802903AC + 4) is one of 3, 5, 0xB, 0xC, 0xE, 0xF, 0x10, 0x21 or 0x2B; else 0. */
s32 func_8015C4C8(void) {
    s16 anim;
    if (D_8028FBFB == 0) {
        if (D_8029F9A4 == (s32)&D_802902D8) {
            anim = *(s16 *)(D_802903AC + 4);
            if (anim == 3 || anim == 5) {
                return 1;
            }
            if ((u16)(anim - 0xB) < 2) { /* 0xB or 0xC */
                return 1;
            }
            if ((u16)(anim - 0xE) < 2) { /* 0xE or 0xF */
                return 1;
            }
            if (anim == 0x10 || anim == 0x2B) {
                return 1;
            }
            if (anim == 0x21) {
                return 1;
            }
        }
    }
    return 0;
}

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

/* Allocate and register each model sprite, adjust small textures once, then visit child and sibling groups. */
void func_8015C580(SprGroup *group) {
    s32 entryIndex;
    SprNode *sprite;

    if (group->count > 0) {
        for (entryIndex = 0; entryIndex < group->count; entryIndex++) {
            s32 smallTextureSize = MODEL_SPRITE_SMALL_TEXTURE_SIZE;
            sprite = func_8013FCDC(MODEL_SPRITE_ALLOCATION_SIZE, 1, (s32 *)D_801071E8);
            sprite->tex = group->entries[entryIndex].tex;
            *(Vec3F *)sprite->v = *(Vec3F *)&D_801ED3C4;
            if (!(group->entries[entryIndex].flags & MODEL_SPRITE_SIZE_ADJUSTED)) {
                group->entries[entryIndex].flags |= MODEL_SPRITE_SIZE_ADJUSTED;
                if (sprite->tex->w == smallTextureSize) {
                    group->entries[entryIndex].unk0E *= 2;
                }
                if (sprite->tex->h == smallTextureSize) {
                    group->entries[entryIndex].unk10 *= 2;
                }
            }
            sprite->r = MODEL_SPRITE_COLOR_MAX;
            sprite->g = MODEL_SPRITE_COLOR_MAX;
            sprite->b = MODEL_SPRITE_COLOR_MAX;
            sprite->a = MODEL_SPRITE_DEFAULT_ALPHA;
            if (group->unk0D < MODEL_SPRITE_COLOR_MAX) {
                sprite->unk21 = 1;
            } else {
                sprite->unk21 = 0;
            }
            sprite->ox = -(s32)sprite->tex->w / 2;
            sprite->oy = -(s32)sprite->tex->h / 2;
            func_8014AC1C(sprite, 0);
            group->entries[entryIndex].node = (u8 *)sprite;
        }
    }
    if (group->next != 0) {
        func_8015C580(group->next);
    }
    if (group->next2 != 0) {
        func_8015C580(group->next2);
    }
}

static inline s32 *func_8015C758_clear(s32 *p) {
    *p = 0;
    return p - 0x39;
}

/* Empties the three object lists: each sentinel's links point back at itself
 * and its count (at sentinel + 0xE4) is zeroed.
 *   primary list:   sentinel D_8026A148, next/prev at +0x00/+0x04, count D_8026A22C;
 *   secondary list: sentinel D_8026A058, next/prev at +0x08/+0x0C, count D_8026A13C;
 *   render-sorted:  sentinel D_80269F70, first/last at +0x10/+0x14, count D_8026A054,
 *                   sort distance (+0x18) D_80269F88 cleared.
 * Both arms are identical: the sign test on the uninitialized pointer is merged
 * away by the compiler and only shapes register allocation. */
void func_8015C758(void)
{
  s32 *count;
  s32 *sentinel;
  int countOffset;
  if (count)
  {
    count = &D_8026A22C;
    sentinel = (s32 *) (((u8 *) count) - 0xE4);
    *count = 0;
    D_8026A14C = (s32) sentinel;
    *sentinel = (s32) sentinel;
    count = &D_8026A13C;
    *count = 0;
    count = (s32 *) (((u8 *) count) - 0xE4);
    D_8026A064 = (s32) count;
    D_8026A060 = (s32) count;
    count = &D_8026A054;
    *count = 0;
    countOffset = 0xE4;
    count = (s32 *) (((u8 *) count) - countOffset);
    D_80269F84 = (s32) count;
    D_80269F80 = (s32) count;
    D_80269F88 = 0;
  }
  else
  {
    count = &D_8026A22C;
    sentinel = (s32 *) (((u8 *) count) - 0xE4);
    *count = 0;
    D_8026A14C = (s32) sentinel;
    *sentinel = (s32) sentinel;
    count = &D_8026A13C;
    *count = 0;
    count = (s32 *) (((u8 *) count) - 0xE4);
    D_8026A064 = (s32) count;
    D_8026A060 = (s32) count;
    count = &D_8026A054;
    *count = 0;
    countOffset = 0xE4;
    count = (s32 *) (((u8 *) count) - countOffset);
    D_80269F84 = (s32) count;
    D_80269F80 = (s32) count;
    D_80269F88 = 0;
  }
}

/*
 * Insert obj into the render list sorted by ascending squared distance
 * (unk018, f32 bits). The list is circular through a sentinel node that
 * sits 0xE4 bytes before the count D_8026A054; unk010 / unk014 are
 * next / previous, and D_80269F84 is the sentinel's previous (last) link.
 */
void func_8015C7C4(ObjectNode *obj) {
    ObjectNode *node;
    ObjectNode *end;
    f32 dist;
    s32 *count = &D_8026A054;
    s32 *countAgain;

    node = (ObjectNode *)((u8 *)count - 0xE4); /* list sentinel */
    if (*count != 0) {
        /* Both arms are the same; the split is needed for the match. */
        if ((s32)count < 0) {
            if (node == (ObjectNode *)D_80269F84) goto insert;
        } else {
            if (node == (ObjectNode *)D_80269F84) goto insert;
        }
        dist = *(f32 *)&obj->unk018;
        end = (ObjectNode *)node->unk014;
        do {
            if (dist < *(f32 *)&node->unk018) goto insert;
            node = (ObjectNode *)node->unk010;
        } while (node != end);
    }
insert:
    /* Link obj in just before node. */
    countAgain = &D_8026A054;
    (*countAgain)++;
    obj->unk010 = (s32)node;
    obj->unk014 = node->unk014;
    ((ObjectNode *)node->unk014)->unk010 = (s32)obj;
    node->unk014 = (s32)obj;
}

/* Add an object to the active lists, unless it is already in them. It goes
 * at the tail of the secondary list (D_8026A060, counted by D_8026A13C)
 * unless its flag 4 is set, and builds its model sprites (func_8015C580).
 * It goes at the front of the main list (sentinel D_8026A148, counted by
 * D_8026A22C), or at its end when the model's flag 2 is set. */
void func_8015C840(ObjectNode *object) {
    ObjectNode *insertBefore = D_8026A148.next;
    ObjectNode *secondaryTail;
    ObjectNode *model;
    s32 *mainCount;
    s32 secondaryCount;

    if (object->next == 0) {
        if (!(object->unk028 & 4)) {
            secondaryCount = D_8026A13C;
            secondaryTail = (ObjectNode *)D_8026A060;
            D_8026A13C = secondaryCount + 1;
            object->unk008 = (s32)secondaryTail;
            object->unk00C = *(volatile s32 *)&secondaryTail->unk00C;
            ((ObjectNode *)*(volatile s32 *)&secondaryTail->unk00C)->unk008 = (s32)object;
            secondaryTail->unk00C = (s32)object;
        }
        if (object->meshRef != 0) {
            model = (ObjectNode *)((ObjectNode *)object->meshRef)->unk00C;
            if (*(u16 *)((u8 *)model + 0x32) & 2) {
                insertBefore = &D_8026A148;
            }
            if (model != 0) {
                func_8015C580(model);
            }
        }
        mainCount = &D_8026A22C;
        *mainCount = *mainCount + 1;
        object->next = insertBefore;
        object->unk004 = insertBefore->unk004;
        ((ObjectNode *)insertBefore->unk004)->next = object;
        insertBefore->unk004 = (s32)object;
    }
}

void func_8015C924(void *objectData) {
    u8 *object = objectData;
    f32 centerDelta[4];
    f32 boundingRadius;
    f32 sphereExtent;
    s32 sphereIndex;
    s32 sphereOffset;

    /* Enclose every collision sphere in a radius about the object's position. */
    boundingRadius = 0.0f;
    sphereIndex = 0;
    if (sphereIndex < *(u8 *)(*(u8 **)(object + COLLISION_OBJECT_STATE) + COLLISION_SPHERE_COUNT)) {
        sphereOffset = 0;
        do {
            if (*(u16 *)(*(u8 **)(object + COLLISION_OBJECT_STATE) + sphereOffset + COLLISION_FIRST_SPHERE_FLAGS) & COLLISION_SPHERE_WORLD_CENTER) {
                centerDelta[0] = *(f32 *)(object + COLLISION_OBJECT_POSITION_X) - *(f32 *)(*(u8 **)(object + COLLISION_OBJECT_STATE) + sphereOffset + COLLISION_SPHERES_START);
                centerDelta[1] = *(f32 *)(object + COLLISION_OBJECT_POSITION_Y) - *(f32 *)((u8 *)(sphereOffset + (s32)*(u8 **)(object + COLLISION_OBJECT_STATE)) + COLLISION_FIRST_CENTER_Y);
                centerDelta[2] = *(f32 *)(object + COLLISION_OBJECT_POSITION_Z) - *(f32 *)((u8 *)(sphereOffset + (s32)*(u8 **)(object + COLLISION_OBJECT_STATE)) + COLLISION_FIRST_CENTER_Z);
                sphereExtent = sqrtf(centerDelta[0] * centerDelta[0] + centerDelta[1] * centerDelta[1] + centerDelta[2] * centerDelta[2]);
            } else {
                f32 *localCenter = (f32 *)(*(u8 **)(object + COLLISION_OBJECT_STATE) + sphereOffset + COLLISION_SPHERES_START);
                sphereExtent = sqrtf(localCenter[0] * localCenter[0] + localCenter[1] * localCenter[1] + localCenter[2] * localCenter[2]);
            }
            sphereExtent += *(f32 *)(*(u8 **)(object + COLLISION_OBJECT_STATE) + sphereOffset + COLLISION_FIRST_RADIUS);
            if (boundingRadius < sphereExtent) {
                boundingRadius = sphereExtent;
            }
            sphereIndex++;
            sphereOffset += COLLISION_SPHERE_STRIDE;
        } while (sphereIndex < *(u8 *)(*(u8 **)(object + COLLISION_OBJECT_STATE) + COLLISION_SPHERE_COUNT));
    }
    *(f32 *)(object + COLLISION_OBJECT_BOUNDING_RADIUS) = boundingRadius;
}

/* model_unlink_sprites: unlink every sprite of a model node and its children/siblings, freeing them too when freeSprites is set. */
void func_8015CA7C(s32 node, s32 freeSprites) {
    s32 i;

    if (*(s32 *)(node + MODEL_NODE_SPRITES) != 0) {
        for (i = 0; i < *(s32 *)(node + MODEL_NODE_SPRITE_COUNT); i++) {
            s32 sprite = *(s32 *)(*(s32 *)(node + MODEL_NODE_SPRITES) + i * MODEL_SPRITE_ENTRY_BYTES + MODEL_SPRITE_NODE);
            if (sprite != 0) {
                func_8014ACB4(sprite); /* world_sprite_unlink */
            }
            if (freeSprites != 0) {
                func_80141720((s32 *)(*(s32 *)(node + MODEL_NODE_SPRITES) + i * MODEL_SPRITE_ENTRY_BYTES + MODEL_SPRITE_NODE));
            }
        }
    }
    if (*(s32 *)(node + MODEL_NODE_CHILD_OFFSET) != 0) {
        func_8015CA7C(*(s32 *)(node + MODEL_NODE_CHILD_OFFSET), freeSprites);
    }
    if (*(s32 *)(node + MODEL_NODE_SIBLING_OFFSET) != 0) {
        func_8015CA7C(*(s32 *)(node + MODEL_NODE_SIBLING_OFFSET), freeSprites);
    }
}

/* Remove an object from both active lists and unlink its model sprites without freeing them. */
void func_8015CB44(ObjectNode *object) {
    s32 spriteIndex;
    s32 *modelNode;
    s32 *modelRoot;

    if (object->next != 0) {
        s32 *listCount;
        *(s32 *)object->unk004 = (s32)object->next;
        object->next->unk004 = object->unk004;
        listCount = &D_8026A22C;
        *listCount = *listCount - 1;
        object->next = 0;
    }
    if (object->unk008 != 0) {
        s32 *listCount;
        *(s32 *)(object->unk00C + OBJECT_SECONDARY_NEXT_OFFSET) = object->unk008;
        *(s32 *)(object->unk008 + OBJECT_SECONDARY_PREV_OFFSET) = object->unk00C;
        listCount = &D_8026A13C;
        *listCount = *listCount - 1;
        object->unk008 = 0;
    }
    modelRoot = (s32 *)object->meshRef;
    if (modelRoot != 0) {
        modelRoot = (s32 *)modelRoot[ACTOR_MODEL_ROOT_WORD];
        if (modelRoot != 0) {
            modelNode = modelRoot;
            if (modelNode[ACTOR_MODEL_ITEMS_WORD] != 0) {
                for (spriteIndex = 0; spriteIndex < modelNode[ACTOR_MODEL_ITEM_COUNT_WORD]; spriteIndex++) {
                    s32 sprite = *(s32 *)(modelNode[ACTOR_MODEL_ITEMS_WORD] + spriteIndex * MODEL_SPRITE_ENTRY_BYTES + MODEL_SPRITE_NODE);
                    if (sprite != 0) {
                        func_8014ACB4(sprite);
                    }
                }
            }
            if (modelNode[ACTOR_MODEL_CHILD_WORD] != 0) {
                func_8015CA7C(modelNode[ACTOR_MODEL_CHILD_WORD], 0);
            }
            if (modelNode[ACTOR_MODEL_SIBLING_WORD] != 0) {
                func_8015CA7C(modelNode[ACTOR_MODEL_SIBLING_WORD], 0);
            }
        }
    }
}

/* Merges vector `add` into vector `total`. If they point in opposing directions
 * (negative dot product) they are summed; otherwise each axis keeps whichever
 * of the two reaches further in add's direction, so overlapping pushes do not stack. */
void func_8015CC70(f32 *total, f32 *add) {
    s32 end;
    f32 zero;

    if (total[0] * add[0] + total[1] * add[1] + total[2] * add[2] < 0.0f) {
        total[0] = total[0] + add[0];
        total[1] = total[1] + add[1];
        total[2] = total[2] + add[2];
    } else {
        zero = 0.0f;
        end = (s32)(total + 3);
        do {
            if ((zero < *add && *total < *add) || (*add < zero && *add < *total)) {
                *total = *add;
            }
            total++;
            add++;
        } while ((s32)total < end);
    }
}

/*
 * vec -= delta. When delta points against vec (negative dot product) it is a plain subtraction;
 * otherwise each component is reduced towards zero and set to 0 instead of crossing it.
 */
void func_8015CD4C(f32 *vec, f32 *delta) {
    f32 *comp = vec;
    f32 d;

    if (vec[0] * delta[0] + vec[1] * delta[1] + vec[2] * delta[2] < 0.0f) {
        vec[0] = vec[0] - delta[0];
        vec[1] = vec[1] - delta[1];
        vec[2] = vec[2] - delta[2];
        return;
    }
    do {
        d = *delta;
        if (0.0f < d && *comp < d) {
            *(s32 *)comp = 0;
        } else if (d < 0.0f && d < *comp) {
            *(s32 *)comp = 0;
        } else {
            *comp = *comp - *delta;
        }
        comp++;
        delta++;
    } while ((s32)comp < (s32)(vec + 3));
}

extern f32 D_801071F4;

/* Add or replace surface motion using a rotated displacement or a distance-limited radial step. */
void func_8015CE38(Vec3F *outMotion, u8 *platform, f32 *position, s32 replaceOutput) { Vec3F displacement; f32 distanceSquared; f32 distanceOrStep; f32 radialStep; f32 inverseDistance; if (*(f32 *)(platform + PLATFORM_SURFACE_RADIAL_STEP) == 0.0f) {
        if (*(s32 *)(platform + PLATFORM_ROTATION) != 0) {
            func_801499A0((s32)&displacement, (s32)(platform + PLATFORM_SURFACE_MOTION_VECTOR), (s32)(platform + PLATFORM_QUATERNION));
        } else {
            displacement = *(Vec3F *)(platform + PLATFORM_SURFACE_MOTION_VECTOR);
        }
    } else {
        func_80149374((f32 *)&displacement, (f32 *)(platform + PLATFORM_POSITION), (f32 *)(platform + PLATFORM_SURFACE_MOTION_VECTOR));
        func_80149428((f32 *)&displacement, (f32 *)&displacement, position);
        distanceSquared = displacement.x * displacement.x + displacement.z * displacement.z;
        distanceOrStep = __builtin_sqrtf(distanceSquared);
        if (distanceOrStep == 0.0f) {
            return;
        }
        inverseDistance = D_801071F4 / distanceOrStep;
        displacement.x = displacement.x * inverseDistance;
        displacement.z = displacement.z * inverseDistance;
        radialStep = *(f32 *)(platform + PLATFORM_SURFACE_RADIAL_STEP);
        if (0.0f < radialStep) {
            distanceOrStep = (radialStep < distanceOrStep) ? radialStep : distanceOrStep;
        } else {
            distanceOrStep = (radialStep < -distanceOrStep) ? -distanceOrStep : radialStep;
        }
        displacement.x = displacement.x * distanceOrStep;
        displacement.z = displacement.z * distanceOrStep;
        displacement.y = 0.0f;
    }
    if (replaceOutput != 0) {
        *outMotion = displacement;
    } else {
        outMotion->x += displacement.x;
        outMotion->y += displacement.y;
        outMotion->z += displacement.z;
    }
}

static inline void func_8015D020_rot(Quat801488C0 *o, f32 *axis)
{
  Quat801488C0 q;
  func_80148C3C(q.v, axis);
  func_801488C0(o, o->v, q.v);
}

void func_8015D020(u8 *arg0)
{
/* Per-frame physics/motion update for a rolling object (player D_802902D8 or ball): settles the squash/stretch scale at +0xD4, clamps velocity (+0x58) to the max speed in the params at +0xD0, runs collision (func_8015EE6C/func_8015E0A0), applies slope and ground-contact flags (+0xD8 contact block, byte 392 = on ground), then rebuilds the orientation quaternion at +0x9C from the per-axis spin at +0x78. (work split: the definition continues below this guard; settle loop and contact scan share the counter _59; zero compare loop-weighted) */
#if 0
}
#endif
  extern const f32 D_801071FC;
  extern const f64 D_80107200;
  extern const f32 D_801071F8;
  extern const f64 D_80107208;
  extern const f32 D_80107210;
  extern const f32 D_80107214;
  extern const f32 D_80107218;
  extern f32 D_80107224;
  extern const f32 D_80107228;
  extern const f32 D_80107234;
  extern const f64 D_80107238;
  extern const f32 D_80107240;
  f32 new_var3;
  extern const f32 D_80107248;
  extern const f32 D_80107254;
  extern const f64 D_80107258;
  extern const f32 D_80107260;
  extern const f32 D_80107264;
  extern const f64 D_80107268;
  extern const f64 D_80107270;
  extern const f32 D_80107278;
  extern f32 D_801ED3C8;
  extern f32 D_801ED3CC;
  extern f32 D_801ED680;
  extern s32 D_801ED74C;
  extern s32 D_801ED754;
  extern s32 D_801ED758;
  extern f32 D_801ED75C;
  extern u8 D_801EEB60;
  int new_var4;
  extern f32 D_80290080;
  extern f32 D_80290088;
  extern u8 * volatile D_80290090;
  extern f32 D_80290098;
  extern f32 D_8029009C;
  extern f32 D_802900A0;
  extern s32 D_802900A4;
  extern f32 D_80290330;
  extern f32 D_80290334;
  extern f32 D_80290338;
  extern struct 
  {
    s32 flags;
    u8 pad[0x38];
    s16 x;
    u8 pad2[0x2C2];
  } D_80299964[];
  extern f32 D_8029F9D8;
  void func_8015E0A0(void *);
  void func_8015EE6C(s32 arg0);
  s32 func_8015F098(u8 *arg0);
  void func_8015F910();
  float new_var2;
  void func_80191548(s32 *arg0, s32 arg1);
  f32 sp28[4];
  Quat801488C0 *_0;
  f32 _1;
  f32 _2;
  f32 _3;
  f32 _4;
  f32 _5;
  f32 _6;
  f32 _7;
  f32 _8;
  f32 _9;
  f32 _10;
  f32 _11;
  f32 _12;
  f32 _13;
  f32 _14;
  f32 _15;
  f32 _16;
  f32 _17;
  f32 _18;
  f32 _19;
  f32 _20;
  f32 _21;
  f32 _22;
  f32 _23;
  f32 _24;
  f32 _25;
  f32 _26;
  f32 _27;
  f32 _28;
  f32 _29;
  f32 _30;
  f32 _31;
  f32 _32;
  f32 _33;
  f32 _34;
  f32 _35;
  f32 _36;
  f32 _37;
  f32 _38;
  f32 _39;
  f32 _40;
  f32 _41;
  f32 _42;
  f32 _43;
  f32 _44;
  f32 _45;
  f32 _46;
  f32 _47;
  f64 _48;
  s16 _49;
  s16 _50;
  s32 _51;
  s32 _52;
  s32 _53;
  s32 _54;
  s32 _55;
  s32 _56;
  s32 _57;
  s32 _59;
  s8 *_60;
  s8 _61;
  s8 _62;
  s8 _63;
  u16 _64;
  void **_65;
  void *_66;
  void *_67;
  void *_68;
  void *_69;
  void *_70;
  void *_71;
  void *_72;
  u8 *new_var6;
  void *_73;
  void *_74;
  void *_75;
  f32 *new_var5;
  void *_76;
  void *_77;
  void *_78;
  void *_79;
  f32 *new_var;
  void *_80;
  void *_81;
  void *_82;
  void *_83;
  void *_84;
  void *_85;
  void *_86;
  void *_87;
  void *_88;
  void *_89;
  void *_90;
  void *_91;
  void *_92;
  void *_93;
  void *_94;
  void *_95;
  if ((*((f32 *) (((u8 *) arg0) + 56))) < D_801071F8)
  {
    *((f32 *) (((u8 *) arg0) + 56)) = D_801071F8;
  }
  if ((*((s8 *) (((u8 *) arg0) + 34))) == 2)
  {
    *((u8 *) (((u8 *) arg0) + 34)) = 0;
    func_8015CB44(arg0);
    if ((*((s32 *) (((u8 *) arg0) + 212))) != ((void *) 0))
    {
      if (((*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) - (-212))))) + 2))) != (-1)) && (D_80299964[*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))].x != 0))
      {
        func_80191548(arg0, 0x3A);
        new_var4 = (*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))) * 0x300;
        func_80151FD0(arg0 + 0xC8, func_80139CA0(D_801F00A8[*((s16 *) (((u8 *) (D_80299708 + new_var4)) + 0))]), D_801F00A8[*((s16 *) (((u8 *) (D_80299708 + ((*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))) * 0x300))) + 0))], 1);
        D_80299964[*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))].flags &= ~0x10;
        func_80195CD4(((*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))) * 0x300) + D_802996E8, *((s16 *) (((u8 *) arg0) + 32)));
        func_80197794(((*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))) * 0x300) + D_802996E8, 0, 1);
        *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 220)))) + 76)) = D_801071FC;
        *((u8 *) (((u8 *) arg0) + 34)) = 0;
        func_8015CB44(arg0);
        D_80299964[*((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 2))].x = 0;
      }
    }
  }
  else
  {
    if (((*((s32 *) (((u8 *) arg0) + 212))) != ((void *) 0)) && ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24))) != 0.0f))
    {
      _50 = *((s16 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 28));
              _56 = 0;
        if (_50 >= 0)
      {
        _44 = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 60));
        if (_44 > 0.0f)
        {
          _47 = func_80149724(_44, (_44 * D_80107200) + (_50 * 0xA), 0);
        }
        else
        {
          _47 = func_80149724(-_44, (_44 * D_80107208) + (_50 * 0xA), 0);
        }
        *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24)) = (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24))) * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 64)));
        _64 = *((u16 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 28));
        *((s16 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 28)) = _64 + 1;
        if ((((s16) _64) >= 5) && ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24))) < (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 56)))))
        {
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24)) = 0.0f;
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 16)) = D_80107224;
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 20)) = D_80107224;
        }
        else
        {
          _47 = _47 * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24)));
_35 = D_80107210 - _47;
*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 16)) = _47 + D_80107210;
          new_var5 = (f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 20);
          *new_var5 = _35;
        }
      }
      else
      {
          _59 = 0;
          do
          {
            _54 = _59 * 4;
            _14 = *((f32 *) (((u8 *) (_54 + (*((s32 *) (((u8 *) arg0) + 212))))) + 16));
            *((f32 *) (((u8 *) (_54 + (*((s32 *) (((u8 *) arg0) + 212))))) + 16)) = _14 - ((_14 - D_80107214) / D_80107218);
            _36 = (*((f32 *) (((u8 *) (_54 + (*((s32 *) (((u8 *) arg0) + 212))))) + 16))) - D_80107214;
            do { if (!(_36 > 0.0f)) _36 = -_36; } while (0);
            {
              const f32 *k = &D_80107218;
              if (_36 < *((const f64 *) (k + 1)))
              {
                _56 += 1;
              }
            }
            _59 += 1;
          }
          while (_59 < 2);
        if (_56 == 2)
        {
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 24)) = 0.0f;
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 16)) = D_80107224;
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 20)) = D_80107224;
        }
      }
    }
    *((Words3 *) (arg0 + 100)) = *((Words3 *) (arg0 + 88));
    _53 = *((s32 *) (((u8 *) arg0) + 40));
    if ((_53 & 0x8000) || ((!(_53 & 0x01000000)) && ((*((s16 *) (((u8 *) arg0) + 32))) == 4)))
    {
      _38 = sqrtf((((*((f32 *) (((u8 *) arg0) + 88))) * (*((f32 *) (((u8 *) arg0) + 88)))) + ((*((f32 *) (((u8 *) arg0) + 92))) * (*((f32 *) (((u8 *) arg0) + 92))))) + ((*((f32 *) (((u8 *) arg0) + 96))) * (*((f32 *) (((u8 *) arg0) + 96)))));
      _22 = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8));
      _47 = _38;
      if (_22 < _47)
      {
        *((f32 *) (((u8 *) arg0) + 88)) = (*((f32 *) (((u8 *) arg0) + 88))) * (_22 / _47);
        *((f32 *) (((u8 *) arg0) + 92)) = (*((f32 *) (((u8 *) arg0) + 92))) * ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8))) / _47);
        *((f32 *) (((u8 *) arg0) + 96)) = (*((f32 *) (((u8 *) arg0) + 96))) * ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8))) / _47);
      }
    }
    else
      if (!(_53 & 0x01000000))
    {
      _37 = sqrtf(((*((f32 *) (((u8 *) arg0) + 88))) * (*((f32 *) (((u8 *) arg0) + 88)))) + ((*((f32 *) (((u8 *) arg0) + 96))) * (*((f32 *) (((u8 *) arg0) + 96)))));
      _20 = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8));
      _47 = _37;
      if (_20 < _47)
      {
        *((f32 *) (((u8 *) arg0) + 88)) = (*((f32 *) (((u8 *) arg0) + 88))) * (_20 / _47);
        *((f32 *) (((u8 *) arg0) + 96)) = (*((f32 *) (((u8 *) arg0) + 96))) * ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8))) / _47);
      }
    }
    _93 = *((s32 *) (((u8 *) arg0) + 216));
    if (_93 != ((void *) 0))
    {
      for (_57 = 0; _57 < (*((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 395))); _57++)
      {
        _94 = (*((s32 *) (((u8 *) arg0) + 216))) + (_57 * 0x24);
        if ((*((f32 *) (((u8 *) _94) + 116))) != (*((f32 *) (((u8 *) _94) + 112))))
        {
          *((f32 *) (((u8 *) _94) + 112)) = (*((f32 *) (((u8 *) _94) + 112))) + (((((((*((f32 *) (((u8 *) ((*((s32 *) (((u8 *) arg0) + 216))) + (_57 * 0x24))) + 116))) - (*((f32 *) (((u8 *) ((*((s32 *) (((u8 *) arg0) + 216))) + (_57 * 0x24))) + 112)))) / D_80107228) < (-(*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 76))))) ? (-(*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 76)))) : (((*((f32 *) (((u8 *) ((*((s32 *) (((u8 *) arg0) + 216))) + (_57 * 0x24))) + 116))) - (*((f32 *) (((u8 *) ((*((s32 *) (((u8 *) arg0) + 216))) + (3 * (12 * _57)))) + 112)))) / D_80107228)) < (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 76)))) ? (((((*((f32 *) ((new_var6 = (u8 *) ((*((s32 *) (((u8 *) arg0) + 216))) + (_57 * 0x24))) + 116))) - (*((f32 *) (new_var6 + 112)))) / D_80107228) < (-(*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 76))))) ? (-(*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 76)))) : (((*((f32 *) (new_var6 + 116))) - (*((f32 *) (new_var6 + 112)))) / D_80107228)) : (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 76))));
        }
      }

      func_8015F910(arg0 + 0x34, arg0 + 0x4C, arg0 + 0x58, arg0 + 0x78, arg0 + 0x84, arg0 + 0x9C, *((s8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 37)), *((s32 *) (((u8 *) arg0) + 40)), *((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 376)), *((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 380)));
      *((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 394)) = 0;
    }
    _88 = *((s32 *) (((u8 *) arg0) + 212));
    if ((((_88 == ((void *) 0)) || ((*((s32 *) (((u8 *) _88) + 12))) == 0)) || ((*((s16 *) (((u8 *) arg0) + 32))) == 4)) || (func_8015F098(arg0) == 0))
    {
      if (((arg0 == (&D_802902D8)) && ((*((u8 **) (&D_80290090))) != ((void *) 0))) && ((*((s16 *) (((u8 *) (*((s32 *) (((u8 *) (*((u8 **) (&D_80290090)))) + 80)))) + 26))) > 0))
      {
        if ((*((s16 *) (((u8 *) D_802903AC) + 4))) == 3)
        {
          D_8029F9D0 = (D_8029F9D4 = (D_8029F9D8 = 0.0f));
        }
        else
        {
          D_80290330 = (D_80290334 = (D_80290338 = 0.0f));
        }
      }
      func_8015EE6C(arg0);
      func_8015E0A0(arg0);
      if (((*((s32 *) (((u8 *) arg0) + 40))) & 0x8000) || ((*((s16 *) (((u8 *) arg0) + 32))) == 4))
      {
        _30 = *((f32 *) (((u8 *) arg0) + 88));
        _26 = *((f32 *) (((u8 *) arg0) + 92));
        _5 = *((f32 *) (((u8 *) arg0) + 96));
        _10 = ((_30 * _30) + (_26 * _26)) + (_5 * _5);
        _40 = sqrtf(_10);
        _47 = _40;
        if (!((*((s32 *) (((u8 *) arg0) + 40))) & 0x01000000))
        {
          _15 = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8));
          if (_15 < _47)
          {
            new_var = (f32 *) (((u8 *) arg0) + 92);
            *((f32 *) (((u8 *) arg0) + 88)) = (*((f32 *) (((u8 *) arg0) + 88))) * (_15 / _47);
            _43 = (*new_var) * ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8))) / _47);
            *new_var = _43;
            *((f32 *) (((u8 *) arg0) + 96)) = (*((f32 *) (((u8 *) arg0) + 96))) * ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8))) / _47);
          }
        }
      }
      else
      {
        _16 = *((f32 *) (((u8 *) arg0) + 88));
        _6 = *((f32 *) (((u8 *) arg0) + 96));
        _11 = (_16 * _16) + (_6 * _6);
        _41 = sqrtf(_11);
        _47 = _41;
        if (!((*((s32 *) (((u8 *) arg0) + 40))) & 0x01000000))
        {
          _17 = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8));
          if (_17 < _47)
          {
            *((f32 *) (((u8 *) arg0) + 88)) = (*((f32 *) (((u8 *) arg0) + 88))) * (_17 / _47);
            *((f32 *) (((u8 *) arg0) + 96)) = (*((f32 *) (((u8 *) arg0) + 96))) * ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 208)))) + 8))) / _47);

          }
        }
      }
      if (((arg0 != (&D_802902D8)) || ((*((s16 *) (((u8 *) D_802903AC) + 4))) != 0x23)) && ((*((s32 *) (((u8 *) arg0) + 40))) & 0x10))
      {
        _77 = *((s32 *) (((u8 *) arg0) + 208));
        if ((_47 < ((*((f32 *) (((u8 *) _77) + 16))) * (*((f64 *) (((u8 *) (&D_80107228)) + 4))))) && (((_47 == 0.0f) || ((*((f32 *) (((u8 *) arg0) + 112))) < (*((f32 *) (((u8 *) _77) + 24))))) || ((((_78 = *((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 0)), _78 != ((void *) 0))) && ((*((f32 *) (((u8 *) (&D_801ED758)) + ((*((u8 *) (((u8 *) _78) + 116))) * 0x1C)))) != D_80107234)) && (arg0 != (&D_802902D8)))))
        {
          _73 = *((s32 *) (((u8 *) arg0) + 216));
          _68 = *((s32 *) (((u8 *) _73) + 0));
          if (_68 != ((void *) 0))
          {
            _69 = *((s32 *) (((u8 *) arg0) + 208));
            _51 = (*((u8 *) (((u8 *) _68) + 116))) * 0x1C;
            _34 = (*((f32 *) (((u8 *) _69) + 16))) / (*((f32 *) (((u8 *) (&D_801ED754)) + _51)));
            if (((_47 < (_34 * D_80107238)) && (((double) (D_80107240 - ((D_80107240 - (_1 = *((f32 *) (((u8 *) _69) + 20)))) / (*((f32 *) (((u8 *) (&D_801ED758)) + _51)))))) < (*((f32 *) (((u8 *) _68) + 4))))) && ((*((u8 *) (((u8 *) _73) + 84))) == 1))
            {
              if (_47 < _34)
              {
                f32 t58, t5c, t60;
                *((f32 *) (((u8 *) arg0) + 88)) = (*((f32 *) (((u8 *) (&D_801ED3C4)) + 0))) - (*((f32 *) (((u8 *) _68) + 0)));
                new_var3 = D_801ED680;
                t58 = (*((volatile f32 *) (((u8 *) arg0) + 88))) * new_var3;
                *((f32 *) (((u8 *) arg0) + 92)) = D_801ED3C8 - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 0)))) + 4)));
                t5c = (*((volatile f32 *) (((u8 *) arg0) + 92))) * new_var3;
                *((f32 *) (((u8 *) arg0) + 96)) = D_801ED3CC - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 0)))) + 8)));
                t60 = (*((volatile f32 *) (((u8 *) arg0) + 96))) * new_var3;
                *((f32 *) (((u8 *) arg0) + 88)) = t58;
                *((f32 *) (((u8 *) arg0) + 92)) = t5c;
                *((f32 *) (((u8 *) arg0) + 96)) = t60;
              }
              else
              {
                f32 t58, t5c, t60;
                t58 = (*((f32 *) (((u8 *) arg0) + 88))) * (*((f64 *) (((u8 *) (&D_80107240)) + 4)));
                t5c = (*((f32 *) (((u8 *) arg0) + 92))) * (*((f64 *) (((u8 *) (&D_80107240)) + 4)));
                t60 = (*((f32 *) (((u8 *) arg0) + 96))) * (*((f64 *) (((u8 *) (&D_80107240)) + 4)));
                *((f32 *) (((u8 *) arg0) + 88)) = t58;
                *((f32 *) (((u8 *) arg0) + 92)) = t5c;
                *((f32 *) (((u8 *) arg0) + 96)) = t60;
              }
            }
          }
        }
      }
      if ((!((*((s32 *) (((u8 *) arg0) + 40))) & 0x01000000)) && ((*((f64 *) (((u8 *) (&D_80107248)) + 4))) < (*((f32 *) (((u8 *) arg0) + 92)))))
      {
        *((f32 *) (((u8 *) arg0) + 92)) = D_80107254;
      }
      _31 = *((f32 *) (((u8 *) arg0) + 88));
      _18 = *((f32 *) (((u8 *) arg0) + 92));
      _7 = *((f32 *) (((u8 *) arg0) + 96));
      _12 = ((_31 * _31) + (_18 * _18)) + (_7 * _7);
      _43 = sqrtf(_12);
      *((f32 *) (((u8 *) arg0) + 116)) = _43;
      if (((arg0 == (&D_802902D8)) && (D_80290300 & 0x8000)) && ((*((s32 *) (((u8 *) D_802903B0) + 0))) != ((void *) 0)))
      {
        *((u8 *) (((u8 *) D_802903B0) + 392)) = 1;
      }
      else
      {
        _95 = *((s32 *) (((u8 *) arg0) + 216));
        if (_95 != ((void *) 0))
        {
          *((u8 *) (((u8 *) _95) + 393)) = *((u8 *) (((u8 *) _95) + 392));
          if ((*((s32 *) (((u8 *) arg0) + 40))) & 0x10)
          {
            *((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 392)) = 0;
            _89 = *((s32 *) (((u8 *) arg0) + 216));
            _59 = 0;
            if (((*((s32 *) (((u8 *) _89) + 0))) == ((void *) 0)) && ((*((u8 *) (((u8 *) _89) + 394))) & 2))
            {
              *((u8 *) (((u8 *) _89) + 392)) = 1;
            }
            else
            {
              while ((((s32 *) (*((s32 *) (((u8 *) arg0) + 216))))[_59] != 0) & (_59 < 4))
              {
                _79 = (void *) ((s32 *) (*((s32 *) (((u8 *) arg0) + 216))))[_59];
                if (((*((f32 *) (((u8 *) _79) + 4))) < D_80107258) && (D_80107260 <= (*((f32 *) (((u8 *) (&D_801ED75C)) + (_55 = (*((u8 *) (((u8 *) _79) + 116))) * 0x1C))))))
                {
                  _59++;
                }
                else
                {
                  *((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 392)) = 1;
                  break;
                }
              }

            }
            if (arg0 == (&D_802902D8))
            {
              _49 = *((s16 *) (((u8 *) D_802903AC) + 4));
              if ((((_49 != 0x23) & (_49 != 7)) && (D_8029011E == 0)) && (((_80 = *((s32 *) (((u8 *) D_802903B0) + 0)), _80 == ((void *) 0))) || ((*((f32 *) (((u8 *) (&D_801ED74C)) + ((*((u8 *) (((u8 *) _80) + 116))) * 0x1C)))) <= D_80107264)))
              {
                D_80290348 = D_80290348 * D_80107268;
              }
              if ((((*((u8 *) (((u8 *) D_802903B0) + 392))) == 0) && ((*((u8 *) (((u8 *) D_802903B0) + 394))) != 0)) && (func_80148EBC(&D_8029030C, ((u8 *) (&D_8029030C)) + 0xC) < D_80107270))
              {
                *((u8 *) (((u8 *) D_802903B0) + 392)) = 1;
              }
            }
          }
          else
          {
            *((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 392)) = 0;
          }
        }
      }
      if ((*((s32 *) (((u8 *) arg0) + 212))) != ((void *) 0))
      {
        if (((*((s32 *) (((u8 *) arg0) + 216))) != ((void *) 0)) && ((*((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 212)))) + 12))) != 0))
        {
          *((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 392)) = 0;
          *((u8 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 216)))) + 394)) = 0;
        }
      }
      if (((arg0 == (&D_802902D8)) && ((*((s16 *) (((u8 *) D_802903AC) + 4))) != 0x23)) && ((*((u8 *) (((u8 *) D_802903B0) + 392))) != 0))
      {
        _72 = *((s32 *) (((u8 *) D_802903B0) + 0));
        if ((_72 != ((void *) 0)) && (((D_80290080 * (*((f32 *) (((u8 *) _72) + 0)))) + (D_80290088 * (*((f32 *) (((u8 *) _72) + 8))))) < 0.0f))
        {
          func_80148D50(arg0 + 0x58, _72, -D_801ED680);
        }
        if ((((*((s16 *) (((u8 *) D_802903AC) + 4))) != 0x1C) && (D_8028FBEA >= 3)) && ((*((u8 *) (((u8 *) D_802903AC) + 11))) == 0))
        {
          D_802900A4 = *((s32 *) (((u8 *) D_802903B0) + 376));
          _82 = *((s32 *) (((u8 *) D_802903B0) + 376));
          if (_82 != ((void *) 0))
          {
            D_80290098 = (*((f32 *) (((u8 *) (&D_8029030C)) + 0))) - (*((f32 *) (((u8 *) _82) + 180)));
            D_8029009C = D_80290310 - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) D_802903B0) + 376)))) + 184)));
            D_802900A0 = D_80290314 - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) D_802903B0) + 376)))) + 188)));
          }
          else
          {
            *((Words3 *) (&D_80290098)) = *((Words3 *) (&D_8029030C));
          }
        }
      }
      if (D_801EEB60 == 0)
      {
        *((f32 *) (((u8 *) arg0) + 116)) = (*((f32 *) (((u8 *) arg0) + 88)) = (*((f32 *) (((u8 *) arg0) + 92)) = (*((f32 *) (((u8 *) arg0) + 96)) = 0.0f)));
      }
      _0 = arg0 + 0x9C;
      if (!((*((s32 *) (((u8 *) arg0) + 40))) & 0x4000))
      {
        _74 = arg0 + 0x78;
              *_0 = *((Quat801488C0 *) (&D_801ED3D0));
      ;
      for (_52 = 0; _52 <= (3 - 1); _52++)
        {
          _63 = D_801EFC80[_52];
          if (((f32 *) _74)[_63] == 0.0f)
          {
            continue;
          }
          switch (_63)
          {
            case 0:
              sp28[0] = D_80107278;
              sp28[1] = 0.0f;
              sp28[2] = 0.0f;
              break;

            case 1:
              sp28[0] = 0.0f;
              sp28[1] = D_80107278;
              sp28[2] = 0.0f;
              break;

            case 2:
              sp28[0] = 0.0f;
              sp28[1] = 0.0f;
              sp28[2] = D_80107278;
              break;

          }

          sp28[3] = ((f32 *) _74)[D_801EFC80[_52]];
          func_8015D020_rot(_0, sp28);
        }

      }
    }
  }
}

/* Run collision detection, rolling updates, gravity, and slope sliding for a physics object.
 * Returns 1 if the object contacted a low-traction surface while slope mode (D_801EEB64) is active. */
s32 func_8015E0A0(void *objectData)
{
  int controllerOffset;
  Vec3F *sphereOffsets;
  f32 frictionThreshold;
  int isBallActionState;
  extern s32 D_802902D8;
  extern s32 D_8029F978;
  extern s32 D_8029F9A4;
  extern u8 *D_802903AC;
  extern u8 *D_80290090;
  extern f32 D_80290088;
  extern u8 *D_80290094;
  extern u8 *D_802900A8;
  extern s32 D_802900BC;
  extern s32 D_80290300;
  extern f32 D_80290330;
  extern u8 D_8029F486;
  extern f32 D_8029F9AC;
  extern f32 D_8029F9B0;
  extern f32 D_8029F9B4;
  extern f32 D_8029F9D0;
  extern f32 D_8029F9D8;
  extern f32 D_801ED680;
  extern s32 D_801ED3C4;
  extern Vec3F D_801ED68C[];
  extern s32 D_801ED758;
  extern u8 D_801ED75C[];
  extern u8 D_801FAA94[];
  extern u8 D_80202218;
  extern u8 D_801EEB60;
  extern s32 D_801EEB64;
  extern f32 D_8010727C;
  extern f32 D_80107280;
  extern f32 D_8010728C;
  extern f32 D_80107290;
  extern f32 D_80107294;
  extern f64 D_80107298;
  extern const f32 D_801072A0;
  extern const f32 D_801072A4;
  extern f32 D_801072A8;
  extern f32 D_801072AC;
  extern f32 D_801072B0;
  extern f32 D_801072B8;
  extern f32 D_801072C0;
  void func_801B2B58(s32, f32, f32);
  void func_801B31A8(s32);
  void func_80157708(void *);
  extern void func_8014932C(void *, void *);
  PhysicsObjectView *object = objectData;
  s32 onLowTraction = 0;
  s32 slideCount = 0;
  s32 i;
  s32 shouldSlide;
  f32 gravity;
  f32 terminalVelocity;
  PhysicsContactState *contacts;
  f32 projectedPoint[3];
  f32 slideVelocitySum[3];
  f32 offsetVec[3];

  if (object->flags & PHYSICS_FLAG_ANY_COLLISION)
  {
    object->speed = __builtin_sqrtf(((object->vel.x * object->vel.x) + (object->vel.y * object->vel.y)) + (object->vel.z * object->vel.z));
    object->contacts->prevPlatform = object->contacts->curPlatform;
    object->contacts->curPlatform = NULL;
    object->contacts->prevSurfaceObject = object->contacts->curSurfaceObject;
    object->contacts->curSurfaceObject = NULL;
    if (object->extra != NULL)
    {
      object->extra->contactCleared = 0;
    }
    object->contacts->hasGroundContact = 0;
    func_8015C1D4((u8 *) object);
    func_8015C924(object);
    if (object->flags & PHYSICS_FLAG_TERRAIN_COLLISION)
    {
      func_80157708(object);
    }
    if (object->flags & PHYSICS_FLAG_OBJECT_COLLISION)
    {
      func_80155D54((u8 *) object);
    }
    if (object->flags & PHYSICS_FLAG_ROLLING)
    {
      if (object->type == PHYSICS_OBJECT_TYPE_BALL)
      {
        if (D_80290090 == NULL)
        {
          if (((*((s16 *) (D_802903AC + 4))) != PHYSICS_PLAYER_ACTION_DRIBBLE) & ((*((s16 *) (D_802903AC + 4))) != PHYSICS_PLAYER_ACTION_SPECIAL_BALL))
          {
            contacts = object->contacts;
            if (contacts->plane[0] != NULL)
            {
              func_801B2B58((s32) object, 0.0f, 0.0f);
            }
            else
              if (contacts->hasGroundContact)
            {
              func_801B2B58((s32) object, object->vel.x, object->vel.z);
            }
          }
        }
      }
      else
      {
        func_801B31A8((s32) object);
      }
    }
    if (object == ((PhysicsObjectView *) (&D_802902D8)))
    {
      if ((D_80290090 != NULL) && ((*((s16 *) ((*((u8 **) ((*((u8 **) (((u8 *) (&D_80290088)) + 8))) + 0x50))) + 0x1A))) > 0))
      {
        if ((*((s16 *) (D_802903AC + 4))) == PHYSICS_PLAYER_ACTION_RIDE_BALL)
        {
          ((PhysicsContactState *) D_802903B0)->curPlatform = D_80290090;
          ((PhysicsContactState *) D_8029FA50)->curPlatform = D_80290090;
        }
        else
          if (slideCount)
        {
          ((PhysicsContactState *) D_802903B0)->curPlatform = D_80290090;
        }
        else
        {
          ((PhysicsContactState *) D_802903B0)->curPlatform = D_80290090;
        }
      }
      if (D_80290094 != NULL)
      {
        ((PhysicsContactState *) D_802903B0)->curPlatform = D_80290094;
      }
      if (D_802900A8 != NULL)
      {
        object->contacts->curPlatform = D_802900A8;
      }
    }
  }
  if (!(PHYSICS_FLAG_GRAVITY & object->flags))
  {
    return onLowTraction;
  }
  if (D_801EEB60 != 1)
  {
    return onLowTraction;
  }
  if (object->flags & PHYSICS_FLAG_REDUCED_GRAVITY)
  {
    gravity = D_801ED680 / D_8010727C;
  }
  else
  {
    gravity = D_801ED680;
  }
  if (object->flags & PHYSICS_FLAG_HIGH_TERMINAL_VEL)
  {
    terminalVelocity = D_80107280;
  }
  else
    if (((!(object->flags & PHYSICS_FLAG_NO_SLOW_FALL)) && (object->extra != NULL)) && object->extra->slowFall)
  {
    gravity = gravity / (*((f64 *) (((u8 *) (&D_80107280)) + 4)));
    terminalVelocity = D_8010728C;
  }
  else
  {
    terminalVelocity = D_80107290;
  }
  if (object == ((PhysicsObjectView *) (&D_8029F978)))
  {
    if ((*((s8 *) (&D_8029F486))) == PHYSICS_BALL_STATUS_CARRIED)
    {
      PhysicsObjectView *carrier;
      f32 containRadius;
      f32 radiusInset;
      func_8015C924(object);
      carrier = (PhysicsObjectView *) D_8029F9A4;
      ((PhysicsCarrierView *) &D_8029F9A4)->pos.x += carrier->pos.x;
      ((PhysicsCarrierView *) &D_8029F9A4)->pos.y += carrier->pos.y;
      ((PhysicsCarrierView *) &D_8029F9A4)->pos.z += carrier->pos.z;
      ((PhysicsCarrierView *) &D_8029F9A4)->pos.x -= carrier->prevPos.x;
      ((PhysicsCarrierView *) &D_8029F9A4)->pos.y -= carrier->prevPos.y;
      ((PhysicsCarrierView *) &D_8029F9A4)->pos.z -= carrier->prevPos.z;
      containRadius = 16.0f;
      radiusInset = carrier->extra->radiusScale * containRadius;
      containRadius = (f32) (carrier->radius - 3.5);
      containRadius -= radiusInset;
      func_80155B90((u8 *) object, &carrier->pos.x, containRadius);
      func_801B2B58((s32) object, D_8029F9D0, D_8029F9D8);
    }
    for (i = 0; i < object->contacts->sphereCount; i++)
    {
      if ((object->contacts->plane[i] != NULL) && (object->contacts->sphereIndex[i] != 0))
      {
        offsetVec[0] = object->pos.x - (object->contacts->hit + i)->x;
        offsetVec[1] = object->pos.y - (object->contacts->hit + i)->y;
        offsetVec[2] = object->pos.z - (object->contacts->hit + i)->z;
        if (object->contacts->kind[i] != 0)
        {
          if (i == 0)
          {
            offsetVec[0] *= (object->contacts->plane[0]->normal.y * D_801ED680) / D_801072A0;
            offsetVec[1] *= (object->contacts->plane[0]->normal.y * D_801ED680) / D_801072A0;
            offsetVec[2] *= (object->contacts->plane[0]->normal.y * D_801ED680) / D_801072A0;
            func_8014932C(&object->vel, offsetVec);
          }
        }
        else
        {
          offsetVec[0] *= (object->speed * D_801ED680) / D_801072A4;
          offsetVec[1] *= (object->speed * D_801ED680) / D_801072A4;
          offsetVec[2] *= (object->speed * D_801ED680) / D_801072A4;
          func_8014932C(&object->vel, offsetVec);
          func_801B2B58((s32) object, object->vel.x, object->vel.z);
        }
      }
      { f64 terminalVelPrecision = terminalVelocity; terminalVelocity = terminalVelPrecision; }
      { f64 terminalVelPrecision = terminalVelocity; terminalVelocity = terminalVelPrecision; }
      { f64 gravityPrecision = gravity; gravity = gravityPrecision; }
      { f64 gravityPrecision = gravity; gravity = gravityPrecision; }
    }

  }
  if (object->contacts == NULL)
  {
    object->vel.y = ((object->vel.y - gravity) > terminalVelocity) ? (object->vel.y - gravity) : (terminalVelocity);
    return 0;
  }
  for (i = 0; i < PHYSICS_CONTACT_PLANE_SLOTS; i++)
  {
    PhysicsContactPlane *plane = object->contacts->plane[i];
    if (((plane != NULL) && (0.0f < plane->normal.y)) && ((object->contacts->kind[i] == 1) || (object->params->bounceFactor == 0.0f)))
    {
      break;
    }
  }

  if (((object == ((PhysicsObjectView *) (&D_802902D8))) && (D_80290300 & PHYSICS_FLAG_TERRAIN_COLLISION)) && (D_802900BC != 0))
  {
    if (((*((f32 *) (D_801FAA94 + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE)))) == 0.0f) && (((PhysicsContactState *) D_802903B0)->plane[0] != NULL))
    {
      ((void (*)(f32 *, f32 *, f32 *, f32)) func_80148CC8)(&object->vel.x, (f32 *) (&D_801ED3C4), (f32 *) D_802900BC, -D_801ED680);
      return onLowTraction;
    }
    func_80148D0C(&D_80290330, (f32 *) D_802900BC, -D_801ED680);
    return onLowTraction;
  }
  if ((i == PHYSICS_CONTACT_PLANE_SLOTS) || (!(object->flags & PHYSICS_FLAG_TERRAIN_COLLISION)))
  {
    object->vel.y = ((object->vel.y - gravity) > terminalVelocity) ? (object->vel.y - gravity) : (terminalVelocity);
    return onLowTraction;
  }
  if (D_801EEB64 != 0)
  {
    PhysicsContactPlane *plane = object->contacts->plane[0];
    if ((plane != NULL) && (((f32 *)D_801ED75C)[plane->material * PHYSICS_SURFACE_FLOAT_STRIDE] < D_801072A8))
    {
      if (__builtin_sqrtf(((object->vel.x * object->vel.x) + (object->vel.y * object->vel.y)) + (object->vel.z * object->vel.z)) < object->params->minSlideSpeed)
      {
        func_80148D0C(&object->vel.x, &object->contacts->plane[0]->normal.x, -gravity);
      }
      onLowTraction = 1;
      if ((((object != ((PhysicsObjectView *) (&D_802902D8))) || ((*((f32 *) (D_801FAA94 + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE)))) == 0.0f)) && (((object != ((PhysicsObjectView *) (&D_8029F978))) || (!(isBallActionState = ((*((s16 *) (D_802903AC + 4))) == PHYSICS_PLAYER_ACTION_RIDE_BALL) | ((*((s16 *) (D_802903AC + 4))) == PHYSICS_PLAYER_ACTION_SPECIAL_BALL)))) || ((*((f32 *) (D_801FAA94 + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE)))) == 0.0f))) != 0)
      {
        object->vel.y = ((object->vel.y - (gravity / D_801072AC)) > terminalVelocity) ? (object->vel.y - (gravity / D_801072AC)) : (terminalVelocity);
      }
    }
    else
    {
      object->vel.y = ((object->vel.y - gravity) > terminalVelocity) ? (object->vel.y - gravity) : (terminalVelocity);
    }
  }
  slideVelocitySum[0] = (slideVelocitySum[1] = (slideVelocitySum[2] = 0.0f));
  for (i = 0; i < PHYSICS_CONTACT_PLANE_SLOTS; i++)
  {
    f32 planeDist;
    s32 surfaceOffset;
    PhysicsContactPlane *plane;
    controllerOffset = D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE;
    contacts = object->contacts;
    plane = contacts->plane[i];
    frictionThreshold = D_801072B0;
    if (plane == NULL)
    {
      continue;
    }
    if (!(0.0f < plane->normal.y))
    {
      continue;
    }
    if ((contacts->kind[i] != 1) && (object->params->bounceFactor != 0.0f))
    {
      continue;
    }
    surfaceOffset = plane->material * PHYSICS_SURFACE_ENTRY_STRIDE;
    if ((((*((f32 *) (D_801ED75C + surfaceOffset))) < D_801072B0) || ((object == ((PhysicsObjectView *) (&D_802902D8))) && ((*((s16 *) (D_802903AC + 4))) == PHYSICS_PLAYER_ACTION_SLIDE))) || (plane->normal.y <= (D_801072B0 - ((frictionThreshold - object->params->slopeGrip) / (*((f32 *) (((u8 *) (&D_801ED758)) + (plane->material * PHYSICS_SURFACE_ENTRY_STRIDE))))))))
    {
      shouldSlide = 1;
    }
    else
    {
      shouldSlide = 0;
      if (0.0f < object->vel.y)
      {
        shouldSlide = 1;
      }
    }
    if (!shouldSlide)
    {
      continue;
    }
    sphereOffsets = D_801ED68C;
    offsetVec[0] = object->pos.x + sphereOffsets[object->contacts->sphereIndex[i]].x;
    offsetVec[1] = object->pos.y + sphereOffsets[object->contacts->sphereIndex[i]].y;
    offsetVec[2] = object->pos.z + sphereOffsets[object->contacts->sphereIndex[i]].z;
    {
      PhysicsContactPlane *contactPlane = object->contacts->plane[i];
      planeDist = -((((offsetVec[0] * contactPlane->normal.x) + ((offsetVec[1] - gravity) * contactPlane->normal.y)) + (offsetVec[2] * contactPlane->normal.z)) + contactPlane->dist);
      projectedPoint[0] = offsetVec[0] + (planeDist * contactPlane->normal.x);
    }
    if ((((object == ((PhysicsObjectView *) (&D_802902D8))) && ((*((f32 *) (D_801FAA94 + controllerOffset))) != 0.0f)) && ((*((s16 *) (D_802903AC + 4))) != PHYSICS_PLAYER_ACTION_SLIDE)) || (((object == ((PhysicsObjectView *) (&D_8029F978))) && (((*((s16 *) (D_802903AC + 4))) == PHYSICS_PLAYER_ACTION_RIDE_BALL) | ((*((s16 *) (D_802903AC + 4))) == PHYSICS_PLAYER_ACTION_SPECIAL_BALL))) && ((*((f32 *) (D_801FAA94 + controllerOffset))) != 0.0f)))
    {
      PhysicsContactPlane *contactPlane = object->contacts->plane[i];
      s32 materialOffset = contactPlane->material * PHYSICS_SURFACE_ENTRY_STRIDE;
      projectedPoint[1] = (offsetVec[1] - ((gravity * (*((f64 *) (((u8 *) (&D_801072B0)) + 4)))) * (*((f32 *) (D_801ED75C + materialOffset))))) + (planeDist * contactPlane->normal.y);
    }
    else
    {
      PhysicsContactPlane *contactPlane = object->contacts->plane[i];
      s32 materialOffset = contactPlane->material * PHYSICS_SURFACE_ENTRY_STRIDE;
      projectedPoint[1] = (offsetVec[1] - (gravity * (*((f32 *) (D_801ED75C + materialOffset))))) + (planeDist * contactPlane->normal.y);
    }
    projectedPoint[2] = offsetVec[2] + (planeDist * object->contacts->plane[i]->normal.z);
    offsetVec[0] = projectedPoint[0] - (object->contacts->hit + i)->x;
    offsetVec[1] = projectedPoint[1] - (object->contacts->hit + i)->y;
    offsetVec[2] = projectedPoint[2] - (*(object->contacts->hit + i)).z;
    if (offsetVec[1] < 0.0f)
    {
      slideVelocitySum[0] += offsetVec[0];
      slideVelocitySum[1] += offsetVec[1];
      slideVelocitySum[2] += offsetVec[2];
      slideCount++;
    }
  }

  if (slideCount == 0)
  {
    return onLowTraction;
  }
  if (D_801EEB64 != 0)
  {
    func_80148D50(&object->vel.x, slideVelocitySum, (*((f64 *) (((u8 *) (&D_801072B8)) + 4))) / ((f32) slideCount));
  }
  else
  {
    func_80148D0C(&object->vel.x, slideVelocitySum, (*((f64 *) (((u8 *) (&D_801072C0)) + 4))) / ((f32) slideCount));
  }
  return onLowTraction;
}

/* Move an object by its velocity, damp the velocity (air, gravity axis or surface friction), then advance its rotation. */
void func_8015EE6C(s32 object)
{
  extern const f32 D_801072CC;
  extern const f32 D_801072D0;
  extern u8 D_801EEB60;
  extern struct
  {
    f32 f;
    u8 pad[24];
  } D_801ED74C[];
  void func_80160228();
  f32 *fields;
  f32 spinQuat[4];
  s32 axis;
  fields = (f32 *) object;
  for (axis = 0; axis < 3; axis++)
  {
    f32 t;
    f32 slip;
    s32 *contact;
    s32 n;
    t = fields[axis + (ACTOR_POSITION / 4)];
    fields[axis + (ACTOR_PREVIOUS_POSITION / 4)] = t;
    fields[axis + (ACTOR_POSITION / 4)] += fields[axis + (ACTOR_VELOCITY / 4)];
    contact = *((s32 **) (object + ACTOR_MODEL_STATE));
    if ((((contact != 0) && ((*contact) == 0)) && (((n = *((s16 *) (object + ACTOR_TYPE))) != 4) || ((*((s32 *) (object + ACTOR_FLAGS))) & 0x200000))) && (n != 0))
    {
      /* Airborne: half of the physics block's linear damping. */
      fields[axis + (ACTOR_VELOCITY / 4)] *= D_801072CC - ((D_801072CC - (*((f32 *) ((*((s32 *) (object + ACTOR_PHYSICS))) + PHYSICS_LINEAR_DAMPING)))) / D_801072D0);
    }
    else
      if ((axis == 1) && (!((*((s32 *) (object + ACTOR_FLAGS))) & 0x8000)))
    {
      *((f32 *) (object + ACTOR_VELOCITY_Y)) *= *((f32 *) ((*((s32 *) (object + ACTOR_PHYSICS))) + PHYSICS_LINEAR_DAMPING));
    }
    else
      if (((*((s32 **) (object + ACTOR_MODEL_STATE))) != 0) && ((*(*((s32 **) (object + ACTOR_MODEL_STATE)))) != 0))
    {
      /* On a face: friction scaled down by the surface's resistance. */
      f32 *velocity;
      f32 speed;
      s32 material;
      u8 *face = *((u8 **) (*((s32 **) (object + ACTOR_MODEL_STATE))));
      material = face[0x74];
      n = material << 3;
      n -= material;
      n <<= 2;
      t = *((f32 *) (((u8 *) D_801ED74C) + n));
      slip = *((f32 *) (object + ACTOR_VELOCITY_DAMPING));
      slip = D_801072CC - slip;
      velocity = (f32 *) (((s32) (fields + axis)) + ACTOR_VELOCITY);
      speed = *velocity;
      if (!(t < D_801072CC))
      {
        if (velocity)
        {
          slip /= t;
        }
        else
        {
          slip /= t;
        }
      }
      *velocity = speed * (D_801072CC - slip);
    }
    else
    {
      fields[axis + (ACTOR_VELOCITY / 4)] *= *((f32 *) (object + ACTOR_VELOCITY_DAMPING));
    }
  }

  if ((*((s32 *) (object + ACTOR_FLAGS))) & OBJECT_APPLY_SPIN)
  {
    func_80148C3C(spinQuat, (f32 *) (object + ACTOR_SPIN_AXIS));
    func_801488C0((Quat801488C0 *) (object + ACTOR_ORIENTATION), (f32 *) spinQuat, (f32 *) (object + ACTOR_ORIENTATION));
    *((f32 *) (object + ACTOR_SPIN_ANGLE)) *= *((f32 *) ((*((s32 *) (object + ACTOR_PHYSICS))) + PHYSICS_ANGULAR_DAMPING));
  }
  else
  {
    for (axis = 0; axis < 3; axis++)
    {
      f32 *s = ((f32 *) object) + axis;
      s[ACTOR_PITCH / 4] += s[ACTOR_ANGULAR_VELOCITY / 4];
      s[ACTOR_PITCH / 4] = func_801496C8(s[ACTOR_PITCH / 4]);
      if (*((s8 *) (((*((s32 *) (object + ACTOR_PHYSICS))) + axis) + PHYSICS_ANGLE_APPROACH_MODES)))
      {
        func_80160228(object, axis);
      }
      s[ACTOR_ANGULAR_VELOCITY / 4] *= *((f32 *) ((*((s32 *) (object + ACTOR_PHYSICS))) + PHYSICS_ANGULAR_DAMPING));
      if (D_801EEB60 == 0)
      {
        s[ACTOR_ANGULAR_VELOCITY / 4] = 0;
      }
    }

  }
}


extern f32 D_801072D0, D_801072D8, D_801072E4, D_80107328;
extern f64 D_801072E8, D_801072F0, D_801072F8, D_80107300, D_80107308, D_80107310, D_80107318, D_80107320;
/* One frame of an object's teleport: sparkles, then shrinks over the
 * definition's shrink frames, moves (or swaps player and ball) at zero,
 * and grows back. Returns 1 while still shrinking, else 0. The ball's
 * scale lives at D_8029FA34/38/3C, its base size at D_8029FA50 + 0x70. */
s32 func_8015F098(u8 *obj)
{
  extern f32 D_8029FA3C;
  extern f32 D_8029FA38;
  extern f32 D_8029FA34;
  extern u8 *D_8028FAC8;
  void func_801490AC(Vec3F *, Vec3F *, f32);
  Vec3F pos;
  s32 i;
  s32 jitter;
  u8 *state;
  u8 *def;
  s8 timer;
  if (OBJ_PTR(obj, TELEPORT_OBJECT_STATE) == NULL)
  {
    return 0;
  }
  if (OBJ_PTR(OBJ_PTR(obj, TELEPORT_OBJECT_STATE), TELEPORT_STATE_DEFINITION) == NULL)
  {
    return 0;
  }
  for (i = 0; i < 1; i++)
  {
    pos = *((Vec3F *) (obj + TELEPORT_OBJECT_POSITION));
    pos.x += func_80147000(0x1F) - 15;
    pos.y += func_80147000(0x1F) - 15;
    jitter = func_80147000(0x1F) - 15;
    pos.z += jitter;
    func_801B66D4(5, &pos, &D_801ED3C4, 0, 0);
  }

  state = OBJ_PTR(obj, TELEPORT_OBJECT_STATE);
  timer = state[TELEPORT_STATE_TIMER];
  if (timer == 0)
  {
    /* Arrival: start growing, and move to the destination. */
    def = OBJ_PTR(state, TELEPORT_STATE_DEFINITION);
    state[TELEPORT_STATE_TIMER] = -def[TELEPORT_DEF_GROW_FRAMES_LOW_BYTE];
    if (*((s8 *) (OBJ_PTR(obj, TELEPORT_OBJECT_STATE) + TELEPORT_STATE_TIMER)) == 0)
    {
      if (obj == ((u8 *) (&D_8029F978)))
      {
        D_8029FA34 = (D_8029FA38 = (D_8029FA3C = (OBJ_F32(D_8029FA50, 0x70) * (*((f64 *) (((u8 *) (&D_801072D0)) + 4)))) / (*((f64 *) (((u8 *) (&D_801072D8)) + 4)))));
      }
      else
      {
        OBJ_F32(obj, OBJ_FIELD_SCALE_X) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Y) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Z) = D_801072E4));
      }
      OBJ_PTR(OBJ_PTR(obj, TELEPORT_OBJECT_STATE), TELEPORT_STATE_DEFINITION) = NULL;
    }
    if (OBJ_PTR(def, TELEPORT_DEF_ANCHOR) != NULL)
    {
      /* Destination is relative to an anchor object, rotated with it. */
      u8 *rotation = OBJ_PTR(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0x2C);
      if (rotation != NULL)
      {
        if (OBJ_F32(rotation, 0x3C) != 0.0f)
        {
          func_801490AC(&pos, (Vec3F *) def, OBJ_F32(rotation, 0x3C));
        }
        else
          if (OBJ_F32(rotation, 0x38) != 0.0f)
        {
          func_8014915C(&pos, (Vec3F *) def, OBJ_F32(rotation, 0x38), 0);
        }
        else
          if (OBJ_F32(rotation, 0x40) != 0.0f)
        {
          func_8014915C(&pos, (Vec3F *) def, OBJ_F32(rotation, 0x40), 2);
        }
        OBJ_F32(obj, WFO_POSITION) = pos.x + OBJ_F32(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0xB4);
        OBJ_F32(obj, WFO_POSITION_Y) = pos.y + OBJ_F32(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0xB8);
        OBJ_F32(obj, WFO_POSITION_Z) = pos.z + OBJ_F32(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0xBC);
      }
      else
      {
        OBJ_F32(obj, WFO_POSITION) = OBJ_F32(def, 0x0) + OBJ_F32(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0xB4);
        OBJ_F32(obj, WFO_POSITION_Y) = OBJ_F32(def, 0x4) + OBJ_F32(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0xB8);
        OBJ_F32(obj, WFO_POSITION_Z) = OBJ_F32(def, 0x8) + OBJ_F32(OBJ_PTR(def, TELEPORT_DEF_ANCHOR), 0xBC);
      }
      if ((*((u16 *) (def + TELEPORT_DEF_FLAGS))) & TELEPORT_ATTACH_TO_DESTINATION)
      {
        /* Stand on the anchor: it becomes the support, and Y its top. */
        u8 *anchor;
        OBJ_PTR(OBJ_PTR(obj, WFO_SUPPORT), 0x17C) = (OBJ_PTR(OBJ_PTR(obj, WFO_SUPPORT), 0x178) = OBJ_PTR(def, TELEPORT_DEF_ANCHOR));
        anchor = OBJ_PTR(def, TELEPORT_DEF_ANCHOR);
        if (OBJ_PTR(anchor, 0x30) != NULL)
        {
          OBJ_F32(obj, WFO_POSITION_Y) = OBJ_F32(anchor, 0xB8) + ((OBJ_F32(anchor, 0xC) * OBJ_F32(anchor, 0x140)) / OBJ_F32(OBJ_PTR(anchor, 0x30), 4));
        }
        else
        {
          OBJ_F32(obj, WFO_POSITION_Y) = OBJ_F32(anchor, 0xB8) + OBJ_F32(anchor, 0xC);
        }
      }
    }
    else
      if ((*((u16 *) (def + TELEPORT_DEF_FLAGS))) & TELEPORT_SWAP_PLAYER_AND_BALL)
    {
      /* Swap places with the partner, which starts teleporting too. */
      if (obj == ((u8 *) (&D_802902D8)))
      {
        *((Words3 *) (&pos)) = *((Words3 *) (&D_8029F9AC));
        *((Words3 *) (&D_8029F9AC)) = *((Words3 *) (obj + TELEPORT_OBJECT_POSITION));
        *((Words3 *) (obj + TELEPORT_OBJECT_POSITION)) = *((Words3 *) (&pos));
        ((u8 *) D_8029FA4C)[TELEPORT_STATE_TIMER] = -def[TELEPORT_DEF_GROW_FRAMES_LOW_BYTE];
        *((u8 **) (((u8 *) D_8029FA4C) + TELEPORT_STATE_DEFINITION)) = def;
        OBJ_F32(D_8029FA50, 0x70) = (OBJ_F32(D_8029FA50, 0x74) = 0.0f);
      }
      else
        if (obj == ((u8 *) (&D_8029F978)))
      {
        *((Words3 *) (&pos)) = *((Words3 *) (obj + TELEPORT_OBJECT_POSITION));
        *((Words3 *) (obj + TELEPORT_OBJECT_POSITION)) = *((Words3 *) (((u8 *) (&D_802902D8)) + TELEPORT_OBJECT_POSITION));
        *((Words3 *) (((u8 *) (&D_802902D8)) + TELEPORT_OBJECT_POSITION)) = *((Words3 *) (&pos));
        D_802903AC[TELEPORT_STATE_TIMER] = -def[TELEPORT_DEF_GROW_FRAMES_LOW_BYTE];
        *((u8 **) (D_802903AC + TELEPORT_STATE_DEFINITION)) = def;
        D_80290394 = (D_80290398 = (D_8029039C = 0.0f));
      }
    }
    else
    {
      *((Words3 *) (obj + TELEPORT_OBJECT_POSITION)) = *((Words3 *) def);
    }
    if (D_8028FAC8 == (obj + TELEPORT_OBJECT_POSITION))
    {
      /* The camera follows this object: carry it (and its target) along. */
      f32 *cam = &D_8028F914;
      *cam += OBJ_F32(obj, WFO_POSITION);
      D_8028F918 += OBJ_F32(obj, WFO_POSITION_Y);
      D_8028F91C += OBJ_F32(obj, WFO_POSITION_Z);
      *cam -= OBJ_F32(obj, 0x40);
      D_8028F918 -= OBJ_F32(obj, 0x44);
      D_8028F91C -= OBJ_F32(obj, 0x48);
      D_8028FA00 += OBJ_F32(obj, WFO_POSITION);
      D_8028FA04 += OBJ_F32(obj, WFO_POSITION_Y);
      D_8028FA08 += OBJ_F32(obj, WFO_POSITION_Z);
      D_8028FA00 -= OBJ_F32(obj, 0x40);
      D_8028FA04 -= OBJ_F32(obj, 0x44);
      D_8028FA08 -= OBJ_F32(obj, 0x48);
    }
    if ((*((u16 *) (def + TELEPORT_DEF_FLAGS))) & TELEPORT_CLEAR_VELOCITY)
    {
      OBJ_F32(obj, WFO_VELOCITY_X) = (OBJ_F32(obj, WFO_VELOCITY_Y) = (OBJ_F32(obj, WFO_VELOCITY_Z) = 0.0f));
    }
    OBJ_F32(obj, WFO_POSITION_Y) += OBJ_F32(obj, WFO_RADIUS);
    *((Words3 *) (obj + OBJ_FIELD_PREVIOUS_POSITION)) = *((Words3 *) (obj + TELEPORT_OBJECT_POSITION));
    func_80178134(TELEPORT_SOUND_ARRIVE, (f32 *) (obj + TELEPORT_OBJECT_POSITION), 0x64, 0x80);
    if (obj == ((u8 *) (&D_802902D8)))
    {
      func_8018D39C(3);
    }
    return 0;
  }
  if (timer > 0)
  {
    /* Shrinking: scale = timer / shrinkFrames. */
    state[TELEPORT_STATE_TIMER] = timer - 1;
    if (obj == ((u8 *) (&D_8029F978)))
    {
      u8 *ballState = (u8 *) D_8029FA4C;
      f32 size = ((*((s8 *) (ballState + TELEPORT_STATE_TIMER))) * D_801072E8) * OBJ_F32(D_8029FA50, 0x70);
      D_8029FA34 = (D_8029FA38 = (D_8029FA3C = size / ((*((s16 *) (OBJ_PTR(ballState, TELEPORT_STATE_DEFINITION) + TELEPORT_DEF_SHRINK_FRAMES))) * D_801072F0)));
    }
    else
    {
      u8 *objState = OBJ_PTR(obj, TELEPORT_OBJECT_STATE);
      OBJ_F32(obj, OBJ_FIELD_SCALE_X) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Y) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Z) = ((f32) ((*((s8 *) (objState + TELEPORT_STATE_TIMER))) * D_801072F8)) / ((f32) (*((s16 *) (OBJ_PTR(objState, TELEPORT_STATE_DEFINITION) + TELEPORT_DEF_SHRINK_FRAMES))))));
    }
    return 1;
  }
  /* Growing: scale = (growFrames + timer) / growFrames. */
  state[TELEPORT_STATE_TIMER] = timer + 1;
  if (obj == ((u8 *) (&D_8029F978)))
  {
    u8 *ballState = (u8 *) D_8029FA4C;
    s32 growFrames = *((s16 *) (OBJ_PTR(ballState, TELEPORT_STATE_DEFINITION) + TELEPORT_DEF_GROW_FRAMES));
    f32 size = ((growFrames + (*((s8 *) (ballState + TELEPORT_STATE_TIMER)))) * D_80107300) * OBJ_F32(D_8029FA50, 0x70);
    D_8029FA34 = (D_8029FA38 = (D_8029FA3C = size / (growFrames * D_80107308)));
  }
  else
  {
    u8 *objState = OBJ_PTR(obj, TELEPORT_OBJECT_STATE);
    s32 growFrames = *((s16 *) (OBJ_PTR(objState, TELEPORT_STATE_DEFINITION) + TELEPORT_DEF_GROW_FRAMES));
    OBJ_F32(obj, OBJ_FIELD_SCALE_X) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Y) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Z) = (((f32) (growFrames + (*((s8 *) (objState + TELEPORT_STATE_TIMER))))) * D_80107310) / growFrames));
  }
  if ((*((s8 *) (OBJ_PTR(obj, TELEPORT_OBJECT_STATE) + TELEPORT_STATE_TIMER))) == 0)
  {
    /* Done: restore full size and drop the teleport. */
    jitter = (u8 *) (&D_8029F978);
    if (obj == jitter)
    {
      D_8029FA34 = (D_8029FA38 = (D_8029FA3C = (OBJ_F32(D_8029FA50, 0x70) * D_80107318) / D_80107320));
    }
    else
    {
      OBJ_F32(obj, OBJ_FIELD_SCALE_X) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Y) = (OBJ_F32(obj, OBJ_FIELD_SCALE_Z) = D_80107328));
    }
    OBJ_PTR(OBJ_PTR(obj, TELEPORT_OBJECT_STATE), TELEPORT_STATE_DEFINITION) = NULL;
  }
  return 0;
}

extern f32 D_8010732C;
/* Carries an actor with the platform it stands on (floor) or touches (contact): applies surface
 * motion pushes, then the platform's (and its parents') movement since last frame, then its
 * rotation, turning the actor's velocity, facing and orientation along with it. */
void func_8015F910(Vec3F *position, Vec3F *rotatedPosition, f32 *velocity, Vec3F *facing, Vec3F *targetFacing,
                   Quat801488C0 *orientation, u8 turnWithPlatform, s32 actorFlags, u8 *floor, u8 *contact) {
    void func_801490AC(Vec3F *, Vec3F *, f32);
    f32 planar[3];
    f32 turnQuat[4];
    Vec3F relative;
    Vec3F push;
    u8 *platform;
    u8 *parent;
    f32 radius;
    f32 angle;
    s32 i;
    s32 rotationAxis;

    if (floor != NULL && (*(s32 *)(floor + PLATFORM_FLAGS) & PLATFORM_SCROLL_TEXCOORDS)) {
        if (*(u8 **)(floor + PLATFORM_ROTATION) != NULL) {
            relative.x = position->x - *(f32 *)(floor + PLATFORM_POSITION);
            relative.y = position->y - *(f32 *)(floor + PLATFORM_POSITION_Y);
            relative.z = position->z - *(f32 *)(floor + PLATFORM_POSITION_Z);
            func_801490AC(&relative, &relative, *(f32 *)(*(u8 **)(floor + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(floor + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW));
            rotatedPosition->x = relative.x + *(f32 *)(floor + PLATFORM_POSITION);
            rotatedPosition->y = relative.y + *(f32 *)(floor + PLATFORM_POSITION_Y);
            rotatedPosition->z = relative.z + *(f32 *)(floor + PLATFORM_POSITION_Z);
        } else {
            *rotatedPosition = *position;
        }
        func_8015CE38(&push, floor, (f32 *)position, 1);
        position->x += push.x;
        position->y += push.y;
        position->z += push.z;
        if (contact != floor) {
            func_8015CD4C(velocity, (f32 *)&push);
        }
    }
    if (contact != NULL && floor != contact && (*(s32 *)(contact + PLATFORM_FLAGS) & PLATFORM_SCROLL_TEXCOORDS)) {
        func_8015CE38(&push, contact, (f32 *)position, 1);
        if (velocity[0] * push.x + velocity[1] * push.y + velocity[2] * push.z < 0.0f) {
            velocity[0] = velocity[0] + push.x;
            velocity[1] = velocity[1] + push.y;
            velocity[2] = velocity[2] + push.z;
        } else {
            f32 *v;
            f32 *src;
            f32 zero = 0.0f;

            v = velocity;
            src = (f32 *)&push;
            do {
                if ((zero < *src && *v < *src) || (*src < zero && *src < *v)) {
                    *v = *src;
                }
                v++;
                src++;
            } while ((s32)v < (s32)(velocity + 3));
        }
    }
    if (floor != NULL) {
        platform = floor;
    } else if (contact != NULL) {
        platform = contact;
    } else {
        return;
    }
    if (!(*(f32 *)(platform + PLATFORM_POSITION_Y) - *(f32 *)(platform + PLATFORM_PREVIOUS_POSITION_Y) > D_8010732C)) {
        return;
    }
    position->x += *(f32 *)(platform + PLATFORM_POSITION);
    position->y += *(f32 *)(platform + PLATFORM_POSITION_Y);
    position->z += *(f32 *)(platform + PLATFORM_POSITION_Z);
    position->x -= *(f32 *)(platform + PLATFORM_PREVIOUS_POSITION);
    position->y -= *(f32 *)(platform + PLATFORM_PREVIOUS_POSITION_Y);
    position->z -= *(f32 *)(platform + PLATFORM_PREVIOUS_POSITION_Z);
    for (parent = *(u8 **)(platform + PLATFORM_PARENT); parent != NULL; parent = *(u8 **)(parent + PLATFORM_PARENT)) {
        position->x += *(f32 *)(parent + PLATFORM_POSITION);
        position->y += *(f32 *)(parent + PLATFORM_POSITION_Y);
        position->z += *(f32 *)(parent + PLATFORM_POSITION_Z);
        position->x -= *(f32 *)(parent + PLATFORM_PREVIOUS_POSITION);
        position->y -= *(f32 *)(parent + PLATFORM_PREVIOUS_POSITION_Y);
        position->z -= *(f32 *)(parent + PLATFORM_PREVIOUS_POSITION_Z);
    }
    if (*(s32 *)(platform + PLATFORM_UNK50) != 0 || (*(s32 *)(platform + PLATFORM_FLAGS) & PLATFORM_MULTI_AXIS_ROTATION)) {
        /* yaw, then X and Z rotation around the platform's position */
        if (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) != *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW)) {
            func_801490AC((Vec3F *)velocity, (Vec3F *)velocity, *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW));
            if (!(actorFlags & 0x20)) {
                facing->y += *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW);
                targetFacing->y += *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW);
            }
            planar[0] = position->x - *(f32 *)(platform + PLATFORM_POSITION);
            planar[1] = position->z - *(f32 *)(platform + PLATFORM_POSITION_Z);
            radius = sqrtf(planar[0] * planar[0] + planar[1] * planar[1]);
            angle = func_801496C8(func_80147460(planar[1], planar[0]) - (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW)));
            planar[0] = radius * func_801C4040(angle);
            planar[1] = radius * func_801C6000(angle);
            position->x = planar[0] + *(f32 *)(platform + PLATFORM_POSITION);
            position->z = planar[1] + *(f32 *)(platform + PLATFORM_POSITION_Z);
        }
        if (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) != *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES)) {
            relative.x = position->x - *(f32 *)(platform + PLATFORM_POSITION);
            relative.y = position->y - *(f32 *)(platform + PLATFORM_POSITION_Y);
            relative.z = position->z - *(f32 *)(platform + PLATFORM_POSITION_Z);
            func_8014915C(&relative, &relative, -*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW), 1);
            planar[0] = relative.y; planar[1] = relative.z; radius = sqrtf(planar[0] * planar[0] + planar[1] * planar[1]); angle = func_801496C8(func_80147460(planar[1], planar[0]) + (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES)));
            planar[0] = radius * func_801C4040(angle);
            planar[1] = radius * func_801C6000(angle);
            relative.y = planar[0];
            relative.z = planar[1];
            func_8014915C(&relative, &relative, *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW), 1);
            position->x = *(f32 *)(platform + PLATFORM_POSITION) + relative.x;
            position->y = *(f32 *)(platform + PLATFORM_POSITION_Y) + relative.y;
            position->z = *(f32 *)(platform + PLATFORM_POSITION_Z) + relative.z;
        }
        if (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ROLL) != *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ROLL)) {
            relative.x = position->x - *(f32 *)(platform + PLATFORM_POSITION);
            relative.y = position->y - *(f32 *)(platform + PLATFORM_POSITION_Y);
            relative.z = position->z - *(f32 *)(platform + PLATFORM_POSITION_Z);
            func_8014915C(&relative, &relative, -*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW), 1);
            planar[0] = relative.x; planar[1] = relative.y; radius = sqrtf(planar[0] * planar[0] + planar[1] * planar[1]); angle = func_801496C8(func_80147460(planar[1], planar[0]) + (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ROLL) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ROLL)));
            planar[0] = radius * func_801C4040(angle);
            planar[1] = radius * func_801C6000(angle);
            relative.x = planar[0];
            relative.y = planar[1];
            func_8014915C(&relative, &relative, *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW), 1);
            position->x = *(f32 *)(platform + PLATFORM_POSITION) + relative.x;
            position->y = *(f32 *)(platform + PLATFORM_POSITION_Y) + relative.y;
            position->z = *(f32 *)(platform + PLATFORM_POSITION_Z) + relative.z;
        }
        return;
    }
    if (*(u8 **)(platform + PLATFORM_ROTATION) == NULL) {
        return;
    }
    if (*(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) != *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW)) {
        func_801490AC((Vec3F *)velocity, (Vec3F *)velocity, *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW));
        if (actorFlags & 0x4000) {
            f32 *g = &D_801ED3EC;

            *g = *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW);
            func_80148C3C(turnQuat, g - 3);
            func_801488C0(orientation, turnQuat, (f32 *)orientation);
        } else if (turnWithPlatform) {
            facing->y += *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW);
            targetFacing->y += *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW);
        }
    }
    {
        /* find the one X/Z axis the platform turned about, if any */
        f32 *pp;
        u8 *bp;
        f32 *dst;

        rotationAxis = PLATFORM_ROTATION_NO_AXIS;
        for (i = 0, pp = (f32 *)position, bp = platform, dst = planar; i < 3; i++) {
            if (((f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES))[i] == ((f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES))[i]) {
                *dst = *pp - *(f32 *)(bp + PLATFORM_POSITION);
                dst++;
            } else {
                rotationAxis = i;
            }
            pp++;
            bp += 4;
        }
    }
    if (rotationAxis == PLATFORM_ROTATION_NO_AXIS) {
        return;
    }
    relative.x = position->x - *(f32 *)(platform + PLATFORM_POSITION);
    relative.y = position->y - *(f32 *)(platform + PLATFORM_POSITION_Y);
    relative.z = position->z - *(f32 *)(platform + PLATFORM_POSITION_Z);
    func_8014915C(&relative, &relative, ((f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES))[rotationAxis] - ((f32 *)(*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES))[rotationAxis], (s8)rotationAxis);
    position->x = *(f32 *)(platform + PLATFORM_POSITION) + relative.x;
    position->y = *(f32 *)(platform + PLATFORM_POSITION_Y) + relative.y;
    position->z = *(f32 *)(platform + PLATFORM_POSITION_Z) + relative.z;
}

/* Approach one target Euler angle along the shortest arc with a capped angular step. */
void func_80160228(s32 objectAddress, s32 axis) {
    f32 approachDivisor;
    f32 currentAngle;
    f32 targetAngle;
    f32 *axisFields;
    f32 *currentAnglePtr;
    f32 *physics;
    f32 *angleOut;

    approachDivisor = D_80107330;
    if (*(s8 *)(*(s32 *)(objectAddress + ACTOR_PHYSICS) + axis + PHYSICS_ANGLE_APPROACH_MODES) == ANGLE_APPROACH_HALF_DISTANCE) {
        approachDivisor = D_80107334;
    }
    axisFields = (f32 *)(axis * 4 + objectAddress);
    currentAnglePtr = &axisFields[ACTOR_PITCH / 4];
    axisFields[ACTOR_TARGET_PITCH / 4] = func_801496C8(axisFields[ACTOR_TARGET_PITCH / 4]);
    if (func_8014944C(axisFields[ACTOR_PITCH / 4], axisFields[ACTOR_TARGET_PITCH / 4]) <= D_80107338) {
        axisFields[ACTOR_PITCH / 4] = axisFields[ACTOR_TARGET_PITCH / 4];
    } else {
        currentAngle = axisFields[ACTOR_PITCH / 4];
        targetAngle = axisFields[ACTOR_TARGET_PITCH / 4];
        if (currentAngle < targetAngle) {
            if (targetAngle - currentAngle > D_80107340) {
                physics = *(f32 **)(objectAddress + ACTOR_PHYSICS);
                angleOut = currentAnglePtr;
                *angleOut = currentAngle - ((func_8014944C(currentAngle, targetAngle) / approachDivisor < physics[PHYSICS_MAX_ANGLE_STEP / 4]) ? func_8014944C(*angleOut, axisFields[ACTOR_TARGET_PITCH / 4]) / approachDivisor : (*(f32 **)(objectAddress + ACTOR_PHYSICS))[PHYSICS_MAX_ANGLE_STEP / 4]);
            } else {
                physics = *(f32 **)(objectAddress + ACTOR_PHYSICS);
                angleOut = currentAnglePtr;
                *angleOut = currentAngle + ((func_8014944C(currentAngle, targetAngle) / approachDivisor < physics[PHYSICS_MAX_ANGLE_STEP / 4]) ? func_8014944C(*angleOut, axisFields[ACTOR_TARGET_PITCH / 4]) / approachDivisor : (*(f32 **)(objectAddress + ACTOR_PHYSICS))[PHYSICS_MAX_ANGLE_STEP / 4]);
            }
        } else if (targetAngle < currentAngle) {
            if (currentAngle - targetAngle > D_80107348) {
                physics = *(f32 **)(objectAddress + ACTOR_PHYSICS);
                angleOut = currentAnglePtr;
                *angleOut = currentAngle + ((func_8014944C(currentAngle, targetAngle) / approachDivisor < physics[PHYSICS_MAX_ANGLE_STEP / 4]) ? func_8014944C(*angleOut, axisFields[ACTOR_TARGET_PITCH / 4]) / approachDivisor : (*(f32 **)(objectAddress + ACTOR_PHYSICS))[PHYSICS_MAX_ANGLE_STEP / 4]);
            } else {
                physics = *(f32 **)(objectAddress + ACTOR_PHYSICS);
                angleOut = currentAnglePtr;
                *angleOut = currentAngle - ((func_8014944C(currentAngle, targetAngle) / approachDivisor < physics[PHYSICS_MAX_ANGLE_STEP / 4]) ? func_8014944C(*angleOut, axisFields[ACTOR_TARGET_PITCH / 4]) / approachDivisor : (*(f32 **)(objectAddress + ACTOR_PHYSICS))[PHYSICS_MAX_ANGLE_STEP / 4]);
            }
        }
    }
    ((f32 *)objectAddress)[axis + ACTOR_PITCH / 4] = func_801496C8(((f32 *)objectAddress)[axis + ACTOR_PITCH / 4]);
}

/* Accelerate along yaw, optionally cap horizontal speed, and refresh the cached XYZ speed. */
void func_8016049C(u8 *object, f32 acceleration, f32 maxHorizontalSpeed) {
    f32 *velocity = (f32 *)(object + OBJECT_VELOCITY_X);
    f32 yaw = *(f32 *)(object + ACTOR_YAW);

    velocity[0] += acceleration * func_801C6000(yaw);
    velocity[2] += acceleration * func_801C4040(yaw);
    velocity[(OBJECT_SPEED - OBJECT_VELOCITY_X) / sizeof(f32)] = __builtin_sqrtf(velocity[0] * velocity[0] + velocity[1] * velocity[1] + velocity[2] * velocity[2]);
    if (!(*(s32 *)(object + OBJECT_MOTION_FLAGS) & OBJECT_BYPASS_SPEED_LIMIT)) {
        acceleration = __builtin_sqrtf(velocity[0] * velocity[0] + velocity[2] * velocity[2]);
        if (maxHorizontalSpeed < acceleration) {
            f32 speedScale = maxHorizontalSpeed / acceleration;
            f32 clampedX = velocity[0] * speedScale;
            f32 clampedZ = velocity[2] * speedScale;
            velocity[0] = clampedX;
            velocity[2] = clampedZ;
            velocity[(OBJECT_SPEED - OBJECT_VELOCITY_X) / sizeof(f32)] = __builtin_sqrtf(velocity[0] * velocity[0] + velocity[1] * velocity[1] + clampedZ * clampedZ);
        }
    }
}

/*
 * Accelerate an object along its facing direction: the unit forward vector
 * (0, 0, 1) is rotated by the orientation quaternion (OBJECT_APPLY_SPIN) or
 * by pitch then yaw, scaled by `acceleration` and added to the velocity,
 * which func_80160728 then caps at `maxSpeed`. D_80107350 = 1.0f.
 * func_801499A0 rotates by a quaternion; func_8014915C / func_801490AC
 * rotate about X / Y.
 */
void func_80160610(u8 *object, f32 acceleration, f32 maxSpeed) {
    Vec3F forward;
    f32 yaw;
    f32 zero = 0.0f;

    forward.z = D_80107350;
    forward.x = zero;
    forward.y = zero;
    if (*(s32 *)(object + OBJECT_MOTION_FLAGS) & OBJECT_APPLY_SPIN) {
        func_801499A0((s32)&forward, (s32)&forward, (s32)(object + ACTOR_ORIENTATION));
    } else {
        yaw = *(f32 *)(object + ACTOR_YAW);
        func_8014915C(&forward, &forward, *(f32 *)(object + ACTOR_PITCH), 0);
        func_801490AC(&forward, &forward, yaw);
    }
    forward.x *= acceleration;
    forward.y *= acceleration;
    forward.z *= acceleration;
    *(f32 *)(object + OBJECT_VELOCITY_X) += forward.x;
    *(f32 *)(object + OBJECT_VELOCITY_Y) += forward.y;
    *(f32 *)(object + OBJECT_VELOCITY_Z) += forward.z;
    func_80160728(object, maxSpeed);
}

/* Store the actor's total speed (|velocity|) and, unless flag 0x1000000 is set, scale the velocity down to maxSpeed. */
void func_80160728(u8 *actor, f32 maxSpeed) { f32 *velocity = (f32 *)(actor + 0x58); f32 sq; velocity[7] = sqrtf(velocity[0] * velocity[0] + velocity[1] * velocity[1] + velocity[2] * velocity[2]);
    if (!(*(s32 *)(actor + 0x28) & 0x1000000)) {
        if (maxSpeed < velocity[7]) {
            velocity[0] = velocity[0] * (maxSpeed / velocity[7]);
            velocity[1] = velocity[1] * (maxSpeed / velocity[7]);
            velocity[2] = velocity[2] * (maxSpeed / velocity[7]);
            sq = velocity[0] * velocity[0] + velocity[1] * velocity[1];
            velocity[7] = sqrtf(sq + velocity[2] * velocity[2]); /* speed lives at +0x74 */
        }
    }
}

/* Limit an object's horizontal (XZ) speed to maxSpeed, unless its flags opt out: the
 * X/Z velocity is scaled by maxSpeed / cached speed, then the cached 3D speed is
 * recomputed from the new velocity. */
void func_80160830(u8 *object, f32 maxSpeed) {
    if (!(*(s32 *)(object + OBJECT_MOTION_FLAGS_OFFSET) & OBJECT_MOTION_NO_SPEED_CLAMP)) {
        if (maxSpeed < __builtin_sqrtf(*(f32 *)(object + OBJECT_MOTION_VELOCITY_X_OFFSET) * *(f32 *)(object + OBJECT_MOTION_VELOCITY_X_OFFSET) + *(f32 *)(object + OBJECT_MOTION_VELOCITY_Z_OFFSET) * *(f32 *)(object + OBJECT_MOTION_VELOCITY_Z_OFFSET))) {
            *(f32 *)(object + OBJECT_MOTION_VELOCITY_X_OFFSET) *= maxSpeed / *(f32 *)(object + OBJECT_MOTION_SPEED_OFFSET);
            *(f32 *)(object + OBJECT_MOTION_VELOCITY_Z_OFFSET) *= maxSpeed / *(f32 *)(object + OBJECT_MOTION_SPEED_OFFSET);
            *(f32 *)(object + OBJECT_MOTION_SPEED_OFFSET) = __builtin_sqrtf(*(f32 *)(object + OBJECT_MOTION_VELOCITY_X_OFFSET) * *(f32 *)(object + OBJECT_MOTION_VELOCITY_X_OFFSET) + *(f32 *)(object + OBJECT_MOTION_VELOCITY_Y_OFFSET) * *(f32 *)(object + OBJECT_MOTION_VELOCITY_Y_OFFSET) + *(f32 *)(object + OBJECT_MOTION_VELOCITY_Z_OFFSET) * *(f32 *)(object + OBJECT_MOTION_VELOCITY_Z_OFFSET));
        }
    }
}

/* Add quaternion-rotated forward acceleration, then limit XYZ or horizontal speed. */
void func_80160920(s32 objectAddress, f32 acceleration, f32 maxSpeed, void *rotation, s32 limitAllAxes) {
    f32 velocityDelta[3];
    f32 horizontalSpeed;
    f32 zero = 0.0f;

    velocityDelta[2] = D_80107354;
    velocityDelta[0] = zero;
    velocityDelta[1] = zero;
    func_801499A0((s32)velocityDelta, (s32)velocityDelta, (s32)rotation);
    velocityDelta[0] *= acceleration;
    velocityDelta[1] *= acceleration;
    velocityDelta[2] *= acceleration;
    *(f32 *)(objectAddress + OBJECT_VELOCITY_X) += velocityDelta[0];
    *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) += velocityDelta[1];
    *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) += velocityDelta[2];
    if (limitAllAxes != 0) {
        *(f32 *)(objectAddress + OBJECT_SPEED) = __builtin_sqrtf(*(f32 *)(objectAddress + OBJECT_VELOCITY_X) * *(f32 *)(objectAddress + OBJECT_VELOCITY_X) +
                            *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) +
                            *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Z));
        if (!(*(s32 *)(objectAddress + OBJECT_MOTION_FLAGS) & OBJECT_BYPASS_SPEED_LIMIT)) {
        if (maxSpeed < *(f32 *)(objectAddress + OBJECT_SPEED)) {
            *(f32 *)(objectAddress + OBJECT_VELOCITY_X) *= maxSpeed / *(f32 *)(objectAddress + OBJECT_SPEED);
            *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) *= maxSpeed / *(f32 *)(objectAddress + OBJECT_SPEED);
            *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) *= maxSpeed / *(f32 *)(objectAddress + OBJECT_SPEED); *(f32 *)(objectAddress + OBJECT_SPEED) = __builtin_sqrtf(*(f32 *)(objectAddress + OBJECT_VELOCITY_X) * *(f32 *)(objectAddress + OBJECT_VELOCITY_X) + *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) + *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Z));
        }
        }
    } else {
        if (!(*(s32 *)(objectAddress + OBJECT_MOTION_FLAGS) & OBJECT_BYPASS_SPEED_LIMIT)) {
        horizontalSpeed = __builtin_sqrtf(*(f32 *)(objectAddress + OBJECT_VELOCITY_X) * *(f32 *)(objectAddress + OBJECT_VELOCITY_X) +
                            *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Z));
        if (maxSpeed < horizontalSpeed) {
            *(f32 *)(objectAddress + OBJECT_VELOCITY_X) *= maxSpeed / *(f32 *)(objectAddress + OBJECT_SPEED);
            *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) *= maxSpeed / *(f32 *)(objectAddress + OBJECT_SPEED); *(f32 *)(objectAddress + OBJECT_SPEED) = __builtin_sqrtf(*(f32 *)(objectAddress + OBJECT_VELOCITY_X) * *(f32 *)(objectAddress + OBJECT_VELOCITY_X) + *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Y) + *(f32 *)(objectAddress + OBJECT_VELOCITY_Z) * *(f32 *)(objectAddress + OBJECT_VELOCITY_Z));
        }
        }
    }
}

void func_80160B6C(u8 *directionSource, void *targetObject, f32 acceleration, f32 maxSpeed) {
    f32 *velocity = (f32 *)((u8 *)targetObject + OBJECT_VELOCITY_X);
    f32 limitedVelocityZ;

    /* Accelerate along the source object's yaw, then optionally cap total speed. */
    velocity[0] += acceleration * func_801C6000(*(f32 *)(directionSource + ACTOR_YAW));
    velocity[2] += acceleration * func_801C4040(*(f32 *)(directionSource + ACTOR_YAW));
    velocity[OBJECT_VELOCITY_SPEED_INDEX] = __builtin_sqrtf(velocity[0] * velocity[0] + velocity[1] * velocity[1] + velocity[2] * velocity[2]);
    if (!(*(s32 *)((u8 *)targetObject + OBJECT_MOTION_FLAGS) & OBJECT_BYPASS_SPEED_LIMIT)) {
        if (maxSpeed < velocity[OBJECT_VELOCITY_SPEED_INDEX]) {
            velocity[0] = velocity[0] * (maxSpeed / velocity[OBJECT_VELOCITY_SPEED_INDEX]);
            velocity[1] = velocity[1] * (maxSpeed / velocity[OBJECT_VELOCITY_SPEED_INDEX]);
            limitedVelocityZ = velocity[2] * (maxSpeed / velocity[OBJECT_VELOCITY_SPEED_INDEX]);
            velocity[2] = limitedVelocityZ;
            velocity[OBJECT_VELOCITY_SPEED_INDEX] = __builtin_sqrtf(velocity[0] * velocity[0] + velocity[1] * velocity[1] + limitedVelocityZ * limitedVelocityZ);
        }
    }
}

/* Accelerate along the source yaw and optionally limit X/Z using cached total speed. */
void func_80160CC4(u8 *directionSource, u8 *targetObject, f32 acceleration, f32 maxHorizontalSpeed) {
    f32 *velocity = (f32 *)(targetObject + OBJECT_VELOCITY_X);

    velocity[0] += acceleration * func_801C6000(*(f32 *)(directionSource + ACTOR_YAW));
    velocity[2] += acceleration * func_801C4040(*(f32 *)(directionSource + ACTOR_YAW));
    if (!(*(s32 *)(targetObject + OBJECT_MOTION_FLAGS) & OBJECT_BYPASS_SPEED_LIMIT)) {
        if (maxHorizontalSpeed < __builtin_sqrtf(velocity[0] * velocity[0] + velocity[2] * velocity[2])) {
            velocity[0] = velocity[0] * (maxHorizontalSpeed / velocity[OBJECT_VELOCITY_SPEED_INDEX]); velocity[2] = velocity[2] * (maxHorizontalSpeed / velocity[OBJECT_VELOCITY_SPEED_INDEX]); velocity[OBJECT_VELOCITY_SPEED_INDEX] = __builtin_sqrtf(velocity[0] * velocity[0] + velocity[1] * velocity[1] + velocity[2] * velocity[2]);
        }
    }
}

/*
 * Returns TRUE if obj is facing target: the X/Z heading from obj's
 * position (+0x34) to target's is within maxAngle radians of obj's yaw (+0x7C).
 * func_80149428 = subtract X/Z, func_80147460 = atan2(y, x),
 * func_801496C8 = wrap angle once, func_8014944C = shortest angle distance.
 */
s32 func_80160E00(u8 *obj, u8 *target, f32 maxAngle) {
    f32 delta[4];
    f32 heading;

    func_80149428(delta, (f32 *)(target + 0x34), (f32 *)(obj + 0x34));
    heading = func_801496C8(func_80147460(delta[0], delta[2]));
    return func_8014944C(*(f32 *)(obj + 0x7c), heading) < maxAngle;
}

/* Returns 1 when `target` lies within `maxAngle` radians of the actor's facing:
 * the XZ heading from the actor's position (+0x34) to the target, wrapped once,
 * is compared with its yaw (+0x7C) by shortest angular distance. */
s32 func_80160E80(u8 *actor, f32 *target, f32 maxAngle) {
    f32 delta[4];
    f32 heading;
    f32 angleOff;

    func_80149428(delta, target, (f32 *)(actor + 0x34)); /* XZ subtract */
    heading = func_80147460(delta[0], delta[2]);         /* atan2 */
    heading = func_801496C8(heading);                    /* wrap one turn */
    angleOff = func_8014944C(*(f32 *)(actor + 0x7c), heading);
    if (maxAngle > angleOff) {
        return 1;
    }
    return 0;
}

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

/* Per-frame update for player/ball coupling and camera focus tracking.
 * Computes forward probe points from the player's yaw, handles special player
 * actions (contact watch, riding/dribbling/carrying the ball, actor mounts),
 * applies ball slope damping, and smoothly updates the camera target, height,
 * lateral lead offset, and horizontal focus position (D_8028FA00). */
void func_80160EFC(void)
{
  extern const f32 D_80107358;
  extern const f32 D_8010735C;
  extern const f64 D_80107360;
  extern const f64 D_80107368;
  extern const f64 D_80107370;
  extern const s32 D_80107378;
  extern const f32 D_80107384;
  extern const f64 D_80107388;
  extern const s32 D_80107390;
  extern const s32 D_80107398;
  extern const s32 D_801073A0;
  extern const s32 D_801073A8;
  extern const s32 D_801073B0;
  extern const s32 D_801073B8;
  extern const f32 D_801073C4;
  extern const f32 D_801073C8;
  extern const f32 D_801073CC;
  extern const f32 D_801073D0;
  extern const f32 D_801073D4;
  extern const s32 D_801073D8;
  extern const s32 D_801073E0;
  extern const s32 D_801073E8;
  extern const s32 D_801073F0;
  extern const s32 D_801073F8;
  extern const s32 D_80107400;
  extern const s32 D_80107408;
  f32 *focusYPtr;
  extern const s32 D_80107410;
  extern const f32 D_8010741C;
  extern const f32 D_80107420;
  extern const f32 D_80107424;
  extern const f32 D_80107428;
  extern const f32 D_8010742C;
  extern const f64 D_80107430;
  extern const s32 D_80107438;
  extern const f32 D_80107444;
  extern const f64 D_80107448;
  extern const f32 D_80107450;
  extern const f32 D_80107454;
  extern const f32 D_80107458;
  extern f32 D_801EEB68;
  float leadDiff;
  extern u8 D_801FAA94[];
  extern u8 D_80202218;
  extern f32 D_8028F93C;
  extern f32 D_8028F950;
  extern f32 D_8028F9C8;
  extern f32 D_8028FB3C;
  extern f32 D_8028F920;
  Vec3F *ballVelVec;
  extern f32 D_8028FA0C;
  extern f32 D_8029F9B8;
  extern f32 D_8028FAB4;
  extern u8 *D_8028FAC8;
  extern u8 *D_8028FAD0;
  extern s16 D_8028FB40;
  extern f32 D_8028FB44;
  extern f32 D_8028FB48;
  extern f32 D_8028FB4C;
  extern s32 D_801EEB70;
  extern s32 D_801EEB74;
  extern s32 D_8028F908;
  extern s32 D_8028FB80;
  extern s32 D_8028FAF8;
  extern s32 D_8028FAC0;
  extern s32 D_8028FB74;
  extern s16 D_8028FBEE;
  extern s32 D_8028FC3C;
  extern f32 D_8028FC40;
  extern f32 D_8028FC44;
  extern s32 D_8028FD20;
  extern f32 D_8028FD24;
  extern f32 D_8028FD28;
  extern s16 D_802900D8;
  extern f32 D_80290330;
  extern f32 D_80290334;
  extern f32 D_80290338;
  extern f32 D_80290360;
  extern s16 D_8029F47C;
  extern s16 D_8029F480;
  extern s32 D_8029F56C;
  extern f32 D_8029F57C;
  extern f32 D_8029F9BC;
  extern f32 D_8029F9C0;
  extern f32 D_8029F9D8;
  extern f32 D_8029F9EC;
  void func_80149568(f32 *);
  void func_80173CE8(s32);
  void func_801B10B8(u8 *, f32 *, f32, f32);
  void func_801B182C(void);
  void func_801B1E70(void);
  s32 func_801B2AF0(void);
  Vec3F offsetVec;
  Vec3F deltaVec;
  f32 deltaQuat[4];
  volatile f32 *playerYawPtr;
  f32 zero;
  s8 *ballAttachState;
  u8 *carrier;
  s16 *mountState;
  u8 **cameraTargetPtr;
  f32 ballVelX;
  s32 *savedContacts;
  s32 *prevContacts;
  f32 *targetVelPtr;
  f32 probeZ;
  f32 leadVel;
  f32 targetY;
  f32 deltaY;
  f32 stepZ;
  f32 mountDeltaX;
  f32 yawDiff;
  f32 targetZ;
  f32 deltaZ;
  f32 horizDistSq;
  f32 maxFocusStep;
  f32 probeY;
  f32 dropStep;
  f32 newLeadX;
  f32 clampedLeadStep;
  f32 stepX;
  f32 attachedX;
  f32 mountPosY;
  f32 mountDeltaY;
  f32 slopeNormalY;
  f32 riseStep;
  f32 probeX;
  f32 stepY;
  f32 attachedY;
  f32 mountPosX;
  f32 mountDeltaZ;
  f32 floorOrNormalDot;
  f32 rawLeadStep;
  f32 targetX;
  f32 deltaX;
  f32 minSepOrAttachedZ;
  f32 mountPosZ;
  f32 maxRiseStep;
  f32 maxDropStep;
  s32 contactEntry;
  f32 absYawDiff;
  f32 *heightOffsetPtr;
  f32 absYawDiffPos;
  f32 absYawDiffNeg;
  f32 negLeadTarget;
  f32 horizDist;
  f32 nextFocusYUp;
  f32 nextFocusYDown;
  f32 posLeadTarget;
  f32 nextMaxSpeed;
  f32 yawFromPiOrGoalY;
  f32 curFocusYOrSpeed;
  f64 ballVelX64;
  f64 ballVelZ64;
  f64 dampX;
  f64 dampZ;
  f64 newBallVelZ;
  f64 yawFromPi64;
  f64 newBallVelX;
  s16 actionFollow;
  s16 actionHold;
  s16 actionDribble;
  s16 actionSlope;
  s16 actionCamera;
  s32 contactIdx;
  s32 *curContacts;
  void *carrierContacts;
  void *slopeNormal;

  /* Save previous camera focus position. */
  *((Vec3F *) (&D_8028FA0C)) = *((Vec3F *) (&D_8028FA00));
  if (D_801E7531 < 0x2E)
  {
    /* Compute forward camera probe points from player position and yaw. */
    playerYawPtr = &D_80290354;
    zero = 0.0f;
    offsetVec.y = zero;
    offsetVec.x = zero;
    offsetVec.z = D_80107358;
    func_801490AC(&offsetVec, &offsetVec, *playerYawPtr);
    probeX = (*((f32 *) (((u8 *) (&D_80290308)) + 4))) + offsetVec.x;
    probeY = D_80290310 + offsetVec.y;
    offsetVec.x = zero;
    probeZ = D_80290314 + offsetVec.z;
    offsetVec.z = D_8010735C;
    offsetVec.y = D_801EEB68;
    *((f32 *) (&D_8028FC3C)) = probeX;
    D_8028FC40 = probeY;
    D_8028FC44 = probeZ;
    func_801490AC(&offsetVec, &offsetVec, *playerYawPtr);
    *((f32 *) (&D_8028FD20)) = (*((f32 *) (((u8 *) (&D_80290310)) + (-4)))) + offsetVec.x;
    D_8028FD24 = D_80290310 + offsetVec.y;
    D_8028FD28 = D_80290314 + offsetVec.z;

    /* Action 0x19: snapshot contact slots, then transition to 0x1B if any change. */
    if ((*((s16 *) (((u8 *) D_802903AC) + 4))) == 0x19)
    {
      contactIdx = 0;
      if (D_8028FBEA < 0xC)
      {
        savedContacts = ((u8 *) (&(*((f32 *) (&D_8028FC3C))))) + 0x470;
        do
        {
          contactEntry = *((s32 *) (((u8 *) (D_802903B0 + (contactIdx * 4))) + 0));
          contactIdx += 1;
          *savedContacts = contactEntry;
          savedContacts++;
        }
        while (contactIdx < 4);
      }
      else
      {
        goto check_objects;
        changed_object:
        func_80167604(0x1B);

        goto clear_motion;
        check_objects:
        prevContacts = (s32 *) (((u8 *) (&D_8028FC3C)) + 0x470);

        curContacts = (s32 *) D_802903B0;
        for (; contactIdx < 4; contactIdx++, curContacts++)
        {
          if (((*curContacts) != 0) && ((*curContacts) != (*prevContacts)))
          {
            goto changed_object;
          }
          prevContacts++;
        }

      }
      clear_motion:
      D_80290330 = (D_80290334 = (D_80290338 = 0.0f));

    }

    /* Special ball action (0x14): align player over the ball with minimum separation. */
    if ((*((s16 *) (((u8 *) D_802903AC) + 4))) == PHYSICS_PLAYER_ACTION_SPECIAL_BALL)
    {
      func_80149318(&(*((f32 *) (&D_8029030C))), &D_8029F9AC);
      { minSepOrAttachedZ = ((*((f32 *) (((u8 *) D_8029FA50) + 112))) + (*((f32 *) (((u8 *) D_802903B0) + 112)))) + 2.0;
        if ((D_80290310 - D_8029F9B0) < minSepOrAttachedZ)
        {
          D_80290310 = (D_8029F9B0 + minSepOrAttachedZ) - 5.0;
        if (D_8029F9D4 > 0.0f)
        {
          D_80290334 = D_8029F9D4 * D_80107370;
        }
        else
        {
          D_80290334 = 0.0f;
        }
      } }
    }

    /* Ball attached to a carrier actor (D_8029F486 == 1): track carrier or bone position. */
    ballAttachState = (s8 *) (&D_8029F486);
    if ((*ballAttachState) == 1)
    {
      D_8029F480 = 0;
      if (D_8029F47C == (-1))
      {
        if ((*((s16 *) (((u8 *) D_8029F46C) + 32))) == 0x1E)
        {
          func_80149318(D_8029F46C + 0x34, &D_8029F9AC);
          func_80149318(((u8 *) (&D_8029F9AC)) + 0x24, D_8029F46C + 0x58);
          *((f32 *) (((u8 *) D_8029F46C) + 92)) = D_8029F9D4;
          carrier = *((u8 **) (((u8 *) (&D_8029F468)) + 4));
          carrierContacts = *((s32 *) (((u8 *) carrier) + 216));
          *((f32 *) (((u8 *) carrier) + 56)) = (((D_8029F9B0 + (*((f32 *) (((u8 *) D_8029FA50) + 112)))) + (*((f32 *) (((u8 *) carrierContacts) + 112)))) - (*((f32 *) (((u8 *) carrierContacts) + 92)))) - (*((f32 *) (&D_80107378)));
        }
        else
        {
          f32 *ballPosX = &D_8029F9AC;
          func_801490AC(&deltaVec, ((u8 *) ballAttachState) - 0x16, *((f32 *) (((u8 *) D_8029F46C) + 124)));
          targetX = (*((f32 *) (((u8 *) D_8029F46C) + 52))) + deltaVec.x;
          offsetVec.x = targetX;
          deltaX = (*ballPosX) - targetX;
          targetY = (*((f32 *) (((u8 *) D_8029F46C) + 56))) + deltaVec.y;
          offsetVec.y = targetY;
          deltaY = D_8029F9B0 - targetY;
          targetZ = (*((f32 *) (((u8 *) D_8029F46C) + 60))) + deltaVec.z;
          deltaZ = D_8029F9B4 - targetZ;
          deltaVec.x = deltaX;
          deltaVec.y = deltaY;
          stepX = deltaX * (*((f64 *) (((u8 *) (&D_80107378)) + 4)));
          offsetVec.z = targetZ;
          deltaVec.x = stepX;
          stepY = deltaY * (*((f64 *) (((u8 *) (&D_80107378)) + 4)));
          deltaVec.z = deltaZ;
          *ballPosX -= stepX;
          stepZ = deltaZ * (*((f64 *) (((u8 *) (&D_80107378)) + 4)));
          deltaVec.y = stepY;
          D_8029F9B0 -= stepY;
          deltaVec.z = stepZ;
          D_8029F9B4 -= stepZ;
        }
      }
      else
      {
        f32 *ballPosX = &D_8029F9AC;
        ;
        *((Vec3F *) ballPosX) = *((Vec3F *) (((u8 *) ((D_8029F47C * 0x24) + (*((s32 *) (((u8 *) D_8029F46C) + 216))))) + 88));
        func_801499A0(&offsetVec, ((u8 *) ballAttachState) - 0x16, D_8029F46C + 0x9C);
        attachedX = (*ballPosX) + offsetVec.x;
        attachedY = D_8029F9B0 + offsetVec.y;
        minSepOrAttachedZ = D_8029F9B4 + offsetVec.z;
        *ballPosX = attachedX;
        D_8029F9B0 = attachedY;
        D_8029F9B4 = minSepOrAttachedZ;
        *ballPosX = attachedX + (*((f32 *) (((u8 *) D_8029F46C) + 88)));
        D_8029F9B0 = attachedY + (*((f32 *) (((u8 *) D_8029F46C) + 92)));
        minSepOrAttachedZ = minSepOrAttachedZ + (*((f32 *) (((u8 *) D_8029F46C) + 96)));
        D_8029F9B4 = minSepOrAttachedZ;
      }
      if ((*((s16 *) (((u8 *) D_8029F46C) + 32))) == 0x1C)
      {
        func_80149568(&deltaVec);
        func_801B10B8(&D_8029F978, &deltaVec, -3.0f, 0.5f);
        if (func_80148E48(((u8 *) (&D_8029F978)) + 0x34, D_8029F46C + 0x34) < ((*((f32 *) (((u8 *) D_8029F46C) + 48))) - D_80107384))
        {
          D_8029F486 = 5;
          D_8029F9D0 = (*((f32 *) (((u8 *) (&D_8029F978)) + 52))) - D_8029F9B8;
          D_8029F9D4 = D_8029F9B0 - D_8029F9BC;
          D_8029F9A0 |= 1;
          D_8029F9D8 = D_8029F9B4 - D_8029F9C0;
          D_8029F9A0 &= ~0x18;
        }
      }
      else
      {
        {
          f32 *axisAngleRad = &D_801ED3EC;
          *axisAngleRad = (*((f32 *) (((u8 *) D_8029F46C) + 124))) - D_8029F57C;
          func_80148C3C(deltaQuat, ((u8 *) axisAngleRad) - 0xC);
        }
        func_801488C0(D_8029FA14, deltaQuat, D_8029FA14);
      }
    }

    /* Player mounted on an actor (D_8028FBEE == 3 or 4): follow mount root or bone. */
    mountState = &D_8028FBEE;
    if (((u32) (((u16) (*mountState)) - 3)) < 2)
    {
      if ((*mountState) == 3)
      {
        func_80173CE8(2);
        D_8028FBD8 = 2;
        D_80290360 = *((f32 *) (((u8 *) D_802900C8) + 124));
      }
      if (D_802900D8 == (-1))
      {
        if ((*((s32 *) (((u8 *) D_802900C8) + 40))) & 0x4000)
        {
          func_801499A0(&deltaVec, ((u8 *) mountState) + 0x4DE, D_802900C8 + 0x9C);
        }
        else
        {
          func_801490AC(&deltaVec, ((u8 *) mountState) + 0x4DE, *((f32 *) (((u8 *) D_802900C8) + 124)));
        }
        mountPosX = (*((f32 *) (((u8 *) D_802900C8) + 52))) + deltaVec.x;
        offsetVec.x = mountPosX;
        mountPosY = (*((f32 *) (((u8 *) D_802900C8) + 56))) + deltaVec.y;
        offsetVec.y = mountPosY;
        mountPosZ = (*((f32 *) (((u8 *) D_802900C8) + 60))) + deltaVec.z;
        mountDeltaX = (*((f32 *) (&D_8029030C))) - mountPosX;
        mountDeltaY = D_80290310 - mountPosY;
        mountDeltaZ = D_80290314 - mountPosZ;
        deltaVec.y = mountDeltaY;
        deltaVec.x = mountDeltaX;
        offsetVec.z = mountPosZ;
        deltaVec.z = mountDeltaZ;
        if (D_8028FBEE != 4)
        {
          deltaVec.x = mountDeltaX * D_80107388;
          deltaVec.y = mountDeltaY * D_80107388;
          deltaVec.z = mountDeltaZ * D_80107388;
        }
        *((f32 *) (&D_8029030C)) = (*((f32 *) (&D_8029030C))) - deltaVec.x;
        D_80290310 -= deltaVec.y;
        D_80290314 -= deltaVec.z;
      }
      else
      {
        ;
        *((Vec3F *) (&D_8029030C)) = *((Vec3F *) (((u8 *) ((D_802900D8 * 0x24) + (*((s32 *) (((u8 *) D_802900C8) + 216))))) + 88));
        func_801499A0(&offsetVec, ((u8 *) mountState) + 0x4DE, D_802900C8 + 0x9C);
        *((f32 *) (&D_8029030C)) = (*((f32 *) (&D_8029030C))) + offsetVec.x;
        D_80290310 += offsetVec.y;
        D_80290314 += offsetVec.z;
      }
      *((Vec3F *) (&D_80290330)) = *((Vec3F *) (D_802900C8 + 88));
    }

    /* Update player/ball follow and dribble coupling based on player action. */
    actionFollow = *((s16 *) (((u8 *) D_802903AC) + 4));
    if ((((actionFollow == PHYSICS_PLAYER_ACTION_RIDE_BALL) | (actionFollow == 0xC)) != 0) || (actionFollow == 0xF))
    {
      func_801B182C();
    }
    actionDribble = *((s16 *) (((u8 *) D_802903AC) + 4));
    if (((actionDribble == PHYSICS_PLAYER_ACTION_DRIBBLE) | (actionDribble == 0x2B)) != 0)
    {
      func_801B1E70();
      *((Vec3F *) (&D_8029F9D0)) = *((Vec3F *) (&D_80290330));
    }
    actionHold = *((s16 *) (((u8 *) D_802903AC) + 4));
    if (actionHold == 0xE)
    {
      u8 *playerPos = (u8 *) (&D_8029030C);
      u8 *ballPos = (u8 *) (&D_8029F9AC);
      func_80149318(playerPos, ballPos);
      func_80149318(playerPos + 0x24, ballPos + 0x24);
      if ((D_8029F56C == 0) && ((*((f32 *) (((u8 *) (&D_801FAA94)) + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE)))) < (*((f32 *) (&D_80107390)))))
      {
          *((f32 *) (((u8 *) ballPos) + 36)) = (*((f32 *) (((u8 *) ballPos) + 36))) * (*((f64 *) (((u8 *) (&D_80107390)) + 4)));

        D_8029F9D8 = D_8029F9D8 * (*((f64 *) (((u8 *) (&D_80107390)) + 4)));
      }
      floorOrNormalDot = (D_8029F9B0 - (*((f64 *) (((u8 *) (&D_80107398)) + 4)))) + (*((f32 *) (((u8 *) D_8029FA50) + 112)));
      {
        f32 *playerPosY = &D_80290310;
        if ((*playerPosY) < floorOrNormalDot)
        {
          *playerPosY = floorOrNormalDot;
          if (D_80290334 < 0.0f)
          {
            D_80290334 = 0.0f;
          }
        }
      }
    }
    else
    {
      s32 *cameraTrackFlag = &D_8028FB6C;
      if (((*cameraTrackFlag) != 0) && ((D_8028FAC8 != (&(*((f32 *) (&D_8029030C))))) || ((*((s16 *) (((u8 *) D_802903AC) + 4))) != PHYSICS_PLAYER_ACTION_DRIBBLE)))
      {
        func_80148D0C(((u8 *) cameraTrackFlag) - 0x16C, D_8028FAD0, 0.4f);
      }
    }

    /* Damp ball XZ velocity on shallow slopes when rolling freely. */
    {
      f32 *ballSpeedPtr = &D_8029F9EC;
      if (((*ballSpeedPtr) != 0.0f) && ((*((u8 *) (((u8 *) D_8029FA50) + 393))) == 0))
      {
        actionSlope = *((s16 *) (((u8 *) D_802903AC) + 4));
        if (((actionSlope != PHYSICS_PLAYER_ACTION_RIDE_BALL) & (actionSlope != 0xE)) && ((*((u8 *) (((u8 *) D_8029FA50) + 392))) != 0))
        {
          slopeNormal = *((s32 *) (((u8 *) D_8029FA50) + 0));
          if (slopeNormal != ((void *) 0))
          {
            slopeNormalY = *((f32 *) (((u8 *) slopeNormal) + 4));
            if ((*((f64 *) (((u8 *) (&D_801073A0)) + 4))) < slopeNormalY)
            {
              f32 *ballVelXPtr = ballSpeedPtr - 7;
              Vec3F *ballVel = (Vec3F *) (&D_8029F9D0);
              ballVelX = *ballVelXPtr;
                              floorOrNormalDot = ((ballVelX * (*((f32 *) (((u8 *) slopeNormal) + 0)))) + (D_8029F9D4 * slopeNormalY)) + (D_8029F9D8 * (*((f32 *) (((u8 *) slopeNormal) + 8))));
                if (!(floorOrNormalDot > 0.0f)) floorOrNormalDot = -floorOrNormalDot;
                floorOrNormalDot = floorOrNormalDot / (*ballSpeedPtr);
              dampX = (*((f64 *) (((u8 *) (&D_801073A8)) + 4))) - floorOrNormalDot;
              ballVelX64 = ballVelX;
              if (dampX < (*((f64 *) (((u8 *) (&D_801073A0)) + 4))))
              {
                newBallVelX = ballVelX64 * dampX;
              }
              else
              {
                newBallVelX = ballVelX64 * (*((f64 *) (((u8 *) (&D_801073A0)) + 4)));
              }
              dampZ = (*((f64 *) (((u8 *) (&D_801073B0)) + 4))) - floorOrNormalDot;
              *ballVelXPtr = newBallVelX;
              ballVelVec = ballVel;
              ballVelZ64 = D_8029F9D8;
              if (dampZ < (*((f64 *) (((u8 *) (&D_801073B8)) + 4))))
              {
                newBallVelZ = ballVelZ64 * dampZ;
              }
              else
              {
                newBallVelZ = ballVelZ64 * (*((f64 *) (((u8 *) (&D_801073B8)) + 4)));
              }
              ballVelVec->z = newBallVelZ;
            }
          }
        }
      }
    }

    /* Update camera target selection, focus height, lateral lead, and XZ follow. */
    if (D_8028FB6C != 0)
    {
      func_80165230();
      if ((D_8028FAF4 == 0) && (D_8028FB80 == 0))
      {
        if ((D_8028FAC8 == (&(*((f32 *) (&D_8029030C))))) && (func_801B2AF0() != 0))
        {
          D_8028FAC8 = &D_8029F9AC;
          targetVelPtr = ((u8 *) (&D_8029F9AC)) + 0x24;
          goto block_83;
        }
        cameraTargetPtr = &D_8028FAC8;
        if ((*cameraTargetPtr) == ((u8 *) (&D_8029F9AC)))
        {
          actionCamera = *((s16 *) (((u8 *) D_802903AC) + 4));
          if (((actionCamera == PHYSICS_PLAYER_ACTION_DRIBBLE) | (actionCamera == 0x10)) != 0)
          {
            *cameraTargetPtr = (u8 *) (&D_8029030C);
            targetVelPtr = ((u8 *) (&(*((f32 *) (&D_8029030C))))) + 0x24;
            block_83:
            D_8028FAD0 = targetVelPtr;

          }
        }
        ;
        if (((D_8028FAC8 == (&(*((f32 *) (&D_8029030C))))) || (D_8028FAC8 == (&D_8029F9AC))) && ((*((s16 *) (((u8 *) D_802903AC) + 4))) == 0xE))
        {
          D_8028FAB4 = D_8029F9B0 + ((D_80290310 - D_8029F9B0) / D_801073C4);
        }
        else
        {
          D_8028FAB4 = (*((f32 *) (((u8 *) D_8028FAC8) + 4))) + D_8028FAB0;
        }
        heightOffsetPtr = &D_8028FAB0;
        {
          f32 *camFocusY = heightOffsetPtr - 43;
          *heightOffsetPtr = D_8028F9C8 / D_801073C8;
          if ((*(focusYPtr = &(*camFocusY))) < D_8028FAB4)
          {
            maxRiseStep = D_8028FB3C / D_801073CC;
            riseStep = (D_8028FAB4 - (*focusYPtr)) / D_801073D0;
            if (riseStep < maxRiseStep)
            {
              nextFocusYUp = (*camFocusY) + riseStep;
            }
            else
            {
              nextFocusYUp = (*focusYPtr) + maxRiseStep;
            }
            *camFocusY = nextFocusYUp;
          }
        }
        {
                    f32 *camFocusYDown = &D_8028FA04;
            if ((curFocusYOrSpeed = *camFocusYDown) > (yawFromPiOrGoalY = D_8028FAB4))
            {
              maxDropStep = D_8028FB3C / D_801073D4;
              dropStep = ((*camFocusYDown) - yawFromPiOrGoalY) / (*((f32 *) (&D_801073D8)));
            if (dropStep < maxDropStep)
            {
              nextFocusYDown = (*camFocusYDown) - dropStep;
            }
            else
            {
              nextFocusYDown = maxDropStep;
              nextFocusYDown = (*camFocusYDown) - nextFocusYDown;
            }
            *camFocusYDown = nextFocusYDown;
          }
        }
        {
          f32 *camVelY = &D_8028F93C;
          *camVelY = (*camVelY) * (*((f64 *) (((u8 *) (&D_801073D8)) + 4)));
        }
        if ((D_8028FB7C != 0) && (D_801E7542 == 0))
        {
          if ((*((s16 *) (((u8 *) D_802903AC) + 4))) != PHYSICS_PLAYER_ACTION_SPECIAL_BALL)
          {
            yawDiff = func_801494CC(D_8028F95C, func_801496C8(D_80290354 + (*((f64 *) (((u8 *) (&D_801073E0)) + 4)))));
          }
          else
          {
            yawDiff = func_801494CC(D_8028F95C, D_80290354);
          }
          absYawDiff = yawDiff;
          if (!(yawDiff > 0.0f))
          {
            absYawDiff = -yawDiff;
          }
          if ((3.141592654 - absYawDiff) > 0.0)
          {
            do
            {
              absYawDiffPos = yawDiff;
              if (!(yawDiff > 0.0f))
              {
                absYawDiffPos = -yawDiff;
              }
            }
            while (0);
            yawFromPi64 = 3.141592654 - absYawDiffPos;
          }
          else
          {
            absYawDiffNeg = yawDiff;
            if (!(yawDiff > 0.0f))
            {
              absYawDiffNeg = -yawDiff;
            }
            yawFromPi64 = -(3.141592654 - absYawDiffNeg);
          }
                                          yawFromPiOrGoalY = (f32) yawFromPi64;
                      ;
          if ((yawFromPiOrGoalY < 0.4) || ((3.141592654 - 0.4) < yawFromPiOrGoalY))
          {
            D_8028FB48 = 0.0f;
          }
          else
            if ((((*((f64 *) (((u8 *) (&D_80107400)) + 4))) < yawFromPiOrGoalY) && (yawFromPiOrGoalY < (*((f64 *) (((u8 *) (&D_80107408)) + 4))))) || ((yawFromPiOrGoalY < (*((f64 *) (((u8 *) (&D_80107410)) + 4)))) && ((*((f64 *) (((u8 *) (&D_80107400)) + 4))) < yawFromPiOrGoalY)))
          {
            if (yawDiff > 0.0f)
            {
              posLeadTarget = D_8028F9C8 / D_8010741C;
              if (!(posLeadTarget < D_80107420))
              {
                posLeadTarget = D_80107420;
              }
              D_8028FB48 = posLeadTarget;
            }
            else
            {
              negLeadTarget = (-D_8028F9C8) / D_80107424;
              if (negLeadTarget < D_80107428)
              {
                negLeadTarget = D_80107428;
              }
              D_8028FB48 = negLeadTarget;
            }
          }
          leadDiff = D_8028FB48 - D_8028FB44;
          rawLeadStep = leadDiff / D_8010742C;
          clampedLeadStep = rawLeadStep;
                                  if (clampedLeadStep > 0.0f)
            {
              f32 clampedStep = *((f32 *) (&D_80107438));
              if (rawLeadStep < D_80107430)
              {
                clampedStep = rawLeadStep;
              }
              clampedLeadStep = clampedStep;
            }
            else
            {
              f32 clampedStep = rawLeadStep;
              if (clampedLeadStep < (*((f64 *) (((u8 *) (&D_80107438)) + 4))))
              {
                clampedStep = D_80107444;
              }
              clampedLeadStep = clampedStep;
            }
            {
              f32 *leadVelPtr = &D_8028FB4C;
              f32 prevLeadVel = *leadVelPtr;
              leadVel = (prevLeadVel + clampedLeadStep) * D_80107448;
            newLeadX = D_8028FB44 + leadVel;
            offsetVec.y = 0.0f;
            offsetVec.z = 0.0f;
            *leadVelPtr = leadVel;
            D_8028FB44 = newLeadX;
            offsetVec.x = newLeadX;
          }
          func_801490AC(&offsetVec, &offsetVec, D_8028F95C);
        }
        else
        {
          goto block_138;
        }
      }
      else
      {
        block_138:
        offsetVec.x = (offsetVec.y = (offsetVec.z = 0.0f));

      }
      {
        s32 *cameraLockFlag = &D_8028FB80;
        if ((*cameraLockFlag) == 0)
        {
          func_80149428(&deltaVec, D_8028FAC8, ((u8 *) cameraLockFlag) - 0x180);
          func_8014932C(&deltaVec, &offsetVec);
          if (D_8028FB40 != 0)
          {
            D_8028FB40 -= 1;
          }
          else
          {
            f32 *maxFocusSpeed = (f32 *) (((u8 *) cameraLockFlag) - 0x44);
            do if ((curFocusYOrSpeed = *maxFocusSpeed) < D_80107450)
            {
              f32 speedStep = (D_80107450 - (*maxFocusSpeed)) / D_80107454;
              if (speedStep < 1.0f)
              {
                nextMaxSpeed = (*maxFocusSpeed) + speedStep;
              }
              else
              {
                nextMaxSpeed = (*maxFocusSpeed) + 1.0f;
              }
              *maxFocusSpeed = nextMaxSpeed;
            } while (0);
          }
          {
            f32 *maxFocusSpeedPtr = &D_8028FB3C;
            horizDistSq = (deltaVec.x * deltaVec.x) + (deltaVec.z * deltaVec.z);
            maxFocusStep = *maxFocusSpeedPtr;
            horizDist = sqrtf(horizDistSq);
            if (maxFocusStep < horizDist)
            {
              func_80148D50(((u8 *) maxFocusSpeedPtr) - 0x13C, &deltaVec, maxFocusStep / horizDist);
            }
            else
            {
              func_8014932C(((u8 *) maxFocusSpeedPtr) - 0x13C, &deltaVec);
            }
          }
        }
      }
      D_8028FB7C = 1;
    }
  }
}

/* Start an eligible collision teleport, coordinating player and ball when required. */
s32 func_8016225C(u8 *object, u8 *contactActor) {
    u8 *teleport;
    u8 *candidate = *(u8 **)(contactActor + TELEPORT_ACTOR_DEFINITION);

    if (candidate == 0) {
        goto fail;
    }
    if (((TeleportDefinition *)candidate)->type != TELEPORT_TYPE_COLLISION) {
        goto fail;
    }
    if (*(s16 *)(object + TELEPORT_OBJECT_TYPE) == ((TeleportDefinition *)candidate)->type) {
        teleport = candidate;
        if (((TeleportDefinition *)teleport)->flags & TELEPORT_ALLOW_PLAYER) {
            if (!func_8016225C_check()) {
                s16 playerState = *(s16 *)(D_802903AC + TELEPORT_STATE_ACTION);
                if (playerState != 0x14 && playerState != 6) {
                    goto start_teleport;
                }
            }
        }
    } else {
        teleport = candidate;
    }
    if (*(s16 *)(object + TELEPORT_OBJECT_TYPE) == TELEPORT_OBJECT_BALL) {
        u16 flags = ((TeleportDefinition *)teleport)->flags;
        if (flags & TELEPORT_ALLOW_BALL) {
            s16 playerState = *(s16 *)(D_802903AC + TELEPORT_STATE_ACTION);
            if (playerState != 5 && playerState != 3) {
                goto start_teleport;
            }
        }
        if (*(s16 *)(D_802903AC + TELEPORT_STATE_ACTION) == 3) {
            if (flags & TELEPORT_ALLOW_BALL_IN_STATE_3) {
                goto start_teleport;
            }
        }
    }
    if (!(((TeleportDefinition *)teleport)->flags & TELEPORT_ALLOW_OTHER_OBJECTS)) {
        goto fail;
    }
    if ((u16)(*(u16 *)(object + TELEPORT_OBJECT_TYPE) - 3) < 2) {
        goto fail;
    }
start_teleport:
    if (object == (u8 *)&D_8029F978) {
        switch (*(s16 *)(D_802903AC + TELEPORT_STATE_ACTION)) {
        case 0xe: {
            s32 *playerFlags = &D_80290300;
            func_80167604(9);
            *playerFlags &= ~0x40;
            break;
        }
        case 0x14:
            func_80167604(1);
            D_8029F9A4 = 0;
            break;
        }
    } else if (object == (u8 *)&D_802902D8) {
        D_802901DC = 0;
        D_802902FE = 100;
    }
    if (*(s16 *)(D_802903AC + TELEPORT_STATE_ACTION) == 3 && (object == (u8 *)&D_802902D8 || object == (u8 *)&D_8029F978)) {
        if (*(s32 *)(D_802903AC + TELEPORT_STATE_DEFINITION) != 0 || *(s32 *)((u8 *)D_8029FA4C + TELEPORT_STATE_DEFINITION) != 0) {
            goto fail;
        }
        *(u8 **)(D_802903AC + TELEPORT_STATE_DEFINITION) = teleport;
        ((ObjectDataPointer *)&D_802903AC)->data[TELEPORT_STATE_TIMER] = ((TeleportDefinition *)teleport)->shrinkFrames;
        *(u8 **)((u8 *)D_8029FA4C + TELEPORT_STATE_DEFINITION) = teleport;
        ((u8 *)((struct { Words13 *p; } *)&D_8029FA4C)->p)[TELEPORT_STATE_TIMER] = ((TeleportDefinition *)teleport)->shrinkFrames;
    } else {
        if (((TeleportDefinition *)teleport)->flags & TELEPORT_SWAP_PLAYER_AND_BALL) {
            D_802900DC = ((TeleportDefinition *)teleport)->shrinkFrames + ((TeleportDefinition *)teleport)->growFrames;
            if (object == (u8 *)&D_802902D8) {
                *(u8 **)((u8 *)D_8029FA4C + TELEPORT_STATE_DEFINITION) = teleport;
                ((u8 *)((struct { Words13 *p; } *)&D_8029FA4C)->p)[TELEPORT_STATE_TIMER] = teleport[TELEPORT_SHRINK_FRAMES_LOW_BYTE] + 1;
            } else if (object == (u8 *)&D_8029F978) {
                *(u8 **)(D_802903AC + TELEPORT_STATE_DEFINITION) = teleport;
                ((ObjectDataPointer *)&D_802903AC)->data[TELEPORT_STATE_TIMER] = teleport[TELEPORT_SHRINK_FRAMES_LOW_BYTE] + 1;
            }
        }
        *(u8 **)(*(u8 **)(object + TELEPORT_OBJECT_STATE) + TELEPORT_STATE_DEFINITION) = teleport;
        (*(u8 **)(object + TELEPORT_OBJECT_STATE))[TELEPORT_STATE_TIMER] = ((TeleportDefinition *)teleport)->shrinkFrames;
    }
    func_80178134(TELEPORT_SOUND_START, (f32 *)(object + TELEPORT_OBJECT_POSITION), 0x64, 0x80);
    return 1;

fail:
    return 0;
}

/* Free an object's allocated buffers: the one at 0x1C always (when 0xC8 is set),
 * and the optional ones at 0xD0/0xD8/0xDC/0xCC/0xD4 selected by bits 0-4 of
 * `flags`. func_80141720 frees the block a pointer slot refers to. */
void func_801625F0(s32 object, s32 flags) {
    if (*(s32 *)(object + 0xC8) != 0) {
        func_80141720(object + 0x1C);
    }
    if (flags & 1) {
        func_80141720(object + 0xD0);
    }
    if (flags & 2) {
        func_80141720(object + 0xD8);
    }
    if (flags & 4) {
        func_80141720(object + 0xDC);
    }
    if (flags & 8) {
        func_80141720(object + 0xCC);
    }
    if (flags & 0x10) {
        func_80141720(object + 0xD4);
    }
}

/* Recursively free the geometry allocation of a model tree node, its children and its siblings. */
void func_80162694(s32 nodeAddress) {
    if ((s32)((ModelTreeNode *)nodeAddress)->child != 0) {
        func_80162694((s32)((ModelTreeNode *)nodeAddress)->child);
    }
    if ((s32)((ModelTreeNode *)nodeAddress)->sibling != 0) {
        func_80162694((s32)((ModelTreeNode *)nodeAddress)->sibling);
    }
    func_80141720(&((ModelTreeNode *)nodeAddress)->geometry->allocation);
}

/* model_free_sprites: recursively free every sprite of a model tree node and
 * its children and siblings, logging "Freeing sprite %d from %s\n"
 * (D_8010745C) through the disabled debug hook func_80139D70. */
void func_801626EC(s32 node) {
    s32 i;

    if (*(s32 *)(node + MODEL_NODE_SPRITES) != 0) {
        for (i = 0; i < *(s32 *)(node + MODEL_NODE_SPRITE_COUNT); i++) {
            func_80141720((s32 *)(*(s32 *)(node + MODEL_NODE_SPRITES) + i * MODEL_SPRITE_ENTRY_BYTES + MODEL_SPRITE_NODE));
            func_80139D70(func_801D2150(&D_8025D578, D_8010745C, i, node + MODEL_NODE_NAME));
        }
    }
    if (*(s32 *)(node + MODEL_NODE_CHILD) != 0) {
        func_801626EC(*(s32 *)(node + MODEL_NODE_CHILD));
    }
    if (*(s32 *)(node + MODEL_NODE_SIBLING) != 0) {
        func_801626EC(*(s32 *)(node + MODEL_NODE_SIBLING));
    }
}

/* Unlink an object and free its components, model sprites and own allocation. */
void func_801627AC(s32 object) {
    s32 spriteIndex;
    s32 spriteOffset;
    s32 *modelNode;
    s32 *model;
    s32 *rootNode;
    s32 stackPadding[2];

    func_8015CB44(object);
    if (*(s32 *)(object + OBJECT_COMPONENT_MODEL) != 0) {
        func_80141720((s32 *)(object + OBJECT_CACHED_MATRICES));
    }
    func_80141720((s32 *)(object + ACTOR_PHYSICS));
    func_80141720((s32 *)(object + ACTOR_MODEL_STATE));
    func_80141720((s32 *)(object + ACTOR_ANIMATION));
    func_80141720((s32 *)(object + OBJECT_SHADOW_COMPONENT));
    func_80141720((s32 *)(object + OBJECT_COMPONENT_STATS_OFFSET));
    model = *(s32 **)(object + OBJECT_COMPONENT_MODEL);
    if (model != 0) {
        rootNode = (s32 *)model[ACTOR_MESH_ROOT / 4];
        if (rootNode != 0) {
            modelNode = rootNode;
            if (modelNode[ACTOR_MODEL_ITEMS_WORD] != 0) {
                spriteIndex = 0;
                if (modelNode[ACTOR_MODEL_ITEM_COUNT_WORD] > 0) {
                    spriteOffset = 0;
                    do {
                        func_80141720((s32 *)(modelNode[ACTOR_MODEL_ITEMS_WORD] + spriteOffset + MODEL_SPRITE_NODE));
                        func_80139D70(func_801D2150(&D_8025D578, D_8010745C, spriteIndex, (s32)modelNode + MODEL_NODE_NAME));
                        spriteIndex++;
                        spriteOffset += MODEL_SPRITE_ENTRY_BYTES;
                    } while (spriteIndex < modelNode[ACTOR_MODEL_ITEM_COUNT_WORD]);
                }
            }
            if (modelNode[ACTOR_MODEL_CHILD_WORD] != 0) {
                func_801626EC(modelNode[ACTOR_MODEL_CHILD_WORD]);
            }
            if (modelNode[ACTOR_MODEL_SIBLING_WORD] != 0) {
                func_801626EC(modelNode[ACTOR_MODEL_SIBLING_WORD]);
            }
        }
        func_80141720((s32 *)(object + TEXCOORD_OBJECT_COLLISION_FACES));
    }
    func_80141720((s32 *)&object);
}

/* Accelerate along a surface-relative heading, with an optional three-axis speed limit. */
void func_801628F4(s32 objectAddress, f32 *surfaceNormal, f32 acceleration, f32 maxSpeed, f32 yaw, s32 limitAllAxes)
{
    extern f32 D_80107478;
    extern f64 D_80107480;
    extern f32 D_80107484;
    extern f32 D_80107488;
    f32 func_80147114(f32);
    void func_80160920(s32, f32, f32, void *, s32);
    QuaternionComponents headingRotation;
    QuaternionComponents surfaceRotation;
    AxisAngle surfaceTilt;
    if (surfaceNormal[1] == D_80107478) {
        D_801ED3EC = func_801496C8(*(f64 *)((u8 *)&D_80107478 + 4) - yaw);
        surfaceTilt[AXIS_ANGLE_Y] = 0.0f;
        surfaceTilt[AXIS_ANGLE_Z] = 0.0f;
        surfaceTilt[AXIS_ANGLE_RADIANS] = D_80107484;
        surfaceTilt[AXIS_ANGLE_X] = D_80107488;
    } else {
        D_801ED3EC = yaw;
        func_801470F8(surfaceTilt, surfaceNormal);
        func_80149604(surfaceTilt);
        surfaceTilt[AXIS_ANGLE_RADIANS] = func_80147114(surfaceNormal[1]);
    }
    func_80148C3C(headingRotation, (f32 *)D_801ED3E0);
    func_80148C3C(surfaceRotation, surfaceTilt);
    func_801488C0((Quaternion *)headingRotation, surfaceRotation, headingRotation);
    func_80160920(objectAddress, acceleration, maxSpeed, headingRotation, limitAllAxes);
}

extern f32 D_8010748C;
extern f32 D_80107490;
extern f32 D_80107494;

/* Accelerate using surface tilt composed with a supplied heading quaternion. */
void func_80162A38(s32 objectAddress, f32 *surfaceNormal, f32 acceleration, f32 maxSpeed, f32 *headingQuaternion, s32 limitAllAxes)
{
    Quaternion alignedRotation;
    QuaternionComponents surfaceRotation;
    AxisAngle surfaceTilt;

    alignedRotation = *(Quaternion *)headingQuaternion;
    if (surfaceNormal[1] == D_8010748C) {
        surfaceTilt[AXIS_ANGLE_Y] = 0.0f;
        surfaceTilt[AXIS_ANGLE_Z] = 0.0f;
        surfaceTilt[AXIS_ANGLE_RADIANS] = D_80107490;
        surfaceTilt[AXIS_ANGLE_X] = D_80107494;
    } else {
        func_801470F8(surfaceTilt, surfaceNormal);
        func_80149604(surfaceTilt);
        surfaceTilt[AXIS_ANGLE_RADIANS] = func_80147114(surfaceNormal[1]);
    }
    func_80148C3C(surfaceRotation, surfaceTilt);
    func_801488C0(&alignedRotation, surfaceRotation, &alignedRotation);
    func_80160920(objectAddress, acceleration, maxSpeed, &alignedRotation, limitAllAxes);
}

/* Gives the object a random unit direction vector at +0xAC: each component is
 * random_below(21) - 10 (func_80147000), then normalized (func_80149568). */
void func_80162B60(u8 *obj) {
    *(f32 *)(obj + 0xAC) = (f32)(func_80147000(21) - 10);
    *(f32 *)(obj + 0xB0) = (f32)(func_80147000(21) - 10);
    *(f32 *)(obj + 0xB4) = (f32)(func_80147000(21) - 10);
    func_80149568(obj + 0xAC);
}

/* Original compiler padding. */
const u32 D_80162BD4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000400, 0x00009601
};

void func_80162BE0(void) {
    extern u8 D_8028F8E0[], D_8028F9CC[];
    extern s16 D_8028F900;
    extern f32 D_801074C4, D_801074C8, D_801074CC, D_801074D0, D_801074D4;
    extern f32 D_8028FA3C;
    extern struct { f32 *p; } D_8028FA9C;
    extern s32 D_801EEB70, D_801EEB74;
    extern s16 D_801EEB78;
    extern f32 D_801EEB7C[], D_8028FB24;
    extern u8 *D_8028FAC8;
    void func_80162D18(void);
    f32 focusX, focusY, focusZ, focusResponse, unused;

    /* Initialize the camera eye and focus objects, then set player-follow offsets. */
    func_8013FBC0(D_8028F8E0, ACTOR_OBJECT_PREFIX_BYTES);
    func_80142700(D_8028F8E0, OBJECT_COMPONENT_PHYSICS | OBJECT_COMPONENT_COLLISION | OBJECT_COMPONENT_STATS);
    D_8028F900 = 0;
    func_80162D18();
    func_8013FBC0(D_8028F9CC, ACTOR_OBJECT_PREFIX_BYTES);
    func_80142700(D_8028F9CC, OBJECT_COMPONENT_PHYSICS);
    focusX = D_801074C4; focusY = D_801074C8; focusZ = D_801074CC; focusResponse = D_801074D0;
    ((ScalarF32 *)&D_8028FA00)->value = focusX;
    ((ScalarF32 *)&D_8028FA04)->value = focusY;
    ((ScalarF32 *)&D_8028FA08)->value = focusZ;
    ((ScalarF32 *)&D_8028FA3C)->value = focusResponse;
    D_8028FA9C.p[CAMERA_FOCUS_PHYSICS_UNK1C_INDEX] = D_801074D4;
    D_8028FA9C.p[CAMERA_FOCUS_PHYSICS_SPEED_INDEX] = focusY;
    D_8028FA9C.p[CAMERA_FOCUS_PHYSICS_RESPONSE_INDEX] = ((ScalarF32 *)&D_8028FA00)[CAMERA_FOCUS_RESPONSE_FROM_POSITION_INDEX].value;
    ((u8 **)&D_8028F9CC)[CAMERA_FOLLOW_POSITION_FROM_FOCUS_INDEX] = (u8 *)&D_8029030C;
    ((ScalarF32 *)&D_8028FB28)->value = D_801EEB70;
    ((ScalarF32 *)&D_8028FB24)->value = D_801EEB74 * D_801EEB7C[D_801EEB78];
}

void func_80162D18(void) {
    extern const f32 D_801074D8, D_801074DC, D_801074E0, D_801074E4, D_801074E8, D_801074EC, D_801074F0, D_801074F4, D_801074F8;
    extern s32 D_801EEB70, D_801EEB74, D_8028F908, D_8028FB80, D_8028FAF8, D_8028FAC0, D_8028FB74;
    extern u8 D_8028F902;
    extern f32 D_8028F9C8, D_8028FB3C;
    extern u8 D_80290330[];
    extern u8 *D_8028FAD0;
    extern u8 D_8028F8E0[];

    /* Restore camera collision and motion defaults, then resume following the player. */
    *(f32 *)(((CameraFollowObject *)D_8028F8E0)->collision + CAMERA_COLLISION_RADIUS_OFFSET) = D_801074D8;
    *(f32 *)(((CameraFollowObject *)D_8028F8E0)->collision + CAMERA_COLLISION_TARGET_RADIUS) = D_801074D8;
    D_801EEB70 = -0x1E;
    D_801EEB74 = 0x64;
    D_8028F908 = 0x10;
    D_8028FB7C = 1;
    D_8028FB80 = 0;
    D_8028FAF8 = 0;
    *(u8 *)(((CameraFollowObject *)D_8028F8E0)->collision + COLLISION_SPHERE_COUNT) = 1;
    ((CameraFollowObject *)D_8028F8E0)->response = D_801074DC;
    *(f32 *)(((CameraFollowObject *)D_8028F8E0)->physics + CAMERA_PHYSICS_UNK20) = D_801074E0;
    *(f32 *)(((CameraFollowObject *)D_8028F8E0)->physics + CAMERA_PHYSICS_UNK1C) = D_801074E4;
    *(f32 *)(((CameraFollowObject *)D_8028F8E0)->physics + ACTOR_PHYSICS_RESPONSE_OFFSET) = ((CameraFollowObject *)D_8028F8E0)->response;
    if (D_801E7531 == 0x28) {
        *(f32 *)(((CameraFollowObject *)D_8028F8E0)->physics + PLAYER_PHYSICS_HORIZONTAL_SPEED_LIMIT) = D_801074E8;
    } else {
        *(f32 *)(((CameraFollowObject *)D_8028F8E0)->physics + PLAYER_PHYSICS_HORIZONTAL_SPEED_LIMIT) = D_801074EC;
    }
    *(f32 *)(((CameraFollowObject *)D_8028F8E0)->physics + PHYSICS_MAX_ANGLE_STEP) = D_801074F0;
    *(u8 *)(((CameraFollowObject *)D_8028F8E0)->physics + PHYSICS_ANGLE_APPROACH_MODES) = 1;
    D_8028F902 = 1;
    D_8028F9C8 = D_801074F8;
    D_8028FAC0 = 0;
    D_8028FB74 = 0;
    D_8028FB3C = D_801074F4;
    D_8028FB6C = CAMERA_CONTROL_NORMAL;
    func_801364D0();
    D_8028FAD0 = D_80290330;
}

extern s32 D_8028FB08, D_8028FAD8;
void func_80162EAC(f32 eyeX, f32 eyeY, s32 eyeZBits, s32 targetPositionAddress, s32 targetVelocityAddress, s32 transitionParameter, s32 transitionFlags)
{
  f32 *cameraPosition;
  s32 newTargetAddress;
  float zeroMotion;
  extern u8 *D_8028FAC8;
  extern s32 D_8028FACC;
  extern s32 D_8028FAD4;
  extern s32 D_8028FAE4;
  extern s32 D_8028FAF4;
  extern s32 D_8028FAF8;
  extern s32 D_8028FB94;
  extern u8 *D_8028FAD0;
  extern f32 D_8028FAB4;
  extern f32 D_8028FAB8;
  extern f32 D_8028F93C;
  extern f32 D_8028F938;
  extern f32 D_8028F940;
  f32 *position;
  f32 previousTargetHeight;

  /* Switch camera position and tracked target, saving the previous state and clearing motion. */
  D_8028FAF4 = transitionParameter;
  D_8028FACC = (s32) D_8028FAC8;
  D_8028FAD4 = (s32) D_8028FAD0;
  cameraPosition = &D_8028F914;
  D_8028FAE4 = D_8028FAF8;
  do
  {
    position = cameraPosition;
  }
  while (0);
  *((Vec3Words *) (&D_8028FB08)) = *((Vec3Words *) position);
  previousTargetHeight = D_8028FAB4;
  position = cameraPosition;
  newTargetAddress = targetPositionAddress;
  do
  {
    zeroMotion = 0.0f;
    position[0] = eyeX;
    D_8028F918 = eyeY;
    *((s32 *) (&D_8028F91C)) = eyeZBits;
    D_8028F938 = (D_8028F93C = (D_8028F940 = zeroMotion));
    do
    {
      D_8028FAC8 = (u8 *) newTargetAddress;
      D_8028FAD0 = (u8 *) targetVelocityAddress;
    }
    while (0);
    if (newTargetAddress != 0U)
    {
      D_8028FAB8 = previousTargetHeight;
      *((Vec3Words *) (&D_8028FAD8)) = *((Vec3Words *) (&D_8028FA00));
    }
    else
    {
      D_8028FAB8 = previousTargetHeight;
      *((Vec3Words *) (&D_8028FAD8)) = *((Vec3Words *) (&D_8028FA00));
    }
  }
  while (0);
  *((Vec3Words *) (&D_8028FA00)) = *((Vec3Words *) newTargetAddress);
  if (D_801E7531 != CAMERA_TARGET_SWITCH_SPECIAL_LEVEL)
  {
    func_80173CE8((s16) (transitionParameter + CAMERA_TARGET_SWITCH_TIMER_PADDING));
    D_8028FB94 = transitionFlags;
  }
}

/* Per-frame camera update (camera state at D_8028F8E0): ends a timed target switch and restores
 * the saved targets, plays the rumble/sound cue, applies the camera shake counter (D_8028FB34),
 * picks the follow target (player D_802902D8 or D_8029F978), adjusts the pitch from the target's
 * height (D_801EEBC4, clamped) and recomputes the yaw (D_8028F95C) from the camera-to-target vector. */
void func_80162FF8(void)
{
/* work split: the definition continues below this guard (o2) */
#if 0
}
#endif
  u8 *new_var4;
  double new_var2;
  u8 *new_var;
  volatile f32 *new_var3;
  f32 new_var5;
  typedef struct 
  {
    u8 pad0[0x34];
    f32 posX;
    f32 posY;
    f32 posZ;
    u8 pad40[0x58 - 0x40];
    f32 f58;
    f32 f5C;
    f32 f60;
    u8 pad64[0x7C - 0x64];
    f32 f7C;
    u8 pad80[0xD0 - 0x80];
    u8 *pD0;
    u8 padD4[0xE8 - 0xD4];
    f32 fE8;
    u8 padEC[0x120 - 0xEC];
    f32 f120;
    f32 f124;
    f32 f128;
    u8 pad12C[0x1D8 - 0x12C];
    f32 f1D8;
    u8 pad1DC[4];
    f32 f1E0;
    u8 pad1E4[4];
    u8 *p1E8;
    s32 s1EC;
    u8 *p1F0;
    s32 s1F4;
    Words3 w1F8;
    s32 s204;
    Words3 w208;
    s32 s214;
    s32 s218;
    f32 f21C;
    f32 f220;
    f32 f224;
    Words3 w228;
    s32 s234;
    f32 f238;
    f32 f23C;
    f32 f240;
    f32 f244;
    f32 f248;
    s32 s24C;
    s32 s250;
    s16 h254;
    u8 pad256[2];
    f32 f258;
    u8 pad25C[0x28C - 0x25C];
    s32 s28C;
    s32 s290;
    s32 s294;
    s32 s298;
    u8 pad29C[0x2A8 - 0x29C];
    f32 f2A8;
    u8 pad2AC[4];
    s16 h2B0;
    u8 pad2B2[2];
    s32 s2B4;
  } Cam;
  extern const f32 D_801074D8;
  extern const f32 D_801074DC;
  extern const f32 D_801074E0;
  extern const f32 D_801074E4;
  extern const f32 D_801074E8;
  extern const f32 D_801074EC;
  extern const f32 D_801074F0;
  extern const f32 D_801074F4;
  extern const f32 D_801074F8;
  extern const f32 D_80107500;
  extern const f32 D_80107508;
  extern const f32 D_80107514;
  extern const f32 D_80107518;
  extern const f32 D_8010751C;
  extern const f32 D_80107520;
  extern const f32 D_80107524;
  extern const f32 D_80107528;
  extern const f32 D_80107534;
  extern const f32 D_80107538;
  extern const f32 D_8010753C;
  extern const f64 D_80107540;
  extern const f64 D_80107548;
  extern const f32 D_80107550;
  extern const f32 D_80107554;
  extern const f64 D_80107558;
  extern const f32 D_80107560;
  extern const f32 D_80107564;
  extern const f32 D_80107568;
  extern const f32 D_80107570;
  extern const f32 D_8010757C;
  extern const f32 D_80107580;
  extern const f32 D_80107584;
  extern const f64 D_80107588;
  extern const f32 D_80107590;
  extern const f32 D_80107594;
  extern const f32 D_80107598;
  extern const f32 D_801075A0;
  extern const f32 D_801075AC;
  extern const f64 D_801075B0;
  extern const f64 D_801075B8;
  extern const f64 D_801075C0;
  extern const f64 D_801075C8;
  extern const f64 D_801075D0;
  extern const f64 D_801075D8;
  extern const f64 D_801075E0;
  extern const f64 D_801075E8;
  extern const f64 D_801075F0;
  extern const f32 D_801075F8;
  extern const f32 D_80107600;
  extern const f32 D_80107608;
  extern const f32 D_80107614;
  extern const f64 D_80107618;
  extern const f64 D_80107620;
  extern const f32 D_80107628;
  extern const f32 D_8010762C;
  extern const f32 D_80107630;
  extern const f32 D_80107638;
  extern const f32 D_80107644;
  extern const f32 D_80107648;
  extern const f32 D_80107650;
  extern const f32 D_8010765C;
  extern const f32 D_80107660;
  extern const f32 D_80107668;
  extern const f32 D_80107674;
  extern s32 D_801EEB70;
  extern s32 D_801EEB74;
  extern s32 D_8028F908;
  extern s32 D_8028FB80;
  extern s32 D_8028FAF8;
  extern s32 D_8028FAC0;
  extern s32 D_8028FB74;
  extern s32 D_801EEB74;
  extern s16 D_801EEB78;
  extern f32 D_801EEB7C[];
  extern f32 D_801EEBB4;
  extern f32 D_801EEBB8;
  extern f32 D_801EEBBC;
  extern f32 D_801EEBC0;
  extern f32 D_801EEBC4;
  extern u8 D_801FAA94[];
  extern u8 D_801FAAD3[];
  extern u8 D_80202218;
  extern f32 D_8028F93C;
  extern f32 D_8028F950;
  extern f32 D_8028F9C8;
  extern f32 D_8028FB3C;
  extern f32 D_8028FAB8;
  extern s32 D_801EEB70;
  extern s32 D_801EEB74;
  extern s32 D_8028F908;
  extern s32 D_8028FB80;
  extern s32 D_8028FAF8;
  extern s32 D_8028FAC0;
  extern s32 D_8028FB74;
  extern u8 *D_8028FAC8;
  extern s32 D_8028FACC;
  extern u8 *D_8028FAD0;
  extern s32 D_8028FAD4;
  extern s32 D_8028FAD8;
  extern s32 D_8028FAE4;
  extern s32 D_8028FAE8;
  extern s32 D_801EEB70;
  extern s32 D_801EEB74;
  extern s32 D_8028F908;
  extern s32 D_8028FB80;
  extern s32 D_8028FAF8;
  extern s32 D_8028FAC0;
  extern s32 D_8028FB74;
  extern s32 D_8028FAFC;
  extern f32 D_8028FB00;
  extern f32 D_8028FB04;
  extern s32 D_8028FB08;
  extern s32 D_8028FB94;
  extern s32 D_8028FB14;
  extern s32 D_8028FB74;
  extern f32 D_8028FB18;
  extern f32 D_8028FB1C;
  extern f32 D_8028FB20;
  extern f32 D_8028F938;
  extern f32 D_8028F93C;
  extern f32 D_8028F940;
  extern f32 D_8028FB24;
  extern s32 D_8028FB2C;
  extern s32 D_8028FB30;
  extern s16 D_8028FB34;
  extern f32 D_8028FB38;
  extern s32 D_8028FB70;
  extern s32 D_8028FB94;
  extern s32 D_8028FB14;
  extern s32 D_8028FB74;
  extern s32 D_8028FB78;
  extern s16 D_8028FB90;
  extern s32 D_8028FB94;
  extern s32 D_8028FB14;
  extern s32 D_8028FB74;
  extern s32 D_802901A8;
  extern f32 D_80290330;
  extern f32 D_80290338;
  void func_80149568(f32 *);
  s32 func_80164428(void);
  s32 func_801793DC(s32, u8, u8, u8);
  f32 sp10[3];
  f32 sp20[3];
  f32 sp30[3];
  f32 sp40[3];
  f64 _dd;
  f32 *pc;
  f32 *px;
  s32 *pf;
  s32 mode;
  f32 _0;
  f32 _1;
  f32 _2;
  f32 _3;
  f32 _4;
  f32 _5;
  f32 _6;
  f32 _7;
  f32 _8;
  f32 _9;
  f32 _10;
  f32 _11;
  f32 _12;
  f32 _13;
  f32 _14;
  f32 _15;
  f32 _16;
  f32 _17;
  f32 _18;
  f32 _19;
  f32 _20;
  f32 _21;
  f32 _22;
  f32 _23;
  f32 _24;
  f32 _25;
  f32 _26;
  f32 _27;
  f32 _28;
  f32 _29;
  f32 _30;
  f32 _31;
  f32 _32;
  f32 _33;
  f32 _34;
  f32 _35;
  f32 _36;
  f32 _37;
  f32 _38;
  f32 _39;
  f32 _40;
  f32 _41;
  f32 _42;
  f32 _43;
  f32 _44;
  f32 _45;
  f32 _46;
  f32 _47;
  f32 _48;
  f32 _49;
  f64 _50;
  f64 _51;
  f64 _52;
  f64 _53;
  f64 _54;
  f64 _55;
  f64 _56;
  f64 _57;
  f64 _58;
  f64 _59;
  f64 _60;
  f64 _61;
  f64 _62;
  f64 _63;
  f64 _64;
  f64 _65;
  f64 _66;
  f64 _67;
  f64 _68;
  s16 _69;
  s32 *_70;
  s32 _71;
  s32 _72;
  void *_73 = 0;
  void *_74;
  _70 = &D_802902D8;
  if ((D_801E7531 < 0x2E) && ((mode = ((Cam *) D_8028F8E0)->s28C) == 1))
  {
    if (((Cam *) D_8028F8E0)->s214 != 0)
    {
      if ((--((Cam *) D_8028F8E0)->s214) == 0)
      {
        ((Cam *) D_8028F8E0)->s2B4 = 0;
        ((Cam *) D_8028F8E0)->p1E8 = (u8 *) ((Cam *) D_8028F8E0)->s1EC;
        ((Cam *) D_8028F8E0)->p1F0 = (u8 *) ((Cam *) D_8028F8E0)->s1F4;
        ((Cam *) D_8028F8E0)->s218 = ((Cam *) D_8028F8E0)->s204;
        *((Words3 *) (&((Cam *) D_8028F8E0)->posX)) = ((Cam *) D_8028F8E0)->w228;
        *((Words3 *) (&((Cam *) D_8028F8E0)->f120)) = ((Cam *) D_8028F8E0)->w1F8;
        ((Cam *) D_8028F8E0)->f124 = ((Cam *) D_8028F8E0)->f1D8;
        if (((Cam *) D_8028F8E0)->s218 == mode)
        {
          *((Words3 *) (&((Cam *) D_8028F8E0)->f21C)) = ((Cam *) D_8028F8E0)->w208;
        }
        if ((((Cam *) D_8028F8E0)->p1E8 == ((u8 *) (&D_8029F9AC))) && (D_8029F9A4 != (&D_802902D8)))
        {
          ((Cam *) D_8028F8E0)->p1E8 = ((u8 *) (&D_802902D8)) + 0x34;
          ((Cam *) D_8028F8E0)->p1F0 = ((u8 *) (&D_802902D8)) + 0x58;
        }
      }
    }
    if ((*((u8 *) (((u8 *) (&D_801FAAD3)) + (D_80202218 * 0x190)))) != 0)
    {
      if (D_801EEBAC == 0)
      {
        D_801EEB78 += 1;
        func_801793DC(0xDB, 0x64, 0x80, 0x64);
        if (D_801EEB78 >= 3)
        {
          D_801EEB78 = 0;
        }
      }
      else
      {
        func_801793DC(0x6F, 0x64, 0x80, 0x64);
      }
    }
    {
      s16 *cnt = &D_8028FB34;
      if ((*cnt) != 0)
      {
        f32 *cam = &D_8028F95C;
        f32 z = 0.0f;
        *cnt -= 1;
        sp20[0] = (sp20[1] = (sp20[2] = z));
        _30 = func_801494CC(D_8028FB38, *cam);
        if (D_8028F8E0)
        {
          _26 = _30;
          sp20[2] = _26;
        }
        else
        {
          _26 = _30;
          sp20[2] = _26;
        }
        if (!(_30 > z))
        {
          _30 = -_30;
        }
        if (0, _30 < (*((f64 *) (((u8 *) (&D_801074F8)) + 4))))
        {
          *cnt = 0;
        }
        sp20[2] = _26 * (*((f64 *) (((u8 *) (&D_80107500)) + 4)));
        func_801490AC(sp20, sp20, func_801496C8((*cam) - (*((f64 *) (((u8 *) (&D_80107508)) + 4)))));
        D_8028F938 += sp20[0];
        D_8028F93C += sp20[1];
        D_8028F940 += sp20[2];
      }
    }
    _69 = *((s16 *) (((u8 *) D_802903AC) + 4));
    if ((((_69 == 3) | (_69 == 5)) != 0) || (_69 == 0x14))
    {
      _70 = &D_8029F978;
    }
    new_var4 = (u8 *) _70;
    if (((D_8028FAF8 == 0) && (D_8028FAF4 == 0)) && (D_8028FB70 == 0))
    {
      if ((D_8028FB30 != 0) && (D_802901A8 == 0))
      {
        _74 = *((s32 *) (new_var4 + 216));
                  if (((*((s32 *) (((u8 *) _74) + 0))) != 0) && ((*((s32 *) (((u8 *) (*((s32 *) (((u8 *) _70) + 204)))) + 4))) != 0))
          {
            if ((*((s32 *) (((u8 *) _74) + 68))) >= 2)
            {
              f32 *cam2 = &D_8028F914; _73 = (void *) (*((s32 *) (((u8 *) (*((s32 *) (((u8 *) _70) + 204)))) + 4)));
            sp40[0] = (sp40[2] = 0.0f);
            sp40[1] = D_80107514;
            sp30[0] = (*((f32 *) (((u8 *) _70) + 52))) + 0.0f;
            sp30[1] = (*((f32 *) (((u8 *) _70) + 56))) + D_80107514;
            sp30[2] = (*((f32 *) (((u8 *) _70) + 60))) + 0.0f;
            _0 = func_80148E48(sp30, cam2);
                          sp30[0] = (*((f32 *) (((u8 *) _73) + 0))) + (*((f32 *) (((u8 *) _70) + 52)));
              sp30[1] = (*((f32 *) (((u8 *) _73) + 4))) + (*((f32 *) (((u8 *) _70) + 56)));
              sp30[2] = (*((f32 *) (((u8 *) _73) + 8))) + (*((f32 *) (((u8 *) _70) + 60)));
                                        _22 = (func_80148E48(sp30, cam2) - _0) * D_80107518;
              D_801EEBC4 = _22;
              if (_22 >= 0.0f)
              {
                if (D_8010751C < _22)
                {
                  _34 = D_8010751C;
                }
              else
              {
                _34 = _22;
              }
            }
            else
            {
              if (D_80107520 < _22)
              {
                _34 = _22;
              }
              else _34 = D_80107520;
            }
                          D_801EEBC4 = _34;
            }
          }
        else
          if ((*((s32 *) (((u8 *) (*((s32 *) (((u8 *) _70) + 216)))) + 68))) >= 2)
        {
          goto block_38;
        }
      }
      else
      {
        block_38:
        D_801EEBC4 = 0.0f;

      }
      _48 = D_80107534;
      _3 = (((D_801EEBC4 + D_80107524) * D_80107528) * D_801EEC40) / (*((f64 *) (((u8 *) (&D_80107528)) + 4)));
      pc = (f32 *) (&D_8028FAC0);
      *pc = _3;
      *pc = _3 + D_8028FB28;
      if (D_801E7531 == 0x28)
      {
        _48 = D_80107538;
      }
      {
        f32 *q = pc - 62;
        if ((D_8028FB24 + D_8010753C) < (*q))
        {
          _4 = (*q) - D_8028FB24;
          if (_4 < _48)
          {
            _35 = (*q) - _4;
          }
          else
          {
            do
            {
              _35 = (*q) - _48;
            }
            while (0);
          }
          *q = _35;
        }
        else
          if ((*q) < (D_8028FB24 - D_8010753C))
        {
          _5 = D_8028FB24 - (*q);
          if (_5 < _48)
          {
            _35 = (*q) + _5;
          }
          else
          {
            _35 = (*q) + _48;
          }
          *q = _35;
        }
      }
    }
    px = &D_8028F914;
    _9 = (*px) - D_8028FA00;
    _17 = D_8028F91C - D_8028FA08;
    sp10[0] = _9;
    sp10[2] = _17;
    sp10[1] = D_8028F918 - D_8028FA04;
    {
      f32 yaw_ = func_80147460(_9, _17);
      f32 old_ = D_8028F95C;
      _51 = yaw_ + D_80107540;
      D_8028FB88 = old_;
    }
    D_8028F95C = func_801496C8(_51);
    if (D_8028FAF8 == 1)
    {
      _21 = (*px) - (*((f32 *) (((u8 *) (&D_8028FAFC)) + 0)));
      _18 = D_8028F918 - D_8028FB00;
      _8 = D_8028F91C - D_8028FB04;
      _27 = _21 * D_80107548;
      _23 = _18 * D_80107548;
      _29 = 2.0f * _23;
      _10 = _29 * _29;
      _6 = _8 * D_80107548;
      *((f32 *) (&D_8028FAC0)) = 0.0f;
      sp10[0] = _21;
      sp10[1] = _18;
      sp10[2] = _8;
      sp10[0] = _27;
      sp10[1] = _23;
      sp10[2] = _6;
      sp10[1] = _29;
      if (D_80107550 < (((_27 * _27) + (_29 * _29)) + (_6 * _6)))
      {
        func_80149568(sp10);
        sp10[0] *= D_80107554;
        sp10[1] *= D_80107554;
        sp10[2] *= D_80107554;
      }
      *px -= sp10[0];
      D_8028F918 -= sp10[1];
      D_8028F91C -= sp10[2];
      goto block_139;
    }
    if (D_8028FAF4 == 0)
    {
      if (D_8028FB14 == 1)
      {
        new_var5 = D_8028FB18;
        _11 = (*((f32 *) (&D_8029030C))) - (*px);
        _19 = D_80290314 - D_8028F91C;
        D_8028FB20 = new_var5;
        sp20[0] = _11;
        sp20[2] = _19;
        sp20[1] = D_80290310 - D_8028F918;
        _7 = func_801494CC(func_801496C8(func_80147460(_11, _19)), D_8028FB18);
        _62 = _7;
        if (D_80107558 < _62)
        {
          _24 = _7 * D_80107560;
          sp20[0] = (sp20[1] = (sp20[2] = 0.0f));
          if (D_8028FB1C < _24)
          {
            _42 = D_8028FB1C * D_80107564;
          }
          else
          {
            _42 = _24 * D_80107568;
          }
          if (_41 || D_8028F8E0)
          {
            sp20[2] = _42;
            func_801490AC(sp20, sp20, func_801496C8(D_8028F95C + (*((f64 *) (((u8 *) (&D_80107568)) + 4)))));
            D_8028F938 += sp20[0];
            D_8028F93C += sp20[1];
            D_8028F940 += sp20[2];
          }
          else
          {
            sp20[2] = _42;
            func_801490AC(sp20, sp20, func_801496C8(D_8028F95C + (*((f64 *) (((u8 *) (&D_80107568)) + 4)))));
            D_8028F938 += sp20[0];
            D_8028F93C += sp20[1];
            D_8028F940 += sp20[2];
          }
        }
        else
          if (_62 < (*((f64 *) (((u8 *) (&D_80107570)) + 4))))
        {
          _24 = (-_7) * D_8010757C;
          sp20[0] = (sp20[1] = (sp20[2] = 0.0f));
          if (D_8028FB1C < _24)
          {
            _42 = D_8028FB1C * D_80107580;
          }
          else
          {
            _42 = _24 * D_80107584;
          }
          sp20[2] = _42;
          func_801490AC(sp20, sp20, func_801496C8(D_8028F95C - D_80107588));
          D_8028F938 += sp20[0];
          D_8028F93C += sp20[1];
          D_8028F940 += sp20[2];
        }
      }
      _12 = (sp10[0] * sp10[0]) + (sp10[2] * sp10[2]);
      _36 = sqrtf(_12);
      _41 = D_80107590;
      if ((D_801E7531 == 0x28) && (D_801E7542 == 0))
      {
        _41 = D_80107594;
      }
      new_var2 = (D_801EEC40 * D_80107598) / (*((f64 *) (((u8 *) (&D_80107598)) + 4)));
      *((f32 *) (((u8 *) D_8028F9B0) + 8)) = 2.0f * _41;
      _57 = D_8028F9C8 + new_var2;
      _52 = _36;
      if (_57 < _52)
      {
        _58 = (_52 - _57) / (*((f64 *) (((u8 *) (&D_801075A0)) + 4)));
        _37 = _41;
        if (_58 < _41)
        {
          if (D_8028F8E0)
          {
            _37 = _58;
          }
          else
          {
            _37 = _58;
          }
        }
        func_8016049C(D_8028F8E0, _37, *((f32 *) (((u8 *) D_8028F9B0) + 8)));
      }
      _53 = D_8028F9C8 - ((D_801EEC40 * D_801075AC) / D_801075B0);
      _63 = _36;
      if (_63 < _53)
      {
        _59 = (_53 - _63) / D_801075B8;
        _50 = _41;
        if (_59 < _50)
        {
          _64++;
          _64--;
          _64 = -_59;
        }
        else
        {
          _64 = -_50;
        }
        func_8016049C(D_8028F8E0, _64, *((f32 *) (((u8 *) D_8028F9B0) + 8)));
      }
      pf = &D_8028FB70;
      *pf = func_80164428();
      if (D_8028FB74 == 0)
      {
        _13 = (*((f32 *) (((u8 *) D_8028FAC8) + 0))) - D_8028F914;
        sp20[0] = _13;
        sp20[1] = (*((f32 *) (((u8 *) D_8028FAC8) + 4))) - D_8028F918;
        _20 = (*((f32 *) (((u8 *) D_8028FAC8) + 8))) - D_8028F91C;
        sp20[2] = _20;
        new_var3 = (volatile f32 *) (&D_801EEBC0);
        D_8028FB20 = func_801496C8(func_80147460(_13, _20));
        if (D_8028FB14 == 0)
        {
          if (((*pf) == 0) && (D_801EC7D2 == 0))
          {
            _14 = (D_80290330 * D_80290330) + (D_80290338 * D_80290338);
            _45 = sqrtf(_14);
            if ((D_801EEBB4 < _45) && ((*((s16 *) (((u8 *) D_802903AC) + 4))) != 0x1D))
            {
              _1 = func_801494CC(D_8028F95C, func_801496C8(D_80290354));
              if (D_801EEBBC < ((_1 > 0.0f) ? (_1) : (-_1)))
              {
                if (((_1 > 0.0f) ? (_1) : (-_1)) < (D_801075C0 - D_801EEBBC))
                {
                  if (((_1 > 0.0f) ? (_1) : (-_1)) < D_801075C8)
                  {
                    _68 = _1 / D_801075C8;
                    D_801EEBC0 = (_68 > 0.0) ? (_68) : (-_68);
                  }
                  if (D_801075D0 < ((_1 > 0.0f) ? (_1) : (-_1)))
                  {
                    D_801EEBC0 = (D_801075D8 - ((_1 > 0.0f) ? (_1) : (-_1))) / D_801075D0;
                  }
                  {
                    f32 abs_ = (D_801EEBC0 > 0.0f) ? (D_801EEBC0) : (-D_801EEBC0);
                    f32 scale_ = D_801EEB7C[D_801EEB78];
                    *new_var3 = abs_;
                    D_801EEBC0 = abs_ * scale_;
                  }
                  if (_1 > 0.0f)
                  {
                    sp20[0] = (sp20[1] = (sp20[2] = 0.0f));
                    _46 = sqrtf((D_80290330 * D_80290330) + (D_80290338 * D_80290338));
                    _40 = (D_801EEBB8 * _46) * D_801EEBC0;
                    sp20[2] = _40;
                    func_801490AC(sp20, sp20, func_801496C8(D_8028F95C + D_801075E0));
                    D_8028F938 += sp20[0];
                    D_8028F93C += sp20[1];
                    D_8028F940 += sp20[2];
                  }
                  else
                  {
                    sp20[0] = (sp20[1] = (sp20[2] = 0.0f));
                    _47 = sqrtf((D_80290330 * D_80290330) + (D_80290338 * D_80290338));
                    _40 = (D_801EEBB8 * _47) * D_801EEBC0;
                    sp20[2] = _40;
                    func_801490AC(sp20, sp20, func_801496C8(D_8028F95C - D_801075E8));
                    D_8028F938 += sp20[0];
                    D_8028F93C += sp20[1];
                    D_8028F940 += sp20[2];
                  }
                }
              }
            }
          }
          if ((((D_8028FB14 == 0) && (D_8028FB2C != 0)) && (D_8028FB70 == 0)) && ((*((f32 *) (((u8 *) (&D_801FAA94)) + (D_80202218 * 0x190)))) == 0.0f))
          {
            _1 = func_801494CC(D_8028F95C, func_801496C8(D_80290354));
            if (_1 > 0.0f)
            {
              _61 = _1;
              sp20[0] = (sp20[1] = (sp20[2] = 0.0f));
              if (D_801075F0 < _61)
              {
                sp20[2] = D_801075F8;
              }
              else
              {
                sp20[2] = _61 * (*((f64 *) (((u8 *) (&D_801075F8)) + 4)));
              }
              func_801490AC(sp20, sp20, func_801496C8(D_8028F95C + (*((f64 *) (((u8 *) (&D_80107600)) + 4)))));
              D_8028F938 += sp20[0];
              D_8028F93C += sp20[1];
              D_8028F940 += sp20[2];
            }
            else
            {
              sp20[0] = (sp20[1] = (sp20[2] = 0.0f));
              _60 = -_1;
              if ((*((f64 *) (((u8 *) (&D_80107608)) + 4))) < _60)
              {
                sp20[2] = D_80107614;
              }
              else
              {
                sp20[2] = _60 * D_80107618;
              }
              func_801490AC(sp20, sp20, func_801496C8(D_8028F95C - D_80107620));
              D_8028F938 += sp20[0];
              D_8028F93C += sp20[1];
              D_8028F940 += sp20[2];
            }
          }
        }
      }
      block_139:
      if (((D_8028FAF4 == 0) && (D_8028FB70 == 0)) && (D_8028FAF8 == 0))
      {
        _28 = sp10[1] - ((D_8028F9C8 / D_80107628) + (*((f32 *) (&D_8028FAC0))));
        sp10[1] = _28;
        {
          f32 *p_ = &D_8028F93C;
          *p_ -= _28 / D_8010762C;
        }
      }

    }
    {
      u8 *cb = (u8 *) (&D_8028FB90);
      if ((*((s16 *) cb)) != 0)
      {
        if ((*((f32 *) D_802903A4)) == D_80107630)
        {
          f32 *t;
          new_var = cb - 0x6C;
          _dd = (*((f32 *) new_var)) / (*((f64 *) (((u8 *) (&D_80107630)) + 4)));
          t = (f32 *) (cb - 0x6C);
          if (_dd < (*((f64 *) (((u8 *) (&D_80107638)) + 4))))
          {
            _31 = D_80107644;
          }
          else
          {
            _31 = _dd;
          }
          {
            f32 *z = &D_8028FB28;
            *t = _31;
            if ((*z) < D_80107648)
            {
              *z = D_80107648;
            }
            else
            {
              _dd = (*z) * (*((f64 *) (((u8 *) (&D_80107648)) + 4)));
              _32 = D_8010765C;
              if (_dd < (*((f64 *) (((u8 *) (&D_80107650)) + 4))))
              {
                _32 = _dd;
              }
              *z = _32;
            }
          }
          {
            f32 *w = &D_8028F93C;
            if ((*w) < 0.0f)
            {
              *w = 0.0f;
            }
          }
        }
        else
        {
          f32 *u = (f32 *) (cb - 0x68);
          do
          {
          }
          while (0);
          if ((*((f32 *) (cb - 0x68))) < D_80107660)
          {
            *((f32 *) (cb - 0x68)) = D_80107660;
          }
          else
          {
            _dd = (*u) * (*((f64 *) (((u8 *) (&D_80107660)) + 4)));
            _33 = D_80107674;
            if (_dd < (*((f64 *) (((u8 *) (&D_80107668)) + 4))))
            {
              _33 = _dd;
            }
            *u = _33;
          }
        }
        {
          s16 *n = &D_8028FB90;
          *n = (*n) + 1;
        }
      }
      else
      {
        D_8028FB28 = D_801EEB70;
        D_8028FB24 = D_801EEB74 * (*((f32 *) (((u8 *) (&D_801EEB7C)) + (D_801EEB78 * 4))));
      }
    }
    if (!D_8028FB34)
    {
      _72 = D_8028FB74;
      D_8028FB74 = 0;
      D_8028FB14 = 0;
      D_8028FAF8 = 0;
      D_8028FB30 = 1;
      D_8028FB78 = _72;
    }
    D_8028FB30 = 1;
  }
}

s32 func_80164428(void)
{
    extern f32 D_8028FB60, D_8028FB64, D_8028F938, D_8028F93C, D_8028F940, D_8028F9C8, D_80107678, D_80107690, D_8010769C, D_801076A0, D_801076A4;
    extern const f32 D_8010767C;
    extern f64 D_80107680, D_80107688, D_80107698;
    f64 *correctionAngleThreshold;
    Vec3F normal, normalSum;
    Vec3F *contactNormal;
    f32 *motionX;
    f32 halfRadius, weightingRadius, focusHeading, motionHeading, contactHeading, distanceReduction, playerDistance, correctionScale;
    f64 angleThreshold;
    f32 *contactDistance;
    f32 *smoothedOffset = &D_8028FB60;
    s32 stopped = 0;
    f32 *targetOffset, *motionZ;
    s32 nearWall = 0, contactCount = 0;

    /* Stop or deflect camera motion using weighted wall-contact normals. */
    normalSum.x = (normalSum.y = (normalSum.z = 0.0f));
    *smoothedOffset += (D_8028FB64 - *smoothedOffset) / D_80107678;
    halfRadius = (*(f32 *)(D_8028F9B8 + CAMERA_COLLISION_RADIUS_OFFSET)) / D_8010767C;
    weightingRadius = (*(f32 *)(D_8028F9B8 + CAMERA_COLLISION_RADIUS_OFFSET)) - halfRadius;
    contactDistance = smoothedOffset - CAMERA_COLLISION_MAX_CONTACTS;
    for (; contactCount < CAMERA_COLLISION_MAX_CONTACTS; contactCount++, contactDistance++) {
        contactNormal = ((Vec3F **)D_8028F9B8)[contactCount];
        if (contactNormal == 0)
            break;
        normal = *contactNormal;
        normal.x *= D_8010767C - contactDistance[0] / weightingRadius;
        normal.y *= D_8010767C - contactDistance[0] / weightingRadius;
        normal.z *= D_8010767C - contactDistance[0] / weightingRadius;
        contactHeading = normal.z;
        normalSum.x += normal.x;
        normalSum.y += normal.y;
        normalSum.z += normal.z;
        if ((halfRadius / D_8010767C) > contactDistance[0]) nearWall = 1;
        { f64 radiusPrecision = weightingRadius; weightingRadius = radiusPrecision; }
    }
    targetOffset = &D_8028FB64;
    *targetOffset = 0;
    correctionAngleThreshold = &(*(f64 *)((u8 *)&D_80107690 + 4));
    if (contactCount != 0) {
        motionZ = &D_8028F940;
        do {
            motionHeading = func_801496C8(func_80147460(*motionZ, D_8028F938));
        } while (0);
        { f64 headingPrecision = motionHeading; motionHeading = headingPrecision; }
        contactHeading = func_801496C8(func_80147460(normalSum.z, normalSum.x));
        { f64 headingPrecision = motionHeading; motionHeading = headingPrecision; }
        focusHeading = func_801496C8(func_80147460(D_8028F91C - D_8028FA08, D_8028F914 - D_8028FA00));
        if ((func_8014944C(motionHeading, contactHeading) > D_80107680) &&
            (func_8014944C(focusHeading, contactHeading) > D_80107688)) {
            if (nearWall) {
                normal.x = D_8028F914 - *(f32 *)&D_8029030C;
                normal.z = D_8028F91C - *(f32 *)((u8 *)&D_8029030C + 8);
                D_8028F938 = (D_8028F93C = (*motionZ = 0.0f));
                playerDistance = __builtin_sqrtf(normal.x * normal.x + normal.z * normal.z);
                distanceReduction = D_8028F9C8 - playerDistance;
                {
                    f32 *offsetDestination;
                    f32 clampedReduction = distanceReduction;
                    f32 maxReduction = D_80107690;
                    if (distanceReduction < maxReduction) { offsetDestination = targetOffset; } else {
                        offsetDestination = targetOffset;
                        clampedReduction = maxReduction;
                    }
                    *offsetDestination = clampedReduction;
                }
                {
                    f32 *nonnegativeOffset = &D_8028FB64;
                    if (*nonnegativeOffset < 0.0f) *nonnegativeOffset = 0.0f;
                }
                stopped = 1;
            }
        } else if (angleThreshold = *correctionAngleThreshold,
                   (func_8014944C(motionHeading, contactHeading) < angleThreshold) &&
                   (func_8014944C(focusHeading, contactHeading) > angleThreshold)) {
            normalSum.x *= D_8010769C / (f32)contactCount;
            normalSum.y *= D_8010769C / (f32)contactCount;
            normalSum.z *= D_8010769C / (f32)contactCount;
            ((Vec3F *)&D_8028F938)->x += normalSum.x;
            ((Vec3F *)&D_8028F938)->y += normalSum.y;
            D_8028FB64 = 0;
            ((Vec3F *)&D_8028F938)->z += normalSum.z;
        } else {
            correctionScale = D_801076A0 / (f32)contactCount;
            normalSum.x *= correctionScale;
            normalSum.y *= correctionScale;
            normalSum.z *= correctionScale;
            normalSum.x *= D_801076A4;
            normalSum.y *= D_801076A4;
            normalSum.z *= D_801076A4;
            D_8028FB64 = 0;
            motionX = &((Vec3F *)&D_8028F938)->x;
            ((Vec3F *)&D_8028F938)->x = *motionX + normalSum.x;
            ((Vec3F *)&D_8028F938)->y += normalSum.y;
            ((Vec3F *)&D_8028F938)->z += normalSum.z;
        }
    }
    return stopped;
}

extern Vec3F D_8028FAFC;
extern f32 D_80290310;
extern f32 D_8028FB24;
extern s32 D_801EEB70;
extern s32 D_8028FAF8;

/* Free-camera movement: turns C-left/C-right (D_801FAAB4/B5, per-controller
 * stride 400) and the look-at target's drift into a push on the camera
 * velocity D_8028F938/3C/40, slid along the walls it touches (D_8028F9B8,
 * up to 4 normals) and kept above the floor. D_8028F914/18/1C is the camera
 * position, D_8028F95C its yaw, D_801EEBC8 (two bytes) the C-button hold
 * timers that keep the buttons reading as pressed. */
void func_801648E0(void) {
    extern u8 D_80202218;
    extern s32 D_8028FB94, D_8028FB14, D_8028FB74;
    extern s16 D_8028FB90;
    extern f32 D_80290330, D_80290334, D_80290338, D_8029F9D4, D_8029F9D8;
    extern f32 D_8028FB20, D_8028F938, D_8028F93C, D_8028F940;
    struct CButtonHoldTimers { u8 left; u8 right; };
    extern u8 D_801EEBC8;
    extern u8 D_801FAAB4[], D_801FAAB5[], D_801FAAFA[], D_801FAAFB[];
    extern u8 *D_8028FAC8;
    extern f32 D_801076A8, D_801076AC, D_801076B8, D_801076BC, D_801076E8, D_801076F4, D_801076F8;
    extern const f64 D_801076B0, D_801076C0, D_801076C8, D_801076D0, D_801076D8, D_801076E0;
    Vec3F tmp;
    Vec3F wallNormal;
    Vec3F unused;
    Vec3F push;
    Vec3F followPush;
    Vec3F toTarget;
    f32 floorArg;
    f32 floorOut;
    Vec3F **normals;
    f32 f;
    s32 i;
    s32 wallCount = 0;
    u8 timer;

    if (D_8028FAF4 != 0 && (D_8028FB94 & 1)) {
        D_80290330 = D_80290334 = D_80290338 = 0.0f;
        D_8029F9D0 = D_8029F9D4 = D_8029F9D8 = 0.0f;
    }
    if (D_8028FB14 == 1 || D_8028FAF8 == 1 || D_801EC740 == 0 || D_8028FAF4 != 0) {
        return;
    }
    push.x = push.y = push.z = 0.0f;
    toTarget.x = toTarget.y = toTarget.z = 0.0f;
    if ((timer = D_801EEBC8) != 0) {
        D_801EEBC8 = timer - 1;
        D_801FAAFA[D_80202218 * 400] = 1;
    }
    if ((timer = ((struct CButtonHoldTimers *)(&D_801EEBC8))->right) != 0) {
        ((struct CButtonHoldTimers *)(&D_801EEBC8))->right = timer - 1;
        D_801FAAFB[D_80202218 * 400] = 1;
    }
    if (D_8028FB74 == 1) {
        /* Following a target (D_8028FAC8): remember its heading while
         * turning, then swing sideways by how far it has drifted from it. */
        if (D_801FAAB5[D_80202218 * 400] != 0 || D_801FAAB4[D_80202218 * 400] != 0) {
            toTarget.x = ((f32 *)D_8028FAC8)[0] - D_8028F914;
            toTarget.y = ((f32 *)D_8028FAC8)[1] - D_8028F918;
            toTarget.z = ((f32 *)D_8028FAC8)[2] - D_8028F91C;
            D_8028FB20 = func_801496C8(func_80147460(toTarget.x, toTarget.z));
        }
        if (D_8028FB14 == 0) {
            f32 drift;

            toTarget.x = ((f32 *)D_8028FAC8)[0] - D_8028F914;
            toTarget.y = ((f32 *)D_8028FAC8)[1] - D_8028F918;
            toTarget.z = ((f32 *)D_8028FAC8)[2] - D_8028F91C;
            drift = func_801494CC(func_801496C8(func_80147460(toTarget.x, toTarget.z)), D_8028FB20);
            toTarget.x = toTarget.y = toTarget.z = 0.0f; if (0.0f < drift) {
                toTarget.z = drift * D_801076A8 * D_801076AC;
                func_801490AC(&toTarget, &toTarget, func_801496C8(D_8028F95C + D_801076B0));
            } else {
                toTarget.z = -drift * D_801076B8 * D_801076BC;
                func_801490AC(&toTarget, &toTarget, func_801496C8(D_8028F95C - D_801076C0));
            }
            followPush = toTarget;
        }
    }
    if (D_8028FB90 == 0) {
        /* C-right / C-left: strafe around, sideways to the camera's yaw. */
        if (D_801FAAB5[D_80202218 * 400] != 0) {
            f32 *yaw = &D_8028F95C;
            f64 offset = D_801076C8;
            f64 speed = D_801076D0;

            tmp.x = func_801C6000(*yaw - offset) * speed * speed;
            tmp.y = 0.0f;
            tmp.z = func_801C4040(*yaw - offset) * speed * speed;
            push = tmp;
        } else if (D_801FAAB4[D_80202218 * 400] != 0) {
            f32 *yaw = &D_8028F95C;
            f64 offset = D_801076D8;
            f64 speed = D_801076E0;

            tmp.x = func_801C6000(*yaw + offset) * speed * speed;
            tmp.y = 0.0f;
            tmp.z = func_801C4040(*yaw + offset) * speed * speed;
            push = tmp;
        }
    }
    if (D_8028FB74 == 1) {
        push.x += followPush.x;
        push.y += followPush.y;
        push.z += followPush.z;
    }
    normals = (Vec3F **)D_8028F9B8;
    wallNormal.x = wallNormal.y = wallNormal.z = 0.0f;
    for (i = 0; i < 4; i++, normals++) {
        if (*normals == 0) {
            break;
        }
        wallNormal.x += (*normals)->x;
        wallNormal.y += (*normals)->y;
        wallNormal.z += (*normals)->z;
        wallCount++;
    }
    if (wallCount != 0) {
        /* Angle between the push and the averaged wall normal. */
        func_80149568(&wallNormal.x);
        func_801492D4(&wallNormal.x);
        tmp = push;
        func_80149568(&tmp.x);
        f = func_801496C8(func_80147114(tmp.x * wallNormal.x + tmp.y * wallNormal.y + tmp.z * wallNormal.z));
        if (D_801076E8 < f) {
            /* Slide: remove the part into the wall, keep the speed. */
            f = sqrtf(push.x * push.x + push.y * push.y + push.z * push.z);
            wallNormal.x = wallNormal.x * (f * *(f64 *)((u8 *)&D_801076E8 + 4));
            wallNormal.y = wallNormal.y * (f * *(f64 *)((u8 *)&D_801076E8 + 4));
            wallNormal.z = wallNormal.z * (f * *(f64 *)((u8 *)&D_801076E8 + 4));
            push.x -= wallNormal.x;
            push.y -= wallNormal.y;
            push.z -= wallNormal.z;
            func_80149568(&push.x);
            push.x *= f;
            push.y *= f;
            push.z *= f;
        } else {
            /* Pushing straight into a wall: stop, and hold the button
             * that was turning for 20 frames. */
            D_8028F938 = D_8028F93C = D_8028F940 = 0.0f; if (0.0f < f) {
                if (D_801FAAB4[D_80202218 * 400] != 0) {
                    D_801EEBC8 = 20;
                    D_801FAAFA[D_80202218 * 400] = 1;
                }
                if (D_801FAAB5[D_80202218 * 400] != 0) {
                    ((struct CButtonHoldTimers *)(&D_801EEBC8))->right = 20;
                    D_801FAAFB[D_80202218 * 400] = 1;
                }
                return;
            }
        }
    }
    {
        f32 *velocity = &D_8028F938;

        velocity[0] += push.x;
        D_8028F93C += push.y;
        D_8028F940 += push.z;
        if (wallCount != 0) {
            /* Keep the camera at least D_801076F4 above the floor. */
            f32 height = func_8015B524(velocity - 9, (s32)&floorArg, &floorOut, (s32)D_8028F9B8);

            if ((height < D_801076F4) & (0.0f <= height)) {
                D_8028F93C /= D_801076F8;
                D_8028F918 += D_801076F4 - height;
            }
        }
    }
}

/* Request a camera handoff (D_8028FAF8) to a position looking at the player from the
 * direction of the given point: the camera sits the follow distance D_8028FB24 beyond the
 * player on the XZ line from the point through the player, raised by the vertical offset
 * D_801EEB70. The result goes to D_8028FAFC. */
void func_80165140(f32 *lookFrom) {
    Vec3F cameraPos;
    Vec3F direction;

    D_8028FAF8 = 1;
    cameraPos.x = lookFrom[0];
    cameraPos.z = lookFrom[2];
    cameraPos.y = ((f32 *)&D_8029030C)[1];
    direction.x = ((f32 *)&D_8029030C)[0] - cameraPos.x;
    direction.y = ((f32 *)&D_8029030C)[1] - cameraPos.y;
    direction.z = D_80290314 - cameraPos.z;
    func_80149568(&direction.x);
    direction.x *= D_8028FB24;
    direction.z *= D_8028FB24;
    func_80149374(&cameraPos.x, (f32 *)&D_8029030C, &direction.x);
    cameraPos.y += (f32)D_801EEB70;
    D_8028FAFC = cameraPos;
}

/* Recompute the camera's yaw and pitch from its position and focus, saving the previous angles. */
void func_80165230(void) {
    Vec3F toCamera;
    f32 angle;

    toCamera.x = D_8028F914 - D_8028FA00;
    toCamera.z = D_8028F91C - D_8028FA08;
    toCamera.y = D_8028F918 - D_8028FA04;
    angle = func_80147460(toCamera.x, toCamera.z); /* atan2 */
    D_8028FB88 = D_8028F95C;
    D_8028F95C = func_801496C8(angle + D_801076FC); angle = func_80147460(sqrtf(toCamera.x * toCamera.x + toCamera.z * toCamera.z), toCamera.y);
    D_8028FB84 = D_8028F958;
    D_8028F958 = func_801496C8(angle - D_80107704);
}

/* Original compiler padding: the ASCII bytes "      0 " in front of the function. */
const u32 D_80165338_padding[] __attribute__((section(".text"))) = {
    0x20202020, 0x20203020
};

/* Returns whether the player may change from action state `fromState` to `toState`
 * (D_801EEC44 = the u8 [PLAYER_ACTION_COUNT][PLAYER_ACTION_COUNT] transition table). */
s32 func_80165340(s32 fromState, s32 toState) {
    extern s32 D_801EEC44;
    u8 *transitions = (u8 *)&D_801EEC44;
    return (transitions + fromState * PLAYER_ACTION_COUNT)[toState];
}

static inline void cpy3_8016536C(Vec3F *d, Vec3F *s) { *d = *s; }
/* Tests player state-transition condition `condition` (0..44): reads the
 * current player state (D_802903AC +4/+6), ground contact (D_802903B0 +0x188,
 * floor/wall normals), the controller of player D_80202218 (P(): stick
 * magnitude/angle and buttons in its 0x190-byte record) and the ball, and
 * returns nonzero when the transition may be taken. A few conditions also
 * latch values the next state uses (ledge target, wall hit, cue IDs). */
s32 func_8016536C(s32 condition, u8 *unused) {
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define P(t,sym) F(t, &sym, D_80202218 * 0x190)
#define PD(sym) (*(const f64 *)&sym[1])
extern const f32 D_801077EC;
extern const f64 D_801077F0;
extern const f64 D_801077F8;
extern const f32 D_80107800[];
extern const f32 D_80107808[];
extern const f32 D_80107810[];
extern const f32 D_8010781C;
extern const f32 D_80107820;
extern const f32 D_80107824;
extern const f64 D_80107828;
extern const f32 D_80107830;
extern const f32 D_80107834;
extern const f64 D_80107838;
extern const f64 D_80107840;
extern const f64 D_80107848;
extern const f64 D_80107850;
extern const f64 D_80107858;
extern const f64 D_80107860;
extern const f64 D_80107868;
extern const f64 D_80107870;
extern const f64 D_80107878;
extern const f32 D_80107880[];
extern const f32 D_8010788C;
extern const f64 D_80107890;
extern const f32 D_80107898[];
extern const f32 D_801078A4;
extern const f64 D_801078A8;
extern const f64 D_801078B0;
extern const f32 D_801078B8;
extern const f32 D_801078BC;
extern const f64 D_801078C0;
extern const f64 D_801078C8;
extern const f64 D_801078D0;
extern const f64 D_801078D8;
extern const f64 D_801078E0;
extern const f64 D_801078E8;
extern const f64 D_801078F0;
extern const f64 D_801078F8;
extern const f64 D_80107900;
extern const f32 D_80107908;
extern s16 D_801E7464;
extern s8 D_801ED684;
extern s32 D_801ED74C;
extern s32 D_801ED758;
extern s32 D_801ED8D4;
extern f32 D_801EEB68;
extern f32 D_801EF430;
extern f32 D_801EF434;
extern u8 D_801FAA94[];
extern s32 D_801FAA98;
extern s32 D_801FAAA4;
extern u8 D_801FAAAA[];
extern u8 D_801FAAAB[];
extern u8 D_801FAAAC[];
extern u8 D_801FAAAF[];
extern u8 D_801FAAC8[];
extern s32 D_801FAB00;
extern s32 D_801FAB04;
extern s32 D_801FAB08;
extern s32 D_801FAB70;
extern u8 D_801FAB74[];
extern s32 D_801FAB78;
extern u8 D_80202218;
extern s32 D_8028FBD0;
extern s16 D_8028FBDC;
extern s32 D_8028FBE0;
extern s8 D_8028FBED;
extern u8 D_8028FBFA;
extern s16 D_8028FC00;
extern s32 D_8028FC3C;
extern s32 D_8028FCEC;
extern s32 D_8028FD20;
extern f32 D_8028FD24;
extern f32 D_8028FD28;
extern s32 D_8028FD2C;
extern f32 *D_8028FDC4;
extern f32 D_8029007C;
extern f32 D_80290080;
extern s16 D_8029008C;
extern u8 *volatile D_80290090;
extern u8 *D_80290094;
extern u8 *D_802900A8;
extern void *D_802900AC;
extern s16 D_8029010A;
extern s32 D_8029013C;
extern s32 D_802901BC;
extern s32 D_802901C0;
extern s32 D_802901A0, D_802901A4, D_802901AC, D_802901B0, D_802901D0, D_802901D4;
extern s32 D_802901E4;
extern s32 D_802901E8;
extern s32 D_80290210;
extern s32 D_80290270;
extern u8 *D_80290304;
extern f32 D_80290318;
extern f32 D_8029031C;
extern f32 D_80290320;
extern f32 D_80290330;
extern f32 D_80290334;
extern f32 D_80290338;
extern f32 D_8029034C;
extern f32 D_8029035C;
extern f32 D_80290360;
extern u8 *D_802903A8;
extern s32 D_802AA708;
void func_80149568(f32 *);
void func_80149604(f32 *arg0);
void func_80157708(void *);
s32 func_80173D28(u8 *arg0, f32 *arg1);
s32 func_80174B58(void);
s32 func_8017723C(void);
s32 func_801B1580(void);
    Vec3F delta;
    Vec3F savedPos;
    Vec3F offset;
    Vec3F step;
    void *hit[2];
    s32 i;
    f32 yaw;

    hit[0] = NULL;
    delta.x = *(f32 *)&D_8029030C - D_80290318;
    delta.y = D_80290310 - D_8029031C;
    delta.z = D_80290314 - D_80290320;
    switch (condition) {
    case 0: {
        s32 state;
        s32 s;

        state = F(s16, D_802903AC, 4);
        if (state == 0x29 && D_80290304 != NULL) {
            return 0;
        }
        if (state == 0x13 && func_801B1580() != 0) {
            return 0;
        }
        if (F(s16, D_802903AC, 4) == 0x20) {
            return 1;
        }
        if (P(f32, D_801FAA94) == 0.0f) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (F(u8, D_802903AC, 9) != 0 && !(D_80290300 & 0x200000) &&
                (F(u8, D_802903B0, 0x188) != 0 || (D_80290300 & 0x1000))) {
                if (sqrtf(delta.x * delta.x + delta.z * delta.z) < D_801077EC) {
                    return 1;
                }
            }
            s = F(s16, D_802903AC, 4);
            if (s == 0x1D || s == 0x13) {
                return 1;
            }
            if (s == 0x23 && (F(u8, D_802903B0, 0x188) != 0 || (D_80290300 & 0x1000))) {
                if (sqrtf(delta.x * delta.x + delta.z * delta.z) < D_801077F0) {
                    return 1;
                }
                if (D_802AA708 != 0) {
                    return 1;
                }
            }
            if (!(sqrtf(delta.x * delta.x + delta.z * delta.z) < D_801077F8) && D_802AA708 == 0) {
                return 0;
            }
            if (F(u8, D_802903B0, 0x188) == 0 && !(D_80290300 & 0x1000)) {
                return 0;
            }
            if (F(s16, D_802903AC, 4) != 9) {
                return 1;
            }
            if ((F(s16, D_802903AC, 6) != 0x14) && (F(s16, D_802903AC, 6) != 0x24)) {
                return 1;
            }
        }
        break;
    }
    case 1:
        if (P(f32, D_801FAA94) > D_80107800[0]) {
            s32 state;
            u8 *wall;
            f64 maxDot;
            f32 dz;
            f32 dx;
            f64 maxY;

            if (D_801EC740 != 1) {
                return 0;
            }
            if (!(D_80290300 & 0x1000) && F(u8, D_802903B0, 0x188) == 0) {
                return 0;
            }
            state = F(s16, D_802903AC, 4);
            if (state == 0x29 && D_80290304 != NULL) {
                return 0;
            }
            if (state == 0x23 && F(u8, D_802903B0, 0x188) != 0 && D_8029034C < PD(D_80107800)) {
                return 1;
            }
            if (F(s16, D_802903AC, 4) != 0x1D) {
                return 1;
            }
            delta = *(Vec3F *)&D_80290080;
            func_80149568(&delta.x);
            do {
                i = 0;
            } while (0);
            maxY = PD(D_80107808);
            do {
                dx = delta.x;
                dz = delta.z;
            } while (0);
            do {
                maxDot = PD(D_80107810);
            } while (0);
            for (; i < 4; i++) {
                wall = ((u8 **)D_802903B0)[i];
                if (wall != NULL && F(f32, wall, 4) < maxY &&
                    dx * F(f32, wall, 0) + dz * F(f32, wall, 8) < maxDot) {
                    return 0;
                }
            }
            return 1;
        }
        break;
    case 2:
        if (F(s16, D_802903AC, 4) == 0x12 && func_801B1580() != 0) {
            return 1;
        }
        if (P(u8, D_801FAAAA) != 0) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (F(u8, D_802903B0, 0x188) == 0 && F(s16, D_802903AC, 4) != 0x14) {
                return 0;
            }
            if (D_80290300 & 0x8000) {
                return 0;
            }
            if (F(s16, D_802903AC, 4) != 0x12) {
                return 1;
            }
        }
        break;
    case 3: {
        f32 dy;
        f32 lim;

        if (D_801EFCFC != 0) {
            return 0;
        }
        if (D_8029F468 != 0) {
            return 0;
        }
        if (F(s16, D_802903AC, 4) == 0x13 && ((s32 (*)(s32))func_8016536C)(0x14) != 0) {
            return 0;
        }
        if (D_80290300 & 0x8000) {
            return 0;
        }
        if (D_802901D4 != 0) {
            return 0;
        }
        if (F(s8, D_8029FA4C, 3) > 0) {
            return 0;
        }
        if (F(s8, D_802903AC, 3) > 0) {
            return 0;
        }
        if (D_802900DC != 0) {
            return 0;
        }
        if (F(s16, D_802903AC, 4) == 0xF) {
            return 1;
        }
        if (D_8029F9A4 != 0) {
            return 0;
        }
        dy = D_80290310 - D_8029F9B0; lim = D_80290308 + D_8029F9A8; if (dy > 0.0f) {
            if (!(dy <= lim)) {
                return 0;
            }
        } else if (!(-dy <= lim)) {
            return 0;
        }
        if (D_8029010A != 0) {
            return 1;
        }
        break;
    }
    case 11: {
        f32 dy;
        f32 lim;

        if (P(u8, D_801FAAAB) == 0) {
            return 0;
        }
        if (P(s32, D_801FAB04) < 5) {
            return 0;
        }
        if (D_801EC740 != 1) {
            return 0;
        }
        dy = D_80290310 - D_8029F9B0;
        lim = D_8029F9A8 * D_8010781C; if (dy > 0.0f) {
            return dy < lim;
        }
        if (-dy < lim) { return 1; } break;
    }
    case 12:
        if (P(u8, D_801FAAC8) == 0) {
            return 0;
        }
        if (D_801EC740 == 1) {
            return 1;
        }
        break;
    case 4:
        if (F(s16, D_802903AC, 6) == 0x1F) {
            return 0;
        }
        if (P(u8, D_801FAAAB) != 0) {
            return 0;
        }
        if (D_801EC740 == 1) {
            return 1;
        }
        break;
    case 7:
        if (D_80290300 & 0x8000) {
            return 0;
        }
        if (F(s16, D_802903AC, 4) == 0) {
            if (P(f32, D_801FAA94) < D_80107820) {
                u8 *floor;

                if (D_801EC740 != 1) {
                    return 0;
                }
                floor = ((u8 **)D_802903B0)[0];
                if (floor == NULL) {
                    return 0;
                }
                if (!(F(f32, floor, 4) <= D_80107824 - (D_80107824 - F(f32, D_802903A8, 0x14)) / F(f32, &D_801ED758, F(u8, floor, 0x74) * 0x1C))) {
                    return 0;
                }
                if (D_80107828 < sqrtf(D_80290330 * D_80290330 + D_80290338 * D_80290338)) { return 1; }
            }
        } else {
            if (P(f32, D_801FAA94) < D_80107830 && D_801EC740 == 1) {
                u8 *floor;

                if (D_8028FBED == 2 && D_8028FBEA >= 0xB) {
                    goto block_105;
                }
                floor = ((u8 **)D_802903B0)[0];
                if (floor != NULL && F(f32, &D_801ED74C, F(u8, floor, 0x74) * 0x1C) > D_80107834 &&
                    D_80107838 < sqrtf(D_80290330 * D_80290330 + D_80290338 * D_80290338)) {
                block_105:
                    if (F(u8, D_802903B0, 0x188) != 0) {
                        return 1;
                    }
                    break;
                }
            }
            if (F(u8, D_802903B0, 0x188) != 0) {
                if (D_801EC740 != 1) {
                    return 0;
                }
                if (F(s16, D_802903AC, 4) != D_801EC740) {
                    return 0;
                }
                if (D_8028FBEA < 3) {
                    return 0;
                }
                if (!(D_80107840 < func_8014944C(P(f32, D_801FAAA4), P(f32, D_801FAA98)))) {
                    return 0;
                }
                if (D_80107848 < sqrtf(D_80290330 * D_80290330 + D_80290338 * D_80290338)) { return 1; }
            }
        }
        break;
    case 21:
        if (P(f32, D_801FAA94) != 0.0f) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (D_8028FBEA >= 5) {
                return 1;
            }
        }
        break;
    case 8:
        if (F(u8, D_802903B0, 0x188) != 0 && P(u8, D_801FAAAC) != 0 && D_801EC740 == 1 &&
            !(D_80290300 & 0x8000) && P(s32, D_801FAB08) == 4) {
            if (F(s16, D_802903AC, 4) != 0x15) {
                return 1;
            }
        } else if (F(s16, D_802903AC, 4) != 0x15) {
            return 0;
        }
        if (P(f32, D_801FAA94) != 0.0f) {
            return 0;
        }
        if (D_801EC740 == 1) {
            return 1;
        }
        break;
    case 10:
        if (P(u8, D_801FAAAC) == 0 && D_801EC740 == 1 && D_8028FBF4 == 0) {
            return 1;
        }
        if (F(u8, D_802903B0, 0x188) != 0) {
            return 0;
        }
        if (F(s16, D_802903AC, 4) == 8) {
            return 1;
        }
        break;
    case 5:
        if (P(u8, D_801FAAAA) != 0) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (P(s32, D_801FAB00) >= 3) {
                return 1;
            }
        }
        break;
    case 6:
        if (P(u8, D_801FAAAA) != 0) {
            return 0;
        }
        if (D_801EC740 == 1) {
            return 1;
        }
        break;
    case 9:
        if (P(u8, D_801FAAC8) != 0) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if ((D_802901BC != 0 || D_802901C0 != 0) && D_802901AC == 0) {
                D_80290310 = D_8029F9B0;
            }
            func_80178134(0xA8, (f32 *)&D_8029030C, 0x64, 0x80);
            return 1;
        }
        break;
    case 13:
        if (D_8028FC00 >= 3) {
            return 1;
        }
        break;
    case 14:
        if (D_801EC740 == 2 && P(u8, D_801FAAAA) == 0 && P(s32, D_801FAB70) < 6) {
            goto block_154;
        }
        if (P(u8, D_801FAAAB) != 0) {
            return 0;
        }
        if (D_801EC740 == 0) {
            return 0;
        }
        if (P(s32, D_801FAB74) < 6) {
        block_154:
            D_8028FBE0 = 1;
            return 1;
        }
        break;
    case 15: {
        f64 base;

        if (F(s16, D_802903AC, 4) == 0xE && D_8028FBEA < 2) {
            return 0;
        }
        yaw = D_80290310 - D_8029F9B0;
        base = F(f32, D_8029FA50, 0x70) - D_80107850;
        if (yaw < base + D_80107858) {
                          if (F(f32, D_8029FA44, 0) < base + D_80107860 && D_8029F9D4 < 0.0f) {
                return 1;
            }
        }
        if (yaw < F(f32, D_8029FA50, 0x70) - D_80107868 + D_80107870 && F(u8, D_8029FA4C, 9) != 0 &&
            D_8029F9D4 < 0.0f) {
            return 1;
        }
                  if (!(F(f32, D_8029FA44, 0) < D_801EF434)) {
            return 0;
        }
        if (!(D_8029F9D4 > 0.0f)) {
            return 0;
        }
        if (D_8029F9D4 < D_801EF430) { return 1; }
        break;
    }
    case 16:
        if (P(u8, D_801FAAAA) != 0) {
            if (D_801EC740 != 1) {
                break;
            }
            if (D_80290310 - D_8029F9B0 < D_8029F9A8 * D_80107878) {
                return 1;
            }
        }
        break;
    case 17:
        if (F(u8, D_802903B0, 0x188) != 1 && !(D_80290300 & 0x1000)) {
            return 0;
        }
        if (D_8028FBEA < 2) {
            return 0;
        }
        if (D_80290090 == 0) {
            return 1;
        }
        break;
    case 18:
        if (P(u8, D_801FAAC8) != 0) {
            if (D_801EC740 != 1) {
                break;
            }
            if (D_80290334 > D_80107880[0]) {
                return 1;
            }
        }
        break;
    case 19:
        if (F(u8, D_802903B0, 0x188) == 1) {
            return 1;
        }
        if (D_80290300 & 0x1000) {
            return 1;
        }
        if (func_801B1580() != 0) {
            return 1;
        }
        break;
    case 20:
        if (func_801B1580() != 0) {
            return 1;
        }
        break;
    case 22:
        if (F(u8, D_802903B0, 0x188) == 0) {
            return 0;
        }
        if (P(u8, D_801FAAAC) != 0) {
            return 0;
        }
        if (D_801EC740 != 1) {
            return 0;
        }
        if ((u32)(P(s32, D_801FAB78) - 1) >= 5) {
            return 0;
        }
        if (!(D_80290300 & 0x8000)) {
            return 1;
        }
        break;
    case 24: {
        u8 *ground;
        u8 *ledge;
        f32 *angle;
        f32 height;

        if (F(u8, D_802903B0, 0x188) == 0) {
            return 0;
        }
        ground = F(u8 *, D_802903B0, 0x178);
        if (ground != NULL && (F(s32, ground, 0x14) & 0x200)) {
            return 0;
        }
        if (D_80290300 & 0x8000) {
            return 0;
        }
        if (!(D_8029034C > 0.0f)) {
            return 0;
        }
        if (!(D_8029034C < PD(D_80107880) && P(f32, D_801FAA94) < D_8010788C)) {
            if (F(s16, D_802903AC, 4) != 7) {
                return 0;
            }
        }
        if (D_801EC740 != 1) {
            return 0;
        }
        height = func_8015B524(&D_8028FC3C, (s32)&hit[0], &hit[1], 0);
        ledge = F(u8 *, D_802903A4, 4);
        if (ledge != NULL) {
            if (!(D_80107890 < F(f32, ledge, 4))) {
                return 0;
            }
            if (((D_80107898[0] < height - F(f32, D_802903A4, 0)) | (height < 0.0f)) == 0) {
                return 0;
            }
            if (func_80173D28((u8 *)&D_8028FC3C - 0x34, (f32 *)ledge) == 0) {
                return 0;
            }
            angle = &D_80290354;
            D_80290360 = *angle = func_801496C8(*angle + PD(D_80107898));
            D_80290094 = F(u8 *, D_802903B0, 0x178);
            D_802900AC = F(u8 *, D_802903A4, 4);
            return 1;
        }
        break;
    }
    case 25: {
        f32 height;
        f32 floorY;
        f32 *plane;
        Vec3F *probe;

        if (F(u8, D_802903B0, 0x188) != 0 && !(F(u8, D_802903B0, 0x18A) & 2)) {
            return 0;
        }
        if (D_80290300 & 0x8000) {
            return 0;
        }
        floorY = F(f32, D_802903A4, 0);
        if (!(D_801078A4 < floorY) && !(floorY < 0.0f)) {
            return 0;
        }
        height = func_8015B524(&D_8028FD20, (s32)&hit[0], &hit[1], 0);
        if (hit[0] != NULL && (hit[1] == NULL || !(F(s32, hit[1], 0x14) & 0x200)) &&
            D_801078A8 < F(f32, hit[0], 4) && ((height < D_801078B0) & (0.0f < height))) {
            yaw = D_80290354;
            D_8029007C = height;
            if (func_80173D28((u8 *)&D_8028FD20 - 0x34, hit[0]) != 0) {
                offset.x = 0.0f;
                offset.z = D_801078B8;
                offset.y = D_801EEB68;
                func_801490AC(&offset, &offset, yaw);
                ((f32 *)&D_8028FD20)[0] = *(f32 *)&D_8029030C + offset.x;
                ((f32 *)&D_8028FD20)[1] = D_80290310 + offset.y;
                ((f32 *)&D_8028FD20)[2] = D_80290314 + offset.z;
                savedPos = *(Vec3F *)&D_8028FD20;
                cpy3_8016536C((Vec3F *)&D_8028FD20 + 1, (Vec3F *)&D_8029030C);
                i = 0;
                func_8015C1D4((u8 *)&D_8028FD20 - 0x34);
                D_8028FBD0 = D_801ED8D4;
                for (; i < 8; i++) {
                    ((Vec3F *)&D_80290270)[i] = D_801ED68C[i];
                    ((Vec3F *)&D_80290210)[i] = D_801ED6EC[i];
                }
                func_80157708(&D_8028FCEC);
                D_801ED684 = 0;
                for (i = 0; i < 8; i++) {
                    D_801ED68C[i] = ((Vec3F *)&D_80290270)[i];
                    D_801ED6EC[i] = ((Vec3F *)&D_80290210)[i];
                }
                *(Vec3F *)&D_8028FD20 = savedPos;
                D_801ED8D4 = D_8028FBD0;
                for (i = 0, probe = (Vec3F *)&D_8028FD20; i < 4; i++) {
                    if (((void **)D_8028FDC4)[i] != NULL) {
                        if (i == 0) {
                            step = offset;
                            func_80149604(&step.x);
                            step.x *= F(f32, D_8028FDC4, 0x70);
                            step.z *= F(f32, D_8028FDC4, 0x70);
                        }
                        hit[0] = ((void **)D_8028FDC4)[i];
                        func_80149374(&offset.x, &probe->x, &step.x);
                        offset.y = D_8028FD24;
                        plane = hit[0];
                        if ((offset.x * plane[0] + offset.y * plane[1] + offset.z * plane[2] + plane[3]) *
                            (*(f32 *)&D_8029030C * plane[0] + D_80290310 * plane[1] + D_80290314 * plane[2] + plane[3]) < 0.0f) {
                            F(f32, &D_8029030C, 0x54) = yaw;
                            F(f32, &D_8029030C, 0x48) = yaw;
                            return 0;
                        }
                    }
                }
                D_802900A8 = hit[1];
                return 1;
            }
        } else {
            D_8029007C = D_801078BC;
            return 0;
        }
        break;
    }
    case 26:
        if (D_801FAAC6[D_80202218].f != 0 && D_801EC740 == 1) {
            return 1;
        }
        if (P(f32, D_801FAA94) != 0.0f) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (D_801078C8 < func_8014944C(D_80290354, func_801496C8(-P(f32, D_801FAA98) + D_801078C0 + D_8028F95C))) { return 1; }
        }
        break;
    case 23:
        if (D_801FAAC6[D_80202218].f != 0 && D_801EC740 == 1) {
            return 1;
        }
        if (P(f32, D_801FAA94) != 0.0f) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (F(s16, D_802903AC, 4) != 0x18) {
                return 0;
            }
            if (D_801078D0 < func_8014944C(D_80290354, func_801496C8(-P(f32, D_801FAA98) + D_8028F95C))) { return 1; }
        }
        break;
    case 27: {
        if (P(u8, D_801FAAC8) != 0) {
            return 1;
        }
        do {
            if (P(f32, D_801FAA94) == 0.0f) {
                return 0;
            }
            if (D_801EC740 != 1) {
                return 0;
            }
        } while (0);
        if (F(s16, D_802903AC, 4) == 0x18) {
            if (func_8014944C(D_80290354, func_801496C8(-P(f32, D_801FAA98) + D_8028F95C)) < D_801078D8) {
                return 1;
            }
        } else if (func_8014944C(D_80290354, func_801496C8(-P(f32, D_801FAA98) + D_801078E0 + D_8028F95C)) < D_801078E8) {
            return 1;
        }
        break;
    }
    case 29:
        if (P(f32, D_801FAA94) != 0.0f) {
            u8 *wall;

            if (D_801EC740 != 1) {
                return 0;
            }
            if (F(u8, D_802903B0, 0x188) == 0) {
                return 0;
            }
            if (D_80290300 & 0x8000) {
                return 0;
            }
            delta = *(Vec3F *)&D_80290080;
            func_80149568(&delta.x);
            for (i = 0; i < 4; i++) {
                wall = ((u8 **)D_802903B0)[i];
                if (wall != NULL && F(f32, wall, 4) < D_801078F0 &&
                    delta.x * F(f32, wall, 0) + delta.z * F(f32, wall, 8) < D_801078F8) {
                    if (F(s16, &D_80290080, 0xC)++ >= 3) {
                        wall = ((u8 **)D_802903B0)[i];
                        D_8029035C = func_80147460(F(f32, ((u8 **)D_802903B0)[i], 4),
                                                   sqrtf(F(f32, wall, 0) * F(f32, wall, 0) + F(f32, wall, 8) * F(f32, wall, 8)));
                        return 1;
                    }
                    break;
                }
            }
            if (i < 4) {
                return 0;
            }
            D_8029008C = 0;
            return 0;
        }
        break;
    case 30:
        if (P(u8, D_801FAAAA) != 0) {
            return 0;
        }
        if (D_801EC740 != 1) {
            return 0;
        }
        if (P(s32, D_801FAB70) < 4) {
            return 1;
        }
        break;
    case 31:
        if (func_80174B58() != 0) {
            return 1;
        }
        break;
    case 32:
        if (D_8028FBDC != 0) {
            return 0;
        }
        if (P(u8, D_801FAAAF) != 0) {
            s32 cue;

            if (D_801EC740 != 1) {
                return 0;
            }
            cue = D_802901E0;
            if (cue == 0xF && !(D_80297BEC & 1) && D_801E7464 == 0) {
                return 0;
            }
            D_802901E4 = cue;
            D_802901E8 = cue;
            return 1;
        }
        break;
    case 34:
        if (P(u8, D_801FAAC7) == 0) {
            if (P(u8, D_801FAAAB) == 0) {
                return 0;
            }
            if (F(s16, D_802903AC, 4) != 0x2A) {
                return 0;
            }
            if (D_8029013C != 0) {
                return 0;
            }
        }
        if (D_801EC740 != 1) {
            return 0;
        }
        if (D_80290300 & 0x8000) {
            return 0;
        }
        if (func_8017723C() != 0) {
            return 1;
        }
        break;
    case 37:
        if (F(u8, D_802903B0, 0x188) == 0) {
            u8 *floor = ((u8 **)D_802903B0)[0];

            if (floor == NULL) {
                return 0;
            }
            if (!(F(f32, floor, 4) > 0.0f)) {
                return 0;
            }
        }
        if (F(s16, D_802903AC, 4) != 0x27) {
            return 1;
        }
        if (D_8028FBFA >= 2) {
            return 1;
        }
        break;
    case 38:
        if (P(u8, D_801FAAAA) != 0) {
            if (D_801EC740 != 1) {
                return 0;
            }
            if (F(u8, D_802903B0, 0x188) == 0) {
                return 0;
            }
            if (func_8014944C(D_80290354, D_80290360) < D_80107900) {
                return 1;
            }
        }
        break;
    case 39:
        if (D_801EC740 != 1) {
            return 0;
        }
        if (P(u8, D_801FAAAB) == 0) {
            return 0;
        }
        if (F(u8, D_802903B0, 0x188) == 0) {
            return 0;
        }
        if (func_8014944C(D_80290354, D_80290360) < D_80107900) {
            return 1;
        }
        break;
    case 42:
        if (D_801EFCFC == 2) {
            s8 level = D_801E7531;

            if (((level == 0x2A) | (level == 8)) == 0 && !((u32)level < 7)) {
                return 0;
            }
        }
        if (P(u8, D_801FAAAB) == 0) {
            return 0;
        }
        if (func_8017723C() != 0) {
            return 0;
        }
        if (!(D_80290334 > D_80107908)) {
            return 0;
        }
        D_8029013C = 0;
        return 1;
    case 44:
        if (P(u8, D_801FAAAC) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/* player_set_state: puts the player (Glover, object D_802902D8) into action state `state`
 * (0..44: the index of the transition table D_801EEC44, tested by func_8016536C).
 * Does nothing while the action countdown D_8028FBD8 runs, unless D_801E7542 is clear.
 * Otherwise it records the previous state (state block D_802903AC: +4 current, +6 previous),
 * clears the state's frame counter D_8028FBEA and runs the state's entry code: animation
 * (func_80133998(object, clip, loop, queue, speed)), collision target radius (func_80175388
 * on collision block +0x74), a new action countdown, sounds (func_80178134), velocity changes
 * (D_80290330/334/338 = player velocity XYZ) and ball handling (ball object D_8029F978,
 * its carrier at +0x2C, physics D_8029FA48, state D_8029FA4C).
 * Player object fields used through their own symbols: D_8029030C position (+0x34),
 * D_80290348 response factor (+0x70), D_80290350/354 rotation and yaw (+0x78), D_80290360
 * target yaw (+0x88), D_802903A4/A8/AC/B0/B4 ground contact, physics, state, collision and
 * animation blocks. D_8028FCEC is a second object used to probe collisions for the player. */
void func_80167604(s32 state)
{
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define PREV_STATE F(s16, D_802903AC, PLAYER_STATE_PREVIOUS_OFFSET)
/* The f64 pooled right after an f32 constant. */
#define F64_AFTER(sym) (*(const f64 *)((const u8 *)&sym + 4))
  f32 targetYaw;
  f32 *ballVelocityOut;
  /* Reads a pointer global again through a struct view (a fresh load). */
  typedef struct
  {
    u8 *ptr;
  } PBox;
  typedef struct
  {
    u8 pad0[10];
    u8 unkA;
  } UnkFA4CView;
  extern const s32 D_8010790C;
  extern const f32 D_80107914;
  extern const f32 D_801079CC;
  extern const f32 D_801079D0;
  extern const f32 D_801079D4;
  extern const f32 D_801079D8;
  extern const f32 D_801079DC;
  extern const f64 D_801079E0;
  extern const f64 D_801079E8;
  extern const f64 D_801079F0;
  extern const f64 D_801079F8;
  extern const f64 D_80107A00;
  extern const f64 D_80107A08;
  extern const f64 D_80107A10;
  extern const f32 D_80107A18;
  extern const f32 D_80107A1C;
  extern const f32 D_80107A20;
  extern const f32 D_80107A24;
  extern const f32 D_80107A28;
  extern const f32 D_80107A34;
  extern const f64 D_80107A38;
  extern const f32 D_80107A40;
  extern const f32 D_80107A44;
  extern const f32 D_80107A48;
  extern const f32 D_80107A4C;
  extern const f32 D_80107A50;
  extern const f32 D_80107A54;
  extern const f32 D_80107A58;
  extern const f32 D_80107A64;
  extern const f64 D_80107A68;
  extern const f64 D_80107A70;
  extern const f64 D_80107A78;
  extern const f32 D_80107A80;
  extern const f32 D_80107A88;
  extern const f32 D_80107A90;
  extern const f32 D_80107A9C;
  extern const f64 D_80107AA0;
  extern const f32 D_80107AA8;
  extern const f32 D_80107AB4;
  extern const f32 D_80107AB8;
  extern const f32 D_80107ABC;
  extern const f32 D_80107AC0;
  extern const f32 D_80107AC4;
  extern const f64 D_80107AC8;
  extern const f64 D_80107AD0;
  extern const f32 D_80107AD8;
  extern const f32 D_80107ADC;
  extern const f32 D_80107AE0;
  extern const f32 D_80107AE4;
  extern const f32 D_80107AE8;
  extern const f32 D_80107AEC;
  extern const f32 D_80107AF0;
  extern const f32 D_80107B3C;
  extern const f32 D_80107B40;
  extern const f32 D_80107B44;
  extern const f64 D_80107B48;
  extern const f32 D_80107B50;
  extern const f32 D_80107B54;
  extern const f32 D_80107B58;
  extern const f32 D_80107B5C;
  extern const f32 D_80107B60;
  extern const f32 D_80107B64;
  extern const f32 D_80107B68;
  extern const f32 D_80107B6C;
  extern const f32 D_80107B70;
  extern const f32 D_80107B7C;
  extern const f32 D_80107B80;
  extern const f32 D_80107B84;
  extern const f32 D_80107B88;
  extern const f32 D_80107B8C;
  extern s16 D_801E7464;
  extern s8 D_801ED684;
  extern s32 D_801ED8D4;
  extern f32 D_801EEBF8;
  extern f32 D_801EEBFC;
  extern f32 D_801EEC04;
  extern u16 D_801EEC12;
  extern f32 D_801EF438;
  extern s32 D_801EFCF8;
  extern u8 D_801EFD74;
  extern u8 D_801EFD84;
  extern u8 D_801EFD94[];
  extern s16 D_801F19B0;
  extern s16 D_801F19B2;
  extern u8 D_801FAA94[];
  extern u8 D_801FAAAA[];
  extern u8 D_801FAAF1[];
  extern s32 D_801FAB78;
  extern u8 D_80202218;
  extern u8 *D_8028FAC8;
  extern u8 *D_8028FAD0;
  extern f32 D_8028F950;
  extern f32 D_8028F9C8;
  extern f32 D_8028FB3C;
  extern s16 D_8028FB40;
  extern s32 D_8028FBA0;
  extern u8 D_8028FBC0;
  extern s32 D_8028FBD0;
  extern s16 D_8028FBDA;
  extern s16 D_8028FBDC;
  extern s32 D_8028FBE0;
  extern s32 D_8028FBE4;
  extern s16 D_8028FBE8;
  extern s8 D_8028FBEC;
  extern s16 D_8028FBF6;
  extern u8 D_8028FBFA;
  extern s16 D_8028FBFC;
  extern s32 D_8028FC04;
  extern s32 D_8028FCEC;
  extern s32 D_8028FD14;
  extern f32 D_8028FD1C;
  extern s32 D_8028FD20;
  extern s32 D_8028FD2C;
  extern f32 D_8028FD68;
  extern f32 *D_8028FDC4;
  extern u8 *D_80290094;
  extern u8 *D_802900A8;
  extern s16 D_80290108;
  extern s32 D_80290134;
  extern s32 D_8029013C;
  extern s32 D_80290168;
  extern s32 D_802901A0;
  extern s32 D_802901A4;
  extern s32 D_802901AC;
  extern s32 D_802901B0;
  extern s32 D_802901D0;
  extern s32 D_802901D4;
  extern s32 D_802901E4;
  extern f32 D_802901F0;
  extern f32 D_802901F4;
  extern s32 D_802901FC;
  extern u8 D_80290200[];
  extern f32 D_80290204;
  extern s32 D_80290210;
  extern s32 D_80290270;
  extern u8 *D_80290304;
  extern f32 D_80290330;
  extern f32 D_80290334;
  extern f32 D_80290338;
  extern f32 D_80290340;
  extern f32 D_8029035C;
  extern f32 D_80290360;
  extern u8 D_80290374;
  extern u8 *D_802903A8;
  extern u8 *D_802903B4;
  extern f32 D_8029F398;
  extern f32 D_8029F39C;
  extern f32 D_8029F3A0;
  extern f32 D_8029F9D8;
  extern f32 D_8029F9D4;
  extern f32 D_8029F9DC;
  extern f32 D_8029F9E0;
  extern f32 D_8029F9E4;
  extern s32 D_8029F9F0;
  void func_80133B9C(u8 *arg0);
  void func_80173CE8(s32);
  s32 func_80176C3C(void);
  void func_80176C70(void);
  void func_80177390(s32 *arg0);
  void func_80177910(void);
  void func_80188FD8(u8 *arg0);
  void func_801890EC(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, f32 arg7, f32 arg8, f32 arg9);
  void func_801A87CC(s32);
  void func_801B10B8(u8 *, f32 *, f32, f32);
  extern void func_801B13CC(void);
  f32 func_801B1498(void);
  void func_801B182C(void);
  void func_801B33A0(u8 *, u8 **, s32 *);
  Vec3F *velocity;
  Vec3F vec;
  void *floorNormal;
  s32 index;
  f32 *player;
  f32 loudness;
  f32 dx;
  f32 dz;
  f32 savedRadius;
  f32 maxDeform;
  f32 defaultResponse;
  f32 deformAmount;
  f64 ballRadius;
  f64 playerGravity;
  f32 lightArg;
  s16 anim;
  s32 framesInState;
  s32 prevState;
  s32 volume;
  s16 lightTimer;
  s32 *ballVelocityIn;
  s32 *player2;
  s32 padOffset;
  s32 briefState8;
  s32 wallAhead;
  u8 count;
  u8 **player3;
  u8 *effect;
  void *platform;
  void *face;
  void *light;
  void *support;

  framesInState = *(s16 *)&D_8028FBEA;
  if (F(s16, D_802903AC, PLAYER_STATE_CURRENT_OFFSET) == 0x21) {
    func_8018D39C(6); /* cancel active effect 6 */
  }
  {
    /* D_8028FAC8 / D_8028FAD0: pointers to a tracked position and its velocity; back to the player's. */
    u8 **trackedPos = &D_8028FAC8;
    if ((*trackedPos) == (&D_8028FBC0)) {
      *trackedPos = &D_8029030C;
      D_8028FAD0 = ((u8 *)&D_8029030C) + 0x24;
    }
  }
  if ((D_8028FBD8 == 0) || (D_801E7542 == 0)) {
    if ((state == PLAYER_STATE_HURT) && (func_8015C4C8() != 0)) {
      func_801B13CC(); /* holding the ball: give it up */
    }
    {
      f32 friction = D_80107914;
      F(s16, D_802903AC, PLAYER_STATE_PREVIOUS_OFFSET) = F(s16, D_802903AC, PLAYER_STATE_CURRENT_OFFSET);
      F(s16, ((PBox *)&D_802903AC)->ptr, PLAYER_STATE_CURRENT_OFFSET) = state;
      F(f32, D_8029FA48, 12) = friction;
    }
    D_8028FBEA = 0;
    D_8028FBE4 = 0;
    D_8028FD14 &= ~0x10;
    func_8015C924(&D_802902D8);
    if (((u32)(state - 0x19)) >= 2) {
      D_802900A8 = 0;
    }
    switch (state) {
      case 0:
        /* Idle: loop clip 0x2A, after a transition clip where one applies. */
        anim = F(s16, D_802903B4, PLAYER_ANIM_CURRENT_OFFSET);
        if (anim == 0x3D) {
          F(f32, D_802903B4, 12) = D_801079CC;
          func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
        } else if (PREV_STATE == 0x1D) {
          func_80133998(&D_802902D8, 0x34, 0, 0, 0.0f);
          func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
        } else if (F(s16, D_802903B4, 16) != 0x2A) {
          if (anim == 7) {
            func_80133B9C(&D_802902D8);
            func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
          } else {
            func_80133998(&D_802902D8, 0x2A, 1, 0, 0.0f);
          }
        }
        func_80175388(D_802903B0 + 0x74, 13.0f);
        return;

      case 1:
        /* Loop clip 0x18; after a long wait (D_8028FBF8 > 400) clip 7 plays first. */
        if (D_8028FBF8 >= 0x191) {
          func_80133998(&D_802902D8, 7, 0, 0, D_801079D0);
          func_80133998(&D_802902D8, 0x18, 1, 1, 0.0f);
          D_8028FBEC = 0;
        } else {
          if (PREV_STATE == 0x1D) {
            func_80133998(&D_802902D8, 0x34, 0, 0, 0.0f);
            F(f32, D_802903B4, 12) = F(f32, D_802903B4, 12) + F(f32, D_802903B4, 12);
            func_80133998(&D_802902D8, 0x18, 1, 1, 0.0f);
          } else {
            func_80133998(&D_802902D8, 0x18, 1, 0, 0.0f);
          }
          D_8028FBEC = -1;
        }
        func_80175388(D_802903B0 + 0x74, 13.0f);
        return;

      case 7:
      {
        f32 *response = &D_80290348;
        *response = D_801079D4;
        func_80173CE8(8);
        D_8028FBD8 = 8;
        func_80133998(((u8 *)response) - 0x70, 0x3D, 0, 0, 0.0f);
        func_80175388(D_802903B0 + 0x74, 13.0f);
        D_80290360 = D_80290354;
        func_80178134(0x96, ((u8 *)response) - 0x3C, 0x32, 0x80);
      }
        return;

      case PLAYER_STATE_FALL:
        /* Airborne: a jump. Sets the upward velocity; jumping off the ball squashes it,
         * and repeated bounces (D_8028FBFA) or a moving platform add height. */
        F(f32, D_802903A8, 12) = D_801079D8;
        if (PREV_STATE == 0x14) {
          D_8028FBDC = 5;
          if (F(u8, D_8029FA4C, 9) != 0) {
            D_8029F9D4 = D_801079DC;
          }
          func_801B13CC();
        }
        D_8028FC04 = 0;
        func_80133B9C(&D_802902D8);
        func_80133998(&D_802902D8, 0x2C, 0, 0, 0.0f);
        maxDeform = F(f32, D_8029FA48, 48);
        if (((maxDeform != 0.0f) && (PREV_STATE == 0x12)) && (F(u8, D_802903B0, 392) == 0)) {
          func_801B10B8(&D_8029F978, D_801ED3E0, 10.0f, maxDeform);
          D_80290334 = (D_801EEC40 * D_801079E0) / D_801079E8;
          func_80178134(0x13, ((u8 *)&D_8029F978) + 0x34, 0x64, 0x80);
        } else {
          D_80290334 = (D_801EEC40 * D_801079F0) / D_801079F8;
        }
      {
        u8 **collision = &D_802903B0;
        func_80175388((*collision) + 0x74, 13.0f);
        func_80178134(func_80147000(2) + 0xF9, ((u8 *)collision) - 0xA4, 0x6E, 0x82);
      }
        D_8028FBD8 = 1;
        D_80290348 = D_8028FBCC;
        if ((D_8028FBE8 == 0x14) && (F(f32, D_8029FA48, 48) != 0.0f)) {
          count = D_8028FBFA;
          D_80290334 = D_80290334 + (((f32)count) * D_80107A00);
          D_80290338 = 0.0f;
          D_80290330 = 0.0f;
          if (count < 3) {
            D_8028FBFA += 1;
          }
          func_80178134(0x13, (f32 *)(((u8 *)&D_8029F978) + 52), (D_8028FBFA * 0x14) + 0x32, (D_8028FBFA * 0xA) + 0x64);
        }
        support = F(u8 *, D_802903B0, 376);
        if ((support != NULL) && (F(f32, support, 112) != 0.0f)) {
          s16 *counter = &D_8028FBFC;
          f32 *velocityY = &D_80290334;
          *velocityY = (*velocityY) + (2.0 * ((f32)(*counter)));
          if ((*counter) < 4) {
            *counter += 1;
            return;
          }
        }
        break;

      case 3:
        /* Ride the ball: take its velocity and become its carrier. */
        prevState = PREV_STATE;
        D_801EFCF8 = 1;
        if ((prevState != 0xC) & (prevState != 0xF)) {
          velocity = (Vec3F *)&D_8029F9D0;
          *velocity = *((Vec3F *)&D_8029F9DC);
          func_801B182C();
          if ((D_802901D0 != 0) && (D_8029F482 >= 0x32)) {
            velocity->x = velocity->x * D_80107A08;
            D_8029F9D4 = D_8029F9D4 * D_80107A08;
            D_8029F9D8 = D_8029F9D8 * D_80107A08;
          }
          *((Words3 *)(&(*(velocity = (Vec3F *)(&D_80290330))))) = *((Words3 *)&D_8029F9D0);
          if (F(s16, ((PBox *)&D_802903AC)->ptr, PLAYER_STATE_PREVIOUS_OFFSET) != 0x22) {
            func_80133998(((u8 *)&D_80290330) - 0x58, 0x36, 0, 0, 0.0f);
          }
          D_8028FBD8 = 4;
          F(s32, &D_8029F978, 44) = ((u8 *)&D_80290330) - 0x58;
          D_8028FBFB = 0;
          D_8029F47E = 0;
          F(u8, D_802903A4, 13) = 0;
          F(u8, D_802903A4, 14) = 0x14;
          D_8028FB40 = 1;
          D_8028FB3C = 0;
        }
        D_8028FBFB = 0;
        F(f32, D_802903B0, 116) = F(f32, D_8029FA50, 116) + D_80107A10;
        D_8029F482 = 0;
      {
        s32 *ballFlags = (s32 *)&D_8029F9A0;
        *ballFlags |= 1;
      }
        return;

      case 5:
        func_80133998(&D_802902D8, 0x48, 0, 0, D_80107A18);
        func_80133998(&D_802902D8, 0x49, 1, 1, 0.0f);
        func_80175388(D_802903B0 + 0x74, 8.0f);
        return;

      case 6:
        /* Clip 0x47; the ball takes the player's rotation. */
        func_80133998(&D_802902D8, 0x47, 0, 0, D_80107A1C);
        *((Words3 *)&D_8029F9F0) = *((Words3 *)&D_80290350);
        D_8028FBD8 = 3;
        D_8028FBDA = 1;
        D_8028FBDC = 0xA;
        func_80175388(D_802903B0 + 0x74, 13.0f);
        F(u8, D_802903A4, 13) = 0xFF;
        F(u8, D_802903A4, 14) = 0x1E;
        F(u8, D_8029FA4C, 10) = 0;
        return;

      case 9:
        /* Release the ball with a reaction. The probe object (D_8028FCEC, position at
         * D_8028FBD8 + 0x148, collision block pointer at + 0x1EC) is collided at the player's
         * position with an enlarged radius to look for a wall ahead: with one the ball is
         * pushed along the player's yaw, without one the player recoils. */
      {
        f32 *response = &D_80290348;
        *response = D_80107A20;
        func_80133998(((u8 *)response) - 0x70, 0x35, 0, 0, D_80107A24);
      }
      {
        s16 *countdown = &D_8028FBD8;
        *countdown = 5;
        F(Words3, &D_8028FBD8, 0x148) = *((Words3 *)&D_8029030C);
        F(Words3, &D_8028FBD8, 0x154) = F(Words3, &D_802902D8, 0x34);
        savedRadius = F(f32, *(f32 **)((u8 *)&D_8028FBD8 + 0x1EC), 112);
        {
          f64 widened = savedRadius;
          savedRadius = widened;
        }
        F(f32, *(f32 **)((u8 *)&D_8028FBD8 + 0x1EC), 112) = D_80107A28;
        F(f32, *(f32 **)((u8 *)&D_8028FBD8 + 0x1EC), 116) = D_80107A28;
        D_8028FD1C = D_80107A28;
        func_8015C1D4(((u8 *)countdown) + 0x114);
      }
        /* Collide the probe; D_801ED8D4 and the tables D_801ED68C / D_801ED6EC are saved around it. */
        F(s32, &D_8028FBD8, -8) = D_801ED8D4;
        for (index = 0; index < 8; index++) {
          ((Vec3F *)&D_80290270)[index] = D_801ED68C[index];
          ((Vec3F *)&D_80290210)[index] = D_801ED6EC[index];
        }

        func_80157708(&D_8028FCEC);
        D_801ED684 = 0;
        for (index = 0; index < 8; index++) {
          D_801ED68C[index] = ((Vec3F *)&D_80290270)[index];
          D_801ED6EC[index] = ((Vec3F *)&D_80290210)[index];
        }

        wallAhead = 0;
        *((Words3 *)&F(s32, &D_8028FBD8, 328)) = *((Words3 *)&D_8029030C);
        D_801ED8D4 = F(s32, &D_8028FBD8, -8);
        index = 0;
        F(f32, D_8028FDC4, 112) = savedRadius;
        F(f32, D_8028FDC4, 116) = savedRadius;
        D_8028FD1C = savedRadius;
        /* A steep contact face whose normal points along the player's facing direction. */
        for (; index < 4; index++) {
          if ((((u8 **)D_8028FDC4)[index] != NULL) && (F(f32, ((u8 **)D_8028FDC4)[index], 4) < F64_AFTER(D_80107A28))) {
            vec.x = 0.0f;
            vec.y = 0.0f;
            vec.z = D_80107A34;
            func_801490AC(&vec, &vec, D_80290354);
            face = ((u8 **)D_8028FDC4)[index];
            if (D_80107A38 < (((vec.x * F(f32, face, 0)) + (vec.y * F(f32, face, 4))) + (vec.z * F(f32, face, 8)))) {
              wallAhead = 1;
              break;
            }
          }
        }

        if (wallAhead != 0) {
          func_80160B6C(&D_802902D8, &D_8029F978, 4.0f, F(f32, D_8029FA48, 8));
        } else {
          func_80160610(&D_802902D8, -10.0f, F(f32, D_802903A8, 8));
          D_80290334 += D_80107A40;
        }
        func_801B13CC();
        D_8028FBDC = 0xA;
        return;

      case 8:
        if (PREV_STATE != 0x15) {
          func_80133998(&D_802902D8, 0x24, 0, 0, 0.0f);
          func_80175388(D_802903B0 + 0x74, 4.0f);
          F(f32, D_802903B0, 112) = F(f32, D_802903B0, 116);
          D_8028FBD8 = 0x40C;
          func_80173CE8(8);
          F(f32, D_802903A8, 12) = D_80107A44;
          return;
        }
        F(s32, D_802903B4, 8) = 0;
        return;

      case 21:
        func_80133998(&D_802902D8, 0x23, 1, 0, 0.0f);
        D_80290348 = D_801EF438;
        F(f32, D_802903A8, 24) = D_801EF438;
        return;

      case 10:
        /* Skipped when state 8 lasted under 4 frames, unless clip 0x23 is playing. */
        briefState8 = (PREV_STATE == 8) & (framesInState < 4);
        if ((!briefState8) || (F(s16, D_802903B4, PLAYER_ANIM_CURRENT_OFFSET) == 0x23)) {
          func_80133998(&D_802902D8, 0x25, 0, 0, 0.0f);
          func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
          D_8028FBD8 = 6;
          D_80290334 += D_80107A48;
          func_80175388(D_802903B0 + 0x70, 1.0f);
          func_80175388(D_802903B0 + 0x74, 13.0f);
        }
        defaultResponse = D_8028FBCC;
        F(f32, ((PBox *)&D_802903A8)->ptr, 12) = D_80107A4C;
        F(f32, D_802903A8, 24) = D_80107A50;
        D_80290348 = defaultResponse;
        return;

      case 12:
      {
        f32 *rotation = &D_80290350;
        f32 zero = 0.0f;
        D_8029035C = zero;
        *rotation = zero;
        func_80133998((u8 *)rotation - 0x78, 0x4B, 0, 0, zero);
      }
        D_8028FBD8 = 5;
        F(f32, D_802903B0, 116) = F(f32, D_8029FA50, 116) + D_80107A68;
        return;

      case 11:
        /* Dribble the ball (clip 0x44); from any state but riding, horizontal speed is scaled down. */
        if (PREV_STATE == 3) {
          func_80133998(&D_802902D8, 0x44, 0, 0, D_80107A54);
        } else {
          func_80133998(&D_802902D8, 0x44, 0, 1, D_80107A58);
          D_80290334 = 0.0f;
          D_80290330 = D_80290330 * F64_AFTER(D_80107A58);
          D_80290338 = D_80290338 * F64_AFTER(D_80107A58);
        }
        if (F(u8, D_802903B0, 392) == 0) {
          s32 *flags = (s32 *)&D_80290300;
          *flags &= ~1;
        }
        D_8028FBE0 = 0;
        D_8028FBD8 = 4;
        func_80175388(D_802903B0 + 0x74, 19.0f);
        return;

      case 4:
        D_8028FBD8 = 0xA;
        D_8028FBDA = 1;
        F(u8, D_802903A4, 13) = 0xFF;
        F(u8, D_802903A4, 14) = 0x1E;
        F(u8, D_8029FA4C, 10) = 0;
        return;

      case 13:
        func_80133998(&D_802902D8, 0x2C, 0, 0, 0.0f);
        func_80175388(D_802903B0 + 0x74, 13.0f);
        return;

      case 15:
        func_80133998(&D_802902D8, 0x1C, 0, 0, D_80107A64);
        D_8028FBD8 = 0x404;
        F(f32, D_802903B0, 116) = F(f32, D_8029FA50, 116) + D_80107A68;
        return;

      case 14:
        /* Take the ball (clip 0x37) and drop the player's own ground contacts; if the ball
         * rests on a floor, launch it upward at a speed scaled by its gravity. */
      {
        u8 *carrierField = (u8 *)((s32 *)(((u8 *)&D_8029F978) + 44));
        *((void **)carrierField) = &D_802902D8;
        D_8029F47E = 0;
        D_8028FBFB = 0;
        F(u8, D_802903A4, 13) = 0;
        F(u8, D_802903A4, 14) = 0x1E;
        func_80133998(&D_802902D8, 0x37, 0, 0, 0.0f);
        F(s32, D_802903B0, 388) = 0;
        F(s32, D_802903B0, 384) = 0;
        F(s32, D_802903B0, 380) = 0;
        F(s32, D_802903B0, 376) = NULL;
        F(u8, ((PBox *)&D_802903B0)->ptr, 392) = 0;
        F(f32, D_802903B0, 0) = 0;
        func_801B33A0(carrierField - 0x2C, &floorNormal, &index);
        if ((floorNormal != NULL) && (D_80107A70 < F(f32, floorNormal, 4))) {
          f32 *ballVelocityY = (f32 *)(carrierField + 48);
          f64 impulse, launchSpeed;
          const f32 ballGravity = F(f32, D_8029FA48, 0);
          impulse = (D_801EEC40 * D_80107A78) / F64_AFTER(D_80107A80);

          if ((!(D_80107A80 < ballGravity)) || (15.0 > ballGravity)) {
            if (D_80107A80 < ballGravity) {
              launchSpeed = impulse / ballGravity;
            } else {
              launchSpeed = impulse / F64_AFTER(D_80107A90);
            }
          } else {
            launchSpeed = impulse / 15.0;
          }
          *ballVelocityY = launchSpeed;
        }
      }
        F(f32, D_8029FA48, 12) = func_801B1498();
        func_80175388(D_802903B0 + 0x74, 12.0f);
        F(u8, D_8029FA4C, 10) = 0;
        return;

      case 16:
        /* Clip 0x47; the ball takes the player's rotation and position. */
        func_80133998(&D_802902D8, 0x47, 0, 0, D_80107A9C);
        *((Words3 *)&D_8029F9F0) = *((Words3 *)&D_80290350);
        *((Words3 *)&F(f32, &D_8029F978, 52)) = *((Words3 *)&D_8029030C);
        D_8028FBD8 = 9;
        D_8028FBDA = 1;
        D_8028FBE0 = 0;
        D_8028FBDC = 0xA;
        func_80175388(D_802903B0 + 0x74, 13.0f);
        F(u8, D_802903A4, 13) = 0xFF;
        F(u8, D_802903A4, 14) = 0x1E;
        return;

      case 17:
        /* Landing (clip 0x2D, then idle); becomes a jump when func_80176C3C asks for one. */
        if ((func_80176C3C() == 0) && ((func_80176C3C() == 0) || (!(D_80290340 < D_80107AA0)))) {
          D_8028FBFC = 0;
          F(s32, &D_801FAB78, (50 * D_80202218) * 8) = 0x64;
          if (PREV_STATE == 9) {
            func_80178134(0x9A, &D_8029030C, 0x5A, 0x80);
          }
          func_80133998(&D_802902D8, 0x2D, 0, 0, D_80107AA8);
          func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
          /* The current controller's record: stick idle slows the player down. */
          padOffset = D_80202218 * 0x190;
          if (F(u8, &D_801FAAAA, padOffset) == 0) {
            if (F(f32, &D_801FAA94, padOffset) == 0.0f) {
              D_80290330 = D_80290330 * F64_AFTER(D_80107AA8);
              D_80290338 = D_80290338 * F64_AFTER(D_80107AA8);
            }
            D_8028FBD8 = 3;
          }
          if (F(u8, D_802903B0, 392) != 0) {
            func_801A87CC(4);
            func_801A87CC(-4);
            return;
          }
        } else {
          func_80167604(PLAYER_STATE_FALL);
          return;
        }
        break;

      case 18:
        func_80178134(0xA8, &D_8029030C, 0x64, 0x80);
        func_80133998(((u8 *)&D_8029030C) - 0x34, 0x3E, 0, 0, D_80107AB4);
        D_8028FBD8 = 4;
        func_80175388(D_802903B0 + 0x74, 16.0f);
        return;

      case 19:
        /* Ground pound impact: a particle ring and an impact ring below the player. */
        if (F(u8, D_802903B0, 392) != 0) {
          func_801A87CC(0);
        }
        *((Words3 *)&vec) = *((Words3 *)&D_8029030C);
        D_8028FBD8 = 3;
        vec.y -= D_80107AB8;
        if (D_80290134 & 1) {
          D_80290334 = 0.0f;
          return;
        }
        if (F(u8, D_802903B0, 394) != 0) {
          func_80178134(0xA6, &D_8029030C, 0x64, 0x80);
          func_801B7344(&vec.x, 8, 4.0f);
          func_80176C70();
          if (func_80176C3C() != 0) {
            func_80167604(PLAYER_STATE_FALL);
            return;
          }
        }
        break;

      case 20:
        /* Land on the ball: squash it by the fall speed, become its carrier and give it
         * part of the player's velocity (scaled by the two gravities). */
        deformAmount = D_80290334 / D_80107ABC;
        if (!(deformAmount > 0.0f)) {
          deformAmount = -deformAmount;
        }
        if (F(f32, D_8029FA48, 48) != 0.0f) {
          loudness = 2.0f * (-D_80290340);
          volume = 0x64;
          if (!(loudness < D_80107AC0)) {
            volume = (s16)(loudness + D_80107AC0);
          }
          func_80178134(0x13, &D_8029F9AC, volume, 0x80);
          func_801B10B8(&D_8029F978, D_801ED3E0, deformAmount, F(f32, D_8029FA48, 48));
        }
        if (PREV_STATE != 0x13) {
          func_80133998(&D_802902D8, 0x2D, 0, 0, 0.0f);
          func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
        }
      {
        u8 *carrierField = (u8 *)((s32 *)(((u8 *)&D_8029F978) + 44));
        u8 *playerObj = (u8 *)&D_802902D8;
        *((u8 **)carrierField) = playerObj;
        D_8029F47E = 0;
        D_8028FBFB = 0;
        D_8028FBEC = -1;
        if (PREV_STATE != PLAYER_STATE_FALL) {
          D_8028FBD8 = 0xF;
        }
        F(u8, D_802903A4, 13) = 0;
        F(u8, D_802903A4, 14) = 0x1E;
        ballVelocityOut = (f32 *)(carrierField + 0x2C);
        ballVelocityIn = (s32 *)(carrierField + 0x2C);
        playerGravity = F(f32, D_802903A8, 0);
        ((void (*)(f32 *, f32 *, f32 *, f32))func_80148D80)(ballVelocityOut, (f32 *)ballVelocityIn, (f32 *)(playerObj + 0x58), (F(f32, D_8029FA48, 0) < D_80107AC4) ? (playerGravity / D_80107AC8) : (playerGravity / (F(f32, D_8029FA48, 0) * D_80107AD0)));
      }
        func_80175388(D_802903B0 + 0x74, 13.0f);
        F(f32, D_802903B0, 112) = F(f32, D_802903B0, 116);
        return;

      case 22:
        func_80133998(&D_802902D8, 0x1D, 0, 0, D_80107AD8);
        D_8028FBD8 = 0x405;
        func_80175388(D_802903B0 + 0x74, 17.0f);
        D_80290330 = (D_80290334 = (D_80290338 = 0.0f));
        return;

      case 24:
        /* Stop (zero velocity) and play clip 0x3C, then 0x12. */
      {
        u8 **collision = &D_802903B0;
        func_80175388((*collision) + 0x74, 2.0f);
        F(f32, D_802903B0, 112) = F(f32, D_802903B0, 116);
        player3 = (u8 **)(((u8 *)collision) - 0xD8);
      }
        *((Words3 *)&D_80290330) = *((Words3 *)&D_801ED3C4);
        D_8028FBD8 = 0x14;
        func_80133998(player3, 0x3C, 0, 0, 0.0f);
        func_80133998(player3, 0x12, 0, 1, 0.0f);
        F(u8, D_802903A4, 13) = 0;
        F(u8, D_802903A4, 14) = 0x1E;
        return;

      case 25:
        func_80178134(func_80147000(4) + 0x101, (u8 *)(((u8 *)&D_802902D8) + 0x34), 0x64, 0x80);
        func_80175388(D_802903B0 + 0x74, 2.0f);
        F(f32, D_802903B0, 112) = F(f32, D_802903B0, 116);
        {
          s32 *probeFlags = (s32 *)&D_8028FD14;
          *probeFlags |= 0x10;
        }
        func_80133998(&D_802902D8, 0x1F, 0, 0, 0.0f);
        func_80133998(&D_802902D8, 0x21, 1, 1, 0.0f);
        targetYaw = F(f32, &D_802902D8, 0x88);
        F(Words3, &D_802902D8, 0x58) = *((Words3 *)&D_801ED3C4);
        D_8028FBD8 = 0x14;
        D_8028FD68 = targetYaw;
        func_801493EC(&D_80290200, &D_80290200, 0.8f, ((u8 *)&D_802902D8) + 0x34, D_80107ADC);
        return;

      case 26:
        func_80178134(func_80147000(4) + 0x101, (f32 *)(((u8 *)&D_802902D8) + 0x34), 0x64, 0x80);
        func_80133998(&D_802902D8, 0x22, 0, 0, 0.0f);
        func_80133998(&D_802902D8, 0x2A, 1, 1, 0.0f);
        func_80175388(F(u8 *, &D_802902D8, 0xD8) + 0x74, 13.0f);
        *((Words3 *)&D_80290200) = *((Words3 *)&D_8028FD20);
        D_8028FBD8 = 0xA;
        F(f32, D_80290200, 4) += D_80107AE0;
        return;

      case 23:
        func_80178134(0x98, &D_8029030C, 0x78, 0x80);
        func_80133998(((u8 *)&D_8029030C) - 0x34, 0x13, 0, 0, 0.0f);
        F(u8, D_802903A4, 13) = 0xFF;
        F(u8, D_802903A4, 14) = 0x1E;
        func_80175388(D_802903B0 + 0x74, 13.0f);
        F(f32, D_802903B0, 112) = F(f32, D_802903B0, 116);
        D_8028FBD8 = 0x14;
        D_80290300 |= 1;
        func_80173CE8(0x14);
        return;

      case 27:
        /* Push off forward (after state 0x18) or backward. */
        F(u8, D_802903A4, 13) = 0xFF;
        F(u8, D_802903A4, 14) = 0x1E;
        D_802900A8 = 0;
        D_80290094 = NULL;
        if (PREV_STATE == 0x18) {
          func_8016049C(&D_802902D8, 4.0f, F(f32, D_802903A8, 8));
          func_80133998(&D_802902D8, 0x11, 0, 0, 0.0f);
        } else {
          func_8016049C(&D_802902D8, -4.0f, F(f32, D_802903A8, 8));
          func_80133998(&D_802902D8, 0x20, 0, 0, 0.0f);
        }
        return;

      case PLAYER_STATE_HURT:
        /* Hurt: drop the ball if carried, play clip 0x29. */
        if (F(s32, &D_8029F978, 44) == (&D_802902D8)) {
          func_801B13CC();
        }
        D_8028FBD8 = 0x7D3;
        func_80133998(&D_802902D8, 0x29, 0, 0, D_80107AE4);
        F(u8, D_802903A4, 13) = 0xFF;
        F(u8, D_802903A4, 14) = 0x1E;
        return;

      case 29:
        func_80178134(func_80147000(4) + 0x101, &D_8029030C, 0x64, 0x80);
        player2 = ((u8 *)&D_8029030C) - 0x34;
        func_80133998(player2, 0x2B, 0, 0, 0.0f);
        func_80133998(player2, 0x33, 1, 1, 0.0f);
        D_8028FBD8 = 0x40C;
        return;

      case 30:
        /* Clip 0x2E; the ball takes the player's velocity and the tracked position is the player's. */
      {
        u8 *position = (u8 *)&D_8029030C;
        *((Words3 *)&D_8029F9D0) = *((Words3 *)(position + 36));
        D_8028FBD8 = 0x416;
        D_8028FAC8 = position;
        D_8028FAD0 = position + 0x24;
        ((UnkFA4CView *)D_8029FA4C)->unkA = 0;
        func_80133998(position - 0x34, 0x2E, 0, 0, D_80107AE8);
      }
        return;

      case PLAYER_ACTION_CATCH_BALL:
        /* Catch the ball: become its carrier. */
        func_80133998(&D_802902D8, 0x44, 0, 0, D_80107AEC);
        D_8029035C = D_80107AF0;
        D_80290350 = D_80107AF0;
        func_80175388(D_802903B0 + 0x74, 19.0f);
        F(f32, D_802903B0, 112) = D_80290308;
        F(s32, &D_8029F978, 44) = &D_802902D8;
        D_8029F47E = 0;
        D_8028FBFB = 0;
        return;

      case 32: { u8 *obj; s32 clip, loop, queue; f32 speed;
        /* Act on cue D_802901E4 (latched by condition 32): play its clip, lock the player
         * until it ends (countdown 1000 + clip) and create two coloured lights. */
        switch (D_802901E4) {
          case -1:

          case 7:

          case 8:

          case 9:

          case 10:

          case 11:

          case 12:

          case 13:

          case 14:
            lightTimer = 1;
            func_80177910();
            obj = (u8 *)&D_802902D8; clip = 0x19; loop = 0; lightArg = D_80107B3C; queue = 0; speed = D_80107B40;
            goto animate;
            break;

          case 0:

          case 1:

          case 2:
            lightTimer = 0xA;
            func_80177910();
            func_80133998(&D_802902D8, 0x2F, 0, 0, 0.0f);
            lightArg = D_80107B44;
            break;

          case 15:
            if ((D_80297BEC & 1) || (D_801E7464 != 0)) {
              if (D_80299398 > D_8029018C) {
                D_8029013C = 1;
                func_80167604(0x2A);
                return;
              }
              func_80133998(&D_802902D8, 0xD, 0, 0, 0.0f);
              D_80290360 = D_8028F95C;
              F(s16, D_802903AC, PLAYER_STATE_CURRENT_OFFSET) = 0x29;
              D_8028FBD8 = 0x3F5;
              func_80173CE8(0x14);
              D_80290330 = D_80290330 * D_80107B48;
              D_80290334 = D_80290334 * D_80107B48;
              D_80290338 = D_80290338 * D_80107B48;
            }
            return;

          default:
            lightTimer = 0xF;
            func_80177910();
            obj = (u8 *)&D_802902D8; clip = 0x3B; loop = 0; lightArg = D_80107B50; speed = D_80107B54; queue = 0;
            animate: func_80133998(obj, clip, loop, queue, speed);
            break;

        }

        D_8028FBD8 = F(u16, D_802903B4, PLAYER_ANIM_CURRENT_OFFSET) + 0x3E8;
        light = func_8013FCDC(0x58, 1, &D_8010790C);
        func_801890EC(light, 0xFF, 0x32, 0x32, 0xFF, 0x50, 0x50, 0, 0, lightArg);
        F(s16, light, 10) = lightTimer;
        F(u8, light, 9) = 2;
        F(f32, light, 24) = D_80107B58;
        func_80188FD8(light);
        light = func_8013FCDC(0x58, 1, &D_8010790C);
        func_801890EC(light, 0x32, 0xFF, 0x32, 0x50, 0xFF, 0x50, 0, 0, lightArg);
        F(s16, light, 10) = lightTimer;
        F(u8, light, 9) = 2;
        F(f32, light, 28) = D_80107B5C;
        func_80188FD8(light);
        return; }

      case 33:
        func_80133998(&D_802902D8, 0x44, 0, 0, D_80107B60);
        F(s16, D_802903B0, 122) = F(s16, D_802903B0, 122) & 0xFFDF;
        F(f32, ((PBox *)&D_802903B0)->ptr, 92) = D_80107B64;
        D_8029035C = D_80107B6C;
        F(f32, &D_802902D8, 120) = D_80107B6C;
        D_80290310 -= D_80107B68;
        func_8015C350(((u8 *)&D_802902D8) + 0x9C, ((u8 *)&D_802902D8) + 0x78);
        func_801785E0(&D_80290168, 0x138, 0x28, ((u8 *)&D_802902D8) + 0x34, 0x14);
        return;

      case 34:
        /* Clip 8: become the ball's carrier, face the ball, and track a fixed copy of the
         * player's position (D_8028FBC0) with zero velocity. */
        func_80133998(&D_802902D8, 8, 0, 0, D_80107B70);
        func_80178134(0xA7, ((u8 *)&D_802902D8) + 0x34, 0x64, 0xA0);
        *((Words3 *)&D_8028FBC0) = F(Words3, &D_802902D8, 52);
        *((Words3 *)&D_80290200) = F(Words3, &D_802902D8, 52);
        F(s32, &D_8029F978, 44) = &D_802902D8;
        *((Words3 *)&D_802901F0) = *((Words3 *)&F(f32, &D_8029F978, 52));
        D_8028FAC8 = &D_8028FBC0;
        D_8029F47E = 0;
        ballRadius = D_8029F9A8;
        D_8028FBFB = 0;
        D_8028FAD0 = &D_801ED3C4;
        if (F64_AFTER(D_80107B70) < ballRadius) {
          D_802901F4 = D_802901F4 + (2.0 * (ballRadius - F64_AFTER(D_80107B70)));
        }
        dx = F(f32, &D_8029F978, 52) - F(f32, &D_802902D8, 52);
        dz = D_8029F9B4 - D_80290314;
        vec.x = dx;
        vec.y = D_8029F9B0 - D_80290310;
        vec.z = dz;
        D_80290360 = func_801496C8(func_80147460(dx, dz));
        F(u8, &D_801FAAF1, (D_80202218 * 10) * 40) = 1;
        D_80290094 = F(u8 *, D_802903B0, 376);
        return;

      case PLAYER_STATE_SLOPE_SLIDE:
      {
        u8 *flags;
        if (((D_8028FBF6 == 0) && (!((*((s32 *)(flags = (u8 *)(&D_80290300)))) & 0x2000))) && (D_80290108 == 0)) {
          func_80133998(flags - 0x28, 0x3D, 0, 0, 0.0f);
        }
      }
        D_8028FBD8 = 0xA;
        return;

      case PLAYER_STATE_ATTACHED_TYPE29:
        /* Attach to the actor at player +0x2C: take its yaw and track its position. */
        func_80133998(&D_802902D8, 0xF, 1, 0, D_80107B7C);
      {
        u8 *actor = D_80290304;
        D_802900C8 = (s32)actor;
        D_80290360 = F(f32, actor, 136);
        D_8028FAC8 = actor + 0x34;
        D_80290300 &= ~0x100;
      }
        return;

      case 37:
        /* Frog idle (clip 5): a carried ball is released first. */
      {
        u8 **ballCarrier = (u8 **)((s32 *)(((u8 *)&D_8029F978) + 44));
        if ((*ballCarrier) == ((u8 *)&D_802902D8)) {
          func_801B13CC();
          func_80160610(&D_802902D8, -10.0f, F(f32, D_802903A8, 8));
          D_8028FBFB = 0;
          *ballCarrier = 0;
          F(f32, D_802903B0, 112) = (F(f32, D_802903B0, 116) = F(f32, D_802903A8, 72));
        }
      }
        D_80290348 = D_80107B80;
        func_80133998(&D_802902D8, 5, 1, 1, 0.0f);
        return;

      case 39:
      {
        f32 *response = &D_80290348;
        *response = D_80107B84;
        func_80133998(((u8 *)&D_80290348) - 0x70, 0xF, 0, 0, D_80107B84);
      }
        D_8028FBFA = 0;
        return;

      case 38:
        /* Hop (clip 7): upward velocity D_801EEBFC, forward push D_801EEBF8, plus the
         * supporting platform's motion. */
      {
        f32 *response = &D_80290348;
        player = (f32 *)(((u8 *)response) - 0x70);
        *response = D_80107B88;
        F(s16, D_802903B4, PLAYER_ANIM_CURRENT_OFFSET) = 0;
        func_80133998(player, 7, 0, 0, 0.0f);
        D_80290334 = D_801EEBFC;
        func_80178134(0x68, (f32 *)(((u8 *)response) - 0x3C), 0x64, 0x76);
        func_8016049C((u8 *)player, D_801EEBF8, F(f32, D_802903A8, 12));
        D_8028FBD8 = 5;
        platform = F(u8 *, D_802903B0, 376);
        if (platform != NULL) {
          func_8014932C(((u8 *)response) - 0x18, ((u8 *)platform) + 0xD8);
        }
      }
        return;

      case 40:
        func_80133998(&D_802902D8, 9, 0, 0, 0.0f);
        return;

      case 42:
        /* Clips 0x30 / 0x31, detached from any actor, with one of four thought bubbles. */
        if (D_802900C8 != 0) {
          func_801964B0();
        }
        func_80133998(&D_802902D8, 0x30, 0, 0, 0.0f);
        func_80133998(&D_802902D8, 0x31, 1, 1, 0.0f);
      {
        typedef struct
        {
          s32 w[4];
        } W4;
        *((W4 *)&D_8028FBA0) = *((W4 *)&D_80290374);
      }
        if (D_8029013C == 0) {
          if (D_8029F468 != 0) {
            func_80177390(&D_801EFD74);
            return;
          }
          func_80177390(&D_801EFD84);
          return;
        }
        if (D_80297BEC & 0x2000) {
          func_80177390(D_801EFD94);
          return;
        }
        func_80177390(D_801EFD64);
        return;

      case 43:
        /* One of two clip pairs, picked at random unless D_801E7460 or D_8029F5C8 forces the first. */
        if (((D_801E7460 != 0) || (func_80147000(0x32) < 0x14)) || (D_8029F5C8 != 0)) {
          u8 **collision = &D_802903B0;
          func_80175388((*collision) + 0x74, 19.0f);
          if (D_8029F5C8 != 0) {
            f32 speed = D_80107B8C;
            func_80133998(((u8 *)collision) - 0xD8, 0x38, 0, 0, speed);
            func_80133998(((u8 *)collision) - 0xD8, 0x40, 1, 1, speed);
          } else {
            func_80133998(((u8 *)collision) - 0xD8, 0x38, 0, 0, 0.0f);
            func_80133998(((u8 *)collision) - 0xD8, 0x40, 1, 1, 0.0f);
          }
        } else {
          u8 **collision = &D_802903B0;
          func_80175388((*collision) + 0x74, 10.0f);
          func_80133998(((u8 *)collision) - 0xD8, 0x10, 0, 0, 0.0f);
          func_80133998(((u8 *)collision) - 0xD8, 0xE, 1, 1, 0.0f);
        }
        D_8028FBF8 = 0;
        return;

      case 44:
        /* Spawn actor effect 0x1D on the player (kept in D_8029020C) and record its offset from the player. */
        func_80178134(8, &D_8029030C, 0x64, 0x3C);
        effect = func_801A9054(((u8 *)&D_8029030C) - 0x34, 0x1D, 0);
        D_8029020C = effect;
        if (((s32 *)effect)[89] != 0) {
          D_801EEC04 = D_801F19B0;
        } else {
          D_801EEC04 = D_801F19B2;
        }
        D_802901FC = 0;
        D_80290360 = D_80290354;
        if (D_8029020C != NULL) {
          F(u8, D_8029020C, 269) = 0;
          F(s16, D_8029020C, 260) = D_801EEC12;
          F(s16, D_8029020C, 262) = D_801EEC12;
          F(s16, D_8029020C, 280) = D_801EEC12;
          F(s16, D_8029020C, 282) = D_801EEC12;
          func_8014ACB4(D_8029020C + 0xEC);
          func_8014AC1C(D_8029020C + 0xEC, 0);
          D_8029F398 = F(f32, D_8029020C, 60) - (*((f32 *)&D_8029030C));
          D_8029F39C = F(f32, D_8029020C, 64) - D_80290310;
          D_8029F3A0 = F(f32, D_8029020C, 68) - D_80290314;
        }
        break;

    }

  } else if (1) {
  }
#undef PREV_STATE
#undef F64_AFTER
}

extern s16 D_8029012E;
extern f32 D_8029F9D4, D_8029F9D8, D_8029F9DC, D_8029F9E0, D_8029F9E4;
/* Player action update (player_update_action), called from func_80171924 (player_update) every frame:
 * draws the sparkle trail while D_802901B0 >= 40, sets the D_80290300 state flags from the current
 * action (D_802903AC +4), then switches on the action (D_802903A4 ->unk8 +4) to handle input and
 * request transitions through func_80167604.
 * work split: the definition continues below this guard (c31 loop-weighted; only the case 30 li.d row is left; verified 11-20) */
void func_8016A058(void) {
#if 0
}
#endif
/* body of func_8016A058 */
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define V(t,s) F(t,&s,0)
typedef struct { f32 pad_; f32 v_; } VolF32_8016A058;
#define PCX F(f32,&PC,0)
#define IDX (D_80202218 * 0x190)
#define G(op,v) { s32 *g_=&D_80290300; *g_ op v; }
#define PD D_802902D8
#define P3 D_80290330
#define PC D_8029030C
#define FB D_8028FBEA
extern s32 D_802900C0;
#define B4(t,o) F(t,((ObjPtrBlk *)&D_802903A4)->unk10,o)
#define B0(t,o) F(t,((ObjPtrBlk *)&D_802903A4)->unkC,o)
#define AC(t,o) F(t,((ObjPtrBlk *)&D_802903A4)->unk8,o)
#define FA(t,o) F(t,((ObjPtrBlk *)&D_8029FA44)->unkC,o)
#define C8(t,o) F(t,((ObjPtrBlk *)&D_802900C0)->unk8,o)
#define A8(t,o) F(t,((ObjPtrBlk *)&D_802903A4)->unk4,o)
#define SF(t,p,o) (((struct { u8 pad_[o]; t f_; } *)(p))->f_)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
extern s32 D_80107B90;
extern f32 D_80107B98, D_80107B9C, D_80107BA0, D_80107BA4;
extern const f32 D_80107C58, D_80107C60, D_80107C68, D_80107C70, D_80107C78, D_80107C80, D_80107C88, D_80107C90, D_80107C98;
extern f32 D_80107CA4;
extern const f32 D_80107CA8, D_80107CB0;
extern f32 D_80107CBC, D_80107CC0, D_80107CC4;
extern const f32 D_80107CC8;
extern f32 D_80107CD4;
extern f64 D_80107CD8;
extern f32 D_80107CE0, D_80107CE4;
extern f64 D_80107CE8, D_80107CF0, D_80107CF8, D_80107D00;
extern const f32 D_80107D08;
extern f32 D_80107D14;
extern const f32 D_80107D18, D_80107D20, D_80107D28;
extern f32 D_80107D34;
extern f64 D_80107D38, D_80107D40, D_80107D48, D_80107D50, D_80107D58, D_80107D60, D_80107D68, D_80107D70;
extern const f32 D_80107D78;
extern f32 D_80107D84, D_80107D88, D_80107D8C, D_80107D90, D_80107D94;
extern f64 D_80107D98, D_80107DA0;
extern f32 D_80107DA8, D_80107DAC;
extern const f32 D_80107DB0, D_80107DB8, D_80107DC0, D_80107DC8, D_80107DD0, D_80107DD8, D_80107DE0, D_80107DE8;
extern const f32 D_80107DF4;
extern const f64 D_80107DF8, D_80107E00;
extern f32 D_80107E08, D_80107E0C, D_80107E10, D_80107E14, D_80107E18, D_80107E1C, D_80107E20, D_80107E24;
extern const f32 D_80107E28, D_80107E30, D_80107E38;
extern f32 D_80107E44, D_80107E48, D_80107E4C;
extern f64 D_80107E50, D_80107E58;
extern f32 D_80107E60, D_80107E64, D_80107E68, D_80107E6C, D_80107E70, D_80107E74, D_80107E78, D_80107E7C, D_80107E80, D_80107E84, D_80107E88, D_80107E8C, D_80107E90, D_80107E94;
extern f64 D_80107E98, D_80107EA0;
extern f32 D_80107EA8, D_80107EAC, D_80107EB0, D_80107EB4;
extern f64 D_80107EB8;
extern const f32 D_80107EC0, D_80107EC8;
extern f32 D_80107ED4;
extern f64 D_80107ED8;
extern f32 D_80107EE0, D_80107EE4;
extern const f32 D_80107EE8;
extern f32 D_80107EF4;
extern f64 D_80107EF8, D_80107F00, D_80107F08;
extern const f32 D_80107F10;
extern f32 D_80107F1C;
extern f64 D_80107F20;
extern f32 D_80107F28, D_80107F2C, D_80107F30, D_80107F34, D_80107F38, D_80107F3C;
extern f64 D_80107F40, D_80107F48;
extern f32 D_80107F90, D_80107F94, D_80107F98, D_80107F9C, D_80107FA0, D_80107FA4;
extern f64 D_80107FA8, D_80107FB0, D_80107FB8, D_80107FC0;
extern const f32 D_80107FC8, D_80107FD0;
extern f32 D_80107FDC;
extern f64 D_80107FE0;
extern const f32 D_80107FE8, D_80107FF0, D_80107FF8;
extern f32 D_80108004;
extern f64 D_80108008, D_80108010;
extern const f32 D_80108018, D_80108020, D_80108028;
extern f32 D_80108034, D_80108038, D_8010803C, D_80108040, D_80108044, D_80108048, D_8010804C;
extern f64 D_80108050;
extern const f32 D_80108058;
extern f32 D_80108064, D_80108068, D_8010806C;
extern f64 D_80108070, D_80108078;
extern const f32 D_80108080, D_80108088, D_80108090;
extern f32 D_8010809C;
extern f64 D_801080A0, D_801080A8, D_801080B0;
extern f32 D_801080B8, D_801080BC;
extern const f32 D_801080C0;
extern f32 D_801080C4, D_801080C8, D_801080CC, D_801080D0, D_801080D4, D_801080D8, D_801080E4;
extern const f32 D_801080E8;
extern f32 D_801080F4;
extern const f32 D_801080F8;
extern f32 D_80108104, D_80108108, D_8010810C, D_80108110, D_80108114, D_80108118, D_8010811C, D_80108120, D_80108124;
extern const f32 D_80108128;
extern f32 D_80108134, D_80108138, D_8010813C, D_80108140, D_80108144;
extern f64 D_80108148;
extern f32 D_80108150, D_80108154;
extern const f32 D_80108158;
extern f32 D_80108164;
extern const f64 D_80108168, D_80108170;
extern f32 D_80108178, D_8010817C, D_80108180, D_80108184, D_80108188;
extern const f32 D_80108190;
extern f32 D_8010819C, D_801081A0, D_801081A4;
extern const f32 D_801081A8, D_801081B0, D_801081B8;
extern f32 D_801081C4, D_801081C8, D_801081CC;
extern f64 D_801081D0;
extern f32 D_801081D8;
extern s16 D_801E7462;
extern f32 D_801ED680;
extern s32 D_801EEBD0, D_801EEBD4;
extern s16 D_801EEBF2;
extern s32 D_801EEBF4;
extern f32 D_801EEC00, D_801EEC04, D_801EEC14;
extern f32 D_801EF43C, D_801EF440, D_801EF444, D_801EF448, D_801EF44C, D_801EF450, D_801EF454, D_801EF458;
extern s32 D_801EF45C;
extern f32 D_801EF460;
extern u8 D_801FAA94[], D_801FAAAA[], D_801FAAAB[], D_801FAAAC[], D_801FAAAF[], D_801FAAB9[], D_801FAAC8[], D_801FAACA[], D_801FAACB[], D_801FAAF0[], D_801FAAF1[];
extern s32 D_801FAB78;
extern u8 D_80202218;
extern u8 *D_8028FAC8;
extern u8 *D_8028FAD0;
extern f32 D_8028F950, D_8028F9C8, D_8028FB3C;
extern s16 D_8028FB40;
extern f32 D_8028FBC4;
extern s16 D_8028FBDA, D_8028FBDC;
extern s32 D_8028FBE0, D_8028FBE4;
extern s16 D_8028FBE8;
extern s8 D_8028FBEC;
extern s16 D_8028FBEE;
extern s32 D_8028FBF0;
extern s16 D_8028FBF6;
extern u8 D_8028FBFA;
extern u16 D_8028FBFE;
extern s32 D_8028FC04;
extern f32 D_8028FD24, D_8029007C, D_80290080, D_80290088;
extern u8 *D_80290094;
extern u8 *D_802900A8;
extern void *D_802900AC;
extern s32 D_802900CC;
extern s16 D_802900D8;
extern u8 *D_802900E0;
extern f32 D_802900E4;
extern s16 D_802900F4, D_80290108, D_8029012E;
extern s32 D_80290134, D_8029013C;
extern s32 D_80290140[];
extern s32 D_80290144, D_80290168, D_8029016C, D_802901A8, D_802901C4;
extern s32 D_802901A0, D_802901A4, D_802901AC, D_802901B0, D_802901D0, D_802901D4;
extern s32 D_802901E4, D_802901E8;
extern f32 D_802901F0, D_802901F4, D_802901F8;
extern s32 D_802901FC;
extern u8 D_80290200[];
extern f32 D_80290204, D_80290208;
extern u16 D_802902FC;
extern u8 *D_80290304;
extern f32 D_80290318, D_8029031C, D_80290320;
extern f32 P3;
extern f32 D_80290334, D_80290338, D_80290340, D_8029034C, D_8029035C, D_80290360;
extern u8 D_80290374;
extern u8 D_80299718[], D_8029971C[];
extern s16 D_80299960;
extern u8 D_80299964[];
extern f32 D_8029F398, D_8029F39C, D_8029F3A0;
extern s32 D_8029F3A4, D_8029F3A8, D_8029F3AC;
extern s16 D_8029F480;
extern s8 D_8029F484, D_8029F485;
extern s32 D_8029F56C;
extern f32 D_8029F9D8;
extern f32 D_8029F9D4, D_8029F9D8, D_8029F9DC, D_8029F9E0, D_8029F9E4;
extern f32 D_8029F9EC, D_8029F9F4, D_8029FA00;
void func_80133B90();
void func_80149568(f32 *);
void func_8015F910();
s32 func_80174B58(void);
void func_8017541C(u8 *arg0);
void func_801754C0(u8 *arg0);
void func_80175560();
void func_80175EC0(void);
void func_801764A8(void);
void func_801766C0(void);
void func_8017753C(void);
void func_80177888(s32 arg0);
void func_80177910(void);
void func_8017797C(void);
void func_8018DF4C(u8 *arg0);
void func_80195D50();
s32 func_801A2944(f32, u8 *);
extern void func_801B13CC(void);
f32 func_801B150C(void);
s32 func_801B1580(void);
void func_801B1E48(void);
void func_801B2A1C(void);
void func_801B2B58(s32, f32, f32);
void func_801B3CA8(void);
void func_801BA644(TrailBuf *buf, TrailVec *a, TrailVec *b, u8 c, u8 d, u8 e, u8 f);
void func_801BA700(TrailBuf *buf, TrailVec *a, TrailVec *b);
void func_801BAF8C(u8 *arg0);
void func_801BB064(ObjectNode *arg0);
f32 a[3];
f32 b[3];
f32 c[4];
f32 q[4];
f32 unused_[18];
void *_0;
s32 _1;
Unk802904D4Node *_2;
f32 *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13, *_14;
u8 *_46c;
f32 *_15, *_16;
f32 _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _62, _63, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, _100, _101, _102, _103, _104, _105, _106, _107, _108, _109, _110, _111, _112, _113, _114, _115, _116, _117, _118, _119, _120, _121, _122, _123, _124, _125, _126, _127, _128, _129, _130, _131, _134, _135, _137, _138, _139, _140, _141, _142, _143, _144, _145, _146;
f64 _147, _148, _149, _150, _151, _152, _153, _154, _155, _156, _157, _158, _159, _160, _161, _162, _163, _164, _165, _166, _167, _168, _169, _170, _171, _172, _173, _174, _175;
s16 *_176;
s32 _177, _178, _179, _180, _181, _182, _183, _184, _185, _186, _187, _188, _189, _190, _191, _192, _193, _194, _195, _196, _197;
s32 **_198;
s32 *_199, *_200, *_201;
u8 *_202, *_203;
s32 *_204, *_205, *_206, *_207, *_208, *_209;
u8 *_210, *_211;
s32 *_212;
s32 _213, _214, _215, _216, _217, _218, _219, _220, _221, _222, _223, _224, _225, _226, _227, _228, _i36, _229, _230, _231, _232, _233, _234, _235, _236;
s32 var_condition_bit, var_condition_bit_2, var_condition_bit_3;
s32 _237, _238, _239, _240, _241, _242, _243, _244, _245, _246, _247, _248, _249, _250, _251;
#define _252 _196
s32 _253, _254, _255, _256, _257, _258, _260;
#define _259 _237
#define _133 _131
#define _35 _131
s32 _262;
u16 _263, _264;
u32 _265, _266;
u8 *_267, *_268, *_269, *_270, *_271, *_272, *_273;
u8 _274, _275, _276;
u8 *_277;
void **_278, **_279, **_280;
void *_281, *_282, *_283, *_284, *_285, *_286, *_287, *_288, *_289, *_290, *_291, *_292, *_293, *_294, *_295, *_296, *_297, *_298, *_299, *_300, *_301, *_302, *_303, *_304;
#define _242 _241
#define _244 _241
#define _245 _241
#define _246 _241
#define _247 _241
#define _248 _241
#define _249 _241
#define _304 _303
#define _210 _211
if (D_802901B0 >= 0x28) {
a[1]=0.0f;
a[2]=0.0f;
a[0]=D_80107B98;
func_801499A0(b, a, &D_80290374);
{ f32 px=PCX, py=D_80290310, pz=D_80290314;
f32 t0=px + b[0], t1=py + b[1], t2=pz + b[2];
f32 u0=px - b[0], u1=py - b[1], u2=pz - b[2];
a[0]=t0; a[1]=t1; a[2]=t2; b[0]=u0; b[1]=u1; b[2]=u2; }
_131=func_80147000(5) - 2;
a[1] += _131;
b[1] -= _131;
{ s32 t=D_801EEBD0;
if (t == 0) {
s32 fresh_=func_8013FCDC(0x578, 1, &D_80107B90);
D_801EEBD0=fresh_;
func_801BAF8C(fresh_);
func_801BA644(D_801EEBD0, a, b, 0xFF, 0xFF, 0x1E, 0x1E);
} else {
func_801BA700(t, a, b);
} }
_185=B4(s16,2);
if (((_185 == 0x3A) | (_185 == 1)) != 0) {
{ s32 *p=(s32 *)&D_8029016C; s32 *sq=p - 1; s16 *h; *p=0x64;
if (*sq == 0) {
func_801785E0(sq, 0x81, 0x64, &PC, 0xB4);
} else if (D_802004E0 == ((D_802004E0 / 10) * 0xA)) {
h=(s16 *)((u8 *)p + 0xC);
*h=MIN(MAX(*h + func_80147000(13) - 6, 0xA0), 0xC8);
}
}
} else { s32 *p68_=&D_80290168; if (*p68_ != 0) {
_224=D_8029016C - 0xA;
D_8029016C=_224;
if (_224 <= 0) {
func_80178704(p68_);
}
} }
} else if (((D_802901B0 == 1) || (D_802004E0 == 1) || ((D_802900E0 != 0) && (F(s16,F(s32,D_802900E0,84),2) != 0))) && (D_801EEBD0 != 0)) {
func_801BB064(D_801EEBD0);
func_80141720(&D_801EEBD0);
}
if ((D_802004E0 == 1) && (D_801EEBD4 != 0)) {
func_801BB064(D_801EEBD4);
func_80141720(&D_801EEBD4);
}
_188=AC(s16,4);
if (((_188 == 0x29) && (D_801E7460 == 0)) || (((_188 == 0xB) || ((_188 == 0x2A) && (B4(s16,2) != 0x32))) && (B0(u8,392) == 0))) {
s32 *g_=&D_80290300; *g_ &= ~1;
} else {
s32 *g_=&D_80290300; *g_ |= 1;
}
_177=AC(s16,4);
if ((_177 != 5) & (_177 != 0xB)) {
if (D_801E7531 == 0x28) {
A8(f32,40)=D_80107B9C;
} else if (_177 == 0x21) {
A8(f32,40)=D_80107BA0;
} else {
A8(f32,40)=D_80107BA4;
}
}
_187=AC(s16,4);
if (((_187 == 0xE) | (_187 == 0x21)) != 0) {
G(|=,0x40)
} else {
G(&=,~0x40)
}
if (AC(s16,4) == 0x12) {
G(|=,0x200)
} else {
G(&=,~0x200)
}
if (AC(s16,4) != 0xE) {
D_8028FBE0=0;
}
{ s16 *pdc_=&D_8028FBDC; if (*pdc_ > 0) {
*pdc_ -= 1;
} }
_178=F(s16,D_802903AC,4);
if ((((_178 == 3) | (_178 == 5)) != 0) || (_178 == 0xE)) {
G(&=,~0x18)
B0(s32,376)=FA(s32,376);
B0(s32,380)=FA(s32,380);
B0(s32,384)=FA(s32,384);
B0(s32,388)=FA(s32,388);
B0(u8,392)=FA(u8,392);
} else if (D_8028FBF6 == 0) {
if (_178 != 0x29) {
G(|=,0x18)
}
}
if (AC(s16,4) == 3) {
if (!(D_80290300 & 0x2000)) {
F(s32,&D_8029F9A0,0) &= 0xFEFFFFFF;
}
_212=&D_8029F978;
} else {
do { _212=&PD; } while (0);
}
if (V(s16,D_802900DC) != 0) {
V(s16,D_802900DC) -= 1;
}
if ((func_8015C4C8() == 0) && (AC(s16,4) != 0x21) && (F(u8,&D_801FAAAB,IDX) != 0)) {
V(s16,D_802900DC)=V(s16,D_802900DC) + 1;
}
if ((B0(u8,392) == 1) && (AC(s16,4) != 0x27)) {
V(u8,D_8028FBFA)=0;
D_8028FC04=0;
}
{ u8 *pfb_=&D_8028FBFB;
if (*pfb_ != 0) {
if (V(s32,D_8029F9A4) == &PD) {
if (--*pfb_ == 0) {
V(s32,D_8029F9A4)=0;
}
} else if (D_80290304 != NULL) {
if (--*pfb_ == 0) {
D_80290304=NULL;
}
} else {
goto block_80;
}
} else {
block_80:
D_8028FBFB=0;
} }
_189=AC(s16,4);
switch (_189) {
case 3:
if ((F(u8,D_8029FA4C,9) != 0) && (V(s32,D_8029F9A0) & 0x200000) && (*(f32 *)D_8029FA44 > (FA(f32,112) + F(f64,&D_80107C58,4)))) {
func_801B13CC();
goto block_89;
}
if (F(u8,&D_801FAACA,IDX) != 0) {
if (D_801EC740 == 1) {
block_89:
func_80167604(0x14);
} else {
goto block_92;
}
} else if ((D_801EC740 != 1) || (V(s16,D_8028FBF8) != 0x190)) {
block_92:
if (!(D_80297BEC & 0x80) && (D_801EC740 == 1) && (D_8029F56C == 0) && (V(f32,D_8029F5C4) <= F(f64,&D_80107C60,4)) && (F(u8,&D_801FAAAF,IDX) != 0) && (D_8029F5C8 == 0)) {
D_8029F5C8=0x1E;
func_80177910();
blk99:
func_80167604(0x2B);
break;
}
if ((B4(s32,4) != 0) && (func_80147000(500) < 0xA)) {
func_80133998(&PD, 0x39, 0, 0, 0.0f);
}
F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,12)=func_801B150C();
B0(f32,116)=FA(f32,116) + F(f64,&D_80107C68,4);
if ((D_8029F5C8 == 0) && (FB >= 0xB) && (D_802901D4 == 0) && ((D_802900E0 == 0) || (F(s16,F(s32,D_802900E0,84),2) == 0))) {
_156=FA(f32,112) - F(f64,&D_80107C70,4);
_129=_156;
if (_129 > 0.0f) {
_175=F(f64,&D_80107C80,4);
_164=_156 / F(f64,&D_80107C78,4);
_147=(f64)_129;
if (_164 < _175) {
_129 += _164;
} else {
_129 += _175;
}

}
if ((D_801E7462 == 0) && (func_80148DB0(&PC, &D_8029F9AC) > (_129 + F(f64,&D_80107C88,4))) && (D_802901B0 == 0)) {
*(Words3 *)&P3=*(Words3 *)&D_8029F9D0;


func_80167604(7);
D_8028FBD8=0xA;
func_801B13CC();
}
_168=D_80290310 - V(f32,D_8029F9B0);
_170=F(f64,&D_80107C90,4) - D_8029F9A8;
_150=FA(f32,112) + F(f64,&D_80107C98,4); if (_170 < 0.0) {

if ((_150 + 0.0) < _168) {
goto block_121;
}
} else if ((_150 + _170) < _168) {
block_121:
func_80167604(0xE);
V(f32,D_80290334)=V(f32,D_8029F9D4);
}
}
} else {
goto blk99;
}
break;
case 0:
if ((V(s16,D_8028FBF8) >= 0x191) && (D_801EC740 == 1)) {
if (B4(s16,2) == 0x2A) {
if ((func_80147000(50) < 0x19) || (D_802901A8 != 0)) {
func_80133998(&PD, 6, 0, 0, D_80107CA4);
func_80133998(&PD, 0x1A, 0, 1, 0.0f);
} else {
func_80133998(&PD, 0xB, 0, 0, 0.0f);
func_80133998(&PD, 0x46, 0, 1, 0.0f);
func_80133998(&PD, 0xB, 0, 1, D_80107CA8);
func_80133998(&PD, 0x2A, 1, 1, 0.0f);
D_80290360=func_801496C8(D_8028F95C + F(f64,&D_80107CA8,4));
V(s16,D_8028FBF8)=0;
}
} else {
if (F(f64,&D_80107CB0,4) < V(s16,D_8028FBF8)) {
func_80133998(&PD, 7, 0, 0, 0.0f);
func_80133998(&PD, 0x2A, 1, 1, 0.0f);
V(s16,D_8028FBF8)=0;
}
if ((B4(s16,2) == 0x1A) && (func_801A2944(D_80107CBC, &PD) != 0)) {
func_80178134(0xA4, ((u8 *)&PD + 0x34), 0x5A, func_80147000(16) + 0x78);
}
}
if ((D_802004E0 == ((D_802004E0 / 30) * 0x1E)) && (func_80147000(10) < 4)) {
func_80133998(&PD, 0x1A, 0, 1, 0.0f);
func_80133998(&PD, 0x1A, 0, 1, 0.0f);
if (func_80147000(10) < 5) {
func_80133998(&PD, 0x1A, 0, 1, 0);
}
}
}
break;
case 21:
if (func_801A2944(D_801EEBF4, &PD) != 0) {
func_80178134(D_801EEBF2, ((u8 *)&PD + 0x34), 0x50, func_80147000(56) + 0x64);
}
break;
case 1:
case 29:
if ((AC(s16,6) == 7) && (FB < 3)) {
V(f32,D_80290354)=D_80290360;
}
if ((B4(s16,16) == -1) || (AC(s16,4) != 1)) {
_190=B4(s16,2);
_258=V(s8,D_8028FBEC);
if (((_190 == 0x50) | (_190 == 0x34)) == 0) {
a[0]=PCX - D_80290318;
a[1]=D_80290310 - D_8029031C;
a[2]=D_80290314 - D_80290320;
if (D_80290300 & 0x8000) {
A8(f32,12)=D_80107CC0;
goto block_152;
}
if ((B0(u8,392) == 0) && (D_80290300 & 0x1000)) {
A8(f32,12)=D_80107CC4;
_125=(a[0] * a[0]) + (a[2] * a[2]);
} else {
A8(f32,12)=D_80107CC8;
block_152:
_125=(a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]);
}
_118=sqrtf(_125);
_131=_118;
if (D_802901B0 != 0) {
_131=_131 * F(f64,&D_80107CC8,4);
}
{ s32 _261;
if (D_80290134 & 1) {
_261=2;
_131=D_80107CD4;
goto block_172;
}
if (_131 == 0.0f) {
_261=-1;
goto block_172;
}
{
_161=_131;
if ((_161 < D_80107CD8) || (D_80290300 & 0x8000)) {
_101=_131 * D_80107CE0;
V(s8,D_8028FBEC)=0;
D_8028FBFE += 1; _141=D_80107CE4; if (_101 < D_80107CE8) {
_141=_101;
}
goto block_170;
} else if ((_161 < D_80107CF0) && (AC(u8,9) != 3)) {
_162=(_161 - D_80107CF8) * D_80107D00;
_141=D_80107D08;
V(s8,D_8028FBEC)=1;
D_8028FBFE += 1; if (_162 < F(f64,&D_80107D08,4)) {
_141=_162;
}
block_170:
_131=_141;
} else {
_131=D_80107D14;
_261=2;
D_8028FBFE=0;
block_172:
V(s8,D_8028FBEC)=_261;
}
} }
if (AC(s16,4) == 0x1D) {
_252=-1;
_131=D_80107D18;
_241=0;
do {
_297=((u8 **)D_802903B0)[_241];
if (_297 != NULL) {
_31=F(f32,_297,4);
if (_31 > 0.0f) {
if (_31 < _131) goto block_183;
} else {
if (-_31 < _131) {
block_183:
_131=F(f32,((u8 **)D_802903B0)[_241],4);
_252=_241;
{ f64 d_=_131; _131=d_; }
if (!(_131 > 0.0f)) {
_131=-_131;
}
}
}
}
_241 += 1;
} while (_241 < 4);
if (_252 != -1) {
_241=_252 * 4;
_298=*(s32 *)((s32)_241 + (s32)D_802903B0);
_131=(D_80290080 * F(f32,_298,0)) + (D_80290088 * F(f32,_298,8)); { f64 d_=_131; _131=d_; }
_119=_131;
if (!(_131 > 0.0f)) {
_119=-_131;
}
if (F(f64,&D_80107D18,4) < _119) {
{ f32 *p3_=&P3;
func_80149318(p3_, F(s32,_241 + F(s32,_212,216),0));
_43=*p3_ * _131; }
_52=D_80290338 * _131;
V(f32,P3)=_43;
D_80290338=_52;
D_80290360=func_801496C8(func_80147460(_43, _52));
_299=*(s32 *)((s32)_241 + (s32)D_802903B0);
_85=F(f32,_299,0);
_32=F(f32,_299,8);
_44=(_85 * _85) + (_32 * _32);
_120=sqrtf(_44);
D_8029035C=func_80147460(F(f32,(((u8 **)D_802903B0)[_252]),4), _120);
}
}
} else {
if ((_258 != V(s8,D_8028FBEC)) && (B4(s16,16) == -1)) {
switch (V(s8,D_8028FBEC)) {
case 0:
func_80133998(&PD, 0x18, 1, 0, 0);
break;
case 1:
func_80133998(&PD, 0xC, 1, 0, 0);
break;
case 2:
func_80133998(&PD, 0x3A, 1, 0, 0);
break;
}
}
if (D_802901B0 != 0) {
_131=_131 * F(f64,&D_80107D20,4);
}
((void (*)(void *, f32))func_80133B90)(&PD, _131);
}
func_8017753C();
}
}
break;
case 28:
if (B4(s32,4) == 0x2A) {
AC(s16,4)=2;
}
break;
case 8:
V(f32,P3)=V(f32,P3) * F(f64,&D_80107D28,4);
D_80290334=D_80290334 * F(f64,&D_80107D28,4);
D_80290338=D_80290338 * F(f64,&D_80107D28,4);
break;
case 9:
V(f32,D_80290348)=D_80107D34;
if (AC(s16,6) == 0xE) {
P3=P3 * D_80107D38;
D_80290338=D_80290338 * D_80107D38;
}
if ((u32)(AC(u8,9) - 2) < 2) {
P3=P3 * D_80107D40;
D_80290338=D_80290338 * D_80107D40;
}
if ((D_802901AC != 0) || (D_80107D48 < D_8029F9A8)) {
P3=P3 * D_80107D50;
D_80290338=D_80290338 * D_80107D50;
}
if (D_802901AC != 0) {
if (D_802901C4 != 0) {
F(f32,&P3,0)=F(f32,&P3,0) * D_80107D58;
D_80290338=D_80290338 * D_80107D58;
goto block_229;
}
} else {
block_229:
if (D_802901C4 != 0) {
F(f32,&P3,0)=F(f32,&P3,0) * D_80107D60;
D_80290338=D_80290338 * D_80107D60;
}
}
if ((AC(s16,6) == 0x14) && (D_80107D68 < D_8029F9A8)) {
F(f32,&P3,0)=F(f32,&P3,0) * D_80107D70;
D_80290338=D_80290338 * D_80107D70;
}
if (((D_80290300 & 0x1000) || (AC(u8,9) != 0)) && (D_8028FBD8 == 0)) {
AC(s16,4)=2;
}
break;
case 6:
case 16:
{ s16 n_; s16 *t_ = (s16 *)&D_8028FBDA; n_ = *t_;
#define n_avail_
if (n_ != 0) {
*t_ = n_ - 1;
{ f32 *p3_ = (f32 *)&P3;
*p3_=F(f32,&P3,4)=F(f32,&P3,8)=0.0f;
{ s32 c_ = *(s16 *)((u8 *)p3_ + ((u8 *)&D_8028FBDA - (u8 *)&P3)); Vec3F *v_ = (Vec3F *)((u8 *)p3_ + ((u8 *)&D_8029F9D0 - (u8 *)&P3)); *v_ = *(Vec3F *)p3_;
#define b9d0_ ((u8 *)v_)
if (c_ == 0) {
{ _7=b9d0_ - 0x58;
func_801754C0(_7);
func_80178134(0xAB, ((u8 *)p3_ - 0x24), 0x64, 0x80);
func_801B13CC();
D_8028FBD8=7;
func_801B2B58(_7, v_->x, v_->z); v_ = NULL; }
D_8029F485=1;
if (D_802901D0 != 0) {
D_8029F482=1;
}
}
} }
#undef b9d0_
#undef c_
} else {
if (B4(s32,4) == 0x48) {
func_8017797C();
}
} }
break;
case 5:
_215=D_80202218 * 0x190;
if ((F(u8,&D_801FAAAC,_215) != 0) && (D_801EC740 == 1)) {
F(u8,&D_801FAAF0,_215)=1;
func_80167604(3);
func_80133998(&PD, 0x48, 0, 0, D_80107D78);
} else {
func_801B1E48();
*(Words3 *)&P3=*(Words3 *)&D_801ED3C4;
if ((FB >= 0x15) && (D_802900F0 == 0) && (D_802900F4 == 0)) {
func_80175560();
if (D_802900F0 != 0) {
func_801754C0(D_802900F0);
}
}
}
break;
case 11:
V(f32,P3)=V(f32,P3) * F(f64,&D_80107D78,4);
D_80290334=D_80290334 * F(f64,&D_80107D78,4);
D_80290338=D_80290338 * F(f64,&D_80107D78,4);
if ((AC(s16,6) == 0x1F) && (FB >= 4)) {
func_80167604(3);
func_80133998(((u8 *)&P3 - 0x58), 0x44, 0, 0, D_80107D84);
break;
}
if ((B0(u8,392) == 0) && !(D_802004E0 & 1)) {
a[0]=func_80147000(11) - 5;
a[1]=D_80107D88;
_33=func_80147000(11) - 5;
a[2]=_33;
a[0] += PCX;
a[1] += D_80290310;
a[2]=_33 + D_80290314;
_277=func_801B66D4(7, a, ((u8 *)&PC + 0x24), 0, 0);
if (_277 != 0) {
((ObjectNode *)_277)->unk028 |= 0x41;
F(f32,((ObjectNode *)_277)->unk0D0,24)=D_80107D8C;
F(f32,_277,112)=D_80107D8C;
}
}
V(f32,D_80290334)=0.0f;
_216=D_80202218 * 0x190;
if ((F(u8,&D_801FAAAC,_216) != 0) && (D_801EC740 == 1)) {
F(u8,&D_801FAAF1,_216)=1;
func_80167604(3);
func_80133998(((u8 *)&D_80290334 - 0x5C), 0x44, 0, 0, D_80107D90);
break;
}
if ((FB >= 0x15) && (D_802900F0 == 0) && (D_802900F4 == 0)) {
func_80175560();
if (D_802900F0 != 0) {
func_8017541C(D_802900F0);
}
}
break;
case 4:
{ s16 *t_ = (s16 *)&D_8028FBDA;
if (*t_ != 0) {
*t_ -= 1;
if (*t_ == 0) {
func_80133998(&PD, 0x43, 0, 0, D_80107D94);
func_80133998(&PD, 0x2A, 1, 1, 0.0f);
D_8028FBD8=0xC;
func_8017541C(&D_8029F978);
func_801B2B58(&D_8029F978, D_8029F9D0, D_8029F9D8);
_34=D_80290334 + (D_801ED680 * D_80107D98 * D_80107DA0);
V(f32,D_80290334)=_34;
D_80290334=_34 * (A8(f32,0) / D_80107DA8);
_201=((u8 *)&PD + 0x34);
func_801B13CC();
func_80178134(0xA7, _201, 0x64, 0x80);
if (D_8029F487 == 1) {
func_80178134(0x104, _201, 0x64, 0x80);
}
if (D_802901D0 != 0) {
D_8029F482=1;
}
}
} }
break;
case 7:
{ f32 kdb0_; f32 *pa_;
V(f32,D_80290348)=D_80107DAC;
kdb0_=D_80107DB0;
do { *(Words3 *)a=*(Words3 *)&PC; } while (0);
a[1] -= kdb0_; pa_=a;
if (!(D_80290134 & 1) && (FB < 4)) {
func_801B7344(pa_, 2, 0.0f);
} }
if (((s32 (*)(s32))func_8016536C)(3) == 0) {
if (((s32 (*)(s32))func_8016536C)(2) != 0) {
func_80167604(2);
} else if (B4(s32,4) != 0x3E) {
if (((s32 (*)(s32))func_8016536C)(0x18) != 0) {
func_80167604(0x18);
}
} else {
func_8017797C();
}
} else {
goto blk372;
}
break;
case 14:
if ((F(u8,D_8029FA4C,9) != 0) && (V(s32,D_8029F9A0) & 0x200000) && (*(f32 *)D_8029FA44 > (FA(f32,112) + F(f64,&D_80107DB0,4)))) {
D_8029F9D0=D_8029F9D0 * F(f64,&D_80107DB8,4);
D_8029F9D4=D_8029F9D4 * F(f64,&D_80107DB8,4);
D_8029F9D8=D_8029F9D8 * F(f64,&D_80107DB8,4);
func_80167604(0x14);
}
if (F(f64,&D_80107DC0,4) < (F(f32,&D_80290310,0) - F(f32,&D_8029F9B0,0))) {
D_80290334=(D_80290334 * F(f64,&D_80107DC8,4)) + (V(f32,D_8029F9D4) * F(f64,&D_80107DD0,4));
}
_131=func_80148E48(((u8 *)&D_80290310 - 4), ((u8 *)&D_8029F9B0 - 4));
if ((((D_801EC740 == 2) && (D_8028FBE0 != 0)) || ((D_8028FBE0 != 0) && (F(u8,&D_801FAAAB,IDX) == 0) && (D_801EC740 != 0))) && (F(u8,&D_801FAAAA,IDX) == 0)) {
_169=D_801EEC40;
_151=F(f64,&D_80107DE0,4);
if ((_131 < (FA(f32,112) + ((_169 * F(f64,&D_80107DD8,4)) / _151))) && (V(f32,D_8029F9D4) < (_169 / _151))) {
if (D_801EC740 != 2) {
func_80178134(0xAC, &PC, 0x64, 0x80);
}
if (FA(u8,394) & 2) {
_163=(D_801EEC40 * F(f64,&D_80107DE8,4)) / _151;
#define _94x F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,0)
_95=_94x;
F(f32,&D_8029F9D4,0)=_163 / ((!(D_80107DF4 < _95) || (_95 < D_80107DF8)) ? ((D_80107DF4 < _95) ? _95 : D_80107E00) : D_80107DF8);
#undef _94x
} else {
F(f32,&D_8029F9D4,0)=(D_801EEC40 * D_80107E08) / _151;
}
D_8028FBE0=0;
D_8029F9E0=V(f32,D_8029F9D4);
if (D_8028FBE8 == 0xE) {
if (*(f32 *)D_8029FA44 > D_80107E0C) {
func_80133998(&PD, 0x1B, 0, 0, D_80107E10);
} else {
func_80133998(&PD, 0x1B, 0, 0, D_80107E14);
}
}
}
}
if (((F(u8,D_801FAAC6,(D_80202218) * 400 + 0) != 0) || (F(u8,&D_801FAAC7,IDX) != 0)) && (D_801EC740 != 0)) {
D_8028FBE0=1;
if ((B4(s32,4) != 0) && (D_8028FBE4 == 0)) {
D_8028FBE4=1;
}
}
break;
case 18:
if (FB < 3) {
V(f32,D_80290334)=0.0f;
} else {
V(f32,D_80290334)=D_80107E18;
}
if (!(D_80290300 & 0x2000)) {
P3 /= D_80107E1C;
D_80290338 /= D_80107E1C;
}
break;
case 19:
if (FB == 3) {
func_80133998(&PD, 0x3F, 0, 0, D_80107E20);
func_80133998(&PD, 0x2A, 1, 1, 0.0f);
D_8028FBD8=6;
}
if (func_801B1580() != 0) {
func_80175388(D_802903B0 + 0x74, 11.0f);
} else {
func_80175388(D_802903B0 + 0x74, 13.0f);
}
break;
case 2:
{ f32 *p334_;
if ((V(s32,D_8029F9A4) == 0) && (p334_=&D_80290334, *p334_ < 0.0f)) {
_102=B0(f32,112);
_95=D_80290310 - V(f32,D_8029F9B0);
_86=FA(f32,112);
if ((_95 < (_86 + (_102 * D_80107E24))) && ((_86 + _102) < _95)) {
_11=((u8 *)p334_ - 0x28);
if (AC(s16,6) != 0x14) {
_199=((u8 *)&D_8029F9A4 + 8);
if (func_80148DB0(_11, _199) < (FA(f32,112) + D_80107E28)) {
func_80149428(a, _11, _199);
_3=((u8 *)p334_ - 4);
a[0]=a[0] * F(f64,&D_80107E28,4);
a[2]=a[2] * F(f64,&D_80107E28,4);
func_80149428(_3, _3, a);
}
}
}
} }
if ((FB >= 2) && (V(s32,D_8029F9A4) == &PD)) {
V(s32,D_8029F9A4)=0;
}
if (((u32)(*(u16 *)&FB - 1) < 4) && (AC(s16,6) != 0x12) && (F(u8,&D_801FAAAA,IDX) != 0) && (D_801EC740 == 1)) {
V(f32,D_80290334)=V(f32,D_80290334) + ((D_801EEC40 * F(f64,&D_80107E30,4)) / F(f64,&D_80107E38,4));
}
if ((F(u8,D_801FAAC6,(D_80202218) * 400 + 0) != 0) && (B0(u8,392) == 0) && (FB >= 2)) {
_221=D_801EC740;
{ f32 *q334_;
if ((_221 == 1) && (D_8028FC04 == 0) && (q334_=&D_80290334, *q334_ >= D_80107E44)) {
func_80178134(func_80147000(4) + 0xFB, ((u8 *)q334_ - 0x28), 0x64, 0x80);
_13=((u8 *)q334_ - 0x5C);
func_80133998(_13, 0x42, 0, 0, D_80107E48);
_45=(P3 * P3) + (D_80290338 * D_80290338);
_128=sqrtf(_45);
P3=D_80290338=0.0f;
_116 = _128 / D_80107E4C;
func_8016049C(_13, -_116, A8(f32,8));
D_8028FC04=_221;
*q334_=(D_801EEC40 * D_80107E50) / D_80107E58;
} }
}
break;
case 20:
if ((func_801A2944(D_80107E60, &PD) != 0) || (func_801A2944(D_80107E64, &PD) != 0) || (func_801A2944(D_80107E68, &PD) != 0) || (func_801A2944(D_80107E6C, &PD) != 0) || (func_801A2944(D_80107E70, &PD) != 0) || (func_801A2944(D_80107E74, &PD) != 0)) {
func_80178134(0x94, &PC, 0x78, func_80147000(40) + 0x6E);
} else if ((func_801A2944(D_80107E78, &PD) != 0) || (func_801A2944(D_80107E7C, &PD) != 0) || (func_801A2944(D_80107E80, &PD) != 0) || (func_801A2944(D_80107E84, &PD) != 0) || (func_801A2944(D_80107E88, &PD) != 0) || (func_801A2944(D_80107E8C, &PD) != 0)) {
func_80178134(0x95, &PC, 0x78, func_80147000(40) + 0x6E);
}
F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,12)=A8(f32,12);
if ((!(V(s32,D_8029F9A0) & 0x200000) || (F(u8,D_8029FA4C,9) == 0)) && (F(u8,&D_801FAACA,IDX) != 0) && (D_801EC740 == 1)) {
blk372:
func_80167604(3);
break;
}
if ((F(u8,&D_801FAAAC,IDX) != 0) && (D_801EC740 == 1)) {
func_801766C0();
} else {
if ((F(u8,&D_801FAAAA,IDX) == 0) && (D_801EC740 == 1)) {
V(u8,D_8028FBFA)=0;
}
if ((D_8028FBD8 == 0) && (!(V(s32,D_8029F9A0) & 0x200000) || (F(u8,D_8029FA4C,9) == 0)) && (FB >= 2) && (((D_80290310 - V(f32,D_8029F9B0)) > (D_8029F9A8 + B0(f32,112) + D_80107E90)) || ((D_801ED680 * D_80107E94) < V(f32,D_8029F9D4)))) {
func_80167604(1);
func_801B13CC();
V(s32,D_8029F9A4)=0;
V(f32,D_80290334)=V(f32,D_8029F9D4);
}
func_801B2B58(&D_8029F978, D_8029F9D0, D_8029F9D8);
_46=(D_8029F9D0 * D_8029F9D0) + (D_8029F9D8 * D_8029F9D8);
_123=sqrtf(_46);
_152=D_80107E98;
if (_152 < _123) {
D_80290360=func_801496C8(func_80147460(D_8029F9D0, D_8029F9D8) + D_80107EA0);
}
_206=((u8 *)&D_8029F978 + 0x34);
B0(u8,392)=1;
_35=func_80148DB0(_206, ((u8 *)&D_8029F978 + 0x40));
_259=V(s8,D_8028FBEC); if (_35 < _152) {

if (_259 != -1) {
func_80133998(&PD, 2, 0, 0, 0.0f);
func_80133998(&PD, 0x2A, 1, 1, 0.0f);
}
V(s8,D_8028FBEC)=-1;
} else {
V(s8,D_8028FBEC)=3;
if ((_259 ^ 3) != 0) {
if (B4(s16,2) == 0x2A) {
func_80133998(&PD, 2, 0, 0, D_80107EA8);
func_80133998(&PD, 0, 1, 1, 0);
} else {
func_80133998(&PD, 0, 1, 0, 0);
}
}
_191=B4(s16,2);
if (_191 != 2) {
if (D_801EF454 < _35) {
if (_191 != 1) {
func_80133998(&PD, 1, 1, 0, 0);
goto block_409;
}
}
if (_35 <= D_801EF454) {
if (B4(s16,2) != 0) {
func_80133998(&PD, 0, 1, 0, 0);
goto block_409;
}
goto block_410;
}
block_409:
if (B4(s16,2) == 0) {
block_410:
_133=_35 / D_801EF450;
} else {
_133=_35 / (D_801EF450 * D_80107EAC);
}
((void (*)(void *, f32))func_80133B90)(&PD, _133);
}
}
}
break;
case 22:
{ s16 *fbp_=&FB;
if (*fbp_ == 3) {
D_801EF460=D_80107EB0;
func_80175388(D_802903B0 + 0x74, 6.5f);
}
if ((u32)(*(u16 *)fbp_ - 4) < 0x12) {
A8(f32,8)=D_80107EB4;
func_8016049C(&PD, D_801EF460, A8(f32,8));
D_801EF460=D_801EF460 * D_80107EB8;
SF(f32,((ObjPtrBlk *)&D_802903A4)->unk4,8)=D_80107EC0;
}
_192=*fbp_;
if (_192 == 0x16) {
func_80175388(D_802903B0 + 0x74, 13.0f);
}
if (*fbp_ == 4) {
V(f32,D_80290334)=V(f32,D_80290334) + F(f64,&D_80107EC0,4);
func_80178134(func_80147000(2) + 0xFF, ((u8 *)&D_80290334 - 0x28), 0x64, 0x8A);
}
if ((B4(s32,4) != 0) && (B0(u8,392) != 0)) {
D_80290360=V(f32,D_80290354);
V(f32,D_80290354)=V(f32,D_80290354);
}
}
break;
case 23:
{ s16 *fbp_=&FB;
if (*fbp_ == 0xA) {
D_80290360=func_801496C8(V(f32,D_80290354) + F(f64,&D_80107EC8,4));
}
if (*fbp_ < 0xB) {
func_8016049C(&PD, -0.2f, A8(f32,8));
} else {
func_8016049C(&PD, 0.2f, A8(f32,8));
}
if (B4(s32,4) != 0) {
func_8017797C();
}
}
break;
case 24:
*(Words3 *)&P3=*(Words3 *)&D_801ED3C4;
a[0]=a[1]=a[2]=0.0f;
func_8015F910(&D_80290200, a, &D_801ED3C4, NULL, NULL, NULL, 0, 0x20, *(volatile s32 *)&D_80290094, *(volatile s32 *)&D_80290094);
_4=((u8 *)&P3 - 0x24);
func_801493EC(_4, _4, D_80107ED4, &D_80290200, D_80107ED4);
if ((FB >= 0x15) && (B4(s32,4) == 0x13) && (func_80147000(200) < 0xA)) {
func_80133998(((u8 *)&P3 - 0x58), 0x12, 0, 0, 0.0f);
}
if (F(f32,D_802900AC,4) <= D_80107ED8) {
func_80167604(0x1B);
}
B0(u8,392)=1;
break;
case 26:
if (func_801A2944(D_80107EE0, &PD) != 0) {
func_80178134(0x9A, ((u8 *)&PD + 0x34), 0x5A, 0x80);
}
a[0]=a[1]=a[2]=0.0f;
func_8015F910(&D_80290200, a, &D_801ED3C4, NULL, NULL, NULL, 0, 0x20, *(volatile s32 *)&D_802900A8, *(volatile s32 *)&D_802900A8);
a[0]=F(f32,&D_80290200,0) - F(f32,&PD,52);
a[1]=D_80290204 - D_80290310;
a[2]=D_80290208 - D_80290314;
func_80148D0C(((u8 *)&PD + 0x34), a, 0.4f);
if (B4(s32,4) == 0x23) {
func_8017797C();
}
break;
case 25:
a[0]=a[1]=a[2]=0.0f;
func_8015F910(&D_80290200, a, &D_801ED3C4, NULL, NULL, NULL, 0, 0x20, *(volatile s32 *)&D_802900A8, *(volatile s32 *)&D_802900A8);
V(f32,D_80290334)=0.0f;
D_8028FD24 -= D_8029007C;
if (FB < 0xB) {
_8=((u8 *)&D_80290334 - 0x28);
func_80149428(a, &D_80290200, _8);
a[0] *= D_801EF43C;
a[2] *= D_801EF43C;
a[1]=(D_80290204 + D_801EF440) - D_80290310;
func_80148D0C(_8, a, 0.4f);
}
break;
case 17:
if (B4(s32,4) != 0) {
func_8017797C();
}
break;
case 27:
if (FB >= 4) {
u8 *b0_=(u8 *)((ObjPtrBlk *)&D_802903A4)->unkC;
_36=F(f32,b0_,116);
if (_36 != F(f32,b0_,112)) {
_87=F(f32,b0_,112);
_37=(_36 - _87) / D_80107EE4;
_88=A8(f32,76);
_96=-_88;
if (_37 < _96) {
if (_96 < _88) {
goto block_450;
}
goto block_455;
}
if (_37 < _88) {
block_450:
_97=(B0(f32,116) - B0(f32,112)) / D_80107EE8;
_89=A8(f32,76);
if (_97 < -_89) {
_124=_87 - _89;
} else {
_124=_87 + _97;
}
} else {
block_455:
_124=_87 + A8(f32,76);
}
F(f32,b0_,112)=_124;
}
if ((AC(s16,6) == 0x18) && (FB < 6)) {
func_8016049C(&PD, 1.0f, A8(f32,8));
}
}
if (FB == 3) {
u8 **b3=&D_802903B0;
func_80175388(*b3 + 0x74, 13.0f);
D_80290300 |= 1;
if (AC(s16,6) == 0x18) {
func_8016049C(((u8 *)b3 - 0xD8), 4.0f, A8(f32,8));
} else {
func_8016049C(((u8 *)b3 - 0xD8), -4.0f, A8(f32,8));
}
}
break;
case 30:
if (FB < 5) {
D_8029F9D0=D_8029F9D4=D_8029F9D8=0.0f;
F(f32,&D_8029F9B0,0) += D_801EF458;
D_8029F9A0 &= ~1;
V(f32,P3)=V(f32,P3) * F(f64,&D_80107EE8,4);
D_80290334=D_80290334 * F(f64,&D_80107EE8,4);
D_80290338=D_80290338 * F(f64,&D_80107EE8,4);
} else {
if (FB == 5) {
{ s32 *pa=&D_8029F9A0; f32 *pf;
*pa |= 1;
func_80178134(0xA8, &PC, 0x64, 0x80);
D_8029FA00=V(f32,D_80290354);
D_8029F9F4=V(f32,D_80290354);
pf=(f32 *)((u8 *)pa + 52);
func_801B13CC();
_98=F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,0);
*pf=(A8(f32,0)*D_80107EF8) / ((D_80107EF4 < _98) ? (f64)_98 : 5.0); }
F(f32,&D_8029F9D0,0)=D_8029F9D8=0.0f;
FA(s32,0)=NULL;
{ u8 *b9d0_=(u8 *)&D_8029F9D0; _9=b9d0_ - 0x58;
func_8016049C(_9, (A8(f32,0) * D_80107F08) / F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,0), F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,8));
func_801B2B58(_9, *(f32 *)b9d0_, D_8029F9D8); }
*(Words3 *)&P3=*(Words3 *)&D_801ED3C4;
F(u8,&D_801FAAAC,IDX)=0;
F(s32,&D_801FAB78,IDX)=0x3E8;
V(s16,D_802900DC)=0xA;
if (D_802901D0 != 0) {
D_8029F482=1;
}
break;
}
if (((s32 (*)(s32))func_8016536C)(1) != 0) {
func_80167604(1);
}
}
break;
case 31:
if ((D_802901D4 != 0) || ((D_802901D0 != 0) && (D_8029F482 >= 0x32))) {
func_80149428(a, &D_8029F9AC, &PC);
_47=(a[0] * a[0]) + (a[2] * a[2]);
_142=sqrtf(_47);
if (D_80107F10 < _142) {
D_80290360=func_801496C8(func_80147460(a[0], a[2]));
}
}
_157=V(f32,D_80290350);
if ((F(f64,&D_80107F10,4) < _157) || (V(f32,D_80290350) < D_80107F1C)) {
_17=func_801496C8(_157 - D_80107F20);
D_8029035C=_17;
V(f32,D_80290350)=_17;
}
_99=V(f32,D_8029F9B0) - D_80290310;
if (((_99 > 0.0f) ? (_99 < D_80107F28) : (-_99 < D_80107F2C))) {
if (func_80148DB0(&D_8029F9AC, &PC) < ((FA(f32,112) + B0(f32,112)) - D_80107F30)) {
func_80178134(0xAB, &PC, 0x46, 0x8A);
AC(s16,4)=0xB;
AC(s16,6)=0x1F;
FB=0;
D_8029F9D0 *= 0.0f;
D_8029F9D4 *= 0.0f;
D_8029F9D8 *= 0.0f;
} else {
goto block_493;
}
} else {
block_493:
if (func_80174B58() == 0) {
V(s32,D_8029F9A4)=0;
func_8017797C();
break;
}
{ f32 *pB0=&D_8029F9B0; f32 *p310=&D_80290310;
f32 f9ac_;
f32 b4_;
f32 pcv_, f34v_;
f32 b0v_, v310_;
#define _95 _60
#define _86 _58
#define _102 f34v_
#define _48 _49
#define _53 _109
do { do { b0v_=*pB0; v310_=*p310;
_131=b0v_ - v310_; } while (0); } while (0);
f34v_=D_80107F34;

if (!(_131 < f34v_)) goto out31_; {
_86=((volatile VolF32_8016A058 *)((u8 *)&PC - 4))->v_; do { f9ac_=((volatile VolF32_8016A058 *)((u8 *)&D_8029F9AC - 4))->v_;
a[1]=v310_ - b0v_; _95=D_80290314; _103=_86 - f9ac_;
b4_=D_8029F9B4; _48=_95 - b4_;
#undef _53
#define _53 a[1]
a[0]=_103; a[2]=_48;
if (!(((_103 * _103) + (_48 * _48)) < D_80107F38)) goto out31_; } while (0); {


_67=(f34v_ - _131) / D_80107F3C;
a[1]=_53 * _67;
a[0]=_103 * _67;
a[1]=2.0f * a[1];
a[2]=_48 * _67;
{ f32 t_;
t_=f9ac_ + a[0];
D_8029F9AC = t_; }
*pB0 += a[1];
{ f32 pd_=_86 - a[0];
D_8029F9B4 = b4_ + a[2];
F(f32,&PD,0x34)=pd_; }
D_80290314=_95 - a[2];
#undef _95
#undef _86
#undef _102
#undef _48
#undef _53
#undef _53
a[1]=0.0f;
*p310 -= a[1];
if (F(f32,D_802900E0,316) <= D_80107F40) {
{ s16 *p40_=&D_8028FB40; *p40_=2; }
D_8028FB3C=a[1];
}
_109=V(f32,PC) - D_8029F9AC;
_105=*p310 - *pB0;
_19=D_80290314 - D_8029F9B4;
_49=(_109 * _109) + (_105 * _105) + (_19 * _19);
a[0]=_109;
a[1]=_105;
a[2]=_19;
_131=sqrtf(_49);
if (_131 < D_8029F9EC) {
_91=_131 / D_8029F9EC;
D_8029F9D0 *= _91;
D_8029F9D4 *= _91;
D_8029F9D8 *= _91;
}
}
} out31_: ;
}
}
break;
case 32:
if (D_802901E4 != 0xF) {
V(f32,P3)=V(f32,P3) * D_80107F48;
D_80290334=D_80290334 * D_80107F48;
D_80290338=D_80290338 * D_80107F48;
}
if ((AC(s16,6) == 2) && (FB < 0x1E)) {
V(f32,D_80290334)=0.0f;
}
switch (D_802901E4) {
case -1:
case 7:
case 8:
case 9:
case 10:
case 11:
case 12:
case 13:
case 14:
if (FB == 8) {
func_80178134(0xB0, &PC, 0x64, 0x80);
_207=((u8 *)&PC - 0x34);
_1=0;
goto block_516;
}
break;
case 0:
case 1:
case 2:
if (FB == 0xA) {
func_80178134(0xB0, &PC, 0x64, 0x80);
_207=((u8 *)&PC - 0x34);
_1=2;
goto block_516;
}
break;
case 3:
case 4:
case 5:
case 6:
if (func_801A2944(D_80107F90, &PD) != 0) {
func_80178134(0xB0, ((u8 *)&PD + 0x34), 0x64, 0x80);
_207=&PD;
_1=1;
block_516:
func_801A9054(_207, _1, 1);
D_80290360=V(f32,D_80290354);
}
break;
}
break;
case 33:
{ s32 *p16c=(s32 *)&D_8029016C; s16 *h16_; f32 e4_=V(f32,D_802900E4); { f64 d_=e4_; e4_=d_; } _69=(e4_ * D_80107F94) + D_80107F94; _256=0xDC; if (_69 < D_80107F98) {
#define E4X_ e4_



_256=_69;
}
_70=(E4X_ * D_80107F9C) - D_80107FA0;
#undef E4X_
*p16c=_256;
h16_=(s16 *)(p16c + 3);
*h16_=((_70 < D_80107FA4) || (_70 < D_80107F9C)) ? ((_70 < D_80107FA4) ? 10 : (s16)_70) : 200; }
_106=V(f32,D_802900E4) * D_80107FA8;
_228=D_80202218 * 0x190;
V(f32,D_802900E4)=_106;
if ((F(u8,&D_801FAAAA,_228) != 0) && (D_801EC740 == 1)) {
_148=D_801ED680;
_158=_148 * D_80107FB8;
_174=_106 + (_148 * D_80107FB0);
if (_158 < _174) {
_174=_158;
}
V(f32,D_802900E4)=_174;
}
_165=D_801ED680 * D_80107FC0;
_137=V(f32,D_802900E4);
if (_137 < _165) {
_137=_165;
}
V(f32,D_802900E4)=_137;
if (D_801EC740 == 1) {
if (F(u8,&D_801FAAAB,IDX) != 0) {
_166=F(f32,&D_801FAA94,IDX) / D_80107FC8;
if (_166 < F(f64,&D_80107FC8,4)) {
_126=_166 + F(f64,&D_80107FD0,4);
} else {
_126=D_80107FDC;
}
D_8029035C=func_801496C8(_126);
P3=P3 * D_80107FE0;
D_80290338=D_80290338 * D_80107FE0;
A8(f32,12)=D_80107FE8;
D_80290300 &= ~1;
D_80290334=D_80290334 * F(f64,&D_80107FF8,4);
V(f32,D_802900E4)=(V(f32,D_802900E4) * F(f64,&D_80107FE8,4)) + (D_801ED680 * F(f64,&D_80107FE8,4) * F(f64,&D_80107FF0,4));
} else {
_167=F(f32,&D_801FAA94,IDX) / D_80108004;
if (_167 < D_80108008) {
_127=_167 + D_80108010;
} else {
_127=D_80108018;
}
D_8029035C=func_801496C8(_127);
D_80290300 |= 1;
if (F(u8,&D_801FAAB9,IDX) == 0) {
D_80290334=D_80290334 + (V(f32,D_802900E4) * (F(f64,&D_80108028,4) - (func_801496C8(V(f32,D_80290350) - F(f64,&D_80108018,4)) / F(f64,&D_80108020,4))));
}
}
} else {
D_8029035C=D_80108034;
}
if ((D_8029F47E == 0) && (V(s32,D_8029F9A4) == 0) && (V(s32,D_8029F9A0) & 0x40000000)) {
V(s32,D_8029F9A4)=&PD;
V(u8,D_8028FBFB)=0;
V(s16,D_802900DC)=D_801EF45C - 1;
}
_219=V(s32,D_8029F9A4);
if ((_219 == &PD) && (D_8029F47E == 0)) {
func_801B2A1C();
_71=A8(f32,0);
_71=F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,0) * D_80108038 / D_8010803C; { f32 s_ = A8(f32,0) + _71; _71 = s_; }
_134=D_801ED680 * D_80108040 * (A8(f32,0) / _71);

A8(f32,12)=_134;
_71=A8(f32,0);
_130=-D_801ED680 * D_80108048 * ((_71 + (F(f32,((ObjPtrBlk *)&D_8029FA44)->unk4,0) / D_80108044)) / _71);
a[0]=0.0f;
a[2]=0.0f;
if (FA(u8,394) != 0) {
D_8029F9A0 |= 1;
do { *(Words3 *)&D_8029F9D0=*(Words3 *)&P3; } while (0);
a[1]=FA(f32,112) + D_8010804C;
_130=-D_801ED680;
func_8014915C(a, a, func_801496C8(V(f32,D_80290350) - D_80108050), 0);
func_801490AC(a, a, V(f32,D_80290354));
_146=(f32)V(s16,D_802900DC);
{ f32 den_=D_801EF45C; _146 /= den_; }
{ f32 z_=V(f32,D_8029F9B4); _138=a[2];
_145=V(f32,D_8029F9AC); _145 += a[0];
_143=V(f32,D_8029F9B0); _143 += a[1];
_208=_219 + 0x34;
z_ += _138;
b[0]=_145; b[2]=z_; } b[1]=_143;
func_80149398(_208, _208, _146, b, D_80108064 - _146);
} else {
D_8029F9A0 &= ~1;
do { *(Words3 *)&D_8029F9D0=*(Words3 *)&P3; } while (0);
a[1]=-(FA(f32,112) + D_80108058);
func_8014915C(a, a, func_801496C8(V(f32,D_80290350) - F(f64,&D_80108058,4)), 0);
func_801490AC(a, a, V(f32,D_80290354));
_146=(f32)V(s16,D_802900DC);
_146 /= D_801EF45C; { f64 d_=_146; _146=d_; }
{ f32 z_=D_80290314; _138=a[2];
_145=PCX; _145 += a[0]; { f64 d_=_145; _145=d_; }
_143=D_80290310; _143 += a[1]; { f64 d_=_143; _143=d_; }
_208=((u8 *)&D_8029F9A4 + 8);
z_ += _138;
b[0]=_145;
b[2]=z_; }
b[1]=_143;
func_80149398(_208, _208, _146, b, D_80108064 - _146);
}
if ((F(u8,&D_801FAAAC,IDX) != 0) && (FA(u8,394) == 0)) {
D_8029F47E=6;
D_8028FAC8=&PC;
D_8028FAD0=((u8 *)&PC + 0x24);
V(s32,D_8029F9A0) |= 1;
}
} else {
_134=D_801ED680 * D_80108068;
_130=-D_801ED680 * D_8010806C;
}
if (V(f32,D_80290334) < _130) {
V(f32,D_80290334)=_130;
} else if (_134 < V(f32,D_80290334)) {
V(f32,D_80290334)=_134;
}
break;
case 34:
for (_248=0; _248 < 4; _248++) {
_288=*(s32 *)(D_802903B0 + _248 * 4);
if (_288 == NULL) continue;
{
if (((PCX * F(f32,_288,0)) + (D_80290310 * F(f32,_288,4)) +
(D_80290314 * F(f32,_288,8)) + F(f32,_288,12)) *
((F(f32,&D_8029F9AC,0) * F(f32,_288,0)) +
(V(f32,D_8029F9B0) * F(f32,_288,4)) +
(V(f32,D_8029F9B4) * F(f32,_288,8)) + F(f32,_288,12)) < 0.0f) {
func_8017797C();
if (F(s32,&D_8029F9AC,-8) == (s32)((u8 *)&PC - 0x34)) {
F(s32,&D_8029F9AC,-8)=0;
}
break;
}
}
}
if (AC(s16,4) == 0x22) {
func_80160228(&PD, 1);
_153=D_80108070;
B0(f32,116)=FA(f32,116) + _153;
func_8015F910(&D_80290200, a, &D_801ED3C4, NULL, NULL, NULL, 0, 0x20, *(volatile s32 *)&D_80290094, *(volatile s32 *)&D_80290094);
if (B4(s32,4) != 0) {
*(Words3 *)&D_8029F9AC=*(Words3 *)&D_80290200;
F(f32,&D_8029F9AC,4)=F(f32,&D_8029F9AC,4) + (F(f32,&D_8029F9AC,-4) - ((D_80290394 * D_80108078) / _153));
func_80167604(3);
} else {
a[0]=D_802901F0 - F(f32,&D_80290200,0);
a[1]=D_802901F4 - D_80290204;
a[2]=D_802901F8 - D_80290208;
_289=B4(s32,72);
_179=F(s16,_289,96);
if ((_179 + ((F(s16,_289,98) - _179) / 2)) < B4(f32,76)) {
_200=((u8 *)&PD + 0x34);
func_80148D0C(_200, a, -0.15f);
_108=(V(f32,D_8029F9B0) + D_80290310) / D_80108080;
_159=D_8029F9A8;
D_80290310=_108; if (F(f64,&D_80108080,4) < _159) {

D_80290310=_108 + (_159 - F(f64,&D_80108080,4));
}
func_80149318(((u8 *)&D_8029F9B0 - 4), _200);
} else {
func_80148D0C(((u8 *)&PD + 0x34), a, F(f64,&D_80108088,4) / FB);
}
D_8028FBC4=D_80290310;
}
}
break;
case 35:
if (((s32 (*)(s32))func_8016536C)(0x19) != 0) {
func_80167604(0x19);
} else if (D_80290108 != 1) {
if (FB == 4) {
((void (*)(void *, f32))func_80133B90)(&PD, 0.0f);
}
_50=(V(f32,P3) * V(f32,P3)) + (D_80290338 * D_80290338);
_114=sqrtf(_50);
_154=F(f64,&D_80108090,4);
if (_154 < _114) {
_15=B0(s32,0);
if ((_15 != NULL) && (B0(u8,392) == 0)) {
_22=func_801496C8(func_80147460(F(f32,_15,0), F(f32,_15,8))); D_80290360=_22; if ((D_8029034C != 0.0f) && (D_8029034C < D_8010809C) && (func_8014944C(V(f32,D_80290354), _22) < _154)) {


_149=D_8029034C;
_171=(_149 + D_801080A0) / _149;
V(f32,P3)=V(f32,P3) * _171;
D_80290334=D_80290334 * _171;
D_80290338=D_80290338 * _171;
}
} else {
D_80290360=func_801496C8(func_80147460(V(f32,P3), D_80290338));
}
_5=B0(s32,0);
if (_5 != NULL) {
((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(a, (f32 *)&PC, (f32 *)_5, (f32)-D_80290308 * D_801080A8);
a[0] += func_80147000(7) - 3;
_92=a[2] + (func_80147000(7) - 3);
b[1]=D_801080B8;
a[2]=_92;
b[0]=V(f32,P3) / D_801080B0;
b[2]=D_80290338 / D_801080B0;
func_801B66D4(0, a, b, 0, 0);
}
}
}
break;
case 36:
*(Words3 *)(D_80290304 + 132)=*(Words3 *)&D_8029035C;
func_80160228(D_80290304, 1);
{ u32 i_=D_80202218;
*(s16 *)((u8 *)&D_80299960 + (F(s8,F(s32,D_80290304,212),2) * 0x300))=0xA;
do {} while (0);
if ((F(u8,&D_801FAAAA,i_ * 400) == 0) && (D_801EC740 == 1)) {
V(u8,D_8028FBFA)=0;
} }
if (0) {
V(u8,D_8028FBFA)=0;
}
func_80175EC0();
if ((F(u8,&D_801FAAAA,IDX) != 0) && (D_801EC740 == 1) && (F(u8,F(s32,D_80290304,216),392) != 0)) {
if (V(s16,D_8028FBDA) == 0) {
if (FB >= 6) {
if (V(u8,D_8028FBFA) == 0) {
u8 **p304_=(u8 **)&D_80290304;
func_80133998(*p304_, 0xA, 0, 0, 0.0f);
func_80133998(*p304_, 7, 0, 1, 0.0f);
V(s16,D_8028FBDA)=5;
} else {
u8 **p304_=(u8 **)&D_80290304;
V(s16,D_8028FBDA)=1;
func_80133998(*p304_, 7, 0, 0, 0.0f);
func_80178134(0x13, ((u8 *)p304_ + 8), 0x64, 0x80);
}
}
goto block_611;
}
goto block_612;
}
block_611:
if (V(s16,D_8028FBDA) != 0) {
block_612:
_181=V(u16,D_8028FBDA) - 1;
V(s16,D_8028FBDA)=_181;
if ((_181 << 0x10) == 0) {
func_80178134(0x13, &PC, 0x64, 0x80);
if (V(u8,D_8028FBFA) < 0xF) {
V(u8,D_8028FBFA) += 4;
}
F(f32,((u8 **)&PD)[11],88)=F(f32,((u8 **)&PD)[11],92)=F(f32,((u8 **)&PD)[11],96)=0.0f;
F(f32,D_80290304,92)=V(u8,D_8028FBFA) + 8;
}
}
if ((F(u8,&D_801FAAC8,IDX) != 0) && (D_801EC740 == 1)) {
func_801764A8();
}
break;
case 44:
{ s16 *fb=(s16 *)&FB; typedef struct { s16 v_; } S16_;
if (((S16_ *)fb)->v_ <= D_801EEC04) {
{ u8 *o=D_8029020C;
F(f32,&D_8029F398,*fb * 0xC)=F(f32,o,60) - PCX;
F(f32,&D_8029F39C,*fb * 0xC)=F(f32,o,64) - D_80290310;
F(f32,&D_8029F3A0,*fb * 0xC)=F(f32,o,68) - D_80290314;
F(f32,&D_8029F3A4,*fb * 0xC)=F(f32,o,60) - PCX;
F(f32,&D_8029F3A8,*fb * 0xC)=F(f32,o,64) - D_80290310;
F(f32,&D_8029F3AC,*fb * 0xC)=F(f32,o,68) - D_80290314;
_196=*fb; }
} else if (D_8029020C != NULL) {
F(s32,D_8029020C,356)=0;
F(f32,D_8029020C,96)=F(f32,D_8029020C,100)=F(f32,D_8029020C,104)=0.0f;
_196=((2.0f * D_801EEC04) - ((S16_ *)fb)->v_) + D_801080BC;
if (_196 >= 0) {
{ u8 *tbl=(u8 *)&D_8029F398; _290=tbl + (_196 * 0xC); }
F(f32,D_8029020C,60)=F(f32,_290,0) + PCX;
F(f32,D_8029020C,64)=F(f32,_290,4) + D_80290310;
F(f32,D_8029020C,68)=F(f32,_290,8) + D_80290314;
*(Words3 *)(D_8029020C + 248)=*(Words3 *)(D_8029020C + 60);
}
}
_244=0;
if (_196 >= 0) {

{ typedef struct { f32 v_[3]; } V3_;
f32 z_=0.0f;
do {
if (_244 < _196) {
for (_115=z_, _237=0; _115 < D_801EEC00; _115=_237) {
_23=_115 / D_801EEC00;
func_80149398(a, &((V3_ *)&D_8029F398)[_244], _23, &((V3_ *)&D_8029F398)[_244 + 1], D_801080C0 - _23);
a[0] += PCX;
a[1] += D_80290310;
a[2] += D_80290314;
func_80177888(a);
_237 += 1;
}
} else {
a[0]=((V3_ *)&D_8029F398)[_244].v_[0] + PCX;
a[1]=((V3_ *)&D_8029F398)[_244].v_[1] + D_80290310;
a[2]=((V3_ *)&D_8029F398)[_244].v_[2] + D_80290314;
func_80177888(a);
}
_244 += 1;
} while (_196 >= _244);
}
}
if ((D_8029020C != NULL) && (F(s32,D_8029020C,0) != 0)) {
_245=0;
if (D_801F0198 > 0) {
u8 *pos_=D_8029971C, *p_;
_238=0;
loop_638:
if (D_802901FC == 0) {
_260=((s8 *)D_8029970A)[_238];
if ((_260 == 1) && (p_=(u8 *)(_238 + (s32)pos_), (*(f32 *)&D_80299718[_238]) <= D_801EEC14)) {
if (func_80148EBC(p_, D_8029020C + 0x3C) < ({
 _73=(*(f32 *)&D_80299718[_238]) + D_801080C4; _73 * _73; })) {
D_8029970A[_238]=0xA;
{ typedef struct { s32 f; } W_; ((W_ *)(D_80299964 + _238))->f |= 0x400; }
F(s32,D_8029020C,356)=0;
_74=FB;
if (_74 <= D_801EEC04) {
D_801EEC04=_74;
}
D_802901FC=_260;
}
}
}
_267=(u8 *)(_238 + (s32)pos_);
if (F(s32,D_80299964 + _238,0) & 0x400) {
_75=FB / (2.0f * D_801EEC04);
func_80149398(_267, D_8029020C + 0x3C, _75, _267, D_801080C8 - _75);
}
_245 += 1;
_238 += 0x300;
if (_245 < D_801F0198) goto loop_638;
}
{ u8 **h3a4_=(u8 **)&D_802993A4; f32 k80cc_; _211=*h3a4_;
if (_211 != ((u8 *)h3a4_ - 4)) {
k80cc_=D_801080CC;
#define _58 k80cc_
do {
_303=F(s32,_211,12);
if (_303 != (s32)(_211 + 8)) {
_202=_211 + 8;
loop_303:
if ((D_802901FC == 0) && (F(s8,_303,13) != 0)) {
if (F(u8,_303,15) != 0xA) {
if (func_80148EBC(_303 + 0x24, D_8029020C + 0x3C) < D_801080D0) {
F(u8,_303,15)=0xA;
_76=FB;
if (_76 <= D_801EEC04) {
D_801EEC04=_76;
}
D_802901FC=1;
}
goto block_656;
}
goto block_657;
}
block_656:
if (F(u8,_303,15) == 0xA) {
block_657:
_77=FB / (2.0f * D_801EEC04);
_282=_303 + 0x24;
func_80149398(_282, D_8029020C + 0x3C, _77, _282, _58 - _77);
_301=F(s32,_211,12);
F(f32,_211,192)=F(f32,_211,196)=F(f32,_211,200)=0.0f;
if (_301 != _202) {
do {
{ f32 d_; d_=F(f32,_211,192); d_ += F(f32,_301,36); F(f32,_211,192)=d_;
d_=F(f32,_211,196); d_ += F(f32,_301,40); F(f32,_211,196)=d_;
d_=F(f32,_211,200); d_ += F(f32,_301,44); F(f32,_211,200)=d_; }
_301=F(s32,_301,4);
} while (_301 != (_211 + 8));
}
#define _302 _301
_302=F(s32,_211,12);
F(f32,_211,192)=F(f32,_211,192) * (_58 / F(s32,_211,184));
F(f32,_211,196)=F(f32,_211,196) * (_58 / F(s32,_211,184));
F(f32,_211,200)=F(f32,_211,200) * (_58 / F(s32,_211,184));
if (_302 != _202) {
do {
_24=func_80148E48(_211 + 0xC0, _302 + 0x24);
if (F(f32,_211,204) < _24) {
F(f32,_211,204)=_24;
}
_302=F(s32,_302,4);
} while (_302 != (_211 + 8));
}
F(f32,_211,204)=F(f32,_211,204) + D_801080D4;
}
_303=F(s32,_303,4);
if (_303 != _202) goto loop_303;
}
_211=F(s32,_211,4);
} while (_211 != D_802993A0);
#undef _58
} }
if (D_802901FC == 0) {
_291=F(s32,D_8029020C,224);
if ((_291 != NULL) && (F(u8,_291,394) != 0)) {
F(s32,D_8029020C,356)=0;
F(f32,D_8029020C,96)=F(f32,D_8029020C,100)=F(f32,D_8029020C,104)=0.0f;
_78=FB;
if (_78 <= D_801EEC04) {
D_801EEC04=_78;
}
D_802901FC=1;
}
}
}
if (((2.0f * D_801EEC04) + D_801080D8) <= FB) {
_246=0;
if (D_801F0198 > 0) { void *pc_=&PC;
_155=F(f64,&D_801080D8,4);
_270=D_802996E8;
_239=0;
do {
if (F(s32,D_80299964 + _239,0) & 0x400) {
func_80195D50(_270);
((void (*)(void))func_8018DF4C)();
func_80178134(0x6F, pc_, 0x64, 0xA0);
D_80290394=D_80290394 * _155;
D_80290398=D_80290398 * _155;
D_8029039C=D_8029039C * _155;
}
_270 += 0x300;
_246 += 1;
_239 += 0x300;
} while (_246 < D_801F0198);
}
}
if (((2.0f * D_801EEC04) + D_801080E4) <= FB) {
_268=D_8029020C;
D_8029020C=NULL;
F(s16,_268,44)=1;
func_80167604(0x25);
}
}
break;
case 37:
if ((func_801A2944(D_801080E8, &PD) != 0) && (func_80147000(50) < 5)) {
func_80178134(0xDA, ((u8 *)&PD + 0x34), 0x64, 0x76);
}
if ((B0(u8,392) != 0) && (B0(u8,393) == 0)) {
F(f32,&P3,0)=F(f32,&P3,0) * F(f64,&D_801080E8,4);
D_80290338=D_80290338 * F(f64,&D_801080E8,4);
}
break;
case 38:
V(f32,D_80290348)=D_801080F4;
if (((B0(u8,392) != 0) || ((B4(s32,4) == 8) && (_14=B0(s32,0), (_14 != NULL)) && (F(f32,_14,4) > 0.0f))) && (B4(s16,16) == -1) && (B4(s16,2) == 7) && ((F(s16,B4(s32,72),84) + 5) < B4(f32,76))) {
func_80178134(0xDA, ((u8 *)&D_80290348 - 0x3C), 0x64, 0x76);
func_80133998(((u8 *)&D_80290348 - 0x70), 8, 0, 1, 0);
}
break;
case 39:
V(f32,D_80290348)=D_801080F8;
{ u8 *pfa_=&D_8028FBFA; if (*pfa_ != 0) {
*pfa_ += 1;
}
if (B0(u8,392) != 0) {
if (B0(u8,393) == 0) {
P3=P3 * F(f64,&D_801080F8,4);
D_80290338=D_80290338 * F(f64,&D_801080F8,4);
}
_12=((u8 *)&D_80290348 - 0x70);
if (func_801A2944(D_80108104, _12) != 0) {
func_80178134(0xDA, ((u8 *)&D_80290348 - 0x3C), 0x32, 0x76);
V(f32,D_80290334)=D_80108108;
func_80160610(_12, 4.0f, A8(f32,12));
*pfa_=1;
}
}
}
if (B4(s32,4) != 0) {
func_80133998(&PD, 0xF, 0, 0, -B4(f32,12));
}
break;
case 40:
{ s32 c8_;
_285=C8(s32,220);
c8_=C8(s32,200);
_292=(F(s16,_285,2) * 0xC) + F(s32,_285,72);
((void (*)(s32, s32, s16, s16, f32))func_80145298)(F(s32,F(s32,c8_,12),52), F(s32,_285,76), F(s16,_292,0), F(s16,_292,2), F(f32,_285,12)); }
a[0]=0.0f;
a[1]=D_8010810C;
_79=C8(f32,88);
_25=C8(f32,96);
_40=(_79 * _79) + (_25 * _25);
_144=sqrtf(_40);
a[2]=_144 - D_80108110;
func_801489F0(c, &D_80290374);
func_801499EC(&D_802900CC, a, c);
{ s32 ix_=D_802900D8; u8 *c8_=C8(u8 *,216); _293=(u8 *)(ix_ * 0x24 + (s32)c8_); }
*(Words3 *)&PC=*(Words3 *)(_293 + 88);
func_801499A0(a, &D_802900CC, ((ObjPtrBlk *)&D_802900C0)->unk8 + 0x9C);
*(f32 *)((u8 *)&D_80290310 - 4)=F(f32,&PD,0x34) + a[0];
D_80290310 += a[1];
D_80290314 += a[2];
C8(f32,136)=D_80290360;
_26=C8(f32,124);
V(f32,D_80290354)=_26;
D_80290360=_26;
_93=F(f32,&D_801FAA94,IDX) / D_80108114;
_80=D_801EF44C - D_801EF448;
if (_93 > 0.0f) {
if (_93 < _80) {
goto block_715;
}
goto block_718;
}
if (_80 > 0.0f) {
block_715:
_81=F(f32,&D_801FAA94,IDX) / D_80108118;
if (_81 > 0.0f) {
_139=D_801EF448 + _81;
} else {
_139=D_801EF448 + 0.0f;
}
} else {
block_718:
_139=(D_801EF44C - D_801EF448) + D_801EF448;
}
_283=C8(s32,220);
D_801EF444=_139;
if (((struct { s16 pad; s16 f; } *)_283)->f == 0xF) {
F(f32,_283,12)=F(f32,F(s32,_283,72),184) * _139;
C8(s32,40)=C8(s32,40) & 0xFEFFFFFF;
_294=C8(s32,208);
func_8016049C(D_802900C8, F(f32,_294,4), F(f32,_294,12) * _139);
C8(s32,40)=C8(s32,40) | 0x01000000;
} else {
G(&=,~8)
_65=D_8010811C;
_82=F(f32,C8(s32,220),76);
if ((_65 <= _82) && (_82 <= D_80108120)) {
a[0]=F(f32,C8(s32,216),124) - C8(f32,52);
a[1]=F(f32,C8(s32,216),128) - C8(f32,56);
a[2]=F(f32,C8(s32,216),132) - C8(f32,60);
func_80149568(a);
_59=D_80108124;
((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(b, (f32 *)(((ObjPtrBlk *)&D_802900C0)->unk8 + 0x34), a, _59);
((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(a, (f32 *)(C8(s32,216) + 0x7C), a, _59);
_284=C8(s32,220);
_217=F(s32,_284,72);
if (F(f32,_284,76) < (F(f32,((F(s16,_284,2) * 0xC) + _217),4) + _65)) {
if (D_801EEBD4 != 0) {
if (F(s32,D_801EEBD4,0) != 0) {
func_801BB064(D_801EEBD4);
}
} else {
D_801EEBD4=func_8013FCDC(0x578, 1, &D_80107B90);
}
func_801BAF8C(D_801EEBD4);
func_801BA644(D_801EEBD4, a, b, 0xFF, 0, 0x1E, 0x1E);
}
func_801BA700(D_801EEBD4, a, b);
}
_247=0;
if (D_801F0198 > 0) {
s32 one_ = 1;
_60=D_80108128;
do {
_240 = _247 * 0x300;
if ((((s8 *)D_8029970A)[_240] == one_) && ((D_802996E8 + _247 * 0x300) != D_802900C8) && (func_80148E48(D_802996E8 + _247 * 0x300 + 0x34, F(s32,D_802900C8,216) + 0x7C) <= ((*(f32 *)&D_80299718[_240]) + F(f32,F(s32,D_802900C8,216),148) + _60))) {
func_80195D50(D_802996E8 + _247 * 0x300);
}
_247 += 1;
} while (_247 < D_801F0198);
}
}
V(f32,D_801ED3EC)=V(f32,D_80290354);
func_80148C3C(c, ((u8 *)&D_801ED3EC - 0xC));
_10=((u8 *)&D_80290354 + 0x20);
func_801488C0(_10, c, _10);
if ((F(u8,D_801FAAC6,(D_80202218) * 400 + 0) != 0) && (F(u8,C8(s32,216),392) != 0)) {
{ u8 **pc8_=(u8 **)&D_802900C8; func_80133998(*pc8_, 0, 0, 0, 0.0f);
func_80133998(*pc8_, 0xF, 1, 1, F(f32,F(s32,C8(s32,220),72),184) * D_801EF444); }
}
if ((F(u8,&D_801FAAC8,IDX) != 0) && (D_801EC740 == 1)) {
func_801764A8();
}
break;
case 41:
func_8017753C();
_182=B4(s16,2);
if (((_182 == 0xD) | (_182 == 0x17)) != 0) {
V(f32,P3)=V(f32,D_80290334)=D_80290338=0.0f;
_295=(B4(s16,2) * 0xC) + B4(s32,72);
_193=F(s16,_295,0);
if (B4(f32,76) > (_193 + ((F(s16,_295,2) - _193) * F(f64,&D_80108128,4)))) {
func_80133998(((u8 *)&P3 - 0x58), 0x2A, 1, 1, 0.0f);
AC(s16,4)=0;
}
}
break;
case 42:
{ void *pc_;
_54=((volatile VolF32_8016A058 *)((u8 *)&D_80108134 - 4))->v_;
a[2]=0.0f;
a[0]=((volatile VolF32_8016A058 *)((u8 *)&D_80108138 - 4))->v_;
func_801490AC(a, a, D_8028F95C);
_248=0;
pc_=&PC;
for (_280=&D_80290140; _248 < 2; _248++, _280 += 1) {
_281=*_280;
if (_281 == NULL) continue;
func_80149374(_281 + 0xC, pc_, a);
F(f32,(*_280),16)=D_80290310 + _54;
}
_248=0;
if ((u32)(B4(u16,2) - 0x30) < 2) {
for (; _248 < 2; _248++) {
_286=((void **)&D_80290140)[_248];
if (_286 == NULL) continue;
{ s32 d_; s32 e_=(1 - _248) * 0x28; d_=F(s16,_286,24) - 0x30; e_ -= d_;
_264=F(u16,_286,46) + e_ / 2; }
F(s16,_286,46)=_264;
F(s16,_286,44)=_264;
F(s16,_286,26)=_264;
F(s16,_286,24)=_264;
}
if ((D_8029013C == 0) && (D_8029F468 != 0)) {
u8 *q2_;
_55=D_8010813C;
_287=D_80290144;
_66=D_80108140;
q2_=D_80290144;
if ((F(s16,D_80290144,24) + (func_80149724(_55, D_802004E0, NULL) * _66)) < 0.0f) {
_257=0;
} else {
_257=F(s16,D_80290144,24) + (func_80149724(_55, D_802004E0, NULL) * _66);
}
F(s16,q2_,24)=_257;
F(s16,_287,26)=_257;
}
if (func_801A2944(D_80108144, &PD) != 0) {
func_80178134(0xB2 - D_8029013C, ((u8 *)&PD + 0x34), 0x64, 0x80);
}
_183=AC(s16,6);
if (((_183 == 2) | (_183 == 0x20)) != 0) {
D_80290334=D_80290334 * D_80108148;
}
if ((D_8029013C != 0) || (F(u8,&D_801FAAAB,IDX) != 0) || (V(s8,D_8029F486) == 2)) {
if (D_8029013C == 1) {
if (F(u8,&D_801FAAAF,IDX) == 0) {
goto block_773;
}
goto block_775;
}
goto block_796;
}
block_773:
if (B4(s16,2) == 0x31) {
SF(s32,((ObjPtrBlk *)&D_802903A4)->unk10,8)=0;
func_80133998(&PD, 0x32, 0, 1, D_80108150);
func_80133998(&PD, 0x2A, 1, 1, 0.0f);
}
block_775:
if (D_8029013C == 1) {
#define _135 _131
#define _137 _60
{ u8 **h3a4_=(u8 **)&D_802993A4; _210=*h3a4_;
_135=D_80108154;
if (_210 != ((u8 *)h3a4_ - 4)) {
do {
_304=F(s32,_210,12);
if (_304 != (_210 + 8)) {
do {
if ((F(s8,_304,13) != 0) && (F(u8,_304,14) != 2)) {
_137=func_80148E48(_304 + 0x24, &PC);
if (_137 < _135) {
*(Words3 *)a=*(Words3 *)(_304 + 36);
_135=_137;
}
}
{ f64 d_=_137; _137=d_; }
_304=F(s32,_304,4);
} while (_304 != (_210 + 8));
}
_210=F(s32,_210,4);
} while (_210 != ((u8 *)&D_802993A4 - 4));
} }
_242=0;
if (D_801F0198 > 0) {
_269=D_8029971C;
_250=0;
do {
_225=F(s32,D_80299964 + _250,0);
if (_225 & 0x40) if (!(_225 & 0x80)) {
_137=func_80148E48(_269, &PC);
if (_137 < _135) {
*(Words3 *)a=*(Words3 *)_269;
_135=_137;
}
}
{ f64 d_=_137; _137=d_; }
_269 += 0x300;
_242 += 1;
_250 += 0x300;
} while (_242 < D_801F0198);
}
#undef _137
if (_135 < D_80108158) {
a[0] -= PCX;
a[1] -= D_80290310;
a[2] -= D_80290314;
} else {
a[0]=func_80147000(20000) - 0x2710;
a[1]=func_80147000(20000) - 0x2710;
a[2]=func_80147000(20000) - 0x2710;
}
goto block_859;
}
block_796:
if (D_801EFCFC < 2) {
a[0]=V(f32,D_8029F9AC) - PCX;
a[1]=V(f32,D_8029F9B0) - D_80290310;
a[2]=V(f32,D_8029F9B4) - D_80290314;
if (!(D_80297BEC & 0x80) && (F(u8,&D_801FAACB,IDX) != 0) && (V(f32, D_8029F5C4) <= F(f64,&D_80108158,4)) && ((_46c=(u8 *)D_8029F46C, _46c == 0) || (_184=F(s16,_46c,32), (((_184 == 0x1C) | (_184 == 0x1E)) != 0)))) {
_176=&D_801F1A98[D_8029F487];
D_802901E4=*_176;
D_802901E8=*_176;
D_8029012E=-1;
func_80167604(0x20);
break;
}
if (0) {
found_806:
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
} else {
_2=D_802904D4.next;
{ s32 type; s32 wu;
#define W0 (*(const s8 *)w)
#define w ((s8 *)&D_801E7531)
#define q7 (w + 7)
#define q9 (w + 9)
for (; _2 != &D_802904D4; _2=_2->next) {
if ((D_801EFD00 == 8) && (F(s32,_2,24) == 0xC)) goto found_806;
type=F(volatile s32,_2,24);
if (D_801EFD00 == type + 0x24) goto found_806;
if (W0 == 8) {
if (type == 0) continue;
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
} else if (W0 == 0x2A) {
s32 bits, sh, ix_;
if ((u32)(D_801EFD00 - 1) < 6) {
if (type == 0xD) goto found_806;
}
ix_=*(s16 *)&D_801EAB24 << 3; sh=*(s8 *)&D_801E7533; ix_ -= *(s16 *)&D_801EAB24; ix_ <<= 2; bits=*(s32 *)(ix_ + (s32)D_801EAA48);
sh=(sh - 1) * 5;
if (!((bits >> sh) & 1)) {
if (type == 0x10) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
} else if (!((bits >> (sh + 1)) & 1)) {
if (type == 0x11) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
} else if (!((bits >> (sh + 2)) & 1)) {
if (type == 0x12) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
} else if (!((bits >> (sh + 3)) & 1)) {
if (type == 0x13) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
} else if (type == 0x14) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
} else {
if ((type == 6) && (W0 == 1)) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
continue;
}
#define TYPEV ((ObjectNode *)_2)->unk018
wu=*(u8 *)w;
if ((u32)(wu - 2) < 2) {
if ((TYPEV == 8) && ((w[6] != 0) || ((w[7] == 0) && !(((s16)*(u16 *)&FB % 60) < 0x1E)))) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
break;
}
if (TYPEV != 7) continue;
if (q7[0] != 0) goto stop_806;
if (q7[-1] != 0) continue;
if (!(((s16)*(u16 *)&FB % 60) < 0x1E)) continue;
{
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
break;
}
} else if ((u32)(wu - 4) < 2) {
if ((TYPEV == 0xA) && ((w[8] != 0) || ((w[9] == 0) && !(((s16)*(u16 *)&FB % 60) < 0x1E)))) {
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
break;
}
if (TYPEV != 9) continue;
if (q9[0] != 0) goto stop_806;
if (q9[-1] != 0) continue;
if (!(((s16)*(u16 *)&FB % 60) < 0x1E)) continue;
stop_806:
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
break;
} else {
if (TYPEV == 0xB) if ((s8)wu == 6) {
keep_806:
a[0]=F(f32,_2,180) - PCX;
a[1]=F(f32,_2,184) - D_80290310;
a[2]=F(f32,_2,188) - D_80290314;
}
}
}
}
}
}
#undef w
#undef q7
#undef q9
block_859:
_41=(a[0] * a[0]) + (a[2] * a[2]);
_116=sqrtf(_41);
if (B4(s16,2) == 0x31) {
if (((D_8029013C == 1) && (F(u8,&D_801FAAAF,IDX) != 0)) || (((F(u8,&D_801FAAAB,IDX) != 0) || (V(s8,D_8029F486) == 2)) && (D_8029013C == 0))) {
_42=(a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]);
_140=sqrtf(_42);
_100=D_80108164 / _140;
B4(f32,12)=((_100 < D_80108168) || (_100 < D_80108170)) ? ((_100 < D_80108168) ? D_80108178 : _100) : D_8010817C;
} else {
_83=B4(f32,12);
_117=F(f32,B4(s32,72),592);
if (_117 < _83) {
_117=_83;
}
B4(f32,12)=_117;
}
}
if (_116 != 0.0f) {
_29=func_80147460(a[0] / _116, a[2] / _116);
D_80290360=_29;
V(f32,D_80290354)=_29;
b[1]=_29;
_30=-func_80147460(a[1], _116);
b[2]=0.0f;
b[0]=_30;
func_8015C350(q, b);
} else {
c[1]=0.0f;
c[2]=0.0f; c[0]=D_80108180; if (a[1] > 0.0f) {


c[3]=D_80108184;
} else {
c[3]=D_80108188;
}
func_80148C3C(q, c);
goto block_892;
}
goto block_892;
} else {
_278=&D_80290140;
do {
_300=*_278;
_249 += 1;
if (_300 != NULL) {
_266=F(u16,_300,46) >> 1;
F(s16,_300,46)=_266;
F(s16,_300,44)=_266;
F(s16,_300,26)=_266;
F(s16,_300,24)=_266;
}
_278 += 1;
} while (_249 < 2);
{ u8 *b_=(u8 *)&D_801ED3EC; _16=b_ - 0xC; *(f32 *)b_=V(f32,D_80290354); }
func_80148C3C(q, _16);
block_892:
func_80147B10(&D_80290374, q, 0.15f, &D_80290374);
if (B4(s32,4) == 0x33) {
func_8017797C();
}
}
}
break;
case 43:
if (((D_801E7460 == 0) && (B4(s16,2) == 0x40) && (D_8029F5C8 >= -0xF) && (F(u8,&D_801FAACB,IDX) != 0)) || ((D_8029F5C8 == 0) && (F(u8,&D_801FAAAF,IDX) != 0))) {
func_801B3CA8();
FB=0;
}
if (B4(s32,8) != 0) {
_186=B4(s16,2);
if ((((_186 == 0x40) | (_186 == 0xE)) != 0) && ((FB >= 0x3F) || ((_223=D_80202218 * 0x190, (F(f32,&D_801FAA94,_223) != 0.0f)) && (F(u8,&D_801FAAAF,_223) == 0) && (D_8029F5C8 >= -0x11)) || ((D_801E7460 != 0) && (FB >= 0x1A)))) {
    ((ObjectNode *)((ObjPtrBlk *)&D_802903A4)->unk10)->unk008=0;
    if (D_801E7460 != 0) {
        _231=3; _236=1;
        func_80133998(&PD, _231, 0, _236, F(f32, &D_80108190, -4));
    } else {
        _231=0x10;
        if (B4(s16,2) == 0x40) {
            _231=0x41; _236=0;
            func_80133998(&PD, _231, 0, _236, 0);
        } else {
            _236=0;
            func_80133998(&PD, _231, 0, _236, D_80108190);
        }
    }
}
}
if ((B4(s16,2) == 0x41) && (D_801E7460 == 0)) {
    func_80175388(D_802903B0 + 0x74, FA(f32,116) + F(f64,&D_80108190,4));
}
_227=B4(s32,4);
if ((_227 == 0x42) || ((_227 == 0x11) && (B4(s16,2) != 0xE))) {
    AC(s16,4)=3;
    FB=0;
}
if (func_801A2944(D_8010819C, &PD) != 0) {
    func_80178134(0x94, ((u8 *)&PD + 0x34), 0x78, func_80147000(56) + 0x64);
}
if (func_801A2944(D_801081A0, &PD) != 0) {
func_80178134(0x95, ((u8 *)&PD + 0x34), 0x78, func_80147000(56) + 0x64);
}
if ((B4(s16,2) == 0x41) && (F(f32,&D_801FAA94,IDX) > D_801081A4)) {
AC(s16,4)=3;
FB=0;
}
break;
}
if (V(s16,D_8028FBEE) == 2) {
*(Words3 *)a=*(Words3 *)&PC;
{ s32 k_=func_80147000(30);
_56=D_801081A8;
_131=k_ - 0xF; _131 /= _56; a[0] += _131;
_131=func_80147000(30) - 0xF; _131 /= _56; a[1] += _131;
_131=func_80147000(30) - 0xF; _131 /= _56; a[2] += _131; }
func_801B66D4(6, a, &D_801ED3C4, 0, 0);
_263=(u16)D_802902FC - 1;
D_802902FC=_263;
if ((_263 << 0x10) == 0) {
V(s16,D_8028FBEE)=0;
}
}
{ s32 *p468_=&D_8029F468;
if (*p468_ == 0) {
if (D_8029F480 >= 0x13) {
_274=FA(u8,394);
if (((_274 != 0) & (_274 != 8)) && (D_8029F9E0 < F(f64,&D_801081A8,4))) {
*p468_=0x1E;
D_8029F486=2;
func_801785E0(&D_8029014C, 0x114, 0x64, &PC, 0x8C);
}
}
if (D_8029F480 >= 0x29) {
D_8029F468=0x1E;
D_8029F486=2;
func_801785E0(&D_8029014C, 0x114, 0x64, &PC, 0x8C);
}
}
}
if ((B0(u8,392) == 1) && (D_8028FBF0 == 0) && (func_8015C4C8() == 0) && (D_8029011E == 0)) {
{ _6=(f32 *)&D_80290340;
if (*_6 < F(f64,&D_801081B0,4)) {
_6=(f32 *)((u8 *)_6 - 0x68);
if (V(f32,D_80290334) == F(f64,&D_801081B8,4)) {
func_80133998(_6, 0x50, 0, 0, 0.0f);
func_80133998(_6, 0x2A, 1, 1, 0.0f);
D_8028FBD8=0x438;
}
*(Words3 *)a=*(Words3 *)&PC;
a[1] -= D_801081C4;
if (!(D_80290134 & 1)) {
func_801B7344(a, 4, 0.0f);
}
}
}
_84=-D_80290340 * D_801081C8;
_195=((_84 < 0.0f) || (_84 < D_801081CC)) ? ((_84 < 0.0f) ? 0 : (s16)_84) : 0x80;
func_80178134(0x9A, &PC, _195, 0x80);
}
if ((FA(u8,392) == 1) && (D_8029F484 == 0)) {
_296=FA(s32,0);
if ((_296 != NULL) && (F(u8,_296,116) != 5)) {
*(Words3 *)a=*(Words3 *)&D_8029F9AC;
a[1]=a[1] - (FA(f32,112) * D_801081D0); if (D_8029F9E0 < D_801081D8) {
func_801B66D4(0, a, &D_801ED3C4, 0, 0);
}
}
}
}
#undef F
#undef V
#undef PCX
#undef IDX
#undef G
#undef PD
#undef P3
#undef PC
#undef FB
#undef B4
#undef B0
#undef AC
#undef FA
#undef C8
#undef A8
#undef SF
#undef MIN
#undef MAX
#undef _252
#undef _259
#undef _133
#undef _35
#undef _242
#undef _244
#undef _245
#undef _246
#undef _247
#undef _248
#undef _249
#undef _304
#undef _210
#undef n_avail_
#undef b9d0_
#undef _94x
#undef _95
#undef _86
#undef _102
#undef _48
#undef _53
#undef E4X_
#undef _302
#undef _135
#undef _137
#undef W0
#undef TYPEV

#undef D_8029FA48
#undef D_8029FA4C
#undef D_802903B0
#undef D_80290310
#undef D_80290314
#undef D_802900C8
#undef D_802903AC
#undef D_802903B0

void func_80171924(void) { /* player_update: per-frame update of the player (Glover). Banks into turns, applies fall damage and death, services the tracked sounds, gravity, scale and blink timers, runs the action state machine and its sub-updates, aligns the body to the surface (wall cling, slope slide), then sets next frame's drag and friction. */
#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define DB(x) (*(f64 *)((u8 *)&(x) + 4))
typedef struct { s32 w[4]; } QuatWords;
typedef struct { u8 *v; } PointerBox;
typedef s32 (*StateConditionFn)(s32);
extern f32 D_801081D8;
extern s32 D_801081E0;
extern f32 D_801081EC;
extern f64 D_801081F0;
extern f64 D_801081F8;
extern f32 D_80108200;
extern f32 D_80108204;
extern f32 D_80108208;
extern f32 D_8010820C;
extern f32 D_80108210;
extern f32 D_80108214;
extern f64 D_80108218;
extern f64 D_80108220;
extern f64 D_80108228;
extern s32 D_80108230;
extern s32 D_80108238;
extern s32 D_80108240;
extern f32 D_8010824C;
extern s32 D_80108250;
extern s32 D_80108258;
extern f32 D_80108264;
extern s32 D_80108268;
extern s32 D_80108270;
extern f32 D_8010827C;
extern f64 D_80108280;
extern f64 D_80108288;
extern s32 D_80108290;
extern s32 D_80108298;
extern f32 D_801082A4;
extern s32 D_801082A8;
extern f32 D_801082B4;
extern s32 D_801082B8;
extern f32 D_801082C4;
extern s32 D_801082C8;
extern f32 D_801082D4;
extern f32 D_801082D8;
extern f32 D_801082DC;
extern f64 D_801082E0;
extern s32 D_801EEBD8;
extern f32 D_801EEBE8;
extern f32 D_801EEC14;
extern s32 D_801EEC44;
extern u8 D_801FAA94[];
extern u8 D_801FAAAA[];
extern u8 D_801FAAAB[];
extern u8 D_801FAAAC[];
extern s32 D_801FAAAE;
extern u8 D_801FAAAF[];
extern u8 D_801FAAC8[];
extern s32 D_801FAAF2;
extern s32 D_801FAB78;
extern u8 D_80202218;
extern s16 D_8028FB90;
extern s16 D_8028FBE8;
extern s8 D_8028FBEC;
extern s8 D_8028FBED;
extern s32 D_8028FBF0;
extern s16 D_8028FBF6;
extern s16 D_8028FC00;
extern s32 D_8028FC04;
extern f32 D_80290080;
extern f32 D_80290084;
extern f32 D_80290088;
extern u8 *volatile D_80290090;
extern u8 *D_80290094;
extern s32 D_802900BC;
extern s32 D_802900C0;
extern s32 D_802900C4;
extern s16 D_802900DA;
extern u8 *D_802900E0;
extern s32 D_802900EC;
extern s16 D_802900F4;
extern s32 D_80290104;
extern s16 D_8029011C;
extern s32 D_80290134;
extern s32 D_80290138;
extern s32 D_80290140[];
extern s16 D_8029014A;
extern s32 D_802901A8;
extern s32 D_802901A0, D_802901A4, D_802901AC, D_802901B0, D_802901D0, D_802901D4;
extern u8 *D_80290304;
extern f32 D_80290330;
extern f32 D_80290334;
extern f32 D_80290338;
extern f32 D_80290340;
extern f32 D_8029034C;
extern f32 D_8029035C;
extern f32 D_80290360;
extern f32 D_80290364;
extern f32 D_80290370;
extern u8 D_80290374;
extern u8 *D_802903A8;
extern u8 *D_802903B4;
extern s16 D_8029F480;
extern s8 D_8029F484;
void func_801735E8(void);
void func_80174058(s16);
void func_801743A8();
void func_80160228();
void func_8017479C(void);
void func_801748D0(void);
void func_80174D4C(void);
void func_8017574C(f32 *arg0);
void func_80176758(void);
s32 func_80176C3C(void);
void func_80176E9C(void);
void func_8017797C(void);
void func_80178760(void *);
void func_801AE204(s16);
extern void func_801B13CC(void);
void func_801B33A0(u8 *, u8 **, s32 *);
f32 surfaceQuat[3];
f32 platformSpinQuat[3];
f32 forward[3];
void *contactNormal;
s32 slot;
f32 turnDelta;
f32 dirLengthSq;
f32 animTime;
f32 wallDot;
f32 normalY;
f32 absTurnDelta;
f32 alignFraction;
f32 lowestDot;
f32 dirLength;
f64 clingBlend;
s16 *powerupTimers;
s16 stateNow;
s16 alignState;
s16 surfaceState;
s16 pitchState;
s16 timer;
s16 timerLeft;
s16 contactState;
s16 attachFramesLeft;
s16 deathFramesLeft;
s16 fallState;
s16 fallFrames;
s32 *playerQuat;
u8 *fallBody;
s32 sprite;
s32 blinkLeft;
s32 yawStep;
s32 hitCount;
s32 nextFace;
s32 padOffset;
s32 nextContact;
s32 unusedTemp;
s32 nextSprite;
s32 nextTimer;
s32 soundOffset;
s32 scaleFrame;
s32 idlePadOffset;
s32 touchesGround;
s32 nextState;
s32 unlock;
u8 contactFlags;
u8 deathContactFlags;
void **dirVec;
void *face;
void *platform;
void *platformRotation;
void *rotationAgain;
void *supportPlatform;
void *supportRotation;
void *wallFace;
void *groundPlane;
void *groundFace;
void *effect;
void *touchedFace;
f32 *playerUnk98;
s32 yawSnapDivisions = PLAYER_UPDATE_YAW_SNAP_DIVISIONS;
func_80176E9C();
if ((F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) == 1) && (*(f64 *)((u8 *)&D_801081D8 + 4) < D_8029034C)) { /* moving fast: bank (roll) into the turn */
turnDelta = func_801494CC(D_80290360, D_80290354) * D_801EEBE8;
absTurnDelta = turnDelta;
if (!(turnDelta > 0.0f)) {
absTurnDelta = -turnDelta;
}
if (*(f64 *)((u8 *)&D_801081E0 + 4) < absTurnDelta) {
D_80290364 = func_801496C8(turnDelta);
} else {
D_80290364 = 0.0f;
}
F(u8,D_802903A8,PLAYER_PHYS_ROLL_LOCK_OFFSET) = 1;
func_80160228(&D_802902D8, 2);
F(u8,D_802903A8,PLAYER_PHYS_ROLL_LOCK_OFFSET) = 0;
} else if (F(s16,F(s32,D_802900E0,84),2) < 0xB) {
playerUnk98 = &D_80290370;
D_80290364 = 0.0f;
*playerUnk98 /= D_801081EC;
F(u8,D_802903A8,PLAYER_PHYS_ROLL_LOCK_OFFSET) = 1;
func_80160228((u8 *)playerUnk98 - 0x98, 2);
F(u8,D_802903A8,PLAYER_PHYS_ROLL_LOCK_OFFSET) = 0;
}
if (((D_80290300 & PLAYER_UPDATE_FLAG_WALL_CLING) && (D_80290340 < D_801081F0)) || (D_80290340 < D_801081F8)) { /* landed hard after a long fall: damage */
contactFlags = F(u8,D_802903B0,PLAYER_COLLISION_CONTACT_FLAGS_OFFSET);
if ((contactFlags != 0) & (contactFlags != 8)) {
if (D_8028FC00 >= PLAYER_UPDATE_FALL_LETHAL_MIN_FRAMES) {
if (func_80176C3C() == 0) {
func_801743A8(2, -1);
}
} else if ((D_8028FC00 >= PLAYER_UPDATE_FALL_DAMAGE_MIN_FRAMES) && (func_80176C3C() == 0)) {
func_801743A8(2, 1);
}
}
}
if ((D_8028FC00 >= PLAYER_UPDATE_FALL_LETHAL_MIN_FRAMES) && ((F(f32,D_802903A4,0) == D_80108200) || ((D_80290304 != NULL) && (F(f32,F(s32,D_80290304,204),0) == D_80108200)))) {
func_80174058(2);
}
for (slot = 0; slot < PLAYER_UPDATE_SOUND_SLOT_COUNT; slot++) { /* tracked positional sounds; slot 0 holds the falling sound */
soundOffset = slot * PLAYER_UPDATE_SOUND_SLOT_STRIDE;
if (F(s32,&D_8029014C,soundOffset) != 0) {
func_80178760(soundOffset + (u8 *)&D_8029014C);
if (slot == 0) {
if (F(s16,&D_8029014C,18) == PLAYER_UPDATE_FALL_SOUND_ID) {
if (F(s16,&D_8029014C,-1366) == 0) {
if ((F(u8,D_802903AC,PLAYER_ACTION_IN_WATER_OFFSET) != 0) || (F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET) != 0)) {
func_80178704(&D_8029014C);
}
}
} else if (F(s32,&D_8029014C,4) != 0) {
F(s32,&D_8029014C,4) = F(s32,&D_8029014C,4) - 1;
} else {
func_80178704(&D_8029014C);
}
} else if (F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) != 0x21) {
if (D_802901B0 == 0) {
func_80178704((u8 *)&D_8029014C + PLAYER_UPDATE_SOUND_SLOT_STRIDE);
}
}
}
}
if ((D_801E7531 == 0x28) || ((u16)(F(u16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) - 0x18) < 2U)) { /* gravity for this frame */
F(f32,D_802903A8,PLAYER_PHYS_GRAVITY_OFFSET) = D_80108204;
{ s32 *flags = &D_80290300; *flags |= PLAYER_UPDATE_FLAG_NO_GRAVITY; }
} else {
{ s32 *flags = &D_80290300; *flags &= ~PLAYER_UPDATE_FLAG_NO_GRAVITY; }
if (D_802901AC != 0) {
F(f32,D_802903A8,PLAYER_PHYS_GRAVITY_OFFSET) = D_80108208;
} else {
F(f32,D_802903A8,PLAYER_PHYS_GRAVITY_OFFSET) = D_8010820C;
}
}
if ((F(u8,D_802903AC,PLAYER_ACTION_IN_WATER_OFFSET) != 0) || ((groundFace = F(s32,D_802903B0,PLAYER_COLLISION_FACE0_OFFSET), (groundFace != NULL)) && (F(u8,groundFace,116) == 5))) {
D_8029014A = PLAYER_UPDATE_SURFACE_TIMER_MAX;
} else {
s16 *surfaceTimer = &D_8029014A;
if (*surfaceTimer != 0) {
*surfaceTimer -= 1;
}
}
if ((F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) != 0x2A) || (D_8028FBF6 != 0)) {
slot = 0;
do {
sprite = F(s32,&D_80290140,slot * 4);
if (sprite != 0) {
func_8014ACB4(sprite);
func_80141720((u8 *)&D_80290140 + (slot * 4));
}
nextSprite = slot + 1;
slot = nextSprite;
} while (nextSprite < PLAYER_UPDATE_SPRITE_SLOT_COUNT);
}
{
s32 *trailTimer = &D_80290138;
if (*trailTimer != 0) {
*trailTimer -= 1;
if (func_80147000(0x23) < 0xB) {
effect = func_801A9054(&D_802902D8, 0x11, 0);
if (effect != NULL) {
F(f32,effect,100) = F(f32,effect,100) + D_80108210;
forward[0] = 0.0f;
forward[2] = D_80108214;
func_801490AC(forward, forward, D_80290354);
func_8014932C((u8 *)effect + 0x3C, forward);
}
}
}
}
if ((F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET) == 0) && !(D_80290300 & PLAYER_UPDATE_FLAG_LAUNCHED) && (F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) != PLAYER_STATE_SLOPE_SLIDE) && (D_8029011E == 0)) { /* airborne with a zero D_80290080 vector: damp X/Z velocity */
dirLengthSq = (D_80290080 * D_80290080) + (D_80290084 * D_80290084) + (D_80290088 * D_80290088);
dirLength = sqrtf(dirLengthSq);
if (dirLength == 0.0f) {
D_80290330 = D_80290330 * D_80108218;
D_80290338 = D_80290338 * D_80108218;
}
}
{
s16 *attachTimer = &D_802900DA;
if (*attachTimer != 0) {
attachFramesLeft = *attachTimer - 1;
*attachTimer = attachFramesLeft;
if ((attachFramesLeft << 0x10) == 0) {
D_80290304 = NULL;
}
}
}
{
s16 *unkTimer = &D_802900F4;
if (*unkTimer != 0) {
*unkTimer -= 1;
}
}
scaleFrame = D_802900E8;
if (scaleFrame != 0) { /* grow/shrink animation: scale from the D_801EEC14 table, collision radius follows */
if (D_802900EC == 0) {
((s32 *)&D_802900E0)[2] = scaleFrame + 1;
D_80290394 = D_80290398 = D_8029039C = (&D_801EEC14)[scaleFrame];
} else {
((s32 *)&D_802900E0)[2] = scaleFrame + 1;
D_80290394 = D_80290398 = D_8029039C = D_80108220 - (&D_801EEC14)[scaleFrame];
}
{
s32 *scaleFramePtr = &D_802900E8;
if (*scaleFramePtr >= PLAYER_UPDATE_SCALE_ANIM_FRAMES) {
*scaleFramePtr = 0;
}
}
func_80175388(D_802903B0 + 0x74, 13.0f);
F(f32,D_802903B0,112) = F(f32,D_802903B0,116);
F(f32,D_802903A4,8) = F(f32,((u8 **)&D_802902D8)[54],112) * D_80108228;
}
if (D_8028FBF6 != 0) { /* death recovery countdown */
deathContactFlags = F(u8,D_802903B0,PLAYER_COLLISION_CONTACT_FLAGS_OFFSET);
if (((deathContactFlags & 1) || (deathContactFlags & 2)) && (F(s16,D_802903B4,PLAYER_ANIM_CURRENT_OFFSET) == PLAYER_FALL_ANIMATION)) {
func_80133998(&D_802902D8, PLAYER_DEATH_CONTACT_ANIMATION, 0, 0, 0.0f);
}
D_802901DC = 1;
D_8028FC00 = 0;
deathFramesLeft = D_8028FBF6 - 1;
D_8028FBF6 = deathFramesLeft;
if ((deathFramesLeft << 0x10) == 0) {
func_8017479C();
}
func_80174D4C();
if ((F(s32,D_802903B0,PLAYER_COLLISION_FACE0_OFFSET) != NULL) && (D_8028FBF6 < PLAYER_UPDATE_DEATH_ALIGN_MAX_FRAMES)) {
func_801B33A0(&D_802902D8, &contactNormal, &slot);
D_80290300 |= PLAYER_UPDATE_FLAG_ALIGN_SURFACE;
func_8014A040(&D_802902D8, surfaceQuat, contactNormal);
playerQuat = ((u8 *)&D_802902D8 + 0x9C);
func_80147704(playerQuat, surfaceQuat, 0.1f, playerQuat);
}
}
{
s32 *blinkTimer = &D_802901DC;
blinkLeft = *blinkTimer - 1;
if (*blinkTimer != 0) {
*blinkTimer = blinkLeft;
if (D_801E7531 != 0x28) {
if (blinkLeft & 2) {
D_802902FE = 0;
} else {
D_802902FE = PLAYER_UPDATE_BLINK_OPAQUE;
}
}
}
}
{
s16 *unkTimerFBF4 = &D_8028FBF4;
if (*unkTimerFBF4 != 0) {
*unkTimerFBF4 -= 1;
}
}
if (func_8015C4C8() != 0) { /* whose fall counts: the ball, the attached actor, or the player */
fallBody = (u8 *)&D_8029F978;
} else {
u8 **attachedSlot = &D_80290304;
{ u8 *attached = *attachedSlot; if (attached != NULL) fallBody = attached; else fallBody = (u8 *)attachedSlot - 0x2C; }
}
fallState = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
if (((fallState != PLAYER_STATE_SLOPE_SLIDE) || (F(f32,D_802903A4,0) == *(f32 *)&D_80108230)) && (fallState != 0x21) && (F(u8,F(s32,fallBody,216),PLAYER_COLLISION_GROUNDED_OFFSET) == 0) && (((D_80290300 & PLAYER_UPDATE_FLAG_WALL_CLING) && (F(f32,fallBody,92) < DB(D_80108230))) || (F(f32,fallBody,92) < DB(D_80108238)))) {
s16 *fallCounter = &D_8028FC00;
fallFrames = *fallCounter + 1;
*fallCounter = fallFrames;
if (fallBody == (u8 *)&D_802902D8) {
if (fallFrames >= PLAYER_UPDATE_FALL_ANIM_MIN_FRAMES) {
s32 *fallSound = (s32 *)(fallCounter + 0x2A6);
if (*fallSound == 0) {
func_801785E0(fallSound, PLAYER_UPDATE_FALL_SOUND_ID, 0x64, fallBody + 0x34, 0x80);
}
if (D_8029011E == 0) {
func_80133998(fallBody, PLAYER_FALL_ANIMATION, 1, 0, 0.0f);
D_8028FC04 = 1;
F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) = PLAYER_STATE_FALL;
D_8028FBEC = -1;
}
{
s16 *fallStarted = &D_8028FB90;
if (*fallStarted == 0) {
*fallStarted = 1;
}
}
}
}
} else {
if (D_8028FBF6 != 0) {
return;
}
D_8028FC00 = 0;
D_8028FB90 = 0;
}
{
s16 *deathTimer = &D_8028FBF6;
if (*deathTimer != 0) {
return;
}
powerupTimers = (s16 *)((u8 *)deathTimer + 0x522);
slot = 0;
do {
s32 timerIndex = slot;
s16 *timerPtr = (s16 *)(timerIndex * 2 + (s32)powerupTimers);
timer = *timerPtr;
if (timer != 0) {
timerLeft = timer - 1;
*timerPtr = timerLeft;
if ((timerLeft << 0x10) == 0) {
func_801AE204(timerIndex);
}
}
nextTimer = slot + 1;
slot = nextTimer;
} while (nextTimer < PLAYER_UPDATE_POWERUP_TIMER_COUNT);
if (D_8029011C != 0) {
func_80176758();
}
stateNow = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
if (((stateNow != 0x22) & (stateNow != 0x18)) && (stateNow != 0x17)) {
D_80290094 = 0;
}
func_801735E8();
func_801748D0();
func_8016A058();
func_80174D4C();
if (D_802901D4 != 0) { /* power-up 14: the player carries the ball */
D_8029F9A4 = &D_802902D8;
D_8029F47E = 0;
D_8028FBFB = 0;
if ((D_8029F482 == 0) && (func_8015C4C8() != 0)) {
F(f32,D_8029FA50,116) = 0.0f;
func_801B13CC();
func_8017797C();
}
if (D_8029F9A8 <= DB(D_80108240)) {
D_8029F9AC = D_8010824C;
D_8029F9B0 = D_8010824C;
D_8029F9B4 = D_8010824C;
} else if (F(f32,D_8029FA50,116) == 0.0f) {
*(Vec3F *)&D_8029F9AC = *(Vec3F *)&D_8029030C;
}
}
{
s16 *actionLock = (s16 *)&D_8028FBD8; /* action lock: a frame count, 1000 + animation to wait for, or 2000 = until grounded */
s16 lockValue = *actionLock;
if ((u16)lockValue - 1000U < 1000U) {
if (F(s16,D_802903B4,PLAYER_ANIM_CURRENT_OFFSET) != lockValue - PLAYER_UPDATE_LOCK_ANIM_BASE) {
*actionLock = 0;
} else {
unlock = F(s32,D_802903B4,PLAYER_ANIM_DONE_OFFSET);
goto check_unlock;
}
} else if (lockValue > PLAYER_UPDATE_LOCK_GROUNDED) {
*actionLock = lockValue - 1;
} else if (lockValue == PLAYER_UPDATE_LOCK_GROUNDED) {
if (F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET) == 1) {
*actionLock = 0;
} else {
unlock = D_80290300 & PLAYER_UPDATE_FLAG_GROUNDED_LOCK;
check_unlock:
if (unlock != 0) {
*actionLock = 0;
}
}
} else if (lockValue != 0) {
*actionLock = lockValue - 1;
}
}
alignState = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
{
s32 *flags;
if ((((alignState == 8) | (alignState == 0x15)) != 0) || ((u16)(alignState - 0x28) < 2U) || (((alignState == 3) | (alignState == 5)) != 0) || (flags = &D_80290300, (*flags & PLAYER_UPDATE_FLAG_WALL_CLING)) || (alignState == 0x2A)) {
s32 *playerFlags = &D_80290300;
*playerFlags |= PLAYER_UPDATE_FLAG_ALIGN_SURFACE;
func_80160228((u8 *)playerFlags - 0x28, 1);
} else {
*flags &= ~PLAYER_UPDATE_FLAG_ALIGN_SURFACE;
}
}
surfaceState = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
if ((((surfaceState == 8) | (surfaceState == 0x15)) != 0) || (((surfaceState == 3) | (surfaceState == 5)) != 0) || ((D_80290304 == NULL) && (F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) == 0x29))) { /* tilt to the surface normal and turn with a spinning platform */
platform = F(void *,D_802903B0,GROUND_CONTACT_PLATFORM_OFFSET);
if (platform != NULL) {
platformRotation = F(void *,platform,44);
if (platformRotation != NULL) {
{
f32 *yaw = &D_80290354;
*yaw = func_801496C8((*yaw + F(f32,platformRotation,PLATFORM_ROTATION_YAW)) - F(f32,platformRotation,PLATFORM_ROTATION_PREVIOUS_YAW));
}
rotationAgain = F(void *,F(void *,D_802903B0,GROUND_CONTACT_PLATFORM_OFFSET),44);
D_80290360 = func_801496C8((D_80290360 + F(f32,rotationAgain,PLATFORM_ROTATION_YAW)) - F(f32,rotationAgain,PLATFORM_ROTATION_PREVIOUS_YAW));
}
}
contactState = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
if (((contactState == 8) | (contactState == 0x15)) != 0) {
func_801B33A0(&D_802902D8, &contactNormal, &slot);
hitCount = F(s32,D_802903B0 + slot * 4,PLAYER_COLLISION_HIT_COUNT_OFFSET);
} else {
func_801B33A0(&D_8029F978, &contactNormal, &slot);
hitCount = F(s32,D_8029FA50 + slot * 4,PLAYER_COLLISION_HIT_COUNT_OFFSET);
}
if ((contactNormal != NULL) && (F(f32,contactNormal,4) > 0.0f)) {
f32 *yaw = &D_80290354;
forward[0] = 0.0f;
forward[1] = 0.0f;
forward[2] = *(f32 *)&D_80108250;
func_801490AC(forward, forward, *yaw);
if (hitCount >= 2) {
u8 *player = (u8 *)yaw - 0x7C;
D_8029035C = func_801496C8(DB(D_80108250) - func_80147114((forward[0] * F(f32,contactNormal,0)) + (forward[2] * F(f32,contactNormal,8))));
func_80160228(player, 0);
func_8014A040(player, &D_801EEBD8, contactNormal);
}
} else {
f32 *yaw = &D_80290354;
f32 *axisAngleYaw = &D_801ED3EC;
*axisAngleYaw = *yaw;
if (hitCount >= 2) {
func_80148C3C(&D_801EEBD8, (u8 *)axisAngleYaw - 0xC);
D_8029035C = 0.0f;
func_80160228((u8 *)yaw - 0x7C, 0);
}
}
supportPlatform = F(void *,D_802903B0,GROUND_CONTACT_PLATFORM_OFFSET);
if (supportPlatform != NULL) {
supportRotation = F(void *,supportPlatform,44);
if (supportRotation != NULL) {
f32 *axisAngleYaw = &D_801ED3EC;
*axisAngleYaw = F(f32,supportRotation,PLATFORM_ROTATION_YAW) - F(f32,supportRotation,PLATFORM_ROTATION_PREVIOUS_YAW);
func_80148C3C(platformSpinQuat, (u8 *)axisAngleYaw - 0xC);
func_801488C0(&D_801EEBD8, platformSpinQuat, &D_801EEBD8);
}
}
func_80148000(&D_80290374, &D_801EEBD8, F(f32,D_802903A8,PLAYER_PHYS_ALIGN_RATE_OFFSET) * DB(D_80108258), &D_80290374);
} else {
pitchState = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
if (((pitchState != 0x1D) & (pitchState != 0x21)) && ((pitchState != 0xB) & (pitchState != 0x1F)) && ((!(D_80290300 & PLAYER_UPDATE_FLAG_LAUNCHED) && (D_80290090 == 0)) || (pitchState == 3))) {
if ((D_802901B0 != 0) && (F(s16,D_802903B4,PLAYER_ANIM_CURRENT_OFFSET) == 0x3A)) {
D_8029035C = D_80108264;
} else {
D_8029035C = 0.0f;
}
}
*(QuatWords *)&D_801EEBD8 = *(QuatWords *)&D_80290374;
}
{
s32 *flags = &D_80290300;
if ((*flags & PLAYER_UPDATE_FLAG_WALL_CLING) && ((F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) != 0x2A) || (F(s16,D_802903B4,PLAYER_ANIM_CURRENT_OFFSET) == 0x32))) { /* wall cling: hold the contact face that most opposes the D_80290080 vector */
s32 *clingFace;
s32 previousClingFace;
lowestDot = *(f32 *)&D_80108268;
func_80160228((u8 *)flags - 0x28, 1);
clingFace = &D_802900BC;
previousClingFace = *clingFace;
dirVec = (void **)((u8 *)clingFace - 0x3C);
slot = 0;
do {
wallFace = F(void *,D_802903B0 + (slot * 4),PLAYER_COLLISION_FACE0_OFFSET);
if (wallFace != NULL) {
wallDot = (F(f32,dirVec,0) * F(f32,wallFace,0)) + (D_80290084 * F(f32,wallFace,4)) + (D_80290088 * F(f32,wallFace,8));
if (wallDot <= lowestDot) {
F(void *,dirVec,60) = wallFace;
lowestDot = wallDot;
}
}
nextFace = slot + 1;
slot = nextFace;
} while (nextFace < PLAYER_UPDATE_CONTACT_SLOT_COUNT);
if (previousClingFace == D_802900BC) {
D_802900C0 += 1;
} else {
D_802900C0 = 0;
}
if (D_802900C4 == 6) {
D_802900BC = 0;
D_802900C0 = 0;
}
if (D_802900BC != 0) {
func_8014A040(&D_802902D8, surfaceQuat, D_802900BC);
} else {
f32 *axisAngleYaw = &D_801ED3EC;
*axisAngleYaw = D_80290354;
func_80148C3C(surfaceQuat, (u8 *)axisAngleYaw - 0xC);
}
clingBlend = D_802900C0 * DB(D_80108268);
{
u8 *orientation = &D_80290374; alignFraction = D_8010827C; if (clingBlend < DB(D_80108270)) { alignFraction = clingBlend; }
func_80147704(orientation, surfaceQuat, alignFraction, orientation);
}
if (D_801FAAC8[D_80202218 * PLAYER_UPDATE_CONTROLLER_STRIDE] != 0) {
func_8018D39C(3);
padOffset = D_80202218 * PLAYER_UPDATE_CONTROLLER_STRIDE;
F(s32,&D_801FAB78,padOffset) = 6;
F(u8,&D_801FAAF2,padOffset) = 1;
}
} else if ((F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) != 0x21) && (D_8029011E == 0) && (F(u8,D_802903AC,PLAYER_ACTION_IN_WATER_OFFSET) == 0) && (func_8015C4C8() == 0) && (((StateConditionFn)func_8016536C)(3) == 0) && ((D_8029F9A4 != &D_802902D8) || (D_8028FBFB != 0)) && (F(void *,D_802903B0,PLAYER_COLLISION_FACE0_OFFSET) != NULL)) { /* otherwise: slope slide checks */
groundPlane = F(void *,D_802903A4,4);
if (groundPlane != NULL) {
touchesGround = 0;
if (F(f32,groundPlane,4) > 0.0f) {
contactNormal = groundPlane;
for (slot = 0; slot < PLAYER_UPDATE_CONTACT_SLOT_COUNT; slot++) {
touchedFace = F(void *,D_802903B0 + (slot * 4),PLAYER_COLLISION_FACE0_OFFSET);
if ((touchedFace == contactNormal) || ((touchedFace != NULL) && (D_80108280 < ((F(f32,F(void *,D_802903A4,4),0) * F(f32,touchedFace,0)) + (F(f32,F(void *,D_802903A4,4),4) * F(f32,touchedFace,4)) + (F(f32,F(void *,D_802903A4,4),8) * F(f32,touchedFace,8)))))) {
touchesGround = 1;
break;
}
}
if (touchesGround != 0) {
func_8017574C(contactNormal);
}
}
}
if ((F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) == PLAYER_STATE_FALL) && (F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET) == 0) && (D_80290104 >= 3)) {
slot = 0;
do {
face = F(void *,D_802903B0 + (slot * 4),PLAYER_COLLISION_FACE0_OFFSET);
contactNormal = face;
if (face != NULL) {
normalY = F(f32,face,4);
if ((normalY > 0.0f) && (((D_80290330 * F(f32,face,0)) + (D_80290334 * normalY) + (D_80290338 * F(f32,face,8))) < 0.0f)) {
func_8017574C(face);
}
}
nextContact = slot + 1;
slot = nextContact;
} while (nextContact < PLAYER_UPDATE_CONTACT_SLOT_COUNT);
}
}
}
if (D_801E7531 == PLAYER_UPDATE_LEVEL_SNAP_YAW) { /* this level snaps the target yaw to eighths of a turn */
f32 *targetYaw;
s32 yawUnits;
f32 snappedYaw;
yawStep = D_80108288 / yawSnapDivisions;
targetYaw = &D_80290360;
yawUnits = *targetYaw * *(f32 *)&D_80108290;
yawUnits += yawStep / 2;
yawUnits = (yawUnits / yawStep) * yawStep; snappedYaw = yawUnits; *targetYaw = func_801496C8(snappedYaw / DB(D_80108290));
}
if (D_8028FBD8 == 0) { /* unlocked: enter the first allowed action state whose condition holds */
for (nextState = 0; nextState < PLAYER_ACTION_COUNT; nextState++) {
u8 *transitions = (u8 *)&D_801EEC44 + F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) * PLAYER_ACTION_COUNT;
if ((transitions[nextState] != 0) && (((StateConditionFn)func_8016536C)(nextState) != 0) && (D_801E7460 == 0)) {
func_80167604(nextState);
break;
}
}
}
if ((F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET) != 0) && (idlePadOffset = D_80202218 * PLAYER_UPDATE_CONTROLLER_STRIDE, (F(f32,&D_801FAA94,idlePadOffset) == 0.0f)) && (F(u8,&D_801FAAAB,idlePadOffset) == 0) && (F(u8,&D_801FAAAA,idlePadOffset) == 0) && (F(u8,&D_801FAAAC,idlePadOffset) == 0) && (F(u8,&D_801FAAAF,idlePadOffset) == 0) && (F(u8,&D_801FAAAE,idlePadOffset) == 0) && (D_801E7542 == 0)) { /* grounded with no input: count idle frames */
s16 *idleFrames = (s16 *)&D_8028FBF8;
*idleFrames += 1;
} else {
D_8028FBF8 = 0;
}
D_8028FBED = D_8028FBEC;
D_8028FBE8 = F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET);
if (D_8028FBF0 == F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET)) {
D_80290104 += 1;
} else {
D_80290104 = 0;
}
D_8028FBF0 = F(u8,D_802903B0,PLAYER_COLLISION_GROUNDED_OFFSET);
D_8029F484 = F(u8,D_8029FA50,PLAYER_COLLISION_GROUNDED_OFFSET);
D_8028FBEA = D_8028FBEA + 1;
if (D_80290300 & PLAYER_UPDATE_FLAG_WALL_CLING) {
if (F(void *,D_802903B0,PLAYER_COLLISION_FACE0_OFFSET) != NULL) {
D_802900C4 = 0;
} else {
D_802900C4 += 1;
}
}
if (D_8029F9A4 != &D_802902D8) {
if ((F(u8,D_8029FA50,PLAYER_COLLISION_GROUNDED_OFFSET) == 0) && (D_8029F9D4 < DB(D_80108298)) && (F(s32,D_8029FA50,PLAYER_COLLISION_FACE0_OFFSET) == 0)) {
s16 *ballAirFrames = &D_8029F480;
*ballAirFrames += 1;
} else {
D_8029F480 = 0;
}
}
F(f32,D_802903A8,PLAYER_PHYS_DRAG_OFFSET) = D_801082A4; /* drag and friction for the next frame */
F(f32,((u8 **)&D_802902D8)[52],PLAYER_PHYS_FRICTION_OFFSET) = *(f32 *)&D_801082A8;
if (D_802901AC != 0) {
F(f32,((PointerBox *)&D_802903A8)->v,PLAYER_PHYS_DRAG_OFFSET) = F(f32,((PointerBox *)&D_802903A8)->v,PLAYER_PHYS_DRAG_OFFSET) * DB(D_801082A8);
F(f32,((u8 **)&D_802903A4)[1],PLAYER_PHYS_FRICTION_OFFSET) = D_801082B4;
}
if (D_802901B0 != 0) {
F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) = *(f32 *)&D_801082B8;
F(f32,((u8 **)&D_802903AC)[-1],PLAYER_PHYS_DRAG_OFFSET) = F(f32,((u8 **)&D_802903AC)[-1],PLAYER_PHYS_DRAG_OFFSET) * DB(D_801082B8);
}
if (D_802901A8 != 0) {
F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) = F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) / D_801082C4;
}
if (F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) == PLAYER_STATE_SLOPE_SLIDE) {
F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) = F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) * *(f32 *)&D_801082C8;
}
if (D_80290134 & 1) {
F(f32,D_802903A8,PLAYER_PHYS_DRAG_OFFSET) = F(f32,D_802903A8,PLAYER_PHYS_DRAG_OFFSET) * DB(D_801082C8);
}
if (F(s16,D_802903AC,PLAYER_STATE_CURRENT_OFFSET) == 0x15) {
animTime = F(f32,D_802903B4,PLAYER_ANIM_TIME_OFFSET);
if ((D_801082D4 <= animTime) && (animTime <= D_801082D8)) {
F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) = D_801082DC;
return;
}
F(f32,D_802903A8,PLAYER_PHYS_FRICTION_OFFSET) = F(f32,D_802903A8,PLAYER_PHYS_DRAG_OFFSET) = 0.0f;
{
f32 *velocityX = &D_80290330;
*velocityX = *velocityX * D_801082E0;
D_80290338 = D_80290338 * D_801082E0;
}
}
}
}

void func_80160B6C(u8 *arg0, void *arg1, f32 arg2, f32 arg3);
void func_8016049C(u8 *arg0, f32 arg1, f32 arg2);
f32 func_80148E48(f32 *a, f32 *b);
void func_8017797C(void);
void func_801B182C(void);
void func_801B1E48(void);
/* Captures the player (or the ball) on a nearby launcher object, pulls it to the launch point for a few frames, then fires it off with the launcher's speed. */
void func_801735E8(void) {
    extern u8 *volatile D_80290090;
    extern Vec3F D_80290330;
    extern f32 D_8029035C;
    extern f32 D_80290360;
    extern f32 D_80290334;
    extern const f32 D_801082FC;
    extern const f32 D_80108300;
    extern const f32 D_80108304;
    extern const f32 D_80108308;
    extern const f32 D_8010830C;
    extern const f64 D_80108310;
    extern char D_801082E8[];
    Vec3F launch_pos;
    Vec3F *launch_ptr;
    u8 *launcher;
    u8 *launch_data;
    f32 *target;
    s32 tmp;

    if (D_80290300 & 0x2000) {
        if ((D_802903B0[0x188] != 0 && *(s16 *)(D_802903AC + 4) != 3)
            || (*(s16 *)(D_802903AC + 4) == 3 && D_8029FA50[0x188] != 0)) {
            s32 *player_flags = &D_80290300;
            player_flags[0] &= ~0x1002000;
            if (*(s16 *)(D_802903AC + 4) == 3) {
                s32 *ball_flags = &D_8029F9A0;
                ball_flags[0] &= ~0x1000000;
            }
        } else {
            s32 *player_flags2 = &D_80290300;
            tmp = player_flags2[0] | 0x10;
            player_flags2[0] = tmp;
            D_80290348 = D_8028FBCC;
            func_80173CE8(2);
        }
    }

    if (*(u8 **)&D_80290090 != NULL) {
        f32 *cam = &D_80290348;
        launcher = *(u8 **)&D_80290090;
        *cam = D_8028FBCC;
        if (*(s16 *)(*(u8 **)(launcher + 0x50) + 0x18) > 0) {
            launch_pos = **(Vec3F **)(launcher + 0x50);
            launch_ptr = &launch_pos;
            if (*(u8 **)(launcher + 0x2c) != NULL) {
                func_801490AC(launch_ptr, launch_ptr, *(f32 *)(*(u8 **)(launcher + 0x2c) + 0x3c));
            }
            launch_pos.x = *(f32 *)(launcher + 0xb4) + launch_pos.x;
            launch_pos.y = *(f32 *)(launcher + 0xb8) + launch_pos.y;
            launch_pos.z = *(f32 *)(launcher + 0xbc) + launch_pos.z;
            if (*(s16 *)(D_802903AC + 4) == 3) {
                target = &D_8029F9AC;
            } else {
                target = cam - 15;
            }
            func_801493EC(target, target, 0.8f, &launch_ptr->x, D_801082FC);
            tmp = *(u16 *)(*(u8 **)(launcher + 0x50) + 0x18);
            tmp -= 1;
            *(s16 *)(*(u8 **)(launcher + 0x50) + 0x18) = tmp;
            if (*(s16 *)(*(u8 **)(launcher + 0x50) + 0x18) == 0) {
                if (*(u8 **)(D_802903B0 + 0x178) == launcher && *(s16 *)(*(u8 **)(launcher + 0x50) + 0x1a) == 0) {
                    if (*(s16 *)(D_802903AC + 4) != 3) {
                        f32 *z = &D_8029035C;
                        *z = D_80108300;
                    }
                    *(f32 *)(*(u8 **)(*(u8 **)(D_802903B0 + 0x178) + 0x2c) + 0x50) = -*(f32 *)(*(u8 **)(launcher + 0x50) + 0x1c);
                    *(s16 *)(*(u8 **)(launcher + 0x50) + 0x1a) = *(s32 *)(*(u8 **)(launcher + 0x50) + 0x20);
                }
            }
            if (*(s16 *)(D_802903AC + 4) == 3) {
                func_80149318(&D_8029F9D0, &D_801ED3C4);
                func_801B182C();
            } else {
                func_80149318(&D_80290330, &D_801ED3C4);
            }
        }
        launch_data = *(u8 **)(launcher + 0x50);
        if (*(s16 *)(launch_data + 0x1a) > 0) {
            if (--*(s16 *)(launch_data + 0x1a) == 0) {
                s32 *flags;
                *(f32 *)(*(u8 **)(launcher + 0x2c) + 0x50) = -*(f32 *)(*(u8 **)(launcher + 0x2c) + 0x50) / D_80108304;
                flags = &D_80290300;
                *(s16 *)(*(u8 **)(launcher + 0x50) + 0x1a) = -1;
                flags[0] = (flags[0] | 0x2000) & ~0x10;
                if (*(s16 *)(D_802903AC + 4) == 3) {
                    *(Vec3F *)&D_8029F9D0 = *(Vec3F *)&D_801ED3C4;
                    func_80160B6C((u8 *)flags - 0x28, (u8 *)&D_8029F9D0 - 0x58,
                                  *(f32 *)(*(u8 **)(launcher + 0x50) + 0xc), 100000.0f);
                    D_8029F9A0 |= 0x1000000;
                    D_8029F9D4 = ((f32 **)launcher)[20][4];
                } else {
                    f32 cam_value;
                    f32 launch_speed;
                    D_80290330 = *(Vec3F *)&D_801ED3C4;
                    func_80167604(2);
                    func_8016049C((u8 *)flags - 0x28, *(f32 *)(*(u8 **)(D_80290090 + 0x50) + 0xc), 100000.0f);
                    launch_speed = *(f32 *)(*(u8 **)(launcher + 0x50) + 0x10);
                    cam_value = D_8028FBCC;
                    D_80290348 = cam_value;
                    *flags |= 0x1000000;
                    D_80290334 = launch_speed;
                }
            }
        } else if (*(s16 *)(launch_data + 0x1a) != 0) {
            if (--*(s16 *)(launch_data + 0x1a) == (1 - *(s32 *)(*(u8 **)(launcher + 0x50) + 0x20)) * 4) {
                D_80290090 = NULL;
                *(f32 *)(*(u8 **)(launcher + 0x2c) + 0x50) = 0.0f;
                *(f32 *)(*(u8 **)(launcher + 0x2c) + 0x38) = 0.0f;
                *(s16 *)(*(u8 **)(launcher + 0x50) + 0x1a) = 0;
            }
        }
    }

    if (*(u8 **)(D_802903B0 + 0x178) != NULL) {
        u8 *standing_data = *(u8 **)(*(u8 **)(D_802903B0 + 0x178) + 0x50);
        if (standing_data != NULL && *(s16 *)(standing_data + 0x14) != 0 && *(s32 *)(standing_data + 0x18) == 0) {
            Vec3F *point;
            launch_pos = *(Vec3F *)standing_data;
            point = &launch_pos;
            if (*(u8 **)(*(u8 **)(D_802903B0 + 0x178) + 0x2c) != NULL) {
                func_801490AC(point, point, *(f32 *)(*(u8 **)(*(u8 **)(D_802903B0 + 0x178) + 0x2c) + 0x3c));
            }
            launch_pos.x = *(f32 *)(*(u8 **)(D_802903B0 + 0x178) + 0xb4) + launch_pos.x;
            launch_pos.y = *(f32 *)(*(u8 **)(D_802903B0 + 0x178) + 0xb8) + launch_pos.y;
            launch_pos.z = *(f32 *)(*(u8 **)(D_802903B0 + 0x178) + 0xbc) + launch_pos.z;
            if ((*(s16 *)(D_802903AC + 4) == 3 && func_80148EBC(D_8029FA50 + 0x10, (s32)point) < D_80108308)
                || (*(s16 *)(D_802903AC + 4) != 3 && func_80148E48((f32 *)(D_802903B0 + 0x10), &point->x) < D_8010830C)) {
                if (*(s16 *)(D_802903AC + 4) == 3) {
                    func_80149318(&D_8029F9D0, &D_801ED3C4);
                    func_801B1E48();
                    D_8029FA30 = 0.0f;
                } else {
                    func_8017797C();
                    func_80149318(&D_80290330, &D_801ED3C4);
                }
                func_80139D70(func_801D2150(&D_8025D578, D_801082E8));
                D_80290090 = *(u8 **)(D_802903B0 + 0x178);
                *(s16 *)(*(u8 **)(D_80290090 + 0x50) + 0x18) = 10;
                *(s16 *)(*(u8 **)(D_80290090 + 0x50) + 0x16) = 0;
                func_80173CE8(D_8028FBD8 = *(s32 *)(*(u8 **)(D_80290090 + 0x50) + 0x20) + 11);
                D_80290360 = func_801496C8(*(f32 *)(*(u8 **)(*(u8 **)(D_802903B0 + 0x178) + 0x2c) + 0x3c) + D_80108310);
            }
        }
    }
}

/* During gameplay (game state 4 or 5), extends the gameplay timer D_8028FBF4 to at least `duration`. */
void func_80173CE8(s32 duration) {
    extern s16 D_8028FBF4;
    s16 newTime = duration;

    if ((u32)((u8)D_801E7530 - GAME_STATE_PLAY) < 2) {
        s16 *timer = &D_8028FBF4;

        if (*timer < (s16)duration) {
            *timer = newTime;
        }
    }
}

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

/* Detect a player/probe crossing of an enabled triangle edge, then set yaw and an edge point. */
s32 func_80173D28(u8 *probeBody, f32 *triangle) {
    extern f32 D_80108318;
    extern u8 D_80290200[];
    s32 edgeIndex = 0;
    f32 *playerPosition = (f32 *)&D_8029030C;
    f32 edgeNormalOrOffset[4];
    f32 pointOffset[4];
    s32 nextVertexIndex;
    f32 *nextVertexBase;
    f32 playerSideOrDistance, probeSideOrDistance, distanceSum;
    f32 negatedEdgeStartZ;

    for (; edgeIndex < COLLISION_TRIANGLE_VERTEX_COUNT; edgeIndex++) {
        if (triangle[edgeIndex + TRI_EDGE_LENGTHS] == D_80108318) {
            continue;
        }
        nextVertexIndex = (edgeIndex + 1) % COLLISION_TRIANGLE_VERTEX_COUNT;
        negatedEdgeStartZ = -triangle[edgeIndex * 3 + TRI_VERTEX0_Z];
        nextVertexBase = triangle + nextVertexIndex * 3;
        edgeNormalOrOffset[0] = negatedEdgeStartZ + nextVertexBase[TRI_VERTEX0_Z];
        edgeNormalOrOffset[2] = triangle[edgeIndex * 3 + TRI_VERTEX0_X] - nextVertexBase[TRI_VERTEX0_X];
        pointOffset[0] = playerPosition[0] - nextVertexBase[TRI_VERTEX0_X];
        pointOffset[2] = playerPosition[2] - nextVertexBase[TRI_VERTEX0_Z];
        playerSideOrDistance = pointOffset[0] * edgeNormalOrOffset[0] + pointOffset[2] * edgeNormalOrOffset[2];
        pointOffset[0] = *(f32 *)(probeBody + EDGE_PROBE_POSITION_X) - nextVertexBase[TRI_VERTEX0_X];
        pointOffset[2] = *(f32 *)(probeBody + EDGE_PROBE_POSITION_Z) - nextVertexBase[TRI_VERTEX0_Z];
        probeSideOrDistance = pointOffset[0] * edgeNormalOrOffset[0] + pointOffset[2] * edgeNormalOrOffset[2];
        if (playerSideOrDistance * probeSideOrDistance < 0.0f) {
            playerPosition[EDGE_PLAYER_YAW_INDEX] = playerPosition[EDGE_PLAYER_TARGET_YAW_INDEX] = func_801496C8(func_80147460(edgeNormalOrOffset[0], edgeNormalOrOffset[2]));
            func_80149428(edgeNormalOrOffset, playerPosition, &triangle[edgeIndex * 3 + TRI_VERTEX0_X]);
            func_80149428(pointOffset, playerPosition, &triangle[nextVertexIndex * 3 + TRI_VERTEX0_X]);
            playerSideOrDistance = __builtin_sqrtf(edgeNormalOrOffset[0] * edgeNormalOrOffset[0] + edgeNormalOrOffset[2] * edgeNormalOrOffset[2]);
            probeSideOrDistance = __builtin_sqrtf(pointOffset[0] * pointOffset[0] + pointOffset[2] * pointOffset[2]);
            distanceSum = playerSideOrDistance + probeSideOrDistance;
            func_80149398(D_80290200, &triangle[edgeIndex * 3 + TRI_VERTEX0_X], probeSideOrDistance / distanceSum, &triangle[nextVertexIndex * 3 + TRI_VERTEX0_X], playerSideOrDistance / distanceSum);
            return 1;
        }
    }
    return 0;
}

/*
 * Puts the player into state 2: zeroes its velocity (D_80290330), drops whatever it is attached to
 * (D_802900C8, offset D_802900CC), extends the gameplay timer D_8028FBF4 to at least 20 frames
 * (func_80173CE8 inlined), stores `arg` in D_802900DA and, when the camera has no transition
 * (D_8028FAF4 == 0), points the camera targets back at the player position D_8029030C.
 */
void func_80173F6C(s16 arg) {
    extern Vec3F D_80290330;
    extern Vec3F D_802900CC;
    extern s16 D_8028FBEE;
    extern s16 D_802900DA;
    extern s32 D_8028FAF4;
    extern s8 D_801E7530;
    extern u8 *D_8028FAC8;
    extern u8 *D_8028FAD0;
    s16 minFrames;
    __builtin_memcpy(&D_80290330, &D_801ED3C4, sizeof(Vec3F));
    D_8028FBEE = 0;
    D_802900C8 = 0;
    do { } while (0);
    __builtin_memcpy(&D_802900CC, &D_801ED3C4, sizeof(Vec3F));
    func_80167604(2);
    minFrames = 20;
    /* game states 4 and 5: in gameplay */
    if ((u32)((u8)D_801E7530 - 4) < 2) {
        if (D_8028FBF4 < minFrames) {
            D_8028FBF4 = minFrames;
        }
    }
    D_802900DA = arg;
    if (D_8028FAF4 == 0) {
        D_8028FAC8 = (u8 *)&D_8029030C;
        D_8028FAD0 = (u8 *)&D_8029030C + 0x24;
    }
}

void func_80174058(s16 damageMode) {
    /* Start the player's death animation, sound and recovery timers. */
    s32 effectIndex;
    s32 *health;
    s32 *objectFlags;
    s32 *effectTimers;
    s16 transitionDelay;

    health = &D_80290194;
    *health = 0;
    func_8018D39C(PLAYER_DEATH_EFFECT_TO_CANCEL);
    if (D_802900C8 != 0) {
        func_801964B0();
    }
    if (D_801EC740 == 0) {
        func_801364D0();
    }
    objectFlags = &D_80290300;
    *objectFlags = (*objectFlags & ~8) | 0x11;
    *(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) = PLAYER_STATE_HURT;
    effectTimers = health + 2;
    for (effectIndex = 0; effectIndex < PLAYER_DEATH_EFFECT_TIMER_COUNT; effectIndex++) {
        if (effectTimers[effectIndex] > PLAYER_DEATH_EFFECT_MAX_FRAMES) {
            effectTimers[effectIndex] = PLAYER_DEATH_EFFECT_MAX_FRAMES;
        }
    }
    if (D_8028FBF6 != 0) {
        return;
    }
    if (D_801E7531 == PLAYER_ROBOT_LEVEL) {
        func_8017479C();
        return;
    }
    func_80167604(PLAYER_STATE_HURT);
    func_80175388(D_802903B0 + PLAYER_COLLISION_TARGET_RADIUS_OFFSET, 13.0f);
    transitionDelay = PLAYER_DEATH_TRANSITION_DELAY;
    if ((u32)((u8)D_801E7530 - 4) < 2) {
        if (D_8028FBF4 < transitionDelay) {
            D_8028FBF4 = transitionDelay;
        }
    }
    switch (damageMode) {
    case PLAYER_DAMAGE_NO_HORIZONTAL_KNOCKBACK:
        if (D_802903B0[0x18A] != 0) {
            s32 *soundState = &D_8029014C;
            if (*soundState != 0) {
                func_80178704(soundState);
            }
            func_80178134(func_80147000(PLAYER_DEATH_SOUND_VARIANTS) + PLAYER_DEATH_SOUND_BASE, (f32 *)&D_8029030C, PLAYER_DEATH_SOUND_VOLUME, PLAYER_DEATH_SOUND_PITCH);
            if (D_8029011E == 0) {
                func_80133998((u8 *)&D_8029030C - PLAYER_OBJECT_POSITION_OFFSET, PLAYER_DEATH_CONTACT_ANIMATION, 0, 0, D_8010831C);
            }
        } else {
            s32 *soundState = &D_8029014C;
            s16 *pendingCountdown;
            if (*soundState == 0) {
                func_801785E0(soundState, PLAYER_FALL_SOUND, PLAYER_DEATH_SOUND_VOLUME, (s32)&D_8029030C, PLAYER_DEATH_SOUND_PITCH);
            }
            func_80133998(&D_802902D8, PLAYER_FALL_ANIMATION, 1, 0, 0);
            *(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) = PLAYER_STATE_FALL;
            pendingCountdown = &D_8028FB90;
            D_8028FC04 = 1;
            D_8028FBEC = -1;
            if (*pendingCountdown == 0) {
                *pendingCountdown = 1;
            }
        }
        break;
    case 3:
        func_80178134(func_80147000(PLAYER_DEATH_SOUND_VARIANTS) + PLAYER_DEATH_SOUND_BASE, (f32 *)&D_8029030C, PLAYER_DEATH_SOUND_VOLUME, PLAYER_DEATH_SOUND_PITCH);
        func_80133998((u8 *)&D_8029030C - PLAYER_OBJECT_POSITION_OFFSET, 0x14, 0, 0, 0);
        D_80290300 &= ~0x100;
        break;
    default:
        func_80178134(func_80147000(PLAYER_DEATH_SOUND_VARIANTS) + PLAYER_DEATH_SOUND_BASE, (f32 *)&D_8029030C, PLAYER_DEATH_SOUND_VOLUME, PLAYER_DEATH_SOUND_PITCH);
        func_80133998((u8 *)&D_8029030C - PLAYER_OBJECT_POSITION_OFFSET, PLAYER_DEATH_ANIMATION, 0, 0, D_80108320);
        break;
    }
    {
        s32 *ballRecoveryTimer = &D_8029F468;
        D_8028FBF6 = PLAYER_DEATH_RECOVERY_FRAMES;
        if (*ballRecoveryTimer != 0) {
            *ballRecoveryTimer = PLAYER_DEATH_BALL_RECOVERY_FRAMES;
        }
    }
    D_8028FBD8 = PLAYER_DEATH_RECOVERY_FRAMES;
}

void func_801743A8(s32 damageMode, s16 damage) {
    /* Apply damage, death or hit recovery, and the requested horizontal knockback. */
    extern f32 D_80108324;
    extern s32 D_802901DC;
    extern s32 D_80284DF0;
    extern f32 D_80290334;
    extern f32 D_80290330;
    extern s32 D_802900A4;
    extern u8 *D_802903A8;
    extern s8 D_801E7530;
    f32 knockback[3];
    f32 knockbackSpeed;
    s32 *playerPosition;
    s32 *previousSupport;
    s16 *deathTimer;
    s32 gameModeOrDelay;

    func_8018D39C(6);
    gameModeOrDelay = D_801EC740;
    knockbackSpeed = D_80108324;
    if (gameModeOrDelay == 2) return;
    deathTimer = &D_8028FBF6;
    if (*deathTimer != 0 || D_802901DC != 0) {
        return;
    }
    if (damage == 0) {
        damage = 1;
    }
    if (D_8029011E != 0) {
        func_80176AFC();
        func_80174058(damageMode);
        *deathTimer = 1;
        D_8029F468 = 0;
        return;
    }
    func_80175388(D_802903B0 + 0x74, knockbackSpeed);
    D_80290348 = D_8028FBCC;
    if (damage >= 0) {
        if (!(D_80297BEC & PLAYER_DAMAGE_HEALTH_PROTECTED)) D_80290194 -= damage;
    } else {
        D_80290194 = 0;
    }
    gameModeOrDelay = 0x14;
    if ((u32)((u8)D_801E7530 - 4) < 2) {
        if (D_8028FBF4 < 0x14) {
            D_8028FBF4 = gameModeOrDelay;
        }
    }
    if (func_8015C4C8() == 1) {
        func_80167604(9);
        do { *(Vec3Words *)&D_80290330 = *(Vec3Words *)&D_801ED3C4; } while (0);
        D_80290300 |= 0x18;
    }
    if (*(s16 *)(D_802903AC + 4) == 0x24 || *(s16 *)(D_802903AC + 4) == 0x28) {
        func_801764A8();
    }
    if (*(s16 *)(D_802903AC + 4) == 0x14) {
        func_801766C0();
    }
    if (D_80290194 <= 0) {
        if (D_801E7531 == 0x28) {
            D_802901DC = PLAYER_DAMAGE_SHORT_INVULNERABILITY_FRAMES;
        }
        func_80174058(damageMode);
        return;
    }
    D_80284DF0 = 0x800;
    playerPosition = &D_8029030C;
    func_80178134(func_80147000(PLAYER_DAMAGE_SOUND_VARIANTS) + PLAYER_DAMAGE_SOUND_BASE, (f32 *)playerPosition, PLAYER_DAMAGE_SOUND_VOLUME, PLAYER_DAMAGE_SOUND_PITCH);
    if (D_801E7531 == 0x28) {
        D_802901DC = PLAYER_DAMAGE_SHORT_INVULNERABILITY_FRAMES;
        return;
    }
    D_802901DC = PLAYER_DAMAGE_INVULNERABILITY_FRAMES;
    func_80167604(PLAYER_STATE_HURT);
    D_80290334 = *(f32 *)D_80108328;
    switch (damageMode) {
    case PLAYER_DAMAGE_NO_HORIZONTAL_KNOCKBACK: return;
    case PLAYER_DAMAGE_KNOCKBACK_FROM_SUPPORT:
        previousSupport = &D_802900A4;
        if (*previousSupport == 0) {
            func_80149428(knockback, (f32 *)playerPosition, (f32 *)previousSupport - 3);
        } else {
            func_80149428(knockback, (f32 *)playerPosition, (f32 *)(*previousSupport + 0xB4));
            func_80149374(knockback, knockback, (f32 *)previousSupport - 3);
        }
        func_80149604(knockback);
        knockbackSpeed = -knockbackSpeed;
        knockback[0] *= knockbackSpeed;
        knockback[2] *= knockbackSpeed;
        if (sqrtf(knockback[0] * knockback[0] + knockback[2] * knockback[2]) != 0) {
            func_80149428(&D_80290330, &D_80290330, knockback);
        } else {
            func_8016049C(&D_802902D8, knockbackSpeed, *(f32 *)(D_802903A8 + 8));
        }
        break;
    case PLAYER_DAMAGE_KNOCKBACK_BACKWARD:
        knockbackSpeed = -knockbackSpeed;
        func_8016049C(&D_802902D8, knockbackSpeed, *(f32 *)(D_802903A8 + 8));
        break;
    }
}

void func_8017479C(void) {
    s32 *lives;

    /* Consume a life, start game over if exhausted, and schedule respawning. */
    if (func_80128F0C()) {
        D_80290194 = PLAYER_RESPAWN_HEALTH;
        func_80128DF8(PLAYER_LIFE_LOSS_TRANSITION, 1, 0);
        return;
    }
    if (!(D_80297BEC & PLAYER_OPTION_INFINITE_LIVES)) {
        func_8014E9F4((s32)D_8028F714, (s32)D_8028F718, -4.0f, 12.0f, SCREEN_PARTICLE_LIFE_ICON, 1);
        lives = &D_80290190;
        if (--*lives != PLAYER_LIVES_EXHAUSTED) {
            goto restore_health;
        }
        D_801E7470 = 1;
        D_801EC7D2 = 1;
    }
    if (D_80290190 != PLAYER_LIVES_EXHAUSTED) {
restore_health:
        D_80290194 = PLAYER_RESPAWN_HEALTH;
    }
    if (D_801E7531 != PLAYER_ROBOT_LEVEL && D_802900E0 != 0) {
        s16 *respawnState = *(s16 **)(D_802900E0 + RESPAWN_PLATFORM_STATE_OFFSET);
        if (respawnState[RESPAWN_PLATFORM_COUNTDOWN_WORD] == 0) {
            respawnState[RESPAWN_PLATFORM_COUNTDOWN_WORD] = RESPAWN_PLATFORM_START_COUNTDOWN;
        }
    }
    if (D_801EC740 == 0) {
        func_801364D0();
    }
}

void func_801748D0(void) {
    /* Apply contacted platforms' linked velocities, or release a waiting support path. */
    u8 *linkedPlatform;
    u8 *motionLinks;

    if (*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) && *(u8 **)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_PATH) && (u16)(*(s16 *)(*(u8 **)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_PATH) + PLATFORM_PATH_WAIT) + 2) < 2) {
        motionLinks = *(u8 **)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_MOTION_LINKS);
        if (motionLinks && motionLinks + PLATFORM_LINK_VELOCITY_TAG) {
            linkedPlatform = (u8 *)func_8017DBD8(&D_802904D4, *(s16 *)(motionLinks + PLATFORM_LINK_VELOCITY_TAG));
            while (linkedPlatform) {
                *(Vec3F *)(linkedPlatform + PLATFORM_VELOCITY) = **(Vec3F **)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_MOTION_LINKS);
                if (*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS)) {
                    *(f32 *)(linkedPlatform + PLATFORM_VELOCITY) += *(f32 *)(*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_OFFSET);
                    *(f32 *)(linkedPlatform + PLATFORM_VELOCITY_Y) += *(f32 *)(*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_OFFSET_Y);
                    *(f32 *)(linkedPlatform + PLATFORM_VELOCITY_Z) += *(f32 *)(*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_OFFSET_Z);
                }
                linkedPlatform = (u8 *)func_8017DBD8((Unk802904D4Node *)linkedPlatform, *(s16 *)(*(u8 **)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_TAG));
            }
        } else if (*(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) == 0x12) {
            if (*(s16 *)(*(u8 **)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_PATH) + PLATFORM_PATH_WAIT) == -1) {
                *(u16 *)(*(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_UNK078_OFFSET) |= 2;
                *(u16 *)(*(u8 **)((u8 *)*(void **)&D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_UNK078_OFFSET) &= ~0x800;
            }
            *(s16 *)(*(u8 **)(*(u8 **)((u8 *)*(void **)&D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET) + PLATFORM_PATH) + PLATFORM_PATH_WAIT) = 1;
        }
    } else {
        if (*(u8 **)(D_802903B0 + PLAYER_CONTACT_PLATFORM_SLOT1) && *(u8 **)(*(u8 **)(D_802903B0 + PLAYER_CONTACT_PLATFORM_SLOT1) + PLATFORM_PATH) && *(s16 *)(*(u8 **)(*(u8 **)(D_802903B0 + PLAYER_CONTACT_PLATFORM_SLOT1) + PLATFORM_PATH) + PLATFORM_PATH_WAIT) == -1) {
            motionLinks = *(u8 **)(*(u8 **)(D_802903B0 + PLAYER_CONTACT_PLATFORM_SLOT1) + PLATFORM_MOTION_LINKS);
            if (motionLinks && motionLinks + PLATFORM_LINK_VELOCITY_TAG) {
                linkedPlatform = (u8 *)func_8017DBD8(&D_802904D4, *(s16 *)(motionLinks + PLATFORM_LINK_VELOCITY_TAG));
                while (linkedPlatform) {
                    *(Vec3F *)(linkedPlatform + PLATFORM_VELOCITY) = **(Vec3F **)(*(u8 **)(D_802903B0 + PLAYER_CONTACT_PLATFORM_SLOT1) + PLATFORM_MOTION_LINKS);
                    if (*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS)) {
                        *(f32 *)(linkedPlatform + PLATFORM_VELOCITY) += *(f32 *)(*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_OFFSET);
                        *(f32 *)(linkedPlatform + PLATFORM_VELOCITY_Y) += *(f32 *)(*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_OFFSET_Y);
                        *(f32 *)(linkedPlatform + PLATFORM_VELOCITY_Z) += *(f32 *)(*(u8 **)(linkedPlatform + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_OFFSET_Z);
                    }
                    linkedPlatform = (u8 *)func_8017DBD8((Unk802904D4Node *)linkedPlatform, *(s16 *)(*(u8 **)(*(u8 **)(D_802903B0 + PLAYER_CONTACT_PLATFORM_SLOT1) + PLATFORM_MOTION_LINKS) + PLATFORM_LINK_VELOCITY_TAG));
                }
            }
        }
    }
}

extern s16 D_801E7462;
s32 func_80133E24(u8 *, f32);
void func_801A87CC(s32);

s32 func_80174B58(void) {
    s32 catchRadius;
    s32 minBallHeight;
    f32 *ballVelocityY;
    f32 *playerPositionY;

    /* Check whether the player can enter or continue catching the ball. */
    if (D_8029F9A4 != 0 && D_8029F9A4 != (s32)&D_802902D8) {
        return 0;
    }
    if (D_8029F468 != 0) {
        return 0;
    }
    if ((s8)D_8029F486 == 1 || (s8)D_8029F486 == 5) {
        return 0;
    }
    if (D_80290300 & PLAYER_CATCH_BLOCKING_FLAG) {
        return 0;
    }
    if (D_8029F9A0 & BALL_CATCH_STATE_CHECK_FLAG) {
        if (((u8 *)D_8029FA4C)[BALL_LANDING_STATE_BYTE_9] != 0) {
            return 0;
        }
        if (D_802903AC[BALL_LANDING_STATE_BYTE_9] == 3) {
            return 0;
        }
    }
    if (*(s16 *)(D_802903AC + BALL_LANDING_ACTION) == PLAYER_ACTION_CATCH_BALL) {
        catchRadius = BALL_CATCH_CONTINUE_RADIUS;
        minBallHeight = 0;
    } else {
        catchRadius = BALL_CATCH_ENTER_RADIUS;
        minBallHeight = BALL_CATCH_MIN_HEIGHT;
    }
    if (D_8029F482 >= BALL_CATCH_PROXIMITY_THRESHOLD) {
        if (func_80148E48((f32 *)&D_8029030C, &D_8029F9AC) < (f64)(D_8029F9A8 + D_80290308) + (f64)catchRadius * *(f64 *)(D_80108328 + BALL_CATCH_RADIUS_SCALE_POOL_OFFSET)) {
            return 1;
        }
    }
    if (D_8029FA50[BALL_LANDING_CONTACT_COUNT] != 0) {
        return 0;
    }
    ballVelocityY = &D_8029F9D4;
    if (!(*ballVelocityY < 0.0f)) {
        return 0;
    }
    playerPositionY = &D_80290310;
    if ((f32)minBallHeight < D_8029F9B0 - *playerPositionY) {
        if (func_80148DB0((u8 *)(playerPositionY - 1), (u8 *)(ballVelocityY - BALL_POSITION_FROM_VELOCITY_Y_FLOATS)) < (f32)catchRadius) {
            return 1;
        }
    }
    return 0;
}

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
/* Animate the orbiting player effects, shrink their fading models, emit trails, and orient the attached effect. */
void func_80174D4C(void) {
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
    extern s32 D_8028FF7C;
    extern s32 D_80290060;
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

    AxisAngle rotationInput;
    QuaternionComponents rotationQuat;
    QuaternionComponents ownerQuat;
    Vec3F offset;
    u8 *transformCursor;
    u8 *orbitBModelOrPosition;
    u8 *owner;
    f32 *yawAxisAngle;
    f64 reducedScaleX, reducedScaleY, reducedScaleZ;
    f32 clampedScaleX, clampedScaleY, clampedScaleZ;
    f32 *scaleX, *scaleY, *scaleZ, *orbitBPositionX;
    s16 *effectType;
    f32 bobAmplitude;

    transformCursor = (u8 *)&D_8028FE98;
    if (*(s32 *)transformCursor != 0) {
        offset.x = D_80108334;
        offset.y = func_80149724((f32)D_801EF464, 0.0f, D_802004E0) * D_80108338 + D_8010833C;
        offset.z = 0.0f;
        func_801490AC(&offset, &offset, -D_8028FE4C);
        D_8028FE04 = *(f32 *)&D_8029030C + offset.x;
        D_8028FE08 = D_80290310 + offset.y;
        D_8028FE0C = D_80290314 + offset.z;
        D_8028FE4C = func_801496C8((f32)((f64)D_8028FE4C + D_80108340));
        func_8015C350(transformCursor - EFFECT_MODEL_TO_QUATERNION, transformCursor - EFFECT_MODEL_TO_EULER);
        if (D_8028F1FC[D_8028FDF0] < ORBIT_A_SHRINK_TIMER) {
            scaleX = (f32 *)(transformCursor - EFFECT_MODEL_TO_SCALE_X);
            reducedScaleX = (f64)*scaleX - D_80108348;
            if (reducedScaleX < 0.0) {
                clampedScaleX = 0.0f;
            } else {
                clampedScaleX = (f32)reducedScaleX;
            }
            *scaleX = clampedScaleX;

            scaleY = &D_8028FE90;
            reducedScaleY = (f64)*scaleY - D_80108350;
            if (reducedScaleY < 0.0) {
                clampedScaleY = 0.0f;
            } else {
                clampedScaleY = (f32)reducedScaleY;
            }
            *scaleY = clampedScaleY;

            scaleZ = &D_8028FE94;
            reducedScaleZ = (f64)*scaleZ - D_80108358;
            if (reducedScaleZ < 0.0) {
                clampedScaleZ = 0.0f;
            } else {
                clampedScaleZ = (f32)reducedScaleZ;
            }
            *scaleZ = clampedScaleZ;
        }
        effectType = &D_8028FDF0;
        if (D_8028F1FC[*effectType] >= ORBIT_PARTICLE_MIN_TIMER && !(D_802004E0 & 1)) {
            offset.x = offset.z = 0.0f;
            offset.y = D_80108360;
            ((void (*)(s16, void *, void *, s32))func_801AE2E8)(ORBIT_TRAIL_PARTICLE_TYPE, (u8 *)effectType + EFFECT_TYPE_TO_POSITION, &offset, *effectType - EFFECT_TYPE_ID_BASE);
        }
    }

    orbitBModelOrPosition = (u8 *)&D_8028FF7C;
    if (*(s32 *)orbitBModelOrPosition != 0) {
        offset.x = D_80108364;
        bobAmplitude = D_80108368;
        offset.y = func_80149724((f32)D_801EF464, 0.0f, D_802004E0) * bobAmplitude + D_8010836C;
        offset.z = 0.0f;
        transformCursor = (u8 *)&offset;
        func_801490AC((Vec3F *)transformCursor, (Vec3F *)transformCursor, -D_8028FF30);
        *(orbitBPositionX = (f32 *)(orbitBModelOrPosition - EFFECT_MODEL_TO_POSITION)) = *(f32 *)&D_8029030C + offset.x;
        D_8028FEEC = D_80290310 + offset.y;
        D_8028FEF0 = D_80290314 + offset.z;
        D_8028FF30 = func_801496C8((f32)((f64)D_8028FF30 - D_80108370));
        func_8015C350(orbitBModelOrPosition - EFFECT_MODEL_TO_QUATERNION, orbitBModelOrPosition - EFFECT_MODEL_TO_EULER);
        orbitBModelOrPosition -= EFFECT_MODEL_TO_POSITION;
        if (D_8028F1FC[D_8028FED4] < ORBIT_B_SHRINK_TIMER) {
            D_8028FF70 = (f32)((f64)D_8028FF70 - D_80108378);
            D_8028FF74 = (f32)((f64)D_8028FF74 - D_80108378);
            D_8028FF78 = (f32)((f64)D_8028FF78 - D_80108378);
        }
        if (D_8028F1FC[D_8028FED4] >= ORBIT_PARTICLE_MIN_TIMER && !(D_802004E0 & 1)) {
            offset.x = offset.z = 0.0f;
            offset.y = bobAmplitude;
            ((void (*)(s16, void *, void *, s32))func_801AE2E8)(ORBIT_TRAIL_PARTICLE_TYPE, orbitBModelOrPosition, transformCursor, D_8028FED4 - EFFECT_TYPE_ID_BASE);
        }
    }

    if (D_80290060 != 0) {
        owner = D_8028FFC4[0];
        offset.x = 0.0f;
        if (owner == (u8 *)&D_802902D8) {
            offset.y = D_80108380;
            offset.z = D_80108384;
        } else {
            offset.y = D_80108388;
            offset.z = D_8010838C;
        }
        func_8014915C(&offset, &offset, *(f32 *)(owner + OBJECT_PITCH_OFFSET), ROTATION_AXIS_X);
        func_801490AC(&offset, &offset, *(f32 *)(owner + OBJECT_YAW_OFFSET));
        ((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)(&D_8028FFCC, (f32 *)(owner + OBJECT_POSITION_OFFSET), (f32 *)&offset, -22.0f);
        D_80290014 = func_801496C8(D_80290014 - D_802900E4);
        rotationInput[0] = D_80108390;
        rotationInput[1] = 0.0f;
        rotationInput[2] = 0.0f;
        if (owner == (u8 *)&D_802902D8) {
            rotationInput[3] = (f32)((f64)D_80290350 + *(const f64 *)((const u8 *)&D_80108390 + 4));
        } else {
            rotationInput[3] = *(f32 *)(owner + OBJECT_PITCH_OFFSET);
        }
        func_80148C3C(rotationQuat, rotationInput);
        yawAxisAngle = &D_801ED3EC;
        *yawAxisAngle = *(f32 *)(owner + OBJECT_YAW_OFFSET);
        func_80148C3C(rotationInput, yawAxisAngle - 3);
        func_801488C0((Quaternion *)ownerQuat, rotationInput, rotationQuat);
        offset.x = 0.0f;
        offset.y = D_8010839C;
        offset.z = 0.0f;
        func_8014915C(&offset, &offset, *(f32 *)(owner + OBJECT_PITCH_OFFSET), ROTATION_AXIS_X);
        func_801490AC(&offset, &offset, *(f32 *)(owner + OBJECT_YAW_OFFSET));
        rotationInput[0] = offset.x;
        rotationInput[1] = offset.y;
        rotationInput[2] = offset.z;
        transformCursor = (u8 *)&D_80290014;
        rotationInput[3] = *(f32 *)transformCursor - *(f32 *)(owner + OBJECT_YAW_OFFSET);
        func_80148C3C(rotationQuat, rotationInput);
        func_801488C0((Quaternion *)(transformCursor + EFFECT_YAW_TO_QUATERNION), rotationQuat, ownerQuat);
    }
}

/* Set a player float (callers pass a radius/speed field of D_802903B0) to
 * baseValue scaled by the level's physics scale D_801EEC40 over the reference
 * scale D_801083A0. When D_802901AC is set it is also scaled by the player's
 * X scale D_80290394 (or D_801EEC3C when that is zero). Level 0x28 (D_801E7531)
 * leaves the value untouched. */
void func_80175388(u8 *out, f32 baseValue) {
    f32 scale;
    f32 value;
    f64 refScale;

    if (D_801E7531 != 0x28) {
        value = baseValue;
        refScale = D_801083A0;
        value = value * D_801EEC40 / refScale;
        *(f32 *)out = value;
        if (D_802901AC != 0) {
            scale = D_80290394;
            if (scale == 0.0f) {
                scale = D_801EEC3C;
            }
            *(f32 *)out = value * (scale / refScale);
        }
    }
}

/* Pushes an object (e.g. the ball, D_8029F978) away from the player: it takes
 * the player's velocity (D_80290330), is accelerated along the player's yaw by
 * 5.25 (D_801083A8) * playerMass / objectMass (func_80160B6C), gets twice that
 * as upward speed, then has its speed capped at its maximum (func_80160728).
 * Physics parameters: D_802903A8 (player) and object + 0xD0: [0] mass, [2] max speed. */
void func_8017541C(u8 *object) {
    extern u8 D_80290330[];
    extern f32 *D_802903A8;
    extern f32 D_801083A8;
    void func_80160B6C(u8 *, void *, f32, f32);
    f32 push;
    f32 massRatio;

    *(Vec3F *)(object + 0x58) = *(Vec3F *)D_80290330;
    massRatio = *D_802903A8 / **(f32 **)(object + 0xD0);
    push = massRatio * (push = D_801083A8);
    func_80160B6C(D_80290330 - 0x58, object, push, (*(f32 **)(object + 0xD0))[2]);
    *(f32 *)(object + 0x5C) = push + push;
    func_80160728(object, (*(f32 **)(object + 0xD0))[2]);
}

/* Throws an object (the ball) from the player: starts it with the player's
 * velocity, sets an upward speed of playerParam * 5.25 / objParam, then pushes
 * it along the player's yaw by playerParam * 14.0 / objParam, capped at the
 * object's speed limit (physics parameter [2]). */
void func_801754C0(u8 *obj) {
    extern u8 D_80290330[];   /* player velocity XYZ (player object + 0x58) */
    extern f32 *D_802903A8;   /* player physics parameters */
    extern f64 D_801083AC;    /* 5.25: throw lift factor */
    extern f64 D_801083B4;    /* 14.0: throw push factor */
    void func_80160B6C(u8 *, void *, f32, f32);
    double playerParam;
    double objParam;
    f32 lift;
    f32 push;

    *(Vec3F *)(obj + 0x58) = *(Vec3F *)D_80290330;
    playerParam = *D_802903A8;
    objParam = **(f32 **)(obj + 0xD0);
    lift = playerParam * D_801083AC / objParam;
    push = playerParam * D_801083B4 / objParam;
    *(f32 *)(obj + 0x5C) = lift;
    func_80160B6C(D_80290330 - 0x58, obj, push, (*(f32 **)(obj + 0xD0))[2]);
}

/* Spawn the player's tracked trail particle with ball physics, collision radii and state-dependent color. */
void func_80175560(void) {
    extern volatile s32 D_802900F0;
    extern u8 *volatile D_8029FA50;
    BallTrailPhysicsChunk *particlePhysics;
    BallTrailPhysicsChunk *ballPhysics;
    BallTrailPhysicsChunk *ballPhysicsEnd;
    s32 particleAddress;

    particleAddress = func_801B66D4(PARTICLE_TRAIL_SOURCE, &D_8029F9AC, &D_801ED3C4, 0, 0);
    D_802900F0 = particleAddress;
    if (particleAddress == 0) {
        return;
    }
    particlePhysics = *(BallTrailPhysicsChunk **)(D_802900F0 + PARTICLE_PHYSICS_OFFSET);
    ballPhysics = (BallTrailPhysicsChunk *)D_8029FA48;
    ballPhysicsEnd = (BallTrailPhysicsChunk *)((u8 *)D_8029FA48 + BALL_TRAIL_PHYSICS_BYTES);
    do {
        *particlePhysics++ = *ballPhysics++;
    } while (ballPhysics != ballPhysicsEnd);
    if (D_801EF468 != 0) {
        *(s32 *)(D_802900F0 + PARTICLE_FLAGS_OFFSET) = D_8029F9A0 | BALL_TRAIL_OPTIONAL_FLAG;
    } else {
        *(s32 *)(D_802900F0 + PARTICLE_FLAGS_OFFSET) = D_8029F9A0;
    }
    {
        s32 *flags = (s32 *)(D_802900F0 + PARTICLE_FLAGS_OFFSET);
        *flags &= ~8;
    }
    {
        s32 *flags = (s32 *)(D_802900F0 + PARTICLE_FLAGS_OFFSET);
        *flags |= BALL_TRAIL_REQUIRED_FLAG;
    }
    *(s32 *)(D_802900F0 + BALL_TRAIL_OWNER_OFFSET) = (s32)&D_802902D8;
    *(f32 *)(*(s32 *)(D_802900F0 + PARTICLE_COLLISION_OFFSET) + PARTICLE_COLLISION_RADIUS_OFFSET) = ((BallTrailCollisionRadii *)D_8029FA50)->radius;
    *(f32 *)(*(s32 *)(D_802900F0 + PARTICLE_COLLISION_OFFSET) + PARTICLE_COLLISION_TARGET_RADIUS_OFFSET) = ((BallTrailCollisionRadii *)D_8029FA50)->targetRadius;
    *(f32 *)(D_802900F0 + PARTICLE_RESPONSE_OFFSET) = D_8029F9E8;
    if (*(s16 *)(D_802903AC + BALL_TRAIL_PLAYER_STATE_OFFSET) == BALL_TRAIL_ORANGE_PLAYER_STATE) {
        *(u8 *)(D_802900F0 + PARTICLE_RED_OFFSET) = D_801EF46C;
        *(u8 *)(D_802900F0 + PARTICLE_GREEN_OFFSET) = D_801EF46D;
        *(u8 *)(D_802900F0 + PARTICLE_BLUE_OFFSET) = D_801EF46E;
    } else {
        *(u8 *)(D_802900F0 + PARTICLE_RED_OFFSET) = D_801EF46F;
        *(u8 *)(D_802900F0 + PARTICLE_GREEN_OFFSET) = D_801EF470;
        *(u8 *)(D_802900F0 + PARTICLE_BLUE_OFFSET) = D_801EF471;
    }
}

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

/* Enter or sustain slope sliding when the contact normal exceeds the material's slope limit. */
void func_8017574C(f32 *contactPlane) {
    f32 playerDisplacement[3];
    f32 surfaceSlopeFactor;

    if (!(*(f32 *)(D_801ED75C + ((u8 *)contactPlane)[TRI_SURFACE_TYPE] * SURFACE_PARAMETER_STRIDE) < D_801083BC)) {
        playerDisplacement[0] = *(f32 *)&D_8029030C - D_80290318;
        playerDisplacement[1] = D_80290310 - D_8029031C;
        playerDisplacement[2] = D_80290314 - D_80290320;
        surfaceSlopeFactor = *(f32 *)(D_801ED764 + ((u8 *)contactPlane)[TRI_SURFACE_TYPE] * SURFACE_PARAMETER_STRIDE);
        if (contactPlane[TRI_NORMAL_Y] <= (f32)(D_801083C8 - D_801083C0 / surfaceSlopeFactor)) {
            if (*(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) == PLAYER_STATE_SLOPE_SLIDE) {
                D_8028FBD8 = 1;
            } else {
                if (contactPlane[TRI_NORMAL_Y] <= D_801EF474 / surfaceSlopeFactor) {
                    D_80290148 = 0;
                } else {
                    D_80290148 = 1;
                }
                if (contactPlane[TRI_NORMAL_Y] > D_801EF474) {
                    D_80290108 = 0;
                } else {
                    D_80290108 = 1;
                }
                func_80167604(PLAYER_STATE_SLOPE_SLIDE);
            }
        }
    }
}

void func_801758D0(s32 resetEffects) {
    /* Initialize player physics and orientation, optionally resetting effects and robot collision attachments. */
    typedef struct { u8 *p; } WrapP;
    extern s16 D_802902F8;
    extern s32 D_801EEBD0;
    extern s32 D_801EEBD4;
    extern QuaternionWords D_801EEBD8;
    extern u8 D_801083D0[];
    extern u8 D_801083DC[];
    extern u8 D_801083EC[];
    extern u8 D_801083F8[];
    extern u8 D_80108404[];
    extern u8 D_80108410[];
    extern u8 D_8010841C[];
    extern s32 D_8028FBB8[];
    extern u8 *volatile D_802903A8;
    extern u8 *D_802903A0;
    extern f32 D_8010842C;
    extern f32 D_80108430;
    extern f32 D_80108434;
    extern f32 D_80108438;
    extern f32 D_8010843C;
    extern f32 D_80108440;
    extern f64 D_80108444;
    extern f64 D_8010844C;
    extern f64 D_80108454;
    extern f32 D_8010845C;
    extern f32 D_80108460;
    extern f32 D_80108464;
    extern f32 D_80108468;
    extern f32 D_8010846C;
    extern f32 D_80108470;
    extern f32 D_80108474;
    extern f32 D_80108478;
    extern f32 D_8010847C;
    extern f32 D_80108480;
    extern f32 D_80108484;
    extern u8 D_802902FA;
    extern f32 D_80290364;
    extern f32 D_80290358;
    extern f32 D_8029035C;
    extern f32 D_80290338;
    extern f32 D_80290334;
    extern f32 D_80290330;
    extern s32 D_80290140[];
    extern s32 D_80290144;
    extern f32 *D_8028FDC4;
    extern f32 D_8028FD1C;
    extern s32 D_802901E8;
    extern s32 D_802901E4;
    extern s16 D_8028FBEE;
    extern QuaternionWords D_80290374;
    extern ObjectPhysicsWords D_801EE4D0;
    u8 assetName[0x10];
    f32 defaultPhysicsValue;
    f32 defaultObjectFactor;
    u8 *component;
    f32 *contactRadius;

#define C(s) ((*(WrapP *)&(s)).p)
#define F(p, o) (*(f32 *)((u32)(p) + (o)))
#define B(p, o) (*(u8 *)((u32)(p) + (o)))
    D_801EEBD8 = *(QuaternionWords *)&D_801ED3D0;
    D_802902F8 = 1;
    D_801EEBD0 = 0;
    D_801EEBD4 = 0;
    func_801D2150(assetName, D_801083D0);
    func_8014FCF8(&D_8028FBB8[0], func_80139CA0(assetName), 1);
    func_801D2150(assetName, D_801083DC);
    func_8014FCF8(&D_8028FBB8[1], func_80139CA0(assetName), 1);
    func_8013FBC0(D_802903A8, PLAYER_PHYSICS_SIZE);
    defaultObjectFactor = D_8010842C;
    D_80290348 = defaultObjectFactor;
    F(D_802903A8, 0x2C) = D_80108430;
    F(D_802903A8, 0x1C) = D_80108434;
    F(D_802903A8, 0x4C) = D_80108438;
    D_8028FBCC = defaultObjectFactor;
    B(D_802903A8, 0x25) = 1;
    B(D_802903A8, 0x24) = 1;
    D_80290300 = PLAYER_NORMAL_OBJECT_FLAGS;
    D_80290350 = D_8029035C = D_80290358 = D_80290364 = 0.0f;
    if (D_801E7531 == 0x13) {
        D_801EEC40 = D_8010843C;
    } else {
        D_801EEC40 = D_80108440;
    }
    { u8 *collision = D_802903B0; F(collision, PLAYER_COLLISION_RADIUS_OFFSET) = F(collision, PLAYER_COLLISION_TARGET_RADIUS_OFFSET) = D_801EEC40 * D_80108444 / D_8010844C; }
    defaultPhysicsValue = D_8010845C;
    contactRadius = (f32 *)(D_802903A4 + PLAYER_CONTACT_RADIUS_OFFSET);
    *contactRadius = F(C(D_802903B0), PLAYER_COLLISION_RADIUS_OFFSET) * D_80108454;
    *(f32 *)C(D_802903A4) = D_80108460;
    F(D_802903A8, 0x28) = D_80108464;
    F(D_802903A8, 0x8) = D_80108468;
    F(D_802903A8, 0xC) = D_8010846C;
    F(D_802903A8, 0x18) = D_80108470;
    F(D_802903A8, 0x10) = D_80108474;
    F(D_802903A8, 0x14) = D_80108478;
    component = D_802903A8;
    D_802902FA = 1;
    F(component, 0) = defaultPhysicsValue;
    if (resetEffects != 0) {
        D_80290140[0] = 0;
        D_80290144 = 0;
        *(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) = 0;
        *(s16 *)(C(D_802903AC) + PLAYER_STATE_PREVIOUS_OFFSET) = 0;
        func_8013FBC0((u8 *)D_80290140 - PLAYER_EFFECT_STATE_TO_HANDLES, PLAYER_EFFECT_STATE_SIZE);
        D_8028FBEE = 0;
        func_8013FBC0((u8 *)D_80290140 - PLAYER_FIRST_EFFECT_TO_HANDLES, PLAYER_EFFECT_OBJECT_SIZE);
        func_80142700((u8 *)D_80290140 - PLAYER_FIRST_EFFECT_TO_HANDLES, PLAYER_EFFECT_PHYSICS);
        func_8013FBC0((u8 *)D_80290140 - PLAYER_SECOND_EFFECT_TO_HANDLES, PLAYER_EFFECT_OBJECT_SIZE);
        func_80142700((u8 *)D_80290140 - PLAYER_SECOND_EFFECT_TO_HANDLES, PLAYER_EFFECT_PHYSICS_AND_COLLISION);
        F(D_8028FDC4, PLAYER_COLLISION_RADIUS_OFFSET) = defaultPhysicsValue;
        F(D_8028FDC4, PLAYER_COLLISION_TARGET_RADIUS_OFFSET) = defaultPhysicsValue;
        D_8028FD1C = defaultPhysicsValue;
        if (D_801E7531 == PLAYER_ROBOT_LEVEL) {
            func_80167604(PLAYER_ROBOT_INITIAL_STATE);
            *(ObjectPhysicsWords *)D_802903A8 = D_801EE4D0;
            { u8 *collision = D_802903B0; F(collision, PLAYER_COLLISION_RADIUS_OFFSET) = F(collision, PLAYER_COLLISION_TARGET_RADIUS_OFFSET) = F(D_802903A8, 0x48) = D_8010847C; }
            F(D_802903A8, 0) = D_80108480;
            D_8028FBEE = PLAYER_ROBOT_MODE;
            D_80290348 = D_8028FBCC = D_80108484;
            F(D_802903A8, 0x18) = D_80108484;
            component = (u8 *)func_80152220(*(u8 **)(D_802903A0 + PLAYER_MODEL_ROOT_OFFSET), func_80139CA0(D_801083EC));
            *(u8 **)(component + PLAYER_MODEL_ATTACHMENT_OFFSET) = D_802903B0 + PLAYER_ROBOT_RIGHT_FOOT_SPHERE_OFFSET;
            *(s16 *)(C(D_802903B0) + PLAYER_ROBOT_RIGHT_FOOT_FLAGS_OFFSET) = PLAYER_ROBOT_SPHERE_FLAGS;
            component = (u8 *)func_80152220(*(u8 **)(D_802903A0 + PLAYER_MODEL_ROOT_OFFSET), func_80139CA0(D_801083F8));
            *(u8 **)(component + PLAYER_MODEL_ATTACHMENT_OFFSET) = D_802903B0 + PLAYER_ROBOT_LEFT_FOOT_SPHERE_OFFSET;
            *(s16 *)(((WrapP *)&D_802903A0)[4].p + PLAYER_ROBOT_LEFT_FOOT_FLAGS_OFFSET) = PLAYER_ROBOT_SPHERE_FLAGS;
            component = (u8 *)func_80152220(*(u8 **)(D_802903A0 + PLAYER_MODEL_ROOT_OFFSET), func_80139CA0(D_80108404));
            *(u8 **)(component + PLAYER_MODEL_ATTACHMENT_OFFSET) = D_802903B0 + PLAYER_ROBOT_SAC_SPHERE_OFFSET;
            *(s16 *)(((WrapP *)&D_802903A4)[3].p + PLAYER_ROBOT_SAC_FLAGS_OFFSET) = PLAYER_ROBOT_SPHERE_FLAGS;
            component = (u8 *)func_80152220(*(u8 **)(D_802903A0 + PLAYER_MODEL_ROOT_OFFSET), func_80139CA0(D_80108410));
            *(u8 **)(component + PLAYER_MODEL_ATTACHMENT_OFFSET) = D_802903B0 + PLAYER_ROBOT_HEAD_SPHERE_OFFSET;
            *(s16 *)(((WrapP *)&D_802903AC)[1].p + PLAYER_ROBOT_HEAD_FLAGS_OFFSET) = PLAYER_ROBOT_SPHERE_FLAGS;
            *(u16 *)((u8 *)func_80152220(*(u8 **)(D_802903A0 + PLAYER_MODEL_ROOT_OFFSET), func_80139CA0(D_8010841C)) + PLAYER_MODEL_FLAGS_OFFSET) |= PLAYER_ROBOT_LIGHT_FLAG;
            D_80290300 = PLAYER_ROBOT_OBJECT_FLAGS;
            D_80290350 = D_80290354 = D_80290358 = D_80290330 = D_80290334 = D_80290338 = 0.0f;
            do { D_80290374 = *(QuaternionWords *)&D_801ED3D0; } while (0);
        }
    }
    D_802901E8 = PLAYER_INITIAL_ACTION;
    D_802901E4 = PLAYER_INITIAL_ACTION;
    func_8015C350((u8 *)&D_80290374, (u8 *)&D_80290374 - PLAYER_QUATERNION_TO_EULER);
#undef C
#undef F
#undef B
}

/* Follow the attached actor's animated transform and inherit its velocity. */
void func_80175EC0(void)
{
  extern u8 *D_80290304;
  extern f32 D_80108488;
  extern f32 D_8010848C;
  extern f32 D_80108490;
  extern f32 D_80108494;
  extern f32 D_80108498;
  extern f64 D_8010849C;
  extern f32 D_801084A4;
  extern f64 D_801084A8;
  extern u8 D_80299964[];
  extern s16 D_8028FBEA;
  extern f32 D_80290310;
  extern f32 D_80290314;
  extern Vec3F D_80290330;
  u8 *transformTracks;
  f32 sampleFrame;
  f32 fraction;
  f32 translationY;
  f32 scaleY;
  s32 keyIndex;
  s32 nextKey;
  s32 previousKey;
  s32 frameSpan;
  s16 firstKey;
  s16 lastKey;
  s32 lowAttachmentHeight;
  Vec3F attachmentPosition;
  Vec3F positionDelta;
  f32 rotationQuaternion[4];
  f32 *playerPositionX;
  transformTracks = *((u8 **) ((*((u8 **) (D_80290304 + ACTOR_MESH))) + ACTOR_MESH_ROOT));
  sampleFrame = (*((f32 *) ((*((u8 **) (D_80290304 + ACTOR_ANIMATION))) + ANIM_PLAYBACK_FRAME))) + (*((f32 *) ((*((u8 **) (D_80290304 + ACTOR_ANIMATION))) + ANIM_PLAYBACK_SPEED)));
  previousKey = -1;
  nextKey = -1;
  if ((*((s16 *) (transformTracks + ANIM_TRANSLATION_KEY_COUNT))) >= 2)
  {
    for (keyIndex = 0; keyIndex < (*((s16 *) (transformTracks + ANIM_TRANSLATION_KEY_COUNT))); keyIndex++)
    {
      if (sampleFrame < ((f32) (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[keyIndex].frame))
      {
        nextKey = keyIndex;
        previousKey = nextKey - 1;
        break;
      }
    }

    if (previousKey != (-1))
    {
      frameSpan = (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[nextKey].frame - (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[previousKey].frame;
      fraction = (f32) abs(frameSpan);
      fraction = (sampleFrame - (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[previousKey].frame) / fraction;
    }
    else
    {
      previousKey = (nextKey = (*((s16 *) (transformTracks + ANIM_TRANSLATION_KEY_COUNT))) - 1);
      fraction = D_80108488;
    }
    translationY = (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[previousKey].components[1] + (((*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[nextKey].components[1] - (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[previousKey].components[1]) * fraction);
  }
  else
  {
    translationY = (*((AnimationTransformKey **) (transformTracks + ANIM_TRANSLATION_KEYS)))[0].components[1];
  }
  if ((*((s16 *) (transformTracks + ANIM_SCALE_KEY_COUNT))) >= 2)
  {
    nextKey = -1;
    previousKey = -1;
    for (keyIndex = 0; keyIndex < (*((s16 *) (transformTracks + ANIM_SCALE_KEY_COUNT))); keyIndex++)
    {
      if (sampleFrame < ((f32) (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[keyIndex].frame))
      {
        nextKey = keyIndex;
        previousKey = nextKey - 1;
        break;
      }
    }

    if (previousKey != (-1))
    {
      frameSpan = (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[nextKey].frame - (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[previousKey].frame;
      fraction = (f32) abs(frameSpan);
      fraction = (sampleFrame - (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[previousKey].frame) / fraction;
    }
    else
    {
      previousKey = (nextKey = (*((s16 *) (transformTracks + ANIM_SCALE_KEY_COUNT))) - 1);
      fraction = D_8010848C;
    }
    scaleY = (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[previousKey].components[1] + (((*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[nextKey].components[1] - (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[previousKey].components[1]) * fraction);
  }
  else
  {
    scaleY = (*((AnimationTransformKey **) (transformTracks + ANIM_SCALE_KEYS)))[0].components[1];
  }
  if ((*((s16 *) (transformTracks + ANIM_ROTATION_KEY_COUNT))) >= 2)
  {
    nextKey = -1;
    previousKey = -1;
    lastKey = (*((s16 *) (transformTracks + ANIM_ROTATION_KEY_COUNT))) - 1;
    firstKey = 0;
    while (firstKey <= lastKey)
    {
      keyIndex = (firstKey + lastKey) >> 1;
      if (((f32) (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[keyIndex].frame) == sampleFrame)
      {
        break;
      }
      if (sampleFrame < ((f32) (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[keyIndex].frame))
      {
        lastKey = keyIndex - 1;
      }
      else
      {
        firstKey = keyIndex + 1;
      }
    }

    if (firstKey > 0)
    {
      firstKey--;
    }
    for (keyIndex = firstKey; keyIndex < (*((s16 *) (transformTracks + ANIM_ROTATION_KEY_COUNT))); keyIndex++)
    {
      if (sampleFrame < ((f32) (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[keyIndex].frame))
      {
        nextKey = keyIndex;
        previousKey = nextKey - 1;
        break;
      }
    }

    if (previousKey != (-1))
    {
      frameSpan = (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[nextKey].frame - (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[previousKey].frame;
      fraction = (f32) abs(frameSpan);
      fraction = (sampleFrame - (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[previousKey].frame) / fraction;
    }
    else
    {
      previousKey = (nextKey = (*((s16 *) (transformTracks + ANIM_ROTATION_KEY_COUNT))) - 1);
      fraction = D_80108490;
    }
    func_80147704((*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[previousKey].components, (*((AnimationTransformKey **) (transformTracks + ANIM_ROTATION_KEYS)))[nextKey].components, fraction, rotationQuaternion);
  }
  do
  {
    lowAttachmentHeight = (*((s32 *) (&D_80299964[(*((s8 *) ((*((u8 **) (D_80290304 + ACTOR_TYPE_DATA))) + ACTOR_TYPE_SLOT))) * ACTOR_INSTANCE_STRIDE]))) & PLAYER_ATTACHMENT_LOW_HEIGHT;
  }
  while (0);
  {
    f32 normalHeight = D_80108494;
    f32 scaledHeight;
    if (lowAttachmentHeight)
    {
      scaledHeight = scaleY * D_80108498;
    }
    else
    {
      scaledHeight = scaleY * normalHeight;
    }
    if (D_8010849C == D_8010849C)
    {
      attachmentPosition.y = scaledHeight + (translationY * D_8010849C);
    }
    else
    {
      attachmentPosition.y = scaledHeight + (translationY * D_8010849C);
    }
  }
  do
  {
  }
  while (0);
  attachmentPosition.x = 0.0f;
  attachmentPosition.z = D_801084A4;
  func_801499A0((s32) (&attachmentPosition), (s32) (&attachmentPosition), (s32) rotationQuaternion);
  func_801490AC(&attachmentPosition, &attachmentPosition, D_80290354);
  attachmentPosition.x += *((f32 *) (D_80290304 + ACTOR_POSITION));
  attachmentPosition.y += *((f32 *) (D_80290304 + ACTOR_POSITION_Y));
  attachmentPosition.z += *((f32 *) (D_80290304 + ACTOR_POSITION_Z));
  {
    f32 dx = attachmentPosition.x - (*((f32 *) (&D_8029030C)));
    f32 dy = attachmentPosition.y - D_80290310;
    f32 dz = attachmentPosition.z - D_80290314;
    positionDelta.x = dx;
    positionDelta.y = dy;
    positionDelta.z = dz;
    if (D_8028FBEA < PLAYER_ATTACHMENT_BLEND_FRAMES)
    {
      positionDelta.x = dx * D_801084A8;
      positionDelta.y = dy * D_801084A8;
      positionDelta.z = dz * D_801084A8;
    }
    else
    {
      positionDelta.x = dx;
      positionDelta.y = dy;
      positionDelta.z = dz;
    }
  }
  playerPositionX = (f32 *) (&D_8029030C);
  *playerPositionX += positionDelta.x;
  D_80290310 += positionDelta.y;
  D_80290314 += positionDelta.z;
  D_80290330 = *((Vec3F *) (D_80290304 + ACTOR_VELOCITY));
}

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

/* Detach the player from an actor, restore its script, and kick the player backward and upward. */
void func_801764A8(void) {
    u8 *animation;
    s32 *attachmentActor;
    u8 *playerVelocityY;
    f32 launchVelocityY;

    if (*(s16 *)(D_80299708 + *(s8 *)(*(u8 **)(D_802900C8 + CONTACT_OBJECT_STATE_OFFSET) + CONTACT_STATE_ACTOR_INDEX) * ACTOR_INSTANCE_STRIDE) == PLAYER_DETACH_TYPE29) {
        func_80197794(D_802996E8 + *(s8 *)(*(u8 **)(D_802900C8 + CONTACT_OBJECT_STATE_OFFSET) + CONTACT_STATE_ACTOR_INDEX) * ACTOR_INSTANCE_STRIDE, PLAYER_DETACH_TYPE29_INSTRUCTION, 0);
    } else {
        func_80197794(D_802996E8 + *(s8 *)(*(u8 **)(D_802900C8 + CONTACT_OBJECT_STATE_OFFSET) + CONTACT_STATE_ACTOR_INDEX) * ACTOR_INSTANCE_STRIDE, PLAYER_DETACH_DEFAULT_INSTRUCTION, 0);
    }
    *(s16 *)((u8 *)&D_80299960 + *(s8 *)(*(u8 **)((u8 *)D_802900C8 + CONTACT_OBJECT_STATE_OFFSET) + CONTACT_STATE_ACTOR_INDEX) * ACTOR_INSTANCE_STRIDE) = 0;
    *(s16 *)((u8 *)&D_80299930 + *(s8 *)(*(u8 **)((u8 *)D_802900C8 + CONTACT_OBJECT_STATE_OFFSET) + CONTACT_STATE_ACTOR_INDEX) * ACTOR_INSTANCE_STRIDE) = PLAYER_DETACH_ACTOR_COOLDOWN;
    if (*(s16 *)((u8 *)D_802900C8 + ACTOR_TYPE) == PLAYER_DETACH_TYPE16) {
        animation = *(u8 **)((u8 *)D_802900C8 + ACTOR_ANIMATION);
        if (*(s16 *)(animation + ANIM_CURRENT_OFFSET) == PLAYER_DETACH_TYPE16_ANIMATION) {
            *(f32 *)(animation + ANIM_PLAYBACK_SPEED) = *(f32 *)(*(u8 **)(animation + ANIM_PLAYBACK_CLIPS) + ANIM_CLIP15_SPEED_OFFSET);
        } else {
            *(f32 *)(animation + ANIM_FIRST_QUEUED_SPEED_OFFSET) = *(f32 *)(*(u8 **)(animation + ANIM_PLAYBACK_CLIPS) + ANIM_CLIP15_SPEED_OFFSET);
        }
    } else if (*(s16 *)((u8 *)D_802900C8 + ACTOR_TYPE) == PLAYER_DETACH_TYPE29) {
        func_80133998((void *)*(attachmentActor = &D_802900C8), PLAYER_DETACH_TYPE29_ANIMATION, 1, 0, 0);
    }
    D_8028FBFB = 5;
    D_802900C8 = 0;
    D_8028FBEE = 0;
    func_80167604(PLAYER_STATE_FALL);
    *(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) = PLAYER_DETACH_STATE;
    playerVelocityY = (u8 *)&D_80290334;
    *(f32 *)playerVelocityY = *(f32 *)playerVelocityY * D_801084B0;
    func_8016049C(playerVelocityY - PLAYER_DETACH_Y_VELOCITY_TO_OBJECT, -10.0f, *(f32 *)(D_802903A8 + PLAYER_PHYSICS_HORIZONTAL_SPEED_LIMIT));
    launchVelocityY = D_801084B8;
    D_801FAAC8[D_80202218 * PLAYER_DETACH_CONTROLLER_STRIDE] = 0;
    D_8028FAC8 = playerVelocityY - PLAYER_DETACH_Y_VELOCITY_TO_POSITION;
    D_8028FAD0 = playerVelocityY - PLAYER_DETACH_Y_VELOCITY_TO_VELOCITY;
    *(f32 *)playerVelocityY = launchVelocityY;
    D_80290300 |= PLAYER_DETACH_OBJECT_FLAG;
}

/* Enter player action 2 with sub-state 9: damp the player's Y velocity
 * (D_80290334) by D_801084BC, push the player back along its yaw (-10, capped
 * at the physics speed limit), and clear the active controller's D_801FAAC8 byte. */
void func_801766C0(void) {
    u8 *velocityY;

    func_80167604(2);
    *(s16 *)(D_802903AC + 4) = 9;
    velocityY = (u8 *)&D_80290334;
    *(f32 *)velocityY = *(f32 *)velocityY * D_801084BC;
    func_8016049C(velocityY - 0x5C, -10.0f, *(f32 *)(D_802903A8 + 8));
    D_801FAAC8[D_80202218 * 400] = 0;
}

extern s16 D_8029011C;
extern u8 *D_802903A0;
extern u8 *D_802903A4;
extern u8 *D_802903A8;
extern u8 *D_802903AC;
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

extern ObjectPhysicsWords D_801EEB10;
/* Shrink, swap and regrow the player when entering or leaving frog form. */
void func_80176758(void) {
    s16 *isFrog = &D_8029011E;
    u8 *collision;
    s16 *actionTimer;

    if (*isFrog != 0) {
        if (D_8029011C < ACTOR_TRANSFORM_RETURN_FRAMES) {
            (*(ObjectScaleField *)&D_80290394).value *= *(f64 *)(D_801084C0 + 4); D_80290398 *= *(f64 *)(D_801084C0 + 4); D_8029039C *= *(f64 *)(D_801084C0 + 4); if ((*(ObjectScaleField *)&D_80290394).value <= *(f64 *)(D_801084C8 + 4)) {
                func_80176AFC();
            }
        } else {
            if ((*(ObjectScaleField *)&D_80290394).value < (f64)D_801F00A0 - *(f64 *)(D_801084D0 + 4)) {
                (*(ObjectScaleField *)&D_80290394).value += (D_801F00A0 - (*(ObjectScaleField *)&D_80290394).value) / D_801084DC;
                D_80290398 = (*(ObjectScaleField *)&D_80290394).value;
                D_8029039C = (*(ObjectScaleField *)&D_80290394).value;
            } else {
                D_8029039C = D_801F00A0;
                D_80290398 = D_801F00A0;
                (*(ObjectScaleField *)&D_80290394).value = D_801F00A0;
            }
        }
    } else {
        if (D_8029011C < ACTOR_TRANSFORM_RETURN_FRAMES) {
            if ((*(ObjectScaleField *)&D_80290394).value < D_801084E0) {
                (*(ObjectScaleField *)&D_80290394).value += (D_801084E8 - (*(ObjectScaleField *)&D_80290394).value) / D_801084F0;
                D_80290398 = (*(ObjectScaleField *)&D_80290394).value;
                D_8029039C = (*(ObjectScaleField *)&D_80290394).value;
            } else {
                D_8029011C = ACTOR_TRANSFORM_FINISH_TIMER;
                D_8029039C = D_801084F8;
                D_80290398 = D_801084F8;
                (*(ObjectScaleField *)&D_80290394).value = D_801084F8;
            }
        } else {
            (*(ObjectScaleField *)&D_80290394).value *= *(f64 *)((u8 *)&D_801084F8 + 4); D_80290398 *= *(f64 *)((u8 *)&D_801084F8 + 4); D_8029039C *= *(f64 *)((u8 *)&D_801084F8 + 4); if ((*(ObjectScaleField *)&D_80290394).value <= *(f64 *)(D_80108500 + 4)) {
                func_8015CB44((u8 *)&D_80290394 - PLAYER_OBJECT_SCALE_X_OFFSET);
                *isFrog = 1;
                D_802903A0 = (u8 *)D_802996E4;
                func_8014D61C(0, PLAYER_FROG_FLASH_GREEN, 0, PLAYER_FROG_FLASH_ALPHA, PLAYER_FROG_FLASH_ALPHA_STEP);
                *(ObjectPhysicsWords *)D_802903A8 = D_801EEB10;
                *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_RESPONSE_OFFSET) = D_8028FBCC;
                D_80290300 = *(s32 *)(D_802903A8 + PLAYER_PHYSICS_FLAGS_OFFSET);
                collision = D_802903B0;
                *(f32 *)(collision + PLAYER_COLLISION_RADIUS_OFFSET) = *(f32 *)(collision + PLAYER_COLLISION_TARGET_RADIUS_OFFSET) = *(f32 *)(D_802903A8 + PLAYER_PHYSICS_RADIUS_OFFSET);
                func_80191284(&D_802902D8, ACTOR_TYPE_FROG);
                func_80133900(&D_802902D8);
                func_8015C840(&D_802902D8);
                *(f32 *)(D_802903AC + PLAYER_ACTION_UNK18_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_PITCH_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_TARGET_PITCH_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_ROLL_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_TARGET_ROLL_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_SCALE_X_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_SCALE_Y_OFFSET) = *(f32 *)((u8 *)&D_802902D8 + PLAYER_OBJECT_SCALE_Z_OFFSET) = 0.0f;
                actionTimer = &D_8028FBD8;
                *actionTimer = 0;
                func_80167604(PLAYER_FROG_STATE);
                *(f32 *)(D_802903A4 + PLAYER_CONTACT_RADIUS_OFFSET) = D_8010850C;
                *actionTimer = 0;
            }
        }
    }
}

/* Restore the normal player model and physics after frog form, releasing captured actors and the capture effect. */
void func_80176AFC(void) {
    s32 pad[2];
    s32 actorIndex;
    f32 initialScale;

    D_80297BEC &= PLAYER_FROG_OPTION_CLEAR_MASK;
    func_8015CB44(&D_802902D8);
    func_80191548(&D_802902D8, ACTOR_TYPE_FROG);
    func_80151FD0((s32)&D_802902D8 + ACTOR_MESH, func_80139CA0(D_80108510), (s32)D_80108510, 1);
    D_8029011E = 0;
    func_801758D0(0);
    func_80133900(&D_802902D8);
    func_8015C840(&D_802902D8);
    initialScale = 0.0f;
    D_8029039C = initialScale;
    D_80290398 = initialScale;
    D_80290394 = initialScale;
    func_8017797C();
    actorIndex = 0;
    if (D_801F0198 > 0) {
        s32 clearCaptureMask = ACTOR_CAPTURE_FLAG_CLEAR_MASK;
        s32 capturedState = ACTOR_CAPTURED_STATE;
        s32 activeState = ACTOR_ACTIVE;
        s8 *actorState = (s8 *)D_8029970A;
        s32 *instanceFlags = (s32 *)(actorState + ACTOR_STATE_TO_INSTANCE_FLAGS);

        do {
            *instanceFlags &= clearCaptureMask;
            if (*actorState == capturedState) {
                *actorState = activeState;
            }
            actorState += ACTOR_INSTANCE_STRIDE;
            actorIndex++;
            instanceFlags = (s32 *)((s8 *)instanceFlags + ACTOR_INSTANCE_STRIDE);
        } while (actorIndex < D_801F0198);
    }
    if (D_8029020C != NULL) {
        *(s16 *)(D_8029020C + EFFECT_EXPIRY_TIMER_OFFSET) = 1;
        D_8029020C = NULL;
    }
}

extern f32 D_80290310;
extern f32 D_80290314;
extern f32 D_8029F9B0;
extern f32 D_8029F9B4;
extern f32 D_80108554;

/* Is the player standing on a platform whose f32 at +0x70 is non-zero?
 * D_802903B0 is the player's collision state. */
s32 func_80176C3C(void) {
    u8 *platform = *(u8 **)(D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET);

    return platform != NULL && *(f32 *)(platform + 0x70) != 0.0f;
}

/* Create the player's fading ground-impact ring and start distance-attenuated shake. */
void func_80176C70(void)
{
  extern s32 D_80108520[];
  extern s32 D_802901AC;
  extern s32 D_80297910;
  extern u8 D_80108528[];
  extern const f32 D_80108534;
  extern s16 D_8029012C;
  extern s32 D_80290120[];
  extern ObjectNode *D_80290130;
  void func_801B33A0(u8 *, u8 **, s32 *);
  void func_801B9974(u8 *, s32, f32, f32, s32, s32);
  u8 *groundNormal;
  s32 contactIndex;
  u8 *ring;
  s32 lifetime;
  f32 alphaPerFrame;
  f32 unsignedConversionThreshold;
  s32 unusedTemporary;
  u32 alphaStep;
  func_801B33A0((u8 *) (&D_802902D8), &groundNormal, &contactIndex);
  ring = func_8013FCDC(ATTACHED_EFFECT_ALLOCATION_BYTES, 1, D_80108520);
  *((s32 *) (ring + 0xC)) = *((s32 *) (D_802903B0 + GROUND_CONTACT_PLATFORM_OFFSET));
  lifetime = ((((volatile Words3 *)((u8 *)&D_802901AC - 4))->w[1] != 0) ? (IMPACT_RING_LARGE_LIFETIME_BITS) : (0)) | IMPACT_RING_BASE_LIFETIME;

  if (func_801A6844(ring, (f32 *) (((u8 *) (&D_802902D8)) + IMPACT_RING_PLAYER_POSITION_OFFSET), (f32 *) groundNormal, (f32) ((lifetime / 2) + 1), (f32) lifetime, ((const Words3 *)((u8 *)&D_80297910 - 4))->w[1], IMPACT_RING_FLAGS, IMPACT_RING_TEXTURE_EXTENT))
  {
    ((AttachedEffectView *)ring)->position[1] = ((AttachedEffectView *)ring)->position[1] - (D_80290308 / (*((f64 *) (D_80108528 + 4))));
    ((AttachedEffectView *)ring)->alpha = IMPACT_RING_INITIAL_ALPHA;
    alphaPerFrame = ((f32) (*((volatile u8 *) (ring + 0x2F)))) / ((f32) lifetime);
    unsignedConversionThreshold = D_80108534;
    ((AttachedEffectView *)ring)->scale = (f32) (lifetime / IMPACT_RING_INITIAL_SCALE_DIVISOR);
    ((AttachedEffectView *)ring)->targetAlpha = 0;
    if (!(alphaPerFrame >= unsignedConversionThreshold))
    {
      alphaStep = (s32) alphaPerFrame;
    }
    else
    {
      alphaStep = ((s32) (alphaPerFrame - unsignedConversionThreshold)) | 0x80000000;
    }
    ((AttachedEffectView *)ring)->alphaStep = alphaStep;
    ((AttachedEffectView *)ring)->red = IMPACT_RING_COLOR_WHITE;
    ((AttachedEffectView *)ring)->green = IMPACT_RING_COLOR_WHITE;
    ((AttachedEffectView *)ring)->blue = IMPACT_RING_COLOR_WHITE;
    func_801A69F8(ring);
    if (lifetime)
    {
    }
    D_80290130 = (ObjectNode *) ring;
    *((Words3 *) D_80290120) = *((Words3 *) (ring + 0x14));
    D_8029012C = lifetime;
    func_801B9974((u8 *) (&D_8029030C), IMPACT_RING_SHAKE_DURATION, (f32) (lifetime * IMPACT_RING_SHAKE_RANGE_PER_FRAME), (f32) (lifetime * IMPACT_RING_SHAKE_SECOND_RANGE_PER_FRAME), IMPACT_RING_SHAKE_CYCLES, IMPACT_RING_SHAKE_FLAGS);
  }
}

/* Impact-ring collision: while the ring's lifetime D_8029012C runs, a ball near
 * the ring's height and within its inner radius is bounced (D_8029F9D4, ball Y
 * velocity), and every active actor slot near the ring gets func_80196610 (ball impact). */
void func_80176E9C(void)
{
  extern s16 D_8029012C;
  extern ObjectNode *D_80290130;
  extern s32 D_80290120[];
  extern f32 D_801EF478;
  extern f32 D_80108538;
  extern f32 D_8010853C;
  extern f32 D_80108540;
  extern f32 D_80108544;
  extern f32 D_80108548;
  extern const f32 D_8010854C;
  extern const f32 D_80108550;
  extern u8 D_8029970A[];
  extern u8 D_80299964[];
  extern u8 D_80299710[];
  extern u8 D_80299720[];
  extern u8 D_80299718[];
  extern u8 D_8029971C[];
  extern u8 D_802997B4[];
  f32 ringPos[3];
  f32 heightDiff;
  f32 actorY;
  f32 outerRadius;
  f32 innerRadius;
  s32 slot;
  s32 slotOffset;
  u8 *ballCollision;
  u8 *actor;
  if ((D_8029012C > 0) && (D_80290130 != 0))
  {
    if ((*((u8 **) (((u8 *) D_80290130) + 0xC))) != 0)
    {
      ringPos[0] = (*((f32 *) (&D_80290120[0]))) + (*((f32 *) ((*((u8 **) (((u8 *) D_80290130) + 0xC))) + 0xB4)));
      ringPos[1] = (*((f32 *) (&D_80290120[1]))) + (*((f32 *) ((*((u8 **) (((u8 *) D_80290130) + 0xC))) + 0xB8)));
      ringPos[2] = (*((f32 *) (&D_80290120[2]))) + (*((f32 *) ((*((u8 **) (((u8 *) D_80290130) + 0xC))) + 0xBC)));
    }
    else
    {
      *((Words3 *) ringPos) = *((Words3 *) D_80290120);
    }
    outerRadius = (*((f32 *) (((u8 *) D_80290130) + 0x3C))) * D_801EF478;
    innerRadius = (*((f32 *) (((u8 *) D_80290130) + 0x38))) * D_801EF478;
    (*((u16 *) (&D_8029012C)))--;
    ballCollision = D_8029FA50;
    if ((ballCollision[0x188] != 0) && ((*((s32 *) ballCollision)) != 0) && (ballCollision[0x54] != 0))
    {
      f32 ballHeightDiff = (D_8029F9B0 - ringPos[1]) - (*((f32 *) D_8029FA44));
      if ((ballHeightDiff > 0.0f) ? (ballHeightDiff <= 10.0f) : (-ballHeightDiff <= 10.0f))
      {
        if (func_80148DB0((u8 *) (&D_8029F9AC), (u8 *) ringPos) <= innerRadius)
        {
          D_8029F9D4 = ((((outerRadius - innerRadius) / 8.0f) + 1.0f) * 10.0f) / 10.0f;
        }
      }
    }
    for (slot = 0; slot < D_801F0198; slot++)
    {
      slotOffset = slot * ACTOR_INSTANCE_STRIDE;
      if ((*((s32 *) (&D_80299964[slotOffset]))) & 0x20)
        continue;
      if (((s8) D_8029970A[slotOffset]) != 1)
        continue;
      if (!((*((s32 *) (&D_80299710[slotOffset]))) & 0x100))
      {
        actorY = *((volatile f32 *) (&D_80299720[slotOffset]));
        if (!(ringPos[1] < actorY))
          goto floor_test;
        if ((((heightDiff = (actorY - ringPos[1]) - (*((f32 *) (&D_80299718[slotOffset])))) > 0.0f) ? heightDiff : (heightDiff = -heightDiff)) <= 25.0f)
          goto hit;
      }
      actorY = *((volatile f32 *) (&D_80299720[slotOffset]));
    floor_test:
      actorY -= ringPos[1];
      if ((((heightDiff = actorY - (*(*((f32 **) (&D_802997B4[slotOffset]))))) > 0.0f) ? heightDiff : -heightDiff) <= 10.0f)
      {
      hit:
        if (func_80148DB0(D_8029971C + slotOffset, (u8 *) ringPos) <= innerRadius)
        {
          u8 *slotBase;
          do { slotBase = D_8029971C - 0x34; } while (0);
          actor = slotBase;
          actor += slotOffset;
          func_80196610(actor);
        }
      }
    }
  }
}

/* Test for a free, grounded ball within 40 units, with no player contact plane separating it. */
s32 func_8017723C(void) {
    s32 *ballSupport = &D_8029F9A4;
    f32 *playerPosition;
    f32 *ballPosition;
    s32 planeIndex;

    if (*ballSupport != 0) {
        return 0;
    }
    if ((s8)D_8029F486 == BALL_STATUS_DESTROYED) {
        return 0;
    }
    if (D_8029FA50[BALL_LANDING_CONTACT_COUNT] == 0) {
        return 0;
    }
    if (D_802903B0[BALL_LANDING_CONTACT_COUNT] == 0) {
        return 0;
    }
    planeIndex = 0;
    playerPosition = (f32 *)&D_8029030C;
    ballPosition = (f32 *)&ballSupport[BALL_POSITION_FROM_SUPPORT_WORDS];
    do {
        f32 *contactPlane = ((f32 **)D_802903B0)[planeIndex];

        if (contactPlane != NULL) {
            if ((*playerPosition * contactPlane[TRI_NORMAL_X] + D_80290310 * contactPlane[TRI_NORMAL_Y] + D_80290314 * contactPlane[TRI_NORMAL_Z] + contactPlane[TRI_PLANE_DISTANCE]) *
                    (*ballPosition * contactPlane[TRI_NORMAL_X] + D_8029F9B0 * contactPlane[TRI_NORMAL_Y] + D_8029F9B4 * contactPlane[TRI_NORMAL_Z] + contactPlane[TRI_PLANE_DISTANCE]) < 0.0f) {
                return 0;
            }
        }
        planeIndex++;
    } while (planeIndex < BALL_GROUND_PROXIMITY_PLANE_COUNT);
    if (func_80148EBC(&D_8029030C, (s32)&D_8029F9AC) < D_80108554) {
        return 1;
    }
    return 0;
}

/* Recreate the thought-bubble background and animated foreground, then link them in draw order. */
void func_80177390(s32 *foregroundAnimation) {
    extern u8 *D_80290140[2];
    extern u8 D_80108558[];
    extern u8 D_8010855C[];
    u8 **sprites = D_80290140;
    s32 spriteIndex;

    for (spriteIndex = 0; spriteIndex < THOUGHT_BUBBLE_SPRITE_COUNT; spriteIndex++) {
        if (sprites[spriteIndex] != NULL) {
            func_8014ACB4(sprites[spriteIndex]);
            func_80141720((s32 *)&sprites[spriteIndex]);
        }
        sprites[spriteIndex] = func_8013FCDC(THOUGHT_BUBBLE_SPRITE_BYTES, 1, (s32 *)D_80108558);
        if (spriteIndex == THOUGHT_BUBBLE_FOREGROUND) {
            func_8014B7F0(sprites[THOUGHT_BUBBLE_FOREGROUND], foregroundAnimation, 0);
            *(s8 *)(sprites[THOUGHT_BUBBLE_FOREGROUND] + WORLD_SPRITE_OFFSET_X) = THOUGHT_BUBBLE_FOREGROUND_X;
            *(s8 *)(sprites[THOUGHT_BUBBLE_FOREGROUND] + WORLD_SPRITE_OFFSET_Y) = THOUGHT_BUBBLE_FOREGROUND_Y;
        } else {
            func_8014FCF8(sprites[spriteIndex] + WORLD_SPRITE_IMAGE, func_80139CA0(D_8010855C), 1);
            sprites[spriteIndex][WORLD_SPRITE_OFFSET_X] = -(*(u16 *)(*(u8 **)(sprites[spriteIndex] + WORLD_SPRITE_IMAGE) + BACKGROUND_TEXTURE_WIDTH_OFFSET)) / 2;
            sprites[spriteIndex][WORLD_SPRITE_OFFSET_Y] = -(*(u16 *)(*(u8 **)(sprites[spriteIndex] + WORLD_SPRITE_IMAGE) + BACKGROUND_TEXTURE_HEIGHT_OFFSET)) / 2;
        }
        sprites[spriteIndex][WORLD_SPRITE_ALPHA] = THOUGHT_BUBBLE_CHANNEL_MAX;
        sprites[spriteIndex][WORLD_SPRITE_FLAGS] = WORLD_SPRITE_LATE_PASS;
        sprites[spriteIndex][WORLD_SPRITE_RED] = THOUGHT_BUBBLE_CHANNEL_MAX;
        sprites[spriteIndex][WORLD_SPRITE_GREEN] = THOUGHT_BUBBLE_CHANNEL_MAX;
        sprites[spriteIndex][WORLD_SPRITE_BLUE] = THOUGHT_BUBBLE_CHANNEL_MAX;
        *(s16 *)(sprites[spriteIndex] + WORLD_SPRITE_SCALE_X) = 0;
        *(s16 *)(sprites[spriteIndex] + WORLD_SPRITE_SCALE_Y) = 0;
        *(s16 *)(sprites[spriteIndex] + WORLD_SPRITE_ANIM_START_SCALE) = 0;
        *(s16 *)(sprites[spriteIndex] + WORLD_SPRITE_ANIM_END_SCALE) = 0;
    }
    func_8014AC1C(D_80290140[THOUGHT_BUBBLE_BACKGROUND], 0);
    func_8014AC1C(D_80290140[THOUGHT_BUBBLE_FOREGROUND], D_80290140[THOUGHT_BUBBLE_BACKGROUND]);
}

/* Play surface-dependent footstep sounds and emit effects at animation cues. */
void func_8017753C(void) {
    s32 *playerFlags;

    if (D_802903B0[ACTOR_MODEL_CONTACT_COUNT] == 0 && D_801E7462 == 0) {
        return;
    }
    if (func_80133E24((u8 *)&D_802902D8, 27.0f) || func_80133E24((u8 *)&D_802902D8, 69.0f) ||
        func_80133E24((u8 *)&D_802902D8, 85.0f)) {
        if (D_802903AC[WATER_CONTACT_DEPTH] != 0 || (*(u8 **)D_802903B0 != 0 && (*(u8 **)D_802903B0)[PLATFORM_FACE_SURFACE_TYPE] == PLAYER_FOOTSTEP_SPLASH_SURFACE)) {
            func_80178134(PLAYER_FOOTSTEP_SOUND_SPLASH, (f32 *)&D_8029030C, 0x32, func_80147000(0x14) + 0x8C);
        } else {
            playerFlags = &D_80290300;
            if (*playerFlags & PLAYER_FOOTSTEP_ALTERNATE_SOUND_FLAG) {
                func_80178134(PLAYER_FOOTSTEP_SOUND_ALTERNATE, (f32 *)(playerFlags + PLAYER_POSITION_WORDS_FROM_FLAGS), 0x82, 0x80);
            } else if (D_801E7462 != 0) {
                func_80178134(PLAYER_FOOTSTEP_SOUND_FIRST, (f32 *)(playerFlags + PLAYER_POSITION_WORDS_FROM_FLAGS), D_801E7462 * 3 + 0x28, func_80147000(0x24) + 0x6E);
            } else {
                func_80178134(PLAYER_FOOTSTEP_SOUND_FIRST, (f32 *)(playerFlags + PLAYER_POSITION_WORDS_FROM_FLAGS), 0x82, func_80147000(0x38) + 0x64);
            }
        }
    }
    if (func_80133E24((u8 *)&D_802902D8, 58.0f) || func_80133E24((u8 *)&D_802902D8, 76.0f) ||
        func_80133E24((u8 *)&D_802902D8, 90.0f)) {
        if (D_802903AC[WATER_CONTACT_DEPTH] != 0 || (*(u8 **)D_802903B0 != 0 && (*(u8 **)D_802903B0)[PLATFORM_FACE_SURFACE_TYPE] == PLAYER_FOOTSTEP_SPLASH_SURFACE)) {
            func_80178134(PLAYER_FOOTSTEP_SOUND_SPLASH, (f32 *)&D_8029030C, 0x32, func_80147000(0x14) + 0x8C);
        } else {
            playerFlags = &D_80290300;
            if (*playerFlags & PLAYER_FOOTSTEP_ALTERNATE_SOUND_FLAG) {
                func_80178134(PLAYER_FOOTSTEP_SOUND_ALTERNATE, (f32 *)(playerFlags + PLAYER_POSITION_WORDS_FROM_FLAGS), 0x82, 0x80);
            } else if (D_801E7462 != 0) {
                func_80178134(PLAYER_FOOTSTEP_SOUND_SECOND, (f32 *)(playerFlags + PLAYER_POSITION_WORDS_FROM_FLAGS), D_801E7462 * 3 + 0x28, func_80147000(0x24) + 0x6E);
            } else {
                func_80178134(PLAYER_FOOTSTEP_SOUND_SECOND, (f32 *)(playerFlags + PLAYER_POSITION_WORDS_FROM_FLAGS), 0x82, func_80147000(0x38) + 0x64);
            }
        }
    }
    if (func_80133E24((u8 *)&D_802902D8, 77.0f) || func_80133E24((u8 *)&D_802902D8, 15.0f) ||
        func_80133E24((u8 *)&D_802902D8, 86.0f)) {
        func_801A87CC(PLAYER_FOOTSTEP_EFFECT_NEGATIVE_X);
    }
    if (func_80133E24((u8 *)&D_802902D8, 69.0f) || func_80133E24((u8 *)&D_802902D8, 44.0f) ||
        func_80133E24((u8 *)&D_802902D8, 91.0f)) {
        func_801A87CC(PLAYER_FOOTSTEP_EFFECT_POSITIVE_X);
    }
}

/* Spawn a one-frame trail particle at arg0: no green/blue tint, sprite flags cleared,
 * every sprite scale set to D_801EEC10; then relink its sprite (func_8014ACB4 unlinks,
 * func_8014AC1C with NULL reinserts it at the default list position). */
void func_80177888(s32 arg0) {
    PooledParticle *particle = (PooledParticle *)func_801B66D4(PARTICLE_TRAIL, arg0, &D_801ED3C4, 0, 0);
    if (particle != NULL) {
        particle->green = 0;
        particle->blue = 0;
        particle->spriteFlags = 0;
        particle->lifetime = 1;
        particle->scaleParam1 = particle->scaleParam0 = particle->spriteScaleY = particle->spriteScaleX = D_801EEC10;
        func_8014ACB4(particle->spriteLinks);
        func_8014AC1C((ListNode *)particle->spriteLinks, 0);
    }
}

/* Play the next of the four rotating player sounds (IDs 0x109..0x10C) at the player's
 * position (func_80178134: sound id, position, volume, pitch); D_801EEBEC picks the variant. */
void func_80177910(void) {
    func_80178134((s16)(D_801EEBEC + 0x109), &D_8029030C, 0x64, 0x8A);
    D_801EEBEC = (D_801EEBEC + 1) % 4;
}

/* Put the player in action state 0 (func_80167604 = player_set_state); with no collision contacts (D_802903B0 +0x188 == 0) the action block's state (+4) becomes 2 instead. */
void func_8017797C(void) {
    func_80167604(0);
    if (D_802903B0[0x188] == 0) {
        *(u16 *)(D_802903AC + 0x4) = 2;
    }
}

/* Original compiler padding. */
const u32 D_801779BC_padding[] __attribute__((section(".text"))) = {
    0x00000300
};



/* Unlinks a SoundEmitter from the emitter list (sentinel D_802903C0) and decrements the emitter count D_8029040C.
 * unk00 is the node's next link, unk04 its prev link. */
void func_801779C0(UnkList *emitter) {
    s32 *emitterCount = &D_8029040C;

    emitter->unk04->unk00 = emitter->unk00;
    emitter->unk00->unk04 = emitter->unk04;
    (*emitterCount)--;
}

/* sound_emitter_list_init: empty the circular sound-emitter list (sentinel D_802903C0,
 * prev/tail D_802903C4, both back at the sentinel) and zero the emitter count D_8029040C. */
void func_801779F0(void) {
    s32 *head = &D_802903C0;

    D_802903C4 = (s32)head;
    *head = (s32)head;
    D_8029040C = 0;
}

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

/* Music select: stops the current song (D_80290424 = sequence player, D_80290428 = current track), then loads track `track`'s sequence from ROM and starts it. */
void func_80177A14(s32 track) {
    u8 *seq_start;
    u8 *seq_end;
    s32 *player = &D_80290424;
    s32 *seq_buf;
    s32 handle;

    func_801C0E3C(*player, 0);
    func_801C0C70(*player, 0x50);
    if ((u8)track != D_80290428) {
        handle = *player;
        D_80290428 = (u8)track;
        func_801C0B70(handle, 1);
        while (func_801C0C1C(D_80290424) != 0) {
        }
        if ((u8)track == 0) {
            return;
        }
        switch ((u8)track) {
        case 28: seq_start = D_B07630A0; seq_end = D_B0763DA0; break;
        case 29: seq_start = D_B0763DA0; seq_end = D_B0765980; break;
        case 30: seq_start = D_B0765980; seq_end = D_B07669C0; break;
        case 31: seq_start = D_B07669C0; seq_end = D_B07683A0; break;
        case 32: seq_start = D_B07683A0; seq_end = D_B0768D40; break;
        case 33: seq_start = D_B0768D40; seq_end = D_B076A8A0; break;
        case 1: seq_start = D_B06F8720; seq_end = D_B06FB420; break;
        case 2: seq_start = D_B06FB420; seq_end = D_B06FE820; break;
        case 3: seq_start = D_B06FE820; seq_end = D_B0701460; break;
        case 4: seq_start = D_B0701460; seq_end = D_B0706220; break;
        case 5: seq_start = D_B0706220; seq_end = D_B070C5E0; break;
        case 6: seq_start = D_B070C5E0; seq_end = D_B07126C0; break;
        case 7: seq_start = D_B07126C0; seq_end = D_B07187E0; break;
        case 8: seq_start = D_B075C440; seq_end = D_B07630A0; break;
        case 9: seq_start = D_B07187E0; seq_end = D_B071D800; break;
        case 10: seq_start = D_B071D800; seq_end = D_B07245A0; break;
        case 11: seq_start = D_B0758CE0; seq_end = D_B075C440; break;
        case 12: seq_start = D_B07245A0; seq_end = D_B07282E0; break;
        case 13: seq_start = D_B07282E0; seq_end = D_B072DDC0; break;
        case 14: seq_start = D_B072DDC0; seq_end = D_B07318E0; break;
        case 15: seq_start = D_B07318E0; seq_end = D_B07356A0; break;
        case 16: seq_start = D_B07356A0; seq_end = D_B07371E0; break;
        case 17: seq_start = D_B07371E0; seq_end = D_B073B320; break;
        case 18: seq_start = D_B073B320; seq_end = D_B073E7A0; break;
        case 19: seq_start = D_B073E7A0; seq_end = D_B07437C0; break;
        case 20: seq_start = D_B07437C0; seq_end = D_B0747080; break;
        case 21: seq_start = D_B0747080; seq_end = D_B074C440; break;
        case 22: seq_start = D_B074C440; seq_end = D_B074F5C0; break;
        case 23: seq_start = D_B074F5C0; seq_end = D_B0752EC0; break;
        case 24: seq_start = D_B0752EC0; seq_end = D_B0756920; break;
        case 25: seq_start = D_B076A8A0; seq_end = D_B076D5A0; break;
        case 26: seq_start = D_B0756920; seq_end = D_B0758340; break;
        case 27: seq_start = D_B0758340; seq_end = D_B0758CE0; break;
        case 42: seq_start = D_B076FB00; seq_end = D_B076FD80; break;
        case 43: seq_start = D_B076FD80; seq_end = D_B076FF00; break;
        case 44: seq_start = D_B076FF00; seq_end = D_B0770200; break;
        case 45: seq_start = D_B0770200; seq_end = D_B0770540; break;
        case 34: seq_start = D_B0770540; seq_end = D_B0770900; break;
        case 35: seq_start = D_B0770900; seq_end = D_B0770CA0; break;
        case 36: seq_start = D_B0770CA0; seq_end = D_B0771020; break;
        case 37: seq_start = D_B0771020; seq_end = D_B0771340; break;
        case 38: seq_start = D_B0771340; seq_end = D_B07717E0; break;
        case 39: seq_start = D_B07717E0; seq_end = D_B0771A60; break;
        case 40: seq_start = D_B0771A60; seq_end = D_B0771D60; break;
        case 41: seq_start = D_B0771D60; seq_end = D_B0772040; break;
        case 46: seq_start = D_B076D5A0; seq_end = D_B076D820; break;
        case 47: seq_start = D_B076D820; seq_end = D_B076DB00; break;
        case 48: seq_start = D_B076DB00; seq_end = D_B076DF20; break;
        case 49: seq_start = D_B076DF20; seq_end = D_B076E440; break;
        case 50: seq_start = D_B076F0E0; seq_end = D_B076F340; break;
        case 51: seq_start = D_B076F340; seq_end = D_B076F540; break;
        case 52: seq_start = D_B076F540; seq_end = D_B076F7C0; break;
        case 53: seq_start = D_B076F7C0; seq_end = D_B076FB00; break;
        case 54: seq_start = D_B076E440; seq_end = D_B076E700; break;
        case 55: seq_start = D_B076E700; seq_end = D_B076EA80; break;
        case 56: seq_start = D_B076EA80; seq_end = D_B076EDC0; break;
        case 57: seq_start = D_B076EDC0; seq_end = D_B076F0E0; break;
        case 58: seq_start = D_B0772040; seq_end = D_B0775580; break;
        case 59: seq_start = D_B0775580; seq_end = D_B0777420; break;
        case 60: seq_start = D_B0777420; seq_end = D_B077BBE0; break;
        default:
            func_80139D70(func_801D2150(&D_8025D578, &D_80108594));
            return;
        }
        seq_buf = &D_80290420;
        *seq_buf = (s32)D_80290410 + (D_B04E3EE0 - D_B04DA9A0);
        func_80141DD8((u8 *)*seq_buf, seq_start, seq_end);
        D_80290424 = func_801C0EE0((s32)D_80290418, *seq_buf);
        while (func_801C0C1C(D_80290424) == 0) {
        }
        player = &D_80290424;
        func_801C0C70(*player, 0x50);
        if ((u8)track == 0x1A && D_80000300 == 0) {
            func_801C0DAC(*player, 0x6A);
        }
    }
}

extern f64 D_801086A0, D_801086A8, D_801086B0, D_801086C0;
extern f32 D_801086B8, D_801086BC;
extern f32 sqrtf(f32);
/* Play a sound with camera-relative attenuation and pan, then apply pitch, tempo and effect mix. */
s32 func_80178134(s16 soundId, f32 *position, s16 volume, s16 pitch)
{
    f32 direction[3], attenuatedVolume, distanceSquaredOrYaw, attenuationOrPan, distanceOrSideYaw;
    u32 volumeLevel;
    s32 handle, effectId;

    attenuatedVolume = (f32)volume;
    distanceSquaredOrYaw = func_80148EBC(&D_8028F914, (s32)position); if ((f32)(D_801EF480 * D_801EF480) < distanceSquaredOrYaw) return 0;
    distanceOrSideYaw = __builtin_sqrtf(distanceSquaredOrYaw); attenuationOrPan = (attenuationOrPan = (f32)D_801EF480 - distanceOrSideYaw) / (f32)D_801EF480; attenuatedVolume *= attenuationOrPan;
    func_80149428(direction, position, &D_8028F914);
    distanceSquaredOrYaw = func_801496C8(func_80147460(direction[0], direction[2]));
    distanceOrSideYaw = func_801496C8(D_8028F95C + D_801086A0);
    attenuationOrPan = func_8014944C(distanceOrSideYaw, distanceSquaredOrYaw) * D_801086A8;
    if ((effectId = soundId) != 0) {
        attenuatedVolume *= D_801086B0; if (attenuatedVolume > D_801086B8) attenuatedVolume = D_801086B8;
        if (!(attenuatedVolume >= D_801086BC)) volumeLevel = (s32)attenuatedVolume; else { volumeLevel = (s32)(attenuatedVolume - D_801086BC); volumeLevel |= 0x80000000; }
        handle = func_801C08E4(effectId, volumeLevel & POSITIONAL_SOUND_VOLUME_MASK, (s32)attenuationOrPan, 0, POSITIONAL_SOUND_DEFAULT_PRIORITY);
        func_801C0D40(handle, (f32)(pitch - POSITIONAL_SOUND_NEUTRAL_PITCH) / D_801086C0); func_801C0DAC(handle, pitch);
    } else handle = 0;
    if (D_801EF484 != 0 || D_8028F9B4[9] != 0) func_801C0E3C(handle, POSITIONAL_SOUND_EFFECT_MIX);
    return handle;
}

/* Play a camera-relative sound at full volume inside its radius, attenuating beyond it. */
s32 func_801783A8(s16 soundId, s32 positionAddress, s16 volume, s16 pitch, f32 radius)
{
    f32 direction[4];
    f32 attenuatedVolume = volume;
    f32 distanceOrYaw;
    f32 cameraSideYaw;
    int defaultPriorityMagnitude;
    f32 attenuationOrPan;
    s32 handle;
    if ((func_80148E48(&D_8028F914, (f32 *) positionAddress) - radius) < 0.0f)
    {
        distanceOrYaw = 0.0f;
    }
    else
    {
        distanceOrYaw = func_80148E48(&D_8028F914, (f32 *) positionAddress) - radius;
    }
    if (((f32) D_801EF480) < distanceOrYaw)
    {
        return 0;
    }
    attenuationOrPan = (attenuationOrPan = ((f32) D_801EF480) - distanceOrYaw) / ((f32) D_801EF480);
    attenuatedVolume = attenuatedVolume * attenuationOrPan;
    func_80149428(direction, (f32 *) positionAddress, &D_8028F914);
    distanceOrYaw = func_801496C8(func_80147460(direction[0], direction[2]));
    cameraSideYaw = func_801496C8(D_8028F95C + D_801086C8);
    attenuationOrPan = func_8014944C(cameraSideYaw, distanceOrYaw) * D_801086D0;
    if (soundId != 0)
    {
        defaultPriorityMagnitude = 1;
        attenuatedVolume = attenuatedVolume * D_801086D8;
        if (attenuatedVolume > D_801086E0)
        {
            attenuatedVolume = D_801086E0;
        }
        handle = func_801C08E4(soundId, (s32) attenuatedVolume, (s32) attenuationOrPan, 0, -defaultPriorityMagnitude);
        func_801C0D40(handle, ((f32) (pitch - POSITIONAL_SOUND_NEUTRAL_PITCH)) / D_801086E4);
        func_801C0DAC(handle, pitch);
    }
    else
    {
        handle = 0;
    }
    if ((D_801EF484 != 0) || ((*((u8 *) (D_8028F9B4 + POSITIONAL_SOUND_EFFECT_FLAG_OFFSET))) != 0))
    {
        func_801C0E3C(handle, POSITIONAL_SOUND_EFFECT_MIX);
    }
    return handle;
}

/* Starts a tracked positional sound in `sound`, stopping whatever it played
 * before, and records its id, base volume (scaled, capped at 255), pitch and
 * emitter position so func_80178760 can keep updating it. */
void func_801785E0(s32 *soundState, s16 soundId, s16 volume, s32 position, s16 pitch) {
    PositionalSound *sound = (PositionalSound *)soundState;

    if (soundId != 0) {
        s32 handle;
        s16 baseVolume;
        if (sound->handle != 0) {
            func_80178704(soundState);
        }
        handle = func_801783A8(soundId, position, volume, pitch, sound->radius);
        baseVolume = (f32)volume * D_801086EC;
        sound->handle = handle;
        if (baseVolume > 255) {
            baseVolume = 255;
        }
        sound->volume = baseVolume;
        sound->position = (f32 *)position;
        sound->soundId = soundId;
        sound->pitch = pitch;
        if (sound->handle != 0) {
            D_801EF488++;
        }
    }
}

void func_80178704(s32 *soundState) { /* Stops a tracked PositionalSound (words: 0 handle, 1 volume, 2 attenuatedVolume), keeping its volume in word 2. */
    if (soundState[0] != 0) {
        func_801C0B70(soundState[0], 0); /* MusHandleStop */
        D_801EF488--;                    /* tracked sound handles */
    }
    {
        s32 savedVolume = soundState[1];
        soundState[1] = 0;
        soundState[0] = 0;
        soundState[2] = savedVolume;
    }
}

/* Update distance attenuation, stereo pan and playback pitch for a tracked sound. */
void func_80178760(void *soundState)
{
    extern f64 D_801086F0;
    extern f64 D_801086F8;
    extern f64 D_80108700;
    extern f64 D_80108708;
    PositionalSound *sound = soundState;
    f32 direction[4];
    f32 distanceScale;
    f32 cameraSideYaw;
    f32 pan;
    f32 maxDistance;

    if (sound->soundId == 0) {
        return;
    }
    if (sound->handle == 0 && sound->volume == 0) {
        return;
    }
    if (sound->radius != 0.0f) {
        distanceScale = (func_80148E48(&D_8028F914, (f32 *)sound->position) - sound->radius < 0.0f) ? 0.0f : func_80148E48(&D_8028F914, (f32 *)sound->position) - sound->radius;
        maxDistance = D_801EF480;
        if (maxDistance < distanceScale) {
            if (sound->handle != 0) {
                func_801C0B70(sound->handle, 0);
                D_801EF488--;
                sound->handle = 0;
            }
            return;
        }
    } else {
        distanceScale = func_80148EBC(&D_8028F914, (s32)sound->position); if ((f32)(D_801EF480 * D_801EF480) < distanceScale) {
            if (sound->handle != 0) {
                func_801C0B70(sound->handle, 0);
                D_801EF488--;
                sound->handle = 0;
            }
            return;
        }
        distanceScale = __builtin_sqrtf(distanceScale);
        maxDistance = D_801EF480;
    }
    distanceScale = maxDistance - distanceScale;
    distanceScale /= maxDistance;
    sound->attenuatedVolume = (f32)sound->volume * distanceScale;
    func_80149428(direction, (f32 *)sound->position, &D_8028F914);
    distanceScale = func_801496C8(func_80147460(direction[0], direction[2]));
    cameraSideYaw = func_801496C8(D_8028F95C + *(f64 *)((u8 *)&D_801086F0 + 4));
    pan = func_8014944C(cameraSideYaw, distanceScale) * *(f64 *)((u8 *)&D_801086F8 + 4);
    if (sound->handle == 0) {
        sound->handle = func_801C08E4(sound->soundId, sound->attenuatedVolume, (s32)pan, 0, POSITIONAL_SOUND_DEFAULT_PRIORITY);
        if (D_801EF484 != 0 || D_8028F9B4[9] != 0) {
            func_801C0E3C(sound->handle, POSITIONAL_SOUND_EFFECT_MIX);
        }
        D_801EF488++;
    } else {
        func_801C0C70(sound->handle, sound->attenuatedVolume);
    }
    func_801C0CD4(sound->handle, (s32)pan);
    func_801C0D40(sound->handle, (f32)(sound->pitch - POSITIONAL_SOUND_NEUTRAL_PITCH) / *(f64 *)((u8 *)&D_80108700 + 4));
    func_801C0DAC(sound->handle, sound->pitch);
}

/* sound_set_max_audible_dist: sets D_801EF480, the distance beyond which
 * positional sounds are silent (see sound_update_positional). */
void func_80178A48(s32 maxDist)
{
    D_801EF480 = maxDist;
}

s32 func_801C08E4(s32, s32, s32, s32, s32);
void func_801C0D40(s32, f32);
void func_801C0DAC(s32, s32);
extern f64 D_80108758;

/*
 * Start a non-positional sound and track it as a SoundEmitter: allocate a
 * node ("AmbSnd", D_8010870C), link it at the head of the emitter list
 * D_802903C0, scale `volume` by 1.8 (D_80108714) capped at 255, start sound
 * `soundId` with `pitch` (func_801C08E4 = MusStartEffect2) and store its
 * handle. The zero vector D_801ED3C4 as position marks it non-positional.
 */
void func_80178A58(s32 soundId, s32 volume, s32 pitch)
{
    extern u8 D_8010870C[];
    extern const f64 D_80108714;
    SoundEmitter *emitter;
    s32 **head = *(s32 ***)&D_802903C0;
    s32 **link;

    emitter = func_8013FCDC(sizeof(SoundEmitter), 1, (s32 *)D_8010870C);
    link = (s32 **)emitter;
    link[1] = (s32 *)head;
    link[0] = head[0];
    ((s32 **)head[0])[1] = (s32 *)link;
    head[0] = (s32 *)link;
    D_8029040C++;
    volume = (f32)volume * D_80108714;
    if (volume > 255) {
        volume = 255;
    }
    emitter->sound.handle = func_801C08E4(soundId, volume, pitch, 0, -1);
    emitter->sound.position = (f32 *)&D_801ED3C4;
    emitter->sound.unk0C = volume;
    emitter->sound.attenuatedVolume = volume;
    emitter->sound.soundId = soundId;
    D_801EF488++;
}

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

/* Create a timed positional sound emitter, optionally attached to a platform. */
void func_80178B6C(s32 soundId, s32 volume, s32 *position, s16 pitch, u16 repeatDelay, s16 randomDelay, u16 playDuration, s32 parentTag, u16 unk4A, f32 radius)
{
    extern u8 D_8010870C[];
    extern const f64 D_80108718;
    SoundEmitter *emitter;
    s32 **listAnchor = *(s32 ***)&D_802903C0;
    s32 **links;

    emitter = func_8013FCDC(SOUND_EMITTER_SIZE, 1, (s32 *)D_8010870C);
    links = (s32 **)emitter;
    links[1] = (s32 *)listAnchor;
    links[0] = listAnchor[0];
    ((s32 **)listAnchor[0])[1] = (s32 *)links;
    listAnchor[0] = (s32 *)links;
    D_8029040C++;
    if ((s16)parentTag != 0) {
        *(Vec3Words *)&emitter->localPosition = *(Vec3Words *)position;
        emitter->parent = (u8 *)(s32)func_8017DBA0((s16)parentTag);
    } else {
        *(Vec3Words *)&emitter->worldPosition = *(Vec3Words *)position;
        emitter->parent = 0;
    }
    emitter->sound.volume = volume;
    emitter->sound.soundId = soundId;
    emitter->sound.pitch = pitch;
    if (playDuration != 0 || (repeatDelay == 0 && randomDelay == 0)) {
        s16 id = soundId;
        s32 *soundWords = &emitter->sound.handle;
        s32 positionAddress = (s32)&emitter->worldPosition;
        if (id != 0) {
            s16 scaledVolume;
            if (soundWords[EMITTER_SOUND_HANDLE_WORD] != 0) {
                func_80178704(soundWords);
            }
            emitter->sound.handle = func_801783A8(id, positionAddress, volume, pitch, emitter->sound.radius);
            scaledVolume = (s32)((f32)(s16)volume * *(f64 *)((u8 *)&D_80108718 + 4));
            if (scaledVolume > SOUND_VOLUME_MAX) {
                scaledVolume = SOUND_VOLUME_MAX;
            }
            soundWords[EMITTER_SOUND_VOLUME_WORD] = scaledVolume;
            soundWords[EMITTER_SOUND_POSITION_WORD] = positionAddress;
            ((s16 *)soundWords)[EMITTER_SOUND_ID_HALFWORD] = id;
            ((s16 *)soundWords)[EMITTER_SOUND_PITCH_HALFWORD] = pitch;
            if (soundWords[EMITTER_SOUND_HANDLE_WORD] != 0) {
                D_801EF488++;
            }
        }
        if (emitter->sound.handle != 0 && emitter->sound.soundId == SOUND_ID_SLOW_FADE) {
            func_801C0E3C(emitter->sound.handle, SOUND_SLOW_FADE_FX_MIX);
        }
        emitter->timer = playDuration;
    } else {
        emitter->timer = repeatDelay + ((s32 (*)(s32))func_80147000)(randomDelay);
        emitter->sound.position = (f32 *)&emitter->worldPosition;
    }
    emitter->sound.radius = radius;
    emitter->initialVolume = volume;
    emitter->repeatDelay = repeatDelay;
    emitter->randomDelay = randomDelay;
    emitter->playDuration = playDuration;
    emitter->unk4A = unk4A;
}

/* Stop every sound emitter in the list at D_802903C0: stop a playing handle
 * (MusHandleStop), drop the tracked-handle count D_801EF488 and keep its
 * volume as the attenuated volume; then mark every emitter non-positional
 * (position = the zero vector D_801ED3C4). */
void func_80178E04(void)
{
    SoundEmitter *emitter = *(SoundEmitter **)&D_802903C0;

    if (emitter != (SoundEmitter *)&D_802903C0) {
        f32 *nonPositional = (f32 *)&D_801ED3C4;
        SoundEmitter *head = (SoundEmitter *)&D_802903C0;
        do {
            if (emitter->sound.handle != 0) {
                func_801C0B70(emitter->sound.handle, 0);
                D_801EF488 -= 1;
                emitter->sound.attenuatedVolume = emitter->sound.volume;
                emitter->sound.volume = 0;
                emitter->sound.handle = 0;
            }
            emitter->sound.position = nonPositional;
            emitter = emitter->next;
        } while (emitter != head);
    }
}

extern const f32 D_80108724, D_80108728, D_8010872C, D_80108730, D_80108738, D_8010873C, D_80108740, D_80108748;
/* Update emitter positions, modulation, fades, repeat timers, and expired sounds. */
void func_80178E98(void)
{
    SoundEmitter *emitter;
    SoundEmitter *nextEmitter;
    f32 modulatedValue;
    s32 outputVolume;

    if (D_801EC7D2 || (D_801E7584 & GAME_TRANSITION_PENDING)) {
        emitter = *(SoundEmitter **)&D_802903C0;
        if (emitter != (SoundEmitter *)&D_802903C0) {
            SoundEmitter *head = (SoundEmitter *)&D_802903C0;
            do {
                if (emitter->sound.handle) func_801C0C70(emitter->sound.handle, (emitter->sound.attenuatedVolume * D_801E765A) / SOUND_VOLUME_Q15_ONE);
                emitter = emitter->next;
            } while (emitter != head);
        }
        return;
    }
    emitter = *(SoundEmitter **)&D_802903C0;
    while (emitter != (SoundEmitter *)&D_802903C0) {
        nextEmitter = emitter->next;
        if (emitter->sound.position == (f32 *)&D_801ED3C4) {
            if (emitter->sound.soundId == SOUND_ID_MODULATED) {
                modulatedValue = func_80149724(D_80108724, (f32)D_802004E0, 0) * D_80108728 + D_8010872C;
                func_801C0D40(emitter->sound.handle, (f32)((modulatedValue - D_8010872C) / *(const f64 *)&D_80108730));
                func_801C0DAC(emitter->sound.handle, (s32)modulatedValue);
                modulatedValue = (func_80149724(D_80108738, (f32)D_802004E0, 0) + D_8010873C) / D_80108740 + *(const f64 *)((const u8 *)&D_80108740 + 4);
                modulatedValue *= emitter->sound.unk0C;
                outputVolume = modulatedValue;
                func_801C0C70(emitter->sound.handle, outputVolume);
                emitter->sound.attenuatedVolume = outputVolume;
            } else if (emitter->sound.handle) {
                func_801C0C70(emitter->sound.handle, (emitter->sound.attenuatedVolume * D_801E765A) / SOUND_VOLUME_Q15_ONE);
            }
        } else {
            if (emitter->parent) {
                func_801499A0(emitter->worldPosition, emitter->localPosition, (s32)emitter->parent + SOUND_PARENT_QUATERNION);
                emitter->worldPosition[0] += *(f32 *)((u8 *)(emitter->parent) + PLATFORM_POSITION);
                emitter->worldPosition[1] += *(f32 *)((u8 *)(emitter->parent) + PLATFORM_POSITION_Y);
                emitter->worldPosition[2] += *(f32 *)((u8 *)(emitter->parent) + PLATFORM_POSITION_Z);
            }
            if (emitter->sound.volume) func_80178760(&emitter->sound);
            if (emitter->playDuration) {
                if (emitter->timer) {
                    emitter->timer--;
                    if (emitter->timer) goto advance;
                }
                { SoundEmitter *current = emitter;
                if (current->sound.handle) {
                    if (current->sound.soundId == SOUND_ID_SLOW_FADE) current->sound.volume -= SOUND_SLOW_FADE_STEP;
                    else current->sound.volume -= SOUND_FADE_STEP;
                    { SoundEmitter *fading = *(SoundEmitter **)&emitter;
                    if (fading->sound.volume <= 0) {
                        if (fading->sound.handle) {
                            func_801C0B70(fading->sound.handle, 0);
                            D_801EF488--;
                        }
                        fading->sound.attenuatedVolume = fading->sound.volume;
                        fading->sound.volume = 0;
                        fading->sound.handle = 0;
                        if (*(s32 *)&emitter->repeatDelay) {
                            emitter->timer = emitter->repeatDelay + func_80147000(emitter->randomDelay);
                            goto advance;
                        }
                        { SoundEmitter *removed = emitter;
                        *(s32 *)removed->prev = (s32)removed->next;
                        *(s32 *)((s32)removed->next + 4) = (s32)removed->prev;
                        }
                        D_8029040C--;
                        func_80141720(&emitter);
                    }
                    }
                } else {
                    s16 restartVolume = current->initialVolume;
                    s16 soundId = current->sound.soundId;
                    s32 positionAddress = (s32)current->worldPosition;
                    s16 pitch = current->sound.pitch;
                    if (soundId) {
                        current->sound.handle = func_801783A8(soundId, positionAddress, restartVolume, pitch, current->sound.radius);
                        restartVolume = (s32)((f64)(f32)restartVolume * *(const f64 *)((const u8 *)&D_80108748 + 4));
                        if (restartVolume >= SOUND_VOLUME_LIMIT) restartVolume = SOUND_VOLUME_MAX;
                        current->sound.volume = restartVolume;
                        current->sound.position = (f32 *)positionAddress;
                        current->sound.soundId = soundId;
                        current->sound.pitch = pitch;
                        if (current->sound.handle) D_801EF488++;
                    }
                    emitter->timer = emitter->playDuration;
                    if (emitter->sound.handle && emitter->sound.soundId == SOUND_ID_SLOW_FADE) func_801C0E3C(emitter->sound.handle, SOUND_SLOW_FADE_FX_MIX);
                }
                }
            } else if (emitter->repeatDelay) {
                emitter->timer--;
                if (!emitter->timer) {
                    if (emitter->sound.radius != 0.0f)
                        func_801783A8(emitter->sound.soundId, (s32)(emitter->worldPosition), *(s16 *)((u8 *)&emitter->sound.volume + 2), emitter->sound.pitch, emitter->sound.radius);
                    else
                        func_80178134(emitter->sound.soundId, emitter->worldPosition, *(s16 *)((u8 *)&emitter->sound.volume + 2), emitter->sound.pitch);
timer:
                    emitter->timer = emitter->repeatDelay + func_80147000(emitter->randomDelay);
                }
            }
        }
advance:
        emitter = nextEmitter;
    }
}

/* Starts sound effect `effectId` at the given volume and pan (MusStartEffect2,
 * default priority) and applies `speed` (128 = normal) to it both as a pitch
 * offset and as a playback tempo. Returns the effect's playback handle. */
s32 func_801793DC(s32 effectId, u8 volume, u8 pan, u8 speed)
{    extern f32 D_80108750; /* pool: the f64 pitch divisor lives at +4 */

    s32 handle = func_801C08E4(effectId, volume, pan, 0, -1);

    func_801C0D40(handle, (f32)(speed - 128) / *(f64 *)((u8 *)&D_80108750 + 4)); /* MusHandleSetFreqOffset */
    func_801C0DAC(handle, speed); /* MusHandleSetTempo */
    return handle;
}

extern s16 D_801EF48C;
extern s32 D_801EF490;

/* Install a timed sound cue table (D_801EF490) and reset the triggered cue counter (D_801EF48C). */
void func_80179468(s32 cueTable) {
    D_801EF48C = 0;
    D_801EF490 = cueTable;
}

/* One timed sound cue of a cue table (installed by func_80179468); a negative startStep ends the table. */
typedef struct {
    /* 0x0 */ s16 startStep;    /* cue frame: step (+ subStep fraction) */
    /* 0x2 */ u16 startSubStep;
    /* 0x4 */ s16 stopStep;     /* -1: never stopped by time */
    /* 0x6 */ u16 stopSubStep;
    /* 0x8 */ s16 effectId;     /* libmus effect number */
    /* 0xA */ u8 volume;
    /* 0xB */ u8 pitch;         /* SOUND_PITCH_NORMAL = unchanged; 0 means the same */
    /* 0xC */ s32 handle;       /* libmus handle of the playing effect */
} SoundCue;

extern s32 D_801EF494;
extern f64 D_80108760;
extern f64 D_80108768;
extern f64 D_80108770;
extern f64 D_80108778;


/* Returns 1 when the state frame counter D_802004E0 has reached a cue time.
 * With the default cue table (D_801EF490 == &D_801EF494) the cue frame is
 * step + 4; otherwise it is step * 20 + subStep * 0.8 (f64 0.8 stored at
 * D_80108758 + 4). */
s32 func_80179480(s16 step, s16 subStep) {
    if (D_801EF490 == (s32)&D_801EF494) {
        if (D_802004E0 != step + 4) {
            goto notYet;
        }
        return 1;
    }
    if (D_802004E0 != (s16)((s16)(step * 5 << 2) + (f32)((f32)subStep * *(f64 *)((u8 *)&D_80108758 + 4)))) {
        goto notYet;
    }
    return 1;
notYet:
    return 0;
}

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
    s32 ti;
    f64 x;
    f64 k;
    f64 prod;

    if (D_801EF490 == (s32)&D_801EF494) {
        if (D_802004E0 != id + 4) {
            goto fail;
        }
        return 1;
    }
    ti = t;
    do {
        do {
            do {
                do {
                    k = *(const f64 *)((const u8 *)&D_80108768 + 4);
                } while (0);
            } while (0);
        } while (0);
    } while (0);
    x = (f32)ti;
    prod = x * k;
    if (D_802004E0 != (s16)((s16)(id * 5 << 2) + (f32)prod)) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}

/* Runs the current sound cue table (D_801EF490): stops every cue whose stop time has come
 * (or all of them while flag 1 of D_801E7584 is set), then starts every cue whose start
 * time has come with its volume and pitch. A started cue with startStep -1 ends the table. */
void func_80179524(void) {
    SoundCue *cue = (SoundCue *)D_801EF490;
    u8 pitch;
    s32 handle;
    s16 startStep;
    s32 effectId;
    if (cue == 0) return;
    if (cue->startStep >= 0) {
        do {
            if (cue->stopStep != -1 || (D_801E7584 & 1)) {
                if ((D_801E7584 & 1) || check_sound1(cue->stopStep, cue->stopSubStep)) func_801C0B70(cue->handle, 0);
            }
            cue++;
        } while (cue->startStep >= 0);
    }
    if (D_801E7584 & 1) return;
    cue = (SoundCue *)D_801EF490;
    startStep = cue->startStep;
    if (startStep >= 0) {
        do {
            if (check_sound2(cue->startSubStep, startStep)) {
                effectId = cue->effectId;
                pitch = cue->pitch;
                if (pitch == 0) pitch = SOUND_PITCH_NORMAL;
                /* libmus MusStartEffect2, MusHandleSetFreqOffset, MusHandleSetTempo */
                handle = func_801C08E4(effectId, cue->volume, 0x80, 0, -1);
                func_801C0D40(handle, (f32)(pitch - SOUND_PITCH_NORMAL) / *(f64 *)((u8 *)&D_80108770 + 4));
                func_801C0DAC(handle, pitch);
                cue->handle = handle;
                if (cue->effectId == SOUND_ID_SLOW_FADE) func_801C0E3C(handle, SOUND_CUE_SLOW_FADE_FX_MIX);
                D_801EF48C++;
                if (cue->startStep == -1) {
                    D_801EF490 = 0;
                    return;
                }
            }
            cue++;
            startStep = cue->startStep;
        } while (startStep >= 0);
    }
}

/* Original compiler padding. */
const u32 D_80179808_padding[] __attribute__((section(".text"))) = {
    0x24360000
};
const u32 D_80179808_padding_tail[] __attribute__((section(".text"))) = { 0 };

typedef ActorVectorWords Vec3I179F5C;
typedef ActorSoundOwnerView Sub179F5C;
typedef ActorCleanupView Actor179F5C;
typedef ActorReferenceSlots Holder179F5C;
typedef ActorCleanupNodeView Node179F5C;


extern u32 D_802904D0;

extern f64 D_801087A8;
extern f32 D_801087B0;
extern f32 D_801087B4;
extern f64 D_801087B8;
extern f32 D_801087A4;
/*
 * Update the breakable-object list (head D_802904D4, count D_802904D0).
 * Every object flagged as broken (flags & 2) plays its break sound, throws
 * debris particles from its break description (+0x24) inside its extent,
 * then is removed (func_80179F5C), and the scan restarts. The surviving
 * objects are then updated, jittered around their path point and attached.
 */
void func_80179810(void) {
    Vec3F velocity;
    Vec3F spawnPos;
    u8 *spark;
    u8 *obj;
    u8 *next;
    u8 *breakInfo;
    s32 i;
    s32 j;
    s32 range;
    f32 extent;
    f32 two31;
    u32 hibit;
    f64 velocityScale;
    Vec3F *spawnPosPtr;
    f32 ten;
    f32 five;

    obj = *(u8 **)&D_802904D4;
    i = 0;
    if (i < (s32)D_802904D0) {
        two31 = D_801087A4;
        hibit = 0x80000000;
        velocityScale = D_801087A8;
        spawnPosPtr = &spawnPos;
        ten = D_801087B0;
        do {
            i++;
            if (*(s32 *)(obj + 0x14) & 2) {
                if (*(u8 **)(obj + 0x24) != NULL) {
                    /* Object type 0x74 on level 0x23: flash and a burst of sparks. */
                    if (*(s16 *)(obj + 0x6C) == 0x74 && D_801E7531 == 0x23) {
                        func_8014D61C(0xDC, 0x64, 0x64, 0xFF, -0x1E);
                        for (j = 0; j < 20; j++) {
                            spark = func_801AA5BC(4);
                            *(Vec3F *)(spark + 0x3C) = *(Vec3F *)(obj + 0xB4);
                            *(f32 *)(spark + 0x60) = func_80147000(0x28) - 0x14;
                            *(f32 *)(spark + 0x64) = func_80147000(0x28) - 0x14;
                            *(f32 *)(spark + 0x68) = func_80147000(0x28) - 0x14;
                            func_801A96A8(spark, 0, 0);
                            func_801A8E54(spark);
                            *(s16 *)(spark + 0x118) = func_80147000(0x100) + 0xD4;
                            *(s16 *)(spark + 0x11A) = func_80147000(0x38) + 0x100;
                            *(s16 *)(spark + 0x150) = func_80147000(0x100) + 0xD4;
                            *(s16 *)(spark + 0x152) = func_80147000(0x38) + 0x100;
                            func_801793DC(0x63, 0x64, 0x80, 0x80);
                        }
                    }
                    breakInfo = *(u8 **)(obj + 0x24);
                    if (*(s16 *)(breakInfo + 0xE) != 0) {
                        func_80178134(*(s16 *)(breakInfo + 0xE), (f32 *)(obj + 0xB4), *(s16 *)(breakInfo + 0xA), *(s16 *)(breakInfo + 0xC));
                    }
                    /* breakInfo->count debris pieces at random points in the extent. */
                    j = 0;
                    if (j < **(s32 **)(obj + 0x24)) {
                        five = D_801087B4;
                        do {
                            spawnPos = *(Vec3F *)(obj + 0xB4);
                            extent = *(f32 *)(obj + 0x8) * 2.0f;
                            if (!(two31 <= extent)) { range = extent; } else { range = extent - two31; range |= hibit; }
                            spawnPos.x += (f32)func_80147000(range) - *(f32 *)(obj + 0x8);
                            extent = *(f32 *)(obj + 0xC) * 2.0f;
                            if (!(two31 <= extent)) { range = extent; } else { range = extent - two31; range |= hibit; }
                            spawnPos.y += (f32)func_80147000(range) - *(f32 *)(obj + 0xC);
                            extent = *(f32 *)(obj + 0x10) * 2.0f;
                            if (!(two31 <= extent)) { range = extent; } else { range = extent - two31; range |= hibit; }
                            spawnPos.z += (f32)func_80147000(range) - *(f32 *)(obj + 0x10);
                            velocity.x = spawnPos.x - *(f32 *)(obj + 0xB4);
                            velocity.y = spawnPos.y - *(f32 *)(obj + 0xB8);
                            velocity.z = spawnPos.z - *(f32 *)(obj + 0xBC);
                            velocity.x *= velocityScale;
                            velocity.y *= velocityScale;
                            velocity.z *= velocityScale;
                            velocity.y = func_80147000(10) + 5;
                            spark = (u8 *)func_801B66D4(4, spawnPosPtr, &velocity, 0, 0);
                            if (spark != NULL) {
                                *(s32 *)(spark + 0x28) |= 0x10000;
                                *(s32 *)(spark + 0xC8) = *(s32 *)(*(u8 **)(obj + 0x24) + 4);
                                *(f32 *)(spark + 0xBC) *= (f32)(func_80147000(6) + 6) / ten;
                                *(f32 *)(spark + 0xC0) *= (f32)(func_80147000(6) + 6) / ten;
                                *(f32 *)(spark + 0xC4) *= (f32)(func_80147000(6) + 6) / ten;
                                *(f32 *)(spark + 0x90) = (f32)func_80147000(10) / five;
                                *(f32 *)(spark + 0x94) = (f32)func_80147000(10) / five;
                            }
                            if (!(*(s32 *)(obj + 0x14) & 0x80000)) {
                                velocity.x = (f32)(func_80147000(0x65) - 0x32) / ten;
                                velocity.z = (f32)(func_80147000(0x65) - 0x32) / ten;
                                velocity.y = (f32)func_80147000(0x65) / ten;
                                func_801B66D4(2, spawnPosPtr, &velocity, 0, 0);
                            }
                            j++;
                        } while (j < **(s32 **)(obj + 0x24));
                    }
                }
                if (!(*(s32 *)(obj + 0x14) & 0x80000)) {
                    func_801B70F8(obj + 0xB4, 5, 8.0f, 2.0f);
                }
                /* Remove it and rescan from the head. */
                func_80179F5C((Actor179F5C *)obj, 1);
                next = *(u8 **)&D_802904D4;
                i = 0;
            } else {
                next = *(u8 **)obj;
            }
            obj = next;
        } while (i < (s32)D_802904D0);
    }
    for (spark = *(u8 **)&D_802904D4; spark != (u8 *)&D_802904D4; spark = *(u8 **)spark) {
        func_8017CF00((Obj8017CF00 *)spark);
        breakInfo = *(u8 **)(spark + 0x3C);
        if (breakInfo != NULL && *(s16 *)breakInfo != 0 &&
            (*(f32 *)(breakInfo + 8) == 0.0f || *(s16 *)(breakInfo + 4) >= *(s16 *)breakInfo)) {
            *(f32 *)(spark + 0xB4) = *(f32 *)(*(u8 **)(spark + 0x3C) + 0xC) + (f32)(func_80147000(0x19) - 0xD) / *(const f64 *)&D_801087B8;
            *(f32 *)(spark + 0xBC) = *(f32 *)(*(u8 **)(spark + 0x3C) + 0x14) + (f32)(func_80147000(0x19) - 0xD) / *(const f64 *)&D_801087B8;
        }
        if (*(u8 **)(spark + 0x2C) != NULL && !(*(s32 *)(spark + 0xA8) & 0x4000)) {
            func_8015C350(spark + 0x11C, *(u8 **)(spark + 0x2C) + 0x38);
        }
    }
    func_8017DC10();
}

/* Empties the platform list: zeroes the platform count (D_802904D0) and points the
 * list sentinel's next and prev (D_802904D4 / +4) back at itself. */
void func_80179EAC(void) {
    s32 *count = (s32 *)&D_802904D0;
    s32 *sentinel = count + 1;

    *count = 0;
    *(s32 *)((u8 *)count + 8) = (s32)sentinel; /* sentinel->prev */
    sentinel[0] = (s32)sentinel;
}

extern s32 *volatile D_802904D8;

/* Append a platform to the tail of the circular platform list (count D_802904D0,
 * sentinel D_802904D4 whose prev link is D_802904D8), unless it is already linked.
 * A node's word 0 is its next link and word 1 its prev link. */
void func_80179ECC(s32 *platform) {
    s32 *count;
    s32 *sentinel;

    if (platform[0] != 0) {
        return;
    }
    count = (s32 *)&D_802904D0;
    (*count)++;
    sentinel = count + 1;
    platform[0] = (s32)sentinel;
    *(volatile s32 *)&platform[1] = (s32)D_802904D8;
    D_802904D8[0] = (s32)platform;
    D_802904D8 = platform;
}

/* Unlink a node from the circular list counted by D_802904D0 (sentinel D_802904D4),
 * if it is linked. next is the node's next link, unk004 its prev link. */
void func_80179F1C(ObjectNode *node) {
    if (node->next != 0) {
        ((ObjectNode *)node->unk004)->next = node->next;
        ((ObjectNode *)node->next)->unk004 = node->unk004;
        node->next = 0;
        *(volatile u32 *)&D_802904D0 = *(volatile u32 *)&D_802904D0 - 1;
    }
}

/* Destroy an actor, clear references and attached resources, and optionally destroy its children. */
void func_80179F5C(ActorCleanupView *actor, s32 destroyChildren) {
    extern ActorCleanupNodeView D_8029F170;
    extern ObjectNode *D_80290130;
    extern ParticleActiveFieldView D_802A20E4[];
    extern ParticleActorRefsFieldView D_802A20D8[];
    extern ActorCleanupNodeView D_802A2000[];
    s32 actorsVisited = 0;
    ActorCleanupNodeView *effect;
    ActorCleanupNodeView *nextEffect;
    ActorCleanupNodeView *effectList;
    ActorCleanupNodeView *object;
    s32 allocationIndex;

    if (actor->unk164 != 0) {
        func_80178704(&actor->unk164);
    }
    if (actor->unk2C != 0 && actor->unk2C->unk74 != 0) {
        func_80178704(&actor->unk2C->unk74);
    }
    if (actor->unk28 != 0 && actor->unk28->unk28 != 0) {
        func_80178704(&actor->unk28->unk28);
    }
    if (actor->unk3C != 0 && actor->unk3C->unk18 != 0) {
        func_80178704(&actor->unk3C->unk18);
    }
    effect = D_8029F170.next;
    if (effect != &D_8029F170) {
        effectList = &D_8029F170;
        do {
            nextEffect = effect->next;
            if (effect->unkC == actor) {
                if ((ObjectNode *)effect == D_80290130) {
                    func_801499A0((s32)&effect->x, (s32)&effect->x, (s32)&actor->unk11C);
                    effect->x += effect->unkC->x;
                    effect->y += effect->unkC->y;
                    effect->z += effect->unkC->z;
                    *(ActorVectorWords *)&effect->u20 = *(ActorVectorWords *)effect->unk10;
                    effect->unkC = 0;
                    effect->unk10 = 0;
                } else {
                    func_801A6AEC((ObjectNode *)effect);
                }
            }
            effect = nextEffect;
        } while (effect != effectList);
    }
    object = (ActorCleanupNodeView *)D_8026A148.next;
    if (object != (ActorCleanupNodeView *)&D_8026A148) {
        do {
            if (object->holder != 0) {
                if (object->holder->slot[0] == actor) {
                    object->holder->slot[0] = 0;
                }
                if (object->holder->slot[1] == actor) {
                    object->holder->slot[1] = 0;
                }
                if (object->holder->slot[2] == actor) {
                    object->holder->slot[2] = 0;
                }
                if (object->holder->slot[3] == actor) {
                    object->holder->slot[3] = 0;
                }
            }
            object = object->next;
        } while (object != (ActorCleanupNodeView *)&D_8026A148);
    }
    for (allocationIndex = 0; allocationIndex < PARTICLE_POOL_CAPACITY; allocationIndex++) {
        ActorCleanupNodeView *particle = &D_802A2000[allocationIndex];

        if (D_802A20E4[allocationIndex].flag != 0 && D_802A20D8[allocationIndex].holder != 0) {
            if (particle->holder->slot[0] == actor) {
                particle->holder->slot[0] = 0;
            }
            if (particle->holder->slot[1] == actor) {
                particle->holder->slot[1] = 0;
            }
            if (particle->holder->slot[2] == actor) {
                particle->holder->slot[2] = 0;
            }
            if (particle->holder->slot[3] == actor) {
                particle->holder->slot[3] = 0;
            }
        }
    }
    func_801627AC((s32)actor + ACTOR_OBJECT_OFFSET);
    if (destroyChildren != 0) {
        Unk802904D4Node *child = D_802904D4.next;

        while (actorsVisited < (s32)D_802904D0) {
            actorsVisited++;
            if (((ActorCleanupNodeView *)child)->u20 == (s32)actor) {
                func_80179F5C((ActorCleanupView *)child, 1);
                child = D_802904D4.next;
                actorsVisited = 0;
            } else {
                child = child->next;
            }
        }
    }
    if (actor->next != 0) {
        actor->prev->next = actor->next;
        actor->next->prev = actor->prev;
        *(volatile s32 *)&actor->next = 0;
        D_802904D0 = D_802904D0 - 1;
    }
    if (actor->unk38 != 0) {
        allocationIndex = 0;
        do {
            func_80141720((s32 *)((s32)actor->unk38 + allocationIndex * 4));
            allocationIndex++;
        } while (allocationIndex < ACTOR_OWNED_ALLOCATION_COUNT);
        func_80141720((s32 *)&actor->unk38);
    }
    func_80141720((s32 *)&actor->unk30);
    func_80141720((s32 *)&actor->unk48);
    func_80141720((s32 *)&actor->unk4C);
    func_80141720((s32 *)&actor->unk50);
    func_80141720((s32 *)&actor->unk54);
    func_80141720((s32 *)&actor->unk2C);
    func_80141720((s32 *)&actor->unk3C);
    func_80141720((s32 *)&actor->unk28);
    func_80141720((s32 *)&actor->unk34);
    func_80141720((s32 *)&actor->unk44);
    func_80141720((s32 *)&actor->unk44);
    func_80141720((s32 *)&actor->unk40);
    func_80141720((s32 *)&actor->unk160);
    func_80141720((s32 *)&actor->unk24);
    func_80141720((s32 *)&actor->unk58);
    func_80141720((s32 *)&actor);
}

/* platform_update_stretch: oscillate scale between endpoints, pausing at each reversal. */
void func_8017A38C(u8 *platform) {
    PlatformScaleView *object = (PlatformScaleView *)platform;
    PlatformStretchState *stretch = *(PlatformStretchState **)(platform + PLATFORM_STRETCH);
    PlatformStretchState *stepState;
    PlatformStretchState *snapState;
    PlatformStretchState *reverseState;
    extern f64 D_801087C0;
    s32 axis;
    s32 snappedAxes;
    f32 distance;

    if (stretch == 0) {
        return;
    }
    if (stretch->travelFrames == 0) {
        return;
    }
    snappedAxes = 0;
    if (stretch->directionAndWait >= 2) {
        stretch->directionAndWait = stretch->directionAndWait - 1;
    } else if (stretch->directionAndWait < -1) {
        stretch->directionAndWait = stretch->directionAndWait + 1;
    } else if (stretch->directionAndWait != 0) {
        for (axis = 0; axis < 3; axis++) {
            stepState = *(PlatformStretchState **)(platform + PLATFORM_STRETCH);
            if (stepState->directionAndWait == 1) {
                object->scale[axis] = object->scale[axis] + (stepState->endScale[axis] - stepState->startScale[axis]) / (f32)stepState->travelFrames;
            } else {
                object->scale[axis] = object->scale[axis] - (stepState->endScale[axis] - stepState->startScale[axis]) / (f32)stepState->travelFrames;
            }
            snapState = *(PlatformStretchState **)(platform + PLATFORM_STRETCH);
            distance = object->scale[axis] - snapState->endScale[axis];
            if (!(distance > 0.0f)) {
                distance = -distance;
            }
            if ((f64)distance <= D_801087C0) {
                snappedAxes++;
                object->scale[axis] = snapState->endScale[axis];
            } else {
                distance = object->scale[axis] - snapState->startScale[axis];
                if (!(distance > 0.0f)) {
                    distance = -distance;
                }
                if ((f64)distance <= D_801087C0) {
                    snappedAxes++;
                    object->scale[axis] = snapState->startScale[axis];
                }
            }
        }
    }
    if (snappedAxes == 3) {
        reverseState = *(PlatformStretchState **)(platform + PLATFORM_STRETCH);
        reverseState->directionAndWait = -reverseState->directionAndWait * (reverseState->waitFrames + 1); } }

/* Update a triggered falling platform, fade its sound, and restore it after expiry. */
void func_8017A514(u8 *platform) {
    extern s32 D_802900E0;
    extern f32 D_801ED680;
    FallingPlatformView *object = (FallingPlatformView *)platform;
    s16 frame;
    s32 previousFrame;
    FallingPlatformState *fall = object->fall;

    if (fall == 0) {
        return;
    }
    frame = fall->frame;
    previousFrame = frame;
    if (previousFrame <= 0) {
        return;
    }
    if (fall->disappearFrame + FALL_PLATFORM_RESET_DELAY < previousFrame || *(s16 *)(*(u8 **)(*(u8 **)&D_802900E0 + 0x54) + 2) != 0) {
        object->position = *(Vec3Words *)((u8 *)fall + FALL_PLATFORM_INITIAL_POSITION);
        object->unkA6 = FALL_PLATFORM_RESET_UNKA6;
        object->velocityX = object->velocityY = object->velocityZ = 0.0f;
        object->flags &= ~FALL_PLATFORM_DISAPPEARED;
        object->fall->frame = 0;
        return;
    }
    fall->frame = frame + 1;
    if (object->fall->disappearFrame < previousFrame) {
        object->flags |= FALL_PLATFORM_DISAPPEARED;
        object->unkA6 = 0;
        if (object->fall->soundHandle != 0) {
            func_80178704(&object->fall->soundHandle);
        }
    }
    if (object->fall->frame > object->fall->fallStartFrame) {
        object->velocityY -= D_801ED680 * object->fall->gravityScale;
    }
    if (object->fall->soundId == 0) {
        return;
    }
    if (object->fall->frame > object->fall->fallStartFrame) {
        object->fall->soundVolume -= FALL_PLATFORM_SOUND_FADE_STEP;
        if (object->fall->soundVolume <= 0) {
            func_80178704(&object->fall->soundHandle);
            return;
        }
    } else if (object->fall->soundHandle == 0) {
        func_801785E0(&object->fall->soundHandle, object->fall->soundId, object->fall->initialSoundVolume, (s32)&object->position, object->fall->soundPitch);
    }
    func_80178760(&object->fall->soundHandle);
}

typedef struct { f32 x, y, z; u16 unk0C; s16 unk0E; u8 pad10[0x2]; s16 unk12; s16 unk14; s16 unk16; } Wp6B8;
typedef struct { Wp6B8 *wp[20]; s16 timer; u8 pad52[2]; s8 dir; u8 count; u8 cur; u8 prev; f32 accel; } Path6B8;
typedef struct { u8 pad0[0x38]; f32 unk38; f32 unk3C; u8 pad40[0x20]; f32 unk60; } Rot6B8;
typedef struct { u8 pad0[0x20]; f32 scale; s16 id; u8 pad26[2]; f32 x, y, z; } Link6B8;
typedef struct Obj6B8 { u8 pad0[0x14]; s32 flags; u8 pad18[4]; f32 maxSpeed; struct Obj6B8 *parent; u8 pad24[8]; Rot6B8 *rot; u8 pad30[4]; Link6B8 *link; Path6B8 *path; u8 pad3C[0x3C]; u16 unk78; u8 pad7A[0x3A]; Vec3F pos; u8 padC0[0x18]; f32 vx, vy, vz; u8 padE4[0xC]; f32 damp; f32 speed; } Obj6B8;

/*
 * Moves a path-following platform one frame toward `target` (relative to its
 * parent when it has one): damps its velocity, handles waypoint wait timers and
 * arrival (sound, turn, ping-pong), accelerates/brakes toward the waypoint, caps
 * the speed, and feeds the speed to every linked node in D_802904D4.
 */
void func_8017A6B8(Obj6B8 *platform, Vec3F *target) {
    s32 moving;
    Wp6B8 *waypoint;
    Unk802904D4Node *node;
    Vec3F from;
    Vec3F delta;
    f32 distSq;
    f32 brakeDist;

    platform->vx *= platform->damp;
    platform->vy *= platform->damp;
    platform->vz *= platform->damp;
    moving = 1;
    if (platform->path != 0 && platform->path->count >= 2) {
        /* Timers -9..-4 / -15..-10 wait while the ball / player stands on it. */
        if (platform->path->timer >= -9 && platform->path->timer <= -4) {
            if (*(Obj6B8 **)(D_8029FA50 + 0x178) == platform) {
                platform->path->timer = -4;
            } else if (--platform->path->timer == -10) {
                platform->path->timer = 1;
            }
        }
        if (platform->path->timer >= -15 && platform->path->timer <= -10) {
            if (*(Obj6B8 **)(D_802903B0 + 0x178) == platform) {
                platform->path->timer = -10;
            } else if (--platform->path->timer == -16) {
                platform->path->timer = 1;
            }
        }
        if (platform->path->timer > 0) {
            if (--platform->path->timer == 0) {
                Path6B8 *path = platform->path; path->cur = (path->cur + path->count + path->dir) % path->count; } } else if (platform->path->timer == 0 && (!(platform->flags & 0x1000) || platform->rot->unk3C == platform->rot->unk60 || (platform->flags & 0x2000))) {
            if (platform->parent != 0) {
                from.x = platform->pos.x - platform->parent->pos.x;
                from.y = platform->pos.y - platform->parent->pos.y;
                from.z = platform->pos.z - platform->parent->pos.z;
            } else {
                from = platform->pos;
            }
            delta.x = target->x - from.x;
            delta.y = target->y - from.y;
            delta.z = target->z - from.z;
            distSq = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            if (distSq <= platform->speed * platform->speed) {
                /* Arrived at the waypoint. */
                if (!(platform->flags & 0x2000)) {
                    moving = 0;
                    if (platform->parent != 0) {
                        platform->pos.x = target->x + platform->parent->pos.x;
                        platform->pos.y = target->y + platform->parent->pos.y;
                        platform->pos.z = target->z + platform->parent->pos.z;
                    } else {
                        platform->pos = *target;
                    }
                    do {
                        *(Vec3F *)&platform->vx = *(Vec3F *)&D_801ED3C4;
                        platform->speed = 0.0f;
                    } while (0);
                }
                platform->path->timer = platform->path->wp[platform->path->cur]->unk0C;
                platform->path->prev = platform->path->cur;
                waypoint = platform->path->wp[platform->path->prev];
                if (waypoint->unk16 != 0) {
                    func_80178134(waypoint->unk16, (f32 *)&platform->pos, waypoint->unk12, waypoint->unk14);
                }
                if (platform->flags & 0x1000) {
                    waypoint = platform->path->wp[(platform->path->cur + platform->path->count + platform->path->dir) % platform->path->count];
                    platform->rot->unk60 = func_801496C8(func_80147460(platform->pos.x - waypoint->x, platform->pos.z - waypoint->z));
                }
                if (platform->flags & 0x20) {
                    if (platform->path->prev == 0 || platform->path->prev == platform->path->count - 1) {
                        platform->path->dir = -platform->path->dir;
                    }
                }
                if ((platform->unk78 & 2) || (platform->path->prev == 0 && (platform->unk78 & 1))) {
                    platform->unk78 |= 0x800;
                }
            }
            if (moving) {
                if (platform->unk78 & 0x800) {
                    platform->speed = 0.0f;
                    platform->vx = platform->vy = platform->vz = platform->speed;
                } else {
                    if (platform->flags & 0x2000) {
                        Path6B8 *pathX = platform->path;
                        Path6B8 *pathY;
                        Path6B8 *pathZ;

                        platform->vx -= pathX->accel * func_801C6000(platform->rot->unk3C);
                        pathY = platform->path;
                        platform->vy += pathY->accel * func_801C6000(platform->rot->unk38);
                        pathZ = platform->path;
                        platform->vz -= pathZ->accel * func_801C4040(platform->rot->unk3C);
                    } else {
                        brakeDist = (platform->path->accel + platform->speed) * platform->speed / (platform->path->accel + platform->path->accel);
                        func_80149568((f32 *)&delta);
                        if (distSq < brakeDist * brakeDist) {
                            if (platform->path->accel < platform->speed) {
                                func_80148D0C(&platform->vx, (f32 *)&delta, -platform->path->accel);
                            }
                        } else {
                            func_80148D0C(&platform->vx, (f32 *)&delta, platform->path->accel);
                        }
                    }
                    platform->speed = sqrtf(platform->vx * platform->vx + platform->vy * platform->vy + platform->vz * platform->vz);
                    if (platform->maxSpeed < platform->speed) {
                        platform->vx *= platform->maxSpeed / platform->speed;
                        platform->vy *= platform->maxSpeed / platform->speed;
                        platform->vz *= platform->maxSpeed / platform->speed;
                        platform->speed = platform->maxSpeed;
                    }
                }
            }
        } else if (platform->path->timer == -100) {
            platform->path->timer--;
        }
    } else {
        platform->speed = sqrtf(platform->vx * platform->vx + platform->vy * platform->vy + platform->vz * platform->vz);
    }
    if (platform->link != 0 && platform->link->scale != 0.0f) {
        for (node = func_8017DBD8(&D_802904D4, platform->link->id); node != 0; node = func_8017DBD8(node, platform->link->id)) {
            **(f32 **)((u8 *)node + 0x2C) = (platform->vx * platform->link->x + platform->vy * platform->link->y + platform->vz * platform->link->z) * platform->link->scale;
        }
    }
}

/* Apply ancestor translation and parent rotation to this platform, its velocity and path target. */
void func_8017AE0C(u8 *platform, Vec3F *pathTarget) {
    u8 *parent;
    u8 *rotation;
    u8 *path;
    s32 rotationAxis;
    s32 axis;
    s32 axisOffset;
    Vec3F relativePosition;

    *(Vec3F *)(platform + PLATFORM_FRAME_START_POSITION) = *(Vec3F *)(platform + PLATFORM_POSITION);
    parent = *(u8 **)(platform + PLATFORM_PARENT);
    if (parent != 0) {
        do {
            for (axis = 0; axis < 3; axis++) {
                ((f32 *)platform)[PLATFORM_POSITION / 4 + axis] += ((f32 *)parent)[PLATFORM_POSITION / 4 + axis] - ((f32 *)parent)[PLATFORM_PREVIOUS_POSITION / 4 + axis];
            }
            parent = *(u8 **)(parent + PLATFORM_PARENT);
        } while (parent != 0);
    }
    parent = *(u8 **)(platform + PLATFORM_PARENT);
    *(Vec3F *)(platform + PLATFORM_PREVIOUS_POSITION) = *(Vec3F *)(platform + PLATFORM_POSITION);
    rotation = *(u8 **)(platform + PLATFORM_ROTATION);
    if (rotation != 0) {
        *(Vec3F *)(rotation + PLATFORM_ROTATION_PREVIOUS_ANGLES) = *(Vec3F *)(rotation + PLATFORM_ROTATION_ANGLES);
    }
    path = *(u8 **)(platform + PLATFORM_PATH);
    if (path != 0 && path[PLATFORM_PATH_COUNT] >= 2) {
        *pathTarget = **(Vec3F **)(path + path[PLATFORM_PATH_CURRENT] * 4);
    }
    if (parent != 0 && *(u8 **)(parent + PLATFORM_ROTATION) != 0) {
        f32 angleDelta = *(f32 *)(*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_YAW) - *(f32 *)(*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_YAW);
        if (angleDelta != 0.0f) {
            func_801490AC((Vec3F *)(platform + PLATFORM_VELOCITY), (Vec3F *)(platform + PLATFORM_VELOCITY), angleDelta);
        } else {
            angleDelta = *(f32 *)(*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) - *(f32 *)(*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES);
            if (angleDelta != 0.0f) {
                func_8014915C((Vec3F *)(platform + PLATFORM_VELOCITY), (Vec3F *)(platform + PLATFORM_VELOCITY), angleDelta, 0);
            } else {
                angleDelta = *(f32 *)(*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_ROLL) - *(f32 *)(*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ROLL);
                if (angleDelta != 0.0f) {
                    func_8014915C((Vec3F *)(platform + PLATFORM_VELOCITY), (Vec3F *)(platform + PLATFORM_VELOCITY), angleDelta, 2);
                }
            }
        }
        rotationAxis = PLATFORM_ROTATION_NO_AXIS;
        for (axis = 0; axis < 3; axis++) {
            if (*(s32 *)(platform + PLATFORM_FLAGS) & PLATFORM_INHERIT_ROTATION) {
                u8 *parentRotation = *(u8 **)(parent + PLATFORM_ROTATION);
                if (parentRotation != 0) {
                    f32 parentAngle, previousParentAngle;
                    axisOffset = axis << 2;
                    parentAngle = *(f32 *)(axisOffset + (s32)parentRotation + PLATFORM_ROTATION_ANGLES);
                    previousParentAngle = *(f32 *)(axisOffset + (s32)parentRotation + PLATFORM_ROTATION_PREVIOUS_ANGLES);
                    if (parentAngle != previousParentAngle) {
                        *(f32 *)(axisOffset + (s32)*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) = func_801496C8(*(f32 *)(axisOffset + (s32)*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) + parentAngle - previousParentAngle);
                        *(f32 *)(axisOffset + (s32)*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_TARGET_ANGLES) = func_801496C8(*(f32 *)(axisOffset + (s32)*(u8 **)(platform + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) + *(f32 *)(axisOffset + (s32)*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) - *(f32 *)(axisOffset + (s32)*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES));
                    }
                }
            }
            if (*(s8 *)(*(u8 **)(parent + PLATFORM_ROTATION) + axis + PLATFORM_ROTATION_AXES) != 0) {
                rotationAxis = axis;
            }
        }
        if (rotationAxis != PLATFORM_ROTATION_NO_AXIS) {
            u8 *childPath;
            axisOffset = rotationAxis << 2;
            axis = (s8)rotationAxis;
            relativePosition.x = *(f32 *)(platform + PLATFORM_POSITION) - *(f32 *)(parent + PLATFORM_POSITION);
            relativePosition.y = *(f32 *)(platform + PLATFORM_POSITION_Y) - *(f32 *)(parent + PLATFORM_POSITION_Y);
            relativePosition.z = *(f32 *)(platform + PLATFORM_POSITION_Z) - *(f32 *)(parent + PLATFORM_POSITION_Z);
            func_8014915C(&relativePosition, &relativePosition, *(f32 *)(axisOffset + (s32)*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES) - *(f32 *)(axisOffset + (s32)*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_PREVIOUS_ANGLES), axis);
            *(f32 *)(platform + PLATFORM_POSITION) = *(f32 *)(parent + PLATFORM_POSITION) + relativePosition.x;
            *(f32 *)(platform + PLATFORM_POSITION_Y) = *(f32 *)(parent + PLATFORM_POSITION_Y) + relativePosition.y;
            *(f32 *)(platform + PLATFORM_POSITION_Z) = *(f32 *)(parent + PLATFORM_POSITION_Z) + relativePosition.z;
            childPath = *(u8 **)(platform + PLATFORM_PATH);
            if (childPath != 0 && childPath[PLATFORM_PATH_COUNT] >= 2) {
                func_8014915C(pathTarget, *(Vec3F **)(childPath + childPath[PLATFORM_PATH_CURRENT] * 4), *(f32 *)(axisOffset + (s32)*(u8 **)(parent + PLATFORM_ROTATION) + PLATFORM_ROTATION_ANGLES), axis);
            }
        }
    }
}

/* Update object spin and rotation targets, pausing or reversing at stops and playing their sound cues. */
void func_8017B178(u8 *object) {
    extern f64 D_801087C8;
    extern f64 D_801087D0;
    extern const f64 D_801087D8;
#define P (*(ObjectRotation **)(object + 0x2C))
    f32 spinQuaternion[4];
    f32 axisAngle[4];
    f32 restoreQuaternion[4];
    s32 axis;
    f32 currentAngle;
    f32 targetAngle;
    f32 angleDistance;
    f32 zero;
    f64 fullTurn;

    if (*(s32 *)(object + 0xA8) & OBJECT_APPLY_SPIN) {
        func_80148C3C(spinQuaternion, (f32 *)(object + 0x12C));
        func_801488C0((Quat801488C0 *)(object + 0x11C), spinQuaternion, (f32 *)(object + 0x11C));
        *(f32 *)(object + 0x138) *= P->spinDamping;
    }
    if (*(s32 *)(object + 0x14) & OBJECT_RESTORE_ROTATION) {
        func_801489F0(axisAngle, (f32 *)(object + 0x11C));
        if ((f64)*(f32 *)(object + 0x128) > D_801087C8) {
            *(QuaternionWords *)(object + 0x11C) = *(QuaternionWords *)&D_801ED3D0;
            *(f32 *)(object + 0x138) = 0.0f;
        } else {
            if (axisAngle[3] > P->restoreAngleLimit) {
                *(f32 *)(object + 0x138) = 0.0f;
            }
            axisAngle[3] = -(P->restoreStep * axisAngle[3]) / P->restoreAngleLimit;
            func_80148C3C(restoreQuaternion, axisAngle);
            func_801488C0((Quat801488C0 *)(object + 0x11C), restoreQuaternion, (f32 *)(object + 0x11C));
            func_801489F0(axisAngle, (f32 *)(object + 0x11C));
        }
    }
    if (P == 0 || P->angularStep == 0.0f) {
        return;
    }
    axis = 0;
    zero = 0.0f;
    fullTurn = D_801087D0;
    for (; axis < 3; axis++) {
        if (P->axisEnabled[axis] == 0) {
            continue;
        }
        if (P->delay > 0) {
            P->delay--;
            if ((*(s32 *)&P->stopCount & 0xFF00FFFF) == 0x01000000) {
                P->delay = ROTATION_RESTART_DELAY;
            }
        } else if (P->delay == 0) {
            if (P->stopCount != 0) {
                currentAngle = func_801496C8(P->angles[axis]);
                if (P->angularStep < zero) {
                    targetAngle = func_801496C8(fullTurn - P->nextStop * fullTurn / P->stopCount + P->baseAngle); } else { targetAngle = func_801496C8(P->nextStop * fullTurn / P->stopCount + P->baseAngle); } angleDistance = func_8014944C(currentAngle, targetAngle); if (angleDistance < (P->angularStep > zero ? P->angularStep : -P->angularStep)) { P->delay = P->pauseFrames; P->angularVelocity[axis] = 0.0f; if ((f64)angleDistance < D_801087D8) { P->angles[axis] = targetAngle; } if ((*(u16 *)(object + 0x7A) & ROTATION_STOP_AT_NEXT_TARGET) || (P->nextStop == 0 && (*(u16 *)(object + 0x7A) & ROTATION_STOP_AFTER_CYCLE))) { P->angularStep = 0.0f; P->angles[axis] = targetAngle; } P->nextStop = (P->nextStop + 1) % P->stopCount; if (P->unk086 == 0 && P->stopSoundId != 0) { func_80178134(P->stopSoundId, (f32 *)(object + 0xB4), P->stopSoundVolume, P->stopSoundPitch);
                    }
                }
            } else if (P->oscillationLimit != zero) {
                if (P->angularStep < zero) {
                    currentAngle = func_801496C8(P->angles[axis] - P->baseAngle);
                } else {
                    currentAngle = func_801496C8(P->baseAngle - P->angles[axis]);
                }
                angleDistance = func_8014944C(currentAngle, P->oscillationLimit);
                if (angleDistance < (P->angularStep > zero ? P->angularStep : -P->angularStep))
                    goto reverseRotation;
                angleDistance = func_8014944C(fullTurn - P->oscillationLimit, currentAngle);
                if (angleDistance < (P->angularStep > zero ? P->angularStep : -P->angularStep)) {
                reverseRotation:
                    P->delay = P->pauseFrames;
                    P->angularStep = -P->angularStep;
                    P->angularVelocity[axis] = 0.0f;
                    if ((*(u16 *)(object + 0x7A) & ROTATION_STOP_AT_NEXT_TARGET) || (P->nextStop == 1 && (*(u16 *)(object + 0x7A) & ROTATION_STOP_AFTER_CYCLE))) {
                        P->angularStep = 0.0f;
                    }
                    func_80178704(&P->soundHandle);
                    if (P->stopSoundId != 0) {
                        func_80178134(P->stopSoundId, (f32 *)(object + 0xB4), P->stopSoundVolume, P->stopSoundPitch);
                    }
                }
            }
        }
        if (P->delay <= 0) {
            if (P->delay < 0) {
                if (P->delay > -ROTATION_WAYPOINT_DELAY_SCALE) {
                    P->delay++;
                    P->angularVelocity[axis] = P->angularStep;
                } else {
                    u8 *path = *(u8 **)(object + 0x38);
                    if (path != 0 && path[0x57] == -P->delay / ROTATION_WAYPOINT_DELAY_SCALE && path[0x56] == path[0x57]) {
                        P->delay = 1;
                    }
                }
            } else {
                P->angularVelocity[axis] = P->angularStep;
            }
        }
    }
#undef P
}

/* platform_update_orbit: plays the orbit's move/stop sounds, handles pauses and flips, then
 * advances the orbit angle and sets the platform velocity that moves it around the centre. */
void func_8017B780(u8 *platform) {
    extern f64 D_801087E0; /* one full turn in radians */
    extern f64 D_801087E8; /* one full turn in radians */
#define ORBIT (*(PlatformOrbit **)(platform + PLATFORM_ORBIT))
    u8 *parent;
    s32 axisIndex;
    s32 planeIndex;
    s32 normalAxis;
    f32 offset[2];
    f32 angle;
    f32 radius;
    f32 turned;
    f32 distance;

    parent = *(u8 **)(platform + PLATFORM_PARENT);
    if (ORBIT == 0) {
        return;
    }
    if (ORBIT->delay != 0) {
        if (ORBIT->soundHandle != 0) {
            func_80178760(&ORBIT->soundHandle);
            ORBIT->soundStopTimer -= 0x3C;
            if (ORBIT->soundStopTimer <= 0) {
                func_80178704(&ORBIT->soundHandle);
                if (ORBIT->stopSoundId != 0) {
                    func_80178134(ORBIT->stopSoundId, (f32 *)(platform + PLATFORM_POSITION), ORBIT->stopSoundVolume, ORBIT->stopSoundPitch);
                }
            }
        }
    } else if (ORBIT->moveSoundId != 0) {
        if (ORBIT->soundHandle == 0) {
            func_801785E0(&ORBIT->soundHandle, ORBIT->moveSoundId, ORBIT->moveSoundVolume, (s32)(platform + PLATFORM_POSITION), ORBIT->moveSoundPitch);
        } else {
            func_80178760(&ORBIT->soundHandle);
        }
    }
    if (ORBIT->angularStep == 0.0f) {
        return;
    }
    /* Offset from the centre in the orbit plane (relative to the parent, if any). */
    normalAxis = 10;
    for (axisIndex = 0, planeIndex = 0; axisIndex < 3; axisIndex++) {
        f32 delta;
        if (ORBIT->axisLocked[axisIndex] == 0) {
            delta = ((f32 *)platform)[PLATFORM_POSITION / 4 + axisIndex] - ORBIT->center[axisIndex];
            offset[planeIndex] = delta;
            if (parent != 0) {
                offset[planeIndex] = delta - ((f32 *)parent)[PLATFORM_POSITION / 4 + axisIndex];
            }
            planeIndex++;
        } else {
            normalAxis = axisIndex;
        }
    }
    radius = sqrtf(offset[0] * offset[0] + offset[1] * offset[1]);
    if (D_802004E0 == 0) {
        angle = func_80147460(offset[1], offset[0]);
        ORBIT->initialAngle = ORBIT->currentAngle = angle;
    } else {
        angle = ORBIT->currentAngle;
    }
    if (ORBIT->delay > 0) {
        ORBIT->delay--;
        if (ORBIT->pauseCount == 1 && ORBIT->delay == 0) {
            ORBIT->delay = -2;
        }
    } else if (ORBIT->delay == 0) {
        /* Angle travelled since the start, in the direction of motion. */
        if (ORBIT->axisLocked[1] != 0) {
            if (ORBIT->angularStep < 0.0f) {
                turned = func_801496C8(angle - ORBIT->initialAngle);
            } else {
                turned = func_801496C8(ORBIT->initialAngle - angle);
            }
        } else if (ORBIT->angularStep > 0.0f) {
            turned = func_801496C8(angle - ORBIT->initialAngle);
        } else {
            turned = func_801496C8(ORBIT->initialAngle - angle);
        }
        if (ORBIT->pauseCount != 0) {
            distance = func_8014944C(turned, ORBIT->nextPause * D_801087E0 / ORBIT->pauseCount);
            if (!(distance < (ORBIT->angularStep > 0.0f ? ORBIT->angularStep : -ORBIT->angularStep))) {
                goto end;
            }
            ORBIT->delay = ORBIT->pauseFrames;
            *(Vec3F *)(platform + PLATFORM_VELOCITY) = *(Vec3F *)&D_801ED3C4;
            ORBIT->nextPause = (ORBIT->nextPause + 1) % ORBIT->pauseCount; } else if (ORBIT->flipAngle != 0.0f) {
            if (func_8014944C(turned, ORBIT->flipAngle) < (ORBIT->angularStep > 0.0f ? ORBIT->angularStep : -ORBIT->angularStep) ||
                func_8014944C(D_801087E8 - ORBIT->flipAngle, turned) < (ORBIT->angularStep > 0.0f ? ORBIT->angularStep : -ORBIT->angularStep)) {
                ORBIT->delay = ORBIT->pauseFrames;
                ORBIT->angularStep = -ORBIT->angularStep;
                *(Vec3F *)(platform + PLATFORM_VELOCITY) = *(Vec3F *)&D_801ED3C4;
            } else {
                goto end;
            }
        } else {
            goto end;
        }
        if ((*(u16 *)(platform + 0x7C) & 2) || (ORBIT->nextPause == 1 && (*(u16 *)(platform + 0x7C) & 1))) {
            ORBIT->angularStep = 0.0f;
        }
    }
end:
    if (ORBIT->delay > 0) {
        return;
    }
    if (ORBIT->delay < 0) {
        ORBIT->delay++;
    }
    if (normalAxis == 1) {
        ORBIT->currentAngle = ORBIT->currentAngle - ORBIT->angularStep;
    } else {
        ORBIT->currentAngle = ORBIT->currentAngle + ORBIT->angularStep;
    }
    ORBIT->currentAngle = func_801496C8(ORBIT->currentAngle);
    offset[0] = radius * func_801C4040(ORBIT->currentAngle);
    offset[1] = radius * func_801C6000(ORBIT->currentAngle);
    /* Velocity that carries the platform to its new orbit position this frame. */
    if (parent != 0) {
        for (axisIndex = 0, planeIndex = 0; axisIndex < 3; axisIndex++) {
            if (ORBIT->axisLocked[axisIndex] == 0) {
                ((f32 *)platform)[PLATFORM_VELOCITY / 4 + axisIndex] = offset[planeIndex] + ORBIT->center[axisIndex] - ((f32 *)platform)[PLATFORM_PREVIOUS_POSITION / 4 + axisIndex] + ((f32 *)parent)[PLATFORM_POSITION / 4 + axisIndex];
                planeIndex++;
            }
        }
    } else {
        for (axisIndex = 0, planeIndex = 0; axisIndex < 3; axisIndex++) {
            if (ORBIT->axisLocked[axisIndex] == 0) {
                ((f32 *)platform)[PLATFORM_VELOCITY / 4 + axisIndex] = ORBIT->center[axisIndex] - ((f32 *)platform)[PLATFORM_PREVIOUS_POSITION / 4 + axisIndex];
                ((f32 *)platform)[PLATFORM_VELOCITY / 4 + axisIndex] += offset[planeIndex];
                planeIndex++;
            }
        }
    }
#undef ORBIT
}

/* Apply ground gravity/bounce, integrate velocity, and clamp to parent-relative motion bounds. */
void func_8017BDD0(u8 *platform) {
    extern f64 D_801087F0;
    extern f32 D_801087F8;
    extern f64 D_80108800;
    extern f64 D_80108808;
    extern f32 D_801EFC84;
    extern f32 D_801ED680;
    f32 scratchPosition[3];
    f32 groundFaceStorage;
    f32 groundPlatformStorage;
    f32 groundDistance;
    s32 parentAddress = *(s32 *)(platform + PLATFORM_PARENT);
    s32 unsupported;
    s32 axis;

    if (*(s32 *)(platform + PLATFORM_RENDER_FLAGS) & PLATFORM_GRAVITY_ENABLED) {
        f32 halfHeight = *(f32 *)(platform + PLATFORM_HALF_HEIGHT);
        f32 supportDistance;
        f64 cornerInset;
        f32 noGroundDistance;
        scratchPosition[1] = *(f32 *)(platform + PLATFORM_POSITION_Y);
        cornerInset = D_801087F0;
        scratchPosition[0] = (f32)((f64)(*(f32 *)(platform + PLATFORM_POSITION) + *(f32 *)(platform + PLATFORM_HALF_WIDTH)) - cornerInset);
        scratchPosition[2] = (f32)((f64)(*(f32 *)(platform + PLATFORM_POSITION_Z) + *(f32 *)(platform + PLATFORM_HALF_DEPTH)) - cornerInset);
        supportDistance = halfHeight + D_801EFC84;
        { f64 distancePrecision = supportDistance; supportDistance = distancePrecision; }
        groundDistance = func_8015B524(scratchPosition, (s32)&groundFaceStorage, &groundPlatformStorage, 0);
        unsupported = 0; if ((supportDistance < groundDistance) | (groundDistance == (noGroundDistance = D_801087F8))) {
            scratchPosition[0] = (f32)((f64)(*(f32 *)(platform + PLATFORM_POSITION) - *(f32 *)(platform + PLATFORM_HALF_WIDTH)) + cornerInset);
            groundDistance = func_8015B524(scratchPosition, (s32)&groundFaceStorage, &groundPlatformStorage, 0);
            if ((supportDistance < groundDistance) | (groundDistance == noGroundDistance)) {
                scratchPosition[2] = (f32)((f64)(*(f32 *)(platform + PLATFORM_POSITION_Z) - *(f32 *)(platform + PLATFORM_HALF_DEPTH)) + cornerInset);
                groundDistance = func_8015B524(scratchPosition, (s32)&groundFaceStorage, &groundPlatformStorage, 0);
                if ((supportDistance < groundDistance) | (groundDistance == noGroundDistance)) {
                    scratchPosition[0] = (f32)((f64)(*(f32 *)(platform + PLATFORM_POSITION) + *(f32 *)(platform + PLATFORM_HALF_WIDTH)) - cornerInset);
                    groundDistance = func_8015B524(scratchPosition, (s32)&groundFaceStorage, &groundPlatformStorage, 0);
                    if ((supportDistance < groundDistance) | (groundDistance == noGroundDistance)) {
                        *(f32 *)(platform + PLATFORM_VELOCITY_Y) = (f32)((f64)*(f32 *)(platform + PLATFORM_VELOCITY_Y) - (f64)D_801ED680 * *(f64 *)((u8 *)&D_801087F8 + 4));
                        unsupported = 1;
                    }
                }
            }
        }
        if (unsupported == 0) {
            *(f32 *)(platform + PLATFORM_VELOCITY_Y) = (f32)((f64)-*(f32 *)(platform + PLATFORM_VELOCITY_Y) * *(f64 *)((u8 *)&D_80108800 + 4));
        }
    }
    for (axis = 0; axis < 3; axis++) {
        *(f32 *)(platform + PLATFORM_POSITION + axis * 4) += *(f32 *)(platform + PLATFORM_VELOCITY + axis * 4);
    }
    if (*(s32 *)(platform + PLATFORM_MOTION_BOUNDS) != 0) {
        f32 zero = 0.0f;
        f32 *axisPosition = scratchPosition;
        for (axis = 0; axis < 3; axisPosition++, axis++) {
            if (zero <= *(f32 *)(*(s32 *)(platform + PLATFORM_MOTION_BOUNDS) + axis * 4 + PLATFORM_BOUNDS_EXTENT)) {
                f32 clampedPosition;
                *axisPosition = *(f32 *)(platform + PLATFORM_POSITION + axis * 4);
                if (parentAddress != 0) {
                    *axisPosition = *axisPosition - *(f32 *)(parentAddress + PLATFORM_POSITION + axis * 4);
                }
                if (*axisPosition < *(f32 *)(*(s32 *)(platform + PLATFORM_MOTION_BOUNDS) + axis * 4)) {
                    *axisPosition = *(f32 *)(*(s32 *)(platform + PLATFORM_MOTION_BOUNDS) + axis * 4);
                    *(f32 *)(platform + PLATFORM_VELOCITY + axis * 4) = zero;
                } else {
                    f32 upperLimit = *(f32 *)(*(s32 *)(platform + PLATFORM_MOTION_BOUNDS) + axis * 4) + *(f32 *)(*(s32 *)(platform + PLATFORM_MOTION_BOUNDS) + axis * 4 + PLATFORM_BOUNDS_EXTENT);
                    if (upperLimit < *axisPosition) {
                        *axisPosition = upperLimit;
                        *(f32 *)(platform + PLATFORM_VELOCITY + axis * 4) = zero;
                    }
                }
                clampedPosition = *axisPosition;
                *(f32 *)(platform + PLATFORM_POSITION + axis * 4) = clampedPosition;
                if (parentAddress != 0) {
                    *(f32 *)(platform + PLATFORM_POSITION + axis * 4) = clampedPosition + *(f32 *)(parentAddress + PLATFORM_POSITION + axis * 4);
                }
            }
        }
    }
}

void func_8017C17C(void *arg0);
void func_8017C17C(void *object);
void func_8017C17C(void *);
/* Integrate platform angular motion: track player/ball yaw, seek snapped or
 * path-banked target angles, apply pendulum trail/torque, clamp angle limits,
 * forward spin links to tagged platforms, and update positional rotation audio. */
void func_8017C17C(void *platform)
{
  extern f64 D_80108808;
  extern s32 D_80108810;
  extern s32 D_80108818;
  extern s32 D_80108820;
  extern s32 D_80108828;
  extern f32 D_80108834;
  extern f64 D_80108838;
  extern s32 D_80108840;
  extern s32 D_80108848;
  extern s32 D_80108850;
  u8 *axisVelocityPtr;
  extern f32 D_8010885C;
  extern f32 D_80108860;
  extern f32 D_80108864;
  extern s32 D_80108868;
  extern s32 D_80108870;
  extern s32 D_80108878;
  void func_80149568(f32 *);
  void func_80178760(void *);
  Unk802904D4Node *func_8017DBD8(Unk802904D4Node *arg0, s32 arg1);
  void func_801BA700(TrailBuf *buf, TrailVec *a, TrailVec *b);
  Vec3F workVec;
  Vec3F trailInner;
  Vec3F toCamera;
  f32 *trailInnerPtr;
  f32 *workVecPtr;
  Unk802904D4Node *linkedPlatform;
  f32 maxAngularSpeed;
  f32 maxDeviation;
  f32 rawAngle;
  f32 currentAngle;
  f32 upperLimitAngle;
  f32 deltaX;
  f32 horizDistSq;
  f32 deltaZ;
  f32 angleValue;
  f32 axisVelocity;
  f32 negMaxAngularSpeed;
  f32 seekCurrentAngle;
  f32 seekTargetAngle;
  f32 lowerLimitAngle;
  f32 absAngleDelta;
  f32 wrappedAngle;
  f32 absVelocity;
  f32 horizDist;
  f32 absYawDelta;
  f32 activeAngularVelocity;
  f32 angleBound;
  f32 approachStep;
  f64 halfTurn;
  f64 wrappedAngleF64;
  f64 rawAngleF64;
  s16 stopSoundId;
  s16 upperStopSoundId;
  s16 lowerStopSoundId;
  s16 moveSoundId;
  s32 *trackTarget;
  s32 platformFlags;
  short waypointOffset;
  s32 axisOffset;
  s32 axis;
  u8 snapDivisions;
  u8 snapDivisions2;
  s32 soundHandle;
  u8 currentWaypoint;
  s32 rotSoundFade;
  s32 rotSoundStop;
  s32 rotAxisVel;
  s32 rotSeek;
  s32 rotSnap;
  s32 rotApproach;
  s32 rotClamp;
  s32 pathData;
  s32 rotMinClamp;
  s32 rotPendulum;
  s32 rotPendulumAxis;
  s32 rotIntegrateAxis;
  s32 rotUpperBound;
  s32 rotUpperCheck;
  s32 rotLowerBound;
  s32 rotLowerCheck;
  s32 rotDamp;
  s32 rotZeroCheckAxis;
  s32 motionLinks;
  s32 linkBase;
  s32 rotBank;
  s32 rotHoldYaw;
  s32 rotFadeVol;
  s32 rotStopCue;
  s32 rotMinClampAxis;
  s32 rotDistAxis;
  s32 rotSnapAngleAxis;
  s32 rotSnapVelAxis;
  s32 rotStopSnapAxis;
  s32 rotBreak;
  s32 rotBreakAxis;
  s32 rotPendulumCheck;
  s32 rotLoop;
  s32 rotMoveSound;
  s32 rotApproachAxis;
  s32 rotUpperFlag;
  s32 rotUpperSound;
  s32 rotLowerSound;
  s32 rotDampAxis;

  trackTarget = (void *) 0;
  if ((*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))) != ((void *) 0))
  {
    platformFlags = *((s32 *) (((u8 *) platform) + PLATFORM_FLAGS));
    activeAngularVelocity = 0.0f;
    if (platformFlags & PLATFORM_FLAG_TRACK_BALL_YAW)
    {
      trackTarget = &D_8029F978;
    }
    else
      if (platformFlags & PLATFORM_FLAG_TRACK_PLAYER_YAW)
    {
      trackTarget = &D_802902D8;
    }
    if (trackTarget != ((void *) 0))
    {
      *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_TARGET_YAW)) = func_801496C8(func_80147460((*((f32 *) (((u8 *) trackTarget) + OBJECT_POSITION_OFFSET))) - (*((f32 *) (((u8 *) platform) + PLATFORM_POSITION))), (*((f32 *) (((u8 *) trackTarget) + OBJECT_POSITION_Z_OFFSET))) - (*((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Z)))));
    }
    axis = 0;
    halfTurn = *((f64 *) (((u8 *) (&D_80108808)) + 4));
    trailInnerPtr = &trailInner.x;
    workVecPtr = &workVec.x;
    axisOffset = 0;
    do
    {
      rotLoop = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
      rotAxisVel = axisOffset + rotLoop;
      axisVelocity = *((f32 *) (((u8 *) rotAxisVel) + PLATFORM_ROTATION_ANGULAR_VELOCITY));
      if (axisVelocity != 0.0f)
      {
        activeAngularVelocity = axisVelocity;
      }
      if ((*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & PLATFORM_FLAG_CLAMP_ANGULAR_SPEED)
      {
        maxAngularSpeed = *((f32 *) (((u8 *) rotLoop) + PLATFORM_ROTATION_MAX_ANGULAR_SPEED));
        if (maxAngularSpeed < axisVelocity)
        {
          *((f32 *) (((u8 *) rotAxisVel) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = maxAngularSpeed;
        }
        rotMinClamp = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        rotMinClampAxis = axisOffset + rotMinClamp;
        negMaxAngularSpeed = -(*((f32 *) (((u8 *) rotMinClamp) + PLATFORM_ROTATION_MAX_ANGULAR_SPEED)));
        if ((*((f32 *) (((u8 *) rotMinClampAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) < negMaxAngularSpeed)
        {
          *((f32 *) (((u8 *) rotMinClampAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = negMaxAngularSpeed;
        }
      }
      rotSeek = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
      if ((*((s8 *) (((u8 *) (rotSeek + axis)) + PLATFORM_ROTATION_SEEK_TARGET))) == 1)
      {
        snapDivisions = *((u8 *) (((u8 *) rotSeek) + PLATFORM_ROTATION_SNAP_DIVISIONS));
        if (snapDivisions >= 2)
        {
          {
            f32 angle;
            s32 step;
            if (1)
            {
              angle = func_801496C8(((*((f32 *) (((u8 *) (axisOffset + rotSeek)) + PLATFORM_ROTATION_ANGLES))) - (*((f32 *) (((u8 *) rotSeek) + PLATFORM_ROTATION_BASE_ANGLE)))) + (halfTurn / snapDivisions));
            }
            rotSnap = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
            snapDivisions2 = *((u8 *) (((u8 *) rotSnap) + PLATFORM_ROTATION_SNAP_DIVISIONS));
            step = (snapDivisions2 * angle) / (*((f64 *) (((u8 *) (&D_80108810)) + 4)));
            angle = func_801496C8((((step * halfTurn) * 2.0) / snapDivisions2) + (*((f32 *) (((u8 *) rotSnap) + PLATFORM_ROTATION_BASE_ANGLE))));
            *((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_TARGET_ANGLES)) = angle;
          }
        }
        rotDistAxis = axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)));
        angleValue = func_8014944C(*((f32 *) (((u8 *) rotDistAxis) + PLATFORM_ROTATION_ANGLES)), *((f32 *) (((u8 *) rotDistAxis) + PLATFORM_ROTATION_TARGET_ANGLES)));
        {
          f64 d = angleValue;
          angleValue = d;
        }
        if ((axis == 2) && ((*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & PLATFORM_FLAG_BANK_ALONG_PATH))
        {
          approachStep = (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_BANK_SCALE))) * (*((f64 *) (((u8 *) (&D_80108818)) + 4)));
        }
        else
        {
          approachStep = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_RESTORE_STEP));
        }
        if (approachStep != 0.0f)
        {
          absAngleDelta = angleValue;
          if (!(angleValue > 0.0f))
          {
            absAngleDelta = -angleValue;
          }
          if (absAngleDelta <= (*((f64 *) (((u8 *) (&D_80108820)) + 4))))
          {
            rotSnapAngleAxis = axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)));
            *((f32 *) (((u8 *) rotSnapAngleAxis) + PLATFORM_ROTATION_ANGLES)) = *((f32 *) (((u8 *) rotSnapAngleAxis) + PLATFORM_ROTATION_TARGET_ANGLES));
            rotSnapVelAxis = axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)));
            *((f32 *) (((u8 *) rotSnapVelAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = (*((f32 *) (((u8 *) rotSnapVelAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * (*((f64 *) (((u8 *) (&D_80108828)) + 4)));
          }
          else
          {
            rotApproach = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
            rotApproachAxis = axisOffset + rotApproach;
            seekTargetAngle = *((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_TARGET_ANGLES));
            axisVelocityPtr = ((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY;
            currentAngle = *((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGLES));
            seekCurrentAngle = currentAngle;
            if (seekCurrentAngle < (seekTargetAngle - approachStep))
            {
              if ((halfTurn - approachStep) < (seekTargetAngle - seekCurrentAngle))
              {
                *((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) -= (angleValue < approachStep) ? (angleValue) : (approachStep);
              }
              else
              {
                *((f32 *) axisVelocityPtr) += (angleValue < approachStep) ? (angleValue) : (approachStep);
              }
            }
            else
              if ((seekTargetAngle + approachStep) < seekCurrentAngle)
            {
              if ((approachStep + halfTurn) < (seekCurrentAngle - seekTargetAngle))
              {
                *((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) += (angleValue < approachStep) ? (angleValue) : (approachStep);
              }
              else
              {
                *((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) -= (angleValue < approachStep) ? (angleValue) : (approachStep);
              }
            }
            else
              if (!((*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & PLATFORM_FLAG_CLAMP_ANGULAR_SPEED))
            {
              if (((*((f32 *) (((u8 *) rotApproach) + PLATFORM_ROTATION_SPIN_DAMPING))) == D_80108834) || ((((*((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) > 0.0f) ? (*((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) : (-(*((f32 *) (((u8 *) rotApproachAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))))) <= approachStep))
              {
                rotStopSnapAxis = axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)));
                *((f32 *) (((u8 *) rotStopSnapAxis) + PLATFORM_ROTATION_ANGLES)) = *((f32 *) (((u8 *) rotStopSnapAxis) + PLATFORM_ROTATION_TARGET_ANGLES));
                *((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = 0;
              }
            }
          }
        }
        rotBreak = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        maxDeviation = *((f32 *) (((u8 *) rotBreak) + PLATFORM_ROTATION_MAX_DEVIATION));
        if (maxDeviation != 0.0f)
        {
          rotBreakAxis = axisOffset + rotBreak;
          if (maxDeviation < angleValue)
          {
            *((f32 *) (((u8 *) rotBreakAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = (*((f32 *) (((u8 *) rotBreakAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * D_80108838;
            *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_RESTORE_STEP)) = 0.0f;
          }
        }
      }
      *((s32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_STEP_COUNTER)) = (*((s32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_STEP_COUNTER))) + 1;
      rotPendulumCheck = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
      if (((*((f32 *) (((u8 *) rotPendulumCheck) + PLATFORM_ROTATION_PENDULUM_DIVISOR))) != 0.0f) && ((*((s8 *) (((u8 *) (rotPendulumCheck + axis)) + PLATFORM_ROTATION_AXES))) != 0))
      {
        if ((*((s32 *) (((u8 *) platform) + PLATFORM_TRAIL))) != ((void *) 0))
        {
          f32 outerY;
          f32 outerZ;
          workVec.x = 0.0f;
          workVec.y = -(*((f32 *) (((u8 *) platform) + PLATFORM_HALF_HEIGHT)));
          workVec.z = 0.0f;
          func_8014915C(&workVec, &workVec, *((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGLES)), (s8) axis);
          trailInner = workVec;
          trailInner.x *= *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_TRAIL)))) + PLATFORM_TRAIL_INNER_SCALE));
          trailInner.y *= *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_TRAIL)))) + PLATFORM_TRAIL_INNER_SCALE));
          trailInner.z *= *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_TRAIL)))) + PLATFORM_TRAIL_INNER_SCALE));
          workVec.x += *((f32 *) (((u8 *) platform) + PLATFORM_POSITION));
          outerY = workVec.y + *((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Y));
          workVec.y = outerY;
          { f64 d = outerY; outerY = d; }
          outerZ = workVec.z + *((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Z));
          workVec.z = outerZ;
          { f64 d = outerZ; outerZ = d; }
          { f64 d = outerZ; outerZ = d; }
          trailInner.x += *((f32 *) (((u8 *) platform) + PLATFORM_POSITION));
          trailInner.y += *((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Y));
          trailInner.z += *((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Z));
          {
            typedef struct { f32 pad_; f32 v_; } VolF32_8017C17C;
            toCamera.x = workVec.x - ((volatile VolF32_8017C17C *) (((u8 *) (&D_8028F914)) - 4))->v_;
            toCamera.y = outerY - D_8028F918;
            outerZ = outerZ - D_8028F91C;
            angleValue = ((volatile VolF32_8017C17C *) (((u8 *) (&D_80108840)) - 4))->v_;
            toCamera.z = outerZ;
          }
          func_80149568(&toCamera.x);
          func_80148D0C(workVecPtr, &toCamera.x, angleValue);
          func_80148D0C(trailInnerPtr, &toCamera.x, angleValue);
          func_801BA700(*((s32 *) (((u8 *) platform) + PLATFORM_TRAIL)), workVecPtr, trailInnerPtr);
        }
        {
          f32 delta = func_801494CC(*((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGLES)), 0.0f);
          rotPendulum = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
          rotPendulumAxis = axisOffset;
          rotPendulumAxis = rotPendulumAxis + rotPendulum;
          *((f32 *) (((u8 *) rotPendulumAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = (*((f32 *) (((u8 *) rotPendulumAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) - (delta / (*((f32 *) (((u8 *) rotPendulum) + PLATFORM_ROTATION_PENDULUM_DIVISOR))));
        }
      }
      rotIntegrateAxis = axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)));
      *((f32 *) (((u8 *) rotIntegrateAxis) + PLATFORM_ROTATION_ANGLES)) = (*((f32 *) (((u8 *) rotIntegrateAxis) + PLATFORM_ROTATION_ANGLES))) + (*((f32 *) (((u8 *) rotIntegrateAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)));
      *((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGLES)) = func_801496C8(*((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGLES)));
      rotClamp = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
      if ((*((f32 *) (((u8 *) rotClamp) + PLATFORM_ROTATION_RESTORE_ANGLE_LIMIT))) > 0.0f)
      {
        if ((*((s8 *) (((u8 *) (rotClamp + axis)) + PLATFORM_ROTATION_AXES))) == 1)
        {
          rawAngle = *((f32 *) (((u8 *) (axisOffset + rotClamp)) + PLATFORM_ROTATION_ANGLES));
          rawAngleF64 = rawAngle;
          if (halfTurn < rawAngleF64)
          {
            angleValue = rawAngleF64 - (*((f64 *) (((u8 *) (&D_80108840)) + 4)));
          }
          else
          {
            angleValue = rawAngle;
          }
          wrappedAngleF64 = angleValue;
          if (wrappedAngleF64 < (*((f64 *) (((u8 *) (&D_80108848)) + 4))))
          {
            wrappedAngle = wrappedAngleF64 + (*((f64 *) (((u8 *) (&D_80108850)) + 4)));
          }
          else
          {
            wrappedAngle = angleValue;
          }
          angleValue = wrappedAngle;
          rotUpperFlag = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
          if ((*((u16 *) (((u8 *) rotUpperFlag) + PLATFORM_ROTATION_LIMIT_FLAGS))) & PLATFORM_ROTATION_LIMIT_UPPER)
          {
            angleBound = *((f32 *) (((u8 *) rotUpperFlag) + PLATFORM_ROTATION_RESTORE_ANGLE_LIMIT));
          }
          else
          {
            angleBound = ((*((f32 *) (((u8 *) rotUpperFlag) + PLATFORM_ROTATION_MAX_DEVIATION))) * D_8010885C) / D_80108860;
          }
          rotUpperBound = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
          upperLimitAngle = (*((f32 *) (((u8 *) rotUpperBound) + PLATFORM_ROTATION_BASE_ANGLE))) + angleBound;
          if (((upperLimitAngle < angleValue) && ((*((f32 *) (((u8 *) (axisOffset + rotUpperBound)) + PLATFORM_ROTATION_ANGLES)) = upperLimitAngle, *((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = 0, rotUpperCheck = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)), (*((f32 *) (((u8 *) rotUpperCheck) + PLATFORM_ROTATION_MAX_DEVIATION))) != 0.0f))) && (angleBound == (*((f32 *) (((u8 *) rotUpperCheck) + PLATFORM_ROTATION_RESTORE_ANGLE_LIMIT)))))
          {
            *((s32 *) (((u8 *) platform) + PLATFORM_FLAGS)) = (*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & (~PLATFORM_FLAG_CLAMP_ANGULAR_SPEED);
            *((s8 *) (((u8 *) ((*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))) + axis)) + PLATFORM_ROTATION_SEEK_TARGET)) = 0;
            rotUpperSound = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
            if ((*((s16 *) (((u8 *) rotUpperSound) + PLATFORM_ROTATION_MOVE_SOUND_ID))) == 0)
            {
              upperStopSoundId = *((s16 *) (((u8 *) rotUpperSound) + PLATFORM_ROTATION_STOP_SOUND_ID));
              if (upperStopSoundId != 0)
              {
                func_80178134(upperStopSoundId, platform + PLATFORM_POSITION, *((s16 *) (((u8 *) rotUpperSound) + PLATFORM_ROTATION_STOP_SOUND_VOLUME)), *((s16 *) (((u8 *) rotUpperSound) + PLATFORM_ROTATION_STOP_SOUND_PITCH)));
              }
            }
          }
          if ((*((u16 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_LIMIT_FLAGS))) & PLATFORM_ROTATION_LIMIT_LOWER)
          {
            angleBound = *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_RESTORE_ANGLE_LIMIT));
          }
          else
          {
            angleBound = ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_MAX_DEVIATION))) * D_80108864) / (*((f32 *) (&D_80108868)));
          }
          rotLowerBound = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
          lowerLimitAngle = (*((f32 *) (((u8 *) rotLowerBound) + PLATFORM_ROTATION_BASE_ANGLE))) - angleBound;
          if (((angleValue < (lowerLimitAngle - (*((f64 *) (((u8 *) (&D_80108868)) + 4))))) && ((*((f32 *) (((u8 *) (axisOffset + rotLowerBound)) + PLATFORM_ROTATION_ANGLES)) = lowerLimitAngle, *((f32 *) (((u8 *) (axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = 0, rotLowerCheck = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)), (*((f32 *) (((u8 *) rotLowerCheck) + PLATFORM_ROTATION_MAX_DEVIATION))) != 0.0f))) && (angleBound == (*((f32 *) (((u8 *) rotLowerCheck) + PLATFORM_ROTATION_RESTORE_ANGLE_LIMIT)))))
          {
            *((s32 *) (((u8 *) platform) + PLATFORM_FLAGS)) = (*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & (~PLATFORM_FLAG_CLAMP_ANGULAR_SPEED);
            *((s8 *) (((u8 *) ((*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))) + axis)) + PLATFORM_ROTATION_SEEK_TARGET)) = 0;
            rotLowerSound = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
            if ((*((s16 *) (((u8 *) rotLowerSound) + PLATFORM_ROTATION_MOVE_SOUND_ID))) == 0)
            {
              lowerStopSoundId = *((s16 *) (((u8 *) rotLowerSound) + PLATFORM_ROTATION_STOP_SOUND_ID));
              if (lowerStopSoundId != 0)
              {
                func_80178134(lowerStopSoundId, platform + PLATFORM_POSITION, *((s16 *) (((u8 *) rotLowerSound) + PLATFORM_ROTATION_STOP_SOUND_VOLUME)), *((s16 *) (((u8 *) rotLowerSound) + PLATFORM_ROTATION_STOP_SOUND_PITCH)));
              }
            }
          }
        }
      }
      if ((axis == 2) && ((*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & PLATFORM_FLAG_BANK_ALONG_PATH))
      {
        *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_ANGULAR_VELOCITY_Z)) = 0;
      }
      else
      {
        rotDamp = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        rotDampAxis = axisOffset + rotDamp;
        *((f32 *) (((u8 *) rotDampAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = (*((f32 *) (((u8 *) rotDampAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * (*((f32 *) (((u8 *) rotDamp) + PLATFORM_ROTATION_SPIN_DAMPING)));
      }
      rotZeroCheckAxis = axisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)));
      absVelocity = *((f32 *) (((u8 *) rotZeroCheckAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY));
      if (!(absVelocity > 0.0f))
      {
        absVelocity = -absVelocity;
      }
      if (absVelocity <= (*((f64 *) (((u8 *) (&D_80108870)) + 4))))
      {
        *((f32 *) (((u8 *) rotZeroCheckAxis) + PLATFORM_ROTATION_ANGULAR_VELOCITY)) = 0.0f;
      }
      motionLinks = *((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS));
      if (motionLinks != ((void *) 0))
      {
        if ((*((f32 *) (((u8 *) motionLinks) + PLATFORM_LINK_SPIN_TO_MOVE_SCALE))) != 0.0f)
        {
          linkedPlatform = func_8017DBD8(&D_802904D4, *((s16 *) (((u8 *) motionLinks) + PLATFORM_LINK_SPIN_TO_MOVE_TAG)));
          if (linkedPlatform != ((void *) 0))
          {
            s32 linkAxisOffset = axisOffset;
            do
            {
              linkBase = *((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS));
              *((Vec3F *) ((u8 *) linkedPlatform + PLATFORM_VELOCITY)) = *((Vec3F *) linkBase);
              *((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY)) = (*((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY))) + (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) linkedPlatform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_VELOCITY_OFFSET)));
              *((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Y)) = (*((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Y))) + (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) linkedPlatform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_VELOCITY_OFFSET_Y)));
              *((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Z)) = (*((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Z))) + (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) linkedPlatform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_VELOCITY_OFFSET_Z)));
              *((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY)) = (*((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY))) * ((*((f32 *) (((u8 *) (linkAxisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_MOVE_SCALE))));
              *((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Y)) = (*((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Y))) * ((*((f32 *) (((u8 *) (linkAxisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_MOVE_SCALE))));
              *((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Z)) = (*((f32 *) (((u8 *) linkedPlatform) + PLATFORM_VELOCITY_Z))) * ((*((f32 *) (((u8 *) (linkAxisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_MOVE_SCALE))));
              linkedPlatform = func_8017DBD8(linkedPlatform, *((s16 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_MOVE_TAG)));
            }
            while (linkedPlatform != ((void *) 0));
          }
        }
        if ((*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_SPIN_SCALE))) != 0.0f)
        {
          linkedPlatform = func_8017DBD8(&D_802904D4, *((s16 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_SPIN_TAG)));
          if (linkedPlatform != ((void *) 0))
          {
            {
              s32 linkAxisOffset = axisOffset;
              do
              {
                *((f32 *) (((u8 *) (*((s32 *) (((u8 *) linkedPlatform) + PLATFORM_ROTATION)))) + 0)) = (*((f32 *) (((u8 *) (linkAxisOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION))))) + PLATFORM_ROTATION_ANGULAR_VELOCITY))) * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_SPIN_SCALE)));
                linkedPlatform = func_8017DBD8(linkedPlatform, *((s16 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_MOTION_LINKS)))) + PLATFORM_LINK_SPIN_TO_SPIN_TAG)));
              }
              while (linkedPlatform != ((void *) 0));
            }
          }
        }
      }
      axis += 1;
      axisOffset += 4;
    }
    while (axis < 3);
    if ((*((s32 *) (((u8 *) platform) + PLATFORM_FLAGS))) & PLATFORM_FLAG_BANK_ALONG_PATH)
    {
      pathData = *((s32 *) (((u8 *) platform) + PLATFORM_PATH));
      currentWaypoint = *((u8 *) (((u8 *) pathData) + PLATFORM_PATH_CURRENT));
      if ((currentWaypoint != (*((u8 *) (((u8 *) pathData) - (-PLATFORM_PATH_NEXT_WAYPOINT))))) && ((waypointOffset = currentWaypoint * 4, (*((f32 *) (((u8 *) platform) + PLATFORM_MAX_SPEED))) != 0.0f)))
      {
        deltaX = (*((f32 *) (((u8 *) platform) + PLATFORM_POSITION))) - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) (waypointOffset + pathData)) + 0)))) + 0)));
        workVec.x = deltaX;
        workVec.y = (*((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Y))) - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) (waypointOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_PATH))))) + 0)))) + 4)));
        deltaZ = (*((f32 *) (((u8 *) platform) + PLATFORM_POSITION_Z))) - (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) (waypointOffset + (*((s32 *) (((u8 *) platform) + PLATFORM_PATH))))) + 0)))) + 8)));
        workVec.z = deltaZ;
        *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_TARGET_YAW)) = func_801496C8(func_80147460(deltaX, deltaZ));
        horizDistSq = (workVec.x * workVec.x) + (workVec.z * workVec.z);
        horizDist = sqrtf(horizDistSq);
        *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_TARGET_ANGLES)) = func_801496C8(func_80147460(-workVec.y, horizDist));
        rotBank = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        absYawDelta = func_801494CC(*((f32 *) (((u8 *) rotBank) + PLATFORM_ROTATION_YAW)), *((f32 *) (((u8 *) rotBank) + PLATFORM_ROTATION_PREVIOUS_YAW)));
        angleValue = absYawDelta;
        if (!(angleValue > 0.0f))
        {
          absYawDelta = -angleValue;
        }
        if ((*((f64 *) (((u8 *) (&D_80108878)) + 4))) <= absYawDelta)
        {
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_TARGET_ROLL)) = func_801496C8(angleValue * (*((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_BANK_SCALE))));
        }
        else
        {
          *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_TARGET_ROLL)) = 0.0f;
        }
      }
      else
      {
        rotHoldYaw = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        *((f32 *) (((u8 *) rotHoldYaw) + PLATFORM_ROTATION_TARGET_YAW)) = *((f32 *) (((u8 *) rotHoldYaw) + PLATFORM_ROTATION_YAW));
        *((f32 *) (((u8 *) (*((s32 *) (((u8 *) platform) + PLATFORM_ROTATION)))) + PLATFORM_ROTATION_TARGET_ROLL)) = 0.0f;
      }
    }
    if (activeAngularVelocity == 0.0f)
    {
      rotSoundFade = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
      soundHandle = *((s32 *) (((u8 *) rotSoundFade) + PLATFORM_ROTATION_SOUND_HANDLE));
      if (soundHandle != 0)
      {
        func_80178760(rotSoundFade + PLATFORM_ROTATION_SOUND_HANDLE);
        rotFadeVol = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        *((s32 *) (((u8 *) rotFadeVol) + PLATFORM_ROTATION_SOUND_VOLUME)) = (*((s32 *) (((u8 *) rotFadeVol) + PLATFORM_ROTATION_SOUND_VOLUME))) - PLATFORM_MOVEMENT_SOUND_FADE_STEP;
        rotSoundStop = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
        if ((*((s32 *) (((u8 *) rotSoundStop) + PLATFORM_ROTATION_SOUND_VOLUME))) <= 0)
        {
          func_80178704(rotSoundStop + PLATFORM_ROTATION_SOUND_HANDLE);
          rotStopCue = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
          stopSoundId = *((s16 *) (((u8 *) rotStopCue) + PLATFORM_ROTATION_STOP_SOUND_ID));
          if (stopSoundId != 0)
          {
            func_80178134(stopSoundId, platform + PLATFORM_POSITION, *((s16 *) (((u8 *) rotStopCue) + PLATFORM_ROTATION_STOP_SOUND_VOLUME)), *((s16 *) (((u8 *) rotStopCue) + PLATFORM_ROTATION_STOP_SOUND_PITCH)));
          }
        }
      }
    }
    else
    {
      rotMoveSound = *((s32 *) (((u8 *) platform) + PLATFORM_ROTATION));
      moveSoundId = *((s16 *) (((u8 *) rotMoveSound) + PLATFORM_ROTATION_MOVE_SOUND_ID));
      if (moveSoundId != 0)
      {
        if ((*((s32 *) (((u8 *) rotMoveSound) + PLATFORM_ROTATION_SOUND_HANDLE))) == 0)
        {
          func_801785E0(rotMoveSound + PLATFORM_ROTATION_SOUND_HANDLE, moveSoundId, *((s16 *) (((u8 *) rotMoveSound) + PLATFORM_ROTATION_MOVE_SOUND_VOLUME)), platform + PLATFORM_POSITION, *((s16 *) (((u8 *) rotMoveSound) + PLATFORM_ROTATION_MOVE_SOUND_PITCH)));
          return;
        }
        func_80178760(rotMoveSound + PLATFORM_ROTATION_SOUND_HANDLE);
      }
    }
  }
}

void func_8017CF00(PlatformUpdateState *platform) {    extern f32 D_80108880;
    /* Update movement audio, collision geometry, interactions and platform motion. */
    s32 pathTargetStorage[4];
    Vec3F displacement;
    f32 distanceSquared;

    if (platform->movementSoundId != 0) {
        displacement.x = platform->position.x - platform->previousPosition.x;
        displacement.y = platform->position.y - platform->previousPosition.y;
        displacement.z = platform->position.z - platform->previousPosition.z;
        distanceSquared = displacement.x * displacement.x + displacement.y * displacement.y + displacement.z * displacement.z;
        if (platform->fallState != 0 && !(platform->fallState[0] > platform->fallState[2])) {
            goto fadeMovementSound;
        }
        if (!(distanceSquared > *(f64 *)((u8 *)&D_80108880 + 4))) {
            if (!(distanceSquared > 0.0f)) {
                goto fadeMovementSound;
            }
            if (platform->pushState != 0) {
                goto fadeMovementSound;
            }
        }
        if (platform->movementSoundHandle == 0) {
            if (platform->unkA6 == 0) {
                goto updateMotion;
            }
            func_801785E0(&platform->movementSoundHandle, platform->movementSoundId, platform->movementVolume, (s32)&platform->position, platform->movementPitch);
        } else {
            platform->movementSoundVolume = *(s32 *)&platform->movementVolumeHigh;
            func_80178760(&platform->movementSoundHandle);
        }
        goto updateMotion;
fadeMovementSound:
        if (platform->movementSoundHandle != 0) {
            platform->movementSoundVolume -= PLATFORM_MOVEMENT_SOUND_FADE_STEP;
            if (platform->movementSoundVolume <= 0) {
                func_80178704(&platform->movementSoundHandle);
            } else {
                func_80178760(&platform->movementSoundHandle);
            }
        }
    }
updateMotion:
    if (platform->collisionEnabled != 0 && platform->collisionUpdateFrame < D_802004E0) {
        func_8017D7B8(platform);
    }
    if (platform->triggerType != 0) {
        func_801246AC(platform);
    }
    if (platform->renderFlags & PLATFORM_APPLY_FORCE_VOLUMES) {
        func_8017D0FC((u8 *)platform);
    }
    func_8018AA60(platform);
    func_8017A514(platform);
    func_8017A38C(platform);
    func_8017AE0C(platform, pathTargetStorage);
    func_8017A6B8(platform, pathTargetStorage);
    func_8017B178(platform);
    func_8017B780(platform);
    func_8017BDD0(platform);
    func_8017C17C(platform);
    func_8017E324((s32)platform);
}

extern f32 D_801ED680;
void func_801B4078(s32 *, u8 *, s32);

/* Applies every water volume the platform is inside: cancels gravity, adds
 * the water's forces to its physics body and caps its speed at maxSpeed. */
void func_8017D0FC(u8 *arg0)
{
    extern f32 D_801ED680;  /* gravity */
    void func_801B4078(s32 *, u8 *, s32);  /* apply water forces */
    PlatformPhysicsView *platform = (PlatformPhysicsView *)arg0;
    s32 *head = &D_80299250;  /* WaterVolume list head */
    s32 *water = (s32 *)*head;

    if (water != head) {
        s32 *sentinel = head;
        do {
            if (func_80148F10(((WaterVolume *)water)->boundsMin, platform->position)) {
                platform->velocity[1] -= D_801ED680;
                func_801B4078(water, platform->body, 0);
                platform->speed = __builtin_sqrtf(platform->velocity[0] * platform->velocity[0] +
                                                  platform->velocity[1] * platform->velocity[1] +
                                                  platform->velocity[2] * platform->velocity[2]);
                if (platform->maxSpeed < platform->speed) {
                    platform->velocity[0] *= platform->maxSpeed / platform->speed;
                    platform->velocity[1] *= platform->maxSpeed / platform->speed;
                    platform->velocity[2] *= platform->maxSpeed / platform->speed;
                    platform->speed = platform->maxSpeed;
                }
            }
            water = (s32 *)water[0];
        } while (water != sentinel);
    }
}

/* Rebuild platform collision triangles, expand scaled bounds, and disable shared edges. */
void func_8017D21C(Obj8018315C *platform, f32 localYOffset) {
    void func_8017D558(u8 *, f32);
    f32 sqrtf(f32);
    u8 *platformBytes = (u8 *)platform;
    u8 *collisionMesh;
    f32 triangleScratch[30];
    f32 vertexRadius;
    s32 triangleIndex;
    s32 corner;

    if ((*(u32 *)(platformBytes + PLATFORM_COLLISION_FLAGS) & PLATFORM_SKIP_COLLISION_REBUILD_MASK) == 0) {
        func_8017D558(platformBytes, localYOffset);
        collisionMesh = *(u8 **)(*(u8 **)(*(u8 **)(platformBytes + PLATFORM_MODEL) + PLATFORM_MODEL_COLLISION) + PLATFORM_COLLISION_MESH);
        if (*(Vec3F **)(platformBytes + PLATFORM_STRETCH) != NULL) {
            **(Vec3F **)(platformBytes + PLATFORM_STRETCH) = *(Vec3F *)(platformBytes + PLATFORM_SCALE);
        }
        for (triangleIndex = 0; triangleIndex < *(s16 *)collisionMesh; triangleIndex++) {
            for (corner = 0; corner < COLLISION_TRIANGLE_VERTEX_COUNT; corner++) {
                s16 vertexIndex;

                vertexIndex = *(s16 *)(corner * 2 + (*(u8 **)(collisionMesh + COLLISION_MESH_INDICES) + triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES));
                triangleScratch[corner * 3 + TRI_VERTEX0_X] = ((f32 *)(*(u8 **)(collisionMesh + COLLISION_MESH_VERTICES) + vertexIndex * COLLISION_VERTEX_BYTES))[0];
                vertexIndex = *(s16 *)(corner * 2 + (*(u8 **)(collisionMesh + COLLISION_MESH_INDICES) + triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES));
                triangleScratch[corner * 3 + TRI_VERTEX0_Y] = ((f32 *)(*(u8 **)(collisionMesh + COLLISION_MESH_VERTICES) + vertexIndex * COLLISION_VERTEX_BYTES))[1];
                vertexIndex = *(s16 *)(corner * 2 + (*(u8 **)(collisionMesh + COLLISION_MESH_INDICES) + triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES));
                triangleScratch[corner * 3 + TRI_VERTEX0_Z] = ((f32 *)(*(u8 **)(collisionMesh + COLLISION_MESH_VERTICES) + vertexIndex * COLLISION_VERTEX_BYTES))[2];
                triangleScratch[corner * 3 + TRI_VERTEX0_X] *= *(f32 *)(platformBytes + PLATFORM_SCALE);
                triangleScratch[corner * 3 + TRI_VERTEX0_Y] *= *(f32 *)(platformBytes + PLATFORM_SCALE_Y);
                triangleScratch[corner * 3 + TRI_VERTEX0_Z] *= *(f32 *)(platformBytes + PLATFORM_SCALE_Z);
                vertexRadius = sqrtf(triangleScratch[corner * 3 + TRI_VERTEX0_X] * triangleScratch[corner * 3 + TRI_VERTEX0_X] + triangleScratch[corner * 3 + TRI_VERTEX0_Y] * triangleScratch[corner * 3 + TRI_VERTEX0_Y] + triangleScratch[corner * 3 + TRI_VERTEX0_Z] * triangleScratch[corner * 3 + TRI_VERTEX0_Z]);
                if (*(f32 *)(platformBytes + PLATFORM_BOUNDS_RADIUS) < vertexRadius) {
                    *(f32 *)(platformBytes + PLATFORM_BOUNDS_RADIUS) = vertexRadius;
                }
                if (*(f32 *)(platformBytes + PLATFORM_BOUNDS_HALF_X) < (triangleScratch[corner * 3 + TRI_VERTEX0_X] > 0.0f ? triangleScratch[corner * 3 + TRI_VERTEX0_X] : -triangleScratch[corner * 3 + TRI_VERTEX0_X])) {
                    *(f32 *)(platformBytes + PLATFORM_BOUNDS_HALF_X) = (triangleScratch[corner * 3 + TRI_VERTEX0_X] > 0.0f ? triangleScratch[corner * 3 + TRI_VERTEX0_X] : -triangleScratch[corner * 3 + TRI_VERTEX0_X]);
                }
                if (*(f32 *)(platformBytes + PLATFORM_BOUNDS_HALF_Y) < (triangleScratch[corner * 3 + TRI_VERTEX0_Y] > 0.0f ? triangleScratch[corner * 3 + TRI_VERTEX0_Y] : -triangleScratch[corner * 3 + TRI_VERTEX0_Y])) {
                    *(f32 *)(platformBytes + PLATFORM_BOUNDS_HALF_Y) = (triangleScratch[corner * 3 + TRI_VERTEX0_Y] > 0.0f ? triangleScratch[corner * 3 + TRI_VERTEX0_Y] : -triangleScratch[corner * 3 + TRI_VERTEX0_Y]);
                }
                if (*(f32 *)(platformBytes + PLATFORM_BOUNDS_HALF_Z) < (triangleScratch[corner * 3 + TRI_VERTEX0_Z] > 0.0f ? triangleScratch[corner * 3 + TRI_VERTEX0_Z] : -triangleScratch[corner * 3 + TRI_VERTEX0_Z])) {
                    *(f32 *)(platformBytes + PLATFORM_BOUNDS_HALF_Z) = (triangleScratch[corner * 3 + TRI_VERTEX0_Z] > 0.0f ? triangleScratch[corner * 3 + TRI_VERTEX0_Z] : -triangleScratch[corner * 3 + TRI_VERTEX0_Z]);
                }
            }
        }
        for (triangleIndex = 0; triangleIndex < *(s16 *)collisionMesh; triangleIndex++) {
            func_8015739C(*(s16 *)collisionMesh, *(u8 **)(platformBytes + PLATFORM_COLLISION_FACES), triangleIndex);
        }
    }
}

/* Rebuild world-space platform collision triangles and their normals, planes, and edges. */
void func_8017D558(u8 *platform, f32 localYOffset)
{
    void func_80147094(f32 *, f32 *, f32 *);
    void func_8015BA6C(f32 *);
    f32 edge01[4];
    f32 edge02[4];
    f32 rotation[16];
    u8 *mesh = *(u8 **)(*(u8 **)(*(u8 **)(platform + PLATFORM_MODEL) + PLATFORM_MODEL_COLLISION) + PLATFORM_COLLISION_MESH);
    s32 triangleIndex;
    s32 corner;

    if (!(*(s32 *)(platform + PLATFORM_COLLISION_FLAGS) & PLATFORM_SKIP_COLLISION_REBUILD_MASK)) {
        *(s16 *)(platform + PLATFORM_COLLISION_UPDATE_FRAME) = D_802004E0;
        func_801484F0((f32 *)(platform + PLATFORM_QUATERNION), rotation);
        for (triangleIndex = 0; triangleIndex < *(s16 *)mesh; triangleIndex++) {
            f32 *triangle = (f32 *)(*(u8 **)(platform + PLATFORM_COLLISION_FACES) + triangleIndex * PLATFORM_FACE_BYTES);
            for (corner = 0; corner < COLLISION_TRIANGLE_VERTEX_COUNT; corner++) {
                u8 *indices = (u8 *)(triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_INDICES));
                s32 vertexIndex = *(s16 *)(indices + corner * 2);
                f32 *vertex = (f32 *)(vertexIndex * COLLISION_VERTEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_VERTICES));
                f32 x = *(f32 *)(platform + PLATFORM_SCALE) * vertex[0];
                f32 y = *(f32 *)(platform + PLATFORM_SCALE_Y) * vertex[1] + localYOffset;
                f32 z = *(f32 *)(platform + PLATFORM_SCALE_Z) * vertex[2];
                triangle[TRI_VERTEX0_X + corner * 3] = rotation[0] * x + rotation[4] * y + rotation[8] * z;
                triangle[TRI_VERTEX0_Y + corner * 3] = rotation[1] * x + rotation[5] * y + rotation[9] * z;
                triangle[TRI_VERTEX0_Z + corner * 3] = rotation[2] * x + rotation[6] * y + rotation[10] * z;
            }
            edge01[0] = triangle[TRI_VERTEX1_X] - triangle[TRI_VERTEX0_X];
            edge01[1] = triangle[TRI_VERTEX1_X + 1] - triangle[TRI_VERTEX0_Y];
            edge01[2] = triangle[TRI_VERTEX1_X + 2] - triangle[TRI_VERTEX0_Z];
            edge02[0] = triangle[TRI_VERTEX2_X] - triangle[TRI_VERTEX0_X];
            edge02[1] = triangle[TRI_VERTEX2_X + 1] - triangle[TRI_VERTEX0_Y];
            edge02[2] = triangle[TRI_VERTEX2_X + 2] - triangle[TRI_VERTEX0_Z];
            func_80147094(triangle, edge01, edge02);
            func_80149568(triangle);
            for (corner = 0; corner < COLLISION_TRIANGLE_VERTEX_COUNT; corner++) {
                triangle[TRI_VERTEX0_X + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_X);
                triangle[TRI_VERTEX0_Y + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_Y);
                triangle[TRI_VERTEX0_Z + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_Z);
            }
            func_8015BA6C(triangle);
        }
    }
}

extern f32 D_8010888C;

void func_8017D7B8(u8 *platform)
{
    /* Update world-space platform triangles, rebuilding normals when rotated. */
    extern f32 D_8010888C;
    void func_80147094(f32 *, f32 *, f32 *);
    f32 edge01[4];
    f32 edge02[4];
    f32 rotation[16];
    u8 *mesh = *(u8 **)(*(u8 **)(*(u8 **)(platform + PLATFORM_MODEL) + PLATFORM_MODEL_COLLISION) + PLATFORM_COLLISION_MESH);
    f32 *triangle;
    s32 triangleIndex;
    s32 corner;

    if (!(*(s32 *)(platform + PLATFORM_COLLISION_FLAGS) & PLATFORM_SKIP_COLLISION_UPDATE_MASK)) {
        *(s16 *)(platform + PLATFORM_COLLISION_UPDATE_FRAME) = D_802004E0;
        if (*(s32 *)(platform + PLATFORM_COLLISION_UNK2C) == 0 && *(f32 *)(platform + PLATFORM_QUATERNION_W) == D_8010888C) {
            for (triangleIndex = 0; triangleIndex < *(s16 *)mesh; triangleIndex++) {
                triangle = (f32 *)(*(u8 **)(platform + PLATFORM_COLLISION_FACES) + triangleIndex * PLATFORM_FACE_BYTES);
                for (corner = 0; corner < 3; corner++) {
                    triangle[TRI_VERTEX0_X + corner * 3] = ((f32 *)(*(s16 *)(triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_INDICES) + corner * 2) * COLLISION_VERTEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_VERTICES)))[0];
                    triangle[TRI_VERTEX0_Y + corner * 3] = ((f32 *)(*(s16 *)(triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_INDICES) + corner * 2) * COLLISION_VERTEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_VERTICES)))[1];
                    triangle[TRI_VERTEX0_Z + corner * 3] = ((f32 *)(*(s16 *)(triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_INDICES) + corner * 2) * COLLISION_VERTEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_VERTICES)))[2];
                    triangle[TRI_VERTEX0_X + corner * 3] *= *(f32 *)(platform + PLATFORM_SCALE);
                    triangle[TRI_VERTEX0_Y + corner * 3] *= *(f32 *)(platform + PLATFORM_SCALE_Y);
                    triangle[TRI_VERTEX0_Z + corner * 3] *= *(f32 *)(platform + PLATFORM_SCALE_Z);
                    triangle[TRI_VERTEX0_X + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_X);
                    triangle[TRI_VERTEX0_Y + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_Y);
                    triangle[TRI_VERTEX0_Z + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_Z);
                }
                triangle[TRI_PLANE_DISTANCE] = -(triangle[TRI_VERTEX0_X] * triangle[TRI_NORMAL_X] + triangle[TRI_VERTEX0_Y] * triangle[TRI_NORMAL_Y] + triangle[TRI_VERTEX0_Z] * triangle[TRI_NORMAL_Z]);
            }
        } else {
            func_801484F0((f32 *)(platform + PLATFORM_QUATERNION), rotation);
            for (triangleIndex = 0; triangleIndex < *(s16 *)mesh; triangleIndex++) {
                triangle = (f32 *)(*(u8 **)(platform + PLATFORM_COLLISION_FACES) + triangleIndex * PLATFORM_FACE_BYTES);
                for (corner = 0; corner < 3; corner++) {
                    u8 *indices = (u8 *)(triangleIndex * COLLISION_TRIANGLE_INDEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_INDICES));
                    s32 vertexIndex = *(s16 *)(indices + corner * 2);
                    f32 *vertex = (f32 *)(vertexIndex * COLLISION_VERTEX_BYTES + *(s32 *)(mesh + COLLISION_MESH_VERTICES));
                    f32 scaledX = *(f32 *)(platform + PLATFORM_SCALE) * vertex[0];
                    f32 scaledY = *(f32 *)(platform + PLATFORM_SCALE_Y) * vertex[1];
                    f32 scaledZ = *(f32 *)(platform + PLATFORM_SCALE_Z) * vertex[2];
                    triangle[TRI_VERTEX0_X + corner * 3] = rotation[0] * scaledX + rotation[4] * scaledY + rotation[8] * scaledZ;
                    triangle[TRI_VERTEX0_Y + corner * 3] = rotation[1] * scaledX + rotation[5] * scaledY + rotation[9] * scaledZ;
                    triangle[TRI_VERTEX0_Z + corner * 3] = rotation[2] * scaledX + rotation[6] * scaledY + rotation[10] * scaledZ;
                }
                edge01[0] = triangle[TRI_VERTEX1_X] - triangle[TRI_VERTEX0_X];
                edge01[1] = triangle[TRI_VERTEX1_X + 1] - triangle[TRI_VERTEX0_Y];
                edge01[2] = triangle[TRI_VERTEX1_X + 2] - triangle[TRI_VERTEX0_Z];
                edge02[0] = triangle[TRI_VERTEX2_X] - triangle[TRI_VERTEX0_X];
                edge02[1] = triangle[TRI_VERTEX2_X + 1] - triangle[TRI_VERTEX0_Y];
                edge02[2] = triangle[TRI_VERTEX2_X + 2] - triangle[TRI_VERTEX0_Z];
                func_80147094(triangle, edge01, edge02);
                func_80149568(triangle);
                for (corner = 0; corner < 3; corner++) {
                    triangle[TRI_VERTEX0_X + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_X);
                    triangle[TRI_VERTEX0_Y + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_Y);
                    triangle[TRI_VERTEX0_Z + corner * 3] += *(f32 *)(platform + PLATFORM_WORLD_Z);
                }
                func_8015BE58(triangle);
            }
        }
    }
}

/* Return the first node in the circular list headed by D_802904D4 whose unk06C equals `key`,
 * or NULL if none does. */
void *func_8017DBA0(s32 key) {
    Unk802904D4Node *node = D_802904D4.next;

    while (node != &D_802904D4) {
        if (node->unk06C == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}

/* Returns the next platform after `start` in the platform list (D_802904D4) whose tag (+0x6C) equals `tag`, or NULL. */
Unk802904D4Node *func_8017DBD8(Unk802904D4Node *start, s32 tag) {
    Unk802904D4Node *platform;
    Unk802904D4Node *sentinel;

    platform = start->next;
    if (platform != &D_802904D4) {
        sentinel = &D_802904D4;
        do {
            if (platform->unk06C == tag)
                return platform;
            platform = platform->next;
        } while (platform != sentinel);
    }
    return NULL;
}

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

/* Spring chains: for each of up to 10 chains of linked nodes {first, last, stiffness, damp_ends}, adds spring forces between neighbouring nodes to their velocities. */
void func_8017DC10(void)
{
  extern s32 D_80290430;
  extern s32 D_80290434;
  extern f32 D_80290438;
  extern s32 D_8029043C;
  extern f64 D_80108890;
  Vec3F force[100];
  f32 delta[3];
  s32 chain;
  s32 node_id;
  s32 axis;
  s32 chain_off;
  u8 *node;
  u8 *neighbour;
  f64 end_scale = D_80108890;
  chain_off = 0;
  for (chain = 0;; chain_off = chain * 16)
  {
    if ((*((f32 *) (((u8 *) (&D_80290438)) + chain_off))) == 0)
    {
      return;
    }
    for (node_id = *((s32 *) (((u8 *) (&D_80290430)) + chain_off)); node_id <= (*((s32 *) (((u8 *) (&D_80290434)) + chain_off))); node_id++)
    {
      force[node_id - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off)))] = *((Vec3F *) (&D_801ED3C4));
    }

    node_id = *((s32 *) (((u8 *) (&D_80290430)) + chain_off));
    if (node_id <= (*((s32 *) (((u8 *) (&D_80290434)) + chain_off))))
    {
      s32 off = chain_off;
      do
      {
        node = (u8 *) findNodeW(node_id);
        if ((*((s32 *) (((u8 *) (&D_80290430)) + off))) < node_id)
        {
          neighbour = (u8 *) findNodeW(node_id - 1);
          for (axis = 0; axis < 3; axis++)
          {
            delta[axis] = func_801494CC(*((f32 *) (((*((u8 **) (node + 0x2C))) + (axis * 4)) + 0x38)), *((f32 *) (((*((u8 **) (neighbour + 0x2C))) + (axis * 4)) + 0x38)));
            if (1)
            {
            }
          }

          {
            s32 start = (*((s32 *) (((u8 *) (&D_80290430)) + off))) + 1;
            f32 *f = (f32 *) (&force[node_id - start]);
            func_80148CC8(f, f, delta, *((U32F32 *) (((u8 *) (&D_80290438)) + off)));
          }
        }
        if (node_id < (*((s32 *) (((u8 *) (&D_80290434)) + off))))
        {
          neighbour = (u8 *) findNodeW(node_id + 1);
          for (axis = 0; axis < 3; axis++)
          {
            delta[axis] = func_801494CC(*((f32 *) (((*((u8 **) (node + 0x2C))) + (axis * 4)) + 0x38)), *((f32 *) (((*((u8 **) (neighbour + 0x2C))) + (axis * 4)) + 0x38)));
          }

          {
            s32 start = (*((s32 *) (((u8 *) (&D_80290430)) + off))) - 1;
            f32 *f = (f32 *) (&force[node_id - start]);
            func_80148CC8(f, f, delta, *((U32F32 *) (((u8 *) (&D_80290438)) + off)));
          }
        }
        node_id++;
      }
      while (node_id <= (*((s32 *) (((u8 *) (&D_80290434)) + off))));
    }
    if ((*((s32 *) (((u8 *) (&D_8029043C)) + chain_off))) == 1)
    {
      0[force].x *= end_scale;
      0[force].y *= end_scale;
      0[force].z *= end_scale;
    }
 do { node = (u8 *) findNodeW(*((s32 *) (((u8 *) (&D_80290430)) + chain_off))); *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x50)) += 0[force].x; *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x54)) += 0[force].y; *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x58)) += 0[force].z; if ((*((s32 *) (((u8 *) (&D_8029043C)) + chain_off))) == 1) { ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))))[force].x *= end_scale; ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))))[force].y *= end_scale; ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))))[force].z *= end_scale; } } while (0);
    node = (u8 *) findNodeW(*((s32 *) (((u8 *) (&D_80290434)) + chain_off)));
    *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x50)) += ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))))[force].x;
    *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x54)) += ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))))[force].y;
    *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x58)) += ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))))[force].z;
    node_id = (*((s32 *) (((u8 *) (&D_80290430)) + chain_off))) + 1;
    if (node_id <= ((*((s32 *) (((u8 *) (&D_80290434)) + chain_off))) - 1))
    {
      s32 off = chain_off;
      do
      {
        node = (u8 *) findNodeW(node_id);
        if ((*((s32 *) ((*((u8 **) (node + 0x2C))) + 0x20))) >= 2)
        {
          *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x50)) += (node_id - (*((s32 *) (((u8 *) (&D_80290430)) + off))))[force].x;
          *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x54)) += (node_id - (*((s32 *) (((u8 *) (&D_80290430)) + off))))[force].y;
          *((f32 *) ((*((u8 **) (node + 0x2C))) + 0x58)) += (node_id - (*((s32 *) (((u8 *) (&D_80290430)) + off))))[force].z;
        }
        node_id++;
      }
      while (node_id <= ((*((s32 *) (((u8 *) (&D_80290434)) + off))) - 1));
    }
    if ((++chain) >= 10)
    {
      break;
    }
  }

}

void func_8017E324(s32 platformAddress) {
    /* Ease platform scale and activate its effects when the ball crosses downward. */
    u8 *platform = (u8 *)platformAddress;
    u8 *contactState;
    Vec3F particleVelocity;
    f32 scale;
    f32 easingDivisor;
    u8 particleIndex;
    void func_801BB5C4(s32, s32, f32);

    contactState = *(u8 **)(platform + PLATFORM_GROUND_EFFECT_STATE);
    if (contactState == 0) {
        return;
    }
    easingDivisor = D_80108898;
    scale = *(f32 *)(platform + PLATFORM_SCALE);
    scale -= (scale - *(f32 *)(contactState + PLATFORM_CONTACT_TARGET_SCALE)) / easingDivisor;
    *(f32 *)(platform + PLATFORM_SCALE_Z) = scale;
    *(f32 *)(platform + PLATFORM_SCALE_Y) = scale;
    *(f32 *)(platform + PLATFORM_SCALE) = scale;
    if (*(s16 *)(contactState + PLATFORM_CONTACT_ARMED) == 0) {
        return;
    }
    if (func_80148DB0((u8 *)&D_8029F9AC, platform + PLATFORM_POSITION) < *(f32 *)(platform + PLATFORM_BOUNDS_RADIUS)
        && D_8029F9B0 <= *(f32 *)(platform + PLATFORM_POSITION_Y)
        && *(f32 *)(platform + PLATFORM_POSITION_Y) < D_8029F9BC) {
        particleVelocity.x = easingDivisor;
        particleVelocity.y = 0.0f;
        particleVelocity.z = 0.0f;
        func_801490AC(&particleVelocity, &particleVelocity, *(f32 *)(*(u8 **)(platform + PLATFORM_CONTACT_ROTATION) + PLATFORM_ROTATION_YAW));
        for (particleIndex = 0; particleIndex < PLATFORM_CONTACT_PARTICLE_COUNT; particleIndex++) {
            func_801490AC(&particleVelocity, &particleVelocity, 1.0f);
            func_801BB5C4((s32)(platform + PLATFORM_POSITION), (s32)&particleVelocity, 2.0f);
        }
        *(s16 *)(contactState + PLATFORM_CONTACT_ARMED) = 0;
        *(s32 *)(contactState + PLATFORM_CONTACT_TARGET_SCALE) = 0;
        D_802900E0 = (s32)platform;
        *(Words3 *)(contactState + PLATFORM_CONTACT_SAVED_CAMERA) = *(Words3 *)&D_8028F914;
        func_80178134(PLATFORM_CONTACT_SOUND, &D_8029F9AC, PLATFORM_CONTACT_SOUND_VOLUME, POSITIONAL_SOUND_NEUTRAL_PITCH);
    }
}

typedef struct { s16 v; u8 pad[0x2FE]; } S16Slot;
extern S16Slot D_80299968[];

/* Per-frame player warp/respawn sequence driven by the countdown at state+2 (state = *(D_802900E0+0x54)):
 * at 0x41 it resets the player, camera and level objects and pre-runs the camera a few frames; while the
 * countdown runs it spawns sparkles around the player and scales the player in, and at 0 it hands control
 * back (camera target, scale and physics restored). */
void func_8017E49C(void)
{
  typedef struct 
  {
    f32 v;
    u8 pad[0x2FC];
  } F32Slot;
  typedef struct
  {
    u8 *p;
  } PtrBox;
  extern s8 D_801E7530;
  extern s32 D_801EFCF8;
  extern u8 *D_80290304;
  extern s32 D_8029F574;
  extern s32 D_8029F56C;
  extern s32 D_802901E4;
  extern s32 D_802901E8;
  extern f32 D_80290330;
  extern f32 D_80290360;
  extern f32 D_80290364;
  extern f32 D_80290358;
  extern f32 D_80290370;
  extern f32 D_8029FA34;
  extern f32 D_8029FA38;
  extern f32 D_8029FA3C;
  extern f32 D_8028FB3C;
  extern f32 D_8028FB44;
  extern f32 D_8028FB4C;
  extern f32 D_8028F93C;
  extern f32 D_8028F9C8;
  extern f32 D_8029F9D8;
  extern s16 D_8029F480;
  extern s16 D_8028FC00;
  extern S16Slot D_80299968[];
  extern F32Slot D_802999A4[];
  extern F32Slot D_802999A8[];
  extern F32Slot D_802999AC[];
  extern F32Slot D_80299998[];
  extern const f32 D_8010889C;
  extern const f64 D_801088A0;
  extern const f32 D_801088A8;
  extern const f32 D_801088AC;
  extern const f64 D_801088B0;
  extern const f64 D_801088B8;
  extern const f32 D_801088C0;
  extern const f32 D_801088CC;
  extern const f32 D_801088D0;
  extern const f32 D_801088D4;
  extern const f32 D_801088D8;
  extern const f32 D_801088DC;
  extern const f32 D_801088E0;
  extern const f32 D_801088E4;
  extern const f32 D_801088E8;
  extern const f32 D_801088EC;
  extern const f64 D_801088F0;
  extern const f32 D_801088F8;
  extern const f32 D_801088FC;
  extern const f32 D_80108900;
  extern const f32 D_80108904;
  extern const f32 D_80108908;
  extern const f32 D_80108914;
  extern const f32 D_80108918;
  extern const f32 D_80108920;
  extern const f32 D_80108928;
  extern const f32 D_80108930;
  extern const f32 D_80108938;
  extern const f32 D_80108944;
  extern const f32 D_80108948;
  void func_80160EFC(void);
  void func_80162FF8(void);
  void func_801AE244(void);
  void func_801AE204(s16);
  void func_801B101C(s32);
  void func_8015D020(u8 *);
  void func_80162B60(u8 *);
  void func_80173CE8(s32);
  void func_801490AC(Vec3F *, Vec3F *, f32);
  void func_801BB5C4(s32, s32, f32);
  Vec3F sparkle;
  u8 *state;
  s32 i;
  s32 offset;
  f32 scale;
  f64 t1;
  f64 factor;
  f64 finalScale;
  f64 growth;
  f64 yDrop;
  if ((D_801E7530 == 1) || (D_802900E0 == 0))
  {
    return;
  }
  state = *((u8 **) (((u8 *) D_802900E0) + 0x54));
  if ((*((s16 *) (state + 2))) == 0x41)
  {
    /* first frame: reset everything */
    s32 *p;
    f64 rate;
    if ((*(s8 *)&D_801E7533 != 0) && (D_801E7531 != 0x2A))
    {
      D_802901DC = 0x46;
    }
    D_80297BEC &= ~0x20;
    func_8011BD60();
    p = &D_8029014C;
    if ((*p) != 0)
    {
      func_80178704(p);
    }
    func_80167604(0);
    *((f32 *) (D_802903B0 + 0x70)) = (*((f32 *) (D_802903B0 + 0x74)) = D_8010889C);
    *((s32 *) (&D_8028FAC8)) = D_802900E0 + 0xB4;
    *((Vec3F *) (&D_8028FA00)) = *((Vec3F *) D_8028FAC8);
    D_8028FAD0 = (u8 *) (&D_80290330);
    D_8028FAF4 = 0;
    if (D_801EC740 == 0)
    {
      func_801364D0();
      if (0)
      {
      }
    }
    D_80290304 = (D_8028FBF6 = (D_8029F468 = (D_8029F574 = 0)));
    if (((((((D_801E7531 != 0x1C) && (D_801E7531 != 0x21)) && (D_801E7531 != 0x26)) && (D_801E7531 != 0x28)) && (D_801E7531 != 0xD)) && (D_801E7531 != 0x17)) && (D_801E7531 != 0x12))
    {
      for (i = 0; i < D_801F0198; i++)
      {
        offset = i * 0x300;
        func_80191794(D_802996E8 + (i * 0x300), *((f32 *) (((u8 *) D_802999A4) + offset)), *((f32 *) (((u8 *) D_802999A8) + offset)), *((f32 *) (((u8 *) D_802999AC) + offset)), *((s16 *) (((u8 *) D_80299968) + offset)), *((f32 *) (((u8 *) D_80299998) + offset)), *((s16 *) (&D_80299708[offset])));
      }

    }
    D_802901E4 = (D_802901E8 = 0xF);
    D_8028FB90 = 0;
    if (D_801E7531 == 0x28)
    {
      f32 angle;
      do
      {
        *((Vec3F *) (&D_8029030C)) = *((Vec3F *) (((u8 *) D_802900E0) + 0xB4));
      }
      while (0);
      *((s16 *) (state + 2)) = 0;
      angle = func_801496C8((*((f32 *) ((*((u8 **) (((u8 *) D_802900E0) + 0x54))) + 0x1C))) + D_801088A0);
      D_80290354 = (D_80290360 = angle);
      D_8029039C = (D_80290398 = (D_80290394 = D_801088A8));
      *((s16 *) (((u8 *) D_802900E0) + (0xA6 ^ 0))) = 0;
      for (i = 0; i < 30; i++)
      {
        func_8015D020(D_8028F8E0);
        func_80160EFC();
        func_80162FF8();
      }

      return;
    }
    func_801AE244();
    for (i = 0; i < 3; i++)
    {
      if (((s16 *) D_80290118)[i] != 0)
      {
        func_801AE204(i);
        ((s16 *) D_80290118)[i] = 0;
      }
    }

    if (D_801EFCF8 != 0)
    {
      func_801B101C(10);
      D_8029F468 = 0;
    }
    D_802900E8 = 0;
    {
      s32 *p = &D_8029F56C;
      if ((*p) != 0)
      {
        *p = 1;
      }
    }
    {
      s32 *p = &D_80290300;
      *p &= ~0x4000;
    }
    if (D_801EFCF8 != 0)
    {
      D_8029FA34 = (D_8029FA38 = (D_8029FA3C = 0.0f));
    }
    D_8029F486 = 0;
    D_80290394 = (D_80290398 = (D_8029039C = 0.0f));
    if ((*((s32 *) (&((Vec3F *) (&D_801EFCF8))->x))) != 0)
    {
      *((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x70)) = (*((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x74)) = 0.0f);
      {
        Vec3F *src = (Vec3F *) (((u8 *) D_802900E0) + 0xB4);
        f32 k;
        D_8029F9A8 = 0.0f;
        do
        {
        }
        while (0);
        do
        {
          do
          {
            k = D_801088AC;
          }
          while (0);
        }
        while (0);
        do
        {
          *((Vec3F *) (&D_8029F9AC)) = *src;
        }
        while (0);
        D_8029F9B0 = D_8029F9B0 + k;
      }
      D_8028FBF4 = 0x4B;
    }
    else
    {
      D_8028FBF4 = 0x2D;
    }
    yDrop = (D_801EEC40 * D_801088B0) / D_801088B8;
    {
      Vec3F *src = (Vec3F *) (((u8 *) D_802900E0) + 0xB4);
      Vec3F *dst = (Vec3F *) (&D_8029030C);
      do
      {
        *dst = *src;
      }
      while (0);
    }
    D_80290310 = D_80290310 - yDrop;
    D_8029F47E = 0;
    D_8028FBFB = 0;
    func_80173CE8(0x41);
    rate = D_801EEC40 / D_801088B8;
    do
    {
      *((Vec3F *) (&D_8028F914)) = *((Vec3F *) (state + 4));
    }
    while (0);
    do
    {
      *((Vec3F *) (&D_8028FA00)) = *((Vec3F *) (&D_8029030C));
    }
    while (0);
    {
      f32 num = D_8028F9C8;
      f32 den = D_801088C0;
      f32 fa04 = D_8028FA04;
      f32 r = num / den;
      f64 k = *((const f64 *) (((u8 *) (&D_801088C0)) + 4));
      f32 z = 0.0f;
      f64 prod;
      D_8028F93C = (D_8028F940 = z);
      do {
        prod = rate * k;
      } while (0);
      fa04 += r;
      D_8028FB44 = (D_8028FB4C = (D_8028F938 = z));
      D_8028FA04 = fa04;
      *((f32 *) (state + 0x18)) = prod;
    }
    D_80290354 = (D_80290360 = *((f32 *) (state + 0x1C)));
    /* let the camera settle */
    for (i = 0; i < 20; i++)
    {
      func_8015D020(D_8028F8E0);
      func_80160EFC();
      func_80162FF8();
    }

    D_8029F480 = 0;
    D_8028FC00 = 0;
    func_801758D0(0);
  }
  else
    if (D_801E7531 == 0x28)
  {
    return;
  }
  if ((*((s16 *) (state + 2))) <= 0)
  {
    return;
  }
  D_8029F47E = 0;
  D_8028FBFB = 0;
  /* ring of sparkles around the player */
  sparkle.y = 0.0f;
  sparkle.z = 0;
  sparkle.x = D_801088CC;
  func_801490AC(&sparkle, &sparkle, *((f32 *) ((*((u8 **) (((u8 *) D_802900E0) + 0x2C))) + 0x3C)));
  if (((*((s16 *) (state + 2))) == 0x23) || (((*((s16 *) (state + 2))) == 0xA) && (D_801EFCF8 != 0)))
  {
    scale = D_801088D0;
  }
  else
    if (((*((s16 *) (state + 2))) == 0x24) || (((*((s16 *) (state + 2))) == 0xB) && (D_801EFCF8 != 0)))
  {
    scale = D_801088D4;
  }
  else
  {
    scale = D_801088D8;
  }
  i = 0;
  if ((D_801088DC <= scale) || (D_802004E0 & 1))
  {
    do
    {
      func_801490AC(&sparkle, &sparkle, 1.0f);
      i++;
      func_801BB5C4(D_802900E0 + 0xB4, (s32) (&sparkle), scale);
    }
    while (i < 6);
  }
  if ((*((s16 *) (state + 2))) == 0x23)
  {
    if ((D_801EFCF8 == 0) && ((D_801E7542 == 0) || (D_801E7531 == 0xE)))
    {
      D_8028FAC8 = (u8 *) (&D_8029030C);
      D_8028FAD0 = ((u8 *) (&D_8029030C)) + 0x24;
      D_8028FB3C = D_801088E0;
    }
    func_80167604(2);
    {
      f32 f = (D_801ED680 * D_801088E4) + D_801088E8;
      D_80290370 = D_801088EC;
      D_80290358 = (D_80290364 = 0.0f);
      D_80290334 = f;
    }
  }
  if ((*((s16 *) (state + 2))) < 0x24)
  {
    /* scale the player in */
    for (i = 0; i < 15; i++)
    {
      func_8018D39C(i);
    }

    growth = D_801EEC40;
    growth = growth / D_801088F0;
    sparkle.x = (sparkle.y = (sparkle.z = D_801088F0));
    {
      Vec3F *pv = (Vec3F *) (&D_80290394);
      *pv = sparkle;
      pv->x *= growth;
    }
    D_80290398 *= growth;
    D_8029039C *= growth;
    scale = D_801088F8;
    if (D_801EFCF8 != 0)
    {
      if ((*((s16 *) (state + 2))) == 0xA)
      {
        func_801AE510();
        *((Vec3F *) (&D_8029F9AC)) = *((Vec3F *) (((u8 *) D_802900E0) + 0xB4));
        func_80162B60(((u8 *) (&D_8029F9AC)) - 0x34);
        D_8029FA30 = D_80108904;
        D_8029F9D4 = (D_801ED680 * D_801088FC) + D_80108900;
        func_80178134(0x5D, &D_8029F9AC, 100, 100);
        if (D_801E7542 == 0)
        {
          D_8028FAC8 = (u8 *) (&D_8029F9AC);
          D_8028FAD0 = ((u8 *) (&D_8029F9AC)) + 0x24;
          D_8028FB3C = D_80108908;
        }
      }
      if ((*((s16 *) (state + 2))) < 0xB)
      {
        *((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x70)) = (*((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x74)) = (scale * D_801EEC40) / (*((const f64 *) (((u8 *) (&D_80108908)) + 4))));
      }
      else
      {
        {
          f32 step = D_80108914;
          *((Vec3F *) (&D_8029F9AC)) = *((Vec3F *) (((u8 *) D_802900E0) + 0xB4));
          ((Vec3F *) (&D_8029F9AC))->y += step;
          ((Vec3F *) (&D_8029F9AC))->x += step;
        }
        do
        {
          *((Vec3F *) (&D_8029F9D0)) = *((Vec3F *) (&D_801ED3C4));
        }
        while (0);
        D_8029FA30 = 0.0f;
      }
    }
  }
  else
  {
    D_8028FBD8 = 2;
    if (D_801EFCF8 != 0)
    {
      *((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x70)) = (*((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x74)) = 0.0f);
      {
        f32 step = D_80108918;
        f32 vy, vx;
        *((Vec3F *) (&D_8029F9AC)) = *((Vec3F *) (((u8 *) D_802900E0) + 0xB4));
        vy = ((Vec3F *) (&D_8029F9AC))->y + step;
        vx = ((Vec3F *) (&D_8029F9AC))->x + step;
        D_8029F9D0 = (D_8029F9D4 = (D_8029F9D8 = 0.0f));
        ((Vec3F *) (&D_8029F9AC))->y = vy;
        do
        {
          ((Vec3F *) (&D_8029F9AC))->x = vx;
        }
        while (0);
      }
    }
    factor = D_801EEC40;
    factor = factor * (*((const f64 *) (((u8 *) (&D_80108918)) + 4)));
    factor = factor / (*((const f64 *) (((u8 *) (&D_80108920)) + 4)));
    D_80290394 = (D_80290398 = (D_8029039C = 0.0f));
    D_80290310 = (*((f32 *) (((u8 *) D_802900E0) + 0xB8))) - factor;
    do
    {
      *((Vec3F *) (&D_80290330)) = *((Vec3F *) (&D_801ED3C4));
    }
    while (0);
  }
  if ((--(*((s16 *) (state + 2)))) == 0)
  {
    /* done: give control back */
    if (D_801E7542 == 0)
    {
      D_8028FAC8 = (u8 *) (&D_8029030C);
    }
    if (D_801EFCF8 != 0)
    {
      *((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x70)) = (*((f32 *) ((*((u8 **) (&D_8029FA50))) + 0x74)) = (D_801EEC40 * (*((const f64 *) (((u8 *) (&D_80108928)) + 4)))) / (*((const f64 *) (((u8 *) (&D_80108930)) + 4))));
    }
    finalScale = D_801EEC40;
    finalScale = (float) ((finalScale / (*((const f64 *) (((u8 *) (&D_80108938)) + 4)))) * D_80108944);
    *((s32 *) (state + 0x18)) = 0;
    *((s16 *) (state + 0x14)) = 0;
    {
      f32 *pv = &D_80290394;
      *((volatile f32 *) pv) = (D_80290398 = (D_8029039C = D_80108944));
      D_8029039C = (D_80290398 = (*pv = finalScale));
    }
    *((f32 *) (D_802903B0 + 0x70)) = (*((f32 *) (D_802903B0 + 0x74)) = D_80108948);
    *((f32 *) (D_802903A4 + 8)) = (*((f32 *) (((PtrBox *) (&D_802903B0))->p + 0x70))) * (*((const f64 *) (((u8 *) (&D_80108948)) + 4)));
    func_801758D0(0);
  }
  if ((*((s16 *) (state + 2))) == 0xA)
  {
    *((s32 *) (state + 0x18)) = 0;
  }
}

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
static inline void split_externs_801A0444(void) { extern s32 D_802004E0; extern s32 D_801F01CC; extern s32 D_801F01C8; extern f32 D_801F01C4; extern s32 D_8029F9A4; extern s32 D_802902D8; extern f32 D_8029F9AC; extern f32 D_8029F9B0; extern f32 D_8029F9B4; extern s16 D_801E7460; extern s32 D_8029030C; extern s32 D_801E7588; extern s16 D_8028FBD8; extern f32 D_8028F95C; extern u8 D_801E7541; extern f32 D_80290360; extern s32 D_8029F9A0; extern f32 D_801EFFB0; extern u8 *D_8028F9B8; extern s32 D_8028F908; extern s32 D_80290300; extern f32 D_80290330; extern f32 D_80290334; extern f32 D_80290338; extern s16 D_8028FBF6; extern f32 D_80290310; extern s32 D_8029F394; extern s32 D_8029F210; extern s32 D_801EEB70; extern const f32 D_8010AC3C; extern const f32 D_8010AC40; extern const f32 D_8010AC4C; extern const f64 D_8010AC50; extern const f64 D_8010AC58; extern const f64 D_8010AC60; extern const f64 D_8010AC68; extern const f32 D_8010AC70; extern const f32 D_8010AC74; extern const f32 D_8010AC78; extern const f32 D_8010AC7C; extern const f32 D_8010AC80; extern const f32 D_8010AC84; extern const f64 D_8010AC88; extern const f64 D_8010AC90; extern const f32 D_8010AC98; extern const f32 D_8010AC9C; extern const f32 D_8010ACA0; extern const f32 D_8010ACA4; extern const f32 D_8010ACA8; extern const f32 D_8010ACB4; extern const f32 D_8010ACB8; extern const f32 D_8010ACBC; extern const f32 D_8010ACC0; extern const f32 D_8010ACC4; void func_80149568(f32 *); void func_80148D0C(f32 *, f32 *, f32); void func_80173CE8(s32); void func_80167604(s32); s32 func_80178134(s16, f32 *, s16, s16); void func_801B9974(u8 *, s32, f32, f32, s32, s32); void func_80174058(s16); void func_801B0DDC(void); f32 func_80148DB0(u8 *, u8 *); void func_80165140(f32 *); s32 func_801936CC(u8 *, f32 *, f32, s32); s32 func_801A2944(f32, u8 *); void *func_801A9054(); void func_80133998(void *, s32, s32, s32, f32); f32 func_801496C8(f32); s32 func_80147000(s32); void *func_8017DBA0(s32); void func_801490AC(Vec3F *, Vec3F *, f32); }

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
/* func_8016A058 declaration test */
