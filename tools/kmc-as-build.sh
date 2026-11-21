#!/usr/bin/env bash
# Rebuild tools/build/as (decompals/mips-binutils-2.6 + the seven patches in tools/), verify it against expected/
# on every unit (tools/fable/as_verify.py), and install it only when nothing is lost. Then rebuild the project and
# ask the app to re-measure. Usage: tools/kmc-as-build.sh [absolute path to a mips-binutils-2.6 checkout]
set -uo pipefail
G=$(cd "$(dirname "$0")/.." && pwd)
SRC=${1:-$HOME/Decomp/.decomp/binutils-src/mips-binutils-2.6}
case "$SRC" in /*) ;; *) echo "checkout path must be absolute: $SRC"; exit 1;; esac
OUT=$HOME/Decomp/.decomp/tc-scratch; mkdir -p "$OUT"
if [ ! -d "$SRC/.git" ]; then
  mkdir -p "$(dirname "$SRC")" && git clone -q https://github.com/decompals/mips-binutils-2.6 "$SRC" || exit 1
fi
cd "$SRC" || exit 1
git checkout -q 54514de && git reset -q --hard && git clean -qfdx
for p in no-float-doubleword kmc-as-fixes kmc-as-lw-dest-temp kmc-as-libultra-nops kmc-as-hilo-libultra kmc-as-pool-float kmc-as-lid-pair; do
  git apply --ignore-whitespace "$G/tools/$p.patch" || { echo "patch $p does not apply"; exit 1; }
done
CFL=$(sed -n "s/^       make -C {libiberty,bfd,opcodes,gas} CFLAGS='\(.*\)'.*$/\1/p" "$G/tools/kmc-as-fixes.patch" | head -1)
echo "configure..."; ./configure --target=mips-kmc-elf --host=i386-pc-linux --build=i386-pc-linux > "$OUT/configure.log" 2>&1 || { tail -5 "$OUT/configure.log"; exit 1; }
for d in libiberty bfd opcodes gas; do
  echo "make $d..."; make -C $d CFLAGS="$CFL" > "$OUT/make-$d.log" 2>&1 || { echo "make $d failed:"; tail -20 "$OUT/make-$d.log"; exit 1; }
done
ls -la gas/as.new || exit 1
cd "$G" || exit 1
echo "verify old vs new on every unit..."
python3 -I tools/fable/as_verify.py tools/build/as "$SRC/gas/as.new" 2>&1 | tee "$OUT/verify.log"
if [ "${PIPESTATUS[0]}" != "0" ]; then echo "NOT INSTALLED: a function was lost or a game unit changed (see $OUT/verify.log)"; exit 1; fi
# keep the first backup of the day: a rerun must not replace it with an already patched assembler
BK="tools/build/as.pre-libultra-nops-$(date +%Y%m%d)"; [ -e "$BK" ] || cp tools/build/as "$BK"
cp "$SRC/gas/as.new" tools/build/as && echo "installed tools/build/as (backup $BK)"
echo "rebuilding the project (make -B: the objects do not depend on the assembler)..."; make -B RUN_CC_CHECK=0 > "$OUT/make-glover.log" 2>&1 && echo "project rebuilt" || { tail -20 "$OUT/make-glover.log"; exit 1; }
SECRET=$(python3 -I -c "import json;print(json.load(open('$HOME/Decomp/.decomp/server.json'))['secret'])" 2>/dev/null)
if [ -n "$SECRET" ]; then
  echo "asking the app to re-measure..."
  curl -s -X POST http://127.0.0.1:6464/api/fork/check -H "User-Agent: decompdecomp-window/$SECRET" -H "X-Decomp: 1" -H "Content-Type: application/json" -d '{"slug":"glover"}' | head -c 300; echo
fi
echo "DONE"
