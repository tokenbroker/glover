#!/usr/bin/env python3
"""First structural draft of a big Glover function from m2c, cleaned up until the unit compiles.

    tools/m2c_draft.py func_XXXXXXXX [--out DIR] [--no-score]

What it does, in order (each step was worked out by hand on func_8016A058, 7,731 instructions):
  1. copies the target's assembly with named registers; finds the switch jump tables it reads
     (jtbl_* in asm/1000.s or asm/data), labels every table target inside the function and appends
     the tables as .rodata, which m2c needs to reconstruct the switches;
  2. builds an m2c context from the unit: the preprocessed file with function bodies, asm blocks
     and GCC attributes removed (cached per unit under the output dir);
  3. runs m2c (mips-gcc-c, no casts, no comments) and rewrites its output into C that KMC GCC
     accepts: pseudo-struct accesses on scalar globals become the neighbouring symbol or a typed
     byte-offset read, every `p->unkN` becomes F(type, p, N) with the type read from the load or
     store the assembly uses at that offset, `bitwise` casts go, denormal float literals become the
     integer immediates they are, func_80147000 keeps one integer argument, byte tables become
     array indexing, the sqrtf NaN fallback goes (GCC emits it), m2c temporaries get short names,
     and calls get the argument count of the unit's prototype;
  4. declares, inside the function body, every symbol the unit does not declare at file scope
     before the stub, copying the unit's own declaration when it has one anywhere;
  5. compiles the unit with the draft spliced in and prints the errors left, then scores the draft
     with objdiff using the judge's settings (functionRelocDiffs=none).

The result is a draft to submit with compile_and_diff (or the operator try endpoint when it is
over the 64 KB tool limit), never a match: expect 60-75% and a handoff note's worth of work.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
M2C = Path.home() / ".local/share/decompnet/toolchains/m2c/venv/bin/m2c"
OBJDIFF = Path.home() / ".local/share/decompnet/toolchains/objdiff-cli/objdiff-cli"
GCC = ROOT / "tools/gcc_2.7.2/linux/gcc"
CFLAGS = ["-O2", "-g2", "-G0", "-mips3", "-mgp32", "-mfp32", "-Wa,--no-float-doubleword",
          "-Wa,-mabi=32", "-Wa,-Iinclude", "-D_LANGUAGE_C", "-DF3DEX_GBI_2", f"-I{ROOT}/include", f"-I{ROOT}/src"]
REGS = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3', 't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
        's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 't8', 't9', 'k0', 'k1', 'gp', 'sp', 'fp', 'ra']
WIDTH = {'lb': 's8', 'lbu': 'u8', 'sb': 'u8', 'lh': 's16', 'lhu': 'u16', 'sh': 's16', 'lw': 's32', 'sw': 's32',
         'lwc1': 'f32', 'swc1': 'f32', 'ldc1': 'f64', 'sdc1': 'f64'}
NO_WRITE = {'sw', 'sh', 'sb', 'swc1', 'sdc1', 'bne', 'beq', 'bnez', 'beqz', 'blez', 'bgtz', 'bltz', 'bgez', 'j',
            'jal', 'jr', 'nop', 'bc1t', 'bc1f', 'bc1tl', 'bc1fl', 'bnel', 'beql', 'bnezl', 'beqzl', 'mult', 'multu',
            'div', 'divu', 'c.lt.s', 'c.le.s', 'c.eq.s', 'c.lt.d', 'c.le.d', 'c.eq.d', 'mtc1'}
MACROS = ("#define F(t,p,o) (*(t *)((u8 *)(p)+(o)))\n"
          "#define MIN(a,b) ((a) < (b) ? (a) : (b))\n"
          "#define MAX(a,b) ((a) < (b) ? (b) : (a))\n")


def unit_of(fn: str) -> str:
    for c in (ROOT / "src").glob("*.c"):
        t = c.read_text(errors="replace")
        if re.search(r'INCLUDE_ASM\("asm/nonmatchings/[^"]+",\s*' + fn + r'\)', t) or re.search(r'^[A-Za-z_][\w \*]*\b' + fn + r'\([^;]*\)\s*\{', t, re.M):
            return c.stem
    sys.exit(f"{fn}: no INCLUDE_ASM stub or definition in src/*.c")


# ----------------------------------------------------------------------------- assembly

def prepare_asm(fn: str, unit: str, out: Path) -> Path:
    src = (ROOT / "asm/nonmatchings" / unit / f"{fn}.s").read_text()
    src = re.sub(r'\$(\d{1,2})\b', lambda m: '$' + REGS[int(m.group(1))] if int(m.group(1)) < 32 else m.group(0), src)
    # a jr through a register loaded via %lo(D_X)($at) is a switch whose table splat left unnamed: name it
    lines0 = src.split("\n")
    for i, l in enumerate(lines0):
        if re.search(r'\bjr\s+\$(?!ra\b)\w+', l):
            for back in range(1, 8):
                m = re.search(r'%lo\((D_[0-9A-F]{8})\)', lines0[i - back]) if i - back >= 0 else None
                if m and (0x80100000 <= int(m.group(1)[2:], 16) < 0x8010C920 or 0x801D41D0 <= int(m.group(1)[2:], 16) < 0x801F4680):
                    src = src.replace(m.group(1), 'jtbl_' + m.group(1)[2:])
                    break
    tables = sorted(set(re.findall(r'\bjtbl_[0-9A-F]{8}\b', src)))
    # how many entries each table has: the sltiu bound checked before the jr that uses it
    bounds = {}
    lines1 = src.split("\n")
    for i, l in enumerate(lines1):
        m = re.search(r'%lo\((jtbl_[0-9A-F]{8})\)', l)
        if m:
            for back in range(1, 12):
                b = re.search(r'sltiu\s+\$\w+,\s*\$\w+,\s*(0x[0-9A-Fa-f]+|\d+)', lines1[i - back]) if i - back >= 0 else None
                if b:
                    bounds[m.group(1)] = int(b.group(1), 16) if b.group(1).startswith('0x') else int(b.group(1))
                    break
    if tables:
        pool = "\n".join((ROOT / p).read_text() for p in ["asm/1000.s", *[str(x.relative_to(ROOT)) for x in (ROOT / "asm/data").glob("*.s")]]).split("\n")
        rodata = ["", ".section .rodata", ""]
        for t in tables:
            i = next((k for k, l in enumerate(pool) if re.match(r'^(glabel|dlabel|jlabel)\s+(' + t + '|D_' + t[5:] + r')\b', l)), None)
            if i is None:
                print(f"  jump table {t} not found in asm/1000.s or asm/data; the switch will not decompile")
                continue
            want = bounds.get(t)
            words = []
            j = i + 1
            while j < len(pool):
                l = pool[j]
                if '.word' in l:
                    words.append(l)
                    if want and len(words) >= want:
                        break
                elif re.match(r'^(glabel|dlabel|jlabel|\.size|[A-Za-z_]\w*:)', l) and not want:
                    break
                elif re.match(r'^(\.size|[A-Za-z_]\w*:)', l) and want and len(words) >= want:
                    break
                j += 1
            if want and len(words) != want:
                print(f"  jump table {t}: expected {want} entries from the sltiu bound, found {len(words)}")
            rodata.append("glabel " + t)
            rodata += words
        src += "\n".join(rodata) + "\n"
        lines = src.split("\n")
        targets = {m.group(1).upper() for l in lines for m in [re.search(r'\.word 0x([0-9A-Fa-f]{8})', l)] if m}
        have = set(re.findall(r'^\s*\.L([0-9A-F]{8}):', src, re.M))
        out_lines = []
        for l in lines:
            m = re.match(r'\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/', l)
            if m and m.group(1) in targets and m.group(1) not in have:
                out_lines.append('.L' + m.group(1) + ':')
                have.add(m.group(1))
            out_lines.append(l)
        src = "\n".join(out_lines)
        src = re.sub(r'\.word 0x([0-9A-Fa-f]{8})', lambda m: '.word .L' + m.group(1).upper() if m.group(1).upper() in have else m.group(0), src)
    p = out / f"{fn}.m2c.s"
    p.write_text(src)
    return p


def field_widths(asm: Path) -> dict:
    """(global symbol, byte offset) -> C type, from the load/store applied to a register that holds the symbol's value."""
    held: dict[str, str] = {'$a0': 'arg0', '$a1': 'arg1', '$a2': 'arg2', '$a3': 'arg3'}  # pointer parameters
    widths: dict[str, dict] = {}
    for raw in asm.read_text().split("\n"):
        l = re.sub(r'/\*.*?\*/', '', raw).strip()
        m = re.match(r'(\S+)\s+(.*)', l)
        if not m:
            continue
        op, args = m.group(1), [a.strip() for a in m.group(2).split(',')]
        if op == 'lw' and len(args) == 2:
            mm = re.match(r'%lo\((D_[0-9A-F]{8})\)\(\$(\w+)\)', args[1])
            if mm:
                held[args[0]] = mm.group(1)
                continue
        if op in WIDTH and len(args) == 2:
            mm = re.match(r'(-?0x[0-9A-Fa-f]+|-?\d+)?\(\$(\w+)\)', args[1])
            if mm and '$' + mm.group(2) in held:
                off = int(mm.group(1), 16) if mm.group(1) and 'x' in mm.group(1) else int(mm.group(1) or 0)
                widths.setdefault(held['$' + mm.group(2)], {})[off] = WIDTH[op]
        if op in ('addu', 'move', 'or') and len(args) >= 2 and args[-1] in ('$zero', '$0') and args[1] in held:
            held[args[0]] = held[args[1]]  # a copy of a held pointer keeps its name
            continue
        if op == 'move' and len(args) == 2 and args[1] in held:
            held[args[0]] = held[args[1]]
            continue
        if op not in NO_WRITE and args:
            held.pop(args[0], None)
        if op == 'jal':
            held = {k: v for k, v in held.items() if k.startswith('$s')}  # callee-saved copies survive calls
    return widths


