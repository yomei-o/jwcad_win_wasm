/* 建築の平面図を一枚、人が毎日やる順に描く通しの試験。
 *
 *   tests/workflow_test.exe
 *
 * 用紙と縮尺を決め、通り芯を引いて複線で割り、２線で壁を回し（(R) で読み、
 * (LL) で角を回る）、コーナー・伸縮・消去（部分消し・節間消し）で開口と取り
 * 合いを整え、建具・寸法・室名（文字の移動と複写も）・ハッチを入れ、範囲を
 * 選んで複写・移動・パラメトリック変形し、属性変更で取り違えを直す。そのあと
 * 戻る・進むを何段も行き来し、.jww と .dxf に書いて読み戻す。
 *
 * どれも app_press・app_move・app_key・app_command（とバーの箱）だけで、
 * 画面の点は用紙の mm から画素に直して押す。個々の命令の細かい答え合わせは
 * それぞれの試験がやっているので、ここは「つながって最後まで行けるか」：
 * 落ちない・数が NaN にならない・戻るで元に戻る・保存して読んでも変わらない。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cp932.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static int fails;
static jw_drawing *d;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near_(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

/* 用紙の mm → 画面の画素 */
static void px(double mx, double my, int *x, int *y)
{
    const jw_view *v = app_view();

    *x = (int)floor(v->bx + (mx - v->ox) * v->scale + 0.5);
    *y = (int)floor(v->by - (my - v->oy) * v->scale + 0.5);
}

/* WF_V=1 なら押すたびに 点・要素の数・案内文 を出す */
static void vprint(double mx, double my, int button)
{
    if (getenv("WF_V")) {
        const char *p = jw_cmd_prompt();
        unsigned short w[400];
        long n = p ? jw_to_utf16(p, (long)strlen(p), w, 400) : 0, i;

        printf("       at %.3f,%.3f %c -> n=%d [", mx, my, "LRD"[button], d->ndrawn);
        for (i = 0; i < n; i++) {
            unsigned c = w[i];

            if (c < 0x80)
                putchar((int)c);
            else if (c < 0x800) {
                putchar((int)(0xc0 | (c >> 6)));
                putchar((int)(0x80 | (c & 63)));
            } else {
                putchar((int)(0xe0 | (c >> 12)));
                putchar((int)(0x80 | ((c >> 6) & 63)));
                putchar((int)(0x80 | (c & 63)));
            }
        }
        printf("]\n");
    }
}

/* マウスをそこへ持っていって押す。button 0 が (L)、1 が (R) */
static void at(double mx, double my, int button)
{
    int x, y;

    px(mx, my, &x, &y);
    app_move(x, y);
    app_press(x, y, button);
    app_release(x, y, button);
    vprint(mx, my, button);
}

/* (LL): 同じ所を続けて二度 */
static void dbl(double mx, double my)
{
    int x, y;

    px(mx, my, &x, &y);
    app_move(x, y);
    app_press(x, y, 0);
    app_release(x, y, 0);
    app_press(x, y, 0);
    app_release(x, y, 0);
    vprint(mx, my, 2);
}

/* 少し動かすだけ（原典は (L) のあと 2 画素動くまで待つ命令がある） */
static void wiggle(double mx, double my)
{
    int x, y;

    px(mx, my, &x, &y);
    app_move(x + 6, y + 6);
}

static void box(int id, const char *s)
{
    jw_cmd_box_put(id, s);
}

static void type(const unsigned short *s)
{
    for (; *s; s++) {
        unsigned short u = *s;
        char buf[4];
        long m = jw_from_utf16(&u, 1, buf, sizeof buf), i;

        for (i = 0; i < m; i++)
            app_key((unsigned char)buf[i]);
    }
}

static int count_cls(int cls)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        n += d->obj[i].cls == cls;
    return n;
}

static double wscale(void)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

/* 書込みレイヤを n に（レイヤの釦を (R)） */
static void write_layer(int n)
{
    const fb_t *fb = app_fb();
    int x, y, k;

    app_paint();
    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_layer_hit(fb->w, x, y, &k) == 0 && k == n) {
                app_press(x, y, 1);
                return;
            }
    printf("BAD  レイヤ %d の釦が無い\n", n);
    fails++;
}

/* レイヤ n の釦を (L)。編集 → 非表示 → 表示のみ → 編集 と回る */
static void layer_click(int n)
{
    const fb_t *fb = app_fb();
    int x, y, k;

    app_paint();
    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_layer_hit(fb->w, x, y, &k) == 0 && k == n) {
                app_press(x, y, 0);
                return;
            }
    printf("BAD  レイヤ %d の釦が無い\n", n);
    fails++;
}

