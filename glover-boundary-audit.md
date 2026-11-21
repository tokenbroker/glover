# Function-boundary audit

## Baseline

Base ROM: `baserom.z64`, SHA-1 `270be17b3c8da9b88a7b99c2a545b0bce16837f4`.
Splat: 0.50.1; spimdisasm: 1.42.4. Installed in `/tmp/glover-splat-venv`.

A fresh `make RUN_CC_CHECK=0 -B build/src/D910.o build/src/18020.o build/src/18020_O0.o` succeeds after restoring the unsupported builtin drafts. Full-ROM linking fails with unresolved `.L80118088` in `func_801190BC`; there is no verified matching full-ROM baseline. The per-unit baseline against the unchanged `expected/` objects is recorded in [reports/boundary-baseline.json](reports/boundary-baseline.json). It includes the O0 unit missing from the original objdiff configuration.

| Unit | Reported matches |
|---|---:|
| D910 | 37 |
| 18020 | 33 |
| 18020_O0 | 10 |

The unsupported `__builtin_mfc0` in `func_8010D9B4` was introduced by `1cc7ca6`; its use in `func_8010D998` was introduced by `5b2b52c`. Only those two bodies are restored in the baseline preparation commit. Pre-existing working-tree edits are excluded from that commit.

The game segment maps ROM `0x18020` to VRAM `0x80117020`, as established by the entrypoint (`0x80100000` at ROM `0x1000`) and encoded direct jump targets. The previous `0x80118020` mapping was wrong by `0x1000`. `.L80118088` is a local label in the actual function beginning at `0x801170DC`, not a reference to the small preceding function.

Four baseline matches are false function boundaries: old `func_80147000`, `func_80147460`, `func_8015F098`, and `func_801B9894`. Each is only `jr ra; nop` at the end of a parent whose epilogue immediately precedes it. These empty C drafts must be absorbed into the parent, rather than retained as independent functions.

## Boundary repair

The corrected split contains 1,227 standalone CPU functions/handwritten entry routines, plus two callable helpers embedded within the noncontiguous handwritten exception-handler layouts. RSP boot (`ROM 0x1D720–0x1D7F0`) and graphics microcode (`0xBD710–0xC0800`) are binary assets, not CPU functions. C is divided around these assets to preserve storage order. Main text begins at ROM `0xD920`; the initial 16 bytes previously named `func_8010C910` remain in entry data. BSS is explicitly placed at `0x801F5680`.

Function sizes exclude trailing compiler padding. The padding is preserved by constant arrays in `.text`; it is never exposed as a separate function stub. Two handwritten handlers contain callable helpers and out-of-line exception continuations; their physical spans remain together instead of creating epilogue-only stubs. The non-returning thread cleanup entry at `0x801C6F60`, referenced by a function pointer, is retained as a real entry.

All 67 supplied entries were checked against their original instruction words and the corrected ROM-to-VRAM mapping. The table below records the actual byte range and owning complete function(s). Ends are exclusive. The original names are identifiers from the broken split, not reliable VRAM addresses. [Machine-readable evidence](reports/boundary-fragments.json) includes the first two original instructions for each entry. No supplied entry remains unresolved.

