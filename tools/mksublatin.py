#!/usr/bin/env python
"""Cut Liberation Sans/Serif/Mono and Carlito down to the Latin letters a
CP932 text holds.

    python tools/mksublatin.py <LiberationSans-Regular.ttf> <LiberationSerif-Regular.ttf> \
        <LiberationMono-Regular.ttf> <Carlito-Regular.ttf> fonts

Writes fonts/jwsubsans.ttf, jwsubserif.ttf, jwsubmono.ttf and
jwsubcalibri.ttf.  Needs fonttools (pip install fonttools).

They stand in for Arial, Times New Roman / Century, Courier New and Calibri
(src/outfont.c): the original draws a text whose face is e.g. Arial with
Windows' Arial, which the port cannot ship.  Liberation Sans/Serif/Mono and
Carlito have Arial's, Times New Roman's, Courier New's and Calibri's advance
widths (every one of the 95 ASCII 0x20..0x7e glyphs checked one by one
against the real Windows face files, not just the OS/2 average -- see
font/PROVENANCE.md).  Only that Latin range is kept; everything else in such
a text -- kana, kanji, the full-width forms -- is set in IPAex, the way
Windows' font association sets a Japanese letter of an ANSI face in
ＭＳ ゴシック / ＭＳ 明朝.

Liberation is under the SIL OFL 1.1 with the Reserved Font Names
"Liberation" (Red Hat), "Arimo", "Tinos" and "Cousine" (Google).  Carlito is
under the SIL OFL 1.1 with the Reserved Font Name "Carlito" (Google).  A
subset is a Modified Version, so it may not carry those names: the subsets
are renamed JwSubSans / JwSubSerif / JwSubMono / JwSubCalibri (font and file
names), see font/PROVENANCE.md.  "Calibri" itself is not an OFL reserved
name (it is Microsoft's own face, which this file does not contain), so the
Calibri stand-in's name may still refer to the face it stands in for, the
way fonts/bizudgothic-sub.ttf keeps "BIZUDGothic" in its name.
"""
import sys
from fontTools import subset


def cut(src, dst, family, source_tag):
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
            rec.string = family + " (subset of " + source_tag + ")"
        elif rec.nameID == 6:
            rec.string = family.replace(" ", "")
        elif rec.nameID == 2:
            rec.string = "Regular"
    f.save(dst)


def main():
    if len(sys.argv) != 6:
        print(__doc__)
        return 2
    sans, serif, mono, calibri, out = sys.argv[1:6]
    out = out.rstrip("/\\")
    cut(sans, out + "/jwsubsans.ttf", "JwSubSans", "Liberation 2.1.5")
    cut(serif, out + "/jwsubserif.ttf", "JwSubSerif", "Liberation 2.1.5")
    cut(mono, out + "/jwsubmono.ttf", "JwSubMono", "Liberation 2.1.5")
    cut(calibri, out + "/jwsubcalibri.ttf", "JwSubCalibri", "Carlito 1.104")
    return 0


if __name__ == "__main__":
    sys.exit(main())