static int layer_state(int n)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].layer[n].state;
}

/* バーの箱を押して、打って、Enter */
static void typebox(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 40; i++)
        app_key(8);
    for (; *s; s++)
        app_key((unsigned char)*s);
    app_key(13);
}

/* (x0,y0)-(x1,y1) の線（向きは問わない）の番号。無ければ -1 */
static int find_line(double x0, double y0, double x1, double y1)
{
    int i;

    for (i = 0; i < d->ndrawn; i++) {
        const double *q = d->obj[i].d;

        if (d->obj[i].cls != JW_SEN)
            continue;
        if ((near_(q[0], x0) && near_(q[1], y0) && near_(q[2], x1) && near_(q[3], y1))
            || (near_(q[0], x1) && near_(q[1], y1) && near_(q[2], x0) && near_(q[3], y0)))
            return i;
    }
    return -1;
}

/* x = xx に立つ長さ 50 mm を超える縦の線（通り芯・補助線）の数 */
static int vline_long(double xx)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++) {
        const double *q = d->obj[i].d;

        if (d->obj[i].cls == JW_SEN && near_(q[0], xx) && near_(q[2], xx)
            && fabs(q[3] - q[1]) > 50)
            n++;
    }
    return n;
}

/* 横の線 y=yy で、x の範囲 [a,b] を覆うものの数 */
static int hline_covers(double yy, double a, double b)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++) {
        const double *q = d->obj[i].d;
        double lo, hi;

        if (d->obj[i].cls != JW_SEN || !near_(q[1], yy) || !near_(q[3], yy))
            continue;
        lo = q[0] < q[2] ? q[0] : q[2];
        hi = q[0] < q[2] ? q[2] : q[0];
        if (lo <= a + 1e-6 && hi >= b - 1e-6)
            n++;
    }
    return n;
}

/* 文字 t を持つ字の数 */
static int count_text(const char *t)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].text >= 0
            && !strcmp(jw_str(d, d->obj[i].text), t))
            n++;
    return n;
}

/* ---- 段ごとの控え（戻る・進むで比べる） ---------------------------------- */
typedef struct {
    jw_obj *o;
    int n, nd, depth;
    const char *name;
} snap_t;
static snap_t snaps[40];
static int nsnap;

static void clean_sel(jw_obj *o, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        o[i].sel = 0;
        o[i].was_sel = 0;
        o[i].flags &= ~2u;
    }
}

static void phase(const char *name)
{
    snap_t *s = &snaps[nsnap++];
    char m[160];

    app_key(27);                        /* 途中の操作は残さない */
    app_paint();
    s->name = name;
    s->n = d->nobj;
    s->nd = d->ndrawn;
    s->depth = jw_cmd_undo_depth();
    s->o = (jw_obj *)malloc((size_t)(s->n + 1) * sizeof *s->o);
    if (s->n)
        memcpy(s->o, d->obj, (size_t)s->n * sizeof *s->o);
    clean_sel(s->o, s->n);
    snprintf(m, sizeof m, "[%s] 数が正気（%d 要素、戻る %d 段）", name, d->ndrawn, s->depth);
    ck(jw_numbers_sane(d), m);
}

static int same_as(const snap_t *s)
{
    clean_sel(d->obj, d->nobj);
    return d->nobj == s->n && d->ndrawn == s->nd
        && (!s->n || !memcmp(d->obj, s->o, (size_t)s->n * sizeof *s->o));
}

static int cmp_obj(const void *a, const void *b)
{
    return memcmp(a, b, sizeof(jw_obj));
}

/* 進む は足した要素を頭に戻す（原典どおり、jw_cmd_redo の注）ので、
   並びは問わず中身だけ比べる */
static int same_set(const snap_t *s)
{
    jw_obj *a, *b;
    int ok;

    clean_sel(d->obj, d->nobj);
    if (d->nobj != s->n || d->ndrawn != s->nd)
        return 0;
    if (!s->n)
        return 1;
    a = (jw_obj *)malloc((size_t)s->n * sizeof *a);
    b = (jw_obj *)malloc((size_t)s->n * sizeof *b);
    memcpy(a, d->obj, (size_t)s->n * sizeof *a);
    memcpy(b, s->o, (size_t)s->n * sizeof *b);
    qsort(a, (size_t)s->nd, sizeof *a, cmp_obj);
    qsort(b, (size_t)s->nd, sizeof *b, cmp_obj);
    ok = !memcmp(a, b, (size_t)s->n * sizeof *a);
    free(a);
    free(b);
    return ok;
}

