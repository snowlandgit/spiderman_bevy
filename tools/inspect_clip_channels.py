import struct,json,zlib
from extract_assets import ROOT,sections
crc=lambda s:zlib.crc32(s.encode(),0x12477cdf)^0xffffffff
bones=json.loads((ROOT/'research/spiderman_base_skeleton.json').read_text());names={e['hash']:e['name'] for e in bones}
for path in (ROOT/'assets/source/characters/hero/hero_spiderman/animations').rglob('*idle*.animclip'):
 b=path.read_bytes();s=sections(b[b.find(b'1TAD'):]);print('Tags',[(hex(k),len(v)) for k,v in s.items()]);header=struct.unpack_from('<IIIffBBBBIIHHIIHHHHHHHHHHfIIII12s',s[crc('Anim Clip Built')]);print('header',header)
 hashes=struct.unpack('<'+'I'*(len(s[crc('Anim Clip Joint Hashes')])//4),s[crc('Anim Clip Joint Hashes')]);base=s[crc('Anim Clip Base State')];print('jointcount',len(hashes),'missing', [e['name'] for e in bones if e['hash'] not in hashes])
 for i,h in enumerate(hashes):
  name=names.get(h,hex(h))
  if name.startswith('LF_loarm') or name in ['LF_wrist','LF_upleg','LF_loleg','LF_foot']:
   q=struct.unpack_from('<8h',base,16*i);print(i,name,q)
