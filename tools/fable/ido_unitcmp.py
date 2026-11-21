#!/usr/bin/env python3
"""ido_unitcmp.py: compile the live IDO unit under several compiler/flag configs off-tree and compare per-function
scores (how the 5.3 -> 7.1 and unroller decisions were made on 2026-10-31). Scratch files go to $SCRATCH or /tmp."""
import subprocess, json, os, sys, concurrent.futures as cf
S = os.environ.get('SCRATCH') or '/tmp/ido_unitcmp'; os.makedirs(S, exist_ok=True); unit = '18020_C0800'
OD = os.path.expanduser('~/.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli')
AS = ['--', 'mips-linux-gnu-as', '-march=vr4300', '-32', '-G0', '-EB', '-Iinclude', '-I.', '--']
COMMON = ['-G0', '-non_shared', '-Xcpluscomm', '-Wab,-r4300_mul', '-woff', '649,838,712', '-mips2', '-Iinclude', '-Ibuild/include', '-Isrc', '-DF3DEX_GBI_2', '-D_LANGUAGE_C']
cfgs = {
 '53on':  ['tools/ido-static-recomp/build/5.3/out/cc', '-O2'],
 '53off': ['tools/ido-static-recomp/build/5.3/out/cc', '-O2', '-Wo,-loopunroll,0'],
 '71on':  ['tools/ido-static-recomp/build/7.1/out/cc', '-O2'],
 '71off': ['tools/ido-static-recomp/build/7.1/out/cc', '-O2', '-Wo,-loopunroll,0'],
}
def build(k):
    cc, *fl = cfgs[k]; d = f'{S}/uc2_{k}'; os.makedirs(d, exist_ok=True)
    r = subprocess.run(['python3', 'tools/fable/ido_build.py', cc] + AS + fl + COMMON + ['-c', '-o', f'{d}/unit.o', f'src/{unit}.c'], capture_output=True, text=True)
    if r.returncode or not os.path.exists(f'{d}/unit.o'): return k, None, (r.stderr + r.stdout)[-600:]
    subprocess.run([OD, 'diff', '-1', f'expected/src/{unit}.o', '-2', f'{d}/unit.o', '-c', 'functionRelocDiffs=none', '-c', 'combineDataSections=true', '-c', 'combineTextSections=true', '-o', f'{d}/diff.json', '--format', 'json'], capture_output=True)
    dj = json.load(open(f'{d}/diff.json'))
    res = {s['name']: (s.get('match_percent') or 0.0, len(s.get('instructions') or [])) for s in dj['left']['symbols'] if s.get('name','').startswith('func_')}
    return k, res, ''
with cf.ThreadPoolExecutor(4) as ex:
    out = {k: (r, e) for k, r, e in ex.map(build, cfgs)}
for k, (r, e) in out.items():
    if r is None: print(k, 'FAILED', e)
ks = [k for k in cfgs if out[k][0]]
print('config   matched  sum%')
for k in ks: print(f'{k:8s} {sum(1 for v in out[k][0].values() if v[0] == 100):4d}  {sum(v[0] for v in out[k][0].values()):8.1f}')
names = sorted(out[ks[0]][0])
print('\nfunctions whose score differs between configs (insns, then ' + ' '.join(ks) + ')')
for n in names:
    vals = [out[k][0].get(n, (0, 0))[0] for k in ks]
    if max(vals) != min(vals): print(f"{n} {out[ks[0]][0][n][1]:4d}  " + '  '.join(f'{v:6.1f}' for v in vals))
