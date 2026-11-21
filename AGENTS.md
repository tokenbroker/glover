# AGENTS.md — Glover (N64) matching decomp

You are working on a **matching decompilation** of *Glover* (Nintendo 64, USA, sha1 `270be17b3c8da9b88a7b99c2a545b0bce16837f4`) through decomp.wtf. The goal is C that compiles with the game's original compiler into **exactly** the same bytes as the ROM. Getting close doesn't count. A function is done only when objdiff reports a 100% match (score 0).

**Claim order, read this first. Claim by name, never by strategy.** `claim_function()` with no arguments and `claim_function(strategy="closest")` both serve the same handful of sinkholes to every agent; on 2026-10-15 that produced 580 claims and 3 matches in an hour. Work is tiered by what each model is good at, and a function moves down the tiers through its best attempt and release notes:
- **Claude Fable (the most capable model):** the "Large, undrafted" table of [docs/untouched-functions.md](docs/untouched-functions.md). Structure first; stop at 80% or 15 compiles and release with the handoff note described there. Do not polish: your compiles cost ten times a cheaper model's and the last 10% is register allocation, which the permuter does for free.
- **Codex, Claude Opus/Sonnet:** the near misses in [docs/permuter-queue.md](docs/permuter-queue.md), top table, and the "Medium, undrafted" table when that runs dry.
- **DeepSeek, Gemini, other API models:** the "Medium, undrafted" table.
- **The permuter** (built in, plus `tools/run_permuter.sh`) takes anything at 94%+ automatically; nobody claims the permuter-only table.
Claim with `claim_function(function="func_XXXXXXXX")`. Fifteen agents share these lists, so do not all start at line one: pick a line at random from the first 40, and if the tool answers "claimed by" or "already matched", pick another random line, never the next one down. When the named function is already matched, `claim_function` hands you a *different* function of its own choosing instead of an error: release that substitute at once with the note `substituted` and pick another line. Its substitutes are the tiny library-unit sinkholes, and working them is where whole sessions have gone. Once a claim succeeds, do not call `claim_function` again until you have released or matched that function. "Claimed by permuter" means the app's background permuter holds it for a minute or two: pick another line. Once you hold a function, work it: start from the best attempt and compile. `compile_and_diff` now says when to move on (no better after 4 compiles in a row, up to 10 for big functions); for a near miss at 90%+ keep going to about 25 compiles as long as the score still moves, then release with notes. The only functions you release without compiling are the two do-not-claim tables: hand-written assembly (note `handwritten asm`) and the permuter-only table (note `permuter queue`). When the near misses and the undrafted tables run dry, take the "Drafts below 90%" table of [docs/permuter-queue.md](docs/permuter-queue.md): structure first, handoff note at about 25 compiles. Both list files are regenerated every hour while agents are active, so a stale line is the hour's, not yours to report: pick another line instead of writing a note about it. A trick that worked, or a compiler quirk others will hit, goes in `add_note` with no function: every new session starts with those notes. Details under "Claim order" below.

**Current objective: link `src/D910.c` first.** It is the file closest to done (with `src/D910_F0D0.c`, which the hand-written block `asm/E860.s` now separates from it: 68 of 70 C functions matched), and one linked file is the proof of the whole pipeline. Its open functions sit at the top of both claim lists, which the hourly editor pass regenerates from the database: take a D910 line before anything else. As of 2026-10-28 that is two large drafts in progress (`func_80110598`, a near miss, and `func_80112F80`; Fable only, continue from the handoff notes); everything else in the file is matched.

## The toolchain (don't change it)

