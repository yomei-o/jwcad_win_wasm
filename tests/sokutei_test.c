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
 * 座標測定 (1066) も入りました —— 原点を置くと、そこからの**マウスの
 * 今の位置**を 【 x , y 】 で映します。`m<x>,<y>` で本物のカーソルを
 * 動かして読みました（`tools/probe141.sh`）。
 *
 * ○単独円指定 (1068) も入りました —— 押すと問いかけが
 * 「円を指示してください。」になり（読み出しは**消えます**）、次の一手で
 * 円を一つ指すとその**周長**が合計に入ります。半径 100 画素の円で
 * 【 38.468ｍ 】 38.4685ｍ、つまり 2πr。指したあとは印が下りて、次の
 * クリックはふつうの一点目です。楕円・円弧・面積測定 と組んだときは
 * 訊いていません。
 *
 * 測定結果書込 (1071) も入りました —— 押すと**走っていた測りが 0 に
 * 戻り**、問いかけが「文字の位置を指示して下さい」になります。次の
 * クリックで、そのときの読み出しの数が文字として置かれます。合計
 * 24.490 のときに押しても書かれるのは `0.000ｍ` で、三度試して三度とも
 * そうでした（`decomp/res/sokutei_write2.jww`）。
 *
 * 角度測定 の**途中の数**だけはマウス任せのままで、そこは合わせて
 * いません。書込設定 (1072) は押しても何も変わりませんでした。
 *
 * 四つの 〜測定 のうちどれが選ばれているかを、原典は**何も印して
 * いません** —— バーを撮り比べると動くのは Windows の点線の焦点枠だけ
 * でした（`tools/probe141.sh`）。移植は焦点枠を描かないので、ここは
 * 差が出ません。
 */
#include <stdio.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"

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
/* 座標測定: before the origin, and then the cursor at three places */
static const char *const XY[] = {
    "      S = 1 / 100  \x81y 0.000\x82\x8d , 0.000\x82\x8d \x81z",
    "      S = 1 / 100  \x81y 12.245\x82\x8d , -6.122\x82\x8d \x81z",
    "      S = 1 / 100  \x81y 24.490\x82\x8d , 0.000\x82\x8d \x81z",
};

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

    /* ------------------------------------------------ ○単独円指定 --- */
    {
        rect_t vr;
        jw_drawing *dr;

        app_new();
        app_resize(1264, 741);
        ui_view_rect(1264, 741, &vr);
        dr = (jw_drawing *)app_drawing();
        app_command(JW_CMD_ENKO);
        app_press(vr.x + 500, vr.y + 400, 0);
        app_press(vr.x + 600, vr.y + 400, 0);
        ck(dr->ndrawn == 1, "半径 100 画素の円を一つ引く");
        app_command(32897);
        bar(1068);
        ck(strstr(jw_cmd_status(dr), "S = 1 /") == 0,
           "○単独円指定 を押すと読み出しが消える");
        app_press(vr.x + 600, vr.y + 400, 0);
        cktext("      S = 1 / 100  \x81y 38.468\x82\x8d \x81z   38.4685\x82\x8d",
               "  円を指すと周長 2πr が合計に入る");
        app_press(vr.x + 500, vr.y + 400, 0);
        cktext("      S = 1 / 100  \x81y 38.468\x82\x8d \x81z   38.4685\x82\x8d",
               "  印は下り、次のクリックはふつうの一点目");
    }

    /* ------------------------------------------------ 測定結果書込 --- */
    {
        rect_t vr;
        jw_drawing *dr;
        const jw_obj *o = 0;
        int i;

        app_new();
        app_resize(1264, 741);
        ui_view_rect(1264, 741, &vr);
        dr = (jw_drawing *)app_drawing();
        app_command(32897);
        app_press(vr.x + 300, vr.y + 300, 0);
        app_press(vr.x + 700, vr.y + 300, 0);
        cktext(WANT[2], "測定結果書込: 24.490 まで測って");
        bar(1071);
        cktext(WANT[0], "  押すと測りが 0 に戻り");
        ck(strstr(jw_cmd_status(dr), "\x95\xb6\x8e\x9a\x82\xcc\x88\xca\x92\x75") != 0,
           "  文字の位置を訊いてくる");
        app_press(vr.x + 300, vr.y + 300, 0);
        for (i = 0; i < dr->ndrawn; i++)
            if (dr->obj[i].cls == JW_MOJI)
                o = &dr->obj[i];
        ck(o != 0, "  クリックした所に文字が置かれる");
        if (o) {
            ck(!strcmp(jw_str(dr, o->text), "0.000\x82\x8d"),
               "    中身は 0.000ｍ（原典もそう書きます）");
            ck(o->n == 2 && o->d[4] == 2.5 && o->d[5] == 2.5,
               "    文字種 2・高さ 2.5・幅 2.5");
            ck(o->d[2] - o->d[0] > 8.74 && o->d[2] - o->d[0] < 8.76,
               "    走りは 8.75 mm");
            ck((o->flags & 0x4000u) != 0 && o->ltype == 1,
               "    flags 0x4000・種類 1");
        }
        cktext(WANT[0], "  そのあとは 始点 から測り直し");
    }

    /* ------------------------------------------------------ 座標測定 --- */
    {
        rect_t vr;

        app_new();
        app_resize(1264, 741);
        app_command(32897);
        bar(1066);
        ck(jw_cmd_sokutei_mode() == 1066, "座標測定 を選べる");
        cktext(XY[0], "  原点を置く前は 0, 0");
        ui_view_rect(1264, 741, &vr);
        app_press(vr.x + 300, vr.y + 300, 0);
        cktext(XY[0], "  原点を置いた直後も 0, 0");
        app_move(vr.x + 500, vr.y + 400);
        cktext(XY[1], "  カーソル (500,400) で 12.245, -6.122");
        app_move(vr.x + 700, vr.y + 300);
        cktext(XY[2], "  カーソル (700,300) で 24.490, 0.000");
        app_move(vr.x + 300, vr.y + 300);
        cktext(XY[0], "  原点へ戻ると 0, 0");
        ck(app_drawing()->ndrawn == 0, "  座標測定も図面に何も足さない");
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
