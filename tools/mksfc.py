"""Make an SFC of the features a drawing of lines does not exercise, to ask
the original what it makes of them.

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
Q = "\\'"                       # a name is quoted like this, a number is not


def elements():
    """layer, colour, line type, width, then whatever the feature wants.

    The arcs go both ways round and one starts past the top, so that the way
    the original folds a start and an end angle into a sweep is pinned; the
    texts are turned, spaced and in CP932, because the file gives the width
    of the whole string and the width of one letter has to come back out of
    it.
    """
    return [
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
        "polyline_feature('1','3','1','2','4',"
        "'(64100.000000,68100.000000,72100.000000,64100.000000)',"
        "'(71400.000000,75400.000000,71400.000000,71400.000000)')",
        "text_string_feature('1','3','1'," + Q + "ABC" + Q + ","
        "'64100.000000','61400.000000','500.000000','1875.000000',"
        "'0.000000','0.00000000000000','0.00000000000000','1','1')",
        "text_string_feature('1','5','1'," + Q + "あいabc" + Q + ","
        "'64100.000000','66400.000000','800.000000','2800.000000',"
        "'0.000000','30.0000000000000','0.00000000000000','1','1')",
        "text_string_feature('2','2','1'," + Q + "XY" + Q + ","
        "'74100.000000','71400.000000','400.000000','800.000000',"
        "'100.000000','90.0000000000000','0.00000000000000','1','1')",
    ]


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else 'decomp/res/geo.sfc'
    src = io.open(SRC, 'rb').read().decode('cp932')
    head = src[:src.index("/*SXF\r\n#470")]
    tail = src[src.index("/*SXF\r\n#650"):]

    ent = elements()
    # a text names one of the fonts the file lists, so there has to be one
    body = ["/*SXF\r\n#465 = text_font_feature("
            + Q + "ＭＳ ゴシック" + Q
            + ")\r\nSXF*/\r\n\r\n"]
    n = 470
    for e in ent:
        body.append("/*SXF\r\n#%d = %s\r\nSXF*/\r\n\r\n" % (n, e))
        n += 10
    io.open(out, 'wb').write((head + ''.join(body) + tail).encode('cp932'))
    print('%s: %d elements' % (out, len(ent)))


if __name__ == '__main__':
    main()
