/* AUTO モード (32915) の 端点移動（時計 80 = 0x158c、jw_cmd_auto_endmove・
   au_endmove_release）。逆コンパイルの読み、原典では押していない。

   1. 左の離しで 近い方の端点が 離した点へ動く（既にある au_endmove_release を
      初めて試験で固定する）。
   2. 押した点を線へ寄せる FUN_0045ba00（decomp/decomp/all_00401000.c:48878、
      au_snap_to_line）: 線のすぐ外・pick 許容内を押しても 拾った線自体への
      射影になり、取り込みがそのまま成功する。
   3. 状態 10 の 右の押し（FUN_00631cf0、decomp/decomp/all_005c7556.c:47154-47322）:
      読める点があれば 文書も状態も変えず 取り込むだけ、読める点が無ければ
      札 5324（au_endmove_release の button != 0 の分岐）で、どちらも 状態 10
      のまま（続く左の離しが まだ効くことで確かめる）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

static unsigned char *buf;
static long nbuf;
static rect_t r;
static int fails;
static int wall;                /* 壁の線の番号 */

static void fresh(void)
{
    app_new();
    app_resize(1264, 741);
    app_open(buf, nbuf);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32771);
    app_press(r.x + 300, r.y + 400, 0);     /* 壁 (300,400)→(800,400) */
    app_press(r.x + 800, r.y + 400, 0);
    wall = app_drawing()->ndrawn - 1;
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    app_command(32915);
}

static void press(int x, int y, int b)
{
    app_press(r.x + x, r.y + y, b);
}

/* 画面の点 → 図面の点（app.c の to_paper） */
static void mm(int x, int y, double *mx, double *my)
{
    const jw_view *v = app_view();

    *mx = v->ox + (r.x + x - v->bx) / v->scale;
    *my = v->oy + (v->by - (r.y + y)) / v->scale;
}

static void bad(const char *what)
{
    printf("BAD  %s\n", what);
    fails++;
}

static int nsen(const jw_drawing *d)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN)
            n++;
    return n;
}

/* 時計の 80 番を模す: 画面の点 (x,y) で 端点移動を始める */
static void begin_endmove(int x, int y)
{
    double mx, my;

    mm(x, y, &mx, &my);
    jw_cmd_auto_endmove((jw_drawing *)app_drawing(), app_view(), mx, my);
}

