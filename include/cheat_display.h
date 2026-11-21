#ifndef CHEAT_DISPLAY_H
#define CHEAT_DISPLAY_H

/*
 * func_801BC43C: cheat_input_update_display.
 * D_801F2198 holds eight input codes; D_801F21A1 is the input count.
 * D_802AAFF0 is the current glyph string (12 bytes of BSS);
 * D_802AB000 is the saved string used by the cheat notification (16 bytes).
 * D_801F21A8 is the notification frame counter; zero permits saving the code.
 * D_801EC7D2 enables the input overlay; level 45 uses conversion only.
 * D_8010C014 = 1.0f, the text scale.
 * func_80145680 = text_select_font; func_801469E4 = text_queue;
 * func_8012C2B0 = buffer_fill_bytes.
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */

/*
 * Eight-byte copy prefix of the glyph buffers, not their allocation size.
 * Preserve this legacy extent: the terminator written at index 8 is outside
 * the prefix and is deliberately excluded from the structure assignment.
 */
typedef struct {
    /* 0x00 */ u8 unk0[8]; /* Encoded cheat glyphs. */
} Unk801BC43C; /* size = 8 */

enum CheatDisplayConstants {
    CHEAT_DISPLAY_CREDITS_LEVEL = 45,
    CHEAT_GLYPH_CODE_2 = 0xAA,
    CHEAT_GLYPH_CODE_3 = 0xAB,
    CHEAT_GLYPH_CODE_1 = 0xAC,
    CHEAT_GLYPH_CODE_0 = 0xAD,
    CHEAT_GLYPH_BLANK = 0x20,
    CHEAT_TEXT_CENTERED = 1
};

#endif /* CHEAT_DISPLAY_H */
