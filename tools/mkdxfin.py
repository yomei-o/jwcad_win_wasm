"""Make a DXF of the entities a drawing of lines does not exercise, to ask the
original what it makes of them.

    python tools/mkdxfin.py text   decomp/res/text.dxf
    python tools/mkdxfin.py poly   decomp/res/poly.dxf
    python tools/mkdxfin.py ellipse decomp/res/ell.dxf
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


def main():
    kind = sys.argv[1] if len(sys.argv) > 1 else 'text'
    out = sys.argv[2] if len(sys.argv) > 2 else 'decomp/res/%s.dxf' % kind
    head, lay = prologue()
    lay = b'  8\r\n' + lay + b'\r\n'
    if kind == 'text':
        body = texts(lay)
    elif kind == 'poly':
        body = polys(lay)
    elif kind == 'ellipse':
        body = ellipses(lay)
    elif kind == 'insert':
        head = head.replace(b'  2\r\nBLOCKS\r\n',
                            b'  2\r\nBLOCKS\r\n' + block(lay), 1)
        body = inserts(lay)
    else:
        print('which: text, poly, ellipse or insert')
        return
    io.open(out, 'wb').write(head + body + g(0, 'ENDSEC') + g(0, 'EOF'))
    print('%s: %s' % (out, kind))


if __name__ == '__main__':
    main()
