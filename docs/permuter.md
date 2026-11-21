# Running the permuter

The installed tool is pinned to simonlindholm/decomp-permuter commit `8556c81d80d1c1af98a858c8f4dc951357f29139`. Tool checkout and virtual environment are ignored; reproduce them with:

```sh
tools/run_permuter.sh --setup
tools/run_permuter.sh 5                  # 5 best drafts, 30 minutes each, all CPU cores
tools/run_permuter.sh 1 --seconds 30     # brief test
tools/run_permuter.sh 10 --list          # compile/rank only
tools/run_permuter.sh --function func_8010CF54 --seconds 60 --jobs 4
```

Requires Python 3.11+, git, cpp, MIPS binutils, objdiff-cli, and the existing KMC toolchain. Setup downloads the pinned tool and installs isolated Python dependencies. On this machine the legacy compiler requires execution outside the filesystem sandbox; use the normal command approval mechanism when prompted.

Cleanup intentionally removes nonmatching C bodies from src/. The runner therefore uses pre-cleanup revision `e632d9d36fcdb428c6f1b6b3538a10c39d526b53` by default (the `before-codex-cleanup` tag's original target). It compiles those archived modules and headers under `permuter_results/ranking/<revision>/` without linking them or editing the working source. This also preserves access to their declarations and local types. `--draft-ref REF` selects a later revision with new drafts. The existing root `permuter_settings.toml` supplies `compiler_type = "gcc"` to each isolated input.

Ranking uses a freshly generated objdiff report on archived objects and the current expected objects, then excludes the protected 100% baseline, assembly stubs, -O0 modules and cross-unit -O0 draft copies, and unsupported inline-assembly/builtin inputs. The CLI report exposes percentages rather than raw decomp.wtf scores, so the sortable **objdiff distance is 100 minus fuzzy_match_percent**: lowest nonzero distance first. The default archive currently has 126 eligible pure-C drafts. Partial working-tree experiments from stopped agents are not resurrected. The top candidate is func_8010CF54 at 99.44444% (distance 0.55556).

For each selected function, the runner isolates a single C body with its declaration context, copies target assembly to ignored output, assembles target.o, and invokes the original compiler with unchanged project -O2/-g2/-G0/-mips3/-mgp32/-mfp32 and assembler flags. No project macro, build config, source, target assembly, linker or symbols are edited. Distinct list layouts and headers are taken from the selected revision to avoid cross-version type collisions. Functions requiring -O0 must be released with a note unless already in the designated -O0 unit; this runner does not move them.

Each run is saved under `permuter_results/<func>/<timestamp>/`, preserving earlier outputs. Inputs include base.c, target.o, compile.sh and settings.toml. `selection.json` records the ranking and revision; `run.log` records permuter scores; `status.json` records workers, elapsed time and termination. Improved candidates use upstream `output-<score>-<index>/` directories within that run. Time limits interrupt the whole worker process group and allow ten seconds for shutdown before killing remaining workers. Default worker count is all detected CPU cores; functions run sequentially, giving each the full worker pool. Failed inputs are reported and the remaining selected functions are still attempted.

A permuter score of zero is only a proposal: stack differences are enabled, but objdiff and the full linked-ROM SHA-1 remain the acceptance criteria. The script neither applies nor commits results.

Validation: the default installed setup completed a 12-second run on func_8010CF54 with 16 workers and shut down at the time limit. Its isolated input retained the original 99.44444% objdiff result, with permuter base score 60. No improvement or match was found during this smoke test. Results and logs remain locally in the ignored results directory.
