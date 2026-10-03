"""Locate original swing-state vtables via PE x64 RTTI; read-only analysis."""
import struct,re,json,bisect,hashlib
from pathlib import Path
import pefile
ROOT=Path(__file__).resolve().parents[1]
b=(ROOT.parent/'Spider-Man.exe').read_bytes(); pe=pefile.PE(data=b); base=pe.OPTIONAL_HEADER.ImageBase
out=ROOT/'research'; out.mkdir(exist_ok=True)
ranges=[(x.struct.BeginAddress,x.struct.EndAddress) for x in pe.DIRECTORY_ENTRY_EXCEPTION]
starts=[x[0] for x in ranges]
def function(rva):
    i=bisect.bisect_right(starts,rva)-1
    return ranges[i] if i>=0 and ranges[i][0]<=rva<ranges[i][1] else (rva,rva+256)
records=[]
for classname in ['HeroStateSwingLocal','HeroStateSwing','HeroStateSwingJumpLocal','HeroStateSwingIntroJumpLocal','HeroRopeManager']:
    needle=('.?AV'+classname+'@Hero@@').encode()
    off=b.find(needle)
    if off<0:
        needle=('.?AV'+classname+'@@').encode(); off=b.find(needle)
    if off<0: continue
    type_rva=pe.get_rva_from_offset(off-16)
    for match in re.finditer(re.escape(struct.pack('<I',type_rva)),b):
        col_off=match.start()-12
        if col_off<0: continue
        signature,offset,cd,td,ch,self_rva=struct.unpack_from('<6I',b,col_off)
        if signature!=1 or td!=type_rva or self_rva!=pe.get_rva_from_offset(col_off): continue
        col_va=base+self_rva
        for ref in re.finditer(re.escape(struct.pack('<Q',col_va)),b):
            vt_off=ref.start()+8; methods=[]
            for index in range(48):
                va=struct.unpack_from('<Q',b,vt_off+index*8)[0]
                rva=va-base
                if not 0<=rva<pe.OPTIONAL_HEADER.SizeOfImage: break
                section=pe.get_section_by_rva(rva)
                if section is None or not section.Characteristics&0x20000000: break
                start,end=function(rva)
                methods.append({'index':index,'entry':hex(va),'start':hex(base+start),'end':hex(base+end),'size':end-start})
            if methods: records.append({'class':classname,'vtable':hex(base+pe.get_rva_from_offset(vt_off)),'offset':offset,'methods':methods})
(out/'swing_vtables.json').write_text(json.dumps({'exe_sha256':hashlib.sha256(b).hexdigest(),'image_base':hex(base),'vtables':records},indent=2))
selected={}
for r in records:
    for m in r['methods']:
        if m['size']>=80 and m['size']<30000: selected.setdefault(m['start'],r['class']+'_virtual_'+str(m['index']))
(out/'function_selection.txt').write_text('\n'.join(f'{address} {name}' for address,name in selected.items()))
print('Vtables',[(r['class'],r['vtable'],len(r['methods'])) for r in records]); print('Selected',len(selected),'functions')
