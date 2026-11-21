#!/usr/bin/env python3
"""Link-level address audit: for every function whose draft matches the target row for row, compare the ADDRESS each
relocation resolves to (the judge masks relocation fields, so a draft naming the neighbouring pool double or the
wrong callee still scores 100%). Reads expected/src/*.o against build/src/*.o (run `make RUN_CC_CHECK=0` first) and
resolves symbols through symbol_addrs.txt, undefined_syms_auto.txt, undefined_funcs_auto.txt and the D_/func_
naming. Usage: addr_audit.py [--all] [unit ...]; without --all only functions the app lists as matched are reported."""
import os, re, sys, glob, json, sqlite3, subprocess, collections

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
OBJDUMP = os.environ.get('OBJDUMP', 'mips-linux-gnu-objdump')

SYMS = {}
for f in ('symbol_addrs.txt', 'undefined_syms_auto.txt', 'undefined_funcs_auto.txt'):
    if os.path.exists(f):
        for m in re.finditer(r'^\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;', open(f).read(), re.M):
            SYMS.setdefault(m.group(1), int(m.group(2), 16))

def addr_of(name):
    if name in SYMS:
        return SYMS[name]
    m = re.match(r'^(?:D|func|jtbl|L)_([0-9A-Fa-f]{8})$', name)
    return int(m.group(1), 16) if m else None

def symtab(obj):
    """section -> sorted [(offset, name)] of named function/object symbols."""
    out = subprocess.run([OBJDUMP, '-t', obj], capture_output=True, text=True).stdout
    secs = collections.defaultdict(dict)
    for ln in out.splitlines():
        m = re.match(r'^([0-9a-f]{8})\s+(\S+)\s+(\S+)?\s*(\.\S+)\s+([0-9a-f]{8})\s+(\S+)$', ln)
        if not m:
            continue
        off, sec, name = int(m.group(1), 16), m.group(4), m.group(6)
        if name.endswith('.NON_MATCHING') or name.startswith('.L') or name.startswith('$'):
            continue
        secs[sec].setdefault(off, name)
    return secs

def functions(obj):
    """name -> list of (mnemonic, resolved address or None, reloc text) per instruction. MIPS objects carry REL
    relocations: the addend sits in the instruction word, so only LO16 (sign-extended immediate), 26-bit jump and
    32-bit word relocations give a complete address; HI16 halves are skipped (their value depends on the LO16 pair)."""
    secs = symtab(obj)
    out = subprocess.run([OBJDUMP, '-d', '-r', obj], capture_output=True, text=True).stdout
    funcs = collections.OrderedDict(); cur = None; word = 0
    for ln in out.splitlines():
        m = re.match(r'^[0-9a-f]+ <(\S+)>:', ln)
        if m:
            cur = m.group(1)
            if cur.endswith('.NON_MATCHING'):
                cur = None
            else:
                funcs[cur] = []
            continue
        if cur is None:
            continue
        m = re.match(r'^\s*[0-9a-f]+:\s+([0-9a-f]{8})\s+(\S+)', ln)
        if m:
            word = int(m.group(1), 16)
            funcs[cur].append((m.group(2), None, None))
            continue
        m = re.match(r'^\s*[0-9a-f]+:\s+(R_MIPS_\S+)\s+(\S+)', ln)
        if not m or not funcs[cur]:
            continue
        kind, base = m.group(1), m.group(2)
        a = None
        if kind == 'R_MIPS_LO16':
            imm = word & 0xffff
            imm = imm - 0x10000 if imm & 0x8000 else imm
            if not base.startswith('.'):
                ab = addr_of(base); a = ab + imm if ab is not None else None
        elif kind == 'R_MIPS_26':
            off = (word & 0x3ffffff) << 2
            if base == '.text':
                name = secs['.text'].get(off); a = addr_of(name) if name else None
            elif not base.startswith('.'):
                ab = addr_of(base); a = ab + off if ab is not None else None
        elif kind == 'R_MIPS_32':
            if not base.startswith('.'):
                ab = addr_of(base); a = ab + word if ab is not None else None
        else:
            continue
        mn, _, _ = funcs[cur][-1]
        funcs[cur][-1] = (mn, a, f"{base} ({kind.replace('R_MIPS_', '')}, {a:#x})" if a is not None else base)
    return funcs

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    show_all = '--all' in sys.argv
    units = args or sorted(os.path.basename(p)[:-2] for p in glob.glob('expected/src/*.o'))
    matched = set()
    try:
        c = sqlite3.connect('file:' + os.path.expanduser('~/Decomp/.decomp/decomp.db') + '?mode=ro', uri=True)
        pid = c.execute("select id from projects where slug='glover'").fetchone()[0]
        matched = {n for (n,) in c.execute("select name from functions where project_id=? and status='matched'", (pid,))}
    except Exception as e:
        print('no app database:', e, file=sys.stderr)
    report = {}
    for unit in units:
        e, b = f'expected/src/{unit}.o', f'build/src/{unit}.o'
        if not (os.path.exists(e) and os.path.exists(b)):
            continue
        E, B = functions(e), functions(b)
        for name, rows in E.items():
            if name not in B or len(B[name]) != len(rows):
                continue
            if [r[0] for r in rows] != [r[0] for r in B[name]]:
                continue                      # not row-aligned: an open draft, the judge sees those diffs itself
            if not show_all and name not in matched:
                continue
            bad = [(i, t[2], d[2]) for i, (t, d) in enumerate(zip(rows, B[name]))
                   if t[1] is not None and d[1] is not None and t[1] != d[1]]
            if bad:
                report[name] = {'unit': unit, 'matched': name in matched, 'rows': bad}
    for name, r in report.items():
        print(f"{name} ({r['unit']}{', matched' if r['matched'] else ''}): {len(r['rows'])} rows")
        seen = set()
        for i, t, d in r['rows']:
            if (t, d) in seen:
                continue
            seen.add((t, d)); print(f"    row {i}: target {t}  draft {d}")
    print(f"{len(report)} functions with a wrong resolved address", file=sys.stderr)
    if '--json' in sys.argv:
        json.dump(report, open('addr_audit.json', 'w'), indent=1)

if __name__ == '__main__':
    main()
