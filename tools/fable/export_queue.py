#!/usr/bin/env python3
"""Write the off-tree permuter's queue from the app's database: permuter_results/queue.txt (open near misses, best
first) and permuter_results/best/<function>.c (the app's best draft of each, as it would be spliced into the unit).
run_permuter.py --drafts permuter_results/best splices those drafts into the unit copies it ranks and permutes.

A draft is queued until it has had `runs` finished permuter runs (default 2), so the batches do not permute the same
draft again and again: permuter_results/permute_runs.json maps each near miss to the sha1 of its current best_source
and the runs made on that draft. A run counts when its result directory (pulled from the server or made here) holds
the draft in its input (context.c, or context_gnu.c) and finished (status.json), or was refused because the draft
needs its GNU statement expressions. A new best draft (an improvement went in) starts again from zero runs. Matching
the input rather than the time keeps the count right across the two machines' clocks and for a run that started on
the old draft.
    python3 -I tools/fable/export_queue.py [max-distance-percent (default 6)] [max-insns (default 3000)] [runs (default 2)]"""
import glob, hashlib, json, os, sqlite3, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
import run_permuter as rp  # noqa: E402  (definitions() and the K&R pattern: the drafts as the runs see them)

dist = float(sys.argv[1]) if len(sys.argv) > 1 else 6.0
max_insns = int(sys.argv[2]) if len(sys.argv) > 2 else 3000
max_runs = int(sys.argv[3]) if len(sys.argv) > 3 else 2
c = sqlite3.connect('file:' + os.path.expanduser('~/Decomp/.decomp/decomp.db') + '?mode=ro', uri=True)
pid = c.execute("select id from projects where slug='glover'").fetchone()[0]
rows = c.execute("select name, n_insns, best_score, best_source from functions where project_id=? and status='open' "
                 "and best_score > 0 and best_source is not null and best_score <= ? * n_insns and n_insns <= ? "
                 "order by best_score * 1.0 / n_insns", (pid, dist, max_insns)).fetchall()
# Structural near misses are not permuter work: the editor pass's row classes (~/Decomp/.decomp/glover-editor/classes.json)
# count the rows where an instruction, branch, stack slot, immediate or nop differs; a draft with more than
# QUEUE_MAX_STRUCT such rows (default 4) needs C, and the permuter's mutations only burn server time on it.
# Unclassified drafts (the editor pass skips drafts below 85% and some units) are kept.
max_struct = int(os.environ.get('QUEUE_MAX_STRUCT', '4'))
try:
    with open(os.path.expanduser('~/Decomp/.decomp/glover-editor/classes.json')) as f:
        _classes = json.load(f)
except (OSError, ValueError):
    _classes = {}
def structural(name):
    c = (_classes.get(name) or {}).get('counts') or {}
    return sum(c.get(k, 0) for k in ('struct', 'branch', 'stack', 'imm', 'nop'))
skipped = [r[0] for r in rows if structural(r[0]) > max_struct]
rows = [r for r in rows if structural(r[0]) <= max_struct]
res = os.path.join(ROOT, 'permuter_results')
best = os.path.join(res, 'best')
os.makedirs(best, exist_ok=True)
runs_path = os.path.join(res, 'permute_runs.json')


def write(path, text):
    """Replace the file in one step: the batches read the queue and the drafts while this runs."""
    with open(path + '.tmp', 'w') as f:
        f.write(text)
    os.replace(path + '.tmp', path)


def needles(fn, draft):
    """Text that a run's input holds when the run permuted this draft: run_permuter.py splices the draft verbatim,
    then cuts the bodies of the other functions and gives a K&R definition a prototype head."""
    defs = rp.definitions(draft)
    if fn not in defs:
        return [draft.strip()]
    start, brace, end = defs[fn]
    found = [draft.strip() if len(defs) == 1 else draft[start:end]]
    if any(m['name'] == fn for m in rp.KNR_DEF.finditer(draft)):
        found.append(draft[brace:end])
    return found


def false_zero(d):
    """A run the permuter ended at once because its scorer saw no difference (the judge does): nothing to search."""
    try:
        with open(os.path.join(d, 'status.json')) as f:
            return bool(json.load(f).get('false_zero'))
    except (OSError, ValueError):
        return False


def finished(d):
    if os.path.exists(os.path.join(d, 'status.json')):
        return True
    # refused (the draft needs its GNU statement expressions): prepare() stops before selection.json
    return os.path.exists(os.path.join(d, 'gnu_check.json')) and not os.path.exists(os.path.join(d, 'selection.json'))


def holds(d, keys):
    for name in ('context.c', 'context_gnu.c'):
        try:
            with open(os.path.join(d, name), errors='replace') as f:
                text = f.read()
        except OSError:
            continue
        if any(k in text for k in keys):
            return True
    return False


try:
    with open(runs_path) as f:
        old = json.load(f)
except (OSError, ValueError):
    old = {}
state, queue, new_drafts = {}, [], 0
for name, n, score, source in rows:
    draft = source.rstrip('\n') + '\n'
    path = os.path.join(best, name + '.c')
    try:
        with open(path) as f:
            unchanged = f.read() == draft
    except OSError:
        unchanged = False
    if not unchanged:
        write(path, draft)
    sha = hashlib.sha1(source.encode()).hexdigest()
    # permuter_results/best_override/<fn>.c with <fn>.c.for holding the sha of the app draft it replaces: a repaired
    # copy of a best draft that no longer compiles in its unit (the app keeps an equal-scoring resubmission out of
    # best_source); it expires on its own when the app's best changes
    ov = os.path.join(res, 'best_override', name + '.c')
    try:
        with open(ov + '.for') as f:
            if f.read().strip() == sha:
                with open(ov) as g:
                    draft = g.read()
                    write(path, draft)
    except OSError:
        pass
    prev = old.get(name, {})
    same = prev.get('sha1') == sha
    new_drafts += bool(prev) and not same
    # cache: a finished directory never changes its draft, so only new ones are read (all of them for a new draft)
    known, known_older = (set(prev.get('dirs', [])), set(prev.get('older', []))) if same else (set(), set())
    dirs, older, keys = [], [], None
    for d in sorted(glob.glob(os.path.join(res, name, '2*-*'))):
        run = os.path.basename(d)
        if run in known or run in known_older:
            (dirs if run in known else older).append(run)
        elif finished(d):  # one still running (or broken before the permuter) is looked at again next time
            keys = keys or needles(name, draft)
            (dirs if holds(d, keys) else older).append(run)
    blind = any(false_zero(os.path.join(res, name, run)) for run in dirs)
    state[name] = {'sha1': sha, 'runs': len(dirs), 'dirs': dirs, 'older': older, 'false_zero': blind}
    if len(dirs) < max_runs and not blind:
        queue.append(name)
names = {r[0] for r in rows}
for f in os.listdir(best):
    if f.endswith('.tmp') or (f.endswith('.c') and f[:-2] not in names):
        os.remove(os.path.join(best, f))
write(os.path.join(res, 'queue.txt'), ''.join(fn + '\n' for fn in queue))
write(runs_path, json.dumps(state, indent=1, sort_keys=True) + '\n')
print(f"queue: {len(queue)} of {len(rows)} near misses ({len(skipped)} structural drafts left to agents, QUEUE_MAX_STRUCT={max_struct}; best first; {len(rows) - len(queue)} have had {max_runs} runs "
      f"on their current draft, {new_drafts} new drafts since the last export), drafts in permuter_results/best/")
