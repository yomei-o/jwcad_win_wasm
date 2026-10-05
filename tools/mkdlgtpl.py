#!/usr/bin/env python3
"""Generate src/gen/dlgtpl.h -- the original's own dialog templates, laid out.

    python tools/mkdlgtpl.py

The dialogs the port has so far were each read out of the running original
(tools/jwdraw.ps1's `dlg:` step walks the children and writes their pixel
rectangles).  But every one of them is also a DIALOG resource in
orig/Jw_win.exe, which tools/rsrc.py has already written out to
decomp/res/dialog.txt in dialog units -- 108 of them.  Turning dialog units
into pixels is Windows' own sum, MapDialogRect:

    x px = MulDiv(x, base_x, 4)      y px = MulDiv(y, base_y, 8)

with the base units of the dialog's font.  For the 94 templates in
「ＭＳ Ｐゴシック」 9 the base units are 7 and 12, and that is not a guess:
the 縮尺・読取 dialog (template 277) comes out of this sum with every control
on the pixel tools/jwdraw.ps1 read off the original -- the edit box 1471 at
165,28 35x13 units is 289,42 61x20 pixels in decomp/res/shakudo.txt, the OK
button 211,25 65x18 is 369,38 114x27, and the client 279x125 is 488x188.
tests/tdlg_test.c holds the two to each other for every control.

The other fonts (ＭＳ ゴシック, MS UI Gothic, size 10) have other base units,
and none of their dialogs has been read off the original to fix them; they
are left out until one is.  So are the child dialogs (WS_CHILD -- the
command bars and the pages of 基本設定), which the port lays out from its
own captures already.
"""
import io
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mkmoji import esc                            # noqa: E402

SRC = 'decomp/res/dialog.txt'
OUT = 'src/gen/dlgtpl.h'

FONTS = {('ＭＳ Ｐゴシック', 9): (7, 12),
         # 書込み文字種変更 (270) and 文字基点設定 (276), both read off the
         # original, are 260x224 and 159x133 units and came out 390x336 and
         # 239x200 pixels: 6 across, 12 down (tests/tdlg_test.c holds every
         # control of both to it)
         ('ＭＳ ゴシック', 9): (6, 12)}
WS_CHILD = 0x40000000
WS_CAPTION = 0x00C00000
WS_VISIBLE = 0x10000000
WS_DISABLED = 0x08000000
WS_GROUP = 0x00020000
BORDER = 8                  # as the captured dialogs have it
CAPTION = 31

KINDS = ['PUSH', 'DEFPUSH', 'CHECK', 'RADIO', 'GROUP', 'STATIC', 'EDIT',
         'COMBO', 'LIST', 'FRAME', 'ICON']


def muldiv(a, b, c):
    """Windows' MulDiv: a*b/c rounded half away from zero"""
    n = a * b
    q, r = divmod(abs(n), c)
    if 2 * r >= c:
        q += 1
    return q if n >= 0 else -q


def kind_of(cls, style):
    if cls == 'BUTTON':
        t = style & 0xF
        if style & 0x1000:              # BS_PUSHLIKE
            return 'PUSH'
        return {0: 'PUSH', 1: 'DEFPUSH', 2: 'CHECK', 3: 'CHECK', 4: 'RADIO',
                5: 'CHECK', 6: 'CHECK', 7: 'GROUP', 9: 'RADIO',
                11: 'PUSH'}.get(t, 'PUSH')
    if cls == 'STATIC':
        t = style & 0x1F
        if t in (0, 1, 2, 0xB, 0xC):
            return 'STATIC'
        if t == 3:
            return 'ICON'
        return 'FRAME'
    if cls == 'EDIT':
        return 'EDIT'
    if cls == 'COMBOBOX':
        return 'COMBO'
    if cls == 'LISTBOX':
        return 'LIST'
    return 'FRAME'


