/* 使う人が決めたこと（2026-10-16 夕）の三つ:
 *
 *   Tab            属性取得。基本設定 KEY 1325「直接属性取得を行う」が入なら
 *                  命令に入らず その場でマウスの下の要素から取る
 *   2493           線コマンドの指定寸法値を保持する。線 に入り直すと 傾き は毎回空、
 *                  寸法 は 切なら空・入なら前の値
 *   2447           新規でレイヤ初期化。切（既定）なら新規で前の図面のレイヤの
 *                  状態・書込レイヤ・名前を持ち越す、入なら雛形のまま
 *
 * どれも逆コンパイルの読み（src/app.c の app_key・kh_apply、src/cmd.c の
 * jw_cmd_set の注）で、原典では押していない。ここで確かめるのは 移植がその
 * 読みどおりに動くことだけ。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void px(double mx, double my, int *x, int *y)
{
    const jw_view *v = app_view();

    *x = (int)floor(v->bx + (mx - v->ox) * v->scale + 0.5);
    *y = (int)floor(v->by - (my - v->oy) * v->scale + 0.5);
}

static int hit(int want)
{
    const fb_t *fb = app_fb();
    int x, y;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == want) {
                app_press(x, y, 0);
                return 1;
            }
    return 0;
}

static int kh_press(int tab, int id)
{
    if (!app_kihon_open())
        app_command(32891);
    if (!app_kihon_open())
        return 0;
    if (app_kihon_tab() != tab && !hit(-tab - 1))
        return 0;
    return hit(id);
}

static void kh_ok(void)
{
    if (app_kihon_open())
        hit(1);
}

static jw_obj *addline(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    return o;
}

static void tab_test(void)
{
    jw_drawing *d;
    jw_obj *o;
    int x, y;

    app_new();
    d = (jw_drawing *)app_drawing();
    o = addline(d, -50.0, 20.0, 50.0, 20.0);
    o->ltype = 6;
    o->color = 3;
    o->lgroup = 0;
    o->layer = 5;
    d->ndrawn = d->nobj;
    app_fit();

    /* 1325 切（既定）: Tab は 属性取得 の釦と同じ（命令に入る） */
    app_command(JW_CMD_SEN);
    ck(app_key(9) == 1 && jw_cmd() == JW_CMD_ZOKUSEI, "Tab で 属性取得 に入る（1325 切）");
    px(0.0, 20.0, &x, &y);
    app_press(x, y, 0);
    ck(d->write_ltype == 6 && d->write_color == 3 && d->group[0].write_layer == 5,
       "  続くクリックで線の線種・線色・レイヤを取る");

    /* 1325 入: 命令はそのまま、マウスの下の要素から すぐ取る */
    ck(kh_press(6, 1325), "KEY の 直接属性取得を行う を押す");
    kh_ok();
    o->ltype = 2;
    o->color = 5;
    o->layer = 9;
    d->write_ltype = 1;
    d->write_color = 1;
    app_command(JW_CMD_SEN);
    px(0.0, 20.0, &x, &y);
    app_move(x, y);
    ck(app_key(9) == 1 && jw_cmd() == JW_CMD_SEN, "  Tab で命令は 線 のまま（1325 入）");
    ck(d->write_ltype == 2 && d->write_color == 5 && d->group[0].write_layer == 9,
       "  マウスの下の線の属性をその場で取る");
    px(0.0, -80.0, &x, &y);
    app_move(x, y);
    d->write_ltype = 1;
    app_key(9);
    ck(d->write_ltype == 1 && jw_cmd() == JW_CMD_SEN, "  何も無いところでは何もしない");
    kh_press(6, 1325);
    kh_ok();
    app_command(JW_CMD_SEN);
    app_key(9);
    ck(jw_cmd() == JW_CMD_ZOKUSEI, "  切ればまた 属性取得 に入る");
}

static const char *bx(int id)
{
    const char *t = jw_cmd_box_raw(id);

    return t ? t : "(null)";
}

