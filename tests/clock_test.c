/* クロックメニュー（左ボタン・右ボタン、src/clock.h）。
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
#include "../src/jww.h"
#include "../src/gen/prompts.h"

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

/* 基本設定（tests/kihon3_test.c と同じ手） */
static int hit(int want)
{
    const fb_t *fb = app_fb();
    int x, y;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == want) {
                app_press(x, y, 0);
                return 1;
            }
    return 0;
}

static int kh_press(int tab, int id)
{
    if (!app_kihon_open())
        app_command(32891);
    if (!app_kihon_open())
        return 0;
    if (app_kihon_tab() != tab && !hit(-tab - 1))
        return 0;
    return hit(id);
}

static void kh_ok(void)
{
    if (app_kihon_open())
        hit(1);
}

static int kh_type(int tab, int id, const char *s)
{
    if (!kh_press(tab, id))
        return 0;
    while (*s)
        app_key((unsigned char)*s++);
    return 1;
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
    ck(clk_cmd(6, 0, 0, 1) == CLK_ZOKU && clk_cmd(5, 0, 0, 1) == CLK_SENSHU,
       "AM 6 属性取得、AM 5 線種変更");
    ck(clk_cmd(1, 1, 0, 1) == JW_CMD_KIGOU && clk_cmd(2, 1, 0, 1) == JW_CMD_KYOKUSEN
       && clk_cmd(3, 1, 0, 1) == JW_CMD_TATEGU_RITSU && clk_cmd(4, 1, 0, 1) == JW_CMD_TATEGU_DAN
       && clk_cmd(5, 1, 0, 1) == JW_CMD_TATEGU && clk_cmd(6, 1, 0, 1) == CLK_ZOKUALL
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
    /* 包絡の終点の状態行（FUN_00683e00）: 1326 が切なら 5704、入なら 5705 */
    app_press(cx, cy, 0);
    ck(strstr(jw_cmd_prompt(), JW_STR_5704) != NULL, "包絡の終点: 5704 (Shift+L) (Ｌ←)中間消去");
    jw_cmd_nonclock_set(1);
    ck(strstr(jw_cmd_prompt(), JW_STR_5705) != NULL && !strstr(jw_cmd_prompt(), JW_STR_5704),
       "1326 が入なら 5705");
    jw_cmd_nonclock_set(0);
    jw_cmd_set(JW_CMD_HOURAKU);

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

    /* AM 4 範囲選択: 押した点が箱の一つ目の角（原典で測った）。線を一本引き、
       その左上で 4 時へ引いて離し、右下を押すと その線が入る。押した点が線の
       あとなら 入らない */
    app_command(JW_CMD_SEN);
    app_press(cx - 100, cy - 100, 0);
    app_press(cx - 50, cy - 60, 0);
    app_command(JW_CMD_SEN);
    at_hour(4, 60, &dx, &dy);
    app_clock_begin(cx - 150, cy - 150);
    app_clock_move(cx - 150 + dx, cy - 150 + dy);
    ck(app_clock_now() == 4, "4 時");
    app_clock_end();
    ck(jw_cmd() == JW_CMD_HANI,
       "AM 4: 範囲選択 の終点待ち（押した点が一つ目）");
    app_press(cx + 100, cy + 100, 0);
    ck(jw_cmd_sel_count(app_drawing()) == 1, "押した点から終点までの箱に線が入る");
    /* 選択のあとに押し直すと 前の選択は消え 新しい一つ目 */
    app_clock_begin(cx - 70, cy - 150);
    app_clock_move(cx - 70 + dx, cy - 150 + dy);
    app_clock_end();
    ck(jw_cmd() == JW_CMD_HANI
       && jw_cmd_sel_count(app_drawing()) == 0, "選択のあと: 前の選択は消え 新しい一つ目");
    app_press(cx + 100, cy + 100, 0);
    ck(jw_cmd_sel_count(app_drawing()) == 0, "押した点が線のあとなら 入らない");
    app_command(JW_CMD_SEN);

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

    /* ---- 基本設定 1326・1054・2108 ---- */
    ck(kh_press(0, 1326), "1326 クロックメニューを使用しない を押す");
    kh_ok();
    ck(!app_kihon_open() && !app_clock_possible() && !app_clock_ready(cx, cy, cx + 200, cy),
       "1326 が入なら 左は時計にならない（前のとおり 3 画素で渡す）");
    kh_press(0, 1326);
    kh_ok();
    ck(app_clock_possible(), "切に戻せば また時計");
    ck(kh_type(0, 1054, "50"), "1054 に 50");
    kh_ok();
    ck(clk_minimum() == 50 && !app_clock_ready(cx, cy, cx + 50, cy) && app_clock_ready(cx, cy, cx + 51, cy),
       "1054 50: 距離 50 までは時計にならない");
    ck(kh_type(0, 1054, "10"), "1054 に 10");
    kh_ok();
    ck(clk_minimum() == 50, "|箱| が 20 未満なら入れない（前の 50 のまま）");
    kh_type(0, 1054, "35");
    kh_ok();
    ck(kh_press(0, 2108), "2108 左クロックメニュー開始の AM/PM は前操作状態");
    kh_ok();
    app_clock_begin(cx, cy);
    app_clock_move(cx + 60, cy);
    app_clock_right();
    app_clock_cancel();
    ck(app_clock_pm() == 1, "2108 が入なら PM が残る");
    app_clock_begin(cx, cy);
    app_clock_move(cx + 60, cy);
    ck(jw_cmd_notice_id() == 5165, "次の時計は PM から（3 時 建具立面）");
    app_clock_right();
    app_clock_cancel();
    kh_press(0, 2108);
    kh_ok();
    ck(app_clock_pm() == 0, "AM に戻した");

    /* ---- 分割の受け手（FUN_007637e0）---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        int i;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
        o = jw_add(d, JW_SEN);
        o->d[0] = 0; o->d[1] = 100; o->d[2] = 100; o->d[3] = 100;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_BUNKATSU);
        jw_cmd_box_click(1411);
        for (i = 0; i < 24; i++)
            jw_cmd_box_key(8);
        jw_cmd_box_key('3');
        jw_cmd_box_key(13);

        /* 線（Ａ）の前は 既定の表: 3 時 包絡 の札 */
        app_clock_begin(cx, cy);
        app_clock_move(cx + 60, cy);
        ck(jw_cmd_notice_id() == 10003, "分割: Ａの前の 3 時は 既定の表（包絡）");
        app_clock_cancel();

        jw_cmd_point(d, v, 50, 0, 0);
        ck(jw_cmd_bunkatsu_a() && jw_cmd_bunkatsu_hojo(), "線（Ａ）を指した");
        at_hour(1, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 5611, "Ａのあとの 1 時は 札 5611 逆分割");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_BUNKATSU && jw_cmd_notice_id() == 5611 && jw_cmd_bunkatsu_a(),
           "離すと 逆分割（バーの 1066 と同じ、命令はそのまま）");
        {   /* 逆分割になったか: Ｂを指すと交差に組む（tests/bunkatsu_test.c と同じ形） */
            int g = d->ndrawn;

            jw_cmd_point(d, v, 50, 100, 0);
            ck(d->ndrawn == g + 2 && fabs(d->obj[g].d[1] - 100.0 / 3) < 1e-6
               && fabs(d->obj[g].d[3] - 100.0 / 3) < 1e-6
               && fabs(fmin(d->obj[g].d[0], d->obj[g].d[2]) - 100.0 / 3) < 1e-6,
               "Ｂを指すと 逆分割の線（交差に組む）");
        }
        jw_cmd_point(d, v, 50, 0, 0);
        at_hour(2, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 5612, "2 時は 札 5612 線長割合分割");
        app_clock_move(cx + 60, cy);
        ck(jw_cmd_notice_id() == 5609, "3 時は 札 5609 馬目地分割");
        {   /* 離すと 縦分割数の窓の依頼（バーの 1065 と同じ） */
            int um = 0, okk;

            app_clock_end();
            okk = jw_cmd_bunkatsu_umeji_ask(&um);
            ck(okk, "3 時で離すと 馬目地の縦分割数の窓を出す");
            jw_cmd_bunkatsu_umeji_set(0);
            app_clock_begin(cx, cy);
            app_clock_move(cx, cy - 60);
        }
        app_clock_move(cx, cy - 60);
        ck(jw_cmd_notice_id() == 10035, "12 時は 札 10035 線属性設定");
        app_clock_move(cx - 60, cy);
        ck(jw_cmd_notice_id() == 10009 || jw_cmd_notice_id() == 5199, "9 時は 既定の表（AUTO）");
        app_clock_move(cx, cy - 60);
        app_clock_end();
        ck(app_zoku_open(), "12 時で離すと 線属性 の窓");
        app_key(27);
    }

    /* ---- PM 6【全】属性取得（FUN_007751e0(1)）: 線の傾き・寸法の箱へ ---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        int px, py;
        int dx2, dy2;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 100;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_SEN);
        px = jw_sx(v, 50.0);
        py = jw_sy(v, 50.0);
        at_hour(6, 60, &dx2, &dy2);
        app_clock_begin(px, py);
        app_clock_right();
        app_clock_move(px + dx2, py + dy2);
        ck(app_clock_pm() == 1 && jw_cmd_notice_id() == 10026, "PM 6 の札 10026");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_SEN, "PM 6: 命令は線のまま");
        ck(fabs(atof(jw_cmd_box(1411)) - 45.0) < 1e-6, "PM 6: 傾きの箱に 45");
        printf("len box [%s]\n", jw_cmd_box(1412));
        ck(fabs(atof(jw_cmd_box(1412)) - 14142.13562) < 1e-3, "PM 6: 寸法の箱に 長さ × 縮尺（1/100）");
    }

    /* ---- PM 6【全】属性取得: 命令が 円（FUN_006485b0）・複線（FUN_0065c360）のとき ---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        int px, py, dx2, dy2;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_ENKO);
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 50; o->d[3] = 0; o->d[4] = 6.283185307179586;
        o->d[5] = 0; o->d[6] = 0.5;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_ENKO);
        px = jw_sx(v, 50.0);
        py = jw_sy(v, 0.0);
        at_hour(6, 60, &dx2, &dy2);
        app_clock_begin(px, py);
        app_clock_right();
        app_clock_move(px + dx2, py + dy2);
        app_clock_end();
        ck(jw_cmd() == JW_CMD_ENKO, "PM 6 円: 命令は円のまま");
        ck(fabs(atof(jw_cmd_box(1413))) < 1e-6, "PM 6 円: 傾きの箱 0");
        ck(fabs(atof(jw_cmd_box(1411)) - 5000.0) < 1e-3, "PM 6 円: 半径の箱 半径 × 縮尺");
        ck(fabs(atof(jw_cmd_box(1412)) - 50.0) < 1e-6, "PM 6 円: 扁平率の箱 50");

        jw_cmd_m_input(1);
        app_command(JW_CMD_ENKO);
        app_clock_begin(px, py);
        app_clock_right();
        app_clock_move(px + dx2, py + dy2);
        app_clock_end();
        ck(fabs(atof(jw_cmd_box(1411)) - 5000.0) < 1e-3, "PM 6 円 ｍ: 読みの箱は ×1000 で元の長さ");
        ck(fabs(atof(jw_cmd_box_raw(1411)) - 5.0) < 1e-6, "PM 6 円 ｍ: 箱の字は ÷1000");
        jw_cmd_m_input(0);
    }

    /* ---- PM 6【全】属性取得: 命令が 文字（FUN_006c4840）のとき 押した字の文字種 ---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        int px, py, dx2, dy2;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_MOJI);
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 30; o->d[3] = 0;
        o->d[4] = 7.0; o->d[5] = 9.0; o->d[6] = 1.5; o->d[7] = 0.0;
        o->color = 4;
        o->text = jw_add_str(d, "ABC");
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_MOJI);
        d->cur_style.w = 1.0;
        d->cur_style.h = 1.0;
        d->cur_style.sp = 0.0;
        d->cur_style.color = 1;
        px = jw_sx(v, 15.0);
        py = jw_sy(v, 0.0);
        at_hour(6, 60, &dx2, &dy2);
        app_clock_begin(px, py);
        app_clock_right();
        app_clock_move(px + dx2, py + dy2);
        app_clock_end();
        ck(jw_cmd() == JW_CMD_MOJI, "PM 6 文字: 命令は文字のまま");
        ck(d->cur_style.w == 7.0 && d->cur_style.h == 9.0 && d->cur_style.sp == 1.5
           && d->cur_style.color == 4, "PM 6 文字: 大きさ・間隔・色を取る");
        ck(jw_cmd_line()[0] == 0, "PM 6 文字: 字の中身は箱へ入れない");
    }

    /* ---- AM 5 線種変更（FUN_0076e360）---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        int px, py, wg = 0, g, wl, n;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
        o = jw_add(d, JW_SEN);
        o->d[0] = 0; o->d[1] = 100; o->d[2] = 100; o->d[3] = 100;
        for (g = 0; g < 16; g++)
            if (d->group[g].state == 3)
                wg = g;
        wl = d->group[wg].write_layer & 15;
        d->obj[0].ltype = 1; d->obj[0].color = 2; d->obj[0].width = 0;
        d->obj[0].layer = (unsigned short)((wl + 3) & 15);
        d->write_ltype = 3; d->write_color = 5; d->write_width = 7;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_FUKUSEN);
        px = jw_sx(v, 30.0);
        py = jw_sy(v, 0.0);
        at_hour(5, 60, &dx, &dy);
        app_clock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        ck(jw_cmd_notice_id() == 10005, "AM 5 の札 10005 線種変更");
        n = d->ndrawn;
        app_clock_end();
        o = &d->obj[d->ndrawn - 1];
        ck(jw_cmd() == JW_CMD_FUKUSEN && d->ndrawn == n, "AM 5: 命令はそのまま、数は同じ");
        ck(o->d[1] == 0.0 && o->d[3] == 0.0 && o->ltype == 3 && o->color == 5 && o->width == 7
           && o->layer == wl && o->lgroup == wg,
           "押した線が 書込み線（線種・線色・線幅）と書込みレイヤになって終わりへ");
        ck(d->obj[0].d[1] == 100.0, "もう一本は先頭へ詰まる");
        jw_cmd_undo(d);
        ck(d->obj[0].d[1] == 0.0 && d->obj[0].ltype == 1 && d->obj[0].layer == ((wl + 3) & 15),
           "戻るで元の線・元の場所に");

        /* 1523 が入なら レイヤは元のまま、札 6004 */
        ck(kh_press(1, 1523), "1523 AM5 の線種変更でレイヤは変更しない を押す");
        kh_ok();
        app_clock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        app_clock_end();
        o = &d->obj[d->ndrawn - 1];
        ck(o->d[1] == 0.0 && o->ltype == 3 && o->color == 5 && o->layer == ((wl + 3) & 15),
           "1523: 線種・線色は替わり、レイヤは元のまま");
        ck(jw_cmd_notice_id() == 6004, "1523: 札 6004 レイヤ変更なし");
        kh_press(1, 1523);
        kh_ok();

        /* 何も無い所なら何もしない */
        n = d->ndrawn;
        app_clock_begin(jw_sx(v, 50.0), jw_sy(v, 50.0));
        app_clock_move(jw_sx(v, 50.0) + dx, jw_sy(v, 50.0) + dy);
        app_clock_end();
        ck(d->ndrawn == n && d->obj[0].d[1] == 100.0, "要素の無い所では何もしない");
        app_command(JW_CMD_SEN);
    }

    /* 寸法図形（sub 1〜8 の一続き）は 一つの図形として 終わりへ */
    {
        jw_drawing *d;
        const jw_view *v;
        int f = -1, k, wg = 0, wl, ok8, px, py, e;

        app_new();
        d = (jw_drawing *)app_drawing();
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = 100; o->d[1] = 100; o->d[2] = 200; o->d[3] = 100;
        app_fit();
        app_paint();
        v = app_view();
        jw_cmd_sunpo_chk_set(2424, 1);
        jw_cmd_set(JW_CMD_SUNPO);
        jw_cmd_point(d, v, 100.0, 120.0, 0);
        jw_cmd_point(d, v, 100.0, 110.0, 0);
        jw_cmd_point(d, v, 100.0, 100.0, 0);
        jw_cmd_point(d, v, 200.0, 100.0, 0);
        jw_cmd_set(JW_CMD_SEN);
        jw_cmd_sunpo_chk_set(2424, 0);
        for (k = 0; k + 7 < d->ndrawn; k++)
            if (d->obj[k].sub == 1 && d->obj[k + 7].sub == 8)
                f = k;
        ck(f >= 0, "寸法図形を作った");
        for (k = 0; k < 16; k++)
            if (d->group[k].state == 3)
                wg = k;
        wl = d->group[wg].write_layer & 15;
        for (k = 0; f >= 0 && k < 8; k++)
            d->obj[f + k].layer = (unsigned short)((wl + 2) & 15);
        d->write_ltype = 4; d->write_color = 6; d->write_width = 0;
        e = f >= 0 ? d->ndrawn - 8 : 0;
        if (f >= 0) {
            px = jw_sx(v, (d->obj[f].d[0] + d->obj[f].d[2]) / 2);
            py = jw_sy(v, (d->obj[f].d[1] + d->obj[f].d[3]) / 2);
            at_hour(5, 60, &dx, &dy);
            app_clock_begin(px, py);
            app_clock_move(px + dx, py + dy);
            app_clock_end();
        }
        ok8 = f >= 0;
        for (k = 0; ok8 && k < 8; k++)
            if (d->obj[e + k].sub != k + 1 || d->obj[e + k].layer != wl)
                ok8 = 0;
        ck(ok8, "寸法図形: 部品 1〜8 が一続きのまま終わりへ、レイヤは書込みレイヤ");
        ck(ok8 && d->obj[e].ltype == 4 && d->obj[e].color == 6
           && (d->obj[e].mark & 0xff) == 4 && ((d->obj[e].mark >> 8) & 0xffff) == 6
           && (((unsigned)d->obj[e].list[2] >> 16) & 0xffff) == (unsigned)wl,
           "寸法図形: 頭と寸法線が書込み線種・線色に");
        jw_cmd_undo(d);
        ck(f >= 0 && d->obj[f].sub == 1 && d->obj[f + 7].sub == 8 && d->obj[f].layer == ((wl + 2) & 15),
           "寸法図形: 戻るで元に");
    }

    /* ---- 右ボタンの時計（FUN_0076d330、src/clock.h） ---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        double qx, qy, k2 = 0.7071067811865476;
        int px, py, n;

        /* 円・円弧の向きの点（FUN_005f92e0・FUN_0045b790）: 1/4 点は小さい方の成分を 0 に */
        {
            jw_obj c;

            memset(&c, 0, sizeof c);
            c.cls = JW_ENKO;
            c.d[2] = 10.0;
            c.d[4] = 6.283185307179586;
            c.d[6] = 1.0;
            ck(clk_circle_pt(&c, 3, 8, 0, 0, &qx, &qy) && fabs(qx) < 1e-9 && fabs(qy - 10) < 1e-9,
               "円の 1/4 点: (3,8) は 真上 (0,10)");
            ck(clk_circle_pt(&c, 8, -3, 0, 0, &qx, &qy) && fabs(qx - 10) < 1e-9 && fabs(qy) < 1e-9,
               "円の 1/4 点: (8,-3) は 右 (10,0)");
            ck(clk_circle_pt(&c, 6, 5, 0, 1, &qx, &qy) && fabs(qx - 10 * k2) < 1e-9
               && fabs(qy - 10 * k2) < 1e-9, "1/8 点: (6,5) は 差が大きい方の半分より近いので 斜め");
            ck(clk_circle_pt(&c, -6, -5, 0, 1, &qx, &qy) && fabs(qx + 10 * k2) < 1e-9
               && fabs(qy + 10 * k2) < 1e-9, "1/8 点: (-6,-5) は 左下の斜め");
            ck(clk_circle_pt(&c, 10, 1, 0, 1, &qx, &qy) && fabs(qx - 10) < 1e-9 && fabs(qy) < 1e-9,
               "1/8 点: (10,1) は 軸の上");
            ck(clk_circle_pt(&c, 4.33012701892219 - 0.25, 2.5 + 0.43301270189222, 30, 0, &qx, &qy)
               && fabs(qx - 8.660254037844386) < 1e-6 && fabs(qy - 5) < 1e-6,
               "軸角 30° の枠で 1/4 点（その向きの軸の上）");
            ck(!clk_circle_pt(&c, 0, 0, 0, 0, &qx, &qy), "中心の上は 点が出ない");
            c.d[6] = 0.5;
            ck(clk_circle_pt(&c, 3, 8, 0, 0, &qx, &qy) && fabs(qx) < 1e-9 && fabs(qy - 5) < 1e-9,
               "楕円（扁平率 0.5）の 真上は (0,5)");
        }

        app_new();
        d = (jw_drawing *)app_drawing();
        app_fit();
        app_paint();
        v = app_view();
        ui_view_rect(1000, 700, &r);
        cx = r.x + r.w / 2;
        cy = r.y + r.h / 2;

        /* しきい: 1326 が切なら左と同じ。入なら左は時計にならず、右は時計になる */
        app_command(JW_CMD_SEN);
        ck(app_rclock_possible() && app_rclock_ready(cx, cy, cx + 36, cy)
           && !app_rclock_ready(cx, cy, cx + 35, cy), "右も 35 画素を越えれば時計");
        clk_settings(1, 35, 0, 0, 0);
        ck(!app_clock_possible() && app_rclock_possible()
           && app_rclock_ready(cx, cy, cx + 36, cy), "1326 が入: 左は時計にならず 右は時計（FUN_005185e0）");
        clk_settings(0, 35, 0, 0, 0);

        /* AM 4 戻る・5 進む（札 10105・10106、FUN_00504100・FUN_00503e90） */
        jw_cmd_point(d, v, 100.0, 100.0, 0);
        jw_cmd_point(d, v, 200.0, 100.0, 0);
        ck(d->ndrawn == 1, "線を一本引いた");
        at_hour(4, 60, &dx, &dy);
        app_rclock_begin(cx, cy);
        ck(app_clock_active() && app_clock_button() == 1, "右の時計が始まる");
        app_clock_move(cx + dx, cy + dy);
        ck(app_clock_now() == 4 && jw_cmd_notice_id() == 10105, "右 AM 4 の札 10105 戻る");
        app_clock_end();
        ck(!app_clock_active() && d->ndrawn == 0 && jw_cmd_notice_id() == 0, "右 AM 4 を離すと 戻る");
        at_hour(5, 60, &dx, &dy);
        app_rclock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10106, "右 AM 5 の札 10106 進む");
        app_clock_end();
        ck(d->ndrawn == 1 && jw_cmd() == JW_CMD_SEN, "右 AM 5 を離すと 進む（命令はそのまま）");

        /* 札: AM 3・6・9・12、PM、左の表へ回る時 */
        app_rclock_begin(cx, cy);
        at_hour(3, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10101, "右 AM 3 の札 10101 中心点・A点");
        at_hour(6, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10103, "右 AM 6 の札 10103 オフセット");
        at_hour(9, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10102, "右 AM 9 の札 10102 線上点・交点");
        at_hour(12, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10104, "右 AM 12 の札 10104 円周1/4点");
        at_hour(2, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10002, "右 AM 2 は 左の表の札 10002（円）");
        /* 左が押されると 右の AM/PM が替わる（FUN_00507d00） */
        ck(app_clock_right() && app_clock_pm() == 1, "右の時計の間の左で 右が PM");
        ck(jw_cmd_notice_id() == 10014, "右 PM 2 の札 10014 ２点間角");
        app_clock_end();
        ck(app_clock_pm() == 0, "離すと 右の AM/PM は 2109 が切なので AM に戻る");
        app_rclock_begin(cx, cy);
        app_clock_right();
        at_hour(1, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10022, "右 PM 1 の札 10022 鉛直角");
        at_hour(12, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10031, "右 PM 12 の札 10031 数値 長");
        at_hour(5, 60, &dx, &dy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10020, "右 PM 5 の札 10020 軸角取得");
        app_clock_cancel();
        ck(!app_clock_active() && app_clock_pm() == 0, "やめると 右の AM/PM も戻る");
        /* 左の時計の AM/PM とは別 */
        app_clock_begin(cx, cy);
        ck(app_clock_button() == 0 && app_clock_right() && app_clock_pm() == 1, "左の時計の右は 左の AM/PM");
        app_clock_cancel();

        /* 12 時: 円の 1/4 点（FUN_0076efd0）。点 の命令に 左の点として渡る */
        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_ENKO);
        o->d[0] = 100; o->d[1] = 100; o->d[2] = 50; o->d[3] = 0; o->d[4] = 6.283185307179586;
        o->d[5] = 0; o->d[6] = 1;
        o = jw_add(d, JW_SEN);
        o->d[0] = 10; o->d[1] = 20; o->d[2] = 200; o->d[3] = 20;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_TEN);
        n = d->ndrawn;
        px = jw_sx(v, 103.0);
        py = jw_sy(v, 149.0);
        app_rclock_begin(px, py);
        at_hour(12, 60, &dx, &dy);
        app_clock_move(px + dx, py + dy);
        ck(jw_cmd_notice_id() == 10104, "点: 右 12 時の札");
        app_clock_end();
        ck(d->ndrawn == n + 1 && d->obj[n].cls == JW_TEN
           && fabs(d->obj[n].d[0] - 100.0) < 1e-6 && fabs(d->obj[n].d[1] - 150.0) < 1e-6,
           "円の上を 3 mm 横ずれで押して 12 時 → 真上の 1/4 点 (100,150) に 点");
        n = d->ndrawn;
        px = jw_sx(v, 50.0);
        py = jw_sy(v, 21.0);
        app_rclock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        app_clock_end();
        ck(d->ndrawn == n && jw_cmd_notice_id() == 10110, "線を押して 12 時 → 札 10110 円ではありません、何も置かない");
        n = d->ndrawn;
        px = jw_sx(v, 300.0);
        py = jw_sy(v, 250.0);
        app_rclock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        app_clock_end();
        ck(d->ndrawn == n, "何も無い所の 12 時は 何もしない");
        clk_settings(0, 35, 0, 0, 1);
        px = jw_sx(v, 100.0 + 50.0 * k2 + 1.0);
        py = jw_sy(v, 100.0 + 50.0 * k2 + 0.5);
        app_rclock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        ck(jw_cmd_notice_id() == 10123, "2099 が入: 札 10123 円周1/8点");
        n = d->ndrawn;
        app_clock_end();
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - (100.0 + 50.0 * k2)) < 1e-6
           && fabs(d->obj[n].d[1] - (100.0 + 50.0 * k2)) < 1e-6,
           "2099: 斜めの 1/8 点に 点");
        clk_settings(0, 35, 0, 0, 0);
        app_command(JW_CMD_SEN);
        n = d->ndrawn;
        px = jw_sx(v, 103.0);
        py = jw_sy(v, 149.0);
        app_rclock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        app_clock_end();
        ck(d->ndrawn == n && jw_cmd() == JW_CMD_SEN, "線 の 12 時は 何もしない（FUN_006f3490 は読んでいない）");
        app_command(JW_CMD_SEN);

        /* 右 AM 3 中心点・A点 と AM 9 線上点・交点（FUN_0076ea20・FUN_0076fae0）。
           読みを固定する試験（逆コンパイルの読み、原典では押していない）:
           点は 命令へ 左の点として届く（view+0x85d0 → 仮想関数 9 の 0x231d） */
        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = 10; o->d[1] = 20; o->d[2] = 200; o->d[3] = 20;
        o = jw_add(d, JW_SEN);
        o->d[0] = 50; o->d[1] = 0; o->d[2] = 50; o->d[3] = 200;
        o = jw_add(d, JW_ENKO);
        o->d[0] = 150; o->d[1] = 150; o->d[2] = 30; o->d[3] = 0; o->d[4] = 6.283185307179586;
        o->d[5] = 0; o->d[6] = 1;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_TEN);
