#include "common.h"
#include "structs.h"

extern s32 D_801F54B0;
extern s32 D_802AB038;
extern u8 *D_802AB040;
extern s32 *D_802AB048;
s32 func_801C2B24(u8 *arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4);
u32 func_801CE900(void);
void func_801CF0C0(void);
void func_801CF654(void);
void func_801CF890(void);
extern volatile u32 D_A4080000;
extern u8 D_802AE8A0[];
extern u8 D_802AE890[];
extern u16 D_802AB054;
extern u16 D_802AB056;

typedef struct DspChan {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8 pad10[0x30];
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u8 pad44[0x10];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ u32 unk64;
    /* 0x68 */ u8 pad68[0x53];
    /* 0xBB */ u8 unkBB;
    /* 0xBC */ u8 unkBC;
    /* 0xBD */ u8 unkBD;
    /* 0xBE */ u8 unkBE;
    /* 0xBF */ u8 state;
    /* 0xC0 */ u8 unkC0;
    /* 0xC1 */ u8 unkC1;
    /* 0xC2 */ u8 unkC2;
    /* 0xC3 */ u8 unkC3;
    /* 0xC4 */ u8 unkC4;
    /* 0xC5 */ u8 padC5[0x4];
    /* 0xC9 */ u8 unkC9;
} DspChan;

typedef struct SndState {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 limit;
    /* 0x10 */ u8 pad10[0x80];
    /* 0x90 */ u32 pos;
    /* 0x94 */ u8 pad94[0x25];
    /* 0xB9 */ u8 vol;
    /* 0xBA */ u8 padBA[0x16];
    /* 0xD0 */ u8 step;
    /* 0xD1 */ u8 padD1[4];
    /* 0xD5 */ u8 acc;
    /* 0xD6 */ u8 dir;
} SndState;

typedef struct UnkStream21FC {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u8 pad10[0x08];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x08];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0x0C];
    /* 0x34 */ u8 *unk34;
    /* 0x38 */ u8 pad38[0x34];
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ u8 pad74[0x2C];
    /* 0xA0 */ u16 unkA0;
} UnkStream21FC;

/* 0x801F4764: current render object used by the 0x801D00xx wrappers. */
typedef struct Unk801F4764 {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ struct Unk801F4764 *unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u16 unk28;
    /* 0x2A */ u16 pad2A;
    /* 0x2C */ u32 unk2C;
} Unk801F4764;

typedef struct UnkViField {
    /* 0x00 */ u32 origin;
    /* 0x04 */ u32 yScale;
    /* 0x08 */ u32 vStart;
    /* 0x0C */ u32 vBurst;
    /* 0x10 */ u32 vIntr;
} UnkViField;

typedef struct UnkViMode {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 control;
    /* 0x08 */ u32 width;
    /* 0x0C */ u32 burst;
    /* 0x10 */ u32 vSync;
    /* 0x14 */ u32 hSync;
    /* 0x18 */ u32 leap;
    /* 0x1C */ u32 hStart;
    /* 0x20 */ u32 xScale;
    /* 0x24 */ u32 vCurrent;
    /* 0x28 */ UnkViField fld[2];
} UnkViMode;

extern Unk801F4764 *D_801F4760;
extern u32 D_A4400000;
extern Unk801F4764 D_801F4700[];
extern u8 D_801F4738[];
extern u8 D_801F5520[];
extern u8 D_801F5570[];
extern u8 D_801F54D0[];

extern Unk801F4764 *D_801F4764;

s32 func_801C6F70();

typedef struct Unk801CAA34State {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[8];
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s32 unk24;
} Unk801CAA34State;

typedef struct Unk801CAA34Obj {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad08[0x10];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[8];
    /* 0x24 */ Unk801CAA34State *unk24;
} Unk801CAA34Obj;

u32 *func_801CAC4C(s32 *, s32, s32, s32, u32 *);
f32 func_801CAFC8(u8 *, s32);

typedef struct Unk16 {
    u32 w[4];
} Unk16;

extern Unk16 func_801C6620;
extern Unk16 D_80000000;
extern u32 D_80000300;
extern u32 D_8000030C;
extern u8 D_8000031C[];
extern s32 D_802AD3A0;
extern u64 D_801F43D0;
s32 func_801C7320();
void func_801C73C0(s32);
void func_801C73B0(s32);
void func_801C7330(void *, s32);
void func_801C73D0();
s32 func_801CF4C0(u32 arg0, s32 arg1);
s32 func_801D03E0(s32 arg0, s32 *arg1);
void func_801D3B40(s32, s32, s32, s32);
void func_801C6F90(s32);
s32 func_801C62B0();
void func_801C7D80(s32);
extern s32 D_802AD5F0;
extern s32 D_802AD5E0;
extern u64 D_802AD5E8;
extern s32 D_802AD5EC;
extern u8 D_8010C6A0[];
extern u8 D_8010C6A4[];
extern u8 D_8010C640[];
extern u8 D_8010C644[];
extern u8 D_8010C610[];
typedef struct { u32 w0; u32 w1; } Gfx_B060;
extern u8 D_8010C5B0[];
extern u8 D_8010C5B4[];
u32 *func_801CADBC(s32 *, s32, s32, s32, u32 *);
u8 *func_801CAF2C(u8 *, u32, u32, u8 *);
u32 *func_801CAA34(s32 *, Unk801CAA34Obj *, s32, s32, u32 *);
extern u8 D_8010C614[];
extern ObjectNode *D_801F4410;
extern s32 D_801F4170;
extern s32 D_801F4174;
extern u8 D_802AD318[];
extern s32 D_802AD354;
typedef struct { s32 w[6]; } Cmd18;
extern u8 D_802AD338[];
void func_801C7C10(s64 arg0);
s64 func_801C7C70(s32 *arg0);
extern u8 D_802AE830[];
extern u8 D_802AE848[];
extern u16 D_802AE860;
extern u8 D_802AE862;
extern s32 D_802AE864;
extern u16 D_802AE878;
extern u8 D_802AE87A;
extern s32 D_802AE87C;
extern u8 D_802AD678[];
extern s32 D_801F4770;
extern s32 D_801F4774;
extern s32 D_801F4778;
extern s32 D_801F477C;
extern s32 D_801F4780;
extern s32 D_801F4784;
extern s32 D_801F4788;
void func_801C7690(s32, OSMesgQueue *, s32);
s32 func_801CEDD0(s32);
void func_801CE950();
void func_801CEC38();

typedef struct GloverTimer {
    /* 0x00 */ struct GloverTimer *next;
    /* 0x04 */ struct GloverTimer *prev;
    /* 0x08 */ u64 interval;
    /* 0x10 */ u64 value;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} GloverTimer;
