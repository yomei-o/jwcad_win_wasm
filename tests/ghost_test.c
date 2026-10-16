/* 複写・移動 の仮表示（jw_cmd_sel_preview）が 置いたときと同じ形か。
 * 倍率・回転・ﾏｳｽ倍率（X・Y 別）・角・数値位置・移動の二度目・画像、と
 * 仮表示を出さない段（反転・ﾏｳｽ倍率／角 の一つ目待ち）。
 *
 *   tests/ghost_test.exe
 *
 * 逆コンパイルの読みで、原典では押していない（答えの .jww は無い）。根拠は
 * src/cmd.c の sel_ghost_xf の注（CZukeiFukusha slot 6 FUN_0064d290、
 * FUN_0064f350・FUN_0064f900・FUN_00653e10）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/image.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
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

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

static jw_drawing *fresh(void)
{
    unsigned char *b;
    long n;

    app_new();
    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        free(b);
        return 0;
    }
    free(b);
    jw_cmd_set_axis(0.0);
    return (jw_drawing *)app_drawing();
}

static jw_obj *add_line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    return o;
}

/* 範囲 (-5,-5)-(15,15) を拾って、基準点 (0,0) で確定 */
static double pick_far = 15.0;

static int pick(jw_drawing *d, int cmd)
{
    jw_cmd_set(cmd);
    jw_cmd_box_put(1411, "");
    jw_cmd_box_put(1412, "");
    jw_cmd_box_put(1413, "");
    jw_cmd_point(d, app_view(), -5.0, -5.0, 0);
    jw_cmd_point(d, app_view(), pick_far, pick_far, pick_far > 15.0);   /* 右は文字も */
    jw_cmd_track(0.0, 0.0);
    return jw_cmd_bar(d, 1120) == 1;
}

static jw_drawing *setup(int cmd)
{
    jw_drawing *d = fresh();

    if (!d)
        return 0;
    add_line(d, 0.0, 0.0, 10.0, 0.0);
    if (!pick(d, cmd)) {
        printf("BAD  選択確定 could not be pressed\n");
        fails++;
        return 0;
    }
    return d;
}

static void pt(jw_drawing *d, double x, double y)
{
    jw_cmd_point(d, app_view(), x, y, 0);
}

static int same_obj(const jw_obj *a, const jw_obj *b)
{
    int k;

    if (a->cls != b->cls)
        return 0;
    for (k = 0; k < 8; k++)
        if (!near(a->d[k], b->d[k]))
            return 0;
    return 1;
}

/* (x, y) で仮表示を取り、そこで置いた最後の要素と比べる */
static void ghost_vs_place(jw_drawing *d, double x, double y, const char *what)
{
    jw_drawing g;
    jw_obj o;
    int ok;

    jw_cmd_track(x, y);
    ok = jw_cmd_sel_preview(d, &g) && g.ndrawn == 1;
    if (ok)
        o = g.obj[0];
    pt(d, x, y);
    ok = ok && same_obj(&o, &d->obj[d->ndrawn - 1]);
    ck(ok, what);
}