#define AMRUN(h, X, Y) do { px = jw_sx(v, (X)); py = jw_sy(v, (Y)); \
            app_rclock_begin(px, py); at_hour((h), 60, &dx, &dy); \
            app_clock_move(px + dx, py + dy); app_clock_end(); } while (0)
        /* AM 3: 線の途中（読めない所）→ 二端の中点 */
        n = d->ndrawn;
        AMRUN(3, 150.0, 21.0);
        ck(d->ndrawn == n + 1 && d->obj[n].cls == JW_TEN
           && fabs(d->obj[n].d[0] - 105.0) < 1e-6 && fabs(d->obj[n].d[1] - 20.0) < 1e-6,
           "AM 3: 線の途中で離す → 線の中点 (105,20) に 点（FUN_004497b0 → 仮想関数 11）");
        /* 円 → 中心 */
        n = d->ndrawn;
        AMRUN(3, 150.0 + 30.0 * 0.7071, 150.0 + 30.0 * 0.7071);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 150.0) < 1e-6
           && fabs(d->obj[n].d[1] - 150.0) < 1e-6, "AM 3: 円を押して → 中心 (150,150) に 点");
        /* 何もない所 → 何もしない */
        n = d->ndrawn;
        AMRUN(3, 300.0, 250.0);
        ck(d->ndrawn == n, "AM 3: 何も無い所は 何もしない");
        /* 読取点（線の端 (10,20)）→ 点は出ず、二点目待ち（状態行 10107） */
        n = d->ndrawn;
        AMRUN(3, 10.2, 20.1);
        ck(d->ndrawn == n && strcmp(jw_cmd_prompt(), JW_STR_10107) == 0,
           "AM 3: 読取点（端）→ 何も置かず 状態行 10107「２点間中心 Ｂ点指示」");
        /* 左の二点目: 読まず 押した点そのまま。中点 (10+(100-10)/2, 20+(80-20)/2) */
        app_press(jw_sx(v, 100.0), jw_sy(v, 80.0), 0);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 55.0) < 0.6
           && fabs(d->obj[n].d[1] - 50.0) < 0.6
           && strcmp(jw_cmd_prompt(), JW_STR_10107) != 0,
           "AM 3: 続く左は 二点の中点 (55,50) に 点、待ちは終わる");
        /* 右の二点目は 読取点が要る */
        n = d->ndrawn;
        AMRUN(3, 10.2, 20.1);
        app_press(jw_sx(v, 120.0), jw_sy(v, 120.0), 1);
        ck(d->ndrawn == n && strcmp(jw_cmd_prompt(), JW_STR_10107) == 0,
           "AM 3: 右の二点目が読めない所なら 何もせず 待ちのまま（段 6）");
        app_press(jw_sx(v, 200.0), jw_sy(v, 20.0), 1);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 105.0) < 1e-6
           && fabs(d->obj[n].d[1] - 20.0) < 1e-6,
           "AM 3: 右で端 (200,20) を読めば 中点 (105,20) に 点");
        /* 命令を替えれば待ちは捨てる */
        AMRUN(3, 10.2, 20.1);
        app_command(JW_CMD_SEN);
        app_command(JW_CMD_TEN);
        ck(strcmp(jw_cmd_prompt(), JW_STR_10107) != 0, "命令を替えると 二点目待ちは捨てる");

        /* AM 9: 線 A（(10,20)-(200,20)）を拾い、二図形目との交点を 線 A の上に */
        n = d->ndrawn;
        AMRUN(9, 150.0, 21.0);
        ck(d->ndrawn == n && strcmp(jw_cmd_prompt(), JW_STR_10108) == 0,
           "AM 9: 一図形目は 何も置かず 状態行 10108");
        app_press(jw_sx(v, 50.3), jw_sy(v, 100.0), 0);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 50.0) < 1e-6
           && fabs(d->obj[n].d[1] - 20.0) < 1e-6,
           "AM 9: 続く左で 縦の線を押す → 二線の交点 (50,20) に 点");
        n = d->ndrawn;
        AMRUN(9, 150.0, 21.0);
        app_press(jw_sx(v, 80.0), jw_sy(v, 60.0), 0);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 80.0) < 0.6
           && fabs(d->obj[n].d[1] - 20.0) < 1e-6,
           "AM 9: 二図形目が無ければ 押した点を 線 A へ落とす（線上点 (80,20)）");
        n = d->ndrawn;
        AMRUN(9, 150.0, 21.0);
        app_press(jw_sx(v, 150.0 + 30.0 * 0.7071), jw_sy(v, 150.0 + 30.0 * 0.7071), 0);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[1] - 20.0) < 1e-6
           && fabs(d->obj[n].d[0] - (150.0 + 30.0 * 0.7071)) < 0.6,
           "AM 9: 円と線 A は交わらない → 押した点の 線 A への足");
        /* 円を一図形目 → 押した点から 円の上へ（中心から外へ） */
        n = d->ndrawn;
        AMRUN(9, 150.0 + 30.0 * 0.7071, 150.0 + 30.0 * 0.7071);
        app_press(jw_sx(v, 150.0), jw_sy(v, 190.0), 0);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 150.0) < 0.5
           && fabs(d->obj[n].d[1] - 180.0) < 0.5,
           "AM 9: 円が一図形目 → 下の (150,190) は 円の上の (150,180) へ");
        /* 右の二つ目は 読取点が要り、交点は使わない */
        n = d->ndrawn;
        AMRUN(9, 150.0, 21.0);
        app_press(jw_sx(v, 120.0), jw_sy(v, 120.0), 1);
        ck(d->ndrawn == n && strcmp(jw_cmd_prompt(), JW_STR_10108) == 0,
           "AM 9: 右の二つ目が読めない所なら 何もせず 待ちのまま");
        app_press(jw_sx(v, 200.0), jw_sy(v, 20.0), 1);
        ck(d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 200.0) < 1e-6
           && fabs(d->obj[n].d[1] - 20.0) < 1e-6, "AM 9: 右で端を読めば その点を 線 A へ落とす (200,20)");
        /* AM 3: 寸法図形 → 部品 1（寸法線）の二端の中点（CDataSunpou 仮想関数 11 =
           FUN_0042af20 の +0x70・+0x78 と +0x80・+0x88）。値を拾っても 寸法線の中点 */
        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->sub = 1;
        o->d[0] = 20; o->d[1] = 40; o->d[2] = 120; o->d[3] = 40;
        o = jw_add(d, JW_MOJI);
        o->sub = 2;
        o->d[0] = 60; o->d[1] = 50; o->d[2] = 80; o->d[3] = 50;
        o = jw_add(d, JW_SEN);          /* 図形でない 線 */
        o->d[0] = 20; o->d[1] = 150; o->d[2] = 120; o->d[3] = 190;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_TEN);
        n = d->ndrawn;
        AMRUN(3, 30.0, 40.5);
        ck(d->ndrawn == n + 1 && d->obj[n].cls == JW_TEN
           && fabs(d->obj[n].d[0] - 70.0) < 1e-6 && fabs(d->obj[n].d[1] - 40.0) < 1e-6,
           "AM 3: 寸法の寸法線を押して → 寸法線の中点 (70,40) に 点");
        n = d->ndrawn;
        AMRUN(3, 70.0, 50.2);
        ck(d->ndrawn == n || (d->ndrawn == n + 1 && fabs(d->obj[n].d[0] - 70.0) < 1e-6
           && fabs(d->obj[n].d[1] - 40.0) < 1e-6),
           "AM 3: 寸法の値を押しても 値の中点 (70,50) でなく 寸法線の中点 (70,40)");