extern u8 D_8010C6E0[];
extern u8 D_8010C6E4[];
extern s32 D_80000308;
extern u8 *D_801F4400;
extern u16 D_801F46E4;
extern s32 D_802AD620;
extern s32 D_802AD624;
extern s32 D_802AD628;
extern s32 D_802AD62C;
void func_801C6C84(void *);
typedef struct Thread801 {
    /* 0x000 */ struct Thread801 *next;
    /* 0x004 */ s32 priority;
    /* 0x008 */ void *queue;
    /* 0x00C */ void *tlnext;
    /* 0x010 */ u16 state;
    /* 0x012 */ u16 flags;
    /* 0x014 */ s32 id;
    /* 0x018 */ s32 fp;
    /* 0x01C */ u8 pad1C[0x1C];
    /* 0x038 */ s64 a0;
    /* 0x040 */ u8 pad40[0xB0];
    /* 0x0F0 */ s64 sp;
    /* 0x0F8 */ u8 padF8[8];
    /* 0x100 */ s64 ra;
    /* 0x108 */ u8 pad108[0x10];
    /* 0x118 */ u32 sr;
    /* 0x11C */ u32 pc;
    /* 0x120 */ u8 pad120[8];
    /* 0x128 */ u32 rcp;   /* RCP interrupt mask */
    /* 0x12C */ u32 fpcsr; /* FPU control/status register */
} Thread801;
void func_801C6F60(void);
typedef struct QNode {
    u8 pad0[4];
    s32 unk4;
    ObjectNode *unk8;
    struct QNode *unkC;
    u16 unk10;
} QNode;
extern QNode *D_801F43F8;
extern QNode *D_801F43FC;
extern u8 *D_802AFC54;
extern s32 D_801F43E0;
void func_801D126C();
void func_801D119C(void);
typedef struct {
    /* 0x00 */ u32 errStatus;
    /* 0x04 */ void *dramAddr;
    /* 0x08 */ void *C2Addr;
    /* 0x0C */ u32 sectorSize;
    /* 0x10 */ u32 C1ErrNum;
    /* 0x14 */ u32 C1ErrSector[4];
} LeoBlockInfo;
typedef struct {
    /* 0x00 */ u32 cmdType;
    /* 0x04 */ u16 transferMode;
    /* 0x06 */ u16 blockNum;
    /* 0x08 */ s32 sectorNum;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 bmCtlShadow;
    /* 0x14 */ u32 seqCtlShadow;
    /* 0x18 */ LeoBlockInfo block[2];
} LeoTranxInfo;
#define LEO_WAIT_ON_IOBUSY(stat) \
    stat = *(volatile u32 *)0xA4600010; \
    while (stat & 3) \
        stat = *(volatile u32 *)0xA4600010;
#define LEO_IO_READ(addr) (*(volatile u32 *)(addr))
#define LEO_IO_WRITE(addr, data) (*(volatile u32 *)(addr) = (data))
extern OSMesgQueue *D_802AD5A0;
extern void *D_802AD5A4;
void func_801C5300(f32 *, u32 *);
void func_801C6D8C(ObjectNode *, QNode *);

typedef struct {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0xC];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 pad3C[0x30];
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ u8 pad74[0x2A];
    /* 0x9E */ u16 unk9E;
    /* 0xA0 */ u16 unkA0;
    /* 0xA2 */ u8 padA2[0x16];
    /* 0xB8 */ u8 unkB8;
    /* 0xB9 */ u8 padB9[0x1E];
    /* 0xD7 */ u8 unkD7;
    /* 0xD8 */ u8 padD8[4];
    /* 0xDC */ s32 unkDC[4];
    /* 0xEC */ s32 unkEC[4];
    /* 0xFC */ s32 unkFC[4];
    /* 0x10C */ u16 unk10C[4];
    /* 0x114 */ u16 unk114[4];
    /* 0x11C */ u8 unk11C[4];
    /* 0x120 */ u8 unk120[4];
    /* 0x124 */ u8 unk124[4];
} UnkBFE90;

typedef struct {
    s32 quot;
    s32 rem;
} LongDiv;

typedef struct {
    s64 quot;
    s64 rem;
} LongLongDiv;

typedef struct {
    f64 d[8];
} Unk8010C4F0;

extern Unk8010C4F0 D_8010C4F0;
extern const f64 D_8010C530;
extern const f64 D_8010C538;
extern const f64 D_8010C540;
extern const f64 D_8010C548;
extern const f64 D_8010C550;
extern const f64 D_8010C558;
extern const f64 D_8010C560;
extern const f64 D_8010C568;
extern const f64 D_8010C570;
extern const f64 D_8010C578;
static inline f64 frexp_inline(f64 arg0, s32 *arg1) {
    f64 temp;

    if (arg0 == 0.0) {
        *arg1 = 0;
        return arg0;
    }
    temp = (arg0 > 0.0) ? arg0 : -arg0;
    if (temp >= D_8010C540) {
        do {
            temp *= D_8010C548;
            (*arg1)++;
        } while (temp >= D_8010C540);
    } else if (temp < D_8010C550) {
        do {
            temp += temp;
            (*arg1)--;
        } while (temp < D_8010C550);
    }
    if (arg0 > 0.0) {
        return temp;
    }
    return -temp;
}

extern f64 D_8010C580;
extern f64 D_8010C5F0;
extern f64 D_8010C5F8;
extern f64 D_8010C670;
extern s32 D_801F43D8;
extern f64 D_8010C600;
extern f64 D_8010C608;
extern f64 D_8010C170;
extern f64 D_8010C4D8;
extern f64 D_8010C4E0;
extern f64 D_8010C4E8;
extern f64 D_8010C180;

/* Controller status query packet (8 bytes). */
typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeLow;
    u8 typeHigh;
    u8 status;
    u8 dummy1;
} UnkCFE9C;

extern s32 D_802AB038;
extern u8 *D_802AB040;
extern s32 D_802AB04C;
extern s32 D_802AB060;
extern f32 D_8010C1E8;
extern f32 D_8010C1EC;
extern f32 D_8010C1F0;
extern s32 D_802AE98C;
extern u8 D_802AE950[];
extern u8 D_802AE940;
extern u8 D_802AE900[];
extern u8 D_802AE8FC;
extern s32 D_802AE93C;
extern s32 D_802AE938;
extern s32 *D_802AD370;
extern f64 D_8010C200;
s32 func_801C3AFC(s32 *, s32 *, s32);
s32 func_801CA830(s32 *, s32, s32);
s32 func_801CA844();
s32 func_801CA1A0(s32 *, s32, s32);
typedef struct {
    u8 unk0[2];
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} Ent8 __attribute__((packed));
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4[8];
} Ent12 __attribute__((packed));
s32 func_801CF710(s32, void *);
s32 func_801C7430(void *, void *, s32);
extern s32 D_802AB058;
void func_801C2A84(s32 *, s32 *, s32);
s32 func_801C28A0(s32 *, s32);
void func_801C1054(s32);
extern u8 *D_802AB044;
extern u8 D_802AB2C8[];
extern u8 *D_802AB03C;
void func_801C2768();
s32 func_801CB280(s32, s32, u32 *, s32, s32);
void func_801CA040(s32 *, s32, s32, s32);
u32 *func_801C86E0();
u32 *func_801C8B24();
void func_801C8EC0();
u32 *func_801C9300();
s32 func_801CB8AC();
s32 func_801C984C();
f32 func_801C2314(f32);
void func_801CBD00(ObjectNode *, ObjectNode *, f32);

