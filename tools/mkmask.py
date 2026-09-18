#!/usr/bin/env python3
"""Move docs/textareas.txt to another client size.

    python tools/mkmask.py docs/textareas.txt 1484 841 tests/out/mask_big.txt

The frame is measured at 1264x741; at any other size the right-hand bar and
everything in it rides the right edge and the status line rides the bottom
(src/ui.h says how that was read out of the original).  The rectangles that
mark where text is drawn have to move the same way, or they would no longer
cover it.
"""
import sys

REF_W, REF_H = 1264, 741
RIGHT_X, BOTTOM_Y = 1188, 720


def main():
    src, cw, ch, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
    dw, dh = cw - REF_W, ch - REF_H
    o = open(out, 'w', encoding='utf-8', newline='\n')
    o.write('# %s moved to %dx%d by tools/mkmask.py\n' % (src, cw, ch))
    for line in open(src, encoding='utf-8'):
        line = line.split('#')[0].strip()
        if not line:
            continue
        x, y, w, h = (int(v) for v in line.split()[:4])
        if x >= RIGHT_X:
            x += dw
        if y >= BOTTOM_Y:
            y += dh
            w += dw             # the status line is as wide as the client
        o.write('%d %d %d %d\n' % (x, y, w, h))
    o.close()
    print('wrote', out)


main()
