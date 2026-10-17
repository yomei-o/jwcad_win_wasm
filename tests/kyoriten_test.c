/* 距離指定点 (32930) —— 箱の距離だけ離れた所に点を置く。
 *
 *   tests/kyoriten_test.exe
 *
 * バーは 仮点 (1323)・距離 (1412)・連続 (1066) の三つだけ。一点目を
 * 打つと問いかけが
 *
 *   線上･円周距離は線･円指示 ﾏｳｽ(L) 、 距離の方向は読取点指示 ﾏｳｽ(R)
 *
 * に変わり、次の読取点が向きを言います（`tools/probe120.sh`・
 * `probe128.sh`）。原典に 1/100 の紙で 距離 1000 を打たせ、273.804 mm の
 * 線の一方の端を始点、もう一方を読取点にさせたものが答えです:
 *
 *   decomp/res/kyoriten_base.jww  線だけ
 *   decomp/res/kyoriten_dir.jww   点が一つ増える。始点から紙で 10 mm
 *                                 （1000 は実寸なので縮尺で割る）、線の上
 *   decomp/res/kyoriten_kari.jww  仮点 を入れると同じ所に、**種別 1** の点
 *
 * 線を指す (L) のほうは、始点が線に乗っている今回の形では読取点と同じ
 * 答えでした。線から離れた所を始点にしたときは訊いていません。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cknear(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.6f / %.6f)\n", ok ? "ok" : "BAD", what, got, want);
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

/* the line and the point of one of the original's answers */
static int theirs(const char *path, double *lx0, double *ly0,
                  double *lx1, double *ly1, double *px, double *py, int *kind)
{
    static jw_drawing d;
    unsigned char *b;
    long n;
    int i, got_line = 0, got_pt = 0;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return 0;
    }
    memset(&d, 0, sizeof d);
    if (!jw_parse(&d, b, n)) {
        printf("BAD  cannot parse %s\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    for (i = 0; i < d.ndrawn; i++) {
        if (d.obj[i].cls == JW_SEN && !got_line) {
            *lx0 = d.obj[i].d[0];
            *ly0 = d.obj[i].d[1];
            *lx1 = d.obj[i].d[2];
            *ly1 = d.obj[i].d[3];
            got_line = 1;
        } else if (d.obj[i].cls == JW_TEN && !got_pt) {
            *px = d.obj[i].d[0];
            *py = d.obj[i].d[1];
            *kind = d.obj[i].n;
            got_pt = 1;
        }
    }
    return got_line && got_pt;
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (i = 0; s[i]; i++)
        jw_cmd_box_key((unsigned char)s[i]);
    jw_cmd_box_key(13);
}

static void click(double x, double y, int button)
{
    const jw_view *v = app_view();

    app_press(jw_sx(v, x), jw_sy(v, y), button);
}

