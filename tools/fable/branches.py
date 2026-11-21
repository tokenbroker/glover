# usage: FN= UNIT= SCRATCH= python3 -I tools/fable/branches.py -> rows where the branch/jump/call instruction itself differs (structure, not registers)
import re, sys; sys.path.insert(0,'tools/fable'); import common
li,ri=common.load(); br=re.compile(r'^(b\w*|j|jal)\b'); n=0
for k,(a,b) in enumerate(zip(li,ri)):
    if (a.get('diff_kind') or 'none')=='none' and (b.get('diff_kind') or 'none')=='none': continue
    ia=(a.get('instruction') or {}).get('formatted',''); ib=(b.get('instruction') or {}).get('formatted','')
    ma=ia.split()[0] if ia else '-'; mb=ib.split()[0] if ib else '-'
    if (br.match(ma) or br.match(mb)) and ma!=mb: n+=1; print(f'{k:5d} {ia:40s} | {ib}')
print('branch-mnemonic mismatches', n)
