"""Make an SFC of arcs, circles and points, to ask the original what it makes
of features it does not itself write for a drawing of lines.

    python tools/mksfc.py decomp/res/geo.sfc

The preamble -- the colour, line type and width tables, the figure and the
layers -- is lifted from decomp/res/pens.sfc, which the original wrote, so
the only new thing in the file is the elements.  tools/refanswers.sh then has
the original open this and save it, and tests/sfcread_test.c holds what
src/sfcread.c makes of it against that.
"""
import io
import sys

SRC = 'decomp/res/pens.sfc'


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else 'decomp/res/geo.sfc'
    src = io.open(SRC, 'rb').read().decode('cp932')
    head = src[:src.index("/*SXF\r\n#470")]
    tail = src[src.index("/*SXF\r\n#650"):]

    # layer, colour, line type, width, then whatever the feature wants.  The
    # arcs go both ways round and one starts past the top, so that the way
    # the original folds a start and an end angle into a sweep is pinned.
    ent = [
        "arc_feature('1','1','1','2','72100.000000','53400.000000',"
        "'3000.000000','0','0.00000000000000','90.0000000000000')",
        "arc_feature('1','3','1','3','80100.000000','53400.000000',"
        "'3000.000000','1','180.000000000000','90.0000000000000')",
        "arc_feature('1','5','1','4','88100.000000','53400.000000',"
        "'3000.000000','0','270.000000000000','30.0000000000000')",
        "arc_feature('2','6','7','5','96100.000000','53400.000000',"
        "'3000.000000','1','45.0000000000000','315.000000000000')",
        "circle_feature('1','6','1','12','96100.000000','43400.000000',"
        "'3000.000000')",
        "circle_feature('2','2','3','2','88100.000000','43400.000000',"
        "'5000.000000')",
        "point_marker_feature('1','3','80100.000000','45400.000000','3',"
        "'0.00000000000000','1.00000000000000')",
        "point_marker_feature('2','5','72100.000000','45400.000000','3',"
        "'0.00000000000000','1.00000000000000')",
        "line_feature('1','7','1','11','64100.000000','61400.000000',"
        "'104100.000000','61400.000000')",
    ]
    n = 470
    body = []
    for e in ent:
        body.append("/*SXF\r\n#%d = %s\r\nSXF*/\r\n\r\n" % (n, e))
        n += 10
    io.open(out, 'wb').write((head + ''.join(body) + tail).encode('cp932'))
    print('%s: %d elements' % (out, len(ent)))


if __name__ == '__main__':
    main()
