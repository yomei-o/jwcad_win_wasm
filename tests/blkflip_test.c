/* 反転した参照（倍率 x・y の符号が違うブロックの参照）の 描画・PDF・当たり。
 *
 *   tests/blkflip_test.exe
 *
 * 定義（裏返すと形の変わる鉤形）を 倍率 (1,-1)・(-1,1) の参照で置き、
 * 入れ子の参照（外が反転、内が 1.5 倍・40°）も置く。x・y の大きさが違う
 * 参照（(2,0.5) で 30°、入れ子の外が (2,1)。前は 倍率 x だけで描いていた）も。
 * 同じ形を
 * T + R(角)·diag(倍率x,倍率y)·p で計算した線の図面と、
 *   描画（jw_draw の画素）・PDF（jw_plot_pdf の線の点）が同じで、
 *   AUTO の左クリック（au_block_hit）が 裏返った線の上で「ブロック図形です」
 *   を出し、裏返らずに回っただけの所では出さない
 * ことを見る。原典の描画 FUN_0042b460 は内側の段から 倍率 FUN_00465c40
 * （x・y）・回転 FUN_0046d5b0・移動 FUN_0046bdf0 を掛ける。逆コンパイルの読み、
 * 原典では押していない。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/fb.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/draw.h"
#include "../src/plot.h"
#include "../src/cmd.h"

#define PI 3.14159265358979323846
#define W 600
#define H 400

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* 定義 0: 鉤形の二本。定義 1: 縦の線一本と 定義 0 の参照 */
static const double DEF0[2][4] = {
    {  0.0, 0.0, 20.0,  0.0 },
    { 20.0, 0.0, 20.0, 10.0 },
};
static const double DEF1_LINE[4] = { 0.0, 0.0, 0.0, 8.0 };
static const double DEF1_REF[5] = { 5.0, 5.0, 1.5, 1.5, 40.0 };  /* x,y,sx,sy,角 */

/* 置く参照: x, y, 倍率 x, 倍率 y, 角, 定義。終わりの二つは x・y の大きさが
   違う参照（回した参照に x・y 違いの倍率を掛けて 定義を作り直したあとの形
   FUN_00464870、回っていない参照に掛けたときの形。入れ子の内は 40° 回って
   いる） */
#define NREF 6
static const double REF[NREF][6] = {
    { -100.0, -40.0,  1.0, -1.0,  0.0, 0 },
    {  -40.0, -40.0, -1.0,  1.0, 30.0, 0 },
    {   20.0, -40.0,  2.0, -2.0, 60.0, 0 },
    {   80.0, -40.0,  1.0, -1.0, 20.0, 1 },
    {  100.0,  20.0,  2.0,  0.5, 30.0, 0 },
    { -100.0,   0.0,  2.0,  1.0,  0.0, 1 },
};

static jw_obj *add(jw_drawing *d, int cls)
{
    jw_obj *o = jw_add(d, cls);

    if (o) {
        o->color = 2;
        o->ltype = 1;
        o->width = 0;
    }
    return o;
}

/* T + R(角)·diag(sx,sy)·p。wrong なら これまでの描き方（倍率 x だけ） */
static void put(const double *r, int wrong, double x, double y,
                double *ox, double *oy)
{
    double a = r[4] * PI / 180.0, sx = r[2], sy = wrong ? r[2] : r[3];
    double c = cos(a), s = sin(a);

    x *= sx;
    y *= sy;
    *ox = r[0] + x * c - y * s;
    *oy = r[1] + x * s + y * c;
}

static void line(jw_drawing *d, const double *r0, const double *r1, int wrong,
                 const double *l)
{
    jw_obj *o = add(d, JW_SEN);
    double x0 = l[0], y0 = l[1], x1 = l[2], y1 = l[3];

    if (!o)
        return;
    if (r1) {
        put(r1, wrong, x0, y0, &x0, &y0);
        put(r1, wrong, x1, y1, &x1, &y1);
    }
    put(r0, wrong, x0, y0, &o->d[0], &o->d[1]);
    put(r0, wrong, x1, y1, &o->d[2], &o->d[3]);
}