typedef struct {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ u8 pad2A[4];
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
} UnkC83EC;

typedef struct UnkC8EC0Info {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
} UnkC8EC0Info;

typedef struct UnkC8EC0Dims {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
} UnkC8EC0Dims;

typedef struct UnkC8EC0Stream {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 unk8;
    /* 0x0C */ UnkC8EC0Info *unkC;
    /* 0x10 */ UnkC8EC0Dims *unk10;
} UnkC8EC0Stream;

typedef struct UnkC8EC0Obj {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ UnkC8EC0Stream *unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
} UnkC8EC0Obj;

/* Envelope mixer (libultra ALEnvMixer) and its parameter records, as used by func_801C9300. */
typedef struct EnvParam {
    /* 0x00 */ struct EnvParam *next;
    /* 0x04 */ s32 delta;
    /* 0x08 */ s16 type;
    /* 0x0A */ s16 unity;
    /* 0x0C */ s32 data;
    /* 0x10 */ s32 moredata;
} EnvParam;

typedef struct {
    /* 0x00 */ EnvParam *next;
    /* 0x04 */ s32 delta;
    /* 0x08 */ s16 type;
    /* 0x0A */ s16 unity;
    /* 0x0C */ s32 pitch;
    /* 0x10 */ s16 volume;
    /* 0x12 */ u8 pan;
    /* 0x13 */ u8 fxMix;
    /* 0x14 */ s32 samples;
    /* 0x18 */ s32 wave;
} EnvStartParamAlt;

typedef struct EnvFilter {
    /* 0x00 */ struct EnvFilter *source;
    /* 0x04 */ void *handler;
    /* 0x08 */ s32 (*setParam)(void *, s32, s32);
} EnvFilter;

typedef struct {
    /* 0x00 */ EnvFilter filter;
    /* 0x0C */ u8 padC[0xC];
    /* 0x18 */ s16 pan;
    /* 0x1A */ s16 volume;
    /* 0x1C */ s16 cvolL;
    /* 0x1E */ s16 cvolR;
    /* 0x20 */ s16 dryamt;
    /* 0x22 */ s16 wetamt;
    /* 0x24 */ u16 lratl;
    /* 0x26 */ s16 lratm;
    /* 0x28 */ s16 ltgt;
    /* 0x2A */ u16 rratl;
    /* 0x2C */ s16 rratm;
    /* 0x2E */ s16 rtgt;
    /* 0x30 */ s32 delta;
    /* 0x34 */ s32 segEnd;
    /* 0x38 */ s32 first;
    /* 0x3C */ EnvParam *ctrlList;
    /* 0x40 */ EnvParam *ctrlTail;
} EnvMixer;