#undef AMRUN
        app_command(JW_CMD_SEN);
    }

    /* 右 PM 1〜12 の角度・長さ取得（FUN_00772770・00771030・007748b0・00770b60・
       00771ca0・0076bba0。逆コンパイルの読み）。押した点で拾い、二点のものは続きの押し */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        double deg, mm, ang = atan2(50.0, 100.0) * 180.0 / 3.141592653589793;
        int px, py, dx, dy;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = 10; o->d[1] = 20; o->d[2] = 110; o->d[3] = 70;
        o = jw_add(d, JW_ENKO);
        o->d[0] = 200; o->d[1] = 100; o->d[2] = 30; o->d[3] = 0;
        o->d[4] = 6.283185307179586; o->d[5] = 0; o->d[6] = 1;
        app_fit();
        app_paint();
        v = app_view();
        app_command(JW_CMD_SEN);
#define PMRUN(h, X, Y) do {             px = jw_sx(v, (X)); py = jw_sy(v, (Y));             app_rclock_begin(px, py);             at_hour((h), 60, &dx, &dy);             app_clock_move(px + dx, py + dy);             app_clock_right();             app_clock_end(); } while (0)
        PMRUN(4, 60.0, 45.0);
        ck(jw_cmd_get_kata(&deg) && fabs(deg - ang) < 1e-6, "右 PM 4 線角度: 押した線の角");
        PMRUN(8, 60.0, 45.0);
        ck(jw_cmd_get_kata(&deg) && fabs(deg + ang) < 1e-6, "右 PM 8 (-)角度: 符号を逆に");
        PMRUN(1, 60.0, 45.0);
        ck(jw_cmd_get_kata(&deg) && fabs(deg - (ang + 90.0 - 180.0)) < 1e-6,
           "右 PM 1 鉛直角: 角 + 90 を -90 より大きく 90 以下へ");
        PMRUN(4, 300.0, 200.0);
        ck(jw_cmd_get_kata(&deg) && fabs(deg - (ang - 90.0)) < 1e-6,
           "何も無い所の PM は何もしない（前の値のまま）");
        PMRUN(11, 60.0, 45.0);
        ck(jw_cmd_get_naga(&mm) && fabs(mm - sqrt(12500.0)) < 1e-6, "右 PM 11 線長取得: 線の長さ");
        PMRUN(11, 230.0, 100.0);
        ck(jw_cmd_get_naga(&mm) && fabs(mm - 30.0) < 1e-6, "右 PM 11: 円は 半径（2100 が切）");
        PMRUN(3, 10.0, 20.0);
        ck(jw_cmd_get_mode_now() == 90003, "右 PM 3: 点 1 を読んで 続きの押しを待つ");
        app_press(jw_sx(v, 110.0), jw_sy(v, 120.0), 0);
        printf("dbg %d %d %g\n", jw_cmd_get_mode_now(), jw_cmd_get_kata(&deg), deg);
        ck(jw_cmd_get_mode_now() == 0 && jw_cmd_get_kata(&deg) && fabs(deg - 45.0) < 0.5,
           "右 PM 3 X軸角度: 点 1 → 点 2 の向き 45 度");
        PMRUN(9, 10.0, 20.0);
        app_press(jw_sx(v, 110.0), jw_sy(v, 120.0), 0);
        ck(jw_cmd_get_kata(&deg) && fabs(deg + 45.0) < 0.5, "右 PM 9 X軸(-)角度: -45 度");
        PMRUN(10, 10.0, 20.0);
        ck(jw_cmd_get_mode_now() == 90010, "右 PM 10: 点 1 のあと 点 2 待ち");
        app_press(jw_sx(v, 10.0), jw_sy(v, 120.0), 0);
        ck(jw_cmd_get_naga(&mm) && fabs(mm - 100.0) < 0.5, "右 PM 10 ２点間長: 点 1 から点 2 まで 100");
        PMRUN(2, 10.0, 20.0);
        app_press(jw_sx(v, 110.0), jw_sy(v, 20.0), 0);
        ck(jw_cmd_get_mode_now() == 90002, "右 PM 2: 点 2 のあとも 点 3 を待つ");
        app_press(jw_sx(v, 10.0), jw_sy(v, 120.0), 0);
        ck(jw_cmd_get_mode_now() == 0 && jw_cmd_get_kata(&deg) && fabs(deg - 90.0) < 0.5,
           "右 PM 2 ２点間角: 向き 2 − 向き 1 = 90 − 0");
        PMRUN(5, 60.0, 45.0);
        ck(fabs(jw_cmd_axis() - ang) < 1e-6, "右 PM 5 軸角取得: 押した線の角が 軸角に");
        PMRUN(7, 60.0, 45.0);
        ck(fabs(jw_cmd_axis() + ang) < 1e-6, "右 PM 7 (-)軸角取得: 符号を逆に");
        jw_cmd_set_axis(0.0);
        PMRUN(10, 300.0, 250.0);
        ck(jw_cmd_get_mode_now() == 0, "読めない所の PM 10 は 続きを待たない（札 5324）");
