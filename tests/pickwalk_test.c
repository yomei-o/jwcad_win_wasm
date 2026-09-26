/* 拾い上げ -- click on every pixel, and on none of them.
 *
 *   tests/pickwalk_test.exe
 *
 * Every command starts with a pick: src/pick.c decides which element the
 * mouse is nearest, and hands back an index into d->obj.  Whatever it hands
 * back is used as an index straight away, so an index that is not in the
 * drawing is a read past the end of the element array -- and the array is
 * one malloc, so a neighbouring index lands inside it and no sanitizer says
 * a word.  (The same shape of hole as the clip in tests/clipwalk_test.c.)
 *
 * This clicks on **every pixel** of the window, in every mode, over a
 * drawing that carries one of each class, and checks the only thing that
 * can be checked without the original: the answer is either -1 or an index
 * this drawing really has, and a read point is a number.
 *
 * Nothing is scored against the original.  tests/pick_test.c is the one that
 * holds the picking against what Jw_cad does; this is the wider net under it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/pick.h"
#include "../src/jww.h"
#include "../src/view.h"

#define FBW 200
#define FBH 150
#define PI 3.14159265358979323846

static int fails;
static char pool[] = "\0\x93\xfa\x96\x7b abc\0";

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void view_of(jw_view *v)
{
    memset(v, 0, sizeof *v);
    v->mmpp = 1.0;
    v->scale = 1.0;
    v->bx = FBW / 2;
    v->by = FBH / 2;
    v->clip.x = 0;
    v->clip.y = 0;
    v->clip.w = FBW;
    v->clip.h = FBH;
}

/* One of every class, spread across the window, plus a block and its
   definition after ndrawn. */
static int build(jw_drawing *d, jw_obj *o, int n, double far)
{
    int k = 0;

    memset(d, 0, sizeof *d);
    memset(o, 0, (size_t)n * sizeof *o);
    d->paper_hw = 297.0;
    d->paper_hh = 210.0;
    d->group[0].state = 3;
    d->group[0].scale = 1.0;
    d->group[0].layer[0].state = 3;
    d->pool = pool;
    d->npool = (int)sizeof pool;
    d->obj = o;

    o[k].cls = JW_SEN;  o[k].ltype = 1; o[k].color = 1;
    o[k].d[0] = -60; o[k].d[1] = -40; o[k].d[2] = 60; o[k].d[3] = 40; k++;
    o[k].cls = JW_SEN;  o[k].ltype = 1; o[k].color = 1;
    o[k].d[0] = -60; o[k].d[1] = 40; o[k].d[2] = 60; o[k].d[3] = -40; k++;
    o[k].cls = JW_ENKO; o[k].ltype = 1; o[k].color = 1;
    o[k].d[2] = 30; o[k].d[4] = 2 * PI; o[k].d[6] = 1.0; k++;
    o[k].cls = JW_ENKO; o[k].ltype = 4; o[k].color = 1;
    o[k].d[0] = 20; o[k].d[1] = 10; o[k].d[2] = 15;
    o[k].d[3] = 0.4; o[k].d[4] = 2.0; o[k].d[6] = 0.6; k++;
    o[k].cls = JW_TEN;  o[k].color = 1; o[k].n = 1;
    o[k].d[0] = -25; o[k].d[1] = 12; k++;
    o[k].cls = JW_TEN;  o[k].color = 1;
    o[k].d[0] = 33; o[k].d[1] = -18; k++;
    o[k].cls = JW_MOJI; o[k].color = 1; o[k].text = 1;
    o[k].d[0] = -50; o[k].d[1] = -30; o[k].d[2] = -10; o[k].d[3] = -30;
    o[k].d[4] = 4; o[k].d[5] = 5; k++;
    o[k].cls = JW_SOLID; o[k].color = 1;
    o[k].d[0] = 5; o[k].d[1] = 5; o[k].d[2] = 45; o[k].d[3] = 8;
    o[k].d[4] = 40; o[k].d[5] = 35; o[k].d[6] = 2; o[k].d[7] = 30; k++;
    /* one a long way off, to be sure the far case is in the list too */
    o[k].cls = JW_SEN; o[k].ltype = 1; o[k].color = 1;
    o[k].d[0] = -far; o[k].d[1] = -far; o[k].d[2] = far; o[k].d[3] = far; k++;
    o[k].cls = JW_BLOCK; o[k].color = 1; o[k].ltype = 1;
    o[k].block = 3;
    o[k].d[0] = -15; o[k].d[1] = 25; o[k].d[2] = 2.0; o[k].d[3] = 2.0; k++;
    /* The **last** drawn element has to be one that really does get picked,
       or an answer one past the end never shows up: a deliberate off-by-one
       in jw_pick_tie went unseen here twice, first because the bound was
       d->nobj and then because the last element was a block, which the
       picking does not offer. */
    o[k].cls = JW_SEN; o[k].ltype = 1; o[k].color = 1;
    o[k].d[0] = -70; o[k].d[1] = 0; o[k].d[2] = 70; o[k].d[3] = 0; k++;
    d->ndrawn = k;
    /* the definition, after the drawn ones */
    o[k].cls = JW_LIST; o[k].list[0] = 3; o[k].n = 1; k++;
    o[k].cls = JW_SEN;  o[k].ltype = 1; o[k].color = 1;
    o[k].d[0] = -5; o[k].d[1] = -5; o[k].d[2] = 5; o[k].d[3] = 5; k++;
    d->nobj = k;
    d->cobj = k;
    return k;
}

