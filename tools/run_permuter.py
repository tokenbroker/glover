#!/usr/bin/env python3
"""Rank archived C drafts with objdiff and permute isolated copies; never edit src/."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import signal
import subprocess
import sys
import time
import tomllib
import venv

ROOT = Path(__file__).resolve().parents[1]
PIN = '8556c81d80d1c1af98a858c8f4dc951357f29139'
RESULTS = ROOT / 'permuter_results'
TOOL = Path(os.environ.get('DECOMP_PERMUTER', ROOT / 'tools/decomp-permuter')).resolve()
PYTHON = Path(os.environ.get('PERMUTER_PYTHON', ROOT / 'tools/.permuter-venv/bin/python')).absolute()
OBJD = Path(os.environ.get('OBJDIFF_CLI', Path.home() / '.local/share/decompnet/toolchains/objdiff-cli/objdiff-cli'))


def run(args, **kwargs):
    return subprocess.run([str(x) for x in args], check=True, **kwargs)


def setup():
    if not TOOL.exists():
        run(['git', 'clone', 'https://github.com/simonlindholm/decomp-permuter.git', TOOL])
        run(['git', '-C', TOOL, 'checkout', PIN])
    if not PYTHON.exists():
        venv.create(PYTHON.parent.parent, with_pip=True)
        run([PYTHON, '-m', 'pip', 'install', 'toml==0.10.2', 'PyNaCl==1.6.2', 'Levenshtein==0.27.5'])
    run([PYTHON, TOOL / 'permuter.py', '--help'], stdout=subprocess.DEVNULL)
    print(f'Ready: {TOOL}, {PYTHON}')


def definitions(source):
    # Run on unpreprocessed repository C. Count braces with comments/strings masked.
    masked = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                    lambda m: ''.join('\n' if c == '\n' else ' ' for c in m[0]), source, flags=re.S)
    # ANSI definitions, and K&R ones whose parameter declarations follow the ')' (each 'type name;' on its own
    # line, no parentheses): a prototype's ')' is followed by ';' and never matches.
    pattern = r'(?m)^[\w][\w\s*]*?\b(func_[0-9A-Fa-f]+|main)\s*\([^;{}]*\)\s*(?:[\w\s*,\[\]]+;\s*)*\{'
    found = {}
    for match in re.finditer(pattern, masked):
        start = masked.index('{', match.start())
        depth, end = 1, start + 1
        while depth:
            depth += (masked[end] == '{') - (masked[end] == '}')
            end += 1
        found[match[1]] = (match.start(), start, end)
    return found


KNR_DEF = re.compile(r'(?m)^(?P<head>[A-Za-z_][\w\s*]*?\b(?P<name>func_[0-9A-Fa-f]+|main))\s*\('
                     r'(?P<params>[A-Za-z_]\w*(?:\s*,\s*[A-Za-z_]\w*)*)\)\s*\n'
                     r'(?P<decls>(?:[ \t]*[A-Za-z_][^;{}\n]*;[ \t]*\n)+)[ \t]*\{')


def ansify_knr(source, target):
    """Rewrite old-style (K&R) definitions as prototype-style ones.

    The permuter's C parser drops the parameter declarations of a K&R definition
    and definitions() does not recognise the form either, so one such function in
    a unit breaks every run on that unit. Bodies of non-target functions are
    stripped anyway, so the (float-promotion) codegen difference only matters when
    the target itself is K&R; that case is reported."""
    converted = []
    promoted = {'f32': 'f64', 'float': 'double', 's8': 's32', 'u8': 's32', 's16': 's32',
                'u16': 's32', 'char': 'int', 'short': 'int'}

    def prototype_types(name):
        # Types from an existing prototype-style declaration, so the rewritten
        # definition agrees with what the rest of the unit already declares.
        for proto in re.finditer(r'(?m)^[\w][\w\s*]*?\b' + re.escape(name) + r'\s*\(([^;{}]*)\)\s*;', source):
            params = [p.strip() for p in proto[1].split(',')]
            if params == ['void'] or not all(re.search(r'[A-Za-z_]', p) for p in params):
                continue
            types = []
            for p in params:
                tokens = p.replace('*', ' * ').split()
                if len(tokens) > 1 and tokens[-1] != '*' and re.match(r'[A-Za-z_]\w*$', tokens[-1]) \
                        and tokens[-1] not in ('int', 'char', 'short', 'long', 'unsigned', 'signed', 'float', 'double', 'void'):
                    tokens = tokens[:-1]
                types.append(' '.join(tokens).replace(' * ', ' *').replace('* *', '**'))
            return types
        return None

    def repl(match):
        decls = {}
        for line in match['decls'].strip().split('\n'):
            line = line.strip().rstrip(';').strip()
            if not line:
                continue
            parts = [p.strip() for p in line.split(',')]
            base, first = parts[0].rsplit(' ', 1) if ' ' in parts[0] else ('int', parts[0])
            base = base.strip()
            for declarator in [first] + parts[1:]:
                stars = declarator.count('*')
                ident = declarator.replace('*', '').strip()
                decls[ident] = (base, '*' * stars)
        params = [p.strip() for p in match['params'].split(',')]
        if any(p not in decls for p in params):
            return match[0]
        name = match['name']
        if name == target:
            typed = [f'{decls[p][0]} {decls[p][1]}{p}' for p in params]
        else:
            types = prototype_types(name)
            if types and len(types) == len(params):
                typed = [f'{t} {p}' if t.endswith('*') else f'{t} {p}' for t, p in zip(types, params)]
                typed = [t.replace('* ', '*') for t in typed]
            else:
                typed = [f'{promoted.get(decls[p][0], decls[p][0]) if not decls[p][1] else decls[p][0]} '
                         f'{decls[p][1]}{p}' for p in params]
        converted.append(name)
        return f"{match['head']}({', '.join(typed)})\n{{"

    source = KNR_DEF.sub(repl, source)
    if target in converted:
        print(f'{target}: old-style definition rewritten with prototypes; float arguments lose '
              'default promotion, so the score may differ from objdiff', file=sys.stderr)
    return source


_UNIT_CMDS = {}


def unit_command(unit):
    """The unit's own compile command from the Makefile (`make -n`), as a token list without the source, the object,
    `-c`, `-o` and the COMPILER_PATH export: KMC GCC for most units, IDO 5.3 for src/18020_C0800.c. Each unit's
    flags differ (the -O0 pieces, the library without -g and with --fp-move-nops, the IDO unit), so one command
    would judge most of them against the wrong code."""
    if unit not in _UNIT_CMDS:
        toks, env = None, {}
        try:
            out = subprocess.run(['make', '-s', '-n', '-B', 'RUN_CC_CHECK=0', f'build/{unit}.o'], cwd=ROOT,
                                 capture_output=True, text=True, timeout=120).stdout
            lines = [ln for ln in out.splitlines() if f'{unit}.c' in ln and f'build/{unit}.o' in ln]
            line = lines[-1] if lines else ''   # the last one: with RUN_CC_CHECK=0 the first is the empty check (`:`)
            m = re.match(r'export COMPILER_PATH=(\S+) && (.*)', line)
            if m:
                env['COMPILER_PATH'] = str(ROOT / m.group(1)); line = m.group(2)
            if 'ido_build.py' in line:
                # the IDO unit goes through asm-processor (tools/fable/ido_build.py <cc> -- <as> -- <args>): the
                # permuter wants the bare compiler command, so take the compiler and the arguments after the last `--`
                toks = shlex.split(line)
                cc = toks[toks.index('ido_build.py') + 1 if 'ido_build.py' in toks else 2: toks.index('--')]
                line = ' '.join(shlex.quote(t) for t in cc + toks[len(toks) - toks[::-1].index('--'):])
            if line:
                toks = shlex.split(line)
                skip = {'-c', f'build/{unit}.o', f'{unit}.c'}
                toks = [t for k, t in enumerate(toks) if t not in skip and not (t == '-o') and not (k > 0 and toks[k - 1] == '-o')]
                toks = [t for t in toks if not t.startswith('-I')]
                if not os.path.isabs(toks[0]):
                    toks[0] = str(ROOT / toks[0])
        except (OSError, subprocess.TimeoutExpired, IndexError):
            toks = None
        if not toks:
            compiler = ROOT / 'tools/gcc_2.7.2' / ('macos' if sys.platform == 'darwin' else 'linux')
            toks = [str(compiler / 'gcc'), '-B' + str(ROOT / 'tools/build') + '/', '-O2', '-g2', '-G0', '-mips3', '-mgp32', '-mfp32',
                    '-Wa,--no-float-doubleword', '-Wa,-mabi=32', '-Wa,-Iinclude', '-D_LANGUAGE_C', '-DF3DEX_GBI_2']
            env = {'COMPILER_PATH': str(compiler)}
        _UNIT_CMDS[unit] = (toks, env)
    toks, env = _UNIT_CMDS[unit]
    return list(toks), dict(env)


def compiler_args(include, unit='src/18020_1D7F0'):
    toks, env = unit_command(unit)
    flags = toks + ['-I' + str(include), '-I' + str(ROOT / 'include'), '-I' + str(ROOT / 'src')]
    return flags, dict(os.environ, **env)


def compiler_type(unit):
    """What decomp-permuter should assume about the unit's compiler: ido for the IDO unit, gcc otherwise."""
    return 'ido' if 'ido' in unit_command(unit)[0][0] else 'gcc'


