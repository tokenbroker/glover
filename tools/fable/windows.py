# usage: FN= UNIT= SCRATCH= python3 -I tools/fable/windows.py [W] -> W-row windows ranked by mismatches
import sys; sys.path.insert(0,'tools/fable'); import common
li,ri=common.load(); W=int(sys.argv[1]) if len(sys.argv)>1 else 100
bad=[(a.get('diff_kind') or 'none')!='none' or (b.get('diff_kind') or 'none')!='none' for a,b in zip(li,ri)]
wins=sorted(((sum(bad[w:w+W]),w) for w in range(0,len(bad),W)), reverse=True)
for n,w in wins[:16]: print(f'rows {w:5d}-{w+W:5d} bad {n:3d}')
print('total bad', sum(bad), 'of', len(bad))