/* Click everywhere and check every answer is one this drawing could give. */
static long walk(jw_drawing *d, const jw_view *v, long *reads)
{
    long bad = 0;
    int x, y, mode;

    for (y = -4; y < FBH + 4; y++)
        for (x = -4; x < FBW + 4; x++) {
            double px = v->ox + (x - v->bx) / v->scale;
            double py = v->oy + (v->by - y) / v->scale;
            double rx = 0.0, ry = 0.0;

            for (mode = 0; mode < 4; mode++) {
                int at = jw_pick(d, v, px, py, mode);
                /* d->ndrawn, not d->nobj: what comes back has to be one of
                   the *drawn* elements.  The block definitions and their
                   members sit after ndrawn in the same array, and a command
                   handed one of those would edit a definition.  (Checking
                   against nobj was the first try here, and a deliberate
                   off-by-one put into jw_pick_tie walked straight through
                   it -- the two bounds are two apart in this drawing.) */
                if (at < -1 || at >= d->ndrawn)
                    bad++;
                at = jw_pick_tie(d, v, px, py, mode, 1);
                if (at < -1 || at >= d->ndrawn)
                    bad++;
            }
            if (jw_read(d, v, px, py, &rx, &ry)) {
                (*reads)++;
                if (!(rx > -1e300 && rx < 1e300)
                    || !(ry > -1e300 && ry < 1e300))
                    bad++;
            }
        }
    return bad;
}

int main(void)
{
    jw_drawing d;
    static jw_obj o[16];
    jw_view v;
    long bad, reads = 0;
    int n;

    view_of(&v);

    n = build(&d, o, 16, 9e11);
    bad = walk(&d, &v, &reads);
    ck(!bad, "every pixel, every mode: the answer is an element or nothing");
    printf("     %d elements, %d clicks a mode, %ld read points\n",
           n, (FBW + 8) * (FBH + 8), reads);

    /* The same with the view zoomed a long way in and a long way out, which
       moves the tolerance (jw_pick_tol is pixels / scale). */
    {
        double sc[] = { 1e-6, 0.01, 100.0, 1e6 };
        int i;
        long b2 = 0;
        for (i = 0; i < 4; i++) {
            view_of(&v);
            v.scale = sc[i];
            v.mmpp = 1.0 / sc[i];
            reads = 0;
            b2 += walk(&d, &v, &reads);
        }
        ck(!b2, "the same at four zooms, from a millionth to a million");
    }

    /* And a drawing whose every number is at the edge of what is allowed. */
    {
        long b3;
        view_of(&v);
        n = build(&d, o, 16, 1e12);
        {
            int i;
            for (i = 0; i < d.nobj; i++) {
                int j;
                for (j = 0; j < 8; j++)
                    if (o[i].d[j] != 0.0)
                        o[i].d[j] *= 1e10;
            }
        }
        reads = 0;
        b3 = walk(&d, &v, &reads);
        ck(!b3, "a drawing whose numbers are all at the edge");
    }

    /* An empty drawing, and one with no layer switched on. */
    {
        long b4;
        view_of(&v);
        build(&d, o, 16, 1.0);
        d.nobj = d.ndrawn = 0;
        reads = 0;
        b4 = walk(&d, &v, &reads);
        build(&d, o, 16, 1.0);
        d.group[0].layer[0].state = 0;
        b4 += walk(&d, &v, &reads);
        ck(!b4, "an empty drawing, and one with its layer switched off");
    }

    printf("%s pickwalk\n", fails ? "BAD " : "ok  ");
    return fails ? 1 : 0;
}
