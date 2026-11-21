#!/usr/bin/env python3
"""Hourly editor pass for the Glover decomp (run by cron through tools/editor_pass.sh).

Agents write two kinds of project-wide notes: compiler lessons worth keeping, and housekeeping
("the list is stale, X is already matched"). New sessions only ever see the newest ~2,500
characters of notes, so housekeeping crowds the lessons out within hours. This pass:

  1. does nothing unless agents produced events, compiles or notes since the last pass (gate);
  2. regenerates docs/permuter-queue.md and docs/untouched-functions.md from the app database;
  3. moves new lesson notes into docs/notes-digest.md and deletes housekeeping notes that the
     regenerated lists have answered (every deleted note is archived first);
  4. asks a headless Claude to promote generalisable lessons into the "Lessons from agents"
     section of AGENTS.md, and reverts anything it touches outside that section;
  5. commits only the docs files it owns, never src/ or include/.

State and logs live under ~/Decomp/.decomp/glover-editor/. `--dry-run` writes nothing,
`--force` skips the activity gate.
"""
from __future__ import annotations

import argparse
import fcntl
import json
import os
import re
import sqlite3
import subprocess
import sys
import time
import urllib.request
import collections
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
HOME = Path(os.environ.get("DECOMP_HOME", Path.home() / "Decomp"))
DB = HOME / ".decomp" / "decomp.db"
STATE_DIR = HOME / ".decomp" / "glover-editor"
STATE = STATE_DIR / "state.json"
ARCHIVE = STATE_DIR / "deleted-notes.jsonl"
LOCK = STATE_DIR / "lock"
SLUG = "glover"
STATIC = json.loads((ROOT / "tools" / "editor_static_lists.json").read_text())

LIBRARY_UNIT = "src/18020_C5030"   # libultra: ported from ultralib, listed in its own table
# ... with the C pieces cut from it (2026-10-29: the libgcc tail at -g2, and the C between the hand-written routines,
# which became assembly segments): every unit 18020_<ROM> from ROM 0xC5030 on
def _is_library(u):
    tail = u.rsplit("_", 1)[-1]
    return u.startswith("src/18020_") and bool(re.fullmatch(r"[0-9A-F]+", tail)) and int(tail, 16) >= 0xC5030
LIBRARY_UNITS = frozenset(u["name"] for u in json.loads((ROOT / "objdiff.json").read_text())["units"] if _is_library(u["name"]))
# Game units: every unit of objdiff.json but the library one (the 19 pieces of the game unit cut at every change of flags
# on 2026-10-21, and src/18020_C0800, IDO-built game code since 2026-10-28), D910 first, then in ROM order.
def _unit_key(u):
    tail = u.rsplit("_", 1)[-1]
    return (0 if u.startswith("src/D910") else 1 if u == "src/18020" else 2, int(tail, 16) if re.fullmatch(r"[0-9A-F]+", tail) else 0)
GAME_UNITS = tuple(sorted((u["name"] for u in json.loads((ROOT / "objdiff.json").read_text())["units"] if u["name"] not in LIBRARY_UNITS), key=_unit_key))
UNIT_ORDER = {u: i for i, u in enumerate(GAME_UNITS)}
LARGE = 2000          # bytes: Fable's table
NEAR_MISS = 90.0      # percent
PERMUTER_ONLY = 40    # compiles
# A housekeeping note names one of the list files AND says it is stale / asks for a move. Anything that
# teaches (gcc, nop, trick, tip, pattern, emits, scheduler ...) is kept even if it also mentions the lists.
HOUSEKEEPING = re.compile(r"(permuter-queue\.md|untouched-functions\.md|near-miss list|blocked (?:list|table))", re.I)
STALE_WORDS = re.compile(r"already matched|is stale|out of date|please (?:move|add)|stale again|lines? \d+-\d+ are", re.I)
TEACHING = re.compile(r"\bgcc|\bgas\b|\bnop\b|trick|\btip\b|pattern|emits|schedul|register|hoist|alias|\$LM|-g2", re.I)
MAX_DELETE = 40       # housekeeping notes deleted per pass
NOTES_EPOCH = "2026-10-16 14:00"  # tools/build/as v3 installed; notes about the earlier assembler walls are obsolete
MAX_DIGEST = 25       # lesson notes digested per pass; the rest wait for the next hour


def is_housekeeping(text: str) -> bool:
    return bool(HOUSEKEEPING.search(text) and STALE_WORDS.search(text) and not TEACHING.search(text) and len(text) < 450)


LESSONS_HEADING = "## Lessons from agents (auto-curated)"
GIT_ID = ["-c", "user.name=Glover editor pass", "-c", "user.email=noreply@anthropic.com"]
TRAILER = ("\n\nCo-Authored-By: Claude Fable 5.1 <noreply@anthropic.com>\n")


def log(msg: str) -> None:
    line = f"{time.strftime('%Y-%m-%d %H:%M:%S')} {msg}"
    print(line, flush=True)
    STATE_DIR.mkdir(parents=True, exist_ok=True)
    with open(STATE_DIR / "editor.log", "a") as f:
        f.write(line + "\n")


