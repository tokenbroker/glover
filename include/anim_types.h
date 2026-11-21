#ifndef ANIM_TYPES_H
#define ANIM_TYPES_H

#include "common.h"

/* Animation, object and particle structs shared by the 18020_* units. */

typedef struct { s32 w[16]; } Blk142700;
typedef struct { s16 start; s16 end; s32 unk4; s32 unk8; } AnimKey133BD0;
typedef struct {
    s16 unk0;
    s16 cur;
    s32 done;
    s32 hold;
    f32 speed;
    s16 next[5];
    s32 nextHold[5];
    f32 nextSpeed[5];
    s16 count;
    AnimKey133BD0 *keys;
    f32 time;
} Anim133BD0;
typedef struct { f32 x, y, z; s32 pad; s32 time; } Key143;
typedef struct Anim143 {
    u8 pad0[0xD];
    u8 opacity;
    s16 nScale;
    s16 nTrans;
    s16 nRot;
    s16 **unk14;
    s32 dlist;
    Key143 *scale;
    Key143 *trans;
    Key143 *rot;
    s32 nKids;
    u8 *kids;
    u8 pad30[2];
    u16 flags;
    struct Anim143 *child;
    struct Anim143 *sibling;
    u8 *att;
} Anim143;
typedef struct {
    /* 0x00 */ u8 pad0[0xD];
    /* 0x0D */ s8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 unk18[8];
    /* 0x20 */ u8 *unk20;
    /* 0x24 */ f32 unk24[3];
    /* 0x30 */ u8 pad30[5];
    /* 0x35 */ u8 unk35;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 unk37;
    /* 0x38 */ u8 pad38[2];
    /* 0x3A */ u8 unk3A;
    /* 0x3B */ u8 unk3B;
    /* 0x3C */ u8 pad3C[0x14];
    /* 0x50 */ f32 unk50;
} Obj80184FC0;
typedef struct Particle8014ED9C {
    /* 0x00 */ struct Particle8014ED9C *next;
    /* 0x04 */ struct Particle8014ED9C *prev;
    /* 0x08 */ s32 type;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20[3];
    /* 0x23 */ u8 unk23;
    /* 0x24 */ s32 unk24[20];
    /* 0x74 */ f32 vx;
    /* 0x78 */ f32 vy;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s16 unk80;
    /* 0x82 */ s16 unk82;
    /* 0x84 */ s16 unk84;
    /* 0x86 */ s16 unk86;
    /* 0x88 */ s16 unk88;
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ u8 unk8C;
    /* 0x8D */ u8 flags;
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 unk8F;
} Particle8014ED9C;

#endif /* ANIM_TYPES_H */
