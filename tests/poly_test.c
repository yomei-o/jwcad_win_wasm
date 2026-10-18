/* 多角形 -- against the one the original drew.
 *
 *   tests/poly_test.exe [decomp/res/poly.jww]
 *
 * That file is Test5 with an octagon on it, made by driving Jw_cad with
 * 角数 8, 寸法 3000 and 底辺角度 30 typed into the command bar and one click
 * for the centre.  The test types the same three numbers into the port's own
 * boxes, clicks the same centre, and holds the eight lines up against the
 * original's.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/bars.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* 任意 (1070) の 円・連続線指示 (1083): 連続線の鎖に 弧（JW_ENKO）が混ざった
 * ときのソリッド化。原典を動かして確かめる手段が無いので、これは「src/cmd.c
 * の tk_pick_solid に書いた逆コンパイルの読みどおりに実装した」という形の
 * 試験で、原典では押していない。
 *
 * 出典: 原典 FUN_007258d0（decomp/decomp/all_006aa801.c 54920〜55130 行目）
 * の鎖歩き第一ループ（54983-55006 行目）は CDataSen が来れば頂点を積むが、
 * CDataEnko が来ると 55001-55004 行目で +0x128 を数えるだけで頂点配列には
 * 積まない。鎖が閉じれば 55052 行目で +0x128 が 1 に上書きされ、その状態の
 * まま 55067-55073 行目の第二ループが 鎖に含まれる CDataEnko 1 個ごとに
 * FUN_007249c0(…,0) を呼ぶ。FUN_007249c0 側（54522〜54784 行目）では
 * 54615-54617 行目の `if (*(this+0x128)==1 && local_137c<10) local_137c=1;`
 * がこの呼び出しのときだけ発火し、箱 1327「弓形」・1328「円外側」の選択を
 * 無視して 常に弓形(1)（線形・円周 1326 が有効なら +10 の 11）になる。
 * nokori.md の「多角形」行にも記録済み。
 *
 * 移植（src/cmd.c の tk_pick_solid、JW_SEN 分岐）は: 鎖歩きで弧の両端点も
 * 頂点として多角形の辺に組み込み（直線の辺が弦になる）、かつ 弧 1 個につき
 * 既存の単独円ソリッド化（同じ関数の JW_ENKO 分岐）と同じ組み方の
 * ltype=101（線形・円周なら 111）・d[7]=5（弓形固定）のソリッドを 1 枚
 * 追加で作る。 */
static jw_drawing *arc_chain_setup(int ring)
{
    jw_drawing *d;
    jw_obj *o;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();

    /* 線 A (0,0)-(300,0) -> 弧 B 中心(300,100) 半径 100 (300,0)から(300,200)
       まで反時計回り半円 -> 線 C (300,200)-(600,200)。開いた鎖（閉じた輪で
       はない）で、既存の m<=4 の四角ソリッド分岐だけを使い、鎖に新しく通した
       弧の扱いを汚染なく見られるようにする */
    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 300; o->d[3] = 0;
    o = jw_add(d, JW_ENKO);
    o->d[0] = 300; o->d[1] = 100; o->d[2] = 100;
    o->d[3] = -1.5707963267948966;      /* 始角: (300,0) */
    o->d[4] = 3.141592653589793;        /* 開き 180°: 終わりは (300,200) */
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    o = jw_add(d, JW_SEN);
    o->d[0] = 300; o->d[1] = 200; o->d[2] = 600; o->d[3] = 200;
    app_fit();

    jw_cmd_set(JW_CMD_TAKAKU);
    jw_cmd_bar(d, 1070);                /* 任意 */
    if (jw_cmd_bar_check(1323) <= 0)
        jw_cmd_bar(d, 1323);
    if (ring && jw_cmd_bar_check(1326) <= 0)
        jw_cmd_bar(d, 1326);            /* 線形・円周 */
    if (!ring && jw_cmd_bar_check(1326) > 0)
        jw_cmd_bar(d, 1326);
    jw_cmd_bar(d, 1083);                /* 円・連続線指示 */
    return d;
}