def db_ro() -> sqlite3.Connection:
    c = sqlite3.connect(f"file:{DB}?mode=ro", uri=True, timeout=30)
    c.row_factory = sqlite3.Row
    return c


def pct(best_score, n_insns) -> float | None:
    if best_score is None or not n_insns:
        return None
    return max(0.0, 100.0 - best_score / n_insns)


def stubs_present() -> set[str]:
    names = set()
    for f in (ROOT / "src").glob("*.c"):
        names.update(re.findall(r"^INCLUDE_ASM\([^,]+,\s*(func_[0-9A-F]+)\)", f.read_text(errors="replace"), re.M))
    return names


# ------------------------------------------------------------------ lists

def row(fn, with_score=True) -> str:
    cells = [f"`{fn['name']}`", f"`{fn['unit']}.c`", f"{fn['size']}"]
    if with_score:
        p = pct(fn["best_score"], fn["n_insns"])
        cells += [f"{p:.2f}%" if p is not None else "n/a", f"{fn['attempts']}"]
    return "| " + " | ".join(cells) + " |"


def near_table(rows, classes) -> str:
    head = "| Function | File | Size (bytes) | Score | Compiles | Diff |\n|---|---|---:|---:|---:|---|"
    return head + "\n" + "\n".join(row(r)[:-1] + f" {diff_label(classes.get(r['name']))} |" for r in rows) if rows else head + "\n| (none) | | | | | |"


def table(rows, with_score=True) -> str:
    head = ("| Function | File | Size (bytes) | Score | Compiles |\n|---|---|---:|---:|---:|" if with_score
            else "| Function | File | Size (bytes) |\n|---|---|---:|")
    return head + "\n" + "\n".join(row(r, with_score) for r in rows) if rows else head + "\n| (none) | | |"


def sort_key(fn):
    return (UNIT_ORDER.get(fn["unit"], 9), -(pct(fn["best_score"], fn["n_insns"]) or 0), fn["name"])


def regenerate(db, stamp: str, classes: dict | None = None) -> dict:
    classes = classes or {}
    pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
    fns = db.execute("SELECT name, unit, size, status, best_score, n_insns, attempts FROM functions "
                     "WHERE project_id=? AND name LIKE 'func_%'", (pid,)).fetchall()
    byname = {f["name"]: f for f in fns}
    stubs = stubs_present()
    hw = set(STATIC["handwritten"])   # the -O0 and assembler-blocked tables are gone: -O0 functions live in -O0 pieces
    skip = hw                          # since 2026-10-21 and no known nop is the assembler's since 2026-10-20
    game = [f for f in fns if f["unit"] in GAME_UNITS and f["status"] == "open" and f["name"] not in skip]   # set-aside (asm) and nosource rows cannot be claimed
    big = sorted([f for f in game if f["attempts"] and f["size"] >= 4000 and (pct(f["best_score"], f["n_insns"]) or 0) < NEAR_MISS],
                 key=lambda f: -f["size"])
    near = sorted([f for f in game if f["attempts"] and f["attempts"] < PERMUTER_ONLY
                   and (pct(f["best_score"], f["n_insns"]) or 0) >= NEAR_MISS], key=sort_key)
    perm = sorted([f for f in game if f["attempts"] >= PERMUTER_ONLY
                   and (pct(f["best_score"], f["n_insns"]) or 0) >= NEAR_MISS], key=sort_key)
    below = sorted([f for f in game if f["attempts"] and f["size"] < 4000 and (pct(f["best_score"], f["n_insns"]) or 0) < NEAR_MISS],
                   key=sort_key)
    lib = sorted([f for f in fns if f["unit"] in LIBRARY_UNITS and f["status"] == "open" and f["name"] not in skip],
                 key=lambda f: -(pct(f["best_score"], f["n_insns"]) or 0))
    undrafted = [f for f in game if not f["attempts"] and f["name"] in stubs]
    large = sorted([f for f in undrafted if f["size"] >= LARGE], key=lambda f: (UNIT_ORDER[f["unit"]], -f["size"]))
    medium = sorted([f for f in undrafted if f["size"] < LARGE], key=lambda f: (UNIT_ORDER[f["unit"]], -f["size"]))
    hw_rows = sorted([byname[n] for n in hw if n in byname and byname[n]["status"] != "matched"], key=lambda f: f["name"])

    claim_text = ("Claim by name: `claim_function(function=\"func_XXXXXXXX\")`, picking a random line from the first 40. "
                  "If the tool says a line is already matched or hands you a different function instead, release the "
                  "substitute at once (note `substituted`) and pick another line. Work what you claim: start from the "
                  "best attempt, compile, up to about 25 compiles while the score moves, then release with notes. "
                  "A function you have already released this session is not yours to claim again.")
    queue = f"""# Near misses for Claude and Codex

Regenerated {stamp} by the hourly editor pass (`tools/editor_pass.py`) from the decomp.wtf database. Game units only, D910 first, then by score. {claim_text}

## Big drafts in progress: Claude Opus and Sonnet, one at a time

The largest functions, drafted by Fable with `tools/m2c_draft.py` (m2c, cleaned up until the unit compiles) and left with a handoff note. The leg work is yours: read the `[editor]` note and the handoff note on the function, then work the diff from the top one region per compile, with compile_and_diff on the whole function. Budget 40 compiles before releasing; release with a note that says the row where you stopped and what the next region needs. Do not restart from m2c: the draft in the tree is the starting point.

{table(big)}

## Near misses under {PERMUTER_ONLY} compiles

The Diff column is the editor pass's row-by-row read of the current draft with the judge's own settings (struct = instruction count or opcode differs, stack = frame size, branch = target off, nop = hazard nop, imm = constant or offset, reg = registers only, wrongaddr = a relocation resolves to a different address than the target's, which the judge cannot see); each function also carries a `[editor]` note with the detail.

{near_table(near, classes)}

## Permuter only: {PERMUTER_ONLY} or more compiles

Release on sight with the note `permuter queue`. Every spelling tried gives the same one-register diff; the permuter works these in the background.

{table(perm)}

## Drafts below {NEAR_MISS:.0f}%: structure first

Every open game function with a draft that is not a near miss (the largest ones are in the first table). Any model: read the notes, list the rows where a branch target or an instruction count differs, fix the control flow and the struct layout before any register work, and leave a handoff note at about 25 compiles.

{table(below)}

## Library unit `{LIBRARY_UNIT}.c` and its pieces: libultra, port from ultralib

{len(lib)} open functions, built without `-g` with `ldc1`/`sdc1` doubles. Claimable: `docs/library-candidates.md` names the ultralib file to copy from; write the upstream source verbatim with the right struct layout. Hardware registers and KSEG bases are literals (`*(volatile u32 *)0xA4600010`, `x | 0xA0000000`), never `D_A4xxxxxx` symbols.

{table(lib)}
"""
    untouched = f"""# Untouched functions

Regenerated {stamp} by the hourly editor pass (`tools/editor_pass.py`) from the decomp.wtf database: open functions that still have an `INCLUDE_ASM` stub and zero compiles, game units only, D910 first. {claim_text}

## Large, undrafted: Claude Fable only

Structure first: calls, control flow, types, the struct layouts the function implies (add them to include/structs.h as new structs, never by editing fields matched code uses). Stop at 80% or 15 compiles, whichever comes first, and release with a handoff note in this shape: `structure done at NN%; remaining: <what differs>; tried: <forms>; next: <one concrete idea>`. A cheaper model and the permuter take it from there.

{table(large, False)}

## Medium, undrafted: DeepSeek, Gemini, Codex

Same deliverable, same handoff note, up to 25 compiles.

{table(medium, False)}

## Hand-written assembly: do not claim

libultra exception, interrupt and CP0/FPU-control routines assembled by hand (rule 10 in AGENTS.md). Release on sight with the note `handwritten asm`.

{table(hw_rows, False)}
"""
    return {"queue": queue, "untouched": untouched,
            "counts": {"big": len(big), "near": len(near), "permuter": len(perm), "blocked": 0, "below": len(below), "library": len(lib),
                       "large": len(large), "medium": len(medium), "matched": sum(1 for f in fns if f["status"] == "matched")}}


