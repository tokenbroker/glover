#include "common.h"
#include "structs.h"

/* libultra's single-precision trigonometry and matrix utilities. The game's symbols can't
 * be renamed yet, so each function's comment starts with its libultra name. The sqrtf that
 * precedes them (func_801C4030: jr ra with sqrt.s in its delay slot) is hand-written and
 * lives, with its padding, in asm/C5030.s. */

f32 func_801C4040(f32 radians);             /* cosf */
void func_801C5300(f32 *mf, u32 *m);        /* guMtxF2L */
void func_801C5440(s32 *mf);                /* guMtxIdentF */
void func_801C5E70(f32 *x, f32 *y, f32 *z); /* guNormalize */
f32 func_801C6000(f32 angle);               /* sinf */

/* Quiet NaN (bits 0x7F810000) that the trigonometric functions return for a NaN argument. */
extern f32 D_8010C270;

/* Degrees-to-radians factor (0.017453292f) of the rotation builders. */
extern f32 D_801F43A0;

/* Constants of func_801C4040: polynomial coefficients for x^3, x^5, x^7 and x^9, 1/pi,
 * pi split into a high and a low part, the zero returned past 2^28, and two 0.5s. */
extern f64 D_8010C218;
extern f64 D_8010C220;
extern f64 D_8010C228;
extern f64 D_8010C230;
extern f64 D_8010C238;
extern f64 D_8010C240;
extern f64 D_8010C248;
extern f32 D_8010C250;
extern f64 D_8010C258;
extern f64 D_8010C260;

/* cosf: approximate cosine in radians using range reduction and a sine polynomial. */
f32 func_801C4040(f32 radians) {
    f32 magnitude;
    f64 reducedAngle;
    f64 angleSquared;
    f64 polynomial;
    f64 halfTurns;
    s32 halfTurnIndex;
    f64 result;
    s32 floatBits;
    s32 rangeKey;

    floatBits = *(s32 *)&radians;
    rangeKey = (floatBits >> COSINE_RANGE_KEY_SHIFT) & COSINE_RANGE_KEY_MASK;

    if (rangeKey < COSINE_RANGE_LIMIT_2_POW_28) {
        magnitude = (radians > 0.0f) ? radians : -radians;
        reducedAngle = magnitude;
        halfTurns = reducedAngle * D_8010C238 + D_8010C258;
        halfTurnIndex = (s32)((halfTurns >= 0.0) ? (halfTurns + D_8010C258) : (halfTurns - D_8010C258));
        halfTurns = halfTurnIndex;
        halfTurns -= D_8010C260;
        reducedAngle = reducedAngle - halfTurns * D_8010C240;
        reducedAngle = reducedAngle - halfTurns * D_8010C248;
        angleSquared = reducedAngle * reducedAngle;
        polynomial = ((D_8010C230 * angleSquared + D_8010C228) * angleSquared + D_8010C220) * angleSquared + D_8010C218;
        result = reducedAngle + (reducedAngle * angleSquared) * polynomial;
        if ((halfTurnIndex & 1) == 0) {
            return result;
        }
        return -(f32)result;
    }
    if (radians != radians) {
        return D_8010C270;
    }
    return D_8010C250;
}

