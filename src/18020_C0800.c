#include "common.h"
#include "structs.h"
#include "audio_synth.h"
#include "mus_song.h"
extern s32 D_802AB070;
extern s32 D_802AB050;
extern s32 D_802AB064;
extern s32 D_802AB068;
extern s32 D_802AB06C;
extern s32 D_802AB05C;
extern u32 D_802AB02C;
extern u32 D_802AB010[];
void func_801CB240(u32 *, u32, u32);
void func_801CB9B0();
s32 func_801CBA00(u8 *, u8 *, u16 *);
s32 func_801C3FC0(s32);


extern s32 D_801F54B0;
extern s32 D_802AB038;
extern u8 *D_802AB040;
extern s32 *D_802AB048;
s32 func_801C2B24(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u32 D_A4080000;
extern u8 D_802AE8A0[];
extern u8 D_802AE890[];
extern u16 D_802AB054;
extern u16 D_802AB056;



/* Music channel, as seen by the pitch-bend stream reader func_801C21FC. */
typedef struct UnkStream21FC {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 unkC;    /* MUS_CH_TIME: channel time, 8 fractional bits */
    /* 0x10 */ u8 pad10[0x08];
    /* 0x18 */ u32 unk18;   /* MUS_CH_PITCH_STREAM_TIME */
    /* 0x1C */ u8 pad1C[0x08];
    /* 0x24 */ f32 unk24;   /* pitch bend: unk70 * unk6C */
    /* 0x28 */ u8 pad28[0x0C];
    /* 0x34 */ u8 *unk34;   /* MUS_CH_PITCH_STREAM: read cursor */
    /* 0x38 */ u8 pad38[0x34];
    /* 0x6C */ f32 unk6C;   /* bend range (scale) */
    /* 0x70 */ f32 unk70;   /* current bend value, centred on 0 */
    /* 0x74 */ u8 pad74[0x2C];
    /* 0xA0 */ u16 unkA0;   /* ticks left in the current run */
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
extern u8 D_8010C5B0[];
extern u8 D_8010C5B4[];
u32 *func_801CADBC(s32 *, s32, s32, s32, u32 *);
u8 *func_801CAF2C(u8 *, u32, u32, u8 *);
u32 *func_801CAA34(s32 *, Unk801CAA34Obj *, s32, s32, u32 *);
extern u8 D_8010C614[];
extern ObjectNode *D_801F4410;
extern s32 D_801F4170;
extern volatile s32 D_801F4174;
typedef struct {
    u8 flag;
    u8 pad[3];
    s32 next;
    s32 prev;
} QueueHead;
extern QueueHead D_802AD318[];
extern s32 D_802AD354;
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
    /* 0x128 */ u32 fpcsr;
    /* 0x12C */ u32 rcp;
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
extern OSMesgQueue *D_802AD5A0;
extern void *D_802AD5A4;
void func_801C48A0(f32 *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
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

/* Music channel, as seen by the volume stream reader func_801C2144. */
typedef struct MusVolumeChannel {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ u32 time;              /* MUS_CH_TIME: eight fractional bits */
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u32 volumeStreamTime;  /* MUS_CH_VOLUME_STREAM_TIME */
    /* 0x18 */ u8 pad18[0x20];
    /* 0x38 */ u8 *volumeStream;      /* MUS_CH_VOLUME_STREAM: read cursor */
    /* 0x3C */ u8 pad3C[0x62];
    /* 0x9E */ u16 volumeRunLeft;     /* ticks left in the current run */
    /* 0xA0 */ u8 padA0[0x18];
    /* 0xB8 */ u8 sequenceVolume;     /* MUS_CH_SEQUENCE_VOLUME */
} MusVolumeChannel;



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






/* mus_cmd_stop (libmus Fstop): sequence command that ends the channel's track.
 * Clears its volume/pitch streams, song, effect and pending wavetable, and
 * returns a NULL stream so the channel stops reading notes. */
s32 func_801BF800(u8 *channel, s32 stream)
{
    *(s32 *)(channel + MUS_CH_VOLUME_STREAM) = 0;
    *(s32 *)(channel + MUS_CH_PITCH_STREAM) = 0;
    *(s32 *)(channel + MUS_CH_SONG) = 0;
    *(u16 *)(channel + MUS_CH_EFFECT_ID) = 0;
    *(s32 *)(channel + 0x44) = 0;
    *(s32 *)(channel + MUS_CH_PENDING_WAVETABLE) = 0;
    return 0;
}

/* mus_cmd_wave: sequence command that selects the channel's sample. The index is
 * one byte, or two (big-endian, top bit of the first set) when it exceeds 0x7F.
 * Returns the stream pointer past the operand. */
u8 *func_801BF824(u8 *channel, u8 *stream) {
    u16 sample = *stream++;
    if (sample & MUS_SEQUENCE_COMMAND_FLAG) {
        sample &= MUS_SEQUENCE_VALUE_MASK;
        sample <<= 8;
        sample |= *stream++;
    }
    *(u16 *)(channel + MUS_CH_SAMPLE_INDEX) = sample;
    return stream;
}

/* mus_cmd_portamento (libmus Fporta): sets the pitch-slide duration from one
 * operand byte; a nonzero duration starts the slide from the current note's
 * pitch. Returns the stream pointer past the operand. */
u8 *func_801BF85C(u8 *channel, u8 *stream) {
    channel[MUS_CH_SLIDE_DURATION] = *stream++;
    if (channel[MUS_CH_SLIDE_DURATION] != 0) {
        *(f32 *)(channel + MUS_CH_SLIDE_PITCH) = *(f32 *)(channel + MUS_CH_NOTE_PITCH);
    }
    return stream;
}

/* mus_cmd_portamento_off (libmus Fportoff): sequence command that turns the
 * pitch slide off. Takes no operand; returns the stream pointer unchanged. */
s32 func_801BF880(u8 *channel, s32 stream) {
    s32 off = 0;
    channel[MUS_CH_SLIDE_DURATION] = off;
    return stream - off;
}

/* musSetEnvelope: load a seven-byte volume envelope and calculate its slopes. */
u8 *func_801BF88C(u8 *channel, u8 *envelopeData) {
    MusEnvelopeChannel *envelope = (MusEnvelopeChannel *)channel;
    f64 one = 1.0;
    s32 updatePeriod;
    u32 duration;
    s32 attackVolume;

    duration = *envelopeData++;
    updatePeriod = duration;
    if (!duration) {
        duration = 1;
        updatePeriod = 1;
    }
    envelope->updatePeriod = duration;
    envelope->timeScale = MUS_ENVELOPE_SCALE_UNITY / updatePeriod;
    envelope->initialVolume = *envelopeData++;
    envelope->attackDuration = duration = *envelopeData++;
    envelope->attackVolume = *envelopeData++;
    attackVolume = envelope->attackVolume;
    envelope->attackSlope = (one / (f32)duration) * (f32)(attackVolume - envelope->initialVolume);
    envelope->decayDuration = duration = *envelopeData++;
    envelope->sustainVolume = *envelopeData++;
    envelope->decaySlope = (one / (f32)duration) * (f32)(envelope->sustainVolume - attackVolume);
    envelope->releaseDuration = duration = *envelopeData++;
    envelope->releaseSlope = one / (f32)duration;
    return envelopeData;
}

/* Sequence command "set tempo": read a BPM byte and set the time step of
 * this effect channel, or (for a song) of every channel playing the same song. */
u8 *func_801BF9E4(u8 *channel, u8 *cmd) {
    s32 baseStep;
    s32 timeStep;
    s32 i;
    u8 *other;

    baseStep = ((cmd[0] * MUS_DEFAULT_FIXED_TICKS_PER_SECOND) / 120) / D_802AB04C;
    cmd++;
    timeStep = (s32)((u32)*(s16 *)(channel + MUS_CH_HANDLE_TEMPO) * (u32)baseStep) >> 7;

    if (*(u16 *)(channel + MUS_CH_EFFECT_ID) != 0) {
        *(s16 *)(channel + MUS_CH_TIME_STEP) = baseStep;
    } else {
        for (i = 0, other = D_802AB040; i < D_802AB038; i++, other += 0x134) {
            if (*(s32 *)(channel + MUS_CH_SONG) == *(s32 *)(other + MUS_CH_SONG)) {
                *(s16 *)(other + MUS_CH_BASE_TIME_STEP) = baseStep;
                *(s16 *)(other + MUS_CH_TIME_STEP) = timeStep;
            }
        }
    }
    return cmd;
}


/* Sequence command "cutoff percent": read a one-byte note cutoff as a percentage of the note's
 * duration and clear the fixed cutoff time (func_801BFAC4). Returns the stream position after it. */
u8 *func_801BFAB0(u8 *channel, u8 *cmd) {
    *(s16 *)(channel + MUS_CH_CUTOFF_PERCENT) = *cmd++;
    *(s16 *)(channel + MUS_CH_CUTOFF_TICKS) = 0;
    return cmd;
}

/* Sequence command "cutoff": read a big-endian 16-bit fixed note cutoff time and clear
 * the percentage cutoff (func_801BFAB0 sets the percentage instead). Returns the stream position after it. */
u8 *func_801BFAC4(u8 *channel, u8 *cmd) {
    s16 cutoff;

    cutoff = *cmd++ << 8;
    cutoff |= *cmd++;
    *(s16 *)(channel + MUS_CH_CUTOFF_TICKS) = cutoff;
    *(s16 *)(channel + MUS_CH_CUTOFF_PERCENT) = 0;
    return cmd;
}

/* Music command: set up the sine pitch modulation (vibrato) from the stream:
 * delay byte, period byte, depth byte (in fiftieths of a semitone). The phase
 * step is the full cycle D_8010C170 divided by the period. Returns the stream
 * position after the command's arguments. */
u8 *func_801BFAF4(u8 *channel, u8 *cmd) {
    channel[MUS_CH_SINE_PITCH_DELAY] = cmd[0];
    cmd += 2;
    channel[MUS_CH_SINE_PITCH_PERIOD] = cmd[-1];
    *(f32 *)(channel + MUS_CH_SINE_PITCH_DEPTH) = (f32)(u32)cmd[0] / 50.0;
    cmd++;
    *(f32 *)(channel + MUS_CH_SINE_PITCH_STEP) = D_8010C170 / (f32)(u32)channel[MUS_CH_SINE_PITCH_PERIOD];
    return cmd;
}

extern f64 D_8010C178;
/* Sequence command "vibrato down" (libmus Fvibdown): read delay, period and
 * depth (in 1/50 semitone) bytes; like func_801BFAF4 but with negated depth. */
u8 *func_801BFB88(u8 *channel, u8 *cmd) {
    channel[MUS_CH_SINE_PITCH_DELAY] = *cmd++;
    channel[MUS_CH_SINE_PITCH_PERIOD] = *cmd++;
    *(f32 *)(channel + MUS_CH_SINE_PITCH_DEPTH) = -(f32)*cmd++ / 50.0;
    *(f32 *)(channel + MUS_CH_SINE_PITCH_STEP) = D_8010C178 / (f32)channel[MUS_CH_SINE_PITCH_PERIOD];
    return cmd;
}

/* Sequence command "vibrato off" (libmus Fviboff): stop the sine pitch
 * modulation and clear its current offset. Takes no arguments, so the
 * stream position is returned unchanged. */
s32 func_801BFC20(u8 *channel, s32 cmd)
{
    f32 zero;
    zero = 0.0f;
    channel[MUS_CH_SINE_PITCH_PERIOD] = 0;
    return *(f32 *)(channel + MUS_CH_SINE_PITCH_VALUE) = zero, cmd;
}

/* Sequence command "fixed length" (libmus Flength): read a note duration (one
 * byte, or two bytes big-endian when the top bit is set) and make it every
 * following note's duration. Returns the next command. */
u8 *func_801BFC34(u8 *channel, u8 *cmd) {
    u8 value;

    value = *cmd++;
    if (value < 0x80) {
        *(u16 *)(channel + MUS_CH_DEFAULT_DURATION) = value;
    } else {
        *(u16 *)(channel + MUS_CH_DEFAULT_DURATION) = (value & 0x7F) << 8;
        *(u16 *)(channel + MUS_CH_DEFAULT_DURATION) += *cmd++;
    }
    return cmd;
}

/* Sequence command "ignore" (libmus Fignore): the next note reads its own
 * duration instead of the fixed length. Takes no arguments, so the stream
 * position is returned unchanged. */
s32 func_801BFC78(u8 *channel, s32 cmd) {
    u8 *ch = channel;
    ch[MUS_CH_DURATION_OVERRIDE] = 1;
    return cmd;
}

/* Sequence command "transpose" (libmus Ftrans): read a signed semitone byte
 * and make it the channel's transpose. Returns the next command. */
u8 *func_801BFC88(u8 *channel, u8 *cmd) {
    channel[MUS_CH_TRANSPOSE] = *cmd++;
    return cmd;
}

/* Sequence command "ignore transpose" (libmus Fignore_trans): following notes
 * skip the channel's transpose. Takes no arguments, so the stream position is
 * returned unchanged. */
s32 func_801BFC98(u8 *channel, s32 cmd) {
    channel[MUS_CH_TRANSPOSE_DISABLED] = 1;
    return cmd;
}


/* Sequence command: reads a signed byte of cents and makes it the channel's base
 * pitch offset, replacing the old one in the total pitch offset. Returns the next command. */
u8 *func_801BFCA8(u8 *channel, u8 *command)
{
    s32 cents = *command++;
    f32 semitones;
    if (cents & 0x80) {
        cents |= -0x100;
    }
    *(f32 *)(channel + MUS_CH_PITCH_OFFSET) -= *(f32 *)(channel + MUS_CH_BASE_PITCH_OFFSET);
    semitones = (f32)cents / 100.0;
    *(f32 *)(channel + MUS_CH_BASE_PITCH_OFFSET) = semitones;
    *(f32 *)(channel + MUS_CH_PITCH_OFFSET) += semitones;
    return command;
}

/* Sequence command "set envelope": read the envelope index (one byte, or two
 * bytes big-endian when the top bit is set) and load that envelope from the
 * song's envelope table. Returns the next command. */
u8 *func_801BFD0C(u8 *channel, u8 *cmd) {
    s32 index;

    index = *cmd++;
    if (index & 0x80) {
        index &= 0x7F;
        index <<= 8;
        index |= *cmd++;
    }
    func_801BF88C(channel, (u8 *)(*(s32 *)(*(s32 *)(channel + MUS_CH_SONG) + MUS_SONG_ENVELOPES_OFFSET) + index * MUS_ENVELOPE_SIZE));
    return cmd;
}

/* Sequence command "envelope off" (libmus Fenvoff): set the channel's
 * hold-envelope flag. Takes no arguments; returns the stream position unchanged. */
s32 func_801BFD6C(u8 *channel, s32 cmd)
{
    volatile u8 *hold = channel + MUS_CH_HOLD_ENVELOPE;
    *hold = 1;
    return cmd | 0;
}

/* Sequence command "envelope on" (libmus Fenvon): clear the channel's
 * hold-envelope flag. Takes no arguments; returns the stream position unchanged. */
s32 func_801BFD7C(u8 *channel, s32 cmd)
{
    *(u8 *)(channel + MUS_CH_HOLD_ENVELOPE) = 0;
    return cmd ^ 0;
}

/* Sequence command "voice hold on": set the channel's hold-voice flag. Takes no
 * arguments; returns the stream position unchanged. */
u32 func_801BFD88(u8 *channel, u32 cmd) {
    channel[MUS_CH_HOLD_VOICE] = 1;
    return cmd;
}

/* Sequence command "voice hold off": clear the channel's hold-voice flag. Takes no
 * arguments; returns the stream position unchanged. */
s32 func_801BFD98(u8 *channel, s32 cmd)
{
    channel[MUS_CH_HOLD_VOICE] = 0;
    return (s32)((u32)cmd + 0U);
}

/*
 * Sequence command "loop start": pushes a loop frame on the track's loop stack (depth at 0xD7).
 * The command's byte is the repeat count (0xFF loops forever); the frame saves the script position
 * after it and the track state that func_801BFE90 ("loop end") restores on each repeat.
 */
u8 *func_801BFDA4(u8 *track, u8 *script) {
    s32 depth = track[0xD7];
    track[depth + 0x11C] = *script++;                                    /* repeat count */
    *(u8 **)(track + depth * 4 + 0xDC) = script;                        /* loop start */
    *(s32 *)(track + depth * 4 + 0xEC) = *(s32 *)(track + 0x38);
    *(s32 *)(track + depth * 4 + 0xFC) = *(s32 *)(track + 0x34);
    track[depth + 0x120] = track[0xB8];
    track[depth + 0x124] = (u32)*(f32 *)(track + 0x70);
    *(u16 *)(track + depth * 2 + 0x10C) = *(u16 *)(track + 0x9E);
    *(u16 *)(track + depth * 2 + 0x114) = *(u16 *)(track + 0xA0);
    track[0xD7]++;
    return script;
}

/* Sequence command "loop end": counts down the innermost loop (0xFF never
 * ends). When it runs out, the frame is popped and `script` is returned;
 * otherwise the track state saved by func_801BFDA4 is restored and the
 * loop's start position is returned. unkD7 is the loop depth, unk11C the
 * repeat counts, unkDC the saved script positions. */
s32 func_801BFE90(UnkBFE90 *track, s32 script) {
    s32 frame = track->unkD7 - 1;
    if (track->unk11C[frame] != 0xFF) {
        track->unk11C[frame]--;
        if (track->unk11C[frame] == 0) {
            track->unkD7 = frame;
            frame = -1;
        }
    }
    if (frame >= 0) {
        script = track->unkDC[frame];
        track->unk38 = track->unkEC[frame];
        track->unk34 = track->unkFC[frame];
        track->unkB8 = track->unk120[frame];
        track->unk70 = (f32)(u32)track->unk124[frame];
        track->unk9E = track->unk10C[frame];
        track->unkA0 = track->unk114[frame];
        track->unk24 = track->unk70 * track->unk6C;
    }
    return script;
}

/* Sequence command "square pitch modulation": reads three bytes, the depth in
 * semitones, the duration of the raised phase and the duration of the zero phase
 * (stored as the vibrato initial delay). Returns the advanced sequence pointer.
 * The no-op statements below are needed for IDO to schedule it as the ROM has it. */
u8 *func_801BFF40(u8 *channel, u8 *seq)
{
  u8 depth = *seq;
  channel[MUS_CH_SQUARE_PITCH_DEPTH] = *seq;
  seq += 3;
  channel[MUS_CH_SQUARE_PITCH_DURATION] = seq[-2];
  ;
  channel[MUS_CH_VIBRATO_INITIAL_DELAY] = seq[-((0, 1))];
  goto stored;
stored:
  seq++;
  seq--;
  return seq;
  if (seq)
  {
    if (1)
    {
    }
  }
}

/* Sequence command "square pitch modulation off": clears the square-wave
 * duration, which disables the modulation. Takes no arguments, so the stream
 * position is returned unchanged. */
s32 func_801BFF60(u8 *channel, s32 cmd) {
    channel[MUS_CH_SQUARE_PITCH_DURATION] = 0;
    return cmd;
}

/* Sequence command "velocity on" (libmus Fvelon): notes carry their own volume
 * byte from now on. Takes no arguments, so the stream position is returned
 * unchanged. (cmd == cmd) is 1; written so IDO keeps the constant in t6. */
s32 func_801BFF6C(u8 *channel, s32 cmd) {
    channel[MUS_CH_EXPLICIT_NOTE_VOLUME] = (cmd == cmd);
    return cmd;
}

/* Sequence command "velocity off" (libmus Fveloff): notes use the channel's
 * default volume again. Takes no arguments, so the stream position is returned
 * unchanged. The XOR with the re-read (always zero) byte is folded away; it is
 * written so IDO moves cmd with `or` as the ROM does. */
s32 func_801BFF7C(u8 *channel, s32 cmd)
{
    channel[MUS_CH_EXPLICIT_NOTE_VOLUME] = 0;
    return cmd ^ (channel[MUS_CH_EXPLICIT_NOTE_VOLUME] & 0);
}

/* Sequence command "set default note volume": reads one byte as the volume
 * used by notes that carry none, and turns off explicit per-note volumes.
 * Returns the advanced sequence pointer. */
u8 *func_801BFF88(u8 *channel, u8 *seq)
{
    channel[MUS_CH_DEFAULT_NOTE_VOLUME] = *seq++;
    channel[MUS_CH_EXPLICIT_NOTE_VOLUME] = 0;
    return seq;
}

/* Sequence command "set pan": reads one byte (0..255) and stores it halved
 * (0..127) as the channel's pan. Returns the advanced sequence pointer. */
u8 *func_801BFF9C(u8 *channel, u8 *seq)
{
    channel[MUS_CH_PAN] = *seq / 2;
    return seq + 1;
}

/* Sequence command this player ignores: skips its two argument bytes and
 * returns the advanced sequence pointer. */
u8 *func_801BFFBC(u8 *channel, u8 *seq)
{
    return seq + 2;
}

/* Sequence command "set drum map": reads a one-byte index into the song's
 * drum-table offset list (song + 0x14) and points the channel's drum map at
 * that entry. Returns the advanced sequence pointer. */
u8 *func_801BFFC8(u8 *channel, u8 *seq, u8 *song) {
    u8 *drumMap;
    song = *(u8 **)(channel + MUS_CH_SONG);
    drumMap = (*(s32 **)(song + 0x14))[*seq++] + song;
    *(u8 **)(channel + MUS_CH_DRUM_MAP) = drumMap;
    return seq;
}

/* Clears word 0x20 (byte offset 0x80) of obj and returns value unchanged. */
s32 func_801BFFF0(s32 *obj, s32 value) {
    obj[0x20] = 0;
    return (s32)((u32)value | 0U);
}

/* Sequence command this player ignores: skips its one-byte argument and
 * returns the next command byte. */
u8 *func_801BFFFC(u8 *channel, u8 *cmd)
{
    return cmd + 1;
}

/* Sequence command "marker" (libmus Fmarker): reads three big-endian u16
 * offsets from the command data, rewinds the volume and pitch streams to
 * their start plus the second and third offsets (restarting their countdowns),
 * and returns the new note-stream position: track start plus the first offset. */
s32 func_801C0008(u8 *channel, u8 *data)
{
    s32 offset;
    s32 noteOffset;
    offset = data[2];
    noteOffset = data[0];
    noteOffset <<= 8;
    noteOffset += data[1];
    offset <<= 8;
    offset += data[3];
    *(s32 *)(channel + MUS_CH_VOLUME_STREAM) = *(s32 *)(channel + MUS_CH_VOLUME_STREAM_START) + offset;
    *(s16 *)(channel + MUS_CH_VOLUME_STREAM_COUNTDOWN) = 1;
    data += 4;
    offset = *data++;
    offset <<= 8;
    offset += *data;
    *(s32 *)(channel + MUS_CH_PITCH_STREAM) = *(s32 *)(channel + MUS_CH_PITCH_STREAM_START) + offset;
    *(s16 *)(channel + MUS_CH_PITCH_STREAM_COUNTDOWN) = 1;
    return *(s32 *)(channel + MUS_CH_TRACK_START) + noteOffset;
}

/* Sequence command "set effect mix" (libmus Freverb, likely): read one byte, the
 * channel's effect (reverb) send level. Returns the next command. */
u8 *func_801C006C(u8 *channel, u8 *cmd) {
    channel[MUS_CH_EFFECT_MIX] = *cmd++;
    return cmd;
}

s32 func_801C2668(s32 arg0);
/* mus_cmd_random_note (libmus FrandNote): sequence command that sets the
 * channel's transpose to a random value below the first data byte, plus the
 * second data byte as a base. Returns the next command byte. */
u8 *func_801C007C(u8 *channel, u8 *cmd)
{
    u8 random;
    u8 *ch;
    ch = channel;
    random = func_801C2668(*cmd++);
    ch[MUS_CH_TRANSPOSE] = random;
    ch[MUS_CH_TRANSPOSE] += *cmd++;
    return cmd;
}

/* mus_cmd_random_volume (libmus FrandVolume): sequence command that sets the
 * channel's volume to a random value below the first data byte, plus the
 * second data byte as a base. Returns the next command byte. */
u8 *func_801C00CC(u8 *channel, u8 *cmd)
{
    u8 random;
    u8 *ch;
    ch = channel;
    random = func_801C2668(*cmd++);
    ch[MUS_CH_SEQUENCE_VOLUME] = random;
    ch[MUS_CH_SEQUENCE_VOLUME] += *cmd++;
    return cmd;
}

/* mus_cmd_random_pan (libmus FrandPan): sequence command that sets the
 * channel's pan to a random value below the first data byte, plus the
 * second data byte as a base. Returns the next command byte. */
u8 *func_801C011C(u8 *channel, u8 *cmd)
{
    u8 random;
    u8 *ch;
    ch = channel;
    random = func_801C2668(*cmd++);
    ch[MUS_CH_PAN] = random;
    ch[MUS_CH_PAN] += *cmd++;
    return cmd;
}

/* Sequence command "set volume" (libmus Fvolume): reads one byte as the
 * channel's sequence-controlled volume. Returns the advanced sequence pointer. */
u8 *func_801C016C(u8 *channel, u8 *seq)
{
    channel[MUS_CH_SEQUENCE_VOLUME] = *seq++;
    return seq;
}

s32 func_801C08E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
/* mus_cmd_start_effect (Fstartfx): sequence command that starts a sound effect
 * at this channel's volume, pan and priority + 1. Its ID is one byte, or two
 * when the top bit is set. Every channel the new effect plays on inherits this
 * channel's playback handle and sample bank. Returns the next command byte. */
u8 *func_801C017C(u8 *channel, u8 *cmd) {
    s32 effectId;
    s32 handle;
    s32 i;
    u8 *other;
    effectId = *cmd++;
    if (effectId >= 0x80) {
        effectId = ((effectId & 0x7F) << 8) + *cmd++;
    }
    handle = func_801C08E4(effectId, *(s16 *)(channel + MUS_CH_HANDLE_VOLUME), *(s16 *)(channel + MUS_CH_HANDLE_PAN), 0, (*(s32 *)(channel + MUS_CH_EFFECT_PRIORITY))++);
    *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY) -= 1;
    if (!handle) return cmd;
    other = D_802AB040;
    i = 0;
    if (D_802AB038 > 0) {
        do {
            i++;
            if (handle == *(s32 *)(other + MUS_CH_PLAYBACK_HANDLE)) {
                *(s32 *)(other + MUS_CH_PLAYBACK_HANDLE) = *(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE);
                *(s32 *)(other + MUS_CH_SAMPLE_BANK) = *(s32 *)(channel + MUS_CH_SAMPLE_BANK);
            }
            other += 0x134;
        } while (i < D_802AB038);
    }
    return cmd;
}

/* Sequence command "pitch-stream range": reads one byte, sets the stream's
 * scale to byte/64 semitones per unit, and recomputes the stream pitch
 * offset from the field at 0x70 (squared, exactly as the game does). */
u8 *func_801C025C(u8 *channel, u8 *stream)
{
    *(f32 *)(channel + MUS_CH_PITCH_STREAM_SCALE) = (f32)(u32)*stream * (1.0 / 64.0);
    *(f32 *)(channel + MUS_CH_STREAM_PITCH) = *(f32 *)(channel + 0x70) * *(f32 *)(channel + 0x70);
    return stream + 1;
}

/* mus_cmd_sweep (Fsweep): sequence command that sets the channel's pan sweep
 * rate from one byte. Returns the next command byte. */
u8 *func_801C02AC(u8 *channel, u8 *cmd) {
    channel[MUS_CH_PAN_SWEEP_RATE] = *cmd++;
    return cmd;
}


/* mus_cmd_change_effect (Fchangefx): sequence command that selects effect
 * preset `cmd[0]`. It is applied (func_801C3FC0) only while songs may change
 * the preset, i.e. the MusSetSongFxChange flag D_802AB068 is 1. Returns the
 * next command byte. */
u8 *func_801C02BC(u8 *channel, u8 *cmd) {
    s32 presetIndex;

    presetIndex = *cmd++;
    if (D_802AB068 == 1) {
        func_801C3FC0(presetIndex);
    }
    return cmd;
}

s32 func_801C1100();
s32 func_801C1338(s32 arg0);
void func_801C066C(s32 arg0, s32 arg1);
void func_801C249C(s32 *arg0, s32 arg1);
void func_801C2A18(u8 *arg0, u8 arg1, u32 arg2);
void func_801C2C10();
/* Initialize music playback and synthesis, returning the audio heap bytes consumed. */
s32 func_801C0300(MusConfig *settings) {
    u16 voiceConfig[3];
    AudioSynthConfig synthConfig;
    s32 audioParams[3];
    s32 channelIndex;

    D_802AB070 = settings->flags;
    D_802AB038 = settings->channelCount;
    D_802AB044 = (u8 *)settings->effectSequences;
    D_802AB048 = (s32 *)settings->effectPriorities;
    if (D_80000300 == 0) {
        D_802AB04C = MUS_REFRESH_PAL;
    } else {
        D_802AB04C = MUS_REFRESH_NTSC;
    }
    D_802AB050 = MUS_MICROSECONDS_PER_SECOND / D_802AB04C;
    func_801C2A18((u8 *)settings->heapAddress, 0, settings->heapBytes);
    func_801CB240(&D_802AB028, settings->heapAddress, settings->heapBytes);
    D_802AB03C = (u8 *)func_801CB280(0, 0, &D_802AB028, 1, D_802AB038 * MUS_VOICE_SIZE);
    D_802AB040 = (u8 *)func_801CB280(0, 0, &D_802AB028, 1, D_802AB038 * MUS_CHANNEL_BYTES);
    func_801C1100(settings->commandQueueCapacity);
    func_801C2A18(D_802AB03C, 0, D_802AB038 * MUS_VOICE_SIZE);
    func_801C2A18(D_802AB040, 0, D_802AB038 * MUS_CHANNEL_BYTES);
    if ((u8 *)settings->sampleBank != NULL) {
        func_801C249C((s32 *)settings->sampleBank, settings->sampleRomAddress);
        D_802AB064 = D_802AB060 = settings->sampleBank;
    } else {
        D_802AB064 = 0;
    }
    synthConfig.maxVVoices = D_802AB038;
    synthConfig.maxPVoices = D_802AB038;
    synthConfig.maxUpdates = settings->maxUpdates;
    synthConfig.outputRate = 0;
    synthConfig.fxType = AUDIO_FX_BIG_ROOM;
    synthConfig.initOsc = 0;
    synthConfig.heap = &D_802AB028;
    D_802AB06C = AUDIO_FX_BIG_ROOM;
    audioParams[AUDIO_PARAM_SAMPLE_RATE] = settings->sampleRate;
    audioParams[AUDIO_PARAM_FRAMES_PER_UPDATE] = settings->framesPerUpdate;
    audioParams[AUDIO_PARAM_COMMAND_CAPACITY] = settings->commandCapacity;
    func_801C2C10(settings->scheduler, &synthConfig, settings->threadPriority, audioParams, settings->dmaBufferCount, settings->dmaBufferBytes, D_802AB04C);
    func_801C066C(MUS_MASTER_VOLUME_ALL, MUS_MASTER_VOLUME_MAX);
    D_802AB058 = 1;
    D_802AB05C = MUS_INITIAL_RANDOM_SEED;
    D_802AB010[MUS_PLAYER_NEXT] = 0;
    D_802AB010[MUS_PLAYER_HANDLER] = (u32)func_801C1338;
    D_802AB010[MUS_PLAYER_CLIENT_DATA] = (u32)D_802AB010;
    func_801CB9B0((s32 *)D_802AB2C8, (s32 *)D_802AB010);
    for (channelIndex = 0; channelIndex < D_802AB038; channelIndex++) {
        D_802AB040[channelIndex * MUS_CHANNEL_BYTES + MUS_CH_VOICE_ACTIVE] = 0;
        func_801C2768(&D_802AB040[channelIndex * MUS_CHANNEL_BYTES]);
        ((u8 *)voiceConfig)[MUS_VOICE_CONFIG_UNITY_PITCH_OFFSET] = 0;
        voiceConfig[MUS_VOICE_CONFIG_PRIORITY] = settings->threadPriority;
        voiceConfig[MUS_VOICE_CONFIG_FX_BUS] = 0;
        func_801CBA00((u8 *)D_802AB2C8, &D_802AB03C[channelIndex * MUS_VOICE_SIZE], voiceConfig);
    }
    return D_802AB02C - D_802AB028;
}

/* MusSetMasterVolume: sets the effects (D_802AB054) and/or songs (D_802AB056)
 * master volume, as selected by the flag bits. */
void func_801C066C(s32 flags, s32 volume) {
    if (flags & MUS_MASTER_VOLUME_EFFECTS) {
        D_802AB054 = volume;
    }
    if (flags & MUS_MASTER_VOLUME_SONGS) {
        D_802AB056 = volume;
    }
}

s32 func_801C28A0(s32 *arg0, s32 arg1);
void func_801C1054(s32 arg0);
void func_801C2A84(s32 *arg0, s32 *arg1, s32 arg2);
/* Relocate a song, initialize its active tracks, and queue playback under one handle. */
s32 func_801C0694(s32 *song) {
    s32 trackCount = song[MUS_SONG_TRACK_COUNT_WORD];
    s32 handle;
    s32 trackIndex;
    if ((u32)song[MUS_SONG_TRACKS_WORD] < MUS_SONG_UNRELOCATED_LIMIT) {
        func_801C2A84(&song[MUS_SONG_TRACKS_WORD], song, MUS_SONG_HEADER_POINTER_COUNT);
        func_801C2A84((s32 *)song[MUS_SONG_TRACKS_WORD], song, trackCount);
        func_801C2A84((s32 *)song[MUS_SONG_VOLUME_STREAMS_WORD], song, trackCount);
        func_801C2A84((s32 *)song[MUS_SONG_PITCH_STREAMS_WORD], song, trackCount);
    }
    handle = D_802AB058++;
    for (trackIndex = 0; trackIndex < trackCount; trackIndex++) {
        if (((s32 *)song[MUS_SONG_TRACKS_WORD])[trackIndex] != 0) {
            u32 channelIndex = func_801C28A0(song, trackIndex);
            u8 *channel = D_802AB040 + channelIndex * MUS_CHANNEL_BYTES;
            func_801C2768(channel);
            *(s32 *)(channel + MUS_CH_SONG) = (s32)song;
            *(s32 *)channel |= MUS_CHANNEL_PAUSED;
            *(s32 *)(channel + MUS_CH_VOLUME_STREAM) = *(s32 *)(channel + MUS_CH_VOLUME_STREAM_START) = ((s32 *)song[MUS_SONG_VOLUME_STREAMS_WORD])[trackIndex];
            *(s32 *)(channel + MUS_CH_PITCH_STREAM) = *(s32 *)(channel + MUS_CH_PITCH_STREAM_START) = ((s32 *)song[MUS_SONG_PITCH_STREAMS_WORD])[trackIndex];
            *(s32 *)(channel + MUS_CH_NOTE_STREAM) = *(s32 *)(channel + MUS_CH_TRACK_START) = ((s32 *)song[MUS_SONG_TRACKS_WORD])[trackIndex];
            *(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE) = handle;
        }
    }
    func_801C1054(handle);
    return handle;
}

/* MusStartEffect: starts effect `effectId` at unity volume and pan with its
 * default priority (D_802AB048). An idle channel is used at once; otherwise the
 * lowest-priority effect channel is stolen if its priority is below the new one.
 * Returns the playback handle, or MUS_EFFECT_INVALID_HANDLE. */
s32 func_801C0808(s32 effectId) {
    u8 *channel;
    u8 *lowest;
    s32 i;
    s32 lowestPriority;
    s32 priority = D_802AB048[effectId];

    lowestPriority = priority + 1;
    channel = D_802AB040;
    for (i = 0; i < D_802AB038; i++, channel += 0x134) {
        if (*(s32 *)(channel + MUS_CH_NOTE_STREAM) == 0) {
            return func_801C2B24(channel, effectId, MUS_HANDLE_SCALE_UNITY, MUS_HANDLE_SCALE_UNITY, priority);
        }
        if (*(u16 *)(channel + MUS_CH_EFFECT_ID) != 0 && *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY) < lowestPriority) {
            lowestPriority = *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY);
            lowest = channel;
        }
    }
    if (lowestPriority < priority) {
        return func_801C2B24(lowest, effectId, MUS_HANDLE_SCALE_UNITY, MUS_HANDLE_SCALE_UNITY, priority);
    }
    return MUS_EFFECT_INVALID_HANDLE;
}

