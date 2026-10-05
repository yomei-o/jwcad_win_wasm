/* 測定 (32897) —— 状態表示の読み出しを原典と一字ずつ突き合わせます。
 *
 *   tests/sokutei_test.exe
 *
 * 原典に 400x200 画素の四角を一周させ、クリックのたびに状態表示を読んだ
 * ものが下の表です（`tools/probe125.sh`・`probe129.sh`・`probe130.sh`、
 * 新規の A-2・1/100）。【】の中がこれまでの合計、その右がいま足した分で、
 * 合計は 小数桁 のぶん、右は %g と同じ六桁です。
 *
 *   距離測定 (1064)  合計は道のり、右は一辺
 *   面積測定 (1065)  合計は多角形の面積、右はいま足した三角形。単位は ｍ2
 *   角度測定 (1067)  原点 → 基準点 → 角度点 の三手。S = 1 / … は付かない
 *   mm /【ｍ】(1069) 単位が mm になり、合計にだけ三桁ごとのコンマ
 *   小数桁 3 (1070)  押すたびに 0 1 2 3 4 F とめぐる（F は小数六桁）
 *
 * **「足したものが零」のときは「-0」**と書かれます —— 距離の一点目も、
 * 面積の輪を閉じる一手も。
 *
 * 座標測定 と 角度測定 の**途中の数はマウスの今の位置**を映すので、
 * 投げたクリックでは測れませんでした。そこは原典と合いません（ここでも
 * 較べていません）。座標測定・○単独円指定・測定結果書込・書込設定 は
 * まだ入れていません。
 */
#include <stdio.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* the tail the original hung off the status line, one per click */
static const char *const WANT[] = {
    "      S = 1 / 100  \x81y 0.000\x82\x8d \x81z   0\x82\x8d",
    "      S = 1 / 100  \x81y 0.000\x82\x8d \x81z   -0\x82\x8d",
    "      S = 1 / 100  \x81y 24.490\x82\x8d \x81z   24.4898\x82\x8d",
    "      S = 1 / 100  \x81y 36.735\x82\x8d \x81z   12.2449\x82\x8d",
    "      S = 1 / 100  \x81y 61.224\x82\x8d \x81z   24.4898\x82\x8d",
    "      S = 1 / 100  \x81y 73.469\x82\x8d \x81z   12.2449\x82\x8d",
};

/* 面積測定: on entering, after the four corners, and after closing */
static const char *const AREA[] = {
    "      S = 1 / 100  \x81y 0.000\x82\x8d" "2 \x81z   0\x82\x8d" "2",
    "      S = 1 / 100  \x81y 299.875\x82\x8d" "2 \x81z   149.938\x82\x8d" "2",
    "      S = 1 / 100  \x81y 299.875\x82\x8d" "2 \x81z   -0\x82\x8d" "2",
};

/* and the same in mm, which is what mm /【ｍ】 turns it into */
static const char *const AREAMM[] = {
    "      S = 1 / 100  \x81y 0.000mm2 \x81z   0mm2",
    "      S = 1 / 100  \x81y 299,875,052.062mm2 \x81z   1.49938e+08mm2",
};

/* 距離測定 in mm */
static const char *const MM[] = {
    "      S = 1 / 100  \x81y 0.000mm \x81z   0mm",
    "      S = 1 / 100  \x81y 0.000mm \x81z   -0mm",
    "      S = 1 / 100  \x81y 24,489.796mm \x81z   24489.8mm",
};

/* 角度測定: on entering, while it asks for the 基準点 (no readout at all),
   while it asks for the 角度点, and the angle it ends on */
static const char *const ANG[] = {
    "              \x81y 0.000\x81\x8b \x81z",
    "(R)Read",
    "       \x81y 0.000\x81\x8b \x81z",
    "              \x81y -26.565\x81\x8b \x81z",
};

static const struct { int x, y; } PT[5] = {
    { 300, 300 }, { 700, 300 }, { 700, 500 }, { 300, 500 }, { 300, 300 },
};

static void cktext(const char *want, const char *what)
{
    const char *s = jw_cmd_status(app_drawing());
    int n = (int)strlen(s), m = (int)strlen(want);
    int ok = n >= m && !strcmp(s + n - m, want);

    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok) {
        printf("     got  [%s]\n", n >= m ? s + n - m : s);
        printf("     want [%s]\n", want);
        fails++;
    }
}

