/* 枠の外に出ないか -- every element class, dragged across the clip's edges.
 *
 *   tests/clipwalk_test.exe
 *
 * The companion to tests/linewalk_test.c, which does the same for lines.
 *
 * src/draw.c cuts every pixel against `v->clip`, which is the drawing area
 * -- and the drawing area is *smaller* than the framebuffer, because the
 * toolbars and the status line take the rest.  A pixel that gets past that
 * cut therefore lands inside the allocation and no sanitizer says a word;
 * it just paints over a button.  The framebuffer here is painted with a
 * sentinel first and everything outside the clip is counted afterwards.
 *
 * Every class is walked across all four edges and both diagonals, at sizes
 * from under a pixel to far larger than the window, so that each one is
 * partly in and partly out at some point.  Nothing is scored against the
 * original: this is about the cut, not the picture.
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
#define PI 3.14159265358979323846

static int fails;
static fb_t fb;
/* "flag byte, text, NUL", which is what jw_str walks; offset 1 is the text */
static char pool[] = "\0\x93\xfa\x96\x7b\x8c\xea abc\0";

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void base(jw_drawing *d, jw_obj *o)
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
    d->pen_rgb[3] = 0x00ff0000u;
    d->pen_width[3] = 5;                /* a wide pen in the mix */
    d->pool = pool;
    d->npool = (int)sizeof pool;
    o->color = 1;
    o->ltype = 1;
    d->obj = o;
    d->nobj = 1;
    d->cobj = 1;
    d->ndrawn = 1;
}

/* Draw that one element and say how many pixels landed outside the clip. */
static long outside(jw_drawing *d)
{
    jw_view v;
    long i, n = 0;
    int x, y;

    memset(&v, 0, sizeof v);
    v.mmpp = 1.0;
    v.scale = 1.0;
    v.bx = FBW / 2;
    v.by = FBH / 2;
    v.clip.x = CLX;
    v.clip.y = CLY;
    v.clip.w = CLW;
    v.clip.h = CLH;
    for (i = 0; i < (long)FBW * FBH; i++)
        fb.px[i] = SENTINEL;
    jw_draw(&fb, &v, d);
    for (y = 0; y < FBH; y++)
        for (x = 0; x < FBW; x++) {
            if (x >= CLX && x < CLX + CLW && y >= CLY && y < CLY + CLH)
                continue;
            if (fb.px[(size_t)y * FBW + x] != SENTINEL)
                n++;
        }
    return n;
}

/* The places an element's middle is put: well outside every edge, on each
   edge, and in the middle.  In paper millimetres, which here is pixels. */
static const double AT[] = { -140, -75, -71, -70, -69, -40, 0,
                             40, 69, 70, 71, 75, 140 };
#define NAT ((int)(sizeof AT / sizeof AT[0]))

