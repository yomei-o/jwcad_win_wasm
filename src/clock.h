/* クロックメニュー（左ボタン）。使う人が決めた作法（2026-10-16）: 右ドラッグは
 * 画面の移動のまま、左だけ入れる。左を図面の上で押したら すぐには点を渡さず
 * 預かり（表側の held、src/ryoboton.h と同じ預かり）、
 *
 *   動かさずに（しきいの内で）離す   クリック（押した点で app_press）
 *   しきいを越えて引く               クロックメニュー（離した向きの命令）
 *
 * しきいは 基本設定 一般(1) 1054「クロックメニュー移行」（Drag\Minimum、既定 35 →
 * DAT_00a0cad4、その二乗が DAT_00a0cad8）。原典の OnMouseMove（0x50a0xx の
 * FUN_005185e0）は 左が押されて（view+0x90c8）、まだ向きが無く（+0x9068 == 0）、
 * 押した画素から今の画素への距離の二乗が DAT_00a0cad8 を越えたら 1（左の時計）を
 * 返し、以後は動くたびに FUN_004fc1d0 が向きを決めて FUN_005088f0(…, 1) が札を出す。
 * 離し（FUN_005081c0）は 向きが 0 なら命令にふつうの左（押した点 +0x85d0）、
 * 向きがあれば FUN_005088f0(…, 2) が命令の仮想関数 46 番目（既定は FUN_0076c9c0）
 * を呼び、それが view+0x9090 に置いた命令へ FUN_004fdc40 で移る。
 *
 * 向きの割り方（FUN_004fc1d0）: 押した点から今の点への角に 90° を足して 0〜360
 * （画面の上が 12 時）、15° 未満は 12 時、ほかは (角 − 15) / 30 + 1。押した点から
 * 距離の二乗が DAT_00a0cae4 以下（|DAT_00a0cad4| < DAT_00a0cae0 なら DAT_00a0cad4 の
 * 二乗以下）は 13（選ばない＝キャンセル）で、外から そこへ戻ると AM/PM が切り替わる。
 * **DAT_00a0cae0・DAT_00a0cae4 はどこからも書かれない**（Jw_win.exe の .text に
 * 読む命令が 0x4faf4d・0x4fc33b・0x4fc365・0x4fc53b の四つあるだけで、番地は
 * .data の生の部分（0xa08000 まで）の外の bss）ので 0。つまり 13 になるのは押した
 * 画素ちょうどの上だけで、AM/PM は「押した画素へちょうど戻す」か「左を押したまま
 * 右を押す」（右押し FUN_0050d070: 左の時計の間で DAT_00a0cad4 > 0 なら +0x241e を
 * 反転、向きを 99 にして札を出し直させ、右の押しは無かったことに。0 以下なら時計を
 * やめて 両ボタン（CZoom）へ）。時計の円（FUN_004fc460 の半径も DAT_00a0cae0）も
 * 0 なので描かない。
 *
 * DAT_00a0cacc（1326「クロックメニューを使用しない」、Clock\NONCLOCK）が立つと
 * 左の時計のしきいが 100000000 になる（FUN_005185e0）ので左は時計にならない。
 * それでも原典は点を離しで渡す（押した点）。移植は 1326 が入なら前のとおり
 * （預かった左を 3 画素動くか離すかで渡す）。
 *
 * 移植で入れないもの（読みだけ、または答えの無いもの）: AUTO モードの時計
 * （CZukeiAuto と DAT_00a0c7bc・DAT_00a0c7c4 > 1 の FUN_00777690。移植は AUTO・
 * 手書線 の間は時計にしない）、AM 5 線種変更（FUN_0076e360: 押した点の要素を書込み
 * 線の属性に）・PM 6【全】属性取得（FUN_007751e0(1)）は札だけ、AM 4 範囲選択の
 * 「押した点を拾う」（FUN_0040dbb0）、AM 6 の 5261 札、右ボタンの時計
 * （FUN_0076d330、右ドラッグは移植では画面の移動）。
 *
 * どれも逆コンパイルの読みで、原典では押していない。
 *
 * 作りは stb 流: 中身は JW_CLOCK_IMPL を立てた src/app.c の中にある。 */
