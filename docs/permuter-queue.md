# Near misses for Claude and Codex

Regenerated 2026-11-20 19:07 by the hourly editor pass (`tools/editor_pass.py`) from the decomp.wtf database. Game units only, D910 first, then by score. Claim by name: `claim_function(function="func_XXXXXXXX")`, picking a random line from the first 40. If the tool says a line is already matched or hands you a different function instead, release the substitute at once (note `substituted`) and pick another line. Work what you claim: start from the best attempt, compile, up to about 25 compiles while the score moves, then release with notes. A function you have already released this session is not yours to claim again.

## Big drafts in progress: Claude Opus and Sonnet, one at a time

The largest functions, drafted by Fable with `tools/m2c_draft.py` (m2c, cleaned up until the unit compiles) and left with a handoff note. The leg work is yours: read the `[editor]` note and the handoff note on the function, then work the diff from the top one region per compile, with compile_and_diff on the whole function. Budget 40 compiles before releasing; release with a note that says the row where you stopped and what the next region needs. Do not restart from m2c: the draft in the tree is the starting point.

| Function | File | Size (bytes) | Score | Compiles |
|---|---|---:|---:|---:|
| (none) | | |

## Near misses under 40 compiles

The Diff column is the editor pass's row-by-row read of the current draft with the judge's own settings (struct = instruction count or opcode differs, stack = frame size, branch = target off, nop = hazard nop, imm = constant or offset, reg = registers only, wrongaddr = a relocation resolves to a different address than the target's, which the judge cannot see); each function also carries a `[editor]` note with the detail.

| Function | File | Size (bytes) | Score | Compiles | Diff |
|---|---|---:|---:|---:|---|
| (none) | | | | | |

## Permuter only: 40 or more compiles

Release on sight with the note `permuter queue`. Every spelling tried gives the same one-register diff; the permuter works these in the background.

| Function | File | Size (bytes) | Score | Compiles |
|---|---|---:|---:|---:|
| (none) | | |

## Drafts below 90%: structure first

Every open game function with a draft that is not a near miss (the largest ones are in the first table). Any model: read the notes, list the rows where a branch target or an instruction count differs, fix the control flow and the struct layout before any register work, and leave a handoff note at about 25 compiles.

| Function | File | Size (bytes) | Score | Compiles |
|---|---|---:|---:|---:|
| (none) | | |

## Library unit `src/18020_C5030.c` and its pieces: libultra, port from ultralib

0 open functions, built without `-g` with `ldc1`/`sdc1` doubles. Claimable: `docs/library-candidates.md` names the ultralib file to copy from; write the upstream source verbatim with the right struct layout. Hardware registers and KSEG bases are literals (`*(volatile u32 *)0xA4600010`, `x | 0xA0000000`), never `D_A4xxxxxx` symbols.

| Function | File | Size (bytes) | Score | Compiles |
|---|---|---:|---:|---:|
| (none) | | |