| Old symbol | Actual start | Finding | Correct owner/range |
|---|---|---|---|
| `func_801C117C` | `0x801C017C` | Truncated start | `func_801C017C` (`0x801C017C–0x801C025C`) |
| `func_801D51CC` | `0x801D41CC` | Padding | `0x801D41CC–0x801D41D0` after `func_801D41A0` |
| `func_8010C910` | `0x8010C910` | Entry data/padding | ROM `0xD910–0xD920`, retained in entry assembly |
| `func_80144AF8` | `0x80143AF8` | Tail/epilogue | `func_801437E4` (`0x801437E4–0x80143AFC`) |
| `func_801499EC` | `0x801489EC` | Tail/epilogue | `func_801488C0` (`0x801488C0–0x801489F0`) |
| `func_801C8690` | `0x801C7690` | Truncated start | `func_801C7690` (`0x801C7690–0x801C76EC`) |
| `func_801CFA5C` | `0x801CEA5C` | Padding | `0x801CEA5C–0x801CEA60` after `func_801CE950` |
| `func_80133B90` | `0x80132B90` | Internal block | `func_80132B5C` (`0x80132B5C–0x80132BB0`) |
| `func_8018AA58` | `0x80189A58` | Truncated start | `func_80189A58` (`0x80189A58–0x80189B50`) |
| `func_801C2C10` | `0x801C1C10` | Tail/epilogue | `func_801C1A90` (`0x801C1A90–0x801C1C1C`) |
| `func_8018A040` | `0x80189040` | Truncated start | `func_80189040` (`0x80189040–0x80189098`) |
| `func_80149C3C` | `0x80148C3C` | Truncated start | `func_80148C3C` (`0x80148C3C–0x80148CC8`) |
| `func_80122F9C` | `0x80121F9C` | Crosses real functions | `func_80120D18` (`0x80120D18–0x80121FCC`); `func_80121FCC` (`0x80121FCC–0x80121FF4`); `func_80121FF4` (`0x80121FF4–0x80122D68`) |
| `func_801A87CC` | `0x801A77CC` | Tail/epilogue | `func_801A76CC` (`0x801A76CC–0x801A77D8`) |
| `func_8014A9EC` | `0x801499EC` | Truncated start | `func_801499EC` (`0x801499EC–0x80149C4C`) |
| `func_8017674C` | `0x8017574C` | Truncated start | `func_8017574C` (`0x8017574C–0x801758D0`) |
| `func_80160910` | `0x8015F910` | Truncated start | `func_8015F910` (`0x8015F910–0x80160228`) |
| `func_8018B47C` | `0x8018A47C` | Internal block | `func_8018A050` (`0x8018A050–0x8018A9C8`) |
| `func_8014932C` | `0x8014832C` | Internal block | `func_80148000` (`0x80148000–0x801484F0`) |
| `func_8015CA6C` | `0x8015BA6C` | Truncated start | `func_8015BA6C` (`0x8015BA6C–0x8015BE58`) |
| `func_8019A008` | `0x80199008` | Truncated start | `func_80199008` (`0x80199008–0x801990D4`) |
| `func_801C2080` | `0x801C1080` | Truncated start | `func_801C1080` (`0x801C1080–0x801C10B4`) |
| `func_801C2A84` | `0x801C1A84` | Tail/epilogue | `func_801C19FC` (`0x801C19FC–0x801C1A90`) |
| `func_80141C1C` | `0x80140C1C` | Truncated start | `func_80140C1C` (`0x80140C1C–0x801411DC`) |
| `func_801A6FC0` | `0x801A5FC0` | Internal block | `func_801A5EDC` (`0x801A5EDC–0x801A6170`) |
| `func_801C6F70` | `0x801C5F70` | Tail/epilogue | `func_801C5F20` (`0x801C5F20–0x801C5F80`) |
| `func_801C73C0` | `0x801C63C0` | Padding | `0x801C63C0–0x801C63D0` after `func_801C62C0` |
| `func_801C73B0` | `0x801C63B0` | Padding | `0x801C63B0–0x801C63C0` after `func_801C62C0` |
| `func_801C6F80` | `0x801C5F80` | Truncated start | `func_801C5F80` (`0x801C5F80–0x801C5FFC`) |
| `func_801C62B0` | `0x801C52B0` | Internal block | `func_801C5224` (`0x801C5224–0x801C52F8`) |
| `func_801C7550` | `0x801C6550` | Truncated start | `func_801C6550` (`0x801C6550–0x801C6620`) |
| `func_801CE2F0` | `0x801CD2F0` | Internal block | `func_801CC118` (`0x801CC118–0x801CD3C0`) |
| `func_801CE750` | `0x801CD750` | Internal block | `func_801CD578` (`0x801CD578–0x801CE22C`) |
| `func_801CEDF0` | `0x801CDDF0` | Internal block | `func_801CD578` (`0x801CD578–0x801CE22C`) |
| `func_801CC050` | `0x801CB050` | Tail/epilogue | `func_801CAFC8` (`0x801CAFC8–0x801CB054`) |
| `func_801CA030` | `0x801C9030` | Internal block | `func_801C8EC0` (`0x801C8EC0–0x801C906C`) |
| `func_801CE900` | `0x801CD900` | Internal block | `func_801CD578` (`0x801CD578–0x801CE22C`) |
| `func_80133990` | `0x80132990` | Truncated start | `func_80132990` (`0x80132990–0x80132A30`) |
| `func_801CB9A0` | `0x801CA9A0` | Internal block | `func_801CA844` (`0x801CA844–0x801CAA34`) |
| `func_801C4030` | `0x801C3030` | Tail/epilogue | `func_801C2C10` (`0x801C2C10–0x801C3040`) |
| `func_801CF8B0` | `0x801CE8B0` | Truncated start | `func_801CE8B0` (`0x801CE8B0–0x801CE8FC`) |
| `func_80149318` | `0x80148318` | Internal block | `func_80148000` (`0x80148000–0x801484F0`) |
| `func_801C6DD4` | `0x801C5DD4` | Internal block | `func_801C5CEC` (`0x801C5CEC–0x801C5E64`) |
| `func_801D2C10` | `0x801D1C10` | Tail/epilogue | `func_801D1BB4` (`0x801D1BB4–0x801D1C20`) |
| `func_8019B658` | `0x8019A658` | Tail/epilogue | `func_8019A47C` (`0x8019A47C–0x8019A668`) |
| `func_80133B9C` | `0x80132B9C` | Tail/epilogue | `func_80132B5C` (`0x80132B5C–0x80132BB0`) |
| `func_801AEAF8` | `0x801ADAF8` | Truncated start | `func_801ADAF8` (`0x801ADAF8–0x801ADDC4`) |
| `func_8014A9D8` | `0x801499D8` | Tail/epilogue | `func_801499A0` (`0x801499A0–0x801499EC`) |
| `func_801CBC4C` | `0x801CAC4C` | Truncated start | `func_801CAC4C` (`0x801CAC4C–0x801CADBC`) |
| `func_80178390` | `0x80177390` | Truncated start | `func_80177390` (`0x80177390–0x8017753C`) |
| `func_801976D8` | `0x801966D8` | Truncated start | `func_801966D8` (`0x801966D8–0x801971A8`) |
| `func_8014707C` | `0x8014607C` | Internal block | `func_80146008` (`0x80146008–0x801462E0`) |
| `func_8014B03C` | `0x8014A03C` | Tail/epilogue | `func_80149C4C` (`0x80149C4C–0x8014A040`) |
| `func_801764A8` | `0x801754A8` | Tail/epilogue | `func_8017541C` (`0x8017541C–0x801754C0`) |
| `func_801D2C20` | `0x801D1C20` | Whole function (old name/address wrong) | `func_801D1C20` (`0x801D1C20–0x801D1C48`) |
| `func_801D126C` | `0x801D026C` | Tail/epilogue | `func_801D01C4` (`0x801D01C4–0x801D0280`) |
| `func_801CB1BC` | `0x801CA1BC` | Tail/epilogue | `func_801CA1A0` (`0x801CA1A0–0x801CA1D0`) |
| `func_801C3F18` | `0x801C2F18` | Internal block | `func_801C2C10` (`0x801C2C10–0x801C3040`) |
| `func_80150E88` | `0x8014FE88` | Truncated start | `func_8014FE88` (`0x8014FE88–0x80150110`) |
| `func_8019A2C8` | `0x801992C8` | Tail/epilogue | `func_801990D4` (`0x801990D4–0x801992E0`) |
| `func_8018AE5C` | `0x80189E5C` | Tail/epilogue | `func_80189C9C` (`0x80189C9C–0x80189E78`) |
| `func_80180644` | `0x8017F644` | Tail/epilogue | `func_8017F25C` (`0x8017F25C–0x8017F660`) |
| `func_801CFE9C` | `0x801CEE9C` | Tail/epilogue | `func_801CEE60` (`0x801CEE60–0x801CEEAC`) |
| `func_801CC0D0` | `0x801CB0D0` | Internal block | `func_801CB060` (`0x801CB060–0x801CB160`) |
| `func_801CF6FC` | `0x801CE6FC` | Truncated start | `func_801CE6FC` (`0x801CE6FC–0x801CE728`) |
| `func_801CB7B8` | `0x801CA7B8` | Internal block | `func_801CA480` (`0x801CA480–0x801CA830`) |
| `func_801470F8` | `0x801460F8` | Internal block | `func_80146008` (`0x80146008–0x801462E0`) |