/* guLookAtF: build an orthonormal look-at view matrix from the eye, target and up vector. */
void func_801C4190(Matrix4f view, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp) {
    f32 inverseLength, xBack, yBack, zBack, xRight, yRight, zRight;

    func_801C5440((s32 *)view);

    xBack = xAt - xEye;
    yBack = yAt - yEye;
    zBack = zAt - zEye;
    inverseLength = -1.0 / __builtin_sqrtf(xBack * xBack + yBack * yBack + zBack * zBack);
    xBack *= inverseLength;
    yBack *= inverseLength;
    zBack *= inverseLength;

    xRight = yUp * zBack - zUp * yBack;
    yRight = zUp * xBack - xUp * zBack;
    zRight = xUp * yBack - yUp * xBack;
    inverseLength = 1.0 / __builtin_sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= inverseLength;
    yRight *= inverseLength;
    zRight *= inverseLength;

    xUp = yBack * zRight - zBack * yRight;
    yUp = zBack * xRight - xBack * zRight;
    zUp = xBack * yRight - yBack * xRight;
    inverseLength = 1.0 / __builtin_sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= inverseLength;
    yUp *= inverseLength;
    zUp *= inverseLength;

    view[0][0] = xRight;
    view[1][0] = yRight;
    view[2][0] = zRight;
    view[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    view[0][1] = xUp;
    view[1][1] = yUp;
    view[2][1] = zUp;
    view[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    view[0][2] = xBack;
    view[1][2] = yBack;
    view[2][2] = zBack;
    view[3][2] = -(xEye * xBack + yEye * yBack + zEye * zBack);

    view[0][3] = 0.0f;
    view[1][3] = 0.0f;
    view[2][3] = 0.0f;
    view[3][3] = 1.0f;
}

/* guLookAt: build an orthonormal look-at view matrix (guLookAtF, inlined) and pack it for the RSP. */
void func_801C4510(u32 *packedMatrix, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp) {
    Matrix4f viewMatrix;

    {
        f32 (*view)[4] = viewMatrix;
        f32 inverseLength, xBack, yBack, zBack, xRight, yRight, zRight;

        func_801C5440((s32 *)view);

        xBack = xAt - xEye;
        yBack = yAt - yEye;
        zBack = zAt - zEye;
        inverseLength = -1.0 / __builtin_sqrtf(xBack * xBack + yBack * yBack + zBack * zBack);
        xBack *= inverseLength;
        yBack *= inverseLength;
        zBack *= inverseLength;

        xRight = yUp * zBack - zUp * yBack;
        yRight = zUp * xBack - xUp * zBack;
        zRight = xUp * yBack - yUp * xBack;
        inverseLength = 1.0 / __builtin_sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
        xRight *= inverseLength;
        yRight *= inverseLength;
        zRight *= inverseLength;

        xUp = yBack * zRight - zBack * yRight;
        yUp = zBack * xRight - xBack * zRight;
        zUp = xBack * yRight - yBack * xRight;
        inverseLength = 1.0 / __builtin_sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
        xUp *= inverseLength;
        yUp *= inverseLength;
        zUp *= inverseLength;

        view[0][0] = xRight;
        view[1][0] = yRight;
        view[2][0] = zRight;
        view[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

        view[0][1] = xUp;
        view[1][1] = yUp;
        view[2][1] = zUp;
        view[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

        view[0][2] = xBack;
        view[1][2] = yBack;
        view[2][2] = zBack;
        view[3][2] = -(xEye * xBack + yEye * yBack + zEye * zBack);

        view[0][3] = 0.0f;
        view[1][3] = 0.0f;
        view[2][3] = 0.0f;
        view[3][3] = 1.0f;
    }

    func_801C5300((f32 *)viewMatrix, packedMatrix);
}

/* Original compiler padding. */
const u32 D_801C4894_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* Constants of func_801C48A0: the -1.0 and 1.0 of the reciprocal lengths, then for each
 * of the two lights a 1.0 and the 0.1 below which its half vector is too short to use. */
extern const f64 D_8010C2A0;
extern const f64 D_8010C2A8;
extern const f64 D_8010C2B0;
extern const f64 D_8010C2B8;
extern const f64 D_8010C2C0;

/* guLookAtHiliteF: build a float view matrix looking from eye to at, fill the LookAt light
 * directions and compute the texture coordinates of two specular highlights (Hilite). */
void func_801C48A0(f32 mf[4][4], u8 *l, s32 *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight)
{
    f64 one;
    f32 len, xLook, yLook, zLook, zl2Copy, xRight, zUpCopy, yRight, zRight, xHilite, yHilite, zHilite;
    float scale;

    func_801C5440((s32 *)mf);
    { { f64 d = xUp; xUp = d; } { f64 d = zUp; zUp = d; } }

    xLook = xAt - xEye;
    zUpCopy = zUp;
    yLook = yAt - yEye;
    zLook = zAt - zEye;
    len = D_8010C2A0 / __builtin_sqrtf(((xLook * xLook) + (yLook * yLook)) + (zLook * zLook));
    xLook *= len;
    yLook *= len;
    zLook *= len;

    /* right = up x look */
    xRight = (yUp * zLook) - (zUpCopy * yLook);
    yRight = (zUpCopy * xLook) - (xUp * zLook);
    zRight = (xUp * yLook) - (yUp * xLook);
    len = __builtin_sqrtf(((xRight * xRight) + (yRight * yRight)) + (zRight * zRight));
    one = D_8010C2A8;
    do { f64 d = one; one = d; } while (0);
    len = one / len;
    xRight *= len;
    yRight *= len;
    zRight *= len;

    /* up = look x right */
    xUp = (yLook * zRight) - (zLook * yRight);
    yUp = (zLook * xRight) - (xLook * zRight);
    zUp = (xLook * yRight) - (yLook * xRight);
    len = one / __builtin_sqrtf(((xUp * xUp) + (yUp * yUp)) + (zUp * zUp));
    xUp *= len;
    yUp *= len;
    zUp = zUp * len;

    /* highlight 1 */
    len = one / __builtin_sqrtf(((xl1 * xl1) + (yl1 * yl1)) + (zl1 * zl1));
    xl1 *= len;
    yl1 *= len;
    zl1 *= len;
    xHilite = xl1 + xLook;
    yHilite = yl1 + yLook;
    zHilite = zl1 + zLook;
    len = __builtin_sqrtf(((xHilite * xHilite) + (yHilite * yHilite)) + (zHilite * zHilite));
    if (len > D_8010C2B0) {
        len = one / len;
        xHilite *= len;
        yHilite *= len;
        zHilite *= len;
        h[0] = (twidth * 4) + (((((xHilite * xRight) + (yHilite * yRight)) + (zHilite * zRight)) * twidth) * 2);
        h[1] = (theight * 4) + (((((xHilite * xUp) + (yHilite * yUp)) + (zHilite * zUp)) * theight) * 2);
    } else {
        h[0] = twidth * 2;
        h[1] = theight * 2;
    }

    /* highlight 2 */
    zl2Copy = zl2;
    len = __builtin_sqrtf(((xl2 * xl2) + (yl2 * yl2)) + (zl2Copy * zl2Copy));
    one = D_8010C2B8;
    len = one / len;
    xl2 *= len;
    yl2 *= len;
    zl2 *= len;
    xHilite = xl2 + xLook;
    yHilite = yl2 + yLook;
    zHilite = zl2 + zLook;
    len = __builtin_sqrtf(((xHilite * xHilite) + (yHilite * yHilite) + (zHilite * zHilite)));
    if (len > D_8010C2C0) {
        len = one / len;
        xHilite *= len;
        yHilite *= len;
        zHilite *= len;
        h[2] = (twidth * 4) + (((((xHilite * xRight) + (yHilite * yRight)) + (zHilite * zRight)) * twidth) * 2);
        h[3] = (theight * 4) + (((((xHilite * xUp) + (yHilite * yUp)) + (zHilite * zUp)) * theight) * 2);
    } else {
        h[2] = twidth * 2;
        h[3] = theight * 2;
    }

    /* LookAt directions, as signed bytes clamped to 127 */
    { f32 value = xRight * 128.0f; if (value < 127.0f) { l[8] = (s32)value; } else { l[8] = (s32)127.0f; } }
    { f32 value = yRight * 128.0f; if (value < 127) { l[9] = (s32)value; } else { l[9] = (s32)127.0f; } }
    { f32 value = zRight * 128.0f; if (value < 127.0f) { l[10] = (s32)value; } else { l[10] = (s32)127.0f; } }
    { f32 value = xUp * 128.0f; if (value < 127.0f) { l[0x18] = (s32)value; } else { l[0x18] = (s32)127.0f; } }
    { f32 value = yUp * 128.0f; if (value < 127.0f) { l[0x19] = (s32)value; } else { l[0x19] = (s32)127.0f; } }
    scale = 128.0f;
    { f32 value = zUp * scale; if (value < 127.0f) { l[0x1A] = (s32)value; } else { l[0x1A] = (s32)127.0f; } }

    /* LookAt colors: black, with the second light's col/colc set to 0x80 */
    l[0] = 0; l[1] = 0; l[2] = 0; l[3] = 0;
    l[4] = 0; l[5] = 0; l[6] = 0; l[7] = 0;
    l[0x10] = 0; l[0x11] = 0x80; l[0x12] = 0; l[0x13] = 0;
    l[0x14] = 0; l[0x15] = 0x80; l[0x16] = 0; l[0x17] = 0;

    mf[0][0] = xRight; mf[1][0] = yRight; mf[2][0] = zRight;
    mf[3][0] = -(((xEye * xRight) + (yEye * yRight)) + (zEye * zRight));
    mf[0][1] = xUp; mf[1][1] = yUp; mf[2][1] = zUp;
    mf[3][1] = -(((xEye * xUp) + (yEye * yUp)) + (zEye * zUp));
    mf[0][2] = xLook; mf[1][2] = yLook; mf[2][2] = zLook;
    mf[3][2] = -(((xEye * xLook) + (yEye * yLook)) + (zEye * zLook));
    mf[0][3] = 0.0f; mf[1][3] = 0.0f; mf[2][3] = 0.0f; mf[3][3] = 1.0f;
}

/* guLookAtHilite: build the float look-at matrix, the LookAt and the Hilite with
 * guLookAtHiliteF (func_801C48A0), then pack the matrix into the fixed-point Mtx with
 * guMtxF2L (func_801C5300). xEye arrives as its raw bits in a3. */
void func_801C5224(u32 *m, s32 lookAt, s32 hilite, s32 xEyeBits, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight) {
    f32 mf[16];

    ((void (*)(f32 *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32))func_801C48A0)(mf, lookAt, hilite, xEyeBits, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp, xl1, yl1, zl1, xl2, yl2, zl2, twidth, theight);
    func_801C5300(mf, m);
}

/* Original compiler padding. */
const u32 D_801C52F8_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* guMtxF2L: convert a 4x4 float matrix to the RSP's s15.16 fixed-point Mtx
 * (integer halves in the first 8 words, fraction halves in the last 8). */
void func_801C5300(f32 *mf, u32 *m) {
    u32 *intPart = m;
    u32 *fracPart = m + 8;
    s32 row;
    s32 col;
    f32 *rowSrc;
    f32 *src;

    row = 0;
    do {
        rowSrc = mf + row * 4;
        col = 0;
        src = rowSrc;
        do {
            s32 e1 = src[0] * 65536.0f;
            s32 e2 = src[1] * 65536.0f;

            *intPart++ = (e1 & 0xFFFF0000) | ((u32)e2 >> 16);
            *fracPart++ = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
            src += 2;
            col++;
        } while (col < 2);
        row++;
    } while (row < 4);
}

/* guMtxL2F: convert a fixed-point s15.16 Mtx (integer halves in words 0-7,
 * fraction halves in words 8-15) to a 4x4 float matrix. */
void func_801C5398(f32 mf[4][4], u32 *m) {
    u32 *intPart = m;
    u16 *fracPart = (u16 *)(m + 8);
    s32 row, col;
    s32 fixed[2];
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 2; col++) {
            f32 a, b;
            fixed[0] = (intPart[0] & 0xffff0000) | fracPart[0];
            fixed[1] = ((intPart[0] << 16) & 0xffff0000) | fracPart[1];
            a = (f32)(s32)fixed[0] * (1.0f / 65536.0f);
            b = (f32)(s32)fixed[1] * (1.0f / 65536.0f);
            mf[row][col * 2] = a;
            mf[row][col * 2 + 1] = b;
            fracPart += 2;
            intPart++;
        }
    }
}

/* guMtxIdentF: fill a 4x4 float matrix with the identity (zeros are stored as
 * integer words, the diagonal as 1.0f). */
void func_801C5440(s32 *mf) {
    s32 row = 0;
    f32 one = 1.0f;
    s32 col;
    s32 *cell;
    f32 *diagonal = (f32 *)mf;

    for (; row < 4; row++) {
        col = 0;
        cell = mf;
        do {
            if (row == col) {
                *diagonal = one;
            } else {
                *cell = 0;
            }
            cell++;
            col++;
        } while (col < 4);
        diagonal += 5;
        mf += 4;
    }
}

/* guMtxIdent: write an identity matrix in the RSP's fixed-point Mtx format
 * (guMtxIdentF followed by guMtxF2L, both inlined): the first 8 words hold the
 * 16-bit integer parts, the next 8 the 16-bit fractions. */
void func_801C5490(u32 *mtx) {
    f32 mf[4][4];

    {
        int row, col;

        for (row = 0; row < 4; row++)
            for (col = 0; col < 4; col++)
                if (row == col) mf[row][col] = 1.0;
                else mf[row][col] = 0.0;
    }
    {
        int row, pair;
        int fixed1, fixed2;
        int *intPart, *fracPart;

        intPart = (int *)mtx;
        fracPart = (int *)(mtx + 8);
        for (row = 0; row < 4; row++)
            for (pair = 0; pair < 2; pair++) {
                fixed1 = (long)(mf[row][pair * 2] * (float)0x00010000);
                fixed2 = (long)(mf[row][pair * 2 + 1] * (float)0x00010000);
                *(intPart++) = (fixed1 & 0xffff0000) | ((fixed2 >> 16) & 0xffff);
                *(fracPart++) = ((fixed1 << 16) & 0xffff0000) | (fixed2 & 0xffff);
            }
    }
}

/* guMtxCatF: res = mf * nf (row-vector convention), via a temporary so res may alias an input. */
void func_801C5580(f32 mf[4][4], f32 nf[4][4], f32 res[4][4]) {
    f32 temp[4][4];
    s32 i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = 0.0f;
            for (k = 0; k < 4; k++) {
                temp[i][j] += mf[i][k] * nf[k][j];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            res[i][j] = temp[i][j];
        }
    }
}

/* guMtxXFMF: transform the point (x, y, z) by the float matrix mf (row vectors, translation in row 3). */
void func_801C565C(f32 mf[4][4], f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz) {
    *ox = mf[0][0] * x + mf[1][0] * y + mf[2][0] * z + mf[3][0];
    *oy = mf[0][1] * x + mf[1][1] * y + mf[2][1] * z + mf[3][1];
    *oz = mf[0][2] * x + mf[1][2] * y + mf[2][2] * z + mf[3][2];
}

/* Original compiler padding. */
const u32 D_801C5708_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* guMtxCatL: res = a * b for fixed-point Mtx. Unpacks both to float (guMtxL2F),
 * multiplies (guMtxCatF) and packs the product back (guMtxF2L). */
void func_801C5710(u8 *a, u8 *b, u8 *res) {
    f32 af[4][4];
    f32 bf[4][4];
    f32 resf[4][4];

    func_801C5398(af, (u32 *)a);
    func_801C5398(bf, (u32 *)b);
    func_801C5580(af, bf, resf);
    func_801C5300((f32 *)resf, (u32 *)res);
}

/* guMtxXFML: transform the point (x, y, z) by the fixed-point matrix m. */
void func_801C5784(u32 *m, f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz)
{
    f32 mf[4][4];

    func_801C5398(mf, m);                   /* guMtxL2F */
    func_801C565C(mf, x, y, z, ox, oy, oz); /* guMtxXFMF */
}

/* Constants of func_801C5810: degrees to radians (pi / 180), the near + far sum of 2
 * at or below which the normalization factor saturates, and its numerator 131072. */
extern f64 D_8010C2D0;
extern f64 D_8010C2D8;
extern f64 D_8010C2E0;

/* guPerspectiveF: build a floating-point perspective matrix and optionally its RSP normalization factor. */
void func_801C5810(f32 *matrixElements, u16 *perspNorm, f32 fovY, f32 aspectRatio, f32 nearPlane, f32 farPlane, f32 matrixScale) {
    f32 cotHalfFov;
    s32 row, column;

    func_801C5440((s32 *)(*(Matrix4f *)matrixElements));

    fovY *= D_8010C2D0;
    cotHalfFov = func_801C4040(fovY / 2) / func_801C6000(fovY / 2);

    (*(Matrix4f *)matrixElements)[0][0] = cotHalfFov / aspectRatio;
    (*(Matrix4f *)matrixElements)[1][1] = cotHalfFov;
    (*(Matrix4f *)matrixElements)[2][2] = (nearPlane + farPlane) / (nearPlane - farPlane);
    (*(Matrix4f *)matrixElements)[2][3] = -1;
    (*(Matrix4f *)matrixElements)[3][2] = (2 * nearPlane * farPlane) / (nearPlane - farPlane);
    (*(Matrix4f *)matrixElements)[3][3] = 0;

    for (row = 0; row < 4; row++)
        for (column = 0; column < 4; column++)
            (*(Matrix4f *)matrixElements)[row][column] *= matrixScale;

    if (perspNorm != (u16 *)NULL) {
        if (nearPlane + farPlane <= D_8010C2D8) {
            *perspNorm = (u16)PERSPECTIVE_NORMALIZATION_MAX;
        } else {
            *perspNorm = (u16)(D_8010C2E0 / (nearPlane + farPlane));
            if (*perspNorm <= 0)
                *perspNorm = (u16)PERSPECTIVE_NORMALIZATION_MIN;
        }
    }
}

/* The same three constants again, for the copy of that code inlined in func_801C59C0. */
extern f64 D_8010C2F0;
extern f64 D_8010C2F8;
extern f64 D_8010C300;

/* guPerspective: build a packed perspective projection matrix (guPerspectiveF, inlined) and
 * optionally its RSP normalization factor. */
void func_801C59C0(u32 *packedMatrix, u16 *perspNorm, f32 fovYDegrees, f32 aspectRatio, f32 nearPlane, f32 farPlane, f32 matrixScale) {
    Matrix4f projection;
    {
        f32 (*matrix)[4] = projection;
        f32 fovY = fovYDegrees, aspect = aspectRatio, nearClip = nearPlane, farClip = farPlane, scale = matrixScale;
        f32 cotHalfFov;
        s32 row, column;

        func_801C5440((s32 *)matrix);
        fovY *= D_8010C2F0;
        cotHalfFov = func_801C4040(fovY / 2) / func_801C6000(fovY / 2);
        matrix[0][0] = cotHalfFov / aspect;
        matrix[1][1] = cotHalfFov;
        matrix[2][2] = (nearClip + farClip) / (nearClip - farClip);
        matrix[2][3] = -1;
        matrix[3][2] = (2 * nearClip * farClip) / (nearClip - farClip);
        matrix[3][3] = 0;
        for (row = 0; row < 4; row++)
            for (column = 0; column < 4; column++)
                matrix[row][column] *= scale;
        if (perspNorm != (u16 *)NULL) {
            if (nearClip + farClip <= D_8010C2F8) {
                *perspNorm = (u16)PERSPECTIVE_NORMALIZATION_MAX;
            } else {
                *perspNorm = (u16)(D_8010C300 / (nearClip + farClip));
                if (*perspNorm <= 0)
                    *perspNorm = (u16)PERSPECTIVE_NORMALIZATION_MIN;
            }
        }
    }
    func_801C5300(projection, packedMatrix);
}

/* Original compiler padding. */
const u32 D_801C5B88_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* guRotateF: build a row-vector rotation matrix from an angle in degrees and a nonzero XYZ axis. */
void func_801C5B90(Matrix4f matrix, f32 angle, f32 axisX, f32 axisY, f32 axisZ) {
    f32 sine;
    f32 cosine;
    f32 xyTerm, yzTerm, zxTerm, term;

    func_801C5E70(&axisX, &axisY, &axisZ);
    angle *= D_801F43A0;
    sine = func_801C6000(angle);
    cosine = func_801C4040(angle);
    term = (1 - cosine);
    xyTerm = axisX * axisY * term;
    yzTerm = axisY * axisZ * term;
    zxTerm = axisZ * axisX * term;

    func_801C5440((s32 *)matrix);

    term = axisX * axisX;
    matrix[0][0] = term + cosine * (1 - term);
    matrix[2][1] = yzTerm - axisX * sine;
    matrix[1][2] = yzTerm + axisX * sine;

    term = axisY * axisY;
    matrix[1][1] = term + cosine * (1 - term);
    matrix[2][0] = zxTerm + axisY * sine;
    matrix[0][2] = zxTerm - axisY * sine;

    term = axisZ * axisZ;
    matrix[2][2] = term + cosine * (1 - term);
    matrix[1][0] = xyTerm - axisZ * sine;
    matrix[0][1] = xyTerm + axisZ * sine;
}

/* guRotate: build a packed 16.16 rotation matrix from an angle in degrees and an XYZ axis
 * (guRotateF, inlined). */
void func_801C5CEC(u32 *packedMatrix, f32 angleDegrees, f32 axisX, f32 axisY, f32 axisZ) {
    Matrix4f rotation;
    {
        f32 angle = angleDegrees;
        f32 scratch[2];
        f32 unitX = axisX, unitY = axisY, unitZ = axisZ;
        f32 (*matrix)[4] = rotation;
        f32 sine;
        f32 cosine;
        f32 xyTerm, yzTerm, zxTerm, term;

        func_801C5E70(&unitX, &unitY, &unitZ);
        angle *= D_801F43A0;
        sine = func_801C6000(angle);
        cosine = func_801C4040(angle);
        term = (1 - cosine);
        xyTerm = unitX * unitY * term;
        yzTerm = unitY * unitZ * term;
        zxTerm = unitZ * unitX * term;

        func_801C5440((s32 *)matrix);

        term = unitX * unitX;
        matrix[0][0] = term + cosine * (1 - term);
        matrix[2][1] = yzTerm - unitX * sine;
        matrix[1][2] = yzTerm + unitX * sine;

        term = unitY * unitY;
        matrix[1][1] = term + cosine * (1 - term);
        matrix[2][0] = zxTerm + unitY * sine;
        matrix[0][2] = zxTerm - unitY * sine;

        term = unitZ * unitZ;
        matrix[2][2] = term + cosine * (1 - term);
        matrix[1][0] = xyTerm - unitZ * sine;
        matrix[0][1] = xyTerm + unitZ * sine;
    }
    func_801C5300((f32 *)rotation, packedMatrix);
}

/* Original compiler padding. */
const u32 D_801C5E64_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* guNormalize: scale the vector (*x, *y, *z) to unit length in place. */
void func_801C5E70(f32 *x, f32 *y, f32 *z)
{
    f32 invLength = 1.0f / __builtin_sqrtf(x[0] * x[0] + y[0] * y[0] + z[0] * z[0]);
    x[0] *= invLength;
    y[0] *= invLength;
    z[0] *= invLength;
}

/* Original compiler padding. */
const u32 D_801C5F18_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* guScaleF: build a 4x4 float scale matrix (the identity from guMtxIdentF, then the diagonal). */
void func_801C5F20(s32 *mf, f32 x, f32 y, f32 z) {
    func_801C5440(mf);
    ((f32 *)mf)[0] = x;  /* mf[0][0] */
    ((f32 *)mf)[5] = y;  /* mf[1][1] */
    ((f32 *)mf)[10] = z; /* mf[2][2] */
    ((f32 *)mf)[15] = 1.0f;
}

/* guScale: build a fixed-point scale matrix in `mtx` (guScaleF, inlined, then guMtxF2L). */
void func_801C5F80(s32 mtx, f32 scaleX, f32 scaleY, f32 scaleZ) {
    f32 mf[4][4];

    {
        f32 (*m)[4] = mf;
        f32 x = scaleX, y = scaleY, z = scaleZ;

        func_801C5440((s32 *)m);
        m[0][0] = x;
        m[1][1] = y;
        m[2][2] = z;
        m[3][3] = 1;
    }
    func_801C5300((f32 *)mf, (u32 *)mtx);
}

/* Original compiler padding. */
const u32 D_801C5FFC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

/* Constants of func_801C6000, laid out like the cosine's: coefficients for x^3, x^5, x^7
 * and x^9, 1/pi, pi high and low, the zero returned past 2^28, and two 0.5s. */
extern f64 D_8010C318;
extern f64 D_8010C320;
extern f64 D_8010C328;
extern f64 D_8010C330;
extern f64 D_8010C338;
extern f64 D_8010C340;
extern f64 D_8010C348;
extern f32 D_8010C350;
extern f64 D_8010C358;
extern f64 D_8010C360;

/* sinf: approximate sine in radians, reducing by multiples of pi and restoring the sign. */
f32 func_801C6000(f32 angle) {
    f64 reducedAngle, angleSquared, polynomial, piMultiple;
    f64 result;
    s32 halfTurns;
    s32 magnitudeClass = *(s32 *)&angle >> SINE_CLASS_SHIFT;
    magnitudeClass &= SINE_CLASS_MASK;
    if (magnitudeClass < SINE_DIRECT_CLASS_LIMIT) {
        reducedAngle = angle;
        if (magnitudeClass >= SINE_TINY_CLASS_LIMIT) {
            { f64 angleCopy; angleCopy = reducedAngle; do { reducedAngle = angleCopy; } while (0); angleSquared = reducedAngle * angleCopy; }
            polynomial = ((D_8010C330 * angleSquared + D_8010C328) * angleSquared + D_8010C320) * angleSquared + D_8010C318;
            result = reducedAngle + (reducedAngle * angleSquared) * polynomial;
            return (f32)result;
        } else {
            return angle;
        }
    } else if (magnitudeClass < SINE_REDUCTION_CLASS_LIMIT) {
        reducedAngle = angle;
        piMultiple = reducedAngle * D_8010C338;
        if (piMultiple >= 0.0)
            halfTurns = (s32)(piMultiple + D_8010C358);
        else
            halfTurns = (s32)(piMultiple - D_8010C360);
        piMultiple = halfTurns;
        reducedAngle -= piMultiple * D_8010C340;
        reducedAngle -= piMultiple * D_8010C348;
        angleSquared = reducedAngle * reducedAngle;
        polynomial = ((D_8010C330 * angleSquared + D_8010C328) * angleSquared + D_8010C320) * angleSquared + D_8010C318;
        result = reducedAngle + (reducedAngle * angleSquared) * polynomial;
        if ((halfTurns & 1) == 0)
            return (f32)result;
        return -(f32)result;
    } else {
        if (angle != angle) {
            return D_8010C270;
        } else {
            return D_8010C350;
        }
    }
}

/* guTranslateF: build a 4x4 float translation matrix by (x, y, z) (the identity from
 * guMtxIdentF, then the translation row mf[3][0..2]). */
void func_801C61A0(s32 *mf, f32 x, f32 y, f32 z) {
    func_801C5440(mf);
    ((f32 *)mf)[12] = x; /* mf[3][0] */
    ((f32 *)mf)[13] = y; /* mf[3][1] */
    ((f32 *)mf)[14] = z; /* mf[3][2] */
}

/* guTranslate: build a fixed-point translation matrix by (x, y, z) in `packedMatrix`
 * (guTranslateF, inlined, then guMtxF2L). */
void func_801C61F4(u32 *packedMatrix, f32 x, f32 y, f32 z) {
    Matrix4f floatMatrix;
    f32 (*rows)[4] = floatMatrix;

    func_801C5440((s32 *)rows);
    rows[3][0] = x;
    rows[3][1] = y;
    rows[3][2] = z;
    func_801C5300((f32 *)rows, packedMatrix);
}

/* Original compiler padding. */
const u32 D_801C6264_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* guSprite2DInit: fill a 0x14-byte uSprite_t (Sprite2D microcode sprite descriptor) field by field. */
void func_801C6270(u8 *sprite, s32 sourceImage, s32 tlut, s16 stride, u16 subImageWidth, u16 subImageHeight, u8 imageType, u8 imageBitSize, u16 offsetS, u16 offsetT) {
    *(s32 *)(sprite + 0x0) = sourceImage;     /* SourceImagePointer */
    *(s32 *)(sprite + 0x4) = tlut;            /* TlutPointer */
    *(s16 *)(sprite + 0x8) = stride;          /* Stride */
    *(u16 *)(sprite + 0xA) = subImageWidth;   /* SubImageWidth */
    *(u16 *)(sprite + 0xC) = subImageHeight;  /* SubImageHeight */
    *(u8 *)(sprite + 0xE) = imageType;        /* SourceImageType */
    *(u8 *)(sprite + 0xF) = imageBitSize;     /* SourceImageBitSize */
    *(u16 *)(sprite + 0x10) = offsetS;        /* SourceImageOffsetS */
    *(u16 *)(sprite + 0x12) = offsetT;        /* SourceImageOffsetT */
}


