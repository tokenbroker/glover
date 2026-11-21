#!/usr/bin/env bash
# ido_tiny.sh file.c [unroll0]: compile a tiny file with IDO -O2 -mips2 (7.1 by default, CC71=path overrides; the unroller
# is on unless a 2nd arg is given) and print the disassembly: the fast way to test which C shape gives which instructions.
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
fl=""; [ -n "${2:-}" ] && fl="-Wo,-loopunroll,0"
o=${1%.c}.o
${CC71:-tools/ido-static-recomp/build/7.1/out/cc} -O2 -G0 -non_shared -Xcpluscomm -Wab,-r4300_mul $fl -woff 649,838,712 -mips2 -Iinclude -c -o $o $1 2>&1 | grep -iv warning
mips-linux-gnu-objdump -d -M reg-names=n32 $o | grep -E '^\s+[0-9a-f]+:|^[0-9a-f]+ <' | sed -E 's/^\s+[0-9a-f]+:\s+[0-9a-f]+\s+//'
