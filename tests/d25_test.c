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

int main(void)
{
    int bad = run(32937, "decomp/res/p197_h1.jww", "2.5D");

    bad += views();

    bad += run(32943, "decomp/res/p198_k1.jww", "hikage");
    bad += run(32971, "decomp/res/p198_t1.jww", "tenku");
    printf(bad ? "SOME BAD\n" : "all ok\n");
    return bad != 0;
}