extern u8 D_8010C480[];
extern u8 D_8010C484[];
extern s16 D_801F45B0[];
u32 *func_801C9920();
f32 func_801C9FA4(f32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801CA030(u8 *arg0, u8 *arg1, s32 arg2);

/* Variable-length byte stream decoder state (fields as used by func_801C2144). */
typedef struct {
    u8 unk0[0xC];
    u32 unkC;
    u8 unk10[4];
    u32 unk14;
    u8 unk18[0x20];
    u8 *unk38;
    u8 unk3C[0x62];
    u16 unk9E;
    u8 unkA0[0x18];
    u8 unkB8;
} UnkStream2144;



extern ObjectNode *D_801F46D0;
extern u8 D_801F46F0;
extern u32 D_A4500000;
extern u32 D_A4600000;
extern u8 *D_801F55E0[];
extern u32 D_802AB028;
extern s32 D_802AB074;
extern u8 D_8010C680[];
extern u8 D_8010C684[];
extern u32 D_A4040000;
u32 func_801C7D90(u32);
s32 func_801CE730(void);
extern s32 D_802AB078;
extern s32 D_802AB07C;
extern u8 *D_802AB080;
extern s32 D_802B0C6C;
typedef struct {
    void *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    u8 transferInfo[0x60];
} PiHandleY;
extern PiHandleY D_802B0C60;
extern u8 D_802B0C64;
extern u8 D_802B0C65;
extern u8 D_802B0C66;
extern u8 D_802B0C67;
extern u8 D_802B0C68;
extern u8 D_802B0C69;
extern s32 D_802B0C70;
extern s32 D_801F55DC;
extern u8 D_802AFBE4;
extern u8 D_802AFBE5;
extern u8 D_802AFBE6;
extern u8 D_802AFBE7;
extern u8 D_802AFBE8;
extern u8 D_802AFBE9;
extern s32 D_802AFBEC;
extern s32 D_802AFBF0;
void func_801D2020(u8 *, s32);
void func_801C2A4C(u8 *, u8 *, s32);


u64 func_801D3B60(u64, u64, u64 *);




void func_8014A9FC();

u32 func_80139CA0(u8 *);








s32 func_801D20F8();








void *func_801D211C();













/* Tail of func_801C6CEC (overlaid by func_801C6DD4). */

/* 0x801F4764: current render object used by the 0x801D00xx wrappers. */


































































void func_801C249C(s32 *arg0, s32 arg1);


extern s32 D_802AB064;






extern s32 D_802AB06C;
extern s32 D_802AB068;








extern s32 D_802AB050;
void func_801C1C1C(u8 *, s32, f32);
void func_801C1A90(u8 *, s32);
void func_801C1FD8(u8 *);
void func_801C15B8(u8 *, s32);
void func_801C1DB4(u8 *);
f32 func_801C2088(u8 *);
f32 func_801C20D8(u8 *);
s32 func_801BF800(u8 *, s32);



extern u8 *D_801F40C0[];
void func_801C1D48(u8 *);
void func_801C1FBC(u8 *);
void func_801C19FC(u8 *, s32);
void func_801CBBE0(ObjectNode *, ObjectNode *);
void func_801CBD90(u8 *, u8 *, s16, s32);
void func_801CBE50(u8 *, u8 *, u8);


extern s32 D_802AB050;
extern u16 D_802AB054;
extern u16 D_802AB056;
void func_801CBEE0(ObjectNode *, ObjectNode *, u8);








f32 func_801C6000(f32);



extern s32 D_802AB05C;


extern const f64 D_8010C188, D_8010C190, D_8010C198, D_8010C1A0, D_8010C1A8, D_8010C1B0, D_8010C1B8, D_8010C1C0, D_8010C1C8, D_8010C1D0, D_8010C1D8, D_8010C1E0;
extern f64 D_8010C188;
extern f64 D_8010C190;
extern f64 D_8010C198;
extern f64 D_8010C1A0;
extern f64 D_8010C1A8;
extern f64 D_8010C1B0;
extern f64 D_8010C1B8;
extern f64 D_8010C1C0;
extern f64 D_8010C1C8;
extern f64 D_8010C1D0;
extern f64 D_8010C1D8;
extern f64 D_8010C1E0;










extern u8 D_802AB258[];
extern u8 D_802AB290[];
extern u8 D_802AB090[];
extern u8 *D_802AD350;
extern s32 D_801F4180;
void func_8017F9A4(u8 *, void *, void *);
s32 func_801C3198(s32, s32);
void func_801C3364(s32);
void func_801CB1BC(s32 *);
extern s32 D_802AD358;
extern s32 D_802AD35C;
extern s32 D_802AD360;
extern s32 D_802AD364;
extern s32 D_802AD368;
extern s32 D_802AD36C;
extern s32 D_802AD324;
extern s32 D_802AD328;
extern s32 D_802AD32C;
extern s32 D_802AD330;
extern s32 D_801F417C;
extern u8 D_802AB0A0[];
extern u8 D_802AB0A8[];
extern u8 D_802AB270[];
extern u8 D_802AB2A8[];
s32 func_801C35B8(u32 *);
void func_801C3710(void *, void *);
void func_801C3040(volatile s32);
void func_801C6550(Thread801 *, s32, u32, s32, void *, s32);
void func_801C7860(QNode *);
void *func_801D0AB0(void);
void *func_801D1320(void);




extern s32 D_802AB070;
extern s32 D_802AD358;
extern s32 D_802AD360;
extern s32 D_802AD368;
extern s32 D_802AD36C;

/* Entry in the command table at D_802AD358 (0x18 bytes each). */
typedef struct Unk802AD358Ent {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
} Unk802AD358Ent;






f32 func_801C4030(f32 arg0);

extern f64 D_8010C218;
extern f64 D_8010C220;
extern f64 D_8010C228;
extern f64 D_8010C230;
extern f64 D_8010C238;
extern f64 D_8010C240;
extern f64 D_8010C248;
extern f64 D_8010C258;
extern f64 D_8010C260;
extern f32 D_8010C250;
extern f32 D_8010C270;


f32 func_801C4040(f32 x);

extern f64 D_8010C280;
extern f64 D_8010C288;
extern const f64 D_8010C280;
extern const f64 D_8010C288;
void func_801C4190(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);

void func_801C4510(u32 *m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);


extern f64 D_8010C2A0;
extern f64 D_8010C2A8;
extern f64 D_8010C2B0;
extern f64 D_8010C2B8;
extern f64 D_8010C2C0;
extern const f64 D_8010C2A0;
extern const f64 D_8010C2A8;
extern const f64 D_8010C2B0;
extern const f64 D_8010C2B8;
extern const f64 D_8010C2C0;
void func_801C48A0(f32 mf[4][4], u8 *l, s32 *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight);

void func_801C5224(u32 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32 arg17, s32 arg18, s32 arg19);


void func_801C5300(f32 *arg0, u32 *arg1);

void func_801C5398(f32 mf[4][4], u32 *m);

void func_801C5440(s32 *arg0);

void func_801C5490(u32 *arg0);

void func_801C5580(f32 b[4][4], f32 a[4][4], f32 c[4][4]);

void func_801C565C(f32 *m, f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz);


void func_801C5710(u8 *arg0, u8 *arg1, u8 *arg2);

void func_801C5784(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_801C5810(f32 *arg0, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
static inline void split_externs_801C5810(void) { extern f64 D_8010C2D0; extern f64 D_8010C2D8; extern f64 D_8010C2E0; f32 func_801C4040(f32); f32 func_801C6000(f32); }

void func_801C59C0(u32 *arg0, u16 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);


void func_801C5B90(f32 mf[4][4], f32 a, f32 x, f32 y, f32 z);
static inline void split_externs_801C5B90(void) { extern f32 D_801F43A0; f32 func_801C6000(f32); f32 func_801C4040(f32); }

void func_801C5CEC(u32 *m, f32 a, f32 x, f32 y, f32 z);
static inline void split_externs_801C5CEC(void) { extern f32 D_801F43A0; f32 func_801C6000(f32); f32 func_801C4040(f32); }


void func_801C5E70(f32 *arg0, f32 *arg1, f32 *arg2);


void func_801C5F20(s32 *arg0, f32 arg1, f32 arg2, f32 arg3);

void func_801C5F80(s32 arg0, f32 arg1, f32 arg2, f32 arg3);


extern f64 D_8010C318;
extern f64 D_8010C320;
extern f64 D_8010C328;
extern f64 D_8010C330;
extern f64 D_8010C338;
extern f64 D_8010C340;
extern f64 D_8010C348;
extern f32 D_8010C350;
extern f64 D_8010C358;
extern f64 D_8010C360;

f32 func_801C6000(f32 x);

void func_801C61A0(s32 *arg0, f32 arg1, f32 arg2, f32 arg3);


void func_801C61F4(u32 *m, f32 x, f32 y, f32 z);


void func_801C6270(u8 *arg0, s32 arg1, s32 arg2, s16 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7, u16 arg8, u16 arg9);









/* Original compiler padding. */
extern u8 D_801F43F0[];


/* osCreateMesgQueue: initialise an empty message queue over the caller's buffer of `count` slots.
 * D_801F43F0 is __osThreadTail, the empty thread-queue sentinel. */
void func_801C6520(OSMesgQueue *queue, void **msg, s32 count) {
    queue->mtqueue = D_801F43F0;
    queue->fullqueue = D_801F43F0;
    queue->validCount = 0;
    queue->first = 0;
    queue->msgCount = count;
    queue->msg = msg;
}

/* Original compiler padding. */
const u32 D_801C6544_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osCreateThread: initialize a stopped thread that will run entry(arg) on the
 * given stack, and add it to the active-thread list. */
void func_801C6550(Thread801 *t, s32 id, u32 entry, s32 arg, void *sp, s32 pri) {
    s32 savedMask;

    t->id = id;
    t->priority = pri;
    t->next = NULL;
    t->queue = NULL;
    t->pc = entry;
    t->a0 = arg;
    t->sp = (u64)(s32)sp - OS_THREAD_STACK_ARGS;
    t->ra = (s32)func_801C6F60;
    t->sr = OS_THREAD_INITIAL_SR;
    t->fpcsr = OS_FPCSR_INIT;
    t->rcp = OS_THREAD_INITIAL_RCP;
    t->fp = 0;
    t->state = OS_STATE_STOPPED;
    t->flags = 0;
    savedMask = func_801C6F70();
    t->tlnext = D_801F43FC;
    D_801F43FC = (QNode *)t;
    func_801C6F90(savedMask);
}




void func_801C6D8C(ObjectNode *arg0, QNode *arg1);

ObjectNode *func_801C6DD4(ObjectNode *arg0);


void func_801C6FB0(QNode *arg0) __attribute__((noreturn));
void func_801C6F60(void);





void func_801C6FB0(QNode *arg0);


u64 func_801C7080(void);


void func_801C7110(void);









s32 func_801C7430(void *arg0, void *arg1, s32 flags);


s32 func_801C7560(u8 *arg0, s32 arg1, s32 flags);

typedef struct { OSMesgQueue *unk0; s32 unk4; } Unk802AD560;
extern Unk802AD560 D_802AD560[];

void func_801C7690(s32 arg0, OSMesgQueue *arg1, s32 arg2);


void func_801C76F0(QNode *arg0, s32 arg1);


extern u8 D_802AE8C0[];
extern u8 D_802AE8E0[];
extern u8 D_802AE8F8[];
s32 func_801CFC50(void *, s32, void *);

s32 func_801C77C0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4, volatile s32 arg6, volatile s32 arg7);


void func_801C7860(QNode *arg0);


void func_801C7980(u8 *arg0);


void func_801C7A40(ObjectNode *arg0, ObjectNode *arg1);


extern ObjectNode *D_801F4410;
extern s32 D_802AD5E0;
extern s32 D_802AD5E4;

void func_801C7A80(void);

void func_801C7AD4(void);

void func_801C7C10(s64 arg0);

s64 func_801C7C70(s32 *arg0);




u32 func_801C7D90(u32 a0);





typedef struct Unk801C7F54Entry {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ u8 pad0E[0x2];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ u8 *unk20;
    /* 0x24 */ u8 *unk24;
} Unk801C7F54Entry; /* size = 0x28 */

void func_801C7EB0(s16 *arg0);
static inline void split_externs_801C7EB0(void) { extern f64 D_8010C440; }

void func_801C7F54(u8 *arg0,u8 *arg1,s32 arg2);

void func_801C83EC(UnkC83EC *arg0, u32 *arg1);

void func_801C84A4(s32 *arg0, s32 (*arg1)(s32 *), u32 *arg2);

void func_801C8554(s32 *arg0, u32 *arg1);
static inline void split_externs_801C8554(void) { extern void func_801CA1D0(void); extern void func_801CA3BC(void); }

void func_801C85E0(s32 *arg0, s32 arg1, s32 arg2);
static inline void split_externs_801C85E0(void) { extern void func_801C91F0(void); extern s32 func_801C92CC(s32 *, s32, s32); extern void func_801CA040(s32 *, s32, s32, s32); }

void func_801C863C(s32 *arg0, s32 arg1, s32 arg2);
static inline void split_externs_801C863C(void) { extern u32 *func_801CA060(s32 *, s32, s32, s32, u32 *); }

void func_801C8698(s32 *arg0);
static inline void split_externs_801C8698(void) { extern void func_801CB060(void); extern s32 func_801CB160(s32 *, s32, s32); extern void func_801CA040(s32 *, s32, s32, s32); }


u32 *func_801C86E0(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, u32 *p);

u32 *func_801C8B24(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, u32 *p);

void func_801C8EC0(UnkC8EC0Obj *arg0, s32 arg1, UnkC8EC0Stream *arg2);

s32 func_801C906C(u32 *arg0, u8 *arg1, s32 arg2, s32 arg3, u16 arg4, s32 arg5, s32 arg6);


s32 func_801C91F0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4);

s32 func_801C92CC(s32 *arg0, s32 arg1, s32 arg2);


u32 *func_801C9300(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, u32 *p);

s32 func_801C984C(s32 *arg0, s32 arg1, s32 arg2);

extern u8 D_8010C480[];
extern u8 D_8010C484[];
extern s16 D_801F45B0[];
s16 func_801C9D24(f64 arg0, f64 arg1, s32 arg2, u16 *arg3);

typedef struct {
    /* 0x00 */ s32 *unk0;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 pad3C[0xC];
    /* 0x48 */ s32 unk48;
} Unk801C9920Obj;

u32 *func_801C9920(Unk801C9920Obj *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, u32 *p0);

f64 func_801C9C20(f64 arg0, s32 *arg1);

f64 func_801C9D00(f64 arg0, s32 arg1);

s16 func_801C9D24(f64 arg0, f64 arg1, s32 arg2, u16 *arg3);

f32 func_801C9FA4(f32 arg0, s32 arg1, s32 arg2, s32 arg3);


void func_801CA030(u8 *arg0, u8 *arg1, s32 arg2);


void func_801CA040(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);


u32 *func_801CA060(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, u32 *p);

s32 func_801CA1A0(s32 *arg0, s32 arg1, s32 arg2);

u32 *func_801CA1D0(s32 *arg0, u16 *arg1, s32 arg2, s32 arg3, u32 *arg4);

s32 func_801CA3BC(s32 *arg0, s32 arg1, s32 arg2);


u32 *func_801CA480(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4);

typedef struct {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ u8 pad14[8];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ s16 *unk20;
    /* 0x24 */ s32 pad24;
} Func801CA844Entry; /* size 0x28 */

typedef struct {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ Func801CA844Entry *entries;
} Func801CA844Obj;

s32 func_801CA830(s32 *arg0, s32 arg1, s32 arg2);

extern const f64 D_8010C5E0;
extern f64 D_8010C5E0;
extern const f64 D_8010C5E8;
s32 func_801CA844(Func801CA844Obj *arg0, s32 arg1, s32 *arg2);

u32 *func_801CAA34(s32 *arg0, Unk801CAA34Obj *arg1, s32 arg2, s32 arg3, u32 *arg4);

u32 *func_801CAC4C(s32 *arg0, s32 arg1, s32 buff, s32 count, u32 *p);

u32 *func_801CADBC(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4);

u8 *func_801CAF2C(u8 *arg0, u32 arg1, u32 arg2, u8 *arg3);

extern const f64 D_8010C5F8;
extern const f64 D_8010C600;
extern const f64 D_8010C608;
extern const f64 D_8010C5F8, D_8010C600, D_8010C608;
f32 func_801CAFC8(u8 *arg0, s32 arg1);
static inline void split_externs_801CAFC8(void) { extern const f64 D_8010C5F8, D_8010C600, D_8010C608; }


u32 *func_801CB060(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4);

s32 func_801CB160(s32 *arg0, s32 arg1, s32 arg2);


void func_801CB190(ObjectNode *arg0);

void func_801CB1BC(s32 *arg0);

void func_801CB1EC(ObjectNode *arg0, s32 *arg1);

void func_801CB20C(ObjectNode *arg0);


void func_801CB240(u32 *arg0, u32 arg1, u32 arg2);


s32 func_801CB280(s32 arg0, s32 arg1, u32 *arg2, s32 arg3, s32 arg4);


void func_801CB2D0(u8 *arg0, u8 *arg1, s32 arg2);


s32 func_801CB864(u8 *arg0, s32 arg1);
s32 func_801CB8F8(s32 *arg0, s32 **arg1);
void func_801CB7D0(ObjectNode *arg0);

void func_801CB310(s32 *arg0, s32 *arg1);

u8 *func_801CB5DC(u8 *arg0, s32 *arg1, s32 *arg2, s32 arg3);

ObjectNode *func_801CB78C(void);

void func_801CB7B8(ObjectNode *arg0);

void func_801CB7D0(ObjectNode *arg0);

void func_801CB824(ObjectNode *arg0, ObjectNode *arg1);

extern f64 D_8010C620;
extern f64 D_8010C628;
s32 func_801CB864(u8 *arg0, s32 arg1);

extern f64 D_8010C630;
extern f64 D_8010C638;
s32 func_801CB8AC(u8 *arg0, s32 arg1);

s32 func_801CB8F8(s32 *arg0, s32 **arg1);

void func_801CB9A0(s32 *arg0);



void func_801CB9B0(s32 *arg0, s32 *arg1);

s32 func_801CBA00(u8 *arg0, u8 *arg1, u16 *arg2);

s32 func_801CBB28(ObjectNode *arg0, s32 *arg1, s32 arg2);

void func_801CBBE0(ObjectNode *arg0, ObjectNode *arg1);


s32 func_801CBC60(u8 *, u8 *, s32);
s32 func_801CBC60(u8 *arg0, u8 *arg1, s32 arg2);


void func_801CBD00(ObjectNode *arg0, ObjectNode *arg1, f32 arg2);

void func_801CBD90(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3);


void func_801CBE50(u8 *arg0, u8 *arg1, u8 arg2);

void func_801CBEE0(ObjectNode *arg0, ObjectNode *arg1, u8 arg2);

u8 *func_801CBF70(s32 *arg0, s16 arg1, s32 arg2, s32 arg3);


void func_801CC010(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);


void func_801CC030(u16 *arg0, u16 arg1);


void func_801CC050(f32 *arg0, f32 arg1, f32 arg2);


void func_801CC0D0(u16 *arg0, u16 arg1);

void func_801CC0E0(u8 *arg0, s16 arg1);

void func_801CC0E8(u8 *arg0, s16 arg1, s16 arg2);

typedef struct {
    /* 0x00 */ s16 w;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s16 h;
    /* 0x0E */ s16 unkE;
} SpriteGlyph;

typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 right;
    /* 0x06 */ s16 bottom;
    /* 0x08 */ f32 scaleX;
    /* 0x0C */ f32 scaleY;
    /* 0x10 */ s16 xSpacing;
    /* 0x12 */ s16 ySpacing;
    /* 0x14 */ u16 flags;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u8 r;
    /* 0x19 */ u8 g;
    /* 0x1A */ u8 b;
    /* 0x1B */ u8 a;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s16 count;
    /* 0x2A */ s16 maxGfx;
    /* 0x2C */ s16 lineH;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ u8 mode;
    /* 0x31 */ u8 siz;
    /* 0x34 */ SpriteGlyph *glyphs;
    /* 0x38 */ Gfx *buf0;
    /* 0x3C */ Gfx *buf1;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
} SpriteText;

