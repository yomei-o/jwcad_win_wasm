/* ２．５D (32937) の (L) 設定・変更: 線の端に「高さ , 奥行」の文字が付く
   （原典 decomp/res/p197_h1.jww）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/d25view.h"
#include "../src/gen/bars.h"

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
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n)
        return 0;
    fclose(f);
    return b;
}

static int run(int cmd, const char *refpath, const char *name)
{
    long n, rn;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    unsigned char *rb = slurp(refpath, &rn);
    jw_drawing ref;
    const jw_drawing *d;
    rect_t r;
    const jw_obj *a, *m;
    int k, fails = 0;

    if (!b || !rb)
        return 1;
    memset(&ref, 0, sizeof ref);
    jw_parse(&ref, rb, rn);
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32771);
    app_press(r.x + 300, r.y + 400, 0);
    app_press(r.x + 800, r.y + 400, 0);
    app_command(cmd);
    app_press(r.x + 300, r.y + 400, 0);
    d = app_drawing();
    if (d->ndrawn < 2 || ref.ndrawn < 2) {
        printf("BAD  文字が付かない\n");
        return 1;
    }
    a = &ref.obj[1];
    m = &d->obj[d->ndrawn - 1];
    if (m->cls != JW_MOJI || m->color != a->color || m->ltype != a->ltype ||
        m->flags != a->flags || m->n != a->n) {
        printf("BAD  属性 cls%d col%d lt%d fl%x\n", m->cls, m->color, m->ltype, m->flags);
        fails++;
    }
    for (k = 0; k < 6; k++)
        if (fabs(a->d[k] - m->d[k]) > 2e-3) {
            printf("BAD  d[%d] 原典 %.4f・移植 %.4f\n", k, a->d[k], m->d[k]);
            fails++;
        }
    if (strcmp(jw_str(&ref, a->text), jw_str(d, m->text))) {
        printf("BAD  文字\n");
        fails++;
    }
    printf("%-4s %s\n", fails ? "BAD" : "ok", name);
    return fails != 0;
}

/* ---- 透視図・鳥瞰図・アイソメ（src/d25view.c）。原典の答えは無いので、
   逆コンパイルの読み（FUN_00613c10・FUN_0043ecc0・FUN_00617640）を
   手で計算した値と比べる。原典では押していない。 ---- */
static int vfail;

static void vck(int ok, const char *what)
{
    if (!ok) {
        printf("BAD  %s\n", what);
        vfail++;
    }
}

static unsigned long long fbsum(void)
{
    const fb_t *f = app_fb();
    unsigned long long h = 1469598103934665603ULL;
    long i;

    for (i = 0; i < (long)f->w * f->h; i++)
        h = (h ^ f->px[i]) * 1099511628211ULL;
    return h;
}

