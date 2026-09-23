/* Ask GDI what a dashed arc looks like.
 *
 *   gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32
 *   tmp/gdiarc.exe <r> <style> [a0deg sweepdeg]   # one arc, as a picture
 *   tmp/gdiarc.exe --table > decomp/res/arcdash.txt
 *
 * Nothing is captured: everything is drawn into a memory bitmap, so no window
 * is created and the screen is never touched -- the same as tools/gdicirc.c.
 *
 * Why this exists.  The port dashes a straight line the way the original
 * does, by walking the pattern and drawing each run of set bits as its own
 * short line, and it copied that rule to arcs.  The original does not: it
 * hands the whole arc to GDI with a styled pen and lets GDI do the dashing.
 * FUN_004b50e0 (CDC::Arc) makes it with
 *
 *     ExtCreatePen(style | PS_GEOMETRIC | PS_JOIN_BEVEL, width, &brush, 0, 0)
 *
 * -- a predefined style, no user array -- and then calls Arc once.  Nothing
 * slices the sweep: FUN_00421490 calls CDC::Arc once for an arc and twice for
 * a whole circle, and neither of its callers loops.
 *
 * So the dashes on an arc are GDI's, and this writes down where GDI puts
 * them.  Held up against the port's own walk it says whether the difference
 * is the phase, the direction, or the rule for advancing.
 *
 * `style` is the PS_ constant: 1 PS_DASH, 2 PS_DOT, 3 PS_DASHDOT,
 * 4 PS_DASHDOTDOT.  0 (PS_SOLID) is there to check the boundary itself.
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RMAX 64
#define PAD 8
#define W (2 * RMAX + 2 * PAD)
#define H (2 * RMAX + 2 * PAD)

static HDC dc;
static unsigned *px;

/* Draw one arc and leave the pixels in px.  The box is the one Jw_cad uses:
   2r+1 across for a part of a circle (FUN_00421490's second CRect). */
static void draw(int r, int style, double a0, double sweep)
{
    int cx = W / 2, cy = H / 2;
    LOGBRUSH lb;
    HPEN pen, old;
    double a1 = a0 + sweep;
    int i;

    for (i = 0; i < W * H; i++)
        px[i] = 0xffffff;
    memset(&lb, 0, sizeof lb);
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(255, 0, 0);
    /* style >= 100 asks for the geometric pen with (style - 100) as the dash
       style, so the plain geometric outline can be looked at on its own */
    if (style >= 100)
        pen = ExtCreatePen((style - 100) | PS_GEOMETRIC | PS_JOIN_BEVEL, 1,
                           &lb, 0, 0);
    else if (style == PS_SOLID)
        pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    else
        pen = ExtCreatePen(style | PS_GEOMETRIC | PS_JOIN_BEVEL, 1, &lb, 0, 0);
    old = (HPEN)SelectObject(dc, pen);
    /* GDI's Arc runs counter-clockwise from the first radial to the second,
       and the y axis points down, so the angles are negated on the way in --
       which is what the port's own screen coordinates do as well. */
    Arc(dc, cx - r, cy - r, cx + 1 + r, cy + 1 + r,
        cx + (int)(r * 2.0 * cos(a0)), cy - (int)(r * 2.0 * sin(a0)),
        cx + (int)(r * 2.0 * cos(a1)), cy - (int)(r * 2.0 * sin(a1)));
    SelectObject(dc, old);
    DeleteObject(pen);
}

static int lit(int x, int y)
{
    return px[(size_t)y * W + x] != 0xffffff;
}

int main(int argc, char **argv)
{
    BITMAPINFO bi;
    void *bits = 0;
    HBITMAP bm;
    int r, style, x, y;
    double a0 = 0.0, sweep = 6.283185307179586;

    dc = CreateCompatibleDC(0);
    memset(&bi, 0, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biWidth = W;
    bi.bmiHeader.biHeight = -H;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    bm = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, 0, 0);
    SelectObject(dc, bm);
    SelectObject(dc, GetStockObject(NULL_BRUSH));
    px = (unsigned *)bits;

    if (argc > 1 && !strcmp(argv[1], "--table")) {
        /* Every style at every radius, as the list of lit pixels round the
           boundary.  What src/draw.c needs is which of them are on, in the
           order the boundary walk visits them; the walk itself is already in
           src/gen/circle.h, so this only has to say on or off. */
        printf("# GDI's dashed arcs: r style then one line of 0/1 per lit\n");
        printf("# pixel of the 2r+1 box, scanned row by row.\n");
        for (style = 1; style <= 4; style++)
            for (r = 2; r <= RMAX; r++) {
                draw(r, style, 0.0, 6.283185307179586);
                printf("%d %d", r, style);
                for (y = 0; y < H; y++)
                    for (x = 0; x < W; x++)
                        if (lit(x, y))
                            printf(" %d,%d", x - W / 2, y - H / 2);
                printf("\n");
            }
        return 0;
    }

    r = argc > 1 ? atoi(argv[1]) : 20;
    style = argc > 2 ? atoi(argv[2]) : PS_DASH;
    if (argc > 4) {
        a0 = atof(argv[3]) * 3.14159265358979323846 / 180.0;
        sweep = atof(argv[4]) * 3.14159265358979323846 / 180.0;
    }
    draw(r, style, a0, sweep);
    printf("r=%d style=%d a0=%g sweep=%g   box %d across\n",
           r, style, a0, sweep, 2 * r + 1);
    for (y = H / 2 - r - 2; y <= H / 2 + r + 2; y++) {
        for (x = W / 2 - r - 2; x <= W / 2 + r + 2; x++)
            putchar(lit(x, y) ? '#' : '.');
        putchar('\n');
    }
    return 0;
}
