/* 取得の残り三つ —— 数値角度 (32938)・数値長 (32941)・軸角 (32962)。
 *
 *   tests/getnum_test.exe
 *
 * 取得の仲間でただ二つ、**線でなく図面に書いてある数字**を指すものです。
 * 問いかけは二つとも「数値を指示してください。」（`tools/probe120.sh`）。
 *
 * 原典に文字「30」を (400,400) に書かせ、それを指してから一本引かせた
 * ものが答えです（`tools/probe121.sh`、縮尺 1/100 の新規図面）:
 *
 *   decomp/res/getnumplain.jww  取らずに引いた線
 *   decomp/res/getnumang.jww    数値角度 —— 線は 30 度、長さはクリックを
 *                               その向きへ落としたぶん（線角度と同じ形）
 *   decomp/res/getnumlen.jww    数値長 —— 線はクリックの向きのまま、
 *                               紙の上で 0.300 mm。30 ÷ 100 なので
 *                               **30 は実寸**です
 *
 * 軸角 はこの仲間で一つだけ毛色が違い、**次の線に数を渡すのでなく図面の
 * 軸を回します**。問いかけも「軸角取得  基準線を指示してください。」です。
 * -26.565 度の線を指してから 水平･垂直 で引かせると、原典は水平でなく
 * その -26.565 度に引きました（`tools/probe123.sh`）:
 *
 *   decomp/res/getjikbase.jww  軸角を取らずに 水平･垂直 で引いた線（水平）
 *   decomp/res/getjik.jww      取ってから引いた線（基準線と同じ向き）
 *
 * 原典のクリックは画面の画素なので、ここで較べるのは座標でなく**決まり**
 * です（`tests/getang_test.c` と同じ）。
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

#define PI 3.14159265358979323846

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

static double deg_of(const jw_obj *o)
{
    return atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
}

static double len_of(const jw_obj *o)
{
    return sqrt((o->d[2] - o->d[0]) * (o->d[2] - o->d[0])
                + (o->d[3] - o->d[1]) * (o->d[3] - o->d[1]));
}

/* the lines of one of those files, in the order they were drawn */
static int lines_of(const char *path, double *deg, double *len, int max)
{
    static jw_drawing d;
    unsigned char *b;
    long n;
    int i, k = 0;

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
    for (i = 0; i < d.ndrawn && k < max; i++)
        if (d.obj[i].cls == JW_SEN) {
            deg[k] = deg_of(&d.obj[i]);
            len[k] = len_of(&d.obj[i]);
            k++;
        }
    return k;
}

/* the one line the original drew after the grab */
static int line_of(const char *path, double *deg, double *len)
{
    static jw_drawing d;
    unsigned char *b;
    long n;
    int i, got = 0;

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
    for (i = 0; i < d.ndrawn; i++)
        if (d.obj[i].cls == JW_SEN) {
            *deg = deg_of(&d.obj[i]);
            *len = len_of(&d.obj[i]);
            got = 1;
            break;
        }
    if (!got) {
        printf("BAD  %s holds no line\n", path);
        fails++;
    }
    return got;
}

static void click(double x, double y, int button)
{
    const jw_view *v = app_view();

    app_press(jw_sx(v, x), jw_sy(v, y), button);
}

/* 文字「30」を (tx,ty) に書き、grab を出してそれを指し、線を一本引く */
static const jw_obj *port_run(int grab, double tx, double ty,
                              double sx, double sy, double ex, double ey)
{
    jw_drawing *d;
    int i;

    app_new();
    d = (jw_drawing *)app_drawing();
    app_command(JW_CMD_MOJI);
    app_key('3');                       /* the text to place */
    app_key('0');
    click(tx, ty, 0);
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    if (grab) {
        app_command(grab);
        click(tx + 1.0, ty + 1.0, 0);   /* the number */
    }
    click(sx, sy, 0);
    click(ex, ey, 0);
    for (i = d->ndrawn - 1; i >= 0; i--)
        if (d->obj[i].cls == JW_SEN)
            return &d->obj[i];
    return 0;
}