extern s32 D_801F46E0;

/* gbi.h-style display list helpers used by the sprite bitmap loader */
#define SP_SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define SP_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SP_MAX(a, b) ((a) > (b) ? (a) : (b))
#define SP_WORDS(txls, b) SP_MAX(1, ((txls) * (b) / 8))
#define SP_WORDS_4b(txls) SP_MAX(1, ((txls) / 16))
#define SP_DXT(words) (((1 << 11) + (words) - 1) / (words))

#define spSetTImg(pkt, f, s, w, i) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = SP_SHIFTL(0xFD, 24, 8) | SP_SHIFTL(f, 21, 3) | SP_SHIFTL(s, 19, 2) | SP_SHIFTL((w) - 1, 0, 12); \
    _g->w1 = (u32)(i); \
}
#define spSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = SP_SHIFTL(0xF5, 24, 8) | SP_SHIFTL(fmt, 21, 3) | SP_SHIFTL(siz, 19, 2) | SP_SHIFTL(line, 9, 9) | SP_SHIFTL(tmem, 0, 9); \
    _g->w1 = SP_SHIFTL(tile, 24, 3) | SP_SHIFTL(palette, 20, 4) | SP_SHIFTL(cmt, 18, 2) | SP_SHIFTL(maskt, 14, 4) | SP_SHIFTL(shiftt, 10, 4) | SP_SHIFTL(cms, 8, 2) | SP_SHIFTL(masks, 4, 4) | SP_SHIFTL(shifts, 0, 4); \
}
#define spNoOp(pkt, c) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = SP_SHIFTL(c, 24, 8); \
    _g->w1 = 0; \
}
#define spLoadBlock(pkt, tile, uls, ult, lrs, dxt) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = SP_SHIFTL(0xF3, 24, 8) | SP_SHIFTL(uls, 12, 12) | SP_SHIFTL(ult, 0, 12); \
    _g->w1 = SP_SHIFTL(tile, 24, 3) | SP_SHIFTL(SP_MIN(lrs, 0x7FF), 12, 12) | SP_SHIFTL(dxt, 0, 12); \
}
#define spLoadBlockS(pkt, tile, uls, ult, lrs) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = SP_SHIFTL(0xF3, 24, 8) | SP_SHIFTL(uls, 12, 12) | SP_SHIFTL(ult, 0, 12); \
    _g->w1 = SP_SHIFTL(tile, 24, 3) | SP_SHIFTL(SP_MIN(lrs, 0x7FF), 12, 12); \
}
#define spSetTileSize(pkt, t, uls, ult, lrs, lrt) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = SP_SHIFTL(0xF2, 24, 8) | SP_SHIFTL(uls, 12, 12) | SP_SHIFTL(ult, 0, 12); \
    _g->w1 = SP_SHIFTL(t, 24, 3) | SP_SHIFTL(lrs, 12, 12) | SP_SHIFTL(lrt, 0, 12); \
}

