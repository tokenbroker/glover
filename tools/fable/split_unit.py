#!/usr/bin/env python3
"""Split a splat C unit at function boundaries into pieces with their own compile flags.
usage: split_unit.py --root DIR --unit 18020_C0800 --live path/to/live.c --rom-start 0xC0800 --vram-start 0x801BF800
       --boundary 0x801C4030:18020_C5030:LIB  [--boundary ...]  --expected-src DIR(with per-function .s)
Pieces: the first keeps the unit's name; each boundary starts a new piece named as given; the tag after the name
selects the flags block written to the Makefile (GAME: default; LIB: -O2 without -g, --fp-move-nops, doubles kept;
O0: -O0 -g2; LIBGCC: -O2 -g2, the libgcc helpers at the end of the library unit; ASM: no C at all, see below).
Writes the C pieces, asm/nonmatchings/<piece>/, expected/src/<piece>.o (assembled from the .s files
with --fp-move-nops so nothing is transformed), glover.yaml, glover.ld, objdiff.json and the Makefile overrides.
An ASM piece (hand-written routines) becomes asm/<piece>.s, assembled by the Makefile's %.o: %.s rule: the
functions' .s bodies in address order (their per-function .s files leave asm/nonmatchings/), the bytes between
them (alignment padding) as .word from baserom.z64; it has no C file, no expected object and no objdiff unit.
A piece that starts or ends off a 16-byte boundary gets `PACK_TEXT := 1` in the Makefile: tools/fable/pack_text.py
then gives its .text 4-byte alignment and drops the assembler's tail padding, which would otherwise move the piece
or the one after it (the padding blocks between functions are symbols, in C and in the ASM pieces, so they stay)."""
import argparse, json, os, re, shutil, subprocess, sys
from pathlib import Path

ap = argparse.ArgumentParser()
ap.add_argument("--root", required=True); ap.add_argument("--unit", required=True); ap.add_argument("--live", required=True)
ap.add_argument("--rom-start", type=lambda x: int(x, 16), required=True); ap.add_argument("--vram-start", type=lambda x: int(x, 16), required=True)
ap.add_argument("--boundary", action="append", default=[]); ap.add_argument("--first-tag", default="GAME")
ap.add_argument("--asm-src", required=True, help="dir with every function's .s (the unit's nonmatchings dir)")
ap.add_argument("--extra", default="", help="functions of the range the C file lacks (comma list): placed as INCLUDE_ASM by address")
ap.add_argument("--vram-end", type=lambda x: int(x, 16), default=None, help="end of the unit (needed when the last piece is ASM)")
a = ap.parse_args()
root = Path(a.root); unit = a.unit
bounds = [(int(b.split(":")[0], 16), b.split(":")[1], b.split(":")[2]) for b in a.boundary]
bounds.sort()
pieces = [(0, unit, a.first_tag)] + bounds  # (start vram, name, tag)
def piece_of(addr):
    name = pieces[0][1]
    for st, n, _ in pieces:
        if addr >= st: name = n
    return name
src = open(a.live).read().split("\n")
# ---- chunk the file: function chunks (INCLUDE_ASM lines and definitions) vs shared lines
def def_start(i):
    l = src[i]
    if l.startswith("INCLUDE_ASM("): return "inc"
    if re.match(r"^[A-Za-z_][\w \*]*\bfunc_[0-9A-F]{8}\s*\(", l):
        b, sc = l.find("{"), l.find(";")
        if b >= 0: return "def" if (sc < 0 or b < sc) else None  # the body starts on this line, or it is a prototype
        if sc >= 0: return None  # a prototype
        j = i + 1  # the header continues (K&R declarations) up to the opening brace
        while j < len(src) and "{" not in src[j]:
            if src[j].rstrip().endswith(";") and not re.match(r"^\s*(register\s+)?[A-Za-z_][\w \*]*\b\w+\s*(\[[^]]*\])?\s*;", src[j]): return None
            j += 1
        return "def" if j < len(src) else None
    return None
