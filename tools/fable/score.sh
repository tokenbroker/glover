#!/usr/bin/env bash
# usage: FN=func_XXXXXXXX UNIT=18020_1D7F0 SCRATCH=/tmp/dir [SRC=path/to/unit.c] tools/fable/score.sh <draft.c>
# SRC overrides the unit source (default src/$UNIT.c); use a HEAD copy when the app's permuter is mutating the tree.
# Splices the draft into src/$UNIT.c, compiles the unit with the project compiler, runs objdiff with the
# judge's settings and prints the match percent + diff classes. Leaves $SCRATCH/unit_try.{c,o} and $SCRATCH/diff.json.
set -u; cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."; : "${FN:?set FN}" "${UNIT:?set UNIT}" "${SCRATCH:?set SCRATCH}"; mkdir -p "$SCRATCH"
python3 -I - "$1" <<'PY'
import re,sys,os
FN=os.environ['FN']; UNIT=os.environ['UNIT']; S=os.environ['SCRATCH']
s=open(sys.argv[1]).read(); u=open(os.environ.get('SRC') or f'src/{UNIT}.c').read()
m=re.search(r'INCLUDE_ASM\("[^"]*", '+FN+r'\);', u)
if m: out=u[:m.start()]+s+u[m.end():]
else:
    m=re.search(r'(?m)^[A-Za-z_][\w \*]*\b'+FN+r'\([^;\n]*\)(?:\n[^\n{]*;)*\s*\{', u)  # K&R definitions too
    if not m: sys.exit(f'{FN} not found in src/{UNIT}.c')
    i=m.start(); j=u.index('{',i); depth=0; k=j
    while True:
        depth+= (u[k]=='{')-(u[k]=='}'); k+=1
        if depth==0: break
    out=u[:i]+s.rstrip('\n')+u[k:]
open(S+'/unit_try.c','w').write(out)
PY
export COMPILER_PATH=$PWD/tools/gcc_2.7.2/linux
# the unit's own compile command from the Makefile (KMC GCC for most units, IDO 5.3 for src/18020_C0800.c): the
# make -n line that names both the source and the object, with the scratch copy in place of the source
CMD=$(make -s -n -B RUN_CC_CHECK=0 "build/src/$UNIT.o" 2>/dev/null | grep -F "src/$UNIT.c" | grep -F "build/src/$UNIT.o" | tail -1 | sed -E 's/^export COMPILER_PATH=[^ ]+ && //')
[ -n "$CMD" ] || CMD="tools/gcc_2.7.2/linux/gcc -Btools/build/ -O2 -g2 -G0 -mips3 -mgp32 -mfp32 -Wa,--no-float-doubleword -Wa,-mabi=32 -Wa,-Iinclude -D_LANGUAGE_C -DF3DEX_GBI_2 -Iinclude -Isrc -c -o build/src/$UNIT.o src/$UNIT.c"
CMD=${CMD//build\/src\/$UNIT.o/$SCRATCH/unit_try.o}; CMD=${CMD//src\/$UNIT.c/$SCRATCH/unit_try.c}
eval "$CMD" > $SCRATCH/unit_try.log 2>&1 || { echo "COMPILE FAILED"; grep -vE 'warning:|Warning' $SCRATCH/unit_try.log | grep -E '^[^:]+:[0-9]+: |Error' | grep -vE 'In function|At top level' | head -8; exit 1; }
$HOME/.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli diff -1 expected/src/$UNIT.o -2 $SCRATCH/unit_try.o -c functionRelocDiffs=none -o $SCRATCH/diff.json --format json $FN >/dev/null 2>&1
python3 -I - <<'PY'
import json, sys, os
sys.path.insert(0,'tools'); import editor_pass as e
FN=os.environ['FN']; S=os.environ['SCRATCH']
d=json.load(open(S+'/diff.json'))
L=next(s for s in d['left']['symbols'] if s.get('name')==FN); R=next(s for s in d['right']['symbols'] if s.get('name')==FN)
cls=e.classify(d,FN)
print('match', round(L.get('match_percent',0),2), '% rows', len(L['instructions']), len(R['instructions']), 'classes', cls['counts'] if cls else None, 'stack', cls['stack'] if cls else None)
PY