def parse(path):
    out = []
    cur = None
    for line in io.open(path, encoding='utf-8'):
        line = line.rstrip('\n')
        m = re.match(r'=== DIALOG (\d+)', line)
        if m:
            cur = {'id': int(m.group(1)), 'ctl': [], 'caption': '',
                   'font': None, 'style': 0, 'w': 0, 'h': 0}
            out.append(cur)
            continue
        if cur is None:
            continue
        m = re.match(r'DIALOG(?:EX)? (-?\d+), (-?\d+), (\d+), (\d+)\s+style=0x([0-9a-f]+)', line)
        if m:
            cur['w'], cur['h'] = int(m.group(3)), int(m.group(4))
            cur['style'] = int(m.group(5), 16)
            continue
        m = re.match(r'  CAPTION "(.*)"$', line)
        if m:
            cur['caption'] = m.group(1)
            continue
        m = re.match(r'  FONT (\d+), "(.*)"', line)
        if m:
            cur['font'] = (m.group(2), int(m.group(1)))
            continue
        m = re.match(r'  CONTROL (\S+)\s+id=(\d+)\s+(-?\d+),\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s+style=0x([0-9a-f]+)\s+"(.*)"$', line)
        if m:
            cid = int(m.group(2)) & 0xffff
            cur['ctl'].append({'cls': m.group(1), 'id': cid,
                               'x': int(m.group(3)), 'y': int(m.group(4)),
                               'w': int(m.group(5)), 'h': int(m.group(6)),
                               'style': int(m.group(7), 16),
                               'text': m.group(8)})
    return out


def main():
    dlgs = parse(SRC)
    rows, tbl = [], []
    for d in dlgs:
        if d['style'] & WS_CHILD or (d['style'] & WS_CAPTION) != WS_CAPTION:
            continue
        if d['font'] not in FONTS:
            continue
        bx, by = FONTS[d['font']]
        first = len(rows)
        for c in d['ctl']:
            k = kind_of(c['cls'], c['style'])
            x, y = muldiv(c['x'], bx, 4), muldiv(c['y'], by, 8)
            w, h = muldiv(c['w'], bx, 4), muldiv(c['h'], by, 8)
            if k == 'COMBO':
                # the template's height is the list dropped down; closed, a
                # combo is as tall as an edit box of the dialog's font
                h = muldiv(12, by, 8) + 2
            flags = ((1 if c['style'] & WS_VISIBLE else 0)
                     | (2 if c['style'] & WS_DISABLED else 0)
                     | (4 if c['style'] & WS_GROUP else 0))
            text = c['text']
            if k == 'ICON':
                text = ''
            rows.append('    { %4d, %4d, %4d, %4d, %5d, JW_TC_%-7s, %d, 0x%08xu, "%s" },'
                        % (x, y, w, h, c['id'], k, flags, c['style'], esc(text)))
        cw, ch = muldiv(d['w'], bx, 4), muldiv(d['h'], by, 8)
        tbl.append('    { %4d, %4d, %4d, %4d, %3d, "%s" },'
                   % (d['id'], cw, ch, first, len(rows) - first, esc(d['caption'])))

    o = []
    o.append('/* generated by tools/mkdlgtpl.py from decomp/res/dialog.txt --')
    o.append('   the original\'s own dialog templates, in pixels: see that script */')
    o.append('#ifndef JW_GEN_DLGTPL_H')
    o.append('#define JW_GEN_DLGTPL_H')
    o.append('')
    o.append('#define JW_TDLG_BORDER %d' % BORDER)
    o.append('#define JW_TDLG_CAPTION %d' % CAPTION)
    o.append('')
    o.append('enum { ' + ', '.join('JW_TC_' + k for k in KINDS) + ' };')
    o.append('')
    o.append('/* flags: 1 visible, 2 disabled, 4 starts a group */')
    o.append('typedef struct {')
    o.append('    short x, y, w, h;      /* in the dialog\'s client area */')
    o.append('    unsigned short id;')
    o.append('    unsigned char kind, flags;')
    o.append('    unsigned int style;')
    o.append('    const char *text;      /* CP932 */')
    o.append('} jw_tctl_t;')
    o.append('')
    o.append('typedef struct {')
    o.append('    unsigned short tpl;    /* the DIALOG resource\'s number */')
    o.append('    short cw, ch;          /* its client area */')
    o.append('    unsigned short first, n;')
    o.append('    const char *title;     /* CP932 */')
    o.append('} jw_tdlg_t;')
    o.append('')
    o.append('static const jw_tctl_t jw_tctl[] = {')
    o.extend(rows)
    o.append('};')
    o.append('')
    o.append('static const jw_tdlg_t jw_tdlg[] = {')
    o.extend(tbl)
    o.append('};')
    o.append('#define JW_NTDLG %d' % len(tbl))
    o.append('')
    o.append('#endif')
    with io.open(OUT, 'w', encoding='ascii', newline='\n') as f:
        f.write('\n'.join(o) + '\n')
    print('%s: %d dialogs, %d controls' % (OUT, len(tbl), len(rows)))


if __name__ == '__main__':
    main()