def rank(ref, drafts_dir=None):
    revision = subprocess.check_output(['git', 'rev-parse', ref], cwd=ROOT, text=True).strip()
    snapshot = RESULTS / 'ranking' / revision
    snapshot.mkdir(parents=True, exist_ok=True)
    include = snapshot / 'include'
    include.mkdir(exist_ok=True)
    # Historical headers prevent collisions with today's shared types.
    headers = subprocess.check_output(['git', 'ls-tree', '-r', '--name-only', revision, 'include'], cwd=ROOT, text=True)
    for name in headers.splitlines():
        dest = snapshot / name
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(subprocess.check_output(['git', 'show', f'{revision}:{name}'], cwd=ROOT))
    units, sources = [], {}
    config = json.loads((ROOT / 'objdiff.json').read_text())
    checks_path = snapshot / 'draft_check.json'
    checks = json.loads(checks_path.read_text()) if checks_path.exists() else {}
    with (snapshot / 'compile.log').open('w') as log:
        for unit in config['units']:
            source = unit.get('metadata', {}).get('source_path')
            if not source:
                continue
            dest = snapshot / source
            dest.parent.mkdir(parents=True, exist_ok=True)
            text = subprocess.check_output(['git', 'show', f'{revision}:{source}'], cwd=ROOT).decode()
            obj = dest.with_suffix('.o')
            args, env = compiler_args(include, unit['name'])

            def compiles(candidate_text):
                dest.write_text(candidate_text)
                return subprocess.run(args + ['-c', dest, '-o', obj], cwd=ROOT, env=env, stdout=log, stderr=log).returncode == 0

            drafts = available_drafts(text, drafts_dir) if drafts_dir else {}
            if drafts and not compiles(splice_drafts(text, drafts)):
                # one draft breaks the unit: keep those that compile on their own (remembered per draft text)
                good = {}
                for fn, draft in drafts.items():
                    key = hashlib.sha1(f'{unit["name"]} {fn}\n{draft}'.encode()).hexdigest()
                    if key not in checks:
                        checks[key] = compiles(splice_drafts(text, {fn: draft}))
                        checks_path.write_text(json.dumps(checks))
                    if checks[key]:
                        good[fn] = draft
                    else:
                        print(f'{unit["name"]}: draft of {fn} does not compile, skipped', file=sys.stderr)
                drafts = good
                if drafts and not compiles(splice_drafts(text, drafts)):
                    print(f'{unit["name"]}: the drafts conflict with each other, none spliced', file=sys.stderr)
                    drafts = {}
            if not drafts:
                dest.write_text(text)
                run(args + ['-c', dest, '-o', obj], cwd=ROOT, env=env, stdout=log, stderr=log)
            units.append({'name': unit['name'], 'target_path': str(ROOT / unit['target_path']), 'base_path': str(obj)})
            sources[unit['name']] = (source, dest.read_text())
    (snapshot / 'objdiff.json').write_text(json.dumps({'units': units}))
    report = snapshot / 'objdiff-report.json'
    run([OBJD, 'report', 'generate', '-p', snapshot, '-o', report])
    baseline = {line.split('\t')[1] for line in (ROOT / 'reports/cleanup-baseline-100-percent.txt').read_text().splitlines()}
    candidates = []
    for unit in json.loads(report.read_text())['units']:
        source, text = sources[unit['name']]
        defs = definitions(text)
        for fn in unit.get('functions', []):
            name, percent = fn['name'], fn.get('fuzzy_match_percent', 0)
            if name not in defs or name in baseline or not 0 < percent < 100:
                continue
            start, _, end = defs[name]
            body = text[start:end]
            if re.search(r'\b(?:asm|__asm__)\s*\(|\b__builtin_mfc0\b', body):
                continue
            candidates.append({'function': name, 'source': source, 'objdiff_percent': percent,
                               'objdiff_distance': 100 - percent, 'draft_revision': revision})
    candidates.sort(key=lambda x: (x['objdiff_distance'], x['function']))
    (snapshot / 'candidates.json').write_text(json.dumps(candidates, indent=2) + '\n')
    return candidates, sources, snapshot


