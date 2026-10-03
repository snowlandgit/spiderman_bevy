from pathlib import Path
import struct
root=Path(__file__).resolve().parents[1];b=(root.parent/'Spider-Man.exe').read_bytes()
def crc(s):
 n=0xedb88320
 for x in s.encode():
  n^=x
  for _ in range(8):n=(n>>1)^(0xedb88320 if n&1 else 0)
 return n
for name in ['RisePitchAngleMin','RisePitchAngleMax','RiseTiltAngleMin','RiseHighSpeedMin','RiseGravityHighMin','RiseGravityHighMinZero','GravityFallInit','TerminalVelocityHorzMid','InSpeedCarryover','TruePivotFactorStart']:
 v=crc(name);p=struct.pack('<I',v);hits=[];start=0
 while (at:=b.find(p,start))>=0:
  hits.append(at);start=at+4
 print(name,hex(v),'literal',hex(b.find(name.encode())),'hash-offsets',*[hex(x) for x in hits[:12]])
 for at in hits[:4]:print(' ',[hex(x) for x in struct.unpack_from('<12I',b,max(0,at-16))])
