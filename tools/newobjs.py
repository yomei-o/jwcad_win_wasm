"""原典が引かせた図面で、下敷きの図面に無い要素を一行ずつ読みやすく出す。

    python tools/newobjs.py decomp/res/new.jww tmp/answer.jww
"""
import re
import subprocess
import sys

out = subprocess.run([sys.executable, 'tools/whatdid.py', sys.argv[1], sys.argv[2]],
                     capture_output=True, text=True, encoding='utf-8').stdout
for l in out.splitlines():
    m = re.search(r'CData(\w+)', l)
    if not m:
        print(l)
        continue
    if 'x0=' in l:
        g = re.search(r'x0=(\S+) x1=(\S+) y0=(\S+) y1=(\S+)', l).groups()
        print('%s%s (%.4f,%.4f)-(%.4f,%.4f)' % (l[0], m.group(1), float(g[0]), float(g[2]), float(g[1]), float(g[3])))
    elif 'd=[' in l:
        d = re.search(r'd=\[([^\]]*)\]', l).group(1)
        print('%s%s d=[%s]' % (l[0], m.group(1), ' '.join('%.4f' % float(v) for v in d.split())))
    elif 'pts=' in l:
        d = re.search(r'pts=\[([^\]]*)\]', l).group(1)
        print('%s%s pts=[%s]' % (l[0], m.group(1), ' '.join('%.4f' % float(v) for v in d.split())))
    else:
        print(l[:120])
