/* 測定 (32897) の 距離測定 —— 状態表示の読み出しを原典と突き合わせます。
 *
 *   tests/sokutei_test.exe
 *
 * 原典に 400x200 画素の四角を一周させ、クリックのたびに状態表示を読んだ
 * ものが下の `WANT` です（`tools/probe125.sh`、新規の A-2・1/100）。
 * 【】の中がこれまでの合計、その右がいま足した一辺で、合計は小数桁 3、
 * 一辺は %g と同じ六桁、単位は ｍ です。
 *
 * **一点目だけ「-0」**と出るのも原典のとおりです。なぜ負の零になるのかは
 * 分かりません。
 *
 * このバーには 距離測定 のほかに 面積測定・座標測定・角度測定・
 * ○単独円指定・mm/【ｍ】・小数桁・測定結果書込・書込設定 が並びますが、
 * まだ訊いていません。
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

static const struct { int x, y; } PT[5] = {
    { 300, 300 }, { 700, 300 }, { 700, 500 }, { 300, 500 }, { 300, 300 },
};

static void cktail(int k)
{
    const char *s = jw_cmd_status(app_drawing());
    int n = (int)strlen(s), m = (int)strlen(WANT[k]);
    int ok = n >= m && !strcmp(s + n - m, WANT[k]);
    char what[96];

    sprintf(what, "%d 点目の読み出し", k);
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok) {
        printf("     got  [%s]\n", n >= m ? s + n - m : s);
        printf("     want [%s]\n", WANT[k]);
        fails++;
    }
}

int main(void)
{
    int i;

    app_resize(1264, 741);
    app_new();

    ck(app_command(32897) != 0, "測定 が出る");
    ck(jw_cmd() == JW_CMD_SOKUTEI, "  それが今の命令になる");
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
    app_command(32897);
    cktail(0);

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