# ----------------------------------------------------------------------------- context

def strip_attributes(t: str) -> str:
    out = []
    i = 0
    while True:
        j = t.find('__attribute__', i)
        if j < 0:
            out.append(t[i:])
            return ''.join(out)
        out.append(t[i:j])
        k = t.find('(', j)
        depth = 0
        while k < len(t):
            if t[k] == '(':
                depth += 1
            elif t[k] == ')':
                depth -= 1
                if depth == 0:
                    break
            k += 1
        i = k + 1


def build_context(unit: str, out: Path) -> Path:
    ctx = out / f"ctx_{unit}.c"
    src = ROOT / "src" / f"{unit}.c"
    if ctx.exists() and ctx.stat().st_mtime > src.stat().st_mtime:
        return ctx
    pp = subprocess.run(["cpp", "-P", "-I", "include", "-D_LANGUAGE_C", "-DF3DEX_GBI_2", str(src)], cwd=ROOT,
                        capture_output=True, text=True).stdout
    t = strip_attributes(pp)
    lines = t.split("\n")
    out_lines = []
    i = depth = 0
    skipping = False
    sig = re.compile(r'^[A-Za-z_][^;{}]*\)\s*\{?\s*$')
    while i < len(lines):
        l = lines[i]
        if not skipping and depth == 0 and sig.match(l) and not l.lstrip().startswith(('typedef', 'extern', 'struct', 'union', 'enum')):
            skipping = True
            if '{' not in l:
                i += 1
                continue
        if skipping:
            depth += l.count('{') - l.count('}')
            if depth <= 0 and ('{' in l or '}' in l):
                skipping = False
                depth = 0
            i += 1
            continue
        if '__asm__' in l or 'asm(' in l or 'asm volatile' in l:
            i += 1
            continue
        out_lines.append(l)
        i += 1
    txt = re.sub(r'\b__inline__\b|\binline\b', '', "\n".join(out_lines))
    ctx.write_text(txt)
    return ctx


