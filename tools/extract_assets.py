"""Read-only MSMR archive extractor. Formats: Tkachov/Overstrike (GPL-3.0)."""
import argparse,bisect,hashlib,json,re,struct,zlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
GAME=ROOT.parent

def sections(data):
    assert struct.unpack_from('<I',data)[0]==0x44415431
    return {t:data[o:o+s] for t,o,s in (struct.unpack_from('<III',data,16+i*12) for i in range(struct.unpack_from('<H',data,12)[0]))}

def lz4(data,expected):
    out=bytearray(); at=0
    while at<len(data):
        token=data[at]; at+=1; length=token>>4
        if length==15:
            while True:
                n=data[at]; at+=1; length+=n
                if n!=255: break
        out.extend(data[at:at+length]); at+=length
        if at>=len(data): break
        offset=struct.unpack_from('<H',data,at)[0]; at+=2
        assert 0<offset<=len(out)
        length=(token&15)+4
        if (token&15)==15:
            while True:
                n=data[at]; at+=1; length+=n
                if n!=255: break
        while length:
            n=min(length,offset); start=len(out)-offset
            out.extend(out[start:start+n]); length-=n
    assert len(out)==expected,(len(out),expected)
    return out

class Archives:
    def __init__(self):
        b=(GAME/'asset_archive/toc').read_bytes()
        assert struct.unpack_from('<I',b)[0]==0x77AF12AF
        # This shipped TOC omits a zlib trailer; validate the full DAT1 size instead.
        d=zlib.decompressobj().decompress(b[8:])
        assert len(d)==struct.unpack_from('<I',d,8)[0]
        s=sections(d)
        self.ids=[x[0] for x in struct.iter_unpack('<Q',s[0x506D7B8A])]
        self.offsets=list(struct.iter_unpack('<II',s[0xDCD720B5]))
        self.sizes=[x[1] for x in struct.iter_unpack('<III',s[0x65BCF461])]
        self.spans=list(struct.iter_unpack('<II',s[0xEDE8ADA9]))
        a=s[0x398ABFF0]
        self.archives=[a[i+8:i+72].split(b'\0')[0].decode() for i in range(0,len(a),72)]
        self.names={}; self.by_name={}
        for line in (ROOT/'tools/hashes.txt').read_text(encoding='utf-8-sig').splitlines():
            p=line.split(',')
            if len(p)>=2:
                key=int(p[0],16); name=p[1].replace('\\','/').lower()
                self.names[key]=name; self.by_name[name]=key
        self.indices={}
        for span,(start,count) in enumerate(self.spans):
            for i in range(start,start+count): self.indices.setdefault(self.ids[i],[]).append((span,i))
        self.block_tables={}; self.block_cache={}
    def available(self,pattern):
        r=re.compile(pattern)
        return sorted(n for k,n in self.names.items() if k in self.indices and r.search(n))
    def read(self,key,span=None):
        _,i=next((s,i) for s,i in self.indices[key] if span is None or s==span)
        ai,offset=self.offsets[i]; size=self.sizes[i]
        archive=GAME/'asset_archive'/self.archives[ai]
        assert archive.resolve().is_relative_to((GAME/'asset_archive').resolve())
        with archive.open('rb') as f:
            if f.read(4)!=b'DSAR': f.seek(offset); return f.read(size)
            if ai not in self.block_tables:
                f.seek(12); end=struct.unpack('<I',f.read(4))[0]; f.seek(32)
                table=[struct.unpack('<QQIIB7x',f.read(32)) for _ in range((end-32)//32)]
                self.block_tables[ai]=(table,[x[0] for x in table])
            table,starts=self.block_tables[ai]; first=max(0,bisect.bisect_right(starts,offset)-1); out=bytearray()
            for bi in range(first,len(table)):
                ro,co,rs,cs,kind=table[bi]
                if ro>=offset+size: break
                ck=(ai,bi)
                if ck not in self.block_cache:
                    f.seek(co); compressed=f.read(cs)
                    if kind==3: block=lz4(compressed,rs)
                    elif kind==0: block=compressed
                    else: raise ValueError(f'Unsupported DSAR compression {kind} in {archive.name}')
                    if len(self.block_cache)>128: self.block_cache.clear()
                    self.block_cache[ck]=block
                block=self.block_cache[ck]
                out.extend(block[max(offset,ro)-ro:min(offset+size,ro+rs)-ro])
            assert len(out)==size,(len(out),size)
            return bytes(out)
    def extract(self,name,span=None):
        key=self.by_name[name]; data=self.read(key,span)
        dest=ROOT/'assets/source'/name
        assert dest.resolve().is_relative_to((ROOT/'assets/source').resolve())
        dest.parent.mkdir(parents=True,exist_ok=True); dest.write_bytes(data)
        return {'path':name,'hash':f'{key:016X}','bytes':len(data),'sha256':hashlib.sha256(data).hexdigest(),'spans':self.indices[key]}

def main():
    p=argparse.ArgumentParser(); p.add_argument('--list'); p.add_argument('--extract',nargs='*'); p.add_argument('--selection',type=Path); args=p.parse_args()
    a=Archives()
    if args.list:
        for name in a.available(args.list): print(name)
    selection=args.extract or []
    if args.selection: selection+=json.loads(args.selection.read_text())
    if selection:
        manifest=[]
        for name in selection:
            record=a.extract(name); manifest.append(record); print(record['bytes'],name,flush=True)
        (ROOT/'assets/source_manifest.json').write_text(json.dumps(manifest,indent=2))
if __name__=='__main__': main()
