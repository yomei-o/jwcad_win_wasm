#!/usr/bin/env python3
"""Longest horizontal dark run in the view of a tools/jwdraw.ps1 `shot:` PNG
(a line drawn across the paper): x0 x1 y length.  For reading the zoom."""
import sys
from PIL import Image

for path in sys.argv[1:]:
    im = Image.open(path).convert('L')
    w, h = im.size
    px = im.load()
    best = (0, 0, 0, 0)
    for y in range(86, min(h, 770)):
        run = 0
        for x in range(88, min(w, 1192)):
            if px[x, y] < 100:
                run += 1
                if run > best[3]:
                    best = (x - run + 1, x, y, run)
            else:
                run = 0
    print(path, 'x0=%d x1=%d y=%d len=%d' % best)
