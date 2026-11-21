#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include "common.h"

/* Plain XYZ float vector, as the game stores positions and velocities. */
typedef struct { f32 x, y, z; } Vec3F;

/* A word read either as an integer or as its float bit pattern. */
typedef union {
    s32 i;
    f32 f;
} U32F32;

#endif