/* Start an effect by restarting it, using an idle channel, or stealing a lower-priority effect. */
s32 func_801C08E4(s32 effectId, s32 volumeScale, s32 panScale, s32 restartExisting, s32 priority) {
    u8 *channel;
    u8 *lowestPriorityChannel;
    s32 channelIndex;
    s32 lowestPriority;

    if (priority == MUS_EFFECT_DEFAULT_PRIORITY) {
        priority = D_802AB048[effectId];
    }
    if (restartExisting != 0) {
        channel = D_802AB040;
        for (channelIndex = 0; channelIndex < D_802AB038; channelIndex++, channel += MUS_CHANNEL_BYTES) {
            if (*(u16 *)(channel + MUS_CH_EFFECT_ID) == effectId) {
                return func_801C2B24(channel, effectId, volumeScale, panScale, priority);
            }
        }
    }
    lowestPriority = priority + 1;
    channel = D_802AB040;
    for (channelIndex = 0; channelIndex < D_802AB038; channelIndex++, channel += MUS_CHANNEL_BYTES) {
        if (*(s32 *)(channel + MUS_CH_NOTE_STREAM) == 0) {
            return func_801C2B24(channel, effectId, volumeScale, panScale, priority);
        }
        if (*(u16 *)(channel + MUS_CH_EFFECT_ID) != MUS_EFFECT_SONG_ID && *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY) < lowestPriority) {
            lowestPriority = *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY);
            lowestPriorityChannel = channel;
        }
    }
    if (lowestPriority < priority) {
        return func_801C2B24(lowestPriorityChannel, effectId, volumeScale, panScale, priority);
    }
    return MUS_EFFECT_INVALID_HANDLE;
}

