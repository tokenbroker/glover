#include "common.h"
#include "structs.h"
#include "effect_visuals.h"
#include "wind_cone.h"

extern u8 D_80109488[], D_80109494[], D_801094A0[], D_801094A8[], D_801094DC[];
extern s16 D_801EFD44;
extern s32 D_801EFCE8;
extern u8 *D_801EFCF0;
extern u8 D_80105F74[], D_80105F80[], D_80105F8C[], D_80105F98[], D_80105FA4[];
extern f32 D_80105FB0, D_80105FB4, D_80105FB8;
extern s32 D_801EC810, D_801EC814;
extern u8 D_801F0238[];
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
f32 func_8014944C(f32, f32);
void func_801B7494(void *, s32, f32);

extern s32 D_801ED3C4;
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

/* Frees every background sprite in the list at D_8028F350 and resets the list (func_8011C810). */
void func_8011C7F0(void) {
    func_8011C810();
}

/* Frees every node of the background sprite list (sentinel D_8028F350), then resets the list. */
void func_8011C810(void) {
    ObjectNode *node;
    ObjectNode *next;
    ObjectNode *sentinel;

    node = D_8028F350.next;
    if (node != &D_8028F350) {
        sentinel = &D_8028F350;
        do {
            next = node->next;
            func_80141720(&node); /* heap free, clears node */
            node = next;
        } while (next != sentinel);
    }
    func_8014A9FC(); /* reset the list to empty */
}

/* Resets the scene view block D_802978E8 to its defaults (the same reset
 * the level loader does): first vector zeroed, then +4 = D_80100DE4 and
 * the three floats at +0xC..+0x14 = D_80100DE8, view mode D_801EC7EA = 2;
 * then dumps heap usage (func_80141874: game_heap_dump). */
void func_8011C870(void) {
    f32 defaultY = D_80100DE4;
    f32 defaultScale = D_80100DE8;

    *(Vec3F *)D_802978E8 = *(Vec3F *)&D_801ED3C4;
    D_801EC7EA = 2;
    *(f32 *)(D_802978E8 + 0x4) = defaultY;
    *(f32 *)(D_802978E8 + 0xC) = defaultScale;
    *(f32 *)(D_802978E8 + 0x10) = defaultScale;
    *(f32 *)(D_802978E8 + 0x14) = defaultScale;
    func_80141874();
}

/* Reset level actors, hide locked hub platforms, and prepare shared effect textures. */
void func_8011C8F4(s32 levelId) {
    s32 index;

    func_801758D0(1);
    func_801AE510();
    func_80162BE0();
    func_80139D70(func_801D2150(&D_8025D578, &D_80100DEC, levelId));
    func_8015C924(&D_802902D8);
    func_8015C924(&D_8029F978);
    D_801EC7DA = LEVEL_DEFAULT_DRAW_DISTANCE;
    func_80182090(levelId);

    if (levelId == LEVEL_HUB) {
        index = *(&D_801EAA57 + D_801EAB24 * LEVEL_SAVE_SLOT_BYTES) + 1;
        if (index < HUB_PLATFORM_TAG_LIMIT) {
            f32 hiddenPlatformY = D_80100E24;
            s32 platformFlagsKeepMask = HUB_PLATFORM_FLAGS_KEEP_MASK;
            do {
                void *platform = func_8017DBA0(index);
                s32 platformFlags = *(s32 *)((u8 *)platform + PLATFORM_FLAGS);
                index++;
                *(s16 *)((u8 *)platform + HUB_PLATFORM_OPACITY) = 0;
                *(f32 *)((u8 *)platform + PLATFORM_POSITION_Y) = hiddenPlatformY;
                *(s32 *)((u8 *)platform + PLATFORM_FLAGS) = platformFlags & platformFlagsKeepMask;
            } while (index < HUB_PLATFORM_TAG_LIMIT);
        }
    }

    if (D_801E7531 != PLAYER_ROBOT_LEVEL) {
        func_80133998(&D_802902D8, LEVEL_INITIAL_ANIMATION, 1, 0, 0);
    }

    func_80133998(&D_8029F978, LEVEL_INITIAL_ANIMATION, 1, 0, 0);
    func_801A7360();
    func_8014FCF8(&D_80297900, func_80139CA0(&D_80100DFC), 0);

    index = 0;
    do {
        Texture80154300 *restartTexture = (Texture80154300 *)D_80297900;
        func_80181A40((s32)restartTexture->image, restartTexture->width, restartTexture->height);
        index++;
    } while (index < RESTART_TEXTURE_SMOOTHING_PASSES);

    func_8014FCF8(&D_80297904, func_80139CA0(&D_80100E08), 0);
    func_8014FCF8(&D_802988BC, func_80139CA0(&D_80100E14), 0);
}

void func_8011CAF8(void) {
    s32 bankIndex;
    s32 modelIndex;
    ObjectNode *sprite[2];
    ObjectNode *nextSprite;
    ObjectNode *listHead;
    ObjectNode *textureSprite;

    /* Release scene resources, reset the heap, and reload common models and cameras. */
    func_801C0A2C(SCENE_AUDIO_ALL, SCENE_AUDIO_STOP_TICKS);
    do {
    } while (func_801C0B00(SCENE_AUDIO_ALL) != 0);
    func_80155A44((s32 *)D_80100E28);
    func_80145E30();
    func_8014F38C();
    for (bankIndex = 0; bankIndex < SCENE_MODEL_BANK_COUNT; bankIndex++) {
        for (modelIndex = 0; modelIndex < D_8028F82C[bankIndex].count; modelIndex++) {
            func_80162694(*(s32 *)((u8 *)((SceneModelEntry *)D_8028F834[bankIndex].items)[modelIndex].modelAddress + SCENE_MODEL_GEOMETRY_OFFSET));
        }
        func_80141720((s32 *)&D_8028F82C[bankIndex]);
        D_8028F82C[bankIndex].count = 0;
    }
    for (bankIndex = 0; bankIndex < SCENE_TEXTURE_BANK_COUNT; bankIndex++) {
        func_80141720(D_8028F7DC[bankIndex]);
    }
    for (bankIndex = 0; bankIndex < PARTICLE_IMAGE_SEQUENCE_COUNT; bankIndex++) {
        func_80141720(D_801F1B24[bankIndex]);
    }
    sprite[0] = ((ObjectNode *)&D_8028D9C0)->next;
    if (sprite[0] != (ObjectNode *)&D_8028D9C0) {
        listHead = (ObjectNode *)&D_8028D9C0;
        do {
            nextSprite = sprite[0]->next;
            func_80141720((s32 *)&sprite[0]);
            sprite[0] = nextSprite;
        } while (nextSprite != listHead);
    }
    func_8014A9D8();
    textureSprite = D_8028F350.next;
    if (textureSprite != (ObjectNode *)((u8 *)&D_8028F354 - 4)) {
        listHead = (ObjectNode *)((u8 *)&D_8028F354 - 4);
        do {
            nextSprite = textureSprite->next;
            func_80141720((s32 *)&textureSprite);
            textureSprite = nextSprite;
        } while (nextSprite != listHead);
    }
    func_8014A9FC();
    func_801456DC();
    func_801627AC((s32)D_8028F8E0);
    func_801627AC((s32)D_8028F9CC);
    func_8013FC38((s32)D_802B0D10, SCENE_HEAP_END - (s32)D_802B0D10);
    func_80150EA4(SCENE_COMMON_MODEL_BANK);
    func_80162BE0();
}

/* Leave the current scene: set the transition color to black and close it fully,
 * fade out every sound effect and wait until none is playing, then unload the level. */
void func_8011CCF0(void) {
    D_801ED402 = 0;
    D_801ED401 = 0;
    D_801ED400 = 0;
    D_801E753C = SCENE_EXIT_TRANSITION_EXTENT;
    func_801C0A2C(SCENE_EXIT_AUDIO_FLAGS, SCENE_EXIT_AUDIO_STOP_TICKS);
    do {
    } while (func_801C0B00(SCENE_EXIT_AUDIO_FLAGS) != 0);
    func_8011CD50(SCENE_EXIT_FULL_UNLOAD);
}

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

