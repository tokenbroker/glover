# usage: FN= UNIT= SCRATCH= python3 -I tools/fable/lines.py [N]  (after score.sh) -> draft lines ranked by mismatching rows
import sys, collections; sys.path.insert(0,'tools/fable'); import common
N=int(sys.argv[1]) if len(sys.argv)>1 else 40
li,ri=common.load(); a2l=common.addr2line(); draft=common.draft_lines()
cnt=collections.Counter(); ex={}
for k,(a,b) in enumerate(zip(li,ri)):
    if (a.get('diff_kind') or 'none')=='none' and (b.get('diff_kind') or 'none')=='none': continue
    ib=b.get('instruction'); ia=a.get('instruction')
    if not ib: continue
    dl=a2l.get(int(ib.get('address',0)))
    if dl is None: continue
    cnt[dl]+=1; ex.setdefault(dl,[]).append(f"{k}: {(ia or {}).get('formatted','-'):34s} | {ib.get('formatted','')}")
print('attributed bad rows', sum(cnt.values()))
for dl,c in cnt.most_common(N):
    print(f"\n--- draft line {dl} ({c} bad): {draft[dl-1][:150]}")
    for e in ex[dl][:4]: print('     ', e[:120])