static int veq(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

/* 画面の絵の i 本目（補助線を除いて） */
static int view_line(const jw_drawing *d, int i, double o[4], int *n)
{
    jw_drawing one = *d;
    int k, m = 0, got = 0;

    one.obj = 0;
    one.nobj = one.ndrawn = one.cobj = 0;
    *n = jw_d25_view(d, &one);
    for (k = 0; k < one.ndrawn; k++) {
        if (one.obj[k].ltype == 9 && one.obj[k].color == 9)
            continue;
        if (m++ == i) {
            memcpy(o, one.obj[k].d, 4 * sizeof o[0]);
            got = 1;
        }
    }
    free(one.obj);
    return got;
}

static int views(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d;
    rect_t r;
    double x1, y1, x2, p[6], o[4], k[6], cxm, cz, c, s, pc, ps;
    int nv, i, nd, base_off;
    unsigned long long plan_sum;

    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32771);
    app_press(r.x + 300, r.y + 400, 0);
    app_press(r.x + 800, r.y + 400, 0);
    app_command(32937);
    app_press(r.x + 300, r.y + 400, 0);     /* 「10 , 0」を両端に */
    app_press(r.x + 800, r.y + 400, 0);
    d = (jw_drawing *)app_drawing();
    /* new.jww には初めから文字がある（線の端には無い）。線は末尾から三つ目 */
    i = d->ndrawn - 3;
    vck(i >= 0 && d->obj[i].cls == JW_SEN && d->obj[i + 1].cls == JW_MOJI
        && d->obj[i + 2].cls == JW_MOJI && veq(d->obj[i].d[1], d->obj[i].d[3]),
        "線一本と文字二つ");
    if (vfail || i < 0)
        return 1;
    x1 = d->obj[i].d[0];
    y1 = d->obj[i].d[1];
    x2 = d->obj[i].d[2];

    /* (m) の字: 「( m )」↔「 [mm] 」（FUN_00404f50 の 0x955948・0x955938） */
    vck(jw_cmd_bar_label(1067) && !strcmp(jw_cmd_bar_label(1067), "( m )"), "(m) の字");
    jw_cmd_bar(d, 1067);
    vck(jw_d25_mm() && !strcmp(jw_cmd_bar_label(1067), " [mm] "), "(m) を押すと [mm]");
    jw_cmd_bar(d, 1067);
    vck(!jw_d25_mm(), "もう一度で (m)");

    /* アイソメ: 10 m は 1/100 で 100 図寸 mm。奥行の線・高さの線・両端の縦の線の四本 */
    app_paint();
    plan_sum = fbsum();
    jw_cmd_bar(d, 1066);
    app_paint();
    vck(fbsum() != plan_sum, "画面が 平面から立体の絵に替わる");
    vck(jw_d25_mode() == 3 &&jw_cmd_bar_check(9017) == 1 && jw_cmd_bar_check(9016) == 0,
        "アイソメ (1066) で 段 3、バーが替わる");
    vck(jw_d25_nline() == 4, "立体は四本");
    if (vfail)
        for (i = 0; jw_d25_line(i, p); i++)
            printf("    3D %d: (%.4f,%.4f,%.4f)-(%.4f,%.4f,%.4f)\n", i, p[0], p[1], p[2], p[3],
                   p[4], p[5]);
    vck(jw_d25_line(0, p) && veq(p[0], x1) && veq(p[2], 0) && veq(p[3], x2) && veq(p[5], 0),
        "  奥行の線 (z 0)");
    vck(jw_d25_line(1, p) && veq(p[2], 100) && veq(p[5], 100), "  高さの線 (z 100)");
    vck(jw_d25_line(2, p) && veq(p[0], x1) && veq(p[3], x1) && veq(p[2], 100) && veq(p[5], 0),
        "  始点の縦の線");
    vck(jw_d25_line(3, p) && veq(p[0], x2) && veq(p[3], x2) && veq(p[2], 100) && veq(p[5], 0),
        "  終点の縦の線");
    jw_d25_knobs(k);
    vck(veq(k[0], -45.0) && veq(k[5], atan2(1.0, sqrt(2.0)) * 180.0 / 3.14159265358979323846),
        "  初めは 回転 -45°・見下ろし 35.26°");
    /* 真ん中は 中点の平均: x は線の中、z は (0+100+50+50)/4 = 50 */
    cxm = (x1 + x2) / 2.0;
    cz = 50.0;
    c = cos(-45.0 * 3.14159265358979323846 / 180.0);
    s = sin(-45.0 * 3.14159265358979323846 / 180.0);
    pc = cos(atan2(1.0, sqrt(2.0)));
    ps = sin(atan2(1.0, sqrt(2.0)));
    vck(view_line(d, 1, o, &nv) && nv == 4, "  画面は四本（アイソメに補助線は無い）");
    {
        double dx = x1 - cxm, dy = y1 - y1;
        double xr = dx * c + dy * s, yr = dy * c - dx * s;

        vck(veq(o[0], xr) && veq(o[1], (100 - cz) * pc + yr * ps), "  高さの線の始点の写し");
    }
    jw_cmd_bar(d, 1084);                    /* ０，０: 正面の立面 */
    view_line(d, 1, o, &nv);
    vck(veq(o[0], x1 - cxm) && veq(o[1], 50.0) && veq(o[2], x2 - cxm) && veq(o[3], 50.0),
        "  ０，０ で正面（x は真ん中から、y は 高さ − 50）");
    jw_cmd_bar(d, 1125);                    /* 上: 見下ろし +5° */
    jw_d25_knobs(k);
    vck(veq(k[5], 5.0), "  上 (1125) で 見下ろし 5°");
    jw_cmd_bar(d, 1129);
    jw_d25_knobs(k);
    vck(veq(k[0], -45.0) && veq(k[5], atan2(1.0, sqrt(2.0)) * 180.0 / 3.14159265358979323846),
        "  等角 (1129) で戻る");
    vck(strstr(jw_cmd_prompt(), " -45.000(\xdf)  35.264(\xdf)") != 0, "  状況の行");
    jw_cmd_bar(d, 1121);
    vck(jw_d25_mode() == 0 && jw_cmd_bar_check(9017) == 0, "≪ (1121) で平面へ");

    /* 透視図: A-2 の 短辺 420 → (int)(84)×10 = 840、焦点 420、目の高さ 2000/100、距離 -840 */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_mode() == 1 && jw_cmd_bar_check(9016) == 1, "透視図 (1064) で 段 1");
    app_paint();
    vck(fbsum() != plan_sum, "  画面は透視の絵");
    jw_d25_knobs(k);
    vck(veq(k[0], -45) && veq(k[1], 20) && veq(k[2], -840), "  初めの つまみ");
    vck(strstr(jw_cmd_prompt(), " -45.000(\x81\x8b)  2.0(m)   -84.0(m)") != 0, "  状況の行");
    vck(view_line(d, 1, o, &nv) && nv == 6, "  四本と補助線二本");
    {
        double dx = x1 - cxm, xr = dx * c, yr = -dx * s, dd = yr + 840.0;

        vck(veq(o[0], xr * 420.0 / dd) && veq(o[1], (100.0 - 20.0) * 420.0 / dd),
            "  高さの線の始点の写し (f/奥行)");
    }
    jw_cmd_point(d, app_view(), 10.0, 0.0, 0);     /* 視点を横へ 10 */
    {
        double o2[4];
        double dx = x1 - cxm, xr = dx * c, yr = -dx * s, dd = yr + 840.0;

        view_line(d, 1, o2, &nv);
        vck(veq(o2[0], (xr - 10.0) * 420.0 / dd), "  (L) で視点が横へ");
    }
    jw_cmd_bar(d, 1123);
    jw_cmd_bar(d, 1127);
    jw_cmd_bar(d, 1125);
    jw_d25_knobs(k);
    vck(veq(k[0], -50) && veq(k[2], -740) && veq(k[1], 120),
        "  左 −5°・前 +10 m・上 +10 m（図寸 100）");
    jw_cmd_bar(d, 1084);
    jw_d25_knobs(k);
    vck(veq(k[0], -45) && veq(k[1], 20) && veq(k[2], -840), "  初期値 (1084)");
    /* 作図: 写した四本を書込みレイヤへ、一手で戻る */
    nd = d->ndrawn;
    jw_cmd_bar(d, 1122);
    vck(d->ndrawn == nd + 4 && jw_d25_mode() == 0, "作図 (1122) で四本、平面へ");
    jw_cmd_undo(d);
    vck(d->ndrawn == nd, "  戻る で四本とも消える");
    /* 作図に Ctrl（FUN_006194a0 の間引き、逆コンパイルの読み）: 図面に 同じ端の線（向きは
       逆でも）が あれば 書かない。先に 一本目の写しを 逆向きで 図面に置いておく */
    {
        int g, ol = -1, lyr_ok;
        double o1[4];
        jw_obj *pre;

        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_SEN) {
                ol = d->obj[i].layer;
                break;
            }
        jw_d25_forget();
        jw_cmd_bar(d, 1064);
        vck(view_line(d, 0, o1, &nv), "Ctrl 作図の用意");
        pre = jw_add(d, JW_SEN);
        pre->d[0] = o1[2]; pre->d[1] = o1[3]; pre->d[2] = o1[0]; pre->d[3] = o1[1];
        jw_d25_keymods(0, 1);
        jw_cmd_bar(d, 1122);
        vck(d->ndrawn == nd + 1 + 3, "Ctrl 作図は 同じ端の線を 書かない（四本のうち一本）");
        d->ndrawn = d->nobj = nd;
        jw_d25_keymods(1, 1);           /* Shift も押せば 間引かない・元のレイヤ */
        for (g = 0; g < 16; g++)
            if (d->group[g].state == 3)
                d->group[g].write_layer = (unsigned char)((ol + 1) & 15);
        jw_d25_forget();
        jw_cmd_bar(d, 1064);
        jw_cmd_bar(d, 1122);
        for (i = nd, lyr_ok = 1; i < d->ndrawn; i++)
            lyr_ok &= d->obj[i].layer == ol;
        vck(d->ndrawn == nd + 4 && lyr_ok, "  Shift+Ctrl は 間引かず 元の線のレイヤへ");
        d->ndrawn = d->nobj = nd;
        jw_d25_keymods(0, 0);
        jw_d25_forget();
        jw_cmd_bar(d, 1064);
        jw_cmd_bar(d, 1122);
        for (i = nd, lyr_ok = 1; i < d->ndrawn; i++)
            lyr_ok &= d->obj[i].layer == ((ol + 1) & 15);
        vck(d->ndrawn == nd + 4 && lyr_ok, "  押さなければ 間引かず 書込みレイヤへ");
    }
    d->ndrawn = d->nobj = nd;           /* 写した線を捨てる */
    jw_d25_keymods(0, 0);
    /* 視点を立体の向こうへ: 写らない */
    jw_cmd_bar(d, 1064);
    for (i = 0; i < 30; i++)
        jw_cmd_bar(d, 1127);
    view_line(d, 0, o, &nv);
    vck(nv == 2, "視点の後ろの線は描かない（補助線だけ）");
    nd = d->ndrawn;
    jw_cmd_bar(d, 1122);
    vck(d->ndrawn == nd && jw_cmd_notice_id() == 5384,"  作図しても足さず「作図されない部分があります」");
    jw_cmd_bar(d, 1064);
    jw_cmd_bar(d, 1084);
    vck(jw_cmd_back(d) == 1 && jw_d25_mode() == 0, "戻る で平面へ");

    /* 鳥瞰図: 高さ 840・距離 -840 → 見下ろし 45° */
    jw_cmd_bar(d, 1065);
    jw_d25_knobs(k);
    vck(jw_d25_mode() == 2 && veq(k[3], 840) && veq(k[4], -840), "鳥瞰図 (1065) の つまみ");
    view_line(d, 1, o, &nv);
    {
        double dx = x1 - cxm, xr = dx * c, yr = -dx * s, q = sqrt(0.5);
        double ey = -840 * q - 840 * q, ez = 840 * q - 840 * q;
        double yy = yr * q - 100 * q, zz = 100 * q + yr * q, dd = yy - ey;

        vck(veq(o[0], xr * 420.0 / dd) && veq(o[1], (zz - ez) * 420.0 / dd),
            "  高さの線の始点の写し（見下ろして）");
    }
    jw_cmd_bar(d, 1121);

    /* レイヤ名 #lv5 で 底上げ 5 m（図寸 50） */
    base_off = jw_add_str(d, "#lv5");
    d->group[0].layer_name[0] = base_off;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_line(0, p) && veq(p[2], 50) && jw_d25_line(1, p) && veq(p[2], 150),
        "#lv5 のレイヤは 50 上がる");
    jw_cmd_bar(d, 1121);
    d->group[0].layer_name[0] = -1;
    app_command(32771);
    vck(jw_d25_mode() == 0, "命令を替えると平面へ");
    printf("%-4s views\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* 原典の答えの 線の数（2.5D の 作図 (1122) が図面に足した線）。原典で測った:
   円に「3g」「3,0」「3,0,30g」を 2.5D の高さ・奥行の箱 (1491) に打って L で円を押し、
   透視図 (1064) → 作図 (1122)（tools/mprobe.sh）。「3g」は 552、「3,0,30g」は 132 */
static int count_sen(const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    jw_drawing a;
    int i, k = 0;

    if (!b || !jw_parse(&a, b, n))
        return -1;
    free(b);
    for (i = 0; i < a.ndrawn; i++)
        if (a.obj[i].cls == JW_SEN)
            k++;
    return k;
}

/* ---- 円弧の立体（FUN_0061e030）と 矢印キー（slot 37〜42）。逆コンパイルの読み、
   原典では押していない ---- */
static jw_obj *add_arc(jw_drawing *d, double cx, double cy, double r, double a0, double sw,
                       int full)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = a0;
    o->d[4] = sw;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    o->n = full;
    return o;
}

