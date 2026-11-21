"""Compare two assemblers on every KMC GCC unit of the project: compile each unit to .s once, assemble it with both,
and judge the results with objdiff-cli (the project's own judge) against expected/. Prints per-unit matched counts
old -> new and the functions gained, lost and moved, game and library units alike (since 2026-11-20 a game unit may
change where a draft uses float literals; the gate is that no function is lost).
Exit code 1 when anything was lost. Usage: tools/fable/as_verify.py <old as> <new as>"""
import re, subprocess, sys, os, json, shutil
G = os.path.expanduser("~/Decomp/glover"); OUT = os.path.expanduser("~/Decomp/.decomp/tc-scratch")
OBJDIFF = os.path.expanduser("~/.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli")
OLD_AS, NEW_AS = os.path.abspath(sys.argv[1]), os.path.abspath(sys.argv[2])
os.makedirs(OUT, exist_ok=True)
cfg = json.load(open(f"{G}/objdiff.json"))

def sh(cmd):
    return subprocess.run(cmd, shell=isinstance(cmd, str), capture_output=True, text=True, cwd=G)

def compile_cmd(unit):
    r = sh(f"make -n -B RUN_CC_CHECK=0 build/{unit}.o")
    for line in r.stdout.splitlines():
        if "gcc_2.7.2/linux/gcc" in line and f"{unit}.c" in line:
            return line
    return None

def as_args(cmd):
    """What the driver passes to `as`, read off gcc -v; minus its own input and output."""
    r = sh(cmd.replace("linux/gcc ", "linux/gcc -v ", 1))
    for line in (r.stderr + r.stdout).splitlines():
        toks = line.split()
        if toks and (toks[0].endswith("/as") or toks[0] == "as"):
            out, skip = [], False
            for t in toks[1:]:
                if skip: skip = False; continue
                if t == "-o": skip = True; continue
                if t.endswith(".s") or t.startswith("/tmp/"): continue
                out.append(t)
            return out
    raise SystemExit(f"no `as` line in gcc -v output for: {cmd[:120]}\n{r.stderr[-600:]}")

units = []   # (unit name like src/18020_C8EB0, is_lib)
for u in cfg["units"]:
    name = u["name"]; src = (u.get("metadata") or {}).get("source_path", "")
    if not src.endswith(".c") or name.endswith("18020_C0800"):   # IDO unit: not our assembler
        continue
    units.append((name, "fp-move-nops" in ((u.get("scratch") or {}).get("c_flags", ""))))

# 1. compile every unit to .s once, remember the driver's as arguments
plan = {}
for name, is_lib in units:
    cmd = compile_cmd(name)
    if cmd is None: print(f"skip {name}: no gcc command"); continue
    s_path = f"{OUT}/{name.replace('/', '_')}.s"
    r = sh(re.sub(r"-o\s+\S+\.o\b", f"-S -o {s_path}", cmd))
    if not os.path.exists(s_path): raise SystemExit(f"gcc -S failed for {name}: {r.stderr[-500:]}")
    plan[name] = (s_path, as_args(cmd), is_lib)
print(f"{len(plan)} units compiled to .s ({sum(1 for v in plan.values() if v[2])} libultra pieces)")

# 2. assemble with each assembler into its own tree and let objdiff judge the tree
reports = {}
for tag, exe in (("old", OLD_AS), ("new", NEW_AS)):
    root = f"{OUT}/{tag}"; shutil.rmtree(root, ignore_errors=True); os.makedirs(f"{root}/src", exist_ok=True)
    for name, (s_path, args, is_lib) in plan.items():
        r = subprocess.run([exe, *args, "-o", f"{root}/{name}.o", s_path], capture_output=True, text=True, cwd=G)
        if r.returncode != 0: raise SystemExit(f"{tag} assembler failed on {name}: {r.stderr[-600:]}")
    c = json.loads(json.dumps(cfg)); c.pop("custom_make", None); c.pop("custom_args", None); c["build_base"] = False; c["build_target"] = False
    for u in c["units"]:
        u["target_path"] = f"{G}/{u['target_path']}"
        u["base_path"] = f"{root}/{u['name']}.o" if u["name"] in plan else f"{G}/{u['base_path']}"
    json.dump(c, open(f"{root}/objdiff.json", "w"))
    r = subprocess.run([OBJDIFF, "report", "generate", "-p", root, "-o", f"{root}/report.json"], capture_output=True, text=True)
    if r.returncode != 0: raise SystemExit(f"objdiff report failed ({tag}): {r.stderr[-600:]}")
    rep = json.load(open(f"{root}/report.json"))
    reports[tag] = {u["name"]: {f["name"]: f.get("fuzzy_match_percent", 0.0) for f in u["functions"]} for u in rep["units"]}
    print(f"{tag}: objdiff matched_functions = {rep['measures']['matched_functions']} of {rep['measures']['total_functions']}")

# 3. compare
loss = False; gained_total = []
for name, (s_path, args, is_lib) in plan.items():
    same = open(f"{OUT}/old/{name}.o", "rb").read() == open(f"{OUT}/new/{name}.o", "rb").read()
    old, new = reports["old"][name], reports["new"][name]
    gained = sorted(f for f in old if old[f] < 100 <= new.get(f, 0))
    lost = sorted(f for f in old if old[f] >= 100 > new.get(f, 0))
    moved = {f: (round(old[f], 2), round(new[f], 2)) for f in old if f not in gained and f not in lost and abs(old[f] - new.get(f, 0)) > 0.001}
    print(f"{'lib ' if is_lib else 'game'}  {name:18} matched {sum(v >= 100 for v in old.values())} -> {sum(v >= 100 for v in new.values())} of {len(old)}"
          f"{'  (unchanged bytes)' if same else ''}; gained {gained}; lost {lost}; moved {moved}")
    gained_total += gained
    if lost: loss = True
print("RESULT:", "LOSS" if loss else "OK", "| gained", len(gained_total), gained_total)
sys.exit(1 if loss else 0)
