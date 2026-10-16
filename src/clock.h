/* クロックメニュー（左ボタン・右ボタン）。使う人が決めた作法（2026-10-16 夕）:
 * 原典と同じに 右ドラッグも時計にし、画面の移動は両ボタン（src/ryoboton.h）に
 * 任せる（右の時計は下の「右ボタンの時計」）。左を図面の上で押したら
 * すぐには点を渡さず 預かり（表側の held、src/ryoboton.h と同じ預かり）、
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
 * 手書線 の間は時計にしない）、PM 6【全】属性取得（FUN_007751e0(1)）は札だけ、AM 4 範囲選択の
 * 「押した点を拾う」（FUN_0040dbb0）、AM 6 の 5261 札。
 *
 * 右ボタンの時計（FUN_0076d330、命令の仮想関数 47）。右を押して しきいを越えて
 * 引けば 左と同じ向きの割り（FUN_004fc1d0）で 右の AM/PM（view+0x907c、
 * 2109 で前のまま）の札を出し、右を離すと FUN_0050d3f0 が FUN_0050d8e0(…, 2)
 * から仮想関数 47 を呼ぶ。動かさずに離せば ふつうの右クリック（読取り点）。
 * 時計の間に左を押すと 右の AM/PM が替わる（左押し FUN_00507d00。1326 が入なら
 * 替えずに時計をやめて 両ボタンへ）。右の時計は 1326 のしきい 100000000 にならない
 * （FUN_005185e0 は 左が押されているときだけ）。入れたのは
 *   AM 4 戻る（札 10105、FUN_00504100 = app_command の戻る）・AM 5 進む（10106、
 *   FUN_00503e90）、AM 12 円周1/4点（FUN_0076efd0、2099 が入なら 1/8 点）、
 *   AM 3・6・9 と PM の札（10101・10103・10102、PM は 10022 …）、
 *   ほかの時（AM 1・2・7・8・10・11、PM 13）は左の表（FUN_0076c9c0 は 左の
 *   AM/PM +0x9078 を見る）
 * 入れていないもの: AM 3・6・9 の読取り（仮想関数 18〜20 の既定 FUN_0076ea20・
 * FUN_0076f880・FUN_0076fae0。点の読み FUN_00451f30・FUN_004497b0 の中が要る）、
 * PM の角度・長さ取得（FUN_00772770・FUN_00771030・FUN_007748b0・FUN_00770b60・
 * FUN_00771ca0・FUN_0076bba0。命令ごとの仮想関数 49・50・48 へ値を渡す）、
 * 49 の命令のうち 34 が仮想関数 47 を持つ（CZukeiSen 0x6effb0 など。多くは
 * AM で FUN_00778a40（AUTO の覚え）を先に呼んでから FUN_0076d330 へ渡すだけだが、
 * 線・円のように 12 時が別の命令がある: 線は FUN_006f3490 の 札 10120 台）。
 * 移植は 線 の 12 時だけは何もしない。DAT_00a0c7cc（基本設定の読みの一項、
 * 入だと AM 4・5 が 10013 キャンセルになる）は読まない。
 *
 * どれも逆コンパイルの読みで、原典では押していない。
 *
 * 作りは stb 流: 中身は JW_CLOCK_IMPL を立てた src/app.c の中にある。 */
#ifndef JW_CLOCK_H
#define JW_CLOCK_H

#include "jww.h"

#define CLK_NONE 13             /* 選ばない（札は 10013 キャンセル） */

/* FUN_004fc1d0 の向き。dx, dy は押した画素からの差（画面の y は下が正）。
   *ampm は 0 AM・1 PM（押した点へ戻ると切り替わる）、*prevd2 は前の距離の二乗
   （初めは 0）。only4 は 1326 の 3・6・9・12 寄せ。1〜13 を返す */
int clk_dir(int dx, int dy, int *ampm, int *prevd2, int only4);
/* 左の時計の表（FUN_0076c9c0）: 移る命令の番号。0 は何もしない。
   cur はいまの命令（AM 1 は 線 なら 矩形）、copy は 前の 複写・移動 が複写か
   （view+0x9058、原典の既定 1） */
enum { CLK_ZOKU = -1,           /* AM 6 属性取得（押した点で） */
       CLK_SENSHU = -2 };       /* AM 5 線種変更（押した点の要素、FUN_0076e360） */
