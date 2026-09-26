/* 線の刻み -- every line type, every direction, and nothing outside the clip.
 *
 *   tests/linewalk_test.exe
 *
 * Nothing here is scored against the original: a line at 137 degrees on a
 * 200x150 canvas has no reference picture.  What is checked is the two
 * things the drawing code owes its caller whatever it is handed.
 *
 * **It stays inside the clip.**  src/draw.c's walk puts every pixel through
 * put(), which cuts against v->clip -- but the framebuffer is bigger than
 * the clip, so a pixel that escapes the cut still lands inside the
 * allocation and no sanitizer says a word.  Here the framebuffer is painted
 * with a sentinel first and everything outside the clip is counted
 * afterwards: that catches an escape which ASan cannot.  (ui.c's checker()
 * was found writing past the framebuffer itself, which ASan did catch; this
 * is the other half of the same question.)
 *
 * **It comes back.**  The walk steps once per pixel of whichever axis is the
 * longer *in pixels*.  The far coordinates below are lines nowhere near the
 * sheet, which is where that used to go wrong.
 *
 * Measured, so that the comment does not claim more than it should: with
 * src/view.h's clamp taken back out (a bare `(int)` on a value of 9e11,
 * which is undefined) this test still comes back, and with src/draw.c's
 * throw-out of lines that cannot touch the window taken out as well it
 * still comes back.  So neither guard is *needed* to terminate on these
 * cases -- the cut against the view already bounds both axes for a sloping
 * line, and a dead-level or dead-upright one has a span of zero on the
 * other axis.  They stay because the conversion has to be defined and
 * because drawing what cannot be seen is waste, not because this test can
 * show a hang without them.
 *
 * The sweep is 9 line types x 52 directions x 9 lengths x 3 pen widths,
 * which is 12,636 lines and about a second.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/draw.h"
#include "../src/fb.h"
#include "../src/jww.h"
#include "../src/view.h"

#define FBW 200
#define FBH 150
#define CLX 20
#define CLY 15
#define CLW 140
#define CLH 105

#define SENTINEL 0x00123456u

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* A drawing of one line, on the layer that is being written to. */
static void one_line(jw_drawing *d, jw_obj *o, double x0, double y0,
                     double x1, double y1, int ltype, int pen)
{
    memset(d, 0, sizeof *d);
    memset(o, 0, sizeof *o);
    d->paper_hw = 297.0;
    d->paper_hh = 210.0;
    d->paper_size = 3;
    d->group[0].state = 3;
    d->group[0].scale = 1.0;
    d->group[0].layer[0].state = 3;
    d->pen_rgb[pen] = 0x00000000u;
    d->pen_width[pen] = pen == 3 ? 5 : 1;       /* one wide pen in the mix */
    o->cls = JW_SEN;
    o->ltype = (unsigned char)ltype;
    o->color = (unsigned short)pen;
    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    d->obj = o;
    d->nobj = 1;
    d->cobj = 1;
    d->ndrawn = 1;
}

/* Draw it and say how many pixels landed outside the clip. */
static long outside(fb_t *fb, double x0, double y0, double x1, double y1,
                    int ltype, int pen)
{
    jw_drawing d;
    jw_obj o;
    jw_view v;
    long i, n = 0;
    int x, y;

    one_line(&d, &o, x0, y0, x1, y1, ltype, pen);
    memset(&v, 0, sizeof v);
    v.mmpp = 1.0;
    v.scale = 1.0;
    v.ox = 0.0;
    v.oy = 0.0;
    v.bx = FBW / 2;
    v.by = FBH / 2;
    v.clip.x = CLX;
    v.clip.y = CLY;
    v.clip.w = CLW;
    v.clip.h = CLH;
    for (i = 0; i < (long)FBW * FBH; i++)
        fb->px[i] = SENTINEL;
    jw_draw(fb, &v, &d);
    for (y = 0; y < FBH; y++)
        for (x = 0; x < FBW; x++) {
            if (x >= CLX && x < CLX + CLW && y >= CLY && y < CLY + CLH)
                continue;
            if (fb->px[(size_t)y * FBW + x] != SENTINEL)
                n++;
        }
    return n;
}

int main(void)
{
    fb_t fb;
    static const double len[] = { 0.0, 0.5, 1.0, 3.0, 17.0, 60.0, 120.0,
                                  4000.0, 9e11 };
    static const int pens[] = { 1, 3, 9 };
    int lt, a, li, pi;
    long bad = 0, drawn = 0;

    if (!fb_init(&fb, FBW, FBH)) {
        printf("BAD  no framebuffer\n");
        return 1;
    }

    for (lt = 1; lt <= 9; lt++)
        for (a = 0; a < 360; a += 7)
            for (li = 0; li < (int)(sizeof len / sizeof len[0]); li++)
                for (pi = 0; pi < 3; pi++) {
                    double t = a * 3.14159265358979323846 / 180.0;
                    double dx = cos(t) * len[li], dy = sin(t) * len[li];

                    bad += outside(&fb, -dx / 2, -dy / 2, dx / 2, dy / 2,
                                   lt, pens[pi]);
                    drawn++;
                }
    ck(!bad, "every line type, direction and length stays inside the clip");
    printf("     %ld lines drawn, %ld pixels outside the clip\n", drawn, bad);

    /* And the lines that are nowhere near the sheet: dead level, dead
       upright and sloping, each with one axis inside the window and the
       other a long way off.  jw_numbers_sane lets a coordinate reach 1e12. */
    {
        long n = 0;

        n += outside(&fb, -50.0, 9e11, 50.0, 9e11, 1, 1);   /* level, far up */
        n += outside(&fb, 9e11, -50.0, 9e11, 50.0, 1, 1);   /* upright, far  */
        n += outside(&fb, -9e11, 9e11, 9e11, 9e11 + 1, 1, 1);
        n += outside(&fb, -9e11, -9e11, 9e11, 9e11, 1, 1);  /* corner to corner */
        n += outside(&fb, 0.0, 0.0, 9e11, 1.0, 1, 1);
        ck(!n, "lines a long way off the sheet: nothing outside, and it returns");
    }

    /* A zero-length line in every type: the walk has to stop at once. */
    {
        long n = 0;
        for (lt = 1; lt <= 9; lt++)
            n += outside(&fb, 10.0, 10.0, 10.0, 10.0, lt, 1);
        ck(!n, "a line of no length in every type");
    }

    fb_free(&fb);
    printf("%s linewalk\n", fails ? "BAD " : "ok  ");
    return fails ? 1 : 0;
}
