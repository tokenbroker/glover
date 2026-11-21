# usage: FN= UNIT= SCRATCH= python3 -I tools/fable/rowsrc.py A B [only] -> rows A..B (target | ours) with the draft line of our instruction
import sys; sys.path.insert(0,'tools/fable'); import common
li,ri=common.load(); a2l=common.addr2line(); draft=common.draft_lines()
a0,a1=int(sys.argv[1]),int(sys.argv[2]); only=len(sys.argv)>3; last=None
for k in range(a0,min(a1,len(li))):
    a=li[k]; b=ri[k]; ia=a.get('instruction') or {}; ib=b.get('instruction') or {}
    bad=(a.get('diff_kind') or 'none')!='none' or (b.get('diff_kind') or 'none')!='none'
    if only and not bad: continue
    dl=a2l.get(int(ib.get('address',0))) if ib else None
    print(f"{k:5d} {'*' if bad else ' '} {ia.get('formatted',''):36s} | {ib.get('formatted',''):36s} L{dl if dl else '-'}")
    if dl and dl!=last: print(f"          >> {draft[dl-1][:120]}"); last=dl