- Compiler: **KMC GCC 2.7.2**, from `tools/gcc_2.7.2/<os>/gcc`
- **Except `src/18020_C0800.c`: IDO 7.1** (`tools/ido-static-recomp/build/7.1/out/cc`, flags `-O2 -G0 -non_shared -Xcpluscomm -Wab,-r4300_mul -mips2`, loop unroller ON; since 2026-10-31: 7.1 matches everything 5.3 matched and also the prologues that truncate a byte parameter in place, and the ROM's unrolled loops are the unroller's work), see the layout table. `tools/fable/score.sh` and the permuter runner take each unit's compiler from the Makefile. Its `INCLUDE_ASM` stubs are spliced in by asm-processor (`tools/fable/ido_build.py`, the Makefile rule), so the unit links.
- Flags: `-O2 -g2 -G0 -mips3 -mgp32 -mfp32`. Also `-Wa,--no-float-doubleword` (the assembler's VR4300 mulmul fix is on since 2026-10-19)
- **-O0 functions:** the game unit is cut into pieces at every change of flags (`src/18020_<rom>.c`); the pieces the
  Makefile builds with `OPTFLAGS := -O0 -g2` hold every function the original compiled at -O0 (frame pointer in `$30`,
  arguments stored to their home slots, no scheduling). Such a function is already in its -O0 piece: write plain C and
  let -O0 produce the frame; never move a function between files, never force a frame pointer at -O2. `src/18020_376E8.c` (only `func_801366E8`, 3209 instructions) is such a piece since 2026-10-31: its callee-saved `$f20`-`$f26` are GCC's own temporaries across calls, not register allocation, and it matched at `-O0 -g2` with `sinf`/`cosf` (link aliases in `undefined_syms_auto.txt`, builtins GCC evaluates after the rest of the expression).
- Build: `make RUN_CC_CHECK=0`, driven by objdiff (`objdiff.json`). Targets: `expected/**.o`, base: `build/**.o`.
- Assembler: `tools/build/as` is decompals' mips-binutils-2.6 (KMC GNU as 2.6) rebuilt with `tools/no-float-doubleword.patch` and `tools/kmc-as-fixes.patch`. The second patch makes it behave like the assembler that built the ROM: `-g2` keeps hazard nops conditional, `mtc1`/`ctc1`/`mfc1`/`cfc1` are never padded (the VR4300 interlocks them, so `mfc1 $a0; jal` has no nop), an FP compare directly followed by a filled branch gets one nop and a compare with one instruction between it and the branch gets none, `lw $rd, sym($idx)` expands through `$at` (`lui $at; addu $at,$at,$idx; lw $rd,%lo(sym)($at)`), and a branch label defined before a hazard nop stays in front of it (`c.lt.s; .L: nop; bc1t`, so a `j`/`bc1t` target one instruction early is the C, not the tool). Since 2026-10-31 the libultra pieces (`src/18020_C5030.c` ... `src/18020_D30C0.c`) pass `-Wa,--lw-dest-temp` (`tools/kmc-as-lw-dest-temp.patch`): there `lw rd, sym(idx)` expands through `rd`, as the ROM's library objects do (`lui $v1; addu $v1,$v1,$v0; lw $v1,%lo(sym)($v1)`), while the game units keep KMC's `$at` form. A library target with that shape against our `$at` was the assembler, now fixed; write the plain `table[index]` C. If a diff shows only a scratch register or only a hazard nop, the assembler is stale, not the C; say so in the notes and release. Since 2026-11-06 `tools/kmc-as-libultra-nops.patch` adds the libultra assembler's two nop rules under `--fp-move-nops`: two nops between an FP compare and the filled branch after it (`c.le.d; nop; nop; bc1tl; slot`, 25 ROM sites) and a nop before a multiply that follows a label or the blank line GCC leaves after `.set reorder` (`.L: nop; mul.d`, 13 sites). 15 library functions matched from it alone and every game unit stayed byte-identical. Rebuild and verify the assembler with `tools/kmc-as-build.sh`: it applies the four patches, builds, runs `tools/fable/as_verify.py old new` (objdiff-cli judges every unit against `expected/`, game units must be identical) and refuses to install on any loss; it then runs `make -B`, because the objects do not depend on the assembler. When counting nops in a ROM object use `objdump -d -z`: without `-z` two nops fold into a `...` line. Since 2026-11-20 three more patches (`tools/kmc-as-hilo-libultra.patch`, `tools/kmc-as-pool-float.patch`, `tools/kmc-as-lid-pair.patch`): in the library pieces an `mfhi`/`mflo` directly before GCC's `.set noreorder` gets its two nops back (`mflo; nop; nop; j`, `func_801CC118` matched from it); in the game units (`--no-float-doubleword`) a float literal is pooled like the ROM's, `li.s` becomes `lui $at; lwc1 $fN,%lo(pool)($at)` with one unmerged `.rodata` entry per use (the ROM has 3751 such loads and no `lui`/`mtc1` float), and `li.d` becomes the `lwc1` pair, odd register first (1028 ROM sites, no `ldc1`). **Float and double literals in C now assemble to the ROM's shape**: `func_8016A058` (case 30, `/ 5.0`) and `func_8018BFA4` (`2.0f`, `5.0f` in place of `D_80109688`/`D_8010968C`) matched from that alone.

## Layout

| Path | What it is |
|---|---|
| `asm/1000.s` | entry/boot code, ROM `0x1000–0xD920`, VRAM `0x80100000–0x8010C920`; includes the entry data at ROM `0xD910–0xD920`. **Read-only** |
| `src/D910.c`, `src/D910_F0D0.c` | `main` segment (boot/PI/DMA helpers), ROM `0xD920–0x18020`, VRAM `0x8010C920–0x80117020`, cut on 2026-10-29 around the hand-written exception block `asm/E860.s` (VRAM `0x8010D860–0x8010E0D0`) |
| `src/18020.c` | `game_start`: first game CPU code range, ROM `0x18020–0x1D720`, VRAM `0x80117020–0x8011C720` |
| `assets/rspboot.bin` | RSP boot microcode, ROM `0x1D720–0x1D7F0`, stored at VRAM `0x8011C720–0x8011C7F0`; binary asset, not CPU functions. **Read-only** |
| `src/18020_1D7F0.c`, `src/18020_2D2B0.c` ... `src/18020_812E0.c` | `game`: ROM `0x1D7F0–0xBD710`, VRAM `0x8011C7F0–0x801BC710`, in 19 pieces cut at every change of compiler flags (2026-10-21, `tools/fable/split_unit.py`); the pieces listed with `OPTFLAGS := -O0 -g2` in the Makefile hold the game's -O0 functions and compile at -O0, the rest at -O2 |
| `assets/rspgfx.bin` | RSP graphics microcode, ROM `0xBD710–0xC0800`, stored at VRAM `0x801BC710–0x801BF800`; binary asset, not CPU functions. **Read-only** |
| `src/18020_C0800.c` | `game_end` head, ROM `0xC0800–0xC5030`, VRAM `0x801BF800–0x801C4030`: **built with SGI IDO 7.1 at `-O2 -mips2`**, not KMC GCC (IDO since 2026-10-28, 7.1 since 2026-10-31; `or` register moves, `ra` saved at frame-4, `$t6`–`$t9` temps). Every older note calling this window "unmatchable", "IDO sinkhole" or "assembler-blocked" is obsolete: its drafts just need IDO-style C. No GCC extensions in this file (no `inline`, `__attribute__`, statement expressions, `volatile` parameters); declare every function before its first use, one declaration per global; IDO's codegen habits differ from the GCC tricks below (no reorg delay-slot games; `-O2` keeps arguments in registers, `-O1` spills them). The 12 functions already at 90%+ there are the first to take |
| `src/18020_C5030.c`, `src/18020_C7520.c` ... `src/18020_D30C0.c` | `game_end` tail: libultra 2.0I from `sqrtf` on, ROM `0xC5030–0xD4AA0`, VRAM `0x801C4030–0x801D3AA0`; built without `-g`, with `ldc1`/`sdc1` doubles and `--fp-move-nops`; since 2026-10-29 in nine C pieces cut around the hand-written segments `asm/C72B0.s` ... `asm/D2D00.s` (`tools/fable/split_unit.py`, tag ASM) |
| `src/18020_D4AA0.c` | libgcc tail: `__divdi3`, `__udivdi3`, `__udivmoddi4`, `__umoddi3`, ROM `0xD4AA0–0xD51D0`, VRAM `0x801D3AA0–0x801D41D0`, built at `-O2 -g2` (all four matched 2026-10-29) |
| `asm/data/D51D0.data.s` | game data, ROM `0xD51D0–0xF5680`, VRAM `0x801D41D0–0x801F4680`. **Read-only** |
| `asm/data/F5680.bss.s` | game BSS, VRAM `0x801F5680–0x802B0D10`; zeroed at runtime, occupies no ROM bytes. **Read-only** |
| `assets/ipl3.bin`, `assets/F5680.bin` | IPL3 boot binary (ROM `0x40–0x1000`) and remaining ROM assets (ROM `0xF5680–0x800000`). **Read-only** |
| `include/common.h` | basic types (`s32`, `u8`, `f32`, …) |
| `include/structs.h` | shared structs. `ObjectNode` (0x110) is the main game object, kept in a circular doubly linked list with head `D_8026A148` (also `D_8028F350`) |
| `asm/nonmatchings/<file>/<func>.s` | target assembly for each unmatched function. **Read-only** |
| `symbol_addrs.txt`, `undefined_*_auto.txt` | symbol addresses. **Read-only** for agents; a missing symbol is added by the maintainer (see rule 9) |
| `Makefile`, `glover.ld`, `glover.yaml`, `objdiff.json` | build config. **Read-only** |
| `decomp.yaml` | leftover config from the upstream author's own tooling (paths on his machine, a different model). **Ignore it** |

## Rules

1. **Write C only.** Only edit `.c` files under `src/` and headers under `include/`. Never touch assembly, the linker script, the Makefile, splat config or symbol files.
2. **No inline assembly in new code.** decomp.wtf rejects `asm`/`__asm__` blocks, `register x asm("$n")` pinning and `.include` tricks. A match has to come from real C. Older upstream code in this repo uses a few of these hacks (for example `func_8011D810`, and parts of `D910.c`). Leave those alone, but don't copy them.
3. **Replace exactly one stub.** To decompile `func_X`, replace its `INCLUDE_ASM("asm/nonmatchings/<file>", func_X);` line in place, at the same position, so function order (and therefore addresses) stays the same. Don't reorder, merge or remove any other stub.
4. **Declarations go right above the function, at file scope.** This project has no per-module headers. Put the prototypes (`void func_801C6F90(s32);`) and externs (`extern u8 D_802AD560[];`) the function needs just above it in the same `.c` file, not inside the function body. First check whether the file already declares them (search for the name), since a duplicate declaration with a different type breaks the build. One symbol gets one type per file; if a different view is needed for codegen, cast the access (`*(f32 *)&D_X`) instead of redeclaring. No anonymous-struct externs (`extern struct { ... } D_X[];`): name the struct in `include/structs.h` or index a `u8` array. Implicit declarations are allowed in GCC 2.7.2, but an explicit prototype with the right return type often changes codegen, so add one.
5. **Shared structs go in `include/structs.h`.** If several functions touch the same layout, add or extend a struct there, with `/* 0xOFF */` offset comments and a size comment. Keep `unkXXX` names unless you know what a field does. A struct change is only kept if every function already matched still matches.
6. **Never break an existing match.** decomp.wtf undoes any edit that causes a regression. If your change makes something else fail, the problem is your change, not the other function.
7. **Protected:** never edit `include/common.h`, `include/include_asm.h`, `include/*.inc`, or any macro. Never add volatile to a global declaration or change the type of a global other functions use. If one access must reload, cast only that access. Use canonical structs in `include/structs.h` instead of local struct copies; inspect all consumers before changing a shared layout.
8. **Use names only for real knowledge.** Rename `func_`/`D_` symbols only when the behavior is clear. Renames are safe because matching works by address.
9. **Every symbol you reference must already exist.** objdiff does not check this: a draft that calls a function or reads a global that no file defines still compiles, still scores, and can even reach 100%, but the ROM stops linking. Before using a `func_`/`D_` name, confirm it appears in `symbol_addrs.txt`, `undefined_syms_auto.txt`, a `glabel`/`dlabel` in `asm/`, or a C definition. Never invent a name to make a diff line up, and never add a suffix (`D_X_s`) to dodge a type conflict. If the target genuinely needs a symbol that is missing (an address inside a labelled block, a literal between labels, a library name), write the address and the enclosing label into the release notes so the maintainer can add it; use the enclosing label plus an offset in the meantime.
10. **Handwritten assembly is out of the C units.** Since 2026-10-29 the 31 libultra exception, interrupt and CP0/FPU-control routines (`func_8010D860`–`func_8010E0D0`, `func_801C62B0`–`func_801C7EB0`, `func_801D1D00`, `func_801D2020`) live in assembled segments (`asm/E860.s`, `asm/C72B0.s`, `asm/C7620.s`, `asm/C7DE4.s`, `asm/C7F70.s`, `asm/C8320.s`, `asm/C8D80.s`, `asm/C8DF0.s`, `asm/D2D00.s`), verified byte for byte against the ROM, and are not claimable. Since 2026-11-20 the last four are out too: `sqrtf` (`func_801C4030`, `asm/C5030.s`), `__osEnqueueThread`/`__osPopThread` (`func_801C6D8C`, `func_801C6DD4`, `asm/C7D8C.s`) and `__osCleanupThread` (`func_801C6F60`, `asm/C7F60.s`); `src/18020_C7D8C.c` and `src/18020_C7F60.c` no longer exist and `src/18020_C5030.c` starts at `func_801C4040`. If a target you hold still shows `/* handwritten instruction */`, `mtc0`/`mfc0`, `cfc1`/`ctc1` outside the IDO unit, `cache` or `eret`, release it with the note `handwritten asm` and say which. The old `func_80165338` is `func_80165340` since 2026-11-20 (matched): its two odd leading words were ASCII padding (`D_80165338_padding`) in front of an ordinary compiled function.
11. **Don't park functions.** Never replace a body with an empty `{}` or a call to a placeholder to "hold" a claim; release it with notes instead. Other agents' unmatched drafts may be sitting uncommitted in the same file: leave hunks you did not write alone.

## Matching with KMC GCC 2.7.2 (MIPS, -O2)

- **Attribute the diff to source lines before guessing.** `tools/fable/README.md`: `score.sh` compiles a draft
  locally with the judge's objdiff settings, `lines.py` ranks the draft's lines by mismatching rows and
  `branches.py` lists the rows where a branch itself differs (always a C mistake). Fixing the top lines first took
  `func_8016A058` from 71% to 89% in a day; the long tail is register allocation and not worth compiles.
- **Fix structure first, registers last.** Get the control flow, call order and stack size right before chasing register allocation.
- **Check the delay slot.** The instruction after a `jal`/branch runs before the jump. A store in a `jal` delay slot is a C statement that comes just before the call, not after it.
- **Types drive the instructions.** `lb`/`lbu`, `lh`/`lhu` and `sll`+`sra` sign extension tell you whether a value is `s8`/`u8`/`s16`/`u16`. Return types also matter: a missing prototype makes the compiler assume `int`.
- **Array indexing vs. pointer math.** `base + idx*8` written as `((u8*)&D_X)[idx*8]`, `&arr[idx]` or a struct array produces different code. Try more than one form.
- **Declaration order and temps affect register allocation.** Reorder locals, add or remove a temp variable, or combine/split expressions. GCC 2.7.2 reacts strongly to these.
- **Loops.** `do { } while` with a guard `if` in front usually matches better than `for`/`while` when the asm tests once before the loop and again at the bottom.
- **Branch shape.** `if/else` vs. early `return` vs. ternary each produce different branch layouts. `beql`/`bnel` (branch-likely) are normal at -O2.
- **Floats.** `-mfp32`, with no doubleword float ops. Use `f32` literals with the `f` suffix (`1.0f`). A float passed through `$a` registers via `lw` usually means the source passed it as an `s32` bit pattern (see the `posX`/`scaleX` notes in `structs.h`).
- **Look for similar code.** `find_similar` often finds a matched function with the same shape. Start from its C.
- **Use the m2c draft as a starting point**, then fix it based on the instruction diff.

## Function boundaries

Function boundaries were repaired and verified; see [glover-boundary-audit.md](glover-boundary-audit.md). If a target still has no prologue or no `jr $ra`, release the claim with a note instead of compiling it.

## Build status and what objdiff does not check

The last revision verified byte-identical to the ROM is tag `good-20261014-1555`. Since then unmatched drafts live in the tree, so a full build links but does not reproduce the ROM; it will again only once every function and all data match. The link itself is a separate property from objdiff scores: decomp.wtf reverts on compile errors and on match regressions, not on undefined symbols, so an invented name survives until someone runs `make RUN_CC_CHECK=0` and reads the linker errors. On 2026-10-14 the tree stopped linking for a day this way (a phantom `func_8013EBEC`, 56 double literals named at `+4` inside the boot pool, `sqrtf`, `__divdi3`). The symbols that were legitimately missing are now defined; the rest were fixed in C. On 2026-10-28 the full build linked again with zero undefined references: the libgcc 64-bit helpers (`__divdi3`, `__udivdi3`, `__udivmoddi4`, `__umoddi3`) and two pool addresses got link aliases in `undefined_syms_auto.txt`, and `tools/fable/addr_audit.py` (run after `make RUN_CC_CHECK=0`) lists every matched function whose relocations resolve to a different address than the target's; it found six matched functions reading the neighbouring pool constant, all fixed the same day. A clean verification build (`make clean && make RUN_CC_CHECK=0 && sha1sum build/glover.z64`) must at minimum link with zero undefined references, and at a fully matched revision must print SHA-1 `270be17b3c8da9b88a7b99c2a545b0bce16837f4`.

## When the environment is broken

If `compile_and_diff` fails **before your code is compiled**, the build environment itself is broken. Examples: `make` not installed, compiler path missing, `mips-linux-gnu-as` not found, `/bin/bash` missing. Don't keep trying different code, and don't edit build files to work around it. Write your analysis of the function into its notes, release the claim, and report the exact error. This project builds only on Linux (or WSL) or macOS. There's no Windows compiler under `tools/gcc_2.7.2/`.

## Contributing upstream

Every match is a git commit on the local `decomp-wtf` branch. Nothing is sent upstream automatically. A person reviews the work before anything goes upstream.

## Known tricks (KMC GCC 2.7.2, collected from matched functions)

- **A branch that lands a few rows from ours is a statement in the wrong block**, even when earlier notes call the diff register-only: a call or store sitting on the wrong side of an `if`, a shared test placed before the if/else instead of after, a retry `do { } while` written as a straight line. Nine near misses matched that way in one hour (`func_8011D88C`, `func_801B7C0C`, `func_8014AC1C`, `func_801AC398`, `func_801AB140`, `func_801AB58C`, `func_8017A6B8` ...). Permuter leftovers that look like no-ops (an uninitialised `return new_var;`, a stray `volatile`, an `if (cnt)` on an uninitialised local) often hide such a slip; but some are load-bearing (they stop GCC folding an address or keep a reference count), so re-score after removing each one.
- **A constant hoisted above a float test** (`bnez flag, EXIT` with `li $v0, K` in its slot, then `bc1tl EXIT` with `move $v0, $zero` annulled, then `lw $v1, D` and `bne $v1, $v0`): the constant was moved out of a loop as an invariant. Write the float test and the compare inside `do { ... } while (0);` (or `for (;;) { ...; break; }`) and keep the literal `K` in the compare (`func_8016536C` case 27; `func_8016A058` has the same shape four times).
- **Return directly, don't use a result variable.** Several `if (...) return x;` statements
  ending in `return v;` keep the value in `$v0`. A `ret` temp often lands in `$a0`/`$a1` and
  costs an extra `move`.
- **Declare loop pointers inside the loop.** `for (i...) { Entry *p = &arr[i]; ... }` with `i`
  as the only outer local. A pointer declared outside and incremented makes GCC create a
  second induction variable (extra saved register, extra instructions).
- **Grouped loads then stores need temps.** If the target does several `lw`/`lhu` and then
  several `sw`/`sh`, read every field into its own temporary first, then store. Direct
  `a->x = b->x;` lines interleave load/store and change register allocation.
- **Duplicate cleanup instead of `goto`.** Write error-path cleanup inline in each path
  rather than jumping to a shared `bad:` label; the shared label changes block layout.
- **Loop shape matters.** `while` and `do {} while` produce different block layouts; try
  both. For branch-likely pairs (`beql`/`bnel`) in loops, put the increments in the `for`
  clause as a comma expression (`n--, a++, b++`) and use `continue` for the skip.
- **Keep expressions inline when the target recomputes them.** Pulling `arg + 2` into a
  variable can get hoisted above a branch and add instructions.
- **Initialise locals straight from arguments.** `u32 lo = arg & 0xFFFF;`, not
  `u32 x = arg; ... x & 0xFFFF`, which adds a `move`.
- **Target loads the same field twice?** GCC merges repeated loads. Make only that one
  access volatile with a cast: `*(volatile s32 *)&p->field`. Never change the global's
  or struct's declaration (that breaks other functions). When the volatile cast gets the
  reload but shifts a register, take the address into a local pointer instead and
  dereference it at the use (`u8 **pp = &D_80269F44; ... f(*pp, ...)`), as in the
  permuter's match for `func_80118D54`.
- **Volatile parameter.** Small 0x801BFxxx functions that return `arg1` via `or v0,a1,zero`
  match with the parameter itself volatile: `volatile s32 arg0`, or `u8 *volatile arg0`.
- **Recognise library code.** If a function looks like standard code (libultra `os*`/`gu*`,
  libc `memcpy`/`strlen`, a known compression routine), write the upstream library source
  verbatim with the right struct layout. These often match on the first compile.
  `docs/library-candidates.md` names 132 of them with the upstream file to copy from.
- **Square root.** A target `sqrt.s` followed by `c.eq.s`, `bc1t`, `jal func_801C4030` is
  one `sqrtf(x)` call (declare `f32 sqrtf(f32);`; `__builtin_sqrtf` emits the same code).
  GCC always adds that NaN fallback; `func_801C4030` is the ROM's `sqrtf` and the linker
  symbol `sqrtf` resolves to it. Don't try to write the fallback branch yourself.
- **64-bit division.** `s64 / s64` emits `jal __divdi3`, `u64 / u64` emits `__udivdi3` and `u64 % u64`
  emits `__umoddi3`; the ROM has them as `func_801D3AA0`, `func_801D3B40` and `func_801D41A0`
  (`func_801D3B60` is `__udivmoddi4`), and since 2026-10-28 all four libgcc names resolve to those addresses
  through `undefined_syms_auto.txt`, so plain C division links. Calling `func_801D3AA0(num, den)` explicitly
  with an `s64 (s64, s64)` prototype works too; the remainder is then `num - den * quot` with inline `mult`/`multu`.
- **Relocation names are not scored; addresses are what matter.** The judge diffs with the
  progress report's settings (`functionRelocDiffs=none`): the relocated fields are masked, so
  `%lo(D_8010BA70+0x8)` against a target `D_8010BA78` is not a diff, `sqrtf` against
  `func_801C4030` is not a diff, and a draft can read 100% while it names a *different*
  address than the target (a wrong pool constant, the neighbouring double). objdiff's
  interactive view shows those rows as mismatches, which is why earlier notes called this
  "relocation spelling"; it never cost a match. What does matter: every symbol must exist
  (rule 9), and the address must be the target's. The editor pass audits resolved addresses
  and flags `wrongaddr` in its per-function notes and in the near-miss table.
- **A fresh `lui`/`addiu` pair for an address inside a known block** (for example the
  thread stack `D_802AEB40` inside `D_802AE990`) means the original used a distinct global.
  Writing `&D_802AE990[0x1B0]` makes GCC reuse the block's base register and changes the
  allocation; use the distinct symbol and ask for it if it is missing (rule 9).

- **Narrow only at the observed operation.** Halfword arguments and explicit `(s16)` / `(u16)` conversions affect sign extension and range tests. Preserve the width of stored fields and the exact point of conversion (for example the signed halfword comparison in `func_80173CE8`).
- **Preserve call setup shape.** Keep separate calls in separate branches when the target repeats their setup; combining them into one call changes scheduling and live ranges. Keep temporaries near their use, as in the matched field-copy and display-list routines.
- **Preserve padding ownership.** Objdiff can match a padding symbol while a missing following word still shifts later functions. Function scores alone do not prove linked addresses or ROM identity; always verify the full ROM after cleanup or layout changes.

## Lessons from agents (auto-curated)

Project-wide notes from agents, promoted by the hourly editor pass (`tools/editor_pass.py`). Same format
as the tricks above; the source function is in parentheses.

- **Float constants live in the boot pool; a literal is allowed since 2026-11-20.** The assembler now pools `li.s`/`li.d` as the ROM's did
  (see "The toolchain"), so `2.0f` and `extern const f32 D_8010xxxx;` (or `f64`) give the same instructions but different register
  allocation and scheduling (GCC treats a constant and a memory load differently): when the extern form leaves FP registers rotated or a
  load on the wrong side of a branch, read the value from the pool (`read_data`, or the `.word` at its `dlabel` in `asm/1000.s`) and
  write the literal. Matched functions keep their extern form. A pooled `0x4f000000` before `lui $sN,0x8000` is the 2^31 limit of a
  `(u32)`-from-float conversion (`func_80144F0C`); an odd `lwc1 $f1,%lo(D_X+4)` with `$f0` from the next label is
  one `f64` at `D_X+4`, `*(f64 *)((u8 *)&D_X + 4)` (`func_8016A058`).
- **Write the float-from-`u32` conversion by hand.** Each site loads its own 2^32 pool double as an `lwc1` pair
  from a 4-aligned label, where GCC's fixup dedups them into one `ldc1`: write `(f32)((s32)n < 0 ? (f64)(s32)n +
  *(const f64 *)((const u8 *)&D_X + 4) : (f64)(s32)n)` with `extern const f32 D_X;` (`func_80157708`).
- **Write the `u32`-from-float conversion by hand.** `if (!(a >= lim)) { r = (s32)a; } else
  { r = (s32)(a - lim) | 0x80000000; }` with `u32 r` gives `c.le.s lim,a; bc1t`; `if (a >= lim)` flips to
  `bc1f`, `u16 r` drops the `or`, a `(u8)` on a `?:` folds the `or` away (`func_801B70F8`, `func_801BB5C4`).
- **The `f64` version is a labelled pool double.** For `lwc1 D_X; lwc1 D_X+0x4`, write the same with
  `*(const f64 *)&D_X`, `r |= 0x80000000;` as its own statement, no local, on one source line (`func_801AE348`).
- **Declare rodata floats `extern const`.** Non-const, the load aliases every store and sinks, giving an
  extra nop before `bc1f` (`func_8019B658`). `const` lets it pass `sb` stores and leave a loop with calls
  (`func_80184FC0`); past a non-const file-scope declaration read `*(const f64 *)&D_X` (`func_80179810`).
  A literal kept *after* a store is non-const (`func_801AE510`).
- **Preheader order follows source order.** Hoisted invariants appear in the order loop.c meets them: a
  constant loaded after `addiu $s2,$zero,12` is read in the body (`func_801B4BBC`); a limit loaded first was
  tested in the loop condition (`func_801A8528`). Write induction values as products in the body,
  `rowStart = y * bh;`, not `off += 6`: a hand-kept giv initialises too early and swaps saved registers (`func_8014A760`).
- **Statement order decides load order outside loops.** Write `off = idx * 80;` before `g = D_X;`
  (`func_80191794`) and `h = p->f; lim = D_X; if (h < lim)` for a field loaded before a global (`func_8019993C`).
  A load that comes too early is deferred by taking its address, `u8 **p = &base[idx]; ... *p` (`func_80198A58`).
- **Re-materialised global addresses.** A fresh `lui`/`addiu` per 12-byte copy means a pointer argument
  after `if (arg0 == &D_X)`: write `*(Words3 *)(arg0 + 0x34)`; a flag read and written through a register
  base gets its own block `{ s32 *p = &D_X; *p |= K; }` per site (`func_8015F098`, `func_80171924`). Across
  calls, load the symbol into a local, pass it, then set `v = NULL;` for a fresh pair (`func_801326F0`).
- **In-struct versus scalar access decides store ordering.** A dereference counts as "in-struct" only when its
  operand is literally a pointer addition or its type is an aggregate: `((T *)p)[k]`, `(&X)[n]` and `*(f32 *)((u8 *)obj + k)`
  are in-struct, while `*(f32 *)(obj + k)` through an integer is scalar. The scheduler and loop optimiser assume a
  non-char in-struct store at a varying address never aliases a scalar fixed-address access, so in-struct lets a
  following global load hoist above the store and scalar keeps the order; char-sized accesses are exempt
  (`func_80110598`, `func_8019787C`, `func_80129AFC`, `func_8012643C`). A global that is a field of a known object,
  reloaded after a store through another pointer, is in-struct: `((u8 **)&D_802902D8)[54]` (`func_80171924`).
- **Output-pointer stores are in-struct too.** A global load kept after `arg[1] = x`, or an `arg[1]` load kept
  after a scalar global store, wants a non-PLUS address, `p = &arg[1]; *p = x;` or `*p` (`func_801B1B4C`,
  `func_801B10B8`); an inlined `(*count)--` drifting past field stores wants casts,
  `*(s32 *)(*(s32 *)n + 4) = ...` (`func_8018B358`).
- **Box one access in a struct to pin or reload it.** `((T *)p)->f74` with `typedef struct { u8 pad[0x74];
  f32 f74; } T;` keeps `sw $zero,%lo(D_X)` below the load (`func_801B1E70`); `((U8Box *)&D_801ED403)->v` keeps
  a flag after struct stores (`func_80189C9C`); `((F32Box *)&D_X)->v` forces a reload (`func_80125294`).
- **Loop invariants in big loops.** An `extern const` the target loads inside the body is read through a
  non-const pointer there, `ofs = *(f64 *)&D_801005A0;`; a `%lo(D_X+4)` body load wants `extern const f32 D_X[];`
  and `*(const f64 *)&D_X[1]` (`func_8016536C`). A `+4`-per-iteration array base needs `p = arr;` before the
  loop and `p[i]` inside (`func_80112F80`).
- **Indexed global loads in a loop.** For `lui $at; addu $at,$at,idx; lw %lo(sym)($at)`, put the byte index in
  a local and index `sym[idx]`, recomputing `idx = x * 20;` before each use (`func_8011FF40`). Scalar globals at a
  fixed stride are one `extern struct X D_base[];` written `D_base[i].f`; `((struct X *)&D_base)[i]` puts the base
  in a register (`func_80120D18`).
- **Split or merge multi-block temporaries.** A local assigned in several blocks is one pseudo and lands
  elsewhere than block-local temps: declare `{ s16 *sel = &G; s32 n = *sel; }` inside each `if`
  (`func_8012860C`) and write `s2 - 7` inline (`func_80120A90`). The reverse: reuse one `f32` local across
  blocks, `t = dot; ... t = p->f;`, to swap `$fv1`/`$ft0` (`func_8014ED9C`).
- **Block-scope externs shadow yours.** A symbol declared `extern` inside another function drops your
  file-scope declaration and the build fails showing only warnings. Declare it inside your function
  (`func_80186420`) or cast at the access (`func_8018B3FC`); a block-scope `extern T *volatile D_x;` leaks
  into the whole file (`func_801735E8`).
- **Hazard nops come from line notes.** A nop after `c.lt.s`/`c.eq.s`/`mfhi`/`mflo` that the target lacks is a line
  change between the compare and its consequence: put `if (x < K) { return 1; }`, or the header, locals and first
  `if (`, or a whole `if (x) { A; } else { B; }` on one line, join the last statement with its closing braces, keep a
  `%` inside the condition, put a `#define` inside the body (`func_8015F910`, `func_8014B8F8`, `func_80198310`, `func_80148000`).
- **A delay-slot nop usually means a wrong block boundary.** When the target fills a `beqz`/`bc1f` slot and
  yours has a nop, the branch target skips a statement that belongs inside the `if` (`func_801A21B8`). A
  `j func+0x150` ends an `else if` chain; a `beql`-skipped `sw $zero` before a call means the call is
  unconditional (`func_8017A38C`).
- **objdiff does not flag a wrong branch target.** A stubborn last-branch diff can be a logic error, a test
  returning 0 for 1 (`func_80128D34`) or an inverted `continue` test (`func_80158DC4`). A stray `$a3` before a
  printf-style call is a missing variadic argument (`func_80186420`).
- **Keep a known symbol out of a pointer offset.** With `s1 = (u8 *)&sym;` in the same extended block,
  `*(f32 *)(s1 - 0x94) = v;` folds to `swc1 %lo(sym-0x94)($at)`: write `*(p = (f32 *)(s1 - 0x94)) = v;` with
  `p` assigned twice across a branch (`func_80174D4C`); for reads `q = base - 0xA0; *(f32 *)q` (`func_8012BD44`).
- **Flush CSE's memory with a block-local pointer.** When the target reloads a global after a small conditional
  store, write `if (c) { f32 *z = &D_8029035C; *z = k; }`: the raw store invalidates the cache and still folds to
  `swc1 %lo(D_...)($at)` (`func_801735E8`). The reverse: a pointer local around `if (s0 == G) G = 0;` forces an
  address register and `beql`; the plain form gives `lw %lo; bne; sw $zero,%lo` (`func_801B6B3C`).
- **A `u8` store through the same pointer forces a later reload.** When the target reloads a field you wrote
  and yours reuses the register, move `p->f &= ~X;` ahead of a nearby `sb` through `p`: the char store kills
  CSE's equivalence and the scheduler still sinks the `sw` below it (`func_801A29F0`).
- **Volatile on both sides keeps a load after an unrelated store.** A cast `*(volatile s32 *)&D_x` CSEs
  the address; block-scope `extern volatile s32 D_x;` keeps `%lo` only for symbols with no file-scope
  declaration (`func_801AB58C`). If arguments then swap, volatile only the guard and the store (`func_801A8528`).
- **Swapped `$s` registers follow reference counts.** Allocation ranks by `log2(refs)*refs/length`: add or drop
  one reference (`done = 1;` in both arms, `== done` for `== 1`) to flip two; `f64 d = x; x = d;` raises a float
  for free (`func_801230A8`); `do { ... } while (0);` around the uses weights them by loop depth (`func_8014E9F4`);
  a pseudo set once to a constant loses its register to a hoisted constant: set `hb = K` in both arms (`func_80110598`).
- **Inline a single-use load into its test.** `if ((*(s32 *)&arr[i] >> (shift + 4)) & 1)` with `shift`
  computed first, not `bits = arr[i];` when the local is reused later; an index local `idx = D_X * 28`
  hoists the multiply, inline it for `sym(reg)` addressing (`func_80128D34`).
- **Operand order of a loop `addu`.** `addu $v0,base,giv` comes from a per-iteration temp `u8 *q = base + j * 0x78;
  q[0x74] = v;` (`func_80188A5C`); for `addu $v0,$s3,$v0` index the global directly, `D_X[*sel + 3]`.
  `(s0 << 5) + func() + 8` folds the `+ 8` into the shift; write `r = func(); ... (s0 << 5) + (r += 8)` (`func_801230A8`).
- **Ternaries load into `$v0`; `if`/`else` arms fill the slot.** `p->f = A ? 4 : B ? 1 : 2;` with a constant in each
  slot is `if (A) p->f = 4; else if (B) p->f = 1; ...` (`func_801B4078`); `beqz; addu $a0,$s0,$zero` then
  `lui $a0; lw $a0; addiu $a0,$a0,K` is `f32 *tp = a->pos; if (c) { tp = (f32 *)G; tp = (f32 *)((u8 *)tp + K); } f(tp);` (`func_801A0444`).
- **Frame size follows the locals.** A clamped `s16` local, or one passed to a call, can add an 8-byte slot the
  target lacks; make it `s32` and cast at the compare (`func_801A87CC`). For gaps beside address-taken slots declare the pointer as
  an array, `T *n[2]`, and use `n[0]`: aggregates get their slot at declaration, scalars when their address is
  first taken (`func_8011CD50`).
- **Neighbouring globals are one table.** When `$sM` is derived as `addiu $sM,$sN,-0x70`, several globals load off
  one `lui`, or a scalar's `lhu` hoists above struct-field stores, write every access as an offset of one symbol
  even where the asm names another: `*(f32 *)((u8 *)&D_BASE + off)` or `(&D_801E7530)[1]` (`func_80176758`, `func_8018978C`).
- **`bgez`/`addu`/`negu` is `abs()`.** It is GCC's `abssi2`; write `abs(a - b)`, since the ternary gets the
  operand order wrong (`func_80144AF8`).
- **Every saved register shifted by one.** The target has one pseudo fewer: reuse the first loop's `i` for a
  second loop (`func_801570AC`), or drop `u8 *o = (u8 *)arg0;` and cast at every access (`func_801A6844`).
- **Assembler-blocked nops.** As of 2026-11-06 no known nop is the assembler's (the libultra two-nop compare and the padded
  multiply after a label were, until `tools/kmc-as-libultra-nops.patch`): a nop the target lacks is a line note
  (join the statements) or a hazard GCC really scheduled. Since 2026-10-29 the assembler also pads a multiply that follows
  `mul.s`/`mul.d` through a branch and its slot nop (`mul.s; j; nop; nop; mul.s`, `func_80157708` matched from that alone). Since 2026-10-20 the assembler keeps float multiplies out of
  delay slots itself, pads an FP compare only before an instruction that reads the condition code (`func_80160920`),
  (`func_801B1B4C`, `func_801B48DC`, `func_801B70F8` matched from that alone). Since
  2026-10-19 the assembler pads `mul.s`/`mul.d` followed by `mul*` itself (`func_80160728` matched) and no longer pads
  `mfhi`/`mflo` before a `.set noreorder` branch (`func_8017B780`, `func_8018DFAC`, `func_8018E260`, `func_80129AFC`
  matched from that alone), so a nop after `mfhi`/`mflo` before a filled branch is a line note again, not the assembler.
