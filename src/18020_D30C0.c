#include "common.h"
#include "structs.h"

typedef PrintfLongDiv LongDiv;

typedef PrintfLongLongDiv LongLongDiv;

/* strchr: return a pointer to the first `ch` in the string `str`, or NULL if the terminator comes first. */
u8 *func_801D20C0(u8 *str, u8 ch) {
    u16 c = *str;
    while ((u8)c != ch) {
        if (!c) {
            return NULL;
        }
        c = *++str;
    }
    return str;
}

/* strlen: length of a NUL-terminated string. */
s32 func_801D20F8(u8 *str) {
    u8 *end = str;
    if (*end != 0) {
        do {
            end++;
        } while (*end != 0);
    }
    return end - str;
}

/* memcpy (libultra/libc): copies `count` bytes from src to dst and returns dst. */
void *func_801D211C(void *dst, u8 *src, u32 count)
{
    u8 *out = dst;
    if (count != 0) {
        do {
            *out++ = *src++;
        } while (--count != 0);
    }
    return dst;
}

/* Original compiler padding. */
const u32 D_801D2144_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

typedef char *va_list;
#define va_start(ap, last) ((ap) = (va_list)__builtin_next_arg(last))

typedef PrintfFieldArgs PutfldArgs;

#define PUTFLD_ARG(ap, T) (*(T *)(((ap) = (char *)((((s32)(ap)) + sizeof(T) - 1) & -sizeof(T)) + sizeof(T)) - sizeof(T)))

/* _Putfld: convert one printf argument into text segments and zero counts. */
void func_801D2750(PutfldArgs *x, va_list *pap, u8 code, u8 *ac);
extern u8 D_8010C730[];    /* Printf flag characters: " +-#0". */
extern s32 D_8010C738[];   /* Corresponding PrintfFormatFlags bits, then zero. */
extern u8 D_8010C750[];    /* Printf length qualifiers: "hlL". */
extern u8 D_801F5600[];    /* Block of 32 spaces for field padding. */
extern u8 D_801F5624[];    /* Block of 32 ASCII zeros for numeric padding. */

#define _PROUT(buf, n) \
    if ((n) > 0) { \
        arg = prout(arg, buf, n); \
        if (arg == 0) { \
            return x.nchar; \
        } \
        x.nchar += (n); \
    }
#define _PAD(m, src) \
    { \
        s32 i, j; \
        for (j = (m); j > 0; j -= i) { \
            i = j > 32 ? 32 : j; \
            _PROUT(src, i); \
        } \
    }

s32 func_801D21A8();
s32 func_801D21E0();

/* sprintf: format into dst through _Printf (func_801D21E0) with the
 * memcpy-and-advance callback proutSprintf (func_801D21A8), then
 * NUL-terminate. Returns the number of characters written. */
s32 func_801D2150(u8 *dst, u8 *format, ...)
{
    va_list args;
    s32 length;

    va_start(args, format);
    length = func_801D21E0(func_801D21A8, dst, format, args);
    if (length >= 0) {
        dst[length] = 0;
    }
    return length;
}

/* proutSprintf: sprintf's output callback. Copies count bytes of formatted
 * text to dst (memcpy) and returns the position just past them. */
s32 func_801D21A8(void *dst, u8 *src, u32 count)
{
    func_801D211C(dst, src, count);
    return (s32)((u8 *)dst + count);
}

/* Original compiler padding. */
const u32 D_801D21DC_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

