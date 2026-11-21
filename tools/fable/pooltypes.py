import os
ROOT=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))  # the repo
SCR=os.environ.get('SCRATCH','/tmp/fable-scratch')  # where the pipeline's intermediate files go
# build map {(sym, off): kind} from the target asm: f64 (odd lwc1 then even lwc1 pair), f32 (even lwc1 alone), s32 (lw), s16 (lh), u8 (lbu), s8 (lb)
import re, json
f=open(ROOT+'/asm/nonmatchings/18020_1D7F0/func_8016A058.s').read().split('\n')
ins=[]
for l in f:
    m=re.search(r'\*/\s+(\w+)\s+\$(\w+), %lo\((D_8010[0-9A-F]{4})(?: \+ 0x([0-9A-F]+))?\)', l)
    if m: ins.append((m.group(1), m.group(2), m.group(3), int(m.group(4) or '0',16)))
    else: ins.append(None)
kinds={}
def reg(r): return int(r[1:]) if r.startswith('f') else None
for i,x in enumerate(ins):
    if not x: continue
    op,r,sym,off=x
    key=(sym,off)
    if op=='lwc1':
        fr=reg(r)
        if fr is not None and fr%2==1: kinds.setdefault(key,set()).add('f64')
        else:
            # even reg: part of a double if previous pool insn is odd lwc1 at addr-4 (within 3 lines)
            prev=[y for y in ins[max(0,i-3):i] if y and y[0]=='lwc1' and reg(y[1]) is not None and reg(y[1])%2==1]
            if prev and int(prev[-1][2][2:],16)+prev[-1][3]+4==int(sym[2:],16)+off: kinds.setdefault(key,set()).add('f64lo')
            else: kinds.setdefault(key,set()).add('f32')
    elif op=='ldc1': kinds.setdefault(key,set()).add('f64')
    elif op=='lw': kinds.setdefault(key,set()).add('s32')
    elif op=='lh': kinds.setdefault(key,set()).add('s16')
    elif op=='lhu': kinds.setdefault(key,set()).add('u16')
    elif op=='lb': kinds.setdefault(key,set()).add('s8')
    elif op=='lbu': kinds.setdefault(key,set()).add('u8')
out={f'{k[0]}+{k[1]}':sorted(v) for k,v in kinds.items()}
json.dump(out, open(SCR+'/pooltypes.json','w'), indent=0)
multi={k:v for k,v in out.items() if len(v)>1}
print(len(out),'pool refs;', 'conflicting:', multi)
print({k:v for k,v in out.items() if 'f64' in v})