- **Cast a call whose setup disagrees with the prototype.** A `sw $v0` after a call the file declares `void` is
  `p->w1 = ((u32 (*)(u8 *))func_801CD578)(s2);` (`func_8014B110`); a two-argument function called with only `$a0`
  set is `((s32 (*)(s32))func)(x)` (`func_8016536C`); block-scope prototypes that disagree across the unit stop the
  definition compiling, so cast the odd caller (`func_80157708`).
- **Signs of an inlined helper.** A mystery 8 bytes plus `sw $sN,XX($sp)` in a `beqz` slot, a fresh `addiu $t0,$s2,0xe4`
  instead of a folded offset, or a raw `addu $a0,$s3,$zero` index copy: add a `static inline` copy of the callee,
  dead branches included, with `s16` parameters (`func_8018B358`, `func_80198A58`), or paste the matched body as a
  statement expression, `x = ({ f32 w; if (..) w = ..; else w = ..; w; });` (`func_8014A040`).
- **A flag materialised before `beqzl` is an inlined predicate.** `bne; addu $v0,$zero,$zero; addiu $v0,$zero,1;
  beqzl $v0` comes from a `static inline s32` helper written `goto fail; return 1; fail: return 0;` and called as
  `if (helper(..))` (`func_80179524`).
- **Sparse `switch` trees.** For a compare tree rooted in the middle (`== 6`, `slti 7`, `== 5`, `== 8`), write
  separate `case 6:` and `case 5:` bodies even when identical; `case 5: case 6:` becomes a range check (`func_80198A58`).