static void cktail(int k)
{
    char what[96];

    sprintf(what, "%d 点目の読み出し", k);
    cktext(WANT[k], what);
}

static void bar(int id)
{
    jw_cmd_bar((jw_drawing *)app_drawing(), id);
}

static void corners(int n)
{
    int i;

    for (i = 0; i < n; i++)
        app_press(PT[i].x, PT[i].y, 0);
}

int main(void)
{
    int i;

    app_resize(1264, 741);
    app_new();

    /* ------------------------------------------------------ 距離測定 --- */
    ck(app_command(32897) != 0, "測定 が出る");
    ck(jw_cmd() == JW_CMD_SOKUTEI, "  それが今の命令になる");
    ck(jw_cmd_sokutei_mode() == 1064, "  出たときは 距離測定");
    cktail(0);
    for (i = 0; i < 5; i++) {
        app_press(PT[i].x, PT[i].y, 0);
        cktail(i + 1);
    }
    ck(app_drawing()->ndrawn == 0, "測定は図面に何も足さない");

    /* leaving the command drops the run */
    app_command(JW_CMD_SEN);
    ck(strstr(jw_cmd_status(app_drawing()), "S = 1 /") == 0,
       "命令を出ると読み出しも消える");

    /* ------------------------------------------------------ 面積測定 --- */
    app_command(32897);
    bar(1065);
    ck(jw_cmd_sokutei_mode() == 1065, "面積測定 を選べる");
    cktext(AREA[0], "  出たての読み出し");
    corners(4);
    cktext(AREA[1], "  四隅で 299.875 m2");
    app_press(PT[4].x, PT[4].y, 0);
    cktext(AREA[2], "  輪を閉じる一手は -0");

    /* ------------------------------------------------------ mm に --- */
    app_command(32897);
    bar(1065);
    bar(1069);
    ck(jw_cmd_sokutei_mm(), "mm にできる");
    cktext(AREAMM[0], "  面積の単位は mm2");
    corners(4);
    cktext(AREAMM[1], "  合計には三桁ごとのコンマ、右は %g のまま");

    app_command(32897);
    ck(jw_cmd_sokutei_mode() == 1064, "命令に入り直すと 距離測定 に戻る");
    ck(jw_cmd_sokutei_mm(), "  単位は mm のまま（設定なので）");
    cktext(MM[0], "  距離も mm で");
    app_press(PT[0].x, PT[0].y, 0);
    cktext(MM[1], "  一点目は -0");
    app_press(PT[1].x, PT[1].y, 0);
    cktext(MM[2], "  二点目で 24,489.796mm");

    /* ------------------------------------------------------ 小数桁 --- */
    ck(jw_cmd_sokutei_dp() == 3, "小数桁 は 3 から");
    bar(1070);
    ck(jw_cmd_sokutei_dp() == 4, "  押すと 4");
    cktext("\x81y 24,489.7959mm \x81z   24489.8mm", "  読み出しも四桁に");
    bar(1070);
    ck(jw_cmd_sokutei_dp() == 5, "  その次は F");
    cktext("\x81y 24,489.795918mm \x81z   24489.8mm", "  F は小数六桁");
    bar(1070);
    ck(jw_cmd_sokutei_dp() == 0, "  その次は 0");
    cktext("\x81y 24,490mm \x81z   24489.8mm", "  桁なし");
    bar(1070);
    bar(1070);
    bar(1070);
    ck(jw_cmd_sokutei_dp() == 3, "  六回で一周して 3 に戻る");

    /* ------------------------------------------------------ 角度測定 --- */
    app_command(32897);
    bar(1069);                          /* back to ｍ */
    bar(1067);
    ck(jw_cmd_sokutei_mode() == 1067, "角度測定 を選べる");
    cktext(ANG[0], "  出たては 0.000 度");
    app_press(PT[0].x, PT[0].y, 0);
    cktext(ANG[1], "  原点のあとは読み出しが消える");
    app_press(PT[1].x, PT[1].y, 0);
    cktext(ANG[2], "  基準点のあとはまた出る");
    app_press(PT[2].x, PT[2].y, 0);
    cktext(ANG[3], "  角度点で -26.565 度");
    ck(app_drawing()->ndrawn == 0, "  角度測定も図面に何も足さない");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