int main(void)
{
    FILE *f = fopen("decomp/res/new.jww", "rb");
    const jw_drawing *d;
    double wx0, wy0, wx1, wy1, tx, ty;

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    nbuf = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (unsigned char *)malloc((size_t)nbuf);
    if (fread(buf, 1, (size_t)nbuf, f) != (size_t)nbuf)
        return 1;
    fclose(f);

    /* 1. 壁の (800,400) 側の端を 押して、別の点へ 離す。終点だけが動く */
    fresh();
    d = app_drawing();
    wx0 = d->obj[wall].d[0];
    wy0 = d->obj[wall].d[1];
    begin_endmove(798, 400);                /* 終点のすぐそば（pick 許容内） */
    press(700, 500, 0);
    mm(700, 500, &tx, &ty);
    d = app_drawing();
    if (nsen(d) != 1)
        bad("端点移動で 線の数が変わった");
    {
        const jw_obj *o = &d->obj[d->ndrawn - 1];

        if (fabs(o->d[0] - wx0) > 1e-6 || fabs(o->d[1] - wy0) > 1e-6
            || fabs(o->d[2] - tx) > 1e-6 || fabs(o->d[3] - ty) > 1e-6) {
            printf("BAD  端点移動 1: (%.3f,%.3f)-(%.3f,%.3f)、期待 (%.3f,%.3f)-(%.3f,%.3f)\n",
                   o->d[0], o->d[1], o->d[2], o->d[3], wx0, wy0, tx, ty);
            fails++;
        }
    }
    if (jw_cmd() != JW_CMD_AUTO)
        bad("端点移動のあと AUTO に戻らない");

    /* 2. 線の少し外（縦に 1 画素）を押しても、拾った線自体への射影
       （au_snap_to_line、FUN_0045ba00）で 取り込みが そのまま成功する */
    fresh();
    d = app_drawing();
    wx1 = d->obj[wall].d[2];
    wy1 = d->obj[wall].d[3];
    begin_endmove(302, 401);                /* 始点のすぐそば、線から 1 画素外 */
    press(250, 350, 0);
    mm(250, 350, &tx, &ty);
    d = app_drawing();
    if (nsen(d) != 1)
        bad("線のすぐ外を押した端点移動が 取り込まれない");
    {
        const jw_obj *o = &d->obj[d->ndrawn - 1];

        if (fabs(o->d[2] - wx1) > 1e-6 || fabs(o->d[3] - wy1) > 1e-6
            || fabs(o->d[0] - tx) > 1e-6 || fabs(o->d[1] - ty) > 1e-6)
            bad("線のすぐ外を押した端点移動の 結果が違う");
    }

    /* 3. 状態 10 の 右の押し・読める点がある（壁の端そのもの）: 文書を変えず、
       状態 10 のまま（続く左の離しが まだ効く） */
    fresh();
    d = app_drawing();
    wx0 = d->obj[wall].d[0];
    wy0 = d->obj[wall].d[1];
    wx1 = d->obj[wall].d[2];
    wy1 = d->obj[wall].d[3];
    begin_endmove(798, 400);
    press(800, 400, 1);                     /* 読める点（終点そのもの）を 右で押す */
    d = app_drawing();
    if (nsen(d) != 1 || fabs(d->obj[d->ndrawn - 1].d[0] - wx0) > 1e-6
        || fabs(d->obj[d->ndrawn - 1].d[2] - wx1) > 1e-6)
        bad("状態10 の 右（読める点）で 文書が変わった");
    if (jw_cmd_notice_id() != 0)
        bad("状態10 の 右（読める点）で 札が出た");
    press(700, 500, 0);                     /* 状態 10 がまだ残っていれば これで動く */
    mm(700, 500, &tx, &ty);
    d = app_drawing();
    {
        const jw_obj *o = &d->obj[d->ndrawn - 1];

        if (nsen(d) != 1 || fabs(o->d[0] - wx0) > 1e-6 || fabs(o->d[1] - wy0) > 1e-6
            || fabs(o->d[2] - tx) > 1e-6 || fabs(o->d[3] - ty) > 1e-6)
            bad("状態10 の 右のあと 左の離しが効かない（状態が消えた）");
    }

    /* 4. 状態 10 の 右の押し・読める点が無い: 札 5324、文書も状態も変えない */
    fresh();
    d = app_drawing();
    wx0 = d->obj[wall].d[0];
    wy0 = d->obj[wall].d[1];
    wx1 = d->obj[wall].d[2];
    wy1 = d->obj[wall].d[3];
    begin_endmove(798, 400);
    press(50, 50, 1);                       /* 何も読めない 空き地 */
    if (jw_cmd_notice_id() != 5324)
        bad("状態10 の 右（読めない）で 札 5324 が出ない");
    d = app_drawing();
    if (nsen(d) != 1 || fabs(d->obj[d->ndrawn - 1].d[0] - wx0) > 1e-6
        || fabs(d->obj[d->ndrawn - 1].d[2] - wx1) > 1e-6)
        bad("状態10 の 右（読めない）で 文書が変わった");
    press(700, 500, 0);
    mm(700, 500, &tx, &ty);
    d = app_drawing();
    {
        const jw_obj *o = &d->obj[d->ndrawn - 1];

        if (nsen(d) != 1 || fabs(o->d[0] - wx0) > 1e-6 || fabs(o->d[1] - wy0) > 1e-6
            || fabs(o->d[2] - tx) > 1e-6 || fabs(o->d[3] - ty) > 1e-6)
            bad("状態10 の 右（読めない）のあと 左の離しが効かない（状態が消えた）");
    }

    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