static void sizekeep_test(void)
{
    app_new();
    app_fit();
    app_command(JW_CMD_ENKO);
    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1411, "30");
    jw_cmd_box_put(1412, "1000");
    ck(!strcmp(bx(1411), "30") && !strcmp(bx(1412), "1000"), "線 の 傾き 30・寸法 1000 を打つ");
    app_command(JW_CMD_SEN);
    ck(!strcmp(bx(1411), "30") && !strcmp(bx(1412), "1000"), "  線 のまま押し直しても残る");
    app_command(JW_CMD_ENKO);
    app_command(JW_CMD_SEN);
    ck(!strcmp(bx(1411), "") && !strcmp(bx(1412), ""),
       "  2493 切（既定）: 円 から 線 に入り直すと 傾き も 寸法 も空");

    ck(kh_press(1, 2493), "一般(2) の 線コマンドの指定寸法値を保持する を押す");
    kh_ok();
    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1411, "45");
    jw_cmd_box_put(1412, "2500");
    app_command(JW_CMD_ENKO);
    app_command(JW_CMD_SEN);
    ck(!strcmp(bx(1411), "") && !strcmp(bx(1412), "2500"),
       "  2493 入: 入り直すと 傾き は空、寸法 は前の値");
    kh_press(1, 2493);
    kh_ok();
    app_command(JW_CMD_ENKO);
    app_command(JW_CMD_SEN);
    ck(!strcmp(bx(1412), ""), "  切ればまた空");
}

static int off_of(jw_drawing *d, const char *s)
{
    return jw_add_str_w(d, s, d->version > 0x275);
}

static void layinit_test(void)
{
    jw_drawing *d;
    jw_group g0[16];
    int g, l, same;

    /* 雛形（初めの新規）の状態を控える。毎回 雛形 から作り直すので初期化と同じ */
    kh_press(0, 2447);                  /* 入にして雛形を作る */
    kh_ok();
    app_new();
    d = (jw_drawing *)app_drawing();
    memcpy(g0, d->group, sizeof g0);

    kh_press(0, 2447);                  /* 切（既定）に戻す */
    kh_ok();
    d->group[0].state = 2;
    d->group[0].layer[0].state = 2;
    d->group[3].state = 3;
    d->group[3].write_layer = 7;
    d->group[3].layer[7].state = 3;
    d->group[3].layer[2].state = 0;
    d->group[5].layer[4].state = 1;
    d->group[3].name = off_of(d, "GRP3");
    d->group[3].layer_name[7] = off_of(d, "KABE");
    d->group[3].layer[1].state2 = 1;    /* 保護 */
    app_new();
    d = (jw_drawing *)app_drawing();
    ck(d->group[3].state == 3 && d->group[0].state == 2 && d->group[3].write_layer == 7
       && d->group[3].layer[7].state == 3 && d->group[3].layer[2].state == 0
       && d->group[5].layer[4].state == 1 && d->group[0].layer[0].state == 2,
       "2447 切（既定）: 新規で前の図面のグループ・レイヤの状態と書込レイヤが残る");
    ck(!strcmp(jw_str(d, d->group[3].name), "GRP3")
       && !strcmp(jw_str(d, d->group[3].layer_name[7]), "KABE"),
       "  名前も残る");
    ck(d->group[3].layer[1].state2 == 0, "  保護は残らない");
    ck(d->nobj == 0, "  要素は無い");

    ck(kh_press(0, 2447), "一般(1) の 新規でレイヤ初期化 を押す");
    kh_ok();
    app_new();
    d = (jw_drawing *)app_drawing();
    same = 1;
    for (g = 0; g < 16; g++) {
        if (d->group[g].state != g0[g].state || d->group[g].write_layer != g0[g].write_layer)
            same = 0;
        for (l = 0; l < 16; l++)
            if (d->group[g].layer[l].state != g0[g].layer[l].state)
                same = 0;
    }
    ck(same && d->group[0].state == 3 && d->group[3].state == 2
       && d->group[0].layer[0].state == 3,
       "  入: 新規で雛形の状態（グループ 0・各レイヤ 0 が書込、ほかは編集可）");
    ck(!*jw_str(d, d->group[3].name) && !*jw_str(d, d->group[3].layer_name[7]),
       "  名前も空");
    kh_press(0, 2447);
    kh_ok();
}

int main(void)
{
    app_resize(1264, 741);
    tab_test();
    sizekeep_test();
    layinit_test();
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails != 0;
}
