import json, os, re, subprocess
FN=os.environ['FN']; UNIT=os.environ['UNIT']; S=os.environ['SCRATCH']
def load():
    d=json.load(open(S+'/diff.json'))
    L=next(s for s in d['left']['symbols'] if s.get('name')==FN); R=next(s for s in d['right']['symbols'] if s.get('name')==FN)
    return L['instructions'], R['instructions']
def addr2line():
    """map of our instruction address -> draft line (1-based), via objdump -dl on the compiled unit"""
    unit=open(S+'/unit_try.c').read().split('\n')
    first=next(i for i,l in enumerate(unit) if re.match(r'^[A-Za-z_][\w \*]*\b'+FN+r'\(', l))
    nm=subprocess.check_output(['mips-linux-gnu-nm',S+'/unit_try.o'],text=True)
    addr=int(next(l for l in nm.split('\n') if l.endswith(' '+FN)).split()[0],16)
    li,ri=load(); size=len([1 for b in ri if b.get('instruction')])*4
    dump=subprocess.check_output(['mips-linux-gnu-objdump','-dl',f'--start-address={addr:#x}',f'--stop-address={addr+size:#x}',S+'/unit_try.o'],text=True)
    line=None; a2l={}
    for l in dump.split('\n'):
        m=re.match(r'.*unit_try\.c:(\d+)',l)
        if m: line=int(m.group(1)); continue
        m=re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s',l)
        if m and line: a2l[int(m.group(1),16)]=line-first
    return a2l
def draft_lines():
    unit=open(S+'/unit_try.c').read().split('\n')
    first=next(i for i,l in enumerate(unit) if re.match(r'^[A-Za-z_][\w \*]*\b'+FN+r'\(', l))
    return unit[first:]
