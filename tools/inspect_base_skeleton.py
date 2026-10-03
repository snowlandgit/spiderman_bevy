import json,struct
from extract_assets import ROOT,Archives,sections
archives=Archives();name='characters/hero/hero_spiderman_base/hero_spiderman_base.model';record=archives.extract(name);p=ROOT/'assets/source_manifest.json';records={r['path']:r for r in json.loads(p.read_text())};records[name]=record;p.write_text(json.dumps(list(records.values()),indent=2))
b=(ROOT/'assets/source'/name).read_bytes();data=b[b.find(b'1TAD'):];s=sections(data);print('base model tags',[(hex(k),len(v)) for k,v in s.items()]);j=list(struct.iter_unpack('<hHHHII',s[0x15df9d3b]));rows=[]
for i,(parent,index,count,flags,h,off) in enumerate(j):
 name=data[off:data.index(b'\0',off)].decode();rows.append({'name':name,'parent':parent,'hash':h,'flags':flags,'transform':struct.unpack_from('<12f',s[0xdcc88a19],48*i)})
(ROOT/'research/base_model_skeleton.json').write_text(json.dumps(rows,indent=2));body=json.loads((ROOT/'research/spiderman_base_skeleton.json').read_text());bnames={r['name']:r for r in body};diff=[]
for r in rows:
 if r['name'] in bnames:
  bp=bnames[r['name']]['parent'];bp=body[bp]['name'] if bp>=0 else None
  np=rows[r['parent']]['name'] if r['parent']>=0 else None
  if bp!=np:diff.append((r['name'],bp,np))
print('base joints',len(rows),'parentdiff',diff)
