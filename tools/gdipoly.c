/* Ask GDI what Polygon fills, and hold the port's own rule up against it.
 *
 *   gcc -O2 -Isrc -o tmp/gdipoly.exe tools/gdipoly.c src/jww.c src/cp932.c -lgdi32
 *   tmp/gdipoly.exe orig/Ａマンション平面例.jww
 *
 * Nothing is captured: everything goes into a memory bitmap, so no window is
 * created and the screen is never touched -- the same as tools/gdicirc.c.
 *
 * Why.  The original fills a CDataSolid with GDI's Polygon (the wrapper at
 * 0x0049... in the decompilation), and GDI's fill leaves the right and bottom
 * edges out while the port's scanline fill takes them in.  This draws the
 * drawing's own solids both ways and says how many pixels each covers, so the
 * rule can be settled rather than guessed.
 *
 * The view is set up exactly as tests/shot.exe does, so the numbers line up
 * with the pictures scored by tools/scoreall.sh.
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "view.h"

#define W 1264
#define H 741

static HDC dc;
static unsigned *px;
static unsigned char mine[H][W];

static void clear(void)
{
    int i;

    for (i = 0; i < W * H; i++)
        px[i] = 0xffffff;
    memset(mine, 0, sizeof mine);
}

/* GDI: Polygon with a brush of the fill colour and a pen of the same, which
   is what the original selects before it calls. */
static void gdi_poly(const POINT *p, int n)
{
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    HBRUSH br = CreateSolidBrush(RGB(255, 0, 0));
    HPEN op = (HPEN)SelectObject(dc, pen);
    HBRUSH ob = (HBRUSH)SelectObject(dc, br);

    Polygon(dc, p, n);
    SelectObject(dc, op);
    SelectObject(dc, ob);
    DeleteObject(pen);
    DeleteObject(br);
}

/* The port's rule, copied out of src/draw.c's solid(): every scanline between
   the topmost and bottommost vertex, both ends of each span included. */
static void port_poly(const POINT *p, int n)
{
    int ymin = p[0].y, ymax = p[0].y, i, j, y;

    for (i = 1; i < n; i++) {
        if (p[i].y < ymin) ymin = p[i].y;
        if (p[i].y > ymax) ymax = p[i].y;
    }
    if (ymin < 0) ymin = 0;
    if (ymax >= H) ymax = H - 1;
    for (y = ymin; y <= ymax; y++) {
        int xs[8], m = 0, a, b;

        for (i = 0, j = n - 1; i < n; j = i++) {
            int y0 = p[j].y, y1 = p[i].y;
            if ((y0 <= y) == (y1 <= y))
                continue;
            xs[m++] = p[j].x + (int)((double)(y - y0) * (p[i].x - p[j].x)
                                     / (y1 - y0) + 0.5);
        }
        for (i = 1; i < m; i++) {
            int k = xs[i], q = i - 1;
            while (q >= 0 && xs[q] > k) { xs[q + 1] = xs[q]; q--; }
            xs[q + 1] = k;
        }
        for (i = 0; i + 1 < m; i += 2) {
            a = xs[i] < 0 ? 0 : xs[i];
            b = xs[i + 1] >= W ? W - 1 : xs[i + 1];
            for (; a <= b; a++)
                mine[y][a] = 1;
        }
    }
}

static int count_gdi(void)
{
    int n = 0, i;

    for (i = 0; i < W * H; i++)
        if (px[i] != 0xffffff)
            n++;
    return n;
}

static int count_mine(void)
{
    int n = 0, x, y;

    for (y = 0; y < H; y++)
        for (x = 0; x < W; x++)
            n += mine[y][x];
    return n;
}

int main(int argc, char **argv)
{
    BITMAPINFO bi;
    void *bits = 0;
    HBITMAP bm;
    FILE *f;
    unsigned char *b;
    long n;
    jw_drawing d;
    jw_view v;
    rect_t r;
    double hw, hh;
    int i, nsolid = 0, gdi_total = 0, port_total = 0, differ = 0;

    if (argc < 2) {
        fprintf(stderr, "usage: gdipoly <drawing.jww>\n");
        return 2;
    }
    f = fopen(argv[1], "rb");
    if (!f) {
        fprintf(stderr, "cannot open %s\n", argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        fprintf(stderr, "%s: %s\n", argv[1], d.error);
        return 1;
    }

    /* the drawing area of the reference screen, and the sheet in it */
    r.x = 78; r.y = 34; r.w = 1186 - 78; r.h = 720 - 34;
    hw = d.paper_hw;
    hh = d.paper_hh;
    jw_view_fit(&v, &r, hw, hh);

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
    px = (unsigned *)bits;

    printf("%-5s %-28s %8s %8s\n", "#", "corners (screen)", "GDI", "port");
    for (i = 0; i < d.ndrawn; i++) {
        const jw_obj *o = &d.obj[i];
        POINT p[4];
        int k, np = 4, g, m;

        if (o->cls != JW_SOLID)
            continue;
        for (k = 0; k < 4; k++) {
            p[k].x = jw_sx(&v, o->d[2 * k]);
            p[k].y = jw_sy(&v, o->d[2 * k + 1]);
        }
        if (p[3].x == p[2].x && p[3].y == p[2].y)
            np = 3;
        clear();
        gdi_poly(p, np);
        port_poly(p, np);
        g = count_gdi();
        m = count_mine();
        gdi_total += g;
        port_total += m;
        if (g != m)
            differ++;
        if (nsolid < 8)
            printf("%-5d (%d,%d) (%d,%d) (%d,%d) (%d,%d) %8d %8d\n",
                   nsolid, p[0].x, p[0].y, p[1].x, p[1].y,
                   p[2].x, p[2].y, p[3].x, p[3].y, g, m);
        nsolid++;
    }
    printf("\n%d solids: GDI fills %d pixels, the port fills %d "
           "(%d of them disagree)\n", nsolid, gdi_total, port_total, differ);
    return 0;
}
