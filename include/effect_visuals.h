#ifndef EFFECT_VISUALS_H
#define EFFECT_VISUALS_H

#include "common.h"

/* Quaternion components are x, y, z, w; w is the scalar component.
 * func_801488C0 (quaternion_multiply) computes left * right using a
 * temporary result, so its output may overlap either input. */
typedef struct {
    /* 0x00 */ f32 v[4];
} Quat801488C0; /* size = 0x10 */
typedef Quat801488C0 Quaternion;

/*
 * func_801628F4: object_accelerate_on_surface. Composes surface tilt with yaw,
 * then func_80160920 adds forward acceleration and applies the speed limit.
 * func_801470F8 computes up cross normal = (normal.z, 0, -normal.x);
 * func_80149604 normalizes XZ; func_80147114 returns acos in radians.
 * D_801ED3E0..EC is the shared (0, 1, 0, yaw) axis-angle scratch storage.
 * D_80107478 = -1 (downward normal); the double at byte +4 is a full turn.
 * D_80107484 = pi (downward tilt), D_80107488 = 1 (tilt axis X).
 * The downward case reverses yaw before applying the half-turn about X.
 */

/* func_80162A38: object_accelerate_surface_quaternion. Left-multiplies
 * the supplied heading quaternion by the surface tilt, then passes the result
 * to func_80160920 (object_accelerate_rotated) with the same speed-limit mode.
 * The input surface normal must be unit length. The heading is copied first.
 * D_8010748C = -1 (downward normal Y), D_80107490 = pi (half-turn),
 * D_80107494 = 1 (fallback axis X). The downward case rotates about positive X.
 * Other normals use normalize(up cross normal), then acos(normal.y).
 */

/* Axis-angle: unit axis x, y, z followed by the angle in radians. */
typedef f32 AxisAngle[4];

/* func_801499EC: vec3_rotate_axis_angle. Projects onto the unit axis and
 * rotates the perpendicular component, retaining its original magnitude.
 * func_801C4040 is cosf; func_801C6000 is sinf; func_801C4030 is sqrtf. */
enum AxisAngleComponent {
    AXIS_ANGLE_X = 0,
    AXIS_ANGLE_Y = 1,
    AXIS_ANGLE_Z = 2,
    AXIS_ANGLE_RADIANS = 3
};
typedef f32 QuaternionComponents[4];

/*
 * func_8015C350: quaternion_from_euler, angles in radians.
 * D_801EFC80 is the mutable Euler axis order, initially Y, Z, X.
 * D_801ED3D0 is the identity quaternion (x, y, z, w = 0, 0, 0, 1).
 * D_801071E4 is the unit-axis component (1.0f).
 * func_80148C3C converts axis-angle to quaternion;
 * func_801488C0 computes out = left * right (Hamilton product).
 */
enum EulerRotationConstants {
    EULER_AXIS_COUNT = 3
};

/*
 * func_801489F0: quaternion_to_axis_angle. Produces a unit axis and
 * 2 * acos(w) radians, selecting positive Y when sin(acos(w)) is zero.
 * D_80106304 = 1; D_80106308[0] = -1, with double 10000 at byte +4;
 * D_80106314 = 10000 (input scale); D_80106318 = 20000 (angle scale);
 * D_8010631C = 2 (half-angle divisor); D_80106320 = 1 (fallback Y).
 */

/*
 * func_8014A040 builds a surface-aligned quaternion from object yaw and a
 * unit surface normal. D_801ED3E0/E4/E8/EC hold the shared Y-axis angle:
 * (0, 1, 0, yaw). The downward normal uses a half-turn about X.
 *
 * D_801D41D0 is the u16 acos table: signed input * 10000 indexes around
 * byte offset 0x4E20; entries store radians * 20000.
 * D_801063F4 = -1 (downward Y); D_801063F8/6400 = 6.283185308 (full turn);
 * D_80106408 = pi (flip angle); D_8010640C = 1 (flip axis X);
 * D_80106410/6418 = +/-1.000001 (acos diagnostic bounds);
 * D_80106420 = 1 (acos identity); D_80106428 = 10000 (input scale);
 * D_8010642C = 20000 (angle scale); D_80106430 = 2 (half-angle divisor).
 *
 * func_801C6000/func_801C4040 are libultra sinf/cosf.
 * func_801D2150 is sprintf. D_8025D578 is its 256-byte debug buffer;
 * D_80106184 is "\\n%f\\n", and D_8010618C is "ACOS".
 * func_80139D70 is a disabled debug-output hook; func_80139D94 formats
 * a "CRASHED %s" diagnostic through that hook.
 */
/*
 * func_80147704: quaternion_slerp, shortest-arc spherical interpolation.
 * D_80106208 and D_80106224 = 1; D_8010620C = 0.00001 (linear fallback).
 * D_80106210[0] = -1; the double at +4 = 10000 (acos index scale).
 * D_8010621C = 10000; D_80106220 = 20000 (stored angle scale).
 * D_80106228[0] = pi/2; later values in that pool serve other functions.
 * D_801D8FF0 is the zero-input entry of the table at D_801D41D0.
 * D_801061B4 is "ACOSBETTER", passed to func_80139D94 on a domain error.
 * The original antipodal fallback blends only x/y/z after setting w = z.
 */
