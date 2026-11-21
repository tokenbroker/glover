#ifndef LIBGCC_ARITHMETIC_H
#define LIBGCC_ARITHMETIC_H

#include "common.h"

/* N64 big-endian view of a 64-bit value as two 32-bit words. */
typedef union {
    struct {
        /* 0x00 */ u32 high;
        /* 0x04 */ u32 low;
    } s;
    /* 0x00 */ u64 ll;
} UInt64Words; /* size = 0x08 */

typedef UInt64Words DIunion;

enum LibgccArithmeticConstants {
    LIBGCC_WORD_BITS = 32
};

/*
 * func_801D3B60 is libgcc's __udivmoddi4: unsigned 64-bit division with
 * an optional remainder output. The divisor-zero path deliberately divides
 * by zero. Normalization shifts the divisor's highest set bit to bit 31.
 *
 * D_8010C070 is __clz_tab: byte bit lengths (0, 1, 2, 2, 3, ...).
 * count_leading_zeros uses this table to normalize a nonzero divisor word.
 * udiv_qrnnd divides a two-word numerator by a normalized one-word divisor,
 * returning a one-word quotient and remainder; numerator high < divisor.
 * sub_ddmmss subtracts two word pairs and propagates the low-word borrow.
 * These macros remain in the source with their original statement grouping.
 */

#endif /* LIBGCC_ARITHMETIC_H */
