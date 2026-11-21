#include "common.h"

/* Peripheral Interface status register (libultra rcp.h) */
#define PI_STATUS_REG 0xA4600010
#define PI_STATUS_DMA_BUSY 0x01
#define PI_STATUS_IO_BUSY 0x02

s32 func_8010D9B4(void);
void func_8010D9C0(s32);

extern volatile s32 D_801F5680;

void func_8010D8D0(void);
void func_8010C988(s32*, s32);
extern s8 D_801F59B0;
extern u8 D_801F59B2;
extern s32 D_801F5808;
u32 func_8010C9C0(s32 *);
void func_8010C9FC(s32);
void func_8010CF54(s32);

s32 func_8010D39C(s32, s32, s32, s32);

void func_8010CD28(s32, s32, s32);

void func_8012A738(s32, s32, s32);
void func_80122F9C(void);
void func_8012C2B0(u8*, s32, s32);
void func_8010FB80(s8);
void func_8010E558(void);
extern s32 D_801E64C8;
extern s16 D_801E753C;
extern s16 D_801E753E;
extern u8 D_80092030[];
extern u8 D_800B7830[];
extern u8 D_8010048C[];

#include "credits.h"
#include "debug_monitor.h"

extern unkEAF00 D_801EAF00[];
extern u32 D_801EAF04[];
extern u32 D_801EAF04[];
void func_80146CC8(s32);

void func_8013FBC0(u8*, s32);
void func_8011F9F4(void);
extern s32 D_801E589C;
extern u8 D_801000C4[];
extern u8 D_801EAAEC[];
extern s16 D_801EAB24;
extern u8 D_801EAA55[];
extern s32 D_801E58A4;
extern s32 D_801E58B4;
extern s32 D_801E58A8;
extern s32 D_801E747C;
extern s32 D_801E6608;
extern f32 D_801E6598;
extern f32 D_801001F4;
extern f32 D_801001F8;
extern f32 D_8010021C;

typedef struct MenuEntry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} MenuEntry; /* size 0x14 */

typedef struct MenuState {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ u32 cur;
    /* 0x20 */ u32 prev;
    /* 0x24 */ MenuEntry entries[1];
} MenuState;

extern f32 D_801F9214;
extern f32 D_801F9218;
extern s32 D_801F9220;
extern s32 D_801F9224;
extern f32 D_801E5890;
extern s32 D_801F613C;
extern s32 D_801F63FC;
extern s32 D_801F6400;
s32 func_801793DC(s32, u8, u8, u8);

void func_8011FF08(u8*);
extern u8 D_801F6440[];
extern s32 D_801E64CC;

void func_8014A50C(u8*, u8*, s32, s32, s32, s32);
extern u8 D_801000D0[];
extern u8 D_801000DC[];
extern f32 D_801000E8;
extern f32 D_801000EC;
extern s32 D_801E64C0;
extern f32 D_801F644C;
extern s32 D_801F6458;
extern s32 D_801F645C;
extern s8 D_801F6460;
extern s8 D_801F6461;
extern s8 D_801F6462;
extern s32 D_801F64AC;
extern f32 D_801F64C0;
extern s32 D_801F64CC;
extern s32 D_801F64D0;
extern s8 D_801F64D4;
extern s8 D_801F64D5;
extern s8 D_801F64D6;
extern s32 D_801F6520;

extern f32 D_801000F0;
extern f32 D_801000F4;
extern f32 D_801000F8;
extern f32 D_801000FC;
extern f32 D_80100100;
extern f32 D_801E64C4;
extern s32 D_801F6528;
extern u8 D_801F64B4[];

extern f32 D_80100104;
extern f32 D_80100108;
extern f32 D_8010010C;
extern f32 D_80100110;
extern f32 D_80100114;

extern f32 D_80100118;
extern f32 D_8010011C;
extern f32 D_80100120;
extern f32 D_80100124;
extern f64 D_80100128;
extern s32 D_801E5894;
extern f32 D_801F6450;
extern f32 D_801F64C4;
extern s16 D_801E7658;
void func_801C066C(s32, s16);

void func_80141720(void *);

s32 func_80147000(s32);
extern s32 D_801E64B8;
extern s32 D_801E64BC;
extern s8 D_801F6330;
extern u8 D_801F6331;
extern s8 D_801F6332;
extern u8 D_801F6333;
extern s8 D_801F63A8;
extern u8 D_801F63A9;
extern u8 D_801F63AA;
extern u8 D_801F63AB;

extern f32 D_801E652C[];
extern f32 D_801E654C[];
extern f32 D_801E656C[];
extern s32 D_80269F40[];
extern f32 D_80100168;
extern f32 D_8010016C;
extern s32 D_801F6128;
extern s32 D_801F612C;
extern s32 D_801F6130;
extern s32 D_801F6134;
extern s32 D_801E64F8;
extern f32 D_801F60A0;
extern f32 D_801F60A4;
extern f32 D_801F60A8;
extern f32 D_801F60AC;
extern f32 D_801F6430;
extern f32 D_801F6434;
extern f32 D_801F6438;
extern f32 D_801F643C;

extern f32 D_80100170;
extern f32 D_80100174;
extern f32 D_80100178;
extern f64 D_80100180;
extern f32 D_80100184;
extern f32 D_80100188;
extern f32 D_8010018C;
extern f64 D_80100190;
extern f32 D_801E658C;
extern s32 D_801E650C[];
extern s32 D_801F6138;
extern s32 D_801E5898;
extern s32 D_801F6124[];
extern f32 D_80100194;
extern f32 D_80100198;
extern f64 D_801001A0;
extern f32 D_801001A4;
extern f64 D_801001A8;
extern f32 D_801001B0;
extern s32 D_801E64FC[];
extern f32 D_801E64E8[];

void func_801625F0(s32, s32);
extern s32 D_801EC860;
void *func_8013FCDC(s32, s32, void *);
void func_80142928(void *, s32, f32, f32, f32, s32);
void func_8015C350(u8 *, u8 *);
extern u8 D_80100160[];

typedef struct { s32 unk0; s32 count; struct { s32 unk0; s32 unk4; } *items; s32 unkC; } Unk8011CAF8List;
typedef struct ListNode { struct ListNode *next; } ListNode;
extern Unk8011CAF8List D_8028F82C[];
extern struct { struct { s32 unk0; s32 unk4; } *items; s32 pad[3]; } D_8028F834[];
extern u8 D_8028F8E0[];
extern u8 D_8028F9CC[];
extern u8 D_802B0D10[];
extern u8 D_80100150[];
extern f32 D_8010015C;
extern u8 D_801F9208[];
extern s32 D_8028FAF4;
extern ListNode D_8028D9C0;
extern ListNode D_802892D8;
void func_80145D88(void);
void func_8010F94C(void);
void func_80141874(void);
void func_8014A9D8(void);
void func_8014ABEC(void);
void func_8015C758(void);
void func_8014A9FC(void);
void func_80188F90(void);
void func_801779F0(void);
void func_80162694(s32);
void func_8011C810(void);
void func_8011FD80(void);
void func_801456DC(void);
void func_801627AC(s32);
void func_8013FC38(s32, s32);
void func_80150EA4(s32);
void func_80162BE0(void);
void func_8010EBE8(void);
void func_80155A44(u8*);
void func_8011FB8C(void);
void func_8011FF40(s8);
extern u8 D_801001B8[];
extern s8 D_801E7531;
extern s8 D_801EC7A7;

