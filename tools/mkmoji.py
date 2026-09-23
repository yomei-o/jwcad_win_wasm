#!/usr/bin/env python3
"""Generate src/gen/moji.h -- the 書込み文字種変更 dialog (the 文字 bar's 1843).

Like the 線属性 one (tools/mkzoku.py), the dialog is read out of the running
original rather than worked out from its template: tools/jwdraw.ps1's `dlg:b`
step presses the button, walks the dialog's children with EnumChildWindows
and writes down each control's class, id, style, text and rectangle in the
dialog's own client coordinates (decomp/res/moji.txt).  It also paints the
dialog into a PNG, which is what docs/ref_moji.png is.

Two things come out of that picture rather than the list: **the radio
button**, which is Windows' own themed one and is baked here as the two
13-by-13 sprites it is, and nothing else -- everything else the dialog
draws is a box, a line or a piece of text.

Only the controls that are on the screen are kept: the dialog carries a
second, hidden font combo and a hidden edit box.
"""
import io
import os
import struct
import sys
import zlib

SRC = 'decomp/res/moji.txt'
PNG = 'docs/ref_moji.png'
OUT = 'src/gen/moji.h'

WS_VISIBLE = 0x10000000
BORDER = 8
CAPTION = 31
FACE = 0xf0f0f0


def esc(s):
    BS = chr(92)
    keep = '"' + BS + '?'
    out = []
    b = s.encode('cp932')
    for i, c in enumerate(b):
        if c > 0x7e or c < 0x20 or chr(c) in keep:
            out.append(BS + 'x%02x' % c)
            if i + 1 < len(b) and chr(b[i + 1]) in '0123456789abcdefABCDEF':
                out.append('" "')
        else:
            out.append(chr(c))
    return ''.join(out)


