"""Make a DXF of the entities a drawing of lines does not exercise, to ask the
original what it makes of them.

    python tools/mkdxfin.py text   decomp/res/text.dxf
    python tools/mkdxfin.py poly   decomp/res/poly.dxf
    python tools/mkdxfin.py ellipse decomp/res/ell.dxf
    python tools/mkdxfin.py hatch  decomp/res/hat.dxf
    python tools/mkdxfin.py insert decomp/res/ins.dxf

The prologue -- the header, the tables and the layers -- is lifted from
decomp/res/pens.dxf, which the original wrote, so the only new thing in the
file is the entities.  tools/refanswers.sh then has the original open these
and save them, and tests/dxfread_test.c holds what src/dxfread.c makes of
them against that.
"""
import io
import sys

SRC = 'decomp/res/pens.dxf'


def g(code, val):
    return ('%3d\r\n%s\r\n' % (code, val)).encode('cp932')


def i5(code, val):
    return ('%3d\r\n%5d\r\n' % (code, val)).encode()


def prologue():
    src = io.open(SRC, 'rb').read()
    i = src.index(b'ENTITIES\r\n') + len(b'ENTITIES\r\n')
    j = src.index(b'  8\r\n', i) + 5
    return src[:i], src[j:src.index(b'\r\n', j)]


def texts(lay):
    # place, height, how wide the letters are against it, turn, text
    cases = [
        (64100, 61400, 500, 1.0, 0.0, 'ABC'),
        (64100, 66400, 1000, 1.0, 30.0, 'abc123'),
        (64100, 71400, 500, 0.5, 0.0, 'thin'),
        (64100, 76400, 500, 2.0, -45.0, 'wide'),
        (74100, 61400, 300, 1.0, 90.0, '日本語'),
        (84100, 61400, 250, 1.0, 180.0, '日本語abc'),
    ]
    out = []
    for x, y, h, wf, rot, s in cases:
        out.append(g(0, 'TEXT') + lay + i5(62, 5))
        out.append(g(10, x) + g(20, y) + g(40, h) + g(41, wf) + g(50, rot))
        out.append(('  1\r\n%s\r\n' % s).encode('cp932'))
    return b''.join(out)


def polys(lay):
    out = []
    for close, pts in ((0, [(64100, 61400), (68100, 65400), (72100, 61400)]),
                       (1, [(76100, 61400), (80100, 65400), (84100, 61400)])):
        out.append(g(0, 'LWPOLYLINE') + lay + g(6, 'CONTINUOUS') + i5(62, 3))
        out.append(i5(90, len(pts)) + i5(70, close))
        for x, y in pts:
            out.append(g(10, x) + g(20, y))
    out.append(g(0, 'POLYLINE') + lay + g(6, 'CONTINUOUS') + i5(62, 4)
               + i5(66, 1))
    for x, y in [(64100, 71400), (68100, 75400), (72100, 71400),
                 (76100, 75400)]:
        out.append(g(0, 'VERTEX') + lay + g(10, x) + g(20, y))
    out.append(g(0, 'SEQEND') + lay)
    return b''.join(out)


def block(lay):
    """The BLOCKS section a reference needs, to splice into the prologue."""
    out = [g(0, 'BLOCK') + lay + g(2, 'SQ') + i5(70, 0)
           + g(10, 0) + g(20, 0) + g(3, 'SQ')]
    for x0, y0, x1, y1 in ((0, 0, 2000, 0), (2000, 0, 2000, 2000),
                           (2000, 2000, 0, 2000), (0, 2000, 0, 0)):
        out.append(g(0, 'LINE') + lay + g(6, 'CONTINUOUS') + i5(62, 3)
                   + g(10, x0) + g(20, y0) + g(11, x1) + g(21, y1))
    out.append(g(0, 'ENDBLK') + lay)
    return b''.join(out)


def inserts(lay):
    out = []
    for x, y, sx, sy, rot in ((64100, 61400, 1, 1, 0),
                              (74100, 61400, 2, 2, 45),
                              (84100, 61400, 1, 2, 0)):
        out.append(g(0, 'INSERT') + lay + i5(62, 5) + g(2, 'SQ')
                   + g(10, x) + g(20, y) + g(41, sx) + g(42, sy) + g(50, rot))
    return b''.join(out)


def ellipses(lay):
    """centre, the longer half axis as an offset, how flat, the two ends"""
    out = []
    for cx, cy, mx, my, flat, t0, t1 in (
            (64100, 61400, 6000, 0, 0.5, 0, 6.283185307179586),
            (78100, 61400, 0, 6000, 0.25, 0, 3.141592653589793),
            (92100, 61400, 4000, 4000, 0.5, 0.5, 4.0)):
        out.append(g(0, 'ELLIPSE') + lay + g(6, 'CONTINUOUS') + i5(62, 3)
                   + g(10, cx) + g(20, cy) + g(11, mx) + g(21, my)
                   + g(40, flat) + g(41, t0) + g(42, t1))
    return b''.join(out)