/* MusStop: fade out every channel of the kinds in `flags` (MUS_FLAG_EFFECTS,
 * MUS_FLAG_SONGS) over `speed` updates (0 stops on the next update);
 * a paused channel is unpaused and stopped at once. */
void func_801C0A2C(s32 flags, s32 speed) {
    u8 *channel;
    s32 fadeDuration;
    s32 i;

    if (speed) {
        fadeDuration = speed;
    } else {
        fadeDuration = 1;
    }
    i = 0; channel = D_802AB040;
    if (D_802AB038 > 0) {
        do {
            u16 effectId = *(u16 *)(channel + MUS_CH_EFFECT_ID);
            i++;
            if ((effectId && (flags & MUS_FLAG_EFFECTS)) || (!effectId && (flags & MUS_FLAG_SONGS))) {
                /* Playing and not already fading out. */
                if (*(s32 *)(channel + MUS_CH_NOTE_STREAM) != 0 && *(s32 *)(channel + MUS_CH_FADE_REMAINING) == MUS_FADE_INACTIVE) {
                    s32 chFlags = *(s32 *)channel;
                    if (chFlags & MUS_CHANNEL_PAUSED) {
                        *(s32 *)(channel + MUS_CH_FADE_DURATION) = 1;
                        *(s32 *)(channel + MUS_CH_FADE_REMAINING) = 0;
                        *(s32 *)channel = chFlags & ~MUS_CHANNEL_PAUSED;
                    } else {
                        *(s32 *)(channel + MUS_CH_FADE_DURATION) = fadeDuration;
                        *(s32 *)(channel + MUS_CH_FADE_REMAINING) = speed;
                    }
                }
            }
            channel += MUS_CHANNEL_BYTES;
        } while (i < D_802AB038);
    }
}

/* libmus MusAsk: count the channels that are playing something of the kinds in
 * `flags` (MUS_FLAG_EFFECTS: an effect, MUS_FLAG_SONGS: a song). */
s32 func_801C0B00(u32 flags) {
    s32 i;
    s32 count;
    u8 *channel;
    for (i = 0, channel = D_802AB040, count = 0; i < D_802AB038; i++, channel += MUS_CHANNEL_BYTES) {
        if (*(s32 *)(channel + MUS_CH_NOTE_STREAM)) {
            u16 effectId = *(u16 *)(channel + MUS_CH_EFFECT_ID);
            if ((effectId && (flags & MUS_FLAG_EFFECTS)) || (!effectId && (flags & MUS_FLAG_SONGS))) count++;
        }
    }
    return count;
}

/*
 * libmus MusHandleStop: fade out over `speed` updates every channel playing `handle` that is not
 * already fading (a paused channel stops at once). Returns how many channels were stopped.
 */
s32 func_801C0B70(s32 handle, s32 speed) {
    u8 *channel;
    s32 fadeDuration;
    s32 i;
    s32 count;

    if (!handle) {
        return 0;
    }
    if (speed) {
        fadeDuration = speed;
    } else {
        fadeDuration = 1;
    }
    i = 0;
    channel = D_802AB040;
    count = 0;
    if (D_802AB038 > 0) {
        do {
            i++;
            if (*(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE) == handle && *(s32 *)(channel + MUS_CH_FADE_REMAINING) == MUS_FADE_INACTIVE) {
                s32 chFlags = *(s32 *)channel;
                count++;
                if (chFlags & MUS_CHANNEL_PAUSED) {
                    *(s32 *)(channel + MUS_CH_FADE_DURATION) = 1;
                    *(s32 *)(channel + MUS_CH_FADE_REMAINING) = 0;
                    *(s32 *)channel = chFlags & ~MUS_CHANNEL_PAUSED;
                } else {
                    *(s32 *)(channel + MUS_CH_FADE_DURATION) = fadeDuration;
                    *(s32 *)(channel + MUS_CH_FADE_REMAINING) = speed;
                }
                do { } while (0);
            }
            channel += MUS_CHANNEL_BYTES;
        } while (i < D_802AB038);
    }
    return count;
}

/* MusHandleAsk: returns how many music channels are playing the given
 * playback handle (zero for the invalid handle). */
s32 func_801C0C1C(s32 handle)
{
    s32 i = 0;
    u8 *channel;
    s32 playing;
    s32 channelCount;
    if (handle == MUS_EFFECT_INVALID_HANDLE) return 0;
    channel = D_802AB040;
    playing = 0;
    channelCount = D_802AB038;
    if (channelCount > 0) {
        do {
            i++;
            if (handle == *(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE)) playing++;
            channel += MUS_CHANNEL_BYTES;
        } while (i < channelCount);
    }
    return playing;
}

/* libmus MusHandleSetVolume: set the volume scale (128 is unity) of every channel
 * playing `handle`. Returns how many channels changed. */
s32 func_801C0C70(u32 handle, s32 volume)
{
    s32 i;
    s32 count;
    u8 *channel;
    if (!handle) return 0;
    for (i = 0, channel = D_802AB040, count = 0; i < D_802AB038; i++, channel += MUS_CHANNEL_BYTES) {
        if (handle == *(u32 *)(channel + MUS_CH_PLAYBACK_HANDLE)) {
            *(u16 *)(channel + MUS_CH_HANDLE_VOLUME) = volume;
            count++;
        }
    }
    return count;
}

/* libmus MusHandleSetPan: set the pan scale of every channel playing `handle`
 * and invalidate its cached pan so it is resent. Returns how many channels changed. */
s32 func_801C0CD4(u32 handle, s32 pan)
{
    s32 i;
    s32 count;
    u8 *channel;
    if (!handle) return 0;
    for (i = 0, channel = D_802AB040, count = 0; i < D_802AB038; i++, channel += MUS_CHANNEL_BYTES) {
        if (handle == *(u32 *)(channel + MUS_CH_PLAYBACK_HANDLE)) {
            *(u16 *)(channel + MUS_CH_HANDLE_PAN) = pan;
            channel[MUS_CH_CACHED_PAN] = MUS_BYTE_CACHE_INVALID;
            count++;
        }
    }
    return count;
}

/* MusHandleSetFreqOffset: set the pitch offset (semitones, relative to the
 * channel's base offset) of every channel playing `handle`; returns the
 * channel count. */
s32 func_801C0D40(s32 handle, f32 offset)
{
    s32 i = 0;
    s32 count;
    u8 *channel;
    if (handle == 0) return 0;
    channel = D_802AB040;
    count = 0;
    if (D_802AB038 > 0) {
        do {
            i++;
            if (handle == *(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE)) {
                *(f32 *)(channel + MUS_CH_PITCH_OFFSET) = *(f32 *)(channel + MUS_CH_BASE_PITCH_OFFSET) + offset;
                count++;
            }
            channel += MUS_CHANNEL_BYTES;
        } while (i < D_802AB038);
    }
    return count;
}

/* MusHandleSetTempo: set the tempo scale (1..256, 128 = unity) of every channel
 * playing `handle` and rescale its time step; returns the channel count. */
s32 func_801C0DAC(s32 handle, s32 tempo) {
    u8 *channel;
    s32 i = 0, count;

    if (!handle) return 0;
    if (tempo <= 0) tempo = 1;
    else if (tempo > MUS_HANDLE_TEMPO_MAX) tempo = MUS_HANDLE_TEMPO_MAX;
    channel = D_802AB040;
    count = 0;
    if (D_802AB038 > 0) do {
        i++;
        if (handle == *(u32 *)(channel + MUS_CH_PLAYBACK_HANDLE)) {
            *(u16 *)(channel + MUS_CH_HANDLE_TEMPO) = tempo;
            count++;
            *(u16 *)(channel + MUS_CH_TIME_STEP) =
                (s32)(*(u16 *)(channel + MUS_CH_BASE_TIME_STEP) * (u32)tempo) >> MUS_HANDLE_SCALE_SHIFT;
        }
        channel += MUS_CHANNEL_BYTES;
    } while (i < D_802AB038);
    return count;
}

/* MusHandleSetReverb: set the effect (reverb) mix, clamped to 0..127, of every channel
 * playing `handle`, and invalidate its cached mix so it is resent; returns the channel count. */
s32 func_801C0E3C(s32 handle, s32 reverb) {
    u8 *channel;
    s32 i = 0;
    s32 count;

    if (!handle) return 0;
    if (reverb < 0) reverb = 0;
    else if (reverb >= 128) reverb = MUS_CHANNEL_VOLUME_MAX;
    channel = D_802AB040;
    count = 0;
    if (D_802AB038 > 0) do {
        if (*(u32 *)(channel + MUS_CH_PLAYBACK_HANDLE) == handle) {
            channel[MUS_CH_EFFECT_MIX_OVERRIDE] = reverb;
            channel[MUS_CH_CACHED_EFFECT_MIX] = MUS_BYTE_CACHE_INVALID;
            count++;
        }
        i++;
        channel += MUS_CHANNEL_BYTES;
    } while (i < D_802AB038);
    return count;
}

void func_801C249C(s32 *arg0, s32 arg1);

/* MusBankInitialize: relocate a sample bank's offsets and point its waves at the sample data in ROM. */
void func_801C0EC0(s32 *sampleBank, s32 sampleRomAddress) {
    func_801C249C(sampleBank, sampleRomAddress);
}



/* Starts a song with a specific sample bank: if `bank` is given and set up
 * (high bit of its flags word at +0x10), it becomes the current bank
 * (D_802AB060) for the MusStartSong call (func_801C0694); the default bank
 * (D_802AB064) is restored afterwards. */
void func_801C0EE0(s32 *bank, s32 song) {
    if (bank != 0 && (bank[4] & 0x80000000U) != 0) {
        D_802AB060 = (s32)bank;
    }
    func_801C0694((s32 *)song);
    D_802AB060 = D_802AB064;
}

/* libmus MusBankStartEffect: start effect `effectId` (MusStartEffect, func_801C0808) with a
 * relocated sample bank as the current one (D_802AB060), then go back to the default bank. */
void func_801C0F28(u8 *bank, s32 effectId) {
    if (bank != NULL && (((MusSampleBank *)bank)->flags & MUS_SAMPLE_BANK_RELOCATED)) {
        D_802AB060 = (s32)bank;
    }
    func_801C0808(effectId);
    D_802AB060 = D_802AB064;
}

/* musStartEffectWithBank: start an effect (func_801C08E4) with a relocated sample
 * bank as the current one (D_802AB060), then go back to the default bank. */
void func_801C0F70(u8 *bank, s32 effectId, s32 volumeScale, s32 panScale, s32 restartExisting, s32 priority) {
    if (bank != NULL && (((MusSampleBank *)bank)->flags & MUS_SAMPLE_BANK_RELOCATED)) {
        D_802AB060 = (s32)bank;
    }
    func_801C08E4(effectId, volumeScale, panScale, restartExisting, priority);
    D_802AB060 = D_802AB064;
}

/* libmus MusHandleGetPtrBank: the sample bank used by the first channel playing
 * `handle`, or 0 if the handle is invalid or no channel is playing it. */
s32 func_801C0FD8(s32 handle) {
    u8 *channel;
    s32 i;
    if (!handle) return 0;
    channel = D_802AB040;
    i = 0;
    while (i < D_802AB038) {
        if (*(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE) == handle) return *(s32 *)(channel + MUS_CH_SAMPLE_BANK);
        i++;
        channel += MUS_CHANNEL_BYTES;
    }
    return 0;
}

extern s32 D_802AB068;

s32 func_801C12A0(s32 arg0);
/* MusHandlePause(handle): queues a MUS_FIFO_PAUSE command for the playback
 * handle on the audio thread's FIFO (func_801C12A0 = __MusIntFifoAddCommand). */
void func_801C102C(s32 handle)
{
    MusFifoCommand command;
    command.type = MUS_FIFO_PAUSE;
    command.data = handle;
    func_801C12A0((s8 *)&command);
}

/* libmus MusHandleUnPause: queue a MUS_FIFO_UNPAUSE command for the audio thread
 * (func_801C12A0), resuming every channel of playback `handle`. */
void func_801C1054(s32 handle)
{
    u8 message[8];
    message[0] = MUS_FIFO_UNPAUSE;
    *(s32 *)(message + 4) = handle;
    func_801C12A0((s8 *)message);
}

/* libmus MusSetFxType: remember the effect preset (D_802AB06C) and queue a
 * MUS_FIFO_SET_FX_PRESET command for the audio thread (func_801C12A0).
 * The queue's result is left in v0 as the return value. */