#undef PMRUN
    }

    /* ---- AUTO モード自前の時計（CZukeiAuto の 46・47、FUN_0062a980） ---- */
    {
        static const struct { int h, cmd, id; } am[] = {
            { 1, JW_CMD_SEN, 5150 }, { 2, JW_CMD_ENKO, 10002 }, { 3, JW_CMD_HOURAKU, 10003 },
            { 4, JW_CMD_HANI, 10004 }, { 7, JW_CMD_FUKUSHA, 5160 },
            { 8, JW_CMD_SHINSHUKU, 10008 }, { 10, JW_CMD_SHOUKYO, 10010 },
            { 11, JW_CMD_FUKUSEN, 5159 }, { 12, JW_CMD_MOJI, 10012 }, { 9, JW_CMD_AUTO, 5199 } };
        static const int pmid[13] = { 0, 5198, 5194, 5168, 5164, 5235, 5196, 5161, 5166,
                                      10009, 10010, 5193, 5238 };
        int k, hok = 1, idok = 1;

        app_command(JW_CMD_AUTO);
        ck(app_clock_possible() && app_clock_ready(cx, cy, cx + 100, cy),
           "AUTO の間も時計になる");
        ck(app_rclock_possible() && app_rclock_ready(cx, cy, cx + 100, cy),
           "AUTO の間は 右も時計になる");
        for (k = 0; k < (int)(sizeof am / sizeof am[0]); k++) {
            app_command(JW_CMD_AUTO);
            at_hour(am[k].h, 60, &dx, &dy);
            app_clock_begin(cx, cy);
            app_clock_move(cx + dx, cy + dy);
            if (jw_cmd_notice_id() != am[k].id)
                idok = 0;
            app_clock_end();
            if (jw_cmd() != am[k].cmd)
                hok = 0;
        }
        ck(idok, "AUTO 左 AM: 札は 表の番号の札（1 線 2 円 3 包絡 4 範囲 7 複写 8 伸縮 9 AUTO 10 消去 11 複線 12 文字）");
        ck(hok, "AUTO 左 AM: 離すと その命令（1 時は 線のまま 矩形に替わらない）");
        app_command(JW_CMD_AUTO);
        at_hour(5, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10005, "AUTO 左 AM 5 は AUTO 自前の 札 10005（表でない）");
        app_clock_cancel();
        at_hour(6, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10006, "AUTO 左 AM 6 は 札 10006（表でない）");
        app_clock_cancel();

        /* PM（LD_PM）: 札 */
        idok = 1;
        for (k = 1; k <= 12; k++) {
            app_command(JW_CMD_AUTO);
            at_hour(k, 60, &dx, &dy);
            app_clock_begin(cx, cy);
            app_clock_move(cx + dx, cy + dy);
            app_clock_right();
            if (app_clock_pm() != 1 || jw_cmd_notice_id() != pmid[k])
                idok = 0;
            app_clock_cancel();
        }
        ck(idok, "AUTO 左 PM: 札は LD_PM の表（30 3 27 10 7 6 29 17 8 12 15 26）の番号の札");
        app_command(JW_CMD_AUTO);
        at_hour(10, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        app_clock_right();
        app_clock_end();
        ck(jw_cmd() == JW_CMD_SHOUKYO, "AUTO 左 PM 10 は 15 = 消去");

        /* 遠い方の輪（DAT_00a0d8ec = 900）: 札の頭に「(2) 」、LD2_AM は 9 時だけ AUTO */
        app_command(JW_CMD_AUTO);
        clk_auto_far(900);
        at_hour(9, 1000, &dx, &dy);
        app_clock_begin(cx + 1000, cy);
        app_clock_move(cx + 1000 + dx, cy + dy);
        ck(jw_cmd_notice_id() == 5199 && strstr(jw_cmd_notice_text(), "(2) ") != NULL,
           "遠い方の輪の 9 時: 札 5199 の頭に (2)");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_AUTO, "遠い方の輪の 9 時 = LD2_AM9 = AUTO");
        app_command(JW_CMD_SEN);
        app_command(JW_CMD_AUTO);
        at_hour(3, 1000, &dx, &dy);
        app_clock_begin(cx + 1000, cy);
        app_clock_move(cx + 1000 + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10013, "遠い方の輪の 3 時は 空（札 10013）");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_AUTO, "空の番号は 何もしない");
        clk_auto_far(100);
        at_hour(3, 150, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10013, "切替距離 100（|しきい|×2 = 70 以上でそのまま）: 150 画素は 遠い輪");
        app_clock_cancel();
        clk_auto_far(10);
        at_hour(3, 150, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10013, "切替距離 10 は 50 未満で入らず 100 のまま: 150 は 遠い輪");
        app_clock_cancel();
        clk_auto_far(900);

        /* 表を替える（基本設定の箱 2364〜2403）: 負は「* 」、0 は空 */
        app_command(JW_CMD_AUTO);
        clk_auto_set(0, 1, -2);
        at_hour(1, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 5150 && strstr(jw_cmd_notice_text(), "* ") != NULL,
           "値 -2: 札に「* 」が付く（逆の印）");
        app_clock_cancel();
        clk_auto_set(0, 1, 2);
        clk_auto_set(0, 2, 0);
        at_hour(2, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10013, "値 0 の向きは 札 10013");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_AUTO, "値 0 の向きで離しても 命令はそのまま");
        clk_auto_set(0, 2, 4);
        clk_auto_set(0, 2, 999);
        at_hour(2, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10002, "±200 の外の値は 前のまま");
        app_clock_cancel();

        /* 右（RD_AM・RD_PM）: AM 1・2・7・8・10・11 は AUTO の表、3・4・5・6・9・12 は既定の右 */
        app_command(JW_CMD_AUTO);
        at_hour(1, 60, &dx, &dy);
        app_rclock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 5170, "AUTO 右 AM 1: RD_AM1 = 20 → 札 5170");
        app_clock_end();
        ck(jw_cmd() == 0x8050, "AUTO 右 AM 1 を離すと 20 = 0x8050");
        app_command(JW_CMD_AUTO);
        at_hour(7, 60, &dx, &dy);
        app_rclock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 5167, "AUTO 右 AM 7: RD_AM7 = 9 → 札 5167");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_CHUSHIN, "AUTO 右 AM 7 を離すと 中心線");
        app_command(JW_CMD_AUTO);
        at_hour(4, 60, &dx, &dy);
        app_rclock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10105, "AUTO 右 AM 4 は 既定の右（戻る 10105）");
        app_clock_cancel();
        at_hour(1, 60, &dx, &dy);
        app_rclock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        app_clock_right();
        ck(jw_cmd_notice_id() == 10022, "AUTO 右 PM 1: RD_PM1 = 88 → 札 10022（鉛直角）");
        app_clock_move(cx - dx, cy - dy);
        ck(jw_cmd_notice_id() == 10021, "AUTO 右 PM 7（向き 7）: 値 -83 → 札 10021");
        app_clock_cancel();

        /* 1323（DAT_00a0c7c4 > 1）: AUTO でない命令も 表を使う */
        app_command(JW_CMD_SEN);
        clk_auto_std(1);
        at_hour(1, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        app_clock_end();
        ck(jw_cmd() == JW_CMD_SEN, "1323 入: 線の 1 時は 矩形に替わらず 表の 2 = 線");
        app_command(JW_CMD_SEN);
        at_hour(5, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        ck(jw_cmd_notice_id() == 10005, "1323 入でも 左 AM 5 は 表でない");
        app_clock_cancel();
        clk_auto_std(0);
        at_hour(1, 60, &dx, &dy);
        app_clock_begin(cx, cy);
        app_clock_move(cx + dx, cy + dy);
        app_clock_end();
        ck(jw_cmd() == JW_CMD_KUKEI, "1323 切: 線の 1 時は 矩形（既定の表）");
        app_command(JW_CMD_SEN);
    }

    /* ---- AUTO 端点移動（番号 80 = 0x158c。FUN_0062a980 → 状態 10 → FUN_00478c70。
       逆コンパイルの読みで、原典では押していない） ---- */
    {
        jw_drawing *d;
        const jw_view *v;
        jw_obj *o;
        int px, py, dx, dy, n;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = 10; o->d[1] = 20; o->d[2] = 110; o->d[3] = 70;
        app_fit();
        app_paint();
        v = app_view();
        n = d->ndrawn;
        app_command(JW_CMD_AUTO);
        clk_auto_set(0, 2, 80);
        /* 終点の近く（100, 65）で 2 時 → 拾って待つ。離した点（60, 200）へ 終点が動く */
        px = jw_sx(v, 100.0);
        py = jw_sy(v, 65.0);
        at_hour(2, 60, &dx, &dy);
        app_clock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        ck(jw_cmd_notice_id() == 5516, "AUTO 番号 80 の札は 5516 端点移動");
        app_clock_end();
        ck(jw_cmd() == JW_CMD_AUTO && jw_cmd_midway(), "端点移動: 線を拾って 次の点を待つ");
        app_press(jw_sx(v, 60.0), jw_sy(v, 200.0), 0);
        ck(d->ndrawn == n && fabs(d->obj[n - 1].d[0] - 10) < 1e-6 && fabs(d->obj[n - 1].d[1] - 20) < 1e-6
           && fabs(d->obj[n - 1].d[2] - 60) < 0.5 && fabs(d->obj[n - 1].d[3] - 200) < 0.5,
           "端点移動: 近い方（終点）だけが 離した点へ");
        ck(!jw_cmd_midway(), "端点移動: 済んだら AUTO の初めに戻る");
        /* 始点の近く（15, 25）なら 始点が動く */
        px = jw_sx(v, 15.0);
        py = jw_sy(v, 38.0);
        app_clock_begin(px, py);
        app_clock_move(px + dx, py + dy);
        app_clock_end();
        app_press(jw_sx(v, 30.0), jw_sy(v, 120.0), 0);
        ck(fabs(d->obj[d->ndrawn - 1].d[0] - 30) < 0.5 && fabs(d->obj[d->ndrawn - 1].d[1] - 120) < 0.5
           && fabs(d->obj[d->ndrawn - 1].d[2] - 60) < 0.5, "端点移動: 始点に近ければ 始点が動く");
        /* 何もない所では 何もしない */
        app_clock_begin(jw_sx(v, 300.0), jw_sy(v, 300.0));
        app_clock_move(jw_sx(v, 300.0) + dx, jw_sy(v, 300.0) + dy);
        app_clock_end();
        ck(!jw_cmd_midway(), "端点移動: 線が拾えなければ 何もしない");
        app_command(JW_CMD_SEN);
    }

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