void func_8011D88C(s32);
extern u8 D_801001C4[];
extern s8 D_801E7530;

extern s32 D_801E58B0;
extern s32 D_802004E0;
extern s32 D_801E6680;
extern s8 D_801EFC92;
extern f32 D_801ED3BC;
extern s32 D_801E668C;
extern u8 D_801F652B;
extern f32 D_80100694;
extern f32 D_80100698;
void func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
extern u8 D_801001D0[];
extern u8 D_801001D8[];
extern f32 D_801001E4;
extern f32 D_801001E8;
extern u8 D_801ED3C4[];
extern s32 D_8028FAC8;
extern u8 D_801ED403;
extern s16 D_801ED404;
extern s16 D_801ED406;
extern u8 D_801F6040[];
extern u8 D_802991A0[];
extern s32 D_801E58B8;
extern s16 D_801E6590;
extern u8 D_80202218;
extern struct { s16 f; u8 pad[398]; } D_801FAA92[];
extern struct { u8 f; u8 pad[399]; } D_801FAAC6[];
extern struct { u8 f; u8 pad[399]; } D_801FAAC7[];
extern struct { u8 f; u8 pad[399]; } D_801FAAC9[];
void func_801890EC(u8 *, s32, s32, s32, s32, s32, s32, f32, f32, s32);
void func_80188FD8(u8 *);
void func_801891E4(u8 *, s32, s32, s32);
void func_801B6370(void);
void func_80177A14(s32);
void func_80155AE4(u8 *);
void func_80125040(void);
void func_8010F9C0(s32 *);
void func_8010E6AC(void);

/* __osDisableInt: clear the CPU's interrupt-enable bit (SR.IE) and return its previous state. */
s32 func_8010C920(void) {
    s32 sr = func_8010D9B4(); /* __osGetSR */
    func_8010D9C0(sr & -2);   /* __osSetSR(sr & ~SR_IE) */
    return sr & 1;
}

/* __osRestoreInt: OR the interrupt-enable state saved by __osDisableInt
 * (func_8010C920) back into the CPU status register (__osGetSR / __osSetSR). */
void func_8010C958(s32 savedInterrupts) {
    func_8010D9C0(func_8010D9B4() | savedInterrupts);
}

/* osPiWriteIo-style register write: wait until the PI is idle (no DMA or I/O in flight), then store value at addr. */
void func_8010C988(s32 *addr, s32 value) {
    while (*(volatile u32*)PI_STATUS_REG & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}
    *addr = value;
}

/* Read a word over the PI bus (cartridge/debug space): wait until
 * PI_STATUS_REG (0xA4600010) shows neither DMA_BUSY (1) nor IO_BUSY (2), then load it. */
u32 func_8010C9C0(s32 *address) {
    while (*(volatile u32 *)0xA4600010 & (1 | 2)) {}
    return *address;
}

/* Debug monitor delay: busy-waits for `iterations` loop passes, counting in the
 * volatile global D_801F5680 so the loop isn't optimised away. */
void func_8010C9FC(s32 iterations) {
    for (D_801F5680 = 0; D_801F5680 < iterations; D_801F5680++) {}
}

/*
 * Debug monitor "PI read byte": read one byte from word-access-only PI-bus
 * memory (debug host / cartridge) at `address`. Reads the containing word
 * (func_8010C9C0, waits for PI idle) and extracts the big-endian byte lane
 * `address` selects.
 */
s32 func_8010CA44(s32 address) {
    s32 shift = (~address & 3) << 3; /* byte 0 is the most significant lane */
    u32 word = func_8010C9C0((s32*)(address & -4));
    return (word >> shift) & 0xFF;
}

/*
 * Copy `length` bytes from PI-bus space (debug host / cartridge memory) at
 * `piAddress` to RAM at `dest`: a byte at a time (func_8010CA44) until the
 * source is word aligned, then whole words (func_8010C9C0, which waits for the
 * PI to go idle) split big-endian into bytes, then the tail a byte at a time.
 */
void func_8010CA84(s32 piAddress, u8 *dest, u32 length) {
    u8 *dst;
    u32 count;
    s32 src;

    src = piAddress;
    dst = dest;
    count = length;
    if (count != 0) {
        while (count != 0 && (src & 3) != 0) {
            s32 byteAddress = src;
            src++;
            *dst = func_8010CA44(byteAddress);
            dst++;
            count--;
        }
    }
    if (count >= 4) {
        do {
            u32 word = func_8010C9C0((s32 *)src);
            *dst++ = word >> 24;
            *dst++ = word >> 16;
            *dst++ = word >> 8;
            *dst++ = word;
            src += 4;
            count -= 4;
        } while (count >= 4);
    }
    if (count != 0) {
        do {
            s32 byteAddress = src;
            src++;
            *dst = func_8010CA44(byteAddress);
            dst++;
            count--;
        } while (count != 0);
    }
}

/* Write one byte to any address with a word read-modify-write (big-endian
 * byte lane), for memory that only takes 32-bit accesses. */
void func_8010CB60(s32 address, s32 value) {
    s32 shift = (~address & 3) << 3;
    s32 *word = (s32 *)(address & -4);
    *word = (*word & ~(0xFF << shift)) | ((value & 0xFF) << shift);
}

/*
 * Copy `length` bytes from PI-bus space (debug host / cartridge memory) at
 * `piAddress` to `ramAddress`, writing each byte with a word
 * read-modify-write (func_8010CB60) so the destination may be word-only
 * memory. Aligned stretches are read a word at a time (func_8010C9C0, which
 * waits for the PI), the unaligned head and tail a byte at a time
 * (func_8010CA44).
 */