int clk_cmd(int dir, int pm, int cur, int copy);
/* 札の文字列番号と字（CP932）。dir が 13 などは 10013 キャンセル */
const char *clk_label(int dir, int pm, int *id);

/* 基本設定から（src/app.c の kh_apply）: 1326、1054、2108・2109（入なら AM/PM を
   前の操作のまま）、2099（円周1/8点。右の時計の円周1/4点にしか効かない） */
void clk_settings(int nonclock, int minimum, int lkeep, int rkeep, int circle8);
/* 一般(2) 1523「ｸﾛｯｸﾒﾆｭｰ左AM5時の線種変更のときレイヤは変更しない」（DAT_00a0c7d8） */
void clk_set_motolay(int on);
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
/* 右の時計（FUN_0076d330）。ready・possible・begin だけ左と別で、あとの
   move・end・cancel・active・now・pm は いま動いている方のをそのまま使う。
   app_clock_right は「もう片方のボタンが押された」で、左の時計なら右、
   右の時計なら左。app_clock_button は 動いている時計の 0 左・1 右 */
int  app_rclock_ready(int x0, int y0, int x, int y);
int  app_rclock_possible(void);
void app_rclock_begin(int x0, int y0);
int  app_clock_button(void);
/* 右の表（FUN_0076d330）の札と実行。dir 1〜12、pm は右の AM/PM。run が 0 なら札
   （*id, *s）だけ、1 なら実行。持っていれば 1、左の表へ回すなら 0 */
int  clk_rown(int dir, int pm, int run, int *id, const char **s);
/* 円・円弧の（dx, dy）向きの点（FUN_005f92e0・FUN_0045b790）: 中心を原点に 軸角 axis
   （度）で回した枠で、c8 が 0 なら 1/4 点（小さい方の成分を 0 に）、1 なら 1/8 点
   （成分の大小が半分より近ければ斜め）に寄せ、その向きの 楕円の上の点を *rx, *ry へ。
   o は 円・円弧。中心の上など 向きが無ければ 0 */
int  clk_circle_pt(const jw_obj *o, double px, double py, double axis, int c8,
                   double *rx, double *ry);

#endif

#ifdef JW_CLOCK_IMPL
#undef JW_CLOCK_IMPL

#include <math.h>

