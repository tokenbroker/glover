#!/usr/bin/env bash
# (Re)start the UI relay (tools/fable/ui_relay.py) and print the link a Windows browser can open.
cd "$(dirname -- "${BASH_SOURCE[0]}")/../.."
for p in $(pgrep -f "[u]i_relay[.]py"); do kill "$p" 2>/dev/null; done
sleep 1
setsid nohup python3 tools/fable/ui_relay.py > /dev/null 2>&1 < /dev/null &
sleep 1
key=$(python3 -c "import json,os; print(json.load(open(os.path.expanduser('~/Decomp/.decomp/server.json')))['secret'])")
echo "relay: $(pgrep -fc "[u]i_relay[.]py") process(es)"
echo "link: http://$(hostname -I | cut -d' ' -f1):6465/?k=$key"
