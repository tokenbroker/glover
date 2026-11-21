#include "common.h"
#include "structs.h"

/* RSP status register (libultra SP_STATUS_REG) write bits. */
#define SP_CLR_HALT       0x0001
#define SP_CLR_BROKE      0x0004
#define SP_CLR_SSTEP      0x0020
#define SP_SET_INTR_BREAK 0x0100
#define SP_SET_SIG0       0x0400
#define SP_SET_YIELD      SP_SET_SIG0 /* signal 0 asks the running task to yield */

/* RSP status register address (KSEG1) and its read bits. */
#define SP_STATUS_REG      0xA4040010
#define SP_STATUS_DMA_BUSY 0x0004
#define SP_STATUS_DMA_FULL 0x0008
#define SP_STATUS_IO_FULL  0x0010

extern s32 D_801F54B0;
u32 func_801CE900(void);
void func_801CF0C0(void);
void func_801CF654(void);
void func_801CF890(void);
extern u8 D_802AE8A0[];
extern u8 D_802AE890[];

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
extern Unk801F4764 D_801F4700[];
extern u8 D_801F5520[];
extern u8 D_801F5570[];
extern u8 D_801F54D0[];

extern Unk801F4764 *D_801F4764;

s32 func_801C6F70();

u32 *func_801CAC4C(s32 *, s32, s32, s32, u32 *);
f32 func_801CAFC8(u8 *, s32);

extern u32 D_80000300;
s32 func_801D03E0(s32 arg0, s32 *arg1);
void func_801C6F90(s32);
s32 func_801C62B0();
extern s32 D_802AD5E0;
extern u64 D_802AD5E8;
extern u8 D_8010C6A0[];
extern u8 D_8010C6A4[];
extern u8 D_8010C640[];
extern u8 D_8010C644[];
extern u8 D_8010C610[];
extern u8 D_8010C5B0[];
extern u8 D_8010C5B4[];
u32 *func_801CADBC(s32 *, s32, s32, s32, u32 *);
u8 *func_801CAF2C(u8 *, u32, u32, u8 *);
u32 *func_801CAA34(s32 *, AudioEffectDelay *, s32, s32, u32 *);
extern u8 D_8010C614[];
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
typedef struct QNode {
    u8 pad0[4];
    s32 unk4;
    ObjectNode *unk8;
    struct QNode *unkC;
    u16 unk10;
} QNode;
extern QNode *D_801F43F8;
extern u8 *D_802AFC54;
extern s32 D_801F43E0;
void func_801D126C();
void func_801D119C(void);
#define LEO_WAIT_ON_IOBUSY(stat) \
    stat = *(volatile u32 *)0xA4600010; \
    while (stat & 3) \
        stat = *(volatile u32 *)0xA4600010;
#define LEO_IO_READ(addr) (*(volatile u32 *)(addr))
#define LEO_IO_WRITE(addr, data) (*(volatile u32 *)(addr) = (data))
extern OSMesgQueue *D_802AD5A0;
extern void *D_802AD5A4;
void func_801C6D8C(ObjectNode *, QNode *);

typedef struct {
    s32 quot;
    s32 rem;
} LongDiv;

typedef struct {
    s64 quot;
    s64 rem;
} LongLongDiv;

extern EnvRateLogTable D_8010C4F0;
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
extern s32 D_801F43D8;
extern f64 D_8010C4D8;
extern f64 D_8010C4E0;
extern f64 D_8010C4E8;

extern s32 D_802AE98C;
extern u8 D_802AE950[];
extern u8 D_802AE940;
extern u8 D_802AE900[];
extern u8 D_802AE8FC;
extern s32 D_802AE93C;
extern s32 D_802AE938;
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
s32 func_801CF710(s32, void *);
s32 func_801C7430(void *, void *, s32);
s32 func_801CB280(s32, s32, u32 *, s32, s32);
void func_801CA040(s32 *, s32, s32, s32);
u32 *func_801C86E0();
u32 *func_801C8B24();
void func_801C8EC0();
u32 *func_801C9300();
s32 func_801CB8AC();
s32 func_801C984C();

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



#include "audio_envelope.h"
#include "audio_synth.h"

extern u8 D_8010C480[];
extern u8 D_8010C484[];
extern s16 D_801F45B0[];
u32 *func_801C9920();
f32 func_801C9FA4(f32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801CA030(u8 *arg0, u8 *arg1, s32 arg2);

extern ObjectNode *D_801F46D0;
extern u8 D_801F46F0;
extern u8 *D_801F55E0[];
extern u8 D_8010C680[];
extern u8 D_8010C684[];
u32 func_801C7D90(u32);
s32 func_801CE730(void);
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

/* libultra OS routines defined in other units. */
void func_801C6550(Thread801 *, s32, u32, s32, void *, s32);
void func_801C7860(QNode *);
void func_801C6520(OSMesgQueue *queue, void **msg, s32 count);
ObjectNode *func_801C6DD4(ObjectNode *arg0);
u64 func_801C7080(void);
s32 func_801C7560(u8 *arg0, s32 arg1, s32 flags);
void func_801C76F0(QNode *arg0, s32 arg1);
s32 func_801C77C0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4, volatile s32 arg6, volatile s32 arg7);
void func_801C7A80(void);
void func_801C7AD4(void);
void func_801CC0D0(u16 *sprite, u16 attr);
void func_801CFA5C(u8 *pattern, u8 *status);
void func_801CFB10(u8 command);
void func_801CFDD8(u8 blockAddress, u8 *data);
void func_801D01C4(u8 blockAddress);
extern u8 D_802AE8C0[];
extern u8 D_802AE8E0[];
extern u8 D_802AE8F8[];
extern s32 D_802AD5E4;

/* _init_lpfilter (libultra audio): derive a low-pass filter's gain and its
 * 16 coefficients from its cutoff fc. The first 8 coefficients are zero, the
 * rest are successive powers of fc / 16384 (D_8010C440) in Q14. */
void func_801C7EB0(s16 *filter) {
    extern f64 D_8010C440;
    typedef struct {
        s16 fc;
        s16 fgain;
        union {
            s16 fccoef[16];
            s64 force_aligned;
        } fcvec;
        void *fstate;
        s32 first;
    } LowPassFilter;
    LowPassFilter *lp = (LowPassFilter *)filter;
    s32 i, temp;
    s16 fc;
    f64 ffc, fcoef;

    temp = lp->fc * 16384;
    fc = temp >> 15;
    lp->fgain = 16384 - fc;

    lp->first = 1;
    for (i = 0; i < 8; i++)
        lp->fcvec.fccoef[i] = 0;

    lp->fcvec.fccoef[i++] = fc;
    fcoef = ffc = (f64)fc / D_8010C440;

    for (; i < 16; i++) {
        fcoef *= ffc;
        lp->fcvec.fccoef[i] = (s16)(fcoef * D_8010C440);
    }
}

/* Initialize an audio effect's delay buffer and optional modulation and low-pass filters. */
void func_801C7F54(u8 *effectMemory, u8 *configMemory, s32 heapAddress) {
    extern s32 D_801F4420[];
    extern s32 D_801F4488[];
    extern s32 D_801F4510[];
    extern s32 D_801F4538[];
    extern s32 D_801F4560[];
    extern s32 D_801F4588[];
    extern f64 D_8010C460;
    extern f64 D_8010C468;
    extern u32 *func_801CA480(s32 *, s32, s32, s32, u32 *);
    u16 sectionIndex, paramIndex, sampleIndex;
    s32 *parameters = 0;
    AudioEffectFilter *filter = (AudioEffectFilter *)((AudioEffect *)effectMemory);
    AudioEffectDelay *delay;

    func_801CA040((s32 *)filter, 0, (s32)func_801CA830, AUDIO_FILTER_EFFECT);
    filter->handler = (void *)func_801CA480;
    ((AudioEffect *)effectMemory)->parameterHandler = (void *)func_801CA844;

    switch (((AudioEffectConfig *)configMemory)->fxType) {
    case AUDIO_FX_SMALL_ROOM: parameters = D_801F4420; break;
    case AUDIO_FX_BIG_ROOM: parameters = D_801F4488; break;
    case AUDIO_FX_ECHO: parameters = D_801F4510; break;
    case AUDIO_FX_CHORUS: parameters = D_801F4538; break;
    case AUDIO_FX_FLANGE: parameters = D_801F4560; break;
    case AUDIO_FX_CUSTOM: parameters = ((AudioEffectConfig *)configMemory)->params; break;
    default: parameters = D_801F4588; break;
    }

    paramIndex = 0;

    ((AudioEffect *)effectMemory)->sectionCount = parameters[paramIndex++];
    ((AudioEffect *)effectMemory)->length = parameters[paramIndex++];

    ((AudioEffect *)effectMemory)->delay = (AudioEffectDelay *)func_801CB280(0, 0, ((u32 *)heapAddress), ((AudioEffect *)effectMemory)->sectionCount, sizeof(AudioEffectDelay));
    ((AudioEffect *)effectMemory)->base = (s16 *)func_801CB280(0, 0, ((u32 *)heapAddress), ((AudioEffect *)effectMemory)->length, sizeof(s16));
    ((AudioEffect *)effectMemory)->input = ((AudioEffect *)effectMemory)->base;

    for (sampleIndex = 0; sampleIndex < ((AudioEffect *)effectMemory)->length; sampleIndex++)
        ((AudioEffect *)effectMemory)->base[sampleIndex] = 0;

    for (sectionIndex = 0; sectionIndex < ((AudioEffect *)effectMemory)->sectionCount; sectionIndex++) {
        delay = &((AudioEffect *)effectMemory)->delay[sectionIndex];
        delay->input = parameters[paramIndex++];
        delay->output = parameters[paramIndex++];
        delay->feedback = parameters[paramIndex++];
        delay->feedforward = parameters[paramIndex++];
        delay->gain = parameters[paramIndex++];

        if (parameters[paramIndex]) {
            delay->modulationIncrement = ((((f32)parameters[paramIndex++]) / AUDIO_FX_RATE_SCALE) * 2.0) / ((AudioEffectConfig *)configMemory)->outputRate;
            delay->modulationGain = (((f32)parameters[paramIndex++]) / D_8010C468) * (delay->output - delay->input);
            delay->modulationValue = 1.0;
            delay->resampleDelta = 0.0;
            delay->resampler = (AudioEffectResampler *)func_801CB280(0, 0, ((u32 *)heapAddress), 1, sizeof(AudioEffectResampler));
            delay->resampler->state = (void *)func_801CB280(0, 0, ((u32 *)heapAddress), 1, AUDIO_FX_RESAMPLE_STATE_BYTES);
            delay->resampler->delta = 0.0;
            delay->resampler->first = 1;
        } else {
            delay->resampler = 0;
            paramIndex++;
            paramIndex++;
        }

        if (parameters[paramIndex]) {
            delay->lowPass = (AudioEffectLowPass *)func_801CB280(0, 0, ((u32 *)heapAddress), 1, sizeof(AudioEffectLowPass));
            delay->lowPass->state = (void *)func_801CB280(0, 0, ((u32 *)heapAddress), 1, AUDIO_FX_LOW_PASS_STATE_BYTES);
            delay->lowPass->cutoff = parameters[paramIndex++];
            {
                AudioEffectLowPass *lowPass = delay->lowPass;
                s32 coefficientIndex, scaledCutoff;
                s16 cutoff;
                f64 normalizedCutoff, coefficient;

                scaledCutoff = lowPass->cutoff * AUDIO_FX_COEFFICIENT_ONE;
                cutoff = scaledCutoff >> AUDIO_FX_CUTOFF_SHIFT;
                lowPass->gain = AUDIO_FX_COEFFICIENT_ONE - cutoff;

                lowPass->first = 1;
                for (coefficientIndex = 0; coefficientIndex < AUDIO_FX_LOW_PASS_HISTORY_COUNT; coefficientIndex++)
                    lowPass->coefficients.values[coefficientIndex] = 0;

                lowPass->coefficients.values[coefficientIndex++] = cutoff;
                coefficient = normalizedCutoff = (f64)cutoff / AUDIO_FX_COEFFICIENT_ONE;

                for (; coefficientIndex < AUDIO_FX_LOW_PASS_COEFFICIENT_COUNT; coefficientIndex++) {
                    coefficient *= normalizedCutoff;
                    lowPass->coefficients.values[coefficientIndex] = (s16)(coefficient * AUDIO_FX_COEFFICIENT_ONE);
                }
            }
        } else {
            delay->lowPass = 0;
            paramIndex++;
        }
    }
}

/* alEnvmixerNew: set up an envelope-mixer filter with its RSP state, unit
 * gains, no pending controls, and stopped. */
void func_801C83EC(UnkC83EC *mixerData, u32 *heap) {
    EnvMixer *mixer = (EnvMixer *)mixerData;
    s32 one = 1;

    func_801CA040((s32 *)mixer, (s32)func_801C9300, (s32)func_801C984C, 4 /* AL_ENVMIX */);
    mixer->state = (void *)func_801CB280(0, 0, heap, 1, 0x50 /* sizeof(ENVMIX_STATE) */);
    mixer->first = 1;
    mixer->motion = 0;
    mixer->volume = 1;
    mixer->ltgt = 1;
    mixer->rtgt = 1;
    mixer->cvolL = 1;
    mixer->cvolR = 1;
    mixer->dryamt = 0;
    mixer->wetamt = 0;
    /* The left rate is set twice, as in libultra's env.c. */
    mixer->lratm = 1;
    mixer->lratl = 0;
    mixer->lratm = 1;
    mixer->lratl = 0;
    mixer->delta = 0;
    mixer->segEnd = 0;
    mixer->pan = 0;
    mixer->ctrlList = 0;
    mixer->ctrlTail = 0;
    mixer->sources = 0;
}

/* alLoadNew: set up an ADPCM load filter (pull = func_801C86E0, param =
 * func_801C8EC0) with its two ADPCM states and a DMA callback from dmaNew. */
void func_801C84A4(s32 *load, s32 (*dmaNew)(s32 *), u32 *heap) {
    func_801CA040(load, (s32)func_801C86E0, (s32)func_801C8EC0, 0 /* AL_ADPCM */);
    load[5] = func_801CB280(0, 0, heap, 1, 0x20 /* state: sizeof(ADPCM_STATE) */);
    load[6] = func_801CB280(0, 0, heap, 1, 0x20 /* lstate: loop ADPCM_STATE */);
    load[12] = dmaNew(load + 13); /* dma, with its dmaState */
    load[15] = 0; /* lastsam */
    load[16] = 1; /* first */
    load[17] = 0; /* memin */
}

/* libaudio alResampleNew: sets up a resampler filter (pull/param handlers
 * func_801CA1D0/func_801CA3BC), allocates its RESAMPLE_STATE from the heap
 * (alHeapAlloc) and resets it to a stopped, unity-ratio state. */
void func_801C8554(s32 *resampler, u32 *heap) {
    extern void func_801CA1D0(void);
    extern void func_801CA3BC(void);
    s32 *state;

    func_801CA040(resampler, (s32)func_801CA1D0, (s32)func_801CA3BC, AL_RESAMPLE); /* alFilterNew */
    state = (s32 *)func_801CB280(0, 0, heap, 1, 0x20); /* alHeapDBAlloc */
    resampler[RESAMPLER_STATE] = (s32)state;
    resampler[RESAMPLER_DELTA] = 0;
    resampler[RESAMPLER_FIRST] = 1;
    resampler[RESAMPLER_MOTION] = 0; /* AL_STOPPED */
    resampler[RESAMPLER_UNITY_PITCH] = 0;
    resampler[RESAMPLER_CTRL_LIST] = 0;
    resampler[RESAMPLER_CTRL_TAIL] = 0;
    *(f32 *)&resampler[RESAMPLER_RATIO] = 1.0f;
}

/* libaudio alAuxBusInit: set up an auxiliary bus filter (pull = func_801C91F0,
 * param = func_801C92CC) with an empty list of up to maxSources sources.
 * ALAuxBus has the same layout as AudioMainBus. */
void func_801C85E0(s32 *auxBus, s32 sources, s32 maxSources)
{
    extern void func_801C91F0(void);
    extern s32 func_801C92CC(s32 *, s32, s32);
    extern void func_801CA040(s32 *, s32, s32, s32);
    AudioMainBus *bus = (AudioMainBus *)auxBus;

    func_801CA040(auxBus, (s32)func_801C91F0, (s32)func_801C92CC, 6 /* AL_AUXBUS */); /* alFilterNew */
    bus->sourceCount = 0;
    bus->maxSources = maxSources;
    bus->sources = (AudioSynthFilter **)sources;
}

/* libaudio alMainBusNew: set up the main bus filter (pull = func_801CA060,
 * param = func_801CA1A0) with an empty list of up to maxSources sources. */
void func_801C863C(s32 *mainBus, s32 sources, s32 maxSources)
{
    extern u32 *func_801CA060(s32 *, s32, s32, s32, u32 *);
    AudioMainBus *bus = (AudioMainBus *)mainBus;

    func_801CA040(mainBus, (s32)func_801CA060, (s32)func_801CA1A0, AL_MAINBUS); /* alFilterNew */
    bus->sourceCount = 0;
    bus->maxSources = maxSources;
    bus->sources = (AudioSynthFilter **)sources;
}

/* alSaveNew: sets up the output save filter (pull alSavePull = func_801CB060,
 * params alSaveParam = func_801CB160) with no output buffer yet. */
void func_801C8698(s32 *save)
{
    extern void func_801CB060(void);
    extern s32 func_801CB160(s32 *, s32, s32);
    extern void func_801CA040(s32 *, s32, s32, s32);

    func_801CA040(save, (s32)func_801CB060, (s32)func_801CB160, AUDIO_FILTER_TYPE_SAVE);
    save[AUDIO_SAVE_DRAM_OUT_WORD] = 0;
    save[AUDIO_SAVE_FIRST_WORD] = 1;
}

/* Original compiler padding. */
const u32 D_801C86DC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* alAdpcmPull: decode sample blocks, wrap active loops, and silence samples past the wave end. */
u32 *func_801C86E0(void *filter, s16 *outputBuffer, s32 sampleCount, s32 sampleOffset, u32 *commands) {
    u32 *commandPtr = commands;
    s16 inputBuffer;
    long crossesLoopEnd;
    s32 segmentSamples;
    s32 frameCount;
    s32 silenceSamples;
    s32 cachedSamples;
    s32 samplesToDecode;
    s32 compressedBytes;
    s32 decodeBuffer;
    s32 outputCursor;
    s32 bytesPastEnd;
    s32 didDecode = 0;
    AudioSampleLoader *loader = (AudioSampleLoader *)filter;

    if (sampleCount == 0) {
        return commandPtr;
    }
    {
        AudioCommand *command = (AudioCommand *)commandPtr;
        commandPtr += 2;
        command->w0 = (loader->bookBytes & AUDIO_COMMAND_ADDRESS_MASK) | AUDIO_CMD_LOAD_ADPCM;
        command->w1 = ((s32)loader->wave->book + 8) & AUDIO_PHYSICAL_ADDRESS_MASK;
    }
    crossesLoopEnd = 0;
    inputBuffer = 0;
    if ((u32)loader->loopEnd < sampleCount + loader->samplePosition) {
        crossesLoopEnd = loader->loopCount != 0;
    }
    segmentSamples = sampleCount;
    if (crossesLoopEnd) {
        segmentSamples = loader->loopEnd - loader->samplePosition;
    }
    if (loader->frameOffset != 0) {
        cachedSamples = AUDIO_ADPCM_FRAME_SAMPLES - loader->frameOffset;
    } else {
        cachedSamples = 0;
    }
    samplesToDecode = segmentSamples - cachedSamples;
    if (samplesToDecode < 0) {
        samplesToDecode = 0;
    }
    frameCount = (samplesToDecode + (AUDIO_ADPCM_FRAME_SAMPLES - 1)) >> 4;
    compressedBytes = frameCount * AUDIO_ADPCM_FRAME_BYTES;
    if (crossesLoopEnd) {
        commandPtr = (u32 *)func_801C906C(commandPtr, loader, samplesToDecode, compressedBytes, *outputBuffer, inputBuffer, loader->first);
        if (loader->frameOffset != 0) {
            *outputBuffer = *outputBuffer + loader->frameOffset * 2;
        } else {
            *outputBuffer = *outputBuffer + AUDIO_ADPCM_HISTORY_BYTES;
        }
        loader->frameOffset = loader->loopStart & (AUDIO_ADPCM_FRAME_SAMPLES - 1);
        loader->sampleAddress = loader->wave->base + (((u32)loader->loopStart >> 4) + 1) * AUDIO_ADPCM_FRAME_BYTES;
        loader->samplePosition = loader->loopStart;
        outputCursor = *outputBuffer;
        while (sampleCount > segmentSamples) {
            decodeBuffer = (outputCursor + (frameCount + 1) * AUDIO_ADPCM_HISTORY_BYTES) & -AUDIO_ADPCM_HISTORY_BYTES;
            outputCursor += segmentSamples * 2;
            sampleCount -= segmentSamples;
            if ((~loader->loopCount != 0) & (loader->loopCount != 0)) {
                loader->loopCount = loader->loopCount - 1;
            }
            segmentSamples = ((u32)sampleCount < (u32)(loader->loopEnd - loader->loopStart)) ? sampleCount : loader->loopEnd - loader->loopStart;
            samplesToDecode = segmentSamples - AUDIO_ADPCM_FRAME_SAMPLES + loader->frameOffset;
            if (samplesToDecode < 0) {
                samplesToDecode = 0;
            }
            frameCount = (samplesToDecode + (AUDIO_ADPCM_FRAME_SAMPLES - 1)) >> 4;
            commandPtr = (u32 *)func_801C906C(commandPtr, loader, samplesToDecode, frameCount * AUDIO_ADPCM_FRAME_BYTES, (s16)decodeBuffer, inputBuffer, loader->first | AUDIO_ADPCM_LOOP);
            {
                AudioCommand *command = (AudioCommand *)commandPtr;
                commandPtr += 2;
                command->w0 = ((decodeBuffer + loader->frameOffset * 2) & AUDIO_COMMAND_ADDRESS_MASK) | AUDIO_CMD_DMEM_MOVE;
                command->w1 = (outputCursor << 16) | ((segmentSamples << 1) & 0xFFFF);
            }
        }
        loader->frameOffset = (sampleCount + loader->frameOffset) & (AUDIO_ADPCM_FRAME_SAMPLES - 1);
        loader->samplePosition += sampleCount;
        loader->sampleAddress += frameCount * AUDIO_ADPCM_FRAME_BYTES;
        return commandPtr;
    }
    segmentSamples = frameCount * AUDIO_ADPCM_FRAME_SAMPLES;
    bytesPastEnd = loader->sampleAddress + compressedBytes - (loader->wave->base + loader->wave->length);
    if (bytesPastEnd < 0) {
        bytesPastEnd = 0;
    }
    silenceSamples = (bytesPastEnd / AUDIO_ADPCM_FRAME_BYTES) * AUDIO_ADPCM_FRAME_SAMPLES;
    if (silenceSamples > segmentSamples + cachedSamples) {
        silenceSamples = segmentSamples + cachedSamples;
    }
    compressedBytes -= bytesPastEnd;
    if (silenceSamples - (silenceSamples & (AUDIO_ADPCM_FRAME_SAMPLES - 1)) < sampleCount) {
        didDecode = 1;
        commandPtr = (u32 *)func_801C906C(commandPtr, loader, segmentSamples - silenceSamples, compressedBytes, *outputBuffer, inputBuffer, loader->first);
        if (loader->frameOffset != 0) {
            *outputBuffer = *outputBuffer + loader->frameOffset * 2;
        } else {
            *outputBuffer = *outputBuffer + AUDIO_ADPCM_HISTORY_BYTES;
        }
        loader->frameOffset = (sampleCount + loader->frameOffset) & (AUDIO_ADPCM_FRAME_SAMPLES - 1);
        loader->samplePosition += sampleCount;
        loader->sampleAddress += frameCount * AUDIO_ADPCM_FRAME_BYTES;
    } else {
        loader->frameOffset = 0;
        loader->sampleAddress += frameCount * AUDIO_ADPCM_FRAME_BYTES;
    }
    if (silenceSamples != 0) {
        loader->frameOffset = 0;
        if (didDecode) {
            samplesToDecode = (cachedSamples + segmentSamples - silenceSamples) * 2;
        } else {
            samplesToDecode = 0;
        }
        {
            AudioCommand *command = (AudioCommand *)commandPtr;
            commandPtr += 2;
            command->w0 = ((samplesToDecode + *outputBuffer) & AUDIO_COMMAND_ADDRESS_MASK) | AUDIO_CMD_CLEAR_BUFFER;
            command->w1 = silenceSamples << 1;
        }
    }
    return commandPtr;
}

u32 *func_801C8B24(void *filter, s16 *outputDmem, s32 remainingSamples, s32 sampleOffset, u32 *commandList) {
    /* Load PCM16 samples into DMEM, wrapping loops and clearing any tail beyond the wave. */
    
    AudioCommand *nextCommand = (AudioCommand *)commandList;
    AudioSampleLoader *loader = (AudioSampleLoader *)filter;
    s32 chunkSamples;
    s32 transferBytes;
    int dramMisalignment;
    unsigned long dramAddress;
    s32 dmemPadding;
    s32 overflowBytes;
    u32 loopSamples;

    if (remainingSamples == 0) {
        return (u32 *)nextCommand;
    }
    if ((u32)loader->loopEnd < remainingSamples + loader->samplePosition && loader->loopCount != 0) {
        chunkSamples = loader->loopEnd - loader->samplePosition;
        transferBytes = chunkSamples << 1;
        if (chunkSamples > 0) {
            dramAddress = ((AudioSampleDmaCallback)loader->dma)(loader->sampleAddress, transferBytes, loader->dmaState);
            dramMisalignment = dramAddress & AUDIO_DMA_ALIGNMENT_MASK;
            transferBytes += dramMisalignment;
            { AudioCommand *command = nextCommand++;
              command->w0 = *(u16 *)outputDmem | AUDIO_CMD_SET_BUFFER;
              command->w1 = (transferBytes + AUDIO_DMA_ALIGNMENT - (transferBytes & AUDIO_DMA_ALIGNMENT_MASK)) & AUDIO_COMMAND_HALFWORD_MASK; }
            { AudioCommand *command = nextCommand++;
              command->w0 = AUDIO_CMD_LOAD_BUFFER;
              command->w1 = dramAddress - (u32)dramMisalignment; }
        } else {
            dramMisalignment = 0;
        }
        *outputDmem += dramMisalignment;
        loader->sampleAddress = loader->wave->base + loader->loopStart * AUDIO_PCM16_SAMPLE_BYTES;
        loader->samplePosition = loader->loopStart;
        outputDmem = (s16 *)(s32)*outputDmem;
        if (chunkSamples < remainingSamples) {
            do {
                outputDmem = (s16 *)((s32)outputDmem + chunkSamples * AUDIO_PCM16_SAMPLE_BYTES);
                remainingSamples -= chunkSamples;
                if ((~loader->loopCount != 0) & (loader->loopCount != 0)) {
                    loader->loopCount = loader->loopCount - 1;
                }
                loopSamples = loader->loopEnd - loader->loopStart;
                chunkSamples = remainingSamples;
                if (!(remainingSamples < loopSamples)) {
                    chunkSamples = loopSamples;
                }
                transferBytes = chunkSamples * AUDIO_PCM16_SAMPLE_BYTES;
                dramAddress = ((AudioSampleDmaCallback)loader->dma)(loader->sampleAddress, transferBytes, loader->dmaState);
                dramMisalignment = dramAddress & AUDIO_DMA_ALIGNMENT_MASK;
                transferBytes += dramMisalignment;
                if ((((s32)outputDmem) & AUDIO_DMA_ALIGNMENT_MASK) != 0) {
                    dmemPadding = AUDIO_DMA_ALIGNMENT - (((s32)outputDmem) & AUDIO_DMA_ALIGNMENT_MASK);
                } else {
                    dmemPadding = 0;
                }
                { AudioCommand *command = nextCommand++;
                  command->w0 = ((((s32)outputDmem) + dmemPadding) & AUDIO_COMMAND_HALFWORD_MASK) | AUDIO_CMD_SET_BUFFER;
                  command->w1 = (transferBytes + AUDIO_DMA_ALIGNMENT - (transferBytes & AUDIO_DMA_ALIGNMENT_MASK)) & AUDIO_COMMAND_HALFWORD_MASK; }
                { AudioCommand *command = nextCommand++;
                  command->w0 = AUDIO_CMD_LOAD_BUFFER;
                  command->w1 = dramAddress - dramMisalignment; }
                if ((dramMisalignment != 0) | (dmemPadding != 0)) {
                    AudioCommand *command = nextCommand++;
                    command->w0 = ((((s32)outputDmem) + dramMisalignment + dmemPadding) & AUDIO_COMMAND_ADDRESS_MASK) | AUDIO_CMD_DMEM_MOVE;
                    command->w1 = (((s32)outputDmem) << 16) | ((chunkSamples << 1) & AUDIO_COMMAND_HALFWORD_MASK);
                }
            } while (chunkSamples < remainingSamples);
        }
        loader->samplePosition = loader->samplePosition + remainingSamples;
        loader->sampleAddress = loader->sampleAddress + remainingSamples * AUDIO_PCM16_SAMPLE_BYTES;
        return (u32 *)nextCommand;
    } else {
        s32 requestedEndAddress;
        transferBytes = remainingSamples << 1;
        requestedEndAddress = loader->sampleAddress + transferBytes;
        overflowBytes = requestedEndAddress - (loader->wave->base + loader->wave->length);
        if (0 > overflowBytes) {
            overflowBytes = 0;
        }
        if (transferBytes < overflowBytes) {
            overflowBytes = transferBytes;
        }
        if (overflowBytes < transferBytes) {
            transferBytes -= overflowBytes;
            if (remainingSamples > 0) {
                dramAddress = ((AudioSampleDmaCallback)loader->dma)(loader->sampleAddress, transferBytes, loader->dmaState);
                dramMisalignment = dramAddress & AUDIO_DMA_ALIGNMENT_MASK;
                transferBytes += dramMisalignment;
                { AudioCommand *command = nextCommand++;
                  command->w0 = *(u16 *)outputDmem | AUDIO_CMD_SET_BUFFER;
                  command->w1 = (transferBytes + AUDIO_DMA_ALIGNMENT - ((u32)transferBytes & AUDIO_DMA_ALIGNMENT_MASK)) & AUDIO_COMMAND_HALFWORD_MASK; }
                { AudioCommand *command = nextCommand++;
                  command->w0 = AUDIO_CMD_LOAD_BUFFER;
                  command->w1 = dramAddress - dramMisalignment; }
            } else {
                dramMisalignment = 0;
            }
            *outputDmem += dramMisalignment;
            loader->samplePosition += remainingSamples;
            loader->sampleAddress += remainingSamples * AUDIO_PCM16_SAMPLE_BYTES;
        } else {
            loader->sampleAddress = requestedEndAddress;
        }
        if (overflowBytes != 0) {
            s32 validBytes = (remainingSamples << 1) - overflowBytes;
            if (validBytes < 0) {
                validBytes = 0;
            }
            { AudioCommand *command = nextCommand++;
              command->w0 = ((validBytes + *outputDmem) & AUDIO_COMMAND_ADDRESS_MASK) | AUDIO_CMD_CLEAR_BUFFER;
              command->w1 = overflowBytes; }
        }
        return (u32 *)nextCommand;
    }
}

