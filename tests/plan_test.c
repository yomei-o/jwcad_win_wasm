/* A small plan, drawn the way a person draws one.
 *
 *   tests/plan_test.exe [out.jww]
 *
 * The 展開図 test asks whether the drawing commands reach far enough to make
 * a shape.  This one asks the next question: whether the commands people use
 * to turn a shape into a drawing reach as well -- 複線 for the wall's inner
 * face, 中心線 down the middle, ハッチ inside a room, 寸法 across it.
 *
 * Nothing here is scored against the original; each piece has its own test
 * for that.  What this catches is the pieces not reaching each other, which
 * is how the missing font name on a dimension value turned up.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

static double wscale(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

int main(int argc, char **argv)
{
    jw_drawing *d;
    unsigned char *out;
    long n;
    double s, W, H, x0 = -60.0, y0 = -20.0;
    int before, walls;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    s = wscale(d);
    W = 4000.0 / s;
    H = 3000.0 / s;

    /* the room: 4000 x 3000 typed into 矩形の寸法 */
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1413, "4000,3000");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), x0, y0, 0);
    jw_cmd_point(d, app_view(), x0 + 1.0, y0 - 1.0, 0);
    ck(d->ndrawn == before + 4, "間取り: the room is four lines");
    type_box(1413, "");
    /* the view has to be over the drawing before anything can be picked:
       複線 and 中心線 both work by picking a line that is on the screen */
    app_fit();

    /* the wall: 複線 at 150 from each of the four, which is how a wall is
       drawn in Jw_cad -- pick a line, say which side */
    walls = d->ndrawn;
    jw_cmd_set(JW_CMD_FUKUSEN);
    type_box(1411, "150");
    {
        int i;
        for (i = 0; i < 4; i++) {
            const jw_obj *o = &d->obj[before + i];
            double mx = (o->d[0] + o->d[2]) / 2.0;
            double my = (o->d[1] + o->d[3]) / 2.0;
            double ix = x0 + W / 2.0, iy = y0 - H / 2.0;
            /* three clicks, which is what the original asks for as well:
               「複線にする図形を選択」「間隔を入力するか、複写する位置」
               「作図する方向を指示」 */
            jw_cmd_point(d, app_view(), mx, my, 0);          /* the line */
            jw_cmd_point(d, app_view(), mx + (ix - mx) * 0.1,
                         my + (iy - my) * 0.1, 0);           /* how far     */
            jw_cmd_point(d, app_view(), mx + (ix - mx) * 0.2,
                         my + (iy - my) * 0.2, 0);           /* which way   */
        }
    }
    ck(d->ndrawn == walls + 4, "  and 複線 150 gives it an inner face");

    /* a centre line down the room, between two of the walls */
    {
        int was = d->ndrawn;
        /* 中心線 runs between two *lines*, so both clicks pick one --
           the room's left wall and its right */
        const jw_obj *l = &d->obj[before + 3], *r = &d->obj[before + 1];
        jw_cmd_set(JW_CMD_CHUSHIN);
        jw_cmd_point(d, app_view(), (l->d[0] + l->d[2]) / 2.0,
                     (l->d[1] + l->d[3]) / 2.0, 0);
        jw_cmd_point(d, app_view(), (r->d[0] + r->d[2]) / 2.0,
                     (r->d[1] + r->d[3]) / 2.0, 0);
        /* and then the two ends the centre line is to run between */
        jw_cmd_point(d, app_view(), x0 + W / 2.0, y0, 0);
        jw_cmd_point(d, app_view(), x0 + W / 2.0, y0 - H, 0);
        ck(d->ndrawn > was, "  中心線 puts a line between two of them");
    }

    /* a dimension across the room, with arrows and no decimals */
    {
        int was = d->ndrawn;
        jw_cmd_set(JW_CMD_SUNPO);
        jw_cmd_bar(d, 1062);
        jw_cmd_bar(d, 1061);
        jw_cmd_bar(d, 1061);
        type_box(1411, "0");
        jw_cmd_point(d, app_view(), x0, y0 + 12.0, 0);
        jw_cmd_point(d, app_view(), x0, y0 + 10.0, 0);
        jw_cmd_point(d, app_view(), x0, y0, 0);
        jw_cmd_point(d, app_view(), x0 + W, y0, 0);
        ck(d->ndrawn == was + 8, "  寸法 measures it end to end");
        {
            const char *t = jw_str(d, d->obj[d->ndrawn - 1].text);
            ck(t && !strcmp(t, "4,000"), "  and says 4,000");
            if (t && strcmp(t, "4,000"))
                printf("     it says [%s]\n", t);
        }
        jw_cmd_bar(d, 1062);
        jw_cmd_bar(d, 1061);
        jw_cmd_bar(d, 1061);
    }

    ck(app_save(&out, &n) && n > 0, "the plan saves");
    if (argc > 1 && n > 0) {
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(out, 1, (size_t)n, f);
            fclose(f);
            printf("     wrote %s (%ld bytes, %d elements)\n",
                   argv[1], n, d->ndrawn);
        }
    }
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