static void add_text(jw_drawing *d, double x, double y, const char *s)
{
    jw_obj *t = jw_add(d, JW_MOJI);

    t->d[0] = x;
    t->d[1] = y;
    t->d[2] = x + 10;
    t->d[3] = y;
    t->d[4] = 2.5;
    t->d[5] = 2.5;
    t->text = jw_add_str(d, s);
}

/* 画面の絵（補助線を除く）を one に */
static int view_all(const jw_drawing *d, jw_drawing *one)
{
    *one = *d;
    one->obj = 0;
    one->nobj = one->ndrawn = one->cobj = 0;
    return jw_d25_view(d, one);
}

/* 楕円の上にあるか: 中心からの差を 傾きで戻して (u/r)²+(v/rf)² */
static int on_ell(const jw_obj *e, double x, double y)
{
    double dx = x - e->d[0], dy = y - e->d[1], c = cos(e->d[5]), s = sin(e->d[5]);
    double u = dx * c + dy * s, v = -dx * s + dy * c, r = e->d[2], b = e->d[2] * e->d[6];

    return fabs(u * u / (r * r) + v * v / (b * b) - 1.0) < 1e-6;
}

static void ell_pt(const jw_obj *e, double a, double *x, double *y)
{
    double c = cos(e->d[5]), s = sin(e->d[5]), u = e->d[2] * cos(a), v = e->d[2] * e->d[6] * sin(a);

    *x = e->d[0] + u * c - v * s;
    *y = e->d[1] + u * s + v * c;
}

