#!/usr/bin/env python3
"""Compile an IDO unit through asm-processor so its INCLUDE_ASM stubs become real code in the object.

Usage is asm-processor's build.py syntax: ido_build.py <compiler...> -- <assembler...> -- <compile args> -o OUT IN
The INCLUDE_ASM("dir", name); stubs of IN (GCC's macro, defined empty for IDO in include/common.h, which left every
stubbed function out of the linked ROM) are rewritten to asm-processor's GLOBAL_ASM("dir/name.s") in a copy next to
OUT, and build.py splices the assembled .s into the compiled object. Drafts and matched functions are untouched.
"""
import os, re, sys, subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
args = sys.argv[1:]
try:
    out = args[args.index('-o') + 1]
except (ValueError, IndexError):
    sys.exit('ido_build.py: missing -o argument')
src = args[-1]
stub = re.compile(r'^(\s*)INCLUDE_ASM\("([^"]+)",\s*(\w+)\)\s*;')
with open(src, encoding='utf-8', errors='surrogateescape') as f:
    lines = f.read().split('\n')
n = 0
for i, ln in enumerate(lines):
    m = stub.match(ln)
    if m:
        lines[i] = '%sGLOBAL_ASM("%s/%s.s")' % (m.group(1), m.group(2), m.group(3))
        n += 1
copy = os.path.splitext(out)[0] + '.asmproc.c'
os.makedirs(os.path.dirname(copy) or '.', exist_ok=True)
with open(copy, 'w', encoding='utf-8', errors='surrogateescape') as f:
    f.write('\n'.join(lines))
args[-1] = copy
cmd = [sys.executable, os.path.join(ROOT, 'tools/asm-processor/build.py'), '--no-dep-file'] + args
r = subprocess.run(cmd)
sys.exit(r.returncode)
