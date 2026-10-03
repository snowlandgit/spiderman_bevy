"""Decode the installed game's serialized config sections to reviewable JSON."""
import struct,json
from pathlib import Path
from extract_assets import ROOT,sections

def decode_file(path):
    raw=path.read_bytes(); base=raw.find(b'1TAD'); data=raw[base:]
    block=sections(data)[0xE501186F]; at=0
    def read(fmt):
        nonlocal at
        val=struct.unpack_from('<'+fmt,block,at); at+=struct.calcsize('<'+fmt)
        return val[0] if len(val)==1 else val
    def align():
        nonlocal at
        at=(at+3)&~3
    def node(kind):
        nonlocal at
        formats={0:'B',1:'H',2:'I',4:'b',5:'h',6:'i',8:'f',15:'?',17:'Q',19:'B'}
        if kind in formats:
            value=read(formats[kind]); return None if kind==19 else value
        if kind==13: return obj()
        if kind==10:
            length=read('I'); read('I'); read('Q')
            value=block[at:at+length].decode('utf8',errors='replace'); at+=length+1; align(); return value
        raise ValueError(f'Unknown type {kind}')
    def obj():
        nonlocal at
        zero,magic,count,length=read('IIII'); assert zero==0 and magic==0x03150044
        start=at; headers=[read('IHBB') for _ in range(count)]; offsets=[read('I') for _ in range(count)]; result={}
        for (_,flags,_,kind),offset in zip(headers,offsets):
            name=data[offset:data.index(b'\0',offset)].decode('utf8',errors='replace')
            count=flags>>4
            result[name]=[node(kind) for _ in range(count)] if count>1 else node(kind)
        align(); assert at<=start+length; at=start+length
        return result
    return obj()

if __name__=='__main__':
    for path in (ROOT/'assets/source/configs/hero').glob('*.config'):
        obj=decode_file(path); target=ROOT/'assets/tuning'/f'{path.stem}.json'; target.parent.mkdir(exist_ok=True)
        target.write_text(json.dumps(obj,indent=2)); print(target.name)
