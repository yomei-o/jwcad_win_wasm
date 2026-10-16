/* 画面の (L) 二つが (LL) になるか -- 表側（ネイティブもブラウザも）は
 * ダブルクリックを別に送らず、app_press を同じ所へ二度呼ぶだけです。
 * app.c がそれを jw_cmd_point_ll に直すのは ２線（tests/workflow_test.c）
 * のほかに、文字 の 連 の 移動（LL) と 曲線 の スプラインの 連結する線・
 * 弧指示（LL)。どちらも同じ手順を jw_cmd_point / jw_cmd_point_ll で直に
 * 踏んだ図面と、要素が一つ残らず同じになることを見ます。
 *
 *   tests/dblclick_test.exe
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static jw_drawing *fresh(void)
{
    app_resize(1264, 741);
    app_new();
    app_fit();
    return (jw_drawing *)app_drawing();
}

static double mx(int x) { const jw_view *v = app_view(); return v->ox + (x - v->bx) / v->scale; }
static double my(int y) { const jw_view *v = app_view(); return v->oy + (v->by - y) / v->scale; }

static void click(int x, int y)
{
    app_move(x, y);
    app_press(x, y, 0);
    app_release(x, y, 0);
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

/* the elements a run left behind, kept to set against the other run */
static jw_obj kept[64];
static char kept_text[64][32];
static int nkept;

static void keep(const jw_drawing *d)
{
    int i;

    nkept = 0;
    for (i = 0; i < d->ndrawn && nkept < 64; i++, nkept++) {
        kept[nkept] = d->obj[i];
        kept_text[nkept][0] = 0;
        if (d->obj[i].cls == JW_MOJI)
            snprintf(kept_text[nkept], sizeof kept_text[0], "%s", jw_str(d, d->obj[i].text));
    }
}

static int same(const jw_drawing *d)
{
    int i, k;

    if (d->ndrawn != nkept)
        return 0;
    for (i = 0; i < nkept; i++) {
        if (d->obj[i].cls != kept[i].cls)
            return 0;
        for (k = 0; k < 4; k++)
            if (fabs(d->obj[i].d[k] - kept[i].d[k]) > 1e-9)
                return 0;
        if (d->obj[i].cls == JW_MOJI
            && strcmp(jw_str(d, d->obj[i].text), kept_text[i]) != 0)
            return 0;
    }
    return 1;
}

/* 文字を二つ（AB を (400,300)、CD を (400,400)）置いて 連 を入れる */
static jw_drawing *two_texts(void)
{
    jw_drawing *d = fresh();

    app_command(JW_CMD_MOJI);
    jw_cmd_moji_base(2);
    app_key('A');
    app_key('B');
    jw_cmd_point(d, app_view(), mx(400), my(300), 0);
    app_key('C');
    app_key('D');
    jw_cmd_point(d, app_view(), mx(400), my(400), 0);
    jw_cmd_bar(d, 1068);
    return d;
}

static void ren(void)
{
    jw_drawing *d;
    int n;

    printf("文字 の 連 の 移動（LL):\n");
    d = two_texts();
    ck(strcmp(jw_cmd_prompt(), JW_STR_5473) == 0, "  連 が入る（5473）");
    app_move(405, 300);
    jw_cmd_point_ll(d, app_view(), mx(405), my(300));
    ck(strcmp(jw_cmd_prompt(), JW_STR_5311) == 0, "  直の (LL) で 移動先 を問う（5311）");
    app_move(700, 500);
    jw_cmd_point(d, app_view(), mx(700), my(500), 0);
    keep(d);
    n = nkept;

    d = two_texts();
    app_move(405, 300);
    app_press(405, 300, 0);
    app_release(405, 300, 0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5474) == 0, "  画面の一つ目は普通の (L)（字を拾う）");
    app_press(405, 300, 0);
    app_release(405, 300, 0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5311) == 0, "  同じ所の二つ目で (LL) に（5311）");
    click(700, 500);
    ck(n > 0 && same(d), "  直に踏んだのと同じ図面");

    printf("文字 の 連 の 連結（L) は今までどおり:\n");
    d = two_texts();
    jw_cmd_point(d, app_view(), mx(405), my(300), 0);
    jw_cmd_point(d, app_view(), mx(405), my(400), 0);
    keep(d);
    d = two_texts();
    click(405, 300);
    click(405, 400);
    ck(same(d), "  離れた二つの (L) は (LL) にならない");
}

