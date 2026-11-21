#ifndef AUDIO_ENVELOPE_H
#define AUDIO_ENVELOPE_H

#include "common.h"

/*
 * Symbol roles (N64 symbol renames are not supported by the project tools):
 * func_801C9300: envelope mixer pull; consumes timed controls and mixes samples.
 * func_801C9920: emits RSP envelope commands for one uninterrupted segment.
 * func_801C9FA4: evaluates the current gain from an exponential envelope rate.
 * func_801CA030: audio assertion hook (empty in this build).
 * func_801CB824: returns a physical voice to the synthesizer's free list.
 * func_801CB7B8: returns a consumed control record to the parameter free list.
 * D_8010C480 / D_8010C484: assertion strings "EX" / "env.c".
 * D_801F45B0: Q15 equal-power gain table, indexed by pan or dry/wet mix.
 * D_801F46D0: active synthesizer driver; legacy declarations use ObjectNode.
 */

/* libultra synthesizer filter messages and sample-block limits. */
enum AudioFilterParam {
    AL_FILTER_FREE_VOICE = 0,
    AL_FILTER_SET_SOURCE = 1,
    AL_FILTER_ADD_UPDATE = 3,
    AL_FILTER_RESET = 4,
    AL_FILTER_SET_WAVETABLE = 5,
    AL_FILTER_SET_PITCH = 7,
    AL_FILTER_SET_UNITY_PITCH = 8,
    AL_FILTER_START = 9,
    AL_FILTER_SET_VOLUME = 11,
    AL_FILTER_SET_PAN = 12,
    AL_FILTER_START_VOICE_ALT = 13,
    AL_FILTER_START_VOICE = 14,
    AL_FILTER_STOP_VOICE = 15,
    AL_FILTER_SET_FX_MIX = 16
};

/* func_801C9D24 (alEnvMixerGetRate): computes the multiplier per eight
 * samples, returning the signed integer part and a u16 fractional part.
 * Original double constants, decoded from asm/1000.s:
 * D_8010C4F0: eight log2 mantissa midpoint samples (EnvRateLogTable).
 * D_8010C530: 1.0, minimum gain and reciprocal numerator.
 * D_8010C538 / D_8010C568: 2^30, reciprocal precision / log scaling.
 * D_8010C540: 1.0, mantissa upper bound.
 * D_8010C548 / D_8010C550: 0.5, halving factor / mantissa lower bound.
 * D_8010C558: 16.0, mantissa lookup scale.
 * D_8010C560: ln(2), conversion from log2 to natural logarithm.
 * D_8010C570: 1.0, multiplicative identity.
 * D_8010C578: 65535.0, output fractional scale.
 */
enum AudioEnvelopeRateConstants {
    AL_ENVELOPE_LOG_TABLE_SIZE = 8,
    AL_ENVELOPE_LOG_INDEX_BIAS = 8,
    AL_ENVELOPE_RATE_INTEGER_MAX = 0x7FFF,
    AL_ENVELOPE_RATE_FRACTION_MAX = 0xFFFF
};

enum AudioEnvelopeConstants {
    AL_ENVELOPE_MAX_SAMPLES = 160,
    AL_ENVELOPE_PAN_MAX = 127,
    AL_ENVELOPE_VOLUME_SHIFT = 15,
    AL_PHYSICAL_VOICE_OFFSET = 0xD8
};

/* Queued envelope change (size 0x14); delta is its absolute sample time.
 * data/moredata carry the values selected by AudioFilterParam. */
typedef struct EnvParam {
    /* 0x00 */ struct EnvParam *next;
    /* 0x04 */ s32 delta;
    /* 0x08 */ s16 type;
    /* 0x0A */ s16 unity;
    /* 0x0C */ s32 data;
    /* 0x10 */ s32 moredata;
} EnvParam;

/* Combined voice-start parameters (size 0x1C); pitch/wave retain word ABI. */
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

/* Filter dispatch prefix (size 0x0C) shared with upstream audio filters. */
typedef struct EnvFilter {
    /* 0x00 */ struct EnvFilter *source;
    /* 0x04 */ void *handler;
    /* 0x08 */ s32 (*setParam)(void *, s32, s32);
} EnvFilter;

/* Envelope mixer (size 0x4C): Q15 gains, split Q16 rates,
 * elapsed/segment sample counts, and a FIFO of timed control changes.
 * first requests RSP state initialization; motion == 1 means playing.
 * func_801C9D24 computes a rate's integer part and writes its fraction.
 * func_801C7D90 converts the RSP state pointer with osVirtualToPhysical.
 */
typedef struct {
    /* 0x00 */ EnvFilter filter;
    /* 0x0C */ s16 inputBuffer;
    /* 0x0E */ s16 outputBuffer;
    /* 0x10 */ s32 type;
    /* 0x14 */ void *state;
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
    /* 0x44 */ void **sources;
    /* 0x48 */ s32 motion;
} EnvMixer;

/* Upstream pull callback: DMEM byte offset, sample count/time, command cursor. */
struct AudioCommand;
typedef struct AudioCommand *(*EnvPullHandler)(void *, s16 *, s32, s32,
                                               struct AudioCommand *);

enum AudioEnvelopeCommands {
    AUDIO_OP_ENV_MIXER = 3,
    AUDIO_OP_SET_BUFFER = 8,
    AUDIO_OP_SET_VOLUME = 9,
    AUDIO_FLAG_CONTINUE = 0,
    AUDIO_FLAG_INIT = 1,
    AUDIO_FLAG_RIGHT = 0,
    AUDIO_FLAG_LEFT = 2,
    AUDIO_FLAG_RATE = 0,
    AUDIO_FLAG_VOLUME = 4,
    AUDIO_FLAG_MAIN = 0,
    AUDIO_FLAG_AUX = 8,
    AUDIO_DMEM_MAIN_LEFT = 0x440,
    AUDIO_DMEM_MAIN_RIGHT = 0x580,
    AL_ENVELOPE_PLAYING = 1,
    AL_ENVELOPE_PAN_COUNT = 128,
    AL_ENVELOPE_SOURCE_ASSERT_LINE = 0x16F
};

#endif
