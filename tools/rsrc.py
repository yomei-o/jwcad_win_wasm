"""Decode Jw_win.exe's resources.

The UI is not something that has to be recovered from machine code: menus,
dialog templates, toolbar layouts and every string are sitting in .rsrc in a
documented form.  This turns them into text and .bmp files so the port can be
built against the same numbers the original uses.

    python tools/rsrc.py orig/Jw_win.exe decomp/res
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pe import PE, RT

SJIS = 'cp932'

# MFC keeps its own two types in afxres.h, next to the Win32 ones.
RT_DLGINIT = 240
RT_TOOLBAR = 241


def wstr(d, o):
    """NUL-terminated UTF-16 at o; returns (text, offset past it)."""
    e = o
    while struct.unpack_from('<H', d, e)[0]:
        e += 2
    return d[o:e].decode('utf-16-le'), e + 2


def align4(o):
    return (o + 3) & ~3


# ---------------------------------------------------------------- MENU
MF_POPUP, MF_END = 0x0010, 0x0080


def menu(d):
    out = []
    ver, hdr = struct.unpack_from('<HH', d, 0)
    if ver != 0:
        return ['(MENUEX version %d - not decoded)' % ver]
    o = 4 + hdr

    def level(o, depth):
        while True:
            flags = struct.unpack_from('<H', d, o)[0]
            o += 2
            if flags & MF_POPUP:
                text, o = wstr(d, o)
                out.append('  ' * depth + 'POPUP "%s"' % text)
                o = level(o, depth + 1)
            else:
                mid = struct.unpack_from('<H', d, o)[0]
                o += 2
                text, o = wstr(d, o)
                if not text and mid == 0:
                    out.append('  ' * depth + 'SEPARATOR')
                else:
                    out.append('  ' * depth + 'MENUITEM "%s", %d (0x%04x)'
                               % (text, mid, mid))
            if flags & MF_END:
                return o

    level(o, 0)
    return out


# -------------------------------------------------------------- DIALOG
# The control classes that get an ordinal instead of a name.
ORD_CLASS = {0x80: 'BUTTON', 0x81: 'EDIT', 0x82: 'STATIC', 0x83: 'LISTBOX',
             0x84: 'SCROLLBAR', 0x85: 'COMBOBOX'}


def resname(d, o):
    """A dialog's class/title field: 0, an ordinal, or a string."""
    v = struct.unpack_from('<H', d, o)[0]
    if v == 0:
        return '', o + 2
    if v == 0xffff:
        ordv = struct.unpack_from('<H', d, o + 2)[0]
        return ORD_CLASS.get(ordv, '#%d' % ordv), o + 4
    return wstr(d, o)


def dialog(d):
    out = []
    # DLGTEMPLATEEX opens with dlgVer=1 then signature=0xffff; a plain
    # DLGTEMPLATE opens with the low word of its style, which is never that.
    dver, sig = struct.unpack_from('<HH', d, 0)
    ex = sig == 0xffff and dver == 1
    if ex:
        _, _, helpid, exstyle, style, n, x, y, cx, cy = \
            struct.unpack_from('<HHIIIHhhhh', d, 0)
        o = 26
    else:
        style, exstyle, n, x, y, cx, cy = struct.unpack_from('<IIHhhhh', d, 0)
        o = 18
    menu_, o = resname(d, o)
    cls, o = resname(d, o)
    title, o = wstr(d, o)
    fontsz = fontname = None
    if style & 0x40:  # DS_SETFONT
        fontsz = struct.unpack_from('<H', d, o)[0]
        o += 2
        if ex:
            o += 4  # weight, italic, charset
        fontname, o = wstr(d, o)
    out.append('DIALOG%s %d, %d, %d, %d  style=0x%08x exstyle=0x%08x'
               % ('EX' if ex else '', x, y, cx, cy, style, exstyle))
    out.append('  CAPTION "%s"' % title)
    if menu_:
        out.append('  MENU %s' % menu_)
    if cls:
        out.append('  CLASS %s' % cls)
    if fontname is not None:
        out.append('  FONT %d, "%s"' % (fontsz, fontname))
    for _ in range(n):
        o = align4(o)
        if ex:
            chelp, cex, cstyle, cx_, cy_, ccx, ccy, cid = \
                struct.unpack_from('<IIIhhhhI', d, o)
            o += 24
        else:
            cstyle, cex, cx_, cy_, ccx, ccy, cid = \
                struct.unpack_from('<IIhhhhH', d, o)
            o += 18
        ccls, o = resname(d, o)
        ctext, o = resname(d, o)
        extra = struct.unpack_from('<H', d, o)[0]
        o += 2 + extra
        out.append('  CONTROL %-9s id=%-6d %4d,%4d,%4d,%4d  style=0x%08x  "%s"'
                   % (ccls, cid, cx_, cy_, ccx, ccy, cstyle, ctext))
    return out