def stale_entries(old_text: str, byname) -> list[str]:
    """Functions listed as claimable in the old list that are matched now."""
    names = re.findall(r"^\| `(func_[0-9A-F]+)`", old_text.split("## Permuter only", 1)[0], re.M)
    return [n for n in names if n in byname and byname[n]["status"] == "matched"]


# ------------------------------------------------------------------ notes

def new_notes(db, last_id: int):
    pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
    return db.execute("SELECT n.id, n.text, n.created_at, a.name AS agent FROM notes n LEFT JOIN agents a ON a.id=n.agent_id "
                      "WHERE n.project_id=? AND n.function_id IS NULL AND n.id>? ORDER BY n.id", (pid, last_id)).fetchall()


def new_knowledge(db, last_id: int):
    """Shared-knowledge proposals (decompdecomp 1.0.2 backports route a function-less add_note here, not to notes):
    proposed or accepted ones, in the digest's note shape. Rejected ones are left out."""
    pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
    try:
        rows = db.execute("SELECT k.id, k.text, k.created_at, k.status, "
                          "(SELECT group_concat(DISTINCT s.model) FROM knowledge_support s WHERE s.knowledge_id=k.id) AS models "
                          "FROM knowledge k WHERE k.project_id=? AND k.id>? AND k.status!='rejected' ORDER BY k.id", (pid, last_id)).fetchall()
    except sqlite3.OperationalError:  # an app without the knowledge table
        return []
    return [{"id": r["id"], "text": r["text"], "created_at": r["created_at"],
             "agent": f"knowledge #{r['id']} ({r['status']}; {r['models'] or 'no model recorded'})"} for r in rows]


def housekeeping_notes(db, days: int = 2):
    pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
    rows = db.execute("SELECT n.id, n.text, n.created_at, a.name AS agent FROM notes n LEFT JOIN agents a ON a.id=n.agent_id "
                      "WHERE n.project_id=? AND n.function_id IS NULL AND n.created_at>? ORDER BY n.id",
                      (pid, time.time() - days * 86400)).fetchall()
    return [r for r in rows if is_housekeeping(r["text"])][:MAX_DELETE]


