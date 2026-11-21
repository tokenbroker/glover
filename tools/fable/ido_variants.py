#!/usr/bin/env python3
"""ido_variants.py FN VARFILE [-j N] [-r ROWS] [--unit UNIT] [--flags EXTRA] [--cc71|--cc53] [--unroll]
Off-tree variant loop (any unit whose Makefile command names its source and object; written for the IDO unit): VARFILE holds candidate bodies separated by '=====' lines. Each one
replaces FN's definition (or INCLUDE_ASM stub) in a scratch copy of src/UNIT.c, the copy is compiled with the
unit's IDO command into the scratch dir and judged with objdiff-cli. The live tree is never written. Run from the repo root; scratch files go to $SCRATCH (default /tmp/ido_variants).
A line '//@@old|||new' inside a variant edits the unit copy (a prototype, a call site) before the body is spliced in."""
import re, subprocess, sys, json, os, argparse, concurrent.futures as cf
ap = argparse.ArgumentParser(); ap.add_argument('fn'); ap.add_argument('varfile'); ap.add_argument('-j', type=int, default=4)
ap.add_argument('-r', type=int, default=0); ap.add_argument('--unit', default='18020_C0800'); ap.add_argument('--flags', default='')
ap.add_argument('--src', default=None); ap.add_argument('--unroll', action='store_true'); ap.add_argument('--cc71', action='store_true'); ap.add_argument('--cc53', action='store_true')
A = ap.parse_args(); fn, unit = A.fn, A.unit
S = os.environ.get('SCRATCH') or os.path.join(os.environ.get('TMPDIR', '/tmp'), 'ido_variants'); os.makedirs(S, exist_ok=True); ROOT = os.getcwd()  # scratch dir: $SCRATCH
path = A.src or f'src/{unit}.c'; src = open(path).read()
m = re.search(r'INCLUDE_ASM\("[^"]*", ' + fn + r'\);', src)
if not m:
    h = re.search(r'^[A-Za-z_][^\n;{]*\b' + fn + r'\s*\([^;{]*\)\s*(?:[^;{}]*;\s*)*\{', src, re.M)
    assert h, 'function not found'
    i = h.start(); j = src.index('{', h.start()); depth = 0; k = j
    while True:
        depth += (src[k] == '{') - (src[k] == '}'); k += 1
        if depth == 0: break
    while src[k] != '\n': k += 1
    orig = src[i:k+1]
else:
    orig = m.group(0)
variants = [v.strip('\n') + '\n' for v in open(A.varfile).read().split('=====\n') if v.strip()]
OD = os.path.expanduser('~/.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli')
import shlex
_cmd = subprocess.run(['make', '-s', '-n', '-B', 'RUN_CC_CHECK=0', f'build/src/{unit}.o'], capture_output=True, text=True).stdout
_line = [l for l in _cmd.split('\n') if f'src/{unit}.c' in l and f'build/src/{unit}.o' in l][-1]
CC = shlex.split(_line)
CC = CC[:CC.index('-c')] + A.flags.split()   # the Makefile's own command (compiler, assembler, flags), minus '-c -o out in'
if A.unroll and '-Wo,-loopunroll,0' in CC: CC.remove('-Wo,-loopunroll,0')
if A.cc71: CC[2] = 'tools/ido-static-recomp/build/7.1/out/cc'
if getattr(A, 'cc53', False): CC[2] = 'tools/ido-static-recomp/build/5.3/out/cc'
def fmt(r): return (r.get('instruction') or {}).get('formatted', '')
def one(i, v):
    d = f'{S}/vt_{fn}_{i}'; os.makedirs(d, exist_ok=True)
    c = f'{d}/unit.c'; o = f'{d}/unit.o'
    reps = [l[4:].split('|||', 1) for l in v.split('\n') if l.startswith('//@@')]
    body = '\n'.join(l for l in v.split('\n') if not l.startswith('//@@'))
    u = src.replace(orig, body)
    for a, b in reps:
        assert a in u, 'replacement not found: ' + a
        u = u.replace(a, b)
    open(c, 'w').write(u)
    r = subprocess.run(CC + ['-c', '-o', o, c], capture_output=True, text=True)
    if r.returncode or not os.path.exists(o):
        err = [l for l in (r.stderr + r.stdout).split('\n') if 'rror' in l or 'ERROR' in l][:4]
        return f'compile error: ' + ' | '.join(err)
    subprocess.run([OD, 'diff', '-1', f'expected/src/{unit}.o', '-2', o, '-c', 'functionRelocDiffs=none', '-c', 'combineDataSections=true', '-c', 'combineTextSections=true', '-o', f'{d}/diff.json', '--format', 'json', fn], capture_output=True)
    dj = json.load(open(f'{d}/diff.json'))
    L = next(s for s in dj['left']['symbols'] if s['name'] == fn); R = next(s for s in dj['right']['symbols'] if s['name'] == fn)
    rows = [(k, a, b) for k, (a, b) in enumerate(zip(L['instructions'], R['instructions'])) if a.get('diff_kind', 'DIFF_NONE') != 'DIFF_NONE' or b.get('diff_kind', 'DIFF_NONE') != 'DIFF_NONE']
    out = f"{L.get('match_percent', R.get('match_percent')):.1f}% ({len(rows)} rows, {len(L['instructions'])} vs {len(R['instructions'])})"
    if A.r:
        out += '\n' + '\n'.join(f"     {k:4d} T {fmt(a):40s} D {fmt(b)}" for k, a, b in rows[:A.r])
    return out
with cf.ThreadPoolExecutor(A.j) as ex:
    futs = [ex.submit(one, i, v) for i, v in enumerate(variants)]
    for i, f in enumerate(futs): print(f'variant {i+1}: {f.result()}', flush=True)