PAD = re.compile(r"^(?:const\s+)?u32\s+D_([0-9A-F]{8})_padding\w*\[\]")  # splat's inter-function padding, as C data in .text
chunks = []; i = 0
while i < len(src):
    if (pm := PAD.match(src[i])):  # a block up to its `};`, placed by address like a function
        j = i
        while j < len(src) and not src[j].rstrip().endswith("};"): j += 1
        start = i - 1 if i > 0 and src[i - 1].strip() == "/* Original compiler padding. */" else i
        if start < i and chunks and chunks[-1] == ("other", None, i - 1, i): chunks.pop()
        chunks.append(("fn", int(pm.group(1), 16), start, j + 1)); i = j + 1; continue
    k = def_start(i)
    if k == "inc":
        m = re.search(r"func_([0-9A-F]{8})", src[i]); chunks.append(("fn", int(m.group(1), 16), i, i + 1)); i += 1; continue
    if k == "def":
        m = re.search(r"func_([0-9A-F]{8})", src[i]); j = i; d = 0; seen = False
        while j < len(src):
            d += src[j].count("{") - src[j].count("}")
            if "{" in src[j]: seen = True
            if seen and d == 0: break
            j += 1
        chunks.append(("fn", int(m.group(1), 16), i, j + 1)); i = j + 1; continue
    chunks.append(("other", None, i, i + 1)); i += 1
for name in [x for x in a.extra.split(",") if x]:  # a function the file lacks: an INCLUDE_ASM chunk in address order
    addr = int(name[5:], 16)
    if any(c[0] == "fn" and c[1] == addr for c in chunks): continue
    line = f'INCLUDE_ASM("asm/nonmatchings/{unit}", {name});'
    src.append(line); idx = len(src) - 1
    pos = next((k for k, c in enumerate(chunks) if c[0] == "fn" and c[1] > addr), len(chunks))
    chunks.insert(pos, ("fn", addr, idx, idx + 1))
    if pos > 0 and chunks[pos - 1][0] == "fn":  # a blank line between it and the function before
        src.append(""); chunks.insert(pos, ("other", None, len(src) - 1, len(src)))
fns = sorted(c[1] for c in chunks if c[0] == "fn")
print(f"{len(fns)} functions; pieces: " + ", ".join(f"{n}:{sum(1 for f in fns if piece_of(f)==n)}" for _, n, _ in pieces))
# ---- what a removed function leaves behind, in its place: in the one file a definition declared the function for
# everything after it (a later piece gets the same declaration as a prototype; K&R definitions as `type name();`, so
# promotions stay as they were), `#define`s inside its body with no `#undef` stayed live, and GCC 2.7.2 keeps a
# block-scope extern declaration as the identifier's external declaration for everything after it (reproduced in a
# discarded inline stub, one per function)
def prototype(c):
    head = "\n".join(src[c[2]:c[3]])
    if head.startswith("INCLUDE_ASM") or "_padding" in head.split("{", 1)[0]: return None
    i = head.index("("); depth = 0; j = i
    while j < len(head):
        depth += (head[j] == "(") - (head[j] == ")"); j += 1
        if depth == 0: break
    params = head[i + 1:j - 1].strip()
    if head[:i].lstrip().startswith("static"): return None
    knr = params and all(re.fullmatch(r"[A-Za-z_]\w*", x.strip()) for x in params.split(",")) and params not in ("void",)
    # a K&R definition after a file-scope prototype changes nothing for later callers (and an `f();` declaration after
    # an ANSI prototype is an error), so it leaves nothing; an ANSI definition always leaves its prototype, in place:
    # callers after it in the one file saw these parameter types even when an earlier `f();` declaration existed
    if knr: return None if c[1] in declared else " ".join(head[:i].split()) + "();"
    return " ".join(head[:j].split()) + ";"
declared = set()  # functions the shared (file-scope) text declares already: those need no prototype
depth = 0
for c in chunks:
    for l in src[c[2]:c[3]]:
        if c[0] == "other" and depth == 0 and l.rstrip().endswith(";"):
            declared.update(int(x, 16) for x in re.findall(r"\bfunc_([0-9A-F]{8})\s*\(", l))
        depth += l.count("{") - l.count("}")
