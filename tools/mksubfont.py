#!/usr/bin/env python
"""Cut the outline fonts down to what a CP932 drawing can ask for.

    python tools/mksubfont.py <ipaexg.ttf> <ipaexm.ttf> <BIZUDGothic-Regular.ttf> fonts

Writes fonts/jwsubgothic.ttf, fonts/jwsubmincho.ttf and
fonts/bizudgothic-sub.ttf.  Needs fonttools (pip install fonttools).

The characters kept are every one CP932 has (ASCII, half-width katakana,
JIS X 0208, the NEC and IBM extensions), because that is all a drawing's
text can hold (src/cp932.h).  Hinting and layout tables go; they are of no
use to src/stb_truetype.h, which reads cmap, glyf, loca, head, hhea, hmtx
and maxp only.

IPA Font License v1.0 article 3 (4): a derived program must not carry the
name of the original as its font or file name, so the two IPAex subsets are
renamed (JwSubGothic / JwSubMincho) -- see font/PROVENANCE.md.  The face
name a drawing stores is a different thing: that is just the label the
文字種 dialog shows (src/outfont.c).  BIZ UD Gothic is under the SIL OFL
with no reserved font name, so its subset keeps its name.
"""
import sys
from fontTools import subset
from fontTools.ttLib import TTFont


def cp932_chars():
    cs = set()
    for c in range(0x20, 0x7f):
        cs.add(c)
    for c in range(0xa1, 0xe0):
        cs.add(ord(bytes([c]).decode("cp932")))
    for hi in list(range(0x81, 0xa0)) + list(range(0xe0, 0xfd)):
        for lo in range(0x40, 0xfd):
            if lo == 0x7f:
                continue
            try:
                s = bytes([hi, lo]).decode("cp932")
            except UnicodeDecodeError:
                continue
            if len(s) == 1:
                cs.add(ord(s))
    # a few the 'cp932' codec maps elsewhere than the fonts do
    cs.update([0x2015, 0x2225, 0xff0d, 0xffe0, 0xffe1, 0xffe2, 0xff5e])
    return sorted(cs)


def cut(src, dst, rename):
    opt = subset.Options()
    opt.hinting = False
    opt.layout_features = []
    opt.name_IDs = [0, 1, 2, 3, 4, 5, 6, 13, 14]
    opt.notdef_outline = True
    opt.glyph_names = False
    opt.drop_tables += ["DSIG", "GDEF", "GPOS", "GSUB", "vhea", "vmtx", "kern",
                        "MATH", "BASE", "JSTF", "fpgm", "prep", "cvt ", "gasp",
                        "VORG", "hdmx", "LTSH", "VDMX", "meta", "STAT"]
    f = subset.load_font(src, opt)
    s = subset.Subsetter(opt)
    s.populate(unicodes=cp932_chars())
    s.subset(f)
    if rename:
        fam, full, ps = rename
        for n in f["name"].names:
            if n.nameID in (1, 16):
                n.string = fam
            elif n.nameID in (4,):
                n.string = full
            elif n.nameID == 6:
                n.string = ps
            elif n.nameID == 3:
                n.string = ps + ";subset"
    subset.save_font(f, dst, opt)
    g = TTFont(dst)
    print(dst, len(g.getGlyphOrder()), "glyphs")


if __name__ == "__main__":
    if len(sys.argv) != 5:
        sys.exit(__doc__)
    g, m, b, out = sys.argv[1:]
    cut(g, out + "/jwsubgothic.ttf", ("JwSubGothic", "JwSubGothic", "JwSubGothic"))
    cut(m, out + "/jwsubmincho.ttf", ("JwSubMincho", "JwSubMincho", "JwSubMincho"))
    cut(b, out + "/bizudgothic-sub.ttf", None)