s32 func_801C1080(s32 fxPreset)
{
    u8 message[8];
    message[0] = MUS_FIFO_SET_FX_PRESET;
    *(s32 *)(message + 4) = fxPreset;
    D_802AB06C = fxPreset;
    func_801C12A0((s8 *)message);
}

/* MusSetSongFxChange: let songs change the effect preset (enable = 1) or not
 * (enable = 0). Disabling first restores the current preset D_802AB06C. */
s32 func_801C10B4(s32 enable) {
    s32 ok = 1;
    if (enable == 0) {
        ok = func_801C1080(D_802AB06C);
    }
    if (ok != 0) {
        D_802AB068 = enable;
    }
    return ok;
}

/* __MusIntFifoOpen: allocate the player's command FIFO (D_802AB080) of `entries`
 * 8-byte commands, clamped to 64..1024, from the audio heap D_802AB028
 * (func_801CB280: alHeapDBAlloc), and empty it (read/write indices D_802AB074/D_802AB078). */
s32 func_801C1100(s32 entries) {
    if (entries < 0x40) {
        entries = 0x40;
    } else if (entries > 0x400) {
        entries = 0x400;
    }
    D_802AB080 = (u8 *)func_801CB280(0, 0, &D_802AB028, 1, entries * 8);
    D_802AB07C = entries;
    D_802AB074 = D_802AB078 = 0;
}

void func_801C1228(u8 *arg0);
/* Drain the audio command ring buffer: run every queued 8-byte command
 * (func_801C1228) from the read index D_802AB074 up to the write index
 * D_802AB078, wrapping at the capacity D_802AB07C. Buffer: D_802AB080. */
void func_801C1184(void)
{
    if (D_802AB074 == D_802AB078) {
        return;
    }
    while (D_802AB074 != D_802AB078) {
        func_801C1228(D_802AB080 + D_802AB074 * 8);
        if (D_802AB07C == ++D_802AB074) {
            D_802AB074 = 0;
        }
    }
}

s32 func_801C3FC0(s32 arg0);
void func_801C2BB0(s32 arg0, s32 arg1, s32 arg2);
/* __MusIntFifoProcessCommand: run one queued player command on the audio
 * thread: pause or unpause every channel of a playback handle, or change the
 * effect preset. */
void func_801C1228(u8 *command) {
    switch (((MusFifoCommand *)command)->type) {
    case MUS_FIFO_PAUSE:
        func_801C2BB0(((MusFifoCommand *)command)->data, ~MUS_CHANNEL_PAUSED, MUS_CHANNEL_PAUSED);
        break;
    case MUS_FIFO_UNPAUSE:
        func_801C2BB0(((MusFifoCommand *)command)->data, ~MUS_CHANNEL_PAUSED, 0);
        break;
    case MUS_FIFO_SET_FX_PRESET:
        func_801C3FC0(((MusFifoCommand *)command)->data);
        break;
    }
}


/* Queue one 8-byte audio command: copy it (func_801C2A4C = bcopy) into the
 * ring buffer D_802AB080 at the write index D_802AB078 and advance it,
 * wrapping at the capacity D_802AB07C. Returns 0 if the queue is full
 * (the next slot is the read index D_802AB074), 1 when queued. */
s32 func_801C12A0(s32 command) {
    s32 nextWrite;
    s32 write = D_802AB078;
    nextWrite = (write + 1) % D_802AB07C;
    if (nextWrite == D_802AB074) return 0;
    func_801C2A4C(command, &D_802AB080[write * 8], 8);
    D_802AB078 = nextWrite;
    return 1;
}

f32 func_801C2088(u8 *arg0);
f32 func_801C20D8(u8 *arg0);
void func_801C15B8(u8 *arg0, s32 arg1);
void func_801C19FC(u8 *arg0, s32 arg1);
void func_801C1A90(u8 *arg0, s32 arg1);
void func_801C1C1C(u8 *arg0, s32 arg1, f32 arg2);
void func_801C1DB4(u8 *arg);
void func_801C1FD8(u8 *arg0);
void func_801C2144(MusVolumeChannel *channel); /* mus_advance_volume_stream */
void func_801C21FC(UnkStream21FC *arg0);
void func_801CBBE0(ObjectNode *, ObjectNode *);
/* Advance active music channels and their voices, then return the next update interval. */
s32 func_801C1338(s32 unusedClientData) {
    u8 *channel;
    s32 voiceIndex;
    f32 pitchOffset;
    func_801C1184();
    channel = D_802AB040;
    voiceIndex = 0;
    if (voiceIndex < D_802AB038) do {
        if (*(s32 *)(channel + MUS_CH_NOTE_STREAM) != 0 && !(*(u32 *)channel & MUS_CHANNEL_PAUSED)) {
            if (*(s32 *)(channel + MUS_CH_PENDING_WAVETABLE) != 0) func_801C19FC((ObjectNode *)channel, voiceIndex);
            *(u32 *)(channel + MUS_CH_TIME) += *(u16 *)(channel + MUS_CH_TIME_STEP);
            if (*(u16 *)(channel + MUS_CH_NOTE_DURATION) != MUS_NOTE_DURATION_HELD) {
                while (*(u32 *)(channel + MUS_CH_NEXT_NOTE_TIME) < *(u32 *)(channel + MUS_CH_TIME) && *(s32 *)(channel + MUS_CH_NOTE_STREAM) != 0) {
                    func_801C15B8(channel, voiceIndex);
                }
                if (*(s32 *)(channel + MUS_CH_NOTE_STREAM) == 0) goto nextChannel;
            }
            if (*(s32 *)(channel + MUS_CH_VOLUME_STREAM) != 0 && *(u32 *)(channel + MUS_CH_VOLUME_STREAM_TIME) < *(u32 *)(channel + MUS_CH_TIME)) func_801C2144((MusVolumeChannel *)channel);
            if (*(s32 *)(channel + MUS_CH_PITCH_STREAM) != 0 && *(u32 *)(channel + MUS_CH_PITCH_STREAM_TIME) < *(u32 *)(channel + MUS_CH_TIME)) func_801C21FC((UnkStream21FC *)channel);
            if (*(s32 *)(channel + MUS_CH_FADE_REMAINING) != MUS_FADE_INACTIVE) {
                *(s32 *)(channel + MUS_CH_FADE_REMAINING) = *(s32 *)(channel + MUS_CH_FADE_REMAINING) - 1;
                if (*(s32 *)(channel + MUS_CH_FADE_REMAINING) == MUS_FADE_INACTIVE) {
                    *(s32 *)(channel + MUS_CH_NOTE_STREAM) = func_801BF800(channel, 0);
                    if (channel[MUS_CH_VOICE_ACTIVE] != 0) { channel[MUS_CH_VOICE_ACTIVE] = 0; func_801CBBE0((ObjectNode *)D_802AB2C8, (ObjectNode *)(D_802AB03C + voiceIndex * MUS_VOICE_SIZE)); }
                }
            }
            if (channel[MUS_CH_VOICE_ACTIVE] != 0) {
                if (channel[MUS_CH_ENVELOPE_STATE] != 0) func_801C1DB4(channel);
                if (channel[MUS_CH_PAN_SWEEP_RATE] != 0 && *(u32 *)(channel + MUS_CH_PAN_SWEEP_TIME) < *(u32 *)(channel + MUS_CH_TIME)) func_801C1FD8(channel);
                pitchOffset = *(f32 *)(channel + MUS_CH_PITCH_OFFSET);
                if (channel[MUS_CH_SINE_PITCH_PERIOD] != 0) pitchOffset += func_801C20D8(channel);
                if (channel[MUS_CH_SQUARE_PITCH_DURATION] != 0) pitchOffset += func_801C2088(channel);
                if (*(s32 *)(channel + MUS_CH_PENDING_WAVETABLE) == 0) { func_801C1C1C(channel, voiceIndex, pitchOffset); func_801C1A90(channel, voiceIndex); }
            }
            *(u16 *)(channel + MUS_CH_SLIDE_ELAPSED) = (*(u32 *)(channel + MUS_CH_TIME) - *(u32 *)(channel + MUS_CH_NOTE_START_TIME)) >> MUS_TIME_FRACTION_BITS;
        }
    nextChannel:
        voiceIndex++; channel += MUS_CHANNEL_BYTES;
    } while (voiceIndex < D_802AB038);
    return D_802AB050;
}

extern u8 *D_801F40C0[];
void func_801CBBE0(ObjectNode *, ObjectNode *);
void func_801CBD90(u8 *, u8 *, s16, s32);
void func_801CBE50(u8 *, u8 *, u8);
void func_801C1D48(u8 *arg0);
void func_801C1FBC(u8 *arg0);
/* Decode the next music note or rest, updating its envelope, pitch and voice. */
void func_801C15B8(u8 *channel, s32 voiceIndex)
{
    u8 *stream;
    s32 byteValue;
    s32 note;
    s32 noteStartTime;
    u8 *sampleBank;
    s32 sampleIndex;
    u8 encodedByte;
    u8 effectMix;
    s32 wavetableAddress;

    stream = *(u8 **)(channel + MUS_CH_NOTE_STREAM);
    if (stream != 0) {
        byteValue = stream[0];
        if (byteValue >= MUS_SEQUENCE_COMMAND_FLAG) {
            do {
                stream = ((MusSequenceCommandHandler)D_801F40C0[byteValue & MUS_SEQUENCE_VALUE_MASK])(channel, stream + 1);
                if (stream == 0) {
                    break;
                }
                byteValue = stream[0];
            } while (byteValue >= MUS_SEQUENCE_COMMAND_FLAG);
        }
    }
    *(u8 **)(channel + MUS_CH_NOTE_STREAM) = stream;
    if (stream != 0) {
        *(f32 *)(channel + MUS_CH_SLIDE_START_PITCH) = *(f32 *)(channel + MUS_CH_SLIDE_PITCH);
        note = *(*(u8 **)(channel + MUS_CH_NOTE_STREAM))++;
        if (channel[MUS_CH_EXPLICIT_NOTE_VOLUME] != 0) {
            channel[MUS_CH_NOTE_VOLUME] = *(*(u8 **)(channel + MUS_CH_NOTE_STREAM))++;
        } else {
            channel[MUS_CH_NOTE_VOLUME] = channel[MUS_CH_DEFAULT_NOTE_VOLUME];
        }
        if (*(u16 *)(channel + MUS_CH_DEFAULT_DURATION) != 0) {
            if (channel[MUS_CH_DURATION_OVERRIDE] == 0) {
                *(u16 *)(channel + MUS_CH_NOTE_DURATION) = *(u16 *)(channel + MUS_CH_DEFAULT_DURATION);
            } else {
                channel[MUS_CH_DURATION_OVERRIDE] = 0;
                encodedByte = *(*(u8 **)(channel + MUS_CH_NOTE_STREAM))++;
                byteValue = encodedByte;
                if (byteValue < MUS_SEQUENCE_COMMAND_FLAG) {
                    *(u16 *)(channel + MUS_CH_NOTE_DURATION) = byteValue;
                } else {
                    *(u16 *)(channel + MUS_CH_NOTE_DURATION) = ((byteValue & MUS_SEQUENCE_VALUE_MASK) << MUS_TIME_FRACTION_BITS) + *(*(u8 **)(channel + MUS_CH_NOTE_STREAM))++;
                }
            }
        } else {
            encodedByte = *(*(u8 **)(channel + MUS_CH_NOTE_STREAM))++;
            byteValue = encodedByte;
            if (byteValue < MUS_SEQUENCE_COMMAND_FLAG) {
                *(u16 *)(channel + MUS_CH_NOTE_DURATION) = byteValue;
            } else {
                *(u16 *)(channel + MUS_CH_NOTE_DURATION) = ((byteValue & MUS_SEQUENCE_VALUE_MASK) << MUS_TIME_FRACTION_BITS) + *(*(u8 **)(channel + MUS_CH_NOTE_STREAM))++;
            }
        }
        noteStartTime = *(s32 *)(channel + MUS_CH_NEXT_NOTE_TIME);
        *(s32 *)(channel + MUS_CH_NEXT_NOTE_TIME) += *(u16 *)(channel + MUS_CH_NOTE_DURATION) << MUS_TIME_FRACTION_BITS;
        *(u16 *)(channel + MUS_CH_SLIDE_ELAPSED) = 0;
        channel[MUS_CH_VIBRATO_STATE] = 0;
        *(s32 *)(channel + MUS_CH_NOTE_START_TIME) = noteStartTime;
        channel[MUS_CH_VIBRATO_COUNTDOWN] = channel[MUS_CH_VIBRATO_INITIAL_DELAY];
        if (note != MUS_SEQUENCE_REST) {
            sampleBank = *(u8 **)(channel + MUS_CH_SAMPLE_BANK);
            if (*(u8 **)(channel + MUS_CH_DRUM_MAP) != 0) {
                *(u16 *)(channel + MUS_CH_SAMPLE_INDEX) = (*(u8 **)(channel + MUS_CH_DRUM_MAP) + note * MUS_DRUM_ENTRY_SIZE)[MUS_DRUM_SAMPLE];
                channel[MUS_CH_PAN] = (*(u8 **)(channel + MUS_CH_DRUM_MAP) + note * MUS_DRUM_ENTRY_SIZE)[MUS_DRUM_PAN] / 2;
                func_801BF88C(channel, (u8 *)(*(s32 *)(*(s32 *)(channel + MUS_CH_SONG) + MUS_SONG_ENVELOPES_OFFSET) + (*(u8 **)(channel + MUS_CH_DRUM_MAP) + note * MUS_DRUM_ENTRY_SIZE)[MUS_DRUM_ENVELOPE] * MUS_ENVELOPE_SIZE));
                note = (*(u8 **)(channel + MUS_CH_DRUM_MAP) + note * MUS_DRUM_ENTRY_SIZE)[MUS_DRUM_NOTE];
            }
            if (channel[MUS_CH_HOLD_ENVELOPE] == 0) {
                func_801C1D48(channel);
            }
            if (channel[MUS_CH_PAN_SWEEP_RATE] != 0) {
                func_801C1FBC(channel);
            }
            sampleIndex = *(u16 *)(channel + MUS_CH_SAMPLE_INDEX);
            if (channel[MUS_CH_HOLD_VOICE] == 0) {
                wavetableAddress = *(s32 *)(*(s32 *)(sampleBank + MUS_BANK_WAVETABLE_TABLE_OFFSET) + sampleIndex * 4);
                *(s32 *)(channel + MUS_CH_PENDING_WAVETABLE) = wavetableAddress;
                if (channel[MUS_CH_VOICE_ACTIVE] != 0 && *(u16 *)(channel + MUS_CH_CACHED_VOLUME) != 0) {
                    *(u16 *)(channel + MUS_CH_CACHED_VOLUME) = 0;
                    func_801CBD90(D_802AB2C8, D_802AB03C + voiceIndex * MUS_VOICE_SIZE, 0, D_802AB050);
                } else {
                    func_801C19FC(channel, voiceIndex);
                }
            }
            *(f32 *)(channel + MUS_CH_NOTE_PITCH) = *(f32 *)(*(s32 *)(sampleBank + MUS_BANK_PITCH_TABLE_OFFSET) + sampleIndex * 4) + (f32)note;
            encodedByte = (1 - channel[MUS_CH_TRANSPOSE_DISABLED]) * channel[MUS_CH_TRANSPOSE];
            byteValue = encodedByte;
            *(f32 *)(channel + MUS_CH_NOTE_PITCH) += (f32)(((f32)(byteValue & 0x80) != 0.0f) ? (-256 - (-byteValue)) : byteValue);
            if (channel[MUS_CH_CACHED_EFFECT_MIX] != channel[MUS_CH_EFFECT_MIX]) {
                effectMix = channel[MUS_CH_EFFECT_MIX_OVERRIDE];
                channel[MUS_CH_CACHED_EFFECT_MIX] = channel[MUS_CH_EFFECT_MIX];
                effectMix += ((MUS_EFFECT_MIX_UNITY - effectMix) * channel[MUS_CH_EFFECT_MIX]) >> MUS_EFFECT_MIX_FRACTION_BITS;
                func_801CBE50(D_802AB2C8, D_802AB03C + voiceIndex * MUS_VOICE_SIZE, effectMix);
            }
        } else if (channel[MUS_CH_ENVELOPE_STATE] < MUS_ENVELOPE_RELEASE) {
            channel[MUS_CH_ENVELOPE_STATE] = MUS_ENVELOPE_RELEASE;
            *(s32 *)(channel + MUS_CH_RELEASE_TIME) = *(s32 *)(channel + MUS_CH_TIME);
            channel[MUS_CH_ENVELOPE_COUNTDOWN] = 1;
            channel[MUS_CH_RELEASE_VOLUME] = channel[MUS_CH_ENVELOPE_VOLUME];
        }
    } else {
        if (channel[MUS_CH_VOICE_ACTIVE] != 0) {
            channel[MUS_CH_VOICE_ACTIVE] = 0;
            func_801CBD90(D_802AB2C8, D_802AB03C + voiceIndex * MUS_VOICE_SIZE, 0, D_802AB050);
            func_801CBBE0((ObjectNode *)D_802AB2C8, (ObjectNode *)(D_802AB03C + voiceIndex * MUS_VOICE_SIZE));
        }
    }
}