/*
 * func_80149C4C builds an x/y/z/w quaternion from a unit surface normal.
 * Its rotation axis is (normal.z, 0, -normal.x), normalized in XZ;
 * the angle is acos(normal.y). Up gives identity, down a half-turn about -Z.
 * The two branches retain separate copies of the same literal-pool values:
 * D_801063A0 = 1 (axis normalization);
 * D_801063A4/C8 = 1.000001, D_801063AC/D0 = -1.000001 (acos bounds);
 * D_801063B4/D8 = 1 (zero-angle input);
 * D_801063BC/E0 = 10000 (signed table index scale);
 * D_801063C0/E4 = 20000 (stored angle scale);
 * D_801063C4/E8 = 2 (quaternion half-angle divisor);
 * D_801063EC = 1 (identity w), D_801063F0 = -1 (downward axis z).
 */
/* func_80147114: acosTableRadians, a quantized lookup without interpolation.
 * D_80106194/19C are double diagnostic bounds (+/-1.000001);
 * D_801061A4 is double 1.0, handled separately to return exactly zero.
 * D_801061AC scales the input by 10000; truncation gives a signed index
 * relative to ACOS_TABLE_ZERO_BYTE_OFFSET in D_801D41D0.
 * D_801061B0 divides the unsigned 16-bit table value by 20000 for radians.
 * Domain diagnostics do not clamp or terminate: the debug hook is disabled.
 * Address-based symbol names remain because N64 renaming is unsupported.
 */
enum SurfaceOrientationConstants {
    ACOS_TABLE_ZERO_BYTE_OFFSET = 0x4E20,
    ACOS_TABLE_IDENTITY_INDEX = 10000
};

enum EffectTransformConstants {
    EFFECT_TYPE_ID_BASE = 1000,
    ORBIT_A_SHRINK_TIMER = 25,
    ORBIT_B_SHRINK_TIMER = 30,
    ORBIT_PARTICLE_MIN_TIMER = 16,
    ORBIT_TRAIL_PARTICLE_TYPE = 6,
    ROTATION_AXIS_X = 0,
    OBJECT_POSITION_OFFSET = 0x34,
    OBJECT_PITCH_OFFSET = 0x78,
    OBJECT_YAW_OFFSET = 0x7C,
    EFFECT_MODEL_TO_POSITION = 0x94,
    EFFECT_MODEL_TO_EULER = 0x50,
    EFFECT_MODEL_TO_QUATERNION = 0x2C,
    EFFECT_MODEL_TO_SCALE_X = 0x0C,
    EFFECT_TYPE_TO_POSITION = 0x14,
    EFFECT_YAW_TO_QUATERNION = 0x20
};

/*
 * update_player_effect_transforms (func_80174D4C):
 * D_8028FE98 / D_8028FF7C / D_80290060 are the model handles of
 * orbiting effects A / B / the attached effect. Their object bases are
 * D_8028FDD0 / D_8028FEB4 / D_8028FF98 (each model is at +0xC8).
 * D_8028FDF0 and D_8028FED4 contain effect IDs plus EFFECT_TYPE_ID_BASE.
 * D_8028FFC4[0] is the attached effect's owner.
 *
 * Object transforms: position at +0x34, Euler angles at +0x78,
 * quaternion x/y/z/w at +0x9C, scale at +0xBC.
 * D_8028FE4C / D_8028FF30 / D_80290014 are the effects' yaw angles.
 * D_802900E4 is the attached effect's angular step.
 *
 * Math helpers: func_80149724 = sin((frame + phase) / divisor);
 * func_801490AC = rotate vector about Y; func_8014915C = rotate about axis;
 * func_801496C8 = wrap an angle by at most one turn;
 * func_80148CC8 = base + vector * scale; func_80148C3C = axis-angle to quat;
 * func_801488C0 = quaternion product; func_8015C350 = Euler to quaternion.
 * func_801AE2E8 spawns a particle with both fade counters set to 15.
 *
 * Orbit constants in the original pool:
 * A: D_80108334 radius 20, D_80108338 bob amplitude 5,
 * D_8010833C height 3, D_80108340 angular step 0.3 radians,
 * D_80108348/50/58 scale decrements 0.008, D_80108360 particle Y speed 5.
 * B: D_80108364 radius 20, D_80108368 bob amplitude/particle Y speed 5,
 * D_8010836C height 3, D_80108370 angular step 0.3 radians,
 * D_80108378 scale decrement 0.01. D_801EF464 is the bob divisor (4).
 * D_80108380/84 and D_80108388/8C are player/other-owner offset Y/Z;
 * D_80108390 and D_8010839C are unit pitch/spin axis components.
 * The double at D_80108390 + 4 is the player's pitch adjustment (pi).
 */

#endif /* EFFECT_VISUALS_H */
