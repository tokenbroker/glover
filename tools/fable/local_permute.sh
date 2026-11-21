#!/usr/bin/env bash
# The off-tree permuter batch for THIS machine, the counterpart of remote_permute.sh (the server walks the queue top
# down, this walks it bottom up). It skips a function that already has a run directory written today by either
# machine (pulled ones keep the server's mtime; their names carry the server's UTC date, so the name is no guide)
# and one that has left the queue since the batch started (export_queue.py drops matched functions and drafts that
# have had their runs). Runs under nice; logs to permuter_results/local_permute.log.
# usage: tools/fable/local_permute.sh [jobs (default 8)] [seconds per function (default 600)]
#   QUEUE=<file> (default permuter_results/queue.txt), LOG=<file> (default permuter_results/local_permute.log)
set -u
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
JOBS=${1:-8}; SECS=${2:-600}
QUEUE=${QUEUE:-permuter_results/queue.txt}; LOG=${LOG:-permuter_results/local_permute.log}
exec >> "$LOG" 2>&1
exec 9> permuter_results/.local_permute.lock
flock -n 9 || { echo "=== $(date '+%F %T') another local batch holds the lock, not started"; exit 0; }
[ -x tools/.permuter-venv/bin/python ] || python3 -I tools/run_permuter.py --setup || exit 1
mapfile -t FNS < <(tac "$QUEUE")
echo "=== $(date '+%F %T') local batch: jobs=$JOBS seconds=$SECS queue=${#FNS[@]} ($QUEUE, bottom up)"
REF=; STASHED=
# the snapshot that run_permuter.py compiled for this batch's ref (permuter_results/ranking/<ref>, 5-15 MB)
trap '[ -n "$STASHED" ] && rm -rf "permuter_results/ranking/$STASHED"' EXIT
ran_today() {
  [ -n "$(find "permuter_results/$1" -mindepth 1 -maxdepth 1 -type d -newermt "$(date +%F) 00:00" -print -quit 2>/dev/null)" ]
}
for fn in "${FNS[@]}"; do
  [ -z "$fn" ] && continue
  grep -qxF -- "$fn" "$QUEUE" || { echo "=== $fn: no longer queued, skipped"; continue; }
  ran_today "$fn" && { echo "=== $fn: already ran today, skipped"; continue; }
  if [ -z "$REF" ]; then
    # --draft-ref: the live tree's drafts as a commit, made with a private copy of the index so that the app's own
    # git commands in this tree never meet our index.lock
    tmp=$(mktemp -d permuter_results/.index.XXXXXX); cp "$(git rev-parse --git-path index)" "$tmp/index" 2>/dev/null
    REF=$(GIT_INDEX_FILE="$tmp/index" git stash create 2>/dev/null); rm -rf "$tmp"
    if [ -n "$REF" ]; then STASHED=$REF; else REF=$(git rev-parse HEAD); fi
    echo "=== ref $REF"
  fi
  echo "=== $fn $(date '+%F %T')"
  nice -n 15 python3 -I tools/run_permuter.py --function "$fn" --jobs "$JOBS" --seconds "$SECS" --draft-ref "$REF" 2>&1 \
    | grep --line-buffered -vE ': (warning|note): |: In function |: At top level:|^ *[0-9]* \|( |$)'
done
echo "=== queue done $(date '+%F %T')"