void func_8010CB9C(s32 piAddress, s32 ramAddress, u32 length) {
    u32 remaining;
    s32 from;
    s32 to;
    u32 word;

    from = piAddress;
    to = ramAddress;
    remaining = length;
    if (remaining != 0) {
        while (remaining != 0 && (from & 3) != 0) {
            func_8010CB60(to++, func_8010CA44(from++) & 0xFF);
            remaining--;
        }
    }
    if (remaining >= 4) {
        do {
            word = func_8010C9C0((s32 *)from);
            func_8010CB60(to++, (word >> 24) & 0xFF);
            func_8010CB60(to++, (word >> 16) & 0xFF);
            func_8010CB60(to++, (word >> 8) & 0xFF);
            func_8010CB60(to++, word & 0xFF);
            from += 4;
            remaining -= 4;
        } while (remaining >= 4);
    }
    if (remaining != 0) {
        s32 readAddress = from;
        do {
            func_8010CB60(to++, func_8010CA44(readAddress) & 0xFF);
            from++;
            readAddress = from;
            remaining--;
        } while (remaining != 0);
    }
}

/*
 * Write one byte to word-access-only PI-bus memory (debug host / cartridge) at
 * `address`: read the containing word (func_8010C9C0, waits for PI idle),
 * replace the big-endian byte lane `address` selects, and write the word back
 * (func_8010C988).
 */
void func_8010CCB0(s32 address, u8 value) {
    s32 shift = (~address & 3) << 3; /* byte 0 is the most significant lane */
    s32 word;

    address &= -4;
    word = func_8010C9C0((s32 *)address);
    func_8010C988((s32 *)address, (word & ~(0xFF << shift)) | ((value & 0xFF) << shift));
}

/* Copy count bytes from src into word-access-only memory at dstAddress: single bytes
 * (func_8010CCB0, a read-modify-write of the containing word) until dst is word-aligned,
 * then whole big-endian words (func_8010C988), then the remaining tail bytes. */
void func_8010CD28(s32 dstAddress, s32 srcAddress, s32 byteCount) {
    s32 dst = dstAddress;
    u8 *src = (u8 *)srcAddress;
    u32 count = byteCount;
    u32 word;

    if (count != 0) {
        while (count != 0 && (dst & 3) != 0) {
            func_8010CCB0(dst++, *src++);
            count--;
        }
    }
    if (count >= 4) {
        do {
            word = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3];
            func_8010C988((s32 *)dst, word);
            dst += 4;
            src += 4;
            count -= 4;
        } while (count >= 4);
    }
    if (count != 0) {
        do {
            func_8010CCB0(dst++, *src++);
            count--;
        } while (count != 0);
    }
}

/* Fill `length` bytes of word-access-only PI memory at `address` with `value`:
 * single bytes (func_8010CCB0, a read-modify-write of the containing word) until
 * the address is word-aligned, then whole words of four copies of the byte
 * (func_8010C988), then the remaining tail bytes. */
void func_8010CE14(s32 address, s32 value, u32 length) {
    u32 count;
    s32 dst;
    s32 fillWord;
    s32 fillByte;

    dst = address;
    count = length;
    fillByte = value;
    if (count != 0) {
        while (count != 0 && (dst & 3) != 0) {
            func_8010CCB0(dst++, fillByte & 0xFF);
            count--;
        }
    }
    if (count >= 4) {
        s32 b = fillByte & 0xFF;
        fillWord = (b << 24) | (b << 16) | (b << 8) | b;
        do {
            func_8010C988((s32 *)dst, fillWord);
            count -= 4;
            dst += 4;
        } while (count >= 4);
    }
    if (count != 0) {
        do {
            func_8010CCB0(dst++, fillByte & 0xFF);
            count--;
        } while (count != 0);
    }
}

/*
 * Copy `length` bytes from PI-bus address `srcAddress` to `dstAddress` one
 * byte at a time: read with func_8010CA44, write with func_8010CCB0 (a word
 * read-modify-write), so both ends may be word-access-only memory.
 */
void func_8010CEE0(s32 dstAddress, s32 srcAddress, s32 length) {
    s32 remaining;

    for (remaining = length - 1; remaining != -1; remaining--) {
        func_8010CCB0(dstAddress++, func_8010CA44(srcAddress++) & 0xFF);
    }
}

extern u8 D_8F1F5690[];
extern u32 D_801E5840[];
extern u32 D_801E5844[];
void func_8010CE14(s32 arg0, s32 arg1, u32 arg2);
void func_8010CEE0(s32 arg0, s32 arg1, s32 arg2);
/* Transfer debugger memory through the host buffer, honoring each range's access flags. */
void func_8010CF54(s32 direction) {
    u32 targetAddress;
    u32 bytesRemaining;
    s32 hostAddress;
    u32 chunkSize;
    hostAddress = DEBUG_HOST_BUFFER;
    targetAddress = func_8010C9C0((s32 *)DEBUG_MEMORY_ADDRESS);
    bytesRemaining = func_8010C9C0((s32 *)DEBUG_MEMORY_LENGTH);
    if (targetAddress > DEBUG_MEMORY_DIRECT_ADDRESS_MAX) targetAddress += (s32)D_8F1F5690;
    if (bytesRemaining != 0) {
        do {
            s32 rangeIndex = 0;
            s32 scanOffset;
            s32 rangeOffset;
            u32 addressBeforeStart;
            if (D_801E5840[0] < targetAddress) {
                scanOffset = 0;
                do {
                    scanOffset += DEBUG_MEMORY_RANGE_STRIDE;
                    rangeIndex++;
                } while (*(u32 *)((u8 *)D_801E5840 + scanOffset) < targetAddress);
            }
            rangeOffset = rangeIndex * DEBUG_MEMORY_RANGE_STRIDE;
            addressBeforeStart = targetAddress - 1;
            chunkSize = *(u32 *)((u8 *)D_801E5840 + rangeOffset) - addressBeforeStart;
            if (bytesRemaining < chunkSize) chunkSize = bytesRemaining;
            if ((*(s32 *)((u8 *)D_801E5844 + rangeOffset) & direction) == 0) {
                if (direction != DEBUG_MEMORY_READ) goto nextRange;
                func_8010CE14(hostAddress, 0, chunkSize);
            } else {
                s32 rangeFlags = *(s32 *)((u8 *)D_801E5844 + rangeOffset);
                if ((rangeFlags & DEBUG_MEMORY_RANGE_PI) != 0) {
                    if (direction == DEBUG_MEMORY_READ) func_8010CEE0(hostAddress, targetAddress, chunkSize);
                    else func_8010CEE0(targetAddress, hostAddress, chunkSize);
                } else if (direction == DEBUG_MEMORY_READ) func_8010CD28(hostAddress, targetAddress, chunkSize);
                else if ((rangeFlags & DEBUG_MEMORY_RANGE_WORD_WRITES) != 0) func_8010CB9C(hostAddress, targetAddress, chunkSize);
                else func_8010CA84(hostAddress, (u8 *)targetAddress, chunkSize);
            }
        nextRange:
            hostAddress += chunkSize;
            bytesRemaining -= chunkSize;
            targetAddress += chunkSize;
        } while (bytesRemaining != 0);
    }
}