#ifndef JW_CLOCK_H
#define JW_CLOCK_H

#define CLK_NONE 13             /* 選ばない（札は 10013 キャンセル） */

/* FUN_004fc1d0 の向き。dx, dy は押した画素からの差（画面の y は下が正）。
   *ampm は 0 AM・1 PM（押した点へ戻ると切り替わる）、*prevd2 は前の距離の二乗
   （初めは 0）。only4 は 1326 の 3・6・9・12 寄せ。1〜13 を返す */
int clk_dir(int dx, int dy, int *ampm, int *prevd2, int only4);
/* 左の時計の表（FUN_0076c9c0）: 移る命令の番号。0 は何もしない。
   cur はいまの命令（AM 1 は 線 なら 矩形）、copy は 前の 複写・移動 が複写か
   （view+0x9058、原典の既定 1） */
enum { CLK_ZOKU = -1 };         /* AM 6 属性取得（押した点で） */
int clk_cmd(int dir, int pm, int cur, int copy);
/* 札の文字列番号と字（CP932）。dir が 13 などは 10013 キャンセル */
const char *clk_label(int dir, int pm, int *id);

/* 基本設定から（src/app.c の kh_apply）: 1326、1054、2108・2109（入なら AM/PM を
   前の操作のまま）、2099（円周1/8点。右の時計の円周1/4点にしか効かない） */
void clk_settings(int nonclock, int minimum, int lkeep, int rkeep, int circle8);
int  clk_minimum(void);
int  clk_circle8(void);

/* 表側から。clock_ready は 預かった左（押した x0,y0、いま x,y）を時計にするか */
int  app_clock_ready(int x0, int y0, int x, int y);
/* いま左が時計になりうるか（1326 が切で、AUTO・手書線・窓 でない）。なりうる間は
   表側は預かった左を しきいまで渡さない */
int  app_clock_possible(void);
void app_clock_begin(int x0, int y0);
int  app_clock_move(int x, int y);          /* 1 なら描き直す */
/* 時計の間に右が押された: 1 なら AM/PM を替えた（右の離しは捨てる）。
   0 なら時計をやめた（呼ぶ側が 両ボタン に） */
int  app_clock_right(void);
int  app_clock_end(void);                   /* 左の離し: 1 なら描き直す */
void app_clock_cancel(void);
int  app_clock_active(void);
int  app_clock_now(void);                   /* いまの向き（時計でなければ 0） */
int  app_clock_pm(void);

#endif

#ifdef JW_CLOCK_IMPL
#undef JW_CLOCK_IMPL

#include <math.h>

static int clk_nonclock;        /* DAT_00a0cacc */
static int clk_min = 35;        /* DAT_00a0cad4 */
static int clk_lclear = 1;      /* DAT_00a0caec = 2108 の逆 */
static int clk_rclear = 1;      /* DAT_00a0caf0 = 2109 の逆 */
static int clk_c8;              /* DAT_00a0cadc（右の時計だけ。持っておくだけ） */
static const int clk_inner = 0, clk_inner2 = 0;     /* DAT_00a0cae0・cae4（書かれない） */
static int clk_on, clk_x0, clk_y0, clk_x, clk_y, clk_d, clk_am, clk_pd2;
static int clk_copy = 1;        /* view+0x9058（ctor が 1） */

