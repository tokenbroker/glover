import os
import sys, json, urllib.request, subprocess
fn=sys.argv[1]; path=sys.argv[2]
url=subprocess.check_output([os.path.expanduser('~/.local/bin/decomp'),'url'],text=True).strip(); key=url.split('k=')[1]; base=url.split('/?')[0]; hostport=base.split('//')[1]
H={'Content-Type':'application/json','Cookie':f'decomp_live={key}','x-decomp':'1','Host':hostport}
live=json.loads(urllib.request.urlopen(urllib.request.Request(base+'/api/live?slug=glover',headers=H),timeout=30).read())
holders=[c for c in live.get('claims',[]) if c.get('function')==fn or c.get('name')==fn]
if holders: print('claimed:', holders); sys.exit(1)
src=open(path).read()
req=urllib.request.Request(base+'/api/try?slug=glover', data=json.dumps({'name':fn,'source':src}).encode(), headers=H, method='POST')
try:
    with urllib.request.urlopen(req, timeout=1500) as r: res=json.loads(r.read())
except urllib.error.HTTPError as e: print('HTTP', e.code, e.read()[:400]); sys.exit(1)
print(fn, 'judge:', (res.get('text') or '')[:2500].replace('\n',' | '), 'score', res.get('score'), 'pct', res.get('percent'))
urllib.request.urlopen(urllib.request.Request(base+'/api/release?slug=glover', data=json.dumps({'name':fn}).encode(), headers=H, method='POST'), timeout=60).read(); print('released')