s32 func_801CBC60(u8 *, u8 *, s32);
/* Start a channel's pending wavetable on its synth voice: stop the voice if it
 * is playing (func_801CBBE0, alSynStopVoice), mark it active, start it with the
 * pending wavetable (func_801CBC60, alSynStartVoice) and clear the pending slot.
 * D_802AB2C8 is the synth driver, D_802AB03C the music voice array. */
void func_801C19FC(u8 *channel, s32 voiceIndex)
{
    if (channel[MUS_CH_VOICE_ACTIVE] != 0) {
        func_801CBBE0((ObjectNode *)D_802AB2C8, (ObjectNode *)(D_802AB03C + voiceIndex * MUS_VOICE_SIZE));
    }
    channel[MUS_CH_VOICE_ACTIVE] = 1;
    func_801CBC60(D_802AB2C8, D_802AB03C + voiceIndex * MUS_VOICE_SIZE, *(s32 *)(channel + MUS_CH_PENDING_WAVETABLE));
    *(s32 *)(channel + MUS_CH_PENDING_WAVETABLE) = 0;
}

void func_801CBEE0(ObjectNode *, ObjectNode *, u8);

/* Apply channel volume, fade-out and pan to the synthesizer voice when they change. */
void func_801C1A90(u8 *channel, s32 voiceIndex)
{
    u32 voiceValue;
    s32 fadeRemaining;

    voiceValue = *(s16 *)(channel + MUS_CH_HANDLE_VOLUME) * (u32)(channel[MUS_CH_ENVELOPE_VOLUME] * channel[MUS_CH_NOTE_VOLUME] * channel[MUS_CH_SEQUENCE_VOLUME]);
    voiceValue >>= MUS_VOLUME_PRODUCT_SHIFT;
    if (voiceValue >= MUS_VOLUME_CLIP_THRESHOLD) {
        voiceValue = MUS_MASTER_VOLUME_MAX;
    }
    if (*(u16 *)(channel + MUS_CH_EFFECT_ID) == 0) {
        voiceValue *= D_802AB056;
    } else {
        voiceValue *= D_802AB054;
    }
    fadeRemaining = *(s32 *)(channel + MUS_CH_FADE_REMAINING);
    voiceValue >>= MUS_MASTER_VOLUME_FRACTION_BITS;
    if (fadeRemaining != MUS_FADE_INACTIVE) {
        voiceValue = (fadeRemaining * voiceValue) / *(u32 *)(channel + MUS_CH_FADE_DURATION);
    }
    if (voiceValue != *(u16 *)(channel + MUS_CH_CACHED_VOLUME)) {
        *(u16 *)(channel + MUS_CH_CACHED_VOLUME) = voiceValue;
        func_801CBD90(D_802AB2C8, D_802AB03C + voiceIndex * MUS_VOICE_SIZE, (s16)voiceValue, D_802AB050);
    }
    if (channel[MUS_CH_CACHED_PAN] != channel[MUS_CH_PAN]) {
        voiceValue = (*(s16 *)(channel + MUS_CH_HANDLE_PAN) * channel[MUS_CH_PAN] >> MUS_PAN_FRACTION_BITS) & MUS_PAN_MASK;
        channel[MUS_CH_CACHED_PAN] = voiceValue;
        func_801CBEE0((ObjectNode *)D_802AB2C8, (ObjectNode *)(D_802AB03C + voiceIndex * MUS_VOICE_SIZE), (u8)voiceValue);
    }
}

f32 func_801C2314(f32 x);
/* mus_apply_pitch: apply portamento and pitch offsets, then update the voice if its pitch changed. */
void func_801C1C1C(u8 *channel, s32 voiceIndex, f32 modulationPitch) {
    u8 slideDuration;
    f32 pitch;
    f32 slideDelta;

    slideDuration = channel[MUS_CH_SLIDE_DURATION];
    pitch = *(f32 *)(channel + MUS_CH_NOTE_PITCH);
    if (slideDuration != 0) {
        s32 slideElapsed = *(u16 *)(channel + MUS_CH_SLIDE_ELAPSED);
        if (slideDuration >= slideElapsed) {
            slideDelta = (pitch - *(f32 *)(channel + MUS_CH_SLIDE_START_PITCH)) / (f32)(u32)slideDuration;
            slideDelta *= (f32)(u32)slideElapsed;
            pitch = *(f32 *)(channel + MUS_CH_SLIDE_START_PITCH) + slideDelta;
        }
        *(f32 *)(channel + MUS_CH_SLIDE_PITCH) = pitch;
    }
    pitch += modulationPitch + *(f32 *)(channel + MUS_CH_STREAM_PITCH);
    if (pitch == *(f32 *)(channel + MUS_CH_CACHED_PITCH)) {
        return;
    }
    *(f32 *)(channel + MUS_CH_CACHED_PITCH) = pitch;
    pitch = func_801C2314((f32)((f64)pitch * D_8010C180));
    if (2.0 < (f64)pitch) {
        pitch = 2.0f;
        channel[MUS_CH_NOTE_VOLUME] = 0;
    }
    func_801CBD00((ObjectNode *)D_802AB2C8, (ObjectNode *)(D_802AB03C + voiceIndex * MUS_VOICE_SIZE), pitch);
}

/* musStartEnvelope: work out when the note's release begins and start the
 * envelope in its attack phase at the initial volume. */
void func_801C1D48(u8 *channel) {
    MusEnvelopeChannel *envelope = (MusEnvelopeChannel *)channel;
    u32 never = MUS_RELEASE_NEVER;

    if (envelope->noteLength != MUS_NOTE_LENGTH_HELD) {
        u32 fixedLength = envelope->fixedLength;
        if (fixedLength != 0) {
            envelope->releaseTime = envelope->noteStartTime + (fixedLength << 8);
        } else {
            envelope->releaseTime = envelope->noteEndTime - (envelope->releaseFrames << 8);
        }
    } else {
        envelope->releaseTime = never;
    }
    envelope->volume = envelope->initialVolume;
    envelope->updateCountdown = envelope->updatePeriod;
    envelope->state = MUS_ENVELOPE_ATTACK;
}

/* Advance the channel's attack/decay/sustain/release volume envelope. */
void func_801C1DB4(u8 *channel) {
    s32 elapsed;
    u32 releaseVolume;

    if (((MusEnvelopeChannel *)channel)->time >= ((MusEnvelopeChannel *)channel)->releaseTime && ((MusEnvelopeChannel *)channel)->state < MUS_ENVELOPE_RELEASE) {
        ((MusEnvelopeChannel *)channel)->state = MUS_ENVELOPE_RELEASE;
        ((MusEnvelopeChannel *)channel)->updateCountdown = 1;
        ((MusEnvelopeChannel *)channel)->releaseVolume = ((MusEnvelopeChannel *)channel)->volume;
    }
    if (--((MusEnvelopeChannel *)channel)->updateCountdown) {
        return;
    }
    ((MusEnvelopeChannel *)channel)->updateCountdown = ((MusEnvelopeChannel *)channel)->updatePeriod;
    switch (((MusEnvelopeChannel *)channel)->state) {
    case MUS_ENVELOPE_ATTACK:
        elapsed = (((((MusEnvelopeChannel *)channel)->time - ((MusEnvelopeChannel *)channel)->noteStartTime) >> MUS_TIME_FRACTION_BITS) * ((MusEnvelopeChannel *)channel)->timeScale) >> MUS_ENVELOPE_SCALE_BITS;
        if (elapsed < ((MusEnvelopeChannel *)channel)->attackDuration) {
            ((MusEnvelopeChannel *)channel)->volume = ((MusEnvelopeChannel *)channel)->initialVolume + (s32)(((MusEnvelopeChannel *)channel)->attackSlope * elapsed);
        } else {
            ((MusEnvelopeChannel *)channel)->state++;
            ((MusEnvelopeChannel *)channel)->volume = ((MusEnvelopeChannel *)channel)->attackVolume;
        }
        return;
    case MUS_ENVELOPE_DECAY:
        elapsed = ((((((MusEnvelopeChannel *)channel)->time - ((MusEnvelopeChannel *)channel)->noteStartTime) >> MUS_TIME_FRACTION_BITS) - ((MusEnvelopeChannel *)channel)->attackDuration) * ((MusEnvelopeChannel *)channel)->timeScale) >> MUS_ENVELOPE_SCALE_BITS;
        if (elapsed < ((MusEnvelopeChannel *)channel)->decayDuration) {
            ((MusEnvelopeChannel *)channel)->volume = ((MusEnvelopeChannel *)channel)->attackVolume + (s32)(((MusEnvelopeChannel *)channel)->decaySlope * elapsed);
        } else {
            ((MusEnvelopeChannel *)channel)->state++;
            ((MusEnvelopeChannel *)channel)->volume = ((MusEnvelopeChannel *)channel)->sustainVolume;
        }
        return;
    case MUS_ENVELOPE_SUSTAIN:
        return;
    case MUS_ENVELOPE_RELEASE:
        elapsed = (((((MusEnvelopeChannel *)channel)->time - ((MusEnvelopeChannel *)channel)->releaseTime) >> MUS_TIME_FRACTION_BITS) * ((MusEnvelopeChannel *)channel)->timeScale) >> MUS_ENVELOPE_SCALE_BITS;
        if (elapsed < ((MusEnvelopeChannel *)channel)->releaseDuration) {
            releaseVolume = ((MusEnvelopeChannel *)channel)->releaseVolume;
            ((MusEnvelopeChannel *)channel)->volume = releaseVolume - (s32)(((MusEnvelopeChannel *)channel)->releaseSlope * elapsed * releaseVolume);
        } else {
            ((MusEnvelopeChannel *)channel)->state++;
            ((MusEnvelopeChannel *)channel)->volume = 0;
        }
        return;
    }
}

/* Restarts a music channel's pan sweep: the sweep clock starts at the note's
 * start time, the carried fraction is cleared, and it falls toward 0 when the
 * pan is in the right half (>= 64), otherwise rises toward 127. */
void func_801C1FBC(u8 *channel) {
    u8 *ch = channel;
    ((s32 *)ch)[MUS_CH_PAN_SWEEP_TIME / 4] = ((s32 *)ch)[MUS_CH_NOTE_START_TIME / 4];
    ch[MUS_CH_PAN_SWEEP_FRACTION] = 0;
    ch[MUS_CH_PAN_SWEEP_FALLING] = ch[MUS_CH_PAN] & MUS_CHANNEL_PAN_CENTER;
}

/* Advances a channel's pan sweep up to the channel time: each update adds
 * the sweep rate (six fractional bits) to the pan, bouncing it between 0
 * and 127. */
void func_801C1FD8(u8 *channel) {
    do {
        u32 step;
        *(u32 *)(channel + MUS_CH_PAN_SWEEP_TIME) += 0x100;
        step = channel[MUS_CH_PAN_SWEEP_RATE] + channel[MUS_CH_PAN_SWEEP_FRACTION];
        if (step < 0x40) {
            channel[MUS_CH_PAN_SWEEP_FRACTION] = step;
            continue;
        }
        channel[MUS_CH_PAN_SWEEP_FRACTION] = step & 0x3F;
        step >>= 6;
        if (channel[MUS_CH_PAN_SWEEP_FALLING] == 0) {
            channel[MUS_CH_PAN] += step;
            if (channel[MUS_CH_PAN] >= 0x80) {
                channel[MUS_CH_PAN] = 0x7F;
                channel[MUS_CH_PAN_SWEEP_FALLING] = 1;
            }
        } else {
            channel[MUS_CH_PAN] -= step;
            if (channel[MUS_CH_PAN] >= 0x80 || channel[MUS_CH_PAN] == 0) {
                channel[MUS_CH_PAN] = 0;
                channel[MUS_CH_PAN_SWEEP_FALLING] = 0;
            }
        }
    } while (*(u32 *)(channel + MUS_CH_PAN_SWEEP_TIME) < *(u32 *)(channel + MUS_CH_TIME));
}

/* Square-wave pitch modulation: when the countdown expires, toggle between
 * the depth (held for the square duration) and zero (held for the second
 * duration). Returns the current offset in semitones. */
f32 func_801C2088(u8 *channel) {
    if (--channel[MUS_CH_VIBRATO_COUNTDOWN] == 0) {
        if ((s8)channel[MUS_CH_VIBRATO_STATE] == 0) {
            channel[MUS_CH_VIBRATO_STATE] = *(s8 *)(channel + MUS_CH_SQUARE_PITCH_DEPTH);
            channel[MUS_CH_VIBRATO_COUNTDOWN] = channel[MUS_CH_SQUARE_PITCH_DURATION];
        } else {
            channel[MUS_CH_VIBRATO_STATE] = 0;
            channel[MUS_CH_VIBRATO_COUNTDOWN] = channel[MUS_CH_VIBRATO_INITIAL_DELAY];
        }
    }
    return (f32)(s8)channel[MUS_CH_VIBRATO_STATE];
}

f32 func_801C6000(f32);

/* Sine vibrato: once the note has run past the vibrato delay, the pitch offset is
 * depth * sinf(step * (elapsed - delay)); before that it is zero. The offset is
 * stored in the channel and returned. func_801C6000 is sinf. */
f32 func_801C20D8(u8 *channel)
{
    f32 offset;
    if ((*(u16 *)(channel + MUS_CH_SLIDE_ELAPSED) - channel[MUS_CH_SINE_PITCH_DELAY]) > 0) {
        offset = *(f32 *)(channel + MUS_CH_SINE_PITCH_DEPTH) * func_801C6000(*(f32 *)(channel + MUS_CH_SINE_PITCH_STEP) * (f32)(*(u16 *)(channel + MUS_CH_SLIDE_ELAPSED) - channel[MUS_CH_SINE_PITCH_DELAY]));
        *(f32 *)(channel + MUS_CH_SINE_PITCH_VALUE) = offset;
    } else {
        *(f32 *)(channel + MUS_CH_SINE_PITCH_VALUE) = 0.0f;
    }
    return *(f32 *)(channel + MUS_CH_SINE_PITCH_VALUE);
}

/*
 * mus_advance_volume_stream: advance a music channel's volume stream up to the
 * channel time. Run-length coded: a byte below 0x80 is a volume held for one
 * tick; a byte >= 0x80 carries the volume in its low 7 bits and is followed by
 * a run length (one byte, or two big-endian bytes when the first has bit 7
 * set), stored plus 2.
 */
void func_801C2144(MusVolumeChannel *channel) {
    u8 code;
    do {
        channel->volumeStreamTime += 0x100;
        channel->volumeRunLeft--;
        if (channel->volumeRunLeft == 0) {
            code = *channel->volumeStream++;
            if (code >= 0x80) {
                channel->sequenceVolume = code & 0x7F;
                code = *channel->volumeStream++;
                if (code >= 0x80) {
                    channel->volumeRunLeft = (code & 0x7F) << 8;
                    channel->volumeRunLeft += *channel->volumeStream++ + 2;
                } else {
                    channel->volumeRunLeft = code + 2;
                }
            } else {
                channel->sequenceVolume = code;
                channel->volumeRunLeft = 1;
            }
        }
    } while (channel->volumeStreamTime < channel->time);
}


/*
 * Advance a music channel's pitch-bend stream up to the channel time.
 * The stream is run-length coded: a byte below 0x80 is a bend value held for
 * one tick; a byte >= 0x80 carries the value in its low 7 bits and is
 * followed by a run length (one byte, or two big-endian bytes when the first
 * has bit 7 set), stored plus 2. Values are centred on 64 and scaled by the
 * channel's bend range (unk6C) into the pitch bend (unk24).
 */
void func_801C21FC(UnkStream21FC *channel) {
    u8 code;
    f32 bend;
    do {
        channel->unk18 += 0x100;
        channel->unkA0--;
        if (channel->unkA0 == 0) {
            code = *channel->unk34++;
            if (code >= 0x80) {
                bend = (f32)(s32)(code & 0x7F) - 64.0;
                channel->unk70 = bend;
                channel->unk24 = channel->unk70 * channel->unk6C;
                code = *channel->unk34++;
                if (code >= 0x80) {
                    channel->unkA0 = (code & 0x7F) << 8;
                    channel->unkA0 += *channel->unk34++ + 2;
                } else {
                    channel->unkA0 = code + 2;
                }
            } else {
                bend = (f32)(u32)code;
                bend = (f64)bend - 64.0;
                channel->unk70 = bend;
                channel->unkA0 = 1;
                channel->unk24 = channel->unk70 * channel->unk6C;
            }
        }
    } while (channel->unk18 < channel->unkC);
}