/* Initialize the debug monitor with interrupts off: clear the host command and target reply mailbox words,
 * set the stop reason to 1 (initialized) and permit resume. */
void func_8010D104(void) {
    s32 interruptsWereEnabled = func_8010C920();
    func_8010D8D0();
    func_8010C988((s32 *)DEBUG_HOST_COMMAND, DEBUG_COMMAND_IDLE);
    func_8010C988((s32 *)DEBUG_TARGET_REPLY, DEBUG_REPLY_DONE);
    D_801F59B0 = 1;
    D_801F59B2 = DEBUG_RESUME_ENABLED;
    func_8010C958(interruptsWereEnabled);
}

/* Service development-host debugger commands until a permitted resume request. */
void func_8010D170(void) {
    s32 keepPolling;
    u32 command;

    do {
        keepPolling = 1;
        for (;;) {
            command = func_8010C9C0((s32 *)DEBUG_HOST_COMMAND);
            if (command != DEBUG_COMMAND_IDLE) {
                break;
            }
            func_8010C9FC(DEBUG_COMMAND_POLL_DELAY);
        }
        if (command == DEBUG_COMMAND_CANCEL) {
            func_8010C988((s32 *)DEBUG_TARGET_REPLY, DEBUG_REPLY_DONE);
            func_8010C9FC(DEBUG_COMMAND_POLL_DELAY);
        } else {
            func_8010C988((s32 *)DEBUG_TARGET_REPLY, DEBUG_REPLY_ACCEPTED);
            while (func_8010C9C0((s32 *)DEBUG_HOST_COMMAND) == command) {
                func_8010C9FC(DEBUG_HANDSHAKE_POLL_DELAY);
            }
            if (func_8010C9C0((s32 *)DEBUG_HOST_COMMAND) == DEBUG_COMMAND_CANCEL) {
                func_8010C988((s32 *)DEBUG_TARGET_REPLY, DEBUG_REPLY_DONE);
            } else {
                switch (command) {
                case DEBUG_COMMAND_NOP:
                    break;
                case DEBUG_COMMAND_RETURN:
                    keepPolling = 0;
                    break;
                case DEBUG_COMMAND_HALT_DISABLE_INTERRUPTS:
                    D_801F5808 &= DEBUG_CLEAR_BIT_ZERO_MASK;
                    D_801F59B0 = 0;
                    D_801F59B2 = 0;
                    func_8010D9C0(func_8010D9B4() & DEBUG_CLEAR_BIT_ZERO_MASK);
                    break;
                case DEBUG_COMMAND_HALT_CLEAR_REASON:
                    D_801F59B2 = 0;
                    D_801F59B0 = 0;
                    break;
                case DEBUG_COMMAND_ENABLE_RESUME:
                    D_801F59B2 = DEBUG_RESUME_ENABLED;
                    break;
                case DEBUG_COMMAND_DISABLE_RESUME:
                    D_801F59B2 = 0;
                    break;
                case DEBUG_COMMAND_READ_STATE:
                    func_8010C988((s32 *)DEBUG_HOST_BUFFER, (D_801F59B2 << 24) | (*(u8 *)&D_801F59B0 << 16));
                    break;
                case DEBUG_COMMAND_WRITE_MEMORY:
                    func_8010CF54(DEBUG_MEMORY_WRITE);
                    break;
                case DEBUG_COMMAND_READ_MEMORY:
                    func_8010CF54(DEBUG_MEMORY_READ);
                    break;
                }
                func_8010C988((s32 *)DEBUG_TARGET_REPLY, DEBUG_REPLY_DONE);
                while (func_8010C9C0((s32 *)DEBUG_HOST_COMMAND) == DEBUG_COMMAND_HOST_ACK) {
                    func_8010C9FC(DEBUG_HANDSHAKE_POLL_DELAY);
                }
            }
        }
    } while (keepPolling != 0 || D_801F59B2 == 0);
}

/* Break into the debugger; the exception handler services host commands, then resumes.
 * The original's `break 1` has no C equivalent in GCC 2.7.2 (no __builtin_trap). */
#define DEBUG_TRAP() asm("break 1")

/* Make a host call: write the three arguments, then the call number, and poll
 * until the host clears the call word. If the host posts a debugger command
 * meanwhile, withdraw the call, trap into the debugger, then reissue it.
 * Returns the host's result word. */
s32 func_8010D39C(s32 call, s32 arg0, s32 arg1, s32 arg2) {
    func_8010C988((s32 *)DEBUG_HOST_CALL_ARG0, arg0);
    func_8010C988((s32 *)DEBUG_HOST_CALL_ARG1, arg1);
    func_8010C988((s32 *)DEBUG_HOST_CALL_ARG2, arg2);
    func_8010C988((s32 *)DEBUG_HOST_CALL, call);
    do {
        func_8010C9FC(DEBUG_COMMAND_POLL_DELAY);
        if (func_8010C9C0((s32 *)DEBUG_HOST_COMMAND) != DEBUG_COMMAND_IDLE) {
            func_8010C988((s32 *)DEBUG_HOST_CALL, 0);
            DEBUG_TRAP();
            func_8010C988((s32 *)DEBUG_HOST_CALL, call);
        }
    } while (func_8010C9C0((s32 *)DEBUG_HOST_CALL) != 0);
    return func_8010C9C0((s32 *)DEBUG_HOST_CALL_RESULT);
}

/* Returns the size of a NUL-terminated string including its terminator (strlen + 1). */
s32 func_8010D470(u8 *str) {
    u8 *ptr = str + 1;
    if (*str != 0) {
        do {} while (*ptr++ != 0);
    }
    return (s32)(ptr - str);
}

/* Host debugger init: with interrupts off (func_8010C920 / func_8010C958), make the
 * host init call (func_8010D39C) and return the host's result. */
s32 func_8010D490(void) {
    s32 savedInterrupts = func_8010C920();
    s32 result = func_8010D39C(DEBUG_HOST_CALL_INIT, 0, 0, 0);
    func_8010C958(savedInterrupts);
    return result;
}

/* Host debugger open(path, mode): with interrupts off (func_8010C920 /
 * func_8010C958), copy the NUL-terminated path (length from func_8010D470,
 * terminator included) into the host file buffer and make the host call.
 * Returns the host's 16-bit result sign-extended: a file handle, or negative on error. */
s32 func_8010D4DC(s32 path, s32 mode) {
    s32 savedInterrupts = func_8010C920();
    s32 pathLength = func_8010D470((u8*)path);
    s32 result;
    func_8010CD28(DEBUG_HOST_FILE_BUFFER, path, pathLength);
    result = func_8010D39C(DEBUG_HOST_CALL_OPEN, pathLength, mode, 0);
    if (result & 0x8000) {
        result |= (s32)0xFFFF0000;
    }
    func_8010C958(savedInterrupts);
    return result;
}