static int clk_nonclock;        /* DAT_00a0cacc */
static int clk_min = 35;        /* DAT_00a0cad4 */
static int clk_lclear = 1;      /* DAT_00a0caec = 2108 の逆 */
static int clk_rclear = 1;      /* DAT_00a0caf0 = 2109 の逆 */
static int clk_c8;              /* DAT_00a0cadc（右の時計だけ。持っておくだけ） */
static int clk_motolay;         /* DAT_00a0c7d8（1523） */
static const int clk_inner = 0, clk_inner2 = 0;     /* DAT_00a0cae0・cae4（書かれない） */
static int clk_on, clk_x0, clk_y0, clk_x, clk_y, clk_d, clk_am, clk_pd2;
static int clk_btn;             /* 動いている時計の ボタン 0 左・1 右 */
static int clk_ram;             /* view+0x907c（右の AM/PM） */
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
    static const int am[13] = { 0, 0, JW_CMD_ENKO, JW_CMD_HOURAKU, JW_CMD_HANI, CLK_SENSHU,
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

void clk_set_motolay(int on)
{
    clk_motolay = on != 0;
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
   自前の時計）、手書線（引きずって描く）。
   1326 は左だけ（右は FUN_005185e0 が 左も押されているときだけ しきいを替える） */
static int clk_allowed(int right)
{
    if ((clk_nonclock && !right) || !have_drawing || !view_ready || app_modal())
        return 0;
    if (jw_cmd() == JW_CMD_AUTO || jw_cmd_freehand())
        return 0;
    /* 手書線は 引きずる前（押した瞬間）から: 連続線の 1774 が入なら時計にしない。
       押しを 3 画素で渡さないと 線が離すまで出ない */
    if (jw_cmd() == JW_CMD_RENZOKU && jw_cmd_bar_check(1774) > 0)
        return 0;
    return 1;
}

int app_clock_possible(void)
{
    return !clk_on && clk_allowed(0);
}

int app_rclock_possible(void)
{
    return !clk_on && clk_allowed(1);
}

int app_clock_ready(int x0, int y0, int x, int y)
{
    int dx = x - x0, dy = y - y0;

    if (clk_on || !clk_allowed(0))
        return 0;
    return dx * dx + dy * dy > clk_min * clk_min;      /* DAT_00a0cad8 */
}

int app_rclock_ready(int x0, int y0, int x, int y)
{
    int dx = x - x0, dy = y - y0;

    if (clk_on || !clk_allowed(1))
        return 0;
    return dx * dx + dy * dy > clk_min * clk_min;
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

/* 円・円弧の向きの点（FUN_0076efd0 の 0x76f0.. 以降 と FUN_0045b790）。
 * 枠は FUN_005f89c0（原点 = 中心、角 = 軸角 doc+0x17c0）で、FUN_005f92e0 が
 * 図面 → 枠（x' = dx·cos + dy·sin、y' = dy·cos − dx·sin）、FUN_005f8ce0 が 枠 → 図面。
 * 枠の中の押した点を DAT_00a0cadc（2099）が 0 なら 小さい方の成分（|x| <= |y| なら x）
 * を 0 に、1 なら 大きい方 m・小さい方 n で |m − n| < m/2 なら 両方を ±m（符号は
 * 元の符号、0 は −）に、そうでなければ 小さい方を 0 に。
 * 戻した向きの点を FUN_0045b790 が 楕円の上へ（中心から (dx, dy) を 傾き tilt で
 * 回して 扁平率で割った (u, v) の長さ len に 半径 r / len を掛ける）。向きが 1e-7 に
 * 満たなければ（中心の上）0 */
int clk_circle_pt(const jw_obj *o, double px, double py, double axis, int c8,
                  double *rx, double *ry)
{
    double cx = o->d[0], cy = o->d[1], r = o->d[2], tilt = o->d[5], flat = o->d[6];
    double a = axis * 3.141592653589793 / 180.0, co = cos(a), sn = sin(a);
    double x = px - cx, y = py - cy, lx, ly, ax_, ay_, big, small, dx, dy;
    double tc = cos(tilt), ts = sin(tilt), u, v, len, k;

    if (flat <= 0.0)
        flat = 1.0;
    lx = x * co + y * sn;               /* FUN_005f92e0 */
    ly = y * co - x * sn;
    ax_ = lx < 0 ? -lx : lx;
    ay_ = ly < 0 ? -ly : ly;
    if (!c8) {
        if (ax_ <= ay_)
            lx = 0.0;
        else
            ly = 0.0;
    } else {
        big = ay_;
        small = ax_;
        if (ay_ < ax_) {
            big = ax_;
            small = ay_;
        }
        if (big / 2.0 <= (big - small < 0 ? small - big : big - small)) {
            if (ax_ <= ay_)
                lx = 0.0;
            else
                ly = 0.0;
        } else {
            lx = lx <= 0.0 ? -big : big;
            ly = ly <= 0.0 ? -big : big;
        }
    }
    dx = co * lx - sn * ly;             /* FUN_005f8ce0（中心の分は 引いたまま） */
    dy = co * ly + sn * lx;
    if ((dx < 0 ? -dx : dx) + (dy < 0 ? -dy : dy) < 1e-07)
        return 0;
    u = tc * dx + ts * dy;              /* FUN_0045b790 */
    v = (tc * dy - ts * dx) / flat;
    len = sqrt(u * u + v * v);
    if (len < 1e-07)
        return 0;
    k = r / len;
    u *= k;
    v = v * k * flat;
    *rx = tc * u - ts * v + cx;
    *ry = tc * v + ts * u + cy;
    return 1;
}

/* 右の表（FUN_0076d330）。AM（view+0x907c == 0）:
 *   3・6・9 時は 仮想関数 18・19・20 の既定（FUN_0076ea20・FUN_0076f880・
 *   FUN_0076fae0）の札だけ（10101・10103・10102。読取りは入れていない）
 *   4 時 戻る（札 0x2779 = 10105、離しで FUN_00504100）、5 時 進む（0x277a、FUN_00503e90）
 *   12 時 仮想関数 21 の既定 FUN_0076efd0: 札 0x2778 = 10104（2099 が入なら 0x278b = 10123）、
 *   離しで 押した点の線・円（FUN_0044a270 の 3）を拾い、円・円弧でなければ
 *   0x277e = 10110「円ではありません」、円なら 向きの点（clk_circle_pt）を
 *   命令へ 左の点として渡す（FUN_0050d3f0 は 仮想関数 47 が 1 を返すと
 *   仮想関数 9 を呼ぶ。点が どう渡るかの経路は 読み切っていない。
 *   原典では押していない）。移植は 線（JW_CMD_SEN）の 12 時は何もしない
 * PM は 札だけ。持っていない時は 0（左の表へ） */
int clk_rown(int dir, int pm, int run, int *id, const char **s)
{
    static const int pid[13] = { 0, 10022, 10014, 10015, 10016, 10020, 10030,
                                 10021, 10025, 10018, 10024, 10023, 10031 };
    static const char *const ps[13] = { 0, JW_STR_10022, JW_STR_10014, JW_STR_10015,
        JW_STR_10016, JW_STR_10020, JW_STR_10030, JW_STR_10021, JW_STR_10025,
        JW_STR_10018, JW_STR_10024, JW_STR_10023, JW_STR_10031 };

    if (dir < 1 || dir > 12)
        return 0;
    if (pm) {
        *id = pid[dir];
        *s = ps[dir];
        return 1;
    }
    switch (dir) {
    case 3:
        *id = 10101;
        *s = JW_STR_10101;
        return 1;
    case 6:
        *id = 10103;
        *s = JW_STR_10103;
        return 1;
    case 9:
        *id = 10102;
        *s = JW_STR_10102;
        return 1;
    case 4:
        if (run)
            app_command(JW_CMD_UNDO);
        *id = 10105;
        *s = JW_STR_10105;
        return 1;
    case 5:
        if (run)
            app_command(JW_CMD_REDO);
        *id = 10106;
        *s = JW_STR_10106;
        return 1;
    case 12:
        if (clk_c8) {
            *id = 10123;
            *s = JW_STR_10123;
        } else {
            *id = 10104;
            *s = JW_STR_10104;
        }
        if (run && have_drawing && jw_cmd() != JW_CMD_SEN) {
            double mx, my, qx, qy;
            int i;

            to_paper(clk_x0, clk_y0, &mx, &my);
            i = jw_pick(&drawing, &view, mx, my, 3);
            if (i >= 0) {
                if (drawing.obj[i].cls != JW_ENKO) {
                    nt_px = clk_x;      /* 札の場所 +0x8f24 は 離した画素と読む */
                    nt_py = clk_y;
                    jw_cmd_notice(10110, JW_STR_10110);
                } else if (clk_circle_pt(&drawing.obj[i], mx, my, jw_cmd_axis(),
                                         clk_c8, &qx, &qy)) {
                    int was = drawing.ndrawn;

                    jw_cmd_point(&drawing, &view, qx, qy, 0);
                    if (jw_cmd_block_editing() && drawing.ndrawn > was)
                        jw_cmd_block_take(&drawing, was);
                    gaibu_after();
                    if (jw_cmd_figure_base(&fig_bx, &fig_by))
                        action = JW_ACT_SAVE_FIG;
                }
            }
        }
        return 1;
    }
    return 0;
}

static void clk_show(void)
{
    int id;
    const char *s;

    if (clk_btn) {
        /* 右の表に無い時は 左の表（FUN_0076c9c0 は 左の AM/PM を見る） */
        if (!clk_rown(clk_d, clk_ram, 0, &id, &s))
            s = clk_label(clk_d, clk_am, &id);
    } else if (!clk_own(clk_d, clk_am, 0, &id, &s))
        s = clk_label(clk_d, clk_am, &id);
    /* 札は押した画素（+0x8f50/54）に。src/app.c の notice_at が据える */
    nt_px = clk_x0;
    nt_py = clk_y0;
    jw_cmd_notice(id, s);
}

static void clk_start(int x0, int y0, int btn)
{
    clk_on = 1;
    clk_btn = btn;
    clk_x0 = clk_x = x0;
    clk_y0 = clk_y = y0;
    clk_d = 0;
    clk_pd2 = 0;
    jw_cmd_notice_clear();      /* 押し FUN_00507d00・FUN_0050d070 の FUN_004fb9f0 */
}

void app_clock_begin(int x0, int y0)
{
    clk_start(x0, y0, 0);
}

void app_rclock_begin(int x0, int y0)
{
    clk_start(x0, y0, 1);
}

int app_clock_button(void)
{
    return clk_on ? clk_btn : 0;
}

int app_clock_move(int x, int y)
{
    int d;

    if (!clk_on)
        return 0;
    clk_x = x;
    clk_y = y;
    d = clk_dir(x - clk_x0, y - clk_y0, clk_btn ? &clk_ram : &clk_am, &clk_pd2,
                clk_nonclock);
    if (d == clk_d)
        return 0;
    clk_d = d;                  /* 向きが変わるたびに札（FUN_004fc460 と 仮想 46・47 の 1） */
    clk_show();
    return 1;
}

/* もう片方のボタンが押された: 左の時計の間の右は +0x9078 ^= 1（右押し FUN_0050d070）、
   右の時計の間の左は +0x907c ^= 1（左押し FUN_00507d00、こちらだけ 1326 が切のとき）。
   替えないなら 時計をやめて（FUN_004faf00）AM/PM を 2108・2109 で戻し、呼ぶ側が両ボタンへ */
int app_clock_right(void)
{
    int *am;

    if (!clk_on)
        return 0;
    am = clk_btn ? &clk_ram : &clk_am;
    if (clk_min > 0 && (!clk_btn || !clk_nonclock)) {
        *am ^= 1;               /* +0x241e ^= 1、向きを 99 に */
        clk_d = 99;
        /* 原典は次の動きで札を出し直す。移植は すぐ出し直す（その場の向きで） */
        clk_d = clk_dir(clk_x - clk_x0, clk_y - clk_y0, am, &clk_pd2, clk_nonclock);
        clk_show();
        return 1;
    }
    app_clock_cancel();
    if (clk_lclear)
        clk_am = 0;
    if (clk_rclear)
        clk_ram = 0;
    return 0;
}

void app_clock_cancel(void)
{
    if (!clk_on)
        return;
    clk_on = 0;
    clk_d = 0;
    jw_cmd_notice_clear();      /* FUN_004faf00 */
    if (clk_btn ? clk_rclear : clk_lclear)
        *(clk_btn ? &clk_ram : &clk_am) = 0;
}

/* 左の表（FUN_0076c9c0）の実行。pm は 左の AM/PM */
static int clk_table_run(int d, int pm)
{
    int cur = jw_cmd(), c;

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
    if (c == CLK_SENSHU) {
        /* FUN_0076e360: いまの命令のまま 押した点の要素に書込み線を着せる
           （src/cmd.c の jw_cmd_clock_senshu）。札 6004 は押した画素に */
        double x, y;

        to_paper(clk_x0, clk_y0, &x, &y);
        nt_px = clk_x0;
        nt_py = clk_y0;
        jw_cmd_clock_senshu(&drawing, &view, x, y, clk_motolay);
        return 1;
    }
    if (c > 0) {
        app_command(c);
        return 1;
    }
    return 1;                   /* 札を下ろしたので描き直す */
}

int app_clock_end(void)
{
    int d = clk_d, pm = clk_btn ? clk_ram : clk_am, id;
    const char *s;

    if (!clk_on)
        return 0;
    clk_on = 0;
    clk_d = 0;
    jw_cmd_notice_clear();
    if (clk_btn) {
        /* 右の離し（FUN_0050d3f0 → FUN_0050d8e0(…, 2)）: 2109 が切なら 右を AM に戻す
           （0x907c = 0x9084 = 0） */
        if (clk_rclear)
            clk_ram = 0;
        if (clk_rown(d, pm, 1, &id, &s))
            return 1;
        return clk_table_run(d, clk_am);
    }
    if (clk_lclear)             /* DAT_00a0caec: 2108 が切なら AM に戻す */
        clk_am = 0;
    if (clk_own(d, pm, 1, &id, &s))
        return 1;
    return clk_table_run(d, pm);
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
    return clk_btn ? clk_ram : clk_am;
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

/* 右の時計（begin の 右版）。move・right・end・cancel は左と同じ */
EMSCRIPTEN_KEEPALIVE int jw_rclock_ready(int x0, int y0, int x, int y)
{
    return app_rclock_ready(x0, y0 - app_chrome_h(), x, y - app_chrome_h());
}

EMSCRIPTEN_KEEPALIVE int jw_rclock_possible(void)
{
    return app_rclock_possible();
}

EMSCRIPTEN_KEEPALIVE void jw_rclock_begin(int x0, int y0)
{
    app_rclock_begin(x0, y0 - app_chrome_h());
}

EMSCRIPTEN_KEEPALIVE int jw_clock_button(void)
{
    return app_clock_button();
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