int main(void)
{
    double lx0, ly0, lx1, ly1, px, py, dx, dy, len;
    int kind = -1;

    /* ----------------------------------------------- the original's own */
    if (theirs("decomp/res/kyoriten_dir.jww", &lx0, &ly0, &lx1, &ly1,
               &px, &py, &kind)) {
        double d0 = sqrt((px - lx0) * (px - lx0) + (py - ly0) * (py - ly0));
        double cross;

        cknear(d0, 10.0, 1e-5, "原典: 点は始点から紙で 10 mm（実寸 1000）");
        dx = lx1 - lx0;
        dy = ly1 - ly0;
        cross = (px - lx0) * dy - (py - ly0) * dx;
        cknear(cross / sqrt(dx * dx + dy * dy), 0.0, 1e-6,
               "  そしてその線の上に乗っている");
        ck(kind == 0, "  素の点（種別 0）");
    }
    kind = -1;
    if (theirs("decomp/res/kyoriten_kari.jww", &lx0, &ly0, &lx1, &ly1,
               &px, &py, &kind))
        ck(kind == 1, "原典: 仮点 を入れると種別 1 の点");

    /* -------------------------------------------------- and the port's */
    app_resize(1264, 741);
    app_new();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* 水平・垂直 off */
    click(-150.0, 25.0, 0);
    click(90.0, -95.0, 0);

    ck(app_command(32930) != 0, "距離指定点 が出る");
    ck(jw_cmd() == JW_CMD_KYORITEN, "  それが今の命令になる");
    type_box(1412, "1000");
    click(-150.0, 25.0, 1);             /* (R) on the line's near end */
    ck(app_drawing()->ndrawn == 1, "  一点目では何も置かない");
    click(90.0, -95.0, 1);              /* (R) on the far end */
    ck(app_drawing()->ndrawn == 2, "  二点目で点が一つ増える");
    {
        const jw_drawing *d = app_drawing();
        const jw_obj *o = &d->obj[d->ndrawn - 1];
        const jw_obj *l = &d->obj[0];

        ck(o->cls == JW_TEN, "    それは点");
        dx = o->d[0] - l->d[0];
        dy = o->d[1] - l->d[1];
        len = sqrt(dx * dx + dy * dy);
        cknear(len, 10.0, 1e-9, "    始点から紙で 10 mm");
        ck(o->n == 0, "    仮点 を入れていないので種別 0");
    }

    /* 仮点 on */
    app_command(JW_CMD_SEN);
    app_command(32930);
    jw_cmd_bar(0, 1323);                /* tick 仮点 */
    type_box(1412, "1000");
    click(-150.0, 25.0, 1);
    click(90.0, -95.0, 1);
    {
        const jw_drawing *d = app_drawing();
        const jw_obj *o = &d->obj[d->ndrawn - 1];

        ck(d->ndrawn == 3 && o->cls == JW_TEN, "仮点 でも点が増える");
        ck(o->n == 1, "  こちらは種別 1");
    }

    /* 負の距離（-1000）: 原典で測った（decomp/res/kyoriten_neg.jww）。断らず、始点の
       反対側（向きの逆）へ 紙で 10 mm の所に置く */
    {
        double ox, oy, ex, ey, ox1, oy1;
        int nn;

        ck(theirs("decomp/res/kyoriten_neg.jww", &ox, &oy, &ex, &ey, &ox1, &oy1, &kind),
           "原典の答え kyoriten_neg を読む");
        dx = ex - ox;
        dy = ey - oy;
        len = sqrt(dx * dx + dy * dy);
        cknear(((ox1 - ox) * dx + (oy1 - oy) * dy) / len, -10.0, 1e-5,
               "原典: 負の距離は 向きの逆へ 紙で 10 mm");
        app_command(JW_CMD_SEN);
        app_command(32930);
        type_box(1412, "-1000");
        nn = app_drawing()->ndrawn;
        click(-150.0, 25.0, 1);
        click(90.0, -95.0, 1);
        ck(app_drawing()->ndrawn == nn + 1, "-1000: 点が置かれる（断らない）");
        {
            const jw_drawing *d = app_drawing();
            const jw_obj *o = &d->obj[d->ndrawn - 1];
            const jw_obj *l = &d->obj[0];

            dx = l->d[2] - l->d[0];
            dy = l->d[3] - l->d[1];
            len = sqrt(dx * dx + dy * dy);
            cknear(((o->d[0] - l->d[0]) * dx + (o->d[1] - l->d[1]) * dy) / len, -10.0, 1e-5,
                   "  始点から向きの逆へ 紙で 10 mm");
        }
    }

    /* 連続 (1066): 原典で測った — 置けるのは 999 個目まで（1100 回押して 点 999）。999 個目の
       あとの 連続 は 回数 0 で 釦が無効（バーの 1066 の enabled が 1 → 0）。札 5205 は
       読み（FUN_006baad0）で 見えていない */
    {
        int i, n0, ok = 1;

        app_command(JW_CMD_SEN);
        app_command(32930);
        type_box(1412, "1000");
        n0 = app_drawing()->ndrawn;
        click(-150.0, 25.0, 1);
        click(90.0, -95.0, 1);
        ck(app_drawing()->ndrawn == n0 + 1, "連続: 一個目");
        for (i = 2; i <= 999; i++) {
            jw_cmd_bar((jw_drawing *)app_drawing(), 1066);
            if (app_drawing()->ndrawn != n0 + i)
                ok = 0;
        }
        ck(ok && app_drawing()->ndrawn == n0 + 999, "連続: 999 個目まで置ける");
        jw_cmd_bar((jw_drawing *)app_drawing(), 1066);
        ck(app_drawing()->ndrawn == n0 + 999, "連続: 1000 個目は置かない");
        ck(jw_cmd_notice_id() == 5205, "連続: 札 5205 計算できません（札は読み）");
        jw_cmd_bar((jw_drawing *)app_drawing(), 1066);
        ck(app_drawing()->ndrawn == n0 + 999, "連続: 回数 0 に戻ったので続けて押しても置かない");
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
