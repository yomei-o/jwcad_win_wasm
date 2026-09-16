/* What is under the mouse -- src/pick.c against the original.
 *
 *   tests/pick_test.exe orig/Test7.jww
 *
 * Four of the cases were checked against Jw_cad itself, by fitting the
 * drawing, entering 消去 and right clicking, and seeing which element came
 * out of the saved file:
 *
 *   Test7            view 889,538   the text at (79.154, -87.726)
 *   Ａマンション平面例  view 290,246   the line (-114.648,42.123)-(-104.748,…)
 *                    view 333,246   the line  (-96.048,42.123)-(-92.148,…)
 *                    view 357,246   the line  (-85.648,42.123)-(-81.398,…)
 *
 * tmp/jwdraw.ps1 -Cmd 32835 -Clicks 'cmd:32794;r290,246;r333,246;r357,246'
 * took out those three lines and nothing else, out of 1,394.  The last three
 * sit among solids, so they also check that a solid does not win over a line
 * running past it.
 *
 * The rest are properties that have to hold for the pick to be any use at
 * all: the middle of a line finds that line, a point beats a line through
 * it, and far enough away nothing is found.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/jww.h"
#include "../src/pick.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%s %s\n", ok ? "ok  " : "BAD ", what);
    if (!ok)
        fails++;
}

int main(int argc, char **argv)
{
    const jw_drawing *d;
    const jw_view *v;
    unsigned char *b;
    long n;
    FILE *f;
    int i, lines = 0, found = 0, text = -1;

    if (argc < 2) {
        printf("usage: pick_test drawing.jww\n");
        return 2;
    }
    app_new();
    app_resize(1264, 741);
    f = fopen(argv[1], "rb");
    if (!f) {
        printf("BAD  cannot open %s\n", argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n || !app_open(b, n)) {
        printf("BAD  cannot read %s\n", argv[1]);
        return 1;
    }
    fclose(f);
    app_paint();
    d = app_drawing();
    v = app_view();

    /* the middle of a line finds a line, and one that goes through there.
       Only lines that can be edited count: a layer set to "display only"
       cannot be picked, which is what the original's own list holds. */
    for (i = 0; i < d->ndrawn && lines < 200; i++) {
        const jw_obj *o = &d->obj[i];
        double mx, my;
        int k, g = o->lgroup & 15, l = o->layer & 15;
        if (o->cls != JW_SEN)
            continue;
        {   /* the same fold src/pick.c uses: 0 stays 0, 1 stays 1, the
               rest count as 3 */
            int gs = d->group[g].state, ls = d->group[g].layer[l].state;
            gs = gs == 0 ? 0 : gs == 1 ? 1 : 3;
            ls = ls == 0 ? 0 : ls == 1 ? 1 : 3;
            if ((gs & ls) != 3 || (o->flags & 1))
                continue;
        }
        lines++;
        mx = (o->d[0] + o->d[2]) / 2;
        my = (o->d[1] + o->d[3]) / 2;
        k = jw_pick(d, v, mx, my, 0);
        if (k >= 0 && d->obj[k].cls != JW_MOJI)
            found++;
        else
            printf("     %d: (%.3f,%.3f)-(%.3f,%.3f) found %d\n", i,
                   o->d[0], o->d[1], o->d[2], o->d[3], k);
    }
    if (lines == 0)
        printf("ok   nothing here can be edited, so nothing can be picked\n");
    else
        ck(found == lines, "the middle of every line finds something there");

    /* the text the original itself deleted */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI
            && fabs(d->obj[i].d[0] - 79.154) < 0.001
            && fabs(d->obj[i].d[1] + 87.726) < 0.001)
            text = i;
    if (text >= 0) {
        const jw_obj *o = &d->obj[text];
        double mx = (o->d[0] + o->d[2]) / 2;
        double my = (o->d[1] + o->d[3]) / 2 + o->d[5] / 2;
        ck(jw_pick(d, v, mx, my, 0) == text,
           "the text Jw_cad deleted is the one the pick lands on");
        ck(jw_pick(d, v, mx, my, 3) != text,
           "and mode 3 -- which is not the one 消去 uses -- leaves text alone");
    }

    /* the three lines Jw_cad itself took out of the flat's plan */
    {
        static const struct { double px, py, x0, y0, x1, y1; } want[] = {
            { -114.297376, 41.995627, -114.648, 42.123, -104.748, 42.123 },
            {  -95.680758, 41.995627,  -96.048, 42.123,  -92.148, 42.123 },
            {  -85.290087, 41.995627,  -85.648, 42.123,  -81.398, 42.123 }
        };
        int w;
        for (w = 0; w < 3; w++) {
            int k = -1;
            for (i = 0; i < d->ndrawn; i++) {
                const jw_obj *o = &d->obj[i];
                if (o->cls == JW_SEN
                    && fabs(o->d[0] - want[w].x0) < 0.0005
                    && fabs(o->d[1] - want[w].y0) < 0.0005
                    && fabs(o->d[2] - want[w].x1) < 0.0005
                    && fabs(o->d[3] - want[w].y1) < 0.0005)
                    k = i;
            }
            if (k < 0)
                continue;       /* a different drawing */
            printf("%s the line Jw_cad took out at (%.3f, %.3f)\n",
                   jw_pick(d, v, want[w].px, want[w].py, 0) == k
                   ? "ok  " : "BAD ", want[w].px, want[w].py);
            if (jw_pick(d, v, want[w].px, want[w].py, 0) != k)
                fails++;
        }
    }

    /* nothing within reach of a point well outside the paper */
    ck(jw_pick(d, v, 1e6, 1e6, 0) < 0, "nothing is found out in the wild");

    /* the tolerance is ten pixels of paper */
    ck(fabs(jw_pick_tol(v) * v->scale - 10.0) < 1e-9,
       "the tolerance is the original's ten screen pixels");

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
