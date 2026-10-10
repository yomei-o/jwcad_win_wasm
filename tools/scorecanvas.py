"""採点を図面の窓だけに絞る（ツールバー・状態行は見ない）。

    python tools/scorecanvas.py [tmp/refs]

`tools/scoreall.sh` は枠ぜんぶを比べるので、原典の参照を撮った時の
ツールバーの状態が違うと数万画素ずれて見える（2026-10-10、Windows 11 の
本機で d09 以降）。ここは図面の窓（クライアント 1264×741 のうち
x 78..1185、y 34..719）の中だけを、文字の領域を除いて数える。
"""
import glob
import os
import sys
from PIL import Image

X0, Y0, X1, Y1 = 78, 34, 1186, 720


def rects(path):
    out = []
    if os.path.exists(path):
        for l in open(path, encoding='utf-8', errors='replace'):
            f = l.split('#')[0].split()
            if len(f) >= 4:
                try:
                    out.append(tuple(int(v) for v in f[:4]))
                except ValueError:
                    pass
    return out


def main():
    refs = sys.argv[1] if len(sys.argv) > 1 else 'tmp/refs'
    tot = 0
    for r in sorted(glob.glob(os.path.join(refs, 'd*.png'))):
        n = os.path.basename(r)[:-4]
        o = 'tmp/%s.out.png' % n
        if not os.path.exists(o):
            continue
        a = Image.open(r).convert('RGB')
        b = Image.open(o).convert('RGB')
        masks = rects('docs/textareas.txt') + rects('tmp/%s.out.png.mask' % n)
        pa, pb = a.load(), b.load()
        bad = 0
        for y in range(Y0, Y1):
            for x in range(X0, X1):
                if pa[x, y] != pb[x, y]:
                    if any(mx <= x < mx + mw and my <= y < my + mh
                           for mx, my, mw, mh in masks):
                        continue
                    bad += 1
        tot += bad
        print('%-4s %8d' % (n, bad))
    print('total %d' % tot)


main()