void func_80179F5C();
void func_8011FE48(void);
void func_8011CD50(s32 fullUnload) {
    /* Tears down the current level: stops sounds and music, resets camera/fog state, frees every
       level list (objects, effects, actors, water, lights, ...) with func_80141720, and when
       fullUnload is set also frees the persistent lists before resetting the heap. */
    extern s16 D_801E753C;
    extern s32 D_801E747C;
    extern s32 D_8028F814;
    extern s32 D_801F9628;
    extern s32 D_8029F170;
    extern u8 D_802A2000[];
    extern const f32 D_80100E50;
    extern f32 D_801EC7B4;
    extern f32 D_801EC7B8;
    extern f32 D_801EC7C0;
    extern f32 D_801EC7C4;
    s16 *levelState;
    u8 *sound;
    u8 *sound2;
    s32 slotOffset;
    s32 i;
    s32 j;
    u8 *flags;

    levelState = &D_8028FBF4;
    *levelState = 0;
    D_801ED408 = 0;
    D_801E765A = 0;
    D_801E7658 = 0;
    func_801C066C(2, 0);
    func_801C066C(1, 0);
    for (i = 0, sound2 = D_8029F58C, sound = (u8 *)levelState + 0x558, slotOffset = 0; i < 2; i++) {
        if (*(s32 *)((u8 *)&D_8029014C + slotOffset) != 0) {
            func_80178704((s32 *)sound);
        }
        if (*(s32 *)(D_8029F58C + slotOffset) != 0) {
            func_80178704((s32 *)sound2);
        }
        sound2 += 0x1C;
        sound += 0x1C;
        slotOffset += 0x1C;
    }
    func_80155A44((s32 *)D_80100E30);
    D_801EC7D2 = 0;
    D_801EC7B0.x = 0.0f;
    D_801EC7B8 = 0.0f;
    D_801EC7BC.x = 0.0f;
    D_801EC7C4 = 0.0f;
    D_801EC7B4 = D_80100E50;
    D_801EC7C0 = D_80100E50;
    for (i = 0; i < 4; i++) {
        func_80141720((s32 *)&D_8029F6AC[i]);
        D_8029F5C9 = 0;
    }
    func_8014F38C();
    D_801EC7DE = D_801EC7E0 = 0x2D;
    func_80141720((s32 *)&D_801E76B0);
    D_8028F814 = 0;
    D_8028FAF4 = 0;
    if (D_8029011E != 0) {
        func_80176AFC();
    }
    if (D_801EC7F4 != 0) {
        D_8028DA38 = D_80284E98;
    } else {
        D_8028DA38 = D_80289398;
    }
    func_8018DD18();
    func_80178E04();
    D_8028FBF4 = 0;
    D_801E7542 = 0;
    D_801E747C = 0;
    D_802004E0 = 0;
    func_80139D70(func_801D2150(&D_8025D578, D_80100E3C));
    func_8013FBC0(D_8028F9B8, 0x18C);
    func_80145E30();
    func_8011FF08((s32)D_80289320);
    func_8011FF08((s32)D_8028F5A0);
    func_8011FF08((s32)D_8028F618);
    func_8011FF08((s32)D_8028F708);
    for (i = 0; i < 5; i++) {
        func_8011FF08((s32)(D_8028DA40 + i * 0x74));
    }
    for (i = 0; i < 4; i++) {
        func_8011FF08((s32)(D_8028F3D0 + i * 0x74));
    }
    for (i = 0; i < 0xB; i++) {
        func_8011FF08((s32)(D_801F8BD0 + i * 0x74));
    }
    func_8011FF08((s32)D_802AA720);
    func_8011FF08((s32)D_802AA828);
    func_8011FF08((s32)D_802AA8A0);
    func_8011FF08((s32)D_801F92F8);
    func_8010F94C();
    for (i = 0; i < 5; i++) {
        for (j = 0; j < D_8028F82C[i].count; j++) {
            func_80162694(*(s32 *)((u8 *)D_8028F834[i].items[j].unk4 + 0xC));
        }
        func_80141720((s32 *)&D_8028F82C[i]);
        D_8028F82C[i].count = 0;
    }
    if (fullUnload != 0) {
        for (i = 0; i < 5; i++) {
            func_80141720(D_8028F7DC[i]);
        }
    }
    for (i = 0; i < 0x26; i++) {
        func_80141720(D_801F1B24[i]);
    }
    for (i = 0; i < D_801F0198; i++) {
        s32 *base = (s32 *)D_802997CC;
        s32 *soundSlots = base + 0x79;

        for (j = 0; j < 0x1E; j++) {
            s32 *entry = base + i * 0xC0;

            func_80141720(&entry[j + 0x13]);
            func_80141720(&entry[j + 0x31]);
            func_80141720(&entry[j + 0x3B]);
        }
        if (D_802999B0[i][0] != 0) {
            func_80178704((s32 *)(i * 0x300 + (u32)soundSlots));
        }
        if (D_802999CC[i][0] != 0) {
            func_80178704((s32 *)(i * 0x300 + (u32)soundSlots) + 7);
        }
        func_80191548((s32 *)(D_802996E8 + i * 0x300), *(s16 *)(D_80299708 + i * 0x300));
        func_801627AC((s32)(D_802996E8 + i * 0x300));
    }
    for (i = 0; i < 0x78; i++) {
        func_801625F0((s32)(D_802A2000 + i * 0x120), -1);
    }

    {
        s32 *member;
        s32 *child;
        s32 *group;
        s32 *nextGroup;
        s32 *head;

        group = *(s32 **)&D_802994B4;
        if (group != (s32 *)((u8 *)&D_802994B4 - 4)) {
            head = (s32 *)((u8 *)&D_802994B4 - 4);
            do {
                member = (s32 *)group[9];
                nextGroup = (s32 *)group[1];
                if (member != group + 8) {
                    s32 *next;

                    do {
                        next = (s32 *)member[1];
                        func_80141720(member + 9);
                        func_80141720((s32 *)&member);
                        member = next;
                    } while (member != group + 8);
                }
                child = (s32 *)group[3];
                if (child != group + 2) {
                    s32 *next;

                    do {
                        next = (s32 *)child[1];
                        func_80141720(child + 3);
                        func_80141720((s32 *)&child);
                        child = next;
                    } while (child != group + 2);
                }
                func_80141720((s32 *)&group);
                group = nextGroup;
            } while (nextGroup != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_8029F170;
        if (node != &D_8029F170) {
            head = &D_8029F170;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_802903C0;
        if (node != &D_802903C0) {
            head = &D_802903C0;
            do {
                next = (s32 *)node[0];
                if (node[2] != 0) {
                    func_80178704(node + 2);
                }
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)D_802AA9E0;
        if (node != (s32 *)D_802AA9E0) {
            head = (s32 *)D_802AA9E0;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)D_802AA918;
        if (node != (s32 *)D_802AA918) {
            head = (s32 *)D_802AA918;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)D_802AA7A0;
        if (node != (s32 *)D_802AA7A0) {
            head = (s32 *)D_802AA7A0;
            do {
                if (node[0x16] != 0) {
                    func_80178704(node + 0x16);
                }
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_801F9628;
        if (node != &D_801F9628) {
            head = &D_801F9628;
            do {
                next = (s32 *)node[0];
                for (i = 0; i < node[3]; i++) {
                    func_80141720(node + 4 + i);
                }
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_8028D9C0;
        if (node != (s32 *)&D_8028D9C0) {
            head = (s32 *)&D_8028D9C0;
            do {
                next = (s32 *)node[0];
                func_8011FF08((s32)node);
                node[0] = 0;
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    func_8014A9D8();
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_8029948C;
        if (node != &D_8029948C) {
            head = &D_8029948C;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_80299290;
        if (node != &D_80299290) {
            head = &D_80299290;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_80299250;
        if (node != &D_80299250) {
            head = &D_80299250;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *member;
        s32 *group;
        s32 *next;
        s32 *nextGroup;
        s32 *head;

        D_8029928C = 0;
        group = (s32 *)*(s32 *)&D_802993A4;
        if (group != (s32 *)((u8 *)&D_802993A4 - 4)) {
            head = (s32 *)((u8 *)&D_802993A4 - 4);
            do {
                member = (s32 *)group[3];
                nextGroup = (s32 *)group[1];
                if (member != group + 2) {
                    do {
                        next = (s32 *)member[1];
                        func_80141720((s32 *)&member);
                        member = next;
                    } while (next != group + 2);
                }
                func_80141720((s32 *)&group);
                group = nextGroup;
            } while (nextGroup != head);
        }
    }
    {
        u8 *node;
        u8 *next;
        u8 *head;

        node = *(u8 **)&D_80299244;
        if (node != (u8 *)&D_80299244 - 0x34) {
            head = (u8 *)&D_80299244 - 0x34;
            do {
                next = *(u8 **)(node + 0x34);
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    {
        s32 *node[2];
        s32 *next;
        s32 *head;

        node[0] = *(s32 **)D_802991A8;
        if (node[0] != (s32 *)D_802991A8) {
            head = (s32 *)D_802991A8;
            do {
                next = (s32 *)node[0][0];
                func_80141720((s32 *)node);
                node[0] = next;
            } while (next != head);
        }
    }
    if (fullUnload != 0) {
        s32 *node[2];
        s32 *next;
        s32 *head;

        node[0] = (s32 *)D_8028F350.next;
        if (node[0] != (s32 *)((u8 *)&D_8028F354 - 4)) {
            head = (s32 *)((u8 *)&D_8028F354 - 4);
            do {
                next = (s32 *)node[0][0];
                func_80141720((s32 *)node);
                node[0] = next;
            } while (next != head);
        }
        func_8014A9FC();
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)&D_802AAF60;
        if (node != (s32 *)&D_802AAF60) {
            head = (s32 *)&D_802AAF60;
            do {
                if (node[0x12] != 0) {
                    func_80178704(node + 0x12);
                }
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    func_801627AC((s32)D_8028F8E0);
    func_801627AC((s32)D_8028F9CC);
    func_801627AC((s32)&D_802902D8);
    func_801627AC((s32)&D_8029F978);
    func_801627AC((s32)D_8028FC08);
    func_801627AC((s32)(D_8028FC08 + 0xE4));
    {
        ObjectNode *object;
        ObjectNode *next;

        object = D_8026A148.next;
        if (object != &D_8026A148) {
            do {
                next = object->next;
                func_80191548((s32 *)object, object->type);
                func_801627AC((s32)object);
                object = next;
            } while (object != &D_8026A148);
        }
    }
    {
        s32 *effect;
        s32 *next;

        effect = *(s32 **)&D_8029F210;
        if (effect != &D_8029F210) {
            do {
                next = (s32 *)effect[0];
                func_801A8EF8(effect);
                effect = next;
            } while (effect != &D_8029F210);
        }
    }
    {
        s32 *helper;
        s32 *next;

        helper = *(s32 **)&D_802904D4;
        if (helper != (s32 *)&D_802904D4) {
            do {
                next = (s32 *)helper[0];
                func_80179F5C(helper, 0);
                helper = next;
            } while (helper != (s32 *)&D_802904D4);
        }
    }
    {
        s32 *node;
        s32 *next;
        s32 *head;

        node = *(s32 **)D_802892D8;
        if (node != (s32 *)D_802892D8) {
            head = (s32 *)D_802892D8;
            do {
                next = (s32 *)node[0];
                func_80141720((s32 *)&node);
                node = next;
            } while (next != head);
        }
    }
    func_8014ABEC();
    func_80141874();
    func_801456DC();
    flags = (u8 *)&D_801E7584;
    *flags &= 0xFE;
    func_80188F90();
    func_801A6820();
    D_801F0198 = 0;
    if (fullUnload != 0) {
        func_8011FD80();
    } else {
        func_8011FE48();
    }
    func_8013FC38((s32)D_802B0D10, 0x80400000 - (s32)D_802B0D10);
    func_80150EA4(0);
    func_80162BE0();
}

/*
 * Load level `level` (stored in D_801E7531): reset per-level state, load
 * the HUD and shared assets, pick the level's music and banks, build the
 * player and ball (func_80142A10), and set the draw distance.
 */
void func_8011D88C(s32 level) {
    typedef struct {
        s8 v;
        s8 pad[0x17];
    } LevelGroupEntry;
    extern u8 D_80100E54[];
    extern u8 D_80100E60[];
    extern u8 D_80100EA4[];
    extern u8 D_80100EB4[];
    extern u8 D_80100EC4[];
    extern u8 D_80100ED4[];
    extern u8 D_80100EE4[];
    extern u8 D_80100EF4[];
    extern u8 D_80100F04[];
    extern u8 D_80100F14[];
    extern u8 D_80100F24[];
    extern u8 D_80100F34[];
    extern u8 D_80100F40[];
    extern u8 D_80100F50[];
    extern u8 D_80100F60[];
    extern u8 D_80100F70[];
    extern u8 D_80100F80[];
    extern u8 D_80100F8C[];
    extern u8 D_80100F98[];
    extern u8 D_80100FA4[];
    extern u8 D_80100FB4[];
    extern f32 D_80101078;
    extern u8 D_801EC7A4;
    extern s16 D_801E7468;
    extern s32 *D_8029F5D0;
    extern s32 *D_8029F968;
    extern u8 *D_801F0124;
    extern u8 D_801EFC92;
    extern s16 D_801EEB78;
    extern struct {
        u8 pad[0x38];
    } D_801E6910[];
    extern s32 D_80297908;
    extern s32 D_80297910;
    extern s32 D_8029790C;
    extern s32 D_802AA798;
    extern s32 D_8029793C;
    extern s8 D_801E7390[];
    extern s8 D_801E7391[];
    extern LevelGroupEntry D_801E7392[];
    extern s32 D_801EF494;
    extern s32 D_801EF894;
    extern s32 D_801E7590;
    extern u8 D_801E6938[];
    extern s32 D_801EC7CC;
    extern s8 D_801E7530;
    extern u8 D_801E6945[];
    extern f32 D_801EC7A0;
    extern u8 D_80202218;
    extern struct {
        s32 f;
        u8 pad[396];
    } D_801FAB78[];
    s32 func_801A67E4(void);
    void func_801C066C(s32, s32);
    void func_80191260(void);
    void func_8014F510(s32);
    void func_8014A460(Obj8014A460 *, u8 *, s32, s32, s32, s32);
    s32 func_80124F2C(s32);
    void func_80179468(s32);
    void func_80142A10(void);
    void func_80177A14(s32);
    s8 *currentLevel = &D_801E7531;
    s8 *currentLevel2;
    D_801EC7D2 = 0;
    func_80155A44((s32 *)D_80100E54);
    D_801EC7A4 = 0;
    D_801E7468 = 0;
    D_8029018C = 0;
    D_8029F5D0 = 0;
    D_8029F968 = 0;
    *currentLevel = level;
    D_80297BEC &= 0xFFEFF87F;
    D_801F0124[0xA] = func_801A67E4() + 0x31;
    D_801EFC92 = 3;
    D_801E765A = 0;
    D_801E7658 = 0;
    D_801EEB78 = 1;
    func_801C066C(2, 0);
    func_801C066C(1, 0);
    func_80139D70(func_801D2150(&D_8025D578, D_80100E60, &D_801E6910[level]));
    D_801F0198 = 0;
    func_80191260();
    func_8014F510(2);
    D_801ED408 = 0;
    /* Extra HUD sprites for game mode 2. */
    if (D_801EC7F0 == 2) {
        D_801ED408 = 1;
        func_8014F510(0x12);
        func_8014A460((Obj8014A460 *)D_801F8BD0, D_80100EA4, 0x2E, 0xB6, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x74), D_80100EB4, 0x5E, 0xB6, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0xE8), D_80100EC4, 0x5C, 0xAB, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x15C), D_80100ED4, 0x55, 0xA4, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x1D0), D_80100EE4, 0x46, 0xC8, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x244), D_80100EF4, 0x63, 0x98, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x2B8), D_80100F04, 0x63, 0xA4, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x32C), D_80100F14, 0x5D, 0x9E, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x3A0), D_80100F24, 0x69, 0x9E, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x414), D_80100F34, 0xA0, 0x96, 0, 1);
        func_8014A460((Obj8014A460 *)(D_801F8BD0 + 0x488), D_80100F40, 0x67, 0x8E, 0, 1);
    }
    /* Shared textures, by name hash. */
    func_8014FCF8(&D_80297908, func_80139CA0(D_80100F50), 1);
    func_8014FCF8(&D_80297BF0, func_80139CA0(D_80100F60), 1);
    func_8014FCF8(&D_80297910, func_80139CA0(D_80100F70), 1);
    func_8014FCF8(&D_8029790C, func_80139CA0(D_80100F80), 1);
    func_8014FCF8(&D_802AA798, func_80139CA0(D_80100F8C), 1);
    func_8014FCF8(&(&D_802AA798)[1], func_80139CA0(D_80100F98), 1);
    func_8014FCF8(&D_8029793C, func_80139CA0(D_80100FA4), 1);
    func_8014A460((Obj8014A460 *)D_802AA720, D_80100F8C, 0, 0, 0, 1);
    func_8014A460((Obj8014A460 *)D_802AA828, D_80100FB4, 0, 0, 0, 1);
    /* Banks for the level's world (levels below 0x2E) or the special levels. */
    D_801E7533 = func_80124F2C(*currentLevel);
    if ((*currentLevel) < 0x2E) {
        s32 bank;
        if ((*currentLevel) == 0x2A) {
            bank = D_801E7391[0];
        } else if ((*currentLevel) == 0x2B) {
            bank = 0xC;
        } else {
            bank = D_801E7391[D_801E7533 * 24];
        }
        func_8014F510(bank);
        func_80150EA4(D_801E7390[D_801E7533 * 24]);
    } else {
        if ((*currentLevel) == 0x2E) {
            func_80179468((s32)(&D_801EF494));
        }
        if ((*currentLevel) == 0x2F) {
            func_80179468((s32)(&D_801EF894));
        }
        func_8014F510(0xB);
    }
    if (D_801E7531 == 0x13) {
        if (D_80297BEC & 0x200000) {
            D_801E7590 = 1 - D_801E7590;
            func_8014F510(D_801E7590 + 0x10);
        } else {
            func_8014F510(0xF);
        }
    }
    if (!(level == 0x2C)) {
        func_80150EA4(1);
    } else {
        func_8014F510(0xD);
        func_80150EA4(0x45);
    }
    currentLevel2 = &D_801E7531;
    func_80150EA4(*((s32 *)(D_801E6938 + ((*currentLevel2) * 0x38))));
    func_80142A10();
    func_8011C8F4(level);
    D_801EC7CC = 0;
    /* Music. */
    if ((*currentLevel2) == 0x2A) {
        func_80177A14(D_801E6945[D_801E7392[D_801E7533].v * 0x38]);
    } else if ((D_801EC7F0 != 2) || ((*currentLevel2) == 0x27)) {
        if (D_801E7530 == 0xF) {
            func_80177A14(0x19);
        } else {
            func_80177A14(D_801E6945[level * 0x38]);
        }
    }
    /* Squared draw distance. */
    switch (level) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 13:
    case 14:
    case 18:
    case 19:
    case 23:
    case 24:
    case 28:
    case 29:
    case 33:
    case 34:
    case 38:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
        D_801EC7A0 = D_801EC7DA * D_801EC7DA;
        break;
    default:
        D_801EC7A0 = D_80101078;
        break;
    }

    D_801FAB78[D_80202218].f = 99999;
}

/* Update the title menu, then start the saved game, enter practice, or open options. */
void func_8011DF60(void) {
    extern s8 D_801E7530;
    extern s32 D_801E747C;
    extern u8 D_801E7598; /* selected title option */
    extern u8 D_801E7599; /* input repeat delay */
    extern s32 D_801E7594; /* last drawn title option */
    extern u8 *D_8028FAC8;
    extern s32 D_801F7D90[]; /* title text handles */
    extern s32 D_801F7D94; /* practice text handle */
    extern s32 D_801F7D98; /* options text handle */
    extern s32 D_801F7DC4; /* version text handle */
    extern f32 D_80101088; /* version text scale: 0.8 */
    extern f32 D_8010108C; /* Start text scale: 1.0 */
    extern f32 D_80101090; /* Practice text scale: 1.0 */
    extern f32 D_80101094; /* Options text scale: 1.0 */
    extern s32 D_801EACE0; /* build version string */
    extern s32 D_801EAD20[]; /* Start text by language */
    extern s32 D_801EAD2C[]; /* Practice text by language */
    extern s32 D_801EAD38[]; /* Options text by language */
    extern u8 D_8010107C[]; /* "titlescn" debug tag */
    extern u8 D_80202218; /* active controller index */
    extern struct { s16 f; u8 pad[398]; } D_801FAA92[];
    void func_80155AE4(void *); /* start drawing */
    void func_80125040(void); /* animate title camera */
    void func_8012643C(void); /* update pause menu */
    void func_80145CEC(s32); /* destroy text label */
    void func_80145680(s32);
    void func_8011FD80(void); /* initialize scene object lists */
    void func_8011D88C(s32); /* load scene assets */
    s32 func_801399EC(s32); /* menu confirmation pressed */
    void func_8014D4D0(void); /* begin menu exit transition */
    s32 func_8014D5E0(void); /* menu exit transition complete */
    void func_8011C810(void); /* free scene object list */
    void func_801C0A2C(s32, s32); /* stop audio channels selected by mask */
    s32 func_801C0B00(s32); /* count active audio channels selected by mask */
    void func_8011CD50(s32); /* unload level */
    void func_8011F9F4(void); /* reset game progress */
    void func_8011FB8C(void); /* restore saved game state */
    void func_8011FF40(s32); /* load level */
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); /* create text label */
    s32 versionLine = 1;
    s32 lineHeight = TITLE_MENU_VERSION_Y;
    s32 textIndex;
    s16 stickY;

    D_801E7530 = 1;
    if (D_801E747C == 0) {
        func_80145680(0);
        D_801E7584 = 0;
        D_80201004 = 0;
        D_802004E0 = 0;
        D_801E7598 = TITLE_MENU_START;
        D_801E7599 = 0;
        func_8011FD80();
        D_8028FAC8 = (u8 *)&D_801ED3C4;
        func_8011D88C(TITLE_MENU_SCENE);
        D_801ED403 = 0;
        func_8014D548();
        for (textIndex = TITLE_MENU_TEXT_CAPACITY - 1; textIndex >= 0; textIndex--) {
            (&D_801F7DC4)[textIndex - (TITLE_MENU_TEXT_CAPACITY - 1)] = 0;
        }
        D_801F7DC4 = (s32)func_801469E4(TITLE_MENU_CENTER_X, versionLine * lineHeight, 0xFF, 0xFF, 0xFF, 0xFF, D_80101088, D_80101088, 0, D_801EACE0, 1);
        D_801E7594 = TITLE_MENU_SELECTION_UNDRAWN;
    }
    if (D_802004E0 >= 0x1A) {
        func_80155AE4(D_8010107C);
    }
    func_80125040();
    func_8012643C();
    if (D_801E7594 != D_801E7598) {
        D_801E7594 = D_801E7598;
        for (textIndex = 0; textIndex < TITLE_MENU_REDRAW_TEXT_COUNT; textIndex++) {
            func_80145CEC(D_801F7D90[textIndex]);
        }
        D_801F7D90[0] = (s32)func_801469E4(TITLE_MENU_CENTER_X, TITLE_MENU_START_Y, 0xFF, 0xFF, 0xFF, D_801E7598 == TITLE_MENU_START ? 0xFF : 0x64, D_8010108C, D_8010108C, 0, D_801EAD20[D_801E7586], 1);
        D_801F7D94 = (s32)func_801469E4(TITLE_MENU_CENTER_X, TITLE_MENU_PRACTICE_Y, 0xFF, 0xFF, 0xFF, D_801E7598 == TITLE_MENU_PRACTICE ? 0xFF : 0x96, D_80101090, D_80101090, 0, D_801EAD2C[D_801E7586], 1);
        D_801F7D98 = (s32)func_801469E4(TITLE_MENU_CENTER_X, TITLE_MENU_OPTIONS_Y, 0xFF, 0xFF, 0xFF, D_801E7598 == TITLE_MENU_OPTIONS ? 0xFF : 0x96, D_80101094, D_80101094, 0, D_801EAD38[D_801E7586], 1);
    }
    D_801E747C++;
    if (D_801E7599 == 0 && func_801399EC(D_80202218) != 0) {
        func_8014D4D0();
        D_801E7599 = TITLE_MENU_CONFIRM_DELAY;
    }
    stickY = ((ControllerStickYView *)D_801FAA92)[D_80202218].stickY;
    if (stickY >= TITLE_MENU_STICK_UP_THRESHOLD) {
        if (D_801E7599 == 0 && D_801E7598 != TITLE_MENU_START) {
            D_801E7598--;
            D_801E7599 = TITLE_MENU_REPEAT_DELAY;
        }
    } else if (stickY < TITLE_MENU_STICK_DOWN_THRESHOLD) {
        if (D_801E7599 == 0 && D_801E7598 < TITLE_MENU_OPTIONS) {
            D_801E7598++;
            D_801E7599 = TITLE_MENU_REPEAT_DELAY;
        }
    } else {
        D_801E7599 = 0;
    }
    if (D_801E7599 != 0) {
        D_801E7599--;
    }
    if (func_8014D5E0() != 0) {
        D_801E7599 = 0;
        D_801E747C = 0;
        for (textIndex = 0; textIndex < TITLE_MENU_TEXT_CAPACITY; textIndex++) {
            func_80145CEC(D_801F7D90[textIndex]);
        }
        switch (D_801E7598) {
        case TITLE_MENU_START:
            func_8011C810();
            D_80201004 = 0;
            D_802004E0 = 0;
            D_801ED402 = 0;
            D_801ED401 = 0;
            D_801ED400 = 0;
            D_801E753C = 0x12C;
            func_801C0A2C(1, 1);
            do {
            } while (func_801C0B00(1) != 0);
            func_8011CD50(1);
            func_8011FB8C();
            func_80155A44((s32 *)D_8010107C);
            func_8011FF40(D_801E7531);
            break;
        case TITLE_MENU_PRACTICE:
            func_8011C810();
            D_80201004 = 0;
            D_802004E0 = 0;
            D_801ED402 = 0;
            D_801ED401 = 0;
            D_801ED400 = 0;
            D_801E753C = 0x12C;
            func_801C0A2C(1, 1);
            do {
            } while (func_801C0B00(1) != 0);
            func_8011CD50(1);
            func_8011F9F4();
            func_80155A44((s32 *)D_8010107C);
            func_8011FF40(TITLE_MENU_PRACTICE_LEVEL);
            break;
        case TITLE_MENU_OPTIONS:
            D_801E7530 = 2;
            break;
        }
    }
}

/* Update the scrolling level-select menu, preview its music, and load a confirmed selection. */
void func_8011E51C(void)
{
  extern s16 D_801EAB24; /* save slot index */
  extern u8 D_801EAAEC[]; /* scratch save slot used by level select */
  extern s32 D_801E747C; /* frames spent in this menu */
  extern u8 D_80101098[]; /* "levelselect" drawing debug tag */
  extern s32 D_801F7DCC[]; /* level-list text handles */
  extern f32 D_801010D0; /* heading scale: 1.0 */
  extern f32 D_801010D4; /* selected row scale: 1.4 */
  extern f32 D_801010D8; /* normal row scale: 1.0 */
  extern u8 D_801010A4[]; /* "SELECT LEVEL" */
  extern u8 D_801010B4[]; /* "levelseect" drawing debug tag */
  extern u8 D_801010C0[]; /* "%s" */
  extern u8 D_801010C4[]; /* "levelselec" drawing debug tag */
  extern s32 D_801F7DF8; /* heading text handle */
  extern s32 D_801E75A0; /* selected level index */
  extern s32 D_801E75A4; /* last drawn selection */
  extern s32 D_801E75A8; /* input repeat/confirmation countdown */
  extern s32 D_801F7DC8; /* level count; text handles follow in memory */
  extern struct 
  {
    u8 pad[0x38];
  } D_801E6910[];
  extern u8 D_801E6945[]; /* music ID byte at offset 0x35 of each level entry */
  extern u8 D_802846F8[]; /* text formatting buffer */
  extern u8 D_80202218; /* active controller index */
  extern struct 
  {
    s16 f;
    u8 pad[398];
  } D_801FAA92[];
  extern struct 
  {
    u8 f;
    u8 pad[399];
  } D_801FAAC8[];
  extern s32 D_8028FAF4;
  extern s32 D_801EFD00;
  void func_80155AE4(void *); /* start drawing */
  void func_80125040(void); /* animate menu camera */
  void func_80145CEC(s32); /* destroy text label */
  void func_80145680(s32); /* select text object list */
  void func_801C066C(s32, s32); /* set master audio volume by channel mask */
  void func_80177A14(s32); /* play music by ID */
  void func_8010E6AC(void); /* update screen transition */
  s32 func_801399EC(s32); /* test menu confirmation buttons */
  void func_8014D4D0(void); /* begin menu exit transition */
  s32 func_8014D5E0(void); /* test menu exit transition completion */
  void func_8011C810(void); /* free scene objects */
  void func_801C0A2C(s32, s32); /* stop audio channels selected by mask */
  s32 func_801C0B00(s32); /* count active audio channels selected by mask */
  void func_8011CD50(s32); /* unload level */
  void func_8011F9F4(void); /* reset game progress */
  void func_8011FF40(s32); /* load selected level */
  void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); /* create text label */
  s32 row = 1;
  s32 lineHeight = LEVEL_SELECT_LINE_HEIGHT;
  s32 entryIndex;
  s32 textAddressOrBlue;
  s32 clampedSelection;
  s32 nonnegativeSelection;
  D_801EAB24 = LEVEL_SELECT_SAVE_SLOT;
  func_8013FBC0(D_801EAAEC, LEVEL_SELECT_SAVE_SLOT_BYTES);
  D_801EAA55[D_801EAB24 * LEVEL_SELECT_SAVE_SLOT_BYTES] = 1;
  if (D_801E747C == 0)
  {
    func_80155A44((s32 *) D_80101098);
    func_8014D548();
    for (entryIndex = LEVEL_SELECT_TEXT_CAPACITY - 1; entryIndex >= 0; entryIndex--)
    {
      D_801F7DCC[entryIndex] = 0;
    }

    D_801F7DF8 = (s32) func_801469E4(LEVEL_SELECT_CENTER_X, (row << 1) * lineHeight, 0xFF, 0xFF, 0xFF, 0xFF, D_801010D0, D_801010D0, 0, (s32) D_801010A4, 1);
    func_80155AE4(D_801010B4);
    D_801E75A4 = LEVEL_SELECT_SELECTION_UNDRAWN;
    D_801F7DC8 = LEVEL_SELECT_LEVEL_COUNT;
  }
  func_80125040();
  row = 0;
  D_801E747C++;
  if (D_801E75A4 != D_801E75A0)
  {
    textAddressOrBlue = (s32) D_801F7DCC;
    for (entryIndex = 0; entryIndex < LEVEL_SELECT_REDRAW_TEXT_COUNT;)
    {
      do
      {
        func_80145CEC(*(s32 *) textAddressOrBlue);
        textAddressOrBlue += 4;
        entryIndex++;
      }
      while (0);
    }

  }
  func_80145680(1);
  for (entryIndex = D_801E75A0 - LEVEL_SELECT_VISIBLE_RADIUS; entryIndex <= (D_801E75A0 + LEVEL_SELECT_VISIBLE_RADIUS); entryIndex++)
  {
    u8 *textBuffer = D_802846F8;
    f32 selectedScale = *((const f32 *) (&D_801010D4));
    s32 enabled = 1;
    s32 opaqueAlpha = 255;
    f32 normalScale = *((const f32 *) (&D_801010D8));
    row++;
    if ((entryIndex >= 0) && (entryIndex < D_801F7DC8))
    {
      textAddressOrBlue = (entryIndex & 1) ? (0) : (-1);
      func_801D2150(textBuffer, D_801010C0, &D_801E6910[entryIndex]);
      if (entryIndex == D_801E75A0)
      {
        (&D_801F7DC8)[row] = (s32) func_801469E4(LEVEL_SELECT_CENTER_X, (s16) ((row * lineHeight) + LEVEL_SELECT_LIST_Y_OFFSET), 0xFF, 0xFF, (u8) textAddressOrBlue, (D_801E747C * 40) & 0xFF, selectedScale, selectedScale, enabled, (s32) textBuffer, enabled);
      }
      else
        if (D_801E75A4 != D_801E75A0)
      {
        (&D_801F7DC8)[row] = (s32) func_801469E4(LEVEL_SELECT_CENTER_X, (s16) ((row * lineHeight) + LEVEL_SELECT_LIST_Y_OFFSET), 0xFF, 0xFF, (u8) textAddressOrBlue, opaqueAlpha, normalScale, normalScale, 0, (s32) textBuffer, enabled);
      }
    }
  }

  func_80145680(0);
  D_801E75A4 = D_801E75A0;
  if (D_801E75A8 != 0)
  {
    D_801E75A8--;
  }
  else
  {
    if (D_801FAA92[D_80202218].f >= LEVEL_SELECT_STICK_UP_THRESHOLD)
    {
      D_801E75A0 = D_801E75A0 - 1;
      D_801E75A8 = 1;
    }
    if (D_801FAA92[D_80202218].f < (LEVEL_SELECT_STICK_DOWN_THRESHOLD))
    {
      D_801E75A8 = 1;
      D_801E75A0 = D_801E75A0 + 1;
    }
  }
  func_801C066C(2, LEVEL_SELECT_MUSIC_VOLUME);
  if (D_801FAAC8[D_80202218].f != 0)
  {
    func_80177A14(D_801E6945[D_801E75A0 * LEVEL_SELECT_ENTRY_STRIDE]);
  }
  func_8010E6AC();
  nonnegativeSelection = (D_801E75A0 > 0) ? (D_801E75A0) : (0);
  clampedSelection = D_801F7DC8 - 1;
  if (nonnegativeSelection < clampedSelection)
  {
    clampedSelection = (D_801E75A0 > 0) ? (D_801E75A0) : (0);
  }
  D_801E75A0 = clampedSelection;
  if ((D_801E75A8 == 0) && (func_801399EC(D_80202218) != 0))
  {
    func_8014D4D0();
    D_801E75A8 = LEVEL_SELECT_CONFIRM_DELAY;
  }
  if (func_8014D5E0() != 0)
  {
    D_801E75A8 = 0;
    D_8028FAF4 = 0;
    func_8011C810();
    D_80201004 = 0;
    D_802004E0 = 0;
    D_801ED402 = 0;
    D_801ED401 = 0;
    D_801ED400 = 0;
    D_801E753C = 0x12C;
    func_801C0A2C(1, 1);
    do
    {
    }
    while (func_801C0B00(1) != 0);
    func_8011CD50(1);
    func_8011F9F4();
    func_80155A44((s32 *) D_801010C4);
    D_801EFD00 = -1;
    func_8011FF40(D_801E75A0);
  }
}

/*
 * Time-trial selection screen, run once per frame: on the first frame it builds the
 * title text and the list of levels that have a record; then it draws up to seven
 * rows of "level  time  name" around the cursor (the selected row flashes), handles
 * up/down/confirm/back input, and when the fade-out ends either starts the chosen
 * level (D_801E75B4 > 0) or returns to the menu.
 */
void func_8011EAB8(void) {
    extern s16 D_801EAB24;
    extern u8 D_801EAAEC[];
    extern s32 D_801E747C;
    extern u8 D_801010DC[];
    extern u8 D_801010E8[];
    extern u8 D_801010F0[];
    extern s32 D_801F7E04;
    extern s32 D_801F7E08;
    extern s32 D_801F7E0C[][3];
    extern s32 D_801F7E90;
    extern s32 D_801F7E9C;
    extern s32 D_801F7EA8;
    extern s32 D_801F7EB4[];
    extern s32 D_801F7F74;
    extern s32 D_801F7F78;
    extern s32 D_801E75AC;
    extern s32 D_801E75B0;
    extern s32 D_801E75B4;
    extern f32 D_801010F8;
    extern f32 D_801010FC;
    extern const f32 D_80101100;
    extern const f32 D_80101104;
    extern f32 D_80101108;
    extern f32 D_8010110C;
    extern f32 D_80101110;
    extern f32 D_80101114;
    extern f32 D_80101118;
    extern f32 D_8010111C;
    extern f32 D_80101120;
    extern f32 D_80101124;
    extern f32 D_80101128;
    extern f32 D_8010112C;
    extern f32 D_80101130;
    extern f32 D_80101134;
    extern f32 D_80101138;
    extern f32 D_8010113C;
    extern s32 D_801EADA4[];
    extern s32 D_801EADC8[];
    extern s32 D_801EAE70[];
    extern s32 D_801EAEAC[][3];
    extern struct Rec6790 { u16 time; u8 name[4]; } D_801E6790[];
    extern struct Rec6790 D_801E6850[];
    extern s32 D_801E693C[][14];
    extern u8 D_802846F8[];
    extern u8 D_80202218;
    extern struct { s16 f; u8 pad[398]; } D_801FAA92[];
    extern struct { u8 f; u8 pad[399]; } D_801FAAC8[];
    extern u8 D_801EC7D2;
    extern s32 D_8028FAF4;
    extern s32 D_801EFD00;
    extern s8 D_801E7530;
    extern s32 D_801E58A8;
    extern s32 D_801E58B4;
    void func_80155AE4(void *);
    void func_80125040(void);
    void func_8012643C(void);
    void func_80145CEC(s32);
    void func_80145680(s32);
    s32 func_8012ABFC(s32);
    s32 func_8012AC54(s32);
    s16 func_80145928(u8 *, f32, s32);
    f32 func_80149724(f32, f32, s32);
    s32 func_801793DC(s32, u8, u8, u8);
    void func_8010E6AC(void);
    void func_8014D4D0(void);
    s32 func_8014D5E0(void);
    void func_8011C810(void);
    void func_801C0A2C(s32, s32);
    s32 func_801C0B00(s32);
    void func_8011CD50(s32);
    void func_80132C04(void);
    void func_80132DA8(void);
    void func_8011F9F4(void);
    void func_8011FF40(s32);
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    s32 row = 1;
    s32 rowHeight = 0x12;
    s32 i;
    s32 j;
    u32 alpha;
    s32 cursor;
    s16 width;
    s16 time;
    f32 pulse;
    f32 scale;
    u8 timeText[32];

    D_801EAB24 = 6;
    func_8013FBC0(D_801EAAEC, 0x1C);
    D_801EAA55[D_801EAB24 * 28] = 2;
    func_8012643C();
    D_801E7584 = 0;
    if (D_801E747C == 0) {
        /* First frame: clear the row text, create the title and list recorded levels. */
        func_80155A44((s32 *)D_801010DC);
        D_801F7E04 = 0;
        D_801F7E08 = 0;
        func_8014D548();
        for (i = 0; i < 14; i++) {
            for (j = 2; j >= 0; j--) {
                D_801F7E0C[i][j] = 0;
            }
        }
        D_801F7E90 = (s32)func_801469E4(0xA0, (s16)((row << 1) * rowHeight), 0xFF, 0xFF, 0xFF, 0xFF, D_801010F8, D_801010F8, 0, D_801EADC8[D_801E7586], 1);
        D_801E75B4 = 0;
        D_801E75B0 = 0x3E7;
        D_801F7F74 = 0;
        for (j = 0; j < 0x30; j++) {
            if (func_8012ABFC(j) != 0 && func_8012AC54(j) != 0) {
                if (D_801F7F74 == 0) {
                    D_801F7F78 = j;
                }
                D_801F7EB4[D_801F7F74++] = j;
            }
        }
        func_80145680(1);
        {
            s16 *language = &D_801E7586;
            scale = D_801010FC;
            width = ((s16 (*)(u8 *, f32, f32))func_80145928)((u8 *)D_801EAE70[*language], scale, scale);
            D_801F7E9C = (s32)func_801469E4((s16)(0x104 - width / 2), 0xCA, 0xFF, 0xFF, 0xFF, 0xFF, scale, scale, 0, D_801EAE70[*language], 0);
            if (D_801F7F74 != 0) {
                D_801F7EA8 = (s32)func_801469E4(0x28, 0xCA, 0xFF, 0xFF, 0xFF, 0xFF, scale, scale, 0, D_801EAE70[*language + 9], 0);
            }
        }
        func_80145680(0);
        func_80155AE4(D_801010DC);
    }
    func_80125040();
    D_801E747C++;
    if (D_801E75B0 != D_801E75AC) {
        /* The cursor moved: free last frame's row text. */
        for (i = 0; i < 11; i++) {
            for (j = 0; j < 3; j++) {
                func_80145CEC(D_801F7E0C[i][j]);
            }
        }
    }
    func_80145680(1);
    row = 0;
    if (D_801F7F74 - 7 >= D_801E75AC - 3) {
        i = D_801E75AC - 3;
    } else {
        i = D_801F7F74 - 7;
    }
    for (; i < D_801F7F74 && row < 7; i++) {
        if (i >= 0 && i < 0x30) {
            row++;
            /* Odd rows white, even rows yellow (blue component 0 or 0xFF). */
            j = (row & 1) ? 0 : -1;
            func_801D2150(D_802846F8, D_801010E8, D_801EAEAC[(D_801F7EB4[i] - 10) / 5][D_801E7586], (D_801F7EB4[i] - 10) % 5 + 1);
            time = D_801E6790[D_801E693C[D_801F7EB4[i]][0]].time;
            func_801D2150(timeText, D_801010F0, (s16)(time / 60), (s16)(time % 60));
            if (i == D_801E75AC) {
                if (D_801F7E08 != 0) {
                    D_801F7E0C[row - 1][0] = (s32)func_801469E4(0x28, (s16)(row * rowHeight + 0x2A), 0xFF, 0xFF, 0xFF, (D_801E747C * 40) & 0xFF, D_80101100, D_80101104, 1, D_801EAE70[D_801E7586 + 9], 0);
                    D_801F7E0C[row - 1][1] = (s32)func_801469E4(0xAA, (s16)(row * rowHeight + 0x2A), 0xFF, 0xFF, 0xFF, (D_801E747C * 40) & 0xFF, D_80101100, D_80101104, 1, D_801EAE70[D_801E7586], 0);
                } else {
                    D_801F7E0C[row - 1][0] = (s32)func_801469E4(0x28, (s16)(row * rowHeight + 0x2A), 0xFF, 0xFF, (u8)j, (D_801E747C * 40) & 0xFF, D_80101100, D_80101104, 1, (s32)D_802846F8, 0);
                    D_801F7E0C[row - 1][1] = (s32)func_801469E4(0xAA, (s16)(row * rowHeight + 0x2A), 0xFF, 0xFF, (u8)j, (D_801E747C * 40) & 0xFF, D_80101100, D_80101104, 1, (s32)timeText, 0);
                    D_801F7E0C[row - 1][2] = (s32)func_801469E4(0xFA, (s16)(row * rowHeight + 0x2A), 0xFF, 0xFF, (u8)j, (D_801E747C * 40) & 0xFF, D_80101100, D_80101104, 1, (s32)D_801E6790[D_801E693C[D_801F7EB4[i]][0]].name, 0);
                }
            } else if (D_801E75B0 != D_801E75AC) {
                s16 y = row * rowHeight + 0x2D;
                D_801F7E0C[row - 1][0] = (s32)func_801469E4(0x28, y, 0xFF, 0xFF, (u8)j, 0xFF, D_80101100, D_80101100, 0, (s32)D_802846F8, 0);
                D_801F7E0C[row - 1][1] = (s32)func_801469E4(0xAA, y, 0xFF, 0xFF, (u8)j, 0xFF, D_80101100, D_80101100, 0, (s32)timeText, 0);
                D_801F7E0C[row - 1][2] = (s32)func_801469E4(0xFA, y, 0xFF, 0xFF, (u8)j, 0xFF, D_80101100, D_80101100, 0, (s32)D_801E6790[D_801E693C[D_801F7EB4[i]][0]].name, 0);
            }
        }
    }
    func_80145680(0);
    if (D_801F7F74 == 0) {
        /* No records yet: show a pulsing message in the current language. */
        switch (D_801E7586) {
        case 0:
            pulse = func_80149724(D_80101108, (f32)D_801E747C, 0) * D_8010110C + D_80101110;
            if (!(pulse >= D_80101114)) {
                alpha = (s32)pulse;
            } else {
                alpha = (s32)(pulse - D_80101114);
                alpha |= 0x80000000;
            }
            func_801469E4(0xA0, 0x64, 0xFF, 0xFF, 0xFF, alpha & 0xFF, D_80101118, D_80101118, 1, D_801EADA4[D_801E7586], 1);
            break;
        case 1:
            pulse = func_80149724(D_8010111C, (f32)D_801E747C, 0) * D_80101120 + D_80101124;
            if (!(pulse >= D_80101128)) {
                alpha = (s32)pulse;
            } else {
                alpha = (s32)(pulse - D_80101128);
                alpha |= 0x80000000;
            }
            func_801469E4(0xA0, 0x64, 0xFF, 0xFF, 0xFF, alpha & 0xFF, D_8010113C, D_8010113C, 1, D_801EADA4[D_801E7586], 1);
            break;
        case 2:
            pulse = func_80149724(D_8010112C, (f32)D_801E747C, 0) * D_80101130 + D_80101134;
            if (!(pulse >= D_80101138)) {
                alpha = (s32)pulse;
            } else {
                alpha = (s32)(pulse - D_80101138);
                alpha |= 0x80000000;
            }
            func_801469E4(0xA0, 0x64, 0xFF, 0xFF, 0xFF, alpha & 0xFF, D_8010113C, D_8010113C, 1, D_801EADA4[D_801E7586], 1);
            break;
        }
    }
    D_801E75B0 = D_801E75AC;
    if (D_801E75B4 != 0) {
        D_801E75B4--;
    } else if (D_801F7E08 == 0) {
        /* Stick up / down moves the cursor, with a three-frame repeat delay. */
        if (D_801FAA92[D_80202218].f >= 0x33) {
            if (D_801E75AC > 0) {
                func_801793DC(0xD4, 0x64, 0x80, 0x80);
                D_801E75AC--;
            }
            D_801E75B4 = 3;
        }
        if (D_801FAA92[D_80202218].f < -0x32) {
            if (D_801E75AC < D_801F7F74 - 1) {
                func_801793DC(0xD4, 0x64, 0x80, 0x80);
                D_801E75AC++;
            }
            D_801E75B4 = 3;
        }
    }
    func_8010E6AC();
    if (D_801F7F74 - 1 > ((D_801E75AC > 0) ? D_801E75AC : 0)) {
        cursor = (D_801E75AC > 0) ? D_801E75AC : 0;
    } else {
        cursor = D_801F7F74 - 1;
    }
    D_801E75AC = cursor;
    if (D_801E75B4 == 0) {
        /* First press asks to reset the record; the second restores its default. */
        if (D_801FAAC8[D_80202218].f != 0 && D_801F7F74 != 0) {
            if (D_801F7E08 == 0) {
                func_801793DC(0xD8, 0x64, 0x80, 0x80);
                D_801F7E08 = 1;
            } else {
                func_801793DC(0xD8, 0x64, 0x80, 0x80);
                D_801E6790[D_801E693C[D_801F7EB4[D_801E75AC]][0]] = D_801E6850[D_801E693C[D_801F7EB4[D_801E75AC]][0]];
                D_801F7E04 = 1;
                D_801F7E08 = 0;
            }
        }
        if (D_801FAAC6[D_80202218].f != 0 && D_801F7F74 != 0) {
            /* Confirm: fade out and start the level. */
            func_801793DC(0xD8, 0x64, 0x80, 0x80);
            D_801EC7D2 = 1;
            func_8014D4D0();
            D_801E75B4 = 200;
        } else if (D_801FAAC7[D_80202218 * 400] != 0 || (D_801FAAC6[D_80202218].f != 0 && D_801F7F74 == 0)) {
            /* Back: cancel the reset prompt, or fade out to the menu. */
            func_801793DC(0xD9, 0x64, 0x80, 0x80);
            if (D_801F7E08 != 0) {
                D_801F7E08 = 0;
            } else {
                D_801EC7D2 = 1;
                func_8014D4D0();
                D_801E75B4 = -200;
            }
        }
    }
    if (func_8014D5E0() != 0) {
        func_80155A44((s32 *)D_801010DC);
        D_8028FAF4 = 0;
        func_8011C810();
        D_801E747C = 0;
        D_80201004 = 0;
        D_802004E0 = 0;
        D_801ED402 = 0;
        D_801ED401 = 0;
        D_801ED400 = 0;
        D_801E753C = 0x12C;
        func_801C0A2C(1, 1);
        do {
        } while (func_801C0B00(1) != 0);
        func_8011CD50(1);
        if (D_801F7E04 != 0) {
            /* A record was reset: save the time records. */
            func_80132C04();
            func_80132DA8();
        }
        if (D_801E75B4 > 0) {
            typedef struct { s8 mode; s8 level; } GameMode;
            func_8011F9F4();
            func_80155A44((s32 *)D_801010DC);
            ((GameMode *)&D_801E7530)->mode = 4;
            D_801EFD00 = -1;
            func_8011FF40(D_801F7EB4[D_801E75AC]);
        } else {
            D_801E7530 = 1;
            D_801E58B4 = 1;
            D_801E58A8 = 0;
        }
    }
}

void func_8011F9F4(void) {
    extern f32 D_8028FB24;
    extern u8 *D_8028FAC8;
    extern s32 D_80290194;
    extern s32 D_80290188;
    extern u8 D_801E753B;
    s32 progressIndex = NEW_GAME_PROGRESS_FLAG_LAST;
    u8 *progressFlag = &D_801E753B;
    s32 saveOffset;
    u8 difficultyOrLives;
    f32 zero;
    f32 cameraResetValue;

    /* Reset new-game progress and player stats, preserving volumes and using the selected difficulty's lives. */
    D_801EFD00 = -1;
    D_80299398 = 0;
    zero = 0.0f;
    D_801EFCE0 = zero;
    D_801EFCDC = zero;
    D_801EFCD8 = zero;
    D_801EAA5C[D_801EAB24 * SAVE_SLOT_HALFWORDS] = D_801E65C0;
    D_801EAA5E[D_801EAB24 * SAVE_SLOT_HALFWORDS] = D_801E65C4;
    for (; progressIndex >= 0; progressIndex--, progressFlag--) {
        *progressFlag = 0;
    }
    saveOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
    D_801EAA56[saveOffset] = 0;
    *(&D_801EAA57 + D_801EAB24 * LEVEL_SAVE_SLOT_BYTES) = 0;
    *(s32 *)&D_801EAA48[saveOffset] = 0;
    D_801E7534 = 0;
    D_801E7533 = 0;
    D_801E7584 = 0;
    D_8028FBF8 = 0;
    func_8013FBC0((u8 *)&D_80290188, SAVE_RUNTIME_BYTES);
    saveOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
    difficultyOrLives = D_801EAA55[saveOffset];
    cameraResetValue = D_80101140;
    difficultyOrLives = D_801E7500[difficultyOrLives * GARIB_DIFFICULTY_SETTINGS_BYTES];
    D_80290190 = difficultyOrLives;
    *(&D_801EAA54 + saveOffset) = difficultyOrLives;
    D_80290194 = GARIB_MAX_HEALTH;
    D_802901E0 = SAVE_RUNTIME_UNK58_INITIAL;
    D_8028FAC8 = (u8 *)&D_8029030C;
    D_8028FB24 = cameraResetValue;
}

void func_8011FB8C(void)
{
  extern f32 D_8028FB24;
  extern u8 *D_8028FAC8;
  extern s32 D_80290188;
  extern u8 D_801E7536[];
  s32 saveOffset;
  extern f32 D_80101144;
  extern u8 D_801FA9A8;
  s32 world;
  s32 *playerStats;
  s32 completionOffset;
  u32 savedLives;
  s32 slotOrLives;

  /* Restore the selected save's progress, volumes, lives, score and initials, resetting runtime state. */
  D_80299398 = 0;
  D_801E65C0 = D_801EAA5C[D_801EAB24 * SAVE_SLOT_HALFWORDS];
  D_801E65C4 = D_801EAA5E[D_801EAB24 * SAVE_SLOT_HALFWORDS];
  for (world = 1; world < SAVE_WORLD_COUNT + 1; world++)
  {
    completionOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
    if (((*((s32 *) (&D_801EAA48[completionOffset]))) >> ((world * SAVE_WORLD_BITS) - SAVE_WORLD_COMPLETION_SHIFT_BIAS)) & 1)
    {
      D_801E7536[world - 1] = 1;
    }
    else
    {
      D_801E7536[world - 1] = 0;
    }
  }

  if (completionOffset)
  {
    playerStats = &D_80290188;
    D_801E7534 = 0;
    D_801E7533 = 0;
    D_801E7531 = *((&D_801EAA57) + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES));
    D_801E7584 = 0;
    D_801EFD00 = -1;
    D_8028FBF8 = 0;
    func_8013FBC0((u8 *) playerStats, SAVE_RUNTIME_BYTES);
    slotOrLives = D_801EAB24;
    saveOffset = LEVEL_SAVE_SLOT_BYTES * slotOrLives;
    savedLives = *((&D_801EAA54) + saveOffset);
    slotOrLives = SAVE_MINIMUM_LIVES;
  }
  else
  {
    playerStats = &D_80290188;
    D_801E7534 = 0;
    D_801E7533 = 0;
    D_801E7531 = *((&D_801EAA57) + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES));
    D_801E7584 = 0;
    D_801EFD00 = -1;
    D_8028FBF8 = 0;
    func_8013FBC0((u8 *) playerStats, SAVE_RUNTIME_BYTES);
    slotOrLives = D_801EAB24;
    saveOffset = slotOrLives * LEVEL_SAVE_SLOT_BYTES;
    savedLives = *((&D_801EAA54) + saveOffset);
    slotOrLives = SAVE_MINIMUM_LIVES;
  }
  if (savedLives >= SAVE_MINIMUM_LIVES)
  {
    slotOrLives = savedLives;
  }
  playerStats[SAVE_RUNTIME_HEALTH_WORD] = GARIB_MAX_HEALTH;
  playerStats[SAVE_RUNTIME_LIVES_WORD] = slotOrLives;
  playerStats[SAVE_RUNTIME_UNK58_WORD] = SAVE_RUNTIME_UNK58_INITIAL;
  ((ScalarS32 *)playerStats)->value = *((s32 *) (((u8 *) (&D_801EAA50)) + saveOffset));
  D_8028FAC8 = (u8 *) (&D_8029030C);
  D_8028FB24 = D_80101144;
  D_801FA9A8 = *((&D_801EAA44) + saveOffset);
  D_801FA9A9 = *((&D_801EAA45) + saveOffset);
  D_801FA9AA = *((&D_801EAA46) + saveOffset);
}

/* Reset the player idle timer (D_8028FBF8) and clear the active power-up (D_802901E0). */
void func_8011FD64(void) {
    D_8028FBF8 = 0;
    D_802901E0 = SAVE_RUNTIME_UNK58_INITIAL;
}

/* Reset every scene subsystem's object/sprite/render list (called when a scene's resources are released). */
void func_8011FD80(void) {
    func_8014A9D8(); /* sprite-list sentinel A */
    func_80188F90();
    func_80188FB4();
    func_801A6820();
    func_8014ABEC(); /* sprite-list sentinel B */
    func_8015C758(); /* render lists */
    func_801A8E30();
    func_801B4010();
    func_8018A9D0();
    func_80179EAC();
    func_801B9140();
    func_80179EAC();
    func_8018E6F8();
    func_8018E5F0();
    func_8018B3D8();
    func_8012ACC0();
    func_8018B3B8();
    func_801BAF6C();
    func_801B87C4();
    func_801B7B40();
    func_801779F0();
    func_8014A9FC(); /* sprite list */
}

/* Reset every scene subsystem's object/sprite/render list, like func_8011FD80
 * but keeping the main sprite list (no func_8014A9FC at the end). */
void func_8011FE48(void) {
    func_8014A9D8(); /* sprite-list sentinel A */
    func_80188F90();
    func_80188FB4();
    func_801A6820();
    func_8014ABEC(); /* sprite-list sentinel B */
    func_8015C758(); /* render lists */
    func_801A8E30();
    func_801B4010();
    func_8018A9D0();
    func_80179EAC();
    func_801B9140();
    func_80179EAC();
    func_8018E6F8();
    func_8018E5F0();
    func_8018B3D8();
    func_8012ACC0();
    func_8018B3B8();
    func_801BAF6C();
    func_801B87C4();
    func_801B7B40();
    func_801779F0();
}

/* Frees a screen sprite: unlinks it from the sprite list (func_8014AAB8, which
 * also frees the handle at +0x24) and frees the allocation handles at +0x5C
 * and +0x24 (func_80141720 skips empty handles). */
void func_8011FF08(s32 sprite) {
    func_8014AAB8();
    func_80141720((s32 *)(sprite + 0x5C));
    func_80141720((s32 *)(sprite + 0x24));
}

void func_8011FF40(s32 level) {
    /* Starts a level: resets timers, camera and the per-level managers, loads the level's data,
       places already-collected markers (level 0x2A), sets up the HUD sprites and their colours
       for the current world, the fog, weather effects, and marks the level visited in the save. */
    extern u8 D_80101148[];
    extern u8 D_80101154[];
    extern u8 D_8010115C[];
    extern u8 D_8010116C[];
    extern u8 D_8010117C[];
    extern u8 D_80101188[];
    extern u8 D_80101194[];
    extern u8 D_801011A4[];
    extern u8 D_801011B4[];
    extern const f32 D_801011B8;
    extern const f32 D_801011BC;
    extern const f32 D_801011C0;
    extern const f32 D_801011C4;
    extern const f32 D_801011C8;
    extern const f32 D_80101240;
    extern s32 D_801ED670;
    extern s16 D_801E7464;
    extern s32 D_801EFDC0;
    extern s16 D_801E7620;
    extern s16 D_801E7460;
    extern s32 D_801EC7CC;
    extern f32 D_801ED680;
    extern u8 *D_8028FAC8;
    extern s32 D_801E6940[][14];
    extern s32 D_801E693C[][14];
    extern s32 D_801EF480;
    extern s32 D_801EF484;
    extern s32 D_801EC768;
    extern u8 *D_801FB260;
    extern s32 D_801ED3C4;
    extern f32 D_802978EC;
    extern f32 D_802978F4;
    extern f32 D_802978F8;
    extern f32 D_802978FC;
    extern u8 D_8028DA60, D_8028DA61, D_8028DA62;
    extern u8 D_8028DAD4, D_8028DAD5, D_8028DAD6;
    extern u8 D_8028DB48, D_8028DB49, D_8028DB4A;
    extern u8 D_8028DBBC, D_8028DBBD, D_8028DBBE;
    extern u8 D_8028DC30, D_8028DC31, D_8028DC32;
    extern u8 D_8028F3F3[];
    extern u8 *D_80289390;
    extern u8 D_801F1BE4[];
    extern s32 D_80284DC4[][6];
    extern s32 D_80284DCC[][6];
    extern u8 D_80284DE3;
    extern u8 D_80284E13;
    extern s32 D_80284DEC;
    extern s32 D_80284E1C;
    extern s32 D_80284DD4;
    extern s32 D_80290198;
    extern s8 D_801E7530;
    extern u8 D_801EAA58[];
    void func_8014707C(void);
    void func_80155A44(s32 *);
    void func_80145E30(void);
    s32 func_801526C4(s32);
    void func_80141874(void);
    void func_8011D88C(s32);
    void *func_8017DBA0(s32);
    s32 func_80128D34(void);
    void func_8014E760(void);
    void func_8014A460(Obj8014A460 *, u8 *, s32, s32, s32, s32);
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    void func_801BB554();
    void func_80178A58(s32, s32, s32);
    void func_8014D548(void);
    s8 *levelId;
    s8 *gameMode;
    s32 i;
    s32 hudOffset;
    s32 saveOffset;
    s32 saveSlot;
    s32 visitedSave;
    s32 bit;
    s32 collected;
    s32 fogValue;

    if (level == 0x27) {
        D_801EC7F0 = 2;
    }
    D_801ED670 = 0;
    saveOffset = D_801EAB24 * 0x1C;
    if (D_801EAA55[saveOffset] == 0) {
        D_80297BEC |= 1;
    }
    if (D_801EAA55[saveOffset] == 0 || *(&D_801EAA57 + saveOffset) == 7) {
        D_801E7464 = 1;
    } else {
        D_801E7464 = 0;
    }
    D_801EFDC0 = (level == 0x22) ? 0xF : 0x14;
    D_8028F814 = 0;
    D_801E7620 = 0;
    D_801E7460 = 0;
    func_8014707C();
    D_8028FAC8 = (u8 *)&D_8029030C;
    D_80201004 = 0;
    D_802004E0 = 0;
    D_801EC7CC = 0;
    D_801ED680 = D_801011B8;
    func_80155A44((s32 *)D_80101148);
    func_80145E30();
    func_8014A9D8();
    func_80188F90();
    func_80188FB4();
    func_801A6820();
    func_8014ABEC();
    func_8015C758();
    func_801A8E30();
    func_801B4010();
    func_8018A9D0();
    func_80179EAC();
    func_801B9140();
    func_80179EAC();
    func_8018E6F8();
    func_8018E5F0();
    func_8018B3D8();
    func_8012ACC0();
    func_8018B3B8();
    func_801BAF6C();
    func_801B87C4();
    func_801B7B40();
    func_801779F0();
    func_8014A9FC();
    D_801EF480 = D_801E6940[level][0];
    if (D_801EC7F0 == 1) {
        D_801EC768 = (s32)func_8013FCDC(0x2800, 0, (s32 *)D_80101154);
        D_801FB260 = (u8 *)D_801EC768 + 4;
    } else if (D_801EC7F0 == 2) {
        D_801EC768 = func_801526C4(level);
    }
    *(Vec3F *)D_802978E8 = *(Vec3F *)&D_801ED3C4;
    D_801EC7EA = 2;
    D_802978EC = D_801011BC;
    D_802978F4 = D_801011C0;
    D_802978F8 = D_801011C0;
    D_802978FC = D_801011C0;
    func_80141874();
    D_8028FBF8 = 0;
    D_802901E0 = 0xF;
    func_8011D88C(level);
    if (level == 0x2A) {
        for (i = 1; i < 4; i++) {
            if (!(D_80297BEC & 0x2000000)) {
                saveSlot = D_801EAB24 * 0x1C;
                bit = (D_801E7533 - 1) * 5 + i;
                collected = *(s32 *)(D_801EAA48 + saveSlot);
                if (!((collected >> (bit - 1)) & 1) && !((collected >> bit) & 1)) {
                    continue;
                }
            }
            *(f32 *)((u8 *)func_8017DBA0(i) + 0xB8) = D_801011C4;
        }
        if (func_80128D34() != 0) {
            *(f32 *)((u8 *)func_8017DBA0(4) + 0xB8) = D_801011C8;
        }
    }
    D_801E753C = 0x12C;
    D_801E7584 &= 0xFC;
    func_8014E760();
    D_802AAFDC = 0;
    func_8014A460((Obj8014A460 *)D_8028F5A0, D_8010115C, 0x28, 0xD2, 1, 0);
    func_8014A460((Obj8014A460 *)D_8028F618, D_8010116C, 0x28, 0xD2, 1, 0);
    D_801EF484 = (D_801E7531 == 0x18 || D_801E7531 == 8 || D_801E7531 == 0x1D || D_801E7531 == 9 || D_801E7531 == 0x2A);
    if (D_801E7531 == 0x28 || D_801E7531 == 0xD || D_801E7531 == 0x12 || D_801E7531 == 0x17 || D_801E7531 == 0x1C) {
        func_8014A460((Obj8014A460 *)D_8028DA40, D_8010117C, 0x78, 0x20, 1, 1);
        func_8014A460((Obj8014A460 *)(D_8028DA40 + 0x74), D_8010117C, 0x78, 0x20, 1, 1);
        func_8014A460((Obj8014A460 *)(D_8028DA40 + 0xE8), D_8010117C, 0x78, 0x20, 1, 1);
        func_8014A460((Obj8014A460 *)(D_8028DA40 + 0x15C), D_8010117C, 0x78, 0x20, 1, 1);
        func_8014A460((Obj8014A460 *)(D_8028DA40 + 0x1D0), D_8010117C, 0x78, 0x20, 1, 1);
        switch (D_801E7531) {
        case 0xD:
            D_8028DB48 = 0x56;
            D_8028DBBC = 0x56;
            D_8028DC30 = 0x56;
            D_8028DB49 = 0xA7;
            D_8028DBBD = 0xA7;
            D_8028DC31 = 0xA7;
            D_8028DB4A = 0xDD;
            D_8028DBBE = 0xDD;
            D_8028DC32 = 0xDD;
            D_8028DAD4 = 0xE3;
            D_8028DAD5 = 0x2B;
            D_8028DAD6 = 0x2B;
            D_8028DA60 = 0xFF;
            D_8028DA61 = 0x6F;
            D_8028DA62 = 0;
            break;
        case 0x17:
            D_8028DB48 = 0xCC;
            D_8028DAD4 = 0xCC;
            D_8028DA60 = 0xCC;
            D_8028DB49 = 0x60;
            D_8028DAD5 = 0x60;
            D_8028DA61 = 0x60;
            D_8028DB4A = 0;
            D_8028DAD6 = 0;
            D_8028DA62 = 0;
            break;
        case 0x1C:
            D_8028DB49 = 0x60;
            D_8028DAD5 = 0x60;
            D_8028DA61 = 0x60;
            D_8028DB48 = 0;
            D_8028DAD4 = 0;
            D_8028DA60 = 0;
            D_8028DB4A = 0xC8;
            D_8028DAD6 = 0xC8;
            D_8028DA62 = 0xC8;
            break;
        case 0x28:
            D_8028DA60 = 0x98;
            D_8028DA61 = 0;
            D_8028DA62 = 0xA4;
            D_8028DAD4 = 0xFF;
            D_8028DAD5 = 0x8B;
            D_8028DAD6 = 7;
            D_8028DB48 = 0xFF;
            D_8028DB49 = 0x8B;
            D_8028DB4A = 7;
            break;
        case 0x12:
            D_8028DA60 = 0xFF;
            D_8028DA61 = 0;
            D_8028DA62 = 0;
            D_8028DAD4 = 0;
            D_8028DAD5 = 0xFF;
            D_8028DAD6 = 0;
            D_8028DB48 = 0;
            D_8028DB49 = 0;
            D_8028DB4A = 0xFF;
            break;
        }
    } else {
        for (i = 0; i < 4; i++) {
            hudOffset = i * 0x74;
            func_8014A460((Obj8014A460 *)(D_8028F3D0 + hudOffset), D_80101188, (i % 2) * 0x104 + 0x22, (i / 2) * 0x50 + 0x50, 1, 1);
            D_8028F3F3[hudOffset] = 0xB4;
        }
    }
    func_8014A460((Obj8014A460 *)D_8028F708, D_80101194, 0x10E, 0xD2, 1, 0);
    func_8014A460((Obj8014A460 *)D_80289320, D_801011A4, 0x23, 0x1B, 5, 0);
    D_80289390 = D_801F1BE4;
    for (i = 0; i < 9; i++) {
        D_80284DC4[i][0] = 0x400;
        D_80284DCC[i][0] = 0xFF;
    }
    D_80284DEC = (s32)func_801469E4(0xB4, 0x12, 0xFF, 0xFF, 0xFF, D_80284DE3, D_80101240, D_80101240, 0, (s32)D_801011B4, 0);
    D_80284E1C = (s32)func_801469E4(0xDC, 0xC7, 0xFF, 0xFF, 0xFF, D_80284E13, D_80101240, D_80101240, 0, (s32)D_801011B4, 0);
    D_80284DD4 = (s32)func_801469E4(0x36, 0x12, 0xFF, 0xFF, 0xFF, 0xFF, D_80101240, D_80101240, 0, (s32)D_801011B4, 0);
    gameMode = &D_801E7530;
    D_80290198 = 0;
    if (*gameMode != 0xD) {
        if (D_801E7531 < 0x2E) {
            *gameMode = 4;
            fogValue = 0x2D;
        } else {
            *gameMode = 5;
            fogValue = 0x23;
        }
        D_801EC7E0 = fogValue;
        D_801EC7DE = fogValue;
    }
    levelId = &D_801E7531;
    if (*levelId == 0x19 || *levelId == 0x1C) {
        func_801BB554(3, 0x40, 1, 0xDC, 0x96, 0x50, 0, -8, 0x64, -1);
    }
    if (*levelId == 0x1E || *levelId == 0x20) {
        func_801BB554(2, 0x40, 5, 0x78, 0x50, 0x3C, -8, -0x1E, 7, -1);
        func_80178A58(0xF6, 0x46, 0x80);
    }
    visitedSave = D_801EAB24 * 0x1C;
    *(s32 *)(D_801EAA58 + visitedSave) |= 1 << D_801E693C[level][0];
    func_8014D548();
}

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

/* Initialize the fade plane and star with a shared white texture and fixed transforms. */
void func_80120A90(void) {
    u8 *fadePlane = D_8028D7E8;
    s32 *textureImageSlot = (s32 *)&D_80297934;
    f32 initialDepth = D_80101264;
    f32 zero = 0.0f;
    f32 quarterTurn;
    f32 planeScale, planePitch;
    f32 *planePitchSlot;
    s16 opacity;
    s16 triangleIndex;

    *textureImageSlot = (s32)D_801E7480;
    D_80297926 = FADE_TEXTURE_DIMENSION;
    D_80297924 = FADE_TEXTURE_DIMENSION;
    D_80297928 = FADE_TEXTURE_LOG2_DIMENSION;
    D_8029792A = FADE_TEXTURE_LOG2_DIMENSION;
    D_80297932 = FADE_TEXTURE_SIZE_16B;
    D_80297930 = FADE_TEXTURE_FORMAT_RGBA;
    func_80142928(fadePlane, (s32)D_80101244, zero, zero, initialDepth, 0);
    planeScale = D_80101268;
    planePitch = D_8010126C;
    quarterTurn = D_80101270;
    D_8028D864 = zero;
    D_8028D868 = quarterTurn;
    D_8028D8A4 = planeScale;
    D_8028D8A8 = planeScale;
    D_8028D8AC = planeScale;
    planePitchSlot = (f32 *)(fadePlane + MENU_OBJECT_ROTATION_X_OFFSET);
    *planePitchSlot = planePitch;
    *(u16 *)(*(u8 **)(D_8028D8B0 + MENU_MODEL_ROOT_OFFSET) + MENU_MODEL_NODE_FLAGS_OFFSET) |= MENU_MODEL_NODE_ALPHA_FLAG;
    opacity = FADE_INITIAL_OPACITY;
    D_8028D80E = opacity;
    **(s32 **)(*(u8 **)(*(u8 **)(((ObjectDataPointer *)&D_8028D8B0)->data + MENU_MODEL_ROOT_OFFSET) + FADE_MODEL_MESH_OFFSET) + FADE_MESH_TEXTURES_OFFSET) = (s32)(textureImageSlot - FADE_TEXTURE_IMAGE_WORD_OFFSET);
    func_8015C350(fadePlane + MENU_OBJECT_QUATERNION_OFFSET, fadePlane + MENU_OBJECT_ROTATION_X_OFFSET);
    func_80142928(D_8028D8D8, (s32)D_80101254, zero, zero, initialDepth, 0);
    D_8028D950 = quarterTurn;
    D_8028D954 = zero;
    D_8028D958 = zero;
    D_8028D90C = zero;
    D_8028D910 = zero;
    D_8028D994 = D_80101274;
    D_8028D998 = D_80101274;
    D_8028D99C = D_80101274;
    D_8028D914 = D_80101278;
    *(u16 *)(*(u8 **)(D_8028D9A0[0] + MENU_MODEL_ROOT_OFFSET) + MENU_MODEL_NODE_FLAGS_OFFSET) |= MENU_MODEL_NODE_ALPHA_FLAG;
    D_8028D8FE = opacity;
    for (triangleIndex = 0; triangleIndex < *(s16 *)*(u8 **)(*(u8 **)(D_8028D9A0[0] + MENU_MODEL_ROOT_OFFSET) + FADE_MODEL_MESH_OFFSET); triangleIndex++) {
        ((s32 *)*(u8 **)(*(u8 **)(*(u8 **)(D_8028D9A0[0] + MENU_MODEL_ROOT_OFFSET) + FADE_MODEL_MESH_OFFSET) + FADE_MESH_TEXTURES_OFFSET))[triangleIndex] = (s32)(textureImageSlot - FADE_TEXTURE_IMAGE_WORD_OFFSET);
    }
    func_8015C350(D_8028D974, D_8028D974 - FADE_QUATERNION_TO_EULER_OFFSET);
}

extern s16 D_801F91A8;
void func_80120D18(void) /* Level-results screen, one frame: set up on frame 0, slide the text slots in, count Garibs into the score, leave on a press or timeout. */
{
  extern void * volatile D_80269F58;
  extern void * volatile D_80269F5C;
  struct BounceEnt
  {
    f32 pos;
    f32 y;
    f32 vel;
    s32 unkC;
    f32 limit;
    void *obj;
    s16 delay;
    s16 active;
    s32 dir;
  };
  extern s32 D_801010F0;
  extern s32 D_8010127C[];
  extern s32 D_80101288;
  extern s32 D_80101294;
  extern s32 D_801012A4;
  extern s32 D_801012B0;
  extern s32 D_801012C0;
  extern s32 D_801012D0;
  extern s32 D_801012D8;
  extern s32 D_801012DC;
  extern s32 D_801012E4;
  extern f32 D_801012E8;
  extern f32 D_801012EC;
  extern f32 D_801012F0;
  extern f32 D_801012F4;
  extern f32 D_801012F8;
  extern f32 D_801012FC;
  extern f32 D_80101300;
  extern f32 D_80101304;
  extern f32 D_80101308;
  extern f32 D_8010130C;
  extern f32 D_80101310;
  extern f32 D_80101314;
  extern f32 D_80101318;
  extern f32 D_8010131C;
  extern f32 D_80101320;
  extern f32 D_80101324;
  extern f32 D_80101328;
  extern f32 D_8010132C;
  extern const f32 D_80101330[];
  extern const f32 D_80101338[];
  extern const f32 D_80101340[];
  extern f32 D_8010134C;
  extern f32 D_80101350;
  extern f32 D_80101354;
  extern f32 D_80101358;
  extern f32 D_8010135C;
  extern f64 D_80101360;
  extern f32 D_80101368;
  extern f32 D_8010136C;
  extern const f64 D_80101370;
  extern const f64 D_80101378;
  extern const f32 D_80101380;
  extern f32 D_80101384;
  extern const f64 D_80101388;
  extern const f64 D_80101390;
  extern const f32 D_80101398;
  extern const f32 D_8010139C;
  extern const f32 D_801013A0;
  extern const f32 D_801013A4;
  extern const f32 D_801013A8;
  extern const f32 D_801013AC;
  extern const f32 D_801013B0;
  extern const f32 D_801013B4;
  extern const f32 D_801013B8;
  extern struct Col D_801E6790[];
  extern s32 D_801E693C[][14];
  extern s32 D_801E7398;
  extern s32 D_801E746C;
  extern s16 D_801E75B8;
  extern s16 D_801E75BA;
  extern s16 D_801E75BC;
  extern s16 D_801E75BE;
  extern s16 D_801E75C0;
  extern s16 D_801E75C2;
  extern u8 D_801E75C4;
  extern u8 D_801EFC92;
  extern s32 D_801F1CE4;
  extern s16 D_801F7F7C;
  extern s32 D_801F7F80;
  extern s32 D_801F7F84;
  extern struct BounceEnt D_801F90D0[];
  extern u8 D_801F9280;
  extern void *D_801F92F0;
  extern void *D_801F9368;
  extern f32 D_801F94CC;
  extern u8 D_801F94D0;
  extern void *D_801F9540;
  extern s32 D_801F9548;
  extern s32 D_801F9560;
  extern s32 D_801F9564;
  extern u8 D_801F956B;
  extern u8 D_80202218;
  extern u8 D_802846F8[];
  extern s32 D_80290188;
  extern s32 D_80299394;
  void func_8010EEF8(char *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32);
  void func_8010F94C(void);
  void func_8012643C(void);
  s32 func_8012801C(void);
  void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
  s32 func_80147000(s32);
  f32 func_80149724(f32, f32, s32);
  void func_8014A50C(void *, u8 *, s32, s32, s32, s32);
  void func_8014AA20(ObjectNode *);
  void func_8014D4D0(void);
  s32 func_8014D5E0(void);
  void func_8014E760(void);
  void func_8014E8B4(s32, s32, s32, s32);
  void func_8014ED2C(void);
  void func_8014F510(s32);
  void func_80155AE4(void *);
  s32 func_801793DC(s32, u8, u8, u8);
  void func_8018E260(s32);
  void func_801B6370(void);
  s32 direction;
  s32 delay; s32 slot5_x;
  s32 mode;
  f32 one;
  f32 tilt2;
  f32 tilt1;
  struct BounceEnt *ent;
  f32 slot6_y;
  f32 wave;
  f32 fade0;
  f32 fade1;
  f32 fade2;
  f32 text_scale;
  f32 _12;
  f32 spark_dx;
  f32 x1;
  f32 x2;
  f32 x3;
  f32 z;
  f32 y1;
  f32 y2;
  f32 y3;
  f32 y4;
  f32 pulse;
  f32 t;
  s16 seconds;
  s16 _32;
  s32 spark_y;
  s32 init_i;
  s32 k;
  s32 green;
  s32 i;
  s32 red;
  s32 blue;
  s32 alpha0;
  s32 alpha1;
  s32 alpha2;
  u8 **_45;
  u8 **_46;
  u8 **_47;
  u8 **_48;
  u8 *obj;
  u8 *node;
  u8 *_51;
  void *bg;
  if (!(D_801E7584 & 1))
  {
    func_8012643C();
    if (D_801E746C == 0)
    {
      D_801F7F84 = *((s16 *) (((u8 *) (&D_801E6790)) + ((*((s32 *) (((u8 *) (&D_801E693C)) + ((*((s8 *) (&D_801E7532))) * 0x38)))) * 6)));
      D_801F7F80 = func_8012801C();
      D_801EFC92 = 2;
      D_801F7F7C = -1;
      D_801E753C = 0x12C;
      D_801ED400 = 0;
      D_801ED402 = 0;
      D_801ED401 = 0;
      D_801ED403 = 0;
      D_801EC7DA = 0x3E8;
      *((f32 *) D_802978E8) = D_801012E8;
      mode = 0xE;
      if (D_801E7533 < 4)
      {
        mode = 1;
      }
      func_8014F510(mode);
      func_80150EA4(0x46);
      func_8014D548();
      bg = func_8013FCDC(0x70, 1, &D_8010127C);
      func_8014AA20(bg);
      func_8014FCF8(bg + 0x48, func_80139CA0(((u8 *) (&D_801E7398)) + (D_801E7533 * 0x18)), 1);
      *((u8 *) (((u8 *) bg) + 111)) = 0xFF;
      *((u8 *) (((u8 *) bg) + 110)) = 0xFF;
      *((u8 *) (((u8 *) bg) + 109)) = 0xFF;
      *((u8 *) (((u8 *) bg) + 108)) = 0xFF;
      *((s16 *) (((u8 *) bg) + 88)) = 0x400;
      *((s16 *) (((u8 *) bg) + 90)) = 0x400;
      func_801B6370();
      func_8014A50C(D_801F92F8, &D_80101288, D_801E75B8 - 0xD2, 0x3C, 2, 1);
      func_8014A50C(&D_801F9280, &D_80101294, D_801E75BC + 0xD2, 0x6E, 2, 1);
      func_8014A50C(&D_801F94D0, &D_801012A4, D_801E75C0 - 0xD2, 0xA0, 2, 1);
      D_801F9540 = &D_801F1CE4;
      D_801F9368 = ((u8 *) (&D_801F1CE4)) + 0x10;
      D_801F92F0 = ((u8 *) (&D_801F1CE4)) + 0x20;
      for (init_i = 0; init_i < 7; init_i++)
      {
        D_801F90D0[init_i].vel = 0;
        D_801F90D0[init_i].unkC = 0;
        D_801F90D0[init_i].active = 1;
      }

      x1 = D_801012EC;
      y1 = D_801012F0;
      z = D_801012F4;
      tilt1 = D_801012F8;
      one = D_801012FC;
      func_8010EEF8(&D_801012B0, x1, y1, z, 0.0f, tilt1, 0.0f, one, one, one, 0xFF);
      x2 = D_80101300;
      y2 = D_80101304;
      tilt2 = D_80101308;
      func_8010EEF8(&D_801012C0, x1, y1, z, 0.0f, tilt1, 0.0f, one, one, one, 0x80);
      func_8010EEF8(&D_801012B0, x2, y2, z, 0.0f, tilt2, 0.0f, one, one, one, 0xFF);
      x3 = D_8010130C;
      y3 = D_80101310;
      func_8010EEF8(&D_801012C0, x2, y2, z, 0.0f, tilt2, 0.0f, one, one, one, 0x80);
      y4 = D_80101314;
      func_8010EEF8(&D_801012B0, x3, y3, z, 0.0f, tilt1, 0.0f, one, one, one, 0xFF);
      func_8010EEF8(&D_801012C0, x3, y3, z, 0.0f, tilt1, 0.0f, one, one, one, 0x80);
      func_8010EEF8(&D_801012B0, 0.0f, y4, z, 0.0f, 0.0f, 0.0f, 2.0f, one, one, 0xFF);
      func_8010EEF8(&D_801012C0, 0.0f, y4, z, 0.0f, 0.0f, 0.0f, 2.0f, one, one, 0x80);
{ s32 first_x = D_801E75B8; f32 height0 = 52.0f; s32 second_x = D_801E75BA;       D_801F90D0[0].obj = D_801F92F8;
      D_801F90D0[0].delay = 1;
      D_801F90D0[1].delay = 1;
      D_801F90D0[2].obj = &D_801F9280;
      D_801F90D0[2].delay = 0xF;
      D_801F90D0[3].delay = 0xF;
      D_801F90D0[4].obj = &D_801F94D0;
      D_801F90D0[0].pos = first_x - 0xC8;
      D_801F90D0[0].y = height0;
      D_801F90D0[0].limit = first_x;
      D_801F90D0[1].pos = second_x + 0xC8;
      D_801F90D0[1].y = height0;
      D_801F90D0[1].limit = second_x;
      slot6_y = 210.0f;
      D_801F90D0[2].pos = D_801E75BC + 0xC8;
      D_801F90D0[2].y = 110.0f;
      D_801F90D0[2].limit = D_801E75BC;
      D_801F90D0[3].pos = D_801E75BE - 0xC8;
      D_801F90D0[3].y = 118.0f;
      D_801F90D0[3].limit = D_801E75BE;
      D_801F90D0[4].pos = D_801E75C0 - 0xC8;
      D_801F90D0[4].limit = D_801E75C0;
      direction = 1;
      D_801F90D0[0].dir = 0;
      D_801F90D0[1].obj = (void *) 0;
      D_801F90D0[1].dir = direction;
      D_801F90D0[2].dir = direction;
      D_801F90D0[3].obj = (void *) 0;
      D_801F90D0[3].dir = 0;
      D_801F90D0[4].y = 165.0f;
      delay = 0x1E;
      D_801F90D0[4].delay = delay;
      D_801F90D0[5].delay = delay;
      D_801F90D0[6].delay = 0x3C;
      D_801F90D0[6].obj = &D_801F9548;
      D_801F90D0[4].dir = 0;
      D_801F90D0[5].y = 158.0f;
      D_801F90D0[5].obj = (void *) 0;
      D_801F90D0[5].dir = direction;
      D_801F90D0[6].y = slot6_y;
      slot5_x = D_801E75C2;
      D_801F90D0[6].pos = 160.0f;
      D_801F9560 = 0x2000;
      D_801F9564 = 0x2000;
      D_801F956B = 0;
      D_801F90D0[5].pos = slot5_x + 0xC8;
      D_801F90D0[5].limit = slot5_x;
}
      func_8014E760();
      func_80177A14(0x3B);
      {
        s8 *fl = &D_801E7584;
        *fl &= 0xFE;
      }
      func_80155AE4(&D_801012D0);
    }
    if (D_801F7F7C > 0)
    {
      D_801F7F7C -= 1;
    }
    i = 0;
    func_8014ED2C();
    {
      f64 acc = *((const f64 *) (&D_80101330[1]));
      f64 damp = *((const f64 *) (&D_80101338[1]));
      f64 lo = *((const f64 *) (&D_80101340[1]));
      do
      {
        ent = &D_801F90D0[i];
        if (ent->active != 0)
        {
          if (ent->delay != 0)
          {
            ent->delay -= 1;
          }
          else
          {
            if (ent->dir == 0)
            {
              if (ent->vel < D_8010134C)
              {
                ent->vel += acc;
              }
              ent->pos += ent->vel;
              if (ent->limit < ent->pos)
              {
                if (ent->vel < D_80101350)
                {
                  ent->active = 0;
                  ent->pos = ent->limit;
                }
                ent->pos = ent->limit;
                ent->vel = (-ent->vel) * damp;
              }
            }
            else
            {
              if (ent->vel > D_80101354)
              {
                ent->vel -= acc;
              }
              ent->pos += ent->vel;
              if (ent->pos < ent->limit)
              {
                if (ent->vel > D_80101358)
                {
                  ent->active = 0;
                  ent->pos = ent->limit;
                }
                ent->pos = ent->limit;
                ent->vel = (-ent->vel) * damp;
              }
            }
            if (ent->obj != ((void *) 0))
            {
              *((f32 *) (((u8 *) ent->obj) + 12)) = ent->pos;
              *((f32 *) (((u8 *) ent->obj) + 16)) = ent->y;
            }
            else
            {
              t = (ent->pos - ent->limit) / D_8010135C;
              *((f32 *) (((u8 *) D_80269F40[i]) + 124)) = (*((f32 *) (((u8 *) D_80269F40[i - 1]) + 124)) = ((t < lo) || (t < D_80101360)) ? ((t < lo) ? (D_80101368) : (t)) : (D_8010136C));
            }
          }
        }
        i += 1;
      }
      while (i < 6);
    }
    i = 0;
    do
    {
      obj = D_80269F40[i];
      if ((*((f32 *) (((u8 *) obj) + 124))) <= D_80101370)
      {
        *((s16 *) (((u8 *) obj) + 38)) = 0;
      }
      else
        if (D_80101378 <= (*((f32 *) (((u8 *) obj) + 124))))
      {
        *((s16 *) (((u8 *) obj) + 38)) = 0;
      }
      else
      {
        *((s16 *) (((u8 *) obj) + 38)) = 0xFF - ((i % 2) * 0x7F);
      }
      wave = func_80149724(D_80101380, D_801E746C, (i / 2) * 60) / D_80101384;
      *((f32 *) (((u8 *) D_80269F40[i]) + 128)) = wave;
      i += 1;
 } while (i < 8); for (k = 0; k < D_801EC860; k++) { node = D_80269F40[k]; func_8015C350(node + 0x9C, node + 0x78); } { } { u8 *pa; u8 *pb; alpha0 = (*((u8 *) (((u8 *) D_801F90D0[6].obj) + 35))) * 2; pa = D_80269F58; pb = D_80269F5C; if (alpha0 >= 0x100) { alpha0 = 0xFF; } fade0 = ((f32) (alpha0 * 2)) / D_80101388; *((f32 *) (((u8 *) pb) + 188)) = fade0; *((f32 *) (((u8 *) pa) + 188)) = fade0; } { u8 *pa; u8 *pb; alpha1 = (*((u8 *) (((u8 *) D_801F90D0[6].obj) + 35))) * 2; pa = D_80269F58; pb = D_80269F5C; if (alpha1 >= 0x100) { alpha1 = 0xFF; } fade1 = ((f32) (alpha1 * D_80101390)) / D_80101388; *((f32 *) (((u8 *) pb) + 192)) = fade1; *((f32 *) (((u8 *) pa) + 192)) = fade1; } { u8 *pa; u8 *pb; alpha2 = (*((u8 *) (((u8 *) D_801F90D0[6].obj) + 35))) * 2; pa = D_80269F58; pb = D_80269F5C; if (alpha2 >= 0x100) { alpha2 = 0xFF; } fade2 = ((f32) (alpha2 * D_80101390)) / D_80101388; *((f32 *) (((u8 *) pb) + 196)) = fade2; *((f32 *) (((u8 *) pa) + 196)) = fade2; } if (D_801F91A8 != 0) { if ((--D_801F91A8) == 0) { D_801F956B = 5; goto block_56; } } else { block_56: { s32 *p = &D_801F9560; *p -= ((*p) - 0x400) / 3; } D_801F9564 -= (D_801F9564 - 0x400) / 3; if (D_801F956B < 0xFF) { D_801F956B += 0xA; } } if (D_801E746C >= 0x97) { s32 *q = &D_8029018C; if ((*q) != 0) { if (D_801E746C & 1) { *q -= 1; func_801793DC(0x8C, 0x64, 0x80, 0x80); func_8018E260(0xA); } if ((*q) == 0) { goto block_63; } } else { block_63: if (D_801F7F7C == (-1)) { D_801F7F7C = 0x3C; } } } if (D_801E746C > 0) { if (D_801E7584 & 2) { seconds = D_801F94CC; func_801D2150(D_802846F8, &D_801010F0, (s16) (seconds / 60), (s16) (seconds % 60)); } else { func_801D2150(D_802846F8, &D_801012D8); } text_scale = D_80101398; func_801469E4((s16) D_801F90D0[1].pos, (s16) D_801F90D0[1].y, 0xFF, 0xFF, 0xFF, 0xFF, text_scale, text_scale, 1, D_802846F8, 1); seconds = *((u16 *) (((u8 *) (&D_801E6790)) + ((*((s32 *) (((u8 *) (&D_801E693C)) + ((*((s8 *) (&D_801E7532))) * 0x38)))) * 6))); func_801D2150(D_802846F8, &D_801010F0, (s16) (seconds / 60), (s16) (seconds % 60)); func_801469E4((s16) D_801F90D0[3].pos, (s16) D_801F90D0[3].y, 0xFF, 0xFF, 0xFF, 0xFF, text_scale, text_scale, 1, D_802846F8, 1); if (D_801F7F80 != 0) { pulse = ((func_80149724(D_8010139C, D_801E746C, 0) * D_801013A0) + D_801013A4) + D_801013A0; blue = 0x80; { u32 cv; if (!(D_801013A8 <= pulse)) { cv = (s32) pulse; } else { cv = (s32) (pulse - D_801013A8); cv |= 0x80000000; } green = cv; } red = green; } else { blue = 0xFF; green = 0xFF; red = 0xFF; } if (blue < 0) { func_801D2150(D_802846F8, &D_801012DC, D_8029018C, D_80299394); func_801469E4((s16) D_801F90D0[5].pos, (s16) D_801F90D0[5].y, red & 0xFF, green & 0xFF, blue, 0xFF, 1.0f, 1.0f, 1, D_802846F8, 1); func_801D2150(D_802846F8, &D_801012E4, D_80290188); func_801469E4((s16) D_801F90D0[6].pos, (s16) D_801F90D0[6].y, 0xFF, 0xFF, 0xFF, D_801F956B, 1.0f, 1.0f, 1, D_802846F8, 1); } else { func_801D2150(D_802846F8, &D_801012DC, D_8029018C, D_80299394); func_801469E4((s16) D_801F90D0[5].pos, (s16) D_801F90D0[5].y, red & 0xFF, green & 0xFF, blue, 0xFF, 1.0f, 1.0f, 1, D_802846F8, 1); func_801D2150(D_802846F8, &D_801012E4, D_80290188); func_801469E4((s16) D_801F90D0[6].pos, (s16) D_801F90D0[6].y, 0xFF, 0xFF, 0xFF, D_801F956B, 1.0f, 1.0f, 1, D_802846F8, 1); } } if (((D_801F7F84 >= ((s32) D_801F94CC)) && (D_801E7584 & 2)) && (D_801E746C & 1)) { spark_dx = (s32) (func_80149724(D_801013B0, D_801E746C, 0) * D_801013B4); spark_y = (D_801F90D0[1].y + func_80147000(0xB)) - D_801013B8; func_8014E8B4(D_801F90D0[1].pos + spark_dx, spark_y, func_80147000(3) + 3, 6); } D_801E746C += 1; if (((D_801E75C4 == 0) && ((*((u8 *) (((u8 *) D_801FAAC6) + ((D_80202218 * 400) + 0)))) != 0)) || (D_801F7F7C == 0)) { D_801F7F7C = -1; D_801E75C4 = 0xC8; func_8014D4D0(); D_801EC7D2 = 1; } if (func_8014D5E0() != 0) { D_801E75C4 = 0; D_801EFC92 = 3; func_8014AAB8(&D_801F94D0); func_8014AAB8(D_801F92F8); func_8014AAB8(&D_801F9280); D_801E746C = 0; func_8010F94C(); func_8011CAF8(); func_8018E260(D_8029018C * 0xA); func_8011FF40(D_801E7531);
    }
  }
}

/* Reloads the current level (D_801E7531) via the level loader func_8011FF40. */
void func_80121FCC(void) {
    func_8011FF40(D_801E7531);
}

/* Update and render the end-of-world celebration screen: initialize the world
 * backdrop, title box, waving Glover model, lighting, music, and per-letter
 * world-name buffer on frame 1; animate the bouncing text, sparkles, and
 * Glover drop/spin each frame; then fade out after 500 frames or button input. */
void func_80121FF4(void)
{
  const f32 unusedInitFloat;
  float lightDirZ;
  extern s32 D_801E7474;
  extern s16 D_801E75F4;
  extern s16 D_801E760C;
  extern s16 D_801E7600;
  extern f32 D_801E7604;
  extern f32 D_801E7608;
  extern f32 D_801E75F8;
  extern f32 D_801E75FC;
  extern f32 D_801E75D0;
  extern f32 D_801E75D4;
  extern f32 D_801E75D8;
  extern s32 D_801E75DC[];
  extern s32 D_801E75E8[];
  extern f32 D_801F7F88[];
  extern f32 D_801F8118[];
  extern f32 D_801F7FD4;
  extern f32 D_801F7FC4;
  extern s16 D_801F8310[];
  extern u8 D_801F830C;
  extern u8 D_801F82A8[];
  extern u8 D_801F82A9[];
  extern u8 *D_801F83D8;
  extern u8 *D_80269F48;
  extern s32 D_801EAB9C[];
  extern s32 D_801EAC2C[];
  extern s32 D_801EAC50[];
  extern s32 D_801EAC38[];
  extern s32 D_801E7398;
  extern u8 D_801F91B0[];
  extern u8 D_802991A0[];
  extern s32 D_801013BC[];
  extern s32 D_8010127C[];
  extern s32 D_801012B0;
  extern s32 D_801012C0;
  extern s32 D_801013C4;
  extern u8 D_801EFC92;
  extern u8 D_801EC7D2;
  extern s16 D_801EC7DA;
  extern u8 D_80202218;
  extern u8 D_801E7534;
  extern s16 D_801E7586;
  extern s8 D_801ED400;
  extern s8 D_801ED401;
  extern s8 D_801ED402;
  extern s8 D_801E7584;
  extern s32 D_801EC860;
  extern u8 *D_80269F40[];
  extern s8 D_801E7531;
  extern u8 D_802978E8[];
  extern const f32 D_801013D0;
  extern const f32 D_801013D4;
  extern const f32 D_801013D8;
  extern const f32 D_801013DC;
  extern const f32 D_801013E0;
  extern const f32 D_801013E4;
  extern const f32 D_801013E8;
  extern const f32 D_801013EC;
  extern const f32 D_801013F0;
  extern const f32 D_801013F4;
  extern const f32 D_801013F8;
  extern const f32 D_801013FC;
  extern const f32 D_80101400;
  extern const f32 D_80101404;
  extern const f32 D_80101408;
  extern const f32 D_8010140C;
  extern const f32 D_80101410;
  extern const f32 D_80101414;
  extern const f32 D_80101418;
  extern const f32 D_8010141C;
  extern const f32 D_80101438;
  extern const f32 D_8010143C;
  extern const f32 D_80101440;
  extern const f32 D_80101444;
  extern const f32 D_80101448;
  extern const f32 D_8010144C;
  extern const f64 D_80101420;
  extern const f64 D_80101428;
  extern const f64 D_80101430;
  extern const f64 D_80101450;
  extern const f64 D_80101458;
  extern const f64 D_80101460;
  extern const f64 D_80101468;
  extern const f64 D_80101470;
  extern const f64 D_80101478;
  extern const f64 D_80101480;
  extern const f64 D_80101488;
  extern const f64 D_80101490;
  extern const f64 D_80101498;
  void func_8010EEF8(char *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32);
  void func_8010F94C(void);
  void func_8011CAF8(void);
  void func_8011FF40(s32);
  void func_8012643C(void);
  s32 func_8012801C(void);
  s32 func_80128D34(void);
  void func_8012A738(u8, u8, u8);
  void func_80133998(void *, s32, s32, s32, f32);
  s32 func_801399EC(u8);
  u32 func_80139CA0(u8 *);
  void *func_8013FCDC(s32, s32, s32 *);
  void func_80142700(void *, s32);
  void func_80145680(s32);
  s16 func_80145928(u8 *, f32, s32);
  void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
  s32 func_80147000(s32);
  f32 func_80149724(f32, f32, s32);
  void func_8014AA20(ObjectNode *);
  void func_8014D4D0(void);
  void func_8014D548(void);
  s32 func_8014D5E0(void);
  void func_8014E760(void);
  void func_8014E8B4(s32, s32, s32, s32);
  void func_8014ED2C(void);
  void func_8014F510(s32);
  void func_8014FCF8(void *, s32, s32);
  void func_80150EA4(s32);
  void func_80155A44(s32 *);
  void func_80155AE4(void *);
  void func_8015C350(u8 *, u8 *);
  void func_80177A14(s32);
  void func_80188FD8(u8 *);
  void func_801890EC(u8 *, u8, u8, u8, u8, u8, u8, f32, f32, f32);
  void func_801891E4(u8 *, u8, u8, u8);
  f32 func_801C6000(f32);
  s32 i;
  s32 charIndex;
  s32 bankOrWidth;
  u32 letterX;
  f32 bonusScale;
  f32 boxPosX;
  f32 boxPosY;
  f32 boxScaleX;
  f32 boxScaleY;
  f32 modelPosZ;
  f32 modelScaleZ;
  f32 letterY;
  u8 *backdropSprite;
  u8 **gloverModelSlot;
  s16 *languagePtr;
  s16 *bonusLangPtr;
  s32 pad[2];
  typedef struct { s16 v; } S16Box;

  /* Frame 1: one-time scene, backdrop, model, lighting, and letter-buffer setup. */
  if ((++D_801E7474) == 1)
  {
    func_80155A44(D_801013BC);
    D_801E75F4 = 0;
    func_8012801C();
    D_801E760C = 0;
    D_801E7604 = D_801013D0;
    D_801E7608 = D_801013D4;
    for (i = 0; i < EOW_LETTER_SLOTS; i++)
    {
      D_801F7F88[i] = (i * EOW_LETTER_INITIAL_Y_STEP) + EOW_LETTER_INITIAL_Y_BASE;
      D_801F8118[i] = D_801013D4;
      D_801F8310[i] = 0;
    }

    /* Split the localized world name into null-terminated single-character strings. */
    i = 0;
    D_801F830C = func_801D20F8(((LocalizedWorldNameRow *) D_801EAB9C)[*((s8 *) (&D_801E7534))].s[*((s16 *) (((u8 *) (&D_801E7534)) + 0x52))]);
    for (charIndex = 0; charIndex < D_801F830C; charIndex++, i += 2)
    {
      D_801F82A8[i] = ((LocalizedWorldNameRow *) D_801EAB9C)[*((s8 *) (&D_801E7534))].s[*((s16 *) (((u8 *) (&D_801E7534)) + 0x52))][charIndex];
      D_801F82A9[i] = 0;
    }

    D_801ED400 = 0;
    D_801ED402 = 0;
    D_801ED401 = 0;
    *((f32 *) D_802978E8) = D_801013D8;
    letterY = unusedInitFloat;
    bankOrWidth = EOW_TEXTURE_BANK_LATE_WORLD;
    if (((s8) D_801E7534) < EOW_EARLY_WORLD_LIMIT)
    {
      bankOrWidth = EOW_TEXTURE_BANK_EARLY_WORLD;
    }
    func_8014F510(bankOrWidth);
    func_80150EA4(EOW_MODEL_BANK_ID);

    /* Allocate and link the world backdrop sprite. */
    D_801F83D8 = func_8013FCDC(EOW_BACKDROP_SPRITE_SIZE, 1, D_8010127C);
    func_8014AA20((ObjectNode *) D_801F83D8);
    func_8014FCF8(D_801F83D8 + 0x48, func_80139CA0(((u8 *) (&D_801E7398)) + (((s8) D_801E7534) * EOW_WORLD_RECORD_STRIDE)), 1);
    boxPosX = D_801013DC;
    boxPosY = D_801013E0;
    modelPosZ = D_801013E4;
    boxScaleX = D_801013E8;
    boxScaleY = D_801013EC;
    modelScaleZ = D_801013F0;
    backdropSprite = D_801F83D8;
    backdropSprite[0x6F] = EOW_COLOR_MAX;
    backdropSprite[0x6E] = EOW_COLOR_MAX;
    backdropSprite[0x6D] = EOW_COLOR_MAX;
    backdropSprite[0x6C] = EOW_COLOR_MAX;
    *((s16 *) (D_801F83D8 + 0x58)) = EOW_BACKDROP_SCALE;
    *((s16 *) (D_801F83D8 + 0x5A)) = EOW_BACKDROP_SCALE;

    /* Spawn the title box back/front models and the waving Glover model. */
    func_8010EEF8((char *) (&D_801012B0), boxPosX, boxPosY, modelPosZ, 0.0f, 0.0f, 0.f, boxScaleX, boxScaleY, modelScaleZ, EOW_COLOR_MAX);
    func_8010EEF8((char *) (&D_801012C0), boxPosX, boxPosY, modelPosZ, 0.0f, 0.0f, 0.0f, boxScaleX, boxScaleY, modelScaleZ, EOW_TITLEBOX_FRONT_ALPHA);
    func_8010EEF8((char *) (&D_801013C4), 0.0f, 87.0f, modelPosZ, 0.0f, 0.0f, 0.0f, modelScaleZ, modelScaleZ, modelScaleZ, EOW_COLOR_MAX);
    gloverModelSlot = &D_80269F48;
    func_80142700(*gloverModelSlot, 4);
    func_80133998(*gloverModelSlot, 0, 1, 1, D_801013F4);
    *((f32 *) (D_80269F40[2] + 0xBC)) = boxScaleX;
    D_801EC7DA = EOW_DRAW_DISTANCE;
    *((f32 *) (D_80269F40[2] + 0xC0)) = D_801013F8;

    /* Configure directional/ambient lighting, screen particles, music, and fade-in. */
    lightDirZ = 0.0f;
    func_801890EC(D_801F91B0, EOW_COLOR_MAX, EOW_LIGHT_GREEN, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_LIGHT_GREEN, EOW_COLOR_MAX, D_801013FC, D_80101400, lightDirZ);
    *((s32 *) D_801F91B0) = 0;
    func_80188FD8(D_801F91B0);
    func_801891E4(D_802991A0, EOW_AMBIENT_RED, EOW_AMBIENT_GB, EOW_AMBIENT_GB);
    func_8012A738(0, 0, 0);
    func_8014E760();
    func_80177A14(EOW_MUSIC_TRACK_ID);
    D_801EFC92 = EOW_PACED_MSG_ACTIVE;
    D_801E7584 &= 0xFE;
    func_8014D548();
    func_80155AE4(D_801013BC);
  }

  /* Update pause/audio fade and emit celebratory sparkles on odd frames after frame 70. */
  func_8012643C();
  if ((D_801E7474 >= EOW_SPARKLE_START_FRAME) && (D_801E7474 & 1))
  {
    f32 sparkleOffsetX = (s32) (func_80149724(D_80101404, D_801E7474, 0) * D_80101408);
    s32 sparkleY = func_80147000(EOW_SPARKLE_Y_RANGE) + EOW_SPARKLE_Y_BASE;
    func_8014E8B4((s32) (sparkleOffsetX + D_8010140C), sparkleY, func_80147000(EOW_SPARKLE_COUNT_RANGE) + EOW_SPARKLE_COUNT_BASE, EOW_SPARKLE_PRESET);
  }
  func_8014ED2C();

  /* Hold "WELL DONE" off-screen during the first 20 frames, then slide it inward. */
  if (D_801E7474 < EOW_BANNER_DELAY_FRAMES)
  {
    D_801E7600 = 0;
    D_801E75F8 = D_80101410;
    D_801E75FC = D_80101414;
  }
  languagePtr = &D_801E7586;
  func_801469E4((s16) (D_801E75DC[((S16Box *)languagePtr)->v] - D_801E75F8), EOW_BANNER_Y, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_COLOR_MAX, D_80101418, D_80101418, 1, D_801EAC2C[*languagePtr], 1);
  func_801469E4((s16) (D_801E75E8[((S16Box *)languagePtr)->v] + D_801E75F8), EOW_BANNER_Y, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_COLOR_MAX, D_80101418, D_80101418, 1, D_801EAC50[*languagePtr], 1);

  /* Center the world name horizontally and render each waving, bouncing letter. */
  {
    f32 nameWidthF;
    f64 startX;
    bankOrWidth = ((s16 (*)(u8 *, f32, f32)) func_80145928)(((LocalizedWorldNameRow *) D_801EAB9C)[(s8) D_801E7534].s[*languagePtr], D_8010141C, D_8010141C);
    nameWidthF = bankOrWidth;
    startX = D_80101428 - (nameWidthF / D_80101420);
    if (!(startX >= D_80101430))
    {
      letterX = (s32) startX;
    }
    else
    {
      letterX = (s32) (startX - D_80101430);
      letterX |= 0x80000000;
    }
  }
  for (i = 0; i < D_801F830C; i++)
  {
    f32 letterScale;
    letterY = D_801F7F88[i] + D_80101438;
    letterScale = D_8010143C;
    letterY += func_801C6000((((f32) D_801E7474) / D_801E75D0) + (((f32) i) / D_801E75D4)) * D_801E75D8;
    func_801469E4((s16) letterX, (s16) letterY, EOW_COLOR_MAX, EOW_COLOR_MAX, 0, EOW_COLOR_MAX, letterScale, letterScale, 1, (s32) (&D_801F82A8[i * 2]), 0);
    letterX += ((s16 (*)(u8 *, f32, f32)) func_80145928)(&D_801F82A8[i * 2], letterScale, letterScale) - 3;
  }

  /* Render "COMPLETE" and the bonus-level unlocked/locked message. */
  bonusLangPtr = &D_801E7586;
  func_801469E4((s16) (D_80101444 - D_801F7FD4), EOW_COMPLETE_Y, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_COLOR_MAX, EOW_COLOR_MAX, D_80101440, D_80101440, 1, D_801EAC38[*bonusLangPtr], 1);
  if (func_80128D34())
  {
    bonusScale = D_80101448;
    func_801469E4((s16) (D_801F7FC4 + D_80101444), EOW_BONUS_Y, EOW_COLOR_MAX, EOW_COLOR_MAX, 0, EOW_COLOR_MAX, bonusScale, bonusScale, 1, D_801EAC38[*bonusLangPtr + EOW_BONUS_UNLOCKED_OFFSET], 1);
  }
  else
  {
    func_80145680(1);
    bonusScale = D_8010144C;
    func_801469E4((s16) (D_801F7FC4 + D_80101444), EOW_BONUS_Y, EOW_COLOR_MAX, EOW_COLOR_MAX, 0, EOW_COLOR_MAX, bonusScale, bonusScale, 1, D_801EAC38[*bonusLangPtr + EOW_BONUS_LOCKED_OFFSET], 1);
    func_80145680(0);
  }

  /* Update Glover's drop height and spin angle from the bounce offset. */
  {
    f64 gloverOffset = D_801E7604;
    *((f32 *) (D_80269F40[2] + 0x38)) = (gloverOffset * D_80101460) + D_80101468;
    *((f32 *) (D_80269F40[2] + 0x78)) = (gloverOffset * D_80101450) / D_80101458;
  }

  /* Step bounce physics for the world-name letters, "WELL DONE" banner, and Glover. */
  for (i = 0; i < EOW_LETTER_SLOTS; i++)
  {
    D_801F7F88[i] += D_801F8118[i];
    D_801F8118[i] -= D_80101470;
    if (D_801F7F88[i] <= 0.0f)
    {
      D_801F7F88[i] = 0.0f;
      if (D_801F8310[i] < EOW_MAX_BOUNCES)
      {
        D_801F8310[i]++;
        D_801F8118[i] *= D_80101478;
      }
      else
      {
        D_801F8118[i] *= 0.0f;
      }
    }
  }

  D_801E75F8 += D_801E75FC;
  D_801E75FC -= D_80101480;
  D_801E7604 += D_801E7608;
  D_801E7608 -= D_80101488;
  if (D_801E75F8 <= 0.0f)
  {
    D_801E75F8 = 0.0f;
    if (D_801E7600 < EOW_MAX_BOUNCES)
    {
      D_801E7600++;
      D_801E75FC *= D_80101490;
    }
    else
    {
      D_801E75FC *= 0.0f;
    }
  }
  if (D_801E7604 <= 0.0f)
  {
    D_801E7604 = 0.0f;
    if (D_801E760C < EOW_MAX_BOUNCES)
    {
      D_801E760C++;
      D_801E7608 *= D_80101498;
    }
    else
    {
      D_801E7608 *= 0.0f;
    }
  }

  /* Rebuild orientation quaternions for all active menu models. */
  {
    s32 modelIndex;
    for (modelIndex = 0; modelIndex < D_801EC860; modelIndex++)
    {
      func_8015C350(D_80269F40[modelIndex] + 0x9C, D_80269F40[modelIndex] + 0x78);
    }
  }

  /* Begin fade-out after 500 frames or when a menu button is pressed. */
  if (D_801E75F4 == 0)
  {
    if (D_801E7474 > EOW_AUTO_EXIT_FRAMES)
    {
      D_801E75F4 = EOW_EXIT_LOCK_VALUE;
      func_8014D4D0();
      D_801EC7D2 = 1;
    }
    if ((D_801E75F4 == 0) && func_801399EC(D_80202218))
    {
      D_801E75F4 = EOW_EXIT_LOCK_VALUE;
      func_8014D4D0();
      D_801EC7D2 = 1;
    }
  }

  /* Once the fade-out completes, free menu resources and load the next level. */
  if (func_8014D5E0())
  {
    D_801EFC92 = EOW_PACED_MSG_EXIT;
    func_8010F94C();
    func_8011CAF8();
    func_8011FF40(D_801E7531);
    D_801E7474 = 0;
    D_801E75F4 = 0;
  }
}

/* Reloads the current level (D_801E7531) via the level loader func_8011FF40. */
void func_80122D68(void) {
    func_8011FF40(D_801E7531);
}

/* Show the error message, then fade back to the main menu when the player presses A. */
void func_80122D90(void) {
    extern s32 D_801E7478;
    extern u8 D_801E760E;
    extern u8 D_80202218;
    extern u8 D_801E7544[];
    extern u8 D_801014A0[];
    extern u8 D_801014AC[];
    extern f32 D_801014C0;
    extern s8 D_801E7530;
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    s32 opaqueAlpha;
    s32 centerText;
    f32 textScale;

    func_80145680(1);
    if (++D_801E7478 == 1) {
        func_80145E30();
        D_801ED402 = 0;
        D_801ED401 = 0;
        D_801ED400 = 0;
        D_801E753C = ERROR_SCREEN_TRANSITION_EXTENT;
        func_801C0A2C(1, 1);
        do {
        } while (func_801C0B00(1) != 0);
        func_8011CD50(1);
        func_8014D548();
        opaqueAlpha = ERROR_SCREEN_COLOR_MAX;
        func_80155AE4(D_801014A0);
        centerText = ERROR_SCREEN_CENTER_TEXT;
        textScale = D_801014C0;
        func_801469E4(ERROR_SCREEN_CENTER_X, ERROR_SCREEN_MESSAGE_Y, ERROR_SCREEN_COLOR_MAX, ERROR_SCREEN_COLOR_MAX, ERROR_SCREEN_MESSAGE_BLUE, opaqueAlpha, textScale, textScale, 0, (s32)D_801E7544, centerText);
        func_801469E4(ERROR_SCREEN_CENTER_X, ERROR_SCREEN_PROMPT_Y, ERROR_SCREEN_COLOR_MAX, ERROR_SCREEN_COLOR_MAX, opaqueAlpha, opaqueAlpha, textScale, textScale, 0, (s32)D_801014AC, centerText);
    }
    if (D_801E760E == 0 && D_801FAAC6[D_80202218].f != 0) {
        D_801E760E = ERROR_SCREEN_INPUT_LOCK;
        func_8014D4D0();
    }
    if (func_8014D5E0() != 0) {
        D_801E7530 = GAME_STATE_MAIN_MENU;
        D_801E7478 = 0;
        D_801ED402 = 0;
        D_801ED401 = 0;
        D_801ED400 = 0;
        D_801E753C = ERROR_SCREEN_TRANSITION_EXTENT;
        func_801C0A2C(1, 1);
        do {
        } while (func_801C0B00(1) != 0);
        func_8011CD50(1);
        D_801E760E = 0;
    }
    func_80145680(0);
}

extern s32 D_801E7614;
extern s32 D_801E7610;

/* Step the screen transition: ease the extent D_801E753C toward its target D_801E753E,
 * move the second level D_801E758C toward D_801E758E by fixed down/up steps, and
 * publish the extent clamped to 0..255 to D_8028D80E. */
void func_80122F9C(void)
{
  int changed;
  extern s32 D_801E7614; /* step down */
  extern s32 D_801E7610; /* step up */
  extern f32 D_801014C4; /* easing divisor */
  int canStepDown;
  s16 *extent = &D_801E753C;
  s16 *level;
  s16 cur;
  s16 *levelAddr;
  s32 clamped;
  s32 pad[2];
  levelAddr = &D_801E758C;
  if ((*extent) != D_801E753E)
  {
    *extent = ((f32) (*extent)) + (((f32) (D_801E753E - (*extent))) / D_801014C4);
    if ((D_801E753E == 0) && (((s16) (*extent)) < 10))
    {
      *extent = 0;
    }
  }
  level = levelAddr;
  cur = *level;
  do { cur = cur; } while (0);
  changed = cur != D_801E758E;
  if (changed)
  {
    s16 next = cur;
    s16 target = D_801E758E;
    if (D_801E758E < cur)
    {
      s16 *dst = level;
 do { if (canStepDown = (cur - D_801E7614) >= 0) { next = next - D_801E7614; } else { next = 0; } *dst = next; } while (0);
    }
    else
    {
      if ((cur + D_801E7610) < target)
      {
        level = level;
        next = next + D_801E7610;
      }
      else
      {
        next = target;
      }
      *level = next;
    }
  }
  clamped = D_801E753C;
  if (clamped < 0)
  {
    clamped = 0;
  }
  cur = (clamped < 0x100) ? (clamped) : (0xFF);
  D_8028D80E = cur;
}

/* Save progress, show congratulations and missed bonus levels, then transition to the credits. */
void func_801230A8(void) {
    extern s16 D_801E7468;
    extern s16 D_801E7618;
    extern f32 D_801F83E0;
    extern f32 D_801014C8;
    extern f32 D_801014CC;
    extern f32 D_801014D0;
    extern f32 D_801014D4;
    extern f32 D_801014D8;
    extern f32 D_801014DC;
    extern f32 D_801014E0;
    extern f32 D_801014E4;
    extern f32 D_801014E8;
    extern u8 D_801010E8[];
    extern s32 D_801EAB78[];
    extern s32 D_801EAB84[];
    extern s32 D_801E747C;
    extern u8 D_80202218;
    extern s32 D_80290188;
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    void func_8014E8B4(s32, s32, s32, s32);
    void func_8014ED2C(void);
    void func_8011CAF8(void);
    void func_80132648(void);
    s32 index;
    s32 missingBonusLevels = 0;
    f32 slideStep;
    f32 slideOffset;
    u8 message[CONGRATS_TEXT_BUFFER_SIZE];

    D_801E7468++;
    if (D_801E7468 == CONGRATS_SAVE_FRAME) {
        D_801F83E0 = D_801014C8;
        func_801335A8(0);
        func_8012A77C(D_80290188);
    }
    if ((D_801E7468 >= CONGRATS_INPUT_FRAME && D_801E7618 == 0 && D_801FAAC6[D_80202218].f != 0) || D_801E7468 == CONGRATS_TIMEOUT) {
        D_801E7618 = CONGRATS_INPUT_LOCK;
        func_8014D4D0();
    }
    func_8014ED2C();
    if (D_801E7468 > CONGRATS_INPUT_FRAME) {
        if (D_801E7468 > CONGRATS_SLIDE_FRAME) {
            f64 wideOffset;
            slideOffset = D_801F83E0;
            wideOffset = slideOffset;
            slideOffset = wideOffset;
            slideStep = -slideOffset / D_801014CC;
            D_801F83E0 = slideOffset + ((slideStep < D_801014D0 || slideStep < D_801014D4) ? (slideStep < D_801014D0 ? D_801014D0 : slideStep) : D_801014D4);
        }
        if (D_801F83E0 < D_801014D8) {
            D_801F83E0 = D_801014D8;
        }
        if (D_801E7468 == CONGRATS_FLASH_FRAME) {
            func_8014D61C(TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, 0, TEXT_CHANNEL_MAX, CONGRATS_FLASH_STEP);
        }
        if (D_801E7468 == CONGRATS_BURST_FRAME) {
            for (index = 0; index < CONGRATS_BURST_COUNT; index++) {
                s32 jitter = func_80147000(CONGRATS_BURST_JITTER);
                func_8014E8B4((index << CONGRATS_BURST_X_SHIFT) + (jitter += CONGRATS_BURST_X_OFFSET), CONGRATS_TITLE_Y, CONGRATS_BURST_PARTICLES, CONGRATS_PARTICLE_TYPE);
            }
        }
        func_801469E4(CONGRATS_TITLE_X, CONGRATS_TITLE_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, D_801014DC, D_801014DC, 1, D_801EAB78[D_801E7586], 1);
    }
    for (index = 0; index < CONGRATS_WORLD_COUNT; index++) {
        missingBonusLevels += (u32)((((s32 *)D_801EAA48)[D_801EAB24 * CONGRATS_SAVE_SLOT_WORDS]) & (1 << (index * CONGRATS_WORLD_BIT_STRIDE + CONGRATS_BONUS_BIT))) < 1U;
    }
    if (missingBonusLevels != 0) {
        s16 *language = &D_801E7586;
        f32 textScale;

        func_801D2150(message, D_801010E8, D_801EAB84[*language], missingBonusLevels);
        textScale = D_801014E0;
        if (*language == CONGRATS_ENGLISH) {
            textScale = D_801014E4;
        }
        func_801469E4((s16)(s32)(D_801F83E0 + *(const f32 *)&D_801014E8), CONGRATS_MESSAGE_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, textScale, textScale, 1, (s32)message, 1);
        func_801469E4((s16)(s32)(*(const f32 *)&D_801014E8 - D_801F83E0), CONGRATS_BONUS_LABEL_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, textScale, textScale, 1, D_801EAB84[*language + CONGRATS_LANGUAGE_COUNT], 1);
    }
    if (func_8014D5E0() != 0) {
        D_801E7618 = 0;
        D_801ED402 = 0;
        D_801ED401 = 0;
        D_801ED400 = 0;
        D_801E753C = CONGRATS_TRANSITION_EXTENT;
        func_801C0A2C(1, 1);
        do {
        } while (func_801C0B00(1) != 0);
        func_8011CD50(1);
        func_8011CAF8();
        D_801E747C = 0;
        func_80132648();
    }
}

/* process_gameplay_transitions: drives active portal/goal countdowns, level
 * elapsed ticks, special-level updates (hub and cutscenes 46/47), and executes
 * pending level/state transitions once the screen transition finishes closing. */
void func_80123514(void)
{
  extern s32 D_80000300;
  extern const f32 D_801014EC;
  extern const f32 D_801014F0;
  extern const f32 D_801014F4;
  extern const f32 D_801014F8;
  extern const f32 D_801014FC;
  extern const f32 D_80101500;
  extern const f32 D_80101504;
  extern const f64 D_80101508;
  extern const f32 D_80101510;
  extern const f32 D_80101514;
  extern const f64 D_80101518;
  extern const f32 D_80101520;
  extern s32 D_801E589C;
  extern s32 D_801E58A8;
  extern s32 D_801E58B4;
  extern s32 D_801E58B8;
  extern struct Col D_801E6790[];
  extern s32 D_801E693C[][14];
  extern s32 D_801E7382;
  extern s32 D_801E7396;
  extern s16 D_801E7460;
  extern s16 D_801E7466;
  extern s32 D_801E747C;
  extern s8 D_801E7530;
  extern u8 D_801E7541;
  extern s32 D_801E7588;
  extern s16 D_801E7620;
  extern s16 D_801E76D4;
  extern f32 D_801F94CC;
  extern s32 D_801EC768;
  extern s32 D_801FAA18;
  extern u16 D_801FB280[];
  extern u8 D_80202218;
  extern s32 D_80290198;
  extern u8 *D_802903B4;
  extern u8 D_8029F99E;
  extern f32 D_8029F9B0;
  void func_8010D5FC(s32);
  void func_80125794(void);
  s32 func_8012801C(void);
  s32 func_80128D34(void);
  void func_80128DF8(s32, s32, s32);
  void func_80128F74(void);
  void func_80129AFC(void);
  s32 func_80147000(s32);
  void func_801493EC(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3, f32 arg4);
  s32 func_8014D5E0(void);
  void func_80160228();
  void func_80179524(void);
  s32 func_801A2944(f32, u8 *);
  extern void func_801B13CC(void);
  s32 stopFrameCounter;
  f32 blendKeep;
  f32 blendTarget;
  s16 delayTimer;
  s16 warpTimer;
  s16 goalTimer;
  s32 *playerObj;
  s32 worldClearSlotOffset;
  s32 timeRecordOffset;
  s32 hubSlotOffset;
  s8 transitionCase;
  s32 transitionKind;
  s8 nextLevelId;
  u8 prevWorldIntro;
  u8 prevLevelHub;
  u8 prevLevelReturn;
  u8 prevWorld1;
  u8 prevWorld2;
  u8 prevWorld3;
  u8 prevWorld4;
  u8 prevWorld5;
  u8 prevWorld6;
  u8 prevLevelCutscene;
  u8 prevWorldReturn;
  u8 prevLevelIntro;
  u8 prevLevelWorld6;
  u8 prevWorldExit;
  u8 prevLevelWorldHub;
  u8 prevLevelWorld1;
  u8 prevLevelWorld2;
  u8 prevLevelWorld3;
  short prevLevelWorld4;
  u8 prevLevelWorld5;

  if (((u32) (((u8) D_801E7530) - GAME_STATE_PLAY)) < 2)
  {
    if (D_801EC7D2 == 0)
    {
      if (D_801E7466 != 0)
      {
        /* Delayed transition countdown (used on boss/bonus exits). */
        delayTimer = D_801E7466 - 1;
        D_801E7466 = delayTimer;
        stopFrameCounter = 1;
        if ((delayTimer << 0x10) == 0)
        {
          transitionKind = *((s8 *) (&D_801E7541));
          goto request_transition;
        }
      }
      else
        if (D_801E7460 != 0)
      {
        /* Active portal warp-out animation: pull player and ball to portal. */
        blendKeep = D_801014EC;
        func_801493EC(&D_8029F9AC, &D_8029F9AC, blendKeep, D_801E7588 + PORTAL_POSITION, blendTarget = D_801014F0);
        func_801493EC(&D_8029030C, &D_8029030C, blendKeep, D_801E7588 + PORTAL_POSITION, blendTarget);
        playerObj = ((u8 *) (&D_8029030C)) - 0x34;
        func_80160228(playerObj, 1);
        if ((*((s16 *) (((u8 *) D_802903B4) + 2))) == GAMEPLAY_WARP_ANIM_ID)
        {
          if (func_801A2944(D_801014F4, playerObj) != 0)
          {
            *((s16 *) (((u8 *) D_802903AC) + 4)) = GAMEPLAY_WARP_ACTION_RISE;
            D_8029F9D4 = D_801014F8;
          }
          if (func_801A2944(D_801014FC, playerObj) != 0)
          {
            transitionKind = func_80147000(2);
            {
              s32 fanfareBase = (D_801E7533 * 4) + 0x20;
              func_80177A14((fanfareBase + transitionKind) & 0xFF);
            }
            func_80178134(GAMEPLAY_SFX_WARP_OUT, &D_8029030C, 0x64, 0x8C);
            func_801B7764(&D_8029F9AC, 5, 0x13);
            *((s16 *) (&D_8029F99E)) = 0;
            func_801B13CC();
            D_8029F9B0 = D_80101500;
            D_8029F9A0 &= ~1;
          }
          if ((*((f32 *) (((u8 *) D_802903B4) + 76))) > D_80101504)
          {
            D_80290394 = D_80290394 * D_80101508;
            D_80290398 = D_80290398 * D_80101508;
            D_8029039C = D_8029039C * D_80101508;
          }
        }
        if ((D_801EC7D2 == 0) && ((((*((s32 *) (((u8 *) D_802903B4) + 4))) == GAMEPLAY_WARP_ANIM_DONE_STATE) || ((warpTimer = D_801E7460 - 1, D_801E7460 = warpTimer, (warpTimer << 0x10) == 0))) || ((*((u16 *) (((u8 *) (&D_801FB280)) + (D_80202218 * 6)))) & GAMEPLAY_BUTTON_A_MASK)))
        {
          transitionKind = *((s8 *) (&D_801E7541));
          stopFrameCounter = 1;
          goto request_transition;
        }
      }
      else
        if (D_801E7620 != 0)
      {
        /* Goal-door countdown: hold ball above portal and chime before world clear. */
        if (D_801E7588 != 0)
        {
          func_801493EC(&D_8029F9AC, &D_8029F9AC, 0.8f, D_801E7588 + PORTAL_POSITION, D_80101510);
          D_8029F9B0 = ((*((f32 *) (((u8 *) D_801E7588) + 184))) + D_80101514) + D_8029F9A8;
          *((s16 *) (((u8 *) D_802903AC) + 4)) = GAMEPLAY_GOAL_DOOR_PLAYER_ACTION;
        }
        goalTimer = D_801E7620 - 1;
        D_801E7620 = goalTimer;
        if (goalTimer == GAMEPLAY_GOAL_DOOR_CHIME_1)
        {
          func_80178134(GAMEPLAY_SFX_GOAL_CHIME, &D_8029030C, 0x64, 0x9B);
        }
        if (D_801E7620 == GAMEPLAY_GOAL_DOOR_CHIME_2)
        {
          func_80178134(GAMEPLAY_SFX_GOAL_CHIME, &D_8029030C, 0x64, 0xB4);
        }
        if (D_801E7620 == 0)
        {
          transitionKind = GAMEPLAY_TRANSITION_WORLD_COMPLETE;
          stopFrameCounter = 0;
          request_transition:
          func_80128DF8(transitionKind, stopFrameCounter, 1);
        }
      }
      else
        if ((D_801E76D4 * 0x14) < D_802004E0)
      {
        {
          s32 *tickCounter = &D_80290198;
          *tickCounter += 1;
        }
      }
    }

    /* Per-level scripted updates for hub and cutscenes 46/47. */
    if (D_801E7531 == LEVEL_HUB)
    {
      func_80125794();
    }
    else
      if (D_801E7531 == GAMEPLAY_LEVEL_CUTSCENE_47)
    {
      func_80128F74();
      goto update_cutscene_effects;
    }
    else
      if (D_801E7531 == GAMEPLAY_LEVEL_CUTSCENE_46)
    {
      func_80129AFC();
      update_cutscene_effects:
      func_80179524();
    }

    /* Execute pending transition once the screen curtain finishes closing. */
    if ((func_8014D5E0() != 0) && (D_801E7584 & GAME_TRANSITION_PENDING))
    {
      if (D_801EC7F0 == 1)
      {
        func_8010D5FC(D_801FAA18);
      }
      if (D_80000300 == 0)
      {
        D_801F94CC = ((f32) D_80290198) / D_80101518;
      }
      else
      {
        D_801F94CC = D_80290198 / D_80101520;
      }
      D_801ED402 = 0;
      D_801ED401 = 0;
      D_801ED400 = 0;
      D_801E753C = GAMEPLAY_TRANSITION_CLOSED_EXTENT;
      func_801C0A2C(1, 1);
      do
      {
      }
      while (func_801C0B00(1) != 0);
      func_8011CD50(1);

      transitionCase = D_801E7541 - 1;
      switch (transitionCase)
      {
        case 21: /* Cutscene 47 */
          prevLevelCutscene = D_801E7531;
          D_801E7531 = GAMEPLAY_LEVEL_CUTSCENE_47;
          D_801E7530 = GAME_STATE_LOAD_LEVEL;
          D_801E7532 = prevLevelCutscene;
          break;

        case 20: /* Intro/demo level 9 */
          prevLevelIntro = D_801E7531;
          prevWorldIntro = D_801E7533;
          D_801E7531 = GAMEPLAY_LEVEL_INTRO_DEMO;
          D_801E7533 = 0;
          D_801E7530 = GAME_STATE_LOAD_LEVEL;
          D_801E7532 = prevLevelIntro;
          D_801E7534 = prevWorldIntro;
          break;

        case 15:
        case 16:
        case 17:
        case 18:
          D_801EFD00 = -1;
        case 19: /* World level table lookup */
          D_801E7532 = D_801E7531;
          D_801E7531 = ((u8 *) (&D_801E7382))[(D_801E7533 * GAMEPLAY_WORLD_LEVEL_TABLE_STRIDE) + (*((s8 *) (&D_801E7541)))];
          D_801E7530 = GAME_STATE_LOAD_LEVEL;
          break;

        case 23: /* Reload current level */
          D_801E7530 = GAME_STATE_LOAD_LEVEL;
          break;

        case 14: /* Exit to main menu */
          D_801E747C = 0;
          D_802004E0 = 0;
          D_801E7530 = GAME_STATE_MAIN_MENU;
          break;

        case 13: /* Exit cutscene 46 to level 0 */
        {
          s8 *levelPtr = &D_801E7531;
          if ((*levelPtr) == GAMEPLAY_LEVEL_CUTSCENE_46)
          {
            prevWorldExit = D_801E7533;
            D_801E7530 = GAME_STATE_LOAD_LEVEL;
            D_801E7532 = *levelPtr;
            *levelPtr = 0;
            D_801E7533 = 0;
            D_801E7534 = prevWorldExit;
          }
          break;
        }

        case 0: /* Advance to next level with results screen */
          D_801EFD00 = -1;
          D_801E7530 = GAME_STATE_LEVEL_RESULTS;
          {
            u8 prevLevel = D_801E7531;
            u8 nextLevel = prevLevel + 1;
            D_801E7532 = prevLevel;
            D_801E7531 = nextLevel;
          }
          break;

        case 1: /* Advance to next level directly */
        {
          s8 *levelPtr = &D_801E7531;
          if ((*levelPtr) == GAMEPLAY_LEVEL_PLAYBACK_TRIGGER)
          {
            D_801EC7F0 = INPUT_MODE_PLAYBACK;
          }
          nextLevelId = *levelPtr + 1;
          do
          {
            D_801EFD00 = -1;
            D_801E7530 = GAME_STATE_LOAD_LEVEL;
            D_801E7532 = *levelPtr;
          } while (0);
          *levelPtr = nextLevelId;
          break;
        }

        case 2: /* World complete: record progress and check bonus unlock */
        {
          s8 *levelPtr = &D_801E7531;
          worldClearSlotOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
          if (!(((*((s32 *) (((u8 *) (D_801EAA48 + worldClearSlotOffset)) + 0))) >> (*((s32 *) (((u8 *) (&D_801E693C)) + ((*levelPtr) * GAMEPLAY_LEVEL_INFO_STRIDE))))) & 1))
          {
            *((u8 *) (((u8 *) (D_801EAA56 + worldClearSlotOffset)) + 0)) = (*((u8 *) (((u8 *) (D_801EAA56 + worldClearSlotOffset)) + 0))) + 1;
          }
          D_801E7535[D_801E7533] = 1;
          D_801EFD00 = -1;
          D_801E7532 = *levelPtr;
          D_801E7534 = D_801E7533;
          if (func_80128D34() != 0)
          {
            *levelPtr = GAMEPLAY_LEVEL_WORLD_HUB;
          }
          else
          {
            if (D_80297BEC & GAMEPLAY_CHEAT_ALL_WORLDS_MASK)
            {
              *levelPtr = GAMEPLAY_LEVEL_ALL_OPEN_HUB;
            }
            else
            {
              *levelPtr = *((u8 *) (((u8 *) (&D_801EAA57)) + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)));
            }
            D_801E7533 = 0;
          }
          D_801E7530 = GAME_STATE_WORLD_RESULTS;
          break;
        }

        case 3: /* Advance to world's boss/bonus level with results screen */
          D_801EFD00 = -1;
          D_801E7530 = GAME_STATE_LEVEL_RESULTS;
          D_801E7532 = D_801E7531;
          D_801E7531 = *((u8 *) (((u8 *) (&D_801E7396)) + (D_801E7533 * GAMEPLAY_WORLD_LEVEL_TABLE_STRIDE)));
          break;

        case 4: /* Return to world hub with results screen */
          prevLevelWorldHub = D_801E7531;
          D_801EFD00 = -1;
          D_801E7530 = GAME_STATE_LEVEL_RESULTS;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7532 = prevLevelWorldHub;
          break;

        case 11: /* Enter overworld hub (level 8) */
          prevLevelHub = D_801E7531;
          D_801E7530 = GAME_STATE_LOAD_LEVEL;
          D_801E7531 = LEVEL_HUB;
          D_801E7534 = 0;
          hubSlotOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
          D_801E7532 = prevLevelHub;
          if ((*((u8 *) (((u8 *) (D_801EAA56 + hubSlotOffset)) + 0))) == 0)
        {
          *((u8 *) (((u8 *) (D_801EAA56 + hubSlotOffset)) + 0)) = 1;
        }
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
        {
          D_801EFD00 = -1;
        }
          break;

        case 12: /* Return to overworld hub and save results */
          if (D_801E7531 == GAMEPLAY_LEVEL_WORLD_HUB)
        {
          if (D_8029F9A4 != (&D_802902D8))
          {
            if (D_801EFCFC == 0)
            {
              D_801EFD00 = D_801E7531;
              *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
            }
          }
          else
            if (D_801EFCFC == 0)
          {
            D_801EFD00 = -1;
          }
        }
          prevLevelReturn = D_801E7531;
          D_801E7530 = GAME_STATE_LOAD_LEVEL;
          D_80299398 = 0;
          D_801E7532 = prevLevelReturn;
          if (D_80297BEC & GAMEPLAY_CHEAT_ALL_WORLDS_MASK)
          {
            D_801E7531 = GAMEPLAY_LEVEL_ALL_OPEN_HUB;
          }
          else
          {
            D_801E7531 = *((u8 *) (((u8 *) (&D_801EAA57)) + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)));
          }
          do
          {
            prevWorldReturn = D_801E7533;
            D_801E7533 = 0;
            D_801E7534 = prevWorldReturn;
          } while (0);
          func_8012801C();
          if (D_801E589C != 0)
        {
          D_801E7530 = GAME_STATE_MAIN_MENU;
        }
          break;

        case 5: /* Enter world 1 hub */
          prevLevelWorld1 = D_801E7531;
          prevWorld1 = D_801E7533;
          D_801E7530 = GAME_STATE_LOAD_HUB;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7533 = 1;
          D_801E7532 = prevLevelWorld1;
          D_801E7534 = prevWorld1;
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
          if (D_801EFD00 != GAMEPLAY_LEVEL_WORLD_HUB)
        {
          D_801EFD00 = -1;
        }
          break;

        case 6: /* Enter world 2 hub */
          prevLevelWorld2 = D_801E7531;
          prevWorld2 = D_801E7533;
          D_801E7530 = GAME_STATE_LOAD_HUB;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7533 = 2;
          D_801E7532 = prevLevelWorld2;
          D_801E7534 = prevWorld2;
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
          if (D_801EFD00 != GAMEPLAY_LEVEL_WORLD_HUB)
        {
          D_801EFD00 = -1;
        }
          break;

        case 7: /* Enter world 3 hub */
          prevLevelWorld3 = D_801E7531;
          prevWorld3 = D_801E7533;
          D_801E7530 = GAME_STATE_LOAD_HUB;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7533 = 3;
          D_801E7532 = prevLevelWorld3;
          D_801E7534 = prevWorld3;
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
          if (D_801EFD00 != GAMEPLAY_LEVEL_WORLD_HUB)
        {
          D_801EFD00 = -1;
        }
          break;

        case 8: /* Enter world 4 hub */
          prevLevelWorld4 = D_801E7531;
          prevWorld4 = D_801E7533;
          D_801E7530 = GAME_STATE_LOAD_HUB;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7533 = 4;
          D_801E7532 = prevLevelWorld4;
          D_801E7534 = prevWorld4;
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
          if (D_801EFD00 != GAMEPLAY_LEVEL_WORLD_HUB)
        {
          D_801EFD00 = -1;
        }
          break;

        case 9: /* Enter world 5 hub */
          prevLevelWorld5 = D_801E7531;
          prevWorld5 = D_801E7533;
          D_801E7530 = GAME_STATE_LOAD_HUB;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7533 = 5;
          D_801E7532 = prevLevelWorld5;
          D_801E7534 = prevWorld5;
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
          if (D_801EFD00 != GAMEPLAY_LEVEL_WORLD_HUB)
        {
          D_801EFD00 = -1;
        }
          break;

        case 10: /* Enter world 6 hub */
          prevLevelWorld6 = D_801E7531;
          prevWorld6 = D_801E7533;
          D_801E7530 = GAME_STATE_LOAD_HUB;
          D_801E7531 = GAMEPLAY_LEVEL_WORLD_HUB;
          D_801E7533 = 6;
          D_801E7532 = prevLevelWorld6;
          D_801E7534 = prevWorld6;
          if ((D_8029F9A4 != (&D_802902D8)) && (D_801EFCFC == 0))
        {
          *((Vec3F *) (&D_801EFCD8)) = *((Vec3F *) (&D_8029F9AC));
          D_801EFD00 = (s8) D_801E7532;
        }
        else
          if (D_801EFD00 != GAMEPLAY_LEVEL_WORLD_HUB)
        {
          D_801EFD00 = -1;
        }
          break;

      }

      if (((u32) (((u8) D_801E7531) - GAMEPLAY_LEVEL_MENU_MIN)) < 2)
      {
        D_801E7530 = GAME_STATE_MAIN_MENU;
        D_801E58B4 = 1;
        D_801E58B8 = 0;
        D_801EC748 = 0;
      }
      if (D_801E7531 == GAMEPLAY_LEVEL_LANGUAGE_SELECT)
      {
        D_801E7530 = GAME_STATE_LANGUAGE_SELECT;
        D_802004E0 = 0;
      }

      /* Time-trial exit: update best time or tear down level subsystems. */
      if (((*(D_801EAA55 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES))) == GAMEPLAY_SAVE_MODE_TIME_TRIAL) && (((*((s8 *) (&D_801E7541))) != GAMEPLAY_TRANSITION_EXIT_MENU) & ((*((s8 *) (&D_801E7541))) != GAMEPLAY_TRANSITION_RELOAD_LEVEL)))
      {
        D_801E747C = 0;
        D_802004E0 = 0;
        if (D_801E7584 & LEVEL_RESULT_COMPLETED)
        {
          timeRecordOffset = (*((s32 *) (((u8 *) (&D_801E693C)) + (((s8) D_801E7532) * GAMEPLAY_LEVEL_INFO_STRIDE)))) * GAMEPLAY_TIME_RECORD_STRIDE;
          if (D_801F94CC < (*((s16 *) (((u8 *) (&D_801E6790)) + timeRecordOffset))))
          {
            *((s16 *) (((u8 *) (&D_801E6790)) + timeRecordOffset)) = D_801F94CC;
            D_801E7530 = GAME_STATE_MAIN_MENU;
            D_801E58B4 = 5;
            D_801E58A8 = 0;
            D_802004E0 = 0;
            D_801E747C = 0;
            func_80177A14(GAMEPLAY_FANFARE_TIME_TRIAL_RECORD);
            return;
          }
        }
        func_8014A9D8();
        func_80188F90();
        func_80188FB4();
        func_801A6820();
        func_8014ABEC();
        func_8015C758();
        func_801A8E30();
        func_801B4010();
        func_8018A9D0();
        func_80179EAC();
        func_801B9140();
        func_80179EAC();
        func_8018E6F8();
        func_8018E5F0();
        func_8018B3D8();
        func_8012ACC0();
        func_8018B3B8();
        func_801BAF6C();
        func_801B87C4();
        func_801B7B40();
        func_801779F0();
        func_8014A9FC();
        D_801E7530 = GAME_STATE_TIME_TRIAL_SELECT;
        func_8011D88C(1);
      }
    }
  }
}

/* Hub-world (world 4) level portal: every other frame, sparkles circle
 * portals 1 and 3 (and every portal on level 9). When the player (or, for
 * ball levels, the ball) comes within PORTAL_RADIUS, it enters the level
 * (func_80128DF8), starts the boss/exit sequence, or plays the warp; the
 * ball in a ball-only portal is reset. D_801E7531 is the current level,
 * D_8029030C / D_8029F9AC the player / ball positions. */
void func_801246AC(void *portal)
{
  extern f32 D_80101588;
  extern f32 D_8010158C;
  extern f32 D_80101590;
  extern f32 D_80101594;
  extern s32 D_80101598;
  extern f32 D_801015A4;
  extern s16 D_801E7460;
  extern s16 D_801E7466;
  extern s8 D_801E7530;
  extern u8 D_801E7541;
  extern s32 D_801E7588;
  extern s16 D_801E7620;
  extern f32 D_801E7624;
  extern f32 D_801E7628;
  extern s32 D_801EEB70;
  extern s32 D_801EEB74;
  extern s32 D_8028F908;
  extern s32 D_8028FB80;
  extern s32 D_8028FAF8;
  extern s32 D_8028FAC0;
  extern s32 D_8028FB74;
  extern s32 D_8028FAFC;
  extern f32 D_80290360;
  extern f32 D_8029F9B0;
  extern f32 D_8029F9B4;
  extern f32 D_8029F9D8;
  void func_80128DF8(s32, s32, s32);
  s32 func_80147000(s32);
  void func_80148D80(f32 *arg0, f32 *arg1, f32 *arg2, U32F32 arg3);
  f32 func_80148E48(f32 *a, f32 *b);
  void func_801490AC(Vec3F *, Vec3F *, f32);
  void func_801492FC(void *arg0);
  void func_80173CE8(s32);
  void func_801BB5C4(s32, s32, f32);
  f32 *visitorPos;
  s32 kind;
  s32 kind2;
  s32 kind3;
  s32 kind4;
  s32 kind5;
  s32 kind6;
  s32 slot;
  s32 slot2;
  s8 *world;
  s8 *level;
  f32 *ballPos;
  if (D_801E7530 == 4)
  {
    if ((D_802004E0 & 1) && (((kind6 = PORTAL_KIND(portal), ((kind6 == 1) | (kind6 == 3)) != 0)) || (D_801E7531 == 9)))
    {
      {
        /* Two sparkles on opposite sides of a rotating offset. */
        Vec3F offset;
        Vec3F sparkle;
        u8 *pos;
        f32 lift;
        f32 size;
        f32 scale;
        f32 y;
        offset.z = 0.0f;
        offset.x = D_80101588;
        offset.y = D_8010158C;
        func_801490AC(&offset, &offset, D_801E7628);
        pos = ((u8 *) portal) + PORTAL_POSITION;
        scale = D_80101590;
        D_801E7628 += D_801E7624;
        ((void (*)(f32 *, f32 *, f32 *, f32)) func_80148D80)(&sparkle.x, (f32 *) pos, &offset.x, scale);
        y = PORTAL_Y(portal);
        lift = D_80101594;
        size = *((f32 *) (&D_80101598));
        sparkle.y = y + lift;
        func_801BB5C4((s32) (&sparkle), (s32) (&offset), size);
        func_801492FC(&offset);
        ((void (*)(f32 *, f32 *, f32 *, f32)) func_80148D80)(&sparkle.x, (f32 *) pos, &offset.x, scale);
        sparkle.y = PORTAL_Y(portal) + lift;
        func_801BB5C4((s32) (&sparkle), (s32) (&offset), size);
      }
    }
    if ((((D_801EFCFC == 0) && ((*(world = (s8 *) (&D_801E7533))) == 0)) && (((u32) ((*((u8 *) (&D_801E7531))) - 8)) >= 2)) && ((slot = D_801EAB24 * 0x1C, (*((u8 *) (((u8 *) (D_801EAA56 + slot)) + 0))) != (*((u8 *) (((u8 *) (&D_801EAA57)) + slot))))))
    {
      if (D_8029F9A4)
      {
        kind = PORTAL_KIND(portal);
      }
      else
      {
        kind = PORTAL_KIND(portal);
      }
      if ((kind != 0xC) & (kind != 0x15))
      {
        if ((kind + world)[-3] != 0)
        {
          goto block_11;
        }
      }
      else
      {
        goto block_12;
      }
    }
    else
    {
      block_11:
      block_12:
      /* Which position opens this portal: the player's or the ball's. */
      if ((((((((((PORTAL_KIND(portal)) == 0xC) | ((PORTAL_KIND(portal)) == 0x15)) != 0) || ((((PORTAL_KIND(portal)) == 6) | ((PORTAL_KIND(portal)) == 8)) != 0)) || ((((PORTAL_KIND(portal)) == 7) | ((PORTAL_KIND(portal)) == 9)) != 0)) || (((u32) ((PORTAL_KIND(portal)) - 0xA)) < 2)) || (((PORTAL_KIND(portal)) == 0xD) && (D_801E7531 != 9))) || (((D_801E7531 == 0x2A) | (D_801E7531 == 0xE)) != 0)) || (((D_801E7531 == 0xC) | (D_801E7531 == 0xF)) != 0))
      {
        visitorPos = &D_8029030C;
      }
      else
      {
        visitorPos = &D_8029F9AC;
      }


      kind5 = PORTAL_KIND(portal);
      if (kind5 == 3)
      {
        /* Portal 3: the ball resting on it opens it (once, with a timer). */
        if (((*((s32 *) (((u8 *) D_8029FA50) + 376))) == portal) && (func_8015C4C8() != 0))
        {
          func_80173CE8(0x1F4);
          D_8029F9D0 = (D_8029F9D4 = (D_8029F9D8 = 0.0f));
          if ((D_801E7620 == 0) && (!(D_801E7584 & 1)))
          {
            s32 door;
            if ((*((s16 *) (((u8 *) D_802903AC) + 4))) != kind5)
            {
              func_80167604(3);
              D_8029F5C8 = 0;
            }
            do
            {
              D_8028FAF8 = 1;
            }
            while (0);
            *((Vec3F *) (&D_8028FAFC)) = *((Vec3F *) (&D_8028F914));
            door = *((s32 *) (((u8 *) portal) + PORTAL_DOOR_OBJECT));
            D_801E7620 = 0x3C;
            *((s16 *) (((u8 *) door) + PORTAL_DOOR_TIMER)) = 0x1E;
            func_80178134(func_80147000(4) + 0x10D, &D_8029030C, 0x64, 0x80);
            func_80178134(0x14E, &D_8029030C, 0x64, 0x82);
            D_801E7588 = portal;
          }
        }
        goto block_62;
      }
      level = &D_801E7531;
      if (((((((((*level) == 0x2A) | ((*level) == 8)) != 0) || (((kind5 == 0xC) | (kind5 == 6)) != 0)) || (((u32) (kind5 - 7)) < 2)) || (((u32) (kind5 - 9)) < 2)) || ((PORTAL_KIND(portal)) == 0xB)) || ((((*level) == 0xC) | ((*level) == 0xF)) != 0))
      {
        if ((!(D_801E7584 & 1)) && (func_80148E48(visitorPos, portal + PORTAL_POSITION) < (PORTAL_RADIUS(portal))))
        {
          if (((D_801E7531 == 0xC) | (D_801E7531 == 0xF)) != 0)
          {
            if (D_801E7466 == 0)
            {
              s32 base;
              D_801E7466 = 0x32;
              kind = func_80147000(2);
              base = (D_801E7533 * 4) + 0x20;
              func_80177A14((base + kind) & 0xFF);
              goto block_60;
            }
          }
          else
          {
            goto block_61;
          }
        }
        goto block_62;
      }
      if (((D_801E7460 == 0) && (!(D_801E7584 & 1))) && (func_80148E48(visitorPos, portal + PORTAL_POSITION) < (PORTAL_RADIUS(portal))))
      {
        kind2 = PORTAL_KIND(portal);
        if ((kind2 != 0x15) && ((((*level) == 0x2A) | ((*level) == 0xE)) == 0))
        {
          if (kind2 == 0xD)
          {
            slot2 = D_801EAB24 * 0x1C;
            if ((*((u8 *) (((u8 *) (&D_801EAA57)) + slot2))) != (*((u8 *) (((u8 *) (D_801EAA56 + slot2)) + 0))))
            {
              if (D_801EFCFC != 0)
              {
                goto block_52;
              }
              goto block_62;
            }
            goto block_52;
          }
          if ((func_8015C4C8() != 0) || (D_8029F9A4 == (&D_802902D8)))
          {
            goto block_52;
          }
          goto block_63;
        }
        block_52:
        if (((((PORTAL_KIND(portal)) == 1) || (D_801E7531 == 9)) && ((D_801E7531 != 0x26) & (D_801E7531 != 0xC))) && (D_801E7531 != 0xF))
        {
          if (((D_801E7531 != 9) || (func_8015C4C8() != 0)) || (D_8029F9A4 == (&D_802902D8)))
          {
            /* Warp out through the portal. */
            func_80178134(func_80147000(4) + 0x10D, &D_8029030C, 0x64, 0x80);
            D_801E7460 = 0x2710;
            func_8018D39C(4);
            D_801E7588 = portal;
            func_80173CE8(0x2710);
            D_8028FBD8 = 0x2710;
            func_80167604(0x2B);
            D_80290360 = func_801496C8(D_8028F95C + (*((const f64 *) (((u8 *) (&D_80101598)) + 4))));
            {
              s32 *ballFlags = &D_8029F9A0;
              *ballFlags &= ~0x18;
            }
            block_60:
            D_801E7541 = PORTAL_KIND(portal);

            goto block_62;
          }
          goto block_63;
        }

        block_61:
        func_80128DF8(PORTAL_KIND(portal), 1, 1);

        goto block_62;
      }
      block_62:
      if (D_8029F9A4 != (&D_802902D8))
      {
        block_63:
        /* A loose ball entering a ball portal is sent back. */
        if (((((func_8015C4C8() == 0) && (((((kind3 = PORTAL_KIND(portal), ((kind3 == 0xC) | (kind3 == 6)) != 0)) || (((u32) (kind3 - 7)) < 2)) || (((u32) (kind3 - 9)) < 2)) || ((PORTAL_KIND(portal)) == 0xB))) && (!(D_801E7584 & 1))) && (D_801EFCFC != 2)) && (func_80148E48(ballPos = &D_8029F9AC, portal + PORTAL_POSITION) < (PORTAL_RADIUS(portal))))
        {
          func_801B66D4(0xF, ballPos, &D_801ED3C4, 0, 0);
          func_801B7764(ballPos, 5, 0x13);
          *ballPos = 0.0f;
          D_8029F9B4 = 0.0f;
          D_8029F9B0 = D_801015A4;
          kind4 = PORTAL_KIND(portal);
          D_801EFCFC = 2;
          D_801EFD00 = (kind4 == 0xC) ? (8) : (kind4 + 0x24);
        }

      }

    }
  }
}

/* level_get_world: the world a level belongs to (0 hub, 1..5 the five-level
 * worlds starting at level 10, 6 and 7 for the special levels). */
s32 func_80124F2C(s32 level) {
    s8 id;

    id = level;
    if ((u8)level < LEVEL_FIRST_WORLD_LEVEL || id == LEVEL_HUB_44) {
        return WORLD_HUB;
    }
    if (id == LEVEL_HUB_45) {
        return WORLD_HUB;
    }
    if ((u8)(level - 10) < LEVELS_PER_WORLD) {
        return 1;
    }
    if ((u8)(level - 15) < LEVELS_PER_WORLD) {
        return 2;
    }
    if ((u8)(level - 20) < LEVELS_PER_WORLD) {
        return 3;
    }
    if ((u8)(level - 25) < LEVELS_PER_WORLD) {
        return 4;
    }
    if ((u8)(level - 30) < LEVELS_PER_WORLD) {
        return 5;
    }
    if (id == LEVEL_KEEP_WORLD) {
        return D_801E7533;
    }
    return id < LEVEL_WORLD7_FIRST ? WORLD_6 : WORLD_7;
}

extern s8 D_801E7530;

/* Returns nonzero when the current game state runs the level world (updates and draws it):
 * zero for the main menu, level select, state 3, level results, state 11 and the error screen. */
s32 func_80124FF8(void) {
    s32 state = D_801E7530;

    if (state == GAME_STATE_MAIN_MENU) {
        return 0;
    }
    if (state == GAME_STATE_LEVEL_SELECT) {
        return 0;
    }
    if (state == 3) {
        return 0;
    }
    if (state == GAME_STATE_LEVEL_RESULTS) {
        return 0;
    }
    if (state != 11) {
        return state != GAME_STATE_ERROR;
    }

    return 0;
}

/* Orbit the title camera while oscillating its height, radius and look-at height. */
void func_80125040(void) {
    extern f32 D_801E762C;
    extern f32 D_801015A8;
    extern f32 D_801015AC;
    extern f64 D_801015B0;
    extern f32 D_801015B8;
    extern f32 D_801015BC;
    extern f64 D_801015C0;
    extern s32 D_801F83E4;
    extern f32 D_801F83E8;
    extern f32 D_801F83EC;
    extern f32 D_801F83F0;
    extern f32 D_801F83F4;
    extern f32 D_801F83F8;
    void func_801490AC(Vec3F *, Vec3F *, f32);
    void func_80162EAC(f32, f32, s32, s32, s32, s32, s32);
    s32 *eyePositionWords = &D_801F83E4;
    f32 *targetPosition;
    f32 oscillationScale;

    *eyePositionWords = 0;
    D_801F83E8 = func_801C6000(D_801E762C * D_801015A8) * D_801015AC + (oscillationScale = D_801015B8);
    D_801F83EC = func_801C6000((f32)((f64)D_801E762C * D_801015B0)) * oscillationScale + D_801015BC;
    func_801490AC((Vec3F *)eyePositionWords, (Vec3F *)eyePositionWords, D_801E762C);
    targetPosition = &D_801F83F0;
    *targetPosition = D_801F83F8 = 0.0f;
    D_801F83F4 = func_801C6000(D_801E762C) * oscillationScale + oscillationScale;
    D_801E762C = (f32)((f64)D_801E762C + D_801015C0);
    func_80162EAC(*(f32 *)eyePositionWords, D_801F83E8, *(s32 *)&D_801F83EC, (s32)targetPosition, (s32)&D_801ED3C4, TITLE_CAMERA_MODE, TITLE_CAMERA_FLAGS_NONE);
}

/* Orbit a second title camera: bob the eye offset's height, rotate eye and target offsets by the orbit angle, and apply them. */
void func_8012519C(void) {
    void func_801490AC(Vec3F *, Vec3F *, f32);
    void func_80162EAC(f32, f32, f32, void *, void *, s32, s32);
    f32 *eyeOffsetY = &D_801E7634;
    f32 *eyePosition = &D_801F83FC;
    f32 *targetPosition = &D_801F8408;

    /* D_801015C8 = 2.4 (bob frequency), D_801015D0 = 0.005 (orbit step per frame). */
    *eyeOffsetY += func_801C6000((f32)((f64)D_801E7648 * D_801015C8));
    func_801490AC((Vec3F *)eyePosition, (Vec3F *)((u8 *)eyeOffsetY - 4), D_801E7648);
    func_801490AC((Vec3F *)targetPosition, (Vec3F *)&D_801E763C, D_801E7648);
    D_801E7648 += D_801015D0;
    func_80162EAC(*eyePosition, *(f32 *)&D_801F8400, *(f32 *)&D_801F8404, targetPosition, &D_801ED3C4,
                  TITLE_CAMERA_MODE, TITLE_CAMERA_FLAGS_NONE);
}

/* Animate the game-over text, save the score, and unload the scene after the exit transition. */
void func_80125294(void)
{
  extern s32 D_801E7470;
  extern u8 D_801EC7D2;
  extern s16 D_802902FE;
  extern s16 D_80299960;
  extern s32 D_801ED3D0;
  extern f32 D_801F1A6C;
  extern s32 D_801EAB54[];
  extern s32 D_801EAB60[];
  extern s32 D_801F8414;
  extern s32 D_801F8418;
  extern f32 D_801F841C;
  extern f32 D_801F8420;
  extern f32 D_801F8424;
  extern f32 D_801015D8;
  extern f32 D_801015DC;
  extern f32 D_801015E0;
  extern f32 D_801015EC;
  extern const f32 D_801015F0;
  extern const f32 D_801015F4;
  extern f64 D_801015F8;
  extern u8 D_801E764C;
  extern u8 D_80202218;
  extern s8 D_801E7530;
  extern s32 D_80290188;
  extern f32 D_80290310;
  void func_8010F94C(void);
  u8 *func_801AA5BC(s16);
  void func_801A8E54(u8 *);
  void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
  u8 *effect;
  s32 frame;
  f32 textScale;
  f32 velocity;
  f32 upperStopY;
  ScalarF32 *upperY;
  if (D_801E7531 == GAME_OVER_SPECIAL_LEVEL)
  {
    if (D_801E7470 == 1)
    {
      func_8010F94C();
      D_801EC7D2 = 0;
      func_8012AD30(2);
      D_802902FE = 100;
      D_80299960 = 200;
    }
    else
      if (D_801E7470 < GAME_OVER_EFFECT_FRAME)
    {
      *((f32 *) (&D_8029030C)) = func_80147000(0x15) - 10;
      D_80290310 = func_80147000(0x15) + 240;
      D_80290314 = func_80147000(0x15) - 10;
      D_801E7470 += 1;
      return;
    }
    else
      if (D_801E7470 == GAME_OVER_EFFECT_FRAME)
    {
      D_802902FE = 0;
      effect = func_801AA5BC(0xF);
      *((Vec3Words *) (effect + 0x3C)) = *((Vec3Words *) (&D_8029030C));
      *((QuaternionWords *) (effect + 0xA4)) = *((QuaternionWords *) (&D_801ED3D0));
      *((s16 *) (effect + 0x2C)) = (s32) D_801F1A6C;
      func_801A8E54(effect);
    }
    else
      if (D_801E7470 < GAME_OVER_EFFECT_WAIT_END)
    {
      D_801E7470 += 1;
      return;
    }
  }
  frame = D_801E7470;
  if (frame == 1)
  {
    func_80177A14((u8) (((D_801E7533 * 4) + 0x1E) + func_80147000(2)));
    func_80145680(0);
    textScale = D_801015D8;
    ((ScalarS32 *) (&D_801F8414))->value = (s32) func_801469E4(GAME_OVER_TEXT_CENTER_X, GAME_OVER_UPPER_START_Y, 0xFF, 0xFF, 0xFF, 0xFF, textScale, textScale, 0, *(D_801EAB54 + D_801E7586), frame);
    D_801F8418 = (s32) func_801469E4(GAME_OVER_TEXT_CENTER_X, GAME_OVER_LOWER_START_Y, 0xFF, 0xFF, 0xFF, 0xFF, textScale, textScale, 0, *(D_801EAB60 + D_801E7586), frame);
    D_801F841C = 0;
    D_801F8420 = D_801015DC;
    D_801F8424 = D_801015E0;
    func_8012A77C(D_80290188);
  }
  velocity = (f32) (((f64) D_801F841C) + (*((f64 *) (((u8 *) (&D_801015E0)) + 4))));
  upperY = (ScalarF32 *) (&D_801F8420);
  upperY->value += velocity;
  D_801F8424 -= velocity;
  *((s32 *) (((ScalarS32 *) (&D_801F8414))->value + GAME_OVER_TEXT_Y_OFFSET)) = (s32) upperY->value;
  *((s32 *) (((ScalarS32 *) (&D_801F8418))->value + GAME_OVER_TEXT_Y_OFFSET)) = (s32) ((ScalarF32 *) (&D_801F8424))->value;
  upperStopY = D_801015EC;
  D_801F841C = velocity;
  D_801E7470 += 1;
  if (upperStopY <= (upperY->value + velocity))
  {
    if (velocity > 0.0f)
    {
      *((s32 *) (D_801F8414 + GAME_OVER_TEXT_Y_OFFSET)) = GAME_OVER_UPPER_STOP_Y;
      upperY->value = upperStopY;
      *((s32 *) (D_801F8418 + GAME_OVER_TEXT_Y_OFFSET)) = GAME_OVER_LOWER_STOP_Y;
      D_801F8424 = D_801015F4;
      if (velocity < D_801015F0)
      {
        if (textScale)
        {
          D_801F841C = 0.0f;
        }
        else
        {
          D_801F841C = 0.0f;
        }
      }
      else
      {
        D_801F841C = (f32) (((f64) (-velocity)) * D_801015F8);
      }
    }
  }
  if ((((D_801E764C == 0) && (D_801FAAC6[D_80202218].f != 0)) && (D_801E7470 >= GAME_OVER_EFFECT_FRAME)) || (D_801E7470 == GAME_OVER_TIMEOUT))
  {
    D_801E764C = GAME_OVER_INPUT_LOCK;
    func_8014D4D0();
    ((volatile ScalarS8 *) (&D_801E7584))->value |= GAME_TRANSITION_PENDING;
  }
  if (func_8014D5E0() != 0)
  {
    D_801E7470 = 0;
    D_801E764C = 0;
    D_801EC7D2 = 0;
    D_801ED402 = 0;
    D_801ED401 = 0;
    D_801ED400 = 0;
    D_801E753C = GAME_OVER_TRANSITION_EXTENT;
    func_801C0A2C(1, 1);
    do
    {
    }
    while (func_801C0B00(1) != 0);
    func_8011CD50(1);
    func_8011CAF8();
    D_801E7530 = GAME_STATE_MAIN_MENU;
  }
}

/* Per-frame update of a scripted sequence: while the current stage's step is 7, objects 1..7 fly in one
 * after another towards a fixed point (the last one ending the scene); otherwise, while the step counter is
 * below its target, the camera target is moved towards the next object, sparkles and a looping sound are
 * played around object 10, and each arrival advances the step and spawns the next object. */
void func_80125794(void)
{
  extern const f32 D_80101600;
  extern const f32 D_80101604;
  extern const f32 D_80101608;
  extern const f32 D_8010160C;
  extern const f32 D_80101610;
  u8 *stepPtr;
  extern const f32 D_80101614;
  s32 soundArg;
  extern const f32 D_80101618;
  extern const f32 D_8010161C;
  extern const f32 D_80101620;
  extern const f32 D_80101624;
  extern const f32 D_80101628;
  extern const f32 D_8010162C;
  extern const f32 D_80101630;
  extern const f32 D_80101634;
  extern const f32 D_80101638;
  extern const f32 D_8010163C;
  extern const f32 D_80101640;
  extern const f32 D_8010164C;
  extern const f32 D_80101650;
  extern const f32 D_80101654;
  int two;
  extern s32 D_802004E0;
  extern s16 D_801E7468;
  extern s16 D_801EAB24;
  extern u8 D_801EAA57;
  extern u8 D_801EAA56[];
  extern f32 D_80290360;
  extern f32 D_80290354;
  extern u8 *D_8029F458;
  extern s32 *D_8029F45C;
  extern s32 *D_8029FA5C;
  extern u8 *D_802903B4;
  extern s32 D_802902D8;
  extern s32 D_801EEB74;
  extern s32 D_802901CC;
  extern s32 D_801F842C;
  extern s32 D_801F8428;
  extern s32 D_801F8430;
  extern u8 D_801E7585;
  extern f32 D_8029F9AC;
  extern f32 D_8029F9B0;
  extern f32 D_8029F9B4;
  extern f32 D_8029F9D0;
  extern f32 D_8029F9D4;
  extern f32 D_8029F9D8;
  extern f32 D_801E761C;
  extern f32 D_8028F95C;
  extern s32 D_801EFCF8;
  extern s32 D_801EFCCC;
  extern s32 D_8029F9A0;
  extern s32 D_8029F9A4;
  extern u8 *D_8029FA50;
  extern s32 D_8029030C;
  extern u8 *D_802903AC;
  extern s16 D_8028FBD8;
  extern s16 D_8029F47E;
  extern s16 D_8028FBF4;
  extern u8 D_8028FBFB;
  extern s32 D_801ED3C4;
  extern s32 D_801EFCFC;
  typedef struct 
  {
    s32 a;
    s32 b;
    s32 c;
  } Tri32;
  typedef struct 
  {
    u8 pad0[0x1C];
    f32 unk1C;
    u8 pad20[0xC];
    u8 *unk2C;
    u8 pad30[0x76];
    s16 unkA6;
    u8 padA8[0xC];
    f32 pos[3];
    u8 padC0[0x18];
    f32 vel[3];
    u8 padE4[0x14];
    f32 unkF8;
    f32 unkFC;
    u8 pad100[0x1C];
    f32 unk11C[8];
    f32 unk13C[3];
    u8 *unk148;
    u8 pad14C[0x14];
    u8 *unk160;
  } Obj;
  typedef struct { u8 pad0[0x14]; u8 *unk14; } Mdl;
  void func_801B392C(s32);
  void func_801B39DC(s32, s32, f32);
  void func_80173CE8(s32);
  void func_8012AD30(s32);
  void func_80178760(void *);
  void func_80160228();
  void func_8015C350(u8 *, u8 *);
  void func_80128DF8(s32, s32, s32);
  void func_80148D0C(f32 *, f32 *, f32);
  void func_80149568(f32 *);
  void func_801570AC(u8 *, u8 *, u8 *, u8 *, u8 *, s32);
  f32 func_80149724(f32, f32, s32);
  s32 func_80147000(s32);
  void *func_8017DBA0(s32);
  void func_801490AC(Vec3F *, Vec3F *, f32);
  void func_801785E0(s32 *, s16, s16, s32, s16);
  void func_80178704(s32 *);
  void func_80149318(void *, void *);
  void func_80167604(s32);
  s32 func_80178134(s16, f32 *, s16, s16);
  void func_80133998(void *, s32, s32, s32, f32);
  f32 func_801496C8(f32);
  void func_80189E78(f32 *, f32 *, u8, u8, u8, u8, u16, u16, f32, f32);
  void func_8018C700(s32, s32);
  void func_8014D61C(s32, s32, s32, s32, s32);
  f32 sqrtf(f32);
  f32 dir[3];
  f32 point[3];
  Obj *obj;
  s32 i;
  s32 delay;
  s16 frames;
  s16 red;
  s16 green;
  s16 blue;
  s32 clampR;
  s32 clampG;
  s32 clampB;
  s32 slot;
  s32 slot2;
  s32 slot3;
  s32 count;
  f32 dist;
  f32 scale;
  f32 *camVel;
  s32 *loopSound;
  s32 *flag;
  s32 *loopSound2;
  s32 *loopSound3;
  s32 *loopSound4;
  u8 *phase;
  u8 *phase2;
  f32 destX;
  f32 destZ;
  f32 destY;
  if (D_802004E0 == 1)
  {
    D_801E7468 = 0;
    D_80290360 = D_80101600;
    D_80290354 = D_80101600;
  }
  func_801B392C(6);
  func_801B39DC(6, 0, 1.0f);
  *D_8029F45C = *((s32 *) (D_8029F458 + 0x1C));
  *D_8029FA5C = *((s32 *) (D_8029F458 + 0x20));
  if ((*((s16 *) (D_802903B4 + 2))) == 0x17)
  {
    func_80160228(&D_802902D8, 1);
    func_8015C350(((u8 *) (&D_802902D8)) + 0x9C, ((u8 *) (&D_802902D8)) + 0x78);
  }
  if ((*((&D_801EAA57) + (D_801EAB24 * 0x1C))) == 7)
  {
    if (D_801E7468 == 0)
    {
      func_8012AD30(0);
      D_801EEB74 = 0x96;
      soundArg = 2;
    } else {
      soundArg = 2;
    }
    i = 1;
    do
    {
      destZ = D_80101604;
      destY = D_80101608;
    }
    while (0);
    D_801E7468++;
    destX = 0.0f;
    func_80173CE8(soundArg);
    /* object i starts moving 10 frames after object i-1 */
    for (delay = 0; i < 8; i++, delay += 10)
    {
      if ((D_801E7468 - delay) < 0)
      {
        frames = 0;
      }
      else
      {
        frames = D_801E7468 - delay;
      }
      if (frames == 0)
      {
        continue;
      }
      obj = func_8017DBA0(i);
      if (obj->pos[1] < D_8010160C)
      {
        obj->pos[1] += D_80101610;
      }
      else
        if (obj->pos[2] > D_80101614)
      {
        obj->unk1C = 0.0f;
        obj->vel[2] = destX;
        obj->vel[1] = destX;
        obj->vel[0] = destX;
        if (i == 7)
        {
          func_80128DF8(0x16, 1, 1);
          return;
        }
      }
      else
        if (obj->pos[2] < destZ)
      {
        obj->unk1C = D_80101618;
        point[0] = 0.0f;
        point[1] = destY;
        point[2] = destZ;
        dir[0] = destX - obj->pos[0];
        dir[1] = destY - obj->pos[1];
        dir[2] = destZ - obj->pos[2];
        func_80149568(dir);
        func_80148D0C(obj->vel, dir, 0.5f);
      }
      obj->unkFC += ((f32) frames) / D_8010161C;
      func_8015C350((u8 *) obj->unk11C, (u8 *) (&obj->unkF8));
      func_801570AC(*((u8 **) ((*((u8 **) (obj->unk148 + 0xC))) + 0x14)), (u8 *) obj->pos, obj->unk160, (u8 *) obj->unk13C, (u8 *) obj->unk11C, 1);
      {
        f64 d = destX;
        destX = d;
      }
    }

  }
  else
  {
    D_801E7468 = 0;
  }
  flag = &D_802901CC;
  if ((*flag) != 0)
  {
    *flag = 2;
  }
  loopSound = &D_801F842C;
  if ((*loopSound) != 0)
  {
    func_80178760(loopSound);
  }
  if (D_802004E0 == 1)
  {
    count = *((&D_801EAA57) + (D_801EAB24 * 0x1C));
    *loopSound = 0;
    D_801E7585 = 0;
    D_801F8428 = count;
  }
  for (i = 0; i < D_801F8428; i++)
  {
    ((Obj *) func_8017DBA0(i + 1))->unkA6 = (func_80149724(D_80101628, (f32) (i * 10), D_802004E0) * D_80101620) + D_80101624;
  }

  slot = D_801EAB24 * 0x1C;
  if ((*((&D_801EAA57) + slot)) < D_801EAA56[slot])
  {
    if ((!(D_8029F9B4 < D_8010162C)) && (D_802004E0 < 0x47))
    {
      return;
    }
    if (D_801EFCFC != 0)
    {
      return;
    }
    phase2 = &D_801E7585;
    if ((*phase2) == 0)
    {
      *phase2 = 1;
      D_8029F9A0 &= ~0x19;
      D_8029FA50[0x188] = 0;
      *((s32 *) D_8029FA50) = 0;
      if (D_8029F9A4 == ((s32) (&D_802902D8)))
      {
        func_80167604(9);
      }
      D_8029F9A4 = (s32) (&D_802902D8);
      D_8028FBFB = 0;
      D_8029F47E = 0;
      return;
    }
    func_80173CE8(0x7D0);
    slot2 = D_801EAB24 * 0x1C;
    if (((*((&D_801EAA57) + slot2)) != D_801EAA56[slot2]) && (func_80147000(10) < 8))
    {
      /* two random greenish sparkles on either side of object 10 */
      dir[0] = D_80101630;
      dir[1] = 0.0f;
      dir[2] = 0.0f;
      func_801490AC((Vec3F *) dir, (Vec3F *) dir, *((f32 *) (((Obj *) func_8017DBA0(10))->unk2C + 0x3C)));
      loopSound2 = &D_801F842C;
      if ((*loopSound2) == 0)
      {
        func_801785E0(loopSound2, 0x3C, 0x64, (s32) (&D_801ED3C4), 0x80);
      }
      else
      {
        D_801F8430 = 0x64;
      }
      red = func_80147000(0xA0) + 0x28;
      green = func_80147000(0x78) + 0xC3;
      blue = func_80147000(0xA0) + 0x28;
      red = (red < 0) ? (0) : (red);
      clampR = red;
      if (clampR > 0xFF)
      {
        clampR = 0xFF;
      }
      red = clampR;
      green = (green < 0) ? (0) : (green);
      clampG = green;
      if (clampG >= (0xFF + 1))
      {
        clampG = 0xFF;
      }
      green = clampG;
      blue = (blue < 0) ? (0) : (blue);
      clampB = blue;
      if (clampB > 0xFF)
      {
        clampB = 0xFF;
      }
      blue = clampB;
      point[0] = dir[0] + ((Obj *) func_8017DBA0(10))->pos[0];
      point[1] = dir[1] + ((Obj *) func_8017DBA0(10))->pos[1];
      point[2] = dir[2] + ((Obj *) func_8017DBA0(10))->pos[2];
      func_80189E78(point, &D_8029F9AC, red, green, blue, 8, 1, 6, D_80101634, D_80101638);
      red = func_80147000(0xA0) + 0x28;
      green = func_80147000(0x78) + 0xC3;
      blue = func_80147000(0xA0) + 0x28;
      red = (red < 0) ? (0) : (red);
      clampR = red;
      if (clampR > 0xFF)
      {
        clampR = 0xFF;
      }
      red = clampR;
      green = (green < 0) ? (0) : (green);
      clampG = green;
      if (clampG > 0xFF)
      {
        clampG = 0xFF;
      }
      green = clampG;
      blue = (blue < 0) ? (0) : (blue);
      clampB = blue;
      if (clampB > 0xFF)
      {
        clampB = 0xFF;
      }
      blue = clampB;
      point[0] = ((Obj *) func_8017DBA0(10))->pos[0] - dir[0];
      point[1] = ((Obj *) func_8017DBA0(10))->pos[1] - dir[1];
      point[2] = ((Obj *) func_8017DBA0(10))->pos[2] - dir[2];
      func_80189E78(point, &D_8029F9AC, red, green, blue, 8, 1, 6, D_80101634, D_80101638);
    }
    else
    {
      /* fade the looping sound out */
      loopSound3 = &D_801F842C;
      if ((*loopSound3) != 0)
      {
        D_801F8430 -= 5;
        if (D_801F8430 <= 0)
        {
          func_80178704(loopSound3);
        }
      }
    }
    /* move the camera target towards the next object, at most D_801E761C per frame */
    func_80149318(dir, ((Obj *) func_8017DBA0(D_801EAA56[D_801EAB24 * 0x1C]))->pos);
    if (D_801E7585 == 1)
    {
      dir[1] = D_8010163C;
    }
    else
    {
      dir[1] = D_80101640;
    }
    camVel = ((f32 *) (&D_8029F9A0)) + 12;
    camVel[0] = dir[0] - ((f32 *) (&D_8029F9A0))[3];
    D_8029F9D4 = dir[1] - D_8029F9B0;
    D_8029F9D8 = dir[2] - D_8029F9B4;
    dist = sqrtf(((camVel[0] * camVel[0]) + (D_8029F9D4 * D_8029F9D4)) + (D_8029F9D8 * D_8029F9D8));
    if (D_801E761C < dist)
    {
      scale = D_801E761C / dist;
      camVel[0] *= scale;
      D_8029F9D4 *= scale;
      D_8029F9D8 *= scale;
      return;
    }
    phase = &D_801E7585;
    if ((++(*phase)) == 2)
    {
      func_80178134(func_80147000(4) + 0x10D, (f32 *) (&D_8029030C), 0x64, 0x80);
      func_80133998(((u8 *) (&D_8029030C)) - 0x34, 0x17, 0, 0, 0.0f);
      D_80290360 = func_801496C8(D_8028F95C - (*((const f64 *) (((u8 *) (&D_80101640)) + 4))));
      *((s16 *) (D_802903AC + 4)) = 0x29;
      D_8028FBD8 = 0x3FF;
      func_80173CE8(0x14);
      *((Tri32 *) (((f32 *) (&D_8029F9A0)) + 3)) = *((Tri32 *) dir);
      func_80178134(0x61, ((f32 *) (&D_8029F9A0)) + 3, 0x64, 0x80);
      func_8018C700(0xC, 2);
      func_8014D61C(0, 0xC8, 0, 0x118, -0x1E);
      D_8029F9A0 &= ~0x19;
      return;
    }
    /* arrived: advance the step and bring in the next object */
    *((Tri32 *) (((f32 *) (&D_8029F9A0)) + 3)) = *((Tri32 *) dir);
    *phase = 0;
    {
      slot3 = D_801EAB24 * 0x1C;
      *((&D_801EAA57) + slot3) = (*((&D_801EAA57) + slot3)) + 1;
      camVel[0] = (D_8029F9D4 = (D_8029F9D8 = 0.0f));
      {
        u8 *actor = D_8029FA50;
        f32 m = *((f32 *) (actor + 0x74));
        stepPtr = (&D_801EAA57) + (D_801EAB24 * 0x1C);
        D_801EFCF8 = 0;
        *((f32 *) (actor + 0x74)) = m * 2.0f;
      }
      ((f32 *) (&D_8029F9A0))[3] = 0.0f;
      D_8029F9B0 = D_8010164C;
      D_8029F9B4 = D_80101650;
    }
    D_8029F9A4 = 0;
    obj = func_8017DBA0(*stepPtr);
    obj->pos[1] = D_80101654;
    *((Tri32 *) (&D_801EFCCC)) = *((Tri32 *) (((f32 *) (&D_8029F9A0)) + 3));
    flag = *((u8 **) (obj->unk148 + 0xC));
    D_801EFCFC = (two = 2);
    D_801F8428++;
    func_801570AC(((Mdl *) flag)->unk14, (u8 *) obj->pos, obj->unk160, (u8 *) obj->unk13C, (u8 *) obj->unk11C, 1);
    D_8028FBF4 = 1;
  }
  else
  {
    loopSound4 = &D_801F842C;
    if ((*loopSound4) != 0)
    {
      D_801F8430 -= 5;
      if (D_801F8430 <= 0)
      {
        func_80178704(loopSound4);
      }
    }
  }
}

/* Update pause/transition audio volume fading and drive the in-game pause menu
 * (backdrop animation, localized options, checkpoint cycling, cheat-code polling,
 * and Yes/No confirmation cursors). */
void func_8012643C(void) {
#define FIELD(type, ptr, off) (*(type *)((u8 *)(ptr) + (off)))
    extern u8 D_801010C0[];
    extern const s32 D_80101658;
    extern const s32 D_80101660;
    extern const s32 D_80101668;
    extern const s32 D_80101670;
    extern const f32 D_8010167C;
    extern const f32 D_80101680;
    extern const f32 D_80101684;
    extern const f32 D_80101688;
    extern const f32 D_8010168C;
    extern const f32 D_80101690;
    extern const f32 D_80101694;
    extern const f32 D_80101698;
    extern const f32 D_8010169C;
    extern const f32 D_801016A0;
    extern const f32 D_801016A4;
    extern const f32 D_801016A8;
    extern const f32 D_801016AC;
    extern const f32 D_801016B0;
    extern const f32 D_801016B4;
    extern const f32 D_801016B8;
    extern const f32 D_801016BC;
    extern const f32 D_801016C0;
    extern const f32 D_801016C4;
    extern const f32 D_801016C8;
    extern const f32 D_801016CC;
    extern const f32 D_801016D0;
    extern const f32 D_801016D4;
    extern const f32 D_801016D8;
    extern const f32 D_801016DC;
    extern const f32 D_801016E0;
    extern const f32 D_801016E4;
    extern const f32 D_801016E8;
    extern const f32 D_801016EC;
    extern const f32 D_801016F0;
    extern const f32 D_801016F4;
    extern const f32 D_801016F8;
    extern const f32 D_801016FC;
    extern const f32 D_80101700;
    extern const f32 D_80101704;
    extern const f32 D_80101708;
    extern const f32 D_8010170C;
    extern const f32 D_80101710;
    extern const f32 D_80101714;
    extern const f32 D_80101718;
    extern const f32 D_8010171C;
    extern s32 D_801E589C;
    extern s32 D_801E7470;
    extern s32 D_801E747C;
    extern u8 *D_801E7650;
    extern u8 *D_801E7654;
    extern s32 D_801E765C;
    extern f32 D_801E7660;
    extern u8 D_801E7664;
    extern s16 D_801E76DC;
    extern s32 D_801EAB48;
    extern s32 D_801EACE4;
    extern s32 D_801EACF0;
    extern s32 D_801EACFC;
    extern s32 D_801EAD08;
    extern s32 D_801EADC8;
    extern u8 D_801EC7D3;
    extern u8 D_801F20F0;
    extern u8 D_801F2198[];
    extern s32 D_801F8448;
    extern s32 D_801F844C;
    extern s32 D_801F8450;
    extern s32 D_801F8454;
    extern u8 D_801F8458;
    extern u8 D_801F845C;
    extern u8 D_801F8460;
    extern u8 D_801F8464;
    extern s16 D_801FA754;
    extern s16 D_801FAA90;
    extern s16 D_801FAA92;
    extern u8 D_801FAAF0[];
    extern s32 D_801FAB70;
    extern u8 D_80202218;
    extern s16 D_8028FBF6;
    extern u8 *D_802900E0;
    extern s32 D_80290188;
    extern s32 D_80290194;
    extern f32 D_802AA72C;
    extern f32 D_802AA730;
    extern s32 D_802AA738;
    extern s32 D_802AA73C;
    extern f32 D_802AA834;
    extern f32 D_802AA838;
    extern s32 D_802AA840;
    extern s32 D_802AA844;
    extern u8 D_802AA848;
    extern u8 D_802AA849;
    extern u8 D_802AA84A;
    extern u8 D_802AA84B;
    void func_80128DF8(s32, s32, s32);
    s32 func_80128F0C(void);
    void func_8012A850(void);
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    f32 func_80149724(f32, f32, s32);
    void func_8014AB20(ObjectNode *arg0);
    void func_8014E9F4(s32, s32, f32, f32, s32, s32);
    s32 func_801793DC(s32, u8, u8, u8);
    s32 func_801BB710(void);
    void func_801C066C(s32, s32);

    char labelBuf[40];
    Unk802904D4Node *node;
    Unk802904D4Node *prevNode;
    s16 stickY;
    s16 menuY;
    s32 itemAlpha;
    s32 saveOffset;
    s32 nextCheckpoint;
    s32 prevCheckpoint;
    s32 optIdx1;
    s32 optIdx3;
    s32 optIdx2;
    s32 ctrlOffRight;
    s32 nextSteps;
    s32 prevSteps;
    s32 openBoxHeight;
    s32 finalBoxHeight;
    s32 closeBoxHeight;
    s32 ctrlOffLeft;
    s32 labelRow;
    s32 nextCount;
    s32 prevCount;
    void *warpState;
    void *cpState;
    void *nextState;
    void *prevState;
    void *warpState2;

    /* Fade music and SFX master volumes down while paused or transitioning, or ramp back up. */
    if ((D_801EC7D2 != 0) || (D_801E7584 & 1)) {
        if ((D_801E76DC == 0) && (D_801F20F0 == 0) && (D_801E7470 == 0) &&
            ((*(D_801EAA55 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) != GAMEPLAY_SAVE_MODE_TIME_TRIAL) || (D_801FA754 != 0))) {
            D_801E7658 = D_801E7658 * FIELD(f64, &D_80101660, 4);
        }
        D_801E765A = D_801E765A * FIELD(f64, &D_80101668, 4);
        func_801C066C(MUS_MASTER_VOLUME_SONGS, D_801E7658);
        func_8012A850();
    } else {
        {
            f64 rampRate = FIELD(f64, &D_80101670, 4); D_801E765A = D_801E765A + ((((D_801E65C0 * MUS_MASTER_VOLUME_MAX) / 160) - D_801E765A) * rampRate); D_801E7658 = D_801E7658 + ((((D_801E65C4 * MUS_MASTER_VOLUME_MAX) / 160) - D_801E7658) * rampRate);
        }
        func_801C066C(MUS_MASTER_VOLUME_SONGS, D_801E7658);
        func_801C066C(MUS_MASTER_VOLUME_EFFECTS, D_801E765A);
    }

    if (D_801EC7D3 != 0) {
        func_80145680(TEXT_FONT_ALTERNATE);
        if (D_801E7650 != NULL) {
            func_8014ED9C(D_801E7650);
        }
        if (D_801E7654 != NULL) {
            func_8014ED9C(D_801E7654);
        }

        /* First frame of pause: reset state, build option list, link backdrop sprites, count checkpoints. */
        if (D_801E765C == 0) {
            func_8012C2B0(D_801F2198, 0xFF, CHEAT_INPUT_LENGTH);
            D_801F21A1 = 0;
            D_801E7654 = NULL;
            D_801E7650 = NULL;
            D_801F8460 = 1;
            D_801F845C = 0;
            if ((*(D_801EAA55 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) == GAMEPLAY_SAVE_MODE_TIME_TRIAL) ||
                (((D_801E7531 != 0xD) & (D_801E7531 != 0x12)) &&
                 ((D_801E7531 != 0x17) & (D_801E7531 != 0x1C)) &&
                 (D_801E7531 != 0x21) &&
                 (D_801E7542 == 0) &&
                 ((D_801E7531 != 0xE) & (D_801E7531 != 0x13)) &&
                 ((D_801E7531 != 0x18) & (D_801E7531 != 0x1D)) &&
                 ((D_801E7531 != 0x22) & (D_801E7531 != 0x29)) &&
                 ((FIELD(u8, D_802903B0, 392) != 0) || (D_8029F9A4 == &D_802902D8)) &&
                 (D_8028FBF6 == 0) &&
                 (D_8029F468 == 0) &&
                 ((D_801EFCFC != 0) || (FIELD(u8, D_8029FA50, 392) != 0) ||
                  ((D_8029F9A0 & 0x200000) && (FIELD(u8, D_8029FA4C, 9) != 0))))) {
                D_801F8458 = 1;
                optIdx1 = D_801F8460 & 0xFF;
                D_801F8460 += 1;
                (&D_801F845C)[optIdx1] = 1;
            } else {
                D_801F8458 = 0;
            }
            if ((D_801E589C == 0) && ((u8)D_801E7531 >= 8)) {
                FIELD(u8, &D_801F8458, 1) = 1;
                optIdx2 = D_801F8460 & 0xFF;
                D_801F8460 += 1;
                (&D_801F845C)[optIdx2] = 2;
            } else {
                FIELD(u8, &D_801F8458, 1) = 0;
            }
            optIdx3 = D_801F8460 & 0xFF;
            D_801F8460 += 1;
            (&D_801F845C)[optIdx3] = 3;
            switch (D_801F8460) {
                case 2:
                    D_801F8464 = 0x5A;
                    break;
                case 3:
                    D_801F8464 = 0x50;
                    break;
                case 4:
                    D_801F8464 = 0x46;
                    break;
            }
            ((u8 *)&D_801E7660)[7] = 0;
            D_801EC7D2 = 1;
            (&D_801E7664)[1] = 0;
            {
                f32 *p = &D_802AA834;
                *p = D_802AA838 = D_802AA72C = D_802AA730 = 0.0f;
                func_8014AB20((ObjectNode *)((u8 *)p - 0xC));
            }
            node = D_802904D4.next;
            D_802AA738 = 0;
            D_802AA73C = 0;
            D_802AA840 = 0;
            D_802AA844 = 0;
            D_802AA84B = 0xC8;
            D_802AA848 = 0;
            D_802AA849 = 0xC8;
            D_802AA84A = 0;
            D_801E7664 = 0;
            D_801F844C = 0;
            D_801E7660 = D_8010167C;
            if (node != &D_802904D4) {
                do {
                    cpState = (void *)FIELD(s32, node, 84);
                    if ((cpState != NULL) && ((FIELD(s16, cpState, 20) == 0) || (D_80297BEC & 4))) {
                        if (*(u8 *volatile *)&D_802900E0 == (u8 *)node) {
                            D_801F8448 = D_801F844C;
                        }
                        D_801F844C += 1;
                    }
                    node = node->next;
                } while (node != &D_802904D4);
            }
            D_801F8450 = 0;
            D_801F8454 = (s32)D_802900E0;
        }

        /* Poll cheat-code entry while pause menu is open; close immediately on match. */
        if (((u32)(D_801E765C - 7) < 0x3E1) && (func_80128F0C() == 0) && (D_801E7531 != 0x28) && (func_801BB710() & 0xFF)) {
            D_801E765C = 0x3E8;
            if (D_801E7650 != NULL) {
                FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
            }
            if (D_801E7654 != NULL) {
                FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
            }
            ((u8 *)&D_801E7660)[7] = 0;
        }

        /* Cycle target checkpoint left/right when Checkpoint option is highlighted. */
        if (D_801F8450 == 0) {
            if (((&D_801E7664)[1] == 1) && (D_801F844C >= 2) &&
                (*(D_801EAA55 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) != GAMEPLAY_SAVE_MODE_TIME_TRIAL)) {
                if (FIELD(s16, &D_801FAA90, (D_80202218 * 0x190)) >= 0x28) {
                    func_801793DC(0xB4, 0x64, 0x80, 0x80);
                    nextCheckpoint = (D_801F8448 + 1) % D_801F844C; node = &D_802904D4;

                    D_801F8450 = 5;
                    D_801F8448 = nextCheckpoint;
                    nextSteps = nextCheckpoint + 1;
                    nextCount = 0;
                    if (nextSteps > 0) {
                        do {
                            node = node->next;
                            while (node != &D_802904D4) {
                                nextState = FIELD(void *, node, 84);
                                if ((nextState != NULL) && ((FIELD(s16, nextState, 20) == 0) || (D_80297BEC & 4))) {
                                    break;
                                }
                                node = node->next;
                            }
                            nextCount += 1;
                        } while (nextCount < nextSteps);
                    }
                    D_801F8454 = (s32)node;
                }
                if (FIELD(s16, &D_801FAA90, (D_80202218 * 0x190)) < -0x27) {
                    func_801793DC(0xB4, 0x64, 0x80, 0x80);
                    prevCheckpoint = ((D_801F8448 + D_801F844C) - 1) % D_801F844C; prevNode = &D_802904D4;

                    D_801F8450 = 5;
                    D_801F8448 = prevCheckpoint;
                    prevSteps = prevCheckpoint + 1;
                    prevCount = 0;
                    if (prevSteps > 0) {
                        do {
                            prevNode = prevNode->next;
                            while (prevNode != &D_802904D4) {
                                prevState = FIELD(void *, prevNode, 84);
                                if ((prevState != NULL) && ((FIELD(s16, prevState, 20) == 0) || (D_80297BEC & 4))) {
                                    break;
                                }
                                prevNode = prevNode->next;
                            }
                            prevCount += 1;
                        } while (prevCount < prevSteps);
                    }
                    D_801F8454 = (s32)prevNode;
                }
            }
        }
        if (D_801F8450 > 0) {
            D_801F8450 = D_801F8450 - 1;
        }

        /* Opening animation: expand backdrop box (frames 0..5), then fade text in (frames 6..11). */
        if (D_801E765C < 6) {
            D_802AA738 += 0xE9;
            { f32 *pa = &D_802AA72C; *pa += D_80101680; }
            D_802AA730 += D_80101684; openBoxHeight = (D_801F8460 << 7) + 0x200; D_802AA840 += 0x3A5; { f32 *pb = &D_802AA834; *pb += D_80101680; } D_802AA838 += D_80101684; D_802AA73C += openBoxHeight / 6; D_802AA844 += (openBoxHeight * 4) / 6;
        } else if (D_801E765C < 0xC) {
            D_802AA738 = 0x578;
            D_802AA840 = 0x15E0;
            D_801E7664 = D_801E7664 + 0x2A;
            D_802AA72C = D_80101688;
            D_802AA730 = D_8010168C;
            D_802AA834 = D_80101688;
            D_802AA838 = D_8010168C;
            finalBoxHeight = (D_801F8460 << 7) + 0x200;
            D_802AA73C = finalBoxHeight;
            D_802AA844 = finalBoxHeight * 4;
        }

        /* Draw pause header and localized menu options. */
        menuY = D_801F8464;
        func_80145680(TEXT_FONT_NORMAL);
        func_801469E4(0xA0, menuY, 0xFF, 0xFF, 0xFF, D_801E7664, D_80101690, D_80101690, 1, FIELD(s32, &D_801EAB48, (D_801E7586 * 4)), 1);
        func_80145680(TEXT_FONT_ALTERNATE);
        menuY += 0x1E;
        if (((&D_801E7664)[1] == 0) && !(D_80201004 & 4)) {
            itemAlpha = D_801E7664 / 2;
        } else {
            itemAlpha = D_801E7664;
        }
        func_801469E4(0xA0, menuY, 0xFF, 0xFF, 0xFF, itemAlpha, ((&D_801E7664)[1] != 0) ? D_80101698 : D_80101694, ((&D_801E7664)[1] != 0) ? D_801016A0 : D_8010169C, 1, FIELD(s32, &D_801EACE4, (D_801E7586 * 4)), 1);
        menuY += 0x14;
        if (D_801F8458 != 0) {
            if (((&D_801F845C)[(&D_801E7664)[1]] == 1) && !(D_80201004 & 4)) {
                itemAlpha = D_801E7664 / 2;
            } else {
                itemAlpha = D_801E7664;
            }
            labelRow = 1;
            if (*(D_801EAA55 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) == GAMEPLAY_SAVE_MODE_TIME_TRIAL) {
                labelRow = 4;
            }
            if ((D_801F844C >= 2) & (labelRow == 1)) {
                func_801D2150(labelBuf, &D_80101658, FIELD(s32, &D_801EACF0, (D_801E7586 * 4)), D_801F8448 + 1, D_801F844C);
            } else {
                { s32 *tb = &D_801EACE4; s32 r = labelRow * 12 + (s32)tb; func_801D2150(labelBuf, &D_801010C0, *(s32 *)(D_801E7586 * 4 + r)); }
            }
            func_801469E4(0xA0, menuY, 0xFF, 0xFF, 0xFF, itemAlpha, ((&D_801F845C)[(&D_801E7664)[1]] != 1) ? D_801016A8 : D_801016A4, ((&D_801F845C)[(&D_801E7664)[1]] != 1) ? D_801016B0 : D_801016AC, 1, (s32)labelBuf, 1);
            menuY += 0x14;
        }
        if (FIELD(u8, &D_801F8458, 1) != 0) {
            if (((&D_801F845C)[(&D_801E7664)[1]] == 2) && !(D_80201004 & 4)) {
                itemAlpha = D_801E7664 / 2;
            } else {
                itemAlpha = D_801E7664;
            }
            if (*(D_801EAA55 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) == GAMEPLAY_SAVE_MODE_TIME_TRIAL) {
                func_801469E4(0xA0, menuY, 0xFF, 0xFF, 0xFF, itemAlpha, ((&D_801F845C)[(&D_801E7664)[1]] != 2) ? D_801016B8 : D_801016B4, ((&D_801F845C)[(&D_801E7664)[1]] != 2) ? D_801016C0 : D_801016BC, 1, FIELD(s32, &D_801EADC8, (D_801E7586 * 4)), 1);
            } else {
                func_801469E4(0xA0, menuY, 0xFF, 0xFF, 0xFF, itemAlpha, ((&D_801F845C)[(&D_801E7664)[1]] != 2) ? D_801016C8 : D_801016C4, ((&D_801F845C)[(&D_801E7664)[1]] != 2) ? D_801016D0 : D_801016CC, 1, FIELD(s32, &D_801EACFC, (D_801E7586 * 4)), 1);
            }
            menuY += 0x14;
        }
        if (((&D_801F845C)[(&D_801E7664)[1]] == 3) && !(D_80201004 & 4)) {
            itemAlpha = D_801E7664 / 2;
        } else {
            itemAlpha = D_801E7664;
        }
        func_801469E4(0xA0, menuY, 0xFF, 0xFF, 0xFF, itemAlpha, ((&D_801F845C)[(&D_801E7664)[1]] != 3) ? D_801016D8 : D_801016D4, ((&D_801F845C)[(&D_801E7664)[1]] != 3) ? D_801016E0 : D_801016DC, 1, FIELD(s32, &D_801EAD08, (D_801E7586 * 4)), 1);

        /* Start button closes the pause menu immediately. */
        if ((FIELD(u8, &D_801FAAC9, (D_80202218 * 0x190)) != 0) && ((u32)(D_801E765C - 0xD) < 0x3DB)) {
            D_801E765C = 0x3E8;
            ((u8 *)&D_801E7660)[7] = 0;
            if (D_801E7650 != NULL) {
                FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
            }
            if (D_801E7654 != NULL) {
                FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
            }
        }

        /* A button confirms the highlighted option or Yes/No prompt. */
        if ((D_801FAAC6[D_80202218].f != 0) && ((u32)(D_801E765C - 0xD) < 0x3DB)) {
            func_801793DC(0xB5, 0x64, 0x80, 0x80);
            FIELD(u8, &D_801FAAF0, (D_80202218 * 0x190)) = 1;
            (&D_801E7664)[2] = 0;
            { typedef struct { u8 pad[0xE0]; s32 v; u8 pad2[0xAC]; } R190; ((R190 *)&D_801FAA90)[D_80202218].v = 0x1869F; }
            switch ((&D_801F845C)[*(u8 *)((s32)&D_801E7664 + 1)]) {
                case 1:
                    saveOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
                    if (D_801EAA55[saveOffset] == GAMEPLAY_SAVE_MODE_TIME_TRIAL) {
                        if ((&D_801E7664)[3] != 0) {
                            if ((&D_801E7664)[3] == 1) {
                                D_801E765C = 0x3E8;
                                D_80290190 = D_801E7500[D_801EAA55[saveOffset] * 4];
                                D_80290194 = 3;
                                func_80128DF8(GAMEPLAY_TRANSITION_RELOAD_LEVEL, 1, 0);
                                D_80299398 = 0;
                                D_80290188 = 0;
                                ((u8 *)&D_801E7660)[7] = 0;
                            } else {
                                ((u8 *)&D_801E7660)[7] = 0;
                                if (D_801E7650 != NULL) {
                                    FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
                                }
                                if (D_801E7654 != NULL) {
                                    FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
                                }
                            }
                        } else {
                            D_801E7650 = ((u8 *(*)(s32, s32, f32, f32, s32, s32))func_8014E9F4)(0x78, menuY - 0x28, 0.0f, 0.0f, 4, 1);
                            D_801E7654 = ((u8 *(*)(s32, s32, f32, f32, s32, s32))func_8014E9F4)(0xC8, menuY - 0x28, 0.0f, 0.0f, 5, 1);
                            ((u8 *)&D_801E7660)[7] = 1;
                        }
                    } else {
                        {
                            u8 **pp = &D_802900E0;
                            D_802900E0 = (u8 *)D_801F8454;
                            FIELD(s16, FIELD(u8 *, *pp, 84), 2) = 0x41;
                        }
                        warpState = FIELD(u8 *, D_801F8454, 84);
                        if (FIELD(s16, warpState, 20) != 0) {
                            *(Words3 *)((u8 *)warpState + 4) = *(Words3 *)((u8 *)D_801F8454 + 180);
                            warpState2 = FIELD(u8 *, D_801F8454, 84);
                            FIELD(f32, warpState2, 12) = FIELD(f32, warpState2, 12) + D_801016E4;
                        }
                        D_801E765C = 0x3E8;
                    }
                    break;
                case 0:
                    D_801E765C = 0x3E8;
                    break;
                case 2:
                    if ((&D_801E7664)[3] != 0) {
                        if ((&D_801E7664)[3] == 1) {
                            D_801E765C = 0x3E8;
                            func_80128DF8(0xD, 1, 0);
                            D_80290194 = 3;
                            ((u8 *)&D_801E7660)[7] = 0;
                        } else {
                            ((u8 *)&D_801E7660)[7] = 0;
                            if (D_801E7650 != NULL) {
                                FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
                            }
                            if (D_801E7654 != NULL) {
                                FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
                            }
                        }
                    } else {
                        D_801E7650 = ((u8 *(*)(s32, s32, f32, f32, s32, s32))func_8014E9F4)(0x78, menuY - 0x14, 0.0f, 0.0f, 4, 1);
                        D_801E7654 = ((u8 *(*)(s32, s32, f32, f32, s32, s32))func_8014E9F4)(0xC8, menuY - 0x14, 0.0f, 0.0f, 5, 1);
                        ((u8 *)&D_801E7660)[7] = 1;
                    }
                    break;
                case 3:
                    if ((&D_801E7664)[3] != 0) {
                        if ((&D_801E7664)[3] == 1) {
                            D_801E765C = 0x3E8;
                            func_80128DF8(GAMEPLAY_TRANSITION_EXIT_MENU, 1, 0);
                            D_801E765C = 0;
                            D_801EC7D3 = 0;
                            D_801EC7D2 = 0;
                            ((u8 *)&D_801E7660)[7] = 0;
                            D_802004E0 = 0;
                            D_801E747C = 0;
                            return;
                        } else {
                            ((u8 *)&D_801E7660)[7] = 0;
                            if (D_801E7650 != NULL) {
                                FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7650, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
                            }
                            if (D_801E7654 != NULL) {
                                FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) = FIELD(u8, D_801E7654, SCREEN_PARTICLE_FLAGS_OFFSET) & ~SCREEN_PARTICLE_HOLD_LIFETIME;
                            }
                        }
                    } else {
                        D_801E7650 = ((u8 *(*)(s32, s32, f32, f32, s32, s32))func_8014E9F4)(0x64, menuY, 0.0f, 0.0f, 4, 1);
                        D_801E7654 = ((u8 *(*)(s32, s32, f32, f32, s32, s32))func_8014E9F4)(0xDC, menuY, 0.0f, 0.0f, 5, 1);
                        ((u8 *)&D_801E7660)[7] = 1;
                    }
                    break;
            }
        }

        /* Advance open/close frame timer and run closing fade/shrink animation. */
        if ((u32)(D_801E765C - 0x64) >= 0x384) {
            D_801E765C += 1;
        }
        if ((u32)(D_801E765C - 0x3E8) < 7) {
            D_801E7664 = D_801E7664 - 0x2A;
        }
        if (D_801E765C >= 0x3EF) {
            /* Both menu sprites go through a pointer to their sub-object at +0xC: only x is reached through the register, the
               other fields fold to direct addresses. Keep the statements on one line (mfhi hazard nops). */
            { typedef struct { f32 x; f32 y; s32 unk8; s32 unkC; s32 unk10; } Sub; Sub *pa; Sub *pb; pa = (Sub *)&D_802AA72C; pa->unkC -= 0xE9; pa->x += D_801016E8; pa->y += D_801016EC; closeBoxHeight = (D_801F8460 << 7) + 0x200; pb = (Sub *)&D_802AA834; pb->unkC -= 0x3A5; pb->x += D_801016E8; pb->y += D_801016EC; D_801E7664 = 0; D_801F21A1 = 0; pa->unk10 -= closeBoxHeight / 6; pb->unk10 -= (closeBoxHeight * 4) / 6; }
            func_8012C2B0(D_801F2198, 0xFF, CHEAT_INPUT_LENGTH);
        }
        if (D_801E765C == 0x3F4) {
            D_801EC7D3 = 0;
            D_801EC7D2 = 0;
            func_8014AAB8((ObjectNode *)D_802AA720);
            func_8014AAB8((ObjectNode *)D_802AA828);
            D_801E765C = 0;
        }

        /* Navigate vertical pause menu or bob/toggle Yes/No confirmation cursors. */
        if ((&D_801E7664)[3] == 0) {
            stickY = FIELD(s16, &D_801FAA92, (D_80202218 * 0x190));
            if (stickY >= 0x33) {
                if (((&D_801E7664)[2] == 0) && ((&D_801E7664)[1] != 0)) {
                    (&D_801E7664)[1] = (&D_801E7664)[1] - 1;
                    func_801793DC(0xB3, 0x64, 0x80, 0x80);
                }
                (&D_801E7664)[2] = 1;
            } else if (stickY < -0x32) {
                if (((&D_801E7664)[2] == 0) && ((&D_801E7664)[1] < (D_801F8460 - 1))) {
                    (&D_801E7664)[1] = (&D_801E7664)[1] + 1;
                    func_801793DC(0xB3, 0x64, 0x80, 0x80);
                }
                (&D_801E7664)[2] = 1;
            } else {
                (&D_801E7664)[2] = 0;
            }
        } else {
            if (D_801E7650 != NULL) {
                FIELD(f32, D_801E7650, 16) = menuY + (func_80149724(D_801016F0, D_80201004 / 2, 0) * D_801016F4);
            }
            if (D_801E7654 != NULL) {
                FIELD(f32, D_801E7654, 16) = menuY + (func_80149724(D_801016F8, D_80201004 / 2, 0) * D_801016FC);
            }
            if ((&D_801F845C)[(&D_801E7664)[1]] == 2) {
                if (D_801E7650 != NULL) {
                    FIELD(f32, D_801E7650, 16) = FIELD(f32, D_801E7650, 16) - D_80101700;
                }
                if (D_801E7654 != NULL) {
                    FIELD(f32, D_801E7654, 16) = FIELD(f32, D_801E7654, 16) - D_80101704;
                }
            }
            if ((&D_801F845C)[(&D_801E7664)[1]] == 1) {
                if (D_801E7650 != NULL) {
                    FIELD(f32, D_801E7650, 16) = FIELD(f32, D_801E7650, 16) - D_80101708;
                }
                if (D_801E7654 != NULL) {
                    FIELD(f32, D_801E7654, 16) = FIELD(f32, D_801E7654, 16) - D_8010170C;
                }
            }
            if ((&D_801E7664)[3] == 2) {
                if (D_801E7650 != NULL) {
                    FIELD(f32, D_801E7650, 12) = D_80101710;
                }
                if (D_801E7654 != NULL) {
                    FIELD(f32, D_801E7654, 12) = D_80101714;
                }
            }
            if ((&D_801E7664)[3] == 1) {
                if (D_801E7650 != NULL) {
                    FIELD(f32, D_801E7650, 12) = D_80101718;
                }
                if (D_801E7654 != NULL) {
                    FIELD(f32, D_801E7654, 12) = D_8010171C;
                }
            }
            ctrlOffLeft = D_80202218 * 0x190;
            if (((FIELD(s16, &D_801FAA90, ctrlOffLeft) >= 0x33) || (FIELD(s16, &D_801FAA92, ctrlOffLeft) < -0x32)) && ((&D_801E7664)[3] == 1)) {
                ((u8 *)&D_801E7660)[7] = 2;
                func_801793DC(0xB3, 0x64, 0x80, 0x80);
            }
            ctrlOffRight = D_80202218 * 0x190;
            if (((FIELD(s16, &D_801FAA90, ctrlOffRight) < -0x32) || (FIELD(s16, &D_801FAA92, ctrlOffRight) >= 0x33)) && ((&D_801E7664)[3] == 2)) {
                ((u8 *)&D_801E7660)[7] = 1;
                func_801793DC(0xB3, 0x64, 0x80, 0x80);
            }
        }
        func_80145680(TEXT_FONT_NORMAL);
    }
#undef FIELD
}