static int arcs(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d, one;
    double p[6], k[6], c5 = cos(5.0 * 3.14159265358979323846 / 180.0);
    double s5 = sin(5.0 * 3.14159265358979323846 / 180.0);
    int i, nv, nd, ne, ok;

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();
    add_arc(d, 1000, 1000, 50, 0, 2 * 3.14159265358979323846, 1);

    /* 文字の無い円: 数 0 で 刻み 5°、z 0 の輪 72 本 */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 72 && jw_d25_nell() == 0, "文字の無い円は 5° 刻みの輪 72 本");
    vck(jw_d25_line(0, p) && veq(p[0], 1050) && veq(p[1], 1000) && veq(p[2], 0)
        && veq(p[3], 1000 + 50 * c5) && veq(p[4], 1000 + 50 * s5) && veq(p[5], 0),
        "  一本目は 0° から 5° へ");
    jw_cmd_bar(d, 1121);

    /* 「3 , 0」: 高さ 30・奥行 0、刻み 15° で 24 刻み → 下の輪・上の輪・縦の線 */
    add_text(d, 1000, 1000, "3 , 0");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 72, "「3 , 0」の円は 24×3 本");
    vck(jw_d25_line(0, p) && veq(p[2], 30) && veq(p[5], 30), "  高さの輪 (z 30)");
    vck(jw_d25_line(1, p) && veq(p[2], 0) && veq(p[5], 0), "  奥行の輪 (z 0)");
    vck(jw_d25_line(2, p) && veq(p[0], p[3]) && veq(p[1], p[4]) && veq(p[2], 30) && veq(p[5], 0)
        && veq(p[0], 1000 + 50 * cos(15.0 * 3.14159265358979323846 / 180.0)),
        "  縦の線は 15° に");
    jw_cmd_bar(d, 1121);

    /* アイソメ: 輪は楕円二つ、縦の線 24 本 */
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nell() == 2 && jw_d25_nline() == 24, "アイソメでは 楕円二つと縦の線 24 本");
    nv = view_all(d, &one);
    vck(nv == 26 && one.obj[0].cls == JW_ENKO && one.obj[1].cls == JW_ENKO
        && one.obj[0].n == 1, "  画面は 弧二つと線 24 本");
    ok = 1;
    for (i = 2; i < one.ndrawn; i++)
        if (!on_ell(&one.obj[0], one.obj[i].d[0], one.obj[i].d[1])
            || !on_ell(&one.obj[1], one.obj[i].d[2], one.obj[i].d[3]))
            ok = 0;
    vck(ok, "  縦の線の端は 写した楕円の上");
    free(one.obj);
    jw_cmd_bar(d, 1121);

    /* 四分の一の弧（0° から 90°）: 縦の線は 始めの一本と 6 刻み */
    d->obj[d->ndrawn - 2].n = 0;
    d->obj[d->ndrawn - 2].d[4] = 3.14159265358979323846 / 2;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nell() == 2 && jw_d25_nline() == 7, "四分の一の弧は 縦の線 7 本");
    nv = view_all(d, &one);
    if (nv == 9) {
        double sx, sy, ex, ey;
        const jw_obj *e = &one.obj[0], *v0 = &one.obj[2], *v6 = &one.obj[8];

        ell_pt(e, e->d[3], &sx, &sy);
        ell_pt(e, e->d[3] + e->d[4], &ex, &ey);
        vck((veq(sx, v0->d[0]) && veq(sy, v0->d[1]) && veq(ex, v6->d[0]) && veq(ey, v6->d[1]))
            || (veq(ex, v0->d[0]) && veq(ey, v0->d[1]) && veq(sx, v6->d[0])
                && veq(sy, v6->d[1])),
            "  弧の両端は 始めと終わりの縦の線の下");
    } else
        vck(0, "  画面は 弧二つと線 7 本");
    free(one.obj);
    nd = d->ndrawn;
    jw_cmd_bar(d, 1122);
    for (i = nd, ne = 0; i < d->ndrawn; i++)
        ne += d->obj[i].cls == JW_ENKO;
    vck(d->ndrawn == nd + 9 && ne == 2, "  作図で 弧二つと線七本");
    jw_cmd_undo(d);

    /* 刻みを負に「3,0,-30」: 輪は描かず 縦の線だけ（30° 刻みで 3 と始め） */
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0,-30");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 4 && jw_d25_nell() == 0, "刻み −30 は 縦の線 4 本だけ");

    /* 末尾 g の球「3,0,30g」（FUN_00620ef0・FUN_0061af10）: 刻み 30°、輪 A 6 本・輪 B 5 本 */
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0,30g");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 132 && jw_d25_nell() == 0
        && count_sen("decomp/res/d25_sphere_3_0_30g.jww") == 132,
        "球は 輪 11 本の 12 刻み = 線 132 本（原典の答えも 132）");
    {
        const double c30 = cos(30.0 * 3.14159265358979323846 / 180.0);

        vck(jw_d25_line(0, p) && veq(p[0], 1050) && veq(p[1], 1000) && veq(p[2], 30)
            && veq(p[3], 1000 + 50 * c30) && veq(p[4], 1025) && veq(p[5], 30),
            "  輪 A の一本目 (a=0): xy 平面の輪、高さ 30");
        vck(jw_d25_line(72, p) && veq(p[0], 1000 + 50 * c30) && veq(p[1], 1000)
            && veq(p[2], 30 + 25),
            "  輪 B は a=30 から: x = R cos a、始めの点は 高さ + R K sin a");
    }
    /* 数が足りない「3g」「3,0g」: 刻みは 0 のまま球へ渡り 15°（5 ではない）= 輪 12+11 本の 24 刻み */
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3g");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 552 && count_sen("decomp/res/d25_sphere_3g.jww") == 552,
        "「3g」の球: 刻み 15°（線 552 本。原典の答えも 552）");
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0g");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 552, "「3,0g」の球: 刻み 15°");
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0,30g");
    jw_cmd_bar(d, 1064);
    jw_cmd_bar(d, 1121);
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nell() == 11 && jw_d25_nline() == 0, "  アイソメでは 楕円 11 個");
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0,-30");
    jw_cmd_bar(d, 1064);

    /* 矢印キー: 立体の画面では 2.5D の視点（← 回転 −5°、↑ 前へ 10 m） */
    app_paint();
    jw_d25_knobs(k);
    vck(app_arrow_key(0x25) == 1, "← を 2.5D が受ける");
    vck(app_arrow_key(0x26) == 1, "↑ を 2.5D が受ける");
    {
        double k2[6];

        jw_d25_knobs(k2);
        vck(veq(k2[0], k[0] - 5.0) && veq(k2[2], k[2] + 100.0), "  回転 −5°・距離 +10 m（図寸 100）");
    }
    vck(app_arrow_key(0x21) == 1, "PageUp は 上へ");
    {
        double k3[6];

        jw_d25_knobs(k3);
        vck(veq(k3[1], k[1] + 100.0), "  高さ +10 m");
    }
    jw_cmd_bar(d, 1121);
    vck(jw_d25_mode() == 0, "≪ で平面へ");
    printf("%-4s arcs\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* ---- ソリッドの面（FUN_00615f90・FUN_0043f7a0）。逆コンパイルの読み、原典では
   押していない ---- */
static int faces(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d, one;
    jw_obj *so;
    double pc = cos(atan2(1.0, sqrt(2.0)));
    int i, ok, nd, ns, lh_off;

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();
    so = jw_add(d, JW_SOLID);
    so->d[0] = 2000; so->d[1] = 2000;
    so->d[2] = 2100; so->d[3] = 2000;
    so->d[4] = 2100; so->d[5] = 2100;
    so->d[6] = 2000; so->d[7] = 2100;
    so->color = 3;

    /* 文字が無ければ z 0 の面一つ */
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1 && jw_d25_nline() == 0, "文字の無いソリッドは 面一つ");
    jw_cmd_bar(d, 1121);
    /* 四隅に「3 , 0」: 高さ 30 と 奥行 0 の二面 */
    add_text(d, 2000, 2000, "3,0");
    add_text(d, 2100, 2000, "3,0");
    add_text(d, 2100, 2100, "3,0");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "三隅だけでは 一面");
    jw_cmd_bar(d, 1121);
    add_text(d, 2000, 2100, "3,0");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 2, "四隅とも二つで 二面");
    view_all(d, &one);
    ok = one.ndrawn == 2 && one.obj[0].cls == JW_SOLID && one.obj[1].cls == JW_SOLID
         && one.obj[0].color == 3;
    for (i = 0; ok && i < 4; i++)
        if (!veq(one.obj[0].d[2 * i], one.obj[1].d[2 * i])
            || !veq(one.obj[0].d[2 * i + 1] - one.obj[1].d[2 * i + 1], 30 * pc))
            ok = 0;
    vck(ok, "  アイソメの面は 高さの面が 30·cos 上");
    free(one.obj);
    jw_cmd_bar(d, 1121);
    /* 透視図と作図: 塗りのソリッド二つ */
    jw_cmd_bar(d, 1064);
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    vck(ns == 2, "透視図でも 面二つ");
    free(one.obj);
    nd = d->ndrawn;
    jw_cmd_bar(d, 1122);
    vck(d->ndrawn == nd + 2 && d->obj[nd].cls == JW_SOLID && d->obj[nd].color == 3,
        "  作図で ソリッド二つ（色はもとのソリッド）");
    jw_cmd_undo(d);
    /* 視点を面の中へ: 奥行 1 で切られて 一部だけ */
    jw_cmd_bar(d, 1064);
    for (i = 0; i < 9; i++)
        jw_cmd_bar(d, 1127);
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    vck(ns >= 1, "  視点が近くても 見える所は描く");
    free(one.obj);
    jw_cmd_bar(d, 1121);
    /* 文字を隅から退けて #lh4: 高さ 40 と 0 の二面 */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].d[0] >= 2000 && d->obj[i].d[0] < 3000)
            d->obj[i].d[1] += 10000;
    lh_off = jw_add_str(d, "#lh4");
    d->group[so->lgroup].layer_name[so->layer] = lh_off;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 2, "#lh4 のレイヤは 二面");
    jw_cmd_bar(d, 1121);
    d->group[so->lgroup].layer_name[so->layer] = -1;
    printf("%-4s faces\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* ---- 2554「DXF出力」（src/dxf.c の jw_d25_dxf_write）。原典を動かして
 * 確かめることができず（2.5D の DXF サンプルが decomp/res に一つも無い）、
 * ここは バイト一致ではなく「jw_d25_face3・jw_d25_dxf_write が このまま
 * 実装している式どおりに動く」ことだけを固定する――出典は src/dxf.c の
 * jw_d25_dxf_write の長い注（CData3DSolid::WriteDxf = FUN_00441c10,
 * decomp/byclass/CData3DSolid.c:85-131、四隅を 10/20/30.. 13/23/33 で
 * 書くところだけ確認できた）と src/d25view.c の d25_face.p3 の注。 ---- */
static void lines_after(const char *s, char out[][40], int maxlines)
{
    int i;

    for (i = 0; i < maxlines; i++) {
        const char *e = s ? strstr(s, "\r\n") : 0;
        int len;

        if (!e) {
            out[i][0] = 0;
            continue;
        }
        len = (int)(e - s);
        if (len > 39)
            len = 39;
        memcpy(out[i], s, (size_t)len);
        out[i][len] = 0;
        s = e + 2;
    }
}

static void press_bar25(int id)
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
    vck(0, "その釦がバーに無い");
}