# ----------------------------------------------------------------------------- cleanup

def convert_arrows(s: str, width) -> str:
    while True:
        m = re.search(r'->unk(-?[0-9A-F]+)\b', s)
        if not m:
            return s
        j = m.start()
        k = j
        depth = 0
        while k > 0:
            c = s[k - 1]
            if c in ')]':
                depth += 1
                k -= 1
                continue
            if c in '([':
                if depth == 0:
                    break
                depth -= 1
                k -= 1
                continue
            if depth > 0 or c.isalnum() or c in '_.':
                k -= 1
                continue
            if c == '>' and k >= 2 and s[k - 2] == '-' and depth == 0:
                k -= 2
                continue
            break
        operand = s[k:j]
        off = m.group(1)
        n = -int(off[1:], 16) if off.startswith('-') else int(off, 16)
        s = s[:k] + f'F({width(operand, n)},{operand},{n})' + s[m.end():]


def cleanup(fn: str, unit: str, m2c_out: str, widths: dict, syms_known: dict) -> str:
    unit_src = (ROOT / "src" / f"{unit}.c").read_text(errors="replace")
    unit_lines = unit_src.split("\n")
    stub_line = next(i for i, l in enumerate(unit_lines) if re.search(r'INCLUDE_ASM\([^)]*\b' + fn + r'\)', l)
                     or re.match(r'^[A-Za-z_][\w \*]*\b' + fn + r'\([^;]*\)\s*\{', l))
    sig = re.search(r'^[a-zA-Z_][^\n]*\b' + fn + r'\([^)]*\)\s*\{', m2c_out, re.M)
    if not sig:
        sys.exit("m2c output has no function definition:\n" + m2c_out[:600])
    pro, body = m2c_out[:sig.start()], m2c_out[sig.start():]
    head, rest = body.split("\n", 1)
    m2c_decl = {}
    for l in pro.split("\n"):
        mm = re.match(r'(extern .*?\b(D_[0-9A-F]{8})\b.*;|[A-Za-z_?][\w\s\*?]*\b(func_[0-9A-F]{8})\(.*\);)$', l.strip())
        if mm:
            m2c_decl[mm.group(2) or mm.group(3)] = l.strip()
    # locals block ends at the first statement
    decl_line = re.compile(r'^\s*(?:\?\d*|[A-Za-z_]\w*)(?: \*+)?\s*\**\w+(?:\[\d+\])?;\s*$')
    rest_lines = rest.split("\n")
    n_decl = 0
    while n_decl < len(rest_lines) and (not rest_lines[n_decl].strip() or decl_line.match(rest_lines[n_decl])):
        n_decl += 1
    locals_blk, code = "\n".join(rest_lines[:n_decl]) + "\n", "\n".join(rest_lines[n_decl:])
    locals_blk = re.sub(r'^(\s*)\? \*', r'\1void *', locals_blk, flags=re.M)
    locals_blk = re.sub(r'^(\s*)\?\d* ', r'\1s32 ', locals_blk, flags=re.M)
    ltype = {m.group(2): m.group(1) for m in re.finditer(r'^\s*([A-Za-z0-9_]+(?: \*+)?)\s*(\w+)(?:\[\d+\])?;', locals_blk, re.M)}

    def declared_type(sym):
        m = re.search(r'^\s*extern ([a-zA-Z0-9_]+) \**' + sym + r'\b', unit_src, re.M)
        return m.group(1) if m else 's32'

    code = code.replace('M2C_ERROR(/* Unable to find stack arg 0x10 in block */)', '0')
    code = re.sub(r'\(unaligned (s32|u32)\) ', '', code)
    for r_ in sorted(set(re.findall(r'\bsaved_reg_(\w+)\b', code))):
        locals_blk += f"{'f32' if r_.startswith('f') else 's32'} saved_reg_{r_};\n"
    code = re.sub(r'M2C_ERROR\([^)]*\)', '0', code)
    # pseudo-struct accesses on globals: neighbouring symbol when it exists, else a typed byte read
    def unk_repl(m):
        sym, off = m.group(1), m.group(2)
        n = -int(off[1:], 16) if off.startswith('-') else int(off, 16)
        if n == 0:
            return sym
        base = syms_known.get(sym)
        ty = declared_type(sym)
        if base is not None and f'D_{base + n:08X}' in syms_known:
            return f'D_{base + n:08X}'
        if sym in widths and n in widths[sym]:
            ty = widths[sym][n]
        return f'F({ty},&{sym},{n})'
    code = re.sub(r'\b(D_[0-9A-F]{8})\.unk(-?[0-9A-F]+)\b', unk_repl, code)
    code = re.sub(r'\b(D_[0-9A-F]{8})\.(x|y|z)\b', lambda m: f'F(f32,&{m.group(1)},{"xyz".index(m.group(2)) * 4})', code)
    code = re.sub(r'&F\(f32,&(D_[0-9A-F]{8}),0\)', r'&\1', code)
    code = re.sub(r'\(bitwise [a-z0-9]+(?: \*+)?\) ', '', code)
    code = re.sub(r'\b([0-9.]+e-4\d)f\b', lambda m: str(struct.unpack('>I', struct.pack('>f', float(m.group(1))))[0]), code)
    addr_syms = sorted((a, n) for n, a in syms_known.items() if n.startswith('D_'))
    def raw_addr(m):
        a = int(m.group(1), 16)
        import bisect
        i = bisect.bisect_right(addr_syms, (a, 'zzz')) - 1
        if i < 0 or a - addr_syms[i][0] > 0x100:
            return m.group(0)
        base, name = addr_syms[i]
        return f'F(f32,&{name},{a - base})'
    code = re.sub(r'\*0x(8[0-9A-Fa-f]{7})\b', raw_addr, code)

    def f47(m):
        args = [a.strip() for a in m.group(1).split(',')]
        ints = [a for a in args if re.fullmatch(r'-?\d+|0x[0-9A-Fa-f]+', a)]
        return 'func_80147000(' + (ints[0] if ints else args[0]) + ')'
    code = re.sub(r'func_80147000\(([^()]*(?:\([^()]*\)[^()]*)*)\)', f47, code)
    code = re.sub(r'&(D_[0-9A-F]{8}) ([+-]) (0x[0-9A-F]+|\d+)\b', r'((u8 *)&\1 \2 \3)', code)
    code = re.sub(r'\*\(\(([^()]+)\) \+ &(D_[0-9A-F]{8})\)', r'F(s32,&\2,\1)', code)
    code = re.sub(r'\(\(([^()]+)\) \+ &(D_[0-9A-F]{8})\)', r'((u8 *)&\2 + (\1))', code)
    def table_type(sym):
        m = re.search(r'^\s*extern (f32|s32|u8|s8|s16|u16) ' + sym + r'\b', unit_src, re.M)
        if m:
            return m.group(1)
        d = m2c_decl.get(sym, '')
        m = re.match(r'extern (f32|s32|u8|s8|s16|u16)\b', d)
        return m.group(1) if m else 'u8'
    tbl = r'\*\(&(D_[0-9A-F]{8}) \+ ((?:[^()]|\((?:[^()]|\((?:[^()]|\([^()]*\))*\))*\))+?)\)'
    for _ in range(3):
        code = re.sub(tbl, lambda m: f'F({table_type(m.group(1))},&{m.group(1)},{m.group(2)})', code)
    code = re.sub(r'&(D_[0-9A-F]{8}) \+ \(((?:[^()]|\((?:[^()]|\([^()]*\))*\))+?)\)(?!\))', r'((u8 *)&\1 + (\2))', code)
    tbl2 = r'\*\((D_801FA[AB][0-9A-F]{2}) \+ ((?:[^()]|\([^()]*\))+?)\)'
    code = re.sub(tbl2, lambda m: f'F({table_type(m.group(1))},&{m.group(1)},{m.group(2)})', code)
    # pointer tables: *((i * 4) + D_table) and *(i + D_table) and **(...)
    for _ in range(2):
        code = re.sub(r'\*\(\(([^()]+)\) \+ (D_[0-9A-F]{8})\)', r'F(s32,\2 + (\1),0)', code)
        code = re.sub(r'\*\((\w+) \+ (D_[0-9A-F]{8})\)', r'F(s32,\2 + \1,0)', code)
        code = re.sub(r'\*\((D_[0-9A-F]{8}) \+ \(((?:[^()]|\([^()]*\))*)\)\)', lambda m: f'F({table_type(m.group(1))},{m.group(1)} + ({m.group(2)}),0)', code)
        code = re.sub(r'\*\(\(([^()]+)\) \+ ((?:temp|var)_\w+|_\d+)\)', r'F(s32,\2 + (\1),0)', code)
        code = re.sub(r'\*\((D_[0-9A-F]{8}) \+ (\w+)\)', r'F(s32,\1 + \2,0)', code)
        code = re.sub(r'\*(F\((?:[^()]|\([^()]*\))*\))', r'F(s32,\1,0)', code)
    code = re.sub(r'(\w+) = sqrtf\(([^;]+)\);\n\s*if \(\1 != \1\) \{\n\s*\1 = func_801C4030\(\2\);\n\s*\}\n', r'\1 = sqrtf(\2);\n', code)
    agg: dict[int, set] = {}
    for sym, d in widths.items():
        for off, w in d.items():
            agg.setdefault(off, set()).add(w)

    def width(operand, off):
        if operand in widths and off in widths[operand]:
            return widths[operand][off]
        ws = agg.get(off)
        return next(iter(ws)) if ws and len(ws) == 1 else 's32'
    # assignments to typed temps say the width
    code = re.sub(r'\b(\w+) = (D_[0-9A-F]{8}|\w+)->unk([0-9A-F]+)\b(?![-\]>.\w])',
                  lambda m: f'{m.group(1)} = F({ltype.get(m.group(1), width(m.group(2), int(m.group(3), 16))) if ltype.get(m.group(1), "") in ("f32", "s32", "s16", "u16", "u8", "s8", "f64") else width(m.group(2), int(m.group(3), 16))},{m.group(2)},{int(m.group(3), 16)})', code)
    code = re.sub(r'\b((?:temp|var)_\w+|_\d+)\[(\w+)\]\.unk([0-9A-F]+)\b', lambda m: f'F(s32,(u8 *){m.group(1)} + ({m.group(2)}) * 4 /* stride? */,{int(m.group(3), 16)})', code)
    SZ = {'s8': 1, 'u8': 1, 's16': 2, 'u16': 2, 's32': 4, 'u32': 4, 'f32': 4, 'f64': 8}
    def gl_arr(m):
        sym, idx, off = m.group(1), m.group(2), m.group(3)
        n = -int(off[1:], 16) if off.startswith('-') else int(off, 16)
        ty = declared_type(sym)
        return f'F({ty},&{sym},({idx}) * {SZ.get(ty, 4)} + {n})'
    code = re.sub(r'\(&(D_[0-9A-F]{8})\)\[(\w+)\]\.unk(-?[0-9A-F]+)\b', gl_arr, code)
    # arrays of anonymous structs the unit declares only inside other functions: byte offsets from that layout
    structs = {}
    for m in re.finditer(r'extern struct \{([^}]*)\} (D_[0-9A-F]{8})\[\];', unit_src):
        off, fields = 0, {}
        for fm in re.finditer(r'(\w+) (\w+)(?:\[(0x[0-9A-Fa-f]+|\d+)\])?;', m.group(1)):
            ty, name, cnt = fm.group(1), fm.group(2), fm.group(3)
            n = int(cnt, 16) if cnt and cnt.startswith('0x') else int(cnt) if cnt else 1
            fields[name] = (off, ty)
            off += SZ.get(ty, 4) * n
        structs[m.group(2)] = (off, fields)
    def anon(m):
        sym, idx, field = m.group(1), m.group(2), m.group(3)
        if sym in structs and field in structs[sym][1]:
            stride, fields = structs[sym]
            o, ty = fields[field]
            return f'F({ty},{sym},({idx}) * {stride} + {o})'
        return m.group(0)
    code = re.sub(r'\b(D_[0-9A-F]{8})\[(\w+)\]\.(\w+)\b', anon, code)
    code = convert_arrows(code, width)
    for _ in range(2):
        code = re.sub(r'(F\((?:[^()]|\([^()]*\))*\))->next\b', r'F(s32,\1,0)', code)
        code = re.sub(r'(F\((?:[^()]|\([^()]*\))*\))->prev\b', r'F(s32,\1,4)', code)
    for _ in range(2):  # derefs of values that are now F() reads
        code = re.sub(r'\*(F\((?:[^()]|\([^()]*(?:\([^()]*\)[^()]*)*\))*\))', r'F(s32,\1,0)', code)
        code = re.sub(r'\*\(\(([^()]+)\) \+ (F\((?:[^()]|\([^()]*\))*\))\)', r'F(s32,\2 + (\1),0)', code)
    code = re.sub(r'\*\(\(([^()]+)\) \+ (F\((?:[^()]|\([^()]*\))*\))\)', r'F(s32,\2 + (\1),0)', code)
    code = re.sub(r'\*\((F\((?:[^()]|\([^()]*\))*\)) \+ (\w+)\)', r'F(s32,\1 + \2,0)', code)
    # (u32)float conversion: (s32)(x - 2^31) | 0x80000000, with the pool constant read as f32
    code = re.sub(r'\((\w+) - F\(s32,&(D_8010[0-9A-F]{4}),4\)\) \| 0x80000000', r'((s32)(\1 - F(f32,&\2,4))) | 0x80000000', code)
    code = re.sub(r'\((\w+) - (D_8010[0-9A-F]{4})\) \| 0x80000000', r'((s32)(\1 - \2)) | 0x80000000', code)
    code = re.sub(r'\[F\(f32,', '[F(s32,', code)  # an index is an integer
    code = re.sub(r'F\(f32,((?:[^()]|\([^()]*\))*)\) \* (0x[0-9A-Fa-f]+|\d+)\)', r'F(s32,\1) * \2)', code)
    code = re.sub(r'F\(f32,((?:[^()]|\([^()]*(?:\([^()]*\)[^()]*)*\))*)\) %', r'F(s32,\1) %', code)
    for _ in range(2):  # a float read inside a pointer expression is a pointer
        code = re.sub(r'F\((\w+),\(F\(f32,', r'F(\1,(F(s32,', code)
        code = re.sub(r'F\((\w+),F\(f32,', r'F(\1,F(s32,', code)
    ptr_syms = set(re.findall(r'^\s*extern [A-Za-z0-9_]+ \*+(D_[0-9A-F]{8})\b', unit_src, re.M))
    code = re.sub(r'F\(f32,((?:[^()]|\([^()]*(?:\([^()]*\)[^()]*)*\))*)\) (==|!=) (D_[0-9A-F]{8})\b',
                  lambda m: f'F(s32,{m.group(1)}) {m.group(2)} (s32){m.group(3)}' if m.group(3) in ptr_syms else m.group(0), code)
    # a float-typed read used with a bit operator is a flag word
    for _ in range(2):
        code = re.sub(r'F\(f32,((?:[^()]|\([^()]*\))*)\)(\s*(?:\||&|>>|<<|%|\^)\s*)', r'F(s32,\1)\2', code)
        code = re.sub(r'((?:\||&|>>|<<|%|\^)\s*)F\(f32,((?:[^()]|\([^()]*\))*)\)', r'\1F(s32,\2)', code)
        code = re.sub(r'(!)F\(f32,((?:[^()]|\([^()]*\))*)\) &', r'\1F(s32,\2) &', code)
    for _ in range(3):  # a read that is dereferenced again is a pointer, not a float
        code = re.sub(r'F\((\w+),F\(f32,', r'F(\1,F(s32,', code)
    code = re.sub(r'\*\((\w+) \+ (F\((?:[^()]|\([^()]*\))*\))\)', r'F(s32,\2 + \1,0)', code)
    code = re.sub(r'F\(f32,((?:[^()]|\([^()]*\))*)\) (==|!=|<|>|<=|>=) (\d+|NULL|0x[0-9A-Fa-f]+)\b', r'F(s32,\1) \2 \3', code)
    code = re.sub(r'\((\w+) - (\w+)\) \| 0x80000000', r'((s32)(\1 - \2)) | 0x80000000', code)
    code = re.sub(r'(?<![\w)])(\w+) \| 0x80000000', lambda m: f'((s32){m.group(1)}) | 0x80000000' if ltype.get(m.group(1)) in ('f32', 'f64') else m.group(0), code)
    nonptr = lambda t: t in ltype and '*' not in ltype[t]
    code = re.sub(r'\*\((\w+) \+ (F\([^()]*\)|\w+)\)', lambda m: f'F(s32,{m.group(2)} + {m.group(1)},0)' if nonptr(m.group(1)) else m.group(0), code)
    code = re.sub(r'(?<![\w)])\*(temp_\w+|var_\w+)\b', lambda m: f'F(s32,{m.group(1)},0)' if nonptr(m.group(1)) else m.group(0), code)
    # argument counts from the unit's prototypes and definitions
    def param_count(f):
        best = None
        for m in re.finditer(r'^\s*(?:extern\s+)?[A-Za-z_][\w\s\*]*?\s\**' + f + r'\(([^;{}]*)\)\s*[;{]', unit_src, re.M):
            a = m.group(1).strip()
            n = 0 if a == 'void' else (None if a == '' else a.count(',') + 1)
            if n is not None:
                return n
        return best

    def fix_call(m):
        f, args = m.group(1), m.group(2)
        n = param_count(f)
        if n is None or f == fn:
            return m.group(0)
        parts, depth, cur = [], 0, ''
        for c in args:
            if c in '([':
                depth += 1
            if c in ')]':
                depth -= 1
            if c == ',' and depth == 0:
                parts.append(cur.strip())
                cur = ''
            else:
                cur += c
        if cur.strip() or parts:
            parts.append(cur.strip())
        if len(parts) > n:
            parts = parts[:n]
        while len(parts) < n:
            parts.append('0')
        return f'{f}({", ".join(parts)})'
    for _ in range(3):
        code = re.sub(r'\b(func_[0-9A-F]{8})\(((?:[^()]|\([^()]*(?:\([^()]*\)[^()]*)*\))*)\)', fix_call, code)
    for _ in range(2):
        code = re.sub(r'\*(F\((?:[^()]|\([^()]*(?:\([^()]*\)[^()]*)*\))*\))', r'F(s32,\1,0)', code)
    code = re.sub(r'\b(\w+) = F\(f32,', lambda m: f'{m.group(1)} = F(s32,' if '*' in ltype.get(m.group(1), '') else m.group(0), code)
    code = re.sub(r'(?<![\w)])(\w+) \| 0x80000000', lambda m: f'((s32){m.group(1)}) | 0x80000000' if ltype.get(m.group(1), '') in ('f32', 'f64') else m.group(0), code)
    void_fns = set(re.findall(r'^\s*(?:extern\s+)?void\s+(func_[0-9A-F]{8})\(', unit_src, re.M))
    code = re.sub(r'(=\s*|return\s+|\(\s*)(func_[0-9A-F]{8})\(', lambda m: f'{m.group(1)}((s32 (*)()){m.group(2)})(' if m.group(2) in void_fns else m.group(0), code)
    # short names for m2c temporaries, in both the locals block and the code
    names: dict[str, str] = {}

    def short(m):
        n = m.group(0)
        if n not in names:
            names[n] = '_' + str(len(names))
        return names[n]
    locals_blk = re.sub(r'\b(?:temp|var)_[a-z0-9]+(?:_\d+)?\b', short, locals_blk)
    code = re.sub(r'\b(?:temp|var)_[a-z0-9]+(?:_\d+)?\b', short, code)
    # declarations the unit does not provide before the stub
    syms = sorted(set(re.findall(r'\b(D_[0-9A-F]{8}|func_[0-9A-F]{8})\b', code)) - {fn})
    proto = lambda s: re.compile(r'^\s*((?:extern\s+)?[A-Za-z_][\w\s\*]*?\s\**' + s + r'\([^;{}]*\);)')
    ext = lambda s: re.compile(r'^\s*(extern [^;]*\b' + s + r'\b[^;]*;)')
    defn = lambda s: re.compile(r'^([A-Za-z_][\w\s\*]*?\s\**' + s + r'\([^;{}]*\))\s*\{')

    def file_scope_before(s):
        pat = re.compile(r'\b' + s + r'\b')
        depth = 0
        for l in unit_lines[:stub_line]:
            at_top = depth == 0
            depth += l.count('{') - l.count('}')
            if at_top and l and not l[0].isspace() and pat.search(l):
                # a declaration or definition has a type before the name; a statement in an unindented draft does not
                if l.startswith('extern') or proto(s).match(l) or defn(s).match(l) or re.match(r'^[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*\**\s+\**' + s + r'\b\s*(\[[^\]]*\])*\s*(=|;)', l):
                    return True
        return False

    def any_decl(s):
        for l in unit_lines:
            m = ext(s).match(l) or proto(s).match(l)
            if m:
                return m.group(1).strip()
        for i, l in enumerate(unit_lines):
            m = defn(s).match(l) or (re.match(r'^([A-Za-z_][\w\s\*]*?\s\**' + s + r'\([^;{}]*\))\s*$', l)
                                     if i + 1 < len(unit_lines) and unit_lines[i + 1].strip().startswith('{') else None)
            if m:
                return m.group(1).strip() + ';'
        return None
    decls = []
    for s in syms:
        if file_scope_before(s):
            continue
        d = any_decl(s)
        if d:
            decls.append(d)
            continue
        if s in m2c_decl:
            d = m2c_decl[s].replace('?32', 's32').replace('? *', 'void *')
            d = re.sub(r'^\? ', 's32 ' if s.startswith('D_') else 'void ', d)
            d = d.replace('?', 's32')
            decls.append(d)
            continue
        decls.append(f'void {s}();' if s.startswith('func_') else f'extern s32 {s};')
    # case labels that m2c left outside their switch: label them and dispatch from the nearest switch above
    cl = code.split("\n")
    depth = 0
    switches = []  # (line index, depth after its brace)
    adds: dict[int, list] = {}
    for i, l in enumerate(cl):
        st = l.strip()
        if st.startswith('switch ('):
            switches.append((i, depth + 1))
        open_sw = any(d <= depth for _, d in switches if d <= depth)
        m = re.match(r'^(case ([^:]+)|default):$', st)
        if m and not any(d <= depth for _, d in switches):
            lab = 'L_' + re.sub(r'\W', '_', m.group(0)[:-1]) + f'_{i}' 
            cl[i] = lab + ':'
            if switches:
                adds.setdefault(switches[-1][0], []).append(f"{m.group(0)} goto {lab};")
        depth += l.count('{') - l.count('}')
        switches = [(a, d) for a, d in switches if d <= depth]
    for i in sorted(adds, reverse=True):
        cl.insert(i + 1, " ".join(adds[i]))
    code = "\n".join(cl)
    visible_types = set(re.findall(r'^\}\s*(\w+);|^typedef [^;{]*?\b(\w+);', unit_src, re.M)) | set(re.findall(r'\b(Vec3F|Gfx|ObjectNode|U32F32|s8|u8|s16|u16|s32|u32|f32|f64|void|char|int|short|long|float|double|unsigned)\b', 'x'))
    vis = {t for pair in re.findall(r'^\}\s*(\w+);|^typedef [^;{]*?\b(\w+);', unit_src, re.M) for t in pair if t}
    vis |= {t for pair in re.findall(r'^\}\s*(\w+);|^typedef [^;{]*?\b(\w+);', (ROOT / "include/structs.h").read_text() + (ROOT / "include/common.h").read_text(), re.M) for t in pair if t}
    vis |= {'s8', 'u8', 's16', 'u16', 's32', 'u32', 'f32', 'f64', 'void', 'char', 'int', 'short', 'long', 'float', 'double', 'unsigned', 'struct', 'union', 'const', 'volatile', 'register'}
    fixed = []
    for d in decls:
        m = re.match(r'extern (?:const )?(\w+)', d)
        if m and m.group(1) not in vis:
            sym = re.search(r'\b(D_[0-9A-F]{8}|func_[0-9A-F]{8})\b', d).group(1)
            d = f'extern s32 {sym};'
            code = re.sub(r'F\(' + m.group(1) + ',', 'F(s32,', code)
        fixed.append(d)
    decls = fixed
    for d in list(decls):
        m = re.match(r'extern (\w+) (D_[0-9A-F]{8})\[\];', d)
        if m and re.search(r'(?<![\w\]])' + m.group(2) + r'\s*(=|[|&+\-*/]=)', code):
            decls[decls.index(d)] = f'extern s32 {m.group(2)};'
    pm = None
    depth = 0
    for l in unit_lines:
        if depth == 0:
            m_ = re.match(r'^(?:extern\s+)?([A-Za-z_][\w\s\*]*?)\s(\**)' + fn + r'\(([^;{}]*)\);', l)
            if m_:
                pm = m_
                break
        depth += l.count('{') - l.count('}')
    pm = pm or re.search(r'^\s*(?:extern\s+)?([A-Za-z_][\w\s\*]*?)\s(\**)' + fn + r'\(([^;{}]*)\);', unit_src, re.M)
    if pm and pm.group(3).strip() not in ('', 'void'):
        params = [a.strip() for a in pm.group(3).split(',')]
        named = [a if (len(a.split()) > 1 and not a.endswith('*')) else f'{a} arg{i}' for i, a in enumerate(params)]
        head = f"{pm.group(1).strip()} {pm.group(2)}{fn}({', '.join(named)}) {{"
    declared = set(re.findall(r'\b(\w+);', locals_blk)) | set(re.findall(r'\b(sp[0-9A-F]+)\s*\[', locals_blk))
    extra = sorted(set(re.findall(r'(?<![\w&])(sp[0-9A-F]{2,3})\b', code)) - declared)
    for v in extra:
        locals_blk += f"s32 {v};\n"
    for v in sorted(set(re.findall(r'(?<![\w&])(unksp[0-9A-F]{2,3})\b', code)) - declared):
        locals_blk += f"u8 {v};\n"
    body = "\n".join(l.strip() for l in (locals_blk + code).split("\n") if l.strip())
    return head.strip() + "\n" + MACROS + "\n".join(decls) + "\n" + body + "\n"