def delete_notes(ids: list[int]) -> None:
    c = sqlite3.connect(str(DB), timeout=30)
    try:
        c.executemany("DELETE FROM notes WHERE id=?", [(i,) for i in ids])
        c.commit()
    finally:
        c.close()


def digest_append(entries, stamp: str) -> str:
    path = ROOT / "docs" / "notes-digest.md"
    text = path.read_text() if path.exists() else (
        "# Agent notes digest\n\nProject-wide notes agents left in decomp.wtf, copied here by the hourly editor pass "
        "(`tools/editor_pass.py`) so they outlive the 2,500-character window new sessions see. A headless Claude promotes "
        "the generalisable ones into the \"Lessons from agents\" section of AGENTS.md and marks the batch reviewed.\n")
    block = [f"\n## {stamp} (unreviewed)\n"]
    for e in entries:
        block.append(f"- **{e['agent'] or 'agent'}**: {' '.join(e['text'].split())[:1500]}\n")
    path.write_text(text + "".join(block))
    return str(path.relative_to(ROOT))


# ------------------------------------------------------------------ promotion

SECTION_CAP = 20000   # characters: the lessons section is read by every agent session, so it stays short

PROMPT = """You are the editor for a matching decompilation project (Glover, N64, KMC GCC 2.7.2). Read docs/notes-digest.md:
its sections marked "(unreviewed)" hold notes other agents wrote about compiler behaviour and tool pitfalls.
Then read AGENTS.md and find the section headed exactly "{heading}".

Task: promote the lessons that generalise beyond one function into that section, in the style of the "Known tricks"
bullets above it: one bold lead-in, then at most four lines, with the concrete C spelling and the source function in
parentheses. One lesson per bullet. Merge a note into an existing bullet only by replacing words, never by appending
another paragraph to it; a bullet that would grow past six lines gets split or trimmed instead. Skip anything that
only restates a rule already in AGENTS.md, anything about one function's state, and anything you cannot make general.
Hard limit: the whole section must stay under {cap} characters (it is {size} now); if adding would exceed that,
shorten or drop the weakest existing bullets first. Edit ONLY the text between that heading and the next "## " heading.
Do not touch any other part of AGENTS.md. Then, in docs/notes-digest.md, change each "(unreviewed)" heading to
"(reviewed)". Reply with one line: how many bullets you added, merged or shortened."""


def _section(text: str) -> str:
    head, _, rest = text.partition(LESSONS_HEADING)
    nxt = rest.find("\n## ")
    return rest[:nxt] if nxt >= 0 else rest


def promote(dry: bool) -> str:
    agents_md = ROOT / "AGENTS.md"
    before = agents_md.read_text()
    if LESSONS_HEADING not in before:
        return "no lessons section in AGENTS.md; skipped"
    if dry:
        return "dry run: would call claude -p"
    cmd = ["claude", "-p", PROMPT.format(heading=LESSONS_HEADING, cap=SECTION_CAP, size=len(_section(before))),
           "--allowedTools", "Read,Edit,Grep", "--permission-mode", "acceptEdits", "--max-turns", "40"]
    try:
        out = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=1200)
        reply = (out.stdout.strip().splitlines() or ["(no reply)"])[-1][:200]
    except subprocess.TimeoutExpired:
        reply = "claude -p timed out"
    after = agents_md.read_text()

    def outside(t: str) -> str:
        head, _, rest = t.partition(LESSONS_HEADING)
        nxt = rest.find("\n## ")
        return head + (rest[nxt:] if nxt >= 0 else "")
    if outside(before) != outside(after):
        agents_md.write_text(before)
        return f"reverted AGENTS.md: edit left the lessons section ({reply})"
    if len(_section(after)) > SECTION_CAP * 1.2 and len(_section(after)) > len(_section(before)):
        agents_md.write_text(before)
        return f"reverted AGENTS.md: lessons section grew to {len(_section(after))} chars, over the cap ({reply})"
    return reply



# ------------------------------------------------------------------ diff analysis

OBJDIFF = Path.home() / ".local/share/decompnet/toolchains/objdiff-cli/objdiff-cli"
ANALYZE_MIN = 85.0     # percent: below this the draft is structural work, not worth a row-by-row read
ANALYZE_MAX_FUNCS = 200
# The app judges with the progress report's settings (decompnet/forks/objdiff.py REPORT_OPTIONS): relocation
# names and addends are not compared at all, only the masked instruction bytes.
JUDGE_OPTS = ["-c", "functionRelocDiffs=none", "-c", "combineDataSections=true", "-c", "combineTextSections=true"]
NOTE_TAG = "[editor]"
MAX_FUNCTION_NOTES = 80   # notes posted per pass