static int dxf25(void)
{
    long n, m;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    unsigned char *out = 0;
    jw_drawing *d;
    jw_obj *so;
    double p3[12], hw, hh, s;
    int ltype, color, layer, lgroup, i, ok;
    char lines[30][40];
    const char *p3df;

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();
    so = jw_add(d, JW_SOLID);
    so->d[0] = 2000; so->d[1] = 2000;
    so->d[2] = 2100; so->d[3] = 2000;
    so->d[4] = 2100; so->d[5] = 2100;
    so->d[6] = 2000; so->d[7] = 2100;
    so->color = 3;
    jw_cmd_bar(d, 1066);                /* アイソメへ（build() が 立体を組む） */
    vck(jw_d25_nface() == 1, "文字の無いソリッドは 面一つ");

    /* jw_d25_face3: 射影前の四隅は ソリッドの d[] そのまま、高さ 0 */
    ok = jw_d25_face3(0, p3) != 0;
    for (i = 0; ok && i < 4; i++) {
        ok = fabs(p3[3 * i + 0] - so->d[2 * i]) < 1e-9
             && fabs(p3[3 * i + 1] - so->d[2 * i + 1]) < 1e-9
             && fabs(p3[3 * i + 2]) < 1e-9;
    }
    vck(ok, "  jw_d25_face3 は 射影前の生の座標（z は 0）");
    ok = jw_d25_face_meta(0, &ltype, &color, &layer, &lgroup) != 0;
    vck(ok && color == 3 && layer == so->layer && lgroup == so->lgroup,
        "  jw_d25_face_meta は 色・層・レイヤ・グループをそのまま返す");

    /* jw_d25_dxf_write: 3DFACE が一つ、四隅は (x+半紙)×層の縮尺 */
    vck(jw_d25_dxf_write(d, &out, &m) != 0, "jw_d25_dxf_write は 書ける");
    p3df = out ? strstr((const char *)out, "3DFACE") : 0;
    vck(p3df != 0, "  3DFACE が出る");
    hw = d->paper_hw;
    hh = d->paper_hh;
    s = lgroup >= 0 && lgroup < 16 && d->group[lgroup].scale > 0.0
        ? d->group[lgroup].scale : 1.0;
    if (p3df) {
        lines_after(p3df + strlen("3DFACE\r\n"), lines, 30);
        ok = 1;
        for (i = 0; i < 4; i++) {
            double ex = (p3[3 * i + 0] + hw) * s;
            double ey = (p3[3 * i + 1] + hh) * s;
            double ez = p3[3 * i + 2] * s;
            double gx = atof(lines[6 + 6 * i + 1]);
            double gy = atof(lines[6 + 6 * i + 3]);
            double gz = atof(lines[6 + 6 * i + 5]);

            if (fabs(gx - ex) > 1e-6 || fabs(gy - ey) > 1e-6 || fabs(gz - ez) > 1e-6)
                ok = 0;
        }
        vck(ok, "  四隅は (座標＋半紙)×層の縮尺（z は 半紙を足さず 縮尺だけ）");
    }
    free(out);

    /* 2554 の釦: app_press がバーで横取りして JW_ACT_SAVE_DXF25D を立てる */
    press_bar25(2554);
    vck(app_take_action() == JW_ACT_SAVE_DXF25D, "DXF出力 の釦は JW_ACT_SAVE_DXF25D");
    out = 0;
    vck(app_save_dxf25d(&out, &m) != 0 && out && strstr((const char *)out, "3DFACE") != 0,
        "  app_save_dxf25d も 3DFACE を書く");
    free(out);

    jw_cmd_bar(d, 1121);                /* ≪ で平面へ */
    printf("%-4s dxf25\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* ---- 勾配の文字 t T d D（FUN_00613c10・FUN_0061c770）。逆コンパイルの読み、
   原典では押していない ---- */
static int grads(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d;
    jw_obj *o;
    double p[6], el, c45 = cos(45.0 * 3.14159265358979323846 / 180.0) * 10.0;
    int i, ok;

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN);
    o->d[0] = 1000; o->d[1] = 1000;
    o->d[2] = 2000; o->d[3] = 1000;
    o->color = 2;
    o->ltype = 1;

    /* 始点「0,2,2,90,0T」・終点「1,2,2,90,0t」: 幅 20 の 四角（刻み 90°、45° ずらし）の筒、
       高さ 0 → 10。真ん中の線・刻みごとの線 4・始点の辺 4 */
    add_text(d, 1000, 1000, "0,2,2,90,0T");
    add_text(d, 2000, 1000, "1,2,2,90,0t");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 9, "勾配の筒は 真ん中の線・刻みの線 4・始点の辺 4 の 9 本");
    vck(jw_d25_line(0, p) && veq(p[0], 1000) && veq(p[1], 1000) && veq(p[2], 0)
        && veq(p[3], 2000) && veq(p[4], 1000) && veq(p[5], 10), "  真ん中の線 (z 0 → 10)");
    el = sqrt(1000.0 * 1000.0 + 100.0);
    ok = jw_d25_line(1, p);
    /* 45°: 断面の (7.07, 7.07) を 勾配の面に立てて 線の上へ */
    vck(ok && veq(p[0], 1000 - 10.0 / el * c45) && veq(p[1], 1000 + c45)
        && veq(p[2], c45 * 1000.0 / el)
        && veq(p[3], 2000 - 10.0 / el * c45) && veq(p[4], 1000 + c45)
        && veq(p[5], 10 + c45 * 1000.0 / el), "  45° の刻みの線は 勾配の面に立つ");
    if (vfail)
        for (i = 0; jw_d25_line(i, p); i++)
            printf("    3D %d: (%.4f,%.4f,%.4f)-(%.4f,%.4f,%.4f)\n", i, p[0], p[1], p[2], p[3],
                   p[4], p[5]);
    jw_cmd_bar(d, 1121);

    /* 「0,1,1,0D」を両端に: 一辺 10 の四角の筒（d D は幅を √2 倍、刻み 90°）。両端の辺 */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].d[1] == 1000
            && (d->obj[i].d[0] == 1000 || d->obj[i].d[0] == 2000))
            d->obj[i].d[1] += 10000;
    add_text(d, 1000, 1000, "0,1,1,0D");
    add_text(d, 2000, 1000, "0,1,1,0D");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 13, "「D」を両端に: 1 + 4 + 4 + 4 本");
    ok = 1;
    for (i = 1; jw_d25_line(i, p); i++)
        if (!(veq(fabs(p[1] - 1000), 5) && veq(fabs(p[2]), 5) && veq(fabs(p[4] - 1000), 5)
              && veq(fabs(p[5]), 5)))
            ok = 0;
    vck(ok, "  隅は どれも (±5, ±5)");
    jw_cmd_bar(d, 1121);

    /* 幅が両端とも 0 なら 筒にしない（ふつうの線へ） */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].d[1] == 1000
            && (d->obj[i].d[0] == 1000 || d->obj[i].d[0] == 2000))
            d->obj[i].d[1] += 10000;
    add_text(d, 1000, 1000, "3,0,0t");
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() >= 1 && jw_d25_line(0, p) && !veq(p[0], p[3]), "幅 0 の t は筒にしない");
    jw_cmd_bar(d, 1121);
    printf("%-4s grads\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* ---- 勾配の補助線（FUN_006129c0・FUN_006109b0）。逆コンパイルの読み、原典では押していない ---- */
static jw_obj *add_sen(jw_drawing *d, double x1, double y1, double x2, double y2, int col, int lt)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x1;
    o->d[1] = y1;
    o->d[2] = x2;
    o->d[3] = y2;
    o->color = col;
    o->ltype = lt;
    return o;
}

