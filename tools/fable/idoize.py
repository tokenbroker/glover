"""Rewrite a GCC-flavoured unit so IDO's front end accepts it, keeping GCC's visible semantics:
register-asm hack stubbed, split_externs stubs and block-scope declarations hoisted to file scope (GCC's limbo rule),
volatile parameters dropped, `return f();` of a void f split, a prototype before the first use of every function
defined later, and earlier prototypes that disagree with the definition removed."""
import re, sys
sys.path.insert(0, 'tools'); import run_permuter as rp
src, dst = sys.argv[1], sys.argv[2]
u = open(src).read()
m = re.search(r'void func_801C2A4C\(u8 \*arg0, u8 \*arg1, s32 arg2\) \{\n    register u8 \*s asm\("v1"\)', u)
if m:
    j = u.index('\n}\n', m.start()) + 3
    u = u[:m.start()] + 'INCLUDE_ASM("asm/nonmatchings/18020_C0800", func_801C2A4C);\n' + u[j:]
u = re.sub(r'static inline void split_externs_[0-9A-Fa-f]+\(void\)\s*\{([^}]*)\}\n?', lambda m: '\n'.join(s.strip() for s in re.findall(r'[^;{}]+;', m.group(1))) + '\n', u)
u = re.sub(r'\bvolatile (s8|u8|s16|u16|s32|u32|f32|f64)\b(?=[^;{]*\))', r'\1', u)
void_fns = set(re.findall(r'(?m)^void (func_[0-9A-F]+)\s*\(', u))
u = re.sub(r'(?m)^([ \t]+)return (func_[0-9A-F]+)(\([^;\n]*\));[ \t]*$', lambda m: f"{m.group(1)}{m.group(2)}{m.group(3)}; return;" if m.group(2) in void_fns else m.group(0), u)
defs = rp.definitions(u)
seen = set(x.strip() for x in re.findall(r'(?m)^extern [^;]+;|^[A-Za-z_][\w \*]*\bfunc_[0-9A-F]+\([^;{]*\)\s*;', u))
inserts = []
for fn, (start, brace, end) in defs.items():
    hoist = []
    for d in re.findall(r'(?m)^\s+(extern [^;]+;|(?!return\b|else\b|if\b|while\b)[A-Za-z_][\w \*]*\bfunc_[0-9A-F]+\([^;{]*\)\s*;)', u[brace:end]):
        d = d.strip()
        if d not in seen: seen.add(d); hoist.append(d)
    if hoist: inserts.append((start, '\n'.join(hoist) + '\n'))
for pos, text in sorted(inserts, reverse=True): u = u[:pos] + text + u[pos:]
defs = rp.definitions(u)
heads = {}
for fn, (start, brace, end) in defs.items():
    h = u[start:brace].strip()
    if ';' in h[h.rfind(')'):] or h.startswith('static'): continue
    heads[fn] = h + ';'
# drop file-scope prototypes that disagree with the definition
u = re.sub(r'(?m)^([A-Za-z_][\w \*]*\b)(func_[0-9A-F]+)\s*\([^;{]*\)\s*;\n', lambda m: '' if m.group(2) in heads and m.group(0).strip() != heads[m.group(2)] else m.group(0), u)
defs = rp.definitions(u); ins2 = []
order = sorted(defs.items(), key=lambda x: x[1][0])
for fn, (start, brace, end) in order:
    if fn not in heads: continue
    # the first CALL of fn inside an earlier function's body (comments and declarations don't count)
    user = next(((f2, s2) for f2, (s2, b2, e2) in order if s2 < start and re.search(r'\b' + fn + r'\b', u[b2:e2])), None)
    if not user or heads[fn] in u[:user[1]]: continue
    ins2.append((user[1], heads[fn] + '\n'))
for pos, text in sorted(ins2, reverse=True): u = u[:pos] + text + u[pos:]
open(dst, 'w').write(u); print("idoize: hoisted groups", len(inserts), "prototypes inserted", len(ins2))

# external functions declared later than their first use: a copy of the prototype before the using function
u = open(dst).read()
defs = rp.definitions(u); order = sorted(defs.items(), key=lambda x: x[1][0]); ins3 = []
for m in re.finditer(r'(?m)^((?!static\b)[A-Za-z_][\w \*]*\b(func_[0-9A-F]+)\s*\([^;{]*\)\s*;)$', u):
    proto, name = m.group(1), m.group(2)
    if name in defs: continue
    user = next(((f2, s2) for f2, (s2, b2, e2) in order if e2 <= m.start() and re.search(r'\b' + name + r'\b', u[b2:e2])), None)
    if user and proto not in u[:user[1]]:
        ins3.append((user[1], proto + '\n'))
for pos, text in sorted(set(ins3), reverse=True): u = u[:pos] + text + u[pos:]
open(dst, 'w').write(u); print("idoize: external prototypes copied before first use:", len(set(ins3)))

# one declaration per global: IDO refuses a second extern with other qualifiers (GCC only warned)
u = open(dst).read(); seen_syms = set()
def dedupe(m):
    names = re.findall(r'\b(D_[0-9A-Fa-f]+)\b', m.group(0))
    if not names: return m.group(0)
    if all(n in seen_syms for n in names): return ''
    seen_syms.update(names); return m.group(0)
u = re.sub(r'(?m)^extern [^;]+;\n', dedupe, u)
open(dst, 'w').write(u); print("idoize: duplicate extern declarations dropped")
