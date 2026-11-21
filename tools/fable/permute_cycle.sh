#!/usr/bin/env bash
# The hourly permute-and-refine cycle, meant to run in the background (it replaces remote_pull_loop.sh). Each cycle:
#   (a) pulls the server's results and submits every improvement through the app (remote_pull.sh -> perm_submit.py;
#       perm_submit.py alone for this machine's results when the server cannot be reached)
#   (b) re-exports the queue and drafts from the app's database (export_queue.py: near misses whose current draft has
#       had fewer than two runs) and pushes them to the server (remote_push.sh --no-export)
#   (c) starts the server batch (remote_permute.sh) when it is not running, (d) the same for this machine's batch
#       (local_permute.sh), (e) appends one status line to permuter_results/cycle.log, then sleeps out the hour.
# Every step tolerates failure: a dead link only skips that cycle's remote steps.
# usage: setsid nohup tools/fable/permute_cycle.sh host [minutes (default 60)] \
#            > permuter_results/permute_cycle.out 2>&1 &
#   env: SERVER_JOBS SERVER_SECONDS (24 900), LOCAL_JOBS LOCAL_SECONDS (8 600), REMOTE_DIR (glover),
#        QUEUE_DISTANCE QUEUE_INSNS QUEUE_RUNS (6 3000 2): how wide the queue is; LOCAL_JOBS=0 runs no batch on this machine;
#        SUBMIT=0 pulls results but submits nothing (no fable activity in the app)
#   stop: pkill -f "[p]ermute_cycle[.]sh"   (the batches it started keep running until their queue is done)
set -u
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
HOST=${1:?usage: permute_cycle.sh host [minutes]}; MIN=${2:-60}; DIR=${REMOTE_DIR:-glover}
SJOBS=${SERVER_JOBS:-24}; SSECS=${SERVER_SECONDS:-900}; LJOBS=${LOCAL_JOBS:-8}; LSECS=${LOCAL_SECONDS:-600}
QDIST=${QUEUE_DISTANCE:-6}; QINSNS=${QUEUE_INSNS:-3000}; QRUNS=${QUEUE_RUNS:-2}   # export_queue.py: near-miss distance %, max instructions, runs per draft
SSH=(ssh -o ConnectTimeout=20 -o BatchMode=yes -o ServerAliveInterval=15 -o ServerAliveCountMax=4)
export RSYNC_RSH="${SSH[*]}"   # the rsyncs in remote_pull.sh / remote_push.sh give up on a dead link instead of hanging
exec 9> permuter_results/.permute_cycle.lock
flock -n 9 || { echo "another permute_cycle.sh holds permuter_results/.permute_cycle.lock"; exit 1; }
remote() { timeout -k 10 120 "${SSH[@]}" "$HOST" "$@" 9>&-; }   # 9>&-: children must not inherit the lock
db_counts() {
  python3 -I - <<'PY' 2>/dev/null || echo "matched=? open=?"
import os, sqlite3
c = sqlite3.connect('file:' + os.path.expanduser('~/Decomp/.decomp/decomp.db') + '?mode=ro', uri=True, timeout=30)
pid = c.execute("select id from projects where slug='glover'").fetchone()[0]
n = dict(c.execute("select status, count(*) from functions where project_id=? group by status", (pid,)).fetchall())
print(f"matched={n.get('matched', 0)} open={n.get('open', 0)}")
PY
}
SUBMIT_LINE='^[0-9]{2}:[0-9]{2} submitted: '
while true; do
  t0=$(date +%s)
  echo "=== $(date '+%F %T') cycle"
  # (a) pull + verify + submit (SUBMIT=0: pull only; nothing acts in the app under the fable identity)
  if [ "${SUBMIT:-1}" = 0 ]; then
    if remote true; then
      timeout -k 60 3600 rsync -az "$HOST:$DIR/permuter_results/" permuter_results/ --include 'func_*/***' --exclude '*' 9>&- \
        && pull="pulled, submission off (SUBMIT=0)" || pull="pull failed, submission off (SUBMIT=0)"
    else
      pull="$HOST unreachable, submission off (SUBMIT=0)"
    fi
  elif remote true; then
    pull=$(timeout -k 60 7200 tools/fable/remote_pull.sh "$HOST" "$DIR" 2>&1 9>&-) || pull+=$'\n'"remote_pull.sh failed"
  else
    pull="$HOST unreachable"
  fi
  if [ "${SUBMIT:-1}" != 0 ] && ! printf '%s\n' "$pull" | grep -qE "$SUBMIT_LINE"; then
    pull+=$'\n'"submitting this machine's results only"$'\n'$(timeout -k 60 7200 python3 -I tools/fable/perm_submit.py 2>&1 | grep -v warning | tail -5)
  fi
  printf '%s\n' "$pull" | tail -12
  submitted=$(printf '%s\n' "$pull" | grep -E "$SUBMIT_LINE" | grep -oE 'func_[0-9A-Fa-f]+' | sort -u | wc -l)
  # (b) new queue and drafts, pushed with the tree
  timeout -k 10 600 python3 -I tools/fable/export_queue.py "$QDIST" "$QINSNS" "$QRUNS" 2>&1 9>&- | tail -3
  timeout -k 30 1800 tools/fable/remote_push.sh --no-export "$HOST" "$DIR" 2>&1 9>&- | tail -3
  # (c) the server batch (exit 1 = pgrep found none; anything else is a failed ssh)
  remote 'pgrep -f "[r]emote_permute[.]sh" >/dev/null'
  case $? in
    0) server=running ;;
    1) if remote "cd $DIR && { [ ! -f remote_permute.log ] || mv -f remote_permute.log remote_permute.prev.log; } && { nohup tools/fable/remote_permute.sh $SJOBS $SSECS > remote_permute.log 2>&1 < /dev/null & }"
       then server=started; else server=start-failed; fi ;;
    *) server=unreachable ;;
  esac
  # (d) this machine's batch
  if [ "$LJOBS" -le 0 ]; then here=off   # LOCAL_JOBS=0: the user wants no batch on this machine
  elif pgrep -f "[l]ocal_permute[.]sh" >/dev/null; then here=running
  else setsid nohup tools/fable/local_permute.sh "$LJOBS" "$LSECS" > /dev/null 2>&1 < /dev/null 9>&- & here=started; fi
  # (e) status line
  load=$(remote 'cut -d" " -f1-3 /proc/loadavg' 2>/dev/null) && [ -n "$load" ] || load='?'
  queue=$(wc -l < permuter_results/queue.txt 2>/dev/null) || queue='?'
  line="$(date '+%F %T') $(db_counts) queue=$queue submitted=$submitted server_load=${load// //} server=$server local=$here"
  echo "$line" >> permuter_results/cycle.log
  echo "$line"
  left=$(( MIN * 60 - ($(date +%s) - t0) ))
  sleep $(( left > 300 ? left : 300 )) 9>&-
done
