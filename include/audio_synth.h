#ifndef AUDIO_SYNTH_H
#define AUDIO_SYNTH_H

#include "common.h"

/* func_801C3758 is the libmus alSynNew variant; func_801CB310 is libultra
 * alSynNew. Both build the synthesizer and its free pools.
 * Symbol renaming is unavailable for N64 projects; helper roles are:
 * func_801CB280: alHeapDBAlloc; func_801CB1EC: alLink.
 * func_801C8698 / func_801CB160: alSaveNew / alSaveParam.
 * func_801C85E0 / func_801C92CC: alAuxBusNew / alAuxBusParam.
 * func_801C863C / func_801CA1A0: alMainBusNew / alMainBusParam.
 * func_801C84A4 / func_801C8EC0: alLoadNew / alLoadParam.
 * func_801C8554 / func_801CA3BC: alResampleNew / alResampleParam.
 * func_801C83EC / func_801C984C: alEnvmixerNew / alEnvmixerParam.
 * func_801C3A58 is the libmus effect allocator; func_801CBF70 is libultra
 * alSynAllocFX. Both allocate and connect an effect on an auxiliary bus.
 */

/* Word indices of the audio heap (libultra ALHeap, size 0x10), kept as a
 * u32 array to match the allocator's existing prototype. func_801CB240
 * (alHeapInit) sets it up; func_801CB280 (alHeapDBAlloc) allocates from it. */
enum AudioHeapWord {
    AUDIO_HEAP_BASE = 0,    /* first byte of the heap, 16-byte aligned */
    AUDIO_HEAP_CURRENT = 1, /* next free byte */
    AUDIO_HEAP_LENGTH = 2,  /* size of the heap in bytes */
    AUDIO_HEAP_COUNT = 3    /* unused allocation counter */
};

enum AudioHeapConstants {
    AUDIO_HEAP_ALIGN_LOW_BITS = 0xF /* allocations are rounded up to 16 bytes */
};

/* Physical voice storage, size 0xDC. Retain integer addresses and filter
 * word arrays to match the existing constructor interfaces. The envelope
 * storage includes its final physical-voice word at voice offset 0xD8. */
typedef struct AudioPhysicalVoice {
    /* 0x00 */ s32 link[2];
    /* 0x08 */ s32 virtualVoice;
    /* 0x0C */ s32 channelKnob;
    /* 0x10 */ s32 decoder[18];
    /* 0x58 */ s32 resampler[13];
    /* 0x8C */ s32 envelopeMixer[20];
} AudioPhysicalVoice;

/* Word indices for the existing s32* synthesizer ABI (size 0x4C).
 * Each two-word list contains next/previous pointers. */
enum AudioSynthWord {
    SYNTH_CLIENT_HEAD = 0,
    SYNTH_FREE_VOICE_NEXT = 1,
    SYNTH_FREE_VOICE_PREV = 2,
    SYNTH_ALLOCATED_VOICE_NEXT = 3,
    SYNTH_ALLOCATED_VOICE_PREV = 4,
    SYNTH_LAME_VOICE_NEXT = 5,
    SYNTH_LAME_VOICE_PREV = 6,
    SYNTH_PARAM_SAMPLES = 7,
    SYNTH_CURRENT_SAMPLES = 8,
    SYNTH_DMA_FACTORY = 9,
    SYNTH_HEAP = 10,
    SYNTH_PARAM_FREE_LIST = 11,
    SYNTH_MAIN_BUS = 12,
    SYNTH_AUX_BUS = 13,
    SYNTH_OUTPUT_FILTER = 14,
    SYNTH_MAX_PHYSICAL_VOICES = 15,
    SYNTH_AUX_BUS_COUNT = 16,
    SYNTH_OUTPUT_RATE = 17,
    SYNTH_MAX_OUTPUT_SAMPLES = 18
};

/* AudioEffectConfig's layout, accessed as words to preserve the constructor ABI. */
enum AudioSynthConfigWord {
    SYNTH_CONFIG_MAX_PHYSICAL_VOICES = 1,
    SYNTH_CONFIG_MAX_UPDATES = 2,
    SYNTH_CONFIG_DMA_FACTORY = 4,
    SYNTH_CONFIG_HEAP = 5,
    SYNTH_CONFIG_OUTPUT_RATE = 6
};

/* One auxiliary bus (SYNTH_AUX_BUS_BYTES): the bus filter, then its effect. */
typedef struct AudioSynthAuxBus {
    /* 0x00 */ u8 bus[0x20];
    /* 0x20 */ u8 effect[0x2C];
} AudioSynthAuxBus;

enum AudioSynthConstructionConstants {
    SYNTH_CONFIG_EFFECT_TYPE_OFFSET = 0x1C,
    SYNTH_CONFIG_EFFECT_PARAMS_OFFSET = 0x20, /* s32 *params for AUDIO_FX_CUSTOM */
    SYNTH_FILTER_SET_SOURCE = 1,
    SYNTH_BUS_ADD_SOURCE = 2,
    SYNTH_FILTER_SET_DRAM = 6, /* libultra AL_FILTER_SET_DRAM */
    SYNTH_OUTPUT_FILTER_BYTES = 0x1C,
    SYNTH_AUX_BUS_BYTES = 0x4C,
    SYNTH_MAIN_BUS_BYTES = 0x20,
    SYNTH_SOURCE_POINTER_BYTES = 4,
    SYNTH_PHYSICAL_VOICE_BYTES = 0xDC,
    SYNTH_PARAM_RECORD_BYTES = 0x1C,
    SYNTH_FRAME_SAMPLES = 160
};

/* Word indices of the output save filter (libultra ALSave): the ALFilter
 * header (its source first), then the DRAM output buffer. */