extern const f64 D_8010C188, D_8010C190, D_8010C198, D_8010C1A0, D_8010C1A8, D_8010C1B0, D_8010C1B8, D_8010C1C0, D_8010C1C8, D_8010C1D0, D_8010C1D8, D_8010C1E0;
/* mus_pitch_ratio_from_octaves: approximate 2^octaves, using a reciprocal for negative offsets. */
f32 func_801C2314(f32 octaves) {
    f32 octavesSquared;
    f32 octavesFourth;
    f64 unity;

    if (octaves == 0.0f) {
        return 1.0f;
    }
    if (0.0f < octaves) {
        octavesSquared = octaves * octaves;
        unity = 1.0;
        octavesFourth = octavesSquared * octavesSquared;
        return octaves * D_8010C188 + unity + octavesSquared * D_8010C190 + (octavesSquared * octaves) * D_8010C198 + octavesFourth * D_8010C1A0
            + (octavesFourth * octaves) * D_8010C1A8 + (octavesFourth * octavesSquared) * D_8010C1B0;
    }
    octaves = -octaves;
    unity = 1.0;
    octavesSquared = octaves * octaves;
    octavesFourth = octavesSquared * octavesSquared;
    return unity / (octaves * D_8010C1B8 + unity + octavesSquared * D_8010C1C0 + (octavesSquared * octaves) * D_8010C1C8 + octavesFourth * D_8010C1D0
                  + (octavesFourth * octaves) * D_8010C1D8 + (octavesFourth * octavesSquared) * D_8010C1E0);
}

/* Relocate the sample bank and its wave tables, decode tuning, then flush the data cache. */
void func_801C249C(s32 *bank, s32 sampleRomAddress) {
    f32 *tuning;
    s32 tableOffset;
    s32 sampleIndex;
    s32 *bankHeader = bank;

    if (!(((MusSampleBank *)bank)->flags & MUS_SAMPLE_BANK_RELOCATED)) {
        ((MusSampleBank *)bank)->flags |= MUS_SAMPLE_BANK_RELOCATED;
        func_801C2A84(&((MusSampleBank *)bank)->baseNotes, bank, MUS_SAMPLE_BANK_POINTER_COUNT);
        func_801C2A84((s32 *)((MusSampleBank *)bank)->waves, bank, ((MusSampleBank *)bank)->sampleCount);
        for (sampleIndex = 0, tableOffset = 0; sampleIndex < ((MusSampleBank *)bankHeader)->sampleCount; sampleIndex++, tableOffset += 4) {
            u8 encodedPitch;
            s32 positivePitch;
            f32 pitch;
            s32 *wave;
            s32 sampleAddress;

            tuning = (f32 *)((u8 *)((MusSampleBank *)bank)->tuning + tableOffset);
            encodedPitch = *(u8 *)tuning;
            if (encodedPitch & MUS_SAMPLE_SIGN_BIT) {
                pitch = -(MUS_SAMPLE_BYTE_RANGE - encodedPitch);
            } else {
                positivePitch = encodedPitch;
                pitch = positivePitch;
            }
            *tuning = pitch / 100.0;
            encodedPitch = ((u8 *)((MusSampleBank *)bank)->baseNotes)[sampleIndex] - MUS_SAMPLE_REFERENCE_NOTE;
            if (encodedPitch & MUS_SAMPLE_SIGN_BIT) {
                pitch = -(MUS_SAMPLE_BYTE_RANGE - encodedPitch);
            } else {
                positivePitch = encodedPitch;
                pitch = positivePitch;
            }
            *tuning += pitch;
            wave = *(s32 **)((u8 *)((MusSampleBank *)bank)->waves + tableOffset);
            if (((AudioSampleWave *)wave)->flags == 0) {
                sampleAddress = ((AudioSampleWave *)wave)->base;
                if ((sampleAddress & MUS_SAMPLE_ADDRESS_TAG_MASK) != MUS_SAMPLE_ADDRESS_TAG_MASK) {
                    sampleAddress += sampleRomAddress;
                    ((AudioSampleWave *)wave)->base = sampleAddress;
                }
                wave = *(s32 **)((u8 *)((MusSampleBank *)bank)->waves + tableOffset);
                ((AudioSampleWave *)wave)->flags = MUS_SAMPLE_WAVE_RELOCATED;
                wave = *(s32 **)((u8 *)((MusSampleBank *)bank)->waves + tableOffset);
                if (wave[MUS_SAMPLE_WAVE_LOOP_WORD]) {
                    wave[MUS_SAMPLE_WAVE_LOOP_WORD] += (s32)bank;
                }
                wave = *(s32 **)((u8 *)((MusSampleBank *)bank)->waves + tableOffset);
                if (((AudioSampleWave *)wave)->type == MUS_SAMPLE_WAVE_ADPCM) {
                    wave[MUS_SAMPLE_WAVE_BOOK_WORD] += (s32)bank;
                }
            }
        }
        func_801C64F0();
    }
}

/* Random integer in [0, range): steps the LFSR D_802AB05C eight bits and scales it by range. */
s32 func_801C2668(s32 range) {
    s32 step;
    s32 taps;
    f32 fraction;

    for (step = 0; step < MUS_RANDOM_STEPS; step++) {
        taps = D_802AB05C & MUS_RANDOM_TAPS;
        D_802AB05C <<= 1;
        if (taps == MUS_RANDOM_TAPS || taps == MUS_RANDOM_TAP_LOW) {
            D_802AB05C |= 1;
        }
    }
    fraction = (f32)D_802AB05C / 65536.0f;
    fraction /= 65536.0f;
    return (f32)range * fraction;
}

/* mus_reset_channel: restore playback defaults while preserving the voice-active flag. */
void func_801C2768(channel)
u8 *channel;
{
    u8 voiceActive;
    s32 byteIndex;
    u8 *clearByte;
    u16 timeStep;

    *(s32 *)(channel + MUS_CH_NOTE_STREAM) = 0;
    voiceActive = channel[MUS_CH_VOICE_ACTIVE];
    clearByte = channel;
    for (byteIndex = 0; byteIndex < MUS_CHANNEL_BYTES; byteIndex++) {
        *clearByte++ = 0;
    }
    *(u16 *)(channel + MUS_CH_CACHED_VOLUME) = MUS_VOLUME_CACHE_INVALID;
    channel[MUS_CH_CACHED_EFFECT_MIX] = MUS_BYTE_CACHE_INVALID;
    channel[MUS_CH_CACHED_PAN] = MUS_BYTE_CACHE_INVALID;
    *(f32 *)(channel + MUS_CH_CACHED_PITCH) = D_8010C1E8;
    timeStep = MUS_DEFAULT_FIXED_TICKS_PER_SECOND / D_802AB04C;
    *(u16 *)(channel + MUS_CH_BASE_TIME_STEP) = timeStep;
    *(u16 *)(channel + MUS_CH_TIME_STEP) = timeStep;
    *(u16 *)(channel + MUS_CH_NOTE_DURATION) = 1;
    channel[MUS_CH_EXPLICIT_NOTE_VOLUME] = 0;
    channel[MUS_CH_DEFAULT_NOTE_VOLUME] = MUS_CHANNEL_VOLUME_MAX;
    channel[MUS_CH_SEQUENCE_VOLUME] = MUS_CHANNEL_VOLUME_MAX;
    channel[MUS_CH_PAN] = MUS_CHANNEL_PAN_CENTER;
    *(u16 *)(channel + MUS_CH_VOLUME_STREAM_COUNTDOWN) = 1;
    *(u16 *)(channel + MUS_CH_PITCH_STREAM_COUNTDOWN) = 1;
    *(s32 *)(channel + MUS_CH_FADE_REMAINING) = MUS_FADE_INACTIVE;
    *(u16 *)(channel + MUS_CH_HANDLE_VOLUME) = MUS_HANDLE_SCALE_UNITY;
    *(u16 *)(channel + MUS_CH_HANDLE_PAN) = MUS_HANDLE_SCALE_UNITY;
    *(u16 *)(channel + MUS_CH_HANDLE_TEMPO) = MUS_HANDLE_SCALE_UNITY;
    channel[MUS_CH_ENVELOPE_UPDATE_PERIOD] = 1;
    channel[MUS_CH_ATTACK_DURATION] = 1;
    channel[MUS_CH_ATTACK_VOLUME] = MUS_CHANNEL_VOLUME_MAX;
    channel[MUS_CH_DECAY_DURATION] = MUS_DEFAULT_DECAY_DURATION;
    *(f32 *)(channel + MUS_CH_PITCH_STREAM_SCALE) = 0.03125f;
    *(f32 *)(channel + MUS_CH_ATTACK_SLOPE) = 1.0f;
    *(f32 *)(channel + MUS_CH_DECAY_SLOPE) = D_8010C1EC;
    channel[MUS_CH_SUSTAIN_VOLUME] = MUS_CHANNEL_VOLUME_MAX;
    channel[MUS_CH_RELEASE_DURATION] = MUS_DEFAULT_RELEASE_DURATION;
    *(f32 *)(channel + MUS_CH_RELEASE_SLOPE) = D_8010C1F0;
    *(s32 *)(channel + MUS_CH_SAMPLE_BANK) = D_802AB060;
    channel[MUS_CH_VOICE_ACTIVE] = voiceActive;
    channel[MUS_CH_SINE_PITCH_PERIOD] = 0;
}

/* mus_select_song_channel: choose an idle or replaceable channel for a song track. */
s32 func_801C28A0(s32 *song, s32 trackIndex) {
    s32 channelIndex, lowestPriority, bestChannel;
    u8 *channel;
    channelIndex = 0; channel = D_802AB040;
    while (channelIndex < D_802AB038) {
        if (*(s32 *)(channel + MUS_CH_NOTE_STREAM) == 0) return channelIndex;
        channelIndex++; channel += MUS_CHANNEL_BYTES;
    }
    lowestPriority = MUS_CHANNEL_PRIORITY_MAX;
    bestChannel = MUS_CHANNEL_NOT_FOUND;
    channelIndex = 0; channel = D_802AB040;
    while (channelIndex < D_802AB038) {
        if (*(u16 *)(channel + MUS_CH_EFFECT_ID) && *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY) <= lowestPriority) {
            lowestPriority = *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY);
            bestChannel = channelIndex;
        }
        channelIndex++; channel += MUS_CHANNEL_BYTES;
    }
    if (bestChannel != MUS_CHANNEL_NOT_FOUND) return bestChannel;
    channelIndex = 0; channel = D_802AB040;
    while (channelIndex < D_802AB038) {
        if (!*(u16 *)(channel + MUS_CH_EFFECT_ID) && *(s32 **)(channel + MUS_CH_SONG) != song) return channelIndex;
        channelIndex++;
    }
    channelIndex = 0; channel = D_802AB040;
    while (channelIndex < D_802AB038) {
        if (*(s32 **)(channel + MUS_CH_SONG) == song && *(s32 *)(channel + MUS_CH_TRACK_START) == ((s32 *)song[MUS_SONG_TRACKS_WORD])[trackIndex]) return channelIndex;
        channelIndex++; channel += MUS_CHANNEL_BYTES;
    }
    return trackIndex % D_802AB038;
}

/* memset-style fill: write count copies of value starting at dst. */
void func_801C2A18(u8 *dst, u8 value, u32 count)
{
    u8 *out = dst;
    while (count--) {
        *out++ = value;
    }
}

/* mus_bcopy: copy `length` bytes from src to dst, one byte at a time
 * (bcopy argument order: source first). */
void func_801C2A4C(u8 *src, u8 *dst, s32 length) {
    u8 *out = dst;
    u8 *in = src;

    while (length--) {
        *out++ = *in++;
    }
}

/* Relocates a table of offsets in place: every nonzero entry gets the base
 * address added, so it becomes a pointer; zero entries stay null. */
void func_801C2A84(s32 *table, s32 *base, s32 count) {
    s32 i;
    s32 *entry = table;
    for (i = 0; i < count; i++) {
        if (entry[i] != 0) entry[i] += (s32)base;
    }
}

/* mus_start_effect_on_channel: resets `channel` and starts sound effect
 * `effectId` on it with the given volume/pan scales and steal priority,
 * pointing its note stream at the effect's sequence (D_802AB044 table).
 * Returns the fresh playback handle (D_802AB058 counter). */
s32 func_801C2B24(u8 *channel, s32 effectId, s32 volumeScale, s32 panScale, s32 priority)
{
    func_801C2768(channel); /* mus_reset_channel */
    *(u16 *)(channel + MUS_CH_EFFECT_ID) = effectId;
    *(u16 *)(channel + MUS_CH_HANDLE_VOLUME) = volumeScale;
    *(u16 *)(channel + MUS_CH_HANDLE_PAN) = panScale;
    *(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE) = D_802AB058++;
    *(s32 *)(channel + MUS_CH_EFFECT_PRIORITY) = priority;
    *(s32 *)(channel + MUS_CH_NOTE_STREAM) = *(s32 *)(channel + MUS_CH_TRACK_START) = ((s32 *)D_802AB044)[effectId];
    return *(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE);
}

/* mus_set_handle_flags: on every channel playing `handle`, keep the flag bits in
 * `keepMask` and then set the bits in `setBits`. */
void func_801C2BB0(s32 handle, s32 keepMask, s32 setBits) {
    u8 *channel;
    s32 i;

    for (i = 0, channel = D_802AB040; i < D_802AB038; i++, channel += MUS_CHANNEL_BYTES) {
        if (*(s32 *)(channel + MUS_CH_PLAYBACK_HANDLE) == handle) {
            *(u32 *)channel = *(u32 *)channel & keepMask;
            *(u32 *)channel = *(u32 *)channel | setBits;
        }
    }
}

/* Original compiler padding (alignment between the original source files). */
GLOBAL_ASM(
.text
glabel text_padding_1
.word 0, 0
)

extern u8 D_802AB258[];
extern u8 D_802AB290[];
extern u8 D_802AB090[];
extern u8 *D_802AD350;
extern s32 D_801F4180;
void func_8017F9A4(u8 *, void *, void *);
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
void func_801C6550(Thread801 *, s32, u32, s32, void *, s32);
void func_801C7860(QNode *);
void *func_801D0AB0(void);
void *func_801D1320(void);
extern u8 D_802AB098[];
s32 func_801CE300(s32);
void func_801C6520(OSMesgQueue *, void **, s32);
void func_801C3710(void *arg0, void *arg1);
s32 func_801C35B8();
void func_801C3040(s32);



void func_801CB1EC(void *, void *);

