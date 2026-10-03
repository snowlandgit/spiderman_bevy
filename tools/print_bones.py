from pathlib import Path
p=Path(__file__).resolve().parents[1]
it=iter((p/'tools/character.ascii').read_text().splitlines());n=int(next(it));bs=[]
for i in range(n):
 name=next(it);parent=int(next(it));coords=list(map(float,next(it).split()));bs.append((name,parent,coords))
for i,(name,parent,coords) in enumerate(bs):
 if name.startswith('LF_') or name in ['a_body','hips','root']:
  print(i,name,'parent',bs[parent][0] if parent>=0 else '', 'xyzq',','.join(f'{f:.3f}' for f in coords))