s32 func_8012801C(void) {
    /* Save level results and report whether every Garib was collected. */
    struct Col { s16 time; u8 initial0, initial1, initial2, terminator; };
    extern s32 D_801E693C[][14];
    extern struct Col D_801E6790[];
    extern f32 D_801F94CC;
    extern s32 D_80299394;
    extern s32 D_80290188;
    extern u8 D_801FA9A8;
    ScalarS8 *completedLevel = (ScalarS8 *)&D_801E7532;
    s32 collectedAllGaribs = 0;

    if ((f32)D_801E6790[D_801E693C[completedLevel->value][0]].time > D_801F94CC) {
        if (!(D_801E7584 & LEVEL_RESULT_COMPLETED)) {
            goto saveProgress;
        }
        { s16 *bestTime = &D_801E6790[D_801E693C[completedLevel->value][0]].time; *bestTime = D_801F94CC; }
        D_801E6790[D_801E693C[completedLevel->value][0]].initial0 = D_801FA9A8;
        D_801E6790[D_801E693C[completedLevel->value][0]].initial1 = D_801FA9A9;
        D_801E6790[D_801E693C[completedLevel->value][0]].initial2 = D_801FA9AA;
    }
    if (D_801E7584 & LEVEL_RESULT_COMPLETED) {
        s32 saveSlotOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
        *(s32 *)(D_801EAA48 + saveSlotOffset) |= 1 << D_801E693C[completedLevel->value][0];
        if (D_8029018C >= D_80299398 && D_80299398 > 0) {
            *(s32 *)(D_801EAA4C + saveSlotOffset) |= 1 << D_801E693C[completedLevel->value][0];
            collectedAllGaribs = 1;
        }
    }
saveProgress:
    D_80299394 = D_80299398;
    D_80299398 = 0;
    {
        s32 scoreSlotOffset = D_801EAB24 * LEVEL_SAVE_SLOT_BYTES;
        *(s32 *)((u8 *)&D_801EAA50 + scoreSlotOffset) = D_80290188 + D_8029018C * LEVEL_GARIB_SCORE;
    }
    func_801335A8(collectedAllGaribs);
    func_80132C04();
    func_80132B5C();
    func_80132DA8();
    return collectedAllGaribs;
}

