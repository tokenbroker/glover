# Fable's drafting tools for big functions

Local tools that attribute objdiff mismatches to draft source lines. They took
`func_8016A058` (30 KB) from 71% to 89% in one day by fixing the worst lines first.
All take the target from the environment:

    export FN=func_XXXXXXXX UNIT=18020_1D7F0 SCRATCH=/tmp/<your own dir>

- `score.sh <draft.c>`: splices the draft (the whole function definition, with its block-scope
  externs and macros) into `src/$UNIT.c` in place of the stub or the current body, compiles the
  unit with the project compiler, runs `objdiff-cli diff` with the judge's settings and prints the
  match percent plus the diff classes (`reg` = register only, `struct` = memory operand, `branch`,
  `nop`, `stack` = frame size, `wrongaddr`). Leaves `$SCRATCH/unit_try.{c,o,log}` and
  `$SCRATCH/diff.json`. The app's judge is the same objdiff; the percent is what the app shows.
- `lines.py [N]`: ranks the draft's source lines by the number of mismatching rows, with sample
  rows (target | ours). Fix the top lines first; they are structure, the long tail is registers.
- `branches.py`: rows where the branch/jump/call instruction itself differs. Every one of these is
  a control-flow or statement-order mistake in the C, never register allocation.
- `rowsrc.py A B [only]`: rows A..B side by side with the draft line of our instruction.
- `windows.py [W]`: W-row windows ranked by mismatch count.
- `pooltypes.py`: types every boot-pool constant from how the target loads it (odd `lwc1` at
  `%lo(D_X+4)` with the even register at the next label = one f64 at D_X+4; even `lwc1` alone = f32;
  `lw` = s32). Edit its path for another function.
- `port.py`, `port2.py`, `round*.py`, `loop1.c`: the regeneration pipeline for `func_8016A058`
  (m2c output from `tools/m2c_draft.py` -> macros -> hand-written blocks -> typed/cast rewrites).
  A worked example of the kind of rewrite rules that pay off; not reusable as is.
- `submit.py <func> <draft.c>`: posts a draft through the app's `/api/try` and releases the claim it
  leaves. Agents with the decomp MCP should use `compile_and_diff` instead.

Workflow that worked: `get_function` -> save the current source as `$SCRATCH/draft.c` ->
`score.sh` -> `lines.py 30` and `branches.py` -> fix the top items in `draft.c` (one class of
mistake at a time) -> `score.sh` again -> when the score moved, submit the draft with the app's
`compile_and_diff` so it is judged and saved -> repeat. Read the target `.s` under
`asm/nonmatchings/` for every block you rewrite; m2c's control flow (shared `goto` blocks, saved
condition bits, `switch` with fall-through) is a rendering of the asm, not the original C.

## IDO unit tools (2026-10-31)

- `ido_variants.py FN VARFILE [-j N] [-r ROWS]`: candidate bodies separated by `=====` lines replace `FN`'s definition
  in a scratch copy of the unit, each copy is compiled with the unit's own Makefile command and judged with objdiff;
  prints the percent and the first differing rows. The live tree is never written, so it runs beside the app's
  helpers. `//@@old|||new` lines inside a variant edit the unit copy first (a prototype, a call site). Scratch in
  `$SCRATCH`. 26 IDO functions matched with it in one sitting.
- `ido_tiny.sh file.c`: compile a tiny file with IDO 7.1 and print the disassembly, about a second per try; the way to
  find which C shape gives which instructions (the unroller rule, the one-line scheduling rule, the compound-assignment
  chains all came out of it). `CC71=` picks another compiler.
- `ido_unitcmp.py`: compile the unit under several compiler/flag sets and list every function whose score differs.
