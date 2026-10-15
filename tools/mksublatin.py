#!/usr/bin/env python
"""Cut Liberation Sans / Serif down to the Latin letters a CP932 text holds.

    python tools/mksublatin.py <LiberationSans-Regular.ttf> <LiberationSerif-Regular.ttf> fonts

Writes fonts/jwsubsans.ttf and fonts/jwsubserif.ttf.  Needs fonttools
(pip install fonttools).

They stand in for Arial and Times New Roman / Century (src/outfont.c): the
original draws a text whose face is Arial with Windows' Arial, which the port
cannot ship.  Liberation Sans and Serif have Arial's and Times New Roman's
advance widths.  Only the single-byte half of CP932 that has Latin glyphs
(0x20..0x7e) is kept; everything else in such a text -- kana, kanji, the
full-width forms -- is set in IPAex, the way Windows' font association sets
a Japanese letter of an ANSI face in ＭＳ ゴシック / ＭＳ 明朝.

Liberation is under the SIL OFL 1.1 with the Reserved Font Names
"Liberation", "Arimo" and "Tinos".  A subset is a Modified Version, so it may
not carry those names: the subsets are renamed JwSubSans / JwSubSerif (font
and file names), see font/PROVENANCE.md.
"""
import sys
from fontTools import subset


def cut(src, dst, family):
    opt = subset.Options()
    opt.hinting = False
    opt.layout_features = []
    opt.name_IDs = [0, 1, 2, 3, 4, 5, 6, 13, 14]
    opt.notdef_outline = True
    opt.glyph_names = False
    opt.drop_tables += ["DSIG", "GDEF", "GPOS", "GSUB", "kern", "fpgm", "prep",
                        "cvt ", "gasp", "hdmx", "LTSH", "VDMX", "meta", "STAT",
                        "FFTM"]
    f = subset.load_font(src, opt)
    s = subset.Subsetter(opt)
    s.populate(unicodes=range(0x20, 0x7f))
    s.subset(f)
    name = f["name"]
    for rec in list(name.names):
        if rec.nameID in (1, 4, 16, 21):
            rec.string = family
        elif rec.nameID == 3:
            rec.string = family + " (subset of Liberation 2.1.5)"
        elif rec.nameID == 6:
            rec.string = family.replace(" ", "")
        elif rec.nameID == 2:
            rec.string = "Regular"
    f.save(dst)


def main():
    if len(sys.argv) != 4:
        print(__doc__)
        return 2
    out = sys.argv[3].rstrip("/\\")
    cut(sys.argv[1], out + "/jwsubsans.ttf", "JwSubSans")
    cut(sys.argv[2], out + "/jwsubserif.ttf", "JwSubSerif")
    return 0


if __name__ == "__main__":
    sys.exit(main())