static void show_diff(const snap_t *s)
{
    int q, k = 0;

    printf("     nobj %d / %d  ndrawn %d / %d\n", d->nobj, s->n, d->ndrawn, s->nd);
    for (q = 0; q < d->nobj && q < s->n && k < 6; q++)
        if (memcmp(&d->obj[q], &s->o[q], sizeof *d->obj)) {
            printf("     %d: cls %d/%d  %.4f,%.4f,%.4f,%.4f / %.4f,%.4f,%.4f,%.4f\n", q,
                   d->obj[q].cls, s->o[q].cls, d->obj[q].d[0], d->obj[q].d[1],
                   d->obj[q].d[2], d->obj[q].d[3], s->o[q].d[0], s->o[q].d[1],
                   s->o[q].d[2], s->o[q].d[3]);
            k++;
        }
}

/* ---- 保存して読み戻す ----------------------------------------------------- */
static int shown(const jw_drawing *e, int cls)
{
    int i, n = 0;

    for (i = 0; i < e->ndrawn; i++)
        if (e->obj[i].cls == cls && !(cls == JW_MOJI && e->obj[i].d[1] == -1000.0))
            n++;
    return n;
}

int main(void)
{
    /* 室名（UTF-16） */
    static const unsigned short ldk[] = { 'L', 'D', 'K', 0 };
    static const unsigned short yoshitsu[] = { 0x6d0b, 0x5ba4, 0 };      /* 洋室 */
    static const unsigned short genkan[] = { 0x7384, 0x95a2, 0 };        /* 玄関 */
    char yoshitsu_s[16], genkan_s[16];
    double S, X1, X2, X3, Y1, Y2, t, A, B;
    int i, n, before;

    jw_from_utf16(yoshitsu, 2, yoshitsu_s, sizeof yoshitsu_s);
    yoshitsu_s[4] = 0;
    jw_from_utf16(genkan, 2, genkan_s, sizeof genkan_s);
    genkan_s[4] = 0;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();

    /* ---- 1. 用紙 A3・縮尺 1/50 ----------------------------------------- */
    app_command(32823);                 /* 用紙サイズ A-3 */
    ck(d->paper_size == 3, "用紙は A-3");
    ck(app_command(32944) && app_shakudo_open(), "縮尺・読取 の窓が出る");
    for (i = 0; i < 6; i++)
        app_key(8);                     /* 分母の 100 を消して */
    app_key('5');
    app_key('0');
    app_key(13);
    ck(!app_shakudo_open() && wscale() == 50.0, "縮尺 1/50");
    S = wscale();
    app_fit();
    phase("用紙・縮尺");

    /* ---- 2. 通り芯: 線を二本、複線で割る（レイヤ 8） --------------------- */
    write_layer(8);
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar(d, 1333);
    before = d->ndrawn;
    at(-90, -85, 0);
    at(-90, 55, 0);                     /* X1 */
    at(-105, -70, 0);
    at(75, -70, 0);                     /* Y1 */
    ck(d->ndrawn == before + 2, "通り芯 X1・Y1 を引く");
    X1 = d->obj[before].d[0];
    Y1 = d->obj[before + 1].d[1];
    ck(near_(d->obj[before].d[2], X1) && near_(d->obj[before + 1].d[3], Y1),
       "  縦は縦、横は横");
    app_command(JW_CMD_FUKUSEN);
    /* 原典の 複線 は線を拾ってから間隔の箱が出る（jw_cmd_box_put の注） */
    at(X1, 0, 0);                       /* X1 を拾って */
    box(1411, "3640");
    at(X1 + 20, 0, 0);                  /* 右へ → X2 */
    at(X1 + 72.8, 0, 1);                /* X2 を (R) 前回値で拾って */
    at(X1 + 100, 0, 0);                 /* 右へ → X3 */
    at(0, Y1, 0);
    box(1411, "5460");
    at(0, Y1 + 20, 0);                  /* 上へ → Y2 */
    X2 = X1 + 3640 / S;
    X3 = X1 + 7280 / S;
    Y2 = Y1 + 5460 / S;
    ck(d->ndrawn == before + 5, "複線で X2・X3・Y2");
    ck(vline_long(X2) == 1, "  X2 は 3640 右");
    ck(d->ndrawn > before + 3 && near_(d->obj[before + 3].d[0], X3), "  X3 はさらに 3640 右");
    ck(d->ndrawn > before + 4 && near_(d->obj[before + 4].d[1], Y2), "  Y2 は 5460 上");
    for (i = before; i < d->ndrawn; i++)
        if (d->obj[i].layer != 8)
            break;
    ck(i == d->ndrawn, "  通り芯はみなレイヤ 8");
    phase("通り芯");

    /* ---- 3. 壁: ２線 150（75,75）で外周を一筆。(R) で始点・終点、(LL) で角 -- */
    write_layer(0);
    t = 75 / S;
    app_command(JW_CMD_NISEN);
    box(1412, "75");
    before = d->ndrawn;
    at((X1 + X2) / 2, Y1, 0);           /* 基準線 Y1 */
    wiggle((X1 + X2) / 2, Y1);
    at(X1, Y1, 1);                      /* 始点 (R) X1∩Y1 */
    wiggle(X1, Y1);
    dbl(X3, (Y1 + Y2) / 2);             /* (LL) X3 で角を回る */
    wiggle(X3, (Y1 + Y2) / 2);
    dbl((X2 + X3) / 2, Y2);             /* (LL) Y2 */
    wiggle((X2 + X3) / 2, Y2);
    dbl(X1, (Y1 + Y2) / 2 + 3);         /* (LL) X1 */
    wiggle(X1, (Y1 + Y2) / 2 + 3);
    at(X1, Y1, 1);                      /* 終点 (R) X1∩Y1 */
    wiggle(X1, Y1);
    printf("     ２線: %d 本\n", d->ndrawn - before);
    ck(d->ndrawn == before + 8, "外壁は 4 辺 × 2 本");
    ck(find_line(X3 + t, Y1 - t, X3 + t, Y2 + t) >= 0 && find_line(X3 - t, Y1 + t, X3 - t, Y2 - t) >= 0,
       "  東の壁は角どうしで出会う");
    ck(find_line(X1 + t, Y2 - t, X1 + t, Y1) >= 0 && find_line(X1 - t, Y2 + t, X1 - t, Y1) >= 0,
       "  西の壁は Y1 まで（始点の角はまだ開いている）");
    /* 始点の角をコーナーで閉じる: 外の二本、内の二本 */
    app_command(JW_CMD_CORNER);
    at((X1 + X2) / 2, Y1 - t, 0);
    at(X1 - t, (Y1 + Y2) / 2, 0);
    at((X1 + X2) / 2, Y1 + t, 0);
    at(X1 + t, (Y1 + Y2) / 2, 0);
    ck(find_line(X1 - t, Y2 + t, X1 - t, Y1 - t) >= 0 && find_line(X1 - t, Y1 - t, X3 + t, Y1 - t) >= 0,
       "  コーナー: 外の角が閉じる");
    ck(find_line(X1 + t, Y2 - t, X1 + t, Y1 + t) >= 0 && find_line(X1 + t, Y1 + t, X3 - t, Y1 + t) >= 0,
       "  コーナー: 内の角も");
    ck(d->ndrawn == before + 8, "  本数は変わらない");
    phase("外壁");

    /* 間仕切り: X2 に沿って ２線、伸縮の基準線で内面まで縮め、節間消しで T を抜く */
    app_command(JW_CMD_NISEN);
    box(1412, "50");
    before = d->ndrawn;
    at(X2, (Y1 + Y2) / 2, 0);
    wiggle(X2, (Y1 + Y2) / 2);
    at(X2, Y1, 1);
    wiggle(X2, Y1);
    at(X2, Y2, 1);
    wiggle(X2, Y2);
    ck(d->ndrawn == before + 2, "間仕切り ２線 50 で二本");
    {
        double u = 50 / S;

        app_command(JW_CMD_SHINSHUKU);
        at((X1 + X2) / 2, Y1 + t, 1);   /* (RR) 基準線 = 南の壁の内面 */
        at((X1 + X2) / 2, Y1 + t, 1);
        at(X2 - u, Y1 + 20, 0);
        at(X2 + u, Y1 + 20, 0);
        app_key(27);
        at((X1 + X2) / 2, Y2 - t, 1);   /* 北の壁の内面 */
        at((X1 + X2) / 2, Y2 - t, 1);
        at(X2 - u, Y2 - 20, 0);
        at(X2 + u, Y2 - 20, 0);
        app_key(27);
        ck(find_line(X2 - u, Y1 + t, X2 - u, Y2 - t) >= 0 && find_line(X2 + u, Y1 + t, X2 + u, Y2 - t) >= 0,
           "  伸縮 (RR) 基準線: 両端が壁の内面まで");
        /* 通り芯が交わりに数えられないよう、レイヤ 8 を 表示のみ に */
        layer_click(8);
        layer_click(8);
        ck(layer_state(8) == 1, "  通り芯のレイヤを 表示のみ に");
        app_command(JW_CMD_SHOUKYO);
        jw_cmd_bar(d, 1324);            /* 節間消し */
        at(X2, Y1 + t, 0);
        at(X2, Y2 - t, 0);
        jw_cmd_bar(d, 1324);
        layer_click(8);
        ck(layer_state(8) == 2, "  通り芯のレイヤを 編集 に戻す");
        ck(find_line(X1 + t, Y1 + t, X2 - u, Y1 + t) >= 0 && find_line(X2 + u, Y1 + t, X3 - t, Y1 + t) >= 0,
           "  節間消し: 南の内面が間仕切りの所で抜ける");
        ck(find_line(X1 + t, Y2 - t, X2 - u, Y2 - t) >= 0 && find_line(X2 + u, Y2 - t, X3 - t, Y2 - t) >= 0,
           "  北の内面も");
    }
    phase("間仕切り");

    /* ---- 4. 開口: 南の壁に 1820 の開口。補助線を複線で、(R) で読んで部分消し -- */
    A = X1 + 910 / S;
    B = X1 + 2730 / S;
    app_command(JW_CMD_FUKUSEN);
    at(X1, (Y1 + Y2) / 2 - 10, 0);
    box(1411, "910");
    at(X1 + 10, (Y1 + Y2) / 2 - 10, 0);
    at(A, (Y1 + Y2) / 2 - 10, 0);
    box(1411, "1820");
    at(A + 10, (Y1 + Y2) / 2 - 10, 0);
    n = d->ndrawn;
    ck(vline_long(A) == 1 && near_(d->obj[n - 2].d[0], A), "補助線 A（X1 から 910）");
    ck(vline_long(B) == 1 && near_(d->obj[n - 1].d[0], B), "補助線 B（そこから 1820）");
    app_command(JW_CMD_SHOUKYO);
    at((A + B) / 2, Y1 - t, 0);         /* 外面を拾って */
    at(A, Y1 - t, 1);                   /* 始点 (R) */
    at(B, Y1 - t, 1);                   /* 終点 (R) */
    at((A + B) / 2, Y1 + t, 0);         /* 内面も */
    at(A, Y1 + t, 1);
    at(B, Y1 + t, 1);
    ck(hline_covers(Y1 - t, A + 0.1, B - 0.1) == 0 && hline_covers(Y1 + t, A + 0.1, B - 0.1) == 0,
       "部分消し (R)Read: 外面・内面とも A〜B が抜ける");
    ck(find_line(X1 - t, Y1 - t, A, Y1 - t) >= 0 && find_line(B, Y1 - t, X3 + t, Y1 - t) >= 0,
       "  外面は A と B でちょうど切れる");
    /* 補助線は (R) で消して、抱きの線を (R)〜(R) で */
    at(A, Y2 + 5, 1);
    at(B, Y2 + 5, 1);
    ck(vline_long(A) == 0 && vline_long(B) == 0, "補助線を (R) で消す");
    app_command(JW_CMD_SEN);
    before = d->ndrawn;
    at(A, Y1 - t, 1);
    at(A, Y1 + t, 1);
    at(B, Y1 - t, 1);
    at(B, Y1 + t, 1);
    ck(d->ndrawn == before + 2 && find_line(A, Y1 - t, A, Y1 + t) >= 0 && find_line(B, Y1 - t, B, Y1 + t) >= 0,
       "抱きの線を (R)Read で二本");
    phase("開口");

    /* ---- 5. 建具: 開口の中ほどに 建具平面 の一つ目 ------------------------- */
    write_layer(1);
    before = d->ndrawn;
    app_command(JW_CMD_TATEGU);
    app_paint();
    app_key('1');
    at((A + B) / 2, Y1, 0);
    at((A + B) / 2, Y1, 0);
    app_key(27);
    printf("     建具: %d → %d\n", before, d->ndrawn);
    ck(d->ndrawn > before, "建具を置く");
    ck(jw_numbers_sane(d), "  数は正気");
    phase("建具");

    /* ---- 6. 寸法: 北の外側に X1・X2・X3 を連続で --------------------------- */
    write_layer(2);
    before = d->ndrawn;
    app_command(JW_CMD_SUNPO);
    at(X1, Y2 + 15, 0);                 /* 引出し線の始点 */
    at(X1, Y2 + 12, 0);                 /* 寸法線の位置 */
    at(X1, Y2, 1);
    at(X2, Y2, 1);
    at(X3, Y2, 1);
    app_key(27);
    printf("     寸法: %d → %d\n", before, d->ndrawn);
    ck(count_text("3,640") >= 2, "寸法値 3,640 が二つ");
    phase("寸法");

    /* ---- 7. 室名: 文字。入れ違えて移動し、複写する ------------------------- */
    write_layer(3);
    before = d->ndrawn;
    app_command(JW_CMD_MOJI);
    type(ldk);
    at(X1 + 20, Y1 + 50, 0);
    type(yoshitsu);
    at(X2 + 20, Y1 + 30, 0);            /* わざと低い所に */
    ck(d->ndrawn == before + 2, "室名を二つ");
    ck(count_text("LDK") == 1 && count_text(yoshitsu_s) == 1, "  LDK と 洋室");
    {   /* 入力欄が空の (L) で 洋室 を拾い、上へ移す */
        const jw_obj *o = &d->obj[d->ndrawn - 1];
        double mx = (o->d[0] + o->d[2]) / 2, my = o->d[1] + o->d[5] * 0.3;

        at(mx, my, 0);
        at(X2 + 20, Y1 + 70, 0);
        o = &d->obj[d->ndrawn - 1];
        ck(d->ndrawn == before + 2 && count_text(yoshitsu_s) == 1
           && fabs(o->d[1] - (Y1 + 70)) < 2.0, "  文字を (L) で拾って移動");
        /* (R) で拾って下へ複写、入力を 玄関 に書き換える前に置く */
        mx = (o->d[0] + o->d[2]) / 2;
        my = o->d[1] + o->d[5] * 0.3;
        at(mx, my, 1);
        at(X2 + 20, Y1 + 30, 0);
        ck(d->ndrawn == before + 3 && count_text(yoshitsu_s) == 2, "  (R) で拾って複写");
    }
    /* 文字種の違う 玄関 */
    type(genkan);
    at(X1 + 10, Y1 + 10, 0);
    ck(count_text(genkan_s) == 1, "玄関");
    for (i = before; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].layer != 3)
            break;
    ck(i == d->ndrawn, "  字はみなレイヤ 3");
    phase("室名");

    /* ---- 8. ハッチ: 玄関の土間を矩形で囲い、(R) で輪を拾って実行 ------------ */
    write_layer(4);
    app_command(JW_CMD_KUKEI);
    at(X1 + 5, Y1 + 5, 0);
    at(X1 + 30, Y1 + 22, 0);
    before = d->ndrawn;
    app_command(JW_CMD_HATCH);
    {
        const jw_obj *o = &d->obj[before - 1];

        at((o->d[0] + o->d[2]) / 2, (o->d[1] + o->d[3]) / 2, 1);
    }
    box(1411, "3");
    jw_cmd_bar(d, 1148);
    printf("     ハッチ: %d → %d\n", before, d->ndrawn);
    ck(d->ndrawn > before + 3, "ハッチの線が入る");
    phase("ハッチ");

    /* ---- 9. 範囲選択して 複写・移動、パラメトリック変形 -------------------- */
    {
        int nb = d->ndrawn, k;
        double ex0 = X1 + 5, ey0 = Y1 + 5;

        /* 土間（矩形とハッチ）を東の部屋へ複写 */
        app_command(JW_CMD_FUKUSHA);
        at(X1 + 3, Y1 + 3, 0);
        at(X1 + 32, Y1 + 24, 0);
        k = jw_cmd_sel_count(d);
        printf("     複写の選択: %d\n", k);
        app_move(0, 0);
        jw_cmd_track(ex0, ey0);         /* 基準点 = 土間の角 */
        jw_cmd_bar(d, 1120);            /* 選択確定 */
        at(X2 + 10, Y1 + 5, 0);
        app_key(27);
        ck(k > 4 && d->ndrawn == nb + k, "範囲を選んで 複写");
        phase("複写");

        /* 複写したものを 移動 で 100（図で 2 mm）右へ。数値位置 を打って Enter */
        {
            jw_obj *cp = (jw_obj *)malloc((size_t)k * sizeof *cp);
            int q, moved = 0;

            memcpy(cp, &d->obj[d->ndrawn - k], (size_t)k * sizeof *cp);
            nb = d->ndrawn;
            app_command(JW_CMD_IDOU);
            at(X2 + 8, Y1 + 3, 0);
            at(X2 + 37, Y1 + 24, 0);
            printf("     移動の選択: %d\n", jw_cmd_sel_count(d));
            jw_cmd_bar(d, 1120);
            typebox(1413, "100,0");
            typebox(1413, "");
            app_key(27);
            for (q = 0; q < k; q++)
                if (cp[q].cls == JW_SEN
                    && find_line(cp[q].d[0] + 2, cp[q].d[1], cp[q].d[2] + 2, cp[q].d[3]) >= 0)
                    moved++;
            printf("     移動した線: %d / %d\n", moved, k);
            ck(d->ndrawn == nb && moved == k, "移動: 数値位置 100,0 で 2 mm 右へ");
            free(cp);
        }
        phase("移動");

        /* パラメトリック変形: 東の壁を 910 だけ東へ（家が広がる）。これも数値位置で */
        app_command(JW_CMD_PARAM);
        at(X3 - 10, Y1 - 20, 0);
        at(X3 + 20, Y2 + 30, 0);
        k = jw_cmd_sel_count(d);
        printf("     パラメトリックの選択: %d\n", k);
        jw_cmd_bar(d, 1120);
        typebox(1413, "910,0");
        typebox(1413, "");
        app_key(27);
        ck(find_line(X3 + 910 / S + t, Y1 - t, X3 + 910 / S + t, Y2 + t) >= 0,
           "パラメトリック: 東の壁の外面が 910 東へ");
        ck(find_line(B, Y1 - t, X3 + 910 / S + t, Y1 - t) >= 0,
           "  南の外面は伸びる");
        ck(jw_numbers_sane(d), "  数は正気");
        phase("パラメトリック");
    }

    /* ---- 10. 属性変更: 通り芯 X2 を レイヤ 8 → 書込みレイヤ 5 へ ------------- */
    write_layer(5);
    {
        int k = -1;

        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_SEN && d->obj[i].layer == 8 && near_(d->obj[i].d[0], X2)
                && near_(d->obj[i].d[2], X2))
                k = i;
        ck(k >= 0, "通り芯 X2 がある");
        app_command(JW_CMD_ZOKUHEN);
        at(X2, Y1 - 10, 0);             /* 壁と寸法の無い所で */
        app_key(27);
        k = -1;
        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_SEN && near_(d->obj[i].d[0], X2) && near_(d->obj[i].d[2], X2)
                && fabs(d->obj[i].d[1] - d->obj[i].d[3]) > 100)
                k = i;
        ck(k >= 0 && d->obj[k].layer == 5, "属性変更: 通り芯 X2 がレイヤ 5 に");
    }
    phase("属性変更");

    /* ---- 11. 戻る・進むを何段も ------------------------------------------- */
    app_command(JW_CMD_SEN);
    {
        int k, guard;
        char m[160];

        for (k = nsnap - 2; k >= 0; k--) {
            guard = 0;
            while (jw_cmd_undo_depth() > snaps[k].depth && guard++ < 500)
                app_command(JW_CMD_UNDO);
            snprintf(m, sizeof m, "戻る: 「%s」のあとに戻る", snaps[k].name);
            ck(same_as(&snaps[k]), m);
            if (!same_as(&snaps[k]))
                show_diff(&snaps[k]);
        }
        for (k = 1; k < nsnap; k++) {
            guard = 0;
            while (jw_cmd_undo_depth() < snaps[k].depth && guard++ < 500)
                app_command(JW_CMD_REDO);
            snprintf(m, sizeof m, "進む: 「%s」まで進む（並びは問わない）", snaps[k].name);
            ck(same_set(&snaps[k]), m);
            if (!same_set(&snaps[k]))
                show_diff(&snaps[k]);
        }
        /* 行き来を五往復 */
        for (k = 0; k < 5; k++) {
            int q;

            for (q = 0; q < 400 && jw_cmd_can_undo(); q++)
                app_command(JW_CMD_UNDO);
            for (q = 0; q < 400 && jw_cmd_can_redo(); q++)
                app_command(JW_CMD_REDO);
        }
        ck(same_set(&snaps[nsnap - 1]), "五往復しても仕上がりのまま（並びは問わない）");
        ck(jw_numbers_sane(d), "  数は正気");
    }
    phase("行き来のあと");

    /* ---- 12. 保存して読み戻す ----------------------------------------------- */
    {
        const snap_t *fin = &snaps[nsnap - 1];
        unsigned char *out = 0, *dxf = 0;
        long on = 0, dn = 0;
        int c, ok, okc;

        /* 保存の前に ハッチのレイヤ 4 を 非表示 に（書込みはレイヤ 5 のまま） */
        layer_click(4);
        ck(layer_state(4) == 0 && layer_state(5) == 3, "ハッチのレイヤを 非表示 に");
        ck(app_save(&out, &on) && on > 0, ".jww に保存");
        ck(app_save_dxf(&dxf, &dn) && dn > 0, ".dxf に保存");
        app_new();
        ck(app_open(out, on), ".jww を開く");
        d = (jw_drawing *)app_drawing();
        printf("     jww: %d 要素（描いたのは %d）\n", d->ndrawn, fin->nd);
        {   /* 寸法は保存すると線・字に分かれて戻るので、種類ごとに比べる */
            jw_drawing m;

            memset(&m, 0, sizeof m);
            m.obj = fin->o;
            m.nobj = m.ndrawn = fin->nd;
            ok = 1;
            for (c = 0; c < JW_NCLASS; c++)
                if (shown(d, c) != shown(&m, c)) {
                    printf("     種類 %d: %d → %d\n", c, shown(&m, c), shown(d, c));
                    ok = 0;
                }
            ck(ok, "  種類ごとの数が同じ");
            okc = 1;
            for (i = 0; i < fin->nd && i < d->ndrawn; i++) {
                const jw_obj *a = &fin->o[i], *b = &d->obj[i];

                if (a->cls != b->cls || a->layer != b->layer || a->lgroup != b->lgroup
                    || a->color != b->color || a->ltype != b->ltype) {
                    printf("     %d: cls %d/%d layer %d/%d color %d/%d ltype %d/%d\n", i,
                           a->cls, b->cls, a->layer, b->layer, a->color, b->color, a->ltype, b->ltype);
                    okc = 0;
                    break;
                }
                for (c = 0; c < 8; c++)
                    if (fabs(a->d[c] - b->d[c]) > 1e-9) {
                        printf("     %d: d[%d] %.12g / %.12g\n", i, c, a->d[c], b->d[c]);
                        okc = 0;
                        break;
                    }
                if (!okc)
                    break;
            }
            /* 書くと隠れた設定の字（y = -1000）が後ろに六つ付く（flow_test の shown） */
            for (i = fin->nd; i < d->ndrawn; i++)
                if (!(d->obj[i].cls == JW_MOJI && d->obj[i].d[1] == -1000.0))
                    okc = 0;
            ck(okc && d->ndrawn >= fin->nd, "  一つずつ 種類・レイヤ・色・線種・座標が同じ");
            ck(count_text("LDK") == 1 && count_text(yoshitsu_s) == 2 && count_text(genkan_s) == 1
               && count_text("3,640") >= 2, "  字も同じ");
            printf("     読んだ縮尺 1/%g、用紙 %d\n", wscale(), d->paper_size);
            ck(fabs(wscale() - 50.0) < 1e-9 && d->paper_size == 3, "  縮尺 1/50・A-3 のまま");
            printf("     レイヤ 4 %d、5 %d、8 %d\n", layer_state(4), layer_state(5), layer_state(8));
            ck(layer_state(4) == 0 && layer_state(5) == 3 && layer_state(8) == 2,
               "  レイヤの 非表示・書込み も保存したまま");
        }
        /* もう一度書くと同じバイト */
        {
            unsigned char *out2 = 0;
            long on2 = 0;

            ck(app_save(&out2, &on2) && on2 == on && !memcmp(out, out2, (size_t)on),
               "  読んだものをもう一度書くと同じバイト");
            free(out2);
        }
        /* DXF */
        {
            int sen0 = 0, sen1;
            jw_drawing m;

            memset(&m, 0, sizeof m);
            m.obj = fin->o;
            m.nobj = m.ndrawn = fin->nd;
            sen0 = shown(&m, JW_SEN);
            app_new();
            ck(app_open_dxf(dxf, dn), ".dxf を読む");
            d = (jw_drawing *)app_drawing();
            sen1 = shown(d, JW_SEN);
            printf("     dxf: 線 %d → %d、字 %d → %d、円 %d → %d\n", sen0, sen1,
                   shown(&m, JW_MOJI), shown(d, JW_MOJI), shown(&m, JW_ENKO), shown(d, JW_ENKO));
            ck(jw_numbers_sane(d), "  数は正気");
            ck(sen1 >= sen0, "  線は減らない");
            ck(count_text("LDK") == 1 && count_text(yoshitsu_s) == 2 && count_text(genkan_s) == 1,
               "  室名が戻る");
            {   /* 南の外面の東側（開口の B からパラメトリックで伸びた端まで）が同じ
                   実寸の所に。DXF は実寸で書かれ、読むと縮尺は用紙に収まるよう選び
                   直されるので、図の mm は 50 / 縮尺 倍になる */
                double k = 50.0 / wscale(), x0 = B * k, x1 = (X3 + 910 / S + t) * k, y = (Y1 - t) * k;
                int q, hit = 0;

                printf("     dxf の縮尺 1/%g\n", wscale());
                for (q = 0; q < d->ndrawn; q++) {
                    const double *e = d->obj[q].d;

                    if (d->obj[q].cls == JW_SEN
                        && ((fabs(e[0] - x0) < 1e-4 && fabs(e[2] - x1) < 1e-4)
                            || (fabs(e[0] - x1) < 1e-4 && fabs(e[2] - x0) < 1e-4))
                        && fabs(e[1] - y) < 1e-4 && fabs(e[3] - y) < 1e-4)
                        hit++;
                }
                ck(hit == 1, "  南の外面が同じ実寸の所に");
            }
        }
        free(out);
        free(dxf);
    }

    for (i = 0; i < nsnap; i++)
        free(snaps[i].o);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
