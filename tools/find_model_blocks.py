import itertools,struct,re
from pathlib import Path
from extract_assets import ROOT,sections

def crc(t):
    v=0xedb88320
    for b in t.encode():
        v^=b
        for _ in range(8): v=(v>>1)^(0xedb88320 if v&1 else 0)
    return v
b=(ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model').read_bytes(); d=b[b.find(b'1TAD'):]; s=sections(d)
words=['Vertex','Vert','Vtx','Position','Positions','Normal','Normals','Tangent','Tangents','Uv','UV','Color','Colour','Data','Buffer','Standard','Stream','Indices','Index','Skin','Weight','Weights','Blend','Cluster','Clusters','Subset','Geometry','Geom','Render','Built','Info','TexCoord','Texcoord','Texcoords','Uv0','Uv1','Uv2','UV0','UV1','UV2','Joint','Matrix','Matrices','Inverse','Bind','Pose','Anim','Morph','Float','Compressed','Packed','Short','Half','Mirror','Ids','Leaf']
found={}
for n in range(1,4):
    for combo in itertools.product(words,repeat=n):
        name='Model '+' '.join(combo); key=crc(name)
        if key in s: found[key]=name
for k,n in sorted(found.items()): print(hex(k),n,len(s[k]))
(ROOT/'tools/model_block_names.json').write_text(json.dumps({hex(k):v for k,v in found.items()},indent=2))
sub=s[crc('Model Subset')]
for i in range(4):
    print('SUBSET',i)
    for j in range(0,64,4): print(j,sub[i*64+j:i*64+j+4].hex(),struct.unpack_from('<I',sub,i*64+j)[0],struct.unpack_from('<f',sub,i*64+j)[0])