/* 0: 参照で、1: 計算した線で、2: 計算した線（これまでの 倍率 x だけ） */
static void build(jw_drawing *d, int how)
{
    int i, k;

    while (d->nobj > 0)
        jw_remove(d, d->nobj - 1);
    if (how) {
        for (k = 0; k < NREF; k++) {
            if ((int)REF[k][5] == 0) {
                for (i = 0; i < 2; i++)
                    line(d, REF[k], 0, how == 2, DEF0[i]);
            } else {
                line(d, REF[k], 0, how == 2, DEF1_LINE);
                for (i = 0; i < 2; i++)
                    line(d, REF[k], DEF1_REF, how == 2, DEF0[i]);
            }
        }
        return;
    }
    for (k = 0; k < NREF; k++) {
        jw_obj *o = add(d, JW_BLOCK);

        if (!o)
            return;
        o->d[0] = REF[k][0];
        o->d[1] = REF[k][1];
        o->d[2] = REF[k][2];
        o->d[3] = REF[k][3];
        o->d[4] = REF[k][4] * PI / 180.0;
        o->block = (int)REF[k][5];
    }
    {
        jw_obj *o = add(d, JW_LIST);
        int at;

        if (!o)
            return;
        at = (int)(o - d->obj);
        d->obj[at].list[0] = 0;
        d->obj[at].n = 2;
        for (i = 0; i < 2; i++) {
            jw_obj *m = add(d, JW_SEN);

            if (!m)
                return;
            memcpy(m->d, DEF0[i], sizeof DEF0[i]);
        }
        o = add(d, JW_LIST);
        if (!o)
            return;
        at = (int)(o - d->obj);
        d->obj[at].list[0] = 1;
        d->obj[at].n = 2;
        o = add(d, JW_SEN);
        if (!o)
            return;
        memcpy(o->d, DEF1_LINE, sizeof DEF1_LINE);
        o = add(d, JW_BLOCK);
        if (!o)
            return;
        o->d[0] = DEF1_REF[0];
        o->d[1] = DEF1_REF[1];
        o->d[2] = DEF1_REF[2];
        o->d[3] = DEF1_REF[3];
        o->d[4] = DEF1_REF[4] * PI / 180.0;
        o->block = 0;
        d->ndrawn = NREF;
    }
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

/* PDF の "x y m" / "x y l" の点を順に */
static int pdf_points(const jw_drawing *d, double *pt, int max)
{
    long n = 0, i;
    unsigned char *b = jw_plot_pdf(d, 0, &n);
    char *t;
    int np = 0;
    double a = 0.0, c = 0.0;
    int have = 0;

    if (!b)
        return -1;
    t = (char *)malloc((size_t)n + 1);
    memcpy(t, b, (size_t)n);
    t[n] = 0;
    for (i = 0; i < n; i++)
        if (!t[i])
            t[i] = ' ';
    for (i = 0; i < n;) {
        char *e;
        double v;

        while (i < n && (t[i] == ' ' || t[i] == '\n' || t[i] == '\r'))
            i++;
        if (i >= n)
            break;
        v = strtod(t + i, &e);
        if (e != t + i && (*e == ' ' || *e == '\n')) {
            a = c;
            c = v;
            have++;
            i = (long)(e - t);
            continue;
        }
        if ((t[i] == 'm' || t[i] == 'l') && (i + 1 >= n || t[i + 1] == ' '
                                             || t[i + 1] == '\n') && have >= 2
            && np < max) {
            pt[np * 2] = a;
            pt[np * 2 + 1] = c;
            np++;
        }
        have = 0;
        while (i < n && t[i] != ' ' && t[i] != '\n' && t[i] != '\r')
            i++;
    }
    free(t);
    free(b);
    return np;
}

/* AUTO の左クリックで「ブロック図形です」が出るか */
static int hit(jw_drawing *d, const jw_view *v, double x, double y)
{
    jw_cmd_set(JW_CMD_AUTO);
    jw_cmd_notice_clear();
    jw_cmd_point(d, v, x, y, 0);
    return jw_cmd_notice_id() == 5231;
}

/* k の隣（3×3）に色 c の画素があるか。白は描いていない所 */
static int near_ink(const unsigned int *im, int k, unsigned int c)
{
    int x = k % W, y = k / W, dx, dy;

    if (c == 0xffffff)
        return 1;
    for (dy = -1; dy <= 1; dy++)
        for (dx = -1; dx <= 1; dx++)
            if (x + dx >= 0 && x + dx < W && y + dy >= 0 && y + dy < H &&
                im[(y + dy) * W + x + dx] == c)
                return 1;
    return 0;
}

int main(void)
{
    jw_drawing d;
    unsigned char *b;
    long n;
    fb_t fb;
    jw_view v;
    rect_t r;
    unsigned int *img[3];
    int i, k, ink = 0, differ = 0, wrongdiff = 0;

    b = slurp("orig/Test5.jww", &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read orig/Test5.jww\n");
        return 1;
    }
    free(b);
    memset(&fb, 0, sizeof fb);
    if (!fb_init(&fb, W, H)) {
        printf("BAD  out of memory\n");
        return 1;
    }
    r.x = r.y = 0;
    r.w = W;
    r.h = H;
    memset(&v, 0, sizeof v);
    /* 置いた参照が収まる ±150×±100 mm を画面いっぱいに（当たりの幅が 2 mm ほどに） */
    jw_view_fit(&v, &r, 150.0, 100.0);
    v.clip = r;

    /* 描画 */
    for (i = 0; i < 3; i++) {
        build(&d, i);
        for (k = 0; k < W * H; k++)
            fb.px[k] = 0xffffff;
        jw_draw(&fb, &v, &d);
        img[i] = (unsigned int *)malloc(W * H * sizeof *img[i]);
        if (!img[i]) {
            printf("BAD  out of memory\n");
            return 1;
        }
        memcpy(img[i], fb.px, W * H * sizeof *img[i]);
    }
    for (k = 0; k < W * H; k++) {
        if (img[0][k] != 0xffffff)
            ink++;
        /* 同じ形を別の道で計算するので、端数の丸めで 1 画素ずれることがある
         * （VM の ARM と手元の x86 で違った）。隣の画素までは同じとみなす */
        if (img[0][k] != img[1][k] &&
            (!near_ink(img[1], k, img[0][k]) || !near_ink(img[0], k, img[1][k])))
            differ++;
        if (img[2][k] != img[1][k])
            wrongdiff++;
    }
    printf("     %d pixels of ink, %d differ (倍率 x だけなら %d)\n", ink, differ,
           wrongdiff);
    ck(ink > 200, "描画: 反転した参照が画面に出る");
    ck(wrongdiff > 50, "描画: 倍率 x だけの形とは違う形の試験");
    ck(differ == 0, "描画: 裏返した線（T + R·diag(x,y)·p）と同じ画素");

    /* PDF */
    {
        static double pa[2000], pb[2000];
        int na, nb, bad = 0;

        build(&d, 0);
        na = pdf_points(&d, pa, 1000);
        build(&d, 1);
        nb = pdf_points(&d, pb, 1000);
        printf("     PDF の点 %d と %d\n", na, nb);
        ck(na > 0 && na == nb, "PDF: 点の数が同じ");
        for (k = 0; k < na && k < nb; k++)
            if (fabs(pa[k * 2] - pb[k * 2]) > 0.011
                || fabs(pa[k * 2 + 1] - pb[k * 2 + 1]) > 0.011) {
                if (bad < 4)
                    printf("     %d: (%g,%g) と (%g,%g)\n", k, pa[k * 2],
                           pa[k * 2 + 1], pb[k * 2], pb[k * 2 + 1]);
                bad++;
            }
        ck(na == nb && bad == 0, "PDF: 裏返した線と同じ点");
    }

    /* 当たり（AUTO の左クリック → au_block_hit） */
    build(&d, 0);
    for (k = 0; k < NREF; k++) {
        double x, y, wx, wy;
        char what[128];

        /* 鉤の縦の線（定義 0 の二本目）の中ほど。入れ子は 内の参照で写してから */
        x = 20.0;
        y = 6.0;
        wx = x;
        wy = y;
        if ((int)REF[k][5] == 1) {
            put(DEF1_REF, 0, x, y, &x, &y);
            put(DEF1_REF, 1, wx, wy, &wx, &wy);
        }
        put(REF[k], 0, x, y, &x, &y);
        put(REF[k], 1, wx, wy, &wx, &wy);
        snprintf(what, sizeof what, "当たり: 参照 %d 倍率 (%g,%g) %g° の裏返った線 (%.1f,%.1f)",
                 k, REF[k][2], REF[k][3], REF[k][4], x, y);
        ck(hit(&d, &v, x, y), what);
        snprintf(what, sizeof what, "当たり: 参照 %d 裏返らずに回っただけの所 (%.1f,%.1f) は外れ",
                 k, wx, wy);
        ck(!hit(&d, &v, wx, wy), what);
    }
    jw_cmd_set(JW_CMD_AUTO);

    for (i = 0; i < 3; i++)
        free(img[i]);
    jw_free(&d);
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
