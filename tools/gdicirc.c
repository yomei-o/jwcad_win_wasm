/* Write down the circles GDI itself draws, so the port can use them.
 *
 *   gcc -O2 -o tmp/gdicirc.exe tools/gdicirc.c -lgdi32
 *   tmp/gdicirc.exe > decomp/res/circles.txt
 *
 * Nothing is captured: the circles are drawn into a memory bitmap, so no
 * window is created and the screen is never touched.
 *
 * Jw_cad draws a whole circle into a box 2r across and a part of one into a
 * box 2r+1 across, so both are written down.  What is stored is one quadrant
 * as a walk from (0,r) to (r,0), two bits a step: 0 along x, 1 along y, 2
 * both at once (GDI's boundary does take diagonal steps).  src/draw.c
 * mirrors that quadrant the other three ways.  GDI's own circle is not quite symmetric (about half a percent of
 * its pixels are not), and that is the price of storing a quarter of it.
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RMAX 256
#define W (2 * RMAX + 8)
#define H (2 * RMAX + 8)

static unsigned char hit[H][W];

static int at(int x, int y)
{
    x += W / 2;
    y += H / 2;
    return x >= 0 && x < W && y >= 0 && y < H && hit[y][x];
}

int main(void)
{
    HDC dc = CreateCompatibleDC(0);
    BITMAPINFO bi;
    void *bits = 0;
    HBITMAP bm;
    unsigned *px;
    int r, x, y, odd;

    memset(&bi, 0, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biWidth = W;
    bi.bmiHeader.biHeight = -H;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    bm = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, 0, 0);
    SelectObject(dc, bm);
    SelectObject(dc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));
    SelectObject(dc, GetStockObject(NULL_BRUSH));
    px = (unsigned *)bits;

    printf("# GDI's own circles, quadrant staircases.  odd r q hex\n");
    printf("# odd 1 means the box is 2r+1 across, 0 means 2r.\n");
    for (odd = 0; odd < 2; odd++)
        for (r = 1; r <= RMAX; r++) {
            int lo = odd ? 0 : -1;
            int cx = W / 2, cy = H / 2, qx, qy, i, bad = 0, quad;
            unsigned char bitbuf[RMAX + 4];
            int nbit = 0;

            memset(bits, 0xff, (size_t)W * H * 4);
            if (odd) {
                /* a part of a circle: the box is 2r+1 and FUN_00421490 asks
                   GDI for an arc inside it.  The whole ring is what a table
                   can hold, so ask for all of it in one go. */
                Ellipse(dc, cx - r, cy - r, cx + r + 1, cy + r + 1);
            } else {
                /* a whole circle: FUN_00421490 does NOT call Ellipse.  It
                   sets the box to 2r across and calls CDC::Arc twice, from
                   (+r,0) round to (-r,0) and back again -- and GDI's arc is
                   not GDI's ellipse, so the ring is a different one. */
                Arc(dc, cx - r, cy - r, cx + r, cy + r,
                    cx + r, cy, cx - r, cy);
                Arc(dc, cx - r, cy - r, cx + r, cy + r,
                    cx - r, cy, cx + r, cy);
            }
            GdiFlush();
            for (y = 0; y < H; y++)
                for (x = 0; x < W; x++)
                    hit[y][x] = (px[(size_t)y * W + x] & 0xffffff) != 0xffffff;

            /* Walk each quadrant from (0,r) to (r,0).  In the drawing code
               the quadrant point (qx,qy) is put on the screen at
               (qx + lo, -qy) in the top right, (-qx, -qy) in the top left,
               (-qx, qy + lo) in the bottom left and (qx + lo, qy + lo) in
               the bottom right, so that is how each is read back.  The
               2r+1 box is an ellipse and folds the four ways, so only the
               first quadrant is written down for it; the 2r one is two
               arcs and does not fold, so all four are. */
            for (quad = 0; quad < (odd ? 1 : 4); quad++) {
                bad = 0;
                nbit = 0;
                memset(bitbuf, 0, sizeof bitbuf);
                qx = 0;
                qy = r;
                while (qx < r || qy > 0) {
                    int code, ax, ay, bx, by, cx2, cy2;
                    /* where the next three candidates land on the screen */
                    ax = qx + 1; ay = qy;           /* along x   */
                    bx = qx;     by = qy - 1;       /* along y   */
                    cx2 = qx + 1; cy2 = qy - 1;     /* both      */
#define PUT(X, Y) (quad == 0 ? at((X) + lo, -(Y)) : \
                   quad == 1 ? at(-(X), -(Y)) : \
                   quad == 2 ? at(-(X), (Y) + lo) : at((X) + lo, (Y) + lo))
                    if (qx < r && PUT(ax, ay)) {
                        code = 0;
                        qx++;
                    } else if (qy > 0 && PUT(bx, by)) {
                        code = 1;
                        qy--;
                    } else if (qx < r && qy > 0 && PUT(cx2, cy2)) {
                        code = 2;
                        qx++;
                        qy--;
                    } else {
                        bad = 1;
                        fprintf(stderr, "stuck odd=%d r=%d q=%d at %d,%d\n",
                                odd, r, quad, qx, qy);
                        break;
                    }
#undef PUT
                    if (nbit >= 4 * RMAX)
                        break;
                    bitbuf[nbit >> 2] |= code << ((nbit & 3) * 2);
                    nbit++;
                }
                printf("%d %d %d ", odd, r, quad);
                if (bad) {
                    printf("-\n");      /* the walk does not close: skip it */
                    continue;
                }
                for (i = 0; i < (nbit + 3) / 4; i++)
                    printf("%02x", bitbuf[i]);
                printf("\n");
            }
        }
    return 0;
}
