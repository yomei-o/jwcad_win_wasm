/* 寸法値 (1069) -- against the original's own drawing.
 *
 *   tests/sunpochi_test.exe [decomp/res/sunpochi.jww]
 *
 * The original was driven (tools/probe15.sh): a line from one side of the
 * sheet to the other, then 寸法 with 寸法値 pressed, then a left click on
 * each end of it.  The status line went
 *
 *   【寸法値】の始点指示(L)  移動寸法値指示(R) 変更寸法値指示(RR) …
 *   ●   寸法の終点を指示して下さい。
 *   ○●寸法の始点はﾏｳｽ(L)、連続入力の終点はﾏｳｽ(R)で指示して下さい。
 *
 * and one thing was added: a text, and nothing else -- no dimension line,
 * no extension lines, no end marks.
 *
 * What is checked is the rule, read off that drawing and then required of
 * the port: the value is the distance between the two points in real
 * units, the text is centred on the middle of them, half a millimetre off
 * to the left of the way they run, laid along them, and carries the
 * dimension's own pen, flags and width word.  `value_rule` is that rule;
 * it is put to the original's drawing first and to the port's second, so
 * the answer is the original's and not this file's.
 *
 * Going through the mouse, the port cannot land on the original's own two
 * points to the last decimal -- a pixel is six tenths of a millimetre on
 * that sheet -- so the port draws its own line through two pixels and the
 * rule is checked against the ends of that.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/gen/bars.h"
#include "../src/gen/sunpo.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cknear(double got, double want, const char *what)
{
    int ok = fabs(got - want) < 1e-4;

    printf("%-4s %s (%.6f / %.6f)\n", ok ? "ok" : "BAD", what, got, want);
    if (!ok)
        fails++;
}

/* the same with a tolerance, for the value: it is written to as
   many places as 小数桁 asks and its trailing zeros are dropped */
static void cknearly(double got, double want, double tol,
                     const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.6f / %.6f +-%g)\n", ok ? "ok" : "BAD",
           what, got, want, tol);
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

/* The rule, put to one text and the two points it was drawn between.
 * `what` names whose drawing it is, for the report. */
static void value_rule(jw_drawing *d, const jw_obj *o,
                       double x0, double y0, double x1, double y1,
                       const char *what)
{
    double dx = x1 - x0, dy = y1 - y0, len = sqrt(dx * dx + dy * dy);
    double ux = dx / len, uy = dy / len, vx = -uy, vy = ux;
    double mx = (x0 + x1) / 2.0 + JW_SUN_HANARE * vx;
    double my = (y0 + y1) / 2.0 + JW_SUN_HANARE * vy;
    double tw = sqrt((o->d[2] - o->d[0]) * (o->d[2] - o->d[0])
                     + (o->d[3] - o->d[1]) * (o->d[3] - o->d[1]));
    const char *t = jw_str(d, o->text);
    int wg = 0, i, nch = 0;
    double want = 0.0;

    printf("--   %s\n", what);
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    ck(o->cls == JW_MOJI, "  文字である");
    ck(o->ltype == 2, "  ＋0x28 が 2（ふつうの文字は 1）");
    ck(o->n == JW_SUN_MOJINO, "  文字種は寸法のもの");
    ck((o->width & 0x0fffu) == (JW_SUN_TEXT_WIDTH & 0x0fffu),
       "  幅の語の下十二ビットが寸法値のもの");
    ck((o->flags & JW_SUN_TEXT_FLAGS) == JW_SUN_TEXT_FLAGS,
       "  寸法のフラグが立っている");
    /* the value: the distance in real units, with a comma every three */
    if (t) {
        char plain[64], *q = plain;
        const char *p;
        for (p = t; *p && q < plain + sizeof plain - 1; p++)
            if (*p != ',')
                *q++ = *p;
        *q = 0;
        want = strtod(plain, 0);
    }
    {
        /* however many places the value was written to: the
           original drops the trailing zeros */
        const char *dot = t ? strchr(t, '.') : 0;
        double tol = 0.5;
        int k;
        if (dot)
            for (k = 1; dot[k] >= '0' && dot[k] <= '9'; k++)
                tol /= 10.0;
        cknearly(want, len * d->group[wg].scale, tol + 1e-9,
                 "  値は実寸の長さ");
    }
    /* where it sits */
    cknear((o->d[0] + o->d[2]) / 2.0, mx, "  真ん中の x");
    cknear((o->d[1] + o->d[3]) / 2.0, my, "  真ん中の y");
    if (tw > 0.0) {
        cknear((o->d[2] - o->d[0]) / tw, ux, "  向きの x");
        cknear((o->d[3] - o->d[1]) / tw, uy, "  向きの y");
    }
    for (nch = 0; t && t[nch]; nch++)
        ;
    cknear(tw, nch * o->d[4] / 2.0, "  幅は半角 n 文字ぶん");
}

