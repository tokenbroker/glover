#include "common.h"
#include "structs.h"
#include "save_data.h"

/*
 * Saving to the cartridge EEPROM.
 *
 * The game never touches the EEPROM directly: it pushes a SaveOperation on a
 * small queue and busy-waits until the save worker thread (func_8013DF34)
 * has emptied it. The worker takes each operation off the queue and calls the
 * matching handler from the second half of this file, which does the actual
 * osEepromLongRead / osEepromLongWrite.
 */

/* libultra and libc, still known by address */
s32 func_801CFBD0(void *siQueue);                                    /* osEepromProbe */
s32 func_801D0280(void *siQueue, s32 block, void *buffer, s32 size); /* osEepromLongWrite */
s32 func_801D0370(void *siQueue, s32 block, void *buffer, s32 size); /* osEepromLongRead */
u64 func_801C7080(void);                                             /* osGetTime */
extern u64 D_801F43D0;                                               /* osClockRate, ticks per second */
s32 func_801D2150(void *dst, void *format, ...);                     /* sprintf */
void func_801D211C(void *dst, void *src, s32 size);                  /* memcpy */

u32 func_80139D14(u8 *data, s32 size); /* CRC of a block of bytes */

/* Save queue */
extern u8 D_801FA9B0[]; /* SAVE_QUEUE_LEN SaveOperation bytes; [0] is the one in progress */
extern u8 D_801EAB28;   /* number of queued operations */

/* EEPROM */
extern s32 D_801FB268; /* SI message queue the EEPROM calls go through */
extern s16 D_801EA9E0; /* osEepromProbe result: nonzero when an EEPROM is present */
extern u8 *D_801EAB2C; /* signature text that marks the EEPROM as holding our data */
extern u8 D_801EAB29;  /* 1 when the EEPROM carries that signature */

/* Saved data, and the defaults it is repaired from */
extern HighScoreEntry D_801EA9E4[]; /* high-score table, GAME_HIGH_SCORE_COUNT entries */
extern u8 D_801EAA14[];             /* default high-score table */
extern u8 D_801E6790[];             /* time records: six groups of GAME_TIME_RECORD_GROUP_BYTES */
extern u8 D_801E6850[];             /* default time records */
extern u8 D_801EAB08[];             /* default (unused) save slot */

/*
 * The six save slots are one table, LevelSaveSlot D_801EAA44[6] (save_data.h).
 * The code only comes out like the original's when each field is reached
 * through its own symbol, so the table is declared here as one view per
 * field: the field of slot 0, repeating every LEVEL_SAVE_SLOT_BYTES.
 */
typedef struct { u8 value; u8 restOfSlot[LEVEL_SAVE_SLOT_BYTES - 1]; } SaveSlotByte;
typedef struct { s32 value; u8 restOfSlot[LEVEL_SAVE_SLOT_BYTES - 4]; } SaveSlotWord;
extern SaveSlotByte D_801EAA44[]; /* LevelSaveSlot.initials[0]; also the start of the table */
extern SaveSlotByte D_801EAA45[]; /* LevelSaveSlot.initials[1] */
extern SaveSlotByte D_801EAA46[]; /* LevelSaveSlot.initials[2] */
extern SaveSlotWord D_801EAA50[]; /* LevelSaveSlot.score */
extern SaveSlotByte D_801EAA54[]; /* LevelSaveSlot.lives */

/* CRCs of the saved data, stored with it in the EEPROM: one per save slot,
 * then the high scores' and the time records' (D_801FA9D0 and D_801FA9D4 in
 * other files) */
enum {
    SAVE_CRC_HIGH_SCORES = SAVE_VALIDATION_SLOT_COUNT,
    SAVE_CRC_TIME_RECORDS
};
extern u32 D_801FA9B8[];

/* Game state that goes into the selected save slot */
extern s16 D_801EAB24; /* selected save slot */
extern u8 D_801FA9A8;  /* the player's three initials */
extern u8 D_801FA9A9;
extern u8 D_801FA9AA;
extern s32 D_80290188; /* score */
extern s32 D_8029018C; /* Garibs collected */
extern u8 D_80290193;  /* lives: low byte of the word at D_80290190 */

/*
 * The save queue
 */

/* save_queue_push: appends a SaveOperation to the end of the save queue. */
void func_80132940(u16 saveOp) {
    D_801FA9B0[D_801EAB28++] = saveOp;
}

