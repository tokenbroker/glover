#!/usr/bin/env bash
# Pull the server's permuter results every N minutes and submit every improvement through the app.
# usage: nohup tools/fable/remote_pull_loop.sh user@host [minutes (default 15)] [remote-dir] > permuter_results/remote_pull.log 2>&1 &
set -u
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
HOST=$1; MIN=${2:-15}; DIR=${3:-glover}
while true; do
  echo "=== $(date '+%F %T') pull from $HOST"
  tools/fable/remote_pull.sh "$HOST" "$DIR" 2>&1 | tail -8
  sleep $((MIN * 60))
done