/* Host debugger create(path, mode): like func_8010D4DC (open), but the host
 * creates the file. Returns the sign-extended 16-bit handle, negative on error. */
s32 func_8010D56C(s32 path, s32 mode) {
    s32 savedInterrupts = func_8010C920();
    s32 pathLength = func_8010D470((u8*)path);
    s32 result;
    func_8010CD28(DEBUG_HOST_FILE_BUFFER, path, pathLength);
    result = func_8010D39C(DEBUG_HOST_CALL_CREATE, pathLength, mode, 0);
    if (result & 0x8000) {
        result |= (s32)0xFFFF0000;
    }
    func_8010C958(savedInterrupts);
    return result;
}

/* Host debugger close(fd): with interrupts off (func_8010C920 / func_8010C958),
 * make the host close call (func_8010D39C). Returns the host's 16-bit result
 * sign-extended: 0 on success, negative on error. */
s32 func_8010D5FC(s32 fd) {
    s32 savedInterrupts = func_8010C920();
    s32 result = func_8010D39C(DEBUG_HOST_CALL_CLOSE, fd, 0, 0);
    if (result & 0x8000) {
        result |= 0xFFFF0000;
    }
    func_8010C958(savedInterrupts);
    return result;
}

s32 func_8010D664(s32 fd, s32 buffer, s32 count) {
    s32 savedInterrupts;
    s32 totalBytes;
    s32 bytesRead;
    s32 chunkSize;
    /* Host read(fd, buffer, count) in 32 KB chunks; returns bytes read. (An early stop leaves interrupts disabled.) */
    savedInterrupts = func_8010C920();
    totalBytes = 0;

    if (count != 0) {
        do {
            chunkSize = count;
            if ((u32)count > (u32)DEBUG_HOST_IO_CHUNK) {
                chunkSize = DEBUG_HOST_IO_CHUNK;
            }
            bytesRead = func_8010D39C(DEBUG_HOST_CALL_READ, fd, chunkSize, 0);
            if (bytesRead == 0) {
                return totalBytes;
            }
            func_8010CA84(DEBUG_HOST_FILE_BUFFER, buffer, bytesRead);
            buffer += bytesRead;
            count -= bytesRead;
            totalBytes += bytesRead;
        } while (count != 0);
    }

    func_8010C958(savedInterrupts);
    return totalBytes;
}

s32 func_8010D728(s32 fd, s32 buffer, s32 count) {
    s32 savedInterrupts;
    s32 totalBytes;
    s32 chunkSize;
    s32 written;
    /* Host write(fd, buffer, count) in 32 KB chunks; returns bytes written. (An early stop leaves interrupts disabled.) */
    savedInterrupts = func_8010C920();
    totalBytes = 0;

    if (count != 0) {
        do {
            chunkSize = count;
            if ((u32)count > (u32)DEBUG_HOST_IO_CHUNK) {
                chunkSize = DEBUG_HOST_IO_CHUNK;
            }
            func_8010CD28(DEBUG_HOST_FILE_BUFFER, buffer, chunkSize);
            written = func_8010D39C(DEBUG_HOST_CALL_WRITE, fd, chunkSize, 0);
            if (written == 0) {
                return totalBytes;
            }
            buffer += written;
            count -= written;
            totalBytes += written;
        } while (count != 0);
    }

    func_8010C958(savedInterrupts);
    return totalBytes;
}

/* Host lseek(fd, offset, whence) through the debug mailbox, with interrupts
 * disabled around the call; returns the host's result. */
s32 func_8010D7F0(s32 fd, s32 offset, s32 whence) {
    s32 savedInterrupts = func_8010C920();
    s32 result = func_8010D39C(DEBUG_HOST_CALL_SEEK, fd, offset, whence);
    func_8010C958(savedInterrupts);
    return result;
}


void func_8010D874(void);










void func_8010E0D0(void);

s32 func_8010E0D8(void);

s32 func_8010E174(void);

void func_8010E2B4(void);

void func_8010E2F4(void);

void func_8010E400(void);

void func_8010E558(void);

void func_8010E560(void);

void func_8010E6AC(void);

extern u32 D_801E64D4;
extern s16 D_801E64D8;
extern u16 D_801EC7DA;
extern u8 D_801ED400;
extern u8 D_801ED401;
extern u8 D_801ED402;
extern u8 D_80100130[];
extern u8 D_8010013C[];
extern u8 D_80100144[];
extern s32 D_80000300;
extern u8 *D_801F6098;
extern u8 D_8028F7DC[];
extern u8 D_801F1B24[];
void func_8014F510(s32);
void func_8014AA20(void *);
s32 func_80139CA0(void *);
void func_8014FCF8(void *, s32, s32);
void func_8014D4D0(void);
s32 func_8014D5E0(void);
void func_8014D548(void);
void func_8011C810(void);

s32 func_8010E86C(void);

s32 func_8010EB14(void);

void func_8010EBE8(void);

void func_8010EEF8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, s32 arg10);

void func_8010F0B8(s32 arg0);

void func_8010F1AC(s32 arg0);

void func_8010F23C(s32 arg0);

void func_8010F520(s32 arg0);

void func_8010F94C(void);

typedef struct {
    s32 unk0;
    s32 pad[58];
} D910Val;
extern D910Val D_801E58DC[];
typedef s32 (*D910Fn)(s32 *);
typedef struct {
    D910Fn fn[8];
    s32 unk20;
    s32 pad[50];
} D910Entry;
extern D910Entry D_801E58BC[];
extern s32 D_801F6138;
extern s32 D_801F613C;
extern f32 D_801E58A0;
extern f32 D_801001B4;
s32 func_8010FC10(s32 *);

void func_8010F9C0(s32 *arg0);

void func_8010FB30(void);

void func_8010FB80(s8 arg0);

s32 func_8010FC10(s32 *arg0);

void func_8010FC84(void);

s32 func_801100B8(u32 *arg0, MenuState *m);
static inline void split_externs_801100B8(void) { extern f32 D_801001E8; }


extern u8 D_801003B4[];
extern u8 D_801003C0[];
extern const f32 D_801003D0;
extern const f32 D_801003D4;
extern const f32 D_801003D8;
extern const f32 D_801003DC;
extern const f32 D_801003E0;
extern const f32 D_801003E4;
extern const f32 D_801003E8;
extern const f32 D_801003EC;
extern s32 D_801E65B4;
extern s32 D_80269F44;
extern s32 D_80269F48;
void func_80133998(s32, s32, s32, s32, f32);
void func_80142700(s32, s32);
void func_8010EEF8(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32);