/* save_queue_pop: takes the finished operation off the front of the save
 * queue: moves the rest down one slot, clears the last slot and decrements
 * the count. The save worker calls it after each handler. */
void func_80132990(void) {
    s16 slot;

    for (slot = 0; slot < SAVE_QUEUE_LEN - 1; slot++) {
        D_801FA9B0[slot] = D_801FA9B0[slot + 1];
    }
    D_801FA9B0[slot] = SAVE_OP_NONE;
    D_801EAB28--;
}

/* save_init: looks for an EEPROM (osEepromProbe), then queues a write of the
 * save signature and waits until the save worker has emptied the queue. */
void func_80132A30(void) {
    D_801EA9E0 = func_801CFBD0(&D_801FB268);
    func_80132940(SAVE_OP_WRITE_SIGNATURE);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_queue_clear: empties the save queue. */
void func_80132A9C(void) {
    u8 slot;

    D_801EAB28 = 0;
    for (slot = 0; slot < SAVE_QUEUE_LEN; slot++) {
        D_801FA9B0[slot] = SAVE_OP_NONE;
    }
}

/*
 * Requests from the game. Each one queues an operation and busy-waits until
 * the save worker has emptied the queue.
 */

/* save_read_high_scores: loads the high-score table from the EEPROM. */
void func_80132B08(void) {
    func_80132940(SAVE_OP_READ_HIGH_SCORES);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_write_high_scores: stores the high-score table in the EEPROM. */
void func_80132B5C(void) {
    func_80132940(SAVE_OP_WRITE_HIGH_SCORES);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_write_slots: stores the six save slots in the EEPROM. */
void func_80132BB0(void) {
    func_80132940(SAVE_OP_WRITE_SLOTS);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_read_time_records: loads the time records from the EEPROM. */
void func_80132C04(void) {
    func_80132940(SAVE_OP_READ_TIME_RECORDS);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_read_signature: checks the EEPROM for the save signature. */
void func_80132C58(void) {
    func_80132940(SAVE_OP_READ_SIGNATURE);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_read_slots: loads the six save slots from the EEPROM. */
void func_80132CAC(void) {
    func_80132940(SAVE_OP_READ_SLOTS);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_write_checksums: recomputes the CRCs of the saved data and stores them in the EEPROM. */
void func_80132D00(void) {
    func_80132940(SAVE_OP_WRITE_CHECKSUMS);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_read_checksums: loads the CRCs of the saved data from the EEPROM. */
void func_80132D54(void) {
    func_80132940(SAVE_OP_READ_CHECKSUMS);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* save_queue_flush: queues SAVE_OP_UNK_11, which transfers nothing, and waits
 * until the save worker has worked through everything queued before it. */
void func_80132DA8(void) {
    func_80132940(SAVE_OP_UNK_11);
    while (D_801FA9B0[0] != SAVE_OP_NONE) {
    }
}

/* busy_wait_20ms: spins on osGetTime until 20 ms have passed. The delay the
 * callers ask for is ignored. */
void func_80132DFC(register s32 unusedDelay) {
    s16 unusedDelayCopy = unusedDelay;
    u64 nowUsec;
    u64 startUsec;

    startUsec = nowUsec = (func_801C7080() * (u64)BUSY_WAIT_MICROSECONDS_PER_SECOND) / D_801F43D0;
    while ((nowUsec - startUsec) < (u64)BUSY_WAIT_DURATION_USEC) {
        nowUsec = (func_801C7080() * (u64)BUSY_WAIT_MICROSECONDS_PER_SECOND) / D_801F43D0;
    }
}

/*
 * The save worker's handlers, one per SaveOperation. They transfer nothing
 * when no EEPROM was found, give the EEPROM 20 ms after each transfer, and
 * never look at the status the libultra call returns.
 */

/* eeprom_write_high_scores (SAVE_OP_WRITE_HIGH_SCORES). */
void func_80132FF4(void) {
    s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0280(&D_801FB268, EEPROM_BLOCK_HIGH_SCORES, D_801EA9E4, EEPROM_HIGH_SCORES_BYTES);
    }
    func_80132DFC(10000);
}

/* eeprom_read_high_scores (SAVE_OP_READ_HIGH_SCORES). */
void func_8013305C(void) {
    s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0370(&D_801FB268, EEPROM_BLOCK_HIGH_SCORES, D_801EA9E4, EEPROM_HIGH_SCORES_BYTES);
    }
    func_80132DFC(10000);
}

/* eeprom_write_time_records (SAVE_OP_WRITE_TIME_RECORDS). */
void func_801330C4(void) {
    s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0280(&D_801FB268, EEPROM_BLOCK_TIME_RECORDS, D_801E6790, EEPROM_TIME_RECORDS_BYTES);
        func_80132DFC(10000);
    }
}

/* eeprom_read_time_records (SAVE_OP_READ_TIME_RECORDS). */
void func_8013312C(void) {
    s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0370(&D_801FB268, EEPROM_BLOCK_TIME_RECORDS, D_801E6790, EEPROM_TIME_RECORDS_BYTES);
        func_80132DFC(10000);
    }
}

/* eeprom_write_save_slots (SAVE_OP_WRITE_SLOTS): all six slots at once.
 * (The volatile keeps the status in memory, as the original code has it.) */
void func_80133194(void) {
    volatile s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0280(&D_801FB268, EEPROM_BLOCK_SAVE_SLOTS, D_801EAA44, EEPROM_SAVE_SLOTS_BYTES);
        func_80132DFC(10000);
    }
}

/* eeprom_read_save_slots (SAVE_OP_READ_SLOTS): all six slots at once. */
void func_801331FC(void) {
    volatile s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0370(&D_801FB268, EEPROM_BLOCK_SAVE_SLOTS, D_801EAA44, EEPROM_SAVE_SLOTS_BYTES);
        func_80132DFC(10000);
    }
}

/* eeprom_read_signature (SAVE_OP_READ_SIGNATURE): reads the signature block
 * and sets D_801EAB29 when its first four bytes are the expected signature. */
void func_80133264(void) {
    u8 signature[EEPROM_SIGNATURE_BYTES];
    s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0370(&D_801FB268, EEPROM_BLOCK_SIGNATURE, signature, EEPROM_SIGNATURE_BYTES);
        func_80132DFC(10000);
        if (signature[0] == D_801EAB2C[0] && signature[1] == D_801EAB2C[1] && signature[2] == D_801EAB2C[2] && signature[3] == D_801EAB2C[3]) {
            D_801EAB29 = 1;
        } else {
            D_801EAB29 = 0;
        }
    }
}

/* eeprom_write_signature (SAVE_OP_WRITE_SIGNATURE): writes the signature text
 * (copied with sprintf) to the signature block. */
void func_80133350(void) {
    s16 status;
    s32 signature[EEPROM_SIGNATURE_BYTES / sizeof(s32)];

    func_801D2150(signature, D_801EAB2C);
    if (D_801EA9E0 != 0) {
        status = func_801D0280(&D_801FB268, EEPROM_BLOCK_SIGNATURE, signature, EEPROM_SIGNATURE_BYTES);
        func_80132DFC(10000);
    }
}

/* eeprom_write_checksums (SAVE_OP_WRITE_CHECKSUMS): recomputes the CRCs of the
 * high scores, the time records and each save slot, then writes the table. */
void func_801333D0(void) {
    s16 status;
    s32 slot;

    D_801FA9B8[SAVE_CRC_HIGH_SCORES] = func_80139D14((u8 *)D_801EA9E4, GAME_HIGH_SCORE_TABLE_BYTES);
    D_801FA9B8[SAVE_CRC_TIME_RECORDS] = func_80139D14(D_801E6790, SAVE_TIME_RECORD_CRC_BYTES);
    for (slot = 0; slot < SAVE_VALIDATION_SLOT_COUNT; slot++) {
        D_801FA9B8[slot] = func_80139D14((u8 *)D_801EAA44 + slot * LEVEL_SAVE_SLOT_BYTES, LEVEL_SAVE_SLOT_BYTES);
    }
    if (D_801EA9E0 != 0) {
        status = func_801D0280(&D_801FB268, EEPROM_BLOCK_CHECKSUMS, D_801FA9B8, EEPROM_CHECKSUMS_BYTES);
        func_80132DFC(10000);
    }
}

/* eeprom_read_checksums (SAVE_OP_READ_CHECKSUMS): reads the CRC table. */
void func_801334F0(void) {
    s16 status;

    if (D_801EA9E0 != 0) {
        status = func_801D0370(&D_801FB268, EEPROM_BLOCK_CHECKSUMS, D_801FA9B8, EEPROM_CHECKSUMS_BYTES);
        func_80132DFC(10000);
    }
}

/* Empty stub (debug build leftover); its s16 argument is ignored. */
void func_80133558(s16 unused) {
}

/* Empty stub (debug build leftover); its s16 argument is ignored. */
void func_80133580(s16 unused) {
}

/*
 * Requests that work on the saved data itself
 */

/* save_slot_update: copies the player's initials, score (with
 * LEVEL_GARIB_SCORE points for every Garib collected) and lives into the
 * selected save slot. What it then queues is a read of the slots from the
 * EEPROM, not a write. The argument is not used. */
void func_801335A8(volatile u8 unused) {
    D_801EAA44[D_801EAB24].value = D_801FA9A8;
    D_801EAA45[D_801EAB24].value = D_801FA9A9;
    D_801EAA46[D_801EAB24].value = D_801FA9AA;
    D_801EAA50[D_801EAB24].value = D_80290188 + D_8029018C * LEVEL_GARIB_SCORE;
    D_801EAA54[D_801EAB24].value = D_80290193;
    func_80132CAC();
    func_80132DA8();
}

/* save_restore_invalid_records: checks everything loaded from the EEPROM
 * against its stored CRC and puts the defaults back where they differ: each
 * save slot on its own, the high-score table, and the time records (whose CRC
 * covers SAVE_TIME_RECORD_CRC_BYTES, of which only the six groups are reset). */
void func_801336E8(void) {
    s32 slot;
    u32 crc;

    for (slot = 0; slot < SAVE_VALIDATION_SLOT_COUNT; slot++) {
        crc = func_80139D14((u8 *)D_801EAA44 + slot * LEVEL_SAVE_SLOT_BYTES, LEVEL_SAVE_SLOT_BYTES);
        if (crc != D_801FA9B8[slot]) {
            func_801D211C((u8 *)D_801EAA44 + slot * LEVEL_SAVE_SLOT_BYTES, D_801EAB08, LEVEL_SAVE_SLOT_BYTES);
        }
    }
    crc = func_80139D14((u8 *)D_801EA9E4, GAME_HIGH_SCORE_TABLE_BYTES);
    if (crc != D_801FA9B8[SAVE_CRC_HIGH_SCORES]) {
        func_801D211C(D_801EA9E4, D_801EAA14, GAME_HIGH_SCORE_TABLE_BYTES);
    }
    crc = func_80139D14(D_801E6790, SAVE_TIME_RECORD_CRC_BYTES);
    if (crc != D_801FA9B8[SAVE_CRC_TIME_RECORDS]) {
        func_801D211C(D_801E6790 + 0 * GAME_TIME_RECORD_GROUP_BYTES, D_801E6850 + 0 * GAME_TIME_RECORD_GROUP_BYTES, GAME_TIME_RECORD_GROUP_BYTES);
        func_801D211C(D_801E6790 + 1 * GAME_TIME_RECORD_GROUP_BYTES, D_801E6850 + 1 * GAME_TIME_RECORD_GROUP_BYTES, GAME_TIME_RECORD_GROUP_BYTES);
        func_801D211C(D_801E6790 + 2 * GAME_TIME_RECORD_GROUP_BYTES, D_801E6850 + 2 * GAME_TIME_RECORD_GROUP_BYTES, GAME_TIME_RECORD_GROUP_BYTES);
        func_801D211C(D_801E6790 + 3 * GAME_TIME_RECORD_GROUP_BYTES, D_801E6850 + 3 * GAME_TIME_RECORD_GROUP_BYTES, GAME_TIME_RECORD_GROUP_BYTES);
        func_801D211C(D_801E6790 + 4 * GAME_TIME_RECORD_GROUP_BYTES, D_801E6850 + 4 * GAME_TIME_RECORD_GROUP_BYTES, GAME_TIME_RECORD_GROUP_BYTES);
        func_801D211C(D_801E6790 + 5 * GAME_TIME_RECORD_GROUP_BYTES, D_801E6850 + 5 * GAME_TIME_RECORD_GROUP_BYTES, GAME_TIME_RECORD_GROUP_BYTES);
    }
}

/* Not code: eight bytes of leftover text ("D.lll/  ") the original build left
 * between this file's functions and the next file's. */
const u32 D_801338F8_padding[] __attribute__((section(".text"))) = {
    0x442E646C, 0x6C2F2020
};
