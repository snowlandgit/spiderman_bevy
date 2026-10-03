import sys,re,struct,json,math
from pathlib import Path
root=Path(__file__).resolve().parents[1];sys.path.insert(0,str(root/'tools/python_deps'));import pefile
pe=pefile.PE(str(root.parent/'Spider-Man.exe'),fast_load=True);code=(root/'research/swing_core_decompiled.c').read_text();values={}
for h in set(re.findall(r'_DAT_([0-9a-f]+)',code)):
 try:
  raw=pe.get_data(int(h,16)-pe.OPTIONAL_HEADER.ImageBase,4);u=struct.unpack('<I',raw)[0];f=struct.unpack('<f',raw)[0];values[h]={'bits':hex(u),'float':f if math.isfinite(f) else None}
 except Exception:pass
(root/'research/native_constants.json').write_text(json.dumps(values,indent=2))
for addr in ['140ab4450','140abf160','140ac0b60','140abf580','140abf850','140ac04f0','140abc8c0','140ab38e0','140ac1680','140ac2200','140abd610']:
 m=re.search(r'/\* SwingRegion_'+addr+r' @.*?(?=/\* SwingRegion_|\Z)',code,re.S)
 if not m:continue
 def replace(m):
  v=values.get(m[1]);return m[0]+(' /* '+str(v['float'])+', '+v['bits']+' */' if v else '')
 out=re.sub(r'_DAT_([0-9a-f]+)',replace,m[0]);(root/'research'/f'native_{addr}.c').write_text(out)
 if addr in ['140ac0b60','140ab4450']:print(out)