/* 線を一本、(600,350) を通るように */
static jw_drawing *one_line(void)
{
    jw_drawing *d = fresh();
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = mx(600) - 40.0;
    o->d[1] = my(350) - 25.0;
    o->d[2] = mx(600) + 40.0;
    o->d[3] = my(350) + 25.0;
    app_command(JW_CMD_KYOKUSEN);
    type_box(1411, "4");
    return d;
}

static void curve(void)
{
    jw_drawing *d;
    int before;

    printf("曲線 の 連結する線・弧指示（LL):\n");
    d = one_line();
    ck(jw_cmd_bar_radio(1691) == 1, "  スプライン（1691）で入る");
    before = d->ndrawn;
    app_move(300, 300);
    jw_cmd_point(d, app_view(), mx(300), my(300), 0);
    app_move(450, 200);
    jw_cmd_point(d, app_view(), mx(450), my(200), 0);
    app_move(600, 350);
    jw_cmd_point_ll(d, app_view(), mx(600), my(350));
    jw_cmd_bar(d, 1800);
    ck(d->ndrawn > before, "  直に踏むと曲線が出る");
    keep(d);

    d = one_line();
    click(300, 300);
    click(450, 200);
    click(600, 350);
    app_press(600, 350, 0);
    app_release(600, 350, 0);
    jw_cmd_bar(d, 1800);
    ck(same(d), "  画面の (L) 二つで同じ曲線（線に連結）");

    printf("曲線 の 普通の (L) は今までどおり:\n");
    d = one_line();
    app_move(300, 300);
    jw_cmd_point(d, app_view(), mx(300), my(300), 0);
    app_move(450, 200);
    jw_cmd_point(d, app_view(), mx(450), my(200), 0);
    app_move(600, 350);
    jw_cmd_point(d, app_view(), mx(600), my(350), 0);
    jw_cmd_bar(d, 1800);
    keep(d);
    d = one_line();
    click(300, 300);
    click(450, 200);
    click(600, 350);
    jw_cmd_bar(d, 1800);
    ck(same(d), "  一つずつの (L) は直に渡したのと同じ");
}

/* コピー・切り取りは表側に クリップボードへ を頼む（JW_ACT_CLIP_PUT） */
static void clip(void)
{
    jw_drawing *d;

    printf("コピー・切り取りのあと:\n");
    d = fresh();
    app_take_action();
    ck(app_command(57634) == 0 && app_take_action() == JW_ACT_NONE,
       "  何も選んでいなければ頼まない");
    {
        jw_obj *o = jw_add(d, JW_SEN);

        o->d[0] = mx(300);
        o->d[1] = my(300);
        o->d[2] = mx(500);
        o->d[3] = my(300);
    }
    app_command(JW_CMD_HANI);
    click(250, 250);
    click(550, 350);
    ck(app_command(57634) && app_take_action() == JW_ACT_CLIP_PUT,
       "  選んでいれば JW_ACT_CLIP_PUT");
}

/* (LL)(RR) 範囲枠交差線選択（案内 5762）: 箱 (250,250)-(550,350) の中の線 A、
   枠を横切る線 B（両端とも外）、片端だけ中の線 C、外の線 D */
static jw_drawing *four_lines(int cmd)
{
    jw_drawing *d = fresh();
    static const int xy[4][4] = {
        { 300, 300, 500, 300 },         /* A 中 */
        { 200, 320, 600, 320 },         /* B 両端外で横切る */
        { 400, 330, 700, 330 },         /* C 片端だけ中 */
        { 200, 450, 600, 450 },         /* D 外 */
    };
    int i;

    for (i = 0; i < 4; i++) {
        jw_obj *o = jw_add(d, JW_SEN);

        o->d[0] = mx(xy[i][0]);
        o->d[1] = my(xy[i][1]);
        o->d[2] = mx(xy[i][2]);
        o->d[3] = my(xy[i][3]);
    }
    app_command(cmd);
    return d;
}

static int picked(const jw_drawing *d, int a, int b, int c, int e)
{
    return d->obj[0].sel == a && d->obj[1].sel == b && d->obj[2].sel == c
        && d->obj[3].sel == e;
}

