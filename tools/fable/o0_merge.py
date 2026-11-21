#!/usr/bin/env python3
"""After split_unit.py on 18020_1D7F0: fold src/18020_O0.c's functions into the -O0 pieces, drop the 18020_O0 unit,
and tidy the first piece's nonmatchings dir. usage: o0_merge.py --root DIR --unit 18020_1D7F0"""
import argparse, json, re, shutil
from pathlib import Path
ap = argparse.ArgumentParser(); ap.add_argument("--root", required=True); ap.add_argument("--unit", required=True); a = ap.parse_args()
root = Path(a.root); unit = a.unit
o0 = (root / "src/18020_O0.c").read_text().split("\n")
# chunk O0.c like split_unit does
def def_start(src, i):
    l = src[i]
    if re.match(r"^[A-Za-z_][\w \*]*\bfunc_[0-9A-F]{8}\s*\(", l) and not l.rstrip().endswith(";"):
        j = i
        while j < len(src) and "{" not in src[j]: j += 1
        return j < len(src)
    return False
chunks = []; i = 0
while i < len(o0):
    if def_start(o0, i):
        m = re.search(r"func_([0-9A-F]{8})", o0[i]); j = i; d = 0; seen = False
        while j < len(o0):
            d += o0[j].count("{") - o0[j].count("}")
            if "{" in o0[j]: seen = True
            if seen and d == 0: break
            j += 1
        chunks.append(("fn", m.group(1), o0[i:j + 1])); i = j + 1; continue
    chunks.append(("other", None, [o0[i]])); i += 1
shared = [ln for k, _, lines in chunks for ln in lines if k == "other" and ln.strip() and not ln.startswith("#include")]
fns = {addr: lines for k, addr, lines in chunks if k == "fn"}
od = json.loads((root / "objdiff.json").read_text())
pieces = [u["name"].split("/", 1)[1] for u in od["units"] if u["name"].startswith("src/18020_") and u["name"] != "src/18020_O0"]
placed = 0; touched = set()
IDENT = re.compile(r"\b((?:func|D)_[0-9A-Fa-f]{8})\b")
def declared_before(text, pos):
    depth = 0; out = set()
    for ln in text[:pos].split("\n"):
        if depth == 0 and ln.rstrip().endswith(";"): out.update(IDENT.findall(ln))
        depth += ln.count("{") - ln.count("}")
    return out
for addr, lines in fns.items():
    for p in pieces:
        f = root / "src" / f"{p}.c"
        if not f.exists(): continue
        text = f.read_text()
        inc = f'INCLUDE_ASM("asm/nonmatchings/{p}", func_{addr});'
        if inc in text:
            pos = text.index(inc); have = declared_before(text, pos); used = set(IDENT.findall("\n".join(lines)))
            need = [ln for ln in shared if (ids := set(IDENT.findall(ln))) and ids & used and not ids & have]
            print(f"  func_{addr} -> {p}: {len(need)} declarations added")
            f.write_text(text.replace(inc, ("\n".join(need) + "\n" if need else "") + "\n".join(lines))); placed += 1; touched.add(p)
            (root / "asm/nonmatchings" / p / f"func_{addr}.s").unlink(missing_ok=True)
            break
    else:
        raise SystemExit(f"func_{addr}: no piece has its INCLUDE_ASM")
print(f"placed {placed} -O0 functions into {sorted(touched)}")
# drop the 18020_O0 unit
(root / "src/18020_O0.c").unlink(); (root / "expected/src/18020_O0.o").unlink(missing_ok=True)
shutil.rmtree(root / "asm/nonmatchings/18020_O0", ignore_errors=True)
od["units"] = [u for u in od["units"] if u["name"] != "src/18020_O0"]
(root / "objdiff.json").write_text(json.dumps(od, indent=2) + "\n")
mk = (root / "Makefile").read_text()
mk = mk.replace("# -O0 functions in the game segment need separate compilation\n", "").replace("$(BUILD_DIR)/src/18020_O0.o: OPTFLAGS := -O0 -g2\n", "")
(root / "Makefile").write_text(mk)
# tidy: the first piece's dir keeps only its own functions' .s
first = root / "src" / f"{unit}.c"; mine = set(re.findall(r"func_([0-9A-F]{8})", first.read_text()))
own = set(re.findall(r'INCLUDE_ASM\("asm/nonmatchings/' + unit + r'", func_([0-9A-F]{8})\)', first.read_text()))
defs = set(re.findall(r"(?m)^[A-Za-z_][\w \*]*\bfunc_([0-9A-F]{8})\s*\([^;]*\)\s*\{", first.read_text()))
keep = own | defs
removed = 0
for f in (root / "asm/nonmatchings" / unit).glob("func_*.s"):
    if f.stem[5:] not in keep: f.unlink(); removed += 1
print(f"tidied {removed} stale .s from {unit}")
