#ifndef COMMON_H
#define COMMON_H

/* IDO (SGI MIPSpro) builds src/18020_C0800.c: GCC's extensions in the shared C are defined away for it, and the
   INCLUDE_ASM stubs expand to nothing (the functions stay in the expected object only). */
#ifdef __sgi
#define __attribute__(x)
#define inline
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"macro.inc\"\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#endif

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

typedef u32 uintptr_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif /* COMMON_H */