# ----------------------------------------------------------------------------- compile and score

def splice(unit_src: str, fn: str, draft: str) -> str:
    stub = re.search(r'INCLUDE_ASM\([^)]*\b' + fn + r'\);', unit_src)
    if stub:
        return unit_src[:stub.start()] + draft + unit_src[stub.end():]
    i = unit_src.index('\nvoid ' + fn + '(') + 1
    j = unit_src.index('{', i)
    depth = 0
    k = j
    while True:
        depth += (unit_src[k] == '{') - (unit_src[k] == '}')
        k += 1
        if depth == 0:
            break
    return unit_src[:i] + draft.rstrip('\n') + unit_src[k:]


def compile_unit(unit: str, fn: str, draft: str, out: Path) -> list[str]:
    unit_src = (ROOT / "src" / f"{unit}.c").read_text(errors="replace")
    c = out / f"unit_{fn}.c"
    c.write_text(splice(unit_src, fn, draft))
    env = {**os.environ, "COMPILER_PATH": str(ROOT / "tools/gcc_2.7.2/linux")}
    r = subprocess.run([str(GCC), f"-B{ROOT}/tools/build/", *CFLAGS, "-c", str(c), "-o", str(out / f"unit_{fn}.o")],
                       capture_output=True, text=True, env=env, cwd=ROOT)
    head = draft.split("\n", 1)[0]
    off = next(i for i, l in enumerate(c.read_text().split("\n")) if l == head) + 1
    errs = []
    for l in (r.stdout + r.stderr).split("\n"):
        m = re.match(r'[^:]+:(\d+): (.*)', l)
        if m and 'warning:' not in l and not re.search(r'In function|At top level|Each undeclared|for each function', l):
            errs.append(f"[{int(m.group(1)) - off + 1}] {m.group(2)}")
    return errs