extern s32 D_801E65A0;
extern s32 D_801E65A4;
extern s16 D_801F6864;
extern u8 D_801003F0[];
extern u8 D_801F65A8[];
extern s32 D_801E65AC;
extern s32 D_801E65B0;
extern s32 D_801F6C88;
s32 func_80110598();
void func_8010F23C(s32);
extern s16 D_801E7586;
extern f32 D_801E58A0;
extern s32 D_801E65A8;
extern s32 D_801E65B8;
extern s32 D_801E6614;
extern s32 D_801E6618;
extern s32 D_801E661C;
extern f32 D_801E6610[];
extern s32 D_801F6860;
extern s32 D_801EAE70[];
extern u8 D_801EAA44[];
void func_80145680(s32);
s32 func_80112808(s32);
void func_8012519C(void);
f32 func_801C6000(f32);

typedef struct MenuSprite {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0x6C];
} MenuSprite; /* size 0x74 */

typedef struct SaveSlot {
    /* 0x00 */ s32 w[7];
} SaveSlot; /* size 0x1C */

typedef struct MenuObj {
    /* 0x00 */ u8 pad0[0x26];
    /* 0x26 */ s16 alpha;
    /* 0x28 */ u8 pad28[0x50];
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ f32 unk80;
    /* 0x84 */ u8 pad84[0x38];
    /* 0xBC */ f32 unkBC;
    /* 0xC0 */ f32 unkC0;
    /* 0xC4 */ f32 unkC4;
} MenuObj;

typedef struct MenuCtx {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 cur;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
} MenuCtx;

typedef struct MenuItem {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u8 pad10[0x8];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
    /* 0x24 */ u8 pad24[0x50];
} MenuItem; /* size 0x74, the D_801F65A8 table */

/* float -> u32 the way the compiler expands an unsigned conversion, with the 2^31 pool entry named */
#define TO_U32C(f, c) (!((c) <= (f)) ? (s32)(f) : (0x80000000 | (s32)((f) - (c))))

void func_80110520(void);

extern const f32 D_80100244;
extern const f32 D_80100248;
extern const f32 D_8010024C;
extern const f32 D_80100250;
extern const f32 D_80100254;
extern const f32 D_80100258;
extern const f32 D_8010025C;
extern const f32 D_80100260;
extern const f32 D_80100264;
extern const f32 D_80100268;
extern const f32 D_8010026C;
extern const f32 D_80100270;
extern const f32 D_80100274;
extern const f64 D_80100278;
extern const f32 D_80100280;
extern const f32 D_80100284;
extern const f32 D_80100288;
extern const f32 D_8010028C;
extern const f64 D_801002A8;
extern const f64 D_801002B0;
extern const f32 D_801002B8;
extern const f32 D_801002BC;
extern const f64 D_801002C0;
extern const f32 D_801002C8;
extern const f32 D_801002D0;
extern const f32 D_801002D8;
extern const f32 D_801002E4;
extern const f32 D_801002E8;
extern const f32 D_801002EC;
extern const f32 D_801002F0;
extern const f32 D_801002F4;
extern const f32 D_801002F8;
extern const f32 D_801002FC;
extern const f32 D_80100300;
extern const f32 D_80100304;
extern const f32 D_80100308;
extern const f32 D_8010030C;
extern const f32 D_80100310;
extern const f32 D_80100314;
extern const f32 D_80100318;
extern const f32 D_8010031C;
extern const f32 D_80100320;
extern const f32 D_80100324;
extern const f32 D_80100328;
extern const f32 D_8010032C;
extern const f32 D_80100330;
extern const f32 D_80100334;
extern const f32 D_80100338;
extern const f32 D_8010033C;
extern const f32 D_80100340;
extern const f32 D_80100344;
extern const f32 D_80100348;
extern const f32 D_8010034C;
extern const f32 D_80100350;
extern const f32 D_80100354;
extern const f32 D_80100358;
extern const f32 D_8010035C;
extern const f32 D_80100360;
extern const f32 D_80100364;
extern const f32 D_80100368;
extern const f32 D_8010036C;
extern const f32 D_80100370;
extern const f32 D_80100374;
extern const f32 D_80100378;
extern const f32 D_8010037C;
extern const f32 D_80100380;
extern const f32 D_80100384;
extern const f32 D_80100388;
extern const f32 D_8010038C;
extern const f32 D_80100390;
extern const f32 D_8010039C;
extern s32 D_801EAD5C[];
extern s32 D_801EADF8[][3];
extern s32 D_801EAE04[];
extern s32 D_801EAE34[];
extern s32 D_801EAE40[];
extern s32 D_801EAE4C[];
extern s32 D_801EAE88[];
extern s32 D_801EAA48[];
extern s32 D_801EAA4C[];
extern s32 D_801EAA50[];
extern u8 D_801EAA54[];
extern f32 D_801F65B4;
extern f32 D_801F6628;
extern f32 D_801F669C;
extern f32 D_801F6710;
extern f32 D_801F6784;
extern f32 D_801F67F8;
extern MenuSprite D_801F65C4[];
extern u8 D_801F65CB[];
void func_801D2150(u8 *, ...);
void func_80132CAC(void);
void func_80132DA8(void);
#define ROW_U8(i, k) ((D_801F65A8 + (k))[mm])
#define ROW_S32(i, k) (*(s32 *)&(D_801F65A8 + (k))[mm])

s32 func_80112338(s32 arg0, s32 *arg1);

s32 func_801126C4(s32 arg0, u8 *arg1);

extern u8 D_801EAA44[];
extern u8 D_80100424[];
extern u8 D_801F1CD4[];
extern u8 *D_801F9278;
extern s32 D_801F9274;
extern const f32 D_80100430;
extern s32 D_801EC7F0;
extern s32 D_801F922C;
void func_80145680(s32);

s32 func_80112808(s32 arg0);


void func_80112830(void);

extern u8 D_80100434[];
extern u8 D_8010043C[];
extern u8 D_80100448[];
extern u8 D_80100458[];
extern const f32 D_80100468;
extern const f32 D_8010046C;
extern const f32 D_80100470;
extern const f32 D_80100474;
extern const f32 D_80100478;
extern const f32 D_8010047C;
extern const f32 D_80100480;
extern const f32 D_80100484;
extern const f32 D_80100488;
extern s32 D_801E6614;
extern s32 D_801E6618;
extern s32 D_801E661C;
extern s32 D_801E6620;
extern s32 D_801E660C;
extern f32 D_801E6598;
void func_80142700(s32, s32);
void func_80133998(s32, s32, s32, s32, f32);

s32 func_801128C8(s32 arg0, s32 *arg1);

s32 func_80112E18(void *arg0, u8 *arg1);

s32 func_80112F80();