void func_801C8EC0(AudioSampleLoader *loader, s32 param, AudioSampleWave *wave) {
    /* Install a sample wave and its loop state, or reset playback to its beginning. */
    if (param != AL_FILTER_RESET) {
        if (param == AL_FILTER_SET_WAVETABLE) {
            loader->wave = wave;
            loader->sampleAddress = wave->base;
            loader->samplePosition = 0;
            switch (loader->wave->type) {
            case AUDIO_SAMPLE_WAVE_ADPCM:
                loader->handler = (s32)func_801C86E0;
                loader->wave->length = loader->wave->length / AUDIO_ADPCM_FRAME_BYTES * AUDIO_ADPCM_FRAME_BYTES;
                loader->bookBytes = loader->wave->book->order * (loader->wave->book->predictorCount << 1) * AUDIO_ADPCM_BOOK_VECTOR_SAMPLES;
                if (loader->wave->loop != 0) {
                    loader->loopStart = loader->wave->loop->start;
                    loader->loopEnd = loader->wave->loop->end;
                    loader->loopCount = loader->wave->loop->count;
                    func_801CB2D0((u8 *)loader->wave->loop + AUDIO_ADPCM_LOOP_HISTORY_OFFSET, (u8 *)loader->loopState, AUDIO_ADPCM_HISTORY_BYTES);
                } else {
                    loader->loopCount = 0;
                    loader->loopEnd = 0;
                    loader->loopStart = 0;
                }
                break;
            case AUDIO_SAMPLE_WAVE_PCM16:
                loader->handler = (s32)func_801C8B24;
                if (loader->wave->loop != 0) {
                    loader->loopStart = loader->wave->loop->start;
                    loader->loopEnd = loader->wave->loop->end;
                    loader->loopCount = loader->wave->loop->count;
                } else {
                    loader->loopCount = 0;
                    loader->loopEnd = 0;
                    loader->loopStart = 0;
                }
                break;
            }
        }
    } else {
        loader->frameOffset = 0;
        loader->first = AUDIO_FLAG_INIT;
        loader->samplePosition = 0;
        if (loader->wave != 0) {
            loader->sampleAddress = loader->wave->base;
            if (loader->wave->type == AUDIO_SAMPLE_WAVE_ADPCM) {
                if (loader->wave->loop != 0) {
                    loader->loopCount = loader->wave->loop->count;
                }
            } else if (loader->wave->type == AUDIO_SAMPLE_WAVE_PCM16) {
                if (loader->wave->loop != 0) {
                    loader->loopCount = loader->wave->loop->count;
                }
            }
        }
    }
}

/* audio_adpcm_decode_block: DMA compressed samples and append RSP load, loop-state and decode commands. */
s32 func_801C906C(u32 *commands, u8 *loader, s32 sampleCount, s32 compressedBytes, u16 outputBuffer, s32 inputBuffer, s32 flags) {
    AudioCommand *loadBufferCommand;
    AudioCommand *loadCommand;
    AudioCommand *loopCommand;
    AudioCommand *decodeBufferCommand;
    AudioCommand *decodeCommand;
    s32 dramAddress;
    s32 alignmentOffset;
    s32 alignmentAdjustment;
    s16 inputOffset;

    inputOffset = inputBuffer;
    if (compressedBytes > 0) {
        dramAddress = ((AudioSampleDmaCallback)((AudioSampleLoader *)loader)->dma)(((AudioSampleLoader *)loader)->sampleAddress, compressedBytes, ((AudioSampleLoader *)loader)->dmaState);
        alignmentOffset = dramAddress & AUDIO_DMA_ALIGNMENT_MASK;
        compressedBytes += alignmentOffset;
        loadBufferCommand = (AudioCommand *)commands;
        commands += 2;
        loadCommand = (AudioCommand *)commands;
        commands += 2;
        loadBufferCommand->w0 = (inputBuffer & AUDIO_COMMAND_HALFWORD_MASK) | AUDIO_CMD_SET_BUFFER;
        alignmentAdjustment = (compressedBytes & AUDIO_DMA_ALIGNMENT_MASK) - AUDIO_DMA_ALIGNMENT;
        loadBufferCommand->w1 = (compressedBytes - alignmentAdjustment) & AUDIO_COMMAND_HALFWORD_MASK;
        loadCommand->w0 = AUDIO_CMD_LOAD_BUFFER;
        loadCommand->w1 = dramAddress - alignmentOffset;
    } else {
        alignmentOffset = 0;
    }
    if (flags & AUDIO_ADPCM_LOOP) {
        loopCommand = (AudioCommand *)commands;
        commands += 2;
        loopCommand->w0 = AUDIO_CMD_SET_LOOP;
        loopCommand->w1 = ((AudioSampleLoader *)loader)->loopState & AUDIO_PHYSICAL_ADDRESS_MASK;
    }
    decodeBufferCommand = (AudioCommand *)commands;
    commands += 2;
    decodeBufferCommand->w0 = ((inputOffset + alignmentOffset) & AUDIO_COMMAND_HALFWORD_MASK) | AUDIO_CMD_SET_BUFFER;
    decodeBufferCommand->w1 = (outputBuffer << 16) | ((sampleCount << 1) & AUDIO_COMMAND_HALFWORD_MASK);
    decodeCommand = (AudioCommand *)commands;
    commands += 2;
    decodeCommand->w0 = ((flags & AUDIO_COMMAND_FLAGS_MASK) << 16) | AUDIO_CMD_ADPCM;
    decodeCommand->w1 = ((AudioSampleLoader *)loader)->decoderState & AUDIO_PHYSICAL_ADDRESS_MASK;
    ((AudioSampleLoader *)loader)->first = 0;
    return (s32)commands;
}

/* Original compiler padding. */
const u32 D_801C91E4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* alMainBusPull: clears the main bus's left (DMEM 0x6C0) and right (0x800)
 * output buffers, then has each of its sources append its audio commands.
 * bus[5] is the source count and bus[7] the source array; a source's word 1
 * is its pull handler. Returns the advanced command pointer. */
s32 func_801C91F0(s32 *mainBus, s32 outp, s32 outCount, s32 sampleOffset, u32 *cmdList) {
    typedef struct { u32 w0, w1; } Acmd;
    Acmd *ptr = (Acmd *)cmdList;
    s32 *bus = mainBus;
    s32 **sources = (s32 **)bus[7];
    s32 i;

    /* aClearBuffer(left out), aClearBuffer(right out) */
    { Acmd *_a = ptr++; _a->w0 = 0x02000000 | (0x6C0 & 0xFFFFFF); _a->w1 = outCount << 1; }
    { Acmd *_a = ptr++; _a->w0 = 0x02000000 | (0x800 & 0xFFFFFF); _a->w1 = outCount << 1; }

    for (i = 0; i < bus[5]; i++) {
        ptr = (Acmd *)((u32 *(*)(s32 *, s32, s32, s32, u32 *))sources[i][1])(sources[i], outp, outCount, sampleOffset, (u32 *)ptr);
    }

    return (s32)ptr;
}

/* alAuxBusParam: SYNTH_BUS_ADD_SOURCE appends `param` (a filter) to the
 * auxiliary bus's source list; every other parameter is ignored. */
s32 func_801C92CC(s32 *auxBus, s32 paramId, s32 param) {
    s32 *sources = (s32 *)auxBus[MAIN_BUS_SOURCES];
    if (paramId == SYNTH_BUS_ADD_SOURCE) {
        sources[auxBus[MAIN_BUS_SOURCE_COUNT]++] = param;
    }
    return 0;
}

/* Original compiler padding. */
const u32 D_801C92FC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* Apply timed voice controls and emit envelope mixing commands for the requested samples. */
u32 *func_801C9300(void *filter, s16 *outputOffset, s32 remainingSamples, s32 sampleOffset, u32 *commands) {
    u32 *commandPtr = commands;
    EnvMixer *mixer = (EnvMixer *)filter;
    s32 previousOffset;
    s16 inputByteOffset;
    s32 controlOffset = sampleOffset;
    s32 segmentSamples;
    s16 outputByteOffset = 0;
    s32 volume;
    EnvParam *completedParam;

    inputByteOffset = 0;

    while (mixer->ctrlList != 0) {
        previousOffset = controlOffset;
        controlOffset = mixer->ctrlList->delta;
        segmentSamples = controlOffset - previousOffset;
        if (remainingSamples < segmentSamples) {
            break;
        }

        if (segmentSamples < 0) {
            func_801CA030(D_8010C480, D_8010C484, 0x68);
        }
        if (AL_ENVELOPE_MAX_SAMPLES < segmentSamples) {
            func_801CA030(D_8010C480, D_8010C484, 0x69);
        }

        switch (mixer->ctrlList->type) {
            case AL_FILTER_START_VOICE_ALT: {
                EnvStartParamAlt *control = (EnvStartParamAlt *)mixer->ctrlList;
                EnvFilter *filterPrefix = (EnvFilter *)mixer;
                s32 squaredVolume;

                if (control->unity) {
                    (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_SET_UNITY_PITCH, 0);
                }
                (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_SET_WAVETABLE, control->wave);
                (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_START, 0);

                mixer->first = 1;
                mixer->delta = 0;
                mixer->segEnd = control->samples;

                squaredVolume = ((s32)control->volume * control->volume) >> AL_ENVELOPE_VOLUME_SHIFT; mixer->volume = (s16)squaredVolume;
                mixer->pan = control->pan;
                mixer->dryamt = D_801F45B0[control->fxMix];
                mixer->wetamt = D_801F45B0[AL_ENVELOPE_PAN_MAX - control->fxMix];

                if (control->samples) {
                    mixer->cvolL = 1;
                    mixer->cvolR = 1;
                } else {
                    mixer->cvolL = (mixer->volume * D_801F45B0[mixer->pan]) >> AL_ENVELOPE_VOLUME_SHIFT; mixer->cvolR = (mixer->volume * D_801F45B0[AL_ENVELOPE_PAN_MAX - mixer->pan]) >> AL_ENVELOPE_VOLUME_SHIFT;
                }

                if (filterPrefix->source) {
                    (*filterPrefix->source->setParam)(filterPrefix->source, AL_FILTER_SET_PITCH, control->pitch);
                }
            } break;

            case AL_FILTER_SET_FX_MIX:
            case AL_FILTER_SET_PAN:
            case AL_FILTER_SET_VOLUME:
                commandPtr = func_801C9920(mixer, &inputByteOffset, &outputByteOffset, segmentSamples, sampleOffset, commandPtr);

                if (mixer->delta >= mixer->segEnd) {
                    mixer->ltgt = (mixer->volume * D_801F45B0[mixer->pan]) >> AL_ENVELOPE_VOLUME_SHIFT; mixer->rtgt = (mixer->volume * D_801F45B0[AL_ENVELOPE_PAN_MAX - mixer->pan]) >> AL_ENVELOPE_VOLUME_SHIFT; mixer->delta = mixer->segEnd;
                    mixer->cvolL = mixer->ltgt;
                    mixer->cvolR = mixer->rtgt;
                } else {
                    mixer->cvolL = func_801C9FA4(mixer->cvolL, mixer->delta, mixer->lratm, mixer->lratl);
                    mixer->cvolR = func_801C9FA4(mixer->cvolR, mixer->delta, mixer->rratm, mixer->rratl);
                }

                if (mixer->cvolL == 0) mixer->cvolL = 1;
                if (mixer->cvolR == 0) mixer->cvolR = 1;

                if (mixer->ctrlList->type == AL_FILTER_SET_PAN) {
                    mixer->pan = (s16)mixer->ctrlList->data;
                }

                if (mixer->ctrlList->type == AL_FILTER_SET_VOLUME) {
                    mixer->delta = 0;
                    volume = mixer->ctrlList->data;
                    volume = (volume * volume) >> AL_ENVELOPE_VOLUME_SHIFT; mixer->volume = (s16)volume; mixer->segEnd = mixer->ctrlList->moredata;
                }

                if (mixer->ctrlList->type == AL_FILTER_SET_FX_MIX) {
                    mixer->dryamt = D_801F45B0[mixer->ctrlList->data];
                    mixer->wetamt = D_801F45B0[AL_ENVELOPE_PAN_MAX - mixer->ctrlList->data];
                }

                mixer->first = 1;
                break;

            case AL_FILTER_START_VOICE: {
                EnvParam *control = mixer->ctrlList;

                if (control->unity) {
                    (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_SET_UNITY_PITCH, 0);
                }
                (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_SET_WAVETABLE, control->data);
                (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_START, 0);
            } break;

            case AL_FILTER_STOP_VOICE:
                commandPtr = func_801C9920(mixer, &inputByteOffset, &outputByteOffset, segmentSamples, sampleOffset, commandPtr);
                (*mixer->filter.setParam)(&mixer->filter, AL_FILTER_RESET, 0);
                break;

            case AL_FILTER_FREE_VOICE: {
                ObjectNode *synthDriver = D_801F46D0;
                EnvParam *control = mixer->ctrlList;

                *(s32 *)(control->data + AL_PHYSICAL_VOICE_OFFSET) = 0; func_801CB824(synthDriver, control->data);
            } break;

            default:
                commandPtr = func_801C9920(mixer, &inputByteOffset, &outputByteOffset, segmentSamples, sampleOffset, commandPtr);
                (*mixer->filter.setParam)(&mixer->filter, mixer->ctrlList->type, mixer->ctrlList->data);
                break;
        }

        remainingSamples -= segmentSamples;
        outputByteOffset += segmentSamples << 1;

        completedParam = mixer->ctrlList;
        mixer->ctrlList = completedParam->next;
        if (mixer->ctrlList == 0) {
            mixer->ctrlTail = 0;
        }
        func_801CB7B8(completedParam);
    }

    commandPtr = func_801C9920(mixer, &inputByteOffset, &outputByteOffset, remainingSamples, sampleOffset, commandPtr);

    if (mixer->delta > mixer->segEnd) {
        mixer->delta = mixer->segEnd;
    }

    return commandPtr;
}

/* libultra alEnvmixerParam: handles the envelope mixer's own messages and forwards the rest to its source filter. */
s32 func_801C984C(EnvMixer *mixer, s32 paramId, s32 param) {
    EnvMixer *self = mixer;
    EnvFilter *source;
    switch (paramId) {
    case AL_FILTER_SET_SOURCE:
        mixer->filter.source = (EnvFilter *)param;
        return 0;
    case AL_FILTER_ADD_UPDATE:
        if (mixer->ctrlTail != 0) {
            mixer->ctrlTail->next = (EnvParam *)param;
        } else {
            mixer->ctrlList = (EnvParam *)param;
        }
        self->ctrlTail = (EnvParam *)param;
        return 0;
    case AL_FILTER_RESET:
        source = mixer->filter.source;
        mixer->first = 1;
        mixer->motion = 0;
        mixer->volume = 1;
        if (source != 0) {
            source->setParam(source, AL_FILTER_RESET, param);
        }
        return 0;
    case AL_FILTER_START:
        source = mixer->filter.source;
        mixer->motion = AL_ENVELOPE_PLAYING;
        if (source != 0) {
            source->setParam(source, AL_FILTER_START, param);
        }
        return 0;
    }
    mixer = (EnvMixer *)mixer->filter.source;
    if (mixer != 0) {
        mixer->filter.setParam(mixer, paramId, param);
    }
    return 0;
}

extern u8 D_8010C480[];
extern u8 D_8010C484[];
extern s16 D_801F45B0[];
s16 func_801C9D24(f64 arg0, f64 arg1, s32 arg2, u16 *arg3);

/* Emit RSP commands to mix one voice segment into the main and auxiliary stereo buffers. */
u32 *func_801C9920(EnvMixer *filter, s16 *inputByteOffset, s16 *outputByteOffset, s32 sampleCount, s32 sampleOffset, u32 *commandList) {
    AudioCommand *commandPtr = (AudioCommand *)commandList;
    EnvMixer *mixer = (EnvMixer *)filter;
    EnvFilter *source = mixer->filter.source;

    if (mixer->motion != AL_ENVELOPE_PLAYING || !sampleCount)
        return (u32 *)commandPtr;

    (source) ? ((void)0) : func_801CA030(D_8010C480, D_8010C484, AL_ENVELOPE_SOURCE_ASSERT_LINE);

    commandPtr = (*(EnvPullHandler)source->handler)(source, inputByteOffset, sampleCount, sampleOffset, (AudioCommand *)commandList);

    {
        AudioCommand *command = (AudioCommand *)commandPtr++;
        command->w0 = ((((u32)AUDIO_OP_SET_BUFFER & 0xFF) << 24) | (((u32)AUDIO_FLAG_MAIN & 0xFF) << 16) | (((u32)*inputByteOffset & 0xFFFF) << 0));
        command->w1 = (((u32)(AUDIO_DMEM_MAIN_LEFT + *outputByteOffset) & 0xFFFF) << 16) | (((u32)(sampleCount << 1) & 0xFFFF) << 0);
    }
    {
        AudioCommand *command = (AudioCommand *)commandPtr++;
        command->w0 = ((((u32)AUDIO_OP_SET_BUFFER & 0xFF) << 24) | (((u32)AUDIO_FLAG_AUX & 0xFF) << 16) | (((u32)(AUDIO_DMEM_MAIN_RIGHT + *outputByteOffset) & 0xFFFF) << 0));
        command->w1 = (((u32)(AUDIO_FX_DMEM_LEFT + *outputByteOffset) & 0xFFFF) << 16) | (((u32)(AUDIO_FX_DMEM_RIGHT + *outputByteOffset) & 0xFFFF) << 0);
    }

    if (mixer->first) {
        mixer->first = 0;

        mixer->ltgt = (mixer->volume * D_801F45B0[mixer->pan]) >> AL_ENVELOPE_VOLUME_SHIFT;
        mixer->lratm = func_801C9D24((f64)mixer->cvolL, (f64)mixer->ltgt, mixer->segEnd, &(mixer->lratl));
        mixer->rtgt = (mixer->volume * D_801F45B0[AL_ENVELOPE_PAN_COUNT - mixer->pan - 1]) >> AL_ENVELOPE_VOLUME_SHIFT;
        mixer->rratm = func_801C9D24((f64)mixer->cvolR, (f64)mixer->rtgt, mixer->segEnd, &(mixer->rratl));

        {
            AudioCommand *command = (AudioCommand *)commandPtr++;
            command->w0 = ((((u32)AUDIO_OP_SET_VOLUME & 0xFF) << 24) | (((u32)(AUDIO_FLAG_LEFT | AUDIO_FLAG_VOLUME) & 0xFFFF) << 16) | (((u32)mixer->cvolL & 0xFFFF) << 0));
            command->w1 = (((u32)0 & 0xFFFF) << 16) | (((u32)0 & 0xFFFF) << 0);
        }
        {
            AudioCommand *command = (AudioCommand *)commandPtr++;
            command->w0 = ((((u32)AUDIO_OP_SET_VOLUME & 0xFF) << 24) | (((u32)(AUDIO_FLAG_RIGHT | AUDIO_FLAG_VOLUME) & 0xFFFF) << 16) | (((u32)mixer->cvolR & 0xFFFF) << 0));
            command->w1 = (((u32)0 & 0xFFFF) << 16) | (((u32)0 & 0xFFFF) << 0);
        }
        {
            AudioCommand *command = (AudioCommand *)commandPtr++;
            command->w0 = ((((u32)AUDIO_OP_SET_VOLUME & 0xFF) << 24) | (((u32)(AUDIO_FLAG_LEFT | AUDIO_FLAG_RATE) & 0xFFFF) << 16) | (((u32)mixer->ltgt & 0xFFFF) << 0));
            command->w1 = (((u32)mixer->lratm & 0xFFFF) << 16) | (((u32)mixer->lratl & 0xFFFF) << 0);
        }
        {
            AudioCommand *command = (AudioCommand *)commandPtr++;
            command->w0 = ((((u32)AUDIO_OP_SET_VOLUME & 0xFF) << 24) | (((u32)(AUDIO_FLAG_RIGHT | AUDIO_FLAG_RATE) & 0xFFFF) << 16) | (((u32)mixer->rtgt & 0xFFFF) << 0));
            command->w1 = (((u32)mixer->rratm & 0xFFFF) << 16) | (((u32)mixer->rratl & 0xFFFF) << 0);
        }
        {
            AudioCommand *command = (AudioCommand *)commandPtr++;
            command->w0 = ((((u32)AUDIO_OP_SET_VOLUME & 0xFF) << 24) | (((u32)AUDIO_FLAG_AUX & 0xFFFF) << 16) | (((u32)mixer->dryamt & 0xFFFF) << 0));
            command->w1 = (((u32)0 & 0xFFFF) << 16) | (((u32)mixer->wetamt & 0xFFFF) << 0);
        }
        {
            AudioCommand *command = (AudioCommand *)commandPtr++;
            command->w0 = (((u32)AUDIO_OP_ENV_MIXER & 0xFF) << 24) | (((u32)(AUDIO_FLAG_INIT | AUDIO_FLAG_AUX) & 0xFF) << 16);
            command->w1 = (u32)(func_801C7D90((u32)mixer->state));
        }
    }
    else {
        AudioCommand *command = (AudioCommand *)commandPtr++;
        command->w0 = (((u32)AUDIO_OP_ENV_MIXER & 0xFF) << 24) | (((u32)(AUDIO_FLAG_CONTINUE | AUDIO_FLAG_AUX) & 0xFF) << 16);
        command->w1 = (u32)(func_801C7D90((u32)mixer->state));
    }

    *inputByteOffset += (sampleCount << 1);
    mixer->delta += sampleCount;

    return (u32 *)commandPtr;
}

/* frexp: splits value into a mantissa in [0.5, 1) with value's sign and a power
 * of two stored in *exponent, so value == mantissa * 2^*exponent. Zero gives
 * zero with exponent 0. D_8010C4D8 = 1.0, D_8010C4E0 = 0.5, D_8010C4E8 = 0.5. */
f64 func_801C9C20(f64 value, s32 *exponent) {
 f64 mag, mantissa; f64 half, limit;
 *exponent = 0;
 if (value == 0.0)
 { return value; }
 if (value > 0.0) mag = value; else mag = -value;
 limit = D_8010C4D8;
 if (mag >= limit) {
 half = D_8010C4E0;
 do {
 mag *= half;
 ++*exponent;
 } while (mag >= limit);
 }
 limit = D_8010C4E8;
 if (mag < limit) { do { mag += mag; (*exponent)--; } while (mag < limit); }
 mantissa = mag;
 if (!(value > 0.0)) mantissa = -mantissa;
 return mantissa;
}

/* ldexp-style helper: scale `value` by 2^exponent (non-negative exponents only). */
f64 func_801C9D00(f64 value, s32 exponent) {
    if (exponent != 0) {
        value *= 1 << exponent;
    }
    return value;
}

s16 func_801C9D24(f64 initialVolume, f64 targetVolume, s32 sampleCount, u16 *rateFraction)
{
    /* Approximate the exponential gain per eight samples as a split fixed-point rate. */
    f64 logTable[AL_ENVELOPE_LOG_TABLE_SIZE];
    f64 powerBase, rateValue, magnitude, inverseSamples, unusedResult;
    f64 mantissa;
    s32 binaryExponent;
    s32 *exponentPtr;
    s32 power;
    s16 rateInteger;

    inverseSamples = D_8010C530 / (f64)sampleCount;
    if (sampleCount == 0) {
        if (initialVolume <= targetVolume) { *rateFraction = AL_ENVELOPE_RATE_FRACTION_MAX; return AL_ENVELOPE_RATE_INTEGER_MAX; }
        *rateFraction = 0; return 0;
    }
    if (targetVolume < D_8010C530) targetVolume = D_8010C530;
    if (initialVolume <= 0.0) initialVolume = D_8010C530;
    *((EnvRateLogTable *)logTable) = D_8010C4F0;
    initialVolume = targetVolume / initialVolume;
    power = (s32)(inverseSamples * D_8010C538);
    exponentPtr = &binaryExponent;
    binaryExponent = 0;
    if (initialVolume != 0.0) {
        magnitude = initialVolume > 0.0 ? initialVolume : -initialVolume;
        mantissa = D_8010C540;
        if (magnitude >= mantissa) {
            do { magnitude *= D_8010C548; ++binaryExponent; } while (magnitude >= mantissa);
        }
        if (magnitude < D_8010C550) {
            do { magnitude += magnitude; --binaryExponent; } while (magnitude < D_8010C550);
        }
        mantissa = magnitude;
        if (!(initialVolume > 0.0)) mantissa = -mantissa;
        initialVolume = mantissa;
    }
    powerBase = (((logTable[(s32)(initialVolume * D_8010C558) - AL_ENVELOPE_LOG_INDEX_BIAS] + (f64)binaryExponent) * D_8010C560) / D_8010C568) + D_8010C570;
    rateValue = D_8010C570;
    if (power != 0) {
        do { if (power & 1) rateValue *= powerBase; power >>= 1; powerBase *= powerBase; } while (power != 0);
    }
    rateValue *= rateValue;
    rateValue *= rateValue;
    rateValue *= rateValue;
    rateInteger = (s16)(s32)rateValue;
    *rateFraction = (s32)((rateValue - (f64)(f32)rateInteger) * D_8010C578);
    return rateInteger;
}

/* Audio envelope ramp: returns volume * rate^(samples / 8), where the
 * per-8-sample rate is the 16.16 fixed-point value rateHigh:rateLow.
 * The power is taken by repeated squaring over the bits of the count. */
f32 func_801C9FA4(f32 volume, s32 samples, s32 rateHigh, s32 rateLow) {
    f32 rate;
    f32 factor;
    s32 i;
    s32 steps;

    steps = samples >> 3;
    if (steps == 0) {
        return volume;
    }
    rate = ((f32)(rateHigh << 16) + (f32)(rateLow & 0xFFFF)) / 65536.0f;
    factor = 1.0f;
    for (i = 0; i < 32; i++) {
        if (steps & 1) {
            factor *= rate;
        }
        steps >>= 1;
        if (steps == 0) {
            break;
        }
        rate = rate * rate;
    }
    return volume * factor;
}

/* Original compiler padding. */
const u32 D_801CA028_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra __assert(expression, file, line): reports a failed assert in debug
 * builds; in this release build it does nothing. */
void func_801CA030(u8 *expression, u8 *file, s32 line)
{
}

/* Original compiler padding. */
const u32 D_801CA038_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra alFilterNew: initialise an audio synthesis filter (ALFilter):
 * no source, the given command handler and parameter setter, input/output
 * buffers 0, and the filter type (AL_ADPCM, AL_RESAMPLE, AL_ENVMIX, ...). */
void func_801CA040(s32 *filter, s32 handler, s32 setParam, s32 type)
{
    filter[0] = 0;                /* source */
    filter[1] = handler;          /* handler */
    filter[2] = setParam;         /* setParam */
    ((s16 *)filter)[6] = 0;       /* inp */
    ((s16 *)filter)[7] = 0;       /* outp */
    filter[4] = type;             /* type */
}

