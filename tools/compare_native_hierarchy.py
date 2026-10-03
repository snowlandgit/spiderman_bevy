import struct,json,zlib
from extract_assets import ROOT,sections
lines=iter((ROOT/'tools/character.ascii').read_text().splitlines()); n=int(next(lines)); model={}
for i in range(n):
 name=next(lines);parent=int(next(lines));next(lines);model[name]=parent
modelnames=list(model)
for path in (ROOT/'assets/source/characters/hero/hma_master').glob('*.animset'):
 b=path.read_bytes();sec=sections(b[b.find(b'1TAD'):])[0x42F16D0C]; entries=[]
 for off in range(0,len(sec),12):
  h,s,p,f=struct.unpack_from('<IIhh',sec,off)
  if h==0xffffffff:break
  name=sec[s:sec.index(b'\0',s)].decode();entries.append({'name':name,'hash':h,'parent':p,'flags':f})
 print(path.name,'bones',len(entries))
 diff=[]
 for e in entries:
  name=e['name'];parent=entries[e['parent']]['name'] if e['parent']>=0 else None
  if name in model:
   mp=modelnames[model[name]] if model[name]>=0 else None
   if mp!=parent:diff.append((name,mp,parent))
 print('Hierarchy differences',diff)
 (ROOT/'research'/f'{path.stem}_skeleton.json').write_text(json.dumps(entries,indent=2))
