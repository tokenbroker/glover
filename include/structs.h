#ifndef STRUCTS_H
#define STRUCTS_H

#include "common.h"

/*
 * func_80181DC8: color_apply_rgb_curves, used when loading the fog RGB.
 * Each channel uses t = 1 - channel / 255: red / (1 + 0.086*t),
 * green * (1 + 0.04*t), blue / (1 + 0.06*t), then clamps to 255.
 * The original mixes f32 arithmetic with f64 coefficients.
 * Keep the pool declarations and byte-offset accesses: some doubles are
 * only 4-byte aligned and their low words have separate legacy symbols.
 * D_80108B44 / B64 / B7C: red/green/blue normalization, 1/255 (f32).
 * D_80108B48 / B68 / B80: red/green/blue complement base, 1 (f32).
 * At those complement symbols +4: strengths 0.086 / 0.04 / 0.06 (f64).
 * D_80108B50 / B88: low words of the red/blue strength doubles;
 * at each +4 is the corresponding denominator base, 1 (f64).
 * D_80108B5C / B74 / B94: red/green/blue channel maximum, 255 (f32).
 * D_80108B60 / B78 / B98: 2^31 (f32), for conversion to unsigned integer.
 */

/*
 * func_80197360: NMEInitInstruction, loads one enemy-script instruction.
 * func_801831FC copies bytes and advances the stream address;
 * func_8013FCDC allocates from the selected heap.
 * D_8010A4A4 is the allocation label "Instruct"; D_8010A4B0 is the
 * unrecognized-instruction diagnostic. func_801D2150 formats it into
 * D_8025D578 for the disabled debug hook func_80139D70.
 * The diagnostic's name buffer is uninitialized in the original.
 *
 * The stream stores opcode/duration, a 4/12/24-byte opcode-specific payload,
 * then argument, conditionLower, conditionUpper, flags and condition.
 * func_8019787C executes the instruction; func_80198310 tests its condition.
 */
typedef struct NmeInstruction {
    /* 0x00 */ s16 opcode;
    /* 0x02 */ s16 duration;
    /* 0x04 */ u32 operands[6]; /* Scalar or vector data, depending on opcode. */
    /* 0x1C */ u32 argument; /* Read as integer or float by individual opcodes. */
    /* 0x20 */ u8 unk20[8];
    /* 0x28 */ u32 flags;
    /* 0x2C */ s16 condition;
    /* 0x2E */ u8 unk2E[2];
    /* 0x30 */ f32 conditionLower;
    /* 0x34 */ u8 unk34[8];
    /* 0x3C */ f32 conditionUpper;
    /* 0x40 */ u8 unk40[8];
} NmeInstruction; /* size = 0x48 */

enum NmeInstructionFields {
    NME_INSTRUCTION_DURATION = 0x02,
    NME_INSTRUCTION_OPERANDS = 0x04,
    NME_INSTRUCTION_SECOND_VECTOR = 0x10,
    NME_INSTRUCTION_ARGUMENT = 0x1C,
    NME_INSTRUCTION_FLAGS = 0x28,
    NME_INSTRUCTION_CONDITION = 0x2C,
    NME_INSTRUCTION_CONDITION_LOWER = 0x30,
    NME_INSTRUCTION_CONDITION_UPPER = 0x3C
};

/* Libultra synthesizer list heads contain next/previous links (size 0x08). */
typedef struct AudioSynthLink {
    /* 0x00 */ void *next;
    /* 0x04 */ void *prev;
} AudioSynthLink;

/* Synthesizer driver, size 0x4C. Voice pools and pending parameter records
 * are owned by the audio heap; sample counters use output-rate samples. */
typedef struct AudioSynthDriver {
    /* 0x00 */ void *head;
    /* 0x04 */ AudioSynthLink pFreeList;
    /* 0x0C */ AudioSynthLink pAllocList;
    /* 0x14 */ AudioSynthLink pLameList;
    /* 0x1C */ s32 paramSamples;
    /* 0x20 */ s32 curSamples;
    /* 0x24 */ s32 dma;
    /* 0x28 */ u32 *heap;
    /* 0x2C */ s32 *paramList;
    /* 0x30 */ s32 *mainBus;
    /* 0x34 */ s32 *auxBus;
    /* 0x38 */ s32 *outputFilter;
    /* 0x3C */ s32 numPVoices;
    /* 0x40 */ s32 maxAuxBusses;
    /* 0x44 */ s32 outputRate;
    /* 0x48 */ s32 maxOutSamples;
} AudioSynthDriver;

/* Virtual voice (size 0x1C), bound to a physical voice by alSynAllocVoice.
 * State and priority retain the signed halfword layout used by libultra. */
typedef struct AudioVirtualVoice {
    /* 0x00 */ void *next;
    /* 0x04 */ void *prev;
    /* 0x08 */ struct AudioPhysicalVoice *physicalVoice;
    /* 0x0C */ void *wavetable;
    /* 0x10 */ void *clientPrivate;
    /* 0x14 */ s16 state;
    /* 0x16 */ s16 priority;
    /* 0x18 */ s16 fxBus;
    /* 0x1A */ s16 unityPitch;
} AudioVirtualVoice;

/* Voice allocation settings, size 0x06 including trailing alignment padding. */
typedef struct AudioVoiceConfig {
    /* 0x00 */ s16 priority;
    /* 0x02 */ s16 fxBus;
    /* 0x04 */ u8 unityPitch;
} AudioVoiceConfig;

/* libultra ALPlayer prefix; handlers return microseconds until their next call. */
typedef struct AudioSynthClient {
    /* 0x00 */ struct AudioSynthClient *next;
    /* 0x04 */ void *clientData;
    /* 0x08 */ s32 (*handler)(s32 *client);
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 nextSampleTime;
} AudioSynthClient; /* size = 0x14 */

/* ALFilter callback prefix; pull appends RSP commands for a sample interval. */
typedef struct AudioSynthFilter {
    /* 0x00 */ void *source;
    /* 0x04 */ u8 *(*pull)(u8 *filter, s16 *dmemOutput, s32 sampleCount,
                          s32 sampleOffset, u8 *commands);
    /* 0x08 */ s32 (*setParam)(u8 *filter, s32 parameter, s32 *value);
} AudioSynthFilter; /* prefix size = 0x0C */

/* Row-vector 4x4 matrix: basis vectors occupy columns, translation is row 3.
 * func_801C4190 is guLookAtF; func_801C4510 is guLookAt;
 * func_801C5440 is guMtxIdentF; func_801C5300 is guMtxF2L.
 * guMtxF2L packs signed 16.16 elements into
 * 16 u32 words: integer halfwords at +0x00, fractional halfwords at +0x20.
 * The whole libultra matrix set is src/18020_C5030.c, named function by function there.
 */
typedef f32 Matrix4f[4][4]; /* size = 0x40 */

/* func_801C5B90 is guRotateF: writes a Matrix4f using an angle in degrees
 * and an XYZ axis, normalized internally; the axis must be nonzero.
 * func_801C5CEC is guRotate: normalizes an XYZ axis, builds a row-vector
 * rotation from an angle in degrees, then packs it using guMtxF2L.
 * Its inlined guRotateF body retains separate axis copies and scratch storage.
 * func_801C5E70 is guNormalize (three separate component pointers);
 * func_801C6000 / func_801C4040 are sinf / cosf, taking radians.
 * D_801F43A0 is the f32 degrees-to-radians factor, bits 0x3C8EFA35
 * (0.01745329238). Keep its existing non-const declaration.
 */

/* func_801C5810 is guPerspectiveF: writes a Matrix4f and optionally the
 * RSP perspective-normalization factor. Its f64 pool constants are
 * D_8010C2D0 = 0.017453292222222222 (degrees to radians),
 * D_8010C2D8 = 2 (near + far saturation threshold), and
 * D_8010C2E0 = 131072 (normalization numerator).
 */

/* func_801C59C0 is guPerspective: fovy is in degrees; output uses guMtxF2L's
 * packed 16.16 layout above. A null normalization pointer skips that output.
 * Its f64 pool values in asm/1000.s are D_8010C2F0 = 0.017453292222222222 (degrees to radians),
 * D_8010C2F8 = 2 (near + far saturation threshold), D_8010C300 = 131072
 * (normalization numerator). D_8010C308 = 2147483648 is a conversion constant.
 * Preserve the pool accesses and inlined floating-point matrix temporaries.
 */
enum PerspectiveNormalizationLimits {
    PERSPECTIVE_NORMALIZATION_MAX = 0xFFFF,
    PERSPECTIVE_NORMALIZATION_MIN = 1
};

/* func_801CF0C0 is __osViSwapContext; func_801C7D90 is osVirtualToPhysical.
 * D_801F4760 points to the current VI context, D_801F4764 to the next.
 * This view names the fields without changing the legacy context declarations.
 * The original context representation ends at +0x30; retain that copy size. */
typedef struct ViContextView {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ u32 framebuffer;
    /* 0x08 */ struct Unk801F4764 *mode;
    /* 0x0C */ u32 control;
    /* 0x10 */ void *msgQueue; /* retrace message queue (osViSetEvent) */
    /* 0x14 */ void *msg;
    /* 0x18 */ u8 unk18[0x08];
    /* 0x20 */ u32 xScale;
    /* 0x24 */ f32 yScaleFactor;
    /* 0x28 */ u16 yOffset;
    /* 0x2A */ u16 unk2A;
    /* 0x2C */ u32 yScale;
} ViContextView; /* size = 0x30 */

enum ViContextState {
    VI_STATE_MODE_UPDATED = 0x01, /* a new mode was set: reload every register */
    VI_STATE_XSCALE = 0x02,
    VI_STATE_YSCALE = 0x04,
    VI_STATE_CONTROL = 0x08,
    VI_STATE_BLACK = 0x20,
    VI_STATE_REPEAT_LINE = 0x40,
    VI_STATE_FADE = 0x80
};

/* func_801CEEB0 is osViSetSpecialFeatures; D_801F4764 is __osViNext.
 * func_801C6F70 / func_801C6F90 disable / restore interrupts.
 * OFF requests override ON requests. Disabling dither filtering restores
 * the selected mode's antialiasing bits.
 */
enum ViSpecialFeatures {
    OS_VI_GAMMA_ON = 0x01,
    OS_VI_GAMMA_OFF = 0x02,
    OS_VI_GAMMA_DITHER_ON = 0x04,
    OS_VI_GAMMA_DITHER_OFF = 0x08,
    OS_VI_DIVOT_ON = 0x10,
    OS_VI_DIVOT_OFF = 0x20,
    OS_VI_DITHER_FILTER_ON = 0x40,
    OS_VI_DITHER_FILTER_OFF = 0x80
};

enum ViControlBits {
    VI_CTRL_GAMMA_DITHER_ON = 0x04,
    VI_CTRL_GAMMA_ON = 0x08,
    VI_CTRL_DIVOT_ON = 0x10,
    VI_CTRL_ANTIALIAS_MASK = 0x300,
    VI_CTRL_DITHER_FILTER_ON = 0x10000
};

enum ViScaleFields {
    VI_SCALE_MASK = 0xFFF,
    VI_Y_OFFSET_MASK = 0x3FF,
    VI_Y_OFFSET_SHIFT = 16
};

/* Uncached VI MMIO addresses; access each as volatile u32. */
enum ViRegisterAddress {
    VI_STATUS_REG = 0xA4400000,
    VI_ORIGIN_REG = 0xA4400004,
    VI_WIDTH_REG = 0xA4400008,
    VI_INTR_REG = 0xA440000C,
    VI_CURRENT_REG = 0xA4400010,
    VI_BURST_REG = 0xA4400014,
    VI_V_SYNC_REG = 0xA4400018,
    VI_H_SYNC_REG = 0xA440001C,
    VI_LEAP_REG = 0xA4400020,
    VI_H_START_REG = 0xA4400024,
    VI_V_START_REG = 0xA4400028,
    VI_V_BURST_REG = 0xA440002C,
    VI_X_SCALE_REG = 0xA4400030,
    VI_Y_SCALE_REG = 0xA4400034
};

/* Actor destruction (func_80179F5C) uses these layout views without changing
 * the integer storage used by other functions. Unknown owned allocations retain
 * their offset names. ActorCleanupView is a prefix through 0x168, not a size claim.
 * unk38 owns 20 allocations; unk11C starts the rotation quaternion; unk164 starts
 * a three-word sound state. Subobject sound states start at +18, +28 or +74.
 * ActorReferenceSlots holds four actor references at +178 (prefix size 0x188).
 * ActorCleanupNodeView overlays different node kinds: attached effects use +C
 * as their owner, +10 as a borrowed vector, +14 as position and +20 as a copied
 * vector; actors use +20 as their parent. Object/particle references are at +D8.
 * Its 0x120 size is the particle stride, not the allocation size of each kind.
 * ActorVectorWords copies three vector words verbatim (size 0xC).
 * ActorSoundOwnerView maps sound handles through +74 (prefix size 0x78).
 *
 * func_80178704 stops an actor sound; func_801499A0 rotates by a quaternion;
 * func_801A6AEC destroys an attached effect; func_801627AC destroys an object;
 * func_80141720 frees and clears an allocation.
 * D_802904D4/D_802904D0 are the actor list sentinel/count.
 * D_8029F170 is the attached-effect list; D_80290130 is the effect preserved
 * when its actor is removed. D_8026A148 is the object list sentinel.
 * D_802A2000 is the particle pool; D_802A20E4/D_802A20D8 alias its active byte
 * and reference-holder pointer with a 0x120 stride.
 */
enum ActorCleanupConstants {
    ACTOR_OWNED_ALLOCATION_COUNT = 20,
    ACTOR_OBJECT_OFFSET = 0x80
};

typedef struct ActorVectorWords {
    /* 0x000 */ s32 a;
    /* 0x004 */ s32 b;
    /* 0x008 */ s32 c;
} ActorVectorWords;
typedef struct ActorSoundOwnerView {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ s32 unk18;
    /* 0x01C */ u8 pad1C[0xC];
    /* 0x028 */ s32 unk28;
    /* 0x02C */ u8 pad2C[0x48];
    /* 0x074 */ s32 unk74;
} ActorSoundOwnerView;
typedef struct ActorCleanupView {
    /* 0x000 */ struct ActorCleanupView *next;
    /* 0x004 */ struct ActorCleanupView *prev;
    /* 0x008 */ u8 pad8[0x1C];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ ActorSoundOwnerView *unk28;
    /* 0x02C */ ActorSoundOwnerView *unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 *unk38;
    /* 0x03C */ ActorSoundOwnerView *unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05C */ u8 pad5C[0x58];
    /* 0x0B4 */ f32 x;
    /* 0x0B8 */ f32 y;
    /* 0x0BC */ f32 z;
    /* 0x0C0 */ u8 padC0[0x5C];
    /* 0x11C */ s32 unk11C;
    /* 0x120 */ u8 pad120[0x40];
    /* 0x160 */ s32 unk160;
    /* 0x164 */ s32 unk164;
} ActorCleanupView;
typedef struct ActorReferenceSlots {
    /* 0x000 */ u8 pad0[0x178];
    /* 0x178 */ ActorCleanupView *slot[4];
} ActorReferenceSlots;
typedef struct ActorCleanupNodeView {
    /* 0x000 */ struct ActorCleanupNodeView *next;
    /* 0x004 */ u8 pad4[8];
    /* 0x00C */ ActorCleanupView *unkC;
    /* 0x010 */ s32 *unk10;
    /* 0x014 */ f32 x;
    /* 0x018 */ f32 y;
    /* 0x01C */ f32 z;
    /* 0x020 */ s32 u20;
    /* 0x024 */ s32 u24;
    /* 0x028 */ s32 u28;
    /* 0x02C */ u8 pad2C[0xAC];
    /* 0x0D8 */ ActorReferenceSlots *holder;
    /* 0x0DC */ u8 padDC[8];
    /* 0x0E4 */ u8 flag;
    /* 0x0E5 */ u8 padE5[0x3B];
} ActorCleanupNodeView;

/* Strided views of separately labelled fields inside the particle pool. */
typedef struct ParticleActiveFieldView {
    /* 0x000 */ u8 flag;
    /* 0x001 */ u8 pad[0x11F];
} ParticleActiveFieldView; /* size = 0x120 */

typedef struct ParticleActorRefsFieldView {
    /* 0x000 */ ActorReferenceSlots *holder;
    /* 0x004 */ u8 pad[0x11C];
} ParticleActorRefsFieldView; /* size = 0x120 */


/*
 * Ending credits (func_801320E8).
 * D_801FA740: displayed cheat index; D_801FA748: horizontal slide offset.
 * D_801FA744: fade alpha; D_801FA747 aliases its low byte on big-endian N64.
 * D_801FA74C: hides cheats when the save-bit check fails.
 * D_801F21BC: cheat names at the start of 44-byte records; D_801F21DC:
 * eight input codes at record offset 0x20, with the same 44-byte stride.
 * D_801F2198: eight-code input buffer; D_802AAFF0: converted glyph string.
 * D_801F6CB0: credit entry index; D_801EAF00: pairs of name/heading pointers.
 * func_801BC43C converts/displays cheat input; func_80114784 animates credits.
 * func_8012C2B0 fills bytes; func_80145680 selects a font (0 normal, 1 alternate);
 * func_801469E4 queues text with position, RGBA, scale and centering arguments.
 * Pool entries D_80101F1C..D_80101F34 are slide start (320), divisor (4),
 * step limits (-50, 50), minimum offset (1), center X (160), and scale (1).
 */
enum EndingCreditsConstants {
    CREDITS_LEVEL = 45,
    CREDITS_INIT_FRAMES = 10,
    CREDITS_SAVE_CHECK_COUNT = 6,
    CREDITS_SAVE_FIRST_BIT = 4,
    CREDITS_SAVE_BIT_STRIDE = 5,
    CREDITS_SAVE_SLOT_BYTES = 28,
    CREDITS_CHEAT_PERIOD = 100,
    CREDITS_CHEAT_COUNT = 26,
    CREDITS_CHEAT_START_FRAME = 1300,
    CREDITS_CHEAT_FADE_FRAME = 81,
    CREDITS_CHEAT_FADE_STEP = 15,
    CREDITS_CHEAT_CODE_LENGTH = 8,
    CREDITS_CHEAT_RECORD_BYTES = 44,
    CREDITS_CHEAT_CODE_Y = 110,
    CREDITS_CHEAT_NAME_Y = 135,
    CREDITS_TEXT_START_FRAME = 21,
    CREDITS_TEXT_HOLD_FRAMES = 51,
    CREDITS_TEXT_CENTER_X = 160,
    CREDITS_HEADING_Y = 180,
    CREDITS_NAME_Y = 200,
    CREDITS_NAME_Y_DIVISOR = 3,
    CREDITS_ENTRY_BYTES = 8,
    TEXT_CHANNEL_MAX = 255,
    TEXT_FONT_NORMAL = 0,
    TEXT_FONT_ALTERNATE = 1
};

/* func_801456DC (text_init_fonts) loads the generic texture bank and
 * resolves both fonts' glyph image offsets.
 * func_8014F510: texture_load_bank; func_8014FCF8: texture_find_by_id;
 * func_80139CA0: crc32_string; func_801D20F8: string_length.
 * D_80106114 / D_80106124: "bigfinal.bmp" / "helpfnt3.bmp".
 * D_801EC900 / D_802846F0: normal / alternate font texture.
 * D_801EC908 / D_801EC940: terminated character maps.
 * D_801EC994 / D_801ECA00: glyph image byte offsets from texture pixels.
 * D_801ECAAC / D_801ECE0C: image-address fields, at offset 8 in each
 * TextGlyphBitmap, with a 16-byte stride.
 * D_801ED324 / D_801ED338: normal / alternate font descriptors.
 * D_801ED32C / D_801ED340: descriptor pixel-base addresses.
 * D_801ED330 / D_801ED344: descriptor texture pointers.
 * D_802846F4: current font; D_80201004 / D_802004E0: frame / state counters.
 * Existing global declarations retain their types; these views name accesses.
 */
enum TextFontInitConstants {
    TEXT_GENERIC_TEXTURE_BANK = 10
};

typedef struct TextTexturePixelsView {
    /* 0x00 */ u8 unk0[0x1C];
    /* 0x1C */ s32 pixelsAddress;
} TextTexturePixelsView; /* size = 0x20; accessed prefix */

/* Glyph bitmap copied into a text sprite; width -1 terminates the list.
 * A zero image address advances the layout without drawing a bitmap. */
typedef struct TextGlyphBitmap {
    /* 0x00 */ s16 width;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s32 imageAddress;
    /* 0x0C */ s16 height;
    /* 0x0E */ s16 unkE;
} TextGlyphBitmap; /* size = 0x10 */

/* Accessed prefix of SpriteText; legacy declarations retain their types. */
typedef struct TextSpriteView {
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
    /* 0x34 */ TextGlyphBitmap *glyphs;
    /* 0x38 */ void *buf0; /* default display-list buffer */
    /* 0x3C */ void *buf1; /* current display-list cursor */
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
} TextSpriteView; /* size = 0x44 */

/* Font prefix: each byte in the terminated character map selects one bitmap.
 * The character-map address stays an s32 to preserve existing address arithmetic. */
typedef struct TextFontGlyphMap {
    /* 0x00 */ s32 characterMapAddress;
    /* 0x04 */ TextGlyphBitmap *glyphs;
} TextFontGlyphMap; /* size = 0x08; accessed prefix */

/* func_80145928 (text_measure_width) uses glyph zero for unknown characters.
 * It scales the summed glyph widths, then adds count * xSpacing when the
 * string has at least two characters. Its third argument is unused.
 * D_802846F4 selects the current font; the normal/alternate descriptors
 * initialize signed xSpacing to -3/-1. The renderer reads its low halfword.
 */
typedef struct TextFontMetricsView {
    /* 0x00 */ s32 characterMapAddress;
    /* 0x04 */ u8 *glyphData;
    /* 0x08 */ u8 unk8[8];
    /* 0x10 */ s32 xSpacing;
} TextFontMetricsView; /* size = 0x14 */

enum TextFontMetricsConstants {
    TEXT_GLYPH_BITMAP_STRIDE = 0x10
};

/* func_80145EAC: text_draw_entries. D_80284800 is the circular text-list
 * sentinel; D_80202240 is the display-list write cursor. Entries marked
 * DRAW_ONCE become PENDING_DELETE after drawing; func_80145D88 frees them.
 * func_80146380/80146468 begin/end text rendering; func_801464FC sets
 * screen X/Y, func_80146594 sets RGBA, func_8014653C sets X/Y scale,
 * and func_8014666C draws the string with its saved font.
 * This view preserves the legacy field widths and global declarations.
 * N64 symbol renaming is unavailable; these comments record the roles.
 */
typedef struct TextEntryView {
    /* 0x00 */ struct TextEntryView *next;
    /* 0x04 */ s32 previousAddress;
    /* 0x08 */ u8 text[0x40];
    /* 0x48 */ s32 x;
    /* 0x4C */ s32 y;
    /* 0x50 */ f32 scaleX;
    /* 0x54 */ f32 scaleY;
    /* 0x58 */ u8 red;
    /* 0x59 */ u8 green;
    /* 0x5A */ u8 blue;
    /* 0x5B */ u8 alpha;
    /* 0x5C */ s32 state;
    /* 0x60 */ s32 fontAddress;
} TextEntryView; /* size = 0x64 */

/* Centering view preserves the float/raw-word access used by text_add_entry. */
typedef struct TextEntryCenteringView {
    /* 0x00 */ u8 unk0[0x48];
    /* 0x48 */ s32 x;
    /* 0x4C */ s32 y;
    /* 0x50 */ f32 scaleX;
    /* 0x54 */ union {
        f32 value;
        s32 bits;
    } scaleY;
    /* 0x58 */ u8 unk58[8];
    /* 0x60 */ s32 fontAddress;
} TextEntryCenteringView; /* size = 0x64 */

enum TextEntryState {
    TEXT_ENTRY_DRAW_ONCE = 1,
    TEXT_ENTRY_PENDING_DELETE = 2
};

enum TextEntryConstants {
    TEXT_ENTRY_STRING_OFFSET = 8
};

/* func_80145B98: text_add_entry saves the current font and optionally centers
 * the entry before inserting it after the sentinel's next node.
 * D_801EC904 guards list insertion against deferred deletion;
 * D_80284864 counts linked text entries. D_80106134 divides the measured
 * width for horizontal centering; D_80106138[0] is the vertical offset
 * multiplied by scaleY. scaleY is also passed as raw s32 bits to the unused
 * third argument of func_80145928 (text_measure_width).
 */

/* Font rendering metadata read by func_8014666C (text_draw_sprite). */
typedef struct TextFontPaletteView {
    /* 0x00 */ u8 unk0[0x20];
    /* 0x20 */ s32 paletteAddress;
} TextFontPaletteView; /* size = 0x24; accessed prefix */

typedef struct TextFontRenderView {
    /* 0x00 */ u8 *characterMap;
    /* 0x04 */ TextGlyphBitmap *glyphs;
    /* 0x08 */ u8 unk8[4];
    /* 0x0C */ TextFontPaletteView *sprite;
    /* 0x10 */ u8 unk10[2];
    /* 0x12 */ u16 xSpacing;
} TextFontRenderView; /* size = 0x14; accessed prefix */

/* Text renderer state (original symbol names retained):
 * D_801ED34C: reusable text sprite; its unk20 is the palette address.
 * D_801ED390/391/392/393: red/green/blue/alpha.
 * D_801ED394/398: screen X/Y; D_801ED39C/3A0: grid columns/rows.
 * D_801ED3A8/3B0: X/Y scale, accessed as doubles; D_801ED3B8: text length.
 * D_801EC7F4: render buffer index; D_8028DA38: sprite display-list cursor.
 * D_80284F58 and D_80289458: alternate sprite command-buffer bases;
 * the capacity check reserves 0x60 bytes per input character.
 * func_801D20F8: strlen; func_80146008: text_build_sprite_grid.
 * func_80146594: text_set_color (sets D_801ED390..393).
 * func_801CC0E8/CC010/CC050: set sprite position/color/scale.
 * func_801CD578: build sprite display list and advance buf1.
 */
enum TextGridConstants {
    TEXT_GRID_CELL_SIZE = 16,
    TEXT_GLYPH_LIST_END = -1,
    TEXT_SPRITE_BUFFER_CAPACITY = 180,
    TEXT_SPRITE_COLUMN_WIDTH = 8,
    TEXT_SPRITE_BOUND_MARGIN = 8,
    TEXT_SPRITE_CALL_DISPLAY_LIST = 0x06000000
};

/* func_801462E0 (text_find_character) returns the address of a matching
 * nonzero byte in a terminated string, or zero when absent. */

/* Byte codes used by func_80146CC8 (text_encode_glyphs).
 * Letters A-Z and digits 1-9 use separate ASCII offsets; zero and supported
 * punctuation have individual codes. Other input bytes pass through unchanged.
 * func_80146B98 (text_encode_numeric_glyphs) converts only digits and spaces.
 * Both encoders truncate the length returned by func_801D20F8 (strlen) to u8. */
enum TextGlyphCode {
    TEXT_GLYPH_UPPERCASE_OFFSET = 0x60,
    TEXT_GLYPH_DIGIT_OFFSET = 0x90,
    TEXT_GLYPH_EXCLAMATION = 0xBB,
    TEXT_GLYPH_HYPHEN = 0xBE,
    TEXT_GLYPH_SLASH = 0xC0,
    TEXT_GLYPH_ZERO = 0xCA,
    TEXT_GLYPH_PERIOD = 0xCD,
    TEXT_GLYPH_LEFT_BRACKET = 0xCF,
    TEXT_GLYPH_RIGHT_BRACKET = 0xD0,
    TEXT_GLYPH_COLON = 0xD2,
    TEXT_GLYPH_SPACE = 0xE4
};

/* Credit animation state: D_801F6C9C counts hold frames, D_801F6CA0 selects
 * the current heading, and D_801F6CB0 selects the current name.
 * D_801F6CB4 is the horizontal slide/fade offset; D_801F6CB8 is the name's
 * vertical offset before division by three. Empty names mark heading changes.
 * D_801EAF04 aliases the heading word of the first D_801EAF00 entry.
 *
 * Float pool for func_80114784 (keep distinct entries and existing types):
 * D_8010062C = advance threshold (500); D_80100630 = slide start (-300);
 * D_80100634 = name start offset (300); D_80100638 = snap threshold (-1);
 * D_8010063C = entry divisor (3).
 * D_80100640/4C = exit-step test divisor (2), D_80100644/50 = minimum step (1),
 * D_80100648/54 = actual exit-step divisor (3), for name/slide respectively.
 * D_80100658..64 = heading alpha bases (255), D_80100668..74 = name alpha
 * bases (255); each group has separate outgoing/incoming test/result entries.
 * D_80100678/7C/80 = moving heading/stationary heading/name scale (1).
 */

/* Flags used by the libc printf field formatter. */
enum PrintfFormatFlags {
    PRINTF_SPACE_SIGN = 0x01,
    PRINTF_FORCE_SIGN = 0x02,
    PRINTF_LEFT_JUSTIFY = 0x04,
    PRINTF_ALTERNATE_FORM = 0x08,
    PRINTF_ZERO_PAD = 0x10
};

/* _Ldtob (func_801D3020) generates decimal digits; _Dunscale
 * (func_801D3460) classifies the double and extracts its binary exponent.
 * func_801D2E60 is ldiv; func_801D34F8 lays out the rounded digits.
 * Original pool: D_8010C8B0[i] = 10^(2^i), i = 0..8;
 * D_8010C8F8 = "NaN", D_8010C8FC = "Inf", D_8010C900 = 1.0,
 * D_8010C908 = 100000000.0 (eight decimal digits per generated block). */
enum PrintfDoubleClass {
    PRINTF_DOUBLE_FINITE = -1,
    PRINTF_DOUBLE_ZERO = 0,
    PRINTF_DOUBLE_INFINITY = 1,
    PRINTF_DOUBLE_NAN = 2
};

enum PrintfDecimalConstants {
    PRINTF_DEFAULT_PRECISION = 6,
    PRINTF_DIGIT_BUFFER_BYTES = 32,
    PRINTF_DECIMAL_BLOCK_DIGITS = 8,
    PRINTF_DECIMAL_DIGIT_LIMIT = 20,
    PRINTF_LOG10_2_NUMERATOR = 30103,
    PRINTF_LOG10_2_DENOMINATOR = 100000
};

/*
 * _Litob (func_801D2C10) generates octal, decimal, or hexadecimal digits.
 * D_801F5650 / D_801F5664 are lowercase / uppercase hexadecimal digit tables.
 * func_801D3B40 is __udivdi3; func_801D2EE4 returns signed quotient/remainder;
 * func_801D211C copies the finished digit string (memcpy).
 */
enum PrintfIntegerConstants {
    PRINTF_INTEGER_BUFFER_BYTES = 24
};

/* Signed 64-bit quotient/remainder returned by lldiv (func_801D2EE4).
 * Used by printf after extracting the first unsigned digit.
 * func_801D3AA0 is libgcc's __divdi3 signed quotient helper. */
typedef struct PrintfLongLongDiv {
    /* 0x00 */ s64 quot;
    /* 0x08 */ s64 rem;
} PrintfLongLongDiv; /* size = 0x10 */

/* Signed long division result used while extracting decimal digits. */
typedef struct PrintfLongDiv {
    /* 0x00 */ s32 quot;
    /* 0x04 */ s32 rem;
} PrintfLongDiv; /* size = 0x08 */

/* The sign bit is in the first halfword of an N64 big-endian double. */
/* func_801C6000 is libultra sinf (radians). Its classification key contains
 * the IEEE-754 exponent and top fraction bit, with the sign removed.
 * D_8010C318/320/328/330 are the x^3/x^5/x^7/x^9 coefficients.
 * D_8010C338 is 1/pi; D_8010C340 and D_8010C348 split pi into high/low parts.
 * D_8010C358 and D_8010C360 are separate 0.5 rounding constants.
 * D_8010C270 holds the N64 NaN bit pattern 0x7F810000.
 * D_8010C350 is zero, returned for non-NaN inputs with magnitude >= 2^28.
 * Symbol names are retained because N64 symbol renaming is unsupported. */
enum LibultraSineConstants {
    SINE_CLASS_SHIFT = 22,
    SINE_CLASS_MASK = 0x1FF,
    SINE_TINY_CLASS_LIMIT = 0xE6,       /* 2^-12 */
    SINE_DIRECT_CLASS_LIMIT = 0xFF,    /* 1.5 */
    SINE_REDUCTION_CLASS_LIMIT = 0x136 /* 2^28 */
};

enum PrintfFloatBits {
    PRINTF_DOUBLE_SIGN_MASK = 0x8000
};

/* Formatter helpers: func_801D2750 (_Putfld) consumes one conversion argument;
 * func_801D2C10 (_Litob) formats integer digits, func_801D3020 (_Ldtob) formats
 * floating-point digits, and func_801D20F8 is strlen.
 * PUTFLD_ARG advances the KMC va_list with the argument type's alignment.
 */

/* Printf conversion state (size 0x38); segment names follow the libc formatter.
 * Emit n0 prefix bytes, nz0 zeros, n1 text bytes, nz1 zeros,
 * n2 further text bytes, and nz2 trailing zeros, in that order. */
typedef struct PrintfFieldArgs {
    /* 0x00 */ union {
        s64 ll;                  /* Integer argument. */
        f64 ld;                  /* Floating-point argument. */
    } v;
    /* 0x08 */ char *s;           /* First text segment; second follows n1 bytes later. */
    /* 0x0C */ s32 n0;            /* Prefix length in the caller's scratch buffer. */
    /* 0x10 */ s32 nz0;           /* Zeros before the first text segment. */
    /* 0x14 */ s32 n1;            /* First text segment length. */
    /* 0x18 */ s32 nz1;           /* Zeros between the text segments. */
    /* 0x1C */ s32 n2;            /* Second text segment length. */
    /* 0x20 */ s32 nz2;           /* Trailing zero count. */
    /* 0x24 */ s32 prec;          /* Precision; negative means unspecified. */
    /* 0x28 */ s32 width;         /* Field width, then remaining space padding. */
    /* 0x2C */ u32 nchar;         /* Successfully emitted character count. */
    /* 0x30 */ u32 flags;         /* PrintfFormatFlags bits. */
    /* 0x34 */ u8 qual;           /* Length qualifier: h, l, or L (also ll). */
} PrintfFieldArgs;

/*
 * Floating-point view of the printf conversion state (size 0x38).
 * Output order: sign/prefix (n0), nz0 zeros, s[0..n1), nz1 zeros,
 * s[n1..n1+n2), then nz2 zeros. Zero runs are emitted by the caller.
 */
typedef struct PrintfFloatArgs {
    /* 0x00 */ f64 d;       /* Value being converted. */
    /* 0x08 */ char *s;     /* Buffer holding the two non-padding segments. */
    /* 0x0C */ s32 n0;      /* Sign/prefix length in the caller's buffer. */
    /* 0x10 */ s32 nz0;     /* Zeros between the prefix and first segment. */
    /* 0x14 */ s32 n1;      /* First segment length. */
    /* 0x18 */ s32 nz1;     /* Zeros between the two segments. */
    /* 0x1C */ s32 n2;      /* Second segment length. */
    /* 0x20 */ s32 nz2;     /* Trailing zeros. */
    /* 0x24 */ s32 prec;    /* Requested precision; adjusted during formatting. */
    /* 0x28 */ s32 width;   /* Minimum field width. */
    /* 0x2C */ s32 nchar;   /* Characters emitted by printf so far. */
    /* 0x30 */ u32 flags;   /* PrintfFormatFlags bits. */
} PrintfFloatArgs;

/*
 * ObjectNode — main game object struct
 * Linked list head: D_8026A148 (circular doubly-linked list)
 * Also used via D_8028F350
 *
 * Field names are provisional; derived from asm access patterns.
 * Fields accessed as both s32 and f32 are typed f32 (lw used for
 * bitwise copy to function args in O32 ABI).
 */
typedef struct ObjectNode {
    /* 0x000 */ struct ObjectNode *next;
/* 0x004 */ s32 unk004;
    /* 0x008 */ s32 unk008;
    /* 0x00C */ s32 unk00C;
    /* 0x010 */ s32 unk010;
    /* 0x014 */ s32 unk014;
    /* 0x018 */ s32 unk018;
    /* 0x01C */ s32 displayList;      /* Gfx* — allocated by func_8013FCDC, freed by func_80141720 */
    /* 0x020 */ s16 type;             /* compared against 0x3C */
    /* 0x022 */ u8 pad022[0x2];
    /* 0x024 */ struct ObjectNode *parent;  /* owner/parent node */
    /* 0x028 */ s32 unk028;
    /* 0x02C */ s32 unk02C;
    /* 0x030 */ s32 unk030;
    /* 0x034 */ s32 posX;            /* f32 bitwise — passed as s32 via lw/$a regs */
    /* 0x038 */ s32 posY;
    /* 0x03C */ s32 posZ;
    /* 0x040 */ f32 unk040;
    /* 0x044 */ f32 unk044;
    /* 0x048 */ s32 unk048;
    /* 0x04C */ f32 unk04C;
    /* 0x050 */ u8 pad050[0x4];
    /* 0x054 */ s32 unk054;           /* sort key for the list at D_8028F350 */
    /* 0x058 */ s16 unk058;
    /* 0x05A */ s16 unk05A;
    /* 0x05C */ u8 pad05C[0x4];
    /* 0x060 */ f32 unk060;
    /* 0x064 */ f32 unk064;
    /* 0x068 */ f32 unk068;
    /* 0x06C */ u8 unk06C;
    /* 0x06D */ u8 unk06D;
    /* 0x06E */ u8 unk06E;
    /* 0x06F */ u8 unk06F;
    /* 0x070 */ u8 pad070[0x2C];
    /* 0x09C */ s32 rotW;             /* quaternion — copied from D_801ED3D0[0] */
    /* 0x0A0 */ s32 rotX;             /* quaternion — copied from D_801ED3D0[1] */
    /* 0x0A4 */ s32 rotY;             /* quaternion — copied from D_801ED3D0[2] */
    /* 0x0A8 */ s32 rotZ;             /* quaternion — copied from D_801ED3D0[3] */
    /* 0x0AC */ u8 pad0AC[0x10];
    /* 0x0BC */ s32 scaleX;
    /* 0x0C0 */ s32 scaleY;
    /* 0x0C4 */ s32 scaleZ;
    /* 0x0C8 */ s32 meshRef;          /* model/mesh reference, checked != 0 */
    /* 0x0CC */ u8 pad0CC[0x4];
    /* 0x0D0 */ s32 unk0D0;
    /* 0x0D4 */ u8 pad0D4[0x8];
    /* 0x0DC */ s32 unk0DC;
    /* 0x0E0 */ u8 pad0E0[0x29];
    /* 0x109 */ u8 unk109;
    /* 0x10A */ u8 unk10A;
    /* 0x10B */ u8 unk10B;
    /* 0x10C */ u8 pad10C[0x4];
} ObjectNode; /* size = 0x110 */

extern ObjectNode D_8026A148;  /* linked list head */

/* func_80160920: object_add_rotated_velocity.
 * func_801499A0: vec3_rotate_quaternion; D_80107354 is forward Z = 1.0f.
 * Object motion fields use raw accesses because ObjectNode also represents
 * layouts with different field types. Speed is the cached XYZ magnitude.
 * Horizontal limiting tests XZ magnitude but divides by the cached XYZ speed. */
/* func_80155B90 confines an object within a sphere: +0x30 is its radius,
 * ACTOR_POSITION is its center, and OBJECT_VELOCITY_X/Y/Z its velocity.
 * ACTOR_MODEL_STATE points to collision state; ACTOR_MODEL_CONTACT_COUNT
 * is set to one when the enclosing sphere pushes the object upward.
 * func_80148D0C adds a scaled vector in place. D_80106EC4 is 1.0f,
 * the normalization numerator (verified in the original data at ROM 0x7EC4).
 * Raw accesses preserve the shared object layouts and aliasing behavior. */
enum ObjectSphereContainmentOffset {
    OBJECT_CONTAINMENT_RADIUS = 0x30
};

/* func_801B8F84: object_intersects_segment_projection.
 * Tests the sphere at ACTOR_POSITION against a nonzero-length segment.
 * Rejects center projections outside the segment and excludes tangency;
 * endpoint overlaps are not tested separately. The radius is an f32 at +0x30.
 * func_80148CC8: vec3_add_scaled (output = origin + direction * distance).
 * D_8010BE7C is the pooled normalization numerator, 1.0f.
 * Raw float accesses preserve the shared ObjectNode layout and aliasing.
 */
enum ObjectSegmentTestOffset {
    OBJECT_SEGMENT_TEST_RADIUS = 0x30
};

enum ObjectMotionOffset { /* func_8016049C: object_accelerate_forward; sinf/cosf are func_801C6000/func_801C4040. */
    OBJECT_MOTION_FLAGS = 0x28,
    OBJECT_VELOCITY_X = 0x58,
    OBJECT_VELOCITY_Y = 0x5C,
    OBJECT_VELOCITY_Z = 0x60,
    OBJECT_SPEED = 0x74
};

enum ObjectMotionFlags {
    OBJECT_BYPASS_SPEED_LIMIT = 0x01000000
};

/* func_80160B6C: object_accelerate_along_source_yaw. ACTOR_YAW is radians;
 * func_801C6000 / func_801C4040 compute sine / cosine. Acceleration affects
 * X/Z, but the speed cap rescales all three velocity components.
 * A float view starting at OBJECT_VELOCITY_X reaches the cached speed at
 * index 7 (OBJECT_SPEED), with unrelated fields in indices 3 through 6. */
enum ObjectVelocityViewIndex {
    OBJECT_VELOCITY_SPEED_INDEX = 7
};

/* func_80160CC4: object_accelerate_xz_along_source_yaw. Adds acceleration
 * along ACTOR_YAW using func_801C6000 (sinf) and func_801C4040 (cosf).
 * Tests horizontal speed against the limit, then scales only X/Z using the
 * existing OBJECT_SPEED as divisor. Recomputes total speed only if limited. */

/* Message ring buffer with sentinel-terminated queues of blocked threads. */
typedef struct {
    /* 0x00 */ void *mtqueue;  /* Receivers waiting for a message. */
    /* 0x04 */ void *fullqueue; /* Senders waiting for free space. */
    /* 0x08 */ s32 validCount; /* Number of queued messages. */
    /* 0x0C */ s32 first;      /* Index of the next message to receive. */
    /* 0x10 */ s32 msgCount;   /* Ring capacity. */
    /* 0x14 */ void **msg;     /* Message storage. */
} OSMesgQueue; /* size = 0x18 */

/* func_801D0950 = osJamMesg (insert at the front of the message ring).
 * func_801C6F70 / func_801C6F90 = __osDisableInt / __osRestoreInt;
 * func_801C6C84 = __osEnqueueAndYield; func_801C6DD4 = __osPopThread;
 * func_801C7860 = osStartThread; D_801F4400 = __osRunningThread.
 * The running thread's state is a halfword at offset 0x10. */
/* func_801C7560 (osSendMesg) appends a message and wakes one receiver;
 * blocking sends yield on fullqueue until the ring has free space.
 * func_801C7430 (osRecvMesg) removes the oldest message and wakes one sender.
 * A NULL output discards the message; OS_MESG_NOBLOCK returns -1 if empty.
 * Other receive flags wait on mtqueue. Thread queues end in a sentinel
 * whose next pointer is NULL; the queue head itself is never NULL. */
enum OsMessageThreadConstants {
    OS_MESG_FULLQUEUE_OFFSET = 0x04,
    OS_THREAD_STATE_OFFSET = 0x10,
    OS_STATE_STOPPED = 1,
    OS_STATE_RUNNABLE = 2,
    OS_STATE_RUNNING = 4,
    OS_STATE_WAITING = 8
};

/* Timer service symbols (N64 symbol renaming is not supported yet):
 * func_801C7AD4 = __osTimerInterrupt; func_801C7C10 = __osSetTimerIntr;
 * func_801C7C70 = __osInsertTimer; func_801C7D80 = __osSetCompare;
 * func_801C62B0 = osGetCount; func_801C7560 = osSendMesg.
 * D_801F4410 = __osTimerList, pointing to the sentinel at D_802AD600;
 * D_802AD5F0 = __osTimerCounter, the Count sample used for elapsed ticks.
 */
/* libultra timer in a circular, sentinel-headed list, ordered by expiration.
 * interval is the repeat period (zero for one-shot timers); value is the
 * delay relative to the preceding timer, in CP0 Count ticks.
 * Expiration sends msg to mq without blocking when mq is non-NULL. */
typedef struct OSTimer {
    /* 0x00 */ struct OSTimer *next;
    /* 0x04 */ struct OSTimer *prev;
    /* 0x08 */ u64 interval;
    /* 0x10 */ u64 value;
    /* 0x18 */ OSMesgQueue *mq;
    /* 0x1C */ void *msg;
} OSTimer; /* size = 0x20 */

/*
 * Controller/SI library symbols (kept at their existing linker names):
 * func_801CF8C0: osContInit; func_801C7080: osGetTime.
 * func_801C6520: osCreateMesgQueue; func_801C7430: osRecvMesg.
 * func_801C77C0: osSetTimer; func_801CF710: __osSiRawStartDma.
 * func_801CFB10: __osPackRequestData; func_801CFA5C: __osContGetInitData.
 * func_801CF7D0: __osSiCreateAccessQueue.
 * D_801F54C0: __osContinitialized, the one-time initialization flag.
 * D_802AE8FC: __osMaxControllers, number of controller channels to query.
 * D_802AE900: __osContPifRam, the 64-byte controller command/reply buffer.
 * D_802AE940: __osContLastCmd, the most recently packed controller command.
 * D_802AE8E0 / D_802AE8F8: __osEepromTimerQ / __osEepromTimerMsg.
 */
/* func_801CFE9C: __osEepStatus. Skips four controller channels, then
 * sends an EEPROM status request over SI and returns the DMA/channel error.
 * D_802AE950 is __osEepPifRam (64 bytes); D_802AE98C is its final word,
 * containing the PIF execute byte. Both are BSS, verified in F5680.bss.s.
 * D_802AE940 is __osContLastCmd; helpers are named in the SI list above.
 */
typedef struct PifStatusRequest {
    /* 0x00 */ u8 dummy;
    /* 0x01 */ u8 txsize;
    /* 0x02 */ u8 rxsize;
    /* 0x03 */ u8 cmd;
    /* 0x04 */ u8 typeLow;
    /* 0x05 */ u8 typeHigh;
    /* 0x06 */ u8 status;
    /* 0x07 */ u8 dummy1;
} PifStatusRequest; /* size = 0x08, including alignment/padding commands */

/* Controller/EEPROM status returned by the SI status query. */
typedef struct OSContStatus {
    /* 0x00 */ u16 type;
    /* 0x02 */ u8 status;
    /* 0x03 */ u8 errno;
} OSContStatus; /* size = 0x04 */

/* func_801CFC50: osEepromWrite, writes one eight-byte block under the SI lock.
 * func_801CFDD8: __osPackEepWriteData, builds the write request.
 * The write routine queries status twice and retains the original inclusive
 * address checks; its 16K limit exceeds the range of the u8 block address.
 */
enum EepromWriteConstants {
    EEPROM_16K_BLOCK_LIMIT = 0x100,
    EEPROM_ERR_INVALID_ADDRESS = -1,
    CONT_CMD_WRITE_EEPROM = 5,
    EEPROM_WRITE_TX_BYTES = 10, /* command, address and eight data bytes */
    EEPROM_WRITE_RX_BYTES = 1
};

/* EEPROM command/reply packet, following the four skipped controller channels. */
typedef struct PifEepromPacket {
    /* 0x00 */ u8 txsize;
    /* 0x01 */ u8 rxsize;
    /* 0x02 */ u8 command;
    /* 0x03 */ u8 blockAddress;
    /* 0x04 */ u8 data[8];
} PifEepromPacket; /* size = 0x0C */

/* Linker names: func_801D0030 = osEepromRead;
 * func_801D01C4 = __osPackEepReadData;
 * func_801CF824 / func_801CF890 = __osSiGetAccess / __osSiRelAccess.
 * D_802AE950 and D_802AE940 are the EEPROM PIF buffer and last command above. */
enum EepromReadConstants {
    EEPROM_TYPE_MASK = 0xC000,
    EEPROM_TYPE_4K = 0x8000,
    EEPROM_TYPE_16K = 0xC000,
    EEPROM_4K_BLOCK_LIMIT = 0x40,
    EEPROM_STATUS_BUSY = 0x80,
    EEPROM_BLOCK_BYTES = 8,
    CONT_CMD_READ_EEPROM = 4,
    CONT_ERR_NO_RESPONSE = 8,
    EEPROM_READ_TX_BYTES = 2, /* command and address */
    EEPROM_READ_RX_BYTES = 8  /* eight data bytes */
};

/* func_801CFBD0: osEepromProbe, returns which EEPROM the cartridge has. */
enum EepromProbeResult {
    EEPROM_PROBE_NONE = 0,
    EEPROM_PROBE_4K = 1,
    EEPROM_PROBE_16K = 2
};

enum EepromStatusConstants {
    EEPROM_PIF_LAST_WORD = 15,
    EEPROM_PIF_EXECUTE = 1,
    PIF_CMD_NOP = 0xFF,
    PIF_CMD_END = 0xFE,
    PIF_STATUS_TX_BYTES = 1,
    PIF_STATUS_RX_BYTES = 3,
    PIF_CHANNEL_ERROR_MASK = 0xC0,
    PIF_CHANNEL_ERROR_SHIFT = 4,
    CONT_STATUS_FLAGS_OFFSET = 2,
    CONT_STATUS_ERROR_OFFSET = 3
};

enum ControllerSiConstants {
    OS_READ = 0,
    OS_WRITE = 1,
    OS_MESG_NOBLOCK = 0,
    OS_MESG_BLOCK = 1,
    CONT_CMD_REQUEST_STATUS = 0,
    CONT_CMD_READ_BUTTON = 1,
    CONT_READ_BUTTON_TX_BYTES = 1,
    CONT_READ_BUTTON_RX_BYTES = 4, /* buttons (2), stick x, stick y */
    /* Half a second at the N64 Count register's 46.875 MHz frequency. */
    CONTROLLER_STARTUP_TICKS = 0x165A0BC
};

enum EepromConstants {
    EEPROM_BLOCK_SIZE = 8,
    /* 12 ms at 46.875 MHz: the time an EEPROM block write takes. */
    EEPROM_WRITE_WAIT_TICKS = 0x89544
};

typedef struct {
    /* 0x00 */ u32 w0;
    /* 0x04 */ u32 w1;
} Gfx; /* size = 0x08 */

/* Palette-cycling view of a texture header; size 0x24.
 * The inclusive palette range advances once per 64 accumulated rate units.
 * Positive rates shift toward lower indices, negative rates toward higher ones.
 * The rendering fields in the unused ranges are described by Texture80154300. */
typedef struct PaletteCycleTexture {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ u8 firstColor;
    /* 0x05 */ u8 lastColor;
    /* 0x06 */ u8 pad06[2];
    /* 0x08 */ s16 cycleRate;
    /* 0x0A */ u16 cycleAccumulator;
    /* 0x0C */ u8 pad0C[0x14];
    /* 0x20 */ u16 *palette;
} PaletteCycleTexture;

enum { PALETTE_CYCLE_STEP = 0x40, PALETTE_CYCLE_MAX_TEXTURES = 20 };

/* func_8014FCF8 (texture_find_by_id) searches banks from highest slot to lowest.
 * D_8028F7D8 / D_8028F7DC / D_8028F7E0 are the first texture, allocation,
 * and texture count views of the same five banks, each with a 0x0C stride.
 * D_80106864 is the missing-texture diagnostic format; D_8025D578 is its buffer.
 * func_801D2150 is sprintf; func_80139D70 is the empty diagnostic sink.
 * This prefix describes lookup fields of the Texture80154300 layout below. */
typedef struct TextureAssetHeader {
    /* 0x00 */ s32 nameHash;
    /* 0x04 */ u8 unk04[0x10];
    /* 0x14 */ s32 recordSize;
} TextureAssetHeader; /* size = 0x18; recordSize includes header and payload */

typedef struct Texture80154300 {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u16 width;
    /* 0x0E */ u16 height;
    /* 0x10 */ u16 unk10; /* S tile mask (log2 width) */
    /* 0x12 */ u16 unk12; /* T tile mask (log2 height) */
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ u16 format;
    /* 0x1A */ s16 size;
    /* 0x1C */ u32 image;
    /* 0x20 */ u32 palette;
} Texture80154300; /* size = 0x24 */

/* func_80154300: loadTexture. Emits RDP GBI commands to D_80202240 to load a
 * 16-bit (size 2), 8-bit CI (size 1), or 4-bit CI (size 0) texture into TMEM,
 * loading its RGBA16 TLUT for paletted formats. D_801EC7EC selects mirrored
 * (G_TX_MIRROR) vs wrapped (G_TX_WRAP) S/T clamping on both load and render tiles. */
enum TextureLoadGbiConstants {
    TEXTURE_SIZ_4B = 0,
    TEXTURE_SIZ_8B = 1,
    TEXTURE_SIZ_16B = 2,
    TEXTURE_LUT_NONE = 0,
    TEXTURE_LUT_RGBA16 = 0x8000,
    TEXTURE_TX_WRAP = 0,
    TEXTURE_TX_MIRROR = 1,
    TEXTURE_TX_RENDERTILE = 0,
    TEXTURE_TX_LOADTILE = 7,
    GFX_CMD_SET_TIMG_16B = 0xFD100000,
    GFX_CMD_TILE_SYNC = 0xE8000000,
    GFX_CMD_SET_TILE_TLUT = 0xF5000100,
    GFX_LOAD_TILE_TLUT_W1 = 0x07000000,
    GFX_CMD_LOAD_SYNC = 0xE6000000,
    GFX_CMD_LOAD_TLUT = 0xF0000000,
    GFX_LOAD_TLUT_256 = 0x073FC000,
    GFX_LOAD_TLUT_16 = 0x0703C000,
    GFX_CMD_SET_TILE_LOAD_16B = 0xF5100000,
    GFX_CMD_SET_TILE = 0xF5000000,
    GFX_CMD_LOAD_BLOCK = 0xF3000000,
    GFX_CMD_SET_TILE_SIZE = 0xF2000000
};

/* Attached textured effects: func_801A6C24 draws, then updates the list.
 * func_801A6FD0 draws a quad; func_80154300 loads its texture.
 * func_801A6FC0 hides an effect and schedules removal five cleanup passes later.
 * func_801A76CC updates an actor-owned effect's ground placement and scale.
 * func_801A0064 applies the expanding ring's collision response.
 * D_8029F170 is the list sentinel; D_80202240 is the display-list write pointer.
 * D_80290130 is the effect preserved when its owner is removed.
 * D_8010B10C is the scale-step divisor; D_8010B110 is the tested normal Y.
 * Positive scaleRate interpolates; nonpositive scaleRate limits the step.
 */
typedef struct AttachedEffectView {
    /* 0x00 */ u8 *next;
    /* 0x04 */ u8 *prev;
    /* 0x08 */ s32 texture;
    /* 0x0C */ u8 *owner;
    /* 0x10 */ f32 *ownerNormal;
    /* 0x14 */ f32 position[3];
    /* 0x20 */ f32 normal[3];
    /* 0x2C */ u8 red;
    /* 0x2D */ u8 green;
    /* 0x2E */ u8 blue;
    /* 0x2F */ u8 alpha;
    /* 0x30 */ u8 targetAlpha;
    /* 0x31 */ u8 flags;
    /* 0x32 */ u8 unk32[2];
    /* 0x34 */ f32 scaleRate;
    /* 0x38 */ f32 scale;
    /* 0x3C */ f32 targetScale;
    /* 0x40 */ s16 lifetime;
    /* 0x42 */ u16 age;
    /* 0x44 */ u8 unk44[4];
    /* 0x48 */ u8 vertices[0x40];
    /* 0x88 */ u16 textureExtent;
    /* 0x8A */ u8 alphaStep;
    /* 0x8B */ u8 removalDelay;
} AttachedEffectView; /* size = 0x8C */

/* func_801B614C: spawn_surface_wake, using the AttachedEffectView layout.
 * D_8029790C holds the ai_wake.bmp texture; D_8010BBC4 is "Footprint".
 * D_801EC7A0 is squared draw distance; D_8028F914 starts camera XYZ;
 * D_802004E0 counts frames in the current state.
 * Scale pool: D_8010BC94 = 0.5 (low-alpha threshold), D_8010BC9C = 1.5
 * and D_8010BCA4 = 2.0 (double clamp thresholds); D_8010BCAC = 1.5 and
 * D_8010BCB0 = 2.0 are float clamp values. D_8010BCB4 = 15 (lifetime),
 * D_8010BCB8 = 0.6 (initial scale).
 * func_80148EBC measures squared XYZ distance; func_80149374 adds XZ.
 * func_8013FCDC allocates tagged memory (1 clears it); func_801A6844
 * initializes an attached effect; func_801A69F8 adds it to the active list.
 */
enum SurfaceWakeConstants {
    WAKE_EMIT_INTERVAL = 3,
    WAKE_ALLOCATION_SIZE = 0x90,
    WAKE_EFFECT_FLAGS = 6,
    WAKE_TEXTURE_EXTENT = 0x400,
    WAKE_LOW_ALPHA = 50,
    WAKE_HIGH_ALPHA = 90,
    WAKE_RED = 200,
    WAKE_COLOR_MAX = 255
};

/* func_80176C70: spawn_player_impact_ring.
 * func_801B33A0 selects the contact normal with the greatest Y component;
 * func_8013FCDC allocates cleared tagged memory; func_801A6844 initializes
 * AttachedEffectView; func_801A69F8 links it into the active effect list.
 * func_801B9974 starts distance-attenuated shake.
 * D_80108520 is the allocation tag "Footprnt"; D_80108528 + 4 holds the
 * double 1.1 used to lower the ring by player radius / 1.1.
 * D_80108534 is 2^31 for the original float-to-unsigned conversion.
 * D_802902D8 is the player object, D_80290308 its radius, D_8029030C its
 * position, and D_802903B0 its collision state (+0x178: supporting platform).
 * D_802901AC selects the larger ring; its wider purpose is unknown.
 * D_80297910 is the ring texture handle. D_80290130 tracks the active ring,
 * D_80290120 saves its owner-relative position, and D_8029012C counts down
 * its collision lifetime in func_80176E9C. Preserve their existing types.
 */
/* func_801A02A0: spawn_impact_ring(position, lifetime, heightOffset, scaleRate).
 * Allocates an AttachedEffectView with zero initial scale and fading alpha.
 * D_8010AC20 is the allocation tag "Footprnt"; D_80297910 is the ring texture.
 * D_801ED3E0 supplies the upward normal (0, 1, 0).
 * Level 13 clamps ring Y to 0.5: f64 at D_8010AC28 + 4, f32 D_8010AC34.
 * D_8010AC38 is 2^31 for the unsigned alpha-step conversion.
 * func_8013FCDC allocates cleared tagged memory; func_801A6844 initializes
 * the effect; func_801A69F8 links it and enforces the active-effect limit.
 * These byte offsets retain the raw access semantics of the matched code. */
enum ImpactRingFields {
    IMPACT_RING_POSITION_Y = 0x18,
    IMPACT_RING_NORMAL = 0x20,
    IMPACT_RING_ALPHA = 0x2F,
    IMPACT_RING_TARGET_ALPHA = 0x30,
    IMPACT_RING_SCALE_RATE = 0x34,
    IMPACT_RING_SCALE = 0x38,
    IMPACT_RING_ALPHA_STEP = 0x8A
};

enum ImpactRingSpawnConstants {
    IMPACT_RING_HEIGHT_CLAMP_LEVEL = 13
};

enum PlayerImpactRingConstants {
    IMPACT_RING_BASE_LIFETIME = 10,
    IMPACT_RING_LARGE_LIFETIME_BITS = 15,
    IMPACT_RING_FLAGS = 6,
    IMPACT_RING_TEXTURE_EXTENT = 0x800,
    IMPACT_RING_INITIAL_ALPHA = 150,
    IMPACT_RING_COLOR_WHITE = 255,
    IMPACT_RING_INITIAL_SCALE_DIVISOR = 10,
    IMPACT_RING_SHAKE_DURATION = 10,
    IMPACT_RING_SHAKE_RANGE_PER_FRAME = 100,
    IMPACT_RING_SHAKE_SECOND_RANGE_PER_FRAME = 25,
    IMPACT_RING_SHAKE_CYCLES = 1,
    IMPACT_RING_SHAKE_FLAGS = 14,
    IMPACT_RING_PLAYER_POSITION_OFFSET = 0x34
};


/* func_801A0064: attached_effect_apply_ring_collision.
 * func_80149428 subtracts X/Z; func_80148D50 adds a scaled X/Z vector;
 * func_801743A8 applies player damage. D_8029030C / D_8029F9AC are player /
 * ball position; velocity begins nine floats later. D_80290334 / D_8029F9D4
 * are their Y velocities. D_802903B0 / D_8029FA50 are collision states.
 * D_802901DC is damage invulnerability; D_8028FBF6 is death/recovery time.
 * D_80290134 bit 0 excludes the player; the other bits remain unidentified.
 * D_80290300 holds player object flags.
 * Pool roles: D_8010AC00[0] / *(f64 *)&D_8010AC00[1] are the player's
 * outer / inner ring scale factors; D_8010AC0C / D_8010AC10 are horizontal /
 * vertical impulse speeds. D_8010AC14 / D_8010AC18 are the ball's outer /
 * inner scale factors; D_8010AC1C is its horizontal and vertical impulse speed.
 */
enum RingCollisionConstants {
    RING_COLLISION_MIN_ALPHA = 21,
    RING_COLLISION_CONTACT_COUNT_OFFSET = 0x188,
    RING_COLLISION_PLAYER_EXCLUSION_BIT = 1,
    RING_COLLISION_PLAYER_HIT_FLAG = 0x2000,
    RING_COLLISION_VELOCITY_FLOAT_OFFSET = 9
};

/* func_801A7360 creates ground shadows for platforms with state at +0x54.
 * func_801A7360_set initializes a black, owner-linked shadow; func_8013FCDC
 * allocates cleared tagged memory; func_8015B524 returns ground distance and
 * the collision face (whose first Vec3F is its normal) and supporting platform.
 * D_802904D4 is the platform list, D_80297908 the shadow texture handle,
 * D_8029F170 the effect-list sentinel and D_8029F200 its entry count.
 * D_8010B114 is the allocation tag, D_8010B120 the ground offset and
 * D_8010B128 the initial scale. Keep their existing declarations and accesses.
 * Use offsets here to preserve raw-pointer aliasing and the signed age read;
 * AttachedEffectView.age remains unsigned for the other consumers. */
enum PlatformShadowField {
    PLATFORM_GROUND_EFFECT_STATE = 0x54,
    ATTACHED_EFFECT_PREV_OFFSET = 4,
    ATTACHED_EFFECT_TEXTURE_OFFSET = 8,
    ATTACHED_EFFECT_FLAGS_OFFSET = 0x31,
    ATTACHED_EFFECT_AGE_OFFSET = 0x42
};

enum PlatformShadowConstants {
    ATTACHED_EFFECT_ALLOCATION_BYTES = 0x90,
    ATTACHED_EFFECT_OVERFLOW_COUNT = 41,
    PLATFORM_SHADOW_FLAGS = 5,
    PLATFORM_SHADOW_TEXTURE_EXTENT = 0x400
};

/* N64 vertex layout used by AttachedEffectView.vertices. */
typedef struct EffectQuadVertex {
    /* 0x00 */ s16 position[3];
    /* 0x06 */ u16 flag;
    /* 0x08 */ s16 texCoord[2];
    /* 0x0C */ u8 color[4];
} EffectQuadVertex; /* size = 0x10 */

/* func_801A77D8 draws a ground-shadow quad using EffectQuadVertex data.
 * D_801F0238 is the shared unit quad (XZ = +/-1, alpha = 255).
 * Other quads receive per-vertex alpha; primitive RGB is always black.
 * D_8010B150/154 are scale weights of 7, D_8010B158 is the divisor 8;
 * the double at D_8010B158 + 4 is the surface offset 1.5.
 * D_80202240 is the display-list write pointer; D_801EC86C counts matrices
 * starting at +0x80 in the graphics buffer pointed to by D_8025D0C0.
 * func_80148CC8 adds a scaled direction to a position. */
enum GroundShadowConstants {
    SHADOW_QUAD_VERTEX_COUNT = 4,
    SHADOW_VERTEX_BYTES = 0x10,
    SHADOW_VERTEX_ALPHA_OFFSET = 0x0F
};

/* func_801A6844: attached_effect_init. The owner must be set before calling;
 * an owned effect requires a normal pointer and stores position in owner space.
 * func_801499A0: vec3_rotate_quaternion (output, input, quaternion).
 * D_8010B104 supplies the initial scale rate; D_8010B108 the default normal Y.
 */
enum AttachedEffectFlags {
    ATTACHED_EFFECT_EVICTABLE = 2,
    ATTACHED_EFFECT_LOW_ALPHA = 4,
    ATTACHED_EFFECT_FADE_ON_EXPIRY = 8,
    ATTACHED_EFFECT_FADE_IN = 0x10,
    ATTACHED_EFFECT_DOUBLE_SIDED = 0x20
};

/* func_801B52BC: spawn_expanding_surface_effects.
 * D_8010BBC4 is the allocation label "Footprint"; D_80297BF0 is ai_ripple.bmp.
 * D_8010BBD0 = 2.0 divides the target scale; D_8010BBD4 = 80.0 is lifetime;
 * D_8010BBD8 = 1.0 supplies the default upward normal.
 * func_8013FCDC allocates tagged memory, func_801A6844 initializes the effect,
 * and func_801A69F8 inserts it into the active list, evicting on overflow.
 * Preserve the scratch padding and raw field accesses for matching codegen. */
typedef struct SurfaceEffectSpawnScratch {
    /* 0x00 */ f32 normal[3];
    /* 0x0C */ u8 pad0C[0x6C];
    /* 0x78 */ f32 position[3];
} SurfaceEffectSpawnScratch; /* size = 0x84 */

enum SurfaceEffectSpawnConstants {
    SURFACE_EFFECT_OWNER_OFFSET = 0x0C,
    SURFACE_EFFECT_ALPHA_OFFSET = 0x2F,
    SURFACE_EFFECT_TARGET_ALPHA_OFFSET = 0x30,
    SURFACE_EFFECT_SCALE_OFFSET = 0x38,
    SURFACE_EFFECT_ALPHA_STEP_OFFSET = 0x8A,
    SURFACE_EFFECT_RIPPLE_ALPHA = 200,
    SURFACE_EFFECT_FADE_STEP = 10
};

enum AttachedEffectInitConstants {
    ATTACHED_EFFECT_ALPHA_STEP = 5,
    ATTACHED_EFFECT_ALPHA_LOW = 80,
    ATTACHED_EFFECT_ALPHA_HIGH = 250,
    ATTACHED_EFFECT_COLOR_WHITE = 255
};

/* Packed F3DEX commands: the front/back pairs draw the four quad vertices. */
enum AttachedEffectGfxConstants {
    EFFECT_GFX_CLEAR_GEOMETRY_MODE = 0xB6000000,
    EFFECT_GFX_LIGHTING = 0x20000,
    EFFECT_GFX_SET_RENDER_MODE = 0xB900031D,
    EFFECT_GFX_PRIMITIVE_COLOR = 0xFA000000,
    EFFECT_GFX_PUSH_MODELVIEW = 0x01040040,
    EFFECT_GFX_LOAD_QUAD_VERTICES = 0x0400103F,
    EFFECT_GFX_FRONT_TRIANGLES_W0 = 0xB1040002,
    EFFECT_GFX_FRONT_TRIANGLES_W1 = 0x00060004,
    EFFECT_GFX_BACK_TRIANGLES_W0 = 0xB1000402,
    EFFECT_GFX_BACK_TRIANGLES_W1 = 0x00040006,
    EFFECT_GFX_POP_MODELVIEW = 0xBD000000,
    EFFECT_QUAD_HALF_SIZE = 10,
    EFFECT_MATRIX_BYTES = 64,
    EFFECT_MATRIX_BUFFER_OFFSET = 0x80
};

/* func_801A6FD0 draws a surface-aligned attached-effect quad.
 * func_801499A0 rotates a vector by a quaternion; func_80149C4C builds a
 * quaternion from a surface normal; func_801484F0 converts it to a matrix.
 * func_801C61A0/801C5F20/801C5580/801C5300 are guTranslateF/guScaleF/
 * guMtxCatF/guMtxF2L. Keep the existing word-bit argument casts.
 * func_8017D7B8 refreshes the owner's world-space collision triangles.
 * D_801F0232 receives the effect texture's format; D_802004E0 is the frame
 * counter compared with the owner's collision-update stamp.
 * D_801EC86C counts render matrices in D_8025D0C0's graphics buffer.
 */

/*
 * Background sprites linked at D_8028F350; func_8014CF98 updates their
 * placement. Coordinates used for drawing are in quarter-pixel units.
 * Scale 1024 is unit size; width/height * scale >> 9 gives half-extents
 * in quarter-pixels. A nonzero yawRepeatCount enables panoramic scrolling.
 */
typedef struct BackgroundSpriteView {
    /* 0x00 */ struct BackgroundSpriteView *next;
    /* 0x04 */ struct BackgroundSpriteView *prev;
    /* 0x08 */ struct BackgroundSpriteView *parent;
    /* 0x0C */ f32 offsetX;
    /* 0x10 */ f32 offsetY;
    /* 0x14 */ u8 unk14[0x34];
    /* 0x48 */ Texture80154300 *texture;
    /* 0x4C */ s32 screenLeft;
    /* 0x50 */ s32 screenTop;
    /* 0x54 */ s32 sortKey;
    /* 0x58 */ s16 scaleX;
    /* 0x5A */ s16 scaleY;
    /* 0x5C */ u8 unk5C[4];
    /* 0x60 */ s16 visible;
    /* 0x62 */ s16 yawRepeatCount;
    /* 0x64 */ s16 unk64;
    /* 0x66 */ s16 pitchOffset;
    /* 0x68 */ s32 scrollCenterX;
    /* 0x6C */ u8 red;
    /* 0x6D */ u8 green;
    /* 0x6E */ u8 blue;
    /* 0x6F */ u8 alpha;
} BackgroundSpriteView; /* size = 0x70; accessed prefix */

/* Raw accesses retain the original compiler's aliasing behavior.
 * Dimension calculations and their conversions share source lines to retain
 * KMC GCC's original instruction scheduling. */
enum BackgroundSpriteOffsets {
    BACKGROUND_LIST_COUNT_OFFSET = 0x70,
    BACKGROUND_PARENT_OFFSET = 0x08,
    BACKGROUND_OFFSET_X_OFFSET = 0x0C,
    BACKGROUND_OFFSET_Y_OFFSET = 0x10,
    BACKGROUND_TEXTURE_OFFSET = 0x48,
    BACKGROUND_SCREEN_LEFT_OFFSET = 0x4C,
    BACKGROUND_SCREEN_TOP_OFFSET = 0x50,
    BACKGROUND_SCALE_X_OFFSET = 0x58,
    BACKGROUND_SCALE_Y_OFFSET = 0x5A,
    BACKGROUND_VISIBLE_OFFSET = 0x60,
    BACKGROUND_YAW_REPEAT_OFFSET = 0x62,
    BACKGROUND_PITCH_OFFSET = 0x66,
    BACKGROUND_SCROLL_CENTER_X_OFFSET = 0x68,
    BACKGROUND_TEXTURE_WIDTH_OFFSET = 0x0C,
    BACKGROUND_TEXTURE_HEIGHT_OFFSET = 0x0E,
    BACKGROUND_HALF_EXTENT_SHIFT = 9,
    BACKGROUND_SECOND_MATRIX_OFFSET = 0x4080,
    BACKGROUND_SPRITE_DESCRIPTOR_OFFSET = 0x18,
    BACKGROUND_REPEAT_DESCRIPTOR_OFFSET = 0x30,
    BACKGROUND_FLIP_X_BYTE_OFFSET = 0x5D,
    BACKGROUND_FLIP_Y_BYTE_OFFSET = 0x5F,
    BACKGROUND_SCREEN_LEFT_LOW_OFFSET = 0x4E,
    BACKGROUND_SCREEN_TOP_LOW_OFFSET = 0x52,
    BACKGROUND_FULL_EXTENT_SHIFT = 8,
    BACKGROUND_SCREEN_WIDTH_Q2 = 320 * 4,
    BACKGROUND_RECIPROCAL_SCALE = 0x100000,
    BACKGROUND_GFX_SPRITE_BASE = 0x09000018,
    BACKGROUND_GFX_SPRITE_SCALE_FLIP = 0xBE000000,
    BACKGROUND_GFX_SPRITE_DRAW = 0xBD000000,
    BACKGROUND_KSEG0_TO_PHYSICAL = 0x80000000
};

/* func_8014B360: draw_background_sprites. D_8028F3C0 is the sprite count,
 * 0x70 bytes after the list sentinel D_8028F350. D_801ED4C0 and D_801ED538
 * are the two setup display lists called before drawing visible sprites.
 * func_8014B4A4 draws a background sprite and its optional horizontal repeat.
 * func_801C6270 is guSprite2DInit: image, palette, stride, width, height,
 * image format, texel size, image X and image Y follow its destination.
 * D_80202240 is the display-list write pointer. Sprite2D microcode interprets
 * 0xBE/0xBD as scale-and-flip / draw commands, unlike F3DEX's commands.
 * The 0x18-byte descriptors occupy background offsets 0x18 and 0x30.
 * Scale 1024 is unity; 0x100000 / scale produces the inverse in Q10.
 * Screen positions are Q2; the low-halfword offsets above assume N64 big endian.
 * Texture80154300 supplies the texture layout; this caller reads format as
 * s16 and image/palette as s32, so those accesses retain explicit casts.
 */

/*
 * D_8025D0C0 points to the current graphics buffer, whose matrices are
 * combined by func_801C5710 (guMtxCatL) and decoded by func_801C5398
 * (guMtxL2F). func_80149568 normalizes a vector; func_80147460 is atan2;
 * func_80147460(y, x) returns a table approximation in radians, with (0,0)
 * returning zero. atan_tab inlines the positive-ratio lookup: D_801DDE20
 * begins with two u16 header words, followed by angles scaled by 40000.
 * D_80284DB4 is the samples-per-unit ratio and D_80284DB6 the maximum ratio,
 * initialized from those header words by func_801473BC.
 * D_801061DC/E0/E4/F0 are separate 40000.0f divisors for the four quadrants.
 * D_801061E8/F4 hold double-precision approximations of +pi/2 and -pi/2;
 * D_801061FC/6200/6204 hold float approximations of pi, +pi/2 and -pi/2.
 * Keep these pool references and their precision when porting the lookup.
 * func_801490AC rotates about Y.
 * D_8028FA00/04/08 are camera focus; D_8028F914/918/91C are camera position;
 * D_8028F958 is camera pitch. D_801ED638 is the maximum background top Y
 * (initially zero), added to the half-height when clamping its center.
 *
 * func_8014CF98 pools: D_801064E4 = 4 (pixels to quarter-pixels);
 * D_801064E8 = 3.141592654 (yaw divisor); D_801064F0 = 500 (pitch radius);
 * D_801064F4 = 2 (pitch divisor); D_801064F8 = 136 (vertical bias);
 * D_801064FC/6500 = 1280/960 (viewport width/height in quarter-pixels).
 */


typedef struct Unk802904D4Node {
    /* 0x00 */ struct Unk802904D4Node *next;
    /* 0x04 */ u8 pad04[0x68];
    /* 0x6C */ s16 unk06C;
} Unk802904D4Node; /* size = 0x70; accessed prefix, not an allocation-size claim */

/* A lightning beam between two points (D_802AA7A0 is the circular list's
 * sentinel head). func_801B8824 updates every active beam with func_801B889C:
 * it blinks on a timer, jitters its colour, flashes the screen, and zaps
 * Glover or the ball when they touch it. D_802AA794 is the beam's phase
 * offset for its hum (0x3C per beam in list order). */
typedef struct Unk802AA7A0Node {
    /* 0x00 */ struct Unk802AA7A0Node *next;
    /* 0x04 */ u8 pad04[0x26];
    /* 0x2A */ s16 unk02A;
    /* 0x2C */ u8 rgb[3];
    /* 0x2F */ u8 colorJitter;
    /* 0x30 */ u8 active;
    /* 0x31 */ u8 lit;
} Unk802AA7A0Node; /* size = 0x32; accessed prefix, not an allocation-size claim */

enum LightningBeamConstants {
    LIGHTNING_BEAM_PHASE_STEP = 0x3C
};

typedef struct UnkList {
    /* 0x00 */ struct UnkList *unk00;
    /* 0x04 */ struct UnkList *unk04;
} UnkList; /* size = 0x08; accessed prefix, not an allocation-size claim */

/* Dynamic lights: func_8018978C updates the list; func_80189040 removes a
 * light; func_80189908 updates its direction; func_80189A58 approaches its
 * target RGB color. D_802991A8 is the circular-list sentinel, D_80299200
 * the light count, and D_80299202 the count excluded from flagged objects.
 * D_8010951C is the 1.0f RGB-length cutoff for removing faded lights.
 * D_80109520 is the 127.0f direction-vector scale used by the RSP.
 * func_80189908: dynamic_light_update_direction.
 * func_801494CC(target, current): signed shortest angle difference in radians.
 * func_801496C8: wrap_angle_once; func_8014915C: vec3_rotate_axis;
 * func_801490AC: vec3_rotate_y.
 */
enum DynamicLightConstants {
    DYNAMIC_LIGHT_SKIP_FLAGGED_OBJECTS = 2,
    /* D_80299200 (light count) as a u16 index from the sentinel D_802991A8. */
    DYNAMIC_LIGHT_COUNT_INDEX = 0x2C,
    /* D_80299202 relative to the sentinel; retain the shared-base access. */
    DYNAMIC_LIGHT_FILTERED_COUNT_INDEX = 0x2D
};

typedef struct DynamicLight {
    /* 0x00 */ UnkList links;
    /* 0x08 */ u8 index;
    /* 0x09 */ u8 type;
    /* 0x0A */ s16 fadeTimer; /* Positive: countdown; zero: fade; negative: persist. */
    /* 0x0C */ f32 direction[3];
    /* 0x18 */ f32 angularVelocity[2];
    /* 0x20 */ f32 color[3];
    /* 0x2C */ f32 targetColor[3];
    /* 0x38 */ f32 colorStep;
    /* 0x3C */ f32 angles[2]; /* Pitch about X, then yaw about Y, in radians. */
    /* 0x44 */ f32 targetAngles[2]; /* Approached by at most angleStep per update. */
    /* 0x4C */ f32 unk4C[2];
    /* 0x54 */ f32 angleStep;
} DynamicLight; /* size = 0x58 */


/* func_8018AE5C: update_wind_volumes; func_80147000: random_bounded;
 * func_80148CC8: vec3_add_scaled; func_801B66D4: spawn_particle.
 * D_80299244 is the first wind-volume pointer (sentinel at address - 0x34);
 * D_802004E0 is the state frame counter; D_8026A148 is the object-list head.
 * D_801095DC/E0 control particle speed jitter; D_801095E0+4 is the double
 * minimum physics divisor test and D_801095EC its float fallback.
 * D_801095F0/F4 scale interior/falloff force; D_801095F8 is its cutoff.
 *
 * Wind volumes share this list layout. The float words before the links are
 * minimum corner [0..2], box extent [3..5], unit direction [6..8],
 * an s32 enabled flag at 0x24, strength/emission count at 0x28, and
 * falloff distance at 0x2C. unk30 is not yet identified.
 * ObjectNode uses float velocity at 0x58 and a physics pointer at 0xD0;
 * the first float of that physics block divides the wind acceleration.
 * Keep the existing storage declarations; these indices describe their views.
 */
enum WindVolumeFields {
    WIND_MIN = 0,
    WIND_EXTENT = 3,
    WIND_DIRECTION = 6,
    WIND_STRENGTH = 10,
    WIND_FALLOFF = 11,
    WIND_ENABLED_OFFSET = 0x24,
    WIND_NEXT_OFFSET = 0x34,
    WIND_OBJECT_FLAGS_OFFSET = 0x28,
    WIND_OBJECT_POSITION_OFFSET = 0x34,
    WIND_OBJECT_VELOCITY_OFFSET = 0x58,
    WIND_OBJECT_PHYSICS_OFFSET = 0xD0,
    WIND_PARTICLE_LIFETIME_OFFSET = 0x24,
    WIND_PARTICLE_SPRITE_FLAGS_OFFSET = 0x109
};

enum WindFlags {
    WIND_VOLUME_ENABLED = 1,
    OBJECT_AFFECTED_BY_WIND = 0x800,
    OBJECT_RECEIVING_WIND = 0x1000,
    WIND_PARTICLE_TYPE = 16,
    WIND_PARTICLE_FLIP = 2
};

typedef struct Unk80299210Node {
    /* 0x00 */ u8 pad00[0x30];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ struct Unk80299210Node *next;
    /* 0x38 */ struct Unk80299210Node *prev;
} Unk80299210Node; /* size = 0x3C; accessed prefix, not an allocation-size claim */

typedef struct Camera80180B78 {
    /* 0x00 */ u8 pad00[0x30];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ s32 unk40[3];
    /* 0x4C */ u8 pad4C[0xC];
    /* 0x58 */ f32 unk58[3];
    /* 0x64 */ u8 pad64[0x74];
    /* 0xD8 */ u8 *unkD8;
} Camera80180B78; /* size = 0xDC */


/*
 * 64DD disk DMA state used by func_801D0C90 (__osLeoInterrupt).
 * D_802AFC54 is the disk PI handle; transfer state begins at handle + 0x14.
 * D_801F43E0 is the global interrupt mask.
 * func_801D06E0 (__osEPiRawStartDma) starts raw PI DMA using the handle's bus timings.
 * D_801F55E0 (__osCurrentHandle) caches the active handle for each PI domain.
 * func_801C7D90 (osVirtualToPhysical) translates the DRAM buffer address.
 * func_801D119C resets the block manager and reports completion.
 * func_801D126C posts the disk event and wakes a waiting thread.
 */
typedef struct LeoDmaBlock {
    /* 0x00 */ u32 errStatus;
    /* 0x04 */ void *dramAddr;       /* Current data-sector destination/source. */
    /* 0x08 */ void *C2Addr;         /* Buffer for the four C2 parity sectors. */
    /* 0x0C */ u32 sectorSize;       /* Bytes per sector. */
    /* 0x10 */ u32 C1ErrNum;
    /* 0x14 */ u32 C1ErrSector[4];   /* One-based sectors with C1 errors. */
} LeoDmaBlock; /* size = 0x24 */

typedef struct LeoDmaTransfer {
    /* 0x00 */ u32 cmdType;
    /* 0x04 */ u16 transferMode;
    /* 0x06 */ u16 blockNum;
    /* 0x08 */ s32 sectorNum;        /* -1 before the first data-sector request. */
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 bmCtlShadow;      /* Block-manager control register shadow. */
    /* 0x14 */ u32 seqCtlShadow;     /* Sequencer control register shadow. */
    /* 0x18 */ LeoDmaBlock block[2];
} LeoDmaTransfer; /* size = 0x60 */

/* func_801D13E0 is __osDevMgrMain: serializes PI DMA and 64DD block transfers.
 * func_801C7430 / func_801C7560 receive / send queue messages.
 * func_801D17A0 / func_801D17F0 clear / set global interrupt-mask bits.
 * func_801D1880 / func_801D1A10 read / write raw extended PI registers.
 * func_801D1830 yields the current thread.
 * Queue storage types retain the existing calling conventions.
 */
typedef struct PiDeviceHandle {
    /* 0x00 */ void *next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 relDuration;
    /* 0x08 */ u8 pulse;
    /* 0x09 */ u8 domain;
    /* 0x0C */ u32 baseAddress;
    /* 0x10 */ u32 speed;
    /* 0x14 */ LeoDmaTransfer transferInfo;
} PiDeviceHandle; /* size = 0x74 */

typedef struct PiIoMessage {
    /* 0x00 */ u16 type;
    /* 0x02 */ u8 priority;
    /* 0x03 */ u8 status;
    /* 0x04 */ u8 *returnQueue;
    /* 0x08 */ void *dramAddr;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 size;
    /* 0x14 */ PiDeviceHandle *piHandle;
} PiIoMessage; /* size = 0x18 */

/*
 * PI manager state at D_801F55C0: the separately declared words through
 * D_801F55D8 correspond to the fields below; keep their existing types.
 * D_802AE990 is its thread, D_802AEB40 its stack, D_802AFB40 the completion
 * queue, D_802AFB58 its message buffer, and D_802B0CF0 the PI access queue.
 * D_801F55F0 records whether the access queue has been initialized.
 */
typedef struct PiDeviceManager {
    /* 0x00 */ s32 active;
    /* 0x04 */ void *thread;
    /* 0x08 */ void *commandQueue;
    /* 0x0C */ void *eventQueue;
    /* 0x10 */ void *accessQueue;
    /* 0x14 */ s32 (*dma)(s32, u32, void *, u32);
    /* 0x18 */ s32 (*extendedDma)(PiDeviceHandle *, s32, u32, void *, u32);
} PiDeviceManager; /* size = 0x1C */

/* PI bus registers; writing a length starts a transfer of length + 1 bytes. */
enum PiRegisterAddress {
    PI_DRAM_ADDR_REG = 0xA4600000,
    PI_CART_ADDR_REG = 0xA4600004,
    PI_RD_LEN_REG = 0xA4600008,
    PI_WR_LEN_REG = 0xA460000C,
    PI_STATUS_REG = 0xA4600010,
    PI_BSD_DOM1_LAT_REG = 0xA4600014,
    PI_BSD_DOM1_PWD_REG = 0xA4600018,
    PI_BSD_DOM1_PGS_REG = 0xA460001C,
    PI_BSD_DOM1_RLS_REG = 0xA4600020,
    PI_BSD_DOM2_LAT_REG = 0xA4600024,
    PI_BSD_DOM2_PWD_REG = 0xA4600028,
    PI_BSD_DOM2_PGS_REG = 0xA460002C,
    PI_BSD_DOM2_RLS_REG = 0xA4600030
};

enum PiBusConstants {
    PI_DOMAIN1 = 0,
    PI_DOMAIN2 = 1,
    PI_STATUS_DMA_BUSY = 1,
    PI_STATUS_IO_BUSY = 2,
    PI_PHYSICAL_ADDRESS_MASK = 0x1FFFFFFF,
    DEVICE_TYPE_CART = 0,
    CART_ROM_UNCACHED_BASE = 0xB0000000, /* PI_DOM1_ADDR2 | K1BASE */
    DEVICE_TYPE_BULK = 1,
    DRIVE_ROM_UNCACHED_BASE = 0xA6000000, /* PI_DOM1_ADDR1 | K1BASE: 64DD IPL ROM */
    PI_HANDLE_TRANSFER_INFO_SIZE = 0x60
};

/* func_801D1A10 (__osEPiRawWriteIo) waits until DMA and programmed I/O
 * are idle, selects the handle's domain timing, and writes one device word.
 * D_801F55E0 caches the last PiDeviceHandle for each domain; only changed
 * latency, pageSize, relDuration and pulse registers are written.
 * The device address is ORed with baseAddress and the uncached segment.
 */
/* CPU uncached segment used for programmed PI reads and writes. */
enum PiCpuAddress {
    PI_UNCACHED_ADDRESS_BASE = 0xA0000000
};

enum PiRawReadDiagnostic {
    PI_RAW_READ_OUTPUT_ASSERT_LINE = 43
};

enum PiManagerMessageType {
    PI_MESSAGE_LOOPBACK = 10,
    PI_MESSAGE_DMA_READ = 11,
    PI_MESSAGE_DMA_WRITE = 12,
    PI_MESSAGE_EXTENDED_DMA_READ = 15,
    PI_MESSAGE_EXTENDED_DMA_WRITE = 16
};

enum PiManagerConstants {
    PI_OS_EVENT = 8,                  /* libultra OS_EVENT_PI */
    PI_COMPLETION_MESSAGE = 0x22222222,
    PI_EVENT_QUEUE_CAPACITY = 1,
    PI_THREAD_STACK_SIZE = 0x1000,
    PI_PRIORITY_UNCHANGED = -1,
    PI_DEVICE_64DD = 2,
    PI_DMA_READ = 0,
    PI_DMA_WRITE = 1,
    PI_MESSAGE_NONBLOCKING = 0,
    PI_MESSAGE_BLOCKING = 1,
    LEO_ASIC_STATUS_DEVICE_ADDR = 0x05000508,
    LEO_ASIC_BM_CONTROL_DEVICE_ADDR = 0x05000510,
    LEO_BM_CONTROL_START = 0x80000000,
    LEO_BM_CONTROL_RESET = 0x10000000,
    LEO_PI_CART_INTERRUPT_ENABLE_MASK = 0x100C01
};

enum LeoDmaCommand {
    LEO_DMA_READ = 0,
    LEO_DMA_WRITE = 1,
    LEO_DMA_COMPLETE = 2
};

enum LeoDmaMode {
    LEO_DMA_TRACK_MODE = 2,         /* Transfer both blocks of a track. */
    LEO_DMA_SECTOR_MODE = 3
};

enum LeoDmaStatus {
    LEO_DMA_OK = 0,
    LEO_DMA_INVALID_COMMAND = 4,
    LEO_DMA_STATUS_22 = 0x16,       /* BM error or first block awaiting C2 DMA. */
    LEO_DMA_C1_ERROR = 0x17,
    LEO_DMA_SECTOR_ERROR = 0x18,
    LEO_DMA_PI_BUSY = 0x1D
};

enum LeoDmaConstants {
    LEO_TRANSFER_OFFSET = 0x14,
    LEO_DATA_SECTORS_PER_BLOCK = 85,
    LEO_LAST_DATA_SECTOR = 0x54,
    LEO_C2_REQUEST_SECTOR_COUNT = 88,
    LEO_C2_SECTORS = 4,
    LEO_MAX_C1_ERROR_INDEX = 3,
    LEO_SECTOR_MODE_C1_WINDOW = 17,
    LEO_SECTOR_MODE_C1_LIMIT = 0x52,
    LEO_PI_STATUS_REG = 0xA4600010,
    LEO_ASIC_STATUS_REG = 0xA5000508,
    LEO_ASIC_BM_STATUS_CTL_REG = 0xA5000510,
    LEO_PI_DMA_BUSY = 1,
    LEO_PI_CLEAR_INTERRUPT = 2,
    LEO_STATUS_MECHANIC_INTERRUPT = 0x02000000,
    LEO_STATUS_BM_ERROR = 0x08000000,
    LEO_STATUS_C2_TRANSFER = 0x10000000,
    LEO_STATUS_DATA_REQUEST = 0x40000000,
    LEO_BM_CTL_RESET_MECHANIC_INTERRUPT = 0x01000000,
    LEO_BM_C1_ERROR_BIT21 = 0x00200000,
    LEO_BM_C1_ERROR_BIT22 = 0x00400000,
    LEO_BM_C1_ERROR_BIT25 = 0x02000000,
    LEO_CART_INTERRUPT_MASK = 0x800,
    LEO_PI_INTERRUPT_ENABLE_MASK = 0x100401,
    LEO_SECTOR_BUFFER_DEVICE_ADDR = 0x05000400,
    LEO_C2_BUFFER_DEVICE_ADDR = 0x05000000
};

typedef struct ObjectFlagSlot {
    /* 0x000 */ s32 flags;
    /* 0x004 */ u8 pad004[0x2FC];
} ObjectFlagSlot; /* size = 0x300 */

typedef struct ObjectFloatSlot {
    /* 0x000 */ f32 value;
    /* 0x004 */ u8 pad004[0x2FC];
} ObjectFloatSlot; /* size = 0x300 */

/* Positional sound maintained by func_801785E0/func_80178760;
 * func_80178704 stops it. Volume fades independently of distance attenuation.
 * func_80178760: sound_update_positional. D_801EF480 is the maximum audible
 * distance (initially 800), D_801EF484 enables effect mix, and D_801EF488
 * counts tracked handles. D_8028F914 starts camera XYZ; D_8028F95C is camera yaw.
 * func_80148E48 / func_80148EBC: ordinary / squared XYZ distance;
 * func_80149428 subtracts XZ, func_80147460 is table-based atan2,
 * func_801496C8 wraps an angle by at most one turn, and func_8014944C
 * returns the shortest unsigned angle difference.
 * func_801C08E4: MusStartEffect2; func_801C0CD4: MusHandleSetPan;
 * func_801C0D40: MusHandleSetFreqOffset; func_801C0DAC: MusHandleSetTempo.
 * The unaligned f64 pool values at D_801086F0 + 4, D_801086F8 + 4,
 * D_80108700 + 4 are pi/2, 255/pi and 10, respectively. The first two
 * convert the angle from the camera's side axis to stereo pan (0..255).
 * pitch controls both frequency offset and tempo, with 128 as neutral. */
enum PositionalSoundConstants {
    POSITIONAL_SOUND_NEUTRAL_PITCH = 128,
    POSITIONAL_SOUND_EFFECT_MIX = 30,
    POSITIONAL_SOUND_DEFAULT_PRIORITY = -1,
    POSITIONAL_SOUND_VOLUME_MASK = 0xFF,
    POSITIONAL_SOUND_EFFECT_FLAG_OFFSET = 9
};

/* Immediate positional playback (func_80178134): D_801086A0 is pi/2,
 * D_801086A8 is 255/pi, D_801086B0 is the 1.8 volume multiplier,
 * D_801086B8 is the volume ceiling 255, D_801086BC is 2^31 for the
 * unsigned conversion, and D_801086C0 is the pitch-offset divisor 10.
 * D_8028F9B4[9] also enables effect mix; its containing type is unknown.
 * func_801783A8: playPositionalSoundWithRadius. Subtracts the emitter radius
 * from camera distance, clamps at zero, then attenuates over D_801EF480.
 * Its pool constants are D_801086C8 (camera side-axis angle offset),
 * D_801086D0 (angle-to-pan multiplier), D_801086D8 (volume multiplier),
 * D_801086E0 (volume ceiling), and D_801086E4 (pitch-offset divisor).
 * Returns the MusStartEffect2 handle, or zero if out of range / not started. */
typedef struct PositionalSound {
    /* 0x00 */ s32 handle;
    /* 0x04 */ s32 volume;
    /* 0x08 */ s32 attenuatedVolume;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s16 pitch;
    /* 0x12 */ s16 soundId;
    /* 0x14 */ f32 *position;
    /* 0x18 */ f32 radius;
} PositionalSound; /* size = 0x1C */

/* func_8012A850 refreshes tracked sounds after the effects volume changes.
 * D_801E765A is the Q15 effects-volume multiplier; func_801C0C70 is
 * MusHandleSetVolume. D_802904D4 is the actor list, D_802AAF60 the
 * LevelEffect list, and D_8029F210 the effect list.
 * D_802999B0/9B8 alias the first sound's handle/attenuated volume in each
 * 0x300-byte actor slot; D_801F0198 is the slot count. D_8029014C/154 and
 * D_8029F58C/594 likewise alias two sound arrays' first handle/volume.
 * The kind of node in D_802AA7A0 is not yet identified.
 * Actor subobjects at +2C/+28/+3C embed sounds at +74/+28/+18.
 * These offsets preserve the byte-pointer views used by the audio traversal.
 */
enum TrackedSoundLayout {
    TRACKED_SOUNDS_PER_OWNER = 2,
    POSITIONAL_SOUND_STRIDE = 0x1C,
    UNK_AA7A0_SOUND_OFFSET = 0x58,
    ACTOR_PRIMARY_SOUND_OFFSET = 0x164,
    ACTOR_ROTATION_POINTER_OFFSET = 0x2C,
    ACTOR_MOTION_POINTER_OFFSET = 0x28,
    ACTOR_SUBOBJECT_3C_POINTER_OFFSET = 0x3C,
    ROTATION_SOUND_OFFSET = 0x74,
    MOTION_SOUND_OFFSET = 0x28,
    SUBOBJECT_3C_SOUND_OFFSET = 0x18
};

/* Sound emitters form the circular list at D_802903C0; D_8029040C counts
 * nodes and D_801EF488 counts tracked sound handles. D_801E765A is the
 * effects volume (Q15); D_802004E0 is the current state's frame counter.
 * A position pointer equal to &D_801ED3C4 marks non-positional audio.
 *
 * func_80178E98 updates emitters; func_80178760 updates positional audio.
 * func_80178134 / func_801783A8 play positional sounds without / with a radius.
 * func_801C0C70 sets handle volume; func_801C0D40 sets pitch bend;
 * func_801C0DAC sets tempo; func_801C0E3C sets effect mix; func_801C0B70 stops.
 * func_801499A0 rotates a vector by a quaternion, func_80147000 returns a
 * bounded random integer, and func_80141720 frees and clears an allocation.
 * func_80149724 returns sin((phase + offset) / scale).
 *
 * Pitch modulation constants D_80108724/28/2C are 50, 30 and 128;
 * D_80108730 holds the f64 divisor 10. Volume modulation uses
 * D_80108738/3C/40 = 60, 1, 4 and the f64 0.5 at D_80108740 + 4.
 * The f64 at D_80108748 + 4 converts volume by a factor of 1.8.
 */
typedef struct SoundEmitter {
    /* 0x00 */ struct SoundEmitter *next;
    /* 0x04 */ struct SoundEmitter *prev;
    /* 0x08 */ PositionalSound sound; /* unk0C holds non-positional base volume. */
    /* 0x24 */ f32 localPosition[3];
    /* 0x30 */ f32 worldPosition[3];
    /* 0x3C */ u8 *parent;
    /* 0x40 */ s16 repeatDelay;
    /* 0x42 */ s16 randomDelay;
    /* 0x44 */ s16 timer;
    /* 0x46 */ s16 playDuration;
    /* 0x48 */ s16 initialVolume;
    /* 0x4A */ s16 unk4A;
} SoundEmitter; /* size = 0x4C */

/* func_80178B6C creates a positional emitter, optionally attached to the
 * platform returned by func_8017DBA0 (platform_find_by_tag).
 * D_8010870C is the heap allocation label "AmbSnd"; the f64 at
 * D_80108718 + 4 scales its stored volume by 1.8. The final halfword
 * parameter is stored at unk4A; its meaning is not yet established.
 * Word/halfword indices below address the embedded PositionalSound without
 * changing the integer accesses used by its inlined start routine. */
enum SoundEmitterSoundIndex {
    EMITTER_SOUND_HANDLE_WORD = 0,
    EMITTER_SOUND_VOLUME_WORD = 1,
    EMITTER_SOUND_POSITION_WORD = 5,
    EMITTER_SOUND_PITCH_HALFWORD = 8,
    EMITTER_SOUND_ID_HALFWORD = 9
};

enum SoundEmitterConstants {
    SOUND_EMITTER_SIZE = 0x4C,
    SOUND_VOLUME_Q15_ONE = 32768,
    SOUND_VOLUME_LIMIT = 256,
    SOUND_VOLUME_MAX = 255,
    SOUND_ID_SLOW_FADE = 0x1C,
    SOUND_ID_MODULATED = 0xDF,
    SOUND_FADE_STEP = 20,
    SOUND_SLOW_FADE_STEP = 2,
    SOUND_SLOW_FADE_FX_MIX = 40,
    SOUND_CUE_SLOW_FADE_FX_MIX = 60, /* reverb of a SOUND_ID_SLOW_FADE started by a sound cue table */
    SOUND_PITCH_NORMAL = 0x80,
    SOUND_PARENT_QUATERNION = 0x11C
};

/* Timed emitter loaded by level token 0xA2; token 0xA3 adds off/on durations.
 * The phase index advances on entering the on phase, before the next off phase. */
typedef struct LevelEffect {
    /* 0x00 */ struct LevelEffect *next;
    /* 0x04 */ struct LevelEffect *prev;
    /* 0x08 */ s16 kind;
    /* 0x0A */ s16 id;
    /* 0x0C */ u8 effectType;
    /* 0x0D */ u8 enabled;
    /* 0x0E */ u8 emitting;
    /* 0x0F */ u8 unk00F; /* Number of timing phases. */
    /* 0x10 */ s16 unk010[6]; /* Off durations. */
    /* 0x1C */ s16 unk01C[6]; /* On durations; -1 means continuous. */
    /* 0x28 */ s16 timer;
    /* 0x2A */ s16 phase;
    /* 0x2C */ f32 velocity[3]; /* Relative to parent when present. */
    /* 0x38 */ f32 position[3]; /* Relative to parent when present. */
    /* 0x44 */ u8 *parent;
    /* 0x48 */ PositionalSound sound;
    /* 0x64 */ f32 soundPosition[3];
} LevelEffect; /* size = 0x70 */

/* func_801B922C updates a LevelEffect.
 * func_801AA5BC allocates an effect; func_801A96A8 initializes its appearance;
 * func_801A8E54 links it into the active effect list.
 * func_801B66D4 spawns a pooled particle; func_80178134 plays positional audio.
 * func_801499A0 rotates a vector by a quaternion; func_80147000 returns random % n.
 * D_802004E0 is the current state frame counter; D_801E7531 is the level ID.
 * D_801ED3C4 is the zero vector (three consecutive zero words).
 * Emitter pool floats: D_8010BE80 = upward velocity bias (1);
 * D_8010BE84 = velocity jitter divisor (20); D_8010BE88 = burst divisor (2);
 * D_8010BE8C = burst jitter center (3); D_8010BE90 = particle coefficient (0.6).
 * The N64 tool currently cannot rename these symbols.
 */
enum LevelEffectConstants {
    LEVEL_EFFECT_POOLED_PARTICLE = 8,
    LEVEL_EFFECT_SPRITE_COUNT = 2,
    LEVEL_EFFECT_BURST_COUNT = 5,
    LEVEL_EFFECT_SOUND_VOLUME = 70,
    LEVEL_EFFECT_SOUND_FADE_STEP = 5,
    LEVEL_EFFECT_PARTICLE_LIFETIME = 5
};

/* Model asset relocation. Symbol renaming is unavailable for N64 projects:
 * func_8015092C: relocate a model tree.
 * func_80150110: add the asset base to the low 24 bits of an encoded pointer.
 * func_80150168: relocate display-list vertices and resolve texture references.
 * func_8014FCF8: find a texture asset by ID; third argument reports missing IDs.
 * func_8013FCDC: allocate named heap storage; second argument 1 clears it.
 * func_801D2150 / func_801D211C: sprintf / memcpy.
 * D_801ED670: allocation-name serial, initially zero.
 * D_801068B4: "OFTC%d", the saved texture-coordinate allocation name.
 */
enum ModelAssetConstants {
    MODEL_TRIANGLE_TEXCOORD_BYTES = 12,
    MODEL_TRIANGLE_VERTICES = 3,
    MODEL_TEXCOORD_COMPONENTS = 2,
    MODEL_POSITION_BYTES = 12
};

/* func_80144F0C (model_distort_texcoords) updates each triangle corner's UV.
 * func_80149724 returns sinf((frame + phase) / timeScale); func_801C6000 is sinf.
 * D_801EC8F0 selects cumulative UV drift (zero) or offsets from saved UVs.
 * D_801EC8E8 / D_801EC8EC are U/V spatial phase divisors (1.0 / 0.5).
 * D_802004E0 is the current state's frame counter.
 * Pool constants: D_801060B4 = drift time scale (20), D_801060B8 = drift
 * amplitude (8), D_801060BC = saved-UV wave amplitude (300), D_801060C0 =
 * unsigned-conversion split (2^31), D_801060C4 / D_801060D0 = U/V time
 * scales (20 / 25), D_801060C8 = V phase offset (double).
 */

/* func_801B4BBC: update_scene_texcoords.
 * func_80144F0C distorts model UVs; func_80144AF8 scrolls object UVs by
 * world-space Z/X displacement, scaled to each triangle's UV spans.
 * D_8026A148 is the object sentinel; D_80269F40 / D_801EC860 are the
 * separately tracked model objects / count; D_802904D4 is the platform
 * sentinel; D_802004E0 is the state frame counter.
 * Model root +0 holds the last UV-scroll frame. Shared roots scroll once
 * per frame after the first twelve frames. Surface type 12 eases object
 * opacity toward 80 using the f64 divisor at D_8010BBA8 + 4.
 * Preserve raw accesses: ObjectNode overlays several runtime layouts.
 * N64 symbol renaming is unavailable; these are the intended names. */
enum SceneTexcoordField {
    TEXCOORD_OBJECT_COLLISION_FACES = 0xE0,
    TEXCOORD_MODEL_ROOT = 0x0C,
    TEXCOORD_MODEL_FLAGS = 0x32,
    TEXCOORD_PLATFORM_RENDER_OBJECT = 0x80
};

enum SceneTexcoordConstants {
    MODEL_DISTORT_TEXCOORDS = 0x20,
    PLATFORM_SCROLL_TEXCOORDS = 0x200,
    TEXCOORD_FADED_SURFACE_TYPE = 12,
    TEXCOORD_FADED_OPACITY = 80,
    TEXCOORD_INITIAL_FRAMES = 12
};

/* A 0x18-byte model texture reference; lookup replaces the first word with a pointer. */
typedef struct ModelTextureRef {
    /* 0x00 */ s32 idOrTexture;
    /* 0x04 */ u8 pad004[0x10];
    /* 0x14 */ s32 size;
} ModelTextureRef;

/* Geometry pointers are encoded offsets until the model is relocated. */
typedef struct ModelMeshData {
    /* 0x00 */ s16 triangleCount;
    /* 0x02 */ u8 pad002[2];
    /* 0x04 */ void *positions;
    /* 0x08 */ void *triangles;
    /* 0x0C */ void *colors;
    /* 0x10 */ void *texCoords;
    /* 0x14 */ void *savedTexCoords;
    /* 0x18 */ void *unk18;
    /* 0x1C */ void *unk1C;
    /* 0x20 */ s32 *textures; /* Per-triangle IDs, replaced with asset pointers. */
} ModelMeshData; /* size = 0x24 */

/* Prefix used by the loader; the full model node has additional runtime fields. */
typedef struct ModelNodeRelocView {
    /* 0x00 */ u8 pad000[0x14];
    /* 0x14 */ ModelMeshData *mesh;
    /* 0x18 */ void *displayList;
    /* 0x1C */ void *unk1C;
    /* 0x20 */ void *unk20;
    /* 0x24 */ void *unk24;
    /* 0x28 */ s32 textureRefCount;
    /* 0x2C */ ModelTextureRef *textureRefs;
    /* 0x30 */ u8 pad030[4];
    /* 0x34 */ void *child;
    /* 0x38 */ void *sibling;
} ModelNodeRelocView; /* prefix size = 0x3C */

/*
 * func_801425D0: relocate_model_tree; returns this record's byte size, or zero
 * if its node was already relocated. Each serialized record starts with a
 * size word, followed by a ModelNodeRelocView-compatible node.
 * D_80269F68: current serialized record address, advanced before recursion.
 * D_8026A140: most recently visited node address (record address + 4).
 * Node +0x0C is the relocated flag; +0x32 receives the supplied model flags.
 * Mesh positions/triangles and node +0x14/+0x1C/+0x20/+0x24 are offsets
 * relative to the record start. Nonzero child/sibling words signal records
 * that follow in the stream; recursion replaces them with node pointers.
 * Keep the existing raw accesses and declarations to preserve aliasing.
 */
enum ModelRelocationField {
    MODEL_RECORD_NODE_OFFSET = 4,
    MODEL_RECORD_RELOCATED_OFFSET = 0x10,
    MODEL_RECORD_FLAGS_OFFSET = 0x36,
    MODEL_NODE_RELOCATED_OFFSET = 0x0C,
    MODEL_NODE_CHILD_OFFSET = 0x34,
    MODEL_NODE_SIBLING_OFFSET = 0x38,
    MODEL_NODE_MESH_WORD = 0x14 / 4,
    MODEL_NODE_UNK1C_WORD = 0x1C / 4,
    MODEL_NODE_UNK20_WORD = 0x20 / 4,
    MODEL_NODE_UNK24_WORD = 0x24 / 4,
    MODEL_MESH_POSITIONS_WORD = 0x04 / 4,
    MODEL_MESH_TRIANGLES_WORD = 0x08 / 4
};

typedef struct LevelModelInfo {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 pad004[8];
} LevelModelInfo; /* size = 0x0C */

/* 0x50-byte parameter block copied as a unit. */
typedef struct Blk50 {
    /* 0x00 */ s32 v[20];
} Blk50;

/*
 * Scene renderer symbol roles (N64 symbol renaming is not supported yet):
 * func_801431AC: draw scene objects; func_801437E4: draw one object.
 * func_801804A0 / func_80180534: begin / end a profiling interval.
 * func_80148EBC: squared distance between two 3D positions.
 * func_8015C7C4: insert an object in the distance-sorted render list.
 * func_80189224: load object lights.
 * func_8013CEEC / func_8013A874: apply texture / object render state.
 * func_8013A284 / func_8013A1F4: load camera / identity modelview matrices.
 * func_8013A6B0: load overlay camera matrices.
 * func_801A8794: restore world render state and matrices.
 * func_801A7AC4: set translucent render state and primitive alpha.
 * func_8013D624: finish the current graphics task.
 *
 * D_80202240: next display-list command.
 * D_8026A054: sorted object count; D_80269F80 / D_80269F84: first / last.
 * ObjectNode.unk010 / unk014: next / previous in that sorted list.
 * ObjectNode.unk018: squared distance used by the render sorter (f32 bits).
 * D_801ED400 / D_801ED401 / D_801ED402: fog red / green / blue.
 * D_801ED403: fog enabled; D_801ED404 / D_801ED406: fog near / far.
 * D_801EC86C: render matrix count; D_801EC7F4: render buffer index.
 * D_801EFD50: light blocks used this frame (func_80189224, at most 100).
 * D_80105C18: label of the SCENE_RENDER_PROFILE profiler region.
 * func_8013D9BC: draw the scene for one frame.
 */

/* Views of the fixed 0x120-byte render slots, retaining each symbol's origin. */
typedef struct RenderObjectSlot {
    /* 0x000 */ u8 bytes[0x120];
} RenderObjectSlot; /* size = 0x120 */

typedef struct RenderObjectActiveSlot {
    /* 0x000 */ u8 active; /* object offset 0xE4 */
    /* 0x001 */ u8 pad001[0x11F];
} RenderObjectActiveSlot; /* stride = 0x120 */

typedef struct RenderObjectMeshSlot {
    /* 0x000 */ s32 meshRef; /* object offset 0xC8 */
    /* 0x004 */ u8 pad004[0x11C];
} RenderObjectMeshSlot; /* stride = 0x120 */

/* Byte field view used when reading packed render-state globals. */
typedef struct RenderStateByte {
    /* 0x00 */ u8 value;
} RenderStateByte; /* size = 0x01 */

enum ModelRenderFlags {
    MODEL_RENDER_TRANSLUCENT = 0x02,
    MODEL_RENDER_SKIP_LIGHTS = 0x08,
    MODEL_RENDER_LATE_PASS = 0x80
};

enum SceneRenderConstants {
    SCENE_RENDER_PROFILE = 3,
    RENDER_OBJECT_SLOT_COUNT = 120,
    RENDER_WORK_BUFFER_SIZE = 0x3200,
    FOG_SCALE_NUMERATOR = 128000,
    FOG_OFFSET_BIAS = 500
};

/* RSP clip-ratio move-word commands select the negative/positive X/Y planes.
 * Negative-plane payloads are the ratio (1..6); positive-plane payloads
 * encode its negation in the low 16 bits. */
enum GfxClipRatioCommands {
    GFX_CMD_CLIP_RATIO_NEG_X = 0xBC000404,
    GFX_CMD_CLIP_RATIO_NEG_Y = 0xBC000C04,
    GFX_CMD_CLIP_RATIO_POS_X = 0xBC001404,
    GFX_CMD_CLIP_RATIO_POS_Y = 0xBC001C04
};

enum GfxClipRatioPositiveValues {
    GFX_CLIP_RATIO_POS_1 = 0xFFFF,
    GFX_CLIP_RATIO_POS_2 = 0xFFFE,
    GFX_CLIP_RATIO_POS_3 = 0xFFFD,
    GFX_CLIP_RATIO_POS_4 = 0xFFFC,
    GFX_CLIP_RATIO_POS_5 = 0xFFFB,
    GFX_CLIP_RATIO_POS_6 = 0xFFFA
};

/* func_8013CEEC (setupSceneTextureShading) appends initial scene state.
 * func_8013CBBC resets RDP state; func_8013CA1C sets the 320x240 viewport
 * and RSP geometry modes. D_80202240 is the next display-list command.
 * D_801EC7E8 selects no texture / single level / mipmapped (initially 1).
 * D_801EC7E9 selects primitive / smooth shade / lit smooth shade (initially 2);
 * the lit mode also uses the camera's highlight setup.
 *
 * These are packed F3DEX command words, retained as separate w0/w1 stores.
 * The LOD combiners interpolate TEXEL0 and TEXEL1 with LOD_FRACTION in
 * cycle 0; cycle 1 passes that color or multiplies it by SHADE.
 * Textured modes use SHADE alpha. Untextured modes use PRIMITIVE or SHADE
 * for both color and alpha.
 */
enum SceneTextureMode {
    SCENE_TEXTURE_NONE = 0,
    SCENE_TEXTURE_SINGLE_LEVEL = 1,
    SCENE_TEXTURE_MIPMAPPED = 2
};

enum SceneShadeMode {
    SCENE_SHADE_PRIMITIVE = 0,
    SCENE_SHADE_SMOOTH = 1,
    SCENE_SHADE_LIT_SMOOTH = 2
};

/* func_8013CA1C and func_8013DA1C: identical setupViewportGeometry routines.
 * D_80202240 is the display-list write cursor; D_801EC7E9 is SceneShadeMode.
 * The eight s16 globals D_80202270..D_8020227E form an RSP viewport:
 * +0/+2/+4/+6 are X/Y/Z scale and padding; +8/+A/+C/+E are translation
 * and padding. X/Y use quarter-pixel units; Z maps to the range 0..1022.
 * Keep their existing scalar declarations for matching code generation.
 */
enum ViewportGeometryConstants {
    VIEWPORT_HALF_WIDTH_QUARTER_PIXELS = 320 * 2,
    VIEWPORT_HALF_HEIGHT_QUARTER_PIXELS = 240 * 2,
    VIEWPORT_HALF_DEPTH = 511,
    GFX_CMD_LOAD_VIEWPORT = 0x03800010,
    GFX_CMD_CLEAR_GEOMETRY_MODE = 0xB6000000,
    GFX_CMD_SET_GEOMETRY_MODE = 0xB7000000,
    GFX_GEOMETRY_SHADE = 0x00000004,
    GFX_GEOMETRY_SHADING_SMOOTH = 0x00000200,
    GFX_GEOMETRY_CULL_BACK = 0x00002000,
    GFX_GEOMETRY_LIGHTING = 0x00020000,
    /* Clear depth, shading, both cull modes, fog, lighting, texgen and LOD. */
    GFX_GEOMETRY_RESET_MASK = 0x001F3205
};

enum SceneTextureCommands {
    GFX_CMD_SET_TEXTURE_FILTER = 0xBA000C02,
    GFX_TEXTURE_FILTER_BILERP = 0x2000,
    GFX_CMD_TEXTURE_ON_LEVEL5 = 0xBB002801,
    GFX_CMD_TEXTURE_ON_LEVEL0 = 0xBB000001,
    GFX_CMD_TEXTURE_OFF = 0xBB000000,
    GFX_TEXTURE_SCALE_FULL = -1,
    GFX_CMD_SET_TEXTURE_DETAIL = 0xBA001102,
    GFX_TEXTURE_DETAIL_CLAMP = 0,
    GFX_CMD_SET_TEXTURE_LOD = 0xBA001001,
    GFX_TEXTURE_LOD_ENABLE = 0x10000,
    GFX_COMBINE_LOD_TEXTURE_W0 = 0xFC26A1FF,
    GFX_COMBINE_LOD_TEXTURE_W1 = 0x1FFC923C,
    GFX_COMBINE_LOD_TEXTURE_SHADE_W0 = 0xFC26A004,
    GFX_COMBINE_LOD_TEXTURE_SHADE_W1 = 0x1FFC93FC,
    GFX_COMBINE_DIRECT_COLOR_W0 = 0xFCFFFFFF,
    GFX_COMBINE_TEXTURE_SHADE_ALPHA_W1 = 0xFFFCF87C,
    GFX_COMBINE_MODULATE_SHADE_W0 = 0xFC127E24,
    GFX_COMBINE_MODULATE_SHADE_W1 = -0x604,
    GFX_COMBINE_PRIMITIVE_W1 = 0xFFFDF6FB,
    GFX_COMBINE_SHADE_W1 = 0xFFFE793C
};

/* resetRdpState (func_8013CBBC) appends baseline RDP state to D_80202240.
 * D_80000430 supplies the depth-image address. Scissor coordinates are 10.2
 * fixed point; 0x005003C0 encodes (320, 240) with non-interlaced mode.
 * Pipeline mode occupies bit 23; texture perspective occupies bit 19. */
enum RdpResetCommands {
    GFX_CMD_SET_PIPELINE_MODE = 0xBA001701,
    GFX_PIPELINE_NPRIMITIVE = 0,
    GFX_PIPELINE_1PRIMITIVE = 0x800000,
    GFX_CMD_SCISSOR_ORIGIN = 0xED000000,
    GFX_SCISSOR_320X240 = 0x005003C0,
    GFX_TEXTURE_LOD_TILE = 0,
    GFX_CMD_SET_TEXTURE_LUT = 0xBA000E02,
    GFX_TEXTURE_LUT_NONE = 0,
    GFX_CMD_SET_TEXTURE_PERSP = 0xBA001301,
    GFX_TEXTURE_PERSP_ENABLE = 0x80000,
    GFX_CMD_SET_TEXTURE_CONVERT = 0xBA000903,
    GFX_TEXTURE_CONVERT_FILTER = 0xC00,
    GFX_CMD_SET_COMBINE_KEY = 0xBA000801,
    GFX_COMBINE_KEY_NONE = 0,
    GFX_CMD_SET_ALPHA_COMPARE = 0xB9000002,
    GFX_ALPHA_COMPARE_NONE = 0,
    GFX_CMD_BLEND_COLOR = 0xF9000000,
    GFX_RGBA_WHITE_ZERO_ALPHA = -0x100,
    GFX_CMD_SET_COLOR_DITHER = 0xBA000602,
    GFX_COLOR_DITHER_MAGIC_SQUARE = 0,
    GFX_CMD_DEPTH_IMAGE = 0xFE000000,
    GFX_CMD_PRIMITIVE_COLOR = 0xFA000000,
    GFX_RGBA_BLACK_OPAQUE = 0xFF,
    GFX_CMD_SET_DEPTH_SOURCE = 0xB9000201,
    GFX_DEPTH_SOURCE_PIXEL = 0
};

/* func_8013A874: applyObjectRenderState. Emits combiner, primitive alpha and
 * render mode for the next object from packed render-state bytes:
 * D_801ED403 fog enabled; D_801EC7E3 object fades (alpha from D_801EC878,
 * written as primitive color alpha); D_801EC7E2 texture has its own alpha;
 * D_801EC7E5 is ObjectBlendMode; D_801EC7E6 enables depth buffering;
 * D_801EC7E8 is SceneTextureMode (mipmapping needs a pass-through first cycle).
 * Render-mode words are a first-cycle (_1) and a second-cycle (_2) blender
 * half OR'd together, as libultra's G_RM_* pairs. The NO_READ variants are
 * the AA opaque modes without IM_RD. */
enum ObjectBlendMode {
    OBJECT_BLEND_AA_XLU = 0,
    OBJECT_BLEND_OPAQUE = 1,
    OBJECT_BLEND_XLU = 2
};

enum ObjectRenderStateConstants {
    GFX_GEOMETRY_ZBUFFER = 0x00000001,
    GFX_GEOMETRY_FOG = 0x00010000,
    GFX_ALPHA_MASK = 0xFF,
    /* TEXEL0 color, TEXEL0 * PRIMITIVE alpha; second cycle passes it on. */
    GFX_COMBINE_FOG_TEXEL_PRIM_ALPHA_W0 = 0xFCFF97FF,
    GFX_COMBINE_FOG_TEXEL_PRIM_ALPHA_W1 = 0xFFFCFE38,
    /* TEXEL0 * SHADE color; second cycle passes it on. */
    GFX_COMBINE_FOG_MODULATE_W0 = 0xFC127FFF,
    GFX_COMBINE_FOG_MODULATE_PRIM_ALPHA_W1 = 0xFFFFF638,
    GFX_COMBINE_FOG_MODULATE_TEXEL_ALPHA_W1 = 0xFFFFF238,
    /* With GFX_COMBINE_MODULATE_SHADE_W0: TEXEL0 * SHADE alpha / PRIMITIVE alpha. */
    GFX_COMBINE_MODULATE_SHADE_ALPHA_W1 = 0xFF33F9FF,
    GFX_COMBINE_MODULATE_PRIM_ALPHA_W1 = 0xFFFFF7FB,
    GFX_RM_PASS_1 = 0x0C080000,
    GFX_RM_FOG_SHADE_A_1 = 0xC8000000,
    GFX_RM_AA_ZB_XLU_SURF_1 = 0x004049D8,
    GFX_RM_AA_ZB_XLU_SURF_2 = 0x001049D8,
    GFX_RM_ZB_XLU_SURF_1 = 0x00404A50,
    GFX_RM_ZB_XLU_SURF_2 = 0x00104A50,
    GFX_RM_AA_XLU_SURF_1 = 0x004041C8,
    GFX_RM_AA_XLU_SURF_2 = 0x001041C8,
    GFX_RM_XLU_SURF_1 = 0x00404240,
    GFX_RM_XLU_SURF_2 = 0x00104240,
    GFX_RM_AA_ZB_OPA_NO_READ_1 = 0x00442038,
    GFX_RM_AA_ZB_OPA_NO_READ_2 = 0x00112038,
    GFX_RM_AA_OPA_NO_READ_1 = 0x00442008,
    GFX_RM_AA_OPA_NO_READ_2 = 0x00112008,
    GFX_RM_AA_ZB_OPA_SURF_1 = 0x00442078,
    GFX_RM_AA_ZB_OPA_SURF_2 = 0x00112078,
    GFX_RM_ZB_OPA_SURF_1 = 0x00442230,
    GFX_RM_ZB_OPA_SURF_2 = 0x00112230,
    GFX_RM_AA_OPA_SURF_1 = 0x00442048,
    GFX_RM_AA_OPA_SURF_2 = 0x00112048,
    GFX_RM_AA_ZB_TEX_EDGE_1 = 0x00443078,
    GFX_RM_AA_ZB_TEX_EDGE_2 = 0x00113078,
    GFX_RM_AA_TEX_EDGE_1 = 0x00443048,
    GFX_RM_AA_TEX_EDGE_2 = 0x00113048,
    GFX_RM_TEX_EDGE_1 = 0x0C087008,
    GFX_RM_TEX_EDGE_2 = 0x03027008,
    GFX_RM_OPA_SURF_1 = 0x0C084000,
    GFX_RM_OPA_SURF_2 = 0x03024000
};

enum SceneGfxCommands {
    GFX_CMD_FOG_COLOR = 0xF8000000,
    GFX_CMD_FOG_POSITION = 0xBC000008,
    GFX_CMD_PIPE_SYNC = 0xE7000000,
    GFX_CMD_SET_CYCLE_TYPE = 0xBA001402
};

/* func_801CD3C0: spInit (sprite_init_render_state).
 * Reset the software sprite clip rectangle and append eleven Gfx commands.
 * D_802AD620 / D_802AD624: exclusive clip right / bottom (BSS s32s).
 * D_802AD628 / D_802AD62C: inclusive clip left / top (BSS s32s).
 * D_801F46E4: cached sprite flags, compared with SpriteText.flags by spDraw.
 * State uses one cycle, affine textures, bilinear filtering, tile LOD, no
 * texture lookup table, and the default sprite render mode. Texture S/T
 * scales are packed unsigned 0.16 values (0x8000 each).
 */
enum SpriteInitConstants {
    SPRITE_DEFAULT_CLIP_RIGHT = 320,
    SPRITE_DEFAULT_CLIP_BOTTOM = 240,
    GFX_TEXTURE_PERSP_NONE = 0,
    GFX_TEXTURE_SCALE_HALF_ST = 0x80008000,
    GFX_CMD_SET_RENDER_MODE = 0xB900031D,
    SPRITE_DEFAULT_RENDER_MODE = 0x0F0A7008,
    /* G_RM_OPA_SURF | G_RM_OPA_SURF2, restored by spFinish. */
    SPRITE_FINISH_RENDER_MODE = 0x0F0A4000
};

/* SpriteText.flags bits cached in D_801F46E4 (libultra SP_*). */
enum SpriteFlags {
    SPRITE_FLAG_TRANSPARENT = 0x1,
    SPRITE_FLAG_CUTOUT = 0x2,
    SPRITE_FLAG_FASTCOPY = 0x20,
    SPRITE_FLAG_TEXSHUF = 0x200
};

/* libultra G_IM_FMT_* / G_IM_SIZ_* and GBI opcodes used by drawbitmap (func_801CC118). */
enum SpriteBitmapConstants {
    SPRITE_IM_FMT_YUV = 1,
    SPRITE_IM_FMT_I = 4,
    SPRITE_IM_SIZ_4b = 0,
    SPRITE_IM_SIZ_8b = 1,
    SPRITE_IM_SIZ_16b = 2,
    SPRITE_IM_SIZ_32b = 3,
    SPRITE_TX_RENDERTILE = 0,
    SPRITE_TX_LOADTILE = 7,
    SPRITE_TX_CLAMP = 2,
    SPRITE_G_LOADBLOCK = 0xF3,
    SPRITE_G_TEXRECT = 0xE4,
    SPRITE_G_RDPHALF_1 = 0xB4000000,
    SPRITE_G_RDPHALF_2 = 0xB3000000
};

/* func_8013A284 (camera_emit_projection) builds fixed-point camera matrices
 * in the graphics buffer at D_8025D0C0, then appends three Gfx commands to
 * D_80202240: load projection, multiply view, and set perspective normalization.
 * D_801EC7DE/DC/DA are vertical FOV in degrees / near / far (initially 45/6/2000).
 * D_80202248 and D_802586F8 are eye and target Vec3F arrays, selected by
 * D_801EC7F4. D_801EC7BC is the base up vector; func_801490AC rotates it
 * about Y by D_8028F95C into D_80202260 before constructing the view.
 * D_801EC7E9 selects rendering mode; mode 2 also builds LookAt and Hilite
 * data for a 32x32 highlight texture. D_80105BE4 is matrix scale 1;
 * D_80105BE8/BEC are the two light-direction Z components, both 127.
 * func_801C59C0 is guPerspective, func_801C4510 is guLookAt, and
 * func_801C5224 is guLookAtHilite. Keep the aspect argument's float bits:
 * this caller's prototype passes it as s32. Matrix addresses are KSEG0
 * addresses converted for the RSP by adding 0x80000000.
 * Symbol names are retained because rename_symbol does not yet support N64.
 */
/* func_8013A6B0: loadOverlayCameraMatrices. Builds the overlay projection
 * with guPerspective (func_801C59C0) and view with guLookAt (func_801C4510).
 * D_80105BF0 is projection scale; D_80105BF4 is view target Z;
 * D_80105BF8 is the up vector's Y component. D_801EC7E6 enables depth
 * buffering in object render state and is cleared for overlays.
 * The overlay view occupies a separate matrix slot from the world camera.
 */
enum OverlayCameraConstants {
    OVERLAY_VIEW_MATRIX_OFFSET = 0x40C0,
    OVERLAY_VIEW_PHYSICAL_OFFSET = 0x800040C0
};

enum CameraProjectionConstants {
    CAMERA_RENDER_HILITE = 2,
    CAMERA_ASPECT_4_3_BITS = 0x3FAAAAAB,
    CAMERA_VIEW_MATRIX_OFFSET = 0x4080,
    CAMERA_LOOKAT_OFFSET = 0x2B200,
    CAMERA_HILITE_OFFSET = 0x2B220,
    CAMERA_HILITE_TEXTURE_SIZE = 32,
    CAMERA_PROJECTION_PHYSICAL_OFFSET = 0x80000000,
    CAMERA_VIEW_PHYSICAL_OFFSET = 0x80004080,
    GFX_CMD_LOAD_PROJECTION = 0x01030040,
    GFX_CMD_MULTIPLY_PROJECTION = 0x01010040,
    GFX_CMD_PERSP_NORMALIZE = 0xBC00000E
};

/* func_8013A1F4: loadIdentityModelMatrix. func_801C61F4 is guTranslate. */
enum ModelMatrixConstants {
    MODEL_IDENTITY_MATRIX_OFFSET = 0x40,
    MODEL_IDENTITY_PHYSICAL_OFFSET = 0x80000040,
    GFX_CMD_LOAD_MODELVIEW = 0x01020040 /* F3D G_MTX, modelview | load, 0x40 bytes */
};

/*
 * Object rotation controller, reached through the object's pointer at +0x2C.
 * delay counts down to a stop transition; -1 through -9 defer rotation,
 * while values <= -10 encode a path waypoint to wait for (-delay / 10).
 */
typedef struct ObjectRotation {
    /* 0x00 */ f32 angularStep;
    /* 0x04 */ s8 axisEnabled[3];
    /* 0x07 */ u8 pad007[3];
    /* 0x0A */ u16 pauseFrames;
    /* 0x0C */ u8 stopCount;
    /* 0x0D */ u8 nextStop;
    /* 0x0E */ s16 delay;
    /* 0x10 */ u8 pad010[4];
    /* 0x14 */ f32 oscillationLimit;
    /* 0x18 */ u8 pad018[4];
    /* 0x1C */ f32 restoreStep;
    /* 0x20 */ u8 pad020[8];
    /* 0x28 */ f32 restoreAngleLimit;
    /* 0x2C */ u8 pad02C[4];
    /* 0x30 */ f32 baseAngle;
    /* 0x34 */ u8 pad034[4];
    /* 0x38 */ f32 angles[3];
    /* 0x44 */ u8 pad044[0xC];
    /* 0x50 */ f32 angularVelocity[3];
    /* 0x5C */ u8 pad05C[0x10];
    /* 0x6C */ f32 spinDamping;
    /* 0x70 */ u8 pad070[4];
    /* 0x74 */ s32 soundHandle;
    /* 0x78 */ u8 pad078[0xE];
    /* 0x86 */ s16 unk086;
    /* 0x88 */ u8 pad088[0xA];
    /* 0x92 */ s16 stopSoundVolume;
    /* 0x94 */ s16 stopSoundPitch;
    /* 0x96 */ s16 stopSoundId;
} ObjectRotation; /* size = 0x98 */

/*
 * func_801B3D60: update_ball_damage_visuals.
 * D_8029F5C9: active damage-overlay count; D_801F1A90: overlay scale padding.
 * D_8029F9AC starts the ball position, with rotation at +0x68 and scale
 * at +0x88. D_8029FA4C points to its 0x34-byte action-state block.
 * D_8029F60C and D_8029F6AC are overlapping views of the 0xE4-byte
 * damage-overlay objects, starting at position and action-state pointer.
 * Elem8029F60C: a (+0x00) copies position as three integer words;
 * q (+0x68) is world rotation, q2 (+0x78) is the fixed local rotation;
 * x/y/z (+0x88/8C/90) are scale. Elem8029F6AC.ptr (+0x00) points to
 * Words13, a 13-word opaque action-state copy. Preserve these word-copy
 * views: interpreting their storage as floats can change the emitted loads.
 * func_801488C0 multiplies quaternions: out = ballRotation * localRotation.
 */
typedef struct {
    /* 0x00 */ s32 w[13]; /* Opaque action state, copied without conversion. */
} BallActionStateCopy; /* size = 0x34 */

enum BallDamageVisualOffsets {
    BALL_DAMAGE_ROTATION_FROM_POSITION = 0x68,
    BALL_DAMAGE_SCALE_FROM_POSITION = 0x88
};

/* Integer view for copying three floating-point coordinates without conversion. */
typedef struct Vec3Words {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
} Vec3Words; /* size = 0x0C */

/* Single-field views preserve aggregate access semantics without changing globals. */
typedef struct ScalarF32 { /* 0x00 */ f32 value; } ScalarF32; /* size = 4 */
typedef struct ScalarS32 { /* 0x00 */ s32 value; } ScalarS32; /* size = 4 */
typedef struct ScalarS8 { /* 0x00 */ s8 value; } ScalarS8; /* size = 1 */

/*
 * func_80125294: update game-over text and return to the main menu.
 * D_801F8414 / D_801F8418: upper / lower text objects (Y at +0x4C).
 * D_801F841C: inward text velocity; D_801F8420 / D_801F8424: text Y positions.
 * D_801EAB54 / D_801EAB60: localized upper / lower text pointer tables.
 * D_801E7586: language index; D_801E7470: game-over frame counter.
 * D_801015D8/DC/E0: text scale (1), initial Y positions (-32, 288).
 * The double at D_801015E0 + 4 is acceleration (1.5).
 * D_801015EC/F0/F4/F8: upper stop Y (104), minimum bounce speed (5),
 * lower stop Y (120), and bounce damping (double 0.7).
 * D_801ED3D0: identity quaternion (0, 0, 0, 1).
 * func_80147000: bounded random integer; func_80177A14: select music.
 * func_8012A77C: insert score into the high-score table and save it.
 * func_8014D4D0 / func_8014D5E0: start / test completion of screen transition.
 * func_801C0A2C / func_801C0B00: stop / count audio channels by category.
 * func_8011CD50 / func_8011CAF8: unload level / release remaining scene resources.
 */
/* func_8011CCF0: black out the screen, silence sound effects, then unload the level. */
enum SceneExitConstants {
    SCENE_EXIT_AUDIO_FLAGS = 1,          /* MusStop flags: MUS_FLAG_EFFECTS */
    SCENE_EXIT_AUDIO_STOP_TICKS = 1,     /* fade-out length in audio updates */
    SCENE_EXIT_TRANSITION_EXTENT = 300,  /* screen transition fully closed */
    SCENE_EXIT_FULL_UNLOAD = 1           /* func_8011CD50 argument */
};
/* func_8014D5E0: the screen transition (extent D_801E753C, target D_801E753E)
 * counts as closed once both have reached this extent (of 300). */
enum ScreenTransitionConstants {
    SCREEN_TRANSITION_CLOSED_EXTENT = 0x114
};
/*
 * func_801230A8: update congratulations screen after the final encounter.
 * D_801E7468 is its frame counter; D_801E7618 locks transition input;
 * D_801F83E0 is the horizontal offset of the two bonus-level text lines.
 * D_801EAB78 holds localized "CONGRATULATIONS!" strings; D_801EAB84 holds
 * "BUT YOU MISSED" in three languages, followed by "BONUS LEVELS".
 * D_801010E8 is "%s %d"; D_801E7586 selects the language (0 is English).
 * D_801EAA48 contains save completion bits at a seven-word slot stride;
 * bit 4 of each five-bit world group records its bonus-level completion.
 * D_801EAB24 selects the save slot. D_80290188 is the score.
 * D_801FAAC6[].f contains controller button input; D_80202218 selects it.
 * D_801ED400/401/402 are transition RGB channels; D_801E753C is its extent.
 *
 * D_801014C8 = initial text offset (320); CC = easing divisor (4);
 * D0/D4 = step limits (-50/50); D8 = final offset (1); DC = title scale (1);
 * E0/E4 = translated/English message scales (0.9/1); E8 = center X (160).
 * func_801335A8 saves current progress; func_8014ED2C updates screen particles;
 * func_8014E8B4 emits a radial particle burst; func_8014D61C sets the screen
 * color and fade parameters; func_801469E4 queues text; func_801D2150 is sprintf.
 * func_80132648 initializes the ending credits.
 */
/* func_80122D90: update_error_screen.
 * D_801E7478 is its frame counter; D_801E760E locks confirmation during exit.
 * D_801E7544 is the 60-byte error message buffer, initially empty.
 * D_801014A0 is the drawing tag "errorscn"; D_801014AC is "PRESS A TO CONTINUE";
 * D_801014C0 is the text scale, 1.0f.
 * D_801FAAC6[].f is the selected controller's A-button input.
 * func_80145680 selects the font (0 normal, 1 alternate);
 * func_80145E30 removes all text; func_801469E4 creates a text object.
 * func_8014D548 starts the fade in; func_8014D4D0 starts the fade out;
 * func_8014D5E0 tests fade-out completion. D_801ED400/401/402 set its RGB.
 * func_801C0A2C / func_801C0B00 stop / count music voices (category 1);
 * func_8011CD50 unloads the level; func_80155AE4 resumes drawing.
 */
enum ErrorScreenConstants {
    ERROR_SCREEN_CENTER_X = 160,
    ERROR_SCREEN_MESSAGE_Y = 60,
    ERROR_SCREEN_PROMPT_Y = 100,
    ERROR_SCREEN_COLOR_MAX = 255,
    ERROR_SCREEN_MESSAGE_BLUE = 155,
    ERROR_SCREEN_CENTER_TEXT = 1,
    ERROR_SCREEN_INPUT_LOCK = 200,
    ERROR_SCREEN_TRANSITION_EXTENT = 300
};

enum CongratulationsConstants {
    CONGRATS_SAVE_FRAME = 2,
    CONGRATS_INPUT_FRAME = 20,
    CONGRATS_SLIDE_FRAME = 40,
    CONGRATS_TIMEOUT = 200,
    CONGRATS_INPUT_LOCK = 200,
    CONGRATS_FLASH_FRAME = 21,
    CONGRATS_BURST_FRAME = 26,
    CONGRATS_BURST_COUNT = 10,
    CONGRATS_BURST_JITTER = 8,
    CONGRATS_BURST_X_SHIFT = 5,
    CONGRATS_BURST_X_OFFSET = 8,
    CONGRATS_BURST_PARTICLES = 4,
    CONGRATS_PARTICLE_TYPE = 6,
    CONGRATS_TITLE_X = 160,
    CONGRATS_TITLE_Y = 30,
    CONGRATS_FLASH_STEP = -30,
    CONGRATS_MESSAGE_Y = 85,
    CONGRATS_BONUS_LABEL_Y = 120,
    CONGRATS_WORLD_COUNT = 6,
    CONGRATS_SAVE_SLOT_WORDS = 7,
    CONGRATS_WORLD_BIT_STRIDE = 5,
    CONGRATS_BONUS_BIT = 4,
    CONGRATS_LANGUAGE_COUNT = 3,
    CONGRATS_ENGLISH = 0,
    CONGRATS_TEXT_BUFFER_SIZE = 64,
    CONGRATS_TRANSITION_EXTENT = 300
};

enum GameOverConstants {
    GAME_OVER_SPECIAL_LEVEL = 0x28,
    GAME_OVER_EFFECT_FRAME = 20,
    GAME_OVER_EFFECT_WAIT_END = 40,
    GAME_OVER_TIMEOUT = 100,
    GAME_OVER_INPUT_LOCK = 200,
    GAME_OVER_TEXT_CENTER_X = 160,
    GAME_OVER_UPPER_START_Y = -32,
    GAME_OVER_LOWER_START_Y = 288,
    GAME_OVER_UPPER_STOP_Y = 104,
    GAME_OVER_LOWER_STOP_Y = 120,
    GAME_OVER_TEXT_Y_OFFSET = 0x4C,
    GAME_OVER_TRANSITION_EXTENT = 300
};

/* func_80148654 (matrix_to_quaternion) reads the rotation block of a
 * row-vector Matrix4f through a flat f32 pointer and writes x/y/z/w.
 * Positive trace computes w first; otherwise the largest diagonal selects
 * the first vector component, with the remaining axes in cyclic order.
 * D_801062F4 / D_801062FC supply the square-root bias;
 * D_801062F8 / D_80106300 supply the half-scale factors.
 */
enum QuaternionComponent {
    QUAT_X = 0,
    QUAT_Y = 1,
    QUAT_Z = 2,
    QUAT_W = 3
};

enum Matrix4RotationElement {
    MATRIX4_XX = 0,
    MATRIX4_XY = 1,
    MATRIX4_XZ = 2,
    MATRIX4_YX = 4,
    MATRIX4_YY = 5,
    MATRIX4_YZ = 6,
    MATRIX4_ZX = 8,
    MATRIX4_ZY = 9,
    MATRIX4_ZZ = 10,
    MATRIX4_ROW_BYTES = 16
};

/* Integer view for preserving quaternion bits during whole-value copies. */
typedef struct QuaternionWords {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
    /* 0x0C */ s32 w;
} QuaternionWords; /* size = 0x10 */

/*
 * func_80147B10: step toward a target quaternion along the shorter arc.
 * Inputs are unit quaternions in x/y/z/w order. The step is measured in
 * acos(dot) radians (half the corresponding physical rotation angle).
 * func_80147704 performs spherical interpolation using a fraction of that arc.
 * ACOS_BLK uses a u16 table centered at D_801D41D0 + 0x4E20:
 * index = dot * 10000, angle = table[index] / 20000.
 * D_80106244/64/84 are index scales; D_80106248[0], D_80106268[0],
 * and D_80106288 are angle divisors. The doubles at +4/+12/+20 in
 * D_80106228/48/68 are domain bounds (+/-1.000001) and exact one.
 * D_80106184 is the diagnostic format "\\n%f\\n"; D_8010618C is "ACOS".
 * func_801D2150 formats diagnostics into D_8025D578; func_80139D70 is
 * a disabled debug-output hook, and func_80139D94 reports the operation name.
 */
/* func_80148000 measures the longer quaternion arc, then uses func_80147704
 * for interpolation. Its pool blocks D_80106288/A8/C8 hold the same acos
 * bounds at +4 and +12, exact one at +20, and index scale 10000 at +28.
 * D_801062A8[0], D_801062C8[0], and D_801062E8 are angle divisors (20000).
 * Unlike func_80147B10, its distance comparison selects a nonpositive dot.
 */
enum QuaternionStepResult {
    QUATERNION_STEP_IN_PROGRESS = 0,
    QUATERNION_STEP_REACHED = 1
};

enum ObjectRotationFlags {
    ROTATION_STOP_AFTER_CYCLE = 1,
    ROTATION_STOP_AT_NEXT_TARGET = 2,
    OBJECT_APPLY_SPIN = 0x4000,
    OBJECT_RESTORE_ROTATION = 0x10000
};

/* func_801B31A8: object_update_rolling_from_motion.
 * func_801B2B58: object_set_roll_from_displacement; computes axis/angle
 * spin at +0xAC, or pitch/yaw, using the object's radius at +0x30.
 * func_801C4040 / func_801C6000 are cosf / sinf.
 * Collision state at object +0xD8 starts with four contact-face pointers;
 * +0x178 is the supporting platform. Faces start with their normal and
 * store the surface-material index at +0x74.
 * D_801ED74C is the 0x1C-byte surface-parameter table. Its first f32
 * (legacy member f) scales rolling resistance; the other six words retain
 * their existing types. Initial first-column values are 1, 0.5, 6, 0.3.
 * D_8010BA6C = 1 (minimum rolling divisor); D_8010BA70 = 2
 * (surface resistance normalization), verified in asm/1000.s.
 * Platform +0x5C/+0x60/+0x64 supplies motion to subtract from displacement;
 * when rotation exists, XZ is rotated by negative platform yaw first.
 * The role of platform +0x68 is unresolved; zero enables this adjustment.
 * Preserve raw accesses and legacy declarations for compiler aliasing.
 * N64 symbol renaming is unavailable; descriptive names are recorded here.
 */
/*
 * func_8017574C: player_check_slope_slide; accepts the flat normal-first
 * CollisionTriangle view and enters or sustains the slope-sliding state.
 * func_80167604: player_set_state, including animation and state-entry effects.
 * D_801ED75C: surface parameter at table +0x10; values below 1 skip this check.
 * D_801ED764: surface slope factor at table +0x18, used as a divisor.
 * D_801083BC = 1 (f32); D_801083C0 = 0.25 and D_801083C8 = 1 (f64).
 * The normal-Y entry threshold is 1 - 0.25 / surfaceSlopeFactor.
 * D_801EF474 is the secondary normal-Y threshold. D_80290148 records
 * normalY > threshold / factor; D_80290108 records normalY <= threshold.
 * D_8028FBD8: player action countdown, shortened to 1 while already sliding.
 * D_80290318/31C/320: previous player position, subtracted from current XYZ.
 * Raw accesses preserve the matched function's aliasing and declaration types.
 */
enum PlayerSlopeSlideConstants {
    SURFACE_PARAMETER_STRIDE = 0x1C,
    PLAYER_STATE_SLOPE_SLIDE = 0x23
};

enum ObjectRollingField {
    ROLLING_OBJECT_CONTACT_STATE = 0xD8,
    ROLLING_PLATFORM_MOTION_X = 0x5C,
    ROLLING_PLATFORM_MOTION_Z = 0x64,
    ROLLING_PLATFORM_UNK68 = 0x68,
    ROLLING_PLATFORM_MOTION_FLAG = 0x200
};

enum ObjectRotationDelay {
    ROTATION_RESTART_DELAY = -2,
    ROTATION_WAYPOINT_DELAY_SCALE = 10
};

/*
 * func_8017B178 updates spin, restoring torque and scheduled rotation stops.
 * func_80148C3C / func_801489F0 convert axis-angle to / from quaternion.
 * func_801488C0 multiplies quaternions; func_801496C8 wraps by one turn.
 * func_8014944C returns the shortest unsigned angular distance.
 * func_80178134 plays a positional sound; func_80178704 stops a sound state.
 * D_801ED3D0 is the identity quaternion (x, y, z, w = 0, 0, 0, 1).
 * D_801087C8 = 0.99995 (identity threshold for quaternion w);
 * D_801087D0 = 6.283185308 (full turn); D_801087D8 = 0.0001 (snap tolerance).
 */

/* Animation clips are 0x0C-byte entries in an object's animation table.
 * func_80133BD0 (advanceObjectAnimation) advances the frame, wraps looping
 * clips, or clamps completed clips and starts the next queued animation.
 * finished is zero while playing, otherwise the completed clip index + 1.
 * func_80133998 (set_object_animation) starts a clip or appends it to the
 * queue; speed zero selects the clip's default speed. Loop and queue flags
 * use only their low byte. Restarting immediately clears the queue via
 * func_80133B9C (clear_object_animation_queue), unless the same unfinished
 * clip and speed are already active, in which case only looping changes.
 * Negative speed starts an immediate animation at its last frame.
 * D_80105934 is the -1.0f speed sentinel for an unused queue slot.
 */
/* func_8019B658: actor_type41_update_proximity_pause. Animation 5 pauses
 * horizontal motion and yaw changes; once it finishes, leaving the outer
 * distance threshold starts animation 6 and queues looping animation 15.
 * ActorAnimation describes the animation component; byte accesses retain
 * the original aliasing. func_80148EBC returns squared XYZ distance;
 * func_80133998 starts or queues an animation. D_8029030C begins player XYZ.
 * Pool data in asm/1000.s: D_8010A8CC = 3600 (enter distance squared),
 * D_8010A8D4 = 3700 (leave distance squared), D_8010A8D0 = 1.3 (pause speed).
 */
enum Type41ProximityAnimation {
    TYPE41_ANIM_PAUSE = 5,
    TYPE41_ANIM_RESUME = 6,
    TYPE41_ANIM_MOVE = 9,
    TYPE41_ANIM_MOVE_LOOP = 15
};

enum ActorAnimationQueueConstants {
    ANIMATION_QUEUE_CAPACITY = 5,
    ANIMATION_QUEUE_UNUSED = -1
};
typedef struct ActorAnimationClip {
    /* 0x00 */ s16 firstFrame;
    /* 0x02 */ s16 lastFrame;
    /* 0x04 */ f32 speed;
    /* 0x08 */ s32 unk008;
} ActorAnimationClip; /* size = 0x0C */

typedef struct ActorAnimation {
    /* 0x00 */ s16 maxAnimation;
    /* 0x02 */ s16 current;
    /* 0x04 */ s32 finished;
    /* 0x08 */ s32 loop;
    /* 0x0C */ f32 speed;
    /* 0x10 */ s16 queuedAnimations[5];
    /* 0x1A */ u8 pad01A[2];
    /* 0x1C */ s32 queuedLoops[5];
    /* 0x30 */ f32 queuedSpeeds[5];
    /* 0x44 */ s16 queueCount;
    /* 0x46 */ u8 pad046[2];
    /* 0x48 */ ActorAnimationClip *clips;
    /* 0x4C */ f32 frame;
} ActorAnimation; /* size = 0x50 */

/* Type-13 actor animation effects (func_8019A668).
 * ActorAnimation describes the component at ACTOR_ANIMATION; raw accesses
 * below preserve the matched compiler's aliasing behavior.
 * func_801A2944 tests whether an animation frame was crossed.
 * func_80178134 plays a positional sound; func_80147000 returns a bounded
 * random integer; func_801B66D4 spawns a particle.
 * func_801B9974 starts distance-attenuated camera/actor shake.
 * D_802AA708 counts shake frames remaining; D_8029030C starts player XYZ;
 * D_801ED3C4 starts the zero vector.
 * Sound-frame floats: D_8010A7E4/E8 = 1/14 (animation 15);
 * D_8010A7EC/F0 = 28/36 and D_8010A7F4/F8 = 32/40 (animation 9);
 * D_8010A7FC = 84 (animation 5), D_8010A800 = 56 (animation 12).
 * Physics floats: D_8010A804 = 160 (animation-9 unk08),
 * D_8010A808 = 8 (animation-9 speed limit), D_8010A80C = 2 (default
 * speed limit), D_8010A810 = 40 (default unk08).
 * Particle floats: D_8010A814 = 48 (start frame), D_8010A818 = 2
 * (horizontal offset), D_8010A81C = 3 (height above actor bottom).
 * D_8010A820 = 0.96 (animation-12 physics response);
 * D_8010A824/828 = 83/90 (exclusive shake frame bounds).
 */
enum Type13EffectConstants {
    TYPE13_ANIM_SHAKE = 5,
    TYPE13_ANIM_FAST = 9,
    TYPE13_ANIM_PARTICLES = 12,
    TYPE13_ANIM_SOUND_PAIR = 15,
    TYPE13_SHAKE_SOUND = 0x2C,
    TYPE13_PARTICLE_SOUND = 0x2D,
    TYPE13_STEP_SOUND_A = 0x2E,
    TYPE13_STEP_SOUND_B = 0x2F,
    TYPE13_STEP_VOLUME = 10,
    TYPE13_SHAKE_SOUND_VOLUME = 255,
    TYPE13_PARTICLE_SOUND_VOLUME = 100,
    TYPE13_SOUND_PITCH = 128,
    TYPE13_PARTICLE_KIND = 0,
    TYPE13_PARTICLE_POSITION_RANGE = 5,
    TYPE13_SHAKE_DURATION = 50,
    TYPE13_SHAKE_CYCLES = 1
};

/* Type-25 animation effects (func_8019D294), using ActorAnimation at
 * ACTOR_ANIMATION. func_801A2944 tests a frame crossing, func_80178134
 * plays positional audio, func_80147000 returns a bounded random integer,
 * func_801B66D4 spawns a particle, and func_801B9974 starts attenuated shake.
 * D_801ED3C4 is the zero velocity vector; D_802AA708 is shake frames remaining.
 * Sound-frame floats: D_8010A9B4/B8 = 1/14 (animation 15),
 * D_8010A9BC/C0 = 28/36 and D_8010A9C4/C8 = 32/40 (animation 9),
 * D_8010A9CC = 84 (animation 5), D_8010A9D0 = 56 (animation 12).
 * D_8010A9D4 = 48 (particle start frame); D_8010A9D8 = 2 (XZ jitter bias);
 * D_8010A9DC = 3 (height above actor bottom); D_8010A9E0 = 0.96 (response).
 * D_8010A9E4/E8 = 83/90 (exclusive shake frame bounds).
 */
enum Type25EffectConstants {
    TYPE25_ANIM_SHAKE = 5,
    TYPE25_ANIM_BALL_CONTACT = 9,
    TYPE25_ANIM_PARTICLES = 12,
    TYPE25_ANIM_SOUND_PAIR = 15,
    TYPE25_SHAKE_SOUND = 0x2C,
    TYPE25_PARTICLE_SOUND = 0x2D,
    TYPE25_STEP_SOUND_A = 0x2E,
    TYPE25_STEP_SOUND_B = 0x2F,
    TYPE25_STEP_VOLUME = 10,
    TYPE25_SHAKE_SOUND_VOLUME = 255,
    TYPE25_PARTICLE_SOUND_VOLUME = 100,
    TYPE25_SOUND_PITCH = 128,
    TYPE25_PARTICLE_KIND = 0,
    TYPE25_PARTICLE_POSITION_RANGE = 5,
    TYPE25_SHAKE_DURATION = 50,
    TYPE25_SHAKE_CYCLES = 1
};

enum ActorEffectPhysicsOffset {
    ACTOR_EFFECT_RADIUS = 0x30,
    ACTOR_EFFECT_RESPONSE = 0x70,
    ACTOR_PHYSICS_UNK08_OFFSET = 8,
    ACTOR_PHYSICS_RESPONSE_OFFSET = 0x18
};

/* Byte offsets retain the integer-address accesses used by the matched C. */
/*
 * Type-26 actor: wakes near the player/ball, tracks the player along one axis,
 * and emits an attack effect at close range.
 * func_8019C020: update; func_80193298: move toward a point.
 * func_80133998: start/queue animation; func_80197794: select actor action.
 * func_80148E48/func_80148DB0: XYZ/XZ distance.
 * func_80149724: sin((frame + phase) / divisor).
 * func_80147460: XZ heading; func_801496C8: wrap angle by at most one turn.
 * func_801B66D4: spawn particle; func_801A9054: spawn actor effect.
 * func_80178134: play positional sound.
 * D_802004E0: update counter; D_802902D8: player object.
 * D_8029030C/310/314: player XYZ; D_8029F9AC: ball XYZ.
 * D_8029F9A4: ball's supporting object.
 * Constant pool (asm/1000.s): D_8010A92C = 160 (wake distance),
 * D_8010A930 = 17 (particle Y offset), D_8010A934 = -1 (particle Y speed),
 * D_8010A938 = 100 (tracking distance), +4 = 0.5 (f64 bob compensation),
 * D_8010A944 = 15 (tracking height), D_8010A948 = 65 (attack distance).
 */
enum Type26Behavior {
    TYPE26_ANIM_STOP_ATTACK = 3,
    TYPE26_ANIM_HIT = 4,
    TYPE26_ANIM_DORMANT = 5,
    TYPE26_ANIM_ACTIVE = 6,
    TYPE26_ANIM_WAKE = 10,
    TYPE26_ANIM_ATTACK = 11,
    TYPE26_ANIM_START_ATTACK = 12,
    TYPE26_ATTACK_SOUND = 0x57,
    TYPE26_ATTACK_EFFECT = 3,
    TYPE26_TRAIL_PARTICLE = 1,
    TYPE26_EFFECT_FRAME_MASK = 3,
    TYPE26_SOUND_VOLUME = 100,
    TYPE26_SOUND_PITCH = 128,
    TYPE26_TRACK_X = 8
};

/* func_80193298 moves an actor toward a 3D point; returns one on arrival
 * or when func_80192F84 overrides movement to avoid terrain/collision.
 * func_80148EBC / func_80148E48 give squared / ordinary XYZ distance.
 * func_80149568 normalizes the displacement; func_80147460 gives XZ heading.
 * func_8014944C / func_801494CC give absolute / signed shortest yaw difference;
 * func_801496C8 wraps an angle by at most one turn.
 * func_8016049C accelerates along current yaw and limits horizontal speed;
 * func_80160728 updates and limits total speed.
 * Actor +0xD0 points to physics floats: [1] acceleration, [3] speed limit.
 * Actor +0xDC points to ActorAnimation; type 18 moves in animation 9,
 * or during frames strictly between 103 and 134 of animation 15.
 * Actor +0x8C holds the yaw step; +0x28C scales the yaw error.
 * Pool doubles: D_8010A138 = 0.5 (type-43 arrival damping),
 * D_8010A140 = 3.141592654 (reverse displacement heading),
 * D_8010A150 = 1.0471975513333334 (turn damping threshold),
 * D_8010A158 = 0.8 (turn damping), D_8010A160 = 1.3 (arrival zone),
 * D_8010A168 = 0.7 (arrival acceleration), D_8010A170 = 0.08 (yaw deadband).
 * Pool floats D_8010A148 / D_8010A14C are animation frames 103 / 134.
 * Keep the existing raw accesses to preserve compiler aliasing.
 */
/* func_801948C8 updates a circular actor action (action type 13).
 * The action record begins at actor +0xE4: center XYZ at +4/+8/+C,
 * radius at +0x1C, and flags at +0x28. Runtime fields below use the same
 * base: frame +0x178, target Vec3F +0x17C, orbit phase +0x18C,
 * forward-only facing phase +0x190, and signed delay counter +0x196.
 * Keep byte-offset accesses to preserve the shared fields' storage types.
 *
 * Helpers: func_80148EBC = squared XYZ distance; func_801496C8 = wrap
 * by at most one turn; func_80149428 / func_80149604 = subtract / normalize
 * XZ only; func_80147460 = table-based atan2; func_8014915C = rotate about
 * axis 0/1/2 (X/Y/Z). func_80193298 / func_801936CC steer in XYZ / XZ.
 *
 * Orbit float pool: D_8010A27C = speed scale 1.12, D_8010A280 = type-24
 * speed scale 0.7, D_8010A284 = reverse initial phase pi, D_8010A288 =
 * advance distance squared 400. D_8010A28C is f64 velocity damping 0.9.
 * D_8010A294 / D_8010A298 = reverse / forward Z-orbit yaw (3pi/2, pi/2).
 * D_8010A29C = f64 Z-orbit pitch offset pi; D_8010A2A4 = forward
 * X-orbit yaw pi; D_8010A2A8 = f64 X-orbit pitch offset pi.
 * D_8010A2B0 / B4 / B8 are distinct unit-radius floats for X/Y/Z orbits.
 */
/* func_80194548: actor_update_charge (action 17).
 * Select the player, ball, or nearest of the two. Until facing the target
 * within 1 radian, refresh a destination 256 times the displacement toward it;
 * then lock that destination for the rest of the action. The first action
 * frame always refreshes the destination. Movement uses a 2-unit arrival radius.
 * func_80160E80 tests facing tolerance; func_80148EBC gives squared XYZ distance;
 * func_80193298 / func_801936CC steer in XYZ / XZ.
 * D_8029030C / D_8029F9AC: player / ball XYZ.
 * D_8010A264: 256.0f charge displacement scale.
 * D_8010A23C: "NME_CHARGE:error no player specified\\n".
 * func_801D2150 formats into D_8025D578; func_80139D70 is a disabled debug hook.
 * Offsets below are relative to the action record at ACTOR_ACTION_TYPE.
 * Keep raw accesses so the shared storage types and aliasing remain unchanged.
 */
/* func_80194354: actor_update_flee (action 12). Select player/ball by
 * flags, return one outside the horizontal flee radius, otherwise steer
 * toward actorPosition + 256 * (actorPosition - threatPosition).
 * The action record at ACTOR_ACTION_TYPE stores an s32 flee radius at +4
 * and movement/target-selection flags at +0x28. Type-data byte +8 selects
 * XYZ steering (1) or XZ steering (other values).
 * D_8010A238 = 256.0f; D_8010A20C =
 * "NME_FLEEPLAYER:error no player specified\\n".
 * func_80148EBC measures squared XYZ distance; func_80193298 / func_801936CC
 * steer in XYZ / XZ. func_801D2150 formats into D_8025D578 and
 * func_80139D70 is a disabled debug hook. Valid actions need a target flag.
 */
/* func_8019418C: actor_update_follow (action 9).
 * The action at +0xE4 stores target-relative XYZ offsets in float slots 1..3,
 * arrival distance in slot 7, and movement/target flags in word slot 10.
 * Actor +0x290 holds an origin/extent box; positive X extent enables it.
 * D_8028FBF6 is the player death/recovery timer; D_802903AC is player state.
 * D_8029F486 is ball status; D_8029030C / D_8029F9AC start player / ball XYZ.
 * func_80148EBC measures squared XYZ distance; func_80148F10 tests box inclusion.
 * func_80193298 / func_801936CC move toward a point in XYZ / XZ.
 * func_801D2150 formats the missing-target error D_8010A1E0 into the
 * 256-byte debug buffer D_8025D578; func_80139D70 is the disabled debug hook.
 * Keep raw accesses to preserve shared storage types and compiler aliasing.
 */
/* func_80193FC8: actor_update_facing. Selects player/ball (nearest ties
 * choose the ball), or picks a random yaw on the first action frame.
 * Actor +0x100 selects random facing when nonzero for this action.
 * D_8029030C / D_8029F9AC are player / ball Vec3F positions.
 * D_8010A1D4 = 100.0f scales random hundredths of a radian;
 * D_8010A1D8 = 0.1 (f64) is the strict facing tolerance.
 * D_8010A1A8 is "NME_FACEPLAYER:error no player specified\n".
 * func_801D2150 formats into D_8025D578; func_80139D70 is a no-op debug hook.
 * func_80148EBC measures squared XYZ distance; func_80133998 starts animation;
 * func_80147460 computes atan2; func_801496C8 wraps yaw by one turn;
 * func_80147000 returns random % bound; func_8014944C gives unsigned shortest
 * angular distance. Raw accesses preserve shared storage types and aliasing.
 */
/*
 * func_80194754: actor_update_jump (action 23). On the first frame, apply
 * upward velocity and forward acceleration, then start animation 7.
 * Optional target braking halves X/Z velocity and subtracts 0.8 from Y
 * while within 15 horizontal units of the selected player or ball.
 * D_8029030C / D_8029F9AC are player / ball XYZ positions.
 * Pool: D_8010A268 = 15.0f; double at +4 = 0.5;
 * double at D_8010A270 +4 = 0.8 (verified in asm/1000.s).
 * func_8016049C accelerates along yaw with a horizontal speed limit;
 * func_80133998 sets animation; func_80178134 plays positional sound;
 * func_80148DB0 measures XZ distance. Braking requires a target flag.
 * Raw accesses preserve the shared fields' storage types and aliasing.
 */
enum ActorJumpConstants {
    ACTOR_JUMP_VERTICAL_SPEED = 0xEC,
    ACTOR_JUMP_FORWARD_IMPULSE = 0xF0,
    ACTOR_JUMP_KEEP_VELOCITY = 1,
    ACTOR_JUMP_TARGET_PLAYER = 0x40,
    ACTOR_JUMP_TARGET_BALL = 0x80,
    ACTOR_JUMP_KEEP_ANIMATION = 0x4000,
    ACTOR_JUMP_BRAKE_NEAR_TARGET = 0x800000,
    ACTOR_JUMP_ANIMATION = 7,
    ACTOR_JUMP_SOUND_TYPE = 0x1D,
    ACTOR_JUMP_SOUND = 0x13,
    ACTOR_JUMP_SOUND_VOLUME = 100,
    ACTOR_JUMP_SOUND_PITCH = 128
};

enum ActorFacingConstants {
    ACTOR_FACE_PLAYER = 0x40,
    ACTOR_FACE_BALL = 0x80,
    ACTOR_FACE_NEAREST = 0x100,
    ACTOR_FACE_RANDOM_MODE = 0x100,
    ACTOR_FACE_KEEP_ANIMATION = 0x4000,
    ACTOR_FACE_ANIMATION = 0xF,
    ACTOR_FACE_RANDOM_YAW_STEPS = 628
};

enum ActorFollowFlags {
    ACTOR_FOLLOW_PLAYER = 0x40,
    ACTOR_FOLLOW_BALL = 0x80,
    ACTOR_FOLLOW_NEAREST = 0x100
};

enum ActorFollowOffset {
    ACTOR_FOLLOW_BOUNDS = 0x290,
    ACTOR_FOLLOW_BOUNDS_WIDTH = 0x29C,
    FOLLOW_OFFSET_X_INDEX = 1,
    FOLLOW_OFFSET_Y_INDEX = 2,
    FOLLOW_OFFSET_Z_INDEX = 3,
    FOLLOW_ARRIVAL_DISTANCE_INDEX = 7,
    FOLLOW_MOVE_FLAGS_INDEX = 10,
    ACTOR_FOLLOW_XYZ_MOVEMENT = 1
};

enum ActorFleeFlags {
    ACTOR_FLEE_FROM_PLAYER = 0x40,
    ACTOR_FLEE_FROM_BALL = 0x80,
    ACTOR_FLEE_FROM_NEAREST = 0x100
};

enum ActorFleeOffset {
    FLEE_RADIUS = 4,
    FLEE_MOVE_FLAGS = 0x28
};

enum ActorChargeFlags {
    ACTOR_CHARGE_TARGET_PLAYER = 0x40,
    ACTOR_CHARGE_TARGET_BALL = 0x80,
    ACTOR_CHARGE_TARGET_NEAREST = 0x100
};

enum ActorChargeOffset {
    CHARGE_MOVE_FLAGS = 0x28,
    CHARGE_ACTION_FRAME = 0x178,
    CHARGE_DESTINATION = 0x17C,
    CHARGE_DESTINATION_LOCKED = 0x188
};

enum ActorChargeMovementMode {
    ACTOR_CHARGE_XYZ_MOVEMENT = 1
};

enum ActorOrbitFlags {
    ACTOR_ORBIT_AROUND_X = 0x8,
    ACTOR_ORBIT_AROUND_Y = 0x10,
    ACTOR_ORBIT_AROUND_Z = 0x20,
    ACTOR_ORBIT_FLAG_0200 = 0x200,
    ACTOR_ORBIT_REVERSE = 0x400
};

enum ActorOrbitOffset {
    ORBIT_CENTER_X = 4,
    ORBIT_CENTER_Y = 8,
    ORBIT_CENTER_Z = 0xC,
    ORBIT_RADIUS = 0x1C,
    ORBIT_FLAGS = 0x28,
    ORBIT_ACTION_FRAME = 0x178,
    ORBIT_TARGET_X = 0x17C,
    ORBIT_TARGET_Y = 0x180,
    ORBIT_TARGET_Z = 0x184,
    ORBIT_PHASE = 0x18C,
    ORBIT_FACING_PHASE = 0x190,
    ORBIT_DELAY_COUNTER = 0x196,
    ACTOR_ORBIT_PHASE = 0x270,
    ACTOR_ORBIT_FACING_PHASE = 0x274,
    ACTOR_TARGET_PITCH = 0x84,
    ACTOR_TYPE_MOVEMENT_MODE = 8,
    ACTOR_PHYSICS_SPEED_LIMIT_OFFSET = 0xC
};

enum ActorOrbitAxis {
    ORBIT_AXIS_X = 0,
    ORBIT_AXIS_Y = 1,
    ORBIT_AXIS_Z = 2
};

/* func_80193D60: actor_update_wander. D_8010A1A4 is the 20.0f arrival
 * margin added to the actor's radius (verified in asm/1000.s).
 * func_80193298 / func_801936CC steer in XYZ / XZ and return nonzero on
 * arrival or obstacle avoidance; func_80147000 returns random % bound;
 * func_80148EBC measures squared XYZ distance; func_80133998 sets/queues
 * animation; func_80197794 selects the next eligible actor action.
 * Wander data overlays the action record; offsets retain raw-access aliasing. */
/*
 * func_80193C2C: actor_choose_wander_target. Rejection-sample within these
 * bounds until the new target is at least ACTOR_WANDER_MIN_TARGET_DISTANCE
 * from the previous target. Movement mode zero keeps the actor's current Y.
 * func_80147000 is random_below; func_80148EBC is vec3_distance_squared.
 * Each extent is truncated to s32 before selecting an integer random offset.
 */
typedef struct ActorWanderBounds {
    /* 0x00 */ struct { f32 x, y, z; } minimum;
    /* 0x0C */ struct { f32 x, y, z; } extent;
} ActorWanderBounds; /* size = 0x18 */

enum ActorWanderOffset {
    ACTOR_WANDER_RADIUS = 0x74,
    ACTOR_WANDER_BOUNDS = 0xE8,
    ACTOR_WANDER_MIN_TARGET_DISTANCE = 0x100
};

enum ActorWanderConstants {
    ACTOR_WANDER_KEEP_ANIMATION = 0x4000,
    ACTOR_WANDER_USE_ANIMATION_9 = 0x40000,
    ACTOR_WANDER_TRANSITION_TYPE = 0x18,
    ACTOR_WANDER_TRANSITION_ANIMATION = 0xD,
    ACTOR_WANDER_DEFAULT_ANIMATION = 0xF,
    ACTOR_WANDER_ALTERNATE_ANIMATION = 9,
    ACTOR_WANDER_XYZ_MOVEMENT = 1
};

enum ActorMoveFlags {
    ACTOR_MOVE_ACCELERATE_FORWARD = 1,
    ACTOR_MOVE_ACCELERATE_XZ = 2,
    ACTOR_MOVE_NO_ARRIVAL_DAMPING = 4,
    ACTOR_MOVE_KEEP_TARGET_YAW = 0x1000,
    ACTOR_MOVE_SET_YAW_STEP = 0x2000
};

/* func_801936CC: actor_move_toward_point_xz. Returns one on arrival or
 * terrain/collision avoidance, zero while steering. Arrival halves XZ velocity.
 * D_8010A178 = 0.5 (arrival damping), D_8010A180 = pi (reverse heading),
 * D_8010A188 = 0.08 (minimum yaw step), all stored as doubles.
 * func_80148DB0 measures XZ distance; func_80149428 subtracts XZ;
 * func_80149604 normalizes XZ without touching Y.
 * Byte offsets preserve the existing shared declarations and aliasing.
 */
/*
 * func_80192F84 (actor_avoid_obstacles) probes 20 units along horizontal
 * velocity and checks four collision normals. It stops at unsafe ground
 * heights or pushes away from steep contacts, then starts a 30-frame delay.
 * Type 28 uses twice the full contact normal; other types use only X/Z.
 * func_8015B524 returns distance to ground and writes triangle/platform
 * pointers into the two output slots (legacy locals retain f32 storage).
 * func_8014932C adds X/Z vector components; func_80149568 normalizes XYZ.
 * func_8014944C returns absolute shortest yaw difference; func_801496C8
 * wraps yaw by one turn. Shared field declarations are unchanged.
 *
 * Pool values verified in asm/1000.s:
 * D_8010A0F4 = 20 (probe distance), D_8010A0F8 = f64 0.8 (normal Y limit),
 * D_8010A100 = f64 pi/2 (turn threshold), D_8010A108 = f64 pi (turn).
 */
enum ActorAvoidanceConstants {
    ACTOR_AVOIDANCE_DISABLED = 4,
    ACTOR_AVOIDANCE_CONTACT_SLOTS = 4,
    ACTOR_AVOIDANCE_DELAY_FRAMES = 30,
    ACTOR_AVOIDANCE_DOUBLE_NORMAL_TYPE = 28,
    ACTOR_GROUND_DISTANCE_MAX = 0x2A8,
    ACTOR_GROUND_DISTANCE_MIN = 0x2AC
};

/* func_80160228 (approachObjectAxisAngle) turns one Euler component toward
 * its target along the shorter arc, limiting the step by physics +0x28.
 * Axis 0/1/2 selects pitch/yaw/roll at object +0x78 and target +0x84.
 * The physics block at object +0xD0 contains three signed mode bytes at
 * +0x24..+0x26 and an f32 maximum angular step at +0x28. Mode 1 halves
 * the remaining angular distance before applying the step limit.
 * func_8014944C is shortestAngleDistance; func_801496C8 is wrapAngleOnce.
 * Pool values verified from asm/1000.s: D_80107330 = 1 and
 * D_80107334 = 2 (f32 divisors), D_80107338 = 0.01 (f64 snap tolerance),
 * D_80107340 / D_80107348 = 3.141592654 (f64 half-turn thresholds).
 * Helper pools D_80106328 = pi, D_80106330 / D_80106368 / D_80106370
 * = 2*pi. Symbol names remain unchanged because N64 renames are unsupported.
 */
enum ObjectAngleApproachPhysics {
    PHYSICS_ANGLE_APPROACH_MODES = 0x24,
    PHYSICS_MAX_ANGLE_STEP = 0x28,
    ANGLE_APPROACH_HALF_DISTANCE = 1
};

enum ActorSteeringOffset {
    ACTOR_TYPE = 0x20,
    ACTOR_YAW_STEP = 0x8C,
    ACTOR_PHYSICS = 0xD0,
    ACTOR_TURN_RESPONSE = 0x28C,
    ACTOR_PHYSICS_ACCELERATION_INDEX = 1,
    ACTOR_PHYSICS_SPEED_LIMIT_INDEX = 3,
    ANIMATION_FRAME_OFFSET = 0x4C
};

/*
 * func_8019DB7C: actor_type23_update_bounds. Uses ActorAnimation at +0xDC
 * and the model contact count at +0x188 through ACTOR_MODEL_STATE.
 * func_80178134 plays positional sound; func_801A2944 tests a frame crossing.
 * func_80149044 tests an origin/extent box in XZ; func_80149428 subtracts XZ.
 * func_80147460 is table-based atan2; func_801496C8 wraps an angle once.
 * func_80197794 selects the next eligible actor action.
 * Pool words in asm/1000.s: D_8010AA1C = sound frame 35 (f32),
 * D_8010AA20 = horizontal damping 0.6 (f64), D_8010AA28 = center divisor 2.
 * Keep raw field accesses to preserve the matched aliasing behavior.
 */
enum Type23BoundsConstants {
    TYPE23_SOUND_ACTION = 23,
    TYPE23_ACTION_SOUND_FRAME = 2,
    TYPE23_ACTION_SOUND = 0x68,
    TYPE23_ANIMATION_SOUND = 0xDA,
    TYPE23_SOUND_VOLUME = 50,
    TYPE23_ACTION_SOUND_PITCH = 140,
    TYPE23_ANIMATION_SOUND_PITCH = 128,
    TYPE23_UNDAMPED_ANIMATION = 7,
    TYPE23_RETURN_ACTION = 1,
    TYPE23_RETURN_COOLDOWN_FRAMES = 80,
    TYPE23_BOUNDS_ORIGIN_Z = 0x298,
    TYPE23_BOUNDS_DEPTH = 0x2A4
};

/* func_8015EE6C: object_integrate_motion. Saves the position, adds velocity,
 * then damps each velocity axis: airborne objects (contact state without a
 * face) by half of (1 - physics linear damping), Y by the linear damping
 * unless flag 0x8000 is set, objects on a face by their velocity damping
 * divided by the surface's D_801ED74C resistance (when >= 1), and the rest
 * by ACTOR_VELOCITY_DAMPING alone. Type 4 gets airborne damping only with
 * flag 0x200000; type 0 never. Then it turns ACTOR_ORIENTATION by the spin
 * axis/angle (OBJECT_APPLY_SPIN) or integrates the Euler angular velocity
 * from ACTOR_PITCH, zeroed while D_801EEB60 is clear.
 * D_801072CC = 1.0f, D_801072D0 = 2.0f.
 */
enum ActorMotionOffset {
    ACTOR_VELOCITY_DAMPING = 0x70,
    ACTOR_ANGULAR_VELOCITY = 0x90,
    PHYSICS_LINEAR_DAMPING = 0x18,
    PHYSICS_ANGULAR_DAMPING = 0x1C
};

enum ActorTrackingOffset {
    ACTOR_PREVIOUS_POSITION = 0x40,
    ACTOR_PREVIOUS_POSITION_Y = 0x44,
    ACTOR_PREVIOUS_POSITION_Z = 0x48,
    ACTOR_BEHAVIOR_CONFIG = 0x130,
    ACTOR_MOVE_TARGET_X = 0x260,
    ACTOR_MOVE_TARGET_Z = 0x268,
    ACTOR_BOB_DIVISOR = 0x282,
    ACTOR_BOB_AMPLITUDE = 0x284,
    ACTOR_DEFAULT_YAW = 0x2B0,
    ACTOR_ACTION_DELAY_FROM_ACTION = 0x194,
    ACTOR_BEHAVIOR_CONFIG_FLAGS = 0x28,
    ANIMATION_FINISHED_OFFSET = 4
};

/* func_8019DEE8 updates type-20 animation sounds, particles and landing effects.
 * Actor +0xDC is ActorAnimation; +0x2C8 is PositionalSound.
 * func_801936CC steers toward a point in XZ; func_801A2944 tests whether
 * an animation frame was crossed. func_80178134 plays positional audio;
 * func_801785E0/func_80178704 start/stop tracked positional audio.
 * func_80149318 copies XZ only; func_80147000 returns a bounded random value.
 * func_801B66D4 spawns a particle; func_801B7984 emits five radial particles.
 * D_802004E0 is the current state's frame counter; D_8029030C is player X
 * followed by Y/Z. Pool floats: D_8010AA30/34 = frames 15/47,
 * D_8010AA38/3C = frames 31/63, D_8010AA40/44 = frames 122/128,
 * D_8010AA48/4C = frames 94/105, D_8010AA50 = particle height 25,
 * D_8010AA54 = particle Y velocity 4.
 */
/* func_8019E248: actor_type28_update_animation. Coordinates paired tracked
 * sounds, a quarter-turn clip, and a timed animation pause.
 * The animation at ACTOR_ANIMATION uses ActorAnimation/ActorAnimationClip;
 * both sound slots use PositionalSound. Raw accesses preserve aliasing.
 * func_80133998 selects/queues a clip; func_80133BD0 advances playback.
 * func_80178134 plays positional sound; func_801785E0/func_80178704
 * start/stop tracked sound. func_801494CC returns signed wrapped yaw error;
 * func_8015C350 rebuilds a quaternion from Euler angles.
 * Original pool words in asm/1000.s: D_8010AA58 = pi/2 (f64 turn offset),
 * D_8010AA60/68 = 0.4 (f64 positive/negative tolerances),
 * D_8010AA70 = 3*pi/2 (f32 pitch while paused).
 */
enum Type28AnimationConstants {
    TYPE28_ACTION_TURN = 2,
    TYPE28_ACTION_SOUND = 9,
    TYPE28_ANIM_IDLE = 5,
    TYPE28_ANIM_FAST_SOUND = 9,
    TYPE28_ANIM_TURN = 10,
    TYPE28_ANIM_SOUND_13 = 13,
    TYPE28_ANIM_SOUND_15 = 15,
    TYPE28_OVERRIDE_SOUND = 0x58,
    TYPE28_TRACKED_SOUND_A = 0x59,
    TYPE28_TRACKED_SOUND_B = 0x5A,
    TYPE28_SOUND_VOLUME = 100,
    TYPE28_SOUND_PITCH = 128,
    TYPE28_TRACKED_PITCH = 120,
    TYPE28_FAST_TRACKED_PITCH = 150,
    TYPE28_PAUSE_TRIGGER_FLAG = 0x4000000,
    TYPE28_PAUSED_FLAG = 1,
    TYPE28_PAUSE_FRAMES = 70,
    TYPE28_RESUME_FRAMES = 10,
    TYPE28_PAUSE_TIMER_OFFSET = 0x26C,
    TYPE28_SECOND_SOUND_OFFSET = 0x2E4
};

enum Type20EffectConstants {
    TYPE20_ANIM_TRACKED_SOUND = 5,
    TYPE20_ANIM_SOUND_PAIR = 9,
    TYPE20_ANIM_PARTICLES = 10,
    TYPE20_ANIM_TRACK_PLAYER = 11,
    TYPE20_IMPACT_ACTION = 23,
    TYPE20_TRACKED_SOUND = 0x26,
    TYPE20_PARTICLE_SOUND = 0x27,
    TYPE20_IMPACT_SOUND = 0x2A,
    TYPE20_ACTION_START_SOUND = 0x7D,
    TYPE20_PARTICLE = 0x12,
    TYPE20_SOUND_FADE_STEP = 5,
    TYPE20_SOUND_VOLUME = 100,
    TYPE20_SOUND_PITCH = 128,
    TYPE20_PARTICLE_POSITION_RANGE = 11,
    TYPE20_PARTICLE_POSITION_RADIUS = 5,
    TYPE20_PARTICLE_VELOCITY_RANGE = 5,
    TYPE20_PARTICLE_VELOCITY_RADIUS = 2
};

/* func_80199758: actor_type35_update_animation.
 * Uses ActorAnimation at ACTOR_ANIMATION and PositionalSound at ACTOR_SOUND_STATE.
 * func_801A2944 tests a frame crossing; func_80178134 plays positional audio.
 * func_801785E0 starts tracked positional audio; func_80178704 stops it.
 * func_8016049C accelerates forward, limiting horizontal speed to physics +8.
 * func_80195D50 begins actor death and its effects.
 * D_8010A730/734 are sound trigger frames for clips 5/10; D_8010A738
 * scales movement speed to animation speed. Their pool values remain unverified.
 * Raw field accesses retain the matched function's aliasing behavior.
 */
enum Type35AnimationConstants {
    TYPE35_SOUND_ANIMATION_5 = 5,
    TYPE35_SOUND_ANIMATION_10 = 10,
    TYPE35_TRACKED_SOUND_ANIMATION = 11,
    TYPE35_ANIMATION_SOUND = 0x49,
    TYPE35_TRACKED_SOUND = 0x4A,
    TYPE35_SOUND_VOLUME = 100,
    TYPE35_MOVE_ACTION = 7,
    TYPE35_DEATH_FRAME = 201,
    TYPE35_PHYSICS_SPEED_LIMIT_OFFSET = 8
};

/* func_8019B7AC: actor_type39_update_explosion.
 * Plays the action cue, accelerates the fuse animation, then detonates once
 * clip 12 finishes. ActorAnimation/ActorAnimationClip describe the component;
 * byte offsets below retain the matched integer-address access semantics.
 * D_8010A8D8 supplies the blast speed limit; D_8010A8DC its impulse scale.
 * Helpers: func_80178134 sound_play_positional; func_801785E0 sound_start_tracked;
 * func_80133998 object_set_animation; func_8014D61C screen_flash_start;
 * func_801BA0E0 apply_radial_blast; func_801B9974 shake_start_at_position;
 * func_80195D50 actor_begin_death.
 */
enum Type39ExplosionConstants {
    TYPE39_CUE_ACTION = 23,
    TYPE39_DETONATE_ANIMATION = 12,
    TYPE39_DEAD_STATE = 2,
    TYPE39_FUSE_SOUND_FRAME = 2,
    TYPE39_FUSE_FRAMES = 100,
    TYPE39_DETONATE_ACTION_DELAY = 100,
    TYPE39_ACTION_SOUND = 0x68,
    TYPE39_FUSE_SOUND = 0x69,
    TYPE39_SOUND_VOLUME = 100,
    TYPE39_FLASH_ALPHA_STEP = -20,
    TYPE39_SHAKE_DURATION = 14,
    TYPE39_ANIMATION_SPEED_OFFSET = 0x0C,
    TYPE39_ANIMATION_CLIPS_OFFSET = 0x48,
    TYPE39_CLIP_STRIDE = 12,
    TYPE39_CLIP_SPEED_OFFSET = 4
};

/* func_80193988: actor_update_action4_animation.
 * Starts or queues clips 14 and 5, with optional startup sound and particles.
 * ActorAnimation describes the component at ACTOR_ANIMATION; raw accesses
 * retain the original aliasing. func_80133998 is object_set_animation,
 * func_80178134 is sound_play_positional, and func_801B70F8 is spawn_particle_ring.
 * D_8010A190 is the type-43 velocity damping factor, f64 0.5, verified
 * from the boot constant pool words 0x3FE00000 and 0.
 * Action 4 interprets +0xE8 as flags and +0x103 as the clip-5 loop byte.
 */
enum ActorAction4Constants {
    ACTOR_ACTION4_OPTIONS = 0xE8,
    ACTOR_ACTION4_LOOP = 0x103,
    ACTOR_ACTION4_STARTUP_EFFECTS = 1,
    ACTOR_ACTION4_PLAY_TRANSITION = 2,
    ACTOR_ACTION4_QUEUE_ANIMATION = 4,
    ACTOR_ACTION4_KEEP_ANIMATION = 0x4000,
    ACTOR_ACTION4_DAMPED_TYPE = 43,
    ACTOR_ACTION4_TRANSITION_CLIP = 14,
    ACTOR_ACTION4_MAIN_CLIP = 5,
    ACTOR_ACTION4_SOUND_FRAME = 2,
    ACTOR_ACTION4_EFFECT_FRAMES = 5,
    ACTOR_ACTION4_SOUND = 150,
    ACTOR_ACTION4_SOUND_VOLUME = 100,
    ACTOR_ACTION4_PARTICLE_COUNT = 2
};

/*
 * func_80139ACC: object_limit_horizontal_speed(object, maxSpeed, previousSpeed).
 * The player and ball share ACTOR_VELOCITY: a Vec3F (size 0x0C),
 * with f32 x/y/z at +0/+4/+8. Only x and z are changed.
 * Speed crossing the limit is clamped; existing excess speed is damped by 0.9.
 * Callers normally pass speed before acceleration; 10000 forces damping.
 * func_801C4030 is sqrtf. Pool doubles at D_80105B88+4 and D_80105B90+4
 * both contain 0.9 (0x3FECCCCCCCCCCCCD, verified in asm/1000.s).
 * Retain these 4-aligned pool accesses and the existing Vec3F declarations.
 */
enum ActorFieldOffset {
    ACTOR_FLAGS = 0x28,
    ACTOR_POSITION = 0x34,
    ACTOR_POSITION_Y = 0x38,
    ACTOR_POSITION_Z = 0x3C,
    ACTOR_VELOCITY = 0x58,
    ACTOR_YAW = 0x7C,
    ACTOR_TARGET_YAW = 0x88,
    ACTOR_MODEL_STATE = 0xD8,
    ACTOR_ANIMATION = 0xDC,
    ACTOR_ACTION_COOLDOWN = 0x248,
    ACTOR_ACTION_INDEX = 0x254,
    ACTOR_ACTION_FRAME = 0x25C,
    ACTOR_ACTION_DELAY = 0x278,
    ACTOR_SOUND_STATE = 0x2C8,
    ACTOR_SOUND_VOLUME = 0x2CC,
    ACTOR_PITCH = 0x78,
    ACTOR_ROLL = 0x80,
    ACTOR_ORIENTATION = 0x9C,
    ACTOR_SPIN_AXIS = 0xAC,
    ACTOR_SPIN_ANGLE = 0xB8,
    ACTOR_OVERRIDE_FRAME = 0x258 /* Zero selects the default action list. */
};

/*
 * func_80199A9C updates type-33 actor ball-facing rotation and idle spin.
 * The dispatcher subtracts 7 from the actor type before selecting case 26.
 * func_8015C350 converts Euler angles to a quaternion.
 * func_80147B10 approaches a quaternion with a maximum angular step.
 * func_80148C3C converts axis/angle to quaternion; func_801499EC rotates by
 * axis/angle. The spin axis at +0xAC and angle at +0xB8 form four floats.
 * func_80149568 normalizes a vector; func_801496C8 wraps an angle by one turn.
 * func_80178134 plays positional audio; func_80178704 stops tracked audio.
 * func_801B2B58 updates rolling rotation from an object's X/Z displacement.
 *
 * Constant pool, verified in asm/1000.s:
 * D_8010A74C = 3 (gravity divisor while supporting ball form 1).
 * D_8010A750 = 0.5 (f64 ball horizontal damping).
 * D_8010A758 = 0.3 (f64 facing pitch offset).
 * D_8010A760 = 0.6 (f64 actor velocity damping).
 * D_8010A768/770 = 19/1 (f64 pull-speed ramp divisor/base).
 * D_8010A778/77C/780 = 3/6/1 (pull limit, rolling divisor/base).
 * D_8010A784 = 1 (unit direction); D_8010A788 = 0.05 (f64 spin-axis jitter).
 * D_8010A790 = 0.035 (idle spin step); +4 = 0.3 (f64 ball speed threshold).
 */
/*
 * func_8019A2C8: actor_type30_update_jump, for action 23.
 * The action starts at ACTOR_ACTION_TYPE (actor +0xE4). Its float at +8
 * supplies launch velocity Y, and +0xC supplies forward acceleration.
 * The s32 at action +0x178 is ACTOR_ACTION_FRAME, shared runtime storage.
 * func_8016049C adds forward velocity and caps horizontal speed (20 here);
 * func_80133998 selects an animation (8 when descent begins).
 * D_801ED680 is gravity (initially 1.2f); D_8010A7BC = 3 divides its
 * upward compensation. D_8010A7B0 + 4 holds f64 initial damping 0.3;
 * D_8010A7C0 holds f64 horizontal damping 0.2; D_8010A7C8 = 4 is
 * the additional downward acceleration after the pause.
 */
enum Type30JumpConstants {
    TYPE30_JUMP_ACTION = 23,
    TYPE30_JUMP_INITIAL_FRAME = 1,
    TYPE30_JUMP_LAUNCH_FRAME = 9,
    TYPE30_JUMP_ALWAYS_UPDATE_FRAME = 14,
    TYPE30_JUMP_COAST_FRAME = 18,
    TYPE30_JUMP_DESCENT_FRAME = 35,
    TYPE30_JUMP_DESCENT_ANIMATION = 8,
    TYPE30_JUMP_LAUNCH_VELOCITY = 0xEC,
    TYPE30_JUMP_ACCELERATION_FROM_ACTION = 0xC,
    TYPE30_JUMP_FRAME_FROM_ACTION = 0x178,
    TYPE30_JUMP_CLEAR_ALWAYS_UPDATE = 0xFFDFFFFF
};

enum Type33BallInteraction {
    TYPE33_SOUND_IDLE = 0x19,
    TYPE33_SOUND_BALL = 0x1A,
    TYPE33_SOUND_VOLUME = 100,
    TYPE33_SOUND_PITCH = 128,
    TYPE33_SOUND_FADE_STEP = 5,
    TYPE33_ACTION_UPRIGHT = 4,
    TYPE33_UPRIGHT_DELAY = 5,
    TYPE33_IDLE_SOUND_FRAME_MASK = 0x3F,
    TYPE33_IDLE_SOUND_CHANCE_RANGE = 20,
    TYPE33_IDLE_SOUND_CHANCE_COUNT = 5,
    TYPE33_SPIN_JITTER_RANGE = 21,
    TYPE33_SPIN_JITTER_CENTER = 10
};

/* func_80145298 samples translation and rotation tracks at frame + frameOffset,
 * wrapping past the clip end to its start, then writes the player quaternion
 * D_80290374 after a 180-degree Y-axis basis conversion. Its translation matrix
 * is built but is not used in the final orientation.
 * func_80147704 interpolates quaternions; func_801484F0 converts quaternion
 * to matrix; func_80148654 converts matrix to quaternion.
 * func_801C61A0 is guTranslateF; func_801C5B90 is guRotateF;
 * func_801C5580 is guMtxCatF (matrix multiplication, output may alias input).
 * D_801060D4/D_801060D8 hold translation/rotation fallback fractions.
 * The f64 at D_801060D8 + 4 scales translation coordinates.
 */
/* func_801437E4 (drawObjectModel) draws an object's animated model tree.
 * func_80145258 tests the object's squared distance against its draw radius.
 * func_80133BD0 advances its queued animation; func_80143AFC draws model nodes.
 * func_80149834 / func_801498CC push-and-concatenate / pop the CPU matrix stack.
 * func_801C5F20 is guScaleF; the other matrix helpers are described below.
 * D_80263ABC is the object's cached matrix storage; D_8026A144 selects its reuse.
 * D_801EC87C forces matrix rebuilding; D_801EC866 bypasses distance culling.
 * D_80263AB0/AB4/AB8 are the current object's XYZ scale.
 * D_80269EC0/EC4/EC8 hold parent scale by hierarchy depth D_801EC868.
 * D_801EC870 tracks emitted modelview depth; D_801EC87A is object opacity.
 * D_80269F38 is the object currently being drawn.
 * N64 symbol renames are unavailable; retain these symbol-role annotations.
 */
enum ObjectModelRenderOffset {
    OBJECT_CACHED_MATRICES = 0x1C,
    OBJECT_RENDER_OPACITY = 0x26,
    OBJECT_SCALE_X = 0xBC,
    OBJECT_SCALE_Y = 0xC0,
    OBJECT_SCALE_Z = 0xC4,
    TYPE_DEFORM_SCALE_XZ = 0x10,
    TYPE_DEFORM_SCALE_Y = 0x14,
    TYPE_DEFORM_AMOUNT = 0x18,
    TYPE_DEFORM_COUNTER = 0x1C,
    TYPE_DEFORM_ORIENTATION = 0x20,
    ANIM_PLAYBACK_CLIPS = 0x48
};

/* Model node fields read by func_80143AFC (drawModelNode). Keyframes are
 * 20 bytes: XYZ (or a 16-byte XYZW quaternion) then an s32 frame at +0x10.
 * Sprite slots are 0x18 bytes: +0x04 sprite object, +0x08/0x0A/0x0C local
 * position, +0x0E/0x10 sprite width/height. */
enum ModelNodeDrawField {
    NODE_OPACITY = 0x0D,          /* u8 */
    NODE_SCALE_KEY_COUNT = 0x0E,  /* s16 */
    NODE_TRANS_KEY_COUNT = 0x10,  /* s16 */
    NODE_ROT_KEY_COUNT = 0x12,    /* s16 */
    NODE_MESH = 0x14,
    NODE_DISPLAY_LIST = 0x18,
    NODE_SCALE_KEYS = 0x1C,
    NODE_TRANS_KEYS = 0x20,
    NODE_ROT_KEYS = 0x24,
    NODE_SPRITE_COUNT = 0x28,
    NODE_SPRITES = 0x2C,
    NODE_FLAGS = 0x32,            /* u16 */
    NODE_CHILD = 0x34,
    NODE_SIBLING = 0x38,
    NODE_ATTACHMENT = 0x3C
};
enum ModelNodeDrawFlag {
    NODE_FLAG_ALT_MESH_DRAW = 0x01,
    NODE_FLAG_ENV_EFFECT = 0x02,
    NODE_FLAG_ALT_RENDER_MODE = 0x04,
    NODE_FLAG_NO_LIGHTING = 0x08,
    NODE_FLAG_LOOP_ROTATION = 0x40
};

/* func_801B10B8: setActorDirectionalDeformation.
 * Nonnegative amounts are scaled by physics +0x34, capped by the fourth
 * argument, and ignored if weaker than the current deformation. Negative
 * amounts directly set scale XZ from the fourth argument and scale Y from
 * their magnitude, with counter -1. The direction supplies the deformation
 * quaternion: normalize(up cross direction), angle acos(direction.y).
 * Actor type data +0x10/+0x14 are XZ/Y scales, +0x18 is deformation amount,
 * +0x1C is a signed counter, and +0x20 is an XYZW quaternion (16 bytes).
 * Physics +0x3C > 0 enables the initial 1+amount / 1-amount scale assignment.
 *
 * func_801470F8: up cross vector; func_80147114: table-based acos.
 * func_80149568: normalize vector; func_80148C3C: axis-angle to quaternion.
 * D_8029F9A4: ball supporting object; D_8029F487: ball form.
 * D_8029F9D0/D4/D8: ball velocity XYZ; a type-28 support can add an impulse.
 * D_8010B864 / D_8010B870 / D_8010B878: impulse multipliers (8).
 * D_8010B868 / D_8010B86C: vertical impulse thresholds (2).
 * D_8010B874: minimum upward impulse (2); D_8010B87C: unit scale (1).
 * Symbol renaming is unavailable for N64 projects; raw accesses retain
 * existing aliasing behavior and shared source lines retain scheduling.
 */
enum ActorDeformationConstants {
    PHYSICS_DEFORM_MULTIPLIER = 0x34,
    PHYSICS_DEFORM_SCALE_ENABLE = 0x3C,
    DEFORM_BALL_IMPULSE_ACTOR_TYPE = 0x1C,
    DEFORM_EXCLUDED_BALL_FORM = 1,
    DEFORM_BALL_IMPULSE_COUNTER_MIN = 4,
    DEFORM_DIRECT_SCALE_COUNTER = -1,
    DEFORM_BALL_VELOCITY_Y_WORDS_FROM_SUPPORT = 12
};

/* XYZW quaternion copied as four words, preserving the original copy type. */
typedef struct RenderQuaternionWords {
    /* 0x00 */ s32 w[4];
} RenderQuaternionWords; /* size = 0x10 */

enum AnimationTrackSamplingConstants {
    ANIM_KEY_NOT_FOUND = -1,
    ANIM_INTERPOLATION_MIN_KEYS = 2
};

/* Transform tracks use four float components and an integer frame number. */
typedef struct AnimationTransformKey {
    /* 0x00 */ f32 components[4]; /* XYZ for scale/translation, XYZW for rotation. */
    /* 0x10 */ s32 frame;
} AnimationTransformKey; /* size = 0x14 */

enum AnimationTransformOffset {
    ANIM_SCALE_KEY_COUNT = 0x0E,
    ANIM_TRANSLATION_KEY_COUNT = 0x10,
    ANIM_ROTATION_KEY_COUNT = 0x12,
    ANIM_SCALE_KEYS = 0x1C,
    ANIM_TRANSLATION_KEYS = 0x20,
    ANIM_ROTATION_KEYS = 0x24,
    ANIM_PLAYBACK_SPEED = 0x0C,
    ANIM_PLAYBACK_FRAME = 0x4C,
    ACTOR_MESH = 0xC8,
    ACTOR_TYPE_DATA = 0xD4,
    ACTOR_TYPE_SLOT = 2,
    ACTOR_MESH_ROOT = 0x0C
};

/* Float view of the actor fields used by the frog transformation.
 * ObjectNode keeps several of these fields as integer bit patterns; this view
 * does not change that shared layout. Only the prefix through +0x2B8 is mapped. */
typedef struct ActorTransformView {
    /* 0x000 */ u8 pad000[0x20];
    /* 0x020 */ s16 originalType;
    /* 0x022 */ u8 pad022[0x12];
    /* 0x034 */ f32 positionX;
    /* 0x038 */ f32 positionY;
    /* 0x03C */ u8 pad03C[0x3C];
    /* 0x078 */ f32 pitch;
    /* 0x07C */ f32 yaw;
    /* 0x080 */ f32 roll;
    /* 0x084 */ f32 targetPitch;
    /* 0x088 */ f32 targetYaw;
    /* 0x08C */ f32 targetRoll;
    /* 0x090 */ u8 pad090[0x2C];
    /* 0x0BC */ f32 scaleX;
    /* 0x0C0 */ f32 scaleY;
    /* 0x0C4 */ f32 scaleZ;
    /* 0x0C8 */ s32 model;
    /* 0x0CC */ u8 pad0CC[8];
    /* 0x0D4 */ u8 *typeData;
    /* 0x0D8 */ u8 pad0D8[4];
    /* 0x0DC */ u8 *animation;
    /* 0x0E0 */ u8 pad0E0[0x18C];
    /* 0x26C */ s32 behaviorCounter;
    /* 0x270 */ u8 pad270[0xC];
    /* 0x27C */ s32 instanceFlags;
    /* 0x280 */ u8 pad280[0x38];
    /* 0x2B8 */ s16 transformationTimer;
} ActorTransformView; /* prefix size = 0x2BC; actor stride = 0x300 */

/* func_80195794 shrinks, swaps, then grows an actor's normal/frog model.
 * func_8019A47C runs frog hopping; func_8015CB44 unlinks render/collision data;
 * func_8019149C recursively frees a copied model tree; func_80141720 frees
 * and clears an allocation. func_80151FD0 finds an asset by its name hash
 * (func_80139CA0). func_80195CD4 rebuilds actor state for the selected type.
 * func_801B7764 emits a radial particle burst; func_8014D61C starts a colored
 * screen flash. func_801963AC / func_801964B0 release ball / player contact.
 * func_8019655C finds the actor's downward collision extent.
 *
 * D_801F00A8: model-name table; entry 58 is "nmefrog.ndo".
 * D_802996E4: shared frog model; D_802996A8: per-type model reference counts,
 * with the frog count at D_802996E2. D_801EFDE8[type][0]: normal model scale.
 * D_801F00A0 = 0.15 (frog scale); D_801EEB58 = 7 (frog height).
 * D_801E7531: level selector; level 23 has special frog behavior.
 * D_8029F46C / D_802900C8: actors contacting the ball / player.
 *
 * D_8010A2D8+4 and D_8010A300+4 hold f64 shrink factors of 0.5.
 * D_8010A2E0+4, D_8010A2F0, D_8010A2F8, D_8010A308+4 hold f64 0.001
 * (minimum scale / snap tolerance). D_8010A300 = 2 (growth divisor);
 * D_8010A2EC = 1 (restored animation frame).
 */
/* Word-index view used when freeing copied model trees. The source-file
 * UnkTreeNode has an item count, two item-pointer slots, child and sibling
 * at these offsets; integer-address accesses preserve the original aliasing. */
enum ActorModelTreeWord {
    ACTOR_MODEL_ITEM_COUNT_WORD = 0x28 / 4,
    ACTOR_MODEL_ITEMS_WORD = 0x2C / 4,
    ACTOR_MODEL_CHILD_WORD = 0x34 / 4,
    ACTOR_MODEL_SIBLING_WORD = 0x38 / 4
};

/* func_8019A47C: actor_update_frog_hopping. ActorAnimation supplies the
 * current clip and completion flag; collision +0x188 counts contacts.
 * behaviorCounter (+0x26C) counts idle cycles before the next hop.
 * func_80133998 sets/queues an animation; func_801A2944 tests a frame crossing;
 * func_8016049C accelerates forward with a horizontal speed limit;
 * func_80178134 plays positional audio; func_801496C8 wraps a radian angle
 * by at most one full turn.
 * Pool data in asm/1000.s: D_8010A7CC = 35 (croak frame, f32),
 * D_8010A7D0 = 0.5 (contact damping, f64), D_8010A7D8 = 8 (hop Y speed,
 * f32), D_8010A7DC = 1.2 (yaw increment, f64). Keep their existing types
 * and raw field accesses to preserve the compiler's aliasing behavior. */
enum FrogHopConstants {
    FROG_ANIM_TAKEOFF = 10,
    FROG_ANIM_AIRBORNE = 7,
    FROG_ANIM_LAND = 8,
    FROG_IDLE_CYCLES_OFFSET = 0x26C,
    FROG_IDLE_CYCLES = 3,
    FROG_CROAK_SOUND = 0xDA,
    FROG_HOP_SOUND = 0x68,
    FROG_SOUND_VOLUME = 50,
    FROG_CROAK_PITCH = 118,
    FROG_HOP_PITCH = 110
};

enum ActorTransformationConstants {
    ACTOR_TRANSFORMED_FROG = 0x10,
    ACTOR_TYPE_FROG = 0x3A,
    ACTOR_TRANSFORM_RETURN_FRAMES = 50,
    ACTOR_TRANSFORM_FINISH_TIMER = 1,
    ACTOR_TRANSFORM_PARTICLE_COUNT = 5,
    ACTOR_TRANSFORM_PARTICLE_TYPE = 0x13,
    ACTOR_FROG_ANIM_IDLE = 5,
    ACTOR_FROG_SPECIAL_LEVEL = 0x17,
    ACTOR_TYPE_DATA_UNK18 = 0x18
};

/* func_80191794: actor_reset. Restores spawn position, model scale, yaw and
 * the default action list; a transformed actor first regains its normal model.
 * func_80178704: stop_tracked_sound; func_80195794: actor_update_transformation;
 * func_801919F4: actor_initialize_type_state; func_80197794: actor_select_action;
 * func_8015B524: collision_ground_distance.
 * D_801EFDE8[type][0] is the scale member of a 12-byte type record.
 * D_801ED8F0 starts the 0x50-byte physics records; D_801ED934 aliases
 * their flags at +0x44. D_80109D3C is -1, the deferred-initialization yaw.
 * D_802004E0 counts frames in the current state.
 * Keep raw accesses here: ObjectNode stores some floats as integer bits. */
enum ActorResetOffset {
    ACTOR_SCALE_X = 0xBC,
    ACTOR_SCALE_Y = 0xC0,
    ACTOR_SCALE_Z = 0xC4,
    ACTOR_ACTION_UNK12C = 0x12C,
    ACTOR_RESET_UNK280 = 0x280,
    ACTOR_TRANSFORMATION_TIMER = 0x2B8,
    ACTOR_SPAWN_POSITION_X = 0x2BC,
    ACTOR_SPAWN_POSITION_Y = 0x2C0,
    ACTOR_SPAWN_POSITION_Z = 0x2C4,
    ACTOR_SECOND_SOUND_STATE = 0x2E4,
    ACTOR_PHYSICS_RECORD_SIZE = 0x50
};

/* func_8019321C: actor_begin_attack. Switches an actor from its default action
 * list (ACTOR_BEHAVIOR_CONFIG) to its attack action list.
 * D_8010A110 is "error:no attack instructions present". */
enum ActorAttackListOffset {
    ACTOR_ATTACK_ACTION_LIST = 0x1D0,
    ACTOR_ATTACK_ACTION_COUNT = 0x24E,   /* s16: entries in the attack list. */
    ACTOR_RESUME_ACTION_INDEX = 0x255    /* u8: default-list index + 1 to resume at. */
};

/* func_80194FE8: actor_update_all. func_80178760 updates positional sound;
 * func_80195224 simulates one actor; func_80148EBC returns squared XYZ distance.
 * D_801F0198 is the actor count; D_801EC7DA is draw distance; D_8028F914 is
 * camera position; D_802004E0 is the state frame counter. D_8029F46C points
 * to the ball's attachment actor. D_801ED934 aliases per-type physics flags.
 * D_80299708 / D_802997B0 alias actor type / model; D_802999B0 aliases the
 * first of two PositionalSound records in each ACTOR_INSTANCE_STRIDE slot.
 * Far actors still copy their position to non-null model reference state:
 * model +0xC -> root, root +0x28/+0x2C -> count/0x18-byte reference array,
 * reference +4 -> state, state +0xC -> position. The state's other uses
 * are not yet identified. Keep integer-address and volatile access forms.
 * The reused unsigned offset holds the root count offset or actor byte offset.
 */
enum ActorUpdateRangeConstants {
    ACTOR_ALWAYS_UPDATE = 0x200000,
    ACTOR_UPDATE_DISTANCE_SQUARED_MARGIN = 40000,
    ACTOR_TYPE9_UPDATE_WITH_SOUND = 9,
    ACTOR_SOUND_RECORD_WORDS = 7,
    ACTOR_SOUND_TO_POSITION = 0x294,
    ACTOR_SOUND_TO_CONTACT_FLAGS_WORDS = 0x13,
    ACTOR_SOUND_TO_OBJECT_FLAGS_WORDS = 0xA8,
    ACTOR_CONTACT_FRAME_BIT = 8,
    ACTOR_CLEAR_BALL_HIT_MASK = 0xFBFFFFFF,
    ACTOR_MODEL_ROOT_OFFSET = 0xC,
    ACTOR_MODEL_REFERENCE_COUNT_OFFSET = 0x28,
    ACTOR_MODEL_REFERENCES_OFFSET = 0x2C,
    ACTOR_MODEL_REFERENCE_STRIDE = 0x18,
    ACTOR_MODEL_REFERENCE_STATE_OFFSET = 4,
    ACTOR_MODEL_REFERENCE_POSITION_OFFSET = 0xC
};

/*
 * func_801971A8: spawn_stun_orbit_particles(center).
 * func_80149724: sine_with_phase(divisor, frame, phase).
 * func_801490AC: vec3_rotate_y(destination, source, radians).
 * func_801B66D4: spawn_particle(type, position, velocity, insertAfter, reuseSlot).
 * D_802004E0 counts frames in the current state; D_801ED3C4 starts zero XYZ.
 * Stun particle constants: D_801F01A0 = 2 (bob time scale),
 * D_8010A468 = 15 (orbit radius), D_8010A468 + 4 = 3.0 (f64 orbit time scale),
 * D_8010A474 = 5 (bob amplitude), D_8010A478 = -15 (opposite orbit radius).
 */
enum StunOrbitParticleConstants {
    STUN_ORBIT_PARTICLE_TYPE = 0x13
};

enum ActorUpdateConstants {
    ACTOR_STATUS_TIMER_COUNT = 3,
    ACTOR_STATUS_TIMERS_OFFSET = 0x2B4,
    ACTOR_UPDATE_DISABLED = 0x100,
    ACTOR_BALL_IMPACT_ENABLED = 0x200,
    OBJECT_HIT_BY_BALL = 0x04000000,
    ACTOR_EMBEDDED_ACTION_LIST_OFFSET = 0x4C,
    COLLISION_SECOND_SPHERE_CENTER = 0x7C,
    PLAYER_STATE_ATTACHED_TYPE29 = 0x24,
    TYPE29_ANIM_PLAYER_ATTACH = 5
};

/*
 * func_80195224 updates one actor slot, including physics, status effects and AI.
 * func_8015D020 updates object physics, collision and orientation.
 * func_801AE0CC handles a status timer expiring.
 * func_80196610 handles a qualifying ball impact (see BallImpactActorTypes).
 * func_801966D8 updates the shrinking effect; func_80195794 updates transformation.
 * func_80198C20 advances actions and dispatches the actor's type-specific behavior.
 * func_80149318 copies only X/Z; func_801971A8 emits the orbiting stun particles.
 *
 * Actor slot aliases (all have ACTOR_INSTANCE_STRIDE bytes between entries):
 * D_802996E8: slot base; D_80299708: type; D_8029970A: active state.
 * D_80299710: object flags; D_80299718: effect height offset.
 * D_8029971C/720: position / position Y; D_802997A0: spin angle.
 * D_802997BC: type data; D_802997C0: collision state.
 * D_802997CC: current action storage; D_80299938: action-list pointer.
 * D_80299964: instance flags.
 * D_8029999C/99E/9A0: stun, shrink and transformation timers.
 * D_802999B0/9CC: the two tracked positional sounds.
 * D_8029F578: saved Euler angles of the actor contacting the ball.
 *
 * Constant pool, decoded from asm/1000.s:
 * D_8010A2C0+4 = 0.05 (f64 spin threshold).
 * D_8010A2CC = 5 (ball-impact speed threshold).
 * D_8010A2D0 = 20 (type-32 stun effect height).
 * D_8010A2D4 = 40 and D_8010A2D8 = 20 (type-29 attachment height/radius).
 */

/* Actor types func_80196610 treats specially when the ball hits them. */
enum BallImpactActorTypes {
    BALL_IMPACT_ALWAYS_STUN_TYPE = 0x11,      /* stunned even without model contact */
    BALL_IMPACT_CONTACT_ONLY_TYPE = 0x13,     /* only marked when its model is touched */
    BALL_IMPACT_SUPPORT_TYPE = 0x1B,          /* marked if it carries the ball, else stunned */
    BALL_IMPACT_MARK_TYPE_1E = 0x1E,          /* always marked with a contact frame */
    BALL_IMPACT_MARK_TYPE_2B = 0x2B,
    BALL_IMPACT_FIRST_KILLED_TYPE = 0x2C,     /* this type and above die instead of being stunned */
    BALL_IMPACT_STUN_FRAMES = 100
};

enum PlayerAttachmentConstants {
    ACTOR_INSTANCE_STRIDE = 0x300,
    PLAYER_ATTACHMENT_BLEND_FRAMES = 5,
    PLAYER_ATTACHMENT_LOW_HEIGHT = 0x10
};

/*
 * func_80175EC0 positions the player from the attached actor's transform tracks.
 * func_80147704 interpolates quaternions; func_801499A0 rotates by a quaternion.
 * D_80290304: player's attached actor; D_8029030C/310/314: player position.
 * D_80290330: player velocity; D_80290354: player yaw.
 * D_8028FBEA: elapsed player-state frames.
 * D_80299964: actor instance flags, one entry every 0x300 bytes.
 * D_80108488/48C/490 = 1 (end-of-track interpolation fractions).
 * D_80108494 = 21 and D_80108498 = 4 (normal/low attachment height).
 * D_8010849C = 0.05 (f64 translation scale); D_801084A4 = -5 (Z offset).
 * D_801084A8 = 0.5 (f64 initial attachment blend).
 */

/* func_8019B078 updates type 37 (dispatcher case 30 after subtracting 7):
 * choose the nearer player/ball when the attack action starts, aim at it,
 * emit effect 6 after the attack's windup, and fade the tracked attack sound.
 * ActorAnimation supplies clip bounds and current playback frame.
 * Actor +0x2E4 contains the second PositionalSound; +0x2E8 is its volume.
 * D_8029030C/310/314 and D_8029F9AC/9B0/9B4 are player and ball XYZ.
 * func_80133998 starts/queues clips; func_80147000 returns bounded random values;
 * func_80148EBC gives squared XYZ distance; func_80147460 computes atan2;
 * func_801496C8 wraps angles by one turn; func_80178134 plays positional sound;
 * func_801785E0/func_80178704 start/stop a tracked positional sound;
 * func_801A9054 spawns an actor effect.
 * Pool doubles (asm/1000.s): D_8010A8A0+4 = pi (yaw reversal),
 * D_8010A8A8+4 = 0.4 (attack pitch offset). Preserve their split-symbol loads.
 */
/* func_8019B3DC: update type-38 facing, idle spins and action-9 hops.
 * func_80162B60 chooses a normalized random spin axis.
 * func_80147460 computes atan2; func_80148C3C converts axis/angle to quaternion;
 * func_80148000 approaches a quaternion by a bounded angular step.
 * func_80147000 returns a bounded random integer.
 * D_801ED3E0/E4/E8 = (0, 1, 0); D_801ED3EC is the shared yaw angle.
 * D_8029030C/314 are player X/Z; D_802004E0 is the state frame counter.
 * Data values verified in asm/1000.s and asm/data/D51D0.data.s:
 * D_801F01B0 = 0.96 (idle spin angle); D_801F01B4 = 0.1 (speed threshold).
 * D_8010A8B4 = 3 (triggered spin angle); D_8010A8B8/BC = 1 (Y spin axis).
 * D_8010A8C0 = 9 (hop velocity); D_8010A8C0 + 4 holds f64 0.01 (spin cutoff).
 * The target-quaternion scratch array retains its original three-element
 * declaration for matching, although the conversion helper writes four floats.
 */
/* ACTOR_FLAGS bit cleared while an actor's spin (ACTOR_SPIN_AXIS/ANGLE) is
 * running; func_8019B02C (actor_start_y_spin) clears it for any actor type. */
enum ActorSpinFlags {
    ACTOR_FLAG_NOT_SPINNING = 0x20
};

enum Type38SpinConstants {
    TYPE38_NOT_SPINNING = 0x20,
    TYPE38_ACTION9_FLAG = 0x08000000,
    TYPE38_RANDOM_SPIN_TRIGGER = 8,
    TYPE38_HOP_ACTION = 9,
    TYPE38_HOP_START_FRAME = 21,
    TYPE38_SPIN_CHANCE_RANGE = 70,
    TYPE38_TRIGGER_STUN_FRAMES = 500,
    TYPE38_HOP_STUN_FRAMES = 50,
    TYPE38_SPIN_ACTION_DELAY = 2,
    ACTOR_SPIN_AXIS_Y = 0xB0,
    ACTOR_SPIN_AXIS_Z = 0xB4
};

enum Type37AttackConstants {
    TYPE37_ANIM_ATTACK = 12,
    TYPE37_ANIM_TRANSITION = 13,
    TYPE37_ANIM_QUEUED_LOOP = 15,
    TYPE37_ANIM_ACTION2 = 5,
    TYPE37_TARGET_OFFSET = 0x26C,
    TYPE37_TARGET_PLAYER = 1,
    TYPE37_TARGET_BALL = 2,
    TYPE37_SOUND_OFFSET = 0x2E4,
    TYPE37_SOUND_VOLUME_OFFSET = 0x2E8,
    TYPE37_ATTACK_SOUND = 0x24,
    TYPE37_VOCAL_SOUND = 0x25,
    TYPE37_ATTACK_VOLUME = 80,
    TYPE37_VOCAL_VOLUME = 100,
    TYPE37_SOUND_PITCH = 128,
    TYPE37_ATTACK_WINDUP_FRAMES = 35,
    TYPE37_ATTACK_EFFECT = 6,
    TYPE37_SOUND_FADE_STEP = 5
};

/* func_80194D30: actor_attach_ball_or_player. The ball branch takes priority.
 * Vec3i_B1344 is the legacy source-local name for three f32 components
 * (x/y/z at 0/4/8, size 0xC), used for attachment offsets and Euler angles.
 * D_8029F46C / D_802900C8: ball / player attachment actor.
 * D_8029F470 / D_802900CC: ball / player attachment offset.
 * D_8029F47C / D_802900D8: model attachment index, or -1 for actor origin.
 * D_8029F578: actor Euler angles saved when attaching the ball.
 * D_8029F9A4: ball's owner; D_80290304: player's associated actor.
 * D_8029F9A0 / D_80290300: ball / player object flags.
 * D_8028FAC8 / D_8028FAD0: followed position / velocity pointers.
 * D_8029F9AC / D_8029030C: ball / player position X (XYZ follows).
 * D_8010A2BC is the double 0.1 added to ball X when releasing player ownership.
 * func_801963AC / func_801964B0 release ball / player actor attachments;
 * func_80167604 transitions the player state.
 */
enum ActorAttachmentFlags {
    ACTOR_ACTION_ATTACH_PLAYER = 0x40,
    ACTOR_ACTION_ATTACH_TO_MODEL = 0x20000,
    ACTOR_ATTACHMENT_ORIGIN = -1
};

enum ActorBallInteractionOffset {
    ACTOR_BALL_HEIGHT_OFFSET = 0x30,
    ACTOR_VELOCITY_Y = 0x5C,
    ACTOR_VELOCITY_Z = 0x60,
    ACTOR_ACTION_TYPE = 0xE4,
    ACTOR_ACTION_CONTACT_OFFSET = 0xE8,
    ACTOR_ACTION_CONTACT_INDEX = 0x100,
    ACTOR_ACTION_FLAGS = 0x10C,
    ACTOR_ATTACK_COOLDOWN = 0x26C,
    ACTOR_CONTACT_FLAGS = 0x27C,
    ACTOR_MODEL_CONTACT_COUNT = 0x188,
    BALL_PRIMARY_SPHERE_RADIUS = 0x70,
    ANIMATION_CURRENT_OFFSET = 2
};

/* func_8019A018: update type-32 animation audio and impact particles.
 * ActorAnimation supplies playback state. The second ObjectCollisionSphere
 * starts at collision +0x7C; +0x94 is its radius and +0x9E its flags.
 * Impact particles spawn at that sphere's bottom.
 * func_80147000 returns a bounded random integer; func_801490AC rotates a
 * Vec3F about Y; func_801B66D4 creates a particle; func_801B70F8 emits a
 * radial ring of type-0 particles with vertical speed and scale arguments.
 * D_802004E0 is the update counter. D_802978F4/F8/FC are three shared values
 * set to 30 during frames (10, 30); their broader purpose is not established.
 * Pool values from asm/1000.s: D_8010A79C/A7A0 = 10/30 (open frame window),
 * D_8010A7A4 = 46 (sound frame), D_8010A7A8 = 24 (impact frame),
 * D_8010A7AC = 2 (ring speed/scale), D_8010A7B0 = 5 (particle X speed).
 */
/* func_80199500: actor_type40_update_effects. Action 4 plays paired sounds;
 * action 7 emits an impact burst at frame 54 (variant 0) or 9 (variant 1).
 * The action begins at ACTOR_ACTION_TYPE; +4 selects its variant, and
 * ACTOR_ACTION_FRAME is the actor's action timer, not a clip frame.
 * ObjectCollisionSphere describes the second sphere at model state +0x7C.
 * Raw offsets retain the existing aliasing behavior.
 * func_80178134: sound_play_positional; func_80147000: bounded random integer.
 * func_801490AC: vec3_rotate_y; func_801B66D4: particle_spawn.
 * func_801B70F8: particle_spawn_radial_ring (position, count, Y speed, scale).
 * func_801B9974: shake_start_at_position; func_801A02A0: fading sprite effect.
 * Pool words verified in asm/1000.s: D_8010A728 = 2 (height above sphere
 * bottom), D_8010A72C = 5 (particle horizontal speed).
 */
enum Type40EffectConstants {
    TYPE40_ACTION_SOUND = 4,
    TYPE40_ACTION_IMPACT = 7,
    TYPE40_ACTION_VARIANT_OFFSET = 4,
    TYPE40_SOUND_FRAME_A = 18,
    TYPE40_SOUND_FRAME_B = 27,
    TYPE40_IMPACT_FRAME_A = 54,
    TYPE40_IMPACT_FRAME_B = 9,
    TYPE40_ACTION_SOUND_ID = 0x33,
    TYPE40_IMPACT_SOUND_ID = 0x32,
    TYPE40_SOUND_VOLUME = 100,
    TYPE40_RING_PARTICLE_COUNT = 6,
    TYPE40_PARTICLE_TYPE = 2,
    TYPE40_UPWARD_SPEED_RANGE = 5,
    TYPE40_UPWARD_SPEED_MIN = 10,
    TYPE40_PARTICLE_ANGLE_RANGE = 6,
    TYPE40_SHAKE_DURATION = 6,
    TYPE40_SHAKE_CYCLES = 1,
    TYPE40_SHAKE_FLAGS = 10,
    TYPE40_SPRITE_LIFETIME = 10,
    COLLISION_SECOND_SPHERE_RADIUS = 0x94
};

enum Type32EffectConstants {
    TYPE32_ANIM_RANDOM_SOUND = 15,
    TYPE32_SOUND_INTERVAL = 3,
    TYPE32_RANDOM_SOUND_CHOICES = 2,
    TYPE32_RANDOM_SOUND_A = 9,
    TYPE32_RANDOM_SOUND_B = 8,
    TYPE32_RANDOM_SOUND_VOLUME = 70,
    TYPE32_EFFECT_ACTION = 7,
    TYPE32_ACTION_UNK04 = 4,
    TYPE32_SPHERE_FLAGS_OFFSET = 0x9E,
    TYPE32_SPHERE_FLAG_8 = 8,
    TYPE32_CLEAR_SPHERE_FLAG_8 = 0xFFF7,
    TYPE32_SPHERE_RADIUS_OFFSET = 0x94,
    TYPE32_ANIMATION_SOUND = 0x7B,
    TYPE32_IMPACT_SOUND = 0xB,
    TYPE32_SOUND_VOLUME = 100,
    TYPE32_SOUND_PITCH = 128,
    TYPE32_RING_PARTICLE_COUNT = 4,
    TYPE32_PARTICLE_TYPE = 2,
    TYPE32_PARTICLE_UPWARD_SPEED_RANGE = 5,
    TYPE32_PARTICLE_UPWARD_SPEED_MIN = 10,
    TYPE32_PARTICLE_ANGLE_RANGE = 6
};

/* func_8019E538: update type-19 animation sounds, proximity and recoil.
 * The animation pointer uses ActorAnimation; byte offsets retain the legacy
 * integer-address accesses. The recoil latch reuses behaviorCounter (+0x26C).
 * func_801A2944 tests frame <= animation.frame < frame + animation.speed.
 * func_80178134 plays positional sound; func_80148E48 measures 3D distance.
 * func_80160610 adds forward velocity with a speed limit.
 * func_80160B6C adds the source yaw's velocity to a target, then limits speed.
 * func_801963AC detaches the ball; func_80197794 selects an actor action.
 * D_8029030C / D_8029F9AC start player / ball XYZ.
 * D_8029F46C is the ball attachment actor; D_8029F9D4 is ball velocity Y,
 * 23 float words after the ball object base.
 * Pool values verified in asm/1000.s: D_8010AA74/78 = 69/84 (clip 15
 * sound frames), D_8010AA7C/80 = 119/123 (clip 9 sound frames),
 * D_8010AA84 = 87 (clip 10 sound frame), D_8010AA88 = 136 (clip 4
 * sound frame), D_8010AA8C = 100 (proximity radius), D_8010AA90 = 9
 * (ball launch velocity Y).
 */
enum Type19BehaviorConstants {
    TYPE19_ANIM_SOUND_B = 4,
    TYPE19_ANIM_PROXIMITY = 5,
    TYPE19_ANIM_FLAG = 6,
    TYPE19_ANIM_BALL_CONTACT = 9,
    TYPE19_ANIM_SOUND_A = 10,
    TYPE19_ANIM_RESET_RECOIL = 15,
    TYPE19_ANIMATION_FLAG = 1,
    TYPE19_RECOIL_REQUEST = 8,
    TYPE19_RECOIL_LATCH_OFFSET = 0x26C,
    TYPE19_RECOIL_COOLDOWN = 2000,
    TYPE19_RECOIL_ACTION = 3,
    TYPE19_STEP_SOUND = 0x38,
    TYPE19_SOUND_A = 0x7F,
    TYPE19_SOUND_B = 0x80,
    TYPE19_SOUND_VOLUME = 100,
    TYPE19_SOUND_PITCH = 128,
    TYPE19_CLEAR_BALL_CONTACT_MASK = 0xFEFFFFFF,
    BALL_VELOCITY_Y_WORD_OFFSET = 23,
    ACTOR_ACTION_LIST = 0x250,
    ACTOR_ACTION_COUNTDOWN = 0x27A
};

enum Type17BallInteraction {
    TYPE17_ANIM_CAPTURE = 7,
    TYPE17_ANIM_CONTACT = 9,
    TYPE17_ANIM_DETACH = 15,
    TYPE17_SOUND_CONTACT = 0x17,
    TYPE17_SOUND_ATTACK = 0x15,
    TYPE17_SOUND_DETACH = 0x7C,
    TYPE17_SOUND_BOUNCE = 0x6D,
    TYPE17_ATTACK_EFFECT = 9,
    TYPE17_ATTACK_DELAY = 50,
    TYPE17_DETACH_DELAY = 70,
    TYPE17_SOUND_FADE_STEP = 5,
    ACTOR_BALL_CONTACT_FLAG = 0x1000000,
    ACTOR_ACTION_ATTACH_BALL = 0x80
};

/*
 * func_8019D58C updates type-17 actor ball capture, attacks and detachment.
 * func_80194D30 attaches the player or ball according to the action flags.
 * func_80197794 selects an actor action; func_801982F0 restores its default list.
 * func_80160E00 tests whether an object faces another within an angle.
 * func_80148DB0 measures X/Z distance; func_801A9054 spawns an actor effect.
 * func_8016049C adds forward velocity and limits horizontal speed.
 * func_8015C4C8 tests the player's ball-holding states.
 *
 * D_8029F470/474/478: ball contact offset; D_8029F9A8: ball radius.
 * Type-17 constants, decoded from asm/1000.s:
 * D_8010A9E8+4 = 0.8 (f64 bowling-ball damping);
 * D_8010A9F0+4 = 0.7 (f64 capture damping); D_8010A9FC = 4 (capture step).
 * D_8010AA00 = 150 (attack distance), +4 = pi (f64 reverse heading).
 * D_8010AA0C = -1 (no ground contact); D_8010AA10 = 50 (detach clearance).
 * D_8010AA14 = 8 (detach lift); D_8010AA18 = 5 (bounce velocity).
 */

enum BallPullAnimation {
    BALL_PULL_ANIM_CONTACT = 9,
    BALL_PULL_ANIM_RELEASE = 10,
    BALL_PULL_ANIM_AFTER_RELEASE = 11,
    BALL_PULL_ANIM_PULL = 12
};

/*
 * func_8019B968 updates type-27 actor ball contact, release and pull behavior.
 * func_80147000 returns a random integer below its argument.
 * func_80148D0C adds a scaled vector; func_801490AC rotates a vector about Y.
 * func_801B66D4 spawns a particle with a position and velocity.
 * func_80133998 starts or queues an object animation.
 * func_801B1344 clears the ball's contact and velocity, with a contact delay.
 * func_8018C700 applies a player/ball power-up; id 12 selects ball form 6.
 * func_801785E0 starts a tracked positional sound.
 * func_80147460 computes an X/Z heading; func_80160228 approaches a target angle.
 * func_801B10B8 sets a ball's rolling axis and speed.
 * func_80167604 changes player state; func_80197794 selects an actor action.
 *
 * D_802004E0: update counter.
 * D_8029F46C: actor currently contacting the ball; D_8029F487: ball form.
 * D_8029F9A0: ball object flags; D_8029F9A4: ball's supporting object.
 * D_8029F9AC/B0/B4: ball position X/Y/Z; D_8029F9D0/D4/D8: velocity X/Y/Z.
 * D_802902D8: player object; D_802901CC: timer for power-up 12.
 *
 * Type-27 constant pool (verified in asm/1000.s):
 * D_8010A8E0 = 8 (particle Y offset); D_8010A8E4 = 3 (particle Y velocity).
 * D_8010A8E8 = 28 and D_8010A8EC = -2 (local ball release velocity Y/Z).
 * D_8010A8F0 = 0.5 (f64 horizontal damping); D_8010A8F8 = 1 (unit length).
 * D_8010A8F8+4 = 10 and D_8010A900+4 = 1 (f64 pull ramp divisor/base).
 * D_8010A90C = 3 (pull ramp limit); D_8010A910 = 6 (rolling ramp divisor).
 * D_8010A914 = 1 (rolling ramp base); D_8010A918 = 12 (capture distance).
 */

/*
 * Camera collision response (func_80164428): weighted contact normals either
 * stop camera motion or push the camera away from walls.
 * D_8028F9B8 points to collision state: the first four words are contact-normal
 * pointers (Vec3F *); the first ObjectCollisionSphere radius is at +0x70.
 * D_8028FB50..D_8028FB5C hold the corresponding contact distances, addressed
 * relative to D_8028FB60. D_8028FB60/64 are the smoothed/target reduction of
 * camera follow distance; D_8028F9C8 is the desired follow distance.
 * D_8028F914/918/91C: camera position; D_8028F938/93C/940: camera motion.
 * D_8028FA00/04/08: camera focus position; D_8029030C/310/314: player position.
 *
 * func_80147460 is table-based atan2(y, x); func_801496C8 wraps radians by
 * at most one turn; func_8014944C returns the shortest angular distance.
 * Pool constants: D_80107678 = 8 (offset smoothing divisor),
 * D_8010767C = 2 (radius divisor and contact-weight base),
 * D_80107680 = 2*pi/3 and D_80107688 = pi/2 (stop angle thresholds),
 * D_80107690 = 120 (maximum distance reduction), D_80107690+4 = pi/2
 * (f64 correction-angle threshold, spanning D_80107698),
 * D_8010769C/A0 = 1 (normal averaging scales), D_801076A4 = 6 (push strength).
 */
enum CameraCollisionConstants {
    CAMERA_COLLISION_MAX_CONTACTS = 4,
    CAMERA_COLLISION_RADIUS_OFFSET = 0x70
};

/* Collision spheres are stored from +0x58 in an object's collision state. */
typedef struct ObjectCollisionSphere {
    /* 0x00 */ f32 center[3];
    /* 0x0C */ u8 unk00C[0x0C];
    /* 0x18 */ f32 radius;
    /* 0x1C */ f32 targetRadius;
    /* 0x20 */ u16 unk020;
    /* 0x22 */ u16 flags;
} ObjectCollisionSphere; /* size = 0x24 */

/* func_8015C1D4: collision_update_sphere_centers.
 * D_801ED6EC holds world centers; D_801ED68C holds world-space offsets
 * from the object's position. Both scratch arrays start zeroed in ROM.
 * func_801499A0 rotates a vector by a quaternion, converting it to axis-angle
 * with func_801489F0 and rotating with func_801499EC.
 * A sphere center is local unless WORLD_CENTER is set; AT_OBJECT_ORIGIN
 * takes precedence and ignores the stored center. BallCollisionState names
 * the count and initial sphere slots. Byte accesses preserve legacy aliasing.
 * Symbol renaming is currently unsupported for Nintendo 64 projects. */
enum CollisionSphereCenterFlags {
    COLLISION_SPHERE_WORLD_CENTER = 0x10,
    COLLISION_SPHERE_AT_OBJECT_ORIGIN = 0x20
};

enum CollisionSphereTransformOffsets {
    COLLISION_OBJECT_POSITION_X = 0x34,
    COLLISION_OBJECT_POSITION_Y = 0x38,
    COLLISION_OBJECT_POSITION_Z = 0x3C,
    COLLISION_OBJECT_QUATERNION = 0x9C,
    COLLISION_OBJECT_STATE = 0xD8,
    COLLISION_SPHERES_START = 0x58
};

/* func_8015C924: collision_update_bounding_radius. Each sphere contributes
 * its radius plus its center's distance from the object origin. World-space
 * centers first subtract the object position; other centers are offsets.
 * These byte offsets preserve the legacy ObjectNode access types. */
enum CollisionBoundingRadiusOffsets {
    COLLISION_OBJECT_BOUNDING_RADIUS = 0x30,
    COLLISION_FIRST_CENTER_Y = 0x5C,
    COLLISION_FIRST_CENTER_Z = 0x60,
    COLLISION_FIRST_RADIUS = 0x70,
    COLLISION_SPHERE_STRIDE = 0x24
};

/* func_80162D18: camera_reset_follow; func_801364D0: camera_resume_follow.
 * D_8028F8E0 is the camera object; D_8028FAD0 points to the followed
 * object's velocity (reset to player velocity XYZ at D_80290330).
 * D_8028F9C8 is desired follow distance; D_8028FB3C is maximum focus step.
 * D_8028FB6C selects following (0 disabled, 1 normal, 2 scripted).
 * Reset pool, verified in asm/1000.s: D_801074D8 = 40 (collision radius),
 * DC = 0.2666666806 (response), E0 = -1 (physics unk20),
 * E4 = 0.8000000119 (physics unk1C), E8/EC = 200/20 (speed limits),
 * F0 = 0.05000000075 (angular step), F4 = 2 (focus step), F8 = 250 (distance).
 * Level 0x28 uses the larger speed limit; unidentified flags stay unnamed.
 */
typedef struct CameraFollowObject {
    /* 0x00 */ u8 unk00[0x70];
    /* 0x70 */ f32 response;
    /* 0x74 */ u8 unk74[0xD0 - 0x74];
    /* 0xD0 */ u8 *physics;
    /* 0xD4 */ u8 unkD4[4];
    /* 0xD8 */ u8 *collision;
} CameraFollowObject; /* size = 0xDC; accessed prefix */

/* func_80162BE0: camera_init. func_8013FBC0 clears bytes and func_80142700
 * initializes object components. D_8028F8E0 is the eye object and
 * D_8028F9CC is the focus object; D_8028F900 is the eye object's type.
 * D_8028FA00/04/08 are focus XYZ, D_8028FA3C is focus response,
 * D_8028FA9C holds the focus physics pointer, and D_8028FAC8 follows
 * player position D_8029030C. D_801EEB70/74 are configured vertical
 * offset/base distance; D_801EEB78 selects the D_801EEB7C distance scale.
 * D_8028FB28/24 hold the resulting vertical offset/distance.
 * Symbol renaming is unsupported for N64; retain the address names.
 * Float and pointer indices retain the original aggregate accesses. */
enum CameraInitIndices {
    CAMERA_FOCUS_PHYSICS_SPEED_INDEX = 2,
    CAMERA_FOCUS_PHYSICS_RESPONSE_INDEX = 6,
    CAMERA_FOCUS_PHYSICS_UNK1C_INDEX = 7,
    CAMERA_FOCUS_RESPONSE_FROM_POSITION_INDEX = 15,
    CAMERA_FOLLOW_POSITION_FROM_FOCUS_INDEX = 63
};

enum CameraResetOffset {
    CAMERA_COLLISION_TARGET_RADIUS = 0x74,
    CAMERA_PHYSICS_UNK1C = 0x1C,
    CAMERA_PHYSICS_UNK20 = 0x20
};

/* Camera motion fields used when switching between look and follow modes. */
typedef struct CameraMotionState {
    /* 0x00 */ u8 unk000[0x25];
    /* 0x25 */ u8 mode;
    /* 0x26 */ u8 unk026[2];
    /* 0x28 */ f32 blendRate;
} CameraMotionState; /* size = 0x2C; accessed prefix */

typedef struct CameraCollisionState {
    /* 0x00 */ u8 unk000[0x58];
    /* 0x58 */ ObjectCollisionSphere sphere;
} CameraCollisionState; /* size = 0x7C; accessed prefix */

/* func_80162EAC: camera_set_position_and_target.
 * Saves the old camera state, sets eye XYZ and followed position/velocity,
 * and clears camera motion. The third argument carries the Z float's bits.
 * D_8028F914/918/91C: eye XYZ; D_8028FB08: saved eye (Vec3Words).
 * D_8028F938/93C/940: camera motion XYZ.
 * D_8028FAC8/FAD0: followed position/velocity pointers.
 * D_8028FACC/FAD4: saved followed position/velocity pointers.
 * D_8028FA00: focus XYZ; D_8028FAD8: saved focus XYZ (Vec3Words).
 * D_8028FAB4/FAB8: current/saved target height.
 * D_8028FAF8/FAE4: current/saved camera handoff state.
 * D_8028FAF4: camera transition parameter; D_8028FB94: transition flags.
 * func_80173CE8 extends the gameplay timer D_8028FBF4 to at least the
 * requested duration. Level 43 skips this timer update and the flags store.
 * Symbol renaming is currently unsupported for this N64 project.
 */
enum CameraTargetSwitchConstants {
    CAMERA_TARGET_SWITCH_TIMER_PADDING = 10,
    CAMERA_TARGET_SWITCH_SPECIAL_LEVEL = 0x2B
};

/* func_8013640C: camera_enter_look_mode (the opposite of func_801364D0).
 * D_80105964 = 0.002 (look-mode D_801F1A94 setting); D_80105968 = 5 (look
 * collision radius). D_8028F968 and D_801FAA1C receive the current yaw. */
enum CameraFollowMode {
    CAMERA_MOTION_FOLLOW = 0,
    CAMERA_MOTION_LOOK = 1,
    CAMERA_CONTROL_LOOK = 0,
    CAMERA_CONTROL_NORMAL = 1,
    CAMERA_FOLLOW_DISABLED = 0
};

/*
 * func_8012BD44: level43_update_player_ball_scene.
 * func_80167604 enters a player action; func_801B7764 emits radial particles;
 * func_8018C700 applies a power-up (-1 clears ball-form effects), and
 * func_80149318 copies only X/Z from one position to another.
 * D_802903AC: player action block; D_8028FBEA: frames in that action.
 * D_8029030C/310/314 and D_8029F9AC/B0/B4: player and ball XYZ.
 * D_8029F9A0: ball object flags; D_8029FA50: BallCollisionState.
 * D_802004E0: scene frame counter; D_8028F914: camera position.
 * D_80101940+4: f64 ball placement Y offset; D_8010194C and D_80101950:
 * target collision radii after clearing forms and selecting bowling form.
 * Keep the unidentified D_8028FB7C / D_801EFCFC flags and action IDs unnamed.
 */
enum Level43BallSceneConstants {
    LEVEL43_BALL_PLACEMENT_ACTION_FRAME = 8,
    LEVEL43_BALL_RESTORE_ACTION_FRAME = 10,
    LEVEL43_BOWLING_SCENE_FRAME = 100,
    LEVEL43_PLAYER_ALIGN_SCENE_FRAME = 199,
    LEVEL43_PLAYER_BURST_COUNT = 6,
    LEVEL43_BALL_BURST_COUNT = 8,
    LEVEL43_PLAYER_PARTICLE_TYPE = 0x13,
    LEVEL43_BALL_PARTICLE_TYPE = 0x15,
    LEVEL43_BOWLING_POWERUP = 7,
    LEVEL43_CLEAR_BALL_POWERUPS = -1,
    LEVEL43_POWERUP_INDEFINITE = -1,
    LEVEL43_PLAYER_POSITION_BEFORE_STATE_POINTER = 0xA0
};

/* func_8014915C: vec3_rotate_axis(destination, source, radians, axis).
 * Axis must be X, Y or Z. The selected component is preserved; the other
 * two are rotated in cyclic order. A temporary allows in-place rotation.
 * func_801C4040 computes cosine; func_801C6000 computes sine.
 * The K&R s8 parameter preserves the existing promoted s32 prototype. */
/* func_801C4040: libultra cosf(radians). Reduce |x| around an odd multiple
 * of pi/2, approximate sine, then apply the sign from the half-turn index.
 * Constants decoded from the original pool in asm/1000.s:
 * D_8010C218/C220/C228/C230: sine polynomial coefficients for x^3/x^5/x^7/x^9
 * (-0.16666659550427756, 0.008333066246082155,
 *  -0.0001980960290193795, 0.000002605780637968037).
 * D_8010C238: 1/pi; D_8010C240: pi high (3.1415926218032837);
 * D_8010C248: pi low (3.178650954705639e-8).
 * D_8010C258: rounding half (0.5); D_8010C260: phase half (0.5).
 * D_8010C270: NaN result (f32 bits 0x7F810000).
 * D_8010C250: zero returned for non-NaN inputs with |x| >= 2^28.
 * The range key contains the biased exponent and the top fraction bit. */
enum CosineFloatRange {
    COSINE_RANGE_KEY_SHIFT = 22,
    COSINE_RANGE_KEY_MASK = 0x1FF,
    COSINE_RANGE_LIMIT_2_POW_28 = 0x136
};

enum Vec3RotationAxis {
    VEC3_AXIS_X = 0,
    VEC3_AXIS_Y = 1,
    VEC3_AXIS_Z = 2
};

/*
 * func_801364D0: camera_resume_follow.
 * func_8014915C rotates about the selected axis; func_801490AC rotates about Y.
 * D_8028F9B0: CameraMotionState pointer; D_8028F9B8: collision-state pointer.
 * D_8028F958/95C: camera pitch/yaw; D_8028FB6C: follow enabled.
 * D_801EC788: focus reset distance (100); D_801EEB84 supplies its scale,
 * clamped to [0.5, 1]. D_8028FB3C: maximum focus movement per update;
 * D_8028FB44: smoothed sideways focus offset.
 * Pool words verified in asm/1000.s: D_80105968 is radius 5 for look mode;
 * the f64 values at D_80105968+4, D_80105970+4, D_80105978+4 and
 * D_80105980+4 are 0.5, 1, 0.5 and 0.5 respectively.
 * D_8010598C: follow blend rate 0.05; D_80105990: initial focus step 1;
 * D_80105994: restored D_801F1A94 setting 0.003;
 * D_80105998: follow collision radius 40.
 */

typedef struct BallCollisionState {
    /* 0x000 */ u8 unk000[0x58];
    /* 0x058 */ ObjectCollisionSphere spheres[4];
    /* 0x0E8 */ u8 unk0E8[0xA3];
    /* 0x18B */ u8 sphereCount;
} BallCollisionState; /* size = 0x18C; accessed prefix */

/* Aggregate view retains the original pointer-load aliasing behavior. */
typedef struct ObjectDataPointer {
    /* 0x00 */ u8 *data;
} ObjectDataPointer; /* size = 0x04 */

/* func_801B39DC (ball_blend_palettes) fills palette banks 1..15 with
 * blends of the destination's base colors and the source's first 15 colors.
 * D_8029F440 holds texture headers indexed by BallTextureIndex; their
 * Texture80154300.palette field points to RGBA5551 colors.
 * D_8010BA98 is f64 0.99 (copy threshold), D_8010BAA0 is f32 2
 * (copy upper limit), and D_8010BAA4 is f32 1 (total blend weight).
 * Weights from 0.99 through 2 copy the base bank; weights above 2 do nothing.
 */
enum BallPaletteConstants {
    BALL_PALETTE_BANK_SIZE = 16,
    BALL_PALETTE_BANK_COUNT = 16,
    BALL_TEXTURE_PALETTE_OFFSET = 0x20
};

enum BallTextureIndex {
    BALL_TEXTURE_NORMAL = 0,
    BALL_TEXTURE_BOWLING = 1,
    BALL_TEXTURE_POWER = 2,
    BALL_TEXTURE_BEARING = 3,
    BALL_TEXTURE_BEACH = 4,
    BALL_TEXTURE_SNOW = 5,
    BALL_TEXTURE_CBALL = 6
};

/* func_801B0DDC (ball_begin_damage) cancels ball enlargement and selects
 * form-specific destruction, or starts the normal damage/recovery sequence.
 * D_8029F486 is ball status; D_8029F487 indexes BallTextureIndex and the
 * 0x50-byte form records. D_8029F5C4 tracks enlargement; D_8029F5CA is the
 * damage cooldown. D_8029FA50 points to ball collision state (radius +70).
 * D_801ED938 supplies each form's radius; D_8029F9D4 is ball velocity Y.
 * D_8029F9A0 is ball flags; XYZ follows at +0C. D_80290330/334/338 are
 * player velocity XYZ. D_8029014C and D_8029F5A8 are sound emitters.
 * D_8010B848+4/+C/+14 hold f64 0.7/0.5/0.4: enlargement tolerance,
 * upward impulse, and player velocity multiplier (verified in asm/1000.s).
 * func_801B362C emits radial debris; func_8018D39C cancels a power-up;
 * func_801B3408 handles destruction for forms 6/1/3; func_801B101C
 * detaches the ball and starts recovery timers. func_80167604 enters a
 * player action; func_80178134 plays a positional sound and func_801785E0
 * replaces a tracked sound. Global declarations retain their original types.
 */
enum BallDamageConstants {
    BALL_DAMAGE_ENLARGEMENT_POWERUP = 11,
    BALL_DAMAGE_DEBRIS_COUNT = 8,
    BALL_DAMAGE_RECOVERY_FRAMES = 60,
    BALL_DAMAGE_PLAYER_ACTION = 42,
    BALL_DAMAGE_RADIUS_OFFSET = 0x70,
    BALL_FORM_FLOAT_STRIDE = 20,
    BALL_DAMAGE_RADIUS_TOLERANCE_POOL = 4,
    BALL_DAMAGE_UPWARD_IMPULSE_POOL = 0xC,
    BALL_DAMAGE_VELOCITY_SCALE_POOL = 0x14,
    BALL_DAMAGE_POSITION_FROM_FLAGS = 0xC,
    BALL_DAMAGE_SOUND_FROM_COOLDOWN = 0x22,
    BALL_DAMAGE_BURST_SOUND = 0x8B,
    BALL_DAMAGE_PLAYER_SOUND = 0x114,
    BALL_DAMAGE_TRAILING_SOUND = 0x5B,
    BALL_DAMAGE_SOUND_VOLUME = 100
};

/*
 * func_801AEC14: ball_apply_damage. D_8029F5C9 counts active damage
 * overlays; D_8029F5CB is the level's damage limit (2, 3 or 4).
 * D_8029F5D8 holds the overlay objects at BALL_EFFECT_SLOT_STRIDE.
 * func_801B3EF4 shrinks the enlarged ball, emitting debris first when
 * its radius exceeds the normal radius. Its arguments are debris scale,
 * target-radius decrement and current-radius decrement.
 * D_8010B664 is f64 0.7 (enlargement tolerance); D_8010B66C/B674 are
 * f32 1 (debris scale); D_8010B670/B678 are f32 3 (target-radius decrement),
 * decoded from asm/1000.s. The current-radius decrement is 1.5f.
 * func_8015C840 activates an object in the scene lists. func_8015C4C8
 * tests whether the player is holding the ball in a supported action;
 * func_80167604(9) makes the player release it with a reaction.
 */
enum BallHitConstants {
    BALL_HIT_RELEASE_PLAYER_ACTION = 9,
    BALL_HIT_SOUND_FROM_FORM = 0x121,
    BALL_HIT_SOUND_PITCH = 0xA0
};

enum BallInitConstants {
    BALL_EFFECT_SLOT_COUNT = 4,
    BALL_EFFECT_SLOT_STRIDE = 0xE4,
    BALL_INITIAL_OBJECT_FLAGS = 0x60493D
};

/*
 * func_801AE510 initializes ball effects, textures, physics and collision spheres.
 * func_8015CB44 removes an object from active lists and detaches its mesh children.
 * func_80149568 normalizes a 3D vector (leaving an axis-angle's fourth value).
 * func_801D2150 is sprintf; func_80139CA0 hashes an asset name with CRC.
 * func_8014FCF8 finds an asset by hash; func_8015C924 updates a bounding radius.
 * D_8029F440: ball texture assets, indexed by BallTextureIndex.
 * D_8010B594/B5A4/B5B0/B5BC/B5C8/B5D4/B5E0: "newball2.bmp",
 * "bowling.bmp", "power.bmp", "beach.bmp", "bearing.bmp", "snow2.bmp",
 * "cball.bmp", respectively (decoded from asm/1000.s).
 * D_8029F5D8: four effect objects, stride 0xE4; D_8029F684: first orientation.
 * D_8029F768/B/C/774, D_8029F84C/850/854/858 and D_8029F930/934/938/93C
 * are the remaining three orientations (x/y/z/w).
 * D_8010B5EC through D_8010B620: their initial quaternion components.
 * D_8029FA48: ball physics parameters; D_801ED8F0: normal ball parameters.
 * D_8029FA50: ball collision state; D_8029FA44: ball ground-contact state.
 * D_80297998/97A7C/97B60: saved centers for the three auxiliary spheres.
 * D_8010B620+4 = 9 and D_8010B628+4 = 0.05 (f64 ball-radius scaling).
 * D_8010B634 = -2; B638 = 10; B63C = 7.5; B640 = 4; B644 = 5.6;
 * B648 = 3; B64C = 5.7; B650 = -5.5; B654 = 6.5 (sphere setup).
 * D_8010B658 = 0.85 (f64 ground-contact radius scale); B660 = -1.
 */



/* Float view preserves aggregate access to an individual object scale field. */
typedef struct ObjectScaleField {
    /* 0x00 */ f32 value;
} ObjectScaleField; /* size = 0x04 */

/*
 * func_80176AFC: player_restore_from_frog.
 * D_80108510 is "goodglov.ndo" (decoded from asm/1000.s).
 * D_80290394/398/39C are the player's XYZ model scales.
 * D_8029020C is the active type-29 capture effect; its +0x2C expiry timer
 * is set to one before releasing the tracked pointer.
 * D_8029970A is the first actor's active state at +0x22; instance flags
 * at +0x27C are 0x25A bytes beyond it. Capture uses state 10 and bit 0x400.
 * D_80297BEC bit 0x100000 is cleared when restoring normal player form.
 *
 * func_8015CB44 / func_8015C840 unlink / activate object and mesh lists.
 * func_80191548 releases an actor model instance and its type reference.
 * func_80151FD0 finds a required model by the CRC from func_80139CA0.
 * func_801758D0 initializes player physics; func_80133900 resets animation.
 * func_8017797C selects the default player action, or falling if airborne.
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */
enum PlayerFrogRestoreConstants {
    PLAYER_FROG_OPTION_CLEAR_MASK = 0xFFEFFFFF,
    ACTOR_CAPTURE_FLAG_CLEAR_MASK = 0xFFFFFBFF,
    ACTOR_CAPTURED_STATE = 10,
    ACTOR_STATE_TO_INSTANCE_FLAGS = 0x25A
};

enum PlayerFrogTransformConstants {
    PLAYER_FROG_STATE = 0x25,
    PLAYER_FROG_FLASH_GREEN = 200,
    PLAYER_FROG_FLASH_ALPHA = 250,
    PLAYER_FROG_FLASH_ALPHA_STEP = -30
};

enum PlayerFrogTransformOffset {
    PLAYER_OBJECT_RESPONSE_OFFSET = 0x70,
    PLAYER_OBJECT_PITCH_OFFSET = 0x78,
    PLAYER_OBJECT_ROLL_OFFSET = 0x80,
    PLAYER_OBJECT_TARGET_PITCH_OFFSET = 0x84,
    PLAYER_OBJECT_TARGET_ROLL_OFFSET = 0x8C,
    PLAYER_OBJECT_SCALE_X_OFFSET = 0xBC,
    PLAYER_OBJECT_SCALE_Y_OFFSET = 0xC0,
    PLAYER_OBJECT_SCALE_Z_OFFSET = 0xC4,
    PLAYER_PHYSICS_FLAGS_OFFSET = 0x44,
    PLAYER_PHYSICS_RADIUS_OFFSET = 0x48,
    PLAYER_ACTION_UNK18_OFFSET = 0x18
};

/*
 * func_80176758: player_update_frog_transformation.
 * func_80176AFC: restore the normal player model and physics after frog form.
 * func_80191284: acquire a model instance, copying its tree if already in use.
 * func_80133900: reset object animation from the model's animation template.
 * func_8015C840 / func_8015CB44: activate / unlink object and mesh list entries.
 * func_80167604: enter a player action state; state 37 starts frog idle.
 * func_8014D61C: start a screen flash with RGB, alpha and alpha step.
 *
 * D_8029011C: transformation timer; below 50 restores normal form.
 * D_8029011E: player is in frog form.
 * D_802902D8: player object; D_80290300: its flags.
 * D_80290394/398/39C: player scale X/Y/Z.
 * D_802903A0/A4/A8/AC/B0: model, ground contact, physics, action, collision.
 * D_802996E4: shared frog model; D_801EEB10: frog physics defaults (0x50 bytes).
 * The defaults have flags 0x11D at +0x44 and radius 7 at +0x48.
 * D_8028FBCC: saved default object response factor.
 * D_8028FBD8: player action countdown, cleared on entering frog form.
 *
 * Transformation constant pool, decoded from asm/1000.s:
 * D_801084C0+4 and D_801084F8+4: f64 shrink factor 0.5.
 * D_801084C8+4, D_801084D0+4, D_80108500+4: f64 scale tolerance 0.001.
 * D_801084DC: f32 growth divisor 2; D_801F00A0: f32 frog scale 0.15.
 * D_801084E0/E8/F0: f64 normal-scale threshold 0.049, target 0.05, divisor 2.
 * D_801084F8: f32 normal scale 0.05; D_8010850C: f32 contact radius 8.
 */

/* Object physics blocks are copied as 20 words, without float conversion. */
typedef Blk50 ObjectPhysicsWords;

enum PlayerInitConstants {
    PLAYER_PHYSICS_SIZE = 0x50,
    PLAYER_EFFECT_STATE_SIZE = 0x5AC,
    PLAYER_EFFECT_OBJECT_SIZE = 0xE4,
    PLAYER_EFFECT_PHYSICS = 1,
    PLAYER_EFFECT_PHYSICS_AND_COLLISION = 3,
    PLAYER_NORMAL_OBJECT_FLAGS = 0x40091D,
    PLAYER_ROBOT_OBJECT_FLAGS = 0x4000,
    PLAYER_ROBOT_LEVEL = 0x28,
    PLAYER_ROBOT_INITIAL_STATE = 0x29,
    PLAYER_ROBOT_MODE = 5,
    PLAYER_ROBOT_SPHERE_FLAGS = 0x1F,
    PLAYER_ROBOT_LIGHT_FLAG = 0x40,
    PLAYER_INITIAL_ACTION = 0xF
};

/* D_801EEC44 is a u8 [PLAYER_ACTION_COUNT][PLAYER_ACTION_COUNT] table: nonzero at
 * [current][next] when the player may change from action state `current` to `next`. */
enum PlayerActionTransitionConstants {
    PLAYER_ACTION_COUNT = 0x2D
};

enum PlayerInitOffsets {
    PLAYER_EFFECT_STATE_TO_HANDLES = 0x568,
    PLAYER_FIRST_EFFECT_TO_HANDLES = 0x538,
    PLAYER_SECOND_EFFECT_TO_HANDLES = 0x454,
    PLAYER_STATE_CURRENT_OFFSET = 4,
    PLAYER_STATE_PREVIOUS_OFFSET = 6,
    PLAYER_CONTACT_RADIUS_OFFSET = 8,
    PLAYER_MODEL_ROOT_OFFSET = 0xC,
    PLAYER_MODEL_FLAGS_OFFSET = 0x32,
    PLAYER_MODEL_ATTACHMENT_OFFSET = 0x3C,
    PLAYER_COLLISION_RADIUS_OFFSET = 0x70,
    PLAYER_COLLISION_TARGET_RADIUS_OFFSET = 0x74,
    PLAYER_ROBOT_RIGHT_FOOT_SPHERE_OFFSET = 0x7C,
    PLAYER_ROBOT_LEFT_FOOT_SPHERE_OFFSET = 0xA0,
    PLAYER_ROBOT_SAC_SPHERE_OFFSET = 0xC4,
    PLAYER_ROBOT_HEAD_SPHERE_OFFSET = 0xE8,
    PLAYER_ROBOT_RIGHT_FOOT_FLAGS_OFFSET = 0x9E,
    PLAYER_ROBOT_LEFT_FOOT_FLAGS_OFFSET = 0xC2,
    PLAYER_ROBOT_SAC_FLAGS_OFFSET = 0xE6,
    PLAYER_ROBOT_HEAD_FLAGS_OFFSET = 0x10A,
    PLAYER_QUATERNION_TO_EULER = 0x24
};

/*
 * func_801758D0 initializes player physics and orientation; a nonzero argument
 * also resets effect objects and configures the robot in level 0x28.
 * func_8013FBC0 clears bytes; func_80142700 initializes object components
 * selected by flags; func_80152220 searches a model tree by its asset hash;
 * func_8015C350 converts Euler angles to a quaternion.
 *
 * D_802903A0/A4/A8/AC/B0: player model, ground-contact, physics, action and
 * collision components. D_80290374 is the player quaternion; D_801EEBD8 is
 * another quaternion reset from identity. D_801EE4D0 holds robot physics.
 * D_8028FBB8[0/1] receive white.bmp / whitered.bmp (D_801083D0/DC).
 * D_801083EC/F8, D_80108404/410/41C name bot_foot_R, bot_foot_L,
 * bot_sac01, bot_hed_UFO and bot_hed_light, respectively.
 *
 * Default physics constants D_80108430/434/438 = 1/0.8/10;
 * D_80108464/468/46C/470/474/478 = 0.6/14/7/0.8/0.1/0.5.
 * D_8010842C = 0.6 (object response); D_8010843C/440 = 0.025/0.05
 * (level-dependent scale), D_80108444/44C = 13/0.05 (f64 radius scaling),
 * D_80108454 = 0.65 (f64 ground-contact radius factor);
 * D_8010845C/460 = 10/-1. Robot overrides D_8010847C/480/484 = 180/999999/0.92.
 */

/* Precipitation state begins at D_802AAFD8; declarations retain their original
 * types. D_801F2180 cycles the next particle through three depth layers.
 * D_8010BF28/BF30 are f64 velocity factors 0.75/0.5.
 * func_801BB1DC updates precipitation; func_801BB554 configures it.
 * func_80147000 returns a bounded random integer; func_8014E9F4 spawns a
 * screen particle; func_8014D61C sets the screen transition color/extent/step;
 * func_801793DC starts a sound with volume, pan and pitch/speed controls.
 */
typedef struct PrecipitationState {
    /* 0x00 */ s16 spawnRate;           /* D_802AAFD8 */
    /* 0x02 */ s16 particlesPerBatch;   /* D_802AAFDA */
    /* 0x04 */ s16 remainingFrames;     /* D_802AAFDC: negative runs indefinitely */
    /* 0x06 */ s16 particleType;        /* D_802AAFDE: 2 rain, 3 snow */
    /* 0x08 */ s32 spawnAccumulator;    /* D_802AAFE0 */
    /* 0x0C */ u8 layerOpacity[3];      /* D_802AAFE4..6 */
    /* 0x0F */ u8 lightningTicks;       /* D_802AAFE7: ticks every other frame */
    /* 0x10 */ s8 velocityX;            /* D_802AAFE8 */
    /* 0x11 */ s8 velocityY;            /* D_802AAFE9 */
    /* 0x12 */ s8 lifetime;             /* D_802AAFEA */
    /* 0x13 */ u8 pad13;
} PrecipitationState; /* size = 0x14 */

/* Distances backward from velocityX preserve the original raw pointer accesses. */
enum PrecipitationOffsets {
    PRECIP_BATCH_COUNT_BACK = 0xE,
    PRECIP_PARTICLE_TYPE_BACK = 0xA,
    PRECIP_ACCUMULATOR_BACK = 8,
    PRECIP_NEAR_OPACITY_BACK = 4,
    PRECIP_MIDDLE_OPACITY_BACK = 3,
    PRECIP_FAR_OPACITY_BACK = 2,
    PRECIP_VELOCITY_Y_OFFSET = 1,
    PRECIP_LIFETIME_OFFSET = 2,
    PRECIP_VELOCITY_FROM_ACCUMULATOR = 8
};

enum PrecipitationConstants {
    PRECIP_RAIN = 2,
    PRECIP_SPAWN_THRESHOLD = 64,
    PRECIP_SPAWN_WIDTH = 350,
    PRECIP_LAYER_COUNT = 3,
    PRECIP_NEAR_LAYER = 0,
    PRECIP_MIDDLE_LAYER = 1,
    PRECIP_FAR_LAYER = 2,
    PRECIP_NEAR_SCALE = 1024,
    PRECIP_MIDDLE_SCALE = 768,
    PRECIP_FAR_SCALE = 512,
    PRECIP_THUNDER_SOUND = 0xF8,
    PRECIP_LIGHTNING_CHANCE_RANGE = 2000,
    PRECIP_LIGHTNING_CHANCE_COUNT = 5
};

/* drawScreenSpritesAndHud (func_8014AD0C) uses D_80202240 as the display-list
 * write pointer. D_801ED4A8 and D_801ED430 are setup display lists.
 * D_8028DA34 is the sprite count, immediately after the 0x74-byte sentinel;
 * D_801EC7D9 enables the sprite pass. ObjectNode is used as a layout view:
 * next is the sprite link and unk06C is the sprite draw-enable word.
 * func_8014B110 draws one sprite; func_8014D66C updates and draws the HUD.
 * D_801ED62C/630/634 are text objects created by func_801469E4, with alpha
 * at +0x5B. In play state on level 0x2C, their alpha pulses with frame
 * offsets 0, 5 and 10. func_80149724 computes sin((phase + frame) / divisor).
 * The six pool entries for each pulse supply frame divisor, sine divisor,
 * sine bias, amplitude, alpha bias and the unsigned-conversion threshold:
 * D_80106478..D_8010648C, D_80106490..D_801064A4, D_801064A8..D_801064BC.
 * Symbol names remain unchanged because N64 renames are unsupported. */
/* func_8014A760 (buildScreenSpriteTiles) partitions a 16-bit image into
 * 32-pixel-wide bitmaps. The image (Unk8014A460Sub) has u16 width/height
 * at +0x0C/+0x0E and a pixel pointer at +0x1C. Obj8014A460 owns the
 * bitmap allocation at +0x24 and embeds a libultra Sprite at +0x28.
 * Each 0x10-byte bitmap has u16 width, image stride, S offset, T offset,
 * a pixel pointer, u16 actual height and u16 row-end padding.
 * Raw offsets retain the matched code's pointer-access semantics. */
/* func_8014B110: drawScreenSprite advances an optional image sequence and
 * draws a centered, scaled sprite if the active display-list buffer has room.
 * Obj8014A460 fields: unk08=image, unk0C/10=center X/Y, unk16=frame index,
 * unk18/1C=X/Y scale in units of 1/1024, unk20..23=RGBA,
 * unk50=bitmap count, unk5C=bitmap array, unk70=animation table address.
 * Unk8014B110Tbl has image pointers at +0 and an s16 frame count at +4.
 * Unk8014A460Sub has width/height at +0x0C/+0x0E and pixels at +0x1C.
 * D_801EC7F4 selects the buffer; D_80289218/D_8028D718 bound its sprite
 * display-list storage. D_8028DA38 is that storage's current cursor;
 * D_80202240 is the main display-list cursor.
 * D_801064C0 is the scale divisor 1024; D_801064C4 is the center divisor 2.
 * func_801CD3C0/func_801CE22C are libultra spInit/spFinish;
 * func_801CC0E8, func_801CC010 and func_801CC050 set position, RGBA and
 * scale; func_801CD578 (spDraw) returns the sprite's generated display list.
 * The final spFinish end command is overwritten by the next main-list write.
 * N64 symbol renaming is unsupported; these address names are retained.
 */
enum ScreenSpriteDrawLayout {
    SCREEN_SPRITE_LIBULTRA_OFFSET = 0x28,
    SCREEN_LIBULTRA_GFX_CURSOR_OFFSET = 0x3C,
    SCREEN_BITMAP_PIXELS_WORD = 2,
    SCREEN_SPRITE_MULTIPLE_BITMAPS = 2
};

enum ScreenSpriteTileLayout {
    SCREEN_SPRITE_IMAGE = 0x08,
    SCREEN_SPRITE_TILE_ALLOCATION = 0x24,
    SCREEN_SPRITE_TILE_COUNT = 0x50,
    SCREEN_SPRITE_MAX_GFX = 0x52,
    SCREEN_SPRITE_BITMAP_HEIGHT = 0x54,
    SCREEN_SPRITE_BITMAP_REAL_HEIGHT = 0x56,
    SCREEN_SPRITE_BITMAPS = 0x5C,
    SCREEN_IMAGE_WIDTH = 0x0C,
    SCREEN_IMAGE_HEIGHT = 0x0E,
    SCREEN_IMAGE_PIXELS = 0x1C
};

/* Halfword indices in the 0x10-byte bitmap record. */
enum ScreenSpriteBitmapWords {
    SCREEN_BITMAP_WIDTH = 0,
    SCREEN_BITMAP_STRIDE = 1,
    SCREEN_BITMAP_S = 2,
    SCREEN_BITMAP_T = 3,
    SCREEN_BITMAP_PIXELS = 4,
    SCREEN_BITMAP_HEIGHT = 6,
    SCREEN_BITMAP_ROW_PADDING = 7,
    SCREEN_BITMAP_WORDS = 8
};

/* func_8014A5C0: initScreenSpriteTiles; allocates named bitmap records,
 * copies the shared libultra Sprite defaults, then builds the tile grid.
 * D_80106464 is "bit-%d"; D_801ED628 is its allocation serial (initially 0).
 * D_801ED34C is the shared Sprite template, also used by text rendering.
 * func_801D2150 is sprintf; func_8013FCDC is the named heap allocator.
 * Obj8014A460: unk08=image, unk20/21/22/23=RGBA, unk24=tile allocation,
 * unk2C/2E=width/height, unk58/59=image format/size, unk6C=draw enabled.
 * Unk8014A460Sub: unk0C/0E=width/height, unk18/1A=image format/size.
 * The word-copy view retains the original 0x44-byte aggregate assignment. */
typedef struct ScreenSpriteTemplate {
    /* 0x00 */ s32 words[0x11];
} ScreenSpriteTemplate; /* size = 0x44 */

enum ScreenSpriteInitConstants {
    SCREEN_BITMAP_SIZE_SHIFT = 4,
    SCREEN_BITMAP_NAME_CAPACITY = 16,
    SCREEN_SPRITE_COLOR_MAX = 255,
    SCREEN_SPRITE_INITIAL_ALPHA = 127
};

enum ScreenSpriteTileConstants {
    SCREEN_TILE_WIDTH = 32,
    SCREEN_TILE_DEFAULT_HEIGHT = 32,
    SCREEN_TILE_MEDIUM_MIN_WIDTH = 65,
    SCREEN_TILE_MEDIUM_HEIGHT = 16,
    SCREEN_TILE_WIDE_MIN_WIDTH = 129,
    SCREEN_TILE_WIDE_HEIGHT = 8,
    SCREEN_IMAGE_BYTES_PER_PIXEL = 2,
    SCREEN_TILE_GFX_COUNT = 12,
    SCREEN_SPRITE_BASE_GFX_COUNT = 24
};

enum ScreenOverlayConstants {
    GFX_CMD_CALL_DISPLAY_LIST = 0x06000000,
    SCREEN_SPRITE_SENTINEL_BYTES = 0x74,
    SCREEN_TEXT_ALPHA_OFFSET = 0x5B,
    SCREEN_TEXT_SECOND_PULSE_OFFSET = 5,
    SCREEN_TEXT_THIRD_PULSE_OFFSET = 10,
    SCREEN_OVERLAY_STATE_LEVEL_MASK = 0xFFFF0000,
    SCREEN_OVERLAY_PLAY_LEVEL_2C = 0x042C0000
};

/* func_8014B7F0 initializes world-sprite animation; func_8014B8F8 updates it.
 * A nonzero lifetime drives opacity/scale interpolation and hides the sprite
 * on expiry. Otherwise interpolation follows the frame index. Frame delay
 * is accumulated as a byte and tested as signed, in units of 1/32 tick. */
typedef struct SpriteAnimationFrames {
    /* 0x00 */ s32 *images;
    /* 0x04 */ s16 count;
    /* 0x06 */ u8 unk06[2];
} SpriteAnimationFrames; /* size = 0x08; accessed prefix */

typedef struct SpriteAnimationState {
    /* 0x00 */ SpriteAnimationFrames *frames;
    /* 0x04 */ u8 frameDelay;
    /* 0x05 */ u8 mode;
    /* 0x06 */ u8 startAlpha;
    /* 0x07 */ u8 endAlpha;
    /* 0x08 */ u16 startScale;
    /* 0x0A */ u16 endScale;
    /* 0x0C */ u16 flags;
    /* 0x0E */ u16 lifetime;
    /* 0x10 */ u16 remainingLife;
    /* 0x12 */ u8 frame;
    /* 0x13 */ u8 delayAccumulator;
} SpriteAnimationState; /* size = 0x14 */

enum SpriteAnimationMode {
    SPRITE_ANIM_DISABLED = 0,
    SPRITE_ANIM_LOOP = 1,
    SPRITE_ANIM_ONCE = 2,
    SPRITE_ANIM_PING_PONG = 3,
    SPRITE_ANIM_RANDOM_START = 4,
    SPRITE_ANIM_HOLD_FRAME = 5,
    SPRITE_ANIM_REVERSE_ONCE = 6,
    SPRITE_ANIM_HOLD_ALL = 7
};

/* World-sprite rendering symbol roles (N64 symbol renaming is unavailable):
 * func_8014BB90: drawWorldSpritesFirstPass; returns the first late-pass sprite.
 * func_8014BE1C: drawWorldSpritesRemaining; resumes at that sprite through
 * the sentinel, drawing before advancing animation. Keeps D_80289314 from
 * the first pass while resetting the cached image and rebuilding the matrix.
 * func_8014C054: drawWorldSprite; func_8014B8F8: updateWorldSpriteAnimation; func_8014C6B0: drawWorldSpriteTexRect.
 * func_801C5710 / func_801C5398: guMtxCatL / guMtxL2F.
 * D_802892D8: circular world-sprite list sentinel.
 * D_80289318: last drawn sprite image, used to avoid reloading its texture.
 * D_80289314: late-pass render mode has been selected.
 * D_8028DC88: combined floating-point world-to-clip matrix.
 * D_8028DCC8: sprite fog scale, 128000 / (fogFar - fogNear).
 * D_8025D0C0: graphics matrix buffer; second input matrix is at +0x4080.
 * D_801EC7D2: nonzero suppresses animation updates in these passes.
 * D_801ED558 / D_801ED578: initial sprite display lists;
 * D_801ED5E8: additional display list used with fog enabled.
 * Fog parameters and the display-list cursor are documented with scene rendering.
 */
/* A world-space sprite (billboard) drawn by drawWorldSprite. */
typedef struct WorldSprite {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ Texture80154300 *texture;
    /* 0x0C */ f32 pos[3];
    /* 0x18 */ s16 width;
    /* 0x1A */ s16 height;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 color[4]; /* RGBA primitive color */
    /* 0x21 */ u8 flags; /* WORLD_SPRITE_LATE_PASS, _FLIP_X, _FLIP_Y */
    /* 0x22 */ s8 offsetX;
    /* 0x23 */ s8 offsetY;
} WorldSprite;

enum WorldSpriteRenderConstants {
    WORLD_SPRITE_LATE_PASS = 0x01,
    WORLD_SPRITE_FLIP_X = 0x02,
    WORLD_SPRITE_FLIP_Y = 0x04,
    WORLD_SPRITE_ANIMATION_MODE = 0x29,
    WORLD_SPRITE_SECOND_MATRIX_OFFSET = 0x4080,
    WORLD_SPRITE_PACKED_MATRIX_BYTES = 0x40,
    WORLD_SPRITE_FOG_RENDER_MODE = 0xC4113078,
    WORLD_SPRITE_RENDER_MODE = 0x00553078,
    WORLD_SPRITE_FOG_COMBINE_W0 = 0xFC1197FF,
    WORLD_SPRITE_FOG_COMBINE_W1 = 0xFFFFFE38,
    WORLD_SPRITE_COMBINE_W0 = 0xFC119623,
    WORLD_SPRITE_COMBINE_W1 = 0xFF2FFFFF
};

/* func_80189C9C: drawLightningEffects; func_8018A050: drawLightningStrip.
 * func_80154300 loads a texture into the RDP.
 * D_802989D0 holds 50 LightningEffect records; D_802991BC is the
 * one-past-end lifetime-field address used by the draw loop.
 * D_802989E8/E9/EA/EB alias red/green/blue/segmentCount in the first record;
 * D_802989EE/F0/F4 alias flags/jitter/width. D_802988BC is the lightning
 * texture, D_80202240 the display-list cursor, and D_801ED403 enables fog.
 */
typedef struct LightningEffect {
    /* 0x00 */ f32 start[3];
    /* 0x0C */ f32 end[3];
    /* 0x18 */ u8 red;
    /* 0x19 */ u8 green;
    /* 0x1A */ u8 blue;
    /* 0x1B */ u8 segmentCount;
    /* 0x1C */ u16 remainingFrames;
    /* 0x1E */ u16 flags;
    /* 0x20 */ f32 jitter;
    /* 0x24 */ f32 width;
} LightningEffect; /* size = 0x28 */

/* Aggregate access preserves the fog load's ordering after display-list stores. */
typedef struct FogEnabledFlag {
    /* 0x00 */ u8 enabled;
} FogEnabledFlag; /* size = 0x01 */

/* func_80189E78: spawnLightningEffect; rejects effects whose midpoint is
 * farther than D_801EC7DA from the camera position at D_8028F914.
 * func_80149398 computes a weighted vector sum; func_80148EBC returns
 * squared 3D distance. D_80109540 holds the 0.5f midpoint weight.
 * D_802989EC aliases the first record's remainingFrames.
 */
enum LightningRenderConstants {
    LIGHTNING_EFFECT_CAPACITY = 50,
    LIGHTNING_EFFECT_STRIDE = 0x28,
    LIGHTNING_END_OFFSET = 0x0C,
    LIGHTNING_LIFETIME_OFFSET = 0x1C,
    LIGHTNING_FOG_RENDER_MODE = 0xC8104B50,
    LIGHTNING_RENDER_MODE = 0x00504B50
};

/* func_801A7AC4: begin_translucent_draw(alpha). Same render modes as lightning;
 * the combiners blend the primitive alpha in (with or without fog). */
enum TranslucentDrawConstants {
    TRANSLUCENT_FOG_COMBINE_W0 = 0xFC1317FF,
    TRANSLUCENT_FOG_COMBINE_W1 = 0xFFFE7E38,
    TRANSLUCENT_COMBINE_W0 = WORLD_SPRITE_COMBINE_W0,
    TRANSLUCENT_COMBINE_W1 = WORLD_SPRITE_COMBINE_W1,
    GFX_CMD_SET_PRIM_COLOR = 0xFA000000,
    GFX_PRIM_COLOR_WHITE = 0xFFFFFF00   /* RGB 255,255,255; alpha in the low byte */
};

/* func_801AA74C: spawn_object_lightning_burst; emits five bolts in the XY
 * plane with independently randomized RGB channels in [160, 255].
 * func_80178134 plays positional sound; func_80147000 returns random % bound;
 * func_8014915C rotates a Vec3F about an axis; func_80189E78 spawns a bolt.
 * Pool values: D_8010B378 = 40.0f (bolt radius), the f64 at +4 = 10.0
 * (angle divisor), D_8010B384 = 6.0f (jitter), D_8010B388 = 1.0f (width).
 * Retain the original pool accesses and shared declarations.
 */
enum ObjectLightningBurstConstants {
    OBJECT_LIGHTNING_SOUND_ID = 0x3E,
    OBJECT_LIGHTNING_SOUND_VOLUME = 100,
    OBJECT_LIGHTNING_SOUND_PITCH = 160,
    OBJECT_LIGHTNING_BOLT_COUNT = 5,
    OBJECT_LIGHTNING_ANGLE_STEPS = 64,
    OBJECT_LIGHTNING_COLOR_RANGE = 96,
    OBJECT_LIGHTNING_COLOR_MASK = 0xFF,
    OBJECT_LIGHTNING_SEGMENT_COUNT = 8,
    OBJECT_LIGHTNING_LIFETIME_FRAMES = 2,
    OBJECT_LIGHTNING_FLAGS = 0x16
};

enum WorldSpriteAnimationLayout {
    WORLD_SPRITE_IMAGE = 0x08,
    WORLD_SPRITE_SCALE_X = 0x18,
    WORLD_SPRITE_SCALE_Y = 0x1A,
    WORLD_SPRITE_ALPHA = 0x20,
    WORLD_SPRITE_FLAGS = 0x21,
    WORLD_SPRITE_RED = 0x1D,
    WORLD_SPRITE_GREEN = 0x1E,
    WORLD_SPRITE_BLUE = 0x1F,
    WORLD_SPRITE_OFFSET_X = 0x22,
    WORLD_SPRITE_OFFSET_Y = 0x23,
    WORLD_SPRITE_ANIMATION = 0x24,
    WORLD_SPRITE_ANIM_START_SCALE = 0x2C,
    WORLD_SPRITE_ANIM_END_SCALE = 0x2E,
    SPRITE_ANIM_REVERSE_FLAG = 0x10,
    SPRITE_ANIM_FORWARD_MASK = 0xEF,
    SPRITE_ANIM_DELAY_TICK = 0x20
};

/* func_80177390: createThoughtBubbleSprites. D_80290140 holds the background
 * and animated foreground world-sprite pointers. D_80108558 is the allocation
 * label "Spr"; D_8010855C is "thought.bmp". The input supplies the first 0x10
 * bytes of SpriteAnimationState; runtime frame fields are initialized by
 * func_8014B7F0 (initWorldSpriteAnimation).
 * func_8014ACB4 unlinks a world sprite; func_80141720 frees and clears a heap
 * pointer; func_8013FCDC allocates; func_80139CA0 hashes an asset name;
 * func_8014FCF8 finds its texture; func_8014AC1C inserts a world sprite after
 * another, or chooses the list position when passed NULL.
 * Offsets 0x22/0x23 hold signed image origins, including the centered texture
 * half-width/half-height. SpriteAnimationState starts at offset 0x24.
 */
enum ThoughtBubbleSpriteConstants {
    THOUGHT_BUBBLE_SPRITE_COUNT = 2,
    THOUGHT_BUBBLE_BACKGROUND = 0,
    THOUGHT_BUBBLE_FOREGROUND = 1,
    THOUGHT_BUBBLE_SPRITE_BYTES = 0x38,
    THOUGHT_BUBBLE_FOREGROUND_X = -14,
    THOUGHT_BUBBLE_FOREGROUND_Y = -21,
    THOUGHT_BUBBLE_CHANNEL_MAX = 255
};

/* Screen-space sprite particle; scale values use 1024 for unit size. */
typedef struct ScreenParticle {
    /* 0x00 */ struct ScreenParticle *next;
    /* 0x04 */ struct ScreenParticle *prev;
    /* 0x08 */ s32 imageHandle;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 scaleX;
    /* 0x1C */ s32 scaleY;
    /* 0x20 */ u8 unk20[3];
    /* 0x23 */ u8 alpha;
    /* 0x24 */ s32 renderData[20]; /* First word is an allocation handle. */
    /* 0x74 */ f32 velocityX;
    /* 0x78 */ f32 velocityY; /* Positive moves upward on screen. */
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s16 opacity;
    /* 0x82 */ s16 targetOpacity;
    /* 0x84 */ s16 scale;
    /* 0x86 */ s16 targetScale;
    /* 0x88 */ s16 active;
    /* 0x8A */ s16 lifetime;
    /* 0x8C */ u8 age;
    /* 0x8D */ u8 flags;
    /* 0x8E */ u8 fadeDelay;
    /* 0x8F */ u8 pulsePhase;
} ScreenParticle; /* size = 0x90 */

/* Byte offsets preserve the raw-access aliasing used by the original compiler. */
enum ScreenParticleOffsets {
    SCREEN_PARTICLE_NEXT_OFFSET = 0x0,
    SCREEN_PARTICLE_IMAGE_HANDLE_OFFSET = 0x8,
    SCREEN_PARTICLE_X_OFFSET = 0xC,
    SCREEN_PARTICLE_Y_OFFSET = 0x10,
    SCREEN_PARTICLE_DRAW_ORDER_OFFSET = 0x14, /* Accessed as s16; retain unk14's type. */
    SCREEN_PARTICLE_UNK6C_OFFSET = 0x6C,
    SCREEN_PARTICLE_SCALE_X_OFFSET = 0x18,
    SCREEN_PARTICLE_SCALE_Y_OFFSET = 0x1C,
    SCREEN_PARTICLE_ALPHA_OFFSET = 0x23,
    SCREEN_PARTICLE_RENDER_DATA_OFFSET = 0x24,
    SCREEN_PARTICLE_VELOCITY_X_OFFSET = 0x74,
    SCREEN_PARTICLE_VELOCITY_Y_OFFSET = 0x78,
    SCREEN_PARTICLE_OPACITY_OFFSET = 0x80,
    SCREEN_PARTICLE_TARGET_OPACITY_OFFSET = 0x82,
    SCREEN_PARTICLE_SCALE_OFFSET = 0x84,
    SCREEN_PARTICLE_TARGET_SCALE_OFFSET = 0x86,
    SCREEN_PARTICLE_ACTIVE_OFFSET = 0x88,
    SCREEN_PARTICLE_LIFETIME_OFFSET = 0x8A,
    SCREEN_PARTICLE_AGE_OFFSET = 0x8C,
    SCREEN_PARTICLE_FLAGS_OFFSET = 0x8D,
    SCREEN_PARTICLE_FADE_DELAY_OFFSET = 0x8E,
    SCREEN_PARTICLE_PULSE_PHASE_OFFSET = 0x8F
};

enum ScreenParticleFlags {
    SCREEN_PARTICLE_DAMP_VELOCITY = 1,
    SCREEN_PARTICLE_GRAVITY = 2,
    SCREEN_PARTICLE_PULSE_WIDTH = 4,
    SCREEN_PARTICLE_HOLD_LIFETIME = 8,
    SCREEN_PARTICLE_DAMP_FALLING = 0x10
};

/* Presets selected by func_8014E9F4 (screen_particle_create).
 * The allocator tests slot 39 after scanning 40 entries; preserve that test.
 * With reuse enabled, that case uses the preset number as the slot index.
 */
enum ScreenParticlePreset {
    SCREEN_PARTICLE_SPARK = 0,
    SCREEN_PARTICLE_LIFE_ICON = 1,
    SCREEN_PARTICLE_RAIN = 2,
    SCREEN_PARTICLE_SNOW = 3,
    SCREEN_PARTICLE_YES_ICON = 4,
    SCREEN_PARTICLE_NO_ICON = 5,
    SCREEN_PARTICLE_DAMPED_SPARK = 6
};

enum ScreenParticleLimits {
    SCREEN_PARTICLE_POOL_COUNT = 40,
    SCREEN_PARTICLE_BYTES = 0x90,
    SCREEN_PARTICLE_UNIT_SCALE = 1024,
    SCREEN_PARTICLE_PULSE_PHASE_COUNT = 50,
    SCREEN_PARTICLE_SCALE_STEP = 100,
    SCREEN_PARTICLE_OPACITY_STEP = 1,
    SCREEN_PARTICLE_OPAQUE = 255,
    SCREEN_SNOW_MIN_SCALE = 100
};

/* func_8014E760: screen_particles_init clears active/lifetime/link fields,
 * sets unit scale and opaque alpha, and resolves the six preset textures.
 * D_8028DD5A is the first pool entry's lifetime field.
 * func_80139CA0 hashes a terminated asset name; func_8014FCF8 looks up its
 * texture and writes NULL if absent (the final zero suppresses diagnostics).
 * D_80106548/54/64/74/80/88 name spark/life/rain/snow/yes/no textures.
 */
enum ScreenParticleInitConstants {
    SCREEN_PARTICLE_INITIAL_DRAW_ORDER = 1
};

/* func_8014E8B4: screen_particle_emit_burst(screenX, screenY, count, preset).
 * D_80106590 is the burst's 6.28-radian angle span (f64).
 * D_80106598 is its speed and initial-angle divisor (3.0f); the f64 at
 * byte offset 4 is the spark's downward screen-velocity bias (1.2).
 * Vec3F.x/z carry screen X/Y velocity through func_801490AC (Y rotation).
 * func_80147000 supplies a bounded random integer; func_8014E9F4 creates
 * each ScreenParticle using ScreenParticlePreset, with slot reuse disabled.
 */
enum ScreenParticleBurstConstants {
    SCREEN_PARTICLE_BURST_PHASE_COUNT = 6,
    SCREEN_PARTICLE_BURST_BIAS_OFFSET = 4,
    SCREEN_PARTICLE_NO_REUSE = 0
};

/*
 * func_8014ED9C updates a ScreenParticle.
 * func_8014E9F4 creates one with a preset and inserts it in draw order.
 * func_8014A5C0 allocates and initializes its sprite rendering data;
 * func_80147000 returns a random value below its argument.
 * func_80139D94 reports a diagnostic through the disabled func_80139D70;
 * func_801D2150 formats text into D_8025D578.
 * D_8028DCD0 is the 40-entry pool; D_8028DD58 is its first active field.
 * D_8028D9C0 is the screen-sprite list sentinel.
 * The initializer's image names identify D_8028D8CC as sspark1.bmp,
 * D_80289394 as numlives01.bmp, D_8028D8D4 as yes.bmp and D_8028F3C8 as no.bmp.
 * D_801065A4 is the diagnostic label "SCREEN DEBRIS".
 * N64 symbol renames are unsupported; retain these address names.
 * func_801490AC rotates a Vec3F about Y; func_801494CC returns a wrapped
 * angle difference; func_80149724 computes sin((phase + frame) / divisor).
 * func_801C6000 is sine in radians; func_80141720 frees and clears a heap handle.
 *
 * D_8028D7D8 / D_8028D8D0 hold raindrop.bmp / ai_snow.bmp image handles.
 * D_8028DA34 counts linked screen sprites, including particles.
 * D_8028F938 / D_8028F940 are camera motion X/Z; D_8028F95C is camera yaw,
 * and D_8028FB88 is its previous value.
 *
 * Particle pool constants: D_801065B4 = unit X (1);
 * D_801065B8/BC/C0/C4 = horizontal wrap right/subtract/left/add (360/400/-40/400);
 * D_801065C8/CC = snow sway phase divisor / scale divisor (10/256);
 * D_801065D4 = snow base fall factor (0.25); D_801065DC = screen bottom (240);
 * D_801065E0/E8/F0 = damping/gravity/pulse phase divisor (0.9/0.5/2).
 * D_801ED65C/660 = camera motion/yaw divisors (2000000/-3000);
 * D_801ED664/668 = snow depth scale factor/maximum scale (-3/1200).
 */

/* Sound-options menu: 16 sprite segments represent volume levels 0..160.
 * The 0x74-byte sprite layout is the prefix of ScreenParticle through renderData.
 * D_801009F0/0A00/0A0C name sliderbit.bmp/newwave.ndo/newglove.ndo;
 * D_80100A1C/0A2C name horn0001.bmp/note0001.bmp.
 * D_80100A3C is the pooled f64 value 10.0 (volume units per segment).
 */
enum SoundOptionsLayout {
    SOUND_OPTIONS_SEGMENT_COUNT = 16,
    SOUND_OPTIONS_SPRITE_SIZE = 0x74,
    SOUND_OPTIONS_FIRST_SEGMENT_X = 155,
    SOUND_OPTIONS_BAR_BASE_X = 0x87,
    SOUND_OPTIONS_SEGMENT_SPACING = 6,
    SOUND_OPTIONS_MUSIC_BAR_Y = 80,
    SOUND_OPTIONS_SFX_BAR_Y = 110,
    SOUND_OPTIONS_VOLUME_HALF_STEP = 5,
    SOUND_OPTIONS_VOLUME_MAX = 160,
    SOUND_OPTIONS_STICK_DIVISOR = 30,
    SOUND_OPTIONS_SFX_TEST_ID = 0x83,
    SOUND_OPTIONS_SFX_REPEAT_DELAY = 5,
    SOUND_OPTIONS_SEGMENT_SCALE_X = 990,
    SOUND_OPTIONS_SEGMENT_SCALE_Y_END = 1450,
    SOUND_OPTIONS_SEGMENT_SCALE_Y_STEP = 60,
    SOUND_OPTIONS_DIM_ALPHA = 90,
    SOUND_OPTIONS_BAR_DIM_ALPHA = 0x7F,
    SOUND_OPTIONS_ITEM_COUNT = 4,
    SOUND_OPTIONS_OPTION_MUSIC = 0,
    SOUND_OPTIONS_OPTION_SFX = 1,
    SOUND_OPTIONS_OPTION_MODE = 2,
    SOUND_OPTIONS_OPTION_BACK = 3,
    SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET = 28,
    SOUND_OPTIONS_CONTROLLER_STRIDE = 0x190,
    SOUND_OPTIONS_GLOVE_ANIM_OFFSET = 220
};

/* func_8010EEF8: appendMenuModel(modelNameAddress, positionXYZ, rotationXYZ,
 * scaleXYZ, alpha). Appends a 0xE4-byte object and rebuilds every menu model's
 * quaternion. Addresses remain s32 to preserve the original access aliasing.
 * D_80269F40 is the menu model address array; D_801EC860 is its count.
 * D_80100160 is the allocator label "FGObj".
 * func_8013FCDC allocates aligned game memory; func_80142928 initializes a
 * model by asset name; func_8015C350 converts Euler angles to a quaternion.
 * ObjectNode's scaleX stores float bits; keep raw access for compiler aliasing.
 */
enum MenuObjectConstants {
    MENU_OBJECT_SCALE_X_OFFSET = 0xBC,
    MENU_OBJECT_ANIMATION_COMPONENT = 4,
    MENU_OBJECT_SIZE = 0xE4,
    MENU_OBJECT_ALPHA_OFFSET = 0x26,
    MENU_OBJECT_POSITION_X_OFFSET = 0x34,
    MENU_OBJECT_ROTATION_X_OFFSET = 0x78,
    MENU_OBJECT_ROTATION_Y_OFFSET = 0x7C,
    MENU_OBJECT_ROTATION_Z_OFFSET = 0x80,
    MENU_OBJECT_SCALE_Y_OFFSET = 0xC0,
    MENU_OBJECT_SCALE_Z_OFFSET = 0xC4,
    MENU_OBJECT_MODEL_OFFSET = 0xC8,
    MENU_MODEL_ROOT_OFFSET = 0x0C,
    MENU_MODEL_NODE_FLAGS_OFFSET = 0x32,
    MENU_MODEL_NODE_ALPHA_FLAG = 2,
    MENU_OBJECT_OPAQUE = 255
};

/* Menu input commands consumed by func_801100B8 (menu_update_selection). */
/* func_80120A90: initializeFadeModels.
 * func_80142928 initializes an object from a model asset name and position.
 * func_8015C350 builds a quaternion from Euler angles in D_801EFC80 order.
 * D_8028D7E8 / D_8028D8D8: fade plane / star objects;
 * D_8028D8B0 / D_8028D9A0: their model assets.
 * D_80101244 / D_80101254: "fadeplane.ndo" / "fadestar.ndo".
 * D_80101264: initial Z (400); D_80101268: plane scale (1);
 * D_8010126C / D_80101270: rotations (-1.57 / 1.57 radians);
 * D_80101274: star scale (0.2); D_80101278: star Z (13).
 * D_8028D864/868: plane Y/Z rotation; D_8028D8A4/A8/AC: plane scale XYZ.
 * D_8028D950/954/958: star rotation XYZ; D_8028D90C/910/914: star position XYZ;
 * D_8028D994/998/99C: star scale XYZ; D_8028D974: star quaternion.
 * D_8028D80E / D_8028D8FE: plane / star opacity.
 * D_80297918: shared texture header (Texture80154300 layout).
 * D_80297924/26: width/height; D_80297928/2A: log2 width/height;
 * D_80297930/32: RGBA format / 16-bit size; D_80297934: image pointer.
 * D_801E7480: 8x8 opaque white RGBA16 texels (128 bytes of 0xFF).
 * Symbol-role comments are used because N64 symbol renaming is unavailable.
 */
enum FadeModelConstants {
    FADE_TEXTURE_DIMENSION = 8,
    FADE_TEXTURE_LOG2_DIMENSION = 3,
    FADE_TEXTURE_FORMAT_RGBA = 0,
    FADE_TEXTURE_SIZE_16B = 2,
    FADE_INITIAL_OPACITY = 0x80,
    FADE_TEXTURE_IMAGE_WORD_OFFSET = 7,
    FADE_MODEL_MESH_OFFSET = 0x14,
    FADE_MESH_TEXTURES_OFFSET = 0x20,
    FADE_MESH_VERTEX_COLORS_OFFSET = 0x18, /* RGBA bytes, one per corner */
    FADE_PLANE_CORNER_COUNT = 4,
    FADE_QUATERNION_TO_EULER_OFFSET = 0x24
};

/*
 * Menu phase dispatch: func_8010F9C0 (menu_update_phase) calls one handler;
 * func_8010FC10 (menu_advance_phase) skips to the next phase/menu.
 * D_801E58B4 is the current menu ID, D_801E58A4 the pending menu ID,
 * D_801E58A8 the phase index, and D_801E58BC the 0xEC-byte menu table.
 * D_801F6138 is the first selectable entry; D_801F613C is the exclusive end.
 * D_801E58DC views the entry count at table offset 0x20 with the same stride.
 * D_801E58A0 is the animation frame accumulator; D_801001B4 holds 1.0f.
 * Seven callback slots are dispatched; slot 7 overlaps MenuState.cur.
 * Keep the one-argument callback type and cast at dispatch for the context.
 */
enum MenuPhaseConstants {
    MENU_PHASE_COUNT = 7
};

typedef s32 (*MenuPhaseHandler)(s32 *menuCommand);

typedef struct MenuPhaseTable {
    /* 0x00 */ MenuPhaseHandler fn[8]; /* Seven callbacks and selection word. */
    /* 0x20 */ s32 unk20;             /* Default selectable entry count. */
    /* 0x24 */ s32 pad[50];           /* Menu entries; retain the storage view. */
} MenuPhaseTable; /* size 0xEC */

typedef struct MenuEntryCountView {
    /* 0x00 */ s32 unk0;    /* Default exclusive selectable-entry bound. */
    /* 0x04 */ s32 pad[58]; /* Stride to the next menu's count. */
} MenuEntryCountView; /* size 0xEC */

enum MenuInputCommand {
    MENU_INPUT_DOWN = 0,
    MENU_INPUT_UP = 1,
    MENU_INPUT_NEXT = 2,
    MENU_INPUT_PREVIOUS = 3,
    MENU_INPUT_CONFIRM = 4,
    MENU_INPUT_CANCEL = 5,
    MENU_INPUT_NONE = 6
};

/* func_8010FC84 initializes the menu scene and polls menu input.
 * D_801E747C counts menu frames; D_801E58B4 is the current menu ID.
 * D_801E58B8 skips reloading menu banks once; D_801E5898 enables buttons.
 * D_801E6590 is the vertical-stick repeat countdown.
 * D_801FAA92 is stick Y; D_801FAAC6/9 confirm and D_801FAAC7 cancels.
 * These input fields are views into controller records with stride 0x190.
 * D_801F6098 is the backdrop sprite: image at +0x48, s16 X/Y scales at
 * +0x58/+0x5A, color bytes at +0x6C..+0x6E and alpha at +0x6F (size 0x70).
 * D_80092030 / D_800B7830 are the two 320x240 16-bit framebuffers.
 * D_801001D0 is drawing tag "domenu"; D_80100130 is allocation tag
 * "Backdrop"; D_801001D8 is "backgr.bmp"; D_801001E4/E8 hold 4/1.
 * func_80155A44 / func_80155AE4 stop / start drawing and wait for acknowledgement.
 * func_8012C2B0 fills bytes; func_8013FCDC allocates tagged memory.
 * func_8014F510 / func_80150EA4 load texture / model banks.
 * func_80177A14 selects music; func_8011C810 frees the sprite list.
 * func_8014AA20 inserts a sprite in draw order; func_8014FCF8 finds a
 * texture by the name hash computed by func_80139CA0.
 * func_801890EC initializes a light, func_80188FD8 links it, and
 * func_801891E4 sets ambient RGB. D_801F6040 is the menu light.
 * func_8010F9C0 dispatches the current menu phase with the input command.
 * Symbol names remain unchanged because N64 rename_symbol is unsupported.
 */
/*
 * func_8010E86C: update_startup_logos. D_801E64D4 counts frames and
 * D_801E64D8 records the switch from the N64 logo to the licence screen.
 * D_80000300 is osTvType (zero is PAL); other TV modes start with licence.bmp.
 * D_801F6098 is the 0x70-byte backdrop described below.
 * Strings decoded from asm/1000.s: D_80100130 = "Backdrop",
 * D_8010013C = "n64.bmp", D_80100144 = "licence.bmp".
 * D_801ED400/401/402 are transition RGB; D_801EC7DA is the draw-distance limit.
 * func_8014D4D0 closes the transition, func_8014D548 opens it, and
 * func_8014D5E0 tests whether it has closed far enough to change screens.
 * The cleanup frees texture-bank allocations, ParticleImageSequence.images,
 * and the background sprite list through func_8011C810.
 */
enum StartupLogoConstants {
    STARTUP_LOGO_DRAW_DISTANCE = 30000,
    STARTUP_LOGO_SCREEN_LEFT = 10,
    STARTUP_LOGO_FADE_STEP = 10,
    STARTUP_LOGO_FULL_ALPHA = 255,
    STARTUP_LOGO_ALPHA_LIMIT = 256,
    STARTUP_LOGO_FADE_IN_END_FRAME = 70,
    STARTUP_LOGO_FIRST_FADE_OUT_FRAME = 125,
    STARTUP_LOGO_FIRST_SWITCH_FRAME = 126,
    STARTUP_LOGO_SECOND_FADE_OUT_FRAME = 250,
    STARTUP_LOGO_FINISH_FRAME = 251
};

enum MenuSceneConstants {
    MENU_FRAMEBUFFER_BYTES = 320 * 240 * 2,
    MENU_TRANSITION_FULL_EXTENT = 300,
    MENU_STICK_THRESHOLD = 40,
    MENU_STICK_REPEAT_DELAY = 6,
    MENU_TEXTURE_BANK = 0,
    MENU_MODEL_BANK = 70,
    MENU_MUSIC_TRACK = 60,
    MENU_BACKDROP_BYTES = 0x70,
    MENU_BACKDROP_IMAGE_OFFSET = 0x48,
    MENU_BACKDROP_SCALE_X_OFFSET = 0x58,
    MENU_BACKDROP_SCALE_Y_OFFSET = 0x5A,
    MENU_BACKDROP_COLOR_0_OFFSET = 0x6C,
    MENU_BACKDROP_COLOR_1_OFFSET = 0x6D,
    MENU_BACKDROP_COLOR_2_OFFSET = 0x6E,
    MENU_BACKDROP_ALPHA_OFFSET = 0x6F,
    MENU_BACKDROP_UNIT_SCALE = 1024,
    MENU_FOG_NEAR = 990,
    MENU_FOG_FAR = 1000
};

/*
 * func_801282BC: update_scene_menu. On entry, reset scene lists, load scene 1,
 * set the camera/fog, free the scene's sprite allocations, and select the
 * alternate font. Each frame animates the camera and dispatches menu input.
 * D_801E747C: menu frame counter; D_801E7668: saved vertical field of view;
 * D_801E766A: stick-repeat countdown; D_801EC7D8: menu input/dispatch gate.
 * D_80101720 is the drawing tag "u3dtg".
 * D_801FAAC6/7/9 confirm here; D_801FAAC8 cancels. Stick input takes priority.
 * func_8011D88C loads scene assets; func_80125040 animates the title camera;
 * func_8014F510 loads a texture bank; func_80145680 selects the font;
 * func_80141720 frees an allocation and clears its pointer;
 * func_8014A9FC resets the sprite list; func_8014D548 resets the transition;
 * func_80155AE4 enables drawing; func_8010F9C0 dispatches the menu phase.
 */
enum SceneMenuConstants {
    SCENE_MENU_LEVEL = 1,
    SCENE_MENU_DRAW_START_FRAME = 26,
    SCENE_MENU_FIELD_OF_VIEW = 45,
    SCENE_MENU_FOG_RED = 130,
    SCENE_MENU_FOG_GREEN = 130,
    SCENE_MENU_FOG_BLUE = 200,
    SCENE_MENU_FAR_CLIP = 2500,
    SCENE_MENU_STICK_REPEAT_DELAY = 2,
    SCENE_MENU_CONTROLLER_STRIDE = 400,
    SCENE_MENU_ALTERNATE_FONT = 1
};

enum MenuEntryKind {
    MENU_ENTRY_SKIP = 3,
    MENU_ENTRY_END = 4
};

enum MenuSelectionConstants {
    MENU_ID_MAIN = 1,
    MENU_ID_NO_CHANGE = 13,
    MENU_TRANSITION_FLAGS = 31,
    MENU_CURSOR_SCALE_STEP = 120,
    MENU_CURSOR_REBOUND_THRESHOLD = 350,
    MENU_CURSOR_SNAP_THRESHOLD = 910,
    MENU_CURSOR_FULL_SCALE = 1024,
    MENU_CURSOR_CONFIRM_SCALE = 700,
    MENU_SOUND_MOVE = 0xD4,
    MENU_SOUND_CONFIRM = 0xD8,
    MENU_SOUND_CANCEL = 0xD9,
    MENU_SOUND_VOLUME = 100,
    MENU_SOUND_CENTER_PAN = 128,
    MENU_SOUND_NORMAL_PITCH = 128
};

/* func_801151C8: records_menu_init; func_80115CE4 updates/draws records.
 * Page -1 shows high scores; pages 0..5 show five best times per world.
 * MenuState describes the second argument, retained as an integer address.
 * func_8010EEF8 appends a model with XYZ position, XYZ rotation, XYZ scale
 * and opacity. func_8014A50C initializes and links a 0x74-byte sprite;
 * func_8010E560 starts the entry transition, func_8010F0B8 saves slide origins.
 * D_8010069C/6AC are "titleboxb.ndo"/"titleboxbf.ndo";
 * D_801006BC/6C8 are "arrow.bmp"/"arrowrev.bmp" (verified in asm/1000.s).
 * Pool floats: D_801006D8 = -48 (Y), D_801006DC = 400 (Z),
 * D_801006E0 = 0.1 (pitch), D_801006E4 = 3.14 (roll),
 * D_801006E8 = 1 (Z scale and initial title scale),
 * D_801006EC = 250 (initial text slide offset).
 * D_801F6C90/94: current high-score/best-time heading opacity.
 * D_801F6CA8/AC: target high-score/best-time heading opacity.
 * D_801F6CC0/C4: target left/right arrow opacity.
 * D_801F6CC8: right arrow sprite; +0x74: left arrow; D_801F6D5F: left alpha.
 * D_801F6DB0: records update counter; D_801F6CA4: exit transition flag.
 * D_801E6644/48: current/pending page; D_801E6638/3C: current/target title scale.
 * D_801E6690: fade value approaching 255; D_801E6694: slide bounce count.
 * D_801E6698/9C: text slide offset/velocity. Preserve the existing global
 * types: zero stores through integer declarations also initialize float bits.
 */
enum RecordsMenuConstants {
    RECORDS_MENU_HIGH_SCORES_PAGE = -1,
    RECORDS_MENU_OPAQUE = 255,
    RECORDS_MENU_TRANSLUCENT_MODEL_ALPHA = 100,
    RECORDS_MENU_MODEL_COUNT = 2,
    RECORDS_MENU_SPRITE_BYTES = 0x74,
    RECORDS_MENU_RIGHT_ARROW_X = 205,
    RECORDS_MENU_LEFT_ARROW_X = 125,
    RECORDS_MENU_ARROW_Y = 210,
    RECORDS_MENU_ARROW_DEPTH = 4,
    RECORDS_MENU_ARROW_MODE = 1
};

/* Menu selection state; entries follow the fixed 0x24-byte prefix.
 * cur and prev are entry indices; the trailing array has variable capacity.
 * func_801793DC plays a sound effect with volume, pan and pitch controls.
 * D_801F9214/18 are cursor X/Y; D_801F9220/24 are cursor X/Y scale
 * (the ScreenParticle prefix of the sprite at D_801F9208).
 * D_801F63FC/6400 are target cursor X/Y; D_801E6598 offsets target X.
 * D_801E5890 is target scale; D_801001F4/F8/021C hold 3/1024/300.
 * The f64 at D_801001E8 + 4 is 2^32 for unsigned coordinate conversion.
 * D_801F6138/3C bound selectable entries; D_801E58A4 is the next menu ID.
 * D_801E6608 holds menu transition flags (31 when starting a transition).
 */
typedef struct MenuEntry {
    /* 0x00 */ s32 unk0;  /* Entry kind; MenuEntryKind names known sentinels. */
    /* 0x04 */ s32 unk4;  /* Cursor X, interpreted as unsigned by selection. */
    /* 0x08 */ s32 unk8;  /* Cursor Y. */
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10; /* Menu ID selected on confirmation. */
} MenuEntry; /* size 0x14 */

typedef struct MenuState {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ u32 cur;
    /* 0x20 */ u32 prev;
    /* 0x24 */ MenuEntry entries[1];
} MenuState;

/* Callback view of MenuState: each callback is at +0x30 + index * 0x14.
 * This view starts entries at 0x20, four bytes before MenuState.entries.
 * func_80112E18 (title_menu_finish) uses this layout after exit motion.
 * D_801E64C8: transition complete; D_801E58A4: destination menu ID.
 * IDs 9/12 enable the closing transition via D_801E5894; IDs 2/3/4
 * keep the framebuffers. Other destinations pause drawing with
 * func_80155A44 and clear D_80092030/D_800B7830 via func_8012C2B0.
 * D_8010048C is the drawing-pause diagnostic label.
 * func_8010F23C slides the four waves out; func_80112F80 updates/draws
 * the title menu; func_8010E558 is empty; func_8010F94C frees its models.
 * D_801F6C88 enables the selection callback (disabled for the idle demo).
 * D_801E65B0 is set on exit; its wider purpose remains unresolved.
 * Return 0 while exiting or after a callback, 1 when no callback runs. */
typedef struct MenuCallbackEntry {
    /* 0x00 */ u8 unk0[0x10];
    /* 0x10 */ void (*callback)(void);
} MenuCallbackEntry; /* size 0x14 */

typedef struct MenuCallbackState {
    /* 0x00 */ u8 unk0[0x1C];
    /* 0x1C */ s32 selectedEntry;
    /* 0x20 */ MenuCallbackEntry entries[1];
} MenuCallbackState; /* accessed prefix size 0x34 */

/* Title-menu model slots and slide axes (D_801E650C).
 * The four waves use newwave.ndo; slot four uses newglove.ndo.
 * func_801128C8 initializes these models; func_80112F80 updates the menu.
 * D_80269F40 holds their addresses; D_801EC860 is the model count.
 * D_801E660C shifts the waves in X; D_801E6614/18/1C/20 reset menu rotations.
 * D_80100434 is allocation label "TitA1", D_8010043C is "newwave.ndo",
 * D_80100448 is "newglove.ndo", D_80100458 is wait label "inittitlewait".
 * D_80100468/6C set wave X/Z (-15/400), D_80100470/74 set Z/X angles
 * (3.14/-0.2), D_80100478 is unit scale/speed, D_8010047C is Y scale (0.6),
 * D_80100480/84 are animation speeds (0.8/1.1), D_80100488 is glove Y angle (3.5).
 * func_8013FCDC allocates; func_80142928 loads and positions a model;
 * func_80142700 creates requested components; func_80133998 sets/queues animation.
 * func_8010EEF8 appends a transformed model; func_8010F0B8 saves slide origins.
 */
enum TitleMenuModelSlots {
    TITLE_MENU_WAVE_COUNT = 4,
    TITLE_MENU_GLOVE_SLOT = 4
};

/* func_80118D54: menu_init_difficulty; func_801190BC updates the menu.
 * The two entries select Easy (0) or Normal (1), saved in D_801EAA55.
 * D_801E6720 records confirmation; D_801E5898 enables menu input.
 * D_80100AD4 names "newwave.ndo"; D_80100AE0/E4/E8 hold model Z (400),
 * X rotation (0.1) and Z rotation (3.14). D_80100AEC is unit scale/speed;
 * D_80100AF0 is the second wave's animation speed (0.9).
 * D_801E6614/18/1C/20 are reset rotation impulses. D_80269F40/44 are
 * the first/second model slots. D_801E650C/10/14/18 hold slide directions.
 * func_8010E560 starts the transition; func_80145680 selects the font;
 * func_8010EEF8 appends a model; func_80142700 enables object components;
 * func_80133998 sets/queues animation; func_8010F0B8 saves slide origins.
 * Address names remain because N64 symbol renaming is unsupported.
 */
/* func_80118B70: menu_init_name_entry; func_801198D0 updates the screen.
 * Arguments retain integer addresses of the input command and menu context.
 * D_801E66C0 is the character grid; D_801E6708 is its row count;
 * D_801F7D34 is the calculated column count. D_801E6704 is the selected
 * character index; D_801E6724 marks confirmation. D_801E6700 holds up to
 * three entered characters and a terminator.
 * func_801D20F8 measures a string; func_8012C2B0 fills a byte range.
 * func_8010E560 starts the entry transition; func_80145680 selects the font;
 * func_8010EEF8 creates a menu model; func_8010F0B8 saves slide origins;
 * func_80155AE4 resumes drawing and waits for acknowledgement.
 * Verified in asm/1000.s: D_80100A94 = "titleboxb.ndo",
 * D_80100AA4 = "titleboxbf.ndo", D_80100AB4 = "initnamescr".
 * D_80100AC0/C4/C8/CC/D0 supply model Y (-38), Z (400), pitch (0.1),
 * roll (3.14), and X scale (2). D_801E65B0's wider purpose is unknown.
 */
/*
 * func_8011A6EC (menu_finish_name_entry) waits for D_801E64C8, frees the
 * menu models, and copies D_801E6700/01/02 into the departing level's record.
 * D_801EAA55 is the mode/difficulty byte of the slot selected by D_801EAB24;
 * its stride is LEVEL_SAVE_SLOT_BYTES. Mode 2 is time trial.
 * D_801E7532 holds the departing level; D_801E693C[level][0] is its record
 * index (14 words per level). D_801E6792 addresses initial0 of the first
 * LevelTimeRecordView, with a six-byte record stride.
 * func_8010F23C updates model exit motion; func_801198D0 updates name entry;
 * func_8010E558 is empty; func_8010F94C releases menu models.
 * func_80132C04 queues save operation 4 and waits; func_80132DA8 queues
 * operation 11 and waits. func_8010E0D8 returns to time-trial selection.
 * Parameters remain integer addresses of the input command and menu context.
 */
enum NameEntryMenuConstants {
    NAME_ENTRY_TIME_TRIAL_MODE = 2,
    NAME_ENTRY_MODEL_COUNT = 2,
    NAME_ENTRY_BUFFER_BYTES = 4,
    NAME_ENTRY_MODEL_OPAQUE = 255,
    NAME_ENTRY_MODEL_TRANSLUCENT_ALPHA = 100,
    NAME_ENTRY_SHADOW_MAX_ALPHA = 127,
    NAME_ENTRY_KEY_SPACE = 0x20,
    NAME_ENTRY_KEY_BACKSPACE = 0x24,
    NAME_ENTRY_KEY_BLANK = 0x40,
    NAME_ENTRY_KEY_CONFIRM = 0xA3,
    NAME_ENTRY_MAX_CHARS = 3,
    NAME_ENTRY_REPEAT_DELAY = 7,
    NAME_ENTRY_STICK_DEADZONE = 20,
    NAME_ENTRY_CELL_SPACING = 20,
    NAME_ENTRY_CONTROLLER_STRIDE = 0x190,
    NAME_ENTRY_CMD_CANCEL = 5,
    NAME_ENTRY_NEXT_MENU_CONFIRM = 10,
    NAME_ENTRY_NEXT_MENU_CANCEL = 2
};

/* func_8011A99C: menu_finish_difficulty.
 * D_801E64C8 signals transition completion; D_801E6720 confirms a new game;
 * D_801E5894 enables the visible closing transition and audio fade.
 * D_801E6700/01/02 are entered initials, copied to the current player name
 * D_801FA9A8/A9/AA and the selected save slot's D_801EAA44/45/46 bytes.
 * D_801EAB24 selects the slot. D_80092030/D_800B7830 are framebuffers.
 * func_8010F94C releases menu models; func_8012C2B0 fills bytes;
 * func_8010EBE8 resets scene resources; func_80155A44 pauses drawing;
 * func_8011F9F4 resets new-game progress; func_801335A8 updates the save;
 * func_8011FF40 initializes the requested level. Keep the existing call
 * casts and extra save-call argument: their setup is part of the match.
 */
enum DifficultyMenuConstants {
    DIFFICULTY_MENU_MODEL_COUNT = 2,
    DIFFICULTY_MENU_NORMAL_ENTRY = 1,
    DIFFICULTY_MENU_START_LEVEL = 0x2E,
    MENU_STATE_SELECTION_WORD = 7
};

enum MenuSlideAxis {
    MENU_SLIDE_POSITIVE_Y = 0,
    MENU_SLIDE_NEGATIVE_Y = 1,
    MENU_SLIDE_NEGATIVE_X = 2,
    MENU_SLIDE_POSITIVE_X = 3
};

/* func_8010F23C (menu_update_model_exit) disables menu input and accelerates
 * models away from their saved positions along MenuSlideAxis directions.
 * All models share the fade derived from the first slide distance, unless
 * D_801F6138 disables fading. Quaternion updates cover D_801EC860 models,
 * independently of the number being moved. D_80100174/178/184 are opacity
 * 255, fade distance 110 and cutoff 111; D_80100188 is travel limit 500.
 * The f64 at D_80100178 + 4 is the horizontal travel multiplier 1.6.
 */

/* func_8010F520 (menu_update_model_slide) brings menu models to their saved
 * positions with delayed, damped bounces, fades them in and updates rotations.
 * D_801F60A0..AC are slide distances; D_801F6430..3C are approach speeds.
 * D_801F6128..34 are phases, initialized to 1 and incremented on each bounce.
 * D_801F6124[count] aliases the last model's phase; phase >= 3 enables
 * menu buttons through D_801E5898. The following word, D_801F6138, is the
 * first selectable entry, also read as phase[4] to decide whether to fade.
 * D_801E64F8 is the slide frame counter; D_801E64FC delays each model by
 * 0/8/16/24 frames. D_801E64E8 holds rebound factors 0.35/0.30/0.25/0.20.
 * D_801E652C/654C hold saved X/Y positions. D_801E656C holds saved Y
 * rotations, which this update deliberately writes to the X rotation field.
 * D_801E650C holds MenuSlideAxis values; D_801E658C is rotation divisor 10.
 * D_80100194/198/1A4 hold opacity 255, fade distance 110 and cutoff 111;
 * the f64 at D_80100198 + 4 is horizontal scale 1.2.
 * D_801001A8 is acceleration 0.8; D_801001B0 is bounce distance 1.
 * func_8015C350 builds a quaternion from Euler angles in D_801EFC80 order.
 * The original reset loop repeats stores to the same model, not every model.
 * Symbol names are retained because rename_symbol does not yet support N64.
 */
enum MenuSlideConstants {
    MENU_SLIDE_SETTLED_PHASE = 3,
    MENU_SLIDE_INACTIVE_PHASE = 4,
    MENU_SLIDE_FIRST_ENTRY_WORD = 4,
    MENU_SLIDE_FADE_ENTRY_LIMIT = 2,
    MENU_OBJECT_POSITION_Y_OFFSET = 0x38,
    MENU_OBJECT_QUATERNION_OFFSET = 0x9C
};

/* The heap at D_8025D690 allocates from both ends of one memory region.
 * High-end allocations occupy entries 0..highLastBlock in descending address
 * order; low-end allocations grow upward using entries 1279 down to lowFirstBlock.
 * Addresses remain s32 to preserve the original N64 representation.
 * func_801411DC frees a low-end allocation; func_80140C1C frees a high-end one.
 * Both clear the caller's address when found and return 1, including an already
 * free block; an unknown address returns 0. func_80141720 tries both ends.
 */
/* func_801420E0 validates block adjacency and allocated-byte totals at both ends.
 * D_80105EFC / D_80105F20 report a gap / total mismatch with the current
 * state's frame counter D_802004E0. D_8025D578 is the debug formatting buffer;
 * func_801D2150 is sprintf and func_80139D70 is the disabled output hook.
 * func_801C066C sets master volume for a sound-category mask;
 * func_801793DC plays an effect with volume, pan and combined pitch/tempo.
 * A diagnostic sounds effect 248, then waits for A on controller D_80202218.
 * D_801FB280 contains the raw controller samples.
 */
/* func_80141874 dumps the Jalloc block list (game_heap_dump).
 * It counts allocated/free entries at both ends, but returns immediately if
 * the high end is empty. Its displayed block count covers only the high end.
 * D_80105E1C is the title, D_80105E34 the divider, D_80105E50 the count format,
 * D_80105E5C the index/name/address/size/status format, D_80105E90 a newline,
 * and D_80105E94 the used/free totals format. Output goes through the disabled
 * func_80139D70 hook after sprintf (func_801D2150) fills D_8025D578.
 */
/* func_80141C2C (rom_asset_output_size) reads the FLA2 header synchronously
 * and returns its little-endian decoded size, or romEnd - romStart for raw data.
 * It retains the same unused word cursor increment as rom_load_asset below.
 */
/* func_80141DD8 (rom_load_asset) reads [romStart, romEnd) synchronously,
 * decoding FLA2 data into the caller's destination when the signature matches.
 * FLA2 has an 8-byte header: ASCII magic at 0, little-endian output size at 4.
 * The loader keeps this header as two s32 words and swaps the size explicitly.
 * Its unused, uninitialized word cursor increment is retained for the -O0 match.
 *
 * func_801C62C0 / func_801C6470: osInvalDCache / osWritebackDCache.
 * func_801D1C50 / func_801C7430: osPiStartDma / osRecvMesg.
 * func_8013FCDC: game_heap_alloc (size, clear flag, allocation name).
 * func_80141720: game_heap_free, clearing the caller's allocation address.
 * func_8012C3BC: fla2_decompress, consuming the payload after the header.
 * func_801D2150 / func_80139D70: sprintf / disabled diagnostic output hook.
 * D_8025D558: ROM DMA I/O message storage (0x20 bytes).
 * D_80201008: ROM DMA completion queue (OSMesgQueue, 0x18 bytes).
 * D_8025D578: debug formatting buffer (0x100 bytes).
 * D_80105EB8: "Compressed file found"; D_80105EE0: "tempdecomp".
 * D_80105EEC: "DMAMemory:%d\\n", reporting the output byte count.
 * Symbol names remain unchanged because N64 rename_symbol is unsupported.
 */
/* func_8012C3BC: fla2_decompress; input starts after the FLA2 header.
 * Flags are consumed most-significant bit first: 0 copies a literal, 1
 * decodes a two-byte back-reference. Its high nibble and second byte give
 * the backward distance; its low nibble gives length minus two. A zero
 * first back-reference byte terminates the stream before a second is read.
 * The zero-filled 4 KiB history ring supports overlapping copies.
 * func_8012C2B0: fill_bytes; func_8012C32C: fla2_emit_byte.
 * D_801E76C0: fla2_output_cursor (address stored as s32).
 * D_801E76C4: fla2_output_byte_count.
 * D_801F9690: fla2_history, 0x1000 bytes.
 * D_801FA690: fla2_history_write_index, wrapping modulo 0x1000.
 * These globals make the decoder non-reentrant. Symbol names are retained
 * until N64 symbol renaming is supported. */
enum Fla2TokenFormat {
    FLA2_HISTORY_SIZE = 0x1000,
    FLA2_HISTORY_MASK = 0xFFF,
    FLA2_TOKENS_PER_FLAG_BYTE = 8,
    FLA2_BACK_REFERENCE_FLAG = 0x80,
    FLA2_DISTANCE_HIGH_MASK = 0xF0,
    FLA2_DISTANCE_HIGH_SCALE = 16,
    FLA2_LENGTH_MASK = 0xF,
    FLA2_MIN_MATCH_LENGTH = 2,
    FLA2_END_MARKER = 0
};

enum RomAssetFormat {
    FLA2_MAGIC = 0x464C4132,
    FLA2_HEADER_SIZE = 8,
    FLA2_HEADER_WORDS = 2,
    FLA2_MAGIC_WORD = 0,
    FLA2_OUTPUT_SIZE_WORD = 1
};

/* func_80152498 (loadLandscape) loads the indexed level-data entry from
 * [D_B0492500, D_B04D5890). Each entry begins with a native-endian s32
 * byte length, including that word; the returned allocation retains it.
 * func_80141C2C determines the decoded allocation size, func_80141DD8 loads it.
 * D_80106DE4 = "loadlandscape" (stop-drawing tag);
 * D_80106DF4 = "LEVEL UNPLAYABLE - NO LEV FILE";
 * D_80106E14 = "LandData" (allocation name).
 * A missing entry stops drawing and sets GAME_STATE_ERROR with its message
 * in D_801E7544. Address names remain until N64 symbol renaming is supported.
 */
/*
 * func_801526C4 (load_recorded_input) selects a level's controller recording
 * in [D_B077BBE0, D_B077DE20). Entries start with a big-endian s32 byte
 * length including the length word. The loader skips that word for the
 * returned data but retains the full length for allocation and loading.
 * D_80106E20 = "loadrecord" (stop-drawing tag);
 * D_80106E2C = "LEVEL UNPLAYABLE - NO MOO FILE";
 * D_80106E4C = "RecKey" (allocation name).
 * func_80155A44 stops drawing; a missing entry sets GAME_STATE_ERROR and
 * formats the error in D_801E7544. The caller stores the result in
 * D_801EC768 for controller playback in func_80135568.
 */
enum RomBankFormat {
    ROM_BANK_LENGTH_SIZE = 4
};

enum RomAssetLoadOptions {
    ROM_DMA_PRIORITY_NORMAL = 0,
    ROM_DMA_READ = 0,
    ROM_DMA_WAIT = 1,
    ROM_ASSET_CLEAR_ALLOCATION = 1
};

enum GameHeapLimits {
    GAME_HEAP_BLOCK_CAPACITY = 1280,
    GAME_HEAP_HIGH_EMPTY = -1
};

enum HeapDiagnosticSound {
    HEAP_DIAGNOSTIC_EFFECTS_MASK = 1,
    HEAP_DIAGNOSTIC_MASTER_VOLUME = 0x55F0,
    HEAP_DIAGNOSTIC_SOUND_ID = 0xF8,
    HEAP_DIAGNOSTIC_SOUND_VOLUME = 100,
    HEAP_DIAGNOSTIC_SOUND_PAN = 128,
    HEAP_DIAGNOSTIC_SOUND_PITCH = 128
};

enum ControllerButtons {
    CONTROLLER_BUTTON_A = 0x8000
};

/* Raw libultra controller sample; the final byte is alignment padding. */
typedef struct ControllerPad {
    /* 0x00 */ u16 button;
    /* 0x02 */ s8 stickX;
    /* 0x03 */ s8 stickY;
    /* 0x04 */ u8 error;
} ControllerPad; /* size = 0x06 */

typedef struct GameHeapBlock {
    /* 0x00 */ s32 address;
    /* 0x04 */ s32 size;
    /* 0x08 */ u8 name[11];
    /* 0x13 */ u8 allocated;
} GameHeapBlock; /* size = 0x14 */

typedef struct GameHeap {
    /* 0x0000 */ GameHeapBlock blocks[GAME_HEAP_BLOCK_CAPACITY];
    /* 0x6400 */ s32 baseAddress;
    /* 0x6404 */ s32 size;
    /* 0x6408 */ s32 highLastBlock; /* Inclusive; -1 when empty. */
    /* 0x640C */ s32 lowFirstBlock; /* 1280 when empty. */
    /* 0x6410 */ s32 highAllocatedBytes;
    /* 0x6414 */ s32 lowAllocatedBytes;
} GameHeap; /* size = 0x6418 */

/* World particles occupy 120 slots of 0x120 bytes at D_802A2000.
 * Their object prefix is followed by an active byte and a 0x38-byte sprite.
 * func_801B6B3C updates the pool; func_801B6A78 expires or replaces a slot;
 * func_8015D020 updates object physics; func_801B7344 emits a radial burst.
 *
 * The separately labelled pool fields below all use a byte stride of 0x120:
 * D_802A2024 lifetime, D_802A2028 flags, D_802A2034 position,
 * D_802A2058/60 velocity X/Z, D_802A20BC scale,
 * D_802A20E4/ E5 active/type, D_802A20F0 sprite image,
 * D_802A2100/102 sprite scale X/Y, D_802A2105/106/107 sprite RGB.
 * D_801F1D84 is the 16-byte sprite descriptor table indexed by particle type.
 * Keep those global declarations unchanged: their aliasing affects scheduling.
 *
 * Pooled doubles at D_8010BD18+4 / D_8010BD20+4 are 0.94 / 0.5.
 * D_8010BD2C/30/34/38 are sway divisor/amplitude/base size/impulse:
 * 10, 7, 32, 0.7.
 */
typedef struct PooledParticle {
    /* 0x000 */ u8 unk000[0x24];
    /* 0x024 */ s16 lifetime;
    /* 0x026 */ s16 unk026;
    /* 0x028 */ s32 flags;
    /* 0x02C */ u8 unk02C[8];
    /* 0x034 */ f32 position[3];
    /* 0x040 */ u8 unk040[0x18];
    /* 0x058 */ f32 velocity[3];
    /* 0x064 */ u8 unk064[0x58];
    /* 0x0BC */ f32 scale[3];
    /* 0x0C8 */ u8 unk0C8[0x1C];
    /* 0x0E4 */ u8 active;
    /* 0x0E5 */ u8 type;
    /* 0x0E6 */ u16 initialLifetime;
    /* 0x0E8 */ u8 spriteLinks[8];
    /* 0x0F0 */ s32 spriteImage;
    /* 0x0F4 */ f32 spritePosition[3];
    /* 0x100 */ s16 spriteScaleX;
    /* 0x102 */ s16 spriteScaleY;
    /* 0x104 */ u8 unk104;
    /* 0x105 */ u8 red;
    /* 0x106 */ u8 green;
    /* 0x107 */ u8 blue;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 spriteFlags; /* flags byte of the sprite node at 0x0E8 */
    /* 0x10A */ u8 unk10A[0xA];
    /* 0x114 */ u16 scaleParam0;
    /* 0x116 */ u16 scaleParam1;
    /* 0x118 */ u8 unk118[8];
} PooledParticle; /* size = 0x120 */

/* func_801B6370 loads numbered particle images and initializes the pool.
 * D_801F1B24: image sequences; D_801F1B2A/2C: fixed-count/name field aliases.
 * D_801F1B14/18 are one stride before the image/count fields: only accessed
 * for sequence indices >= 1 when finding the preceding sequence.
 * D_8010BCE4 = "%s%02d.bmp"; D_8010BCF0 = "SFL_Tex" (allocation label).
 * D_8029FA80: 120 physics blocks, each 0x50 bytes.
 * D_802A2020/28: object type/flags; D_802A20E8: sprite list link.
 * D_801ED3D0: identity quaternion (0, 0, 0, 1).
 * Defaults D_8010BCF8/FC/BD00/04/08/0C = 1, 0.7, 10, 0.9, 0.2, 0.1.
 * func_801D2150 formats a string; func_80139CA0 hashes it with CRC32;
 * func_8014FCF8 finds a texture by hash (last argument reports missing assets);
 * func_8013FCDC allocates aligned game memory; func_8013FBC0 clears bytes.
 */
typedef struct ParticleImageSequence {
    /* 0x00 */ s32 images; /* Address of the allocated texture-pointer slice. */
    /* 0x04 */ s16 imageCount;
    /* 0x06 */ s16 fixedCount; /* Nonzero skips automatic image counting. */
    /* 0x08 */ u8 name[8];
} ParticleImageSequence; /* size = 0x10 */

/* func_8010EBE8 (resetSceneResources) releases scene allocations, resets
 * object lists and the heap, then reloads the common model bank.
 * Its local ListNode is only the +0 next-pointer prefix of each list element.
 * D_8028F82C uses 0x10-byte bank records: allocation at +0, count at +4,
 * item pointer at +8 (also D_8028F834), unknown word at +0xC.
 * Each 8-byte item has a name hash at +0 and model address at +4.
 * D_8028F7DC is the allocation field of 0x0C-byte texture-bank records.
 * D_801F1B24 is the ParticleImageSequence array described above.
 * func_8011FF08 releases a screen sprite's subordinate allocations.
 * func_8014A9D8 / func_8014ABEC reset the two sprite-list sentinels.
 * func_80162694 recursively frees model-node geometry allocations.
 * func_801627AC releases an object's owned data; func_80141720 frees a handle.
 * func_8010F94C releases the tracked model allocations.
 * func_8015C758 resets render lists; func_8011C810 releases an object list.
 * func_8011FD80 resets scene subsystem lists; func_80141874 dumps heap usage.
 * func_8013FC38 resets the heap region; func_80150EA4 loads a model bank.
 * func_8012A738 sets transition RGB; func_80122F9C updates transition extent.
 * D_801E753C / D_801E753E are current / target transition extent.
 * D_802004E0 is the state frame counter; D_802B0D10 begins the game heap.
 * N64 symbol renames are unavailable; preserve the address names.
 */
/* func_80151FD0 (findModelByNameHash) searches the loaded model banks.
 * The output and optional name parameters carry addresses in s32 values.
 * D_8028F82C is the bank allocation view; D_8028F834 aliases its item pointer.
 * D_8028F828 supplies an unused word at the same 0x10-byte bank stride.
 * func_801D2150 is sprintf; func_80139D70 is an empty diagnostic sink.
 * D_8025D578 is the diagnostic buffer, D_801E7544 the error-screen message,
 * and D_801E7530 the game state. func_80155A44 stops drawing.
 * Original strings: D_80106D60 = "Object '%s' not found\n",
 * D_80106D78 = "LEVEL UNPLAYABLE - %s MISSING",
 * D_80106D98 = "Whoops, object '%X' not found!\n",
 * D_80106DB8 = "LEVEL UNPLAYABLE - OBJECT MISSING",
 * D_80106DDC = "fondobj" (drawing-stop diagnostic tag).
 */
typedef struct SceneModelEntry {
    /* 0x00 */ s32 nameHash;
    /* 0x04 */ s32 modelAddress;
} SceneModelEntry; /* size = 0x08 */

/* func_80152330: findModelNodeInLoadedBanks searches every loaded bank's
 * model tree for a name hash, returning the node address or zero through out.
 * func_80152220: findModelNodeByNameHash recursively visits child then sibling.
 * Model addresses refer to ActorModelContainer; ACTOR_MODEL_ROOT_WORD holds
 * the tree root. D_80106D98 is the missing-object hash diagnostic format.
 */
typedef struct SceneModelBank {
    /* 0x00 */ s32 allocation;
    /* 0x04 */ s32 count;
    /* 0x08 */ SceneModelEntry *items;
    /* 0x0C */ s32 unk00C;
} SceneModelBank; /* size = 0x10 */

/* Vertex-position view of a model mesh (func_80151EC0: mesh bounding radius). */
typedef struct MeshVertexPos {
    f32 x, y, z;
} MeshVertexPos;

typedef struct MeshVertexView {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 vertexCount;
    /* 0x04 */ MeshVertexPos *vertices;
} MeshVertexView;

/* Geometry block a model tree node points at; +0x14 is its heap allocation handle. */
typedef struct ModelNodeGeometry {
    /* 0x00 */ u8 pad000[0x14];
    /* 0x14 */ s32 allocation;
} ModelNodeGeometry;

/* Model tree node as seen by the name-hash search: first child and next sibling.
 * func_80162694 (modelTreeFreeGeometry) frees each node's geometry allocation. */
typedef struct ModelTreeNode {
    /* 0x00 */ s32 nameHash;
    /* 0x04 */ u8 pad004[0x10];
    /* 0x14 */ ModelNodeGeometry *geometry;
    /* 0x18 */ u8 pad018[0x1C];
    /* 0x34 */ struct ModelTreeNode *child;
    /* 0x38 */ struct ModelTreeNode *sibling;
} ModelTreeNode;

/* func_8011CAF8: resetSceneResourcesAndCameras.
 * func_801C0A2C / func_801C0B00 stop / count channels by category.
 * func_80155A44 stops drawing; D_80100E28 is its caller diagnostic tag.
 * func_80145E30 removes text; func_8014F38C frees animated texture data;
 * func_801456DC reloads font textures; func_80162BE0 initializes cameras.
 * D_8028D9C0 / D_8028F350 are sprite-list sentinels; D_8028F354 aliases
 * the latter's previous link. func_8014A9D8 / func_8014A9FC reset them.
 * D_8028F8E0 / D_8028F9CC hold the camera objects.
 * Model records point to their geometry hierarchy at offset 0x0C.
 */
enum SceneAudioStopConstants {
    SCENE_AUDIO_MUSIC = 1,
    SCENE_AUDIO_EFFECTS = 2,
    SCENE_AUDIO_ALL = 3,
    SCENE_AUDIO_STOP_TICKS = 1
};

enum SceneResourceResetConstants {
    SCENE_MODEL_GEOMETRY_OFFSET = 0x0C,
    SCENE_MODEL_BANK_COUNT = 5,
    SCENE_TEXTURE_BANK_COUNT = 5,
    SCENE_TEXTURE_BANK_STRIDE = 0x0C,
    SCENE_RESET_TRANSITION_EXTENT = 300,
    SCENE_COMMON_MODEL_BANK = 0,
    SCENE_HEAP_END = 0x80400000
};

enum ParticleInitConstants {
    PARTICLE_IMAGE_SEQUENCE_COUNT = 38,
    PARTICLE_IMAGE_SEQUENCE_STRIDE = 0x10,
    PARTICLE_OBJECT_PREFIX_SIZE = 0xE4,
    PARTICLE_PHYSICS_STRIDE = 0x50,
    PARTICLE_OBJECT_TYPE = 3,
    PARTICLE_INITIAL_FLAGS = 5,
    PARTICLE_QUATERNION_OFFSET = 0x9C
};

enum ParticlePoolConstants {
    PARTICLE_POOL_CAPACITY = 120,
    PARTICLE_POOL_STRIDE = 0x120,
    PARTICLE_POSITION_OFFSET = 0x34,
    PARTICLE_SPRITE_POSITION_DELTA = 0xC0,
    PARTICLE_SPRITE_DESCRIPTOR_SIZE = 16,
    PARTICLE_SKIP_PHYSICS = 0x800000,
    PARTICLE_SIMPLE_EXPIRY = 0x2000,
    PARTICLE_SHRINKING_BURST = 4,
    PARTICLE_TRAIL_SOURCE = 13,
    PARTICLE_SWAYING = 20,
    PARTICLE_TRAIL = 22,
    /* D_801F1F14 (type table field 0x10): the type a particle turns into when
     * it expires; this value means "none, free the slot". */
    PARTICLE_NO_SUCCESSOR = 0x18,
    PARTICLE_TYPE_TABLE_STRIDE = 0x14,
    /* object free mask passed to func_801625F0 for an expired particle */
    PARTICLE_FREE_MASK = 0x1E
};

/* Field views of the 0x14-byte particle type table; each symbol starts at
 * its own field, so replacing these with one table would change addressing. */
typedef struct ParticleTypeFlagsField {
    /* 0x00 */ s32 v; /* Object flags. */
    /* 0x04 */ s32 p[4];
} ParticleTypeFlagsField; /* stride = 0x14 */

typedef struct ParticleTypeLifetimeField {
    /* 0x00 */ u16 v; /* Base lifetime in frames. */
    /* 0x02 */ u8 p[18];
} ParticleTypeLifetimeField; /* stride = 0x14 */

typedef struct ParticleTypeLifetimeRangeField {
    /* 0x00 */ s16 v; /* Exclusive upper bound for random extra frames. */
    /* 0x02 */ u8 p[18];
} ParticleTypeLifetimeRangeField; /* stride = 0x14 */

typedef struct ParticleTypeFloatField {
    /* 0x00 */ f32 v; /* Radius or response factor, depending on the symbol. */
    /* 0x04 */ s32 p[4];
} ParticleTypeFloatField; /* stride = 0x14 */

/* func_80175560: ball_spawn_trail_source. Creates a type-13 particle with
 * the ball's physics, radii and response, owned by the player.
 * D_802900F0 tracks the particle; D_8029F9AC is ball XYZ; D_801ED3C4 is
 * zero XYZ; D_8029FA48 points to the ball's 0x50-byte physics block;
 * D_8029FA50 points to its collision data; D_8029F9A0 holds ball flags;
 * D_8029F9E8 is its response factor; D_802902D8 is the player object.
 * D_802903AC points to player state (s16 at +4). State 11 selects orange
 * RGB D_801EF46C/D/E = 255/128/0; otherwise D_801EF46F/470/471 = 255/255/255.
 * D_801EF468 initially equals 1 and enables the extra 0x80 flag.
 * func_801B66D4 allocates/initializes a particle and may return zero.
 * Preserve the existing volatile declarations and integer-address accesses. */
typedef struct BallTrailPhysicsChunk {
    /* 0x00 */ s32 words[4];
} BallTrailPhysicsChunk; /* size = 0x10; copied five times */
typedef struct BallTrailCollisionRadii {
    /* 0x00 */ u8 pad0[0x70];
    /* 0x70 */ f32 radius;
    /* 0x74 */ f32 targetRadius;
} BallTrailCollisionRadii; /* prefix size = 0x78 */

enum BallTrailConstants {
    BALL_TRAIL_PHYSICS_BYTES = 0x50,
    BALL_TRAIL_OPTIONAL_FLAG = 0x80,
    BALL_TRAIL_REQUIRED_FLAG = 0x40000000,
    BALL_TRAIL_OWNER_OFFSET = 0x2C,
    BALL_TRAIL_PLAYER_STATE_OFFSET = 4,
    BALL_TRAIL_ORANGE_PLAYER_STATE = 11
};

/* func_801AE348: spawnBlueParticlePair(position). Spawns types 9 and 11,
 * tinting the first blue; both start at four times their normal sprite scale
 * and interpolate to half their normal end scale over six frames.
 * func_801B66D4 is spawn_particle; D_801ED3C4 starts the zero velocity vector.
 * D_8010B548 / D_8010B558 are f64 0.5 end-scale multipliers.
 * D_8010B550 / D_8010B560 are f64 2^31 unsigned-conversion thresholds.
 * SpriteAnimationState is embedded at +0x10C in PooledParticle.
 */
enum BlueParticlePairConstants {
    BLUE_PARTICLE_PAIR_FIRST_TYPE = 9,
    BLUE_PARTICLE_PAIR_SECOND_TYPE = 11,
    BLUE_PARTICLE_PAIR_GREEN = 160,
    BLUE_PARTICLE_PAIR_SCALE_SHIFT = 2,
    BLUE_PARTICLE_PAIR_LIFETIME = 12,
    BLUE_PARTICLE_PAIR_SPRITE_LIFETIME = 6,
    PARTICLE_SPRITE_LIFETIME_OFFSET = 0x11A,
    PARTICLE_SPRITE_REMAINING_LIFE_OFFSET = 0x11C
};

enum ParticleSpawnConstants {
    PARTICLE_FIXED_IMAGE_TYPE = 23,
    PARTICLE_DISTANCE_EXEMPT_LEVEL = 40,
    PARTICLE_COLLISION_FLAGS = 0x18,
    PARTICLE_ALLOC_COLLISION = 2,
    PARTICLE_ALLOC_TRAIL_COMPONENTS = 0x18,
    PARTICLE_DEFAULT_UNK26 = 100,
    PARTICLE_COLOR_WHITE = 255
};

/* func_801BB5C4: spawn_warm_colored_particle(position, velocity, scale).
 * Position and velocity are Vec3F addresses passed in s32 argument slots.
 * func_801B66D4 allocates a PooledParticle; func_80147000 chooses its tint.
 * D_801F20F4/20F5/20F6 alias the R/G/B bytes of five packed RGB colors:
 * (253,173,41), (255,210,5), (254,141,30), (251,227,21), (255,106,17).
 * SpriteAnimationState at +0x10C supplies startScale/endScale at +0x114/116.
 * D_8010BF38/3C are f32 2^31 thresholds for the two unsigned conversions.
 */
enum WarmParticleConstants {
    WARM_PARTICLE_TYPE = 21,
    WARM_PARTICLE_COLOR_COUNT = 5,
    WARM_PARTICLE_RGB_STRIDE = 3
};

/* Byte offsets retain the original access widths and pointer arithmetic. */
enum ParticleSpawnOffset {
    PARTICLE_OBJECT_ACTIVE_OFFSET = 0x22,
    PARTICLE_LIFETIME_OFFSET = 0x24,
    PARTICLE_UNK26_OFFSET = 0x26,
    PARTICLE_FLAGS_OFFSET = 0x28,
    PARTICLE_RADIUS_OFFSET = 0x30,
    PARTICLE_PREVIOUS_POSITION_OFFSET = 0x40,
    PARTICLE_VELOCITY_OFFSET = 0x58,
    PARTICLE_VELOCITY_Y_OFFSET = 0x5C,
    PARTICLE_RESPONSE_OFFSET = 0x70,
    PARTICLE_PITCH_OFFSET = 0x78,
    PARTICLE_YAW_OFFSET = 0x7C,
    PARTICLE_ROLL_OFFSET = 0x80,
    PARTICLE_SCALE_X_OFFSET = 0xBC,
    PARTICLE_SCALE_Y_OFFSET = 0xC0,
    PARTICLE_SCALE_Z_OFFSET = 0xC4,
    PARTICLE_MODEL_OFFSET = 0xC8,
    PARTICLE_PHYSICS_OFFSET = 0xD0,
    PARTICLE_COLLISION_OFFSET = 0xD8,
    PARTICLE_ACTIVE_OFFSET = 0xE4,
    PARTICLE_TYPE_OFFSET = 0xE5,
    PARTICLE_INITIAL_LIFETIME_OFFSET = 0xE6,
    PARTICLE_SPRITE_OFFSET = 0xE8,
    PARTICLE_IMAGE_OFFSET = 0xF0,
    PARTICLE_SPRITE_POSITION_OFFSET = 0xF4,
    PARTICLE_RED_OFFSET = 0x105,
    PARTICLE_GREEN_OFFSET = 0x106,
    PARTICLE_BLUE_OFFSET = 0x107,
    PARTICLE_SPRITE_ORIGIN_X_OFFSET = 0x10A,
    PARTICLE_SPRITE_ORIGIN_Y_OFFSET = 0x10B,
    PARTICLE_IMAGE_TABLE_OFFSET = 0x10C,
    PARTICLE_SPRITE_ANIMATION_MODE_OFFSET = 0x111,
    PARTICLE_IMAGE_INDEX_OFFSET = 0x11E,
    PARTICLE_PHYSICS_RESPONSE_OFFSET = 0x18,
    PARTICLE_COLLISION_RADIUS_OFFSET = 0x70,
    PARTICLE_COLLISION_TARGET_RADIUS_OFFSET = 0x74,
    PARTICLE_IMAGE_WIDTH_OFFSET = 0xC,
    PARTICLE_IMAGE_HEIGHT_OFFSET = 0xE
};

/*
 * func_801B66D4: spawn_particle(type, position, velocity, insertAfter, reuseSlot).
 * Returns the slot address, or zero if disabled, culled or the pool is full.
 * IDs >= 23 share type 23 and select image frame (ID - 23).
 * func_80148EBC: squared 3D distance; func_80160E80: horizontal facing test.
 * func_80147000: bounded random integer; func_8014B7F0: initialize sprite
 * animation; func_8014AC1C: insert sprite after a list node (zero selects
 * the default list); func_80142700: allocate selected object components.
 *
 * D_801F1B20: particle spawning disabled (initially zero).
 * D_8028F914: camera position; D_8028F8E0: object used for the facing test.
 * D_801F1F04/08/0A/0C/10: flags, base lifetime, lifetime range, radius,
 * response factor; each field has a 0x14-byte stride.
 * Type zero contains flags 0, lifetime 20, range 0, radius 5, response 0.7.
 * D_801F1D84: four-word sprite descriptors, indexed by particle type.
 * D_8010BD10: squared culling distance 2250000 (1500 units).
 * D_8010BD14: fixed-image particle vertical velocity 1.
 * D_8010BD18: initial XYZ scale 1.
 */

/*
 * func_8012BEE0 initializes the title flythrough.
 * D_80101954: drawing-stop tag "setflythru"; D_80101960: "glover.bmp".
 * D_8010196C: prompt scale (1); D_80101970/74: warning X/Y scales (0.6/1).
 * D_801EAB30: English/French/German "PRESS START" pointers.
 * D_801EAB3C/40/44: English/French/German controller-disconnected pointers.
 * D_801ED62C: primary text object; D_801ED630/634: French/German warnings.
 * D_801EC749: controller 1 connected; D_801E7586: language index.
 * D_801EAB24: selected save slot (slot 6 is used for this flythrough).
 * func_80155A44 stops drawing; func_8011FF40 initializes a level.
 * func_8014A50C initializes and inserts a bitmap sprite.
 * func_801469E4 creates text (x, y, RGBA, scale X/Y, mode, string, flags).
 */
/*
 * func_801145A4: attract_start_next_scene; cycles through five recorded
 * gameplay demos, then the title flythrough (func_8012BEE0).
 * D_801E662C: next attract scene index; D_801EC7F0: input recording mode.
 * D_801EAB24: selected save slot; D_801EAAFD: difficulty byte of slot 6
 * (D_801EAA55 + 6 * LEVEL_SAVE_SLOT_BYTES).
 * D_801F21A8: cheat notification frame counter.
 * D_801E5894: enable menu transitions; D_801ED3BC: global text scale.
 * D_801005D8: drawing-stop caller label; D_801005DC: attract text scale.
 * func_80155A44: stop drawing and wait for the render worker.
 * func_8012C2B0: fill bytes; D_80092030/D_800B7830: framebuffers.
 * func_8010EBE8: release scene resources and reset the scene heap.
 * func_801BB9AC: execute/toggle a cheat (second argument shows notification).
 * func_8011F9F4: reset new-game progress; func_8011FF40: initialize a level.
 */
enum AttractCycleConstants {
    ATTRACT_SAVE_SLOT = 6,
    ATTRACT_DIFFICULTY = 1,
    ATTRACT_TITLE_SCENE = 5,
    ATTRACT_SCENE_COUNT = 6,
    CHEAT_RESET_ALL = 22,
    INPUT_MODE_LIVE = 0
};

enum TitleFlythroughConstants {
    TITLE_FLYTHROUGH_SAVE_SLOT = 6,
    TITLE_FLYTHROUGH_LEVEL = 44,
    TITLE_FLYTHROUGH_LOGO_X = 165,
    TITLE_FLYTHROUGH_LOGO_Y = 40,
    TITLE_FLYTHROUGH_LOGO_PRIORITY = 2,
    TITLE_FLYTHROUGH_TEXT_X = 160,
    TITLE_FLYTHROUGH_PROMPT_Y = 200,
    TITLE_FLYTHROUGH_WARNING_ENGLISH_Y = 150,
    TITLE_FLYTHROUGH_WARNING_FRENCH_Y = 180,
    TITLE_FLYTHROUGH_WARNING_GERMAN_Y = 210,
    TITLE_FLYTHROUGH_EXIT_FRAME = 0x929,
    TITLE_FLYTHROUGH_EXIT_SOUND = 0x3B,
    TITLE_FLYTHROUGH_EXIT_VOLUME = 100,
    TITLE_FLYTHROUGH_EXIT_PAN = 128,
    TITLE_FLYTHROUGH_EXIT_PITCH_TEMPO = 190,
    TITLE_FLYTHROUGH_EXIT_TRANSITION = 15
};

/*
 * func_8012BCA8 starts the recorded intro cutscene (level 43, played back
 * from save slot 6); func_8012BD44 scripts it per frame.
 * D_801EC748: scene active flag; D_8028FB7C: cutscene event flag.
 */
enum IntroCutsceneConstants {
    INTRO_CUTSCENE_SAVE_SLOT = 6,
    INTRO_CUTSCENE_LEVEL = 0x2B,
    INTRO_CUTSCENE_MUSIC = 0x3B
};

/*
 * func_8012C124: title_flythrough_update; follows the first actor and exits
 * on menu input once transitions clear, or at frame 2345, with controller 1.
 * func_801399EC: controller_has_menu_button_input (three button fields).
 * func_801793DC: sound_play_with_pitch_tempo (sound, volume, pan, scale).
 * func_80128DF8: game_request_transition (reason, flag, flag).
 * D_8028FAC8: camera target position pointer; D_8029971C: actor 0 position.
 * D_802004E0: state frame counter; D_80202218: active controller index.
 * D_80101978/7C: lower threshold 20 and inactive sentinel -1 (f32).
 * D_80101980: motion increase 0.75 (f64).
 * D_80101988: upper threshold 40 (f32), followed by decrease 0.2 (f64).
 * D_80101994: motion scale divisor 2 (f32), undoing the title setup's doubling.
 * D_802997B4 and D_80299744 retain unknown field names; this update compares
 * the pointed-to value against those thresholds and adjusts D_80299744.
 */

/* Title-screen choices and timings; input uses a 400-byte controller stride. */
enum TitleMenuChoice {
    TITLE_MENU_START = 0,
    TITLE_MENU_PRACTICE = 1,
    TITLE_MENU_OPTIONS = 2
};

enum TitleMenuConstants {
    TITLE_MENU_TEXT_CAPACITY = 14,
    TITLE_MENU_REDRAW_TEXT_COUNT = 11,
    TITLE_MENU_SELECTION_UNDRAWN = 999,
    TITLE_MENU_REPEAT_DELAY = 10,
    TITLE_MENU_CONFIRM_DELAY = 200,
    TITLE_MENU_STICK_UP_THRESHOLD = 51,
    TITLE_MENU_STICK_DOWN_THRESHOLD = -50,
    TITLE_MENU_VERSION_Y = 25,
    TITLE_MENU_CENTER_X = 160,
    TITLE_MENU_START_Y = 140,
    TITLE_MENU_PRACTICE_Y = 170,
    TITLE_MENU_OPTIONS_Y = 200,
    TITLE_MENU_SCENE = 7,
    TITLE_MENU_PRACTICE_LEVEL = 46
};

/* func_801B182C follows the ball with the player (player_follow_ball).
 * func_801B1B4C computes two targets: one behind the player's facing
 * direction, one along the ball's travel direction. Its result is true
 * when the ball is stationary or moving near the player's facing direction.
 * D_8029030C/310/314: player XYZ; D_80290334: player vertical velocity.
 * D_8029F9D0/D8: ball X/Z velocity; D_8029F9B0: ball Y.
 * D_801F1AE8 / D_801F1AEC: current / target follow blend (initially 0.3).
 * D_801FAA94: controller stick magnitude; D_80202218 selects the controller.
 * D_80290300: player flags. D_80290090 is a contact-object reference
 * whose presence bypasses follow smoothing; its broader purpose is unknown.
 * D_802903AC: player state; D_8029FA50: ball collision state.
 * D_8029F487 selects the ball form (form 4 bypasses the height clamp).
 * Pool floats D_8010B8D0/DC/F0 = 1 (full follow), D_8010B8D4 = 100
 * and D_8010B8D8 = 2 (stick scaling), D_8010B8E0 = 4 (blend smoothing).
 * D_8010B8E0+4 holds f64 0.3; D_8010B8EC holds f32 0.3 (minimum blend).
 */
/*
 * func_801B1580: player_can_land_on_ball; func_80148DB0: vec3_distance_xz.
 * D_8029030C / D_8029F9AC: player / ball position; D_80290310 / D_8029F9B0:
 * their Y components. D_80290308 is player radius; D_80290334 is Y velocity.
 * D_8029F9A0: ball object flags; D_8028FBEA: elapsed player-state frames.
 * D_802903AC / D_8029FA4C: player / ball action state; +0xC holds a teleport.
 * D_8029FA50: BallCollisionState; sphere zero's radius is at +0x70.
 * Collision byte +0x188 counts contacts. State byte +9 allows a ball without
 * contacts and increases the vertical tolerance; its full meaning is unknown.
 * D_8029010A records player/ball contact; it permits the swept-height test.
 * D_802901D4 is power-up 14's active timer; D_8029F486 is ball status.
 * D_8010B8B8: horizontal radius multiplier; D_8010B8C0: vertical tolerance;
 * D_8010B8C8: extra vertical tolerance for state byte +9 (all f64).
 * D_801EFCFC and D_8029F5C4 are additional eligibility gates, still unnamed.
 * Keep raw accesses and existing global types: they preserve alias scheduling.
 */
/* func_80174B58: player_can_catch_ball. func_80148E48 measures XYZ
 * distance and func_80148DB0 measures XZ distance.
 * D_802902D8 is the player object; D_8029F9A4 is the ball's support.
 * D_8029F468 is the ball recovery timer; D_8029F486 is ball status.
 * D_80290300 / D_8029F9A0 hold player / ball object flags.
 * D_802903AC / D_8029FA4C point to their action states; byte +9 is
 * still only partially understood. D_8029FA50 is ball collision state.
 * D_8029030C/310 and D_8029F9AC/B0 are player and ball position X/Y;
 * D_80290308 / D_8029F9A8 are their radii; D_8029F9D4 is ball Y velocity.
 * D_8029F482 >= 50 enables the proximity test, including while rising.
 * D_80108328+4 holds f64 2.5 (words 0x40040000, 0): catch-radius scale.
 * Retain raw accesses to preserve the existing alias and address arithmetic.
 */
enum BallCatchConstants {
    PLAYER_ACTION_CATCH_BALL = 31,
    PLAYER_CATCH_BLOCKING_FLAG = 0x8000,
    BALL_CATCH_STATE_CHECK_FLAG = 0x200000,
    BALL_CATCH_PROXIMITY_THRESHOLD = 50,
    BALL_CATCH_ENTER_RADIUS = 20,
    BALL_CATCH_CONTINUE_RADIUS = 30,
    BALL_CATCH_MIN_HEIGHT = 20,
    BALL_CATCH_RADIUS_SCALE_POOL_OFFSET = 4,
    BALL_POSITION_FROM_VELOCITY_Y_FLOATS = 10
};

/*
 * func_8017723C: player_has_nearby_grounded_ball.
 * D_8029F9A4 is the ball support/owner; D_8029F486 is ball status.
 * D_802903B0 / D_8029FA50 point to player / ball collision state:
 * the first four pointers are contact planes, and byte +0x188 counts contacts.
 * D_8029030C/310/314 and D_8029F9AC/9B0/9B4 are player and ball XYZ.
 * func_80148EBC returns squared 3D distance; D_80108554 is its 1600
 * threshold (40 units squared), verified in asm/1000.s.
 * Keep the raw accesses and existing global types for matching.
 */
enum BallGroundProximityConstants {
    BALL_GROUND_PROXIMITY_PLANE_COUNT = 4,
    BALL_POSITION_FROM_SUPPORT_WORDS = 2
};

enum BallLandingOffsets {
    BALL_LANDING_ACTION = 4,
    BALL_LANDING_STATE_BYTE_9 = 9,
    BALL_LANDING_TELEPORT = 0xC,
    BALL_LANDING_RADIUS = 0x70,
    BALL_LANDING_CONTACT_COUNT = 0x188
};

enum BallLandingConstants {
    BALL_LANDING_COLLIDABLE_FLAG = 8,
    BALL_LANDING_MIN_STATE_FRAMES = 2
};

enum PlayerBallFollowConstants {
    PLAYER_BALL_FOLLOW_SNAP_FLAG = 0x2000,
    PLAYER_BALL_FOLLOW_HEIGHT_CLAMP_STATE = 3,
    PLAYER_BALL_FOLLOW_UNCLAMPED_FORM = 4,
    PLAYER_BALL_FOLLOW_STATE_OFFSET = 4,
    PLAYER_BALL_FOLLOW_PITCH_AXIS = 0
};

/* Ball-follow target construction (func_801B1B4C):
 * D_80290350/354: player pitch/yaw; D_80290394: player X scale.
 * D_8029F9AC/B0/B4: ball position; D_8029F9B8/BC/C0: previous position.
 * D_801EEC40: level-dependent physics scale (normally 0.05).
 * D_802901AC enables a raised, closer follow target; its wider role is unknown.
 * func_8014915C rotates Vec3F about axis 0/1/2 (X/Y/Z).
 * func_801490AC rotates Vec3F about Y; func_80147460 is table-based atan2.
 * func_801496C8 wraps an angle by at most one turn into [0, 2*pi];
 * func_8014944C returns the shortest unsigned angle difference.
 * Literal-pool doubles at B8F0+4/B8F8+4/B900+4/B908+4 are respectively
 * radius bias 9, radius-delta floor -5, minimum distance factor
 * -1999.9999999999995, and radius divisor 0.0025000000000000005.
 * B910+4 caps player scale at 0.05; B918+4 gives minimum height 9.
 * D_8010B924 is f32 2 (distance adjustment), D_8010B928 is f64 pi,
 * and D_8010B930 is f32 1 (forward-travel angle tolerance, radians).
 * Pool symbols retain their byte-array views and offsets for matching.
 */

/*
 * Controller initialization (func_80133E60, init_controllers):
 * func_801C6520 / func_801C7690 / func_801CF8C0 are osCreateMesgQueue,
 * osSetEventMesg and osContInit. func_80132DFC busy-waits 20 ms; its
 * argument is unused.
 * D_801FA9F0 / D_801FB264: initialization SI queue / its message slot.
 * D_801FAA08: four OSContStatus records (u16 type, u8 status, u8 errno).
 * D_801FAA0B: errno field of the first status record.
 * D_801FB268 / D_801FAA20: runtime SI queue / eight message slots.
 * D_801FAB70: button press ages, in frames, with 0x190-byte controller stride.
 * D_801FABA8: connected flag with the same controller stride.
 * D_801EC749: controller zero connected flag.
 */
/* func_80132DFC (busy_wait_20ms) ignores its delay argument.
 * func_801C7080 is osGetTime; D_801F43D0 is osClockRate in ticks/second.
 * Convert the 64-bit timer to microseconds before measuring the delay. */
enum BusyWaitConstants {
    BUSY_WAIT_MICROSECONDS_PER_SECOND = 1000000,
    BUSY_WAIT_DURATION_USEC = 20000
};

enum ControllerInitConstants {
    CONTROLLER_COUNT = 4,
    CONTROLLER_INPUT_COUNT = 14,
    CONTROLLER_PRESS_AGE_INITIAL = 999999,
    CONTROLLER_ERROR_NO_RESPONSE = 8,
    CONTROLLER_SI_EVENT = 5,
    CONTROLLER_SI_QUEUE_CAPACITY = 8
};

/* Field views preserve the original independent global declarations. */
typedef struct ControllerButtonPressAges {
    /* 0x000 */ s32 framesSincePress[14];
    /* 0x038 */ s32 unk038;
    /* 0x03C */ u8 pad03C[400 - 0x3C];
} ControllerButtonPressAges; /* stride = 0x190 */

typedef struct ControllerStatusErrorField {
    /* 0x0 */ u8 error;
    /* 0x1 */ u8 pad1[3];
} ControllerStatusErrorField; /* stride = 0x04 */

typedef struct ControllerConnectedField {
    /* 0x000 */ s32 connected;
    /* 0x004 */ u8 pad004[396];
} ControllerConnectedField; /* stride = 0x190 */

/* Field view at D_801FAA94, with the controller record's 0x190-byte stride. */
typedef struct ControllerStickMagnitudeField {
    /* 0x000 */ f32 magnitude;
    /* 0x004 */ u8 pad004[396];
} ControllerStickMagnitudeField; /* size = 0x190 */

/* View beginning at D_801FAA92, the Y-stick field of controller zero.
 * Preserve existing global declarations; cast individual accesses to this view. */
typedef struct ControllerStickYView {
    /* 0x000 */ s16 stickY;
    /* 0x002 */ u8 unk002[398];
} ControllerStickYView; /* stride = 0x190 */

/*
 * Level-select data views:
 * D_801E6910 entries have stride 0x38, a name at +0, and music ID at +0x35
 * (also addressed through D_801E6945).
 * D_801FAA92 supplies signed Y-stick values; D_801FAAC8 supplies the
 * music-preview button byte. Both controller field arrays have stride 0x190.
 */
enum LevelSelectConstants {
    LEVEL_SELECT_SAVE_SLOT = 6,
    LEVEL_SELECT_SAVE_SLOT_BYTES = 28,
    LEVEL_SELECT_TEXT_CAPACITY = 14,
    LEVEL_SELECT_REDRAW_TEXT_COUNT = 11,
    LEVEL_SELECT_SELECTION_UNDRAWN = 999,
    LEVEL_SELECT_LEVEL_COUNT = 42,
    LEVEL_SELECT_VISIBLE_RADIUS = 3,
    LEVEL_SELECT_LINE_HEIGHT = 17,
    LEVEL_SELECT_CENTER_X = 160,
    LEVEL_SELECT_LIST_Y_OFFSET = 55,
    LEVEL_SELECT_ENTRY_STRIDE = 0x38,
    LEVEL_SELECT_STICK_UP_THRESHOLD = 51,
    LEVEL_SELECT_STICK_DOWN_THRESHOLD = -50,
    LEVEL_SELECT_CONFIRM_DELAY = 200,
    LEVEL_SELECT_MUSIC_VOLUME = 20000
};

/*
 * func_801AB88C updates the type-28 spider bomb (spiderbomb.ndo in the
 * effect table at D_801F1830): face the player while waiting, then scale
 * animation speed and sound with movement, emit a trail, and damage on contact.
 * The effect embeds its object at +8 and a PositionalSound at +0x168.
 * Its animation pointer refers to ActorAnimation; speed is at +0x0C.
 * Collision state starts with contact-normal pointers; byte +0x54 marks an
 * upward-facing first contact. The field at effect +0x70 drives impact volume.
 * The sprite at +0xEC uses scales at +0x18/+0x1A, animation step at +0x28,
 * and start/end scales at +0x2C/+0x2E.
 *
 * func_801AA5BC allocates an effect by type; func_801A96A8 initializes it.
 * func_80149428 subtracts X/Z vectors; func_80149604 normalizes X/Z.
 * func_80148C3C converts axis-angle to quaternion; D_801ED3E0..EC is the
 * shared Y-axis angle (0, 1, 0, angle). func_80133998 starts an animation.
 * func_80147000 is bounded random; func_80178134 plays positional audio;
 * func_801785E0 starts a tracked sound; func_801C0D40 changes pitch bend.
 * func_80148DB0 measures X/Z distance; func_801743A8 damages the player;
 * func_801B9894 configures screen shake.
 * D_8029F210 is the effect-list head; D_8029F394 counts effects.
 * D_801F19B8 counts types 11/25; D_801F19BC counts types 12/28.
 * D_80290308 is the player collision radius; D_8029030C is player position X.
 *
 * Tuning: D_801F18CE = -50 (negated activation delay),
 * D_801F1A58/5C/60 = 4/10/2 (animation divisor, pitch and volume scales).
 * Pool constants: D_8010B3CC/D8 = 8 (impact-volume scale);
 * D_8010B3D0/D4 = 100 (impact-volume caps); D_8010B3D8+4 = pi/2 (f64 yaw);
 * D_8010B3E4/E8 = 159/32 (pitch limit/base), D_8010B3E8+4 = 10 (f64 divisor);
 * D_8010B3F4/F8/FC = 12.7/20/60 (pitch cap, volume base/cap);
 * D_8010B400/404 = 25/7 (trail height/vertical velocity).
 */
/* func_801AA5BC: effect_alloc_from_type. D_801F0330 is the effect
 * definition table (0xC0 bytes per entry); effects embed an ObjectNode at +8.
 * func_8013FCDC allocates tagged, optionally cleared memory;
 * func_80142700 initializes the requested object components.
 * D_8010B364 is the allocation label, D_8010B36C scales shadow size,
 * and D_8010B374 supplies the initial physics unk20 value.
 * Raw offsets preserve the existing access types and aliasing.
 */
enum EffectAllocationConstants {
    EFFECT_ALLOCATION_BYTES = 0x184,
    EFFECT_DEFINITION_BYTES = 0xC0,
    EFFECT_CLEAR_ALLOCATION = 1,
    EFFECT_COLLISION_FLAGS = 0x18,
    EFFECT_OBJECT_TYPE = 4,
    EFFECT_SHADOW_INITIAL_UNK0E = 40,
    EFFECT_NO_ACTOR_INDEX = -1,
    EFFECT_ACTIVE = 1,
    EFFECT_DEF_UNK94 = 0x94,
    EFFECT_DEF_UNK9C = 0x9C,
    EFFECT_DEF_TARGET_FLAGS = 0xA0,
    EFFECT_DEF_OBJECT_FLAGS = 0xA4,
    EFFECT_DEF_PHYSICS_UNK08 = 0xA8,
    EFFECT_DEF_RESPONSE = 0xAC,
    EFFECT_DEF_RADIUS = 0xB0,
    EFFECT_OBJECT_TYPE_OFFSET = 0x28,
    EFFECT_ACTIVE_OFFSET = 0x2A,
    EFFECT_UNK2C_OFFSET = 0x2C,
    EFFECT_RADIUS_OFFSET = 0x38,
    EFFECT_RESPONSE_OFFSET = 0x78,
    EFFECT_SHADOW_SIZE_OFFSET = 8,
    EFFECT_COLLISION_RADIUS_OFFSET = 0x70,
    EFFECT_COLLISION_TARGET_RADIUS_OFFSET = 0x74,
    EFFECT_PHYSICS_UNK20_OFFSET = 0x20
};

enum ActorEffectOffsets {
    EFFECT_OBJECT_OFFSET = 8,
    EFFECT_POSITION_OFFSET = 0x3C,
    EFFECT_POSITION_Y_OFFSET = 0x40,
    EFFECT_POSITION_Z_OFFSET = 0x44,
    EFFECT_VELOCITY_X_OFFSET = 0x60,
    EFFECT_VELOCITY_Y_OFFSET = 0x64,
    EFFECT_VELOCITY_Z_OFFSET = 0x68,
    EFFECT_IMPACT_SOUND_VALUE_OFFSET = 0x70,
    EFFECT_ORIENTATION_OFFSET = 0xA4,
    EFFECT_BEHAVIOR_STATE_OFFSET = 0xDC,
    EFFECT_COLLISION_STATE_OFFSET = 0xE0,
    EFFECT_ANIMATION_OFFSET = 0xE4,
    EFFECT_SPRITE_SCALE_X_OFFSET = 0x104,
    EFFECT_SPRITE_SCALE_Y_OFFSET = 0x106,
    EFFECT_SPRITE_ANIMATION_STEP_OFFSET = 0x114,
    EFFECT_SPRITE_START_SCALE_OFFSET = 0x118,
    EFFECT_SPRITE_END_SCALE_OFFSET = 0x11A,
    EFFECT_AGE_OFFSET = 0x15C,
    EFFECT_TYPE_OFFSET = 0x161,
    EFFECT_SOUND_OFFSET = 0x168,
    EFFECT_SOUND_VOLUME_OFFSET = 0x16C,
    EFFECT_ANIMATION_SPEED_OFFSET = 0x0C,
    EFFECT_FIRST_CONTACT_UPWARD_OFFSET = 0x54
};

/* Byte offsets in the collision state at effect +0xE0 (EFFECT_COLLISION_STATE_OFFSET). */
enum EffectCollisionStateOffsets {
    EFFECT_COLLISION_CONTACT_COUNT = 0x188,
    EFFECT_COLLISION_CONTACT_UNK189 = 0x189
};

/* func_801AB0AC: sound volume ramp while touching something (+40, at most
 * 120) and when not (-10, at least 0). */
enum EffectContactSoundConstants {
    EFFECT_CONTACT_VOLUME_RISE = 0x28,
    EFFECT_CONTACT_VOLUME_MAX = 0x78,
    EFFECT_CONTACT_VOLUME_FALL = 10,
    EFFECT_CONTACT_MIN_AGE = 0x15
};

/* func_801ACBD0 (effect_update_bubble_trail) is the type-10 bubble2.ndo
 * callback. A contact stops translation, initializes a random spin axis and
 * shortens the expiry timer; later contacts reverse the spin angle.
 * It emits particle type 1 at an oriented offset on contact, or at the effect
 * position with scaled effect velocity otherwise.
 * The embedded object starts at +8; its spin axis/angle are at +0xAC/+0xB8.
 * The physics pointer at effect +0xD8 owns an unidentified float at +0x1C.
 * func_80147000 = random_below; func_80149568 = vec3_normalize;
 * func_801499A0 = vec3_rotate_quaternion; func_801B66D4 = particle_spawn.
 * Pool values: D_8010B4EC = (0,4,0), D_8010B4F8 = 1.06 (physics unk1C),
 * D_8010B4FC = 0.2 (spin angle), D_8010B500 = 6 (particle Y velocity),
 * D_8010B504 = 9 (local Z emission offset), D_8010B508 = 1.8 (velocity scale).
 * Keep address symbols until N64 symbol renaming is supported.
 */
/* func_801AC398: effect_update_floating_bubble, the type-12 bubble1.ndo
 * callback. Effects embed an ObjectNode at +8; ActorEffectOffsets and
 * EffectAllocationConstants describe the shared byte offsets.
 * D_801F03B8 is the horizontal-acceleration field at +0x88 of each
 * 0xC0-byte effect definition; D_801F1A7C is the bubble scale (0.277777791).
 * D_802004E0 is the frame counter. Helpers: func_80149724 computes
 * sin((frame + phase) / divisor), func_801490AC rotates a Vec3F about Y,
 * and func_80147000 returns a bounded random integer.
 * Pool values from asm/1000.s: D_8010B460 = 12 (bob time divisor),
 * D_8010B464 = 20 (bob amplitude divisor), D_8010B468 = 1.2 (f64 upward
 * multiplier), D_8010B470 = 100 (turn divisor), D_8010B474 = 1 (speed
 * multiplier base), D_8010B478 = 0.85 (f64 shadow-radius multiplier).
 * Preserve the float-array accesses and double intermediates for matching.
 */
enum FloatingBubbleConstants {
    FLOATING_BUBBLE_TURN_RANGE = 21,
    FLOATING_BUBBLE_TURN_CENTER = 10,
    EFFECT_SCALE_X_OFFSET = 0xC4,
    EFFECT_SCALE_Y_OFFSET = 0xC8,
    EFFECT_SCALE_Z_OFFSET = 0xCC,
    EFFECT_SHADOW_OFFSET = 0xD4
};

enum BubbleEffectConstants {
    BUBBLE_CONTACT_INITIALIZED = 0x01000000,
    BUBBLE_CONTACT_LIFETIME = 20,
    BUBBLE_SPIN_RANDOM_RANGE = 21,
    BUBBLE_SPIN_RANDOM_CENTER = 10,
    BUBBLE_PARTICLE_RANDOM_RANGE = 5,
    BUBBLE_PARTICLE_RANDOM_CENTER = 2,
    BUBBLE_TRAIL_PARTICLE_TYPE = 1,
    EFFECT_SPIN_AXIS_X_OFFSET = 0xB4,
    EFFECT_SPIN_AXIS_Y_OFFSET = 0xB8,
    EFFECT_SPIN_AXIS_Z_OFFSET = 0xBC,
    EFFECT_SPIN_ANGLE_OFFSET = 0xC0,
    EFFECT_PHYSICS_OFFSET = 0xD8,
    EFFECT_PHYSICS_UNK1C_OFFSET = 0x1C
};

/* func_801A41B4: effect_spawn_scaled_sprite.
 * func_801AA5BC allocates an effect from its type's defaults;
 * func_801A96A8 initializes its model or embedded sprites;
 * func_801A8E54 inserts it into the active effect list; func_80147000 is random_below.
 * Each embedded sprite occupies 0x38 bytes, starting at effect +0xEC.
 * The first sprite's offsets are in ActorEffectOffsets; these name the second.
 * D_8010AF00/04/08/0C are separate 2147483648.0f pool entries used for
 * unsigned conversion of first/second start scales, then first/second end scales.
 */
/* func_801AA8D4: effect_spawn_fire_pair.
 * Type 4 uses the firea/fireb sprite resources in the effect definition table.
 * func_801AA5BC allocates it; func_801A96A8 initializes its two sprites.
 * func_80178134 plays positional sound; func_80147000 returns random % bound.
 * D_8029F210 is the active effect-list sentinel; D_8029F394 is its count.
 * D_801F19B8 / D_801F19BC count types 11/25 and 12/28 respectively.
 * Sprite start scales range from 196 to 451, end scales from 220 to 275.
 * Velocity components range from -3 to 3; player-contact damage is disabled.
 * Raw link words and Vec3F copies retain the original compiler aliasing.
 */
enum FirePairEffectConstants {
    FIRE_PAIR_EFFECT_COUNT = 2,
    EFFECT_TYPE_FIRE_SPRITES = 4,
    FIRE_PAIR_SOUND_ID = 0x6A,
    FIRE_PAIR_SOUND_VOLUME = 100,
    FIRE_PAIR_VELOCITY_RANGE = 7,
    FIRE_PAIR_VELOCITY_BIAS = 3,
    FIRE_PAIR_START_SCALE_RANGE = 256,
    FIRE_PAIR_START_SCALE_MIN = 196,
    FIRE_PAIR_END_SCALE_RANGE = 56,
    FIRE_PAIR_END_SCALE_MIN = 220,
    EFFECT_CLEAR_PLAYER_DAMAGE_MASK = 0xFFFDFFFF
};

enum ScaledSpriteEffectConstants {
    EFFECT_POSITION_JITTER_RANGE = 21,
    EFFECT_POSITION_JITTER_BIAS = 10,
    EFFECT_SECOND_SPRITE_SCALE_X_OFFSET = 0x13C,
    EFFECT_SECOND_SPRITE_SCALE_Y_OFFSET = 0x13E,
    EFFECT_SECOND_SPRITE_START_SCALE_OFFSET = 0x150,
    EFFECT_SECOND_SPRITE_END_SCALE_OFFSET = 0x152
};

/*
 * func_801AB140: effect_update_sprite_trail.
 * Emits type 6 every other state frame, with sevenfold sprite start scales.
 * D_8010B3AC is -1 (trail Y velocity); D_8010B3B0 is 5 (X velocity bias).
 * A contact with collision byte +0x189 clear plays sound 198; at age 21 or
 * later the same condition returns 1 to finish the effect. The meaning of
 * collision byte +0x189 is still unknown.
 * Uses the allocator, initializer, list counters and audio helpers documented
 * with ActorEffectOffsets above; all existing field access types are retained.
 */
enum SpriteTrailEffectConstants {
    SPRITE_TRAIL_EFFECT_TYPE = 6,
    SPRITE_TRAIL_FRAME_MASK = 1,
    SPRITE_TRAIL_SCALE_MULTIPLIER = 7,
    SPRITE_TRAIL_X_VELOCITY_RANGE = 10,
    SPRITE_TRAIL_CONTACT_SOUND = 198,
    SPRITE_TRAIL_CONTACT_VOLUME = 100,
    SPRITE_TRAIL_MIN_CONTACT_AGE = 21,
    EFFECT_COLLISION_UNK189_OFFSET = 0x189
};

/* func_801AB404: effect_collect_nearby_garibs.
 * ActorEffectOffsets describe the effect's radius and position.
 * D_8010B3B4 is its minimum Y; D_8010B3B8 expands the pickup radius.
 * D_802993A0/A4 are the Garib-group sentinel and tail; GaribLoadView and
 * GaribActivationFields describe each group's members. Type 2 grants a life.
 * D_801ED3C4 supplies the particle velocity vector.
 * func_80148EBC measures squared distance; func_8018DF4C grants a life;
 * func_8018DFAC grants Garib rewards; func_8018E260 adds score;
 * func_8014ACB4 unlinks the collected sprite; func_801B66D4 spawns particles.
 * Return 1 below the minimum Y, otherwise collect all overlapping entries
 * and return 0. Keep the raw list accesses and signed active-byte test.
 */
enum GaribPickupEffectConstants {
    GARIB_PICKUP_EXTRA_LIFE_SCORE = 500,
    GARIB_PICKUP_SOUND = 0x8C,
    GARIB_PICKUP_PARTICLE = 5,
    GARIB_PICKUP_SCORE_PARTICLE = 0x17,
    GARIB_PICKUP_LIFE_PARTICLE = 0x1B
};

/* func_801AB58C: effect_update_player_capture.
 * The effect embeds its object at +8; ActorEffectOffsets describe its fields.
 * +0x16C is the PositionalSound volume, increased during collision contact.
 * Collision +0x188 is the contact count; +0x189 remains unidentified.
 * D_802900C8: player contact actor; D_80290304: player supporting object.
 * D_8028FAC8 / D_8028FAD0: tracked position / velocity pointers.
 * D_8029FA50: ball collision state; +0x74 is its target collision radius.
 * D_8029F9D0/D4/D8: ball velocity X/Y/Z; DC/E0/E4: next vector, cleared too.
 * D_80290374: player orientation, copied verbatim using Quad32.
 * D_802903B4: player ActorAnimation; D_802903AC: player state.
 * D_8010B3BC/C0: ball-radius increase/cap; C4: initial contact offset;
 * C8: impact threshold. These pool symbols retain their existing types.
 * func_80147000: random_below; func_80133998: object_set_animation;
 * func_8018C700: apply_player_ball_powerup;
 * func_801B13CC: restore_player_ball_control.
 */
enum CaptureEffectConstants {
    CAPTURE_EFFECT_FLAGS_OFFSET = 0x30,
    CAPTURE_EFFECT_PLAYER_CONTACT = 0x40000000,
    CAPTURE_EFFECT_VOLUME_RISE = 40,
    CAPTURE_EFFECT_VOLUME_FALL = 10,
    CAPTURE_EFFECT_VOLUME_MAX = 120,
    CAPTURE_EFFECT_MIN_IMPACT_AGE = 21,
    CAPTURE_EFFECT_CONTACT_UNK189 = 0x189,
    CAPTURE_EFFECT_PLAYER_STATE = 0x29,
    CAPTURE_EFFECT_PLAYER_ANIMATION = 0x2C,
    CAPTURE_EFFECT_BALL_POWERUP = 11,
    CAPTURE_EFFECT_BALL_FORM_EXCLUDED = 6,
    CAPTURE_EFFECT_BALL_RADIUS_OFFSET = 0x74
};

enum SpiderBombConstants {
    SPIDER_BOMB_IMPACT_SOUND = 190,
    SPIDER_BOMB_IMPACT_PITCH_RANGE = 60,
    SPIDER_BOMB_IMPACT_PITCH_BASE = 50,
    SPIDER_BOMB_IMPACT_VOLUME_MAX = 100,
    SPIDER_BOMB_MOVEMENT_SOUND = 0x2B,
    SPIDER_BOMB_MOVEMENT_VOLUME = 0x14,
    SPIDER_BOMB_MOVEMENT_PITCH = 0xF0,
    SPIDER_BOMB_MOVEMENT_VOLUME_MAX = 60,
    SPIDER_BOMB_TRAIL_EFFECT = 0x11,
    SPIDER_BOMB_TRAIL_RANDOM_RANGE = 20,
    SPIDER_BOMB_TRAIL_RANDOM_THRESHOLD = 7,
    SPIDER_BOMB_TRAIL_VELOCITY_RANGE = 4,
    SPIDER_BOMB_TRAIL_VELOCITY_BIAS = 2,
    SPIDER_BOMB_TRAIL_SCALE_RANGE = 0x38,
    SPIDER_BOMB_TRAIL_SCALE_BASE = 0x9C,
    SPIDER_BOMB_TRAIL_ANIMATION_STEP = 0x20
};

/* Prefix used by func_801ABD38; the effect's embedded actor begins at +8. */
typedef struct ExplosionEffectView {
    /* 0x000 */ u8 unk000[0x2C];
    /* 0x02C */ s16 remainingFrames;
    /* 0x02E */ s16 intensity;
    /* 0x030 */ s32 flags;
    /* 0x034 */ u8 unk034[8];
    /* 0x03C */ f32 position[3];
    /* 0x048 */ u8 unk048[0x38];
    /* 0x080 */ f32 rotation[3];
    /* 0x08C */ u8 unk08C[0x18];
    /* 0x0A4 */ f32 orientation[4];
    /* 0x0B4 */ u8 unk0B4[0x10];
    /* 0x0C4 */ f32 scale[3];
    /* 0x0D0 */ s32 mesh;
    /* 0x0D4 */ u8 unk0D4[0x10];
    /* 0x0E4 */ ActorAnimation *animation;
} ExplosionEffectView; /* prefix size = 0xE8 */

/* func_801BA0E0 applies radial explosion damage and knockback.
 * Actors within blastRadius are destroyed except the excluded actor.
 * Player/ball knockback uses blastRadius; their damage uses damageRadius.
 * Player states 8 and 21 take one damage point instead of lethal damage.
 * The impulse is the unnormalized offset times (blastRadius-distance)*scale.
 *
 * D_801F0198: actor slot count. D_802903AC: player state block.
 * D_8028FBF6: player death/recovery timer. D_80290300: player object flags.
 * D_8029035C/360: player knockback angle/heading.
 * D_802903B0 / D_8029FA50: player / ball collision state; +0x188 counts contacts.
 * D_802902D8 / D_8029F978: player / ball object.
 * Player position/velocity: D_8029030C/310/314 and D_80290330/334/338.
 * Ball position/velocity: D_8029F9AC/B0/B4 and D_8029F9D0/D4/D8.
 * D_8029F9A4 is the ball's supporting object.
 *
 * func_80195D50 destroys an actor; func_80167604 changes player state.
 * func_80148D0C adds a scaled vector; func_80160728 updates and limits speed.
 * func_801B13CC resets player/ball handling after release.
 * func_80147460 computes X/Z heading; func_801496C8 wraps it by one revolution.
 * func_801743A8 damages the player; func_80174058 kills the player.
 * func_801B0DDC handles ball damage, with form-specific responses.
 *
 * Pool floats: D_8010BF14/BF20 = 12 (vertical-speed cap for the lift),
 * D_8010BF18/BF24 = 8 (added lift), D_8010BF1C = pi/2 (knockback angle).
 * The scratch array holds XYZ in 0..2, an unused slot at 3, distance at 4.
 */
/*
 * func_801743A8 applies player damage. Zero damage means one point; negative
 * damage is lethal. damageMode also selects the death response in func_80174058.
 * D_80290194 is health; D_802901DC is the damage-invulnerability timer.
 * D_8028FBF6 is the death/recovery timer; D_80297BEC bit 0x40 protects health
 * from nonnegative damage. Level 0x28 uses five invulnerability frames.
 * D_8029030C is player position; D_80290330/334/338 are velocity X/Y/Z.
 * D_802900A4 is the previous supporting object; the three floats before it
 * hold the saved player position relative to that support (world space if null).
 * D_80108324 = 13 (collision setting and horizontal knockback magnitude);
 * the first float at D_80108328 = 9 (upward hit velocity).
 * D_801ED3C4/C8/CC form the zero vector copied through Vec3Words.
 *
 * func_8018D39C cancels a numbered active effect; func_80167604 changes state.
 * func_80175388 scales a collision value; func_80178134 plays positional sound.
 * func_80147000 supplies a bounded random index.
 * func_80149428/func_80149374 subtract/add XZ only; func_80149604 normalizes XZ.
 * func_8016049C adds velocity along object yaw and limits horizontal speed.
 */
enum PlayerDamageMode {
    PLAYER_DAMAGE_KNOCKBACK_BACKWARD = 0,
    PLAYER_DAMAGE_KNOCKBACK_FROM_SUPPORT = 1,
    PLAYER_DAMAGE_NO_HORIZONTAL_KNOCKBACK = 2
};

enum PlayerDamageConstants {
    PLAYER_DAMAGE_HEALTH_PROTECTED = 0x40,
    PLAYER_DAMAGE_INVULNERABILITY_FRAMES = 60,
    PLAYER_DAMAGE_SHORT_INVULNERABILITY_FRAMES = 5,
    PLAYER_DAMAGE_SOUND_BASE = 0x105,
    PLAYER_DAMAGE_SOUND_VARIANTS = 4,
    PLAYER_DAMAGE_SOUND_VOLUME = 140,
    PLAYER_DAMAGE_SOUND_PITCH = 128,
    PLAYER_STATE_HURT = 0x1C
};

/*
 * func_80174058: player_die(damageMode). Starts the death response once,
 * shortens active effect timers, and schedules recovery.
 * D_80290194: player health; the effect timers D_8029019C start two words later.
 * D_8029014C: positional sound state (handle at +0, volume at +4).
 * D_8028FBD8: player action countdown; D_8028FBF6: death/recovery countdown.
 * D_8029011E: frog-form flag. D_802903AC: action block, current state at +4.
 * D_802903B0: collision block, target radius at +0x74.
 *
 * func_8018D39C: cancel_active_effect; func_80167604: player_change_state.
 * func_80175388: set_scaled_collision_radius; func_80147000: random_below.
 * func_80178134: play_positional_sound; func_801785E0: start_tracked_sound;
 * func_80178704: stop_tracked_sound; func_80133998: set_object_animation.
 * func_8017479C: process_lost_life (used immediately in the robot level).
 * Animation 5 and sound 0xA0 are also used by the falling-player update.
 * The meanings of death mode 3 and collision byte +0x18A remain unresolved.
 */
/*
 * func_8017479C: player_process_lost_life.
 * D_80290190/194: remaining lives and health; D_801E7470: game-over timer.
 * D_80297BEC bit 8 prevents losing lives; D_801E7531 is the current level.
 * D_802900E0 is the activated respawn platform. Its +0x54 state pointer
 * addresses s16 words; word 1 is the recovery countdown, started at 65.
 * D_801EC740 is camera control mode; func_801364D0 resumes camera following.
 * func_8014E9F4 spawns a screen particle (preset 1 is the life icon).
 * D_8028F714/718 provide the icon's screen X/Y.
 * func_80128F0C selects levels 14, 19, 24, 29, 34 and 41 for an immediate
 * transition; func_80128DF8 requests that transition.
 * D_801EC7D2 blocks normal gameplay updates while the transition runs.
 */
enum PlayerLifeLossConstants {
    PLAYER_LIVES_EXHAUSTED = -1,
    PLAYER_RESPAWN_HEALTH = 3,
    PLAYER_OPTION_INFINITE_LIVES = 8,
    PLAYER_LIFE_LOSS_TRANSITION = 5,
    RESPAWN_PLATFORM_STATE_OFFSET = 0x54,
    RESPAWN_PLATFORM_COUNTDOWN_WORD = 1,
    RESPAWN_PLATFORM_START_COUNTDOWN = 0x41
};

enum PlayerDeathConstants {
    PLAYER_DEATH_EFFECT_TO_CANCEL = 6,
    PLAYER_DEATH_EFFECT_TIMER_COUNT = 15,
    PLAYER_DEATH_EFFECT_MAX_FRAMES = 40,
    PLAYER_DEATH_RECOVERY_FRAMES = 80,
    PLAYER_DEATH_BALL_RECOVERY_FRAMES = 81,
    PLAYER_DEATH_TRANSITION_DELAY = 60,
    PLAYER_DEATH_SOUND_BASE = 0x111,
    PLAYER_DEATH_SOUND_VARIANTS = 3,
    PLAYER_DEATH_SOUND_VOLUME = 100,
    PLAYER_DEATH_SOUND_PITCH = 128,
    PLAYER_FALL_SOUND = 0xA0,
    PLAYER_FALL_ANIMATION = 5,
    PLAYER_STATE_FALL = 2,
    PLAYER_DEATH_ANIMATION = 0x28,
    PLAYER_DEATH_CONTACT_ANIMATION = 0x26,
    PLAYER_OBJECT_POSITION_OFFSET = 0x34
};

enum RadialBlastConstants {
    BLAST_SCRATCH_FLOATS = 5,
    BLAST_DISTANCE_INDEX = 4,
    BLAST_OBJECT_POSITION_X_WORD = 0x34 / 4,
    BLAST_OBJECT_POSITION_Y_WORD = 0x38 / 4,
    BLAST_OBJECT_POSITION_Z_WORD = 0x3C / 4,
    BLAST_OBJECT_VELOCITY_OFFSET = 0x58,
    BLAST_PLAYER_KNOCKBACK_FLAGS = 0x1002000,
    BLAST_PLAYER_AIRBORNE_STATE = 2
};

/* func_801AADFC: object_explode. D_8010B390 is angle divisor 10 (f64);
 * D_8010B398/B39C are particle horizontal/upward speeds 4/10;
 * D_8010B3A0/B3A4 are knockback speed limit 25 and impulse scale 0.2;
 * D_801F1A50/54 are damage/blast radii 50/100. D_801ED3C4 is zero XYZ.
 * Helpers: func_80147000 random_below; func_801490AC vec3_rotate_y;
 * func_801B66D4 particle_spawn; func_8014D61C screen_flash_start;
 * func_80178134 sound_play_positional; func_801BA0E0 apply_radial_blast;
 * func_801B9974 camera_shake_at_position. */
enum ExplosionConstants {
    OBJECT_EXPLOSION_POSITION_OFFSET = 0x34,
    OBJECT_EXPLOSION_EXCLUDED_ACTOR_OFFSET = 0x2C,
    OBJECT_EXPLOSION_PARTICLE_COUNT = 6,
    OBJECT_EXPLOSION_ANGLE_STEPS = 63,
    OBJECT_EXPLOSION_SOUND = 0x6A,
    EXPLOSION_SOUND = 0x63,
    EXPLOSION_WARMUP_SOUND = 0xB6,
    EXPLOSION_SOUND_VOLUME = 255,
    EXPLOSION_SOUND_PITCH = 128,
    EXPLOSION_SHAKE_DURATION = 50,
    EXPLOSION_FLASH_STEP = -30,
    EXPLOSION_FLAGS_KEEP_MASK = -0x1A,
    EXPLOSION_PLAYER_KNOCKBACK_FLAGS = 0x01002010,
    EXPLOSION_VISUAL_ONLY_LEVEL = 0x28
};

/*
 * func_801ABD38 expands the explosion and applies player/ball knockback.
 * func_80178134 plays positional audio; func_801B9974 starts distance-based shake.
 * func_8014D61C sets screen-flash RGB, intensity and step.
 * func_801496C8 wraps an angle; func_8015C350 converts Euler angles to a quaternion.
 * func_80148D0C adds a scaled vector; func_80174058 handles player damage.
 * func_801B0DDC handles ball damage; func_801A2944 tests an animation frame crossing.
 *
 * Explosion tuning, decoded from the original data:
 * D_801F1A64 = 2000 (growth numerator); D_801F1A68 = 40 (scale to hit radius);
 * D_801F1A6C = 100 (explosion-phase frames); D_801F1A70 = 100 (growth divisor factor);
 * D_801F1A74 = 30 (minimum damaging intensity); D_801F0F0C = 200 (initial lifetime).
 * D_8010B408/40C/410/414 = 2/7/8/16 (flash timing and color factors);
 * D_8010B418/41C = 255 (color/intensity maximum);
 * D_8010B420 = 0.9 (f64 vertical scale); D_8010B428 = 0.2 (f64 yaw step);
 * D_8010B430 = 100 (effect intensity maximum);
 * D_8010B434/438/43C = 14/5/1 (player impulse, minimum lift, position lift);
 * D_8010B440/444 = 7/5 (ball impulse, minimum lift);
 * D_8010B448/450 = 0.03/0.6 (f64 animation-speed ramp/minimum);
 * D_8010B458 = 0.6 (minimum speed); D_8010B45C = 10 (warmup sound frame).
 */

/*
 * Platform motion commands in the level stream (func_801884A4).
 * func_80182F64 appends a path point; func_8017D21C rebuilds collision geometry.
 * func_80147460 computes an X/Z heading; func_801496C8 wraps it by one turn.
 * func_8013FCDC allocates tagged memory (second argument 1 clears it);
 * func_8013FBC0 clears bytes; func_801D211C copies bytes (memcpy).
 * func_801D2150 formats text (sprintf); func_80139D70 is the disabled log sink.
 * D_8025D578 is the formatting buffer.
 * D_801090B8 = "Plat_Spin"; D_80108D34 = "Plat_Path" allocation tags.
 * D_801090D0 warns that the platform already has spin state.
 * D_80109420 / D_80109454 warn of LOOKATPOINT / GOFORWARDS without a platform.
 * D_801EFCF4 is the level loader's collision-mesh Y offset, initially zero.
 * N64 symbol renaming is unavailable; retain the address names above.
 */
/* Platform motion links at platform + 0x34 (allocation tag "Plat_MvSpn").
 * Rotation can drive another tagged platform's velocity or angular step;
 * movement can drive its angular step through a scaled dot product.
 */
typedef struct PlatformMotionLinks {
    /* 0x00 */ f32 velocity[3];
    /* 0x0C */ s16 velocityTargetTag;
    /* 0x0E */ u8 unk00E[2];
    /* 0x10 */ f32 spinToMoveScale;
    /* 0x14 */ s16 spinToMoveTag;
    /* 0x16 */ u8 unk016[2];
    /* 0x18 */ f32 spinToSpinScale;
    /* 0x1C */ s16 spinToSpinTag;
    /* 0x1E */ u8 unk01E[2];
    /* 0x20 */ f32 moveToSpinScale;
    /* 0x24 */ s16 moveToSpinTag;
    /* 0x26 */ u8 unk026[2];
    /* 0x28 */ f32 moveToSpinDirection[3];
    /* 0x34 */ f32 velocityOffset[3];
} PlatformMotionLinks; /* size = 0x40 */

/* func_801852EC reads one motion-link or parenting command and advances the
 * stream address; returns 0 only for an unhandled command. Parent tags must
 * precede path points. Rotation inheritance also rotates the initial position.
 * func_8017DBA0 finds a platform by tag; func_801C4040/801C6000 are cosf/sinf.
 * D_80109040 is "Plat_MvSpn"; D_8010904C warns of a missing parent tag;
 * D_80109080 warns of a parent tag after the first path point.
 * D_802904D0 identifies the platform currently being loaded.
 */
/* func_801748D0 handles the player's platform contacts. A support path wait
 * of -2 or -1, or contact slot 1's wait of -1, forwards PlatformMotionLinks
 * velocity to every platform with velocityTargetTag, adding each target's
 * velocityOffset. With no links, player state 0x12 releases the support path.
 * D_802903B0 is player collision state; D_802903AC is player action state.
 * D_802904D4 is the platform list sentinel. func_8017DBD8 searches after its
 * first argument for the next platform whose signed tag at +0x6C matches.
 * The meanings of the two bits changed at platform +0x78 remain unknown.
 */
enum PlatformContactField {
    PLAYER_CONTACT_PLATFORM_SLOT1 = 0x17C,
    PLATFORM_UNK078_OFFSET = 0x78,
    PLATFORM_LINK_VELOCITY_OFFSET_Y = 0x38,
    PLATFORM_LINK_VELOCITY_OFFSET_Z = 0x3C,
    PLATFORM_VELOCITY_Z = 0xE0
};

enum PlatformMotionLinkField {
    PLATFORM_MOTION_LINKS = 0x34,
    PLATFORM_LINK_VELOCITY_TAG = 0x0C,
    PLATFORM_LINK_SPIN_TO_MOVE_SCALE = 0x10,
    PLATFORM_LINK_SPIN_TO_MOVE_TAG = 0x14,
    PLATFORM_LINK_SPIN_TO_SPIN_SCALE = 0x18,
    PLATFORM_LINK_SPIN_TO_SPIN_TAG = 0x1C,
    PLATFORM_LINK_MOVE_TO_SPIN_SCALE = 0x20,
    PLATFORM_LINK_MOVE_TO_SPIN_TAG = 0x24,
    PLATFORM_LINK_MOVE_TO_SPIN_DIRECTION = 0x28,
    PLATFORM_LINK_VELOCITY_OFFSET = 0x34
};

/* Byte offsets into ObjectRotation; the packed axis copy includes byte 7.
 * Previous angles occupy the existing pad044 bytes as three floats; retain
 * that field's declared type for callers that use other views.
 * func_8017AE0C applies parent motion to position, velocity and path targets.
 * Its helpers: func_801490AC rotates a Vec3F about Y; func_8014915C rotates
 * about axis 0/1/2 (X/Y/Z); func_801496C8 wraps an angle by at most one turn.
 * Symbol renaming is currently unsupported by the N64 project tools. */
enum PlatformInheritedRotationField {
    PLATFORM_ROTATION_AXES = 4,
    PLATFORM_ROTATION_ANGLES = 0x38,
    PLATFORM_ROTATION_YAW = 0x3C,
    PLATFORM_ROTATION_ROLL = 0x40,
    PLATFORM_ROTATION_PREVIOUS_ANGLES = 0x44,
    PLATFORM_ROTATION_PREVIOUS_YAW = 0x48,
    PLATFORM_ROTATION_PREVIOUS_ROLL = 0x4C,
    PLATFORM_ROTATION_TARGET_ANGLES = 0x5C,
    PLATFORM_ROTATION_NO_AXIS = 10,
    PLATFORM_INHERIT_ROTATION = 0x40
};

enum PlatformMotionCommand {
    PLATFORM_CMD_SPIN_TO_MOVE = 0x58,
    PLATFORM_CMD_MOVE_TO_SPIN = 0x59,
    PLATFORM_CMD_SPIN_TO_SPIN = 0x5A,
    PLATFORM_CMD_PARENT_TAG = 0x71,
    PLATFORM_CMD_LINK_VELOCITY = 0x73,
    PLATFORM_CMD_VELOCITY_OFFSET = 0x74,
    PLATFORM_CMD_INHERIT_ROTATION = 0x7B,
    PLATFORM_CMD_LOOK_AT_POINT = 0x5E,
    PLATFORM_CMD_GO_FORWARDS = 0x5F,
    PLATFORM_CMD_ADD_PATH_POINT = 0x6B,
    PLATFORM_CMD_MAX_SPEED = 0x6C,
    PLATFORM_CMD_PATH_ACCELERATION = 0x6D,
    PLATFORM_CMD_POSITION = 0xA6,
    PLATFORM_CMD_START_PATH_POINT = 0xA7
};

/* Byte offsets preserve the existing casts and aliasing of platform accesses. */
/* func_8017BDD0 integrates platform motion, using four inset ground probes
 * for gravity/bounce, then clamps position to optional parent-relative bounds.
 * func_8015B524 returns the distance to ground below a point, or -1, and
 * writes collision-face/platform pointers into two 32-bit output slots.
 * D_801ED680 is gravity; D_801EFC84 adds to the half-height support tolerance.
 * Original pool: D_801087F0 = 0.1 (f64 corner inset), D_801087F8 = -1;
 * f64 at D_801087F8 + 4 = 1.5 (gravity scale), and at D_80108800 + 4 =
 * 0.7 (bounce damping). Preserve those labelled pool accesses.
 * Bounds at platform + 0x44 contain minimum[3] followed by extent[3];
 * a negative extent disables clamping on that axis.
 */
enum PlatformIntegrationField {
    PLATFORM_HALF_WIDTH = 0x08,
    PLATFORM_HALF_HEIGHT = 0x0C,
    PLATFORM_HALF_DEPTH = 0x10,
    PLATFORM_MOTION_BOUNDS = 0x44,
    PLATFORM_VELOCITY = 0xD8,
    PLATFORM_VELOCITY_Y = 0xDC,
    PLATFORM_BOUNDS_EXTENT = 0x0C
};

/* func_80187444 parses platform orbit tokens; func_8017B780 advances the orbit.
 * func_801D211C copies bytes, func_8013FCDC allocates tagged memory (1 clears it),
 * func_80147460 computes atan2, and func_801D2150 formats diagnostics into
 * D_8025D578 before the empty diagnostic hook func_80139D70.
 * D_80109100 = "Plat_Orbit"; D_80109234 warns about multiple path points;
 * D_80109278 / D_801092C0 report conflicting ORBITPAUSE / ORBITFLIP tokens.
 * The orbit state is 0x4C bytes. Axis flags exclude one coordinate from
 * the orbit plane. Pause count and flip angle select mutually exclusive modes.
 * Sound volume words at +0x34/+0x44 are written as s32; playback reads their
 * low halfwords at +0x36/+0x46. Preserve those packed writes. */
enum PlatformOrbitCommand {
    PLATFORM_CMD_ORBIT = 0x75,
    PLATFORM_CMD_ORBIT_PAUSE = 0x76,
    PLATFORM_CMD_ORBIT_FLIP = 0x77,
    PLATFORM_CMD_ORBIT_MOVE_SOUND = 0xC4,
    PLATFORM_CMD_ORBIT_STOP_SOUND = 0xC6
};

enum PlatformOrbitField {
    PLATFORM_ORBIT = 0x28,
    PLATFORM_ORBIT_STATE_BYTES = 0x4C,
    ORBIT_ANGULAR_STEP = 0x00,
    ORBIT_AXIS_FLAGS = 0x04,
    ORBIT_PAUSE_FRAMES = 0x08,
    ORBIT_DELAY = 0x0A,
    ORBIT_PAUSE_COUNT = 0x0C,
    ORBIT_NEXT_PAUSE = 0x0D,
    ORBIT_FLIP_ANGLE = 0x10,
    ORBIT_INITIAL_ANGLE = 0x14,
    ORBIT_CENTER = 0x18,
    ORBIT_CURRENT_ANGLE = 0x24,
    ORBIT_SOUND_HANDLE = 0x28,
    ORBIT_SOUND_STOP_TIMER = 0x2C,
    ORBIT_MOVE_SOUND_VOLUME_WORD = 0x34,
    ORBIT_MOVE_SOUND_PITCH = 0x38,
    ORBIT_MOVE_SOUND_ID = 0x3A,
    ORBIT_STOP_SOUND_VOLUME_WORD = 0x44,
    ORBIT_STOP_SOUND_PITCH = 0x48,
    ORBIT_STOP_SOUND_ID = 0x4A
};

/* Orbit state at platform + PLATFORM_ORBIT (see PlatformOrbitField). */
typedef struct PlatformOrbit {
    /* 0x00 */ f32 angularStep;      /* Radians per frame; sign gives direction. */
    /* 0x04 */ s8 axisLocked[3];     /* Nonzero marks the axis normal to the orbit plane. */
    /* 0x07 */ u8 pad07;
    /* 0x08 */ u16 pauseFrames;
    /* 0x0A */ s16 delay;            /* >0: pausing; <0: frames to ignore stop tests. */
    /* 0x0C */ u8 pauseCount;        /* Evenly spaced pause points per turn. */
    /* 0x0D */ u8 nextPause;
    /* 0x0E */ u8 pad0E[2];
    /* 0x10 */ f32 flipAngle;        /* Nonzero: reverse at +/- this angle. */
    /* 0x14 */ f32 initialAngle;
    /* 0x18 */ f32 center[3];
    /* 0x24 */ f32 currentAngle;
    /* 0x28 */ s32 soundHandle;
    /* 0x2C */ s32 soundStopTimer;
    /* 0x30 */ u8 pad30[6];
    /* 0x36 */ s16 moveSoundVolume;
    /* 0x38 */ s16 moveSoundPitch;
    /* 0x3A */ s16 moveSoundId;
    /* 0x3C */ u8 pad3C[0xA];
    /* 0x46 */ s16 stopSoundVolume;
    /* 0x48 */ s16 stopSoundPitch;
    /* 0x4A */ s16 stopSoundId;
} PlatformOrbit; /* size = 0x4C */

/* func_8015CE38: platform_apply_surface_motion. With radialStep == 0,
 * the vector at +0x5C is a displacement, rotated by PLATFORM_QUATERNION
 * when PLATFORM_ROTATION is present. Otherwise it is an offset from the
 * platform position to an XZ target: positive radialStep moves toward it,
 * negative moves away, with magnitude capped by the horizontal distance.
 * A nonzero final argument replaces the output; zero adds the displacement.
 * D_801071F4 is 1.0f, the horizontal normalization numerator.
 * func_801499A0 rotates a vector by quaternion; func_80149374/func_80149428
 * add/subtract XZ only. Symbol renames are unsupported by the N64 tools. */
enum PlatformSurfaceMotionField {
    PLATFORM_SURFACE_MOTION_VECTOR = 0x5C,
    PLATFORM_SURFACE_RADIAL_STEP = 0x68
};

enum PlatformMotionField {
    PLATFORM_FLAGS = 0x14,
    PLATFORM_MAX_SPEED = 0x1C,
    PLATFORM_PARENT = 0x20,
    PLATFORM_ROTATION = 0x2C,
    PLATFORM_PATH = 0x38,
    PLATFORM_POSITION = 0xB4,
    PLATFORM_POSITION_Y = 0xB8,
    PLATFORM_POSITION_Z = 0xBC,
    PLATFORM_PREVIOUS_POSITION = 0xC0, PLATFORM_PREVIOUS_POSITION_Y = 0xC4, PLATFORM_PREVIOUS_POSITION_Z = 0xC8,
    PLATFORM_FRAME_START_POSITION = 0xCC, PLATFORM_UNK50 = 0x50, PLATFORM_MULTI_AXIS_ROTATION = 0xA000, /* flags */
    PLATFORM_DAMPING = 0xF0
};

/*
 * Atlantis bonus update (func_8011BDE0, level 14, "atbonus").
 * func_80155A44 / func_80155AE4 stop / start drawing around allocation.
 * func_8018315C sets a platform's parent-relative position and collision mesh;
 * func_80179ECC appends it to the circular list at D_802904D4.
 * func_80142700 initializes the embedded render object at platform + 0x80.
 * D_80100D48 / D_80100D54 are "Plat_Push" / "Plat" allocation tags.
 *
 * D_801E6754 / D_801E6758: push/shuttle damping (both initially 0.9).
 * D_801E675C: push strength (10). D_801F7D7C: state-3 frame counter.
 * D_801E6764 / D_801E6770: first Z clamp bounds (100 / -3700).
 * D_801E676C / D_801E6778: second Z clamp bounds (0 / -3865).
 * D_801E6768 / D_801E6774: player Z failure bounds (100 / -4100).
 * D_80100D58 + 4: f64 horizontal falling-velocity multiplier (0.6).
 * D_80100D64/68: max speed 1000 / initial damping 1.
 * D_80100D6C/70: parent/child path acceleration 0.001 / 0.015.
 * D_80100D74: child max speed 3; D_80100D78: push Z numerator 1.
 * D_80100D7C/80: Z wrap endpoints 200 / -4500.
 * D_80100D84: shuttle Z numerator -2.
 */
enum BonusPlatformRole {
    BONUS_PLATFORM_ORDINARY = 0,
    BONUS_PLATFORM_PUSH = 1,
    BONUS_PLATFORM_SHUTTLE_CHILD = 2,
    BONUS_PLATFORM_SHUTTLE_PARENT = 3
};

/* Byte offsets into the existing platform, push state and player layouts. */
enum BonusPlatformField {
    BONUS_PLATFORM_PUSH_STATE = 0x40,
    BONUS_PLATFORM_ROLE = 0x6C,
    BONUS_PLATFORM_RENDER_OBJECT = 0x80,
    BONUS_PLATFORM_RENDER_TYPE = 0xA0,
    BONUS_PLATFORM_VELOCITY_Z = 0xE0,
    BONUS_PUSH_ENABLED = 1,
    BONUS_PUSH_STRENGTH = 4,
    BONUS_PLAYER_SUPPORT_PLATFORM = 0x178
};

/*
 * func_8011C36C: level 39 platform interaction sequence.
 * func_8017DBA0 finds a platform by its signed role/tag at +0x6C.
 * func_801A9054 spawns effects from an actor and an effect-type table.
 * func_80197794 selects an actor action (third argument bypasses conditions).
 * func_80133998 selects or queues an animation; a zero speed uses the clip speed.
 * func_80148EBC is squared Vec3F distance; func_80149398 is a weighted vector sum.
 *
 * D_801F7D80 counts interaction frames; D_802004E0 counts state frames.
 * D_802902D8 is the player; D_802903AC points to its state (s16 at +4).
 * D_8029030C/310/314 and D_80290330/334/338 are player position and velocity.
 * D_80290360 is player target yaw; D_80290300 holds player flags.
 * D_8028F908 holds camera flags; D_8028F914 is camera position.
 * D_8028FA00/04/08 is camera focus; D_8028FAFC is the saved camera position.
 * D_8028FAC8 points to the followed position; +8 points to its velocity,
 * and +0x34 aliases the saved camera position. D_8028FAF8 requests the handoff.
 * D_802999E8 is the actor followed after frame 70; D_80299A40 is its velocity X.
 *
 * Original float pools: D_80100D88/8C/90 = focus (-8.1,22.7,268);
 * D_80100D94/98/9C = approach Z (-100), bias (100), divisor (4);
 * D_80100DA0/A4 = actor velocity X changes (15);
 * D_80100DA8/AC = effect Z offset (50), Y velocity increment (5);
 * D_80100DB0/B4/B8/BC = target yaw (pi), player Y/Z offsets (17/4),
 * and target interpolation weight (0.3).
 * D_801E677C = platform recoil distance (17); D_801E6780 = trigger radius squared (900).
 * Raw accesses preserve the existing layouts and aliasing behavior.
 */
enum Level39InteractionConstants {
    LEVEL39_PLATFORM_PRIMARY = 4,
    LEVEL39_PLATFORM_COMPANION = 5,
    LEVEL39_PLAYER_INTERACTION_STATE = 0x29,
    LEVEL39_PLAYER_INTERACTION_ANIMATION = 0x3E,
    LEVEL39_INTERACTION_EFFECT = 0x19,
    LEVEL39_FIRST_EFFECT_FRAME = 30,
    LEVEL39_SECOND_EFFECT_FRAME = 60,
    LEVEL39_CAMERA_HANDOFF_FRAME = 70,
    LEVEL39_FIXED_CAMERA_FRAMES = 130,
    LEVEL39_FOLLOW_ACTOR_ACTION = 4,
    LEVEL39_CAMERA_CLEARED_FLAG = 0x10,
    LEVEL39_PLAYER_CLEARED_FLAGS = 0x11,
    LEVEL39_EFFECT_POSITION_Z = 0x44,
    LEVEL39_FOLLOW_VELOCITY_FROM_POSITION = 8,
    LEVEL39_SAVED_CAMERA_FROM_FOLLOW_POSITION = 0x34,
    LEVEL39_PLAYER_POSITION_FROM_TARGET_YAW = 0x54
};

enum BonusPlatformConstants {
    BONUS_PLATFORM_BYTES = 0x180,
    BONUS_PUSH_STATE_BYTES = 8,
    BONUS_SHUTTLE_RENDER_TYPE = 0x3B,
    BONUS_FAILURE_DELAY = 21,
    BONUS_SHUTTLE_WAIT = -100,
    BONUS_SHUTTLE_TRIGGER_THRESHOLD = -99,
    BONUS_SHUTTLE_TRIGGER_WAIT = 25,
    BONUS_SHUTTLE_RETURN_WAIT = 65
};

/*
 * func_80182F64: platform_add_path_point; zero wait becomes one frame.
 * func_8013FCDC allocates from the selected heap (flag 1 clears the block).
 * func_8018315C sets current/previous position, adds the parent position,
 * and rebuilds collision through func_8017D21C.
 * D_80108D34 / D_80108D40: allocation tags "Plat_Path" / "Path_Point".
 * D_80108D4C warns that an orbiter cannot follow a path;
 * D_80108D8C warns of too many points. D_802904D0 is the loader's platform
 * number, D_8025D578 the diagnostic buffer, func_801D2150 sprintf, and
 * func_80139D70 the disabled diagnostic sink.
 */
enum PlatformPathLimits {
    PLATFORM_PATH_MAX_POINTS = 20,
    PLATFORM_PATH_POINT_BYTES = 0x18
};

/* Partial views preserve the existing signedness and layout of the loader. */
typedef struct PlatformPathPointView {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ s16 waitFrames;
} PlatformPathPointView; /* view size = 0x10; allocation = 0x18 */

typedef struct PlatformPathListView {
    /* 0x00 */ PlatformPathPointView *points[PLATFORM_PATH_MAX_POINTS];
    /* 0x50 */ s16 waitRemaining;
    /* 0x52 */ u8 unk52[2];
    /* 0x54 */ u8 direction;
    /* 0x55 */ u8 count;
} PlatformPathListView; /* view size = 0x58; allocation = 0x5C */

typedef struct PlatformPathOwnerView {
    /* 0x00 */ u8 unk00[0x28];
    /* 0x28 */ void *orbit;
    /* 0x2C */ u8 unk2C[0xC];
    /* 0x38 */ PlatformPathListView *path;
} PlatformPathOwnerView; /* partial platform view, size = 0x3C */

/* Path6B8: 20 point pointers followed by traversal state.
 * Each 0x18-byte point starts with Vec3F and a signed halfword wait time.
 * The remaining point fields retain their unknown names. */
enum PlatformPathField {
    PLATFORM_PATH_WAIT = 0x50,
    PLATFORM_PATH_COUNT = 0x55,
    PLATFORM_PATH_CURRENT = 0x56,
    PLATFORM_PATH_PREVIOUS = 0x57,
    PLATFORM_PATH_ACCELERATION = 0x58,
    PLATFORM_POINT_WAIT = 0x0C
};

/* ObjectRotation remains the canonical 0x98-byte spin state.
 * The yaw entries below index the same state through an f32 pointer. */
enum PlatformLookField {
    PLATFORM_LOOK_Y_ENABLED = 5,
    PLATFORM_LOOK_RESTORE_STEP = 0x1C,
    PLATFORM_LOOK_UNK034 = 0x34,
    PLATFORM_LOOK_FORWARD = 0x68,
    PLATFORM_LOOK_AT_POINT = 0x69,
    PLATFORM_LOOK_UNK06A = 0x6A,
    PLATFORM_LOOK_DAMPING = 0x6C,
    PLATFORM_LOOK_YAW_INDEX = 0xF,
    PLATFORM_LOOK_TARGET_YAW_INDEX = 0x18
};

enum PlatformMotionFlags {
    PLATFORM_FACE_PATH_POINT = 0x1000,
    PLATFORM_MOVE_FORWARDS = 0x2000,
    PLATFORM_ROTATION_BYTES = 0x98,
    PLATFORM_PATH_BYTES = 0x5C
};


/*
 * Main game thread: func_8013D990 starts input/save and rendering workers,
 * restores persistent records, then dispatches scheduler frame messages.
 * N64 symbol renaming is unavailable; the address names have these roles:
 *
 * func_801C6550 / func_801C7860: osCreateThread / osStartThread.
 * func_801C6520 / func_801C7430: osCreateMesgQueue / osRecvMesg.
 * func_8017F9A4: register a scheduler client (next pointer, message queue).
 * func_80133E60: initialize controllers and select controller zero.
 * func_8013DF34: controller polling and queued EEPROM operations.
 * func_8013E1B0: render-thread entry.
 * func_80132A9C: reset the save-operation queue.
 * func_80132A30: probe EEPROM and queue the save signature write.
 * func_80132B08 / func_80132B5C: read / write high scores.
 * func_80132BB0 / func_80132C04: write save slots / read time records.
 * func_80132C58: read and validate the save signature.
 * func_80132CAC: read save slots.
 * func_80132D54 / func_80132D00: read / write save checksums.
 * func_80132DA8: wait for queued save operations to drain.
 * func_801336E8: check record CRCs and restore damaged records to defaults.
 * func_80145D88: remove text objects marked for deletion.
 * func_8010FC84 / func_8011E51C / func_8011EAB8: main menu / level select /
 * time-trial selection updates.
 * func_8013990C: test the selected controller's three exit-input flags.
 * func_80128DF8: request a game transition; reason 14 exits level 46.
 * func_80155AE4: enable drawing and wait for the render thread to acknowledge.
 * func_8013F358: update gameplay; func_80180A80: update camera and frame UI.
 * func_80123514: process gameplay transitions; func_80125294: game-over display.
 * func_80120D18: level-results screen; func_80121FF4: end-of-world screen.
 * func_80121FCC / func_80122D68: load the current level.
 * func_80122D90: error screen; func_8012860C: language selection.
 *
 * D_80202218: selected controller index.
 * D_80202060 / D_8025CF00: input / render thread records (also stack tops).
 * D_801EC7AE / D_801EC7AD: input / render thread priorities (115 / 20).
 * D_801FFE60: scheduler; D_80202210: main thread's scheduler client.
 * D_8025D140 / D_80202220: main message queue / eight message slots.
 * Messages point to a signed 16-bit type; type 9 signals a frame.
 * D_801E7530 / D_801E7531: game state / level ID.
 * D_801EAB29: valid EEPROM signature flag, initially zero.
 * D_801EA9E4 / D_801EAA14: active / default six-entry high-score tables.
 * HighScoreEntry is 8 bytes: s32 score at +0, char name[4] at +4.
 * D_801E6790..D_801E6826: six time-record groups, 30 bytes each;
 * D_801E6850..D_801E68E6: their defaults. Each record is a halfword
 * time followed by four name bytes; each group has five records.
 * D_801FA9A8..D_801FA9AA: initial three-letter player name ("BTA").
 * D_802004E0 / D_80201004: state frame counter / frame counter.
 * D_801E747C: menu frame counter; D_80297BEC: gameplay option flags.
 * D_8025D0B0: frame update ready flag, cleared by scene rendering.
 * D_801EC818: gameplay-update flag (zero in menus, one during play).
 * D_801E7584 bit 0: transition pending; D_801EC7D3: stop state-frame counter.
 * D_801E7470: game-over display timer; D_80105C50: "doPolu" drawing tag.
 * D_801E58A8: menu state, reset after gameplay updates.
 */
/*
 * func_8012801C (save_level_results) updates time records and completion bits.
 * D_801E693C[level][0] maps a level ID to its saved record/bit index.
 * D_801E7532 is the level being left; D_801F94CC is its elapsed time.
 * D_801E7584 bit 1 marks successful completion.
 * D_801EAA48 / D_801EAA4C: completed / all-Garibs level masks per save slot.
 * D_801EAA50: saved score including the ten-point reward per collected Garib.
 * D_80299394 retains the departing level's Garib total for the results screen.
 */
typedef struct LevelTimeRecordView {
    /* 0x00 */ s16 time;
    /* 0x02 */ u8 initial0;
    /* 0x03 */ u8 initial1;
    /* 0x04 */ u8 initial2;
    /* 0x05 */ u8 terminator;
} LevelTimeRecordView; /* size = 0x06 */

/* func_801336E8: save_restore_invalid_records.
 * D_801EAA44 contains six 0x1C-byte save slots; D_801EAB08 is their default.
 * D_801FA9B8 holds the six saved slot CRCs. D_801FA9D0 / D_801FA9D4
 * hold the high-score / time-record CRCs.
 * func_80139D14 computes a zero-seeded, most-significant-byte-first CRC;
 * func_801D211C copies bytes like memcpy.
 * The time-record CRC covers 0xC0 bytes, but repair copies only the six
 * 0x1E-byte groups (five LevelTimeRecordView records apiece), leaving the
 * trailing 12 bytes untouched. High scores use GAME_HIGH_SCORE_TABLE_BYTES.
 */
/* func_8011FB8C: restore_saved_game. func_8013FBC0 clears bytes.
 * D_801EAB24 selects the 28-byte save slot; D_801EAA54 stores its lives,
 * D_801EAA57 its hub progress, D_801EAA50 its score, and D_801EAA44..46
 * its initials. D_801EAA5C/5E restore sound-effect/music volume to
 * D_801E65C0/C4. D_801E7536 holds six world-completion flags, extracted
 * from bit 3 of each five-bit group in D_801EAA48.
 * The 0x64-byte runtime block at D_80290188 starts with score, collected
 * Garibs, lives and health. The word at +0x58 is reset to 15; its role is
 * unresolved. ScalarS32 preserves the original aggregate score access.
 * D_8028FAC8 becomes the player-position pointer; D_8028FB24 is reset
 * from D_80101144. Preserve their existing declarations and storage. */
/* func_8011F9F4: reset_new_game_progress; func_8013FBC0: clear_bytes.
 * Save the current sound-effect/music volumes (D_801E65C0/C4), clear the
 * selected slot's completion mask (D_801EAA48) and progress bytes
 * (D_801EAA56/57), and reset the runtime score/Garib/lives/health block.
 * D_801E7500 supplies starting lives at byte 0 of each four-byte difficulty
 * record; D_801EAA55 selects the record and D_801EAA54 stores the lives.
 * D_801E7535..3B are cleared in reverse order: an unresolved byte followed
 * by the six world-completion flags. D_80299398 is the level Garib total.
 * D_80290194 is health; D_802901E0 is the unresolved runtime +0x58 word.
 * D_8028FAC8 follows the player position at D_8029030C; D_80101140 supplies
 * D_8028FB24's new-game reset value. Keep the separate global accesses.
 */
enum NewGameResetConstants {
    NEW_GAME_PROGRESS_FLAG_LAST = 6
};

/* func_8013072C: level42_swap_saved_progress_platforms, on state frame zero.
 * D_802004E0 is the state frame counter; D_801EAB24 selects the save slot;
 * D_801E7533 selects the one-based world and its five-bit progress group.
 * D_801EAA48 is the completion mask; D_801EAA4C is the all-Garibs mask.
 * Entry 3 uses completion; the other four entries use all-Garibs.
 * func_8017DBA0 (platform_find_by_tag) locates paired tags 11..15 / 21..25.
 * Swap their PLATFORM_POSITION coordinates as Vec3Words to preserve bits.
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */
/* func_80124F2C: level_get_world. Levels below 10 and 44/45 belong to the hub
 * (world 0); 10..34 are worlds 1..5, five levels each; level 42 keeps the
 * current world (D_801E7533); other levels below 46 are world 6, the rest 7. */
enum LevelWorldConstants {
    LEVEL_FIRST_WORLD_LEVEL = 10,
    LEVELS_PER_WORLD = 5,
    LEVEL_KEEP_WORLD = 42,      /* '*' */
    LEVEL_HUB_44 = 44,          /* ',' */
    LEVEL_HUB_45 = 45,          /* '-' */
    LEVEL_WORLD7_FIRST = 46,
    WORLD_HUB = 0,
    WORLD_6 = 6,
    WORLD_7 = 7
};

enum Level42ProgressPlatformConstants {
    LEVEL42_WORLD_COMPLETION_ENTRY = 3,
    LEVEL42_PROGRESS_PLATFORM_TAG_BASE = 11,
    LEVEL42_ALTERNATE_PLATFORM_TAG_BASE = 21,
    LEVEL42_COMPLETION_PLATFORM_TAG = 14,
    LEVEL42_COMPLETION_ALTERNATE_TAG = 24
};

enum SaveRestoreConstants {
    SAVE_SLOT_HALFWORDS = 14,
    SAVE_WORLD_COUNT = 6,
    SAVE_WORLD_BITS = 5,
    SAVE_WORLD_COMPLETION_SHIFT_BIAS = 2,
    SAVE_RUNTIME_BYTES = 0x64,
    SAVE_MINIMUM_LIVES = 3,
    SAVE_RUNTIME_LIVES_WORD = 2,
    SAVE_RUNTIME_HEALTH_WORD = 3,
    SAVE_RUNTIME_UNK58_WORD = 0x16,
    SAVE_RUNTIME_UNK58_INITIAL = 0xF
};

enum SaveValidationConstants {
    SAVE_VALIDATION_SLOT_COUNT = 6,
    SAVE_TIME_RECORD_CRC_BYTES = 0xC0
};

/* func_8011C8F4: initialize a loaded level's player, ball, camera and effects.
 * func_801758D0 / func_801AE510 / func_80162BE0 reset player / ball / camera;
 * func_8015C924 recomputes an object's enclosing collision radius.
 * func_80182090 loads the level script; func_8017DBA0 finds a platform by tag.
 * func_80133998 selects an animation; func_801A7360 creates platform shadows.
 * func_80139CA0 hashes asset names; func_8014FCF8 resolves a texture by hash.
 * func_80181A40 smooths texture bytes in place using four wrapping neighbors.
 * func_801D2150 formats text; func_80139D70 is the disabled diagnostic sink.
 *
 * D_802902D8 / D_8029F978 are the player / ball objects.
 * D_801EC7DA is draw distance; D_801E7531 is the current level.
 * D_801EAA57 + D_801EAB24 * LEVEL_SAVE_SLOT_BYTES holds saved hub progress.
 * D_80297900 / D_80297904 / D_802988BC receive restart / bubble / lightning textures.
 * D_80100DFC / D_80100E08 / D_80100E14 name restart.bmp / bubble.bmp / lightning.bmp.
 * D_80100DEC is "IMP:level:%d\\n"; D_8025D578 is its diagnostic buffer.
 * D_80100E24 is the hidden hub-platform Y position (-5000).
 */
enum LevelInitializationConstants {
    LEVEL_HUB = 8,
    LEVEL_DEFAULT_DRAW_DISTANCE = 1000,
    HUB_PLATFORM_TAG_LIMIT = 8,
    HUB_PLATFORM_OPACITY = 0xA6, /* s16: embedded render object + 0x26 */
    HUB_PLATFORM_FLAGS_KEEP_MASK = 0xFFFDFFFF, /* clear platform flag 0x20000 */
    LEVEL_INITIAL_ANIMATION = 0x2A,
    RESTART_TEXTURE_SMOOTHING_PASSES = 50
};

enum LevelResultConstants {
    LEVEL_RESULT_COMPLETED = 2,
    LEVEL_SAVE_SLOT_BYTES = 0x1C,
    LEVEL_GARIB_SCORE = 10, SAVE_SLOT_EMPTY = 0xD /* first-initial byte of an unused save slot */
};

/* func_80128D34: world_bonus_level_unlocked. Each world owns a five-bit group
 * in the save masks: bits 0..2 its three levels, 3 the boss, 4 the bonus level.
 * D_80297BEC bit 0x2000000 is a cheat that unlocks every bonus level. */
enum WorldProgressBits {
    WORLD_PROGRESS_BITS = 5,
    WORLD_LEVEL1_BIT = 0,
    WORLD_LEVEL2_BIT = 1,
    WORLD_LEVEL3_BIT = 2,
    WORLD_BOSS_BIT = 3,
    WORLD_BONUS_BIT = 4,
    GAME_OPTION_ALL_BONUS_LEVELS = 0x2000000
};

/*
 * func_80180370: profiler_snapshot_and_reset.
 * D_802972A0: live profiler regions; D_80296C60: completed-region snapshots.
 * Unk802972A0 is a 0xA0-byte profiler region, with the existing layout:
 *   +0x00 s32 unk0: region is active.
 *   +0x04 s32 a[10]: sample start CPU counts.
 *   +0x2C s32 b[10]: sample end CPU counts.
 *   +0x54 s32 c[10]: accumulated elapsed CPU counts per sample.
 *   +0x7C: frame-start CPU count, accessed as D_8029731C[region][0].
 *   +0x80 u8 unk80 and following bytes: region label, cleared through
 *          D_80297320[region][0] and formatted by func_801804A0.
 *   +0x9F u8 unk9F: completed sample count / next sample index, accessed
 *          as D_8029733F[region][0].
 * The separate field symbols have a 0xA0-byte region stride. Preserve their
 * declarations and access forms; they alias the live region array.
 * D_80296C30: frame-start CPU count copied into each reset region.
 * func_80180644: profiler_draw_bars. When D_801EFCA0 (display mode, cycled
 * 0..2) is set, fills one 5-pixel-high bar per snapshot sample, 16 pixels
 * apart per region, in red/green/blue/yellow RGBA5551 by sample index.
 * D_80296C64 / D_80296CB4 / D_80296CDC are the snapshots' a[] / c[] / +0x7C
 * fields. One pixel is PROFILER_COUNTS_PER_PIXEL CPU counts; D_802586E8
 * (counts per retrace) also places frame markers.
 */
/* func_801C7110: libultra osInitialize. D_802AD3A0 = __osFinalrom;
 * func_801C7320 / func_801C73C0 = __osGetSR / __osSetSR; func_801C73B0 =
 * __osSetFpcCsr; func_801CF410 / func_801CF4C0 = __osSiRawReadIo /
 * __osSiRawWriteIo; func_801C6620 = __osExceptionPreamble (16 bytes, copied
 * to each exception vector); func_801C7330 = osInvalICache; func_801C73D0 =
 * osMapTLBRdb; func_801D03E0 = osPiRawReadIo; func_801D3B40 = __ull_div;
 * func_801D2020 = bzero. D_8000030C = osResetType, D_8000031C =
 * osAppNMIBuffer, D_801F43D8 = osViClock.
 */
enum OsInitializeConstants {
    OS_SR_CU1 = 0x20000000,
    OS_FPCSR_INIT = 0x01000800, /* flush denormals to zero, invalid-op trap */
    OS_PIF_STATUS_ADDR = 0x1FC007FC,
    OS_PIF_TERMINATE_BOOT = 8,
    OS_ROM_CLOCK_RATE_ADDR = 4,
    OS_APP_NMI_BUFFER_SIZE = 0x40,
    OS_TV_TYPE_PAL = 0,
    OS_TV_TYPE_MPAL = 2,
    OS_VI_PAL_CLOCK = 49656530,
    OS_VI_MPAL_CLOCK = 48628316,
    OS_VI_NTSC_CLOCK = 48681812
};

/* func_801C6550: libultra osCreateThread. func_801C6F60 = __osCleanupThread
 * (the return address of every new thread); D_801F43FC = __osActiveQueue,
 * the list of all threads linked through tlnext. */
enum OsCreateThreadConstants {
    OS_THREAD_INITIAL_SR = 0xFF03,  /* SR_IMASK | SR_EXL | SR_IE */
    OS_THREAD_INITIAL_RCP = 0x3F,   /* all RCP interrupts enabled */
    OS_THREAD_STACK_ARGS = 16       /* argument save area below the stack top */
};

enum ProfilerBarConstants {
    PROFILER_COUNTS_PER_PIXEL = 20000,
    PROFILER_BAR_LEFT = 100,
    PROFILER_BAR_TOP = 30,
    PROFILER_BAR_BOTTOM = 35,
    PROFILER_BAR_SPACING = 16
};
enum ProfilerLimits {
    PROFILER_REGION_COUNT = 10,
    PROFILER_SAMPLES_PER_REGION = 10
};

enum MainLoopState {
    GAME_STATE_MAIN_MENU = 1,
    GAME_STATE_LEVEL_SELECT = 2,
    GAME_STATE_PLAY = 4,
    GAME_STATE_UNK_5 = 5,
    GAME_STATE_LEVEL_RESULTS = 7,
    GAME_STATE_LOAD_LEVEL = 8,
    GAME_STATE_WORLD_RESULTS = 9,
    GAME_STATE_LOAD_HUB = 10,
    GAME_STATE_ERROR = 13,
    GAME_STATE_LANGUAGE_SELECT = 14,
    GAME_STATE_TIME_TRIAL_SELECT = 15
};

/*
 * func_8013DF34: input/save thread; polls controllers and executes one queued
 * EEPROM operation per scheduler frame. Symbol renaming is unavailable on N64.
 * D_801EC7F6: input/save worker paused flag; D_801FA9B0: operation queue head.
 * D_801EC7F0: input recording/playback mode (2 = playback).
 * D_801FB268: SI completion queue; D_801FB280: raw controller pad array.
 * D_80296C30: frame-start CPU counter used by the profiler.
 * func_801C62B0: osGetCount; func_801CF530 / func_801CF5B8:
 * osContStartReadData / osContGetReadData.
 * func_80180370: snapshot completed profiler entries and reset a finished frame.
 * func_801804A0 / func_80180534: begin / end a profiler region.
 * func_80135568 / func_8013407C: update playback / live controller state.
 * func_80132990: remove the completed operation from the save queue.
 * Save queue: D_801FA9B0 (u8[SAVE_QUEUE_LEN] of SaveOperation, head first;
 * D_801FA9B1 is its second slot), D_801EAB28 = number of queued operations.
 * func_80132940 pushes an operation, func_80132A9C clears the queue.
 * EEPROM handlers, in operation order: func_80132FF4, func_8013305C,
 * func_801330C4, func_8013312C, func_80133194, func_801331FC,
 * func_80133264, func_80133350, func_801333D0, func_801334F0.
 */
#define SAVE_QUEUE_LEN 6

typedef struct SchedulerClient {
    /* 0x00 */ struct SchedulerClient *next;
    /* 0x04 */ OSMesgQueue *queue;
} SchedulerClient; /* size = 0x08 */

enum SaveOperation {
    SAVE_OP_NONE = 0,
    SAVE_OP_WRITE_HIGH_SCORES = 1,
    SAVE_OP_READ_HIGH_SCORES = 2,
    SAVE_OP_WRITE_TIME_RECORDS = 3,
    SAVE_OP_READ_TIME_RECORDS = 4,
    SAVE_OP_WRITE_SLOTS = 5,
    SAVE_OP_READ_SLOTS = 6,
    SAVE_OP_READ_SIGNATURE = 7,
    SAVE_OP_WRITE_SIGNATURE = 8,
    SAVE_OP_WRITE_CHECKSUMS = 9,
    SAVE_OP_READ_CHECKSUMS = 10,
    SAVE_OP_UNK_11 = 11
};

/*
 * func_80181B4C: save a debug screenshot to the development host.
 * D_80108AA0: serialized BMP header (BM, 320x240, 24 bpp, uncompressed).
 * D_80108B08: numbered BMP filename format; D_801EFCBC: screenshot counter.
 * D_80092030: RGBA5551 framebuffer; D_801EC7A8: render-worker exit request.
 * D_80108AD8 / D_80108B18 / D_80108B40: drawing synchronization tags.
 * D_80108AE0 / D_80108AF4 / D_80108B20: separator / capture / open-error text.
 * func_8010D4DC / func_8010D728 / func_8010D5FC: host file open / write / close.
 * func_80155A44 / func_80155AE4: stop / restart drawing.
 * func_801D2150 / func_80139D70: sprintf / disabled diagnostic output hook.
 */
typedef struct ScreenshotBmpHeader {
    /* 0x00 */ u8 bytes[0x36];
    /* Serialized little-endian fields: signature +0, file size +2,
     * pixel offset +0x0A, DIB size +0x0E, width +0x12, height +0x16,
     * planes +0x1A, bits per pixel +0x1C, compression +0x1E,
     * image bytes +0x22, resolution +0x26/+0x2A, colors +0x2E/+0x32. */
} ScreenshotBmpHeader; /* size = 0x36, byte-aligned */

enum ScreenshotConstants {
    SCREENSHOT_WIDTH = 320,
    SCREENSHOT_LAST_ROW = 239,
    SCREENSHOT_LAST_ROW_OFFSET = 239 * 320,
    SCREENSHOT_ROW_BYTES = 320 * 3,
    SCREENSHOT_ROW_BUFFER_BYTES = 0x500,
    SCREENSHOT_FILENAME_BYTES = 0x10,
    SCREENSHOT_HEADER_BYTES = 0x36,
    RGBA5551_BLUE_SHIFT = 1,
    RGBA5551_GREEN_SHIFT = 6,
    RGBA5551_RED_SHIFT = 11,
    SCREENSHOT_CHANNEL_EXPAND_SHIFT = 3
};

enum InputWorkerConstants {
    INPUT_MODE_PLAYBACK = 2,
    INPUT_PROFILE_REGION = 2
};

enum MainLoopConstants {
    GAME_INPUT_THREAD_ID = 6,
    GAME_RENDER_THREAD_ID = 4,
    GAME_MESSAGE_CAPACITY = 8,
    GAME_MESSAGE_FRAME = 9,
    GAME_MESSAGE_BLOCK = 1,
    GAME_TRANSITION_PENDING = 1,
    GAME_TRANSITION_EXIT_LEVEL = 14,
    GAME_HIGH_SCORE_TABLE_BYTES = 0x30,
    GAME_HIGH_SCORE_COUNT = 6,
    GAME_TIME_RECORD_GROUP_BYTES = 0x1E
};

/*
 * EEPROM layout (8-byte blocks), read with func_801D0370 (osEepromLongRead) and
 * written with func_801D0280 (osEepromLongWrite) through the SI queue D_801FB268.
 * D_801EA9E0 is set when an EEPROM is present. Block 0 holds the save signature
 * (D_801EAB2C); D_801EAB29 is set when it is valid.
 */
enum EepromLayout {
    EEPROM_BLOCK_SIGNATURE = 0,
    EEPROM_BLOCK_HIGH_SCORES = 1,
    EEPROM_BLOCK_TIME_RECORDS = 7,
    EEPROM_BLOCK_SAVE_SLOTS = 0x1F,
    EEPROM_BLOCK_CHECKSUMS = 0x34,
    EEPROM_SIGNATURE_BYTES = 8,
    EEPROM_TIME_RECORDS_BYTES = 0xC0, /* 24 blocks: six 30-byte groups, padded */
    EEPROM_SAVE_SLOTS_BYTES = 0xA8,   /* six LEVEL_SAVE_SLOT_BYTES slots, 21 blocks */
    EEPROM_HIGH_SCORES_BYTES = 0x30,  /* six-entry high-score table, 6 blocks */
    EEPROM_CHECKSUMS_BYTES = 0x20     /* eight u32 CRCs (six slots, high scores, time records), 4 blocks */
};


/*
 * func_80188A5C reads platform properties from the level stream.
 * func_8017CF00 updates a platform; func_801B922C updates an effect emitter.
 * func_80133900 initializes ActorAnimation; func_80133998 starts/queues a clip.
 * func_80141720 frees and clears an allocation; func_80151FD0 resolves an
 * asset hash. func_8018E610 links a spike node (next, prev, platform; 0x0C).
 * D_801EFD44 is the current level record kind; D_801EFCE8 is its effect
 * emitter, D_801EFCF0 its non-platform collision record, and D_80297C18
 * is the eight-byte asset-name scratch buffer. D_802904D0 counts platforms.
 * Allocation tags in asm/1000.s: D_80109488 = "PlatAnim",
 * D_80109494 = "Plat_Dest", D_801094A0 = "spike", D_801094DC = "Plat_Str".
 * D_801094A8 warns of scale after the first platform path point.
 * Symbol renaming is unavailable for N64; these roles document the names.
 */
enum PlatformPropertyCommand {
    PLATFORM_CMD_ADVANCE_FRAMES = 0x5C,
    PLATFORM_CMD_DISABLE_COLLISION = 0x64,
    PLATFORM_CMD_DESTRUCTION = 0x65,
    PLATFORM_CMD_REVERSE_AT_PATH_END = 0x66,
    PLATFORM_CMD_SURFACE_TYPE = 0x6A,
    PLATFORM_CMD_ROLE = 0x6F,
    PLATFORM_CMD_SCALE = 0x79,
    PLATFORM_CMD_STRETCH = 0x7A,
    PLATFORM_CMD_SPIKE = 0x82,
    PLATFORM_CMD_GRAVITY = 0x9D,
    PLATFORM_CMD_UNK_A4 = 0xA4,
    PLATFORM_CMD_ANIMATION = 0xC0,
    PLATFORM_CMD_DESTRUCTION_PARAMS = 0xC8
};

enum LevelRecordKind {
    LEVEL_RECORD_PLATFORM = 0x62,
    LEVEL_RECORD_GARIB_GROUP = 0x85,
    LEVEL_RECORD_GARIB = 0x86,
    LEVEL_RECORD_COLLECTIBLE = 0x87,
    LEVEL_RECORD_EFFECT = 0xA2
};

/* func_80184FC0 (load_collectible_record) consumes a record payload and
 * advances an integer byte address. Records contain: group ID/active (two s16),
 * Garib position/type/unkF (three f32 and two u16), or collectible parameters
 * (three s16) followed by position. Collectible types 7 and 9 are skipped.
 *
 * D_80297C0C: current Garib group; D_80299478: group count.
 * D_80299398: collectible total (Garib type 2 is excluded here).
 * D_80109024 = "GaribGp%d"; D_80109030 = "Garib" (allocation tags).
 * D_80109038 = -1.0f; D_8010903C = 1.0f (initial field values).
 * D_801EFD64: 16-byte Garib sprite descriptors, indexed by type.
 * D_801EFD94: alternate type-0 descriptor, selected by option bit 0x2000.
 *
 * func_801D2150: sprintf; func_801D211C: memcpy; func_8013FCDC: allocator.
 * func_8018B3FC links a group; func_8018B47C initializes its member list;
 * func_8018B48C links a member. func_8014B7F0 initializes sprite animation;
 * func_8014AC1C links a sprite for drawing; func_8018DD54 creates a collectible
 * (allocation tag "Collect" at D_801097B4).
 */
/* func_8018DFAC (collect_garib) updates rewards and the all-Garibs celebration.
 * D_8029018C: collected Garibs; D_80299398: level total; D_80290190: lives.
 * D_80290194: health. D_80284DC0/DF0/E08 drive the Garib/health/lives HUD pulses.
 * D_801E7501: Garibs per extra life, at byte 1 of each four-byte difficulty
 * settings record; D_801EAA55 selects difficulty in the current 28-byte save
 * slot, indexed by D_801EAB24. D_801097C8 scales velocity for the celebration.
 * func_8018E260 adds score and grants lives at score thresholds.
 * func_80178134 plays positional sound; func_801793DC plays sound with pan.
 * func_80133998 selects an object animation. func_8015C4C8 tests particular
 * player states while the player supports the ball. func_80173CE8 raises
 * D_8028FBF4 to at least the requested duration during gameplay.
 * D_8029011E is frog form; D_801E7531 is level ID; D_802903AC + 4 is the
 * player state. Level 0x13, states 0x14/0x21 and nonzero D_80290304 suppress
 * the celebration; their more specific meanings remain unresolved.
 */
/* func_8018DD54: createCollectible. Its 0x100-byte allocation embeds an
 * ObjectNode prefix at +0x14. Byte offsets retain the original aliasing.
 * D_801097B4 = "Collect"; D_801EFD08 maps collectible types to model names.
 * D_80299290 is the collectible-list sentinel; D_80299390 counts its members.
 * D_801ED3D0 is the identity quaternion. D_801097BC is the initial scale,
 * D_801097C0 the squared pickup radius, and D_801097C4 the shadow size.
 * func_8015C840 links the embedded object into the render lists.
 * The +0x0E effect duration is passed to func_8018C700 when collected;
 * +0x12 is the respawn delay (zero removes the collectible).
 * +0xFC is the target render opacity; +0xF8 is the target scale.
 */
enum CollectibleFields {
    COLLECTIBLE_PREV = 0x04,
    COLLECTIBLE_PICKUP_RADIUS_SQUARED = 0x08,
    COLLECTIBLE_TYPE = 0x0C,
    COLLECTIBLE_ACTIVE = 0x0D,
    COLLECTIBLE_EFFECT_DURATION = 0x0E,
    COLLECTIBLE_TIMER = 0x10, /* >0: shrinking after pickup; <0: respawn countdown */
    COLLECTIBLE_RESPAWN_DELAY = 0x12,
    COLLECTIBLE_OPACITY = 0x3A,
    COLLECTIBLE_ROTATION = 0x8C,
    COLLECTIBLE_YAW = 0x90,
    COLLECTIBLE_OBJECT = 0x14,
    COLLECTIBLE_OBJECT_TYPE = 0x34,
    COLLECTIBLE_OBJECT_FLAGS = 0x3C,
    COLLECTIBLE_POSITION = 0x48,
    COLLECTIBLE_QUATERNION = 0xB0,
    COLLECTIBLE_SCALE_X = 0xD0,
    COLLECTIBLE_SCALE_Y = 0xD4,
    COLLECTIBLE_SCALE_Z = 0xD8,
    COLLECTIBLE_MODEL = 0xDC,
    COLLECTIBLE_SHADOW = 0xE0,
    COLLECTIBLE_TARGET_SCALE = 0xF8,
    COLLECTIBLE_TARGET_OPACITY = 0xFC
};

/* func_8018C584: init_collectible_effect_model(object, collectibleType, scale).
 * Loads the model only once, initializes its transform and links the object.
 * D_801EFD08 is the collectible-model-name table; func_80139CA0 hashes the
 * name and func_80151FD0 looks it up in the loaded scene model banks.
 * func_80142700 initializes object components; func_8015C840 links render lists.
 * D_801ED3D0 holds identity quaternion bits (0,0,0,1), copied as QuaternionWords.
 * D_8028FDD0 / D_8029F488 are paired effect objects; D_8028FE98 / D_8029F550
 * are their model handles at +0xC8, D_8028FE4C / D_8029F504 their yaw at +0x7C.
 * D_801096A4 and D_801096AC are f64 pi; func_801496C8 wraps by at most one turn.
 * The type base is also EFFECT_TYPE_ID_BASE in effect_visuals.h.
 */
enum CollectibleEffectModelConstants {
    COLLECTIBLE_EFFECT_TYPE_BASE = 1000,
    COLLECTIBLE_EFFECT_OBJECT_FLAGS = 0x10004,
    COLLECTIBLE_EFFECT_MODEL_REQUIRED = 1
};

enum CollectibleInitConstants {
    COLLECTIBLE_BYTES = 0x100,
    COLLECTIBLE_RENDER_TYPE = 0x3D,
    COLLECTIBLE_INITIAL_FLAGS = 0x10104,
    COLLECTIBLE_INITIAL_OPACITY = 101,
    COLLECTIBLE_SHADOW_OPACITY = 255,
    COLLECTIBLE_SHADOW_UNK0E = 30,
    COLLECTIBLE_SHADOW_SIZE_OFFSET = 8
};

enum GaribRewardConstants {
    GARIBS_PER_HEALTH_POINT = 10,
    GARIB_MAX_HEALTH = 3,
    GARIB_HUD_PULSE = 0x800,
    GARIB_SAVE_SLOT_BYTES = 28,
    GARIB_DIFFICULTY_SETTINGS_BYTES = 4,
    GARIB_COMPLETION_SCORE = 5000,
    GARIB_REWARD_SOUND_VOLUME = 100,
    GARIB_REWARD_SOUND_PAN = 128,
    GARIB_EXTRA_LIFE_SOUND = 0x8F,
    GARIB_EXTRA_LIFE_SOUND_B = 0x10D,
    GARIB_COMPLETION_SOUND = 0x110,
    GARIB_COMPLETION_ANIMATION = 0xD,
    GARIB_COMPLETION_STATE = 0x29,
    GARIB_COMPLETION_ACTION_TIMER = 0x3F5,
    GARIB_COMPLETION_MIN_TIMER = 20
};

enum GaribLoadConstants {
    GARIB_GROUP_BYTES = 0xD8,
    GARIB_BYTES = 0xB0,
    GARIB_GROUP_MEMBERS_OFFSET = 0x08,
    GARIB_GROUP_PENDING_OFFSET = 0xD0,
    GARIB_GROUP_ACTIVE_OFFSET = 0xD1,
    GARIB_GROUP_ID_OFFSET = 0xD2,
    GARIB_ALTERNATE_SPRITE_OPTION = 0x2000,
    GARIB_SPRITE_DESCRIPTOR_BYTES = 16,
    GARIB_TYPE_UNCOUNTED = 2
};

/* func_8018B4C4: activate_garib_group(groupId, heightOverride).
 * Zero height activates only pending groups and keeps their stored heights.
 * D_802993A0 is the group sentinel; D_802993A4 is its previous link.
 * D_801EFD64 supplies 16-byte sprite descriptors indexed by Garib type.
 * D_80109624 is the unit scale, f32 1.0 (pool word 0x3F800000).
 * func_8014B7F0 initializes sprite animation; func_8014AC1C links a sprite
 * for rendering; func_8015B524 queries ground distance and triangle/platform.
 * GaribLoadView describes members: unk10/unk14 are current/target scale,
 * unk50 is ground distance, and unkF selects the ground-update mode.
 * Raw offsets retain the existing casts and aliasing of list traversals.
 */
enum GaribActivationFields {
    GARIB_LIST_PREV_WORD = 1,
    GARIB_GROUP_TAIL_WORD = 3,
    GARIB_GROUP_HEIGHT_OFFSET = 0xC4,
    GARIB_VERTICAL_SPEED_WORD = 2,
    GARIB_ACTIVE_OFFSET = 0x0D,
    GARIB_TYPE_OFFSET = 0x0E,
    GARIB_GROUND_MODE_OFFSET = 0x0F,
    GARIB_SCALE_OFFSET = 0x10,
    GARIB_TARGET_SCALE_OFFSET = 0x14,
    GARIB_SPRITE_OFFSET = 0x18,
    GARIB_POSITION_OFFSET = 0x24,
    GARIB_HEIGHT_OFFSET = 0x28,
    GARIB_GROUND_DISTANCE_OFFSET = 0x50,
    GARIB_GROUND_TRIANGLE_OFFSET = 0x54,
    GARIB_LIST_LINK_BYTES = 4,
    GARIB_GROUP_PENDING = 1,
    GARIB_ACTIVE = 1, GARIB_VERTICAL_SPEED_OFFSET = 0x08, GARIB_Z_OFFSET = 0x2C, GARIB_SPRITE_SCALE_OFFSET = 0x30, GARIB_CAMERA_DISTANCE_OFFSET = 0xA8,
    GARIB_GROUP_CENTER_OFFSET = 0xC0, GARIB_GROUP_RADIUS_OFFSET = 0xCC, GARIB_COLLECTED = 0, GARIB_RESTING = -1 /* active byte: >= 2 counts down, -1 stopped bouncing */
};

/* Accessed prefix of the 0xB0-byte Garib allocation; field types are unchanged. */
typedef struct GaribLoadView {
    /* 0x00 */ u8 pad0[0xD];
    /* 0x0D */ s8 active;
    /* 0x0E */ u8 type;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 spriteLinks[8];
    /* 0x20 */ u8 *image;
    /* 0x24 */ f32 position[3];
    /* 0x30 */ u8 pad30[5];
    /* 0x35 */ u8 red;
    /* 0x36 */ u8 green;
    /* 0x37 */ u8 blue;
    /* 0x38 */ u8 pad38[2];
    /* 0x3A */ u8 centerOffsetX;
    /* 0x3B */ u8 centerOffsetY;
    /* 0x3C */ u8 pad3C[0x14];
    /* 0x50 */ f32 unk50;
} GaribLoadView; /* prefix size = 0x54 */



/* Platform is 0x180 bytes, with an embedded render object at +0x80.
 * Keep byte-offset accesses to preserve the matched C's aliasing.
 * Destruction state is 0x10 bytes; stretch state is 0x28 bytes.
 * Collision faces have stride 0x78 and a surface-type byte at +0x74. */
/* Scale oscillator state: +/-1 advances toward an endpoint; larger signed
 * values count down the pause before motion resumes. Zero disables motion. */
typedef struct PlatformStretchState {
    /* 0x00 */ f32 startScale[3];
    /* 0x0C */ f32 endScale[3];
    /* 0x18 */ s16 travelFrames;
    /* 0x1A */ s16 directionAndWait;
    /* 0x1C */ s16 waitFrames;
} PlatformStretchState; /* accessed prefix size = 0x20; allocation = 0x28 */

typedef struct PlatformScaleView {
    /* 0x000 */ u8 pad0[0x13C];
    /* 0x13C */ f32 scale[3];
} PlatformScaleView; /* accessed prefix size = 0x148 */

/* D_801087C0: gPlatformScaleSnapTolerance = 0.0001 (f64), the absolute
 * per-axis distance within which an endpoint is snapped. */
extern f64 D_801087C0;

enum PlatformPropertyField {
    PLATFORM_DESTRUCTION = 0x24,
    PLATFORM_STRETCH = 0x30,
    PLATFORM_RENDER_FLAGS = 0xA8,
    PLATFORM_SCALE = 0x13C,
    PLATFORM_MODEL = 0x148,
    PLATFORM_ANIMATION = 0x15C,
    PLATFORM_COLLISION_FACES = 0x160,
    PLATFORM_MODEL_COLLISION = 0x0C,
    PLATFORM_MODEL_ANIMATION = 0x18,
    PLATFORM_COLLISION_FACE_COUNT = 0x14,
    PLATFORM_FACE_SURFACE_TYPE = 0x74,
    PLATFORM_STRETCH_TARGET = 0x0C,
    PLATFORM_STRETCH_FRAMES = 0x18,
    PLATFORM_STRETCH_DIRECTION = 0x1A,
    PLATFORM_STRETCH_WAIT = 0x1C,
    PLATFORM_DESTRUCTION_MODEL = 0x04
};

enum PlatformPropertyConstants {
    PLATFORM_COLLISION_DISABLED = 4,
    PLATFORM_REVERSE_AT_PATH_END = 0x20,
    PLATFORM_GRAVITY_ENABLED = 1,
    PLATFORM_ANIMATION_BYTES = 0x50,
    PLATFORM_DESTRUCTION_BYTES = 0x10,
    PLATFORM_STRETCH_BYTES = 0x28,
    PLATFORM_SPIKE_NODE_BYTES = 0x0C,
    PLATFORM_FACE_BYTES = 0x78,
    LEVEL_ASSET_NAME_BYTES = 8
};

/* func_8018E380 checks spike proximity; func_8018E610 registers these nodes.
 * D_8029948C is the circular list sentinel; +8 is present only on real nodes.
 * D_801EFDC0 is the spike radius (20 normally, 15 in level 0x22).
 * D_801097F4/97FC/9804 are f64 values 1, 1.6 and 4: player/ball margin,
 * grounded-player speed threshold, and type-28 actor margin, respectively.
 * D_8029F9A8 is the ball radius and D_8029F486 is its damage/status byte.
 * func_801743A8 damages the player; func_801B0DDC handles ball damage;
 * func_80195D50 destroys an actor. func_80148E48 returns XYZ distance. */
typedef struct SpikeNode {
    /* 0x00 */ struct SpikeNode *next;
    /* 0x04 */ struct SpikeNode *prev;
    /* 0x08 */ u8 *platform;
} SpikeNode; /* size = 0x0C */

/* Words of the spike list header D_80299488 (s32[3]): the node count, then
 * the sentinel's next/prev at D_8029948C. func_8018E5F0 empties the list and
 * func_8018E610 (spike_list_add) links a node at its front. */
enum SpikeListWord {
    SPIKE_LIST_COUNT = 0,
    SPIKE_LIST_FIRST = 1, /* sentinel.next; its address is the sentinel */
    SPIKE_LIST_LAST = 2   /* sentinel.prev */
};

enum SpikeCollisionConstants {
    SPIKE_VULNERABLE_ACTOR_TYPE = 0x1C,
    SPIKE_ACTOR_COLLISION_POINTER = 0xD8,
    BALL_STATUS_DAMAGED = 2
};


/*
 * func_801B4D90 updates environmental effects and water interactions.
 * func_801BB1DC updates precipitation/lightning; func_801B5490 updates
 * underwater camera effects. func_801B5F74 handles an object's water contact;
 * func_801B4078 applies water forces; func_801B48DC emits a surface splash;
 * func_801B6A78 expires/replaces a pooled particle.
 * func_80148F10 tests a point against an origin/size box; func_80149568
 * normalizes a vector; func_80148D0C adds a scaled vector; func_80147000
 * returns a bounded random integer; func_801B66D4 spawns a pooled particle.
 * D_80299250 heads the water list; D_8026A148 heads the object list.
 * The water list is circular and doubly linked: D_80299250/D_80299254 are the
 * sentinel's next/prev, and D_8029928C (sentinel + 0x3C) counts its volumes.
 * func_801B4010 empties it; func_801B4030 links a volume at its front.
 * D_802900F0 tracks a particle outside that object list.
 * D_8028F914/918/91C are camera XYZ; D_801ED3C4 is the zero vector.
 * D_801F1B04 selects mesh-emitted particles (initially 10); D_801F1B08
 * offsets them along the camera-to-vertex direction (initially -6).
 * D_8010BBB4/BBB8 are height-step limits -1/+1; D_8010BBBC is the
 * water bounds margin 25; D_8010BBC0 is the height easing divisor 4.
 * Global types remain unchanged; symbol renaming is unavailable for N64.
 */
typedef struct WaterVolume {
    /* 0x00 */ struct WaterVolume *next;
    /* 0x04 */ struct WaterVolume *prev;
    /* 0x08 */ u8 *renderObject;
    /* 0x0C */ f32 boundsMin[3];
    /* 0x18 */ f32 boundsSize[3];
    /* 0x24 */ f32 current[3];
    /* 0x30 */ f32 surfaceY;
    /* 0x34 */ f32 targetY;
} WaterVolume; /* known prefix size = 0x38 */

/* Object-prefix offsets also apply to PooledParticle. Preserve the raw
 * accesses where the shared ObjectNode layout still has unknown fields. */
enum WaterObjectField {
    WATER_OBJECT_TYPE = 0x20,
    WATER_OBJECT_POSITION_X = 0x34,
    WATER_OBJECT_POSITION_Z = 0x3C,
    WATER_OBJECT_VELOCITY_Y = 0x5C,
    WATER_OBJECT_UNK68 = 0x68,
    WATER_OBJECT_COMPONENT_CC = 0xCC,
    WATER_OBJECT_PHYSICS = 0xD0,
    WATER_OBJECT_EMIT_PERIOD = 0x23,
    WATER_OBJECT_LIFETIME = 0x24,
    WATER_OBJECT_RADIUS = 0x30,
    WATER_OBJECT_PREVIOUS_Y = 0x44,
    WATER_OBJECT_MODEL = 0xC8,
    WATER_OBJECT_CONTACT_STATE = 0xD4,
    WATER_OBJECT_COLLISION_FACES = 0xE0,
    WATER_CONTACT_DEPTH = 9,
    WATER_PARTICLE_TYPE = 0xE5,
    WATER_PARTICLE_UNK110 = 0x110,
    WATER_FACE_VERTEX_START = 0x10
};

/* func_801B48DC emits surface-impact effects. func_801B52BC creates
 * expanding ripple decals; func_801B7494 sprays splash particles radially;
 * func_80178134 plays an attenuated positional sound.
 * D_80297BF0 is the loaded ai_ripple.bmp resource.
 * Float pool (prefix D_8010): BB7C=-1 suppresses effects via component CC;
 * BB80=2 scales particle impacts; BB84/BB88=1/5 clamp their ripple size;
 * BB8C=10 caps the physics factor; BB90=15 scales other impacts;
 * BB94/BB98=1/5 clamp their ripple size; BB9C=20 scales sound volume;
 * BBA0=40 is the minimum sound volume; BBA4=3 is the spray threshold;
 * BBA8=5 caps the spray count. The role of object field 0x68 is unresolved.
 */
/* func_801B7494: spawn_splash_particles(position, count, verticalSpeed).
 * func_80147000: random_below; func_801490AC: vec3_rotate_y;
 * func_801496C8: wrap_angle_once; func_801B66D4: spawn_particle.
 * D_801ED3C4 begins the zero vector. D_8010BD58 is one turn in radians
 * (f64); D_8010BD60 is the base radial speed, 4. Sprite flag 2 is applied
 * to odd particles; its visual meaning is not yet established. */
/* func_801B760C: spawnCameraOffsetParticleBurst. Its input is a Vec3F
 * position, accessed through a byte pointer to preserve the matched signature.
 * D_8028F914/18/1C are the camera position; D_801ED3C4 is the zero vector.
 * func_80149568 normalizes a vector; func_801490AC rotates it about Y.
 * D_8010BD64 is the offset toward the camera (5); D_8010BD68/6C are
 * horizontal/upward speeds (6/3). Directions use angles 0..5 radians.
 * func_801BB5C4 spawns type 21 with a random palette color and scales its
 * initial/final sprite sizes by the third argument (4.0 for this burst).
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */
enum CameraOffsetParticleBurstConstants {
    CAMERA_OFFSET_BURST_PARTICLE_COUNT = 6
};

enum SplashParticleConstants {
    SPLASH_PARTICLE_TYPE = 3,
    SPLASH_START_ANGLE_BOUND = 6,
    SPLASH_RADIAL_SPEED_RANGE = 3,
    SPLASH_VERTICAL_SPEED_RANGE = 9,
    SPLASH_ALTERNATE_SPRITE_FLAG = 2
};

/* libultra sprite (Sprite in sp.h), used by src/18020_C8EB0.c:
 * func_801CC010 spColor, func_801CC030 spClearAttribute, func_801CC050
 * spScale, func_801CC0D0 spSetAttribute, func_801CC0E0 spSetZ,
 * func_801CC0E8 spMove. scalex/scaley are f32 words 2 and 3, attr is the
 * u16 halfword 10 (offset 0x14). */
enum SpriteConstants {
    SPRITE_SCALE_X_WORD = 2,
    SPRITE_SCALE_Y_WORD = 3,
    SPRITE_ATTR_HALFWORD = 10,
    SPRITE_ZDEPTH = 0x16, /* s16 zdepth at 0x16 */
    SPRITE_RED = 0x18, /* u8 red, green, blue, alpha at 0x18..0x1B */
    SPRITE_GREEN = 0x19,
    SPRITE_BLUE = 0x1A,
    SPRITE_ALPHA = 0x1B,
    SP_TRANSPARENT = 0x01,
    SP_CUTOUT = 0x02,
    SP_SCALE = 0x10
};

/* func_801AACD4: random drip splash on an object (half the time: one splash
 * particle; on level 13 also, half of those times, the splash sound). */
enum RandomDripSplashConstants {
    DRIP_SPLASH_CHANCE_RANGE = 10,
    DRIP_SPLASH_CHANCE_THRESHOLD = 5,
    DRIP_SPLASH_SOUND_LEVEL = 13,
    DRIP_SPLASH_SOUND_VOLUME = 0x50,
    DRIP_SPLASH_SOUND_PITCH = 0x96,
    DRIP_SPLASH_PARTICLE_COUNT = 1,
    DRIP_SPLASH_OBJECT_POSITION_OFFSET = 0x34
};

enum WaterSplashConstants {
    WATER_SPLASH_SILENT_OBJECT_TYPE = 4,
    WATER_SPLASH_RIPPLE_FLAGS = 0x400,
    WATER_SPLASH_SOUND_ENTER = 2,
    WATER_SPLASH_SOUND_EXIT = 3,
    WATER_SPLASH_SOUND_PITCH = 0x80,
    WATER_SPLASH_MAX_PARTICLES = 5
};

/* func_801B5F74: update_object_water_contact. Its box test (func_80148FA8)
 * extends only the upper Y bound by the object's radius. func_801B4078
 * applies water forces; func_801B48DC emits splashes; func_801B614C emits
 * surface wakes. D_802902D8 is the player object, D_802903AC its action
 * state, and D_801ED3E0 supplies the shared upward surface normal.
 * Keep the byte-pointer fields: other consumers use their original types. */
typedef struct WaterContactObject {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u32 flags;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ f32 radius;
    /* 0x34 */ f32 posX;
    /* 0x38 */ f32 posY;
    /* 0x3C */ u8 pad3C[8];
    /* 0x44 */ f32 previousY;
    /* 0x48 */ u8 pad48[0x10];
    /* 0x58 */ f32 velX;
    /* 0x5C */ u8 pad5C[4];
    /* 0x60 */ f32 velZ;
    /* 0x64 */ u8 pad64[0x70];
    /* 0xD4 */ u8 *waterState;
    /* 0xD8 */ u8 *collisionState;
} WaterContactObject; /* known prefix size = 0xDC */

/* func_801B4078 (apply_water_forces): object field offsets and flags.
 * D_8029F978 is the ball object, D_802902D8 the player object. */
enum WaterForceObjectField {
    WFO_TYPE = 0x20,            /* s16 */
    WFO_TIMER = 0x24,           /* s16, set to 1 to expire the object */
    WFO_FLAGS = 0x28,           /* s32 */
    WFO_RADIUS = 0x30,
    WFO_POSITION = 0x34,        /* f32[3] */
    WFO_POSITION_Y = 0x38,
    WFO_POSITION_Z = 0x3C,
    WFO_PREVIOUS_Y = 0x44,
    WFO_VELOCITY_X = 0x58,
    WFO_VELOCITY_Y = 0x5C,
    WFO_VELOCITY_Z = 0x60,
    WFO_UNK74 = 0x74,
    WFO_SPIN = 0xB8,
    WFO_COMPONENT_CC = 0xCC,
    WFO_PHYSICS = 0xD0,         /* f32 density at +0x2C */
    WFO_WATER_STATE = 0xD4,     /* u8[]: depth at +9, in-water flag at +0xA */
    WFO_SUPPORT = 0xD8,         /* s32 support at +0, u8 flag at +0x188 */
    WFO_PHYSICS_DENSITY = 0x2C,
    WFO_SUPPORT_FLAG = 0x188,
    WATER_STATE_DEPTH = 9,
    WATER_STATE_IN_WATER = 0xA
};

/* Typed views of a byte-pointer object's fields. */
#define OBJ_F32(obj, off) (*(f32 *)((obj) + (off)))
#define OBJ_S32(obj, off) (*(s32 *)((obj) + (off)))
#define OBJ_S16(obj, off) (*(s16 *)((obj) + (off)))
#define OBJ_PTR(obj, off) (*(u8 **)((obj) + (off)))
/* WaterVolume fields through an untyped pointer (see struct WaterVolume). */
#define WATER_SURFACE_Y(w) (*(f32 *)((u8 *)(w) + 0x30))
#define WATER_CURRENT_X(w) (*(f32 *)((u8 *)(w) + 0x24))
#define WATER_CURRENT_Y(w) (*(f32 *)((u8 *)(w) + 0x28))
#define WATER_CURRENT_Z(w) (*(f32 *)((u8 *)(w) + 0x2C))

/* func_8015F098 (teleport step): the object state at 0xD4 holds the
 * teleport timer (TELEPORT_STATE_TIMER, s8: >0 shrinking, <0 growing) and
 * the active teleport definition (TELEPORT_STATE_DEFINITION). Fields of a
 * teleport definition, read through byte pointers: */
enum TeleportDefinitionField {
    TELEPORT_DEF_DEST = 0x0,          /* f32[3], relative to the anchor when set */
    TELEPORT_DEF_FLAGS = 0xC,         /* u16, enum TeleportFlags */
    TELEPORT_DEF_SHRINK_FRAMES = 0x10,/* s16 */
    TELEPORT_DEF_GROW_FRAMES = 0x12,  /* s16 */
    TELEPORT_DEF_GROW_FRAMES_LOW_BYTE = 0x13,
    TELEPORT_DEF_ANCHOR = 0x14,       /* object the destination follows */
    TELEPORT_SOUND_ARRIVE = 0x13E,
    OBJ_FIELD_PREVIOUS_POSITION = 0x40,
    OBJ_FIELD_SCALE_X = 0xBC,
    OBJ_FIELD_SCALE_Y = 0xC0,
    OBJ_FIELD_SCALE_Z = 0xC4
};

/* func_801246AC: hub-world level portal. Fields through an untyped pointer. */
#define PORTAL_KIND(p) (*(s32 *)((u8 *)(p) + 24))   /* portal / level id */
#define PORTAL_Y(p) (*(f32 *)((u8 *)(p) + 184))
#define PORTAL_RADIUS(p) (*(f32 *)((u8 *)(p) + 176))
enum PortalField {
    PORTAL_POSITION = 0xB4,
    PORTAL_DOOR_OBJECT = 56,
    PORTAL_DOOR_TIMER = 80
};

/* func_801BB9AC: cheats it executes (index into the 44-byte cheat records;
 * D_801F21BC is a record's name, D_801F21E4 its kind, D_80297BEC the bits of
 * the cheats switched on). Kind 0 toggles, kind 1 runs once. */
enum CheatId {
    CHEAT_POWERUP_8 = 4,
    CHEAT_CALL_BALL = 5,
    CHEAT_WORLD_BALL = 7,      /* the ball takes this world's model */
    CHEAT_LOW_GRAVITY = 8,
    CHEAT_BIG_BALL = 9,
    CHEAT_FISH_EYE = 10,       /* 120 degree FOV */
    CHEAT_TURN_LEFT = 11,      /* rotate D_801EC7B0 by -45 degrees */
    CHEAT_TURN_RIGHT = 12,
    CHEAT_ALT_TEXTURES = 13,
    CHEAT_POWERUP_1 = 14,
    CHEAT_POWERUP_2 = 15,
    CHEAT_POWERUP_4 = 16,
    CHEAT_POWERUP_5 = 17,
    CHEAT_POWERUP_13 = 18,
    CHEAT_POWERUP_14 = 19,
    CHEAT_TIMER_8029011C = 20  /* sets the D_8029011C timer to 1000 */
};

enum CheatKind {
    CHEAT_KIND_TOGGLE = 0,
    CHEAT_KIND_ONE_SHOT = 1
};

enum WaterForceObjectFlags {
    WFO_FLAG_DIES_IN_WATER = 0x80,
    WFO_FLAG_SPINS = 0x4000,
    WFO_FLAG_FLOATS = 0x200000
};

enum WaterDepth {
    WATER_DEPTH_TOUCHING = 1,  /* centre above the surface */
    WATER_DEPTH_HALF = 2,      /* centre below, top above */
    WATER_DEPTH_SUBMERGED = 3, /* top below the surface */
    WATER_DEPTH_FLOATING = 4   /* object floats (WFO_FLAG_FLOATS) */
};

enum WaterForceConstants {
    WATER_BUBBLE_PARTICLE = 0x14,
    WATER_RIPPLE_FLAGS = 0x400,
    PLAYER_STATE_BALL_WATER = 0xE,
    PLAYER_STATE_3 = 3,
    PLAYER_STATE_20 = 0x14,
    SOUND_BALL_SPLASH = 3
};

enum WaterContactConstants {
    WATER_BOUNDS_FLOAT_INDEX = 3,
    WATER_SURFACE_FLOAT_INDEX = 12,
    WATER_DISABLE_CURRENT_SHIFT = 28,
    WATER_PLAYER_SKIP_STATE = 3,
    WATER_SUPPORT_PLATFORM_OFFSET = 0x178
};

enum WaterInteractionConstants {
    WATER_OBJECT_SKIP = 0x10000,
    WATER_OBJECT_INTERACTION_MASK = 0x200010,
    WATER_PARTICLE_EXPIRE_ON_ENTRY_MASK = 0x200080,
    WATER_PARTICLE_IGNORED_TYPE_0 = 0,
    WATER_PARTICLE_IGNORED_TYPE_21 = 21,
    WATER_PARTICLE_NO_SPLASH_TYPE = 16,
    WATER_FACE_VERTEX_COUNT = 3,
    WATER_VERTEX_BYTES = 12
};


/* Hint objects: func_801B7C0C animates them and starts their dialog;
 * func_801B80A4 advances/draws the dialog. D_802AA918 is the list sentinel,
 * D_801F20F0 reports an active hint this frame, D_802AA700 is the hint index.
 * D_802AA798/79C hold the normal/alternate sprite images.
 * D_802004E0 is the frame counter; D_8029030C is the player position;
 * D_80202218 selects a 400-byte controller record (D_801FAAC7: activation).
 * D_801EC7D2 blocks new dialog activation while the current dialog runs.
 * func_80149724 computes sin((phase + offset) / divisor);
 * func_801490AC rotates about Y; func_80147000 returns a bounded random int;
 * func_801B66D4 spawns a particle; func_80148E48 measures 3D distance;
 * func_80178134 plays a positional sound.
 * Float pool: BDD4=5 (sway divisor/particle drop), BDD8=10 (sway/height),
 * BDDC=48 (sprite size), BDE0=2^31 (unsigned conversion), BDE4/BDF8=3
 * (phase divisors), BDE8=2 (bob divisor), BDEC/BDF0=1/-0.5 (velocity),
 * BDF4=4 (bob height), BDFC=5 (alpha divisor), BE00/04/08=1/30/60
 * (alpha bias/range/base), BE0C=20 (activation distance); prefix D_8010.
 */
typedef struct HintPosition {
    f32 x, y, z;
} HintPosition; /* size = 0x0C */

typedef struct HintObject {
    /* 0x00 */ struct HintObject *next;
    /* 0x04 */ u8 pad04[4];
    /* 0x08 */ HintPosition position;
    /* 0x14 */ u8 state;
    /* 0x15 */ u8 activated;
    /* 0x16 */ s16 dialogFrame;
    /* 0x18 */ u16 hintIndex;
    /* 0x1A */ u8 pad1A[0x12];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ u8 pad2E[0x52];
    /* 0x80 */ s32 spriteImage;
    /* 0x84 */ HintPosition spritePosition;
    /* 0x90 */ s16 spriteScaleX;
    /* 0x92 */ s16 spriteScaleY;
    /* 0x94 */ u8 pad94[4];
    /* 0x98 */ u8 spriteAlpha;
    /* 0x99 */ u8 pad99[0x17];
    /* 0xB0 */ u16 animationFrame;
} HintObject; /* known prefix size = 0xB4; allocated size = 0xB8 */

/* Byte-aligned view starting at D_801E7531; retain the halfword access cast. */
typedef struct HintLevelStateView {
    /* 0x00 */ s8 level;
    /* 0x01 */ s8 pad01[0x10];
    /* 0x11 */ s8 introHintCondition[2];
} HintLevelStateView; /* size = 0x13 */

enum HintObjectState {
    HINT_IDLE = 0,
    HINT_DIALOG_ACTIVE = 1,
    HINT_DIALOG_FINISHED = 2
};

enum HintAnimationConstants {
    HINT_PARTICLE_TYPE = 7,
    HINT_PARTICLE_JITTER_RANGE = 7,
    HINT_PARTICLE_JITTER_CENTER = 3,
    HINT_IMAGE_FLASH_CHANCE = 20,
    HINT_IDLE_ALPHA = 240,
    HINT_ACTIVATED_UNK2C_2D = 140,
    HINT_CONTROLLER_STRIDE = 400,
    HINT_FIRST_INDEX = 0,
    HINT_LEVEL0_AUTO_FRAME = 330,
    HINT_LEVEL9_AUTO_FRAME = 67,
    HINT_ACTIVATE_SOUND = 59,
    HINT_ACTIVATE_VOLUME = 100,
    HINT_ACTIVATE_PITCH = 190
};


/* libultra alFxNew (func_801C7F54) builds a circular delay buffer from
 * section count, buffer length, then eight words per section: input/output
 * offsets, feedback/feedforward/output gains, modulation rate/depth, cutoff.
 * D_801F4420/4488/4510/4538/4560/4588 are small-room, big-room, echo,
 * chorus, flange and disabled presets. D_8010C468 scales modulation depth.
 * func_801CA040 initializes filter dispatch; func_801CB280 allocates aligned
 * audio-heap storage; func_801CA480 pulls effect samples; func_801CA830
 * attaches the upstream filter; func_801CA844 changes effect parameters.
 */
typedef struct AudioEffectFilter {
    /* 0x00 */ void *source;
    /* 0x04 */ void *handler;
    /* 0x08 */ void *setParam;
    /* 0x0C */ s16 inputBuffer;
    /* 0x0E */ s16 outputBuffer;
    /* 0x10 */ s32 type;
} AudioEffectFilter; /* size = 0x14 */

typedef struct AudioEffectResampler {
    /* 0x00 */ AudioEffectFilter filter;
    /* 0x14 */ void *state;
    /* 0x18 */ f32 ratio;
    /* 0x1C */ s32 unityPitch;
    /* 0x20 */ f32 delta;
    /* 0x24 */ s32 first;
    /* 0x28 */ void *controlList;
    /* 0x2C */ void *controlTail;
    /* 0x30 */ s32 motion;
} AudioEffectResampler; /* size = 0x34 */

typedef struct AudioEffectLowPass {
    /* 0x00 */ s16 cutoff;
    /* 0x02 */ s16 gain;
    /* 0x08 */ union {
        s16 values[16];
        s64 alignment;
    } coefficients;
    /* 0x28 */ void *state;
    /* 0x2C */ s32 first;
} AudioEffectLowPass; /* size = 0x30, aligned to 8 bytes */

typedef struct AudioEffectDelay {
    /* 0x00 */ u32 input;
    /* 0x04 */ u32 output;
    /* 0x08 */ s16 feedforward;
    /* 0x0A */ s16 feedback;
    /* 0x0C */ s16 gain;
    /* 0x10 */ f32 modulationIncrement;
    /* 0x14 */ f32 modulationValue;
    /* 0x18 */ s32 resampleDelta;
    /* 0x1C */ f32 modulationGain;
    /* 0x20 */ AudioEffectLowPass *lowPass;
    /* 0x24 */ AudioEffectResampler *resampler;
} AudioEffectDelay; /* size = 0x28 */

typedef struct AudioEffect {
    /* 0x00 */ AudioEffectFilter filter;
    /* 0x14 */ s16 *base;  /* Circular delay buffer in DRAM. */
    /* 0x18 */ s16 *input; /* Current write position. */
    /* 0x1C */ u32 length; /* Buffer capacity in s16 samples. */
    /* 0x20 */ AudioEffectDelay *delay;
    /* 0x24 */ u8 sectionCount;
    /* 0x28 */ void *parameterHandler;
} AudioEffect; /* size = 0x2C */

/* func_801C3C34 applies a packed preset to the first auxiliary effect.
 * D_802AD370 holds its synthesizer and reusable effect allocations.
 * func_801C7EB0 initializes the low-pass coefficients from the cutoff.
 * Address words retain the existing storage ABI. */
typedef struct AudioEffectStorage {
    /* 0x00 */ s32 *synth;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 delaySections;
    /* 0x14 */ s32 delayBuffer;
    /* 0x18 */ AudioEffectResampler *resampler;
    /* 0x1C */ s32 resamplerState;
    /* 0x20 */ AudioEffectLowPass *lowPass;
    /* 0x24 */ s32 lowPassState;
} AudioEffectStorage; /* size = 0x28 */

enum AudioEffectStorageOffsets {
    AUDIO_FX_SYNTH_AUX_BUS_OFFSET = 0x34,
    AUDIO_FX_SYNTH_OUTPUT_RATE_OFFSET = 0x44,
    AUDIO_FX_AUX_BUS_EFFECT_OFFSET = 0x20,
    AUDIO_FX_RESAMPLER_STATE_OFFSET = 0x14,
    AUDIO_FX_RESAMPLER_DELTA_OFFSET = 0x20,
    AUDIO_FX_RESAMPLER_FIRST_OFFSET = 0x24,
    AUDIO_FX_LOW_PASS_STATE_OFFSET = 0x28
};

/* This constructor reads the sample rate at 0x18. */
typedef struct AudioEffectConfig {
    /* 0x00 */ s32 maxVVoices;
    /* 0x04 */ s32 maxPVoices;
    /* 0x08 */ s32 maxUpdates;
    /* 0x0C */ s32 maxFXbusses;
    /* 0x10 */ void *dmaProc;
    /* 0x14 */ u32 *heap;
    /* 0x18 */ s32 outputRate;
    /* 0x1C */ u8 fxType;
    /* 0x20 */ s32 *params;
} AudioEffectConfig; /* size = 0x24 */

/*
 * func_801CA480 (alFxPull) emits commands for a circular, multi-section reverb.
 * Delay input/output offsets and buffer length are measured in s16 samples;
 * inputBuffer/outputBuffer and the DMEM constants below are byte addresses.
 * Feedforward, feedback and output gain are signed Q15 mixing coefficients.
 * func_801CAC4C loads a wrapped delay segment; func_801CADBC saves one.
 * func_801CAA34 loads a section output, resampling when modulation is enabled.
 * func_801CAF2C emits the optional low-pass filter commands.
 * func_801CA030 is the empty assertion handler; D_8010C5B0/5B4 contain
 * "EX" and "reverb.c", with original assertion line 75.
 *
 * The stereo fold adds -0x257D times left to itself, then 0x5A82 times right,
 * leaving approximately 0.7071 times each channel in the mono delay input.
 */
typedef u32 *(*AudioEffectPullHandler)(s32 *filter, s32 outputAddress,
                                      s32 sampleCount, s32 sampleOffset,
                                      u32 *commands);

/*
 * func_801CAA34: audio_fx_load_output (libultra _loadOutput).
 * func_801CAFC8 advances the triangular delay modulation; func_801CAC4C
 * loads samples with circular-buffer wrapping; func_801C7D90 is
 * osVirtualToPhysical. D_8010C5F0 is f64 1.0 (asm/1000.s), the unity ratio.
 * Resampler delta retains fractional samples between updates; resampleDelta
 * accumulates the difference between consumed and requested sample counts.
 */
/* func_801CA1D0 is libultra alResamplePull; func_801CA3BC sets its
 * parameters. D_8010C580 is the f64 maximum pitch ratio, 1.99996.
 * func_801C7D90 is osVirtualToPhysical. The resampler's first word at
 * 0x24 supplies the low-byte RSP initialization flag at 0x27 (big endian).
 * Input/output buffer values are DMEM byte offsets; delta holds the
 * fractional input sample count carried into the next pull. */
typedef u32 *(*AudioResamplePullHandler)(s32 *filter, s16 *outputBuffer,
                                        s32 sampleCount, s32 sampleOffset,
                                        u32 *commands);

enum AudioResampleConstants {
    AUDIO_RESAMPLE_DMEM_INPUT = 0x140,
    AUDIO_RESAMPLE_FIRST_FLAG_OFFSET = 0x27,
    AUDIO_CMD_RESAMPLE = 0x05000000
};

/* Word indices of libultra's ALResampler (s32 * view): ALFilter first
 * (source, handler, setParam, inp, outp), then the resampler's own state. */
enum AudioResamplerWord {
    RESAMPLER_SOURCE = 0,
    RESAMPLER_SET_PARAM = 2,  /* in the source filter: its setParam handler */
    RESAMPLER_STATE = 5,
    RESAMPLER_RATIO = 6,      /* f32 pitch ratio */
    RESAMPLER_UNITY_PITCH = 7,
    RESAMPLER_DELTA = 8,
    RESAMPLER_FIRST = 9,
    RESAMPLER_CTRL_LIST = 10, /* pending ALParam list head */
    RESAMPLER_CTRL_TAIL = 11,
    RESAMPLER_MOTION = 12     /* AL_STOPPED (0) / AL_PLAYING (1) */
};

/* libaudio reverb delay line (ALDelay), one per tap pair of an ALFx. */
typedef struct ALDelay {
    /* 0x00 */ u32 input;   /* tap positions, in samples */
    /* 0x04 */ u32 output;
    /* 0x08 */ s16 ffcoef;  /* feed-forward / feedback coefficients */
    /* 0x0A */ s16 fbcoef;
    /* 0x0C */ s16 gain;
    /* 0x10 */ f32 rsinc;   /* chorus modulation: phase increment per sample */
    /* 0x14 */ f32 rsval;   /* modulation phase, -2..2 */
    /* 0x18 */ s32 rsdelta;
    /* 0x1C */ f32 rsgain;  /* modulation depth */
    /* 0x20 */ void *rs;    /* resampler state, when modulated */
    /* 0x24 */ void *lp;    /* low-pass state, when filtered */
} ALDelay;

/* ALFilter type passed to alFilterNew for a resampler (libaudio AL_RESAMPLE). */
#define AL_RESAMPLE 1
/* ALFilter type passed to alFilterNew for the main bus (libaudio AL_MAINBUS). */
#define AL_MAINBUS 7

enum AudioEffectResampleConstants {
    AUDIO_FX_DMEM_RESAMPLE_INPUT = 0x280,
    AUDIO_RESAMPLE_RATIO_SCALE = 0x8000,
    AUDIO_OPCODE_SET_BUFFER = 8,
    AUDIO_OPCODE_RESAMPLE = 5
};

/* RSP (SP) interface registers, uncached KSEG1 addresses (libultra rcp.h). */
#define SP_MEM_ADDR_REG  0xA4040000 /* SP DMEM/IMEM address */
#define SP_DRAM_ADDR_REG 0xA4040004 /* RDRAM physical address */
#define SP_RD_LEN_REG    0xA4040008 /* DMA length, RDRAM -> SP */
#define SP_WR_LEN_REG    0xA404000C /* DMA length, SP -> RDRAM */
#define SP_STATUS_REG    0xA4040010
#define SP_PC_REG        0xA4080000 /* RSP program counter (IMEM offset) */
#define SP_STATUS_HALT   0x1        /* SP_STATUS_REG read: the RSP is halted */
#define SP_DMA_ALIGN_MASK 0x7      /* SP DMA addresses and lengths are 8-byte aligned */
#define OS_READ 0                  /* direction: device -> RDRAM */
#define OS_WRITE 1                 /* direction: RDRAM -> device */

/* Serial interface (SI) registers and the PIF RAM window (libultra rcp.h). */
#define SI_DRAM_ADDR_REG      0xA4800000 /* RDRAM physical address */
#define SI_PIF_ADDR_RD64B_REG 0xA4800004 /* start a 64-byte PIF RAM -> RDRAM DMA */
#define SI_PIF_ADDR_WR64B_REG 0xA4800010 /* start a 64-byte RDRAM -> PIF RAM DMA */
#define PIF_RAM_START         0x1FC007C0
#define PIF_RAM_BYTES         0x40
#define SI_STATUS_REG         0xA4800018 /* SI status (read) */
#define SI_STATUS_DMA_BUSY    0x1        /* an SI DMA is in progress */
#define SI_STATUS_RD_BUSY     0x2        /* an IO read is in progress */

enum AudioEffectCommandConstants {
    AUDIO_CMD_SAVE_BUFFER = 0x06000000, /* Copy RSP DMEM to a physical DRAM address. */
    AUDIO_CMD_SET_BUFFER = 0x08000000,
    AUDIO_CMD_MIX = 0x0C000000,
    AUDIO_CMD_POLE_FILTER = 0x0E000000, /* One-pole IIR filter (aPoleFilter). */
    AUDIO_FX_FOLD_LEFT_COMMAND = 0x0C00DA83,
    AUDIO_FX_FOLD_RIGHT_COMMAND = 0x0C005A82,
    AUDIO_FX_DMEM_LEFT = 0x6C0,
    AUDIO_FX_DMEM_RIGHT = 0x800,
    AUDIO_FX_DMEM_DELAY_INPUT = 0,
    AUDIO_FX_DMEM_DELAY_OUTPUT = 0x140,
    AUDIO_FX_SOURCE_ASSERT_LINE = 75
};

enum AudioEffectPreset {
    AUDIO_FX_SMALL_ROOM = 1,
    AUDIO_FX_BIG_ROOM = 2,
    AUDIO_FX_ECHO = 3,
    AUDIO_FX_CHORUS = 4,
    AUDIO_FX_FLANGE = 5,
    AUDIO_FX_CUSTOM = 6
};

enum AudioEffectConstants {
    AUDIO_FILTER_EFFECT = 5,
    AUDIO_FX_RATE_SCALE = 1000,
    AUDIO_FX_RESAMPLE_STATE_BYTES = 0x20,
    AUDIO_FX_LOW_PASS_STATE_BYTES = 8,
    AUDIO_FX_LOW_PASS_HISTORY_COUNT = 8,
    AUDIO_FX_LOW_PASS_COEFFICIENT_COUNT = 16,
    AUDIO_FX_COEFFICIENT_ONE = 16384,
    AUDIO_FX_CUTOFF_SHIFT = 15
};


/* Software Creations music channels are 0x134 bytes; offsets below describe
 * the fields used by func_801C15B8 (mus_read_next_note). Raw accesses preserve
 * the existing declarations and compiler aliasing behavior.
 * D_801F40C0 is the sequence-command dispatch table; D_802AB03C points to
 * 28-byte libultra voices, D_802AB2C8 is the synthesizer, and D_802AB050
 * is the volume-ramp duration passed to alSynSetVol.
 * func_801BF88C loads a seven-byte envelope; func_801C1D48 starts it.
 * func_801C1FBC resets the pan sweep; func_801C19FC restarts the voice.
 * func_801CBD90/CBE50/CBBE0 set volume, set effect mix and stop a voice.
 */
typedef u8 *(*MusSequenceCommandHandler)(u8 *channel, u8 *stream);

/* Music-library initialization (func_801C0300, MusInitialize).
 * Address-valued configuration members retain their original s32 storage.
 * D_802AB028/02C: audio heap base/current pointer; D_802AB038: channel count;
 * D_802AB03C: libultra voices; D_802AB040: music channels;
 * D_802AB044/048: sound-effect sequence/priority tables;
 * D_802AB04C/050: video refresh rate/update interval in microseconds;
 * D_802AB058: next playback handle; D_802AB05C: random-generator state;
 * D_802AB060/064: current/default sample bank; D_802AB06C: effect preset;
 * D_802AB070: initialization flags; D_802AB010: synthesizer player callback.
 * D_80000300 is osTvType (zero selects PAL).
 *
 * Helpers: func_801C2A18 fills bytes; func_801CB240 initializes the audio heap;
 * func_801CB280 is alHeapDBAlloc; func_801C1100 creates the command queue;
 * func_801C249C relocates the sample bank; func_801C2C10 starts the audio manager;
 * func_801C066C sets song/effect master volumes; func_801CB9B0 is alSynAddPlayer;
 * func_801C1338 updates music channels; func_801C2768 resets a channel;
 * func_801CBA00 is alSynAllocVoice.
 */
/* func_801C249C (musRelocateSampleBank) initializes this bank once.
 * func_801C2A84 relocates nonzero offsets in an array by adding the bank base;
 * func_801C64F0 is osWritebackDCacheAll, making the changes visible to the RSP.
 * Address words are bank-relative offsets until relocation.
 */
typedef struct MusSampleBank {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ s32 flags;
    /* 0x14 */ u8 unk14[0x0C];
    /* 0x20 */ s32 sampleCount;
    /* 0x24 */ s32 baseNotes;       /* Byte array, with note 48 as the reference. */
    /* 0x28 */ s32 tuning;          /* Four-byte slots: signed cents byte -> f32 semitones. */
    /* 0x2C */ s32 waves;           /* Array of AudioSampleWave offsets/pointers. */
} MusSampleBank; /* size = 0x30 */

enum MusSampleBankConstants {
    MUS_SAMPLE_BANK_RELOCATED = 0x80000000,
    MUS_SAMPLE_BANK_POINTER_COUNT = 3,
    MUS_SAMPLE_REFERENCE_NOTE = 48,
    MUS_SAMPLE_ADDRESS_TAG_MASK = 0xFF000000,
    MUS_SAMPLE_SIGN_BIT = 0x80,
    MUS_SAMPLE_BYTE_RANGE = 0x100,
    MUS_SAMPLE_WAVE_ADPCM = 0,
    MUS_SAMPLE_WAVE_RELOCATED = 1,
    MUS_SAMPLE_WAVE_LOOP_WORD = 3,
    MUS_SAMPLE_WAVE_BOOK_WORD = 4
};

/* audio_init (func_801326F0) uses these game-specific audio settings. */
enum GameAudioSettings {
    GAME_AUDIO_FLAGS = 0,
    GAME_AUDIO_CHANNEL_COUNT = 24,
    GAME_AUDIO_SAMPLE_RATE = 22050,
    GAME_AUDIO_MAX_UPDATES = 1024,
    GAME_AUDIO_COMMAND_CAPACITY = 8192,
    GAME_AUDIO_FRAMES_PER_UPDATE = 3,
    GAME_AUDIO_DMA_BUFFER_COUNT = 40,
    GAME_AUDIO_HEAP_BYTES = 300000,
    GAME_AUDIO_DMA_BUFFER_BYTES = 1536
};

/* D_801FA940 through D_801FA984 hold the game's configuration in this layout. */
typedef struct MusConfig {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 channelCount;
    /* 0x08 */ s32 scheduler;
    /* 0x0C */ s32 threadPriority;
    /* 0x10 */ s32 heapAddress;
    /* 0x14 */ s32 heapBytes;
    /* 0x18 */ s32 sampleBank;
    /* 0x1C */ s32 sampleRomAddress;
    /* 0x20 */ s32 effectSequences;
    /* 0x24 */ s32 effectPriorities;
    /* 0x28 */ s32 commandQueueCapacity;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 maxUpdates;
    /* 0x34 */ s32 sampleRate;
    /* 0x38 */ s32 commandCapacity;
    /* 0x3C */ s32 framesPerUpdate;
    /* 0x40 */ s32 dmaBufferCount;
    /* 0x44 */ s32 dmaBufferBytes;
} MusConfig; /* size = 0x48 */

enum MusInitConstants {
    MUS_CHANNEL_BYTES = 0x134,
    MUS_REFRESH_PAL = 50,
    MUS_REFRESH_NTSC = 60,
    MUS_MICROSECONDS_PER_SECOND = 1000000,
    MUS_MASTER_VOLUME_EFFECTS = 1, /* MUSFLAG_EFFECTS: D_802AB054 */
    MUS_MASTER_VOLUME_SONGS = 2,   /* MUSFLAG_SONGS: D_802AB056 */
    MUS_MASTER_VOLUME_ALL = 3,
    MUS_MASTER_VOLUME_MAX = 0x7FFF,
    MUS_INITIAL_RANDOM_SEED = 0x12345678,
    MUS_VOICE_CONFIG_PRIORITY = 0,
    MUS_VOICE_CONFIG_FX_BUS = 1,
    MUS_VOICE_CONFIG_UNITY_PITCH_OFFSET = 4,
    MUS_PLAYER_NEXT = 0,
    MUS_PLAYER_CLIENT_DATA = 1,
    MUS_PLAYER_HANDLER = 2
};

/* func_801C1338 (mus_update_channels) is the synthesizer player callback.
 * It drains commands, advances unpaused channels, handles fade-out completion,
 * updates modulation and voices, and returns D_802AB050 microseconds to next tick.
 * func_801C1184 drains queued commands; func_801BF800 clears sequence state.
 * func_801C2144/21FC advance volume/pitch streams.
 * func_801C1DB4/1FD8 update the envelope/pan sweep.
 * func_801C20D8/2088 produce sine/square pitch modulation.
 * func_801C1C1C/1A90 apply pitch and volume/pan to the voice.
 */
/* func_801C1A90: mus_apply_volume_pan, applies channel gains and fade-out,
 * then sends changed volume/pan values to the libultra voice.
 * D_802AB054: sound-effect master volume; D_802AB056: song master volume.
 * D_802AB050: update interval and volume-ramp duration, in microseconds.
 * D_802AB03C: voice array; D_802AB2C8: synthesizer.
 * func_801CBD90: alSynSetVol; func_801CBEE0: alSynSetPan.
 * The pan cache is compared with sequence pan before scaling, as in the game.
 */
enum MusVoiceMixConstants {
    MUS_VOLUME_PRODUCT_SHIFT = 13,
    MUS_VOLUME_CLIP_THRESHOLD = 0x8000,
    MUS_MASTER_VOLUME_FRACTION_BITS = 15,
    MUS_PAN_FRACTION_BITS = 7,
    MUS_PAN_MASK = 0x7F
};

enum MusChannelUpdateConstants {
    MUS_CHANNEL_PAUSED = 1,
    MUS_NOTE_DURATION_HELD = 0x7FFF,
    MUS_FADE_INACTIVE = -1
};

/* func_801C28A0: mus_select_song_channel. D_802AB040 is the channel array;
 * D_802AB038 is its count. Prefer idle channels, then the lowest-priority
 * effect (last on ties), then a different song, then the same song track.
 * The different-song pass intentionally retains the original fixed pointer:
 * it repeatedly tests channel zero. The final fallback is trackIndex % count.
 * Song word 1 points to the table of track-start addresses.
 */
enum MusSongChannelConstants {
    MUS_SONG_TRACKS_WORD = 1,
    MUS_CHANNEL_PRIORITY_MAX = 0x7FFFFFFF,
    MUS_CHANNEL_NOT_FOUND = -1
};

enum MusChannelOffsets {
    MUS_CH_EFFECT_PRIORITY = 0x48, /* s32: smaller values are stolen first */
    MUS_CH_TRACK_START = 0x7C,     /* s32: initial note-stream address */
    MUS_CH_FADE_REMAINING = 0x10,   /* s32: updates remaining; -1 disables fade */
    MUS_CH_FADE_DURATION = 0x1C,    /* u32: initial fade duration, at least one */
    MUS_CH_HANDLE_VOLUME = 0x9A,    /* s16 at application: 128 is unity */
    MUS_CH_EFFECT_ID = 0xA2,        /* u16: zero selects the song master volume */
    MUS_CH_HANDLE_PAN = 0xAC,       /* s16 at application: 128 is unity */
    MUS_CH_SEQUENCE_VOLUME = 0xB8,  /* u8: sequence-controlled volume */
    MUS_CH_CACHED_PAN = 0xBA,       /* u8: last scaled pan sent to the voice */
    MUS_CH_VOLUME_STREAM_TIME = 0x14, /* u32: eight fractional bits */
    MUS_CH_PITCH_STREAM_TIME = 0x18, /* u32: eight fractional bits */
    MUS_CH_PITCH_OFFSET = 0x30,    /* f32: semitones */
    MUS_CH_PITCH_STREAM = 0x34,    /* u8 * */
    MUS_CH_VOLUME_STREAM = 0x38,   /* u8 * */
    MUS_CH_PAN_SWEEP_TIME = 0x90,  /* u32: eight fractional bits */
    MUS_CH_TIME_STEP = 0x98,       /* u16: per-update time increment */
    MUS_CH_SQUARE_PITCH_DURATION = 0xCA, /* u8: zero disables modulation */
    MUS_CH_SINE_PITCH_PERIOD = 0xD1, /* u8: zero disables modulation */
    MUS_CH_SINE_PITCH_DELAY = 0xB2,  /* u8: updates before the vibrato starts */
    MUS_CH_SINE_PITCH_DEPTH = 0x20,  /* f32: semitones, negative starts downward */
    MUS_CH_SINE_PITCH_STEP = 0xD8,   /* f32: phase advance per update */
    MUS_CH_NOTE_STREAM = 0x04,       /* u8 * */
    MUS_CH_PENDING_WAVETABLE = 0x08, /* s32: wavetable address */
    MUS_CH_TIME = 0x0C,             /* s32: ticks with eight fractional bits */
    MUS_CH_NOTE_PITCH = 0x2C,       /* f32: semitones */
    MUS_CH_NEXT_NOTE_TIME = 0x3C,   /* s32 */
    MUS_CH_NOTE_START_TIME = 0x40,  /* s32 */
    MUS_CH_SLIDE_START_PITCH = 0x4C, /* f32 */
    MUS_CH_SLIDE_PITCH = 0x50,      /* f32 */
    MUS_CH_RELEASE_TIME = 0x54,     /* s32 */
    MUS_CH_SONG = 0x74,            /* Song-data address */
    MUS_CH_SAMPLE_BANK = 0x78,     /* u8 * */
    MUS_CH_DRUM_MAP = 0x80,        /* u8 *: four-byte entries */
    MUS_CH_NOTE_DURATION = 0x96,   /* u16 */
    MUS_CH_CACHED_VOLUME = 0x9C,   /* u16 */
    MUS_CH_SLIDE_ELAPSED = 0xA6,   /* u16 */
    MUS_CH_DEFAULT_DURATION = 0xA8, /* u16: zero reads each note's duration */
    MUS_CH_SAMPLE_INDEX = 0xAA,    /* u16 */
    MUS_CH_CUTOFF_TICKS = 0xAE,    /* s16: fixed note cutoff time (libmus Fcutoff, likely); exclusive with the next */
    MUS_CH_CUTOFF_PERCENT = 0xB0,  /* s16: note cutoff as a percentage of the duration (likely) */
    MUS_CH_DURATION_OVERRIDE = 0xB3, /* u8: read one explicit duration */
    MUS_CH_TRANSPOSE = 0xB5,       /* u8: signed semitone bits */
    MUS_CH_TRANSPOSE_DISABLED = 0xB6, /* u8 */
    MUS_CH_NOTE_VOLUME = 0xB7,     /* u8 */
    MUS_CH_PAN = 0xB9,             /* u8 */
    MUS_CH_ENVELOPE_STATE = 0xBF,  /* u8 */
    MUS_CH_ENVELOPE_VOLUME = 0xC0, /* u8 */
    MUS_CH_ENVELOPE_COUNTDOWN = 0xC1, /* u8 */
    MUS_CH_VOICE_ACTIVE = 0xC5,    /* u8 */
    MUS_CH_EFFECT_MIX = 0xC6,      /* u8 */
    MUS_CH_EFFECT_MIX_OVERRIDE = 0xC7, /* u8 */
    MUS_CH_CACHED_EFFECT_MIX = 0xC8, /* u8 */
    MUS_CH_RELEASE_VOLUME = 0xC9,  /* u8 */
    MUS_CH_VIBRATO_INITIAL_DELAY = 0xCB, /* u8 */
    MUS_CH_VIBRATO_COUNTDOWN = 0xCC, /* u8 */
    MUS_CH_VIBRATO_STATE = 0xCD,   /* u8 */
    MUS_CH_EXPLICIT_NOTE_VOLUME = 0xCE, /* u8 */
    MUS_CH_DEFAULT_NOTE_VOLUME = 0xCF, /* u8 */
    MUS_CH_PAN_SWEEP_RATE = 0xD0,  /* u8: pan steps per update, six fractional bits */
    MUS_CH_PAN_SWEEP_FRACTION = 0xD5, /* u8: fractional pan step carried over */
    MUS_CH_PAN_SWEEP_FALLING = 0xD6, /* u8: 0 sweeps up to 127, 1 down to 0 */
    MUS_CH_HOLD_ENVELOPE = 0xD2,   /* u8 */
    MUS_CH_HOLD_VOICE = 0xD3,      /* u8 */
    MUS_CH_BASE_PITCH_OFFSET = 0x8C, /* f32: semitones; MusHandleSetFreqOffset adds to it */
    MUS_CH_SINE_PITCH_VALUE = 0x68, /* f32: current vibrato offset in semitones */
    MUS_CH_SQUARE_PITCH_DEPTH = 0xD4 /* s8: semitones while the square wave is high */
};

/* libultra RSP status bits (SP_STATUS_REG, read by __osSpGetStatus,
 * func_801CE900) and OSTask flags, as used by osSpTaskYielded (func_801CE8B0). */
enum SpStatusBits {
    SP_STATUS_YIELD = 0x80,    /* SIG0: yield requested */
    SP_STATUS_YIELDED = 0x100  /* SIG1: task has yielded */
};
enum OSTaskFlagBits {
    OS_TASK_YIELDED = 0x1,
    OS_TASK_DP_WAIT = 0x2
};

enum MusSequenceConstants {
    MUS_SEQUENCE_COMMAND_FLAG = 0x80,
    MUS_SEQUENCE_VALUE_MASK = 0x7F,
    MUS_SEQUENCE_REST = 0x60,
    MUS_TIME_FRACTION_BITS = 8,
    MUS_ENVELOPE_RELEASE = 4,
    MUS_VOICE_SIZE = 28,
    MUS_ENVELOPE_SIZE = 7,
    MUS_DRUM_ENTRY_SIZE = 4,
    MUS_DRUM_SAMPLE = 0,
    MUS_DRUM_ENVELOPE = 1,
    MUS_DRUM_PAN = 2,
    MUS_DRUM_NOTE = 3,
    MUS_SONG_ENVELOPES_OFFSET = 0x10,
    MUS_BANK_PITCH_TABLE_OFFSET = 0x28,
    MUS_BANK_WAVETABLE_TABLE_OFFSET = 0x2C,
    MUS_EFFECT_MIX_UNITY = 128,
    MUS_EFFECT_MIX_FRACTION_BITS = 7
};


/* Envelope view of a libmus channel; the full channel occupies MUS_CHANNEL_BYTES.
 * Times have eight fractional bits; timeScale is 1024 / updatePeriod.
 * func_801C1DB4 updates this envelope; func_801BF88C reads its seven-byte setup. */
typedef struct MusEnvelopeChannel {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 time;
    /* 0x10 */ u8 pad10[0x2C];
    /* 0x3C */ u32 noteEndTime;
    /* 0x40 */ u32 noteStartTime;
    /* 0x44 */ u8 pad44[0x10];
    /* 0x54 */ u32 releaseTime;
    /* 0x58 */ f32 attackSlope;
    /* 0x5C */ f32 decaySlope;
    /* 0x60 */ f32 releaseSlope;
    /* 0x64 */ u32 timeScale;
    /* 0x68 */ u8 pad68[0x2E];
    /* 0x96 */ u16 noteLength;      /* MUS_NOTE_LENGTH_HELD: the note never releases. */
    /* 0x98 */ u8 pad98[0x16];
    /* 0xAE */ u16 fixedLength;     /* Nonzero: release this long after the note starts. */
    /* 0xB0 */ u16 releaseFrames;   /* Else: release this long before the note ends. */
    /* 0xB2 */ u8 padB2[0x9];
    /* 0xBB */ u8 updatePeriod;
    /* 0xBC */ u8 initialVolume;
    /* 0xBD */ u8 attackVolume;
    /* 0xBE */ u8 sustainVolume;
    /* 0xBF */ u8 state;
    /* 0xC0 */ u8 volume;
    /* 0xC1 */ u8 updateCountdown;
    /* 0xC2 */ u8 attackDuration;
    /* 0xC3 */ u8 decayDuration;
    /* 0xC4 */ u8 releaseDuration;
    /* 0xC5 */ u8 padC5[0x4];
    /* 0xC9 */ u8 releaseVolume;
} MusEnvelopeChannel; /* size = 0xCC; prefix view, not the channel stride */

enum MusEnvelopeConstants {
    MUS_ENVELOPE_ATTACK = 1,
    MUS_ENVELOPE_DECAY = 2,
    MUS_ENVELOPE_SUSTAIN = 3,
    /* MUS_ENVELOPE_RELEASE = 4 is declared above. */
    MUS_ENVELOPE_FINISHED = 5,
    MUS_NOTE_LENGTH_HELD = 0x7FFF,
    MUS_RELEASE_NEVER = 0x7FFFFFFF,
    MUS_ENVELOPE_SCALE_BITS = 10,
    /* Fixed-point unity used to scale elapsed time by the update period. */
    MUS_ENVELOPE_SCALE_UNITY = 1024
};

/* libultra sample loader: func_801C86E0 is alAdpcmPull;
 * func_801C906C emits DMA/load/decode commands for an ADPCM block.
 * Address and callback words retain their existing 32-bit declarations. */
typedef struct AudioSampleLoop {
    /* 0x00 */ s32 start;
    /* 0x04 */ s32 end;
    /* 0x08 */ s32 count;
} AudioSampleLoop; /* size = 0x0C; ADPCM history follows this prefix */

typedef struct AudioAdpcmBook {
    /* 0x00 */ s32 order;
    /* 0x04 */ s32 predictorCount;
} AudioAdpcmBook; /* size = 0x08; signed 16-bit coefficients follow */

/* func_801C8EC0 (alLoadParam) selects the pull handler and restores loop state.
 * func_801C86E0 is alAdpcmPull; func_801C8B24 is alRaw16Pull.
 * func_801CB2D0 copies bytes from its first argument to its second.
 * The ADPCM loop history begins after the shared AudioSampleLoop prefix. */
enum AudioSampleLoaderConstants {
    AUDIO_SAMPLE_WAVE_ADPCM = MUS_SAMPLE_WAVE_ADPCM,
    AUDIO_SAMPLE_WAVE_PCM16 = 1,
    AUDIO_ADPCM_LOOP_HISTORY_OFFSET = 0x0C,
    AUDIO_ADPCM_BOOK_VECTOR_SAMPLES = 8
};

typedef struct AudioSampleWave {
    /* 0x00 */ s32 base;
    /* 0x04 */ s32 length;
    /* 0x08 */ u8 type;
    /* 0x09 */ u8 flags; /* Nonzero after bank pointers have been relocated. */
    /* 0x0C */ AudioSampleLoop *loop;
    /* 0x10 */ AudioAdpcmBook *book;
} AudioSampleWave; /* size = 0x14 */

typedef struct AudioSampleLoader {
    /* 0x00 */ s32 source;
    /* 0x04 */ s32 handler;
    /* 0x08 */ s32 setParam;
    /* 0x0C */ s16 inputBuffer;
    /* 0x0E */ s16 outputBuffer;
    /* 0x10 */ s32 type;
    /* 0x14 */ s32 decoderState;
    /* 0x18 */ s32 loopState;
    /* 0x1C */ s32 loopStart;
    /* 0x20 */ s32 loopEnd;
    /* 0x24 */ s32 loopCount;
    /* 0x28 */ AudioSampleWave *wave;
    /* 0x2C */ s32 bookBytes;
    /* 0x30 */ s32 dma;
    /* 0x34 */ s32 dmaState;
    /* 0x38 */ s32 samplePosition;
    /* 0x3C */ s32 frameOffset;
    /* 0x40 */ s32 first;
    /* 0x44 */ s32 sampleAddress;
} AudioSampleLoader; /* size = 0x48 */

typedef struct AudioCommand {
    /* 0x00 */ u32 w0;
    /* 0x04 */ u32 w1;
} AudioCommand; /* size = 0x08 */

/* libultra ALMainBus: pull each source, then add its stereo auxiliary output
 * to the main DMEM mix. Buffer addresses are bytes; counts are s16 samples. */
typedef struct AudioMainBus {
    /* 0x00 */ AudioEffectFilter filter;
    /* 0x14 */ s32 sourceCount;
    /* 0x18 */ s32 maxSources;
    /* 0x1C */ AudioSynthFilter **sources;
} AudioMainBus; /* size = 0x20 */

enum AudioMainBusConstants {
    AUDIO_MIX_GAIN_MAX = 0x7FFF /* Largest positive signed Q15 gain. */
};

/* func_801C8B24 is libultra alRaw16Pull: load mono PCM16 into RSP DMEM.
 * Its output argument starts as a pointer to a DMEM offset; the looping path
 * then reuses that variable to hold the offset itself. sampleOffset is unused.
 * DMA supplies a DRAM address; loads start on an eight-byte boundary and include
 * an extra alignment block even when the requested byte count is aligned.
 * A loopCount of -1 is unlimited. Samples past the wave end are cleared.
 * func_801C84A4 installs the DMA callback returned by its factory; this game's
 * factory func_801C35B8 returns the cached sample-DMA routine func_801C33A4.
 */
typedef s32 (*AudioSampleDmaCallback)(s32 sampleAddress, s32 byteCount, s32 state);

/* N64 audio interface registers and frequency-divider limits.
 * func_801CE300 is osAiSetFrequency. D_801F43D8 is osViClock, the
 * regional video clock in Hz: PAL 49656530, MPAL 48628316, NTSC 48681812.
 * The DAC and bit-rate registers store their respective divisors minus one.
 */
enum AiRegisterAddress {
    AI_DRAM_ADDR_REG = 0xA4500000,
    AI_LEN_REG = 0xA4500004,
    AI_CONTROL_REG = 0xA4500008,
    AI_STATUS_REG = 0xA450000C,
    AI_DACRATE_REG = 0xA4500010,
    AI_BITRATE_REG = 0xA4500014
};

enum AiFrequencyConstants {
    AI_DAC_DIVISOR_REJECT_MAX = 131,
    AI_BIT_CLOCKS_PER_SAMPLE = 66,
    AI_BIT_DIVISOR_CLAMP_THRESHOLD = 17,
    AI_BIT_DIVISOR_MAX = 16,
    AI_CONTROL_DMA_ON = 1
};

enum AudioRaw16Constants {
    AUDIO_PCM16_SAMPLE_BYTES = 2,
    AUDIO_DMA_ALIGNMENT = 8,
    AUDIO_DMA_ALIGNMENT_MASK = 7,
    AUDIO_COMMAND_HALFWORD_MASK = 0xFFFF,
    AUDIO_CMD_LOAD_BUFFER = 0x04000000
};

enum AudioAdpcmConstants {
    AUDIO_ADPCM_FRAME_SAMPLES = 16,
    AUDIO_ADPCM_FRAME_BYTES = 9,
    AUDIO_ADPCM_HISTORY_BYTES = 32,
    AUDIO_ADPCM_LOOP = 2,
    AUDIO_CMD_ADPCM = 0x01000000,
    AUDIO_CMD_SET_LOOP = 0x0F000000,
    AUDIO_COMMAND_FLAGS_MASK = 0xFF,
    AUDIO_CMD_CLEAR_BUFFER = 0x02000000,
    AUDIO_CMD_DMEM_MOVE = 0x0A000000,
    AUDIO_CMD_LOAD_ADPCM = 0x0B000000,
    AUDIO_COMMAND_ADDRESS_MASK = 0xFFFFFF,
    AUDIO_PHYSICAL_ADDRESS_MASK = 0x1FFFFFFF
};

/* Audio manager initialization (func_801C2C10).
 * params[] contains the requested sample rate, video frames per audio update,
 * and maximum command count. The refresh rate is 50 or 60 Hz.
 * AudioSynthConfig retains historical member names: outputRate at +10 actually
 * stores the DMA factory callback; initOsc at +18 stores the actual sample rate.
 *
 * D_802AD350: scheduler; D_802AD354: DMA buffer descriptors;
 * D_802AD358: DMA I/O messages; D_802AD35C: DMA completion message storage;
 * D_802AD360: DMA buffer bytes; D_802AD364: extra sample allowance;
 * D_802AD324/328/32C: minimum/nominal/maximum stereo sample counts;
 * D_802AD330: command capacity; D_802AD368/36C: cartridge/drive PI handles.
 * D_802AB090 holds two command-list pointers followed by four audio-task pointers.
 * Each task is 0x68 bytes: PCM buffer at +00, sample count at +04, scheduler task
 * at +08, completion message type at +60 and self pointer at +64.
 * D_802AB258/270: scheduler message queue/storage;
 * D_802AB290/2A8: task completion queue/storage; D_802AD338: DMA completion queue.
 * D_802AB0A8: audio thread; D_801F417C: thread-created flag;
 * D_802AB2C8: synthesizer; D_802AD318: stack top and DMA-list state.
 *
 * func_801D0AB0/func_801D1320 initialize cartridge/drive ROM handles;
 * func_801CE300 sets AI frequency; func_801CB280 allocates from the audio heap;
 * func_801C35B8 creates the sample-DMA callback; func_801C3710 opens synthesis;
 * func_801CB1EC links a list node; func_801C6520 creates a message queue;
 * func_801C6550/func_801C7860 create/start the thread at func_801C3040.
 */
typedef struct AudioDmaBuffer {
    /* 0x00 */ s32 next;
    /* 0x04 */ s32 prev;
    /* 0x08 */ s32 startAddress;
    /* 0x0C */ s32 lastFrame;
    /* 0x10 */ s32 ptr;
} AudioDmaBuffer; /* size = 0x14; retain integer address storage */

/*
 * func_801C3198: audio_build_and_submit_task. Queues the previous PCM buffer
 * to AI, builds the next command list, and sends its task to the scheduler.
 * func_801C35F0: drain DMA completions and recycle old sample buffers;
 * func_801C7D90: osVirtualToPhysical; func_801CE430: osAiSetNextBuffer;
 * func_801CE2F0: osAiGetLength; func_801CB5DC: alAudioFrame;
 * func_8017F660: scheduler_get_command_queue; func_801C7560: osSendMesg.
 * D_801F4178 selects one of the two command lists in D_802AB090.
 * D_8011C720 is RSP boot microcode; func_8011C7F0 marks its end.
 * D_801BE9E0 / D_801F3E00 are audio microcode text / data.
 * Word indices below address the 0x68-byte audio frame: PCM address at +0,
 * s16 sample count at +4, SchedulerTaskMessage at +8, RspTask at +0x18.
 * Raw word accesses preserve the original signed address representation.
 */
enum AudioFrameTaskFields {
    AUDIO_FRAME_PCM_WORD = 0,
    AUDIO_FRAME_SAMPLE_COUNT_OFFSET = 4,
    AUDIO_FRAME_SCHEDULER_OFFSET = 8,
    AUDIO_FRAME_NEXT_WORD = 2,
    AUDIO_FRAME_TASK_TYPE_WORD = 6,
    AUDIO_FRAME_TASK_FLAGS_WORD = 7,
    AUDIO_FRAME_BOOT_CODE_WORD = 8,
    AUDIO_FRAME_BOOT_CODE_SIZE_WORD = 9,
    AUDIO_FRAME_UCODE_WORD = 10,
    AUDIO_FRAME_UCODE_DATA_WORD = 12,
    AUDIO_FRAME_UCODE_DATA_SIZE_WORD = 13,
    AUDIO_FRAME_DRAM_STACK_WORD = 14,
    AUDIO_FRAME_DRAM_STACK_SIZE_WORD = 15,
    AUDIO_FRAME_OUTPUT_BUFFER_WORD = 16,
    AUDIO_FRAME_OUTPUT_BUFFER_SIZE_WORD = 17,
    AUDIO_FRAME_COMMAND_LIST_WORD = 18,
    AUDIO_FRAME_COMMAND_BYTES_WORD = 19,
    AUDIO_FRAME_YIELD_BUFFER_WORD = 20,
    AUDIO_FRAME_YIELD_BYTES_WORD = 21,
    AUDIO_FRAME_COMPLETION_QUEUE_WORD = 22,
    AUDIO_FRAME_COMPLETION_MESSAGE_WORD = 23,
    AUDIO_FRAME_SAMPLE_ALIGN_MASK = 0xFFF0,
    AUDIO_FRAME_RSP_TASK_TYPE = 2,
    AUDIO_FRAME_UCODE_DATA_BYTES = 0x800,
    AUDIO_FRAME_SEND_BLOCKING = 1
};

enum AudioManagerParamIndex {
    AUDIO_PARAM_SAMPLE_RATE = 0,
    AUDIO_PARAM_FRAMES_PER_UPDATE = 1,
    AUDIO_PARAM_COMMAND_CAPACITY = 2
};

/* func_801CEAA0 = osCreateViManager: initialize retrace/counter events and
 * start the VI manager once. Calls: func_801C7A80 = __osTimerServicesInit,
 * func_801C6520 = osCreateMesgQueue, func_801C7690 = osSetEventMesg,
 * func_801CEDD0 / func_801C76F0 = osGetThreadPri / osSetThreadPri,
 * func_801C6F70 / func_801C6F90 = __osDisableInt / __osRestoreInt,
 * func_801C6550 / func_801C7860 = osCreateThread / osStartThread,
 * func_801CEC38 = viMgrMain, func_801CE950 = __osViInit.
 *
 * D_801F4770 begins the 0x1C-byte OSDevMgr state. Its separately declared
 * words are active (+0), thread (+4), command queue (+8), event queue (+0xC),
 * access queue (+0x10), DMA callback (+0x14), extended DMA callback (+0x18).
 * Keep the scalar declarations: accessing them as fields changes codegen.
 * D_802AD678 is the thread; D_802AE830 the OSMesgQueue; D_802AE848 its buffer.
 * D_802AE860 / D_802AE878 begin retrace / counter OSIoMesg records:
 * type at +0, priority at +2, return queue at +4 (remaining fields unused).
 * The VI stack top is D_802AE830, expressed as D_802AD630 + 0x1200 because
 * the original formed it independently of the queue and thread addresses.
 */
/* VI manager thread (func_801CEC38 / viMgrMain).
 * func_801CEDF0 = __osViGetCurrentContext; func_801CF0C0 = __osViSwapContext;
 * func_801C7430 / func_801C7560 = osRecvMesg / osSendMesg;
 * func_801C62B0 = osGetCount; func_801C7AD4 = __osTimerInterrupt.
 * D_802AD670 counts retraces until the next client notification.
 * D_802AD5E0 = __osBaseCounter (last Count register sample);
 * D_802AD5E4 = __osViIntrCount; D_802AD5E8 = __osCurrentTime (u64 ticks).
 * Partial views retain the types used by the existing declarations.
 */
typedef struct ViRetraceContextView {
    /* 0x00 */ u8 unk00[2];
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ u8 unk04[0x0C];
    /* 0x10 */ u8 *messageQueue;
    /* 0x14 */ s32 message;
} ViRetraceContextView; /* size = 0x18; prefix of the VI context */

typedef struct ViManagerThreadView {
    /* 0x00 */ s32 active;
    /* 0x04 */ s32 thread;
    /* 0x08 */ s32 commandQueue;
    /* 0x0C */ OSMesgQueue *eventQueue;
} ViManagerThreadView; /* size = 0x10; prefix of OSDevMgr */

enum ViManagerConstants {
    VI_MANAGER_SEND_NONBLOCKING = 0,
    VI_MANAGER_QUEUE_CAPACITY = 5,
    VI_MANAGER_RETRACE_MESSAGE = 13,
    VI_MANAGER_COUNTER_MESSAGE = 14,
    VI_MANAGER_RETRACE_EVENT = 7,
    VI_MANAGER_COUNTER_EVENT = 3,
    VI_MANAGER_NO_SAVED_PRIORITY = -1,
    VI_MANAGER_THREAD_ID = 0,
    VI_MANAGER_STACK_TOP_OFFSET = 0x1200
};

/* Audio manager thread (func_801C3040):
 * func_8017F9A4 registers a SchedulerClient; func_801C7430 is osRecvMesg.
 * func_801C3198 builds/submits an audio task; func_801C3364 checks AI fullness.
 * func_801CB1BC closes the synthesizer.
 * D_802AD350: scheduler; D_802AB258: scheduler-event queue;
 * D_802AB290: task-completion queue; D_802AB2C8: synthesizer state.
 * D_802AB090 holds two command-list pointers followed by four frame pointers.
 * D_801F4170: audio frame counter; D_801F4180: last completed frame address.
 * Completion messages have an s16 type at offset 0 and a frame address at 4.
 */
enum AudioManagerLoopConstants {
    AUDIO_MANAGER_QUIT_MESSAGE = 10,
    AUDIO_MANAGER_RECEIVE_NONBLOCKING = 0,
    AUDIO_MANAGER_FRAME_INDEX_MASK = 3,
    AUDIO_MANAGER_FRAME_TABLE_OFFSET = 8,
    AUDIO_COMPLETION_FRAME_WORD = 1
};

enum AudioManagerConstants {
    AUDIO_RATE_ALLOWANCE_THRESHOLD = 22050,
    AUDIO_LOW_RATE_ALLOWANCE = 80,
    AUDIO_HIGH_RATE_ALLOWANCE = 240,
    AUDIO_SAMPLE_ALIGNMENT = 16,
    AUDIO_SAMPLE_ALIGNMENT_MASK = 15,
    AUDIO_DMA_IO_MESSAGE_BYTES = 24,
    AUDIO_MESSAGE_BYTES = 4,
    AUDIO_COMMAND_BYTES = 8,
    AUDIO_COMMAND_LIST_COUNT = 2,
    AUDIO_TASK_BUFFER_COUNT = 4,
    AUDIO_TASK_BYTES = 0x68,
    AUDIO_TASK_MESSAGE_OFFSET = 0x60,
    AUDIO_TASK_SELF_OFFSET = 0x64,
    AUDIO_TASK_COMPLETE_MESSAGE = 2,
    AUDIO_STEREO_SAMPLE_BYTES = 4,
    AUDIO_MANAGER_QUEUE_CAPACITY = 8,
    AUDIO_MANAGER_THREAD_ID = 3
};

/*
 * func_8017F25C initializes the scheduler and starts its event, audio-task,
 * and graphics-task threads (func_8017F6D0 / func_8017FB70 / func_8017FD8C).
 * func_801C6520 = osCreateMesgQueue; func_801CEAA0 = osCreateViManager;
 * func_801CEE60 = osViSetMode; func_801CF3B0 blanks the screen;
 * func_801D211C = memcpy; func_801CF020 = osViSetYScale;
 * func_801CEE00 = osViSetEvent; func_801C7690 = osSetEventMesg;
 * func_801C6550 / func_801C7860 = osCreateThread / osStartThread.
 * D_80000300 is osTvType (0 = PAL). D_801F4790 is the VI mode table,
 * stride 0x50; D_801F47B8 points to each mode's first 0x14-byte field record.
 * D_80108984 is the PAL vertical scale (0.88).
 * D_80292C18 saves that field record; D_80292C10 saves the selected mode.
 * Stack tops: D_80296C30 (events), D_80294C30 (audio), D_80292C10 (graphics).
 * Address-valued members retain their original s32 representation.
 */
typedef struct SchedulerContext {
    /* 0x000 */ s16 retraceMessageType;
    /* 0x002 */ s16 preNmiMessageType;
    /* 0x004 */ u8 queueAndThreadStorage[0x664];
    /* 0x668 */ s32 clients;
    /* 0x66C */ s32 graphicsTask;
    /* 0x670 */ s32 audioTask;
    /* 0x674 */ s32 waitingGraphicsTask;
    /* 0x678 */ s32 firstFrame;
} SchedulerContext; /* size = 0x67C */

/* osSetIntMask (func_801C63D0) argument: mask every interrupt. */
#define OS_IM_NONE 0x00000001

/* RSP task descriptor copied to DMEM; address fields retain their u32 ABI.
 * func_801CE4F0 = osSpTaskLoad; D_802AD630 is its physical-address task copy.
 * func_801D1D00 = bcopy; func_801C6470 = osWritebackDCache.
 * func_801C7D90 = osVirtualToPhysical; func_801CE750 = __osSpSetStatus.
 * func_801CE760 = __osSpSetPc; func_801CE790 = __osSpRawStartDma.
 * func_801CE730 = __osSpDeviceBusy.
 */
typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ u32 ucode_boot;
    /* 0x0C */ u32 ucode_boot_size;
    /* 0x10 */ u32 ucode;
    /* 0x14 */ u32 ucode_size;
    /* 0x18 */ u32 ucode_data;
    /* 0x1C */ u32 ucode_data_size;
    /* 0x20 */ u32 dram_stack;
    /* 0x24 */ u32 dram_stack_size;
    /* 0x28 */ u32 output_buff;
    /* 0x2C */ u32 output_buff_size; /* Address of the output-size word. */
    /* 0x30 */ u32 data_ptr;
    /* 0x34 */ u32 data_size;
    /* 0x38 */ u32 yield_data_ptr;
    /* 0x3C */ u32 yield_data_size;
} RspTask; /* size = 0x40 */

enum RspTaskConstants {
    RSP_TASK_YIELDED = 1,
    RSP_TASK_LOADABLE = 4,
    RSP_TASK_SIZE = 0x40,
    RSP_YIELD_UCODE_OFFSET = 0xBFC,
    RSP_TASK_DMEM_ADDRESS = 0x04000FC0,
    RSP_IMEM_ADDRESS = 0x04001000,
    RSP_DMA_READ = 1,
    RSP_CLR_SIG0 = 0x0200,
    RSP_CLR_SIG1 = 0x0800,
    RSP_CLR_SIG2 = 0x2000,
    RSP_SET_INTR_BREAK = 0x0100,
    RSP_KSEG1_BASE = 0xA0000000
};

/* Scheduler task messages wrap an OSTask at +0x10 and notify the submitter
 * through completionQueue/completionMessage after the task finishes. */
typedef struct SchedulerTaskMessage {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ s32 flags;
    /* 0x0C */ void *framebuffer;
    /* 0x10 */ u8 taskStorage[0x40];
    /* 0x50 */ void *completionQueue;
    /* 0x54 */ void *completionMessage;
} SchedulerTaskMessage; /* size = 0x58 */

/* func_8017FB70: scheduler_audio_thread.
 * func_801C64F0: osWritebackDCacheAll.
 * func_801CE890 / func_801CE8B0: osSpTaskYield / osSpTaskYielded.
 * func_801CE4F0 / func_801CE6FC: osSpTaskLoad / osSpTaskStartGo.
 * func_801804A0 / func_80180534: begin / end a profiling interval.
 * D_8010898C is the audio RSP profiling label.
 * Symbol renaming is currently unavailable for N64 projects. */
enum SchedulerTaskConstants {
    SCHED_TASK_STORAGE_OFFSET = 0x10,
    SCHED_GRAPHICS_IDLE = 0,
    SCHED_GRAPHICS_YIELDED = 1,
    SCHED_GRAPHICS_FINISHED = 2,
    SCHED_PROFILE_AUDIO_RSP = 7,
    SCHED_PROFILE_GRAPHICS_RSP = 8,
    SCHED_PROFILE_GRAPHICS_RDP = 9,
    SCHED_TASK_SWAP_FRAMEBUFFER = 0x40
};

/* func_8017FD8C: scheduler_graphics_thread. Waits for an available framebuffer
 * and audio RSP ownership, runs graphics, then waits for SP and DP completion.
 * The first completed frame disables VI black; flag 0x40 requests a VI swap.
 * func_8017FF5C: scheduler_wait_framebuffer_available (current/next VI buffers).
 * func_801CF070: osViSwapBuffer; func_801CF3B0 blanks the screen.
 * D_80108994 / D_80108998 are graphics RSP / RDP profiling labels.
 * Uses SchedulerContext and SchedulerTaskMessage without changing their ABI. */

enum SchedulerStorageOffsets {
    SCHED_AUDIO_QUEUE = 0x004,
    SCHED_AUDIO_MESSAGES = 0x01C,
    SCHED_GRAPHICS_QUEUE = 0x03C,
    SCHED_GRAPHICS_MESSAGES = 0x054,
    SCHED_EVENT_QUEUE = 0x074,
    SCHED_EVENT_MESSAGES = 0x08C,
    SCHED_SP_QUEUE = 0x0AC,
    SCHED_SP_MESSAGES = 0x0C4,
    SCHED_DP_QUEUE = 0x0E4,
    SCHED_DP_MESSAGES = 0x0FC,
    SCHED_RESUME_QUEUE = 0x11C,
    SCHED_RESUME_MESSAGES = 0x134,
    SCHED_EVENT_THREAD = 0x158,
    SCHED_AUDIO_THREAD = 0x308,
    SCHED_GRAPHICS_THREAD = 0x4B8
};

/* func_8017F6D0 (scheduler_event_thread) broadcasts paced retrace messages
 * and handles the pre-NMI shutdown countdown.
 * func_8017FAF4 broadcasts to registered client queues without blocking.
 * func_801C7430 / func_801C7560 = osRecvMesg / osSendMesg;
 * func_801C7980 = osStopThread; func_801C0B70 = MusHandleStop.
 * func_8014D4D0 starts the black screen transition.
 *
 * D_801EFC90: retraces left before stopping threads for reset.
 * D_801EFC91 / D_801EFC92: active / requested paced-message interval.
 * D_801EFC98[0]: paced-message counter; [1]: three-retrace counter.
 * D_801EC7C8 inhibits the paced broadcast; its counter is held one below
 * the threshold so it can resume on the next retrace.
 * D_801EFC94 is the paced client message; the scheduler's first two
 * halfwords are its regular retrace and pre-NMI client messages.
 * D_80290424 is the audio handle stopped during reset.
 * D_801FFC98, D_8025CF00, D_80202060 and D_80200168 are threads stopped
 * when the countdown expires. PAL restores its saved VI field record
 * and the vertical scale from D_80108988.
 * D_801E753C is the screen-transition extent, forced to 300 near reset.
 */
/* func_80180024 (scheduler_timer_thread) uses a 19667-us periodic timer.
 * func_801C77C0 = osSetTimer; D_801F43D0 = osClockRate (timer ticks/second).
 * D_801EFC9C holds the timer's paced and regular broadcast counters, separate
 * from the retrace counters in D_801EFC98. The pacing controls and client
 * messages are shared with scheduler_event_thread, as described above.
 * Its local client record is next + queue (8 bytes); the local OSTimer is
 * next + prev + interval + remaining ticks + queue + message (0x20 bytes).
 */
enum SchedulerTimerConstants {
    SCHED_TIMER_MESSAGE = 10,
    SCHED_TIMER_PERIOD_USEC = 19667,
    SCHED_MICROSECONDS_PER_SECOND = 1000000,
    SCHED_CLIENT_BYTES = 8,
    SCHED_TIMER_BYTES = 0x20
};

enum SchedulerEventLoopConstants {
    SCHED_MESSAGE_BLOCK = 1,
    SCHED_PACED_COUNTER = 0,
    SCHED_REGULAR_COUNTER = 1,
    SCHED_REGULAR_RETRACE_INTERVAL = 3,
    SCHED_RESET_RETRACES = 20,
    SCHED_RESET_AUDIO_FADE = 20,
    SCHED_RESET_FORCE_TRANSITION_BELOW = 8,
    SCHED_RESET_TRANSITION_EXTENT = 300,
    SCHED_PRE_NMI_MESSAGE_OFFSET = 2
};

enum SchedulerInitConstants {
    SCHED_QUEUE_CAPACITY = 8,
    SCHED_CLIENT_RETRACE = 1,
    SCHED_CLIENT_PRE_NMI = 3,
    SCHED_EVENT_RETRACE = 0x29A,
    SCHED_EVENT_SP_DONE = 0x29B,
    SCHED_EVENT_DP_DONE = 0x29C,
    SCHED_EVENT_PRE_NMI = 0x29D,
    SCHED_OS_EVENT_SP = 4,
    SCHED_OS_EVENT_DP = 9,
    SCHED_OS_EVENT_PRE_NMI = 14,
    SCHED_TV_PAL = 0,
    SCHED_VI_FIELD_BYTES = 0x14,
    SCHED_VI_VSTART_OFFSET = 8,
    SCHED_PAL_VSTART = 60,
    SCHED_PAL_VEND = 600,
    SCHED_VI_MANAGER_PRIORITY = 254,
    SCHED_EVENT_THREAD_ID = 19,
    SCHED_AUDIO_THREAD_ID = 18,
    SCHED_GRAPHICS_THREAD_ID = 17,
    SCHED_EVENT_PRIORITY = 120,
    SCHED_AUDIO_PRIORITY = 110,
    SCHED_GRAPHICS_PRIORITY = 100
};

/* func_8017D7B8 updates a platform's world-space collision triangles.
 * func_801484F0 builds a matrix from an XYZW quaternion; func_80147094
 * computes a vector cross product; func_80149568 normalizes a vector.
 * func_8015BE58 refreshes triangle plane/projection/edge data using the
 * existing edge lengths. D_802004E0 is the state frame counter;
 * D_8010888C is the quaternion-W comparison constant for the unrotated path.
 * Symbol renaming is not supported by the N64 tools.
 * The collision mesh begins with a signed triangle count at +0, vertex
 * array address at +4 (XYZ floats, stride 12), and index array address at +8
 * (three signed halfwords per triangle, stride 6). +2 remains unknown.
 */
/* func_8017D21C (platform_rebuild_collision) rebuilds transformed triangles,
 * copies scale into stretch state, and expands the unrotated bounds.
 * func_8017D558 (platform_transform_collision) applies scale, local Y offset,
 * quaternion rotation and world translation, then prepares triangle planes.
 * Its local Y offset is applied after scaling and before rotation. The output
 * is CollisionTriangle (0x78 bytes); raw float indices below retain aliasing.
 * It stamps PLATFORM_COLLISION_UPDATE_FRAME from D_802004E0 (state frame)
 * and calls func_8015BA6C (collision_triangle_prepare) to rebuild the plane,
 * projection axes, normalized edge directions, and edge lengths.
 * func_8015739C (collision_disable_shared_edges) removes degenerate edges
 * and edges shared by coplanar triangles. N64 symbol renames are unsupported.
 */
/* func_801570AC (collision_mesh_transform) reads relocated ModelMeshData:
 * positions are XYZ float triples; triangles are signed s16 index triples.
 * It scales and rotates vertices into CollisionTriangle records and returns
 * their maximum distance from the local origin, before translation.
 * With prepareCollision set, it also translates to world space, computes
 * normals, prepares planes/edges via func_8015BA6C, and disables shared
 * coplanar edges via func_8015739C. Otherwise only vertices are written.
 * func_801484F0 converts quaternion to matrix; func_80147094 is cross product;
 * func_80149568 normalizes the resulting triangle normal.
 */
enum PlatformCollisionField {
    PLATFORM_BOUNDS_HALF_X = 0x08,
    PLATFORM_BOUNDS_HALF_Y = 0x0C,
    PLATFORM_BOUNDS_HALF_Z = 0x10,
    PLATFORM_BOUNDS_RADIUS = 0xB0,
    PLATFORM_COLLISION_FLAGS = 0x14,
    PLATFORM_COLLISION_UNK2C = 0x2C,
    PLATFORM_COLLISION_UPDATE_FRAME = 0x6E,
    PLATFORM_WORLD_X = 0xB4,
    PLATFORM_WORLD_Y = 0xB8,
    PLATFORM_WORLD_Z = 0xBC,
    PLATFORM_QUATERNION = 0x11C,
    PLATFORM_QUATERNION_W = 0x128,
    PLATFORM_SCALE_Y = 0x140,
    PLATFORM_SCALE_Z = 0x144,
    PLATFORM_COLLISION_MESH = 0x14,
    COLLISION_MESH_VERTICES = 4,
    COLLISION_MESH_INDICES = 8
};

enum PlatformCollisionConstants {
    PLATFORM_SKIP_COLLISION_REBUILD_MASK = 0x84,
    PLATFORM_SKIP_COLLISION_UPDATE_MASK = 0x20084,
    COLLISION_VERTEX_BYTES = 12,
    COLLISION_TRIANGLE_INDEX_BYTES = 6
};

/* Collision triangle prepared by func_8015BA6C: normal and vertices are inputs.
 * Projection drops the largest normal component for barycentric tests.
 * func_8015BE58 (collision_triangle_refresh) rebuilds the plane, projected
 * edges and edge directions after a transform, retaining cached edgeLengths. */
typedef struct CollisionTriangle {
    /* 0x00 */ f32 normal[3];
    /* 0x0C */ f32 planeDistance;
    /* 0x10 */ f32 vertices[3][3];
    /* 0x34 */ f32 edgeDirections[3][3];
    /* 0x58 */ f32 edgeLengths[3];
    /* 0x64 */ f32 edge01U;
    /* 0x68 */ f32 edge02U;
    /* 0x6C */ f32 edge01V;
    /* 0x70 */ f32 edge02V;
    /* 0x74 */ u8 surfaceType;
    /* 0x75 */ u8 projectionAxisU;
    /* 0x76 */ u8 projectionAxisV;
    /* 0x77 */ u8 unk77;
} CollisionTriangle; /* size = 0x78 */

/* func_8015739C disables degenerate and coplanar shared collision edges.
 * func_80148E48 returns Euclidean distance between two 3D points.
 * D_80106F30 holds edge indices {0, 2, 1}, indexed by vertexA + vertexB - 1.
 * Its +4 pool entry is the f64 minimum vertex separation (0.001).
 * D_80106F40 is the f64 coplanarity/vertex-match tolerance (0.01).
 * D_80106F3C and D_80106F48 both hold -1.0f: disabled edge length.
 */
typedef struct CollisionEdgeLookup {
    u8 edgeIndex[3];
} CollisionEdgeLookup; /* size = 3 */

/* func_8015B524 (collision_ground_distance) returns the nearest downward
 * triangle hit, or -1 when there is no ground. The two outputs are the face
 * and its platform (zero for static geometry). An existing support contact
 * can bypass the search when its upward normal is at least 0.95.
 * func_8015B878 tests a downward ray against one CollisionTriangle;
 * func_80149428 subtracts XZ; func_8017D7B8 refreshes platform triangles.
 * D_8026A058 is the static collision-body sentinel; D_802904D4 is the
 * platform list sentinel. D_802004E0 stamps collision updates.
 * The source's Body157708 view has radius +30, position +34, mesh +C8
 * and triangle bytes +E0. Mesh157708.data (+C) points to MeshData157708,
 * whose +14 points to the signed triangle count. Actor157708 embeds that
 * body at +80, with collision flags +14 and update frame unk6E (+6E).
 * Retain these shared views and their field types for matching.
 * Pool values: D_80107160/16C/170/174 = 1000000 (no triangle hit),
 * D_80107164 = 0.95 (f64 minimum support normal Y), D_80107178 = -1.
 */
/* func_801A8528 updates cached ground distances used by the shadow renderer.
 * D_801E7531 is the level ID; levels 46 and up skip this pass.
 * D_8029F210 is the effect-list sentinel; D_8026A148 the object sentinel.
 * D_802902D8 / D_8029F978 are the player / ball objects.
 * D_802993A0 is the group sentinel, D_802993A4 its previous link.
 * D_802900F0 is the separately tracked particle.
 * D_8010B19C / D_8010B1A0 / D_8010B1A4 are squared-distance cutoffs
 * for effects, objects and group members respectively.
 * Object +CC and effect +D4 point to shadow state: distance at +0,
 * ground triangle at +4. Object shadow state +50 selects a contact
 * position from the +D8 contact records (stride 36, position at +34).
 * Group members instead embed distance at +50 and triangle at +54.
 * Keep raw accesses to preserve aliasing and the existing shared field types.
 */
enum GroundShadowUpdateConstants {
    SHADOW_UPDATE_LEVEL_LIMIT = 46,
    SHADOW_ENABLED_FLAG = 0x100,
    SHADOW_EXCLUDED_OBJECT_TYPE = 0x3D,
    SHADOW_EFFECT_DISTANCE_SQUARED = 0x20,
    SHADOW_EFFECT_FLAGS = 0x30,
    SHADOW_EFFECT_POSITION = 0x3C,
    SHADOW_EFFECT_STATE = 0xD4,
    SHADOW_OBJECT_DISTANCE_SQUARED = 0x18,
    SHADOW_OBJECT_TYPE = 0x20,
    SHADOW_OBJECT_FLAGS = 0x28,
    SHADOW_OBJECT_POSITION = 0x34,
    SHADOW_OBJECT_STATE = 0xCC,
    SHADOW_OBJECT_CONTACT = 0xD8,
    SHADOW_STATE_TRIANGLE = 4,
    SHADOW_STATE_CONTACT_INDEX = 0x50,
    SHADOW_CONTACT_STRIDE = 36,
    SHADOW_MEMBER_UPDATE_MODE = 0xF,
    SHADOW_MEMBER_UPDATE_ENABLED = 1,
    SHADOW_MEMBER_DISTANCE = 0x50,
    SHADOW_MEMBER_TRIANGLE = 0x54,
    SHADOW_MEMBER_DISTANCE_SQUARED = 0xA8
};

enum GroundQueryConstants {
    GROUND_QUERY_SKIP_PLATFORM_MASK = 0x84,
    GROUND_CONTACT_HEIGHT_OFFSET = 0x14,
    GROUND_CONTACT_PLATFORM_OFFSET = 0x178,
    GROUND_NORMAL_Y_OFFSET = 4,
    GROUND_POSITION_Y_OFFSET = 4
};

/* func_80173D28 (player_check_triangle_edge_crossing) tests the player's
 * position against a probe body's position across enabled triangle edges.
 * D_8029030C starts player XYZ; offsets +48/+54 from it are current/target yaw.
 * D_80290200 receives a distance-weighted point on the crossed edge.
 * D_80108318 is -1.0f, the disabled-edge length sentinel.
 * func_80147460 is table-based atan2(y, x); func_801496C8 wraps one turn;
 * func_80149428 subtracts XZ, and func_80149398 adds two weighted XYZ vectors.
 * Flat float accesses retain the matching code's aliasing behavior.
 */
enum PlayerEdgeCrossingField {
    EDGE_PROBE_POSITION_X = 0x34,
    EDGE_PROBE_POSITION_Z = 0x3C,
    EDGE_PLAYER_YAW_INDEX = 0x48 / 4,
    EDGE_PLAYER_TARGET_YAW_INDEX = 0x54 / 4
};

/* func_80158DC4: collision_triangle_edge_distance.
 * Return the distance to the first enabled edge whose segment projection
 * lies within the supplied radius; zero also denotes no hit.
 * The output point is updated for each in-segment projection tested, so it
 * can change even when the function returns zero. This is not a nearest-edge
 * search, and projections beyond an endpoint are skipped rather than clamped.
 * D_80107028 is the pooled -1.0f disabled-edge sentinel (asm/1000.s).
 * func_80148CC8 computes output = origin + direction * distance; its call
 * cast preserves the float argument's ABI without changing shared prototypes.
 * Flat accesses use CollisionTriangleField indices to retain aliasing.
 */
enum CollisionEdgeConstants {
    COLLISION_TRIANGLE_BYTES = 0x78,
    COLLISION_TRIANGLE_VERTICES_OFFSET = 0x10,
    COLLISION_TRIANGLE_VERTEX_COUNT = 3
};

/* func_8015B878: collision_triangle_downward_distance.
 * Intersect a downward ray with an upward-facing CollisionTriangle, then
 * test its projected barycentric coordinates. Return distance only for
 * 0 < distance < maxDistance; D_801071B0 = 1000000 marks a miss.
 * The caller initializes hitPosition X/Z from the ray origin. This function
 * overwrites Y at the plane intersection, even if the triangle test fails.
 * D_8010717C = -1 initializes the rejected barycentric U coordinate.
 * D_80107180 / D_80107190 / D_801071A0 are f64 -0.001 lower bounds;
 * D_80107188 / D_80107198 / D_801071A8 are f64 1.001 upper bounds.
 * Values decoded from asm/1000.s; keep these as pooled f64 comparisons.
 * N64 symbol renaming is unavailable; retain the legacy symbols.
 */
/* Float indices and byte offsets preserve the original flat-array accesses. */
enum CollisionTriangleField {
    TRI_NORMAL_X = 0,
    TRI_NORMAL_Y = 1,
    TRI_NORMAL_Z = 2,
    TRI_PLANE_DISTANCE = 3,
    TRI_VERTEX0_X = 4,
    TRI_VERTEX0_Y = 5,
    TRI_VERTEX0_Z = 6,
    TRI_VERTEX1_X = 7,
    TRI_VERTEX2_X = 10,
    TRI_EDGE_X = 13,
    TRI_EDGE_Y = 14,
    TRI_EDGE_Z = 15,
    TRI_EDGE_LENGTHS = 22,
    TRI_EDGE01_U = 25,
    TRI_EDGE02_U = 26,
    TRI_EDGE01_V = 27,
    TRI_EDGE02_V = 28,
    TRI_SURFACE_TYPE = 0x74,
    TRI_PROJECTION_AXIS_U = 0x75,
    TRI_PROJECTION_AXIS_V = 0x76
};

/* func_801B9C44 updates camera shake and horizontal impulses on contacting actors.
 * func_801B9894 starts a shake; func_801B9974 scales one by source distance.
 * N64 symbol renaming is unavailable; global roles are recorded here:
 * D_802AA708: remaining frames; D_802AA70C/70E: amplitude endpoints;
 * D_802AA710: frame phase offset; D_802AA714: sine divisor; D_802AA718: flags.
 * D_801F2110: camera displacement divisor; D_801F2114: actor impulse divisor;
 * D_801F2118: roll sine divisor; D_801F211C: roll amplitude scale.
 * D_801EC7B0: unshaken up vector; D_801EC7BC: shaken up vector.
 * D_8028F918: camera Y; D_8028FA04: focus Y;
 * D_8028F938: camera motion XYZ; D_8028FA00: camera focus XYZ.
 * D_802004E0: frame counter; D_80290330 / D_8029F9D0: player / ball velocity.
 * D_802903B0 / D_8029FA50: player / ball collision state;
 * D_802903A8 / D_8029FA48: physics parameters; offset zero divides the impulse.
 * func_80149724 returns sin((frame + offset) / divisor);
 * func_8014915C rotates a vector around a coordinate axis;
 * func_80147000 returns a bounded random integer.
 */
typedef struct ShakeState {
    /* 0x00 */ s32 framesRemaining;
    /* 0x04 */ s16 amplitudeAtSinePeak;
    /* 0x06 */ s16 amplitudeAtSineTrough;
    /* 0x08 */ s32 phaseOffset;
    /* 0x0C */ f32 sineDivisor;
    /* 0x10 */ s32 flags;
} ShakeState; /* size = 0x14; begins at D_802AA708 */

enum ShakeFlags {
    SHAKE_ACTOR_IMPULSES = 1,
    SHAKE_CAMERA = 2,
    SHAKE_HALF_DURATION = 4,
    SHAKE_ALTERNATING_VERTICAL = 8
};

enum ShakeConstants {
    SHAKE_ROLL_AXIS = 2,
    SHAKE_RANDOM_SIGN_RANGE = 10,
    SHAKE_RANDOM_SIGN_MIDPOINT = 5,
    SHAKE_VECTOR_COMPONENTS = 3
};

/*
 * func_8016225C starts a collision-triggered teleport; func_8015F098 updates
 * its shrink, relocation and grow phases. A contact actor stores the
 * TeleportDefinition pointer at +0x4C. Object +0xD4 points to state whose
 * signed byte +3 is the phase timer and whose pointer +0xC is the teleport.
 *
 * D_802902D8 / D_8029F978: player / ball object.
 * D_802903AC / D_8029FA4C: player / ball state pointers.
 * D_80290300: player object flags; D_8029F9A4: ball supporting object.
 * D_802901DC: player damage-invulnerability timer.
 * func_80167604 selects player state; func_80178134 plays positional sound.
 * func_8016225C_check is the inlined player ball-holding predicate.
 * Player state 3 teleports both objects together. Flag 0x40 swaps positions.
 * The +0x11 byte access deliberately reads the low byte of shrinkFrames
 * on the big-endian N64. Duration reads elsewhere may interpret s16.
 */
typedef struct TeleportDefinition {
    /* 0x00 */ f32 destination[3];
    /* 0x0C */ u16 flags;
    /* 0x0E */ s16 type;
    /* 0x10 */ u16 shrinkFrames;
    /* 0x12 */ u16 growFrames;
    /* 0x14 */ u8 *destinationActor;
} TeleportDefinition; /* size = 0x18 */

enum TeleportFlags {
    TELEPORT_ALLOW_BALL = 0x01,
    TELEPORT_ALLOW_PLAYER = 0x02,
    TELEPORT_ALLOW_OTHER_OBJECTS = 0x04,
    TELEPORT_ALLOW_BALL_IN_STATE_3 = 0x08,
    TELEPORT_CLEAR_VELOCITY = 0x10,
    TELEPORT_ATTACH_TO_DESTINATION = 0x20,
    TELEPORT_SWAP_PLAYER_AND_BALL = 0x40
};

enum TeleportConstants {
    TELEPORT_TYPE_COLLISION = 1,
    TELEPORT_OBJECT_PLAYER = 1,
    TELEPORT_OBJECT_BALL = 2,
    TELEPORT_STATE_TIMER = 3,
    TELEPORT_STATE_ACTION = 4,
    TELEPORT_STATE_DEFINITION = 0x0C,
    TELEPORT_ACTOR_DEFINITION = 0x4C,
    TELEPORT_OBJECT_TYPE = 0x20,
    TELEPORT_OBJECT_POSITION = 0x34,
    TELEPORT_OBJECT_STATE = 0xD4,
    TELEPORT_SHRINK_FRAMES_LOW_BYTE = 0x11,
    TELEPORT_SOUND_START = 0x13D
};

/*
 * func_801AD764 handles an effect contacting an object. Effects embed their
 * ObjectNode at +8; ListNode801A8E54 is the existing list/type prefix.
 * D_801F03E8 holds contact/expiry callbacks at a 0xC0-byte type stride.
 * D_801FA750 enables type-27 projectile deflection. D_80290374 is the player
 * orientation quaternion used for the deflection flash's normal.
 * D_80297910 is the flash texture; D_8010B51C is its allocation label.
 * D_8010B528 supplies flash lifetime, +4 the alpha-step divisor;
 * D_8010B530+4 supplies the unsigned-conversion threshold, and
 * D_8010B53C supplies the local normal Z component.
 * D_801F19B6 is the default actor status duration.
 *
 * func_801492D4 negates a vector; func_8013FCDC allocates memory;
 * func_801A6844 initializes AttachedEffectView; func_801A69F8 links it;
 * func_801499A0 rotates a vector by a quaternion.
 * func_801B9894 starts screen shake; func_801743A8 damages the player.
 * func_801B0DDC bursts the ball; func_801AEC14 applies ball damage.
 * func_801ADDC4 extends an actor status timer; func_801ADFC8 extends a
 * player status timer; func_8018C700 applies a player/ball power-up.
 * func_801A8EF8 unlinks and frees the effect.
 */
/* Target address stored at effect +0x164; type 29 stores a position pointer,
 * while other types store an object pointer. */
typedef struct EffectTargetWord {
    /* 0x00 */ s32 address;
} EffectTargetWord; /* size = 0x04 */

/* func_801ADAF8: select an effect target. func_80148EBC measures squared 3D
 * distance from D_8029030C (player position). D_8029F978 / D_802902D8 are
 * the ball / player objects. D_801F0198 counts actor slots.
 * D_8010B540 initializes the best distance; D_801EEC14 limits actor effect
 * height for type 29. D_801F19B0 * D_801F1998 supplies its search radius.
 * D_802993A4 is the tail link of the additional target-group list. */
enum EffectTargetFlags {
    EFFECT_TARGET_BALL = 1,
    EFFECT_TARGET_PLAYER = 2,
    EFFECT_TARGET_NEAREST = 4
};

enum EffectTargetSelectionConstants {
    EFFECT_TARGET_FLAGS_OFFSET = 0x160,
    EFFECT_TYPE_INITIAL_PLAYER_TARGET = 0x1A,
    EFFECT_TYPE_POSITION_TARGET = 0x1D,
    EFFECT_TARGET_ACTOR_TYPE_LIMIT = 0x2C,
    EFFECT_TARGET_ACTOR_INACTIVE = 0,
    EFFECT_TARGET_ACTOR_EXCLUDED_STATE = 2,
    EFFECT_TARGET_OBJECT_POSITION = 0x34,
    EFFECT_TARGET_PREVIOUS_LINK = 4,
    EFFECT_TARGET_GROUP_MEMBERS = 8,
    EFFECT_TARGET_GROUP_MEMBER_TAIL = 0xC,
    EFFECT_TARGET_MEMBER_ACTIVE = 0xD,
    EFFECT_TARGET_MEMBER_POSITION = 0x24
};

typedef void (*EffectContactCallback)(u8 *object);

enum EffectContactFlags {
    EFFECT_CONTACT_DAMAGE_PLAYER = 0x20000,
    EFFECT_CONTACT_DAMAGE_BALL = 0x40000,
    EFFECT_CONTACT_BURST_BALL = 0x100000
};

enum EffectContactOffsets {
    EFFECT_EXPIRY_TIMER_OFFSET = 0x2C,
    EFFECT_OBJECT_FLAGS_OFFSET = 0x30,
    EFFECT_STATUS_DURATION_OFFSET = 0x15E,
    EFFECT_STATUS_ID_OFFSET = 0x162,
    EFFECT_TARGET_OFFSET = 0x164,
    CONTACT_OBJECT_STATE_OFFSET = 0xD4,
    CONTACT_STATE_ACTOR_INDEX = 2, EFFECT_CONTACT_OBJECT_OFFSET = 0x34 /* object the effect last touched */
};

enum EffectContactConstants {
    EFFECT_TYPE_DEFLECTABLE_PROJECTILE = 0x1B,
    EFFECT_TYPE_PERSIST_AFTER_CONTACT = 0x0B,
    EFFECT_STATUS_STUN = 0,
    EFFECT_STATUS_SHRINK = 1,
    EFFECT_STATUS_TRANSFORM = 2,
    EFFECT_STATUS_NONE = 15,
    EFFECT_SHRINK_CONTACT_FRAMES = 50,
    EFFECT_DEFLECTION_SOUND = 0x58,
    EFFECT_DEFLECTION_FLASH_BYTES = 0x90,
    EFFECT_DEFLECTION_FLASH_ALPHA = 150,
    EFFECT_DEFLECTION_MODEL_UNK026 = 200
};

/*
 * func_8017753C: update player footstep sounds and effects from animation frames.
 * func_80133E24 tests whether ActorAnimation.frame is in [frame, frame + speed).
 * func_80178134 plays a positional sound (ID, position, volume, pitch).
 * func_80147000 returns a random integer below its argument.
 * func_801A87CC emits a footstep effect at a signed lateral offset.
 * D_802902D8: player object; D_8029030C: player position.
 * D_80290300: player object flags; D_802903AC: player action/water state.
 * D_802903B0: player collision state; its first pointer is the contact face.
 * D_801E7462: nonzero enables footsteps without contacts and scales volume;
 * its broader gameplay meaning is not established.
 */
enum PlayerFootstepSound {
    PLAYER_FOOTSTEP_SOUND_SPLASH = 3,
    PLAYER_FOOTSTEP_SOUND_FIRST = 0x94,
    PLAYER_FOOTSTEP_SOUND_SECOND = 0x95,
    PLAYER_FOOTSTEP_SOUND_ALTERNATE = 0x139
};

enum PlayerFootstepConstants {
    PLAYER_FOOTSTEP_ALTERNATE_SOUND_FLAG = 0x8000,
    PLAYER_FOOTSTEP_SPLASH_SURFACE = 5,
    PLAYER_POSITION_WORDS_FROM_FLAGS = 3,
    PLAYER_FOOTSTEP_EFFECT_NEGATIVE_X = -4,
    PLAYER_FOOTSTEP_EFFECT_POSITIVE_X = 4
};

/*
 * func_80198C20 updates action delays, evaluates action overrides, then
 * dispatches type-specific behavior for actors whose active state is 1.
 * func_80198A58 tests conditional actions and selects a matching override.
 * func_8019787C executes the current action and advances completed actions.
 * D_8029F100 counts immediate action transitions during that update;
 * func_8019787C permits at most four recursive transitions.
 *
 * The action count at actor +0x24A is ScriptState +0x166.
 * ACTOR_ACTION_DELAY > 0 counts down; a negative value waits for
 * ActorAnimation.finished, then clears to zero for the following update.
 * Case labels retain the original type-minus-7 dispatch calculation.
 */
/*
 * func_80198A58: actor_select_conditional_action.
 * func_80198310: actor_action_condition_met.
 * func_80193FC8: actor_face_action_target (player, ball, or nearest).
 * func_80194CC8: actor_trigger_special_action (type 25 effect / type 26 animation).
 * func_80198A58_set2 inlines action selection and the 0x48-byte action copy.
 * Offsets below are relative to the current action at actor +0xE4.
 * The override list begins at +0xC4; +0x48 marks an active override and
 * +0x171 saves the normal action index until that override completes.
 */
/*
 * func_801B2AF0: player_in_listed_state. Returns 1 when D_801EFCFC is clear
 * and the current player state (D_802903AC + 4) is 3, 5, 14 or 15.
 */
enum PlayerListedStates {
    PLAYER_LISTED_STATE_A = 3,
    PLAYER_LISTED_STATE_B = 5,
    PLAYER_LISTED_STATE_RANGE_FIRST = 14, /* 14 and 15 */
    PLAYER_LISTED_STATE_RANGE_COUNT = 2
};

enum ActorSpecialActionConstants {
    SPECIAL_ACTION_EFFECT_ACTOR_TYPE = 0x19,
    SPECIAL_ACTION_ANIMATE_ACTOR_TYPE = 0x1A,
    SPECIAL_ACTION_EFFECT_TYPE = 3
};

enum ActorConditionalActionOffsets {
    ACTION_FLAGS_OFFSET = 0x28,
    ACTION_OVERRIDE_ACTIVE_OFFSET = 0x48,
    ACTION_OVERRIDE_LIST_OFFSET = 0xC4,
    ACTION_OVERRIDE_COUNT_OFFSET = 0x168,
    ACTION_CURRENT_LIST_OFFSET = 0x16C,
    ACTION_CURRENT_INDEX_OFFSET = 0x170,
    ACTION_SAVED_INDEX_OFFSET = 0x171
};

enum ActorConditionalActionConstants {
    ACTION_RUN_WITHOUT_SWITCHING = 0x800,
    ACTION_SPECIAL_WAIT = 5,
    ACTION_SPECIAL_IMMEDIATE = 6,
    ACTION_FACE_TARGET = 8
};

/*
 * Script-state layout used while a level loads an actor's script
 * (D_802994CC = actor array D_802993E8 + 0xE4, one 0x300-byte slot each).
 * Level token 0x9A appends to the action list, 0x9B to the override list.
 */
enum ActorScriptLoadConstants {
    SCRIPT_ACTION_LIST_OFFSET = 0x4C,
    SCRIPT_ACTION_COUNT_OFFSET = 0x166,
    SCRIPT_MAX_ACTIONS = 0x1F,
    SCRIPT_MAX_OVERRIDES = 11, /* list at ACTION_OVERRIDE_LIST_OFFSET */
    /* Third instruction list, filled by level token 0x9C; its use is unknown. */
    SCRIPT_EXTRA_LIST_OFFSET = 0xEC,
    SCRIPT_EXTRA_COUNT_OFFSET = 0x16A,
    SCRIPT_MAX_EXTRA = 0x1F,
    ACTOR_SLOT_SIZE = 0x300
};

enum ActorBehaviorDispatchConstants {
    ACTOR_ACTION_COUNT = 0x24A,
    ACTOR_ACTIVE_STATE = 0x22,
    ACTOR_ACTIVE = 1,
    ACTOR_BEHAVIOR_FIRST_TYPE = 7
};

/* func_80183340: cameo_read_token; D_801EFCEC is the cameo being loaded.
 * D_80108DBC = "Cameo", D_80108DC4 = "CameoInst" (allocation labels).
 * func_8013FCDC allocates tagged memory; func_801D211C is memcpy;
 * func_8012ACE4 links a cameo into the list headed by D_801F9628.
 * func_8012B048 executes instructions. Payload interpretation depends on opcode.
 * startCondition: -1 starts immediately, nonnegative waits for that instruction,
 * values below -1 select a cameo frame. endCondition: nonnegative duration,
 * -1 waits for the operation, values below -1 wait for another instruction.
 */
typedef struct CameoInstruction {
    /* 0x00 */ s16 opcode;
    /* 0x02 */ s16 elapsedFrames;
    /* 0x04 */ s16 endCondition;
    /* 0x06 */ s16 startCondition;
    /* 0x08 */ s16 completed;
    /* 0x0A */ s16 target;
    /* 0x0C */ u8 payload[0xC];
    /* 0x18 */ f32 speed;
} CameoInstruction; /* size = 0x1C */

typedef struct Cameo {
    /* 0x00 */ struct Cameo *next;
    /* 0x04 */ struct Cameo *prev;
    /* 0x08 */ s32 frame;
    /* 0x0C */ s32 instructionCount;
    /* 0x10 */ CameoInstruction *instructions[20];
} Cameo; /* size = 0x60 */

/* func_8012AE8C: cameo_update. Completion flags are per-update pulses;
 * dependent instructions are activated after each completion and once more
 * after the scan. Level 40 defers all activation until that final scan.
 * func_8012B048: cameo_execute_instruction.
 * func_80173CE8 raises the gameplay delay timer to at least its argument.
 * D_801E7531 is the level ID. Raw word indices preserve Cameo access types.
 */
enum CameoUpdateConstants {
    CAMEO_NEXT_WORD = 0, /* Cameo.next; zero while the cameo is not in the list */
    CAMEO_PREV_WORD = 1, /* Cameo.prev */
    CAMEO_FRAME_WORD = 2,
    CAMEO_INSTRUCTION_COUNT_WORD = 3,
    CAMEO_INSTRUCTIONS_WORD = 4,
    CAMEO_START_IMMEDIATELY = -1,
    CAMEO_DEFER_DEPENDENCIES_LEVEL = 40,
    CAMEO_GAMEPLAY_DELAY = 2
};

enum CameoLevelToken {
    LEVEL_TOKEN_CAMEO = 0xAA,
    LEVEL_TOKEN_CAMEO_INSTRUCTION = 0xAB
};

enum CameoOpcode {
    CAMEO_PLAY_ANIMATION = 0,
    CAMEO_SET_CAMERA_TARGET = 1,
    CAMEO_MOVE_TARGET = 2,
    CAMEO_ROTATE_TARGET = 3,
    CAMEO_ATTACH_TO_ACTOR_POINT = 4,
    CAMEO_SET_ACTOR_FLAG_100 = 5,
    CAMEO_OP_6 = 6
};

/* Raw offsets preserve the parser's access types and byte-copy ordering. */
enum CameoLoadOffsets {
    CAMEO_INSTRUCTION_COUNT_OFFSET = 0x0C,
    CAMEO_INSTRUCTIONS_OFFSET = 0x10,
    CAMEO_END_CONDITION_OFFSET = 4,
    CAMEO_START_CONDITION_OFFSET = 6,
    CAMEO_TARGET_OFFSET = 0x0A,
    CAMEO_PAYLOAD_OFFSET = 0x0C,
    CAMEO_PAYLOAD_SECOND_HALFWORD_OFFSET = 0x0E,
    CAMEO_SPEED_OFFSET = 0x18
};

/* func_801A5EDC: spawnMirroredObjectParticles. The caller supplies a velocity
 * vector address. D_801F01FC/0200 are local X/Y offsets (20, -4);
 * D_8010B054/B05C are the two local Z offsets (4).
 * D_8010B058/B060 are 2^31 for float-to-unsigned conversion.
 * func_801499A0 rotates a vector by a quaternion; func_80147000 returns a
 * random integer below its bound; func_801B66D4 spawns a pooled particle.
 * Sprite animation begins at particle + 0x10C, making +0x114 startScale.
 */
enum MirroredParticleConstants {
    MIRRORED_PARTICLE_TYPE = 12,
    MIRRORED_PARTICLE_SCALE_RANGE = 110,
    MIRRORED_PARTICLE_SCALE_BIAS = 55,
    MIRRORED_EMITTER_POSITION_X = 0x34,
    MIRRORED_EMITTER_POSITION_Y = 0x38,
    MIRRORED_EMITTER_POSITION_Z = 0x3C,
    MIRRORED_EMITTER_QUATERNION = 0x9C,
    PARTICLE_SPRITE_SCALE_X_OFFSET = 0x100,
    PARTICLE_SPRITE_SCALE_Y_OFFSET = 0x102,
    PARTICLE_SPRITE_START_SCALE_OFFSET = 0x114
};

/* func_801B70F8: spawn_scaled_particle_ring(position, count, verticalSpeed, scale).
 * func_80147000 returns a bounded random integer; func_801490AC rotates about Y;
 * func_801496C8 wraps an angle by one turn; func_801B66D4 spawns a particle.
 * D_801ED3C4 is the zero vector. D_8010BD3C is a full turn (f64, radians),
 * D_8010BD44 is base radial speed 4, D_8010BD48 is 2^31 for unsigned conversion.
 * Odd particles receive sprite flag 4; its visual meaning is still unknown.
 * The legacy s32 signature has no defined return value; callers ignore it. */
/* func_801B7344: spawn_particle_ring(position, count, verticalSpeed).
 * Uses the same helpers and alternating flag as spawn_scaled_particle_ring.
 * D_8010BD48 + 4 holds one turn in radians (f64); D_8010BD54 is radial
 * speed 4 (f32). The position parameter retains its legacy s32 address type.
 */
enum ParticleRingPoolOffsets {
    PARTICLE_RING_FULL_TURN_FLOAT_INDEX = 1
};

enum ParticleRingConstants {
    PARTICLE_RING_TYPE = 0,
    PARTICLE_RING_START_ANGLE_BOUND = 6,
    PARTICLE_RING_ALTERNATE_FLAG = 4,
    PARTICLE_SPRITE_FLAGS_OFFSET = 0x109,
    PARTICLE_SPRITE_END_SCALE_OFFSET = 0x116
};

/* func_8013D24C: clearFramebuffer. D_80202240 is the Gfx write cursor;
 * D_8025D0B8 holds framebuffer addresses selected by D_801EC7F4 (0 or 1).
 * D_801EC7A6 enables the configured clear color; otherwise use opaque black.
 * D_801ED400/401/402 are the red/green/blue bytes (initially 0, 81, 179).
 * D_801EC7E8 is SceneTextureMode; mipmapping requires two RDP cycles.
 * RGBA5551 is duplicated into both halves of the 32-bit fill color.
 * The fill rectangle covers (0,0)..(319,239), inclusive in fill mode.
 */
/* func_8013D624: finishGraphicsTask. func_8013A018 selects microcode and
 * seeds the next task's display-list pointer. The scheduler task embeds an
 * OSTask at +0x10; this view describes only the prefix used during finalization.
 * D_80202240: display-list cursor; D_80202244: current buffer's task pointers;
 * D_801EC7D0: task index; D_8025D0C8: display-list byte counts by task;
 * D_8025D0B8: framebuffer addresses; D_801EC7F4: active buffer index;
 * D_8025D0C0: graphics arena base (display lists begin at +0x4100).
 * D_8025D578: diagnostic formatting buffer; func_801D2150: sprintf;
 * func_80139D70: disabled diagnostic sink; func_80139D94: diagnostic wrapper.
 * D_80105C20: "Overran the graphics list......."; D_80105C44: "GFX LIST".
 * The diagnostic call after the overflow return is unreachable in the original.
 * Symbol renaming is unavailable for N64 projects.
 */
typedef struct GraphicsTaskFinalizeView {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ s32 flags;
    /* 0x0C */ s32 framebuffer;
    /* 0x10 */ u8 unk10[0x30];
    /* 0x40 */ Gfx *displayList;
    /* 0x44 */ u32 displayListBytes;
} GraphicsTaskFinalizeView; /* prefix size = 0x48 */

/* func_8013A018: graphics_select_microcode.
 * D_8011C720 is RSP boot text; func_8011C7F0 marks its end (not called here).
 * D_801BC710 / D_801F2640 are the default graphics microcode text / data.
 * D_801BDB40 / D_801F2E40 are the alternate graphics microcode text / data.
 * D_801EC7EB selects the graphics microcode mode (handled mode: 4).
 * D_80025C60 is the RSP output buffer; D_801EC7D4 is its capacity in 8-byte words.
 */
/* Signed address view used while selecting microcode; offsets include the
 * scheduler's 0x10-byte prefix. Other task views retain their existing types. */
typedef struct GraphicsTaskMicrocodeView {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 rspFlags;
    /* 0x18 */ s32 bootMicrocode;
    /* 0x1C */ s32 bootMicrocodeBytes;
    /* 0x20 */ s32 microcodeText;
    /* 0x24 */ u8 unk24[4];
    /* 0x28 */ s32 microcodeData;
    /* 0x2C */ u8 unk2C[0x10];
    /* 0x3C */ s32 outputBufferEnd;
    /* 0x40 */ s32 displayList;
} GraphicsTaskMicrocodeView; /* prefix size = 0x44 */

enum GraphicsMicrocodeConstants {
    GRAPHICS_MICROCODE_DEFAULT_MODE = 4,
    GRAPHICS_OUTPUT_WORD_BYTES = 8
};

enum GraphicsTaskFinalizeConstants {
    GFX_CMD_FULL_SYNC = 0xE9000000,
    GFX_CMD_END_DISPLAY_LIST = 0xB8000000,
    GRAPHICS_TASK_DISPLAY_LIST_LIMIT = 0x4E20,
    GRAPHICS_TASK_SWAP_BUFFER = 0x40,
    GRAPHICS_ARENA_DISPLAY_LIST_OFFSET = 0x4100
};

/* func_8013D4DC: clearDepthBuffer. Appends six commands at D_80202240,
 * the active Gfx write cursor, to fill the 320x240 depth image.
 * D_430 is its physical address (0x430), corresponding to D_80000430
 * used by the depth-image setup. Keep the symbol cast for matching.
 * Each halfword of the fill value is maximum packed depth (0xFFFC).
 * Symbol renaming is currently unsupported for this N64 project.
 */
enum DepthBufferClearConstants {
    GFX_FILL_DEPTH_MAX = 0xFFFCFFFC
};

enum FramebufferClearCommands {
    GFX_CYCLE_ONE = 0,
    GFX_CYCLE_TWO = 0x00100000,
    GFX_CYCLE_FILL = 0x00300000,
    GFX_CMD_COLOR_IMAGE_RGBA16_320 = 0xFF10013F,
    GFX_CMD_FILL_COLOR = 0xF7000000,
    GFX_FILL_BLACK_OPAQUE = 0x00010001,
    GFX_CMD_FILL_RECT_320X240 = 0xF64FC3BC,
    GFX_FILL_RECT_ORIGIN = 0,
    FRAMEBUFFER_KSEG0_TO_PHYSICAL = 0x80000000,
    RGBA5551_RED_MASK = 0xF800,
    RGBA5551_GREEN_MASK = 0x07C0,
    RGBA5551_BLUE_MASK = 0x003E,
    RGBA5551_OPAQUE = 1
};

/* Eight log2 midpoint samples for envelope-rate mantissas in [0.5, 1).
 * Entry i approximates log2((8.5 + i) / 16); size 0x40. */
typedef struct EnvRateLogTable {
    /* 0x00 */ f64 d[8];
} EnvRateLogTable;

/* func_80142700: object_init_components.
 * func_8013FCDC allocates tagged memory; func_801D2150 formats a label;
 * func_80133900 copies the model's ActorAnimation and resets playback.
 * D_80105F74 = "ActBeh%d", D_80105F80 = "ActCol%d",
 * D_80105F8C = "Act_Anim", D_80105F98 = "Act_Shad",
 * D_80105FA4 = "Act_Stats". D_801EC814/810 are behavior/collision
 * allocation serials, initially zero.
 * D_80105FB0/FB8 = 1.0f (scale and stats defaults);
 * D_80105FB4 = 2.5f (physics unk2C). D_801F0238 is the unit shadow quad.
 * Collision uses BallCollisionState/ObjectCollisionSphere; animation uses
 * ActorAnimation. Raw offsets preserve existing access types and aliasing.
 * Symbol names remain unchanged because N64 renaming is unsupported.
 */
enum ObjectComponentFlags {
    OBJECT_COMPONENT_PHYSICS = 1,
    OBJECT_COMPONENT_COLLISION = 2,
    OBJECT_COMPONENT_ANIMATION = 4,
    OBJECT_COMPONENT_SHADOW = 8,
    OBJECT_COMPONENT_STATS = 0x10
};

enum ObjectComponentInitConstants {
    OBJECT_COMPONENT_LABEL_BYTES = 0x18,
    OBJECT_PHYSICS_BYTES = 0x50,
    OBJECT_COLLISION_BYTES = 0x18C,
    OBJECT_ANIMATION_BYTES = 0x50,
    OBJECT_SHADOW_BYTES = 0x58,
    OBJECT_STATS_BYTES = 0x34,
    OBJECT_COMPONENT_MODEL = 0xC8,
    OBJECT_COMPONENT_STATS_OFFSET = 0xD4,
    MODEL_ANIMATION_TEMPLATE = 0x18,
    PHYSICS_UNK2C = 0x2C,
    COLLISION_SPHERE_COUNT = 0x18B,
    COLLISION_FIRST_SPHERE_FLAGS = 0x7A,
    COLLISION_INITIAL_SPHERE_FLAGS = 0x20,
    COLLISION_CONTACT_SLOTS = 4,
    COLLISION_UNK044_SLOTS = 0x44,
    SHADOW_QUAD_OFFSET = 0x10,
    SHADOW_UNK0C = 0xC,
    SHADOW_UNK0D = 0xD,
    SHADOW_UNK0E = 0xE,
    SHADOW_INITIAL_UNK0E = 10,
    STATS_ACTOR_INDEX = 2,
    STATS_UNK10 = 0x10,
    STATS_UNK14 = 0x14,
    STATS_UNK18 = 0x18,
    OBJECT_INITIAL_OPACITY = 100
};

/* func_80183240: an object's model (+0xC8) points at its model data (+0xC),
 * whose +0x14 points at the animation count (s16). Objects whose model has no
 * animations get OBJECT_FLAG_STATIC_MODEL in ACTOR_FLAGS. */
enum ObjectModelDataOffset {
    MODEL_DATA = 0xC,
    MODEL_DATA_ANIMATION_COUNT = 0x14,
    OBJECT_FLAG_STATIC_MODEL = 4
};

/* Bitwise copy of four EffectQuadVertex records; size = 0x40. */
typedef struct ObjectShadowQuadWords {
    /* 0x00 */ s32 words[16];
} ObjectShadowQuadWords;

/* func_801B3408: ball_destroy_with_debris. Hides the ball, clears its
 * collision contacts, detaches ball/player attachments and starts recovery.
 * D_8029F487 selects BallTextureIndex; D_8029F486 becomes destroyed (2).
 * D_8029F99E is the ball's s16 opacity (ObjectNode +0x26);
 * D_8029FA34/38/3C are its X/Y/Z scales. D_8029FA60 is the debris model.
 * D_8029FA50 points to BallCollisionState: the first sphere's current/target
 * radii are +0x70/+0x74, contact pointers start at +0, count is +0x188.
 * D_802900DC and D_8029F468 receive the player/ball recovery timers.
 * D_8029F9A4 is the ball support; D_8029F9A0 and D_80290300 are ball/player
 * flags. D_8029F5C8 is a signed ball-state counter reset on destruction.
 * D_8028FBD8 is the player action countdown; D_8029030C is player position.
 * D_8029014C is a PositionalSound emitter. These globals reside in BSS.
 * func_80178134 plays positional sound; func_801B362C emits radial debris.
 * func_8015C4C8 tests player support and compatible ball-interaction actions;
 * func_80167604 enters a player action. func_801963AC / func_801964B0
 * end the interactions with D_8029F46C / D_802900C8 (ball/player actors).
 * func_801785E0 replaces a tracked positional sound.
 * Preserve raw pointer arithmetic and shared declarations for matching.
 */
enum BallDestructionConstants {
    BALL_DESTROY_TARGET_RADIUS_OFFSET = 0x74,
    BALL_DESTROY_POSITION_HALFWORDS_FROM_OPACITY = 7,
    BALL_DESTROY_OBJECT_HALFWORDS_BEFORE_OPACITY = 0x13,
    BALL_DESTROY_BREAK_SOUND = 0x8A,
    BALL_DESTROY_BOWLING_SOUND = 0x13A,
    BALL_DESTROY_SOUND_PITCH = 128,
    BALL_DESTROY_BEARING_SOUND_PITCH = 150,
    BALL_DESTROY_DEBRIS_COUNT = 10,
    BALL_DESTROY_BEARING_DEBRIS_COUNT = 8,
    BALL_DESTROY_RECOVERY_FRAMES = 30,
    BALL_DESTROY_PLAYER_DELAY = 10,
    BALL_DESTROY_PLAYER_ACTION = 9,
    BALL_DESTROY_PLAYER_CLEAR_FLAGS = 0x40,
    BALL_DESTROY_CLEAR_FLAGS = 0x10,
    BALL_DESTROY_CONTACT_COUNT_OFFSET = 0x188,
    BALL_STATUS_DESTROYED = 2,
    BALL_DESTROY_PLAYER_SOUND_PITCH = 140
};

/* func_801992E0: actor_type43_update_effects.
 * ACTOR_ANIMATION points to ActorAnimation. Byte-offset accesses preserve
 * the existing aliasing behavior. Collision byte +0x189 is still unknown.
 * func_80178134: play_positional_sound(sound, position, volume, pitch).
 * func_801A2944: actor_animation_crossed_frame(frame, actor), testing
 * ActorAnimation.frame in [frame, frame + ActorAnimation.speed).
 * func_801B70F8: spawn_particle_ring(position, count, verticalSpeed, scale).
 * Pool data verified in asm/1000.s: D_8010A704/708/70C/710/714/718
 * are sound cue frames 127/133/139/145/151/157. The f64 at
 * D_8010A718 + 4 is the target-pitch increment 0.08; D_8010A724
 * is the contact pitch decrement 1.0f. Keep their declared types.
 */
enum Type43EffectConstants {
    TYPE43_PRESERVED_FLAGS = 0x1FFFF,
    TYPE43_AIRBORNE_OR_ANIM12_FLAGS = 0x60000,
    TYPE43_ANIM_START_SOUND = 6,
    TYPE43_ANIM_CONTACT_SOUND = 8,
    TYPE43_ANIM_SET_FLAGS = 12,
    TYPE43_ANIM_REPEATED_SOUND = 15,
    TYPE43_ACTION_TILT = 23,
    TYPE43_SOUND_ACTION_FRAME = 2,
    TYPE43_START_SOUND = 0x4D,
    TYPE43_REPEATED_SOUND = 0x4C,
    TYPE43_TILT_SOUND = 0x76,
    TYPE43_CONTACT_SOUND = 0x4B,
    TYPE43_LOUD_VOLUME = 100,
    TYPE43_QUIET_VOLUME = 50,
    TYPE43_START_SOUND_PITCH = 60,
    TYPE43_CONTACT_UNK189 = 0x189,
    TYPE43_CONTACT_PARTICLE_COUNT = 3
};

/* func_801B7764: spawn_rising_particle_ring(position, count, particleType).
 * Vec3F holds the initial velocity. ParticleSpawnOffset describes the object
 * and its physics component; ParticleRingConstants describes sprite scales.
 * func_80147000: random_below; func_801490AC: rotate_vector_y;
 * func_801B66D4: spawn_particle. D_801ED3C4 starts the zero vector.
 * Pool values verified in asm/1000.s: D_8010BD70 is a full turn (f64),
 * D_8010BD78 divides the random starting angle by 10 (f64),
 * D_8010BD80 is radial speed 4, D_8010BD84 is physics response 0.9,
 * D_8010BD88/8C/90 produce vertical speed (random / 40 + 1) * 10,
 * and D_8010BD94 is type-19 vertical speed 8.
 * Type 19 enables physics, doubles horizontal speed and doubles sprite size.
 */
/* func_801B7984: spawn_impact_particle_ring(center, heightOffset).
 * Five type-0 particles start at radius 16 and move horizontally outward.
 * func_80147000 returns a random integer below its bound; func_801490AC
 * rotates a Vec3F about Y; func_80149318 copies only X/Z components;
 * func_801B66D4 spawns a pooled particle and returns zero on failure.
 * Pool values verified in asm/1000.s: D_8010BD98 = 2*pi/5 radians (f32),
 * D_8010BD9C = 0.2 (f64 across two words), D_8010BDA4 = radius 16 (f32).
 * Odd particles set sprite flag 2; its visual meaning remains unknown.
 * Keep the raw field casts and grouped loads before stores for matching.
 */
enum ImpactParticleRingConstants {
    IMPACT_PARTICLE_RING_COUNT = 5,
    IMPACT_PARTICLE_ALTERNATE_FLAG = 2,
    IMPACT_PARTICLE_SCALE_MULTIPLIER = 2
};

enum RisingParticleRingConstants {
    RISING_PARTICLE_ANGLE_RANGE = 62,
    RISING_PARTICLE_VERTICAL_SPEED_RANGE = 10,
    RISING_PARTICLE_ENLARGED_TYPE = 19,
    RISING_PARTICLE_SPRITE_SCALE_MULTIPLIER = 2,
    PARTICLE_VELOCITY_Z_OFFSET = 0x60
};

/* func_801764A8: player_detach_from_actor.
 * func_80197794 selects an actor script instruction, skipping unmet conditions;
 * func_80133998 starts or queues an animation; func_80167604 enters a player
 * action; func_8016049C adds forward velocity and caps horizontal speed.
 * D_802900C8 is the player's attachment actor; D_802996E8 is the actor array.
 * D_80299708, D_80299930 and D_80299960 alias its type, action cooldown and
 * action delay fields. The contact component at +0xD4 holds the slot index.
 * ActorAnimation describes the animation component. Preserve raw accesses
 * here because changing their aliasing changes instruction scheduling.
 * D_80290334 is player Y velocity; D_8028FAC8/D0 track position/velocity.
 * D_802903AC points to player action state; D_802903A8 to physics parameters.
 * D_801FAAC8 is a per-controller input byte, with 400-byte controller stride.
 * Pool words in asm/1000.s give D_801084B0 = 0.5 (f64), B8 = 5 (f32).
 */
enum PlayerDetachConstants {
    PLAYER_DETACH_TYPE16 = 0x10,
    PLAYER_DETACH_TYPE29 = 0x1D,
    PLAYER_DETACH_TYPE29_INSTRUCTION = 7,
    PLAYER_DETACH_DEFAULT_INSTRUCTION = 1,
    PLAYER_DETACH_ACTOR_COOLDOWN = 50,
    PLAYER_DETACH_TYPE16_ANIMATION = 15,
    PLAYER_DETACH_TYPE29_ANIMATION = 5,
    PLAYER_DETACH_STATE = 9,
    PLAYER_DETACH_OBJECT_FLAG = 0x100,
    PLAYER_DETACH_CONTROLLER_STRIDE = 400,
    PLAYER_DETACH_Y_VELOCITY_TO_OBJECT = 0x5C,
    PLAYER_DETACH_Y_VELOCITY_TO_POSITION = 0x28,
    PLAYER_DETACH_Y_VELOCITY_TO_VELOCITY = 4,
    PLAYER_PHYSICS_HORIZONTAL_SPEED_LIMIT = 8,
    ANIM_CURRENT_OFFSET = 2,
    ANIM_FIRST_QUEUED_SPEED_OFFSET = 0x30,
    ANIM_CLIP15_SPEED_OFFSET = 0xB8
};

/* func_80191284: actor_make_model_unique. The first actor uses the loaded
 * model; later actors copy its container, tree nodes and sprite records.
 * func_80191120 recursively copies a tree; func_8013FCDC allocates memory.
 * D_802996A8 contains per-type model reference counts; D_801F00A8 model names.
 * Allocation labels in asm/1000.s: D_80109D04 "UniqAct", D_80109D0C "UniqSpr",
 * D_80109D14 "UniqObjC"; D_80109D20 is "Found duplicate enemy %s\\n".
 * func_801D2150 formats that diagnostic into D_8025D578; func_80139D70
 * is the disabled debug-output hook.
 */
/* func_80191120: actor_copy_model_tree.
 * Copy each node and its sprite records, then recurse through first child
 * (left) and next sibling (right). The inline items array belongs to the
 * copied node; pointers inside each sprite record remain shared.
 * func_8013FCDC(size, 1, tag) allocates zeroed memory with a diagnostic label.
 */
typedef struct ActorModelSprite {
    /* 0x00 */ s32 unk0[6];
} ActorModelSprite; /* size = 0x18 */

typedef struct ActorModelTreeNode {
    /* 0x00 */ u8 unk0[0x28];
    /* 0x28 */ s32 itemCount;
    /* 0x2C */ ActorModelSprite *items[2];
    /* 0x34 */ struct ActorModelTreeNode *left;  /* First child. */
    /* 0x38 */ struct ActorModelTreeNode *right; /* Next sibling. */
    /* 0x3C */ s32 unk3C;
} ActorModelTreeNode; /* size = 0x40 */

typedef struct ActorModelContainer {
    /* 0x00 */ s32 w[7]; /* Word 3 holds the root node address. */
} ActorModelContainer; /* size = 0x1C */

/* func_80191640: actor_create. D_802996E8 holds ACTOR_INSTANCE_STRIDE-byte
 * actor slots; D_801F0198 counts occupied slots; D_801F00A8 holds model names.
 * func_8013FBC0 clears bytes; func_80142928 loads a named model and initializes
 * requested components; func_8015C350 converts Euler angles to a quaternion.
 * func_80191284 makes the model unique; func_80191794 resets spawn state.
 * The 0xE4-byte object prefix is cleared before the entire actor slot.
 * Preserve both clears and the raw field accesses used by the original code. */
enum ActorCreateConstants {
    ACTOR_OBJECT_PREFIX_BYTES = 0xE4,
    ACTOR_INITIAL_COMPONENTS = 0x1E, /* Collision, animation, shadow and stats. */
    ACTOR_OVERRIDE_COUNT = 0x24C,
    ACTOR_CREATE_UNK24E = 0x24E
};

enum ActorModelCopyConstants {
    ACTOR_MODEL_CONTAINER_OFFSET = 0xC8,
    ACTOR_MODEL_ROOT_WORD = 3,
    ACTOR_MODEL_CONTAINER_SIZE = 0x1C,
    ACTOR_MODEL_NODE_SIZE = 0x40,
    ACTOR_MODEL_SPRITE_SIZE = 0x18
};

/* func_801990D4: actor_type44_update_effects.
 * ActorAnimation at ACTOR_ANIMATION supplies the clip and loop flag.
 * func_8016049C accelerates forward with a horizontal speed limit;
 * func_80133E24 tests the animation frame window [cue, cue + speed).
 * func_801B70F8 emits a particle ring; func_801B9974 starts attenuated shake;
 * func_80178134 plays positional audio.
 * D_8010A6FC is the f64 horizontal damping factor 0.5, verified from
 * the words 0x3FE00000, 0 in asm/1000.s. Contact state is tested as a
 * packed word at +0x188; its individual bytes retain their existing types.
 */
/* func_8019993C: actor_type34_update_landing.
 * One contact with a zero adjacent state byte triggers animation 5 and
 * velocity-directed deformation, plus sound and particles below the threshold.
 * D_8010A740 is -5.0f; the f64 at +4 is 0.1 (verified in asm/1000.s).
 * Actor +0x68 is the effect gate; its broader role is not established.
 * Physics +0x30 caps deformation. D_80290304 is the player's attached actor;
 * its type-34 actor bypasses the speed limit while attached.
 * func_80178134: sound_play_positional; func_80133998: actor_set_animation;
 * func_801B70F8: particle_spawn_radial_ring; func_80149568: vec3_normalize;
 * func_801B10B8: setActorDirectionalDeformation. N64 symbol renaming is
 * unavailable; retain raw accesses to preserve the existing aliasing behavior.
 */
enum Type34LandingConstants {
    TYPE34_CONTACT_STATE_MASK = 0xFFFF0000,
    TYPE34_LANDING_CONTACT_STATE = 0x01000000,
    TYPE34_EFFECT_GATE_UNK68 = 0x68,
    TYPE34_LANDING_ANIMATION = 5,
    TYPE34_LANDING_SOUND = 0x14,
    TYPE34_LANDING_VOLUME = 100,
    TYPE34_LANDING_PARTICLE_COUNT = 4,
    TYPE34_DEFORMATION_LIMIT_OFFSET = 0x30,
    TYPE34_DEFORMATION_FACTOR_POOL_OFFSET = 4
};

enum Type44EffectConstants {
    TYPE44_ANIM_LOCK_YAW = 5,
    TYPE44_ANIM_DOUBLE_ACCELERATION = 6,
    TYPE44_ANIM_DAMP_VELOCITY = 10,
    TYPE44_ANIM_MOVE = 15,
    TYPE44_CONTACT_STATE_MASK = 0xFFFF0000,
    TYPE44_CONTACT_EFFECT_STATE = 0x01000000,
    TYPE44_STEP_SOUND_A = 0x34,
    TYPE44_STEP_SOUND_B = 0x35,
    TYPE44_CONTACT_SOUND = 0x36,
    TYPE44_LOUD_VOLUME = 100,
    TYPE44_QUIET_VOLUME = 50,
    TYPE44_CONTACT_PARTICLE_COUNT = 3,
    TYPE44_SHAKE_DURATION = 6,
    TYPE44_SHAKE_CYCLES = 1,
    TYPE44_SHAKE_FLAGS = 2,
    ANIMATION_LOOP_OFFSET = 8,
    ACTOR_PHYSICS_ACCELERATION_OFFSET = 4
};

/* func_8013E90C: measure_retrace_clock_rate.
 * After twelve blocking receives, measure one scheduler-client message interval.
 * func_801C7430 is osRecvMesg; func_801C62B0 is osGetCount (CP0 Count).
 * D_80258EE0 is the game's scheduler-client OSMesgQueue (0x18 bytes).
 * D_802586E8 stores count ticks per measured interval (32-bit wraparound);
 * D_80201000 stores the resulting floating-point ticks-per-second estimate.
 * D_80000300 is osTvType: zero selects PAL, otherwise use 60 Hz.
 * Verified words in asm/1000.s: the doubles at D_80105CF0 + 4,
 * D_80105CF8 + 4 and D_80105D00 + 4 are 4294967296, 50 and 60.
 * These doubles straddle existing labels; keep the declarations and casts.
 */
enum RetraceClockConstants {
    RETRACE_CLOCK_POOL_DOUBLE_OFFSET = 4
};

/* func_8019DCE4: updateType22BallPursuit. ActorTransformView describes
 * the shared transform fields; raw accesses retain this routine's aliasing.
 * The s32 at +0x26C is 0 when idle, 1 while pursuing, or a retry countdown.
 * D_8010AA2C is the pursuit trigger distance, 130.0f (asm/1000.s).
 * D_8029F9AC starts ball XYZ; D_8029F9D0 starts ball velocity XYZ.
 * D_8029030C/310/314 hold player XYZ (all are runtime BSS fields).
 * func_80148D0C adds a scaled vector; func_80148E48 measures 3D distance.
 * func_80147460 is table-based atan2; func_801496C8 wraps by one turn.
 * func_80193298 steers toward a point; func_80160228 approaches an axis angle.
 * func_80178134 plays positional sound; func_801A9054 spawns actor effects.
 */
enum Type22BallPursuitConstants {
    TYPE22_PURSUIT_STATE_OFFSET = 0x26C,
    TYPE22_PURSUIT_ACTIVE = 1,
    TYPE22_PURSUIT_COUNTDOWN_MIN = 2,
    TYPE22_BALL_CONTACT_FLAG = 0x4000000,
    TYPE22_CONTACT_RETRY_FRAMES = 20,
    TYPE22_PURSUIT_COOLDOWN_FRAMES = 100,
    TYPE22_PURSUIT_DURATION_FRAMES = 150,
    TYPE22_ANIM_TRACK_PLAYER = 12,
    TYPE22_ANIM_EFFECT = 3,
    TYPE22_EFFECT_ACTION_FRAME = 1,
    TYPE22_EFFECT_SOUND = 0x66,
    TYPE22_EFFECT_VOLUME = 100,
    TYPE22_EFFECT_PITCH = 128,
    TYPE22_EFFECT_ID = 10
};

/* func_801ADDC4: applyActorStatusEffect. Adds to a 16-bit status timer;
 * stun stops both PositionalSound records, while transform has type/level
 * exceptions that restore the normal target radius instead of changing form.
 * D_8029999C starts the stun/shrink/transform timers in actor slot zero.
 * D_802999A0, D_80299CA0 and D_80299FA0 are transform timers in slots 0/1/2.
 * D_802997B8 and D_802997C0 are slot zero's physics/collision pointers;
 * D_802999B0 starts its tracked sounds. These aliases are runtime BSS.
 * D_801E7531 is the current level (initial data byte 0xFF).
 * Collision +0x170 is the special target size approached at +0x16C by
 * func_801A1558; +0x74 is ObjectCollisionSphere's first targetRadius.
 * Physics +0x48 supplies the normal radius. Keep raw casts and table strides.
 * func_80178704 stops a tracked sound and saves its volume for resumption.
 */
enum ActorStatusApplicationConstants {
    ACTOR_STATUS_IMMUNE_TYPE = 31,
    ACTOR_STATUS_SPECIAL_SIZE_TYPE = 40,
    ACTOR_STATUS_RADIUS_TYPE33 = 33,
    ACTOR_STATUS_RADIUS_TYPE38 = 38,
    ACTOR_STATUS_TIMER_BYTES = 2,
    ACTOR_STATUS_TRANSFORM_TIMER_OFFSET = 4,
    ACTOR_STATUS_TO_SOUNDS_OFFSET = 0x14,
    ACTOR_STATUS_RETRY_FRAMES = 50,
    ACTOR_STATUS_NORMAL_RADIUS_OFFSET = 0x48,
    ACTOR_STATUS_TARGET_RADIUS_OFFSET = 0x74,
    ACTOR_STATUS_SPECIAL_TARGET_SIZE_OFFSET = 0x170
};

/* func_8017CF00: platform_update, the per-frame platform dispatcher.
 * D_802004E0 is the state frame counter; the f64 at D_80108880 + 4
 * is the squared movement threshold for the platform's looping sound.
 * func_801785E0 / func_80178704 / func_80178760 start, stop and update
 * PositionalSound. The sound embedded at +0x164 uses +0x170 as a packed
 * volume word, so its existing halfword view is retained here.
 * func_8017D7B8 refreshes collision triangles; func_801246AC handles level
 * trigger interactions; func_8017D0FC applies overlapping force volumes.
 * func_8018AA60 applies wind-cone forces; func_8017A514 updates falling
 * platforms; func_8017A38C animates scale; func_8017AE0C inherits parent
 * motion and computes the path target; func_8017A6B8 updates path velocity.
 * func_8017B178 updates rotation steps; func_8017B780 updates orbit motion;
 * func_8017BDD0 integrates and bounds motion; func_8017C17C integrates
 * angular motion; func_8017E324 updates shrink/ball-contact effects.
 */
/* func_8017D0FC: platform_apply_water_forces. For every WaterVolume in the
 * list at D_80299250 whose box holds the platform's position, it adds gravity
 * (D_801ED680) back to the velocity, applies the water forces to the embedded
 * physics body at +0x80 (func_801B4078), and clamps speed to maxSpeed. */
typedef struct PlatformPhysicsView {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ f32 maxSpeed;
    /* 0x20 */ u8 pad20[0x60];
    /* 0x80 */ u8 body[0x34]; /* physics body; its position/velocity follow */
    /* 0xB4 */ f32 position[3];
    /* 0xC0 */ u8 padC0[0x18];
    /* 0xD8 */ f32 velocity[3];
    /* 0xE4 */ u8 padE4[0x10];
    /* 0xF4 */ f32 speed;
} PlatformPhysicsView; /* partial view, size = 0xF8 */

typedef struct PlatformUpdatePosition {
    f32 x, y, z;
} PlatformUpdatePosition; /* size = 0x0C */

typedef struct PlatformUpdateState {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ s32 triggerType;
    /* 0x01C */ u8 pad1C[0x20];
    /* 0x03C */ s16 *fallState; /* timer at [0], fall threshold at [2] */
    /* 0x040 */ s32 pushState;
    /* 0x044 */ u8 pad44[0x6E - 0x44];
    /* 0x06E */ u16 collisionUpdateFrame;
    /* 0x070 */ u8 pad70[0xA3 - 0x70];
    /* 0x0A3 */ u8 collisionEnabled;
    /* 0x0A4 */ u8 padA4[2];
    /* 0x0A6 */ s16 unkA6; /* zero suppresses starting the movement sound */
    /* 0x0A8 */ s32 renderFlags;
    /* 0x0AC */ u8 padAC[0xB4 - 0xAC];
    /* 0x0B4 */ PlatformUpdatePosition position;
    /* 0x0C0 */ PlatformUpdatePosition previousPosition;
    /* 0x0CC */ u8 padCC[0x164 - 0xCC];
    /* 0x164 */ s32 movementSoundHandle;
    /* 0x168 */ s32 movementSoundVolume;
    /* 0x16C */ u8 pad16C[4];
    /* 0x170 */ s16 movementVolumeHigh;
    /* 0x172 */ s16 movementVolume;
    /* 0x174 */ s16 movementPitch;
    /* 0x176 */ s16 movementSoundId;
} PlatformUpdateState; /* partial platform view, size = 0x178 */

/* func_8017A514: platform_update_falling. D_801ED680 is gravity.
 * func_801785E0 / func_80178704 / func_80178760 start, stop and update
 * tracked positional audio. The sound at +0x18 fades by reducing its volume.
 * Position copies use integer words to preserve the floating-point bits. */
typedef struct FallingPlatformState {
    /* 0x00 */ s16 frame;
    /* 0x02 */ s16 disappearFrame;
    /* 0x04 */ s16 fallStartFrame;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ f32 gravityScale;
    /* 0x0C */ u8 initialPosition[0x0C];
    /* 0x18 */ s32 soundHandle;
    /* 0x1C */ s32 soundVolume;
    /* 0x20 */ u8 unk20[6];
    /* 0x26 */ s16 initialSoundVolume;
    /* 0x28 */ s16 soundPitch;
    /* 0x2A */ s16 soundId;
} FallingPlatformState; /* accessed prefix size = 0x2C */

typedef struct FallingPlatformView {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 flags;
    /* 0x18 */ u8 unk18[0x24];
    /* 0x3C */ FallingPlatformState *fall;
    /* 0x40 */ u8 unk40[0x66];
    /* 0xA6 */ s16 unkA6; /* restored to 100 on reset, zero on disappearance */
    /* 0xA8 */ u8 unkA8[0x0C];
    /* 0xB4 */ Vec3Words position;
    /* 0xC0 */ u8 unkC0[0x18];
    /* 0xD8 */ f32 velocityX;
    /* 0xDC */ f32 velocityY;
    /* 0xE0 */ f32 velocityZ;
} FallingPlatformView; /* accessed prefix size = 0xE4 */

enum FallingPlatformConstants {
    FALL_PLATFORM_RESET_DELAY = 400,
    FALL_PLATFORM_RESET_UNKA6 = 100,
    FALL_PLATFORM_DISAPPEARED = 4,
    FALL_PLATFORM_INITIAL_POSITION = 0x0C,
    FALL_PLATFORM_SOUND_FADE_STEP = 60
};

/* func_8017E324: platform_update_ball_contact.
 * D_80108898 is 8.0f: scale easing divisor and initial particle speed.
 * D_802900E0 identifies the activated platform; D_8028F914 is camera XYZ.
 * D_8029F9AC/B0/B4 are current ball XYZ; D_8029F9BC is previous ball Y.
 * Those runtime globals reside in BSS. Contact requires a downward crossing
 * of platform Y while inside its XZ radius; activation saves camera position.
 * func_80148DB0 measures XZ distance; func_801490AC rotates around Y;
 * func_801BB5C4 emits a randomly colored type-0x15 particle at the supplied
 * position and velocity, scaling its dimensions; func_80178134 plays 3D sound.
 * Raw accesses retain the shared platform representation and integer zero store.
 * Nintendo 64 symbol renaming is unsupported; descriptive names are recorded here. */
typedef struct PlatformBallContactState {
    /* 0x00 */ u8 unk00[4];
    /* 0x04 */ f32 savedCameraPosition[3];
    /* 0x10 */ u8 unk10[4];
    /* 0x14 */ s16 armed;
    /* 0x16 */ u8 unk16[2];
    /* 0x18 */ f32 targetScale;
} PlatformBallContactState; /* accessed prefix size = 0x1C */

enum PlatformBallContactFields {
    PLATFORM_CONTACT_ROTATION = 0x2C,
    PLATFORM_CONTACT_SAVED_CAMERA = 0x04,
    PLATFORM_CONTACT_ARMED = 0x14,
    PLATFORM_CONTACT_TARGET_SCALE = 0x18
};

enum PlatformBallContactConstants {
    PLATFORM_CONTACT_PARTICLE_COUNT = 6,
    PLATFORM_CONTACT_SOUND = 0x118,
    PLATFORM_CONTACT_SOUND_VOLUME = 100
};

enum PlatformUpdateConstants {
    PLATFORM_MOVEMENT_SOUND_FADE_STEP = 60,
    PLATFORM_APPLY_FORCE_VOLUMES = 0x200000
};

/* func_801BC240: cheat_notification_update. Slides the cheat name to the
 * screen center, holds it, then accelerates it off the left edge while the
 * entered button-code glyphs rise, fade and emit sparks.
 * D_801F21A4 is the persistent message; D_801F21A8 counts frames after it
 * reaches the center; D_801F2638 is the hold duration; D_801F2194 is the
 * code's alpha decrement per frame. D_802AB000 holds the saved code glyphs;
 * D_8010C010 supplies their drawing scale; D_802004E0 is the state frame.
 * func_80145680 selects the font; func_80145928 measures text width;
 * func_80145CEC unlinks and frees text; func_801469E4 queues text;
 * func_8014E8B4 emits radial screen particles; func_80147000 returns a
 * pseudorandom integer below its argument.
 * Cast this view at the access; existing global declarations stay unchanged.
 */
typedef struct QueuedTextView {
    /* 0x00 */ u8 unk0[8];
    /* 0x08 */ u8 text[64];
    /* 0x48 */ s32 x;
    /* 0x4C */ s32 y;
    /* 0x50 */ f32 scaleX;
    /* 0x54 */ f32 scaleY;
    /* 0x58 */ u8 red;
    /* 0x59 */ u8 green;
    /* 0x5A */ u8 blue;
    /* 0x5B */ u8 alpha;
    /* 0x5C */ s32 unk5C;
} QueuedTextView; /* size = 0x60; accessed prefix */

/* func_801BB710: cheat_input_update; returns one after finding a code.
 * D_80202218 selects the controller. D_801FAAD0..3 are its four code-input
 * bytes; func_801BB8D4 maps them to symbols 2, 3, 1, 0 in that priority.
 * D_801FAAC8 cancels entry. Controller records are 400 bytes apart.
 * D_801F2198 holds eight symbols (initially 0xFF); D_801F21A1 is the count.
 * D_801F2197 is one byte before that buffer, so indexing it with the updated
 * count reads the symbol just appended. Preserve this original alias access.
 * D_801F2190 is the feedback sound handle; D_802AAFFC counts down to its stop.
 * D_801F21AC begins four 4-byte sound records: s16 sound ID at +0, an
 * unidentified byte at +2, and playback scale at +3 (D_801F21AF).
 * Original records contain IDs 0x49, 0x6F, 0x6E, 0x6D and scale 0x80.
 * func_801793DC plays a sound with volume, pan and pitch/tempo scale;
 * func_801C0B70 stops its handle. func_801BB938 finds a matching code
 * (or -1); func_801BB9AC applies it and optionally shows feedback.
 * func_8012C2B0 fills a byte buffer.
 */
enum CheatInputConstants {
    CHEAT_INPUT_CONTROLLER_STRIDE = 400,
    CHEAT_INPUT_LENGTH = 8,
    CHEAT_INPUT_EMPTY = 0xFF,
    CHEAT_INPUT_NO_MATCH = -1,
    CHEAT_CODE_COUNT = 26,          /* records in the cheat table D_801F21DC */
    CHEAT_CODE_RECORD_SIZE = 0x2C,  /* 8 input symbols first, then the rest */
    CHEAT_INPUT_SOUND_RECORD_SIZE = 4,
    CHEAT_INPUT_SOUND_VOLUME = 100,
    CHEAT_INPUT_SOUND_PAN_CENTER = 128,
    CHEAT_INPUT_SOUND_DURATION = 12
};

enum CheatNotificationConstants {
    CHEAT_TEXT_OFFSET = 8,
    CHEAT_MESSAGE_CENTER_X = 160,
    CHEAT_MESSAGE_MAX_STEP = 50,
    CHEAT_MESSAGE_EXIT_X = -480,
    CHEAT_MESSAGE_EXIT_ACCELERATION = 3,
    CHEAT_CODE_X = 112,
    CHEAT_CODE_START_Y = 200,
    CHEAT_CODE_RISE_SPEED = 2,
    CHEAT_CODE_INITIAL_ALPHA = 510,
    CHEAT_SPARK_FIRST_FRAME = 3,
    CHEAT_SPARK_X_RANGE = 60,
    CHEAT_SPARK_MIN_X = 130,
    CHEAT_SPARK_COUNT = 2
};

/* func_801CA844 (alFxParamHdl) updates one AudioEffectDelay section.
 * D_801F46D0 is the synth driver (output sample rate at +0x44).
 * D_8010C5E0 is f64 173123.404906676, the modulation-depth divisor.
 * func_801C7EB0 (_init_lpfilter) rebuilds low-pass coefficients.
 * Rate parameters are millihertz; delay offsets are aligned to eight samples.
 */
enum AudioEffectParameter {
    AUDIO_FX_PARAM_INPUT = 0,
    AUDIO_FX_PARAM_OUTPUT = 1,
    AUDIO_FX_PARAM_FEEDFORWARD = 2,
    AUDIO_FX_PARAM_FEEDBACK = 3,
    AUDIO_FX_PARAM_GAIN = 4,
    AUDIO_FX_PARAM_MODULATION_RATE = 5,
    AUDIO_FX_PARAM_MODULATION_DEPTH = 6,
    AUDIO_FX_PARAM_LOW_PASS_CUTOFF = 7,
    AUDIO_FX_PARAMS_PER_SECTION = 8,
    AUDIO_FX_PARAM_HEADER_WORDS = 2,
    AUDIO_FX_DELAY_ALIGNMENT_MASK = 7
};

/* func_8015C580: initializeModelSprites; allocates render sprites recursively.
 * SprGroup: count/entries at 0x28/0x2C, child/sibling at 0x34/0x38;
 * unk0D below 255 selects render flag 1.
 * SprEntry (0x18 bytes): texture/node at 0/4, unk0E/unk10 are doubled
 * once for 16-pixel texture width/height; flags at 0x16 records this.
 * SprNode (0x24-byte prefix of a 0x38-byte allocation): texture at 8,
 * float position stored in v[3] at 0x0C, BGRA at 0x1D, render flags
 * at 0x21, signed pixel origin offsets ox/oy at 0x22/0x23.
 * TexInfo: unsigned texture width/height at 0x0C/0x0E.
 * func_8013FCDC allocates memory; func_8014AC1C inserts the render node.
 * D_801071E8 is "Obj_Sprite"; D_801ED3C4 starts the shared zero vector.
 */
/* func_801627AC: object_destroy; unlinks the object, frees its components
 * and model sprites, then frees the object allocation.
 * func_8015CB44: object_unlink; detaches both object lists and model sprites.
 * func_801626EC: model_free_sprites; visits child/sibling nodes recursively.
 * func_80141720: heap_free_and_clear; releases through an allocation address.
 * func_801D2150: sprintf; func_80139D70: disabled debug-output hook.
 * D_8010745C: "Freeing sprite %d from %s\n"; D_8025D578: 256-byte debug buffer.
 * N64 symbol renaming is unsupported; these are the descriptive names.
 *
 * ObjectNode supplies the object layout. Model roots use the existing
 * SprGroup prefix (0x3C); each SprEntry is 0x18 bytes with its runtime
 * sprite allocation at +4. The model-node name starts at +4.
 * Raw word accesses preserve the matched code's aliasing and temporaries.
 */
/* func_8015CB44 removes both memberships without freeing the object or sprites.
 * D_8026A22C counts the primary list (next/unk004 = next/previous);
 * D_8026A13C counts the secondary list (unk008/unk00C = next/previous).
 * func_8014ACB4: world_sprite_unlink.
 * func_8015CA7C: model_unlink_sprites; recursively visits child/sibling nodes,
 * optionally freeing each sprite when its second argument is nonzero.
 * Keep the shared ObjectNode field types and raw pointer accesses unchanged. */
enum ObjectCleanupFields {
    OBJECT_SECONDARY_NEXT_OFFSET = 0x08,
    OBJECT_SECONDARY_PREV_OFFSET = 0x0C,
    OBJECT_SHADOW_COMPONENT = 0xCC,
    MODEL_NODE_NAME = 0x04,
    MODEL_SPRITE_NODE = 0x04,
    MODEL_SPRITE_ENTRY_BYTES = 0x18,
    MODEL_NODE_SPRITE_COUNT = 0x28, /* s32 */
    MODEL_NODE_SPRITES = 0x2C,      /* SprEntry array (MODEL_SPRITE_ENTRY_BYTES each) */
    MODEL_NODE_CHILD = 0x34,        /* ModelTreeNode.child */
    MODEL_NODE_SIBLING = 0x38       /* ModelTreeNode.sibling */
};

/* func_801A40F4: actor type 21 update (scales itself to its collision radius).
 * D_8010AEF0 = 2.0f (initial radius divisor), D_8010AEF4 = 1.0f (animation
 * speed), D_8010AEF8 = 0.8 (shadow size per radius); D_801EFFC8 is the
 * global base actor scale. */
enum RadiusScaledActorFields {
    ACTOR_TYPE_DATA_TIMER = 0x30,     /* s16 countdown in the type data */
    PHYSICS_BASE_RADIUS = 0x48,       /* f32 */
    MODEL_STATE_RADIUS = 0x70,        /* f32 current collision radius */
    MODEL_STATE_TARGET_RADIUS = 0x74, /* f32 */
    ANIMATION_SPEED = 0x4C,           /* f32 */
    SHADOW_COMPONENT_SIZE = 0x08      /* f32 */
};

enum ModelSpriteInitConstants {
    MODEL_SPRITE_ALLOCATION_SIZE = 0x38,
    MODEL_SPRITE_SMALL_TEXTURE_SIZE = 16,
    MODEL_SPRITE_SIZE_ADJUSTED = 8,
    MODEL_SPRITE_COLOR_MAX = 255,
    MODEL_SPRITE_DEFAULT_ALPHA = 128
};

/*
 * func_8012D22C: level23_update_boundary_and_platform_spin.
 * D_8029030C/314 and D_8029F9AC/9B4 are player/ball position X/Z.
 * D_80101B30 = 1100, the XZ boundary radius; D_80101B34 = pi, the
 * platform rotation controller's restoreAngleLimit.
 * D_801E76E0 is the spin axis-angle: initially (102, -46, 55, -0.05712).
 * D_8029970A is actor slot 0's active state. D_80299954 aliases that
 * slot's +0x26C state word, used here as elapsed platform-spin frames.
 * func_80149604 = vec3_normalize_xz; func_80149568 = vec3_normalize;
 * func_80148C3C = quaternion_from_axis_angle;
 * func_8017DBA0 = platform_find_by_tag.
 * Raw offsets retain the existing pointer-access and integer-store semantics.
 * N64 symbol renaming is unsupported; descriptive symbol names are recorded here.
 */
enum Level23PlatformSpinConstants {
    LEVEL23_SPIN_PLATFORM_TAG = 1,
    LEVEL23_PLATFORM_SPIN_FRAMES = 60,
    PLATFORM_ROTATION_RESTORE_ANGLE_LIMIT = 0x28,
    PLATFORM_SPIN_QUATERNION = 0x12C,
    PLATFORM_SPIN_QUATERNION_W = 0x138
};

/* func_801C2314: mus_pitch_ratio_from_octaves, a sixth-order approximation
 * of 2^octaves. Negative offsets use the reciprocal at the positive magnitude.
 * func_801C1C1C converts semitones to octaves with D_8010C180 = 1/12.
 * Coefficients are rounded f64 values of ln(2)^n/n!, in separate literal pools
 * for the positive and reciprocal paths. Keep those distinct symbol accesses:
 *
 * power   positive       reciprocal      coefficient
 *   1     D_8010C188      D_8010C1B8      0.693147180559945
 *   2     D_8010C190      D_8010C1C0      0.240226506959101
 *   3     D_8010C198      D_8010C1C8      0.0555041086648216
 *   4     D_8010C1A0      D_8010C1D0      0.00961812910762848
 *   5     D_8010C1A8      D_8010C1D8      0.00133335581464284
 *   6     D_8010C1B0      D_8010C1E0      0.000154035303933816
 *
 * Powers are computed in f32; coefficients and accumulation use f64.
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */

/* Level event trigger, 0x50 bytes (allocated by func_8018E738, run each frame
 * by func_8018E7F4). Triggers sit on a doubly linked list whose sentinel is a
 * LevelTrigger at D_802994B0 (D_802994B4 is its `next`); the live trigger count
 * follows the sentinel at D_80299500. Links are kept as s32, as the code stores
 * them. When firesLeft (-1 = unlimited) is nonzero and the condition list
 * passes, one fire is used and the action list starts. */
typedef struct LevelTrigger {
    /* 0x00 */ s32 prev;
    /* 0x04 */ s32 next;
    /* 0x08 */ s32 condPrev;     /* condition list head (func_8018E6D0 layout) */
    /* 0x0C */ s32 condNext;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 condCount;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 firesLeft;
    /* 0x20 */ s32 actionPrev;   /* action list head (func_8018E6E8 layout) */
    /* 0x24 */ s32 actionNext;
    /* 0x28 */ s32 unk28[8];
    /* 0x48 */ s32 actionCount;
    /* 0x4C */ s32 actionsRunning;
} LevelTrigger; /* size = 0x50 */

/* One node of a LevelTrigger's action list (ticked by func_8018E888, run by
 * func_8018E9AC when its timer reaches 0). `tag` picks the target: a platform
 * tag, an object id or a variable index, depending on `type`. `arg` holds a
 * vector or up to six shorts; `data` points at extra floats. */
typedef struct TriggerAction {
    /* 0x00 */ s32 prev;
    /* 0x04 */ s32 next;
    /* 0x08 */ s16 timer;    /* frames until it runs; -1 = idle */
    /* 0x0A */ s16 delay;    /* timer reload value */
    /* 0x0C */ s16 type;     /* what the action does (switch in func_8018E9AC) */
    /* 0x0E */ s16 tag;      /* target tag / id / index */
    /* 0x10 */ f32 value;
    /* 0x14 */ union {
        f32 f[3];
        s32 w[3];
        s16 s[6];
        u16 u[6];
    } arg;
    /* 0x20 */ s32 flags;    /* type-specific bits; 0x200: randomise restart delay */
    /* 0x24 */ f32 *data;
} TriggerAction;

/* TriggerAction field offsets. func_8018E9AC reads its action through casts at
 * these offsets: member access marks the loads as in-struct, and gcc 2.7.2's
 * alias analysis then schedules them differently from the ROM. */
enum TriggerActionField {
    TRIGGER_ACTION_TYPE = 0x0C,  /* s16 */
    TRIGGER_ACTION_TAG = 0x0E,   /* s16 */
    TRIGGER_ACTION_VALUE = 0x10, /* f32 */
    TRIGGER_ACTION_ARG = 0x14,   /* f32[3] / s32[3] / s16[6] */
    TRIGGER_ACTION_FLAGS = 0x20, /* s32 */
    TRIGGER_ACTION_DATA = 0x24   /* f32 * */
};
#define TRIGGER_ACTION_ADDR(a, off) (((u8 *) (a)) + (off))
#define TA_TYPE(a)     (*((s16 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_TYPE)))
#define TA_TAG(a)      (*((s16 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_TAG)))
#define TA_VALUE(a)    (*((f32 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_VALUE)))
#define TA_FLAGS(a)    (*((s32 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_FLAGS)))
#define TA_DATA(a)     (*((f32 **) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_DATA)))
#define TA_ARG(a)      TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_ARG)
#define TA_ARG_F(a, i) (*((f32 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_ARG + (i) * 4)))
#define TA_ARG_W(a, i) (*((s32 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_ARG + (i) * 4)))
#define TA_ARG_S(a, i) (*((s16 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_ARG + (i) * 2)))
#define TA_ARG_U(a, i) (*((u16 *) TRIGGER_ACTION_ADDR(a, TRIGGER_ACTION_ARG + (i) * 2)))

/* func_80145258: object draw-distance test. An object is drawn while its
 * squared camera distance is within (bounding radius + D_801EC7DA)^2. */
enum ObjectDrawDistanceOffset {
    OBJECT_CAMERA_DISTANCE_SQUARED = 0x18,
    OBJECT_BOUNDING_RADIUS = 0x30
};

/* func_80121FF4: update_end_of_world_screen.
 * Displays the end-of-world celebration screen: world backdrop, animated waving
 * Glover model (newwave.ndo) in a title box (titleboxb.ndo / titleboxbf.ndo),
 * bouncing "WELL DONE" / world-name letters / "COMPLETE" / bonus-level status
 * text, and celebratory sparkles. Exits after 500 frames or menu button input.
 *
 * Globals (N64 symbol renaming is unsupported; descriptive names recorded here):
 * - D_801E7474: end-of-world frame counter (1 triggers one-time setup).
 * - D_801E75F4: exit transition lock (0 while active, 200 once fading out).
 * - D_801E7534: completed world index (s8); D_801E7586: language index (s16).
 * - D_801E7531: next level ID to load on exit; D_801E7584 bit 0: transition pending.
 * - D_801E75F8 / D_801E75FC / D_801E7600: "WELL DONE" slide offset, velocity, bounces.
 * - D_801E7604 / D_801E7608 / D_801E760C: Glover model drop offset, velocity, bounces.
 * - D_801F7F88[100] / D_801F8118[100] / D_801F8310[100]: per-letter Y offset, velocity, bounces.
 * - D_801F830C: world-name character count; D_801F82A8/A9: 2-byte per-letter strings.
 * - D_801E75D0 / D_801E75D4 / D_801E75D8: world-name sine wave frame divisor, index divisor, amplitude.
 * - D_801E75DC[3] / D_801E75E8[3]: per-language base X positions for "WELL" / "DONE".
 * - D_801F7FD4 / D_801F7FC4: horizontal slide offsets for "COMPLETE" and bonus status.
 * - D_801EAB9C: localized world-name table (3 languages per row).
 * - D_801EAC2C / D_801EAC50 / D_801EAC38: localized "WELL", "DONE", and "COMPLETE"/bonus strings.
 * - D_801E7398: per-world 0x18-byte records starting with the backdrop BMP filename.
 * - D_801F83D8: allocated backdrop sprite; D_80269F48 / D_80269F40[2]: Glover menu model.
 * - D_801F91B0: directional light; D_802991A0: ambient light; D_802978E8: scene view block.
 * - D_801ED400..402: transition RGB; D_801EC7DA: draw distance; D_801EC7D2: block gameplay updates.
 * - D_801EFC92: paced-message interval (2 on screen, 3 on exit).
 * - D_801013BC: "eowscn" render sync tag; D_8010127C: "Backdrop" alloc tag.
 * - D_801012B0 / D_801012C0 / D_801013C4: "titleboxb.ndo", "titleboxbf.ndo", "newwave.ndo".
 */
typedef struct LocalizedWorldNameRow {
    u8 *s[3];
} LocalizedWorldNameRow;

enum EndOfWorldScreenConstants {
    EOW_LETTER_SLOTS = 100,
    EOW_LETTER_INITIAL_Y_STEP = 10,
    EOW_LETTER_INITIAL_Y_BASE = 200,
    EOW_TEXTURE_BANK_EARLY_WORLD = 1,
    EOW_TEXTURE_BANK_LATE_WORLD = 0xE,
    EOW_EARLY_WORLD_LIMIT = 4,
    EOW_MODEL_BANK_ID = 0x46,
    EOW_BACKDROP_SPRITE_SIZE = 0x70,
    EOW_BACKDROP_SCALE = 0x400,
    EOW_WORLD_RECORD_STRIDE = 0x18,
    EOW_DRAW_DISTANCE = 10000,
    EOW_MUSIC_TRACK_ID = 0x3B,
    EOW_PACED_MSG_ACTIVE = 2,
    EOW_PACED_MSG_EXIT = 3,
    EOW_SPARKLE_START_FRAME = 0x47,
    EOW_SPARKLE_Y_RANGE = 0xB,
    EOW_SPARKLE_Y_BASE = 0x41,
    EOW_SPARKLE_COUNT_RANGE = 3,
    EOW_SPARKLE_COUNT_BASE = 3,
    EOW_SPARKLE_PRESET = 6,
    EOW_BANNER_DELAY_FRAMES = 20,
    EOW_BANNER_Y = 0x46,
    EOW_COMPLETE_Y = 0xB4,
    EOW_BONUS_Y = 0xD2,
    EOW_BONUS_UNLOCKED_OFFSET = 3,
    EOW_BONUS_LOCKED_OFFSET = 9,
    EOW_MAX_BOUNCES = 2,
    EOW_AUTO_EXIT_FRAMES = 500,
    EOW_EXIT_LOCK_VALUE = 200,
    EOW_COLOR_MAX = 0xFF,
    EOW_TITLEBOX_FRONT_ALPHA = 0x80,
    EOW_LIGHT_GREEN = 0x82,
    EOW_AMBIENT_RED = 100,
    EOW_AMBIENT_GB = 80
};

/* func_80135568: controller_update_playback.
 * Drives controller state from a recorded input buffer (D_801EC768) during demo
 * or attract-mode playback, falling back to live input (func_8013407C) outside
 * gameplay states (when func_80124FF8 returns 0). Allows A/B/Start on the
 * selected controller to abort playback (except on level 0x27), advances
 * timestamped button events, ends playback 20 frames after the -1 sentinel,
 * and updates the 400-byte per-controller button/stick state tables.
 *
 * Globals (N64 symbol renaming is unsupported; descriptive names recorded here):
 * - D_801EC768: heap pointer to the loaded recorded-input buffer.
 * - D_801FB260: u16 playback cursor into D_801EC768 (alternating frame/buttons).
 * - D_801EC772: next recorded event state-frame (-1 at end of recording).
 * - D_801EC774: post-sentinel countdown timer before exiting playback.
 * - D_801FA9E8: last state frame (D_802004E0) processed by playback.
 * - D_801FA9E4: currently active replayed button bitmask.
 * - D_801EC7F0: input record/playback mode (0 = live, 1 = record, 2 = playback).
 * - D_801EC749: controller 1 connected flag; D_80202218: selected controller.
 * - D_801EC74C[14]: N64 button bitmask table (A, B, Z, Start, L, R, D-L/R/U/D, C-L/R/U/D);
 *   D_801EC74E = B (0x4000), D_801EC752 = Start (0x1000).
 * - D_801FB280[]: raw OSContPad samples (6-byte stride).
 * - Per-controller 400-byte state table fields (base D_801FAA90):
 *   +0x00 D_801FAA90 / +0x02 D_801FAA92: stick X / Y (synthesized +/-79 from D-pad).
 *   +0x04 D_801FAA94: stick magnitude; +0x08..+0x14 D_801FAA98..A4: 4-frame angle history.
 *   +0x1A D_801FAAAA[14]: button held flags (indices 6..9 = D-Left/Right/Up/Down at D_801FAAB0..B3).
 *   +0x28 D_801FAAB8[14]: previous-frame held flags; +0x36 D_801FAAC6[14]: newly pressed flags.
 *   +0x60 D_801FAAF0[14]: button suppress/latch flags.
 *   +0x70 D_801FAB00[14]: consecutive frames in current button state.
 *   +0xA8 D_801FAB38[14]: duration of previous button state.
 *   +0xE0 D_801FAB70[14]: frames elapsed since last button press.
 */
enum ControllerPlaybackConstants {
    CONTROLLER_BUTTON_COUNT = 14,
    CONTROLLER_STATE_STRIDE = 400,
    CONTROLLER_DPAD_STICK_EXTENT = 0x4F,
    DEMO_PLAYBACK_START_FRAME = 9,
    DEMO_PLAYBACK_END_SENTINEL = -1,
    DEMO_PLAYBACK_END_DELAY_FRAMES = 0x14,
    DEMO_UNSKIPPABLE_LEVEL_ID = 0x27,
    DEMO_TRANSITION_UNSKIPPABLE_END = 2,
    DEMO_TRANSITION_EXIT_TO_MENU = 0xF
};

#endif /* STRUCTS_H */
/* Audio synthesizer initialization parameters, size 0x24. */
typedef struct AudioSynthConfig {
    /* 0x00 */ s32 maxVVoices;
    /* 0x04 */ s32 maxPVoices;
    /* 0x08 */ s32 maxUpdates;
    /* 0x0C */ s32 maxFXbusses;
    /* 0x10 */ s32 outputRate;
    /* 0x14 */ u32 *heap;
    /* 0x18 */ s32 initOsc;
    /* 0x1C */ u8 fxType;
    /* 0x1D */ u8 pad1D[3];
    /* 0x20 */ s32 *params;
} AudioSynthConfig;
/* func_80125040: animate_title_camera.
 * D_801E762C is the orbit phase in radians, initially zero.
 * D_801F83E4/E8/EC hold eye XYZ; D_801F83F0/F4/F8 hold target XYZ.
 * Each group is a Vec3F (0x0C bytes); the eye X word retains its s32
 * declaration for bitwise access.
 * Pool values: D_801015A8 = height frequency 3, D_801015AC = height
 * amplitude 300, D_801015B0 = radius frequency 2.4 (f64),
 * D_801015B8 = shared amplitude/height offset 400,
 * D_801015BC = base radius 1000, D_801015C0 = phase step 0.005 (f64).
 * func_801C6000 computes sine; func_801490AC rotates a Vec3F about Y.
 * func_80162EAC sets camera position and target/velocity pointers,
 * saving the previous camera state. D_801ED3C4 begins the zero vector.
 */
enum TitleCameraConstants {
    TITLE_CAMERA_MODE = 5,
    TITLE_CAMERA_FLAGS_NONE = 0
};
/* func_801A8EF8: effect_unlink_and_free.
 * ListNode801A8E54 is the existing effect prefix: next/prev at 0/4,
 * embedded ObjectNode at +8, and the byte-sized effect type at +0x161.
 * D_8029F394 counts linked effects. D_801F19B8 counts types 11/25
 * (bubble2.ndo / gball.ndo); D_801F19BC counts types 12/28
 * (bubble1.ndo / spiderbomb.ndo). All three counts start at zero.
 * D_801F0344 is the sprite-count field of the 0xC0-byte definition table
 * at D_801F0330; entry zero contains two sprites.
 * func_8014ACB4 unlinks a world sprite; func_80178704 stops tracked audio;
 * func_801625F0 releases selected object allocations; func_80141720 frees
 * a heap allocation and clears the supplied address.
 * The table view has s16 count at +0 and 0xBE bytes of padding.
 * Retain its existing declaration and direct indexing for matching.
 */

enum EffectRemovalConstants {
    EFFECT_TYPE_BUBBLE2 = 11,
    EFFECT_TYPE_GBALL = 25,
    EFFECT_TYPE_BUBBLE1 = 12,
    EFFECT_TYPE_SPIDER_BOMB = 28,
    EFFECT_SPRITES_OFFSET = 0xEC,
    EFFECT_SPRITE_BYTES = 0x38,
    EFFECT_FREE_ALL_COMPONENTS = -1
};
/* func_801335A8: update_save_slot_and_reload.
 * The slots are LevelSaveSlot records (save_data.h). SaveSlotByte / SaveSlotWord
 * in src/18020_33940.c are views of one u8 / s32 field with the slot's 0x1C-byte
 * stride: they keep the separate symbols the matching code needs for its fields.
 * D_801EAB24: selected slot. D_801EAA44/45/46: saved initials, copied
 * from D_801FA9A8/A9/AA. D_801EAA50: saved score; D_801EAA54: saved lives.
 * D_80290188: score; D_8029018C: collected Garibs; D_80290193: low byte
 * of the big-endian lives word at D_80290190.
 * func_80132CAC queues SAVE_OP_READ_SLOTS and waits; func_80132DA8 queues
 * operation 11 (no data transfer) and waits for the queue to drain.
 * Thus the slot update is followed by an EEPROM read, not a write.
 * The volatile byte parameter is unused; retain its ABI stack store.
 */
/* func_801AE0CC: actor_status_timer_expired. Stun expiry restarts the
 * actor's two PositionalSound records except for type 32; shrink expiry
 * calls func_80195D50 (actor_begin_death); transformation needs no callback.
 * func_801785E0 starts a tracked sound, replacing its previous handle.
 * D_802999B0 is the first record; D_802999B8 holds saved restart volume
 * (func_80178704 copies volume there when stopping). D_802999C0/C2/C4
 * alias pitch, sound ID and position. These BSS aliases repeat per actor
 * at ACTOR_INSTANCE_STRIDE and per sound at POSITIONAL_SOUND_STRIDE.
 * Raw address casts preserve the existing aliasing and load order.
 * N64 symbol renaming is unsupported; names are documented here. */
enum ActorStatusTimerIndex {
    ACTOR_TIMER_STUN = 0,
    ACTOR_TIMER_SHRINK = 1,
    ACTOR_TIMER_TRANSFORM = 2,
    ACTOR_STUN_NO_SOUND_RESTART_TYPE = 0x20
};
/* Peripheral interface: PI domain 2 timing registers (KSEG1) and the 64DD base address. */
#ifndef PI_BSD_DOM2_LAT_REG
#define PI_BSD_DOM2_LAT_REG 0xA4600024
#define PI_BSD_DOM2_PWD_REG 0xA4600028
#define PI_BSD_DOM2_PGS_REG 0xA460002C
#define PI_BSD_DOM2_RLS_REG 0xA4600030
#endif
#define LEO_DISK_BASE_ADDRESS 0xA5000000
#define DEVICE_TYPE_64DD 2
/* Motion fields shared by moving objects: flags word, velocity XYZ and the cached
 * speed (length of the velocity). func_80160830 clamps the horizontal speed. */
enum ObjectMotionOffsets {
    OBJECT_MOTION_FLAGS_OFFSET = 0x28,
    OBJECT_MOTION_VELOCITY_X_OFFSET = 0x58,
    OBJECT_MOTION_VELOCITY_Y_OFFSET = 0x5C,
    OBJECT_MOTION_VELOCITY_Z_OFFSET = 0x60,
    OBJECT_MOTION_SPEED_OFFSET = 0x74
};
#define OBJECT_MOTION_NO_SPEED_CLAMP 0x1000000

/* func_8017C17C: platform_update_rotation, integrating angular velocity,
 * target seeking (including ball/player tracking and path-oriented banking),
 * pendulum trails/restoring torque, angle-limit clamping, spin-to-move and
 * spin-to-spin platform links, and positional rotation audio.
 * D_8029F978 is the ball object, D_802902D8 the player object, D_802904D4 the
 * platform list sentinel, and D_8028F914/918/91C the camera position.
 * func_80147460 is atan2, func_801496C8 wraps an angle, func_8014944C returns
 * unsigned angular distance, func_801494CC returns signed angular difference,
 * func_8014915C rotates a Vec3F around an axis, func_80149568 normalizes a
 * Vec3F, func_80148D0C adds a scaled Vec3F, func_801BA700 appends a trail
 * segment, func_8017DBD8 finds the next platform by tag, and
 * func_801785E0/80178760/80178704/80178134 manage positional audio.
 * N64 symbol renaming is unsupported; descriptive names are recorded here. */
enum PlatformAngularMotionFlags {
    PLATFORM_FLAG_CLAMP_ANGULAR_SPEED = 0x10,
    PLATFORM_FLAG_TRACK_PLAYER_YAW = 0x400,
    PLATFORM_FLAG_TRACK_BALL_YAW = 0x800,
    PLATFORM_FLAG_BANK_ALONG_PATH = 0x2000
};

enum PlatformAngularMotionField {
    PLATFORM_TRAIL = 0x58,
    PLATFORM_TRAIL_INNER_SCALE = 0x578,
    PLATFORM_PATH_NEXT_WAYPOINT = 0x57,
    PLATFORM_ROTATION_SNAP_DIVISIONS = 0x08,
    PLATFORM_ROTATION_LIMIT_FLAGS = 0x10,
    PLATFORM_ROTATION_LIMIT_UPPER = 1,
    PLATFORM_ROTATION_LIMIT_LOWER = 2,
    PLATFORM_ROTATION_PENDULUM_DIVISOR = 0x18,
    PLATFORM_ROTATION_RESTORE_STEP = 0x1C,
    PLATFORM_ROTATION_STEP_COUNTER = 0x20,
    PLATFORM_ROTATION_MAX_DEVIATION = 0x24,
    PLATFORM_ROTATION_MAX_ANGULAR_SPEED = 0x2C,
    PLATFORM_ROTATION_BASE_ANGLE = 0x30,
    PLATFORM_ROTATION_BANK_SCALE = 0x34,
    PLATFORM_ROTATION_ANGULAR_VELOCITY = 0x50,
    PLATFORM_ROTATION_ANGULAR_VELOCITY_Z = 0x58,
    PLATFORM_ROTATION_TARGET_YAW = 0x60,
    PLATFORM_ROTATION_TARGET_ROLL = 0x64,
    PLATFORM_ROTATION_SEEK_TARGET = 0x68,
    PLATFORM_ROTATION_SPIN_DAMPING = 0x6C,
    PLATFORM_ROTATION_SOUND_HANDLE = 0x74,
    PLATFORM_ROTATION_SOUND_VOLUME = 0x78,
    PLATFORM_ROTATION_MOVE_SOUND_VOLUME = 0x82,
    PLATFORM_ROTATION_MOVE_SOUND_PITCH = 0x84,
    PLATFORM_ROTATION_MOVE_SOUND_ID = 0x86,
    PLATFORM_ROTATION_STOP_SOUND_VOLUME = 0x92,
    PLATFORM_ROTATION_STOP_SOUND_PITCH = 0x94,
    PLATFORM_ROTATION_STOP_SOUND_ID = 0x96,
    OBJECT_POSITION_Z_OFFSET = 0x3C
};

/* func_80150EA4: load_object_bank. Selects a ROM model bank by ID, allocates
 * and unpacks it (func_80141C2C / func_8013FCDC / func_80141DD8), claims a
 * free slot in D_8028F82C (up to MODEL_BANK_MAX_SLOTS), relocates every entry's
 * model header, root model tree (func_8015092C), and optional animation table
 * (func_80150110), and initializes fade-plane models (func_80120A90) when
 * loading the common bank (MODEL_BANK_COMMON).
 * D_802846F8 receives the bank name; D_8025D578 is the diagnostic buffer.
 * D_8028F82C/830/834 alias the SceneModelBank allocation, count, and items. */
enum ModelBankConstants {
    MODEL_BANK_COMMON = 0,
    MODEL_BANK_MAX_SLOTS = 5
};

typedef struct ModelBankEntryHeader {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ s32 rootModel;
    /* 0x10 */ u8 pad10[0x08];
    /* 0x18 */ s32 animation;
} ModelBankEntryHeader; /* accessed prefix size = 0x1C */

typedef struct ModelBankAnimationHeader {
    /* 0x00 */ u8 pad00[0x48];
    /* 0x48 */ s32 keys;
} ModelBankAnimationHeader; /* accessed prefix size = 0x4C */
/* func_8015E0A0: physics_update_collision_and_gravity.
 * Runs sphere-to-world (func_80157708) and sphere-to-object (func_80155D54)
 * collision, rolling updates (func_801B2B58 / func_801B31A8), player/ball
 * carrier propagation, gravity, and slope sliding against contact planes.
 * D_802902D8: player object; D_8029F978: ball object; D_8029F9A4: ball carrier.
 * D_801ED680: gravity; D_801EEB60: gravity active flag; D_801EEB64: slope mode.
 * D_801ED758 / D_801ED75C: surface friction/traction fields in the 28-byte
 * material table; D_801ED68C: world-space collision sphere offsets;
 * D_801FAA94: controller stick magnitude (400-byte stride, D_80202218 index).
 */
typedef struct PhysicsVec3F {
    f32 x;
    f32 y;
    f32 z;
} PhysicsVec3F;

typedef struct PhysicsCarrierView {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ PhysicsVec3F pos;
} PhysicsCarrierView;

typedef struct PhysicsContactPlane {
    /* 0x00 */ PhysicsVec3F normal;
    /* 0x0C */ f32 dist;
    /* 0x10 */ u8 pad10[0x64];
    /* 0x74 */ u8 material;
} PhysicsContactPlane;

typedef struct PhysicsContactState {
    /* 0x000 */ PhysicsContactPlane *plane[4];
    /* 0x010 */ PhysicsVec3F hit[4];
    /* 0x040 */ u8 sphereIndex[4];
    /* 0x044 */ u8 pad44[0x10];
    /* 0x054 */ u8 kind[4];
    /* 0x058 */ u8 pad58[0x120];
    /* 0x178 */ void *curPlatform;
    /* 0x17C */ void *prevPlatform;
    /* 0x180 */ void *curSurfaceObject;
    /* 0x184 */ void *prevSurfaceObject;
    /* 0x188 */ u8 pad188[2];
    /* 0x18A */ u8 hasGroundContact;
    /* 0x18B */ u8 sphereCount;
} PhysicsContactState;

typedef struct PhysicsObjectParams {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ f32 minSlideSpeed;
    /* 0x14 */ f32 slopeGrip;
    /* 0x18 */ u8 pad18[8];
    /* 0x20 */ f32 bounceFactor;
} PhysicsObjectParams;

typedef struct PhysicsObjectExtra {
    /* 0x00 */ u8 pad0[9];
    /* 0x09 */ u8 slowFall;
    /* 0x0A */ u8 padA;
    /* 0x0B */ u8 contactCleared;
    /* 0x0C */ u8 padC[0xC];
    /* 0x18 */ f32 radiusScale;
} PhysicsObjectExtra;

typedef struct PhysicsObjectView {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ s16 type;
    /* 0x22 */ u8 pad22[6];
    /* 0x28 */ s32 flags;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ f32 radius;
    /* 0x34 */ PhysicsVec3F pos;
    /* 0x40 */ PhysicsVec3F prevPos;
    /* 0x4C */ u8 pad4C[0xC];
    /* 0x58 */ PhysicsVec3F vel;
    /* 0x64 */ u8 pad64[0x10];
    /* 0x74 */ f32 speed;
    /* 0x78 */ u8 pad78[0x58];
    /* 0xD0 */ PhysicsObjectParams *params;
    /* 0xD4 */ PhysicsObjectExtra *extra;
    /* 0xD8 */ PhysicsContactState *contacts;
} PhysicsObjectView;

enum PhysicsUpdateConstants {
    PHYSICS_FLAG_GRAVITY = 0x1,
    PHYSICS_FLAG_OBJECT_COLLISION = 0x8,
    PHYSICS_FLAG_TERRAIN_COLLISION = 0x10,
    PHYSICS_FLAG_ANY_COLLISION = 0x18,
    PHYSICS_FLAG_ROLLING = 0x20,
    PHYSICS_FLAG_REDUCED_GRAVITY = 0x40,
    PHYSICS_FLAG_NO_SLOW_FALL = 0x200000,
    PHYSICS_FLAG_HIGH_TERMINAL_VEL = 0x1000000,
    PHYSICS_OBJECT_TYPE_BALL = 2,
    PHYSICS_CONTACT_PLANE_SLOTS = 4,
    PHYSICS_BALL_STATUS_CARRIED = 5,
    PHYSICS_PLAYER_ACTION_RIDE_BALL = 3,
    PHYSICS_PLAYER_ACTION_DRIBBLE = 0xB,
    PHYSICS_PLAYER_ACTION_SPECIAL_BALL = 0x14,
    PHYSICS_PLAYER_ACTION_SLIDE = 0x23,
    PHYSICS_CONTROLLER_RECORD_STRIDE = 400,
    PHYSICS_SURFACE_ENTRY_STRIDE = 28,
    PHYSICS_SURFACE_FLOAT_STRIDE = 7
};
/* func_80182090: level_load_and_parse.
 * Resets per-level counters and ball checkpoint state (D_801EFD00), loads the
 * binary level script via func_80152498, dispatches token records until 0x7D00,
 * and finalizes static geometry (D_8026A148), platforms (D_802904D4), ground
 * raycasts (D_80299290, D_802AA918), and Garib group bounds (D_802993A0/A4).
 * func_801831FC reads bytes from the level stream; func_8015B524 raycasts down
 * to the nearest floor; func_801570AC builds world collision triangles.
 */
enum LevelLoadConstants {
    LEVEL_TOKEN_DUMMY_PLATFORM = 0x5D,
    LEVEL_TOKEN_PLATFORM = 0x62,
    LEVEL_TOKEN_SPAWN_ACTOR = 0x83,
    LEVEL_TOKEN_INIT_ACTOR_PATH = 0x84,
    LEVEL_TOKEN_SCRIPT_9A = 0x9A,
    LEVEL_TOKEN_SCRIPT_9B = 0x9B,
    LEVEL_TOKEN_SCRIPT_9C = 0x9C,
    LEVEL_TOKEN_ACTOR_DATA = 0xA1,
    LEVEL_TOKEN_EFFECT = 0xA2,
    LEVEL_TOKEN_EFFECT_PHASE = 0xA3,
    LEVEL_TOKEN_ACTOR_FLAG = 0xBA,
    LEVEL_TOKEN_END = 0x7D00,
    LEVEL_GAME_STATE_ABORT = 13,
    LEVEL_EFFECT_BYTES = 0x70,
    LEVEL_PLATFORM_BYTES = 0x180,
    LEVEL_PLATFORM_OBJECT_TYPE = 59,
    LEVEL_GEOMETRY_SOLID_TYPE = 60,
    LEVEL_GEOMETRY_VISUAL_TYPE = 62,
    LEVEL_TRIANGLE_RECORD_BYTES = 120,
    LEVEL_PLATFORM_STATIC_FLAG = 0x20000,
    LEVEL_PLATFORM_DUMMY_FLAG = 0x80,
    LEVEL_PLATFORM_INIT_FLAGS = 0x10004,
    LEVEL_ACTOR_RECORD_STRIDE = 0x300,
    LEVEL_ACTOR_FLOAT_STRIDE = 0xC0,
    LEVEL_CLEAR_TABLE_ENTRIES = 10,
    LEVEL_CLEAR_TABLE_ENTRY_BYTES = 16
};

/* func_8011AB30: shooting_gallery_update (level 19 / 0x13 bonus stage).
 * Controls the player-mounted cannon turret, counts knocked-down targets across
 * three rows of 10 (platform IDs 70..79, 90..99, 110..119), drives the turret
 * rotation sound (D_8029014C) and rumble (D_801F7D78), fires projectiles with
 * recoil and muzzle particles, and ramps the three target-row tracks (60, 157, 129).
 */
enum ShootingGalleryConstants {
    SHOOTING_GALLERY_CANNON_ID = 1,
    SHOOTING_GALLERY_LEFT_WHEEL_ID = 2,
    SHOOTING_GALLERY_RIGHT_WHEEL_ID = 3,
    SHOOTING_GALLERY_ROW1_TRACK_ID = 60,
    SHOOTING_GALLERY_ROW3_TRACK_ID = 129,
    SHOOTING_GALLERY_ROW2_TRACK_ID = 157,
    SHOOTING_GALLERY_ROW1_FIRST_TARGET = 70,
    SHOOTING_GALLERY_ROW1_END_TARGET = 80,
    SHOOTING_GALLERY_ROW2_FIRST_TARGET = 90,
    SHOOTING_GALLERY_ROW2_END_TARGET = 100,
    SHOOTING_GALLERY_ROW3_FIRST_TARGET = 110,
    SHOOTING_GALLERY_ROW3_END_TARGET = 120,
    SHOOTING_GALLERY_TOTAL_TARGETS = 30,
    SHOOTING_GALLERY_WIN_DELAY_FRAMES = 60,
    SHOOTING_GALLERY_PLAYER_ACTION = 0x29,
    SHOOTING_GALLERY_MAX_PROJECTILES = 8,
    SHOOTING_GALLERY_PROJECTILE_TYPE = 0x16,
    SHOOTING_GALLERY_MUZZLE_PARTICLE = 15,
    SHOOTING_GALLERY_SMOKE_PARTICLE = 16,
    SHOOTING_GALLERY_SPARK_PARTICLE = 19
};
/* func_8018FF50: evaluate_trigger_condition.
 * Evaluates a single level-trigger condition node (called from func_8018FE98).
 * Condition node layout: +0x08 u8 type, +0x09 u8 target/tag/varId,
 * +0x0A s16 param/mode/value, +0x0C f32* volumeData (box/cylinder/sphere).
 * Non-platform conditions check power-up timers (D_8029019C), collectibles
 * (D_80299290 / D_802993A4), level script variables (D_80299508[0..99],
 * D_80299378 = D_80299508 - 100), actor active flags (D_80299968 / D_8029970A),
 * and player (D_8029030C), ball (D_8029F9AC), or camera (D_8028F914) zones.
 * Platform conditions iterate platforms in D_802904D4 matching tag via
 * func_8017DBD8 and test path/track state, contact (cur/prev platform at
 * +0x178/+0x17C, cur/prev surface at +0x180/+0x184), or axis limits.
 */
enum TriggerConditionType {
    TRIGGER_COND_PATH_STOPPED_AT = 0,
    TRIGGER_COND_ROT_TRACK_STOPPED = 1,
    TRIGGER_COND_SCALE_TRACK_ACTIVE = 2,
    TRIGGER_COND_PATH_AT_WAYPOINT = 3,
    TRIGGER_COND_ROT_TRACK_AT = 4,
    TRIGGER_COND_SCALE_TRACK_AT = 5,
    TRIGGER_COND_PLAYER_ON_PLATFORM = 6,
    TRIGGER_COND_PLAYER_PLATFORM_EDGE = 7,
    TRIGGER_COND_BALL_ON_PLATFORM = 8,
    TRIGGER_COND_BALL_PLATFORM_EDGE = 9,
    TRIGGER_COND_ACTOR_ON_PLATFORM = 10,
    TRIGGER_COND_ACTOR_PLATFORM_EDGE = 11,
    TRIGGER_COND_PLAYER_ON_SURFACE = 12,
    TRIGGER_COND_PLAYER_SURFACE_EDGE = 13,
    TRIGGER_COND_BALL_ON_SURFACE = 14,
    TRIGGER_COND_BALL_SURFACE_EDGE = 15,
    TRIGGER_COND_ACTOR_ON_SURFACE = 16,
    TRIGGER_COND_ACTOR_SURFACE_EDGE = 17,
    TRIGGER_COND_VAR_EQ = 0x12,
    TRIGGER_COND_VAR_NE = 19,
    TRIGGER_COND_VAR_GT = 20,
    TRIGGER_COND_VAR_LT = 21,
    TRIGGER_COND_AXIS_AT_LIMIT = 22,
    TRIGGER_COND_AXIS_REACHED_LIMIT = 23,
    TRIGGER_COND_ACTOR_ALIVE = 0x18,
    TRIGGER_COND_ALWAYS_TRUE = 0x19,
    TRIGGER_COND_PLAYER_IN_BOX = 0x1A,
    TRIGGER_COND_PLAYER_IN_SPHERE = 27,
    TRIGGER_COND_BALL_IN_BOX = 28,
    TRIGGER_COND_BALL_IN_SPHERE = 29,
    TRIGGER_COND_CAMERA_IN_BOX = 30,
    TRIGGER_COND_CAMERA_IN_SPHERE = 31,
    TRIGGER_COND_PLAYER_IN_CYLINDER = 0x20,
    TRIGGER_COND_ALWAYS_FALSE = 33,
    TRIGGER_COND_GARIB_CHECK = 0x22,
    TRIGGER_COND_POWERUP_ACTIVE = 0x23
};

enum TriggerConditionConstants {
    TRIGGER_COND_VAR_COUNT = 100,
    TRIGGER_COND_GROUND_POUND_MAX_FRAMES = 3,
    TRIGGER_COND_PLAYER_ACTION_GROUND_POUND = 19,
    TRIGGER_COND_CONTACT_CUR_PLATFORM = 0x178,
    TRIGGER_COND_CONTACT_PREV_PLATFORM = 0x17C,
    TRIGGER_COND_CONTACT_CUR_SURFACE = 0x180,
    TRIGGER_COND_CONTACT_PREV_SURFACE = 0x184
};
/* func_80123514: process_gameplay_transitions.
 * Updates active warp/goal-door countdowns (D_801E7466, D_801E7460, D_801E7620)
 * and level elapsed ticks (D_80290198), dispatches special-level hooks (hub 8,
 * cutscenes 46/47), and when the screen transition closes (func_8014D5E0) with
 * GAME_TRANSITION_PENDING set, executes the requested transition (D_801E7541),
 * saving ball checkpoint state (D_801EFD00/D_801EFCD8) and handling time-trial
 * record updates and full level teardown.
 */
enum GameplayTransitionConstants {
    GAMEPLAY_WARP_ANIM_ID = 3,
    GAMEPLAY_WARP_ANIM_DONE_STATE = 4,
    GAMEPLAY_WARP_ACTION_RISE = 0x29,
    GAMEPLAY_GOAL_DOOR_PLAYER_ACTION = 3,
    GAMEPLAY_GOAL_DOOR_CHIME_1 = 40,
    GAMEPLAY_GOAL_DOOR_CHIME_2 = 20,
    GAMEPLAY_SFX_WARP_OUT = 0xA5,
    GAMEPLAY_SFX_GOAL_CHIME = 0x14E,
    GAMEPLAY_FANFARE_TIME_TRIAL_RECORD = 0x19,
    GAMEPLAY_BUTTON_A_MASK = 0x8000,
    GAMEPLAY_LEVEL_CUTSCENE_46 = 46,
    GAMEPLAY_LEVEL_CUTSCENE_47 = 47,
    GAMEPLAY_LEVEL_WORLD_HUB = 0x2A,
    GAMEPLAY_LEVEL_LANGUAGE_SELECT = 0x2B,
    GAMEPLAY_LEVEL_MENU_MIN = 0x2C,
    GAMEPLAY_LEVEL_ALL_OPEN_HUB = 7,
    GAMEPLAY_LEVEL_INTRO_DEMO = 9,
    GAMEPLAY_LEVEL_PLAYBACK_TRIGGER = 0x26,
    GAMEPLAY_CHEAT_ALL_WORLDS_MASK = 0x01000000,
    GAMEPLAY_SAVE_MODE_TIME_TRIAL = 2,
    GAMEPLAY_WORLD_LEVEL_TABLE_STRIDE = 0x18,
    GAMEPLAY_LEVEL_INFO_STRIDE = 0x38,
    GAMEPLAY_TIME_RECORD_STRIDE = 6,
    GAMEPLAY_TRANSITION_WORLD_COMPLETE = 3,
    GAMEPLAY_TRANSITION_EXIT_MENU = 0xF,
    GAMEPLAY_TRANSITION_RELOAD_LEVEL = 0x18,
    GAMEPLAY_TRANSITION_CLOSED_EXTENT = 0x12C
};
/* func_8013407C: controller_poll_live_input.
 * Updates per-controller stick/button state from raw OSContPad samples (D_801FB280),
 * shifts 2-frame stick magnitude history (D_801FAC18/1C) and 4-frame angle history
 * (D_801FAA98..A4), enforces input lockout (Start-only) during cutscenes/overlays,
 * applies +/-79 clamp and deadzone (6, offset 5), synthesizes D-pad stick input
 * when analog stick is centered, computes magnitude (func_801C4030) and wrapped
 * angle (func_80147460 + func_801496C8), and records button transitions to
 * D_801FB260 when D_801EC7F0 == 1.
 */
enum ControllerLivePollConstants {
    CONTROLLER_BUTTON_START_INDEX = 3,
    CONTROLLER_STICK_CLAMP = 79,
    CONTROLLER_STICK_DEADZONE = 6,
    CONTROLLER_STICK_DEADZONE_OFFSET = 5,
    CONTROLLER_RECORD_MODE = 1,
    DEMO_RECORD_START_FRAME = 10
};
/* func_80112F80: title_menu_update.
 * Updates and draws the four title-menu options (slide-in X/alpha, pulsing
 * selected label, 3D wave model bob/spin in D_80269F40[0..3], idle glove
 * animation on D_80269F50), drives the orbiting title camera (func_8012519C),
 * handles the 600-frame attract-demo timeout (D_801E6628), delegates navigation
 * to func_801100B8 once the opening curtain finishes (D_801E64C8), and starts
 * the closing transition on confirm/cancel.
 */
enum TitleMenuUpdateConstants {
    TITLE_MENU_OPTION_COUNT = 4,
    TITLE_MENU_SPRITE_COUNT = 6,
    TITLE_MENU_IDLE_COMMAND = 6,
    TITLE_MENU_IDLE_TIMEOUT = 0x258,
    TITLE_MENU_ALPHA_SELECTED = 0xFF,
    TITLE_MENU_ALPHA_UNSELECTED = 0xB4,
    TITLE_MENU_ALPHA_STEP = 2,
    TITLE_MENU_LABEL_Y_0 = 0x35,
    TITLE_MENU_LABEL_Y_1 = 0x62,
    TITLE_MENU_LABEL_Y_2 = 0x8F,
    TITLE_MENU_LABEL_Y_3 = 0xBC,
    TITLE_MENU_GLOVE_IDLE_CHANCE = 0xC8,
    TITLE_MENU_GLOVE_IDLE_ROLL = 0xF,
    TITLE_MENU_GLOVE_ANIM_IDLE = 2,
    TITLE_MENU_GLOVE_ANIM_FIDGET = 3,
    TITLE_MENU_GLOVE_ANIM_EXIT = 1,
    TITLE_MENU_DEMO_DEST = 7,
    TITLE_MENU_DEMO_SLOT = 6,
    TITLE_MENU_CHEAT_HIDDEN_OPTION = 0x800000
};
/* func_801A29F0: actor_type9_update (Cross-Stitch / boss-encounter behavior).
 * Dispatched from actor update for actor type 9 across boss and cutscene
 * levels (13, 14, 18/0x12, 23, 28/0x1C, 33, 38/0x26, 39/0x27, 40/0x28).
 * Handles first-frame level setup (D_802004E0 == 0), mirrored particle trails
 * (func_801A5EDC), level 0x28 flight/crash sequence with cameo triggers
 * (D_801F9628) and countdown (D_8029F13C), animation-4 fading tracked sound,
 * animation-6 death flash/cleanup (func_8014D61C, func_80195D50), level 0x12
 * pendulum sway on D_801FA840, animation-2 jet flames and platform-1 descent
 * (func_8017DBA0, func_80179F5C), and animation-0 projectile/lightning attacks
 * (func_801A9054, func_80189E78).
 * Raw/struct-wrapper field accesses and pool externs preserve matched codegen.
 */
enum Type9BehaviorConstants {
    TYPE9_LEVEL_13 = 13,
    TYPE9_LEVEL_14 = 14,
    TYPE9_LEVEL_18 = 0x12,
    TYPE9_LEVEL_23 = 23,
    TYPE9_LEVEL_28 = 0x1C,
    TYPE9_LEVEL_33 = 33,
    TYPE9_LEVEL_38 = 0x26,
    TYPE9_LEVEL_39 = 0x27,
    TYPE9_LEVEL_40 = 0x28,
    TYPE9_TARGET_OBJECT_TYPE = 0x3F,
    TYPE9_ANIM_ATTACK = 0,
    TYPE9_ANIM_JET = 2,
    TYPE9_ANIM_FLY = 4,
    TYPE9_ANIM_DEATH = 6,
    TYPE9_ANIM_DEATH_FINISH_STATE = 7,
    TYPE9_SOUND_SPARK_A = 0x1B,
    TYPE9_SOUND_FLY_LOOP = 0x1C,
    TYPE9_SOUND_JET_LOOP = 0x24,
    TYPE9_SOUND_LIGHTNING_LOOP = 0x3E,
    TYPE9_SOUND_SWAY_IMPACT = 0x68,
    TYPE9_SOUND_COUNTDOWN_A = 0x94,
    TYPE9_SOUND_COUNTDOWN_B = 0x95,
    TYPE9_SOUND_DEATH_HIT = 0xA5,
    TYPE9_SOUND_ATTACK_CUE = 0xAF,
    TYPE9_SOUND_DEATH_START = 0xB0,
    TYPE9_SOUND_LEVEL38_LOOP = 0x138,
    TYPE9_SOUND_FALL_LOOP = 0x147,
    TYPE9_SOUND_CRASH_THUD = 0x152,
    TYPE9_SOUND_CRASH_LOOP = 0x153,
    TYPE9_SOUND_ENGINE_LOOP = 0x156,
    TYPE9_ACTOR_FLAG_NO_SPIN = 0x100,
    TYPE9_ACTOR_FLAG_FREEZE_MOTION = 0x4000,
    TYPE9_ACTOR_PREV_POS_Y = 0x44,
    TYPE9_ACTOR_VELOCITY_Y = 0x5C,
    TYPE9_ACTOR_VELOCITY_Z = 0x60,
    TYPE9_ACTOR_MESH_REF = 0xC8,
    TYPE9_ACTOR_UNK282 = 0x282,
    TYPE9_ACTOR_UNK284 = 0x284,
    TYPE9_ACTOR_SECOND_SOUND_VOLUME = 0x2E8,
    TYPE9_ANIM_CURRENT_OFFSET = 2,
    TYPE9_ANIM_SPEED_OFFSET = 0x0C,
    TYPE9_EFFECT_FLAGS_OFFSET = 0x30,
    TYPE9_EFFECT_POS_Z_OFFSET = 0x44,
    TYPE9_EFFECT_VEL_Y_OFFSET = 0x64,
    TYPE9_EFFECT_VEL_Z_OFFSET = 0x68,
    TYPE9_EFFECT_TARGET_TYPE_A = 0x162,
    TYPE9_EFFECT_TARGET_TYPE_B = 0x163,
    TYPE9_EFFECT_TARGET_ACTOR = 0x164,
    TYPE9_PLATFORM_HEIGHT_OFFSET = 0x140
};
/* func_80171924: player_update.
 * Main per-frame player update called from the gameplay loop in src/18020_3AD70.c.
 * Drives AoE/shockwave timers (func_80176E9C), banking/roll during turns
 * (func_80160228), fall-height damage and death triggers (func_801743A8,
 * func_80174058), tracked positional sound slots at D_8029014C (stride 0x1C),
 * gravity/physics parameter overrides, water/surface and ride-object timers,
 * scale animation (D_802900E8), death recovery countdown (D_8028FBF6 ->
 * func_8017479C), invulnerability blink (D_802901DC), fall counter (D_8028FC00),
 * powerup timers (func_801AE204), frog transformation (func_80176758),
 * spring/platform/action/effect sub-updates (func_801735E8, func_801748D0,
 * func_8016A058, func_80174D4C), action lock countdown (D_8028FBD8), surface
 * quaternion alignment and wall-cling vs slope-slide detection (func_8017574C),
 * level 0xE 8-way yaw snapping, action transition table scan (D_801EEC44 +
 * func_8016536C -> func_80167604), idle/history counters, and per-frame
 * physics drag/friction adjustments.
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */
enum PlayerUpdateConstants {
    PLAYER_UPDATE_SOUND_SLOT_COUNT = 2,
    PLAYER_UPDATE_SOUND_SLOT_STRIDE = 0x1C,
    PLAYER_UPDATE_SPRITE_SLOT_COUNT = 2,
    PLAYER_UPDATE_POWERUP_TIMER_COUNT = 3,
    PLAYER_UPDATE_CONTACT_SLOT_COUNT = 4,
    PLAYER_UPDATE_CONTROLLER_STRIDE = 0x190,
    PLAYER_UPDATE_FALL_DAMAGE_MIN_FRAMES = 9,
    PLAYER_UPDATE_FALL_ANIM_MIN_FRAMES = 16,
    PLAYER_UPDATE_FALL_LETHAL_MIN_FRAMES = 17,
    PLAYER_UPDATE_FALL_SOUND_ID = 0xA0,
    PLAYER_UPDATE_SURFACE_TIMER_MAX = 100,
    PLAYER_UPDATE_SCALE_ANIM_FRAMES = 11,
    PLAYER_UPDATE_DEATH_ALIGN_MAX_FRAMES = 70,
    PLAYER_UPDATE_BLINK_OPAQUE = 100,
    PLAYER_UPDATE_LOCK_ANIM_BASE = 1000,
    PLAYER_UPDATE_LOCK_GROUNDED = 2000,
    PLAYER_UPDATE_LEVEL_SNAP_YAW = 0xE,
    PLAYER_UPDATE_YAW_SNAP_DIVISIONS = 8,
    PLAYER_UPDATE_FLAG_GROUNDED_LOCK = 0x1000,
    PLAYER_UPDATE_FLAG_LAUNCHED = 0x2000,
    PLAYER_UPDATE_FLAG_ALIGN_SURFACE = 0x4000,
    PLAYER_UPDATE_FLAG_WALL_CLING = 0x8000,
    PLAYER_UPDATE_FLAG_NO_GRAVITY = 0x10000000
};

enum PlayerUpdateOffsets {
    PLAYER_PHYS_GRAVITY_OFFSET = 0,
    PLAYER_PHYS_DRAG_OFFSET = 4,
    PLAYER_PHYS_FRICTION_OFFSET = 12,
    PLAYER_PHYS_ROLL_LOCK_OFFSET = 38,
    PLAYER_PHYS_ALIGN_RATE_OFFSET = 40,
    PLAYER_ACTION_IN_WATER_OFFSET = 9,
    PLAYER_COLLISION_FACE0_OFFSET = 0,
    PLAYER_COLLISION_HIT_COUNT_OFFSET = 68,
    PLAYER_COLLISION_GROUNDED_OFFSET = 392,
    PLAYER_COLLISION_CONTACT_FLAGS_OFFSET = 394,
    PLAYER_ANIM_CURRENT_OFFSET = 2,
    PLAYER_ANIM_DONE_OFFSET = 4,
    PLAYER_ANIM_TIME_OFFSET = 76
};