void func_801282BC(void) {
    /* Initialize the 3D menu scene and dispatch controller input each frame. */
    extern s32 D_801E747C;
    extern s16 D_801EC7E0;
    extern s16 D_801E7668;
    extern s16 D_801E766A;
    extern u8 D_801EC7D8;
    extern u8 D_80202218;
    extern struct { u8 f; u8 pad[399]; } D_801FAAC8[];
    extern struct { s16 f; u8 pad[398]; } D_801FAA92[];
    extern u8 D_80101720[];
    extern s32 D_8028FAC8;
    void func_8011D88C(s32);
    void func_8014F510(s32);
    void func_80155AE4(void *);
    void func_80125040();
    void func_8010F9C0(s32 *);
    ObjectNode *sprite[2];
    ObjectNode *nextSprite;
    ObjectNode *spriteListHead;
    s32 inputCommand = MENU_INPUT_NONE;
    u16 savedFieldOfView;
    s16 stickY;
    s32 stickMagnitude;

    if (D_801E747C == 0) {
        D_80201004 = 0;
        D_802004E0 = 0;
        func_8014A9D8();
        func_80188F90();
        func_80188FB4();
        func_801A6820();
        func_8014ABEC();
        func_8015C758();
        func_801A8E30();
        func_801B4010();
        func_8018A9D0();
        func_80179EAC();
        func_801B9140();
        func_80179EAC();
        func_8018E6F8();
        func_8018E5F0();
        func_8018B3D8();
        func_8012ACC0();
        func_8018B3B8();
        func_801BAF6C();
        func_801B87C4();
        func_801B7B40();
        func_801779F0();
        func_8014A9FC();
        D_8028FAC8 = (s32)&D_801ED3C4;
        func_8011D88C(SCENE_MENU_LEVEL);
        D_801ED403 = 0;
        func_8014D548();
    }
    if (D_802004E0 >= SCENE_MENU_DRAW_START_FRAME) {
        func_80155AE4(D_80101720);
    }
    func_80125040();
    if (D_801E747C == 0) {
        savedFieldOfView = D_801EC7DE;
        D_801EC7E0 = SCENE_MENU_FIELD_OF_VIEW;
        D_801EC7DE = SCENE_MENU_FIELD_OF_VIEW;
        *(u8 *)&D_801ED400 = SCENE_MENU_FOG_RED;
        *(u8 *)&D_801ED401 = SCENE_MENU_FOG_GREEN;
        *(u8 *)&D_801ED402 = SCENE_MENU_FOG_BLUE;
        D_801ED403 = 1;
        D_801EC7DA = SCENE_MENU_FAR_CLIP;
        D_801E7668 = savedFieldOfView;
        func_8014F510(MENU_TEXTURE_BANK);
        sprite[0] = D_8028F350.next;
        if (sprite[0] != (ObjectNode *)((u8 *)&D_8028F354 - 4)) {
            spriteListHead = (ObjectNode *)((u8 *)&D_8028F354 - 4);
            do {
                nextSprite = sprite[0]->next;
                func_80141720((s32 *)sprite);
                sprite[0] = nextSprite;
            } while (nextSprite != spriteListHead);
        }
        func_8014A9FC();
        func_8014D548();
        func_80145680(SCENE_MENU_ALTERNATE_FONT);
    }
    D_801E747C++;
    if (D_801EC7D8 == 0) {
        inputCommand = MENU_INPUT_NONE;
        if (D_801FAAC6[D_80202218].f != 0 || D_801FAAC7[D_80202218 * SCENE_MENU_CONTROLLER_STRIDE] != 0 || D_801FAAC9[D_80202218 * SCENE_MENU_CONTROLLER_STRIDE] != 0) {
            inputCommand = MENU_INPUT_CONFIRM;
        }
        if (D_801FAAC8[D_80202218].f != 0) {
            inputCommand = MENU_INPUT_CANCEL;
        }
        if (D_801E766A == 0) {
            if (D_801FAA92[D_80202218].f != 0) {
                stickMagnitude = D_801FAA92[D_80202218].f;
                if (stickMagnitude < 0) {
                    stickMagnitude = -stickMagnitude;
                }
                if (stickMagnitude > MENU_STICK_THRESHOLD) {
                    D_801E766A = SCENE_MENU_STICK_REPEAT_DELAY;
                }
                stickY = D_801FAA92[D_80202218].f;
                if (stickY > MENU_STICK_THRESHOLD) {
                    inputCommand = MENU_INPUT_UP;
                } else if (stickY < -MENU_STICK_THRESHOLD) {
                    inputCommand = MENU_INPUT_DOWN;
                }
            }
        } else {
            D_801E766A = D_801E766A - 1;
        }
        func_8010F9C0(&inputCommand);
    }
}

