"""Work out which toolbar cell sits in which button, by matching pixels.

The composition of Jw_cad's side bars is buried in CMainFrame::OnCreate and
the bar classes, which is a lot of machine code for a layout question.  The
reference screen already has the answer in it: every button is 31x22 with a
24x15 cell of a toolbar strip in the middle, so each one can simply be looked
up in the strips.  What comes out is a table the port can be built from, and
it is right by construction -- a cell that does not match exactly is reported
rather than guessed at.

    python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h
"""
import collections
import os
import struct
import sys

from PIL import Image

BTN_W, BTN_H = 31, 22
CELL_W, CELL_H = 24, 15

WHITE = (255, 255, 255)
DKSHADOW = (105, 105, 105)
BTNFACE = (240, 240, 240)
BTNSHADOW = (160, 160, 160)

# What MFC substitutes when it loads a toolbar bitmap, in the theme the
# reference was taken in.
REMAP = {(0, 0, 0): (0, 0, 0),
         (128, 128, 128): BTNSHADOW,
         (192, 192, 192): BTNFACE,
         (255, 255, 255): WHITE}


def disabled(cell):
    """The embossed look Windows gives a greyed-out toolbar button: the ink
    is drawn once in highlight offset by (1,1) and once in shadow on top."""
    out = list(cell)
    ink = [i for i, p in enumerate(cell) if p != BTNFACE]
    for i in ink:
        x, y = i % CELL_W, i // CELL_W
        if x + 1 < CELL_W and y + 1 < CELL_H:
            out[(y + 1) * CELL_W + x + 1] = WHITE
    for i in ink:
        out[i] = BTNSHADOW
    return tuple(out)


