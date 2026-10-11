#!/usr/bin/env python
"""Offline check of tools/fuzzcases/<n>.txt against the saved original answers decomp/res/fz_<n>.jww.
Needs tmp/replay.exe (tools/replay.sh).  Prints OK/ORDER/DIFF per case; no original needed."""
import os, sys, glob, re
sys.argv = [sys.argv[0]] + sys.argv[1:]
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
import difffuzz as F

bad = 0
files = sorted(glob.glob(os.path.join(F.ROOT, 'tools', 'fuzzcases', '*.txt')),
               key=lambda p: int(re.sub(r'\D', '', os.path.basename(p)) or 0))
for f in files:
    n = os.path.basename(f)[:-4]
    steps = open(f, encoding='utf-8').read().strip()
    ans = os.path.join(F.ROOT, 'decomp', 'res', 'fz_%s.jww' % n)
    if not os.path.exists(ans):
        continue
    out = F.run_port(steps, 'chk_' + n)
    A = [o for o in (F.dump(out) or []) if 'Printer_' not in o[2] and 'View_D' not in o[2] and 'Draw_B' not in o[2]]
    B = [o for o in (F.dump(ans) or []) if 'Printer_' not in o[2] and 'View_D' not in o[2] and 'Draw_B' not in o[2]]
    oa, ob, order = F.match(A, B)
    st = 'OK' if not oa and not ob and order else 'ORDER' if not oa and not ob else 'DIFF'
    if st == 'DIFF':
        bad += 1
    print(n, st, len(A), len(B))
print('diff', bad)