int main(void)
{
    jw_drawing d;
    jw_obj o;
    int i, j, k;
    long bad, cases;

    if (!fb_init(&fb, FBW, FBH)) {
        printf("BAD  no framebuffer\n");
        return 1;
    }

    /* 円弧と真円: every sweep, both line types, round and squashed. */
    bad = cases = 0;
    {
        static const double rad[] = { 0.3, 1.0, 7.0, 40.0, 90.0, 300.0 };
        static const double sw[] = { 0.05, 1.0, 3.0, 2 * PI, -1.0, -2 * PI };
        static const double flat[] = { 1.0, 0.4 };
        for (i = 0; i < NAT; i++)
            for (j = 0; j < (int)(sizeof rad / sizeof rad[0]); j++)
                for (k = 0; k < (int)(sizeof sw / sizeof sw[0]); k++) {
                    int f, lt;
                    for (f = 0; f < 2; f++)
                        for (lt = 1; lt <= 4; lt += 3) {
                            base(&d, &o);
                            o.cls = JW_ENKO;
                            o.ltype = (unsigned char)lt;
                            o.d[0] = AT[i];
                            o.d[1] = AT[(i + 5) % NAT];
                            o.d[2] = rad[j];
                            o.d[3] = 0.7;
                            o.d[4] = sw[k];
                            o.d[5] = 0.3;
                            o.d[6] = flat[f];
                            bad += outside(&d);
                            cases++;
                        }
                }
    }
    ck(!bad, "arcs and circles, every sweep and both line types");
    printf("     %ld drawn, %ld pixels outside the clip\n", cases, bad);

    /* 点: the four shapes the original picks between. */
    bad = cases = 0;
    for (i = 0; i < NAT; i++)
        for (j = 0; j < NAT; j++)
            for (k = 0; k < 4; k++) {
                base(&d, &o);
                o.cls = JW_TEN;
                o.d[0] = AT[i];
                o.d[1] = AT[j];
                o.n = k == 0;                       /* 実点, with its ring */
                o.flags = k == 1 ? 0x400 : k == 2 ? 0 : 0x40;
                bad += outside(&d);
                cases++;
            }
    ck(!bad, "points, all four shapes, over every edge");
    printf("     %ld drawn, %ld pixels outside the clip\n", cases, bad);

    /* ソリッド: four corners, and the round one. */
    bad = cases = 0;
    for (i = 0; i < NAT; i++)
        for (j = 0; j < NAT; j++) {
            double x = AT[i], y = AT[j];
            base(&d, &o);
            o.cls = JW_SOLID;
            o.d[0] = x - 30; o.d[1] = y - 20;
            o.d[2] = x + 30; o.d[3] = y - 25;
            o.d[4] = x + 25; o.d[5] = y + 30;
            o.d[6] = x - 35; o.d[7] = y + 10;
            bad += outside(&d);
            cases++;
            /* a triangle: the fourth corner repeats the third */
            o.d[6] = o.d[4]; o.d[7] = o.d[5];
            bad += outside(&d);
            cases++;
            /* degenerate: every corner the same point */
            o.d[2] = o.d[4] = o.d[6] = o.d[0];
            o.d[3] = o.d[5] = o.d[7] = o.d[1];
            bad += outside(&d);
            cases++;
            /* the round one */
            base(&d, &o);
            o.cls = JW_SOLID;
            o.ltype = 101;
            o.d[0] = x; o.d[1] = y;
            o.d[2] = 45.0;              /* radius            */
            o.d[3] = 0.6;               /* squashed          */
            o.d[4] = 0.4;               /* turned            */
            o.d[5] = 1.0;               /* from              */
            o.d[6] = 2.5;               /* and how far round */
            bad += outside(&d);
            cases++;
        }
    ck(!bad, "solids: four corners, a triangle, a point, and the round one");
    printf("     %ld drawn, %ld pixels outside the clip\n", cases, bad);

    /* 文字: the glyph blitter writes into the framebuffer itself, after a
       bounds test of its own.  Sizes from under a pixel to far bigger than
       the window, at several angles. */
    bad = cases = 0;
    {
        static const double h[] = { 0.4, 2.0, 12.0, 80.0, 400.0 };
        for (i = 0; i < NAT; i++)
            for (j = 0; j < (int)(sizeof h / sizeof h[0]); j++)
                for (k = 0; k < 8; k++) {
                    double t = k * PI / 4.0, len = h[j] * 6.0;
                    base(&d, &o);
                    o.cls = JW_MOJI;
                    o.text = 1;
                    o.d[0] = AT[i];
                    o.d[1] = AT[(i + 3) % NAT];
                    o.d[2] = o.d[0] + cos(t) * len;
                    o.d[3] = o.d[1] + sin(t) * len;
                    o.d[4] = h[j] * 0.8;        /* one letter across */
                    o.d[5] = h[j];              /* and tall          */
                    bad += outside(&d);
                    cases++;
                }
    }
    ck(!bad, "text, every size and eight directions");
    printf("     %ld drawn, %ld pixels outside the clip\n", cases, bad);

    /* ブロック（図形の参照）: the reference carries a place, a size and a
       turn, and the definition's members are drawn through it.  A
       definition may hold a further reference, which src/draw.c follows
       eight deep.  Everything above is reached again from here, but through
       jw_obj_xform first, so a scale of 1e6 puts a member a long way from
       where the reference sits. */
    bad = cases = 0;
    {
        static jw_obj objs[8];
        static const double sc[] = { 0.01, 1.0, 40.0, 1e6 };
        static const double turn[] = { 0.0, 0.7, 3.0 };
        int si, ti;

        for (i = 0; i < NAT; i++)
            for (si = 0; si < (int)(sizeof sc / sizeof sc[0]); si++)
                for (ti = 0; ti < 3; ti++) {
                    base(&d, &o);
                    memset(objs, 0, sizeof objs);
                    /* the reference */
                    objs[0].cls = JW_BLOCK;
                    objs[0].color = 1;
                    objs[0].ltype = 1;
                    objs[0].block = 7;
                    objs[0].d[0] = AT[i];
                    objs[0].d[1] = AT[(i + 7) % NAT];
                    objs[0].d[2] = sc[si];
                    objs[0].d[3] = sc[si];
                    objs[0].d[4] = turn[ti];
                    /* the definition, and the four members after it */
                    objs[1].cls = JW_LIST;
                    objs[1].list[0] = 7;
                    objs[1].n = 4;
                    objs[2].cls = JW_SEN;
                    objs[2].color = 3;          /* the wide pen */
                    objs[2].ltype = 4;          /* and a dashed one */
                    objs[2].d[0] = -30; objs[2].d[1] = -20;
                    objs[2].d[2] = 30;  objs[2].d[3] = 25;
                    objs[3].cls = JW_ENKO;
                    objs[3].color = 1;
                    objs[3].ltype = 1;
                    objs[3].d[2] = 18.0;
                    objs[3].d[4] = 2 * PI;
                    objs[3].d[6] = 1.0;
                    objs[4].cls = JW_MOJI;
                    objs[4].color = 1;
                    objs[4].ltype = 1;
                    objs[4].text = 1;
                    objs[4].d[2] = 40.0;
                    objs[4].d[4] = 5.0;
                    objs[4].d[5] = 6.0;
                    objs[5].cls = JW_BLOCK;     /* a reference inside one */
                    objs[5].color = 1;
                    objs[5].ltype = 1;
                    objs[5].block = 8;
                    objs[5].d[2] = 1.5;
                    objs[5].d[3] = 1.5;
                    /* and the definition that one stands for */
                    objs[6].cls = JW_LIST;
                    objs[6].list[0] = 8;
                    objs[6].n = 1;
                    objs[7].cls = JW_TEN;
                    objs[7].color = 1;
                    objs[7].n = 1;              /* 実点, with its ring */
                    d.obj = objs;
                    d.nobj = 8;
                    d.cobj = 8;
                    d.ndrawn = 1;
                    bad += outside(&d);
                    cases++;
                }
    }
    ck(!bad, "block references, nested, at every scale and turn");
    printf("     %ld drawn, %ld pixels outside the clip\n", cases, bad);

    /* And the far coordinates, for every class at once. */
    bad = 0;
    {
        static const double far[] = { 9e11, -9e11, 1e6, -1e6 };
        for (i = 0; i < 4; i++) {
            base(&d, &o);
            o.cls = JW_ENKO;
            o.d[0] = far[i]; o.d[1] = far[(i + 1) % 4];
            o.d[2] = 9e11; o.d[4] = 2 * PI; o.d[6] = 1.0;
            bad += outside(&d);
            base(&d, &o);
            o.cls = JW_MOJI;
            o.text = 1;
            o.d[0] = far[i]; o.d[1] = 0; o.d[2] = 0; o.d[3] = far[i];
            o.d[4] = 1e9; o.d[5] = 1e9;
            bad += outside(&d);
            base(&d, &o);
            o.cls = JW_SOLID;
            o.d[0] = far[i]; o.d[1] = -far[i];
            o.d[2] = -far[i]; o.d[3] = far[i];
            o.d[4] = far[i]; o.d[5] = far[i];
            o.d[6] = 0; o.d[7] = 0;
            bad += outside(&d);
            base(&d, &o);
            o.cls = JW_TEN;
            o.d[0] = far[i]; o.d[1] = far[i];
            bad += outside(&d);
        }
    }
    ck(!bad, "coordinates at the edge of what a drawing may hold");

    fb_free(&fb);
    printf("%s clipwalk\n", fails ? "BAD " : "ok  ");
    return fails ? 1 : 0;
}