/* Three-option select screen: sets up three models on the first frame, moves the selection (D_801E7586) with the stick, spins the selected model and eases the others back, and leaves on a button press or after 400 frames. */
void func_8012860C(void)
{
  extern s32 D_80000300;
  extern s32 D_801E7678;
  extern u8 D_801E7674;
  extern f32 D_801E766C;
  extern f32 D_801E7670;
  extern u8 *D_801F6098;
  extern u8 D_801EC749;
  extern u8 D_801F9370[];
  extern s8 D_801E7530;
  extern u8 D_80202218;
  extern struct 
  {
    s16 f;
    u8 pad[398];
  } D_801FAA90[];
  extern char D_80101728[];
  extern char D_80101730[];
  extern char D_8010173C[];
  extern char D_80101748[];
  extern u8 D_80101754[];
  extern s32 D_8010127C[];
  extern const f32 D_80101760;
  extern const f32 D_80101764;
  extern const f32 D_80101768;
  extern const f32 D_8010176C;
  extern const f64 D_80101770;
  extern const f32 D_80101778;
  extern const f32 D_80101780;
  void func_8010EEF8(char *, f32, f32, f32, s32, f32, s32, f32, f32, f32, s32);
  f32 func_80149724(f32, f32, s32);
  void func_8014AA20(ObjectNode *);
  void func_8014F510(s32);
  void func_8014E760(void);
  void func_8014ED2C(void);
  void func_80155AE4(void *);
  void func_801C066C(s32, s32);
  float zero_init;
  s32 func_801399EC(u8);
  void func_8014D4D0(void);
  s32 func_801793DC(s32, u8, u8, u8);
  void func_8010F94C(void);
  void func_8012BEE0(void);
  s32 item;
  u8 *model;
  s16 stick_x;
  f32 zero;
  zero_init = 0.0f;
  if (D_80000300 != 0)
  {
    D_801E7586 = 0;
    goto reset;
  }
  if (D_802004E0 == 0)
  {
    D_801E7678 = 0;
    D_801E7586 = 0;
    func_80155A44((s32 *) D_80101728);
    func_8014F510(0);
    func_8014F510(2);
    func_8014E760();
    func_8014D548();
    func_80150EA4(0x46);
    func_8010EEF8(D_80101730, 400.0f, D_80101760, D_80101764, 0, D_80101768, 0, D_8010176C, D_8010176C, D_8010176C, 0xFF);
    func_8010EEF8(D_8010173C, 100.0f, D_80101760, D_80101764, 0, D_80101768, 0, D_8010176C, D_8010176C, D_8010176C, 0xFF);
    func_8010EEF8(D_80101748, D_80101760, D_80101760, D_80101764, 0, D_80101768, 0, D_8010176C, D_8010176C, D_8010176C, 0xFF);
    for (item = 0; item < 3; item++)
    {
      func_80142700(D_80269F40[item], 4);
      *((f32 *) (D_80269F40[item] + 0xBC)) = D_8010176C;
      *((f32 *) (D_80269F40[item] + 0xC0)) = D_8010176C;
      *((f32 *) (D_80269F40[item] + 0xC4)) = D_8010176C;
      func_80133998(D_80269F40[item], 0, 1, 0, 0);
      *((f32 *) ((*((u8 **) (D_80269F40[item] + 0xDC))) + 0x4C)) = item * 10;
    }

    D_801F6098 = func_8013FCDC(0x70, 1, D_8010127C);
    D_801F6098[0x6C] = (D_801F6098[0x6D] = (D_801F6098[0x6E] = (D_801F6098[0x6F] = 0xFF)));
    func_8014AA20((ObjectNode *) D_801F6098);
    func_8014FCF8(D_801F6098 + 0x48, func_80139CA0(D_80101754), 1);
    *((s16 *) (D_801F6098 + 0x58)) = 0x400;
    *((s16 *) (D_801F6098 + 0x5A)) = 0x400;
    D_801ED400 = 0;
    D_801ED401 = 0;
    D_801ED402 = 0;
    func_80155AE4(D_80101728);
    func_801C066C(1, 0x55F0);
  }
  func_8014ED2C();
  if (D_801E7678 < 1000)
  {
    if ((D_802004E0 > 400) || func_801399EC(D_80202218))
    {
      D_801E7678 = 1000;
      func_8014D4D0();
      func_801793DC(0xD8, 0x80, 0x78, 0x78);
    }
  }
  stick_x = D_801FAA90[D_80202218].f;
  if (stick_x > 50)
  {
    if (D_801E7674 == 0)
    {
      s16 *selection = &D_801E7586;
      s32 current = *selection;
      D_801E7674 = 5;
      if (current < 2)
      {
        (*selection)++;
        func_801793DC(0xD4, 0x80, 0x78, 0x78);
      }
    }
  }
  else
    if (stick_x < (-50))
  {
    if (D_801E7674 == 0)
    {
      s16 *selection = &D_801E7586;
      s32 current = *selection;
      D_801E7674 = 5;
      if (current > 0)
      {
        (*selection)--;
        func_801793DC(0xD4, 0x80, 0x78, 0x78);
      }
    }
  }
  else
  {
    D_801E7674 = 0;
  }
  if (D_801E7674 != 0)
  {
    D_801E7674--;
  }
  zero = zero_init;
  for (item = 0; item < 3; item++)
  {
    if (item == D_801E7586)
    {
      f32 frame = D_802004E0;
      *((s16 *) (D_80269F40[item] + 0x26)) = 100;
      *((f32 *) (D_80269F40[item] + 0x80)) = func_80149724(*((const f32 *) (&D_801E766C)), frame, 0) / D_801E7670;
    }
    else
    {
      *((s16 *) (D_80269F40[item] + 0x26)) = 50;
      model = D_80269F40[item];
      if (func_8014944C(*((f32 *) (model + 0x80)), zero) <= (*((f64 *) (((u8 *) (&D_80101780)) + 4))))
      {
        *((f32 *) (model + 0x80)) = zero;
      }
      else
        if ((*((f32 *) (model + 0x80))) < zero)
      {
        if ((-(*((f32 *) (model + 0x80)))) > D_80101770)
        {
          *((f32 *) (model + 0x80)) -= ((func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) < (*((const f64 *) (((u8 *) (&D_80101778)) + 4)))) ? (func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) : (*((const f64 *) (((u8 *) (&D_80101778)) + 4)));
        }
        else
        {
          *((f32 *) (model + 0x80)) += ((func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) < (*((const f64 *) (((u8 *) (&D_80101778)) + 4)))) ? (func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) : (*((const f64 *) (((u8 *) (&D_80101778)) + 4)));
        }
      }
      else
        if ((*((f32 *) (model + 0x80))) > zero)
      {
        if ((*((f32 *) (model + 0x80))) > D_80101770)
        {
          *((f32 *) (model + 0x80)) += ((func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) < (*((const f64 *) (((u8 *) (&D_80101778)) + 4)))) ? (func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) : (*((const f64 *) (((u8 *) (&D_80101778)) + 4)));
        }
        else
        {
          *((f32 *) (model + 0x80)) -= ((func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) < (*((const f64 *) (((u8 *) (&D_80101778)) + 4)))) ? (func_8014944C(*((f32 *) (model + 0x80)), zero) / D_80101778) : (*((const f64 *) (((u8 *) (&D_80101778)) + 4)));
        }
      }
    }
  }

  {
    s32 obj;
    for (obj = 0; obj < D_801EC860; obj++)
    {
      func_8015C350(D_80269F40[obj] + 0x9C, D_80269F40[obj] + 0x78);
    }
  }

  D_802004E0++;
  D_80201004++;
  if ((D_801E7678 < 100) || (D_801E7678 >= 1000))
  {
    D_801E7678++;
  }
  if ((D_801E7678 != 0x3F2) && (D_801EC749 != 0))
  {
    return;
  }
  if (D_80000300 != 0)
  {
    D_801E7586 = 0;
  }
  for (item = 0; item < 3; item++)
  {
    func_8014AAB8(D_801F9370 + (item * 0x74));
  }

  func_8010F94C();
  func_8011CAF8();
  func_80141720((s32 *) (&D_801F6098));
  reset:
  D_801E7530 = 1;

  D_80201004 = 0;
  D_802004E0 = 0;
  func_8012BEE0();
}