#define spLoadTextureBlockS(pkt, timg, fmt, siz, ldsiz, width, height, lrs, line) { \
    spSetTImg(pkt, fmt, ldsiz, 1, timg); \
    spSetTile(pkt, fmt, ldsiz, 0, 0, 7, 0, 2, 0, 0, 2, 0, 0); \
    spNoOp(pkt, 0xE6); \
    spLoadBlockS(pkt, 7, 0, 0, lrs); \
    spNoOp(pkt, 0xE7); \
    spSetTile(pkt, fmt, siz, line, 0, 0, 0, 2, 0, 0, 2, 0, 0); \
    spSetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); \
}
#define spLoadTextureBlock(pkt, timg, fmt, siz, ldsiz, width, height, lrs, dxt, line, cms, cmt, masks, maskt, shifts, shiftt) { \
    spSetTImg(pkt, fmt, ldsiz, 1, timg); \
    spSetTile(pkt, fmt, ldsiz, 0, 0, 7, 0, 2, 0, 0, 2, 0, 0); \
    spNoOp(pkt, 0xE6); \
    spLoadBlock(pkt, 7, 0, 0, lrs, dxt); \
    spNoOp(pkt, 0xE7); \
    spSetTile(pkt, fmt, siz, line, 0, 0, 0, cmt, maskt, shiftt, cms, masks, shifts); \
    spSetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); \
}

typedef struct {
    unsigned int cmd : 8;
    unsigned int xl : 12;
    unsigned int yl : 12;
    unsigned int pad : 5;
    unsigned int tile : 3;
    unsigned int xh : 12;
    unsigned int yh : 12;
    unsigned int s : 16;
    unsigned int t : 16;
    unsigned int dsdx : 16;
    unsigned int dtdy : 16;
} SpTexRect;

void func_801CC0F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_801CC118(Gfx **glp, SpriteText *s, SpriteGlyph *b, s32 x, s32 y, s32 xx, s32 yy, s32 fs, s32 ft, s32 sx, s32 sy);

void func_801CD3C0(Gfx **arg0);

