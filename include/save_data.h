#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include "common.h"

/*
 * Records the game keeps on the cartridge EEPROM (see EepromLayout in
 * structs.h for where each table is stored).
 */

/* One line of the high-score table; D_801EA9E4 holds GAME_HIGH_SCORE_COUNT of them. */
typedef struct {
    s32 score;
    u8 name[4];
} HighScoreEntry; /* size = 0x08 */

/*
 * One saved game. D_801EAA44 holds SAVE_VALIDATION_SLOT_COUNT of them and
 * D_801EAB24 selects the one in use. The symbols in the comments are the
 * names other files still use for the same field of slot 0.
 */
typedef struct LevelSaveSlot {
    /* 0x00 */ u8 initials[3];      /* D_801EAA44..46; initials[0] == SAVE_SLOT_EMPTY: unused slot */
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s32 completedLevels; /* D_801EAA48: five bits per world */
    /* 0x08 */ s32 allGaribsLevels; /* D_801EAA4C: levels finished with every Garib */
    /* 0x0C */ s32 score;           /* D_801EAA50 */
    /* 0x10 */ u8 lives;            /* D_801EAA54 */
    /* 0x11 */ u8 difficulty;       /* D_801EAA55: 0 easy, 1 normal */
    /* 0x12 */ u8 unk12;            /* D_801EAA56: progress byte */
    /* 0x13 */ u8 hubProgress;      /* D_801EAA57 */
    /* 0x14 */ u8 unk14[4];
    /* 0x18 */ s16 sfxVolume;       /* D_801EAA5C */
    /* 0x1A */ s16 musicVolume;     /* D_801EAA5E */
} LevelSaveSlot; /* size = 0x1C (LEVEL_SAVE_SLOT_BYTES) */

#endif /* SAVE_DATA_H */