int main(void)
{
    const jw_obj *o;
    double rd, rl, d0, l0;
    double tx = -40.0, ty = -60.0;      /* where the number goes, in mm */
    double sx = 0.0, sy = -150.0, ex = 120.0, ey = -180.0;

    app_resize(1264, 741);

    /* ---------------------------------------------------- the port's own */
    o = port_run(0, tx, ty, sx, sy, ex, ey);
    if (!o) {
        printf("BAD  the port drew no line\n");
        return 1;
    }
    d0 = deg_of(o);
    l0 = len_of(o);
    cknear(d0, atan2(ey - sy, ex - sx) * 180.0 / PI, 1e-9,
           "取らなければクリックのまま（角度）");
    cknear(l0, sqrt((ex - sx) * (ex - sx) + (ey - sy) * (ey - sy)), 1e-9,
           "  同じく長さ");

    o = port_run(32938, tx, ty, sx, sy, ex, ey);
    ck(o != 0, "数値角度: 線が引けた");
    if (o) {
        double proj = (ex - sx) * cos(30.0 * PI / 180.0)
                      + (ey - sy) * sin(30.0 * PI / 180.0);

        cknear(deg_of(o), 30.0, 1e-9, "  向きは文字の 30 度");
        cknear(len_of(o), proj, 1e-9, "  長さはクリックをその向きへ落とした分");
    }

    o = port_run(32941, tx, ty, sx, sy, ex, ey);
    ck(o != 0, "数値長: 線が引けた");
    if (o) {
        cknear(deg_of(o), d0, 1e-9, "  向きはクリックのまま");
        cknear(len_of(o), 30.0 / 100.0, 1e-9,
               "  長さは 30 の実寸、紙の上では縮尺で割った 0.3 mm");
    }

    /* ------------------------------------------- against the original's */
    if (line_of("decomp/res/getnumplain.jww", &rd, &rl)) {
        double ad, al, ld, ll;

        if (line_of("decomp/res/getnumang.jww", &ad, &al)) {
            double proj = fabs(rl * cos((ad - rd) * PI / 180.0));

            cknear(ad, 30.0, 1e-4, "原典も 数値角度 で 30 度ちょうど");
            cknear(al, proj, 1e-3,
                   "  その長さは、取らずに引いた線をその向きへ落とした分");
        }
        if (line_of("decomp/res/getnumlen.jww", &ld, &ll)) {
            cknear(ld, rd, 1e-4, "原典も 数値長 では向きを変えない");
            cknear(ll, 0.3, 1e-4, "  長さは 30/100 = 0.3 mm");
        }
    }

    /* ------------------------------------------------------- 軸角 ----- */
    {
        double bd[4], bl[4], jd[4], jl[4];
        const jw_obj *p1;
        double ax;

        if (lines_of("decomp/res/getjikbase.jww", bd, bl, 4) >= 1
            && lines_of("decomp/res/getjik.jww", jd, jl, 4) >= 2) {
            /* [0] is the reference line, [1] the one drawn after it */
            cknear(bd[1], 0.0, 1e-4,
                   "原典: 軸角を取らなければ 水平･垂直 は水平");
            cknear(jd[1], jd[0], 1e-4,
                   "  取ったあとは基準線と同じ向きに引く");
            ck(jl[1] < bl[1],
               "  長さはクリックをその向きへ落とした分なので短くなる");
        }

        /* and the port's own */
        app_new();
        app_resize(1264, 741);
        app_command(JW_CMD_SEN);
        if (jw_cmd_bar_check(1333) > 0)
            app_key(32);
        click(-100.0, -100.0, 0);
        click(100.0, -200.0, 0);
        app_command(32962);
        ck(jw_cmd_get_mode_now() == 32962, "軸角: 取得が立つ");
        click(0.0, -150.0, 0);          /* the middle of that line */
        ax = jw_cmd_axis();
        cknear(ax, atan2(-100.0, 200.0) * 180.0 / 3.14159265358979, 1e-9,
               "  図面の軸角が基準線の角度になる");
        ck(jw_cmd_get_mode_now() == 0, "  一回で終わる");

        /* and 水平･垂直 then runs along that axis, the click projected
           on to it -- which is what 水平･垂直 does round any axis */
        if (jw_cmd_bar_check(1333) <= 0)
            app_key(32);
        click(-100.0, 0.0, 0);
        click(100.0, 50.0, 0);
        p1 = 0;
        {
            const jw_drawing *dr = app_drawing();
            int i;

            for (i = dr->ndrawn - 1; i >= 0; i--)
                if (dr->obj[i].cls == JW_SEN) {
                    p1 = &dr->obj[i];
                    break;
                }
        }
        ck(p1 != 0, "  その軸で一本引ける");
        if (p1) {
            double want = 200.0 * cos(ax * PI / 180.0)
                          + 50.0 * sin(ax * PI / 180.0);

            cknear(deg_of(p1), ax, 1e-9, "    向きは軸角");
            /* the clicks go through the screen's pixels and back, so
               the length is only right to within one of those */
            cknear(len_of(p1), fabs(want), 1.0,
                   "    長さはクリックを軸へ落とした分");
        }
        jw_cmd_set_axis(0.0);

        (void)p1;
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
