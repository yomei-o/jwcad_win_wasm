/* 図形の仮置き -- the figure that hangs off the cursor before it is placed.
 *
 *   tests/figprev_test.exe
 *
 * The original shows the whole figure, at the cursor, the moment it has
 * been read, and it goes on showing it after one has been put down.  Four
 * things were taken off its own window and all four are checked here:
 *
 *   * it is there at all.  decomp/res/fig.jws's 95 KB cousin
 *     《図形01》建築１/17対面キッチン.jws was read in and the cursor moved
 *     to two places; 141 ff0000 pixels came back each time and nowhere
 *     else in the drawing area (tools/probe80.sh)
 *   * it moves by exactly what the cursor moves by -- the second set of
 *     141 was the first shifted by (200, 100), pixel for pixel (probe80)
 *   * it is where the click puts it: every one of those 141 pixels was a
 *     pixel of the figure once it had been placed (tools/probe81.sh)
 *   * it is still there afterwards (tools/probe83.sh)
 *
 * and the fifth is what a **text** inside it looks like: not its glyphs
 * but its box.  tools/probe82.sh pasted a line, a circle, a point and the
 * text 'AW' and compared the picture on the cursor with the one placed:
 * everything matched but the text, which was an empty rectangle 18 by 18
 * pixels where the glyphs would be -- the text's own box, (d0,d1) to
 * (d2,d3) and d5 out to the side, to the pixel.  The 文字 command's own
 * provisional text is the same box (probe83), so that is checked too.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/pens.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

/* every pixel of the drawing area that is 仮表示色, and every pixel that is
   not the paper, as two bitmaps the size of the window */
static unsigned char *mark(int want_kari)
{
    const fb_t *fb = app_fb();
    unsigned char *m = (unsigned char *)calloc((size_t)fb->w * fb->h, 1);
    rect_t r;
    int x, y;
    unsigned int paper;

    ui_view_rect(fb->w, fb->h, &r);
    paper = fb->px[(size_t)(r.y + r.h / 2) * fb->w + r.x + 2] & 0xffffffu;
    for (y = r.y; y < r.y + r.h; y++)
        for (x = r.x; x < r.x + r.w; x++) {
            unsigned int p = fb->px[(size_t)y * fb->w + x] & 0xffffffu;

            if (want_kari ? p == JW_KARI_RGB : p != paper)
                m[(size_t)y * fb->w + x] = 1;
        }
    return m;
}

/* the box round what is marked */
static void box(const unsigned char *m, int *x0, int *y0, int *x1, int *y1)
{
    const fb_t *fb = app_fb();
    int x, y;

    *x0 = *y0 = 1 << 30;
    *x1 = *y1 = -1;
    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (m[(size_t)y * fb->w + x]) {
                if (x < *x0) *x0 = x;
                if (x > *x1) *x1 = x;
                if (y < *y0) *y0 = y;
                if (y > *y1) *y1 = y;
            }
}

static int count(const unsigned char *m)
{
    const fb_t *fb = app_fb();
    size_t i, n = (size_t)fb->w * fb->h, k = 0;

    for (i = 0; i < n; i++)
        k += m[i];
    return (int)k;
}

/* how many of a's pixels are not in b, b read with the whole thing moved by
   (dx, dy) */
static int missing(const unsigned char *a, const unsigned char *b,
                   int dx, int dy)
{
    const fb_t *fb = app_fb();
    int x, y, k = 0;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++) {
            int u = x + dx, v = y + dy;

            if (!a[(size_t)y * fb->w + x])
                continue;
            if (u < 0 || v < 0 || u >= fb->w || v >= fb->h
                || !b[(size_t)v * fb->w + u])
                k++;
        }
    return k;
}