/* world_bonus_level_unlocked: whether the current world's (D_801E7533) bonus
 * level is open: always with the cheat flag; otherwise only on Normal
 * difficulty (D_801EAA55), once the bonus level was already completed
 * (D_801EAA48) or all Garibs were collected in the world's three levels
 * (D_801EAA4C) of the selected save slot (D_801EAB24). */
s32 func_80128D34(void) {
    s32 unlocked = 0;
    s32 worldShift;
    s32 allGaribsMask;

    if (D_80297BEC & GAME_OPTION_ALL_BONUS_LEVELS) {
        unlocked = 1;
    } else if (D_801EAA55[D_801EAB24 * LEVEL_SAVE_SLOT_BYTES] != 0) {
        worldShift = (D_801E7533 - 1) * WORLD_PROGRESS_BITS;
        if ((*(s32 *)&D_801EAA48[D_801EAB24 * LEVEL_SAVE_SLOT_BYTES] >> (worldShift + WORLD_BONUS_BIT)) & 1) {
            unlocked = 1;
        } else {
            allGaribsMask = *(s32 *)&D_801EAA4C[D_801EAB24 * LEVEL_SAVE_SLOT_BYTES];
            if ((allGaribsMask >> worldShift) & 1) {
                if ((allGaribsMask >> (worldShift + WORLD_LEVEL2_BIT)) & 1) {
                    if ((allGaribsMask >> (worldShift + WORLD_LEVEL3_BIT)) & 1) {
                        unlocked = 1;
                    }
                }
            }
        }
    }
    return unlocked;
}