static void arc_chain_test(void)
{
    jw_drawing *d;
    int before, i, nsolid, narc_bow, nquad, nline;

    printf("多角形 (1083): 連続線の鎖に混ざった弧（逆コンパイルの読みどおり、原典では押していない）:\n");

    /* 既定（弓形・円外側・線形・円周 どれも立てない）: 線 A の (0,0) に近い
       端を (L) で押す。弧は常に弓形固定・ltype=101 で 1 枚、多角形本体は
       4 頂点のまま四角ソリッド 1 枚（m<=4 分岐） */
    d = arc_chain_setup(0);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 100, 0, 0);
    ck(d->ndrawn == before + 2,
       "既定: 新しいソリッドが 2 枚（弓形 1・四角 1）、元図形は (L) で残る");
    nsolid = narc_bow = nquad = 0;
    for (i = before; i < d->ndrawn; i++) {
        const jw_obj *s = &d->obj[i];

        if (s->cls != JW_SOLID)
            continue;
        nsolid++;
        if (s->ltype == 101 && fabs(s->d[7] - 5.0) < 1e-9) {
            narc_bow++;
            ck(fabs(s->d[0] - 300) < 1e-6 && fabs(s->d[1] - 100) < 1e-6
               && fabs(s->d[2] - 100) < 1e-6,
               "  弓形ソリッドは 弧の中心・半径そのまま（ltype=101, d[7]=5）");
        } else {
            nquad++;
        }
    }
    ck(nsolid == 2 && narc_bow == 1 && nquad == 1,
       "  弓形ソリッド 1 枚・四角ソリッド 1 枚");

    /* 線形・円周 (1326): 弓形ソリッドは +10 されて ltype=111 のまま弓形
       （d[7]=5、箱 1327・1328 は見ない）。多角形本体は 辺ごとの線形ソリッド
       3 枚（頂点 4 個・辺 3 本） */
    d = arc_chain_setup(1);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 100, 0, 0);
    ck(d->ndrawn == before + 4,
       "線形・円周: 新しいソリッドが 4 枚（弓形 1・線形の辺 3）");
    narc_bow = nline = 0;
    for (i = before; i < d->ndrawn; i++) {
        const jw_obj *s = &d->obj[i];

        if (s->cls != JW_SOLID)
            continue;
        if (s->ltype == 111 && fabs(s->d[7] - 5.0) < 1e-9)
            narc_bow++;
        else
            nline++;
    }
    ck(narc_bow == 1 && nline == 3,
       "  弓形ソリッド (ltype=111) 1 枚・線形の辺 3 枚");
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

/* type into one of the bar's boxes, the way a press and the keys would */
static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);              /* clear it */
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "decomp/res/poly.jww";
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj **ref8 = 0;
    double cx = 0, cy = 0;
    int i, j, nref = 0, before, ok;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        return 1;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        return 1;
    }
    free(b);
    /* the original's octagon is the last eight lines in the file -- the six
       records Jw_cad adds when it saves come after them, so they have to be
       stepped over */
    {
        static const jw_obj *sen[8];
        for (i = 0; i < ref.ndrawn; i++)
            if (ref.obj[i].cls == JW_SEN) {
                for (j = 0; j < 7; j++)
                    sen[j] = sen[j + 1];
                sen[7] = &ref.obj[i];
                nref++;
            }
        if (nref >= 8) {
            for (i = 0; i < 8; i++) {
                cx += sen[i]->d[0];
                cy += sen[i]->d[1];
            }
            cx /= 8;
            cy /= 8;
        }
        ref8 = sen;
    }
    ck(nref >= 8, "the original's octagon is in the file");

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    before = d->ndrawn;

    /* the boxes are what the bar shows, and they can be typed into */
    jw_cmd_set(JW_CMD_TAKAKU);
    ck(jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "1000"),
       "寸法 starts at 1000, the way the original's does");
    ck(jw_cmd_box(1413) && !strcmp(jw_cmd_box(1413), "5"), "角数 at 5");
    ck(jw_cmd_box(1414) && !strcmp(jw_cmd_box(1414), "0"), "底辺角度 at 0");
    ck(jw_cmd_box(9999) == 0, "and a box the port does not keep says so");
    type_box(1413, "8");
    type_box(1411, "3000");
    type_box(1414, "30");
    ck(!strcmp(jw_cmd_box(1413), "8") && !strcmp(jw_cmd_box(1411), "3000")
       && !strcmp(jw_cmd_box(1414), "30"), "typing into them takes");
    ck(jw_cmd_box_focus() == 0, "and Enter puts the caret away");

    jw_cmd_point(d, app_view(), cx, cy, 0);
    ck(d->ndrawn == before + 8, "one click leaves the eight lines");
    if (d->ndrawn != before + 8)
        return 1;
    ok = 1;
    for (i = 0; i < 8; i++) {
        /* the original's lines and ours are the same set; they need not be
           written down in the same order for the shape to be the same */
        int found = 0;
        for (j = 0; j < 8; j++)
            if (fabs(d->obj[before + i].d[0] - ref8[j]->d[0]) < 1e-9
                && fabs(d->obj[before + i].d[1] - ref8[j]->d[1]) < 1e-9
                && fabs(d->obj[before + i].d[2] - ref8[j]->d[2]) < 1e-9
                && fabs(d->obj[before + i].d[3] - ref8[j]->d[3]) < 1e-9)
                found = 1;
        if (!found) {
            ok = 0;
            printf("     ours %.4f,%.4f -> %.4f,%.4f is not one of the "
                   "original's\n", d->obj[before + i].d[0],
                   d->obj[before + i].d[1], d->obj[before + i].d[2],
                   d->obj[before + i].d[3]);
        }
    }
    ck(ok, "every one of them where the original put it");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "元に戻る takes the whole polygon back");

    jw_free(&ref);

    arc_chain_test();

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