def score(unit: str, fn: str, out: Path) -> str:
    dj = out / f"diff_{fn}.json"
    subprocess.run([str(OBJDIFF), "diff", "-1", str(ROOT / "expected/src" / f"{unit}.o"), "-2", str(out / f"unit_{fn}.o"),
                    "-c", "functionRelocDiffs=none", "-o", str(dj), "--format", "json", fn], capture_output=True)
    d = json.loads(dj.read_text())
    L = next(s for s in d['left']['symbols'] if s.get('name') == fn)
    R = next(s for s in d['right']['symbols'] if s.get('name') == fn)
    return f"{L.get('match_percent', 0):.2f}% (target {len(L['instructions'])} rows, draft {len(R['instructions'])})"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("function")
    ap.add_argument("--out", default=str(ROOT / "permuter_results" / "drafts"))
    ap.add_argument("--no-score", action="store_true")
    a = ap.parse_args()
    fn = a.function
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    unit = unit_of(fn)
    asm = prepare_asm(fn, unit, out)
    ctx = build_context(unit, out)
    r = subprocess.run([str(M2C), "--target", "mips-gcc-c", "-f", fn, "--no-casts", "--comment-style", "none",
                        "--context", str(ctx), str(asm)], capture_output=True, text=True, timeout=1800)
    (out / f"{fn}.m2c.c").write_text(r.stdout)
    if r.returncode or 'Decompilation failure' in r.stdout[:400]:
        print(r.stdout[:800] or r.stderr[-800:])
        return 1
    syms = {}
    for f in ("symbol_addrs.txt", "undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        try:
            for m in re.finditer(r"^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)", (ROOT / f).read_text(), re.M):
                syms[m.group(1)] = int(m.group(2), 16)
        except OSError:
            pass
    draft = cleanup(fn, unit, r.stdout, field_widths(asm), syms)
    p = out / f"{fn}.draft.c"
    p.write_text(draft)
    print(f"{fn}: unit {unit}, m2c {len(r.stdout)} bytes -> draft {len(draft)} bytes ({'over' if len(draft) > 65536 else 'under'} the 64 KB tool limit) at {p}")
    errs = compile_unit(unit, fn, draft, out)
    for _ in range(2):  # a float temporary passed where the prototype wants a pointer: cast it (placeholder, note it)
        fixes = [(int(m.group(1)), int(m.group(2)), m.group(3)) for e in errs for m in [re.match(r"\[(\d+)\] incompatible type for argument (\d+) of `(\w+)'", e)] if m]
        if not fixes:
            break
        dl = draft.split("\n")
        for line, argn, f in fixes:
            pm = re.search(r'\b' + f + r'\(([^;{}]*)\)\s*[;{]', (ROOT / "src" / f"{unit}.c").read_text(errors="replace"))
            if not pm or line - 1 >= len(dl):
                continue
            ptypes = [a.strip() for a in pm.group(1).split(',')]
            if argn - 1 >= len(ptypes):
                continue
            ty = re.sub(r'\b\w+$', '', ptypes[argn - 1]).strip() if not ptypes[argn - 1].endswith('*') else ptypes[argn - 1]
            ty = ty or ptypes[argn - 1]
            cm = re.search(r'\b' + f + r'\((.*)\)', dl[line - 1])
            if not cm:
                continue
            parts, depth, cur = [], 0, ''
            for c in cm.group(1):
                depth += (c in '([') - (c in ')]')
                if c == ',' and depth == 0:
                    parts.append(cur); cur = ''
                else:
                    cur += c
            parts.append(cur)
            if argn - 1 < len(parts):
                arg_ = parts[argn - 1].strip()
                if ty == 'U32F32':
                    parts[argn - 1] = f' ({{ U32F32 u_; u_.{"i" if arg_.startswith("&") else "f"} = ({"s32" if arg_.startswith("&") else "f32"}){arg_}; u_; }})'
                elif '*' in ty:
                    parts[argn - 1] = f' ({ty})(s32){arg_}'
                elif arg_.startswith('&'):
                    parts[argn - 1] = f' *({ty} *){arg_}'
                else:
                    parts[argn - 1] = f' ({ty}){arg_}'
                dl[line - 1] = dl[line - 1][:cm.start(1)] + ','.join(parts).strip() + dl[line - 1][cm.end(1):]
        draft = "\n".join(dl)
        p.write_text(draft)
        errs = compile_unit(unit, fn, draft, out)
    for _ in range(2):  # declarations GCC says conflict with the unit's own: drop ours
        bad = {m.group(1) for e in errs for m in [re.search(r"conflicting types for `(\w+)'", e)] if m} - {fn}
        if not bad:
            break
        draft = "\n".join(l for l in draft.split("\n") if not (re.match(r'^(extern |[A-Za-z_][\w \*]*\bfunc_[0-9A-F]{8}\()', l) and any(re.search(r'\b' + b + r'\b', l) for b in bad)))
        p.write_text(draft)
        errs = compile_unit(unit, fn, draft, out)
    if errs:
        print(f"{len(errs)} compile errors left (draft line numbers):")
        print("\n".join(errs[:40]))
        return 2
    print("compiles clean" + ("" if a.no_score else "; objdiff " + score(unit, fn, out)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
