from pathlib import Path
import struct,json,sys
root=Path(__file__).resolve().parents[1];sys.path.insert(0,str(root/'tools/python_deps'));import pefile;from capstone import *
b=(root.parent/'Spider-Man.exe').read_bytes();pe=pefile.PE(data=b,fast_load=True)
def crc(s):
 n=0xedb88320
 for x in s.encode():
  n^=x
  for _ in range(8):n=(n>>1)^(0xedb88320 if n&1 else 0)
 return n
names={}
for p in (root/'assets/tuning').glob('*.json'):
 def walk(v):
  if isinstance(v,dict):
   for k,x in v.items():names[crc(k)]=k;walk(x)
  elif isinstance(v,list):
   for x in v:walk(x)
 walk(json.loads(p.read_text()))
for at,count in [(0x3ac93a0,32),(0x3ac79a0-8,32),(0x3ac9160,8)]:
 print('FIELDS',hex(at))
 for i in range(count):
  x=struct.unpack_from('<I',b,at+i*4)[0];print(hex(i*4),hex(x),names.get(x,''))
 print('NEIGHBORS',b[at-64:at].hex(' '),b[at+count*4:at+count*4+160].hex(' '))
cs=Cs(CS_ARCH_X86,CS_MODE_64)
for addr in [0x1402c2450,0x140876340]:
 print('DISASM',hex(addr))
 for ins in cs.disasm(pe.get_data(addr-pe.OPTIONAL_HEADER.ImageBase,180),addr):
  print(ins.mnemonic,ins.op_str)
  if ins.mnemonic=='ret':break
c=json.loads((root/'research/native_constants.json').read_text());print('CONSTANTS', {h:c.get(h) for h in ['143848d00','14387e6ac','14382ee94','14382ee8c']})