/* Initialize audio DMA and synthesis buffers, message queues, and the scheduler-driven audio thread. */
void func_801C2C10(s32 scheduler, AudioSynthConfig *config, s32 threadPriority, s32 *audioParams, s32 dmaBufferCount, s32 dmaBufferBytes, s32 refreshRate) {
    u32 bufferIndex;
    f32 samplesPerUpdate;

    D_802AD368 = (s32)func_801D0AB0();
    D_802AD36C = (s32)func_801D1320();
    D_802AD350 = (u8 *)scheduler;
    D_802AD360 = dmaBufferBytes;
    *(u8 *)D_802AD318 = 0;

    if ((u32)audioParams[AUDIO_PARAM_SAMPLE_RATE] < AUDIO_RATE_ALLOWANCE_THRESHOLD) {
        D_802AD364 = AUDIO_LOW_RATE_ALLOWANCE;
    } else {
        D_802AD364 = AUDIO_HIGH_RATE_ALLOWANCE;
    }
    config->outputRate = (s32)func_801C35B8;
    config->initOsc = func_801CE300(audioParams[AUDIO_PARAM_SAMPLE_RATE]);

    D_802AD354 = func_801CB280(0, 0, config->heap, 1, dmaBufferCount * sizeof(AudioDmaBuffer));
    bufferIndex = dmaBufferCount * 2;
    D_802AD358 = func_801CB280(0, 0, config->heap, 1, bufferIndex * AUDIO_DMA_IO_MESSAGE_BYTES);
    D_802AD35C = func_801CB280(0, 0, config->heap, 1, bufferIndex * AUDIO_MESSAGE_BYTES);

    samplesPerUpdate = ((f32)(u32)audioParams[AUDIO_PARAM_FRAMES_PER_UPDATE] * (f32)config->initOsc) / (f32)refreshRate;
    D_802AD328 = samplesPerUpdate;
    if ((f32)(u32)D_802AD328 < samplesPerUpdate) {
        D_802AD328++;
    }
    if (D_802AD328 & AUDIO_SAMPLE_ALIGNMENT_MASK) {
        D_802AD328 = (D_802AD328 & ~AUDIO_SAMPLE_ALIGNMENT_MASK) + AUDIO_SAMPLE_ALIGNMENT;
    }
    D_802AD324 = D_802AD328 - AUDIO_SAMPLE_ALIGNMENT;
    D_802AD32C = D_802AD364 + D_802AD328 + AUDIO_SAMPLE_ALIGNMENT;
    func_801C3710(D_802AB2C8, config);

    ((AudioDmaBuffer *)D_802AD354)->prev = 0;
    ((AudioDmaBuffer *)D_802AD354)->next = 0;
    for (bufferIndex = 0; bufferIndex < (u32)(dmaBufferCount - 1); bufferIndex++) {
        func_801CB1EC(bufferIndex + 1 + (AudioDmaBuffer *)D_802AD354, bufferIndex + (AudioDmaBuffer *)D_802AD354);
        ((AudioDmaBuffer *)D_802AD354)[bufferIndex].ptr = func_801CB280(0, 0, config->heap, 1, dmaBufferBytes);
    }
    ((AudioDmaBuffer *)D_802AD354)[bufferIndex].ptr = func_801CB280(0, 0, config->heap, 1, dmaBufferBytes);

    for (bufferIndex = 0; bufferIndex < AUDIO_COMMAND_LIST_COUNT; bufferIndex++) {
        ((s32 *)D_802AB090)[bufferIndex] = func_801CB280(0, 0, config->heap, 1, audioParams[AUDIO_PARAM_COMMAND_CAPACITY] * AUDIO_COMMAND_BYTES);
    }

    D_802AD330 = audioParams[AUDIO_PARAM_COMMAND_CAPACITY];

    for (bufferIndex = 0; bufferIndex < AUDIO_TASK_BUFFER_COUNT; bufferIndex++) {
        ((s32 *)D_802AB090)[bufferIndex + AUDIO_COMMAND_LIST_COUNT] = func_801CB280(0, 0, config->heap, 1, AUDIO_TASK_BYTES);
        *(u16 *)(((s32 *)D_802AB090)[bufferIndex + AUDIO_COMMAND_LIST_COUNT] + AUDIO_TASK_MESSAGE_OFFSET) = AUDIO_TASK_COMPLETE_MESSAGE;
        *(s32 *)(((s32 *)D_802AB090)[bufferIndex + AUDIO_COMMAND_LIST_COUNT] + AUDIO_TASK_SELF_OFFSET) = ((s32 *)D_802AB090)[bufferIndex + AUDIO_COMMAND_LIST_COUNT];
        *(s32 *)((s32 *)D_802AB090)[bufferIndex + AUDIO_COMMAND_LIST_COUNT] = func_801CB280(0, 0, config->heap, 1, D_802AD32C * AUDIO_STEREO_SAMPLE_BYTES);
    }

    func_801C6520((OSMesgQueue *)D_802AB290, (void **)D_802AB2A8, AUDIO_MANAGER_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)D_802AB258, (void **)D_802AB270, AUDIO_MANAGER_QUEUE_CAPACITY);
    func_801C6520((OSMesgQueue *)D_802AD338, (void **)D_802AD35C, dmaBufferCount * 2);

    if (D_801F417C == 0) {
        func_801C6550((Thread801 *)D_802AB0A8, AUDIO_MANAGER_THREAD_ID, (u32)func_801C3040, 0, D_802AD318, threadPriority);
    }
    func_801C7860((QNode *)D_802AB0A8);
    D_801F417C = 1;
}

s32 func_801C3198(s32 arg0, s32 arg1);
void func_801C3364(s32 arg0);
/* audioManagerThread: submit audio frames on retrace, wait for completion, and close on quit. */
void func_801C3040(s32 unusedThreadArg)
{
    s32 pad;
    s32 *message;
    SchedulerClient schedulerClient;
    u32 quitRequested = 0;

    func_8017F9A4(D_802AD350, &schedulerClient, D_802AB258);
    for (;;) {
        func_801C7430(D_802AB258, &message, OS_MESG_BLOCK);
        func_801C7430(D_802AB258, NULL, AUDIO_MANAGER_RECEIVE_NONBLOCKING);
        switch (*(s16 *)message) {
        case SCHED_CLIENT_RETRACE:
            if (func_801C3198(*(s32 *)(D_802AB090 + ((D_801F4170 & AUDIO_MANAGER_FRAME_INDEX_MASK) * AUDIO_MESSAGE_BYTES) + AUDIO_MANAGER_FRAME_TABLE_OFFSET), D_801F4180) != 0) {
                func_801C7430(D_802AB290, &message, OS_MESG_BLOCK);
                func_801C3364(message[AUDIO_COMPLETION_FRAME_WORD]);
                D_801F4180 = message[AUDIO_COMPLETION_FRAME_WORD];
            }
            break;
        case SCHED_CLIENT_PRE_NMI:
            break;
        case AUDIO_MANAGER_QUIT_MESSAGE:
            quitRequested = 1;
            break;
        }
        if (quitRequested != 0) break;
    }
    func_801CB1BC((s32 *)D_802AB2C8);
}


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

void func_8011C7F0(void);
extern s32 D_801F4178;
extern u8 D_8011C720[], D_801BE9E0[], D_801F3E00[];
void func_801C35F0(void);
u32 func_801CE2F0(void);
s32 func_801CE430(s32, s32);
u8 *func_801CB5DC(u8 *, s32 *, s32 *, s32);
s32 func_8017F660(s32);
extern u32 func_801CE2F0(void);
s32 func_801C7560(u8 *, s32, s32);
/* Queue the previous PCM buffer, synthesize the next audio task, and submit it to the scheduler. */
s32 func_801C3198(s32 frameAddress, s32 previousFrameAddress)
{
  s32 physicalPcmAddress;
  s32 *frameWords = (s32 *) frameAddress;
  s32 commandCount;
  u8 *commandEnd;
  volatile s32 *commandBufferIndex;
  func_801C35F0();
  physicalPcmAddress = func_801C7D90(frameWords[AUDIO_FRAME_PCM_WORD]);
  if (previousFrameAddress != 0)
  {
    func_801CE430(*((s32 *) previousFrameAddress), (*((s16 *) (previousFrameAddress + AUDIO_FRAME_SAMPLE_COUNT_OFFSET))) << 2);
  }
  *((s16 *) (frameAddress + AUDIO_FRAME_SAMPLE_COUNT_OFFSET)) = (((D_802AD328 - (func_801CE2F0() >> 2)) + D_802AD364) + AUDIO_SAMPLE_ALIGNMENT) & AUDIO_FRAME_SAMPLE_ALIGN_MASK;
  if (((u32) (*((s16 *) (frameAddress + AUDIO_FRAME_SAMPLE_COUNT_OFFSET)))) < ((u32) D_802AD324))
  {
    *((s16 *) (frameAddress + AUDIO_FRAME_SAMPLE_COUNT_OFFSET)) = D_802AD324;
  }
  commandEnd = func_801CB5DC(((u8 **) D_802AB090)[D_801F4178], &commandCount, (s32 *) physicalPcmAddress, *((s16 *) (frameAddress + AUDIO_FRAME_SAMPLE_COUNT_OFFSET)));
  if (commandCount == 0)
  {
    return 0;
  }
  do
  {
  }
  while (0);
  commandBufferIndex = &D_801F4178;
  frameWords[AUDIO_FRAME_NEXT_WORD] = 0;
  frameWords[AUDIO_FRAME_COMPLETION_QUEUE_WORD] = (s32) D_802AB290;
  frameWords[AUDIO_FRAME_COMPLETION_MESSAGE_WORD] = frameAddress + AUDIO_TASK_MESSAGE_OFFSET;
  frameWords[AUDIO_FRAME_COMMAND_LIST_WORD] = ((s32 *) D_802AB090)[*commandBufferIndex];
  goto set_command_list_size;
  set_command_list_size:
  ;

  ;
  frameWords[AUDIO_FRAME_COMMAND_BYTES_WORD] = ((((s32) commandEnd) - ((s32 *) D_802AB090)[*(&D_801F4178)]) >> 3) << 3;
  frameWords[AUDIO_FRAME_TASK_TYPE_WORD] = AUDIO_FRAME_RSP_TASK_TYPE;
  frameWords[AUDIO_FRAME_BOOT_CODE_WORD] = (s32) D_8011C720;
  frameWords[AUDIO_FRAME_BOOT_CODE_SIZE_WORD] = ((s32) func_8011C7F0) - ((s32) D_8011C720);
  frameWords[AUDIO_FRAME_TASK_FLAGS_WORD] = 0;
  frameWords[AUDIO_FRAME_UCODE_WORD] = (s32) D_801BE9E0;
  frameWords[AUDIO_FRAME_UCODE_DATA_WORD] = (s32) D_801F3E00;
  frameWords[AUDIO_FRAME_UCODE_DATA_SIZE_WORD] = AUDIO_FRAME_UCODE_DATA_BYTES;
  frameWords[AUDIO_FRAME_DRAM_STACK_WORD] = 0;
  frameWords[AUDIO_FRAME_DRAM_STACK_SIZE_WORD] = 0;
  frameWords[AUDIO_FRAME_OUTPUT_BUFFER_WORD] = 0;
  frameWords[AUDIO_FRAME_OUTPUT_BUFFER_SIZE_WORD] = 0;
  frameWords[AUDIO_FRAME_YIELD_BUFFER_WORD] = 0;
  frameWords[AUDIO_FRAME_YIELD_BYTES_WORD] = 0;
  func_801C7560((u8 *) func_8017F660((s32) D_802AD350), frameAddress + AUDIO_FRAME_SCHEDULER_OFFSET, AUDIO_FRAME_SEND_BLOCKING);
  *(&D_801F4178) ^= 1;
  return 1;
}

extern s32 D_801F4184;
extern u32 func_801CE2F0(void);
/* Audio idle check: if the AI DMA buffer has drained (func_801CE2F0 reads
 * AI_LEN_REG, in bytes; >> 2 gives stereo 16-bit frames), clear the flag
 * D_801F4184 if it is already clear (a no-op left in the original). */
void func_801C3364(s32 unused) {
    extern s32 D_801F4184;
    extern u32 func_801CE2F0(void);
    u32 aiLength;
    aiLength = func_801CE2F0();
    if ((aiLength >> 2) != 0) {
        return;
    } else {
        s32 *flag = &D_801F4184;
        if (*flag == 0) {
            *flag = 0;
        }
    }
}

/*
 * Sample DMA callback (libultra's __amDma, handed out by func_801C35B8):
 * returns the physical address of `length` bytes at ROM address `devAddr`.
 * A buffer in the in-use list (D_802AD318.next, sorted by address) that
 * already holds the range is reused; otherwise a free buffer
 * (D_802AD318.prev) is linked in and filled with osEPiStartDma
 * (func_801D08B0). Addresses 0xFFxxxxxx come from the drive handle
 * (D_802AD36C) at offset 0x140000, others from the cartridge (D_802AD368).
 * D_802AD360: buffer size; D_801F4170: audio frame counter;
 * D_801F4174: DMAs issued this frame; D_802AD358: their I/O messages;
 * D_802AD338: completion queue. func_801C7D90 = osVirtualToPhysical,
 * func_801CB20C/func_801CB1EC = alUnlink/alLink.
 */
s32 func_801C33A4(s32 devAddr, s32 length, void *state) {
#define DMA_STATE (*(QueueHead *)D_802AD318)
    typedef struct { s32 next; s32 prev; u32 startAddr; u32 lastFrame; s32 ptr; } DmaBuf;
    s32 buffer;
    s32 oddByte;
    s32 addrEnd;
    s32 buffEnd;
    DmaBuf *dmaPtr;
    DmaBuf *lastDmaPtr;
    s32 piHandle;
    PiIoMessage *ioMesg;
    DmaBuf *head;

    if ((devAddr & 0xFF000000) == 0xFF000000) {
        piHandle = D_802AD36C;
        devAddr = (devAddr & 0xFFFFFF) + 0x140000;
    } else {
        if ((D_802AB070 & 1) != 0) {
            return func_801C7D90(devAddr);
        }
        piHandle = D_802AD368;
    }

    lastDmaPtr = NULL;
    /* Two separate reads of the list head (different lvalue types, so IDO
     * does not merge them before register assignment): required to match. */
    dmaPtr = *(DmaBuf **)&DMA_STATE.next;
    head = (DmaBuf *)DMA_STATE.next;
    addrEnd = devAddr + length;
    while (dmaPtr != NULL) {
        buffEnd = dmaPtr->startAddr + D_802AD360;
        if (dmaPtr->startAddr > devAddr) {
            break;
        } else if (addrEnd <= buffEnd) {
            dmaPtr->lastFrame = D_801F4170;
            buffer = dmaPtr->ptr + devAddr - dmaPtr->startAddr;
            return func_801C7D90(buffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (DmaBuf *)dmaPtr->next;
    }

    dmaPtr = (DmaBuf *)DMA_STATE.prev;
    if (dmaPtr == NULL) {
        return func_801C7D90((s32)head);
    }

    DMA_STATE.prev = dmaPtr->next;
    func_801CB20C((ObjectNode *)dmaPtr);
    if (lastDmaPtr != NULL) {
        func_801CB1EC((ObjectNode *)dmaPtr, (ObjectNode *)lastDmaPtr);
    } else if (DMA_STATE.next != 0) {
        lastDmaPtr = (DmaBuf *)DMA_STATE.next;
        DMA_STATE.next = (s32)dmaPtr;
        dmaPtr->next = (s32)lastDmaPtr;
        dmaPtr->prev = 0;
        lastDmaPtr->prev = (s32)dmaPtr;
    } else {
        DMA_STATE.next = (s32)dmaPtr;
        dmaPtr->next = 0;
        dmaPtr->prev = 0;
    }

    buffer = dmaPtr->ptr;
    oddByte = devAddr & 1;
    devAddr -= oddByte;
    dmaPtr->startAddr = devAddr;
    dmaPtr->lastFrame = D_801F4170;
    ioMesg = &((PiIoMessage *)D_802AD358)[(*(s32 *)&D_801F4174)++];
    ioMesg->priority = 0; /* OS_MESG_PRI_NORMAL */
    ioMesg->returnQueue = D_802AD338;
    ioMesg->devAddr = devAddr;
    ioMesg->dramAddr = (void *)buffer;
    ioMesg->size = D_802AD360;
    func_801D08B0(piHandle, (u8 *)ioMesg, OS_READ);
    return func_801C7D90(buffer) + oddByte;
#undef DMA_STATE
}

/* mus_dma_new: the ALDMANew callback for the synthesizer. Initialises the
 * DMA buffer state once (no buffers in use, all on the free list starting at
 * D_802AD354), hands it back through *statePtr and returns the DMA callback
 * (func_801C33A4). */
s32 func_801C35B8(u32 *statePtr) {
    typedef struct {
        u8 initialized;
        u8 pad[3];
        s32 firstUsed;
        s32 firstFree;
    } DmaState;
#define DMA_STATE (*(DmaState *)&D_802AD318)

    if (DMA_STATE.initialized == 0) {
        DMA_STATE.firstUsed = 0;
        DMA_STATE.firstFree = D_802AD354;
        DMA_STATE.initialized = 1;
    }
    *statePtr = (u32)&DMA_STATE;
    return (s32)func_801C33A4;
#undef DMA_STATE
}

/*
 * Audio DMA bookkeeping, once per audio frame (libultra's _clearAudioDMA):
 * drain one completion message per DMA issued this frame from the DMA queue
 * (D_802AD338, osRecvMesg = func_801C7430), then move every buffer not used
 * in the last frame from the in-use list (D_802AD318.next) to the free list
 * (D_802AD318.prev) with alUnlink/alLink (func_801CB20C/func_801CB1EC).
 * D_801F4174 counts this frame's DMAs; D_801F4170 is the audio frame counter.
 */
void func_801C35F0(void) {
#define DMA_STATE (*(QueueHead *)D_802AD318)
    typedef struct { u32 next; u32 prev; u32 startAddr; u32 lastFrame; s32 ptr; } DmaBuf;
    u32 i;
    s32 msg;
    DmaBuf *dmaPtr;
    DmaBuf *nextPtr;
    s32 *freeList;
    for (i = 0; i < D_801F4174; i++) {
        func_801C7430(D_802AD338, &msg, 0);
    }
    dmaPtr = (DmaBuf *)DMA_STATE.next;
    while (dmaPtr != NULL) {
        nextPtr = (DmaBuf *)dmaPtr->next;
        if (dmaPtr->lastFrame + 1 < D_801F4170) {
            if (DMA_STATE.next == (s32)dmaPtr) {
                DMA_STATE.next = dmaPtr->next;
            }
            func_801CB20C((ObjectNode *)dmaPtr);
            freeList = (s32 *)DMA_STATE.prev;
            if (freeList != 0) {
                func_801CB1EC((ObjectNode *)dmaPtr, freeList);
            } else {
                DMA_STATE.prev = (s32)dmaPtr;
                dmaPtr->next = 0;
                dmaPtr->prev = 0;
            }
        }
        dmaPtr = nextPtr;
    }
    D_801F4174 = 0;
    D_801F4170++;
#undef DMA_STATE
}

/* Original compiler padding (alignment between the original source files). */
GLOBAL_ASM(
.text
glabel text_padding_2
.word 0, 0
)

void func_801C3758(s32 *arg0, s32 *arg1);
void func_801C3F18(u8 *arg0);
/* libmus alInit: the first call installs `globals` as the active synthesizer
 * driver (D_801F46D0), selects the custom effect preset in the config
 * (func_801C3F18) and builds the synthesizer (func_801C3758, alSynNew).
 * Later calls do nothing. `config` is an AudioSynthConfig. */
void func_801C3710(void *globals, void *config)
{
    if (D_801F46D0 == NULL) {
        D_801F46D0 = globals;
        func_801C3F18(config);
        func_801C3758(D_801F46D0, config);
    }
}

/* Build the audio filter chain, physical-voice free list, and timed-update pool. */
void func_801C3758(s32 *synth, s32 *config) {
    s32 index;
    s32 *unusedEventListItem;
    s32 *unusedClient;
    u32 *heap = (u32 *)config[SYNTH_CONFIG_HEAP];
    AudioPhysicalVoice *voices;
    AudioPhysicalVoice *voice;
    s32 outputFilter;
    s32 *update;
    s32 *unusedMainBus;
    synth[SYNTH_CLIENT_HEAD] = 0;
    synth[SYNTH_MAX_PHYSICAL_VOICES] = config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES];
    synth[SYNTH_CURRENT_SAMPLES] = 0;
    synth[SYNTH_PARAM_SAMPLES] = 0;
    synth[SYNTH_OUTPUT_RATE] = config[SYNTH_CONFIG_OUTPUT_RATE];
    synth[SYNTH_MAX_OUTPUT_SAMPLES] = SYNTH_FRAME_SAMPLES;
    synth[SYNTH_DMA_FACTORY] = config[SYNTH_CONFIG_DMA_FACTORY];
    outputFilter = func_801CB280(0, 0, heap, 1, SYNTH_OUTPUT_FILTER_BYTES);
    func_801C8698(outputFilter);
    synth[SYNTH_OUTPUT_FILTER] = outputFilter;
    synth[SYNTH_AUX_BUS] = func_801CB280(0, 0, heap, 1, SYNTH_AUX_BUS_BYTES);
    synth[SYNTH_AUX_BUS_COUNT] = 1;
    func_801C85E0(synth[SYNTH_AUX_BUS], func_801CB280(0, 0, heap, config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES], SYNTH_SOURCE_POINTER_BYTES), config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES]);
    synth[SYNTH_MAIN_BUS] = func_801CB280(0, 0, heap, 1, SYNTH_MAIN_BUS_BYTES);
    func_801C863C(synth[SYNTH_MAIN_BUS], func_801CB280(0, 0, heap, config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES], SYNTH_SOURCE_POINTER_BYTES), config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES]);
    if (*(u8 *)((u8 *)config + SYNTH_CONFIG_EFFECT_TYPE_OFFSET) != 0) {
        func_801C3A58(synth, 0, config, heap);
    } else {
        func_801CA1A0((s32 *)synth[SYNTH_MAIN_BUS], SYNTH_BUS_ADD_SOURCE, synth[SYNTH_AUX_BUS]);
    }
    synth[SYNTH_FREE_VOICE_NEXT] = 0;
    synth[SYNTH_FREE_VOICE_PREV] = 0;
    synth[SYNTH_LAME_VOICE_NEXT] = 0;
    synth[SYNTH_LAME_VOICE_PREV] = 0;
    synth[SYNTH_ALLOCATED_VOICE_NEXT] = 0;
    synth[SYNTH_ALLOCATED_VOICE_PREV] = 0;
    voices = (AudioPhysicalVoice *)func_801CB280(0, 0, heap, config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES], SYNTH_PHYSICAL_VOICE_BYTES);
    for (index = 0; index < config[SYNTH_CONFIG_MAX_PHYSICAL_VOICES]; index++) {
        voice = &voices[index];
        func_801CB1EC((ObjectNode *)voice, &synth[SYNTH_FREE_VOICE_NEXT]);
        voice->virtualVoice = 0;
        func_801C84A4(voice->decoder, (void *)synth[SYNTH_DMA_FACTORY], heap);
        func_801C8EC0(voice->decoder, SYNTH_FILTER_SET_SOURCE, 0);
        func_801C8554(voice->resampler, heap);
        func_801CA3BC(voice->resampler, SYNTH_FILTER_SET_SOURCE, voice->decoder);
        func_801C83EC(voice->envelopeMixer, heap);
        func_801C984C(voice->envelopeMixer, SYNTH_FILTER_SET_SOURCE, voice->resampler);
        func_801C92CC((s32 *)synth[SYNTH_AUX_BUS], SYNTH_BUS_ADD_SOURCE, (s32)voice->envelopeMixer);
        voice->channelKnob = (s32)voice->envelopeMixer;
    }
    index = 0;
    func_801CB160((s32 *)outputFilter, SYNTH_FILTER_SET_SOURCE, synth[SYNTH_MAIN_BUS]);
    update = (s32 *)func_801CB280(0, 0, heap, config[SYNTH_CONFIG_MAX_UPDATES], SYNTH_PARAM_RECORD_BYTES);
    synth[SYNTH_PARAM_FREE_LIST] = 0;
    if (config[SYNTH_CONFIG_MAX_UPDATES] > 0) {
        do {
            *update = synth[SYNTH_PARAM_FREE_LIST];
            synth[SYNTH_PARAM_FREE_LIST] = (s32)update;
            index++;
            update = (s32 *)((u8 *)update + SYNTH_PARAM_RECORD_BYTES);
        } while (index < config[SYNTH_CONFIG_MAX_UPDATES]);
    }
    synth[SYNTH_HEAP] = (s32)heap;
}