def load_strips(bmdir):
    """{id: [cell images as tuples]} for every 24x15 strip."""
    strips = {}
    for fn in sorted(os.listdir(bmdir)):
        if not fn.endswith('.bmp'):
            continue
        if not fn[:-4].isdigit():
            continue        # IMAGESENCOLL and friends are named, not numbered
        rid = int(fn[:-4])
        im = Image.open(os.path.join(bmdir, fn)).convert('RGB')
        if im.height != CELL_H or im.width % CELL_W:
            continue
        cells = []
        for c in range(im.width // CELL_W):
            box = im.crop((c * CELL_W, 0, (c + 1) * CELL_W, CELL_H))
            px = [REMAP.get(p, p) for p in box.get_flattened_data()]
            cells.append(tuple(px))
        strips[rid] = cells
    return strips


def checked(cell, x0, y0):
    """A pressed-in toolbar button keeps its ink but lays it over a
    checkerboard of highlight and face, aligned to the window, not to the
    button -- so the phase depends on where the button is."""
    out = list(cell)
    for i, p in enumerate(cell):
        if p != BTNFACE:
            continue
        x, y = x0 + i % CELL_W, y0 + i // CELL_W
        out[i] = WHITE if (x + y) & 1 else BTNFACE
    return tuple(out)


def find_buttons(im):
    """Every 31x22 button, raised (normal) or sunken (the active command)."""
    px = im.load()
    w, h = im.size
    out = []
    for y in range(h - BTN_H + 1):
        for x in range(w - BTN_W + 1):
            tl, br = px[x, y], px[x + BTN_W - 1, y + BTN_H - 1]
            if tl == WHITE and br == DKSHADOW:
                raised = 1
            elif tl == DKSHADOW and br == WHITE:
                raised = 0
            else:
                continue
            top = WHITE if raised else DKSHADOW
            bot = DKSHADOW if raised else WHITE
            if any(px[x + i, y] != top for i in range(BTN_W - 1)):
                continue
            if any(px[x + i, y + BTN_H - 1] != bot for i in range(1, BTN_W)):
                continue
            # the sides too, or the sunken edge round the drawing area and
            # every other long groove comes back as a button
            if any(px[x, y + j] != top for j in range(BTN_H - 1)):
                continue
            if any(px[x + BTN_W - 1, y + j] != bot for j in range(1, BTN_H)):
                continue
            # the edge has to stop here, or the corner of the sunken frame
            # round the drawing area reads as a 31x22 button
            if x + BTN_W < w and px[x + BTN_W, y] == top:
                continue
            out.append((x, y, raised))
    return out


def main():
    ref, bmdir, out = sys.argv[1], sys.argv[2], sys.argv[3]
    im = Image.open(ref).convert('RGB')
    strips = load_strips(bmdir)
    print('%d strips of 24x15, %d cells'
          % (len(strips), sum(len(c) for c in strips.values())))

    index = {}
    for rid, cells in strips.items():
        for i, c in enumerate(cells):
            index.setdefault(c, []).append((rid, i, 0))
            index.setdefault(disabled(c), []).append((rid, i, 1))

    btns = find_buttons(im)
    print('%d buttons found' % len(btns))

    # Where in the button does the cell sit?  Try every offset once and keep
    # the one that explains the most buttons exactly.
    best = None
    for dy in range(0, BTN_H - CELL_H + 1):
        for dx in range(0, BTN_W - CELL_W + 1):
            n = 0
            for x, y, raised in btns:
                if not raised:
                    continue
                g = tuple(im.crop((x + dx, y + dy,
                                   x + dx + CELL_W, y + dy + CELL_H))
                          .get_flattened_data())
                if g in index:
                    n += 1
            if best is None or n > best[0]:
                best = (n, dx, dy)
    n, dx, dy = best
    print('cell offset (%d,%d) explains %d of %d buttons' % (dx, dy, n, len(btns)))

    rows = []
    misses = []
    for x, y, raised in sorted(btns, key=lambda b: (b[0], b[1])):
        g = tuple(im.crop((x + dx, y + dy, x + dx + CELL_W, y + dy + CELL_H))
                  .get_flattened_data())
        hit = index.get(g)
        if hit is None and not raised:
            # a pressed button draws its image one pixel down and right
            gp = tuple(im.crop((x + dx + 1, y + dy + 1,
                                x + dx + 1 + CELL_W, y + dy + 1 + CELL_H))
                       .get_flattened_data())
            for rid, cells in strips.items():
                for i, c in enumerate(cells):
                    if checked(c, x + dx + 1, y + dy + 1) == gp:
                        hit = [(rid, i, 2)]
                        break
                if hit:
                    break
        if hit:
            rows.append((x, y, hit[0][0], hit[0][1], hit[0][2]))
        else:
            misses.append((x, y, raised))
            rows.append((x, y, -1, -1, 0))

    with open(out, 'w') as f:
        f.write('/* Generated by tools/btnmap.py from the reference screen. */\n')
        f.write('#ifndef JW_LAYOUT_H\n#define JW_LAYOUT_H\n\n')
        f.write('#define BTN_W %d\n#define BTN_H %d\n' % (BTN_W, BTN_H))
        f.write('#define CELL_W %d\n#define CELL_H %d\n' % (CELL_W, CELL_H))
        f.write('#define CELL_DX %d\n#define CELL_DY %d\n\n' % (dx, dy))
        f.write('/* state: 0 normal, 1 disabled (embossed), 2 pressed in */\n')
        f.write('typedef struct { short x, y, strip, cell;'
                ' unsigned char state; } jw_btn_t;\n\n')
        f.write('static const jw_btn_t jw_buttons[] = {\n')
        for x, y, s, c, st in rows:
            f.write('    { %4d, %4d, %4d, %3d, %d },\n' % (x, y, s, c, st))
        f.write('};\n')
        f.write('#define JW_NBUTTONS %d\n\n#endif\n' % len(rows))

    used = collections.Counter(r[2] for r in rows if r[2] >= 0)
    print('strips used:', dict(used))
    if misses:
        print('%d buttons did not match a cell: %s' % (len(misses), misses[:8]))
    print('-> %s' % out)


if __name__ == '__main__':
    main()