s32 func_801D21E0(char *(*prout)(char *, u8 *, u32), char *arg, u8 *formatString, va_list arguments) {
    /* _Printf: emit formatted arguments through prout, advancing its arg context;
     * x holds the current field and total count; func_801D20C0 is strchr. */
#define PR_PUT(s, n)                                     \
    if (0 < (n)) {                                       \
        if ((arg = (*prout)(arg, (u8 *)(s), n)) != NULL) \
            x.nchar += (n);                              \
        else                                             \
            return x.nchar;                              \
    }
#define PR_PAD(s, n)                                                  \
    if (0 < (n)) {                                                    \
        int i, j = (n);                                               \
        for (; 0 < j; j -= i) {                                       \
            i = 32 < (unsigned int)j ? (int)32 : j;                   \
            PR_PUT(s, i);                                             \
        }                                                             \
    }
#define PR_ISDIGIT(x) ((x >= '0' && x <= '9'))
    PrintfFieldArgs x;

    x.nchar = 0;
    while (1) {
        const u8 *cursor;
        u8 character;
        const u8 *flagMatch;
        u8 fieldBuffer[32];

        cursor = (const u8 *)formatString;
        for (character = *cursor; character != 0 && character != '%';) {
            character = *++cursor;
        }
        PR_PUT(formatString, cursor - (const u8 *)formatString);
        if (character == 0) {
            return x.nchar;
        }
        formatString = (u8 *)++cursor;
        for (x.flags = 0; (flagMatch = (const u8 *)func_801D20C0(D_8010C730, *cursor)) != NULL; cursor++) {
            x.flags |= D_8010C738[flagMatch - (const u8 *)D_8010C730];
        }
        if (*cursor == '*') {
            x.width = PUTFLD_ARG(arguments, s32);
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= PRINTF_LEFT_JUSTIFY;
            }
            cursor++;
        } else
            for (x.width = 0; PR_ISDIGIT(*cursor); ++cursor) {
                if (x.width < 999)
                    x.width = x.width * 10 + *cursor - '0';
            }
        if (*cursor != '.') {
            x.prec = -1;
        } else if (*++cursor == '*') {
            x.prec = PUTFLD_ARG(arguments, s32);
            ++cursor;
        } else
            for (x.prec = 0; PR_ISDIGIT(*cursor); cursor++) {
                if (x.prec < 999)
                    x.prec = x.prec * 10 + *cursor - '0';
            }
        x.qual = func_801D20C0(D_8010C750, *cursor) ? *cursor++ : '\0';
        if (x.qual == 'l' && *cursor == 'l') {
            x.qual = 'L';
            ++cursor;
        }
        func_801D2750(&x, &arguments, *cursor, fieldBuffer);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;
        {
            if (!(x.flags & PRINTF_LEFT_JUSTIFY)) {
                PR_PAD(D_801F5600, x.width);
            }
            PR_PUT(fieldBuffer, x.n0);
            PR_PAD(D_801F5624, x.nz0);
            PR_PUT(x.s, x.n1);
            PR_PAD(D_801F5624, x.nz1);
            PR_PUT(x.s + x.n1, x.n2);
            PR_PAD(D_801F5624, x.nz2);
            if (x.flags & PRINTF_LEFT_JUSTIFY) {
                PR_PAD(D_801F5600, x.width);
            }
        }
        formatString = (u8 *)cursor + 1;
    }
    return 0;
#undef PR_PUT
#undef PR_PAD
#undef PR_ISDIGIT
}

