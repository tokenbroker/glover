#!/usr/bin/env bash
# Push this repo's live tree, the objdiff-cli binary and the near-miss queue to the server (rsync over ssh).
# usage: tools/fable/remote_push.sh [--no-export] user@host [remote-dir]      (remote-dir default: ~/glover)
#   --no-export: push permuter_results/queue.txt and best/ as they are (permute_cycle.sh has just exported them)
set -eu
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
EXPORT=1; [ "${1:-}" = --no-export ] && { EXPORT=0; shift; }
HOST=$1; DIR=${2:-glover}
mkdir -p permuter_results
[ "$EXPORT" = 0 ] || python3 -I tools/fable/export_queue.py
ssh "$HOST" "mkdir -p $DIR ~/.local/share/decompnet/toolchains/objdiff-cli"
# --delete keeps the server's own files: its batch logs, the assembler's temp files of a compile in flight, its results
rsync -az --delete --exclude /build/ --exclude '/remote_permute*.log' --exclude '/astemp_*' \
      --exclude 'permuter_results/func_*' --exclude 'permuter_results/ranking' --exclude tools/decomp-permuter/ --exclude tools/.permuter-venv/ \
      ./ "$HOST:$DIR/"
rsync -az "$HOME/.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli" "$HOST:.local/share/decompnet/toolchains/objdiff-cli/"
echo "pushed to $HOST:$DIR; on the server run: cd $DIR && nohup tools/fable/remote_permute.sh 24 900 > remote_permute.log 2>&1 &"
