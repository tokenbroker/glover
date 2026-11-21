#ifndef DEBUG_MONITOR_H
#define DEBUG_MONITOR_H

/*
 * Development-host debugger mailbox on the cartridge PI bus.
 * func_8010D170 services commands until return is requested and resume is enabled.
 * func_8010C9C0/func_8010C988 read/write a word after waiting for PI idle.
 * func_8010C9FC busy-waits for the supplied iteration count.
 * func_8010CF54 transfers memory: direction 1 reads target memory to the host
 * buffer; direction 2 writes the host buffer to target memory.
 * func_8010D9B4/func_8010D9C0 read/write the CPU CP0 Status register.
 *
 * D_801F59B0 is the stop reason: exception code, -1 for a debugger break,
 * or 1 after initialization/resume. D_801F59B2 permits resume when nonzero.
 * D_801F5808 is the HIGH word of the 64-bit saved CP0 Status slot at
 * D_801F5690 + 0x178. The original clears bit 0 of this word; preserve that
 * access rather than moving it to the low word at +0x17C.
 */
/*
 * Host calls (func_8010D39C): the target writes the arguments, then the call
 * number, and polls until the host clears the call word; the result is read
 * from DEBUG_HOST_CALL_RESULT. DEBUG_HOST_FILE_BUFFER carries file names and
 * file data.
 */
enum DebugMonitorMailbox {
    DEBUG_HOST_BUFFER = 0xB1FE0000,
    DEBUG_HOST_FILE_BUFFER = 0xB1FF0000,
    DEBUG_HOST_CALL_RESULT = 0xB1FFFFDC,
    DEBUG_HOST_CALL = 0xB1FFFFE0,
    DEBUG_HOST_CALL_ARG0 = 0xB1FFFFE4,
    DEBUG_HOST_CALL_ARG1 = 0xB1FFFFE8,
    DEBUG_HOST_CALL_ARG2 = 0xB1FFFFEC,
    DEBUG_HOST_COMMAND = 0xB1FFFFF0,
    DEBUG_MEMORY_ADDRESS = 0xB1FFFFF4,
    DEBUG_MEMORY_LENGTH = 0xB1FFFFF8,
    DEBUG_TARGET_REPLY = 0xB1FFFFFC
};

enum DebugMonitorCommand {
    DEBUG_COMMAND_IDLE = 0,
    DEBUG_COMMAND_HOST_ACK = 1,
    DEBUG_COMMAND_CANCEL = 2,
    DEBUG_COMMAND_NOP = 0x10,
    DEBUG_COMMAND_RETURN = 0x11,
    DEBUG_COMMAND_HALT_DISABLE_INTERRUPTS = 0x12,
    DEBUG_COMMAND_HALT_CLEAR_REASON = 0x13,
    DEBUG_COMMAND_ENABLE_RESUME = 0x14,
    DEBUG_COMMAND_DISABLE_RESUME = 0x15,
    DEBUG_COMMAND_READ_STATE = 0x16,
    DEBUG_COMMAND_WRITE_MEMORY = 0x17,
    DEBUG_COMMAND_READ_MEMORY = 0x18
};

/* Host file-I/O call numbers passed to func_8010D39C (call, arg0, arg1, arg2).
 * Read/write move at most DEBUG_HOST_IO_CHUNK bytes per call through
 * DEBUG_HOST_FILE_BUFFER and return the byte count (0 ends the transfer). */
enum DebugHostCall {
    DEBUG_HOST_CALL_INIT = 0x101,
    DEBUG_HOST_CALL_OPEN = 0x202,   /* (name length, mode), name in the file buffer */
    DEBUG_HOST_CALL_CREATE = 0x303, /* (name length, mode), name in the file buffer */
    DEBUG_HOST_CALL_CLOSE = 0x404,  /* (fd) */
    DEBUG_HOST_CALL_READ = 0x505,   /* (fd, count) */
    DEBUG_HOST_CALL_WRITE = 0x606,  /* (fd, count) */
    DEBUG_HOST_CALL_SEEK = 0x707,   /* (fd, offset, whence) */
    DEBUG_HOST_IO_CHUNK = 0x8000
};

enum DebugMonitorConstants {
    DEBUG_REPLY_DONE = 0,
    DEBUG_REPLY_ACCEPTED = 0x101,
    DEBUG_RESUME_ENABLED = 0xFF,
    DEBUG_MEMORY_READ = 1,
    DEBUG_MEMORY_WRITE = 2,
    DEBUG_COMMAND_POLL_DELAY = 1000,
    DEBUG_HANDSHAKE_POLL_DELAY = 500,
    DEBUG_CLEAR_BIT_ZERO_MASK = -2
};

/*
 * D_801E5840 and D_801E5844 address the inclusive end and flags of the
 * first 8-byte memory range record. Subsequent records follow at stride 8.
 * Read/write permission bits use DEBUG_MEMORY_READ/DEBUG_MEMORY_WRITE.
 *
 * func_8010CE14 fills PI memory; func_8010CEE0 copies bytes between PI
 * addresses. func_8010CD28 copies ordinary memory to PI memory.
 * func_8010CA84 copies PI memory to ordinary memory; func_8010CB9C does
 * the same using word read-modify-write stores (needed for RSP memory).
 * D_8F1F5690 is an address adjustment, not a dereferenced data object.
 */
enum DebugMemoryRangeConstants {
    DEBUG_MEMORY_RANGE_STRIDE = 8,
    DEBUG_MEMORY_RANGE_PI = 4,
    DEBUG_MEMORY_RANGE_WORD_WRITES = 8,
    DEBUG_MEMORY_DIRECT_ADDRESS_MAX = 0xEFFFFFFF
};

#endif