enum AudioSaveFilterWord {
    SAVE_FILTER_SOURCE = 0,  /* ALFilter *source */
    SAVE_FILTER_DRAM_OUT = 5 /* s32 dramout */
};

/* Word indices of a main bus (libultra ALMainBus, SYNTH_MAIN_BUS_BYTES):
 * the ALFilter header, then its sources. An auxiliary bus (ALAuxBus)
 * starts with the same words. */
enum AudioMainBusWord {
    MAIN_BUS_SOURCE_COUNT = 5, /* sources added so far */
    MAIN_BUS_MAX_SOURCES = 6,
    MAIN_BUS_SOURCES = 7       /* ALFilter *sources[maxSources] */
};

/* func_801CB5DC: alAudioFrame, schedules clients and builds an RSP audio list.
 * D_801F46D0: active AudioSynthDriver (retain its legacy global declaration).
 * func_801CB8F8: __nextSampleTime, finds the next client callback.
 * func_801CB864: _timeToSamplesNoRound, converts microseconds to samples.
 * func_801CB8AC: _timeToSamples, the same rounded and aligned to 16 samples.
 * func_801CB7D0: _collectPVoices, moves retired voices back to the free list.
 * Output filter callbacks are alSaveParam / alSavePull (func_801CB160 / CB060).
 */
/* alSavePull (func_801CB060): interleaves the main bus into the output.
 * The save filter is an s32 array: word 0 is its source, word 5 the DRAM output.
 * D_8010C610 / D_8010C614: assert expression and file strings. */
enum AudioSaveFilter {
    AUDIO_SAVE_SOURCE_WORD = 0,
    AUDIO_SAVE_PULL_HANDLER_WORD = 1,
    AUDIO_SAVE_DRAM_OUT_WORD = 5,
    AUDIO_SAVE_FIRST_WORD = 6,   /* nonzero until the first frame is saved */
    AUDIO_FILTER_TYPE_SAVE = 3,  /* AL_SAVE, alFilterNew's type argument */
    AUDIO_SAVE_SOURCE_ASSERT_LINE = 0x22,
    AUDIO_OP_SAVE_BUFFER = 6,
    AUDIO_OP_INTERLEAVE = 13
};

/* func_801C2668: libmus random number in [0, range), from the 32-bit LFSR
 * D_802AB05C (taps at bits 30 and 27), stepped 8 times per call. */
enum MusRandomConstants {
    MUS_RANDOM_TAPS = 0x48000000,
    MUS_RANDOM_TAP_LOW = 0x08000000,
    MUS_RANDOM_STEPS = 8
};

enum AudioFrameConstants {
    AUDIO_FRAME_SAMPLE_ALIGN_LOW_BITS = 0xF,
    AUDIO_FRAME_SET_OUTPUT_BUFFER = 6,
    AUDIO_FRAME_SEGMENT_COMMAND = 0x07000000,
    AUDIO_FRAME_COMMAND_BYTES = 8,
    AUDIO_FRAME_COMMAND_SHIFT = 3
};

/* func_801C3AFC (mus_effect_new) installs effect callbacks, allocates enough
 * delay sections and samples for every built-in preset, and applies the
 * configured preset. D_802AD370 uses the shared AudioEffectStorage layout.
 * func_801CA040: alFilterNew; func_801CA830: alFxParam (connect source);
 * func_801CA480: alFxPull; func_801CA844: alFxParamHdl.
 * func_801C3F30: maximum preset section count;
 * func_801C3F78: maximum preset delay-buffer sample count;
 * func_801C3C34: mus_apply_effect_preset.
 * The constructor's legacy s32 return type is retained; callers ignore it.
 */
enum AudioEffectConstructorWord {
    AUDIO_FX_PULL_HANDLER_WORD = 1,
    AUDIO_FX_PARAMETER_HANDLER_WORD = 10,
    AUDIO_FX_CONFIG_PRESET_WORD = 8
};

/* Leading words of a packed effect preset (D_801F4384 entries, read by
 * func_801C3C34): section count, then delay-buffer length in samples. */
enum AudioEffectPresetWord {
    AUDIO_FX_PRESET_SECTION_COUNT_WORD = 0,
    AUDIO_FX_PRESET_LENGTH_WORD = 1
};

enum AudioEffectAllocationBytes {
    AUDIO_FX_DELAY_SECTION_BYTES = 0x28,
    AUDIO_FX_DELAY_SAMPLE_BYTES = 2,
    AUDIO_FX_RESAMPLER_BYTES = 0x34,
    AUDIO_FX_LOW_PASS_BYTES = 0x30
};

/* func_801CBA00: alSynAllocVoice; returns whether a physical voice was obtained.
 * func_801CBB28: _allocatePVoice; returns whether the selected voice was stolen.
 * func_801CB78C: __allocParam, pops a control record from the synthesizer pool.
 * A stolen voice fades to zero over 448 samples and stops at sample offset 512.
 * The offset is word 19 of AudioPhysicalVoice.envelopeMixer, at byte 0xD8.
 */
enum AudioVoiceAllocationConstants {
    AUDIO_VOICE_STOPPED = 0,
    AUDIO_VOICE_STEAL_DELAY_SAMPLES = 512,
    AUDIO_VOICE_STEAL_SETTLE_SAMPLES = 64,
    AUDIO_PHYSICAL_VOICE_OFFSET_WORD = 19,
    AUDIO_VIRTUAL_VOICE_PHYSICAL_OFFSET = 8,
    AUDIO_FILTER_SET_PARAM_OFFSET = 8,
    AUDIO_FILTER_ADD_UPDATE = 3,
    AUDIO_SYNTH_PARAM_SAMPLES_OFFSET = 0x1C
};

#endif