/* float -> u32 the way the compiler expands an unsigned conversion */
#define TO_U32(f) (!(D_801004AC <= (f)) ? (s32)(f) : (0x80000000 | (s32)((f) - D_801004AC)))
#define TO_U32H(f, hb) (!(D_801004AC <= (f)) ? (s32)(f) : ((hb) | (s32)((f) - D_801004AC)))
/* alpha of an unselected menu entry, kept in `a` so the sign bit survives the u8 truncation */
#define FADE_ALPHA_U8(c, t, a) \
    ((D_801F6138 < 2 && !(D_801004A4 < ((c) - D_801F60A0) * D_801004A4 / D_801004A8)) \
         ? ((((t) = (D_801004A8 - D_801F60A0) * D_801004A4 / D_801004A8) < 0.0f) ? 0 : (u8)((a) = TO_U32(t), (a))) \
         : 0xFF)
#define FADE_ALPHA_U8H(c, t, a, hb) \
    ((D_801F6138 < 2 && !(D_801004A4 < ((c) - D_801F60A0) * D_801004A4 / D_801004A8)) \
         ? ((((t) = (D_801004A8 - D_801F60A0) * D_801004A4 / D_801004A8) < 0.0f) ? 0 : (u8)((a) = TO_U32H(t, hb), (a))) \
         : 0xFF)
/* the same conversions with the constants held in locals (big = 2^31, hb = sign bit, f255 = 255, f110 = 110) */
#define TO_U32L(f, big, hb) (!((big) <= (f)) ? (s32)(f) : ((hb) | (s32)((f) - (big))))
#define FADE_ALPHA_U8L(c, t, a, f255, f110, big, hb) \
    ((D_801F6138 < 2 && !((f255) < ((c) - D_801F60A0) * (f255) / (f110))) \
         ? ((((t) = ((f110) - D_801F60A0) * (f255) / (f110)) < 0.0f) ? 0 : (u8)((a) = TO_U32L(t, big, hb), (a))) \
         : 0xFF)
#define FADE_SCALEL(c, t, f255, f110) \
    ((D_801F6138 < 2 && !((f255) < ((c) - D_801F60A0) * (f255) / (f110))) \
         ? ((((t) = ((f110) - D_801F60A0) * (f255) / (f110)) < 0.0f) ? 0.0f : (t)) \
         : (f255))
/* the same fade as a float factor */
#define FADE_SCALE(c, t) \
    ((D_801F6138 < 2 && !(D_801004A4 < ((c) - D_801F60A0) * D_801004A4 / D_801004A8)) \
         ? ((((t) = (D_801004A8 - D_801F60A0) * D_801004A4 / D_801004A8) < 0.0f) ? 0.0f : (t)) \
         : D_801004A4)

extern s16 D_801E7586;
extern f32 D_801E58A0;
extern s32 D_801F6C88;
f32 func_801C6000(f32);
void func_8012643C(void);
void func_8012519C(void);
void func_80180644(void);

extern u8 D_801005D8[];
extern f32 D_801005DC;
extern f32 D_801ED3BC;
extern u8 D_801EAAFD;
extern s32 D_801F21A8;
extern u8 D_801E662C;
extern s32 D_801EC7F0;
void func_801BB9AC(s32, s32);
void func_8012BEE0(void);

s32 func_80112F58(void);

extern const f32 D_8010049C;
extern const f32 D_801004A0;
extern const f32 D_801004A4;
extern const f32 D_801004A8;
extern const f32 D_801004AC;
extern const f64 D_801004B0;
extern const f32 D_801004B8;
extern const f32 D_801004BC;
extern const f64 D_801004C0;
extern const f64 D_801004C8;
extern const f64 D_801004D0;
extern const f64 D_801004D8;
extern const f32 D_801004E0;
extern const f32 D_801004E4;
extern const f32 D_801004E8;
extern const f32 D_801004EC;
extern const f32 D_801004F0;
extern const f32 D_801004F4;
extern const f32 D_801004F8;
extern const f32 D_801004FC;
extern const f32 D_80100500;
extern const f32 D_80100504;
extern const f32 D_80100508;
extern const f32 D_8010050C;
extern const f64 D_80100510;
extern const f32 D_80100518;
extern const f32 D_8010051C;
extern const f32 D_80100520;
extern const f32 D_80100524;
extern const f32 D_80100528;
extern const f32 D_8010052C;
extern const f64 D_80100530;
extern const f32 D_80100538;
extern const f32 D_8010053C;
extern const f32 D_80100540;
extern const f32 D_80100544;
extern const f32 D_80100548;
extern const f32 D_8010054C;
extern const f64 D_80100550;
extern const f32 D_80100558;
extern const f32 D_8010055C;
extern const f32 D_80100560;
extern const f32 D_80100564;
extern const f32 D_80100568;
extern const f32 D_8010056C;
extern const f64 D_80100570;
extern const f32 D_80100578;
extern const f32 D_8010057C;
extern const f32 D_80100580;
extern const f32 D_80100584;
extern const f32 D_80100588;
extern const f32 D_8010058C;
extern const f64 D_80100590;
extern const f64 D_80100598;
extern const f64 D_801005A0;
extern const f64 D_801005A8;
extern const f64 D_801005B0;
extern const f32 D_801005B8;
extern const f32 D_801005C4;
extern const f32 D_801005C8;
extern const f32 D_801005D4;
extern s32 D_801E65C8[];
extern s32 D_801E65D8[];
extern s32 D_801E65DC;
extern s32 D_801E65E0;
extern s32 D_801E65E4;
extern f32 D_801E65E8[];
extern f32 D_801E65F8[];
typedef struct unkF69DC {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ u8 pad4[0x70];
} unkF69DC; /* size 0x74 */

extern unkF69DC D_801F69DC[];
extern u8 D_801E6624;
extern u8 D_801E6625;
extern u8 D_801E6626;
extern s32 D_801E6628;
extern u8 D_801E7584;
extern s32 D_801EAD20[][3];
extern s32 D_801EADC8[];
extern f32 D_801E6610[];
extern s32 D_80269F50;
extern u8 D_801FB108;
extern u32 D_80297BEC;
extern s32 D_80269F4C;

typedef struct MenuIcon {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ f32 unk80;
    /* 0x84 */ u8 pad84[0x18];
    /* 0x9C */ u8 unk9C[1];
} MenuIcon;
s32 func_80112F80(u32 *arg0, MenuState *arg1);
#define FADE_ALPHA_U8G(c, t, a, hb) \
    ((D_801F6138 < 2 && !(D_801004A4 < ({ f32 tt = D_801F60A0; (c) - tt; }) * D_801004A4 / D_801004A8)) \
         ? ((((t) = (D_801004A8 - D_801F60A0) * D_801004A4 / D_801004A8) < 0.0f) ? 0 : (u8)TO_U32S(t, hb, a)) \
         : 0xFF)
