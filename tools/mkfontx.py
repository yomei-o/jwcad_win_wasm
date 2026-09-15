"""Build the FONTX2 fonts the port needs, from the Shinonome BDF sources.

JW_CAD carries no font of its own: it asks DOS/V for one through
`INT 15h AX=5000h` and calls back the routine it gets (see RESUME.md, 文字).
So the port has to bring a font, and it has to be one that can also be handed
to a DOS/V emulator later -- the plan is to check this port against the real
JW_CADV.EXE running in one, and that comparison is only meaningful if both
sides draw with the same glyphs.  FONTX2 is the format DOS/V fonts come in, so
that is what this writes.

    python tools/mkfontx.py <shinonome checkout> font

Shinonome is Public Domain: "このアーカイブに含まれるすべてのフォントデータ、
ドキュメント、スクリプト類はすべて Public Domain で提供されています" --
free to modify, convert, embed and redistribute.  Provenance and the licence
text are recorded in font/PROVENANCE.md.

Two files come out:

    font/JWANK16.FNT   8x16,  256 single-byte glyphs (JIS X 0201)
    font/JWKAN16.FNT   16x16, JIS X 0208 indexed by Shift-JIS

The BDF sources put the glyph encoding in JIS, so the kanji side is
transcoded to Shift-JIS here, because that is what JW_CAD passes: `1def:23c5`
reads a lead byte, joins it with the next one and hands the pair to
`20a9:03e1`.
"""
import os
import re
import struct
import sys


def read_bdf(path):
    """{encoding: [row bitmasks]} from a Shinonome .bit source.

    They are BDF except that the bitmaps are drawn with '@' and '.' rather
    than written as hex, which is easier to read and just as easy to parse.
    """
    glyphs = {}
    code = None
    rows = None
    width = 0
    for line in open(path, encoding='utf-8', errors='replace'):
        line = line.rstrip('\n')
        if line.startswith('ENCODING '):
            code = int(line.split()[1])
        elif line.startswith('BBX '):
            width = int(line.split()[1])
        elif line == 'BITMAP':
            rows = []
        elif line.startswith('ENDCHAR'):
            if code is not None and rows is not None:
                glyphs[code] = (width, rows)
            code, rows = None, None
        elif rows is not None and re.fullmatch(r'[.@]+', line):
            bits = 0
            for ch in line:
                bits = (bits << 1) | (1 if ch == '@' else 0)
            rows.append(bits << (width - len(line)) if len(line) < width else bits)
    return glyphs


def rows_to_bytes(rows, width, height):
    """Left-justified, (width + 7) / 8 bytes per row, as FONTX2 wants."""
    stride = (width + 7) // 8
    out = bytearray(stride * height)
    for y in range(min(height, len(rows))):
        v = rows[y]
        for b in range(stride):
            shift = width - 8 * (b + 1)
            out[y * stride + b] = (v >> shift) & 0xff if shift >= 0 else \
                                  (v << -shift) & 0xff
    return bytes(out)


def jis_to_sjis(jis):
    h, l = jis >> 8, jis & 0xff
    if h & 1:
        l += 0x1f if l < 0x60 else 0x20
    else:
        l += 0x7e
    h = ((h - 0x21) >> 1) + (0x81 if h < 0x5f else 0xc1)
    return (h << 8) | l


def write_sbcs(path, name, glyphs, width, height):
    blank = bytes((width + 7) // 8 * height)
    body = bytearray()
    for code in range(256):
        g = glyphs.get(code)
        body += rows_to_bytes(g[1], width, height) if g else blank
    with open(path, 'wb') as f:
        f.write(b'FONTX2' + name.encode('ascii').ljust(8))
        f.write(bytes([width, height, 0]))
        f.write(body)
    return 256


def write_dbcs(path, name, glyphs, width, height):
    """FONTX2's double-byte form: runs of consecutive codes, then the images.

    The blocks are what keeps the file small -- Shift-JIS leaves big holes
    between the rows, and only the codes actually present are stored.
    """
    codes = sorted(glyphs)
    blocks = []
    for c in codes:
        if blocks and c == blocks[-1][1] + 1:
            blocks[-1][1] = c
        else:
            blocks.append([c, c])
    body = bytearray()
    for c in codes:
        body += rows_to_bytes(glyphs[c][1], width, height)
    with open(path, 'wb') as f:
        f.write(b'FONTX2' + name.encode('ascii').ljust(8))
        f.write(bytes([width, height, 1, len(blocks)]))
        for a, b in blocks:
            f.write(struct.pack('<2H', a, b))
        f.write(body)
    return len(codes), len(blocks)


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else 'shinonome'
    out = sys.argv[2] if len(sys.argv) > 2 else 'font'
    os.makedirs(out, exist_ok=True)

    latin = read_bdf(os.path.join(src, '16', 'latin1', 'font_src.bit'))
    kana = read_bdf(os.path.join(src, '16', 'hankaku', 'font_src_diff.bit'))
    ank = dict(latin)
    ank.update(kana)            # the half-width katakana replace latin1 there
    n = write_sbcs(os.path.join(out, 'JWANK16.FNT'), 'JWANK16', ank, 8, 16)
    print('JWANK16.FNT  8x16   %d glyphs (%d latin1 + %d kana)'
          % (n, len(latin), len(kana)))

    jis = read_bdf(os.path.join(src, '16', 'kanjic', 'font_src.bit'))
    sjis = {jis_to_sjis(c): g for c, g in jis.items()}
    n, nb = write_dbcs(os.path.join(out, 'JWKAN16.FNT'), 'JWKAN16', sjis, 16, 16)
    print('JWKAN16.FNT  16x16  %d glyphs in %d code blocks' % (n, nb))


if __name__ == '__main__':
    main()