ADVICE = {
    "wrongaddr": "the draft references a different address than the target at the rows above; the judge masks relocations so this still scores as if right, but the ROM would differ: use the symbol the target names",
    "nop": "a hazard nop at a statement boundary: join the two statements on one source line (-g2 line notes), or it is an assembler rule (AGENTS.md toolchain note)",
    "branch": "a branch lands in the wrong place: compute its target and move the statement it skips into or out of that block",
    "reg": "register allocation only: reorder declarations, split or merge temporaries, or leave it to the permuter after about 25 compiles (note `permuter queue`)",
    "stack": "the stack frame differs: a local, spill or saved register is missing or extra; fix that before registers",
    "struct": "instruction counts differ: control flow or an expression shape is wrong; fix structure before anything else",
    "imm": "an immediate differs: a field offset, constant or shift amount in the C is wrong",
}


def _snapshot_build(ref: str) -> Path | None:
    """Build the snapshot in its own worktree (never the live tree agents compile in). Returns the worktree."""
    wt = STATE_DIR / "wt"
    subprocess.run(["git", "worktree", "remove", "--force", str(wt)], cwd=ROOT, capture_output=True)
    subprocess.run(["git", "worktree", "prune"], cwd=ROOT, capture_output=True)
    if subprocess.run(["git", "worktree", "add", "-q", "--detach", str(wt), ref], cwd=ROOT, capture_output=True).returncode:
        return None
    r = subprocess.run(["make", "RUN_CC_CHECK=0", "-j4"], cwd=wt, capture_output=True, text=True, timeout=900)
    if r.returncode:
        log("snapshot build failed: " + (r.stderr.strip().splitlines() or ["?"])[-1][:200])
        return None
    return wt



_SYMS: dict | None = None