def mtexts(lay):
    """MTEXT names the top of the line, not the foot of it"""
    out = []
    for x, y, h, rot, t in ((64100, 61400, 500, 0, 'MTEXT one'),
                            (64100, 71400, 800, 30, '\u65e5\u672c\u8a9e MT')):
        out.append(g(0, 'MTEXT') + lay + i5(62, 3) + g(10, x) + g(20, y)
                   + g(40, h) + g(41, 0) + g(50, rot) + i5(71, 1))
        out.append(('  1\r\n%s\r\n' % t).encode('cp932'))
    return b''.join(out)


def dims(lay):
    """A dimension names a block that holds what it draws."""
    return (g(0, 'DIMENSION') + lay + i5(62, 3) + g(2, '*D1')
            + g(10, 84100) + g(20, 71400) + i5(70, 0)
            + g(13, 64100) + g(23, 61400) + g(14, 104100) + g(24, 61400)
            + g(1, '40.00'))


def dimblock(lay):
    out = [g(0, 'BLOCK') + lay + g(2, '*D1') + i5(70, 1)
           + g(10, 0) + g(20, 0) + g(3, '*D1')]
    for x0, y0, x1, y1 in ((64100, 61400, 104100, 61400),
                           (64100, 61400, 64100, 71400),
                           (104100, 61400, 104100, 71400)):
        out.append(g(0, 'LINE') + lay + g(6, 'CONTINUOUS') + i5(62, 3)
                   + g(10, x0) + g(20, y0) + g(11, x1) + g(21, y1))
    out.append(g(0, 'ENDBLK') + lay)
    return b''.join(out)


def hatches(lay):
    """HATCH, the way AutoCAD lays one out.

    The original only takes a 塗りつぶし (a pattern named SOLID): it starts
    keeping the corners at the `2 SOLID` and stops at the `98` that counts
    the seed points, so the elevation point in front and the seed points
    behind are not corners.  Two shapes of boundary are tried -- a closed
    polyline (92 with bit 2) and one edge per side (72 of 1) -- and one with
    three corners rather than four, to see what the fourth becomes.
    """
    def head(x, y):
        return (g(0, 'HATCH') + lay + i5(62, 5)
                + g(10, x) + g(20, y) + g(30, 0)      # elevation, not a corner
                + g(2, 'SOLID') + i5(70, 1) + i5(71, 0) + i5(91, 1))

    def tail(x, y):
        return (i5(97, 0) + i5(75, 0) + i5(76, 1) + i5(98, 1)
                + g(10, x) + g(20, y))                # the seed, not a corner

    out = []
    # a square, as a closed polyline boundary
    pts = [(64100, 61400), (70100, 61400), (70100, 67400), (64100, 67400)]
    out.append(head(64100, 61400) + i5(92, 7) + i5(72, 0) + i5(73, 1)
               + i5(93, len(pts)))
    for x, y in pts:
        out.append(g(10, x) + g(20, y))
    out.append(tail(67100, 64400))
    # the same shape a bit along, as four line edges
    pts = [(74100, 61400), (80100, 61400), (80100, 67400), (74100, 67400)]
    out.append(head(74100, 61400) + i5(92, 1) + i5(93, len(pts)))
    for i in range(len(pts)):
        x0, y0 = pts[i]
        x1, y1 = pts[(i + 1) % len(pts)]
        out.append(i5(72, 1) + g(10, x0) + g(20, y0) + g(11, x1) + g(21, y1))
    out.append(tail(77100, 64400))
    # and a triangle, to see what the fourth corner becomes
    pts = [(84100, 61400), (90100, 61400), (87100, 67400)]
    out.append(head(84100, 61400) + i5(92, 7) + i5(72, 0) + i5(73, 1)
               + i5(93, len(pts)))
    for x, y in pts:
        out.append(g(10, x) + g(20, y))
    out.append(tail(87100, 63400))
    return b''.join(out)


def main():
    kind = sys.argv[1] if len(sys.argv) > 1 else 'text'
    out = sys.argv[2] if len(sys.argv) > 2 else 'decomp/res/%s.dxf' % kind
    head, lay = prologue()
    lay = b'  8\r\n' + lay + b'\r\n'
    if kind == 'text':
        body = texts(lay)
    elif kind == 'poly':
        body = polys(lay)
    elif kind == 'mtext':
        body = mtexts(lay)
    elif kind == 'ellipse':
        body = ellipses(lay)
    elif kind == 'hatch':
        body = hatches(lay)
    elif kind == 'dim':
        head = head.replace(b'  2\r\nBLOCKS\r\n',
                            b'  2\r\nBLOCKS\r\n' + dimblock(lay), 1)
        body = dims(lay)
    elif kind == 'insert':
        head = head.replace(b'  2\r\nBLOCKS\r\n',
                            b'  2\r\nBLOCKS\r\n' + block(lay), 1)
        body = inserts(lay)
    else:
        print('which: text, mtext, poly, ellipse, hatch, insert or dim')
        return
    io.open(out, 'wb').write(head + body + g(0, 'ENDSEC') + g(0, 'EOF'))
    print('%s: %s' % (out, kind))


if __name__ == '__main__':
    main()
