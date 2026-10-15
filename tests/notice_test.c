/* 札（知らせ、jw_cmd_notice）が出て、消えるか。
   原典の FUN_005168b0 → CMsgDialog（FUN_00588100・FUN_00588380）と FUN_004fb9f0 の読み
   （src/cmd.c の jw_cmd_notice の注）。逆コンパイルの読み、原典では押していない。
     - 押した画素の 32 下に、黒の枠・地 0xc8c8c8 の箱
     - 次に押す・マウスが札に乗る・命令を替えると消える
     - 配線したもののうち コーナー（平行・同じ線）・中心線（同じ点）・AUTO（ブロック）・
       接円（楕円）を押して確かめる */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/prompts.h"

static unsigned char *buf;
static long nbuf;
static rect_t r;
static int fails;

static void bad(const char *what)
{
    printf("BAD  %s\n", what);
    fails++;
}

static void press(int x, int y, int b)
{
    app_press(r.x + x, r.y + y, b);
}

/* 白紙に 横の線を二本: (300,400)→(800,400) と (300,450)→(800,450) */
static void fresh(void)
{
    app_new();
    app_resize(1264, 741);
    app_open(buf, nbuf);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32771);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    press(300, 400, 0);
    press(800, 400, 0);
    press(300, 450, 0);
    press(800, 450, 0);
}

static unsigned px(int x, int y)
{
    const fb_t *fb = app_fb();

    return fb->px[y * fb->w + x] & 0xffffffu;
}

/* 札 id が出ていて、押した (x,y) の 32 下に箱が描かれているか */
static void want(const char *what, int id, int x, int y)
{
    char m[160];
    int bx = r.x + x, by = r.y + y + 32;

    if (jw_cmd_notice_id() != id) {
        snprintf(m, sizeof m, "%s: 札 %d（期待 %d）", what, jw_cmd_notice_id(), id);
        bad(m);
        return;
    }
    app_paint();
    if (px(bx, by) != 0 || px(bx + 1, by + 1) != 0xc8c8c8u
        || px(bx + 3, by - 1) == 0xc8c8c8u) {
        snprintf(m, sizeof m, "%s: 箱が無い（枠 %06x 地 %06x）", what, px(bx, by),
                 px(bx + 1, by + 1));
        bad(m);
    }
}

static void none(const char *what)
{
    char m[160];

    if (jw_cmd_notice_id() != 0) {
        snprintf(m, sizeof m, "%s: 札 %d が残る", what, jw_cmd_notice_id());
        bad(m);
    }
}

int main(void)
{
    FILE *f = fopen("decomp/res/new.jww", "rb");
    rect_t nr;
    unsigned before;

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    nbuf = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (unsigned char *)malloc((size_t)nbuf);
    if (fread(buf, 1, (size_t)nbuf, f) != (size_t)nbuf)
        return 1;
    fclose(f);

    /* 1. 仕組み: 出す → 描く → 押せば消える */
    fresh();
    none("初め");
    before = jw_cmd_notice_seq();
    press(200, 200, 0);
    JW_NOTICE(5205);
    if (jw_cmd_notice_seq() == before)
        bad("seq が進まない");
    if (!jw_cmd_notice_text() || strcmp(jw_cmd_notice_text(), JW_STR_5205) != 0)
        bad("文が違う");
    want("じかに出した札", 5205, 200, 200);
    press(150, 150, 0);
    none("押したあと");
    app_paint();
    if (px(r.x + 201, r.y + 233) == 0xc8c8c8u)
        bad("押したあとも箱が描かれる");

    /* 2. マウスが札に乗ると消える。札の外を動いても残る */
    press(200, 200, 0);
    JW_NOTICE(5343);
    app_paint();
    ui_notice_rect(app_fb()->w, app_fb()->h, r.x + 200, r.y + 200, JW_STR_5343, &nr);
    if (nr.x != r.x + 200 || nr.y != r.y + 232 || nr.w < 20 || nr.h < 12)
        bad("箱の場所・大きさがおかしい");
    app_move(r.x + 600, r.y + 100);
    if (jw_cmd_notice_id() != 5343)
        bad("札の外へ動いて消えた");
    app_move(nr.x + 3, nr.y + 3);
    none("札の上へ動いたあと");

    /* 3. 命令を替えると消える */
    press(200, 200, 0);
    JW_NOTICE(5201);
    app_command(32786);
    none("命令を替えたあと");

    /* 4. コーナー: 平行な二本 → 計算できません。同じ線を二度 → 同一線です */
    fresh();
    app_command(32786);
    press(500, 400, 0);
    press(500, 450, 0);
    want("コーナー 平行", 5205, 500, 450);
    press(500, 400, 0);
    none("コーナー 次の押し");
    press(500, 400, 0);
    want("コーナー 同じ線", 5351, 500, 400);

    /* 5. 中心線: (R) で同じ点を二度 → 同一点です */
    fresh();
    app_command(32873);
    press(300, 400, 1);
    none("中心線 一つ目");
    press(300, 400, 1);
    want("中心線 同じ点", 5343, 300, 400);

    /* 6. AUTO: ブロックの線を左で → ブロック図形です */
    fresh();
    ((jw_drawing *)app_drawing())->obj[app_drawing()->ndrawn - 1].sel = 1;
    if (!jw_cmd_block_make((jw_drawing *)app_drawing(), "B", 0))
        bad("ブロック化できない");
    app_command(32915);
    press(500, 450, 0);
    want("AUTO ブロック", 5231, 500, 450);

    /* 7. 接円: 楕円を拾う → 楕円は計算できません。 */
    fresh();
    {
        jw_drawing *d = (jw_drawing *)app_drawing();
        int i = d->ndrawn - 1;

        d->obj[i].cls = JW_ENKO;    /* 下の線を 楕円 に作り替える */
        d->obj[i].d[2] = 50.0;
        d->obj[i].d[3] = 0.0;
        d->obj[i].d[4] = 2 * 3.14159265358979;
        d->obj[i].d[5] = 0.0;
        d->obj[i].d[6] = 0.5;
        {   /* 中心は その線の左端の図面の点 */
            const jw_view *v = app_view();

            d->obj[i].d[0] = v->ox + (r.x + 300 - v->bx) / v->scale;
            d->obj[i].d[1] = v->oy + (v->by - (r.y + 450)) / v->scale;
            d->obj[i].d[0] -= d->obj[i].d[2];       /* 右の端が (300,450) に来る */
        }
    }
    app_command(32872);
    press(300, 450, 0);
    want("接円 楕円", 5214, 300, 450);

    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