static int line_is(int i, double x1, double y1, double z1, double x2, double y2, double z2)
{
    double p[6];

    return jw_d25_line(i, p) && veq(p[0], x1) && veq(p[1], y1) && veq(p[2], z1) && veq(p[3], x2)
        && veq(p[4], y2) && veq(p[5], z2);
}

static void dump_lines(void)
{
    double p[6];
    int i;

    for (i = 0; jw_d25_line(i, p); i++)
        printf("    3D %d: (%.4f,%.4f,%.4f)-(%.4f,%.4f,%.4f)\n", i, p[0], p[1], p[2], p[3], p[4],
               p[5]);
}

static int gslope(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d;
    jw_obj *r, *c6;

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();

    /* 色 5・線種 9 の線 (0,0)→(1000,0): 起点 (0,0)・角 0。左下は 線の端の最小 (1000,1000)。
       立面の (x, y) を 横 = x − 1000、高さ = y − 1000 に起こす */
    r = add_sen(d, 0, 0, 1000, 0, 5, 9);
    add_sen(d, 1000, 1000, 2000, 1000, 2, 1);
    add_sen(d, 1000, 1500, 1000, 2000, 2, 1);
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nline() == 2, "色 5 の補助線そのものは組まない（2 本）");
    vck(line_is(0, 0, 0, 0, 1000, 0, 0), "  横の線は 地面に");
    vck(line_is(1, 0, 0, 500, 0, 0, 1000), "  縦の線は 高さに起きる");
    jw_cmd_bar(d, 1121);

    /* 補助線を (0,0)→(0,−1000) に: x が 0 なので y 正にそろえ 起点は終点 (0,−1000)・角 90° */
    r->d[2] = 0;
    r->d[3] = -1000;
    jw_cmd_bar(d, 1064);
    vck(line_is(0, 0, -1000, 0, 0, 0, 0), "向きを y 正にそろえ 起点は終点・角 90°");
    jw_cmd_bar(d, 1121);

    /* 色 5 の点があれば 起点はその点、点に遠い端へ向ける */
    {
        jw_obj *t = jw_add(d, JW_TEN);

        t->d[0] = 900;
        t->d[1] = -1000;
        t->color = 5;
        r->d[2] = 1000;     /* (0,0)→(1000,−1000)、点は終点に近い → 向きを逆に (−1000, 1000) */
        jw_cmd_bar(d, 1064);
        vck(line_is(0, 900, -1000, 0, 900 - 1000.0 / sqrt(2.0), -1000 + 1000.0 / sqrt(2.0), 0),
            "色 5 の点は起点、点に遠い端へ（135°）");
        jw_cmd_bar(d, 1121);
        t->color = 2;
        r->d[2] = 1000;
        r->d[3] = 0;
    }

    /* 色 6・線種 9 の線 (1000,1000)→(1100,1100): 45°。y6 より上は 奥へ (Y − y6)·cot 45° 寄る */
    c6 = add_sen(d, 1000, 1000, 1100, 1100, 6, 9);
    jw_cmd_bar(d, 1064);
    vck(line_is(0, 0, 0, 0, 1000, 0, 0), "  y6 の高さの線は 寄らない");
    vck(line_is(1, 0, 500, 500, 0, 1000, 1000), "色 6 の 45° の線で 高さの分だけ奥へ");
    if (vfail)
        dump_lines();
    jw_cmd_bar(d, 1121);

    /* グループ名 #k: どの色でも線種 9 の線が補助線、#k では 寄せず、点を補助線の向きに戻す */
    c6->ltype = 1;          /* #k では どの色の線種 9 も補助線になるので 色 6 の線は外す */
    c6->d[0] = c6->d[2] = 5000;
    c6->d[1] = c6->d[3] = 5000;
    d->group[r->lgroup].name = jw_add_str(d, "#k");
    r->d[0] = 0;
    r->d[1] = 0;
    r->d[2] = 0;
    r->d[3] = 1000;         /* 角 90°: 立面の (x,y) を 線に沿う u = y、高さ = −x */
    r->color = 3;
    jw_cmd_bar(d, 1064);
    vck(line_is(0, 0, 1000, -1000, 0, 1000, -2000), "#k は 補助線の座標に戻して起こす");
    if (vfail)
        dump_lines();
    jw_cmd_bar(d, 1121);
    printf("%-4s gslope\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* ---- 円ソリッド（FUN_0060e6d0）・壁のソリッド（FUN_00438f50）・#lh の後ろの旗（+0x89e0）・
   面の +0x5d（FUN_0061bc30）。逆コンパイルの読み、原典では押していない ---- */
static jw_obj *add_sol(jw_drawing *d, double x1, double y1, double x2, double y2, double x3,
                       double y3, double x4, double y4)
{
    jw_obj *so = jw_add(d, JW_SOLID);

    so->d[0] = x1; so->d[1] = y1;
    so->d[2] = x2; so->d[3] = y2;
    so->d[4] = x3; so->d[5] = y3;
    so->d[6] = x4; so->d[7] = y4;
    so->color = 3;
    return so;
}

static jw_obj *add_csol(jw_drawing *d, int lt, double cx, double cy, double r, double a0,
                        double sw, double d7)
{
    jw_obj *so = jw_add(d, JW_SOLID);

    so->d[0] = cx; so->d[1] = cy;
    so->d[2] = r; so->d[3] = 1.0;
    so->d[4] = 0.0; so->d[5] = a0;
    so->d[6] = sw; so->d[7] = d7;
    so->ltype = lt;
    so->color = 3;
    return so;
}

static int csolids(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d, one;
    jw_obj *so, *t;
    int i, ns, lh_off, nd;

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();

    /* 壁: p3 p4 が p1p2 の線の上。両端の字に 数が二つ以上なら 一面（高さ・奥行を 一面に） */
    so = add_sol(d, 2000, 2000, 2100, 2000, 2100, 2000, 2000, 2000);
    add_text(d, 2000, 2000, "3,1");
    add_text(d, 2100, 2000, "3,1");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "壁は 一面");
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    vck(ns == 1, "  壁は アイソメで 塗りのソリッド一つ");
    free(one.obj);
    jw_cmd_bar(d, 1121);
    /* 文字が無ければ 壁は 高さ 0 の 面一つ（四隅が 二点に重なる） */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI)
            d->obj[i].d[1] += 10000;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "  字なしの壁も 一面");
    jw_cmd_bar(d, 1121);

    /* #lh の後ろの v h: v は 高さの面だけ、h は 奥行の面だけ。後ろの字が無ければ 二面 */
    so->d[4] = 2100; so->d[5] = 2100; so->d[6] = 2000; so->d[7] = 2100;
    lh_off = jw_add_str(d, "#lh4");
    d->group[so->lgroup].layer_name[so->layer] = lh_off;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 2, "#lh4 は 二面");
    jw_cmd_bar(d, 1121);
    lh_off = jw_add_str(d, "#lh4v");
    d->group[so->lgroup].layer_name[so->layer] = lh_off;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "#lh4v は 高さの面だけ");
    jw_cmd_bar(d, 1121);
    lh_off = jw_add_str(d, "#lh4H");
    d->group[so->lgroup].layer_name[so->layer] = lh_off;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "#lh4H は 奥行の面だけ");
    jw_cmd_bar(d, 1121);
    lh_off = jw_add_str(d, "#lh0v");
    d->group[so->lgroup].layer_name[so->layer] = lh_off;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "#lh0（一面）では 旗は 0");
    jw_cmd_bar(d, 1121);
    d->group[so->lgroup].layer_name[so->layer] = -1;

    /* 四隅の字の末尾 v: 二面あるのに 高さの面だけ */
    d->nobj = d->ndrawn = 0;
    so = add_sol(d, 2000, 2000, 2100, 2000, 2100, 2100, 2000, 2100);
    add_text(d, 2000, 2000, "3,0v");
    add_text(d, 2100, 2000, "3,0");
    add_text(d, 2100, 2100, "3,0");
    add_text(d, 2000, 2100, "3,0");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 1, "隅の字の v で 高さの面だけ");
    jw_cmd_bar(d, 1121);

    /* 面の +0x5d: 四隅の並びが 8 の字（外積の向きが替わる）なら 手前で切らずに 捨てる */
    d->nobj = d->ndrawn = 0;
    so = add_sol(d, 2000, 2000, 2100, 2000, 2000, 2100, 2100, 2100);
    add_text(d, 2000, 2000, "3,0");
    add_text(d, 2100, 2000, "3,0");
    add_text(d, 2000, 2100, "3,0");
    add_text(d, 2100, 2100, "3,0");
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    for (i = 0; i < 9; i++)
        jw_cmd_bar(d, 1127);
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    vck(ns == 0, "8 の字の面は 視点が近いと 切らずに 捨てる");
    free(one.obj);
    jw_cmd_bar(d, 1121);
    d->nobj = d->ndrawn = 0;
    so = add_sol(d, 2000, 2000, 2100, 2000, 2100, 2100, 2000, 2100);
    add_text(d, 2000, 2000, "3,0");
    add_text(d, 2100, 2000, "3,0");
    add_text(d, 2100, 2100, "3,0");
    add_text(d, 2000, 2100, "3,0");
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    for (i = 0; i < 9; i++)
        jw_cmd_bar(d, 1127);
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    vck(ns >= 1, "  回りの順なら 切って描く");
    free(one.obj);
    jw_cmd_bar(d, 1121);

    /* 円ソリッド（全円、字 3,0）: アイソメは 楕円二つ、透視図は 面（一周 24 刻み × 二段） */
    d->nobj = d->ndrawn = 0;
    so = add_csol(d, 101, 2000, 2000, 50, 0.0, 2.0 * 3.14159265358979323846, 5.0);
    add_text(d, 2000, 2000, "3,0");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nell() == 2 && jw_d25_nface() == 0, "円ソリッドは アイソメで 楕円二つ");
    jw_cmd_bar(d, 1121);
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 48 && jw_d25_nell() == 0, "  透視図では 面 24 × 2");
    jw_cmd_bar(d, 1121);
    /* 一段（字 3）なら 面 24 */
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3");
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 72, "  字 3 は 一段（刻み 5）");
    jw_cmd_bar(d, 1121);
    /* 字 3,0v の旗: アイソメで 一段目だけ */
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0h");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nell() == 1, "  3,0h は アイソメで 奥行の楕円だけ");
    jw_cmd_bar(d, 1121);
    /* 扇（90°）: 6 刻み。弓形（d7=5）も 6、円外側（d7=-1）も 6 */
    so->d[6] = 3.14159265358979323846 / 2.0;
    so->d[7] = 0.0;
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0");
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 12, "  扇は 6 刻み × 二段");
    jw_cmd_bar(d, 1121);
    so->d[7] = 5.0;
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 12, "  弓形も 6 刻み × 二段");
    jw_cmd_bar(d, 1121);
    so->d[7] = -1.0;
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 12, "  円外側も 6 刻み × 二段");
    jw_cmd_bar(d, 1121);
    /* 輪郭の壁（線種 111、字 3,0）: アイソメでも 面（24 の帯）。刻みが負なら 裏を落とす */
    so->ltype = 111;
    so->d[6] = 2.0 * 3.14159265358979323846;
    so->d[7] = 5.0;
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0");
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 24 && jw_d25_nell() == 0, "  輪郭の円ソリッドは 帯 24");
    jw_cmd_bar(d, 1121);
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    nd = ns;
    free(one.obj);
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0,-15");
    jw_d25_forget();                    /* 視点の初めの値を 忘れて 同じ所から */
    jw_cmd_bar(d, 1064);
    view_all(d, &one);
    for (i = ns = 0; i < one.ndrawn; i++)
        ns += one.obj[i].cls == JW_SOLID;
    free(one.obj);
    jw_cmd_bar(d, 1121);
    vck(ns < nd && ns > 0, "  刻みが負なら 裏の面を落とす");
    /* 輪（線種 105、内側の半径は 8 つ目の値、FUN_0042ebf0・FUN_00437050。逆コンパイルの読み） */
    d->nobj = d->ndrawn = 0;
    so = add_csol(d, 105, 2000, 2000, 50, 0.0, 2.0 * 3.14159265358979323846, 20.0);
    add_text(d, 2000, 2000, "3,0");
    jw_d25_forget();
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 48, "輪 105 は 透視図で 帯 24 × 二段");
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3");
    jw_d25_forget();
    jw_cmd_bar(d, 1064);
    vck(jw_d25_nface() == 72, "  字 3 は 一段 24 帯（刻み 5）");
    jw_cmd_bar(d, 1121);
    d->obj[d->ndrawn - 1].text = jw_add_str(d, "3,0");
    jw_cmd_bar(d, 1066);
    /* 2026-10-18: nell()==2 は 一段目・二段目（字 "3,0" で L==2）の 2 個で、原典
     * FUN_00619710（decomp/decomp/all_005c7556.c 36764-37044 行目）が 同じ 1 個の
     * circle-solid に対し 一段目・二段目で 2 回だけ呼ばれる（内側・外側の対では
     * ない）構造と一致する。FUN_00619710 の全文を読んだが、輪の内側楕円の
     * 中心・半径・扁平を計算する式はその中には無く（ltype 105/106 の種別タグを
     * 付け替えるだけ）、どこで内側を描くかは未特定のまま。port が外側だけを
     * 描く現状の実装を否定する材料も、内側を具体的に置く式も、decompから
     * 見つからなかった（src/d25view.c の one_csolid コメント参照）。 */
    vck(jw_d25_nell() == 2 && jw_d25_nface() == 0, "  扁平 1 の輪は アイソメで 楕円（外側だけ）");
    jw_cmd_bar(d, 1121);
    so->d[3] = 0.5;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 48 && jw_d25_nell() == 0, "  扁平 0.5 の輪は アイソメでも 面");
    jw_cmd_bar(d, 1121);
    so->ltype = 106;
    jw_cmd_bar(d, 1066);
    vck(jw_d25_nface() == 48, "  106 も 面");
    jw_cmd_bar(d, 1121);
    (void)t;
    printf("%-4s csolids\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

/* ---- 円ソリッドの勾配の面（cs_face、FUN_0060e6d0 の 0x6096xx.. の FUN_006109b0 二回）。
 * 逆コンパイルの読み（decomp/decomp/all_00599e67.c 55198-55827 行目を全文読んだ。
 * 55696-55699 行目 `FUN_006109b0(local_49c,local_504,1,local_3d4,uStack_3d0);
 * FUN_006109b0(local_34c,local_504,1,local_3d4,uStack_3d0);` の param_1 は 一見
 * local_49c[46]・local_34c[46] という小さい領域に見えるが、スタック上のオフセットを
 * 引くと local_49c−0x68=local_434、−0x70=local_42c、−0x78=local_424、−0x80=local_41c、
 * −0x88=local_414、−0x90=local_40c に ちょうど一致し（同様に local_34c−0x68=local_2e4
 * … −0x90=local_2bc）、FUN_006109b0（=port の gx_xf、+0x68.. +0x90 の 二点 6 個の
 * doubleを 書き換える）が直前（55640-55655・55656-55695 行目）に組んだ 面の四隅
 * （局所変数名の小ささは Ghidra が 隣の変数の宣言までの隙間しか見せていないだけ）を
 * 直接 書き換えていると確定した。param_3（has4）は 常に 1 固定（リテラル）、param_4
 * （local_3d4, uStack_3d0）は 直前の FUN_0043acd0 呼び出し（55402-55407 行目）で
 * 円ソリッドの中心と 文字の位置を 比べるのに使われている値と同じ変数で、円ソリッド
 * 自身の中心 Y（o->d[1]）である——これは port の `cs_face` が すでに
 * `gx_xf(o, &f.p[0][0], fl, 1, o->d[1], -1)` と 書いている内容と 完全に一致する。
 * fl（旗、local_4bc）は 55408-55418 行目の `local_6a8c`（中心の 文字の末尾 v/h 種別、
 * port の tk）から、v のとき 3（1|2）・h のとき 0xf（1|2|4|8）と 組まれ、これも
 * port の `fl = tk==0?0:tk==2?0xf:3` と 一致する。したがって「弧（CDataEnko・一本の
 * 線）と同じ旗・has4」という これまでの読みは 推測ではなく この式の突き合わせで
 * 確定した。ここでは 点が 補助線の y6 より下でも（lean の最初の判定が 偽でも）
 * has4 により 円の中心 Y が y6 以上なら 傾ける、という has4 が実際に 効く場面
 * （さもなければ Z は 動かない）を 具体的な数で 確かめる。 */
static int cs_slope(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    jw_drawing *d;
    double p[12], cx = 1000.0, r = 50.0, a0 = -30.0 * 3.14159265358979323846 / 180.0, sw = 15.0 * 3.14159265358979323846 / 180.0;
    double ca = cos(30.0 * 3.14159265358979323846 / 180.0), sa = sin(30.0 * 3.14159265358979323846 / 180.0);
    double cb = cos(15.0 * 3.14159265358979323846 / 180.0), sb = sin(15.0 * 3.14159265358979323846 / 180.0);
    double ax, ay, bx, by, z0 = -30.0;      /* z0: 高さ 30（字「3,0」）の −z（gx_xf の Z1・Z2 の初め） */

    vfail = 0;
    if (!b)
        return 1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    app_command(32937);
    d = (jw_drawing *)app_drawing();

    add_sen(d, 0, 0, 1000, 0, 5, 9);       /* 色 5・線種 9: 起点 (0,0)・角 0（左下は 既定 0,0） */
    add_sen(d, 0, 0, 1, 1, 6, 9);          /* 色 6・線種 9: 角 45°、起点 (0,0) */
    /* 円ソリッド（線種 111 の輪郭、cy=0）の弧 −30°〜−15°: 点の Y（= −25 〜 −12.94）は
       どちらも y6（=0）未満だが、円の中心 Y（o->d[1]=0）は y6 以上 → has4 が無ければ
       傾かない。半径 50・字「3,0」で 高さ 30・奥行 0 */
    add_csol(d, 111, cx, 0.0, r, a0, sw, 5.0);
    add_text(d, cx, 0.0, "3,0");
    jw_cmd_bar(d, 1064);
    ax = cx + r * ca;
    ay = -r * sa;                           /* sin(−30°) = −sin(30°) */
    bx = cx + r * cb;
    by = -r * sb;                           /* sin(−15°) = −sin(15°) */
    vck(jw_d25_nface() == 1, "輪郭の円ソリッドは 弧 1 刻みで 面 1 つ");
    vck(jw_d25_face(0, p) != 0, "  面が取れる");
    /* gx_xf: 上段（z=30）の 点 1・2 の新しい (x,y,z) = (旧 x, (旧y−y6)·cot45°+z0, 旧y)。
       cot45° = 1・y6 = 0 なので 新しい y 成分 = 旧y + z0（z0 = −30） */
    vck(veq(p[0], ax) && veq(p[1], ay + z0) && veq(p[2], ay),
        "  隅 1（上段 A）は has4 により 中心基準で 傾く");
    vck(veq(p[3], bx) && veq(p[4], by + z0) && veq(p[5], by), "  隅 2（上段 B）も 同様に傾く");
    vck(veq(p[6], bx) && veq(p[7], by) && veq(p[8], by), "  隅 3（下段 B、z=0）は 旧y・旧y のまま");
    vck(veq(p[9], ax) && veq(p[10], ay) && veq(p[11], ay), "  隅 4（下段 A、z=0）も 同様");
    jw_cmd_bar(d, 1121);
    printf("%-4s cs_slope\n", vfail ? "BAD" : "ok");
    return vfail != 0;
}

int main(void)
{
    int bad = run(32937, "decomp/res/p197_h1.jww", "2.5D");

    bad += views();
    bad += arcs();
    bad += faces();
    bad += dxf25();
    bad += grads();
    bad += gslope();
    bad += csolids();
    bad += cs_slope();

    bad += run(32943, "decomp/res/p198_k1.jww", "hikage");
    bad += run(32971, "decomp/res/p198_t1.jww", "tenku");
    printf(bad ? "SOME BAD\n" : "all ok\n");
    return bad != 0;
}
