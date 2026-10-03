import json
from pathlib import Path
p=Path(__file__).resolve().parents[1]/'research/controller_comparison.json';d=json.loads(p.read_text())
for scenario in ['held','dive_entry','normal_release','jump_release']:
 r=d['scenarios'][scenario]['revised'];print(scenario,{k:v for k,v in r.items() if k!='trace'})
 last=''
 for row in r['trace']:
  if row['mode']!=last or row['time']<1.1:
   print(round(row['time'],2),row['mode'],'pos',*[round(x,2) for x in row['position']],'vel',*[round(x,2) for x in row['velocity']],'phase',round(row['phase'],2),'mom',round(row['momentum'],2),'pivot',row['pivot'])
  last=row['mode']