def _addr(spelling: str | None) -> int | None:
    """Address of `sym`, `sym+0x8` or `sym-0x4` from the symbol files, or None."""
    global _SYMS
    if _SYMS is None:
        _SYMS = {}
        for f in ("symbol_addrs.txt", "undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
            try:
                for m in re.finditer(r"^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)", (ROOT / f).read_text(), re.M):
                    _SYMS[m.group(1)] = int(m.group(2), 16)
            except OSError:
                pass
    if not spelling:
        return None
    m = re.match(r"^(\w+)(?:([+-])(0x[0-9a-f]+))?$", spelling)
    if not m or m.group(1) not in _SYMS:
        return None
    off = int(m.group(3), 16) if m.group(3) else 0
    return _SYMS[m.group(1)] + (off if m.group(2) != "-" else -off)

def _sym_name(side: dict, idx) -> str:
    try:
        return side["symbols"][idx]["name"].replace(".NON_MATCHING", "")
    except (IndexError, KeyError, TypeError):
        return "?"


def _row_info(side: dict, row: dict) -> dict:
    ins = row.get("instruction")
    if not ins:
        return {"empty": True}
    mn = next((p["opcode"]["mnemonic"] for p in ins.get("parts", []) if "opcode" in p), "")
    regs = [p["arg"]["opaque"] for p in ins.get("parts", []) if "arg" in p and "opaque" in p["arg"]]
    imms = [p["arg"].get("signed", p["arg"].get("unsigned")) for p in ins.get("parts", []) if "arg" in p and ("signed" in p["arg"] or "unsigned" in p["arg"])]
    rel = None
    if "relocation" in ins:
        rel = _sym_name(side, ins["relocation"]["target_symbol"])
        add = int(ins["relocation"].get("addend", 0) or 0)
        if add:
            rel += f"+{add:#x}" if add > 0 else f"-{-add:#x}"
    return {"mn": mn, "regs": regs, "imms": imms, "reloc": rel, "branch": ins.get("branch_dest"), "text": ins.get("formatted", "")}


def classify(d: dict, name: str) -> dict | None:
    def find(side):
        return next((s for s in side.get("symbols", []) if s.get("name") == name), None)
    L, R = find(d["left"]), find(d["right"])
    if not L or not R:
        return None
    li, ri = L["instructions"], R["instructions"]
    base_l = int(L.get("address", 0)); base_r = int(R.get("address", 0))
    c = collections.Counter(); reloc_pairs = []; nop_after = []; first = None
    for i, (a, b) in enumerate(zip(li, ri)):
        A, B = _row_info(d["left"], a), _row_info(d["right"], b)
        # relocation audit: the judge masks relocation fields, so a draft that names the wrong address still
        # scores 100%; compare the resolved addresses ourselves (symbol files) wherever both sides resolve
        if A.get("reloc") and B.get("reloc") and A["mn"] == B["mn"] and not A["reloc"].startswith(name):
            ta, tb = _addr(A["reloc"]), _addr(B["reloc"])
            if ta is not None and tb is not None and ta != tb:
                c["wrongaddr"] += 1
                reloc_pairs.append(f"row {i} target {A['reloc']} (draft: {B['reloc']})")
        if a.get("diff_kind", "DIFF_NONE") == "DIFF_NONE" and b.get("diff_kind", "DIFF_NONE") == "DIFF_NONE":
            continue
        if A.get("empty") or B.get("empty"):
            c["struct"] += 1
        elif A["mn"] == "nop" or B["mn"] == "nop":
            c["nop"] += 1
            prev = _row_info(d["left"], li[i - 1])["text"] if i else ""
            nop_after.append(f"row {i} after `{prev}`")
        elif A["mn"] != B["mn"]:
            c["struct"] += 1
        elif A["branch"] != B["branch"] and A["regs"] == B["regs"]:
            if (int(A["branch"] or 0) - base_l) != (int(B["branch"] or 0) - base_r):
                c["branch"] += 1
        elif A["regs"] != B["regs"]:
            c["reg"] += 1
        elif A["imms"] != B["imms"]:
            c["imm"] += 1
        elif A["text"].replace(".NON_MATCHING", "") == B["text"].replace(".NON_MATCHING", ""):
            continue  # only the stale .NON_MATCHING alias in the target object differs
        else:
            c["other"] += 1
        first = first or i
    if len(li) != len(ri):
        c["struct"] += abs(len(li) - len(ri))
    sp = lambda rows, side: next((_row_info(side, r)["imms"][0] for r in rows if _row_info(side, r).get("mn") == "addiu" and _row_info(side, r).get("regs", [])[:2] == ["sp", "sp"]), None)
    stack = (sp(li, d["left"]), sp(ri, d["right"]))
    if stack[0] != stack[1]:
        c["stack"] += 1
    if not c:
        return None
    return {"counts": dict(c), "rows": (len(li), len(ri)), "reloc_pairs": reloc_pairs[:4],
            "nops": nop_after[:3], "stack": stack, "first": first, "pct": R.get("match_percent")}


def analyze(db, ref: str, since_match: float = 0.0, last_audit: float = 0.0) -> dict:
    """Row-by-row objdiff classes for every open game-unit draft at ANALYZE_MIN% or better."""
    if not OBJDIFF.is_file():
        return {}
    wt = _snapshot_build(ref)
    if wt is None:
        return {}
    try:
        report = STATE_DIR / "report.json"
        subprocess.run([str(OBJDIFF), "report", "generate", "-p", str(wt), "-o", str(report)], capture_output=True, timeout=300)
        pct = {f["name"]: (u["name"], float(f.get("fuzzy_match_percent", 0))) for u in json.loads(report.read_text())["units"]
               for f in u.get("functions", [])}
        pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
        open_ = [r["name"] for r in db.execute("SELECT name FROM functions WHERE project_id=? AND status!='matched' AND unit IN (" + ",".join("?" * len(GAME_UNITS)) + ")",
                                               (pid, *GAME_UNITS))]
        todo = sorted([n for n in open_ if n in pct and ANALYZE_MIN <= pct[n][1] < 100], key=lambda n: -pct[n][1])[:ANALYZE_MAX_FUNCS]
        # relocation audit: everything matched since the last full audit (a day), else only the new matches
        full = time.time() - last_audit > 24 * 3600
        matched = [r["name"] for r in db.execute("SELECT name FROM functions WHERE project_id=? AND status='matched' AND unit IN (" + ",".join("?" * len(GAME_UNITS)) + ") "
                                                 "AND (? OR matched_at > ?)", (pid, *GAME_UNITS, int(full), since_match)) if r["name"] in pct]
        todo += matched
        out = {}
        for n in todo:
            dj = STATE_DIR / "diff.json"
            unit = pct[n][0]
            r = subprocess.run([str(OBJDIFF), "diff", "-1", str(ROOT / "expected" / f"{unit}.o"), "-2", str(wt / "build" / f"{unit}.o"),
                                *JUDGE_OPTS, "-o", str(dj), "--format", "json", n], capture_output=True, timeout=120)
            if r.returncode:
                continue
            try:
                cls = classify(json.loads(dj.read_text()), n)
            except (ValueError, KeyError, TypeError):
                cls = None
            if cls and (n not in matched or cls["counts"].get("wrongaddr")):
                cls["pct"] = pct[n][1]
                cls["matched"] = n in matched
                out[n] = cls
        (STATE_DIR / "classes.json").write_text(json.dumps(out, indent=1))
        return out
    finally:
        subprocess.run(["git", "worktree", "remove", "--force", str(wt)], cwd=ROOT, capture_output=True)


def diff_label(cls: dict | None) -> str:
    if not cls:
        return ""
    c = cls["counts"]
    order = ["struct", "stack", "branch", "nop", "imm", "reg", "wrongaddr", "other"]
    return ", ".join(f"{k} {c[k]}" for k in order if c.get(k))


def sweep_summary(name: str) -> str:
    runs = sorted((RESULTS_DIR / name).glob("*/")) if (RESULTS_DIR / name).is_dir() else []
    if not runs:
        return ""
    best = None
    for r in runs:
        for o in r.glob("output-*"):
            try:
                sc = int(o.name.split("-")[1]); best = sc if best is None else min(best, sc)
            except ValueError:
                pass
    return f"permuter sweep: {len(runs)} run(s), " + ("no improvement" if best is None else f"best score {best}")


RESULTS_DIR = ROOT / "permuter_results"


def function_note(name: str, fn, cls: dict, stamp: str) -> str:
    c = cls["counts"]; parts = []
    parts.append(f"{NOTE_TAG} {stamp}: {cls['pct']:.2f}% after {fn['attempts']} compiles; {cls['rows'][0]} target rows vs {cls['rows'][1]} in the draft; diff rows: {diff_label(cls)}.")
    if cls["reloc_pairs"]:
        parts.append("Wrong relocation address: " + "; ".join(cls["reloc_pairs"]) + ".")
    if cls["nops"]:
        parts.append("Nop rows: " + "; ".join(cls["nops"]) + ".")
    if c.get("stack"):
        parts.append(f"Stack frame: target {cls['stack'][0]} vs draft {cls['stack'][1]}.")
    main = next((k for k in ("wrongaddr", "struct", "stack", "branch", "nop", "imm", "reg") if c.get(k)), None)
    if main:
        parts.append("Read: " + ADVICE[main] + ".")
    sw = sweep_summary(name)
    if sw:
        parts.append(sw.capitalize() + ".")
    return " ".join(parts)[:1900]


def post_function_notes(db, classes: dict, stamp: str, dry: bool) -> int:
    """One current editor note per analysed function: replace ours when the analysis changed, never touch others'."""
    pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
    fns = {r["name"]: r for r in db.execute("SELECT id, name, attempts FROM functions WHERE project_id=?", (pid,))}
    prev = json.loads((STATE_DIR / "fnotes.json").read_text()) if (STATE_DIR / "fnotes.json").exists() else {}
    key = None; url = ""
    try:  # 1.0.4+: the running app's port and secret are in server.json (`decomp url` is gone)
        info = json.loads(Path(os.path.expanduser("~/Decomp/.decomp/server.json")).read_text())
        url, key = f"http://127.0.0.1:{info['port']}/?k={info['secret']}", info["secret"]
    except Exception:
        try:
            url = subprocess.run(["decomp", "url"], capture_output=True, text=True, timeout=60).stdout
            key = re.search(r"k=([A-Za-z0-9_-]+)", url).group(1)
        except Exception:
            pass
    posted = 0; new_prev = dict(prev)
    for name, cls in classes.items():
        if name not in fns:
            continue
        text = function_note(name, fns[name], cls, stamp)
        body = re.sub(r"^\[editor\] \S+ \S+: ", "", text)  # compare without the timestamp
        if prev.get(name) == body:
            continue
        if dry:
            posted += 1; continue
        if posted >= MAX_FUNCTION_NOTES or not key:
            break
        base = url.split("/?")[0]  # the running app, whatever port it took (`decomp url`)
        req = urllib.request.Request(f"{base}/api/note?slug={SLUG}", data=json.dumps({"text": text, "function": name}).encode(),
                                     headers={"Content-Type": "application/json", "Cookie": f"decomp_live={key}", "x-decomp": "1",
                                              "User-Agent": f"decompdecomp-window/{key}", "Host": base.split("//")[1]}, method="POST")
        try:
            with urllib.request.urlopen(req, timeout=60) as resp:
                resp.read()
        except Exception as e:
            log(f"note for {name} failed: {str(e)[:100]}")
            continue
        # drop our previous note on this function (ours only: tagged, authored by the operator agent)
        c = sqlite3.connect(str(DB), timeout=30)
        try:
            c.execute("DELETE FROM notes WHERE function_id=? AND text LIKE ? AND id < (SELECT max(id) FROM notes WHERE function_id=? AND text LIKE ?)",
                      (fns[name]["id"], NOTE_TAG + "%", fns[name]["id"], NOTE_TAG + "%"))
            c.commit()
        finally:
            c.close()
        new_prev[name] = body; posted += 1
    if not dry:
        (STATE_DIR / "fnotes.json").write_text(json.dumps(new_prev))
    return posted

# ------------------------------------------------------------------ main

def git(*args, check=True):
    return subprocess.run(["git", *GIT_ID, *args], cwd=ROOT, capture_output=True, text=True, check=check)


def fork_check() -> str:
    """Ask the app to re-measure the project (POST /api/fork/check), so its counts follow the tree the agents just
    changed instead of waiting for someone to press the button (2026-10-31: the dashboard sat at 1087 while the DB
    had 1113). Returns the job id or the error; never raises."""
    import urllib.request
    try:
        info = json.loads((Path.home() / "Decomp/.decomp/server.json").read_text())
        key = info["secret"]; base = f"http://127.0.0.1:{info['port']}"
        hdr = {"User-Agent": "decompdecomp-window/" + key, "Cookie": "decomp_live=" + key, "x-decomp": "1",
               "Content-Type": "application/json"}
        req = urllib.request.Request(base + "/api/fork/check", data=json.dumps({"slug": "glover"}).encode(), headers=hdr, method="POST")
        return "fork check " + json.loads(urllib.request.urlopen(req, timeout=30).read()).get("job", "?")
    except Exception as e:  # the app may be down; the pass is not
        return f"fork check skipped ({e.__class__.__name__})"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--force", action="store_true")
    ap.add_argument("--no-promote", action="store_true")
    ap.add_argument("--no-analyze", action="store_true")
    opt = ap.parse_args()
    STATE_DIR.mkdir(parents=True, exist_ok=True)
    lock = open(LOCK, "w")
    try:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except BlockingIOError:
        log("another pass is running; skipped")
        return 0
    now = time.time()
    stamp = time.strftime("%Y-%m-%d %H:%M")
    db = db_ro()
    pid = db.execute("SELECT id FROM projects WHERE slug=?", (SLUG,)).fetchone()["id"]
    if STATE.exists():
        state = json.loads(STATE.read_text())
    else:  # first run: digest nothing older than the v3 assembler install; earlier assembler-wall notes are obsolete
        cutoff = max(now - 36 * 3600, time.mktime(time.strptime(NOTES_EPOCH, "%Y-%m-%d %H:%M")))
        last = db.execute("SELECT max(id) FROM notes WHERE project_id=? AND function_id IS NULL AND created_at<=?",
                          (pid, cutoff)).fetchone()[0] or 0
        state = {"last_run": cutoff, "last_note_id": last}
    activity = sum(db.execute(q, (pid, state["last_run"])).fetchone()[0] for q in (
        "SELECT count(*) FROM events WHERE project_id=? AND created_at>?",
        "SELECT count(*) FROM attempts a JOIN functions f ON f.id=a.function_id WHERE f.project_id=? AND a.created_at>?",
        "SELECT count(*) FROM notes WHERE project_id=? AND created_at>?"))
    if not activity and not opt.force:
        log("quiet: no agent activity since last pass")
        return 0

    ref = subprocess.run(["git", "stash", "create"], cwd=ROOT, capture_output=True, text=True).stdout.strip() or "HEAD"
    classes = {} if opt.no_analyze else analyze(db, ref, since_match=state["last_run"], last_audit=state.get("last_audit", 0.0))
    full_audit = not opt.no_analyze and time.time() - state.get("last_audit", 0.0) > 24 * 3600
    gen = regenerate(db, stamp, classes)
    byname = {f["name"]: f for f in db.execute("SELECT name, status FROM functions WHERE project_id=?", (pid,))}
    old_queue = (ROOT / "docs" / "permuter-queue.md").read_text() if (ROOT / "docs" / "permuter-queue.md").exists() else ""
    stale = stale_entries(old_queue, byname)
    notes = new_notes(db, state["last_note_id"])
    notes = notes[:MAX_DIGEST]
    know = new_knowledge(db, state.get("last_knowledge_id", 0))[:MAX_DIGEST]
    lessons = [n for n in notes if not is_housekeeping(n["text"])] + know
    hk = housekeeping_notes(db)
    summary = (f"activity {activity}; matched {gen['counts']['matched']}; lists: {gen['counts']['near']} near misses, "
               f"{gen['counts']['permuter']} permuter-only, {gen['counts']['large']} large + {gen['counts']['medium']} medium "
               f"undrafted; {len(stale)} stale entries removed; {len(lessons)} lesson notes, {len(hk)} housekeeping notes")
    fnotes = post_function_notes(db, classes, stamp, opt.dry_run) if classes else 0
    summary += f"; analysed {len(classes)} drafts, {fnotes} function notes"
    if opt.dry_run:
        log("dry run: " + summary)
        for n, cls in list(classes.items())[:8]:
            print("  ", n, "|", function_note(n, {"attempts": "?"}, cls, stamp)[:230])
        for n in hk:
            print("  would delete:", n["agent"], "|", " ".join(n["text"].split())[:110])
        for n in lessons:
            print("  lesson:", n["agent"], "|", " ".join(n["text"].split())[:110])
        return 0

    db.close()
    (ROOT / "docs" / "permuter-queue.md").write_text(gen["queue"])
    (ROOT / "docs" / "untouched-functions.md").write_text(gen["untouched"])
    if lessons:
        digest_append(lessons, stamp)
    if hk:
        with open(ARCHIVE, "a") as f:
            for n in hk:
                f.write(json.dumps({"id": n["id"], "agent": n["agent"], "t": n["created_at"], "text": n["text"]}) + "\n")
        delete_notes([n["id"] for n in hk])
    promoted = "no new lessons" if not lessons else ("skipped" if opt.no_promote else promote(False))

    paths = ["AGENTS.md", "docs/permuter-queue.md", "docs/untouched-functions.md", "docs/notes-digest.md"]
    paths = [p for p in paths if (ROOT / p).exists()]
    git("add", "--", *paths)
    if git("diff", "--cached", "--quiet", check=False).returncode:
        msg = (f"Editor pass {stamp}: lists regenerated ({len(stale)} stale), {len(lessons)} notes digested, "
               f"{len(hk)} housekeeping notes pruned; promotion: {promoted}" + TRAILER)
        git("commit", "-q", "-m", msg, "--", *paths)
        committed = git("rev-parse", "--short", "HEAD").stdout.strip()
    else:
        committed = "nothing to commit"
    state = {"last_run": now, "last_note_id": max([state["last_note_id"]] + [n["id"] for n in notes]),
             "last_knowledge_id": max([state.get("last_knowledge_id", 0)] + [k["id"] for k in know]),
             "last_audit": now if full_audit else state.get("last_audit", 0.0)}
    STATE.write_text(json.dumps(state))
    log(f"{summary}; promotion: {promoted}; commit {committed}; {fork_check()}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