/* Consume one printf conversion and prepare its text segments, sign and padding. */
void func_801D2750(PrintfFieldArgs *field, va_list *arguments, u8 conversion, u8 *buffer)
{
    f64 floatValue;

    field->n0 = field->nz0 = field->n1 = field->nz1 = field->n2 = field->nz2 = 0;
    switch (conversion) {
    case 'c':
        buffer[field->n0++] = PUTFLD_ARG(*arguments, s32);
        break;
    case 'd':
    case 'i':
        if (field->qual == 'l') {
            field->v.ll = PUTFLD_ARG(*arguments, s32);
        } else if (field->qual == 'L') {
            field->v.ll = PUTFLD_ARG(*arguments, s64);
        } else {
            field->v.ll = PUTFLD_ARG(*arguments, s32);
        }
        if (field->qual == 'h') {
            field->v.ll = (s16)field->v.ll;
        }
        if (field->v.ll < 0) {
            buffer[field->n0++] = '-';
        } else if (field->flags & PRINTF_FORCE_SIGN) {
            buffer[field->n0++] = '+';
        } else if (field->flags & PRINTF_SPACE_SIGN) {
            buffer[field->n0++] = ' ';
        }
        field->s = (char *)(buffer + field->n0);
        func_801D2C10(field, conversion);
        break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (field->qual == 'l') {
            field->v.ll = PUTFLD_ARG(*arguments, s32);
        } else if (field->qual == 'L') {
            field->v.ll = PUTFLD_ARG(*arguments, s64);
        } else {
            field->v.ll = PUTFLD_ARG(*arguments, s32);
        }
        if (field->qual == 'h') {
            field->v.ll = (u16)field->v.ll;
        } else if (!field->qual) {
            field->v.ll = (u32)field->v.ll;
        }
        if (field->flags & PRINTF_ALTERNATE_FORM) {
            buffer[field->n0++] = '0';
            if (conversion == 'x' || conversion == 'X') {
                buffer[field->n0++] = conversion;
            }
        }
        field->s = (char *)(buffer + field->n0);
        func_801D2C10(field, conversion);
        break;
    case 'e':
    case 'f':
    case 'g':
    case 'E':
    case 'G':
        floatValue = PUTFLD_ARG(*arguments, f64);
        field->v.ld = floatValue;
        if (*(u16 *)&field->v.ld & PRINTF_DOUBLE_SIGN_MASK) {
            buffer[field->n0++] = '-';
        } else if (field->flags & PRINTF_FORCE_SIGN) {
            buffer[field->n0++] = '+';
        } else if (field->flags & PRINTF_SPACE_SIGN) {
            buffer[field->n0++] = ' ';
        }
        field->s = (char *)(buffer + field->n0);
        func_801D3020(field, conversion);
        break;
    case 'n':
        if (field->qual == 'h') {
            *PUTFLD_ARG(*arguments, s16 *) = field->nchar;
        } else if (field->qual == 'l') {
            *PUTFLD_ARG(*arguments, s32 *) = field->nchar;
        } else if (field->qual == 'L') {
            *PUTFLD_ARG(*arguments, s64 *) = field->nchar;
        } else {
            *PUTFLD_ARG(*arguments, s32 *) = field->nchar;
        }
        break;
    case 'p':
        field->v.ll = (s32)PUTFLD_ARG(*arguments, void *);
        field->s = (char *)(buffer + field->n0);
        func_801D2C10(field, 'x');
        break;
    case 's':
        field->s = PUTFLD_ARG(*arguments, char *);
        field->n1 = func_801D20F8(field->s);
        if (field->prec >= 0 && field->prec < field->n1) {
            field->n1 = field->prec;
        }
        break;
    case '%':
        buffer[field->n0++] = '%';
        break;
    default:
        buffer[field->n0++] = conversion;
        break;
    }
}

/* Original compiler padding. */
void func_801D3B40(s32, s32, s32, s32);
extern u8 D_801F5650[];
extern u8 D_801F5664[];
LongLongDiv func_801D2EE4(s64, s64);

const u32 D_801D2C0C_padding[] __attribute__((section(".text"))) = {
    0x00000000
};

u64 func_801D41A0(u64, u64);
/* Format integer digits and compute the leading zeros required by precision or width. */
void func_801D2C10(PrintfFieldArgs *field, u8 conversion)
{
    char digitBuffer[PRINTF_INTEGER_BUFFER_BYTES];
    u8 *digits;
    s32 base;
    s32 digitStart;
    u64 magnitude;

    digits = (conversion == 'X') ? D_801F5664 : D_801F5650;
    base = (conversion == 'o') ? 8 : ((conversion != 'x' && conversion != 'X') ? 10 : 16);
    digitStart = PRINTF_INTEGER_BUFFER_BYTES;
    magnitude = field->v.ll;

    if ((conversion == 'd' || conversion == 'i') && field->v.ll < 0) {
        magnitude = -magnitude;
    }

    if (magnitude != 0 || field->prec != 0) {
        char *digit = &digitBuffer[--digitStart];
        *digit = digits[magnitude % base];
    }

    field->v.ll = ((u64 (*)(u64, u64))func_801D3B40)(magnitude, base);

    while (field->v.ll > 0 && digitStart > 0) {
        PrintfLongLongDiv division = func_801D2EE4(field->v.ll, base);
        field->v.ll = division.quot;
        digitBuffer[--digitStart] = digits[division.rem];
    }

    field->n1 = PRINTF_INTEGER_BUFFER_BYTES - digitStart;
    func_801D211C(field->s, digitBuffer + digitStart, field->n1);

    if (field->n1 < field->prec) {
        field->nz0 = field->prec - field->n1;
    }

    if (field->prec < 0 && (field->flags & (PRINTF_LEFT_JUSTIFY | PRINTF_ZERO_PAD)) == PRINTF_ZERO_PAD) {
        if ((digitStart = field->width - field->n0 - field->nz0 - field->n1) > 0) {
            field->nz0 += digitStart;
        }
    }
}

