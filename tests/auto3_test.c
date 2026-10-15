/* AUTO モード (32915) の 同じ点の円・(LL)・ブロックと保護レイヤの拒否。
   逆コンパイルの読み（src/cmd.c の au_circle・au_ll・au_reject の注）、原典では押していない。
   (LL) の切断・(LL) からの部分消し は 原典に押させた答え au_b9・au_b8 と同じになるはず。 */
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
static int wall;                /* 壁の線の番号（白紙の図面には 文字が一つ先にある） */

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

static void ll(int x, int y)
{
    double mx, my;

    mm(x, y, &mx, &my);
    jw_cmd_point_ll((jw_drawing *)app_drawing(), app_view(), mx, my);
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

/* 最後の要素が 円 で、中心 (cx,cy)・半径 rr か */
static void want_circle(const char *what, double cx, double cy, double rr)
{
    const jw_drawing *d = app_drawing();
    const jw_obj *o = &d->obj[d->ndrawn - 1];

    if (o->cls != JW_ENKO || fabs(o->d[0] - cx) > 1e-6 || fabs(o->d[1] - cy) > 1e-6
        || fabs(o->d[2] - rr) > 1e-6) {
        printf("BAD  %s: 種類 %d 中心 %.4f,%.4f 半径 %.4f（期待 %.4f,%.4f %.4f）\n", what,
               o->cls, o->d[0], o->d[1], o->d[2], cx, cy, rr);
        fails++;
    }
    if (jw_cmd() != JW_CMD_AUTO)
        bad("円のあと AUTO に戻らない");
}

/* 原典の答えと 線の座標が同じか */
static void want_ref(const char *name)
{
    char path[96];
    FILE *f;
    long n;
    unsigned char *b;
    jw_drawing ref;
    const jw_drawing *d = app_drawing();
    const jw_obj *ra[64], *ma[64];
    int ri = 0, mi = 0, i, j;

    snprintf(path, sizeof path, "decomp/res/au_%s.jww", name);
    f = fopen(path, "rb");
    if (!f) {
        bad(path);
        return;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (fread(b, 1, (size_t)n, f) != (size_t)n) {
        fclose(f);
        bad(path);
        return;
    }
    fclose(f);
    memset(&ref, 0, sizeof ref);
    jw_parse(&ref, b, n);
    for (i = 0; i < ref.ndrawn && ri < 64; i++)
        if (ref.obj[i].cls == JW_SEN)
            ra[ri++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && mi < 64; i++)
        if (d->obj[i].cls == JW_SEN)
            ma[mi++] = &d->obj[i];
    if (ri != mi) {
        printf("BAD  %s: 線 原典 %d・移植 %d\n", name, ri, mi);
        fails++;
        return;
    }
    for (i = 0; i < ri; i++)
        for (j = 0; j < 4; j++)
            if (fabs(ra[i]->d[j] - ma[i]->d[j]) > 2e-3) {
                printf("BAD  %s: %d.d[%d] 原典 %.4f・移植 %.4f\n", name, i, j,
                       ra[i]->d[j], ma[i]->d[j]);
                fails++;
            }
}

/* 断られたあとの 二押しが 新しい線 (600,300)→(700,300) になるか（断られなければ
   線編集か 押した所からの線になる） */
static void want_fresh_line(const char *what, int nbefore)
{
    const jw_drawing *d = app_drawing();
    const jw_obj *o = &d->obj[d->ndrawn - 1];
    double ax, ay, bx, by;

    press(600, 300, 0);
    press(700, 300, 0);
    mm(600, 300, &ax, &ay);
    mm(700, 300, &bx, &by);
    o = &d->obj[d->ndrawn - 1];
    if (nsen(d) != nbefore + 1 || o->cls != JW_SEN || fabs(o->d[0] - ax) > 1e-6
        || fabs(o->d[1] - ay) > 1e-6 || fabs(o->d[2] - bx) > 1e-6) {
        printf("BAD  %s: 線 %d→%d、最後 (%.3f,%.3f)-(%.3f,%.3f)\n", what, nbefore,
               nsen(d), o->d[0], o->d[1], o->d[2], o->d[3]);
        fails++;
    }
}

int main(void)
{
    FILE *f = fopen("decomp/res/new.jww", "rb");
    const jw_drawing *d;
    double cx, cy, px, py;

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    nbuf = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (unsigned char *)malloc((size_t)nbuf);
    if (fread(buf, 1, (size_t)nbuf, f) != (size_t)nbuf)
        return 1;
    fclose(f);

    /* 1. 何もないところを 左 → 動かずに 左 → 円（中心は二つ目の押し）。次の左が半径 */
    fresh();
    d = app_drawing();
    press(400, 250, 0);
    press(401, 250, 0);
    if (jw_cmd() != JW_CMD_ENKO)
        bad("同じ点の二押しで 円 にならない");
    press(450, 250, 0);
    mm(401, 250, &cx, &cy);
    mm(450, 250, &px, &py);
    want_circle("同じ点の円", cx, cy, hypot(px - cx, py - cy));
    if (nsen(d) != 1)
        bad("同じ点の円で 線ができた");

    /* 2. 2 画素離れれば 線 */
    fresh();
    d = app_drawing();
    press(400, 250, 0);
    press(402, 250, 0);
    if (jw_cmd() != JW_CMD_AUTO || nsen(d) != 2)
        bad("2 画素離れた二押しが 線 にならない");

    /* 3. 右で読んで 右でもう一度 → 読んだ点（壁の端）が中心 */
    fresh();
    d = app_drawing();
    press(301, 401, 1);
    press(302, 400, 1);
    if (jw_cmd() != JW_CMD_ENKO)
        bad("右の同じ点で 円 にならない");
    press(350, 300, 0);
    mm(350, 300, &px, &py);
    want_circle("右の同じ点の円", d->obj[wall].d[0], d->obj[wall].d[1],
                hypot(px - d->obj[wall].d[0], py - d->obj[wall].d[1]));

    /* 4. 何もないところの (LL) → 円 */
    fresh();
    d = app_drawing();
    ll(400, 250);
    if (jw_cmd() != JW_CMD_ENKO)
        bad("(LL) で 円 にならない");
    press(420, 250, 0);
    mm(400, 250, &cx, &cy);
    mm(420, 250, &px, &py);
    want_circle("(LL) の円", cx, cy, hypot(px - cx, py - cy));

    /* 5. 線を押して その線を (LL) → 切断（原典の b9 = 線・P2・P2 と同じ） */
    fresh();
    press(500, 400, 0);
    ll(450, 400);
    if (jw_cmd() != JW_CMD_AUTO || jw_cmd_midway())
        bad("(LL) の切断のあと AUTO の初めに戻らない");
    want_ref("b9");

    /* 6. 何も持たずに線を (LL) → 線と P2 を一度に。次の左で部分消し（b8 と同じ） */
    fresh();
    ll(450, 400);
    press(600, 400, 0);
    want_ref("b8");

    /* 7. 保護レイヤの線は 左で拾えない。右は 複線 */
    fresh();
    d = app_drawing();
    ((jw_drawing *)d)->group[d->obj[wall].lgroup & 15].layer[d->obj[wall].layer & 15].state2 = 1;
    press(500, 400, 0);
    if (jw_cmd_midway())
        bad("保護レイヤの線を 左で拾った");
    want_fresh_line("保護レイヤ", 1);
    press(500, 400, 1);
    if (jw_cmd() != JW_CMD_FUKUSEN)
        bad("保護レイヤの線を 右で押して 複線 にならない");

    /* 8. グループの保護も同じ */
    fresh();
    d = app_drawing();
    ((jw_drawing *)d)->group[d->obj[wall].lgroup & 15].c = 1;
    press(500, 400, 0);
    want_fresh_line("保護グループ", 1);

    /* 9. ブロックの線は 左で拾えない */
    fresh();
    d = app_drawing();
    ((jw_drawing *)d)->obj[wall].sel = 1;
    if (!jw_cmd_block_make((jw_drawing *)d, "B", 0))
        bad("ブロック化できない");
    app_command(32915);
    press(500, 400, 0);
    if (jw_cmd_midway())
        bad("ブロックの線を 左で拾った");
    want_fresh_line("ブロック", 0);

    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
