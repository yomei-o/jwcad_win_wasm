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
 * partial arcs (docs\notes-pixels.md,「円弧も 1 本ずつ測れます」).
 *
 * So ask, one arc at a time.  Each line of the input is
 *
 *     <tag> <rp> <odd> <x1> <y1> <x2> <y2>
 *
 * with the two endpoints given as offsets from the middle, the way
 * FUN_00421490 computes them ((int)(rp*cos a) across, -(int)(rp*sin a)
 * down).  `odd` says which box and how many calls:
 *
 *     6   one PolyBezier over the same arc, in the 2r+1 box
 *     0   one Arc, in the 2r box
 *     1   one Arc, in the 2r+1 box          (what the port uses)
 *     4   one Arc, in the 2r+2 box
 *     2   two Arcs round the whole ring, 2r box     (a whole circle)
 *     3   two Arcs round the whole ring, 2r+1 box
 *     5   two Arcs round the whole ring, 2r+2 box
 *
 * Two Arcs is how a whole circle is drawn, and asking for both boxes is the
 * question `日影図`'s one circle raised -- GDI answered 206 pixels on the
 * original's ink against 97 (RESUME.md).  The 2r+2 box is here because a
 * ring half a pixel bigger is what `Ａマンション平面例`'s partial arcs
 * measure as wanting.  Out comes
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
#include <math.h>

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
        if (odd == 2 || odd == 3 || odd == 5) {
            /* A whole circle: FUN_00421490 calls Arc **twice**, (+r,0)
               round to (-r,0) and back, so that the two halves tile the
               ring exactly once (GDI's Arc leaves its far end out, the way
               LineTo does).  odd 2 is the 2r box a whole circle goes in and
               odd 3 the 2r+1 box a part of one goes in -- which is the
               question `日影図`'s one circle asks. */
            int hi = (odd == 3) ? 1 : (odd == 5) ? 2 : 0;
            Arc(dc, cx - rp, cy - rp, cx + rp + hi, cy + rp + hi,
                cx + rp, cy, cx - rp, cy);
            Arc(dc, cx - rp, cy - rp, cx + rp + hi, cy + rp + hi,
                cx - rp, cy, cx + rp, cy);
        } else if (odd == 7 || odd == 8) {
            /* Ask GDI what an Arc *is*, rather than guessing.
             *
             * BeginPath / Arc / EndPath puts the arc into a path, and
             * GetPath hands back the records it kept.  If the types come
             * back as PT_BEZIERTO then GDI turns an arc into cubic Beziers
             * and the question "is it Beziers?" is settled from the inside.
             * FlattenPath then gives GDI's **own** polyline for it, which
             * is a recipe the port can follow: its line drawing is already
             * exact against GDI.
             *
             *   odd 7  print the path records (type, x, y), not pixels
 *   odd 9  flatten first, so the polyline itself comes out
             *   odd 8  flatten and stroke it, so the pixels can be held
             *          against a plain Arc's
             */
            POINT pp[4096];
            BYTE tt[4096];
            int got, q;

            BeginPath(dc);
            Arc(dc, cx - rp, cy - rp, cx + rp + 1, cy + rp + 1,
                cx + x1, cy + y1, cx + x2, cy + y2);
            EndPath(dc);
            if (odd == 8) {
                FlattenPath(dc);
                StrokePath(dc);
            } else if (odd == 9) {
                /* GDI's own flattening of the same arc: the polyline it
                 * would stroke.  The port's line drawing is already exact
                 * against GDI, so this is a recipe it can follow. */
                FlattenPath(dc);
                got = GetPath(dc, pp, tt, 4096);
                printf("%s %d\n", tag, got < 0 ? 0 : got);
                for (q = 0; q < got; q++)
                    printf("%d %d\n", (int)pp[q].x - cx,
                           (int)pp[q].y - cy);
                AbortPath(dc);
                continue;
            } else {
                got = GetPath(dc, pp, tt, 4096);
                printf("%s %d\n", tag, got < 0 ? 0 : got);
                for (q = 0; q < got; q++)
                    printf("%d %d\n", (int)pp[q].x - cx,
                           (int)pp[q].y - cy);
                fprintf(stderr, "%s types:", tag);
                for (q = 0; q < got && q < 40; q++)
                    fprintf(stderr, " %d", (int)tt[q]);
                fprintf(stderr, "\n");
                AbortPath(dc);
                continue;
            }
        } else if (odd == 6) {
            /* The same arc as odd 1, but handed over as cubic Beziers.
             *
             * Why ask: tools/arcsame.py showed the ring depends on **both**
             * ends together, not just the start -- stretching the far end
             * moves pixels near the near one.  A walk that accumulates from
             * the start cannot do that; splitting the curve into Beziers
             * whose control points depend on the whole sweep can.  If Arc
             * and PolyBezier paint the same pixels, the port can flatten
             * the same Beziers and hand the pieces to its own line drawing,
             * which is already exact against GDI. */
            double l = cx - rp, t = cy - rp, r = cx + rp + 1, b = cy + rp + 1;
            double mx = (l + r) / 2.0, my = (t + b) / 2.0;
            double R = (r - l) / 2.0;
            /* Angles the way the caller gives its ends: y counted up, so
             * the sweep from the first point to the second is positive.
             * Taking them screen-side (y down) turns the arc into its
             * complement, which is what the first run of this measured. */
            double a0 = atan2(my - (cy + y1), (cx + x1) - mx);
            double a1 = atan2(my - (cy + y2), (cx + x2) - mx);
            double sweep = a1 - a0;
            POINT pts[64];
            int np = 0, seg, nseg;
            double step, a;

            while (sweep <= 0.0)
                sweep += 6.283185307179586;
            nseg = (int)(sweep / 1.5707963267948966) + 1;
            if (nseg > 20)
                nseg = 20;
            step = sweep / nseg;
            a = a0;
            pts[np].x = (LONG)floor(mx + R * cos(a) + 0.5);
            pts[np].y = (LONG)floor(my - R * sin(a) + 0.5);
            np++;
            for (seg = 0; seg < nseg && np + 3 < 64; seg++) {
                double k = 4.0 / 3.0 * tan(step / 4.0);
                double b0 = a, b1 = a + step;
                double x0 = mx + R * cos(b0), y0 = my - R * sin(b0);
                double x3 = mx + R * cos(b1), y3 = my - R * sin(b1);
                double c1x = x0 - k * R * sin(b0), c1y = y0 - k * R * cos(b0);
                double c2x = x3 + k * R * sin(b1), c2y = y3 + k * R * cos(b1);

                pts[np].x = (LONG)floor(c1x + 0.5);
                pts[np].y = (LONG)floor(c1y + 0.5);
                np++;
                pts[np].x = (LONG)floor(c2x + 0.5);
                pts[np].y = (LONG)floor(c2y + 0.5);
                np++;
                pts[np].x = (LONG)floor(x3 + 0.5);
                pts[np].y = (LONG)floor(y3 + 0.5);
                np++;
                a = b1;
            }
            PolyBezier(dc, pts, np);
        } else {
            int hi = (odd == 1) ? 1 : (odd == 4) ? 2 : 0;
            Arc(dc, cx - rp, cy - rp, cx + rp + hi, cy + rp + hi,
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
