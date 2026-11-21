#!/usr/bin/env bash
# Pull the server's permuter results and submit every improvement through the app (tools/fable/perm_submit.py).
# usage: tools/fable/remote_pull.sh user@host [remote-dir]
set -eu
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
HOST=$1; DIR=${2:-glover}
rsync -az "$HOST:$DIR/permuter_results/" permuter_results/ --include 'func_*/***' --include 'drafts/***' --exclude '*'
ssh "$HOST" "tail -3 $DIR/remote_permute.log 2>/dev/null" || true
# perm_submit.py looks at every run of the last 3 days (the server clock is ahead of ours)

python3 -I tools/fable/perm_submit.py 2>&1 | grep -vE 'warning' | tail -5