/* Original compiler padding. */
const u32 D_801CA05C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* alMainBusPull: clear the main stereo mix, pull each source and mix in its auxiliary output. */
u32 *func_801CA060(void *filter, s16 *outputBuffer, s32 sampleCount, s32 sampleOffset, u32 *commandList) {
    register AudioCommand *commands = (AudioCommand *)commandList;
    AudioMainBus *bus = (AudioMainBus *)filter;
    register AudioSynthFilter **sources = bus->sources;
    register int sourceIndex;

    { AudioCommand *command = (AudioCommand *)commands++; command->w0 = AUDIO_CMD_CLEAR_BUFFER | (AUDIO_DMEM_MAIN_LEFT & 0xFFFFFF); command->w1 = (u32)(sampleCount << 1); }
    { AudioCommand *command = (AudioCommand *)commands++; command->w0 = AUDIO_CMD_CLEAR_BUFFER | (AUDIO_DMEM_MAIN_RIGHT & 0xFFFFFF); command->w1 = (u32)(sampleCount << 1); }
    for (sourceIndex = 0; sourceIndex < bus->sourceCount; sourceIndex++) {
        commands = (*(EnvPullHandler)sources[sourceIndex]->pull)(sources[sourceIndex], outputBuffer, sampleCount, sampleOffset, commands);
        { AudioCommand *command = (AudioCommand *)commands++; command->w0 = (AUDIO_OP_SET_BUFFER << 24) | ((0 & 0xFF) << 16); command->w1 = ((0 & 0xFFFF) << 16) | ((sampleCount << 1) & 0xFFFF); }
        { AudioCommand *command = (AudioCommand *)commands++; command->w0 = AUDIO_CMD_MIX | ((s32)AUDIO_MIX_GAIN_MAX & 0xFFFF); command->w1 = (AUDIO_FX_DMEM_LEFT << 16) | AUDIO_DMEM_MAIN_LEFT; }
        { AudioCommand *command = (AudioCommand *)commands++; command->w0 = AUDIO_CMD_MIX | (AUDIO_MIX_GAIN_MAX & 0xFFFF); command->w1 = (AUDIO_FX_DMEM_RIGHT << 16) | AUDIO_DMEM_MAIN_RIGHT; }
    }
    return (u32 *)commands;
}

/* alMainBusParam: SYNTH_BUS_ADD_SOURCE appends `param` (a filter) to the
 * main bus's source list; every other parameter is ignored. */
s32 func_801CA1A0(s32 *mainBus, s32 paramId, s32 param) {
    s32 *sources = (s32 *)mainBus[MAIN_BUS_SOURCES];
    if (paramId == SYNTH_BUS_ADD_SOURCE) {
        sources[mainBus[MAIN_BUS_SOURCE_COUNT]++] = param;
    }
    return 0;
}

/* Pull input samples and emit a DMEM copy at unity pitch or an RSP resample command. */
u32 *func_801CA1D0(s32 *filterMemory, u16 *outputBuffer, s32 outputCount, s32 sampleOffset, u32 *commands)
{
  AudioEffectResampler *resampler = (AudioEffectResampler *) filterMemory;
  s16 inputBuffer = AUDIO_RESAMPLE_DMEM_INPUT;
  s32 *source = (s32 *) filterMemory[0];
  f32 quantizedRatio;
  f32 inputSamples;
  s32 inputCount;
  if (outputCount == 0) return commands;
  {
    if (resampler)
    {
      inputCount = ((AudioEffectResampler *)filterMemory)->unityPitch;
    }
    else
    {
      ;
    }
    if (((AudioEffectResampler *)filterMemory)->unityPitch != 0)
    {
      commands = ((AudioResamplePullHandler) source[1])(source, &inputBuffer, outputCount, sampleOffset, commands);
      {
        u32 *command = commands;
        commands += 2;
        command[0] = (inputBuffer & AUDIO_COMMAND_ADDRESS_MASK) | AUDIO_CMD_DMEM_MOVE;
        command[1] = (outputBuffer[0] << 16) | ((u16) (outputCount << 1));
      }
    }
    else
    {
      if (D_8010C580 < resampler->ratio)
      {
        resampler->ratio = 1.99996f;
      }
      quantizedRatio = (s32) (resampler->ratio * 32768.0f);
      quantizedRatio /= 32768.0f;
      inputSamples = resampler->delta + (quantizedRatio * outputCount);
      inputCount = (s32) inputSamples;
      inputSamples -= inputCount;
      resampler->ratio = quantizedRatio;
      resampler->delta = inputSamples;
      commands = ((AudioResamplePullHandler) source[1])(source, &inputBuffer, inputCount, sampleOffset, commands);
      {
        u32 *command = commands;
        f32 pitch = resampler->ratio;
        commands += 2;
        command[0] = ((u16) inputBuffer) | AUDIO_CMD_SET_BUFFER;
        command[1] = (outputBuffer[0] << 16) | ((u16) (outputCount << 1));
        pitch *= 32768.0f;
        command = commands;
        commands += 2;
        command[0] = (AUDIO_CMD_RESAMPLE | (((u8 *) filterMemory)[AUDIO_RESAMPLE_FIRST_FLAG_OFFSET] << 16)) | ((u16) ((s32) pitch));
        command[1] = func_801C7D90(filterMemory[5]);
      }
      ((AudioEffectResampler *)filterMemory)->first = 0;
    }
  }
  return commands;
}

/* alResampleParam: handle a filter message for a resampler, forwarding
 * reset/start (and any message it doesn't handle) to its source filter.
 * The case labels follow the ROM's jump table jtbl_8010C588. */
s32 func_801CA3BC(s32 *resampler, s32 paramID, s32 param) {
    s32 *r = resampler;
    s32 *source;

    switch (paramID) {
    case AL_FILTER_SET_SOURCE:
        resampler[RESAMPLER_SOURCE] = param;
        return 0;
    case AL_FILTER_RESET:
        r[RESAMPLER_DELTA] = 0;
        r[RESAMPLER_FIRST] = 1;
        r[RESAMPLER_MOTION] = 0;
        r[RESAMPLER_UNITY_PITCH] = 0;
        source = (s32 *)resampler[RESAMPLER_SOURCE];
        if (source != NULL) {
            ((s32 (*)(s32 *, s32, s32))source[RESAMPLER_SET_PARAM])(source, AL_FILTER_RESET, 0);
        }
        return 0;
    case AL_FILTER_START:
        r[RESAMPLER_MOTION] = 1;
        source = (s32 *)resampler[RESAMPLER_SOURCE];
        if (source != NULL) {
            ((s32 (*)(s32 *, s32, s32))source[RESAMPLER_SET_PARAM])(source, AL_FILTER_START, 0);
        }
        return 0;
    case AL_FILTER_SET_PITCH:
        r[RESAMPLER_RATIO] = param;
        return 0;
    case AL_FILTER_SET_UNITY_PITCH:
        r[RESAMPLER_UNITY_PITCH] = 1;
        return 0;
    }

    source = (s32 *)resampler[RESAMPLER_SOURCE];
    if (source != NULL) {
        ((s32 (*)(s32 *, s32, s32))source[RESAMPLER_SET_PARAM])(source, paramID, param);
    }
    return 0;
}

/* Original compiler padding. */
const u32 D_801CA47C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* Emit reverb commands for each delay section, mix the wet output and advance the circular buffer. */
u32 *func_801CA480(s32 *filterMemory, s32 outputAddress, s32 sampleCount, s32 sampleOffset, u32 *commandList) {
    AudioCommand *commands = (AudioCommand *)commandList;
    AudioEffect *effect = (AudioEffect *)filterMemory;
    AudioEffect *upstream = (AudioEffect *)effect->filter.source;
    s16 sectionIndex, delayInputBuffer, delayOutputBuffer, inputBuffer, outputBuffer;
    s16 *delayInput, *delayOutput, *previousOutput = 0;
    AudioEffectDelay *delay;

    if (!upstream) {
        func_801CA030(D_8010C5B0, D_8010C5B4, AUDIO_FX_SOURCE_ASSERT_LINE);
    }
    commands = (AudioCommand *)(*(AudioEffectPullHandler)upstream->filter.handler)((s32 *)upstream, outputAddress, sampleCount, sampleOffset, (u32 *)commands);

    inputBuffer = AUDIO_FX_DMEM_LEFT;
    outputBuffer = AUDIO_FX_DMEM_RIGHT;
    delayInputBuffer = AUDIO_FX_DMEM_DELAY_INPUT;
    delayOutputBuffer = AUDIO_FX_DMEM_DELAY_OUTPUT;

    { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_SET_BUFFER; command->w1 = (sampleCount << 1) & 0xFFFF; }
    { AudioCommand *command = commands++; command->w0 = AUDIO_FX_FOLD_LEFT_COMMAND; command->w1 = (AUDIO_FX_DMEM_LEFT << 16) | (inputBuffer & 0xFFFF); }
    { AudioCommand *command = commands++; command->w0 = AUDIO_FX_FOLD_RIGHT_COMMAND; command->w1 = (AUDIO_FX_DMEM_RIGHT << 16) | (inputBuffer & 0xFFFF); }
    commands = (AudioCommand *)func_801CADBC((s32 *)effect, (s32)effect->input, inputBuffer, sampleCount, (u32 *)commands);

    { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_CLEAR_BUFFER | (outputBuffer & 0xFFFFFF); command->w1 = (u32)(sampleCount << 1); }

    for (sectionIndex = 0; sectionIndex < effect->sectionCount; sectionIndex++) {
        delay = &effect->delay[sectionIndex];
        delayInput = &effect->input[-delay->input];
        delayOutput = &effect->input[-delay->output];

        if (delayInput == previousOutput) {
            s16 swapBuffer = delayOutputBuffer;
            delayOutputBuffer = delayInputBuffer;
            delayInputBuffer = swapBuffer;
        } else {
            commands = (AudioCommand *)func_801CAC4C((s32 *)effect, delayInput, delayInputBuffer, sampleCount, (u32 *)commands);
        }
        commands = (AudioCommand *)func_801CAA34((s32 *)effect, delay, delayOutputBuffer, sampleCount, (u32 *)commands);

        if (delay->feedforward) {
            { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_MIX | (u16)delay->feedforward; command->w1 = (delayInputBuffer << 16) | (delayOutputBuffer & 0xFFFF); }
            if (!delay->resampler && !delay->lowPass) {
                commands = (AudioCommand *)func_801CADBC((s32 *)effect, (s32)delayOutput, delayOutputBuffer, sampleCount, (u32 *)commands);
            }
        }

        if (delay->feedback) {
            { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_MIX | (u16)delay->feedback; command->w1 = (delayOutputBuffer << 16) | (delayInputBuffer & 0xFFFF); }
            commands = (AudioCommand *)func_801CADBC((s32 *)effect, (s32)delayInput, delayInputBuffer, sampleCount, (u32 *)commands);
        }

        if (delay->lowPass) {
            commands = (AudioCommand *)func_801CAF2C((u8 *)delay->lowPass, delayOutputBuffer, sampleCount, (u8 *)commands);
        }

        if (!delay->resampler) {
            commands = (AudioCommand *)func_801CADBC((s32 *)effect, delayOutput, delayOutputBuffer, sampleCount, (u32 *)commands);
        }

        if (delay->gain) {
            AudioCommand *command = commands++; command->w0 = AUDIO_CMD_MIX | (u16)delay->gain; command->w1 = (delayOutputBuffer << 16) | (outputBuffer & 0xFFFF);
        }

        previousOutput = &effect->input[delay->output];
    }

    effect->input += sampleCount;
    if (effect->input > &effect->base[effect->length]) {
        effect->input -= effect->length;
    }

    { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_DMEM_MOVE | (outputBuffer & 0xFFFFFF); command->w1 = (AUDIO_FX_DMEM_LEFT << 16) | ((u32)(sampleCount << 1) & 0xFFFF); }

    return (u32 *)commands;
}


/* libultra alFxParam: AL_FILTER_SET_SOURCE connects the effect's input source; other params are ignored. */
s32 func_801CA830(s32 *fx, s32 paramID, s32 source) {
    if (paramID == SYNTH_FILTER_SET_SOURCE) {
        *fx = source;
    }
    return 0;
}

extern const f64 D_8010C5E0;
extern f64 D_8010C5E0;
extern const f64 D_8010C5E8;
/* Set one delay-section parameter and rebuild low-pass coefficients when needed. */
s32 func_801CA844(AudioEffect *effect, s32 parameterId, s32 *valuePointer) {
    s32 parameter = (parameterId - AUDIO_FX_PARAM_HEADER_WORDS) % AUDIO_FX_PARAMS_PER_SECTION;
    s32 section = (parameterId - AUDIO_FX_PARAM_HEADER_WORDS) / AUDIO_FX_PARAMS_PER_SECTION;
    s32 value = *valuePointer;

    switch (parameter) {
    case AUDIO_FX_PARAM_INPUT:
        effect->delay[section].input = value & ~AUDIO_FX_DELAY_ALIGNMENT_MASK;
        break;
    case AUDIO_FX_PARAM_OUTPUT:
        effect->delay[section].output = value & ~AUDIO_FX_DELAY_ALIGNMENT_MASK;
        break;
    case AUDIO_FX_PARAM_FEEDFORWARD:
        effect->delay[section].feedforward = value;
        break;
    case AUDIO_FX_PARAM_FEEDBACK:
        effect->delay[section].feedback = value;
        break;
    case AUDIO_FX_PARAM_GAIN:
        effect->delay[section].gain = value;
        break;
    case AUDIO_FX_PARAM_MODULATION_RATE:
        effect->delay[section].modulationIncrement = (double)((f32)value / 1000.0f) * 2.0 / (double)*(s32 *)((u8 *)D_801F46D0 + AUDIO_FX_SYNTH_OUTPUT_RATE_OFFSET);
        break;
    case AUDIO_FX_PARAM_MODULATION_DEPTH:
        effect->delay[section].modulationGain = (((f32)value) / D_8010C5E0) * (effect->delay[section].output - effect->delay[section].input);
        break;
    case AUDIO_FX_PARAM_LOW_PASS_CUTOFF:
        if (effect->delay[section].lowPass != NULL) {
            effect->delay[section].lowPass->cutoff = value;
            func_801C7EB0((s16 *)effect->delay[section].lowPass);
        }
        break;
    }
    return 0;
}

u32 *func_801CAA34(s32 *effectMemory, AudioEffectDelay *delay, s32 outputBuffer, s32 sampleCount, u32 *commandList) {
    AudioCommand *commands = (AudioCommand *)commandList;
    s32 ratioFixed, inputCount, resampleBuffer = AUDIO_FX_DMEM_RESAMPLE_INPUT;
    s16 *delayOutput;
    f32 fractionalCount, resampleRatio, modulation;
    s32 alignmentSamples = 0, delayLength;

    /* Load a delay section into DMEM, resampling modulated output and retaining fractional samples. */
    if (delay->resampler) {
        delayLength = delay->output - delay->input;
        modulation = func_801CAFC8((u8 *)delay, sampleCount);
        modulation /= delayLength;
        modulation = (s32)(modulation * AUDIO_RESAMPLE_RATIO_SCALE);
        modulation = modulation / AUDIO_RESAMPLE_RATIO_SCALE;
        resampleRatio = D_8010C5F0 - modulation;

        fractionalCount = delay->resampler->delta + (resampleRatio * (f32)sampleCount);
        inputCount = (s32)fractionalCount;
        delay->resampler->delta = fractionalCount - (f32)inputCount;

        delayOutput = &((AudioEffect *)effectMemory)->input[-(delay->output - delay->resampleDelta)];
        alignmentSamples = ((s32)delayOutput & AUDIO_DMA_ALIGNMENT_MASK) >> 1;

        commands = (AudioCommand *)func_801CAC4C(effectMemory, (s32)(delayOutput - alignmentSamples), resampleBuffer, inputCount + alignmentSamples, (u32 *)commands);

        ratioFixed = (s32)(resampleRatio * AUDIO_RESAMPLE_RATIO_SCALE);
        {
            AudioCommand *command = (AudioCommand *)commands++;
            command->w0 = ((((u32)AUDIO_OPCODE_SET_BUFFER & 0xFF) << 24) | (((u32)0 & 0xFF) << 16) | (((u32)(resampleBuffer + (alignmentSamples << 1)) & 0xFFFF) << 0));
            command->w1 = (((u32)outputBuffer & 0xFFFF) << 16) | (((u32)(sampleCount << 1) & 0xFFFF) << 0);
        }
        {
            AudioCommand *command = (AudioCommand *)commands++;
            command->w0 = ((((u32)AUDIO_OPCODE_RESAMPLE & 0xFF) << 24) | (((u32)delay->resampler->first & 0xFF) << 16) | (((u32)ratioFixed & 0xFFFF) << 0));
            command->w1 = (u32)(func_801C7D90((u32)delay->resampler->state));
        }

        delay->resampler->first = 0;
        delay->resampleDelta += inputCount - sampleCount;
    } else {
        delayOutput = &((AudioEffect *)effectMemory)->input[-delay->output];
        commands = (AudioCommand *)func_801CAC4C(effectMemory, (s32)delayOutput, outputBuffer, sampleCount, (u32 *)commands);
    }

    return (u32 *)commands;
}

u32 *func_801CAC4C(s32 *effectMemory, s32 delayAddress, s32 dmemBuffer, s32 sampleCount, u32 *commandList) {
    /* audio_fx_load_buffer: load a circular delay segment into RSP DMEM, splitting at the buffer end. */
    AudioCommand *commands = (AudioCommand *)commandList;
    s32 samplesAfterEnd, samplesBeforeEnd;
    s16 *readPosition = (s16 *)delayAddress;
    s16 *readEnd, *delayEnd;

    delayEnd = &((AudioEffect *)effectMemory)->base[(s32)((AudioEffect *)effectMemory)->length];

    if (readPosition < (s16 *)((AudioEffect *)effectMemory)->base)
        readPosition += (s32)((AudioEffect *)effectMemory)->length;
    readEnd = readPosition + sampleCount;

    if (readEnd > delayEnd) {
        samplesAfterEnd = readEnd - delayEnd;
        samplesBeforeEnd = delayEnd - readPosition;

        { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_SET_BUFFER | (dmemBuffer & AUDIO_COMMAND_HALFWORD_MASK); command->w1 = (samplesBeforeEnd << 1) & AUDIO_COMMAND_HALFWORD_MASK; }
        { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_LOAD_BUFFER; command->w1 = func_801C7D90((u32)readPosition); }
        { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_SET_BUFFER | ((dmemBuffer + (samplesBeforeEnd << 1)) & AUDIO_COMMAND_HALFWORD_MASK); command->w1 = (samplesAfterEnd << 1) & AUDIO_COMMAND_HALFWORD_MASK; }
        { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_LOAD_BUFFER; command->w1 = func_801C7D90((s32)((AudioEffect *)effectMemory)->base); }
    } else {
        { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_SET_BUFFER | (dmemBuffer & AUDIO_COMMAND_HALFWORD_MASK); command->w1 = (sampleCount << 1) & AUDIO_COMMAND_HALFWORD_MASK; }
        { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_LOAD_BUFFER; command->w1 = func_801C7D90((u32)readPosition); }
    }

    { AudioCommand *command = commands++; command->w0 = AUDIO_CMD_SET_BUFFER; command->w1 = (sampleCount << 1) & AUDIO_COMMAND_HALFWORD_MASK; }

    return (u32 *)commands;
}

u32 *func_801CADBC(s32 *effectMemory, s32 delayAddress, s32 dmemBuffer, s32 sampleCount, u32 *commandList)
{
    /* audio_fx_save_buffer: save RSP DMEM samples into the circular delay buffer, splitting at its end. */
    u32 *commands = commandList;
    s32 samplesAfterEnd, samplesBeforeEnd;
    s16 *writeEnd, *delayEnd;
    s16 *writePosition = (s16 *)delayAddress;

    delayEnd = &((AudioEffect *)effectMemory)->base[(s32)((AudioEffect *)effectMemory)->length];
    if (writePosition < (s16 *)((AudioEffect *)effectMemory)->base) {
        writePosition += (s32)((AudioEffect *)effectMemory)->length;
    }
    writeEnd = writePosition + sampleCount;

    if (delayEnd < writeEnd) {
        samplesAfterEnd = writeEnd - delayEnd;
        samplesBeforeEnd = delayEnd - writePosition;

        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SET_BUFFER;
            command[1] = (dmemBuffer << 16) | ((samplesBeforeEnd << 1) & AUDIO_COMMAND_HALFWORD_MASK);
        }
        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SAVE_BUFFER;
            command[1] = func_801C7D90(writePosition);
        }
        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SET_BUFFER;
            command[1] = ((dmemBuffer + (samplesBeforeEnd << 1)) << 16) | ((samplesAfterEnd << 1) & AUDIO_COMMAND_HALFWORD_MASK);
        }
        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SAVE_BUFFER;
            command[1] = func_801C7D90((s32)((AudioEffect *)effectMemory)->base);
        }
        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SET_BUFFER;
            command[1] = (sampleCount << 1) & AUDIO_COMMAND_HALFWORD_MASK;
        }
    } else {
        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SET_BUFFER;
            command[1] = (dmemBuffer << 16) | ((sampleCount << 1) & AUDIO_COMMAND_HALFWORD_MASK);
        }
        {
            u32 *command = commands;
            commands += 2;
            command[0] = AUDIO_CMD_SAVE_BUFFER;
            command[1] = func_801C7D90((u32)writePosition);
        }
    }
    return commands;
}

/* libultra _filterBuffer: emit RSP commands that run the delay line's
 * one-pole low-pass filter over `sampleCount` samples in DMEM at `buffer`.
 * func_801C7D90 is osVirtualToPhysical. */
u8 *func_801CAF2C(u8 *lowPassMemory, u32 bufferArg, u32 countArg, u8 *commandList) {
    AudioEffectLowPass *lowPass = (AudioEffectLowPass *)lowPassMemory;
    s32 buffer = bufferArg;
    s32 sampleCount = countArg;
    AudioCommand *commands = (AudioCommand *)commandList;

    {
        AudioCommand *command = (AudioCommand *)commands++;
        command->w0 = (AUDIO_CMD_SET_BUFFER | (((u32)0 & 0xFF) << 16) | (((u32)buffer & 0xFFFF) << 0));
        command->w1 = (((u32)buffer & 0xFFFF) << 16) | (((u32)(sampleCount << 1) & 0xFFFF) << 0);
    }
    {
        AudioCommand *command = (AudioCommand *)commands++;
        command->w0 = AUDIO_CMD_LOAD_ADPCM | (((u32)32 & 0xFFFFFF) << 0);
        command->w1 = (u32)func_801C7D90((u32)lowPass->coefficients.values);
    }
    {
        AudioCommand *command = (AudioCommand *)commands++;
        command->w0 = (AUDIO_CMD_POLE_FILTER | (((u32)lowPass->first & 0xFF) << 16) | (((u32)lowPass->gain & 0xFFFF) << 0));
        command->w1 = (u32)(func_801C7D90((u32)lowPass->state));
    }
    lowPass->first = 0;

    return (u8 *)commands;
}

extern const f64 D_8010C5F8;
extern const f64 D_8010C600;
extern const f64 D_8010C608;
extern const f64 D_8010C5F8, D_8010C600, D_8010C608;
/* libaudio reverb _doModFunc: advances the delay's modulation phase by
 * `count` samples (wrapping past 2.0 by 4.0) and returns its triangle wave
 * (|phase| - 1.0) scaled by the modulation depth. */
f32 func_801CAFC8(u8 *delay, s32 count) {
    extern const f64 D_8010C5F8, D_8010C600, D_8010C608; /* 2.0, 4.0, 1.0 */
#define d ((ALDelay *)delay)
    f32 val;
    d->rsval += d->rsinc * count;
    d->rsval = (d->rsval > D_8010C5F8) ? d->rsval - D_8010C600 : d->rsval;
    val = d->rsval;
    val = (val < 0) ? -val : val;
    val -= D_8010C608;
    return d->rsgain * val;
#undef d
}

/* Original compiler padding. */
const u32 D_801CB054_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* alSavePull: pull the main mix, interleave its left/right halves and save them to DRAM. */
u32 *func_801CB060(s32 *filter, s32 outputBuffer, s32 sampleCount, s32 sampleOffset, u32 *commandList)
{
    typedef struct { u32 w0, w1; } SvCmd;
    typedef SvCmd *(*SvHandler)(s32 *, s32, s32, s32, SvCmd *);
    SvCmd *commands = (SvCmd *)commandList;
    s32 *save = filter;
    s32 *source = (s32 *)save[AUDIO_SAVE_SOURCE_WORD];

    ((s32 *)save[AUDIO_SAVE_SOURCE_WORD]) ? ((void)0) : func_801CA030(D_8010C610, D_8010C614, AUDIO_SAVE_SOURCE_ASSERT_LINE);

    commands = (*(SvHandler)source[AUDIO_SAVE_PULL_HANDLER_WORD])(source, outputBuffer, sampleCount, sampleOffset, commands);

    {
        SvCmd *command = (SvCmd *)commands++;
        command->w0 = ((((u32)AUDIO_OP_SET_BUFFER & 0xFF) << 24) | (((u32)0 & 0xFF) << 16) | (((u32)0 & 0xFFFF) << 0));
        command->w1 = (((u32)0 & 0xFFFF) << 16) | (((u32)(sampleCount << 1) & 0xFFFF) << 0);
    }
    {
        SvCmd *command = (SvCmd *)commands++;
        command->w0 = (((u32)AUDIO_OP_INTERLEAVE & 0xFF) << 24);
        command->w1 = (((u32)AUDIO_DMEM_MAIN_LEFT & 0xFFFF) << 16) | (((u32)AUDIO_DMEM_MAIN_RIGHT & 0xFFFF) << 0);
    }
    {
        SvCmd *command = (SvCmd *)commands++;
        command->w0 = ((((u32)AUDIO_OP_SET_BUFFER & 0xFF) << 24) | (((u32)0 & 0xFF) << 16) | (((u32)0 & 0xFFFF) << 0));
        command->w1 = (((u32)0 & 0xFFFF) << 16) | (((u32)(sampleCount << 2) & 0xFFFF) << 0);
    }
    {
        SvCmd *command = (SvCmd *)commands++;
        command->w0 = (((u32)AUDIO_OP_SAVE_BUFFER & 0xFF) << 24);
        command->w1 = (u32)save[AUDIO_SAVE_DRAM_OUT_WORD];
    }
    return (u32 *)commands;
}

/* alSaveParam: sets the save filter's source filter or its DRAM output buffer. */
s32 func_801CB160(s32 *save, s32 paramID, s32 param)
{
    switch (paramID) {
    case SYNTH_FILTER_SET_SOURCE:
        save[SAVE_FILTER_SOURCE] = param;
        break;
    case SYNTH_FILTER_SET_DRAM:
        save[SAVE_FILTER_DRAM_OUT] = param;
        break;
    }
    return 0;
}

/* Original compiler padding. */
const u32 D_801CB188_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra alInit: if no audio library is running yet, make `globals` the active one
 * (D_801F46D0 = alGlobals) and build its synthesizer with func_801CB310 (alSynNew).
 * alSynNew receives the caller's a0/a1 (globals, config) unchanged. */
void func_801CB190(ObjectNode *globals)
{
    if (D_801F46D0 == NULL) {
        D_801F46D0 = globals;
        func_801CB310();
    }
}

/* libultra alClose: if the audio library is running (D_801F46D0 = alGlobals), delete its synthesizer
 * (func_801CB9A0 = alSynDelete) and clear alGlobals. */
void func_801CB1BC(s32 *synth) {
    ObjectNode *globals = D_801F46D0;
    if (globals) {
        func_801CB9A0(synth);
        D_801F46D0 = 0;
        return;
    }
}

/* alLink (libultra audio): inserts node into a doubly linked list right after `after`. */
void func_801CB1EC(ObjectNode *node, s32 *after) {
    node->next = (ObjectNode *)*after;
    node->unk004 = (s32)after; /* prev */
    if (*after != 0) {
        ((ObjectNode *)*after)->unk004 = (s32)node;
    }
    *after = (s32)node;
}

/* alUnlink: take a node out of its doubly linked list by joining its
 * neighbours (unk004 is the node's prev pointer). The node itself is left as is. */
void func_801CB20C(ObjectNode *node) {
    if (node->next != NULL) {
        node->next->unk004 = node->unk004;
    }
    if (node->unk004 != 0) {
        ((ObjectNode *)node->unk004)->next = node->next;
    }
}

/* Original compiler padding. */
const u32 D_801CB23C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* alHeapInit: set up an audio heap of `len` bytes at `base`, aligned up to
 * 16 bytes. heap[] is ALHeap { base, cur, len, count }. */
void func_801CB240(u32 *heap, u32 base, u32 len)
{
    u32 align = 16 - (base & 15);
    if (align != 16) {
        heap[0] = base + align; /* base */
    } else {
        heap[0] = base;
    }
    heap[1] = heap[0]; /* cur */
    heap[2] = len;     /* len */
    heap[3] = 0;       /* count */
}

/* Original compiler padding. */
const u32 D_801CB274_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* alHeapDBAlloc: take count * size bytes, rounded up to 16, from the audio
 * heap. Returns the block's address, or 0 when the heap has no room left.
 * file and line identify the caller in libultra's debug build; unused here. */
s32 func_801CB280(s32 file, s32 line, u32 *heap, s32 count, s32 size) {
    u32 newCurrent;
    s32 block = 0;

    newCurrent = heap[AUDIO_HEAP_CURRENT] + ((count * size + AUDIO_HEAP_ALIGN_LOW_BITS) & ~AUDIO_HEAP_ALIGN_LOW_BITS);
    if (heap[AUDIO_HEAP_BASE] + heap[AUDIO_HEAP_LENGTH] >= newCurrent) {
        block = heap[AUDIO_HEAP_CURRENT];
        heap[AUDIO_HEAP_CURRENT] = newCurrent;
    }
    return block;
}