/* the one value text in a drawing: a dimension text with a number on it */
static const jw_obj *the_value(const jw_drawing *d, int from)
{
    int i;

    for (i = from; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        const char *t;
        if (o->cls != JW_MOJI || o->ltype != 2)
            continue;
        t = jw_str((jw_drawing *)d, o->text);
        if (t && *t && (*t == '-' || (*t >= '0' && *t <= '9')))
            return o;
    }
    return 0;
}

static const jw_obj *the_line(const jw_drawing *d, int from)
{
    int i;

    for (i = from; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN)
            return &d->obj[i];
    return 0;
}

static void press_bar(int id)
{
    int i, k;

    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != (unsigned)jw_cmd())
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int x = c->x + c->w / 2, y = c->y + c->h / 2;
            if (c->id != id || ui_bar_hit(x, y) != id)
                continue;
            app_press(x, y, 0);
            return;
        }
    }
    ck(0, "  その釦がバーに無い");
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "decomp/res/sunpochi.jww";
    const jw_obj *val, *line;
    jw_drawing *d;
    unsigned char *b;
    long n;
    int before;

    app_resize(1264, 741);

    /* what the original drew, and the rule read off it */
    b = slurp(path, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open %s\n", path);
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    line = the_line(d, 0);
    val = the_value(d, 0);
    ck(line != 0, "原典の図に線が一本ある");
    ck(val != 0, "そして寸法値が一つだけ足されている");
    if (!line || !val)
        return 1;
    printf("     '%s'\n", jw_str(d, val->text));
    value_rule(d, val, line->d[0], line->d[1], line->d[2], line->d[3],
               "原典が描いたもの");

    /* the same by hand: a line through two pixels, then the value between
       the same two pixels */
    app_new();
    d = (jw_drawing *)app_drawing();
    before = d->ndrawn;
    ck(app_command(JW_CMD_SEN) != 0, "線 を出す");
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    app_press(379, 335, 0);
    app_press(778, 335, 0);
    line = the_line(d, before);
    ck(line != 0, "  線が引ける");
    if (!line)
        return 1;
    {
        double lx0 = line->d[0], ly0 = line->d[1];
        double lx1 = line->d[2], ly1 = line->d[3];

        before = d->ndrawn;
        ck(app_command(JW_CMD_SUNPO) != 0, "寸法 を出す");
        press_bar(1069);
        ck(jw_cmd_prompt() && *jw_cmd_prompt(), "  状態行が出る");
        app_press(379, 335, 0);
        app_press(778, 335, 0);
        ck(d->ndrawn == before + 1, "  足されるのは一つだけ");
        if (d->ndrawn != before + 1)
            return 1;
        val = &d->obj[before];
        printf("     '%s'\n", jw_str(d, val->text));
        value_rule(d, val, lx0, ly0, lx1, ly1, "移植が描いたもの");
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