/* Original compiler padding. */
const u32 D_801D2E54_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000, 0x00000000
};

/* ldiv (libc): quotient and remainder of num / den, with a negative quotient
 * corrected so the remainder never has the opposite sign of the result's rounding. */
LongDiv func_801D2E60(s32 num, s32 den) {
    LongDiv result;
    s32 quot = num / den;
    s32 rem = num - den * quot;

    result.quot = quot;
    result.rem = rem;
    if (quot < 0) {
        if (rem > 0) {
            result.quot = quot + 1;
            result.rem = rem - den;
        }
    }
    return result;
}

s64 func_801D3AA0(s64, s64);

/* lldiv: compute a signed 64-bit quotient and remainder, then apply the library's sign correction. */
PrintfLongLongDiv func_801D2EE4(s64 numerator, s64 denominator) {
    PrintfLongLongDiv result;

    result.quot = func_801D3AA0(numerator, denominator);
    result.rem = numerator - denominator * result.quot;
    if (result.quot < 0 && result.rem > 0) { result.quot++; result.rem -= denominator; } return result; }

typedef struct { u8 b[3]; } Str3;
typedef PrintfFloatArgs LdtobArgs;
extern f64 D_8010C8B0[];
extern Str3 D_8010C8F8;
extern Str3 D_8010C8FC;
extern f64 D_8010C900;
extern f64 D_8010C908;
extern char D_8010C910[]; /* printf zero digits: "0". */
s32 func_801D3460(s16 *, u16 *);
void func_801D34F8(LdtobArgs *, u8, char *, s16, s16);

/* Original compiler padding. */
const u32 D_801D3018_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

