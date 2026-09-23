/* Ask GDI where a wide pen puts its pixels.
 *
 *   gcc -O2 -o tmp/gdiwide.exe tools/gdiwide.c -lgdi32
 *   ./tmp/gdiwide.exe > decomp/res/widepen.txt
 *
 * Nothing is captured: everything is drawn into a memory bitmap, the same way
 * tools/gdicirc.c and tools/gdiarc.c work.
 *
 * Why this exists.  A drawing carries a width per pen (Test3.jww has pen 6 at
 * 2, pen 7 at 3 and pen 8 at 5) and the original hands that width to
 * CreatePen: FUN_004db560 makes its pen with
 *
 *     CreatePen(PS_SOLID, width, colour)
 *
 * and lets GDI draw the line.  A wide line is not a square stamp walked along
 * the line -- GDI gives it round ends, and for an even width it is not even
 * symmetric.  What GDI actually covers, for a line along an axis, is
 *
 *     for each offset d across the line, the pixels from  start + a(d)
 *     to  end + b(d)  along it
 *
 * with d running from -(w/2) to (w-1)/2, so this writes down a(d) and b(d)
 * for every width from 1 to 16 and for both axes.  Width 1 comes out as
 * a = 0, b = -1 -- LineTo leaves its last point out -- which is what the port
 * already did, so the table covers that case as well.
 *
 * Each width is measured four times, at both parities of the starting pixel
 * and at two lengths, and a line that disagrees between them is reported: the
 * table is only worth having if it does not depend on where the line sits.
 */
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define WMAX 16
#define W 96
#define H 96

static unsigned *px;
static HDC dc;

static int lit(int x, int y)
{
    return x >= 0 && y >= 0 && x < W && y < H && px[(size_t)y * W + x] != 0xffffff;
}

static void seg(int w, int x0, int y0, int x1, int y1)
{
    HPEN p, o;
    int i;

    for (i = 0; i < W * H; i++)
        px[i] = 0xffffff;
    p = CreatePen(PS_SOLID, w, RGB(255, 0, 0));
    o = (HPEN)SelectObject(dc, p);
    MoveToEx(dc, x0, y0, 0);
    LineTo(dc, x1, y1);
    SelectObject(dc, o);
    DeleteObject(p);
}

/* the extent at offset d, as a pair (start delta, end delta) */
static int span(int vert, int d, int m0, int m1, int n, int *a, int *b)
{
    int lo = -1, hi = -1, k;

    for (k = 0; k < (vert ? H : W); k++) {
        int x = vert ? n + d : k, y = vert ? k : n + d;
        if (lit(x, y)) {
            if (lo < 0)
                lo = k;
            hi = k;
        }
    }
    if (lo < 0)
        return 0;
    *a = lo - m0;
    *b = hi - m1;
    return 1;
}

int main(void)
{
    BITMAPINFO bi;
    HBITMAP bm;
    int w, vert;

    dc = CreateCompatibleDC(0);
    ZeroMemory(&bi, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biWidth = W;
    bi.bmiHeader.biHeight = -H;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    bm = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, (void **)&px, 0, 0);
    SelectObject(dc, bm);

    printf("# width axis offset start end   -- tools/gdiwide.c\n");
    for (w = 1; w <= WMAX; w++)
        for (vert = 0; vert < 2; vert++) {
            int d;
            for (d = -(w / 2); d <= (w - 1) / 2; d++) {
                int a = 0, b = 0, got = 0, t;
                for (t = 0; t < 4; t++) {
                    int m0 = 24 + (t & 1), m1 = m0 + 40 + (t >> 1), n = 48;
                    int a2, b2;
                    if (vert)
                        seg(w, n, m0, n, m1);
                    else
                        seg(w, m0, n, m1, n);
                    if (!span(vert, d, m0, m1, n, &a2, &b2))
                        continue;
                    if (got && (a2 != a || b2 != b))
                        fprintf(stderr, "w=%d %c d=%d: %d,%d vs %d,%d\n", w,
                                vert ? 'v' : 'h', d, a, b, a2, b2);
                    a = a2;
                    b = b2;
                    got = 1;
                }
                if (got)
                    printf("%d %c %d %d %d\n", w, vert ? 'v' : 'h', d, a, b);
            }
        }
    return 0;
}