extern f64 D_80101788;
extern f32 D_80101794;
extern s32 D_80000300;
extern s32 D_80290198;
extern f32 D_801F94CC;
extern u8 D_801E7541;
extern u8 D_801EC7D2;
extern s32 D_80290188;
extern s32 D_801E746C;

/*
 * Request a game-state transition to `nextState` (D_801E7541). Ignored while
 * one is already pending (D_801E7584 bit 0), except for state 0xF, which also
 * records the score D_80290188 in the high-score table (func_8012A77C).
 * `success` sets bit 1 of D_801E7584; `stopFrameCounter` sets D_801EC7D2.
 * Starts the fade out (func_8014D4D0) unless D_801E753E is set, and converts
 * the duration D_80290198 (ms) to frames with the TV type's frame period
 * (D_80000300 = osTvType: 1000/60 = 16.67 or 1000/50 = 20.0).
 */
void func_80128DF8(s32 nextState, s32 stopFrameCounter, s32 success) {
    u8 flags = *(u8 *)&D_801E7584;
    s32 notPending = (flags ^ 1) & 1;
    s32 isState15 = nextState == 0xF;

    if (notPending | isState15) {
        *(u8 *)&D_801E7584 = flags | 1;
        if (success != 0) {
            *(u8 *)&D_801E7584 = flags | 3;
        }
        D_801E7541 = nextState;
        if (D_801E753E == 0) {
            func_8014D4D0();
        }
        D_801E746C = 0;
        if (D_80000300 == 0) {
            D_801F94CC = (f32)D_80290198 / *(f64 *)((u8 *)&D_80101788 + 4);
        } else {
            D_801F94CC = (f32)D_80290198 / D_80101794;
        }
        if (stopFrameCounter != 0) {
            D_801EC7D2 = 1;
        }
        if (nextState == 0xF) {
            func_8012A77C(D_80290188);
        }
    }
}

/* Returns 1 when the current level (D_801E7531) is one of levels 14, 19, 24,
 * 29, 34 or 41, which leave immediately when a life is lost; 0 otherwise. */
s32 func_80128F0C(void) {
    s8 level = D_801E7531;
    s32 isInstantExit = 0;

    if (level == 14 || level == 19) {
        isInstantExit = 1;
    } else if (level == 24 || level == 29) {
        isInstantExit = 1;
    } else if (level == 34 || level == 41) {
        isInstantExit = 1;
    }
    return isInstantExit;
}

void func_80128F74(void) {
    /* Cutscene effects driven by the first object's animation frame: sparks, smoke, a homing
       magic orb (D_801F8468) that spirals into D_801E76B0, and when the animation ends a flash
       that fades the screen to white (D_801F8478) before handing over to func_801230A8. */
    extern s16 D_801E7468;
    extern s32 D_802004E0;
    extern ObjectNode D_8028F350;
    extern u8 D_8028F8E0[];
    extern u8 D_802892D8[];
    extern s32 D_8010127C[];
    extern s8 D_801ED400;
    extern s8 D_801ED401;
    extern s8 D_801ED402;
    extern s32 D_801ED3C4;
    extern u8 *D_801F8468;
    extern s32 D_801E768C;
    extern u8 *D_801F8478;
    extern Vec3F D_801F846C;
    extern s16 D_801E767C;
    extern f32 D_801E7680;
    extern f32 D_801E7684;
    extern f32 D_801E7688;
    extern u8 D_8028D7E0;
    extern u8 D_8028D7E1;
    extern u8 D_8028D7E2;
    extern u8 D_80101798[];
    extern const f32 D_801017A4;
    extern const f32 D_801017A8;
    extern const f32 D_801017AC;
    extern const f32 D_801017B0;
    extern const f32 D_801017B4;
    extern const f32 D_801017B8;
    extern const f32 D_801017BC;
    extern const f32 D_801017C0;
    extern const f32 D_801017C4;
    extern const f32 D_801017C8;
    extern const f32 D_801017CC;
    extern const f32 D_801017D0;
    extern const f32 D_801017D4;
    extern const f32 D_801017D8;
    extern const f32 D_801017DC;
    extern const f32 D_801017E0;
    extern const f32 D_801017E4;
    extern const f32 D_801017E8;
    extern const f32 D_801017EC;
    extern const f32 D_801017F0;
    extern const f32 D_801017F4;
    extern const f64 D_801017F8;
    extern const f64 D_80101800;
    extern const f64 D_80101808;
    extern const f64 D_80101810;
    extern const f64 D_80101818;
    extern const f32 D_80101820;
    extern const f32 D_80101824;
    f32 sqrtf(f32);
    s32 func_80147000(s32);
    void func_8014AA20(ObjectNode *);
    void func_8014D61C(s32, s32, s32, s32, s32);
    void func_80149568(f32 *);
    void func_801499EC();
    void func_801A41B4(Vec3F *, Vec3F *, s16, f32, f32);
    u8 *func_801AA5BC(s16);
    void func_801A96A8();
    void func_801A8E54();
    void func_801A8EF8();
    void func_801AE348(u8 *);
    Vec3F vec;
    f32 toTarget[4];
    ObjectNode *node;
    ObjectNode *next;
    ObjectNode *head;
    ObjectNode *object;
    u8 *particle;
    s32 alpha;
    s32 i;
    s32 width;
    s32 height;
    f64 scaled;
    f32 frame;

    if (D_801E7468 != 0) {
        func_801230A8();
        return;
    }
    if (D_802004E0 == 1) {
        D_801F8468 = NULL;
        D_801E768C = 0;
    }
    if (D_801E768C != 0) {
        D_801E768C++;
        if (D_801E768C < 4) {
            *(u8 *)&D_801ED402 = 0xFF;
            *(u8 *)&D_801ED401 = 0xFF;
            *(u8 *)&D_801ED400 = 0xFF;
            D_8028D7E2 = 0xFF;
            D_8028D7E1 = 0xFF;
            D_8028D7E0 = 0xFF;
            for (object = D_8026A148.next; object != &D_8026A148; object = object->next) {
                if (object != (ObjectNode *)D_8028F8E0) {
                    *(f32 *)&object->posY = D_801017A4;
                }
            }
            *(f32 *)(*(u8 **)D_802892D8 + 0x10) = D_801017A8;
            D_801F8478 = func_8013FCDC(0x70, 1, D_8010127C);
            func_8014FCF8(D_801F8478 + 0x48, func_80139CA0(D_80101798), 1);
            D_801F8478[0x6C] = D_801F8478[0x6D] = D_801F8478[0x6E] = 0xFF;
            *(s16 *)(D_801F8478 + 0x5A) = *(s16 *)(D_801F8478 + 0x58) = 0x400;
            node = D_8028F350.next;
            if (node != (ObjectNode *)((u8 *)&D_8028F354 - 4)) {
                head = (ObjectNode *)((u8 *)&D_8028F354 - 4);
                do {
                    next = node->next;
                    func_80141720((s32 *)&node);
                    node = next;
                } while (next != head);
            }
            func_8014A9FC();
            func_8014AA20((ObjectNode *)D_801F8478);
        }
        {
            u8 *flash = D_801F8478;

            alpha = D_801E768C * 30;
            if (alpha > 0xFF) {
                alpha = 0xFF;
            }
            flash[0x6F] = alpha;
        }
        if (D_801F8478[0x6F] == 0xFF) {
            D_801E7468 = 1;
            D_801E768C = 0;
        }
        return;
    }
    if (D_8026A148.next != NULL && D_8026A148.next->unk0DC != 0 && *(s32 *)(D_8026A148.next->unk0DC + 4) != 0) {
        D_801E768C = 1;
        *(u8 *)&D_801ED402 = 0xFF;
        *(u8 *)&D_801ED401 = 0xFF;
        *(u8 *)&D_801ED400 = 0xFF;
        D_8028D7E2 = 0xFF;
        D_8028D7E1 = 0xFF;
        D_8028D7E0 = 0xFF;
    }
    frame = *(f32 *)(D_8026A148.next->unk0DC + 0x4C);
    if ((D_801017AC < frame) & (frame < D_801017B0)) {
        vec.x = *(f32 *)(D_801E76B0 + 0xC) - *(f32 *)(D_801E76B0 + 0x0);
        vec.y = *(f32 *)(D_801E76B0 + 0x10) - *(f32 *)(D_801E76B0 + 0x4);
        vec.z = *(f32 *)(D_801E76B0 + 0x14) - *(f32 *)(D_801E76B0 + 0x8);
        if (func_80147000(30) < 20) {
            func_801A41B4((Vec3F *)D_801E76B0, &vec, 6, 3.0f, D_801017B4);
        } else {
            func_801A41B4((Vec3F *)D_801E76B0, &vec, 0x11, 2.0f, D_801017B8);
        }
    }
    if ((D_801017BC <= frame) & (frame < D_801017C0)) {
        func_801B70F8(D_801E76B0, 4, 0.0f, 2.0f);
    }
    if ((D_801017C4 < frame) & (frame < D_801017C8) && (D_802004E0 & 1)) {
        vec = *(Vec3F *)D_801E76B0;
        vec.y -= D_801017CC;
        vec.x += func_80147000(9) - 4;
        vec.z += func_80147000(9) - 4;
        func_801B66D4(0, &vec, &D_801ED3C4, 0, 0);
    }
    if (D_801E767C <= frame && frame < D_801E767C + 1) {
        func_8014D61C(0xFF, 0xFF, 0, 0xFF, -0x1E);
        D_801F8468 = func_801AA5BC(7);
        *(Vec3F *)(D_801F8468 + 0x3C) = *(Vec3F *)(D_801E76B0 + 0x24);
        *(f32 *)(D_801F8468 + 0x60) = *(f32 *)(D_801E76B0 + 0x0) - *(f32 *)(D_801F8468 + 0x3C);
        *(f32 *)(D_801F8468 + 0x64) = *(f32 *)(D_801E76B0 + 0x4) - *(f32 *)(D_801F8468 + 0x40);
        *(f32 *)(D_801F8468 + 0x68) = *(f32 *)(D_801E76B0 + 0x8) - *(f32 *)(D_801F8468 + 0x44);
        func_80149568((f32 *)(D_801F8468 + 0x60));
        *(f32 *)(D_801F8468 + 0x60) *= D_801017D0;
        *(f32 *)(D_801F8468 + 0x64) *= D_801017D0;
        *(f32 *)(D_801F8468 + 0x68) *= D_801017D0;
        func_801A96A8(D_801F8468, 0, 0);
        D_801F8468[0x109] = 0xFF;
        D_801F8468[0x10A] = 0x32;
        D_801F8468[0x10B] = 0x32;
        func_801A8E54(D_801F8468);
        vec.x = *(f32 *)(D_801F8468 + 0x3C) + *(f32 *)(D_801F8468 + 0x60);
        vec.y = *(f32 *)(D_801F8468 + 0x40) + *(f32 *)(D_801F8468 + 0x64);
        vec.z = *(f32 *)(D_801F8468 + 0x44) + *(f32 *)(D_801F8468 + 0x68);
        func_801AE348((u8 *)&vec);
        *(f32 *)(D_801F8468 + 0x60) = *(f32 *)(D_801F8468 + 0x64) = *(f32 *)(D_801F8468 + 0x68) = 0.0f;
        D_801F846C = *(Vec3F *)(D_801F8468 + 0x3C);
    }
    if (D_801F8468 != NULL) {
        toTarget[0] = *(f32 *)(D_801E76B0 + 0x0) - D_801F846C.x;
        toTarget[1] = *(f32 *)(D_801E76B0 + 0x4) - D_801F846C.y;
        toTarget[2] = *(f32 *)(D_801E76B0 + 0x8) - D_801F846C.z;
        if (sqrtf(toTarget[0] * toTarget[0] + toTarget[1] * toTarget[1] + toTarget[2] * toTarget[2]) < D_801E7684) {
            func_801B66D4(0xF, D_801F8468 + 0x3C, &D_801ED3C4, 0, 0);
            func_801B7764(D_801F8468 + 0x3C, 5, 0x13);
            func_801A8EF8(D_801F8468);
            D_801F8468 = NULL;
        } else {
            func_80149568(toTarget);
            vec.x = D_801017D4;
            vec.y = 0.0f;
            vec.z = 0.0f;
            toTarget[3] = D_802004E0 / D_801E7680;
            func_801499EC(&vec, &vec, toTarget);
            toTarget[0] *= D_801E7684;
            toTarget[1] *= D_801E7684;
            toTarget[2] *= D_801E7684;
            D_801F846C.x += toTarget[0];
            D_801F846C.y += toTarget[1];
            D_801F846C.z += toTarget[2];
            *(f32 *)(D_801F8468 + 0x3C) = D_801F846C.x + vec.x;
            *(f32 *)(D_801F8468 + 0x40) = D_801F846C.y + vec.y;
            *(f32 *)(D_801F8468 + 0x44) = D_801F846C.z + vec.z;
        }
    }
    if ((D_801017D8 < frame) & (frame < D_801017DC) && !(D_802004E0 & 1)) {
        if (frame < D_801017E0) {
            vec.x = (f32)(func_80147000(9) - 4) / D_801017E4;
            vec.y = D_801017E8;
            vec.z = (f32)(func_80147000(9) - 4) / D_801017E4;
        } else {
            vec.x = D_801017EC;
            vec.y = D_801017F0;
            vec.z = (f32)(func_80147000(9) - 4) / D_801017F4;
        }
        particle = (u8 *)func_801B66D4(1, D_801E76B0 + 0x24, &vec, 0, 0);
        if (particle != NULL) {
            *(f32 *)(particle + 0x38) += D_801E7688; *(f32 *)(particle + 0xF8) += D_801E7688; scaled = (f32)*(u16 *)(particle + 0x114) * D_801017F8; if (!(D_80101800 <= scaled)) { width = (s32)scaled; } else { width = (s32)(scaled - D_80101800) | 0x80000000; }
            *(u16 *)(particle + 0x114) = width;
            scaled = (f32)*(u16 *)(particle + 0x116) * D_80101808;
            if (!(D_80101810 <= scaled)) {
                height = (s32)scaled;
            } else {
                height = (s32)(scaled - D_80101810);
                height |= 0x80000000;
            }
            *(u16 *)(particle + 0x116) = height;
            particle[0x105] = 0xFF;
            particle[0x106] = 0xFF;
            particle[0x107] = 0xFF;
            particle[0x108] = 0xFF;
            particle[0x112] = 0xFF;
            particle[0x113] = 0x40;
            *(s16 *)(particle + 0x100) = (f32)*(s16 *)(particle + 0x100) * D_80101818;
            *(s16 *)(particle + 0x102) = (f32)*(s16 *)(particle + 0x102) * D_80101818;
        }
    }
    if (frame < D_80101820) {
        for (i = 2; i < 9; i++) {
            if (D_802004E0 & 1) {
                vec.x = *(f32 *)(D_801E76B0 + i * 0x24 + 0x0) + func_80147000(0x13) - D_80101824;
                vec.y = *(f32 *)(D_801E76B0 + i * 0x24 + 0x4) + func_80147000(0x13) - D_80101824;
                vec.z = *(f32 *)(D_801E76B0 + i * 0x24 + 0x8) + func_80147000(0x13) - D_80101824;
                func_801B66D4(0xA, &vec, &D_801ED3C4, 0, 0);
            }
        }
    }
}

void func_80129AFC(void) { /* Cutscene script: runs on the state frame counter (D_802004E0), showing timed captions, flashes, effects, a light fade and particles. */
    typedef struct {
        u8 b[8];
    } Bytes8;
    extern s16 D_801E76A4; /* frames left on the current caption */
    extern u8 *D_801F847C; /* current caption text object */
    extern u8 *D_801F8480[]; /* effects spawned on the player's animation frames */
    extern u8 *D_801F8484;
    extern u8 *D_801F8488;
    extern s32 D_801F848C; /* count of D_801F8480 */
    extern s16 D_801E743C; /* caption table: (animation frame, duration) pairs, 0-terminated */
    extern s16 D_801E743E[];
    extern s32 D_801EAC68[][3]; /* caption strings per language */
    extern s16 D_801E7586; /* language */
    extern s16 D_801EC7DA;
    extern u8 D_8028D7E0;
    extern u8 D_80101828[];
    extern u8 D_801E76A0; /* effect RGB */
    extern u8 D_801E76A1;
    extern u8 D_801E76A2;
    extern s32 D_801E7690; /* light fade first / last frame */
    extern s32 D_801E7694;
    extern f32 D_801E7698; /* light fade factor per frame */
    extern u8 D_802988B8;
    extern u8 D_802988B9;
    extern u8 D_802988BA;
    extern u8 D_802991A0[]; /* light list: ambient RGB, then a node list at +8 */
    extern u8 D_802991A4;
    extern u8 D_802991A5;
    extern u8 D_802991A6;
    extern u8 D_801F19C0;
    extern u8 D_801F19C1;
    extern u8 D_801F19C2;
    extern s32 D_801ED3C4; /* zero velocity */
    extern const f32 D_80101834;
    extern const f32 D_80101838;
    extern const f32 D_8010183C;
    extern const f32 D_80101840;
    extern const f32 D_80101844;
    extern const f32 D_80101848;
    extern const f32 D_8010184C;
    extern const f32 D_80101850;
    extern const f32 D_80101854;
    extern const f32 D_80101858;
    extern const f32 D_8010185C;
    extern const f32 D_80101860;
    extern const f32 D_80101864;
    extern const f32 D_80101868;
    extern const f32 D_8010186C;
    extern const f32 D_80101870;
    extern const f32 D_80101874;
    extern const f32 D_80101878;
    extern const f32 D_8010187C;
    extern const f32 D_80101880;
    extern const f32 D_80101884;
    extern const f32 D_80101888;
    s32 func_801A2944(f32, u8 *); /* animation_frame_crossed */
    void func_8014D61C(s32, s32, s32, s32, s32); /* screen_flash_start */
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); /* text_queue */
    void func_80145CEC(ObjectNode *);
    void func_80148CC8(f32 *, f32 *, f32 *, U32F32); /* vec3_add_scaled */
    s32 func_80147000(s32); /* random_below */
    u8 *func_801AA5BC(s16); /* effect_alloc_from_type */
    void func_801A96A8(); /* effect_init */
    void func_801A8E54(); /* effect_insert */
    void func_801A8EF8();
    void func_801AE348(u8 *);
    void func_801B7344(s32, s32, f32);
    u8 *player;
    u8 *effect;
    u8 *light;
    u8 *red;
    u8 *green;
    u8 *blue;
    u8 *red2;
    u8 *green2;
    u8 *blue2;
    Vec3F pos;
    s32 i;
    f32 scaled;
    f32 animFrame;
    u32 channel;

    player = (u8 *)D_8026A148.next;
    if (D_802004E0 < 2) {
        D_801E76A4 = 0;
        D_801F8488 = 0;
        D_801F8484 = 0;
        D_801F8480[0] = 0;
        D_801F848C = 0;
    }
    if (D_801E76A4 != 0) {
        if (D_801E76A4 < 10) {
            D_801F847C[0x5B] -= 25;
        }
        if (--D_801E76A4 == 0) {
            func_80145CEC((ObjectNode *)D_801F847C);
            return;
        }
    } else if (D_801E743C != 0) {
        i = 0;
        do {
            if (func_801A2944((&D_801E743C)[i * 2], player)) {
                func_8014D61C(0xFF, 0xFF, 0xFF, 0x118, 1);
                D_801F847C = func_801469E4(0xA0, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF, D_80101834, D_80101834, 0,
                                           D_801EAC68[i][D_801E7586], 1);
                D_801E76A4 = D_801E743E[i * 2] + 10;
            }
            i++;
        } while ((&D_801E743C)[i * 2] != 0);
    }
    if (func_801A2944(D_80101838, player) || func_801A2944(D_8010183C, player) || (func_801A2944(D_80101840, player))) {
        func_8014D61C(0xFF, 0, 0, 0xFF, 0);
    }
    if (func_801A2944(D_80101844, player)) {
        ((u8 *)&D_801ED400)[0] = 0xA4;
        ((u8 *)&D_801ED400)[1] = 0x10;
        ((u8 *)&D_801ED400)[2] = 2;
        *(s16 *)((u8 *)&D_801ED400 + 4) = 0x3D4;
        *(Bytes8 *)&D_8028D7E0 = *(Bytes8 *)&D_801ED400;
        D_801EC7DA = 0xBB8;
        func_8014FCF8(&D_8028F350.next->unk048, func_80139CA0(D_80101828), 1);
        *(s16 *)(D_8028F350.next->unk048 + 0xE) -= 1;
    }
    if ((u32)(D_802004E0 - 0x35C) < 0x11) {
        if (D_802004E0 == 0x36C) {
            for (i = 0; i < 3; i++) {
                func_801A8EF8(D_801F8480[i]);
            }
        } else {
            pos.x = D_80101848;
            pos.y = D_8010184C;
            pos.z = 0.0f;
            ((void (*)(f32 *, f32 *, f32 *, f32))func_80148CC8)((f32 *)(D_801F8480[0] + 0x3C),
                                                                (f32 *)(D_801E76B0 + 0x48), (f32 *)&pos,
                                                                (0x36B - D_802004E0) * 4);
        }
    }
    if ((u32)(D_802004E0 - 0x152) < 0x53 && !(D_802004E0 & 1)) {
        effect = func_801AA5BC(0x11);
        *(f32 *)(effect + 0x3C) = D_80101850;
        *(f32 *)(effect + 0x40) = D_80101854;
        *(f32 *)(effect + 0x44) = 0.0f;
        *(f32 *)(effect + 0x3C) += func_80147000(0x19) - 0xC;
        *(f32 *)(effect + 0x44) += func_80147000(0x19) - 0xC;
        *(f32 *)(effect + 0x60) = 0.0f;
        *(f32 *)(effect + 0x64) = func_80147000(4) + 4;
        *(f32 *)(effect + 0x68) = 0.0f;
        func_801A96A8(effect, 0, 0);
        { s32 r = func_80147000(0x38) - 990; *(s16 *)(effect + 0x118) = (D_802004E0 * 3 + r) / 2; }
        { s32 r = func_80147000(0x38) - 870; *(s16 *)(effect + 0x11A) = (D_802004E0 * 3 + r) / 2; }
        effect[0x109] = D_801E76A0 + func_80147000(0x28);
        effect[0x10A] = D_801E76A1;
        effect[0x10B] = D_801E76A2 + func_80147000(0x28);
        func_801A8E54(effect);
    }
    if (D_802004E0 == 0x280) {
        func_801B7344((s32)(D_801E76B0 + 0x24), 5, 1.0f);
    }
    if (D_802004E0 == 0x284) {
        func_801B7344((s32)(D_801E76B0 + 0x24), 3, 1.0f);
    }
    if (D_802004E0 == 0x1BD) {
        func_8014D61C(0xFF, 0x80, 0, 0xC8, 0);
        for (i = 0; i < 12; i++) {
            effect = func_801AA5BC(4);
            *(f32 *)(effect + 0x3C) = D_80101858;
            *(f32 *)(effect + 0x40) = D_8010185C;
            *(f32 *)(effect + 0x44) = 0.0f;
            *(f32 *)(effect + 0x60) = func_80147000(0xA) - 5;
            *(f32 *)(effect + 0x64) = func_80147000(4) + 7;
            *(f32 *)(effect + 0x68) = func_80147000(0xA) - 5;
            func_801A96A8(effect, 0, 0);
            *(s16 *)(effect + 0x118) = (func_80147000(0x100) + 0xD4) / 3; *(s16 *)(effect + 0x11A) = (func_80147000(0x38) + 0x100) / 3; *(s16 *)(effect + 0x150) = (func_80147000(0x100) + 0xD4) / 3; *(s16 *)(effect + 0x152) = (func_80147000(0x38) + 0x100) / 3; func_801A8E54(effect);
        }
    }
    if (D_802004E0 > D_801E7690 && D_802004E0 <= D_801E7694) {
        if (D_802004E0 == D_801E7694) {
            D_802991A0[0] = D_802991A4 = D_802988B8 = 0x6E;
            D_802991A0[1] = D_802991A5 = D_802988B9 = 0x6E;
            D_802991A0[2] = D_802991A6 = D_802988BA = 0x96;
            for (light = *(u8 **)(D_802991A0 + 8), i = 0; light != D_802991A0 + 8; light = *(u8 **)light, i++) {
                *(f32 *)(light + 0x20) = *(f32 *)(light + 0x2C) = D_80101860;
                *(f32 *)(light + 0x24) = *(f32 *)(light + 0x30) = D_80101860;
                *(f32 *)(light + 0x28) = *(f32 *)(light + 0x34) = i * 60 + 160;
            }
        } else {
            red = &D_802991A0[0];
            red2 = red + 4;
            scaled = *red * D_801E7698;
            if (!(D_80101864 <= scaled)) {
                channel = (s32)scaled;
            } else {
                channel = (s32)(scaled - D_80101864) | 0x80000000;
            }
            *red = *red2 = D_802988B8 = channel; green = &D_802991A0[1]; green2 = green + 4; scaled = *green * D_801E7698; if (!(D_80101868 <= scaled)) {
                channel = (s32)scaled;
            } else {
                channel = (s32)(scaled - D_80101868) | 0x80000000;
            }
            *green = *green2 = D_802988B9 = channel; blue = &D_802991A0[2]; blue2 = blue + 4; scaled = *blue * D_801E7698; if (!(D_8010186C <= scaled)) {
                channel = (s32)scaled;
            } else {
                channel = (s32)(scaled - D_8010186C) | 0x80000000;
            }
            *blue = *blue2 = D_802988BA = channel;
            for (light = *(u8 **)D_802991A8; light != D_802991A8; light = *(u8 **)light) {
                ((f32 *)light)[8] = ((f32 *)light)[11] = ((f32 *)light)[8] * D_801E7698;
                ((f32 *)light)[9] = ((f32 *)light)[12] = ((f32 *)light)[9] * D_801E7698;
                ((f32 *)light)[10] = ((f32 *)light)[13] = ((f32 *)light)[10] * D_801E7698;
            }
        }
    }
    if (func_801A2944(D_80101870, player) || func_801A2944(D_80101874, player) || (func_801A2944(D_80101878, player))) {
        D_801F8480[D_801F848C] = func_801AA5BC(0);
        ((s8 *)D_801F8480[D_801F848C])[0x162] = -1;
        ((s8 *)D_801F8480[D_801F848C])[0x163] = -1;
        *(Vec3F *)(D_801F8480[D_801F848C] + 0x3C) = *(Vec3F *)D_801E76B0;
        *(f32 *)(D_801F8480[D_801F848C] + 0x60) = *(f32 *)(D_801E76B0 + 0x0) - *(f32 *)(D_801E76B0 + 0x24);
        *(f32 *)(D_801F8480[D_801F848C] + 0x64) = *(f32 *)(D_801E76B0 + 0x4) - *(f32 *)(D_801E76B0 + 0x28);
        *(f32 *)(D_801F8480[D_801F848C] + 0x68) = *(f32 *)(D_801E76B0 + 0x8) - *(f32 *)(D_801E76B0 + 0x2C);
        *(f32 *)(D_801F8480[D_801F848C] + 0x3C) += *(f32 *)(D_801F8480[D_801F848C] + 0x60);
        *(f32 *)(D_801F8480[D_801F848C] + 0x40) += *(f32 *)(D_801F8480[D_801F848C] + 0x64);
        *(f32 *)(D_801F8480[D_801F848C] + 0x44) += *(f32 *)(D_801F8480[D_801F848C] + 0x68);
        func_801AE348(D_801F8480[D_801F848C] + 0x3C);
        func_801A96A8(D_801F8480[D_801F848C], 0, 0);
        D_801F8480[D_801F848C][0x109] = D_801F19C0;
        D_801F8480[D_801F848C][0x10A] = D_801F19C1;
        D_801F8480[D_801F848C][0x10B] = D_801F19C2;
        func_801A8E54(D_801F8480[D_801F848C]);
        D_801F848C++;
    }
    for (i = 3; i < 10; i++) {
        if (D_802004E0 & 1) {
            pos.x = *(f32 *)(D_801E76B0 + i * 0x24 + 0x0) + func_80147000(0x13) - D_8010187C;
            pos.y = *(f32 *)(D_801E76B0 + i * 0x24 + 0x4) + func_80147000(0x13) - D_8010187C;
            pos.z = *(f32 *)(D_801E76B0 + i * 0x24 + 0x8) + func_80147000(0x13) - D_8010187C;
            { u8 *particle = (u8 *)func_801B66D4(0xA, &pos, &D_801ED3C4, 0, 0); /* spawn_particle */
            if (particle != NULL) {
                animFrame = *(f32 *)(*(u8 **)(player + 0xDC) + 0x4C);
                if (D_80101880 < animFrame && animFrame < D_80101884) {
                    *(f32 *)(particle + 0x5C) = D_80101888;
                }
            }
            }
        }
    }
}

