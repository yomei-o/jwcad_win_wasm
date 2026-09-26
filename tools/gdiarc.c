/* Ask GDI what pixels *one* Arc call lights up.
 *
 *   gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32
 *   tmp/gdiarc.exe < tmp/arcs.txt
 *
 * tools/gdicirc.c writes down the ring of a *whole* circle, keyed by the
 * radius alone, because a whole circle is always the same two Arc calls.  A
 * part of a circle is one Arc call with two endpoints, and **GDI's ring
 * depends on those endpoints** -- which is why a table keyed by the radius
 * cannot hold it, and why most of what the port still gets wrong is on
 * partial arcs (RESUME.md,「円弧も 1 本ずつ測れます」).
 *
 * So ask, one arc at a time.  Each line of the input is
 *
 *     <tag> <rp> <odd> <x1> <y1> <x2> <y2>
 *
 * with the two endpoints given as offsets from the middle, the way
 * FUN_00421490 computes them ((int)(rp*cos a) across, -(int)(rp*sin a)
 * down).  `odd` says which box and how many calls:
 *
 *     0   one Arc, in the 2r box
 *     1   one Arc, in the 2r+1 box          (a part of a circle)
 *     2   two Arcs round the whole ring, 2r box     (a whole circle)
 *     3   two Arcs round the whole ring, 2r+1 box
 *
 * The last two are how a whole circle is drawn, and asking for both is the
 * question `日影図`'s one circle raises.  Out comes
 *
 *     <tag> <n>
 *     <dx> <dy>          ... n of them, offsets from the middle
 *
 * Nothing is captured from the screen: the arc is drawn into a memory
 * bitmap, so no window is made and no desktop is needed.
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RMAX 9000
#define PAD 8

int main(void)
{
    HDC dc = CreateCompatibleDC(0);
    BITMAPINFO bi;
    void *bits = 0;
    HBITMAP bm = 0;
    unsigned *px;
    char tag[64];
    int rp, odd, x1, y1, x2, y2;
    int w = 0, h = 0;

    memset(&bi, 0, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    while (scanf("%63s %d %d %d %d %d %d", tag, &rp, &odd,
                 &x1, &y1, &x2, &y2) == 7) {
        int need, cx, cy, x, y, n = 0;

        if (rp < 1 || rp > RMAX) {
            printf("%s 0\n", tag);
            continue;
        }
        need = 2 * rp + 2 * PAD + 2;
        if (need != w) {        /* one bitmap per size, reused down the run */
            if (bm) {
                DeleteObject(bm);
                bm = 0;
            }
            w = h = need;
            bi.bmiHeader.biWidth = w;
            bi.bmiHeader.biHeight = -h;
            bm = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, 0, 0);
            if (!bm) {
                fprintf(stderr, "no bitmap for radius %d\n", rp);
                return 1;
            }
            SelectObject(dc, bm);
            SelectObject(dc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));
            SelectObject(dc, GetStockObject(NULL_BRUSH));
        }
        px = (unsigned *)bits;
        cx = w / 2;
        cy = h / 2;
        memset(bits, 0xff, (size_t)w * h * 4);
        if (odd >= 2) {
            /* A whole circle: FUN_00421490 calls Arc **twice**, (+r,0)
               round to (-r,0) and back, so that the two halves tile the
               ring exactly once (GDI's Arc leaves its far end out, the way
               LineTo does).  odd 2 is the 2r box a whole circle goes in and
               odd 3 the 2r+1 box a part of one goes in -- which is the
               question `日影図`'s one circle asks. */
            int hi = (odd == 3) ? 1 : 0;
            Arc(dc, cx - rp, cy - rp, cx + rp + hi, cy + rp + hi,
                cx + rp, cy, cx - rp, cy);
            Arc(dc, cx - rp, cy - rp, cx + rp + hi, cy + rp + hi,
                cx - rp, cy, cx + rp, cy);
        } else {
            Arc(dc, cx - rp, cy - rp, cx + rp + (odd ? 1 : 0),
                cy + rp + (odd ? 1 : 0),
                cx + x1, cy + y1, cx + x2, cy + y2);
        }
        GdiFlush();
        for (y = 0; y < h; y++)
            for (x = 0; x < w; x++)
                if ((px[(size_t)y * w + x] & 0xffffff) != 0xffffff)
                    n++;
        printf("%s %d\n", tag, n);
        for (y = 0; y < h; y++)
            for (x = 0; x < w; x++)
                if ((px[(size_t)y * w + x] & 0xffffff) != 0xffffff)
                    printf("%d %d\n", x - cx, y - cy);
    }
    return 0;
}
