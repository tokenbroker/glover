#!/usr/bin/env python3
"""Call decompdecomp's MCP tools over HTTP, with an identity of your own.

    python3 -I tools/fable/dd.py [--as NAME] TOOL [key=value ...] [--json '{"k": "v"}']
    python3 -I tools/fable/dd.py --as opus-1 claim_function function=func_8012643C
    python3 -I tools/fable/dd.py --as opus-1 compile_and_diff function=func_8012643C source=@draft.c
    python3 -I tools/fable/dd.py tools            # list the tool names

The app's URL and secret come from `decomp url`. The first call under a name mints a token through
/api/agents/token and keeps it in ~/Decomp/.decomp/fable-tokens.json (mode 0600); later calls reuse it, so each
name is one agent in the app with its own claims. `value=@path` reads the value from a file. Output is the tool's
text; a tool error exits 1.
"""
import argparse
import json
import os
import subprocess
import sys
import urllib.error
import urllib.request

TOKENS = os.path.expanduser("~/Decomp/.decomp/fable-tokens.json")


def app():
    """The running app's base URL, host and secret: from ~/Decomp/.decomp/server.json (1.0.4+), else `decomp url`."""
    state = os.path.expanduser("~/Decomp/.decomp/server.json")
    try:
        info = json.load(open(state))
        if info.get("port") and info.get("secret"):
            base = f"http://127.0.0.1:{info['port']}"
            return base, base.split("//")[1], info["secret"]
    except (OSError, ValueError):
        pass
    url = subprocess.check_output([os.path.expanduser("~/.local/bin/decomp"), "url"], text=True).strip()
    key = url.split("k=")[1]
    base = url.split("/?")[0]
    return base, base.split("//")[1], key


def ui_headers(host, key):
    """What the app's own window sends (1.0.4) plus the 1.0.2 cookie, so both versions answer."""
    return {"User-Agent": "decompdecomp-window/" + key, "Cookie": "decomp_live=" + key, "x-decomp": "1", "Host": host,
            "Content-Type": "application/json"}


def token_for(name, base, host, key, project=None):
    """The agent's token, bound to the project for this app run. 1.0.4 keeps the binding in memory, so every
    process registers again (cheap); a token the app still knows is kept, else a new one is minted and saved."""
    try:
        saved = json.load(open(TOKENS))
    except (OSError, ValueError):
        saved = {}
    have = saved.get(name, {}).get("token") or ""
    req = urllib.request.Request(base + "/api/agents/token",
                                 data=json.dumps({"name": name, "project": project or PROJECT, "token": have}).encode(),
                                 headers=ui_headers(host, key), method="POST")
    d = json.loads(urllib.request.urlopen(req, timeout=60).read())
    if d["token"] != have:
        saved[name] = {"base": base, "token": d["token"], "mcp": d["url"], "agent": d["agent"]}
        fd = os.open(TOKENS, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
        with os.fdopen(fd, "w") as f:
            json.dump(saved, f)
    return d["token"], d["url"]


PROJECT = os.environ.get("DD_PROJECT", "glover")


class Session:
    def __init__(self, name):
        base, host, key = app()
        self.name, self.base, self.host, self.key = name, base, host, key
        self.token, self.mcp = token_for(name, base, host, key)
        self.sid, self.n = None, 0
        self.rpc("initialize", {"protocolVersion": "2025-03-26", "capabilities": {},
                                "clientInfo": {"name": "fable-dd", "version": "1"}})
        self.notify("notifications/initialized")

    def remint(self):
        """Only when the app says the token is invalid (a fresh database): a new identity, name_N."""
        saved = json.load(open(TOKENS)) if os.path.exists(TOKENS) else {}
        saved.pop(self.name, None)
        with open(TOKENS, "w") as f:
            json.dump(saved, f)
        self.token, self.mcp = token_for(self.name, self.base, self.host, self.key)
        self.sid, self.n = None, 0
        self.rpc("initialize", {"protocolVersion": "2025-03-26", "capabilities": {},
                                "clientInfo": {"name": "fable-dd", "version": "1"}})
        self.notify("notifications/initialized")

    def _post(self, body):
        h = {"Authorization": "Bearer " + self.token, "Host": self.host, "Content-Type": "application/json",
             "Accept": "application/json, text/event-stream"}
        if self.sid:
            h["mcp-session-id"] = self.sid
        r = urllib.request.urlopen(urllib.request.Request(self.mcp, data=json.dumps(body).encode(), headers=h,
                                                          method="POST"), timeout=1800)
        self.sid = r.headers.get("mcp-session-id") or self.sid
        raw = r.read().decode(errors="replace")
        if "data:" in raw:
            return [json.loads(ln[5:]) for ln in raw.splitlines() if ln.startswith("data:")]
        return [json.loads(raw)] if raw.strip() else []

    def notify(self, method):
        self._post({"jsonrpc": "2.0", "method": method})

    def rpc(self, method, params):
        self.n += 1
        out = self._post({"jsonrpc": "2.0", "id": self.n, "method": method, "params": params})
        for m in out:
            if m.get("id") == self.n:
                if "error" in m:
                    raise RuntimeError(m["error"])
                return m["result"]
        return out[-1].get("result") if out else None

    def call(self, tool, args):
        res = self.rpc("tools/call", {"name": tool, "arguments": args})
        text0 = "".join(c.get("text", "") for c in res.get("content", []) if c.get("type") == "text")
        if res.get("isError") and "invalid API token" in text0:
            self.remint()
            res = self.rpc("tools/call", {"name": tool, "arguments": args})
        text = "\n".join(c.get("text", "") for c in res.get("content", []) if c.get("type") == "text")
        return res.get("isError", False), text


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--as", dest="name", default=os.environ.get("DD_AS", "fable"))
    ap.add_argument("tool")
    ap.add_argument("pairs", nargs="*")
    ap.add_argument("--json", default=None)
    a = ap.parse_args()
    args = json.loads(a.json) if a.json else {}
    for p in a.pairs:
        k, _, v = p.partition("=")
        if v.startswith("@"):
            v = open(v[1:]).read()
        elif v.isdigit():
            v = int(v)
        args[k] = v
    s = Session(a.name)
    if a.tool == "tools":
        print("\n".join(t["name"] for t in s.rpc("tools/list", {})["tools"]))
        return 0
    err, text = s.call(a.tool, args)
    print(text)
    return 1 if err else 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except urllib.error.HTTPError as e:
        print("HTTP", e.code, e.read()[:300].decode(errors="replace"), file=sys.stderr)
        sys.exit(2)