#include "save_data.h"
extern HighScoreEntry D_801EA9E4[];
extern u8 D_801FA9A8;
void func_80132B5C(void);
void func_80132DA8(void);

/* Sets the RGB of all four corners of the fade plane's mesh (model asset
 * D_8028D8B0), leaving each corner's alpha byte alone. */
void func_8012A738(u8 red, u8 green, u8 blue) {
    u8 *color;
    s32 i;

    color = *(u8 **)(*(u8 **)(*(u8 **)(D_8028D8B0 + MENU_MODEL_ROOT_OFFSET) + FADE_MODEL_MESH_OFFSET) + FADE_MESH_VERTEX_COLORS_OFFSET);
    for (i = 0; i < FADE_PLANE_CORNER_COUNT; i++) {
        color[0] = red;
        color[1] = green;
        color[2] = blue;
        color += 4;
    }
}

void func_8012A77C(s32 score) { /* Inserts score into the high-score table (D_801EA9E4) with the player name D_801FA9A8, then saves it. */
    s32 place = GAME_HIGH_SCORE_COUNT + 1; /* not placed */
    s32 i;

    for (i = 0; i < GAME_HIGH_SCORE_COUNT; i++) {
        if (score >= D_801EA9E4[i].score) {
            place = i;
            break;
        }
    }
    if (place < GAME_HIGH_SCORE_COUNT + 1) {
        if (place < GAME_HIGH_SCORE_COUNT - 1) {
            for (i = GAME_HIGH_SCORE_COUNT - 1; i > place; i--) {
                D_801EA9E4[i] = D_801EA9E4[i - 1];
            }
        }
        D_801EA9E4[place].score = score;
        func_801D2150(D_801EA9E4[place].name, &D_801FA9A8); /* sprintf: copy the name */
        func_80132B5C(); /* queue the high-score write */
        func_80132DA8(); /* wait for the save queue to drain */
    }
}

/* Reapply the Q15 effects volume to active, audible tracked sounds on every owner. */
void func_8012A850(void) {
    extern u8 D_802AA7A0[];
    extern u8 D_8029F58C[];
    extern u8 D_8029F594[];
    extern u8 D_80290154[];
    extern s32 D_8029014C;
    extern s32 D_802999B0[][0xC0];
    extern s16 D_801E765A;
    u8 *owner;
    u8 *subobject;
    s32 ownerIndex;
    s32 soundIndex;
    s32 soundOffset;
    s32 unusedBase;

    for (owner = *(u8 **)D_802AA7A0; owner != D_802AA7A0; owner = *(u8 **)owner) { if (((PositionalSound *)(owner + UNK_AA7A0_SOUND_OFFSET))->handle != 0 && ((PositionalSound *)(owner + UNK_AA7A0_SOUND_OFFSET))->attenuatedVolume > 0) { func_801C0C70(((PositionalSound *)(owner + UNK_AA7A0_SOUND_OFFSET))->handle, ((PositionalSound *)(owner + UNK_AA7A0_SOUND_OFFSET))->attenuatedVolume * D_801E765A / SOUND_VOLUME_Q15_ONE); } }
    for (owner = *(u8 **)&D_802904D4; owner != (u8 *)&D_802904D4; owner = *(u8 **)owner) {
        if (((PositionalSound *)(owner + ACTOR_PRIMARY_SOUND_OFFSET))->handle != 0 && ((PositionalSound *)(owner + ACTOR_PRIMARY_SOUND_OFFSET))->attenuatedVolume > 0) { s32 scaledVolume = ((PositionalSound *)(owner + ACTOR_PRIMARY_SOUND_OFFSET))->attenuatedVolume * D_801E765A; func_801C0C70(((PositionalSound *)(owner + ACTOR_PRIMARY_SOUND_OFFSET))->handle, scaledVolume / SOUND_VOLUME_Q15_ONE); }
        subobject = *(u8 **)(owner + ACTOR_ROTATION_POINTER_OFFSET);
        if (subobject != 0 && ((PositionalSound *)(subobject + ROTATION_SOUND_OFFSET))->handle != 0 && ((PositionalSound *)(subobject + ROTATION_SOUND_OFFSET))->attenuatedVolume > 0) { func_801C0C70(((PositionalSound *)(subobject + ROTATION_SOUND_OFFSET))->handle, ((PositionalSound *)(subobject + ROTATION_SOUND_OFFSET))->attenuatedVolume * D_801E765A / SOUND_VOLUME_Q15_ONE); }
        subobject = *(u8 **)(owner + ACTOR_MOTION_POINTER_OFFSET);
        if (subobject != 0 && ((PositionalSound *)(subobject + MOTION_SOUND_OFFSET))->handle != 0 && ((PositionalSound *)(subobject + MOTION_SOUND_OFFSET))->attenuatedVolume > 0) { func_801C0C70(((PositionalSound *)(subobject + MOTION_SOUND_OFFSET))->handle, ((PositionalSound *)(subobject + MOTION_SOUND_OFFSET))->attenuatedVolume * D_801E765A / SOUND_VOLUME_Q15_ONE); }
        subobject = *(u8 **)(owner + ACTOR_SUBOBJECT_3C_POINTER_OFFSET);
        if (subobject != 0 && ((PositionalSound *)(subobject + SUBOBJECT_3C_SOUND_OFFSET))->handle != 0 && ((PositionalSound *)(subobject + SUBOBJECT_3C_SOUND_OFFSET))->attenuatedVolume > 0) { func_801C0C70(((PositionalSound *)(subobject + SUBOBJECT_3C_SOUND_OFFSET))->handle, ((PositionalSound *)(subobject + SUBOBJECT_3C_SOUND_OFFSET))->attenuatedVolume * D_801E765A / SOUND_VOLUME_Q15_ONE); }
    }
    for (ownerIndex = 0; ownerIndex < D_801F0198; ownerIndex++) {
        for (soundIndex = 0; soundIndex < TRACKED_SOUNDS_PER_OWNER; soundIndex++) {
            soundOffset = ownerIndex * ACTOR_INSTANCE_STRIDE + soundIndex * POSITIONAL_SOUND_STRIDE;
            if (*(s32 *)((u8 *)D_802999B0 + soundOffset) != 0 && *(s32 *)(D_802999B8 + soundOffset) > 0) { func_801C0C70(*(s32 *)((u8 *)D_802999B0 + soundOffset), *(s32 *)(D_802999B8 + soundOffset) * D_801E765A / SOUND_VOLUME_Q15_ONE); }
        }
    }
    for (owner = *(u8 **)&D_802AAF60; owner != (u8 *)&D_802AAF60; owner = *(u8 **)owner) {
        if (((LevelEffect *)owner)->sound.handle != 0 && ((LevelEffect *)owner)->sound.attenuatedVolume > 0) { func_801C0C70(((LevelEffect *)owner)->sound.handle, ((LevelEffect *)owner)->sound.attenuatedVolume * D_801E765A / SOUND_VOLUME_Q15_ONE); }
    }
    for (owner = *(u8 **)&D_8029F210; owner != (u8 *)&D_8029F210; owner = *(u8 **)owner) {
        if (((PositionalSound *)(owner + EFFECT_SOUND_OFFSET))->handle != 0 && ((PositionalSound *)(owner + EFFECT_SOUND_OFFSET))->attenuatedVolume > 0) { func_801C0C70(((PositionalSound *)(owner + EFFECT_SOUND_OFFSET))->handle, ((PositionalSound *)(owner + EFFECT_SOUND_OFFSET))->attenuatedVolume * D_801E765A / SOUND_VOLUME_Q15_ONE); }
    }
    for (ownerIndex = 0, soundOffset = 0; ownerIndex < TRACKED_SOUNDS_PER_OWNER; ownerIndex++, soundOffset += POSITIONAL_SOUND_STRIDE) {
        if (*(s32 *)((u8 *)&D_8029014C + soundOffset) != 0 && *(s32 *)(D_80290154 + soundOffset) > 0) { func_801C0C70(*(s32 *)((u8 *)&D_8029014C + soundOffset), *(s32 *)(D_80290154 + soundOffset) * D_801E765A / SOUND_VOLUME_Q15_ONE); }
        if (*(s32 *)(D_8029F58C + soundOffset) != 0 && *(s32 *)(D_8029F594 + soundOffset) > 0) { func_801C0C70(*(s32 *)(D_8029F58C + soundOffset), *(s32 *)(D_8029F594 + soundOffset) * D_801E765A / SOUND_VOLUME_Q15_ONE); }
    }
}

typedef struct { /* one s8 field of the 0x18-byte per-world records (base D_801E7380), seen from the field's own symbol */
    s8 v;
    s8 pad[0x17];
} WorldRecordField;
extern WorldRecordField D_801E7392[]; /* gWorldFirstLevel: first level index of each world */
extern WorldRecordField D_801E7394[]; /* gWorldLastLevel: last level index of each world */

/* level_is_in_world_range: returns 1 if the level index lies between the first and
 * last level of any of worlds 1..6 (the hub, world 0, is skipped), else 0. */
s32 func_8012ABFC(s32 level) {
    s32 world;

    for (world = 1; world < SAVE_WORLD_COUNT + 1; world++) {
        if (level < D_801E7392[world].v) {
            continue;
        }
        if (D_801E7394[world].v < level) {
            continue;
        }
        return 1;
    }
    return 0;
}

/* Returns 1 if the level is the first world level (always open) or is marked
 * completed (D_801EAA48 mask, bit D_801E693C[level][0]) in any of the six save slots. */
s32 func_8012AC54(s32 level) {
    extern u8 D_801E693C[];
    s32 slot = 0;
    s32 firstLevel = LEVEL_FIRST_WORLD_LEVEL;
    s32 levelRecord = level * 56;
    s32 slotOffset = 0;

    do {
        if (level == firstLevel) {
            return 1;
        }
        if ((*(s32 *)&D_801EAA48[slotOffset] >> *(s32 *)&D_801E693C[levelRecord]) & 1) {
            return 1;
        }
        slot++;
        slotOffset += LEVEL_SAVE_SLOT_BYTES;
    } while (slot < SAVE_VALIDATION_SLOT_COUNT);
    return 0;
}

extern s32 D_801F9628;
extern s32 D_801F962C;
extern s32 D_801F9688;
extern s16 D_801E7542;
void func_8012AE8C(s32 *);

/* Original compiler padding. */
const u32 D_8012ACB8_padding[] __attribute__((section(".text"))) = {
    0x494E4B20, 0x342E3230
};

/* cameo_list_init: empty the cameo list. D_801F9628 is the sentinel head's next,
 * D_801F962C its prev (tail); both point back at the head. D_801F9688 is the cameo count. */
void func_8012ACC0(void) {
    s32 *head = &D_801F9628;

    D_801F962C = (s32)head;
    *head = (s32)head;
    D_801F9688 = 0;
}

/*
 * cameo_list_append: link a cameo at the tail of the circular cameo list.
 * D_801F9628 is the list's sentinel head (a Cameo: D_801F9628 is its next,
 * D_801F962C its prev, i.e. the tail) and D_801F9688 counts the linked cameos.
 * A cameo whose next pointer is already set is in the list and is left alone.
 */
void func_8012ACE4(s32 *cameo) {
    if (cameo[CAMEO_NEXT_WORD] == 0) {
        cameo[CAMEO_NEXT_WORD] = (s32)&D_801F9628;
        cameo[CAMEO_PREV_WORD] = D_801F962C;
        *(s32 *)D_801F962C = (s32)cameo;
        *(s32 *)(cameo[CAMEO_NEXT_WORD] + 4) = (s32)cameo;
        D_801F9688 = D_801F9688 + 1;
    }
}

/* cameo_start: start the index-th cameo in the list headed by D_801F9628
 * (frame 1, instructions with startCondition -1 active). Skipped in level 0
 * when arriving from level 8 or 9; resumes camera following if the camera
 * control mode (D_801EC740) is zero. */
void func_8012AD30(s32 index) {
    s32 i;
    s32 *cameo;

    if (D_801E7531 == 0) {
        if ((u32)(D_801E7532 - 8) < 2) {
            return;
        }
    }
    if (D_801EC740 == 0) {
        func_801364D0();
    }
    cameo = (s32 *)D_801F9628;
    for (i = 0; i < index; i++) {
        cameo = (s32 *)*cameo;
    }
    cameo[CAMEO_FRAME_WORD] = 1;
    for (i = 0; i < cameo[CAMEO_INSTRUCTION_COUNT_WORD]; i++) {
        ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + i])->elapsedFrames = 0;
        if (((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + i])->startCondition == CAMEO_START_IMMEDIATELY) {
            ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + i])->elapsedFrames = 1;
        }
    }
}

/* cameos_update: run cameo_update on every running cameo (nonzero frame) in the
 * list headed by D_801F9628; D_801E7542 records whether any cameo is playing. */
void func_8012AE00(void)
{
    s32 *cameo = *(s32 **)&D_801F9628;
    s32 runningCount = 0;

    if (cameo != (s32 *)&D_801F9628) {
        s32 *head = (s32 *)&D_801F9628;
        do {
            if (cameo[CAMEO_FRAME_WORD] != 0) {
                func_8012AE8C(cameo); /* cameo_update */
                runningCount++;
            }
            cameo = (s32 *)cameo[0]; /* next */
        } while (cameo != head);
    }
    if (runningCount != 0) {
        D_801E7542 = 1;
    } else {
        D_801E7542 = 0;
    }
}

void func_8012B048(s32 *arg0, s16 *arg1);

/* Advance a cameo's active instructions and activate frame or completion dependencies. */
void func_8012AE8C(s32 *cameo) {
    s32 instructionIndex;
    s32 dependentIndex;
    s32 activeCount = 0;

    for (instructionIndex = 0; instructionIndex < cameo[CAMEO_INSTRUCTION_COUNT_WORD]; instructionIndex++) {
        ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + instructionIndex])->completed = 0;
        if (((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + instructionIndex])->elapsedFrames != 0) {
            func_8012B048(cameo, (s16 *)cameo[CAMEO_INSTRUCTIONS_WORD + instructionIndex]);
            if (((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + instructionIndex])->completed == 0) {
                activeCount++;
                continue;
            }
            if (D_801E7531 != CAMEO_DEFER_DEPENDENCIES_LEVEL) {
                for (dependentIndex = 0; dependentIndex < cameo[CAMEO_INSTRUCTION_COUNT_WORD]; dependentIndex++) {
                    s32 startCondition = ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + dependentIndex])->startCondition;

                    if ((startCondition < CAMEO_START_IMMEDIATELY && startCondition == -cameo[CAMEO_FRAME_WORD]) || (startCondition >= 0 && ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + startCondition])->completed != 0)) {
                        activeCount++;
                        ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + dependentIndex])->elapsedFrames = 1;
                    }
                }
            }
        }
    }
    for (dependentIndex = 0; dependentIndex < cameo[CAMEO_INSTRUCTION_COUNT_WORD]; dependentIndex++) {
        s32 startCondition = ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + dependentIndex])->startCondition;

        if ((startCondition < CAMEO_START_IMMEDIATELY && startCondition == -cameo[CAMEO_FRAME_WORD]) || (startCondition >= 0 && ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + startCondition])->completed != 0)) {
            activeCount++;
            ((CameoInstruction *)cameo[CAMEO_INSTRUCTIONS_WORD + dependentIndex])->elapsedFrames = 1;
        }
    }
    if (activeCount == 0) {
        cameo[CAMEO_FRAME_WORD] = 0;
    } else {
        cameo[CAMEO_FRAME_WORD]++;
        func_80173CE8(CAMEO_GAMEPLAY_DELAY);
    }
}

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

void func_8012B048(s32 *events, s16 *event) { /* Runs one frame of a cutscene event (+0 type, +2 frame, +4 duration, +8 done, +0xA target): animate, camera target, move, speed, flag, sound or attach. */
    extern u8 *volatile D_8028FAC8; /* camera target position */
    extern u8 *D_8028FAD0; /* camera target velocity */
    extern struct { s32 flags; u8 pad[0x2FC]; } D_80299964[];
    extern struct { s32 flags; u8 pad[0x2FC]; } D_80299710[];
    extern struct { u8 *p; u8 pad[0x2FC]; } D_802997C4[];
    extern u8 *D_80290304;
    extern s16 D_802900DA;
    extern s16 D_801E7620;
    extern f32 D_8028F938;
    extern f32 D_8028F93C;
    extern f32 D_8028F940;
    extern f32 D_8028FAB4;
    extern u8 D_802AAFE7;
    u8 *ev = (u8 *)event;
    u8 *actor;
    u8 *particle;
    u8 **follow;
    f32 *pos;
    Vec3F delta;
    f32 scratch[2];
    f64 diff;
    f32 dist;
    s32 i;

    switch (*(s16 *)(ev + 0x0)) {
    case 6:
        D_802AAFE7 = ev[0xD] + func_80147000(*(s16 *)(ev + 0xE));
        func_801793DC(0xF8, 0xC8, 0x80, 0x80);
        break;
    case 0:
        if (*(s16 *)(ev + 0xA) == 0) {
            actor = (u8 *)&D_802902D8;
            D_8028FBD8 = 2;
        } else {
            actor = D_802993E8 + *(s16 *)(ev + 0xA) * 0x300;
        }
        if (*(s16 *)(ev + 0x2) == 1) {
            *(s32 *)(*(u8 **)(actor + 0xDC) + 8) = 0;
            func_80133998(actor, *(s16 *)(ev + 0xC), ev[0xF], 0, *(f32 *)(ev + 0x18)); /* object_set_animation */
            if (*(s16 *)(ev + 0x4) == 0) {
                *(s16 *)(ev + 0x8) = 1;
            }
        } else if (*(s16 *)(ev + 0x4) == -1 && *(s32 *)(*(u8 **)(actor + 0xDC) + 4) != 0) {
            *(s16 *)(ev + 0x8) = 1;
        }
        break;
    case 1:
        D_8028FB7C = 0;
        switch (*(s16 *)(ev + 0xA)) {
        case -1: {
            u8 *oldTarget = D_8028FAC8;
            u8 *oldVelocity = D_8028FAD0;

            D_8028FAC8 = ev + 0xC;
            D_8028FAD0 = (u8 *)&D_801ED3C4;
            D_801F95C0 = oldTarget;
            D_801F95C4 = oldVelocity;
            break;
        }
        case 0:
            D_8028FAC8 = (u8 *)&D_8029030C;
            D_8028FAD0 = (u8 *)&D_8029030C + 0x24;
            break;
        default:
            D_8028FAC8 = D_8029941C + *(s16 *)(ev + 0xA) * 0x300;
            D_8028FAD0 = D_8029941C + 0x24 + *(s16 *)(ev + 0xA) * 0x300;
            if (*(f32 *)(ev + 0xC) != 0.0f) {
                *(Vec3F *)&D_8028FA00 = *(Vec3F *)D_8028FAC8;
            }
            break;
        }
        break;
    case 3:
        if (*(s16 *)(ev + 0xA) == -1) {
            f32 *yaw = &D_8028F95C;

            delta.x = func_801C6000(*yaw - *(const f64 *)(D_801018D0 + 4)) * *(f32 *)(ev + 0xC);
            delta.y = 0.0f;
            delta.z = func_801C4040(*yaw - *(const f64 *)(D_801018D0 + 4)) * *(f32 *)(ev + 0xC);
            D_8028F938 += delta.x;
            D_8028F93C += delta.y;
            D_8028F940 += delta.z;
        } else {
            if (*(s16 *)(ev + 0xA) == 0) {
                actor = (u8 *)&D_802902D8;
            } else {
                actor = D_802993E8 + *(s16 *)(ev + 0xA) * 0x300;
            }
            if (*(f32 *)(ev + 0xC) >= 0.0f) {
                *(f32 *)(actor + 0x88) = *(f32 *)(ev + 0xC);
            } else {
                *(f32 *)(actor + 0x84) = -*(f32 *)(ev + 0xC);
            }
            if (*(s16 *)(ev + 0x4) == -1 && *(f32 *)(actor + 0x7C) == *(f32 *)(actor + 0x88)) {
                *(s16 *)(ev + 0x8) = 1;
            }
        }
        break;
    case 5:
        D_80299964[*(s16 *)(ev + 0xA) - 1].flags |= 0x100;
        break;
    case 2:
        switch (*(s16 *)(ev + 0xA)) {
        case -7:
            pos = (f32 *)D_80299A1C;
            func_801B66D4(0xF, ev + 0xC, &D_801ED3C4, 0, 0);
            func_801B7764(ev + 0xC, 5, 0x13);
            for (i = 0; i < 10; i++) {
                delta.x = func_80147000(0xB) - 5;
                delta.z = func_80147000(0xB) - 5;
                delta.y = func_80147000(6) + 3;
                particle = (u8 *)func_801B66D4(0x10, ev + 0xC, &delta, 0, 0);
                if (particle != NULL) {
                    *(s16 *)(particle + 0x24) = 5;
                    *(f32 *)(*(u8 **)(particle + 0xD0) + 0x18) = D_80101900;
                    *(f32 *)(particle + 0x70) = D_80101900;
                }
            }
            break;
        case -6:
            D_801E7620 = 1;
            D_801E7588 = 0;
            return;
        case -5:
            D_80299710[(s32)*(f32 *)(ev + 0xC) - 1].flags &= ~0x11;
            D_8028FFC4[0] = D_802993E8 + (s32)*(f32 *)(ev + 0xC) * 0x300;
            *(f32 *)(D_802997C4[(s32)*(f32 *)(ev + 0xC) - 1].p + 0x4C) = D_80101904;
            *(s32 *)(D_802997C4[(s32)*(f32 *)(ev + 0xC) - 1].p + 0xC) = 0;
            *(s16 *)(D_802997C4[(s32)*(f32 *)(ev + 0xC) - 1].p + 2) = 5;
            pos = (f32 *)&D_8028FFC4[2];
            break;
        case -4:
            D_80299710[(s32)*(f32 *)(ev + 0xC) - 1].flags |= 0x11;
            follow = D_8028FFC4;
            pos = (f32 *)(follow + 2);
            follow[0] = (u8 *)&D_802902D8;
            func_801B7764(pos, 5, 0x13);
            break;
        case -2:
            D_8028FB7C = 0;
            if (*(s16 *)(ev + 0x2) == 1) {
                D_801F9618 = *(Vec3F *)D_8028FAC8;
                D_8028FAD0 = (u8 *)&D_801ED3C4;
                D_8028FAC8 = (u8 *)&D_801F9618;
            }
            pos = (f32 *)&D_801F9618;
            break;
        case -1:
            pos = &D_8028F914;
            D_8028FB6C = 2;
            break;
        case 0:
            pos = (f32 *)&D_8029030C;
            break;
        default:
            pos = (f32 *)(D_8029941C + *(s16 *)(ev + 0xA) * 0x300);
            break;
        }
        diff = *(f32 *)(ev + 0xC) - D_80101908;
        if (diff > 0.0 ? diff > D_80101910 : -diff > D_80101918) {
            delta.x = *(f32 *)(ev + 0xC) - pos[0];
            delta.y = *(f32 *)(ev + 0x10) - pos[1];
            delta.z = *(f32 *)(ev + 0x14) - pos[2];
        } else {
            delta.x = delta.z = 0.0f;
            delta.y = *(f32 *)(ev + 0x10) - pos[1];
        }
        dist = sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        if (dist <= *(f32 *)(ev + 0x18)) {
            diff = *(f32 *)(ev + 0xC) - D_80101920;
            if (diff > 0.0 ? diff > D_80101928 : -diff > D_80101930) {
                *(Vec3F *)pos = *(Vec3F *)(ev + 0xC);
            } else {
                pos[1] = *(f32 *)(ev + 0x10);
            }
            if (*(s16 *)(ev + 0x4) == -1) {
                *(s16 *)(ev + 0x8) = 1;
                if (*(s16 *)(ev + 0xA) == -1) {
                    D_8028FB6C = 1;
                }
            }
        } else {
            func_80148D0C(pos, (f32 *)&delta, *(f32 *)(ev + 0x18) / dist); /* step toward the target at the event's speed */
        }
        if (*(s16 *)(ev + 0xA) == -2) {
            func_80149318(&D_8028FA00, &D_801F9618);
            D_8028FA04 = D_8028FAB4 = ((f32 *)D_8028FAC8)[1] + D_8028FAB0;
            if (D_801E7531 == 0x28) {
                *(Vec3F *)&D_8028FA00 = D_801F9618;
            }
        }
        func_80165230();
        if (*(s16 *)(ev + 0xA) > 0) {
            actor = D_802993E8 + *(s16 *)(ev + 0xA) * 0x300;
            if (*(s32 *)(actor + 0x28) & 0x100) {
                **(f32 **)(actor + 0xCC) = func_8015B524(actor + 0x34, *(s32 *)(actor + 0xCC) + 4, scratch, *(s32 *)(actor + 0xD8));
            }
        }
        break;
    case 4:
        if (*(s16 *)(ev + 0xC) == 0) {
            actor = (u8 *)&D_802902D8;
        } else {
            actor = D_802993E8 + *(s16 *)(ev + 0xC) * 0x300;
        }
        switch (*(s16 *)(ev + 0xA)) {
        case -2:
            if (*(s16 *)(ev + 0x2) == 1) {
                D_801F9618 = *(Vec3F *)D_8028FAC8;
                D_8028FAD0 = (u8 *)&D_801ED3C4;
                D_8028FAC8 = (u8 *)&D_801F9618;
            }
            pos = (f32 *)&D_801F9618;
            break;
        case -1:
            pos = &D_8028F914;
            D_8028FB6C = 2;
            break;
        case 0:
            pos = (f32 *)&D_8029030C;
            D_80290304 = actor;
            D_802900DA = 0;
            break;
        default:
            pos = (f32 *)(D_8029941C + *(s16 *)(ev + 0xA) * 0x300);
            D_80299714[*(s16 *)(ev + 0xA) - 1].obj = actor;
            break;
        }
        *(Vec3F *)pos = *(Vec3F *)(*(u8 **)(actor + 0xD8) + *(s16 *)(ev + 0xE) * 0x24 + 0x58);
        break;
    }
    if (*(s16 *)(ev + 0x2) == *(s16 *)(ev + 0x4)
        || (*(s16 *)(ev + 0x4) < -1 && ((s16 *)(events - *(s16 *)(ev + 0x4))[4])[4] != 0)) {
        *(s16 *)(ev + 0x8) = 1;
        if (*(s16 *)(ev + 0x0) == 1) {
            if (*(s16 *)(ev + 0xA) == -1) {
                D_8028FAC8 = D_801F95C0;
                D_8028FAD0 = D_801F95C4;
            }
            D_8028FB7C = 1;
        } else if (*(s16 *)(ev + 0x0) == 2 && *(s16 *)(ev + 0xA) == -1) {
            D_8028FB6C = 1;
        } else if (*(s16 *)(ev + 0x0) == 2 && *(s16 *)(ev + 0xA) == -2) {
            D_8028FB7C = 1;
        } else if (*(s16 *)(ev + 0x0) == 4) {
        } else if (*(s16 *)(ev + 0x0) == 5) {
            D_80299964[*(s16 *)(ev + 0xA) - 1].flags &= ~0x100;
        }
    }
    if (*(s16 *)(ev + 0x4) != 0) {
        (*(s16 *)(ev + 0x2))++;
    } else {
        *(s16 *)(ev + 0x2) = 0;
    }
    if (*(s16 *)(ev + 0x8) != 0) {
        *(s16 *)(ev + 0x2) = 0;
    }
}

/* Start the recorded intro cutscene: reset scene state, load its level in playback mode and fade in. */
s32 func_8012BCA8(void) {
    func_80155A44(&D_80101938);
    func_80145680(0);
    D_801E7584 = 0;
    D_80201004 = 0;
    D_802004E0 = 0;
    func_8011FD80();
    D_801EAB24 = INTRO_CUTSCENE_SAVE_SLOT;
    func_8011F9F4();
    D_801EC7F0 = INPUT_MODE_PLAYBACK;
    func_8011FF40(INTRO_CUTSCENE_LEVEL);
    func_80177A14(INTRO_CUTSCENE_MUSIC);
    func_8014D548();
    D_801EC748 = 1;
    D_8028FB7C = 0;
    return 1;
}

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

/* Run level 43's timed ball placement, particle bursts, form changes and player alignment. */
void func_8012BD44(void) {
    u8 *playerStatePointerAddress = (u8 *)&D_802903AC;
    u8 *playerPosition;
    f32 *ballPosition;

    D_8028FB7C = 0;
    if (*(u8 **)playerStatePointerAddress != NULL) {
        if (*(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) == 0x13 && D_8028FBEA == LEVEL43_BALL_PLACEMENT_ACTION_FRAME) {
            playerPosition = playerStatePointerAddress - LEVEL43_PLAYER_POSITION_BEFORE_STATE_POINTER;
            ballPosition = &D_8029F9AC;
            D_801EFCFC = 0;
            *ballPosition = *(f32 *)playerPosition;
            D_8029F9B4 = D_80290314;
            D_8029F9B0 = D_80290310 - *(const f64 *)(D_80101940 + 4);
            D_8029F9A0 |= 0x19;
            func_80167604(0x14);
            func_801B7764(playerPosition, LEVEL43_PLAYER_BURST_COUNT, LEVEL43_PLAYER_PARTICLE_TYPE);
            func_801B7764(ballPosition, LEVEL43_BALL_BURST_COUNT, LEVEL43_BALL_PARTICLE_TYPE);
        } else if (*(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) == 0x14 && D_8028FBEA == LEVEL43_BALL_RESTORE_ACTION_FRAME) {
            func_8018C700(LEVEL43_CLEAR_BALL_POWERUPS, LEVEL43_POWERUP_INDEFINITE);
            ((BallCollisionState *)D_8029FA50)->spheres[0].targetRadius = D_8010194C;
        }
    }
    if (D_802004E0 == LEVEL43_PLAYER_ALIGN_SCENE_FRAME) {
        func_80149318(&D_8029030C, &D_8028F914);
    } else if (D_802004E0 == LEVEL43_BOWLING_SCENE_FRAME) {
        func_8018C700(LEVEL43_BOWLING_POWERUP, LEVEL43_POWERUP_INDEFINITE);
        ((BallCollisionState *)D_8029FA50)->spheres[0].targetRadius = D_80101950;
    }
}

extern s32 D_801EAB30[];
/* Initialize the title flythrough, logo, and controller-dependent prompt text. */
void func_8012BEE0(void) {
    extern s32 D_80101954;
    extern u8 D_801F92F8[];
    extern u8 D_80101960[];
    extern f32 D_8010196C;
    extern f32 D_80101970;
    extern f32 D_80101974;
    extern u8 D_801EC749;
    extern s32 D_801EAB30[];
    extern s32 D_801EAB3C;
    extern s32 D_801EAB40;
    extern s32 D_801EAB44;
    extern s32 D_801ED62C;
    extern s32 D_801ED630;
    extern s32 D_801ED634;
    void func_8014A50C(void *, u8 *, s32, s32, s32, s32);
    void *func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    s32 enabled;
    s32 fullIntensity;
    f32 *motionX;
    f32 warningScaleX;
    f32 warningScaleY;
    s32 *localizedPrompts;

    enabled = 1;
    func_80155A44(&D_80101954);
    func_80145680(0);
    D_801E7584 = 0;
    D_80201004 = 0;
    D_802004E0 = 0;
    func_8011FD80();
    motionX = &D_801EE8E4;
    *motionX = *motionX + *motionX;
    D_801EE8EC = D_801EE8EC + D_801EE8EC;
    D_801EAB24 = TITLE_FLYTHROUGH_SAVE_SLOT;
    func_8011FF40(TITLE_FLYTHROUGH_LEVEL);
    func_8014A50C(D_801F92F8, D_80101960, TITLE_FLYTHROUGH_LOGO_X, TITLE_FLYTHROUGH_LOGO_Y, TITLE_FLYTHROUGH_LOGO_PRIORITY, 0);
    if (D_801EC749 == enabled) {
        localizedPrompts = D_801EAB30;
        D_801ED62C = (s32)func_801469E4(TITLE_FLYTHROUGH_TEXT_X, TITLE_FLYTHROUGH_PROMPT_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, D_8010196C, D_8010196C, 0, localizedPrompts[D_801E7586], enabled);
    } else {
        fullIntensity = TEXT_CHANNEL_MAX;
        warningScaleX = D_80101970;
        warningScaleY = D_80101974;
        D_801ED62C = (s32)func_801469E4(TITLE_FLYTHROUGH_TEXT_X, TITLE_FLYTHROUGH_WARNING_ENGLISH_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, fullIntensity, fullIntensity, warningScaleX, warningScaleY, 0, D_801EAB3C, enabled);
        if (D_80000300 == 0) {
            D_801ED630 = (s32)func_801469E4(TITLE_FLYTHROUGH_TEXT_X, TITLE_FLYTHROUGH_WARNING_FRENCH_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, fullIntensity, fullIntensity, warningScaleX, warningScaleY, 0, D_801EAB40, enabled);
            D_801ED634 = (s32)func_801469E4(TITLE_FLYTHROUGH_TEXT_X, TITLE_FLYTHROUGH_WARNING_GERMAN_Y, TEXT_CHANNEL_MAX, TEXT_CHANNEL_MAX, fullIntensity, fullIntensity, warningScaleX, warningScaleY, 0, D_801EAB44, enabled);
        }
    }
    func_8014D548();
    D_801EC748 = 1;
}

/* Follow the title flythrough actor, adjust its motion, and exit on menu input or timeout. */
void func_8012C124(void) {
    extern f32 *D_802997B4;
    extern u8 D_8029971C[];
    extern u8 *D_8028FAC8;
    extern f32 D_80299744;
    extern f32 D_80101978;
    extern f32 D_8010197C;
    extern f64 D_80101980;
    extern f32 D_80101988[];
    extern f32 D_80101994;
    extern u8 D_801EC749;
    extern u8 D_80202218;
    f32 *actorMotion;
    f32 *motionX;

    D_8028FAC8 = D_8029971C;
    if (*D_802997B4 < D_80101978 && *D_802997B4 != D_8010197C) {
        D_80299744 = D_80299744 + D_80101980;
    }
    if (*D_802997B4 > D_80101988[0]) {
        actorMotion = &D_80299744;
        *actorMotion = *actorMotion - *(f64 *)&D_80101988[1];
    }
    if (D_801EC749 != 0) {
        if ((func_801399EC(D_80202218) != 0 && D_801E758C == 0 && D_801E753C == 0) || D_802004E0 == TITLE_FLYTHROUGH_EXIT_FRAME) {
            func_801793DC(TITLE_FLYTHROUGH_EXIT_SOUND, TITLE_FLYTHROUGH_EXIT_VOLUME, TITLE_FLYTHROUGH_EXIT_PAN, TITLE_FLYTHROUGH_EXIT_PITCH_TEMPO);
            motionX = &D_801EE8E4;
            *motionX = *motionX / D_80101994;
            D_801EE8EC = D_801EE8EC / D_80101994;
            func_80128DF8(TITLE_FLYTHROUGH_EXIT_TRANSITION, 1, 1);
        }
    }
}

/* Original compiler padding. */
const u32 D_8012C2A8_padding[] __attribute__((section(".text"))) = {
    0x01000000, 0x03002E74
};


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