## Preserved C and verification

No new C function body was written. The 66 genuine O2 matches retain their bodies, with game definitions renamed down by `0x1000` to their real addresses. Encoded call targets already used real VRAM and are not mechanically shifted. The four false empty-body epilogue matches listed above are absorbed into their parents. Other nonmatching drafts, including old `func_8017674C` and `func_801C111C`, are restored to assembly; their old bodies are available in the preceding git history and the session backup under `/tmp/glover-boundary-audit/`. The existing O0 source/object is unchanged and retains its 10 baseline matches; its existing linker treatment is unchanged.

[Preserved-function mapping](reports/boundary-preserved.json) records the old/new names and compiled sizes. The old expected game object had the same bad names/boundaries, so it cannot serve as the final boundary target. New expected objects are assembled independently from the ROM-derived function assembly, with original padding words. The baseline objects remain available in git history. Two recursive calls score below 100% against a mechanically renamed old target because the old target mistakenly points at a different function; both score 100% against the correctly extracted targets.

The original assembler mishandles one interleaved local `.text` HI16/LO16 pair at ROM `0xC4B2C`/`0xC4B34` after the data-like `D_801CA480` is correctly classified as a function. Explicit `MIPS_NONE` extraction overrides preserve the original literal address for that pair. No generated assembly was hand-edited, and compiler flags/Makefile are unchanged. Splat's generated macro replacement is disabled to retain the existing assembler-compatible macros.

