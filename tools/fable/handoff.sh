#!/usr/bin/env bash
# Hand a priority function from one helper to an Opus max helper once the first one stops working on it.
# usage: setsid nohup tools/fable/handoff.sh FUNCTION HELPER_ID > permuter_results/handoff_FUNCTION.log 2>&1 &
# Every 5 minutes: exit when the function is matched; when helper HELPER_ID has not been `working` for two
# checks in a row (quota exhausted, stopped, crashed), start one claude helper with model opus, effort max
# (the function is on the priority list, so it takes it), and exit.
set -u
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
FN=$1; HID=$2; idle=0
state() { python3 -I - "$FN" "$HID" <<'PY'
import sqlite3, os, sys
fn, hid = sys.argv[1], int(sys.argv[2])
c = sqlite3.connect('file:' + os.path.expanduser('~/Decomp/.decomp/decomp.db') + '?mode=ro', uri=True, timeout=30)
st = c.execute("select status, n_insns, best_score from functions where name=?", (fn,)).fetchone()
hs = c.execute("select state from helpers where id=?", (hid,)).fetchone()
print(st[0], "%.2f" % (100 - st[2] / st[1]), hs[0] if hs else "gone")
PY
}
while true; do
  read -r fstatus pct hstate < <(state)
  echo "$(date '+%F %T') $FN $fstatus $pct% helper $HID: $hstate"
  [ "$fstatus" = matched ] && { echo "matched: done"; exit 0; }
  if [ "$hstate" = working ] || [ "$hstate" = starting ]; then idle=0; else idle=$((idle + 1)); fi
  if [ "$idle" -ge 2 ]; then
    python3 -I - <<'PY'
import json, os, urllib.request
info = json.load(open(os.path.expanduser('~/Decomp/.decomp/server.json'))); base = f"http://127.0.0.1:{info['port']}"; key = info['secret']
h = {"User-Agent": "decompdecomp-window/" + key, "Cookie": "decomp_live=" + key, "x-decomp": "1", "Content-Type": "application/json"}
r = urllib.request.urlopen(urllib.request.Request(base + "/api/agents/start", data=json.dumps({"kind": "claude", "slug": "glover", "count": 1, "options": {"model": "opus", "per_session": 2, "effort": "max"}}).encode(), headers=h, method="POST"), timeout=120)
print("started opus max:", r.status, r.read()[:100])
PY
    exit 0
  fi
  sleep 300
done
