/* 接円の三つ目の段の末尾 【 n - k 】 の k（マウスにいちばん近い候補の番号）を、
 * 原典で測った番号の順と比べる（tools/jwdraw.ps1 の m と stat。原典を同じ手順で動かし、
 * 図面の上の格子の各点へ動かして読んだ。逆コンパイルは FUN_00707d60）。
 *
 *   tests/sekidx_test.exe
 *
 * 候補の順は 拾ったものの組で決まる（拾った順ではない）:
 *   線と線   中心 ＝ 交点 から 二等分線の向き（線の角の平均、線は右向きにそろえる）の + と −、
 *            そのあと直角の向きの + と −
 *   線と円   線の左 +r 側 で 円の半径 r+rc（線の向きに先に進む側、あと戻る側）、同じく r−rc、
 *            次に 線の右 −r 側 で r+rc、r−rc
 *   円と円   (r+R1, r+R2)・(r−R1, r+R2)・(r+R1, r−R2)・(r−R1, r−R2) の順に 上の向き、下の向き
 * 読取点（右）を一つ含む組も 末尾が出る。
 * 二つ目を押した直後の番号は 原典では押した点と関わらず、実行ごとに変わった（未解明）ので比べない。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/ui.h"

static int fails;
static rect_t R;

static void ck(int ok, const char *what)
{
    if (!ok) {
        printf("BAD  %s\n", what);
        fails++;
    }
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
        fclose(f);
        return 0;
    }
    fclose(f);
    return b;
}

static int start(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);

    if (!b) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        return 0;
    }
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    free(b);
    ui_view_rect(app_fb()->w, app_fb()->h, &R);
    return 1;
}

static void line(int x1, int y1, int x2, int y2)
{
    app_command(32771);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    app_press(R.x + x1, R.y + y1, 0);
    app_press(R.x + x2, R.y + y2, 0);
}

static void circle(int cx, int cy, int rx, int ry)
{
    app_command(32773);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    app_press(R.x + cx, R.y + cy, 0);
    app_press(R.x + rx, R.y + ry, 0);
}

static void radius(const char *s)
{
    jw_cmd_box_put(1411, s);
    jw_cmd_box_sum(1411);
}

static void pick(int x, int y, int button)
{
    app_press(R.x + x, R.y + y, button);
}

/* 【 n - k 】 を読む。出ていなければ 0 */
static int tail(int x, int y, int *n)
{
    const char *st, *p;
    int k = 0;

    app_move(R.x + x, R.y + y);
    st = jw_cmd_status(app_drawing());
    p = strstr(st, "\x81y");
    if (!p || sscanf(p + 2, " %d - %d", n, &k) != 2)
        return 0;
    return k;
}

static void is(int x, int y, int cnt, int want, const char *what)
{
    int n = -1, k = tail(x, y, &n);
    char b[160];

    snprintf(b, sizeof b, "%s (%d,%d) -> 【 %d - %d 】, want 【 %d - %d 】", what, x, y, n, k, cnt, want);
    ck(k == want && n == cnt, b);
}

