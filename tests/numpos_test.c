/* 複写・移動 の二枚目のバー: 数値位置 (1413) と 連続 (1064)。
 *
 *   tests/numpos_test.exe
 *
 * どちらも逆コンパイルの読みで、原典では押していない（答えの .jww は無い）。
 *
 *   数値位置  箱の「x,y」は 実寸 で、書込みグループの縮尺で割ったずれを
 *             基準点に足した所に置く。数が一つなら y も同じ数。Enter
 *             （バーの箱の中でも）で置き、置いたあと箱は "0 , 0" に戻る。
 *             クリックで置くときも箱が 0 でなければ箱が勝つ。
 *   連続      置くまで死んでいて、置くと生きる。複写では 基準点 + n×一歩
 *             （一歩は回数 0 のときに置いたずれ）、倍率 r は 1-(1-r)n。
 *             移動では その場からもう一歩。
 *
 * 根拠は src/cmd.c の sel_numpos・sel_renzoku の注（CFukushaDialog
 * FUN_004ae4a0 / FUN_004adde0、CZukeiFukusha FUN_00652320 / FUN_00651000 /
 * FUN_00653fe0）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

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

static void type_box(int id, const char *v)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        app_key(8);
    for (; *v; v++)
        app_key((unsigned char)*v);
    app_key(13);              /* app を通す: 箱の Enter で置くのは app */
}

static double wscale(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

/* 一本の線 (0,0)-(10,0) を置いて、範囲で拾い、基準点 (0,0) で確定する */
static jw_drawing *setup(int cmd)
{
    unsigned char *b;
    long n;
    jw_drawing *d;
    jw_obj *o;

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        free(b);
        return 0;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN);
    o->d[0] = 0.0;
    o->d[1] = 0.0;
    o->d[2] = 10.0;
    o->d[3] = 0.0;
    jw_cmd_set(cmd);
    type_box(1413, "");
    jw_cmd_point(d, app_view(), -5.0, -5.0, 0);
    jw_cmd_point(d, app_view(), 15.0, 5.0, 0);
    jw_cmd_track(0.0, 0.0);
    if (jw_cmd_bar(d, 1120) != 1) {
        printf("BAD  選択確定 could not be pressed\n");
        fails++;
        return 0;
    }
    return d;
}

static const jw_obj *last(const jw_drawing *d)
{
    return &d->obj[d->ndrawn - 1];
}

int main(void)
{
    jw_drawing *d;
    double s, ox, oy;
    int before;

    printf("複写: 数値位置を Enter で\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return 1;
    s = wscale(d);
    ox = 1000.0 / s;
    oy = 500.0 / s;
    ck(jw_cmd_bar_enabled(d, 1064) == 0, "  連続 は置くまで死んでいる");
    before = d->ndrawn;
    ck(jw_cmd_enter_key(d) == 0 && d->ndrawn == before,
       "  箱が空なら Enter は何も置かない");
    type_box(1413, "1000,500");      /* 箱の Enter でもう置く */
    ck(d->ndrawn == before + 1, "  箱の Enter で一本置いた");
    ck(near(last(d)->d[0], ox) && near(last(d)->d[1], oy)
       && near(last(d)->d[2], 10.0 + ox) && near(last(d)->d[3], oy),
       "  基準点 + 実寸÷縮尺 の所に");
    ck(strcmp(jw_cmd_box(1413), "0 , 0") == 0, "  箱は \"0 , 0\" に戻る");
    ck(jw_cmd_bar_enabled(d, 1064) == 1, "  置いたら 連続 が生きる");
    before = d->ndrawn;
    ck(jw_cmd_enter_key(d) == 0 && d->ndrawn == before,
       "  0 , 0 のままの Enter は何も置かない");

    printf("複写: 連続\n");
    ck(jw_cmd_bar(d, 1064) == 1 && d->ndrawn == before + 1, "  連続 で一本");
    ck(near(last(d)->d[0], 2 * ox) && near(last(d)->d[1], 2 * oy),
       "  二歩目の所に");
    jw_cmd_bar(d, 1064);
    ck(d->ndrawn == before + 2 && near(last(d)->d[0], 3 * ox)
       && near(last(d)->d[1], 3 * oy), "  もう一度で三歩目");
    /* クリックで置いても一歩は変わらない（回数が 1 以上のあいだ） */
    jw_cmd_point(d, app_view(), 7.0, 7.0, 0);
    ck(d->ndrawn == before + 3 && near(last(d)->d[0], 7.0)
       && near(last(d)->d[1], 7.0), "  クリックはクリックの所に");
    jw_cmd_bar(d, 1064);
    ck(d->ndrawn == before + 4 && near(last(d)->d[0], 4 * ox),
       "  そのあとの連続も最初の一歩で数える");

    printf("複写: 数が一つ、クリックより箱\n");
    {
        int k = d->ndrawn;

        type_box(1413, "300");
        ck(d->ndrawn == k + 1 && near(last(d)->d[0], 300.0 / s)
           && near(last(d)->d[1], 300.0 / s), "  \"300\" は (300,300)");
        type_box(1413, "");
        jw_cmd_box_click(1413);
        jw_cmd_box_key('5');
        jw_cmd_box_key('0');
        jw_cmd_box_key(',');
        jw_cmd_box_key('-');
        jw_cmd_box_key('5');
        jw_cmd_box_key('0');
        jw_cmd_box_key(27);             /* Esc: 置かずに箱だけ */
        k = d->ndrawn;
        jw_cmd_point(d, app_view(), 7.0, 7.0, 0);
        ck(d->ndrawn == k + 1 && near(last(d)->d[0], 50.0 / s)
           && near(last(d)->d[1], -50.0 / s), "  クリックでも箱のずれが勝つ");
    }

    printf("複写: 倍率 0.9 の連続\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return 1;
    type_box(1411, "0.9");
    jw_cmd_point(d, app_view(), 0.0, 20.0, 0);
    ck(near(last(d)->d[2], 9.0) && near(last(d)->d[1], 20.0), "  一回目は 0.9 倍");
    jw_cmd_bar(d, 1064);
    ck(near(last(d)->d[0], 0.0) && near(last(d)->d[1], 40.0)
       && near(last(d)->d[2], 8.0), "  二回目は 1-(1-0.9)×2 = 0.8 倍");
    type_box(1411, "");

    printf("移動: 連続はその場からもう一歩\n");
    d = setup(JW_CMD_IDOU);
    if (!d)
        return 1;
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 3.0, 4.0, 0);
    ck(d->ndrawn == before && near(last(d)->d[0], 3.0)
       && near(last(d)->d[1], 4.0), "  一度動いた");
    ck(jw_cmd_bar(d, 1064) == 1, "  連続 が押せる");
    ck(d->ndrawn == before && near(last(d)->d[0], 6.0)
       && near(last(d)->d[1], 8.0) && near(last(d)->d[2], 16.0),
       "  もう (3,4) 動いた");

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