int clk_dir(int dx, int dy, int *ampm, int *prevd2, int only4)
{
    int d2 = dx * dx + dy * dy, dir, in2, m = clk_min < 0 ? -clk_min : clk_min;
    double a = (dx == 0 && dy == 0) ? 0.0 : atan2((double)dy, (double)dx) / 3.141592653589793 * 180.0;

    for (a += 90.0; a < 0.0; a += 360.0)
        ;
    for (; a >= 360.0; a -= 360.0)
        ;
    if (a < 15.0)
        dir = 12;
    else {
        dir = (int)((a - 15.0) / 30.0) + 1;
        if (dir > 12)
            dir = 12;
    }
    in2 = clk_inner2;
    if (m < clk_inner)
        in2 = clk_min * clk_min;
    if (d2 <= in2) {
        dir = CLK_NONE;
        if (in2 < *prevd2 && ++*ampm > 1)
            *ampm = 0;
    }
    if (only4) {
        *ampm = 0;
        if (dir == 11 || dir == 1)
            dir = 12;
        if (dir == 2 || dir == 4)
            dir = 3;
        if (dir == 5 || dir == 7)
            dir = 6;
        if (dir == 8 || dir == 10)
            dir = 9;
    }
    *prevd2 = d2;
    return dir;
}

int clk_cmd(int dir, int pm, int cur, int copy)
{
    static const int am[13] = { 0, 0, JW_CMD_ENKO, JW_CMD_HOURAKU, JW_CMD_HANI, 0,
                                CLK_ZOKU, 0, JW_CMD_SHINSHUKU, JW_CMD_AUTO,
                                JW_CMD_SHOUKYO, JW_CMD_FUKUSEN, JW_CMD_MOJI };
    static const int pmt[13] = { 0, JW_CMD_KIGOU, JW_CMD_KYOKUSEN, JW_CMD_TATEGU_RITSU,
                                 JW_CMD_TATEGU_DAN, JW_CMD_TATEGU, 0, JW_CMD_HATCH,
                                 JW_CMD_RENZOKU, JW_CMD_CHUSHIN, JW_CMD_NISEN,
                                 JW_CMD_SUNPO, JW_CMD_PARAM };

    if (dir < 1 || dir > 12)
        return 0;
    if (pm)
        return pmt[dir];
    if (dir == 1)
        return cur == JW_CMD_SEN ? JW_CMD_KUKEI : JW_CMD_SEN;
    if (dir == 7)
        return copy ? JW_CMD_FUKUSHA : JW_CMD_IDOU;
    return am[dir];
}

const char *clk_label(int dir, int pm, int *id)
{
    static const int pmid[13] = { 10013, 5197, 5234, 5165, 5195, 5170, 10026,
                                  5169, 5168, 5167, 5166, 5164, 5196 };
    static const char *const pms[13] = { JW_STR_10013, JW_STR_5197, JW_STR_5234,
        JW_STR_5165, JW_STR_5195, JW_STR_5170, JW_STR_10026, JW_STR_5169,
        JW_STR_5168, JW_STR_5167, JW_STR_5166, JW_STR_5164, JW_STR_5196 };
    static const char *const ams[14] = { JW_STR_10013, JW_STR_10001, JW_STR_10002,
        JW_STR_10003, JW_STR_10004, JW_STR_10005, JW_STR_10006, JW_STR_10007,
        JW_STR_10008, JW_STR_10009, JW_STR_10010, JW_STR_10011, JW_STR_10012,
        JW_STR_10013 };
    int k = dir >= 1 && dir <= 12 ? dir : 0;

    if (pm) {
        *id = pmid[k];
        return pms[k];
    }
    if (dir == 9) {             /* AM 9 は いつも 5199 AUTO */
        *id = 5199;
        return JW_STR_5199;
    }
    /* AM の 13 は 10000+13 = 10013、ほか（99 など）も同じ字 */
    *id = k ? 10000 + k : 10013;
    return ams[k];
}

void clk_settings(int nonclock, int minimum, int lkeep, int rkeep, int circle8)
{
    int m = minimum < 0 ? -minimum : minimum;

    clk_nonclock = nonclock != 0;
    /* OK（FUN_005d02e0 の前の CSonotaPage の OK）は |箱| が 20〜200 のときだけ入れる */
    if (m >= 20 && m <= 200)
        clk_min = minimum;
    clk_lclear = !lkeep;
    clk_rclear = !rkeep;
    clk_c8 = circle8 != 0;
}