- **Condition polarity decides delay-slot fills and argument order.** `for (p = head; p != head; p = next)
  { next = *p; if (!x) continue; ... }` let reorg fill the `beqz` slot; the inverted `if (a != 0 || b == K)
  { B } else { A }` fixed swapped `$a0`/`$a1` (`func_8018BFA4`). In each arm, assign in the order the slot
  and fall-through set them (`func_80148654`).
- **Cross-jumped tails.** An arm ending in a `j` into the other arm's `div` divides too: give each arm its own
  `/ den` (`func_8014B8F8`). For a `switch` sharing a `bc1f; li $v0,0; j end; li $v0,1` tail write `if (c) return 1;
  break;`, not `return c;` (`func_80198310`). A final call that appears twice is two calls in `if`/`else` arms
  (`func_80112F80`). End an `if (arg0 == K) { ..; return 1; }` chain with one more case and `return 0;`, not
  `if (arg0 != K) return 0;`, which lets cross-jumping merge two tails (`func_80186420`).
- **Operand load order of `K - x`.** When `x` loads before the pool constant, the original used a float
  literal: a `REAL_CST` loads after the other operand, an extern label first (`func_8012C5E0`).
- **`do {} while (0)` is a scheduling barrier.** To keep `lw $v1,0x38($s1)` after `sw $zero,0xf4($s1)`, wrap
  the preceding statements: `do { vel = D_801ED3C4; o->speed = 0.0f; } while (0);` (`func_8017A6B8`).
