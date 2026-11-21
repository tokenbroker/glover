#!/usr/bin/env bash
# Cron wrapper for the hourly editor pass. Installed as:
#   7 * * * * $HOME/Decomp/glover/tools/editor_pass.sh
# Cron's environment is bare, so set what claude, git and python need.
export HOME="${HOME:-$(getent passwd "$(id -u)" | cut -d: -f6)}"
export PATH="$HOME/.local/bin:/usr/local/bin:/usr/bin:/bin"
cd "$(dirname -- "${BASH_SOURCE[0]}")/.." || exit 1
exec timeout 2700 python3 -I tools/editor_pass.py "$@" >> "$HOME/Decomp/.decomp/glover-editor/cron.out" 2>&1