int clk_minimum(void)
{
    return clk_min;
}

int clk_circle8(void)
{
    return clk_c8;
}

/* 移植が時計にしないとき: 図面が無い、窓が開いている、AUTO（原典は AUTO の
   自前の時計）、手書線（引きずって描く） */
static int clk_allowed(void)
{
    if (clk_nonclock || !have_drawing || !view_ready || app_modal())
        return 0;
    if (jw_cmd() == JW_CMD_AUTO || jw_cmd_freehand())
        return 0;
    return 1;
}

int app_clock_possible(void)
{
    return !clk_on && clk_allowed();
}

int app_clock_ready(int x0, int y0, int x, int y)
{
    int dx = x - x0, dy = y - y0;

    if (clk_on || !clk_allowed())
        return 0;
    return dx * dx + dy * dy > clk_min * clk_min;      /* DAT_00a0cad8 */
}

/* 命令ごとの受け手（原典の仮想関数 46 番目）。受けたら 1、既定の表へ回すなら 0。
   run が 0 なら札（*id, *s）、1 なら実行。
 *
 * 分割（FUN_007637e0）: AM で 線（Ａ）を指した段（+0xc0 == 2）なら
 *   12 時  線属性（FUN_005156d0 = 32807 の窓、札 10035「- 線属性設定 -」）
 *   1・2・3 時  Ａが線で（+0xac == 0、CDataSen）割付（+0x7e84）・等角度（+0xb8）が
 *          切のとき 逆分割 FUN_00763ee0（札 5611）・線長割合分割 FUN_00763cd0
 *          （5612）・馬目地分割 FUN_00763d20(0)（5609）。移植は バーの釦 1066・
 *          1064 と同じ（jw_cmd_bunkatsu_hojo、src/cmd.c）。馬目地は 縦分割数の
 *          窓を写していないので 札だけ（釦 1065 も押せない）
 * ほかは既定の表（FUN_0076c9c0）。DAT_00a0c7c0 と FUN_00778a40（AUTO の覚え）は
 * 入れていない。 */
static int clk_own(int dir, int pm, int run, int *id, const char **s)
{
    static const int hid[4] = { 0, 5611, 5612, 5609 };
    static const char *const hs[4] = { 0, JW_STR_5611, JW_STR_5612, JW_STR_5609 };

    if (jw_cmd() != JW_CMD_BUNKATSU || pm || !jw_cmd_bunkatsu_a())
        return 0;
    if (dir == 12) {
        if (run)
            app_command(0x8027);
        *id = 10035;
        *s = JW_STR_10035;
        return 1;
    }
    if (dir >= 1 && dir <= 3 && jw_cmd_bunkatsu_hojo()) {
        if (run && dir != 3)
            jw_cmd_bar(&drawing, dir == 1 ? 1066 : 1064);
        *id = hid[dir];
        *s = hs[dir];
        return 1;
    }
    return 0;
}

static void clk_show(void)
{
    int id;
    const char *s;

    if (!clk_own(clk_d, clk_am, 0, &id, &s))
        s = clk_label(clk_d, clk_am, &id);
    /* 札は押した画素（+0x8f50/54）に。src/app.c の notice_at が据える */
    nt_px = clk_x0;
    nt_py = clk_y0;
    jw_cmd_notice(id, s);
}

void app_clock_begin(int x0, int y0)
{
    clk_on = 1;
    clk_x0 = clk_x = x0;
    clk_y0 = clk_y = y0;
    clk_d = 0;
    clk_pd2 = 0;
    jw_cmd_notice_clear();      /* 左押し FUN_00507d00 の FUN_004fb9f0 */
}