/* Original compiler padding. */
const u32 D_801CB2C8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* alCopy: libultra audio byte copy of `count` bytes from src to dst. */
void func_801CB2D0(u8 *src, u8 *dst, s32 count)
{
    s32 i;
    for (i = 0; i < count; i++) {
        *dst++ = *src++;
    }
}

/* Original compiler padding. */
const u32 D_801CB304_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

s32 func_801CB864(AudioSynthDriver *driver, s32 micros);
s32 func_801CB8F8(s32 *arg0, s32 **arg1);
void func_801CB7D0(ObjectNode *arg0);

/* alSynNew: allocate the filter graph, physical voices, and free update records. */
void func_801CB310(s32 *synthStorage, s32 *configStorage) {
    AudioSynthDriver *driver = (AudioSynthDriver *)synthStorage;
    AudioEffectConfig *config = (AudioEffectConfig *)configStorage;
    s32 i;
    AudioPhysicalVoice *voice;
    AudioPhysicalVoice *voices;
    u32 *heap = config->heap;
    s32 *outputFilter;
    s32 sources;
    EnvStartParamAlt *updates;
    EnvStartParamAlt *update;

    driver->head = NULL;
    driver->numPVoices = config->maxPVoices;
    driver->curSamples = 0;
    driver->paramSamples = 0;
    driver->outputRate = config->outputRate;
    driver->maxOutSamples = SYNTH_FRAME_SAMPLES;
    driver->dma = (s32)config->dmaProc;

    outputFilter = (s32 *)func_801CB280(0, 0, heap, 1, SYNTH_OUTPUT_FILTER_BYTES);
    func_801C8698(outputFilter);
    driver->outputFilter = outputFilter;

    driver->auxBus = (s32 *)func_801CB280(0, 0, heap, 1, SYNTH_AUX_BUS_BYTES);
    driver->maxAuxBusses = 1;
    sources = func_801CB280(0, 0, heap, config->maxPVoices, SYNTH_SOURCE_POINTER_BYTES);
    func_801C85E0(driver->auxBus, sources, config->maxPVoices);

    driver->mainBus = (s32 *)func_801CB280(0, 0, heap, 1, SYNTH_MAIN_BUS_BYTES);
    sources = func_801CB280(0, 0, heap, config->maxPVoices, SYNTH_SOURCE_POINTER_BYTES);
    func_801C863C(driver->mainBus, sources, config->maxPVoices);

    if (config->fxType != 0) {
        func_801CBF70((s32 *)driver, 0, (s32)config, (s32)heap);
    } else
        func_801CA1A0(driver->mainBus, SYNTH_BUS_ADD_SOURCE, (s32)&driver->auxBus[0]);

    driver->pFreeList.next = 0;
    driver->pFreeList.prev = 0;
    driver->pLameList.next = 0;
    driver->pLameList.prev = 0;
    driver->pAllocList.next = 0;
    driver->pAllocList.prev = 0;

    voices = (AudioPhysicalVoice *)func_801CB280(0, 0, heap, config->maxPVoices, SYNTH_PHYSICAL_VOICE_BYTES);
    for (i = 0; i < config->maxPVoices; i++) {
        voice = &voices[i];
        func_801CB1EC((ObjectNode *)voice, (s32 *)&driver->pFreeList);
        voice->virtualVoice = 0;

        func_801C84A4(voice->decoder, (s32 (*)(s32 *))driver->dma, heap);
        func_801C8EC0(voice->decoder, SYNTH_FILTER_SET_SOURCE, 0);

        func_801C8554(voice->resampler, heap);
        func_801CA3BC(voice->resampler, SYNTH_FILTER_SET_SOURCE, (s32)voice->decoder);

        func_801C83EC((UnkC83EC *)voice->envelopeMixer, heap);
        func_801C984C(voice->envelopeMixer, SYNTH_FILTER_SET_SOURCE, voice->resampler);

        func_801C92CC(driver->auxBus, SYNTH_BUS_ADD_SOURCE, (s32)voice->envelopeMixer);

        voice->channelKnob = (s32)voice->envelopeMixer;
    }

    func_801CB160(outputFilter, SYNTH_FILTER_SET_SOURCE, (s32)driver->mainBus);

    updates = (EnvStartParamAlt *)func_801CB280(0, 0, heap, config->maxUpdates, SYNTH_PARAM_RECORD_BYTES);
    driver->paramList = 0;
    for (i = 0; i < config->maxUpdates; i++) {
        update = &updates[i];
        *(s32 **)update = driver->paramList;
        driver->paramList = (s32 *)update;
    }

    driver->heap = heap;
}

/* Schedule audio clients, render stereo sample blocks, and collect retired voices. */
u8 *func_801CB5DC(u8 *commandList, s32 *commandCount, s32 *outputBuffer, s32 sampleCount)
{
    AudioSynthDriver *driver = (AudioSynthDriver *)D_801F46D0;
    s32 samplesRemaining = sampleCount;
    u8 *command = commandList;
    s32 *output = outputBuffer;
    s32 *client;
    s16 dmemOutput;
    s32 blockSamples;
    u8 *outputFilter;

    dmemOutput = 0;
    if (driver->head == NULL) {
        *commandCount = 0;
        return commandList;
    }

    driver->paramSamples = func_801CB8F8((s32 *)driver, &client);
    while (driver->paramSamples - driver->curSamples < samplesRemaining) {
        driver->paramSamples &= ~AUDIO_FRAME_SAMPLE_ALIGN_LOW_BITS;
        ((AudioSynthClient *)client)->nextSampleTime +=
            func_801CB864(driver,
                          ((AudioSynthClient *)client)->handler(client));
        driver->paramSamples = func_801CB8F8((s32 *)driver, &client);
    }

    driver->paramSamples &= ~AUDIO_FRAME_SAMPLE_ALIGN_LOW_BITS;
    while (samplesRemaining > 0) {
        blockSamples = driver->maxOutSamples;
        if (samplesRemaining < blockSamples) {
            blockSamples = samplesRemaining;
        }
        *(u32 *)command = AUDIO_FRAME_SEGMENT_COMMAND;
        *(u32 *)(command + 0x4) = 0;
        outputFilter = (u8 *)driver->outputFilter;
        ((AudioSynthFilter *)outputFilter)->setParam(outputFilter, AUDIO_FRAME_SET_OUTPUT_BUFFER, output);
        samplesRemaining -= blockSamples;
        command = ((AudioSynthFilter *)outputFilter)->pull(
            outputFilter, &dmemOutput, blockSamples, driver->curSamples, command + AUDIO_FRAME_COMMAND_BYTES);
        driver->curSamples += blockSamples;
        output += blockSamples;
    }
    *commandCount = (command - commandList) >> AUDIO_FRAME_COMMAND_SHIFT;
    func_801CB7D0((ObjectNode *)driver);
    return command;
}

/* libultra __allocParam: pop a parameter-update record off the active synthesizer's
 * free list (D_801F46D0 = alGlobals, word SYNTH_PARAM_FREE_LIST at 0x2C); NULL if empty. */
ObjectNode *func_801CB78C(void) {
    ObjectNode *synth = D_801F46D0;
    ObjectNode *update = NULL;
    if (synth->unk02C != 0) {
        update = (ObjectNode *)synth->unk02C;
        synth->unk02C = (s32)update->next;
        update->next = NULL;
    }
    return update;
}

/* libultra __freeParam: push a consumed parameter-update record back onto the
 * active synthesizer's free list (paramList). */
void func_801CB7B8(ObjectNode *param) {
    AudioSynthDriver *driver = (AudioSynthDriver *)D_801F46D0;

    param->next = (ObjectNode *)driver->paramList;
    driver->paramList = (s32 *)param;
}

/* _collectPVoices: move every retired ("lame") physical voice back to the synth's free list
 * (func_801CB20C = alUnlink, func_801CB1EC = alLink). */
void func_801CB7D0(ObjectNode *synth)
{
    AudioSynthDriver *driver = (AudioSynthDriver *)synth;
    ObjectNode *voice;

    while ((voice = (ObjectNode *)driver->pLameList.next) != NULL) {
        func_801CB20C(voice);
        func_801CB1EC(voice, (s32 *)&driver->pFreeList);
    }
}

/* libultra _freePVoice: move a physical voice from its list to the synth's pLameList (+0x14), freed next frame. */
void func_801CB824(ObjectNode *synth, ObjectNode *pvoice)
{
    func_801CB20C(pvoice);                    /* alUnlink */
    func_801CB1EC(pvoice, &synth->unk014);    /* alLink(&pvoice->node, &synth->pLameList) */
}

extern f64 D_8010C620;
extern f64 D_8010C628;
/* _timeToSamplesNoRound (libultra synthesizer.c): convert a time in microseconds to a count
 * of output-rate samples, rounded to the nearest sample but not aligned to a 16-sample frame
 * (D_8010C620 = 1000000.0, D_8010C628 = 0.5). */
s32 func_801CB864(AudioSynthDriver *driver, s32 micros)
{
    f32 samples = ((f32)micros) * driver->outputRate / D_8010C620 + D_8010C628;

    return (s32)samples;
}

extern f64 D_8010C630;
extern f64 D_8010C638;
s32 func_801CB8AC(AudioSynthDriver *driver, s32 micros) { /* _timeToSamples: microseconds to output samples, rounded (D_8010C630 = 1000000.0, D_8010C638 = 0.5) and aligned down to a 16-sample boundary. */
    f32 tmp = (f32)micros * (f32)driver->outputRate;
    return (s32)(f32)(tmp / D_8010C630 + D_8010C638) & ~AUDIO_FRAME_SAMPLE_ALIGN_LOW_BITS;
}

/* __nextSampleTime (libultra synthesizer.c): find the player in the synth's
 * client list (drvr[0] = head, drvr[8] = curSamples) whose next callback
 * (player[4] = samplesLeft) comes soonest; store it in *client and return its
 * samplesLeft. func_801CA030 is the assert(drvr->head) failure at line 307. */
s32 func_801CB8F8(s32 *drvr, s32 **client) {
    s32 *player;
    s32 delta = 0x7FFFFFFF;

    if (*drvr == 0) {
        func_801CA030(D_8010C640, D_8010C644, 0x133);
    }
    *client = 0;
    for (player = (s32 *)*drvr; player != 0; player = (s32 *)player[0]) {
        if (player[4] - drvr[8] < delta) {
            *client = player;
            delta = player[4] - drvr[8];
        }
    }
    return (*client)[4];
}

/* libultra alSynDelete: detach every client player from the synthesizer
 * (drvr->head = NULL). */
void func_801CB9A0(s32 *drvr)
{
    *drvr = 0;
}

/* Original compiler padding. */
const u32 D_801CB9A8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};


/* alSynAddPlayer: with interrupts masked (func_801C63D0 is osSetIntMask),
 * push `client` onto the synthesizer's player list, starting its sample
 * countdown at the synthesizer's current sample (words: synth[0] head,
 * synth[8] curSamples; client[0] next, client[4] samplesLeft). */
void func_801CB9B0(s32 *synth, s32 *client)
{
    s32 mask;

    mask = func_801C63D0(1 /* OS_IM_NONE */);
    client[4] = synth[8];
    client[0] = synth[0];
    synth[0] = (s32)client;
    func_801C63D0(mask);
}

/* alSynAllocVoice: bind a physical voice, fading and stopping its previous owner when stolen. */
s32 func_801CBA00(u8 *synth, u8 *virtualVoice, u16 *voiceConfig) {
    u8 *driver = synth;
    AudioVirtualVoice *voice = (AudioVirtualVoice *)virtualVoice;
    AudioVoiceConfig *config = (AudioVoiceConfig *)voiceConfig;
    AudioPhysicalVoice *physicalVoice = 0;
    u8 *filter;
    EnvParam *update;
    s32 stolen;

    voice->priority = config->priority;
    voice->unityPitch = config->unityPitch;
    voice->wavetable = 0;
    voice->fxBus = config->fxBus;
    voice->state = AUDIO_VOICE_STOPPED;
    voice->physicalVoice = 0;

    stolen = func_801CBB28((ObjectNode *)driver, (s32 *)&physicalVoice, config->priority);

    if (physicalVoice) {
        filter = (u8 *)physicalVoice->channelKnob;

        if (stolen) {
            physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD] = AUDIO_VOICE_STEAL_DELAY_SAMPLES;
            *(s32 *)((u8 *)physicalVoice->virtualVoice + AUDIO_VIRTUAL_VOICE_PHYSICAL_OFFSET) = 0;

            update = (EnvParam *)func_801CB78C();
            update->delta = *(s32 *)(driver + AUDIO_SYNTH_PARAM_SAMPLES_OFFSET);
            update->type = AL_FILTER_SET_VOLUME;
            update->data = 0;
            update->moredata = physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD] - AUDIO_VOICE_STEAL_SETTLE_SAMPLES;
            (*(void (**)(u8 *, s32, EnvParam *))(filter + AUDIO_FILTER_SET_PARAM_OFFSET))(filter, AUDIO_FILTER_ADD_UPDATE, update);

            update = (EnvParam *)func_801CB78C();
            if (update) {
                update->delta = *(s32 *)(driver + AUDIO_SYNTH_PARAM_SAMPLES_OFFSET) + physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD];
                update->type = AL_FILTER_STOP_VOICE;
                update->next = 0;
                (*(void (**)(u8 *, s32, EnvParam *))(filter + AUDIO_FILTER_SET_PARAM_OFFSET))(filter, AUDIO_FILTER_ADD_UPDATE, update);
            } else {
            }
        } else {
            physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD] = 0;
        }

        physicalVoice->virtualVoice = (s32)(u8 *)voice;
        voice->physicalVoice = physicalVoice;
    }

    return (physicalVoice != 0);
}

/* _allocatePVoice: take a physical voice from the lame list, else the free
 * list, moving it to the allocated list. Failing both, pick the allocated
 * voice of lowest priority (not above `priority`) that has no pending stop
 * offset; it must be stolen, so return 1. */
s32 func_801CBB28(ObjectNode *synthData, s32 *voiceOut, s32 priority) {
    AudioSynthDriver *synth = (AudioSynthDriver *)synthData;
    AudioPhysicalVoice *voice;
    s32 stolen = 0;

    voice = (AudioPhysicalVoice *)synth->pLameList.next;
    if (voice == NULL) {
        voice = (AudioPhysicalVoice *)synth->pFreeList.next;
    }
    if (voice != NULL) {
        *voiceOut = (s32)voice;
        func_801CB20C((ObjectNode *)voice);
        func_801CB1EC((ObjectNode *)voice, (s32 *)&synth->pAllocList);
    } else {
        voice = (AudioPhysicalVoice *)synth->pAllocList.next;
        while (voice != NULL) {
            if (!((s16)priority < (s16)(u16)((AudioVirtualVoice *)voice->virtualVoice)->priority)
                && voice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD] == 0) {
                *voiceOut = (s32)voice;
                stolen = 1;
                priority = (u16)((AudioVirtualVoice *)voice->virtualVoice)->priority;
            }
            voice = (AudioPhysicalVoice *)voice->link[0];
        }
    }
    return stolen;
}

/* alSynStopVoice: queue an AL_FILTER_STOP_VOICE update (from __allocParam,
 * func_801CB78C) on the voice's physical voice channel knob, timed at the next
 * parameter sample plus the voice's pending stop offset. */
void func_801CBBE0(ObjectNode *synthData, ObjectNode *voiceData) {
    AudioVirtualVoice *voice = (AudioVirtualVoice *)voiceData;
    EnvParam *update;
    s32 delta;

    if (voice->physicalVoice == 0) {
        return;
    }
    update = (EnvParam *)func_801CB78C();
    if (update == NULL) {
        return;
    }
    delta = ((AudioSynthDriver *)synthData)->paramSamples
          + voice->physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD];
    update->type = AL_FILTER_STOP_VOICE;
    update->next = NULL;
    update->delta = delta;
    (*(void (**)(u8 *, s32, EnvParam *))((u8 *)voice->physicalVoice->channelKnob + AUDIO_FILTER_SET_PARAM_OFFSET))(
        (u8 *)voice->physicalVoice->channelKnob, AUDIO_FILTER_ADD_UPDATE, update);
}

/* Original compiler padding. */
const u32 D_801CBC5C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* alSynStartVoice: queue an AL_FILTER_START_VOICE update (wavetable, unity
 * pitch) at the voice's next sample time on its physical voice's channel knob. */
s32 func_801CBC60(u8 *synthData, u8 *voiceData, s32 wavetable)
{
    EnvParam *update;
    s32 delta;

    if (((AudioVirtualVoice *)voiceData)->physicalVoice == 0) {
        return;
    }
    update = (EnvParam *)func_801CB78C();
    if (update == 0) {
        return;
    }
    delta = ((AudioSynthDriver *)synthData)->paramSamples
          + ((AudioVirtualVoice *)voiceData)->physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD];
    *(u16 *)&update->type = AL_FILTER_START_VOICE;
    update->data = wavetable;
    update->next = 0;
    update->delta = delta;
    *(u16 *)&update->unity = *(u16 *)&((AudioVirtualVoice *)voiceData)->unityPitch;
    return ((s32 (*)(s32, s32, EnvParam *))(*(s32 *)(((AudioVirtualVoice *)voiceData)->physicalVoice->channelKnob + AUDIO_FILTER_SET_PARAM_OFFSET)))(
        ((AudioVirtualVoice *)voiceData)->physicalVoice->channelKnob, AUDIO_FILTER_ADD_UPDATE, update);
}

/* Original compiler padding. */
const u32 D_801CBCF4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* alSynSetPitch: queue a pitch-ratio change for the voice's physical voice at
 * the synthesizer's next parameter time, through its channel knob filter. */
void func_801CBD00(ObjectNode *synth, ObjectNode *voice, f32 pitch)
{
    s32 *update;
    s32 *channelKnob;

    if (voice->unk008) { /* physical voice */
        update = (s32 *)func_801CB78C(); /* __allocParam */
        if (update == 0) {
            return;
        }
        /* delta = synth->paramSamples + pvoice->offset */
        update[1] = synth->displayList + *(s32 *)((u8 *)voice->unk008 + 0xd8);
        *(s16 *)((u8 *)update + 8) = AL_FILTER_SET_PITCH; /* type */
        *(f32 *)((u8 *)update + 0xc) = pitch;             /* data */
        update[0] = 0;                                    /* next */

        channelKnob = *(s32 **)((u8 *)voice->unk008 + 0xc);
        (*(void (**)(s32 *, s32, s32 *))((u8 *)channelKnob + 8))(channelKnob, AL_FILTER_ADD_UPDATE, update);
    }
}

/* alSynSetVol: queue a volume change for a voice's physical voice, ramped over
 * `time` microseconds (converted to samples by _timeToSamples). */
void func_801CBD90(u8 *synthData, u8 *voiceData, s16 volume, s32 time)
{
    AudioSynthDriver *synth = (AudioSynthDriver *)synthData;
    AudioVirtualVoice *voice = (AudioVirtualVoice *)voiceData;
    EnvParam *update;
    AudioPhysicalVoice *physicalVoice;

    physicalVoice = voice->physicalVoice;
    if (physicalVoice != 0) {
        update = (EnvParam *)func_801CB78C();
        if (update != 0) {
            update->delta = synth->paramSamples + voice->physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD];
            update->type = AL_FILTER_SET_VOLUME;
            update->data = volume;
            update->moredata = func_801CB8AC(synthData, time);
            update->next = 0;
            ((void (*)(s32, s32, EnvParam *))(*(s32 *)(voice->physicalVoice->channelKnob + AUDIO_FILTER_SET_PARAM_OFFSET)))(
                voice->physicalVoice->channelKnob, AUDIO_FILTER_ADD_UPDATE, update);
        }
    }
}

/* Original compiler padding. */
const u32 D_801CBE48_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* alSynSetFXMix: queue a dry/wet effect-mix change for the voice's physical
 * voice at the synthesizer's next parameter time, through its channel knob. */
void func_801CBE50(u8 *synthData, u8 *voiceData, u8 fxMix)
{
    EnvParam *update;
    AudioPhysicalVoice *physicalVoice;

    physicalVoice = ((AudioVirtualVoice *)voiceData)->physicalVoice;
    if (physicalVoice != 0) {
        update = (EnvParam *)func_801CB78C(); /* __allocParam */
        if (update != 0) {
            update->delta = ((AudioSynthDriver *)synthData)->paramSamples
                          + ((AudioVirtualVoice *)voiceData)->physicalVoice->envelopeMixer[AUDIO_PHYSICAL_VOICE_OFFSET_WORD];
            update->type = AL_FILTER_SET_FX_MIX;
            update->data = fxMix;
            update->next = 0;
            ((void (*)(s32, s32, EnvParam *))(*(s32 *)(((AudioVirtualVoice *)voiceData)->physicalVoice->channelKnob + AUDIO_FILTER_SET_PARAM_OFFSET)))(
                ((AudioVirtualVoice *)voiceData)->physicalVoice->channelKnob, AL_FILTER_ADD_UPDATE, update);
        }
    }
}

/* alSynSetPan: queue a pan change for the voice's physical voice at the
 * synthesizer's next parameter time, through its channel knob filter. */
void func_801CBEE0(ObjectNode *synth, ObjectNode *voice, u8 pan)
{
    s32 *update;
    s32 *channelKnob;

    if (voice->unk008) { /* physical voice */
        update = (s32 *)func_801CB78C(); /* __allocParam */
        if (update == 0) {
            return;
        }
        /* delta = synth->paramSamples + pvoice->offset */
        update[1] = synth->displayList + *(s32 *)((u8 *)voice->unk008 + 0xd8);
        *(s16 *)((u8 *)update + 8) = AL_FILTER_SET_PAN; /* type */
        update[3] = pan;                                /* data */
        update[0] = 0;                                  /* next */

        channelKnob = *(s32 **)((u8 *)voice->unk008 + 0xc);
        (*(void (**)(s32 *, s32, s32 *))((u8 *)channelKnob + 8))(channelKnob, AL_FILTER_ADD_UPDATE, update);
    }
}

/* alSynAllocFX: build the effect on aux bus `bus`, make that bus its source,
 * add the effect to the main bus and return it. */
u8 *func_801CBF70(s32 *synth, s16 bus, s32 config, s32 heap) {
    AudioSynthAuxBus *auxBuses;
    func_801C7F54(((AudioSynthAuxBus *)synth[SYNTH_AUX_BUS])[bus].effect, config, heap);
    func_801CA830((s32 *)((AudioSynthAuxBus *)synth[SYNTH_AUX_BUS])[bus].effect, SYNTH_FILTER_SET_SOURCE, (s32)&((AudioSynthAuxBus *)synth[SYNTH_AUX_BUS])[bus]);
    func_801CA1A0((s32 *)synth[SYNTH_MAIN_BUS], SYNTH_BUS_ADD_SOURCE, (s32)((AudioSynthAuxBus *)synth[SYNTH_AUX_BUS])[bus].effect);
    return ((AudioSynthAuxBus *)synth[SYNTH_AUX_BUS])[bus].effect;
}

/* Original compiler padding. */
const u32 D_801CC004_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* libultra spColor: set the sprite's RGBA color. */
void func_801CC010(u8 *sprite, u8 red, u8 green, u8 blue, u8 alpha) {
    sprite[SPRITE_RED] = red;
    sprite[SPRITE_GREEN] = green;
    sprite[SPRITE_BLUE] = blue;
    sprite[SPRITE_ALPHA] = alpha;
}

/* Original compiler padding. */
const u32 D_801CC028_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* spClearAttribute: clear the given attribute bits (SP_SCALE, SP_TRANSPARENT, ...) of a sprite. */
void func_801CC030(u16 *sprite, u16 attr) {
    sprite[SPRITE_ATTR_HALFWORD] &= ~attr;
}

/* Original compiler padding. */
const u32 D_801CC044_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* spScale: set the sprite's x/y scale; the SP_SCALE attribute is set
 * unless both scales are exactly 1. */
void func_801CC050(f32 *sprite, f32 scaleX, f32 scaleY) {
    s32 unitX;
    s32 unitY;
    sprite[SPRITE_SCALE_X_WORD] = scaleX;
    sprite[SPRITE_SCALE_Y_WORD] = scaleY;
    unitX = (scaleX == 1.0f);
    do {
        unitY = (scaleY == 1.0f);
    } while (0);
    if (unitX & unitY) {
        func_801CC030(sprite, SP_SCALE);
    } else {
        func_801CC0D0(sprite, SP_SCALE);
    }
}

/* Original compiler padding. */
const u32 D_801CC0CC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* spSetAttribute: set the given attribute bits (SP_SCALE, SP_TRANSPARENT, ...) of a sprite. */
void func_801CC0D0(u16 *sprite, u16 attr) {
    sprite[SPRITE_ATTR_HALFWORD] |= attr;
}

/* libultra spSetZ: set the sprite's z depth. */
void func_801CC0E0(u8 *sprite, s16 z) {
    *(s16 *)(sprite + SPRITE_ZDEPTH) = z;
}

/* libultra spMove: set the sprite's screen position (s16 x at 0x00, y at 0x02). */
void func_801CC0E8(u8 *sprite, s16 x, s16 y) {
    *(s16 *)(sprite + 0) = x;
    *(s16 *)(sprite + 2) = y;
}

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

/* GBI-style helpers for func_801CC118 (same expansions as gbi.h). */
#define SPR_SHIFTL(v, s, w) ((u32) ((((u32) (v)) & ((0x01 << (w)) - 1)) << (s)))
#define SPR_GFX(pkt, a, b) { Gfx *_g = (Gfx *) ((pkt)++); _g->w0 = (a); _g->w1 = (b); }
#define SPR_SETTIMG(pkt, fmt, siz, img) SPR_GFX(pkt, SPR_SHIFTL(0xFD, 24, 8) | SPR_SHIFTL(fmt, 21, 3) | SPR_SHIFTL(siz, 19, 2) | SPR_SHIFTL(1 - 1, 0, 12), (u32) (img))
#define SPR_SETTILE(pkt, fmt, siz, line, tmem, tile, cmt, maskt, shiftt, cms, masks, shifts) \
  SPR_GFX(pkt, SPR_SHIFTL(0xF5, 24, 8) | SPR_SHIFTL(fmt, 21, 3) | SPR_SHIFTL(siz, 19, 2) | SPR_SHIFTL(line, 9, 9) | SPR_SHIFTL(tmem, 0, 9), \
    SPR_SHIFTL(tile, 24, 3) | SPR_SHIFTL(0, 20, 4) | SPR_SHIFTL(cmt, 18, 2) | SPR_SHIFTL(maskt, 14, 4) | SPR_SHIFTL(shiftt, 10, 4) | SPR_SHIFTL(cms, 8, 2) | SPR_SHIFTL(masks, 4, 4) | SPR_SHIFTL(shifts, 0, 4))
#define SPR_LOADSYNC(pkt) SPR_GFX(pkt, SPR_SHIFTL(0xE6, 24, 8), 0)
#define SPR_PIPESYNC(pkt) SPR_GFX(pkt, SPR_SHIFTL(0xE7, 24, 8), 0)
#define SPR_MIN7FF(v) (((v) < 0x7FF) ? (v) : (0x7FF))
#define SPR_TXL2W(e) ((1 > (e)) ? (1) : (e))
#define SPR_DXT(e) ((((1 << 11) + SPR_TXL2W(e)) - 1) / SPR_TXL2W(e))
#define SPR_LOADBLOCK(pkt, lrs, dxt) SPR_GFX(pkt, SPR_SHIFTL(0xF3, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12), \
    SPR_SHIFTL(7, 24, 3) | SPR_SHIFTL(SPR_MIN7FF(lrs), 12, 12) | SPR_SHIFTL(dxt, 0, 12))
#define SPR_TILESIZE(pkt, w, h) SPR_GFX(pkt, SPR_SHIFTL(0xF2, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12), \
    SPR_SHIFTL(0, 24, 3) | SPR_SHIFTL(((w) - 1) << 2, 12, 12) | SPR_SHIFTL(((h) - 1) << 2, 0, 12))

/* Set the sprite clip rectangle: left/top are inclusive (D_802AD628/62C),
 * right/bottom exclusive (D_802AD620/624). */
void func_801CC0F4(s32 left, s32 right, s32 top, s32 bottom) {
    D_802AD628 = left;
    D_802AD62C = top;
    D_802AD620 = right;
    D_802AD624 = bottom;
}

/* libultra drawbitmap helper called by spDraw (func_801CD578): clips a glyph
 * rectangle against the sprite scissor box (D_802AD628/62C/620/624), uploads
 * its bitmap to TMEM when bitmap->unk8 differs from the cached buffer D_801F46E0
 * (handling 4/8/16/32-bit, pre-swizzled SPRITE_FLAG_TEXSHUF, and 2-plane YUV),
 * and appends the textured rectangle display list commands. */