BUILTIN = {"extern", "const", "volatile", "static", "unsigned", "signed", "void", "char", "short", "int", "long", "float", "double",
           "struct", "union", "enum", "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "register"}
TYPEDEFS = set()
for path in (root / "include").glob("*.h"):
    txt = path.read_text(errors="replace")
    TYPEDEFS.update(re.findall(r"typedef\s+[^;{}]*?\b([A-Za-z_]\w*)\s*(?:\[[^]]*\])?\s*;", txt))
    TYPEDEFS.update(re.findall(r"(?m)^\}\s*([A-Za-z_]\w*)\s*;", txt))
depth = 0  # the unit's own typedefs: file scope only (a typedef inside a function body is not visible to a stub)
for c in chunks:
    for l in src[c[2]:c[3]]:
        if c[0] == "other" and depth == 0:
            TYPEDEFS.update(re.findall(r"^typedef\s+[^;{}]*?\b([A-Za-z_]\w*)\s*(?:\[[^]]*\])?\s*;", l))
            TYPEDEFS.update(re.findall(r"^\}\s*([A-Za-z_]\w*)\s*;", l))
        depth += l.count("{") - l.count("}")
def visible(line):  # every word used as a type is a builtin or a file-scope typedef
    head = line.split("(")[0] if "func_" in line else line
    words = [w for w in re.findall(r"[A-Za-z_]\w*", head) if not re.match(r"(?:func|D|jtbl)_[0-9A-Fa-f]{8}$", w)]
    return all(w in BUILTIN or w in TYPEDEFS for w in words)
def leftovers(c):
    """The lines a removed function chunk leaves in its place."""
    out = []
    body = src[c[2]:c[3]]
    if (pr := prototype(c)): out.append(pr)
    undefd = {m.group(1) for l in body if (m := re.match(r"\s*#\s*undef\s+(\w+)", l))}
    k = 0
    while k < len(body):  # a #define with its continuation lines
        m = re.match(r"\s*#\s*define\s+(\w+)", body[k]); k0 = k
        while body[k].rstrip().endswith("\\") and k + 1 < len(body): k += 1
        if m and m.group(1) not in undefd: out += [l.strip() if j == k0 else l.rstrip() for j, l in enumerate(body[k0:k + 1], k0)]
        k += 1
    decls, seen = [], set()
    for l in body:
        if not ((re.match(r"^\s+extern\s+[^;{}()]*(\([^;{}]*\))?[^;{}]*;\s*$", l)
                 or (re.match(r"^\s+[A-Za-z_]\w*(\s+[A-Za-z_]\w*)*\s+\**func_[0-9A-F]{8}\s*\([^{;]*\)\s*;\s*$", l)
                     and not re.match(r"^\s+(return|if|else|while|for|do|switch|case|goto)\b", l)))
                and visible(l)): continue
        ids = tuple(re.findall(r"\b(?:func|D|jtbl)_[0-9A-Fa-f]{8}\b", l))
        if any(i in seen for i in ids): continue  # the same name again in another block of that function: first wins
        seen.update(ids); decls.append(l.strip())
    if decls: out.append(f"static inline void split_externs_{c[1]:08X}(void) {{ " + " ".join(decls) + " }")
    return out
tags = {n: t for _, n, t in pieces}
starts = {n: st for st, n, _ in pieces}
for _, name, tag in pieces:
    if tag == "ASM": continue
    out = []
    for c in chunks:
        if c[0] == "other" or piece_of(c[1]) == name: out.extend(src[c[2]:c[3]])
        else: out.extend(leftovers(c))
    text = "\n".join(out).replace(f'"asm/nonmatchings/{unit}"', f'"asm/nonmatchings/{name}"')
    (root / "src" / f"{name}.c").write_text(text)
# ---- asm dirs: each piece gets its functions' .s (moved out of the unit's dir)
for _, name, tag in pieces:
    if tag != "ASM": (root / "asm/nonmatchings" / name).mkdir(parents=True, exist_ok=True)
pads = {c[1] for c in chunks if c[0] == "fn" and PAD.match(src[c[2]]) or (c[0] == "fn" and c[3] - c[2] > 1 and PAD.match(src[c[2] + 1]))}
# ---- ASM pieces: one assembled segment each, written before the per-function .s files move
baserom = None
for i, (st, name, tag) in enumerate(pieces):
    if tag != "ASM": continue
    if st == 0: sys.exit("the first piece cannot be ASM: the unit keeps its C file")
    end = pieces[i + 1][0] if i + 1 < len(pieces) else a.vram_end
    if end is None: sys.exit(f"{name}: the last piece is ASM, give --vram-end")
    if baserom is None: baserom = (root / "baserom.z64").read_bytes()
    rom_of = lambda v: a.rom_start + (v - a.vram_start)
    pad_at = {c[1] for c in chunks if c[0] == "fn" and c[1] in pads}
    body = ['.include "macro.inc"', "", ".set noat", ".set noreorder", ".set gp=64", "", '.section .text, "ax"', "",
            f"/* Hand-written routines, VRAM 0x{st:08X}-0x{end:08X}, ROM 0x{rom_of(st):X}-0x{rom_of(end):X}:",
            "   the functions' .s bodies in address order, the alignment padding between them as words. */", ""]
    cur = st
    def gap(lo, hi):
        if lo == hi: return
        if lo > hi or (hi - lo) % 4: sys.exit(f"{name}: bad gap 0x{lo:08X}-0x{hi:08X}")
        if not any(lo <= p < hi for p in pad_at): print(f"warning: {name}: 0x{lo:08X}-0x{hi:08X} is no padding block in the C file")
        body.append(f"dlabel D_{lo:08X}_padding")
        for v in range(lo, hi, 4):
            r = rom_of(v); w = int.from_bytes(baserom[r:r + 4], "big")
            body.append(f"    /* {r:X} {v:08X} {w:08X} */ .word 0x{w:08X}")
        body.extend([f"enddlabel D_{lo:08X}_padding", ""])
    for f in [f for f in fns if piece_of(f) == name and f not in pads]:
        s = (Path(a.asm_src) / f"func_{f:08X}.s").read_text()
        m = re.search(r"^nonmatching func_[0-9A-F]{8}, (0x[0-9A-Fa-f]+)", s, re.M)
        if not m: sys.exit(f"func_{f:08X}.s: no size")
        gap(cur, f)
        body += [l for l in s.rstrip("\n").split("\n") if not l.startswith("nonmatching ")] + [""]
        cur = f + int(m.group(1), 16)
    gap(cur, end)
    (root / "asm" / f"{name}.s").write_text("\n".join(body))
for f in fns:
    if f in pads: continue
    sname = f"func_{f:08X}.s"; dst = root / "asm/nonmatchings" / piece_of(f) / sname; srcp = Path(a.asm_src) / sname
    if not srcp.exists(): sys.exit(f"no .s for func_{f:08X}")
    in_unit = srcp.parent.resolve() == (root / "asm/nonmatchings" / unit).resolve()
    if tags[piece_of(f)] == "ASM":  # now part of asm/<piece>.s
        if in_unit: srcp.unlink()
        continue
    if srcp.resolve() != dst.resolve():
        shutil.copy(srcp, dst)
        if in_unit: srcp.unlink()
# ---- expected objects, assembled from the .s files (nothing else may transform them: --fp-move-nops keeps mul.s in slots)
env = dict(os.environ, COMPILER_PATH=str(root / "tools/gcc_2.7.2/linux"))
for _, name, tag in pieces:
    if tag == "ASM": continue
    mine = [f for f in fns if piece_of(f) == name and f not in pads]
    skel = root / "build" / f"skel_{name}.c"; skel.parent.mkdir(exist_ok=True)
    skel.write_text('#include "common.h"\n\n' + "".join(f'INCLUDE_ASM("asm/nonmatchings/{name}", func_{f:08X});\n\n' for f in mine))
    (root / "expected/src").mkdir(parents=True, exist_ok=True)
    cmd = [str(root / "tools/gcc_2.7.2/linux/gcc"), f"-B{root}/tools/build/", "-O2", "-G0", "-mips3", "-mgp32", "-mfp32", "-Wa,--fp-move-nops",
           "-Wa,-mabi=32", "-Wa,-Iinclude", "-D_LANGUAGE_C", "-Iinclude", "-Ibuild/include", "-Isrc", "-DF3DEX_GBI_2", "-c", str(skel.relative_to(root)), "-o", f"expected/src/{name}.o"]   # relative: the object's FILE symbol must not carry this machine's home path
    r = subprocess.run(cmd, cwd=root, env=env, capture_output=True, text=True)
    if r.returncode: sys.exit(f"expected {name}: {r.stderr[-800:]}")
    nm = subprocess.run(["mips-linux-gnu-nm", "--defined-only", str(root / "expected/src" / f"{name}.o")], capture_output=True, text=True).stdout
    have = {ln.split()[-1] for ln in nm.splitlines() if ln.strip()}
    want = {f"func_{f:08X}" for f in mine}
    if want - have: sys.exit(f"expected {name}: symbols missing after assembly: {sorted(want - have)[:8]}")
    skel.unlink()
# ---- glover.yaml: subsegments
y = (root / "glover.yaml").read_text()
line = f"      - [0x{a.rom_start:X}, c, {unit}]\n"
assert line in y, "yaml subsegment line not found"
new = line + "".join(f"      - [0x{a.rom_start + (st - a.vram_start):X}, {'asm' if t == 'ASM' else 'c'}, {n}]\n" for st, n, t in bounds)
(root / "glover.yaml").write_text(y.replace(line, new))
# ---- glover.ld: the pieces' objects after the unit's, per section
ld = (root / "glover.ld").read_text()
obj = lambda n: f"build/asm/{n}.o" if tags[n] == "ASM" else f"build/src/{n}.o"
for sec in (".text", ".rodata", ".data", ".bss"):
    old = f"        build/src/{unit}.o({sec});\n"
    assert old in ld, f"ld line for {sec}"
    ld = ld.replace(old, old + "".join(f"        {obj(n)}({sec});\n" for _, n, _ in bounds))
(root / "glover.ld").write_text(ld)
# ---- objdiff.json
od = json.loads((root / "objdiff.json").read_text())
names = [u["name"] for u in od["units"]]
for _, n, t in bounds:
    if t == "ASM": continue
    if f"src/{n}" not in names:
        base = next((u for u in od["units"] if u["name"] == f"src/{unit}"), {})
        tag = next(t for _, nn, t in pieces if nn == n)
        scratch = dict(base.get("scratch") or {})
        if "c_flags" in scratch:
            fl = scratch["c_flags"]
            if tag == "LIB": fl = " ".join(x for x in fl.split() if x not in ("-g2", "-Wa,--no-float-doubleword", "-Wa,--fp-move-nops")) + " -Wa,--fp-move-nops"
            if tag == "O0": fl = fl.replace("-O2", "-O0")
            if tag == "LIBGCC": fl = " ".join(x for x in fl.split() if x not in ("-g2", "-Wa,--fp-move-nops")) + " -g2"
            scratch["c_flags"] = " ".join(fl.split())
        od["units"].append({"name": f"src/{n}", "target_path": f"expected/src/{n}.o", "base_path": f"build/src/{n}.o",
                            "metadata": {"source_path": f"src/{n}.c", "progress_categories": list((base.get("metadata") or {}).get("progress_categories", ["game"]))},
                            **({"scratch": scratch} if scratch else {})})
(root / "objdiff.json").write_text(json.dumps(od, indent=2) + "\n")
# ---- Makefile flags per piece: the blocks replace the unit's own override, in its place (or end the override list)
mk = (root / "Makefile").read_text().split("\n")
own = re.compile(rf"^(# {re.escape(unit)}: |\$\(BUILD_DIR\)/src/{re.escape(unit)}\.o: (OPTFLAGS|CFLAGS|PACK_TEXT) :=)")
at = next((k for k, l in enumerate(mk) if own.match(l)), None)
mk = [l for l in mk if not own.match(l)]
if at is None:
    at = mk.index("#### Per-file optimization overrides ####") + 1
    while at < len(mk) and (mk[at].startswith("$(BUILD_DIR)/") or mk[at].startswith("#") or mk[at].startswith("comma :=")): at += 1
blocks = {"LIB": lambda n: [f"# {n}: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops",
                            f"$(BUILD_DIR)/src/{n}.o: OPTFLAGS := -O2 -Wa,--fp-move-nops",
                            f"$(BUILD_DIR)/src/{n}.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))"],
          "LIBGCC": lambda n: [f"# {n}: libgcc helpers (__divdi3, __udivdi3, __udivmoddi4, __umoddi3), built with -g2: GAS leaves the jr slots unfilled",
                               f"$(BUILD_DIR)/src/{n}.o: OPTFLAGS := -O2 -g2"],
          "O0": lambda n: [f"$(BUILD_DIR)/src/{n}.o: OPTFLAGS := -O0 -g2"], "GAME": lambda n: [], "ASM": lambda n: []}
add = []
for i, (st, n, tag) in enumerate(pieces):
    add += blocks[tag](n)
    lo = a.vram_start if st == 0 else st
    hi = pieces[i + 1][0] if i + 1 < len(pieces) else (a.vram_end or 0)
    if lo % 16 or hi % 16:  # the piece starts or ends inside a 16-byte line: no alignment, no tail padding
        add.append(f"$(BUILD_DIR)/{'asm' if tag == 'ASM' else 'src'}/{n}.o: PACK_TEXT := 1")
mk[at:at] = add
if "comma := ," not in mk: mk.insert(mk.index("#### Per-file optimization overrides ####") + 1, "comma := ,")
(root / "Makefile").write_text("\n".join(mk))
print("done:", ", ".join(n for _, n, _ in pieces))
