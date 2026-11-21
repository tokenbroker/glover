# Untouched functions

Regenerated 2026-11-20 19:07 by the hourly editor pass (`tools/editor_pass.py`) from the decomp.wtf database: open functions that still have an `INCLUDE_ASM` stub and zero compiles, game units only, D910 first. Claim by name: `claim_function(function="func_XXXXXXXX")`, picking a random line from the first 40. If the tool says a line is already matched or hands you a different function instead, release the substitute at once (note `substituted`) and pick another line. Work what you claim: start from the best attempt, compile, up to about 25 compiles while the score moves, then release with notes. A function you have already released this session is not yours to claim again.

## Large, undrafted: Claude Fable only

Structure first: calls, control flow, types, the struct layouts the function implies (add them to include/structs.h as new structs, never by editing fields matched code uses). Stop at 80% or 15 compiles, whichever comes first, and release with a handoff note in this shape: `structure done at NN%; remaining: <what differs>; tried: <forms>; next: <one concrete idea>`. A cheaper model and the permuter take it from there.

| Function | File | Size (bytes) |
|---|---|---:|
| (none) | | |

## Medium, undrafted: DeepSeek, Gemini, Codex

Same deliverable, same handoff note, up to 25 compiles.

| Function | File | Size (bytes) |
|---|---|---:|
| (none) | | |

## Hand-written assembly: do not claim

libultra exception, interrupt and CP0/FPU-control routines assembled by hand (rule 10 in AGENTS.md). Release on sight with the note `handwritten asm`.

| Function | File | Size (bytes) |
|---|---|---:|
| `func_8010D874` | `src/D910.c` | 36 |
| `func_8010D97C` | `src/D910.c` | 28 |
| `func_8010D998` | `src/D910.c` | 28 |
| `func_8010D9B4` | `src/D910.c` | 12 |
| `func_8010D9C0` | `src/D910.c` | 12 |
| `func_801C62B0` | `src/18020_C5030.c` | 12 |
| `func_801C6620` | `src/18020_C5030.c` | 16 |
| `func_801C6F70` | `src/18020_C5030.c` | 32 |
| `func_801C73B0` | `src/18020_C5030.c` | 16 |
| `func_801D2020` | `src/18020_C5030.c` | 160 |