void func_801CC118(Gfx **displayListOut, SpriteText *sprite, SpriteGlyph *bitmap, s32 left, s32 top, s32 right, s32 bottom, s32 fracS, s32 fracT, s32 dsdx, s32 dtdy)
{
  SpTexRect texRectBuf;
  SpTexRect *texRect;
  s32 texWidth;
  s32 texHeight;
  s32 startS;
  s32 startT;
  s32 loadTile;
  s32 clipLeft;
  s32 clipTop;
  s32 clipRight;
  s32 clipBottom;
  s32 clampS;
  s32 clampT;
  s32 maskS;
  s32 maskT;
  s32 shiftS;
  s32 shiftT;
  Gfx *displayListCursor;

  texRect = &texRectBuf;
  displayListCursor = *displayListOut;
  texWidth = bitmap->unk2;
  texHeight = sprite->unk2E;
  if ((((left >= D_802AD620) || (top >= D_802AD624)) || (right < D_802AD628)) || (bottom < D_802AD62C))
    return;
  if (left < D_802AD628)
  {
    startS = ((bitmap->unk4 << 5) + fracS) + (((D_802AD628 - left) * dsdx) >> 5);
    clipLeft = D_802AD628 << 2;
  }
  else
  {
    startS = (bitmap->unk4 << 5) + fracS;
    clipLeft = left << 2;
  }
  if (top < D_802AD62C)
  {
    startT = ((bitmap->unk6 << 5) + fracT) + (((D_802AD62C - top) * dtdy) >> 5);
    clipTop = D_802AD62C << 2;
  }
  else
  {
    startT = (bitmap->unk6 << 5) + fracT;
    clipTop = top << 2;
  }
  if (right >= D_802AD620)
    clipRight = D_802AD620 << 2;
  else
    clipRight = right << 2;
  if (bottom >= D_802AD624)
    clipBottom = D_802AD624 << 2;
  else
    clipBottom = bottom << 2;
  clampS = SPRITE_TX_CLAMP;
  clampT = SPRITE_TX_CLAMP;
  maskS = 0;
  maskT = 0;
  shiftS = 0;
  shiftT = 0;
  if (bitmap->unk8 != D_801F46E0)
  {
    switch (sprite->siz)
    {
      case SPRITE_IM_SIZ_4b:
        if (sprite->flags & SPRITE_FLAG_TEXSHUF)
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          {
            Gfx *_g = (Gfx *) (displayListCursor++);
            _g->w0 = SPR_SHIFTL(SPRITE_G_LOADBLOCK, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12);
            loadTile = ((u32) SPRITE_TX_LOADTILE) & ((0x01 << 3) - 1);
            _g->w1 = ((u32) (loadTile << 24)) | SPR_SHIFTL(SPR_MIN7FF((((texWidth * texHeight) + 3) >> 2) - 1), 12, 12);
          }
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_4b, ((texWidth >> 1) + 7) >> 3, 0, SPRITE_TX_RENDERTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        else
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          SPR_LOADBLOCK(displayListCursor, (((texWidth * texHeight) + 3) >> 2) - 1, SPR_DXT(texWidth / 16));
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_4b, ((texWidth >> 1) + 7) >> 3, 0, SPRITE_TX_RENDERTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        break;

      case SPRITE_IM_SIZ_8b:
        if (sprite->flags & SPRITE_FLAG_TEXSHUF)
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
          loadTile = 0x01;
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          {
            Gfx *_g = (Gfx *) (displayListCursor++);
            _g->w0 = SPR_SHIFTL(SPRITE_G_LOADBLOCK, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12);
            _g->w1 = ((u32) ((((u32) SPRITE_TX_LOADTILE) & ((loadTile << 3) - 1)) << 24)) | SPR_SHIFTL(SPR_MIN7FF((((texWidth * texHeight) + 1) >> 1) - 1), 12, 12);
          }
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_8b, (texWidth + 7) >> 3, 0, SPRITE_TX_RENDERTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        else
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          SPR_LOADBLOCK(displayListCursor, (((texWidth * texHeight) + 1) >> 1) - 1, SPR_DXT(texWidth / 8));
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_8b, (texWidth + 7) >> 3, 0, SPRITE_TX_RENDERTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        break;

      case SPRITE_IM_SIZ_16b:
        if (sprite->mode == SPRITE_IM_FMT_YUV)
        {
          if (sprite->flags & SPRITE_FLAG_TEXSHUF)
          {
            SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
            SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
            SPR_LOADSYNC(displayListCursor);
            {
              Gfx *_g = (Gfx *) (displayListCursor++);
              _g->w0 = SPR_SHIFTL(SPRITE_G_LOADBLOCK, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12);
              loadTile = ((u32) SPRITE_TX_LOADTILE) & ((0x01 << 3) - 1);
              _g->w1 = ((u32) (loadTile << 24)) | SPR_SHIFTL(SPR_MIN7FF((texWidth * texHeight) - 1), 12, 12);
            }
            SPR_PIPESYNC(displayListCursor);
            SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, (texWidth + 7) >> 3, 0, SPRITE_TX_RENDERTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
            SPR_TILESIZE(displayListCursor, texWidth, texHeight);
          }
          else
            if (bitmap->unkE != 0)
          {
            u8 *chromaBase;
            u8 *rowAddr;
            s32 rowPair;
            s32 loadBytes;
            s32 tmemOffset;
            s32 rowWords;
            s32 rowOffset;
            SPR_SETTIMG(displayListCursor, SPRITE_IM_FMT_I, SPRITE_IM_SIZ_8b, bitmap->unk8);
            SPR_SETTILE(displayListCursor, SPRITE_IM_FMT_I, SPRITE_IM_SIZ_8b, 0, 0x100, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
            SPR_LOADSYNC(displayListCursor);
            SPR_LOADBLOCK(displayListCursor, (texWidth * texHeight) - 1, SPR_DXT((texWidth * 1) / 8));
            SPR_LOADSYNC(displayListCursor);
            chromaBase = ((u8 *) bitmap->unk8) + (((texWidth * texHeight) / 2) * bitmap->unkE);
            for (rowPair = 0; rowPair <= (texHeight / 2); rowPair++)
            {
              rowAddr = chromaBase + (((texHeight / 2) - (rowOffset = rowPair + 2)) * texWidth);
              loadBytes = texWidth * 3;
              rowWords = texWidth / 8;
              tmemOffset = rowWords * (texHeight - ((rowPair + 1) * 2));
              if (tmemOffset < 0)
              {
                rowAddr += (-tmemOffset) * 8;
                loadBytes -= (-tmemOffset) * 8;
                tmemOffset = 0;
              }
              if (rowPair == 0)
              {
                loadBytes = texWidth * 2;
              }
              SPR_SETTIMG(displayListCursor, SPRITE_IM_FMT_I, SPRITE_IM_SIZ_8b, rowAddr);
              SPR_SETTILE(displayListCursor, SPRITE_IM_FMT_I, SPRITE_IM_SIZ_8b, 0, tmemOffset, SPRITE_TX_LOADTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
              SPR_LOADSYNC(displayListCursor);
              SPR_LOADBLOCK(displayListCursor, loadBytes - 1, SPR_DXT((texWidth * 1) / 8));
              SPR_LOADSYNC(displayListCursor);
            }

            SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, (texWidth + 7) >> 3, 0, SPRITE_TX_RENDERTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
            SPR_TILESIZE(displayListCursor, texWidth, texHeight);
          }
          else
          {
            SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
            SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
            SPR_LOADSYNC(displayListCursor);
            SPR_LOADBLOCK(displayListCursor, (texWidth * texHeight) - 1, SPR_DXT((texWidth * 2) / 8));
            SPR_PIPESYNC(displayListCursor);
            SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, (texWidth + 7) >> 3, 0, SPRITE_TX_RENDERTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
            SPR_TILESIZE(displayListCursor, texWidth, texHeight);
          }
        }
        else
          if (sprite->flags & SPRITE_FLAG_TEXSHUF)
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          {
            Gfx *_g = (Gfx *) (displayListCursor++);
            _g->w0 = SPR_SHIFTL(SPRITE_G_LOADBLOCK, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12);
            loadTile = ((u32) SPRITE_TX_LOADTILE) & ((0x01 << 3) - 1);
            _g->w1 = ((u32) (loadTile << 24)) | SPR_SHIFTL(SPR_MIN7FF((texWidth * texHeight) - 1), 12, 12);
          }
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, ((texWidth * 2) + 7) >> 3, 0, SPRITE_TX_RENDERTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        else
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          SPR_LOADBLOCK(displayListCursor, (texWidth * texHeight) - 1, SPR_DXT((texWidth * 2) / 8));
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_16b, ((texWidth * 2) + 7) >> 3, 0, SPRITE_TX_RENDERTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        break;

      case SPRITE_IM_SIZ_32b:
        if (sprite->flags & SPRITE_FLAG_TEXSHUF)
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_32b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_32b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          {
            Gfx *_g = (Gfx *) (displayListCursor++);
            _g->w0 = SPR_SHIFTL(SPRITE_G_LOADBLOCK, 24, 8) | SPR_SHIFTL(0, 12, 12) | SPR_SHIFTL(0, 0, 12);
            loadTile = ((u32) SPRITE_TX_LOADTILE) & ((0x01 << 3) - 1);
            _g->w1 = ((u32) (loadTile << 24)) | SPR_SHIFTL(SPR_MIN7FF((texWidth * texHeight) - 1), 12, 12);
          }
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_32b, ((texWidth * 2) + 7) >> 3, 0, SPRITE_TX_RENDERTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        else
        {
          SPR_SETTIMG(displayListCursor, sprite->mode, SPRITE_IM_SIZ_32b, bitmap->unk8);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_32b, 0, 0, SPRITE_TX_LOADTILE, SPRITE_TX_CLAMP, 0, 0, SPRITE_TX_CLAMP, 0, 0);
          SPR_LOADSYNC(displayListCursor);
          SPR_LOADBLOCK(displayListCursor, (texWidth * texHeight) - 1, SPR_DXT((texWidth * 4) / 8));
          SPR_PIPESYNC(displayListCursor);
          SPR_SETTILE(displayListCursor, sprite->mode, SPRITE_IM_SIZ_32b, ((texWidth * 2) + 7) >> 3, 0, SPRITE_TX_RENDERTILE, clampT, maskT, shiftT, clampS, maskS, shiftS);
          SPR_TILESIZE(displayListCursor, texWidth, texHeight);
        }
        break;

    }

    D_801F46E0 = bitmap->unk8;
  }
  texRect->cmd = SPRITE_G_TEXRECT;
  texRect->s = startS;
  texRect->t = startT;
  texRect->tile = SPRITE_TX_RENDERTILE;
  texRect->xh = clipLeft;
  texRect->xl = clipRight;
  texRect->yh = clipTop;
  texRect->yl = clipBottom;
  if ((sprite->flags & SPRITE_FLAG_FASTCOPY) && (sprite->mode != SPRITE_IM_FMT_YUV))
    texRect->dsdx = dsdx << 2;
  else
    texRect->dsdx = dsdx;
  texRect->dtdy = dtdy;
  {
    Gfx *_g = (Gfx *) displayListCursor++;
    _g->w0 = SPR_SHIFTL(SPRITE_G_TEXRECT, 24, 8) | SPR_SHIFTL(texRect->xl, 12, 12) | SPR_SHIFTL(texRect->yl, 0, 12);
    _g->w1 = SPR_SHIFTL(texRect->tile, 24, 3) | SPR_SHIFTL(texRect->xh, 12, 12) | SPR_SHIFTL(texRect->yh, 0, 12);
  }
  {
    Gfx *_g = (Gfx *) displayListCursor++;
    _g->w0 = SPRITE_G_RDPHALF_1;
    _g->w1 = (texRect->s << 16) | texRect->t;
  }
  {
    Gfx *_g = (Gfx *) displayListCursor++;
    _g->w0 = SPRITE_G_RDPHALF_2;
    _g->w1 = (texRect->dsdx << 16) | texRect->dtdy;
  }
  SPR_PIPESYNC(displayListCursor);
  *displayListOut = displayListCursor;
}

void func_801CD3C0(Gfx **displayList) {
    Gfx *nextCommand = *displayList;
    Gfx *pipeSync, *cycleType, *textureScale, *alphaCompare, *texturePerspective;
    Gfx *textureFilter, *textureConvert, *textureDetail, *textureLod, *textureLut, *renderMode;

    /* Initialize sprite clipping and rendering state, advancing the display list. */
    D_802AD620 = SPRITE_DEFAULT_CLIP_RIGHT;
    D_802AD624 = SPRITE_DEFAULT_CLIP_BOTTOM;
    D_801F46E4 = 0;
    D_802AD628 = 0;
    D_802AD62C = 0;
    pipeSync = nextCommand++;
    cycleType = nextCommand++;
    textureScale = nextCommand++;
    alphaCompare = nextCommand++;
    texturePerspective = nextCommand++;
    textureFilter = nextCommand++;
    textureConvert = nextCommand++;
    textureDetail = nextCommand++;
    textureLod = nextCommand++;
    textureLut = nextCommand++;
    renderMode = nextCommand++;
    pipeSync->w0 = GFX_CMD_PIPE_SYNC;
    pipeSync->w1 = 0;
    cycleType->w0 = GFX_CMD_SET_CYCLE_TYPE;
    cycleType->w1 = GFX_CYCLE_ONE;
    textureScale->w0 = GFX_CMD_TEXTURE_ON_LEVEL0;
    textureScale->w1 = GFX_TEXTURE_SCALE_HALF_ST;
    alphaCompare->w0 = GFX_CMD_SET_ALPHA_COMPARE;
    alphaCompare->w1 = GFX_ALPHA_COMPARE_NONE;
    texturePerspective->w0 = GFX_CMD_SET_TEXTURE_PERSP;
    texturePerspective->w1 = GFX_TEXTURE_PERSP_NONE;
    textureFilter->w0 = GFX_CMD_SET_TEXTURE_FILTER;
    textureFilter->w1 = GFX_TEXTURE_FILTER_BILERP;
    textureConvert->w0 = GFX_CMD_SET_TEXTURE_CONVERT;
    textureConvert->w1 = GFX_TEXTURE_CONVERT_FILTER;
    textureDetail->w0 = GFX_CMD_SET_TEXTURE_DETAIL;
    textureDetail->w1 = GFX_TEXTURE_DETAIL_CLAMP;
    textureLod->w0 = GFX_CMD_SET_TEXTURE_LOD;
    textureLod->w1 = GFX_TEXTURE_LOD_TILE;
    textureLut->w0 = GFX_CMD_SET_TEXTURE_LUT;
    textureLut->w1 = GFX_TEXTURE_LUT_NONE;
    renderMode->w0 = GFX_CMD_SET_RENDER_MODE;
    renderMode->w1 = SPRITE_DEFAULT_RENDER_MODE;
    *displayList = nextCommand;
}

extern s32 D_801F46E0;
extern u8 D_8010C660[];
extern u8 D_8010C664[];
void func_801CC118(Gfx **, SpriteText *, SpriteGlyph *, s32, s32, s32, s32, s32, s32, s32, s32);
/* libultra-style spDraw: builds the display list for a SpriteText (render-mode changes against the cached
 * flags in D_801F46E4, color, combiner, optional TLUT), then one textured rectangle per glyph (wrapping at
 * s->right, stopping at s->bottom), or a clipped fill rectangle when there are no glyphs.
 * D_802AD620/624 = clip right/bottom (exclusive), D_802AD628/62C = clip left/top; func_801CC118 draws one glyph.
 * Returns the start of the list and leaves s->buf1 at its end. */
Gfx *func_801CD578(SpriteText *s)
{
    Gfx *dl;
    Gfx *start;
    Gfx *ret;
    SpriteGlyph *glyph;
    f32 sx, sy;
    f32 fx, fy;
    s32 dsdx, dtdy;
    s32 xAcc, yAcc;
    s32 x0, y0, x1, y1;
    s32 sFrac, tFrac;
    s32 xSpace, ySpace;
    s32 i, h;
    s32 rowEnd, colEnd;
    u32 fillColor;

    if (s->flags & 4) {
        return NULL;
    }
    dl = s->buf1;
    D_801F46E0 = 0;
    if (dl == NULL) {
        dl = s->buf0;
    }
    glyph = s->glyphs;
    xSpace = 0;
    ret = dl;
    ySpace = 0;
    start = ret;
    if (D_801F46E4 & 0x400) {
        D_801F46E4 = ~s->flags;
    }
    if (s->flags & 0x400) {
        D_801F46E4 = s->flags;
    }
    if (s->flags != D_801F46E4) {
        if (s->flags & 1) {
            if (!(D_801F46E4 & 1)) {
                Gfx *p = dl++;
                p->w0 = 0xB900031D;
                p->w1 = 0x504240;
            }
        } else if (D_801F46E4 & 1) {
            Gfx *p = dl++;
            p->w0 = 0xB900031D;
            p->w1 = 0x0F0A7008;
        }
        if (s->flags & 2) {
            if (!(D_801F46E4 & 2)) {
                Gfx *p = dl++;
                Gfx *q;
                p->w0 = 0xF9000000;
                p->w1 = 0xFFFFFF01;
                q = dl++;
                q->w0 = 0xB9000002;
                q->w1 = 1;
            }
        } else if (D_801F46E4 & 2) {
            Gfx *p = dl++;
            p->w0 = 0xB9000002;
            p->w1 = 0;
        }
        if (s->flags & 0x80) {
            if (!(D_801F46E4 & 0x80)) {
                Gfx *p = dl++;
                p->w0 = 0xBA000C02;
                p->w1 = 0x3000;
            }
        } else if (D_801F46E4 & 0x80) {
            Gfx *p = dl++;
            p->w0 = 0xBA000C02;
            p->w1 = 0x2000;
        }
    }
    if ((D_801F46E4 = s->flags) & 8) {
        Gfx *p = dl++;
        p->w0 = 0xEE000000;
        p->w1 = s->unk16 << 16;
    }
    {
        Gfx *p = dl++;
        p->w0 = 0xFA000000;
        p->w1 = (s->r << 24) | (s->g << 16) | (s->b << 8) | s->a;
    }
    if (s->mode == 3 || s->mode == 4) {
        if (s->a == 0xFF) {
            Gfx *p = dl++;
            p->w0 = 0xFC11FE23;
            p->w1 = 0xFFFFF3F9;
        } else {
            Gfx *p = dl++;
            p->w0 = 0xFC119623;
            p->w1 = 0xFF2FFFFF;
        }
    } else if (s->a == 0xFF) {
        Gfx *p = dl++;
        p->w0 = 0xFC11FE23;
        p->w1 = 0xFFFFF3F9;
    } else {
        Gfx *p = dl++;
        p->w0 = 0xFC119623;
        p->w1 = 0xFF2FFFFF;
    }
    if (s->mode == 2) {
        /* color-indexed: load the palette */
        Gfx *g0, *g1, *g2, *g3, *g4, *g5, *g6, *g7;
        g0 = dl++;
        g0->w0 = 0xBA000E02;
        g0->w1 = 0x8000;
        g1 = dl++;
        g1->w0 = 0xFD100000;
        g1->w1 = s->unk20;
        g2 = dl++;
        g2->w0 = 0xE8000000;
        g2->w1 = 0;
        g3 = dl++;
        g3->w0 = 0xF5000000 | ((s->unk1C + 0x100) & 0x1FF);
        g3->w1 = 0x07000000;
        g4 = dl++;
        g4->w0 = 0xE6000000;
        g4->w1 = 0;
        g5 = dl++;
        g5->w0 = 0xF0000000;
        g5->w1 = 0x07000000 | (((s->unk1E - 1) & 0x3FF) << 14);
        g6 = dl++;
        g6->w0 = 0xE7000000;
        g6->w1 = 0;
        g7 = dl++;
        g7->w0 = 0xE6000000;
        g7->w1 = 0;
    }
    if (s->mode == 1) {
        if (s->flags & 0x20) {
            Gfx *g0;
            Gfx *g1;
            Gfx *g2;
            Gfx *g3;
            g0 = dl++;
            g0->w0 = 0xBA000903;
            g0->w1 = 0;
            g1 = dl++;
            g1->w0 = 0xBA000C02;
            g1->w1 = 0;
            g2 = dl++;
            g2->w0 = 0xFC17FE2F;
            g2->w1 = 0x77FCF87C;
            g3 = dl++;
            g3->w0 = 0xEC15FD5D;
            g3->w1 = 0x3B78E42A;
        } else {
            Gfx *g0;
            Gfx *g1;
            Gfx *g2;
            Gfx *g3;
            Gfx *g4;
            g0 = dl++;
            g0->w0 = 0xBA001402;
            g0->w1 = 0x100000;
            g1 = dl++;
            g1->w0 = 0xBA000C02;
            g1->w1 = 0x2000;
            g2 = dl++;
            g2->w0 = 0xBA000903;
            g2->w1 = 0xA00;
            g3 = dl++;
            g3->w0 = 0xEC15FD5D;
            g3->w1 = 0x3B78E42A;
            g4 = dl++;
            g4->w0 = 0xFC27FFFF;
            g4->w1 = 0x7FFD7E38;
        }
    }
    if (s->flags & 0x10) {
        sx = s->scaleX;
        sy = s->scaleY;
    } else {
        sy = 1.0f;
        sx = sy;
    }
    dsdx = 1024.0f / sx + 0.5f;
    dtdy = 1024.0f / sy + 0.5f;
    if (glyph != NULL) {
        if ((s->flags & 0x20) && s->mode != 1) {
            Gfx *p = dl++;
            p->w0 = 0xBA001402;
            p->w1 = 0x200000;
        }
        yAcc = 0;
        fy = s->y + sy * yAcc;
        y0 = fy + 0.99999f;
        tFrac = dtdy * (y0 - fy);
        tFrac = (tFrac + 16) >> 5;
        xAcc = 0;
        if (s->flags & 0x80) {
            tFrac += 16;
        }
        if (s->flags & 0x100) {
            tFrac += s->unk42;
        }
        rowEnd = yAcc + s->lineH;
        y1 = s->y + rowEnd * sy + 0.99999f;
        if (s->flags & 0x20) {
            y1 -= (s->mode != 1);
        }
        for (i = yAcc; i < s->count; i++, glyph++) {
            if (glyph->w <= 0) {
                break;
            }
            if (s->right < xAcc + glyph->w) {
                /* wrap to the next row */
                yAcc += s->lineH;
                fy = s->y + yAcc * sy;
                y0 = fy + 0.9999f;
                tFrac = dtdy * (y0 - fy);
                xSpace = xAcc = 0;
                ySpace += s->ySpacing;
                tFrac = (tFrac + 16) >> 5;
                rowEnd = yAcc + s->lineH;
                if (s->flags & 0x80) {
                    tFrac += 16;
                }
                if (s->flags & 0x100) {
                    tFrac += s->unk42;
                }
                y1 = s->y + rowEnd * sy + 0.9999f;
                y0 += ySpace;
                y1 += ySpace;
                if (s->flags & 0x20) {
                    y1 -= (s->mode != 1);
                }
                h = glyph->h ? glyph->h : s->lineH;
                if (s->bottom < yAcc + h) {
                    break;
                }
            }
            fx = s->x + xAcc * sx;
            x0 = fx + 0.9999f;
            sFrac = dsdx * (x0 - fx);
            sFrac = (sFrac + 16) >> 5;
            if (s->flags & 0x80) {
                sFrac += 16;
            }
            if (s->flags & 0x100) {
                sFrac += s->unk40;
            }
            colEnd = xAcc + glyph->w;
            x1 = s->x + colEnd * sx + 0.9999f;
            if (glyph->h != 0) {
                rowEnd = yAcc + glyph->h;
                y1 = s->y + rowEnd * sy + 0.9999f;
                y1 += ySpace;
                if (s->flags & 0x20) {
                    y1 -= (s->mode != 1);
                }
            }
            x0 += xSpace;
            x1 += xSpace;
            if (s->flags & 0x20) {
                x1 -= (s->mode != 1);
            }
            if (glyph->unk8 != 0) {
                func_801CC118(&dl, s, glyph, x0, y0, x1, y1, sFrac, tFrac, dsdx, dtdy);
            }
            xAcc += glyph->w;
            xSpace += s->xSpacing;
        }
        if (s->flags & 0x20) {
            Gfx *p = dl++;
            p->w0 = 0xBA001402;
            p->w1 = 0;
        }
        if (s->mode == 1) {
            Gfx *g0;
            Gfx *g1;
            Gfx *g2;
            g0 = dl++;
            g0->w0 = 0xBA001402;
            g0->w1 = 0;
            g1 = dl++;
            g1->w0 = 0xBA000C02;
            g1->w1 = 0x2000;
            g2 = dl++;
            g2->w0 = 0xBA000903;
            g2->w1 = 0xC00;
        }
    } else {
        /* no glyphs: a fill rectangle in the sprite's color, clipped to the scissor box */
        xAcc = s->x;
        yAcc = s->y;
        colEnd = xAcc + s->right * sx - 1.0f;
        rowEnd = yAcc + s->bottom * sy - 1.0f;
        if (xAcc < D_802AD620 && yAcc < D_802AD624 && colEnd >= D_802AD628 && rowEnd >= D_802AD62C) {
            Gfx *g0, *g1, *g2, *g3, *g4, *g5;

            if (xAcc < D_802AD628) {
                xAcc = D_802AD628;
            }
            if (colEnd >= D_802AD620) {
                colEnd = D_802AD620 - 1;
            }
            if (yAcc < D_802AD62C) {
                yAcc = D_802AD62C;
            }
            if (rowEnd >= D_802AD624) {
                rowEnd = D_802AD624 - 1;
            }
            /* RGBA5551 */
            fillColor = ((s->r << 8) & 0xF800) | ((s->g << 3) & 0x7C0) | ((s->b >> 2) & 0x3E) | (s->a >> 7);
            g0 = dl++;
            g0->w0 = 0xBB000000;
            g0->w1 = 0x80008000;
            g1 = dl++;
            g1->w0 = 0xBA001402;
            g1->w1 = 0x300000;
            g2 = dl++;
            g2->w0 = 0xF7000000;
            g2->w1 = (fillColor << 16) | fillColor;
            g3 = dl++;
            g3->w0 = 0xF6000000 | ((colEnd & 0x3FF) << 14) | ((rowEnd & 0x3FF) << 2);
            g3->w1 = ((xAcc & 0x3FF) << 14) | ((yAcc & 0x3FF) << 2);
            g4 = dl++;
            g4->w0 = 0xBA001402;
            g4->w1 = 0;
            g5 = dl++;
            g5->w0 = 0xBB000001;
            g5->w1 = 0x80008000;
        }
    }
    if (s->mode == 2) {
        Gfx *p = dl++;
        p->w0 = 0xBA000E02;
        p->w1 = 0;
    }
    {
        Gfx *p = dl++;
        p->w0 = 0xB8000000;
        p->w1 = 0;
    }
    if (dl - start >= s->maxGfx) {
        func_801CA030(D_8010C660, D_8010C664, 0x2CB);
    }
    s->buf1 = dl;
    return ret;
}

/* spFinish: end sprite drawing. Turn texturing off, select shade combining,
 * undo the render mode / alpha compare that transparent or cutout sprites
 * left set (D_801F46E4 holds the last sprite flags), and end the list. */
void func_801CE22C(Gfx **displayList)
{
    Gfx *dl;

    dl = *displayList;
    {
        Gfx *texture = dl++;
        Gfx *combine = dl++;
        texture->w0 = GFX_CMD_TEXTURE_OFF;
        texture->w1 = GFX_TEXTURE_SCALE_HALF_ST;
        combine->w0 = GFX_COMBINE_DIRECT_COLOR_W0;
        combine->w1 = GFX_COMBINE_SHADE_W1;
    }
    if (D_801F46E4 & SPRITE_FLAG_TRANSPARENT) {
        Gfx *renderMode = dl++;
        renderMode->w0 = GFX_CMD_SET_RENDER_MODE;
        renderMode->w1 = SPRITE_FINISH_RENDER_MODE;
    }
    if (D_801F46E4 & SPRITE_FLAG_CUTOUT) {
        Gfx *alphaCompare = dl++;
        alphaCompare->w0 = GFX_CMD_SET_ALPHA_COMPARE;
        alphaCompare->w1 = GFX_ALPHA_COMPARE_NONE;
    }
    {
        Gfx *end = dl++;
        end->w0 = GFX_CMD_END_DISPLAY_LIST;
        end->w1 = 0;
    }
    *displayList = dl;
}

/* Original compiler padding. */
const u32 D_801CE2E4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osAiGetLength: bytes left in the audio interface's current DMA buffer. */
u32 func_801CE2F0(void)
{
    return *(volatile u32 *)AI_LEN_REG;
}

/* osAiSetFrequency: program the AI clock dividers and return the actual sample rate, or -1 if too high. */
s32 func_801CE300(s32 frequency) {
    register u32 dacDivisor;
    register u8 bitDivisor;
    register f32 roundedDacDivisor;
    roundedDacDivisor = D_801F43D8 / (f32)(u32)frequency + .5f;
    dacDivisor = roundedDacDivisor;
    if (dacDivisor <= AI_DAC_DIVISOR_REJECT_MAX) return -1;
    bitDivisor = dacDivisor / AI_BIT_CLOCKS_PER_SAMPLE;
    if (bitDivisor >= AI_BIT_DIVISOR_CLAMP_THRESHOLD) bitDivisor = AI_BIT_DIVISOR_MAX;
    *(volatile u32 *)AI_DACRATE_REG = dacDivisor - 1;
    *(volatile u32 *)AI_BITRATE_REG = bitDivisor - 1;
    *(volatile u32 *)AI_CONTROL_REG = AI_CONTROL_DMA_ON;
    return D_801F43D8 / (s32)dacDivisor;
}

/* Original compiler padding. */
const u32 D_801CE428_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* osAiSetNextBuffer: queue an audio buffer for AI DMA. D_801F46F0 is the
 * hardware-bug flag: when the previous buffer ended on an 8 KB boundary the
 * AI reads from 0x2000 too far, so the next address is moved back to compensate.
 * func_801CE4D0 is __osAiDeviceBusy, func_801C7D90 osVirtualToPhysical.
 * Returns -1 if the AI's DMA queue is full, 0 once the buffer is queued. */
s32 func_801CE430(s32 bufPtr, s32 size) {
    char *dmaPtr;
    dmaPtr = (char *)bufPtr;
    if (D_801F46F0) dmaPtr = (u8 *)bufPtr - 0x2000;
    if ((((u32)bufPtr + size) & 0x1fff) == 0) D_801F46F0 = 1;
    else D_801F46F0 = 0;
    if (func_801CE4D0()) return -1;
    *(volatile u32 *)AI_DRAM_ADDR_REG = func_801C7D90((u32)dmaPtr);
    *(volatile u32 *)AI_LEN_REG = size;
    return 0;
}

/* Original compiler padding. */
const u32 D_801CE4C4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* __osAiDeviceBusy: nonzero while the AI's DMA FIFO is full (AI_STATUS bit 31). */
s32 func_801CE4D0(void) {
    return *(volatile u32 *)AI_STATUS_REG >= 0x80000000u;
}

typedef RspTask Task801CE4F0;
extern Task801CE4F0 D_802AD630;
extern u32 D_802AD634, D_802AD640, D_802AD648, D_802AD64C, D_802AD650;
extern u32 D_802AD658, D_802AD65C, D_802AD660, D_802AD668, D_802AD66C;
void func_801D1D00(void *, void *, s32);
void func_801C6470(void *, s32);
void func_801CE750(u32);
s32 func_801CE760(u32);
s32 func_801CE790(s32, u32, u32, u32);
extern u32 D_A0000000;

/* Original compiler padding. */
const u32 D_801CE4E4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* Load the physical-address task descriptor and boot microcode into the halted RSP, restoring yielded tasks. */
void func_801CE4F0(RspTask *task) {
    RspTask *physicalTask = &D_802AD630;
    func_801D1D00(task, physicalTask, RSP_TASK_SIZE);
    if (D_802AD630.ucode) {
        D_802AD630.ucode = func_801C7D90(D_802AD630.ucode);
    }
    if (D_802AD630.ucode_data) {
        D_802AD630.ucode_data = func_801C7D90(D_802AD630.ucode_data);
    }
    if (D_802AD630.dram_stack) {
        D_802AD630.dram_stack = func_801C7D90(D_802AD630.dram_stack);
    }
    if (D_802AD630.output_buff) {
        D_802AD630.output_buff = func_801C7D90(D_802AD630.output_buff);
    }
    if (D_802AD630.output_buff_size) {
        D_802AD630.output_buff_size = func_801C7D90(D_802AD630.output_buff_size);
    }
    if (D_802AD630.data_ptr) {
        D_802AD630.data_ptr = func_801C7D90(D_802AD630.data_ptr);
    }
    if (D_802AD630.yield_data_ptr) {
        D_802AD630.yield_data_ptr = func_801C7D90(D_802AD630.yield_data_ptr);
    }
    if (D_802AD630.flags & RSP_TASK_YIELDED) {
        D_802AD630.ucode_data = D_802AD630.yield_data_ptr;
        D_802AD630.ucode_data_size = D_802AD630.yield_data_size;
        task->flags &= ~RSP_TASK_YIELDED;
        if (D_802AD630.flags & RSP_TASK_LOADABLE) {
            D_802AD630.ucode = *(u32 *)((task->yield_data_ptr + RSP_YIELD_UCODE_OFFSET) | RSP_KSEG1_BASE);
        }
    }
    func_801C6470(physicalTask, RSP_TASK_SIZE);
    func_801CE750(RSP_CLR_SIG0 | RSP_CLR_SIG1 | RSP_CLR_SIG2 | RSP_SET_INTR_BREAK);
    while ((func_801CE760)(RSP_IMEM_ADDRESS) == -1) {
    }
    while (func_801CE790(RSP_DMA_READ, RSP_TASK_DMEM_ADDRESS, (u32)physicalTask, RSP_TASK_SIZE) == -1) {
    }
    while (func_801CE730() != 0) {
    }
    while (func_801CE790(RSP_DMA_READ, RSP_IMEM_ADDRESS, physicalTask->ucode_boot, physicalTask->ucode_boot_size) == -1) {
    }
}

/* libultra osSpTaskStartGo: wait until the RSP's DMA/IO is idle (func_801CE730 =
 * __osSpDeviceBusy), then un-halt it with break interrupts on (func_801CE750 = __osSpSetStatus). */
void func_801CE6FC(void) {
    while (func_801CE730() != 0) {
    }
    func_801CE750(SP_SET_INTR_BREAK | SP_CLR_SSTEP | SP_CLR_BROKE | SP_CLR_HALT);
}

/* Original compiler padding. */
const u32 D_801CE728_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra __osSpDeviceBusy: nonzero while the RSP's DMA or IO is busy. */
s32 func_801CE730(void)
{
    return (*(volatile u32 *)SP_STATUS_REG & (SP_STATUS_DMA_BUSY | SP_STATUS_DMA_FULL | SP_STATUS_IO_FULL)) != 0;
}

/* Original compiler padding. */
const u32 D_801CE748_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra __osSpSetStatus: write the SP_SET_ / SP_CLR_ bits in `status` to the RSP status register. */
void func_801CE750(u32 status) {
    *(volatile u32 *)SP_STATUS_REG = status;
}

/* libultra __osSpSetPc: set the RSP program counter, only allowed while the RSP is halted.
 * Returns 0, or -1 if the RSP is running. */
s32 func_801CE760(u32 pc) {
    s32 ret;
    if (*(volatile u32 *)SP_STATUS_REG & SP_STATUS_HALT) {
        *(volatile u32 *)SP_PC_REG = pc;
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}


/* __osSpRawStartDma: start an RSP DMA between SP memory and RDRAM (-1 if the SP is busy).
 * func_801CE730 is __osSpDeviceBusy; func_801C7D90 is osVirtualToPhysical. */
s32 func_801CE790(s32 direction, u32 devAddr, u32 dramAddr, u32 size) {
    u32 unused;
    u32 *unusedPtr;

    if (devAddr & SP_DMA_ALIGN_MASK) {
        func_801CA030(D_8010C680, D_8010C684, 0x3A);
    }
    if (dramAddr & SP_DMA_ALIGN_MASK) {
        func_801CA030(D_8010C680, D_8010C684, 0x3B);
    }
    if (size & SP_DMA_ALIGN_MASK) {
        func_801CA030(D_8010C680, D_8010C684, 0x3C);
    }
    if (func_801CE730() != 0) {
        return -1;
    }
    *(volatile u32 *)SP_MEM_ADDR_REG = devAddr;
    *(volatile u32 *)SP_DRAM_ADDR_REG = func_801C7D90(dramAddr);
    if (direction == OS_READ) {
        *(volatile u32 *)SP_WR_LEN_REG = size - 1;
    } else {
        *(volatile u32 *)SP_RD_LEN_REG = size - 1;
    }
    return 0;
}

/* Original compiler padding. */
const u32 D_801CE888_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra osSpTaskYield: ask the running RSP task to yield by setting signal 0
 * (func_801CE750 = __osSpSetStatus). */
void func_801CE890(void) {
    s32 status = SP_SET_YIELD;
    func_801CE750(status);
}

/* Original compiler padding. */
const u32 D_801CE8AC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* osSpTaskYielded: returns 1 if the RSP task yielded; when a yield was
 * requested, records that in the task's flags and clears OS_TASK_DP_WAIT. */
u32 func_801CE8B0(Unk801F4764 *task) {
    u32 status = func_801CE900();
    u32 yielded = status >> 8;

    yielded &= 1; /* SP_STATUS_YIELDED */
    if (status & SP_STATUS_YIELD) {
        task->unk4 = (task->unk4 | yielded) & ~OS_TASK_DP_WAIT;
    }
    return yielded;
}

/* Original compiler padding. */
const u32 D_801CE8FC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* __osSpGetStatus: read the RSP status register (SP_STATUS_REG). */
u32 func_801CE900(void) {
    return *(volatile u32 *)SP_STATUS_REG;
}

/* osViGetCurrentFramebuffer: the framebuffer the VI is showing now
 * (__osViCurr->framep), read with interrupts disabled. */
s32 func_801CE910(void)
{
    s32 saveMask;
    s32 framebuffer;

    saveMask = func_801C6F70(); /* __osDisableInt */
    framebuffer = D_801F4760->unk4; /* __osViCurr->framep */
    func_801C6F90(saveMask); /* __osRestoreInt */
    return framebuffer;
}

/* Original compiler padding. */
const u32 D_801CE948_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/*
 * __osViInit: clear both VI contexts, make the next one a black screen in the
 * LAN1 mode for the console's TV type, wait for the VI to reach the top of the
 * frame, turn it off and swap the context in.
 */
void func_801CE950(void) {
    func_801D2020((u8 *)D_801F4700, 0x60); /* bzero(both contexts) */
    D_801F4760 = &D_801F4700[0]; /* __osViCurr */
    D_801F4764 = &D_801F4700[1]; /* __osViNext */
    D_801F4700[1].unk2 = 1; /* retraceCount */
    D_801F4700[0].unk2 = 1;
    D_801F4700[1].unk4 = 0x80000000; /* framebuffer = K0BASE */
    D_801F4700[0].unk4 = 0x80000000;
    if (D_80000300 == 0) { /* osTvType: PAL */
        D_801F4700[1].unk8 = (Unk801F4764 *)D_801F5520; /* osViModePalLan1 */
    } else if (D_80000300 == 2) { /* MPAL */
        D_801F4700[1].unk8 = (Unk801F4764 *)D_801F5570; /* osViModeMpalLan1 */
    } else { /* NTSC */
        D_801F4700[1].unk8 = (Unk801F4764 *)D_801F54D0; /* osViModeNtscLan1 */
    }
    D_801F4764->unk0 = VI_STATE_BLACK;
    D_801F4764->unkC = D_801F4764->unk8->unk4; /* control = mode's control register */
    while (*(volatile u32 *)0xA4400010 > 10) { /* VI_CURRENT_REG */
    }
    *(volatile u32 *)0xA4400000 = 0; /* VI_CONTROL_REG: blank */
    func_801CF0C0(); /* __osViSwapContext */
}

/* Original compiler padding. */
const u32 D_801CEA54_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* libultra: with interrupts disabled (func_801C6F70 = __osDisableInt, func_801C6F90 = __osRestoreInt),
 * read field +0x04 of the thread at D_801F4764 (OSThread.priority if that is __osRunningThread). */
u32 func_801CEA60(void)
{
    s32 savedMask = func_801C6F70();
    u32 value = D_801F4764->unk4;

    func_801C6F90(savedMask);
    return value;
}

/* Original compiler padding. */
const u32 D_801CEA98_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

void func_801CEAA0(s32 priority) {
    s32 *managerActive = &D_801F4770;
    s32 previousPriority;
    s32 savedInterruptMask;
    Thread801 *viThread;
    u16 *retraceMessage;
    u16 *counterMessage;
    s32 currentPriority;

    /* Initialize VI event delivery and start its manager thread once. */
    if (*managerActive != 0) {
        return;
    }
    func_801C7A80();
    func_801C6520((OSMesgQueue *)D_802AE830, (void **)D_802AE848, VI_MANAGER_QUEUE_CAPACITY);
    retraceMessage = &D_802AE860;
    *retraceMessage = VI_MANAGER_RETRACE_MESSAGE;
    D_802AE862 = 0;
    D_802AE864 = 0;
    counterMessage = &D_802AE878;
    *counterMessage = VI_MANAGER_COUNTER_MESSAGE;
    D_802AE87A = 0;
    D_802AE87C = 0;
    func_801C7690(VI_MANAGER_RETRACE_EVENT, (OSMesgQueue *)D_802AE830, (s32)retraceMessage);
    func_801C7690(VI_MANAGER_COUNTER_EVENT, (OSMesgQueue *)D_802AE830, (s32)counterMessage);
    previousPriority = VI_MANAGER_NO_SAVED_PRIORITY;
    currentPriority = func_801CEDD0(0);
    if (currentPriority < priority) {
        previousPriority = currentPriority;
        func_801C76F0(0, priority);
    }
    savedInterruptMask = func_801C6F70();
    viThread = (Thread801 *)D_802AD678;
    *managerActive = 1;
    D_801F4774 = (s32)D_802AD678;
    D_801F4778 = (s32)&D_802AE830[0];
    D_801F477C = (s32)&D_802AE830[0];
    D_801F4780 = 0;
    D_801F4784 = 0;
    D_801F4788 = 0;
    func_801C6550(viThread, VI_MANAGER_THREAD_ID, (u32)func_801CEC38, (s32)managerActive, (void *)((u8 *)&D_802AD630 + VI_MANAGER_STACK_TOP_OFFSET), priority);
    func_801CE950();
    func_801C7860((QNode *)viThread);
    func_801C6F90(savedInterruptMask);
    if (previousPriority != VI_MANAGER_NO_SAVED_PRIORITY) {
        func_801C76F0(0, previousPriority);
    }
}

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

void func_801CEC38(ThreadArg801CEC38 *threadArg) {
    /* Handle VI retraces and timer interrupts, notify the client, and advance system time. */
    Unk801CEDF0 *context;
    ThreadArg801CEC38 *manager;
    void *message;
    s32 resetTime;
    u32 counterDelta;

    message = NULL;
    context = func_801CEDF0();
    D_802AD670 = ((ViRetraceContextView *)context)->retraceCount;
    resetTime = 0;
    if (D_802AD670 == 0) {
        D_802AD670 = 1;
    }
    manager = threadArg;
    for (;;) {
        func_801C7430(((ViManagerThreadView *)manager)->eventQueue, &message, OS_MESG_BLOCK);
        switch (*(u16 *)message) {
        case VI_MANAGER_RETRACE_MESSAGE:
            func_801CF0C0();
            if (--D_802AD670 == 0) {
                context = func_801CEDF0();
                if (((ViRetraceContextView *)context)->messageQueue != NULL) {
                    func_801C7560(((ViRetraceContextView *)context)->messageQueue, ((ViRetraceContextView *)context)->message, VI_MANAGER_SEND_NONBLOCKING);
                }
                D_802AD670 = ((ViRetraceContextView *)context)->retraceCount;
            }
            D_802AD5E4++;
            if (resetTime != 0) {
                resetTime = 0;
                counterDelta = func_801C62B0();
                D_802AD5E8 = counterDelta;
            }
            counterDelta = D_802AD5E0;
            D_802AD5E0 = func_801C62B0();
            counterDelta = D_802AD5E0 - counterDelta;
            D_802AD5E8 += counterDelta;
            break;
        case VI_MANAGER_COUNTER_MESSAGE:
            func_801C7AD4();
            break;
        }
    }
}

/* osGetThreadPri: returns a thread's priority (field +0x04); thread 0 means
 * the running thread (D_801F4400 = __osRunningThread). */
s32 func_801CEDD0(s32 threadAddr) {
    QNode *thread = (QNode *)threadAddr;
    if (thread == 0) {
        thread = (QNode *)D_801F4400;
    }
    return thread->unk4;
}

/* Original compiler padding. */
const u32 D_801CEDE8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* __osViGetCurrentContext: returns the current VI context (D_801F4760 = __osViCurr). */
Unk801CEDF0 *func_801CEDF0(void) {
    return (Unk801CEDF0 *)D_801F4760;
}

/* Original compiler padding. */
const u32 D_801CEDFC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* osViSetEvent: with interrupts off, make the next VI context send msg to msgQueue
 * every retraceCount vertical retraces. */
void func_801CEE00(s32 msgQueue, s32 msg, u16 retraceCount)
{
    s32 savedMask;

    savedMask = func_801C6F70(); /* __osDisableInt */
    ((ViContextView *)D_801F4764)->msgQueue = (void *)msgQueue; /* D_801F4764 = __osViNext */
    ((ViContextView *)D_801F4764)->msg = (void *)msg;
    ((ViContextView *)D_801F4764)->retraceCount = retraceCount;
    func_801C6F90(savedMask); /* __osRestoreInt */
}

/* Original compiler padding. */
const u32 D_801CEE58_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* osViSetMode: with interrupts off, make `mode` the next VI context's video mode,
 * flag the context so every VI register is reloaded, and take the mode's control word. */
void func_801CEE60(Unk801F4764 *mode)
{
    s32 savedMask;

    savedMask = func_801C6F70(); /* __osDisableInt */
    ((ViContextView *)D_801F4764)->mode = mode; /* D_801F4764 = __osViNext */
    ((ViContextView *)D_801F4764)->state = VI_STATE_MODE_UPDATED;
    ((ViContextView *)D_801F4764)->control = ((UnkViMode *)((ViContextView *)D_801F4764)->mode)->control;
    func_801C6F90(savedMask); /* __osRestoreInt */
}

/* Original compiler padding. */
const u32 D_801CEEAC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* Update the pending VI context's gamma and filtering features with interrupts disabled. */
void func_801CEEB0(s32 features) {
    s32 interruptState = func_801C6F70();

    if (features & OS_VI_GAMMA_ON) {
        ((ViContextView *)D_801F4764)->control |= VI_CTRL_GAMMA_ON;
    }
    if (features & OS_VI_GAMMA_OFF) {
        ((ViContextView *)D_801F4764)->control &= ~VI_CTRL_GAMMA_ON;
    }
    if (features & OS_VI_GAMMA_DITHER_ON) {
        ((ViContextView *)D_801F4764)->control |= VI_CTRL_GAMMA_DITHER_ON;
    }
    if (features & OS_VI_GAMMA_DITHER_OFF) {
        ((ViContextView *)D_801F4764)->control &= ~VI_CTRL_GAMMA_DITHER_ON;
    }
    if (features & OS_VI_DIVOT_ON) {
        ((ViContextView *)D_801F4764)->control |= VI_CTRL_DIVOT_ON;
    }
    if (features & OS_VI_DIVOT_OFF) {
        ((ViContextView *)D_801F4764)->control &= ~VI_CTRL_DIVOT_ON;
    }
    if (features & OS_VI_DITHER_FILTER_ON) {
        ((ViContextView *)D_801F4764)->control = (((ViContextView *)D_801F4764)->control | VI_CTRL_DITHER_FILTER_ON) & ~VI_CTRL_ANTIALIAS_MASK;
    }
    if (features & OS_VI_DITHER_FILTER_OFF) {
        ((ViContextView *)D_801F4764)->control &= (u32)~VI_CTRL_DITHER_FILTER_ON;
        ((ViContextView *)D_801F4764)->control |= ((UnkViMode *)((ViContextView *)D_801F4764)->mode)->control & VI_CTRL_ANTIALIAS_MASK;
    }
    ((ViContextView *)D_801F4764)->state |= VI_STATE_CONTROL;
    func_801C6F90(interruptState);
}

/* Original compiler padding. */
const u32 D_801CF014_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osViSetYScale: set the next VI context's vertical scale factor (unk24 = y.factor) and mark it updated (state |= VI_STATE_YSCALE_UPDATED, 4). */
void func_801CF020(f32 yScale) {
    s32 savedMask;

    savedMask = func_801C6F70();
    D_801F4764->unk0 |= 4;
    D_801F4764->unk24 = yScale;
    func_801C6F90(savedMask);
}

/* Original compiler padding. */
const u32 D_801CF064_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osViSwapBuffer: show frameBuffer on the next retrace (next VI context's framep = unk4, state |= VI_STATE_BUFFER_UPDATED, 0x10). */
void func_801CF070(u32 frameBuffer)
{
    u32 savedMask;

    savedMask = func_801C6F70();
    D_801F4764->unk0 |= 0x10;
    D_801F4764->unk4 = frameBuffer;
    func_801C6F90(savedMask);
}

/* Original compiler padding. */
const u32 D_801CF0B4_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

extern volatile u32 D_A4400000;
void func_801CF0C0(void) {
    /* Apply the pending VI mode for this field, then swap and copy the contexts. */
    register UnkViMode *mode;
    register ViContextView *nextContext;
    u32 origin, horizontalStart, nominalYScale, field;

    field = 0;
    nextContext = (ViContextView *)D_801F4764;
    mode = (UnkViMode *)nextContext->mode;
    field = *(volatile u32 *)VI_CURRENT_REG & 1;
    origin = func_801C7D90(nextContext->framebuffer) + mode->fld[field].origin;
    if (nextContext->state & VI_STATE_XSCALE) {
        nextContext->xScale |= mode->xScale & ~VI_SCALE_MASK;
    } else {
        nextContext->xScale = mode->xScale;
    }
    if (nextContext->state & VI_STATE_YSCALE) {
        nominalYScale = mode->fld[field].yScale & VI_SCALE_MASK;
        {
            f32 scaledY = nextContext->yScaleFactor * nominalYScale;
            {
                f64 scaledYDouble = scaledY;
                scaledY = scaledYDouble;
            }
            nextContext->yScale = (u32)scaledY;
        }
        nextContext->yScale |= mode->fld[field].yScale & ~VI_SCALE_MASK;
    } else {
        nextContext->yScale = mode->fld[field].yScale;
    }
    horizontalStart = mode->hStart;
    if (nextContext->state & VI_STATE_BLACK) {
        horizontalStart = 0;
    }
    if (nextContext->state & VI_STATE_REPEAT_LINE) {
        nextContext->yScale = 0;
        origin = func_801C7D90(nextContext->framebuffer);
    }
    if (nextContext->state & VI_STATE_FADE) {
        nextContext->yScale = (nextContext->yOffset << VI_Y_OFFSET_SHIFT) & (VI_Y_OFFSET_MASK << VI_Y_OFFSET_SHIFT);
        origin = func_801C7D90(nextContext->framebuffer);
    }
    *(volatile u32 *)VI_ORIGIN_REG = origin;
    *(volatile u32 *)VI_WIDTH_REG = mode->width;
    *(volatile u32 *)VI_BURST_REG = mode->burst;
    *(volatile u32 *)VI_V_SYNC_REG = mode->vSync;
    *(volatile u32 *)VI_H_SYNC_REG = mode->hSync;
    *(volatile u32 *)VI_LEAP_REG = mode->leap;
    *(volatile u32 *)VI_H_START_REG = horizontalStart;
    *(volatile u32 *)VI_V_START_REG = mode->fld[field].vStart;
    *(volatile u32 *)VI_V_BURST_REG = mode->fld[field].vBurst;
    *(volatile u32 *)VI_INTR_REG = mode->fld[field].vIntr;
    *(volatile u32 *)VI_X_SCALE_REG = nextContext->xScale;
    *(volatile u32 *)VI_Y_SCALE_REG = nextContext->yScale;
    *(volatile u32 *)VI_STATUS_REG = nextContext->control;
    D_801F4764 = D_801F4760;
    D_801F4760 = (Unk801F4764 *)nextContext;
    *D_801F4764 = *D_801F4760;
}

/* Original compiler padding. */
const u32 D_801CF3AC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* osViBlack: blank (active != 0) or unblank the video output from the next
 * retrace by setting VI_STATE_BLACK in the next VI context (__osViNext),
 * with interrupts disabled (__osDisableInt / __osRestoreInt). */
void func_801CF3B0(s32 active)
{
    u16 state;
    Unk801F4764 *viNext;
    s32 savedMask;

    savedMask = func_801C6F70();
    if ((active & 0xff) != 0) {
        viNext = D_801F4764;
        state = viNext->unk0 | VI_STATE_BLACK;
    } else {
        viNext = D_801F4764;
        state = viNext->unk0 & ~VI_STATE_BLACK;
    }
    viNext->unk0 = state;
    func_801C6F90(savedMask);
}

/* Original compiler padding. */
const u32 D_801CF40C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* __osSiRawReadIo: read one word from a serial-interface address (asserting
 * word alignment and a non-null destination); -1 while the SI is busy. */
s32 func_801CF410(u32 devAddr, s32 *data)
{
    if (devAddr & 3) {
        func_801CA030(D_8010C6A0, D_8010C6A4, 0x33); /* __assert */
    }
    if (data == NULL) {
        func_801CA030(D_8010C6A0, D_8010C6A4, 0x34);
    }
    if (func_801CF4A0() != 0) { /* __osSiDeviceBusy */
        return -1;
    }
    *data = *(volatile s32 *)(devAddr | 0xA0000000); /* IO_READ(PHYS_TO_K1(devAddr)) */
    return 0;
}

/* __osSiDeviceBusy: nonzero while the serial interface has a DMA or IO read in progress. */
s32 func_801CF4A0(void)
{
    return (*(volatile u32 *)SI_STATUS_REG & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY)) != 0;
}

/* Original compiler padding. */
const u32 D_801CF4B8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

extern u8 D_8010C6B0[];
extern u8 D_8010C6B4[];
/* __osSiRawWriteIo: write one word to a serial-interface address (asserting
 * word alignment); -1 while the SI is busy. */
s32 func_801CF4C0(u32 devAddr, s32 data) {
    if ((devAddr & 3) != 0) {
        func_801CA030(D_8010C6B0, D_8010C6B4, 0x34); /* __assert, line 52 */
    }
    if (func_801CF4A0() != 0) { /* __osSiDeviceBusy */
        return -1;
    }
    *(volatile s32 *)(devAddr | 0xA0000000u) = data; /* IO_WRITE(PHYS_TO_K1(devAddr), data) */
    return 0;
}


/* Original compiler padding. */
const u32 D_801CF52C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* libultra osContStartReadData(mq): under SI access (func_801CF824/890),
 * rebuilds the PIF read-buttons block if the last command (D_802AE940) was
 * something else and writes it, then starts the PIF read DMA
 * (func_801CF710 = __osSiRawStartDma; 1 = OS_WRITE, 0 = OS_READ) into
 * __osContPifRam (D_802AE900). func_801C7430 is osRecvMesg (1 = block). */
s32 func_801CF530(s32 mq) {
    s32 ret = 0;

    func_801CF824();

    if (D_802AE940 != CONT_CMD_READ_BUTTON) {
        func_801CF654();
        ret = func_801CF710(1, D_802AE900);
        func_801C7430((void *)mq, NULL, 1);
    }

    ret = func_801CF710(0, D_802AE900);
    D_802AE940 = CONT_CMD_READ_BUTTON;
    func_801CF890();

    return ret;
}

/*
 * osContGetReadData: copy each controller's reply from __osContPifRam into the
 * caller's 6-byte OSContPad records (button u16, stick_x, stick_y, errno).
 * Read format: unk2 = rxsize (error bits 0xC0), unk4 = buttons, unk6/7 = stick X/Y.
 */
void func_801CF5B8(u8 *pads) {
    s32 channel;
    Ent8 *readFormat = (Ent8 *)D_802AE900;

    for (channel = 0; channel < D_802AE8FC; channel++, readFormat++, pads += 6) {
        Ent8 reply = *readFormat;
        u8 error = (reply.unk2 & 0xC0) >> 4;

        pads[4] = error;
        if (error == 0) {
            *(u16 *)pads = reply.unk4;
            pads[2] = reply.unk6;
            pads[3] = reply.unk7;
        }
    }
}

/* __osPackReadData: clear the controller PIF buffer (D_802AE900), set its
 * execute byte (D_802AE93C), and queue one read-buttons request per
 * controller (D_802AE8FC = __osMaxControllers), then an end marker.
 * Ent8 is the request: dummy, txsize, rxsize, cmd, buttons, stick x/y. */
void func_801CF654(void) {
    s32 i;
    Ent8 *request = (Ent8 *)D_802AE900;
    Ent8 readFormat;

    for (i = EEPROM_PIF_LAST_WORD - 1; i >= 0; i--) {
        ((s32 *)request)[i] = 0;
    }
    D_802AE93C = EEPROM_PIF_EXECUTE;
    readFormat.unk0[0] = PIF_CMD_NOP;
    readFormat.unk0[1] = CONT_READ_BUTTON_TX_BYTES;
    readFormat.unk2 = CONT_READ_BUTTON_RX_BYTES;
    readFormat.unk3 = CONT_CMD_READ_BUTTON;
    readFormat.unk4 = 0xFFFF;
    *(s8 *)&readFormat.unk6 = -1;
    *(s8 *)&readFormat.unk7 = -1;
    for (i = 0; i < D_802AE8FC; i++) {
        *request = readFormat;
        request++;
    }
    request->unk0[0] = PIF_CMD_END;
    return;
}

/* Original compiler padding. */
const u32 D_801CF70C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* __osSiRawStartDma: start a 64-byte DMA between `buffer` and PIF RAM
 * (OS_READ: PIF -> RDRAM, OS_WRITE: RDRAM -> PIF). Returns -1 while the SI
 * is busy. Callees: func_801CF4A0 __osSiDeviceBusy, func_801C6470
 * osWritebackDCache, func_801C7D90 osVirtualToPhysical, func_801C62C0
 * osInvalDCache. */
s32 func_801CF710(s32 direction, void *buffer) {
    extern u8 D_8010C6D0[];
    extern u8 D_8010C6D4[];

    if (((u32)buffer & 3) != 0) {
        func_801CA030(D_8010C6D0, D_8010C6D4, 0x37);
    }
    if (func_801CF4A0() != 0) {
        return -1;
    }
    if (direction == OS_WRITE) {
        func_801C6470(buffer, PIF_RAM_BYTES);
    }
    *(volatile u32 *)SI_DRAM_ADDR_REG = func_801C7D90((u32)buffer);
    if (direction == OS_READ) {
        *(volatile u32 *)SI_PIF_ADDR_RD64B_REG = PIF_RAM_START;
    } else {
        *(volatile u32 *)SI_PIF_ADDR_WR64B_REG = PIF_RAM_START;
    }
    if (direction == OS_READ) {
        func_801C62C0(buffer, PIF_RAM_BYTES);
    }
    return 0;
}

/* Original compiler padding. */

const u32 D_801CF7C8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra __osSiCreateAccessQueue: create the one-slot SI access queue
 * (D_802AE8A0, buffer D_802AE890) and post the token that marks the serial
 * interface as free. */
void func_801CF7D0(void) {
    D_801F54B0 = 1; /* __osSiAccessQueueEnabled */
    func_801C6520((OSMesgQueue *)D_802AE8A0, (void **)D_802AE890, 1); /* osCreateMesgQueue */
    func_801C7560(D_802AE8A0, 0, OS_MESG_NOBLOCK); /* osSendMesg */
}

/* __osSiGetAccess: create the SI access queue on first use (holding one token),
 * then block until the token is free and take it. */
s32 func_801CF824(void) {
    s32 token;
    u8 *accessQueue;
    if (D_801F54B0 == 0) { /* __osSiAccessQueueEnabled */
        D_801F54B0 = 1;
        accessQueue = D_802AE8A0;
        func_801C6520((OSMesgQueue *)accessQueue, (void **)D_802AE890, 1); /* osCreateMesgQueue */
        accessQueue = 0;
        accessQueue = D_802AE8A0;
        func_801C7560(accessQueue, 0, OS_MESG_NOBLOCK); /* osSendMesg */
    }
    accessQueue = 0;
    accessQueue = D_802AE8A0;
    return func_801C7430(accessQueue, &token, OS_MESG_BLOCK); /* osRecvMesg */
}

/* __osSiRelAccess: releases the serial interface by posting to the SI access queue. */
void func_801CF890(void) {
    func_801C7560(D_802AE8A0, 0, OS_MESG_NOBLOCK); /* osSendMesg */
}

/* Original compiler padding. */
const u32 D_801CF8B8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* Initialize controller status once, waiting for PIF startup before the SI query. */
s32 func_801CF8C0(s32 siMessageQueue, s32 connectedMaskOut, s32 controllerStatusOut) {
    extern s32 D_801F54C0;
    void *completionMessage;
    s32 result = 0;
    u64 elapsedTicks;
    u8 startupTimer[sizeof(OSTimer)];
    OSMesgQueue startupMessageQueue;

    if (D_801F54C0) {
        return 0;
    }

    D_801F54C0 = 1;

    elapsedTicks = func_801C7080();
    if (elapsedTicks < (u64)CONTROLLER_STARTUP_TICKS) {
        func_801C6520(&startupMessageQueue, &completionMessage, 1);
        ((void (*)(void *, u64, u64, void *, void *))func_801C77C0)(startupTimer, (u64)CONTROLLER_STARTUP_TICKS - elapsedTicks, 0, &startupMessageQueue, &completionMessage);
        func_801C7430(&startupMessageQueue, &completionMessage, OS_MESG_BLOCK);
    }

    D_802AE8FC = CONTROLLER_COUNT;

    func_801CFB10(CONT_CMD_REQUEST_STATUS);

    result = func_801CF710(OS_WRITE, D_802AE900);
    func_801C7430((void *)siMessageQueue, &completionMessage, OS_MESG_BLOCK);

    result = func_801CF710(OS_READ, D_802AE900);
    func_801C7430((void *)siMessageQueue, &completionMessage, OS_MESG_BLOCK);

    func_801CFA5C(connectedMaskOut, controllerStatusOut);
    D_802AE940 = CONT_CMD_REQUEST_STATUS;
    func_801CF7D0();
    func_801C6520((OSMesgQueue *)D_802AE8E0, (void **)D_802AE8F8, 1);

    return result;
}

/* __osContGetInitData: read each controller's status reply from the PIF buffer
 * (D_802AE900) into status[] (OSContStatus: u16 type, u8 status, u8 errno), and
 * set bit i of *pattern for every controller that answered without error. */
void func_801CFA5C(u8 *pattern, u8 *status) {
    s32 i;
    u8 bits = 0;
    Ent8 *request = (Ent8 *)D_802AE900;

    for (i = 0; i < D_802AE8FC; i++, request++, status += 4) {
        Ent8 reply = *request;
        u8 error = (reply.unk2 & 0xC0) >> 4;  /* CHNL_ERR(rxsize) */

        status[3] = error;
        if (error == 0) {
            /* type = typeh | typel << 8 */
            *(u16 *)status = ((u8 *)&reply)[4] | (((u8 *)&reply)[5] << 8);
            status[2] = reply.unk6;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}

/* __osPackRequestData: clear the controller PIF buffer (D_802AE900) and fill it with one status
 * request per controller (D_802AE8FC = __osMaxControllers) for command `command`, then an end marker. */
void func_801CFB10(u8 command)
{
    s32 i;
    s32 *word;
    s32 *pifStatus;
    PifStatusRequest *dst;
    PifStatusRequest request;

    i = EEPROM_PIF_LAST_WORD - 1;
    word = &D_802AE938;
    do {
        *word = 0;
        word--;
        i--;
    } while (i >= 0);
    pifStatus = &D_802AE93C;
    dst = (PifStatusRequest *)((u8 *)pifStatus - 0x3C);
    i = 0;
    *pifStatus = EEPROM_PIF_EXECUTE;
    request.dummy = PIF_CMD_NOP;
    request.txsize = PIF_STATUS_TX_BYTES;
    request.rxsize = PIF_STATUS_RX_BYTES;
    request.cmd = command;
    request.typeLow = PIF_CMD_NOP;
    request.typeHigh = PIF_CMD_NOP;
    request.status = PIF_CMD_NOP;
    request.dummy1 = PIF_CMD_NOP;
    for (; i < D_802AE8FC; i++) {
        *dst = request;
        dst++;
    }
    *(u8 *)dst = PIF_CMD_END;
}

/* Original compiler padding. */
const u32 D_801CFBCC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* osEepromProbe: asks the SI bus for the EEPROM status and reports which
 * EEPROM the cartridge has (none, 4 Kbit or 16 Kbit). */
s32 func_801CFBD0(s32 mq) {
    OSContStatus status;
    s32 error;
    s32 type;
    s32 eepromType;

    func_801CF824(); /* __osSiGetAccess */
    error = func_801CFE9C(mq, (u8 *)&status); /* __osEepStatus */
    type = status.type & EEPROM_TYPE_MASK;
    if (error == 0) {
        type = (u16)type;
        switch (type) {
        case EEPROM_TYPE_4K:
            eepromType = EEPROM_PROBE_4K;
            break;
        case EEPROM_TYPE_16K:
            eepromType = EEPROM_PROBE_16K;
            break;
        default:
            eepromType = EEPROM_PROBE_NONE;
            break;
        }
    } else {
        eepromType = EEPROM_PROBE_NONE;
    }
    func_801CF890(); /* __osSiRelAccess */
    return eepromType;
}

/* Original compiler padding. */
const u32 D_801CFC44_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* Write one eight-byte EEPROM block, waiting for device readiness and SI transfers. */
s32 func_801CFC50(void *siMessageQueue, s32 block, void *source) {
    u8 blockAddress = block;
    s32 result = 0;
    int channel;
    u16 deviceType;
    u8 *packet = D_802AE950;
    PifEepromPacket reply;
    OSContStatus deviceStatus;

    func_801CF824();
    result = func_801CFE9C(siMessageQueue, (u8 *)&deviceStatus);
    result = func_801CFE9C(siMessageQueue, (u8 *)&deviceStatus);

    deviceType = deviceStatus.type & EEPROM_TYPE_MASK;

    if (result != 0) {
        func_801CF890();
        return CONT_ERR_NO_RESPONSE;
    } else {
        switch (deviceType) {
            case EEPROM_TYPE_4K:
                if (blockAddress > EEPROM_4K_BLOCK_LIMIT) {
                    func_801CF890();
                    return EEPROM_ERR_INVALID_ADDRESS;
                }
                break;
            case EEPROM_TYPE_16K:
                if (blockAddress > EEPROM_16K_BLOCK_LIMIT) {
                    func_801CF890();
                    return EEPROM_ERR_INVALID_ADDRESS;
                }
                break;
            default:
                func_801CF890();
                return CONT_ERR_NO_RESPONSE;
        }
    }

    while (deviceStatus.status & EEPROM_STATUS_BUSY) {
        func_801CFE9C(siMessageQueue, (u8 *)&deviceStatus);
    }

    func_801CFDD8(blockAddress, (u8 *)source);
    result = func_801CF710(OS_WRITE, D_802AE950);
    func_801C7430(siMessageQueue, NULL, OS_MESG_BLOCK);
    result = func_801CF710(OS_READ, D_802AE950);
    D_802AE940 = CONT_CMD_WRITE_EEPROM;
    func_801C7430(siMessageQueue, NULL, OS_MESG_BLOCK);

    for (channel = 0; channel < CONTROLLER_COUNT; channel++) {
        packet++;
    }

    reply = *(PifEepromPacket *)packet;

    result = (reply.rxsize & PIF_CHANNEL_ERROR_MASK) >> PIF_CHANNEL_ERROR_SHIFT;

    func_801CF890();
    return result;
}

/* __osPackEepWriteData: fill the EEPROM PIF buffer (D_802AE950) with a write
 * request for one eight-byte block: four skipped controller channels, the
 * packet, and an end marker; D_802AE98C (the PIF status word) starts execution. */
void func_801CFDD8(u8 blockAddress, u8 *data) {
    u8 *ptr = D_802AE950;
    PifEepromPacket packet;
    int i;

    for (i = 0; i < EEPROM_PIF_LAST_WORD; i++) {
        ((u32 *)D_802AE950)[i] = PIF_CMD_NOP;
    }
    D_802AE98C = EEPROM_PIF_EXECUTE;
    packet.txsize = EEPROM_WRITE_TX_BYTES;
    packet.rxsize = EEPROM_WRITE_RX_BYTES;
    packet.command = CONT_CMD_WRITE_EEPROM;
    packet.blockAddress = blockAddress;
    for (i = 0; i < EEPROM_BLOCK_BYTES; i++) {
        packet.data[i] = *data++;
    }
    for (i = 0; i < CONTROLLER_COUNT; i++) {
        *ptr++ = 0;
    }
    *(PifEepromPacket *)ptr = packet;
    ptr += sizeof(PifEepromPacket);
    ptr[0] = PIF_CMD_END;
}

s32 func_801CFE9C(void *siMessageQueue, u8 *statusOut) {
    PifStatusRequest request;
    s32 index;
    s32 dmaResult;
    s32 *pifWord;
    u8 *packet;

    /* Query EEPROM device type and status, waiting for both SI transfers to finish. */
    index = EEPROM_PIF_LAST_WORD;
    pifWord = &D_802AE98C;
    for (; index >= 0; index--) {
        *pifWord-- = 0;
    }
    pifWord = &D_802AE98C;
    *pifWord = EEPROM_PIF_EXECUTE;
    packet = (u8 *)(pifWord - EEPROM_PIF_LAST_WORD);
    for (index = CONTROLLER_COUNT - 1; index >= 0; index--) {
        *packet++ = 0;
    }
    request.dummy = PIF_CMD_NOP;
    request.txsize = PIF_STATUS_TX_BYTES;
    request.rxsize = PIF_STATUS_RX_BYTES;
    request.cmd = CONT_CMD_REQUEST_STATUS;
    request.typeLow = PIF_CMD_NOP;
    request.typeHigh = PIF_CMD_NOP;
    request.status = PIF_CMD_NOP;
    request.dummy1 = PIF_CMD_NOP;
    *(PifStatusRequest *)packet = request;
    packet[8] = PIF_CMD_END;
    func_801CF710(OS_WRITE, D_802AE950);
    func_801C7430(siMessageQueue, NULL, OS_MESG_BLOCK);
    D_802AE940 = CONT_CMD_REQUEST_STATUS;
    dmaResult = func_801CF710(OS_READ, D_802AE950);
    func_801C7430(siMessageQueue, NULL, OS_MESG_BLOCK);
    if (dmaResult == 0) {
        packet = D_802AE950;
        for (index = CONTROLLER_COUNT - 1; index >= 0; index--) {
            *packet++ = 0;
        }
        request = *(PifStatusRequest *)packet;
        statusOut[CONT_STATUS_ERROR_OFFSET] = (request.rxsize & PIF_CHANNEL_ERROR_MASK) >> PIF_CHANNEL_ERROR_SHIFT;
        *(u16 *)statusOut = request.typeLow | (request.typeHigh << 8);
        statusOut[CONT_STATUS_FLAGS_OFFSET] = request.status;
        if (statusOut[CONT_STATUS_ERROR_OFFSET] != 0) {
            return statusOut[CONT_STATUS_ERROR_OFFSET];
        }
        return 0;
    }
    return dmaResult;
}

s32 func_801D0030(void *siMessageQueue, u8 blockAddress, u8 *destination)
{
    u8 status[4];
    PifEepromPacket reply;
    u8 *packet;
    s32 channel;
    s32 result;
    s32 deviceType;
    u8 *data;

    /* Read one eight-byte EEPROM block after waiting for the device to become idle. */
    func_801CF824();
    result = func_801CFE9C(siMessageQueue, status);
    deviceType = *(u16 *)status & EEPROM_TYPE_MASK;
    packet = D_802AE950;
    if (result != 0) {
        goto error;
    }
    {
        deviceType = (u16)deviceType;
        if (deviceType == EEPROM_TYPE_4K) {
            if (blockAddress > EEPROM_4K_BLOCK_LIMIT) {
                func_801CF890();
                return -1;
            }
            goto read;
        }
    }
    if (deviceType != EEPROM_TYPE_16K) {
error:
        func_801CF890();
        return CONT_ERR_NO_RESPONSE;
    }
read:
    while (status[CONT_STATUS_FLAGS_OFFSET] & EEPROM_STATUS_BUSY) {
        func_801CFE9C(siMessageQueue, status);
    }
    func_801D01C4(blockAddress);
    func_801CF710(OS_WRITE, D_802AE950);
    func_801C7430(siMessageQueue, NULL, OS_MESG_BLOCK);
    func_801CF710(OS_READ, D_802AE950);
    D_802AE940 = CONT_CMD_READ_EEPROM;
    func_801C7430(siMessageQueue, NULL, OS_MESG_BLOCK);
    for (channel = CONTROLLER_COUNT - 1; channel >= 0; channel--) {
        packet++;
    }
    reply = *(PifEepromPacket *)packet;
    result = (reply.rxsize & PIF_CHANNEL_ERROR_MASK) >> PIF_CHANNEL_ERROR_SHIFT;
    if (result == 0) {
        data = reply.data;
        do {
            *destination++ = *data++;
        } while ((s32)data < (s32)(reply.data + EEPROM_BLOCK_BYTES));
    }
    func_801CF890();
    return result;
}

/* __osPackEepReadData: fill the EEPROM PIF buffer (D_802AE950) with a read request for one eight-byte
 * block: four skipped controller channels, the packet, and an end marker. */
void func_801D01C4(u8 blockAddress) {
    s32 i;
    u8 *ptr = D_802AE950;
    s32 nop = PIF_CMD_NOP;
    PifEepromPacket packet;

    for (i = EEPROM_PIF_LAST_WORD - 1; i >= 0; i--) {
        ((s32 *)ptr)[i] = nop;
    }
    D_802AE98C = EEPROM_PIF_EXECUTE;
    packet.txsize = EEPROM_READ_TX_BYTES;
    packet.rxsize = EEPROM_READ_RX_BYTES;
    packet.command = CONT_CMD_READ_EEPROM;
    packet.blockAddress = blockAddress;
    for (i = EEPROM_BLOCK_BYTES - 1; i >= 0; i--) {
        packet.data[i] = 0;
    }
    for (i = CONTROLLER_COUNT - 1; i >= 0; i--) {
        *ptr++ = 0;
    }
    *(PifEepromPacket *)ptr = packet;
    ptr += sizeof(PifEepromPacket);
    *ptr = PIF_CMD_END;
}

/* osEepromLongWrite: write `length` bytes to the EEPROM from `buffer`, one
 * 8-byte block at a time starting at block `address` (func_801CFC50 is
 * osEepromWrite), waiting 12 ms after each block with an osSetTimer on the
 * D_802AE8E0 queue. Returns the first error, or 0. */
s32 func_801D0280(void *queue, u8 address, void *buffer, s32 length)
{
    s32 result = 0;

    while (length > 0) {
        result = func_801CFC50(queue, address, buffer);
        if (result != 0) {
            return result;
        }
        length -= EEPROM_BLOCK_SIZE;
        address++;
        buffer = (u8 *)buffer + EEPROM_BLOCK_SIZE;
        /* osSetTimer(timer, countdown, interval, queue, message) */
        ((void (*)(void *, s64, s64, void *, void *))func_801C77C0)(D_802AE8C0, (s64)EEPROM_WRITE_WAIT_TICKS, 0LL, D_802AE8E0, D_802AE8F8);
        func_801C7430(D_802AE8E0, NULL, OS_MESG_BLOCK); /* osRecvMesg */
    }
    return result;
}

/* Original compiler padding. */
const u32 D_801D0364_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osEepromLongRead: reads `nbytes` from EEPROM, one 8-byte block at a time,
 * starting at block `address`; stops at the first error and returns it. */
s32 func_801D0370(void *mq, u8 address, u8 *buffer, s32 nbytes)
{
    s32 ret = 0;

    while (nbytes > 0) {
        ret = func_801D0030(mq, address, buffer); /* osEepromRead */
        if (ret != 0) {
            return ret;
        }
        nbytes -= 8;
        address++;
        buffer += 8;
    }
    return ret;
}

/* osPiRawReadIo: wait until the PI is idle, then read one 32-bit word from the
 * cartridge at devAddr (relative to osRomBase, D_80000308) into *data. */
s32 func_801D03E0(s32 devAddr, s32 *data)
{
    if (data == NULL) {
        func_801CA030(D_8010C6E0, D_8010C6E4, 0x3d); /* assert(data != NULL) */
    }
    while (*(volatile u32 *)PI_STATUS_REG & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}
    *data = *(volatile s32 *)((D_80000308 | devAddr) | 0xA0000000);
    return 0;
}

extern s32 D_801F55C0; /* PiDeviceManager.active */
extern s32 D_801F55C4; /* PiDeviceManager.thread */
extern s32 D_801F55C8; /* PiDeviceManager.commandQueue */
extern s32 D_801F55CC; /* PiDeviceManager.eventQueue */
extern s32 D_801F55D0; /* PiDeviceManager.accessQueue */
extern s32 D_801F55D4; /* PiDeviceManager.dma */
extern s32 D_801F55D8; /* PiDeviceManager.extendedDma */
extern s32 D_801F55F0; /* PI access queue initialized */
extern u8 D_802AE990[]; /* PI manager thread */
extern u8 D_802AFB40[]; /* PI completion event queue */
extern u8 D_802AEB40[]; /* PI manager thread stack */
extern u8 D_802AFB58[]; /* PI completion event message buffer */
extern u8 D_802B0CF0[]; /* PI access queue */
extern u8 D_802B0CE0[];
void func_801C6520(OSMesgQueue *, void **, s32); /* osCreateMesgQueue */
void func_801C6550(Thread801 *, s32, u32, s32, void *, s32); /* osCreateThread */
void func_801C7690(s32, OSMesgQueue *, s32); /* osSetEventMesg */
void func_801C76F0(QNode *, s32); /* osSetThreadPri */
void func_801C7860(QNode *); /* osStartThread */
s32 func_801CEDD0(s32); /* osGetThreadPri */
void func_801D1B60(void); /* __osPiCreateAccessQueue */
void func_801D13E0(); /* __osDevMgrMain */
s32 func_801D0610(s32, u32, void *, u32); /* __osPiRawStartDma */
s32 func_801D06E0(); /* __osEPiRawStartDma */

/* Original compiler padding. */
const u32 D_801D0474_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osCreatePiManager: initialize PI queues and start the DMA service thread once. */
void func_801D0480(s32 managerPriority, OSMesgQueue *commandQueue, void **commandBuffer, s32 commandCapacity) {
    s32 originalPriority;
    s32 savedInterruptMask;
    s32 callerPriority;
    s32 *managerActive = &D_801F55C0;

    if (*managerActive != 0) {
        return;
    }
    func_801C6520(commandQueue, commandBuffer, commandCapacity);
    func_801C6520((OSMesgQueue *)D_802AFB40, (void **)D_802AFB58, PI_EVENT_QUEUE_CAPACITY);
    if (D_801F55F0 == 0) {
        func_801D1B60();
    }
    func_801C7690(PI_OS_EVENT, (OSMesgQueue *)D_802AFB40, PI_COMPLETION_MESSAGE);
    originalPriority = PI_PRIORITY_UNCHANGED;
    callerPriority = func_801CEDD0(0);
    if (callerPriority < managerPriority) {
        originalPriority = callerPriority;
        func_801C76F0(0, managerPriority);
    }
    savedInterruptMask = func_801C6F70();
    *managerActive = 1;
    D_801F55D0 = (s32)D_802B0CF0;
    D_801F55D4 = (s32)func_801D0610;
    D_801F55D8 = (s32)func_801D06E0;
    D_801F55C4 = (s32)D_802AE990;
    D_801F55C8 = (s32)commandQueue;
    D_801F55CC = (s32)D_802AFB40;
    func_801C6550((Thread801 *)D_802AE990, 0, (u32)func_801D13E0, (s32)managerActive, &D_802AEB40[PI_THREAD_STACK_SIZE], managerPriority);
    func_801C7860((QNode *)D_802AE990);
    func_801C6F90(savedInterruptMask);
    if (originalPriority == PI_PRIORITY_UNCHANGED) {
        return;
    }
    func_801C76F0(0, originalPriority);
}

/* osPiRawStartDma: wait for the PI bus, then start a cartridge DMA of `size`
 * bytes between devAddr (relative to osRomBase, D_80000308) and dramAddr.
 * Returns 0, or -1 for an invalid direction. */
s32 func_801D0610(s32 direction, u32 devAddr, void *dramAddr, u32 size) {
    u32 status;

    status = *(volatile u32 *)PI_STATUS_REG;
    while (status & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        status = *(volatile u32 *)PI_STATUS_REG;
    }
    *(volatile u32 *)PI_DRAM_ADDR_REG = func_801C7D90((u32)dramAddr);
    *(volatile u32 *)PI_CART_ADDR_REG = (D_80000308 | devAddr) & PI_PHYSICAL_ADDRESS_MASK;
    switch (direction) {
    case OS_READ:
        *(volatile u32 *)PI_WR_LEN_REG = size - 1;
        break;
    case OS_WRITE:
        *(volatile u32 *)PI_RD_LEN_REG = size - 1;
        break;
    default:
        return -1;
    }
    return 0;
}

/* __osEPiRawStartDma: select the handle's bus timings and start a PI DMA transfer. */
s32 func_801D06E0(u8 *handle, s32 direction, u32 deviceAddress, u32 dramAddress, u32 size) {
    u32 status;
    u32 domain;
    u8 *currentHandle;

    status = *(volatile u32 *)PI_STATUS_REG;
    while (status & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        status = *(volatile u32 *)PI_STATUS_REG;
    }
    domain = ((PiDeviceHandle *)handle)->domain;
    currentHandle = D_801F55E0[domain];
    if (currentHandle != handle) {
        if (domain == PI_DOMAIN1) {
            if (((PiDeviceHandle *)currentHandle)->latency != ((PiDeviceHandle *)handle)->latency) {
                *(volatile u32 *)PI_BSD_DOM1_LAT_REG = ((PiDeviceHandle *)handle)->latency;
            }
            if (((PiDeviceHandle *)currentHandle)->pageSize != ((PiDeviceHandle *)handle)->pageSize) {
                *(volatile u32 *)PI_BSD_DOM1_PGS_REG = ((PiDeviceHandle *)handle)->pageSize;
            }
            if (((PiDeviceHandle *)currentHandle)->relDuration != ((PiDeviceHandle *)handle)->relDuration) {
                *(volatile u32 *)PI_BSD_DOM1_RLS_REG = ((PiDeviceHandle *)handle)->relDuration;
            }
            if (((PiDeviceHandle *)currentHandle)->pulse != ((PiDeviceHandle *)handle)->pulse) {
                *(volatile u32 *)PI_BSD_DOM1_PWD_REG = ((PiDeviceHandle *)handle)->pulse;
            }
        } else {
            if (((PiDeviceHandle *)currentHandle)->latency != ((PiDeviceHandle *)handle)->latency) {
                *(volatile u32 *)PI_BSD_DOM2_LAT_REG = ((PiDeviceHandle *)handle)->latency;
            }
            if (((PiDeviceHandle *)currentHandle)->pageSize != ((PiDeviceHandle *)handle)->pageSize) {
                *(volatile u32 *)PI_BSD_DOM2_PGS_REG = ((PiDeviceHandle *)handle)->pageSize;
            }
            if (((PiDeviceHandle *)currentHandle)->relDuration != ((PiDeviceHandle *)handle)->relDuration) {
                *(volatile u32 *)PI_BSD_DOM2_RLS_REG = ((PiDeviceHandle *)handle)->relDuration;
            }
            if (((PiDeviceHandle *)currentHandle)->pulse != ((PiDeviceHandle *)handle)->pulse) {
                *(volatile u32 *)PI_BSD_DOM2_PWD_REG = ((PiDeviceHandle *)handle)->pulse;
            }
        }
        D_801F55E0[domain] = handle;
    }
    *(volatile u32 *)PI_DRAM_ADDR_REG = func_801C7D90(dramAddress);
    *(volatile u32 *)PI_CART_ADDR_REG = (((PiDeviceHandle *)handle)->baseAddress | deviceAddress) & PI_PHYSICAL_ADDRESS_MASK;
    switch (direction) {
    case PI_DMA_READ:
        *(volatile u32 *)PI_WR_LEN_REG = size - 1;
        break;
    case PI_DMA_WRITE:
        *(volatile u32 *)PI_RD_LEN_REG = size - 1;
        break;
    default:
        return -1;
    }
    return 0;
}

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

/* Original compiler padding. */
const u32 D_801D08AC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* osEPiStartDma: tag the I/O message `mb` with its PI handle and EDMA type
 * (0xF read, 0x10 write), then jam it (high priority) or send it to the PI
 * manager's command queue (func_801D0A90). Returns -1 if the PI manager
 * (D_801F55C0) is not active. */
s32 func_801D08B0(s32 piHandle, u8 *mb, s32 direction) {
    if (D_801F55C0 == 0) {
        return -1;
    }
    ((PiIoMessage *)mb)->piHandle = (PiDeviceHandle *)piHandle;
    if (direction == OS_READ) {
        ((PiIoMessage *)mb)->type = 0xF;  /* OS_MESG_TYPE_EDMAREAD */
    } else {
        ((PiIoMessage *)mb)->type = 0x10; /* OS_MESG_TYPE_EDMAWRITE */
    }
    if (((PiIoMessage *)mb)->priority == 1) { /* OS_MESG_PRI_HIGH */
        func_801D0950(func_801D0A90(), mb, OS_MESG_NOBLOCK);   /* osJamMesg */
    } else {
        func_801C7560((u8 *)func_801D0A90(), (s32)mb, OS_MESG_NOBLOCK); /* osSendMesg */
    }
}

/* Original compiler padding. */
const u32 D_801D0944_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osJamMesg: prepend a message, optionally wait for space, and wake a waiting receiver. */
s32 func_801D0950(OSMesgQueue *queue, u8 *message, s32 flags) {
    s32 interruptMask = func_801C6F70();

    while (queue->validCount >= queue->msgCount) {
        if (flags != OS_MESG_BLOCK) {
            func_801C6F90(interruptMask);
            return -1;
        }
        *(u16 *)(D_801F4400 + OS_THREAD_STATE_OFFSET) = OS_STATE_WAITING;
        func_801C6C84(&queue->fullqueue);
    }
    queue->first = (queue->first + queue->msgCount - 1) % queue->msgCount;
    queue->msg[queue->first] = message;
    queue->validCount++;
    if (*(s32 *)queue->mtqueue != 0) {
        func_801C7860((QNode *)func_801C6DD4((ObjectNode *)queue));
    }
    func_801C6F90(interruptMask);
    return 0;
}

/* Original compiler padding. */
const u32 D_801D0A84_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osPiGetCmdQueue: the PI device manager's command queue, or NULL if the manager isn't active. */
s32 func_801D0A90(void) {
    if (D_801F55C0 == 0) { /* PiDeviceManager.active */
        return 0;
    }
    return D_801F55C8; /* PiDeviceManager.commandQueue */
}

/*
 * libultra osCartRomInit: on first use, fills the cartridge ROM PI handle
 * (D_802AFB60) with domain 1 timings read from the ROM header word
 * (osPiRawReadIo) and links it into the PI handle table (D_801F55DC) with
 * interrupts disabled. Returns the handle.
 */
void *func_801D0AB0(void) {
    u32 domain = 0;
    u32 saveMask;

    if (D_802AFB60.baseAddress == CART_ROM_UNCACHED_BASE)
        return &D_802AFB60;

    D_802AFB60.type = DEVICE_TYPE_CART;
    D_802AFB60.baseAddress = CART_ROM_UNCACHED_BASE;
    func_801D03E0(0, (s32 *)&domain); /* osPiRawReadIo */
    D_802AFB60.latency = domain & 0xff;
    D_802AFB60.pulse = (domain >> 8) & 0xff;
    D_802AFB60.pageSize = (domain >> 0x10) & 0xf;
    D_802AFB60.relDuration = (domain >> 0x14) & 0xf;
    D_802AFB60.domain = PI_DOMAIN1;
    D_802AFB60.speed = 0;

    func_801D2020(D_802AFB60.transferInfo, PI_HANDLE_TRANSFER_INFO_SIZE); /* bzero */

    saveMask = func_801C6F70(); /* __osDisableInt */
    D_802AFB60.next = (void *)D_801F55DC;
    D_801F55DC = (s32)&D_802AFB60;
    func_801C6F90(saveMask); /* __osRestoreInt */

    return &D_802AFB60;
}


/* Original compiler padding. */
const u32 D_801D0B84_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* osLeoDiskInit: set up the 64DD PI handle at D_802AFBE0 (type, base 0xA5000000, domain 2
 * timings), program the PI domain 2 registers, clear its transfer info and link it at the
 * head of the PI handle list D_801F55DC; D_802AFC54 remembers it as the disk handle.
 * base points at the handle's type byte (offset 4): +1 latency, +2 pulse, +3 pageSize,
 * +4 relDuration, +5 domain, +8 baseAddress, +0xC speed, +0x10 transferInfo. */
void *func_801D0B90(void) {
    u8 *handleType;
    s32 *handle;
    s32 savedMask;

    handleType = &D_802AFBE4;
    handleType[0] = DEVICE_TYPE_64DD;
    D_802AFBEC = LEO_DISK_BASE_ADDRESS;
    D_802AFBE5 = 3;
    D_802AFBE8 = 6;
    D_802AFBE6 = 6;
    D_802AFBE9 = 1;
    D_802AFBE7 = 2;
    *(volatile u32 *)PI_BSD_DOM2_LAT_REG = 3;
    *(volatile u32 *)PI_BSD_DOM2_PWD_REG = 6;
    *(volatile u32 *)PI_BSD_DOM2_PGS_REG = 6;
    *(volatile u32 *)PI_BSD_DOM2_RLS_REG = 2;
    D_802AFBF0 = 0;
    func_801D2020(handleType + 0x10, 0x60);
    handle = (s32 *)(handleType - 0x4);
    savedMask = func_801C6F70();
    handle[0] = D_801F55DC;
    D_801F55DC = (s32)handle;
    D_802AFC54 = (u8 *)handle;
    func_801C6F90(savedMask);
    return handle;
}

/* Original compiler padding. */
const u32 D_801D0C84_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

s32 func_801D0C90(void) {
    /* Service 64DD disk interrupts, advance sector DMA and report block errors. */
    unsigned int diskStatus = 0;
    volatile u32 piStatus;
    LeoDmaTransfer *transfer;
    u32 blockManagerStatus;
    LeoDmaBlock *block;

    transfer = (LeoDmaTransfer *)(D_802AFC54 + LEO_TRANSFER_OFFSET);
    block = &transfer->block[transfer->blockNum];
    piStatus = LEO_IO_READ(LEO_PI_STATUS_REG);
    if (piStatus & LEO_PI_DMA_BUSY) {
        D_801F43E0 = D_801F43E0 & ~LEO_CART_INTERRUPT_MASK;
        block->errStatus = LEO_DMA_PI_BUSY;
        func_801D126C();
        return 1;
    }
    LEO_WAIT_ON_IOBUSY(piStatus);
    diskStatus = LEO_IO_READ(LEO_ASIC_STATUS_REG);
    if (diskStatus & LEO_STATUS_MECHANIC_INTERRUPT) {
        LEO_WAIT_ON_IOBUSY(piStatus);
        LEO_IO_WRITE(LEO_ASIC_BM_STATUS_CTL_REG, transfer->bmCtlShadow | LEO_BM_CTL_RESET_MECHANIC_INTERRUPT);
        block->errStatus = LEO_DMA_OK;
        return 0;
    }
    if (transfer->cmdType == LEO_DMA_COMPLETE) {
        return 1;
    }
    if (diskStatus & LEO_STATUS_BM_ERROR) {
        LEO_WAIT_ON_IOBUSY(piStatus);
        diskStatus = LEO_IO_READ(LEO_ASIC_STATUS_REG);
        block->errStatus = LEO_DMA_STATUS_22;
        func_801D126C();
        LEO_IO_WRITE(LEO_PI_STATUS_REG, LEO_PI_CLEAR_INTERRUPT);
        D_801F43E0 |= LEO_PI_INTERRUPT_ENABLE_MASK;
        return 1;
    }
    if (transfer->cmdType == LEO_DMA_WRITE) {
        if ((diskStatus & LEO_STATUS_DATA_REQUEST) == 0) {
            if (transfer->sectorNum + 1 != transfer->transferMode * LEO_DATA_SECTORS_PER_BLOCK) {
                block->errStatus = LEO_DMA_SECTOR_ERROR;
                func_801D119C();
                return 1;
            }
            LEO_IO_WRITE(LEO_PI_STATUS_REG, LEO_PI_CLEAR_INTERRUPT);
            D_801F43E0 |= LEO_PI_INTERRUPT_ENABLE_MASK;
            block->errStatus = LEO_DMA_OK;
            func_801D126C();
            return 1;
        }
        block->dramAddr = (void *)((u32)block->dramAddr + block->sectorSize);
        transfer->sectorNum++;
        func_801D06E0(D_802AFC54, LEO_DMA_WRITE, LEO_SECTOR_BUFFER_DEVICE_ADDR, (u32)block->dramAddr, block->sectorSize);
        return 1;
    }
    if (transfer->cmdType == LEO_DMA_READ) {
        if (transfer->transferMode == LEO_DMA_SECTOR_MODE) {
            if ((s32)block->C1ErrNum + LEO_SECTOR_MODE_C1_WINDOW < transfer->sectorNum) {
                block->errStatus = LEO_DMA_OK;
                func_801D119C();
                return 1;
            }
            if ((diskStatus & LEO_STATUS_DATA_REQUEST) == 0) {
                block->errStatus = LEO_DMA_C1_ERROR;
                func_801D119C();
                return 1;
            }
        } else {
            block->dramAddr = (void *)((u32)block->dramAddr + block->sectorSize);
        }
        blockManagerStatus = LEO_IO_READ(LEO_ASIC_BM_STATUS_CTL_REG);
        if (((blockManagerStatus & LEO_BM_C1_ERROR_BIT21) && (blockManagerStatus & LEO_BM_C1_ERROR_BIT22)) || (blockManagerStatus & LEO_BM_C1_ERROR_BIT25)) {
            if (block->C1ErrNum > LEO_MAX_C1_ERROR_INDEX) {
                if (transfer->transferMode != LEO_DMA_SECTOR_MODE || transfer->sectorNum > LEO_SECTOR_MODE_C1_LIMIT) {
                    block->errStatus = LEO_DMA_C1_ERROR;
                    func_801D119C();
                    return 1;
                }
            } else {
                int errorIndex = block->C1ErrNum;
                block->C1ErrSector[errorIndex] = transfer->sectorNum + 1;
            }
            block->C1ErrNum++;
        }
        if (diskStatus & LEO_STATUS_C2_TRANSFER) {
            if (transfer->sectorNum + 1 != LEO_C2_REQUEST_SECTOR_COUNT) {
                block->errStatus = LEO_DMA_SECTOR_ERROR;
                func_801D119C();
            }
            if (transfer->transferMode == LEO_DMA_TRACK_MODE && transfer->blockNum == 0) {
                transfer->sectorNum = -1;
                transfer->blockNum = 1;
                transfer->block[1].dramAddr = (void *)((u32)transfer->block[1].dramAddr - transfer->block[1].sectorSize);
                block->errStatus = LEO_DMA_STATUS_22;
            } else {
                LEO_IO_WRITE(LEO_PI_STATUS_REG, LEO_PI_CLEAR_INTERRUPT);
                D_801F43E0 |= LEO_PI_INTERRUPT_ENABLE_MASK;
                transfer->cmdType = LEO_DMA_COMPLETE;
                block->errStatus = LEO_DMA_OK;
            }
            func_801D06E0(D_802AFC54, LEO_DMA_READ, LEO_C2_BUFFER_DEVICE_ADDR, (u32)block->C2Addr, block->sectorSize * LEO_C2_SECTORS);
            return 1;
        }
        if (transfer->sectorNum == -1 && transfer->transferMode == LEO_DMA_TRACK_MODE && transfer->blockNum == 1) {
            LeoDmaBlock *previousBlock = &transfer->block[0];
            if (previousBlock->C1ErrNum == 0) {
                if (((u32 *)previousBlock->C2Addr)[0] | ((u32 *)previousBlock->C2Addr)[1] | ((u32 *)previousBlock->C2Addr)[2] | ((u32 *)previousBlock->C2Addr)[3]) {
                    previousBlock->errStatus = LEO_DMA_SECTOR_ERROR;
                    func_801D119C();
                    return 1;
                }
            }
            previousBlock->errStatus = LEO_DMA_OK;
            func_801D126C();
        }
        transfer->sectorNum++;
        if (diskStatus & LEO_STATUS_DATA_REQUEST) {
            if (transfer->sectorNum > LEO_LAST_DATA_SECTOR) {
                block->errStatus = LEO_DMA_SECTOR_ERROR;
                func_801D119C();
                return 1;
            }
            func_801D06E0(D_802AFC54, LEO_DMA_READ, LEO_SECTOR_BUFFER_DEVICE_ADDR, block->dramAddr, block->sectorSize);
            block->errStatus = LEO_DMA_OK;
            return 1;
        }
        if (transfer->sectorNum <= LEO_LAST_DATA_SECTOR) {
            block->errStatus = LEO_DMA_SECTOR_ERROR;
            func_801D119C();
            return 1;
        }
        return 1;
    }
    block->errStatus = LEO_DMA_INVALID_COMMAND;
    func_801D119C();
    return 1;
}

/* __osLeoAbnormalResume: after a 64DD transfer error, reset the block manager
 * (pulse its reset bit), wake the waiting disk thread (func_801D126C,
 * __osLeoResume), clear the PI interrupt and re-enable PI/cart interrupts. */
void func_801D119C(void) {
    LeoDmaTransfer *transfer = (LeoDmaTransfer *)(D_802AFC54 + LEO_TRANSFER_OFFSET);
    u32 piStatus;

    LEO_WAIT_ON_IOBUSY(piStatus);
    LEO_IO_WRITE(LEO_ASIC_BM_STATUS_CTL_REG, transfer->bmCtlShadow | LEO_BM_CONTROL_RESET);
    LEO_WAIT_ON_IOBUSY(piStatus);
    LEO_IO_WRITE(LEO_ASIC_BM_STATUS_CTL_REG, transfer->bmCtlShadow);
    func_801D126C();
    LEO_IO_WRITE(LEO_PI_STATUS_REG, LEO_PI_CLEAR_INTERRUPT);
    D_801F43E0 |= LEO_PI_INTERRUPT_ENABLE_MASK;
}

/* __osLeoResume: post the cart-interrupt event message (D_802AD5A0/D_802AD5A4:
 * that event's queue and message) without blocking, and move one thread waiting
 * on the queue to the run queue (D_801F43F8 = __osRunQueue). */
void func_801D126C(void) {
    OSMesgQueue *mq = D_802AD5A0;

    if (mq == NULL) {
        return;
    }
    if (mq->validCount >= mq->msgCount) {
        return;
    }
    mq->msg[(mq->first + mq->validCount) % mq->msgCount] = D_802AD5A4;
    mq->validCount++;
    if (*(s32 *)mq->mtqueue != 0) {
        /* __osEnqueueThread(&__osRunQueue, __osPopThread(&mq->mtqueue)) */
        func_801C6D8C((ObjectNode *)&D_801F43F8, (QNode *)func_801C6DD4((ObjectNode *)mq));
        return;
    }
}

/* libultra osDriveRomInit: on first use, fills the 64DD drive ROM PI handle (D_802B0C60) with fixed
 * domain 1 timings and links it into the PI handle table (D_801F55DC) with interrupts disabled. */
void *func_801D1320(void) {
    u32 saveMask;

    if (D_802B0C60.baseAddress == DRIVE_ROM_UNCACHED_BASE) {
        return &D_802B0C60;
    }

    D_802B0C60.type = DEVICE_TYPE_BULK;
    D_802B0C60.baseAddress = DRIVE_ROM_UNCACHED_BASE;
    D_802B0C60.latency = 64;
    D_802B0C60.pulse = 7;
    D_802B0C60.pageSize = 7;
    D_802B0C60.relDuration = 2;
    D_802B0C60.domain = PI_DOMAIN1;
    D_802B0C60.speed = 0;

    func_801D2020(D_802B0C60.transferInfo, PI_HANDLE_TRANSFER_INFO_SIZE); /* bzero */

    saveMask = func_801C6F70(); /* __osDisableInt */
    D_802B0C60.next = (void *)D_801F55DC;
    D_801F55DC = (s32)&D_802B0C60;
    func_801C6F90(saveMask); /* __osRestoreInt */

    return &D_802B0C60;
}


/* Original compiler padding. */
const u32 D_801D13DC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

void func_801D17A0(s32);
void func_801D17F0(s32);
void func_801D1830(void);
s32 func_801D1880(u8 *, u32, u32 *);
s32 func_801D1A10(u8 *, u32, u32);
void func_801D13E0(void *managerArgs) {
    PiIoMessage *request;
    void *completionEvent;
    void *accessToken;
    s32 dmaResult;
    PiDeviceManager *manager;
    s32 secondBlockPending = 0;

    /* Service queued PI DMA requests and 64DD blocks, then notify each caller. */
    manager = (PiDeviceManager *)managerArgs;
    request = NULL;
    dmaResult = 0;

    while (1) {
        func_801C7430(manager->commandQueue, &request, PI_MESSAGE_BLOCKING);

        if (request->piHandle != NULL && request->piHandle->type == PI_DEVICE_64DD &&
            (request->piHandle->transferInfo.cmdType == LEO_DMA_READ ||
             request->piHandle->transferInfo.cmdType == LEO_DMA_WRITE)) {
            LeoDmaBlock *block;
            LeoDmaTransfer *transfer;
            transfer = &request->piHandle->transferInfo;
            block = &transfer->block[transfer->blockNum];
            transfer->sectorNum = -1;

            if (transfer->transferMode != LEO_DMA_SECTOR_MODE) {
                block->dramAddr = (void *)((u32)block->dramAddr - block->sectorSize);
            }

            if (transfer->transferMode == LEO_DMA_TRACK_MODE && request->piHandle->transferInfo.cmdType == LEO_DMA_READ) {
                secondBlockPending = 1;
            } else {
                secondBlockPending = 0;
            }

            func_801C7430(manager->accessQueue, &accessToken, PI_MESSAGE_BLOCKING);
            func_801D17A0(LEO_PI_INTERRUPT_ENABLE_MASK);
            func_801D1A10((u8 *)request->piHandle, LEO_ASIC_BM_CONTROL_DEVICE_ADDR, (transfer->bmCtlShadow | LEO_BM_CONTROL_START));

        waitForDiskBlock:
            func_801C7430(manager->eventQueue, &completionEvent, PI_MESSAGE_BLOCKING);
            transfer = &request->piHandle->transferInfo;
            block = &transfer->block[transfer->blockNum];

            if (block->errStatus == LEO_DMA_PI_BUSY) {
                u32 diskStatus;
                func_801D1A10((u8 *)request->piHandle, LEO_ASIC_BM_CONTROL_DEVICE_ADDR, transfer->bmCtlShadow | LEO_BM_CONTROL_RESET);
                func_801D1A10((u8 *)request->piHandle, LEO_ASIC_BM_CONTROL_DEVICE_ADDR, transfer->bmCtlShadow);
                func_801D1880((u8 *)request->piHandle, LEO_ASIC_STATUS_DEVICE_ADDR, &diskStatus);

                if (diskStatus & LEO_STATUS_MECHANIC_INTERRUPT) {
                    func_801D1A10((u8 *)request->piHandle, LEO_ASIC_BM_CONTROL_DEVICE_ADDR, transfer->bmCtlShadow | LEO_BM_CTL_RESET_MECHANIC_INTERRUPT);
                }

                block->errStatus = LEO_DMA_INVALID_COMMAND;
                *(volatile u32 *)LEO_PI_STATUS_REG = LEO_PI_CLEAR_INTERRUPT;
                func_801D17F0(LEO_PI_CART_INTERRUPT_ENABLE_MASK);
            }

            func_801C7560(request->returnQueue, (s32)request, PI_MESSAGE_NONBLOCKING);

            if (secondBlockPending == 1 && request->piHandle->transferInfo.block[0].errStatus == LEO_DMA_OK) {
                secondBlockPending = 0;
                goto waitForDiskBlock;
            }

            func_801C7560(manager->accessQueue, 0, PI_MESSAGE_NONBLOCKING);
            if (request->piHandle->transferInfo.blockNum == 1) {
                func_801D1830();
            }
        } else {
            switch (request->type) {
                case PI_MESSAGE_DMA_READ:
                    func_801C7430(manager->accessQueue, &accessToken, PI_MESSAGE_BLOCKING);
                    dmaResult = manager->dma(PI_DMA_READ, request->devAddr, request->dramAddr, request->size);
                    break;
                case PI_MESSAGE_DMA_WRITE:
                    func_801C7430(manager->accessQueue, &accessToken, PI_MESSAGE_BLOCKING);
                    dmaResult = manager->dma(PI_DMA_WRITE, request->devAddr, request->dramAddr, request->size);
                    break;
                case PI_MESSAGE_EXTENDED_DMA_READ:
                    func_801C7430(manager->accessQueue, &accessToken, PI_MESSAGE_BLOCKING);
                    dmaResult = manager->extendedDma(request->piHandle, PI_DMA_READ, request->devAddr, request->dramAddr, request->size);
                    break;
                case PI_MESSAGE_EXTENDED_DMA_WRITE:
                    func_801C7430(manager->accessQueue, &accessToken, PI_MESSAGE_BLOCKING);
                    dmaResult = manager->extendedDma(request->piHandle, PI_DMA_WRITE, request->devAddr, request->dramAddr, request->size);
                    break;
                case PI_MESSAGE_LOOPBACK:
                    func_801C7560(request->returnQueue, (s32)request, PI_MESSAGE_NONBLOCKING);
                    dmaResult = -1;
                    break;
                default:
                    dmaResult = -1;
                    break;
            }

            if (dmaResult == 0) {
                func_801C7430(manager->eventQueue, &completionEvent, PI_MESSAGE_BLOCKING);
                func_801C7560(request->returnQueue, (s32)request, PI_MESSAGE_NONBLOCKING);
                func_801C7560(manager->accessQueue, 0, PI_MESSAGE_NONBLOCKING);
            }
        }
    }
}

/* Original compiler padding. */
const u32 D_801D1798_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra __osResetGlobalIntMask: with interrupts disabled (func_801C6F70 =
 * __osDisableInt, func_801C6F90 = __osRestoreInt), clears `mask` from the global
 * interrupt mask D_801F43E0 (__OSGlobalIntMask), always keeping bits 0x401
 * (the software-interrupt/RCP bits). */
void func_801D17A0(s32 mask) {
    s32 savedMask = func_801C6F70();

    D_801F43E0 = D_801F43E0 & (~mask | 0x401);
    func_801C6F90(savedMask);
    return;
}

/* Original compiler padding. */
const u32 D_801D17E8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* libultra __osSetGlobalIntMask: ORs `mask` into the global interrupt mask D_801F43E0 with interrupts disabled. */
void func_801D17F0(s32 mask) {
    s32 savedMask = func_801C6F70(); /* __osDisableInt */
    D_801F43E0 = D_801F43E0 | mask;
    return func_801C6F90(savedMask); /* __osRestoreInt */
}

/* libultra osYieldThread: marks the running thread (D_801F4400 =
 * __osRunningThread) runnable (state at +0x10 = OS_STATE_RUNNABLE, 2) and puts
 * it back on the run queue D_801F43F8 (__osRunQueue) with func_801C6C84
 * (__osEnqueueAndYield), all with interrupts disabled. */
void func_801D1830(void)
{
    s32 savedMask;

    savedMask = func_801C6F70();
    *(u16 *)(D_801F4400 + 0x10) = 2;
    func_801C6C84(&D_801F43F8);
    func_801C6F90(savedMask);
}

/* Original compiler padding. */
const u32 D_801D1878_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

extern u8 *D_801F55E0[]; /* Cached device handle for each PI bus domain. */
extern u8 D_8010C710[]; /* Raw PI read assertion diagnostic argument. */
extern u8 D_8010C714[]; /* Raw PI read assertion source argument. */

/* __osEPiRawReadIo: wait for the PI bus, apply device timing, and read an uncached word. */
s32 func_801D1880(u8 *handle, u32 deviceAddress, u32 *valueOut) {
    u32 status;
    u32 domain;
    u8 *currentHandle;

    if (valueOut == NULL) {
        func_801CA030(D_8010C710, D_8010C714, PI_RAW_READ_OUTPUT_ASSERT_LINE);
    }
    status = *(volatile u32 *)PI_STATUS_REG;
    while (status & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        status = *(volatile u32 *)PI_STATUS_REG;
    }
    domain = ((PiDeviceHandle *)handle)->domain;
    currentHandle = D_801F55E0[domain];
    if (currentHandle != handle) {
        if (domain == PI_DOMAIN1) {
            if (((PiDeviceHandle *)currentHandle)->latency != ((PiDeviceHandle *)handle)->latency) {
                *(volatile u32 *)PI_BSD_DOM1_LAT_REG = ((PiDeviceHandle *)handle)->latency;
            }
            if (((PiDeviceHandle *)currentHandle)->pageSize != ((PiDeviceHandle *)handle)->pageSize) {
                *(volatile u32 *)PI_BSD_DOM1_PGS_REG = ((PiDeviceHandle *)handle)->pageSize;
            }
            if (((PiDeviceHandle *)currentHandle)->relDuration != ((PiDeviceHandle *)handle)->relDuration) {
                *(volatile u32 *)PI_BSD_DOM1_RLS_REG = ((PiDeviceHandle *)handle)->relDuration;
            }
            if (((PiDeviceHandle *)currentHandle)->pulse != ((PiDeviceHandle *)handle)->pulse) {
                *(volatile u32 *)PI_BSD_DOM1_PWD_REG = ((PiDeviceHandle *)handle)->pulse;
            }
        } else {
            if (((PiDeviceHandle *)currentHandle)->latency != ((PiDeviceHandle *)handle)->latency) {
                *(volatile u32 *)PI_BSD_DOM2_LAT_REG = ((PiDeviceHandle *)handle)->latency;
            }
            if (((PiDeviceHandle *)currentHandle)->pageSize != ((PiDeviceHandle *)handle)->pageSize) {
                *(volatile u32 *)PI_BSD_DOM2_PGS_REG = ((PiDeviceHandle *)handle)->pageSize;
            }
            if (((PiDeviceHandle *)currentHandle)->relDuration != ((PiDeviceHandle *)handle)->relDuration) {
                *(volatile u32 *)PI_BSD_DOM2_RLS_REG = ((PiDeviceHandle *)handle)->relDuration;
            }
            if (((PiDeviceHandle *)currentHandle)->pulse != ((PiDeviceHandle *)handle)->pulse) {
                *(volatile u32 *)PI_BSD_DOM2_PWD_REG = ((PiDeviceHandle *)handle)->pulse;
            }
        }
        D_801F55E0[domain] = handle;
    }
    *valueOut = *(volatile u32 *)(((PiDeviceHandle *)handle)->baseAddress | deviceAddress | PI_UNCACHED_ADDRESS_BASE);
    return 0;
}

/* __osEPiRawWriteIo: wait for the PI bus, apply device timing, and write an uncached word. */
s32 func_801D1A10(u8 *handle, u32 deviceAddress, u32 value) {
    u32 status;
    u32 domain;
    u8 *currentHandle;

    status = *(volatile u32 *)PI_STATUS_REG;
    while (status & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        status = *(volatile u32 *)PI_STATUS_REG;
    }
    domain = ((PiDeviceHandle *)handle)->domain;
    currentHandle = D_801F55E0[domain];
    if (currentHandle != handle) {
        if (domain == PI_DOMAIN1) {
            if (((PiDeviceHandle *)currentHandle)->latency != ((PiDeviceHandle *)handle)->latency) {
                *(volatile u32 *)PI_BSD_DOM1_LAT_REG = ((PiDeviceHandle *)handle)->latency;
            }
            if (((PiDeviceHandle *)currentHandle)->pageSize != ((PiDeviceHandle *)handle)->pageSize) {
                *(volatile u32 *)PI_BSD_DOM1_PGS_REG = ((PiDeviceHandle *)handle)->pageSize;
            }
            if (((PiDeviceHandle *)currentHandle)->relDuration != ((PiDeviceHandle *)handle)->relDuration) {
                *(volatile u32 *)PI_BSD_DOM1_RLS_REG = ((PiDeviceHandle *)handle)->relDuration;
            }
            if (((PiDeviceHandle *)currentHandle)->pulse != ((PiDeviceHandle *)handle)->pulse) {
                *(volatile u32 *)PI_BSD_DOM1_PWD_REG = ((PiDeviceHandle *)handle)->pulse;
            }
        } else {
            if (((PiDeviceHandle *)currentHandle)->latency != ((PiDeviceHandle *)handle)->latency) {
                *(volatile u32 *)PI_BSD_DOM2_LAT_REG = ((PiDeviceHandle *)handle)->latency;
            }
            if (((PiDeviceHandle *)currentHandle)->pageSize != ((PiDeviceHandle *)handle)->pageSize) {
                *(volatile u32 *)PI_BSD_DOM2_PGS_REG = ((PiDeviceHandle *)handle)->pageSize;
            }
            if (((PiDeviceHandle *)currentHandle)->relDuration != ((PiDeviceHandle *)handle)->relDuration) {
                *(volatile u32 *)PI_BSD_DOM2_RLS_REG = ((PiDeviceHandle *)handle)->relDuration;
            }
            if (((PiDeviceHandle *)currentHandle)->pulse != ((PiDeviceHandle *)handle)->pulse) {
                *(volatile u32 *)PI_BSD_DOM2_PWD_REG = ((PiDeviceHandle *)handle)->pulse;
            }
        }
        D_801F55E0[domain] = handle;
    }
    *(volatile u32 *)(((PiDeviceHandle *)handle)->baseAddress | deviceAddress | PI_UNCACHED_ADDRESS_BASE) = value;
    return 0;
}

/* Original compiler padding. */
const u32 D_801D1B54_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* __osPiCreateAccessQueue: create the one-slot PI access queue and put its single
 * access token in it. */
void func_801D1B60(void) {
    D_801F55F0 = 1; /* access queue initialized */
    func_801C6520((OSMesgQueue *)D_802B0CF0, (void **)D_802B0CE0, 1); /* osCreateMesgQueue */
    func_801C7560(D_802B0CF0, 0, OS_MESG_NOBLOCK); /* osSendMesg */
}

/* __osPiGetAccess: creates the one-slot PI access queue on first use (filled with
 * a single token), then blocks until the token is free, taking it. */
s32 func_801D1BB4(void) {
    s32 token;
    u8 *accessQueue;
    if (D_801F55F0 == 0) { /* access queue initialized */
        D_801F55F0 = 1;
        accessQueue = D_802B0CF0;
        func_801C6520((OSMesgQueue *)accessQueue, (void **)D_802B0CE0, 1); /* osCreateMesgQueue */
        accessQueue = 0;
        accessQueue = D_802B0CF0;
        func_801C7560(accessQueue, 0, OS_MESG_NOBLOCK); /* osSendMesg */
    }
    accessQueue = 0;
    accessQueue = D_802B0CF0;
    return func_801C7430(accessQueue, &token, OS_MESG_BLOCK); /* osRecvMesg */
}

/* __osPiRelAccess: releases the PI by posting a message to the PI access queue. */
void func_801D1C20(void) {
    func_801C7560(D_802B0CF0, 0, OS_MESG_NOBLOCK); /* osSendMesg */
}

/* Original compiler padding. */
const u32 D_801D1C48_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* osPiStartDma: fill the OSIoMesg `mb` (type DMAREAD 0xB / DMAWRITE 0xC, priority,
 * retQueue, dramAddr, devAddr, size, piHandle = NULL) and post it to the PI
 * manager's command queue (func_801D0A90, osPiGetCmdQueue): jammed to the front
 * (func_801D0950, osJamMesg) for OS_MESG_PRI_HIGH, else sent (func_801C7560,
 * osSendMesg). Returns -1 if the PI manager (D_801F55C0) is not active. */
s32 func_801D1C50(u8 *mb, s32 priority, s32 direction, s32 devAddr, s32 dramAddr, s32 size, s32 retQueue) {
    if (D_801F55C0 == 0) {
        return -1;
    }
    *(s16 *)mb = (direction == 0) ? 0xB : 0xC;  /* hdr.type: OS_READ -> DMAREAD */
    mb[2] = priority;                           /* hdr.pri */
    *(s32 *)(mb + 4) = retQueue;                /* hdr.retQueue */
    *(s32 *)(mb + 8) = dramAddr;
    *(s32 *)(mb + 0xC) = devAddr;
    *(s32 *)(mb + 0x10) = size;
    *(s32 *)(mb + 0x14) = 0;                    /* piHandle */
    if (priority == 1) {
        func_801D0950(func_801D0A90(), mb, 0);
    } else {
        func_801C7560((u8 *)func_801D0A90(), (s32)mb, 0);
    }
}

/* Original compiler padding. */
const u32 D_801D1CF8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};



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

