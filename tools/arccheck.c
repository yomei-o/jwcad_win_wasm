/* Hold the port's own `gdi_arc` against the Python model, arc for arc.
 *
 *   sh tools/arccheck.sh
 *
 * `tools/arcfull.py` says the model matches GDI on 472 of 472 arcs.  That
 * settles the *model*; it says nothing about whether the C in `src/draw.c`
 * is the same thing, and the fifteen-drawing score cannot tell a slip in
 * one quadrant from a drawing that was always going to differ.  So this
 * opens `src/draw.c` with `-Dstatic=` -- the trick `tmp/gdiline.c` used for
 * the line walk -- calls `gdi_arc` straight into a framebuffer, and prints
 * the pixels for `tools/arccheck.py` to compare.
 *
 * One line an arc on stdin:
 *
 *     <tag> <l> <t> <r> <b> <x1> <y1> <x2> <y2>
 *
 * and out comes `<tag> <n>` followed by n lines of `x y`.
 */
#include <stdio.h>
#include <stdlib.h>

#include "fb.h"

#define W 900
#define H 900

void gdi_arc(fb_t *fb, const rect_t *c, int l, int t, int r, int b,
             int x1, int y1, int x2, int y2, unsigned int col, int wide);

int main(void)
{
    static fb_t fb;
    rect_t clip;
    char tag[64];
    int l, t, r, b, x1, y1, x2, y2, x, y;

    if (!fb_init(&fb, W, H))
        return 1;
    clip.x = 0; clip.y = 0; clip.w = W; clip.h = H;
    while (scanf("%63s %d %d %d %d %d %d %d %d", tag, &l, &t, &r, &b,
                 &x1, &y1, &x2, &y2) == 9) {
        int n = 0;

        for (y = 0; y < H; y++)
            for (x = 0; x < W; x++)
                fb.px[y * W + x] = 0xffffffu;
        gdi_arc(&fb, &clip, l, t, r, b, x1, y1, x2, y2, 0u, 1);
        for (y = 0; y < H; y++)
            for (x = 0; x < W; x++)
                if (fb.px[y * W + x] != 0xffffffu)
                    n++;
        printf("%s %d\n", tag, n);
        for (y = 0; y < H; y++)
            for (x = 0; x < W; x++)
                if (fb.px[y * W + x] != 0xffffffu)
                    printf("%d %d\n", x, y);
    }
    return 0;
}
