/* 使う人が決めたこと（2026-10-16 夕）の三つ:
 *
 *   Tab            属性取得。基本設定 KEY 1325「直接属性取得を行う」が入なら
 *                  命令に入らず その場でマウスの下の要素から取る
 *   2493           線コマンドの指定寸法値を保持する。線 に入り直すと 傾き は毎回空、
 *                  寸法 は 切なら空・入なら前の値
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

int main(void)
{
    app_resize(1264, 741);
    tab_test();
    sizekeep_test();
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails != 0;
}