- **Inlined display-list macros share one loaded pointer.** Write `Gfx *g = D_80202240; D_80202240 = g + 1;
  g->w0 = ...; D_80202240 = g + 2; g[1].w0 = ...;` without reloading `g` (`func_801A6FD0`); when later arms get
  other registers, declare a fresh block-local `u32 *list` in each `if`/`else` arm to shorten the pseudo's
  lifetime (`func_8014BB90`).
- **Direct `%lo` access needs a scalar declaration.** A plain scalar global reads `lui; lw %lo(D)`; `D[0]++`,
  `*(s32 *)&D` and struct fields go through a shared address register. Never flip a shared declaration; write
  `*(s32 *)&D_X = *(s32 *)&D_X - 1;` or `s32 *count = (s32 *)&SYM;` (`func_8014ED9C`). Both forms for one
  symbol mean a struct member in the original: cast every access, `*(f32 *)&sym` (`func_8016A058`).
- **`mul.s` operand order follows the assignment target.** `x = t * x;` gives `mul.s x,x,t`; `x = ({ t * x; });`
  keeps `mul.s x,t,x`. For `mul.s c,K` into K's register, `v = K; v = ({ (f32)c * v; });`; for
  `mul.s $fs0,$fv0,$fs0`, `fs0 = t * (fs0 = D_801083A8);` (`func_8017541C`).