s32 func_801C3AFC(s32 *arg0, s32 *arg1, s32 arg2);
/* alSynAllocFX: create the effect on aux bus `bus` (its effect sits 0x20 into
 * the 76-byte bus), make the bus its source and add it to the main bus.
 * Returns the effect. */
s32 func_801C3A58(synth, bus, config, heap)
s32 *synth;
s16 bus;
s32 config;
s32 heap;
{
    s32 busOffset;
    u8 *auxBus;
    *(s32 **)&D_802AD370 = synth;
    busOffset = bus * SYNTH_AUX_BUS_BYTES;
    func_801C3AFC((s32 *)((u8 *)synth[SYNTH_AUX_BUS] + busOffset + AUDIO_FX_AUX_BUS_EFFECT_OFFSET), (s32 *)config, heap);
    auxBus = (u8 *)synth[SYNTH_AUX_BUS] + busOffset;
    func_801CA830((s32 *)(auxBus + AUDIO_FX_AUX_BUS_EFFECT_OFFSET), SYNTH_FILTER_SET_SOURCE, (s32)auxBus);
    func_801CA1A0((s32 *)synth[SYNTH_MAIN_BUS], SYNTH_BUS_ADD_SOURCE, synth[SYNTH_AUX_BUS] + busOffset + AUDIO_FX_AUX_BUS_EFFECT_OFFSET);
    return synth[SYNTH_AUX_BUS] + busOffset + AUDIO_FX_AUX_BUS_EFFECT_OFFSET;
}

s32 func_801C3F30(void);
s32 func_801C3F78(void);
void func_801C3C34(s32 *arg0);
extern void func_801CA480();
/* mus_effect_new: allocate reusable effect storage, install callbacks, and apply the configured preset. */
s32 func_801C3AFC(s32 *effect, s32 *config, s32 heap) {
    func_801CA040(effect, 0, (s32)func_801CA830, AUDIO_FILTER_EFFECT);
    effect[AUDIO_FX_PULL_HANDLER_WORD] = (s32)func_801CA480;
    effect[AUDIO_FX_PARAMETER_HANDLER_WORD] = (s32)func_801CA844;
    (*(AudioEffectStorage *)&D_802AD370).delaySections = func_801CB280(0, 0, heap, func_801C3F30(), AUDIO_FX_DELAY_SECTION_BYTES);
    (*(AudioEffectStorage *)&D_802AD370).delayBuffer = func_801CB280(0, 0, heap, func_801C3F78(), AUDIO_FX_DELAY_SAMPLE_BYTES);
    (*(AudioEffectStorage *)&D_802AD370).resampler = (AudioEffectResampler *)func_801CB280(0, 0, heap, 1, AUDIO_FX_RESAMPLER_BYTES);
    (*(AudioEffectStorage *)&D_802AD370).resamplerState = func_801CB280(0, 0, heap, 1, AUDIO_FX_RESAMPLE_STATE_BYTES);
    (*(AudioEffectStorage *)&D_802AD370).lowPass = (AudioEffectLowPass *)func_801CB280(0, 0, heap, 1, AUDIO_FX_LOW_PASS_BYTES);
    (*(AudioEffectStorage *)&D_802AD370).lowPassState = func_801CB280(0, 0, heap, 1, AUDIO_FX_LOW_PASS_STATE_BYTES);
    func_801C3C34((s32 *)config[AUDIO_FX_CONFIG_PRESET_WORD]);
}

/* Apply a packed effect preset, clear its delay buffer, and initialize modulation and filtering. */
void func_801C3C34(s32 *preset) {
    AudioEffect *effect;
    u16 index, word;
    AudioEffectDelay *delay;

    word = 0;
    effect = (AudioEffect *)(*(u8 **)((u8 *)(*(AudioEffectStorage *)&D_802AD370).synth + AUDIO_FX_SYNTH_AUX_BUS_OFFSET) + AUDIO_FX_AUX_BUS_EFFECT_OFFSET);
    effect->sectionCount = preset[word++];
    effect->length = preset[word++];
    effect->delay = (AudioEffectDelay *)(*(AudioEffectStorage *)&D_802AD370).delaySections;
    effect->base = (s16 *)(*(AudioEffectStorage *)&D_802AD370).delayBuffer;
    effect->input = effect->base;

    for (index = 0; index < effect->length; index++) {
        effect->base[index] = 0;
    }

    for (index = 0; index < effect->sectionCount; index++) {
        delay = &effect->delay[index];
        delay->input = preset[word++];
        delay->output = preset[word++];
        delay->feedback = preset[word++];
        delay->feedforward = preset[word++];
        delay->gain = preset[word++];
        if (preset[word]) {
            delay->modulationIncrement = ((((f32)preset[word++]) / AUDIO_FX_RATE_SCALE) * 2.0) / *(s32 *)((u8 *)(*(AudioEffectStorage *)&D_802AD370).synth + AUDIO_FX_SYNTH_OUTPUT_RATE_OFFSET);
            delay->modulationGain = (((f32)preset[word++]) / 173123.404906676) * (delay->output - delay->input);
            delay->modulationValue = 1.0f;
            delay->resampleDelta = 0;
            delay->resampler = (*(AudioEffectStorage *)&D_802AD370).resampler;
            *(s32 *)((u8 *)delay->resampler + AUDIO_FX_RESAMPLER_STATE_OFFSET) = (*(AudioEffectStorage *)&D_802AD370).resamplerState;
            *(f32 *)((u8 *)delay->resampler + AUDIO_FX_RESAMPLER_DELTA_OFFSET) = 0.0f;
            *(s32 *)((u8 *)delay->resampler + AUDIO_FX_RESAMPLER_FIRST_OFFSET) = 1;
        } else {
            delay->resampler = 0;
            word++;
            word++;
        }
        if (preset[word]) {
            delay->lowPass = (*(AudioEffectStorage *)&D_802AD370).lowPass;
            *(s32 *)((u8 *)delay->lowPass + AUDIO_FX_LOW_PASS_STATE_OFFSET) = (*(AudioEffectStorage *)&D_802AD370).lowPassState;
            *(s16 *)delay->lowPass = preset[word++];
            func_801C7EB0((s16 *)delay->lowPass);
        } else {
            delay->lowPass = 0;
            word++;
        }
    }
}

extern u8 D_801F41F8[];
/* Select the game's custom reverb: set the synth config's effect type to
 * AUDIO_FX_CUSTOM and point its effect parameters at the preset D_801F41F8. */
void func_801C3F18(u8 *config)
{
    extern u8 D_801F41F8[];
    u8 *customParams = D_801F41F8;
    s32 effectType = AUDIO_FX_CUSTOM;

    do {
        *(u8 *)(config + SYNTH_CONFIG_EFFECT_TYPE_OFFSET) = effectType;
        if (0) { effectType = 0; }
    } while (0);
    *(u8 **)(config + SYNTH_CONFIG_EFFECT_PARAMS_OFFSET) = customParams;
}

extern s32 *D_801F4384[];
/* Returns the largest first word among the records listed in the
 * NULL-terminated pointer table D_801F4384 (0 if the table is empty or
 * every value is negative). */
s32 func_801C3F30(void)
{
    extern s32 *D_801F4384[];
    s32 maxValue = 0;
    s32 i;
    s32 *entry;
    s32 value;
    for (i = 0; D_801F4384[i] != NULL; i++) {
        entry = D_801F4384[i];
        value = *entry;
        if (maxValue < value) {
            maxValue = value;
        }
    }
    return maxValue;
}

/* Returns the largest delay-buffer length (in samples) among the built-in
 * effect presets in the NULL-terminated table D_801F4384, so one buffer
 * fits every preset (0 if the table is empty). */
s32 func_801C3F78(void)
{
    extern s32 *D_801F4384[]; /* effect preset table */
    s32 maxLength = 0;
    s32 i;
    s32 *preset;
    s32 length;
    for (i = 0; D_801F4384[i] != NULL; i++) {
        preset = D_801F4384[i];
        length = preset[AUDIO_FX_PRESET_LENGTH_WORD];
        if (maxLength < length) {
            maxLength = length;
        }
    }
    return maxLength;
}

extern s32 D_801F4380;
/* Switches the auxiliary effect to built-in preset `presetIndex` (small room,
 * big room, echo, ...) and reconnects it to the aux bus. Returns 1 if the
 * index is out of range, 0 on success. */
s32 func_801C3FC0(s32 presetIndex)
{
    extern s32 *D_801F4384[]; /* effect preset table */
    extern s32 D_801F4380;    /* number of effect presets */
    s32 *auxBus;
    if (presetIndex >= D_801F4380) {
        return 1;
    }
    func_801C3C34(D_801F4384[presetIndex]);
    auxBus = *(s32 **)((u8 *)D_802AD370 + AUDIO_FX_SYNTH_AUX_BUS_OFFSET);
    func_801CA830((s32 *)((u8 *)auxBus + AUDIO_FX_AUX_BUS_EFFECT_OFFSET), SYNTH_FILTER_SET_SOURCE, (s32)auxBus);
    return 0;
}



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

extern f64 D_8010C280;
extern f64 D_8010C288;


extern f64 D_8010C2A0;
extern f64 D_8010C2A8;
extern f64 D_8010C2B0;
extern f64 D_8010C2B8;
extern f64 D_8010C2C0;


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





/* Original compiler padding. */
extern u8 D_801F43F0[];

void func_801C6FB0(QNode *arg0) __attribute__((noreturn));

typedef struct { OSMesgQueue *unk0; s32 unk4; } Unk802AD560;
extern Unk802AD560 D_802AD560[];


extern u8 D_802AE8C0[];
extern u8 D_802AE8E0[];
extern u8 D_802AE8F8[];
s32 func_801CFC50(void *, s32, void *);


extern s32 D_802AD5E4;





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


extern const f64 D_8010C5E0;






s32 func_801CB864(u8 *arg0, s32 arg1);
s32 func_801CB8F8(s32 *arg0, s32 **arg1);
void func_801CB7D0(ObjectNode *arg0);







extern f64 D_8010C620;
extern f64 D_8010C628;

extern f64 D_8010C630;
extern f64 D_8010C638;



s32 func_801CBC60(u8 *, u8 *, s32);

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
    _g->w1 = SP_SHIFTL(SP_MIN(lrs, 0x7FF), 12, 12) | SP_SHIFTL(tile, 24, 3); \
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




extern u8 D_8010C660[];
extern u8 D_8010C664[];
void func_801CC118(Gfx **, SpriteText *, SpriteGlyph *, s32, s32, s32, s32, s32, s32, s32, s32);


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


extern u8 D_8010C6B0[];
extern u8 D_8010C6B4[];

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
void func_801C76F0(QNode *, s32);
void func_801D1B60(void);
void func_801D13E0();
s32 func_801D0610(s32, u32, void *, u32);
s32 func_801D06E0();

extern s32 D_802AFB6C;
extern PiHandleY D_802AFB60;
extern u8 D_802AFB64;
extern u8 D_802AFB65;
extern u8 D_802AFB66;
extern u8 D_802AFB67;
extern u8 D_802AFB68;
extern u8 D_802AFB69;
extern s32 D_802AFB70;
extern s32 func_801D0A90(void);
s32 func_801C7560(u8 *, s32, s32);

void func_801D17A0(s32);
void func_801D17F0(s32);
void func_801D1830(void);
s32 func_801D1880(u8 *, u32, u32 *);
s32 func_801D1A10(u8 *, u32, u32);

extern u8 D_8010C710[];
extern u8 D_8010C714[];



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



/* Original compiler padding. */
void func_801D3B40(s32, s32, s32, s32);
extern u8 D_801F5650[];
extern u8 D_801F5664[];
LongLongDiv func_801D2EE4(s64, s64);

u64 func_801D41A0(u64, u64);

s64 func_801D3AA0(s64, s64);


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