def prepare(candidate, sources, snapshot):
    name = candidate['function']
    work = RESULTS / name
    # Preserve earlier outputs by using a separate run directory.
    work = work / time.strftime('%Y%m%d-%H%M%S')
    work.mkdir(parents=True, exist_ok=False)
    unit_text = sources[candidate['source'][:-2]][1]
    args, env = compiler_args(snapshot / 'include', candidate['source'][:-2])
    script = '#!/usr/bin/env bash\nset -euo pipefail\ncd -- ' + shlex.quote(str(ROOT)) + '\n'
    script += 'export COMPILER_PATH=' + shlex.quote(env['COMPILER_PATH']) + '\n'
    script += 'exec ' + shlex.join(args) + ' -c "$@"\n'
    (work / 'compile.sh').write_text(script)
    (work / 'compile.sh').chmod(0o755)
    settings = tomllib.loads((ROOT / 'permuter_settings.toml').read_text())
    (work / 'settings.toml').write_text(f'func_name = "{name}"\ncompiler_type = "{compiler_type(candidate["source"][:-2])}"\n')
    asm = ROOT / 'asm/nonmatchings' / Path(candidate['source']).stem / (name + '.s')
    # Target assembly is copied to ignored output; original asm/ is never written.
    target = '.set noat\n.set noreorder\n.include "macro.inc"\n' + asm.read_text()
    (work / 'target.s').write_text(target)
    # the project's own assembler (no cross binutils needed on another machine); --fp-move-nops keeps it from
    # rewriting the ROM's own delay slots, so the object equals the system assembler's byte for byte
    run([ROOT / 'tools/build/as', '-mips3', '-32', '-G0', '-EB', '-mabi=32', '--fp-move-nops', '-I' + str(ROOT / 'include'),
         '-I' + str(ROOT / 'asm'), work / 'target.s', '-o', work / 'target.o'])

    def cpp(path):
        return subprocess.check_output(['cpp', '-P', '-undef', '-D_LANGUAGE_C', '-DF3DEX_GBI_2', '-DINCLUDE_ASM(x,y)=',
                                        '-D__attribute__(x)=', '-I' + str(snapshot / 'include'), '-I' + str(ROOT / 'include'),
                                        path], cwd=ROOT, text=True)

    def build(source, suffix=''):
        """context<suffix>.c -> base<suffix>.c (preprocessed, other bodies dropped) -> base<suffix>.o"""
        defs = definitions(source)
        for fn, (start, brace, end) in sorted(defs.items(), key=lambda x: x[1][0], reverse=True):
            if fn == name:
                continue
            header = source[start:brace]
            if ';' in header[header.rfind(')'):]:   # a K&R definition: `f(a, b) int a; int b;` is no prototype
                if re.search(r'\b' + fn + r'\s*\([^;{]*\)\s*;', source[:start]):
                    source = source[:start] + source[end:]        # an earlier prototype already declares it
                else:
                    ansi = ansify_knr(source[start:end], fn)
                    d2 = definitions(ansi).get(fn)
                    source = source[:start] + (ansi[:d2[1]] + ';' if d2 else '') + source[end:]
            else:
                source = source[:brace] + ';' + source[end:]
        source = re.sub(r'(?m)^INCLUDE_ASM\([^;]+;\s*', '', source)
        # Drop historical padding arrays only in this isolated input.
        source = re.sub(r'(?ms)^const u32 \w+_padding\[\].*?\};', '', source)
        (work / f'context{suffix}.c').write_text(source)
        text = cpp(work / f'context{suffix}.c')
        # GNU statement expressions `({ f(x); })` (some drafts use them, sometimes through macros) are not C to the
        # permuter's parser: the plain expression goes to the permuter, and the function is refused below when that
        # changes its code. The rewrite is done after cpp so macro-made ones are caught too.
        plain = re.sub(r'\(\{\s*([^;{}]+?);\s*\}\)', r'(\1)', text)
        (work / f'base{suffix}.c').write_text(plain)
        if '({' in plain:   # a multi-statement one: no plain C for it
            (work / 'gnu_check.json').write_text('{"refused": "multi-statement GNU statement expression"}\n')
            raise RuntimeError('the draft needs multi-statement GNU statement expressions (no C for the permuter)')
        run([work / 'compile.sh', work / f'base{suffix}.c', '-o', work / f'base{suffix}.o'])
        return text, plain

    ansified = ansify_knr(unit_text, name)
    try:
        gnu_text, plain = build(ansified)
    except subprocess.CalledProcessError:
        if ansified == unit_text:
            raise
        # the K&R definition rewritten as a prototype clashes with an earlier declaration: keep it K&R
        print(f'{name}: the ANSI rewrite of its K&R definition does not compile, keeping it K&R', file=sys.stderr)
        gnu_text, plain = build(unit_text)
    if plain != gnu_text:
        (work / 'base_gnu.c').write_text(gnu_text)
        run([work / 'compile.sh', work / 'base_gnu.c', '-o', work / 'base_gnu.o'])
        run([OBJD, 'diff', '-1', work / 'base_gnu.o', '-2', work / 'base.o', '-c', 'functionRelocDiffs=none',
             '--format', 'json', '-o', work / 'gnu_check.json', name], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        check = json.loads((work / 'gnu_check.json').read_text())
        left = next((x for x in check['left']['symbols'] if x.get('name') == name), None)
        if not left or left.get('match_percent', 0) < 100:
            raise RuntimeError('the draft needs its GNU statement expressions (plain expressions compile differently)')
    (work / 'selection.json').write_text(json.dumps(candidate, indent=2) + '\n')
    return work


def permute(work, seconds, jobs):
    command = [str(PYTHON), str(TOOL / 'permuter.py'), str(work), '-j', str(jobs),
               '--better-only', '--best-only', '--stop-on-zero', '--stack-diffs', '--quiet']
    started = time.monotonic()
    with (work / 'run.log').open('w') as log:
        process = subprocess.Popen(command, cwd=work, stdout=log, stderr=subprocess.STDOUT,
                                   start_new_session=True, env=dict(os.environ, PYTHONUNBUFFERED='1'))
        timed_out = False
        try:
            code = process.wait(timeout=seconds)
        except subprocess.TimeoutExpired:
            timed_out = True
            os.killpg(process.pid, signal.SIGINT)
            try:
                code = process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                code = process.wait()
        except KeyboardInterrupt:
            os.killpg(process.pid, signal.SIGINT)
            try:
                process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                process.wait()
            raise
    status = {'seconds': round(time.monotonic() - started, 2), 'jobs': jobs,
              'timed_out': timed_out, 'exit_code': code, 'command': command}
    (work / 'status.json').write_text(json.dumps(status, indent=2) + '\n')
    log_text = (work / 'run.log').read_text()
    if 'base score =' not in log_text or (not timed_out and code != 0):
        raise RuntimeError(f'Permuter failed; inspect {work / "run.log"}')
    if re.search(r'base score = 0\b', log_text) and not list(work.glob('output-*')):
        status['false_zero'] = True   # the permuter's scorer sees no diff where the judge does: nothing to search
        (work / 'status.json').write_text(json.dumps(status, indent=2) + '\n')
        raise RuntimeError('permuter false zero: its scorer sees no difference, the judge does (nothing to permute)')
    print(f'Finished ({status["seconds"]} seconds): {work}')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('n', nargs='?', type=int, default=1, help='number of best non-zero drafts (default 1)')
    parser.add_argument('--seconds', type=float, default=1800, help='time per function (default 1800)')
    parser.add_argument('--jobs', type=int, default=os.cpu_count() or 1, help='workers (default all CPU cores)')
    parser.add_argument('--draft-ref', default='e632d9d', help='archived source revision, default pre-cleanup HEAD')
    parser.add_argument('--setup', action='store_true', help='install pinned permuter and isolated dependencies, then exit')
    parser.add_argument('--list', action='store_true', help='compile archived drafts, rank, and exit')
    parser.add_argument('--function', help='run one named eligible function instead of the top N')
    parser.add_argument('--drafts', default=str(RESULTS / 'best') if (RESULTS / 'best').is_dir() else '',
                        help="directory of <function>.c drafts spliced into the units (default permuter_results/best if present; '' for none)")
    options = parser.parse_args()
    if options.setup:
        setup()
        return
    if options.n < 1 or options.seconds <= 0 or options.jobs < 1:
        parser.error('n, seconds and jobs must be positive')
    if not OBJD.is_file():
        parser.error(f'objdiff-cli missing: {OBJD}')
    if not options.list and (not (TOOL / 'permuter.py').exists() or not PYTHON.exists()):
        parser.error('Run tools/run_permuter.sh --setup first, or set DECOMP_PERMUTER and PERMUTER_PYTHON')
    candidates, sources, snapshot = rank(options.draft_ref, options.drafts or None)
    chosen = candidates[:options.n]
    if options.function:
        chosen = [c for c in candidates if c['function'] == options.function]
        if not chosen:
            parser.error('Function has no eligible non-zero pure-C draft in the selected revision')
    if not chosen:
        parser.error('No eligible non-zero drafts; use --draft-ref to select a revision containing C drafts')
    for c in chosen:
        print(f'{c["function"]}: objdiff distance {c["objdiff_distance"]:.6f} ({c["objdiff_percent"]:.6f}%)', flush=True)
    if options.list:
        return
    failures = []
    for c in chosen:
        try:
            work = prepare(c, sources, snapshot)
            permute(work, options.seconds, options.jobs)
        except (subprocess.CalledProcessError, RuntimeError) as error:
            failures.append(c['function'])
            print(f'{c["function"]}: {error}', file=sys.stderr)
    if failures:
        raise RuntimeError('Failed inputs: ' + ', '.join(failures))
    print('Results only; no source changes or commits. Verify any proposed match with objdiff and full-ROM SHA-1.')


if __name__ == '__main__':
    try:
        main()
    except (subprocess.CalledProcessError, RuntimeError) as error:
        sys.exit(str(error))