int main(void)
{
    int i;
    static const int lc[8][2] = {{584, 271}, {416, 271}, {508, 271}, {492, 271},
                                 {584, 329}, {416, 329}, {508, 329}, {492, 329}};

    /* 線と線、横線（左から右）に 縦線（上から下）: 右下 1・左上 2・右上 3・左下 4 */
    if (!start())
        return 1;
    line(300, 300, 700, 300);
    line(500, 150, 500, 450);
    app_command(32872);
    radius("100");
    pick(400, 300, 0);
    pick(500, 200, 0);
    is(400, 250, 4, 2, "二線 縦=下向き 左上");
    is(600, 250, 4, 3, "  右上");
    is(600, 350, 4, 1, "  右下");
    is(400, 350, 4, 4, "  左下");

    /* 縦線を 下から上に引くと 二等分線が 右上へ: 右上 1・左下 2・左上 3・右下 4 */
    if (!start())
        return 1;
    line(300, 300, 700, 300);
    line(500, 450, 500, 150);
    app_command(32872);
    radius("100");
    pick(400, 300, 0);
    pick(500, 200, 0);
    is(400, 250, 4, 3, "二線 縦=上向き 左上");
    is(600, 250, 4, 1, "  右上");
    is(600, 350, 4, 4, "  右下");
    is(400, 350, 4, 2, "  左下");

    /* 縦線を先に拾っても同じ（二等分線は 二本の角の平均） */
    if (!start())
        return 1;
    line(500, 150, 500, 450);
    line(300, 300, 700, 300);
    app_command(32872);
    radius("100");
    pick(500, 200, 0);
    pick(400, 300, 0);
    is(400, 250, 4, 2, "二線 縦を先に 左上");
    is(600, 350, 4, 1, "  右下");

    /* 斜めの二本（どちらも 右上がり・右下がり、向きを入れ替えても同じ番号） */
    for (i = 0; i < 2; i++) {
        if (!start())
            return 1;
        if (i == 0) {
            line(300, 400, 700, 200);
            line(350, 150, 650, 450);
        } else {
            line(700, 200, 300, 400);
            line(650, 450, 350, 150);
        }
        app_command(32872);
        radius("1800");
        pick(350, 375, 0);
        pick(600, 400, 0);
        is(300, 150, 4, 2, "斜め二線 左上");
        is(500, 150, 4, 3, "  上");
        is(700, 150, 4, 1, "  右上");
        is(300, 450, 4, i == 0 ? 2 : 4, "  左下");
        is(700, 450, 4, 1, "  右下");
    }

    /* 線（左から右）と円（線の上に中心）: 8 つ。線の左側（紙で上）の 外側の円（先に右、あと左）、
       内側の円（右、左）、次に線の右側（紙で下）で同じ順 */
    if (!start())
        return 1;
    line(300, 300, 700, 300);
    circle(500, 300, 560, 300);
    app_command(32872);
    radius("1800");
    pick(350, 300, 0);
    pick(500, 240, 0);
    for (i = 0; i < 8; i++)
        is(lc[i][0], lc[i][1], 8, i + 1, "線と円 右向き");

    /* 線を右から左へ引くと 左右・上下とも入れ替わる（格子の点で測った） */
    if (!start())
        return 1;
    line(700, 300, 300, 300);
    circle(500, 300, 560, 300);
    app_command(32872);
    radius("1800");
    pick(350, 300, 0);
    pick(500, 240, 0);
    is(300, 150, 8, 5, "線と円 左向き 左上");
    is(700, 150, 8, 6, "  右上");
    is(500, 150, 8, 7, "  上");
    is(300, 450, 8, 1, "  左下");
    is(700, 450, 8, 2, "  右下");
    is(500, 450, 8, 3, "  下");

    /* 円を先に拾っても 線と円の順は変わらない */
    if (!start())
        return 1;
    line(300, 300, 700, 300);
    circle(500, 300, 560, 300);
    app_command(32872);
    radius("1800");
    pick(500, 240, 0);
    pick(350, 300, 0);
    is(300, 150, 8, 2, "円を先に 左上");
    is(700, 150, 8, 1, "  右上");
    is(500, 150, 8, 3, "  上");
    is(300, 450, 8, 6, "  左下");
    is(700, 450, 8, 5, "  右下");
    is(500, 350, 8, 7, "  下");

    /* 線と読取点（右）、読取点と線: 二つ。末尾が出る */
    if (!start())
        return 1;
    line(450, 260, 450, 262);
    line(520, 230, 520, 232);
    line(300, 300, 700, 300);
    app_command(32872);
    radius("5000");
    pick(350, 300, 0);
    pick(450, 260, 1);
    is(300, 150, 2, 2, "線と点 左上");
    is(500, 150, 2, 1, "  上");
    if (!start())
        return 1;
    line(450, 260, 450, 262);
    line(300, 300, 700, 300);
    app_command(32872);
    radius("5000");
    pick(450, 260, 1);
    pick(350, 300, 0);
    is(300, 150, 2, 2, "点と線 左上");
    is(500, 150, 2, 1, "  上");

    /* 二円 */
    if (!start())
        return 1;
    circle(400, 300, 460, 300);
    circle(560, 300, 610, 300);
    app_command(32872);
    radius("1800");
    pick(400, 240, 0);
    pick(560, 250, 0);
    is(450, 150, 2, 1, "二円 上");
    is(450, 450, 2, 2, "  下");

    /* 円と点、点と点: 二つ */
    if (!start())
        return 1;
    line(450, 260, 450, 262);
    line(520, 230, 520, 232);
    circle(400, 300, 460, 300);
    app_command(32872);
    radius("5000");
    pick(400, 240, 0);
    pick(520, 230, 1);
    is(450, 150, 2, 1, "円と点 上");
    is(450, 450, 2, 2, "  下");
    if (!start())
        return 1;
    line(450, 260, 450, 262);
    line(520, 230, 520, 232);
    app_command(32872);
    radius("5000");
    pick(450, 260, 1);
    pick(520, 230, 1);
    is(450, 150, 2, 1, "点と点 上");
    is(450, 450, 2, 2, "  下");

    printf("%s sekidx\n", fails ? "BAD " : "ok  ");
    return fails != 0;
}
