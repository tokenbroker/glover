#!/usr/bin/env python3
"""Verify today's off-tree decomp-permuter outputs against a HEAD copy of their unit and submit, under the `fable`
identity, every variant that beats the app's best attempt (a byte-identical one becomes a match through the app's
own try). Safe to run repeatedly: an output already at or below the app's best is skipped.
    python3 -I tools/fable/perm_submit.py [YYYYMMDD]"""
import glob, json, os, re, sqlite3, subprocess, sys, tempfile, time

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
sys.path.insert(0, "tools")
import run_permuter as rp  # noqa: E402

# Which runs to look at: a day given as YYYYMMDD, else every run directory written in the last 3 days (the server's
# clock is 5 hours ahead, so its directories can carry tomorrow's date: never select by the date in the name).
day = sys.argv[1] if len(sys.argv) > 1 else None
RECENT = time.time() - 3 * 86400
S = tempfile.mkdtemp(prefix="perm_submit_")
heads, texts = {}, {}
for u in json.load(open("objdiff.json"))["units"]:
    sp = u.get("metadata", {}).get("source_path")
    if sp and sp.startswith("src/") and sp.endswith(".c"):
        unit = sp[4:-2]
        heads[unit] = os.path.join(S, f"head_{unit}.c")
        texts[unit] = subprocess.check_output(["git", "show", f"HEAD:{sp}"], text=True)
        open(heads[unit], "w").write(texts[unit])
c = sqlite3.connect("file:" + os.path.expanduser("~/Decomp/.decomp/decomp.db") + "?mode=ro", uri=True)
DD = ["python3", "-I", "tools/fable/dd.py", "--as", "permuter-server"]  # the server batch's results, not a Claude agent


def app_pct(fn):
    r = c.execute("SELECT n_insns, best_score, status FROM functions WHERE name=?", (fn,)).fetchone()
    return ((100 - 100 * r[1] / (r[0] * 100)) if r and r[1] is not None else None), (r[2] if r else None)


done = []
for d in sorted(glob.glob(f"permuter_results/func_*/{day}-*" if day else "permuter_results/func_*/2*-*")):
    if not day and os.path.getmtime(d) < RECENT:
        continue
    fn = d.split("/")[1]
    outs = sorted(glob.glob(d + "/output-*"))
    if not outs:
        continue
    pct, status = app_pct(fn)
    if status == "matched" or pct is None:
        continue
    unit = next((u for u, t in texts.items() if fn in rp.definitions(t) or re.search(r'INCLUDE_ASM\("[^"]*",\s*' + fn + r"\);", t)), None)
    if unit is None:
        continue
    best = (pct, None)
    for o in outs:
        for f in ([o] if os.path.isfile(o) else glob.glob(o + "/*.c")):
            t = open(f).read()
            defs = rp.definitions(t)
            if fn not in defs:
                continue
            s, b, e = defs[fn]
            draft = os.path.join(S, f"{fn}_{os.path.basename(o)}.c")
            open(draft, "w").write(t[s:e] + "\n")
            r = subprocess.run(["bash", "tools/fable/score.sh", draft], capture_output=True, text=True,
                               env=dict(os.environ, FN=fn, UNIT=unit, SCRATCH=os.path.join(S, "s_" + fn), SRC=heads[unit]))
            m = re.search(r"match ([0-9.]+) %", r.stdout + r.stderr)
            if m and float(m.group(1)) > best[0] + 0.005:
                best = (float(m.group(1)), draft)
    if best[1]:
        # the app's permuter or a helper may hold the function: wait for it to be free (a permuter turn is <= 4 min)
        for _ in range(24):
            holder = c.execute("SELECT a.name FROM claims c2 JOIN agents a ON a.id=c2.agent_id JOIN functions f ON f.id=c2.function_id "
                               "WHERE f.name=? AND a.name!='fable'", (fn,)).fetchone()
            if not holder:
                break
            print(time.strftime("%H:%M"), fn, "is claimed by", holder[0], "- waiting", flush=True)
            time.sleep(15)
        subprocess.run(DD + ["claim_function", f"function={fn}"], capture_output=True, text=True)
        out = subprocess.run(DD + ["compile_and_diff", f"function={fn}", f"source=@{best[1]}"], capture_output=True, text=True).stdout
        if "Error executing tool" in out or "claimed by" in out:
            print(time.strftime("%H:%M"), fn, "not submitted:", out.strip().splitlines()[0][:120] if out.strip() else "no answer", flush=True)
            continue
        rel = subprocess.run(DD + ["release_function", f"function={fn}", "notes=Fable's perm_submit: an off-tree decomp-permuter "
                             f"variant ({best[0]:.2f}% locally) submitted as the best attempt; register spelling only."],
                       capture_output=True, text=True)
        if "Released" not in (rel.stdout or ""):
            print(time.strftime("%H:%M"), fn, "release:", ((rel.stdout or "") + (rel.stderr or "")).strip()[:120] or "no answer", flush=True)
        print(time.strftime("%H:%M"), fn, f"{pct:.2f} -> {best[0]:.2f}%:", (out.splitlines() or ["?"])[0][:90], flush=True)
        done.append(fn)
print(time.strftime("%H:%M"), "submitted:", done, flush=True)