# -------------------------------------------------------------- STRING
def strings(d, block):
    out = []
    o = 0
    for i in range(16):
        n = struct.unpack_from('<H', d, o)[0]
        o += 2
        if n:
            out.append((((block - 1) << 4) + i,
                        d[o:o + 2 * n].decode('utf-16-le')))
            o += 2 * n
    return out


# ------------------------------------------------------------- TOOLBAR
def toolbar(d):
    ver, w, h, n = struct.unpack_from('<HHHH', d, 0)
    ids = struct.unpack_from('<%dH' % n, d, 8)
    return ver, w, h, ids


# ------------------------------------------------------------- DLGINIT
def dlginit(d):
    out = []
    o = 0
    while o + 2 <= len(d):
        cid = struct.unpack_from('<H', d, o)[0]
        if cid == 0:
            break
        msg, ln = struct.unpack_from('<II', d, o + 2)
        blob = d[o + 10:o + 10 + ln]
        out.append((cid, msg, blob.rstrip(b'\0').decode(SJIS, 'replace')))
        o += 10 + ln
    return out


# --------------------------------------------------------------- ACCEL
FVIRTKEY, FNOINVERT, FSHIFT, FCONTROL, FALT, FLAST = 1, 2, 4, 8, 16, 0x80


def accel(d):
    out = []
    o = 0
    while o + 8 <= len(d):
        fl, key, cmd, _ = struct.unpack_from('<HHHH', d, o)
        mods = ''.join(c for c, b in
                       (('S', FSHIFT), ('C', FCONTROL), ('A', FALT)) if fl & b)
        out.append('key=0x%04x %-3s cmd=%d (0x%04x)%s'
                   % (key, mods, cmd, cmd, ' VIRTKEY' if fl & FVIRTKEY else ''))
        o += 8
        if fl & FLAST:
            break
    return out


# -------------------------------------------------------------- BITMAP
def bmp_file(d):
    """A BITMAP resource is a DIB with no file header; put one back on."""
    hdrsz = struct.unpack_from('<I', d, 0)[0]
    if hdrsz == 40:
        bits, clrused = struct.unpack_from('<H', d, 14)[0], \
                        struct.unpack_from('<I', d, 32)[0]
        if bits <= 8 and clrused == 0:
            clrused = 1 << bits
        off = 14 + hdrsz + 4 * clrused
    else:
        off = 14 + hdrsz
    return struct.pack('<2sIHHI', b'BM', 14 + len(d), 0, 0, off) + d


def main():
    exe, outdir = sys.argv[1], sys.argv[2]
    p = PE(exe)
    os.makedirs(outdir, exist_ok=True)
    os.makedirs(outdir + '/bitmap', exist_ok=True)
    res = p.resources()
    txt = {}

    def add(fn, lines):
        txt.setdefault(fn, []).extend(lines)

    nbmp = 0
    allstr = []
    for t, n, lang, rva, sz in sorted(res, key=lambda r: (str(r[0]), str(r[1]))):
        d = p.res_data(rva, sz)
        tag = '%s' % n
        if t == 4:
            add('menu.txt', ['', '=== MENU %s (%d bytes)' % (tag, sz)] + menu(d))
        elif t == 5:
            add('dialog.txt', ['', '=== DIALOG %s (%d bytes)' % (tag, sz)] + dialog(d))
        elif t == 6:
            allstr.extend(strings(d, n))
        elif t == 9:
            add('accel.txt', ['', '=== ACCELERATOR %s' % tag] + accel(d))
        elif t == RT_TOOLBAR:
            ver, w, h, ids = toolbar(d)
            add('toolbar.txt',
                ['', '=== TOOLBAR %s  %d x %d  %d buttons'
                 % (tag, w, h, len(ids))] +
                ['  %s' % ('SEPARATOR' if i == 0 else '%d (0x%04x)' % (i, i))
                 for i in ids])
        elif t == RT_DLGINIT:
            add('dlginit.txt', ['', '=== DLGINIT %s' % tag] +
                ['  ctrl=%d msg=0x%04x "%s"' % x for x in dlginit(d)])
        elif t == 2:
            open('%s/bitmap/%s.bmp' % (outdir, tag), 'wb').write(bmp_file(d))
            nbmp += 1

    allstr.sort()
    add('string.txt', ['%6d 0x%04x  %s' % (i, i, s.replace('\n', '\n'))
                       for i, s in allstr])

    for fn, lines in txt.items():
        with open(os.path.join(outdir, fn), 'w', encoding='utf-8') as f:
            f.write('\n'.join(lines) + '\n')
        print('%-14s %6d lines' % (fn, len(lines)))
    print('%-14s %6d files' % ('bitmap/', nbmp))


if __name__ == '__main__':
    main()