/* _Ldtob: generate and round decimal digits for printf, including zero, NaN and infinity. */
void func_801D3020(PrintfFloatArgs *format, u8 conversion) {
    u8 digitBuffer[PRINTF_DIGIT_BUFFER_BYTES];
    u8 *digits = digitBuffer;
    f64 value = format->d;
    s16 valueClass, exponent;
    s32 significantDigits;
    s32 blockDigitsLeft, digitCount, digitBlock;
    f64 *powerOfTen;

    if (format->prec < 0) {
        format->prec = PRINTF_DEFAULT_PRECISION;
    } else if (format->prec == 0 && (conversion == 'g' || conversion == 'G')) {
        format->prec = 1;
    }
    valueClass = func_801D3460(&exponent, (u16 *)format);
    if (valueClass > 0) {
        __builtin_memcpy(format->s, valueClass == PRINTF_DOUBLE_NAN ? &D_8010C8F8 : &D_8010C8FC, format->n1 = 3);
        return;
    }
    if (valueClass == PRINTF_DOUBLE_ZERO) {
        significantDigits = 0;
        exponent = 0;
        goto formatOutput;
    } else {
        if (value < 0.0) { value = -value; } else { significantDigits = 0; exponent = (s16)exponent; }
        exponent = exponent * PRINTF_LOG10_2_NUMERATOR / PRINTF_LOG10_2_DENOMINATOR - 4;
        if (exponent < 0) {
            s32 scaleExponent;
            scaleExponent = (-exponent + 3) & ~3;
            exponent = -scaleExponent;
            if (scaleExponent > 0) for (powerOfTen = D_8010C8B0; scaleExponent > 0; scaleExponent >>= 1, powerOfTen++) {
                if (scaleExponent & 1) {
                    value *= *powerOfTen;
                }
            }
        } else if (exponent > 0) {
            f64 scaleFactor = D_8010C900;
            s32 scaleExponent;
            exponent &= ~3;
            scaleExponent = exponent;
            if (scaleExponent > 0) for (powerOfTen = D_8010C8B0; scaleExponent > 0; scaleExponent >>= 1, powerOfTen++) {
                if (scaleExponent & 1) {
                    scaleFactor *= *powerOfTen;
                }
            }
            value /= scaleFactor;
        }
        digitCount = format->prec + 6;
        if (conversion == 'f') {
            s32 generationPrecision = format->prec + 10;
            digitCount = generationPrecision + exponent;
        }
        if (digitCount >= PRINTF_DECIMAL_DIGIT_LIMIT) {
            digitCount = PRINTF_DECIMAL_DIGIT_LIMIT - 1;
        }
        *digits++ = '0';
        while ((digitCount > 0) & (value > 0.0)) {
            digitBlock = (s32)value;
            digitCount -= PRINTF_DECIMAL_BLOCK_DIGITS;
            digits += PRINTF_DECIMAL_BLOCK_DIGITS;
            if (digitCount > 0) value = (value - digitBlock) * *(const f64 *)&D_8010C908;
            blockDigitsLeft = PRINTF_DECIMAL_BLOCK_DIGITS;
            for (; digitBlock > 0 && --blockDigitsLeft >= 0;) {
                    PrintfLongDiv division = func_801D2E60(digitBlock, 10);
                    *--digits = division.rem + '0';
                    digitBlock = division.quot;
            }
            for (; --blockDigitsLeft >= 0;) { *--digits = '0'; }
            digits += PRINTF_DECIMAL_BLOCK_DIGITS;
        }
        {
            u8 *lastDigit = digits - 1;
            digitCount = lastDigit - digitBuffer;
        }
        exponent += PRINTF_DECIMAL_BLOCK_DIGITS - 1;
        for (digits = digitBuffer + 1; *digits == '0'; digits++) {
            exponent--;
            digitCount--;
        }
    }
    {
        digitBlock = format->prec;
        if (conversion == 'f') {
            s32 precisionWithIntegerDigit = digitBlock + 1;
            significantDigits = precisionWithIntegerDigit + exponent;
        } else {
            significantDigits = digitBlock + (conversion == 'e' || conversion == 'E');
        }
    }
    if (digitCount < (s16)significantDigits) {
        significantDigits = digitCount;
    }
    if ((s16)significantDigits > 0) {
        u8 roundingDigit = '0';
        s32 roundIndex;
        if ((s16)significantDigits < digitCount) {
            roundingDigit = (digits[(s16)significantDigits] >= '5') ? '9' : '0';
        }
        for (roundIndex = (s16)significantDigits - 1; digits[roundIndex] == roundingDigit; roundIndex--) {
            significantDigits--;
        }
        if (roundingDigit == '9') {
            digits[roundIndex]++;
        }
        if (roundIndex < 0) {
            digits--;
            significantDigits++;
            exponent++;
        }
    }
formatOutput:
    func_801D34F8(format, conversion, (char *)digits, significantDigits, exponent);
}

/* libc _Dunscale: splits the double at px (as 4 halfwords, big-endian) into its binary
 * exponent (*pex) and a mantissa left in px. Returns -1 (finite), 0 (zero or denormal),
 * 1 (infinity) or 2 (NaN). */
s32 func_801D3460(s16 *pex, u16 *px)
{
    u16 *ps = px;
    s16 xchar = (ps[0] & 0x7FF0) >> 4;

    if (xchar == 0x7FF) {
        *pex = 0;
        return ((ps[0] & 0xF) || ps[1] || ps[2] || ps[3]) ? 2 : 1;
    } else if (0 < xchar) {
        ps[0] = (ps[0] & 0x800F) | 0x3FF0;
        *pex = xchar - 0x3FE;
        return -1;
    }
    if (xchar < 0) {
        return 2;
    } else {
        *pex = 0;
        return 0;
    }
}

