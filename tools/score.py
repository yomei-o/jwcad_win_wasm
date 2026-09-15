"""Score the port against the reference screens, drawing area and frame apart.

    python tools/score.py [refdir]

The drawing area is scored without the rectangles the text falls in -- the
glyphs are a different typeface and cannot match -- and the frame without
docs/textareas.txt, which covers the menu, the buttons and the status line.
"""
import sys
from PIL import Image, ImageDraw

VIEW = (78, 34, 1186, 720)


def rects(path):
    out = []
    for line in open(path):
        line = line.split('#')[0]
        p = line.split()
        if len(p) < 4:
            continue
        try:
            out.append([int(v) for v in p[:4]])
        except ValueError:
            pass
    return out


def mask(size, paths):
    m = Image.new('1', size, 0)
    d = ImageDraw.Draw(m)
    for p in paths:
        for x, y, w, h in rects(p):
            d.rectangle([x, y, x + w, y + h], fill=1)
    return m.load()


def main():
    refdir = sys.argv[1] if len(sys.argv) > 1 else 'tmp/refs'
    print('%-5s %10s %10s %10s' % ('', 'drawing', 'frame', 'total'))
    tv = tf = 0
    for i in range(1, 16):
        n = 'd%02d' % i
        a = Image.open('%s/%s.png' % (refdir, n)).convert('RGB')
        b = Image.open('tmp/%s.out.png' % n).convert('RGB')
        mv = mask(a.size, ['tmp/%s.out.png.mask' % n])
        mf = mask(a.size, ['docs/textareas.txt'])
        ap, bp = a.load(), b.load()
        v = f = 0
        for y in range(a.size[1]):
            for x in range(a.size[0]):
                inview = VIEW[0] <= x < VIEW[2] and VIEW[1] <= y < VIEW[3]
                if mv[x, y] if inview else mf[x, y]:
                    continue
                if (ap[x, y] != (255, 255, 255)) != (bp[x, y] != (255, 255, 255)):
                    if inview:
                        v += 1
                    else:
                        f += 1
        tv += v
        tf += f
        print('%-5s %10d %10d %10d' % (n, v, f, v + f))
    print('%-5s %10d %10d %10d' % ('all', tv, tf, tv + tf))


main()