- **Where a halfword's `sll`/`sra` lands.** `s32 y = (s16)(expr);` extends where computed, before a later branch;
  an `s16 y` local defers it to the call (`func_801BC240`); an index extended after another one gets that index
  as its own statement first, `row = *(s8 *)(...) * 0x300;` (`func_801ADDC4`).
- **Preheader copies after the `blez`.** For a `mov.s $fsN,$fv0` right after the loop's initial `blez`,
  write `i = 0; if (i < n) { base = G; do { ...; i++; } while (i < n); }`; a `for` puts the copy before
  the guard. A loop-invariant `f64` assigned in that `if` block gets the target's register (`func_8014E8B4`).
- **Integer address arithmetic defeats the `%lo` fold.** For `lui`/`addiu $aN,%lo(SYM)` then `addu $aN,idx,$aN;
  lw 0($aN)` where the inline expression gives `lui $at; addu $at,idx; lw %lo(SYM)($at)`, take the element
  address into a local pointer, `f32 *pf = (f32 *)((u8 *)&SYM + idx); ... *pf` or `data = &SYM; ...
  data = (u16 *)(idx + (s32)data); return *data;` (`func_801473F8`, `func_8010F520`).
- **Giv order and shared index registers.** Assign a pointer giv after the first call, `node = o + i * 0x38;`,
  when two increments come out swapped; for tables indexed alike compute `k = j + o[0x161] * 0xC0;` per use
  (`func_801A96A8`). To keep an outer-loop stride unreduced, define the giv after its uses:
  `for (i = 0; ; off = i * 16) { ...; if (++i >= 10) break; }` (`func_8017DC10`).
- **Volatile only the last store to keep it out of a call's delay slot.** `((volatile Obj *)p)->field = w;`
  or `((volatile S8Box *)&D_x)->v |= 1;` before a `jal`; volatile on earlier stores made it worse
  (`func_801B7C0C`, `func_80125294`).
- **Scheduling diffs that are structure.** A `bnez` into a call's argument setup means the call follows the
  `if`, `if (x == 0) { a = ..; b = ..; } call();`; a `bne` chain falling through to the epilogue, or tail
  stores that look reordered, put the trailing statements inside the `if` (`func_8019DCE4`, `func_80112830`).
- **Load a store's base before the call on its right.** `p->f = ({ call(..) * K + ofs; });` makes GCC evaluate
  the left-hand pointer before the call, as the target does; the plain assignment loads it after (`func_80112F80`).
- **Branches versus `xori`/`sltiu` for `||` and `&&`.** `x == A || x == B` and `a && x == K` fold to
  `xori`/`sltiu`/`or` and one store only when the operands are plain locals (`func_8011FF40`); if the target
  keeps the branches, re-read memory in the right-hand test, `(s16)D_802903AC == 0x29`, not a cached local.
  `x == K || x == K + 1` is `(u16)(x - K) < 2U` (`func_80171924`).
- **Fold-proof arithmetic.** When GCC turns `a - (b - c)` into `(a + c) - b`, or pushes an `(f32)` cast into a
  `?:` clamp, compute the pieces in separate integer temps, `d = b - c; r = a - d;` (`func_801A29F0`).
- **Three float compares are a clamp with an `||`.** `c.lt.s t,lo; bc1t`, `c.lt.s t,hi; bc1fl`, `c.lt.s t,lo; bc1fl`,
  with the first branch landing between the third compare and its branch, is
  `(t < lo || t < hi) ? (t < lo ? lo : t) : hi`; nested `MIN(MAX())` and two `if`s do not reproduce it
  (`func_8019C52C`, `func_80120D18`, `func_801AEE04`).
- **A narrow stack argument against an `s32` prototype.** For `lhu 0x42($sp)` on a fifth argument that block-scope
  prototypes elsewhere declare `s32`, define it K&R style, `void f(a, b) u8 *a; u16 b; {`: the promoted type agrees
  with the prototype and GCC reads the halfword from the stack (`func_801B9974`).
- **Sign-branched `abs` tests.** A `c.eq.s` repeated in both arms of a sign test is `if (x > 0.0f ? max == x : max == -x)`;
  `sltiu`/`multu` by `0xaaaaaaab` on a `do {} while (i < 3)` counter means `u32 i` (`func_8015BE58`).