extern s32 D_801F46E0;
extern u8 D_8010C660[];
extern u8 D_8010C664[];
void func_801CC118(Gfx **, SpriteText *, SpriteGlyph *, s32, s32, s32, s32, s32, s32, s32, s32);
Gfx *func_801CD578(SpriteText *s);

void func_801CE22C(Gfx **arg0);


u32 func_801CE2F0(void);

s32 func_801CE300(s32 arg0);


s32 func_801CE430(s32 arg0, s32 arg1);


s32 func_801CE4D0(void);

typedef struct {
    u32 type;
    u32 flags;
    u32 ucode_boot;
    u32 ucode_boot_size;
    u32 ucode;
    u32 ucode_size;
    u32 ucode_data;
    u32 ucode_data_size;
    u32 dram_stack;
    u32 dram_stack_size;
    u32 output_buff;
    u32 output_buff_size;
    u32 data_ptr;
    u32 data_size;
    u32 yield_data_ptr;
    u32 yield_data_size;
} Task801CE4F0;
extern Task801CE4F0 D_802AD630;
extern u32 D_802AD634, D_802AD640, D_802AD648, D_802AD64C, D_802AD650;
extern u32 D_802AD658, D_802AD65C, D_802AD660, D_802AD668, D_802AD66C;
void func_801D1D00(void *, void *, s32);
void func_801C6470(void *, s32);
void func_801CE750(u32);
s32 func_801CE760(u32);
s32 func_801CE790(s32, u32, u32, u32);
extern u32 D_A0000000;


void func_801CE4F0(Task801CE4F0 *arg0);

void func_801CE6FC(void);


s32 func_801CE730(void);


void func_801CE750(u32 arg0);

s32 func_801CE760(u32 arg0);


s32 func_801CE790(s32 arg0, u32 arg1, u32 arg2, u32 arg3);


void func_801CE890(void);


u32 func_801CE8B0(Unk801F4764 *arg0);


u32 func_801CE900(void);

s32 func_801CE910(void);


void func_801CE950(void);


u32 func_801CEA60(void);


void func_801CEAA0(s32 arg0);

/* Object returned by func_801CEDF0 (the current render object). */
typedef struct Unk801CEDF0 {
    /* 0x00 */ u8 pad0[0x02];
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u8 pad4[0x0C];
    /* 0x10 */ u8 *unk10;
    /* 0x14 */ s32 unk14;
} Unk801CEDF0;

/* Thread argument of func_801CEC38 (points at D_801F4770). */
typedef struct ThreadArg801CEC38 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ OSMesgQueue *unk0C;
} ThreadArg801CEC38;

extern u16 D_802AD670;
Unk801CEDF0 *func_801CEDF0(void);
void func_801CF0C0(void);

static inline void func_801CEC38_update(void) {
    u32 old = D_802AD5E0;

    D_802AD5E0 = func_801C62B0();
    *(u64 *)&D_802AD5E8 += (u32)(D_802AD5E0 - old);
}

void func_801CEC38(ThreadArg801CEC38 *arg0);

s32 func_801CEDD0(s32 arg0);


Unk801CEDF0 *func_801CEDF0(void);


void func_801CEE00(s32 arg0, s32 arg1, u16 arg2);


void func_801CEE60(Unk801F4764 *arg0);


void func_801CEEB0(s32 arg0);


void func_801CF020(f32 arg0);


void func_801CF070(u32 arg0);


extern volatile u32 D_A4400000;
void func_801CF0C0(void);


void func_801CF3B0(s32 arg0);


s32 func_801CF410(u32 arg0, s32 *arg1);

s32 func_801CF4A0(void);


extern u8 D_8010C6B0[];
extern u8 D_8010C6B4[];
s32 func_801CF4C0(u32 arg0, s32 arg1);



s32 func_801CF530(s32 arg0);

void func_801CF5B8(u8 *arg0);

void func_801CF654(void);


s32 func_801CF710(s32 arg0, void *arg1);
static inline void split_externs_801CF710(void) { extern u8 D_8010C6D0[]; extern u8 D_8010C6D4[]; }

/* Original compiler padding. */


void func_801CF7D0(void);

s32 func_801CF824(void);

void func_801CF890(void);


s32 func_801CF8C0(s32 arg0, s32 arg1, s32 arg2);
static inline void split_externs_801CF8C0(void) { extern s32 D_801F54C0; }

void func_801CFA5C(u8 *arg0, u8 *arg1);

void func_801CFB10(u8 arg0);


s32 func_801CFBD0(s32 arg0);


s32 func_801CFC50(void *arg0, s32 arg1, void *arg2);

void func_801CFDD8(u8 arg0, u8 *arg1);

s32 func_801CFE9C(void *arg0, u8 *arg1);

s32 func_801D0030(void *arg0, u8 arg1, u8 *arg2);

void func_801D01C4(u8 arg0);

s32 func_801D0280(void *arg0, u8 arg1, void *arg2, s32 arg3);


s32 func_801D0370(void *arg0, u8 arg1, u8 *arg2, s32 arg3);

s32 func_801D03E0(s32 arg0, s32 *arg1);

extern s32 D_801F55C0;
extern s32 D_801F55C4;
extern s32 D_801F55C8;
extern s32 D_801F55CC;
extern s32 D_801F55D0;
extern s32 D_801F55D4;
extern s32 D_801F55D8;
extern s32 D_801F55F0;
extern u8 D_802AE990[];
extern u8 D_802AFB40[];
extern u8 D_802AEB40[]; /* thread stack inside the D_802AE990 block; needs D_802AEB40 = 0x802AEB40 in the linker symbols */
extern u8 D_802AFB58[];
extern u8 D_802B0CF0[];
extern u8 D_802B0CE0[];
void func_801C6520(OSMesgQueue *, void **, s32);
void func_801C6550(Thread801 *, s32, u32, s32, void *, s32);
void func_801C7690(s32, OSMesgQueue *, s32);
void func_801C76F0(QNode *, s32);
void func_801C7860(QNode *);
s32 func_801CEDD0(s32);
void func_801D1B60(void);
void func_801D13E0();
s32 func_801D0610(s32, u32, void *, u32);
s32 func_801D06E0();


void func_801D0480(s32 pri, OSMesgQueue *cmdQ, void **cmdBuf, s32 cmdMsgCnt);

s32 func_801D0610(s32 direction, u32 devAddr, void *dramAddr, u32 size);

s32 func_801D06E0(u8 *arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4);

extern s32 D_802AFB6C;
extern PiHandleY D_802AFB60;
extern u8 D_802AFB64;
extern u8 D_802AFB65;
extern u8 D_802AFB66;
extern u8 D_802AFB67;
extern u8 D_802AFB68;
extern u8 D_802AFB69;
extern s32 D_802AFB70;
extern s32 D_801F55C0;
extern s32 func_801D0A90(void);
s32 func_801C7560(u8 *, s32, s32);


s32 func_801D08B0(s32 arg0, u8 *arg1, s32 arg2);


s32 func_801D0950(OSMesgQueue *mq, u8 *arg1, s32 flags);


s32 func_801D0A90(void);

void *func_801D0AB0(void);



void *func_801D0B90(void);


s32 func_801D0C90(void);