static void figure(void)
{
    unsigned char *m1, *m2, *placed, *again;
    long n;
    unsigned char *b = slurp("decomp/res/fig.jws", &n);

    printf("-- 図形読込 decomp/res/fig.jws\n");
    if (!b) {
        ck(0, "  decomp/res/fig.jws が読めない");
        return;
    }
    app_new();
    ck(app_figure(b, n) != 0, "  図形が読める");
    free(b);
    /* 倍率 6, so the 6mm box is sixty pixels across and not ten: a
       ten-pixel box turns over too few pixels for the comparisons below to
       say anything. */
    jw_cmd_figure_at(6.0, 0.0);

    /* nothing until the mouse has moved: the original paints it on the
       move.  Both places are kept to the right of the pinned pixel, which
       is near the middle of the view: the port's truncation is toward zero
       and so changes direction there (jw_px_bend), and a figure that
       straddles the seam comes out a pixel different.  That is the port's
       screen rounding, which belongs to its own measurements, not to the
       figure hanging off the cursor. */
    app_move(700, 480);
    app_paint();
    m1 = mark(1);
    printf("     カーソル (700,480) で 仮 %d 画素\n", count(m1));
    ck(count(m1) > 10, "  カーソルのところに図形が出る");

    /* and it goes with the cursor, pixel for pixel */
    app_move(820, 550);
    app_paint();
    m2 = mark(1);
    printf("     カーソル (820,550) で 仮 %d 画素\n", count(m2));
    /* The original's picture moved pixel for pixel: the 141 ff0000 pixels
       at the second place were the 141 at the first, shifted by exactly
       what the cursor had moved by. */
    {
        int a0, b0, a1, b1, c0, e0, c1, e1, dx, dy;

        box(m1, &a0, &b0, &a1, &b1);
        box(m2, &c0, &e0, &c1, &e1);
        dx = c0 - a0;
        dy = e0 - b0;
        printf("     枠 %d,%d..%d,%d -> %d,%d..%d,%d、"
               "ずれ (%d,%d)\n", a0, b0, a1, b1, c0, e0, c1, e1, dx, dy);
        ck(dx == 120 && dy == 70 && c1 - a1 == dx && e1 - b1 == dy,
           "  枠がカーソルと同じだけ動く");
        printf("     その分だけ滑らすと "
               "%d 画素が外れる\n",
               missing(m1, m2, dx, dy));
        ck(missing(m1, m2, dx, dy) == 0,
           "  絵はそのまま付いてくる");
    }

    /* where it hangs is where the click puts it */
    app_press(820, 550, 0);
    app_move(820, 550);
    app_paint();
    placed = mark(0);
    printf("     置いたあと 紙でない画素 %d、仮置きのうち外れた %d\n",
           count(placed), missing(m2, placed, 0, 0));
    ck(missing(m2, placed, 0, 0) == 0, "  仮置きの画素は置いたものに入る");

    /* and it is still on the cursor */
    app_move(940, 620);
    app_paint();
    again = mark(1);
    printf("     もう一度 仮 %d 画素\n", count(again));
    ck(count(again) > 10, "  置いたあともまだ付いてくる");
    free(m1);
    free(m2);
    free(placed);
    free(again);
}

/* The provisional text is its box: nothing inside it. */
static void textbox(void)
{
    const fb_t *fb;
    unsigned char *m;
    int x, y, x0 = 1 << 30, x1 = -1, y0 = 1 << 30, y1 = -1, inside = 0;

    printf("-- 文字の仮表示は箱\n");
    app_new();
    app_command(JW_CMD_MOJI);
    app_key('A');
    app_key('W');
    app_move(700, 500);
    app_paint();
    fb = app_fb();
    m = mark(1);
    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (m[(size_t)y * fb->w + x]) {
                if (x < x0) x0 = x;
                if (x > x1) x1 = x;
                if (y < y0) y0 = y;
                if (y > y1) y1 = y;
            }
    ck(x1 > x0 + 4 && y1 > y0 + 4, "  仮表示が出ている");
    for (y = y0 + 2; y <= y1 - 2; y++)
        for (x = x0 + 2; x <= x1 - 2; x++)
            inside += m[(size_t)y * fb->w + x];
    printf("     枠 %d..%d x %d..%d、内側 %d 画素\n", x0, x1, y0, y1, inside);
    ck(inside == 0, "  枠の内側は空（字形ではない）");
    free(m);

    /* and once it is placed the glyphs are there */
    app_press(700, 500, 0);
    app_move(900, 600);
    app_paint();
    {
        unsigned char *p = mark(0);
        int k = 0;

        for (y = y0 + 2; y <= y1 - 2; y++)
            for (x = x0 + 2; x <= x1 - 2; x++)
                k += p[(size_t)y * fb->w + x];
        printf("     置いたあと同じ中に %d 画素\n", k);
        ck(k > 0, "  置いたら字形が出る");
        free(p);
    }
}

int main(void)
{
    app_resize(1264, 741);
    figure();
    textbox();
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
