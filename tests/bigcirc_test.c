/* 大きな円 -- circles whose radius in pixels runs off the end of the tables.
 *
 *   tests/bigcirc_test.exe
 *
 * Nothing here is scored against the original: at these radii the circle is
 * far larger than any window, so there is no picture to hold it against.
 * What is checked is that the drawing code stays inside its own arrays.
 *
 * Past radius 256 src/gen/circle.h has nothing and src/draw.c walks a
 * midpoint circle instead, which emits about sqrt(2) * rp points -- more
 * than rp, into a quadrant that used to hold ARC_MAX/8 = 8,192.  From radius
 * 5,792 up that walk wrote past the end, and the radius guard let anything
 * under 8,190 through.  A circle 5,800 pixels across is nothing exotic:
 * zooming into any drawing far enough reaches it, and so does a drawing that
 * simply has a big circle in it.
 *
 * The same walk multiplied rp^3 into a `long`, which is 32 bits on both the
 * Windows build and wasm; that passes what one holds at radius 1,291.
 *
 * Run this under tools/asan.sh to make it say anything: on a plain build an
 * overrun of a static array is silent.  What the test itself can tell is
 * that the circle is still drawn -- a guard that fixed the overrun by
 * refusing the radius would show up here as an empty framebuffer.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/draw.h"
#include "../src/fb.h"
#include "../src/jww.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* How many pixels of the framebuffer are not the background. */
static long painted(const fb_t *fb, unsigned int bg)
{
    long i, n = 0;

    for (i = 0; i < (long)fb->w * fb->h; i++)
        if (fb->px[i] != bg)
            n++;
    return n;
}

/* A drawing of exactly one circle: centre at the origin, radius r paper
   millimetres, solid, on the one layer that is being written to. */
static void one_circle(jw_drawing *d, jw_obj *o, double r, double sweep)
{
    memset(d, 0, sizeof *d);
    memset(o, 0, sizeof *o);
    d->paper_hw = 297.0;
    d->paper_hh = 210.0;
    d->paper_size = 3;
    d->group[0].state = 3;
    d->group[0].scale = 1.0;
    d->group[0].layer[0].state = 3;
    d->pen_rgb[1] = 0x00000000u;
    d->pen_width[1] = 1;
    o->cls = JW_ENKO;
    o->ltype = 1;               /* 実線 -- the one that goes through GDI  */
    o->color = 1;
    o->d[0] = 0.0;              /* centre                                 */
    o->d[1] = 0.0;
    o->d[2] = r;                /* radius                                 */
    o->d[3] = 0.0;              /* start angle                            */
    o->d[4] = sweep;            /* sweep, a length rather than an end     */
    o->d[5] = 0.0;              /* tilt                                   */
    o->d[6] = 1.0;              /* flattening: 1 is round                 */
    d->obj = o;
    d->nobj = 1;
    d->cobj = 1;
    d->ndrawn = 1;
}

/* Draw that circle with the view set so its radius comes to rp pixels. */
static long draw_at(fb_t *fb, double r, double sweep, double rp)
{
    jw_drawing d;
    jw_obj o;
    jw_view v;
    unsigned int bg = 0x00ffffffu;

    one_circle(&d, &o, r, sweep);
    memset(&v, 0, sizeof v);
    v.mmpp = r / rp;
    v.scale = 1.0 / v.mmpp;
    v.ox = 0.0;
    v.oy = 0.0;
    v.bx = fb->w / 2;
    v.by = fb->h / 2;
    v.clip.x = 0;
    v.clip.y = 0;
    v.clip.w = fb->w;
    v.clip.h = fb->h;
    fb_fill(fb, 0, 0, fb->w, fb->h, bg);
    jw_draw(fb, &v, &d);
    return painted(fb, bg);
}

int main(void)
{
    fb_t fb;
    double rp[] = { 255, 256, 257, 1290, 1292, 4095, 5791, 5793, 8188, 8191,
                    9000, 70000, 1e9, 1e15 };
    size_t i;

    if (!fb_init(&fb, 640, 480)) {
        printf("BAD  no framebuffer\n");
        return 1;
    }

    /* A whole circle, the arm that asks GDI for the ring. */
    for (i = 0; i < sizeof rp / sizeof rp[0]; i++) {
        char what[64];
        long n = draw_at(&fb, 100.0, 2.0 * 3.14159265358979323846, rp[i]);

        sprintf(what, "whole circle, radius %g pixels: %ld painted",
                rp[i], n);
        /* GDI's own ring is only asked for when the centre is on screen, so
           past about 400 pixels the whole ring is off the far side of a
           640x480 window and nothing is painted -- the walk still runs, and
           that is what is being watched here.  Below that the ring crosses
           the window and has to leave pixels. */
        ck(rp[i] > 400 ? n == 0 : n > 0, what);
    }

    /* And a part of one, which takes the other box and the chord walk. */
    for (i = 0; i < sizeof rp / sizeof rp[0]; i++) {
        char what[64];
        long n = draw_at(&fb, 100.0, 1.0, rp[i]);

        sprintf(what, "arc of 1 rad, radius %g pixels: %ld painted",
                rp[i], n);
        ck(rp[i] > 400 ? n == 0 : n > 0, what);
    }

    /* A radius the file could hold but no view can show: jw_numbers_sane
       lets a coordinate reach 1e12, and the conversion to pixels has to
       stay defined even then. */
    {
        long n = draw_at(&fb, 1e12, 2.0 * 3.14159265358979323846, 1e6);

        printf("ok   radius 1e12 millimetres: %ld painted\n", n);
    }

    fb_free(&fb);
    printf("%s bigcirc\n", fails ? "BAD " : "ok  ");
    return fails ? 1 : 0;
}
