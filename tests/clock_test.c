/* クロックメニュー（左ボタン、src/clock.h）。
 *
 * 向きの割り方（FUN_004fc1d0）、左の表（FUN_0076c9c0 の AM・PM）、札の番号、
 * しきい（1054 Drag\Minimum 35）を越えて引いたら時計・内で離したらクリック、
 * 時計の間の右で AM/PM。逆コンパイルの読み、原典では押していない。答えは
 * 読みから出した数で見る。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/ui.h"
#include "../src/cmd.h"
#include "../src/clock.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* 時計の向きの真ん中へ r 画素（1 時は 30°） */
static void at_hour(int h, int r, int *dx, int *dy)
{
    double a = h * 30.0 * 3.141592653589793 / 180.0;

    *dx = (int)lround(sin(a) * r);
    *dy = (int)lround(-cos(a) * r);
}

static int dir_deg(double deg)
{
    double t = deg * 3.141592653589793 / 180.0;
    int am = 0, pd = 0;

    return clk_dir((int)lround(sin(t) * 1000), (int)lround(-cos(t) * 1000), &am, &pd, 0);
}

int main(void)
{
    rect_t r;
    int cx, cy, h, dx, dy, am, pd, ok, id;

    /* ---- 向き ---- */
    ok = 1;
    for (h = 1; h <= 12; h++) {
        am = 0;
        pd = 0;
        at_hour(h, 60, &dx, &dy);
        if (clk_dir(dx, dy, &am, &pd, 0) != h || am != 0)
            ok = 0;
    }
    ck(ok, "十二の向き（画面の上が 12 時、時計回り）");
    am = pd = 0;
    ck(clk_dir(0, -50, &am, &pd, 0) == 12, "真上は 12 時");
    am = pd = 0;
    ck(clk_dir(50, 0, &am, &pd, 0) == 3, "真右は 3 時");
    ck(dir_deg(14.0) == 12 && dir_deg(16.0) == 1 && dir_deg(344.0) == 11 && dir_deg(346.0) == 12,
       "境は 15°（角 + 90 が 15 未満なら 12、345 からも 12）");
    am = pd = 0;
    ck(clk_dir(0, 0, &am, &pd, 0) == CLK_NONE && am == 0, "押した点の上は 13（初めは AM のまま）");
    am = pd = 0;
    clk_dir(40, 0, &am, &pd, 0);
    ck(clk_dir(0, 0, &am, &pd, 0) == CLK_NONE && am == 1, "外から押した画素へ戻ると PM");
    clk_dir(0, 40, &am, &pd, 0);
    ck(clk_dir(0, 0, &am, &pd, 0) == CLK_NONE && am == 0, "もう一度戻ると AM");
    clk_dir(0, 40, &am, &pd, 0);
    ck(clk_dir(1, 0, &am, &pd, 0) == 3 && am == 0,
       "1 画素ずれた所は戻ったことにならない（DAT_00a0cae4 が 0）");
    ok = 1;
    for (h = 1; h <= 12; h++) {
        static const int to[13] = { 0, 12, 3, 3, 3, 6, 6, 6, 9, 9, 9, 12, 12 };

        am = 1;
        pd = 0;
        at_hour(h, 60, &dx, &dy);
        if (clk_dir(dx, dy, &am, &pd, 1) != to[h] || am != 0)
            ok = 0;
    }
    ck(ok, "1326 の寄せ: 11・1 は 12、2・4 は 3、5・7 は 6、8・10 は 9、AM に");

    /* ---- 表 ---- */
    ck(clk_cmd(1, 0, JW_CMD_SEN, 1) == JW_CMD_KUKEI && clk_cmd(1, 0, JW_CMD_ENKO, 1) == JW_CMD_SEN,
       "AM 1: 線 なら 矩形、ほかは 線");
    ck(clk_cmd(2, 0, 0, 1) == JW_CMD_ENKO && clk_cmd(3, 0, 0, 1) == JW_CMD_HOURAKU
       && clk_cmd(4, 0, 0, 1) == JW_CMD_HANI && clk_cmd(8, 0, 0, 1) == JW_CMD_SHINSHUKU
       && clk_cmd(9, 0, 0, 1) == JW_CMD_AUTO && clk_cmd(10, 0, 0, 1) == JW_CMD_SHOUKYO
       && clk_cmd(11, 0, 0, 1) == JW_CMD_FUKUSEN && clk_cmd(12, 0, 0, 1) == JW_CMD_MOJI,
       "AM 2〜4・8〜12: 円 包絡 範囲 伸縮 AUTO 消去 複線 文字");
    ck(clk_cmd(7, 0, 0, 1) == JW_CMD_FUKUSHA && clk_cmd(7, 0, 0, 0) == JW_CMD_IDOU,
       "AM 7: 前が複写なら 複写、移動なら 移動（view+0x9058）");
    ck(clk_cmd(6, 0, 0, 1) == CLK_ZOKU && clk_cmd(5, 0, 0, 1) == 0,
       "AM 6 属性取得、AM 5 線種変更 は入れていない");
    ck(clk_cmd(1, 1, 0, 1) == JW_CMD_KIGOU && clk_cmd(2, 1, 0, 1) == JW_CMD_KYOKUSEN
       && clk_cmd(3, 1, 0, 1) == JW_CMD_TATEGU_RITSU && clk_cmd(4, 1, 0, 1) == JW_CMD_TATEGU_DAN
       && clk_cmd(5, 1, 0, 1) == JW_CMD_TATEGU && clk_cmd(6, 1, 0, 1) == 0
       && clk_cmd(7, 1, 0, 1) == JW_CMD_HATCH && clk_cmd(8, 1, 0, 1) == JW_CMD_RENZOKU
       && clk_cmd(9, 1, 0, 1) == JW_CMD_CHUSHIN && clk_cmd(10, 1, 0, 1) == JW_CMD_NISEN
       && clk_cmd(11, 1, 0, 1) == JW_CMD_SUNPO && clk_cmd(12, 1, 0, 1) == JW_CMD_PARAM,
       "PM 1〜12: 線記号変形 曲線 建具立面 建具断面 建具平面 (全属性) ハッチ 連続線 中心線 ２線 寸法 ﾊﾟﾗﾒﾄﾘｯｸ");
    ck(clk_cmd(CLK_NONE, 0, 0, 1) == 0 && clk_cmd(CLK_NONE, 1, 0, 1) == 0, "13 は何もしない");
    clk_label(3, 0, &id);
    ck(id == 10003, "AM 3 の札は 10003（包絡）");
    clk_label(9, 0, &id);
    ck(id == 5199, "AM 9 の札は 5199 AUTO");
    clk_label(6, 1, &id);
    ck(id == 10026, "PM 6 の札は 10026【全】属性取得");
    clk_label(CLK_NONE, 1, &id);
    ck(id == 10013, "13 は キャンセル 10013");
    ck(clk_minimum() == 35, "しきいの既定は 35（1054）");

    /* ---- 押し離し ---- */
    ck(app_resize(1000, 700), "窓");
    app_new();
    app_fit();
    app_paint();
    ui_view_rect(1000, 700, &r);
    cx = r.x + r.w / 2;
    cy = r.y + r.h / 2;
    ck(jw_cmd() == JW_CMD_SEN, "初めは 線");
    ck(app_clock_possible(), "線 の間は 左が時計になりうる");
    ck(!app_clock_ready(cx, cy, cx + 35, cy) && !app_clock_ready(cx, cy, cx + 21, cy - 28),
       "距離 35 ちょうどまでは時計にならない（二乗 > 1225）");
    ck(app_clock_ready(cx, cy, cx + 36, cy), "36 で時計");

    /* 3 時（右）へ引いて離す: 包絡 */
    app_clock_begin(cx, cy);
    app_clock_move(cx + 36, cy);
    app_clock_move(cx + 80, cy + 5);
    ck(app_clock_active() && app_clock_now() == 3, "右へ引けば 3 時");
    ck(jw_cmd_notice_id() == 10003, "札 10003 が出る");
    app_paint();
    app_clock_end();
    ck(!app_clock_active() && jw_cmd() == JW_CMD_HOURAKU, "離すと 包絡");
    ck(jw_cmd_notice_id() == 0, "札は下りる");

    /* 1 時: 線 でないので 線、線からなら 矩形 */
    at_hour(1, 60, &dx, &dy);
    app_clock_begin(cx, cy);
    app_clock_move(cx + dx, cy + dy);
    app_clock_end();
    ck(jw_cmd() == JW_CMD_SEN, "AM 1（包絡から）で 線");
    app_clock_begin(cx, cy);
    app_clock_move(cx + dx, cy + dy);
    app_clock_end();
    ck(jw_cmd() == JW_CMD_KUKEI, "AM 1（線から）で 矩形");

    /* 右で PM: 3 時 → 建具立面 */
    app_clock_begin(cx, cy);
    app_clock_move(cx + 60, cy);
    ck(app_clock_right() && app_clock_pm() == 1, "時計の間の右で PM");
    ck(jw_cmd_notice_id() == 5165, "札は 5165 建具立面 に替わる");
    app_clock_end();
    ck(jw_cmd() == JW_CMD_TATEGU_RITSU, "離すと 建具立面");
    ck(app_clock_pm() == 0, "2108 が切なので 次は AM から");

    /* 押した点へ戻して PM、12 時 → ﾊﾟﾗﾒﾄﾘｯｸ */
    app_clock_begin(cx, cy);
    app_clock_move(cx, cy - 50);
    app_clock_move(cx, cy);
    ck(app_clock_now() == CLK_NONE && app_clock_pm() == 1, "押した画素へ戻すと PM（13）");
    ck(jw_cmd_notice_id() == 10013, "札は キャンセル");
    app_clock_move(cx, cy - 50);
    app_clock_end();
    ck(jw_cmd() == JW_CMD_PARAM, "PM 12 で ﾊﾟﾗﾒﾄﾘｯｸ変形");

    /* やめれば何もしない */
    app_command(JW_CMD_SEN);
    app_clock_begin(cx, cy);
    app_clock_move(cx + 50, cy);
    app_clock_cancel();
    ck(jw_cmd() == JW_CMD_SEN && !app_clock_active(), "やめれば命令はそのまま");

    /* 13 で離しても何もしない */
    app_clock_begin(cx, cy);
    app_clock_move(cx + 50, cy);
    app_clock_move(cx, cy);
    app_clock_end();
    ck(jw_cmd() == JW_CMD_SEN, "13（キャンセル）で離せば命令はそのまま");

    /* AUTO の間は時計にしない（AUTO 自前の時計は入れていない） */
    app_command(JW_CMD_AUTO);
    ck(!app_clock_possible() && !app_clock_ready(cx, cy, cx + 100, cy), "AUTO の間は時計にしない");
    app_command(JW_CMD_SEN);

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