static void cross(void)
{
    jw_drawing *d;

    printf("範囲選択 の (LL)(RR) 範囲枠交差線選択:\n");
    d = four_lines(JW_CMD_HANI);
    click(250, 250);
    click(550, 350);
    ck(picked(d, 1, 0, 0, 0), "  (L) で閉じると中の線だけ");
    d = four_lines(JW_CMD_HANI);
    click(250, 250);
    click(550, 350);
    app_press(550, 350, 0);
    app_release(550, 350, 0);
    ck(picked(d, 1, 1, 1, 0), "  (LL) で枠と交わる線も");
    d = four_lines(JW_CMD_HANI);
    click(250, 250);
    app_move(550, 350);
    app_press(550, 350, 1);
    app_release(550, 350, 1);
    ck(picked(d, 1, 0, 0, 0), "  (R) で閉じると中の線だけ");
    app_press(550, 350, 1);
    app_release(550, 350, 1);
    ck(picked(d, 1, 1, 1, 0), "  動かずに二度目の (R) で (RR)");
    d = four_lines(JW_CMD_HANI);
    click(250, 250);
    app_move(550, 350);
    app_press(550, 350, 1);
    app_release(550, 350, 1);
    app_move(300, 300);
    app_press(300, 300, 1);
    app_release(300, 300, 1);
    ck(!d->obj[1].sel && !d->obj[2].sel, "  動いてからの (R) は (RR) でない");
    d = four_lines(JW_CMD_FUKUSHA);
    click(250, 250);
    click(550, 350);
    app_press(550, 350, 0);
    app_release(550, 350, 0);
    ck(picked(d, 1, 1, 1, 0), "  複写 でも (LL)");
}

/* 範囲枠交差の 線より先の型（FUN_0040ab00 の枝）: 同じ箱 (250,250)-(550,350)。
   円弧 FUN_0040b360（-1 丸ごと内・3 枠と交わる・0）、四角のソリッド
   FUN_0040eb50（角が一つでも内）、寸法図形 FUN_0040f2a0（寸法線で丸ごと） */
static jw_obj *add_arc(jw_drawing *d, int cx, int cy, int rpx, double st,
                       double sw, double tilt, double flat)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    o->d[0] = mx(cx);
    o->d[1] = my(cy);
    o->d[2] = mx(cx + rpx) - mx(cx);
    o->d[3] = st;
    o->d[4] = sw;
    o->d[5] = tilt;
    o->d[6] = flat;
    return o;
}

static jw_obj *add_solid(jw_drawing *d, const int *xy)
{
    jw_obj *o = jw_add(d, JW_SOLID);
    int k;

    for (k = 0; k < 4; k++) {
        o->d[2 * k] = mx(xy[2 * k]);
        o->d[2 * k + 1] = my(xy[2 * k + 1]);
    }
    return o;
}

static void add_sunpou(jw_drawing *d)
{
    static const int seg[3][4] = {
        { 500, 320, 600, 320 },         /* 1 寸法線: 枠の右の辺を横切る */
        { 500, 400, 500, 420 },         /* 3・4 引出し線: 外 */
        { 600, 400, 600, 420 },
    };
    int k;

    for (k = 0; k < 8; k++) {
        jw_obj *o = jw_add(d, k == 1 ? JW_MOJI : k >= 4 ? JW_TEN : JW_SEN);
        const int *s = seg[k == 0 ? 0 : k == 2 ? 1 : 2];

        o->sub = (unsigned char)(k + 1);
        if (k == 1) {                   /* 2 値: 外 */
            o->d[0] = mx(540);
            o->d[1] = my(200);
            o->d[2] = mx(580);
            o->d[3] = my(200);
        } else if (k >= 4) {            /* 5〜8 点: 外 */
            o->d[0] = mx(600 + k);
            o->d[1] = my(420);
        } else {
            o->d[0] = mx(s[0]);
            o->d[1] = my(s[1]);
            o->d[2] = mx(s[2]);
            o->d[3] = my(s[3]);
        }
    }
}

