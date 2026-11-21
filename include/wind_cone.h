#ifndef WIND_CONE_H
#define WIND_CONE_H

#include "common.h"
#include "math_types.h"

/* func_8018AA60 applies this emitter's wind/suction cone to the object list
 * at D_8026A148. Positive strength pushes; negative strength pulls.
 * Cone tests use direction cosines after shifting the origin along the axis.
 * radialBlend mixes the cone axis with the direction from emitter to object.
 * axialOffset keeps its original word/float representation for call arguments.
 */
typedef struct WindCone {
    /* 0x00 */ Vec3F direction;
    /* 0x0C */ s16 enabled;
    /* 0x0E */ u8 padE[2];
    /* 0x10 */ f32 strength;
    /* 0x14 */ f32 cutoffCosine;
    /* 0x18 */ f32 radialBlend;
    /* 0x1C */ U32F32 axialOffset;
} WindCone; /* size = 0x20 */

typedef struct WindConeEmitter {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ u8 *rotationState;
    /* 0x30 */ u8 pad30[0x18];
    /* 0x48 */ WindCone *cone;
    /* 0x4C */ u8 pad4C[0x68];
    /* 0xB4 */ Vec3F position;
} WindConeEmitter; /* accessed prefix size = 0xC0 */

/* func_801490AC rotates about Y; func_8014915C rotates about a
 * selected axis. func_80148CC8 adds a scaled vector;
 * func_80149568 normalizes XYZ; func_80149398 sums two weighted vectors.
 * D_801095B0+4 is f64 0.1: minimum forward cosine / physics divisor test.
 * D_801095BC = 1; D_801095C0 = 0.1f (fallback physics divisor);
 * D_801095C4 = 10 (force scale); D_801095C8 = f64 0.01 (force cutoff);
 * D_801095D0 = f64 15 and D_801095D8 = 15.0f (upward speed cap).
 */
enum WindConeConstants {
    WIND_CONE_ENABLED = 1,
    OBJECT_AFFECTED_BY_SUCTION = 0x400,
    WIND_CONE_AXIS_X = 0,
    WIND_CONE_AXIS_Z = 2,
    WIND_CONE_OBJECT_RADIUS = 0x30,
    WIND_CONE_ROTATION_X = 0x38,
    WIND_CONE_ROTATION_Y = 0x3C,
    WIND_CONE_ROTATION_Z = 0x40,
    WIND_CONE_PREVIOUS_ROTATION_X = 0x44,
    WIND_CONE_PREVIOUS_ROTATION_Y = 0x48,
    WIND_CONE_PREVIOUS_ROTATION_Z = 0x4C
};

#endif