static void plain(void)
{
    jw_drawing *d, g;
    double dx, dy, sx, sy, deg;

    printf("複写: 倍率・回転角\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_box_put(1411, "2");
    jw_cmd_box_put(1412, "90");
    jw_cmd_track(100.0, 0.0);
    ck(jw_cmd_sel_ghost_xf(&dx, &dy, &sx, &sy, &deg) && near(dx, 100.0) && near(dy, 0.0)
       && near(sx, 2.0) && near(sy, 2.0) && near(deg, 90.0), "  掛けるもの: ずれ 100・倍率 2・90°");
    ck(jw_cmd_sel_preview(d, &g) && g.ndrawn == 1 && near(g.obj[0].d[0], 100.0)
       && near(g.obj[0].d[1], 0.0) && near(g.obj[0].d[2], 100.0) && near(g.obj[0].d[3], 20.0),
       "  仮表示は (100,0)-(100,20)");
    ghost_vs_place(d, 100.0, 0.0, "  置いたものと同じ");

    printf("複写: 数値位置\n");
    jw_cmd_box_put(1413, "30 , 40");
    jw_cmd_track(500.0, 500.0);
    ck(jw_cmd_sel_preview(d, &g) && g.ndrawn == 1, "  仮表示が出る");
    ghost_vs_place(d, 500.0, 500.0, "  マウスでなく 基準点 + 数値位置 に、置いたものと同じ");

    printf("移動: 二度目も 元の形から\n");
    d = setup(JW_CMD_IDOU);
    if (!d)
        return;
    jw_cmd_box_put(1411, "3");
    pt(d, 50.0, 0.0);
    ghost_vs_place(d, 0.0, 50.0, "  二度目の仮表示 = 二度目に置いたもの");
    ck(near(d->obj[d->ndrawn - 1].d[0], 0.0) && near(d->obj[d->ndrawn - 1].d[1], 50.0)
       && near(d->obj[d->ndrawn - 1].d[2], 30.0), "  (0,50)-(30,50)");
}

static void mouse(void)
{
    jw_drawing *d, g;
    double dx, dy, sx, sy, deg;

    printf("複写: ﾏｳｽ倍率 (1069)\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_bar(d, 1069);
    jw_cmd_track(10.0, 5.0);
    ck(!jw_cmd_sel_preview(d, &g), "  一つ目待ちは 仮表示なし");
    pt(d, 10.0, 5.0);
    jw_cmd_track(100.0, 0.0);
    ck(jw_cmd_sel_preview(d, &g) && near(g.obj[0].d[0], 100.0) && near(g.obj[0].d[2], 110.0),
       "  置く点待ちは 等倍で マウスに");
    pt(d, 100.0, 0.0);
    jw_cmd_track(120.0, 15.0);
    ck(jw_cmd_sel_ghost_xf(&dx, &dy, &sx, &sy, &deg) && near(dx, 100.0) && near(dy, 0.0)
       && near(sx, 2.0) && near(sy, 3.0), "  三つ目待ちは マウスで X 2・Y 3 倍");
    ck(jw_cmd_sel_preview(d, &g) && near(g.obj[0].d[0], 100.0) && near(g.obj[0].d[2], 120.0),
       "  仮表示は (100,0)-(120,0)");
    ghost_vs_place(d, 120.0, 15.0, "  置いたものと同じ");

    printf("複写: ﾏｳｽ倍率 で裏返し（円弧は楕円）\n");
    d = fresh();
    if (!d)
        return;
    {
        jw_obj *c = jw_add(d, JW_ENKO);

        c->d[0] = 5.0;
        c->d[1] = 5.0;
        c->d[2] = 4.0;
        c->d[3] = 0.3;
        c->d[4] = 1.0;
        c->d[5] = 0.0;
        c->d[6] = 1.0;
    }
    pick(d, JW_CMD_FUKUSHA);
    jw_cmd_bar(d, 1069);
    pt(d, 10.0, 10.0);
    pt(d, 50.0, 0.0);
    ghost_vs_place(d, 70.0, -10.0, "  X 2・Y -1 倍の楕円が 置いたものと同じ");

    printf("複写: 角 (1071)\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_box_put(1412, "45");
    jw_cmd_bar(d, 1071);
    jw_cmd_track(0.0, 10.0);
    ck(!jw_cmd_sel_preview(d, &g), "  一つ目待ちは 仮表示なし");
    pt(d, 0.0, 10.0);
    jw_cmd_track(50.0, 0.0);
    ck(jw_cmd_sel_ghost_xf(&dx, &dy, &sx, &sy, &deg) && near(deg, 0.0),
       "  置く点待ちは 回転角の箱 (45) を使わない");
    pt(d, 50.0, 0.0);
    jw_cmd_track(60.0, 0.0);
    ck(jw_cmd_sel_ghost_xf(&dx, &dy, &sx, &sy, &deg) && near(deg, -90.0),
       "  三つ目待ちは マウスの向きで -90°");
    ghost_vs_place(d, 60.0, 0.0, "  置いたものと同じ");

    printf("複写: 反転 (1067) の間\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_bar(d, 1067);
    jw_cmd_track(100.0, 0.0);
    ck(!jw_cmd_sel_preview(d, &g), "  基準線待ちは 仮表示なし（FUN_0064d290 の +0xfd48）");
}

static void picture(void)
{
    jw_drawing *d, g;
    jw_obj *o;
    jw_pic p0, p1;

    printf("複写: 画像の倍率・回転\n");
    d = fresh();
    if (!d)
        return;
    o = jw_add(d, JW_MOJI);
    o->d[0] = 0.0;
    o->d[1] = 0.0;
    o->d[2] = 10.0;
    o->d[3] = 0.0;
    o->d[4] = 3.0;
    o->d[5] = 3.0;
    o->color = 1;
    o->ltype = 1;
    o->text = jw_add_str(d, "^@BMmissing.bmp,10,5,0,0,1,0,255,255,255");
    pick_far = 100000.0;           /* 画像の枠は紙の mm × 縮尺 */
    pick(d, JW_CMD_FUKUSHA);
    pick_far = 15.0;
    jw_cmd_box_put(1411, "2");
    jw_cmd_box_put(1412, "30");
    jw_cmd_track(100.0, 0.0);
    ck(jw_cmd_sel_preview(d, &g) && g.ndrawn == 1 && jw_pic_parse(&g, &g.obj[0], &p0)
       && near(p0.w, 20.0) && near(p0.h, 10.0), "  仮表示の画像は w・h が 2 倍");
    ck(jw_pic_parse(d, &d->obj[d->ndrawn - 1], &p1) && near(p1.w, 10.0),
       "  図面の画像は そのまま（字の置き場は写し）");
    pt(d, 100.0, 0.0);
    ck(jw_pic_parse(d, &d->obj[d->ndrawn - 1], &p1) && near(p1.w, p0.w) && near(p1.h, p0.h)
       && near(p1.d, p0.d) && same_obj(&g.obj[0], &d->obj[d->ndrawn - 1]),
       "  置いた画像と同じ（大きさ・角・位置）");
}

int main(void)
{
    plain();
    mouse();
    picture();
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