static void cross_types(void)
{
    static const int s_in[8] = { 530, 330, 600, 330, 600, 380, 530, 380 };
    static const int s_edge[8] = { 520, 200, 540, 200, 540, 400, 520, 400 };
    static const char *what[] = {
        "円（中）", "円（枠の右の辺を横切る）", "円弧（円は横切るが弧は外）",
        "円弧（弧は中、円は下の辺を横切る）", "楕円（扁平 0.5 で横切る）",
        "楕円（傾き 90° で外、傾けなければ届く）", "円（箱を囲む）",
        "ソリッド（角が一つ中）", "ソリッド（辺が横切るだけ）",
    };
    /* (L) で閉じたとき・(LL) のとき に選ばれるか */
    static const int want_l[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0 };
    static const int want_ll[] = { 1, 1, 0, 1, 1, 0, 0, 1, 0 };
    int pass, i;

    printf("範囲枠交差の 円弧・楕円・ソリッド・寸法図形:\n");
    for (pass = 0; pass < 2; pass++) {
        jw_drawing *d = fresh();
        int ok = 1, sun = 1;

        add_arc(d, 400, 300, 40, 0.0, 2 * M_PI, 0.0, 1.0);
        add_arc(d, 550, 300, 30, 0.0, 2 * M_PI, 0.0, 1.0);
        add_arc(d, 550, 300, 30, -M_PI / 3, 2 * M_PI / 3, 0.0, 1.0);
        add_arc(d, 300, 340, 30, 0.0, M_PI, 0.0, 1.0);
        add_arc(d, 560, 300, 30, 0.0, 2 * M_PI, 0.0, 0.5);
        add_arc(d, 580, 300, 40, 0.0, 2 * M_PI, M_PI / 2, 0.3);
        add_arc(d, 400, 300, 400, 0.0, 2 * M_PI, 0.0, 1.0);
        add_solid(d, s_in);
        add_solid(d, s_edge);
        add_sunpou(d);
        app_command(JW_CMD_HANI);
        click(250, 250);
        click(550, 350);
        if (pass) {
            app_press(550, 350, 0);
            app_release(550, 350, 0);
        }
        for (i = 0; i < 9; i++)
            if (d->obj[i].sel != (pass ? want_ll : want_l)[i]) {
                printf("     %s が %s\n", what[i], d->obj[i].sel ? "選ばれた" : "選ばれない");
                ok = 0;
            }
        for (i = 9; i < 17; i++)
            if (d->obj[i].sel != pass)
                sun = 0;
        ck(ok, pass ? "  (LL): 枠と交わる円・円弧・楕円、角が中のソリッド"
                    : "  (L): 丸ごと中のものだけ");
        ck(sun, pass ? "  (LL): 寸法線が横切る寸法図形は部品ごと（値の字も）"
                     : "  (L): 寸法線が横切る寸法図形は選ばない");
    }
}

/* 日影図・２．５D の (LL) 高さ消去（案内 5524・5519）: 線の端の高さの字 */
static int height_texts(const jw_drawing *d)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && (d->obj[i].flags & 0x8080))
            n++;
    return n;
}

static void height(int cmd, const char *name)
{
    jw_drawing *d;
    jw_obj *o;

    printf("%s の (LL) 高さ消去:\n", name);
    d = fresh();
    o = jw_add(d, JW_SEN);
    o->d[0] = mx(300);
    o->d[1] = my(300);
    o->d[2] = mx(600);
    o->d[3] = my(300);
    app_command(cmd);
    click(302, 300);
    ck(height_texts(d) == 1, "  (L) で端に高さの字");
    click(306, 300);                    /* 2 画素より離す（同じ所なら (LL)） */
    ck(height_texts(d) == 1, "  同じ端の (L) は置き換え");
    click(598, 300);
    ck(height_texts(d) == 2, "  もう一方の端にも");
    click(302, 300);
    app_press(302, 300, 0);
    app_release(302, 300, 0);
    ck(height_texts(d) == 1, "  (LL) でその端の字が無くなる");
    jw_cmd_undo(d);
    ck(height_texts(d) == 2, "  戻す で (LL) が消した字が戻る");
}

int main(void)
{
    ren();
    curve();
    clip();
    cross();
    cross_types();
    height(JW_CMD_HIKAGE, "日影図");
    height(JW_CMD_25D, "２．５D");
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails != 0;
}