The final objdiff configuration includes all three game C ranges and the existing O0 unit. [Final objdiff report](reports/boundary-final.json) records the results.

Commands used for extraction/build verification (the virtual environment supplies splat without changing the Makefile):

```sh
make extract PYTHON=/tmp/glover-splat-venv/bin/python
make RUN_CC_CHECK=0 -B
cmp baserom.z64 build/glover.z64
sha1sum baserom.z64 build/glover.z64
objdiff-cli report generate -p . -o reports/boundary-final.json
```

The original verification used fresh extraction and `make RUN_CC_CHECK=0 -B`, but did not remove the build directory. It therefore missed the absent BSS source and used a stale BSS object. That clean-build claim is superseded by the clean-state verification below. The independent assembly target comparison was also performed before the stale object was discovered.

- ROM size: `8,388,608` bytes.
- SHA-1: `270be17b3c8da9b88a7b99c2a545b0bce16837f4`.
- MD5: `87aa5740dff79291ee97832da1f86205`.
- Byte differences: **0**.

## Clean-build correction

The standalone `game_bss` parent specified its VRAM, but its `bss` subsegment did not. Splat requires the NOLOAD subsegment itself to declare its VRAM. Without it, splat generated the linker reference to `build/asm/data/F5680.bss.o` but skipped scanning/generating its source. A surviving object hid the error during the earlier non-clean rebuilds.

The subsegment now explicitly declares `vram: 0x801F5680`. Re-extraction generates and tracks `asm/data/F5680.bss.s`, so the unchanged Makefile discovers and assembles it from scratch. Generated data references and undefined symbols now use the BSS definitions. No linker-script workaround or compiler change is needed.

Verification was performed only after deleting the complete build directory, with this exact command:

```sh
make clean && make RUN_CC_CHECK=0 && sha1sum build/glover.z64
```

It completed successfully and printed:

```text
270be17b3c8da9b88a7b99c2a545b0bce16837f4  build/glover.z64
```

[Complete clean-build output](reports/boundary-clean-build.log) includes compilation of every C unit and assembly of `F5680.bss.s`. The linked `.game_bss_bss` is NOBITS at `0x801F5680`, size `0xBB690`, ending at `0x802B0D10`. `cmp baserom.z64 build/glover.z64` and `md5sum -c checksum.md5` also passed on that clean build.

[Clean-state objdiff report](reports/boundary-clean-objdiff.json) retains every previous 100% match (D910: 41; game ranges: 3, 57, 3; O0: 10), with zero regressions. All 76 genuine original baseline matches remain at 100%.
