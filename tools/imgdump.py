#!/usr/bin/env python3
"""python tools/imgdump.py file.jww -- the picture elements (text starting ^@BM) with every field."""
import sys, subprocess
out = subprocess.run([sys.executable, 'tools/jww.py', sys.argv[1], '-l'], capture_output=True, text=True, encoding='utf-8', env={**__import__('os').environ, 'PYTHONIOENCODING': 'utf-8'}).stdout
for l in out.splitlines():
    if "text='^@BM" in l:
        l = l.replace('CDataMoji', 'IMG')
        l = l.replace("face='ＭＳ ゴシック' ", '').replace('f2e=0 f2f=0 ', '').replace('width=0 ', '')
        import re
        l = re.sub(r"C:\\prog\\claude2\\jwcad_win_wasm\\tmp\\img\\\\", '', l)
        print(l)
