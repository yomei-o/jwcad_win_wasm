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

    printf("# GDI's own circles, quadrant staircases.  odd r hex\n");
    printf("# odd 1 means the box is 2r+1 across, 0 means 2r.\n");
    for (odd = 0; odd < 2; odd++)
        for (r = 1; r <= RMAX; r++) {
            int lo = odd ? 0 : -1;
            int cx = W / 2, cy = H / 2, qx, qy, i, bad = 0;
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

            /* Walk the top right quadrant from (0,r) to (r,0).  In the
               drawing code the quadrant point (qx,qy) is put on the screen
               at (qx + lo, -qy), so that is how it is read back. */
            memset(bitbuf, 0, sizeof bitbuf);
            qx = 0;
            qy = r;
            while (qx < r || qy > 0) {
                int code;
                if (qx < r && at(qx + 1 + lo, -qy)) {
                    code = 0;                       /* along x              */
                    qx++;
                } else if (qy > 0 && at(qx + lo, -(qy - 1))) {
                    code = 1;                       /* along y              */
                    qy--;
                } else if (qx < r && qy > 0 && at(qx + 1 + lo, -(qy - 1))) {
                    code = 2;                       /* both at once         */
                    qx++;
                    qy--;
                } else {
                    bad = 1;
                    fprintf(stderr, "stuck odd=%d r=%d at %d,%d\n", odd, r, qx, qy);
                    break;
                }
                if (nbit >= 4 * RMAX)
                    break;
                bitbuf[nbit >> 2] |= code << ((nbit & 3) * 2);
                nbit++;
            }
            printf("%d %d ", odd, r);
            if (bad) {
                printf("-\n");          /* the walk does not close: skip it */
                continue;
            }
            for (i = 0; i < (nbit + 3) / 4; i++)
                printf("%02x", bitbuf[i]);
            printf("\n");
        }
    return 0;
}
