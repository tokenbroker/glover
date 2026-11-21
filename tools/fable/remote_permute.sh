#!/usr/bin/env bash
# Run the off-tree permuter on another x86-64 Linux machine (a dedicated server), on a copy of this repo.
#
# One-time, from the home machine:   tools/fable/remote_push.sh user@host [remote-dir]
# Then on the server, in the repo:    tools/fable/remote_permute.sh [jobs] [seconds-per-function]
# Back home, as often as you like:    tools/fable/remote_pull.sh user@host [remote-dir]   (verifies + submits improvements)
# tools/fable/permute_cycle.sh does all three every hour (and runs tools/fable/local_permute.sh at home).
#
# The queue is permuter_results/queue.txt (one function per line, best first); remote_push.sh writes it from the app's
# database. Results land in permuter_results/<function>/<run>/output-*/source.c like the local batches. The batch
# walks the queue as it was when it started, but skips a function that a later push dropped from it (matched, or its
# draft has had its runs).
set -u
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
JOBS=${1:-24}; SECS=${2:-900}
export OBJDIFF_CLI="${OBJDIFF_CLI:-$HOME/.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli}"
export TMPDIR="${TMPDIR:-$HOME/tmp}"; mkdir -p "$TMPDIR"   # gcc temp files on the big disk: a 4 GB /tmp filled up with leftovers of killed compiles (2026-10-26)
find "$TMPDIR" -maxdepth 1 -name "cc*" -mmin +30 -type f -delete 2>/dev/null
[ -x "$OBJDIFF_CLI" ] || { echo "objdiff-cli missing at $OBJDIFF_CLI (remote_push.sh copies it)"; exit 1; }
export PATH="$HOME/.local/bin:$PATH"   # a home-built mips-linux-gnu-objdump (decomp-permuter scores with it)
command -v mips-linux-gnu-objdump >/dev/null || { echo "mips-linux-gnu-objdump missing: build binutils with --target=mips-linux-gnu --prefix=\$HOME/.local (make all-binutils install-binutils)"; exit 1; }
[ -x tools/.permuter-venv/bin/python ] || python3 -I tools/run_permuter.py --setup || exit 1
# --draft-ref: the tree's drafts as they were pushed, as a commit of this copy. The next push (rsync --delete) removes
# that commit again, so it is made anew whenever it is gone (and the old one's compiled snapshot goes with it).
REF=
new_ref() {
  [ -n "$REF" ] && [ "$REF" != HEAD ] && rm -rf "permuter_results/ranking/$REF"
  REF=$(git stash create 2>/dev/null); [ -n "$REF" ] || REF=HEAD
}
ref_ok() { [ "$REF" = HEAD ] || git cat-file -e "$REF^{commit}" 2>/dev/null; }
new_ref
echo "=== $(date) jobs=$JOBS seconds=$SECS ref=$REF queue=$(wc -l < permuter_results/queue.txt)"
while read -r fn; do
  [ -z "$fn" ] && continue
  grep -qxF -- "$fn" permuter_results/queue.txt || { echo "=== $fn: no longer queued, skipped"; continue; }
  ref_ok || { new_ref; echo "=== new ref $REF (a push removed the old one)"; }
  echo "=== $fn $(date)"
  python3 -I tools/run_permuter.py --function "$fn" --jobs "$JOBS" --seconds "$SECS" --draft-ref "$REF" && continue
  # a push during the ranking removes the ref under it: once more with a new one
  ref_ok || { new_ref; echo "=== new ref $REF, $fn again"
              python3 -I tools/run_permuter.py --function "$fn" --jobs "$JOBS" --seconds "$SECS" --draft-ref "$REF"; }
done < permuter_results/queue.txt
[ "$REF" = HEAD ] || rm -rf "permuter_results/ranking/$REF"   # the compiled snapshot of the last ref
echo "=== queue done $(date)"
