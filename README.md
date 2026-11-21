# Glover (N64) decompilation

A **100% matching decompilation** of *Glover* (Nintendo 64, USA, SHA-1 `270be17b3c8da9b88a7b99c2a545b0bce16837f4`).
Every compiled function in the game is C that the game's original compilers turn back into the exact ROM bytes:
building this repository reproduces the retail ROM byte for byte.

Built on [bigyoshi51/glover-decomp](https://github.com/bigyoshi51/glover-decomp), which started the project and set up
the splat configuration this one still uses.

## Status

| | |
|---|---|
| Compiled functions in C, matching | all of them (no `INCLUDE_ASM` stubs left) |
| ROM | rebuilds byte-identical (`checksum.md5`) |
| Hand-written assembly | ~35 libultra routines (exception and interrupt handlers, CP0/FPU control, `sqrtf`, thread queue), assembled from `.s` as in the original |
| Data / rodata | still assembled from splat's output, not yet migrated to C |
| Naming and documentation | early: most functions are still `func_XXXXXXXX`, many struct fields `unkXX` |
| Shiftable | not yet (data is laid out by address) |

## Building

You need your own copy of the ROM. No ROM data is in this repository: the assembly, data and binary assets are
extracted from your ROM by `make extract`.

Requirements (Linux, WSL or macOS): `make`, `python3`, MIPS binutils (`mips-linux-gnu-as`/`ld`/`objcopy`, e.g.
`binutils-mips-linux-gnu` on Debian/Ubuntu) and [splat](https://github.com/ethteck/splat) 0.50.1
(`pip install "splat64[mips]==0.50.1"`). The compilers (KMC GCC 2.7.2, IDO 7.1 via ido-static-recomp) and the patched
assembler are in `tools/`.

```sh
cp /path/to/your/glover.z64 baserom.z64     # big-endian .z64, SHA-1 above
make extract                                 # splat: asm/, assets/ from the ROM
make RUN_CC_CHECK=0 -j8                      # builds build/glover.z64
md5sum -c checksum.md5                       # build/glover.z64: OK
```

`make expected` copies the build's objects to `expected/` for [objdiff](https://github.com/encounter/objdiff)
(`objdiff.json`), useful as a regression check while renaming or restructuring code.

## Layout

- `src/` – the C, one file per original compilation unit, with the game's code cut into pieces at every change of
  compiler flags (some of the game was built at `-O0`, the libultra part without `-g`, and `src/18020_C0800.c` with
  IDO 7.1 rather than KMC GCC).
- `include/` – shared types and structs.
- `glover.yaml`, `glover.ld`, `symbol_addrs.txt`, `undefined_syms*.txt` – splat config, linker script and symbols.
- `tools/` – compilers, the patched KMC GNU as 2.6 (`tools/kmc-as-*.patch`, rebuilt with `tools/kmc-as-build.sh`),
  asm-processor, and the scripts used during matching (`tools/fable/`, permuter helpers).
- `AGENTS.md`, `docs/` – the rulebook and compiler notes from the matching phase. They describe how the matching was
  done; much of the workflow there (claim lists, the editor pass) is historical now.

## Toolchain notes

- KMC GCC 2.7.2, `-O2 -g2 -G0 -mips3 -mgp32 -mfp32`, with per-unit overrides in the Makefile.
- The assembler is decompals' mips-binutils 2.6 rebuilt with the patches in `tools/`, so it pads, reorders and pools
  literals exactly like the assembler that built the ROM. `AGENTS.md` documents each patch.
- `src/18020_C0800.c` is built with IDO 7.1 (`-O2 -mips2`), its padding spliced in by asm-processor.

## How it was made

Most of the C was written by AI agents through [decompdecomp](https://decomp.ndelic.com), with a
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) farm for register allocation and a human
maintaining the toolchain, the unit layout and the rules.

## Credits

- **[bigyoshi51](https://github.com/bigyoshi51)** – the original Glover decompilation project, its splat setup and the
  first matched functions; this repository grew out of it.
- The compiler-behaviour notes in `docs/kmc-gcc-learnings.md` come from the Snowboard Kids 2 decompilation.
- Tools: [splat](https://github.com/ethteck/splat), [spimdisasm](https://github.com/Decompollaborate/spimdisasm),
  [objdiff](https://github.com/encounter/objdiff), [decomp-permuter](https://github.com/simonlindholm/decomp-permuter),
  [asm-processor](https://github.com/simonlindholm/asm-processor),
  [ido-static-recomp](https://github.com/decompals/ido-static-recomp), KMC GCC 2.7.2 and decompals' binutils 2.6.

Glover is the property of its rights holders. This repository contains no ROM or ROM-derived data; you must supply
your own legally obtained copy.