/* Format significant digits as fixed/scientific printf output and record zero-padding runs. */
void func_801D34F8(PrintfFloatArgs *format, u8 conversion, char *digits, s16 significantDigits, s16 decimalExponent)
{
    if (significantDigits <= 0) {
        significantDigits = 1;
        digits = D_8010C910;
    }
    if (conversion == 'f' || ((conversion == 'g' || conversion == 'G') && decimalExponent >= -4 && decimalExponent < format->prec)) {
        decimalExponent++;
        if (conversion != 'f') {
            if (!(format->flags & PRINTF_ALTERNATE_FORM)) {
                if (significantDigits < format->prec) {
                    format->prec = significantDigits;
                }
            }
            if ((format->prec -= decimalExponent) < 0) {
                format->prec = 0;
            }
        }
        if (decimalExponent <= 0) {
            format->s[format->n1++] = '0';
            if (format->prec > 0 || (format->flags & PRINTF_ALTERNATE_FORM)) {
                format->s[format->n1++] = '.';
            }
            if (format->prec < -decimalExponent) {
                decimalExponent = -format->prec;
            }
            format->nz1 = -decimalExponent;
            format->prec += decimalExponent;
            if (format->prec < significantDigits) {
                significantDigits = format->prec;
            }
            func_801D211C(format->s + format->n1, digits, format->n2 = significantDigits);
            format->nz2 = format->prec - significantDigits;
        } else if (significantDigits < decimalExponent) {
            func_801D211C(format->s + format->n1, digits, significantDigits);
            format->n1 += significantDigits;
            format->nz1 = decimalExponent - significantDigits;
            if (format->prec > 0 || (format->flags & PRINTF_ALTERNATE_FORM)) {
                format->s[format->n1] = '.';
                format->n2++;
            }
            format->nz2 = format->prec;
        } else {
            func_801D211C(format->s + format->n1, digits, decimalExponent);
            format->n1 += decimalExponent;
            significantDigits -= decimalExponent;
            if (format->prec > 0 || (format->flags & PRINTF_ALTERNATE_FORM)) {
                format->s[format->n1++] = '.';
            }
            if (format->prec < significantDigits) {
                significantDigits = format->prec;
            }
            func_801D211C(format->s + format->n1, digits + decimalExponent, significantDigits);
            format->n1 += significantDigits;
            format->nz1 = format->prec - significantDigits;
        }
    } else {
        if (conversion == 'g' || conversion == 'G') {
            if (significantDigits < format->prec) {
                format->prec = significantDigits;
            }
            if ((format->prec -= 1) < 0) {
                format->prec = 0;
            }
            conversion = (conversion == 'g') ? 'e' : 'E';
        }
        format->s[format->n1++] = *digits++;
        if (format->prec > 0 || (format->flags & PRINTF_ALTERNATE_FORM)) {
            format->s[format->n1++] = '.';
        }
        if (format->prec > 0) {
            significantDigits--;
            if (format->prec < significantDigits) {
                significantDigits = format->prec;
            }
            func_801D211C(format->s + format->n1, digits, significantDigits);
            format->n1 += significantDigits;
            format->nz1 = format->prec - significantDigits;
        }
        digits = format->s + format->n1;
        *digits++ = conversion;
        if (decimalExponent >= 0) {
            *digits++ = '+';
        } else {
            *digits++ = '-';
            decimalExponent = -decimalExponent;
        }
        if (decimalExponent >= 100) {
            if (decimalExponent >= 1000) {
                *digits++ = decimalExponent / 1000 + '0';
                decimalExponent %= 1000;
            }
            *digits++ = decimalExponent / 100 + '0';
            decimalExponent %= 100;
        }
        *digits++ = decimalExponent / 10 + '0';
        decimalExponent %= 10;
        *digits++ = decimalExponent + '0';
        format->n2 = digits - (format->s + format->n1);
    }
    if ((format->flags & (PRINTF_LEFT_JUSTIFY | PRINTF_ZERO_PAD)) == PRINTF_ZERO_PAD) {
        s32 fieldLength = format->n0 + format->n1 + format->nz1 + format->n2 + format->nz2;
        if (fieldLength < format->width) {
            format->nz0 = format->width - fieldLength;
        }
    }
}

/* Original compiler padding. */
const u32 D_801D3A98_padding[] __attribute__((section(".text"))) = {
    0x00000000, 0x00000000
};

typedef union {
    struct {
        s32 high;
        u32 low;
    } s;
    s64 ll;
} DSunion;

static inline s64 __negdi2(s64 u) {
    DSunion w;
    DSunion uu;

    uu.ll = u;

    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((u32)w.s.low > 0);

    return w.ll;
}


