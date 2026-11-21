#!/usr/bin/env python3
"""Interim link step: point compiled code at the original read-only data block.

The C units still take most of their read-only data (strings, constants) from the
original block at 0x80100000 (asm/1000.s), but the compiler also emits its own copies
of jump tables and float constants into each object's .rodata. Linking those copies
makes the ROM longer than the original and shifts everything after them.

Until the read-only data is fully migrated into C, this script makes a link copy of
each C object (build/link/src/X.o) whose .text references to its own .rodata are
retargeted to the addresses the original ROM uses, read from baserom.z64. The
object's own .rodata is then parked in an unloaded section (see build/link/crodata.ld)
and never reaches the ROM. The objects in build/src/ are left untouched for objdiff.

Usage: link_rodata.py <glover.yaml> <baserom> <out_dir> <obj>...
"""
import re, struct, sys, os

PARK_BASE = 0x80400000  # one 64K slot per object; multiple of 0x10000


def unit_starts(yaml_path):
    starts = {}
    for line in open(yaml_path):
        m = re.match(r'\s*-\s*\[\s*(0x[0-9A-Fa-f]+)\s*,\s*c\s*(?:,\s*"?([\w]+)"?)?\s*\]', line)
        if m:
            off = int(m.group(1), 16)
            starts[m.group(2) or '%X' % off] = off
    return starts


def patch(obj_path, out_path, rom, rom_start, slot_addr):
    d = bytearray(open(obj_path, 'rb').read())
    assert d[:6] == b'\x7fELF\x01\x02', obj_path
    shoff, = struct.unpack_from('>I', d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from('>HHH', d, 0x2E)
    secs = [struct.unpack_from('>10I', d, shoff + i * shentsize) for i in range(shnum)]
    stro = secs[shstrndx][4]
    name = lambda s: bytes(d[stro + s[0]:d.index(b'\0', stro + s[0])]).decode()
    idx = {name(s): i for i, s in enumerate(secs)}
    if '.rodata' not in idx or '.rel.text' not in idx:
        open(out_path, 'wb').write(d)
        return 0
    ro, text, rel, symtab = idx['.rodata'], secs[idx['.text']], secs[idx['.rel.text']], secs[idx['.symtab']]
    n = 0
    pending = []  # HI16 relocs waiting for their LO16
    last_hi = None
    for i in range(rel[5] // 8):
        r_off, r_info = struct.unpack_from('>II', d, rel[4] + i * 8)
        st_value, = struct.unpack_from('>I', d, symtab[4] + (r_info >> 8) * 16 + 4)
        st_shndx, = struct.unpack_from('>H', d, symtab[4] + (r_info >> 8) * 16 + 14)
        rtype = r_info & 0xFF
        if st_shndx != ro:
            if rtype == 5:
                pending = []
            continue
        romw, = struct.unpack_from('>I', rom, rom_start + r_off)
        insn, = struct.unpack_from('>I', d, text[4] + r_off)
        if (romw ^ insn) >> 16:
            sys.exit('%s: instruction at .text+0x%X differs from the ROM' % (obj_path, r_off))
        if rtype == 5:
            pending.append(r_off)
            last_hi = romw & 0xFFFF
        elif rtype == 6:
            lo = romw & 0xFFFF
            target = (last_hi << 16) + (lo - 0x10000 if lo & 0x8000 else lo)
            addend = (target - slot_addr - st_value) & 0xFFFFFFFF
            struct.pack_into('>H', d, text[4] + r_off + 2, addend & 0xFFFF)
            for h in pending:
                struct.pack_into('>H', d, text[4] + h + 2, ((addend + 0x8000) >> 16) & 0xFFFF)
            pending = []
        else:
            sys.exit('%s: unexpected relocation type %d against .rodata' % (obj_path, rtype))
        n += 1
    assert not pending, obj_path
    open(out_path, 'wb').write(d)
    return n


def main():
    yaml_path, rom_path, out_dir = sys.argv[1:4]
    objs = sorted(sys.argv[4:])
    starts = unit_starts(yaml_path)
    rom = open(rom_path, 'rb').read()
    os.makedirs(out_dir, exist_ok=True)
    ld = []
    for i, obj in enumerate(objs):
        unit = os.path.basename(obj)[:-2]
        out = os.path.join(out_dir, unit + '.o')
        slot = PARK_BASE + i * 0x10000
        patch(obj, out, rom, starts[unit], slot)
        ld.append('    .crodata_%d 0x%X (NOLOAD) : { %s(.rodata); }' % (i, slot, out))
    open(os.path.join(out_dir, 'crodata.ld'), 'w').write('\n'.join(ld) + '\n')


if __name__ == '__main__':
    main()
