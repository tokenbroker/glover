#!/usr/bin/env python3
"""Pack a piece's .text for linking at a 4-byte boundary: usage pack_text.py OBJ (an ELF32 big-endian object, edited in place).
Both assemblers give .text 16-byte alignment and pad its size to a multiple of 16. A unit cut into pieces
(tools/fable/split_unit.py) has pieces that start or end inside a 16-byte line, where the original single object had
no such padding: the linker would align the piece's start and the padding would push the next piece. This sets the
section's alignment to 4 and its size to the end of the last symbol in it (functions and padding blocks carry sizes),
so nothing but the assembler's tail padding is dropped."""
import struct, sys

path = sys.argv[1]
b = bytearray(open(path, "rb").read())
if b[:4] != b"\x7fELF" or b[4] != 1 or b[5] != 2: sys.exit(f"{path}: not an ELF32 big-endian object")
shoff, = struct.unpack_from(">I", b, 0x20)
shentsize, shnum, shstrndx = struct.unpack_from(">HHH", b, 0x2E)
def sh(i): return struct.unpack_from(">IIIIIIIIII", b, shoff + i * shentsize)
names_off = sh(shstrndx)[4]
def name(i):
    o = names_off + sh(i)[0]; return bytes(b[o:b.index(0, o)]).decode()
text = next(i for i in range(shnum) if name(i) == ".text")
_, _, _, _, _, size, _, _, align, _ = sh(text)
end = 0
for i in range(shnum):
    s = sh(i)
    if s[1] == 2:  # SHT_SYMTAB
        for k in range(s[5] // 16):
            st_name, value, ssize, info, other, shndx = struct.unpack_from(">IIIBBH", b, s[4] + k * 16)
            if shndx == text and (info & 0xF) in (1, 2): end = max(end, value + ssize)  # STT_OBJECT, STT_FUNC
    if s[1] == 9 and s[7] == text:  # SHT_REL against .text: no relocation may fall beyond the new end
        for k in range(s[5] // 8):
            off, = struct.unpack_from(">I", b, s[4] + k * 8); end = max(end, off + 4)
end = (end + 3) & ~3
if end == 0 or end > size: sys.exit(f"{path}: no sized symbols in .text (end 0x{end:X}, size 0x{size:X})")
if size - end >= 16: sys.exit(f"{path}: 0x{size - end:X} bytes after the last symbol, more than the assembler's padding")
struct.pack_into(">I", b, shoff + text * shentsize + 20, end)
struct.pack_into(">I", b, shoff + text * shentsize + 32, 4)
open(path, "wb").write(b)
