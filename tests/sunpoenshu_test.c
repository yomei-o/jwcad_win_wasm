/* 円周 (1067) -- against the original's own drawing.
 *
 *   tests/sunpoenshu_test.exe
 *
 * Five passes of asking (tools/probe13.sh .. probe17.sh) were needed for
 * this one.  The status line walks:
 *
 *   円を指示してください。     円周
 *   [寸法] 引出し線の始点を指示して下さい。(L)free　(R)Read
 *   ■　寸法線の位置を指示して下さい。(L)free　(R)Read
 *   ○　寸法の始点を指示して下さい    （左回り）円周
 *     ●   寸法の終点を指示して下さい。    （左回り）円周
 *
 * and the last two take a **read** point only.  A circle on its own has
 * nothing on it that can be read -- a right click reads its middle, which
 * is not on it -- so the four passes before drew nothing at all.  The
 * fifth put a chord across the circle, whose two ends are on it, and read
 * those.  decomp/res/sunpoenshu_base.jww is that circle and chord as the
 * original drew them and decomp/res/sunpoenshu.jww is what it made of
 * them.
 *
 * What it drew is 角度's six things in 角度's order -- the value, the arc,
 * a 点 at each end of it, an 引出線 along each way in -- with the middle
 * and the radius taken from the circle, the value the length of that much
 * of the circle in real units, and no 0x0400 on the text.
 *
 * `enshu_rule` is that, put to the original's drawing first and to the
 * port's second, so the answer is the original's and not this file's.
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

#define PI 3.14159265358979323846

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

static void cknearly(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.6f / %.6f +-%g)\n", ok ? "ok" : "BAD", what,
           got, want, tol);
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

/* the six things, in the order they were drawn, from `at` on */
static void enshu_rule(jw_drawing *d, int at, double ox, double oy, double R,
                       const char *whose)
{
    const jw_obj *txt, *arc, *t0, *t1, *l0, *l1;
    double r2, a0, sweep, mid, r1, want, tw;
    const char *s;
    int wg = 0, i, nch;

    printf("--   %s\n", whose);
    if (d->ndrawn < at + 6) {
        ck(0, "  六つ描かれる");
        return;
    }
    txt = &d->obj[at];
    arc = &d->obj[at + 1];
    t0  = &d->obj[at + 2];
    t1  = &d->obj[at + 3];
    l0  = &d->obj[at + 4];
    l1  = &d->obj[at + 5];
    ck(txt->cls == JW_MOJI, "  一つめは値の文字");
    ck(arc->cls == JW_ENKO, "  二つめは弧");
    ck(t0->cls == JW_TEN && t1->cls == JW_TEN, "  三つめ四つめは点");
    ck(l0->cls == JW_SEN && l1->cls == JW_SEN, "  五つめ六つめは引出線");
    if (txt->cls != JW_MOJI || arc->cls != JW_ENKO)
        return;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    cknear(arc->d[0], ox, "  弧の中心 x は円の中心");
    cknear(arc->d[1], oy, "  弧の中心 y は円の中心");
    r2 = arc->d[2];
    a0 = arc->d[3];
    sweep = arc->d[4];
    ck(sweep > 0.0 && sweep < 2.0 * PI, "  掃引は左回りで一周未満");
    cknear(arc->d[6], 1.0, "  弧の d[6] は 1");
    ck(arc->n == 0, "  弧の n は 0");

    /* the two 点 sit on the ends of that arc */
    cknear(t0->d[0], ox + r2 * cos(a0), "  点１ x");
    cknear(t0->d[1], oy + r2 * sin(a0), "  点１ y");
    cknear(t1->d[0], ox + r2 * cos(a0 + sweep), "  点２ x");
    cknear(t1->d[1], oy + r2 * sin(a0 + sweep), "  点２ y");

    /* the two 引出線 run in along the same two ways, from r1 to r2 */
    r1 = sqrt((l0->d[0] - ox) * (l0->d[0] - ox)
              + (l0->d[1] - oy) * (l0->d[1] - oy));
    cknear(l0->d[0], ox + r1 * cos(a0), "  引出線１の内側 x");
    cknear(l0->d[1], oy + r1 * sin(a0), "  引出線１の内側 y");
    cknear(l0->d[2], ox + r2 * cos(a0), "  引出線１の外側 x");
    cknear(l0->d[3], oy + r2 * sin(a0), "  引出線１の外側 y");
    cknear(l1->d[0], ox + r1 * cos(a0 + sweep), "  引出線２の内側 x");
    cknear(l1->d[1], oy + r1 * sin(a0 + sweep), "  引出線２の内側 y");
    cknear(l1->d[2], ox + r2 * cos(a0 + sweep), "  引出線２の外側 x");
    cknear(l1->d[3], oy + r2 * sin(a0 + sweep), "  引出線２の外側 y");
    ck(r1 < r2, "  引出線は内から外へ");

    /* the value: the length of that much of the circle, in real units */
    s = jw_str(d, txt->text);
    want = 0.0;
    if (s) {
        char plain[64], *q = plain;
        const char *p;
        for (p = s; *p && q < plain + sizeof plain - 1; p++)
            if (*p != ',')
                *q++ = *p;
        *q = 0;
        want = strtod(plain, 0);
    }
    {
        const char *dot = s ? strchr(s, '.') : 0;
        double tol = 0.5;
        int k;
        if (dot)
            for (k = 1; dot[k] >= '0' && dot[k] <= '9'; k++)
                tol /= 10.0;
        printf("     '%s'\n", s ? s : "");
        cknearly(want, R * sweep * d->group[wg].scale, tol + 1e-9,
                 "  値は円周のその分の実寸");
    }

    /* where the value sits: the middle of the sweep, はなれ outside the
       arc, laid along the tangent there */
    mid = a0 + sweep / 2.0;
    tw = sqrt((txt->d[2] - txt->d[0]) * (txt->d[2] - txt->d[0])
              + (txt->d[3] - txt->d[1]) * (txt->d[3] - txt->d[1]));
    cknear((txt->d[0] + txt->d[2]) / 2.0,
           ox + (r2 + JW_SUN_HANARE) * cos(mid), "  値の真ん中 x");
    cknear((txt->d[1] + txt->d[3]) / 2.0,
           oy + (r2 + JW_SUN_HANARE) * sin(mid), "  値の真ん中 y");
    if (tw > 0.0) {
        cknear((txt->d[2] - txt->d[0]) / tw, cos(mid - PI / 2.0),
               "  値の向き x");
        cknear((txt->d[3] - txt->d[1]) / tw, sin(mid - PI / 2.0),
               "  値の向き y");
    }
    for (nch = 0; s && s[nch]; nch++)
        ;
    cknear(tw, nch * txt->d[4] / 2.0, "  幅は半角 n 文字ぶん");
    ck(txt->ltype == 2, "  値の ＋0x28 は 2");
    ck(txt->width == 0, "  値の幅の語は 0（角度と同じで、寸法とは違う）");
    ck((txt->flags & 0x0400u) == 0, "  角度の 0x0400 は立たない");
    ck((txt->flags & JW_SUN_TEXT_FLAGS) == JW_SUN_TEXT_FLAGS,
       "  寸法のフラグは立つ");
    ck(txt->n == JW_SUN_MOJINO, "  文字種は寸法のもの");
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

static void click(double x, double y, int button)
{
    const jw_view *v = app_view();

    app_press(jw_sx(v, x), jw_sy(v, y), button);
}

static int open_file(const char *path)
{
    unsigned char *b;
    long n;
    int ok;

    b = slurp(path, &n);
    if (!b)
        return 0;
    ok = app_open(b, n);
    free(b);
    return ok;
}

int main(void)
{
    const jw_obj *circle;
    jw_drawing *d;
    double ox, oy, R;
    int i, at;

    app_resize(1264, 741);

    /* what the original drew, and the rule read off it */
    if (!open_file("decomp/res/sunpoenshu.jww")) {
        printf("BAD  cannot open decomp/res/sunpoenshu.jww\n");
        return 1;
    }
    d = (jw_drawing *)app_drawing();
    circle = 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_ENKO && d->obj[i].n == 1) {
            circle = &d->obj[i];
            break;
        }
    ck(circle != 0, "原典の図に円がある");
    if (!circle)
        return 1;
    ox = circle->d[0];
    oy = circle->d[1];
    R = circle->d[2];
    /* the circle, then the chord, then the six */
    enshu_rule(d, 2, ox, oy, R, "原典が描いたもの");

    /* the same by hand, over the circle and chord it started from */
    if (!open_file("decomp/res/sunpoenshu_base.jww")) {
        printf("BAD  cannot open decomp/res/sunpoenshu_base.jww\n");
        return 1;
    }
    d = (jw_drawing *)app_drawing();
    at = d->ndrawn;
    ck(app_command(JW_CMD_SUNPO) != 0, "寸法 を出す");
    press_bar(1067);
    ck(jw_cmd_prompt() && *jw_cmd_prompt(), "  状態行が出る");
    click(ox + R, oy, 0);               /* indicate the circle */
    click(ox + 97.9592, oy, 0);         /* 引出し線の始点 */
    click(ox + 122.449, oy, 0);         /* 寸法線の位置 */
    click(ox + R, oy, 1);               /* 寸法の始点, read off the chord */
    click(ox, oy + R, 1);               /* 寸法の終点 */
    enshu_rule(d, at, ox, oy, R, "移植が描いたもの");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