int app_clock_move(int x, int y)
{
    int d;

    if (!clk_on)
        return 0;
    clk_x = x;
    clk_y = y;
    d = clk_dir(x - clk_x0, y - clk_y0, &clk_am, &clk_pd2, clk_nonclock);
    if (d == clk_d)
        return 0;
    clk_d = d;                  /* 向きが変わるたびに札（FUN_004fc460 と 仮想 46 の 1） */
    clk_show();
    return 1;
}

int app_clock_right(void)
{
    if (!clk_on)
        return 0;
    if (clk_min > 0) {
        clk_am ^= 1;            /* +0x241e ^= 1、向きを 99 に */
        clk_d = 99;
        /* 原典は次の動きで札を出し直す。移植は すぐ出し直す（その場の向きで） */
        clk_d = clk_dir(clk_x - clk_x0, clk_y - clk_y0, &clk_am, &clk_pd2, clk_nonclock);
        clk_show();
        return 1;
    }
    app_clock_cancel();
    return 0;
}

void app_clock_cancel(void)
{
    if (!clk_on)
        return;
    clk_on = 0;
    clk_d = 0;
    jw_cmd_notice_clear();      /* FUN_004faf00 */
    if (clk_lclear)
        clk_am = 0;
}

int app_clock_end(void)
{
    int d = clk_d, pm = clk_am, cur = jw_cmd(), c, id;
    const char *s;

    if (!clk_on)
        return 0;
    clk_on = 0;
    clk_d = 0;
    jw_cmd_notice_clear();
    if (clk_lclear)             /* DAT_00a0caec: 2108 が切なら AM に戻す */
        clk_am = 0;
    if (clk_own(d, pm, 1, &id, &s))
        return 1;
    if (cur == JW_CMD_FUKUSHA)
        clk_copy = 1;
    else if (cur == JW_CMD_IDOU)
        clk_copy = 0;
    c = clk_cmd(d, pm, cur, clk_copy);
    if (c == CLK_ZOKU) {
        /* FUN_007751e0(0, 押した点): いまの命令のまま 押した点の要素から属性を
           取る。移植は 属性取得 に入って押した点で押し、前の命令へ戻す */
        int x = clk_x0, y = clk_y0;

        app_command(JW_CMD_ZOKUSEI);
        app_press(x, y, 0);
        app_command(cur);
        return 1;
    }
    if (c > 0) {
        app_command(c);
        return 1;
    }
    return 1;                   /* 札を下ろしたので描き直す */
}

int app_clock_active(void)
{
    return clk_on;
}

int app_clock_now(void)
{
    return clk_on ? clk_d : 0;
}

int app_clock_pm(void)
{
    return clk_am;
}

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
/* ブラウザから（index.html）。y は画布の座標（上の飾りの分を引く） */
EMSCRIPTEN_KEEPALIVE int jw_clock_ready(int x0, int y0, int x, int y)
{
    return app_clock_ready(x0, y0 - app_chrome_h(), x, y - app_chrome_h());
}

EMSCRIPTEN_KEEPALIVE int jw_clock_possible(void)
{
    return app_clock_possible();
}

EMSCRIPTEN_KEEPALIVE void jw_clock_begin(int x0, int y0)
{
    app_clock_begin(x0, y0 - app_chrome_h());
}

EMSCRIPTEN_KEEPALIVE int jw_clock_move(int x, int y)
{
    int r = app_clock_move(x, y - app_chrome_h());

    if (r)
        app_paint();
    return r;
}

EMSCRIPTEN_KEEPALIVE int jw_clock_right(void)
{
    int r = app_clock_right();

    app_paint();
    return r;
}

/* jw_clock_end（左の離し）は 求め（action）を press と同じに返すので
   src/main_wasm.c の finish のそばにある */

EMSCRIPTEN_KEEPALIVE void jw_clock_cancel(void)
{
    app_clock_cancel();
    app_paint();
}

EMSCRIPTEN_KEEPALIVE int jw_clock_active(void)
{
    return app_clock_active();
}
#endif

#endif
