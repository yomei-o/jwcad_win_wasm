/* 寸法 (32847) の ＝ (1060、引出線タイプ)。
 *
 *   tests/sunpoeq_test.exe
 *
 * **逆コンパイルの読みで、原典では押していない。照らす原典の答えは無い**
 * （docs/notes-commands.md「＝ (1060) の受け手」）。読んだ所:
 *
 *   釦       FUN_005d9350（+0x25c < 2 で DAT_00a0bcc0 を 0〜3 で回す）、
 *            名札 FUN_005da770
 *   段       左 FUN_0077fda0: 段 0・1 の基準点 +0x558、FUN_00783690 で ＝ は
 *            段 7、－ は段 3。段 7 はクリックで +0x4520（反転）、マウスが
 *            |dx|+|dy| > 2 画素動けば段 3（FUN_0077ab30）―― ここだけは
 *            **原典で測って確かめた**（2026-10-18、tools/probe194.sh・
 *            tools/fuzzcases/505〜508。座標だけ（投げメッセージ）の
 *            クリックでは 反転しない。実カーソルを本当に同じ画素へ置いて
 *            から クリックすると 反転するが、移植の jw_cmd_point に
 *            そこを区別する道が無く、fuzzcases の答えが 座標だけでの
 *            比べなので、座標だけの場合に合わせて 反転しないままにした。
 *            src/cmd.c の JW_CMD_SUNPO・sun_eq_wait のコメントを見てください）
 *   置き場   FUN_00781520: ＝(1) は 基準点から -s·1483 に寸法線、-s·1482 に
 *            引出線の端、＝(2) は 1485・1484。－ は寸法線が基準点を通る
 *   引出線   FUN_00783730: － は端ごとに 測った点から 1486 だけ寸法線へ寄せる
 *   案内     5409 +「  [ =(1) ]」+ 5407、段 7 は 5408、－ は 5330 +「  [ - ]」
 *
 * 既定は 1482〜1486 = 5 10 0 5 3（レジストリ SUNPO の HIKIDASHI1 SUNPOSEN1
 * HIKIDASHI2 SUNPOSEN2 HIKIDASHI3）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/gen/prompts.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
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

static const char *prompt(void)
{
    const char *p = jw_cmd_prompt();
    return p ? p : "";
}

/* 寸法の引出線（色 引出線色、寸法線のあとの 線 二本）の y 二つ */
static int hiki(const jw_drawing *d, int b0, double *ya, double *yb)
{
    int k, m = 0, first = 1;

    for (k = b0; k < d->ndrawn; k++) {
        const jw_obj *o = &d->obj[k];
        if (o->cls != JW_SEN)
            continue;
        if (first) {            /* 一本目は寸法線 */
            first = 0;
            continue;
        }
        if (m == 0) {
            ya[0] = o->d[1];
            ya[1] = o->d[3];
        } else if (m == 1) {
            yb[0] = o->d[1];
            yb[1] = o->d[3];
        }
        m++;
    }
    return m;
}

static double dimline_y(const jw_drawing *d, int b0)
{
    int k;

    for (k = b0; k < d->ndrawn; k++)
        if (d->obj[k].cls == JW_SEN)
            return d->obj[k].d[1];
    return -1e9;
}

static void measure(jw_drawing *d)
{
    jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
}