#define TO_U32R(f, hb) (!(D_801004AC <= (f)) ? (s32)(f) : ((s32)((f) - D_801004AC) | (hb)))
#define TO_U32S(f, hb, a) ({ if (!(D_801004AC <= (f))) (a) = (s32)(f); else { (a) = (s32)((f) - D_801004AC); (a) |= (hb); } (a); })

s32 func_801145A4(void);

extern f32 D_80100624;
extern f32 D_80100628;
extern s32 D_801F6CB0;
extern s32 D_801F6C9C;
extern s16 D_801F6CA0;
extern f32 D_801F6CB4;
extern f32 D_801F6CB8;


extern f32 D_80100684;
extern s32 D_801E6680;
extern s8 D_801EFC92;
extern f32 D_801ED3BC;
extern s32 D_801E5898;

void func_80145680(s32);

void func_80114740(void);

extern f32 D_8010062C;
extern f32 D_80100630;
extern f32 D_80100634;
extern f32 D_80100638;
extern f32 D_8010063C;
extern f32 D_80100640;
extern f32 D_80100644;
extern f32 D_80100648;
extern f32 D_8010064C;
extern f32 D_80100650;
extern f32 D_80100654;
extern f32 D_80100658;
extern f32 D_8010065C;
extern f32 D_80100660;
extern f32 D_80100664;
extern f32 D_80100668;
extern f32 D_8010066C;
extern f32 D_80100670;
extern f32 D_80100674;
extern f32 D_80100678;
extern f32 D_8010067C;
extern f32 D_80100680;
void func_80114784(void);

s32 func_80114C5C(void);

s32 func_80114CC0(s32 *arg0, s32 arg1);
static inline void split_externs_80114CC0(void) { extern f32 D_801F9214; extern f32 D_80100688; extern f32 D_8010068C; extern f32 D_80100690; extern s32 D_801EAF0C[]; }

s32 func_80114F64(void);

s32 func_80115144(u8 *arg0, s32 arg1);
static inline void split_externs_80115144(void) { extern u8 D_801F6CC8[]; }

s32 func_801151C8(u8 *arg0, s32 arg1);
static inline void split_externs_801151C8(void) { extern u8 D_8010069C[]; extern u8 D_801006AC[]; extern u8 D_801006BC[]; extern u8 D_801006C8[]; extern f32 D_801006D8; extern f32 D_801006DC; extern f32 D_801006E0; extern f32 D_801006E4; extern f32 D_801006E8; extern f32 D_801006EC; extern s32 D_801F6C90; extern s32 D_801F6C94; extern s32 D_801F6CA8; extern s32 D_801F6CAC; extern s32 D_801F6CC0; extern s32 D_801F6CC4; extern s32 D_801F6DB0; extern s32 D_801E6694; extern s32 D_801E669C; extern u8 D_801F6CC8[]; extern u8 D_801F6D5F; extern s32 D_801E6690; extern s32 D_801E6644; extern s32 D_801E6648; extern f32 D_801E6638; extern f32 D_801E663C; extern s32 D_801F6CA4; extern f32 D_801E6698; }

void func_8011541C(s32 arg0, s32 arg1);
static inline void split_externs_8011541C(void) { extern f32 D_801E6698; extern const f32 D_80100700; extern const f32 D_80100704; extern const f32 D_80100708; extern const f32 D_8010070C; extern const f32 D_80100710; extern const f32 D_80100714; extern u8 D_801006F0[]; extern u8 D_801006F4[]; extern u8 D_801006F8[]; extern s16 D_801E7586; extern s32 D_801EABF0[]; }

f32 func_801C6000(f32);
s32 func_80115CE4(u32 *arg0, MenuState *arg1);
static inline void split_externs_80115CE4(void) { extern const f32 D_8010071C; extern const f32 D_80100720; extern const f32 D_80100724; extern const f32 D_80100728; extern const f32 D_8010072C; extern const f32 D_80100730; extern const f32 D_80100734; extern const f32 D_80100738; extern const f32 D_8010073C; extern const f32 D_80100740; extern const f32 D_80100748; extern const f32 D_80100754; extern const f32 D_80100758; extern const f32 D_8010075C; extern const f32 D_80100760; extern const f32 D_80100764; extern const f32 D_80100768; extern const f32 D_8010076C; extern const f32 D_80100770; extern const f32 D_80100778; extern const f32 D_80100784; extern const f32 D_80100788; extern const f32 D_8010078C; extern const f32 D_80100790; extern const f32 D_80100794; extern const f32 D_80100798; extern const f32 D_8010079C; extern const f64 D_801007A0; extern const f32 D_801007A8; extern const f32 D_801007B4; extern const f32 D_801007B8; extern const f32 D_801007BC; extern const f64 D_801007C0; extern const f32 D_801007C8; extern const f32 D_801007CC; extern const f32 D_801007D0; extern const f32 D_801007D4; extern const f32 D_801007D8; extern const f32 D_801007DC; extern const f32 D_801007E0; extern const f32 D_80100804; extern const f32 D_80100808; extern const f32 D_8010080C; extern const f32 D_80100810; extern const f32 D_80100834; extern u8 D_80100718[]; extern s16 D_801E7586; extern s32 D_801EAE70[]; extern s32 D_801F6CE0; extern s32 D_801F6CE4; extern s32 D_801F6D54; extern s32 D_801F6D58; extern s32 D_801E6644; extern s32 D_801E6648; extern s32 D_801F6CC0; extern s32 D_801F6CC4; extern f32 D_801F6CBC; extern s32 D_801E6640; extern u8 D_801F6D5F; extern u8 D_801F6CEB; extern s32 D_801F6DB0; extern f32 D_801E6630; extern f32 D_801E6634; extern f32 D_801E6638; extern f32 D_801E663C; extern f32 D_801E58A0; extern u8 D_801FAA90[]; extern s32 D_801E66A0; extern s32 D_801E6690; extern f32 D_801E6694; extern f32 D_801E6698; extern f32 D_801E669C; extern s32 D_801F6CA4; extern f32 D_801F6CD4; extern f32 D_801F6D48; extern s32 D_801F6C90; extern s32 D_801F6C94; extern u8 D_801F6C97; extern s32 D_801F6CA8; extern s32 D_801F6CAC; extern s32 D_801EAD8C[]; extern s32 D_801EAD80[]; extern s32 D_801EABA8[]; extern s32 D_801EABB4[]; extern s32 D_801EABC0[]; extern s32 D_801EABCC[]; extern s32 D_801EABD8[]; extern s32 D_801EABE4[]; extern u8 D_801EA9EB[]; extern u8 D_801EA9E8[]; extern s32 D_801EA9E4[]; }

void func_80116F4C(void);