def readpng(p):
    b = io.open(p, 'rb').read()
    pos, idat, ct, bd, w, h = 8, b'', 6, 8, 0, 0
    while pos < len(b):
        ln = struct.unpack_from('>I', b, pos)[0]
        typ = b[pos + 4:pos + 8]
        data = b[pos + 8:pos + 8 + ln]
        if typ == b'IHDR':
            w, h, bd, ct = struct.unpack_from('>IIBB', data, 0)
        if typ == b'IDAT':
            idat += data
        pos += 12 + ln
    raw = zlib.decompress(idat)
    bpp = {0: 1, 2: 3, 3: 1, 4: 2, 6: 4}[ct] * (bd // 8)
    stride = w * bpp
    out = bytearray()
    prev = bytearray(stride)
    i = 0
    for _ in range(h):
        f = raw[i]
        i += 1
        line = bytearray(raw[i:i + stride])
        i += stride
        for x in range(stride):
            a = line[x - bpp] if x >= bpp else 0
            bb = prev[x]
            c = prev[x - bpp] if x >= bpp else 0
            if f == 1:
                line[x] = (line[x] + a) & 255
            elif f == 2:
                line[x] = (line[x] + bb) & 255
            elif f == 3:
                line[x] = (line[x] + (a + bb) // 2) & 255
            elif f == 4:
                pa, pb, pc = abs(bb - c), abs(a - c), abs(a + bb - 2 * c)
                pr = a if (pa <= pb and pa <= pc) else (bb if pb <= pc else c)
                line[x] = (line[x] + pr) & 255
        out += line
        prev = line
    return w, h, bpp, bytes(out)


def sprite(px, w, bpp, x0, y0, sw, sh):
    """The block at x0,y0 as words, with the dialog's face left out."""
    out = []
    for y in range(y0, y0 + sh):
        row = []
        for x in range(x0, x0 + sw):
            o = (y * w + x) * bpp
            v = (px[o] << 16) | (px[o + 1] << 8) | px[o + 2]
            row.append(0xffffffff if v == FACE else v)
        out.append(row)
    return out


def kind_of(cid, cls, style):
    if cid == 1:
        return 'OK', 0
    if cid == 2:
        return 'CANCEL', 0
    if cls == 'Button':
        low = style & 0xf
        if low == 9:                    # BS_AUTORADIOBUTTON
            # 1884 is 任意サイズ and 1689..1698 are 文字種 1..10
            return 'RADIO', 0 if cid == 1884 else cid - 1688
        if low == 3:                    # BS_AUTOCHECKBOX
            return 'CHECK', 0
        return 'PUSH', 0
    if cls == 'Edit':
        return 'EDIT', 0
    if cls == 'ComboBox':
        return 'COMBO', 0
    if cls == 'Static':
        # 2504..2513 are the ten rows of numbers, which the port fills in
        # from the drawing rather than from what the original happened to
        # have open
        return 'STATIC', cid - 2503 if 2504 <= cid <= 2513 else 0
    return None, 0


def main():
    rows = []
    for line in io.open(SRC, encoding='utf-8'):
        line = line.rstrip('\n')
        if '|' not in line or line.startswith('==='):
            continue
        cls, cid, x, y, w, h, style, chk, en, text = line.split('|', 9)
        if not (int(style, 16) & WS_VISIBLE):
            continue                    # the second font combo, and 1494
        k, n = kind_of(int(cid), cls, int(style, 16))
        if k is None:
            continue
        if k == 'CHECK':
            n = int(chk)                # a checkbox keeps whether it is on
        rows.append((int(x), int(y), int(w), int(h), int(cid), k, n, text))

    w, h, bpp, px = readpng(PNG)
    # the 任意サイズ radio is on, 文字種[ 1] is off
    on = sprite(px, w, bpp, BORDER + 15, CAPTION + 86, 14, 15)
    off = sprite(px, w, bpp, BORDER + 15, CAPTION + 108, 14, 15)

    if not os.path.isdir('src/gen'):
        os.makedirs('src/gen')
    f = io.open(OUT, 'w', encoding='ascii', newline='\n')
    f.write('/* generated by tools/mkmoji.py from decomp/res/moji.txt and\n'
            '   docs/ref_moji.png -- read out of the running original, see\n'
            '   that script */\n')
    f.write('#ifndef JW_GEN_MOJI_H\n#define JW_GEN_MOJI_H\n\n')
    f.write('/* the dialog itself, in the frame\'s client area: the original\n'
            '   centres it across and in the client above the status bar,\n'
            '   which came to 429,162 in a 1264x741 one */\n')
    f.write('#define JW_MOJI_W   406\n')
    f.write('#define JW_MOJI_H   375\n')
    f.write('#define JW_MOJI_CW  390\n')
    f.write('#define JW_MOJI_CH  336\n')
    f.write('#define JW_MOJI_BORDER %d\n' % BORDER)
    f.write('#define JW_MOJI_CAPTION %d\n\n' % CAPTION)
    f.write('enum { JW_MJ_OK, JW_MJ_CANCEL, JW_MJ_RADIO, JW_MJ_CHECK,\n'
            '       JW_MJ_PUSH, JW_MJ_EDIT, JW_MJ_COMBO, JW_MJ_STATIC };\n\n')
    f.write('typedef struct {\n'
            '    short x, y, w, h;      /* the dialog\'s client area */\n'
            '    short id;\n'
            '    unsigned char kind;\n'
            '    unsigned char n;       /* which style, 0 for the free one  */\n'
            '    const char *text;      /* CP932 */\n'
            '} jw_mj_t;\n\n')
    f.write('static const jw_mj_t jw_moji[] = {\n')
    for x, y, ww, hh, cid, k, n, text in rows:
        f.write('    { %4d, %4d, %4d, %3d, %5d, JW_MJ_%-6s, %2d, "%s" },\n'
                % (x, y, ww, hh, cid, k, n, esc(text)))
    f.write('};\n#define JW_NMOJI %d\n\n' % len(rows))
    f.write('/* Windows\' own radio button, off and on, as it comes out of\n'
            '   the original\'s dialog.  0xffffffff is the dialog\'s face. */\n')
    f.write('#define JW_MJ_RADIO_W 14\n#define JW_MJ_RADIO_H 15\n')
    for name, sp in (('off', off), ('on', on)):
        f.write('static const unsigned int jw_moji_radio_%s[] = {\n' % name)
        for row in sp:
            f.write('    ' + ''.join('0x%08x,' % v for v in row) + '\n')
        f.write('};\n')
    f.write('\n#endif\n')
    f.close()
    print('%s: %d controls' % (OUT, len(rows)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