- **Library-style argument copies.** A prologue copying `$a1`, `$a2` first and `$a0` last is libultra's `void *filter;
  T *f = (T *)filter;`; `{ Acmd *c = ptr++; c->w0 = ..; c->w1 = ..; }` per command puts `ptr++` in the `jalr` slot (`func_801C8B24`).
- **IDO fingerprints in the library unit (`src/18020_C5030.c`).** `or $v0,$a1,$zero` moves, `$t6`–`$t9` scratch, nops after `mtc1`/`mfc1`,
  `addiu $sp` in the `jr` slot, a filled `jal` slot, `$a0` copied to `$a3`, arguments spilled to their home slots
  (`sw $a1,0x1c($sp)`) with no `$s` registers: IDO built it. But `addiu $sp` in the `jr` slot and a filled `jal` slot
  alone are not IDO: since 2026-10-19 the unit is built without `-g`, and GAS fills those slots itself. A register scan on 2026-10-28 found no IDO-built function in the library unit (`$t6`–`$t9` without `$t0`–`$t5` only in
  the hand-written `func_801C6D8C`); `func_801BFF60` and `func_801C19FC` are in the IDO unit `src/18020_C0800.c`.
  Port library functions from ultralib as plain C.
- **The library hazard nops were the assembler, fixed 2026-11-06.** The 15 library functions that differed from the ROM
  by a single `nop` (`c.lt.d; nop; nop; bc1f`; `.L: nop; mul.d`) matched from `tools/kmc-as-libultra-nops.patch` alone
  (see "The toolchain"); a nop diff in those units is the C again. Left in the library pieces as of 2026-11-20: only `func_801CC118`
  (98.8%, every instruction and register matches; 14 `mflo; nop; nop` hazard nops are the assembler's, being patched). `func_801C7110` matched once its
  `D_80000004/08/0C` relocation annotations became literals in the target, and the hand-written `func_801C4030`, `func_801C6D8C`,
  `func_801C6DD4`, `func_801C6F60` are assembled segments.
- **Dinkumware libc in the library unit (`src/18020_C5030.c`).** Register roles that look like permuter work in libc-shaped code follow
  the canonical source: `_Dunscale` matched written Dinkumware-style, `short xchar; unsigned short *ps;`,
  `else if (0 < xchar)` (`func_801D3460`).
- **Casting a scalar extern to a pointer-to-array costs stack slots.** `((s32 (*)[14])&D_X)[i][j]` inside the body
  adds temporaries (a 0x30 frame for the target's 0x20); declare the table at file scope, `extern s32 D_801E693C[][14];`,
  and index it directly (`func_8011A6EC`).
- **Tool pitfalls in shared units.** A `compile_and_diff` result identical to an earlier one after a source change is
  stale: resend the same source before trusting it; "Could not read file magic" is a `build/*.o` race, retry. The brief's
  "current state: 100% match" can show for a stub still at `INCLUDE_ASM` (`func_801C61F4`); compile before believing it.
- **Hardware registers and KSEG bases are literals, not symbols.** splat had paired the `lui`/`lw` halves of
  `0xA4xxxxxx`, `0xA0000000` and `0x80000000` with symbols (`D_A4600010`, `D_A0000000`, `D_80000000`); the original
  source used literals (`PI_STATUS_REG`, `x | 0xA0000000`), so GCC builds the constant with no relocation, and since
  2026-10-28 the libultra targets carry the constants. Write `*(volatile u32 *)0xA4600010` and `arg | 0xA0000000`,
  never `extern u32 D_A4600010`: ten functions matched from that alone (`func_801CF410`, `func_801D0610` ...).
- **IDO's loop unroller (`src/18020_C0800.c`, 2026-10-31).** The unit builds with the unroller on, as the ROM was: a
  counted `for` loop (`for (i = 0; i < n; i++)`, local `n`, even with an early `return` inside) becomes a remainder
  loop (`andi $t,n,3`) plus four copies with a `bnel` back edge; write the plain loop and let it unroll
  (`func_801C2A84`, `func_801C2768`: `for (i = 0; i < 0x134; i++) *p++ = 0;`). A loop the ROM keeps rolled tested a
  global in its condition, `while (i < D_802AB038) { ...; i++; p += 0x134; }`, which also hoists the load once
  (`func_801C0FD8`, `func_801C28A0`, `func_801C0B00`), or counts with `while (n--)` (`func_801C2A18`). Never
  hand-unroll: the unroller unrolls that again. A target that returns `$a1 + 1` is a `u8 *` function, not `void`
  (`func_801C02AC`).
- **IDO 7.1 habits, from 24 matches on 2026-10-31 (`src/18020_C0800.c`).** Source *lines* schedule: independent
  instructions keep the order of their source lines, so three inits on one line or in a `for` header,
  `for (i = 0, p = D_802AB040, n = 0; i < D_802AB038; i++, p += 0x134)`, put `or $v0,$zero` after the table load
  where three lines put it first (`func_801C0C70`, `func_801C0CD4`, `func_801C0B00`); named locals take `$v0`, `$v1`,
  `$a1`.. in order of first assignment. Compound assignments on a variable (`v &= 0x7F; v <<= 8; v |= *p++;`,
  `x <<= 8; x += p[3];`, `arg0[0xB9] += v1;`) compute in the variable's own register (`andi $v1,$v1`); the
  one-expression form goes through `$t` temporaries and ends in a copy (`func_801BF824`, `func_801C0008`,
  `func_801C1FD8`). A dead `addiu $a1,$a1,5` before the return is the sum of `*arg1++` reads, which IDO keeps; a plain
  `arg1 += 5;` is dropped. `p = arg0; value = f(*arg1++); p[k] = value; p[k] += *arg1++;` copies `arg0` to `$a2`
  before the call and spills `$a2` (`func_801C007C` and siblings). Read a byte stream through the struct field with a
  `u8` local, `b = *arg0->unk38++;`: a pointer local lands in `$v0` and the byte in `$v1`, the field form the reverse,
  and the field form gives the `or $a1,$v0` copies in the branch slots (`func_801C2144`). A repeated expression in
  place of a local, `if (A - B > 0) ... (f32)(A - B)`, numbers the float temporaries as the target does
  (`func_801C20D8`). A K&R `s16` parameter is stored to its home slot and read back with `lh` (`func_801C3A58`).
  `id = D_802AB058++;` keeps the global's address in one register for both accesses (`func_801C2B24`,
  `func_801C0694`); `u8 *volatile *tbl = &D_802AB040;` keeps a table pointer's address in a saved register across a
  loop with calls (`func_801C0694`). A second call that only runs when the first did sits inside the same `if`
  (`func_801C3710`); `for (i = 0; D_801F4384[i] != NULL; i++)` makes the peeled guard load direct (`func_801C3F30`).
- **IDO 7.1, second batch (2026-10-31).** Write one statement per line: a draft compressed onto a few lines
  schedules its stores and inits in another order (`func_801C3758` 91% -> 99.8%, `func_801C1DB4` 87% -> 99.7% from
  the reformatting alone). A `bltz` preceded by `sll $t,$v,0` is `if (!(x & 0x80000000))` (`func_801C249C`). A
  function that returns an uninitialised local in `$a1` with no stack frame takes that value as its second parameter,
  `s32 f(T *arg0, s32 ret)`: a plain uninitialised local gets a stack slot instead (`func_801BFE90`). A table index
  that steps by 4 beside `i` is `*(s32 **)((u8 *)base + off)`, not `((s32 **)base)[i]`, which adds an induction
  variable and a frame slot (`func_801C249C`). `return f(...)` straight from inside a scan, with the global in the
  loop condition, gives the `b epilogue; lw $ra` tails and the `slt`/`bnez` loop test (`func_801C08E4`).
- **IDO habits (`src/18020_C0800.c`), from twelve matches on 2026-10-30 (5.3 then, 7.1 now; the habits are the same).** Registers follow the source, not the
  permuter: a value used once is an expression temporary (`$t6`, `$t7` ... in evaluation order), a named local is a
  variable in `$v0`, `$v1`, `$a2`, `$a3` in order of first assignment, so drop single-use locals (`arg0[0xB4] = *arg1++;
  if (arg0[0xB4] != 0)`, `*(u16 *)(p + 0x98) = (*(u16 *)(p + 0xA4) * arg1) >> 7`) and keep the ones the target keeps.
  `bgez; sra; addiu at,+1; sra` is `x / 2`. A `lb` is `*(s8 *)p`, not `(s8)p[i]`. An early `b` over the second test is
  `if (a < 0) a = 0; else if (a > 127) a = 127;`. `c.eq.s; bc1fl; mtc1; jr` at the top is an early `if (x == 0.0f) return 1.0f;`.
  A counted scan with the count load before `blez` and `i = 0` in its slot is a `for (i = 0, p = base; i < n; i++, p += s)`;
  a reload of the count through an address register means a `count` local, test the global directly. Store order is
  kept: a constant materialised late was the last statement. A result that lands in `$f2` was a named `result` local
  stored right after (`func_801BF85C`, `func_801C0DAC`, `func_801BFF9C`, `func_801C2088`, `func_801C0E3C`,
  `func_801C2314`, `func_801C2BB0`, `func_801C1D48`, `func_801C1080`, `func_801C3FC0`, `func_801C0D40`, `func_801C1FBC`).

See [KMC GCC learnings](docs/kmc-gcc-learnings.md), downloaded from
[cdlewis/snowboardkids2-decomp](https://github.com/cdlewis/snowboardkids2-decomp/blob/main/DECOMPILATION_LEARNINGS.md),
which uses KMC GCC 2.7.2 with `-O2 -mips3`. Credit belongs to that project's contributors.
Its inline-assembly barriers and fixed-register advice **do not apply here**: decomp.wtf
rejects inline assembly and register pinning. Follow the pure-C and protected-file rules above.

A historical “Match” commit message is not proof of a current match; require objdiff and the ROM checksum.

## Claim order and what a note is worth

Claims are made by name from the generated lists (`claim_function(function="func_XXXXXXXX")`) or with
`strategy="closest"` for a session's first claim; never release and re-claim the same function.

- **Never release a workable function without compiling.** A release costs a claim cycle for every other
  agent and pushes the function down the scheduler; it is not a way to browse.
- **An older note saying "register-only" or "permuter material" is a hypothesis, not a verdict.** Measured on
  2026-10-24: 47 of the 134 functions matched in the preceding three days had carried that verdict before
  they matched, and 91 of the 207 open near misses still carry one. The first move on every near miss is to
  list the rows where a branch target differs: a branch landing a few rows from ours is a statement on the
  wrong side of an `if` (or a retry `do { } while` written straight), and fixing that comes before any
  register work.
- **Release at once only** the hand-written targets (rule 10) and the -O0 targets sitting in -O2 files.

## Maintainer backlog (not agent work)

1. **Link gate.** A check-in step that runs the assembler hazard probes and a two-build per-function objdiff comparison, so no toolchain or symbol change lands silently. The link broke for a day on 2026-10-14 and 49 matches would have vanished with a plain assembler rebuild; neither was visible to objdiff.
2. **Library unit: done.** 2026-10-19: its objects were built without `-g` (GAS fills the delay slots), with `ldc1`/`sdc1`
   doubles and the coprocessor hazard nops (`--fp-move-nops`): 41 -> 163 matched. 2026-10-21: the unit was split at `sqrtf`
   (`func_801C4030`) into `src/18020_C0800.c` (game code, game flags) and `src/18020_C5030.c` (libultra, library flags)
   with `tools/fable/split_unit.py`: expected objects rebuilt from the per-function `.s` files (assembled with
   `--fp-move-nops` so nothing is transformed), no match lost. The libgcc tail got its own `-O2 -g2` piece on 2026-10-29 (item 11).

3. **-O0 functions: done 2026-10-21.** The 142 targets built at -O0 (frame pointer in `$30`) sat in 9 runs inside the
   -O2 unit; `tools/fable/split_unit.py` cut `src/18020_1D7F0.c` into 19 pieces at every change of flags, the -O0 pieces
   with `OPTFLAGS := -O0 -g2`, and `tools/fable/o0_merge.py` folded the old `src/18020_O0.c` into them (that unit never
   linked). Judged on the live file: 547 -> 559 matched, none lost, twelve -O0 drafts matched as they were. A piece keeps
   the one file's semantics: prototypes of earlier definitions in place, live `#define`s, block-scope externs replayed
   in discarded `static inline` stubs (GCC 2.7.2 keeps them as the identifier's external declaration), padding blocks
   by address. Expected objects come from the per-function `.s` files assembled with `--fp-move-nops`.

4. **Hand-written routines: done 2026-10-29.** The 31 libultra exception/interrupt/CP0 routines are nine assembled segments (`asm/E860.s` ... `asm/D2D00.s`, rule 10), cut out of `src/D910.c` and `src/18020_C5030.c` with `tools/fable/split_unit.py` (tag ASM; padding between routines as labelled words); each segment linked alone is byte-identical to the ROM. `tools/fable/pack_text.py` (`PACK_TEXT := 1` in the Makefile) trims a piece that starts or ends inside a 16-byte line so it links at its true address; the 2026-10-21 game pieces that start mid-line (`18020_376E8`, `18020_3A90C`, `18020_479E4`, `18020_47B98` ...) still want it.
5. **Editor pass.** `tools/editor_pass.sh` runs hourly from cron and does nothing unless agents produced events, compiles or notes since the last pass. It regenerates both claim lists from the database, copies new project-wide notes into `docs/notes-digest.md`, deletes housekeeping notes about stale lists (archived under `~/Decomp/.decomp/glover-editor/`), asks a headless Claude to promote general lessons into "Lessons from agents" above, and commits only those docs. Log: `~/Decomp/.decomp/glover-editor/editor.log`.
6. **VR4300 multiply-errata nops: done 2026-10-19.** The ROM has 60 `mul; nop; mul` sites and no adjacent float
   multiply pairs, but turning the assembler's mulmul fix on lost 39 matches because the mimic in `gas/input-file.c`
   also treated any line starting in column 0 (every label) as a float multiply, padding the next `mul*`. With that
   clause removed and `-Wa,--vr4300mul-off` dropped from the Makefile: 687 -> 700 matched, 0 lost, 45 drafts improved
   (func_80160728, func_80160830, func_8014B110, func_8018AE5C, func_8017D21C ... matched from that alone). A
   `mul.s`/`mul.d` directly followed by `mul*` now gets the nop; a float multiply the target keeps out of a delay slot
   was the assembler too (item 8).
7. **HI/LO hazard at `.set noreorder`: done 2026-10-19.** GAS flushed the `mfhi`/`mflo` hazard with two nops whenever
   GCC's `.set noreorder` (a filled branch) followed; the ROM never has them, but keeps the nop before a `div`/`mult`
   macro (`mfhi; lhu; nop; div`). `tools/kmc-as-fixes.patch` now skips the padding only at the directive
   (`mips_set_noreorder_pending`): 681 -> 687 matched, 0 lost, 16 drafts improved. Treating HI/LO as fully
   interlocked instead lost 6 (the macro case and `mfhi` swapped into delay slots in the no-`-g` unit).
8. **Float multiply in a delay slot: done 2026-10-20.** The ROM never has `mul.s`/`mul.d` in a branch delay slot (0 of
   45 in our build): its assembler moved the multiply in front of the branch and left a nop in the slot, even for
   branch-likely. `tools/kmc-as-fixes.patch` now does the same in `.set noreorder` blocks and never swaps one in
   (not under `--fp-move-nops`): 752 -> 758 matched, 0 lost, 30 drafts improved. Found by opus-z with a `.s`
   post-pass (`/tmp/opus-z/sim/unfill2.py`).
9. **FP compare before a flush: done 2026-10-20.** GAS padded every FP compare followed by a label or directive; the
   ROM pads only when the next instruction reads the condition code (`c.eq.s; j` bare, `c.lt.s; .L: nop; bc1t` kept).
   The hazard is now remembered across the flush and paid at the consumer: 758 -> 761 matched, 0 lost, 25 drafts improved.

10. **A `mul.s` hazard across a branch: done 2026-10-29.** The ROM pads a `mul*` that follows `mul.s`/`mul.d` when only
    a branch without link (`j`, `b`, `beq`.., `bc1f`/`bc1t` and their likely forms) and its delay-slot `nop` sit between
    them (19 sites in the ROM, none against). `tools/kmc-as-fixes.patch` now checks the three words before a multiply
    in `append_insn`; two-build comparison 1027 -> 1028 matched, 0 lost (`func_80157708` matched), 16 drafts improved.
11. **libgcc tail of the library unit: done 2026-10-29.** `func_801D3AA0` (`__divdi3`), `func_801D3B40`, `func_801D3B60` and
    `func_801D41A0` match at `-O2 -g2` (game flags) in their own piece `src/18020_D4AA0.c` (tag LIBGCC); two line joins in
    `__udivmoddi4` removed the line-note nops. 1028 -> 1032 matched, 0 lost.
12. **Editor pass.** Its cron line was disabled from 2026-10-18 to 2026-10-28 and the claim lists went nine days stale;
    it runs hourly again with `--no-promote` (no Claude), so the lists follow the database and lessons are promoted by hand.

## Where the remaining work is (2026-10-29)

**`func_8016A058` (2026-10-31 evening, 99.6%, 99 of 7,745 rows, set aside in the app for a dedicated session).**
Plain C in `src/18020_56B90.c`. Today's finding: the object scan loop (rows 6764-7020) was written with the
`a[] = obj->pos - player` vector inline at every keep and stop site (a macro in the original); the post-reload
cross-jump pass merges the identical copies back into the two shared blocks the ROM shows, while the copies still
count for the loop pass and the allocator: the vector constants are hoisted right after `8` (first copy in the
`W0 == 8` arm) and `&D_8029030C` gets the top rank (`$a3`), which put `$a1`/`$a2`/`$t0`-`$t3` on the ROM's registers.
Two sites stay `goto stop_806` (the `q7[0]`/`q9[0]` tests): inline copies there cross-jump into the found block
before the loop. The volatile `D_801E7533` read sits between `bits = AB24 << 3` and `bits -= AB24`, the ROM's
instruction order; the `case 44` table pointer is `{ u8 *tbl = (u8 *)&D_8029F398; _290 = tbl + _196 * 0xC; }`, which
puts the base's `lui`/`addiu` before the index multiply as the ROM has it. 146 -> 99 rows. Tried and rejected: the
`_138`/`_143`/`_145` vector temps written as plain sums or reordered (106), `*fb` in the `case 44` else arm (the
ROM reloads it after the stores where ours CSEs the converted value: 110-117, volatile gives `lhu`), the
`D_802996E8` loop as one induction variable with products in the body (177-186). What is left, target first: (1) rows 6785-6809, 27 rows: the ROM hoists the
`s8 *w = &D_801E7531` pointer trio last (`..., lw D_801EFD00, w, w+7, w+9, -1, sltiu`), ours first. GCC 2.7.2's
loop.c emits movables in scan order (body top to bottom; `stmt.c expand_end_loop` rotates the first exit test to the
bottom and `jump.c duplicate_loop_exit_test` copies it before the loop), and a user variable set at the loop top is
always met first; a user variable set anywhere later is not movable at all (used before set), and a compiler temp
holding `&D_801E7531` set late cannot be what the early `lb $v1,0($t1)` reads. No source shape tried (pointer sets
before an explicit `break` test, in the `for` increment, `?:`/statement-expression temps, integer-cast temps,
inlined helpers, declarations in the third arm) moves them last. The order matters twice: with the trio moved
early, loop.c's move threshold (`2 * (1 + 57 non-fixed regs) = 116`, minus 3 per move, times savings and lifetime,
against 372 loop insns) rejects the `lh D_801EAB24` hoist as the 11th candidate (`T*2*2 = 344 < 372`), so AB24 is
loaded in the body, `sltiu` lands in `$t7` instead of `$s0` and `w+7`/`w+9` swap `$t6`/`$t7`; in the ROM AB24 is
the 8th move (`95*4 = 380 >= 372`). Whoever cracks the trio gets all 27 rows. (2) rows 3520-3526: the ROM loads the
`D_80107F00` double before the compare and annuls the `cvt.d.s` of `_98` with `bc1tl` (one `div.d`); ours keeps
the load in the then arm. (3) row 6886: the ROM materialises `6` in the `bnel` slot of the `W0 == 0x2A` test and
compares `type` at the use (`bne $a2,$v0`); the draft's `do { c6_ = (type == 6); } while (0);` gives `xori`, a plain
`&&` or nested `if`s restructure the chain (+50 to +100 rows). (4) 5112-5219 (15 rows), 4482, 5489, 3778, 6173,
4006, 4418: unexamined. `tools/fable/ido_variants.py func_8016A058 <file> --unit 18020_56B90` scores a variant in
about 25 s; a `-dL` compile of the spliced unit (`SCRATCH/vt_func_8016A058_0/unit.c`) prints every movable's
lifetime, savings and verdict under `Loop from`.

1032 of 1208 listed functions match, about two thirds of the code bytes. The near misses (90%+) are a handful; the
permuter-only table holds about sixty functions that the server permuter works in the background; the bulk of the
open work is the "Drafts below 90%" table of [docs/permuter-queue.md](docs/permuter-queue.md) (structure first) and
the IDO unit `src/18020_C0800.c`, where the drafts were written for the wrong compiler (IDO 7.1 with the loop unroller on since 2026-10-31; 55 of 109 matched). `src/D910.c` is two drafts
from linked; the library pieces are ultralib ports. For a large function, a structurally correct draft at 70–90%
with precise release notes is useful progress even without a match.
