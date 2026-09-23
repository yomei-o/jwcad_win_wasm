"""Make a DXF of the entities a drawing of lines does not exercise, to ask the
original what it makes of them.

    python tools/mkdxfin.py decomp/res/text.dxf

The prologue -- the header, the tables and the layers -- is lifted from
decomp/res/pens.dxf, which the original wrote, so the only new thing in the
file is the entities.  tools/refanswers.sh then has the original open this and
save it, and tests/dxfread_test.c holds what src/dxfread.c makes of it
against that.
"""
import io
import sys

SRC = 'decomp/res/pens.dxf'


def g(code, val):
    return ('%3d\r\n%s\r\n' % (code, val)).encode('cp932')


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else 'decomp/res/text.dxf'
    src = io.open(SRC, 'rb').read()
    i = src.index(b'ENTITIES\r\n') + len(b'ENTITIES\r\n')
    head = src[:i]
    j = src.index(b'  8\r\n', i) + 5
    layer = src[j:src.index(b'\r\n', j)]

    # place, height, how wide the letters are against it, turn, text
    cases = [
        (64100, 61400, 500, 1.0, 0.0, 'ABC'),
        (64100, 66400, 1000, 1.0, 30.0, 'abc123'),
        (64100, 71400, 500, 0.5, 0.0, 'thin'),
        (64100, 76400, 500, 2.0, -45.0, 'wide'),
        (74100, 61400, 300, 1.0, 90.0, '日本語'),
        (84100, 61400, 250, 1.0, 180.0, '日本語abc'),
    ]
    body = []
    for x, y, h, wf, rot, s in cases:
        body.append(g(0, 'TEXT'))
        body.append(b'  8\r\n' + layer + b'\r\n')
        body.append(('%3d\r\n%5d\r\n' % (62, 5)).encode())
        body.append(g(10, x) + g(20, y) + g(40, h) + g(41, wf) + g(50, rot))
        body.append(('  1\r\n%s\r\n' % s).encode('cp932'))
    body.append(g(0, 'ENDSEC') + g(0, 'EOF'))
    io.open(out, 'wb').write(head + b''.join(body))
    print('%s: %d texts' % (out, len(cases)))


if __name__ == '__main__':
    main()