int main(void)
{
    unsigned char *b;
    long n;
    jw_drawing *d;
    jw_obj *ln;
    int b0, m;
    double ya[2], yb[2], px;
    char want[256];

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    ln = jw_add(d, JW_SEN);
    ln->d[0] = 100.0;
    ln->d[1] = 100.0;
    ln->d[2] = 200.0;
    ln->d[3] = 100.0;
    app_fit();
    px = 1.0 / app_view()->scale;           /* 一画素の用紙 mm */

    jw_cmd_set(JW_CMD_SUNPO);
    ck(jw_cmd_sunpo_eq() == 0, "＝ は 0（ふつう）から");
    ck(!strcmp(prompt(), JW_STR_5329), "  案内はふつうの 5329");
    ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_eq() == 1, "一回で ＝(1)");
    sprintf(want, "%s  [ =(1) ]%s", JW_STR_5409, JW_STR_5407);
    ck(!strcmp(prompt(), want), "  案内は 5409 +  [ =(1) ] + 5407");

    /* ---- ＝(1): 基準点 → マウス移動 → 始点 → 終点 */
    jw_cmd_point(d, app_view(), 100.0, 100.0, 1);   /* (R) で線の端を読む */
    ck(!strcmp(prompt(), JW_STR_5408), "基準点のあとは 5408（ﾏｳｽ移動で確定）");
    ck(!jw_cmd_sunpo_move(app_view(), 100.0 + 0.9 * px, 100.0 + 0.9 * px),
       "  二画素では進まない（|dx|+|dy| > 2）");
    ck(jw_cmd_sunpo_move(app_view(), 100.0 + 2 * px, 100.0 + 2 * px),
       "  四画素で進む");
    ck(!strcmp(prompt(), JW_STR_5331), "  案内は 寸法の始点");
    ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_eq() == 1
       && jw_cmd_sunpo_hikikaku(0, 0),
       "  始点待ちでは ＝ は回らない（引出角 の釦になる。S_SET5 が無いので 0 のまま）");
    b0 = d->ndrawn;
    measure(d);
    ck(d->ndrawn > b0, "  寸法が引けた");
    ck(near(dimline_y(d, b0), 90.0), "  寸法線は 基準点から 1483 の 10 下");
    m = hiki(d, b0, ya, yb);
    ck(m == 2 && near(ya[0], 90.0) && near(ya[1], 95.0)
       && near(yb[0], 90.0) && near(yb[1], 95.0),
       "  引出線は寸法線から 基準点の 1482 の 5 下まで");
    printf("     寸法線 %g、引出線 %g..%g / %g..%g（%d 本）\n",
           dimline_y(d, b0), ya[0], ya[1], yb[0], yb[1], m);

    /* 次の寸法も同じ置き場（段 5 → 始点） */
    b0 = d->ndrawn;
    measure(d);
    ck(near(dimline_y(d, b0), 90.0), "  続けて引いても同じ高さ");

    /* ---- 同一点クリック（座標だけ）は 反転しない: 原典で測った
       （2026-10-18、tools/probe194.sh・tools/fuzzcases/505〜508、答えは
       decomp/res/fz_505.jww ほか）。基準点の画素へ 座標だけの投げメッセージ
       （実カーソルは動かさない）で 同じ画素をもう一度クリックしてから
       始点・終点を取ると、寸法線は 基準点 − 10・引出線は 基準点 − 5 の
       まま（反転しない）。fz_505.jww・fz_507.jww・fz_508.jww と 原典で
       測り直して一致を確かめた。

       実カーソル（SetCursorPos）を本当に同じ画素へ置いてから 二回クリック
       すると 原典は +10・+5 側へ出す（tools/probe194.sh、tmp/p194_vtest.jww
       ほか）が、移植の jw_cmd_point は 座標と釦だけを受け、実カーソルが
       動いたかを区別できない。fuzzcases は 座標だけで原典と照らしている
       ので、ここは 座標だけのときに原典が実際にする（反転しない）ほうに
       合わせた。 */
    jw_cmd_set(0);
    jw_cmd_set(JW_CMD_SUNPO);
    ck(jw_cmd_sunpo_eq() == 1, "＝ は命令を出入りしても残る（大域 DAT_00a0bcc0）");
    jw_cmd_point(d, app_view(), 100.0, 100.0, 1);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 1);   /* 段 7 のクリック（座標だけ） */
    ck(!strcmp(prompt(), JW_STR_5331), "  段 7 でクリックすると始点へ");
    b0 = d->ndrawn;
    measure(d);
    m = hiki(d, b0, ya, yb);
    ck(near(dimline_y(d, b0), 90.0) && m == 2 && near(ya[1], 95.0),
       "  反転しない: 寸法線は 10 下、引出線は 5 下から（ふつうと同じ側）");

    /* ---- Esc は基準点へ */
    jw_cmd_set(0);
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 1);
    jw_cmd_esc_key(d);
    sprintf(want, "%s  [ =(1) ]%s", JW_STR_5409, JW_STR_5407);
    ck(!strcmp(prompt(), want), "段 7 で Esc は基準点の案内へ");

    /* ---- ＝(2): 1485 の 5、1484 の 0 */
    ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_eq() == 2, "二回で ＝(2)");
    jw_cmd_point(d, app_view(), 100.0, 100.0, 1);
    jw_cmd_sunpo_move(app_view(), 120.0, 120.0);
    b0 = d->ndrawn;
    measure(d);
    m = hiki(d, b0, ya, yb);
    ck(near(dimline_y(d, b0), 95.0) && m == 2 && near(ya[0], 95.0)
       && near(ya[1], 100.0), "  寸法線は 5 下、引出線は 基準点（0）まで");

    /* ---- －: 寸法線が基準点を通り、引出線は測った点から 1486 の 3 手前 */
    jw_cmd_set(0);
    jw_cmd_set(JW_CMD_SUNPO);
    ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_eq() == 3, "三回で －");
    sprintf(want, "%s  [ - ]", JW_STR_5330);
    ck(!strcmp(prompt(), want), "  案内は 5330 +  [ - ]");
    jw_cmd_point(d, app_view(), 150.0, 130.0, 0);   /* (L) free */
    ck(!strcmp(prompt(), JW_STR_5331), "  基準点のあとはすぐ始点（段 7 は無い）");
    b0 = d->ndrawn;
    measure(d);
    m = hiki(d, b0, ya, yb);
    ck(near(dimline_y(d, b0), 130.0), "  寸法線は基準点の高さ");
    ck(m == 2 && near(ya[0], 130.0) && near(ya[1], 103.0)
       && near(yb[1], 103.0), "  引出線は 寸法線から 測った点の 3 手前まで");
    printf("     寸法線 %g、引出線 %g..%g / %g..%g（%d 本）\n",
           dimline_y(d, b0), ya[0], ya[1], yb[0], yb[1], m);
    /* 測った点の上に基準点を置くと 引出線 は無い（隔たり 0） */
    jw_cmd_set(0);
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_point(d, app_view(), 150.0, 100.0, 0);
    b0 = d->ndrawn;
    measure(d);
    m = hiki(d, b0, ya, yb);
    ck(d->ndrawn > b0 && m == 0, "  測った点の高さに基準点なら引出線は無い");

    /* 四回目で ふつう に戻る */
    jw_cmd_set(0);
    jw_cmd_set(JW_CMD_SUNPO);
    ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_eq() == 0, "四回で ふつう に戻る");
    ck(!strcmp(prompt(), JW_STR_5329), "  案内もふつう");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