void func_801D119C(void);

void func_801D126C(void);

void *func_801D1320(void);



void func_801D17A0(s32);
void func_801D17F0(s32);
void func_801D1830(void);
s32 func_801D1880(u8 *, u32, u32 *);
s32 func_801D1A10(u8 *, u32, u32);
void func_801D13E0(void *args);


void func_801D17A0(s32 arg0);
static inline void split_externs_801D17A0(void) { extern s32 D_801F43E0; }


void func_801D17F0(s32 arg0);

void func_801D1830(void);


extern u8 *D_801F55E0[];
extern u8 D_8010C710[];
extern u8 D_8010C714[];

s32 func_801D1880(u8 *arg0, u32 arg1, u32 *arg2);

s32 func_801D1A10(u8 *arg0, u32 arg1, u32 arg2);


void func_801D1B60(void);

s32 func_801D1BB4(void);

void func_801D1C20(void);


s32 func_801D1C50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);




void func_801D2020(u8 *arg0, s32 arg1);

u8 *func_801D20C0(u8 *arg0, u8 arg1);

s32 func_801D20F8(u8 *arg0);

void *func_801D211C(void *arg0, u8 *arg1, u32 arg2);


typedef char *va_list;
#define va_start(ap, last) ((ap) = (va_list)__builtin_next_arg(last))

typedef struct {
    union {
        s64 ll;
        f64 ld;
    } v;
    char *s;
    s32 n0;
    s32 nz0;
    s32 n1;
    s32 nz1;
    s32 n2;
    s32 nz2;
    s32 prec;
    s32 width;
    u32 nchar;
    u32 flags;
    u8 qual;
} PutfldArgs;

#define PUTFLD_ARG(ap, T) (*(T *)(((ap) = (char *)((((s32)(ap)) + sizeof(T) - 1) & -sizeof(T)) + sizeof(T)) - sizeof(T)))

void func_801D2750(PutfldArgs *x, va_list *pap, u8 code, u8 *ac);
extern u8 D_8010C730[];
extern s32 D_8010C738[];
extern u8 D_8010C750[];
extern u8 D_801F5600[];
extern u8 D_801F5624[];

#define _PROUT(buf, n) \
    if ((n) > 0) { \
        arg = prout(arg, buf, n); \
        if (arg == 0) { \
            return x.nchar; \
        } \
        x.nchar += (n); \
    }
#define _PAD(m, src) \
    { \
        s32 i, j; \
        for (j = (m); j > 0; j -= i) { \
            i = j > 32 ? 32 : j; \
            _PROUT(src, i); \
        } \
    }

s32 func_801D21A8();
s32 func_801D21E0();

s32 func_801D2150(u8 *arg0, u8 *arg1, ...);

s32 func_801D21A8(void *arg0, u8 *arg1, u32 arg2);


s32 func_801D21E0(char *(*prout)(char *, u8 *, u32), char *arg, u8 *fmt, va_list args);

void func_801D2750(PutfldArgs *x, va_list *pap, u8 code, u8 *ac);

/* Original compiler padding. */
void func_801D3B40(s32, s32, s32, s32);
extern u8 D_801F5650[];
extern u8 D_801F5664[];
LongLongDiv func_801D2EE4(s64, s64);


u64 func_801D41A0(u64, u64);
void func_801D2C10(PutfldArgs *x, u8 code);


LongDiv func_801D2E60(s32 num, s32 den);

s64 func_801D3AA0(s64, s64);

LongLongDiv func_801D2EE4(s64 num, s64 den);

typedef struct { u8 b[3]; } Str3;
typedef struct {
    f64 d;
    char *s;
    s32 n0;
    s32 nz0;
    s32 n1;
    s32 nz1;
    s32 n2;
    s32 nz2;
    s32 prec;
    s32 width;
    s32 nchar;
    u32 flags;
} LdtobArgs;
extern f64 D_8010C8B0[];
extern Str3 D_8010C8F8;
extern Str3 D_8010C8FC;
extern f64 D_8010C900;
extern f64 D_8010C908;
extern char D_8010C910[];
s32 func_801D3460(s16 *, u16 *);
void func_801D34F8(LdtobArgs *, u8, char *, s16, s16);


void func_801D3020(LdtobArgs *args,u8 type);

s32 func_801D3460(s16 *arg0, u16 *arg1);

void func_801D34F8(LdtobArgs *px, u8 code, char *p, s16 nsig, s16 xexp);


typedef union {
    struct {
        s32 high;
        u32 low;
    } s;
    s64 ll;
} DSunion;

static inline s64 __negdi2(s64 u) {
    DSunion w;
    DSunion uu;

    uu.ll = u;

    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((u32)w.s.low > 0);

    return w.ll;
}

s64 func_801D3AA0(s64 u, s64 v);

extern u8 D_8010C070[];

typedef union {
    struct {
        u32 high;
        u32 low;
    } s;
    u64 ll;
} DIunion;

#define count_leading_zeros(count, x) \
    do { \
        u32 __xr = (x); \
        u32 __a; \
        __a = __xr < ((u32)1 << 16) ? (__xr < ((u32)1 << 8) ? 0 : 8) \
                                    : (__xr < ((u32)1 << 24) ? 16 : 24); \
        (count) = 32 - (D_8010C070[__xr >> __a] + __a); \
    } while (0)

#define udiv_qrnnd(q, r, n1, n0, d) \
    do { \
        u32 __d1, __d0, __q1, __q0, __r1, __r0, __m; \
        __d1 = (d) >> 16; \
        __d0 = (d) & 0xFFFF; \
        __r1 = (n1) % __d1; \
        __q1 = (n1) / __d1; \
        __m = __q1 * __d0; \
        __r1 = (__r1 << 16) | ((n0) >> 16); \
        if (__r1 < __m) { \
            __q1--, __r1 += (d); \
            if (__r1 >= (d)) \
                if (__r1 < __m) \
                    __q1--, __r1 += (d); \
        } \
        __r1 -= __m; \
        __r0 = __r1 % __d1; \
        __q0 = __r1 / __d1; \
        __m = __q0 * __d0; \
        __r0 = (__r0 << 16) | ((n0) & 0xFFFF); \
        if (__r0 < __m) { \
            __q0--, __r0 += (d); \
            if (__r0 >= (d)) \
                if (__r0 < __m) \
                    __q0--, __r0 += (d); \
        } \
        __r0 -= __m; \
        (q) = (__q1 << 16) | __q0; \
        (r) = __r0; \
    } while (0)

#define umul_ppmm(w1, w0, u, v) \
    do { \
        u64 __x = (u64)(u32)(u) * (u32)(v); \
        (w1) = (u32)(__x >> 32); \
        (w0) = (u32)__x; \
    } while (0)

#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
    do { \
        u32 __x = (al) - (bl); \
        (sh) = (ah) - (bh) - (__x > (al)); \
        (sl) = __x; \
    } while (0)


void func_801D3B40(s32 a, s32 b, s32 c, s32 d);

u64 func_801D3B60(u64 n, u64 d, u64 *rp);


u64 func_801D41A0(u64 u, u64 v);

