#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cmd.h"
#include "cp932.h"
#include "tategu.h"
#include "senkigou.h"
#include "takaku.h"
#include "hikage.h"
#include "image.h"
#include "tenku.h"
#include "tenku_sansha.h"
#include "pick.h"
#include "ui.h"                 /* ui_bar_ctl: what is on each command's bar */
#include "text.h"
#include "gen/prompts.h"
#include "gen/sunpo.h"

/* view+0x8564 in the original, and +0x8568 for the one before.  Entering a
   command copies the outgoing one into +0x8568 before the new command's arm
   of FUN_004fdc40 runs, which is how that arm can tell it is being entered
   from itself. */
static int current = JW_CMD_SEN;
static int prev;
/* 文字の 範囲選択 (2407): a range is being taken for the 文字 command (ms_back),
   texts are picked and shown pink (ms_text), 外部エディタ was pressed with
   nothing picked and goes on once the range is settled (ms_after, ms_go) */
static int ms_back, ms_text, ms_after, ms_go;
/* 外部変形 (0x8091), the steps of a BAT (end of this file) */
static const char *u8cp(const char *u);
static int gb_keep, gb_back, gb_state;
/* 連続線 の 手書線 (1774): the button is held and dragged */
static int fh_state, fh_made;
static void fh_press(jw_drawing *d, const jw_view *v, double x, double y);
static void gb_free(void);
static void gb_step(jw_drawing *d);
static const char *gb_prompt(void);
static void gb_click(jw_drawing *d, const jw_view *v, double x, double y, int button);

/* 水平・垂直, the first checkbox on 線's command bar after 矩形.
 *
 * Pressing 線 when 線 is already the command flips it -- FUN_004fdc40's
 * 0x8003 arm does that and nothing else when the command before was 0x8003
 * too, and driving Jw_cad bears it out: from a fresh start a diagonal drag
 * draws a diagonal, after one press of 線 it draws horizontal or vertical,
 * and after two it is diagonal again.  矩形's arm (0x8004) has no such test,
 * so only 線 toggles.
 *
 * With it on the line keeps whichever way the drag went further; a drag of
 * exactly 45 degrees comes out vertical. */
static int hv;

/* Each command keeps how far it has got in a word of its own -- CZukeiSen in
 * local_662c[0x2a] of FUN_006ecb90, CZukeiEnko in local_6840[0xc2] -- and
 * both use 0 for "nothing yet" and 2 for "one point down".  The same values
 * are used here so the two can be compared.
 */
static int step;
static double sx, sy;           /* the first point, in paper millimetres */
/* 線・矩形・円: Esc pressed right after one was finished takes the pen back
 * to that shape's first point (the status line says 終点 again, and the next
 * click draws from the same start); a second Esc lets go.  Read off the
 * original with tools/escprobe.sh (tmp/esc_report.md). */
static int esc_rearm, esc_cmd;
static int esc_arc;             /* an 円弧 was just finished: Esc takes its 終点 back */
/* 円の ３点指示 (1321): a circle/arc through three points was just finished
   -- Esc takes its 3点目 back, reusing sx,sy (1点目) and en_r,en_a0
   (2点目, never cleared).  Kept apart from esc_arc, which is 1318's own
   and uses sx,sy/en_r,en_a0 in a different convention (radius/angle, not
   a raw second point) -- sharing it would misread a stale 1318 finish as
   a 3点指示 one if the bar was flipped between the two (RESUME.md
   2026-10-13). */
static int esc_3pt;
static double esc_x, esc_y;
/* 連続線 keeps one segment back.  Clicking n times in Jw_cad and saving
 * leaves n-2 lines in the file -- two clicks leave none, four leave two,
 * five leave three (driven with tmp/jwdraw.ps1 -Cmd 32883) -- so the segment
 * between the last two points is still only on the screen when the next
 * click arrives, and that click is what puts it in.  These are those two
 * points; sx,sy is the one before them. */
static double rx, ry;

/* 消去's left button, the partial erase.  Three clicks: the first picks the
 * line, the next two say which piece of it to take out.  CZukeiShoukyo keeps
 * the same three states in +0x21c (0, then 1, then 2, and the third click
 * makes it 3 and runs). */
static int cut_step;
static int cut_obj;             /* which element, while it is being cut */
static double cut_x, cut_y;     /* the first of the two range points */
/* 範囲選択消去 (1066)・連続範囲選択消去 (1067): 0 なし、1 箱の始点待ち、
   2 終点待ち、3 箱を取って実行（Enter）待ち。CZukeiShoukyo の +0x200 が
   1・2 になって範囲選択の働き（CZukeiSentaku）に回る形。shk_rep が 1067 */
static int shk_sel, shk_rep;
static int sel_erase_now(jw_drawing *d);

/* コーナー処理: the first line, and where it was clicked.  CZukeiCorner
   keeps the same in +0x204 (0, then 2 once a line is down, then 3). */
static int corner_step;
static int corner_obj;
static double corner_x, corner_y;
/* 面取 works the same way and keeps its pick in the same three */

/* 点 (32785) -- 原典の名は 仮実点 (string 5251)。そのバーは
 * 1323 仮点・1064 仮点消去・1065 全仮点消去・1066 交点 の四つです。
 *
 * **どれが仮点かは原典に訊いて決めました**（tools/probe151.sh）:
 *
 *   素のクリック      要素の kind (+0x68) が **0**。画面では 5 画素の十字
 *   1323 を押して     kind が **1**。画面では 11 画素の環
 *   全仮点消去 (1065) 消えるのは **kind=1 のほう**。混ぜて置いてから
 *                     押すと、kind=0 だけが残りました
 *   仮点消去 (1064)   押すと「【消去】する仮点を指示してください。」に
 *                     なり、**その状態が続きます** —— 三つ置いて二回
 *                     クリックしたら一つ残りました
 *   交点 (1066)       「線・円（Ａ）を指示してください。」→「線・円【Ｂ】
 *                     …」の二段で、二本の交点に kind=0 の点が落ちます
 *
 * つまり **kind=1 が仮点**です。`src/draw.c` の注は逆のことを書いて
 * いましたが、画素のほうは前から合っています（環を n==1 に描く）。
 */
static int ten_del;             /* 仮点消去 の状態 */
static int ten_cross;           /* 交点: 0 切 / 1 （Ａ）待ち / 2 【Ｂ】待ち */
static int ten_a = -1;          /* 交点 の 線・円（Ａ） */

/* 任意色 —— ソリッドの色 10 で使う色。原典は `doc+0x5e1c` に
 * **COLORREF**（0x00bbggrr）で持っていて、そこへ書くのはバーの
 * 無名の釦 2552 です（`FUN_005bde40`）:
 *
 *   任意色 (2553) が切  `FUN_004eed20` —— 線属性 の窓のほう
 *   入               `CColorDialog` を開いて、OK なら doc+0x5e1c へ
 *
 * 2553 のほうは `doc+0x5e18` にソリッドの色を入れるだけで、切なら 0、
 * 入なら 10（`FUN_005be3c0`）。既定の色は 0x808080 です。
 *
 * ここは原典と同じ COLORREF のまま持ちます（要素の末尾の long が
 * そのまま COLORREF なので。`src/jww.c` の JW_SOLID を見てください）。
 */
static unsigned int solid_any = 0x808080u;

/* 窓に渡すときは 0x00rrggbb に直します */
unsigned int jw_cmd_any_color(void)
{
    return ((solid_any & 0xff) << 16) | (solid_any & 0xff00u)
           | ((solid_any >> 16) & 0xff);
}

void jw_cmd_any_color_set(unsigned int rgb)
{
    solid_any = ((rgb & 0xff) << 16) | (rgb & 0xff00u)
                | ((rgb >> 16) & 0xff);
}

/* 線伸縮: the line, while its end is being moved. */
static int stretch_step;
static int stretch_obj;
static double stretch_t0;       /* where along the line the first click fell */
/* CZukeiShinshuku's +0x210 == 6: the right button down once on an element,
   waiting to see whether the mouse moves (線切断 there) or the right comes
   again (that element is the 基準線).  The point is its +0x220. */
static int stretch_rwait;
static double stretch_rx, stretch_ry;
/* its states 3 and 4: a 基準線 is held -- a copy, as the original holds
   one (+0x218), with the point it was picked at (+0x260) */
static int stretch_based;
static jw_obj stretch_base;
static double stretch_bx, stretch_by;

/* 文字: what has been typed but not placed yet.  The original wants it that
   way round -- type into its floating box first, then click where it goes;
   pressing Enter does not place anything. */
static char line_buf[256];
static int line_n;
static int line_lead_next;      /* the last byte taken was a lead byte */
static int line_drop_trail;     /* a lead byte was refused: drop its trail */
/* 文字: 入力が空のとき (L)/(R) で拾った既存の文字（下の moji_got_pick）。
   1 = 移動・変更（+0x5c4 = 1）、2 = 複写（+0x5c4 = 2）。moji_got_all は
   拾った直後の「全部選んだ」入力欄（FUN_0057f820(0,999)）で、最初の一打が
   全部を置き換える */
static int moji_got, moji_got_i, moji_got_all;
static jw_obj moji_got_was;
/* 斜体 and 太字 from the dialog, which are not part of a 文字種: they go
   into the text's trailing long as 10000 and 20000. */
static int moji_italic, moji_bold;

void jw_cmd_moji_style(int italic, int bold)
{
    moji_italic = italic != 0;
    moji_bold = bold != 0;
}

int jw_cmd_moji_italic(void)
{
    return moji_italic;
}

int jw_cmd_moji_bold(void)
{
    return moji_bold;
}

/* The face a new text is written with: what the 書込み文字種変更 dialog's
   フォント box says, ＭＳ ゴシック until it is changed.  CP932, 47 bytes at
   most.  Anything may be set -- a face the port has no font for is stored
   as given and drawn with the bitmap font -- but the dialog's list holds
   the original's own default and the outline fonts of src/outfont.h. */
static char moji_face[48] = "\x82l\x82r \x83S\x83V\x83" "b\x83N";

const char *jw_cmd_moji_face(void)
{
    return moji_face;
}

void jw_cmd_moji_face_set(const char *face)
{
    size_t n = face ? strlen(face) : 0;

    if (!n || n >= sizeof moji_face) {
        face = "\x82l\x82r \x83S\x83V\x83" "b\x83N";
        n = strlen(face);
    }
    memcpy(moji_face, face, n + 1);
}

/* the typed line put in the drawing's pool, so the preview can be drawn
   without putting it there again on every mouse move */
static int line_off = -1, line_gen, line_shown = -1;
/* what an IME is still converting */
static char comp_buf[256];
static int comp_n;

/* 複線: the line, and how far to one side the copy goes. */
static int para_step;
static int para_obj;
static double para_off;
static int para_last = -1;      /* the copy 連続 carries on from */
static jw_obj para_last_obj;    /* and that copy as it was made: see para_find */
static double tx, ty;           /* where the mouse is now */
static int tracking;

/* 範囲選択 (CZukeiSentaku) and the two commands built on it, 複写 and 移動
 * (both CZukeiFukusha).
 *
 *   0  the box's first corner   「範囲選択の始点をﾏｳｽ(L)で…」
 *   1  its second               「選択範囲の終点を…(L)文字を除く(R)文字を含む」
 *   2  something is selected, waiting for 選択確定
 *   3  being placed             「基準点…」 then 「複写先の点…」
 *
 * The original's own state words are +0x1f8 and +0x1fc while it is choosing
 * a range and +0xfd14 once it is placing (FUN_006533c0).  Which elements are
 * selected is bit 1 of each element's flags at +0x44 -- saving a drawing
 * with a selection keeps it, which is how the rule below was read off the
 * original: it was given a box and the file it wrote said what was in it. */
static int sel_step;

/* The commands that start by taking a range: 範囲選択 and the ones built on
   it.  They all run through the same first two stages. */
static int range_cmd(int c)
{
    return c == JW_CMD_HANI || c == JW_CMD_FUKUSHA || c == JW_CMD_IDOU
        || c == JW_CMD_SEIRI || c == JW_CMD_ZUKEIREG || c == JW_CMD_PARAM;
}
/* パラメトリック変形 (JW_CMD_PARAM) の本体は「パラメトリック変形」の節（sel_place のあと） */
static void param_box(jw_drawing *d, double x0, double y0, double x1,
                      double y1, int with_text);
static const char *param_prompt(void);
static int param_enter(jw_drawing *d);
static void param_settle(void);
static double sel_x0, sel_y0, sel_x1, sel_y1;
/* 範囲外選択 (1334): the box takes what lies wholly *outside* it instead.
   Driving the original says the texts come too, whichever button the second
   corner was given with -- unlike an ordinary box, where the left button
   leaves them out. */
static int sel_outside;
/* 切取り選択 (1344): what crosses the box is cut at its edge and the piece
   inside is what gets picked.  Driving the original bears it out -- a line
   that ran from -140.492 to -190.492 came back starting at the box's own
   edge, -179.239 -- and the texts come along as with 範囲外選択. */
static int sel_cut;
/* 追加範囲 (1065) and 除外範囲 (1066), which the bar offers once a box has
   been taken: the next box adds to what is picked, or takes away from it,
   instead of starting again. */
static int sel_keep, sel_sub;
static double base_x, base_y;   /* 基準点 */
/* 反転 (the second stage's 1067): once pressed, the next click picks the
   基準線 to flip the selection across. */
static int sel_flip;
/* 連続 (二枚目のバーの 1064)。原典 CZukeiFukusha の +0xfd80（回数）、
   +0xfd90/+0xfd98（一回目のずれ）、+0xfda0（一回目の倍率）、+0xfd88
   （初めて押したときの回転角）。sel_place / sel_renzoku を見よ */
static int ren_n;
static double ren_dx, ren_dy, ren_sc, ren_ang;
/* 複写 (the second stage's 2092): the tick says whether the range is
 * copied or moved, and it is **not** the command that says so.
 * 図形複写 comes up with it on and 図形移動 with it off; taking it off in
 * 図形複写 turns that command into a move -- the prompt becomes
 * 「移動先の点を指示して下さい」 and the drawing comes back with the
 * elements shifted, not doubled (tools/probe102.sh). */
static int range_moves(void)
{
    int on = jw_cmd_bar_check(2092);

    return on >= 0 ? !on : current == JW_CMD_IDOU;
}

/* 基点変更 (the second stage's 1066): the next click is the new 基準点, and
   the one after that places as usual. */
static int sel_base_wait;
/* 基準点変更 (the range bar's 1064, before 選択確定): the next click is the
   基準点, and 選択確定 takes it instead of where the mouse is.  CZukeiSentaku's
   slot 22 (FUN_006f8e00) sets +0xac when something is picked, and FUN_006fd240
   then takes the click as the point and drops +0xac.  Read off the decompile;
   the original has not been asked. */
static int sel_base_pick, sel_base_set;
static double sel_base_px, sel_base_py;
/* 任意方向 (the second stage's 1151).  The button cycles through four
   labels -- 任意方向, X 方向, Y 方向, XY方向 -- and each one squares the move
   off: X keeps only the across part, Y only the up-and-down one, and XY
   keeps whichever of the two is the longer.  Read off the original by
   placing the same copy in each of them. */
static int sel_dir;
/* What the selected elements looked like when 基準点 was taken, so a move
   can put them at that place plus the offset however often it is done. */
static jw_obj *sel_was;
static int *sel_at;
static int sel_n;

/* 寸法 (CZukeiSunpo).  Four clicks, and the prompts say what each is for:
 *
 *   0  5329  [寸法] 引出し線の始点を指示して下さい。(L)free (R)Read
 *   1  5330  ■ 寸法線の位置を指示して下さい。(L)free (R)Read
 *   2  5331  ○ 寸法の始点を指示して下さい
 *   3  5332  ● 寸法の終点を指示して下さい。
 *
 * The last two have no "(L)free" on them and that is not an oversight: in
 * the original a click there does nothing at all unless it reads a point.
 * Driving it, a left or a right button on a line's end both moved it on,
 * and a click in open space never did.
 *
 * What comes out is six ordinary elements -- the settings that decide them
 * are in src/gen/sunpo.h, and every one of them showed up in the dimension
 * the original drew for us. */
static int sun_step;
static int sun_made;            /* a dimension has just been made: 5333 asks for the next */
static int ika_step;            /* 一括処理: 0 idle, 1 始線, 2 終線, 3 (R) */
static int ika_live;            /* a dimension is in, so its button is up */
static double ika_tog[512];     /* the 追加・除外 clicks, along the row  */
static int ika_ntog;
static int ika_lt;              /* 同一線種選択: the only 線種 taken   */
static void ika_run(jw_drawing *d);
static double sun_hx, sun_hy;   /* 引出し線の始点                          */
static double sun_lx, sun_ly;   /* 寸法線の位置                            */
static double sun_sx, sun_sy;   /* 寸法の始点, once it has been read       */
/* 寸法's 傾き: any angle, not just the two.  The bar's 0ﾟ/90ﾟ button (1059)
   only writes 0 or 90 into the box -- read out of the original with
   tools/jwdraw.ps1's `read:1411` while pressing it -- so the box is the one
   place the angle lives. */
static void box_put(int id, const char *v);

/* 角度 (1068): the angle between two directions taken about an origin.
 * The original's own status line spells the order out -- 「● 原点を指示して
 * ください」 first, then the two the linear dimension asks for, then the
 * two points measured. */
static int sun_kaku;
static double sun_ox, sun_oy;

/* 累進 (1070): the dimension is drawn as one of a run measured from a
 * common base -- a 点 at the base end, an arrowhead at the far one, and the
 * value stood on end beside it rather than laid along the line. */
static int sun_prog;

/* A length taken from a box is a length the drawing will have to hold, and
 * `jw_numbers_sane` says what a drawing may hold: every coordinate inside
 * ±1e12.  A box takes anything that is made of digits, a dot, a minus and a
 * comma, so `999999999999999999999` goes in as readily as `1000` and comes
 * out of the group's scale as 5e12 -- past that bound, and the four corners
 * it makes can no longer be written out and read back.  Anything that will
 * not fit is treated the same as an empty box.  (tests/fail_test.c's
 * 「rubbish in a number box never makes a rubbish element」 found it.) */
static double box_len_ok(double v)
{
    return v > 0.0 && v < 1e12;
}

/* The same bound for a box whose number goes into an element as it stands
 * -- a radius, a flattening, an angle in degrees.  `deflt` is what an empty
 * box gives, and a number the drawing could not hold gives it too. */
static double box_num(const char *t, double deflt)
{
    double v;

    if (!t || !*t)
        return deflt;
    v = atof(t);
    return (v > -1e12 && v < 1e12) ? v : deflt;
}

static double sun_angle(void)
{
    const char *t = jw_cmd_box(1411);

    return box_num(t, 0.0);
}

/* 円弧 (the 円 bar's 1318): the radius and the start angle taken at the
 * second of its three clicks.  The original asks for the centre, then a
 * point that gives both the radius and where the arc starts, then a point
 * that gives where it ends -- read off its own drawing: a centre, a click
 * to the right of it and a third click up and to the left came out as
 * centre, radius 86.588921, start 0 and sweep 1.107149, which is exactly
 * the angle of that third click.  A whole circle carries a trailing 1; an
 * arc carries 0. */
static double en_r, en_a0;
static int en_step;

/* 中心線: the two lines it runs between, and the first of its two points */
static int chu_a = -1, chu_b = -1, chu_step;
#define CHU_PT (-2)             /* chu_a / chu_b: not a line but a point read with (R), at chu_ax.. / chu_bx.. */
static double chu_ax, chu_ay, chu_bx, chu_by;     /* 二本を拾ったクリック（交わる二本の どちらの半分を拾ったか） */
/* 接線: the circle picked first, and where it was picked -- which of the
   four common tangents comes out is settled by the side each circle was
   pointed at. */
static int ses_a = -1, ses_step;
static double ses_x, ses_y;
/* 角度指定 and 円上点指定 settle on a line first and then take two points
   along it: where it passes through, which way it runs, and the first of the
   two. */
static double ses_lx, ses_ly, ses_ux, ses_uy, ses_t0;
/* which of the bar's four buttons is in force: 0 円→円 (1689), 1 点→円
   (1690).  角度指定 (1691) and 円上点指定 (1692) are not done. */
static int ses_mode = 1689;     /* the bar button: 1689..1692 */
/* 多角形 (32894) の左の四択。原典のバーでは 1690 中心→頂点指定 に
 * 印が付いた状態で出てきます（`decomp/res/bars.txt`）。
 *
 * **寸法 (1411) の箱が何を指すかが、この四択で変わります。**原典に
 * 寸法 1000（縮尺 1/100 なので図寸 10mm）・角数 5 で引かせて測りました
 * （`tools/barsweep.sh`、答えは `decomp/res/bsw_32894_*.jww`）:
 *
 *   1690 中心→頂点指定  外接半径が 10      —— 辺は 11.7557
 *   1691 中心→辺指定    内接半径が 10      —— 辺は 14.5309、外接 12.3607
 *   1692 辺寸法指定      辺そのものが 10    —— 外接 8.5065
 *
 * どれも中心はクリックした点のままです。1689 ２辺 は押しても何も
 * 変わりませんでした（二本を拾う別のやり方なので、三クリックでは
 * 出てきません）。
 *
 * **1068 は分かっていません。**掃き出しでは押したあと多角形が
 * (+辺/2, +内接半径) ずれました（クリックが頂点になる形）が、
 * 同じ釦を続けて押させる `tools/probe160.sh` では、一度押した途端に
 * 状態行が「範囲選択の始点をﾏｳｽ(L)で、連続線をﾏｳｽ(R)で指示して
 * ください。」になり、以後は何も引かなくなりました。二つの結果が
 * 食い違っているので、**決めつけずに手を付けていません**。
 */

#define TG_IS(c) ((c) == JW_CMD_TATEGU || (c) == JW_CMD_TATEGU_DAN)
#define TG_IS3(c) ((c) == JW_CMD_TATEGU_RITSU)

/* 建具平面 (32848).  選ぶ（ファイル選択の窓）→ 基準線 → 位置、を繰り返す。
 * 原典に置かせた答え（tools/probe179〜186.sh、tests/tategu2_test.c）:
 *  ・基準線は壁の線（L）か、二点を読む（R、「２点間の始点指示」）。向きは
 *    **線の向きではなく、右へ（垂直なら上へ）に直したもの**
 *  ・位置は壁へおろした足がブロック①の原点。内法は壁の向きにのびる
 *  ・置いたあとは基準線の問いに戻る */
static int tg_cat = -1, tg_item = -1;   /* 選んだ建具（jw_tgdat の番号と中の何番） */
static int tg_need_pick;
static int tg_step;                     /* 0 基準線 1 位置、R の二点の途中は 2 */
static double tg_ax, tg_ay, tg_ux, tg_uy;
static int au_st;                       /* AUTO の線編集: 0 なし 1 線を押した 2 二点目まで */
static void au_reset(void);
static int hk_north;
static int hk_sub;
static int hk_iso_rng;            /* 範囲指定: 1 始点待ち 2 終点待ち 3 設定済み */
static double hk_rx[4], hk_ry[4], hk_rx0, hk_ry0;
static int hk_iso_on;             /* 等時間の バー */
static int hk_iso_step = 60;      /* 精度（秒）: 60・10・4 */
static int hk_iso_n(jw_drawing *d, double level, double label);
static int hk_tbl_pending;
#define HK_PV_PROMPT "\x81\xa0\x81\xa0\x81@\x81@\x81@\x8d\x80\x96\xda\x82\xf0\x91I\x91\xf0\x82\xb5\x82\xc4\x82\xad\x82\xbe\x82\xb3\x82\xa2\x81@\x81@\x81@\x81\xa0\x81\xa0"
static int hk_pv;                       /* 日影図の 確認 の窓（下の hk_pv_az・hk_pv_el と jw_cmd_hikage_preview） */
static int tn_mode, tn_equi, tn_count, tn_sansha;
static int tn_nq = -1, tn_nq_pend;   /* 真北が無いときの問い（0x15e2、OK/キャンセル）: 答え・待ち */
static int tn_ans = -1, tn_pend, tn_pend_b;   /* 測定点が建物の内側のときの問い: 答え（-1 未回答）・待ち・押したボタン */
static double tn_pend_x, tn_pend_y;
static const jw_view *tn_pend_v;
static int tn_s_plan = 1, tn_s_calc, tn_s_conf;   /* 三斜のバー 9011: 1690 初めから点・1329・2114 */
/* 天空率比較計算 (1066): 0 でなければ 歩み + 1（原典 CZukeiTenkuu +0x1b0 = 0/1/2）。
   tn_cv・tn_cx/cy は 計画・比較 の字の数値と位置、tn_cdec は 小数の桁の大きいほう（+0x828、2 以上）、
   tn_csan は 三斜計算 の字（+0x82c） */
static int tn_cmp, tn_cdec, tn_csan;
static double tn_cv[2], tn_cx[2], tn_cy[2];
static double tn_px, tn_py;
static int hk_pts;
static int hkp_n;
static int hk_calc_step;
static int hk_first_no = 1;
static int hk_outlines(jw_drawing *d, int half);
static double hk_one_hour;
static int hk_write_cond;
static int hk_ask_time;
static void hk_height_text(char *out, size_t cap, const char *box, int d25);
static int auto_back;                   /* AUTO が 複線・矩形 に渡している間 */
static int tg_page2;                    /* ＞ で替わる二枚目のバー */
static int tg_last;                     /* 平面か断面か立面か（最後に入った方） */
static int tg_rh, tg_rv;                /* 立面の基準点: 左・中・右 / 下・中・上 */
static int tg_ref = 4;                  /* 平面・断面の基準点（基準点選択の ○ の番号 0〜14、初めは 左内の中） */
static int tg_need_ref;
static jw_drawing *tg_dst;              /* 仮表示のときの置き先（なければ図面） */

int jw_cmd_tategu_need_ref(void)
{
    int r = tg_need_ref;

    tg_need_ref = 0;
    return r;
}

int jw_cmd_tategu_ref(void)
{
    return tg_ref;
}

void jw_cmd_tategu_set_ref(int idx)
{
    if (idx >= 0 && idx < 15)
        tg_ref = idx;
}

int jw_cmd_tategu_need_pick(void)
{
    int r = tg_need_pick;

    tg_need_pick = 0;
    return r;
}

void jw_cmd_tategu_choose(int catalog, int item)
{
    tg_cat = catalog;
    tg_item = item;
    tg_step = 0;
}

int jw_cmd_tategu_catalog(void)
{
    return tg_cat;
}

/* 線記号変形 (32869).  選ぶ（ファイル選択の窓）→ 線・位置を押す、を繰り返す。
 * 置き方は src/senkigou.c と decomp/res/sk_*.jww（tools/skprobe.sh） */
static int sk_cat = -1, sk_item = -1;   /* 選んだ記号（jw_tgdat の番号と中の何番） */
static int sk_need_pick;
static int sk_step;                     /* 0 最初 1 線２ 2 位置 3 倍率位置 */
static int sk_o1 = -1, sk_o2 = -1;
static double sk_c1x, sk_c1y, sk_c2x, sk_c2y, sk_px, sk_py;
static jw_drawing *sk_dst;              /* 仮表示のときの置き先（なければ図面） */
static jw_sk_run sk_run;                /* 文字入力で止まっているあいだの置きかけ */
static jw_sk_hist sk_hist;              /* "数字"+増分 の行の、前に置いた文字 */
static int sk_op_at = -1;               /* そのときの 元に戻る の番号 */
static int sk_first = -1;               /* 選んだ記号（続けて移った先から戻る） */

int jw_cmd_kigou_need_pick(void)
{
    int r = sk_need_pick;

    sk_need_pick = 0;
    return r;
}

void jw_cmd_kigou_choose(int catalog, int item)
{
    sk_need_pick = 0;
    sk_cat = catalog;
    sk_item = sk_first = item;
    memset(sk_hist, 0, sizeof sk_hist);
    sk_step = 0;
}

/* 文字を打つ箱が出ているか（文字・線記号変形の文字入力） */
int jw_cmd_text_mode(void)
{
    return current == JW_CMD_MOJI || (current == JW_CMD_KIGOU && sk_step == 4);
}

int jw_cmd_kigou_catalog(void)
{
    return sk_cat;
}

int jw_cmd_kigou_item(void)
{
    return sk_item;
}

int jw_cmd_tategu_item(void)
{
    return tg_item;
}

/* 壁の向きを、右へ（垂直なら上へ）の単位ベクトルに */
static int tg_wall(double x0, double y0, double x1, double y1)
{
    double dx = x1 - x0, dy = y1 - y0, l = sqrt(dx * dx + dy * dy);

    if (l <= 1e-9)
        return 0;
    dx /= l;
    dy /= l;
    if (dx < -1e-9 || (fabs(dx) <= 1e-9 && dy < 0.0)) {
        dx = -dx;
        dy = -dy;
    }
    tg_ax = x0;
    tg_ay = y0;
    tg_ux = dx;
    tg_uy = dy;
    return 1;
}


static int tk_mode = 1690;
static int mt_mode = 1689;      /* 面取のラジオ 1689〜1693 */
static int bk_mode = 1689;      /* 分割のラジオ: 1689 等距離・1690 等角度 */
/* 分割始点 (R)。corner_step/corner_obj は 線【A】【B】(L)(L) の既存の歩き
 * （0→1→0、corner_obj が指した線・円）とこれを共用する（CORNER・MENTORI と
 * 同じく、current が BUNKATSU のときしか使わないので衝突しない）。
 *   corner_step 0: 何も指示していない（原典の mode 0/1）
 *   corner_step 1: corner_obj>=0 なら 線・円（Ａ）を (L) で指示済み（mode 2・ac=0）、
 *                  corner_obj<0  なら 始点 Ｐ を (R) で指示済み（bk_px,bk_py、mode 2・ac=1）
 *   corner_step 2: 始点 Ｐ・第二点 Ｐ2 を (R)(R) で指示済み（mode 3）
 * 原典 tools/jwdraw.ps1 を直接叩いた実測（2026-10-13、RESUME.md 参照）で
 * 確かめた式を使う。
 *   bk_rr_n>0（corner_step は 0）: 連続点分割 (RR) の途中。始点 Ｐ と同じ点を
 *                  もう一度 (R) で読むと入る（原典 FUN_00765710 の state 2 の枝、
 *                  FUN_00436970 で +0x100 と同じ点なら +0x138=1・state 0）。 */
static double bk_px, bk_py;     /* corner_step>=1 かつ corner_obj<0: 始点 P */
/* 連続点分割の点列。原典 CZukeiBunkatsu の +0x138（個数、1 始まり）と
   +0x140+i*0x10（点 i、配列は 0x7d4 個）。個数は < 0x7d1 の間だけ増える
   （FUN_00764910・FUN_00765710）ので最大 2001。 */
#define BK_RR_MAX 2001
static double bk_rr_x[BK_RR_MAX + 1], bk_rr_y[BK_RR_MAX + 1];
static int bk_rr_n;
static double bk_p2x, bk_p2y;   /* corner_step==2: 第二点 P2 */
static int bk_a_enko;           /* corner_step==1 かつ corner_obj>=0: 指示した
                                    のが円なら 1、線なら 0（jw_cmd_prompt は
                                    jw_drawing を持たないのでここに控える） */
/* 分割の補助設定（逆コンパイルの読み、原典では押していない）。線（Ａ）を
 * 指示したあと（+0xc0==2・+0xac==0・Ａが CDataSen・割付 +0x7e84 も 等角度
 * +0xb8 も 0）だけ、バーに 3 つの釦が出る（FUN_00763bf0 → FUN_00417640(-1)
 * が テンプレート 299 の隠れた 1066・1064・1065 に 文字列 5611・5612・5609 を
 * 書いて見せる）。押すと WM 0x1403/0x1401/0x1402 → 命令の仮想関数 27/25/26
 * 番目（FUN_00763ee0・FUN_00763cd0・FUN_00763d20）で旗が切り替わる。同じ
 * 三つはクロックメニュー（FUN_007637e0 の 1・2・3 時）からも切り替わる。
 * 旗は Ａを指示し直すとき（FUN_00764910）と分割のあと（FUN_007668f0）に戻る。
 *   bk_gyaku   +0xa8   逆分割: 組んだ線Ｂの端を入れ替える（交差に組む）
 *   bk_senchou +0x7eb0 線長割合分割: 長い線から短い線へ、間隔を線の長さの
 *                      割合で縮める（負の分割数と同じ割付、r=短/長）
 *   +0x7eb4 馬目地分割は 縦分割数の窓と FUN_00767990（7,693 バイト）が
 *   要るので入れていない（釦は出すが押せない）。 */
static int bk_gyaku, bk_senchou;
/* 分割数が負（逆分割、+0x7e98）のときの割付。FUN_007668f0 が r（+0x7ea0）を
 * |分割数| の端数（0.001 未満なら 1）にし、FUN_007674b0 が 刻み
 * bk_step=(1-r)/count と全長を出し、FUN_007697b0 が i 番目の間隔
 * 1-(i-1)×刻み を返す（最初の間隔 1、最後の間隔 r）。 */
static int bk_neg;
static double bk_r = 1.0, bk_step;
static int tk_pos;              /* 中央 (1068): 0 中央・1 頂点・2 辺 */
static int tk2_n;               /* ２辺: 取った点の数 */
static int tk_pickmode;          /* 任意: 円・連続線指示 (1083) の間 */
static int tk_any;              /* 任意 (1070) のバーに入っている */
static void takaku_any(jw_drawing *d);
#define TK_ANY_MAX 1000
static int tk_an;               /* 任意: 積んだ頂点の数 */
static double tk_ax2[TK_ANY_MAX + 1], tk_ay2[TK_ANY_MAX + 1];
static double tk2_x[3], tk2_y[3];
static int tk_step;             /* 寸法が空のとき、一点目を取ったか */
static double tk_ax, tk_ay;
/* 接円: the two elements picked, then a click that says which of the four
   circles of that radius is wanted -- the status line counts them 【 4 − n 】. */
static int sek_a = -1, sek_b = -1, sek_step;
static double sek_ax, sek_ay, sek_bx, sek_by;  /* where each was picked */
static int sek_apt, sek_bpt;    /* 1: that one is a point read with (R) */
/* 曲線: the points clicked so far, kept until 作図実行 is pressed. */
#define CV_MAX 64
static double cv_x[CV_MAX], cv_y[CV_MAX];
static int cv_n;
/* which of the bar's four is in force: 1691 スプライン is the one the
   original enters in; サイン (1689), ２次 (1690) and ベジェ (1692) are not
   done, and pressing 作図実行 in those draws nothing. */
static int cv_mode = 1691;
/* サイン曲線 and ２次曲線 measure everything from a line that is picked
   first: this is its direction, and whether it has been picked yet. */
static double cv_ux = 1.0, cv_uy;
static int cv_base;
/* ハッチ: the closed boundary that was picked, as a ring of corners, or a
   circle.  Right-clicking one line of a closed chain takes the whole chain;
   right-clicking a circle takes the circle. */
#define HT_MAX 256
#define HT_REG 64
static double ht_x[HT_MAX], ht_y[HT_MAX];
static int ht_n;                /* corners used in ht_x/ht_y */
/* the lines picked with the left button, in the order they were picked */
#define HT_CHAIN 64
static int ht_chain[HT_CHAIN];
static int ht_nchain;
/* What is being hatched.  One right click takes one ring or one circle, but
   範囲選択 takes a whole boxful at once, so this is a list: the original
   hatched two rectangles in one go and the lines came out interleaved, in
   one run of offsets across both. */
static struct {
    int round;                  /* a circle rather than a ring */
    int first, n;               /* its corners in ht_x/ht_y */
    double cx, cy, r;
} ht_reg[HT_REG];
static int ht_nreg;
/* ハッチの実寸 (the bar's 1323).  While it is off the ピッチ is in paper
   millimetres, which is how the original comes up; turned on it is in the
   drawing's own units, so it is divided by the write layer group's scale.
   Pitch 2000 with it on drew exactly the same 49 lines as pitch 10 with it
   off in a 1/200 drawing (decomp/res/hatch_jisun.jww against hatch_rect.jww).
   It stays on across commands, the way the boxes keep their numbers. */
static int ht_jisun;
/* 属性変更's two ticks, both on when the command is entered:
   線種・文字種変更 (1352) and 書込みレイヤに変更 (1353). */
static int zh_type = 1, zh_layer = 1;
/* ハッチの基点変 (the bar's 1147).  It asks 「基準点を指示して下さい」 and the
   next click is the point the whole pattern counts from: the lines then sit
   where the distance across is that point's plus a whole ピッチ, and ┬┴┬'s
   grid counts both ways from it.  It does not survive leaving the command --
   the original went back to counting from zero on the way back in. */
static int ht_base, ht_base_wait;
static double ht_bx, ht_by;
/* 範囲選択 (1067): 0 none, 1 waiting for the box's first corner, 2 for its
   second, 3 boxed and waiting for 選択確定. */
static int ht_sel;
/* 図形 (1693): the pattern the hatch lays down, and the box round
   it.  It is **not** the figure 図形読込 read -- that has
   nothing to do with it.  It is what 範囲選択 (1067) picked
   and 選択図形登録 (1068) then registered; with
   nothing registered the original refuses the command outright and says
   so (string 10036,
   「範囲選択で選択図形登録を行ってください。」 -- tools/probe84.sh drew
   nothing at all).  Text and dimensions are left out of it, which is
   what FUN_006765a0 and FUN_00676210 of the decompilation do. */
#define HT_PAT 512
static jw_obj ht_pat[HT_PAT];
static int ht_npat;
static double ht_pxl, ht_pyl, ht_pxh, ht_pyh;

static void ht_mode_set(int id);
static int ht_mode = 1689;      /* 1線, the one the original enters in */
/* The bar keeps one set of numbers for 1線・2線・3線 and another for
   ┬┴┬・図形, and pressing a mode button puts that set up: 1線 shows 角度 45・
   ピッチ 10・線間隔 1, ┬┴┬ shows 角度 0・縦ピッチ 3・横ピッチ 6, and going
   back shows 45・10・1 again, whatever was typed in between (read out of the
   original with tools/jwdraw.ps1's `read:`). */
static char ht_keep[2][3][16] = {
    { "45", "10", "1" }, { "0", "3", "6" }
};
static double chu_x, chu_y;

/* ２線: the line the pair runs along, and the first of the two points */
static double nisen_a, nisen_b;
static int en_kihon;            /* 円・円弧の 基点 (1064): CZukeiEnko の +0x3b */

/* 円・円弧の 基点.  CZukeiEnko slot 8 (FUN_00649520) の終わりの
 * `(0 < +0x3b) && 副モード == 0` の枝をそのまま移したものです。
 * 半径の箱が空なら +0x3b は 2 になり、中心は始点と今の点の中点、半径は
 * 距離の半分。半径があれば、基点の向き 1〜8 で中心を（半径, 半径×扁平率）
 * だけ傾き回しにずらします。角度（始角・掃き）は触りません。 */
static void en_kihon_shift(double *cx, double *cy, double *rad,
                           double dx, double dy, double u, double v,
                           double boxr, double ratio, double tilt)
{
    double c = cos(tilt), sn = sin(tilt), along, perp;
    int k = en_kihon;

    if (k <= 0)
        return;
    if (boxr <= 1e-7) {
        *rad = sqrt(u * u + v * v) / 2.0;
        *cx += dx / 2.0;
        *cy += dy / 2.0;
        return;
    }
    along = *rad;
    perp = boxr * ratio;
    if (k == 4 || k == 8)
        along = 0.0;
    if (k == 5 || k == 6 || k == 7)
        along = -along;
    if (k == 1 || k == 7 || k == 8)
        perp = -perp;
    if (k == 2 || k == 6)
        perp = 0.0;
    *cx = (c * along + *cx) - sn * perp;
    *cy = c * perp + *cy + sn * along;
}
static int nisen_flip;          /* 間隔反転 (1064) */
static int nisen_obj = -1, nisen_step;
static double nisen_x, nisen_y;
/* ２線 の 基準線変更 (LL) で角を回った続き（原典の +0xe6bf0 の鎖を一段だけ
   持つ形）: 書き出し待ちの前の二本・その向きの隔たり・前の基準線 */
static int nisen_chain;
static double nisen_pl[2][4], nisen_ps[2], nisen_pv[4];

/* The boxes on the command bar that hold a number.  Jw_cad keeps these in
 * the command itself, not in the registry, and the values below are the ones
 * the original comes up with: a 多角形 drawn straight after starting came out
 * a pentagon of 1000 (real) radius with its base level.
 *
 * They are what makes the rest of the commands usable, so the port lets them
 * be typed into: a press puts the caret in one (jw_cmd_box_click) and the
 * keys go there instead of to the drawing.
 */
/* The ids are not unique: 1411 is the first combo of nearly every bar, so
   a box belongs to a command as well as to an id. */
static struct { unsigned short cmd, id; char t[64]; } box[] = {
    { JW_CMD_25D, 1491, "10 , 0" },     /* 高さ , 奥行 */
    { JW_CMD_HIKAGE, 1491, "10" },      /* 高さ(m) */
    { JW_CMD_HIKAGE, 1492, "4" },       /* 測定高 */
    { JW_CMD_HIKAGE, 1493, "36" },      /* 緯度 */
    { JW_CMD_TENKU, 1491, "10" },
    { JW_CMD_TENKU, 1492, "" },         /* 測定高（ｍ）、空は 0 */
    { JW_CMD_TENKU, 1493, "" },         /* 天空図半径（図寸mm）、空は 25 */
    { JW_CMD_TENKU, 2216, "" },         /* 測定点表示 の番号、空は表示なし */
    { JW_CMD_TENKU, 2209, "" },         /* 目盛間隔（度）。行は なし・5・10・15・30・45・90（hk_iv*） */
    { JW_CMD_SEN, 1411, "" },           /* 線の傾き */
    { JW_CMD_SEN, 1412, "" },           /* 線の寸法（長さ） */
    { JW_CMD_KUKEI, 1411, "" },         /* 矩形の傾き */
    { JW_CMD_KUKEI, 1413, "" },         /* 矩形の寸法 "横,縦" */
    { JW_CMD_TAKAKU, 1411, "1000" },    /* 寸法      */
    { JW_CMD_TATEGU, 1424, "70" },      /* 建具の 見込 */
    { JW_CMD_TATEGU, 1425, "35" },      /*        枠幅 */
    { JW_CMD_TATEGU, 1426, "1700" },    /*        内法 */
    { JW_CMD_TATEGU, 1427, "0" },       /*        芯ずれ */
    { JW_CMD_TATEGU, 1428, "75" },      /*        内出（S の建具だけ） */
    { JW_CMD_TATEGU, 1429, "75" },      /*        外出 */
    { JW_CMD_TATEGU_DAN, 1424, "70" },      /* 建具の 見込 */
    { JW_CMD_TATEGU_DAN, 1425, "35" },      /*        枠幅 */
    { JW_CMD_TATEGU_DAN, 1426, "1700" },    /*        内法 */
    { JW_CMD_TATEGU_DAN, 1427, "0" },       /*        芯ずれ */
    { JW_CMD_TATEGU_DAN, 1428, "75" },      /*        内出（S の建具だけ） */
    { JW_CMD_TATEGU_DAN, 1429, "75" },      /*        外出 */
    { JW_CMD_TATEGU_RITSU, 1426, "1700 , 1700" }, /* 立面の 内法（幅 , 高さ） */
    { JW_CMD_KIGOU, 1431, "1 , 1" },        /* 線記号変形の 倍率（横 , 縦） */
    { JW_CMD_TATEGU_RITSU, 1430, "" },      /*        角度 */
    { JW_CMD_TAKAKU, 1412, "1000 , 1000" },     /* ２辺の「横 , 縦」 */
    { JW_CMD_TAKAKU, 1413, "5" },       /* 角数      */
    { JW_CMD_TAKAKU, 1414, "0" },       /* 底辺角度  */
    { JW_CMD_MENTORI, 1411, "" },       /* 面取の寸法 -- empty to start with,
                                           the way the original's is */
    { JW_CMD_BUNKATSU, 1411, "" },      /* 分割数, likewise */
    { JW_CMD_NISEN, 1412, "" },         /* ２線の間隔, "a,b"         */
    { JW_CMD_CHUSHIN, 1412, "" },       /* 中心線寸法 -- 空は 終点まで */
    { JW_CMD_SEKIEN, 1411, "" },        /* 接円の半径, likewise */
    { JW_CMD_SEKIEN, 1417, "" },        /* 多重円 -- empty is one circle */
    { JW_CMD_KYOKUSEN, 1411, "7" },     /* 曲線の分割数; the original
                                           comes up with 7 */
    { JW_CMD_SESSEN, 1412, "" },        /* 接線 角度指定 の角度 */
    { JW_CMD_FUKUSHA, 1411, "" },       /* 複写の倍率 */
    { JW_CMD_FUKUSHA, 1412, "" },       /* 複写の回転角 */
    { JW_CMD_IDOU, 1411, "" },          /* 移動の倍率 */
    { JW_CMD_IDOU, 1412, "" },          /* 移動の回転角 */
    { JW_CMD_SUNPO, 1411, "0" },        /* 寸法の傾き */
    { JW_CMD_HATCH, 1419, "45" },       /* ハッチの角度   */
    { JW_CMD_HATCH, 1411, "10" },       /* ハッチのピッチ */
    { JW_CMD_HATCH, 1412, "1" },        /* ハッチの線間隔（２線・３線） */
};
static int box_focus;
/* the box was just clicked and nothing typed yet: what is in it counts as selected, so the first key replaces it
   (a click on a number field does that everywhere else; without it the default 10 had to be backspaced away) */
static int box_fresh;

/* 寸法 の 小数桁 (1061): how many places the value is written to.  The
 * button cycles them, and the original's own drawings say the cycle is
 * 2 -> 3 -> 0 -> 1 -> 2 (the settings start at 2, which is what
 * JW_SUN_DECIMALS carries).  The text's width word carries it as well:
 * 0x2043 for two places, 0x3043 for three, 0x0043 for none, 0x1043 for one
 * -- (places << 12) | 0x43. */
static int sun_keta = -1;

/* ------------------------------------------- 寸法設定 (32925) --------
 *
 * 寸法の形は `src/gen/sunpo.h` に原典の設定から読んだ数として入って
 * いますが、それは**窓から変えられる**ものでした。一つずつ変えて同じ
 * 寸法を引かせ、出てきた要素の差で確かめてあります
 * （`tools/probe147.sh`、【設定値は図寸(mm)単位】）:
 *
 *   1488 文字種類    値の文字が その文字種の 幅・高さ・間隔・色 になる
 *   1489 寸法線色    寸法線の色
 *   2083 引出線色    引出線二本の色
 *   1473 矢印・点色  両端の点（矢印）の色
 *   1475 寸法線と文字の間隔
 *   1477 矢印の長さ  1481 矢印の角度
 *   1479 引出線の突出寸法
 *
 * （`tools/whatdid.py` の `pen` と `type` は名前が入れ替わっています ——
 * 読んでいる +0x28 が線種で +0x2a が色です。`src/jww.h` の注が正しい。）
 */
static int    sun_mojino  = JW_SUN_MOJINO;
static double sun_hanare  = JW_SUN_HANARE;
static double sun_yalen   = JW_SUN_ARROW_LEN;
static double sun_yaang   = JW_SUN_ARROW_ANG;
static double sun_tsuki   = JW_SUN_TSUKIDASHI;
static int    sun_sencol  = JW_SUN_SEN_COLOR;
static int    sun_hikicol = JW_SUN_HIKI_COLOR;
static int    sun_tencol  = JW_SUN_TEN_COLOR;

/* how many places the value is written to, for whoever draws the button */
int jw_cmd_sunpo_decimals(void);

/* The 寸法設定 dialog's boxes, by the id each one carries.  `out` gets
   what the box should show; jw_cmd_sunpo_box_set takes what was typed.
   Anything else is left alone, so the boxes that are not done yet keep
   drawing empty. */
int jw_cmd_sunpo_box(int id, char *out, int n)
{
    switch (id) {
    case 1488: snprintf(out, (size_t)n, "%d", sun_mojino);   return 1;
    case 1489: snprintf(out, (size_t)n, "%d", sun_sencol);   return 1;
    case 2083: snprintf(out, (size_t)n, "%d", sun_hikicol);  return 1;
    case 1473: snprintf(out, (size_t)n, "%d", sun_tencol);   return 1;
    case 1475: snprintf(out, (size_t)n, "%g", sun_hanare);   return 1;
    case 1477: snprintf(out, (size_t)n, "%g", sun_yalen);    return 1;
    case 1479: snprintf(out, (size_t)n, "%g", sun_tsuki);    return 1;
    case 1481: snprintf(out, (size_t)n, "%g", sun_yaang);    return 1;
    }
    return 0;
}

void jw_cmd_sunpo_box_set(int id, const char *t)
{
    double v;

    /* **打ったものをそのまま入れます。**原典がこの箱に何を許すのか
       ――上限・下限・弾かれたときどうなるか―― は**まだ訊いていま
       せん**。勝手に範囲を決めると、その範囲が原典のものだと後から
       読めてしまうので置きません。使う側は値を使うところで自分で
       守っています（文字種は `i < 0 || i >= 10` で 0 に落とす、など）。
       原典に訊いたら、ここにその答えを書いてください。 */
    if (!t || !*t)
        return;
    v = atof(t);
    switch (id) {
    case 1488: sun_mojino  = (int)v; break;     /* 文字種類 */
    case 1489: sun_sencol  = (int)v; break;     /* 寸法線色 */
    case 2083: sun_hikicol = (int)v; break;     /* 引出線色 */
    case 1473: sun_tencol  = (int)v; break;     /* 矢印・点色 */
    case 1475: sun_hanare  = v;      break;     /* 寸法線と文字の間隔 */
    case 1477: sun_yalen   = v;      break;     /* 矢印の長さ */
    case 1479: sun_tsuki   = v;      break;     /* 引出線の突出寸法 */
    case 1481: sun_yaang   = v;      break;     /* 矢印の角度 */
    }
}

static int sun_decimals(void)
{
    return sun_keta < 0 ? JW_SUN_DECIMALS : sun_keta;
}

/* バーのラジオ（BS_AUTORADIOBUTTON）の点き具合。選ばれていれば 1、
 * 選ばれていなければ 0、移植がまだ持っていない命令は -1（取り込んだ
 * 初期値のまま）。 */
int jw_cmd_bar_radio(int id)
{
    switch (current) {
    case JW_CMD_TAKAKU:   return id == tk_mode;
    case JW_CMD_KYOKUSEN: return id == cv_mode;
    case JW_CMD_SESSEN:   return id == ses_mode;
    case JW_CMD_HATCH:    return id == ht_mode;
    case JW_CMD_MENTORI:  return id == mt_mode;
    case JW_CMD_BUNKATSU: return id == bk_mode;
    default:              return -1;
    }
}

int jw_cmd_takaku_pos(void)
{
    return tk_pos;
}

int jw_cmd_sunpo_decimals(void)
{
    return sun_decimals();
}


/* 寸法 の 半径 (1065): one click on a circle instead of two points on a
 * line.  0 is the ordinary two-point dimension. */
static int sun_radius;          /* 1 = 半径, 2 = 直径 */
/* Esc-only: whether 半径／直径 has drawn one yet this activation.  Kept
   apart from sun_made, which the prompt (jw_cmd_prompt) also reads for the
   base/角度/円周 "次へ" tail -- 半径／直径 has no such tail (its own
   prompt is a pre-existing gap, not this one's to fix), so sharing the
   flag would change what the bar says instead of only how Esc behaves. */
static int sun_radius_made;

/* 寸法 の 寸法値 (1069): the value on its own, with no dimension line and
 * no extension lines.  The original was asked and, given two left clicks,
 * wrote one text and nothing else -- the very text the two-point dimension
 * writes: the distance in real units, centred on the middle of the two
 * points, half a millimetre off to the left of the way they run, ltype 2
 * and (places << 12) | 0x043 in the width word.
 *
 * Its prompt is 5576 to begin with and 5333 once one is in, which is what
 * `sun_chi_done` is for.  (R) there moves an existing value and (RR)
 * changes one; neither is done. */
static int sun_chi;
static int sun_chi_done;

/* 寸法 の 円周 (1067): the length of an arc of a circle, written round the
 * circle itself.
 *
 * Read off the original's own drawing (tools/probe17.sh).  Given a circle
 * to indicate, then 引出し線の始点, then 寸法線の位置, then two read points
 * on the circle, it wrote exactly what 角度 writes and in the same order --
 * the value, the arc, a 点 at each end of it, an 引出線 along each way in --
 * with three differences: the origin and the radius come from the circle
 * that was indicated rather than from a click of its own, the value is the
 * length of the arc on THAT circle (its radius times the sweep, in real
 * units) and not an angle, and the text does not carry 角度's 0x0400.
 *
 * The sweep runs anticlockwise, which is what the status line says:
 * 「○　寸法の始点を指示して下さい　（左回り）円周」.
 *
 * A circle on its own has nothing on it that can be read, and those two
 * points have to be read ones, which is why four passes of asking the
 * original drew nothing at all.  The fifth put a chord across the circle
 * and read its ends. */
static int sun_enshu;
static double sun_er;           /* the radius of the circle indicated */

/* 寸法 の 端部 (1062): a point at each end of the dimension line, or an
 * arrowhead.  The button turns it over. */
static int sun_arrow = -1;

static int sun_arrows(void)
{
    return sun_arrow < 0 ? JW_SUN_ARROW : sun_arrow;
}

/* whether 端部 is arrowheads rather than points, for the button that
   says so on the bar */
int jw_cmd_sunpo_arrows(void)
{
    return sun_arrows();
}


/* Everything else on the bars.
 *
 * A command bar is a CDialogBar in the original and the things on it are
 * real controls: a checkbox ticks when it is clicked and a combo takes what
 * is typed into it, whether or not the command reads it afterwards.  The
 * port answered for the handful it acts on and drew the rest, so most of
 * them were pictures -- clicking １５度毎 did not even move the tick, which
 * is the first thing anyone tries.  These hold the state of every control on
 * every bar instead, keyed by the command and the control id the way the
 * table above is, and seeded from how the original has it (the `checked`
 * field src/gen/bars.h carries, read out of the running original).
 *
 * What each control *does* is another matter, and gets written command by
 * command with an answer drawn by the original to score it against.  This is
 * the state alone, which is what the bar is drawn from.
 */
/* One slot per (command, control) for the ticks and the boxes.  The bars
   hold 94 checkboxes between them and a command can be in two states (the
   plain bar and the one a settled range puts up), so 96 was close enough to
   full that a box could quietly stop answering. */
#define JW_NBARSTATE 384
static struct { unsigned cmd; unsigned short id; unsigned char on; }
    chk[JW_NBARSTATE];
static int nchk;
static struct { unsigned cmd; unsigned short id; char t[64]; }
    xbox[JW_NBARSTATE];
static int nxbox;

/* Which bar is up: the command's own, or the one it puts up once a range is
   settled -- 複写・移動・データ整理 each have a second one, filed under
   100000 + the command the way tools/bars2.ps1 writes it. */
static unsigned bar_cmd(void)
{
    /* 選び終えた範囲が残っていても、二つ目のバーを持つのは 範囲を扱う命令だけ
       （複写のあとの 分割 で 割付 の印が 別のスロットに入った: fuzz s24_8） */
    return sel_step == 3 && range_cmd(current) ? 100000u + (unsigned)current : (unsigned)current;
}

/* The checkbox with this id on that bar, made the first time it is asked
   for.  NULL when the original has no checkbox there. */
static unsigned char *chk_slot(unsigned cmd, int id)
{
    int i, on = 0;

    for (i = 0; i < nchk; i++)
        if (chk[i].cmd == cmd && chk[i].id == (unsigned short)id)
            return &chk[i].on;
    if (nchk == JW_NBARSTATE || ui_bar_ctl(cmd, id, &on) != 'c')
        return 0;
    chk[nchk].cmd = cmd;
    chk[nchk].id = (unsigned short)id;
    chk[nchk].on = (unsigned char)(on != 0);
    return &chk[nchk++].on;
}

/* The text of a box on that command's bar: the ones the table above gives a
   starting value to, and an empty one for every other combo the original
   has there.  NULL when it has no combo with that id. */
static char *box_slot(unsigned cmd, int id)
{
    int i;

    /* the table above is keyed by the command itself, because a box like
       複写's 倍率 is the command's whether or not the range is in yet */
    for (i = 0; i < (int)(sizeof box / sizeof box[0]); i++)
        if (box[i].id == (unsigned short)id && box[i].cmd == current)
            return box[i].t;
    for (i = 0; i < nxbox; i++)
        if (xbox[i].cmd == cmd && xbox[i].id == (unsigned short)id)
            return xbox[i].t;
    if (nxbox == JW_NBARSTATE || ui_bar_ctl(cmd, id, 0) != 'o')
        return 0;
    xbox[nxbox].cmd = cmd;
    xbox[nxbox].id = (unsigned short)id;
    xbox[nxbox].t[0] = 0;
    return xbox[nxbox++].t;
}

/* 別のコマンドの箱の中身（box_slot は いまのコマンドの表を先に見るので）。無ければ NULL。
   天空図の 太陽軌跡 が 日影図の 緯度・季節 を読むのに使う */
static const char *box_of(unsigned cmd, int id)
{
    int i;

    for (i = 0; i < (int)(sizeof box / sizeof box[0]); i++)
        if (box[i].id == (unsigned short)id && box[i].cmd == cmd)
            return box[i].t;
    for (i = 0; i < nxbox; i++)
        if (xbox[i].cmd == cmd && xbox[i].id == (unsigned short)id)
            return xbox[i].t;
    return NULL;
}

/* 多角形 (CZukeiTakakukei).  The bar's 中心→頂点指定 is the mode it starts
 * in, and with a 寸法 in the box one click on the centre draws the whole
 * thing -- which is what the original does: a click left a regular pentagon
 * behind, and another click left a second one.
 */

static void sel_free(void);
static void sel_clear(jw_drawing *d);
static int hatch_chain(const jw_drawing *d);

/* 元に戻る works a command at a time, not an element at a time: drawing a
 * rectangle in Jw_cad and pressing it puts the drawing back to 46 lines, all
 * four at once (tmp/jwdraw.ps1 with -After 57643).  So what is remembered is
 * how many elements each command added, and one press takes back the last
 * command's worth.  Adding at the end is all the commands here do, so the
 * count is all that has to be kept. */
/* One step of 元に戻る.  A command can add elements at the end, take one
   out, and change others in place -- a partial erase does the first two, a
   corner does the third to both of its lines -- and one press has to undo
   all of it. */
typedef struct {
    int at;                     /* where it was */
    int removed;                /* 0 changed, 1 taken out of the drawing,
                                   2 taken out of the block definitions past
                                   it (which go back a different way),
                                   3 put into a block definition at `at`
                                   (undo takes that index out again, wherever
                                   the definition sits) */
    jw_obj was;
} op_item;

typedef struct {
    int n;                      /* how many were added, at the end */
    int add_at;                 /* unless they went in somewhere else: this
                                   is that index plus one (ブロック解除 puts
                                   them where the reference was) */
    int ndef;                   /* and how many past the drawn ones, which
                                   is what a new block definition is */
    int nitem, citem;
    op_item *item;              /* 移動 changes a whole selection at once,
                                   so there is no useful upper bound */
    /* What the drawing looked like **before this step was undone**,
       which is what 進む puts back.  Filled in by jw_cmd_undo and
       thrown away when a new step is taken.  The original keeps the
       same thing -- its 戻る and 進む read a whole drawing back
       (FUN_00458a80 and FUN_00453bd0 write and read a version 700
       .jww, $EDTBLK<n>.<nnn>, when it does not fit in memory). */
    jw_obj *after;
    int nafter, ndrawn_after;
    /* and the drawn elements the undo took out, in the order it took
       them.  進む puts these back **at the front** of the drawing, which
       is what the original does (see jw_cmd_redo). */
    jw_obj *back;
    int nback;
    unsigned gen;               /* which step this is, for jw_cmd_edit_stamp */
    /* The whole drawing as it stood before the step, for a step that puts
       things in at more than one place (ブロック解除 of several references:
       each one's members go where that reference was, and add_at can only
       say one place).  戻る puts this back whole; 進む uses `after`. */
    jw_obj *before;
    int nbefore, ndrawn_before;
} op_t;

/* Remember an element as it is now, so it can be put back. */
static op_item *op_keep(op_t *o, const jw_drawing *d, int at, int removed)
{
    op_item *it;

    if (!o || at < 0 || at >= d->nobj)
        return 0;
    if (o->nitem == o->citem) {
        int n = o->citem ? o->citem * 2 : 4;
        op_item *p = (op_item *)realloc(o->item, (size_t)n * sizeof *p);
        if (!p)
            return 0;
        o->item = p;
        o->citem = n;
    }
    it = &o->item[o->nitem++];
    it->at = at;
    it->removed = removed;
    it->was = d->obj[at];
    return it;
}

static op_t *op;
/* nop is how many steps can still be undone; ntop is how many there
   are altogether, so op[nop .. ntop) are the ones 進む can step back
   into.  Taking a new step throws those away. */
static int nop, ntop, cop;
static unsigned op_serial;

static void op_drop(op_t *o)
{
    free(o->item);
    free(o->after);
    free(o->back);
    free(o->before);
    memset(o, 0, sizeof *o);
}

static op_t *op_new(void)
{
    while (ntop > nop)
        op_drop(&op[--ntop]);
    if (nop == cop) {
        int c = cop ? cop * 2 : 64;
        op_t *p = (op_t *)realloc(op, (size_t)c * sizeof *p);
        if (!p)
            return 0;
        op = p;
        cop = c;
    }
    memset(&op[nop], 0, sizeof op[nop]);
    op[nop].gen = ++op_serial;
    ntop = nop + 1;
    return &op[nop++];
}

static void op_push(int n)
{
    op_t *o;

    if (n <= 0)
        return;
    o = op_new();
    if (o)
        o->n = n;
}

#define PI 3.14159265358979323846

/* 画像編集 (see the block at the end of this file) */
static void gz_reset(void);
static int  gz_midway(void);
static int  gz_pending(jw_drawing *d, jw_obj *o, int max);
static int  gz_bar(jw_drawing *d, int id);
static void gz_point(jw_drawing *d, const jw_view *v, double x, double y, int button);

/* A number typed into a command bar box, in paper millimetres.
 *
 * The boxes hold real-world lengths, so what goes on the paper is that over
 * the scale of the layer group being written to: the original, given 1000 in
 * 矩形's 寸法 on a 1/200 group, drew a square 5 mm across.  Returns 0 when
 * the box is empty or the drawing is not there, which is what tells the
 * command to work the free way instead.
 */
static double write_scale(const jw_drawing *d)
{
    int i, wg = 0;

    if (!d)
        return 1.0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

static double box_mm(const jw_drawing *d, int id)
{
    const char *t = jw_cmd_box(id);
    double v;

    if (!t || !*t || !d)
        return 0.0;
    v = atof(t);
    if (v <= 0.0)
        return 0.0;
    v /= write_scale(d);
    return box_len_ok(v) ? v : 0.0;
}

/* the second number of a "横,縦" box, or the first again when there is only
   one -- the original draws a square from 寸法 1000 as readily as from
   1000,1000 */
static double box_mm2(const jw_drawing *d, int id)
{
    const char *t = jw_cmd_box(id);
    const char *p = t ? strchr(t, ',') : 0;
    double v;
    int i, wg = 0;

    if (!p || !p[1] || !d)
        return box_mm(d, id);
    v = atof(p + 1);
    if (v <= 0.0)
        return 0.0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        v /= d->group[wg].scale;
    return box_len_ok(v) ? v : 0.0;
}

/* 連続線 の 丸面辺寸法 (1411) と 実寸 (2096).
 *
 * 原典に直角・鋭角・短い辺・一直線・五点で引かせた答え
 * （`tools/probe159.sh`・`tools/probe162.sh`、`decomp/res/p159_*.jww`・
 * `p162_*.jww`）から。箱の数は**半径ではなく角からの辺の長さ**で、
 * 円弧は両辺に接します。実寸 を点けると箱は実寸で（図寸は 割る 縮尺）、
 * 点けないと**図寸 mm のまま**です（ほかの箱と逆）。
 *
 * 次の点が来るたびに、ひとつ前の辺と、その終わりの角の弧が出ます:
 * 辺は（前の角で削った始点）から（角から辺寸法だけ手前）まで、弧は
 * 辺寸法 t と 振れ角 から 半径 t·tan(φ/2)（φ は角の内角）。
 * **辺の向きは削った始点から角へ向けて引き直す**ので、辺が t より短い
 * と手前が先へ突き抜けます。一直線（φ=180°）は何も出ません。 */
static double rn_sx, rn_sy;     /* 辺の（削った）始点 */

static double renzoku_edge(const jw_drawing *d)
{
    const char *t = jw_cmd_box(1411);
    double v = t && *t ? atof(t) : 0.0;

    if (v <= 0.0)
        return 0.0;
    if (jw_cmd_bar_check(2096) > 0)
        v /= write_scale(d);
    return box_len_ok(v) ? v : 0.0;
}

static void renzoku_round(jw_drawing *d, double t, double nx, double ny)
{
    double px = rx, py = ry;
    double dx = px - rn_sx, dy = py - rn_sy;
    double ex = nx - px, ey = ny - py;
    double dl = sqrt(dx * dx + dy * dy), el = sqrt(ex * ex + ey * ey);
    double cr, dt, turn, phi, r, bx, by, bl, cdist, cx, cy, t1x, t1y, t2x, t2y;
    jw_obj *o;
    int made = 0;

    if (dl <= 0.0 || el <= 0.0) {
        rn_sx = px;
        rn_sy = py;
        return;
    }
    dx /= dl;
    dy /= dl;
    ex /= el;
    ey /= el;
    cr = dx * ey - dy * ex;
    dt = dx * ex + dy * ey;
    if (fabs(cr) < 1e-9) {      /* 一直線（かUターン）は何も出ない */
        rn_sx = px;
        rn_sy = py;
        return;
    }
    turn = atan2(cr, dt);
    phi = PI - fabs(turn);      /* 内角 */
    r = t * tan(phi / 2.0);
    t1x = px - t * dx;
    t1y = py - t * dy;
    t2x = px + t * ex;
    t2y = py + t * ey;
    bx = -dx + ex;
    by = -dy + ey;
    bl = sqrt(bx * bx + by * by);
    if (bl <= 0.0) {
        rn_sx = px;
        rn_sy = py;
        return;
    }
    cdist = t / cos(phi / 2.0);
    cx = px + bx / bl * cdist;
    cy = py + by / bl * cdist;
    o = jw_add(d, JW_SEN);
    if (o) {
        o->d[0] = rn_sx;
        o->d[1] = rn_sy;
        o->d[2] = t1x;
        o->d[3] = t1y;
        made++;
    }
    o = jw_add(d, JW_ENKO);
    if (o) {
        o->d[0] = cx;
        o->d[1] = cy;
        o->d[2] = r;
        o->d[3] = atan2(t1y - cy, t1x - cx);
        o->d[4] = turn;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        o->n = 0;
        made++;
    }
    if (made)
        op_push(made);
    rn_sx = t2x;
    rn_sy = t2y;
}


/* The readout the original hangs off the end of the status line while a
 * command is drawing.  Asked of it (tools/probe26.sh), with a 1/100 sheet:
 *
 *   線    始点を指示してください  (L)free  (R)Read   [ -26.565°]   27,380.424
 *   矩形  始点を指示してください  (L)free  (R)Read     W=24,489.795    H=12,244.897
 *   円    中心点を指示してください  (L)free  (R)Read      r = 6,122.448
 *
 * -- the angle and length of the line just drawn, the width and height of
 * the rectangle, the radius of the circle, all in real units to three
 * places with a comma every three digits.  Before anything is drawn there
 * is no tail at all, while the first point is down it reads 0.000 until
 * the mouse moves, and leaving the command takes it away again. */
static int tail_kind;           /* 0 none, 1 線, 2 矩形, 3 円, 4 測定 */
static double tail_a, tail_b;   /* in paper millimetres, or degrees */

static void tail_set(int kind, double a, double b)
{
    tail_kind = kind;
    tail_a = a;
    tail_b = b;
}

/* a real-world length, three places, with a comma every three digits */
static void num3(char *out, int n, const jw_drawing *d, double mm)
{
    char buf[64];
    int i, len, whole, k = 0, neg;
    double v = mm;
    int g, wg = 0;

    for (g = 0; d && g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    if (d && d->group[wg].scale > 0.0)
        v *= d->group[wg].scale;
    neg = v < 0.0;
    if (neg)
        v = -v;
    snprintf(buf, sizeof buf, "%.3f", v);
    len = (int)strlen(buf);
    whole = (int)(strchr(buf, '.') ? strchr(buf, '.') - buf : len);
    if (neg && k < n - 1)
        out[k++] = '-';
    for (i = 0; i < len && k < n - 1; i++) {
        if (i && i < whole && (whole - i) % 3 == 0)
            out[k++] = ',';
        if (k < n - 1)
            out[k++] = buf[i];
    }
    out[k] = 0;
}

/* -------------------------------------------------------- 測定 --------
 *
 * 距離測定 —— 命令の既定の歩きです。点を打つたびに、状態表示の末尾が
 *
 *     S = 1 / 100  【 73.469ｍ 】   12.2449ｍ
 *
 * になります。【】の中が**これまでの合計**、その右が**いま足した一辺**。
 * 原典に 400x200 画素の四角を一周させて読みました（`tools/probe125.sh`、
 * 1/100 の紙）:
 *
 *   打つ前     【 0.000ｍ 】   0ｍ
 *   一点目     【 0.000ｍ 】   -0ｍ
 *   二点目     【 24.490ｍ 】   24.4898ｍ
 *   三点目     【 36.735ｍ 】   12.2449ｍ
 *   四点目     【 61.224ｍ 】   24.4898ｍ
 *   五点目     【 73.469ｍ 】   12.2449ｍ
 *
 * 400 画素は紙で 244.898 mm、1/100 なので実寸 24.4898 m —— 合計は
 * **小数桁 3**（バーの釦 1070 がそう言っています）、一辺のほうは
 * %g と同じ六桁です。単位は 【ｍ】（釦 1069 が mm と切り替える）。
 *
 * **「足したものが零」のときは「-0」**と書かれます —— 距離の一点目も、
 * 面積の輪を閉じる一手も。
 *
 * 面積測定 (1065) —— 同じ読み出しで、単位が ｍ2 になります。四角を
 * 一周させると 【 299.875ｍ2 】 149.938ｍ2。合計は多角形の面積で、右は
 * **いま足した三角形**（始点・前の点・いまの点）。400x200 画素は実寸
 * 24.4898 x 12.2449 m なので 299.875 m2 ちょうどです。符号は**画面の
 * 向き**（y が下）の靴紐式そのままで、この回り方だと正になり、輪を
 * 閉じる一手は -0 になります。**逆回りは訊いていません。**
 *
 * 角度測定 (1067) —— 三手です。原点 (5404) → 基準点 (10117) →
 * 角度点 (10118) と訊き、読み出しは 【 -26.565° 】。(300,300) を原点、
 * (700,300) を基準点、(700,500) を角度点にした答えで、つまり
 * **原点→基準点 から 原点→角度点 までの角**です。S = 1 / … は付きません。
 *
 * mm /【ｍ】 (1069) —— 単位が mm になり、合計のほうだけ三桁ごとに
 * コンマが入ります（【 24,489.796mm 】、右は 24489.8mm のまま）。札は
 * 【mm】／ ｍ に変わり、面積の単位は mm2 になります。**角度測定 の間は
 * この釦が 【 °】／ °′″ になり、○単独円指定 (1068) は死にます**
 * （まだどちらも入れていません）。

 * 四つの 〜測定 のうちどれが凹んで見えるかは、原典が自前で描いている
 * ので EnumChildWindows からは分かりませんでした。**絵で測るのが次**です。
 *
 * 小数桁 3 (1070) —— 押すたびに **3 → 4 → F → 0 → 1 → 2 → 3** と回り、
 * 釦の札もそのとおりに変わります（`tools/probe130.sh`）。**F は小数六桁**
 * （24.489796）。右の一辺はいつも %g で、mm の面積だと 1.49938e+08 のように
 * 指数まで出ます。
 *
 * 座標測定 (1066) —— 原点 (5404) を置くと、そこからの**マウスの今の
 * 位置**を 【 x , y 】 で映します。投げたクリックでは測れないので、
 * `m<x>,<y>` で本物のカーソルを動かして読みました
 * （`tools/probe141.sh`）。原点を画面の (300,300) に置いて:
 *
 *   カーソル (500,400)   【 12.245ｍ , -6.122ｍ 】
 *   カーソル (700,300)   【 24.490ｍ , 0.000ｍ 】
 *   カーソル (300,300)   【 0.000ｍ , 0.000ｍ 】
 *
 * 200 画素は紙で 122.449 mm、1/100 なので 12.2449 m —— 距離測定 と同じ
 * 換算で、画面の下は負です。小数桁も単位も同じものが効きます。
 *
 * ○単独円指定 (1068) —— 押すと問いかけが「円を指示してください。」
 * (5367) になり、**次の一手で円を一つ指す**と、その**周長**が合計に
 * 入ります。半径 100 画素（紙で 61.2245 mm、1/100 なので実寸 6.12245 m）
 * の円を指すと 【 38.468ｍ 】 38.4685ｍ —— 2πr そのものです
 * （`tools/probe142.sh`）。指したあとは 始点 の問いかけに戻り、印も
 * 下りて、次のクリックはふつうの一点目になります。
 *
 * 楕円・円弧・面積測定 と組んだときは訊いていません。
 *
 * 測定結果書込 (1071) —— 押すと**走っていた測りが 0 に戻り**、問いかけが
 * 「文字の位置を指示して下さい」(5318) になります。次のクリックで、
 * そのときの読み出しの数が**文字として置かれます**。三度試して三度とも
 * 同じで、合計 24.490 のときに押しても書かれたのは `0.000ｍ` でした
 * （投げても送っても、押す前に測っても後に測っても。`tools/probe129.sh`・
 * `probe142.sh`・`probe143.sh`）。妙ですが、原典がそう書きます。
 *
 * 置かれる文字は 文字種 2・高さ 2.5・幅 2.5・間隔 0、書込ペン、
 * 種類 1、flags 0x4000 で、クリックした所が左下です
 * （`decomp/res/sokutei_write.jww`）。
 *
 * 書込設定 (1072) は押しても窓も問いかけも変わりませんでした。
 * 角度測定 の途中の数もマウス任せで、そこは合わせていません。 */
#define SOK_LEN  1064           /* 距離測定 */
#define SOK_AREA 1065           /* 面積測定 */
#define SOK_XY   1066           /* 座標測定 */
#define SOK_ANG  1067           /* 角度測定 */

static int sok_mode = SOK_LEN;
static int sok_one;             /* ○単独円指定: the next click is a circle */
static int sok_write;           /* 測定結果書込: the next click is where */
static int sok_unit;            /* 0 ｍ, 1 mm */
static int sok_dp = 3;          /* 小数桁: 0..4、5 は F（小数六桁） */
static int sok_dms;             /* 角度測定 の 1069: 度分秒で読む（原典 DAT_00a0be54） */
#define SOK_MAX 256
static double sok_rx[SOK_MAX], sok_ry[SOK_MAX];  /* every point, for 仮表示 */
static int sok_n;               /* how many points are down */
static int sok_esc;             /* Esc was pressed: the prompt says 始点 again though the chain goes on */
static double sok_px, sok_py;   /* the last one, in paper millimetres */
static double sok_x0, sok_y0;   /* the first, which 面積 and 角度 need */
static double sok_total;        /* the run so far */
static double sok_seg;          /* the leg, or triangle, just added */

static void sok_reset(void)
{
    sok_n = 0;
    sok_total = 0.0;
    sok_seg = 0.0;
    sok_one = 0;
    sok_esc = 0;
}

/* how many decimals 小数桁 is asking for: F means six */
static int sok_places(void)
{
    return sok_dp == 5 ? 6 : sok_dp;
}

/* 測定's numbers: so many places, and a comma every three digits.
   num3 is the same thing with the places fixed at three and the scale
   applied inside; here the caller has converted already. */
static void sok_num(char *out, int n, double v, int dp)
{
    char buf[64];
    int i, len, whole, k = 0, neg = v < 0.0;

    if (neg)
        v = -v;
    snprintf(buf, sizeof buf, "%.*f", dp, v);
    len = (int)strlen(buf);
    whole = (int)(strchr(buf, '.') ? strchr(buf, '.') - buf : len);
    if (neg && k < n - 1)
        out[k++] = '-';
    for (i = 0; i < len && k < n - 1; i++) {
        if (i && i < whole && (whole - i) % 3 == 0)
            out[k++] = ',';
        if (k < n - 1)
            out[k++] = buf[i];
    }
    out[k] = 0;
}

/* An angle as 度分秒, the original's FUN_00459e40 (read off the decompile;
   not asked of the original): the seconds take 小数桁's places, and if they
   come out as "60..." they are 0 and the minute goes up; minutes and
   seconds under ten get a 0 in front, and the marks are the half-width
   ﾟ ' " (strings 6195・6197・6199 -- the full-width ones are for when
   DAT_00a0bd24 is set, which the port does not have). */
static void sok_dms_str(char *out, int n, double v)
{
    double a = fabs(v), m, sec;
    int deg = (int)a, mn;
    char s[64], ss[72], ms[24];

    m = (a - (double)deg) * 60.0;
    mn = (int)m;
    sec = (m - (double)mn) * 60.0;
    sok_num(s, (int)sizeof s, sec, sok_places());
    if (s[0] == '6' && s[1] == '0') {
        sec = 0.0;
        mn++;
        sok_num(s, (int)sizeof s, 0.0, sok_places());
    }
    sec = atof(s);
    snprintf(ss, sizeof ss, "%s%s\"", 10.0 <= sec ? "" : "0", s);
    if (mn > 59) {
        mn -= 60;
        deg++;
    }
    snprintf(ms, sizeof ms, "%s%d'", mn < 10 ? "0" : "", mn);
    snprintf(out, (size_t)n, "%s%d\xdf%s%s", 0.0 <= v ? "" : "-", deg, ms, ss);
}

/* The readout's number and its unit, which is also what 測定結果書込
   writes.  `out` gets so many places and a comma every three digits. */
static void sok_value(char *out, int n, const jw_drawing *d, double v)
{
    double sc = 1.0, f;
    const char *u;
    char num[64];
    int g, wg = 0;

    for (g = 0; d && g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    if (d && d->group[wg].scale > 0.0)
        sc = d->group[wg].scale;
    if (sok_mode == SOK_AREA) {
        f = sc * sc / (sok_unit ? 1.0 : 1000000.0);
        u = sok_unit ? "mm2" : "\x82\x8d" "2";
    } else {
        f = sc / (sok_unit ? 1.0 : 1000.0);
        u = sok_unit ? "mm" : "\x82\x8d";
    }
    sok_num(num, (int)sizeof num, v * f, sok_places());
    snprintf(out, (size_t)n, "%s%s", num, u);
}


/* ------------------------------------------------ 距離指定点 ----------
 *
 * 一点目を打つと問いかけが
 *
 *   線上･円周距離は線･円指示 ﾏｳｽ(L) 、 距離の方向は読取点指示 ﾏｳｽ(R)
 *
 * に変わり、次の読取点が**向き**を言います。置かれるのは点ひとつで、
 * 始点からその向きへ**箱の 距離**だけ行った所です（`tools/probe128.sh`:
 * 1/100 の紙で 距離 1000 を打ち、273.804 mm の線の一方の端を始点、
 * もう一方を読取点にすると、点は始点から紙で 10.0000001 mm、線の上に
 * 乗って出ました —— 1000 は実寸で、紙にはその 1/100）。
 *
 * **仮点 (1323) を入れると、置かれる点の種別が 1 になります**（素の点は
 * 0）。線を指す (L) のほうは、始点が線に乗っている今回の形では読取点と
 * 同じ答えになったので、**線から離れた所を始点にしたときは訊いていません**。
 */
static int kyo_step;
static double kyo_x, kyo_y;

/* the 傾き box, in radians */
static double box_angle(int id)
{
    const char *t = jw_cmd_box(id);

    return box_num(t, 0.0) * PI / 180.0;
}

/* 設定 > 角度取得 and 設定 > 長さ取得: a number taken off something
 * already drawn instead of typed into the command bar.
 *
 * What the original does with it was asked the only way it could be --
 * the value goes nowhere the port can see (the two combo boxes stay
 * empty and the status line goes back to what it was), so the same line
 * was drawn twice, once with the value taken and once without
 * (tools/probe20.sh .. probe22.sh).  With a reference line at -26.565
 * degrees and 273.804 long:
 *
 *   線角度 (32932)  the lines drawn after it come out at -26.565 and
 *                   their length is the click projected on to that way
 *                   -- which is exactly what the 傾き box does
 *   線長   (32939)  they keep the way they were clicked and come out
 *                   273.804 long -- exactly what the 寸法 box does
 *
 * and three rules besides: it holds for the line after that as well,
 * leaving the command clears it, and a number typed into the box beats
 * it.  So it is a second place to keep what the box keeps, and `kata_*`
 * and `naga_*` below read whichever is set.
 */
static int    get_mode;         /* the 取得 command running, or 0 */
static int    get_step;
static double get_ax, get_ay;   /* the first point of a two-point one */
static int    have_kata;        /* 角度取得 has given one */
static double get_kata;         /* in radians */
static int    have_naga;        /* 長さ取得 has given one */
static double get_naga;         /* in millimetres on the paper */
static int    have_kan;         /* 間隔取得 has given one */
static double get_kan;          /* in the drawing's own units */
static int    get_obj = -1;     /* the line 間隔取得 was given */

static int kata_set(void)
{
    const char *t = jw_cmd_box(1411);

    return (t && *t) || have_kata;
}

static double kata_rad(void)
{
    const char *t = jw_cmd_box(1411);

    if (t && *t)
        return box_angle(1411);
    return have_kata ? get_kata : 0.0;
}

static double naga_mm(const jw_drawing *d)
{
    double v = box_mm(d, 1412);

    return v > 0.0 ? v : (have_naga ? get_naga : 0.0);
}

/* 連続線の 連続弧 (2492).  With it ticked the command strings arcs
 * together instead of segments.  The original's own prompts spell the
 * walk out (tools/probe99.sh):
 *
 *     始点を指示してください
 *     　　◎　円弧の中間点を指示してください
 *     ◆　　終点を指示してください
 *     ◆　　終点を指示してください  << 同一点再指示で終了 ﾏｳｽ（L) >>
 *
 * so: three points make the first arc, and every click after that adds
 * one more.  ra_ux/ra_uy is the way out of the last centre through the
 * join, which is what makes the next one leave tangentially. */
static double ra_pend[5];       /* 控えてある弧: 中心・半径・始角・掃き */
static int ra_have_pend;
static int ra_step;             /* 0 none, 1 after the start, 2 running */
static int ra_have;             /* an arc is laid, so ra_u is good */
static double ra_jx, ra_jy;     /* where the chain has got to */
static double ra_mx, ra_my;     /* the middle point of the first arc */
static double ra_ux, ra_uy;     /* out of the last centre, through the join */
static double ra_dx, ra_dy;     /* and the way the last arc was going there */
static int ra_flip;             /* 弧反転 (1067): CZukeiRenzokuSen +0x460 */

/* 包絡処理: the first corner of the box, and whether it has been given */
static int hou_step;
static double hou_x, hou_y;

/* The font name Jw_cad writes with a new text.  It is whatever its font box
   has, and every text in the drawings to hand has this one; the port draws
   with a bitmap font of its own and has no font list to choose from. */
#define JW_MOJI_FACE_DEFAULT "\x82l\x82r \x83S\x83V\x83" "b\x83N"
#define JW_MOJI_FACE jw_cmd_moji_face()

int jw_cmd(void)
{
    return current;
}

const char *jw_cmd_line(void)
{
    line_buf[line_n] = 0;
    return line_buf;
}

const char *jw_cmd_compose(void)
{
    comp_buf[comp_n] = 0;
    return comp_buf;
}

void jw_cmd_compose_clear(void)
{
    comp_n = 0;
}

void jw_cmd_compose_key(int c)
{
    if (c >= 0 && c < 256 && comp_n < (int)sizeof comp_buf - 2)
        comp_buf[comp_n++] = (char)c;
}

void jw_cmd_key(int c)
{
    line_gen++;
    if (moji_got_all && current == JW_CMD_MOJI) {
        moji_got_all = 0;               /* 選ばれた字は打った字で置き換わる */
        line_n = 0;
        line_lead_next = line_drop_trail = 0;
        if (c == 8)
            return;
    }
    if (c == 8) {
        line_lead_next = line_drop_trail = 0;
        /* back over a whole character, lead byte and all */
        if (line_n > 0) {
            int i = 0, last = 0;
            while (i < line_n) {
                last = i;
                i += (jw_is_lead((unsigned char)line_buf[i]) && i + 1 < line_n)
                     ? 2 : 1;
            }
            line_n = last;
        }
        return;
    }
    /* A character of two bytes comes as two calls, lead byte first.  It
       goes in whole or not at all: the line used to take the lead byte
       into its last free place and refuse the trail byte after it, which
       left a text ending in half a character (253 letters and then あ).
       So a lead byte needs room for two, and the byte after a refused one
       is refused with it. */
    if (line_drop_trail) {
        line_drop_trail = 0;
        return;
    }
    if (c >= 0 && c < 256) {
        int lead = line_lead_next == 0 && jw_is_lead((unsigned char)c);

        if (line_n + (lead ? 2 : 1) > (int)sizeof line_buf - 2) {
            line_drop_trail = lead;
            return;
        }
        line_buf[line_n++] = (char)c;
        line_lead_next = lead;          /* the next byte is its trail */
    }
}

static void blank(jw_obj *o);

static int moji(jw_drawing *d, jw_obj *o, double x, double y);
static int moji_rule(jw_drawing *d, const jw_obj *t);

/* the line typed, put down at (x, y) */
static void moji_place(jw_drawing *d, double x, double y)
{
    jw_obj tmp, *o;

    if (!d || line_n == 0 || !moji(d, &tmp, x, y))
        return;
    {
        int made = moji_rule(d, &tmp);

        o = jw_add(d, JW_MOJI);
        if (!o)
            return;
        tmp.layer = o->layer;
        tmp.lgroup = o->lgroup;
        *o = tmp;
        o->face = jw_add_str(d, JW_MOJI_FACE);
        op_push(made + 1);
    }
    line_n = 0;
    line_gen++;
}

/* 文字の「移動・変更(L)、複写(R)」（5316）: 入力欄が空のとき既存の文字を拾う。
 * 逆コンパイルの読み、原典では押していない。
 *
 * CZukeiMoji の (L) は仮想関数 9 番 FUN_006c71f0、(R) は 11 番 FUN_006c7ae0。
 * どちらも入力欄が空（+0x8560 == 0 で箱が ""）なら FUN_004500e0 で文字を
 * 一つ拾い、FUN_006c6160 でその字を入力欄に入れる（全部選んだ形、
 * FUN_0057f820(0,999)）。そのとき文字種を拾った字のものにする:
 * FUN_00583240 が 大きさ・間隔・色、FUN_00583200 が 角度（字の角度から
 * 軸角 +0x17c0 を引いたもの）、+0x9f8・+0x9fc を落とし、+0xa00（縦字）は
 * 字の +0x44 の 0x20。斜体・太字（+0xdc の 1・0x10）も。拾った字の写しは
 * +0x2e8（置くときの雛形。レイヤや書体はこれのまま、FUN_004552a0 で
 * いまの設定に戻すのは +0x5c4 == 0 のときだけ）と +0x3d8 に入る。
 *
 * (L) は +0x5c4 = 1 で字を選択に入れ（FUN_00447b90）、置くとき
 * （FUN_006c83a0）選択が残っているので元の字が消えて新しい字が入る
 * ＝ 移動・変更。(R) は +0x5c4 = 2 で選択を放す（FUN_0044c830）ので、
 * 元は残る ＝ 複写。次のクリック（どちらのボタンでも）が置く位置。
 *
 * カーソルは拾った字の基点の上へ動かされる（FUN_004fd520 = SetCursorPos、
 * +0x200 − +0x210）ので、字を書き換えて Enter すると元の基点の所に
 * 置かれる。基点はいまの文字基点のまま（DAT_00a0bbb0 が立っていれば字の
 * 線種 byte の基点に替わるが、その切り替えはこの移植に無い）。 */
static void moji_got_pick(jw_drawing *d, const jw_view *v, double x, double y,
                          int button)
{
    int k = jw_pick_moji(d, v, x, y), n;
    const jw_obj *o;
    const char *t;

    if (k < 0)
        return;
    o = &d->obj[k];
    t = jw_str(d, o->text);
    n = t ? (int)strlen(t) : 0;
    if (n <= 0)
        return;
    if (n > (int)sizeof line_buf - 2)
        n = (int)sizeof line_buf - 2;
    memcpy(line_buf, t, (size_t)n);
    line_n = n;
    line_lead_next = line_drop_trail = 0;
    line_gen++;
    /* 文字種 */
    d->cur_style.w = o->d[4];
    d->cur_style.h = o->d[5];
    d->cur_style.sp = o->d[6];
    d->cur_style.color = o->color;
    moji_italic = (o->n / 10000) % 2 != 0;
    moji_bold = (o->n / 20000) % 2 != 0;
    {
        char a[48];
        double deg = o->d[7] - jw_cmd_axis();
        unsigned char *c;

        if (deg == 0.0)
            a[0] = 0;
        else
            snprintf(a, sizeof a, "%.10g", deg);
        box_put(1411, a);
        if ((c = chk_slot(bar_cmd(), 1324)) != 0)
            *c = 0;
        if ((c = chk_slot(bar_cmd(), 1325)) != 0)
            *c = (o->flags & 0x20u) ? 1 : 0;
    }
    moji_got = button != 0 ? 2 : 1;
    moji_got_i = k;
    moji_got_was = *o;
    moji_got_all = 1;
}

/* 拾った字が まだそこにあるか（拾ったあと図面が動いていれば 消さない） */
static int moji_got_here(const jw_drawing *d)
{
    const jw_obj *o;

    if (moji_got_i < 0 || moji_got_i >= d->ndrawn)
        return 0;
    o = &d->obj[moji_got_i];
    return o->cls == JW_MOJI && o->text == moji_got_was.text
           && memcmp(o->d, moji_got_was.d, sizeof o->d) == 0;
}

/* 拾った字の基点（いまの文字基点で数えたもの）: moji() が引き戻す分を足す */
static void moji_got_base(double *x, double *y)
{
    const jw_obj *o = &moji_got_was;
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double len = sqrt(dx * dx + dy * dy);
    double a = len > 0.0 ? atan2(dy, dx) : o->d[7] * PI / 180.0;
    double ux = cos(a), uy = sin(a), vx = -uy, vy = ux;
    int kj = jw_cmd_moji_base_now();    /* moji() と同じ 基点・ずれ */
    double along = len * (double)(kj / 3) / 2.0;
    double across = o->d[5] * (double)(2 - kj % 3) / 2.0;

    *x = o->d[0] + along * ux + across * vx;
    *y = o->d[1] + along * uy + across * vy;
    if (jw_cmd_moji_zure_now()) {
        *x += jw_cmd_moji_zure_get(1, kj / 3);
        *y += jw_cmd_moji_zure_get(0, kj % 3);
    }
}

/* 拾った字を (x, y) へ: 雛形（拾った字）のレイヤ・書体で置き、(L) なら元を消す */
static void moji_got_place(jw_drawing *d, double x, double y)
{
    jw_obj tmp, *o;
    op_t *op1 = 0;
    int made, del;

    if (!d || line_n == 0 || !moji(d, &tmp, x, y))
        return;
    del = moji_got == 1 && moji_got_here(d);
    if (del) {
        op1 = op_new();
        op_keep(op1, d, moji_got_i, 1);
    }
    made = moji_rule(d, &tmp);
    o = jw_add(d, JW_MOJI);
    if (o) {
        tmp.layer = moji_got_was.layer;
        tmp.lgroup = moji_got_was.lgroup;
        *o = tmp;
        o->face = moji_got_was.face >= 0 ? moji_got_was.face
                                         : jw_add_str(d, JW_MOJI_FACE);
        made++;
    }
    if (del) {
        jw_remove(d, moji_got_i);
        if (op1)
            op1->n = made;
    } else {
        op_push(made);
    }
    moji_got = moji_got_all = 0;
    line_n = 0;
    line_gen++;
}

/* What the line is worth in paper millimetres, and how the text element for
   it is laid out.  Shared by the preview and the one that gets placed. */
/* 文読 (1069) -- read a text file and place its lines.
 *
 * The button puts up an ordinary「開く」 (tools/probe66.sh), and the file
 * that comes back is placed line by line at the next click: the first
 * line's start lands on it and the rest follow **downwards**, across the
 * run.
 *
 * **行間 (1418) is that step, and it is twice what the box holds, in
 * millimetres of paper.**  An empty box behaves as 5.  A two line file
 * was read six ways (tools/probe67.sh .. probe69.sh):
 *
 *   文字種10 (10 tall)   empty -> 10   5 -> 10   20 -> 40   40 -> 80
 *   文字種4  (4 tall)    empty -> 10             20 -> 40
 *
 * -- so it is not a multiple of the character height, which the first
 * four runs alone could not tell (10 tall and a 10 step look the same).
 */
static char txt_line[64][256];
static int txt_n;

int jw_cmd_text_load(jw_drawing *d, const unsigned char *b, long n)
{
    long i = 0;
    int k = 0;

    (void)d;
    txt_n = 0;
    while (i < n && k < (int)(sizeof txt_line / sizeof txt_line[0])) {
        int j = 0;

        while (i < n && b[i] != '\r' && b[i] != '\n'
               && j < (int)sizeof txt_line[0] - 1)
            txt_line[k][j++] = (char)b[i++];
        txt_line[k][j] = 0;
        while (i < n && (b[i] != '\r' && b[i] != '\n'))
            i++;                        /* a line longer than the buffer */
        while (i < n && (b[i] == '\r' || b[i] == '\n')) {
            i += b[i] == '\r' && i + 1 < n && b[i + 1] == '\n' ? 2 : 1;
            break;
        }
        k++;
    }
    txt_n = k;
    return k > 0;
}

int jw_cmd_text_ready(void)
{
    return txt_n;
}

/* the step from one line to the next, in millimetres of paper */
static double txt_pitch(void)
{
    const char *t = jw_cmd_box(1418);
    double v = box_num(t, 5.0);

    return (v > 0.0 ? v : 5.0) * 2.0;
}

/* 連 (1068) -- 連結・移動・切断, the 文字 bar's text editor.
 *
 * Not「place one after another」, which is what the label looks like: the
 * status line it puts up is 5473,
 *
 *   文字を指示してください。  連結（L)　　移動（LL)　　　　文字切断位置指示(R)
 *
 * and once one text is picked, 5474,
 *
 *   連結文字指示　　（L)移動　　　　　（R)複写
 *
 * so it joins two texts, moves one, or cuts one in two.  That is why the
 * input box goes away while it is on (tools/probe63.sh).
 *
 * **連結** was asked of the original four ways (tools/probe64.sh,
 * probe65.sh).  With AB at -94.2857 and CD at -69.7959 on the same line:
 *
 *   AB then CD (L)   one text, 'CDAB', at **AB's** start
 *   CD then AB (L)   one text, 'ABCD', at **CD's** start
 *   AB then CD (R)   'CDAB' at AB's start **and CD still where it was**
 *
 * -- so the text picked **second** goes in front, the result sits where
 * the **first** one was, and (R) copies the second instead of moving it.
 *
 * **切断** was asked twice.  'ABCD' from -94.2857, its characters half
 * width (5 across) with half a spacing (0.5) between them:
 *
 *   (R) at 10.41 along   'AB' from -94.2857 and 'CD' from -83.2857
 *   (R) at  5.50 along   'A'  from -94.2857 and 'BCD' from -88.7857
 *
 * -- the boundary taken is the one **nearest the click**, the first piece
 * keeps the start, and the second begins half a spacing after the first
 * one ends.  (The boundaries are at 5.25, 10.75 and 16.25 along, which is
 * each piece's run plus half the gap that follows it.)
 *
 * 移動 (LL) is a double click, which nothing here can post, so it is not
 * done.
 */
static int ren_step;                    /* 0 off, 1 wants a text, 2 the
                                           one to join it to, 3 the one
                                           picked with (LL) wants a place */
static int ren_first;                   /* and which text that was */

/* How far a string runs, the way moji() measures it: a character advances
   its full width if it is a wide one and half if it is not, and the gap
   before it is the spacing or half of it by the same rule. */
static double moji_run(const char *t, double cw, double sp, int nmax)
{
    double len = 0.0;
    int nch = 0, i = 0;

    while (t[i] && (nmax < 0 || nch < nmax)) {
        int wide = jw_is_lead((unsigned char)t[i]) && t[i + 1];
        if (nch)
            len += wide ? sp : sp / 2;
        len += wide ? cw : cw / 2;
        i += wide ? 2 : 1;
        nch++;
    }
    return len;
}

/* how many characters a string holds, wide ones counting one */
static int moji_nch(const char *t)
{
    int n = 0, i = 0;

    while (t[i]) {
        i += jw_is_lead((unsigned char)t[i]) && t[i + 1] ? 2 : 1;
        n++;
    }
    return n;
}

/* the byte offset of the nth character */
static int moji_at(const char *t, int n)
{
    int i = 0;

    while (n-- > 0 && t[i])
        i += jw_is_lead((unsigned char)t[i]) && t[i + 1] ? 2 : 1;
    return i;
}

/* put a text's far end where its run and its direction say it should be */
static void moji_reend(jw_obj *o, const char *t)
{
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double l = sqrt(dx * dx + dy * dy);
    double ux = l > 0.0 ? dx / l : 1.0, uy = l > 0.0 ? dy / l : 0.0;
    double run = moji_run(t, o->d[4], o->d[6], -1);

    o->d[2] = o->d[0] + run * ux;
    o->d[3] = o->d[1] + run * uy;
}

/* 連結: the one picked second goes in front of the one picked first, and
   the result keeps the first one's place on the paper.  `keep` leaves the
   second where it is, which is what (R) does.

   The joined text goes **to the end of the drawing**, the way 属性変更
   moves what it changes: the original's (R) run came back with the
   untouched CD first and the joined CDAB after it, though both had been
   placed the other way round (tools/probe65.sh). */
static void ren_join(jw_drawing *d, int a, int b, int keep)
{
    jw_obj was, *A, *B;
    const char *ta, *tb;
    char buf[512], face[64];
    op_t *o;
    int lo, hi;

    if (a < 0 || b < 0 || a == b || a >= d->ndrawn || b >= d->ndrawn)
        return;
    A = &d->obj[a];
    B = &d->obj[b];
    if (A->cls != JW_MOJI || B->cls != JW_MOJI)
        return;
    ta = jw_str(d, A->text);
    tb = jw_str(d, B->text);
    if (!ta || !tb || strlen(ta) + strlen(tb) >= sizeof buf)
        return;
    strcpy(buf, tb);
    strcat(buf, ta);
    was = *A;
    face[0] = 0;
    if (A->face >= 0) {
        const char *f = jw_str(d, A->face);
        if (f && strlen(f) < sizeof face)
            strcpy(face, f);
    }
    /* take them out from the back, so the indices in front stay put */
    o = op_new();
    lo = a < b ? a : b;
    hi = a < b ? b : a;
    if (!keep) {
        op_keep(o, d, hi, 1);
        jw_remove(d, hi);
        if (lo != hi) {
            op_keep(o, d, lo, 1);
            jw_remove(d, lo);
        }
    } else {
        op_keep(o, d, a, 1);
        jw_remove(d, a);
    }
    A = jw_add(d, JW_MOJI);
    if (!A)
        return;
    *A = was;
    A->sel = 0;
    A->text = jw_add_str(d, buf);
    A->face = face[0] ? jw_add_str(d, face) : -1;
    moji_reend(A, buf);
    if (o)
        o->n = 1;                       /* the joined one, at the end */
}

/* 切断: split the text at the character boundary nearest (x, y) */
static void ren_cut(jw_drawing *d, int i, double x, double y)
{
    jw_obj *A, *B;
    const char *t;
    char head[512], tail[512];
    double dx, dy, l, ux, uy, along, best = 0.0, gap;
    int n, k, cut = 0, off;
    op_t *o;

    if (i < 0 || i >= d->ndrawn || d->obj[i].cls != JW_MOJI)
        return;
    A = &d->obj[i];
    t = jw_str(d, A->text);
    if (!t || !*t)
        return;
    n = moji_nch(t);
    if (n < 2 || strlen(t) >= sizeof head)
        return;
    dx = A->d[2] - A->d[0];
    dy = A->d[3] - A->d[1];
    l = sqrt(dx * dx + dy * dy);
    ux = l > 0.0 ? dx / l : 1.0;
    uy = l > 0.0 ? dy / l : 0.0;
    along = (x - A->d[0]) * ux + (y - A->d[1]) * uy;
    for (k = 1; k < n; k++) {
        off = moji_at(t, k);
        gap = jw_is_lead((unsigned char)t[off]) && t[off + 1]
              ? A->d[6] : A->d[6] / 2;
        {
            double at = moji_run(t, A->d[4], A->d[6], k) + gap / 2;
            double e = at > along ? at - along : along - at;
            if (!cut || e < best) {
                best = e;
                cut = k;
            }
        }
    }
    if (!cut)
        return;
    off = moji_at(t, cut);
    memcpy(head, t, (size_t)off);
    head[off] = 0;
    strcpy(tail, t + off);
    gap = jw_is_lead((unsigned char)t[off]) && t[off + 1]
          ? A->d[6] : A->d[6] / 2;
    o = op_new();
    op_keep(o, d, i, 0);
    B = jw_add(d, JW_MOJI);
    if (!B)
        return;
    A = &d->obj[i];
    *B = *A;
    B->sel = 0;
    B->text = jw_add_str(d, tail);
    B->face = A->face >= 0 ? jw_add_str(d, jw_str(d, A->face)) : -1;
    {
        double run = moji_run(head, A->d[4], A->d[6], -1);
        B->d[0] = A->d[0] + (run + gap) * ux;
        B->d[1] = A->d[1] + (run + gap) * uy;
    }
    moji_reend(B, tail);
    A = &d->obj[i];
    A->text = jw_add_str(d, head);
    moji_reend(A, head);
    if (o)
        o->n = 1;                       /* the piece that was added */
}

/* 連 の 移動 -- the (LL) of its prompt.
 *
 * A double click on a text asks 「移動先の点を指示して下さい」 (5311)
 * and the next click puts the text's **start** there.  Two runs of the
 * original, with AB at (-94.2857, 26.3265): a click at the view's
 * (700,500) left it at (89.3878, -96.1224) and one at (600,250) at
 * (28.1633, 56.9388) -- the clicked point itself, to six places
 * (tools/probe110.sh).  **基点 makes no difference**: the same move with
 * 中中 picked came out at the very same place (probe111).
 *
 * And the text that moved goes to the **end** of the drawing: the two
 * came back CD first and AB second, the other way round from how they
 * were typed.
 *
 * Measuring any of this needed a double click, which the port's own
 * driver could not send until `LL<x>,<y>` was added to
 * tools/jwdraw.ps1 -- Windows delivers one as down, up,
 * WM_LBUTTONDBLCLK, up, and all four can be posted. */
static void ren_move_to(jw_drawing *d, int i, double x, double y)
{
    jw_obj *A, *B;
    op_t *o;

    if (!d || i < 0 || i >= d->ndrawn || d->obj[i].cls != JW_MOJI)
        return;
    o = op_new();
    op_keep(o, d, i, 1);        /* it is taken out and put back at the end */
    A = &d->obj[i];
    B = jw_add(d, JW_MOJI);
    if (!B)
        return;
    A = &d->obj[i];
    *B = *A;
    B->sel = 0;
    jw_obj_move(B, x - A->d[0], y - A->d[1]);
    jw_remove(d, i);
    if (o)
        o->n = 1;
}

/* 基点 (1064): which corner of the text the click is.
 *
 * The button puts up a dialog whose 3x3 of radios is 1689..1697, in the
 * order 左上 左中 左下 中上 中中 中下 右上 右中 右下, and 左下 is the one
 * it comes up on (tools/probe60.sh read them all).  So the index here is
 * that id minus 1689: the column is index/3 -- 左, 中, 右 -- and the row
 * is index%3 -- 上, 中, 下.
 *
 * What each one does was asked of the original, all nine, with ABC typed
 * and one click at the same place (tools/probe62.sh).  The click is at
 * (-94.2857, -34.898), the run is 16 mm and the characters are 10 tall,
 * and the text started at
 *
 *        左            中             右
 *   上   -94.2857     -102.286      -110.286    y -44.898
 *   中   -94.2857     -102.286      -110.286    y -39.898
 *   下   -94.2857     -102.286      -110.286    y -34.898
 *
 * -- so the click is pulled back along the run by nothing, half of it and
 * all of it, and across it by the height, half of it and nothing.
 */
static int moji_kijun = 2;              /* 左下 */

/* ずれ使用 (1323) and the six boxes beside the 3x3: 横ずれ 2004 2005 2006
 * under the three columns and 縦ずれ 2009 2008 2007 beside the three rows,
 * so each cell has a pair.  The label says 図寸法mm and it is: the numbers
 * go on to the paper one for one.
 *
 * What they do was asked of the original (tools/probe70.sh).  With ABC at
 * the same click as everything else:
 *
 *   左上, 横 5 縦 3   (-99.2857, -47.898)   -- plain 左上 is (-94.2857, -44.898)
 *   右下, 横 7 縦 2   (-117.286, -36.898)   -- plain 右下 is (-110.286, -34.898)
 *   左上, boxes filled but ずれ使用 **off**  -- plain 左上, so the tick is
 *                                             what turns them on
 *
 * -- the start moves by **minus** each of them, in both cells, so it is a
 * plain (-横, -縦) on the paper and not something that turns with the
 * corner.  Which box goes with which cell is the dialog's own layout (three
 * under the three columns, three beside the three rows) and the two runs
 * above; a run with the other column's box filled was not done.
 */
static int moji_zure;
static double moji_zx[3], moji_zy[3];   /* 左中右 across, 上中下 down */
static int moji_under, moji_over, moji_side;   /* 1327, 1328, 1329 */

void jw_cmd_moji_rule(int which, int on)
{
    if (which == 1327)
        moji_under = on ? 1 : 0;
    else if (which == 1328)
        moji_over = on ? 1 : 0;
    else if (which == 1329)
        moji_side = on ? 1 : 0;
}

int jw_cmd_moji_rule_now(int which)
{
    return which == 1327 ? moji_under
         : which == 1328 ? moji_over
         : which == 1329 ? moji_side : 0;
}

void jw_cmd_moji_base(int n)
{
    if (n >= 0 && n < 9)
        moji_kijun = n;
}

void jw_cmd_moji_zure(int on)
{
    moji_zure = on ? 1 : 0;
}

int jw_cmd_moji_zure_now(void)
{
    return moji_zure;
}

/* The six boxes of the dialog, as they are typed into.  The numbers
 * above are what the drawing uses; this is the text that stands in
 * them, so that what was typed comes back unchanged (2004 is
 * 左, 2005 中, 2006 右 across; 2009 上, 2008 中, 2007 下 down --
 * which is how the original was driven when the numbers were measured,
 * tools/probe67.sh). */
static char moji_ztext[6][16];

static int zure_ix(int id)
{
    switch (id) {
    case 2004: return 0;
    case 2005: return 1;
    case 2006: return 2;
    case 2009: return 3;
    case 2008: return 4;
    case 2007: return 5;
    }
    return -1;
}

static void zure_text(int ix, double v)
{
    if (ix < 0 || ix > 5)
        return;
    if (v == 0.0)
        moji_ztext[ix][0] = 0;
    else
        sprintf(moji_ztext[ix], "%g", v);
}

const char *jw_cmd_moji_zure_box(int id)
{
    int ix = zure_ix(id);

    return ix < 0 ? 0 : moji_ztext[ix];
}

/* One character into one of them.  8 rubs one out, 13 is the end of
   it; everything a number can hold goes in. */
int jw_cmd_moji_zure_key(int id, int c)
{
    int ix = zure_ix(id), n;

    if (ix < 0)
        return 0;
    n = (int)strlen(moji_ztext[ix]);
    if (c == 8) {
        if (n > 0)
            moji_ztext[ix][--n] = 0;
    } else if (c == 13) {
        /* nothing to do: the number is kept in step as it is typed */
    } else if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
        if (n + 1 < (int)sizeof moji_ztext[ix]) {
            moji_ztext[ix][n++] = (char)c;
            moji_ztext[ix][n] = 0;
        }
    } else {
        return 0;
    }
    if (ix < 3)
        moji_zx[ix] = box_num(moji_ztext[ix], 0.0);
    else
        moji_zy[ix - 3] = box_num(moji_ztext[ix], 0.0);
    return 1;
}

void jw_cmd_moji_zure_at(int across, int n, double v)
{
    if (n >= 0 && n < 3) {
        if (across)
            moji_zx[n] = v;
        else
            moji_zy[n] = v;
        zure_text(across ? n : n + 3, v);
    }
}

double jw_cmd_moji_zure_get(int across, int n)
{
    if (n < 0 || n >= 3)
        return 0.0;
    return across ? moji_zx[n] : moji_zy[n];
}

int jw_cmd_moji_base_now(void)
{
    return moji_kijun;
}

/* 下線作図 (1327)・上線作図 (1328)・左右縦線 (1329) on the 基点 dialog:
 * the lines the original rules round a text.  All three were asked of it
 * with ABC at the usual place, whose run is (-94.2857,-34.898) to
 * (-78.2857,-34.898) and whose characters are 10 tall (tools/probe71.sh):
 *
 *   下線作図   one line **along the baseline**, end to end
 *   上線作図   the same, the character height across from it
 *   左右縦線   two, up from each end by that height
 *
 * and with all three on they came out 下・上・左・右 and then the text.
 * They carry the writing pen, not the text's own colour.
 */
static int moji_rule(jw_drawing *d, const jw_obj *t)
{
    double dx = t->d[2] - t->d[0], dy = t->d[3] - t->d[1];
    double l = sqrt(dx * dx + dy * dy);
    double ux = l > 0.0 ? dx / l : 1.0, uy = l > 0.0 ? dy / l : 0.0;
    double vx = -uy * t->d[5], vy = ux * t->d[5];
    double e[4][4];
    int n = 0, i, made = 0;

    if (moji_under) {
        e[n][0] = t->d[0];      e[n][1] = t->d[1];
        e[n][2] = t->d[2];      e[n][3] = t->d[3];
        n++;
    }
    if (moji_over) {
        e[n][0] = t->d[0] + vx; e[n][1] = t->d[1] + vy;
        e[n][2] = t->d[2] + vx; e[n][3] = t->d[3] + vy;
        n++;
    }
    if (moji_side) {
        e[n][0] = t->d[0];      e[n][1] = t->d[1];
        e[n][2] = t->d[0] + vx; e[n][3] = t->d[1] + vy;
        n++;
        e[n][0] = t->d[2];      e[n][1] = t->d[3];
        e[n][2] = t->d[2] + vx; e[n][3] = t->d[3] + vy;
        n++;
    }
    for (i = 0; i < n; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->d[0] = e[i][0];
        o->d[1] = e[i][1];
        o->d[2] = e[i][2];
        o->d[3] = e[i][3];
        made++;
    }
    return made;
}

static int moji(jw_drawing *d, jw_obj *o, double x, double y)
{
    const char *p = line_buf;
    double len = 0.0, cw, ch, sp;
    int nch = 0, i;

    if (!d || line_n == 0)
        return 0;
    cw = d->cur_style.w;
    ch = d->cur_style.h;
    sp = d->cur_style.sp;
    if (cw <= 0.0 || ch <= 0.0)
        return 0;
    line_buf[line_n] = 0;
    while (*p) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            len += wide ? sp : sp / 2;
        len += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    {   /* 基点: pull the click back to where the text starts */
        const char *as = jw_cmd_box(1411);
        double a = as && *as ? box_num(as, 0.0) * PI / 180.0
                 : jw_cmd_bar_check(1324) > 0 ? PI / 2.0 : 0.0;
        double ux = cos(a), uy = sin(a), vx = -uy, vy = ux;
        double along = len * (double)(moji_kijun / 3) / 2.0;
        double across = ch * (double)(2 - moji_kijun % 3) / 2.0;

        x -= along * ux + across * vx;
        y -= along * uy + across * vy;
        if (moji_zure) {
            /* and the ずれ, which is straight down the paper's own axes */
            x -= moji_zx[moji_kijun / 3];
            y -= moji_zy[moji_kijun % 3];
        }
    }
    blank(o);
    o->cls = JW_MOJI;
    o->color = (unsigned short)d->cur_style.color;
    o->ltype = 1;
    o->d[0] = x;
    o->d[1] = y;
    /* 縦字 (1325) is bit 0x20 of the flags and nothing else: the original
     * wrote the same two ends, running right, with that bit set.  What it
     * means is stacked characters, which src/text.c already draws. */
    if (jw_cmd_bar_check(1325) > 0)
        o->flags = (unsigned short)(o->flags | 0x20u);
    /* 角度 (1411) lays the baseline at whatever is typed there, in
     * degrees: the original, given 30 and three characters whose run is
     * 16 mm, wrote the far end 13.8564 across and 8 up -- 16 at thirty
     * degrees (tools/probe57.sh's mo_ang).
     *
     * 垂直 (1324) turns the baseline a quarter turn: the original wrote
     * the same text running 30 up instead of 30 across, everything else
     * the same.  Which of the two wins when both are set was not asked,
     * so the box is taken when it has something in it and 垂直 when it
     * has not.
     *
     * **With 縦字 as well it runs the other way** -- 30 *down*, not up
     * (decomp/res/moji_vert_tate.jww against moji_vert.jww,
     * tools/probe95.sh).  Which stands to reason: that is the way
     * 縦書き reads. */
    {
        const char *as = jw_cmd_box(1411);

        if (as && *as) {
            double a = box_num(as, 0.0) * PI / 180.0;
            o->d[2] = x + len * cos(a);
            o->d[3] = y + len * sin(a);
            o->d[7] = box_num(as, 0.0);
        } else if (jw_cmd_bar_check(1324) > 0) {
            o->d[2] = x;
            o->d[3] = jw_cmd_bar_check(1325) > 0 ? y - len : y + len;
            o->d[7] = jw_cmd_bar_check(1325) > 0 ? -90.0 : 90.0;
        } else {
            o->d[2] = x + len;
            o->d[3] = y;
        }
    }
    o->d[4] = cw;
    o->d[5] = ch;
    o->d[6] = sp;
    /* 角度 (m_dKakudo) は走る向きの度、線種の byte は 基点 の 1..9
     * （左下 1・中下 2・右下 3 … 左上 7、FUN_006c83a0 が +0x310 =
     * 横 + 1 + 縦 * 3 を入れる）。decomp/res/moji_k0..k8.jww の字が
     * 7 4 1 8 5 2 9 6 3、moji_ang 30・moji_vert 90・moji_vert_tate −90。
     * 角度は上の三つの枝で入れる（blank が 0 にしている） */
    o->ltype = (unsigned char)(moji_kijun / 3 + 1 + (2 - moji_kijun % 3) * 3);
    o->n = 0;
    for (i = 0; i < 10; i++)
        if (d->style[i].w == cw && d->style[i].h == ch
            && d->style[i].sp == sp)
            o->n = i + 1;
    o->n += (moji_italic ? 10000 : 0) + (moji_bold ? 20000 : 0);
    if (line_shown != line_gen) {
        line_off = jw_add_str(d, line_buf);
        line_shown = line_gen;
    }
    o->text = line_off;
    o->face = -1;
    return 1;
}

/* 軸角, in degrees.  Not kept in the file: opening a drawing does not bring
   one back, the same way the write pen does not. */
static double axis_deg;

double jw_cmd_axis(void)
{
    return axis_deg;
}

void jw_cmd_set_axis(double deg)
{
    axis_deg = deg;
}

int jw_cmd_hv(void)
{
    return hv;
}

/* 連続線 は ひとつ手前の線だけ画面にあって図面に入っていない
 * （`step == 3`）。命令を送り直す／別の命令へ移ると、その線が入ります。
 * `tools/probe164.sh` が原典に訊いた: 三点を取って 実寸 (2096) を押しても
 * 入らず、32883 を送り直す・線 (32771) へ移るとどちらでも入りました。
 * 右クリックの終了では入りません（n-2 の決まり）。 */
static void ra_commit(jw_drawing *d);

void jw_cmd_flush(jw_drawing *d)
{
    if (d && current == JW_CMD_RENZOKU)
        ra_commit(d);
    if (d && current == JW_CMD_RENZOKU && step == 3
        && jw_cmd_bar_check(2492) <= 0) {
        jw_obj *o = jw_add(d, JW_SEN);

        if (o) {
            o->d[0] = renzoku_edge(d) > 0.0 ? rn_sx : sx;
            o->d[1] = renzoku_edge(d) > 0.0 ? rn_sy : sy;
            o->d[2] = rx;
            o->d[3] = ry;
            op_push(1);
        }
        step = 0;
    }
}

static int pv_round(double x)
{
    return (int)floor(x + 0.5);
}

/* 日影図の 確認 (1067): 建物を 針金で見る窓。方位角・仰角の向きの正射影で、中心は 三次元の線の端の平均、
 * 黒い線が建物の辺（下端・上端・縦）、紫の点線が 測定面（測定高）の高さの 建物の外接枠。
 * 左 右 は 方位角 −5・+5、上 下 は 仰角 +5・−5、「０，０」は 0・0、等角は −45・35.264、≪ で戻る。
 * 初めは −45・30。原典 tmp の hk_pv1〜pv6（`tools/hkpreview.sh`）。 */
static double hk_pv_az = -45.0, hk_pv_el = 30.0;

int jw_cmd_hikage_pv_on(void)
{
    return current == JW_CMD_HIKAGE && hk_pv;
}

double jw_cmd_hikage_pv_az(void)
{
    return hk_pv_az;
}

/* 窓の中身を out に作る（紙の mm。v の画素に ちょうど落ちる位置）。戻り値は線の数 */
int jw_cmd_hikage_preview(const jw_drawing *d, const jw_view *v, jw_drawing *out)
{
    static double L[7 * 4000];
    int n, i, k, m = 0;
    double cx = 0.0, cy = 0.0, cz = 0.0, s, a, el, ca, sa, ce, se, plane;
    double bx0 = 1e30, by0 = 1e30, bx1 = -1e30, by1 = -1e30;
    const char *pb = jw_cmd_box(1492);

    if (!d || !v || !out || !jw_cmd_hikage_pv_on())
        return 0;
    n = jw_tenku_lines3(d, 0.0, L, 4000);
    if (n < 1)
        return 0;
    for (i = 0; i < n; i++) {
        cx += L[7 * i] + L[7 * i + 3];
        cy += L[7 * i + 1] + L[7 * i + 4];
        cz += L[7 * i + 2] + L[7 * i + 5];
        for (k = 0; k < 2; k++) {
            double x = L[7 * i + 3 * k], y = L[7 * i + 3 * k + 1];

            if (x < bx0) bx0 = x;
            if (x > bx1) bx1 = x;
            if (y < by0) by0 = y;
            if (y > by1) by1 = y;
        }
    }
    cx /= 2.0 * n;
    cy /= 2.0 * n;
    cz /= 2.0 * n;
    s = v->scale;
    a = hk_pv_az * 3.14159265358979323846 / 180.0;
    el = hk_pv_el * 3.14159265358979323846 / 180.0;
    ca = cos(a);
    sa = sin(a);
    ce = cos(el);
    se = sin(el);
    /* 測定面の高さ: 測定高 (1492) 空は 4 m、紙の mm にして（縮尺で割る） */
    plane = 4.0;
    if (pb && *pb)
        plane = atof(pb);
    {
        int g, wg = 0;
        double sc;

        for (g = 0; g < 16; g++)
            if (d->group[g].state == 3)
                wg = g;
        sc = d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
        plane = plane * 1000.0 / sc;
    }
    /* 窓の中心の紙の位置（作図の領域の真ん中の画素）。線は 普通の要素と同じく 紙の mm で置く */
    {
        double mx = v->ox + (v->clip.x + v->clip.w / 2.0 - v->bx) * v->mmpp;
        double my = v->oy - (v->clip.y + v->clip.h / 2.0 - v->by) * v->mmpp;

        {   /* 測定面: 建物ごとの外接枠（hk_pv5: 建物二つで枠も二つ） */
            int bno, nbld = 0;

            for (i = 0; i < n; i++)
                if ((int)L[7 * i + 6] > nbld)
                    nbld = (int)L[7 * i + 6];
            for (bno = 1; bno <= nbld; bno++) {
                double ax0 = 1e30, ay0 = 1e30, ax1 = -1e30, ay1 = -1e30;
                double cxs[4], cys[4], qx[4], qy[4];

                for (i = 0; i < n; i++) {
                    if ((int)L[7 * i + 6] != bno)
                        continue;
                    for (k = 0; k < 2; k++) {
                        double x = L[7 * i + 3 * k], y = L[7 * i + 3 * k + 1];

                        if (x < ax0) ax0 = x;
                        if (x > ax1) ax1 = x;
                        if (y < ay0) ay0 = y;
                        if (y > ay1) ay1 = y;
                    }
                }
                if (ax0 > ax1)
                    continue;
                cxs[0] = ax0; cys[0] = ay0;
                cxs[1] = ax1; cys[1] = ay0;
                cxs[2] = ax1; cys[2] = ay1;
                cxs[3] = ax0; cys[3] = ay1;
                for (k = 0; k < 4; k++) {
                    double X = cxs[k] - cx, Y = cys[k] - cy, Z = plane - cz;
                    double xs = X * ca + Y * sa, dep = -X * sa + Y * ca, vv = dep * se + Z * ce;

                    qx[k] = mx + xs;
                    qy[k] = my + vv;
                }
                for (k = 0; k < 4; k++) {       /* 一周を逆回り（点線の位相が原典と合う） */
                    jw_obj *o = jw_add(out, JW_SEN);
                    int a0 = (4 - k) % 4, a1 = (4 - k - 1 + 4) % 4;

                    if (!o)
                        break;
                    o->color = 5;
                    o->ltype = 2;
                    o->d[0] = qx[a0];
                    o->d[1] = qy[a0];
                    o->d[2] = qx[a1];
                    o->d[3] = qy[a1];
                    m++;
                }

            for (i = 0; i < n; i++) {
                jw_obj *o;

                if ((int)L[7 * i + 6] != bno)
                    continue;
                o = jw_add(out, JW_SEN);
                if (!o)
                    break;
                o->color = 2;
                o->ltype = 1;
                for (k = 0; k < 2; k++) {
                    double X = L[7 * i + 3 * k] - cx, Y = L[7 * i + 3 * k + 1] - cy, Z = L[7 * i + 3 * k + 2] - cz;
                    double xs = X * ca + Y * sa, dep = -X * sa + Y * ca, vv = dep * se + Z * ce;

                    o->d[2 * k] = mx + xs;
                    o->d[2 * k + 1] = my + vv;
                }
                m++;
            }

            }
        }
    }
    return m;
}

/* 範囲の移動・複写などのあとに 複線 へ替えると、選んだままの図形が複線の元になる
 * （原典: 最初のクリックが 何も拾えなくても 選択中の線・円を まとめて写す。一度だけ。
 *  向きはクリックに一番近い選択中の線の側で、ほかの線も同じ側。fuzz 10・15・25・62・71・74、
 *  tmp/ov.py の二本線の実験）。 */
static const jw_drawing *last_dr;   /* 直近に命令へ渡された図面（jw_cmd_set は図面を受け取らない） */

static int fk_has_sel(void)
{
    int i;

    if (!last_dr)
        return 0;
    for (i = 0; i < last_dr->ndrawn; i++)
        if (last_dr->obj[i].sel && (last_dr->obj[i].cls == JW_SEN ||
            (last_dr->obj[i].cls == JW_ENKO && fabs(last_dr->obj[i].d[6] - 1.0) < 1e-9)))
            return 1;
    return 0;
}

static int fk_sel_used;
static int fk_selmode;      /* 選択中の図形が元（最初のクリックは 側・間隔の指示） */
/* (R) 前回値 (CZukeiFukusen slot 11, FUN_0065d230): 状態 0 で (R) が線・円を拾うと
 * 箱 (1411) を零にしない（(L) の slot 9 は 32800 なら箱を 0 にする）。箱が 1e-7 を
 * 超えていれば すぐ状態 3「作図する方向を指示」へ、でなければ状態 2。原典の箱は 写すたびに
 * その間隔を持つ（slot 3 が +0x2d0 に取って書き戻し、自由位置の段は 測った距離を書く）が、
 * この移植は自由位置で箱に書かないので、この命令で最後に写した間隔を fk_prev に持つ。
 * fk_rprev は (R) で拾ったときの その間隔（0 ならふつうの段）。逆コンパイルの読み、原典では
 * 押していない。 */
static double fk_prev, fk_rprev;
/* 端点指定 (1065、slot 26 FUN_0065b720): +0x284 を 3 にする。(L) で始点 (+0x290)、
 * 終点 (+0x2a0、始点と 1e-7 未満なら 0x14df で受けない) と取って 1 に。(R) は点読み
 * （FUN_00451eb0）。写すとき（FUN_0065a340 の CDataSen の枝）は 写した線の上へ二点を
 * 垂直に落とし（FUN_005f92e0 で線の座標へ、y を 0、FUN_005f8ce0 で戻す）、それを写しの
 * 始点・終点にする。Esc（slot 16）は 1→2→3→0。写すと 0（slot 3）。原典で押せるのは
 * 状態 3 で一本の線のときだけ（slot 6、1065 は +0x2c8）。逆コンパイルの読み、原典では
 * 押していない。 */
static int fk_ten;
static double fk_tp[4];
/* 範囲選択 (1067、slot 28 FUN_0065bb40): 箱を +0x2b8 に取って 範囲選択 に出る。選択が
 * 決まると slot 34 (FUN_0065b360) が箱を戻し、状態 0 なら 2（選んだものが元、
 * FUN_00659200）。この移植は 範囲 (JW_CMD_HANI) に出て、確定で 複線 に戻す（選択が残って
 * いれば fk_selmode の道）。 */
static int fk_back;
static char fk_back_box[64];
/* 移動 (1323) の読み: slot 6 (FUN_00656f10) が +0x1f8 にバーの +0x780（1323 の DDX_Check、
 * FUN_004b1cf0）を、+0x1fc に +0x808（1324 元レイヤ）を取る。写す slot 3 (FUN_0065e230) は
 * +0x1f8 なら元の図形を消し（ブロック・寸法図形・プロテクトレイヤは消さずに 5498
 * 「…複線移動不可」）、6009「【図形を移動しました】」。写しに書込み線を着せる
 * FUN_004552a0 は +0x1f8 のとき呼ばれない（FUN_0065a340）ので 線色・線種・線幅は元のまま。
 * 置き場は FUN_00476900 の第四引数 = !(+0x1f8 && +0x1fc)、それが FUN_00447670 の
 * param_5 で、0 なら元の図形のレイヤ・グループ、でなければ書込みレイヤ。
 * 逆コンパイルの読み、原典では押していない。 */
static void fk_finish(jw_drawing *d, jw_obj *o)
{
    int src = para_obj, ni = (int)(o - d->obj);

    if (jw_cmd_bar_check(1323) > 0 && src >= 0 && src < d->ndrawn
        && !d->obj[src].sub) {
        op_t *u = op_new();
        const jw_obj *s = &d->obj[src];

        o->ltype = s->ltype;
        o->color = s->color;
        o->width = s->width;
        if (jw_cmd_bar_check(1324) > 0) {
            o->layer = s->layer;
            o->lgroup = s->lgroup;
        }
        op_keep(u, d, src, 1);
        jw_remove(d, src);
        if (src < ni)
            ni--;
        if (u)
            u->n = 1;
        para_obj = -1;
    } else
        op_push(1);
    para_last = ni;
    para_last_obj = d->obj[ni];
}

/* 原典の状態 3「作図する方向を指示」か: 自由位置を指したあと（para_step 2）か、
   間隔が分かっていて拾ったところ */
static int fk_dir_wait(const jw_drawing *d)
{
    return para_step == 2
           || (para_step == 1 && (box_mm(d, 1411) > 0.0 || have_kan
                                  || fk_rprev > 0.0));
}

/* 連続線選択 (1066、slot 27 FUN_0065b780)。原典は (L) で拾ったものを選択の一覧
 * (+0x174) に入れ、拾った位置を要素の +0x30 に置き（FUN_00657f10 の FUN_00455870）、
 * FUN_00659200 で鎖に並べる（+0x21c 鎖の数、円弧が二つ以上なら +0x24c）。slot 27 は
 * 状態 (+0x204) が 0 でなく、+0x24c が 0 で、選択がちょうど一つのとき、その +0x30 の点
 * （FUN_0046b9d0）で FUN_0040f830 を呼んで（選択は先に FUN_0044c830 で落とす）連続線を
 * 選び、受けたら FUN_00659200（選んだ鎖が複線の元 = fk_selmode）、受けなければ状態 0。
 * 端点指定は落とす（+0x284 = 0）。移植は拾い直さず 拾った要素そのものから歩く
 * （chain_walk、範囲選択の (R) と同じ）。釦は slot 6 が +0x21c == 1 && +0x24c != 1 で
 * 生かす（鎖が一つ）が、移植は押して効くとき（拾った一つ、または選択が一つ）だけ生かす。
 * 選んだ鎖の円弧（全円でないもの）は fukusen_selected が写さない（未）。
 * 逆コンパイルの読み、原典では押していない。 */
static int chain_walk(jw_drawing *d, int k, int clear);

static int fk_one_sel(const jw_drawing *d)
{
    int i, k = -1;

    if (!d)
        return -1;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].sel) {
            if (k >= 0)
                return -1;
            k = i;
        }
    return k;
}

static int fk_chain_ok(const jw_drawing *d)
{
    int k;

    if (!d || para_step < 1)
        return 0;
    k = fk_selmode ? fk_one_sel(d) : para_obj;
    return k >= 0 && k < d->ndrawn && d->obj[k].id == 0
           && (d->obj[k].cls == JW_SEN || d->obj[k].cls == JW_ENKO);
}

/* 範囲選択 (1067) の確定: 複線に戻して箱を戻す（slot 34）。選択が残れば fk_selmode */
static void fk_back_go(jw_drawing *d)
{
    char keep[sizeof fk_back_box];

    snprintf(keep, sizeof keep, "%s", fk_back_box);
    last_dr = d;
    jw_cmd_set(JW_CMD_FUKUSEN);
    box_put(1411, keep);
}

static int fukusen_selected(jw_drawing *d, double x, double y)
{
    int i, near = -1, n = d->ndrawn, made = 0, any = 0;
    double best = 1e300, typed = 0.0, off = 0.0, sgn = 1.0;

    if (fk_sel_used)
        return 0;
    for (i = 0; i < n; i++) {
        const jw_obj *o = &d->obj[i];
        double dd;

        if (!o->sel)
            continue;
        if (o->cls == JW_SEN) {
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1], l2 = dx * dx + dy * dy, u;

            if (l2 < 1e-14)
                continue;
            u = ((x - o->d[0]) * dx + (y - o->d[1]) * dy) / l2;
            u = u < 0.0 ? 0.0 : u > 1.0 ? 1.0 : u;
            dd = hypot(x - o->d[0] - u * dx, y - o->d[1] - u * dy);
        } else if (o->cls == JW_ENKO && fabs(o->d[6] - 1.0) < 1e-9) {
            dd = fabs(hypot(x - o->d[0], y - o->d[1]) - o->d[2]);
        } else
            continue;
        any = 1;
        if (dd < best) {
            best = dd;
            near = i;
        }
    }
    if (!any)
        return 0;
    fk_sel_used = 1;
    if (jw_cmd_get_kankaku(&typed))
        have_kan = 0;
    else
        typed = box_mm(d, 1411);
    {
        const jw_obj *o = &d->obj[near];

        if (o->cls == JW_SEN) {
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1], len = hypot(dx, dy);

            off = ((x - o->d[0]) * -dy + (y - o->d[1]) * dx) / len;
        } else
            off = hypot(x - o->d[0], y - o->d[1]) - o->d[2];
    }
    sgn = off < 0.0 ? -1.0 : 1.0;
    if (typed > 0.0)
        off = sgn * typed;
    {   /* つながった線は 角を延ばして つなぐ（四角の外側の複線が 四本一度にできる: fuzz 74）。
           つながらない線は ただ平行に写す（二本線の実験） */
        int *ch = (int *)calloc((size_t)n * 4 + 4, sizeof(int)); /* 鎖の並び（前後に伸ばせる窓） */
        unsigned char *used = (unsigned char *)calloc((size_t)n + 1, 1);
        int *fw = ch + 2 * n + 2;                    /* 並びの向き: 1 = 元の向き */
        int k;

        if (!ch || !used) {
            free(ch);
            free(used);
            return 1;
        }
        for (i = 0; i < n; i++) {
            const jw_obj *s0 = &d->obj[i];
            int len, head, closed = 0;
            double sx, sy, ex, ey;
            int *seq = ch;

            if (!s0->sel || s0->cls != JW_SEN || used[i] || hypot(s0->d[2] - s0->d[0], s0->d[3] - s0->d[1]) < 1e-9)
                continue;
            /* seq は n+1 個の窓（head から並べる） */
            head = n;
            len = 1;
            seq[head] = i;
            fw[head] = 1;
            used[i] = 1;
            sx = s0->d[0]; sy = s0->d[1]; ex = s0->d[2]; ey = s0->d[3];
            for (;;) {      /* 終わりへ */
                int hit = -1, f2 = 1;

                if (fabs(ex - sx) < 1e-7 && fabs(ey - sy) < 1e-7 && len > 1) {
                    closed = 1;
                    break;
                }
                for (k = 0; k < n; k++) {
                    const jw_obj *q = &d->obj[k];

                    if (used[k] || !q->sel || q->cls != JW_SEN)
                        continue;
                    if (hypot(q->d[0] - ex, q->d[1] - ey) < 1e-7) { hit = k; f2 = 1; break; }
                    if (hypot(q->d[2] - ex, q->d[3] - ey) < 1e-7) { hit = k; f2 = 0; break; }
                }
                if (hit < 0 || head + len >= 2 * n + 1)
                    break;
                seq[head + len] = hit;
                fw[head + len] = f2;
                used[hit] = 1;
                ex = f2 ? d->obj[hit].d[2] : d->obj[hit].d[0];
                ey = f2 ? d->obj[hit].d[3] : d->obj[hit].d[1];
                len++;
            }
            while (!closed) {   /* 始めへ */
                int hit = -1, f2 = 1;

                for (k = 0; k < n; k++) {
                    const jw_obj *q = &d->obj[k];

                    if (used[k] || !q->sel || q->cls != JW_SEN)
                        continue;
                    if (hypot(q->d[2] - sx, q->d[3] - sy) < 1e-7) { hit = k; f2 = 1; break; }
                    if (hypot(q->d[0] - sx, q->d[1] - sy) < 1e-7) { hit = k; f2 = 0; break; }
                }
                if (hit < 0 || head <= 0)
                    break;
                head--;
                seq[head] = hit;
                fw[head] = f2;
                used[hit] = 1;
                sx = f2 ? d->obj[hit].d[0] : d->obj[hit].d[2];
                sy = f2 ? d->obj[hit].d[1] : d->obj[hit].d[3];
                len++;
            }
            {
                double (*Q)[4];
                int m;

                Q = (double (*)[4])malloc(sizeof(double[4]) * (size_t)len);
                if (!Q)
                    continue;
                /* 鎖の向きの上の各線の 写した線 (点 + 向き) */
                for (m = 0; m < len; m++) {
                    const jw_obj *q = &d->obj[seq[head + m]];
                    double ax = fw[head + m] ? q->d[0] : q->d[2], ay = fw[head + m] ? q->d[1] : q->d[3];
                    double bx = fw[head + m] ? q->d[2] : q->d[0], by = fw[head + m] ? q->d[3] : q->d[1];
                    double dx = bx - ax, dy = by - ay, ln = hypot(dx, dy);
                    double sg = fw[head + m] ? 1.0 : -1.0;   /* 元の向きの左 = 鎖の向きの 左 か 右 */

                    Q[m][0] = ax - dy / ln * off * sg;
                    Q[m][1] = ay + dx / ln * off * sg;
                    Q[m][2] = dx / ln;
                    Q[m][3] = dy / ln;
                }
                {
                    double *CX = (double *)malloc(sizeof(double) * 2 * (size_t)(len + 1));
                    double *CY = CX + len + 1;

                    if (!CX) {
                        free(Q);
                        continue;
                    }
                    for (m = 0; m <= len; m++) {
                        int a = m - 1, c = m;       /* 角 m は 線 a と 線 c のあいだ */

                        if (m == 0 && closed)
                            a = len - 1;
                        if (m == len && closed)
                            c = 0;
                        if (a < 0) {                /* 鎖の始め */
                            CX[m] = Q[c][0];
                            CY[m] = Q[c][1];
                        } else if (c >= len) {      /* 鎖の終わり */
                            const jw_obj *q = &d->obj[seq[head + a]];
                            double bx = fw[head + a] ? q->d[2] : q->d[0], by = fw[head + a] ? q->d[3] : q->d[1];
                            double sg = fw[head + a] ? 1.0 : -1.0;

                            CX[m] = bx - Q[a][3] * off * sg;
                            CY[m] = by + Q[a][2] * off * sg;
                        } else {
                            double den = Q[a][2] * Q[c][3] - Q[a][3] * Q[c][2];

                            if (fabs(den) < 1e-9) {
                                CX[m] = Q[c][0];
                                CY[m] = Q[c][1];
                            } else {
                                double tt = ((Q[c][0] - Q[a][0]) * Q[c][3] - (Q[c][1] - Q[a][1]) * Q[c][2]) / den;

                                CX[m] = Q[a][0] + Q[a][2] * tt;
                                CY[m] = Q[a][1] + Q[a][3] * tt;
                            }
                        }
                    }
                    if (closed) {
                        CX[len] = CX[0];
                        CY[len] = CY[0];
                    }
                    for (m = 0; m < len; m++) {
                        jw_obj *o = jw_add(d, JW_SEN);

                        if (!o)
                            break;
                        /* つながった開いた鎖は 元の向きの逆に出る（原典の実測）。閉じた鎖・一本は そのまま */
                        if ((fw[head + m] != 0) != (!closed && len > 1)) {
                            o->d[0] = CX[m]; o->d[1] = CY[m]; o->d[2] = CX[m + 1]; o->d[3] = CY[m + 1];
                        } else {
                            o->d[0] = CX[m + 1]; o->d[1] = CY[m + 1]; o->d[2] = CX[m]; o->d[3] = CY[m];
                        }
                        made++;
                    }
                    free(CX);
                }
                free(Q);
            }
        }
        free(ch);
        free(used);
    }
    for (i = 0; i < n; i++) {
        jw_obj src = d->obj[i], *o;

        if (!src.sel || src.cls != JW_ENKO || fabs(src.d[6] - 1.0) >= 1e-9)
            continue;
        {
            double r, co = hypot(x - src.d[0], y - src.d[1]) - src.d[2];

            r = typed > 0.0 ? src.d[2] + (co < 0.0 ? -typed : typed) : src.d[2] + co;
            if (r < 1e-9)
                continue;
            o = jw_add(d, JW_ENKO);
            if (!o)
                break;
            memcpy(o->d, src.d, sizeof o->d);
            o->d[2] = r;
            made++;
        }
    }
    if (made)
        op_push(made);
    return 1;
}

void jw_cmd_set(int id)
{
    /* 消去 の (L) で線を一本拾ったまま 複線 に替えると、原典は拾った線をそのまま
       複線の元にする（最初のクリックは複写する位置になる。fuzz s7_63、
       tmp/dc6 ga/gb。部分消しの拾いは command をまたいで残る） */
    int carry_para = current == JW_CMD_SHOUKYO && id == JW_CMD_FUKUSEN
                     && cut_step == 1 && cut_obj >= 0;
    int carry_obj = cut_obj;

    prev = current;
    fk_sel_used = 0;
    if (fh_state) {                     /* a stroke does not outlive its command: what it drew stays, as one step */
        fh_made = 0;                    /* (the step is already in: fh_sample opened it) */
        fh_state = 0;
    }
    if (id == 0x8091 ? !gb_keep : id != JW_CMD_HANI)
        gb_free();                      /* a 外部変形 run does not outlive it */
    ms_text = 0;
    if (id != JW_CMD_HANI)
        ms_back = ms_after = 0;
    if (id == JW_CMD_SEN && prev == JW_CMD_SEN)
        hv = !hv;
    /* FUN_004fdc40: the new command's state starts empty. */
    current = id;
    esc_rearm = 0;
    esc_arc = 0;
    esc_3pt = 0;
    if (id == JW_CMD_MENTORI || id == JW_CMD_BUNKATSU || id == JW_CMD_FUKUSEN)
        box_put(1411, "");      /* asking for it again empties the box (s4_10; 複線 s7_66、tmp/dc7 h2) */
    bk_rr_n = 0;                /* FUN_0075b070: +0x138 = 0 */
    bk_gyaku = bk_senchou = 0;  /* 分割の補助設定（FUN_007619c0 で 0） */
    step = 0;
    en_step = 0;
    hou_step = 0;
    sel_outside = 0;
    sel_cut = 0;
    sel_keep = sel_sub = 0;
    comp_n = 0;
    cut_step = 0;
    shk_sel = shk_rep = 0;
    corner_step = 0;
    stretch_step = stretch_rwait = stretch_based = 0;
    para_step = 0;
    if (carry_para) {
        para_obj = carry_obj;
        para_step = 1;
    }
    fk_selmode = 0;
    fk_prev = fk_rprev = 0.0;
    fk_ten = 0;
    if (id != JW_CMD_HANI)
        fk_back = 0;
    if (id == JW_CMD_FUKUSEN && !carry_para && fk_has_sel()) {
        fk_selmode = 1;         /* 選択が残っていれば それが複線の元（すでに「間隔を入力するか」の段） */
        para_step = 1;
        para_obj = -1;
    }
    tracking = 0;
    /* The range starts over, the way FUN_004fdc40 leaves the command's own
       state -- but what is picked belongs to the elements, not to the
       command, so it stays until a new box is begun.  That is how the
       original can be given a range in 範囲選択 and then told what to do
       with it. */
    if (range_cmd(id)) {
        sel_step = 0;
        sel_free();
    }
    ren_step = 0;               /* 文字の 連 is not carried out of the command */
    moji_got = moji_got_all = 0;   /* 拾った文字も */
    ra_step = ra_have = 0;      /* and neither is a 連続弧 part way through */
    ra_have_pend = 0;
    ra_flip = 0;
    tk_step = 0;
    if (id == JW_CMD_SUNPO) {
        sun_step = 0;
        sun_made = 0;
        sun_chi = sun_chi_done = sun_enshu = 0;
        /* 一括処理 is dead again until a dimension has been drawn */
        ika_step = ika_live = ika_ntog = 0;
        ika_lt = -1;
    }
    tail_kind = 0;              /* and the status line's readout with it */
    sok_reset();                /* a 測定 run does not cross a command */
    sok_mode = SOK_LEN;         /* and it comes up on 距離測定 */
    kyo_step = 0;
    /* 測定 shows its readout from the moment it is entered, before any
       point is down (tools/probe125.sh) */
    if (id == JW_CMD_SOKUTEI)
        tail_set(4, 0.0, 0.0);
    /* leaving a command drops whatever 角度取得 or 長さ取得 had given --
       asked of the original: 線, 線角度, then 円 and back to 線, and the
       next line came out plain (tools/probe21.sh) */
    get_mode = 0;
    have_kata = have_naga = 0;
    /* and so does 間隔取得's: taking one, going out to 円 and back to
       複線 left nothing behind (tools/probe94.sh) */
    have_kan = 0;
    get_obj = -1;
    if (id == JW_CMD_NISEN) {
        nisen_step = 0;
        nisen_obj = -1;
        nisen_chain = 0;
    }
    auto_back = 0;
    au_reset();
    hk_write_cond = 0;
    hk_north = 0;
    tn_mode = 0;
    tn_cmp = 0;
    tn_count = 0;
    hk_sub = 0;
    hk_pv = 0;
    hk_iso_on = 0;
    hk_iso_rng = 0;
    hk_iso_step = 60;
    hk_tbl_pending = 0;
    hk_pts = 0;
    hk_calc_step = 0;
    hkp_n = 0;
    if (id == JW_CMD_KIGOU) {
        sk_cat = -1;                /* 入るたびに選び直す */
        sk_step = 0;
        sk_o1 = sk_o2 = -1;
        sk_need_pick = 1;
    }
    if (TG_IS3(id)) {
        if (tg_last != id)
            tg_cat = -1;
        tg_last = id;
        tg_step = 0;
        tg_need_pick = 1;
        tg_rh = tg_rv = 0;      /* 左内法・下内法で入る */
    }
    if (TG_IS(id)) {
        if (tg_last != id)
            tg_cat = -1;            /* 平面と断面で建具の一覧は別 */
        tg_last = id;
        tg_step = 0;
        tg_page2 = 0;
        tg_need_pick = 1;       /* 入るとすぐ ファイル選択 が出る */
    }
    if (id == JW_CMD_ENKO) {
        /* CZukeiEnko slot 10 (FUN_00648830) は命令の始まりで FUN_004aafb0(0) を
         * 呼び、半円 (+0xaf0) と 3点指示 (+0xaf4) を 0 に戻します。
         * 円弧・基点は戻りません */
        unsigned char *o = chk_slot((unsigned)JW_CMD_ENKO, 1320),
                      *t = chk_slot((unsigned)JW_CMD_ENKO, 1321);
        if (o)
            *o = 0;
        if (t)
            *t = 0;
    }
    if (id == JW_CMD_SESSEN) {
        ses_step = 0;
        ses_a = -1;
        ses_mode = 1689;        /* 円→円, the one the original enters in */
    }
    if (id == JW_CMD_SEKIEN) {
        sek_step = 0;
        sek_a = sek_b = -1;
    }
    if (id == JW_CMD_KYOKUSEN) {
        cv_n = 0;
        cv_mode = 1691;
        cv_base = 0;
    }
    if (id == JW_CMD_ZOKUHEN)
        zh_type = zh_layer = 1;
    if (id == JW_CMD_GAZOU)
        gz_reset();
    sel_flip = sel_base_wait = sel_dir = 0;
    sel_base_pick = sel_base_set = 0;
    if (id == JW_CMD_HATCH) {
        ht_n = 0;
        ht_nreg = 0;
        ht_base = ht_base_wait = 0;
        ht_sel = 0;
        ht_mode_set(1689);      /* and the bar's numbers with it */
        ht_nchain = 0;
    }
    if (id == JW_CMD_CHUSHIN) {
        chu_step = 0;
        chu_a = chu_b = -1;
    }
}

/* Esc: let go of the points a command has taken so far, without leaving the
 * command.
 *
 * The original does this -- the status line says so.  In 矩形, a first click
 * turns 「始点を指示してください」 into 「◆　　終点を指示してください」,
 * and Esc turns it back.  (The key has to reach the frame: a driven session
 * never gives the view the focus, which is why an earlier look said the
 * original ignored Esc.)  What is already drawn stays; so does the range,
 * which belongs to the elements rather than to the command.
 */
void jw_cmd_escape(void)
{
    if (current == JW_CMD_GAZOU)
        gz_reset();
    step = 0;
    en_step = 0;
    tk_step = 0;
    tk2_n = 0;
    tk_any = 0;
    tk_pickmode = 0;
    tk_an = 0;
    hou_step = 0;
    cut_step = 0;
    shk_sel = 0;
    corner_step = 0;
    bk_rr_n = 0;
    stretch_step = stretch_rwait = stretch_based = 0;
    para_step = 0;
    fk_ten = 0;
    fk_rprev = 0.0;
    tracking = 0;
    nisen_step = 0;
    nisen_obj = -1;
    nisen_chain = 0;
    ses_step = 0;
    ses_a = -1;
    sek_step = 0;
    sek_a = sek_b = -1;
    chu_step = 0;
    chu_a = chu_b = -1;
    cv_n = 0;
    ht_n = 0;
    ht_nchain = 0;
    ten_del = 0;
    ten_cross = 0;
    ten_a = -1;
    sun_step = sun_chi ? 5 : sun_enshu ? 7 : sun_radius ? 2 : 0;
    sun_made = 0;
    au_reset();
    if (current == JW_CMD_KIGOU && sk_step != 4)
        sk_step = 0;               /* 線・位置のとちゅうは捨てる（文字入力は別） */
}

/* The Esc *key*.  The original does not simply let go of everything: it steps
 * the command back, one stage a press, and which stage it comes back to
 * depends on the command (tools/escprobe.sh, tmp/esc_report.md):
 *
 *   範囲選択・複写・移動  placing -> the selection -> the box's second corner
 *        (with the selection cleared, the first corner kept) -> the first
 *        corner.  (The status line is only redrawn on the next mouse move
 *        when it comes back to the first corner; here it is right at once.)
 *   測定        the prompt says 始点 again, but the chain goes on: the next
 *        click is still a 次の点 and adds to the total
 *   消去 (部分消し)  終点 -> 始点 -> the line
 *   線・矩形・円  one press before the first click lets go (as jw_cmd_escape);
 *        pressed right after a shape was finished it re-arms that shape's
 *        first point
 * Everything else goes straight back to its first stage.  jw_cmd_escape
 * stays the plain "let go of everything" that 戻る and the tests use. */
void jw_cmd_esc_key(jw_drawing *d)
{
    if (current == JW_CMD_HIKAGE && hk_pv) {
        hk_pv = 0;              /* 確認の窓から戻る */
        return;
    }
    if (range_cmd(current) && current != JW_CMD_ZUKEIREG) {
        switch (sel_step) {
        case 1:
            sel_step = 0;
            tracking = 0;
            return;
        case 2:
            sel_clear(d);
            sel_step = 1;          /* the first corner (sel_x0, sel_y0) stays */
            return;
        case 3:
        case 4:
            if (sel_flip || sel_base_wait) {
                sel_flip = sel_base_wait = 0;
                return;
            }
            sel_free();
            sel_step = d && jw_cmd_sel_count(d) > 0 ? 2 : 0;
            return;
        }
    }
    /* 寸法: one dimension in -> its 終点 -> 始点 -> ■寸法線の位置 -> start
       (probed on the original, tools/stagecmp.sh). */
    if (current == JW_CMD_SUNPO && !sun_chi && !sun_kaku && !sun_enshu
        && !sun_radius && !ika_step) {
        if (sun_made && sun_step == 2) {
            sun_made = 0;
            sun_step = 3;
            tracking = 0;
            return;
        }
        if (sun_step >= 1 && sun_step <= 3) {
            sun_step--;
            if (sun_step == 2)
                sun_made = 0;
            tracking = 0;
            return;
        }
    }
    /* 寸法の 角度・円周 (RESUME.md 2026-10-13 の節, tools/jwdraw.ps1 の
       raw:f,256/257,27,0 で実測): 一度も作図していない歩みの途中（原点・
       円の指示待ちも、その先の四手のどこでも）で Esc を押すと、原典は
       一段ずつ戻らず**まるごと手放して平の二点寸法に戻る**（バーの
       角度／円周が外れ、歩みは 0 -- 底の「寸法値」tail が消えるかどうかで
       見分けた）。ただし「作図済みで次に備えている」状態（sun_made かつ
       step==2）だけは別で、そこから一段戻ると角度／円周のまま
       寸法の終点を取り直す（底の block と同じ式）。そこからもう一度 Esc を
       押すと（もう sun_made ではないので）やはりまるごと手放す。 */
    if (current == JW_CMD_SUNPO && (sun_kaku || sun_enshu) && !ika_step) {
        if (sun_made && sun_step == 2) {
            sun_made = 0;
            sun_step = 3;
            tracking = 0;
            return;
        }
        sun_kaku = sun_enshu = 0;
        sun_step = 0;
        sun_made = 0;
        tracking = 0;
        return;
    }
    /* 寸法値 (1069): 同じ形。作図済みで次に備えている状態だけが一段戻って
       二点目を取り直し、それ以外（まだ一つも作っていない、一点目だけ
       打った途中を含む）は寸法値をまるごと手放して平の二点寸法に戻る
       （実測は上と同じ、tools/jwdraw.ps1 で cmd:32847;pb:1069;...）。 */
    if (current == JW_CMD_SUNPO && sun_chi && !ika_step) {
        if (sun_chi_done && sun_step == 5) {
            sun_chi_done = 0;
            sun_step = 6;
            tracking = 0;
            return;
        }
        sun_chi = 0;
        sun_step = 0;
        tracking = 0;
        return;
    }
    /* 半径・直径 (1065/1066): 一手で描き切るので、そのあいだに戻る段が
       ない。一度も描いていなければ Esc は半径／直径をまるごと手放して
       平の二点寸法に戻り、一つでも描いたあとは原典は何もしない
       （sun_step は 2 のままで、jw_cmd_escape の sun_step リセットも
       2 のままなので黙って下に落としてよい）。sunpo_radius が描いたとき
       sun_radius_made を立てるのはこの区別のためだけ（sun_made を使うと
       base/角度/円周 の「次へ」の案内まで出てしまう）。 */
    if (current == JW_CMD_SUNPO && sun_radius && !sun_radius_made
        && !ika_step) {
        sun_radius = 0;
        sun_radius_made = 0;
        sun_step = 0;
        tracking = 0;
        return;
    }
    /* 複線: the direction -> the interval -> the line to offset */
    if (current == JW_CMD_FUKUSEN && fk_ten) {
        if (++fk_ten > 3)       /* 端点指定: slot 16 は +0x284 を 1 足し、3 を超えれば 0 */
            fk_ten = 0;
        tracking = 0;
        return;
    }
    if (current == JW_CMD_FUKUSEN && para_step > 0) {
        para_step--;
        if (para_step < 1)
            para_obj = -1;
        tracking = 0;
        return;
    }
    /* 分割: 状態 3（第二点まで）-> 状態 2（始点のみ）-> 状態 0。原典の実測
       （RESUME.md 2026-10-12 午後〜夜の節）どおり一段ずつ戻る。第一案内
       （corner_step==0）での Esc は原典では直前の作図を消すはずだが、まだ
       ここには書いていない（訊いただけで確かめていないため、nokori.md）。
       連続点分割の途中は点を一つずつ外す（原典 FUN_007619c0: +0x138>=1 なら
       +0x138 を 1 減らすだけ。0 になれば第一案内 5357 に戻る ── tools/bkprobe.sh
       で 3 点から Esc を三回、5820→5819→5357 と実測、2026-10-13）。 */
    if (current == JW_CMD_BUNKATSU && bk_rr_n > 0) {
        bk_rr_n--;
        return;
    }
    /* 天空図: 中心待ち → 測定点待ち → 初めのバー と一段ずつ（tools/tnprobe.sh
       で Esc を二回、バーが 9006 系 → 9005 → 32971 と戻るのを読んだ） */
    if (current == JW_CMD_TENKU && tn_cmp > 0) {
        tn_cmp--;                   /* FUN_007346f0 の +0xbc = 5: 歩みを一つ戻し、初めの歩みなら抜ける */
        return;
    }
    if (current == JW_CMD_TENKU && tn_mode > 0) {
        tn_mode--;
        return;
    }
    if (current == JW_CMD_BUNKATSU && corner_step > 0) {
        corner_step--;
        if (corner_step == 0)
            corner_obj = -1;
        return;
    }
    /* 円弧 (the 円 bar's 1318, not 3点指示): 終点 -> 始点 -> 中心点, and right
       after a finished arc the first press is back at its 終点 */
    if (current == JW_CMD_ENKO && jw_cmd_bar_check(1318) > 0
        && jw_cmd_bar_check(1321) <= 0) {
        if (en_step == 0 && esc_arc) {
            esc_arc = 0;
            en_step = 2;
            tx = sx;
            ty = sy;
            tracking = 0;
            return;
        }
        if (en_step > 0) {
            en_step--;
            tracking = 0;
            return;
        }
    }
    /* 円の ３点指示 (1321): unlike 1318, a point part way through is not
       let go one at a time -- any Esc before the circle is finished drops
       the whole attempt back to its own first point (原典実測、
       tools/jwdraw.ps1 raw:f,256/257,27,0: ２点目待ちでの Esc も３点目
       待ちでの Esc も同じ「１点目の位置を指示してください」に戻った).
       Right after one is finished, the first press takes its 3点目 back,
       the same idea as esc_arc but its own flag (RESUME.md 2026-10-13). */
    if (current == JW_CMD_ENKO && jw_cmd_bar_check(1321) > 0) {
        if (en_step == 0 && esc_3pt) {
            esc_3pt = 0;
            en_step = 2;
            tx = sx;
            ty = sy;
            tracking = 0;
            return;
        }
        if (en_step > 0) {
            en_step = 0;
            tracking = 0;
            return;
        }
    }
    if (current == JW_CMD_SOKUTEI && sok_mode == SOK_LEN && !sok_write
        && !sok_one && sok_n > 0) {
        sok_esc = 1;
        return;
    }
    if (current == JW_CMD_SHOUKYO && shk_sel) {
        /* 範囲の途中: 終点待ちなら始点へ、ほかは範囲選択消去をやめる
           （CZukeiShoukyo の 16 番 FUN_0070ccb0 が +0x200 を 0 に戻す） */
        if (shk_sel == 2)
            shk_sel = 1;
        else {
            sel_clear(d);
            shk_sel = 0;
        }
        return;
    }
    if (current == JW_CMD_SHOUKYO && cut_step > 0) {
        cut_step--;
        if (cut_step == 0)
            cut_obj = -1;
        return;
    }
    if ((current == JW_CMD_SEN || current == JW_CMD_KUKEI
         || current == JW_CMD_ENKO) && step == 0 && en_step == 0
        && esc_rearm && esc_cmd == current
        && !(current == JW_CMD_ENKO && box_mm(d, 1411) > 0.0)
        && !(current == JW_CMD_ENKO && jw_cmd_bar_check(1318) > 0)) {
        esc_rearm = 0;
        sx = tx = esc_x;
        sy = ty = esc_y;
        step = 2;
        return;
    }
    jw_cmd_escape();
}

/* Whether the command in force is part way through -- a point down, an
 * element picked -- which is what the original's 戻る asks first.
 * FUN_00504100 calls the command's own vtable +0x40 before it touches the
 * drawing, and only when that says there was nothing of its own to take
 * back does a step of the drawing come off (the note on jw_cmd_redo; it is
 * why tests/redo_test.c leaves the command before every press).  The
 * states are the ones jw_cmd_escape puts back. */
int jw_cmd_midway(void)
{
    int sun_rest = sun_chi ? 5 : sun_enshu ? 7 : sun_radius ? 2 : 0;

    if (current == JW_CMD_GAZOU)
        return gz_midway();
    /* Only the command in force: another one's state stays as it was left
       -- 中心線 keeps its middle after drawing, ready for the next line --
       and is put back when that command is entered again. */
    if (step != 0)
        return 1;
    switch (current) {
    case JW_CMD_ENKO:      return en_step != 0;
    case JW_CMD_HOURAKU:   return hou_step != 0;
    case JW_CMD_SHOUKYO:   return cut_step != 0;
    case JW_CMD_CORNER:
    case JW_CMD_MENTORI:
    case JW_CMD_BUNKATSU:  return corner_step != 0 || bk_rr_n > 0;
    case JW_CMD_SHINSHUKU: return stretch_step != 0 || stretch_based || stretch_rwait;
    case JW_CMD_FUKUSEN:   return para_step != 0;
    case JW_CMD_NISEN:     return nisen_step != 0;
    case JW_CMD_SESSEN:    return ses_step != 0;
    case JW_CMD_SEKIEN:    return sek_step != 0;
    case JW_CMD_CHUSHIN:   return chu_step != 0;
    case JW_CMD_KYOKUSEN:  return cv_n != 0 || cv_base != 0;
    case JW_CMD_KIGOU:     return sk_step >= 1 && sk_step <= 4;
    case JW_CMD_AUTO:      return au_st != 0;
    /* ハッチ: a circle right-clicked leaves no corners and no chain --
       only a region -- and the original takes 戻る for that too
       (CZukeiHachi slot 16 tests +0x224 and +0x228, which is the
       picked list, not the corner count) */
    case JW_CMD_HATCH:     return ht_n != 0 || ht_nchain != 0
                                  || ht_nreg != 0;
    case JW_CMD_SUNPO:     return sun_step != sun_rest;
    /* 文字 の 連 with one text picked (ren_first, held by its place) and
       the second, or the place for it, still to come.  CZukeiMoji's slot
       16 (FUN_006bd270) takes the press while any of its own part-way
       states is up (+0x5d0, +0x5d4, +0x5e0 ...), lowering it. */
    case JW_CMD_MOJI:      return ren_step >= 2 || moji_got;
    case JW_CMD_HANI:
    case JW_CMD_FUKUSHA:
    case JW_CMD_IDOU:
    case JW_CMD_SEIRI:
    case JW_CMD_PARAM:
        /* a box being drawn, or a selection made or settled.  A settled
           one is held by its places in the drawing (sel_at), and 移動 puts
           each moved element back **at** its place: a step of the drawing
           undone in between would have it write over whatever came to
           stand there.  CZukeiFukusha's own +0x40 (FUN_0064e7c0) takes the
           press in several of its states. */
        return sel_step != 0;
    }
    return 0;
}

/* And what the command does with that press, read out of each one's
 * vtable +0x40:
 *
 *   線 (CZukeiSen, FUN_006ed530)  with its first point down it lets go of
 *        the point and says it took the press -- one press, back to the
 *        start
 *   中心線 (CZukeiChuushinSen, FUN_0063d5f0), 接円 (CZukeiSetuEn,
 *        FUN_00706a20) and ２線 (CZukei2Sen, FUN_00624150)  their state
 *        goes back **one** each press, so the second thing picked is
 *        dropped before the first
 *   分割 (CZukeiBunkatsu)  from one line picked straight back to the start
 *
 * The rest go back to their start, which is what jw_cmd_escape does; how
 * far each of them steps has not been read (コーナー and 伸縮 keep a
 * history of their own and step through it, which the port does not
 * have). */
int jw_cmd_back(jw_drawing *d)
{
    if (current == JW_CMD_KIGOU && sk_step == 4) {
        sk_step = 0;            /* 文字入力をやめる（置いたぶんはそのまま） */
        sk_run.active = 0;
        line_n = 0;
        line_gen++;
        return 1;
    }
    if (current == JW_CMD_MOJI && ren_step >= 2) {
        ren_step = 1;           /* let go of the text; 連 stays on */
        tracking = 0;
        return 1;
    }
    if (current == JW_CMD_MOJI && moji_got) {
        /* 拾った文字を放す: FUN_006bd270 は +0x5c4 = 0 にし、入力欄に字が
           あれば空にして（+0x8560 = 0）押されたことにする */
        moji_got = moji_got_all = 0;
        line_n = 0;
        line_gen++;
        return 1;
    }
    if ((current == JW_CMD_HANI || current == JW_CMD_FUKUSHA
         || current == JW_CMD_IDOU || current == JW_CMD_SEIRI
         || current == JW_CMD_PARAM)
        && sel_step != 0) {
        /* let go of the selection, marks and all */
        sel_clear(d);
        sel_step = 0;
        tracking = 0;
        return 1;
    }
    if (current == JW_CMD_CHUSHIN && chu_step > 0) {
        chu_step--;
        if (chu_step < 2)
            chu_b = -1;
        if (chu_step < 1)
            chu_a = -1;
        tracking = 0;
        return 1;
    }
    /* 接円 (CZukeiSetuEn, FUN_00706a20): 3 -> 2 -> 0, the second element
       and then the first -- the port's sek_step 2 and 1 */
    if (current == JW_CMD_SEKIEN && sek_step > 0) {
        sek_step--;
        if (sek_step < 2)
            sek_b = -1;
        if (sek_step < 1)
            sek_a = -1;
        tracking = 0;
        return 1;
    }
    /* ２線 (CZukei2Sen, slot 16 at 0x00624150): the end point's state 3
       goes back to 2, the start point's, and 2 back to 1, the line --
       the port's nisen_step 2 and 1 */
    if (current == JW_CMD_NISEN && nisen_step > 0) {
        nisen_step--;
        if (nisen_step < 1)
            nisen_obj = -1;
        if (nisen_chain) {
            /* 角を回った続きの途中。原典（同じ slot 16）は鎖を一段戻して
               前の区間の終点待ちに返り、書いた分を図面から戻すが、移植は
               鎖を一段しか持たないので、書き出し待ちの二本ごと捨てて
               基準線から（逆コンパイルの読み、原典では押していない） */
            nisen_chain = 0;
            nisen_step = 0;
            nisen_obj = -1;
        }
        tracking = 0;
        return 1;
    }
    /* 複線 (CZukeiFukusen, slot 16 at 0x00657670): its state at +0x204 is
       3 while it waits for the side to be told and 2 while it waits for
       the offset, and the press takes 3 to 2 and then 2 to 0 -- one step
       back each time, and the second one lets go of the picked line
       (+0x20c = 0).  The port's para_step 2 and 1 are those two. */
    if (current == JW_CMD_FUKUSEN && fk_ten) {
        if (++fk_ten > 3)       /* 端点指定 (+0x284) が先: 1→2→3→0 */
            fk_ten = 0;
        tracking = 0;
        return 1;
    }
    if (current == JW_CMD_FUKUSEN && para_step > 0) {
        para_step--;
        if (para_step < 1)
            para_obj = -1;
        tracking = 0;
        return 1;
    }
    /* 曲線 (CZukeiKyokuSen, slot 16 at 0x00621ca0 の辺り): its state at
       +0xac walks straight down, 5 -> 4 -> 3 -> 2 -> 1, one per press
       (サイン曲線 jumps 5 -> 3, and that mode is not done here).  The
       port's state is the points it has collected and the line the
       two unfinished modes pick first, so one press drops the last
       point, and the last press drops the line. */
    if (current == JW_CMD_KYOKUSEN && (cv_n > 0 || cv_base)) {
        if (cv_n > 0)
            cv_n--;
        else
            cv_base = 0;
        tracking = 0;
        return 1;
    }
    /* ハッチ (CZukeiHachi, slot 16 at 0x00672470).  With the 実行 state
       (+0x208) clear it looks at four things, in this order, and the
       first one that is set is the one it undoes:
     *
     *   +0x220, +0x20c   two states of its own, set to 0.  The port has
     *                    neither (they are 範囲選択's own, which the port
     *                    settles in one press)
     *   +0x230 >= 1      **one** off the count of lines picked with (L)
     *                    -- the port's ht_nchain
     *   +0x224 / +0x228  the picked list: it walks it and lets go of
     *                    **all** of it (FUN_00672d70(-1) until nothing
     *                    is selected any more) -- the port's ht_nreg
     *
     * So the chain comes off one line at a time, and once it is empty
     * the next press drops every ring and circle taken, in one go.
     */
    if (current == JW_CMD_HATCH && (ht_nchain > 0 || ht_nreg > 0)) {
        if (ht_nchain > 0) {
            ht_nchain--;
            if (!d || !hatch_chain(d)) {
                ht_n = 0;       /* what is left no longer closes */
                ht_nreg = 0;
            }
        } else {
            if (d)
                sel_clear(d);
            ht_n = 0;
            ht_nreg = 0;
        }
        tracking = 0;
        return 1;
    }
    /* 寸法 (CZukeiSunpo, slot 16 at 0x0077b730).  Its walk is in [0x6f],
     * which is the port's sun_step with the same numbers for the
     * ordinary two-point kind -- FUN_0077cc90 picks the prompt from it,
     * and the port's prompts line up (jw_cmd_status's case for 寸法).
     * The ladder reads:
     *
     *   0 or 1  **answers 0** -- it does not take the press at all, and
     *           the drawing's own 戻る gets it.  So the 引出線の基準点
     *           and the 寸法線の位置 are not given back one at a time
     *   2       -> 0
     *   3       -> 2 (DAT_00a0bcc0 の値次第では 0。既定は分かっていない)
     *   4, 5, 6 step down one each, but those are the original's own
     *           numbering for the kinds the port numbers differently
     *           (角度・寸法値・円周), so they are left alone here
     *
     * There is also a count at [0x1147]: while it is above zero the
     * press takes the **last dimension drawn** off instead, which is
     * what the drawing's 戻る does in the port.
     */
    if (current == JW_CMD_SUNPO && !sun_chi && !sun_kaku && !sun_enshu
        && !sun_radius) {
        if (sun_step == 2 || sun_step == 3) {
            sun_step = sun_step == 3 ? 2 : 0;
            tracking = 0;
            return 1;
        }
        return 0;               /* 0 と 1 は原典も受け取りません */
    }
    /* 円 (CZukeiEnko) は**押しを受け取りません**。原典に押させて
     * 確かめました（tools/probe156.sh）—— 中心を置いた状態でも、
     * 円弧 で二点置いた状態でも、**状態行がまったく動きません**:
     *
     *   素の円、中心だけ置いて 戻る   「円位置を指示してください」のまま
     *   円弧、中心だけ               「円弧の始点を…」のまま
     *   円弧、二点置いて二回押す     「◆　終点を…」のまま
     *
     * そして**描き終えた円は図面の 戻る で消えます**。slot 16
     * (FUN_006471c0) が 0 を返す枝に落ちているということで、受け取ら
     * なければ呼んだ側の 戻る が動く、という形です。
     *
     * （その関数の +0x308 は 5 → 2 → 0 と降りる別の状態で、クリックの
     * 段ではありません。何なのかは分かっていません。） */
    if (current == JW_CMD_ENKO)
        return 0;
    /* 分割 (CZukeiBunkatsu) goes from its state 2 straight back to 0, which
       is the start; so does the rest, as far as anyone has read */
    jw_cmd_escape();
    return 1;
}

/* Space: turn 水平・垂直 over.
 *
 * The original does this while a line is being drawn -- with the start down
 * and the cursor up and to the right, its readout went from [45.000°] to
 * [90.000°] and back again on the next press, and the line it drew after one
 * press came out straight up (decomp/res/senspace.jww).  That is the same
 * flag the bar's 水平・垂直 box carries, so this is the same switch.
 */
void jw_cmd_space(void)
{
    hv = !hv;
}

void jw_cmd_reset(void)
{
    /* 新規 does not enter a command, so nothing here goes through
       jw_cmd_set: the previous command and 水平・垂直 are left alone, the
       way the original leaves +0x8568 and +0x730 alone. */
    current = JW_CMD_SEN;
    jw_cmd_escape();            /* and nothing picked out of the last one:
                                   the indices meant its elements, not
                                   these */
    /* All of it, the 進む side as well.  This used to free only the
       steps below nop, and only their item lists: ntop stayed where it
       was and nitem kept its count, so 新規 then 進む brought a freed
       step back to life and the 戻る after it read a NULL item list
       (tests/cmdfuzz_test.c's undo-and-redo sweep, seed 2). */
    nop = 0;
    while (ntop > 0)
        op_drop(&op[--ntop]);
    sel_step = 0;
    sel_free();
}

int jw_cmd_can_undo(void)
{
    return nop > 0;
}

int jw_cmd_can_redo(void)
{
    return ntop > nop;
}

/* how many steps 戻る can take back -- for the tests, which want to know
   whether an action took a step at all */
int jw_cmd_undo_depth(void)
{
    return nop;
}

/* Which state the drawing is in, as far as 戻る/進む can tell: 0 for the
   untouched one, otherwise the serial number of the last step still done.
   Two equal stamps mean the same drawing, so the front end compares it with
   the one it took when the file was saved to know whether there is anything
   to lose. */
unsigned jw_cmd_edit_stamp(void)
{
    return nop > 0 ? op[nop - 1].gen : 0;
}

/* The drawing's elements as they stand, kept so that 進む can put them
   back.  Only the elements: the string pool only ever grows, so the
   offsets in them stay good. */
static int op_snap(op_t *o, const jw_drawing *d)
{
    jw_obj *p;

    free(o->after);
    o->after = 0;
    o->nafter = o->ndrawn_after = 0;
    if (d->nobj <= 0)
        return 1;
    p = (jw_obj *)malloc((size_t)d->nobj * sizeof *p);
    if (!p)
        return 0;
    memcpy(p, d->obj, (size_t)d->nobj * sizeof *p);
    o->after = p;
    o->nafter = d->nobj;
    o->ndrawn_after = d->ndrawn;
    return 1;
}

void jw_cmd_undo(jw_drawing *d)
{
    op_t *o;
    int i;

    if (!d || nop <= 0)
        return;
    o = &op[nop - 1];
    if (!op_snap(o, d))
        return;
    if (o->before) {
        /* the whole drawing back as it stood (see op_t's `before`) */
        if (o->nbefore > d->cobj) {
            jw_obj *p = (jw_obj *)realloc(d->obj, (size_t)o->nbefore * sizeof *p);

            if (!p)
                return;
            d->obj = p;
            d->cobj = o->nbefore;
        }
        memcpy(d->obj, o->before, (size_t)o->nbefore * sizeof *d->obj);
        d->nobj = o->nbefore;
        d->ndrawn = o->ndrawn_before;
        nop--;
        step = 0;
        tracking = 0;
        return;
    }
    {   /* A definition and the elements inside it sit past the drawn ones,
           at the very end, so they come off first. */
        int n;
        for (n = o->ndef; n > 0 && d->nobj > d->ndrawn; n--)
            jw_remove(d, d->nobj - 1);
    }
    {   /* Everything is added at the end of the drawn elements, so the last
           command's elements are the last ones there -- unless it said
           where it put them.  Each one is kept as it goes, because
           進む puts exactly these back. */
        int n;

        free(o->back);
        o->back = 0;
        o->nback = 0;
        if (o->n > 0)
            o->back = (jw_obj *)malloc((size_t)o->n * sizeof *o->back);
        for (n = o->n; n > 0 && d->ndrawn > 0; n--) {
            int at = o->add_at ? o->add_at - 1 : d->ndrawn - 1;

            if (o->back)
                o->back[o->nback++] = d->obj[at];
            jw_remove(d, at);
        }
    }
    for (i = o->nitem - 1; i >= 0; i--) {
        op_item *it = &o->item[i];
        if (it->removed == 3) {
            if (it->at < d->nobj)
                jw_remove(d, it->at);
        } else if (it->removed == 2) {
            /* a definition, or an element inside one: they were recorded
               backwards so that putting them back in this order gets them
               in their own order again */
            jw_obj *p = jw_add_def(d, it->was.cls);
            if (p)
                *p = it->was;
        } else if (!it->removed) {
            if (it->at < d->nobj)
                d->obj[it->at] = it->was;
        } else {
            /* an erased one goes back where it was, so the drawing order --
               and so what is on top of what -- comes back with it */
            jw_obj *p = jw_add(d, it->was.cls);
            if (p) {
                int at = it->at < d->ndrawn ? it->at : d->ndrawn - 1;
                *p = it->was;
                while (p > &d->obj[at]) {
                    jw_obj t = p[-1];
                    p[-1] = p[0];
                    p[0] = t;
                    p--;
                }
            }
        }
    }
    /* A step that only added elements is put back by 進む from `back`, not
       from the copy of the whole drawing op_snap made above -- jw_cmd_redo
       tests exactly this before it looks at `after`.  So that copy is
       dropped again: it is the whole drawing, 136 bytes an element, made
       on every 戻る, and kept for as long as the step can be redone.
       Two hundred presses on a drawing of fifty thousand elements came to
       well over a gigabyte, which the browser build does not have. */
    if (o->nitem == 0 && o->ndef == 0 && o->nback > 0) {
        free(o->after);
        o->after = 0;
        o->nafter = o->ndrawn_after = 0;
    }
    /* the items stay: 進む may bring this step back, and then 戻る
       has to be able to take it away again */
    nop--;
    /* **円 は歩みを手放しません。**原典に押させると、中心を置いた
       状態で 戻る を押しても状態行が「円位置を指示してください」の
       ままで、描き終えた円のほうが消えました（tools/probe156.sh）。
       命令が押しを受け取らない (jw_cmd_back が 0 を返す) ので、
       命令の側は何も変わらないわけです。
       ほかの命令でここを空にしているのは、拾った要素を**番号で**
       覚えているものがあるからで（番号は戻したあとずれます）、
       円 が覚えているのは座標だけなので残して差し支えありません。 */
    if (current != JW_CMD_ENKO)
        step = 0;
    tracking = 0;
}

/* 進む (0xe12c).  One press puts one undone step back, and that is all
 * it is: the original was given three lines, two 戻る and then one and
 * two 進む, and came back with two lines and then three
 * (tools/probe107.sh).
 *
 * Measuring it took fixing the apparatus first.  The decompilation says
 * 戻る (`FUN_00504100`) asks **the command in force** to undo its own
 * step before it touches the drawing (vtable +0x40), and 進む
 * (`FUN_00503e90`) does the same through +0x3c.  So a command that is
 * part way through swallows the press, which is why six earlier runs
 * could not make the counts add up.  Leaving the command and coming
 * back first makes every press land exactly once. */
/* The commands hold what they have picked by its place in the drawing.
 * The original holds the element itself, so a 進む in the middle of a
 * command (its +0x3c declines, and the drawing's step goes back) leaves the
 * pick where it was; here a step put back **at the front** moves every
 * element along, and the held places with them have to move by as much. */
static int read_pick;            /* (defined with 線上点, further down) */
static void picks_shift(int by)
{
    int *const P[] = { &cut_obj, &corner_obj, &stretch_obj, &para_obj,
                       &para_last, &chu_a, &chu_b, &ses_a, &sek_a, &sek_b,
                       &nisen_obj, &get_obj, &ren_first, &read_pick };
    unsigned k;
    int i;

    for (k = 0; k < sizeof P / sizeof P[0]; k++)
        if (*P[k] >= 0)
            *P[k] += by;
    for (i = 0; i < ht_nchain; i++)
        if (ht_chain[i] >= 0)
            ht_chain[i] += by;
}

/* The copy 複線's 連続 (1064) carries on from.  It is held by its place,
 * and a place goes stale: a 戻る that puts an erased element back in the
 * middle, or a 進む that puts a step back at the front, moves everything
 * after it along, and the place then names the next line over.  So the
 * copy itself is kept too, and the place is only trusted while it still
 * holds that copy; otherwise the drawn elements are searched for it, last
 * first, and if it is not there any more 連続 has nothing to carry on
 * from.  (The original holds the element itself.) */
static int para_find(const jw_drawing *d)
{
    int i;

    if (!d || para_last < 0)
        return -1;
    if (para_last < d->ndrawn
        && !memcmp(&d->obj[para_last], &para_last_obj, sizeof para_last_obj))
        return para_last;
    for (i = d->ndrawn - 1; i >= 0; i--)
        if (!memcmp(&d->obj[i], &para_last_obj, sizeof para_last_obj))
            return para_last = i;
    return -1;
}

void jw_cmd_redo(jw_drawing *d)
{
    op_t *o;
    int i;

    if (!d || ntop <= nop)
        return;
    o = &op[nop];
    if (o->nitem == 0 && o->ndef == 0 && o->nback > 0) {
        /* The step only added elements, and they go back **at the
           front**.  That is the original's own answer, not a guess:
           three lines drawn 1, 2, 3 and then

             戻る x1, 進む x1   ->  3, 1, 2
             戻る x2, 進む x1   ->  2, 1
             戻る x2, 進む x2   ->  3, 2, 1

           (decomp/res/redo_*.jww).  The first of those is the one that
           tells 'put them at the front' apart from 'turn the whole
           list round', which fits the other two just as well. */
        for (i = 0; i < o->nback; i++)
            if (!jw_add(d, o->back[i].cls))
                return;
        /* Only the drawn elements turn round.  jw_add puts each new one at
           the end of the drawn ones, ahead of the block definitions, so the
           definitions stay where they are.  This used to move the whole
           array along -- definitions too -- which pushed the last of them
           off the end and left the new slots' blanks among the drawn
           elements: a point at the origin came back as a block reference
           (tests/cmdfuzz_test.c, seed 7 at 3000 steps). */
        memmove(&d->obj[o->nback], &d->obj[0],
                (size_t)(d->ndrawn - o->nback) * sizeof *d->obj);
        memcpy(d->obj, o->back, (size_t)o->nback * sizeof *d->obj);
        /* and they are at the front now, which is where the next 戻る of
           this step has to take them from -- it took the last drawn ones,
           which after this are somebody else's */
        o->add_at = 1;
        picks_shift(o->nback);
    } else {
        /* Anything else -- a step that moved or erased things rather
           than adding them -- has not been asked of the original, so
           the drawing simply goes back to how it stood before the
           戻る.  The content is right; whether the original would order
           it differently is not known. */
        if (o->nafter > d->cobj) {
            jw_obj *p = (jw_obj *)realloc(d->obj,
                                          (size_t)o->nafter * sizeof *p);

            if (!p)
                return;
            d->obj = p;
            d->cobj = o->nafter;
        }
        if (o->nafter > 0)
            memcpy(d->obj, o->after, (size_t)o->nafter * sizeof *d->obj);
        d->nobj = o->nafter;
        d->ndrawn = o->ndrawn_after;
        /* the whole drawing as it was: there is no saying where a picked
           element went, so the command lets go of what it had */
        jw_cmd_escape();
    }
    nop++;
    step = 0;
    tracking = 0;
}

/* The prompt with the original's own readout on the end of it.  What the
   readout says, and when, is in the note by tail_set. */
const char *jw_cmd_status(const jw_drawing *d)
{
    static char buf[256];

    if (current == JW_CMD_HIKAGE && hk_pv) {
        snprintf(buf, sizeof buf, "%s         %.3f(\xdf)  %.3f(\xdf)", HK_PV_PROMPT, hk_pv_az, hk_pv_el);
        return buf;
    }
    const char *p = jw_cmd_prompt();
    char a[64], b[64];
    int kind = tail_kind;
    double va = tail_a, vb = tail_b;

    if (step == 2 && !tracking) {
        /* the first point is down and the mouse has not moved into the
           view yet: the original reads out zero */
        kind = current == JW_CMD_SEN ? 1
             : current == JW_CMD_KUKEI ? 2
             : current == JW_CMD_ENKO ? 3 : kind;
        if (kind == 1 || kind == 2 || kind == 3)
            va = vb = 0.0;
    }
    /* 複線の「間隔を入力するか、複写する位置…」(5312) には、選んだ線から
       マウスまでの距離が実寸で付く（FUN_00658890 の 0x14c0 の分岐: 空白二つの
       あとに FUN_006608e0 の距離 × 書込みグループの縮尺を 三桁区切り・小数 3 桁）。
       距離は線なら直線までの垂線、円なら半径の差。逆コンパイルの読みで、原典の
       実測（18,428.571 など）は形が合うことだけ確かめてある */
    if (current == JW_CMD_FUKUSEN && !strcmp(p, JW_STR_5312) && tracking && d
        && para_obj >= 0 && para_obj < d->ndrawn) {
        const jw_obj *o = &d->obj[para_obj];
        double dist = -1.0;

        if (o->cls == JW_ENKO)
            dist = fabs(sqrt((tx - o->d[0]) * (tx - o->d[0])
                             + (ty - o->d[1]) * (ty - o->d[1])) - o->d[2]);
        else if (o->cls == JW_SEN) {
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = sqrt(dx * dx + dy * dy);

            if (len > 1e-9)
                dist = fabs(((tx - o->d[0]) * -dy + (ty - o->d[1]) * dx) / len);
        }
        if (dist >= 0.0) {
            num3(a, (int)sizeof a, d, dist);
            snprintf(buf, sizeof buf, "%s  %s", p, a);
            return buf;
        }
    }
    /* 接円: 一つ目・二つ目を訊く間（0x14fc・0x14fd）、半径が箱にあれば
       「    [ r = %.3lf ]」が付く（CZukeiSetuEn。箱の値の絶対値を紙の mm に
       して 1e-7 を超えるとき、実寸で。三桁区切りはない） */
    if (current == JW_CMD_SEKIEN && (sek_step == 0 || sek_step == 1) && d) {
        const char *t = jw_cmd_box(1411);
        double r = t ? fabs(atof(t)) : 0.0;

        if (r / write_scale(d) > 1e-7) {
            snprintf(buf, sizeof buf, "%s    [ r = %.3f ]", p, r);
            return buf;
        }
    }
    switch (kind) {
    case 1:
        num3(b, (int)sizeof b, d, vb);
        snprintf(buf, sizeof buf, "%s   [ %.3f\x81\x8b]   %s", p, va, b);
        return buf;
    case 2:
        num3(a, (int)sizeof a, d, va);
        num3(b, (int)sizeof b, d, vb);
        snprintf(buf, sizeof buf, "%s     W=%s    H=%s", p, a, b);
        return buf;
    case 3:
        num3(a, (int)sizeof a, d, va);
        snprintf(buf, sizeof buf, "%s      r = %s", p, a);
        return buf;
    case 4: {
        /* 測定: the scale, the running total to 小数桁 places and the leg
           or triangle just added (src/cmd.c's 測定 note) */
        double sc = 1.0, f;
        const char *u;
        int g, wg = 0;

        /* while ○単独円指定 waits for its circle the original shows the
           question alone, with no readout at all */
        if (sok_one)
            return p;

        for (g = 0; d && g < 16; g++)
            if (d->group[g].state == 3)
                wg = g;
        if (d && d->group[wg].scale > 0.0)
            sc = d->group[wg].scale;
        if (sok_mode == SOK_ANG) {
            /* while it waits for the 角度点 the readout follows the
               mouse: the angle from 原点→基準点 round to 原点→カーソル
               (tools/probe144.sh -- with the origin at (300,300) and the
               base at (700,300), the cursor at (700,500) read -26.565,
               at (300,500) -90.000, at (700,100) 26.565 and at (900,300)
               0.000) */
            if (sok_n == 2 && tracking) {
                va = (atan2(ty - sok_y0, tx - sok_x0)
                      - atan2(sok_py - sok_y0, sok_px - sok_x0))
                     * 180.0 / PI;
                while (va > 180.0)
                    va -= 360.0;
                while (va <= -180.0)
                    va += 360.0;
            }
            if (sok_dms) {
                /* FUN_0071fe20: the 度分秒 string takes the number's
                   place, unit and all */
                sok_dms_str(a, (int)sizeof a, va);
                snprintf(buf, sizeof buf, "%s       \x81y %s \x81z", p, a);
            } else {
                sok_num(a, (int)sizeof a, va, sok_places());
                snprintf(buf, sizeof buf, "%s       \x81y %s\x81\x8b \x81z", p, a);
            }
            return buf;
        }
        if (sok_mode == SOK_XY) {
            /* the cursor's place, measured from the origin */
            double dx = 0.0, dy = 0.0;

            if (sok_n && tracking) {
                dx = tx - sok_x0;
                dy = ty - sok_y0;
            }
            f = sc / (sok_unit ? 1.0 : 1000.0);
            u = sok_unit ? "mm" : "\x82\x8d";
            sok_num(a, (int)sizeof a, dx * f, sok_places());
            sok_num(b, (int)sizeof b, dy * f, sok_places());
            snprintf(buf, sizeof buf,
                     "%s      S = 1 / %g  \x81y %s%s , %s%s \x81z",
                     p, sc, a, u, b, u);
            return buf;
        }
        if (sok_mode == SOK_AREA) {
            f = sc * sc / (sok_unit ? 1.0 : 1000000.0);
            u = sok_unit ? "mm2" : "\x82\x8d" "2";
        } else {
            f = sc / (sok_unit ? 1.0 : 1000.0);
            u = sok_unit ? "mm" : "\x82\x8d";
        }
        sok_num(a, (int)sizeof a, va * f, sok_places());
        snprintf(b, sizeof b, "%g", vb * f);
        snprintf(buf, sizeof buf,
                 "%s      S = 1 / %g  \x81y %s%s \x81z   %s%s",
                 p, sc, a, u, b, u);
        return buf;
    }
    }
    return p;
}

/* The two prompts of a range: 5326 and its tail while the second corner is
   asked for, and 5325 (+ what Enter does) once the box is made -- the stage
   where more clicks add or take away (probed on the original; copy and move
   end it with Enter-範囲確定 and ShiftEnter-基点変更, データ整理 with the
   first only, 範囲選択 and 図形登録 with neither). */
static const char *sel_prompt_corner(void)
{
    static char b[300];

    snprintf(b, sizeof b, "%s �@%s", JW_STR_5326, JW_STR_5762);
    return b;
}

static const char *sel_prompt_add(void)
{
    static char b[400];

    snprintf(b, sizeof b, "%s%s%s", JW_STR_5325,
             current == JW_CMD_FUKUSHA || current == JW_CMD_IDOU
             || current == JW_CMD_SEIRI ? JW_STR_5828 : "",
             current == JW_CMD_FUKUSHA || current == JW_CMD_IDOU
             ? JW_STR_5829 : "");
    return b;
}

const char *jw_cmd_prompt(void)
{
    if (current == JW_CMD_HIKAGE && hk_pv)
        return HK_PV_PROMPT;
    if (current == 0x8091)
        return gb_prompt();
    /* a 取得 takes the status line over while it is on */
    if (get_mode) {
        /* What each of them puts there, read off the running original
           (tools/probe27.sh).  X軸角度 shows ●角度点 for both of
           its two clicks; ２点間角度 leads with its own line and
           then shows the same one. */
        if (get_mode == 32940)
            return get_step ? JW_STR_10119 : JW_STR_5345;
        if (get_mode == 32933)
            return JW_STR_10118;
        if (get_mode == 32934)
            return get_step ? JW_STR_10118 : JW_STR_10117;
        /* 数値角度・数値長 ask for a number written in the drawing
           instead of a line (tools/probe120.sh) */
        if (get_mode == 32938 || get_mode == 32941)
            return JW_STR_10043;
        if (get_mode == 32912)          /* 目盛基準点 */
            return JW_STR_5314;
        if (get_mode == 32936)          /* レイヤ非表示化 */
            return JW_STR_5264;
        /* 軸角 leads with its own word and then asks for the line the
           way the others do (tools/probe120.sh) */
        if (get_mode == 32962) {
            static char jik[96];

            if (!jik[0]) {
                strncpy(jik, JW_STR_10020, sizeof jik - 1);
                strncat(jik, "  ", sizeof jik - strlen(jik) - 1);
                strncat(jik, JW_STR_5345, sizeof jik - strlen(jik) - 1);
            }
            return jik;
        }
        return JW_STR_5345;
    }
    switch (current) {
    case JW_CMD_SOKUTEI:
        /* 角度測定 walks 原点 → 基準点 → 角度点; the others ask for a
           始点 and then 次の点 over and over */
        if (sok_mode == SOK_ANG)
            return sok_n == 0 ? JW_STR_5404
                 : sok_n == 1 ? JW_STR_10117 : JW_STR_10118;
        if (sok_write)
            return JW_STR_5318;
        if (sok_one)
            return JW_STR_5367;
        if (sok_mode == SOK_XY)
            return sok_n == 0 ? JW_STR_5404 : JW_STR_5405;
        return sok_n && !sok_esc ? JW_STR_5323 : JW_STR_5320;
    case JW_CMD_KYORITEN:
        return kyo_step ? JW_STR_5462 : JW_STR_5320;
    case JW_CMD_25D:
        return JW_STR_5519;
    case JW_CMD_HIKAGE:
    case JW_CMD_TENKU:
        if (current == JW_CMD_TENKU && tn_mode)
            return tn_mode == 1 ? JW_STR_5712 : JW_STR_5713;
        if (current == JW_CMD_HIKAGE && hk_iso_on && hk_iso_rng == 1)
            return "\x93\x99\x8e\x9e\x8a\xd4\x90}\x82\xcc\x8d\xec\x90}\x94\xcd\x88\xcd\x82\xcc\x8en\x93_\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4\x82\xad\x82\xbe\x82\xb3\x82\xa2\x81" "B  (L)free  (R)Read";
        if (current == JW_CMD_HIKAGE && hk_iso_on && hk_iso_rng == 2)
            return "\x81\x9f\x81@\x81@\x8fI\x93_\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4\x82\xad\x82\xbe\x82\xb3\x82\xa2  (L)free  (R)Read";
        if (hk_write_cond)
            return JW_STR_5582;
        if (hk_pts && hk_calc_step)
            return JW_STR_5560;
        if (hk_pts) {
            static char pn[160];

            snprintf(pn, sizeof pn, "%s    (No.%d)", JW_STR_5541, hk_first_no + hkp_n);
            return pn;
        }
        if (hk_sub && hk_tbl_pending) {
            static char pt[200];

            snprintf(pt, sizeof pt, "%s     (Shift+L,R)\x81\x46\x82\x50\x8e\x9e\x8a\xd4\x96\x88", JW_STR_5560);
            return pt;
        }
        return hk_sub ? JW_STR_5403 : hk_north ? JW_STR_5525 : JW_STR_5524;
    case JW_CMD_AUTO:
        /* 何も持っていなければ AUTO の案内、線を押したら 線編集の案内、線を引き始めたら 線の問い */
        if (au_st == 1)
            return JW_STR_5435;
        if (au_st == 2)
            return JW_STR_5435;
        return step == 0 ? JW_STR_5434 : JW_STR_5321;
    case JW_CMD_SEN:
    case JW_CMD_KUKEI:
    case JW_CMD_RENZOKU:
        /* CZukeiRenzokuSen shows the same two: 0x14c8 while its own step is
           0 or 1, 0x14c9 once it is 3.  (Its step 2 asks for an arc's middle
           point, which belongs to the 連続円弧 half of the command.)
           矩形 shows the same pair -- the running original answers
           「始点を指示してください」 and then 「◆　　終点を指示して
           ください  (L)free  (R)Read     W=0.000    H=0.000」, which is
           this string with the size added to it live. */
        return step == 0 ? JW_STR_5320 : JW_STR_5321;
    case JW_CMD_TEN:
        /* 原典の言葉。仮点消去 と 交点 はそれぞれ自前の行を出します
           （tools/probe150.sh・probe151.sh で読んだもの）。 */
        if (ten_del)
            return JW_STR_5503;
        if (ten_cross)
            return ten_cross == 1 ? JW_STR_5623 : JW_STR_5624;
        return JW_STR_5376;
    case JW_CMD_MOJI:
        if (ren_step)
            return ren_step == 1 ? JW_STR_5473
                   : ren_step == 3 ? JW_STR_5311 : JW_STR_5474;
        if (txt_n > 0)          /* 文読 has lines waiting for a 基準点 (5395, B 3.7) */
            return u8cp("《文字読込》の基準点を指示してください  (L)free  (R)Read");
        /* 「文字を入力するか…」 until something is typed, then
           「文字の位置を指示して下さい」 */
        return line_n ? JW_STR_5318 : JW_STR_5316;
    case JW_CMD_ZOKUSEI:
        return JW_STR_5263;
    case JW_CMD_HOURAKU:
        /* 「包絡範囲の始点指示を指示して下さい」 and then 「…終点を指示して
           下さい　(L)包絡処理　(R)範囲内消去」.  The running original adds
           「(Shift+L) (Ｌ←)中間消去」 to the second, which the string table
           does not carry. */
        return hou_step == 0 ? JW_STR_5327 : JW_STR_5328;
    case JW_CMD_FUKUSEN:
        /* 「複線にする図形を選択してください ﾏｳｽ(L)　前回値 ﾏｳｽ(R)」 then
           「複線方向を指示 ﾏｳｽ(L)…」 */
        /* the original's three: the line, then (with no interval typed) the
           interval or where to put it, then the side */
        if (fk_ten == 3 || fk_ten == 2) {
            /* 端点指定: FUN_00658890 は 5320／5321 を "  %s" にして 5506 の後ろに付ける */
            static char tp[200];

            snprintf(tp, sizeof tp, "%s  %s", u8cp("【端点指定】"),
                     fk_ten == 3 ? JW_STR_5320 : JW_STR_5321);
            return tp;
        }
        if (para_step == 0)
            return JW_STR_5305;
        if (para_step == 1 && box_num(jw_cmd_box(1411), 0.0) <= 0.0
            && !have_kan && fk_rprev <= 0.0)
            return JW_STR_5312;
        {
            static char fp[200];

            snprintf(fp, sizeof fp, "%s%s", JW_STR_5310, JW_STR_5708);
            return fp;
        }
    case JW_CMD_SHINSHUKU:
        /* FUN_00717df0: 0x14db while the right is down once (+0x210 == 6),
           else 0x14d8 in state 0, 0x14da once a line is picked (1, 2) and
           0x14d9 while a 基準線 is held (3, 4) */
        if (stretch_rwait)
            return JW_STR_5339;
        if (stretch_step != 0)
            return JW_STR_5338;
        return stretch_based ? JW_STR_5337 : JW_STR_5336;
    case JW_CMD_BUNKATSU:
        /* 分割 is not コーナー: it has its own pair.  CZukeiBunkatsu's
           FUN_007614c0 puts up 0x14ed while its state is 0 or 1 -- 「線・円
           （Ａ）指示　ﾏｳｽ(L)　分割始点指示　ﾏｳｽ(R)　連続点分割 (RR)」 --
           and once one is picked (state 2) it asks for the second: 0x14ee
           「□　線【B】指示…」 when what was picked is a CDataSen, 0x14ef
           「○　円【B】指示…」 when it is a CDataEnko, and 0x14f1 when what
           was picked instead is a point (corner_obj<0, 分割始点指示 の(R)).
           State 3 (two points, corner_step==2) shows 0x14f0 ── ２点間分割.
           連続点分割の途中（+0x4e = +0x138 が 0 でない）は FUN_007614c0 の
           else 枝: 1 点なら 0x16bb (5819)、2 点以上なら 0x16bc (5820)。
           原典は点を足した (L)(R) のあとの再描画で案内を出し直すので、
           (R)(R) で入った直後だけは次にマウスが動くまで 5361 のまま見える
           （tools/bkprobe.sh の読み出し）── ここはマウスが動いた後の姿。 */
        if (corner_step == 0 && bk_rr_n > 0)
            return bk_rr_n < 2 ? JW_STR_5819 : JW_STR_5820;
        if (corner_step == 0)
            return JW_STR_5357;
        if (corner_step == 2)
            return JW_STR_5360;
        if (corner_obj < 0)
            return JW_STR_5361;
        return bk_a_enko ? JW_STR_5359 : JW_STR_5358;
    case JW_CMD_SESSEN:
        /* CZukeiSessen shows 0x14f7 「円を指示してください。」 while its
           state is 0 or 1 and 0x14f8 「●　　次の円を指示してください。」
           once it is 2.  (Its states 3 and 5 are the 点→円 and 線→円
           halves, which show 0x14fa, 0x14fb and the line command's own
           pair; those are not written down here because the port's modes
           do not line up with them one to one.) */
        if (ses_mode == 1689)
            return ses_step == 0 ? JW_STR_5367 : JW_STR_5368;
        return JW_STR_5320;
    case JW_CMD_SEKIEN:
        /* CZukeiSetuEn asks for three in turn -- 0x14fc, 0x14fd, 0x14fe --
           and once a radius settles the circle it asks where to put it
           instead, 0x14ff.  (It hangs 「    [ r = %.3lf ]」 off the first
           two while a radius is in the box; jw_cmd_status adds it.) */
        if (sek_step == 0)
            return JW_STR_5372;
        if (sek_step == 1)
            return JW_STR_5373;
        return box_num(jw_cmd_box(1411), 0.0) > 0.0
               ? JW_STR_5375 : JW_STR_5374;
    case JW_CMD_CHUSHIN:
        /* CZukeiChuushinSen's state runs 1,2,3,4 and shows 0x14fc, 0x14fd,
           then the line command's own pair -- the two elements first, then
           the two ends of the centre line between them.  The original hangs
           string 0x150a off the last two; that tail is not added here. */
        if (chu_step == 0)
            return JW_STR_5372;
        if (chu_step == 1)
            return JW_STR_5373;
        return chu_step == 2 ? JW_STR_5320 : JW_STR_5321;
    case JW_CMD_KYOKUSEN:
        /* CZukeiKyokuSen keeps a kind in [0xa8] and a step in [0xac].
         *
         *   サイン曲線 (0x15)  1 基準線 0x14e1、2 原点 0x151c、
         *                      3 振幅の幅 0x1529、4 １サイクル点 0x152a、
         *                      5 始点 0x14c8、6 終点 0x14c9
         *   ２次曲線 (0x16)    1 基準線、2 原点、3 中間点 0x1528、
         *                      5 始点、6 終点（4 は飛ばす）
         *
         * which is exactly the five and four points the port's 1689 and
         * 1690 take after the line they run along.  スプライン・ベジェ
         * （原典の「それ以外」）は 0x14c8 のあと中間点 0x1528 で、原典は
         * 三つめの状態で 0x14c9 を出しますが、その状態にいつ入るかは
         * 読み切れていないので、ここは点が一つも無いあいだ始点、あとは
         * 中間点にしてあります。 */
        if (cv_mode == 1689 || cv_mode == 1690) {
            if (!cv_base)
                return JW_STR_5345;
            if (cv_n == 0)
                return JW_STR_5404;
            if (cv_mode == 1689)
                return cv_n == 1 ? JW_STR_5417
                     : cv_n == 2 ? JW_STR_5418
                     : cv_n == 3 ? JW_STR_5320 : JW_STR_5321;
            return cv_n == 1 ? JW_STR_5416
                 : cv_n == 2 ? JW_STR_5320 : JW_STR_5321;
        }
        return cv_n == 0 ? JW_STR_5320 : JW_STR_5416;
    case JW_CMD_NISEN:
        /* CZukei2Sen's FUN_006236b0.  Ghidra dropped the arguments of all
           seven of its FUN_004efbb0 calls, so they were read off the
           machine code instead (objdump of orig/Jw_win.exe, 0x623a75 to
           0x6240be): state 1 pushes 0x14e1 「基準線を指示してください。」,
           state 2 0x1519 「始点を指示してください … 基準線変更(LL)
           指示線包絡(RR)」 and state 3 0x151a, the same for the end.
           (0x1517 and 0x1518 are the 包絡 hovers of its states 4 to 7.) */
        if (nisen_step == 0)
            return JW_STR_5345;
        return nisen_step == 1 ? JW_STR_5401 : JW_STR_5402;
    case JW_CMD_ZOKUHEN:
        /* CZukeiHenkou's FUN_0067ad40 is four lines long: while nothing is
           picked it puts up 0x156f 「変更するデータを指示してください。
           線・円・実点(L)　文字(R)」, and that is the whole of it -- the
           command takes one click and is done, which is what the port does
           too. */
        return JW_STR_5487;
    case JW_CMD_HATCH:
        /* CZukeiHachi's FUN_00672100 branches three ways.  While it is
           waiting for the 基準点 it puts up 0x14c2 (the same line the
           copies and moves use); while a range is being dragged it hands
           over to the range handler; otherwise it asks for the ring, and
           that is 0x1501 「始めの線・弧をﾏｳｽ(L)で、閉鎖連続線・円を
           ﾏｳｽ(R)で指示してください。」 until one is in and 0x1502
           「　■ 次の線・円をﾏｳｽ(L)で指示してください。」 after.  (It hangs
           the count of what is in the ring off both; that tail is not added
           here.) */
        if (ht_base_wait)
            return JW_STR_5314;
        if (ht_sel)
            return ht_sel == 2 ? sel_prompt_corner() : JW_STR_5383;
        return ht_nchain == 0 ? JW_STR_5377 : JW_STR_5378;
    case JW_CMD_ZUKEI:
        /* CZukeiTourokuZukei asks FUN_00572c70 whether there is a figure to
           place: no, and it puts up 0x14ea 「【図形】データがありません。
           再選沢してください。」; yes, and it puts up 0x14e9 「【図形】の
           複写位置を指示してください  (L)free  (R)Read」.  (Its third
           branch, 0x2786, is the one the 倍率・回転 variant shows.) */
        return jw_cmd_figure_ready() ? JW_STR_5353 : JW_STR_5354;
    case JW_CMD_MENTORI:
    case JW_CMD_CORNER:
        /* 「線（Ａ）指示(L)　線切断(R)」 then 「◆　線【Ｂ】指示(L)…」
           -- FUN_00635ae0 puts up 0x14dc while its state is 0 and 0x14dd
           while it is 1 or 2. */
        return corner_step == 0 ? JW_STR_5340 : JW_STR_5341;
    case JW_CMD_SHOUKYO:
        if (shk_sel)            /* 範囲選択消去: 範囲選択と同じ問いかけ */
            return shk_sel == 2 ? sel_prompt_corner()
                 : shk_sel == 3 ? sel_prompt_add() : JW_STR_5383;
        /* 10111 is CZukeiShoukyo's own line, and where the two buttons' jobs
           are written down: (L) takes a piece out of a line or circle, (R)
           deletes the whole element.  Once a line has been picked it asks
           for the two ends of the piece instead (FUN_0070dc20: 0x2780 and
           0x2781 for a line, 0x2782 and 0x2783 for a circle). */
        if (cut_step == 1)
            return JW_STR_10112;
        if (cut_step == 2)
            return JW_STR_10113;
        return JW_STR_10111;
    case JW_CMD_HANI:
    case JW_CMD_FUKUSHA:
    case JW_CMD_IDOU:
    case JW_CMD_SEIRI:
    case JW_CMD_ZUKEIREG:
    case JW_CMD_PARAM:
        if (sel_step == 3 && current == JW_CMD_PARAM)
            return param_prompt();
        /* 5383 while the box has no first corner, 5326 while it is being
           dragged, then 5314 基準点 and 5307/5311 for where it goes. */
        if (ms_back && current == JW_CMD_HANI && sel_step <= 1) {
            /* the 文字 command's own range (5429 and 5430, B 3.1) */
            if (sel_step == 0)
                return u8cp("【文字】　範囲選択の始点をﾏｳｽで指示してください。");
            return u8cp("［文字］　　　　選択範囲の終点を指示して下さい。");
        }
        if (sel_step == 1)
            return sel_prompt_corner();
        /* 整理 places nothing, so 「複写先の点」 was never its line.
           CZukeiSeiri's FUN_006e62c0 asks FUN_0044fcd0 whether the
           selection is empty: if not it puts up 0x152c 「実行項目を指示
           してください。（実行中マウスクリックで中断）」 -- which is where
           the port's 整理 stands once the selection is settled. */
        if (sel_step == 3 && current == JW_CMD_SEIRI)
            return JW_STR_5420;
        /* 図形登録: after 選択確定 the next point is the 基準点 */
        if (sel_step == 3 && current == JW_CMD_ZUKEIREG)
            return JW_STR_5314;
        if (sel_step == 3)
            return current != JW_CMD_SEIRI && range_moves()
                   ? JW_STR_5311 : JW_STR_5307;
        if (sel_step == 2)
            return sel_prompt_add();
        return JW_STR_5383;
    case JW_CMD_KIGOU: {
        const jw_senkigou *sg = sk_cat >= 0 ? jw_sk_load(sk_cat) : 0;
        const jw_sk_item *it = sg && sk_item >= 0 && sk_item < sg->nitem
                               ? &sg->item[sk_item] : 0;

        if (!it)
            return JW_STR_5490;
        if (sk_step == 4)
            return JW_STR_5365;
        if (sk_step == 3)
            return JW_STR_5364;
        if (sk_step == 2 || !it->need_l1)
            return JW_STR_5364;
        return sk_step == 1 ? JW_STR_5363 : JW_STR_5362;
    }
    case JW_CMD_TATEGU:
    case JW_CMD_TATEGU_DAN:
    case JW_CMD_TATEGU_RITSU:
        /* 選ぶまでは「建具を選択してください。」、選んだら基準線、壁を
           指したら位置。(R) で二点を読むあいだは 線の「終点」の問い */
        if (tg_cat < 0)
            return JW_STR_5347;
        if (current == JW_CMD_TATEGU_RITSU)     /* 立面は位置だけ */
            return JW_STR_5346;
        if (tg_step == 1)
            return JW_STR_5346;
        if (tg_step == 2)
            return JW_STR_5321;
        return JW_STR_5478;
    case JW_CMD_TAKAKU: {
        /* CZukeiTakakukei slot 6 (FUN_00646... のプロンプト): 段 (+0xa8) と
         * ラジオの並び (+0xb4: 0 が２辺)・寸法の箱が埋まっているか (+0xac)・
         * 基点 (+0xf8) で選びます。
         *   ２辺               始点 → 終点 → 作図する方向
         *   箱あり             中心点（基点が中央でなければ「位置をマウスで」）
         *   箱なし 1690・1691  中心点 → 位置をマウスで
         *   箱なし 辺寸法      始点 → 位置をマウスで */
        const char *bx = tk_mode == 1689 ? 0 : jw_cmd_box(1411);
        int filled = bx && box_num(bx, 0.0) > 0.0;

        if (tk_any && tk_pickmode)
            return JW_STR_5650;
        if (tk_any)
            return tk_an == 0 ? JW_STR_5320 : JW_STR_5321;
        if (tk_mode == 1689)
            return tk2_n == 0 ? JW_STR_5320 : tk2_n == 1 ? JW_STR_5321
                                                         : JW_STR_5310;
        if (filled)
            return tk_pos == 0 ? JW_STR_5309 : JW_STR_5364;
        if (tk_step == 0)
            return tk_mode == 1692 ? JW_STR_5320 : JW_STR_5309;
        return JW_STR_5364;
    }
    case JW_CMD_SUNPO: {
        /* 円周 and 角度 hang their own name off the end of the prompt from
           the point where the two measured points are asked for, with
           「（左回り）」 in front of it -- 6159 then 6158 or 6157 */
        static char tail[128];
        const char *p;

        if (ika_step)
            return ika_step == 1 ? JW_STR_5391
                 : ika_step == 2 ? JW_STR_5392 : JW_STR_5393;
        if (sun_chi)
            return sun_step == 6 ? JW_STR_5332
                 : sun_chi_done ? JW_STR_5333 : JW_STR_5576;
        if (sun_step == 7) {
            snprintf(tail, sizeof tail, "%s%s", JW_STR_5367, JW_STR_6158);
            return tail;
        }
        if (sun_step == 0)
            return JW_STR_5329;
        if (sun_step == 1)
            return JW_STR_5330;
        /* one dimension in, the next one's start (L) or a 連続入力 end (R) */
        if (sun_made && sun_step == 2 && !sun_enshu && !sun_kaku)
            return JW_STR_5333;
        p = sun_step == 2 ? JW_STR_5331 : JW_STR_5332;
        if (!sun_enshu && !sun_kaku)
            return p;
        snprintf(tail, sizeof tail, "%s%s%s", p, JW_STR_6159,
                 sun_enshu ? JW_STR_6158 : JW_STR_6157);
        return tail;
    }
    case JW_CMD_GAZOU:
        return jw_cmd_gazou_prompt();
    case JW_CMD_ENKO:
        /* CZukeiEnko asks for the centre first and then a point the circle
           goes through.  It leads with 円位置 instead only when a radius has
           been typed into its command bar, which there is nowhere to do
           yet. */
        if (jw_cmd_bar_check(1318) > 0 && jw_cmd_bar_check(1321) <= 0)
            return en_step == 0 ? JW_STR_5309
                 : en_step == 1 ? JW_STR_5304 : JW_STR_5321;
        return step == 0 ? JW_STR_5309 : JW_STR_5301;
    }
    /* Every other command puts its own string there; which one is in that
       command's class and has not been read out of the binary yet, so rather
       than make one up the line keeps the one it starts with. */
    return JW_STR_5320;
}

void jw_cmd_track(double x, double y)
{
    tx = x;
    ty = y;
    tracking = 1;
}

static void blank(jw_obj *o)
{
    memset(o, 0, sizeof *o);
    o->text = o->face = -1;
    o->ltype = 1;
    o->color = 2;
}

/* The circle through three points.  Nought when they are in a line. */
static int three_circle(double x1, double y1, double x2, double y2,
                        double x3, double y3, double *cx, double *cy)
{
    double a = x1 * x1 + y1 * y1, b2 = x2 * x2 + y2 * y2;
    double c = x3 * x3 + y3 * y3;
    double dd = 2.0 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    if (fabs(dd) < 1e-12)
        return 0;
    *cx = (a * (y2 - y3) + b2 * (y3 - y1) + c * (y1 - y2)) / dd;
    *cy = (a * (x3 - x2) + b2 * (x1 - x3) + c * (x2 - x1)) / dd;
    return 1;
}

/* 0 .. 2pi */
static double turn_pos(double a)
{
    while (a < 0.0)
        a += 2.0 * PI;
    while (a >= 2.0 * PI)
        a -= 2.0 * PI;
    return a;
}

/* 控えてある弧を図面へ入れる */
static void ra_commit(jw_drawing *d)
{
    if (ra_have_pend && d) {
        jw_obj *o = jw_add(d, JW_ENKO);

        if (o) {
            o->d[0] = ra_pend[0];
            o->d[1] = ra_pend[1];
            o->d[2] = ra_pend[2];
            o->d[3] = ra_pend[3];
            o->d[4] = ra_pend[4];
            o->d[5] = 0.0;
            o->d[6] = 1.0;
            o->n = 0;
            op_push(1);
        }
    }
    ra_have_pend = 0;
}

/* One arc of a 連続弧 chain, and the way out of its centre through its
   far end, which the next one leaves along. */
static int ren_arc_add(jw_drawing *d, double cx, double cy,
                       double sx2, double sy2, double ex, double ey,
                       int ccw)
{
    double r = sqrt((sx2 - cx) * (sx2 - cx) + (sy2 - cy) * (sy2 - cy));
    double a0 = atan2(sy2 - cy, sx2 - cx);
    double a1 = atan2(ey - cy, ex - cx);
    double sw = turn_pos(a1 - a0);

    if (r < 1e-9)
        return 0;
    if (!ccw)
        sw -= 2.0 * PI;
    (void)d;
    /* 連続線と同じく、**ひとつ手前の弧だけ画面にあって、次のクリックで
       図面に入ります**（`tools/probe163.sh`: 三点では何も入らず、四点目で
       一つ目の弧が入る）。ここでは控えておくだけです。 */
    ra_pend[0] = cx;
    ra_pend[1] = cy;
    ra_pend[2] = r;
    ra_pend[3] = a0;
    ra_pend[4] = sw;
    ra_have_pend = 1;
    ra_ux = (ex - cx) / r;
    ra_uy = (ey - cy) / r;
    ra_dx = ccw ? -ra_uy : ra_uy;
    ra_dy = ccw ? ra_ux : -ra_ux;
    return 1;
}

static void sunpo_text(char *out, int n, double mm, double scale);

/* 線 の 寸法値 (1350): the line is written as a dimension and its length
 * goes beside it.
 *
 * Read off the original: the line itself picks up the dimension flag, and a
 * text of its length in real units is laid along it -- centred on its
 * middle, half a millimetre off to the left, in the 寸法 text style, with
 * the width word left at 0 (unlike the 寸法 command's own value, which
 * carries the places there).  A line 193.618714 long on a 1/200 group came
 * out as 38,723.74.
 *
 * Answers 1 when there is nothing to add, 2 when the text went with it. */
static int sen_text(const jw_drawing *d, const jw_obj *o, jw_obj *t);

static int sen_value(const jw_drawing *d, jw_obj *o, int max)
{
    if (jw_cmd_bar_check(1350) <= 0 || !d || max < 2)
        return 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    return sen_text(d, o, &o[1]) ? 2 : 1;
}

/* 建具平面の寸法図形（&m）が使う: 線 `o` の長さの値を、`t` に */
int jw_cmd_dim_value(const jw_drawing *d, const jw_obj *o, jw_obj *t)
{
    return sen_text(d, o, t);
}

static int sen_text(const jw_drawing *d, const jw_obj *o, jw_obj *t)
{
    double dx, dy, len, ux, uy, vx, vy, cw, ch, sp, tw = 0.0;
    char txt[64];
    const char *p;
    int i, wg = 0, nch = 0;

    dx = o->d[2] - o->d[0];
    dy = o->d[3] - o->d[1];
    len = sqrt(dx * dx + dy * dy);
    if (len <= 0.0)
        return 0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    i = sun_mojino - 1;
    if (i < 0 || i >= 10)
        i = 0;
    cw = d->style[i].w;
    ch = d->style[i].h;
    sp = d->style[i].sp;
    sunpo_text(txt, (int)sizeof txt, len, d->group[wg].scale);
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    if (cw <= 0.0 || ch <= 0.0 || !nch)
        return 0;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    blank(t);
    t->cls = JW_MOJI;
    t->color = (unsigned short)d->style[i].color;
    t->ltype = 2;
    t->width = 0;
    t->flags = (unsigned short)(t->flags | JW_SUN_TEXT_FLAGS);
    {
        double mx = (o->d[0] + o->d[2]) / 2.0 + sun_hanare * vx;
        double my = (o->d[1] + o->d[3]) / 2.0 + sun_hanare * vy;
        t->d[0] = mx - tw / 2.0 * ux;
        t->d[1] = my - tw / 2.0 * uy;
        t->d[2] = mx + tw / 2.0 * ux;
        t->d[3] = my + tw / 2.0 * uy;
    }
    t->d[4] = cw;
    t->d[5] = ch;
    t->d[6] = sp;
    t->d[7] = 0.0;
    t->n = sun_mojino;
    t->text = jw_add_str((jw_drawing *)d, txt);
    t->face = jw_add_str((jw_drawing *)d, JW_MOJI_FACE);
    return 1;
}

/* 線の ●─── (1348) と ＜─── (1349): a mark on the end of the line.
 *
 * The original was asked and drew, at the point clicked first, either one
 * 点 (●) or two lines 3 long at plus and minus 15 degrees off the way the
 * line runs (＜), the plus one first -- the same length and angle the
 * dimension arrowheads use.  Drawn backwards, the mark stayed on the point
 * clicked first, so it is the start and not an end of the segment.
 *
 * The button beside each box says which end.  Pressing it once moved the
 * mark to the far end, twice put one on both ends, three times brought it
 * back to the start, so it runs round three states.  The mark at the far end
 * is the same shape turned about: the legs go back along the line, which is
 * the arrowhead's own rule of pointing from the tip towards the other end.
 *
 * The ● came out with pen 1 and line type 1 while the line it sits on came
 * out pen 2, so the mark is not drawn with the writing pen.  Pen 1 is also
 * what the dimension settings give a 端部 point, and the two cannot be told
 * apart here.
 *
 * The four boxes on that side of the bar turn each other off in the original
 * (FUN_005be280 and the three beside it), so at most one is ever on. */
static unsigned char mark_side[2];      /* 0 start, 1 far end, 2 both */

static int sen_marks(const jw_drawing *d, jw_obj *o, int max, int n)
{
    double dx, dy, len, ux, uy;
    int dot = jw_cmd_bar_check(1348) > 0;
    int arr = jw_cmd_bar_check(1349) > 0;
    int side, e;

    (void)d;
    if ((!dot && !arr) || n < 1)
        return n;
    dx = o[0].d[2] - o[0].d[0];
    dy = o[0].d[3] - o[0].d[1];
    len = sqrt(dx * dx + dy * dy);
    if (len <= 0.0)
        return n;
    ux = dx / len;
    uy = dy / len;
    side = mark_side[dot ? 0 : 1];
    for (e = 0; e < 2; e++) {
        /* e = 0 is the point clicked first, e = 1 the other one */
        double px = e ? o[0].d[2] : o[0].d[0];
        double py = e ? o[0].d[3] : o[0].d[1];
        double wx = e ? -ux : ux, wy = e ? -uy : uy;
        double k;

        if (side != 2 && side != e)
            continue;
        if (dot) {
            if (n >= max)
                break;
            blank(&o[n]);
            o[n].cls = JW_TEN;
            o[n].ltype = 1;
            o[n].color = 1;
            o[n].d[0] = px;
            o[n].d[1] = py;
            o[n].n = 0;
            n++;
            continue;
        }
        for (k = 1.0; k >= -1.0; k -= 2.0) {
            double a = k * sun_yaang * PI / 180.0;
            double ca = cos(a), sa = sin(a);
            if (n >= max)
                break;
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].ltype = o[0].ltype;
            o[n].color = o[0].color;
            o[n].d[0] = px;
            o[n].d[1] = py;
            o[n].d[2] = px + sun_yalen * (wx * ca - wy * sa);
            o[n].d[3] = py + sun_yalen * (wx * sa + wy * ca);
            n++;
        }
    }
    return n;
}

/* What the point down and the point here make -- one element, or the four of
   a rectangle.  Working it out in one place keeps the provisional figure and
   what gets added identical. */
/* 扁平率 (1412) as the original reads it: over one it is a percentage,
   at or under one it is the ratio itself (tools/probe59.sh). */
static double en_ratio(const char *s)
{
    double v;

    if (!s || !*s)
        return 1.0;
    v = box_num(s, 1.0);
    if (v <= 0.0)
        return 1.0;
    return v > 1.0 ? v / 100.0 : v;
}

static int figure_(const jw_drawing *d, jw_obj *o, int max,
                   double x, double y)
{
    blank(o);
    switch (current) {
    case JW_CMD_SEN: {
        /* Where the line goes is settled in two halves: which way it points
         * and how far along that way it runs.  The original was asked with
         * every pair of the four knobs on and answered plainly.
         *
         * The direction, in the order they beat each other:
         *   １５度毎    the drag's own angle rounded to the nearest fifteen
         *   水平・垂直  along the axis or across it, whichever the drag
         *              went further (the axis being 軸角)
         *   傾き      the angle typed, however the drag runs
         * -- １５度毎 beats 水平・垂直 as well: ticked together, with the bar
         * as it comes up, the original drew the drag rounded to 30 degrees
         * and kept its length instead of going along the axis.
         * 傾き 30 with either of the other two on drew the line their way,
         * so the box is only read when neither is -- unless a 寸法 is typed
         * too, and then 傾き comes first: with 水平・垂直 ticked, 傾き 30
         * and 寸法 1000 the original drew 5 long at 30 degrees, not along
         * the axis, while the same 寸法 with an empty 傾き went up the axis.
         *
         * The run, signed along that direction:
         *   寸法 typed   that length, going the way the drag pointed --
         *                50000 on a 1/200 group with 水平・垂直 and a drag
         *                upwards drew 250 straight up
         *   otherwise   as far as the drag goes along it: its component on
         *               the axis for 水平・垂直, its whole length for １５度毎
         *               (the angle already carries the direction), and the
         *               drag projected onto 傾き for 傾き -- 173.178 across
         *               and 86.589 down at 30 degrees came out 106.68 long,
         *               which is exactly that dot product.
         */
        double len = naga_mm(d);
        double dx = x - sx, dy = y - sy;
        int kata = kata_set();
        double ux = 0.0, uy = 0.0, run = 0.0;
        int along = 1;

        if (len > 0.0 && kata) {
            double a = kata_rad();
            ux = cos(a);
            uy = sin(a);
            run = dx * ux + dy * uy;
        } else if (jw_cmd_bar_check(1336) > 0) {
            double l = sqrt(dx * dx + dy * dy);
            double step = PI / 12.0;
            double a = atan2(dy, dx) / step;
            a = (a < 0.0 ? -floor(-a + 0.5) : floor(a + 0.5)) * step;
            ux = cos(a);
            uy = sin(a);
            run = l;
        } else if (hv) {
            double a = axis_deg * PI / 180.0;
            double ca = cos(a), sa = sin(a);
            double u = dx * ca + dy * sa, v = -dx * sa + dy * ca;

            if (fabs(u) > fabs(v)) {
                ux = ca;
                uy = sa;
                run = u;
            } else {
                ux = -sa;
                uy = ca;
                run = v;
            }
        } else if (kata) {
            double a = kata_rad();
            ux = cos(a);
            uy = sin(a);
            run = dx * ux + dy * uy;
        } else if (len > 0.0) {
            /* 寸法 with nothing in 傾き keeps the way it was clicked and
               only sets how far it goes -- asked of the original with
               寸法 50 on a 1/100 sheet and a click up and to the right:
               the line came out along that way, 0.5 long, and clicking
               the other way gave the other way round
               (tools/probe23.sh).  This used to come out flat. */
            double l = sqrt(dx * dx + dy * dy);
            if (l <= 0.0) {
                along = 0;
            } else {
                ux = dx / l;
                uy = dy / l;
                run = l;
            }
        } else {
            along = 0;
        }
        if (along) {
            if (len > 0.0)
                run = run < 0.0 ? -len : len;
            x = sx + run * ux;
            y = sy + run * uy;
        }
        o->cls = JW_SEN;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = x;
        o->d[3] = y;
        return sen_marks(d, o, max, sen_value(d, o, max));
    }
    case JW_CMD_RENZOKU:
        o->cls = JW_SEN;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = x;
        o->d[3] = y;
        return 1;
    case JW_CMD_KUKEI: {
        /* 寸法 in the box makes the rectangle that size: the first click is
         * one corner and the second says which way it runs.  The original,
         * given 1000,1000 on a 1/200 group, drew 5 mm by 5 mm down and to
         * the right of the first click when the second was down-right, and
         * up and to the left when it was up-left. */
        double wmm = box_mm(d, 1413), hmm = box_mm2(d, 1413);
        if (wmm > 0.0 && hmm > 0.0) {
            x = sx + (x < sx ? -wmm : wmm);
            y = sy + (y < sy ? -hmm : hmm);
        }
        /* Four lines round the corners, in the order the original writes
         * them.  Drawn one in Jw_cad itself and read the file back: starting
         * at the corner clicked first it goes along x, then y, then back,
         * each line carrying on from where the last one ended.  There is no
         * rectangle in the file format -- only 線・円弧・点・文字・ソリッド --
         * so four lines is what it has to be. */
        if (jw_cmd_bar_check(1334) > 0) {
            /* ソリッド: one filled quadrilateral instead of four lines.
             * The original wrote its corners going the other way round --
             * the clicked corner, then down the same edge, across, and back
             * up (read off its own drawing). */
            blank(o);
            o->cls = JW_SOLID;
            o->d[0] = sx; o->d[1] = sy;
            o->d[2] = sx; o->d[3] = y;
            o->d[4] = x;  o->d[5] = y;
            o->d[6] = x;  o->d[7] = sy;
            if (jw_cmd_bar_check(1335) > 0) {
                /* (対角線): the original wrote the two clicked corners with
                 * the second repeated -- the quadrilateral collapses onto
                 * the diagonal. */
                o->d[2] = x; o->d[3] = y;
                o->d[4] = x; o->d[5] = y;
                o->d[6] = x; o->d[7] = y;
            }
            if (jw_cmd_bar_check(2553) > 0) {
                /* 任意色: colour 10 is Jw_cad's "any colour" pen and the
                 * trailing long is the colour.  原典は 2553 を押したとき
                 * `doc+0x5e18` に 10 を入れ（`FUN_005be3c0`）、色そのものは
                 * `doc+0x5e1c` に持ちます。既定は 0x808080 でした。 */
                o->color = 10;
                o->n = (int)solid_any;
            }
            return (sx != x && sy != y) ? 1 : 0;
        }
        static const int ix[4][4] = {
            {0, 1, 2, 1}, {2, 1, 2, 3}, {2, 3, 0, 3}, {0, 3, 0, 1}
        };
        double c[4];
        int k, j;
        if (max < 4)
            return 0;
        {   /* 傾き turns the whole thing: the two clicks are still opposite
             * corners, but of a rectangle whose sides run at that angle.
             * The original, given 30 and two clicks 173.178 apart across and
             * 86.589 down, drew sides of 106.68 at 30 degrees and 161.58 at
             * -60 -- which is the diagonal measured in the turned frame,
             * u = dx cos a + dy sin a and v = -dx sin a + dy cos a. */
            double a = box_angle(1411);
            if (a != 0.0) {
                double ca = cos(a), sa = sin(a);
                double dx = x - sx, dy = y - sy;
                double u = dx * ca + dy * sa, v = -dx * sa + dy * ca;
                double px[4], py[4];
                px[0] = sx;                py[0] = sy;
                px[1] = sx + u * ca;       py[1] = sy + u * sa;
                px[2] = px[1] - v * sa;    py[2] = py[1] + v * ca;
                px[3] = sx - v * sa;       py[3] = sy + v * ca;
                for (k = 0; k < 4; k++) {
                    blank(&o[k]);
                    o[k].cls = JW_SEN;
                    o[k].d[0] = px[k];
                    o[k].d[1] = py[k];
                    o[k].d[2] = px[(k + 1) & 3];
                    o[k].d[3] = py[(k + 1) & 3];
                }
                return (u != 0.0 && v != 0.0) ? 4 : 0;
            }
        }
        c[0] = sx; c[1] = sy; c[2] = x; c[3] = y;
        for (k = 0; k < 4; k++) {
            blank(&o[k]);
            o[k].cls = JW_SEN;
            for (j = 0; j < 4; j++)
                o[k].d[j] = c[ix[k][j]];
        }
        if (sx == x || sy == y)
            return 0;
        {   /* 多重 (1417): rectangles inside the one drawn, k/n of its size
             * about the same middle, outermost first -- the same rule the
             * circle's 多重円 follows.  The original, given 3, drew three:
             * 173.178 x 86.589, then 115.452 x 57.726 (two thirds), then a
             * third of it, all centred on (39.831, -92.650). */
            const char *t = jw_cmd_box(1417);
            int rings = t && *t ? atoi(t) : 0, r, made = 4;
            double mx = (sx + x) / 2.0, my = (sy + y) / 2.0;
            if (rings > 1) {
                if (rings * 4 > max)
                    rings = max / 4;
                for (r = rings - 1; r >= 1; r--) {
                    double f = (double)r / (double)rings;
                    for (k = 0; k < 4; k++, made++) {
                        blank(&o[made]);
                        o[made].cls = JW_SEN;
                        for (j = 0; j < 4; j++) {
                            double v = c[ix[k][j]];
                            double m = (j & 1) ? my : mx;
                            o[made].d[j] = m + (v - m) * f;
                        }
                    }
                }
            }
            return made;
        }
    }
    case JW_CMD_ENKO: {
        /* CZukeiEnko's constructor leaves it a whole circle: the sweep it
         * starts with is 2 pi (0x401921fb54442d18 at +0x34), the flattening
         * is 1 (+0x3c) and the 円弧 flag is off (+0xe8 = 1).  Every whole
         * circle in the sample drawings carries the trailing 1 as well.
         *
         * 半径 in the bar makes every click a circle of that radius, which
         * is how a drawing gets a circle of a size rather than of a drag:
         * the original, given 100 on a 1/200 group and two clicks, drew two
         * circles of 0.5 mm -- one at each click -- instead of one circle
         * from the first click out to the second.  The start angle it wrote
         * was 0. */
        double r = box_mm(d, 1411);
        double dx = x - sx, dy = y - sy;
        /* 扁平率 (1412) and 傾き (1413) make it an ellipse: 傾き is where
         * the long axis points, in degrees.  The drag still ends on the
         * curve, which fixes the long radius and the parameter of that
         * point -- the original, given 50 and 20 and a drag of 86.588921
         * straight out, wrote a = 100.642007, the angle -0.629233, the
         * tilt 0.349066 (20 degrees) and the ratio 0.5.
         *
         * **扁平率 takes either form.**  The original was given 0.5, 50
         * and 200 for the same drag (tools/probe57.sh, probe59.sh) and
         * wrote the ratio 0.5, 0.5 and 2.  So anything over one is a
         * percentage and anything at or under it is the ratio itself.
         * What exactly 1 means was not asked; it is 1 either way. */
        const char *fs = jw_cmd_box(1412);
        double ratio = en_ratio(fs);
        double tilt = box_angle(1413);
        o->cls = JW_ENKO;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = r > 0.0 ? r : sqrt(dx * dx + dy * dy);
        o->d[3] = r > 0.0 ? 0.0 : atan2(dy, dx);
        if (ratio > 0.0 && ratio != 1.0 && r <= 0.0) {
            double ct = cos(tilt), st = sin(tilt);
            double u = dx * ct + dy * st, v = (-dx * st + dy * ct) / ratio;
            o->d[2] = sqrt(u * u + v * v);
            o->d[3] = atan2(v, u);
        }
        o->d[4] = 2 * PI;
        o->d[5] = tilt;
        o->d[6] = ratio > 0.0 ? ratio : 1.0;
        o->n = 1;
        if (o->d[2] <= 0.0)
            return 0;
        if (en_kihon > 0) {
            double ct = cos(tilt), st = sin(tilt), rt = ratio > 0.0 ? ratio : 1.0;
            double u = dx * ct + dy * st, v = (-dx * st + dy * ct) / rt;
            en_kihon_shift(&o->d[0], &o->d[1], &o->d[2], dx, dy, u, v, r, rt, tilt);
        }
        {   /* 多重円: rings inside the one that was drawn, at k/n of its
             * radius.  The original, given 3 and a circle of 86.588921,
             * added 57.725948 and 28.862974 -- two thirds and one third,
             * written outermost first after the one clicked. */
            const char *t = jw_cmd_box(1417);
            int rings = t && *t ? atoi(t) : 0, k, made = 1;
            if (rings > 1) {
                if (rings > max)
                    rings = max;
                for (k = rings - 1; k >= 1; k--) {
                    jw_obj *m = &o[made];
                    blank(m);
                    m->cls = JW_ENKO;
                    m->d[0] = o->d[0];
                    m->d[1] = o->d[1];
                    m->d[2] = o->d[2] * (double)k / (double)rings;
                    m->d[3] = o->d[3];
                    m->d[4] = o->d[4];
                    m->d[5] = 0.0;
                    m->d[6] = 1.0;
                    m->n = 1;
                    made++;
                }
            }
            return made;
        }
    }
    }
    return 0;
}

/* The same, and the status line's readout with it: whatever is built here
   is either hanging off the mouse or about to be committed, and either way
   it is what the original is reading out (tools/probe26.sh). */
static int figure(const jw_drawing *d, jw_obj *o, int max,
                  double x, double y)
{
    int n = figure_(d, o, max, x, y);

    if (n > 0 && current == JW_CMD_SEN && o[0].cls == JW_SEN) {
        double dx = o[0].d[2] - o[0].d[0], dy = o[0].d[3] - o[0].d[1];
        tail_set(1, atan2(dy, dx) * 180.0 / PI, sqrt(dx * dx + dy * dy));
    } else if (n > 0 && current == JW_CMD_KUKEI) {
        /* four sides or one fill: the box round the lot is the W and H */
        double x0 = 0.0, y0 = 0.0, x1 = 0.0, y1 = 0.0;
        int i, k, first = 1;
        for (i = 0; i < n; i++)
            for (k = 0; k < 8; k += 2) {
                double px = o[i].d[k], py = o[i].d[k + 1];
                if (o[i].cls != JW_SEN && o[i].cls != JW_SOLID)
                    continue;
                if (o[i].cls == JW_SEN && k > 2)
                    continue;
                if (first) {
                    x0 = x1 = px;
                    y0 = y1 = py;
                    first = 0;
                } else {
                    if (px < x0) x0 = px;
                    if (px > x1) x1 = px;
                    if (py < y0) y0 = py;
                    if (py > y1) y1 = py;
                }
            }
        if (!first)
            tail_set(2, x1 - x0, y1 - y0);
    } else if (n > 0 && current == JW_CMD_ENKO && o[0].cls == JW_ENKO) {
        tail_set(3, o[0].d[2], 0.0);
    }
    return n;
}

int jw_cmd_pending(jw_drawing *d, jw_obj *o, int max)
{
    int n;

    if (current == JW_CMD_GAZOU)
        return gz_pending(d, o, max);

    if (current == JW_CMD_AUTO && step > 0) {       /* 引きかけの線 */
        current = JW_CMD_SEN;
        n = jw_cmd_pending(d, o, max);
        current = JW_CMD_AUTO;
        return n;
    }

    /* 分割の 連続点分割 (RR): 原典 FUN_007614c0 の else 枝が、積んだ点を順に結ぶ線と
       最後の点からカーソルまでの線を仮に描く（添え字 1 から +0x4e 個目まで）。
       画素は未確認（仮表示色の実線で出す） */
    if (current == JW_CMD_BUNKATSU && bk_rr_n > 0) {
        int i, m = 0;

        for (i = 1; i < bk_rr_n && m < max; i++, m++) {
            blank(&o[m]);
            o[m].cls = JW_SEN;
            o[m].d[0] = bk_rr_x[i];
            o[m].d[1] = bk_rr_y[i];
            o[m].d[2] = bk_rr_x[i + 1];
            o[m].d[3] = bk_rr_y[i + 1];
        }
        if (tracking && m < max) {
            blank(&o[m]);
            o[m].cls = JW_SEN;
            o[m].d[0] = bk_rr_x[bk_rr_n];
            o[m].d[1] = bk_rr_y[bk_rr_n];
            o[m].d[2] = tx;
            o[m].d[3] = ty;
            m++;
        }
        return m;
    }

    /* 多角形の 任意: 積んだ頂点を線で結び、最後からカーソルまで。
       原典のスクリーンショット（tmp/s6.png）の赤い仮の線にならった形 */
    if (current == JW_CMD_TAKAKU && tk_any && tk_an > 0) {
        int i, m = 0;

        for (i = 0; i + 1 < tk_an && m < max; i++, m++) {
            blank(&o[m]);
            o[m].cls = JW_SEN;
            o[m].d[0] = tk_ax2[i];
            o[m].d[1] = tk_ay2[i];
            o[m].d[2] = tk_ax2[i + 1];
            o[m].d[3] = tk_ay2[i + 1];
        }
        if (tracking && m < max) {
            blank(&o[m]);
            o[m].cls = JW_SEN;
            o[m].d[0] = tk_ax2[tk_an - 1];
            o[m].d[1] = tk_ay2[tk_an - 1];
            o[m].d[2] = tx;
            o[m].d[3] = ty;
            m++;
        }
        return m;
    }

    /* 測定 shows what it has measured, in 仮表示色 like anything else
     * part way through.  The original's own window bears it out
     * (`tools/probe145.sh`): with three points taken in 距離測定 it had
     * 701 red pixels -- the two segments and a leg out to the cursor --
     * and with four in 面積測定 1,293, which is those three segments,
     * the leg to the cursor, and **a line from the cursor back to the
     * first point**.
     *
     * 原典の絵は `docs/ref_sokutei_len.png`（距離測定、三点）と
     * `docs/ref_sokutei_area.png`（面積測定、四点）で、どちらも
     * カーソルを画面の (900,300) に置いて撮ってあります。
     *
     * **ここは画素まで同じにはできていません。**移植は実線で引き、
     * 原典は点線混じりに見えます —— 横線を一画素ずつ読むと
     * 379, 381,382,383, 385,386,387 … と三画素おきに抜けます。
     * おそらく**実線の辺の上に、カーソルへの点線が重なって XOR で
     * 抜けている**のですが（原典も R2_NOTXORPEN で描きます）、どの脚が
     * どこまで伸びているのかまでは割り切れませんでした。いまの移植は
     * 距離測定で原典の赤 805 画素を**一つ残らず**覆い、面積測定で
     * 1,397 画素のうち 1,288 を覆います。形は合っていて、抜けだけが
     * 違います。
     *
     * 座標測定 と 角度測定 の仮表示は見ていません。 */
    if (current == JW_CMD_SOKUTEI
        && (sok_mode == SOK_LEN || sok_mode == SOK_AREA)) {
        int i, k = sok_n < SOK_MAX ? sok_n : SOK_MAX;

        n = 0;
        for (i = 1; i < k && n < max; i++) {
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].d[0] = sok_rx[i - 1];
            o[n].d[1] = sok_ry[i - 1];
            o[n].d[2] = sok_rx[i];
            o[n].d[3] = sok_ry[i];
            n++;
        }
        if (k > 0 && tracking && n < max) {
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].d[0] = sok_rx[k - 1];
            o[n].d[1] = sok_ry[k - 1];
            o[n].d[2] = tx;
            o[n].d[3] = ty;
            n++;
        }
        if (sok_mode == SOK_AREA && k > 1 && n < max) {
            /* the ring is shown closed, whether or not the mouse is in */
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].d[0] = sok_rx[k - 1];
            o[n].d[1] = sok_ry[k - 1];
            o[n].d[2] = sok_rx[0];
            o[n].d[3] = sok_ry[0];
            n++;
        }
        return n;
    }

    if (current == JW_CMD_MOJI)
        return tracking ? moji(d, o, tx, ty) : 0;
    if (current == JW_CMD_RENZOKU && jw_cmd_bar_check(2492) > 0)
        /* 連続弧 hangs an arc off the cursor, not a segment, and what
           that looks like before the third point has not been asked */
        return 0;
    if (current == JW_CMD_RENZOKU) {
        int n = 0;
        /* the segment that is drawn but not yet in the drawing */
        if (step == 3 && max > 0) {
            blank(o);
            o->cls = JW_SEN;
            o->d[0] = sx;
            o->d[1] = sy;
            o->d[2] = rx;
            o->d[3] = ry;
            n = 1;
        }
        /* and the one following the mouse, from the last point */
        if (step != 0 && tracking && n < max) {
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].d[0] = step == 3 ? rx : sx;
            o[n].d[1] = step == 3 ? ry : sy;
            o[n].d[2] = tx;
            o[n].d[3] = ty;
            n++;
        }
        return n;
    }
    if (step != 2 || !tracking)
        return 0;
    n = figure(d, o, max, tx, ty);
    /* 矩形 の ソリッド: what hangs off the mouse is the frame, not the
     * fill.  Caught on the original's own screen with the second corner
     * under the cursor -- ソリッド alone draws the four sides in the band
     * colour and nothing inside, and with (対角線) as well the diagonal
     * from the first corner to the second is drawn across it.  The fill and
     * the collapsed corners only turn up in what is committed. */
    if (current == JW_CMD_KUKEI && n == 1 && o[0].cls == JW_SOLID) {
        double x0 = sx, y0 = sy, x1 = tx, y1 = ty;
        double wmm = box_mm(d, 1413), hmm = box_mm2(d, 1413);
        int k;
        static const int ix[4][4] = { {0,1,2,1}, {2,1,2,3}, {2,3,0,3}, {0,3,0,1} };
        double c[4];
        if (wmm > 0.0 && hmm > 0.0) {
            x1 = x0 + (x1 < x0 ? -wmm : wmm);
            y1 = y0 + (y1 < y0 ? -hmm : hmm);
        }
        c[0] = x0; c[1] = y0; c[2] = x1; c[3] = y1;
        n = 0;
        for (k = 0; k < 4 && n < max; k++, n++) {
            int j;
            blank(&o[n]);
            o[n].cls = JW_SEN;
            for (j = 0; j < 4; j++)
                o[n].d[j] = c[ix[k][j]];
        }
        if (jw_cmd_bar_check(1335) > 0 && n < max) {
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].d[0] = x0;
            o[n].d[1] = y0;
            o[n].d[2] = x1;
            o[n].d[3] = y1;
            n++;
        }
    }
    return n;
}

/* Take an element out and remember it, so 元に戻る can put it back.  `o` is
   the step it belongs to, so a cut can record the removal and the two pieces
   that replace it as one press-worth. */
/* 仮点消去 が狙うのは **kind=1 の点だけ**です。原典は普通の拾い方
   （FUN_0044a270）に点だけの枠を渡しているはずですが、そこは読んで
   いないので、ここは移植の `jw_pick` と同じ画素の近さで拾います。 */
static int pick_kariten(const jw_drawing *d, const jw_view *v,
                        double x, double y)
{
    int i, best = -1;
    double bd = 0.0;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double dx, dy, r;

        if (o->cls != JW_TEN || o->n != 1)
            continue;
        dx = o->d[0] - x;
        dy = o->d[1] - y;
        r = dx * dx + dy * dy;
        if (best < 0 || r < bd) {
            best = i;
            bd = r;
        }
    }
    if (best < 0)
        return -1;
    /* 拾う幅は移植のほかの拾い方と同じもの */
    {
        double lim = jw_pick_tol(v);

        if (bd > lim * lim)
            return -1;
    }
    return best;
}

/* 交点が二つあるとき、原典は**二度目のクリックに近いほう**を落とします。
 * 円と水平線で確かめました（tools/probe155.sh、答えは
 * decomp/res/ten_lc_*.jww）—— 中心 (-33.0612, -34.8980)・半径 61.2245 の
 * 円と y = -53.2653 の線で、交点は x が -91.4657 と 25.3432。
 * 【Ｂ】を線の左端で押すと前者、右端で押すと後者が落ちました。
 *
 * **円弧と楕円は訊いていません。**ここは環を丸ごとの円として扱います。
 */
static int circle_of(const jw_obj *o, double *cx, double *cy, double *r)
{
    if (o->cls != JW_ENKO || o->d[2] <= 0.0)
        return 0;
    if (o->d[6] != 0.0 && o->d[6] != 1.0)
        return 0;                       /* 扁平率つきは訊いていません */
    *cx = o->d[0];
    *cy = o->d[1];
    *r = o->d[2];
    return 1;
}

/* 要素そのものを渡す形（伸縮の基準線は写しを持つので） */
static int cross_obj(const jw_obj *a, const jw_obj *b,
                     double px, double py, double *ox, double *oy);

static int cross_point(const jw_drawing *d, int ia, int ib,
                       double px, double py, double *ox, double *oy)
{
    return cross_obj(&d->obj[ia], &d->obj[ib], px, py, ox, oy);
}

static int cross_obj(const jw_obj *a, const jw_obj *b,
                     double px, double py, double *ox, double *oy)
{
    double cand[4][2];
    int n = 0, i, best = -1;
    double bd = 0.0;
    double cx, cy, r, cx2, cy2, r2;

    if (a->cls == JW_SEN && b->cls == JW_SEN) {
        double ax = a->d[2] - a->d[0], ay = a->d[3] - a->d[1];
        double bx = b->d[2] - b->d[0], by = b->d[3] - b->d[1];
        double den = ax * by - ay * bx;

        if (den == 0.0)
            return 0;
        {
            double t = ((b->d[0] - a->d[0]) * by
                        - (b->d[1] - a->d[1]) * bx) / den;

            cand[n][0] = a->d[0] + t * ax;
            cand[n][1] = a->d[1] + t * ay;
            n++;
        }
    } else if ((a->cls == JW_SEN) != (b->cls == JW_SEN)) {
        /* 線と円 */
        const jw_obj *ln = a->cls == JW_SEN ? a : b;
        const jw_obj *ci = a->cls == JW_SEN ? b : a;
        double dx, dy, fx, fy, A, B, C, disc;

        if (!circle_of(ci, &cx, &cy, &r))
            return 0;
        dx = ln->d[2] - ln->d[0];
        dy = ln->d[3] - ln->d[1];
        fx = ln->d[0] - cx;
        fy = ln->d[1] - cy;
        A = dx * dx + dy * dy;
        B = 2.0 * (fx * dx + fy * dy);
        C = fx * fx + fy * fy - r * r;
        if (A == 0.0)
            return 0;
        disc = B * B - 4.0 * A * C;
        if (disc < 0.0)
            return 0;
        disc = sqrt(disc);
        for (i = 0; i < 2; i++) {
            double t = (-B + (i ? -disc : disc)) / (2.0 * A);

            cand[n][0] = ln->d[0] + t * dx;
            cand[n][1] = ln->d[1] + t * dy;
            n++;
            if (disc == 0.0)
                break;
        }
    } else if (a->cls == JW_ENKO && b->cls == JW_ENKO) {
        /* 円と円 */
        double L, h2;

        if (!circle_of(a, &cx, &cy, &r) || !circle_of(b, &cx2, &cy2, &r2))
            return 0;
        {
            double dx = cx2 - cx, dy = cy2 - cy;

            L = sqrt(dx * dx + dy * dy);
            if (L == 0.0 || L > r + r2 || L < fabs(r - r2))
                return 0;
            {
                double t = (r * r - r2 * r2 + L * L) / (2.0 * L);
                double mx = cx + t * dx / L, my = cy + t * dy / L;

                h2 = r * r - t * t;
                if (h2 < 0.0)
                    h2 = 0.0;
                h2 = sqrt(h2);
                cand[n][0] = mx + h2 * (-dy) / L;
                cand[n][1] = my + h2 * dx / L;
                n++;
                if (h2 > 0.0) {
                    cand[n][0] = mx - h2 * (-dy) / L;
                    cand[n][1] = my - h2 * dx / L;
                    n++;
                }
            }
        }
    } else {
        return 0;
    }
    for (i = 0; i < n; i++) {
        double dx = cand[i][0] - px, dy = cand[i][1] - py;
        double r = dx * dx + dy * dy;

        if (best < 0 || r < bd) {
            best = i;
            bd = r;
        }
    }
    if (best < 0)
        return 0;
    *ox = cand[best][0];
    *oy = cand[best][1];
    return 1;
}

static void erase(jw_drawing *d, int i, op_t *o)
{
    op_keep(o, d, i, 1);
    jw_remove(d, i);
}

/* Cut the piece between two points out of a line -- FUN_00471e40, the arm of
 * FUN_00470200 that handles CDataSen.
 *
 * Both points are put on the line first (the original drops a perpendicular
 * on to it: drawing a line in Jw_cad at screen y 300 and then cutting it with
 * clicks at y 330 and y 270 leaves two pieces that both end on the line, at
 * exactly the x of the clicks).  What is left is the piece before the nearer
 * cut and the piece after the further one, and either can be nothing.
 *
 * The element itself is kept and made into the first surviving piece; only a
 * second piece is added.  That is what the original does -- cutting the
 * middle out of an arc in Jw_cad left the first half where the whole one had
 * been and put the other half at the end.
 */
static void cut_line(jw_drawing *d, int i, double px, double py,
                     double qx, double qy)
{
    jw_obj was;
    op_t *rec;
    double ax, ay, ux, uy, len, t0, t1, t;
    int keep0, keep1;

    if (i < 0 || i >= d->ndrawn || d->obj[i].cls != JW_SEN)
        return;
    was = d->obj[i];
    ax = was.d[0];
    ay = was.d[1];
    ux = was.d[2] - ax;
    uy = was.d[3] - ay;
    len = sqrt(ux * ux + uy * uy);
    if (len < 1e-07)
        return;
    ux /= len;
    uy /= len;
    t0 = (px - ax) * ux + (py - ay) * uy;
    t1 = (qx - ax) * ux + (qy - ay) * uy;
    if (t1 < t0) {
        t = t0;
        t0 = t1;
        t1 = t;
    }
    if (t1 <= 1e-07 || len - 1e-07 <= t0)
        return;                 /* the piece misses the line altogether */

    keep0 = t0 > 1e-07;
    keep1 = t1 < len - 1e-07;
    rec = op_new();
    if (!keep0 && !keep1) {
        erase(d, i, rec);
        return;
    }
    op_keep(rec, d, i, 0);
    if (keep0) {
        d->obj[i].d[2] = ax + t0 * ux;
        d->obj[i].d[3] = ay + t0 * uy;
    } else {
        d->obj[i].d[0] = ax + t1 * ux;
        d->obj[i].d[1] = ay + t1 * uy;
    }
    if (keep0 && keep1) {
        jw_obj *o = jw_add(d, JW_SEN);
        if (o) {
            *o = was;
            o->d[0] = ax + t1 * ux;
            o->d[1] = ay + t1 * uy;
            if (rec)
                rec->n++;
        }
    }
}

/* The angle of a point round an arc, in the arc's own frame -- turned back
   by its tilt and unsquashed by its flattening, the way FUN_0042b7d0 does
   it.  Only the angle matters: clicking well inside the circle cuts it in
   exactly the same place as clicking on it. */
static double arc_angle(const jw_obj *o, double x, double y)
{
    double ex = x - o->d[0], ey = y - o->d[1];
    double c = cos(o->d[5]), s = sin(o->d[5]);
    double flat = o->d[6] > 0.0 ? o->d[6] : 1.0;

    return atan2((c * ey - s * ex) / flat, c * ex + s * ey);
}

static double turn(double a)
{
    while (a < 0.0)
        a += 2 * PI;
    while (a >= 2 * PI)
        a -= 2 * PI;
    return a;
}

/* The same for an arc.  A whole circle keeps one arc, starting where the
 * second point was and going the long way round; a part of one splits the
 * way a line does.  Both were driven through Jw_cad: cutting a whole circle
 * between 90 and 180 degrees left one arc at 180 sweeping 270, and cutting
 * that one again between 270 and 0 left 180+90 and 0+90.
 */
static void cut_arc(jw_drawing *d, int i, double px, double py,
                    double qx, double qy)
{
    jw_obj was;
    op_t *rec;
    double a0, sw, span, dir, u1, u2, t;
    int whole, keep0, keep1;

    if (i < 0 || i >= d->ndrawn || d->obj[i].cls != JW_ENKO)
        return;
    was = d->obj[i];
    a0 = was.d[3];
    sw = was.d[4];
    dir = sw < 0.0 ? -1.0 : 1.0;
    span = sw == 0.0 ? 2 * PI : fabs(sw);
    whole = span >= 6.283185207179586;
    u1 = turn((arc_angle(&was, px, py) - a0) * dir);
    u2 = turn((arc_angle(&was, qx, qy) - a0) * dir);

    rec = op_new();
    if (whole) {
        double gap = turn(u2 - u1);
        if (gap <= 0.0)
            return;
        op_keep(rec, d, i, 0);
        d->obj[i].d[3] = turn(a0 + dir * u2);
        d->obj[i].d[4] = dir * (2 * PI - gap);
        return;
    }
    if (u2 < u1) {
        t = u1;
        u1 = u2;
        u2 = t;
    }
    if (u2 <= 1e-07 || span - 1e-07 <= u1)
        return;
    keep0 = u1 > 1e-07;
    keep1 = u2 < span - 1e-07;
    if (!keep0 && !keep1) {
        erase(d, i, rec);
        return;
    }
    op_keep(rec, d, i, 0);
    if (keep0) {
        d->obj[i].d[4] = dir * u1;
    } else {
        d->obj[i].d[3] = turn(a0 + dir * u2);
        d->obj[i].d[4] = dir * (span - u2);
    }
    if (keep0 && keep1) {
        jw_obj *o = jw_add(d, JW_ENKO);
        if (o) {
            *o = was;
            o->d[3] = turn(a0 + dir * u2);
            o->d[4] = dir * (span - u2);
            if (rec)
                rec->n++;
        }
    }
}

/* コーナー処理 with an arc in it -- 逆コンパイルの読み、原典では押していない.
 *
 * CZukeiCorner's left button (slot 9, FUN_00636b10) takes the two elements
 * and its slot 3 (FUN_006374e0) hands them to FUN_0046abe0, the corner
 * itself.  That one asks FUN_0045fa30 for the crossing of the two -- a line
 * and an arc go to FUN_00462070, two arcs to FUN_00460710 -- and then has
 * each element taken to it by FUN_0044cfb0: a line by FUN_0044da00, an arc
 * by FUN_0044d190.  What is read here:
 *
 *   - Each element remembers where it was picked (CData +0x30), and that is
 *     not the click but the foot of it on the element (FUN_00455870 →
 *     FUN_0045b790 for an arc: the point of the ellipse at the click's
 *     angle).  corner_foot is that.
 *   - Of the two crossings of a line with an arc (or of two arcs) the one
 *     taken is the one nearer -- |dx|+|dy| -- to a reference point: the
 *     arc's pick for a line and an arc, the middle of the two picks for two
 *     arcs.  A line meeting an arc is taken as the whole line and the whole
 *     ellipse; for an arc the sum is done in the circle's own frame (turned
 *     back by the tilt, the ellipse squashed to a circle).
 *   - Two circles: the textbook crossing, a touch taken as one point.  An
 *     ellipse among them: walked to the crossing from the reference point,
 *     each step the crossing of the two tangents at the points of the
 *     ellipses nearest (at the same angle) to the last one, up to 40 steps
 *     until a step moves less than 1e-8.
 *   - A whole circle is refused when it is picked (FUN_0063aa60, string
 *     5207 「円です。切断で弧にしてください。」) and FUN_0044d190 leaves one
 *     alone anyway: it has no end to move.
 *   - The arc keeps its start and goes to the crossing when the click is
 *     between the start and the crossing; when the crossing is past the
 *     arc's end it is the end that goes there if the click is nearer the
 *     end than the start; otherwise the start moves to the crossing and the
 *     end stays.  A sweep that comes out at 0 is a whole turn, and one of a
 *     whole turn makes the arc a circle (the flag at +0x90, string 5208).
 */
static void corner_foot(const jw_obj *o, double *x, double *y)
{
    if (o->cls == JW_SEN) {
        double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1], l2 = dx * dx + dy * dy, t;

        if (l2 <= 0.0)
            return;
        t = ((*x - o->d[0]) * dx + (*y - o->d[1]) * dy) / l2;
        *x = o->d[0] + t * dx;
        *y = o->d[1] + t * dy;
    } else if (o->cls == JW_ENKO) {
        double f = o->d[6], c = cos(o->d[5]), s = sin(o->d[5]);
        double ex = *x - o->d[0], ey = *y - o->d[1], u, w, l;

        if (f < 1e-07 || fabs(ex) + fabs(ey) < 1e-07)
            return;
        u = c * ex + s * ey;
        w = (c * ey - s * ex) / f;
        l = sqrt(u * u + w * w);
        if (l < 1e-07)
            return;
        u *= o->d[2] / l;
        w *= o->d[2] / l * f;
        *x = c * u - s * w + o->d[0];
        *y = c * w + s * u + o->d[1];
    }
}

static int corner_whole(const jw_obj *o)
{
    return o->d[4] == 0.0 || fabs(o->d[4]) >= 6.283185207179586;
}

/* FUN_0040b250: an angle brought round to the sweep's side, within a turn */
static double corner_norm(double sw, double a)
{
    if (sw > 0.0)
        while (a < 0.0)
            a += 2 * PI;
    if (sw < 0.0)
        while (a > 0.0)
            a -= 2 * PI;
    while (a > 2 * PI)
        a -= 2 * PI;
    while (a < -2 * PI)
        a += 2 * PI;
    return a;
}

/* FUN_00462070 as the corner uses it: line l and arc e, the crossing
   nearer (rx,ry) */
static int corner_line_arc(const jw_obj *l, const jw_obj *e, double rx, double ry,
                           double *ox, double *oy)
{
    double c = cos(e->d[5]), s = sin(e->d[5]), f = e->d[6], r = e->d[2];
    double ax, ay, bx, by, kx, ky, dx, dy, len, ux, uy, along, perp;
    double t1, t2, q1x, q1y, q2x, q2y, qx, qy;

    if (f == 0.0)
        return 0;
#define LOC(X, Y, U, V) (U = c * ((X) - e->d[0]) + s * ((Y) - e->d[1]), \
                         V = (c * ((Y) - e->d[1]) - s * ((X) - e->d[0])) / f)
    LOC(l->d[0], l->d[1], ax, ay);
    LOC(l->d[2], l->d[3], bx, by);
    LOC(rx, ry, kx, ky);
#undef LOC
    dx = bx - ax;
    dy = by - ay;
    len = dx * dx + dy * dy;
    if (len <= 1e-07)
        return 0;
    len = sqrt(len);
    ux = dx / len;
    uy = dy / len;
    along = ux * -ax + uy * -ay;
    perp = fabs(ux * -ay - uy * -ax);
    if (1e-07 < perp - r)
        return 0;               /* the line misses the circle */
    t1 = t2 = along;
    if (1e-07 < fabs(perp - r)) {
        double h = sqrt(r * r - perp * perp);
        t2 = along + h;
        t1 = along - h;
    }
    q1x = ax + ux * t1;
    q1y = ay + uy * t1;
    q2x = ax + ux * t2;
    q2y = ay + uy * t2;
    if (fabs(q1x - kx) + fabs(q1y - ky) < fabs(q2x - kx) + fabs(q2y - ky)) {
        qx = q1x;
        qy = q1y;
    } else {
        qx = q2x;
        qy = q2y;
    }
    *ox = c * qx - s * qy * f + e->d[0];
    *oy = c * qy * f + s * qx + e->d[1];
    if (l->d[0] == l->d[2])
        *ox = l->d[0];
    if (l->d[1] == l->d[3])
        *oy = l->d[1];
    return 1;
}

/* FUN_0045a7f0: the tangent of e at its point at the angle of (px,py) */
static int corner_tangent(const jw_obj *e, double px, double py, double t[4])
{
    double c = cos(e->d[5]), s = sin(e->d[5]), f = e->d[6], r = e->d[2];
    double ex = px - e->d[0], ey = py - e->d[1], u, w, l, p, m;

    if (f < 0.01 || f > 100.0 || fabs(ex) + fabs(ey) < 1e-07)
        return 0;
    u = c * ex + s * ey;
    w = (c * ey - s * ex) / f;
    l = sqrt(u * u + w * w);
    u *= r / l;
    w *= r / l;
    p = (w + u) * f;
    m = (w - u) * f;
    t[0] = c * (u - w) - s * p + e->d[0];
    t[1] = c * p + s * (u - w) + e->d[1];
    t[2] = c * (u + w) - s * m + e->d[0];
    t[3] = c * m + s * (u + w) + e->d[1];
    return 1;
}

/* FUN_00460710 as the corner uses it: two arcs, the crossing nearer (rx,ry) */
static int corner_arc_arc(const jw_obj *a, const jw_obj *b, double rx, double ry,
                          double *ox, double *oy)
{
    double r1 = a->d[2], r2 = b->d[2], f1 = a->d[6], f2 = b->d[6];
    double dx = b->d[0] - a->d[0], dy = b->d[1] - a->d[1], dist;

    if (fabs(f1 - 1.0) < 1e-07 && fabs(f2 - 1.0) < 1e-07) {
        double al, h, ux, uy, p1x, p1y, p2x, p2y;

        dist = dx * dx + dy * dy;
        if (dist < 1e-07)
            return 0;
        dist = sqrt(dist);
        if (r1 + r2 + 1e-07 < dist || dist < fabs(r1 - r2) - 1e-07)
            return 0;
        if (r1 + r2 - 1e-07 <= dist || dist <= fabs(r1 - r2) + 1e-07) {
            al = r1;            /* touching: one point */
            if (dist <= fabs(r1 - r2) + 1e-07 && r1 < r2)
                al = -r1;
            h = 0.0;
        } else {
            al = (r1 * r1 - r2 * r2 + dist * dist) / (dist * 2.0);
            h = sqrt(fabs(r1 * r1 - al * al));
        }
        ux = dx / dist;
        uy = dy / dist;
        p1x = ux * al - uy * h + a->d[0];
        p1y = ux * h + uy * al + a->d[1];
        p2x = ux * al + uy * h + a->d[0];
        p2y = -ux * h + uy * al + a->d[1];
        if (fabs(p2x - rx) + fabs(p2y - ry) <= fabs(p1x - rx) + fabs(p1y - ry)) {
            *ox = p2x;
            *oy = p2y;
        } else {
            *ox = p1x;
            *oy = p1y;
        }
        return 1;
    } else {
        double reach = r1, px = rx, py = ry, move = 1.0;
        int k = 0;

        if (f1 > 1.0)
            reach *= f1;
        if (f2 > 1.0)
            reach *= f2;
        if ((1e-07 < fabs(dx) || 1e-07 < fabs(dy))
            && reach + r2 + 1e-07 < sqrt(dx * dx + dy * dy))
            return 0;
        while (1e-08 < move) {
            double ta[4], tb[4], adx, ady, bdx, bdy, den, t, qx, qy;

            if (!corner_tangent(a, px, py, ta) || !corner_tangent(b, px, py, tb))
                return 0;
            adx = ta[2] - ta[0];
            ady = ta[3] - ta[1];
            bdx = tb[2] - tb[0];
            bdy = tb[3] - tb[1];
            den = adx * bdy - ady * bdx;
            if (den == 0.0)
                return 0;
            t = ((tb[0] - ta[0]) * bdy - (tb[1] - ta[1]) * bdx) / den;
            qx = ta[0] + t * adx;
            qy = ta[1] + t * ady;
            if (++k > 40)
                return 0;
            move = fabs(qx - px) + fabs(qy - py);
            px = qx;
            py = qy;
        }
        *ox = px;
        *oy = py;
        return 1;
    }
}

/* FUN_0044d190: arc o taken to (ix,iy), the side of (kx,ky) kept.  0 when
   it is left as it is. */
static int corner_arc_to(jw_obj *o, double ix, double iy, double kx, double ky)
{
    double c = cos(o->d[5]), s = sin(o->d[5]), f = o->d[6];
    double st = o->d[3], sw = o->d[4], ai, ui, uc, aui, auc, asw, nsw;
    int edge = 0;

    if (corner_whole(o) || o->d[2] == 0.0 || f == 0.0)
        return 0;
    ix -= o->d[0];
    iy -= o->d[1];
    kx -= o->d[0];
    ky -= o->d[1];
    ai = atan2((c * iy - s * ix) / f, c * ix + s * iy);
    ui = corner_norm(sw, ai - st);
    uc = corner_norm(sw, atan2((c * ky - s * kx) / f, c * kx + s * ky) - st);
    aui = fabs(ui);
    auc = fabs(uc);
    asw = fabs(sw);
    if (aui < 1e-07 || fabs(aui - asw) < 1e-07)
        edge = 1;               /* the crossing is at one of its ends */
    if ((!edge && aui <= asw && auc < aui)
        || (!edge && asw < aui && fabs(asw - auc) < auc)
        || (edge && fabs(asw - auc) < auc)) {
        nsw = ui;               /* the start stays, the end goes */
        if (fabs(nsw) < 1e-07)
            nsw = 2 * PI;
    } else {                    /* the end stays, the start goes */
        double e = st + sw;
        nsw = corner_norm(ui, atan2(sin(e), cos(e)) - ai);
        if (fabs(nsw) < 1e-07)
            nsw = 2 * PI;
        st = ai;
    }
    o->d[3] = st;
    o->d[4] = nsw;
    if (fabs(fabs(nsw) - 2 * PI) < 1e-07) {
        if (nsw > 0.0)
            o->d[4] = 2 * PI;
        if (nsw < 0.0)
            o->d[4] = -2 * PI;
        o->n = 1;
    }
    return 1;
}

/* FUN_0044da00: line o taken to (ix,iy), the side of (kx,ky) kept */
static int corner_line_to(jw_obj *o, double ix, double iy, double kx, double ky)
{
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];

    if (dx == 0.0 && dy == 0.0)
        return 0;
    if ((ix - o->d[0]) * dx + (iy - o->d[1]) * dy
        <= (kx - o->d[0]) * dx + (ky - o->d[1]) * dy) {
        o->d[0] = ix;
        o->d[1] = iy;
    } else {
        o->d[2] = ix;
        o->d[3] = iy;
    }
    return 1;
}

static void corner_arc(jw_drawing *d, int a, double ax, double ay,
                       int b, double bx, double by)
{
    jw_obj p = d->obj[a], q = d->obj[b];
    double rx, ry, ix, iy;
    int ok, cp, cq;
    op_t *rec;

    if ((p.cls == JW_ENKO && corner_whole(&p)) || (q.cls == JW_ENKO && corner_whole(&q)))
        return;
    corner_foot(&p, &ax, &ay);
    corner_foot(&q, &bx, &by);
    if (p.cls == JW_ENKO && q.cls == JW_ENKO) {
        rx = (bx - ax) / 2.0 + ax;
        ry = (by - ay) / 2.0 + ay;
        ok = corner_arc_arc(&p, &q, rx, ry, &ix, &iy);
    } else if (q.cls == JW_ENKO) {
        ok = corner_line_arc(&p, &q, bx, by, &ix, &iy);
    } else {
        ok = corner_line_arc(&q, &p, ax, ay, &ix, &iy);
    }
    if (!ok || !(fabs(ix) < 1e9 && fabs(iy) < 1e9))
        return;                 /* string 5205: they do not meet */
    cp = p.cls == JW_ENKO ? corner_arc_to(&p, ix, iy, ax, ay)
                          : corner_line_to(&p, ix, iy, ax, ay);
    cq = q.cls == JW_ENKO ? corner_arc_to(&q, ix, iy, bx, by)
                          : corner_line_to(&q, ix, iy, bx, by);
    if (!cp && !cq)
        return;
    rec = op_new();
    if (cp) {
        op_keep(rec, d, a, 0);
        d->obj[a] = p;
    }
    if (cq) {
        op_keep(rec, d, b, 0);
        d->obj[b] = q;
    }
}

/* (R) 線切断 of コーナー and 面取 -- one function in the original, CZukeiCorner's
 * slot 11 FUN_00636ee0 (面取 is CZukeiCorner too, with +0xa03c set).  The
 * line or arc under the click is cut there, a 切断間隔 wide; with no width it
 * is split in two.  Where the width comes from is the one difference: コーナー
 * reads its bar with FUN_004cacd0 (box 1411), 面取 its own bar, CMentoriDialog,
 * with FUN_0056fd50 -- whose DDX ties the read edit to 0x585, box 1413, and the
 * 実寸 flag to 0x830, the 2096 on the same bar.  Read off the decompile, not
 * asked of the original. */
static void line_cut_r(jw_drawing *d, const jw_view *v, double x, double y,
                       int box)
{
    double gap = box_num(jw_cmd_box(box), 0.0), h;
    const jw_obj *o;
    int i;

    i = jw_pick(d, v, x, y, 3);
    if (i < 0)
        return;
    if (gap < 0.0)
        gap = 0.0;
    if (jw_cmd_bar_check(2096) > 0)
        gap /= write_scale(d);
    h = gap / 2.0;
    o = &d->obj[i];
    if (o->cls == JW_SEN) {
        double ux = o->d[2] - o->d[0], uy = o->d[3] - o->d[1], len = sqrt(ux * ux + uy * uy), t;

        if (len < 1e-7)
            return;
        ux /= len;
        uy /= len;
        t = (x - o->d[0]) * ux + (y - o->d[1]) * uy;
        cut_line(d, i, o->d[0] + ux * (t - h), o->d[1] + uy * (t - h),
                 o->d[0] + ux * (t + h), o->d[1] + uy * (t + h));
    } else if (o->cls == JW_ENKO) {
        double ex = x - o->d[0], ey = y - o->d[1], el = sqrt(ex * ex + ey * ey);

        if (el < 1e-7)
            return;
        if (o->d[4] < 0.0)      /* the arc runs the other way round */
            h = -h;
        cut_arc(d, i, x + ey / el * h, y - ex / el * h,
                x - ey / el * h, y + ex / el * h);
    }
}

/* 伸縮's (R) 線切断 (FUN_00715f50 → FUN_00470200) cuts with the same width
   as コーナー's, the 1411 of the bar */
static void cut_gap_at(jw_drawing *d, const jw_view *v, double x, double y)
{
    line_cut_r(d, v, x, y, 1411);
}

/* 消去 の 節間消し (1324).  左で拾った線・円の、拾った点の両側でいちばん近く
 * 交わる所までを消す。原典は CZukeiShoukyo の左（9 番 FUN_0070f1c0）が
 * +0x25c（バーの 1324、FUN_00710790）を見て一手目で実行に回し、3 番
 * FUN_0070fc60 が mode 3 で拾い直して FUN_00712f00 に渡す。逆コンパイルの読み、
 * 原典では押していない。
 *
 *   線   拾った点を線上に落とした位置 t（線の外なら何もしない）から、手前で
 *        いちばん近い交わりと先でいちばん近い交わりまでを FUN_00470200
 *        （= cut_line）で切る。どちらかが無ければ端まで、両方無ければ線ごと
 *   円弧 中心から見た角度で同じことをする（FUN_0070dae0）。全円は交わりが
 *        無いか一か所だけなら丸ごと消す（FUN_0070cad0）。弧は拾った点が弧の外
 *        なら何もしない（FUN_007104c0）
 *
 * 交わりに数えるのは 編集できる（FUN_0042dd10、表示のみを読む設定なら表示のみも）
 * 線・円弧・点だけ。線どうしは相手の両端が 1e-7 の幅で線を挟むとき、点は
 * 1e-7 以内に乗るとき。楕円どうし・楕円と円の交わり（原典 FUN_00714f40）は
 * 読んでいないので数えない。 */
#define SK_EPS 1e-7

/* 楕円（円）の中の座標へ: 中心を原点に、傾きを戻し、扁平を伸ばす */
static void sk_to_ell(const jw_obj *e, double x, double y, double *u, double *w)
{
    double c = cos(e->d[5]), s = sin(e->d[5]);
    double flat = e->d[6] > 0.0 ? e->d[6] : 1.0;
    double ex = x - e->d[0], ey = y - e->d[1];

    *u = c * ex + s * ey;
    *w = (c * ey - s * ex) / flat;
}

/* 弧の範囲に入っているか（全円は常に） */
static int sk_on_span(const jw_obj *e, double x, double y)
{
    double sw = e->d[4], span = sw == 0.0 ? 2 * PI : fabs(sw);
    double dir = sw < 0.0 ? -1.0 : 1.0, u, tol;

    if (span >= 6.283185207179586)
        return 1;
    tol = e->d[2] > 0.0 ? SK_EPS / e->d[2] : SK_EPS;
    u = turn((arc_angle(e, x, y) - e->d[3]) * dir);
    return u <= span + tol || u >= 2 * PI - tol;
}

/* A→B を通る直線と楕円（全周）の交わり。t は A→B を 1 とする位置 */
static int sk_line_ell(const jw_obj *e, double ax, double ay, double bx,
                       double by, double t[2])
{
    double pu, pw, qu, qw, du, dw, A, B, C, D, r = e->d[2];

    sk_to_ell(e, ax, ay, &pu, &pw);
    sk_to_ell(e, bx, by, &qu, &qw);
    du = qu - pu;
    dw = qw - pw;
    A = du * du + dw * dw;
    if (A < 1e-30 || r <= 0.0)
        return 0;
    B = 2.0 * (pu * du + pw * dw);
    C = pu * pu + pw * pw - r * r;
    D = B * B - 4.0 * A * C;
    if (D < 0.0) {
        /* 接するもの（丸めで僅かに負）は一点に */
        double m = -B / (2.0 * A), mu = pu + m * du, mw = pw + m * dw;

        if (fabs(sqrt(mu * mu + mw * mw) - r) > SK_EPS)
            return 0;
        t[0] = m;
        return 1;
    }
    D = sqrt(D);
    t[0] = (-B - D) / (2.0 * A);
    t[1] = (-B + D) / (2.0 * A);
    return D == 0.0 ? 1 : 2;
}

static int sk_is_round(const jw_obj *e)
{
    return e->d[6] <= 0.0 || fabs(e->d[6] - 1.0) <= SK_EPS;
}

/* 要素 k と、拾った要素 p（線なら延ばした直線、円弧なら全周）の交わりの点。
   k の上（線分の中・弧の範囲）にあるものだけ */
static int sk_cross(const jw_obj *p, const jw_obj *k, double *xs, double *ys)
{
    int n = 0, m, j;
    double t[2];

    if (k->cls == JW_TEN) {
        if (p->cls == JW_SEN) {
            double ux = p->d[2] - p->d[0], uy = p->d[3] - p->d[1];
            double len = sqrt(ux * ux + uy * uy);

            if (fabs(((k->d[0] - p->d[0]) * uy - (k->d[1] - p->d[1]) * ux) / len) > SK_EPS)
                return 0;
        } else {
            double u, w, flat = p->d[6] > 0.0 ? p->d[6] : 1.0;

            sk_to_ell(p, k->d[0], k->d[1], &u, &w);
            /* 扁平を戻した半径で比べる（円なら距離そのもの） */
            if (fabs(sqrt(u * u + w * w) - p->d[2]) > SK_EPS / (flat < 1.0 ? flat : 1.0))
                return 0;
            if (!sk_on_span(p, k->d[0], k->d[1]))
                return 0;
        }
        xs[0] = k->d[0];
        ys[0] = k->d[1];
        return 1;
    }
    if (p->cls == JW_SEN && k->cls == JW_SEN) {
        double ux = p->d[2] - p->d[0], uy = p->d[3] - p->d[1];
        double len = sqrt(ux * ux + uy * uy), y0, y1, f;

        ux /= len;
        uy /= len;
        y0 = (k->d[0] - p->d[0]) * -uy + (k->d[1] - p->d[1]) * ux;
        y1 = (k->d[2] - p->d[0]) * -uy + (k->d[3] - p->d[1]) * ux;
        if ((y0 > SK_EPS && y1 > SK_EPS) || (y0 < -SK_EPS && y1 < -SK_EPS))
            return 0;
        if (fabs(y1 - y0) < 1e-12)
            return 0;           /* 平行（重なるものも）: 交わりにしない */
        f = -y0 / (y1 - y0);
        xs[0] = k->d[0] + f * (k->d[2] - k->d[0]);
        ys[0] = k->d[1] + f * (k->d[3] - k->d[1]);
        return 1;
    }
    if (p->cls == JW_SEN && k->cls == JW_ENKO) {
        m = sk_line_ell(k, p->d[0], p->d[1], p->d[2], p->d[3], t);
        for (j = 0; j < m; j++) {
            double x = p->d[0] + t[j] * (p->d[2] - p->d[0]);
            double y = p->d[1] + t[j] * (p->d[3] - p->d[1]);

            if (sk_on_span(k, x, y)) {
                xs[n] = x;
                ys[n] = y;
                n++;
            }
        }
        return n;
    }
    if (p->cls == JW_ENKO && k->cls == JW_SEN) {
        double len = hypot(k->d[2] - k->d[0], k->d[3] - k->d[1]);
        double tol = len > 0.0 ? SK_EPS / len : 0.0;

        m = sk_line_ell(p, k->d[0], k->d[1], k->d[2], k->d[3], t);
        for (j = 0; j < m; j++) {
            if (t[j] < -tol || t[j] > 1.0 + tol)
                continue;
            xs[n] = k->d[0] + t[j] * (k->d[2] - k->d[0]);
            ys[n] = k->d[1] + t[j] * (k->d[3] - k->d[1]);
            n++;
        }
        return n;
    }
    if (p->cls == JW_ENKO && k->cls == JW_ENKO) {
        double dx, dy, dd, r0 = p->d[2], r1 = k->d[2], a, h, mx, my, cand[2][2];

        if (!sk_is_round(p) || !sk_is_round(k))
            return 0;           /* 楕円が絡むもの（FUN_00714f40）は読んでいない */
        dx = k->d[0] - p->d[0];
        dy = k->d[1] - p->d[1];
        dd = sqrt(dx * dx + dy * dy);
        if (dd < 1e-12 || dd > r0 + r1 + SK_EPS || dd < fabs(r0 - r1) - SK_EPS)
            return 0;
        a = (r0 * r0 - r1 * r1 + dd * dd) / (2.0 * dd);
        h = r0 * r0 - a * a;
        h = h > 0.0 ? sqrt(h) : 0.0;
        mx = p->d[0] + a * dx / dd;
        my = p->d[1] + a * dy / dd;
        cand[0][0] = mx - h * dy / dd;
        cand[0][1] = my + h * dx / dd;
        cand[1][0] = mx + h * dy / dd;
        cand[1][1] = my - h * dx / dd;
        m = h > 0.0 ? 2 : 1;
        for (j = 0; j < m; j++)
            if (sk_on_span(k, cand[j][0], cand[j][1])) {
                xs[n] = cand[j][0];
                ys[n] = cand[j][1];
                n++;
            }
        return n;
    }
    return 0;
}

static void setsukan(jw_drawing *d, int i, double px, double py)
{
    const jw_obj *p;
    double xs[2], ys[2];
    int k, j, m, count = 0;

    if (i < 0 || i >= d->ndrawn)
        return;
    p = &d->obj[i];
    if (p->cls == JW_SEN) {
        double ax = p->d[0], ay = p->d[1], ux = p->d[2] - ax, uy = p->d[3] - ay;
        double len = sqrt(ux * ux + uy * uy), tp, lo, hi;

        if (len < 1e-7)
            return;
        ux /= len;
        uy /= len;
        tp = (px - ax) * ux + (py - ay) * uy;
        if (tp < -SK_EPS || len + SK_EPS < tp)
            return;
        lo = -SK_EPS;
        hi = len + SK_EPS;
        for (k = d->ndrawn - 1; k >= 0; k--) {
            if (k == i || !jw_pick_editable(d, &d->obj[k]))
                continue;
            m = sk_cross(p, &d->obj[k], xs, ys);
            for (j = 0; j < m; j++) {
                double t = (xs[j] - ax) * ux + (ys[j] - ay) * uy;

                if (t <= tp && lo < t)
                    lo = t;
                if (tp <= t && t < hi)
                    hi = t;
            }
        }
        cut_line(d, i, ax + ux * lo, ay + uy * lo, ax + ux * hi, ay + uy * hi);
        return;
    }
    if (p->cls == JW_ENKO) {
        double cx = p->d[0], cy = p->d[1], ap, lo, hi, lx, ly, hx, hy;
        double sw = p->d[4], span = sw == 0.0 ? 2 * PI : fabs(sw);
        int whole = span >= 6.283185207179586;

        if (p->d[2] <= 1e-7)
            return;
        ap = atan2(py - cy, px - cx);
        if (whole) {
            lo = -2 * PI;
            hi = 2 * PI;
            lx = hx = px;
            ly = hy = py;
        } else {
            /* 弧の両端。原典は向きが負なら入れ替えて、反時計回りの始め・終り
               にする。拾った点が弧の外なら何もしない（FUN_007104c0） */
            double c = cos(p->d[5]), s = sin(p->d[5]);
            double flat = p->d[6] > 0.0 ? p->d[6] : 1.0, r = p->d[2];
            /* 端は 1e-9 だけ内側に取る: cut_arc が端を 0 と 2π の取り違えで
               読まないように（どちらも 1e-7 の内なので端まで消える） */
            double dir = sw < 0.0 ? -1.0 : 1.0;
            double a0 = p->d[3] + dir * 1e-9, a1 = p->d[3] + sw - dir * 1e-9;
            double e0x, e0y, e1x, e1y, t;

            if (!sk_on_span(p, px, py))
                return;
            e0x = cx + c * r * cos(a0) - s * flat * r * sin(a0);
            e0y = cy + s * r * cos(a0) + c * flat * r * sin(a0);
            e1x = cx + c * r * cos(a1) - s * flat * r * sin(a1);
            e1y = cy + s * r * cos(a1) + c * flat * r * sin(a1);
            if (sw < 0.0) {
                t = e0x; e0x = e1x; e1x = t;
                t = e0y; e0y = e1y; e1y = t;
            }
            lo = atan2(e0y - cy, e0x - cx) - ap;
            if (lo >= 0.0)
                lo -= 2 * PI;
            hi = atan2(e1y - cy, e1x - cx) - ap;
            if (hi <= 0.0)
                hi += 2 * PI;
            lx = e0x;
            ly = e0y;
            hx = e1x;
            hy = e1y;
        }
        for (k = d->ndrawn - 1; k >= 0; k--) {
            if (k == i || !jw_pick_editable(d, &d->obj[k]))
                continue;
            m = sk_cross(p, &d->obj[k], xs, ys);
            for (j = 0; j < m; j++) {
                /* FUN_0070dae0 */
                double r = atan2(ys[j] - cy, xs[j] - cx) - ap;

                count++;
                if (r >= 0.0)
                    r -= 2 * PI;
                if (lo < r) {
                    lo = r;
                    lx = xs[j];
                    ly = ys[j];
                }
                if (r <= 0.0)
                    r += 2 * PI;
                if (r < hi) {
                    hi = r;
                    hx = xs[j];
                    hy = ys[j];
                }
            }
        }
        if (!count || (whole && fabs(lo + 2 * PI - hi) <= SK_EPS)) {
            erase(d, i, op_new());
            return;
        }
        cut_arc(d, i, lx, ly, hx, hy);
    }
}
#undef SK_EPS

/* コーナー処理 -- two lines, cut or carried on to where they meet.
 *
 * What survives is the piece on the side the line was clicked: drawing an L
 * with a gap in Jw_cad and clicking each near the gap carries both on to the
 * corner, and clicking two lines that already cross, each on one side, cuts
 * both back to the crossing.  Either way both lines stay where they were in
 * the drawing -- the original changes them in place, it does not remake them.
 */
static void corner(jw_drawing *d, int a, double ax, double ay,
                   int b, double bx, double by)
{
    jw_obj *p = &d->obj[a], *q = &d->obj[b];
    double pdx, pdy, qdx, qdy, den, tp, tq, ix, iy, cp, cq;
    op_t *rec;

    if (a == b)
        return;
    if ((p->cls == JW_ENKO && (q->cls == JW_SEN || q->cls == JW_ENKO))
        || (p->cls == JW_SEN && q->cls == JW_ENKO)) {
        corner_arc(d, a, ax, ay, b, bx, by);
        return;
    }
    if (p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    pdx = p->d[2] - p->d[0];
    pdy = p->d[3] - p->d[1];
    qdx = q->d[2] - q->d[0];
    qdy = q->d[3] - q->d[1];
    den = pdx * qdy - pdy * qdx;
    if (den == 0.0)
        return;                 /* parallel: there is no corner */
    tp = ((q->d[0] - p->d[0]) * qdy - (q->d[1] - p->d[1]) * qdx) / den;
    tq = ((q->d[0] - p->d[0]) * pdy - (q->d[1] - p->d[1]) * pdx) / den;
    ix = p->d[0] + tp * pdx;
    iy = p->d[1] + tp * pdy;
    /* two lines that are nearly parallel meet a light-year away: that is no
       corner either (and a drawing cannot hold the number) */
    if (!(fabs(ix) < 1e9 && fabs(iy) < 1e9))
        return;
    /* where each click falls along its own line */
    cp = ((ax - p->d[0]) * pdx + (ay - p->d[1]) * pdy) / (pdx * pdx + pdy * pdy);
    cq = ((bx - q->d[0]) * qdx + (by - q->d[1]) * qdy) / (qdx * qdx + qdy * qdy);

    rec = op_new();
    op_keep(rec, d, a, 0);
    op_keep(rec, d, b, 0);
    if (cp < tp) {
        p->d[2] = ix;
        p->d[3] = iy;
    } else {
        p->d[0] = ix;
        p->d[1] = iy;
    }
    if (cq < tq) {
        q->d[2] = ix;
        q->d[3] = iy;
    } else {
        q->d[0] = ix;
        q->d[1] = iy;
    }
}

/* 面取（角面・辺寸法）.
 *
 * The same two lines as a corner, but each stops short of the crossing by
 * the 寸法 box's distance and a third line joins the two ends.  Driven in
 * the original with 寸法 2000 on a 1/200 group: an L of two lines meeting at
 * (126.4198,-222.5335) came out with the level one ending 10 mm short at
 * 116.4198, the upright one starting 10 mm up at -212.5335, and a new line
 * between exactly those two points.  The distance is therefore 寸法 over the
 * layer group's scale, along each line from the crossing.
 *
 * Both of the old lines are written down cut end first -- the level one's
 * ends came back swapped -- so that is how they are rewritten here. */
static void mentori(jw_drawing *d, int a, double ax, double ay,
                    int b, double bx, double by)
{
    jw_obj *p = &d->obj[a], *q = &d->obj[b];
    double pdx, pdy, qdx, qdy, den, tp, tq, ix, iy, cp, cq;
    double plen, qlen, dist, pux, puy, qux, quy, px, py, qx, qy;
    double psi, sinpsi, t, ex[2], ey[2];
    double kpx, kpy, kqx, kqy;
    jw_obj was_p, was_q;
    const char *sz = jw_cmd_box(1411);
    int wg = 0, i, extra = 0, lo, hi;
    op_t *rec;
    jw_obj *n;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    dist = box_num(sz, 0.0);
    if (mt_mode != 1692 && dist <= 0.0 && sz && *sz)
        return;                 /* a size of 0: nothing to cut */
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        dist /= d->group[wg].scale;
    if (!sz || !*sz)
        dist = 0.1;             /* a blank box cuts 0.1 (fuzz cases 1, 2, 16) */
    pdx = p->d[2] - p->d[0];
    pdy = p->d[3] - p->d[1];
    qdx = q->d[2] - q->d[0];
    qdy = q->d[3] - q->d[1];
    den = pdx * qdy - pdy * qdx;
    if (den == 0.0)
        return;
    tp = ((q->d[0] - p->d[0]) * qdy - (q->d[1] - p->d[1]) * qdx) / den;
    tq = ((q->d[0] - p->d[0]) * pdy - (q->d[1] - p->d[1]) * pdx) / den;
    ix = p->d[0] + tp * pdx;
    iy = p->d[1] + tp * pdy;
    if (!(fabs(ix) < 1e9 && fabs(iy) < 1e9))
        return;                 /* nearly parallel: no corner */
    cp = ((ax - p->d[0]) * pdx + (ay - p->d[1]) * pdy) / (pdx * pdx + pdy * pdy);
    cq = ((bx - q->d[0]) * qdx + (by - q->d[1]) * qdy) / (qdx * qdx + qdy * qdy);
    plen = sqrt(pdx * pdx + pdy * pdy);
    qlen = sqrt(qdx * qdx + qdy * qdy);
    if (plen == 0.0 || qlen == 0.0)
        return;
    /* the way each line runs from the crossing towards the end that stays */
    pux = (cp < tp ? -pdx : pdx) / plen;
    puy = (cp < tp ? -pdy : pdy) / plen;
    qux = (cq < tq ? -qdx : qdx) / qlen;
    quy = (cq < tq ? -qdy : qdy) / qlen;
    /* 保つ側の二本のあいだの角 ψ。**原典に五つの指定を二本の交わり（鋭角・
     * 鈍角・非対称）で引かせた答え**（tools/probe173〜176.sh、
     * decomp/res/p173〜p176_*.jww）から:
     *   角面（辺寸法） 両方を交点から 寸法 だけ削る
     *   角面（面寸法） 削る長さ t は、面（新しい線）の長さが 寸法 になる
     *                  t = 寸法 / (2 sin(ψ/2))
     *   丸面          寸法 が半径、t = 半径 / tan(ψ/2)。弧は両方に接する
     *   Ｌ面          t は 0.1 mm（箱は効かない）。削った二つの端から平行四辺形の
     *                  残り二辺で「Ｌ」を引く
     *   楕円面        寸法 が長半径 a。交点から二本に沿う t を共役半径とする
     *                  楕円の四分の一。a = t(√(1+s)+√(1-s))/√2、s = sin ψ */
    sinpsi = fabs(pux * quy - puy * qux);
    psi = acos(pux * qux + puy * quy);
    if (sinpsi < 1e-9)
        return;                 /* 一直線（同じ向き・逆向き）は何もしない */
    switch (mt_mode) {
    case 1690:
        t = dist / (2.0 * sin(psi / 2.0));
        break;
    case 1691:
        t = dist / tan(psi / 2.0);
        break;
    case 1692:
        t = 0.1;
        break;
    case 1693:
        t = dist * sqrt(2.0)
            / (sqrt(1.0 + sinpsi) + sqrt(1.0 - sinpsi));
        break;
    default:
        t = dist;
    }
    /* a cut longer than the line that is left does nothing (fuzz case 67) */
    if (t > (cp < tp ? tp : 1.0 - tp) * plen + 1e-9
        || t > (cq < tq ? tq : 1.0 - tq) * qlen + 1e-9)
        return;
    px = ix + pux * t;
    py = iy + puy * t;
    qx = ix + qux * t;
    qy = iy + quy * t;
    (void)ex; (void)ey;

    /* cut end first, then the end that stays */
    kpx = cp < tp ? p->d[0] : p->d[2];
    kpy = cp < tp ? p->d[1] : p->d[3];
    kqx = cq < tq ? q->d[0] : q->d[2];
    kqy = cq < tq ? q->d[1] : q->d[3];
    was_p = *p;
    was_q = *q;

    /* The two cut lines do not stay where they were: driving 面取 on a
       rectangle's corner in the original put them at the **end** of the
       drawing, after the untouched sides, in the order they were picked --
       the same 消して末尾に足す the decompilation notes for コーナー and
       伸縮 elsewhere turned out not to hold for コーナー処理 (which keeps
       its two lines in place, tools/probe-corner.sh) but does for 面取
       (tools/fzcheck.py cases 2, 16, 55, 61, 70: a rectangle's sides come
       back top, the untouched one, the two cut ones, the chamfer). */
    rec = op_new();
    lo = a < b ? a : b;
    hi = a < b ? b : a;
    op_keep(rec, d, hi, 1);
    jw_remove(d, hi);
    op_keep(rec, d, lo, 1);
    jw_remove(d, lo);

    n = jw_add(d, JW_SEN);
    if (n) {
        *n = was_p;
        n->d[0] = px; n->d[1] = py; n->d[2] = kpx; n->d[3] = kpy;
    }
    n = jw_add(d, JW_SEN);
    if (n) {
        *n = was_q;
        n->d[0] = qx; n->d[1] = qy; n->d[2] = kqx; n->d[3] = kqy;
    }

    if (mt_mode == 1691 || mt_mode == 1693) {
        double cx, cy, a0, sw;

        n = jw_add(d, JW_ENKO);
        if (n) {
            double ux = pux + qux, uy = puy + quy;
            double ul = sqrt(ux * ux + uy * uy);

            n->n = 0;
            n->d[6] = 1.0;
            if (mt_mode == 1691) {
                double r = dist;
                double ang;

                cx = ix + ux / ul * (t * t + r * r > 0.0
                                      ? sqrt(t * t + r * r) : 0.0);
                cy = iy + uy / ul * sqrt(t * t + r * r);
                /* 弧は第二の線の接点から反時計回りに第一の線の接点まで
                   （振りは π - ψ。向きが逆なら始まりと終わりを入れ替える） */
                sw = PI - psi;
                a0 = atan2(qy - cy, qx - cx);
                ang = atan2(py - cy, px - cx) - a0;
                while (ang < -PI) ang += 2.0 * PI;
                while (ang > PI) ang -= 2.0 * PI;
                if (fabs(ang - sw) > 1e-6)
                    a0 = atan2(py - cy, px - cx);
                n->d[0] = cx;
                n->d[1] = cy;
                n->d[2] = r;
                n->d[3] = a0;
                n->d[4] = sw;
                n->d[5] = 0.0;
            } else {
                double aa = dist, bb, tilt;

                cx = ix + t * ux;
                cy = iy + t * uy;
                bb = aa * (sqrt(1.0 + sinpsi) - sqrt(1.0 - sinpsi))
                     / (sqrt(1.0 + sinpsi) + sqrt(1.0 - sinpsi));
                tilt = atan2(uy, ux);
                if (psi <= PI / 2.0) {
                    a0 = 3.0 * PI / 4.0;        /* 交点の側は 180 度 */
                } else {
                    tilt += PI / 2.0;           /* 長軸は二等分線に直角 */
                    a0 = PI / 4.0;              /* 交点の側は 90 度 */
                }
                while (tilt > PI) tilt -= 2.0 * PI;
                while (tilt <= -PI) tilt += 2.0 * PI;
                n->d[0] = cx;
                n->d[1] = cy;
                n->d[2] = aa;
                n->d[3] = a0;
                n->d[4] = PI / 2.0;
                n->d[5] = tilt;
                n->d[6] = bb / aa;
            }
            if (rec)
                rec->n = 3;         /* the two re-added lines, and the arc */
        }
        return;
    }
    n = jw_add(d, JW_SEN);
    if (n) {
        n->d[0] = px;
        n->d[1] = py;
        n->d[2] = qx;
        n->d[3] = qy;
        if (mt_mode == 1692) {
            /* Ｌ: 二つの端から、もう一方の線の向きへ 0.1 だけ進んだ角で折る */
            double cx = px + qx - ix, cy = py + qy - iy;
            n->d[0] = px;
            n->d[1] = py;
            n->d[2] = cx;
            n->d[3] = cy;
            n = jw_add(d, JW_SEN);
            if (n) {
                n->d[0] = qx;
                n->d[1] = qy;
                n->d[2] = cx;
                n->d[3] = cy;
                extra = 1;
            }
        }
        /* the new line belongs to the same step as the two that were cut,
           so one press of 元に戻る takes the whole chamfer back -- along
           with the two re-added lines themselves */
        if (rec)
            rec->n = 3 + extra;
    }
}

/* 分割（等距離分割）between two lines.
 *
 * The original was given two lines and 分割数 4: it left three lines between
 * them, evenly spaced.  A second run with two lines that were neither
 * parallel nor the same length settles what "evenly" means -- each new line
 * is the two ends of the picked ones walked towards each other: start to
 * start and end to end, k/n of the way along.  Both of its dividers came out
 * exactly there.
 *
 * (The original wrote that pair the other way round, end first; which way it
 * picks is not worked out, and it makes no difference to the line.) */
/*
 * The 分割数 need not be a whole number, and the decompilation says what
 * the original makes of one that is not.  FUN_007668f0 reads the box: a
 * number of 1.01 or less is raised to 1.01 (and written back into the box),
 * and more than 10000 is refused with 5613 「分割数が多すぎます。」.  The
 * line-to-line case, FUN_0075d660, then steps (end - start) / n at a time
 * and draws (int)n - 1 lines -- one more when n has a fractional part
 * (FUN_007674b0: `if (1e-07 < frac) count++`), each step weighted 1
 * (FUN_007697b0 with a zero slope).  So 2.5 gives two lines, at 0.4 and 0.8
 * of the way, the last gap the short one; and 4 gives the three at the
 * quarters it always did.
 *
 * A negative 分割数 is 逆分割 (it sets +0x7e98): |n| divisions whose gaps
 * shrink evenly from 1 to r, r being the fraction of |n| (bk_read_n,
 * bk_total).  An empty box is not done: FUN_0058cc80 may read it as 0 and
 * so as 1.01 -- that has not been asked.
 * (This used to take the box through atoi and refuse anything outside
 * 2..1000, so 2.5 drew one line at the half and 5000 drew nothing.)
 */
/* 分割数 (1411) を読む。空欄は 2、0 は 0 件、正で 1.01 以下は 1.01 に戻して
 * 箱へ書き戻す（原典 FUN_007668f0）。負なら逆分割（bk_neg）で、-2.01 より
 * 0 に近ければ -2.01 に直して書き戻し、r（bk_r）は |n| の端数（0.001 未満は
 * 1 ＝ 等分と同じ）。|n| が 10000 を超えれば箱に "10000"（負は "-10000"）を
 * 書いて 0 件にする。*count に floor(|n|)-1（逆分割でなく端数があれば +1）を
 * 書き、戻り値は割付の全長（bk_total、0 件で終わるときは 0.0）。k 番目の位置は
 * bk_t(k, 戻り値)。逆コンパイルの読み、逆分割は原典では押していない。 */
/* FUN_007674b0: n（|分割数|）と *count（floor(n)-1）から割付の全長を返す。
 * 逆分割でなければ 端数があれば *count を一つ足して n のまま。逆分割なら
 * 刻み bk_step=(1-r)/count、全長 (count+1) - count(count+1)/2 × 刻み。
 * （基本設定に無い設定 S_COMM_7 の 8 番目 DAT_00a0bfa8 が 1 で 線長割合でなく
 * 0.01≦r≦0.99 なら等比 (1-r^(count+1))/(1-r) になるが、原典の既定は 0 で
 * 移植は .jwf からこれを読まないので、等差だけ。） */
static double bk_total(double n, int *count)
{
    if (!bk_neg) {
        if (fabs(n - (int)n) > 1e-07)
            (*count)++;
        return n;
    }
    if (*count < 1) {           /* 線長割合で 1.01 が 1 になったとき: 一本も無い */
        *count = 0;
        return n;
    }
    bk_step = (1.0 - bk_r) / (double)*count;
    return ((double)*count + 1.0) - ((double)((*count + 1) * *count) / 2.0) * bk_step;
}

/* FUN_007697b0（等差）: i 番目（1 始まり）の間隔。逆分割でなければ 1 */
static double bk_w(int i)
{
    return bk_neg ? 1.0 - ((double)i - 1.0) * bk_step : 1.0;
}

/* k 番目の分割の位置（0〜1）。bk_read_n が返した全長 n で割った、間隔の和 */
static double bk_t(int k, double n)
{
    if (!bk_neg)
        return (double)k / n;
    return ((double)k - bk_step * (double)k * ((double)k - 1.0) / 2.0) / n;
}

static double bk_read_n(int *count)
{
    const char *ns = jw_cmd_box(1411);
    double n = box_num(ns, 0.0);

    /* 0 件の答えは bk_total を通らないので、ここで 0 件・逆分割でない形にする */
    bk_neg = 0;
    bk_r = 1.0;
    if (!ns || !*ns)
        n = 2.0;                /* the original divides in two when the box is blank */
    if (n == 0.0) {
        *count = 0;
        return 0.0;
    }
    if (n < 0.0) {
        /* 逆分割（FUN_007668f0）: -2.01 より 0 に近ければ -2.01 に直して書き戻す */
        bk_neg = 1;
        if (-2.01 < n) {
            n = -2.01;
            box_put(1411, "-2.01");
        }
    } else if (n <= 1.01) {
        char t[16];

        n = 1.01;
        snprintf(t, sizeof t, "%.2f", n);
        box_put(1411, t);
    }
    if (fabs(n) > 10000.0) {
        box_put(1411, n < 0.0 ? "-10000" : "10000");
        bk_neg = 0;
        *count = 0;
        return 0.0;
    }
    n = fabs(n);
    if (bk_neg && 0.001 <= n - (double)(int)n)
        bk_r = n - (double)(int)n;
    *count = (int)n - 1;
    return bk_total(n, count);
}

/* 二本の線 p・q の端の組み方。二本が交わるところ（平行なら中点）を境に
 * クリック (ax,ay)・(bx,by) の落ちた側どうしを組み、長い横木を先にする
 * （tools/fzcheck.py の fuzz ケース 5, 9, 11-13, 18-21, 23, 26, 68）。
 * a[0..3]・b[0..3] に 始点x・始点y・終点x・終点y を返す。 */
static void bk_pair_ends(const jw_obj *p, const jw_obj *q, double ax, double ay,
                         double bx, double by, double *a, double *b)
{
    double ax0 = p->d[0], ay0 = p->d[1], ax1 = p->d[2], ay1 = p->d[3];
    double bx0 = q->d[0], by0 = q->d[1], bx1 = q->d[2], by1 = q->d[3];
    double adx = ax1 - ax0, ady = ay1 - ay0, bdx = bx1 - bx0, bdy = by1 - by0;
    double den = adx * bdy - ady * bdx;
    double ta = ((ax - ax0) * adx + (ay - ay0) * ady) / (adx * adx + ady * ady + 1e-30);
    double tb = ((bx - bx0) * bdx + (by - by0) * bdy) / (bdx * bdx + bdy * bdy + 1e-30);
    double ip = 0.5, iq = 0.5, tx, ty;
    int flipb;

    if (fabs(den) > 1e-9 * (adx * adx + ady * ady + 1e-30)) {
        ip = ((bx0 - ax0) * bdy - (by0 - ay0) * bdx) / den;
        iq = ((bx0 - ax0) * ady - (by0 - ay0) * adx) / den;
    }
    flipb = (ta >= ip) != (tb >= iq);
    if (den == 0.0 || fabs(den) <= 1e-9 * (adx * adx + ady * ady + 1e-30)) {
        /* parallel: the pairing that does not cross (fuzz case 68) */
        double same = hypot(bx0 - ax0, by0 - ay0) + hypot(bx1 - ax1, by1 - ay1);
        double flip = hypot(bx1 - ax0, by1 - ay0) + hypot(bx0 - ax1, by0 - ay1);

        flipb = flip < same - 1e-9;
    }
    /* 逆分割 (bk_gyaku、+0xa8): 組んだあと、長い横木を先にする前に Ｂ の端を
       入れ替える（FUN_0075d660 の 0x75e4be、馬目地 +0x7eb4 のときは見ない） */
    if (bk_gyaku)
        flipb = !flipb;
    if (flipb) {
        tx = bx0; ty = by0;
        bx0 = bx1; by0 = by1;
        bx1 = tx; by1 = ty;
    }
    if (hypot(bx0 - ax0, by0 - ay0) < hypot(bx1 - ax1, by1 - ay1) - 1e-6) {
        tx = ax0; ty = ay0;
        ax0 = ax1; ay0 = ay1;
        ax1 = tx; ay1 = ty;
        tx = bx0; ty = by0;
        bx0 = bx1; by0 = by1;
        bx1 = tx; by1 = ty;
    }
    a[0] = ax0; a[1] = ay0; a[2] = ax1; a[3] = ay1;
    b[0] = bx0; b[1] = by0; b[2] = bx1; b[3] = by1;
}

/* 割付 が効くか（等角度分割 は 0xb8 が立って 割付 を切る。FUN_00766460）。 */
static int bk_waritsuke_on(void)
{
    return jw_cmd_bar_check(1324) > 0 && bk_mode != 1690;
}

/* 線と線（点は両端が同じ点の線）の 割付 の歩き。原典 FUN_0075d660 の 0x7e84 枝
 * （_unassigned.c 312176〜312300）。A の端 A0・A1 を B の端 B0・B1 へ向けて、
 * 割付距離 dist ずつ進めた線を置く。
 *   L    = |A0B0|。A が B に平行（点も）なら 進める歩幅は dist*L/垂直距離
 *          （＝ B の線からの垂直距離で dist ずつ）。A が B の線の上なら 何もしない。
 *   振分 = 最初の一歩を (余り+歩幅)/2/歩幅 倍（余りは L を歩幅で割ったあまり）。
 *   割付距離以下 = L'（平行なら垂直距離、でなければ L）を ceil(L'/dist) 等分。
 *   A0 が L に届いたら止める（端の線は置かない）。
 * 実測（2026-10-14）: 点 P=(-155.51,26.33)→線 B=(-106.53,56.94)-(-106.53,-47.14)、
 * dist 15 で x=-140.51・-125.51・-110.51 の 3 本（P+(B-P)*k*15/48.98、
 * 48.98 は P から B の線までの垂直距離。decomp/res/bk_w12.jww）。 */
static int bk_fan_walk(jw_drawing *d, const double *A, const double *B)
{
    double dist = box_mm(d, 1412);
    double bdx = B[2] - B[0], bdy = B[3] - B[1], bl = hypot(bdx, bdy);
    double ya0, ya1, perp, L, step, dl[4], m[4];
    int parallel, made = 0, k, i;

    if (dist < 1e-7)
        return 0;
    if (bl >= 1e-9) {
        ya0 = ((A[0] - B[0]) * bdy - (A[1] - B[1]) * bdx) / bl;
        ya1 = ((A[2] - B[0]) * bdy - (A[3] - B[1]) * bdx) / bl;
    } else {
        /* B が点（線 A ＋ 点 E の扇）: 線 A を枠にして E までの垂直距離を測る */
        double adx = A[2] - A[0], ady = A[3] - A[1], al = hypot(adx, ady);

        if (al < 1e-9)
            return 0;
        ya0 = ((B[0] - A[0]) * ady - (B[1] - A[1]) * adx) / al;
        ya1 = ya0;
    }
    if (fabs(ya0) < 1e-7 && fabs(ya1) < 1e-7)
        return 0;
    parallel = fabs(ya0 - ya1) < 1e-7;
    perp = fabs(ya0);
    L = hypot(B[0] - A[0], B[1] - A[1]);
    if (L < 1e-9)
        return 0;
    step = parallel ? dist * L / perp : dist;
    if (!(step + 1e-7 < L))
        return 0;
    for (i = 0; i < 4; i++) {
        dl[i] = (B[i] - A[i]) * step / L;
        m[i] = A[i];
    }
    if (jw_cmd_bar_check(1326) > 0) {
        double lp = parallel ? perp : L, q = lp / dist;
        int cnt = (int)q;

        if (fabs(q - (double)cnt) > 1e-7)
            cnt++;
        if (cnt < 1)
            cnt = 1;
        for (i = 0; i < 4; i++)
            dl[i] = (B[i] - A[i]) / (double)cnt;
    } else if (jw_cmd_bar_check(1325) > 0) {
        double rem = L, fr;

        while (step <= rem + 1e-7)
            rem -= step;
        if (1e-7 < rem && rem < step - 1e-7) {
            fr = ((step - rem) / 2.0) / step;
            for (i = 0; i < 4; i++)
                m[i] -= dl[i] * fr;
        }
    }
    for (k = 1; k < 10001; k++) {
        double dd;

        for (i = 0; i < 4; i++)
            m[i] += dl[i];
        dd = hypot(m[0] - A[0], m[1] - A[1]);
        if (L - 1e-7 <= dd)
            break;
        if (dd > 1e-7) {
            jw_obj *o = jw_add(d, JW_SEN);

            if (!o)
                break;
            o->d[0] = m[0];
            o->d[1] = m[1];
            o->d[2] = m[2];
            o->d[3] = m[3];
            made++;
        }
    }
    return made;
}

static void bunkatsu(jw_drawing *d, int a, int b, double ax, double ay,
                     double bx, double by)
{
    const jw_obj *p = &d->obj[a], *q = &d->obj[b];
    int k, count, made = 0;
    double n;
    double ax0, ay0, ax1, ay1, bx0, by0, bx1, by1;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    n = bk_read_n(&count);
    if (n <= 0.0)
        return;
    if (bk_mode == 1690) {
        /* 等角度分割 (1690): 二本が交わっていれば、交点から保つ側の二本の
         * あいだの角を n 等分する線を引く。長さは k 本目を
         * （P の保つ長さ）から（Q の保つ長さ）へ k/n だけ進めたもの
         * （tools/probe178.sh の答えで 4 分割・3 分割とも合う）。
         * 平行なら等距離分割と同じ */
        double pdx = p->d[2] - p->d[0], pdy = p->d[3] - p->d[1];
        double qdx = q->d[2] - q->d[0], qdy = q->d[3] - q->d[1];
        double den = pdx * qdy - pdy * qdx;
        /* nearly parallel lines cross a long way off: a hair's breadth
           of den put the crossing at 1e15 and the lines came out with
           coordinates no drawing can hold (tests/fail_test.c's
           press_everything found it).  Past a sheet's reach they are
           parallel, which 等距離分割 handles. */
        double tp0 = den != 0.0
            ? ((q->d[0] - p->d[0]) * qdy - (q->d[1] - p->d[1]) * qdx) / den : 0.0;
        int crosses = den != 0.0
            && fabs(p->d[0] + tp0 * pdx) < 1e8 && fabs(p->d[1] + tp0 * pdy) < 1e8;

        if (crosses) {
            double tp = ((q->d[0] - p->d[0]) * qdy - (q->d[1] - p->d[1]) * qdx) / den;
            double tq = ((q->d[0] - p->d[0]) * pdy - (q->d[1] - p->d[1]) * pdx) / den;
            double ix = p->d[0] + tp * pdx, iy = p->d[1] + tp * pdy;
            double cp = ((ax - p->d[0]) * pdx + (ay - p->d[1]) * pdy)
                        / (pdx * pdx + pdy * pdy);
            double cq = ((bx - q->d[0]) * qdx + (by - q->d[1]) * qdy)
                        / (qdx * qdx + qdy * qdy);
            /* 保つ側の端 */
            double kpx = cp < tp ? p->d[0] : p->d[2], kpy = cp < tp ? p->d[1] : p->d[3];
            double kqx = cq < tq ? q->d[0] : q->d[2], kqy = cq < tq ? q->d[1] : q->d[3];
            double lp = sqrt((kpx - ix) * (kpx - ix) + (kpy - iy) * (kpy - iy));
            double lq = sqrt((kqx - ix) * (kqx - ix) + (kqy - iy) * (kqy - iy));
            double a0 = atan2(kpy - iy, kpx - ix), a1 = atan2(kqy - iy, kqx - ix);
            double da = a1 - a0;

            while (da > PI) da -= 2.0 * PI;
            while (da <= -PI) da += 2.0 * PI;
            for (k = 1; k <= count; k++) {
                double t = bk_t(k, n), ang = a0 + da * t, len = lp + (lq - lp) * t;
                jw_obj *o = jw_add(d, JW_SEN);

                if (!o)
                    break;
                o->d[0] = ix;
                o->d[1] = iy;
                o->d[2] = ix + len * cos(ang);
                o->d[3] = iy + len * sin(ang);
                made++;
            }
            op_push(made);
            return;
        }
    }
    if (bk_senchou) {
        /* 線長割合分割 (+0x7eb0、FUN_0075d660): 短い方を Ｂ にして（Ａ が短ければ
           二本を入れ替える）、割合 |Ｂ|/|Ａ| が 1 でなければ 分割数を floor(|n|)
           にし、箱に -(分割数＋割合) を書いて（%.10lg、FUN_0058c7f0）その割合で
           逆分割する。逆コンパイルの読み、原典では押していない。 */
        double la = hypot(p->d[2] - p->d[0], p->d[3] - p->d[1]);
        double lb = hypot(q->d[2] - q->d[0], q->d[3] - q->d[1]), ratio = 0.0;

        if (la < lb) {
            const jw_obj *t = p;
            double tx = ax, ty = ay, tl = la;

            p = q;
            q = t;
            ax = bx; ay = by;
            bx = tx; by = ty;
            la = lb;
            lb = tl;
        }
        if (1e-07 < la) {
            ratio = lb / la;
            if (fabs(fabs(ratio) - 1.0) <= 1e-07)
                ratio = 0.0;
        }
        if (1e-07 < ratio) {
            char t[40];

            /* n は全長なので、分割数の整数部は count から戻す */
            n = bk_neg ? (double)(count + 1) : (double)(int)n;
            snprintf(t, sizeof t, "%.10g", -(n + ratio));
            box_put(1411, t);
            bk_r = ratio;
            bk_neg = 1;
            count = (int)n - 1;
            n = bk_total(n, &count);
        }
    }
    {
        double aa[4], bb[4];

        bk_pair_ends(p, q, ax, ay, bx, by, aa, bb);
        ax0 = aa[0]; ay0 = aa[1]; ax1 = aa[2]; ay1 = aa[3];
        bx0 = bb[0]; by0 = bb[1]; bx1 = bb[2]; by1 = bb[3];
    }
    for (k = 1; k <= count; k++) {
        double t = bk_t(k, n);
        jw_obj *o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->d[0] = ax0 + (bx0 - ax0) * t;
        o->d[1] = ay0 + (by0 - ay0) * t;
        o->d[2] = ax1 + (bx1 - ax1) * t;
        o->d[3] = ay1 + (by1 - ay1) * t;
        made++;
    }
    op_push(made);
}

/* 分割始点 (R) で指示した点 Ｐ から、線 Ｂ (または先に (L) で指示した線 Ａ) へ
 * 扇に引く。新しい線は P+(B0-P)k/n 〜 P+(B1-P)k/n（k=1..n-1、n は 1411）。
 * 線 A を先に (L) で指示し点 E をあとから (R) で指示したときも「E から A への
 * 同じ扇」（原典の案内文どおり、式はどちらが先でも同じ）。
 *
 * 原典 tools/jwdraw.ps1 を直接叩いた実測（2026-10-13）: 点 P=(-155.51,26.3265)
 * （線の端）・線 B=(-155.51,-4.28571)-(-94.2857,-4.28571)、分割数 3 で
 * 新しい線 2 本 (-155.51,16.1224)-(-135.102,16.1224)・
 * (-155.51,5.91837)-(-114.694,5.91837) ── 上の式とぴったり合う。 */
static void bk_fan_line(jw_drawing *d, double px, double py, int line_idx)
{
    jw_obj bcopy = d->obj[line_idx];    /* a copy: jw_add below may move the array */
    const jw_obj *b = &bcopy;
    int count, k, made = 0;
    double n;

    if (bk_waritsuke_on()) {
        /* 割付: 点を 両端が同じ点の線として 線 B へ向けて歩く（bk_fan_walk） */
        double aa[4], bb[4];

        aa[0] = aa[2] = px;
        aa[1] = aa[3] = py;
        bb[0] = b->d[0]; bb[1] = b->d[1]; bb[2] = b->d[2]; bb[3] = b->d[3];
        op_push(bk_fan_walk(d, aa, bb));
        return;
    }
    n = bk_read_n(&count);
    if (n <= 0.0)
        return;
    {   /* 点が線の延長上にあれば 扇は 同じ線の上に重なるだけ: 原典は何も作らない（ファジング s23_21） */
        double bx = b->d[2] - b->d[0], by = b->d[3] - b->d[1], bl = hypot(bx, by);

        if (bl > 1e-9 && fabs(((px - b->d[0]) * by - (py - b->d[1]) * bx) / bl) < 1e-7)
            return;
    }
    for (k = 1; k <= count; k++) {
        double t = bk_t(k, n);
        jw_obj *o = jw_add(d, JW_SEN);

        if (!o)
            break;
        o->d[0] = px + (b->d[0] - px) * t;
        o->d[1] = py + (b->d[1] - py) * t;
        o->d[2] = px + (b->d[2] - px) * t;
        o->d[3] = py + (b->d[3] - py) * t;
        made++;
    }
    op_push(made);
}

/* 線 A (L)＋点 E (R): 原典は A を始め、E（両端が同じ点の線）を終わりとして歩く
 * （円 A ＋ 点 E の 割付 の実測、decomp/res/bk_cptE.jww、と同じ向き。分割数 のときは
 * 点 P＋線 B と集合は同じで、並びだけが逆）。 */
static void bk_fan_from_line(jw_drawing *d, int line_idx, double ex, double ey)
{
    jw_obj acopy = d->obj[line_idx];    /* a copy: jw_add below may move the array */
    const jw_obj *a = &acopy;
    int count, k, made = 0;
    double n;

    if (bk_waritsuke_on()) {
        double aa[4], bb[4];

        aa[0] = a->d[0]; aa[1] = a->d[1]; aa[2] = a->d[2]; aa[3] = a->d[3];
        bb[0] = bb[2] = ex;
        bb[1] = bb[3] = ey;
        op_push(bk_fan_walk(d, aa, bb));
        return;
    }
    n = bk_read_n(&count);
    if (n <= 0.0)
        return;
    for (k = 1; k <= count; k++) {
        double t = bk_t(k, n);
        jw_obj *o = jw_add(d, JW_SEN);

        if (!o)
            break;
        o->d[0] = a->d[0] + (ex - a->d[0]) * t;
        o->d[1] = a->d[1] + (ey - a->d[1]) * t;
        o->d[2] = a->d[2] + (ex - a->d[2]) * t;
        o->d[3] = a->d[3] + (ey - a->d[3]) * t;
        made++;
    }
    op_push(made);
}

/* 円の扇の端の一つ。原典 FUN_0075b6c0 は 円の五つの値（半径・扁平・開き・傾き・
 * 始め）を読み、開きが負なら 開き=-開き・始め=始め-開き に直し、始めを
 * (π, 3π] に畳んでから k/n（または割付の歩み）で補間する。点は半径 0 で、
 * 角度の値は相手の円のものを借りる。 */
typedef struct { double x, y, r, start, sweep, tilt, flat; } bk_circ;

static void bk_circ_of(bk_circ *c, const jw_obj *o)
{
    c->x = o->d[0];
    c->y = o->d[1];
    c->r = o->d[2];
    c->start = o->d[3];
    c->sweep = o->d[4];
    c->tilt = o->d[5];
    c->flat = o->d[6];
    if (c->sweep <= 0.0) {
        c->sweep = -c->sweep;
        c->start -= c->sweep;
    }
    while (c->start > PI)
        c->start -= 2.0 * PI;
    while (c->start <= PI)
        c->start += 2.0 * PI;
}

static double bk_wrap_pi(double a)
{
    while (a > PI)
        a -= 2.0 * PI;
    while (a <= -PI)
        a += 2.0 * PI;
    return a;
}

/* 補間の途中の円を一つ置く（原典の 0x42f5e0〜0x430200 の並び）。 */
static int bk_circ_put(jw_drawing *d, const bk_circ *c)
{
    jw_obj *o;

    if (c->r < 1e-7 || c->flat < 0.01 || c->flat > 100.0)
        return 0;
    o = jw_add(d, JW_ENKO);
    if (!o)
        return 0;
    o->d[0] = c->x;
    o->d[1] = c->y;
    o->d[2] = c->r;
    o->d[3] = bk_wrap_pi(c->start);
    o->d[4] = c->sweep;
    o->d[5] = bk_wrap_pi(c->tilt);
    o->d[6] = c->flat;
    o->n = fabs(c->sweep - 2.0 * PI) >= 1e-7 ? 0 : 1;
    return 1;
}

/* 分割始点 (R)＋円 Ｂ (L)、円 Ａ (L)＋円 Ｂ (L)、円 Ａ (L)＋点 Ｅ (R) に共通の
 * 円の扇。Ａ（円 または 点）から Ｂ へ、中心・半径・扁平・開き・傾き・始めを
 * 線形に進めた円をつくる。点は半径 0 の円として渡す（a==NULL なら (ax,ay)）。
 *
 * 分割数 のとき: n-1 個、k/n ずつ。
 * 割付 のとき（原典 FUN_0075b6c0 の 0x7e84 枝、2026-10-14 実測 decomp/res/bk_w1.jww）:
 *   中心どうしの隔たり L を 割付距離 dist ずつ歩き（L の外には出ない）、半径ほかは
 *   L/dist 歩みで B に着く割合で進める。例: 円A 中心(-33.06,-96.12) 半径36.73・
 *   円B 中心(89.39,-96.12) 半径18.37、dist 30 で 中心 -3.06・26.94・56.94・86.94、
 *   半径 32.23・27.73・23.23・18.73。中心が重なるときは 半径の差 |ΔR| を L に使う。
 *   振分 は最初の一歩だけ (rem+dist)/2/dist 倍（rem = L を dist で割った余り）、
 *   割付距離以下 は dist = L/ceil(L/dist)。歩みが 1.001 に満たなければ 5617 の
 *   「間隔が…」ではなく 0x15f1 で何も置かない。 */
static void bk_circle_lerp(jw_drawing *d, const jw_obj *a, double ax, double ay,
                            const jw_obj *b, double bx, double by)
{
    bk_circ A = { 0 }, B = { 0 }, C = { 0 };
    int made = 0, k;

    if (b)
        bk_circ_of(&B, b);
    else {
        B.x = bx; B.y = by; B.r = 0.0;
    }
    if (a)
        bk_circ_of(&A, a);
    else {
        A.x = ax; A.y = ay; A.r = 0.0;
    }
    if (!a) {
        A.start = B.start; A.sweep = B.sweep; A.tilt = B.tilt; A.flat = B.flat;
    }
    if (!b) {
        B.start = A.start; B.sweep = A.sweep; B.tilt = A.tilt; B.flat = A.flat;
    }
    if (bk_waritsuke_on()) {
        double dist = box_mm(d, 1412);
        double dx = B.x - A.x, dy = B.y - A.y, L = hypot(dx, dy);
        int conc = L < 1e-6;
        double cc, sx, sy, first = 1.0, rem;

        if (dist < 1e-7)
            return;
        if (conc)
            L = fabs(B.r - A.r);
        if (L < 1e-6 && conc)
            return;
        if (jw_cmd_bar_check(1326) > 0) {
            double q = L / dist;
            int m = (int)q;

            if (fabs(q - (double)m) > 1e-7)
                m++;
            if (m < 1)
                m = 1;
            dist = L / (double)m;
        }
        cc = L / dist;
        if (cc < 1.001)
            return;
        sx = conc ? 0.0 : dx * dist / L;
        sy = conc ? 0.0 : dy * dist / L;
        if (jw_cmd_bar_check(1325) > 0 && jw_cmd_bar_check(1326) <= 0) {
            rem = L;
            while (dist <= rem + 1e-7)
                rem -= dist;
            if (1e-7 < rem && rem < dist - 1e-7) {
                rem += dist;
                first = (rem / 2.0) / dist;
                if (first < 1e-7 || fabs(first - 1.0) < 1e-7)
                    first = 1.0;
            }
        }
        C = A;
        for (k = 1; k < 10001; k++) {
            double w = k == 1 ? first : 1.0;
            double dr = (B.r - A.r) / cc;

            C.x += sx * w;
            C.y += sy * w;
            C.r += dr * w;
            if (C.r < 1e-7 && dr < 0.0)
                break;
            if (C.r >= 1e-7) {
                C.tilt += (B.tilt - A.tilt) / cc * w;
                C.start += (B.start - A.start) / cc * w;
                C.sweep += (B.sweep - A.sweep) / cc * w;
                C.flat += (B.flat - A.flat) / cc * w;
                if (C.flat >= 0.01 && C.flat <= 100.0) {
                    if (!conc) {
                        if (L - 1e-7 <= hypot(C.x - A.x, C.y - A.y))
                            break;
                    } else if (B.r <= A.r) {
                        if (A.r <= C.r || C.r <= B.r)
                            break;
                    } else if (C.r <= A.r || B.r <= C.r) {
                        break;
                    }
                    made += bk_circ_put(d, &C);
                }
            }
        }
        op_push(made);
        return;
    } else {
        int count;
        double n = bk_read_n(&count);

        if (n <= 0.0)
            return;
        for (k = 1; k <= count; k++) {
            double t = bk_t(k, n);

            C.x = A.x + (B.x - A.x) * t;
            C.y = A.y + (B.y - A.y) * t;
            C.r = A.r + (B.r - A.r) * t;
            C.tilt = A.tilt + (B.tilt - A.tilt) * t;
            C.start = A.start + (B.start - A.start) * t;
            C.sweep = A.sweep + (B.sweep - A.sweep) * t;
            C.flat = A.flat + (B.flat - A.flat) * t;
            made += bk_circ_put(d, &C);
        }
        op_push(made);
    }
}

/* 始点＋円 Ｂ (L): 中心 P+(C-P)k/n・半径 r・k/n の円（点は半径 0 の円）。
 * 円 Ａ (L)＋点 Ｅ (R) も同じ式（E が P の役）。
 *
 * 原典実測（2026-10-13）: P=(-106.531,56.9388)（線の端）・
 * 円 B 中心(58.7755,-96.1224) 半径24.4898、分割数 3 で
 * 中心(-51.4286,5.91837) 半径8.16327・中心(3.67347,-45.102) 半径16.3265 ──
 * 上の式とぴったり合う。 */
static void bk_fan_circle_pt(jw_drawing *d, double px, double py, int circ_idx)
{
    const jw_obj *c = &d->obj[circ_idx];

    bk_circle_lerp(d, 0, px, py, c, 0.0, 0.0);
}

/* 円 Ａ (L)＋円 Ｂ (L)（分割の classic な (L)(L) を円どうしにも広げたもの）。
 * 原典実測（2026-10-13）: 円Ａ 中心(-33.0612,-96.1224) 半径36.7347・
 * 円Ｂ 中心(58.7755,-96.1224) 半径24.4898、分割数 3 で
 * 中心(-2.44898,-96.1224) 半径32.6531・中心(28.1633,-96.1224) 半径28.5714 ──
 * bk_circle_lerp と同じ式（中心・半径の線形補間）で合う。 */
static void bk_circle_fan(jw_drawing *d, int a_idx, int b_idx)
{
    const jw_obj *a = &d->obj[a_idx], *b = &d->obj[b_idx];

    bk_circle_lerp(d, a, 0.0, 0.0, b, 0.0, 0.0);
}

/* 始点＋第二点 (R)(R) の状態 3（string 5360）。(R) で確定する「２点間分割」:
 * 線・円を介さず、P1 と P2 のあいだをそのまま線形補間した点を n-1 個つくる。
 *
 * 原典実測（2026-10-13）: P1=(-155.51,26.3265)・P2=(89.3878,26.3265)、
 * 分割数 4 で (-94.2857,26.3265)・(-33.0612,26.3265)・(28.1633,26.3265) ──
 * P1+(P2-P1)*k/4、k=1..3 とぴったり合う。 */
/* 分割で置く点一つ。原典 FUN_007603a0 は +0x7e80（バーの 仮点 1323 を写した
   +0x964）が立っていれば FUN_00455c40(1) で種別を仮点にしてから置く
   （CZukeiTen の 仮点 と同じ呼び出し）。 */
static int bk_put_point(jw_drawing *d, double x, double y)
{
    jw_obj *o = jw_add(d, JW_TEN);

    if (!o)
        return 0;
    o->d[0] = x;
    o->d[1] = y;
    o->n = jw_cmd_bar_check(1323) > 0;      /* 1 が仮点、0 が実点 */
    return 1;
}

/* 原典 FUN_00767660: 連続点分割の仮想の直線（下の bk_rr_finish）の上の距離 s を
 * 折れ線 bk_rr の上の点に写す。*seg（1 始まりの辺の番号）と *acc（その辺の
 * 手前までの長さ）は呼び出しを跨いで進む（s は増える一方なので戻らない）。
 * 辺の終わりを越えれば次の辺へ（`acc+len < s` の間、厳密な <）、最後の辺も
 * 越えれば 0 を返して置かない。 */
static int bk_rr_map(double s, int *seg, double *acc, double *ox, double *oy)
{
    double len, tot;
    int i = *seg;

    if (i >= bk_rr_n)
        return 0;
    len = hypot(bk_rr_x[i + 1] - bk_rr_x[i], bk_rr_y[i + 1] - bk_rr_y[i]);
    tot = *acc + len;
    while (tot < s) {
        i = ++*seg;
        *acc = tot;
        if (i >= bk_rr_n)
            return 0;
        len = hypot(bk_rr_x[i + 1] - bk_rr_x[i], bk_rr_y[i + 1] - bk_rr_y[i]);
        tot = *acc + len;
    }
    *ox = (s - *acc) * ((bk_rr_x[i + 1] - bk_rr_x[i]) / len) + bk_rr_x[i];
    *oy = (s - *acc) * ((bk_rr_y[i + 1] - bk_rr_y[i]) / len) + bk_rr_y[i];
    return 1;
}

/* ２点間分割と連続点分割の本体、原典 FUN_007603a0（_unassigned.c 312717）を
 * 写したもの。P1 から P2 へ一歩ずつ足していき（k/n を掛けるのではなく
 * 「+=」で積む、0x7603a0 の local_24/local_1c）、その位置に点を置く。rr なら
 * その位置の x − P1.x を折れ線の上の距離として bk_rr_map で写す。
 *
 *   分割数（+0x7e84==0）: 一歩は (P2−P1)/n、floor(n)−1 歩（端数があれば +1、
 *       FUN_007674b0）。逆分割（負の n、+0x7e98）なら i 歩目に
 *       FUN_007697b0 の重み bk_w(i) を掛け、全長 bk_total で割る。
 *   割付 1324（+0x7e84）: 一歩は距離 1412 の向き (P2−P1)·d/L。振分 1325
 *       （+0x7e88）なら余り rem（L から d を引けるだけ引いたもの）が
 *       1e-7 < rem < d−1e-7 のとき出発を ((d−rem)/2)/d 歩ぶん手前へずらす。
 *       割付距離以下 1326（+0x7e8c）なら歩数 m=ceil(L/d)（端数 1e-7 まで）で
 *       一歩は (P2−P1)/m。歩くたびに P1 からの距離を見て、L−1e-7 に届けば
 *       止め、1e-7 を超えていれば置く（10000 歩まで）。FUN_00766460 の
 *       とおり 1326 のときは 振分 を見ず、等角度 (1690、+0xb8≠0) のときは
 *       割付 を見ない。距離が 1e-5 以下なら FUN_007668f0 が何もしない。
 *   P1 と P2 が厳密に同じなら何もしない（FUN_00498960）。
 *   rr なら分割点より先に 折れ線の始点・終点 に点を置く（設定 +0x974 が
 *       立っているとき。どこの釦かは見つけていないが、原典の既定では
 *       立っていた ── tools/bkprobe.sh の答えで両端に点が出た）。
 *
 * 原典実測（tools/bkprobe.sh、2026-10-13。答えは decomp/res/bk_rr*.jww）:
 *   割付 4000（1/100、40mm）の２点間 (R)(R)(R): L=244.898 に 40mm おきの 6 点、
 *   両端には置かない。連続点分割の 分割数 4・割付・割付＋振分 は
 *   tests/bunkatsu_test.c の数とぴったり。戻り値は置いた数。 */
static int bk_points_between(jw_drawing *d, double p1x, double p1y,
                             double p2x, double p2y, int rr)
{
    int waritsuke_on = jw_cmd_bar_check(1324) > 0 && bk_mode != 1690;
    int count = 0, k, made = 0, seg = 1;
    double n = 0.0, dist = 0.0, acc = 0.0, L, x = p1x, y = p1y, sx, sy, ox, oy;

    if (waritsuke_on) {
        dist = box_mm(d, 1412);
        if (dist <= 1e-5)
            return 0;
    } else {
        n = bk_read_n(&count);
        if (n <= 0.0)
            return 0;
    }
    if (p1x == p2x && p1y == p2y)
        return 0;
    L = hypot(p2x - p1x, p2y - p1y);
    if (rr) {
        made += bk_put_point(d, bk_rr_x[1], bk_rr_y[1]);
        made += bk_put_point(d, bk_rr_x[bk_rr_n], bk_rr_y[bk_rr_n]);
    }
    if (!waritsuke_on) {
        sx = (p2x - p1x) / n;
        sy = (p2y - p1y) / n;
        for (k = 1; k <= count; k++) {
            x += sx * bk_w(k);
            y += sy * bk_w(k);
            if (!rr) {
                made += bk_put_point(d, x, y);
            } else if (bk_rr_map(x - p1x, &seg, &acc, &ox, &oy)) {
                made += bk_put_point(d, ox, oy);
            }
        }
        return made;
    }
    sx = (p2x - p1x) * dist / L;
    sy = (p2y - p1y) * dist / L;
    if (jw_cmd_bar_check(1326) <= 0 && jw_cmd_bar_check(1325) > 0) {
        double rem = L;

        while (dist <= rem + 1e-7)
            rem -= dist;
        if (1e-7 < rem && rem < dist - 1e-7) {
            double f = ((dist - rem) / 2.0) / dist;

            x -= sx * f;
            y -= sy * f;
        }
    }
    if (jw_cmd_bar_check(1326) > 0) {
        double r = L / dist;
        int m = (int)r;

        if (fabs(r - (double)m) > 1e-7)
            m++;
        sx = (p2x - p1x) / (double)m;
        sy = (p2y - p1y) / (double)m;
    }
    for (k = 1; k < 10001; k++) {
        double dd;

        x += sx;
        y += sy;
        dd = hypot(x - p1x, y - p1y);
        if (L - 1e-7 <= dd)
            break;
        if (dd > 1e-7) {
            if (!rr)
                made += bk_put_point(d, x, y);
            else if (bk_rr_map(x - p1x, &seg, &acc, &ox, &oy))
                made += bk_put_point(d, ox, oy);
        }
    }
    return made;
}

static void bk_two_point_plain(jw_drawing *d, double p1x, double p1y,
                                double p2x, double p2y)
{
    op_push(bk_points_between(d, p1x, p1y, p2x, p2y, 0));
}

/* 連続点分割を閉じる（原典 FUN_007668f0 の +0x138!=0 の枝）。2 点に満たなければ
 * 何もせず点列を捨てる。折れ線の長さ L を辺ごとに足し（+0x110 に積む）、
 * P1=点 1・P2=(P1.x+L, P1.y) の**仮想の水平な直線**を FUN_007603a0 に渡す
 * ── FUN_00767660 は x − P1.x だけを折れ線の上の距離として読むので、
 * 仮想の直線の上の歩みがそのまま折れ線の上の弧長になる。閉じたあとは
 * 第一案内（+0x138=0・state 0）。
 *
 * 原典実測（tools/bkprobe.sh、2026-10-13、答えは decomp/res/bk_rrA.jww・
 * bk_rr2.jww）: 点 (300,300)→(450,200)→(400,350)→(500,250)（画面）を
 * 分割数 4 で閉じると、両端の 2 点のあとに弧長 L/4 おきの 3 点。 */
static void bk_rr_finish(jw_drawing *d)
{
    double L = 0.0;
    int i;

    if (bk_rr_n < 2) {
        bk_rr_n = 0;
        return;
    }
    for (i = 1; i < bk_rr_n; i++)
        L += hypot(bk_rr_x[i + 1] - bk_rr_x[i], bk_rr_y[i + 1] - bk_rr_y[i]);
    op_push(bk_points_between(d, bk_rr_x[1], bk_rr_y[1],
                              bk_rr_x[1] + L, bk_rr_y[1], 1));
    bk_rr_n = 0;
}

/* 状態 3 で 分割する線 を (L) 指示したとき: P1・P2 を線の方向へ射影した
 * 媒介変数 s1・s2（無限直線として、区間の外も可）を n-1 等分し、その
 * 直線上の点を置く。
 *
 * 原典実測（2026-10-13）: P1=(-155.51,26.3265)・P2=(89.3878,26.3265)、
 * 線 L0=(-155.51,-4.28571)-(-94.2857,-4.28571)、分割数 3 で
 * (-73.8776,-4.28571)・(7.7551,-4.28571) ── s1=0・s2=4.0（P2 は線分の外）を
 * k/3 だけ進めた s で L0+s*(L1-L0) を計算するとぴったり合う。 */
static void bk_two_point_line(jw_drawing *d, double p1x, double p1y,
                               double p2x, double p2y, int line_idx)
{
    const jw_obj *l = &d->obj[line_idx];
    double lx0 = l->d[0], ly0 = l->d[1];
    double dx = l->d[2] - l->d[0], dy = l->d[3] - l->d[1];
    double len2 = dx * dx + dy * dy;
    double s1, s2;

    if (len2 <= 0.0)
        return;
    s1 = ((p1x - lx0) * dx + (p1y - ly0) * dy) / len2;
    s2 = ((p2x - lx0) * dx + (p2y - ly0) * dy) / len2;
    /* 原典 FUN_00761370 は P1・P2 を線の上に射影してから ２点間分割と同じ
       FUN_007603a0 に渡す（割付・振分・割付距離以下 も同じ歩き） */
    op_push(bk_points_between(d, lx0 + s1 * dx, ly0 + s1 * dy,
                              lx0 + s2 * dx, ly0 + s2 * dy, 0));
}

/* 円周の上を 始めの角 a1 から 向き dir（+1 反時計回り・-1 時計回り）に 長さ len だけ
 * 歩いて点を置く。原典 FUN_00762870（等距離）・FUN_00761c60（等角度）の歩き。
 *
 * 分割数: len を n 等分した n-1 点（端数があれば一点多い）。
 * 割付（2026-10-14 実測 decomp/res/bk_w2・w4・w5.jww）: dist ごとに置き、len の
 * 手前で止める。振分 は 最初の点を -(dist-余り)/2 ずらし、割付距離以下 は
 * dist を len/ceil(len/dist) にする。端の点は置かない。 */
static int bk_arc_walk(jw_drawing *d, double cx, double cy, double r, double a1,
                       double dir, double len)
{
    int made = 0, k;

    if (len < 1e-7 || r < 1e-7)
        return 0;
    if (bk_waritsuke_on()) {
        double dist = box_mm(d, 1412), step, p0 = 0.0, p;

        if (dist < 1e-5)
            return 0;
        step = dist;
        if (jw_cmd_bar_check(1326) > 0) {
            double q = len / dist;
            int m = (int)q;

            if (fabs(q - (double)m) > 1e-7)
                m++;
            if (m < 1)
                m = 1;
            step = len / (double)m;
        } else if (jw_cmd_bar_check(1325) > 0) {
            double rem = len;

            while (dist <= rem + 1e-7)
                rem -= dist;
            if (1e-7 < rem && rem < dist - 1e-7)
                p0 = -(dist - rem) / 2.0;
        }
        if (dir < 0.0) {
            p0 = -p0;
            step = -step;
        }
        p = p0;
        for (k = 1; k < 10001; k++) {
            double ang;

            p += step;
            if (fabs(p) >= len - 1e-7)
                break;
            if (fabs(p) > 1e-7) {
                ang = a1 + p / r;
                made += bk_put_point(d, cx + r * cos(ang), cy + r * sin(ang));
            }
        }
    } else {
        int count;
        double n = bk_read_n(&count);

        if (n <= 0.0)
            return 0;
        for (k = 1; k <= count; k++) {
            double ang = a1 + dir * (len / r) * bk_t(k, n);

            made += bk_put_point(d, cx + r * cos(ang), cy + r * sin(ang));
        }
    }
    return made;
}

/* 状態 3 で 分割する円 を (L) 指示したとき（円の２点間分割）: P1・P2 を
 * 円の中心からの向き θ1・θ2 に直し、**指示した位置（qx,qy）を通るほうの弧**を
 * 分割する（原典は FUN_00462d70 に 三点 P1・指示点・P2 を渡して弧の長さと向きを
 * 得る）。P1 から反時計回りで指示点に先に着けば反時計回り、そうでなければ時計回り。
 *
 * 原典実測（2026-10-13、2026-10-14）: 円 中心(-33.0612,-96.1224) 半径36.7347・
 * P1 を 90°・P2 を 0°に置き、指示を 180°にすると 分割数 4 で 157.5°・225°・292.5° の
 * 3 点（反時計回り 270° を 4 等分。短いほう 90° ではない）。指示が 45° なら
 * 90°→0° の短いほう（2026-10-13 の実測）。点は 仮点 (1323) で仮点になる。 */
static void bk_two_point_circle(jw_drawing *d, double p1x, double p1y,
                                 double p2x, double p2y, int circ_idx,
                                 double qx, double qy)
{
    const jw_obj *c = &d->obj[circ_idx];
    double cx = c->d[0], cy = c->d[1], r = c->d[2];
    double a1, a2, aq, s, sq, dir, len;

    if (hypot(p1x - cx, p1y - cy) < 1e-7 || hypot(p2x - cx, p2y - cy) < 1e-7)
        return;
    a1 = atan2(p1y - cy, p1x - cx);
    a2 = atan2(p2y - cy, p2x - cx);
    aq = atan2(qy - cy, qx - cx);
    s = a2 - a1;
    while (s < 0.0) s += 2.0 * PI;
    while (s >= 2.0 * PI) s -= 2.0 * PI;
    sq = aq - a1;
    while (sq < 0.0) sq += 2.0 * PI;
    while (sq >= 2.0 * PI) sq -= 2.0 * PI;
    if (sq <= s) {
        dir = 1.0;
        len = r * s;
    } else {
        dir = -1.0;
        len = r * (2.0 * PI - s);
    }
    op_push(bk_arc_walk(d, cx, cy, r, a1, dir, len));
}

/* 円全周分割 ── 始点 Ｐ を (R) で指示したあと、円を (R) で指示する（点では
 * なく円そのものを拾えば全周分割になる、string 5361 の「円全周分割 (R)円指示」）。
 * 円の中心から Ｐ への向き θP を 0 番目（描かない）として、クリックした側
 * （Ｐ→中心→クリック の外積の符号）へ 360°/n ずつ回した円周上の点を
 * n-1 個つくる。Ｐ 自体が円の上にあるかどうかは関係ない。
 *
 * 原典実測（2026-10-13、tools/jwdraw.ps1 を直接叩いた。bkprobe.sh ではない）:
 *   円 中心(-33.0612,-96.1224) 半径36.7347。
 *   P=(-155.51,26.3265)（θP=135°）に対しクリック(-7.3465,-70.408)
 *   （外積<0、時計回り）・分割数 5 → 63°・-9°・-81°・-153° の 4 点。
 *   P=(-106.531,56.9388)（θP=115.7°）に対しクリック(-33.061,-132.857)
 *   （外積>0、反時計回り）・分割数 4 → -154.4°・-63.0°・25.6° の 3 点。
 * どちらも θP − 0 番目の位置から 360/n の等間隔で、Ｐ の向きだけが基準に
 * なり、クリック位置そのものの角度は（どちら側かを決めるだけで）点として
 * 現れない。 */
static void bk_full_circle(jw_drawing *d, double px, double py, int circ_idx,
                            double cx, double cy)
{
    const jw_obj *c = &d->obj[circ_idx];
    double ox = c->d[0], oy = c->d[1], r = c->d[2];
    double thp = atan2(py - oy, px - ox);
    double cross = (px - ox) * (cy - oy) - (py - oy) * (cx - ox);
    double s = cross < 0.0 ? -1.0 : 1.0;

    op_push(bk_arc_walk(d, ox, oy, r, thp, s, 2.0 * PI * r));
}

/* 分割の 割付 (1324).
 *
 * 割付 を押すと 分割 のバーが入れ替わり（`src/gen/bars.h` の
 * `jw_bar_32867_1324`）、分割数 (1411) の代わりに 距離 (1412) が出て、
 * 振分 (1325) と 割付距離以下 (1326) が付きます。歩きは 等距離分割 と
 * 同じ二手で、線を二本指すだけです（`tools/probe115.sh`）。
 *
 * **間は「端どうしの距離の大きいほう」で測ります。**原典に平行でない
 * 二本を割り付けさせて分かりました（`tools/probe138.sh`）—— 始点どうし
 * 183.673 mm・終点どうし 244.898 mm の組に 距離 60 mm（実寸 6000、
 * 1/100 の紙）を与えると、出てきた四本は**終点側が 60 mm ずつ**、
 * 始点側は 45 mm ずつ。t = 60/244.898 = 0.245 の等間隔で、
 * 本数も floor(244.898/60) = 4 でした。小さいほうで測っていたら三本です。
 *
 * 三つの出かた（平行な二本、間 183.673 mm、距離 60 mm。
 * `tools/probe136.sh`・`probe137.sh`）:
 *
 *   割付 だけ        線Ａから 60, 60, 60 と置き、Ｂ側に 3.673 の余り
 *   振分 (1325)      同じ三本を**真ん中に寄せ**、両端が 31.837 ずつ
 *                    （余りを半分ずつ分けたぶん）
 *   割付距離以下     余りが出ないように**等分**。距離を超えないいちばん
 *   (1326)           少ない等分で、183.673/4 = 45.918 ≤ 60。
 *                    振分 と一緒に押しても余りが無いので同じ絵
 *
 * 間がちょうど距離で割り切れるとき、距離が間より大きいとき、円を指した
 * ときは訊いていません。
 */
static void waritsuke(jw_drawing *d, int a, int b, double cax, double cay,
                      double cbx, double cby)
{
    const jw_obj *p = &d->obj[a], *q = &d->obj[b];
    double aa[4], bb[4];

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    /* 歩きは 原典 FUN_0075d660 の 0x7e84 枝（bk_fan_walk に番地と式）。
       端の組み方は 分割数 のときと同じ（bk_pair_ends） */
    bk_pair_ends(p, q, cax, cay, cbx, cby, aa, bb);
    op_push(bk_fan_walk(d, aa, bb));
}

/* ２線.
 *
 * A line is picked to run along, then two points say where the pair starts
 * and stops.  What comes out is two lines parallel to the picked one, as far
 * from it as the two numbers in the 間隔 box say -- one to each side -- and
 * as long as the two points, taken along the line.
 *
 * Which side is which follows the picked line's own direction, not where it
 * was clicked: with 間隔 2000,1000 on a 1/200 group the original put the
 * first 10 mm to the right of the way the line runs and the second 5 mm to
 * the left, and drawing the same line the other way round swapped them over
 * while clicking above or below it changed nothing. */
/* ２線の間隔。箱 (1412) は 「a」 か 「a,b」 で、a が片側、b がもう
 * 片側です。**箱が空なら 50 と同じ**になります —— 原典に訊きました
 * （tools/probe158.sh、答えは decomp/res/nisen_*.jww）:
 *
 *   箱が空     拾った線から ±0.5 図寸mm
 *   「50」     同じく ±0.5
 *   「100」    ±1.0
 *   「0,200」  片側 0.0、もう片側 -2.0
 *
 * 書込レイヤグループの縮尺は 1/100 だったので、箱の数は**図面の単位**で、
 * 縮尺で割った図寸が間隔です（100 ÷ 100 = 1.0mm）。空のときの 50 が
 * 図面の単位なのか図寸 0.5mm なのかは、その縮尺では分かれません。
 */
#define NISEN_DEFAULT 50.0

static int nisen_gap(const jw_drawing *d)
{
    const char *t = jw_cmd_box(1412);
    const char *p;
    int wg = 0, i;
    double s;

    if (!t || !*t)
        t = 0;
    nisen_a = t ? box_num(t, 0.0) : NISEN_DEFAULT;
    p = t ? strchr(t, ',') : 0;
    nisen_b = p ? box_num(p + 1, 0.0) : nisen_a;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    s = d->group[wg].scale;
    if (s > 0.0) {
        nisen_a /= s;
        nisen_b /= s;
    }
    return 1;
}

/* ２線 の 留線 (1323) と 留線常駐 (1324) —— 二本の端をつなぐ蓋。
 *
 * 原典に訊きました（`tools/probe161.sh`、答えは `decomp/res/nisen_tome*.jww`）。
 * 拾った線に沿う長さを s、線からの隔たりを t とすると、何も押さない
 * ときの二本は**二つのクリックの射影のあいだ**ちょうどに引かれます。
 *
 *   留線 (1323)      手前の端（一つ目のクリックの側）が **0.5 図寸mm
 *                    外へ伸び**、そこに二本をつなぐ蓋が一本
 *   留線常駐 (1324)  両端が 0.5 ずつ外へ伸び、蓋が両端に
 *
 * **伸びる量は間隔によりません。**間隔を ±0.5・-1/+3・0/+20 と three
 * 通り変えても、伸びはどれも 0.5 図寸mm でした。縮尺は 1/100 でしか
 * 試していないので、これが図寸 0.5mm なのか図面の 50 単位なのかは
 * 分かれていません（間隔の既定 50 と同じ数なのは、たまたまかも
 * しれません）。
 *
 * 書き出す順も原典のとおり —— 蓋・一本目・二本目、常駐ならそのあとに
 * もう一つの蓋。
 */
#define NISEN_TOME 0.5          /* 図寸mm。留線出の箱が空のとき。上の注 */

/* 留線出 (1413) —— 蓋の付く端が外へ伸びる量。
 *
 * 原典の FUN_006295e0 は留線の値の 10 の余りが 1 以上なら FUN_005bb0d0
 * を呼び、それはバーの +0x2c8 の箱（DoDataExchange 0x5baf3b の DDX_Control
 * で 0x585 = 1413）の数を書込レイヤグループの縮尺で割って返します（図面の
 * 単位 → 図寸）。箱が空のときの 0.5 図寸mm は上の注の実測のまま
 * （1/100 で 50 なので、空 = 50 なのか 0.5mm 固定なのかは分かれていません）。
 * 逆コンパイルの読み、原典では押していない。 */
static double nisen_tome_len(const jw_drawing *d)
{
    const char *t = jw_cmd_box(1413);

    if (!t || !*t)
        return NISEN_TOME;
    return box_num(t, 0.0) / write_scale(d);
}

/* 二本の線（無限に伸ばして）の交点。原典 FUN_00629400 と同じく、交わらない・
   交点の x か y が 100000 を超えるなら 0 */
static int nisen_meet(const double *p, const double *q, double *x, double *y)
{
    double ax = p[2] - p[0], ay = p[3] - p[1];
    double bx = q[2] - q[0], by = q[3] - q[1];
    double den = ax * by - ay * bx, t;

    if (fabs(den) <= 1e-12 * sqrt((ax * ax + ay * ay) * (bx * bx + by * by)))
        return 0;
    t = ((q[0] - p[0]) * by - (q[1] - p[1]) * bx) / den;
    *x = p[0] + ax * t;
    *y = p[1] + ay * t;
    return fabs(*x) <= 100000.0 && fabs(*y) <= 100000.0;
}

static int nisen_put(jw_drawing *d, const double *q)
{
    jw_obj *n = jw_add(d, JW_SEN);

    if (!n)
        return 0;
    n->d[0] = q[0];
    n->d[1] = q[1];
    n->d[2] = q[2];
    n->d[3] = q[3];
    return 1;
}

/* 二本を引く。`ll` は終点を 基準線変更 (LL) で指示したとき —— 原典の
 * slot 12 (FUN_00624fa0) の state 5 の枝で、今の区間を書き出し待ちにして
 * 鎖を一つ進め、ダブルクリックした線を次の基準線にします。
 *
 * 角の扱い（FUN_00627c30 の +0xdeed0 が 1 の枝）: 続きの区間の始まりは
 * 前の基準線と今の基準線の交点の射影。前の二本と今の二本を四通り交わらせ
 * (FUN_004619b0 ×4)、その交点で前の二本の終わりと今の二本の始まりを
 * 揃えてから、前の二本を書き、今の二本（とその後の蓋）を書きます。
 * 始点の蓋（留線）は鎖の最初の区間にしか付きません。
 *
 * 四つの交点のうちどの組を取るかは、原典では今の線の一本の上で二つの
 * 交点の並びを比べて決めていますが、その線がどちら側の線なのかは
 * Ghidra が FUN_00420110 の引数を落としていて読み切れませんでした。
 * ここでは進む向きに対して同じ側どうし（隔たりの並びが同じもの）を
 * 組にします —— 壁の角が交差しない取り方です。逆コンパイルの読み、
 * 原典では押していない。 */
static int nisen(jw_drawing *d, double x, double y, int ll)
{
    jw_obj oline = d->obj[nisen_obj];     /* a copy: jw_add below may move the array */
    const jw_obj *o = &oline;
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double len = sqrt(dx * dx + dy * dy), ux, uy, vx, vy;
    double s0, s1, made = 0, cx, cy, ext;
    double off[2], sc[2], L[2][4], cap[4];
    double e0 = 0.0, e1 = 0.0;
    int k, tome = 0, cap0 = 0;
    int jochu = jw_cmd_bar_check(1324) > 0;

    if (len == 0.0)
        return 0;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    /* the two points, along the line the pair runs on */
    s1 = (x - o->d[0]) * ux + (y - o->d[1]) * uy;
    if (nisen_chain) {
        if (!nisen_meet(nisen_pv, o->d, &cx, &cy))
            return 0;
        s0 = (cx - o->d[0]) * ux + (cy - o->d[1]) * uy;
    } else {
        s0 = (nisen_x - o->d[0]) * ux + (nisen_y - o->d[1]) * uy;
        /* 留線 (1323) は一度きり: 原典 FUN_005bb410 は +0xd8（DDX_Check
           0x52b = 1323）を読んだら 0 に戻す。常駐 (1324, +0xdc) は残る */
        tome = jw_cmd_bar_check(1323) > 0;
        if (tome) {
            unsigned char *c = chk_slot(bar_cmd(), 1323);

            if (c)
                *c = 0;
        }
        cap0 = tome || jochu;
    }
    if (fabs(s1 - s0) < 1e-7)       /* FUN_00627c30: 長さ 0 は引かない */
        return 0;
    ext = nisen_tome_len(d);
    /* 蓋の付く端は外へ伸びます。どちらが外かは二点の並び順しだい */
    if (cap0)
        e0 = s0 > s1 ? ext : -ext;
    if (jochu && !ll)
        e1 = s0 > s1 ? -ext : ext;
    s0 += e0;
    s1 += e1;
    /* 間隔反転 (1064) turns the pair over: the original left the two
       numbers in the box alone when it was pressed, so what it reverses
       is which side each of them goes */
    off[0] = nisen_flip ? nisen_a : -nisen_a;
    off[1] = nisen_flip ? -nisen_b : nisen_b;
    for (k = 0; k < 2; k++) {
        L[k][0] = o->d[0] + ux * s0 + vx * off[k];
        L[k][1] = o->d[1] + uy * s0 + vy * off[k];
        L[k][2] = o->d[0] + ux * s1 + vx * off[k];
        L[k][3] = o->d[1] + uy * s1 + vy * off[k];
        sc[k] = s1 > s0 ? off[k] : -off[k];     /* 進む向きの左が正 */
    }
    if (nisen_chain) {          /* 角: 前の二本の終わりと今の二本の始まり */
        int sw = (nisen_ps[0] < nisen_ps[1]) != (sc[0] < sc[1]);

        for (k = 0; k < 2; k++) {
            int j = sw ? 1 - k : k;

            if (nisen_meet(nisen_pl[k], L[j], &cx, &cy)) {
                nisen_pl[k][2] = cx;
                nisen_pl[k][3] = cy;
                L[j][0] = cx;
                L[j][1] = cy;
            }
        }
        for (k = 0; k < 2; k++)
            made += nisen_put(d, nisen_pl[k]);
    }
    if (cap0) {                 /* 手前の蓋が先に出ます */
        cap[0] = L[0][0];
        cap[1] = L[0][1];
        cap[2] = L[1][0];
        cap[3] = L[1][1];
        made += nisen_put(d, cap);
    }
    if (ll) {                   /* 書き出し待ちにして、次の区間へ */
        memcpy(nisen_pl, L, sizeof L);
        nisen_ps[0] = sc[0];
        nisen_ps[1] = sc[1];
        memcpy(nisen_pv, o->d, sizeof nisen_pv);
        nisen_chain = 1;
        if (made)
            op_push((int)made);
        return 1;
    }
    for (k = 0; k < 2; k++)
        if (!nisen_put(d, L[k]))
            break;
        else
            made++;
    if (jochu) {                /* 常駐なら向こうの端にも */
        cap[0] = L[0][2];
        cap[1] = L[0][3];
        cap[2] = L[1][2];
        cap[3] = L[1][3];
        made += nisen_put(d, cap);
    }
    nisen_chain = 0;
    op_push((int)made);
    return 1;
}

/* ２線 の ダブルクリック (LL)。案内 5401/5402 の「基準線変更(LL)」。
 *
 * 原典はダブルクリックの一つ目を普通の左 (slot 9) で受けて 始点なら
 * state 4、終点なら state 5 に置き、マウスが 2 画素以上動くまで
 * (FUN_00629330) そのまま待ちます。そこへ WM_LBUTTONDBLCLK (slot 12,
 * FUN_00624fa0) が来ると:
 *
 *   始点 (state 4)  そこで拾った線を今の基準線に差し替え、始点待ちに
 *                   戻る（同じ線なら 0x14e7、線でなければ 0x14de で何も
 *                   しない）
 *   終点 (state 5)  拾った線が今の基準線と交わるなら (FUN_00629400)、
 *                   今の区間をそこまでとして書き出し待ちにし、拾った線を
 *                   次の基準線にして終点待ちのまま
 *
 * 移植の jw_cmd_point_ll はダブルクリック一つ分（連 と同じ作法、
 * tools/jwdraw.ps1 の LL<x>,<y>）なので、その場で上をします。
 * 逆コンパイルの読み、原典では押していない。 */
static void nisen_ll(jw_drawing *d, const jw_view *v, double x, double y)
{
    int i = jw_pick(d, v, x, y, 3);
    double cx, cy;

    if (i < 0 || d->obj[i].cls != JW_SEN || i == nisen_obj
        || nisen_obj < 0 || nisen_obj >= d->nobj)
        return;
    if (nisen_step == 1) {
        nisen_obj = i;
        return;
    }
    if (!nisen_meet(d->obj[nisen_obj].d, d->obj[i].d, &cx, &cy))
        return;
    if (nisen(d, x, y, 1))
        nisen_obj = i;
}

/* 中心線.
 *
 * Two lines are picked and then two points, and what comes out is one line
 * along the middle of them, as long as the two points make it.  Driven in
 * the original:
 *
 *   two level lines 259.7667 apart gave a line exactly half way between,
 *   and the two points kept their own place along it;
 *   two lines that meet at 0 and 14.036 degrees gave one at 7.018 -- the
 *   bisector -- and the two points came out at their feet on it.
 *
 * So the middle of two lines that run together is the line half way, of two
 * that cross it is the bisector through the crossing, and the two points are
 * dropped onto it square. */
/* (R) reads a point in place of a line (CZukeiChuushinSen's right button,
   FUN_0063ef60 → FUN_0063f0e0), and the left one takes a circle as well as
   a line.  The middle of each pair is FUN_0063f520 (read off the decompile,
   not asked of the original):
     two points       the square bisector of them (its case 6)
     line + point     the line's parallel half way to the point (case 2)
     line + circle    the parallel half way to where the square from the
                      centre to the line crosses the circle (case 1)
     circle + point   square to centre→point, half way between the point
                      and where that line crosses the circle (case 3)
     two circles      square to centre→centre, half way between where that
                      line crosses each circle (case 5)
   "Where it crosses" is the crossing nearer the click that picked the
   circle (FUN_00462070's near point is the pick, +0x100 / +0x110).  Only
   true circles and arcs: an ellipse is not taken. */
#define CHU_KIND(i) ((i) == CHU_PT ? 2 : d->obj[i].cls == JW_SEN ? 0 : 1)

static int chu_cross(const jw_obj *c, double tx, double ty, double nx, double ny,
                     double *ox, double *oy)
{
    /* the line from the centre towards (tx,ty), across the circle, the
       crossing nearer (nx,ny) */
    double ux = tx - c->d[0], uy = ty - c->d[1], len = sqrt(ux * ux + uy * uy);
    double ax, ay, bx, by;

    if (len < 1e-7)
        return 0;
    ux /= len;
    uy /= len;
    ax = c->d[0] + ux * c->d[2];
    ay = c->d[1] + uy * c->d[2];
    bx = c->d[0] - ux * c->d[2];
    by = c->d[1] - uy * c->d[2];
    if ((ax - nx) * (ax - nx) + (ay - ny) * (ay - ny)
        <= (bx - nx) * (bx - nx) + (by - ny) * (by - ny)) {
        *ox = ax;
        *oy = ay;
    } else {
        *ox = bx;
        *oy = by;
    }
    return 1;
}

/* square to a→b, through their middle */
static int chu_bisect(double ax, double ay, double bx, double by,
                      double *px, double *py, double *ux, double *uy)
{
    double dx = bx - ax, dy = by - ay, len = sqrt(dx * dx + dy * dy);

    if (fabs(dx) < 1e-7 && fabs(dy) < 1e-7)
        return 0;
    *px = ax + dx / 2.0;
    *py = ay + dy / 2.0;
    *ux = -dy / len;
    *uy = dx / len;
    return 1;
}

/* along the line l, half way out to (qx,qy) */
static int chu_parallel(const jw_obj *l, double qx, double qy,
                        double *px, double *py, double *ux, double *uy)
{
    double dx = l->d[2] - l->d[0], dy = l->d[3] - l->d[1], len = sqrt(dx * dx + dy * dy), h;

    if (len < 1e-7)
        return 0;
    dx /= len;
    dy /= len;
    h = ((qx - l->d[0]) * -dy + (qy - l->d[1]) * dx) / 2.0;
    *px = l->d[0] - dy * h;
    *py = l->d[1] + dx * h;
    *ux = dx;
    *uy = dy;
    return 1;
}

static int chushin_line_pt(const jw_drawing *d, double *px, double *py,
                           double *ux, double *uy)
{
    int ka = CHU_KIND(chu_a), kb = CHU_KIND(chu_b);
    /* the pair, the line or circle first and the point last */
    int i = ka <= kb ? chu_a : chu_b, k = ka <= kb ? chu_b : chu_a;
    int ki = ka <= kb ? ka : kb, kk = ka <= kb ? kb : ka;
    double ix = ka <= kb ? chu_ax : chu_bx, iy = ka <= kb ? chu_ay : chu_by;
    double kx = ka <= kb ? chu_bx : chu_ax, ky = ka <= kb ? chu_by : chu_ay;
    double x1, y1, x2, y2;

    if (ki == 2)                                    /* two points */
        return chu_bisect(chu_ax, chu_ay, chu_bx, chu_by, px, py, ux, uy);
    if (ki == 0 && kk == 2)                         /* line + point */
        return chu_parallel(&d->obj[i], kx, ky, px, py, ux, uy);
    if (ki == 0 && kk == 1) {                       /* line + circle */
        const jw_obj *l = &d->obj[i], *c = &d->obj[k];
        double dx = l->d[2] - l->d[0], dy = l->d[3] - l->d[1], len = sqrt(dx * dx + dy * dy), t;

        if (len < 1e-7)
            return 0;
        dx /= len;
        dy /= len;
        if (fabs((c->d[0] - l->d[0]) * -dy + (c->d[1] - l->d[1]) * dx) < 1e-7)
            return 0;                               /* the centre is on the line */
        t = (c->d[0] - l->d[0]) * dx + (c->d[1] - l->d[1]) * dy;
        if (!chu_cross(c, l->d[0] + dx * t, l->d[1] + dy * t, kx, ky, &x1, &y1))
            return 0;
        return chu_parallel(l, x1, y1, px, py, ux, uy);
    }
    if (ki == 1 && kk == 2) {                       /* circle + point */
        const jw_obj *c = &d->obj[i];

        if (!chu_cross(c, kx, ky, ix, iy, &x1, &y1))
            return 0;                               /* the point is the centre */
        return chu_bisect(kx, ky, x1, y1, px, py, ux, uy);
    }
    if (ki == 1 && kk == 1) {                       /* two circles */
        const jw_obj *a = &d->obj[chu_a], *b = &d->obj[chu_b];
        double dx = b->d[0] - a->d[0], dy = b->d[1] - a->d[1], len = sqrt(dx * dx + dy * dy), t;

        if (fabs(dx) < 1e-7 && fabs(dy) < 1e-7)
            return 0;                               /* one centre */
        if (!chu_cross(a, b->d[0], b->d[1], chu_ax, chu_ay, &x1, &y1)
            || !chu_cross(b, a->d[0], a->d[1], chu_bx, chu_by, &x2, &y2))
            return 0;
        dx /= len;
        dy /= len;
        /* through the middle of the two crossings, square to the centres */
        t = ((x1 + x2) / 2.0 - a->d[0]) * dx + ((y1 + y2) / 2.0 - a->d[1]) * dy;
        *px = a->d[0] + dx * t;
        *py = a->d[1] + dy * t;
        *ux = -dy;
        *uy = dx;
        return 1;
    }
    return 0;
}

static int chushin_line(const jw_drawing *d, double *px, double *py,
                        double *ux, double *uy)
{
    const jw_obj *p, *q;
    double adx, ady, bdx, bdy, alen, blen;
    double den, t;

    if (chu_a == CHU_PT || chu_b == CHU_PT || d->obj[chu_a].cls != JW_SEN
        || d->obj[chu_b].cls != JW_SEN)
        return chushin_line_pt(d, px, py, ux, uy);
    p = &d->obj[chu_a];
    q = &d->obj[chu_b];
    adx = p->d[2] - p->d[0];
    ady = p->d[3] - p->d[1];
    bdx = q->d[2] - q->d[0];
    bdy = q->d[3] - q->d[1];
    alen = sqrt(adx * adx + ady * ady);
    blen = sqrt(bdx * bdx + bdy * bdy);
    if (alen == 0.0 || blen == 0.0)
        return 0;
    adx /= alen;
    ady /= alen;
    bdx /= blen;
    bdy /= blen;
    if (adx * bdx + ady * bdy < 0.0) {      /* point them the same way */
        bdx = -bdx;
        bdy = -bdy;
    }
    den = adx * bdy - ady * bdx;
    if (fabs(den) >= 1e-12) {
        /* 交わる二本: 二等分線は 拾った半分どうしの間（原典ファジング s22_19: もう一方の二等分線ではなかった）。
           交点から 拾った点の側を向く向きを 各線に取って足す */
        double tt = ((q->d[0] - p->d[0]) * bdy - (q->d[1] - p->d[1]) * bdx) / den;
        double xx = p->d[0] + tt * adx, yy = p->d[1] + tt * ady;
        double sa = (chu_ax - xx) * adx + (chu_ay - yy) * ady;
        double sb = (chu_bx - xx) * bdx + (chu_by - yy) * bdy;

        if (sa < 0.0) {
            adx = -adx;
            ady = -ady;
        }
        if (sb < 0.0) {
            bdx = -bdx;
            bdy = -bdy;
        }
        den = adx * bdy - ady * bdx;
        t = ((q->d[0] - p->d[0]) * bdy - (q->d[1] - p->d[1]) * bdx) / den;
        (void)t;
        *px = xx;
        *py = yy;
        *ux = adx + bdx;
        *uy = ady + bdy;
        t = sqrt(*ux * *ux + *uy * *uy);
        if (t == 0.0)
            return 0;
        *ux /= t;
        *uy /= t;
        return 1;
    }
    if (fabs(den) < 1e-12) {
        /* they run together: half way between, along the first one */
        double wx = q->d[0] - p->d[0], wy = q->d[1] - p->d[1];
        double along = wx * adx + wy * ady;
        *px = p->d[0] + (wx - along * adx) / 2.0;
        *py = p->d[1] + (wy - along * ady) / 2.0;
        *ux = adx;
        *uy = ady;
        return 1;
    }
    /* they cross: the bisector through the crossing */
    t = ((q->d[0] - p->d[0]) * bdy - (q->d[1] - p->d[1]) * bdx) / den;
    *px = p->d[0] + t * adx;
    *py = p->d[1] + t * ady;
    *ux = adx + bdx;
    *uy = ady + bdy;
    t = sqrt(*ux * *ux + *uy * *uy);
    if (t == 0.0)
        return 0;
    *ux /= t;
    *uy /= t;
    return 1;
}

/* what the left button picks: a line, or a circle or arc that is round */
static int chu_takes(const jw_obj *o)
{
    return o->cls == JW_SEN || (o->cls == JW_ENKO && fabs(o->d[6] - 1.0) < 1e-9 && o->d[2] > 0.0);
}

static void chushin(jw_drawing *d, double x, double y)
{
    double px, py, ux, uy, t0, t1;
    jw_obj *o;

    if ((chu_a < 0 && chu_a != CHU_PT) || (chu_b < 0 && chu_b != CHU_PT)
        || chu_a >= d->nobj || chu_b >= d->nobj)
        return;
    if ((chu_a >= 0 && !chu_takes(&d->obj[chu_a])) || (chu_b >= 0 && !chu_takes(&d->obj[chu_b])))
        return;
    if (!chushin_line(d, &px, &py, &ux, &uy))
        return;
    t0 = (chu_x - px) * ux + (chu_y - py) * uy;
    t1 = (x - px) * ux + (y - py) * uy;
    /* 中心線寸法 (1412): FUN_0063cc50 (逆コンパイルの読み、原典では押して
       いない) takes FUN_004cac50's length -- the box's absolute value over
       the write group's scale -- and, when it is over 1e-7, the line runs
       that far from the start point's foot towards the end point's side
       (the end at or past the start counts as forward).  The end point
       only gives the side.  FUN_004cac50's extra factor DAT_00a0d630
       (when DAT_00a0d62c is set) is not taken. */
    {
        double len = fabs(box_num(jw_cmd_box(1412), 0.0)) / write_scale(d);

        if (len > 1e-07)
            t1 = t1 < t0 ? t0 - len : t0 + len;
    }
    if (t0 == t1)
        return;
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->d[0] = px + ux * t0;
    o->d[1] = py + uy * t0;
    o->d[2] = px + ux * t1;
    o->d[3] = py + uy * t1;
    op_push(1);
}

/* 接線, 円→円 (0x8066).
 *
 * Two circles have four common tangents, and the original draws the one that
 * touches each circle on the side it was pointed at: four runs over the same
 * pair, picking top/top, bottom/bottom, top/bottom and bottom/top, came back
 * with four different lines and each one touches where it was pointed
 * (decomp/res/sessen_*.jww).  The line runs from one touch point to the
 * other -- its ends are the tangency points, to four decimals in every run.
 *
 * A tangent is the line whose unit normal n has
 *     n.cA - k = sa*rA        n.cB - k = sb*rB
 * for a choice of signs; subtracting gives n.(cB-cA) = sb*rB - sa*rA, which
 * fixes n up to the reflection in cB-cA, and the touch points follow as
 * c - s*r*n.  The four sign pairs are the four tangents; the inner two do not
 * exist when the circles overlap, and the term under the root says so.
 */
static int tangent(double ax, double ay, double ra,
                   double bx, double by, double rb,
                   int sa, int sb, double *px, double *py,
                   double *qx, double *qy)
{
    double dx = bx - ax, dy = by - ay;
    double dd = sqrt(dx * dx + dy * dy);
    double r, c, h, ux, uy, nx, ny;

    if (dd < 1e-12)
        return 0;
    r = sb * rb - sa * ra;
    c = r / dd;
    h = 1.0 - c * c;
    if (h < 0.0)
        return 0;               /* no tangent with those two sides */
    h = sqrt(h);
    ux = dx / dd;
    uy = dy / dd;
    /* n = u*c + perp(u)*h -- the other root is the mirror pair of signs */
    nx = ux * c - uy * h;
    ny = uy * c + ux * h;
    *px = ax - sa * ra * nx;
    *py = ay - sa * ra * ny;
    *qx = bx - sb * rb * nx;
    *qy = by - sb * rb * ny;
    return 1;
}

/* 接線, 点→円 (the bar's 点→円 button).
 *
 * A point outside a circle has two tangents, and the original draws the one
 * whose touch point is nearer where the circle was pointed at -- pointing at
 * the upper half of the same circle from the same point gave one, the lower
 * half the other, and the left and right halves agreed with whichever of
 * those they were on (decomp/res/tensen_*.jww).
 *
 * The point comes first and the circle second, whatever the status line says:
 * driving it the other way round leaves nothing drawn.
 *
 * With d = P - c and L = |d|, the touch points are r*cos a along d and
 * r*sin a across it, where cos a = r/L -- (T-P).(T-c) works out to r^2 - r*L*
 * (r/L) = 0, so they are tangents, and the line runs from P to T.
 */
/* 接円 (0x8068): a circle of the radius in the bar's box, touching two lines.
 *
 * Three clicks -- the first line, the second, then a click that says which
 * circle is wanted; the original's status line puts up 「マウスを移動し、必要な
 * 接円位置で左クリックしてください。 【 4 − 1 】」, so there are four of them and
 * it takes the one nearest the click.  Driving it four times over the same
 * crossed pair, placing the click left, right, above and below, gave four
 * circles of radius 10 whose centres are the intersection offset along the
 * two angle bisectors (decomp/res/sekien_*.jww).
 *
 * The radius in the box is a real length, so it is divided by the write layer
 * group's scale the same way 面取's size is -- 2000 in a 1/200 group came out
 * 10 mm on the paper.
 *
 * A centre at distance r from both lines satisfies n1.C = k1 + s1*r and
 * n2.C = k2 + s2*r for the lines' unit normals; the four sign pairs are the
 * four circles, and two parallel lines have none unless they happen to be 2r
 * apart, which the determinant says.
 */
/* 曲線, スプライン (0x808c).
 *
 * Points are clicked one after another and 作図実行 draws the curve through
 * them as a run of straight lines.  Two things had to be settled by asking
 * the original, and both came out exactly.
 *
 * What curve.  A natural cubic spline on uniform knots: driven over four
 * points, the second derivative at the two ends is zero and the tangents
 * across a join agree.  Four points at (0,0) (1,1) (2,0) (3,1) in span units
 * gave f'(0) = 288.6297 where the natural spline's (y1-y0) - (2m0+m1)/6 is
 * 173.178 + 115.452 = 288.630, and the joins matched to 1e-8
 * (decomp/res/curve_*.jww).  Catmull-Rom is not it -- it would have put the
 * tangent at the first interior point at zero, and the original's is -57.73.
 *
 * Where it samples.  Not evenly.  With n divisions to a span the parameter
 * steps are 0.58, 1, 1, ..., 1, 0.58 -- the two at the ends are 0.58 of the
 * rest -- so the middle step is 1/(n - 0.84) and the end ones 0.58 of that.
 * That 0.58 is exact, and the same at n = 3, 4, 7 and 10.
 */
#define CV_END 0.58

/* The second derivatives of the natural cubic spline through v[0..n-1], for
   unit knot spacing.  Thomas' algorithm on the usual tridiagonal system. */
/* two ends of a chain meeting: the original's own rectangles share their
   corners exactly, so this only has to allow for the last bit of a double */
static int near_pt(double ax, double ay, double bx, double by)
{
    double dx = ax - bx, dy = ay - by;

    return dx * dx + dy * dy < 1e-12;
}

static void spline_m(const double *v, int n, double *m)
{
    double c[CV_MAX], r[CV_MAX];
    int i;

    for (i = 0; i < n; i++)
        m[i] = 0.0;
    if (n < 3)
        return;
    /* m[0] = m[n-1] = 0; for i = 1..n-2:
         m[i-1] + 4 m[i] + m[i+1] = 6 (v[i-1] - 2 v[i] + v[i+1]) */
    c[1] = 1.0 / 4.0;
    r[1] = 6.0 * (v[0] - 2 * v[1] + v[2]) / 4.0;
    for (i = 2; i <= n - 2; i++) {
        double den = 4.0 - c[i - 1];
        c[i] = 1.0 / den;
        r[i] = (6.0 * (v[i - 1] - 2 * v[i] + v[i + 1]) - r[i - 1]) / den;
    }
    for (i = n - 2; i >= 1; i--)
        m[i] = r[i] - c[i] * m[i + 1];
}

static double spline_at(const double *v, const double *m, int i, double s)
{
    double a = 1.0 - s;

    return v[i] * a + v[i + 1] * s
         + ((a * a * a - a) * m[i] + (s * s * s - s) * m[i + 1]) / 6.0;
}

/* ベジェ曲線: a Bezier of degree (points - 1) over everything that was
 * clicked, sampled evenly.  Four points came out a cubic Bezier and five a
 * quartic, both to 1e-8, and the sampling is (points - 1) * 分割数 vertices
 * -- one fewer segment than the spline's, since that counts segments rather
 * than points (decomp/res/bezier_*.jww).
 *
 * de Casteljau rather than the Bernstein sum: with up to 64 points the
 * binomial coefficients get large, and this needs no coefficients at all.
 */
static void bezier_at(const double *vx, const double *vy, int n, double t,
                      double *ox, double *oy)
{
    double ax[CV_MAX], ay[CV_MAX];
    int i, k;

    for (i = 0; i < n; i++) {
        ax[i] = vx[i];
        ay[i] = vy[i];
    }
    for (k = n - 1; k > 0; k--)
        for (i = 0; i < k; i++) {
            ax[i] += (ax[i + 1] - ax[i]) * t;
            ay[i] += (ay[i + 1] - ay[i]) * t;
        }
    *ox = ax[0];
    *oy = ay[0];
}

/* サイン曲線 (1689) and ２次曲線 (1690).
 *
 * Both are laid out along a line that is picked first -- the status line asks
 * 「基準線を指示してください。」 -- and then take points:
 *
 *   サイン  原点, 振幅（頂点）の幅の点, １サイクル点, 始点, 終点
 *   ２次    原点, 中間点, 始点, 終点
 *
 * Read them as coordinates along the picked line (s) and across it (h), both
 * from the 原点 -- which is the click itself, not its foot on the line: the
 * original was given an origin 20 pixels off the line and drew the curve
 * about a line through it.  Then
 *
 *   サイン  h = A sin(2 pi s / L), with A the amplitude point's h and L the
 *           cycle point's s.  Checked against the original to 1e-4 at every
 *           vertex.
 *   ２次    h = a s^2, with a from the middle point: a = h_m / s_m^2.
 *
 * The vertices sit on a grid **anchored at the 原点**, and the curve is cut
 * to the 始点 and the 終点 (their s), so the first and last pieces are short.
 * The spacing is where the two part company:
 *
 *   サイン  L / (2 * 分割数) -- a whole wave is 2n pieces, not n.
 *   ２次    (s_end - s_start) / 分割数 -- the drawn span, divided up, but
 *           still counted off from the 原点.  The original put a vertex at
 *           3 * spacing when the start was 2.13 spacings out.
 *
 * Which way round the picked line is stored makes no difference: flipping it
 * flips s and h together, and both formulas are unchanged.
 */
static void curve_draw(jw_drawing *d)
{
    const char *sz = jw_cmd_box(1411);
    double nx = -cv_uy, ny = cv_ux;
    double ox = cv_x[0], oy = cv_y[0];
    double sm, hm, L = 0, a = 0, s0, s1, ss, s, px, py;
    int nd = sz ? atoi(sz) : 0, sine = cv_mode == 1689, k, made = 0;

    if (nd < 1)
        return;
    sm = cv_ux * (cv_x[1] - ox) + cv_uy * (cv_y[1] - oy);
    hm = nx * (cv_x[1] - ox) + ny * (cv_y[1] - oy);
    if (sine) {
        L = cv_ux * (cv_x[2] - ox) + cv_uy * (cv_y[2] - oy);
        if (fabs(L) < 1e-12)
            return;
        s0 = cv_ux * (cv_x[3] - ox) + cv_uy * (cv_y[3] - oy);
        s1 = cv_ux * (cv_x[4] - ox) + cv_uy * (cv_y[4] - oy);
        ss = fabs(L) / (2 * nd);
    } else {
        if (fabs(sm) < 1e-12)
            return;
        a = hm / (sm * sm);
        s0 = cv_ux * (cv_x[2] - ox) + cv_uy * (cv_y[2] - oy);
        s1 = cv_ux * (cv_x[3] - ox) + cv_uy * (cv_y[3] - oy);
        ss = fabs(s1 - s0) / nd;
    }
    if (ss < 1e-9 || fabs(s1 - s0) < 1e-12)
        return;

#define CURVE_H(t) (sine ? hm * sin(2 * PI * (t) / L) : a * (t) * (t))
#define CURVE_X(t) (ox + cv_ux * (t) + nx * CURVE_H(t))
#define CURVE_Y(t) (oy + cv_uy * (t) + ny * CURVE_H(t))

    s = s0;
    px = CURVE_X(s0);
    py = CURVE_Y(s0);
    k = s1 > s0 ? jw_whole(floor(s0 / ss)) + 1 : jw_whole(ceil(s0 / ss)) - 1;
    for (;;) {
        double sn = k * ss, qx, qy;
        jw_obj *o;

        if (s1 > s0 ? sn >= s1 - 1e-9 : sn <= s1 + 1e-9)
            break;
        if (made > 100000)
            break;
        qx = CURVE_X(sn);
        qy = CURVE_Y(sn);
        o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->d[0] = px;
        o->d[1] = py;
        o->d[2] = qx;
        o->d[3] = qy;
        px = qx;
        py = qy;
        s = sn;
        k += s1 > s0 ? 1 : -1;
        made++;
    }
    if (fabs(s1 - s) > 1e-9) {
        jw_obj *o = jw_add(d, JW_SEN);

        if (o) {
            o->d[0] = px;
            o->d[1] = py;
            o->d[2] = CURVE_X(s1);
            o->d[3] = CURVE_Y(s1);
            made++;
        }
    }
#undef CURVE_H
#undef CURVE_X
#undef CURVE_Y
    if (made)
        op_push(made);
}

/* One click of サイン曲線 or ２次曲線: the line first, then the points. */
static void curve_point(jw_drawing *d, const jw_view *v, double x, double y)
{
    int want = cv_mode == 1689 ? 5 : 4;

    if (!cv_base) {
        int i = jw_pick(d, v, x, y, 3);
        double ux, uy, L;

        if (i < 0 || d->obj[i].cls != JW_SEN)
            return;
        ux = d->obj[i].d[2] - d->obj[i].d[0];
        uy = d->obj[i].d[3] - d->obj[i].d[1];
        L = sqrt(ux * ux + uy * uy);
        if (L < 1e-12)
            return;
        cv_ux = ux / L;
        cv_uy = uy / L;
        cv_base = 1;
        cv_n = 0;
        return;
    }
    if (cv_n < CV_MAX) {
        cv_x[cv_n] = x;
        cv_y[cv_n] = y;
        cv_n++;
    }
    if (cv_n >= want) {
        curve_draw(d);
        cv_n = 0;
        cv_base = 0;           /* ready for the next one */
    }
}

static void kyokusen(jw_drawing *d)
{
    const char *sz = jw_cmd_box(1411);
    double mx[CV_MAX], my[CV_MAX], v, px, py;
    int n = sz ? atoi(sz) : 0, i, k, made = 0;

    if (cv_mode != 1691 && cv_mode != 1692)
        return;                 /* サイン and ２次 go through curve_draw */
    if (cv_n < 2 || n < 1)
        return;
    /* Both kinds make (points - 1) * 分割数 lines, and nothing bounded
       that: a nine-digit 分割数 set this making hundreds of millions of
       lines until memory gave out, and the product itself overflows an
       int past two thousand million.  The サイン and ２次 path above stops
       at 100000 lines; this one refuses outright past the same number, so
       that what it does draw is always the whole curve.  (How the
       original bounds it has not been found -- its own point arrays hold
       about five hundred.) */
    if ((double)(cv_n - 1) * n > 100000.0)
        return;
    if (cv_mode == 1692) {      /* ベジェ */
        int pts = (cv_n - 1) * n;

        if (pts < 2)
            return;
        px = cv_x[0];
        py = cv_y[0];
        for (k = 1; k < pts; k++) {
            double qx, qy;
            jw_obj *o;

            bezier_at(cv_x, cv_y, cv_n, (double)k / (pts - 1), &qx, &qy);
            o = jw_add(d, JW_SEN);
            if (!o)
                return;
            o->d[0] = px;
            o->d[1] = py;
            o->d[2] = qx;
            o->d[3] = qy;
            px = qx;
            py = qy;
            made++;
        }
        if (made)
            op_push(made);
        return;
    }
    spline_m(cv_x, cv_n, mx);
    spline_m(cv_y, cv_n, my);
    /* the step that makes the two at the ends 0.58 of the rest add up to 1 */
    v = 1.0 / (n - 2 + 2 * CV_END);
    px = cv_x[0];
    py = cv_y[0];
    for (i = 0; i < cv_n - 1; i++)
        for (k = 1; k <= n; k++) {
            double s, qx, qy;
            jw_obj *o;

            if (k == n)
                s = 1.0;
            else
                s = CV_END * v + (k - 1) * v;
            qx = spline_at(cv_x, mx, i, s);
            qy = spline_at(cv_y, my, i, s);
            o = jw_add(d, JW_SEN);
            if (!o)
                return;
            o->d[0] = px;
            o->d[1] = py;
            o->d[2] = qx;
            o->d[3] = qy;
            px = qx;
            py = qy;
            made++;
        }
    if (made)
        op_push(made);
}

/* ハッチ (0x806a), 1線.
 *
 * The boundary is settled with the right button -- 「閉鎖連続線・円をマウス(R)で
 * 指示してください」 -- and 実行 stays greyed until one is.  Right-clicking one
 * side of a rectangle takes the whole ring; right-clicking a circle takes the
 * circle.
 *
 * What it then draws is simple and came out exact both times.  Take the
 * normal of the 角度 direction; the lines sit where n.p is a whole multiple of
 * the ピッチ -- anchored at zero, not at the region, so the same hatch over
 * two regions lines up -- and each line is exactly the chord of the region at
 * that offset.  A circle of radius 129.88 at 45 degrees and pitch 10 came back
 * as 26 chords at offsets -60 to 190, every one matching sqrt(r^2 - d^2) to
 * 1e-6, and a rectangle as 49 (decomp/res/hatch_*.jww).
 *
 * ピッチ is paper millimetres while 実寸 is off, which is how the original
 * starts.
 */
/* Walk the ring that starts at line `a` and add it to the list.  `used` is
 * the caller's, so a boxful of lines can be walked ring by ring without
 * taking the same line twice; `only` limits the walk to the selected lines.
 */
static int hatch_ring_from(const jw_drawing *d, int a, char *used, int only)
{
    double ex, ey, sx, sy;
    int i, k, first = ht_n, n = d->ndrawn > HT_MAX ? HT_MAX : d->ndrawn;

    if (a < 0 || a >= n || d->obj[a].cls != JW_SEN || ht_nreg >= HT_REG)
        return 0;
    used[a] = 1;
    sx = d->obj[a].d[0];
    sy = d->obj[a].d[1];
    ex = d->obj[a].d[2];
    ey = d->obj[a].d[3];
    if (ht_n >= HT_MAX - 2)
        return 0;
    ht_x[ht_n] = sx;
    ht_y[ht_n] = sy;
    ht_n++;
    for (k = 0; k < HT_MAX; k++) {
        int found = -1, flip = 0;

        if (ht_n >= HT_MAX - 1)
            break;
        ht_x[ht_n] = ex;
        ht_y[ht_n] = ey;
        ht_n++;
        if (near_pt(ex, ey, sx, sy)) {
            if (ht_n - first <= 3)
                break;          /* not a ring */
            ht_reg[ht_nreg].round = 0;
            ht_reg[ht_nreg].first = first;
            ht_reg[ht_nreg].n = ht_n - first;
            ht_nreg++;
            return 1;
        }
        for (i = 0; i < n; i++) {
            if (used[i] || d->obj[i].cls != JW_SEN)
                continue;
            if (only && !d->obj[i].sel)
                continue;
            if (near_pt(d->obj[i].d[0], d->obj[i].d[1], ex, ey)) {
                found = i;
                flip = 0;
                break;
            }
            if (near_pt(d->obj[i].d[2], d->obj[i].d[3], ex, ey)) {
                found = i;
                flip = 1;
                break;
            }
        }
        if (found < 0)
            break;
        used[found] = 1;
        ex = flip ? d->obj[found].d[0] : d->obj[found].d[2];
        ey = flip ? d->obj[found].d[1] : d->obj[found].d[3];
    }
    ht_n = first;               /* nothing usable: give the points back */
    return 0;
}

/* The boundary picked one line at a time with the left button.  The
 * original's status line counts them -- 「■ 次の線・円をﾏｳｽ(L)で指示して
 * ください。 【 n 】 < m >」 -- and the ring closes when a line already in
 * the chain is picked again, not when the chain happens to come back to
 * where it started: four picks round a rectangle leave 実行 greyed, and a
 * fifth on the first line draws the hatch.
 */
static int hatch_chain(const jw_drawing *d)
{
    char used[HT_MAX];
    int i, k, n = d->ndrawn > HT_MAX ? HT_MAX : d->ndrawn;

    if (ht_nchain <= 0)
        return 0;
    for (i = 0; i < n; i++)
        used[i] = 1;            /* everything but the chain is out of bounds */
    for (k = 0; k < ht_nchain; k++)
        if (ht_chain[k] >= 0 && ht_chain[k] < n)
            used[ht_chain[k]] = 0;
    ht_n = 0;
    ht_nreg = 0;
    return hatch_ring_from(d, ht_chain[0], used, 0);
}

static int hatch_ring(const jw_drawing *d, int a)
{
    char used[HT_MAX];
    int i, n = d->ndrawn > HT_MAX ? HT_MAX : d->ndrawn;

    for (i = 0; i < n; i++)
        used[i] = 0;
    ht_n = 0;
    ht_nreg = 0;
    return hatch_ring_from(d, a, used, 0);
}

/* A circle is a region of its own. */
static void hatch_circle(const jw_obj *o)
{
    if (ht_nreg >= HT_REG)
        return;
    ht_reg[ht_nreg].round = 1;
    ht_reg[ht_nreg].first = 0;
    ht_reg[ht_nreg].n = 0;
    ht_reg[ht_nreg].cx = o->d[0];
    ht_reg[ht_nreg].cy = o->d[1];
    ht_reg[ht_nreg].r = o->d[2];
    ht_nreg++;
}

/* Everything the box took: each closed ring of selected lines, and each
 * selected whole circle. */
static void hatch_selected(const jw_drawing *d)
{
    char used[HT_MAX];
    int i, n = d->ndrawn > HT_MAX ? HT_MAX : d->ndrawn;

    ht_n = 0;
    ht_nreg = 0;
    for (i = 0; i < n; i++)
        used[i] = 0;
    for (i = 0; i < n; i++) {
        if (!d->obj[i].sel)
            continue;
        if (d->obj[i].cls == JW_ENKO && d->obj[i].d[2] > 0.0
            && (d->obj[i].d[4] == 0.0 || d->obj[i].d[4] >= 6.283185))
            hatch_circle(&d->obj[i]);
        else if (d->obj[i].cls == JW_SEN && !used[i])
            hatch_ring_from(d, i, used, 1);
    }
}

static int hatch_at(jw_drawing *d, double o, double ux, double uy,
                    double nx, double ny);
static int hatch_grid(jw_drawing *d, double ux, double uy, double nx,
                      double ny, double vp, double hp);
static void hatch_span(double ax, double ay, double *lo, double *hi);
static int hatch_cut(double o, double ax, double ay, double bx, double by,
                     double *t);

/* 属性変更の文字: 線種・文字種変更 (1352) のとき、文字は線の色・線種ではなく
 * 書込みの文字種になる.  逆コンパイルの読み、原典では押していない.
 * CZukeiHenkou の 3 番 FUN_0067b890 の CDataMoji の枝（0x67bcb0〜0x67bf27）:
 *  - 文字種 +0xb4 = 書込文字種 DAT_00a0b4e8（0..10 でなければ 0）、幅 +0xb8・
 *    高さ +0xc0・間隔 +0xc8・色 +0x2a はその文字種の表から
 *  - 書体 +0xd8 = 書込みの書体（DAT_00a0ba84）
 *  - flags の 0x20（縦字）は落としてから、バーの 縦字 (1325) なら立てる
 *  - +0xdc は 0 にして、書込みの斜体（DAT_00a0bc28）・太字（DAT_00a0bc2c）
 *  - そして FUN_0067adf0 で置き直す: 古い始点・終点を文字の角度 +0xd0 で
 *    水平に戻し、新しい長さ L（FUN_004935b0）との差を基点で配る.
 *      始点 x += (古い長さ - L) * 横 / 2、 y += (古い高さ - 新しい高さ) * 縦 / 2
 *    （縦字なら高さの代わりに幅）、終点 = 始点 + L.  横・縦は文字の基点
 *    （view+0x1a0 の +0xbc・+0xc0、0..2 = 左・中・右／下・中・上）
 * 移植では: 書込文字種は cur_style（番号は moji() と同じく style[] との一致）、
 * 斜体・太字は n の 10000・20000（moji() と同じ）、基点は 文字 と同じ moji_kijun
 * （原典も同じ view+0x1a0 の値を読む）。角度は移植が d[7] を回転で直さない
 * ので、始点→終点の向きから取る（長さ 0 なら d[7]）。長さ L は
 * FUN_004935b0 の式: 半角の数 c（CP932 のバイト数）で 0 なら 0、1 なら W/2、
 * でなければ (W+D)/2*c から 最後の字が全角なら D、半角なら D/2 を引く
 * （縦字は W の代わりに H）。特殊文字・間隔 0.01 の比例の枝は入れていない. */
static void zoku_moji(jw_drawing *d, jw_obj *o)
{
    double ow = o->d[4], oh = o->d[5];
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double olen = sqrt(dx * dx + dy * dy);
    double a = olen > 0.0 ? atan2(dy, dx) : o->d[7] * PI / 180.0;
    double c = cos(a), s = sin(a), w, h, sp, run = 0.0, sx, sy;
    const char *t = o->text >= 0 ? jw_str(d, o->text) : "";
    int i, no = 0, nb = 0, wide = 0, hb = moji_kijun / 3, vb = 2 - moji_kijun % 3;

    w = d->cur_style.w;
    h = d->cur_style.h;
    sp = d->cur_style.sp;
    for (i = 0; i < 10; i++)
        if (d->style[i].w == w && d->style[i].h == h && d->style[i].sp == sp) {
            no = i + 1;
            break;
        }
    o->n = no + (moji_italic ? 10000 : 0) + (moji_bold ? 20000 : 0);
    o->d[4] = w;
    o->d[5] = h;
    o->d[6] = sp;
    o->color = (unsigned short)d->cur_style.color;
    o->face = jw_add_str(d, JW_MOJI_FACE);
    o->flags = (unsigned short)(o->flags & ~0x20u);
    if (jw_cmd_bar_check(1325) > 0)
        o->flags = (unsigned short)(o->flags | 0x20u);
    while (t && *t) {
        wide = jw_is_lead((unsigned char)t[0]) && t[1];
        nb += wide ? 2 : 1;
        t += wide ? 2 : 1;
    }
    {
        double cw = (o->flags & 0x20) ? h : w;

        run = nb < 1 ? 0.0 : nb == 1 ? cw / 2.0
            : (cw + sp) * 0.5 * nb - (wide ? sp : sp * 0.5);
    }
    {
        double along = (olen - run) * hb / 2.0;
        double across = ((o->flags & 0x20) ? ow - w : oh - h) * vb / 2.0;

        sx = o->d[0] + along * c - across * s;
        sy = o->d[1] + along * s + across * c;
    }
    o->d[0] = sx;
    o->d[1] = sy;
    o->d[2] = sx + run * c;
    o->d[3] = sy + run * s;
}

/* Give an element the write attributes.  It comes back at the end of the
 * drawing, which is what the original does -- so what is drawn on top of what
 * changes with it. */
static void zoku_change(jw_drawing *d, int i)
{
    jw_obj was, *o;
    op_t *rec;
    unsigned short colour, lt;
    unsigned char layer, lgroup;

    if (!d || i < 0 || i >= d->ndrawn)
        return;
    was = d->obj[i];
    rec = op_new();
    if (!rec)
        return;
    erase(d, i, rec);
    o = jw_add(d, was.cls);
    if (!o)
        return;
    colour = o->color;          /* what a new element gets */
    lt = o->ltype;
    layer = o->layer;
    lgroup = o->lgroup;
    *o = was;
    if (zh_type && o->cls == JW_MOJI)
        zoku_moji(d, o);
    else if (zh_type) {
        o->color = colour;
        o->ltype = lt;
    }
    if (zh_layer) {
        o->layer = layer;
        o->lgroup = lgroup;
    }
    rec->n = 1;
}

/* 選択図形登録 (1068): what the box picked becomes the pattern. */
static int hatch_register(const jw_drawing *d)
{
    int i, first = 1;

    ht_npat = 0;
    if (!d)
        return 0;
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double a, b2, c, e;

        /* the original leaves out text and dimensions (FUN_006765a0
           tests for CDataMoji and CDataSunpou).  The port has no
           dimension class -- its own dimensions come out as lines and
           text -- so only the text is skipped here. */
        if (!o->sel || o->cls == JW_MOJI)
            continue;
        if (ht_npat >= HT_PAT)
            break;
        ht_pat[ht_npat++] = *o;
        jw_obj_box(o, &a, &b2, &c, &e);
        if (first || a < ht_pxl) ht_pxl = a;
        if (first || b2 < ht_pyl) ht_pyl = b2;
        if (first || c > ht_pxh) ht_pxh = c;
        if (first || e > ht_pyh) ht_pyh = e;
        first = 0;
    }
    return ht_npat;
}

/* One copy of the pattern, moved by (dx, dy). */
static int hatch_stamp(jw_drawing *d, double dx, double dy)
{
    int i, made = 0;

    for (i = 0; i < ht_npat; i++) {
        jw_obj *o = jw_add(d, ht_pat[i].cls);

        if (!o)
            break;
        *o = ht_pat[i];
        o->sel = 0;
        o->flags = (unsigned short)((o->flags & ~2u) | 0x20u);
        jw_obj_move(o, dx, dy);
        made++;
    }
    return made;
}

/* 図形 (1693): the pattern tiled over the region.
 *
 * Four things were taken off the original (tools/probe85.sh through
 * probe88.sh), each with an L of known size laid in a plain rectangle:
 *
 *   * the copies sit on a **lattice fixed to the drawing's origin**,
 *     spanned by 横ピッチ (1412) along the hatch angle and
 *     縦ピッチ (1411) across it.  Moving the region did not
 *     move one of them, and neither did moving the pattern itself
 *     (probe86: same coordinates to six places, only the count changed)
 *   * the point of the pattern that lands on a lattice point is
 *     **(box left + width/4, box top - height/4)** -- the middle of the
 *     top left quarter of the box round it.  Three Ls of different
 *     shapes gave that to six places (probe87), and the first L had
 *     width exactly twice height, which is why it took three
 *   * a copy is laid only where **the whole box round it is inside**
 *     the region.  With the rectangle 183.7 across and 縦ピッチ 60,
 *     three rows fit; sliding the rectangle 30.6 left two did
 *   * nothing is scaled.  The same L in Test5, whose write group is at
 *     1/200, came out the same size and at the same 80 apart (probe88),
 *     so the division by the group's scale that FUN_00676210 reads as
 *     doing is not one the drawing ever sees.
 *
 * The copies are **not turned** with the angle -- only the lattice is.
 * At 角度 30 the Ls still stood square (probe86). */
static int hatch_figs(jw_drawing *d, double ux, double uy,
                      double pitch, double gap)
{
    double vx = -uy, vy = ux;   /* across, a quarter turn the other way */
    double w = ht_pxh - ht_pxl, h = ht_pyh - ht_pyl;
    double rx = ht_pxl + w / 4.0, ry = ht_pyh - h / 4.0;
    double alo, ahi, t[HT_MAX];
    int m, m0, m1, made = 0;

    if (ht_npat <= 0 || pitch <= 0.0 || gap <= 0.0)
        return 0;
    hatch_span(vx, vy, &alo, &ahi);
    /* which rows can hold one at all: the box has to clear both ends */
    m0 = (int)floor((alo + (vx * rx + vy * ry)
                     - (vx * ht_pxl + vy * ht_pyl)) / pitch) - 2;
    m1 = (int)ceil((ahi + (vx * rx + vy * ry)
                    - (vx * ht_pxh + vy * ht_pyh)) / pitch) + 2;
    if (m1 - m0 > 100000)
        return 0;
    for (m = m0; m <= m1; m++) {
        double o = m * pitch;   /* the row, measured across */
        int nt = hatch_cut(o, vx, vy, ux, uy, t), k, k0, k1, i;

        for (i = 0; i + 1 < nt; i += 2) {
            if (t[i + 1] - t[i] <= 0.0)
                continue;
            k0 = (int)floor((t[i] - (ux * rx + uy * ry)
                             + (ux * ht_pxl + uy * ht_pyl)) / gap) - 1;
            k1 = (int)ceil((t[i + 1] - (ux * rx + uy * ry)
                            + (ux * ht_pxh + uy * ht_pyh)) / gap) + 1;
            if (k1 - k0 > 100000)
                return made;
            for (k = k0; k <= k1; k++) {
                double lx = k * gap * ux + o * vx;
                double ly = k * gap * uy + o * vy;
                double dx = lx - rx, dy = ly - ry;
                double x0 = ht_pxl + dx, y0 = ht_pyl + dy;
                double x1 = ht_pxh + dx, y1 = ht_pyh + dy;
                double au, bu, av, bv;

                /* the box round the copy, across and along */
                av = vx * x0 + vy * y0;
                bv = vx * x1 + vy * y1;
                if (bv < av) { double s = av; av = bv; bv = s; }
                au = ux * x0 + uy * y0;
                bu = ux * x1 + uy * y1;
                if (bu < au) { double s = au; au = bu; bu = s; }
                if (av <= alo || ahi <= bv)
                    continue;
                if (au <= t[i] || t[i + 1] <= bu)
                    continue;
                made += hatch_stamp(d, dx, dy);
            }
        }
    }
    return made;
}

static void hatch(jw_drawing *d)
{
    const char *sa = jw_cmd_box(1419), *sp = jw_cmd_box(1411);
    const char *sg = jw_cmd_box(1412);
    double ang = box_num(sa, 0.0), pitch = box_num(sp, 0.0);
    double gap = box_num(sg, 0.0);
    double ux, uy, nx, ny, lo, hi, o, bo;
    int k, k0, k1, made = 0, extra = 0;

    if (ht_mode < 1689 || ht_mode > 1693)
        return;
    if (pitch <= 0.0)
        return;
    if (ht_mode != 1689 && ht_mode != 1693) {
        if (gap <= 0.0)
            return;
        /* a group whose middle falls outside the region can still have a
           line of its own inside it */
        extra = 1;
    }
    if (ht_nreg <= 0)
        return;
    if (ht_jisun) {             /* 実寸: the numbers are the drawing's own */
        int wg = 0, k;

        for (k = 0; k < 16; k++)
            if (d->group[k].state == 3)
                wg = k;
        if (d->group[wg].scale > 0.0) {
            pitch /= d->group[wg].scale;
            gap /= d->group[wg].scale;
        }
    }
    ux = cos(ang * PI / 180.0);
    uy = sin(ang * PI / 180.0);
    nx = uy;                    /* turn the direction a quarter turn */
    ny = -ux;
    if (ht_mode == 1693) {      /* 図形 -- the pattern, tiled */
        made = hatch_figs(d, ux, uy, pitch, gap);
        if (made)
            op_push(made);
        return;
    }
    if (ht_mode == 1692) {      /* ┬┴┬ -- ピッチ is 縦ピッチ, 線間隔 is 横ピッチ */
        made = hatch_grid(d, ux, uy, nx, ny, pitch, gap);
        if (made)
            op_push(made);
        return;
    }
    hatch_span(nx, ny, &lo, &hi);
    bo = ht_base ? nx * ht_bx + ny * ht_by : 0.0;
    /* Count in doubles first.  A pitch the dialog will accept can be as
       small as it likes, and (lo - bo) / pitch then leaves the range of an
       int, where the cast itself is undefined -- and the subtraction that
       was catching a runaway count would overflow before it could.  Written
       as !(span <= n) so that a NaN, from a pitch of zero, also turns back. */
    {
        double dlo = ceil((lo - bo) / pitch);
        double dhi = floor((hi - bo) / pitch);

        if (!(dhi - dlo <= 100000.0))
            return;
        k0 = jw_whole(dlo);
        k1 = jw_whole(dhi);
    }
    /* the original goes from the far side back: its first line is the one at
       the highest offset, and inside a ２線 or ３線 group the same way round
       -- 301, 300, 299, then 291, 290, 289 */
    for (k = k1 + extra; k >= k0 - extra; k--) {
        o = bo + k * pitch;
        switch (ht_mode) {
        case 1690:
            made += hatch_at(d, o + gap / 2, ux, uy, nx, ny);
            made += hatch_at(d, o - gap / 2, ux, uy, nx, ny);
            break;
        case 1691:
            made += hatch_at(d, o + gap, ux, uy, nx, ny);
            made += hatch_at(d, o, ux, uy, nx, ny);
            made += hatch_at(d, o - gap, ux, uy, nx, ny);
            break;
        default:
            made += hatch_at(d, o, ux, uy, nx, ny);
            break;
        }
    }
    if (made)
        op_push(made);
}

/* Where the region cuts the line that runs along (bx, by) at offset `o`
 * across it, as pairs of positions along that line.  ┬┴┬ needs this with the
 * two directions the other way round -- its cross pieces run across the hatch
 * rather than along it -- so the two vectors are arguments. */
static int hatch_cut(double o, double ax, double ay, double bx, double by,
                     double *t)
{
    int i, g, nt = 0;

    for (g = 0; g < ht_nreg; g++) {
        if (ht_reg[g].round) {
            double dd = o - (ax * ht_reg[g].cx + ay * ht_reg[g].cy);
            double h = ht_reg[g].r * ht_reg[g].r - dd * dd;
            double mid;

            if (h <= 0.0)
                continue;       /* this one misses the circle */
            h = sqrt(h);
            mid = bx * ht_reg[g].cx + by * ht_reg[g].cy;
            if (nt + 2 <= HT_MAX) {
                t[nt++] = mid - h;
                t[nt++] = mid + h;
            }
            continue;
        }
        for (i = ht_reg[g].first; i + 1 < ht_reg[g].first + ht_reg[g].n; i++) {
            double a0 = ax * ht_x[i] + ay * ht_y[i];
            double a1 = ax * ht_x[i + 1] + ay * ht_y[i + 1];
            double f;

            if ((a0 <= o) == (a1 <= o))
                continue;       /* the edge does not cross this line */
            f = (o - a0) / (a1 - a0);
            if (nt < HT_MAX)
                t[nt++] = bx * (ht_x[i] + f * (ht_x[i + 1] - ht_x[i]))
                        + by * (ht_y[i] + f * (ht_y[i + 1] - ht_y[i]));
        }
    }
    /* sorted across every region together, so two of them side by side come
       out in one run of chords the way the original draws them */
    for (i = 1; i < nt; i++) {
        double v = t[i];
        int j = i - 1;
        while (j >= 0 && t[j] > v) { t[j + 1] = t[j]; j--; }
        t[j + 1] = v;
    }
    return nt;
}

/* How far the region reaches along (ax, ay). */
static void hatch_span(double ax, double ay, double *lo, double *hi)
{
    int i, g, first = 1;

    *lo = *hi = 0.0;
    for (g = 0; g < ht_nreg; g++) {
        double a, b;

        if (ht_reg[g].round) {
            a = ax * ht_reg[g].cx + ay * ht_reg[g].cy - ht_reg[g].r;
            b = a + 2 * ht_reg[g].r;
        } else {
            a = b = ax * ht_x[ht_reg[g].first] + ay * ht_y[ht_reg[g].first];
            for (i = ht_reg[g].first + 1;
                 i < ht_reg[g].first + ht_reg[g].n; i++) {
                double o = ax * ht_x[i] + ay * ht_y[i];

                if (o < a) a = o;
                if (o > b) b = o;
            }
        }
        if (first || a < *lo) *lo = a;
        if (first || b > *hi) *hi = b;
        first = 0;
    }
}

static int hatch_at(jw_drawing *d, double o, double ux, double uy,
                    double nx, double ny)
{
    double t[HT_MAX];
    int i, nt = hatch_cut(o, nx, ny, ux, uy, t), made = 0;
    jw_obj *ob;

    for (i = 0; i + 1 < nt; i += 2) {
        if (t[i + 1] - t[i] <= 0.0)
            continue;
        ob = jw_add(d, JW_SEN);
        if (!ob)
            return made;
        ob->d[0] = ux * t[i] + nx * o;
        ob->d[1] = uy * t[i] + ny * o;
        ob->d[2] = ux * t[i + 1] + nx * o;
        ob->d[3] = uy * t[i + 1] + ny * o;
        made++;
    }
    return made;
}

/* ┬┴┬ (1692): a running bond, the way a brick wall is drawn.
 *
 * Lines all the way across the region every 縦ピッチ, and between them short
 * cross pieces every 横ピッチ, half a 横ピッチ out of step from one course to
 * the next.  Read off two runs of the original (decomp/res/hatch_r1692.jww,
 * 角度 0・縦 3・横 6, and hatch_r1692b.jww, 角度 30・縦 20・横 50):
 *
 *   - the long lines sit where q, the distance across the hatch, is a whole
 *     multiple of 縦ピッチ -- anchored at zero like every other hatch -- and
 *     each is the chord of the region there;
 *   - the cross pieces sit where p, the distance along the hatch, is a whole
 *     multiple of **half** the 横ピッチ.  Call that multiple m and number the
 *     courses by k (the one from k*縦 to (k+1)*縦): a piece is drawn when
 *     **m + k is even**, which is what staggers them;
 *   - each piece is one course long and is cut to the region like the lines
 *     are -- the original left a 0.53 long stub where a course ran off the
 *     bottom edge;
 *   - the order is: the long lines with q rising, then every column with m
 *     even, p falling, then every column with m odd.  Inside a column the
 *     pieces come with q rising.
 */
static int hatch_grid(jw_drawing *d, double ux, double uy, double nx, double ny,
                      double vp, double hp)
{
    /* the other way across: q = n2.point rises where the offset o falls */
    double n2x = -nx, n2y = -ny;
    double qlo, qhi, plo, phi, half = hp / 2;
    double bq = ht_base ? n2x * ht_bx + n2y * ht_by : 0.0;
    double bp = ht_base ? ux * ht_bx + uy * ht_by : 0.0;
    int k, klo, khi, m, mlo, mhi, par, made = 0;

    hatch_span(n2x, n2y, &qlo, &qhi);
    hatch_span(ux, uy, &plo, &phi);
    /* in doubles first, for the reason the other hatch gives */
    {
        double dklo = ceil((qlo - bq) / vp), dkhi = floor((qhi - bq) / vp);
        double dmlo = ceil((plo - bp) / half), dmhi = floor((phi - bp) / half);

        if (!(dkhi - dklo <= 100000.0) || !(dmhi - dmlo <= 100000.0))
            return 0;
        klo = jw_whole(dklo);
        khi = jw_whole(dkhi);
        mlo = jw_whole(dmlo);
        mhi = jw_whole(dmhi);
    }
    for (k = klo; k <= khi; k++)
        made += hatch_at(d, -(bq + k * vp), ux, uy, nx, ny);
    for (par = 0; par < 2; par++)
        for (m = mhi; m >= mlo; m--) {
            double t[HT_MAX], p = bp + m * half;
            int nt, i;

            if (((m % 2) + 2) % 2 != par)
                continue;
            nt = hatch_cut(p, ux, uy, n2x, n2y, t);
            /* one course below the lowest line to one above the highest: a
               course can be cut off by the region and still show */
            for (k = klo - 1; k <= khi; k++) {
                double qa = bq + k * vp, qb = qa + vp;

                if (((m + k) % 2 + 2) % 2 != 0)
                    continue;
                for (i = 0; i + 1 < nt; i += 2) {
                    double a = t[i] > qa ? t[i] : qa;
                    double b = t[i + 1] < qb ? t[i + 1] : qb;
                    jw_obj *ob;

                    if (b - a <= 0.0)
                        continue;
                    ob = jw_add(d, JW_SEN);
                    if (!ob)
                        return made;
                    ob->d[0] = ux * p + n2x * a;
                    ob->d[1] = uy * p + n2y * a;
                    ob->d[2] = ux * p + n2x * b;
                    ob->d[3] = uy * p + n2y * b;
                    made++;
                }
            }
        }
    return made;
}

/* 接線 角度指定 (1691) and 円上点指定 (1692).
 *
 * Both settle on a line that touches the circle and then take two points
 * along it, and the original asks for them in the same words as the 線
 * command -- 「始点を指示してください」「終点を指示してください」.  Read out of
 * the status line, which WM_GETTEXT hands over (tools/jwdraw.ps1's
 * `read:59393`).
 *
 *   角度指定    circle, 始点, 終点.  The 角度 box gives the direction, and of
 *               the two tangents that way round the one on the side the
 *               circle was pointed at is taken.
 *   円上点指定  circle, a point on it, 始点, 終点.  The point is pulled onto
 *               the circle -- centre plus the radius that way -- and the
 *               tangent there is the line.
 *
 * The ends are the two points **dropped onto the line**, not the points
 * themselves: the original was clicked well off the line both times and the
 * segment came back exactly between the two feet (decomp/res/sesang_*.jww,
 * sescpt_*.jww -- 396.5883 long from clicks 500 pixels apart).
 */
static void sesline(jw_drawing *d, const jw_view *v, double x, double y)
{
    const jw_obj *c;
    int i;

    if (ses_step == 0) {                /* the circle */
        i = jw_pick(d, v, x, y, 3);
        if (i < 0 || d->obj[i].cls != JW_ENKO || d->obj[i].d[2] <= 0.0)
            return;
        ses_a = i;
        ses_x = x;
        ses_y = y;
        ses_step = 1;
        if (ses_mode == 1691) {
            const char *sa = jw_cmd_box(1412);
            double ang = box_num(sa, 0.0);
            double nx, ny, side;

            c = &d->obj[i];
            ses_ux = cos(ang * PI / 180.0);
            ses_uy = sin(ang * PI / 180.0);
            nx = -ses_uy;
            ny = ses_ux;
            side = nx * (x - c->d[0]) + ny * (y - c->d[1]) < 0.0 ? -1.0 : 1.0;
            ses_lx = c->d[0] + side * c->d[2] * nx;
            ses_ly = c->d[1] + side * c->d[2] * ny;
            ses_step = 2;       /* the line is settled; the points are next */
        }
        return;
    }
    if (ses_a < 0 || ses_a >= d->nobj || d->obj[ses_a].cls != JW_ENKO) {
        ses_step = 0;
        return;
    }
    c = &d->obj[ses_a];
    if (ses_step == 1) {                /* 円上点: pull it onto the circle */
        double dx = x - c->d[0], dy = y - c->d[1];
        double L = sqrt(dx * dx + dy * dy);

        if (L <= 0.0)
            return;
        ses_lx = c->d[0] + c->d[2] * dx / L;
        ses_ly = c->d[1] + c->d[2] * dy / L;
        ses_ux = -dy / L;               /* a quarter turn from the radius */
        ses_uy = dx / L;
        ses_step = 2;
        return;
    }
    if (ses_step == 2) {                /* 始点 */
        ses_t0 = ses_ux * (x - ses_lx) + ses_uy * (y - ses_ly);
        ses_step = 3;
        return;
    }
    {                                   /* 終点 */
        double t1 = ses_ux * (x - ses_lx) + ses_uy * (y - ses_ly);
        jw_obj *o = jw_add(d, JW_SEN);

        ses_step = 0;
        ses_a = -1;
        if (!o)
            return;
        o->d[0] = ses_lx + ses_ux * ses_t0;
        o->d[1] = ses_ly + ses_uy * ses_t0;
        o->d[2] = ses_lx + ses_ux * t1;
        o->d[3] = ses_ly + ses_uy * t1;
        op_push(1);
    }
}

/* 接円 (0x8068) -- a circle that touches what was picked.
 *
 * The bar asks for 「１番目の線・円」「２番目の線・円」, so an element is
 * either a line or a circle, and this holds whichever it is: a line as the
 * unit normal and its offset, a circle as its centre and radius.
 */
typedef struct {
    int circle;
    int pt;                     /* a point read with (R): a circle of r 0 */
    double nx, ny, k;           /* a line: n.point == k */
    double cx, cy, r;           /* a circle */
} sek_el;

static int sek_elem(const jw_obj *o, sek_el *e)
{
    e->pt = 0;
    if (o->cls == JW_SEN) {
        double ux = o->d[2] - o->d[0], uy = o->d[3] - o->d[1];
        double L = sqrt(ux * ux + uy * uy);

        if (L < 1e-12)
            return 0;
        e->circle = 0;
        e->nx = -uy / L;
        e->ny = ux / L;
        e->k = e->nx * o->d[0] + e->ny * o->d[1];
        return 1;
    }
    /* an ellipse is turned away when it is picked, 「楕円は計算できません。」
       (0x145e, the flatness checked against 1 in FUN_00707130) */
    if (o->cls == JW_ENKO && o->d[2] > 0.0 && fabs(o->d[6] - 1.0) < 1e-7) {
        e->circle = 1;
        e->cx = o->d[0];
        e->cy = o->d[1];
        e->r = o->d[2];
        return 1;
    }
    return 0;
}

/* Where can the centre of a circle of radius `r` be, if it touches both of
 * these?  A line puts it on one of the two lines `r` away, a circle on one of
 * the two circles `r` out or `r` in -- four pairings in all, and each pairing
 * leaves nought, one or two places.  The original counts them out loud:
 * two crossed lines said 【 4 − 1 】, a line and a circle 【 2 − 2 】 and two
 * circles 【 6 − 1 】, which is what these four pairings give.
 */
#define SEK_MAX 8
static int sek_places(const sek_el *p, const sek_el *q, double r,
                      double *px, double *py)
{
    int s1, s2, n = 0;

    for (s1 = -1; s1 <= 1; s1 += 2)
        for (s2 = -1; s2 <= 1; s2 += 2) {
            /* a point is a circle of r 0, so r out and r in are the one
               circle -- FUN_00707d60 takes it once (its cases 2, 3, 6) */
            if ((p->pt && s1 < 0) || (q->pt && s2 < 0))
                continue;
            if (!p->circle && !q->circle) {
                double a1 = p->k + s1 * r, a2 = q->k + s2 * r;
                double den = p->nx * q->ny - p->ny * q->nx;

                if (fabs(den) < 1e-12)
                    continue;   /* parallel: nothing, unless 2r apart */
                px[n] = (a1 * q->ny - a2 * p->ny) / den;
                py[n] = (p->nx * a2 - q->nx * a1) / den;
                n++;
            } else if (p->circle && q->circle) {
                /* two circles, centres apart by L: the usual intersection */
                double d1 = fabs(p->r + s1 * r), d2 = fabs(q->r + s2 * r);
                double ex = q->cx - p->cx, ey = q->cy - p->cy;
                double L = sqrt(ex * ex + ey * ey), a, h2;

                if (L < 1e-12)
                    continue;
                a = (L * L + d1 * d1 - d2 * d2) / (2 * L);
                h2 = d1 * d1 - a * a;
                if (h2 < 0.0)
                    continue;
                h2 = sqrt(h2);
                ex /= L;
                ey /= L;
                px[n] = p->cx + a * ex - h2 * ey;
                py[n] = p->cy + a * ey + h2 * ex;
                n++;
                if (h2 > 1e-9) {
                    px[n] = p->cx + a * ex + h2 * ey;
                    py[n] = p->cy + a * ey - h2 * ex;
                    n++;
                }
            } else {
                /* a line and a circle: drop the circle's centre on the line
                   `r` away and come back along it */
                const sek_el *l = p->circle ? q : p;
                const sek_el *c = p->circle ? p : q;
                double sl = p->circle ? s2 : s1, sc = p->circle ? s1 : s2;
                double off = l->k + sl * r;
                double d = fabs(c->r + sc * r);
                double t = off - (l->nx * c->cx + l->ny * c->cy);
                double fx = c->cx + t * l->nx, fy = c->cy + t * l->ny;
                double h2 = d * d - t * t;

                if (h2 < 0.0)
                    continue;
                h2 = sqrt(h2);
                px[n] = fx - h2 * l->ny;    /* along the line */
                py[n] = fy + h2 * l->nx;
                n++;
                if (h2 > 1e-9) {
                    px[n] = fx + h2 * l->ny;
                    py[n] = fy - h2 * l->nx;
                    n++;
                }
            }
            if (n > SEK_MAX - 2)
                return n;
        }
    return n;
}

/* 多重円 (the box beside it, 1417): that many circles sharing the centre,
 * the radius divided up.  Three of them leaves r, 2r/3 and r/3, biggest
 * first, and it works the same for the three-element kind
 * (decomp/res/sekmul_*.jww).
 */
static int sek_draw(jw_drawing *d, double cx, double cy, double r);

static jw_obj *sek_add(jw_drawing *d, double cx, double cy, double r)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    if (!o)
        return 0;
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = 0.0;
    o->d[4] = 6.283185307179586;        /* the whole way round */
    o->d[5] = 0.0;
    o->d[6] = 1.0;                      /* round, not squashed */
    o->n = 1;                           /* the trailing 1 a whole circle has */
    return o;
}

static int sek_draw(jw_drawing *d, double cx, double cy, double r)
{
    const char *sn = jw_cmd_box(1417);
    int n = sn ? atoi(sn) : 0, k, made = 0;

    if (n < 1)
        n = 1;
    if (n > 64)
        n = 64;
    for (k = n; k >= 1; k--)
        if (sek_add(d, cx, cy, r * k / n))
            made++;
    return made;
}

/* The 半径 box, in the drawing's own units. */
static double sek_radius(const jw_drawing *d)
{
    const char *sz = jw_cmd_box(1411);
    double r = fabs(box_num(sz, 0.0));  /* the original takes its size */
    int wg = 0, i;

    if (r <= 0.0)
        return 0.0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        r /= d->group[wg].scale;
    return r;
}

/* One picked thing: element `i`, or with `pt` the point (x, y) read with
 * the right button (the original keeps a null element and the point). */
static int sek_get(const jw_drawing *d, int i, int pt, double x, double y,
                   sek_el *e)
{
    if (pt) {
        e->circle = 1;
        e->pt = 1;
        e->cx = x;
        e->cy = y;
        e->r = 0.0;
        return 1;
    }
    if (i < 0 || i >= d->nobj)
        return 0;
    return sek_elem(&d->obj[i], e);
}

/* How many places the first two leave for the radius in the box -- the
 * original counts them when the second is picked (FUN_00707d60) and says
 * 「計算できません」 at once if there are none. */
static int sek_count(const jw_drawing *d, int b, int bpt, double bx,
                     double by)
{
    sek_el p, q;
    double px[SEK_MAX], py[SEK_MAX], r = sek_radius(d);

    if (r <= 0.0 || !sek_get(d, sek_a, sek_apt, sek_ax, sek_ay, &p)
        || !sek_get(d, b, bpt, bx, by, &q))
        return 0;
    return sek_places(&p, &q, r, px, py);
}

/* The place nearest the click, by |dx| + |dy| and the first of a tie
 * (FUN_0070b570, against the cursor kept at +0x108). */
static void sekien(jw_drawing *d, double x, double y)
{
    sek_el p, q;
    double px[SEK_MAX], py[SEK_MAX], r, bestd = 9999999.0;
    int i, n, best = -1;

    if (!sek_apt && !sek_bpt && sek_a == sek_b)
        return;
    if (!sek_get(d, sek_a, sek_apt, sek_ax, sek_ay, &p)
        || !sek_get(d, sek_b, sek_bpt, sek_bx, sek_by, &q))
        return;
    r = sek_radius(d);
    if (r <= 0.0)
        return;                 /* no radius typed in: nothing to draw */
    n = sek_places(&p, &q, r, px, py);
    for (i = 0; i < n; i++) {
        double e = fabs(px[i] - x) + fabs(py[i] - y);

        if (e < bestd) {
            best = i;
            bestd = e;
        }
    }
    if (best < 0)
        return;
    n = sek_draw(d, px[best], py[best], r);
    if (n)
        op_push(n);
}

/* 接円, three elements and an empty 半径 box: the circle that touches all
 * three, drawn the moment the third is picked -- no placing click.
 *
 * The original does not solve for it; it walks to it from where the three
 * were picked (FUN_00709940, by reading the decompilation -- the original was
 * not driven for the circle cases).  Each element keeps a touch point, which
 * starts as its pick point, and each round
 *
 *   - puts every touch point back on its element (FUN_0045b6c0: the foot of
 *     the perpendicular on a line, straight out from the centre on a circle),
 *   - takes the circle through the three (FUN_0070ae60), and
 *   - moves every touch point to the middle of the chord that circle cuts
 *     from its element (FUN_0070ace0 over FUN_0045fa30, lines taken as
 *     endless and circles whole).
 *
 * It stops when no touch point moved by 1e-7 in either direction, and gives
 * up past 50 rounds, or if a circle cannot be made or misses an element --
 * 「計算できません」 then.  So which of the circles that touch all three comes
 * out is the one the pick points lead to; for three lines that has been the
 * one inside them however they were picked (three runs pointed at quite
 * different parts of the same three lines came back with the same circle,
 * decomp/res/sek3.jww), and with circles among them the side of each circle
 * that was picked decides (not driven in the original).
 *
 * The original also takes a point read with the right button in place of an
 * element (the circle then passes through it, and FUN_0070b8f0 checks for one
 * read off another of the picked elements); the port's picks are elements
 * only, so that is not here.
 */
static int sek_onto(const sek_el *e, double *tx, double *ty)
{
    double dx, dy, L;

    if (!e->circle) {
        double s = e->nx * *tx + e->ny * *ty - e->k;

        *tx -= s * e->nx;
        *ty -= s * e->ny;
        return 1;
    }
    dx = *tx - e->cx;
    dy = *ty - e->cy;
    if (fabs(dx) + fabs(dy) < 1e-7)
        return 0;               /* at the centre: no way out from it */
    L = sqrt(dx * dx + dy * dy);
    *tx = e->cx + e->r * dx / L;
    *ty = e->cy + e->r * dy / L;
    return 1;
}

/* the middle of the chord the circle (ox, oy, R) cuts from the element */
static int sek_chord(const sek_el *e, double ox, double oy, double R,
                     double *tx, double *ty)
{
    double ex, ey, L, a;

    if (!e->circle) {
        double s = e->nx * ox + e->ny * oy - e->k;

        if (fabs(s) - R > 1e-7)
            return 0;
        *tx = ox - s * e->nx;
        *ty = oy - s * e->ny;
        return 1;
    }
    /* FUN_00460710's two circles: none if apart or one inside the other,
       and a touch counts within 1e-7 */
    ex = ox - e->cx;
    ey = oy - e->cy;
    L = ex * ex + ey * ey;
    if (L < 1e-7)
        return 0;
    L = sqrt(L);
    if (L > e->r + R + 1e-7 || L < fabs(e->r - R) - 1e-7)
        return 0;
    if (L >= e->r + R - 1e-7 || L <= fabs(e->r - R) + 1e-7)
        a = (L <= fabs(e->r - R) + 1e-7 && e->r < R) ? -e->r : e->r;
    else
        a = (e->r * e->r - R * R + L * L) / (2 * L);
    *tx = e->cx + a * ex / L;
    *ty = e->cy + a * ey / L;
    return 1;
}

/* FUN_0070ae60: the circle through three points; two of them the same and it
 * is the one with the other two across it */
static int sek_circ3(const double *px, const double *py,
                     double *ox, double *oy, double *R)
{
    double qx = px[1], qy = py[1], ux, uy, d, x3, y3, cx, cy;
    int same = 0;

#define SEK_EQ(ax, ay, bx, by) (fabs((ax) - (bx)) < 1e-7 && fabs((ay) - (by)) < 1e-7)
    if (SEK_EQ(px[0], py[0], px[1], py[1])
        && SEK_EQ(px[1], py[1], px[2], py[2]))
        return 0;
    if (SEK_EQ(px[0], py[0], px[1], py[1])) {
        same = 1;
        qx = px[2];
        qy = py[2];
    }
    if (SEK_EQ(qx, qy, px[2], py[2]) || SEK_EQ(px[2], py[2], px[0], py[0]))
        same = 1;
#undef SEK_EQ
    if (same) {
        double hx = qx - px[0], hy = qy - py[0];

        *ox = px[0] + hx / 2;
        *oy = py[0] + hy / 2;
        *R = sqrt(hx * hx + hy * hy) / 2;
        return *R >= 1e-7;
    }
    /* in a frame at the first point, its x along to the second */
    ux = px[1] - px[0];
    uy = py[1] - py[0];
    d = sqrt(ux * ux + uy * uy);
    ux /= d;
    uy /= d;
    x3 = ux * (px[2] - px[0]) + uy * (py[2] - py[0]);
    y3 = ux * (py[2] - py[0]) - uy * (px[2] - px[0]);
    if (fabs(y3) < 1e-7)
        return 0;               /* in a row */
    cx = d / 2;
    cy = (x3 * x3 - 2 * x3 * cx + y3 * y3) / (2 * y3);
    *R = sqrt(cx * cx + cy * cy);
    if (*R < 1e-7)
        return 0;
    *ox = px[0] + ux * cx - uy * cy;
    *oy = py[0] + uy * cx + ux * cy;
    return 1;
}

static void sekien3(jw_drawing *d, int c, int cpt, double x, double y)
{
    sek_el e[3];
    double tx[3], ty[3], ox = 0, oy = 0, R = 0;
    int i, j, k;

    if (!sek_get(d, sek_a, sek_apt, sek_ax, sek_ay, &e[0])
        || !sek_get(d, sek_b, sek_bpt, sek_bx, sek_by, &e[1])
        || !sek_get(d, c, cpt, x, y, &e[2]))
        return;
    /* a point read off one of the other two picked elements: the original
       makes the circle touch that element at the point, by a frame turned
       onto it (FUN_0070b8f0 finds it, the 0x3c0 frame in FUN_00709940).
       That frame was not read through, so nothing is drawn for it here. */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (i != j && !e[i].pt && e[j].pt) {
                double qx = e[j].cx, qy = e[j].cy;

                if (sek_onto(&e[i], &qx, &qy) && fabs(qx - e[j].cx) < 1e-7
                    && fabs(qy - e[j].cy) < 1e-7)
                    return;
            }
    tx[0] = sek_ax;
    ty[0] = sek_ay;
    tx[1] = sek_bx;
    ty[1] = sek_by;
    tx[2] = x;
    ty[2] = y;
    for (k = 1; k < 60; k++) {
        double was_x[3], was_y[3];
        int moved = 0;

        for (i = 0; i < 3; i++) {
            was_x[i] = tx[i];
            was_y[i] = ty[i];
            if (!e[i].pt && !sek_onto(&e[i], &tx[i], &ty[i]))
                return;
        }
        if (!sek_circ3(tx, ty, &ox, &oy, &R))
            return;
        for (i = 0; i < 3; i++)
            if (!e[i].pt && !sek_chord(&e[i], ox, oy, R, &tx[i], &ty[i]))
                return;
        for (i = 0; i < 3; i++)
            if (fabs(tx[i] - was_x[i]) >= 1e-7
                || fabs(ty[i] - was_y[i]) >= 1e-7)
                moved = 1;
        if (!moved)
            break;
        if (k > 50)
            return;             /* 計算できません */
    }
    if (!sek_circ3(tx, ty, &ox, &oy, &R))
        return;
    i = sek_draw(d, ox, oy, R);
    if (i)
        op_push(i);
}

static void tensen(jw_drawing *d, int b, double px, double py,
                   double x, double y)
{
    const jw_obj *q;
    double cx, cy, r, dx, dy, L, ux, uy, ca, sa, tx, ty, t2x, t2y;
    jw_obj *o;

    if (b < 0 || b >= d->nobj)
        return;
    q = &d->obj[b];
    if (q->cls != JW_ENKO || q->d[2] <= 0.0)
        return;
    cx = q->d[0];
    cy = q->d[1];
    r = q->d[2];
    dx = px - cx;
    dy = py - cy;
    L = sqrt(dx * dx + dy * dy);
    if (L <= r)
        return;                 /* inside it: no tangent from there */
    ux = dx / L;
    uy = dy / L;
    ca = r / L;
    sa = sqrt(1.0 - ca * ca);
    tx = cx + r * (ca * ux - sa * uy);
    ty = cy + r * (ca * uy + sa * ux);
    t2x = cx + r * (ca * ux + sa * uy);
    t2y = cy + r * (ca * uy - sa * ux);
    if ((t2x - x) * (t2x - x) + (t2y - y) * (t2y - y)
        < (tx - x) * (tx - x) + (ty - y) * (ty - y)) {
        tx = t2x;
        ty = t2y;
    }
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->d[0] = px;
    o->d[1] = py;
    o->d[2] = tx;
    o->d[3] = ty;
    op_push(1);
}

static void sessen(jw_drawing *d, int a, int b, double x, double y)
{
    const jw_obj *p, *q;
    double bestd = 0, bp[4] = { 0, 0, 0, 0 };
    int sa, sb, have = 0;
    jw_obj *o;

    if (a < 0 || b < 0 || a >= d->nobj || b >= d->nobj)
        return;
    p = &d->obj[a];
    q = &d->obj[b];
    if (p->cls != JW_ENKO || q->cls != JW_ENKO)
        return;
    if (p->d[2] <= 0.0 || q->d[2] <= 0.0)
        return;
    for (sa = -1; sa <= 1; sa += 2)
        for (sb = -1; sb <= 1; sb += 2) {
            double tx, ty, ux, uy, e;

            if (!tangent(p->d[0], p->d[1], p->d[2],
                         q->d[0], q->d[1], q->d[2], sa, sb,
                         &tx, &ty, &ux, &uy))
                continue;
            e = (tx - ses_x) * (tx - ses_x) + (ty - ses_y) * (ty - ses_y)
              + (ux - x) * (ux - x) + (uy - y) * (uy - y);
            if (!have || e < bestd) {
                have = 1;
                bestd = e;
                bp[0] = tx; bp[1] = ty; bp[2] = ux; bp[3] = uy;
            }
        }
    if (!have)
        return;
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->d[0] = bp[0];
    o->d[1] = bp[1];
    o->d[2] = bp[2];
    o->d[3] = bp[3];
    op_push(1);
}

static void sel_free(void)
{
    free(sel_was);
    free(sel_at);
    sel_was = 0;
    sel_at = 0;
    sel_n = 0;
}

int jw_cmd_sel_count(const jw_drawing *d)
{
    int i, n = 0;

    if (!d)
        return 0;
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].sel)
            n++;
    return n;
}

/* タグジャンプ (32967) works on a single picked text: its text, or 0 when
   what is picked is not exactly one text.  The menu item is greyed the
   same way (FUN_00511ca0). */
int jw_cmd_sel_text(const jw_drawing *d, char *out, int cap)
{
    int i, n = 0, at = -1;

    if (!d || cap < 1)
        return 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].sel) {
            n++;
            at = i;
        }
    if (n != 1 || d->obj[at].cls != JW_MOJI)
        return 0;
    strncpy(out, jw_str(d, d->obj[at].text), (size_t)cap - 1);
    out[cap - 1] = 0;
    return 1;
}

static void sel_mirror(jw_drawing *d, const jw_obj *axis);

static void sel_clear(jw_drawing *d)
{
    int i, any = 0;

    if (d) {
        for (i = 0; i < d->nobj && !any; i++)
            any = d->obj[i].sel != 0;
        for (i = 0; i < d->nobj; i++) {
            if (any)            /* the last selection, for 前範囲 */
                d->obj[i].was_sel = d->obj[i].sel != 0;
            d->obj[i].flags = (unsigned short)(d->obj[i].flags & ~2u);
            d->obj[i].sel = 0;
        }
    }
    sel_free();
}

/* Everything the box holds whole.  An element that only crosses it is left
 * alone: the original was given a box over Test5 and saved it, and of the
 * lines that crossed the box not one came back with the flag on, while
 * every line inside it did.  Texts are in only when the second corner was
 * the right button -- 「(L)文字を除く (R)文字を含む」, string 5326, and the
 * same run bears it out: 28 texts sat inside the box and a left click took
 * none of them. */
/* How much of a line lies in the box, as two numbers along it (0 to 1).
   The usual Liang-Barsky, and 0 when none of it does. */
static int clip_seg(const jw_obj *o, double x0, double y0, double x1,
                    double y1, double *t0, double *t1)
{
    double p[4], q[4];
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    int i;

    p[0] = -dx; q[0] = o->d[0] - x0;
    p[1] =  dx; q[1] = x1 - o->d[0];
    p[2] = -dy; q[2] = o->d[1] - y0;
    p[3] =  dy; q[3] = y1 - o->d[1];
    *t0 = 0.0;
    *t1 = 1.0;
    for (i = 0; i < 4; i++) {
        if (p[i] == 0.0) {
            if (q[i] < 0.0)
                return 0;       /* alongside the edge and outside it */
            continue;
        }
        {
            double t = q[i] / p[i];

            if (p[i] < 0.0) {
                if (t > *t1)
                    return 0;
                if (t > *t0)
                    *t0 = t;
            } else {
                if (t < *t0)
                    return 0;
                if (t < *t1)
                    *t1 = t;
            }
        }
    }
    return *t1 > *t0;
}

/* 切取り選択: cut what crosses the box at its edge, keep the outside pieces
   where the element was, and pick the piece that is inside. */
static void sel_cut_box(jw_drawing *d, double x0, double y0, double x1,
                        double y1)
{
    struct { jw_obj was; double t0, t1; int at; } cut[256];
    int ncut = 0, i, made = 0;
    op_t *rec = 0;

    for (i = 0; i < d->ndrawn && ncut < 256; i++) {
        jw_obj *o = &d->obj[i];
        double a, b, c2, e, t0, t1;

        if (o->cls != JW_SEN)
            continue;
        jw_obj_box(o, &a, &b, &c2, &e);
        if (a >= x0 && c2 <= x1 && b >= y0 && e <= y1)
            continue;           /* wholly inside: picked as it is */
        if (!clip_seg(o, x0, y0, x1, y1, &t0, &t1))
            continue;           /* none of it is in the box */
        if (t1 - t0 < 1e-12)
            continue;
        cut[ncut].was = *o;
        cut[ncut].t0 = t0;
        cut[ncut].t1 = t1;
        cut[ncut].at = i;
        ncut++;
    }
    if (ncut == 0)
        return;
    rec = op_new();
    for (i = 0; i < ncut; i++) {
        const jw_obj *w = &cut[i].was;
        double ax = w->d[0], ay = w->d[1];
        double bx = w->d[2], by = w->d[3];
        double dx = bx - ax, dy = by - ay;
        double t0 = cut[i].t0, t1 = cut[i].t1;
        jw_obj *o = &d->obj[cut[i].at], *p;

        op_keep(rec, d, cut[i].at, 0);
        if (t0 > 1e-12) {       /* the piece before the box stays put */
            o->d[2] = ax + dx * t0;
            o->d[3] = ay + dy * t0;
        } else {                /* nothing before it: the inside piece does */
            o->d[0] = ax + dx * t0;
            o->d[1] = ay + dy * t0;
            o->d[2] = ax + dx * t1;
            o->d[3] = ay + dy * t1;
            o->flags = (unsigned short)(o->flags | 2u);
            o->sel = 1;
        }
        if (t0 > 1e-12) {       /* and the inside piece is a new element */
            p = jw_add(d, JW_SEN);
            if (p) {
                *p = *w;
                p->d[0] = ax + dx * t0;
                p->d[1] = ay + dy * t0;
                p->d[2] = ax + dx * t1;
                p->d[3] = ay + dy * t1;
                p->flags = (unsigned short)(p->flags | 2u);
                p->sel = 1;
                p->id = 0;
                made++;
            }
        }
        if (t1 < 1.0 - 1e-12) { /* and the piece after it, if there is one */
            p = jw_add(d, JW_SEN);
            if (p) {
                *p = *w;
                p->d[0] = ax + dx * t1;
                p->d[1] = ay + dy * t1;
                p->flags = (unsigned short)(p->flags & ~2u);
                p->sel = 0;
                p->id = 0;
                made++;
            }
        }
    }
    op_push(made);
}

static void sel_box(jw_drawing *d, int with_text)
{
    double x0 = sel_x0 < sel_x1 ? sel_x0 : sel_x1;
    double x1 = sel_x0 < sel_x1 ? sel_x1 : sel_x0;
    double y0 = sel_y0 < sel_y1 ? sel_y0 : sel_y1;
    double y1 = sel_y0 < sel_y1 ? sel_y1 : sel_y0;
    int i;

    if (!d)
        return;
    if (current == JW_CMD_PARAM) {      /* 端点だけ入った線も拾う */
        param_box(d, x0, y0, x1, y1, with_text);
        return;
    }
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        double a, b, c2, e;
        int take;

        if (o->cls == JW_MOJI && !with_text && !sel_outside && !sel_cut)
            continue;
        jw_obj_box(o, &a, &b, &c2, &e);
        if (sel_outside)        /* nothing of it inside the box at all */
            take = c2 < x0 || a > x1 || e < y0 || b > y1;
        else
            take = a >= x0 && c2 <= x1 && b >= y0 && e <= y1;
        if (!take)
            continue;
        if (sel_sub) {
            o->flags = (unsigned short)(o->flags & ~2u);
            o->sel = 0;
        } else {
            o->flags = (unsigned short)(o->flags | 2u);
            o->sel = 1;
        }
    }
    if (sel_cut && !sel_outside)
        sel_cut_box(d, x0, y0, x1, y1);
}

/* 範囲選択の始点の (R)「連続線をﾏｳｽ(R)で」.  逆コンパイルの読み、原典では
 * 押していない.  CZukeiSentaku の右（vtable 11 番 FUN_006fda70）は始点の前
 * なら FUN_0040deb0 へ行き、そこは何でも拾って（FUN_0044a270 の 0）、
 *  - 曲線属性の印（要素の +0x04、ここの id）があればその組をまるごと
 *    （FUN_0040f580: 拾ったのが選ばれていれば組ごと外す、でなければ組ごと選ぶ）
 *  - なければ FUN_0040f830 で拾い直して（線・円弧、FUN_0044a270 の 3）連続線。
 * ハッチの範囲選択（CZukeiHachi 11 番 FUN_00675620 の +0x208 の枝）も同じ
 * FUN_006fda70 を呼ぶ.  原典の 曲線属性 の枝はブロックも拾うが、移植の
 * jw_pick はブロックを拾わないのでその枝は無い.
 *
 * FUN_0040f830 のつなぎ方:
 *  - 端点は仮想関数 13 番。円弧は始角と始角+開き角の点（扁平・傾きも）で、
 *    全円は端点なし（FUN_0043af40）。線は両端（FUN_0043ae00、ソリッドもこれ）。
 *    拾ったものの端点が二つ無ければ何もしない（全円を右で押しても始まらない）
 *  - つなぐ相手は線（CDataSen）と円弧（CDataEnko）だけ。拾ったもの自身、
 *    flags の 0x20（ハッチの印）、編集できないレイヤ（FUN_0042dd10）、
 *    曲線属性の付いたもの（+0x04 が 0 でない）は外す
 *  - 端点の一致は x・y それぞれ差が 1e-6 未満
 *  - まず拾ったものの終点から歩く。毎回図面の頭から探して、始点か終点が
 *    今の点に合う最初のもの（データ順で先のもの）を取り、その反対の端へ
 *    進む。分岐は先のものだけが続く。今の点が拾ったものの始点に戻れば
 *    閉じた輪で終わり。行き止まりなら一度だけ始点から逆向きに歩く
 *    （今度は拾ったものの終点に着けば終わり）。足取りは 2000 回で打ち切り
 *  - 拾ったものが選ばれていたら連なりごと外し、でなければ選ばれていない
 *    ものだけ選ぶ（+0x5a を見て FUN_00454ee0）.
 * 移植の選択は sel と flags の bit 1（値 2）を一緒に立てる（sel_clear と同じ）.
 * 返すのは受け付けたか（原典は受けたら +0xc を立てて選択の段へ進む）. */
static int chain_ends(const jw_obj *o, double *x, double *y)
{
    if (o->cls == JW_ENKO) {
        double r = o->d[2], a0 = o->d[3], sw = o->d[4];
        double c = cos(o->d[5]), s = sin(o->d[5]);
        double fl = o->d[6] > 0.0 ? o->d[6] : 1.0;
        int k;

        if (sw == 0.0 || fabs(fabs(sw) - 2.0 * PI) <= 1e-7)
            return 0;           /* 全円 */
        for (k = 0; k < 2; k++) {
            double t = a0 + (k ? sw : 0.0);
            double u = r * cos(t), w = fl * r * sin(t);

            x[k] = o->d[0] + u * c - w * s;
            y[k] = o->d[1] + u * s + w * c;
        }
    } else {
        x[0] = o->d[0];
        y[0] = o->d[1];
        x[1] = o->d[2];
        y[1] = o->d[3];
    }
    return fabs(x[1] - x[0]) <= 1e-7 && fabs(y[1] - y[0]) <= 1e-7 ? 1 : 2;
}

static int chain_at(double ax, double ay, double bx, double by)
{
    return fabs(ax - bx) < 1e-6 && fabs(ay - by) < 1e-6;
}

static void chain_mark(jw_obj *o, int off)
{
    if (off) {
        o->flags = (unsigned short)(o->flags & ~2u);
        o->sel = 0;
    } else if (!o->sel) {
        o->flags = (unsigned short)(o->flags | 2u);
        o->sel = 1;
    }
}

/* `clear`: the port drops what is left picked first, the way its (L) at the
   始点 does (sel_clear), but only once something was hit */
static int sel_rpick(jw_drawing *d, const jw_view *v, double x, double y,
                     int clear)
{
    double sx[2], sy[2];
    int k, i, off;

    if (!d)
        return 0;
    k = jw_pick(d, v, x, y, 0);
    if (k < 0 || k >= d->ndrawn)
        return 0;
    if (d->obj[k].id != 0) {    /* 曲線属性: the whole group (FUN_0040f580) */
        int id = d->obj[k].id;

        off = d->obj[k].sel != 0;
        if (clear) {
            sel_clear(d);
            off = 0;
        }
        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].id == id && (off || jw_pick_editable(d, &d->obj[i])))
                chain_mark(&d->obj[i], off);
        return 1;
    }
    k = jw_pick(d, v, x, y, 3);
    if (k < 0 || k >= d->ndrawn
        || (d->obj[k].cls != JW_SEN && d->obj[k].cls != JW_ENKO
            && d->obj[k].cls != JW_SOLID)
        || chain_ends(&d->obj[k], sx, sy) < 2)
        return 0;
    return chain_walk(d, k, clear);
}

/* FUN_0040f830 の拾い直しから先: k から連続線をたどって選ぶ（外す）。
   複線の 連続線選択 (1066) も使う */
static int chain_walk(jw_drawing *d, int k, int clear)
{
    double sx[2], sy[2], cx, cy, tx, ty;
    char *seen;
    int i, n, off, first = 1, steps = 0, found = 1;

    if (!d || k < 0 || k >= d->ndrawn
        || (d->obj[k].cls != JW_SEN && d->obj[k].cls != JW_ENKO
            && d->obj[k].cls != JW_SOLID)
        || chain_ends(&d->obj[k], sx, sy) < 2)
        return 0;
    off = d->obj[k].sel != 0;
    if (clear) {
        sel_clear(d);
        off = 0;
    }
    n = d->ndrawn;
    seen = (char *)malloc((size_t)n + 1);
    if (!seen)
        return 0;
    for (i = 0; i < n; i++) {
        const jw_obj *o = &d->obj[i];

        seen[i] = i == k || (o->flags & 0x20) || o->id != 0
                  || (o->cls != JW_SEN && o->cls != JW_ENKO)
                  || !jw_pick_editable(d, o);
    }
    chain_mark(&d->obj[k], off);
    cx = sx[1];                 /* from its end, until it comes back to its start */
    cy = sy[1];
    tx = sx[0];
    ty = sy[0];
    while (found) {
        found = 0;
        for (i = 0; i < n; i++) {
            double ex[2], ey[2];

            if (seen[i] || !chain_ends(&d->obj[i], ex, ey))
                continue;
            if (chain_at(ex[0], ey[0], cx, cy)) {
                found = 1;
                cx = ex[1];
                cy = ey[1];
            } else if (chain_at(ex[1], ey[1], cx, cy)) {
                found = 2;
                cx = ex[0];
                cy = ey[0];
            } else
                continue;
            seen[i] = 1;
            chain_mark(&d->obj[i], off);
            break;
        }
        if (chain_at(cx, cy, tx, ty))
            break;              /* a closed ring */
        if (++steps > 2000)
            break;
        if (!found && first) { /* a dead end: the other way, from its start */
            found = 1;
            first = 0;
            cx = sx[0];
            cy = sy[0];
            tx = sx[1];
            ty = sy[1];
        }
    }
    free(seen);
    return 1;
}

int jw_cmd_sel_stage(void)
{
    return sel_step;
}

/* ------------------------------------------------------ データ整理 -----
 * 重複整理 (1064) and 連結整理 (1065), the two of its bar this port does.
 * What each one does was read off the original by giving it a drawing of
 * pairs (tools/mkseiri.c) and pressing one button:
 *
 *  - Two elements exactly on top of each other become one, whatever they
 *    are: the pairs of lines, arcs, points and texts all came back as one.
 *    They have to match in colour, line type and layer -- the three pairs
 *    that differed in one of those were left alone by both buttons.
 *  - Two lines that overlap along part of their length become one line
 *    covering both: -80..-30 and -55..-5 came back as -80..-5.
 *  - Two lines that only meet end to end are joined by 連結整理 and left
 *    alone by 重複整理.  A bent pair is left alone by both.
 *
 * So 連結整理 is 重複整理 and the joining as well; pressing it alone took
 * the duplicates out too.  decomp/res/seiridup.jww and seirijoin.jww are
 * the two answers.  What is left keeps the place in the list of the earlier
 * of the two, and stays picked.
 */
#define SEIRI_EPS 1e-6

static int seiri_attr(const jw_obj *a, const jw_obj *b)
{
    return a->cls == b->cls && a->color == b->color && a->ltype == b->ltype
        && (a->layer & 15) == (b->layer & 15)
        && (a->lgroup & 15) == (b->lgroup & 15);
}

/* The same thing in the same place -- for everything that is not a line,
   where being the same is all there is to it. */
static int seiri_same(const jw_drawing *d, const jw_obj *a, const jw_obj *b)
{
    int k;

    for (k = 0; k < 8; k++)
        if (a->d[k] != b->d[k])
            return 0;
    if (a->cls == JW_MOJI)
        return a->n == b->n
            && !strcmp(jw_str(d, a->text), jw_str(d, b->text));
    return 1;
}

/* Where b's two ends fall along a, measured from a's first point.  Returns
   0 unless b lies on a's own infinite line. */
static int seiri_along(const jw_obj *a, const jw_obj *b, double *len,
                       double *t0, double *t1)
{
    double ux = a->d[2] - a->d[0], uy = a->d[3] - a->d[1];
    double n0, n1;

    *len = sqrt(ux * ux + uy * uy);
    if (*len < SEIRI_EPS)
        return 0;
    ux /= *len;
    uy /= *len;
    n0 = (b->d[0] - a->d[0]) * -uy + (b->d[1] - a->d[1]) * ux;
    n1 = (b->d[2] - a->d[0]) * -uy + (b->d[3] - a->d[1]) * ux;
    if (n0 > SEIRI_EPS || n0 < -SEIRI_EPS
        || n1 > SEIRI_EPS || n1 < -SEIRI_EPS)
        return 0;
    *t0 = (b->d[0] - a->d[0]) * ux + (b->d[1] - a->d[1]) * uy;
    *t1 = (b->d[2] - a->d[0]) * ux + (b->d[3] - a->d[1]) * uy;
    return 1;
}

/* ------------------------------------- データ整理's other four buttons --
 * 色順整理 (1068), 線ソート (1066), 線ｿｰﾄ(色別) (1067) and 文字角度整理
 * (1069).  All four were read off the original with a drawing made for
 * them (tools/mksort.c): six lines whose colours are in no order and six
 * texts turned six ways.
 *
 *  - 色順整理 puts everything picked in colour order and leaves the rest
 *    of the order alone -- a plain stable sort.  Six lines in colours
 *    3,1,5,2,4,6 with six colour-1 texts after them came back as the
 *    colour-1 line, the six texts, and then 2,3,4,5,6
 *    (decomp/res/seiri_col.jww).
 *  - 線ソート turns every line so the pen carries on from where it left
 *    off, and puts them in that order: lines at y 60,10,40,30,50,20 came
 *    back 60,50,40,30,20,10 with every other one running the other way
 *    (seiri_line2.jww).  Only lines move; the texts stayed where they
 *    were (seiri_line.jww).
 *  - 線ｿｰﾄ(色別) is the colour sort and then that, colour by colour, with
 *    the pen carrying from one colour to the next (seiri_colline*.jww).
 *  - 文字角度整理 lays every turned text flat again, keeping the middle of
 *    the box it fills where it was (seiri_ang.jww).
 */
static int seiri_pick(const jw_drawing *d, int *at)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].sel)
            at[n++] = i;
    return n;
}

typedef struct { unsigned short col; int ord; jw_obj o; } seiri_rec;

static int seiri_bycol(const void *a, const void *b)
{
    const seiri_rec *x = (const seiri_rec *)a, *y = (const seiri_rec *)b;

    if (x->col != y->col)
        return x->col < y->col ? -1 : 1;
    return x->ord < y->ord ? -1 : 1;    /* which makes it a stable sort */
}

static void seiri_colour(jw_drawing *d, const int *at, int n, op_t *rec)
{
    seiri_rec *r = (seiri_rec *)malloc((size_t)n * sizeof *r);
    int i;

    if (!r)
        return;
    for (i = 0; i < n; i++) {
        r[i].col = d->obj[at[i]].color;
        r[i].ord = i;
        r[i].o = d->obj[at[i]];
        op_keep(rec, d, at[i], 0);
    }
    qsort(r, (size_t)n, sizeof *r, seiri_bycol);
    for (i = 0; i < n; i++)
        d->obj[at[i]] = r[i].o;
    free(r);
}

/* Which end of a line the pen should reach first, and how far away it is. */
static double seiri_near(const jw_obj *o, double px, double py, int *flip)
{
    double d0 = (o->d[0] - px) * (o->d[0] - px)
              + (o->d[1] - py) * (o->d[1] - py);
    double d1 = (o->d[2] - px) * (o->d[2] - px)
              + (o->d[3] - py) * (o->d[3] - py);

    *flip = d1 < d0;
    return d1 < d0 ? d1 : d0;
}

/* The lines at at[0..n), chained.  The first one is left as it is when the
   pen has not started yet; after that each is the nearest one left. */
static void seiri_sort_lines(jw_drawing *d, const int *at, int n,
                             double *px, double *py, int *started, op_t *rec)
{
    jw_obj *were = (jw_obj *)malloc((size_t)n * sizeof *were);
    char *used;
    int i, k;

    if (!were)
        return;
    used = (char *)calloc((size_t)n, 1);
    if (!used) {
        free(were);
        return;
    }
    for (i = 0; i < n; i++) {
        were[i] = d->obj[at[i]];
        op_keep(rec, d, at[i], 0);
    }
    for (i = 0; i < n; i++) {
        int best = -1, flip = 0, f;
        double bd = 0.0;

        if (!*started) {
            best = 0;
            flip = 0;
        } else {
            for (k = 0; k < n; k++) {
                double dd;

                if (used[k])
                    continue;
                dd = seiri_near(&were[k], *px, *py, &f);
                if (best < 0 || dd < bd) {
                    best = k;
                    bd = dd;
                    flip = f;
                }
            }
        }
        if (best < 0)
            break;
        used[best] = 1;
        d->obj[at[i]] = were[best];
        if (flip) {
            jw_obj *o = &d->obj[at[i]];
            double t;

            t = o->d[0]; o->d[0] = o->d[2]; o->d[2] = t;
            t = o->d[1]; o->d[1] = o->d[3]; o->d[3] = t;
        }
        *px = d->obj[at[i]].d[2];
        *py = d->obj[at[i]].d[3];
        *started = 1;
    }
    free(used);
    free(were);
}

/* 文字角度整理: the text goes flat and the middle of its box stays put. */
static int seiri_flat(jw_drawing *d, const int *at, int n, op_t *rec)
{
    int i, done = 0;

    for (i = 0; i < n; i++) {
        jw_obj *o = &d->obj[at[i]];
        double dx, dy, len, cx, cy, h;

        if (o->cls != JW_MOJI)
            continue;
        dx = o->d[2] - o->d[0];
        dy = o->d[3] - o->d[1];
        len = sqrt(dx * dx + dy * dy);
        if (len < 1e-12 || (dy > -1e-12 && dy < 1e-12 && dx > 0.0))
            continue;                   /* already flat */
        h = o->d[5];
        /* the middle: half way along the baseline and half the height up
           its own perpendicular */
        cx = o->d[0] + dx / 2.0 - dy / len * h / 2.0;
        cy = o->d[1] + dy / 2.0 + dx / len * h / 2.0;
        op_keep(rec, d, at[i], 0);
        o->d[0] = cx - len / 2.0;
        o->d[1] = cy - h / 2.0;
        o->d[2] = o->d[0] + len;
        o->d[3] = o->d[1];
        o->d[7] = 0.0;
        o->sel = 0;                     /* the original's came back unpicked */
        o->flags = (unsigned short)(o->flags & ~2u);
        done++;
    }
    return done;
}

/* One of the four, by the id its button has. */
static int seiri_sort(jw_drawing *d, int id)
{
    int *at, n, i, k, done = 0;
    double px = 0.0, py = 0.0;
    int started = 0;
    op_t *rec;

    if (!d)
        return 0;
    at = (int *)malloc((size_t)(d->ndrawn + 1) * sizeof *at);
    if (!at)
        return 0;
    n = seiri_pick(d, at);
    if (n <= 0) {
        free(at);
        return 0;
    }
    rec = op_new();
    if (id == 1069) {
        done = seiri_flat(d, at, n, rec);
        free(at);
        return done;
    }
    if (id == 1067 || id == 1068)
        seiri_colour(d, at, n, rec);
    if (id == 1066 || id == 1067) {
        int *ln = (int *)malloc((size_t)n * sizeof *ln);

        if (ln) {
            if (id == 1066) {           /* every line, in one run */
                int m = 0;

                for (i = 0; i < n; i++)
                    if (d->obj[at[i]].cls == JW_SEN)
                        ln[m++] = at[i];
                seiri_sort_lines(d, ln, m, &px, &py, &started, rec);
            } else {                    /* colour by colour */
                for (i = 0; i < n; ) {
                    unsigned short c = d->obj[at[i]].color;
                    int m = 0;

                    for (k = i; k < n && d->obj[at[k]].color == c; k++)
                        if (d->obj[at[k]].cls == JW_SEN)
                            ln[m++] = at[k];
                    seiri_sort_lines(d, ln, m, &px, &py, &started, rec);
                    i = k;
                }
            }
            free(ln);
        }
    }
    done = n;
    free(at);
    return done;
}

static int seiri(jw_drawing *d, int join)
{
    op_t *rec;
    int gone = 0, changed = 1, guard = 0;

    if (!d)
        return 0;
    rec = op_new();
    while (changed && guard++ < 10000) {
        int i, j;

        changed = 0;
        for (i = 0; i < d->ndrawn && !changed; i++) {
            if (!d->obj[i].sel)
                continue;
            for (j = i + 1; j < d->ndrawn; j++) {
                jw_obj *a = &d->obj[i], *b = &d->obj[j];
                double len, t0, t1, lo, hi, ov, ux, uy;

                if (!b->sel || !seiri_attr(a, b))
                    continue;
                if (a->cls != JW_SEN) {
                    if (!seiri_same(d, a, b))
                        continue;
                    erase(d, j, rec);
                    gone++;
                    changed = 1;
                    break;
                }
                if (!seiri_along(a, b, &len, &t0, &t1))
                    continue;
                lo = t0 < t1 ? t0 : t1;
                hi = t0 < t1 ? t1 : t0;
                ov = (hi < len ? hi : len) - (lo > 0.0 ? lo : 0.0);
                /* 重複整理 wants them to share some length; 連結整理 takes
                   them meeting at a point as well */
                if (join ? ov < -SEIRI_EPS : ov <= SEIRI_EPS)
                    continue;
                ux = (a->d[2] - a->d[0]) / len;
                uy = (a->d[3] - a->d[1]) / len;
                op_keep(rec, d, i, 0);
                if (lo < 0.0) {
                    double x0 = a->d[0] + ux * lo, y0 = a->d[1] + uy * lo;

                    a->d[0] = x0;
                    a->d[1] = y0;
                }
                if (hi > len) {
                    double x1 = a->d[0] + ux * (hi - (lo < 0.0 ? lo : 0.0));
                    double y1 = a->d[1] + uy * (hi - (lo < 0.0 ? lo : 0.0));

                    a->d[2] = x1;
                    a->d[3] = y1;
                }
                erase(d, j, rec);
                gone++;
                changed = 1;
                break;
            }
        }
    }
    (void)rec;
    return gone;
}

/* ------------------------------------------------------ ブロック化 -----
 * The one point an element counts as, for working out where a block goes.
 * The original averages one of these over everything picked, which is what
 * driving it showed: two lines at y 20 and -40 put the block at y -10, and
 * adding a circle centred at -80 moved it to -100/3.  A line and a text
 * count as the middle of their two points, an arc and a point as where they
 * are, and a solid as the middle of its corners -- three of them when the
 * last two are the same point, which is how a triangle is written.
 * decomp/res/blkmake.jww is the original doing it to twelve elements at
 * once, and the sum comes out at 0.3125, -18.159722 exactly.
 */
static void blk_point(const jw_obj *o, double *x, double *y)
{
    switch (o->cls) {
    case JW_SEN:
    case JW_MOJI:
        *x = (o->d[0] + o->d[2]) / 2.0;
        *y = (o->d[1] + o->d[3]) / 2.0;
        break;
    case JW_SOLID: {
        int n = (o->d[6] == o->d[4] && o->d[7] == o->d[5]) ? 3 : 4, k;
        double sx = 0.0, sy = 0.0;

        for (k = 0; k < n; k++) {
            sx += o->d[k * 2];
            sy += o->d[k * 2 + 1];
        }
        *x = sx / n;
        *y = sy / n;
        break;
    }
    default:                    /* an arc's centre, a point, a reference */
        *x = o->d[0];
        *y = o->d[1];
        break;
    }
}

int jw_cmd_block_point(const jw_drawing *d, double *x, double *y)
{
    double sx = 0.0, sy = 0.0, px, py;
    int i, n = 0;

    if (!d)
        return 0;
    for (i = 0; i < d->ndrawn; i++) {
        if (!d->obj[i].sel)
            continue;
        blk_point(&d->obj[i], &px, &py);
        sx += px;
        sy += py;
        n++;
    }
    if (!n)
        return 0;
    *x = sx / n;
    *y = sy / n;
    return 1;
}

/* ブロック化 (32853).  What is picked comes out of the drawing and goes into
 * a definition of its own, kept past the drawn elements; one reference to it
 * takes their place, on the write layer and in the write colour (the
 * original does that even when everything inside was on layer 0 in colour 1).
 * The elements inside are written relative to where the reference goes.
 * The name the dialog asks for has @@SfigorgFlag@@4 put on the end of it.
 */
int jw_cmd_block_make(jw_drawing *d, const char *name, int prefer_layer)
{
    double px, py;
    jw_obj *keep, *o;
    op_t *rec;
    char full[128];
    int i, n = 0, num = 0, k;

    if (!d || !jw_cmd_block_point(d, &px, &py))
        return 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].sel)
            n++;
    keep = (jw_obj *)malloc((size_t)n * sizeof *keep);
    if (!keep)
        return 0;
    /* a number no definition has yet */
    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] >= num)
            num = d->obj[i].list[0] + 1;

    rec = op_new();
    for (i = d->ndrawn - 1, k = n; i >= 0; i--) {
        if (!d->obj[i].sel)
            continue;
        keep[--k] = d->obj[i];
        erase(d, i, rec);
    }
    for (k = 0; k < n; k++) {
        keep[k].sel = 0;
        keep[k].flags = (unsigned short)(keep[k].flags & ~2u);
        jw_obj_move(&keep[k], -px, -py);
    }

    strncpy(full, name ? name : "", sizeof full - 20);
    full[sizeof full - 20] = 0;
    strcat(full, "@@SfigorgFlag@@4");
    o = jw_add_def(d, JW_LIST);
    if (!o) {
        free(keep);
        return 0;
    }
    o->n = n;
    o->list[0] = num;
    o->list[1] = 1;
    o->list[2] = (int)time(0);
    o->text = jw_add_str(d, full);
    for (k = 0; k < n; k++) {
        o = jw_add_def(d, keep[k].cls);
        if (!o)
            break;
        *o = keep[k];
    }
    free(keep);
    if (rec)
        rec->ndef = n + 1;

    o = jw_add(d, JW_BLOCK);    /* which puts it on the write layer */
    if (o) {
        /* 元データのレイヤを優先する is one bit of the reference's own
           +0x28: the same drawing blocked with it ticked came back with 65
           there where the plain one has 1. */
        if (prefer_layer)
            o->ltype = (unsigned char)(o->ltype | 64u);
        o->d[0] = px;
        o->d[1] = py;
        o->d[2] = 1.0;
        o->d[3] = 1.0;
        o->d[4] = 0.0;
        o->block = num;
        if (rec)
            rec->n = 1;
    }
    return n;
}

/* ------------------------------------------------------ ブロック編集 ---
 * 32986 puts a dialog up (the block's name, a button to change it, and
 * whether the edit goes to every reference or only the picked one) and then
 * the drawing goes on as usual -- except that what is drawn lands in the
 * definition rather than in the drawing.  Driving it bears that out: a
 * range over decomp/res/blkmake.jww, the command, one line drawn and then
 * ブロック編集終了 (32985) came back with the definition holding thirteen
 * elements instead of twelve and the new line inside it, written relative
 * to where the reference sits (decomp/res/blkedit.jww).  The reference
 * itself did not move.
 *
 * The port does exactly that: nothing is expanded and nothing is hidden, so
 * what is drawn appears straight away through the reference, which is what
 * the original shows too.  ファイル→保存 is off while the original is in
 * the mode (its save dialog never comes up), which is how we know it is a
 * mode and not just a setting.
 */
static int blkedit_on;
static int blkedit_num;         /* which definition */
static double blkedit_x, blkedit_y;     /* where its reference sits */
/* The reference the edit was started from, as a place in d->obj (-1 when
   it is whichever one is picked), and the numbers of the definitions the
   edit touches, innermost first: ブロックツリー can start one on a block
   inside a block, and then both are written again at the end. */
static int blkedit_ref = -1;
static int blkedit_chain[9], blkedit_nchain;
static jw_drawing *blkedit_d;

int jw_cmd_block_editing(void)
{
    return blkedit_on;
}

static void undo_forget(void);
static void blk_reorder(jw_drawing *d, const int *chain, int nchain);

/* The original ends an edit by writing the definitions it touched out
 * again: they go to the back of the list, innermost first, with the time
 * of the edit, and the numbers are given out afresh from 0 in the order the
 * list now has (decomp/res/bt_*.jww -- tools/btprobe.sh).  With one
 * definition, or with the edited one already last, nothing moves. */
void jw_cmd_block_done(void)
{
    if (blkedit_on && blkedit_d && blkedit_nchain > 0)
        blk_reorder(blkedit_d, blkedit_chain, blkedit_nchain);
    blkedit_on = 0;
    blkedit_ref = -1;
    blkedit_nchain = 0;
    blkedit_d = 0;
}

/* Where the definition of the block being edited sits in the array. */
static int blkedit_at(const jw_drawing *d)
{
    int i;

    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] == blkedit_num)
            return i;
    return -1;
}

const char *jw_cmd_block_name(const jw_drawing *d)
{
    static char t[80];
    int at;
    const char *p, *q;

    t[0] = 0;
    if (!d || !blkedit_on)
        return t;
    at = blkedit_at(d);
    if (at < 0)
        return t;
    /* the name without the @@SfigorgFlag@@n the original puts on the end */
    p = jw_str(d, d->obj[at].text);
    q = strstr(p, "@@");
    if (!q)
        q = p + strlen(p);
    if (q - p > (int)sizeof t - 1)
        q = p + sizeof t - 1;
    memcpy(t, p, (size_t)(q - p));
    t[q - p] = 0;
    return t;
}

int jw_cmd_block_edit(jw_drawing *d)
{
    int i;

    if (!d)
        return 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_BLOCK && d->obj[i].sel) {
            blkedit_num = d->obj[i].block;
            blkedit_x = d->obj[i].d[0];
            blkedit_y = d->obj[i].d[1];
            blkedit_on = blkedit_at(d) >= 0;
            blkedit_ref = i;
            blkedit_chain[0] = blkedit_num;
            blkedit_nchain = blkedit_on ? 1 : 0;
            blkedit_d = d;
            return blkedit_on;
        }
    return 0;
}

/* ブロックツリー's 選択BLK編集: the same mode, started on the reference the
   tree has picked.  `path` is the references' places in d->obj, outermost
   first; a block inside a block is edited where it sits, so what is drawn
   lands in its definition relative to the place the two carry it to. */
int jw_cmd_block_edit_path(jw_drawing *d, const int *path, int n)
{
    double x = 0.0, y = 0.0, sx = 1.0, sy = 1.0;
    int k, last;

    if (!d || n < 1 || n > 9)
        return 0;
    for (k = 0; k < n; k++) {
        const jw_obj *o;

        if (path[k] < 0 || path[k] >= d->nobj
            || d->obj[path[k]].cls != JW_BLOCK)
            return 0;
        o = &d->obj[path[k]];
        /* the way src/draw.c carries an inner reference by the outer one */
        x = o->d[0] * sx + x;
        y = o->d[1] * sy + y;
        sx *= o->d[2];
        sy *= o->d[3];
    }
    last = path[n - 1];
    blkedit_num = d->obj[last].block;
    blkedit_x = x;
    blkedit_y = y;
    blkedit_on = blkedit_at(d) >= 0;
    blkedit_ref = last;
    blkedit_nchain = 0;
    if (blkedit_on)
        /* innermost first: the block, then each one it sits in */
        for (k = n - 1; k >= 0; k--)
            blkedit_chain[blkedit_nchain++] = d->obj[path[k]].block;
    blkedit_d = d;
    return blkedit_on;
}

void jw_cmd_block_take(jw_drawing *d, int from)
{
    int at, n, i, want_at = -1, first_item = -1, made = 0;
    jw_obj was;
    op_t *rec = nop > 0 ? &op[nop - 1] : 0;

    if (!d || !blkedit_on || from < 0 || from >= d->ndrawn)
        return;
    at = blkedit_at(d);
    if (at < 0)
        return;
    n = d->ndrawn - from;
    was = d->obj[at];           /* the definition before its count changes */
    for (i = 0; i < n; i++) {
        jw_obj copy = d->obj[from], *p;

        jw_remove(d, from);
        at = blkedit_at(d);
        jw_obj_move(&copy, -blkedit_x, -blkedit_y);
        copy.sel = 0;
        copy.flags = (unsigned short)(copy.flags & ~2u);
        p = jw_add_def(d, copy.cls);
        if (!p)
            break;
        *p = copy;
        {   /* a definition's elements sit straight after it, so the new one
               has to come down from the end of the array to its place */
            int want = at + 1 + d->obj[at].n, last = d->nobj - 1;

            want_at = want;

            while (last > want) {
                jw_obj t = d->obj[last - 1];

                d->obj[last - 1] = d->obj[last];
                d->obj[last] = t;
                last--;
            }
        }
        if (rec && op_keep(rec, d, want_at, 3)) {   /* where it went, for 元に戻る */
            if (first_item < 0)
                first_item = rec->nitem - 1;
            made++;
        }
        d->obj[at].n++;
    }
    /* The definition's own count changed, so 元に戻る has to know it -- and
       it has to be told where the definition sits *now*, because taking the
       elements out of the drawing moved it.  ndef takes the new ones off
       the end of the array, which is where they are when the block being
       edited is the last definition: the only case there is an answer for. */
    if (rec) {
        op_item *it;

        /* each of the next elements taken out of the drawing moved the
           definitions down by one, so the places noted above are too high
           by the number of elements that came after them */
        for (i = 0; i < made; i++)
            rec->item[first_item + i].at -= made - 1 - i;
        it = op_keep(rec, d, at, 0);

        if (it)
            it->was = was;
        rec->n -= n;
        if (rec->n < 0)
            rec->n = 0;
        /* (the new elements are recorded one by one above, as items of kind
           3, so that taking them out does not depend on the block being the
           last definition) */
    }
}

/* ブロック名変更 (the dialog's button 3).  The original keeps the
 * @@SfigorgFlag@@4 on the end and puts the typed name in front of it:
 * NEWNAME typed into decomp/res/blkmake.jww's dialog came back as
 * NEWNAME@@SfigorgFlag@@4 with nothing else changed
 * (decomp/res/blkrename.jww).
 */
int jw_cmd_block_rename(jw_drawing *d, const char *name)
{
    char full[128];
    int at, off;
    op_t *rec;

    if (!d || !blkedit_on || !name || !*name)
        return 0;
    at = blkedit_at(d);
    if (at < 0)
        return 0;
    strncpy(full, name, sizeof full - 20);
    full[sizeof full - 20] = 0;
    strcat(full, "@@SfigorgFlag@@4");
    off = jw_add_str(d, full);
    if (off < 0)
        return 0;
    rec = op_new();
    op_keep(rec, d, at, 0);
    d->obj[at].text = off;
    return 1;
}

/* 選択したブロックのみに反映させる.  The original makes a copy of the
 * definition rather than editing the one everything shares: a drawing with
 * two references to BLK, one of them edited that way, came back with a
 * second definition numbered 1 and named BLK(1)@@SfigorgFlag@@4 holding the
 * thirteen, the first left with its twelve, and only the edited reference
 * pointing at the new one (decomp/res/blk2one.jww).  The copy goes at the
 * end, after the definition it was made from.
 */
int jw_cmd_block_split(jw_drawing *d)
{
    char full[128], num[16];
    const char *p, *q;
    int at, span, num_new = 0, i, off;
    op_t *rec;

    if (!d || !blkedit_on)
        return 0;
    at = blkedit_at(d);
    if (at < 0)
        return 0;
    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] >= num_new)
            num_new = d->obj[i].list[0] + 1;
    /* <name>(<number>) in front of the flag */
    p = jw_str(d, d->obj[at].text);
    q = strstr(p, "@@");
    if (!q)
        q = p + strlen(p);
    if (q - p > (int)sizeof full - 40)
        q = p + sizeof full - 40;
    memcpy(full, p, (size_t)(q - p));
    full[q - p] = 0;
    sprintf(num, "(%d)", num_new);
    strcat(full, num);
    strcat(full, "@@SfigorgFlag@@4");
    off = jw_add_str(d, full);
    if (off < 0)
        return 0;

    rec = op_new();
    at = blkedit_at(d);         /* jw_add_str cannot move it, but be sure */
    span = d->obj[at].n;
    for (i = 0; i <= span; i++) {
        jw_obj *o = jw_add_def(d, d->obj[at + i].cls);

        if (!o)
            return 0;
        *o = d->obj[at + i];
        if (i == 0) {
            o->list[0] = num_new;
            o->text = off;
        }
    }
    if (rec)
        rec->ndef += span + 1;
    /* and the one reference being edited points at the copy */
    if (blkedit_ref >= 0 && blkedit_ref < d->nobj
        && d->obj[blkedit_ref].cls == JW_BLOCK
        && d->obj[blkedit_ref].block == blkedit_num) {
        op_keep(rec, d, blkedit_ref, 0);
        d->obj[blkedit_ref].block = num_new;
    } else {
        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_BLOCK && d->obj[i].sel
                && d->obj[i].block == blkedit_num) {
                op_keep(rec, d, i, 0);
                d->obj[i].block = num_new;
                break;
            }
    }
    if (blkedit_nchain > 0 && blkedit_chain[0] == blkedit_num)
        blkedit_chain[0] = num_new;
    blkedit_num = num_new;
    return 1;
}

static void undo_forget(void)
{
    nop = 0;
    while (ntop > 0)
        op_drop(&op[--ntop]);
}

/* See jw_cmd_block_done. */
static void blk_reorder(jw_drawing *d, const int *chain, int nchain)
{
    struct def_s { int at, span, num, moved; } *df;
    int *order, *ord2;
    jw_obj *old, *neu;
    int nd = 0, i, k, m, same = 1, region, now = (int)time(0);

    df = (struct def_s *)malloc((size_t)(d->nobj - d->ndrawn + 1) * sizeof *df);
    order = (int *)malloc((size_t)(d->nobj - d->ndrawn + 1) * sizeof *order);
    ord2 = (int *)malloc((size_t)(d->nobj - d->ndrawn + 1) * sizeof *ord2);
    if (!df || !order || !ord2) {
        free(df);
        free(order);
        free(ord2);
        return;
    }
    for (i = d->ndrawn; i < d->nobj && d->obj[i].cls == JW_LIST;
         i += df[nd - 1].span) {
        df[nd].at = i;
        df[nd].span = d->obj[i].n + 1;
        df[nd].num = d->obj[i].list[0];
        df[nd].moved = 0;
        if (i + df[nd].span > d->nobj)
            break;
        nd++;
    }
    /* who goes to the back: the touched ones, innermost first */
    m = 0;
    for (k = 0; k < nchain; k++)
        for (i = 0; i < nd; i++)
            if (df[i].num == chain[k] && !df[i].moved) {
                df[i].moved = 1;
                ord2[m++] = i;
            }
    k = 0;
    for (i = 0; i < nd; i++)
        if (!df[i].moved)
            order[k++] = i;
    for (i = 0; i < m; i++)
        order[k++] = ord2[i];
    for (i = 0; i < nd; i++)
        if (order[i] != i)
            same = 0;
    for (i = 0; i < m; i++)
        d->obj[df[ord2[i]].at].list[2] = now;
    if (!same && k == nd) {
        int *newnum = (int *)malloc((size_t)(nd + 1) * sizeof *newnum);
        int o = 0;

        region = d->nobj - d->ndrawn;
        old = d->obj + d->ndrawn;
        neu = (jw_obj *)malloc((size_t)(region + 1) * sizeof *neu);
        if (newnum && neu) {
            int tot = 0;

            for (i = 0; i < nd; i++)
                tot += df[i].span;
            for (i = 0; i < nd; i++) {
                int src = order[i];

                memcpy(neu + o, d->obj + df[src].at,
                       (size_t)df[src].span * sizeof *neu);
                neu[o].list[0] = i;
                newnum[src] = i;
                o += df[src].span;
            }
            /* whatever lay past the definitions stays where it was */
            if (tot < region)
                memcpy(neu + tot, old + tot,
                       (size_t)(region - tot) * sizeof *neu);
            memcpy(old, neu, (size_t)region * sizeof *neu);
            /* every reference follows its definition to the new number */
            for (i = 0; i < d->nobj; i++)
                if (d->obj[i].cls == JW_BLOCK)
                    for (k = 0; k < nd; k++)
                        if (df[k].num == d->obj[i].block) {
                            d->obj[i].block = newnum[k] | 0x40000000;
                            break;
                        }
            for (i = 0; i < d->nobj; i++)
                if (d->obj[i].cls == JW_BLOCK && (d->obj[i].block & 0x40000000))
                    d->obj[i].block &= ~0x40000000;
            undo_forget();
        }
        free(newnum);
        free(neu);
    }
    free(df);
    free(order);
    free(ord2);
}

/* The same three steps ブロックツリー's ブロック名変更 takes: start the edit
   on the reference, give its definition the name, and end it. */
int jw_cmd_block_rename_path(jw_drawing *d, const int *path, int n,
                             const char *name)
{
    int ok;

    if (!name || !*name || !jw_cmd_block_edit_path(d, path, n))
        return 0;
    ok = jw_cmd_block_rename(d, name);
    jw_cmd_block_done();
    return ok;
}

/* ブロック属性 (32970).  The same dialog as ブロック化 with the name box
 * greyed out and its label cut down to just ブロック名; the one thing it can
 * change is 元データのレイヤを優先する, and ticking it turned the reference's
 * line type from 1 into 65 and left everything else alone
 * (decomp/res/blkattr.jww).
 */
int jw_cmd_block_attr(jw_drawing *d, int prefer_layer)
{
    op_t *rec;
    int i, n = 0;

    if (!d)
        return 0;
    rec = op_new();
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        unsigned char want;

        if (o->cls != JW_BLOCK || !o->sel)
            continue;
        want = (unsigned char)(prefer_layer ? (o->ltype | 64u)
                                            : (o->ltype & ~64u));
        if (want == o->ltype)
            continue;
        op_keep(rec, d, i, 0);
        o->ltype = want;
        n++;
    }
    return n;
}

/* ブロック解除 (32909).  Every reference picked gives its definition's
 * elements back, put where the reference is and turned and scaled the way it
 * is.  They take the reference's layer and layer group but keep their own
 * colour and line type: twelve elements that had been on layer 0 came back
 * on layer 8, which is where the reference was (decomp/res/blkfree.jww).
 * None of them comes back picked, and a definition nothing refers to any
 * more goes with them.
 */
int jw_cmd_block_free(jw_drawing *d)
{
    op_t *rec;
    int i, k, n = 0;

    if (!d)
        return 0;
    rec = op_new();
    if (rec && d->nobj > 0) {
        /* several references put their members in at several places, which
           the record's single add_at cannot say: keep the whole drawing
           (cmdfuzz seed 715 on Test5: 戻る brought the elements back out of
           order) */
        rec->before = (jw_obj *)malloc((size_t)d->nobj * sizeof *rec->before);
        if (rec->before) {
            memcpy(rec->before, d->obj, (size_t)d->nobj * sizeof *rec->before);
            rec->nbefore = d->nobj;
            rec->ndrawn_before = d->ndrawn;
        }
    }
    for (i = d->ndrawn - 1; i >= 0; i--) {
        jw_obj ref;
        int at = -1, span, made = 0;

        if (d->obj[i].cls != JW_BLOCK || !d->obj[i].sel)
            continue;
        ref = d->obj[i];
        for (k = d->ndrawn; k < d->nobj; k++)
            if (d->obj[k].cls == JW_LIST && d->obj[k].list[0] == ref.block) {
                at = k;
                break;
            }
        if (at < 0)
            continue;
        span = d->obj[at].n;
        for (k = 0; k < span; k++) {
            jw_obj copy = d->obj[at + 1 + k], *p;

            jw_obj_xform(&copy, 0.0, 0.0, ref.d[2] != 0.0 ? ref.d[2] : 1.0,
                         ref.d[4], ref.d[0], ref.d[1]);
            p = jw_add(d, copy.cls);
            if (!p)
                break;
            *p = copy;
            p->layer = ref.layer;
            p->lgroup = ref.lgroup;
            p->sel = 0;
            p->flags = (unsigned short)(p->flags & ~2u);
            p->id = 0;
            made++;
            at++;               /* jw_add pushed the definitions up one */
        }
        /* `at` has been kept up to date all along: it is where the
           definition sits now. */
        /* the reference itself, and then the definition if this was the
           last one pointing at it -- recorded backwards so that 元に戻る
           puts them back in their own order */
        erase(d, i, rec);
        /* what came out of the definition goes where the reference was, not
           on the end: the original's own file has the twelve at the front,
           which is where its block had been (decomp/res/blkfree.jww) */
        if (made > 0 && i < d->ndrawn - made) {
            jw_obj *tmp = (jw_obj *)malloc((size_t)made * sizeof *tmp);

            if (tmp) {
                memcpy(tmp, &d->obj[d->ndrawn - made],
                       (size_t)made * sizeof *tmp);
                memmove(&d->obj[i + made], &d->obj[i],
                        (size_t)(d->ndrawn - made - i) * sizeof *tmp);
                memcpy(&d->obj[i], tmp, (size_t)made * sizeof *tmp);
                free(tmp);
            }
        }
        if (rec)
            rec->add_at = i + 1;
        for (k = 0; k < d->ndrawn; k++)
            if (d->obj[k].cls == JW_BLOCK && d->obj[k].block == ref.block)
                break;
        if (k >= d->ndrawn) {
            int m;

            at -= 1;            /* erase() moved the definitions down one */
            for (m = d->obj[at].n; m >= 0; m--)
                op_keep(rec, d, at + m, 2);
            for (m = d->obj[at].n; m >= 0; m--)
                jw_remove(d, at + m);
        }
        if (rec)
            rec->n += made;
        n++;
        i = d->ndrawn;          /* start again: everything has moved */
    }
    return n;
}

/* ---------------------------------------------------- ブロックツリー ---
 * 図面内のブロックを階層的に表示します (32988).  A window of its own with a
 * tree in it: under the root come the references the drawing holds, and
 * under each of those the references its definition holds, and so on.  A
 * name is the definition's with the @@SfigorgFlag@@n taken off, and the
 * children of one parent are in name order (TVI_SORT; two of one name stay
 * as they were laid down).  A reference that has its hidden bit set does
 * not show (the original tests `(flags & 1) == 0`).
 *
 * A node is named here by the place of its reference in d->obj.
 */
static int bt_def_at(const jw_drawing *d, int block)
{
    int i;

    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] == block)
            return i;
    return -1;
}

const char *jw_bt_name(const jw_drawing *d, int ref)
{
    static char t[128];
    const char *p, *q;
    int at;

    t[0] = 0;
    if (!d || ref < 0 || ref >= d->nobj || d->obj[ref].cls != JW_BLOCK)
        return t;
    at = bt_def_at(d, d->obj[ref].block);
    if (at < 0)
        return t;
    p = jw_str(d, d->obj[at].text);
    q = strstr(p, "@@");
    if (!q)
        q = p + strlen(p);
    if ((size_t)(q - p) > sizeof t - 1)
        q = p + sizeof t - 1;
    memcpy(t, p, (size_t)(q - p));
    t[q - p] = 0;
    return t;
}

static int bt_cmp(const jw_drawing *d, int a, int b)
{
    char x[128];
    const unsigned char *p, *q;

    strcpy(x, jw_bt_name(d, a));
    p = (const unsigned char *)x;
    q = (const unsigned char *)jw_bt_name(d, b);
    for (; *p && *q; p++, q++) {
        int c = *p >= 'A' && *p <= 'Z' ? *p + 32 : *p;
        int e = *q >= 'A' && *q <= 'Z' ? *q + 32 : *q;

        if (c != e)
            return c - e;
    }
    return (int)*p - (int)*q;
}

/* The children of `parent` (-1 for the root), in order; how many */
int jw_bt_kids(const jw_drawing *d, int parent, int *out, int max)
{
    int n = 0, i, from, to;

    if (!d)
        return 0;
    if (parent < 0) {
        from = 0;
        to = d->ndrawn;
    } else {
        int at;

        if (parent >= d->nobj || d->obj[parent].cls != JW_BLOCK)
            return 0;
        at = bt_def_at(d, d->obj[parent].block);
        if (at < 0)
            return 0;
        from = at + 1;
        to = at + 1 + d->obj[at].n;
        if (to > d->nobj)
            to = d->nobj;
    }
    for (i = from; i < to && n < max; i++) {
        int k;

        if (d->obj[i].cls == JW_LIST)
            break;
        if (d->obj[i].cls != JW_BLOCK || (d->obj[i].flags & 1))
            continue;
        k = n++;
        while (k > 0 && bt_cmp(d, out[k - 1], i) > 0) {
            out[k] = out[k - 1];
            k--;
        }
        out[k] = i;
    }
    return n;
}

/* Whether the node has anything under it (for the + box) */
int jw_bt_has_kids(const jw_drawing *d, int ref)
{
    int one[1];

    return jw_bt_kids(d, ref, one, 1) > 0;
}

/* ------------------------------------------- 環境設定ファイル (.jwf) ---
 * 設定 > 環境設定ファイル > 書出し (32924) and 読込み (32923), both of which
 * put a Windows file dialog up first ("Jwf|*.JWF|JwL|*.JWL|").  What the
 * original writes is its whole configuration -- 303 lines of text, CRLF,
 * CP932 -- and decomp/res/env_new.jwf is that file as it comes out of a fresh
 * start (src/gen/jwf.h bakes it).  Of those lines these are the ones that
 * follow the drawing that is open (found by writing from Test1, Test5 and
 * 新規 and putting the three side by side, decomp/res/env_t1.jwf and
 * env_t5.jwf; tools/envprobe.sh):
 *
 *   the first line      the file's name
 *   S_COMM_0            its third number is the sheet (A1, A2, ...)
 *   LAYSCALE            the sixteen group scales
 *   LAYNAM_0 .. _F      each group's name, then its sixteen layers' names
 *   LCOLLOR_1..8, _H, _B, _G   the screen pens: R G B and the width
 *   PCOLLOR_1..8, _G    the printing pens: R G B, the width and (as it
 *                       was) the thickness in mm
 *   MWIDE MHIGH MDIST MPEN     the ten text sizes, gaps and pens
 *
 * The rest (the keys of the letters, AUTO's mouse map, the basic settings,
 * hatch and dimension defaults...) is held by the original in its own
 * globals and not in the drawing, so it goes out as a fresh start has it.
 * Reading takes back what the list above is made of.
 */
#include "gen/jwf.h"

static void env_pen3(char *o, const char *key, unsigned rgb_rrggbb, int w, int with_w)
{
    sprintf(o, "%s =", key);
    sprintf(o + strlen(o), " %4u %4u %4u", (rgb_rrggbb >> 16) & 255,
            (rgb_rrggbb >> 8) & 255, rgb_rrggbb & 255);
    if (with_w)
        sprintf(o + strlen(o), " %4d", w);
    strcat(o, " ");
}

/* the text from the start of the template line up to and including '=' */
static int env_key(const char *line, char *key, size_t cap)
{
    const char *e = strchr(line, '=');
    size_t n;

    if (!e)
        return 0;
    n = (size_t)(e - line);
    if (n >= cap)
        return 0;
    memcpy(key, line, n);
    key[n] = 0;
    while (n > 0 && key[n - 1] == ' ')
        key[--n] = 0;
    return 1;
}

int jw_env_write(const jw_drawing *d, const char *name, unsigned char **out,
                 long *outn)
{
    const char *p = (const char *)jw_jwf_tpl, *end = p + JW_JWF_LEN;
    char *buf;
    size_t cap = JW_JWF_LEN + 20000, len = 0;
    int first = 1;

    if (!d || !out || !outn)
        return 0;
    buf = (char *)malloc(cap);
    if (!buf)
        return 0;
    while (p < end) {
        const char *nl = memchr(p, '\n', (size_t)(end - p));
        size_t ll = nl ? (size_t)(nl - p) + 1 : (size_t)(end - p);
        char line[2048], key[64], mine[4096];
        int mod = 0, k, i;

        /* the template line without its CRLF */
        i = (int)ll;
        while (i > 0 && (p[i - 1] == '\n' || p[i - 1] == '\r'))
            i--;
        if (i >= (int)sizeof line)
            i = (int)sizeof line - 1;
        memcpy(line, p, (size_t)i);
        line[i] = 0;
        mine[0] = 0;

        if (first) {
            sprintf(mine, "#        %s       Jw_cad for Windows ",
                    name && *name ? name : "env.jwf");
            mod = 1;
            first = 0;
        } else if (env_key(line, key, sizeof key)) {
            if (!strcmp(key, "S_COMM_0")
                && d->paper_size >= 0 && d->paper_size <= 4) {
                /* the third number is the sheet: A1, A2... */
                char *q = strstr(line, "   A");

                if (q && q[4] >= '0' && q[4] <= '9') {
                    char *f = strchr(line, '=') + 1;
                    int g, wg = 0;

                    strcpy(mine, line);
                    mine[(q + 4) - line] = (char)('0' + d->paper_size);
                    /* the first number: the write group and its write
                       layer, one hex digit each (Test1 0A, Test5 08) */
                    for (g = 0; g < 16; g++)
                        if (d->group[g].state == 3) {
                            wg = g;
                            break;
                        }
                    while (*f == ' ')
                        f++;
                    sprintf(key, "%X%X", wg & 15,
                            d->group[wg].write_layer & 15);
                    if (f[0] && f[1] && f[2] == ' ')
                        memcpy(mine + (f - line), key, 2);
                    mod = 1;
                }
            } else if (!strcmp(key, "LAYSCALE")) {
                strcpy(mine, "LAYSCALE =");
                for (k = 0; k < 16; k++)
                    sprintf(mine + strlen(mine), " %g", d->group[k].scale);
                strcat(mine, "  ");
                mod = 1;
            } else if (!strncmp(key, "LAYNAM_", 7) && key[7] && !key[8]
                       && key[7] != 'N') {
                int g = key[7] >= 'A' ? key[7] - 'A' + 10 : key[7] - '0';

                if (g >= 0 && g < 16) {
                    sprintf(mine, "%s =%s", key, jw_str(d, d->group[g].name));
                    for (k = 0; k < 16; k++)
                        sprintf(mine + strlen(mine), ",%s",
                                jw_str(d, d->group[g].layer_name[k]));
                    mod = 1;
                }
            } else if (!strncmp(key, "LCOLLOR_", 8) && key[8] && !key[9]) {
                int c = key[8];

                if (c >= '1' && c <= '8') {
                    env_pen3(mine, key, d->pen_rgb[c - '0'],
                             d->pen_width[c - '0'], 1);
                    mod = 1;
                } else if (c == 'H') {
                    env_pen3(mine, key, d->pen_rgb[9], d->pen_width[9], 1);
                    mod = 1;
                } else if (c == 'B') {
                    env_pen3(mine, key, d->pen_rgb[0], 0, 0);
                    mod = 1;
                } else if (c == 'G') {
                    env_pen3(mine, key, d->gray_rgb, 0, 0);
                    mod = 1;
                }
            } else if (!strncmp(key, "PCOLLOR_", 8) && key[8] && !key[9]) {
                int c = key[8];

                if (c >= '1' && c <= '8') {
                    unsigned v = d->print_rgb[c - '0'];
                    double pr = 0.0;
                    const char *q = strchr(line, '=');

                    /* the thickness in mm is the template's own */
                    if (q) {
                        int a, b2, cc, w;

                        if (sscanf(q + 1, "%d %d %d %d %lf", &a, &b2, &cc, &w,
                                   &pr) < 5)
                            pr = 0.0;
                    }
                    sprintf(mine, "%s =", key);
                    sprintf(mine + strlen(mine), " %4u %4u %4u %4d %7.2f ",
                            v & 255, (v >> 8) & 255, (v >> 16) & 255,
                            d->print_width[c - '0'], pr);
                    mod = 1;
                } else if (c == 'G') {
                    unsigned v = d->print_rgb[9];

                    sprintf(mine, "%s =", key);
                    sprintf(mine + strlen(mine), " %4u %4u %4u ", v & 255,
                            (v >> 8) & 255, (v >> 16) & 255);
                    mod = 1;
                }
            } else if (!strcmp(key, "MWIDE") || !strcmp(key, "MHIGH")
                       || !strcmp(key, "MDIST")) {
                strcpy(mine, line);
                mine[strchr(line, '=') - line + 1] = 0;
                for (k = 0; k < 10; k++)
                    sprintf(mine + strlen(mine), " %5.1f",
                            key[1] == 'W' ? d->style[k].w
                            : key[1] == 'H' ? d->style[k].h : d->style[k].sp);
                strcat(mine, " ");
                mod = 1;
            } else if (!strcmp(key, "MPEN")) {
                strcpy(mine, line);
                mine[strchr(line, '=') - line + 1] = 0;
                for (k = 0; k < 10; k++)
                    sprintf(mine + strlen(mine), " %5d", d->style[k].color);
                strcat(mine, " ");
                mod = 1;
            }
        }
        {
            const char *src = mod ? mine : line;
            size_t sl = strlen(src);

            if (len + sl + 3 >= cap) {
                char *nb = (char *)realloc(buf, cap * 2);

                if (!nb) {
                    free(buf);
                    return 0;
                }
                buf = nb;
                cap *= 2;
            }
            memcpy(buf + len, src, sl);
            len += sl;
            buf[len++] = '\r';
            buf[len++] = '\n';
        }
        p += ll;
    }
    *out = (unsigned char *)buf;
    *outn = (long)len;
    return 1;
}

/* Reading: every key above that is found goes into the drawing.  Returns
   how many lines it took in. */
int jw_env_read(jw_drawing *d, const unsigned char *b, long n)
{
    const char *p = (const char *)b, *end = p + n;
    int taken = 0;

    if (!d || !b)
        return 0;
    while (p < end) {
        const char *nl = memchr(p, '\n', (size_t)(end - p));
        size_t ll = nl ? (size_t)(nl - p) + 1 : (size_t)(end - p);
        char line[2048], key[64];
        const char *v;
        int i = (int)ll;

        while (i > 0 && (p[i - 1] == '\n' || p[i - 1] == '\r'))
            i--;
        if (i >= (int)sizeof line)
            i = (int)sizeof line - 1;
        memcpy(line, p, (size_t)i);
        line[i] = 0;
        p += ll;
        if (line[0] == '#' || !env_key(line, key, sizeof key))
            continue;
        v = strchr(line, '=') + 1;
        if (!strcmp(key, "LAYSCALE")) {
            int k = 0;
            double s;
            int used;

            while (k < 16 && sscanf(v, "%lf%n", &s, &used) == 1) {
                if (s >= 1.0)
                    d->group[k].scale = s;
                v += used;
                k++;
            }
            taken++;
        } else if (!strncmp(key, "LAYNAM_", 7) && key[7] && !key[8]
                   && key[7] != 'N') {
            int g = key[7] >= 'A' ? key[7] - 'A' + 10 : key[7] - '0';
            int k = 0;

            if (g < 0 || g > 15)
                continue;
            for (;;) {
                char t[128];
                const char *c = strchr(v, ',');
                size_t m = c ? (size_t)(c - v) : strlen(v);
                int off;

                if (m >= sizeof t)
                    m = sizeof t - 1;
                memcpy(t, v, m);
                t[m] = 0;
                off = jw_add_str(d, t);
                if (off >= 0) {
                    if (k == 0)
                        d->group[g].name = off;
                    else if (k <= 16)
                        d->group[g].layer_name[k - 1] = off;
                }
                k++;
                if (!c || k > 16)
                    break;
                v = c + 1;
            }
            taken++;
        } else if (!strncmp(key, "LCOLLOR_", 8) && key[8] && !key[9]) {
            int c = key[8], r, g, bl, w = 0, nn;
            int idx = c >= '1' && c <= '8' ? c - '0' : c == 'H' ? 9
                      : c == 'B' ? 0 : -1;

            nn = sscanf(v, "%d %d %d %d", &r, &g, &bl, &w);
            if (nn >= 3 && idx >= 0 && r >= 0 && r < 256 && g >= 0 && g < 256
                && bl >= 0 && bl < 256) {
                d->pen_rgb[idx] = (unsigned)(r << 16 | g << 8 | bl);
                if (nn >= 4 && w >= 1 && (idx >= 1))
                    d->pen_width[idx] = w;
                taken++;
            } else if (nn >= 3 && c == 'G' && r >= 0 && r < 256 && g >= 0
                       && g < 256 && bl >= 0 && bl < 256) {
                d->gray_rgb = (unsigned)(r << 16 | g << 8 | bl);
                taken++;
            }
        } else if (!strncmp(key, "PCOLLOR_", 8) && key[8] && !key[9]) {
            int c = key[8], r, g, bl, w = 0, nn;
            int idx = c >= '1' && c <= '8' ? c - '0' : c == 'G' ? 9 : -1;

            nn = sscanf(v, "%d %d %d %d", &r, &g, &bl, &w);
            if (nn >= 3 && idx >= 0 && r >= 0 && r < 256 && g >= 0 && g < 256
                && bl >= 0 && bl < 256) {
                d->print_rgb[idx] = (unsigned)(bl << 16 | g << 8 | r);
                if (nn >= 4 && w >= 1 && idx < 9)
                    d->print_width[idx] = w;
                taken++;
            }
        } else if (!strcmp(key, "MWIDE") || !strcmp(key, "MHIGH")
                   || !strcmp(key, "MDIST") || !strcmp(key, "MPEN")) {
            int k = 0, used;
            double x;

            while (k < 10 && sscanf(v, "%lf%n", &x, &used) == 1) {
                if (key[1] == 'P')
                    d->style[k].color = (int)x;
                else if (key[1] == 'W')
                    d->style[k].w = x;
                else if (key[1] == 'H')
                    d->style[k].h = x;
                else
                    d->style[k].sp = x;
                v += used;
                k++;
            }
            taken++;
        }
    }
    return taken;
}

/* ------------------------------------------------- 図形読込 (32862) ----
 * The figure that was picked in the original's own file window.  The port
 * has none, so the front end reads the .jws and hands the bytes over.
 */
static jw_drawing fig;
static int fig_have;
static double fig_bx, fig_by;
static double fig_mag = 1.0, fig_deg;
/* whether the figure came out of a coordinate file, whose texts keep their
   own size and work their far end out from it (see src/coord.c) */
static int fig_coord;

/* 倍率 and 回転角 for a figure, from a front end that has no
   command bar of its own.  They go **into the bar's own boxes**, because
   that is where the original keeps them and where figure_place reads
   them: a front end that types into the boxes and one that calls this
   have to end up in the same place. */
void jw_cmd_figure_at(double mag, double deg)
{
    char *m = box_slot(JW_CMD_ZUKEI, 1431);
    char *g = box_slot(JW_CMD_ZUKEI, 1412);

    fig_mag = mag;
    fig_deg = deg;
    if (m)
        snprintf(m, 16, "%g", mag);
    if (g)
        snprintf(g, 16, "%g", deg);
}

int jw_cmd_figure_ready(void)
{
    return fig_have;
}

int jw_cmd_figure_load(jw_drawing *d, const unsigned char *b, long n)
{
    jw_drawing next;
    double bx = 0.0, by = 0.0;

    memset(&next, 0, sizeof next);
    if (!jw_parse_jws(&next, b, n, &bx, &by)) {
        jw_free(&next);
        return 0;
    }
    if (fig_have)
        jw_free(&fig);
    fig = next;
    fig_bx = bx;
    fig_by = by;
    fig_have = 1;
    fig_coord = 0;
    fig_mag = 1.0;                      /* the bar comes up empty */
    fig_deg = 0.0;
    jw_cmd_set(JW_CMD_ZUKEI);
    (void)d;
    return 1;
}

/* Where 図形登録 was told to put its base point, and whether that has just
   happened.  The original asks for it after 選択確定 and then puts its file
   window up; the port hands the moment to the front end instead. */
static double fig_base_x, fig_base_y;
static int fig_base_new;

int jw_cmd_figure_base(double *x, double *y)
{
    if (!fig_base_new)
        return 0;
    fig_base_new = 0;
    if (x)
        *x = fig_base_x;
    if (y)
        *y = fig_base_y;
    return 1;
}

/* 図形登録: what is picked goes out as a figure of its own.  The elements
 * keep the coordinates they have -- it is the base point in the header that
 * 図形読込 works from -- and the file carries the program's own version, not
 * the drawing's.
 */
int jw_cmd_figure_save(const jw_drawing *d, double bx, double by,
                       unsigned char **out, long *n)
{
    jw_drawing t;
    int i, ok;

    if (!d)
        return 0;
    memset(&t, 0, sizeof t);
    t.version = JW_JWS_VERSION;
    for (i = 0; i < JW_NCLASS; i++)
        t.schema[i] = JW_JWS_VERSION;
    for (i = 0; i < 16; i++)
        t.group[i].scale = d->group[i].scale;
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *p = &d->obj[i];
        jw_obj *o;

        if (!p->sel)
            continue;
        o = jw_add(&t, p->cls);
        if (!o) {
            jw_free(&t);
            return 0;
        }
        *o = *p;
        o->text = p->text >= 0 ? jw_add_str(&t, jw_str(d, p->text)) : -1;
        o->face = p->face >= 0 ? jw_add_str(&t, jw_str(d, p->face)) : -1;
        o->sel = 0;
    }
    ok = jw_write_jws(&t, bx, by, out, n);
    jw_free(&t);
    return ok;
}

/* 切り取り (57635) ・ コピー (57634) ・ 貼り付け (57637).
 *
 * **Jw_cad's clipboard is a 図形.**  貼り付け does not put up a command
 * of its own: it puts up **図形読込's**.  The status line reads
 * 「【図形】の複写位置を指示してください (L)free (R)Read」 and the bar
 * carries 作図属性・倍率(1431)・回転角(1412)・90ﾟ毎・マウス角・
 * グループ化 -- the same controls, in the same places, that 図形読込
 * (32862) puts there (tools/probe56.sh).  So the port does the same
 * thing with the same machinery: コピー writes the selection out as the
 * bytes of a .jws, exactly as 選択図形登録 does, and 貼り付け reads them
 * back in as the figure hanging on the cursor.
 *
 * 切り取り does that and then takes the selection away; the original,
 * given three lines and a range round them, left an empty drawing.
 *
 * **Where the copy lands** is the one number that had to be measured.
 * The original was made to paste the same copy at three different places
 * and then again at 倍率 2 and 回転角 90 (tools/probe58.sh), and an
 * L of two lines came back每 time as
 *
 *     pasted = click + turn(scale * (original - B))
 *
 * with the same B throughout -- so B belongs to the copy, not to the
 * click.  For that L, B = (-94.2857, -19.5918), which is **not** the
 * middle of the box round it (-33.06, -4.29) nor any of its corners: it
 * is the average of the two lines' **own middles**, (-33.06, -34.898)
 * and (-155.51, -4.286).  The three-line drawing of tools/probe56.sh
 * says the same, and there the two readings happen to agree.
 *
 * What the middle of something that is not a line is was not asked, so
 * a circle's is taken as its centre and a point's as itself, which is
 * the only reading of「middle」those have.
 */
static unsigned char *clip;
static long clip_n;

/* the average of the selected elements' own middles */
static void clip_base(const jw_drawing *d, double *bx, double *by)
{
    double sx = 0.0, sy = 0.0;
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double mx, my;

        if (!o->sel)
            continue;
        if (o->cls == JW_SEN || o->cls == JW_MOJI) {
            mx = (o->d[0] + o->d[2]) / 2.0;
            my = (o->d[1] + o->d[3]) / 2.0;
        } else {
            mx = o->d[0];
            my = o->d[1];
        }
        sx += mx;
        sy += my;
        n++;
    }
    *bx = n ? sx / n : 0.0;
    *by = n ? sy / n : 0.0;
}

int jw_cmd_clip_copy(jw_drawing *d, int cut)
{
    unsigned char *b = 0;
    double bx, by;
    long n = 0;

    if (!d || jw_cmd_sel_count(d) <= 0)
        return 0;
    clip_base(d, &bx, &by);
    if (!jw_cmd_figure_save(d, bx, by, &b, &n) || !b)
        return 0;
    free(clip);
    clip = b;
    clip_n = n;
    if (cut) {
        /* straight out, without the 範囲選択 walk's own conditions:
           the original, given three lines and a range round them, left
           the drawing empty (tools/probe56.sh) */
        op_t *t = op_new();
        int i;

        for (i = d->ndrawn - 1; i >= 0; i--)
            if (d->obj[i].sel) {
                op_keep(t, d, i, 1);
                jw_remove(d, i);
            }
    }
    return 1;
}

int jw_cmd_clip_has(void)
{
    return clip && clip_n > 0;
}

int jw_cmd_clip_paste(jw_drawing *d)
{
    if (!d || !clip || clip_n <= 0)
        return 0;
    return jw_cmd_figure_load(d, clip, clip_n);
}

/* 座標ファイル's ファイル読込 hands the text over the same way: the original
 * turns it into a 図形 -- 「【図形】の複写位置を指示してください」 with
 * 図形読込's own bar -- and its (0, 0) is what lands on the click.
 */
int jw_cmd_coord_load(jw_drawing *d, const unsigned char *b, long n)
{
    jw_drawing next;

    memset(&next, 0, sizeof next);
    if (!jw_parse_coord(&next, d, b, n)) {
        jw_free(&next);
        return 0;
    }
    if (fig_have)
        jw_free(&fig);
    fig = next;
    fig_bx = 0.0;
    fig_by = 0.0;
    fig_have = 1;
    fig_coord = 1;
    fig_mag = 1.0;
    fig_deg = 0.0;
    jw_cmd_set(JW_CMD_ZUKEI);
    (void)d;
    return 1;
}

/* 倍率 (1431) and 回転角 (1412) on the 図形 bar.  The original turns
   and scales **about the figure's own base point** before putting it
   down where the click is: the same copy pasted at 倍率 2 came out twice
   the size around that point, and at 回転角 90 a quarter turn round it
   (tools/probe58.sh). */
static void fig_boxes(void)
{
    /* The 図形 bar itself was not taken off the original at first, and
       then there were no boxes to read and whatever jw_cmd_figure_at
       was told stood.  Now that src/gen/bars.h has 32862 these take
       over by themselves. */
    const char *m = jw_cmd_box(1431), *g = jw_cmd_box(1412);

    if (m)
        fig_mag = box_num(m, 0.0) > 0.0 ? box_num(m, 1.0) : 1.0;
    if (g)
        fig_deg = box_num(g, 0.0);
}

/* Which layer group and layer the figure goes on: the write ones. */
static void fig_where(const jw_drawing *d, int *wg, int *wl)
{
    int i;

    *wg = 0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            *wg = i;
    *wl = d->group[*wg].write_layer & 15;
}

/* One element of the figure, moved to where the figure is going.  `sp`
   is the drawing whose pool the element's strings are in -- the
   destination for a placement, the figure itself for the picture that
   hangs off the cursor. */
static void fig_one(const jw_drawing *d, const jw_drawing *sp,
                    jw_obj *o, const jw_obj *p, int wg, int wl,
                    double x, double y)
{
    double fs = fig.group[p->lgroup & 15].scale;
    double f = fs > 0.0 && d->group[wg].scale > 0.0
                   ? fs / d->group[wg].scale : 1.0;

    o->layer = (unsigned short)wl;
    o->lgroup = (unsigned short)wg;
    o->sel = 0;
    jw_obj_xform(o, fig_bx, fig_by, f * fig_mag,
                 fig_deg * 3.141592653589793 / 180.0,
                 x - fig_bx, y - fig_by);
    if (fig_coord && o->cls == JW_MOJI) {
        /* a coordinate file's text keeps the size the file named, in
           millimetres on the paper, and its far end follows from that */
        double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
        double len = sqrt(dx * dx + dy * dy), want;

        o->d[4] = p->d[4];
        o->d[5] = p->d[5];
        o->d[6] = p->d[6];
        want = jw_coord_text_len(sp, o);
        if (len > 0.0) {
            o->d[2] = o->d[0] + dx / len * want;
            o->d[3] = o->d[1] + dy / len * want;
        }
        /* and the angle it runs at, in degrees, which the original
           fills in from the same direction */
        o->d[7] = atan2(dy, dx) * 180.0 / 3.141592653589793;
    }
}

/* Put the figure down with its base point at (x, y). */
static int figure_place(jw_drawing *d, double x, double y)
{
    int i, wg, wl, made = 0;

    if (!d || !fig_have)
        return 0;
    fig_boxes();
    fig_where(d, &wg, &wl);
    for (i = 0; i < fig.ndrawn; i++) {
        const jw_obj *p = &fig.obj[i];
        jw_obj *o = jw_add(d, p->cls);

        if (!o)
            break;
        *o = *p;
        /* the strings belong to the figure's pool, so they are copied over */
        o->text = p->text >= 0 ? jw_add_str(d, jw_str(&fig, p->text)) : -1;
        o->face = p->face >= 0 ? jw_add_str(d, jw_str(&fig, p->face)) : -1;
        fig_one(d, d, o, p, wg, wl, x, y);
        made++;
    }
    if (made)
        op_push(made);
    return made;
}


/* 外部変形 (32913): what the program left in JWC_TEMP.TXT goes into the
   drawing.  Without hd the picked data stays and is let go of; with hd it is
   taken out first.  Both and the new elements are one step of 元に戻る.  The
   text is read as a 座標ファイル whose (0, 0) is (ox, oy) -- the point the
   file was written from.  Returns the elements made, -2 if the program did not
   run (msg says why), -1 if the file is not readable. */
int jw_cmd_gaibu_commit(jw_drawing *d, const unsigned char *b, long n,
                        double ox, double oy, jw_gaibu_out *out)
{
    jw_drawing next;
    jw_gaibu_out dummy;
    op_t *op;
    int st, i, wg, wl, made = 0;

    if (!d)
        return -1;
    if (!out)
        out = &dummy;
    memset(&next, 0, sizeof next);
    st = jw_gaibu_read(&next, d, b, n, out);
    if (st < 0) {
        jw_free(&next);
        return st;
    }
    op = op_new();
    if (st == 10)
        for (i = d->nobj - 1; i >= 0; i--)
            if (d->obj[i].sel) {
                op_keep(op, d, i, 1);
                jw_remove(d, i);
            }
    sel_clear(d);
    sel_step = 0;
    if (fig_have)
        jw_free(&fig);
    fig = next;
    fig_have = 1;
    fig_coord = 1;
    fig_bx = 0.0;
    fig_by = 0.0;
    fig_mag = 1.0;
    fig_deg = 0.0;
    fig_where(d, &wg, &wl);
    for (i = 0; i < fig.ndrawn; i++) {
        const jw_obj *p = &fig.obj[i];
        jw_obj *o = jw_add(d, p->cls);

        if (!o)
            break;
        *o = *p;
        o->text = p->text >= 0 ? jw_add_str(d, jw_str(&fig, p->text)) : -1;
        o->face = p->face >= 0 ? jw_add_str(d, jw_str(&fig, p->face)) : -1;
        fig_one(d, d, o, p, wg, wl, ox, oy);
        made++;
    }
    if (op)
        op->n = made;
    jw_free(&fig);
    fig_have = 0;
    fig_coord = 0;
    return made;
}
/* The figure as it hangs off the cursor, waiting for the point that puts
 * it down.  The original shows it the whole time, in 仮表示 -- a 95 KB
 * figure read in and the cursor moved twice put the same 141 ff0000
 * pixels down in both places, moved by exactly what the cursor moved by
 * (tools/probe80.sh) -- and it goes on showing it after one has been
 * placed (tools/probe83.sh).  Where it shows it is where the click puts
 * it: every one of those 141 pixels was also a pixel of the figure once
 * placed (tools/probe81.sh).
 *
 * It is the same drawing as the placement, so it goes through the same
 * fig_one, and it is painted with jw_draw_kari up, which is what makes
 * the texts in it come out as boxes (src/draw.c).
 *
 * `out` is filled in with a drawing the caller can hand to jw_draw: the
 * destination's own tables, the figure's elements where they are going,
 * and the figure's string pool, so nothing has to be put into the
 * drawing itself to show it. */
int jw_cmd_figure_preview(const jw_drawing *d, jw_drawing *out)
{
    static jw_obj *pv;
    static int cpv;
    int i, wg, wl;

    if (!d || !out || !fig_have || !tracking || current != JW_CMD_ZUKEI
        || fig.ndrawn <= 0)
        return 0;
    if (cpv < fig.ndrawn) {
        jw_obj *n = (jw_obj *)realloc(pv, (size_t)fig.ndrawn * sizeof *n);

        if (!n)
            return 0;
        pv = n;
        cpv = fig.ndrawn;
    }
    fig_boxes();
    fig_where(d, &wg, &wl);
    for (i = 0; i < fig.ndrawn; i++) {
        pv[i] = fig.obj[i];
        fig_one(d, &fig, &pv[i], &fig.obj[i], wg, wl, tx, ty);
    }
    *out = *d;
    out->obj = pv;
    out->nobj = out->ndrawn = fig.ndrawn;
    out->pool = fig.pool;
    out->npool = fig.npool;
    return 1;
}


int jw_cmd_zokuhen_range(jw_drawing *d, int to_layer, int to_group,
                         int to_color, int to_ltype)
{
    op_t *rec;
    int i, n = 0, g, wg = 0, wl;

    if (!d || (!to_layer && !to_group && !to_color && !to_ltype))
        return 0;
    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    wl = d->group[wg].write_layer & 15;
    rec = op_new();
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        unsigned short lay = o->layer, grp = o->lgroup, col = o->color;
        unsigned char lt = o->ltype;

        if (!o->sel)
            continue;
        if (to_layer)
            lay = (unsigned short)wl;
        if (to_group)
            grp = (unsigned short)wg;
        if (to_color)
            col = (unsigned short)to_color;
        /* 指定 線種 に変更 reaches lines and arcs only -- driving it over
           tools/mkgeom.c's twelve left the two points and the two solids at
           line type 1 (decomp/res/zhlt.jww). */
        if (to_ltype && (o->cls == JW_SEN || o->cls == JW_ENKO))
            lt = (unsigned char)to_ltype;
        if (lay == o->layer && grp == o->lgroup && col == o->color
            && lt == o->ltype)
            continue;
        op_keep(rec, d, i, 0);
        o->layer = lay;
        o->lgroup = grp;
        o->color = col;
        o->ltype = lt;
        n++;
    }
    return n;
}

/* ブロック名指定: the name ブロック名を指定して選択 was given, "" for any.
   With one, ブロック指定 means the references to that block only.  The
   original keeps the name (CZokuseiSelHenkouDialog +0xe0) and ticks
   ブロック指定 as the small dialog closes (FUN_00609a10); that the name is
   matched whole, without the @@SfigorgFlag@@n on the end, is the port's
   guess and has not been asked of the original. */
static char zok_name[80];
static const jw_drawing *zok_d;

void jw_cmd_zokusel_name(const char *name)
{
    strncpy(zok_name, name ? name : "", sizeof zok_name - 1);
    zok_name[sizeof zok_name - 1] = 0;
}

static int zok_named(const jw_obj *o)
{
    int i;

    if (!zok_name[0] || !zok_d)
        return 1;
    for (i = zok_d->ndrawn; i < zok_d->nobj; i++) {
        const jw_obj *l = &zok_d->obj[i];
        const char *p, *q;
        size_t n;

        if (l->cls != JW_LIST || l->list[0] != o->block)
            continue;
        p = jw_str(zok_d, l->text);
        q = strstr(p, "@@");
        n = q ? (size_t)(q - p) : strlen(p);
        return n == strlen(zok_name) && !strncmp(p, zok_name, n);
    }
    return 0;
}

/* Whether an element is one of the kinds the 属性選択 dialog has ticked. */
static int zok_is(const jw_obj *o, int mask)
{
    if ((mask & JW_ZOK_HOJO) && (o->ltype % 100) == 9)
        return 1;
    switch (o->cls) {
    case JW_SEN:   return (mask & JW_ZOK_SEN) != 0;
    case JW_ENKO:  return (mask & JW_ZOK_ENKO) != 0;
    case JW_TEN:   return (mask & JW_ZOK_TEN) != 0;
    case JW_MOJI:  return (mask & JW_ZOK_MOJI) != 0;
    case JW_SOLID: return (mask & JW_ZOK_SOLID) != 0;
    case JW_BLOCK: return (mask & JW_ZOK_BLOCK) != 0 && zok_named(o);
    default:       return 0;
    }
}

/* 属性選択 (1069).  The dialog only narrows what the box already picked:
 * driving the original bears it out one kind at a time.  A box over the
 * whole of tools/mkgeom.c's drawing (four lines, four arcs, two points and
 * two solids) followed by the one tick and 消去 took away just that kind --
 * 円指定 the four arcs (decomp/res/zokenko.jww), 実点指定 the two points
 * (zokten), ソリッド図形指定 the two solids (zoksol), 直線指定 the four
 * lines (zoksen) -- and 文字指定 on Test5 took away its eight texts and
 * none of its lines (zokmoji).  《指定属性除外》 turns it round: 円指定
 * with it took away everything but the arcs (zokout).  Ticking it unticks
 * 【指定属性選択】, so the two are one choice and not two.
 */
int jw_cmd_zokusel(jw_drawing *d, int mask, int exclude, int color,
                   int ltype)
{
    int i, n = 0;

    if (!d)
        return 0;
    zok_d = d;
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        int off = 0;

        if (!o->sel)
            continue;
        /* 指定【線色】指定 and 指定 線種 指定: the colour and the line type
           are the ones picked in the 線属性 dialog the OK puts up, and each
           narrows what is left the same way a kind does. */
        if (color && (o->color == (unsigned short)color) == !!exclude)
            off = 1;
        if (ltype && (o->ltype == (unsigned char)ltype) == !!exclude)
            off = 1;
        if (off || (mask && zok_is(o, mask) == !!exclude)) {
            o->flags = (unsigned short)(o->flags & ~2u);
            o->sel = 0;
        } else {
            n++;
        }
    }
    return n;
}

/* 選択確定.  The selection is taken as it stands and 基準点 becomes where
 * the mouse is -- the bar's own label for it is ≪基準点：マウス位置≫
 * (string 6144).  Driving the original bears it out: after a confirm its
 * copies came out offset from a point that was neither of the box corners
 * nor any click, but the place the cursor happened to be sitting. */
static int sel_confirm(jw_drawing *d)
{
    int i, n = jw_cmd_sel_count(d);

    if (!d || n <= 0)
        return 0;
    sel_free();
    sel_was = (jw_obj *)malloc((size_t)n * sizeof *sel_was);
    sel_at = (int *)malloc((size_t)n * sizeof *sel_at);
    if (!sel_was || !sel_at) {
        sel_free();
        return 0;
    }
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].sel) {
            sel_at[sel_n] = i;
            sel_was[sel_n] = d->obj[i];
            sel_n++;
        }
    if (sel_base_set) {                 /* 基準点変更 put it somewhere */
        base_x = sel_base_px;
        base_y = sel_base_py;
        sel_base_set = 0;
    } else if (tracking) {
        base_x = tx;
        base_y = ty;
    } else {
        /* マウスがビューの中で動いていない（原典を押し・離しの投稿だけで叩いたとき）の既定の基準点は
           選んだものの外接枠の中心（fuzz 28・31・33・36・37・39: 写しの先がクリックに中心を合わせた） */
        double x0 = 1e30, y0 = 1e30, x1 = -1e30, y1 = -1e30;

        for (i = 0; i < sel_n; i++) {
            double a, b2, c2, e2;

            jw_obj_box(&sel_was[i], &a, &b2, &c2, &e2);
            if (a < x0) x0 = a;
            if (b2 < y0) y0 = b2;
            if (c2 > x1) x1 = c2;
            if (e2 > y1) y1 = e2;
        }
        base_x = (x0 + x1) / 2.0;
        base_y = (y0 + y1) / 2.0;
    }
    /* 範囲選択 has nothing to place: confirming there only settles what is
       picked, and it is the next command that does something with it. */
    sel_step = current == JW_CMD_HANI ? 4 : 3;
    if (current == JW_CMD_PARAM)
        param_settle();
    ren_n = 0;                          /* 連続 は次に置いたずれから */
    return 1;
}

/* Enter in the 追加・除外 stage is 範囲確定, the same as 選択確定. */
/* 基本設定 一般(2) 2466「文字コマンドのとき文字位置指示後に文字入力を行う」
   (DAT_00a0cc64, MOJI\PToInp): a click before anything is typed notes the
   place, and the text typed after it goes there on Enter -- FUN_006bc120 puts
   it at the noted point (+0xb4..) instead of the click's when the flag is set
   and a point is noted.  Read off the decompile; not asked of the original. */
static int moji_pre_on, moji_pre;
static double moji_pre_x, moji_pre_y;

void jw_cmd_moji_point_first(int on)
{
    moji_pre_on = on != 0;
    if (!moji_pre_on)
        moji_pre = 0;
}

static void moji_place(jw_drawing *d, double x, double y);
static int sel_numpos(const jw_drawing *d, double *ox, double *oy);
static void sel_place(jw_drawing *d, double x, double y);

/* 数値位置 (1413) が入っていれば Enter で置く。バーの PreTranslateMessage
   (FUN_004adde0) は どの箱に居ても Enter を 0x1500 にして送り、ビュー
   (FUN_005143b0) が仮想関数 36 番目 FUN_00652320 を呼ぶ: 箱が 0 でなければ
   回数を 0 にして FUN_00653fe0 で置く。0 なら何もしない。逆コンパイルの
   読み、原典では押していない。app は箱の Enter のあとにもこれを呼ぶ */
int jw_cmd_numpos_enter(jw_drawing *d)
{
    double ox, oy;

    if (!d || sel_step != 3 || sel_n <= 0
        || (current != JW_CMD_FUKUSHA && current != JW_CMD_IDOU)
        || sel_flip || sel_base_wait || !sel_numpos(d, &ox, &oy))
        return 0;
    ren_n = 0;
    sel_place(d, base_x + ox, base_y + oy);
    return 1;
}

int jw_cmd_enter_key(jw_drawing *d)
{
    if (d && current == JW_CMD_SHOUKYO && shk_sel == 3) {
        /* 範囲選択消去の実行: CZukeiShoukyo の 34 番 FUN_0070e400 が 3 番
           FUN_0070fc60 を呼び、選んだものを消す（FUN_00478480）。1066 なら
           元の消去に戻り（+0x200 = 0）、1067 なら次の範囲へ（FUN_0070c870）。
           逆コンパイルの読み、原典では押していない */
        if (jw_cmd_sel_count(d) > 0)
            sel_erase_now(d);
        sel_clear(d);
        shk_sel = shk_rep ? 1 : 0;
        return 1;
    }
    if (d && current == JW_CMD_MOJI && moji_pre_on && moji_pre && line_n > 0 && !ren_step) {
        moji_place(d, moji_pre_x, moji_pre_y);
        moji_pre = 0;
        return 1;
    }
    if (d && current == JW_CMD_MOJI && moji_got && line_n > 0 && !ren_step) {
        double bx, by;          /* 書き換えて Enter: 元の基点の所に */

        moji_got_base(&bx, &by);
        moji_got_place(d, bx, by);
        return 1;
    }
    if (d && gb_back && current == JW_CMD_HANI && sel_step == 2) {
        /* the range a 外部変形 step asked for is settled: on to the next step */
        gb_keep = 1;
        jw_cmd_set(0x8091);
        gb_keep = 0;
        gb_back = 0;
        gb_step(d);
        return 1;
    }
    if (d && fk_back && current == JW_CMD_HANI && sel_step == 2) {
        fk_back_go(d);          /* 複線の 範囲選択 (1067) が決まった */
        return 1;
    }
    if (d && ms_back && current == JW_CMD_HANI && sel_step == 2) {
        /* 範囲選択 for the 文字 command: what is not a text is let go, and the
           bar goes back to the 文字 one with the texts picked */
        int i, go = ms_after;

        for (i = 0; i < d->nobj; i++)
            if (d->obj[i].sel && d->obj[i].cls != JW_MOJI) {
                d->obj[i].flags = (unsigned short)(d->obj[i].flags & ~2u);
                d->obj[i].sel = 0;
            }
        jw_cmd_set(JW_CMD_MOJI);
        ms_text = jw_cmd_moji_count(d) > 0;
        ms_go = go && ms_text;
        return 1;
    }
    if (d && current == JW_CMD_PARAM && sel_step == 3)
        return param_enter(d);          /* 数値位置 の確定 */
    if (jw_cmd_numpos_enter(d))
        return 1;
    if (!d || sel_step != 2
        || (current != JW_CMD_FUKUSHA && current != JW_CMD_IDOU
            && current != JW_CMD_SEIRI && current != JW_CMD_PARAM))
        return 0;
    return sel_confirm(d);
}

/* Shift+Enter in the same 追加・除外 stage is 範囲確定 followed at once by
 * 基点変更 (the bar's 1066, once the range is settled, takes the next click
 * as the 基準点 instead of placing from the tracked point): 複写・移動 show
 * both hints together there (JW_STR_5828 "Enter-範囲確定" and JW_STR_5829
 * "ShiftEnter-基点変更" in sel_prompt_add), データ整理 only the first
 * (string 5828 alone -- its own 基点変更 would be JW_STR_5831's plain
 * "Enter-基点変更", a different stage this has not been asked to touch).
 * **Not reached from either front end yet**: WM_CHAR carries no Shift bit,
 * so the native build would need GetKeyState(VK_SHIFT) read alongside it,
 * and the browser side its event's shiftKey -- src/main_win32.c and
 * index.html call this once that plumbing is added (RESUME.md 2026-10-13). */
int jw_cmd_shift_enter_key(jw_drawing *d)
{
    if (!d || sel_step != 2
        || (current != JW_CMD_FUKUSHA && current != JW_CMD_IDOU))
        return 0;
    if (!sel_confirm(d))
        return 0;
    sel_base_wait = 1;
    return 1;
}

/* 消去 entered with a settled selection takes it out at once.  The original
 * does exactly that: 範囲選択 over Test5, 選択確定, then 消去, and the file
 * it saved had 25 of its 46 lines gone and nothing left picked.
 *
 * Only from 範囲選択 though.  The same three keys after a 複写 -- where the
 * selection is settled too, and still drawn pink -- leave the drawing alone:
 * the original made its copy, 消去 took nothing out, and the 25 elements
 * were still picked in the file it saved.  So this is the 範囲選択 arm (step
 * 4) and not the one 複写 and 移動 place from (step 3). */
int jw_cmd_sel_erase(jw_drawing *d)
{

    /* From 範囲選択, 選択確定 is not needed: the original's bar there has no
       選択確定 at all, and 消去 straight after a box takes what the box
       caught (driving it bears that out).  From 複写 or 移動 it still does
       nothing, which is the same run's other half. */
    if (!d || (sel_step != 4
               && !(sel_step == 2 && prev == JW_CMD_HANI
                    && jw_cmd_sel_count(d) > 0)))
        return 0;
    if (sel_step == 4 && sel_n <= 0)
        return 0;
    return sel_erase_now(d);
}

/* 選ばれている要素を消す（jw_cmd_sel_erase と 消去 の 範囲選択消去）。 */
static int sel_erase_now(jw_drawing *d)
{
    op_t *o;
    int i, n = 0;

    o = op_new();
    for (i = d->nobj - 1; i >= 0; i--)
        if (d->obj[i].sel) {
            op_keep(o, d, i, 1);
            jw_remove(d, i);
            n++;
        }
    sel_free();
    sel_step = 0;
    return n > 0;
}

/* One click while the selection is being placed. */
/* The bar's 倍率 (1411) and 回転角 (1412), which the second stage of 複写 and
   移動 puts up.  Empty means 1 and 0. */
static double sel_scale(void)
{
    const char *t = jw_cmd_box(1411);
    double v = box_num(t, 0.0);

    return v > 0.0 ? v : 1.0;
}

static double sel_turn(void)
{
    const char *t = jw_cmd_box(1412);

    return box_num(t, 0.0) * PI / 180.0;
}

/* 基本設定 2446: レイヤ非表示化 が 表示のみ にする */
static int layhide_shown;

void jw_cmd_layhide_shown(int on)
{
    layhide_shown = on != 0;
}

/* 作図属性設定 (template 342), which the second bar's 作図属性 (1070)
 * puts up.  Four of its ticks say what the elements 複写 and 移動 put down
 * take from the ones being written now rather than keep their own:
 * 書込み線種 (1324), 書込み線色 (1323), 書込み【レイヤ】 (1325) and
 * 書込みレイヤグループ (1326).  The original keeps them on the bar
 * (+0xc80, +0xc84, +0xc88, +0xc8c, in that order -- FUN_00651bb0 hands
 * them to the dialog and back), copies them into CZukeiFukusha
 * (+0xfd5c..+0xfd68) and applies them element by element as it places
 * (FUN_00653fe0):
 *
 *   レイヤ or グループ  the element's group is the write group
 *   レイヤ              and its layer the write layer
 *   線種                its line type the write one -- not a solid's
 *   線色                its colour and width the write ones
 *
 * That is the decompilation's reading and has not been asked of the
 * original.  A text's colour is left alone: CDataMoji's own setter is
 * behind the call and has not been read. */
static int za_on[4];

int jw_cmd_zuzoku(int k)
{
    return k >= 0 && k < 4 ? za_on[k] : 0;
}

void jw_cmd_zuzoku_set(int k, int on)
{
    if (k >= 0 && k < 4)
        za_on[k] = on != 0;
}

static void za_apply(const jw_drawing *d, jw_obj *p)
{
    int g, wg = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    if (za_on[2] || za_on[3])
        p->lgroup = (unsigned short)wg;
    if (za_on[2])
        p->layer = (unsigned short)(d->group[wg].write_layer & 15);
    if (za_on[0] && p->cls != JW_SOLID)
        p->ltype = (unsigned char)(d->write_ltype ? d->write_ltype : 1);
    if (za_on[1] && p->cls != JW_MOJI) {
        p->color = (unsigned short)(d->write_ltype ? d->write_color : 2);
        p->width = (unsigned short)(d->write_ltype ? d->write_width : 0);
    }
}

/* 反転: every picked element across the line that was just pointed at.  A
 * copy for 複写, in place for 移動 -- the same split sel_place() makes. */
static void sel_mirror(jw_drawing *d, const jw_obj *axis)
{
    double ux = axis->d[2] - axis->d[0], uy = axis->d[3] - axis->d[1];
    double len = sqrt(ux * ux + uy * uy);
    int i;

    if (!d || sel_n <= 0 || len < 1e-12)
        return;
    ux /= len;
    uy /= len;
    if (range_moves()) {
        op_t *o = op_new();

        for (i = 0; i < sel_n; i++) {
            int at = sel_at[i];

            if (at >= d->nobj)
                continue;
            op_keep(o, d, at, 0);
            d->obj[at] = sel_was[i];
            jw_obj_mirror(&d->obj[at], axis->d[0], axis->d[1], ux, uy);
            za_apply(d, &d->obj[at]);
            d->obj[at].flags = (unsigned short)(d->obj[at].flags | 2u);
            d->obj[at].sel = 1;
        }
        return;
    }
    {
        int made = 0;

        for (i = 0; i < sel_n; i++) {
            jw_obj *p = jw_add(d, sel_was[i].cls);

            if (!p)
                break;
            *p = sel_was[i];
            jw_obj_mirror(p, axis->d[0], axis->d[1], ux, uy);
            za_apply(d, p);
            p->flags = (unsigned short)(p->flags & ~2u);
            p->sel = 0;
            p->id = 0;
            made++;
        }
        op_push(made);
    }
}

/* The label the 任意方向 button carries, which changes as it is pressed. */
const char *jw_cmd_dir_text(void)
{
    static const char *const s[4] = {
        "\x94\x43\x88\xd3\x95\xfb\x8c\xfc",     /* 任意方向 */
        "X \x95\xfb\x8c\xfc",                        /* X 方向 */
        "Y \x95\xfb\x8c\xfc",                        /* Y 方向 */
        "XY\x95\xfb\x8c\xfc"                         /* XY方向 */
    };

    return s[sel_dir & 3];
}

/* 数値位置 (1413):「x,y」を箱に打つと、置く先は 基準点 + (x,y) になる。
 * 逆コンパイルの読み、原典では押していない:
 *   CFukushaDialog の FUN_004ae4a0 / FUN_004ae510 が箱（+0x808）の二つの数を
 *   取り、どちらも 書込みグループの縮尺（doc +0x2578 + 群×8）で割る（箱は
 *   実寸、移植の内部は図寸）。数が一つなら FUN_0058b290 が y にも同じ数を
 *   入れる。CZukeiFukusha の置く本体 FUN_00653fe0 と追いかけ FUN_0064d290 は、
 *   どちらかの絶対値が 1e-7 を超えると FUN_0044cd50（軸角で回す）を通して
 *   置く先 +0xfc78/+0xfc80 = 基準点 (+0x228/+0x230) + ずれ とし、任意方向の
 *   旗 (+0xfd00/+0xfd04) を 0 にする（クリックの場所も方向も効かない）。
 *   置いたあと FUN_004ae320(0,0) で箱は "0 , 0" に戻る（一度きり）。
 * 基本設定の単位の旗 DAT_00a0d62c（立つと DAT_00a0d630 を掛ける）は移植に
 * 無いので入れていない。 */
static int sel_numpos(const jw_drawing *d, double *ox, double *oy)
{
    const char *t = jw_cmd_box(1413);
    const char *c = t ? strchr(t, ',') : 0;
    double x, y, sc, a;

    if (!t || !*t || !d)
        return 0;
    x = box_num(t, 0.0);
    y = c ? box_num(c + 1, 0.0) : x;
    if (!(fabs(x) > 1e-7 || fabs(y) > 1e-7))
        return 0;
    sc = write_scale(d);
    x /= sc;
    y /= sc;
    a = axis_deg * PI / 180.0;
    if (fabs(axis_deg) >= 1e-7) {
        double ca = cos(a), sa = sin(a), x0 = x;

        x = ca * x0 - sa * y;
        y = ca * y + sa * x0;
    }
    *ox = x;
    *oy = y;
    return 1;
}

static void sel_put(jw_drawing *d, double dx, double dy, double sc, double ang);

static void sel_place(jw_drawing *d, double x, double y)
{
    double dx = x - base_x, dy = y - base_y;
    double sc = sel_scale(), ang = sel_turn();
    int num;

    if (!d || sel_n <= 0)
        return;
    num = sel_numpos(d, &dx, &dy);
    if (!num)
        switch (sel_dir) {      /* 任意方向 squares the move off */
        case 1: dy = 0.0; break;
        case 2: dx = 0.0; break;
        case 3:
            if ((dx < 0 ? -dx : dx) >= (dy < 0 ? -dy : dy))
                dy = 0.0;
            else
                dx = 0.0;
            break;
        }
    /* 連続の一歩は、回数が 0 のときに置いたずれ（FUN_00653fe0 の
       +0xfd80 < 1 なら +0xfd90 = 置く先 - 基準点、+0xfda0 = 倍率、そのあと
       回数を 1 に）。二度目のクリックでは更新しない */
    if (ren_n < 1) {
        ren_dx = dx;
        ren_dy = dy;
        ren_sc = sc;
        ren_n = 1;
    }
    sel_put(d, dx, dy, sc, ang);
    if (num)
        box_put(1413, "0 , 0");
}

/* 連続 (1064): 置いたあと同じずれでもう一度。逆コンパイルの読み、原典では
 * 押していない。釦は値の組 1 → 0x1401 → 命令の仮想関数 25 番目
 * FUN_00651000（バーの受け手 FUN_004adc60 が 1064 (+0x340) の状態を戻す）:
 *   回数 < 1 なら何もしない（釦もそれまで死んでいる。FUN_00653fe0 が回数を
 *   1 にした所で 1064 と 1072 を生かす）。
 *   複写でないとき（+0xfd08 != 1、移動）: 置く先 = 基準点 + 一歩 で、
 *   その場の要素にもう一度掛ける（移動の要素は動いたところから、もう一歩）。
 *   複写: 回数が 1 なら回転角の箱 (1412) を覚え、回数を一つ増やして n とし、
 *   倍率 r が 0 か 1 に近ければ 1、|r| ≤ 1 なら 1-(1-r)n（0 に近ければ
 *   n をもう一つ増やして置かない）、|r| > 1 なら (r-1)n+1（1 万を超えれば
 *   同じく置かない）。角は n×覚えた角、置く先は 基準点 + n×一歩。 */
static int sel_renzoku(jw_drawing *d)
{
    double r = ren_sc, s = 1.0, ar = fabs(r);
    int i;

    if (!d || sel_n <= 0 || ren_n < 1)
        return 0;
    if (range_moves()) {
        for (i = 0; i < sel_n; i++)
            if (sel_at[i] < d->nobj)
                sel_was[i] = d->obj[sel_at[i]];
        sel_put(d, ren_dx, ren_dy, sel_scale(), sel_turn());
        return 1;
    }
    if (ren_n == 1)
        ren_ang = sel_turn();
    ren_n++;
    if (!(ar < 0.0001 || fabs(ar - 1.0) < 0.0001)) {
        s = ar <= 1.0 ? 1.0 - (1.0 - r) * ren_n : (r - 1.0) * ren_n + 1.0;
        if (ar <= 1.0 ? fabs(s) < 0.0001 : fabs(s) > 10000.0) {
            ren_n++;
            return 0;
        }
    }
    sel_put(d, ren_n * ren_dx, ren_n * ren_dy, s, ren_n * ren_ang);
    return 1;
}

static void sel_put(jw_drawing *d, double dx, double dy, double sc, double ang)
{
    int i;

    if (range_moves()) {
        op_t *o = op_new();
        for (i = 0; i < sel_n; i++) {
            int at = sel_at[i];
            if (at >= d->nobj)
                continue;
            op_keep(o, d, at, 0);
            d->obj[at] = sel_was[i];
            jw_obj_xform(&d->obj[at], base_x, base_y, sc, ang, dx, dy);
            za_apply(d, &d->obj[at]);
            d->obj[at].flags = (unsigned short)(d->obj[at].flags | 2u);
            d->obj[at].sel = 1;
        }
        return;
    }
    {   /* 複写: every click leaves another copy, all of them measured from
           the one 基準点 -- three clicks in the original left three copies,
           at one, two and three times the step. */
        int made = 0;
        for (i = 0; i < sel_n; i++) {
            jw_obj *p = jw_add(d, sel_was[i].cls);
            int at;
            if (!p)
                break;
            at = (int)(p - d->obj);
            *p = sel_was[i];
            jw_obj_xform(p, base_x, base_y, sc, ang, dx, dy);
            za_apply(d, p);
            /* a copy is not itself selected: in the original the new
               elements come out in their own colours while the ones that
               were picked stay pink */
            p->flags = (unsigned short)(p->flags & ~2u);
            p->sel = 0;
            p->id = 0;
            (void)at;
            made++;
        }
        op_push(made);
    }
}

/* ---------------------------------------------- パラメトリック変形 -----
 * 32898 (0x8082)、原典の CZukeiParametric。以下はみな逆コンパイルの読みで、
 * 原典では押していない。
 *
 * 範囲を取る段は 範囲選択（CZukeiSentaku）そのもので、違うのは枠の拾い方
 * だけ。枠の判定 FUN_00408d00 は CZukeiParametric のとき選び方 1 で回り、
 * 要素ごとの答え（FUN_0040ab00）が
 *   -1 丸ごと入る  1 始点だけ入る  2 終点だけ入る  3 跨ぐだけ  0 外
 * のうち -1・1・2 を拾って、1・2 には印を付ける（+0x58 の bit 1・bit 2、
 * FUN_0040e410・FUN_0040e450）。端点の「入る」は枠の内側に**厳密に**
 * （FUN_0040cd00 の末尾、端に乗ったものは入らない）。線のほかで 1・2 が
 * 返るのは ソリッド の角（FUN_0040eb50 が四辺を線として見て、入った角ごとに
 * +0x88..+0x94 を立てる）と寸法。円・円弧・点・文字・ブロックは -1 だけ
 * （文字は (R) で終点を取ったときだけ、範囲選択 と同じ）。
 *
 * 選択確定 のあとのバーは 複写・移動 の二枚目と同じ窓（CFukushaDialog）を
 * 型 8 で出したもの（FUN_004accf0）: 任意方向・基点変更・倍率・回転角・
 * 数値位置 が残り、ﾏｳｽ倍率 (1069) の札が 再選択 (0x152b) に替わる。
 * 一手ごとに（FUN_006cf900、要素ごとの FUN_006ce8b0）
 *   倍率・回転角 で 基準点 まわりに変えてから 移動先 − 基準点 だけずらし
 *   （FUN_00465c40・FUN_0046d5b0・FUN_0046bdf0、XY 方向固定 はずらしの
 *   ほうだけに効く）、印の付いた線は動かない側の端点を元へ戻す。
 * 数値位置 に値があればずらしはそれ（実寸を縮尺で割る。方向固定は外れる）で、
 * 案内は 0x1522「位置を確定して下さい」、(L) か Enter（36 番目
 * FUN_006cd8a0）で決まる。決まったら **基準点 は移動先に移り**
 * （+0x228 ← +0xfc78）、選んだものはそのまま次の一手を待つ。一手ごとの
 * 基準点は +0x238 からの表に積まれ、戻る（16 番目 FUN_006cca80）で一つ戻る。
 *
 * 寸法（移植では部品ごとの要素）の端点だけの伸縮と寸法値の書き直し
 * （FUN_0047e400）は入れていない: 寸法の部品は丸ごと入ったときだけ動く。 */
static unsigned char *pm_mask;  /* 要素ごと: 0 = 丸ごと、bit k = k 番目の点だけ動く */
static int pm_cap;
static struct { double x, y; int depth; } pm_hist[256];
static int pm_nh;               /* 一手ごとの 基準点（戻る で戻す） */
static int pm_done;             /* いま変形したところ（案内 6010） */
static double pm_done_x, pm_done_y;

static void param_settle(void)
{
    pm_nh = 0;
    pm_done = 0;
}

static int pm_grow(int n)
{
    if (n > pm_cap) {
        unsigned char *p = (unsigned char *)realloc(pm_mask, (size_t)n);

        if (!p)
            return 0;
        memset(p + pm_cap, 0, (size_t)(n - pm_cap));
        pm_mask = p;
        pm_cap = n;
    }
    return 1;
}

static int pm_in(double x, double y, double x0, double y0, double x1,
                 double y1)
{
    return x > x0 && x < x1 && y > y0 && y < y1;
}

static void param_box(jw_drawing *d, double x0, double y0, double x1,
                      double y1, int with_text)
{
    int i, k;

    if (!pm_grow(d->nobj))
        return;
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        double a, b, c2, e;
        int whole, m = 0;

        if (!o->sel)
            pm_mask[i] = 0;
        if (o->cls == JW_MOJI && !with_text)
            continue;
        jw_obj_box(o, &a, &b, &c2, &e);
        whole = a >= x0 && c2 <= x1 && b >= y0 && e <= y1;
        if (!whole) {
            if (o->sub)
                continue;       /* 寸法の部品は 丸ごとだけ（上の注） */
            if (o->cls == JW_SEN)
                m = pm_in(o->d[0], o->d[1], x0, y0, x1, y1)
                  | pm_in(o->d[2], o->d[3], x0, y0, x1, y1) << 1;
            else if (o->cls == JW_SOLID && o->ltype < 100)
                for (k = 0; k < 4; k++)
                    if (pm_in(o->d[2 * k], o->d[2 * k + 1], x0, y0, x1, y1))
                        m |= 1 << k;
            if (!m)
                continue;
        }
        if (sel_sub) {
            o->flags = (unsigned short)(o->flags & ~2u);
            o->sel = 0;
            pm_mask[i] = 0;
            continue;
        }
        if (o->sel)             /* 追加範囲: 丸ごとが勝ち、端点どうしは合わせる */
            pm_mask[i] = (unsigned char)(pm_mask[i] == 0 || m == 0
                                         ? 0 : pm_mask[i] | m);
        else
            pm_mask[i] = (unsigned char)m;
        o->flags = (unsigned short)(o->flags | 2u);
        o->sel = 1;
    }
}

/* 戻る が一手ぶん取り消したら、その一手の前の 基準点 に戻す */
static void param_sync(void)
{
    int depth = jw_cmd_undo_depth();

    while (pm_nh > 0 && depth < pm_hist[pm_nh - 1].depth) {
        pm_nh--;
        base_x = pm_hist[pm_nh].x;
        base_y = pm_hist[pm_nh].y;
        pm_done = 0;
    }
}

/* 数値位置 (1413): "x,y"（実寸）。両方ほぼ 0 なら無いのと同じ */
static int pm_typed(const jw_drawing *d, double *dx, double *dy)
{
    const char *t = jw_cmd_box(1413), *p;
    double a, b = 0.0, s = write_scale(d);

    if (!t || !*t)
        return 0;
    a = atof(t);
    p = strchr(t, ',');
    if (p)
        b = atof(p + 1);
    if (!(a > -1e12 && a < 1e12) || !(b > -1e12 && b < 1e12))
        return 0;
    if (fabs(a) <= 1e-7 && fabs(b) <= 1e-7)
        return 0;
    *dx = a / s;
    *dy = b / s;
    return 1;
}

static int pm_offset(const jw_drawing *d, double x, double y, double *dx,
                     double *dy)
{
    if (pm_typed(d, dx, dy))
        return 1;
    *dx = x - base_x;
    *dy = y - base_y;
    switch (sel_dir) {          /* 任意方向 / X / Y / XY（FUN_004ae200） */
    case 1: *dy = 0.0; break;
    case 2: *dx = 0.0; break;
    case 3:
        if (fabs(*dx) > fabs(*dy))
            *dy = 0.0;
        else
            *dx = 0.0;
        break;
    }
    return 0;
}

/* 一つの要素: 変えてから、印の付いていない点は元へ */
static void pm_one(const jw_obj *was, jw_obj *o, int mask, double dx,
                   double dy, double sc, double ang)
{
    int k, n = was->cls == JW_SEN ? 2 : 4;

    *o = *was;
    jw_obj_xform(o, base_x, base_y, sc, ang, dx, dy);
    if (mask)
        for (k = 0; k < n; k++)
            if (!(mask >> k & 1)) {
                o->d[2 * k] = was->d[2 * k];
                o->d[2 * k + 1] = was->d[2 * k + 1];
            }
}

static int pm_mask_at(int at)
{
    return at >= 0 && at < pm_cap ? pm_mask[at] : 0;
}

static int param_apply(jw_drawing *d, double dx, double dy)
{
    double sc = sel_scale(), ang = sel_turn();
    op_t *rec;
    int k, n = 0;

    if (!d || sel_n <= 0)
        return 0;
    rec = op_new();
    for (k = 0; k < sel_n; k++) {
        int at = sel_at[k];
        jw_obj w;

        if (at >= d->nobj)
            continue;
        op_keep(rec, d, at, 0);
        w = d->obj[at];
        pm_one(&w, &d->obj[at], pm_mask_at(at), dx, dy, sc, ang);
        d->obj[at].flags = (unsigned short)(d->obj[at].flags | 2u);
        d->obj[at].sel = 1;
        sel_was[k] = d->obj[at];
        n++;
    }
    if (pm_nh < (int)(sizeof pm_hist / sizeof pm_hist[0])) {
        pm_hist[pm_nh].x = base_x;
        pm_hist[pm_nh].y = base_y;
        pm_hist[pm_nh].depth = jw_cmd_undo_depth();
        pm_nh++;
    }
    base_x += dx;               /* 基準点 は移動先へ（+0x228 ← +0xfc78） */
    base_y += dy;
    pm_done = 1;
    pm_done_x = tx;
    pm_done_y = ty;
    return n > 0;
}

static void param_click(jw_drawing *d, const jw_view *v, double x, double y,
                        int button)
{
    double dx, dy;

    if (!d)
        return;
    param_sync();
    /* (R) は読取点（11 番目 FUN_006ce710 が FUN_00451eb0 で点を読んでから
       (L) と同じ 9 番目へ渡す） */
    if (button != 0 && !jw_read(d, v, x, y, &x, &y))
        return;
    if (sel_base_wait) {        /* 基点変更 */
        base_x = x;
        base_y = y;
        sel_base_wait = 0;
        pm_done = 0;
        return;
    }
    pm_offset(d, x, y, &dx, &dy);
    param_apply(d, dx, dy);
}

static int param_enter(jw_drawing *d)
{
    double dx, dy;

    param_sync();
    if (sel_base_wait || !pm_typed(d, &dx, &dy))
        return 0;
    return param_apply(d, dx, dy);
}

static const char *param_prompt(void)
{
    double dx, dy;

    if (sel_base_wait)
        return JW_STR_5314;
    if (pm_done && tracking && tx == pm_done_x && ty == pm_done_y)
        return JW_STR_6010;     /* 【図形をパラメトリック変形しました】 */
    return pm_typed(0, &dx, &dy) ? JW_STR_5410 : JW_STR_5311;
}

int jw_cmd_param_preview(const jw_drawing *d, jw_drawing *out)
{
    static jw_obj *pv;
    static int cpv;
    double dx, dy, sc, ang;
    int k, n = 0;

    if (!d || !out || current != JW_CMD_PARAM || sel_step != 3
        || sel_n <= 0 || !tracking || sel_base_wait)
        return 0;
    param_sync();
    if (cpv < sel_n) {
        jw_obj *p = (jw_obj *)realloc(pv, (size_t)sel_n * sizeof *p);

        if (!p)
            return 0;
        pv = p;
        cpv = sel_n;
    }
    pm_offset(d, tx, ty, &dx, &dy);
    sc = sel_scale();
    ang = sel_turn();
    for (k = 0; k < sel_n; k++) {
        int at = sel_at[k];

        if (at >= d->nobj)
            continue;
        pm_one(&d->obj[at], &pv[n], pm_mask_at(at), dx, dy, sc, ang);
        n++;
    }
    if (!n)
        return 0;
    *out = *d;
    out->obj = pv;
    out->nobj = out->ndrawn = n;
    return 1;
}

int jw_cmd_sel_box(double *x0, double *y0, double *x1, double *y1)
{
    if (sel_step != 1 || !tracking)
        return 0;
    *x0 = sel_x0;
    *y0 = sel_y0;
    *x1 = tx;
    *y1 = ty;
    return 1;
}

int jw_cmd_sel_ghost(double *dx, double *dy)
{
    if (sel_step != 3 || sel_n <= 0 || !tracking
        || current == JW_CMD_PARAM)     /* こちらは jw_cmd_param_preview */
        return 0;
    *dx = tx - base_x;
    *dy = ty - base_y;
    return 1;
}

/* Whether a tick box on the bar is ticked, for the ones the port works: -1
   means "not one of them, use what the original came up with". */
/* 天空率計算 で測定点が建物の内側のときの問い（原典 0x1659）。1 を返すと 窓を出す（一度だけ） */
int jw_cmd_tenku_ask(void)
{
    int r = tn_pend == 1 && current == JW_CMD_TENKU;

    if (r)
        tn_pend = 2;                /* 窓に出した */
    return r;
}

/* 窓の答え: 1 はい（その建物の最小半径は 0）・0 いいえ・-1 キャンセル（何も描かない）。
   同じ点でもう一度描く */
void jw_cmd_tenku_answer(jw_drawing *d, int ans)
{
    if (!tn_pend)
        return;
    tn_pend = 0;
    if (ans < 0 || current != JW_CMD_TENKU || !tn_pend_v)
        return;
    tn_ans = ans ? 1 : 0;
    jw_cmd_point(d, tn_pend_v, tn_pend_x, tn_pend_y, tn_pend_b);
    tn_ans = -1;
}

/* 真北の字（旗 0x40・色 5 の数）を探す。あれば 1 と その角 */
static int tn_north_of(const jw_drawing *d, double *north)
{
    int k, found = 0;

    for (k = 0; k < d->ndrawn; k++)
        if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40) && d->obj[k].text >= 0 &&
            d->obj[k].color == 5) {
            const char *t = jw_str(d, d->obj[k].text);

            if ((t[0] >= '0' && t[0] <= '9') || t[0] == '-') {
                if (north)
                    *north = atof(t);
                found = 1;
            }
        }
    return found;
}

/* 真北が無いときの問いを出すか（一度だけ 1） */
int jw_cmd_tenku_north_ask(void)
{
    int r = tn_nq_pend == 1 && current == JW_CMD_TENKU;

    if (r)
        tn_nq_pend = 2;
    return r;
}

/* その答え: OK なら 上向きとして 同じ点でもう一度描く。キャンセルなら 何も描かない */
void jw_cmd_tenku_north_answer(jw_drawing *d, int ok)
{
    if (!tn_nq_pend)
        return;
    tn_nq_pend = 0;
    if (!ok || current != JW_CMD_TENKU || !tn_pend_v)
        return;
    tn_nq = 1;
    jw_cmd_point(d, tn_pend_v, tn_pend_x, tn_pend_y, tn_pend_b);
    tn_nq = -1;
}

/* 三斜のつまみを初めの状態に戻す（試験用。原典ではコマンドを選び直しても残る） */
void jw_cmd_sansha_reset(void)
{
    tn_s_plan = 1;
    tn_s_calc = 0;
    tn_s_conf = 0;
}

int jw_cmd_bar_check(int id)
{
    if (current == JW_CMD_GAZOU) {
        int r = jw_cmd_gazou_check(id);

        if (r >= 0)
            return r;
    }
    if (id == 1064 && TG_IS3(current))
        return tg_cat >= 0;         /* 選んだあとに 縦＝横 が出るバー */
    if (id == 9005 && current == JW_CMD_HIKAGE)
        return hk_pv;
    if (id == 9002 && current == JW_CMD_HIKAGE)
        return hk_sub;
    if (id == 9003 && current == JW_CMD_HIKAGE)
        return hk_pts;
    if (id == 9004 && current == JW_CMD_HIKAGE)
        return hk_iso_on;
    /* 天空図 (32971) のバーは歩みで替わる（tools/tnprobe.sh で原典のバーを
       読んだ、decomp/res/bars3.txt の 232971_90xx）: 正射影 (1064)／等距離
       射影 (1065)／三斜 (1068) を押して 測定点待ち（9005・9013・9010）、
       測定点を置いて 中心待ち（9006・9014・9011）。中心待ちのバーは 天空率
       計算 (1323) で 高精度計算・射影面積表示 が、太陽軌跡 (1325) で
       南方向補正・10分間隔点表示・四季 が出る（9007・9008・9009。等距離は
       1323 の字が「[天空比計算]」の 9015 だが、1325 を入れたものは録って
       いないので 正射影 の 9008・9009 で代える）。 */
    if (current == JW_CMD_TENKU && tn_sansha && tn_mode == 2) {
        if (id == 1689) return !tn_s_plan;
        if (id == 1690) return tn_s_plan;
        if (id == 1329) return tn_s_calc;
        if (id == 2114) return tn_s_conf;
    }
    if (id >= 9005 && id <= 9015 && current == JW_CMD_TENKU) {
        int c = jw_cmd_bar_check(1323) > 0, s = jw_cmd_bar_check(1325) > 0;

        if (tn_cmp)
            return id == 9012;      /* 天空率比較計算 は ≪ だけ */
        if (tn_mode == 1)
            return id == (tn_sansha ? 9010 : tn_equi ? 9013 : 9005);
        if (tn_mode == 2) {
            if (tn_sansha)
                return id == 9011;
            if (s)
                return id == (c ? 9009 : 9008);
            if (tn_equi)
                return id == (c ? 9015 : 9014);
            return id == (c ? 9007 : 9006);
        }
        return 0;
    }
    if (id == 9001 && current == JW_CMD_KIGOU)
        return sk_step == 4;        /* 文字入力のあいだの バー */
    if (id == 1146 && TG_IS(current))
        return tg_page2;            /* ＞ で替わる二枚目 */
    if ((id == 1428 || id == 2448) && TG_IS(current)) {
        /* S の行のある建具には 内出・外出 の箱と 基準厚 が出る。
           S の三つ目があると基準厚に (A) が付く */
        const jw_tategu *t = tg_cat >= 0 ? jw_tategu_load(tg_cat) : 0;

        if (!t || tg_item < 0 || tg_item >= t->nitem || tg_page2 ||
            !t->item[tg_item].has_s)
            return 0;
        return id == 1428 ? 1 : t->item[tg_item].s_third;
    }
    if (id == 1070 && current == JW_CMD_TAKAKU)
        return tk_any;
    if (id == 1692 && current == JW_CMD_MENTORI)
        return mt_mode == 1692;     /* Ｌ面 のバー（寸法の箱が消える） */
    if (id == 1689 && current == JW_CMD_TAKAKU && tk_any)
        return 0;               /* 任意のバーのほうが先 */
    if (id >= 1689 && id <= 1693 && jw_cmd_bar_radio(id) >= 0)
        return jw_cmd_bar_radio(id);   /* 選ばれているラジオ */
    if (current == JW_CMD_SEN || current == JW_CMD_KUKEI
        || current == JW_CMD_RENZOKU) {
        if (id == 1332)
            return current == JW_CMD_KUKEI;
        if (id == 1333)
            return hv;
    }
    if (id == 1334 && range_cmd(current))
        return sel_outside;
    if (id == 1344 && range_cmd(current))
        return sel_cut;
    if (current == JW_CMD_HATCH && id == 1323)
        return ht_jisun;
    if (current == JW_CMD_ZOKUHEN && id == 1352)
        return zh_type;
    if (current == JW_CMD_ZOKUHEN && id == 1353)
        return zh_layer;
    {   /* every other checkbox: what it was left at, or how the original
           has it when the command is entered */
        const unsigned char *on = chk_slot(bar_cmd(), id);
        if (on)
            return *on;
    }
    return -1;
}

int jw_cmd_bar_enabled(const jw_drawing *d, int id)
{
    if (current == JW_CMD_GAZOU)
        return jw_cmd_gazou_enabled(id);
    if (current == JW_CMD_MOJI && ms_text) {
        /* texts picked: 貼付 and 文書 appear, 文読 gives way */
        if (id == 1065 || id == 1070)
            return 1;
        if (id == 1069)             /* its place goes to 1092, the SJIS/UTF8 switch */
            return 1;
    }
    /* 測定's bar shares its ids with 範囲選択's, and the cases below are
       written for that one -- so they would have greyed 距離測定 and
       面積測定 out.  On 測定's bar everything is alive except
       ○単独円指定, which dies while 角度測定 is chosen
       (tools/probe130.sh). */
    if (current == JW_CMD_HIKAGE && hk_pts && (id == 1065 || id == 1066))
        return hkp_n > 0;           /* 測定点を置いてから */
    if (current == JW_CMD_HIKAGE && hk_pts && id == 1070)
        return hkp_n == 0;
    if (current == JW_CMD_SOKUTEI)
        return id == 1068 ? sok_mode != SOK_ANG : 1;
    if (current == JW_CMD_BUNKATSU && id >= 1064 && id <= 1066)
        /* 補助設定の釦。馬目地分割 (1065) は縦分割数の窓と FUN_00767990 を
           写していないので押せなくしておく（原典は押せる） */
        return id != 1065 && jw_cmd_bunkatsu_hojo();
    /* 連続線 の 終了 は、一本（連続弧なら一つ）引けてから点く —— 原典は
       辺を足すたびに FUN_005b8360(1)、終わりで (0)。逆コンパイルの読み */
    if (current == JW_CMD_RENZOKU && id == 1064)
        return jw_cmd_bar_check(2492) > 0 ? ra_have : step == 3;
    if (current == JW_CMD_TAKAKU && tk_any) {
        /* 任意のバー: 作図 は三点から、任意色と色設定 はソリッド図形を点けて
           から（原典のバーを読んだとおり） */
        if (id == 1069)
            return tk_an >= 3;
        if (id == 1083)
            return jw_cmd_bar_check(1323) > 0 && tk_an == 0;
        if (id == 1325 || id == 1326)
            return jw_cmd_bar_check(1323) > 0;
        if (id == 1327 || id == 1328)
            return jw_cmd_bar_check(1323) > 0 && tk_pickmode;
        if (id == 1324 || id == 2552)
            return jw_cmd_bar_check(1323) > 0;
    }
    if (current == JW_CMD_FUKUSEN && (id == 1065 || id == 1066 || id == 1067)) {
        /* slot 6 (FUN_00656f10): 端点指定 (+0x2c8) は状態 3 で一本の線のとき。
           連続線選択 (+0x248) は線を拾うと生きる（fk_chain_ok）。範囲選択は
           いつも生きている */
        if (id == 1065)
            return d && !fk_selmode && !fk_ten && para_obj >= 0
                   && para_obj < d->ndrawn && d->obj[para_obj].cls == JW_SEN
                   && fk_dir_wait(d);
        if (id == 1066)
            return fk_chain_ok(d);
        return id == 1067;
    }
    if (current == JW_CMD_HANI && id == 1068)
        /* 選択図形登録: CSentakuDialog の FUN_005c8120 は 範囲が決まった段
           (param != 0) の 範囲選択 (+0xcc == 0) で 1068〜1071 を生かし、
           切取り選択 (+0x1e8)・範囲外選択 (+0x1ec) なら殺す */
        return sel_step == 2 && !sel_cut && !sel_outside;
    if (current == JW_CMD_PARAM && sel_step == 3 && id == 1069)
        return 1;                   /* 二枚目の 1069 は 再選択 */
    switch (id) {
    case 1120:
        /* 寸法 has 実行 here, and it is alive at exactly one
           place: 一括処理's third prompt.  tools/probe45.sh read
           the button at all five stages of the walk and it went
           58010f00, 58010f00, 58010f00, **50010f00**, 58010f00. */
        if (current == JW_CMD_SUNPO)
            return ika_step == 3;
        return sel_step == 2 && jw_cmd_sel_count(d) > 0;   /* 選択確定 */
    case 1064:                  /* 基準点変更 (not 連続: the template's 278 says so),
                                   alive once something is picked */
        if ((current == JW_CMD_FUKUSHA || current == JW_CMD_IDOU)
            && sel_step == 3)
            return ren_n >= 1;  /* 二枚目では 連続: 一度置いてから */
        if (range_cmd(current) && sel_step == 2)
            return jw_cmd_sel_count(d) > 0;
        return 0;
    case 1065:                  /* 前範囲, and 追加範囲 once a box is in */
        return sel_step == 2 || sel_step == 0;
    case 1067:                  /* 選択解除, and 反転 one stage on */
        return sel_step == 3 || jw_cmd_sel_count(d) > 0;
    case 1066:                  /* 全選択, and 基点変更 one stage on: the
                                   original has both of them alive */
        return 1;
    case 1069:                  /* ＜属性選択＞, once a box is in */
        return sel_step == 2;
    case 1151:                  /* 任意方向, only once the range is settled */
        return sel_step == 3;
    case 1072:
        /* 寸法の一括処理 comes up dead and one drawn dimension wakes
           it (tools/probe37.sh).  Elsewhere 1072 is 範囲選択, which is
           not this port's business here. */
        if (current == JW_CMD_SUNPO)
            return ika_live;
        return -1;
    }
    return -1;                  /* not one this port knows about */
}

/* The presses the port acts on.  Every command's own block ends with a
   `return 0`, so this cannot be where the generic answer goes -- see
   jw_cmd_bar below. */
/* 分割の補助設定の釦（逆分割 1066・線長割合分割 1064・馬目地分割 1065）が
 * バーに出ているか。原典 FUN_00763bf0 の条件: 線（Ａ）を (L) で指示済み
 * （+0xc0==2・+0xac==0、Ａが CDataSen）で、等距離分割（+0xb8==0）・割付が
 * 切（+0x7e84==0）。逆コンパイルの読み、原典では押していない。 */
int jw_cmd_bunkatsu_hojo(void)
{
    return current == JW_CMD_BUNKATSU && corner_step == 1 && corner_obj >= 0
        && !bk_a_enko && bk_rr_n == 0 && bk_mode != 1690
        && jw_cmd_bar_check(1324) <= 0;
}

static int bar_press(jw_drawing *d, int id)
{
    /* 線 and 矩形 share a bar and a class (CZukeiSen): its 矩形 box is what
       tells them apart, and 水平・垂直 is the same flag pressing 線 twice
       flips. */
    if (current == JW_CMD_SEN || current == JW_CMD_KUKEI
        || current == JW_CMD_RENZOKU) {
        if (id == 1332) {
            jw_cmd_set(current == JW_CMD_KUKEI ? JW_CMD_SEN : JW_CMD_KUKEI);
            return 1;
        }
        if (id == 1333) {
            hv = !hv;
            return 1;
        }
    }
    /* 連続線 の 終了 (1064)・弧反転 (1067)。逆コンパイルの読み、原典では
     * 押していない。釦は CRenzokuSenDailog の地図で 1064 → FUN_004180c0、
     * 1067 → FUN_00418c00 で、view へ私用メッセージ 0x1401・0x1404 を送り、
     * view (FUN_00512170・FUN_00512230) が CZukeiRenzokuSen の
     * slot 25・28 を呼ぶ。
     *   終了   slot 25 (FUN_006d9630) = slot 4 (FUN_006db060) で控えの
     *          ひとつ手前を図面へ入れ、状態を素へ戻す。同一点クリックの
     *          終わりと同じで、命令の送り直し（jw_cmd_flush）とも同じ。
     *   弧反転 slot 28 (FUN_006d96c0) は +0x460 を裏返すだけ。読むのは
     *          連続弧の続きの弧 (FUN_006dc260) で、次の弧の回りを逆にする。
     * 基準角度 (1065)・基点 (1066) は入れていない —— 読みでは 1065 が
     * +0xc0 を 0 → 15° → 45° → 0 と回し、線の向きを その倍数（＋軸角）へ
     * 丸める（FUN_006de7a0・FUN_006dcff0）が、素から 1065 だけ押して
     * 三クリックした原典の答え（decomp/res/bsw_32883_1065_solo.jww）は
     * **何も入っていない**。丸めた線が一本入るはずの読みと合わず、
     * 理由が読み切れていない。 */
    if (current == JW_CMD_RENZOKU && id == 1064) {
        jw_cmd_flush(d);
        step = 0;
        ra_step = ra_have = 0;
        ra_flip = 0;
        return 1;
    }
    if (current == JW_CMD_RENZOKU && id == 1067
        && jw_cmd_bar_check(2492) > 0) {
        ra_flip = !ra_flip;
        return 1;
    }
    if (current == JW_CMD_SEIRI && sel_step == 3) {
        if (id == 1064 || id == 1065)   /* 重複整理, 連結整理 */
            return seiri(d, id == 1065) > 0;
        if (id >= 1066 && id <= 1069)   /* the four that only reorder */
            return seiri_sort(d, id) > 0;
        if (id == 1072) {               /* 範囲選択: take another one */
            sel_clear(d);
            sel_step = 0;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_HATCH) {
        if (id >= 1689 && id <= 1693) {
            ht_mode_set(id);
            return 1;
        }
        if (id == 1147) {       /* 基点変 -- the next click is the point */
            ht_base_wait = 1;
            return 1;
        }
        if (id == 1323) {       /* 実寸 */
            ht_jisun = !ht_jisun;
            return 1;
        }
        if (id == 1067) {       /* 範囲選択 -- a boxful instead of one ring */
            sel_clear(d);
            ht_sel = 1;
            ht_n = 0;
            ht_nreg = 0;
            return 1;
        }
        if (id == 1120) {       /* 選択確定 */
            if (ht_sel != 3 || !d)
                return 0;
            hatch_selected(d);
            sel_clear(d);
            ht_sel = 0;
            return 1;
        }
        if (id == 1068) {       /* 選択図形登録 */
            if (ht_sel != 3 || !d || !hatch_register(d))
                return 0;
            sel_clear(d);
            ht_sel = 0;
            return 1;
        }
        if (id == 1149) {       /* クリアー */
            ht_n = 0;
            ht_nreg = 0;
            ht_nchain = 0;
            sel_clear(d);
            ht_sel = 0;
            return 1;
        }
        if (id == 1148) {       /* 実行 */
            hatch(d);
            ht_n = 0;
            ht_nreg = 0;
            ht_nchain = 0;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_SHOUKYO && (id == 1066 || id == 1067)) {
        /* 範囲選択消去 (1066)・連続範囲選択消去 (1067): CZukeiShoukyo の
           27 番 FUN_0070e760（+0x200 = 1）と 28 番 FUN_0070e8f0（+0x200 = 2）。
           範囲の途中（+0x200 が 0 でない）では何もしない。逆コンパイルの読み、
           原典では押していない */
        if (shk_sel || !d)
            return 0;
        sel_clear(d);
        cut_step = 0;
        shk_sel = 1;
        shk_rep = id == 1067;
        return 1;
    }
    if (current == JW_CMD_KYOKUSEN) {
        if (id >= 1689 && id <= 1692) {
            cv_mode = id;
            cv_n = 0;
            cv_base = 0;
            return 1;
        }
        if (id == 1800) {       /* 作図実行 */
            kyokusen(d);
            cv_n = 0;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_TAKAKU && id >= 1689 && id <= 1692) {
        tk_mode = id;
        return 1;
    }
    if (current == JW_CMD_KIGOU && id == 1064) {
        sk_need_pick = 1;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && !hk_sub && !hk_pts && !hk_iso_on && id == 1065) {
        hk_iso_on = 1;              /* 等時間: 時間の選択へ */
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_iso_on) {
        static const double lv[5] = { 2.0, 2.5, 3.0, 4.0, 5.0 };

        if (id == 1064) {
            hk_iso_on = 0;
            return 1;
        }
        if (id == 1070) {
            hk_ask_time = 2;        /* 時間（1 - 8）を入力 */
            return 1;
        }
        if (id >= 1065 && id <= 1069)
            return hk_iso_n(d, lv[id - 1065], lv[id - 1065]) > 0;
        if (id == 1071) {           /* 精度: 標準 (60 秒) と 10 秒、範囲指定のあとは 10 と 4 */
            if (hk_iso_rng == 3)
                hk_iso_step = hk_iso_step == 10 ? 4 : 10;
            else
                hk_iso_step = hk_iso_step == 60 ? 10 : 60;
            return 1;
        }
        if (id == 1072) {           /* 範囲指定 と 範囲解除 */
            hk_iso_rng = hk_iso_rng == 3 ? 0 : 1;
            if (hk_iso_rng == 0 && hk_iso_step != 60 && hk_iso_step != 10)
                hk_iso_step = 60;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_HIKAGE && id == 1064 && hk_pts) {
        hk_pts = 0;                 /* 指定点 から戻る */
        hk_calc_step = 0;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_pv) {
        switch (id) {
        case 1121: hk_pv = 0; break;
        case 1123: hk_pv_az -= 5.0; break;
        case 1124: hk_pv_az += 5.0; break;
        case 1125: hk_pv_el += 5.0; break;
        case 1126: hk_pv_el -= 5.0; break;
        case 1084: hk_pv_az = 0.0; hk_pv_el = 0.0; break;
        case 1129: hk_pv_az = -45.0; hk_pv_el = 35.264389682754654; break;
        default: return 0;
        }
        /* 仰角は 0〜90 に止まり、方位角は (−180, 180] に畳む（原典の実測: 左を 40 回で −245 が 115、
           185 は −175、−180 は 180） */
        if (hk_pv_el < 0.0)
            hk_pv_el = 0.0;
        if (hk_pv_el > 90.0)
            hk_pv_el = 90.0;
        while (hk_pv_az > 180.0)
            hk_pv_az -= 360.0;
        while (hk_pv_az <= -180.0)
            hk_pv_az += 360.0;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && id == 1067 && !hk_sub && !hk_pts) {
        hk_pv = 1;                  /* 確認: 建物を針金で見る窓（初めは −45・30） */
        hk_pv_az = -45.0;
        hk_pv_el = 30.0;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && id == 1066 && !hk_sub && !hk_pts) {
        hk_pts = 1;                 /* 指定点: 測定点を押す */
        hkp_n = 0;
        hk_calc_step = 0;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_pts && (id == 1065 || id == 1066)) {
        if (hkp_n > 0)
            hk_calc_step = id == 1065 ? 60 : 10;     /* 結果を書く位置を押す */
        return 1;
    }
    if (current == JW_CMD_HIKAGE && id == 1064) {
        hk_sub = 1;                 /* 日影図: 時間の選択へ */
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_sub && id == 1121) {
        hk_sub = 0;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_sub && id >= 1069 && id <= 1071) {
        hk_tbl_pending = id;        /* 表を書く位置を指示 */
        return 1;
    }
    if (current == JW_CMD_HIKAGE && id == 1085 && !hk_sub && !hk_pts) {
        hk_write_cond = 1;          /* 測定条件を書込む位置を指示 */
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_sub && id == 1067) {
        hk_ask_time = 1;            /* 作図時間を入力してください（8 - 16） */
        return 1;
    }
    if (current == JW_CMD_HIKAGE && hk_sub && (id == 1065 || id == 1066)) {
        hk_outlines(d, id == 1066);
        return 1;
    }
    if (current == JW_CMD_TENKU && id == 1066 && !tn_mode && !tn_cmp) {
        tn_cmp = 1;                 /* FUN_007393f0: +0xbc = 5、+0x1b0 = 0 */
        tn_cdec = 2;
        tn_csan = 0;
        return 1;
    }
    if (current == JW_CMD_TENKU && id == 1121 && tn_cmp > 0) {
        tn_cmp--;
        return 1;
    }
    if (current == JW_CMD_TENKU && (id == 1064 || id == 1065)) {
        tn_mode = 1;                /* 測定点を指示 */
        tn_equi = id == 1065;
        tn_sansha = 0;
        return 1;
    }
    if (current == JW_CMD_HIKAGE && id == 1068) {
        hk_north = 1;               /* 真北を設定する線端部を指示 */
        return 1;
    }
    if (current == JW_CMD_TENKU && id == 1121 && tn_mode > 0) {
        tn_mode--;                  /* ≪: Esc と同じく一段戻る（原典、tools/hkprobe.sh s12） */
        return 1;
    }
    if (current == JW_CMD_TENKU && tn_sansha && tn_mode == 2 &&
        (id == 1689 || id == 1690 || id == 1329 || id == 2114)) {
        if (id == 1689) tn_s_plan = 0;
        else if (id == 1690) tn_s_plan = 1;
        else if (id == 1329) tn_s_calc = !tn_s_calc;
        else tn_s_conf = !tn_s_conf;
        return 1;
    }
    if (current == JW_CMD_TENKU && id == 1068) {
        tn_mode = 1;                /* 三斜（+0x1a0 = 1）で 測定点を指示 */
        tn_equi = 0;
        tn_sansha = 1;
        return 1;
    }
    if (TG_IS3(current) && id == 1064) {
        tg_need_pick = 1;
        return 1;
    }
    if (TG_IS3(current) && id == 1065) {
        tg_rh = (tg_rh + 1) % 3;
        return 1;
    }
    if (TG_IS3(current) && id == 1066) {
        tg_rv = (tg_rv + 1) % 3;
        return 1;
    }
    if (TG_IS(current) && id == 1065) {
        tg_need_ref = 1;            /* 基準点選択の窓 */
        return 1;
    }
    if (TG_IS(current) && id == 1064) {
        tg_need_pick = 1;
        return 1;
    }
    if (TG_IS(current) && id == 1146) {
        tg_page2 = !tg_page2;
        return 1;
    }
    if (current == JW_CMD_MENTORI && id >= 1689 && id <= 1693) {
        mt_mode = id;
        return 1;
    }
    if (current == JW_CMD_BUNKATSU && (id == 1689 || id == 1690)) {
        bk_mode = id;
        return 1;
    }
    if (current == JW_CMD_BUNKATSU && (id == 1064 || id == 1066)) {
        /* 補助設定の釦: 1066 逆分割（FUN_00763ee0）・1064 線長割合分割
           （FUN_00763cd0、馬目地は切る）。出ているときだけ効く。押したあとの
           札（FUN_00763f20 が 「逆分割 , 線長割合分割」をカーソルのそばに
           出す）は移植に札が無いので出さない */
        if (!jw_cmd_bunkatsu_hojo())
            return 0;
        if (id == 1066)
            bk_gyaku = !bk_gyaku;
        else
            bk_senchou = !bk_senchou;
        return 1;
    }
    if (current == JW_CMD_SESSEN) {
        /* the four ways of drawing a tangent */
        if (id >= 1689 && id <= 1692) {
            ses_mode = id;
            ses_step = 0;
            ses_a = -1;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_MOJI && id == 1068) {
        /* 連: 連結・移動・切断.  The input box goes away while it is on,
           which is what the original does too. */
        ren_step = ren_step ? 0 : 1;
        return 1;
    }
    if (current == JW_CMD_ZOKUHEN) {
        if (id == 1352)
            return zh_type = !zh_type, 1;
        if (id == 1353)
            return zh_layer = !zh_layer, 1;
        return 0;
    }
    if (current == JW_CMD_SUNPO) {
        if (id == 1061) {       /* 小数桁: 2 -> 3 -> 0 -> 1 -> 2 */
            sun_keta = (sun_decimals() + 1) & 3;
            return 1;
        }
        if (id == 1062) {       /* 端部: a point or an arrowhead */
            sun_arrow = !sun_arrows();
            return 1;
        }
        if (id == 1065) {       /* 半径 */
            sun_radius = 1;
            sun_radius_made = 0;
            sun_step = 2;
            return 1;
        }
        if (id == 1066) {       /* 直径 */
            sun_radius = 2;
            sun_radius_made = 0;
            sun_step = 2;
            return 1;
        }
        if (id == 1067) {       /* 円周: a circle is indicated first */
            sun_enshu = 1;
            sun_kaku = 0;
            sun_radius = 0;
            sun_chi = 0;
            sun_step = 7;
            return 1;
        }
        if (id == 1068) {       /* 角度 */
            sun_kaku = 1;
            sun_radius = 0;
            sun_chi = 0;
            sun_enshu = 0;
            sun_step = 4;   /* the origin comes first */
            return 1;
        }
        if (id == 1069) {       /* 寸法値: the value and nothing else */
            sun_chi = 1;
            sun_chi_done = 0;
            sun_radius = 0;
            sun_kaku = 0;
            sun_enshu = 0;
            sun_step = 5;
            return 1;
        }
        if (id == 1072) {       /* 一括処理 */
            if (!ika_live)
                return 0;
            ika_step = 1;
            ika_ntog = 0;
            ika_lt = -1;
            return 1;
        }
        if (id == 1120) {       /* 実行 */
            /* It draws exactly what the (R) at the third prompt draws:
               the two runs of tools/probe46.sh came out with byte for
               byte the same element list.  The one difference is where
               they leave the walk -- the (R) goes back to the 始線
               prompt and 実行 stays on the third one. */
            if (ika_step != 3 || !d)
                return 0;
            ika_run(d);
            return 1;
        }
        if (id == 1064) {       /* リセット: back to the two-point kind */
            sun_radius = 0;
            sun_kaku = 0;
            sun_chi = 0;
            sun_enshu = 0;
            sun_step = 0;
            return 1;
        }
        /* ＝ (1060, 引出線タイプ) は入れていない（docs/notes-commands.md
           の「寸法 の ＝」）: 0〜3 を回すところまでは読めたが、=(1)(2) は
           基準点のあと「マウス移動で確定」の段 (+0x1bc == 7) を通り、
           クリックだけでは進み方が決まらない。 */
        if (id != 1059)
            return 0;
        /* ０º/９０º: the 傾き box turns over between the two.  Asked of
           the original with the ends of a slanted line read, the dimension
           came out standing up and measuring the height between them, and
           pressing it twice drew exactly what no press drew. */
        box_put(1411, sun_angle() == 0.0 ? "90" : "0");
        return 1;
    }
    if (!range_cmd(current))
        return 0;
    if (!jw_cmd_bar_enabled(d, id))
        return 0;
    if (current == JW_CMD_PARAM && sel_step == 3 && id == 1069) {
        /* 再選択: CZukeiParametric の 30 番目 FUN_006cd720 が 範囲選択 の段
           （+0x1fc = 1）へ戻す。要素の印（+0x44 の bit 1）には触らないので、
           選んだものは残ったまま 追加・除外 の段になる（逆コンパイルの読み、
           原典では押していない） */
        sel_free();
        sel_step = d && jw_cmd_sel_count(d) > 0 ? 2 : 0;
        sel_base_wait = 0;
        return 1;
    }
    switch (id) {
    case 1334:                  /* 範囲外選択 -- only before the box */
        if (sel_step != 0)
            return 0;
        sel_outside = !sel_outside;
        return 1;
    case 1344:                  /* 切取り選択, likewise */
        if (sel_step != 0)
            return 0;
        sel_cut = !sel_cut;
        return 1;
    case 1064:                  /* 基準点変更: the next click is the 基準点 */
        if (sel_step == 3)      /* 二枚目のバーでは 連続 */
            return sel_renzoku(d);
        if (!range_cmd(current) || sel_step != 2 || !d || jw_cmd_sel_count(d) <= 0)
            return 0;
        sel_base_pick = 1;
        return 1;
    case 1065:                  /* 追加範囲 -- the next box adds to it */
        if (sel_step != 2 || jw_cmd_sel_count(d) <= 0) {
            /* 前範囲: with nothing picked, CZukeiSentaku's FUN_006fcb00
               picks again what the last selection had, of what can be
               edited now (FUN_0042dd10) -- read off the decompile, not
               asked of the original.  None left: its message 0x1592 */
            int i, n = 0;

            if (!d || (sel_step != 0 && sel_step != 2))
                return 0;
            for (i = 0; i < d->ndrawn; i++)
                if (d->obj[i].was_sel && jw_pick_editable(d, &d->obj[i])) {
                    d->obj[i].flags = (unsigned short)(d->obj[i].flags | 2u);
                    d->obj[i].sel = 1;
                    n++;
                }
            if (!n)
                return 0;
            sel_step = 2;
            return 1;
        }
        sel_keep = 1;
        sel_sub = 0;
        sel_step = 0;
        return 1;
    case 1120:
        return sel_confirm(d);
    case 1067:
        if (sel_step == 3) {    /* 反転 -- the same id as 選択解除, one stage
                                   on, where the bar puts 反転 in its place */
            sel_flip = 1;
            ren_n = 0;          /* FUN_006517e0 も +0xfd80 を 0 に */
            return 1;
        }
        sel_clear(d);
        sel_step = 0;
        sel_flip = sel_base_wait = 0;
        sel_dir = 0;
        return 1;
    case 1059:                  /* 0ﾟ/90ﾟ on 寸法's bar */
        box_put(1411, sun_angle() == 0.0 ? "90" : "0");
        return 1;
    case 1151:                  /* 任意方向 -- X, Y, XY and round again */
        if (sel_step != 3)
            return 0;
        sel_dir = (sel_dir + 1) & 3;
        return 1;
    case 1066: {                /* 全選択, 除外範囲, or 基点変更 later on */
        int i;
        if (!d)
            return 0;
        if (sel_step == 3) {
            sel_base_wait = 1;
            return 1;
        }
        /* 何も入っていない枠のあとは 除外範囲 ではなく 全選択（原典: 空の範囲のあとの 1066 で 複線 が
           図面の全部を元にした。fuzz 62・71、tmp/ov.py） */
        if (sel_step == 2 && jw_cmd_sel_count(d) > 0) {    /* 除外範囲: the next box takes away */
            sel_keep = 1;
            sel_sub = 1;
            sel_step = 0;
            return 1;
        }
        /* 全選択: 原典（CZukeiSentaku の 44 番目 FUN_006fc520）は 全部の選択の印を消してから、
           守られていなくて（FUN_0042dcb0）編集できる（FUN_0042dd10）ものだけに付ける。
           表示のみ・非表示のレイヤの要素は選ばない */
        for (i = 0; i < d->ndrawn; i++) {
            int on = jw_pick_editable(d, &d->obj[i]);

            d->obj[i].flags = (unsigned short)(on ? d->obj[i].flags | 2u : d->obj[i].flags & ~2u);
            d->obj[i].sel = (unsigned char)on;
        }
        sel_step = 2;
        return 1;
    }
    }
    return 0;
}

/* Boxes that turn each other off.  線's four right-hand ones do: ticking
 * ●─── (1348) clears ＜─── (1349) and ＜ (1351), ticking ＜ clears the
 * other three, and 寸法値 (1350) clears ＜ -- FUN_005be280, FUN_005be320,
 * FUN_005bdf80 and FUN_005be220 each zero the others' members before they
 * put the bar back up. */
static void bar_exclude(int id)
{
    static const struct { int cmd, id, off[3]; } X[] = {
        { JW_CMD_SEN, 1348, { 1349, 1351, 0 } },
        { JW_CMD_SEN, 1349, { 1348, 1351, 0 } },
        { JW_CMD_SEN, 1350, { 1351, 0, 0 } },
        { JW_CMD_SEN, 1351, { 1348, 1349, 1350 } },
        /* 円: 半円 (1320) の受け手 FUN_004abfc0 は 3点指示 (+0xaf4) を、
         * 3点指示 (1321) の受け手 FUN_004ac010 は 半円 (+0xaf0) を 0 に
         * します（`decomp/byclass/_unassigned.c`） */
        { JW_CMD_ENKO, 1320, { 1321, 0, 0 } },
        { JW_CMD_ENKO, 1321, { 1320, 0, 0 } },
        /* 多角形 任意: 線形・円周 (1326)・弓形 (1327)・円外側 (1328) は
         * 一つだけ。受け手 FUN_005ec1d0・FUN_005ec230・FUN_005ec280
         * （_unassigned.c 213700 台）が点いたとき残り二つを 0 にする */
        { JW_CMD_TAKAKU, 1326, { 1327, 1328, 0 } },
        { JW_CMD_TAKAKU, 1327, { 1326, 1328, 0 } },
        { JW_CMD_TAKAKU, 1328, { 1326, 1327, 0 } }
    };
    int i, k;

    for (i = 0; i < (int)(sizeof X / sizeof X[0]); i++) {
        if (X[i].cmd != current || X[i].id != id)
            continue;
        for (k = 0; k < 3; k++) {
            unsigned char *o;
            if (!X[i].off[k])
                break;
            o = chk_slot(bar_cmd(), X[i].off[k]);
            if (o)
                *o = 0;
        }
    }
}

int jw_cmd_moji_ready(void)
{
    return current == JW_CMD_MOJI && ms_text;
}

/* 1 once, when 外部エディタ was pressed first and the range is now settled */
int jw_cmd_moji_go(void)
{
    int g = ms_go;

    ms_go = 0;
    return g;
}

int jw_cmd_bar(jw_drawing *d, int id)
{
    unsigned char *on;

    last_dr = d;

    /* 複線の 範囲選択 (1067) から出た 範囲: 選択確定 で 複線 に戻る（fk_back を見よ） */
    if (fk_back && current == JW_CMD_HANI && id == 1120) {
        if (!d || sel_step != 2)
            return 0;
        fk_back_go(d);
        return 1;
    }
    if (current == JW_CMD_HANI && id == 1068) {
        /* 選択図形登録: 範囲選択のバーの 1068 は FUN_00418c30 で 0x1405 →
           CZukeiSentaku の 29 番目 FUN_006fb760。+0xb0（追加・除外範囲）を 0 に、
           選択が空なら 5201「図形がありません」、でなければ 登録の一覧を空けて
           （FUN_00454900）選んだものの写しを入れ、10038「《図形登録》」。範囲も
           選択もそのまま残る。ハッチの 選択図形登録（CZukeiHachi の 29 番目
           FUN_00674450）も同じ FUN_006fb760 を呼ぶので、入れ先は ハッチの 図形
           (1693) が使う ht_pat（hatch_register、文字は入れない）。札は移植に
           出す所がないので出さない。逆コンパイルの読み、原典では押していない */
        if (!d || sel_step != 2 || sel_cut || sel_outside)
            return 0;
        sel_keep = sel_sub = 0;
        if (jw_cmd_sel_count(d) <= 0)
            return 1;
        hatch_register(d);
        return 1;
    }
    if (current == JW_CMD_FUKUSEN && id == 1067) {
        snprintf(fk_back_box, sizeof fk_back_box, "%s",
                 jw_cmd_box(1411) ? jw_cmd_box(1411) : "");
        jw_cmd_set(JW_CMD_HANI);
        fk_back = 1;
        return 1;
    }
    if (current == JW_CMD_FUKUSEN && id == 1065) {
        /* 端点指定: slot 6 は 状態 3 で一本の線のときだけ 1065 を生かす */
        if (!d || fk_selmode || para_obj < 0 || para_obj >= d->ndrawn
            || d->obj[para_obj].cls != JW_SEN || !fk_dir_wait(d))
            return 0;
        fk_ten = 3;
        tracking = 0;
        return 1;
    }
    if (current == JW_CMD_FUKUSEN && id == 1066) {
        /* 連続線選択: slot 27 FUN_0065b780（fk_chain_ok の注） */
        int k = fk_selmode ? fk_one_sel(d) : para_obj;

        if (!fk_chain_ok(d))
            return 0;
        fk_ten = 0;             /* +0x284 = 0 */
        tracking = 0;
        if (chain_walk(d, k, 1)) {
            fk_selmode = 1;     /* FUN_00659200: 選んだ鎖が元 */
            fk_sel_used = 0;
            fk_rprev = 0.0;
            para_step = 1;
            para_obj = -1;
        } else {                /* 全円など: +0x204 = 0（線を選ぶ段へ） */
            sel_clear(d);
            para_step = 0;
            para_obj = -1;
        }
        return 1;
    }

    if (current == JW_CMD_MOJI && !ren_step) {
        if (id == 2407 || (id == 1067 && !ms_text)) {
            int after = id == 1067;

            jw_cmd_set(JW_CMD_HANI);
            ms_back = 1;
            ms_after = after;
            return 1;
        }
        if (id == 1092) {
            jw_moji_sjis_toggle();
            return 1;
        }
    }

    if (current == JW_CMD_GAZOU && gz_bar(d, id))
        return 1;
    if (bar_press(d, id))
        return 1;
    /* Anything the command itself does not act on, and that the original has
       as a checkbox there: its tick moves whatever the command makes of it,
       so the port's does too. */
    if (current == JW_CMD_SUNPO && id == 1070) {
        sun_prog = !sun_prog;
        return 1;
    }
    /* 点 (仮実点) のバー。原典に訊いた動き（src/cmd.c の 点 の注）:
       1064 仮点消去 は押しっぱなしの状態、1065 全仮点消去 はその場で
       kind=1 を全部落とす、1066 交点 は（Ａ）【Ｂ】の二段。 */
    if (current == JW_CMD_TEN) {
        if (id == 1064) {
            ten_del = 1;
            ten_cross = 0;
            ten_a = -1;
            return 1;
        }
        if (id == 1065) {
            int i;
            op_t *rec = 0;

            if (d)
                for (i = d->ndrawn - 1; i >= 0; i--)
                    if (d->obj[i].cls == JW_TEN && d->obj[i].n == 1) {
                        if (!rec)
                            rec = op_new();
                        erase(d, i, rec);
                    }
            ten_del = 0;
            return 1;
        }
        if (id == 1066) {
            ten_cross = 1;
            ten_del = 0;
            ten_a = -1;
            return 1;
        }
        if (id == 1323) {               /* 仮点: 置くものが変わるだけ */
            ten_del = 0;                /* 印はこの下の chk_slot が動かす */
            ten_cross = 0;
            ten_a = -1;
        }
    }
    /* 測定's bar: the four 〜測定 are one choice of four, and the two on
       the right turn the unit and the number of places (src/cmd.c's 測定
       note).  Pressing any of them starts the run over. */
    if (current == JW_CMD_SOKUTEI) {
        if (id >= SOK_LEN && id <= SOK_ANG) {
            sok_mode = id;
            sok_reset();
            tail_set(4, 0.0, 0.0);
            return 1;
        }
        if (id == 1068) {               /* ○単独円指定 */
            sok_one = !sok_one;
            return 1;
        }
        if (id == 1071) {               /* 測定結果書込 */
            /* it starts the measuring over, and then asks where the
               number goes -- so what gets written is the fresh zero
               (src/cmd.c's 測定 note) */
            sok_reset();
            sok_write = 1;
            tail_set(4, 0.0, 0.0);
            return 1;
        }
        if (id == 1069) {
            /* while 角度測定 is chosen this button is 【 °】／ °′″
               instead and turns the readout to 度分秒 and back
               (FUN_0071dcb0: DAT_00a0be54, and the length unit is left
               alone) */
            if (sok_mode == SOK_ANG)
                sok_dms = !sok_dms;
            else
                sok_unit = !sok_unit;
            return 1;
        }
        if (id == 1070) {
            sok_dp = (sok_dp + 1) % 6;  /* 0 1 2 3 4 F とめぐる */
            return 1;
        }
    }
    /* 複線の 両側複線 (1068)・留線付両側複線 (1069)・連続 (1064).
     *
     * Asked of the original with a line picked and 1000 typed into the
     * spacing on a 1/100 sheet:
     *   両側複線        two copies, ten out either side, the near one
     *                   written first -- and no click to say which side
     *   留線付両側複線  the same two, with a line across each end joining
     *                   them, and those two caps written first
     *   連続            after a copy is made, one more the same distance
     *                   on from it
     * None of them needs the third click: the button is the direction. */
    if (current == JW_CMD_NISEN
        && (id == 1064 || id == 1065 || id == 1066)) {
        /* ２線 の 間隔反転 (1064)・1/2 間隔 (1065)・２倍間隔 (1066).
         *
         * Asked of the original with 2000,1000 in the box: 間隔反転 left the
         * text alone (it turns which side is which, not the numbers), 1/2
         * 間隔 wrote back 「1000 , 500」 and ２倍間隔 「4000 , 2000」 --
         * halved and doubled, with a space either side of the comma. */
        const char *t = jw_cmd_box(1412);
        double a, b;
        const char *p;
        char buf[64];

        if (id == 1064) {
            nisen_flip = !nisen_flip;
            return 1;
        }
        /* 箱が空でも効きます —— 空は 50 と同じ扱いなので（上の
           NISEN_DEFAULT の注）、1/2 間隔 で 25 になります。原典に
           空のまま押させると、引いた二本が ±0.25 図寸mm になりました
           （`tools/barsweep.sh`、`decomp/res/bsw_32892_1065.jww`）。 */
        if (t && *t) {
            a = box_num(t, 0.0);
            p = strchr(t, ',');
            b = p ? box_num(p + 1, 0.0) : a;
        } else {
            a = b = NISEN_DEFAULT;
        }
        if (id == 1065) {
            a /= 2.0;
            b /= 2.0;
        } else {
            a *= 2.0;
            b *= 2.0;
        }
        sprintf(buf, "%g , %g", a, b);
        box_put(1412, buf);
        return 1;
    }
    if (current == JW_CMD_FUKUSEN
        && (id == 1064 || id == 1068 || id == 1069)) {
        double gap = box_mm(d, 1411);
        const jw_obj *src;
        double dx, dy, len, nx, ny;
        int base = id == 1064 ? para_find(d) : para_obj;
        int k;
        fk_ten = 0;             /* slot 25・29・30 は +0x284 を 0 に */

        if (!d || base < 0 || base >= d->ndrawn
            || d->obj[base].cls != JW_SEN)
            return 1;
        if (id == 1064) {
            if (para_off == 0.0)
                return 1;
            gap = para_off < 0.0 ? -para_off : para_off;
        }
        if (gap <= 0.0)
            return 1;
        src = &d->obj[base];
        dx = src->d[2] - src->d[0];
        dy = src->d[3] - src->d[1];
        len = sqrt(dx * dx + dy * dy);
        if (len < 1e-09)
            return 1;
        nx = -dy / len;
        ny = dx / len;
        if (id == 1064) {
            /* on the same side again, from the copy that was just made */
            jw_obj *o = jw_add(d, JW_SEN);
            double f = para_off < 0.0 ? -gap : gap;
            if (!o)
                return 1;
            o->d[0] = src->d[0] + nx * f;
            o->d[1] = src->d[1] + ny * f;
            o->d[2] = src->d[2] + nx * f;
            o->d[3] = src->d[3] + ny * f;
            para_last = (int)(o - d->obj);
            para_last_obj = *o;
            op_push(1);
            return 1;
        }
        {
            double ax = src->d[0], ay = src->d[1];
            double bx = src->d[2], by = src->d[3];
            int made = 0;
            if (id == 1069) {
                /* the two caps first, each from one side to the other */
                for (k = 0; k < 2; k++) {
                    jw_obj *o = jw_add(d, JW_SEN);
                    double px = k ? bx : ax, py = k ? by : ay;
                    if (!o)
                        break;
                    o->d[0] = px + nx * gap;
                    o->d[1] = py + ny * gap;
                    o->d[2] = px - nx * gap;
                    o->d[3] = py - ny * gap;
                    made++;
                }
            }
            for (k = 0; k < 2; k++) {
                jw_obj *o = jw_add(d, JW_SEN);
                double f = k ? -gap : gap;
                if (!o)
                    break;
                o->d[0] = ax + nx * f;
                o->d[1] = ay + ny * f;
                o->d[2] = bx + nx * f;
                o->d[3] = by + ny * f;
                if (!k) {
                    para_last = (int)(o - d->obj);
                    para_last_obj = *o;
                }
                made++;
            }
            para_off = gap;
            op_push(made);
        }
        para_step = 0;
        return 1;
    }
    /* the two buttons beside ●─── and ＜─── walk the mark round its
       three ends.  The original leaves them dead while their own box is
       clear, and pressing one then drew nothing different. */
    if ((id == 1836 || id == 1837) && current == JW_CMD_SEN) {
        int k = id == 1836 ? 0 : 1;
        if (jw_cmd_bar_check(id == 1836 ? 1348 : 1349) > 0)
            mark_side[k] = (unsigned char)((mark_side[k] + 1) % 3);
        return 1;
    }
    if (current == JW_CMD_TAKAKU && id == 1070 && !tk_any) {
        /* 任意: バーが別物になり、クリックは頂点を積む。`<<` (1071) で戻る */
        tk_any = 1;
        tk_an = 0;
        return 1;
    }
    if (current == JW_CMD_TAKAKU && tk_any && id == 1083) {
        tk_pickmode = 1;
        return 1;
    }
    if (current == JW_CMD_TAKAKU && tk_any && id == 1071) {
        tk_pickmode = 0;
        tk_any = 0;
        tk_an = 0;
        return 1;
    }
    if (current == JW_CMD_TAKAKU && tk_any && id == 1069) {
        if (tk_an < 3 || !d)
            return 0;
        takaku_any(d);
        return 1;
    }
    if (id == 1068 && current == JW_CMD_TAKAKU) {
        tk_pos = (tk_pos + 1) % 3;
        return 1;
    }
    if (id == 1064 && current == JW_CMD_ENKO) {
        /* 基点: FUN_004ac2c0(1).  半径の箱が空なら 0→2→0 、あれば 1〜8 を回す */
        if (box_mm(d, 1411) <= 1e-7) {
            en_kihon += 2;
            if (en_kihon > 2)
                en_kihon = 0;
        } else {
            en_kihon += 1;
            if (en_kihon > 8)
                en_kihon = 0;
        }
        return 1;
    }
    on = chk_slot(bar_cmd(), id);
    if (on) {
        *on = (unsigned char)!*on;
        if (*on)
            bar_exclude(id);
        return 1;
    }
    return 0;
}

int jw_cmd_sunpo_angle(void)
{
    /* the angle comes out of a text box through atof(), so it may be 1e300
       and the cast would be undefined */
    return jw_whole(sun_angle());
}

static void box_put(int id, const char *v)
{
    char *t = box_slot(bar_cmd(), id);

    if (t) {
        strncpy(t, v, sizeof box[0].t - 1);
        t[sizeof box[0].t - 1] = 0;
    }
}

/* Switch the hatch to one of the five modes, swapping the bar's numbers over
   when that crosses between the line modes and the grid ones. */
static void ht_mode_set(int id)
{
    static const int ID[3] = { 1419, 1411, 1412 };
    int was = ht_mode >= 1692, now = id >= 1692, i;

    if (was != now)
        for (i = 0; i < 3; i++) {
            const char *t = jw_cmd_box(ID[i]);

            if (t) {
                strncpy(ht_keep[was][i], t, sizeof ht_keep[0][0] - 1);
                ht_keep[was][i][sizeof ht_keep[0][0] - 1] = 0;
            }
            box_put(ID[i], ht_keep[now][i]);
        }
    ht_mode = id;
}

const char *jw_cmd_box(int id)
{
    return box_slot(bar_cmd(), id);
}

/* what a dialog hands back to a box, as if it had been typed in */
int jw_cmd_box_put(int id, const char *v)
{
    /* 複線 (JW_CMD_FUKUSEN)'s first bar -- before a line or circle is
       picked -- is 「複線にする図形を選択してください ﾏｳｽ(L)　前回値
       ﾏｳｽ(R)」 with no 間隔 box in it at all (jw_cmd_prompt's
       JW_CMD_FUKUSEN case); the box only appears once para_step reaches
       1.  Typing into 1411 before that pick therefore lands on nothing in
       the original -- tools/difffuzz.py's op_fukusen found this ("typed
       before the first pick the original ignores the value"), and
       tools/fzcheck.py cases 7, 8, 22, 25, 29, 34, 38, 40, 44, 45, 49, 50,
       52, 54, 57, 58, 60, 63, 64, 65, 66 (a typed box before any pick)
       bear it out: the line comes back unchanged, with no offset copy at
       all. */
    if (current == JW_CMD_FUKUSEN && id == 1411 && para_step == 0)
        return 0;
    if (!jw_cmd_box(id))
        return 0;
    box_put(id, v);
    return 1;
}

int jw_cmd_box_focus(void)
{
    return box_focus;
}

/* A sum typed into a box.  The original's boxes take a formula -- every
   CMy02ComboBox value goes through FUN_004f2220 / FUN_004f47b0, its
   expression reader -- so 900+75 in 寸法 is 975.  The port takes the four
   operations and brackets (the reader the 日影 height box already has,
   hk_eval) and works the sum out when the box is left or Enter is pressed,
   leaving the answer in the box; each of two numbers either side of a comma
   is worked out on its own.  The reader is the original's, read off the
   decompile (box_calc below): + - * / % ^ and brackets, the functions
   s c a q b i l n j, p and pp ppp, m, 0x / &, e and 度:分'秒".  What it
   cannot do -- @ \ x y, which are values the original takes from elsewhere,
   and its "@@" / "**" way of writing degrees -- is left as typed, as is a sum
   the original would refuse with a message.  The 日影・天空図・2.5D boxes are
   left alone, their height box has a syntax of its own. */
static int hk_bad;                      /* a number was wanted and not there (hk_atom) */
static int box_calc(const char *t, double *out);

/* The original's expression reader, FUN_004f2220 (read off the decompile;
   the original was not driven for it).  Three passes over the text:

   1. FUN_004f47b0 tidies it: spaces and R dropped, the letters it knows
      lowered, m (metres) is *1000 and mm is nothing, 0x is &, and a degree
      mark with no number before it gets a 0.  A letter it does not know
      empties the lot.
   2. FUN_004f2480 makes it the inner form: // is a (the angle of a slope),
      pp is # (√2/√3) and ppp $ (1/√3), every run of digits -- with its
      度:分'秒" marks and a sign just after an operator -- goes in [ ], a *
      goes in between a number and a bracket, constant or function next to
      it, e after a number is *10^[...], and & / 0x hex is turned into a
      number.  Then it checks the order (an operator not followed by a
      number and so on) and that the brackets close.
   3. FUN_004f36e0 / 3fa0 / 3930 / 3470 / 3b80 work it out by recursive
      descent: + -, then * / % (% of whole numbers), then ^ (left to
      right), and a function letter takes the one number or bracket after
      it -- s30 is sin 30°, so s30+1 is 1.5.

   0 when the original would have shown one of its messages (or the text
   has something the port does not carry: @ \ x y, @@ / ** degrees). */
#define BC_DEG ':'                      /* the original's +0x2f4, a ':' read as one */

static int bc_class(int c)              /* FUN_004f3a30 */
{
    if (c == 0)
        return 0;
    if (c == '.' || (c >= '0' && c <= '9'))
        return 1;
    if (c == '@' || c == 'p' || c == 'x' || c == 'y' || c == '\\' || c == '#' || c == '$')
        return 2;
    if (c == '-' || c == '+')
        return 3;
    if (c == '*' || c == '/' || c == '^' || c == '%')
        return 4;
    if (c == '[' || c == '(')
        return 5;
    if (c == ']' || c == ')')
        return 6;
    if (c && strchr("aicsqblnj", c))
        return 7;
    if (c == BC_DEG || c == '\'' || c == '"' || c == ':')
        return 8;
    if (c == 'e' || c == 'E')
        return 9;
    return -1;
}

static int bc_map(int c)                /* FUN_004f4200 */
{
    if (c == '(')
        return '[';
    if (c == ')')
        return ']';
    if (c == 'P')
        return 'p';
    if (c == ',')
        return 0;
    return c;
}

static int bc_fn(int c)
{
    return c && strchr("aicsqblnj", c) != 0;
}

static double bc_expr(const int *t, int *pos, int *err);

static int bc_atom(const int *t, int *pos, double *val, int *err)    /* FUN_004f3b80 */
{
    double deg = 0.0;
    int dms = 0, c;

    for (;;) {
        double frac = -1.0, num = 0.0;

        *val = 0.0;
        for (;;) {
            if (*err > 100)
                return 0;
            c = t[(*pos)++];
            if (c == '.') {
                if (frac > 0.0)
                    *err = 0x68;
                else
                    frac = 1.0;
            } else if (c >= '0' && c <= '9') {
                if (frac > 0.0) {
                    frac /= 10.0;
                    num = (double)(c - '0') * frac + num;
                } else
                    num = num * 10.0 + (double)(c - '0');
                *val = num;
            } else if (c == 'p')
                *val = 3.141592653589793;
            else if (c == '#')
                *val = sqrt(2.0) * 1.0 / sqrt(3.0);
            else if (c == '$')
                *val = 1.0 / sqrt(3.0);
            else
                break;
        }
        if (c == BC_DEG) {
            deg = *val;
            dms = 1;
        } else if (c == '\'') {
            deg = *val / 60.0 + deg;
            dms = 2;
        } else if (c == '"') {
            deg = *val / 3600.0 + deg;
            dms = 3;
        } else
            break;
    }
    if (dms == 1)
        deg = *val / 60.0 + deg;
    if (dms == 2)
        deg = *val / 3600.0 + deg;
    if (dms) {
        int k = bc_class(c);

        *val = deg;
        if (k != 0 && k != 3 && k != 4 && k != 6) {
            *err = 0x68;
            return 0;
        }
    }
    if (c == '[') {
        if (*err < 100) {
            *val = bc_expr(t, pos, err);
            c = *err < 0x65 ? t[(*pos)++] : 0;
        } else {
            *err = 800;
            c = 0;
        }
    }
    return c;
}

static double bc_pow(const int *t, int *pos, double base, int *c, int *err)    /* FUN_004f3930 */
{
    double e;

    do {
        *c = bc_atom(t, pos, &e, err);
        if (*err > 100)
            return 0.0;
        if ((base < 0.0 && e != (double)(int)e) || (base == 0.0 && e <= 0.0)) {
            *err = 0x67;
            return 0.0;
        }
        base = pow(base, e);
        if (1e20 < base) {
            *err = 0x65;
            return 0.0;
        }
    } while (*c == '^');
    return base;
}

static double bc_func(const int *t, int *pos, double was, int *c, int *err)    /* FUN_004f3470 */
{
    int f = *c;
    double x, r = was;

    *c = bc_atom(t, pos, &x, err);
    if (*err >= 0x65)
        return 0.0;
    switch (f) {
    case 'a': r = atan2(x, 1.0) * 180.0 / 3.141592653589793; break;
    case 'i':
        if (fabs(x) > 100000000.0) {
            *err = 0x65;
            return 0.0;
        }
        r = (double)(int)x;
        break;
    case 'c': r = cos(x * 3.141592653589793 / 180.0); break;
    case 's': r = sin(x * 3.141592653589793 / 180.0); break;
    case 'b': r = fabs(x); break;
    case 'l':
    case 'n':
        if (x <= 0.0) {
            *err = 0x65;
            return 0.0;
        }
        r = f == 'l' ? log10(x) : log(x);
        break;
    case 'j': r = exp(x); break;
    case 'q':
        if (x < 0.0) {
            *err = 0x65;
            return 0.0;
        }
        r = sqrt(x);
        break;
    }
    return r;
}

static double bc_term(const int *t, int *pos, int op, double left, int *c, int *err)   /* FUN_004f3fa0 */
{
    double v;

    for (;;) {
        *c = bc_atom(t, pos, &v, err);
        if (*err > 100)
            return 0.0;
        if (*c == '^')
            v = bc_pow(t, pos, v, c, err);
        if (bc_fn(*c))
            v = bc_func(t, pos, v, c, err);
        if (op == '*')
            left *= v;
        if (op == '/') {
            if (v == 0.0)
                *err = 0x66;
            else
                left /= v;
        }
        if (op == '%') {
            if (fabs(v) <= 100000000.0 && fabs(left) <= 100000000.0 && (int)v != 0)
                left = (double)((int)left % (int)v);
            else
                *err = 0x65;
        }
        if (1e20 < left)
            *err = 0x65;
        if (*err > 100)
            return 0.0;
        if (*c != '*' && *c != '/' && *c != '%')
            return left;
        op = *c;
    }
}

static double bc_expr(const int *t, int *pos, int *err)    /* FUN_004f36e0 */
{
    double sum = 0.0, v;
    int op = '+', c;

    for (;;) {
        for (;;) {
            c = bc_atom(t, pos, &v, err);
            if (*err > 100)
                return 0.0;
            if (c == '^')
                v = bc_pow(t, pos, v, &c, err);
            if (*err > 100)
                return 0.0;
            if (bc_fn(c))
                v = bc_func(t, pos, v, &c, err);
            if (*err > 100)
                return 0.0;
            if (c != '+' && c != '-' && c != 0 && c != ']')
                break;
            if (op == '+')
                sum += v;
            if (op == '-')
                sum -= v;
            if (c < 1 || c == ']')
                break;
            op = c;
        }
        if (c != '*' && c != '/' && c != '%')
            return sum;
        if (op == '+')
            sum = bc_term(t, pos, c, v, &c, err) + sum;
        else if (op == '-')
            sum = sum - bc_term(t, pos, c, v, &c, err);
        if (*err > 100)
            return 0.0;
        if (c <= 0 || c == ']')
            return sum;
        op = c;
    }
}

static int box_calc(const char *text, double *out)
{
    int s[80], t[300], n = 0, i, k, br = 0, err = 0, prev, depth;
    size_t len = strlen(text);

    *out = 0.0;
    if (len >= 64)
        return 0;
    /* 1. FUN_004f47b0 */
    for (i = 0; text[i]; i++) {
        int c = (unsigned char)text[i], nx = (unsigned char)text[i + 1];

        if (c == ' ' || c == 'R')
            continue;
        if (c >= 'A' && c <= 'Z' && strchr("ABCDEFSXYILNJPQ", c))
            c += 'a' - 'A';
        if (c == 'm' || c == 'M') {
            if (nx == 'm' || nx == 'M') {
                i++;
                continue;
            }
            if (nx == '^')
                return 0;               /* m^2 and the like: not carried */
            if (n + 5 >= 72)
                return 0;
            s[n++] = '*'; s[n++] = '1'; s[n++] = '0'; s[n++] = '0'; s[n++] = '0';
            continue;
        }
        if (c == '0' && (nx == 'x' || nx == 'X'))
            c = '&';
        if (c == '&') {
            s[n++] = '&';
            if (text[i] == '0')
                i++;
            while (n < 72) {
                int h = (unsigned char)text[i + 1];

                if (h >= 'A' && h <= 'F')
                    h += 'a' - 'A';
                if (!((h >= '0' && h <= '9') || (h >= 'a' && h <= 'f')))
                    break;
                s[n++] = h;
                i++;
            }
            continue;
        }
        if (c == '@' || c == '\\' || c == 'x' || c == 'y')
            return 0;                   /* values the original takes from elsewhere */
        if (c == '*' && nx == '*')
            return 0;                   /* its other way of writing degrees */
        if (bc_class(c) < 0)
            return 0;
        if ((c == BC_DEG || c == ':') && (n == 0 || bc_class(s[n - 1]) != 1))
            s[n++] = '0';
        if (n >= 72)
            return 0;
        s[n++] = c;
    }
    s[n] = 0;
    s[n + 1] = 0;
    if (n == 0)
        return 0;
    /* 2. FUN_004f2480 */
    k = 0;
#define BC_PUT(ch) do { if (k + 2 >= (int)(sizeof t / sizeof t[0])) return 0; t[++k] = (ch); } while (0)
    for (i = 0; i < 1000 && s[i]; i++) {
        int c = bc_map(s[i]);

        if (c == 0 || c == 10 || c == ';')
            break;
        if (c == ' ')
            continue;
        if (c == '/' && s[i + 1] == '/') {
            c = 'a';
            i++;
        }
        if (c == 'p' && bc_map(s[i + 1]) == 'p') {
            c = '#';
            i++;
        }
        if (c == '#' && bc_map(s[i + 1]) == 'p') {
            c = '$';
            i++;
        }
        if (c == '&') {
            unsigned long h = 0;
            int digits = 0, after;
            char num[24];
            const char *q;

            BC_PUT('[');
            for (;;) {
                int d = s[i + 1];

                if (!((d >= '0' && d <= '9') || (d >= 'a' && d <= 'f')))
                    break;
                h = h * 16 + (unsigned long)(d <= '9' ? d - '0' : d - 'a' + 10);
                digits++;
                i++;
            }
            after = bc_class(s[i + 1]);
            if (!digits || digits > 6 || s[i + 1] == '.'
                || (after != 0 && after != 3 && after != 4 && after != 6))
                return 0;               /* 0x6a */
            snprintf(num, sizeof num, "%d", (int)h);
            for (q = num; *q; q++)
                BC_PUT(*q);
            BC_PUT(']');
            continue;
        }
        if (k == 0 || c != 'e' || bc_class(t[k]) != 1) {
            int sign = 0;

            if (k != 0 && bc_class(c) == 8 && bc_class(t[k]) == 8)
                BC_PUT('0');
            if (c == '+' || c == '-') {
                prev = k == 0 ? 0 : t[k];
                if (bc_class(prev) == 4 || bc_class(prev) == 7)
                    sign = 1;
            }
            if (bc_class(c) == 1 || bc_class(c) == 8 || sign) {
                if (!br) {
                    br = 1;
                    BC_PUT('[');
                }
            } else if (br) {
                br = 0;
                BC_PUT(']');
            }
            if (k != 0 && (bc_class(c) == 2 || c == '[' || bc_class(c) == 7)
                && (bc_class(t[k]) == 1 || bc_class(t[k]) == 2 || t[k] == ']'))
                BC_PUT('*');
            BC_PUT(c);
            if ((bc_class(c) == 2 || c == ']')
                && (bc_class(s[i + 1]) == 1 || bc_class(s[i + 1]) == 2 || bc_class(s[i + 1]) == 5))
                BC_PUT('*');
            if (bc_class(c) == -1)
                return 0;               /* 0x68 */
        } else {
            int got = 0, nk;

            BC_PUT('*'); BC_PUT('1'); BC_PUT('0'); BC_PUT('^'); BC_PUT('[');
            nk = bc_class(s[i + 1]);
            for (;;) {
                if (nk != 1 && (nk != 3 || got))
                    break;
                if (s[i + 1] == '.') {
                    got = 0;
                    break;
                }
                i++;
                BC_PUT(s[i]);
                got = 1;
                nk = bc_class(s[i + 1]);
            }
            if (!got || nk == -1 || (nk != 0 && nk != 3 && nk != 4 && nk != 6))
                return 0;               /* 0x69 */
            BC_PUT(']');
        }
    }
    if (br)
        BC_PUT(']');
#undef BC_PUT
    t[k + 1] = 0;
    t[k + 2] = 0;
    /* the order check */
    depth = 0;
    prev = 0;
    for (i = 0; i < k; i++) {
        int a = bc_class(t[i + 1]), b = bc_class(t[i + 2]);

        if (a == 1 && (b == 7 || b == 2 || b == 5))
            return 0;
        if (a == 2 && (b == 1 || b == 2 || b == 5))
            return 0;
        if (a == 3 && b != 1 && b != 2 && b != 5 && b != 7)
            return 0;
        if (a == 4 && (i == 0 || (b != 1 && b != 2 && b != 5 && b != 7)))
            return 0;
        if (a == 5 && (depth++, b == 0 || b == 4 || b == 6))
            return 0;
        if (a == 6 && (depth--, b == 1 || b == 2 || b == 5 || b == 7))
            return 0;
        if (a == 7 && (b == 3 || b == 4))
            return 0;
        if (a == 8 && (prev == 0 || (2 < prev && prev < 9)))
            return 0;
        if (a == b && (a == 3 || a == 4 || (6 < a && a < 10)))
            return 0;
        prev = a;
    }
    if (depth != 0)
        return 0;
    /* 3. FUN_004f36e0 */
    i = 1;
    *out = bc_expr(t, &i, &err);
    (void)len;
    return err == 0;
}

static void box_sum(int id)
{
    char *t = id ? box_slot(bar_cmd(), id) : 0, out[64], part[64];
    const char *p;
    int k = 0, any = 0;

    if (!t || current == JW_CMD_HIKAGE || current == JW_CMD_TENKU || current == JW_CMD_25D)
        return;
    out[0] = 0;
    for (p = t; ; ) {
        const char *q = strchr(p, ',');
        size_t n = q ? (size_t)(q - p) : strlen(p), i;
        double v;
        int op = 0, digit = 0;

        if (n >= sizeof part)
            return;
        memcpy(part, p, n);
        part[n] = 0;
        for (i = 0; i < n; i++)
            if (part[i] != ' ')
                digit = 1;
        if (digit) {
            const char *q = part + strspn(part, " ");

            if (*q == '-')
                q++;
            op = q[strspn(q, "0123456789. ")] != 0;  /* a plain number is left as typed */
        }
        if (op) {
            if (!box_calc(part, &v) || !(v == v) || v > 1e12 || v < -1e12)
                return;                 /* not one the reader finished */
            snprintf(part, sizeof part, "%.10g", v);
            any = 1;
        }
        if (k + strlen(part) + 2 >= sizeof out)
            return;
        if (k)
            out[k++] = ',';
        strcpy(out + k, part);
        k += (int)strlen(part);
        if (!q)
            break;
        p = q + 1;
    }
    if (any)
        box_put(id, out);
}

void jw_cmd_box_click(int id)
{
    int was = box_focus;

    box_focus = jw_cmd_box(id) ? id : 0;
    box_fresh = box_focus != 0;
    if (was && was != box_focus)
        box_sum(was);
}

int jw_cmd_box_key(int ch)
{
    char *t = box_focus ? box_slot(bar_cmd(), box_focus) : 0;

    if (t) {
        int n = (int)strlen(t);
        if (ch == 13 || ch == 27) {         /* Enter, Esc: done */
            int was = box_focus;

            box_focus = 0;
            if (ch == 13)
                box_sum(was);
            return 1;
        }
        if (ch == 8) {                      /* backspace */
            if (box_fresh)
                t[0] = 0;
            else if (n)
                t[n - 1] = 0;
            box_fresh = 0;
            return 1;
        }
        /* ２線's box holds two numbers with a comma between them, and any
           box takes a sum (box_sum) */
        if ((ch >= '0' && ch <= '9') || ch == '.' || ch == '-' || ch == ','
            || (ch > ' ' && ch < 127 && strchr("+*/()^%:'\"&[]", ch))
            || (ch > ' ' && ch < 127 && strchr("aAbBcCeEiIjJlLmMnNpPqQsSxX", ch))) {
            if (box_fresh) {
                t[0] = 0;
                n = 0;
            }
            box_fresh = 0;
            if (n < (int)sizeof box[0].t - 1) {
                t[n] = (char)ch;
                t[n + 1] = 0;
            }
            return 1;
        }
        return 1;                           /* anything else: swallowed */
    }
    return 0;
}

/* One 多角形, round the point that was clicked.
 *
 * Read off the original: the 寸法 box is the radius out to a corner in real
 * units, so paper millimetres are that over the layer group's scale (2000 on
 * a 1/200 group came out 10 mm across the paper); 角数 is how many corners;
 * and the shape sits with its base level, turned by 底辺角度.  The corners
 * are therefore at -90 - 180/n + 底辺角度 and every 360/n after that, going
 * round the way the original's lines do.  A pentagon of 3000 at 30 degrees
 * and an octagon of 3000 at 30 both came out exactly there. */
static void tg_place(jw_drawing *d, double x, double y)
{
    const jw_tategu *t;
    jw_tg_pose p;
    double along = (x - tg_ax) * tg_ux + (y - tg_ay) * tg_uy;
    int made;

    if (tg_cat < 0 || !d || !(t = jw_tategu_load(tg_cat)))
        return;
    memset(&p, 0, sizeof p);
    p.mikomi = box_num(jw_cmd_box(1424), 70.0);
    p.wakuhaba = box_num(jw_cmd_box(1425), 35.0);
    p.uchinori = box_num(jw_cmd_box(1426), 1700.0);
    p.shinzure = box_num(jw_cmd_box(1427), 0.0);
    p.uchide = box_num(jw_cmd_box(1428), 75.0);
    p.sotode = box_num(jw_cmd_box(1429), 75.0);
    p.have_io = 1;
    p.flip_lr = jw_cmd_bar_check(1325) > 0;
    p.flip_io = jw_cmd_bar_check(1324) > 0;
    p.have_ref = 1;
    p.ref_col = tg_ref / 3;
    p.ref_row = tg_ref % 3;
    p.scale = write_scale(d);
    p.ox = tg_ax + along * tg_ux;
    p.oy = tg_ay + along * tg_uy;
    p.ux = tg_ux;
    p.uy = tg_uy;
    made = jw_tategu_put(tg_dst ? tg_dst : d, t, tg_item, &p);
    if (made > 0 && !tg_dst)
        op_push(made);
}

/* 建具立面の 基準点の釦の字: 押すたびに 左内法→中→右内法、下内法→中→上内法 */
const char *jw_cmd_bar_label(int id)
{
    if (id == 2503 && current == JW_CMD_KIGOU && sk_step == 4) {
        const jw_senkigou *sg = jw_sk_load(sk_cat);

        return sg ? jw_sk_prompt(sg, &sk_run) : 0;
    }
    if (id == 1069 && current == JW_CMD_MOJI && ms_text)
        return jw_moji_sjis() ? "SJIS" : "UTF8";     /* 1092 sits where 文読 was */
    static const char *const h[3] = { "\x8d\xb6\x93\xe0\x96\x40", "\x92\x86", "\x89\x45\x93\xe0\x96\x40" };
    static const char *const v[3] = { "\x89\xba\x93\xe0\x96\x40", "\x92\x86", "\x8f\xe3\x93\xe0\x96\x40" };

    if (!TG_IS3(current))
        return 0;
    if (id == 1065)
        return h[tg_rh];
    if (id == 1066)
        return v[tg_rv];
    return 0;
}

/* 建具立面 (32865).  選んだら 位置（L: free）だけ。内法は「幅 , 高さ」の一つの箱
 * （1426）。基準点は 左内法/中/右内法（1065）と 下内法/中/上内法（1066）。
 * 横反転・縦反転は基準点のまわりの鏡。角度（1430）は基準点のまわりに回す。
 * 原典の答え: tools/probe192.sh、tests/tategu2_test.c の p192_* */
static void tg_place3(jw_drawing *d, double x, double y)
{
    const jw_tategu *t;
    jw_tg_pose p;
    const char *s = jw_cmd_box(1426);
    double w = 1700.0, h = 1700.0, ang;
    char *e;
    int made;

    if (tg_cat < 0 || !d || !(t = jw_tategu_load(tg_cat)))
        return;
    if (s && *s) {
        w = strtod(s, &e);
        if (e == s)
            w = 1700.0;
        h = w;
        while (*e == ' ' || *e == ',' || *e == '	')
            e++;
        if (*e)
            h = strtod(e, 0);
    }
    if (jw_cmd_bar_check(1325) > 0)      /* 縦＝横 */
        h = w;
    ang = box_num(jw_cmd_box(1430), 0.0) * PI / 180.0;
    memset(&p, 0, sizeof p);
    p.uchinori = w;
    p.height = h;
    p.ref_h = tg_rh;
    p.ref_v = tg_rv;
    p.flip_lr = jw_cmd_bar_check(1323) > 0;
    p.flip_io = jw_cmd_bar_check(1324) > 0;
    p.scale = write_scale(d);
    p.ox = x;
    p.oy = y;
    p.ux = cos(ang);
    p.uy = sin(ang);
    made = jw_tategu_put(tg_dst ? tg_dst : d, t, tg_item, &p);
    if (made > 0 && !tg_dst)
        op_push(made);
}


/* ---- 線記号変形 (32869) の置きかた ------------------------------------ */

static void sk_scales(double *sx, double *sy)
{
    const char *s = jw_cmd_box(1431);
    char *e;

    *sx = *sy = 1.0;
    if (s && *s) {
        double v = strtod(s, &e);

        if (e != s) {
            *sx = *sy = v;
            while (*e == ' ' || *e == ',' || *e == '\t')
                e++;
            if (*e)
                *sy = strtod(e, 0);
        }
    }
}

/* 押した線の両端と向き */
static int sk_seg(const jw_drawing *d, int o, double *p0, double *p1,
                  double *dir)
{
    double l;

    if (o < 0 || o >= d->nobj || d->obj[o].cls != JW_SEN)
        return 0;
    p0[0] = d->obj[o].d[0];
    p0[1] = d->obj[o].d[1];
    p1[0] = d->obj[o].d[2];
    p1[1] = d->obj[o].d[3];
    dir[0] = p1[0] - p0[0];
    dir[1] = p1[1] - p0[1];
    l = sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
    if (l < 1e-9)
        return 0;
    dir[0] /= l;
    dir[1] /= l;
    return 1;
}

/* 向き (ux,uy) に沿って小さいほうを始点、大きいほうを終点に */
static void sk_order(const double *p0, const double *p1, double ux, double uy,
                     double *sx, double *sy, double *ex, double *ey)
{
    if (p0[0] * ux + p0[1] * uy <= p1[0] * ux + p1[1] * uy) {
        *sx = p0[0]; *sy = p0[1]; *ex = p1[0]; *ey = p1[1];
    } else {
        *sx = p1[0]; *sy = p1[1]; *ex = p0[0]; *ey = p0[1];
    }
}

/* 11400（寸法）・12930（建具立面）の行まで来たら、そのコマンドに移る */
static void sk_goto_cmd(void)
{
    int c = sk_run.cmd;

    sk_run.cmd = 0;
    if (c == 11400)
        jw_cmd_set(JW_CMD_SUNPO);
    else if (c == 12930)
        jw_cmd_set(JW_CMD_TATEGU_RITSU);
}

/* 一つ置き終えたあと: 10000 の行があればその記号に移る（10000 なら選び直し）。
   移った先に次の指定が無ければ、最初に選んだ記号に戻る */
static void sk_chain(const jw_senkigou *sg)
{
    const jw_sk_item *it = sk_item >= 0 && sk_item < sg->nitem ? &sg->item[sk_item] : 0;

    if (!it)
        return;
    if (it->next == 10000)
        sk_need_pick = 1;
    else if (it->next > 0 && it->next <= sg->nitem)
        sk_item = it->next - 1;
    else if (sk_first >= 0 && sk_first < sg->nitem)
        sk_item = sk_first;
}

/* 押したものから 記号の置き方を決めて置く。置いたら 1 */
static int sk_place(jw_drawing *d)
{
    const jw_senkigou *sg;
    const jw_sk_item *it;
    jw_sk_pose p;
    double a0[2], a1[2], ad[2], b0[2], b1[2], bd[2];
    op_t *o;
    int made, e1 = -1, e2 = -1;

    if (sk_cat < 0 || !d || !(sg = jw_sk_load(sk_cat)) || sk_item < 0 ||
        sk_item >= sg->nitem)
        return 0;
    it = &sg->item[sk_item];
    memset(&p, 0, sizeof p);
    sk_scales(&p.sx, &p.sy);
    p.gscale = write_scale(d);
    p.axis = 0.0;
    if (it->need_l1) {
        double ux, uy;

        if (!sk_seg(d, sk_o1, a0, a1, ad))
            return 0;
        p.have1 = 1;
        p.obj1 = sk_o1;
        p.attr1 = d->obj[sk_o1];
        if (it->need_l2) {
            double det, t, ox, oy;

            if (!sk_seg(d, sk_o2, b0, b1, bd))
                return 0;
            det = ad[0] * bd[1] - ad[1] * bd[0];
            if (fabs(det) < 1e-9)
                return 0;
            t = ((b0[0] - a0[0]) * bd[1] - (b0[1] - a0[1]) * bd[0]) / det;
            ox = a0[0] + ad[0] * t;
            oy = a0[1] + ad[1] * t;
            p.ox = ox;
            p.oy = oy;
            ux = ad[0];
            uy = ad[1];
            if ((ox - sk_c1x) * ux + (oy - sk_c1y) * uy < 0.0) {
                ux = -ux;
                uy = -uy;
            }
            p.u1x = ux;
            p.u1y = uy;
            sk_order(a0, a1, ux, uy, &p.s1x, &p.s1y, &p.e1x, &p.e1y);
            ux = bd[0];
            uy = bd[1];
            if ((sk_c2x - ox) * ux + (sk_c2y - oy) * uy < 0.0) {
                ux = -ux;
                uy = -uy;
            }
            p.u2x = ux;
            p.u2y = uy;
            sk_order(b0, b1, ux, uy, &p.s2x, &p.s2y, &p.e2x, &p.e2y);
            p.have2 = 1;
            p.obj2 = sk_o2;
            p.attr2 = d->obj[sk_o2];
        } else if (it->pointers == 0) {
            /* 線だけ押す: 押したところに近い端が原点、向きは遠い端から近い端へ */
            double d0 = (a0[0] - sk_c1x) * (a0[0] - sk_c1x) + (a0[1] - sk_c1y) * (a0[1] - sk_c1y);
            double d1 = (a1[0] - sk_c1x) * (a1[0] - sk_c1x) + (a1[1] - sk_c1y) * (a1[1] - sk_c1y);
            const double *nr = d0 <= d1 ? a0 : a1, *fr = d0 <= d1 ? a1 : a0;
            double l = sqrt((nr[0] - fr[0]) * (nr[0] - fr[0]) + (nr[1] - fr[1]) * (nr[1] - fr[1]));

            p.ox = nr[0];
            p.oy = nr[1];
            p.u1x = (nr[0] - fr[0]) / l;
            p.u1y = (nr[1] - fr[1]) / l;
            p.s1x = fr[0];
            p.s1y = fr[1];
            p.e1x = nr[0];
            p.e1y = nr[1];
        } else {
            /* 線を押してから位置: 位置の足が原点、押した点から足への向き */
            double t = (sk_px - a0[0]) * ad[0] + (sk_py - a0[1]) * ad[1];
            double side = ad[0] * (sk_py - a0[1]) - ad[1] * (sk_px - a0[0]);

            p.ox = a0[0] + ad[0] * t;
            p.oy = a0[1] + ad[1] * t;
            ux = ad[0];
            uy = ad[1];
            if ((sk_px - sk_c1x) * ux + (sk_py - sk_c1y) * uy < 0.0) {
                ux = -ux;
                uy = -uy;
            }
            if (it->dir75) {
                /* 750・751: 線から位置までの距離が倍率。751 は 位置のほうへ +y が向く */
                p.sx *= fabs(side);
                p.sy *= fabs(side);
                if (it->dir75 == 751) {
                    double nx = side >= 0.0 ? -ad[1] : ad[1];
                    double ny = side >= 0.0 ? ad[0] : -ad[0];

                    ux = ny;
                    uy = -nx;
                }
            }
            p.u1x = ux;
            p.u1y = uy;
            sk_order(a0, a1, ux, uy, &p.s1x, &p.s1y, &p.e1x, &p.e1y);
        }
        e1 = sk_o1;
        e2 = it->need_l2 ? sk_o2 : -1;
    } else {
        p.ox = sk_px;
        p.oy = sk_py;
        p.u1x = 1.0;
        p.u1y = 0.0;
        if (it->mouse) {
            p.have_m = 1;
            p.mx = sk_c1x;
            p.my = sk_c1y;
        }
    }
    if (sk_dst) {                       /* 仮表示: 入力の行の手前まで */
        jw_sk_run tmp;

        made = jw_sk_start(sk_dst, sg, sk_item, &p, &tmp, 0);
        return made > 0;
    }
    o = op_new();
    if (o) {
        /* 消す線は、あとの番号から（前の番号がずれないように） */
        if (e1 >= 0 && e2 >= 0 && e2 > e1) {
            int t = e1;

            e1 = e2;
            e2 = t;
        }
        if (e1 >= 0)
            erase(d, e1, o);
        if (e2 >= 0)
            erase(d, e2, o);
    }
    made = jw_sk_start(d, sg, sk_item, &p, &sk_run, &sk_hist);
    if (o) {
        o->n = made;
        sk_op_at = nop - 1;
    }
    if (sk_run.active) {
        sk_step = 4;                    /* 文字を入力してください */
        line_n = 0;
        line_gen++;
    } else if (made > 0 || e1 >= 0)
        sk_chain(sg);
    sk_goto_cmd();
    return made > 0 || e1 >= 0;
}

/* 建具が 位置を決めるまでカーソルにぶら下がる（仮表示）。置く手前の
   状態（立面は建具を選んだあと、平面・断面は基準線のあと）で、いまのカーソルの
   位置に置いたとおりの要素を作って返す。out は次の呼び出しまで */
int jw_cmd_tategu_preview(const jw_drawing *d, jw_drawing *out)
{
    static jw_drawing pv;
    static int inited;

    int kigou = current == JW_CMD_KIGOU && sk_cat >= 0;

    if (!d || !out || !tracking || (tg_cat < 0 && !kigou))
        return 0;
    if (!kigou && !(TG_IS3(current) || (TG_IS(current) && tg_step == 1)))
        return 0;
    if (!inited) {
        memset(&pv, 0, sizeof pv);
        inited = 1;
    }
    {
        jw_obj *o = pv.obj;
        int c = pv.cobj;
        char *pl = pv.pool;
        int cp = pv.cpool;

        pv = *d;
        pv.obj = o;
        pv.cobj = c;
        pv.pool = pl;
        pv.cpool = cp;
        pv.nobj = pv.ndrawn = 0;
        pv.npool = 0;
    }
    if (kigou) {
        /* 線記号変形: 位置（か 倍率位置）がカーソルにあるとして、置いたとおりに */
        const jw_senkigou *sg = jw_sk_load(sk_cat);
        const jw_sk_item *it = sg && sk_item >= 0 && sk_item < sg->nitem
                               ? &sg->item[sk_item] : 0;
        double spx = sk_px, spy = sk_py, sc1x = sk_c1x, sc1y = sk_c1y;
        int ok = 1;

        if (!it)
            return 0;
        if (sk_step == 0 && !it->need_l1 && !it->mouse) {
            sk_px = tx;
            sk_py = ty;
        } else if (sk_step == 2) {
            sk_px = tx;
            sk_py = ty;
        } else if (sk_step == 3) {
            sk_c1x = tx;
            sk_c1y = ty;
        } else
            ok = 0;
        if (ok) {
            sk_dst = &pv;
            sk_place((jw_drawing *)d);
            sk_dst = 0;
        }
        sk_px = spx;
        sk_py = spy;
        sk_c1x = sc1x;
        sk_c1y = sc1y;
    } else {
        tg_dst = &pv;
        if (TG_IS3(current))
            tg_place3((jw_drawing *)d, tx, ty);
        else
            tg_place((jw_drawing *)d, tx, ty);
        tg_dst = 0;
    }
    if (pv.ndrawn <= 0)
        return 0;
    *out = pv;
    return 1;
}

/* 多角形の n 本を、頂点 v0 から反時計回りに */
static void takaku_put(jw_drawing *d, double cx, double cy, double r,
                       double a0, int n)
{
    int i, made = 0;

    for (i = 0; i < n; i++) {
        double t0 = a0 + 2.0 * PI * i / n, t1 = a0 + 2.0 * PI * (i + 1) / n;
        jw_obj *o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->d[0] = cx + r * cos(t0);
        o->d[1] = cy + r * sin(t0);
        o->d[2] = cx + r * cos(t1);
        o->d[3] = cy + r * sin(t1);
        made++;
    }
    op_push(made);
}

/* 任意 (1070) の 作図 (1069)。`tools/probe170.sh`〜`probe172.sh`:
 * ・線（ソリッド図形が切）: 頂点を順に結び、最後は最初へ戻る
 * ・ソリッド図形: 三点は [A B C A]、四点は [A B C D] の一枚。五点以上は
 *   `tk_solids`（下）経由で `tk_decompose`（src/takaku.c、原典 FUN_007264a0・
 *   八千バイトの写し）に渡す。凸なら **枠 (P1 P2 P(n-1) Pn) の四角を出し、
 *   内側 (P2..P(n-1)) へ同じことを繰り返す**（五点: 四角 (P1 P2 P4 P5) と
 *   三角 (P2 P3 P4 P4)、六点: 四角二枚）。凹み・自己交差があるときは向きを
 *   反時計回りに揃えたうえで、耳（ear）を一つずつ切り落としていく。原典の
 *   答え（p170〜p172）と、凸な五角形・六角形（p172_c5・c5cw・c6、時計回り
 *   も含む）は形も出す順もぴったり一致したが、凹んだ五角形・六角形
 *   （p171_s5・s6）は形は合うものの出す順まで一致しているかは確かめていない。
 *   `tests/takaku_test.c` の `run_any` の `anyorder` がその未確認ぶんのフラグ。*/
static void tk_solid(jw_drawing *d, const double *x, const double *y, int n)
{
    jw_obj *o = jw_add(d, JW_SOLID);
    int i;

    if (!o)
        return;
    for (i = 0; i < 4; i++) {
        int k = i < n ? i : n - 1;

        o->d[i * 2] = x[k];
        o->d[i * 2 + 1] = y[k];
    }
    if (jw_cmd_bar_check(2553) > 0 || jw_cmd_bar_check(1324) > 0) {
        o->color = 10;
        o->n = (int)solid_any;
    }
}

static int tk_solids(jw_drawing *d, const double *x, const double *y, int n)
{
    static double out[1003][8];
    int k, nout = 0;

    tk_decompose(x, y, n, out, &nout);
    for (k = 0; k < nout; k++) {
        double px[4], py[4];
        int i;

        for (i = 0; i < 4; i++) {
            px[i] = out[k][i * 2];
            py[i] = out[k][i * 2 + 1];
        }
        tk_solid(d, px, py, 4);
    }
    return nout;
}

/* 曲線属性化 (1325)。原典 FUN_007254e0: 箱が立っていて、いま作った図形が
 * 二つ以上あれば、まだ誰も使っていない曲線属性の番号（FUN_00479d80: 図面と
 * ブロックの全要素の +4 を印に付け、1 から数えて最初に空いている番号）を
 * 全部の +4 に書く。一つだけなら何もしない。tools/tkprobe.sh の答え
 * tk_s6c（任意の六点、ソリッド三枚）・tk_j5（連続線、二枚）で、何も
 * 無い図面に 1 が付いた。 */
static void tk_curve_attr(jw_drawing *d, int made)
{
    int k, id;

    if (made < 2 || jw_cmd_bar_check(1325) <= 0 || made > d->ndrawn)
        return;
    for (id = 1; id <= 240000; id++) {
        for (k = 0; k < d->nobj; k++)
            if (d->obj[k].id == id && (k < d->ndrawn - made || k >= d->ndrawn))
                break;
        if (k == d->nobj)
            break;
    }
    if (id > 240000)
        return;
    for (k = d->ndrawn - made; k < d->ndrawn; k++)
        d->obj[k].id = id;
}

/* 任意の 円・連続線指示 (1083)。原典の答え decomp/res/p173_*.jww・p174_*.jww:
   円は ソリッド（線種 101、線形・円周 を入れると 111）に、連続線は つながっている線の頂点
   を ソリッドに。(L) は元図形を残し (R) は消す */
static void tk_pick_solid(jw_drawing *d, const jw_view *v, double x, double y, int button)
{
    int i = jw_pick(d, v, x, y, 3), n, k, made = 0, ring = jw_cmd_bar_check(1326) > 0;
    op_t *rec;
    static double vx[TK_ANY_MAX + 1], vy[TK_ANY_MAX + 1];
    static int chain[TK_ANY_MAX + 1];

    if (i < 0)
        return;
    rec = op_new();
    if (d->obj[i].cls == JW_ENKO) {
        /* 原典 FUN_007249c0（_unassigned.c 295642）。円外側 (1328、+0x10a4) で
         * なければ 1 枚: 全円なら末尾 100、弓形 (1327、+0x10a0) なら 5、それ
         * 以外は 0（扇形）。円外側なら末尾 -1 で、開きが 1.5707964267948966
         * 以上の円弧は 1〜4 の最小の m で開き/m がそれ未満になるよう m 等分、
         * 全円は 0・90・180・270° からの 90° 四枚に分ける（それ未満の円弧は
         * そのまま 1 枚）。tools/tkprobe2.sh の答え tk_b2〜b7・j2・j3
         * （decomp/res/）で、弓形・円外側 は 円・連続線指示 (1083) を押した
         * あとでないと enabled にならないことも確かめた。 */
        const jw_obj e = d->obj[i];
        int full = e.d[4] >= 6.283, pieces = 1, outside = !ring
                   && jw_cmd_bar_check(1328) > 0;
        double sw = e.d[4], a0 = e.d[3];

        if (outside && fabs(sw) >= 1.5707964267948966) {
            if (!full && fabs(sw) < 6.283185207179586) {
                for (pieces = 1; pieces < 5; pieces++)
                    if (fabs(sw) / pieces < 1.5707964267948966)
                        break;
                sw /= pieces;
            } else {
                pieces = 4;
                sw = 1.5707963267948966;
                a0 = 0.0;
                full = 2;           /* 始まりは (k-1)·π/2 そのもの */
            }
        }
        for (k = 0; k < pieces; k++) {
            jw_obj *o = jw_add(d, JW_SOLID);

            if (!o)
                break;
            o->ltype = ring ? 111 : 101;
            o->d[0] = e.d[0];
            o->d[1] = e.d[1];
            o->d[2] = e.d[2];
            o->d[3] = e.d[6] > 0.0 ? e.d[6] : 1.0;
            o->d[4] = e.d[5];
            o->d[5] = full == 2 ? k * 1.5707963267948966 : a0 + k * sw;
            o->d[6] = sw;
            o->d[7] = outside ? -1.0 : full ? 100.0
                    : jw_cmd_bar_check(1327) > 0 ? 5.0 : 0.0;
            made++;
        }
        /* 曲線属性化 は (R) の受け手（CZukeiTakakukei.c 1447、FUN_007249c0 の
           第 4 引数 1 = 元の円を消す方）のあとでだけ FUN_007254e0 を呼ぶ */
        if (button == 1)
            tk_curve_attr(d, made);
        if (button == 1)
            erase(d, i, rec), made++;
    } else if (d->obj[i].cls == JW_SEN) {
        int used = 0, a, again = 1;
        double ex, ey, sx, sy;

        /* つながっている線を 両端へ たどる（端点が同じ線） */
        n = 0;
        chain[n++] = i;
        sx = d->obj[i].d[0]; sy = d->obj[i].d[1];
        ex = d->obj[i].d[2]; ey = d->obj[i].d[3];
        (void)used;
        while (again) {
            again = 0;
            for (a = 0; a < d->ndrawn && n < TK_ANY_MAX; a++) {
                const jw_obj *l = &d->obj[a];
                int in = 0;

                if (l->cls != JW_SEN)
                    continue;
                for (k = 0; k < n; k++)
                    if (chain[k] == a)
                        in = 1;
                if (in)
                    continue;
                if (fabs(l->d[0] - ex) < 1e-6 && fabs(l->d[1] - ey) < 1e-6) {
                    chain[n++] = a; ex = l->d[2]; ey = l->d[3]; again = 1;
                } else if (fabs(l->d[2] - ex) < 1e-6 && fabs(l->d[3] - ey) < 1e-6) {
                    chain[n++] = a; ex = l->d[0]; ey = l->d[1]; again = 1;
                } else if (fabs(l->d[2] - sx) < 1e-6 && fabs(l->d[3] - sy) < 1e-6) {
                    memmove(chain + 1, chain, (size_t)n * sizeof chain[0]);
                    chain[0] = a; n++; sx = l->d[0]; sy = l->d[1]; again = 1;
                } else if (fabs(l->d[0] - sx) < 1e-6 && fabs(l->d[1] - sy) < 1e-6) {
                    memmove(chain + 1, chain, (size_t)n * sizeof chain[0]);
                    chain[0] = a; n++; sx = l->d[2]; sy = l->d[3]; again = 1;
                }
            }
        }
        /* 押した点から遠い方の端から 順にたどる（原典 p174_q1・p1）。線の向きもそれに揃える */
        {
            double da = hypot(sx - x, sy - y), db = hypot(ex - x, ey - y);

            if (db > da) {
                double tx = sx, ty = sy;
                int lo, hi;

                sx = ex; sy = ey;
                ex = tx; ey = ty;
                for (lo = 0, hi = n - 1; lo < hi; lo++, hi--) {
                    int tc = chain[lo];

                    chain[lo] = chain[hi];
                    chain[hi] = tc;
                }
            }
        }
        /* 頂点: 始点から 順に */
        {
            int m = 0;
            double cx = sx, cy = sy;

            vx[m] = cx; vy[m] = cy; m++;
            for (k = 0; k < n; k++) {
                jw_obj *l = &d->obj[chain[k]];

                if (fabs(l->d[0] - cx) < 1e-6 && fabs(l->d[1] - cy) < 1e-6) {
                    cx = l->d[2]; cy = l->d[3];
                } else {
                    double t0 = l->d[0], t1 = l->d[1];

                    cx = l->d[0]; cy = l->d[1];
                    l->d[0] = l->d[2]; l->d[1] = l->d[3];     /* 向きを揃える */
                    l->d[2] = t0; l->d[3] = t1;
                }
                vx[m] = cx; vy[m] = cy; m++;
            }
            if (ring) {
                for (k = 0; k + 1 < m; k++) {
                    double px[2], py[2];
                    jw_obj *o = jw_add(d, JW_SOLID);

                    px[0] = vx[k]; py[0] = vy[k];
                    px[1] = vx[k + 1]; py[1] = vy[k + 1];
                    if (!o)
                        break;
                    o->d[0] = px[0]; o->d[1] = py[0];
                    o->d[2] = px[1]; o->d[3] = py[1];
                    o->d[4] = o->d[6] = px[1];
                    o->d[5] = o->d[7] = py[1];
                    made++;
                }
            } else {
                if (m <= 4) {       /* 三角・四角は そのまま（原典 p174_p1）。五つ以上は 未確認 */
                    tk_solid(d, vx, vy, m);
                    made = 1;
                } else
                    made = tk_solids(d, vx, vy, m);
            }
            /* 曲線属性化 (1325): 原典 p174_q4・tk_j5（五点の連続線、(L)）で
               二枚のソリッドに、tk_j9（線形 1326 と一緒）で四本の線形
               ソリッドに曲線属性 1 が付いた。連続線は (L) でも付く */
            tk_curve_attr(d, made);
        }
        if (button == 1) {
            /* 大きい番号から 消す */
            for (a = 0; a < n; a++) {
                int hi = a;

                for (k = a + 1; k < n; k++)
                    if (chain[k] > chain[hi])
                        hi = k;
                k = chain[a]; chain[a] = chain[hi]; chain[hi] = k;
            }
            for (a = 0; a < n; a++)
                erase(d, chain[a], rec), made++;
        }
    }
    if (rec)
        rec->n = made;
    if (made)
        op_push(made);
}

static void takaku_any(jw_drawing *d)
{
    int i, made = 0;

    if (jw_cmd_bar_check(1323) > 0) {
        made = tk_solids(d, tk_ax2, tk_ay2, tk_an);
        tk_curve_attr(d, made);     /* FUN_007255f0 → FUN_007254e0(DAT_00a0cac0) */
    } else {
        for (i = 0; i < tk_an; i++) {
            int j = (i + 1) % tk_an;
            jw_obj *o = jw_add(d, JW_SEN);

            if (!o)
                break;
            o->d[0] = tk_ax2[i];
            o->d[1] = tk_ay2[i];
            o->d[2] = tk_ax2[j];
            o->d[3] = tk_ay2[j];
            made++;
        }
    }
    if (made)
        op_push(made);
    tk_an = 0;
}

/* ２辺 (1689): 二点が底辺で、箱の「横 , 縦」がその両端から頂点までの
 * 長さ。頂点は三点目のある側に立ちます。`tools/probe167.sh`・
 * `probe168.sh` と CZukeiTakakukei slot 9 の FUN_007287b0 から:
 * 長さのどちらかが 0 以下（空も）なら、長さは三点目から両端までの
 * 距離を取り、頂点は三点目そのものになります。引くのは **底辺ではなく**
 * 両端から頂点への 二本 だけで、解けなければ（|a²-t²| が 1e-6 未満・
 * 底辺が 0）何も引かずに最初の点へ戻ります。 */
static void takaku2(jw_drawing *d, double x, double y)
{
    double ax, ay, bx, by, a, b, dx, dy, dl, t, h2, px, py;
    const char *t1 = jw_cmd_box(1412);
    const char *p;
    jw_obj *o;
    int made = 0;

    tk2_x[tk2_n] = x;
    tk2_y[tk2_n] = y;
    tk2_n++;
    if (tk2_n < 3)
        return;
    tk2_n = 0;
    ax = tk2_x[0];
    ay = tk2_y[0];
    bx = tk2_x[1];
    by = tk2_y[1];
    dx = bx - ax;
    dy = by - ay;
    dl = sqrt(dx * dx + dy * dy);
    if (dl <= 1e-7)
        return;
    a = box_mm(d, 1412);
    p = t1 ? strchr(t1, ',') : 0;
    b = p && p[1] ? box_mm2(d, 1412) : a;
    if (a <= 1e-7 || b <= 1e-7) {
        a = sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay));
        b = sqrt((x - bx) * (x - bx) + (y - by) * (y - by));
    }
    t = (a * a + dl * dl - b * b) / (2.0 * dl);
    h2 = a * a - t * t;
    if (h2 < 1e-6)
        return;
    {
        double h = sqrt(h2);
        double ux = dx / dl, uy = dy / dl;
        double side = ux * (y - ay) - uy * (x - ax);    /* 三点目はどちら側か */

        if (side < 0.0)
            h = -h;
        px = ax + ux * t - uy * h;
        py = ay + uy * t + ux * h;
    }
    o = jw_add(d, JW_SEN);
    if (o) {
        o->d[0] = ax;
        o->d[1] = ay;
        o->d[2] = px;
        o->d[3] = py;
        made++;
    }
    o = jw_add(d, JW_SEN);
    if (o) {
        o->d[0] = bx;
        o->d[1] = by;
        o->d[2] = px;
        o->d[3] = py;
        made++;
    }
    if (made)
        op_push(made);
}

static void takaku(jw_drawing *d, double cx, double cy)
{
    const char *sz = jw_cmd_box(1411), *ns = jw_cmd_box(1413);
    const char *ang = jw_cmd_box(1414);
    double r = box_num(sz, 0.0), a0 = box_num(ang, 0.0);
    int n = ns ? atoi(ns) : 0, i, wg = 0;

    if (tk_any) {
        /* 同じ点をもう一度は受けない（FUN_00498960 の比べ） */
        for (i = 0; i < tk_an; i++)
            if (tk_ax2[i] == cx && tk_ay2[i] == cy)
                return;
        tx = cx;
        ty = cy;
        tracking = 1;
        if (tk_an < TK_ANY_MAX) {
            tk_ax2[tk_an] = cx;
            tk_ay2[tk_an] = cy;
            tk_an++;
        }
        return;
    }
    if (tk_mode == 1689) {
        takaku2(d, cx, cy);
        return;
    }
    if (n < 3 || n > 1000)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (r <= 0.0) {
        /* 寸法が空: 二点で決めます（`tools/probe165.sh`）。一点目を取り、
         * 二点目で一つ作って一点目に戻ります。三点目は要りません。
         *  1690  一点目が中心、二点目が頂点（そこから反時計回り）
         *  1691  一点目が中心、二点目が辺の真ん中（頂点はその両側 ±180/n）
         *  1692  一点目→二点目が一辺で、多角形はその左側
         * 底辺角度・中央 (1068) はここでは効きません。 */
        if (tk_step == 0) {
            tk_ax = cx;
            tk_ay = cy;
            tk_step = 1;
            return;
        }
        {
            double dx = cx - tk_ax, dy = cy - tk_ay;
            double len = sqrt(dx * dx + dy * dy), th = atan2(dy, dx);

            tk_step = 0;
            if (len <= 0.0)
                return;
            if (tk_mode == 1691) {
                takaku_put(d, tk_ax, tk_ay, len / cos(PI / n),
                           th - PI / n, n);
            } else if (tk_mode == 1692) {
                double ap = len / (2.0 * tan(PI / n));
                double mx = tk_ax + dx / 2.0 - dy / len * ap;
                double my = tk_ay + dy / 2.0 + dx / len * ap;

                takaku_put(d, mx, my, len / (2.0 * sin(PI / n)),
                           atan2(tk_ay - my, tk_ax - mx), n);
            } else {
                takaku_put(d, tk_ax, tk_ay, len, th, n);
            }
        }
        return;
    }
    if (d->group[wg].scale > 0.0)
        r /= d->group[wg].scale;
    /* 箱の数が何を指すかは左の四択しだい（上の tk_mode の注） */
    if (tk_mode == 1691)
        r /= cos(PI / n);               /* 内接半径 → 外接半径 */
    else if (tk_mode == 1692)
        r /= 2.0 * sin(PI / n);         /* 辺の長さ → 外接半径 */
    a0 = (a0 - 90.0 - 180.0 / n) * PI / 180.0;
    /* 中央 (1068) は押すたびに 中央 → 頂点 → 辺 と回り（ボタンの字は
     * 文字列 5469・5470・5471）、クリックが多角形の どこ にあたるかを
     * 変えます。頂点 は最初の頂点（底辺はそこから右へ）、辺 は底辺の
     * 真ん中。原典の答えは `decomp/res/p165_*_c.jww`・`p166_k*.jww`
     * （`tools/probe165.sh`・`probe166.sh`）。寸法が空の二点指定には
     * 効きません。 */
    if (tk_pos == 1) {
        cx -= r * cos(a0);
        cy -= r * sin(a0);
    } else if (tk_pos == 2) {
        /* 辺: クリックが底辺（v0→v1）の真ん中 */
        double am = a0 + PI / n, ap = r * cos(PI / n);

        cx -= ap * cos(am);
        cy -= ap * sin(am);
    }
    takaku_put(d, cx, cy, r, a0, n);
}

/* The number a dimension is written with.
 *
 * The length is in paper millimetres; what goes on the drawing is the real
 * length, which is that times the scale of the layer group it is on -- the
 * original measured 346.3557 mm on a 1/200 group and wrote 69,271.14.
 * Then SHOUSUUKETA decimals, a comma every three digits if ShowComma, and
 * with ShowZero off the trailing zeros of the fraction go. */
static void sunpo_text(char *out, int n, double mm, double scale)
{
    char buf[64], *p = buf;
    double v = mm * scale;
    int i, len, k, neg = v < 0.0, whole;

    if (neg)
        v = -v;
    /* mm and scale both come from the drawing, so v can be enormous and
       "%f" spells it out in full */
    snprintf(buf, sizeof buf, "%.*f", sun_decimals(), v);
    if (sun_decimals() > 0 && !JW_SUN_ZERO) {
        char *dot = strchr(buf, '.');
        if (dot) {
            char *e = buf + strlen(buf);
            while (e > dot && e[-1] == '0')
                *--e = 0;
            if (e == dot + 1)
                *dot = 0;
        }
    }
    len = (int)strlen(p);
    whole = (int)(strchr(p, '.') ? strchr(p, '.') - p : len);
    k = 0;
    if (neg && k < n - 1)
        out[k++] = '-';
    for (i = 0; i < len && k < n - 1; i++) {
        if (JW_SUN_COMMA && i && i < whole && (whole - i) % 3 == 0)
            out[k++] = ',';
        if (k < n - 1)
            out[k++] = p[i];
    }
    out[k] = 0;
}

/* Put the six elements of one dimension in the drawing. */
/* 寸法 の 半径 (1065): one click on a circle.
 *
 * Read off the original: a line from the centre out to the point clicked,
 * the value with an R in front of it half a millimetre above the middle of
 * that line, and a point at each end -- four elements, in that order.  The
 * text carries 0x4110 where an ordinary dimension value has 0x4010, and its
 * width word is (places << 12) | 0x443 where the ordinary one has 0x043.
 * A circle of 86.588921 on a 1/200 group came out as R17,317.78.
 */
static void sunpo_radius(jw_drawing *d, const jw_view *v, double x, double y)
{
    int i = jw_pick(d, v, x, y, 6), wg = 0, k, si;
    double cx, cy, r, dx, dy, len, ux, uy, ex, ey;
    double cw, ch, sp, tw = 0.0;
    char txt[72], val[64];
    const char *p;
    jw_obj *o;
    int nch = 0;

    if (i < 0 || d->obj[i].cls != JW_ENKO)
        return;
    cx = d->obj[i].d[0];
    cy = d->obj[i].d[1];
    r = d->obj[i].d[2];
    if (r <= 0.0)
        return;
    dx = x - cx;
    dy = y - cy;
    len = sqrt(dx * dx + dy * dy);
    if (len <= 0.0) {
        ux = 1.0;
        uy = 0.0;
    } else {
        ux = dx / len;
        uy = dy / len;
    }
    ex = cx + r * ux;
    ey = cy + r * uy;
    /* 直径 runs right across, from the far side to the point clicked */
    if (sun_radius == 2) {
        cx -= r * ux;
        cy -= r * uy;
    }

    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->color = sun_sencol;
    o->ltype = 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = ex;
    o->d[3] = ey;

    for (k = 0; k < 16; k++)
        if (d->group[k].state == 3)
            wg = k;
    si = sun_mojino - 1;
    if (si < 0 || si >= 10)
        si = 0;
    cw = d->style[si].w;
    ch = d->style[si].h;
    sp = d->style[si].sp;
    sunpo_text(val, (int)sizeof val, sun_radius == 2 ? r * 2.0 : r,
               d->group[wg].scale);
    /* the mark in front: R, or the CP932 phi the original writes (83 d3) */
    snprintf(txt, sizeof txt, "%s%s",
             sun_radius == 2 ? "\x83\xd3" : "R", val);
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    if (cw > 0.0 && ch > 0.0 && nch) {
        double mx = (cx + ex) / 2.0 - uy * sun_hanare;
        double my = (cy + ey) / 2.0 + ux * sun_hanare;
        /* cx,cy is the line's far end by now, so this is its middle */
        o = jw_add(d, JW_MOJI);
        if (o) {
            o->color = (unsigned short)d->style[si].color;
            o->ltype = 2;
            o->width = (unsigned short)((sun_decimals() << 12) | 0x0443u);
            o->flags = (unsigned short)(o->flags | JW_SUN_TEXT_FLAGS
                                       | (sun_radius == 2 ? 0x0200u : 0x0100u));
            o->d[0] = mx - tw / 2.0 * ux;
            o->d[1] = my - tw / 2.0 * uy;
            o->d[2] = mx + tw / 2.0 * ux;
            o->d[3] = my + tw / 2.0 * uy;
            o->d[4] = cw;
            o->d[5] = ch;
            o->d[6] = sp;
            o->d[7] = 0.0;
            o->n = sun_mojino;
            o->text = jw_add_str(d, txt);
            o->face = jw_add_str(d, JW_MOJI_FACE);
        }
    }
    for (k = 0; k < 2; k++) {
        o = jw_add(d, JW_TEN);
        if (!o)
            break;
        o->color = sun_tencol;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
        o->d[0] = k ? ex : cx;
        o->d[1] = k ? ey : cy;
        o->n = 0;
    }
    op_push(4);
    /* so jw_cmd_esc_key can tell "never drawn one yet" (Esc drops 半径／
       直径 back to the plain two-point kind) from "already have" (Esc then
       does nothing, same as the original -- RESUME.md 2026-10-13).  Not
       sun_made: that one also feeds the base/角度/円周 "次へ" prompt, which
       半径／直径 does not show (a pre-existing gap, not this one's to
       fix). sun_step itself stays 2 throughout, made or not. */
    sun_radius_made = 1;
}

/* 寸法値 (1069): the value on its own, between the two points given. */
static int sunpo_value_obj(jw_drawing *d, double x0, double y0,
                           double x1, double y1);

static void sunpo_value(jw_drawing *d, double x0, double y0,
                        double x1, double y1)
{
    if (sunpo_value_obj(d, x0, y0, x1, y1))
        op_push(1);
}

/* 線記号変形の 寸法値記入コード (14***) が使う: 二点の間の寸法値を置く */
int jw_cmd_dim_text(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    return sunpo_value_obj(d, x0, y0, x1, y1);
}

static int sunpo_value_obj(jw_drawing *d, double x0, double y0,
                           double x1, double y1)
{
    double dx = x1 - x0, dy = y1 - y0, len = sqrt(dx * dx + dy * dy);
    double ux, uy, vx, vy, cw, ch, sp, tw = 0.0, mx, my;
    char txt[64];
    const char *p;
    int i, wg = 0, nch = 0;
    jw_obj *o;

    if (len <= 0.0)
        return 0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    i = sun_mojino - 1;
    if (i < 0 || i > 9)
        i = 0;
    cw = d->style[i].w;
    ch = d->style[i].h;
    sp = d->style[i].sp;
    sunpo_text(txt, (int)sizeof txt, len, d->group[wg].scale);
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    if (cw <= 0.0 || ch <= 0.0 || !nch)
        return 0;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    mx = (x0 + x1) / 2.0 + sun_hanare * vx;
    my = (y0 + y1) / 2.0 + sun_hanare * vy;
    o = jw_add(d, JW_MOJI);
    if (!o)
        return 0;
    o->color = (unsigned short)d->style[i].color;
    o->ltype = 2;
    o->width = (unsigned short)((sun_decimals() << 12)
                                | (JW_SUN_TEXT_WIDTH & 0x0fffu));
    o->flags = (unsigned short)(o->flags | JW_SUN_TEXT_FLAGS);
    o->d[0] = mx - tw / 2.0 * ux;
    o->d[1] = my - tw / 2.0 * uy;
    o->d[2] = mx + tw / 2.0 * ux;
    o->d[3] = my + tw / 2.0 * uy;
    o->d[4] = cw;
    o->d[5] = ch;
    o->d[6] = sp;
    o->d[7] = 0.0;
    o->n = sun_mojino;
    o->text = jw_add_str(d, txt);
    o->face = jw_add_str(d, JW_MOJI_FACE);
    return 1;
}

/* 角度 (1068): the angle between two directions about an origin.
 *
 * Read off the original's own drawing.  Given the origin, a point for the
 * extension lines to start at, a point on the arc, and then the two
 * directions read off a rectangle's corners, it wrote, in this order:
 *
 *   the value, D°MM'SS" with a half width 0xdf for the degree sign,
 *              centred on the middle of the sweep at the arc's radius plus
 *              はなれ, its baseline along the tangent there
 *   the arc,   about the origin, from the first direction round to the
 *              second the long way -- 0 to 270, not 90 back
 *   a 点 at each end of it, as 端部 asks
 *   an 引出線 along each direction, from the radius the first click gave
 *              in to the arc
 */
static void sunpo_angle(jw_drawing *d, double bx, double by)
{
    double r1 = sqrt((sun_hx - sun_ox) * (sun_hx - sun_ox)
                     + (sun_hy - sun_oy) * (sun_hy - sun_oy));
    double r2 = sqrt((sun_lx - sun_ox) * (sun_lx - sun_ox)
                     + (sun_ly - sun_oy) * (sun_ly - sun_oy));
    double a0 = atan2(sun_sy - sun_oy, sun_sx - sun_ox);
    double a1 = atan2(by - sun_oy, bx - sun_ox);
    double sweep = a1 - a0;
    double cw, ch, sp, tw = 0.0, mid, deg;
    char txt[64];
    const char *p;
    int nch = 0, i, made = 0, sec;
    jw_obj *o;

    if (r2 <= 0.0)
        return;
    while (sweep < 0.0)
        sweep += 2.0 * PI;
    while (sweep >= 2.0 * PI)
        sweep -= 2.0 * PI;
    if (sweep <= 0.0)
        return;

    if (sun_enshu) {
        /* 円周: the length of that much of the circle, in real units */
        int wg = 0;
        for (i = 0; i < 16; i++)
            if (d->group[i].state == 3)
                wg = i;
        sunpo_text(txt, (int)sizeof txt, sun_er * sweep, d->group[wg].scale);
    } else {
        /* 角度: the value in degrees, minutes and seconds */
        deg = sweep * 180.0 / PI;
        sec = (int)(deg * 3600.0 + 0.5);
        sprintf(txt, "%d\xdf%02d'%02d\"", sec / 3600, (sec / 60) % 60,
                sec % 60);
    }

    i = sun_mojino - 1;
    if (i < 0 || i > 9)
        i = 0;
    cw = d->style[i].w;
    ch = d->style[i].h;
    sp = d->style[i].sp;
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    mid = a0 + sweep / 2.0;
    if (cw > 0.0 && ch > 0.0 && nch) {
        double px = sun_ox + (r2 + sun_hanare) * cos(mid);
        double py = sun_oy + (r2 + sun_hanare) * sin(mid);
        double tx = cos(mid - PI / 2.0), ty = sin(mid - PI / 2.0);
        o = jw_add(d, JW_MOJI);
        if (o) {
            o->color = (unsigned short)d->style[i].color;
            o->ltype = 2;
            o->width = 0;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEXT_FLAGS
                                       | (sun_enshu ? 0u : 0x0400u));
            o->d[0] = px - tw / 2.0 * tx;
            o->d[1] = py - tw / 2.0 * ty;
            o->d[2] = px + tw / 2.0 * tx;
            o->d[3] = py + tw / 2.0 * ty;
            o->d[4] = cw;
            o->d[5] = ch;
            o->d[6] = sp;
            o->d[7] = 0.0;
            o->n = sun_mojino;
            o->text = jw_add_str(d, txt);
            o->face = jw_add_str(d, JW_MOJI_FACE);
            made++;
        }
    }

    /* the arc */
    o = jw_add(d, JW_ENKO);
    if (!o)
        return;
    o->color = sun_sencol;
    o->ltype = 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
    o->d[0] = sun_ox;
    o->d[1] = sun_oy;
    o->d[2] = r2;
    o->d[3] = a0 < 0.0 ? a0 + 2.0 * PI : a0;
    o->d[4] = sweep;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    o->n = 0;
    made++;

    /* 端部 at each end of it */
    for (i = 0; i < 2; i++) {
        double a = i ? a0 + sweep : a0;
        o = jw_add(d, JW_TEN);
        if (!o)
            break;
        o->color = sun_tencol;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
        o->d[0] = sun_ox + r2 * cos(a);
        o->d[1] = sun_oy + r2 * sin(a);
        o->n = 0;
        made++;
    }

    /* an 引出線 along each direction, from r1 in to the arc */
    for (i = 0; i < 2; i++) {
        double a = i ? a0 + sweep : a0;
        o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->color = sun_hikicol;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
        o->d[0] = sun_ox + r1 * cos(a);
        o->d[1] = sun_oy + r1 * sin(a);
        o->d[2] = sun_ox + r2 * cos(a);
        o->d[3] = sun_oy + r2 * sin(a);
        made++;
    }
    op_push(made);
}

static void sunpo_make(jw_drawing *d, double bx, double by)
{
    double a = sun_angle() * PI / 180.0;
    double ux = cos(a), uy = sin(a), vx = -uy, vy = ux;
    /* along the dimension's own direction, and across it */
    double s0 = sun_sx * ux + sun_sy * uy, s1 = bx * ux + by * uy;
    double tl = sun_lx * vx + sun_ly * vy;      /* the dimension line       */
    double th = sun_hx * vx + sun_hy * vy;      /* where the extensions end */
    double x0 = s0 * ux + tl * vx, y0 = s0 * uy + tl * vy;
    double x1 = s1 * ux + tl * vx, y1 = s1 * uy + tl * vy;
    double len = s1 > s0 ? s1 - s0 : s0 - s1;
    double cw, ch, sp, tw = 0.0;
    char txt[64];
    const char *p;
    int nch = 0, i, wg = 0, made = 0;
    jw_obj *o;

    if (len <= 0.0)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;

    /* 寸法線 */
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->color = sun_sencol;
    o->ltype = 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    made++;

    /* 端部 (1062) -- a point at each end, or an arrowhead.
     *
     * The original, with the button pressed once, put two lines at each tip
     * instead of the point: 3 long at 15 degrees either side of the line,
     * pointing inwards, written +15 then -15 at each end.  Those are the
     * ARROW_LEN and ARROW_ANG the settings carry. */
    if (sun_prog) {
        /* 累進: the original put a 点 on the base end and an arrowhead on
           the far one, whatever 端部 is set to -- read off its own drawing */
        o = jw_add(d, JW_TEN);
        if (o) {
            o->color = sun_tencol;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
            o->d[0] = x0;
            o->d[1] = y0;
            o->n = 0;
            made++;
        }
        {
            double wx = x0 - x1, wy = y0 - y1;
            double wl = sqrt(wx * wx + wy * wy), k;
            if (wl > 0.0) {
                wx /= wl;
                wy /= wl;
                for (k = 1.0; k >= -1.0; k -= 2.0) {
                    double aa = k * sun_yaang * PI / 180.0;
                    double ca = cos(aa), sa = sin(aa);
                    o = jw_add(d, JW_SEN);
                    if (!o)
                        break;
                    o->ltype = 1;
                    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
                    o->d[0] = x1;
                    o->d[1] = y1;
                    o->d[2] = x1 + sun_yalen * (wx * ca - wy * sa);
                    o->d[3] = y1 + sun_yalen * (wx * sa + wy * ca);
                    made++;
                }
            }
        }
    } else if (!sun_arrows()) {
        for (i = 0; i < 2; i++) {
            o = jw_add(d, JW_TEN);
            if (!o)
                break;
            o->color = sun_tencol;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
            o->d[0] = i ? x1 : x0;
            o->d[1] = i ? y1 : y0;
            o->n = 0;
            made++;
        }
    } else {
        double alen = sun_yalen;
        double aang = sun_yaang * PI / 180.0;
        for (i = 0; i < 2; i++) {
            double tipx = i ? x1 : x0, tipy = i ? y1 : y0;
            double wx = (i ? x0 - x1 : x1 - x0);
            double wy = (i ? y0 - y1 : y1 - y0);
            double wl = sqrt(wx * wx + wy * wy), k;
            if (wl <= 0.0)
                break;
            wx /= wl;
            wy /= wl;
            for (k = 1.0; k >= -1.0; k -= 2.0) {
                double ca = cos(k * aang), sa = sin(k * aang);
                o = jw_add(d, JW_SEN);
                if (!o)
                    break;
                o->ltype = 1;
                o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
                o->d[0] = tipx;
                o->d[1] = tipy;
                o->d[2] = tipx + alen * (wx * ca - wy * sa);
                o->d[3] = tipy + alen * (wx * sa + wy * ca);
                made++;
            }
        }
    }

    /* 引出線 -- from the dimension line out to where the first click was.
     *
     * None is written when it would have no length.  The original, asked to
     * dimension the height of a rectangle with ０º/９０º on, kept the line
     * position from the width dimension before it -- both of those clicks
     * were at the same place across the new direction -- and wrote the
     * dimension line, the two points and the value with no extensions at
     * all. */
    for (i = 0; th != tl + sun_tsuki && i < 2; i++) {
        double s = i ? s1 : s0;
        o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->color = sun_hikicol;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
        o->d[0] = s * ux + (tl + sun_tsuki) * vx;
        o->d[1] = s * uy + (tl + sun_tsuki) * vy;
        o->d[2] = s * ux + th * vx;
        o->d[3] = s * uy + th * vy;
        made++;
    }

    /* 寸法値 -- 文字種 MOJINO, centred on the line and HANARE above it */
    i = sun_mojino - 1;
    if (i < 0 || i > 9)
        i = 0;
    cw = d->style[i].w;
    ch = d->style[i].h;
    sp = d->style[i].sp;
    sunpo_text(txt, (int)sizeof txt, len, d->group[wg].scale);
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    if (cw > 0.0 && ch > 0.0 && nch) {
        double mid = (s0 + s1) / 2.0, t = tl + sun_hanare;
        o = jw_add(d, JW_MOJI);
        if (o) {
            o->color = (unsigned short)d->style[i].color;
            /* an ordinary text has 1 here; the dimension value the original
               wrote has 2, and 0x2043 in the word at +0x2c */
            o->ltype = 2;
            o->width = (unsigned short)((sun_decimals() << 12)
                                       | (JW_SUN_TEXT_WIDTH & 0x0fffu));
            o->flags = (unsigned short)(o->flags | JW_SUN_TEXT_FLAGS);
            if (sun_prog) {
                /* 累進: stood on end at the far tip.  The original wrote
                   it half a millimetre back along the line from that tip and
                   half a millimetre off it, running across rather than
                   along, with an ordinary text's 1 at +0x28 and the upright
                   bit in the flags. */
                double px = (s1 - sun_hanare) * ux + t * vx;
                double py = (s1 - sun_hanare) * uy + t * vy;
                o->ltype = 1;
                o->flags = (unsigned short)(o->flags | 0x1000u);
                o->d[0] = px;
                o->d[1] = py;
                o->d[2] = px + tw * vx;
                o->d[3] = py + tw * vy;
            } else {
            o->d[0] = (mid - tw / 2.0) * ux + t * vx;
            o->d[1] = (mid - tw / 2.0) * uy + t * vy;
            o->d[2] = (mid + tw / 2.0) * ux + t * vx;
            o->d[3] = (mid + tw / 2.0) * uy + t * vy;
            }
            o->d[4] = cw;
            o->d[5] = ch;
            o->d[6] = sp;
            o->d[7] = 0.0;
            o->n = sun_mojino;
            o->text = jw_add_str(d, txt);
            /* the original's own dimension value carries the font name like
               any other text (decomp/res/sunpo.jww); leaving it out made a
               drawing the original quietly filled in on the next save */
            o->face = jw_add_str(d, JW_MOJI_FACE);
            made++;
        }
    }
    ika_live = 1;               /* 一括処理 wakes up once one dimension is in */
    op_push(made);
}

/* 寸法の一括処理 (1072) -- a row of lines dimensioned in one press.
 *
 * Measured, not invented: tools/probe38.sh .. probe42.sh, with the
 * answers in decomp/res/sunikkatsu.jww, sunikkatsu2.jww and the two runs
 * of tools/mkikkatsu.c's band drawing.
 *
 *   what wakes it up   only a dimension already drawn.  Pressing every
 *                      other button on the bar left it dead; drawing one
 *                      dimension brought it to life (its style went from
 *                      58010f00 to 50010f00).  実行 (1120) never woke at
 *                      all, so what that one is for is still not known.
 *   what it asks for   5391 the 始線, 5392 the 終線, 5393 the ones to add
 *                      or drop -- and (R) at that third prompt draws.
 *   which lines        **the ones the segment between the two clicks
 *                      crosses.**  Five verticals whose tops stood at 20,
 *                      19, 15, 10 and 0 were offered to it twice: with
 *                      the two clicks at sheet y=14.08 the first three
 *                      came out, and with them at y=7.96 the first four
 *                      did.  The wall they all stand on, which the
 *                      segment runs along and so never crosses, came out
 *                      neither time.
 *   which point of it  **the end nearer the dimension line**, and not
 *                      where the segment crossed: a diagonal from
 *                      (0,-20) to (20,20), crossed at x=17.04, came out
 *                      dimensioned at x=20.
 *   what it writes     per gap: the 寸法線, then a 点 at each end that
 *                      has none, then an 引出線 at each of those same
 *                      ends, then the value -- sunpo_make's own order.
 *                      Usually only the far end is new, so it comes out
 *                      寸法線, 点, 引出線, 値; both ends are new on the
 *                      first gap of a row that does not begin where the
 *                      hand-drawn dimension did, and the original writes
 *                      both there (tools/probe55.sh).
 *   where              that dimension's line position and extension
 *                      length, so the row carries straight on from it.
 *
 * The third prompt's (L) **turns the line it hits over**: one that is
 * not in the row comes in, one that is in goes out (tools/probe50.sh).
 * The same walk was run three times over the band drawing -- once with
 * a click on the line at x=70, which the segment misses, once with a
 * click on the one at x=-70, which it crosses, and once with both.  The
 * first came out with 70 in the row, the second with -70 gone, the
 * third with both changes.  So it is a toggle, and that is measured.
 *
 * (R) at either of the first two prompts is 同一線種選択, and what it
 * does is **narrow the row to one line type** (tools/probe55.sh).  The
 * band drawing was given 点線1 at -70, -35 and 10 and left on 実線
 * everywhere else, and the same walk run four ways:
 *
 *   (L) both ends   -100 -70 -55 -35 -20 10 40 100   -- all nine
 *   (R) on a 実線   -100 -55 -20 40 100              -- the 実線 only
 *   (R) on a 点線    -70 -35 10                      -- the 点線 only
 *   (L) then (R)    -100 -55 -20 40 100              -- one (R) is enough
 *
 * so it is the type of the line the (R) lands on that decides, and one
 * (R) sets it for the whole row.  The walk goes on to the next prompt
 * either way.
 */
#define IKA_MAX 512

static double ika_s0, ika_s1;   /* the 始線 and 終線 along the dimension  */
static double ika_ax, ika_ay;   /* where the 始線 was clicked           */
static double ika_bx, ika_by;   /* and the 終線                        */

/* Where the segment a-b crosses o, if it does: the answer is o's own end
 * nearer the dimension line, which is the one the original measures. */
static int ika_hit(const jw_obj *o, double ax, double ay,
                   double bx, double by, double vx, double vy, double tl,
                   double *px, double *py)
{
    double x1 = o->d[0], y1 = o->d[1], x2 = o->d[2], y2 = o->d[3];
    double rx = bx - ax, ry = by - ay;
    double sx = x2 - x1, sy = y2 - y1;
    double den = rx * sy - ry * sx, t, u, e1, e2;

    if (den == 0.0)
        return 0;
    t = ((x1 - ax) * sy - (y1 - ay) * sx) / den;
    u = ((x1 - ax) * ry - (y1 - ay) * rx) / den;
    if (t < 0.0 || t > 1.0 || u < 0.0 || u > 1.0)
        return 0;
    e1 = x1 * vx + y1 * vy - tl;
    e2 = x2 * vx + y2 * vy - tl;
    if (e1 < 0.0)
        e1 = -e1;
    if (e2 < 0.0)
        e2 = -e2;
    *px = e1 <= e2 ? x1 : x2;
    *py = e1 <= e2 ? y1 : y2;
    return 1;
}

/* Only the editable layers, which is what src/pick.c picks from. */
static int ika_editable(const jw_drawing *d, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15;
    int gs = d->group[g].state, ls = d->group[g].layer[l].state;

    gs = gs == 0 ? 0 : gs == 1 ? 1 : 3;
    ls = ls == 0 ? 0 : ls == 1 ? 1 : 3;
    return (gs & ls) == 3 && !(o->flags & 1);
}

/* Is one of the original's dimension 点 already sitting here? */
static int ika_dotted(const jw_drawing *d, double x, double y)
{
    int i;

    /* only the drawing itself: the block definitions after it are not
       drawn, so nothing there can be standing on the paper */
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double dx, dy;

        if (o->cls != JW_TEN || !(o->flags & JW_SUN_TEN_FLAGS))
            continue;
        dx = o->d[0] - x;
        dy = o->d[1] - y;
        if (dx * dx + dy * dy < 1e-12)
            return 1;
    }
    return 0;
}

/* One gap of the row: s0 to s1 along the dimension's own direction. */
static int ika_gap(jw_drawing *d, double s0, double s1,
                   double ux, double uy, double vx, double vy,
                   double tl, double th)
{
    double x0 = s0 * ux + tl * vx, y0 = s0 * uy + tl * vy;
    double x1 = s1 * ux + tl * vx, y1 = s1 * uy + tl * vy;
    double len = s1 > s0 ? s1 - s0 : s0 - s1;
    double cw, ch, sp, tw = 0.0, mid, t;
    char txt[64];
    const char *p;
    int nch = 0, i, wg = 0, made = 0;
    jw_obj *o;

    if (len <= 0.0)
        return 0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;

    o = jw_add(d, JW_SEN);
    if (!o)
        return 0;
    o->color = sun_sencol;
    o->ltype = 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    made++;

    /* 端部 and 引出線 at each end that has neither yet -- the near one
       first, which is sunpo_make's own order.  Usually only the far end
       is new, because the near one was the gap before's far end; both
       are new on the first gap of a row that does not start where the
       hand-drawn dimension did, and the original writes both then
       (tools/probe55.sh's 点線 run). */
    {
        int k, want[2];

        want[0] = !ika_dotted(d, x0, y0);
        want[1] = !ika_dotted(d, x1, y1);
        for (k = 0; k < 2; k++) {
            if (!want[k])
                continue;
            o = jw_add(d, JW_TEN);
            if (!o)
                break;
            o->color = sun_tencol;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
            o->d[0] = k ? x1 : x0;
            o->d[1] = k ? y1 : y0;
            o->n = 0;
            made++;
        }
        for (k = 0; th != tl + sun_tsuki && k < 2; k++) {
            double s = k ? s1 : s0;
            if (!want[k])
                continue;
            o = jw_add(d, JW_SEN);
            if (!o)
                break;
            o->color = sun_hikicol;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
            o->d[0] = s * ux + (tl + sun_tsuki) * vx;
            o->d[1] = s * uy + (tl + sun_tsuki) * vy;
            o->d[2] = s * ux + th * vx;
            o->d[3] = s * uy + th * vy;
            made++;
        }
    }

    i = sun_mojino - 1;
    if (i < 0 || i > 9)
        i = 0;
    cw = d->style[i].w;
    ch = d->style[i].h;
    sp = d->style[i].sp;
    sunpo_text(txt, (int)sizeof txt, len, d->group[wg].scale);
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    if (cw <= 0.0 || ch <= 0.0 || !nch)
        return made;
    mid = (s0 + s1) / 2.0;
    t = tl + sun_hanare;
    o = jw_add(d, JW_MOJI);
    if (!o)
        return made;
    o->color = (unsigned short)d->style[i].color;
    o->ltype = 2;
    o->width = (unsigned short)((sun_decimals() << 12)
                                | (JW_SUN_TEXT_WIDTH & 0x0fffu));
    o->flags = (unsigned short)(o->flags | JW_SUN_TEXT_FLAGS);
    o->d[0] = (mid - tw / 2.0) * ux + t * vx;
    o->d[1] = (mid - tw / 2.0) * uy + t * vy;
    o->d[2] = (mid + tw / 2.0) * ux + t * vx;
    o->d[3] = (mid + tw / 2.0) * uy + t * vy;
    o->d[4] = cw;
    o->d[5] = ch;
    o->d[6] = sp;
    o->d[7] = 0.0;
    o->n = sun_mojino;
    o->text = jw_add_str(d, txt);
    o->face = jw_add_str(d, JW_MOJI_FACE);
    made++;
    return made;
}

/* (R) at the third prompt: draw the lot.
 *
 * The two ends of the row are the lines that were indicated, so they are
 * in whether the clicks landed quite on them or a tenth of a millimetre
 * to one side; the ones in between are the ones the segment between
 * those two clicks crosses.
 */
static void ika_run(jw_drawing *d)
{
    double a = sun_angle() * PI / 180.0;
    double ux = cos(a), uy = sin(a), vx = -uy, vy = ux;
    double tl = sun_lx * vx + sun_ly * vy;
    double th = sun_hx * vx + sun_hy * vy;
    double lo = ika_s0 < ika_s1 ? ika_s0 : ika_s1;
    double hi = ika_s0 < ika_s1 ? ika_s1 : ika_s0;
    double s[IKA_MAX];
    int n = 0, i, j, made = 0;

    s[n++] = ika_s0;
    s[n++] = ika_s1;
    for (i = 0; i < d->ndrawn && n < IKA_MAX; i++) {
        const jw_obj *o = &d->obj[i];
        double px, py, ss;

        if (o->cls != JW_SEN || !ika_editable(d, o))
            continue;
        if (ika_lt >= 0 && o->ltype != ika_lt)
            continue;           /* 同一線種選択 */
        if (!ika_hit(o, ika_ax, ika_ay, ika_bx, ika_by, vx, vy, tl, &px, &py))
            continue;
        ss = px * ux + py * uy;
        if (ss < lo - 1e-9 || ss > hi + 1e-9)
            continue;
        for (j = 0; j < n; j++)
            if (s[j] - ss < 1e-9 && ss - s[j] < 1e-9)
                break;
        if (j == n)
            s[n++] = ss;
    }
    for (i = 0; i < ika_ntog; i++) {
        /* 追加・除外: each click turns its own line over */
        double ss = ika_tog[i];

        for (j = 0; j < n; j++)
            if (s[j] - ss < 1e-9 && ss - s[j] < 1e-9)
                break;
        if (j < n)
            s[j] = s[--n];
        else if (n < IKA_MAX)
            s[n++] = ss;
    }
    for (i = 1; i < n; i++) {   /* along the dimension, left to right */
        double k = s[i];
        for (j = i; j > 0 && s[j - 1] > k; j--)
            s[j] = s[j - 1];
        s[j] = k;
    }
    for (i = 0; i + 1 < n; i++)
        made += ika_gap(d, s[i], s[i + 1], ux, uy, vx, vy, tl, th);
    if (made)
        op_push(made);
}

/* 包絡処理 (0x804e): the first click is one corner of the box, the second
 * the other -- and the second does the work.  What it does to the lines the
 * box catches is src/houraku.c; here it goes into the drawing, so that one
 * 元に戻る takes the lot back.
 */
/* which line types the bar's four checkboxes let through */
static int hou_ltypes(int *out)
{
    int n = 0, i;

    if (jw_cmd_bar_check(1338))         /* 実線 */
        out[n++] = 1;
    if (jw_cmd_bar_check(1339))         /* 点線 */
        for (i = 2; i <= 4; i++)
            out[n++] = i;
    if (jw_cmd_bar_check(1340))         /* 鎖線 */
        for (i = 5; i <= 8; i++)
            out[n++] = i;
    if (jw_cmd_bar_check(1341))         /* 補助線 */
        out[n++] = 9;
    return n;
}

static int houraku(jw_drawing *d, double x, double y, int erase)
{
    jw_hou_out *out = 0;
    int ltype[10], nlt, n, i, j, changed = 0;
    op_t *rec;

    nlt = hou_ltypes(ltype);
    if (!d || nlt == 0)
        return 0;
    n = jw_houraku(d, hou_x, hou_y, x, y, ltype, nlt, erase, &out);
    if (n <= 0) {
        free(out);
        return 0;
    }
    rec = op_new();
    /* the ones that stay, first: the first piece takes the element's place
       and any others are added at the end */
    for (i = 0; i < n; i++) {
        jw_obj *o;
        int first = 1;

        if (out[i].drop || out[i].at < 0 || out[i].at >= d->ndrawn)
            continue;
        for (j = 0; j < i; j++)
            if (out[j].at == out[i].at && !out[j].drop)
                first = 0;
        o = &d->obj[out[i].at];
        if (first) {
            if (o->d[0] != out[i].x0 || o->d[1] != out[i].y0
                || o->d[2] != out[i].x1 || o->d[3] != out[i].y1) {
                op_keep(rec, d, out[i].at, 0);
                o->d[0] = out[i].x0;
                o->d[1] = out[i].y0;
                o->d[2] = out[i].x1;
                o->d[3] = out[i].y1;
                changed = 1;
            }
        } else {
            jw_obj was = *o, *p = jw_add(d, JW_SEN);

            if (p) {
                *p = was;
                p->d[0] = out[i].x0;
                p->d[1] = out[i].y0;
                p->d[2] = out[i].x1;
                p->d[3] = out[i].y1;
                p->sel = 0;
                rec->n++;
                changed = 1;
            }
        }
    }
    /* and then the ones that go, from the back so the rest keep their
       places -- and last, so 元に戻る puts them back before it puts the
       changed ones right */
    for (i = d->ndrawn - 1; i >= 0; i--) {
        int gone = 0;

        for (j = 0; j < n; j++)
            if (out[j].at == i) {
                if (out[j].drop)
                    gone = 1;
                else {
                    gone = 0;
                    break;
                }
            }
        if (gone) {
            op_keep(rec, d, i, 1);
            jw_remove(d, i);
            changed = 1;
        }
    }
    free(out);
    if (!changed && rec == &op[nop - 1] && rec->nitem == 0 && rec->n == 0)
        nop--;                  /* nothing happened: no undo step either */
    return changed;
}

/* 中心点取得 (33016): the next point is the middle of whatever is pointed
 * at.  Driving the original bears out both halves -- a click on the full
 * circle of tools/mkgeom.c ended the line at its centre (60, -30), and one
 * on the first line ended it at that line's middle (0, 60), which is
 * decomp/res/snapcen.jww.
 */
static int read_mode;
static int read_a;              /* the first of the two points, if any */
static double read_ax, read_ay;
static int read_pick = -1;      /* 線上点's element, once it has been picked */

void jw_cmd_read_mode(int mode)
{
    read_mode = mode;
    read_a = 0;
    read_pick = -1;
}

/* 角度取得 (32932 線角度 / 32935 線鉛直角度 / 32933 X軸角度 /
 * 32934 ２点間角度) and 長さ取得 (32939 線長 / 32940 ２点間長), the
 * 設定 menu's two little families.  They take over the next click or two
 * and leave a number behind; see kata_set/naga_mm above for what the
 * number then does.  The status line says what each wants:
 *
 *   32932 / 32939  「基準線を指示してください。」   one line, picked
 *   32934 / 32940  「２点間角度 ▼基準点指示▲」 then 「●角度点 指示」,
 *                  and for the length 「２点間長さ　▲終点指示▼」
 *
 * Five of them are settled, each by drawing the same line with the value
 * taken and without: 線角度 (32932) gives the picked line's angle,
 * 線鉛直角度 (32935) that angle plus a right angle, X軸角度 (32933) the
 * angle between two points read, 線長 (32939) the picked line's length,
 * ２点間長 (32940) the distance between the two points read.
 *
 * ２点間角度 (32934) is **not** done.  Its two prompts are the same two
 * 32933 shows and it takes the same two clicks, but no run has yet caught
 * what it leaves behind, and 32933 already covers「二点の間の角」-- so
 * what the second one is for is still unanswered.  Guessing is not
 * allowed. */
void jw_cmd_get_mode(int mode)
{
    get_mode = mode;
    get_step = 0;
}

int jw_cmd_get_mode_now(void)
{
    return get_mode;
}

/* 測定's bar draws three of its labels from the command's own state:
   which of the four is chosen, the unit and the number of places
   (src/cmd.c's 測定 note). */
int jw_cmd_sokutei_mode(void)
{
    return sok_mode;
}

int jw_cmd_sokutei_dms(void)
{
    return sok_dms;
}

int jw_cmd_sokutei_mm(void)
{
    return sok_unit;
}

/* 0..4, or 5 for F */
int jw_cmd_sokutei_dp(void)
{
    return sok_dp;
}

/* what the two families leave behind, for whoever draws the status line */
int jw_cmd_get_kata(double *out)
{
    if (out && have_kata)
        *out = get_kata * 180.0 / PI;
    return have_kata;
}

int jw_cmd_get_naga(double *out)
{
    if (out && have_naga)
        *out = get_naga;
    return have_naga;
}

int jw_cmd_get_kankaku(double *out)
{
    if (out && have_kan)
        *out = get_kan;
    return have_kan;
}

static void get_take_angle(double a)
{
    while (a > PI)
        a -= 2.0 * PI;
    while (a <= -PI)
        a += 2.0 * PI;
    get_kata = a;
    have_kata = 1;
    get_mode = 0;
}

static void get_take_length(double l)
{
    if (l <= 0.0)
        return;
    get_naga = l;
    have_naga = 1;
    get_mode = 0;
}

/* 間隔取得 (32948), which sits in the same 長さ取得 submenu.  It takes a
 * line with (L) and a point with (R)Read, and what it leaves behind is
 * 複線's 間隔: the perpendicular distance from the point to the line.
 *
 * Six earlier runs looked for the number in six places and found it in
 * none of them (tools/probe44.sh, probe46.sh .. probe48.sh).  All six
 * had the same hole in them: the second click was an (R) at a spot with
 * **nothing to read**, so nothing was ever taken.  With a point to read
 * there, the command finishes by itself, hands control back to the one
 * it was called from, and that one's next click only says which side
 * (tools/probe90.sh, probe92.sh).  Three runs, three distances:
 *
 *     point (300,600)   164.27 out     decomp/res/kankaku_a.jww
 *     point (700,650)    82.14 out     decomp/res/kankaku_b.jww
 *     point (200,200)    27.38 out     decomp/res/kankaku_c.jww
 *
 * and the sign is the click's, not the measurement's: the point of run
 * b is on the far side of the line from the copy.
 *
 * Only a line has been held against the original.  The prompt offers
 * 「線・円指示(L)」, but what the distance to a circle means -- to its
 * middle, or to the near side of it -- has not been asked. */
static void get_take_kankaku(double l)
{
    if (l <= 0.0)
        return;
    get_kan = l;
    have_kan = 1;
    get_mode = 0;
}

/* The length along an arc or circle, FUN_0045cb90: the radius times the sweep,
   and for an ellipse the chords of steps of 2e-5 radians added up.  (A radius
   under 1e-7 is nothing, a flatness under 1e-4 is a diameter.) */
static double arc_length(const jw_obj *o)
{
    double r = o->d[2], a0 = o->d[3], sw = o->d[4], fl = o->d[6];
    double step, t = 0.0, sum = 0.0, px, py;
    int last = 0;

    if (r < 1e-7)
        return 0.0;
    if (fl < 1e-4)
        return r * 2.0;
    if (fabs(fl - 1.0) < 1e-7)
        return fabs(r * sw);
    step = sw < 0.0 ? -2e-5 : 2e-5;
    px = cos(a0);
    py = sin(a0) * fl;
    do {
        double u, cx, cy;

        t += step;
        u = t;
        if (fabs(sw) <= fabs(t)) {
            last = 1;
            u = sw;
        }
        cx = cos(a0 + u);
        cy = sin(a0 + u) * fl;
        sum += sqrt((cx - px) * (cx - px) + (cy - py) * (cy - py));
        px = cx;
        py = cy;
    } while (!last);
    return r * sum;
}

/* 基本設定 2100「線長取得で円を指示したとき、円半径取得を円周長取得にする」
   (DAT_00a0cb64, FUN_0076bba0) */
static int get_arc_len;

void jw_cmd_get_arc_length(int on)
{
    get_arc_len = on != 0;
}

/* one click while a 取得 is on; 1 if it was swallowed */
/* 基本設定 一般(1) 1522「表示のみレイヤも属性取得」: the 取得 interrupts
   (FUN_004754c0) pick with FUN_0044a270's last argument = DAT_00a0c7b0, which
   lets 表示のみ layers in.  Read off the decompile. */
static int get_shown_too;

void jw_cmd_get_shown_too(int on)
{
    get_shown_too = on != 0;
}

static int get_click_(jw_drawing *d, const jw_view *v,
                      double x, double y, int button);

static int get_click(jw_drawing *d, const jw_view *v,
                     double x, double y, int button)
{
    int r, was = jw_pick_shown_too;

    jw_pick_shown_too = get_shown_too;
    r = get_click_(d, v, x, y, button);
    jw_pick_shown_too = was;
    return r;
}

static int get_click_(jw_drawing *d, const jw_view *v,
                     double x, double y, int button)
{
    int two = get_mode == 32940 || get_mode == 32933
              || get_mode == 32934;
    int i;

    if (!d)
        return 1;
    /* 数値角度 (32938) と 数値長 (32941).
     *
     * 問いかけは「数値を指示してください。」で、指すのは**図面に書いて
     * ある数字**、つまり文字要素です。文字「30」を指したあとの一本を
     * 原典に引かせると（`tools/probe121.sh`、縮尺 1/100 の図面）:
     *
     *   数値角度  線は **30 度**に出ます。長さはクリックをその向きへ
     *             落としたぶん —— 線角度 (32932) とまったく同じ形で、
     *             原典は 183.673, -30.612 のクリックから 143.77 mm の
     *             線を引きました（183.673 cos30 − 30.612 sin30）
     *   数値長    線は紙の上で **0.300 mm**。30 ÷ 100 なので、**30 は
     *             実寸**です —— バーの箱とまったく同じ決まり（box_mm）
     *
     * 全角の数字や単位つきの文字を原典がどう読むかは訊いていません。 */
    /* 目盛基準点 (32912).
     *
     * 問いかけは「■■■■    基準点を指示して下さい  (L)free  (R)Read
     * ■■■■」（5314）で、一手で終わります。**動かすのは図面の
     * `mesh_ox`/`mesh_oy`** —— `src/draw.c` が目盛を刻む原点で、.jww に
     * 書かれているものです。だから絵でなくファイルで測れました
     * （`tools/probe132.sh`・`tools/mesh.exe`）。目盛間隔を 10 にして
     * 目盛を出した原典で、この命令のあと格子がずれることも撮ってあります
     * （`tools/probe131.sh`、5,706 画素）。 */
    if (get_mode == 32912) {
        double rx = x, ry = y;

        if (button != 0 && !jw_read(d, v, x, y, &rx, &ry))
            return 1;
        d->mesh_ox = rx;
        d->mesh_oy = ry;
        get_mode = 0;
        return 1;
    }
    /* レイヤ非表示化 (32936).
     *
     * 問いかけは「非表示にするレイヤの図形を指示してください」（5264）で、
     * 一手。指した要素の**レイヤが非表示 (0) になります** ——
     * orig/Test5.jww（書込レイヤは 8）のレイヤ 0 の線を (L) で指すと、
     * 保存した図面のレイヤ 0 が 2 から 0 に変わりました
     * （`tools/probe133.sh`、`tools/laystate.py`）。
     *
     * ここまで三度空振りしています（`probe122`〜`probe124`）。指した所に
     * 図形が無かったのだろうと思いますが、確かなことは分かりません ——
     * 効いたのは、移植に図面を読ませて**線の通る所を計算してから**
     * 指したときでした。
     *
     * 原典の受け手（FUN_004754c0）は、指した図形が**書込グループの書込
     * レイヤ**にあれば札 0x148e を出して何もせず（ほかのグループの書込
     * レイヤは非表示にする）、そうでなければ状態を 0 にする。基本設定の
     * 2446「[レイヤ非表示化]を[表示のみレイヤ化]にする」（DAT_00a0c7d0）
     * が立っていれば 1（表示のみ）にする。逆コンパイルの読み。 */
    if (get_mode == 32936) {
        int i = jw_pick(d, v, x, y, 0);

        if (i < 0)
            return 1;
        {
            int g = d->obj[i].lgroup & 15, l = d->obj[i].layer & 15, wg = 0, k;

            for (k = 0; k < 16; k++)
                if (d->group[k].state == 3)
                    wg = k;
            if (!(g == wg && l == (d->group[wg].write_layer & 15)))
                d->group[g].layer[l].state = layhide_shown ? 1 : 0;
        }
        get_mode = 0;
        return 1;
    }
    if (get_mode == 32938 || get_mode == 32941) {
        const char *t;

        i = jw_pick(d, v, x, y, 0);
        if (i < 0 || d->obj[i].cls != JW_MOJI)
            return 1;
        t = jw_str(d, d->obj[i].text);
        if (!t || !*t)
            return 1;
        if (get_mode == 32938)
            get_take_angle(atof(t) * PI / 180.0);
        else
            get_take_length(atof(t) / write_scale(d));
        return 1;
    }
    if (get_mode == 32948) {
        /* a line first, then a point */
        if (get_step == 0) {
            i = jw_pick(d, v, x, y, 6);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return 1;
            get_obj = i;
            get_step = 1;
            return 1;
        }
        if (button != 0 && !jw_read(d, v, x, y, &x, &y))
            return 1;
        if (get_obj >= 0 && get_obj < d->ndrawn
            && d->obj[get_obj].cls == JW_SEN) {
            const jw_obj *o = &d->obj[get_obj];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = sqrt(dx * dx + dy * dy);

            if (len > 1e-09)
                get_take_kankaku(fabs(((x - o->d[0]) * -dy
                                       + (y - o->d[1]) * dx) / len));
        }
        return 1;
    }
    if (two) {
        if (button != 0 && !jw_read(d, v, x, y, &x, &y))
            return 1;
        if (get_step == 0) {
            get_ax = x;
            get_ay = y;
            get_step = 1;
            return 1;
        }
        if (get_mode == 32940)
            get_take_length(sqrt((x - get_ax) * (x - get_ax)
                                 + (y - get_ay) * (y - get_ay)));
        else if (get_mode == 32934)
            /* ２点間角度 is **not** the angle between the two points,
               which is what X軸角度 next to it gives.  It is a right
               angle minus that -- the angle measured from the y axis.
               Three runs say so: the original was given two points at
               -26.565, -14.036 and +14.036 degrees and the line it drew
               afterwards came out at 116.565, 104.036 and 75.964
               (tools/probe28.sh, probe43.sh, probe46.sh).  The positive
               one is what tells 90 - a from |a| + 90.
               A line only shows the angle modulo 180, and the original
               keeps the number to itself -- the 傾き box stayed empty
               after every grab, X軸角度's included (tools/probe47.sh)
               -- so which of 90 - a and 90 - a - 180 it holds is not
               something this port can know. */
            get_take_angle(PI / 2.0 - atan2(y - get_ay, x - get_ax));
        else
            get_take_angle(atan2(y - get_ay, x - get_ax));
        return 1;
    }
    /* the one-pick ones want a line */
    i = jw_pick(d, v, x, y, 6);
    if (i >= 0 && get_mode == 32939 && d->obj[i].cls == JW_ENKO) {
        /* 線長取得 of a circle or arc: its radius, or with 2100 the length
           round it (FUN_0076bba0).  Read off the decompile. */
        get_take_length(get_arc_len ? arc_length(&d->obj[i]) : d->obj[i].d[2]);
        return 1;
    }
    if (i < 0 || d->obj[i].cls != JW_SEN)
        return 1;
    {
        const jw_obj *o = &d->obj[i];
        double a = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]);

        /* 軸角 (32962) is the odd one out of the 角度取得 submenu: it does
         * not leave a number for the next line, it **turns the drawing's
         * axis**.  Asked of the original with a reference line at
         * -26.565 degrees (tools/probe123.sh), the next line drawn with
         * 水平･垂直 on came out along -26.565 instead of horizontal, and
         * its length was the click projected on to that way -- exactly
         * what 水平･垂直 does round any axis.  The problem it asks is
         * 「軸角取得  基準線を指示してください。」. */
        if (get_mode == 32962) {
            jw_cmd_set_axis(a * 180.0 / PI);
            get_mode = 0;
            return 1;
        }
        if (get_mode == 32939)
            get_take_length(sqrt((o->d[2] - o->d[0]) * (o->d[2] - o->d[0])
                                 + (o->d[3] - o->d[1]) * (o->d[3] - o->d[1])));
        else
            get_take_angle(get_mode == 32935 ? a + PI / 2.0 : a);
    }
    return 1;
}

int jw_cmd_read_mode_now(void)
{
    return read_mode;
}

/* The four quarter points of a circle, in its own frame -- 円周1/4点取得
   (33028) takes whichever is nearest.  A tilted or squashed circle carries
   its tilt in d[5] and its ratio in d[6], so they turn with it. */
static int arc_quarter(const jw_obj *o, double x, double y,
                       double *qx, double *qy)
{
    double c = cos(o->d[5]), s = sin(o->d[5]);
    double best = 0.0;
    int k, got = 0;

    if (o->cls != JW_ENKO)
        return 0;
    for (k = 0; k < 4; k++) {
        double a = k * 1.5707963267948966;
        double ux = o->d[2] * cos(a), uy = o->d[2] * o->d[6] * sin(a);
        double px = o->d[0] + ux * c - uy * s;
        double py = o->d[1] + ux * s + uy * c;
        double dd = (px - x) * (px - x) + (py - y) * (py - y);

        if (!got || dd < best) {
            best = dd;
            *qx = px;
            *qy = py;
            got = 1;
        }
    }
    return got;
}

/* The middle of an element, for 中心点取得.  A line's is half way along it,
   an arc's is where its centre is. */
static int obj_middle(const jw_obj *o, double *mx, double *my)
{
    if (o->cls == JW_SEN) {
        *mx = (o->d[0] + o->d[2]) / 2.0;
        *my = (o->d[1] + o->d[3]) / 2.0;
        return 1;
    }
    if (o->cls == JW_ENKO) {
        *mx = o->d[0];
        *my = o->d[1];
        return 1;
    }
    return 0;
}

/* A double left click.  連 wants one -- it is how the original says
   「移動（LL)」 -- and so does ２線's 基準線変更(LL) (nisen_ll); everywhere
   else it is just a left click. */
void jw_cmd_point_ll(jw_drawing *d, const jw_view *v, double x, double y)
{
    if (d && current == JW_CMD_MOJI && ren_step == 1) {
        int k = jw_pick(d, v, x, y, 0);

        if (k >= 0 && d->obj[k].cls == JW_MOJI) {
            ren_first = k;
            ren_step = 3;
        }
        return;
    }
    if (d && current == JW_CMD_NISEN && nisen_step > 0) {
        nisen_ll(d, v, x, y);   /* 基準線変更 (LL) */
        return;
    }
    jw_cmd_point(d, v, x, y, 0);
}

/* ---- AUTO モードの 線編集（decomp/res/au_*.jww、tools/autoprobe.sh） ----------
 * 線 A を L で押す（au_st 1）。そのあと
 *   L で 別の線      → コーナー（A も B も 押した側を残して 交点まで）
 *   L で 同じ線・何もない所 → 二点目 P2（au_st 2）。次の一点 P3 で、P2 が線の中なら
 *                       P2〜P3 の部分消し、線の外なら 伸縮（P3 の側の端を P3 の足へ）
 *   R で 同じ線          → A を消す
 *   R で 別の線          → A を その線まで（線伸縮基準線）。その線は変わらない
 *   au_st 2 の R で 同じ線 → 前後の交点のあいだを消す、R で読める点 → それを P3 に
 * 変えた線は 元を消して 末尾に（A、B の順）足す。 */
static int au_st = 0;
static int au_a = -1;
static double au_ax, au_ay, au_p2x, au_p2y;

static void au_reset(void)
{
    au_st = 0;
    au_a = -1;
}

/* 線 i の p0・p1 の どちらを 交点 x,y へ動かすか: 押した点 (px,py) の側を残す */
static void au_move_end(const jw_obj *o, double px, double py, double ix,
                        double iy, double *q)
{
    double ux = o->d[2] - o->d[0], uy = o->d[3] - o->d[1];
    double l = sqrt(ux * ux + uy * uy), s, v0, v1;

    q[0] = o->d[0]; q[1] = o->d[1]; q[2] = o->d[2]; q[3] = o->d[3];
    if (l < 1e-9)
        return;
    ux /= l;
    uy /= l;
    s = (px - ix) * ux + (py - iy) * uy >= 0.0 ? 1.0 : -1.0;
    v0 = ((o->d[0] - ix) * ux + (o->d[1] - iy) * uy) * s;
    v1 = ((o->d[2] - ix) * ux + (o->d[3] - iy) * uy) * s;
    if (v0 >= v1) {             /* p0 が残る、p1 を動かす */
        q[2] = ix;
        q[3] = iy;
    } else {
        q[0] = ix;
        q[1] = iy;
    }
}

/* 二本の直線（延長して）の交点 */
static int au_cross(const jw_obj *a, const jw_obj *b, double *ix, double *iy)
{
    double ax = a->d[2] - a->d[0], ay = a->d[3] - a->d[1];
    double bx = b->d[2] - b->d[0], by = b->d[3] - b->d[1];
    double det = ax * by - ay * bx, t;

    if (fabs(det) < 1e-12)
        return 0;
    t = ((b->d[0] - a->d[0]) * by - (b->d[1] - a->d[1]) * bx) / det;
    *ix = a->d[0] + ax * t;
    *iy = a->d[1] + ay * t;
    return 1;
}

static void au_add_line(jw_drawing *d, const jw_obj *from, const double *q)
{
    jw_obj *n = jw_add(d, JW_SEN);

    if (!n)
        return;
    {
        unsigned short ly = n->layer, lg = n->lgroup;

        *n = *from;
        n->layer = ly;
        n->lgroup = lg;
    }
    n->layer = from->layer;
    n->lgroup = from->lgroup;
    n->d[0] = q[0]; n->d[1] = q[1]; n->d[2] = q[2]; n->d[3] = q[3];
}

/* コーナー（b==-1 なら A だけを 基準線 b2 まで） */
static void au_corner(jw_drawing *d, int a, double apx, double apy, int b,
                      double bpx, double bpy, int only_a)
{
    jw_obj oa, ob;
    double ix, iy, qa[4], qb[4];
    op_t *o;
    int hi, lo;

    if (a < 0 || b < 0 || a >= d->ndrawn || b >= d->ndrawn || a == b)
        return;
    oa = d->obj[a];
    ob = d->obj[b];
    if (!au_cross(&oa, &ob, &ix, &iy))
        return;
    au_move_end(&oa, apx, apy, ix, iy, qa);
    au_move_end(&ob, bpx, bpy, ix, iy, qb);
    o = op_new();
    hi = a > b ? a : b;
    lo = a > b ? b : a;
    if (only_a) {
        erase(d, a, o);
    } else {
        erase(d, hi, o);
        erase(d, lo, o);
    }
    au_add_line(d, &oa, qa);
    if (!only_a)
        au_add_line(d, &ob, qb);
    if (o)
        o->n = only_a ? 1 : 2;
}

/* 伸縮: P3 の側の端を P3 の足へ */
static void au_stretch(jw_drawing *d, int a, double apx, double apy,
                       double p3x, double p3y)
{
    jw_obj oa;
    double ux, uy, l, t, q[4];
    op_t *o;

    if (a < 0 || a >= d->ndrawn)
        return;
    oa = d->obj[a];
    ux = oa.d[2] - oa.d[0];
    uy = oa.d[3] - oa.d[1];
    l = sqrt(ux * ux + uy * uy);
    if (l < 1e-9)
        return;
    ux /= l;
    uy /= l;
    q[0] = oa.d[0]; q[1] = oa.d[1]; q[2] = oa.d[2]; q[3] = oa.d[3];
    t = (p3x - oa.d[0]) * ux + (p3y - oa.d[1]) * uy;
    {
        double tp = (apx - oa.d[0]) * ux + (apy - oa.d[1]) * uy;

        if (p3x * 0.0 + t >= tp) {      /* P3 が押した点より先（p1 の側） */
            q[2] = oa.d[0] + ux * t;
            q[3] = oa.d[1] + uy * t;
        } else {
            q[0] = oa.d[0] + ux * t;
            q[1] = oa.d[1] + uy * t;
        }
    }
    o = op_new();
    erase(d, a, o);
    au_add_line(d, &oa, q);
    if (o)
        o->n = 1;
}

/* 線 a と ほかの線の交点の、押した位置 t0 の前後の交点のあいだを消す */
static void au_between(jw_drawing *d, int a, double cx, double cy)
{
    jw_obj oa;
    double ux, uy, l, t0, lo = 0.0, hi, q[4];
    int i, have_lo = 0, have_hi = 0;
    op_t *o;

    oa = d->obj[a];
    ux = oa.d[2] - oa.d[0];
    uy = oa.d[3] - oa.d[1];
    l = sqrt(ux * ux + uy * uy);
    if (l < 1e-9)
        return;
    ux /= l;
    uy /= l;
    hi = l;
    t0 = (cx - oa.d[0]) * ux + (cy - oa.d[1]) * uy;
    for (i = 0; i < d->ndrawn; i++) {
        double ix, iy, t, bx, by, s;

        if (i == a || d->obj[i].cls != JW_SEN)
            continue;
        if (!au_cross(&oa, &d->obj[i], &ix, &iy))
            continue;
        /* 相手の線の上にあること */
        bx = d->obj[i].d[2] - d->obj[i].d[0];
        by = d->obj[i].d[3] - d->obj[i].d[1];
        s = ((ix - d->obj[i].d[0]) * bx + (iy - d->obj[i].d[1]) * by) / (bx * bx + by * by);
        if (s < -1e-9 || s > 1.0 + 1e-9)
            continue;
        t = (ix - oa.d[0]) * ux + (iy - oa.d[1]) * uy;
        if (t <= 1e-9 || t >= l - 1e-9)
            continue;
        if (t <= t0 && (!have_lo || t > lo)) {
            lo = t;
            have_lo = 1;
        }
        if (t >= t0 && (!have_hi || t < hi)) {
            hi = t;
            have_hi = 1;
        }
    }
    o = op_new();
    erase(d, a, o);
    {
        int made = 0;

        if (have_lo) {
            q[0] = oa.d[0]; q[1] = oa.d[1];
            q[2] = oa.d[0] + ux * lo; q[3] = oa.d[1] + uy * lo;
            au_add_line(d, &oa, q);
            made++;
        }
        if (have_hi) {
            q[0] = oa.d[0] + ux * hi; q[1] = oa.d[1] + uy * hi;
            q[2] = oa.d[2]; q[3] = oa.d[3];
            au_add_line(d, &oa, q);
            made++;
        }
        if (o)
            o->n = made;
    }
}

/* AUTO の線編集の一押し。取り込んだら 1 */
static int au_edit(jw_drawing *d, const jw_view *v, double x, double y,
                   int button)
{
    int i;

    if (au_st == 0) {
        i = jw_pick(d, v, x, y, 3);
        if (i < 0 || d->obj[i].cls != JW_SEN)
            return 0;
        if (button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr))
                return 0;               /* 読める点があれば ＋ のほう */
            return 0;                   /* 複線 */
        }
        au_a = i;
        au_ax = x;
        au_ay = y;
        au_st = 1;
        return 1;
    }
    if (au_a < 0 || au_a >= d->ndrawn || d->obj[au_a].cls != JW_SEN) {
        au_reset();
        return 0;
    }
    if (au_st == 1) {
        i = jw_pick(d, v, x, y, 3);
        if (button == 1) {
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return 1;               /* 何もないところ: そのまま */
            if (i == au_a) {
                op_t *o = op_new();

                erase(d, au_a, o);      /* 同じ線: 消去 */
            } else
                au_corner(d, au_a, au_ax, au_ay, i, x, y, 1);
            au_reset();
            return 1;
        }
        if (i >= 0 && i != au_a && d->obj[i].cls == JW_SEN) {
            au_corner(d, au_a, au_ax, au_ay, i, x, y, 0);
            au_reset();
            return 1;
        }
        au_p2x = x;
        au_p2y = y;
        au_st = 2;
        return 1;
    }
    /* au_st == 2 */
    {
        double px = x, py = y;

        if (button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr)) {
                px = sxr;
                py = syr;
            } else {
                i = jw_pick(d, v, x, y, 3);
                if (i == au_a)
                    au_between(d, au_a, x, y);
                au_reset();
                return 1;
            }
        }
        {
            const jw_obj *oa = &d->obj[au_a];
            double ux = oa->d[2] - oa->d[0], uy = oa->d[3] - oa->d[1];
            double l = sqrt(ux * ux + uy * uy), t;

            if (l < 1e-9) {
                au_reset();
                return 1;
            }
            t = ((au_p2x - oa->d[0]) * ux + (au_p2y - oa->d[1]) * uy) / l;
            if (t <= -1e-7 || t >= l + 1e-7)
                au_stretch(d, au_a, au_ax, au_ay, px, py);
            else
                cut_line(d, au_a, au_p2x, au_p2y, px, py);
        }
        au_reset();
        return 1;
    }
}

/* 日影図・天空図の 真北（decomp/res/hk_a6*.jww、tools/hkprobe.sh）。線の端（矢の先）を押すと
   その端から 線に沿って 北の角度の文字（色 5・旗 0x40）と「真北」の文字を置く。
   北の角度 = 端から もう一方の端への向き + 90°（-180..180）。(L) は 度、(R) は 度分秒 */

static void hk_north_set(jw_drawing *d, const jw_view *v, double x, double y,
                         int button)
{
    int i = -1, k;
    double best = 1e99, tol = jw_pick_tol(v), ex, ey, ox, oy, ux, uy, l, ang, north;
    char txt[48];
    static const char tn[] = "\x90\x5e\x96\x6b";     /* 真北 */
    jw_obj *o;
    op_t *rec;

    for (k = 0; k < d->ndrawn; k++) {
        const jw_obj *q = &d->obj[k];
        double ax = q->d[0], ay = q->d[1], bx = q->d[2] - ax, by = q->d[3] - ay;
        double l2 = bx * bx + by * by, t, px, py, e;

        if (q->cls != JW_SEN)
            continue;
        t = l2 > 0.0 ? ((x - ax) * bx + (y - ay) * by) / l2 : 0.0;
        t = t < 0.0 ? 0.0 : t > 1.0 ? 1.0 : t;
        px = ax + t * bx - x;
        py = ay + t * by - y;
        e = sqrt(px * px + py * py);
        if (e <= tol && e < best) {
            best = e;
            i = k;
        }
    }
    if (i < 0)
        return;
    {
        double d0 = (x - d->obj[i].d[0]) * (x - d->obj[i].d[0]) + (y - d->obj[i].d[1]) * (y - d->obj[i].d[1]);
        double d1 = (x - d->obj[i].d[2]) * (x - d->obj[i].d[2]) + (y - d->obj[i].d[3]) * (y - d->obj[i].d[3]);

        if (d0 <= d1 + 0.02) {
            ex = d->obj[i].d[0]; ey = d->obj[i].d[1];
            ox = d->obj[i].d[2]; oy = d->obj[i].d[3];
        } else {
            ex = d->obj[i].d[2]; ey = d->obj[i].d[3];
            ox = d->obj[i].d[0]; oy = d->obj[i].d[1];
        }
    }
    ux = ox - ex;
    uy = oy - ey;
    l = sqrt(ux * ux + uy * uy);
    if (l < 1e-9)
        return;
    ux /= l;
    uy /= l;
    {
        const jw_obj *ln = &d->obj[i];
        double a0 = atan2(ln->d[3] - ln->d[1], ln->d[2] - ln->d[0]) * 180.0 / PI;
        int at0 = fabs(ln->d[0] - ex) < 1e-9 && fabs(ln->d[1] - ey) < 1e-9;

        if (!at0)
            a0 = a0 >= 0.0 ? a0 - 180.0 : a0 + 180.0;
        ang = a0;
    }
    north = ang + 90.0;
    while (north > 180.0)
        north -= 360.0;
    while (north <= -180.0)
        north += 360.0;
    if (button == 0) {
        snprintf(txt, sizeof txt, "%.6f", north);
    } else {
        double a = fabs(floor(north * 1e6 + 0.5) / 1e6);     /* 原典は 小数 6 位に丸めた値から */
        int deg = (int)a, mn = (int)((a - deg) * 60.0);
        double sec = ((a - deg) * 60.0 - mn) * 60.0;

        snprintf(txt, sizeof txt, "%s%d\xdf%02d'%05.2f\"", north < 0.0 ? "-" : "", deg, mn, sec);
    }
    rec = op_new();
    for (k = d->ndrawn - 1; k >= 0; k--)       /* 前の真北（旗 0x40）は消す */
        if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40))
            erase(d, k, rec);
    {
        double w = 0.0, a2, c2, s2, w2 = 5.0;
        const char *q;
        int added = 0;

        for (q = txt; *q; q++)
            w += 1.25;
        o = jw_add(d, JW_MOJI);
        if (!o)
            return;
        o->color = 5;
        o->ltype = 1;
        o->flags = 0x40;
        o->d[0] = ex;
        o->d[1] = ey;
        o->d[2] = ex + w * ux;
        o->d[3] = ey + w * uy;
        o->d[4] = o->d[5] = 2.5;
        o->d[7] = ang;
        o->text = jw_add_str(d, txt);
        o->face = jw_add_str(d, JW_MOJI_FACE);
        added++;
        a2 = (ang + 90.0) * PI / 180.0;
        c2 = cos(a2);
        s2 = sin(a2);
        o = jw_add(d, JW_MOJI);
        if (o) {
            o->color = 5;
            o->ltype = 1;
            o->flags = 0x40;
            o->d[0] = ex - w2 / 2.0 * c2 - s2 * 1.0;
            o->d[1] = ey - w2 / 2.0 * s2 + c2 * 1.0;
            o->d[2] = o->d[0] + w2 * c2;
            o->d[3] = o->d[1] + w2 * s2;
            o->d[4] = o->d[5] = 2.5;
            o->d[7] = ang + 90.0;
            o->text = jw_add_str(d, tn);
            o->face = jw_add_str(d, JW_MOJI_FACE);
            added++;
        }
        if (rec)
            rec->n = added;
    }
}

/* 日影図の 条件（バーの 緯度 1493・季節 2436・9～15時 1323）。
   緯度は 負なら 0、55 を超えれば 55、46 を超えると 9～15時 が強制（spec_hikage 1.4）。
   季節は 冬至 -23.45・春秋分 0・夏至 +23.45・任意時期（日赤緯の数）。
   季節の箱の中身は 原典の並びの番号 "0"～"3" か、名前（UTF-8 でも CP932 でも）。 */
static double hk_dec_user = -23.45;     /* 任意時期で入れた 日赤緯 */
typedef struct {
    double lat, dec;
    int n15;                            /* 9～15時 */
    int season;                         /* 0 冬至 1 春秋分 2 夏至 3 任意時期 */
    char head[40];                      /* 表の見出しの「季節」（CP932） */
} hk_cond_t;

static void hk_cond(hk_cond_t *c)
{
    const char *bs = jw_cmd_box(1493), *sb = jw_cmd_box(2436);

    c->lat = 36.0;
    if (bs && *bs)
        c->lat = atof(bs);
    if (c->lat < -1e-6)
        c->lat = 0.0;
    if (c->lat > 55.0)
        c->lat = 55.0;
    c->n15 = jw_cmd_bar_check(1323) > 0;
    if (c->lat > 46.0)
        c->n15 = 1;
    c->season = 0;
    if (sb && *sb) {
        if (!strcmp(sb, "1") || !strcmp(sb, "\x8f\x74\x8f\x57\x95\xaa") || !strcmp(sb, "春秋分"))
            c->season = 1;
        else if (!strcmp(sb, "2") || !strcmp(sb, "\x89\xc4\x8e\x8a") || !strcmp(sb, "夏至"))
            c->season = 2;
        else if (!strcmp(sb, "3") || !strcmp(sb, "\x94\x43\x88\xd3\x8e\x9e\x8a\xfa") ||
                 !strcmp(sb, "任意時期"))
            c->season = 3;
    }
    c->dec = c->season == 1 ? 0.0 : c->season == 2 ? 23.45 : c->season == 3 ? hk_dec_user : -23.45;
    if (c->season == 0)
        snprintf(c->head, sizeof c->head, "\x93\x7e\x8e\x8a");
    else if (c->season == 1)
        snprintf(c->head, sizeof c->head, "\x8f\x74\x8f\x57\x95\xaa");
    else if (c->season == 2)
        snprintf(c->head, sizeof c->head, "\x89\xc4\x8e\x8a");
    else
        snprintf(c->head, sizeof c->head, "\x93\xfa\x90\xd4\x88\xdc = %g", hk_dec_user);
}

static int hk_edges(const jw_drawing *d, hk_edge *e, int max, double plane_m, double scale);

/* 等時間 (decomp/res/hk_i*.jww)。水準 level 時間の等高線を 一組（同じ id）で書く */
static int hk_iso_n(jw_drawing *d, double level, double label)
{
    static hk_edge ed[1000];
    static hk_isoseg seg[4000];
    static const double sw[12] = { 1189, 841, 594, 420, 297, 514, 364, 257, 1682, 2378, 3364, 4756 };
    static const double sh[12] = { 841, 594, 420, 297, 210, 364, 257, 182, 1189, 1682, 2378, 3364 };
    hk_iso_in in;
    hk_cond_t cond;
    const char *bs;
    double plane = 4.0, north = 0.0;
    int ne, n, k, made = 0, gid = 0, ps = d->paper_size, lab = -1;
    op_t *o;

    hk_cond(&cond);
    bs = jw_cmd_box(1492);
    if (bs && *bs)
        plane = atof(bs);
    for (k = 0; k < d->ndrawn; k++) {
        if (d->obj[k].id > gid)
            gid = d->obj[k].id;
        if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40) && d->obj[k].text >= 0 &&
            d->obj[k].color == 5) {
            const char *t = jw_str(d, d->obj[k].text);

            if ((t[0] >= '0' && t[0] <= '9') || t[0] == '-')
                north = atof(t);
        }
    }
    ne = hk_edges(d, ed, 1000, plane, write_scale(d));
    if (ne < 2)
        return 0;
    if (ps < 0 || ps > 11)
        ps = 3;
    memset(&in, 0, sizeof in);
    in.lat = cond.lat;
    in.dec = cond.dec;
    in.north = north;
    in.level = level;
    in.n15 = cond.n15;
    in.step = hk_iso_step;
    if (hk_iso_rng == 3) {
        in.range = 1;
        memcpy(in.rx, hk_rx, sizeof in.rx);
        memcpy(in.ry, hk_ry, sizeof in.ry);
        if (in.step != 4)
            in.step = 10;
    } else if (in.step != 10)
        in.step = 60;
    in.sheet_w = sw[ps];
    in.sheet_h = sh[ps];
    n = hk_iso(ed, ne, &in, seg, 4000);
    o = op_new();
    gid++;
    for (k = 0; k < n; k++) {
        int q, lcol;
        jw_obj *l = jw_add(d, JW_SEN);

        if (!l)
            break;
        lcol = l->color;    /* jw_tg_text below adds too, and may move the array */
        l->d[0] = seg[k].x0;
        l->d[1] = seg[k].y0;
        l->d[2] = seg[k].x1;
        l->d[3] = seg[k].y1;
        l->id = gid;
        made++;
        for (q = 0; q < n; q++) {
            char lab_s[24];
            jw_tg_out to;
            double wx[2], wy[2], w, ang;
            hk_pt a, b;
            int nn;

            if (!seg[q].label || seg[q].label_at != k + 1)
                continue;
            snprintf(lab_s, sizeof lab_s, "%.1f", label);
            if ((int)(label * 100.0) % 10 > 0)
                snprintf(lab_s, sizeof lab_s, "%.2f", label);
            if ((int)(label * 1000.0) % 10 > 0)
                snprintf(lab_s, sizeof lab_s, "%.3f", label);
            w = (double)strlen(lab_s);
            a.x = seg[q].x0;
            a.y = seg[q].y0;
            b.x = seg[q].x1;
            b.y = seg[q].y1;
            if (hypot(b.x - a.x, b.y - a.y) < 1e-4)
                continue;
            hk_label_place(a, b, w, &a, &b, &ang);
            wx[0] = a.x; wy[0] = a.y; wx[1] = b.x; wy[1] = b.y;
            memset(&to, 0, sizeof to);
            to.cls = JW_TG_TEXT_O;
            to.kind = 1;
            to.text = lab_s;
            nn = jw_tg_text(d, &to, wx, wy, 0);
            if (nn > 0) {
                d->obj[d->ndrawn - 1].id = gid;
                d->obj[d->ndrawn - 1].n = 0;
                d->obj[d->ndrawn - 1].color = (unsigned short)lcol;
            }
            made += nn;
            lab = q;
        }
    }
    (void)lab;
    if (o)
        o->n = made;
    return made;
}

/* 日影図の 日影の線（decomp/res/hk_b*.jww、tools/hkprobe.sh、tmp/spec_hikage の核）。
   高さの文字（旗 0x80）が両端にある線が 建物の辺。時刻ごとに 外形の線を書く。 */

static int hk_edges(const jw_drawing *d, hk_edge *e, int max, double plane_m,
                    double scale)
{
    int n = 0, i, k;

    for (i = 0; i < d->ndrawn && n < max; i++) {
        const jw_obj *l = &d->obj[i];
        double h[2];
        int found[2] = { 0, 0 };

        if (l->cls != JW_SEN || l->color == 9 || l->ltype == 9)
            continue;
        for (k = 0; k < d->ndrawn; k++) {
            const jw_obj *t = &d->obj[k];
            double h1, h2;
            int e2;

            if (t->cls != JW_MOJI || !(t->flags & 0x80) || t->text < 0 ||
                t->layer != l->layer || t->lgroup != l->lgroup)
                continue;
            for (e2 = 0; e2 < 2; e2++)
                if (!found[e2] && fabs(t->d[0] - l->d[e2 * 2]) < 0.01 &&
                    fabs(t->d[1] - l->d[e2 * 2 + 1]) < 0.01 &&
                    hk_parse_height_text(jw_str(d, t->text), &h1, &h2) > 0) {
                    h[e2] = h1;
                    found[e2] = 1;
                }
        }
        if (!found[0] || !found[1])
            continue;
        e[n].a.x = l->d[0];
        e[n].a.y = l->d[1];
        e[n].b.x = l->d[2];
        e[n].b.y = l->d[3];
        e[n].za_mm = hk_vertex_z_mm(h[0], 0.0, plane_m, scale);
        e[n].zb_mm = hk_vertex_z_mm(h[1], 0.0, plane_m, scale);
        n++;
    }
    return n;
}

/* 時間ごと（half: 30 分毎）の日影の線。作った数を返す */
static int hk_outlines(jw_drawing *d, int half)
{
    static hk_edge ed[1000];
    static hk_seg seg[400];
    static int cs[400];
    const char *bs;
    double plane = 4.0, lat = 36.0, north = 0.0, hour, h0, h1;
    hk_cond_t cond;
    int ne, made = 0, k, gid = 0;
    hk_sun sun;
    op_t *o;

    bs = jw_cmd_box(1492);
    if (bs && *bs)
        plane = atof(bs);
    hk_cond(&cond);
    lat = cond.lat;
    h0 = cond.n15 ? 9.0 : 8.0;
    h1 = cond.n15 ? 15.0 : 16.0;
    for (k = 0; k < d->ndrawn; k++) {
        if (d->obj[k].id > gid)
            gid = d->obj[k].id;
        if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40) && d->obj[k].text >= 0 &&
            d->obj[k].color == 5 && (d->obj[k].text >= 0)) {
            const char *t = jw_str(d, d->obj[k].text);

            if ((t[0] >= '0' && t[0] <= '9') || t[0] == '-')
                north = atof(t);
        }
    }
    ne = hk_edges(d, ed, 1000, plane, write_scale(d));
    if (ne < 2)
        return 0;
    hk_sun_init(&sun, lat, cond.dec);
    o = op_new();
    for (hour = half == 2 ? hk_one_hour : h0; hour <= (half == 2 ? hk_one_hour : h1) + 1e-9;
         hour += half == 1 ? 0.5 : 1.0) {
        double x, y, sx, sy;
        int ts = (int)floor((hour - 12.0) * 3600.0 + 0.5), n, j, start = 0, chain_n = 0;

        hk_sun_shadow(&sun, ts, &x, &y);
        hk_rot(x, y, north, &sx, &sy);
        n = hk_outline(ed, ne, sx, sy, seg, cs, 400);
        {
            /* 建物の平面の内側にある線は 影ではない（屋根は影に含まれる）。
               辺の集まりを 偶奇で見た「中」にある線は 外す */
            int w2 = 0;

            for (j = 0; j < n; j++) {
                double mx = (seg[j].a.x + seg[j].b.x) / 2.0, my = (seg[j].a.y + seg[j].b.y) / 2.0;
                int in = 0, q;

                for (q = 0; q < ne; q++) {
                    double ax = ed[q].a.x, ay = ed[q].a.y, bx = ed[q].b.x, by = ed[q].b.y;

                    if ((ay > my) != (by > my) &&
                        mx < ax + (my - ay) * (bx - ax) / (by - ay))
                        in = !in;
                }
                if (!in) {
                    if (cs[j] || (w2 > 0 && 0)) {
                    }
                    seg[w2] = seg[j];
                    cs[w2] = cs[j];
                    w2++;
                } else if (cs[j] && j + 1 < n && !cs[j + 1])
                    cs[j + 1] = 1;      /* 鎖の頭を外したら 次が頭 */
            }
            n = w2;
        }
        gid++;
        for (j = 0; j < n; j++) {
            jw_obj *l = jw_add(d, JW_SEN);

            if (!l)
                break;
            l->d[0] = seg[j].a.x;
            l->d[1] = seg[j].a.y;
            l->d[2] = seg[j].b.x;
            l->d[3] = seg[j].b.y;
            l->id = gid;
            /* 整時は 線種 1、半時は 2、そのほかは 3（原典の組の印 1・2・3） */
            l->ltype = fabs(hour - floor(hour + 0.5)) < 1e-9 ? 1 : fabs(hour * 2.0 - floor(hour * 2.0 + 0.5)) < 1e-9 ? 2 : 3;
            made++;
            if (cs[j]) {
                start = j;
                chain_n = 1;
            } else
                chain_n++;
            /* 一つ目の線から数えて 午前は 2 本目、午後は 3 本目に 時刻の文字 */
            if (chain_n == hk_label_segment_index(hour)) {
                char lab[24];
                jw_tg_out to;
                double wx[2], wy[2], w;
                hk_pt a, b;
                int nn, lcolor;

                hk_fmt_hour_label(lab, sizeof lab, hour);
                w = (double)strlen(lab) * 1.0;
                hk_label_place(seg[start + chain_n - 1].a, seg[start + chain_n - 1].b, w, &a, &b, &w);
                wx[0] = a.x; wy[0] = a.y; wx[1] = b.x; wy[1] = b.y;
                memset(&to, 0, sizeof to);
                to.cls = JW_TG_TEXT_O;
                to.kind = 1;
                to.text = lab;
                lcolor = l->color;          /* before jw_tg_text adds: that may move the array */
                nn = jw_tg_text(d, &to, wx, wy, 0);
                if (nn > 0) {
                    d->obj[d->ndrawn - 1].id = gid;
                    d->obj[d->ndrawn - 1].n = 0;                 /* 原典は 任意サイズ・書く色 */
                    d->obj[d->ndrawn - 1].color = (unsigned short)lcolor;
                }
                made += nn;
            }
        }
    }
    if (o)
        o->n = made;
    return made;
}

/* 時間指定: 作図時間を入力する窓（テンプレート 348）の答え。範囲は 8 - 16（9-15時 なら 9 - 15） */
int jw_cmd_hikage_ask(void)
{
    int r = hk_ask_time;

    hk_ask_time = 0;
    return r && current == JW_CMD_HIKAGE ? r : 0;
}

/* 窓の答え。kind は jw_cmd_hikage_ask の返り値（1 時間指定・2 等時間の時間指定・3 日赤緯） */
int jw_cmd_hikage_answer(jw_drawing *d, int kind, const char *txt)
{
    if (kind == 1)
        return jw_cmd_hikage_time(d, txt);
    if (kind == 2)
        return jw_cmd_hikage_level(d, txt);
    if (kind == 3)
        return jw_cmd_hikage_dec(txt);
    return 0;
}

/* 等時間の 時間指定: 1 - 8（9～15時 なら 1 - 6）の数。水準は 範囲の上限近くでは 0.01 引く */
int jw_cmd_hikage_level(jw_drawing *d, const char *txt)
{
    hk_cond_t cond;
    double v, mx, lv;
    char *end;

    if (current != JW_CMD_HIKAGE || !d || !txt || !hk_iso_on)
        return 0;
    hk_cond(&cond);
    mx = cond.n15 ? 6.0 : 8.0;
    v = strtod(txt, &end);
    if (end == txt || v < 0.9999999 || v > mx + 1e-7)
        return 0;                   /* 0x1599: データが不適当 */
    lv = v;
    if (mx - 0.01 < lv)
        lv -= 0.01;
    return hk_iso_n(d, lv, v) > 0;
}

int jw_cmd_hikage_time(jw_drawing *d, const char *txt)
{
    double h;
    char *end;

    if (current != JW_CMD_HIKAGE || !d || !txt)
        return 0;
    h = strtod(txt, &end);
    {
        hk_cond_t cond;
        double hh;

        hk_cond(&cond);
        hh = cond.n15 ? 3.0 : 4.0;
        if (end == txt || h < 12.0 - hh - 1e-9 || h > 12.0 + hh + 1e-9)
            return 0;               /* 0x1599: 範囲外 */
    }
    hk_one_hour = 8.0 + floor((h - 8.0) * 3600.0 + 0.5) / 3600.0;
    return hk_outlines(d, 2) > 0;
}

/* 任意時期: 日赤緯の窓（-23.45～23.45）の答え。範囲外は 0x1599（何も変えない） */
int jw_cmd_hikage_dec(const char *txt)
{
    double v;
    char *end;

    if (current != JW_CMD_HIKAGE || !txt)
        return 0;
    v = strtod(txt, &end);
    if (end == txt || v < -23.45 - 1e-7 || v > 23.45 + 1e-7)
        return 0;
    hk_dec_user = v;
    jw_cmd_box_put(2436, "3");
    return 1;
}

/* 日影図の 表（影倍率表。decomp/res/hk_t1.jww）。置く位置 (cx,cy) の下に、八時から十六時まで三十分毎。
   線は色 1、文字は書く色の 2.5 角（任意サイズ）。見出しの文字は 欄の中で中央、値は 右に 2.5 寄せ */

static int hk_text_at(jw_drawing *d, double x, double y, const char *t, double wcell,
                      int align, const jw_obj *like)
{
    jw_tg_out o;
    double wx[2], wy[2], w = 0.0;
    const char *q;
    int n;

    for (q = t; *q; ) {
        int wide = jw_is_lead((unsigned char)q[0]) && q[1];

        w += wide ? 2.5 : 1.25;
        q += wide ? 2 : 1;
    }
    (void)wcell;
    wx[0] = x + (align == 2 ? -w : align == 1 ? -w / 2.0 : 0.0);
    wy[0] = wy[1] = y;
    wx[1] = wx[0] + w;
    memset(&o, 0, sizeof o);
    o.cls = JW_TG_TEXT_O;
    o.kind = 2;
    o.text = t;
    n = jw_tg_text(d, &o, wx, wy, 0);
    if (n > 0) {
        d->obj[d->ndrawn - 1].n = 0;
        if (like)
            d->obj[d->ndrawn - 1].color = like->color;
    }
    return n;
}

/* 角度の文字は UTF-8（半角の ﾟ が EF BE 9F）で出てくるので CP932（DF）に */
static void hk_cp932(char *s)
{
    char *w = s;

    for (; *s; s++) {
        if ((unsigned char)s[0] == 0xef && (unsigned char)s[1] == 0xbe && (unsigned char)s[2] == 0x9f) {
            *w++ = (char)0xdf;
            s += 2;
        } else
            *w++ = *s;
    }
    *w = 0;
}

static int hk_hline(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *l = jw_add(d, JW_SEN);

    if (!l)
        return 0;
    l->color = 1;
    l->ltype = 1;
    l->d[0] = x0; l->d[1] = y0; l->d[2] = x1; l->d[3] = y1;
    return 1;
}

/* 日影長さ図・方位角倍率図（decomp/res/hk_t2.jww・hk_t3.jww）。置く位置 O から 三十分毎の
   影の向きに 線を引く（長さ図は 影の長さそのまま、倍率図は 50 mm 一定）。線は色 1、整時は線種 1・半時は 2 */
static int hk_text_u(jw_drawing *d, double x, double y, double ux, double uy,
                     const char *t, int kind, unsigned short color)
{
    jw_tg_out o;
    double wx[2], wy[2], w = 0.0, sz = kind == 1 ? 2.0 : 2.5;
    const char *q;
    int n;

    for (q = t; *q; ) {
        int wide = jw_is_lead((unsigned char)q[0]) && q[1];

        w += wide ? sz : sz / 2.0;
        q += wide ? 2 : 1;
    }
    wx[0] = x;
    wy[0] = y;
    wx[1] = x + ux * w;
    wy[1] = y + uy * w;
    memset(&o, 0, sizeof o);
    o.cls = JW_TG_TEXT_O;
    o.kind = kind;
    o.text = t;
    n = jw_tg_text(d, &o, wx, wy, 0);
    if (n > 0) {
        d->obj[d->ndrawn - 1].n = 0;
        d->obj[d->ndrawn - 1].color = color;
    }
    return n;
}

static int hk_table23(jw_drawing *d, double cx, double cy, int which)
{
    char buf[120], num[40], lat_s[24], hs[24];
    double lat = 36.0, plane = 4.0, hgt = 10.0, north = 0.0, scale = write_scale(d);
    int made = 0, r, k;
    hk_sun sun;
    hk_cond_t cond;
    const char *bs;
    unsigned short wc = (unsigned short)(d->write_ltype ? d->write_color : 2);
    op_t *rec = op_new();
    static const char t2a[] = "\x93\xfa\x89\x65\x92\xb7\x82\xb3\x90\x7d";
    static const char t3a[] = "\x95\xfb\x88\xca\x8a\x70\x94\x7b\x97\xa6\x90\x7d";

    hk_cond(&cond);
    lat = cond.lat;
    bs = jw_cmd_box(1492);
    if (bs && *bs)
        plane = atof(bs);
    bs = jw_cmd_box(1491);
    if (bs && *bs) {
        char tmp[64];

        hk_height_text(tmp, sizeof tmp, bs, 0);
        hgt = atof(tmp);
    }
    for (k = 0; k < d->ndrawn; k++)
        if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40) && d->obj[k].text >= 0 &&
            d->obj[k].color == 5) {
            const char *t = jw_str(d, d->obj[k].text);

            if ((t[0] >= '0' && t[0] <= '9') || t[0] == '-')
                north = atof(t);
        }
    hk_sun_init(&sun, lat, cond.dec);
    snprintf(lat_s, sizeof lat_s, "%g", lat);
    /* 見出し: 題・緯度と季節（・高さと測定面・縮尺と計算高さ）。真ん中に */
    {
        double hh = (hgt - plane);
        char l1[24];
        double w1 = which == 2 ? 12.5 : 15.0;

        snprintf(l1, sizeof l1, "%s", which == 2 ? t2a : t3a);
        made += hk_text_u(d, cx - w1 / 2.0, cy - 3.0, 1.0, 0.0, l1, 2, wc);
        snprintf(buf, sizeof buf, "[ \x88\xdc\x93\x78 = %s\xdf ][ %s ]", lat_s, cond.head);
        {
            double w = 0.0;
            const char *q;

            for (q = buf; *q; ) {
                int wide = jw_is_lead((unsigned char)q[0]) && q[1];

                w += wide ? 2.5 : 1.25;
                q += wide ? 2 : 1;
            }
            made += hk_text_u(d, cx - w / 2.0, cy - 6.0, 1.0, 0.0, buf, 2, wc);
        }
        if (which == 2) {
            double w;
            const char *q;

            snprintf(hs, sizeof hs, "%.3f", hgt);
            snprintf(buf, sizeof buf, "\x8d\x82\x82\xb3\x81\x81%s(m) \x81\x40\x91\xaa\x92\xe8\x96\xca\x8d\x82\x82\xb3\x81\x81%g(m)", hs, plane);
            for (w = 0.0, q = buf; *q; ) {
                int wide = jw_is_lead((unsigned char)q[0]) && q[1];

                w += wide ? 2.5 : 1.25;
                q += wide ? 2 : 1;
            }
            made += hk_text_u(d, cx - w / 2.0, cy - 9.0, 1.0, 0.0, buf, 2, wc);
            snprintf(buf, sizeof buf, "S=1/%g \x81\x40\x8c\x76\x8e\x5a\x8d\x82\x82\xb3\x81\x81%.3f(m)", scale, hh);
            for (w = 0.0, q = buf; *q; ) {
                int wide = jw_is_lead((unsigned char)q[0]) && q[1];

                w += wide ? 2.5 : 1.25;
                q += wide ? 2 : 1;
            }
            made += hk_text_u(d, cx - w / 2.0, cy - 12.0, 1.0, 0.0, buf, 2, wc);
        }
    }
    for (r = 0; r < (cond.n15 ? 13 : 17); r++) {
        int ts = (cond.n15 ? -10800 : -14400) + r * 1800;
        int whole = (r % 2) == 0;
        double x, y, sx, sy, mult, len, ux, uy, nx, ny, tipx, tipy, hmm;
        char tm[16];
        jw_obj *ln;

        hk_sun_shadow(&sun, ts, &x, &y);
        hk_rot(x, y, north, &sx, &sy);
        mult = hk_shadow_mult(x, y);
        len = sqrt(sx * sx + sy * sy);
        ux = len > 0.0 ? sx / len : 1.0;
        uy = len > 0.0 ? sy / len : 0.0;
        nx = -uy;
        ny = ux;
        hmm = (hgt - plane) * 1000.0 / scale;
        if (which == 2) {
            char m3[32];
            double mr;

            snprintf(m3, sizeof m3, "%.3f", mult);
            mr = atof(m3);
            snprintf(num, sizeof num, "%.3f(m)", (hgt - plane) * mr);
            tipx = cx + sx * hmm;
            tipy = cy + sy * hmm;
            len = len * hmm;
            made += hk_text_u(d, tipx - ux * 11.0 + nx * 0.2, tipy - uy * 11.0 + ny * 0.2, ux, uy, num, 1, wc);
        } else {
            double deg;
            char a[40];

            if (r == 0) {
                made += hk_text_u(d, cx + ux * 28.0 + nx * 2.8, cy + uy * 28.0 + ny * 2.8, ux, uy,
                                  "\x91\xbe\x97\x7a\x95\xfb\x88\xca\x8a\x70", 1, wc);
                made += hk_text_u(d, cx + ux * 39.0 + nx * 2.8, cy + uy * 39.0 + ny * 2.8, ux, uy,
                                  "\x20\x89\x65\x92\xb7\x94\x7b\x97\xa6\x20", 1, wc);
            }
            deg = hk_shadow_az_deg(x, y);
            hk_fmt_angle(a, sizeof a, 1, 0, deg);
            hk_cp932(a);
            {
                double aw = (double)strlen(a);      /* 右（36 mm）にそろえる */

                made += hk_text_u(d, cx + ux * (36.0 - aw) + nx * 0.2, cy + uy * (36.0 - aw) + ny * 0.2, ux, uy, a, 1, wc);
            }
            snprintf(num, sizeof num, "%.3f", mult);
            made += hk_text_u(d, cx + ux * 41.0 + nx * 0.2, cy + uy * 41.0 + ny * 0.2, ux, uy, num, 1, wc);
            tipx = cx + ux * 50.0;
            tipy = cy + uy * 50.0;
        }
        ln = jw_add(d, JW_SEN);
        if (!ln)
            break;
        ln->color = 1;
        ln->ltype = whole ? 1 : 2;
        ln->d[0] = cx; ln->d[1] = cy; ln->d[2] = tipx; ln->d[3] = tipy;
        made++;
        if (which == 2) {
            jw_obj *pt = jw_add(d, JW_TEN);

            if (pt) {
                pt->color = 1;
                pt->ltype = 1;
                pt->d[0] = tipx;
                pt->d[1] = tipy;
                made++;
            }
        }
        snprintf(tm, sizeof tm, "%2d:%02d", (ts + 43200) / 3600, (ts + 43200) / 60 % 60);
        made += hk_text_u(d, tipx + ux * 1.0 - nx * 1.25, tipy + uy * 1.0 - ny * 1.25, ux, uy, tm, 2, wc);
    }
    if (rec)
        rec->n = made;
    return made;
}

static int hk_table1(jw_drawing *d, double cx, double cy)
{
    static const double colx[7] = { 0.0, 11.25, 28.75, 46.25, 63.75, 78.75, 93.75 };
    static const char *const head[6] = {
        "\x8e\x9e\x20\x8d\x8f", "\x91\xbe\x97\x7a\x81\x40\x8d\x82\x93\x78",
        "\x91\xbe\x97\x7a\x95\xfb\x88\xca\x8a\x70", "\x20\x89\x65\x92\xb7\x94\x7b\x97\xa6\x20",
        "\x82\x77\x20\x94\x7b\x20\x97\xa6", "\x82\x78\x20\x94\x7b\x20\x97\xa6" };
    char buf[96], num[32], lat_s[24];
    double lat = 36.0, plane;
    int made = 0, i, r, nrow = 17;
    hk_sun sun;
    hk_cond_t cond;
    jw_obj wcol;
    const jw_obj *like = &wcol;
    op_t *rec = op_new();
    const char *bs = jw_cmd_box(1493);

    memset(&wcol, 0, sizeof wcol);
    wcol.color = (unsigned short)(d->write_ltype ? d->write_color : 2);
    (void)plane;
    (void)bs;
    hk_cond(&cond);
    lat = cond.lat;
    nrow = cond.n15 ? 13 : 17;
    hk_sun_init(&sun, lat, cond.dec);
    snprintf(lat_s, sizeof lat_s, "%g", lat);
    snprintf(buf, sizeof buf, "\x89\x65\x94\x7b\x97\xa6\x95\x5c  [ \x88\xdc\x93\x78 = %s\xdf ][ %s ]", lat_s, cond.head);
    made += hk_text_at(d, cx, cy + 1.0, buf, 0.0, 0, like);
    for (i = 0; i < 7; i++) {
        made += hk_hline(d, cx + colx[i], cy, cx + colx[i], cy - 5.0 * (nrow + 1));
        if (i < 6)
            made += hk_text_at(d, cx + (colx[i] + colx[i + 1]) / 2.0, cy - 3.75 - 0.0, head[i],
                               0.0, 1, like);
    }
    made += hk_hline(d, cx, cy, cx + colx[6], cy);
    made += hk_hline(d, cx, cy - 5.0, cx + colx[6], cy - 5.0);
    for (r = 0; r < nrow; r++) {
        int ts = (cond.n15 ? -10800 : -14400) + r * 1800;
        double x, y, y0 = cy - 5.0 * (r + 1) - 3.75, sa;

        hk_sun_shadow(&sun, ts, &x, &y);
        sa = hk_sun_sin_alt(&sun, ts);
        snprintf(buf, sizeof buf, "%2d:%02d", (ts + 43200) / 3600, (ts + 43200) / 60 % 60);
        made += hk_text_at(d, cx + (colx[0] + colx[1]) / 2.0, y0, buf, 0.0, 1, like);
        hk_fmt_angle(num, sizeof num, 0, 0, asin(sa > 1.0 ? 1.0 : sa < -1.0 ? -1.0 : sa) * 180.0 / PI);
        hk_cp932(num);
        made += hk_text_at(d, cx + colx[2] - 2.5, y0, num, 0.0, 2, like);
        hk_fmt_angle(num, sizeof num, 1, 0, hk_shadow_az_deg(x, y));
        hk_cp932(num);
        made += hk_text_at(d, cx + colx[3] - 2.5, y0, num, 0.0, 2, like);
        snprintf(num, sizeof num, "%.3f", hk_shadow_mult(x, y));
        made += hk_text_at(d, cx + colx[4] - 2.5, y0, num, 0.0, 2, like);
        snprintf(num, sizeof num, "%.3f", x);
        made += hk_text_at(d, cx + colx[5] - 2.5, y0, num, 0.0, 2, like);
        snprintf(num, sizeof num, "%.3f", y);
        made += hk_text_at(d, cx + colx[6] - 2.5, y0, num, 0.0, 2, like);
        made += hk_hline(d, cx, cy - 5.0 * (r + 2), cx + colx[6], cy - 5.0 * (r + 2));
    }
    if (rec)
        rec->n = made;
    return made;
}

/* 日影図の 指定点（decomp/res/hk_k*.jww）。測定点を押すと 仮点（色 1）と「No.n」を置き、
   計算の釦（1 分・10 秒間隔）のあと 結果を書く位置を押すと 点ごとに一行、日影になる時間を書く */
#define HK_MAXPT 99
static double hkp_x[HK_MAXPT], hkp_y[HK_MAXPT];

static void hk_point_add(jw_drawing *d, double x, double y)
{
    jw_obj *o;
    jw_tg_out to;
    double wx[2], wy[2];
    char lab[16];
    int made = 1;
    op_t *rec;

    if (hkp_n >= HK_MAXPT)
        return;
    rec = op_new();
    o = jw_add(d, JW_TEN);
    if (!o)
        return;
    o->color = 1;
    o->ltype = 1;
    o->d[0] = x;
    o->d[1] = y;
    hkp_x[hkp_n] = x;
    hkp_y[hkp_n] = y;
    snprintf(lab, sizeof lab, "No.%d", hk_first_no + hkp_n);
    hkp_n++;
    wx[0] = x;
    wx[1] = x + 4.0;
    wy[0] = wy[1] = y;
    memset(&to, 0, sizeof to);
    to.cls = JW_TG_TEXT_O;
    to.kind = 1;
    to.text = lab;
    if (jw_tg_text(d, &to, wx, wy, 0) > 0) {
        d->obj[d->ndrawn - 1].n = 0;
        d->obj[d->ndrawn - 1].color = 1;
        made++;
    }
    if (rec)
        rec->n = made;
}

static int hk_points_write(jw_drawing *d, double cx, double cy, int step)
{
    static hk_edge ed[1000];
    double plane = 4.0, lat = 36.0, north = 0.0;
    const char *bs;
    int ne, k, i, made = 0, nt, t0;
    hk_sun sun;
    hk_cond_t cond;
    static hk_quad qd[1000];
    static unsigned char in[28801];
    op_t *rec;

    bs = jw_cmd_box(1492);
    if (bs && *bs)
        plane = atof(bs);
    hk_cond(&cond);
    lat = cond.lat;
    t0 = cond.n15 ? -10800 : -14400;
    nt = -2 * t0 / step + 1;
    for (k = 0; k < d->ndrawn; k++)
        if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40) && d->obj[k].text >= 0 &&
            d->obj[k].color == 5) {
            const char *t = jw_str(d, d->obj[k].text);

            if ((t[0] >= '0' && t[0] <= '9') || t[0] == '-')
                north = atof(t);
        }
    ne = hk_edges(d, ed, 1000, plane, write_scale(d));
    if (ne < 2)
        return 0;
    hk_sun_init(&sun, lat, cond.dec);
    rec = op_new();
    for (k = 0; k < hkp_n; k++) {
        char line[200];
        hk_interval iv[40];
        int niv;
        jw_tg_out to;
        double wx[2], wy[2], w = 0.0;
        const char *q;

        for (i = 0; i < nt; i++) {
            double x, y, sx, sy;
            int ts = t0 + i * step;

            hk_sun_shadow(&sun, ts, &x, &y);
            hk_rot(x, y, north, &sx, &sy);
            hk_build_quads(ed, ne, sx, sy, qd);
            in[i] = (unsigned char)hk_point_in_quads(qd, ne, hkp_x[k], hkp_y[k]);
        }
        niv = hk_intervals(in, nt, t0, step, iv, 40);
        hk_fmt_n0_line(line, sizeof line, hk_first_no + k, iv, niv, step);
        for (q = line; *q; q++)
            w += 1.0;
        wx[0] = cx;
        wx[1] = cx + w;
        wy[0] = wy[1] = cy - 4.0 * k;
        memset(&to, 0, sizeof to);
        to.cls = JW_TG_TEXT_O;
        to.kind = 1;
        to.text = line;
        if (jw_tg_text(d, &to, wx, wy, 0) > 0) {
            d->obj[d->ndrawn - 1].n = 0;
            d->obj[d->ndrawn - 1].color = 1;
            made++;
        }
    }
    if (rec)
        rec->n = made;
    return made;
}

/* 高さの箱の式（+ - * / と かっこ）。読めなければ 0 */
static const char *hk_e;
static double hk_expr(void);

static double hk_atom(void)
{
    double v = 0.0;

    while (*hk_e == ' ')
        hk_e++;
    if (*hk_e == '-') {
        hk_e++;
        return -hk_atom();
    }
    if (*hk_e == '+') {
        hk_e++;
        return hk_atom();
    }
    if (*hk_e == '(') {
        hk_e++;
        v = hk_expr();
        while (*hk_e == ' ')
            hk_e++;
        if (*hk_e == ')')
            hk_e++;
        return v;
    }
    {
        char *end;

        v = strtod(hk_e, &end);
        if (end == hk_e) {
            hk_bad = 1;
            return 0.0;
        }
        hk_e = end;
    }
    return v;
}

/* a number with its power: ^ binds to the number just read, as the original's
   FUN_004f36e0 takes it straight after FUN_004f3b80's atom (FUN_004f3930) */
static double hk_pow(void)
{
    double v = hk_atom();

    for (;;) {
        while (*hk_e == ' ')
            hk_e++;
        if (*hk_e != '^')
            return v;
        hk_e++;
        v = pow(v, hk_atom());
    }
}

static double hk_term(void)
{
    double v = hk_pow();

    for (;;) {
        while (*hk_e == ' ')
            hk_e++;
        if (*hk_e == '*') {
            hk_e++;
            v *= hk_pow();
        } else if (*hk_e == '/') {
            double r;

            hk_e++;
            r = hk_pow();
            v = r != 0.0 ? v / r : 0.0;
        } else
            return v;
    }
}

static double hk_expr(void)
{
    double v = hk_term();

    for (;;) {
        while (*hk_e == ' ')
            hk_e++;
        if (*hk_e == '+') {
            hk_e++;
            v += hk_term();
        } else if (*hk_e == '-') {
            hk_e++;
            v -= hk_term();
        } else
            return v;
    }
}

static double hk_eval(const char *t)
{
    hk_e = t;
    return hk_expr();
}

/* 高さの箱 → 図面に書く文字。日影は %0.3lf（二つなら " , " でつなぐ）、
   ２．５D は %lg と 文字（v→V h→H g t T d D）を後ろに（tools/hkprobe.sh、decomp/res/hk_a5*.jww） */
static void hk_height_text(char *out, size_t cap, const char *box, int d25)
{
    char buf[96], *comma;
    char letter = 0;
    size_t n = 0, i;
    double a, b;
    int two = 0;

    for (i = 0; box && box[i] && n + 2 < sizeof buf; i++) {
        if (box[i] == '.' && box[i + 1] == '.') {
            buf[n++] = ' ';
            buf[n++] = ',';
            i++;
        } else
            buf[n++] = box[i];
    }
    buf[n] = 0;
    if (d25) {
        char *e = buf + strlen(buf);

        while (e > buf && e[-1] == ' ')
            *--e = 0;
        for (i = 0; buf[i] == ' '; i++)
            ;
        if (strchr("vVhHgGtTdD", buf[i]) && buf[i]) {
            letter = buf[i];
            memmove(buf, buf + i + 1, strlen(buf + i));
        } else if (e > buf && strchr("vVhHgGtTdD", e[-1])) {
            letter = e[-1];
            *--e = 0;
        }
        if (letter == 'v')
            letter = 'V';
        else if (letter == 'h')
            letter = 'H';
        else if (letter == 'G')
            letter = 'g';
    }
    comma = strchr(buf, ',');
    if (comma) {
        *comma = 0;
        two = 1;
        b = hk_eval(comma + 1);
    } else
        b = 0.0;
    a = hk_eval(buf);
    if (d25) {
        if (two)
            snprintf(out, cap, "%.15g , %.15g%c", a, b, letter);
        else
            snprintf(out, cap, "%.15g%c", a, letter);
        if (!letter && out[strlen(out) - 1] == 0) {
        }
    } else if (two)
        snprintf(out, cap, "%0.3f , %0.3f", a, b);
    else
        snprintf(out, cap, "%0.3f", a);
}

/* 伸縮 (CZukeiShinshuku): the pieces its click uses.  All read off the
 * decompile, not asked of the original. */

/* moved off the right press: FUN_00715f50 cuts once |dx| + |dy| > 2 pixels */
static int stretch_far(const jw_view *v, double x, double y)
{
    return v && (fabs(x - stretch_rx) + fabs(y - stretch_ry)) * v->scale > 2.0;
}

/* 突出寸法, the bar's 1413 (FUN_004cad70 → +0xa060): real size, over the
   write group's scale; one under 1e-7 either way is none */
static double stretch_out(const jw_drawing *d)
{
    double v = box_num(jw_cmd_box(1413), 0.0);

    if (!d)
        return 0.0;
    v /= write_scale(d);
    return fabs(v) > 1e-07 ? v : 0.0;
}

/* FUN_0044cfb0 on a line: the end on P's side of where the line was picked
   (t0, along it) goes to P dropped on to the line, so the pick stays on
   what is left (fuzz cases 3, 4, 24, 59, s4_5) -- past an end that is the
   end it is past.  `out` carries it that much further on (FUN_0071a050's
   state 2: in the line's own frame P's x less 突出寸法 when it is not past
   the pick, more when it is). */
static void stretch_end(jw_drawing *d, int i, double t0, double x, double y,
                        double out)
{
    jw_obj *o = &d->obj[i];
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double len2 = dx * dx + dy * dy, t, nx, ny;
    int lo;

    if (len2 < 1e-14)
        return;
    t = ((x - o->d[0]) * dx + (y - o->d[1]) * dy) / len2;
    lo = t < t0;
    if (out != 0.0)
        t += (t <= t0 ? -out : out) / sqrt(len2);
    nx = o->d[0] + t * dx;
    ny = o->d[1] + t * dy;
    op_keep(op_new(), d, i, 0);
    if (lo) {
        o->d[0] = nx;
        o->d[1] = ny;
    } else {
        o->d[2] = nx;
        o->d[3] = ny;
    }
}

/* States 3 and 4 (FUN_0071a050 → FUN_0046e550): the line picked at (x, y)
   goes to where it meets the 基準線 -- the crossing nearest where the
   基準線 was picked, the hint FUN_0045fa30 is given when the line is not an
   arc -- by the end on that side of the pick, as above.  With a 突出寸法
   and a 基準線 that is a line, the 基準線 is first moved off itself by that
   much, away from the side the line was picked on, so the line goes past
   it (a minus one stops short).  No crossing (parallel) leaves it alone
   (0x1455).  A circle as the 基準線 is taken whole (circle_of). */
static void stretch_to_base(jw_drawing *d, int i, double x, double y)
{
    jw_obj base = stretch_base;
    const jw_obj *q = &d->obj[i];
    double out = stretch_out(d), px, py, ex, ey, l2;

    if (base.cls == JW_SEN && out != 0.0) {
        double bx = base.d[2] - base.d[0], by = base.d[3] - base.d[1];
        double bl = sqrt(bx * bx + by * by);

        if (bl > 1e-09) {
            /* the pick's own y in the 基準線's frame; at or over nought
               the 基準線 goes to -out, under it to +out */
            double side = ((x - base.d[0]) * -by + (y - base.d[1]) * bx) / bl;
            double off = side >= 0.0 ? -out : out;
            double ox = -by / bl * off, oy = bx / bl * off;

            base.d[0] += ox;
            base.d[1] += oy;
            base.d[2] += ox;
            base.d[3] += oy;
        }
    }
    if (!cross_obj(&base, q, stretch_bx, stretch_by, &px, &py))
        return;
    ex = q->d[2] - q->d[0];
    ey = q->d[3] - q->d[1];
    l2 = ex * ex + ey * ey;
    if (l2 < 1e-14)
        return;
    stretch_end(d, i, ((x - q->d[0]) * ex + (y - q->d[1]) * ey) / l2, px, py, 0.0);
}

/* The mouse moved with the right button pressed once in 伸縮: 線切断 there
   (CZukeiShinshuku's slot 6, FUN_00715f50).  1 when the drawing changed. */
int jw_cmd_stretch_move(jw_drawing *d, const jw_view *v, double x, double y)
{
    if (current != JW_CMD_SHINSHUKU || !stretch_rwait || !d || !v
        || !stretch_far(v, x, y))
        return 0;
    stretch_rwait = 0;
    cut_gap_at(d, v, stretch_rx, stretch_ry);
    return 1;
}

static void jw_cmd_point_(jw_drawing *d, const jw_view *v,
                          double x, double y, int button);

void jw_cmd_point(jw_drawing *d, const jw_view *v,
                  double x, double y, int button)
{
    last_dr = d;
    int depth0 = nop;

    jw_cmd_point_(d, v, x, y, button);
    /* A step that left a number the drawing cannot hold -- a copy scaled by
       9e11, two nearly parallel lines carried on to where they meet -- is
       taken back and forgotten: it could not be written out and read again,
       and the original has nowhere to put it either.  (tests/boxfuzz_test.c) */
    if (d && nop > depth0 && !jw_numbers_sane(d)) {
        jw_cmd_undo(d);
        ntop = nop;                 /* and not to be redone */
    }
    if (auto_back && ((current == JW_CMD_FUKUSEN && para_step == 0) ||
                      (current == JW_CMD_KUKEI && step == 0) ||
                      (current == JW_CMD_SHOUKYO && cut_step == 0))) {
        current = JW_CMD_AUTO;
        auto_back = 0;
    }
}

static void jw_cmd_point_(jw_drawing *d, const jw_view *v,
                          double x, double y, int button)
{
    if (current == 0x8091) {
        gb_click(d, v, x, y, button);
        return;
    }
    if (current == JW_CMD_RENZOKU && d && jw_cmd_bar_check(1774) > 0) {
        if (button == 0)
            fh_press(d, v, x, y);
        return;
    }
    if (d && ms_text && current == JW_CMD_MOJI) {
        /* a click on the drawing lets the picked texts go (slot 9) */
        sel_clear(d);
        ms_text = 0;
        return;
    }
    if (current == JW_CMD_GAZOU) {
        gz_point(d, v, x, y, button);
        return;
    }
    if ((current == JW_CMD_25D || current == JW_CMD_HIKAGE || current == JW_CMD_TENKU)
        && !hk_north && button == 1 && d) {
        /* (R) 高さ取得: 押した線端の文字を 高さの箱へ写す（なければ何も起きない） */
        int k, bi = -1;
        double best = 1e99, tol = jw_pick_tol(v);

        for (k = 0; k < d->ndrawn; k++) {
            const jw_obj *q = &d->obj[k];
            double e;

            if (q->cls != JW_MOJI || !(q->flags & 0x8080) || q->text < 0)
                continue;
            e = sqrt((q->d[0] - x) * (q->d[0] - x) + (q->d[1] - y) * (q->d[1] - y));
            if (e <= tol && e < best) {
                best = e;
                bi = k;
            }
        }
        if (bi >= 0)
            jw_cmd_box_put(1491, jw_str(d, d->obj[bi].text));
        return;
    }
    if (current == JW_CMD_HIKAGE && hk_write_cond && d && button <= 1) {
        char buf[160], hs[32];
        double px = x, py = y, w = 0.0, wx[2], wy[2], plane = 4.0, lat = 36.0;
        const char *bs, *q;
        jw_tg_out to;
        op_t *rec;

        if (button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr)) {
                px = sxr;
                py = syr;
            }
        }
        bs = jw_cmd_box(1492);
        if (bs && *bs)
            plane = atof(bs);
        bs = jw_cmd_box(1493);
        if (bs && *bs)
            lat = atof(bs);
        snprintf(hs, sizeof hs, "%g", plane);
        snprintf(buf, sizeof buf,
                 "\x91\xaa\x92\xe8\x96\xca\x82\xcc\x8d\x82\x82\xb3 = %s(m)  \x88\xdc\x93" "x = %g\x81\x8b  "
                 "[ \x93\x7e\x8e\x8a ]  \x91\xaa\x92\xe8\x8e\x9e\x8a\xd4:%s",
                 hs, lat,
                 jw_cmd_bar_check(1323) > 0
                     ? "\x82\x58\x8e\x9e\x81\x60\x82\x50\x82\x54\x8e\x9e"
                     : "\x82\x57\x8e\x9e\x81\x60\x82\x50\x82\x55\x8e\x9e");
        for (q = buf; *q; ) {
            int wide = jw_is_lead((unsigned char)q[0]) && q[1];

            w += wide ? 2.5 : 1.25;
            q += wide ? 2 : 1;
        }
        wx[0] = px; wx[1] = px + w;
        wy[0] = wy[1] = py;
        memset(&to, 0, sizeof to);
        to.cls = JW_TG_TEXT_O;
        to.kind = 2;
        to.text = buf;
        rec = op_new();
        if (jw_tg_text(d, &to, wx, wy, 0) > 0) {
            d->obj[d->ndrawn - 1].n = 2;
            d->obj[d->ndrawn - 1].color = 1;
            if (rec)
                rec->n = 1;
        }
        hk_write_cond = 0;
        return;
    }
    if (current == JW_CMD_HIKAGE && hk_pts && d && button <= 1) {
        double px = x, py = y;

        if (button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr)) {
                px = sxr;
                py = syr;
            }
        }
        if (hk_calc_step) {
            hk_points_write(d, px, py, hk_calc_step);
            hk_calc_step = 0;
        } else
            hk_point_add(d, px, py);
        return;
    }
    if (current == JW_CMD_HIKAGE && hk_iso_on && (hk_iso_rng == 1 || hk_iso_rng == 2) && d && button <= 1) {
        double px = x, py = y;

        if (button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr)) {
                px = sxr;
                py = syr;
            }
        }
        if (hk_iso_rng == 1) {
            hk_rx0 = px;
            hk_ry0 = py;
            hk_iso_rng = 2;
        } else {
            double north = 0.0, c, sn, ex, ey, dx, dy;
            int k;

            for (k = 0; k < d->ndrawn; k++)
                if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x40) && d->obj[k].text >= 0 &&
                    d->obj[k].color == 5) {
                    const char *t = jw_str(d, d->obj[k].text);

                    if ((t[0] >= '0' && t[0] <= '9') || t[0] == '-')
                        north = atof(t);
                }
            c = cos(north * 3.14159265358979323846 / 180.0);
            sn = sin(north * 3.14159265358979323846 / 180.0);
            ex = px - hk_rx0;
            ey = py - hk_ry0;
            dx = ex * c + ey * sn;                  /* 始点を原点に 真北に合わせた枠 */
            dy = -ex * sn + ey * c;
            if (fabs(dx) < 50.0)
                dx = dx < 0.0 ? -50.0 : 50.0;
            if (fabs(dy) < 50.0)
                dy = dy < 0.0 ? -50.0 : 50.0;
            for (k = 0; k < 4; k++) {
                double lx = k & 1 ? dx : 0.0, ly = k & 2 ? dy : 0.0;

                hk_rx[k] = hk_rx0 + lx * c - ly * sn;
                hk_ry[k] = hk_ry0 + lx * sn + ly * c;
            }
            hk_iso_rng = 3;
            hk_iso_step = 10;
        }
        return;
    }
    if (current == JW_CMD_HIKAGE && hk_sub && hk_tbl_pending && d && button <= 1) {
        if (hk_tbl_pending == 1069)
            hk_table1(d, x, y);
        else if (hk_tbl_pending == 1070)
            hk_table23(d, x, y, 2);
        else if (hk_tbl_pending == 1071)
            hk_table23(d, x, y, 3);
        return;
    }
    if (current == JW_CMD_TENKU && tn_cmp && d && button <= 1) {
        /* 天空率比較計算 (1066)。一つ目・二つ目は字を指示（FUN_0074e1c0、拾いは FUN_004500e0
           = jw_pick_moji）、三つ目は 結果の位置「(L)free  (R)Read」（0x16a3）。答えは
           decomp/res/hk_tc1〜tc3（tools/tnbatch4.sh） */
        if (tn_cmp <= 2) {
            int best = jw_pick_moji(d, v, x, y);
            double val;
            int dec;

            if (best < 0 || !jw_tenku_cmp_parse(jw_str(d, d->obj[best].text), &val, &dec,
                                                &tn_csan))
                return;             /* 原典は 0x16a4「天空率ではありません」 */
            if (tn_cmp == 1) {
                tn_csan = 0;
                jw_tenku_cmp_parse(jw_str(d, d->obj[best].text), &val, &dec, &tn_csan);
                tn_cdec = 2;
            }
            if (dec > tn_cdec)
                tn_cdec = dec;
            tn_cv[tn_cmp - 1] = val;
            tn_cx[tn_cmp - 1] = d->obj[best].d[0];
            tn_cy[tn_cmp - 1] = d->obj[best].d[1];
            tn_cmp++;
            return;
        } else {
            double px = x, py = y, sxr, syr;
            op_t *rec;
            int n0 = d->ndrawn;

            if (button == 1) {
                if (!jw_read(d, v, x, y, &sxr, &syr))
                    return;
                px = sxr;
                py = syr;
            }
            rec = op_new();
            jw_tenku_cmp_write(d, tn_cv[0], tn_cv[1], tn_cdec, tn_csan,
                               tn_cx[0], tn_cy[0], tn_cx[1], tn_cy[1], px, py);
            if (rec)
                rec->n = d->ndrawn - n0;
            tn_cmp = 1;             /* +0x1b0 = 0 に戻る（FUN_00739bd0） */
            return;
        }
    }
    if (current == JW_CMD_TENKU && tn_mode && !hk_north && d && button <= 1) {
        double px = x, py = y;

        if (button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr)) {
                px = sxr;
                py = syr;
            }
        }
        if (tn_mode == 1) {
            tn_px = px;
            tn_py = py;
            tn_mode = 2;
        } else {
            hk_tenku_opts o;
            int n0 = d->ndrawn, r;
            const char *bs;
            op_t *rec;

            if (!tn_sansha && jw_cmd_bar_check(1323) > 0 && tn_ans < 0) {
                /* 天空率計算 で 測定点が建物の内側（か線の上）なら 原典は「建物内部に測定点を指示した
                   可能性があります。指示した測定点の上に庇または屋根がありますか？」（0x1659・0x165a、
                   はい／いいえ／キャンセル）と問う。窓の答えが来るまで この点を取っておく（hk_s29〜s31） */
                static hk_edge3 qe[1000];
                static hk_tenku_base qb[1000];
                hk_tenku_opts q;
                int qn;

                hk_tenku_opts_default(&q);
                bs = jw_cmd_box(1492);
                if (bs && *bs)
                    q.plane_m = atof(bs);
                qn = jw_tenku_collect2(d, q.plane_m, qe, qb, 1000);
                if (qn > 0 && jw_tenku_inside(&q, qe, qb, qn, tn_px, tn_py)) {
                    tn_pend = 1;
                    tn_pend_x = x;
                    tn_pend_y = y;
                    tn_pend_b = button;
                    tn_pend_v = v;
                    return;
                }
            }
            if (jw_cmd_bar_check(1325) > 0 && tn_nq < 0 && !tn_north_of(d, 0)) {
                /* 太陽軌跡 で 真北が無いと 原典は「真北が設定されていません。」（0x15e2、
                   OK/キャンセル）を出し、OK なら上向きで描く（CZukeiHikage の FUN_004f60a0、
                   hk_s5）。窓の答えまで この点を取っておく */
                tn_nq_pend = 1;
                tn_pend_x = x;
                tn_pend_y = y;
                tn_pend_b = button;
                tn_pend_v = v;
                return;
            }
            rec = op_new();

            hk_tenku_opts_default(&o);
            bs = jw_cmd_box(1492);
            if (bs && *bs)
                o.plane_m = atof(bs);
            /* 1493 は 半径（バーの字は「天空図半径（図寸mm）」。原典 hk_s11 で
               40 を入れると 円の半径が 40 だった） */
            bs = jw_cmd_box(1493);
            if (bs && *bs && atof(bs) > 0.0)
                o.R = atof(bs);
            /* 測定点表示: 2216 に番号があれば 点・「No.n」・「測定点 No.n」を出す
               （原典 hk_s9、3 を入れて No.3） */
            bs = jw_cmd_box(2216);
            if (bs && *bs && atoi(bs) > 0) {
                o.show_point = 1;
            }
            /* 目盛間隔 (2209): 5・10・15・30・45・90 度（原典の行 1〜6）。ほかの字は なし */
            bs = jw_cmd_box(2209);
            if (bs && *bs) {
                double iv = atof(bs);

                if (iv == 5.0 || iv == 10.0 || iv == 15.0 || iv == 30.0 || iv == 45.0 || iv == 90.0)
                    o.interval = iv;
            }
            o.equidist = tn_equi;
            o.inside_yes = tn_ans == 1;
            /* 南方向補正 (1326) は 太陽軌跡 (1325) を入れたときだけバーに出て
               効く（初めから点いている。tools/tnbatch.sh の hk_s1 は 1326 が
               点いたまま 1325 なしで、補正は掛かっていない） */
            o.mirror = jw_cmd_bar_check(1325) > 0 && jw_cmd_bar_check(1326) > 0;
            o.calc = jw_cmd_bar_check(1323) > 0;
            o.precise = jw_cmd_bar_check(1327) > 0;
            /* 射影面積表示 (1324): 「【水平円射影面積 πR² , 隠れる面積】」（原典 hk_s4）。
               隠れる面積は 原典と同じく 建物ごとの射影折れ線 × 光線 で足し上げる
               （src/tenku.c の jw_tenku_ratio、FUN_00748da0） */
            o.show_area = o.calc && jw_cmd_bar_check(1324) > 0;
            o.number = o.show_point ? atoi(jw_cmd_box(2216)) : tn_count + 1;
            /* 太陽軌跡 (1325)・10分間隔点表示 (2113)・四季 (2115)、FUN_0073ea50（src/tenku.c の
               sun_path）。原典 hk_s5〜s8・s15〜s23。緯度 doc+0x83c0・日赤緯 doc+0x83c8 は
               日影図 の 緯度 (1493)・季節 (2436) の箱から取る（日影図で 45・夏至 にすると
               天空図に効く、hk_s19・s22。任意時期 の 日赤緯 は確かめていない） */
            o.sun = jw_cmd_bar_check(1325) > 0;
            if (o.sun) {
                const char *lb = box_of(JW_CMD_HIKAGE, 1493), *sb = box_of(JW_CMD_HIKAGE, 2436);
                double north = 0.0;
                int k;

                const unsigned char *n15 = chk_slot(JW_CMD_HIKAGE, 1323);

                /* 9～15時 (doc+0x83d0) も 日影図 の 1323 が効く（原典 hk_s23: 字が 9 と 15）。
                   緯度 46° 超えの強制は 天空図にも及ぶ（hk_s24） */
                o.sun_n15 = n15 && *n15;
                o.sun10 = jw_cmd_bar_check(2113) > 0;
                o.shiki = jw_cmd_bar_check(2115) > 0;
                o.lat = lb && *lb ? atof(lb) : 36.0;
                if (o.lat < -1e-6)
                    o.lat = 0.0;
                if (o.lat > 55.0)
                    o.lat = 55.0;
                if (o.lat > 46.0)
                    o.sun_n15 = 1;      /* 緯度 46° 超えは 9～15時 に強制（天空図にも及ぶ、hk_s24） */
                o.dec = -23.45;
                if (sb && (!strcmp(sb, "1") || !strcmp(sb, "\x8f\x74\x8f\x48\x95\xaa")))
                    o.dec = 0.0;
                else if (sb && (!strcmp(sb, "2") || !strcmp(sb, "\x89\xc4\x8e\x8a")))
                    o.dec = 23.45;
                else if (sb && (!strcmp(sb, "3") || !strcmp(sb, "\x94\x43\x88\xd3\x8e\x9e\x8a\xfa")))
                    o.dec = hk_dec_user;
                /* 真北（旗 0x40・色 5 の数の字）。無ければ 原典は「真北が設定されていません。」に
                   OK で 上向き（0°）扱い（hk_s5）。問いは この上で出してある（tn_nq） */
                (void)k;
                tn_north_of(d, &north);
                o.north = north;
                /* 南方向補正 のときは 建物も 真北 で回る（FUN_00733e40、原典 hk_s18: 真北 −90 で
                   箱が右へ）。補正なしでは建物は回らず、太陽軌跡と方位の字が回る（hk_s21）。
                   太陽軌跡 なしでは 真北 は効かない（hk_s20） */
                if (o.mirror)
                    o.mirror_off = north * 3.14159265358979323846 / 180.0;
            }
            if (tn_sansha) {
                hk_sansha_opts so;
                const char *md = jw_cmd_box(2210);

                hk_sansha_opts_default(&so);
                so.t = o;
                /* 三斜 の半径は バーの字「天空図半径(R) = 100」で 100 に決まっている
                   （箱 1493 は無い。原典 hk_sa1〜sa3） */
                so.t.R = 100.0;
                if (md && *md && atof(md) > 0.0)
                    so.maxdiv = atof(md);
                /* 点と「No.n」は 測定点表示 の箱 (2216) があるときだけ（hk_sa1: 何も出ない） */
                if (o.show_point)
                    snprintf(so.name, sizeof so.name, "No.%d", o.number);
                else
                    so.name[0] = 0;
                hk_sansha_opts_set_mode(&so, tn_s_plan);   /* 初めは《計画建物用》 */
                so.calc = tn_s_calc;
                so.conf = tn_s_conf;   /* 三斜計算。切なら円と投影の線だけ（hk_sa1） */
                r = jw_tenku_sansha_draw_ex(d, &so, tn_px, tn_py, px, py, NULL);            } else
                r = jw_tenku_draw(d, &o, tn_px, tn_py, px, py, NULL);
            if (r >= 0) {
                tn_count++;
                if (o.show_point) {
                    /* 描いたあと 測定点表示 の番号は一つ進む（原典: 3 → 4、hk_s12） */
                    char nb[16];

                    snprintf(nb, sizeof nb, "%d", o.number + 1);
                    box_put(2216, nb);
                }
                if (rec)
                    rec->n = d->ndrawn - n0;
            }
            tn_mode = 1;
        }
        return;
    }
    if ((current == JW_CMD_HIKAGE || current == JW_CMD_TENKU) && hk_north && d && button <= 1) {
        hk_north_set(d, v, x, y, button);
        return;
    }
    if ((current == JW_CMD_25D || current == JW_CMD_HIKAGE || current == JW_CMD_TENKU) && button == 0 && d) {
        /* ２．５D の (L) 設定・変更: 線の端に「高さ , 奥行」の文字（色 5・旗 0x8000）を
           置く。原典の答え p197_h1。同じ端をもう一度押すと文字を置き換える */
        int i = -1, k, near = -1;
        double ex, ey, dx0, dy0, best = 1e99, tol = jw_pick_tol(v);
        const char *val = jw_cmd_box(1491);     /* 箱が無ければ 原典の初めの値 */

        /* いちばん近い線（線分までの距離が 許容の内）を自分で探す */
        for (k = 0; k < d->ndrawn; k++) {
            const jw_obj *o = &d->obj[k];
            double ax = o->d[0], ay = o->d[1], bx = o->d[2] - ax, by = o->d[3] - ay;
            double l2 = bx * bx + by * by, t, px, py, e;

            if (o->cls != JW_SEN)
                continue;
            t = l2 > 0.0 ? ((x - ax) * bx + (y - ay) * by) / l2 : 0.0;
            t = t < 0.0 ? 0.0 : t > 1.0 ? 1.0 : t;
            px = ax + t * bx - x;
            py = ay + t * by - y;
            e = sqrt(px * px + py * py);
            if (e <= tol && e < best) {
                best = e;
                i = k;
            }
        }
        {
            static char ht[96];

            if (current == JW_CMD_HIKAGE || current == JW_CMD_TENKU)
                hk_height_text(ht, sizeof ht, val && *val ? val : "10", 0);
            else
                hk_height_text(ht, sizeof ht, val && *val ? val : "10 , 0", 1);
            val = ht;
        }
        if (i < 0 || d->obj[i].cls != JW_SEN)
            return;
        dx0 = x - d->obj[i].d[0];
        dy0 = y - d->obj[i].d[1];
        if (dx0 * dx0 + dy0 * dy0 <=
            (x - d->obj[i].d[2]) * (x - d->obj[i].d[2]) +
            (y - d->obj[i].d[3]) * (y - d->obj[i].d[3]) + 0.02) {
            ex = d->obj[i].d[0];
            ey = d->obj[i].d[1];
        } else {
            ex = d->obj[i].d[2];
            ey = d->obj[i].d[3];
        }
        for (k = 0; k < d->ndrawn; k++)
            if (d->obj[k].cls == JW_MOJI && (d->obj[k].flags & 0x8080) &&
                fabs(d->obj[k].d[0] - ex) < 1e-6 && fabs(d->obj[k].d[1] - ey) < 1e-6)
                near = k;
        if (near >= 0) {                /* 同じ端の文字は 消して 新しく（末尾に）置く */
            op_t *rec = op_new();

            erase(d, near, rec);
            if (rec)
                rec->n = 1;
            near = -1;
        }
        if (near < 0) {
            jw_obj *o = jw_add(d, JW_MOJI);

            if (!o)
                return;
            o->color = current == JW_CMD_HIKAGE || current == JW_CMD_TENKU ? 4 : 5;
            o->ltype = 1;
            o->flags = current == JW_CMD_HIKAGE || current == JW_CMD_TENKU ? 0x80 : 0x8000;
            o->d[0] = ex;
            o->d[1] = ey;
            o->d[3] = ey;
            o->d[4] = o->d[5] = 2.5;
            o->face = jw_add_str(d, JW_MOJI_FACE);
            near = d->ndrawn - 1;
            op_push(1);
        }
        {
            double w = 0.0;
            const char *q;

            d->obj[near].text = jw_add_str(d, val);
            for (q = val; *q; q++)
                w += 1.25;              /* 半角は 文字幅の半分 */
            {
                /* 文字は 押した側の端から もう一方の端のほうへ 線に沿って走る（spec_hikage 1.1） */
                const jw_obj *ln = &d->obj[i];
                int at0 = fabs(ln->d[0] - ex) < 1e-9 && fabs(ln->d[1] - ey) < 1e-9;
                double ox = at0 ? ln->d[2] : ln->d[0], oy = at0 ? ln->d[3] : ln->d[1];
                double ux = ox - ex, uy = oy - ey, l = sqrt(ux * ux + uy * uy);

                if (l > 1e-9) {
                    ux /= l;
                    uy /= l;
                } else {
                    ux = 1.0;
                    uy = 0.0;
                }
                d->obj[near].d[2] = ex + w * ux;
                d->obj[near].d[3] = ey + w * uy;
                {
                    /* 原典の角度: 線の向き p0→p1 の角度。押した端が p1 なら 180° 戻す（0 以上は −180） */
                    double a0 = atan2(ln->d[3] - ln->d[1], ln->d[2] - ln->d[0]) * 180.0 / PI;

                    if (!at0)
                        a0 = a0 >= 0.0 ? a0 - 180.0 : a0 + 180.0;
                    d->obj[near].d[7] = fabs(a0) < 1e-9 ? 0.0 : a0;
                }
            }
        }
        return;
    }
    if (current == JW_CMD_AUTO) {
        /* AUTOモード: 何もないところは 線（始点→終点）。原典の言うとおり
           「(L)free：＋／○ ， 線：線編集  (R)Read：＋／○ ， 線：複線 ， 無：□」
           R で線を押すと 複線、R で何も読めなければ 矩形、になり、それが終わると AUTO に
           戻る（tools/probe196）。L で線を押したときの 線編集（部分消し・コーナー・
           線伸縮）は未実装 */
        if (d && step == 0 && au_st == 0 && button == 1) {
            double sxr, syr;

            if (jw_read(d, v, x, y, &sxr, &syr)) {
                /* R で点が読めれば ＋: 読んだ点から線を引き始める（au_r5） */
                current = JW_CMD_SEN;
                jw_cmd_point_(d, v, sxr, syr, 0);
                current = JW_CMD_AUTO;
                return;
            }
        }
        if (d && step == 0 && au_edit(d, v, x, y, button))
            return;
        if (step == 0 && d) {
            int i = jw_pick(d, v, x, y, 3);
            double sxr, syr;

            if (i >= 0 && d->obj[i].cls == JW_SEN && button == 1) {
                current = JW_CMD_FUKUSEN;
                para_step = 0;
                auto_back = 1;
                jw_cmd_point(d, v, x, y, 0);
                return;
            }
            if (button == 1 && !jw_read(d, v, x, y, &sxr, &syr)) {
                current = JW_CMD_KUKEI;
                step = 0;
                auto_back = 1;
                jw_cmd_point(d, v, x, y, 0);
                return;
            }
        }
        current = JW_CMD_SEN;
        jw_cmd_point_(d, v, x, y, button);
        current = JW_CMD_AUTO;
        return;
    }
    if (get_mode && get_click(d, v, x, y, button))
        return;
    if (read_mode == 33028 && d) {
        /* 円周1/4点取得: the nearest of the picked circle's four quarter
           points.  Driving the original bears it out -- a read near 0 gave
           (75, -30) and one near 90 (60, -15) on the r=15 circle centred at
           (60, -30), which is decomp/res/snapmore.jww. */
        int i = jw_pick(d, v, x, y, 1);
        double qx, qy;

        if (i < 0 || !arc_quarter(&d->obj[i], x, y, &qx, &qy))
            return;                     /* nothing to read: no point placed */
        x = qx;
        y = qy;
        button = 0;
        read_mode = 0;
    }
    if (read_mode == 33017 && d) {
        /* 線上点・交点取得: the first click picks a line or a circle -- the
           prompt then reads 「■■線上点指示■■ (L)free (R)Read <<交点>>
           (L)他の線・円」 -- and the next point lands on it: at right angles
           for a line, straight out from the centre for a circle (a read
           beside the r=15 circle at (60,-30) came back exactly 15 away from
           it, along the line from the centre to where it was clicked).

           The second click is CSunpouZukeiKa's slot 20, FUN_0076fae0
           (逆コンパイルの読み、原典では押していない).  (L) is its case 5:
           a line or a circle under the click (FUN_0044a270 mode 3) that is
           not the same line or the same circle over again is crossed with
           the first by FUN_0045fa30 -- line and line, line and arc, arc and
           arc, the crossing nearer the click -- and the crossing is the
           point.  (R) is case 6: the read point (FUN_00451f30), and with
           nothing to read nothing happens and the line stays picked.
           Either way the point then goes onto the first element
           (FUN_0045b6c0: the foot on a line, on an arc FUN_0045b790's point
           of the ellipse at the click's angle). */
        const jw_obj *o;
        double px = x, py = y;
        int had = read_pick;

        if (read_pick < 0) {
            int i = jw_pick(d, v, x, y, 1);

            if (i < 0 || (d->obj[i].cls != JW_SEN
                          && d->obj[i].cls != JW_ENKO))
                return;
            read_pick = i;
            return;
        }
        o = &d->obj[had];
        if (button != 0) {
            if (!jw_read(d, v, x, y, &px, &py))
                return;
        } else {
            /* 《交点》: a second line or circle under the click wins over
               the foot.  Driving the original bears it out for two lines --
               crossing at (-3.463557, 37.233236) and a click on the second
               gave exactly that (decomp/res/snapcross.jww). */
            int j = jw_pick(d, v, x, y, 1);

            if (j >= 0 && j != had && (d->obj[j].cls == JW_SEN || d->obj[j].cls == JW_ENKO)) {
                const jw_obj *q = &d->obj[j];
                double ix, iy;
                int got = 0;

                if (o->cls == JW_SEN && q->cls == JW_SEN) {
                    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
                    double ex = q->d[2] - q->d[0], ey = q->d[3] - q->d[1];
                    double den = dx * ey - dy * ex;

                    if (den != 0.0) {
                        double u = ((q->d[0] - o->d[0]) * ey
                                    - (q->d[1] - o->d[1]) * ex) / den;

                        ix = o->d[0] + u * dx;
                        iy = o->d[1] + u * dy;
                        got = 1;
                    }
                } else if (o->cls == JW_SEN) {
                    got = corner_line_arc(o, q, x, y, &ix, &iy);
                } else if (q->cls == JW_SEN) {
                    got = corner_line_arc(q, o, x, y, &ix, &iy);
                } else if (!(fabs(o->d[0] - q->d[0]) <= 1e-07 && fabs(o->d[1] - q->d[1]) <= 1e-07
                             && fabs(o->d[2] - q->d[2]) <= 1e-07
                             && fabs(o->d[6] - q->d[6]) <= 1e-07
                             && (fabs(1.0 - o->d[6]) <= 1e-07
                                 || fabs(o->d[5] - q->d[5]) <= 1e-07))) {
                    got = corner_arc_arc(o, q, x, y, &ix, &iy);
                }
                if (got) {
                    px = ix;
                    py = iy;
                }
            }
        }
        if (o->cls == JW_SEN) {
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = dx * dx + dy * dy, t;

            read_pick = -1;
            read_mode = 0;
            if (len <= 0.0)
                return;
            t = ((px - o->d[0]) * dx + (py - o->d[1]) * dy) / len;
            x = o->d[0] + t * dx;
            y = o->d[1] + t * dy;
        } else {
            double f = o->d[6] > 0.0 ? o->d[6] : 1.0;

            read_pick = -1;
            read_mode = 0;
            if (fabs(px - o->d[0]) + fabs(py - o->d[1]) < 1e-07 || o->d[2] < 1e-07 || f < 1e-07)
                return;         /* FUN_0045b790 gives up: no point */
            corner_foot(o, &px, &py);
            x = px;
            y = py;
        }
        button = 0;
    }
    if (read_mode == 33016 && d) {
        int i = jw_pick(d, v, x, y, 1);
        double mx, my;

        if (i >= 0 && obj_middle(&d->obj[i], &mx, &my)) {
            x = mx;
            y = my;
            button = 0;         /* the point is settled: no reading on top */
            read_mode = 0;
            read_a = 0;
        } else {
            /* 読取点指示で２点間中心: two read points, and the middle of
               them is the point.  Nothing to read means nothing happens. */
            double rx, ry;

            if (!jw_read(d, v, x, y, &rx, &ry))
                return;
            if (!read_a) {
                read_ax = rx;
                read_ay = ry;
                read_a = 1;
                return;
            }
            x = (read_ax + rx) / 2.0;
            y = (read_ay + ry) / 2.0;
            button = 0;
            read_mode = 0;
            read_a = 0;
        }
    }
    if (current == JW_CMD_KYORITEN) {
        double rx = x, ry = y, dx, dy, len, mm;

        if (button != 0 && !jw_read(d, v, x, y, &rx, &ry))
            return;
        if (!kyo_step) {
            kyo_x = rx;
            kyo_y = ry;
            kyo_step = 1;
            return;
        }
        kyo_step = 0;
        if (!d)
            return;
        dx = rx - kyo_x;
        dy = ry - kyo_y;
        len = sqrt(dx * dx + dy * dy);
        mm = box_mm(d, 1412);
        if (len <= 0.0 || mm <= 0.0)
            return;
        {
            jw_obj *o = jw_add(d, JW_TEN);

            if (o) {
                o->d[0] = kyo_x + dx / len * mm;
                o->d[1] = kyo_y + dy / len * mm;
                o->n = jw_cmd_bar_check(1323) > 0;      /* 仮点 */
                op_push(1);
            }
        }
        return;
    }
    if (current == JW_CMD_SOKUTEI) {
        double rx = x, ry = y;

        sok_esc = 0;

        if (sok_write) {
            /* 測定結果書込: the click says where the number goes.  文字種
               2's size, the writing pen, and the click at its left foot
               (decomp/res/sokutei_write.jww). */
            char t[64];
            jw_obj *o;
            double w, h, tw;
            const char *q;

            sok_write = 0;
            if (!d)
                return;
            sok_value(t, (int)sizeof t, d, sok_total);
            w = d->style[1].w > 0.0 ? d->style[1].w : 2.5;
            h = d->style[1].h > 0.0 ? d->style[1].h : 2.5;
            tw = 0.0;
            for (q = t; *q; ) {
                int wide = (unsigned char)*q >= 0x81;

                tw += wide ? w : w / 2.0;
                q += wide ? 2 : 1;
            }
            o = jw_add(d, JW_MOJI);
            if (!o)
                return;
            o->ltype = 1;
            o->color = (unsigned short)(d->write_color ? d->write_color : 1);
            o->flags = (unsigned short)(o->flags | 0x4000u);
            o->d[0] = rx;
            o->d[1] = ry;
            o->d[2] = rx + tw;
            o->d[3] = ry;
            o->d[4] = w;
            o->d[5] = h;
            o->d[6] = d->style[1].sp;
            o->d[7] = 0.0;
            o->n = 2;                   /* 文字種 2 */
            o->text = jw_add_str(d, t);
            o->face = jw_add_str(d, JW_MOJI_FACE);
            op_push(1);
            return;
        }
        if (sok_one) {
            /* ○単独円指定: one circle, and its way round goes into the
               total (src/cmd.c's 測定 note) */
            int i = d ? jw_pick(d, v, x, y, 1) : -1;

            if (i < 0 || d->obj[i].cls != JW_ENKO)
                return;
            sok_seg = 2.0 * PI * d->obj[i].d[2];
            sok_total += sok_seg;
            sok_one = 0;
            tail_set(4, sok_total, sok_seg);
            return;
        }
        if (button != 0 && !jw_read(d, v, x, y, &rx, &ry))
            return;                     /* (R) with nothing to read */
        if (sok_mode == SOK_XY) {
            /* 座標測定 only ever wants the origin; after that it is the
               cursor that is read out */
            sok_x0 = rx;
            sok_y0 = ry;
            sok_n = 1;
            tail_set(4, 0.0, 0.0);
            return;
        }
        if (sok_mode == SOK_ANG) {
            /* 原点 → 基準点 → 角度点 */
            if (sok_n == 0) {
                sok_x0 = rx;
                sok_y0 = ry;
                sok_n = 1;
                /* while it asks for the 基準点 the original shows no
                   readout at all (tools/probe129.sh) */
                tail_set(0, 0.0, 0.0);
                return;
            }
            if (sok_n == 1) {
                sok_px = rx;
                sok_py = ry;
                sok_n = 2;
                /* and from here it follows the mouse.  The port has no
                   live angle to show, so it reads out the last one. */
                tail_set(4, sok_total, 0.0);
                return;
            }
            sok_total = (atan2(ry - sok_y0, rx - sok_x0)
                         - atan2(sok_py - sok_y0, sok_px - sok_x0))
                        * 180.0 / PI;
            while (sok_total > 180.0)
                sok_total -= 360.0;
            while (sok_total <= -180.0)
                sok_total += 360.0;
            sok_n = 0;                  /* and it asks for an origin again */
            tail_set(4, sok_total, 0.0);
            return;
        }
        if (!sok_n) {
            sok_x0 = rx;
            sok_y0 = ry;
            /* nothing was added, and the original reads that out as -0 --
               unless a circle has already put something in the total, and
               then the readout stays on that (tools/probe142.sh) */
            if (sok_total == 0.0)
                sok_seg = -0.0;
        } else if (sok_mode == SOK_AREA) {
            /* the triangle 始点・前の点・いまの点, with the screen's
               y-down sign -- which makes this walk positive and the
               closing step -0 */
            sok_seg = -((sok_px - sok_x0) * (ry - sok_y0)
                        - (rx - sok_x0) * (sok_py - sok_y0)) / 2.0;
            sok_total += sok_seg;
        } else {
            double dx = rx - sok_px, dy = ry - sok_py;

            sok_seg = sqrt(dx * dx + dy * dy);
            sok_total += sok_seg;
        }
        if (sok_n < SOK_MAX) {
            sok_rx[sok_n] = rx;
            sok_ry[sok_n] = ry;
        }
        sok_px = rx;
        sok_py = ry;
        sok_n++;
        tail_set(4, sok_total, sok_seg);
        return;
    }
    if (current == JW_CMD_HOURAKU) {
        if (hou_step == 0) {
            if (button != 0)    /* the first corner is the left button's */
                return;
            hou_x = x;
            hou_y = y;
            hou_step = 1;
            return;
        }
        /* (L) welds what the box holds, (R) rubs it out */
        houraku(d, x, y, button != 0);
        hou_step = 0;
        return;
    }
    if (current == JW_CMD_TAKAKU && tk_any && tk_pickmode && d && button <= 1) {
        tk_pick_solid(d, v, x, y, button);
        return;
    }
    if (current == JW_CMD_TAKAKU) {
        if (button == 0 && d)
            takaku(d, x, y);
        return;
    }
    if (current == JW_CMD_SUNPO) {
        double rx, ry;
        if (!d)
            return;
        if (ika_step) {
            double a = sun_angle() * PI / 180.0;
            double ux = cos(a), uy = sin(a), vx = -uy, vy = ux;
            double tl = sun_lx * vx + sun_ly * vy;
            double px, py;
            int k;

            if (ika_step == 3 && button == 0) {
                /* 追加・除外: the line this hits comes in if it is out
                   and goes out if it is in */
                int t = jw_pick(d, v, x, y, 3);
                const jw_obj *o;
                double e1, e2;

                if (t < 0 || d->obj[t].cls != JW_SEN
                    || ika_ntog >= (int)(sizeof ika_tog / sizeof ika_tog[0]))
                    return;
                o = &d->obj[t];
                e1 = o->d[0] * vx + o->d[1] * vy - tl;
                e2 = o->d[2] * vx + o->d[3] * vy - tl;
                if (e1 < 0.0)
                    e1 = -e1;
                if (e2 < 0.0)
                    e2 = -e2;
                px = e1 <= e2 ? o->d[0] : o->d[2];
                py = e1 <= e2 ? o->d[1] : o->d[3];
                ika_tog[ika_ntog++] = px * ux + py * uy;
                return;
            }
            if (ika_step == 3) {
                if (button == 0)
                    return;
                ika_run(d);
                /* and round again at the 始線 prompt, which is where
                   the original goes: tools/probe45.sh read 5391 back
                   after the (R), not the plain dimension's own line */
                ika_step = 1;
                ika_ntog = 0;
                ika_lt = -1;
                return;
            }
            k = jw_pick(d, v, x, y, 3);
            if (k < 0 || d->obj[k].cls != JW_SEN)
                return;
            {
                const jw_obj *o = &d->obj[k];
                double e1 = o->d[0] * vx + o->d[1] * vy - tl;
                double e2 = o->d[2] * vx + o->d[3] * vy - tl;
                if (e1 < 0.0)
                    e1 = -e1;
                if (e2 < 0.0)
                    e2 = -e2;
                px = e1 <= e2 ? o->d[0] : o->d[2];
                py = e1 <= e2 ? o->d[1] : o->d[3];
            }
            if (button != 0)    /* (R): 同一線種選択 */
                ika_lt = d->obj[k].ltype;
            if (ika_step == 1) {
                ika_s0 = px * ux + py * uy;
                ika_ax = x;
                ika_ay = y;
                ika_step = 2;
            } else {
                ika_s1 = px * ux + py * uy;
                ika_bx = x;
                ika_by = y;
                ika_step = 3;
            }
            return;
        }
        if (sun_radius) {
            sunpo_radius(d, v, x, y);
            return;
        }
        if (sun_chi) {
            /* 寸法値: two points, and the value alone goes between them.
               (L) is free, (R) reads, the same as everywhere else. */
            /* CZukeiSunpo slot 9 (FUN_0077fda0): 寸法値 (+0x1c4 == 0x19) の
               一点目・二点目は、(R) で読んだ点でなければ **左でも**
               FUN_00451eb0（点に吸着できたか）が 0 を返して捨てられます */
            if (!jw_read(d, v, x, y, &x, &y))
                return;
            if (sun_step != 6) {
                sun_sx = x;
                sun_sy = y;
                sun_step = 6;
                return;
            }
            sunpo_value(d, sun_sx, sun_sy, x, y);
            sun_chi_done = 1;
            sun_step = 5;
            return;
        }
        if (sun_step == 4) {
            /* 角度 asks for the origin before anything else */
            if (button != 0 && !jw_read(d, v, x, y, &x, &y))
                return;
            sun_ox = x;
            sun_oy = y;
            sun_step = 0;
            return;
        }
        if (sun_step == 7) {
            /* 円周 asks for a circle, and takes its middle and its
               radius; from there it is 角度's walk exactly */
            int k = jw_pick(d, v, x, y, 6);
            if (k < 0 || d->obj[k].cls != JW_ENKO
                || d->obj[k].d[2] <= 0.0)
                return;
            sun_ox = d->obj[k].d[0];
            sun_oy = d->obj[k].d[1];
            sun_er = d->obj[k].d[2];
            sun_step = 0;
            return;
        }
        if (sun_step < 2) {
            /* (L) is where it was clicked, (R) reads a point */
            if (button != 0 && !jw_read(d, v, x, y, &x, &y))
                return;
            if (sun_step == 0) {
                sun_hx = x;
                sun_hy = y;
            } else {
                sun_lx = x;
                sun_ly = y;
            }
            sun_step++;
            return;
        }
        /* the two measured points have to be read ones */
        if (!jw_read(d, v, x, y, &rx, &ry))
            return;
        if (sun_step == 2) {
            sun_sx = rx;
            sun_sy = ry;
            sun_step = 3;
            sun_made = 0;
            return;
        }
        if (sun_kaku || sun_enshu)
            sunpo_angle(d, rx, ry);
        else
            sunpo_make(d, rx, ry);
        sun_step = 2;           /* ready for the next one */
        sun_made = 1;
        return;
    }
    if (range_cmd(current)) {
        switch (sel_step) {
        case 0:
            if (button != 0) {  /* (R): 連続線 (sel_rpick) */
                if (sel_rpick(d, v, x, y, !sel_keep)) {
                    sel_keep = 0;
                    sel_sub = 0;
                    sel_step = 2;
                }
                return;
            }
            if (!sel_keep)      /* 追加範囲・除外範囲 keep what is picked */
                sel_clear(d);
            sel_keep = 0;
            sel_x0 = sel_x1 = x;
            sel_y0 = sel_y1 = y;
            sel_step = 1;
            return;
        case 1:
            sel_x1 = x;
            sel_y1 = y;
            sel_box(d, button != 0);
            sel_sub = 0;
            sel_step = 2;       /* a box that caught nothing stays in the stage */
            return;
        case 2: {
            if (sel_base_pick) {
                sel_base_pick = 0;
                sel_base_set = 1;
                sel_base_px = x;
                sel_base_py = y;
                return;
            }
            {
            /* 追加・除外図形指示: (L) a line, circle or point, (R) a text,
               is added if it was not picked and taken away if it was.  A
               click on nothing does nothing -- two of them do not make a
               box either (tools/stageprobe.sh c3 c4 c5 c6); more boxes come
               from 追加範囲 and 除外範囲. */
            int k;

            if (!d)
                return;
            k = jw_pick(d, v, x, y, 0);
            if (k < 0 || k >= d->ndrawn
                || (d->obj[k].cls == JW_MOJI) != (button != 0))
                return;
            if (d->obj[k].sel) {
                d->obj[k].flags = (unsigned short)(d->obj[k].flags & ~2u);
                d->obj[k].sel = 0;
            } else {
                d->obj[k].flags = (unsigned short)(d->obj[k].flags | 2u);
                d->obj[k].sel = 1;
            }
            return;
            }
        }
        default:
            if (current == JW_CMD_PARAM) {
                param_click(d, v, x, y, button);
                return;
            }
            if (button != 0)
                return;
            if (current == JW_CMD_ZUKEIREG) {
                /* 図形登録: the point after 選択確定 is the 基準点, and
                   that is where the original puts its file window up */
                fig_base_x = x;
                fig_base_y = y;
                fig_base_new = 1;
                return;
            }
            if (sel_base_wait) {
                /* 基点変更: this click is the 基準点, not a place to put it */
                base_x = x;
                base_y = y;
                sel_base_wait = 0;
                return;
            }
            if (sel_flip) {
                int i = jw_pick(d, v, x, y, 3);

                if (i < 0 || d->obj[i].cls != JW_SEN)
                    return;     /* 基準線を指示してください */
                sel_mirror(d, &d->obj[i]);
                sel_flip = 0;
                return;
            }
            sel_place(d, x, y);
            return;
        }
    }
    if (current == JW_CMD_MOJI && txt_n > 0) {
        /* 文読: the lines go down from the click, 行間 apart */
        const char *as = jw_cmd_box(1411);
        double a = as && *as ? box_num(as, 0.0) * PI / 180.0
                 : jw_cmd_bar_check(1324) > 0 ? PI / 2.0 : 0.0;
        double vx = -sin(a), vy = cos(a), pitch = txt_pitch();
        int k, made = 0, was = line_n;
        char keep[sizeof line_buf];

        if (button != 0 || !d)
            return;
        memcpy(keep, line_buf, sizeof keep);
        for (k = 0; k < txt_n; k++) {
            jw_obj tmp, *o;

            line_n = (int)strlen(txt_line[k]);
            if (line_n > (int)sizeof line_buf - 2) {
                /* cut on a character, not through one */
                int at = 0;

                while (at < line_n) {
                    int w = jw_is_lead((unsigned char)txt_line[k][at])
                            && at + 1 < line_n ? 2 : 1;

                    if (at + w > (int)sizeof line_buf - 2)
                        break;
                    at += w;
                }
                line_n = at;
            }
            memcpy(line_buf, txt_line[k], (size_t)line_n);
            /* moji() keeps the pool offset of the last string it was given
               and only puts a new one in when line_gen moves, so every
               line has to move it */
            line_gen++;
            if (!line_n)
                continue;
            if (!moji(d, &tmp, x - k * pitch * vx, y - k * pitch * vy))
                continue;
            made += moji_rule(d, &tmp);
            o = jw_add(d, JW_MOJI);
            if (!o)
                break;
            tmp.layer = o->layer;
            tmp.lgroup = o->lgroup;
            *o = tmp;
            o->face = jw_add_str(d, JW_MOJI_FACE);
            made++;
        }
        memcpy(line_buf, keep, sizeof line_buf);
        line_n = was;
        txt_n = 0;
        op_push(made);
        return;
    }
    if (current == JW_CMD_MOJI && ren_step) {
        /* 連 (1068): 連結 and 切断 -- see the note by ren_join above */
        /* mode 0 is the only one that looks at texts at all --
           src/pick.c runs its second pass for modes under 1 */
        int k = jw_pick(d, v, x, y, 0);

        if (!d)
            return;
        if (ren_step == 3) {        /* where the one picked with (LL) goes */
            ren_move_to(d, ren_first, x, y);
            ren_step = 1;
            return;
        }
        if (ren_step == 1) {
            if (k < 0 || d->obj[k].cls != JW_MOJI)
                return;
            if (button != 0) {                  /* (R): 文字切断位置指示 */
                ren_cut(d, k, x, y);
                return;
            }
            ren_first = k;
            ren_step = 2;
            return;
        }
        if (k < 0 || d->obj[k].cls != JW_MOJI)
            return;
        /* (L) moves the one just picked on to the first, (R) copies it */
        ren_join(d, ren_first, k, button != 0);
        ren_step = 1;
        return;
    }
    if (current == JW_CMD_MOJI) {
        /* Place what has been typed.  Everything about the text comes from
         * the drawing's current style, which sits just after the ten in the
         * header: the size, the spacing and the colour.  A text placed in
         * Jw_cad has exactly those, and the run is as long as the characters
         * make it -- half width ones advance cw/2 and the gaps are sp/2, and
         * the last gap is not counted (six of them at cw 10 sp 1 came to
         * 32.5, not 30). */
        if (button == 0 && d && line_n == 0 && moji_pre_on) {
            moji_pre = 1;               /* 2466: the place first, the text after */
            moji_pre_x = x;
            moji_pre_y = y;
            return;
        }
        if (d && moji_got && line_n > 0) {
            /* 次のクリックが置く位置: (L) は free、(R) は点を読む
               （FUN_006c7ae0 は FUN_00451eb0 で読めたときだけ 9 番へ渡す） */
            double rx = x, ry = y;

            if (button != 0 && !jw_read(d, v, x, y, &rx, &ry))
                return;
            moji_got_place(d, rx, ry);
            return;
        }
        if (d && line_n == 0) {
            moji_got = moji_got_all = 0;
            moji_got_pick(d, v, x, y, button);
            return;
        }
        if (button != 0 || !d || line_n == 0)
            return;
        moji_place(d, x, y);
        return;
    }
    if (current == JW_CMD_ZOKUHEN) {
        /* 属性変更 (0x80b8).  「変更するデータを指示してください。 線・円・
         * 実点(L) 文字(R)」 -- one click on one element, no range and no
         * button: the earlier note here had it as unresolved because it was
         * tried by confirming a range first.
         *
         * What it does is give that element the write pen, line type and
         * layer, and **move it to the end of the drawing**: the original's
         * saved file has the changed line last, with everything after it
         * shifted up one.  The bar's two ticks say which halves to apply --
         * 線種・文字種変更 (1352) and 書込みレイヤに変更 (1353), both on when
         * the command is entered.
         */
        int i;

        if (!d)
            return;
        /* (R) picks a text the way the original's slot 11 (FUN_0067b6d0)
           does, with FUN_004500e0 -- jw_pick's mode 1 has no text pass at
           all, so the right button never found one */
        i = button ? jw_pick_moji(d, v, x, y) : jw_pick(d, v, x, y, 3);
        if (i < 0)
            return;
        if (button != 0) {
            if (d->obj[i].cls != JW_MOJI)
                return;         /* (R) is for texts */
        } else if (d->obj[i].cls == JW_MOJI) {
            return;             /* and (L) for everything else */
        }
        zoku_change(d, i);
        return;
    }
    if (current == JW_CMD_ZOKUSEI) {
        /* Take the pen and the layer off an element and make them the ones
         * new elements get.  Driving Jw_cad bears both out: after 属性取得 on
         * a line of type 6 on layer 0, a 複線 came out type 6 on layer 0
         * where before it was type 1 on layer 10. */
        int i;
        if (button != 0 || !d)
            return;             /* (R) turns the layer display round */
        i = jw_pick(d, v, x, y, 0);
        if (i < 0)
            return;
        d->write_ltype = d->obj[i].ltype ? d->obj[i].ltype : 1;
        d->write_color = d->obj[i].color;
        d->write_width = d->obj[i].width;
        {   /* and the write layer, which is the group's own */
            int g = d->obj[i].lgroup & 15, k;
            for (k = 0; k < 16; k++)
                if (d->group[k].state == 3 && k != g)
                    d->group[k].state = 2;
            d->group[g].state = 3;
            d->group[g].write_layer = d->obj[i].layer & 15;
            for (k = 0; k < 16; k++)
                if (d->group[g].layer[k].state == 3)
                    d->group[g].layer[k].state = 2;
            d->group[g].layer[d->group[g].write_layer].state = 3;
        }
        return;
    }
    if (current == JW_CMD_FUKUSEN) {
        /* Three clicks: the line, then which side and how far, then one more
         * to draw it.  That third click only confirms -- moving it further
         * out in Jw_cad does not move the copy, which stays where the second
         * click put it.  The copy is a new element with the write pen on the
         * write layer, not a clone: offsetting a dashed line on layer 0 in
         * Test1 gave a plain one on the write layer. */
        int i;
        if (!d)
            return;
        if (fk_ten == 3 || fk_ten == 2) {
            /* 端点指定の 始点・終点（slot 9 の +0x284 の枝。(R) は slot 11 が点を読んでから
               slot 9 を呼ぶ）。どの段でも これが先 */
            double px = x, py = y;

            if (button == 1) {
                if (!jw_read(d, v, x, y, &px, &py))
                    return;
            } else if (button != 0)
                return;
            if (fk_ten == 2 && hypot(px - fk_tp[0], py - fk_tp[1]) < 1e-7)
                return;         /* 始点と同じ点は受けない（原典は 0x14df を出す） */
            fk_tp[fk_ten == 3 ? 0 : 2] = px;
            fk_tp[fk_ten == 3 ? 1 : 3] = py;
            fk_ten--;
            return;
        }
        if (button == 1 && para_step == 0 && !fk_selmode) {
            /* (R) 前回値: 拾い方は (L) と同じ（FUN_00657f10）。箱に数があるか、この命令で
               もう写していれば その間隔で すぐ「作図する方向を指示」 */
            double prev = box_mm(d, 1411);

            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || (d->obj[i].cls != JW_SEN
                          && !(d->obj[i].cls == JW_ENKO
                               && fabs(d->obj[i].d[6] - 1.0) < 1e-9)))
                return;
            para_obj = i;
            para_step = 1;
            fk_rprev = prev > 0.0 ? prev : fk_prev;
            return;
        }
        if (button != 0)
            return;
        if (para_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || (d->obj[i].cls != JW_SEN
                          && !(d->obj[i].cls == JW_ENKO
                               && fabs(d->obj[i].d[6] - 1.0) < 1e-9))) {
                return;
            }
            para_obj = i;
            para_step = 1;
            fk_rprev = 0.0;
            return;
        }
        if (para_step == 1 && fk_selmode) {
            fk_selmode = 0;
            para_step = 0;
            para_obj = -1;
            fukusen_selected(d, x, y);
            return;
        }
        if (para_step == 1 && d->obj[para_obj].cls == JW_ENKO) {
            /* a circle or arc is offset concentrically: the click says
               inside or out, and how far */
            const jw_obj *o = &d->obj[para_obj];
            double typed = 0.0;
            para_off = sqrt((x - o->d[0]) * (x - o->d[0])
                            + (y - o->d[1]) * (y - o->d[1])) - o->d[2];
            if (jw_cmd_get_kankaku(&typed))
                have_kan = 0;
            else
                typed = box_mm(d, 1411);
            if (typed <= 0.0 && fk_rprev > 0.0)
                typed = fk_rprev;       /* (R) 前回値 */
            if (typed <= 0.0) {
                para_step = 2;
                return;
            }
            para_off = para_off < 0.0 ? -typed : typed;
        }
        else if (para_step == 1) {
            const jw_obj *o = &d->obj[para_obj];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = sqrt(dx * dx + dy * dy);
            if (len < 1e-09) {
                para_step = 0;
                return;
            }
            para_off = ((x - o->d[0]) * -dy + (y - o->d[1]) * dx) / len;
            {   /* 複線間隔 (1411): with a number in the box the click only
                 * says which side, and the copy goes exactly that far.  The
                 * original's own three stages are 「複線にする図形を選択」
                 * 「間隔を入力するか、複写する位置」「作図する方向を指示」,
                 * and typing the number there takes it straight to the
                 * third -- so a typed offset is two clicks, not three.
                 * 1000 on a 1/200 group put the copy 5 mm out. */
                /* and 間隔取得 (32948) leaves a number in the same place:
                 * taking one and then clicking a side put the copy
                 * exactly that far out, three times over
                 * (decomp/res/kankaku_*.jww, tools/probe92.sh).  It
                 * **beats the box**: a run with 50 typed into 1411 and
                 * then 164.28 taken copied by 164.28 (tools/probe93.sh).
                 * That is the other way round from 長さ取得, where the
                 * typed box wins -- but there the box was typed after the
                 * grab and here before it, so what has really been
                 * measured both times may be「last one in wins」.  The
                 * other order has not been asked.
                 *
                 * It is good for **one copy**: picking a second line in
                 * the same command put the 「間隔を入力するか」 question
                 * back and wanted the extra click again
                 * (tools/probe94.sh). */
                double typed = 0.0;
                if (jw_cmd_get_kankaku(&typed))
                    have_kan = 0;       /* one copy, and it is spent */
                else
                    typed = box_mm(d, 1411);
                if (typed <= 0.0 && fk_rprev > 0.0)
                    typed = fk_rprev;   /* (R) 前回値 */
                if (typed <= 0.0) {
                    para_step = 2;
                    return;
                }
                para_off = para_off < 0.0 ? -typed : typed;
            }
            /* and with one, this click was the direction: fall through */
        }
        else if (para_step == 2 && d->obj[para_obj].cls == JW_SEN) {
            /* 「作図する方向を指示」で数が箱に入っていれば その大きさで、向きはこの
               クリックの側（fuzz s7_63: 位置を指したあとに 500 を打って方向を指した） */
            const jw_obj *o = &d->obj[para_obj];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = sqrt(dx * dx + dy * dy);
            double typed = box_mm(d, 1411);

            if (len > 1e-09 && typed > 0.0) {
                double side = ((x - o->d[0]) * -dy + (y - o->d[1]) * dx) / len;

                para_off = side < 0.0 ? -typed : typed;
            }
        }
        para_step = 0;
        {
            int ten = fk_ten == 1;      /* slot 3 は写すと +0x284 を 0 に */

            fk_ten = 0;
            fk_rprev = 0.0;
            fk_prev = fabs(para_off);
            if (para_obj >= 0 && para_obj < d->ndrawn
                && d->obj[para_obj].cls == JW_ENKO) {
                jw_obj src = d->obj[para_obj];
                jw_obj *o;
                if (src.d[2] + para_off < 1e-9)
                    return;
                o = jw_add(d, JW_ENKO);
                if (!o)
                    return;
                {
                    jw_obj *keep = o;
                    double r = src.d[2] + para_off;
                    int k;
                    for (k = 0; k < 8; k++)
                        keep->d[k] = src.d[k];
                    keep->d[2] = r;
                }
                fk_finish(d, o);
                return;
            }
            if (para_obj >= 0 && para_obj < d->ndrawn
                && d->obj[para_obj].cls == JW_SEN) {
                jw_obj src = d->obj[para_obj];
                double dx = src.d[2] - src.d[0], dy = src.d[3] - src.d[1];
                double len = sqrt(dx * dx + dy * dy);
                jw_obj *o;
                if (len < 1e-09)
                    return;
                o = jw_add(d, JW_SEN);
                if (!o)
                    return;
                o->d[0] = src.d[0] + -dy / len * para_off;
                o->d[1] = src.d[1] + dx / len * para_off;
                o->d[2] = src.d[2] + -dy / len * para_off;
                o->d[3] = src.d[3] + dx / len * para_off;
                if (ten) {
                    /* 端点指定: 二点を写しの線へ垂直に落として 端にする (FUN_0065a340) */
                    double ux = dx / len, uy = dy / len;
                    double ox = o->d[0], oy = o->d[1];
                    double t0 = (fk_tp[0] - ox) * ux + (fk_tp[1] - oy) * uy;
                    double t1 = (fk_tp[2] - ox) * ux + (fk_tp[3] - oy) * uy;

                    o->d[0] = ox + ux * t0;
                    o->d[1] = oy + uy * t0;
                    o->d[2] = ox + ux * t1;
                    o->d[3] = oy + uy * t1;
                }
                fk_finish(d, o);
            }
        }
        return;
    }
    if (current == JW_CMD_SHINSHUKU) {
        /* Pick a line, then say where its end should go.  Which end moves is
         * settled by the second point, not the first: clicking the left half
         * of a line in Jw_cad and then a point past its right end moves the
         * right end.  The point is dropped on to the line first, the same
         * way a partial erase drops its two.  A tie goes to the first end.
         *
         * The right button (CZukeiShinshuku's slot 11, FUN_00719580) reads
         * the point while a line is picked, and otherwise only notes the
         * element under it (+0x210 = 6, prompt 0x14db): moving the mouse
         * more than 2 pixels then cuts it there (slot 6, FUN_00715f50 →
         * FUN_00470200, cut_gap_at; jw_cmd_stretch_move), and the right
         * again before that -- wherever it lands; the pick is made at the
         * first point -- makes it the 基準線 (FUN_00717650 in state 3).  A
         * left meanwhile does nothing (FUN_00718e60's first arm).  The port
         * may miss the move, so a press more than 2 pixels away is taken
         * as having moved first.  With a 基準線 held (states 3 and 4,
         * prompt 0x14d9) a left on a line stretches it to where it meets
         * the 基準線 and the 基準線 stays (FUN_0071a050 → FUN_0046e550);
         * the right then cuts, or changes the 基準線.  Read off the
         * decompile, not asked of the original. */
        int i;
        if (!d)
            return;
        if (stretch_rwait) {
            if (stretch_far(v, x, y)) {
                stretch_rwait = 0;      /* it moved: 線切断 at the first point */
                cut_gap_at(d, v, stretch_rx, stretch_ry);
            } else if (button != 0) {
                stretch_rwait = 0;      /* (RR): the 基準線, picked at the first point */
                stretch_step = 0;
                stretch_based = 0;
                i = jw_pick(d, v, stretch_rx, stretch_ry, 3);
                if (i >= 0 && (d->obj[i].cls == JW_SEN || d->obj[i].cls == JW_ENKO)) {
                    stretch_base = d->obj[i];
                    stretch_bx = stretch_rx;
                    stretch_by = stretch_ry;
                    stretch_based = 1;
                }
                return;
            } else {
                return;
            }
        }
        if (button != 0) {
            double rx, ry;

            if (stretch_step == 0) {
                if (jw_pick(d, v, x, y, 3) < 0)
                    return;
                stretch_rwait = 1;
                stretch_rx = x;
                stretch_ry = y;
                return;
            }
            if (!jw_read(d, v, x, y, &rx, &ry))
                return;
            x = rx;             /* and on as the left would (FUN_00718e60) */
            y = ry;
        }
        if (stretch_based) {
            i = jw_pick(d, v, x, y, 3);
            if (i >= 0 && d->obj[i].cls == JW_SEN)
                stretch_to_base(d, i, x, y);
            return;
        }
        if (stretch_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            stretch_obj = i;
            {
                jw_obj *q = &d->obj[i];
                double ex = q->d[2] - q->d[0], ey = q->d[3] - q->d[1];
                double l2 = ex * ex + ey * ey;
                stretch_t0 = l2 > 1e-14 ? ((x - q->d[0]) * ex + (y - q->d[1]) * ey) / l2 : 0;
            }
            stretch_step = 1;
            return;
        }
        stretch_step = 0;
        i = stretch_obj;
        if (i >= 0 && i < d->ndrawn && d->obj[i].cls == JW_SEN)
            stretch_end(d, i, stretch_t0, x, y, stretch_out(d));
        return;
    }
    if (current == JW_CMD_CHUSHIN) {
        int i;
        if (!d)
            return;
        if (button != 0) {
            /* (R): a point read in place of a line, and the two ends
               read too (FUN_0063ef60 reads with FUN_00451eb0 whichever
               step it is) */
            double rx, ry, px, py, ux, uy;

            if (!jw_read(d, v, x, y, &rx, &ry))
                return;
            if (chu_step == 0) {
                chu_a = CHU_PT;
                chu_ax = rx;
                chu_ay = ry;
                chu_step = 1;
            } else if (chu_step == 1) {
                int was = chu_b;
                double wx = chu_bx, wy = chu_by;

                if (chu_a == CHU_PT && fabs(rx - chu_ax) < 1e-7 && fabs(ry - chu_ay) < 1e-7)
                    return;     /* the same point twice: 0x14df */
                chu_b = CHU_PT;
                chu_bx = rx;
                chu_by = ry;
                if (!chushin_line(d, &px, &py, &ux, &uy)) {
                    chu_b = was;  /* no middle: 0x1455, and it waits on */
                    chu_bx = wx;
                    chu_by = wy;
                    return;
                }
                chu_step = 2;
            } else if (chu_step == 2) {
                chu_x = rx;
                chu_y = ry;
                chu_step = 3;
            } else {
                chushin(d, rx, ry);
                chu_step = 2;
            }
            return;
        }
        if (chu_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || !chu_takes(&d->obj[i]))
                return;
            chu_a = i;
            chu_ax = x;
            chu_ay = y;
            chu_step = 1;
            return;
        }
        if (chu_step == 1) {
            double px, py, ux, uy;

            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == chu_a || !chu_takes(&d->obj[i]))
                return;
            chu_b = i;
            chu_bx = x;
            chu_by = y;
            if (!chushin_line(d, &px, &py, &ux, &uy)
                && (d->obj[i].cls != JW_SEN || chu_a == CHU_PT || d->obj[chu_a].cls != JW_SEN)) {
                chu_b = -1;     /* no middle (0x1455): it waits on */
                return;
            }
            chu_step = 2;
            return;
        }
        if (chu_step == 2) {
            chu_x = x;
            chu_y = y;
            chu_step = 3;
            return;
        }
        chushin(d, x, y);
        chu_step = 2;           /* the same middle, another line */
        return;
    }
    if (current == JW_CMD_HATCH) {
        int i;

        if (ht_sel && d) {
            /* the same two-corner box the 範囲 commands use */
            if (ht_sel == 1 || ht_sel == 3) {
                if (button != 0) {
                    /* (R): 連続線, as 範囲選択's (sel_rpick); the hatch
                       then takes the closed rings among what is picked */
                    if (sel_rpick(d, v, x, y, ht_sel == 1))
                        ht_sel = jw_cmd_sel_count(d) > 0 ? 3 : 1;
                    return;
                }
                if (ht_sel == 1)
                    sel_clear(d);
                sel_x0 = sel_x1 = x;
                sel_y0 = sel_y1 = y;
                ht_sel = 2;
                return;
            }
            sel_x1 = x;
            sel_y1 = y;
            sel_box(d, button != 0);
            ht_sel = jw_cmd_sel_count(d) > 0 ? 3 : 1;
            return;
        }
        if (ht_base_wait && d) {
            ht_bx = x;
            ht_by = y;
            ht_base = 1;
            ht_base_wait = 0;
            return;
        }
        if (!d)
            return;
        i = jw_pick(d, v, x, y, 3);
        if (i < 0)
            return;
        if (button != 1) {
            /* (L) adds to the chain, and one that is in it already closes
               the ring */
            int k;

            if (d->obj[i].cls != JW_SEN)
                return;
            for (k = 0; k < ht_nchain; k++)
                if (ht_chain[k] == i)
                    break;
            if (k < ht_nchain) {
                hatch_chain(d);
                ht_nchain = 0;
                return;
            }
            if (ht_nchain < HT_CHAIN)
                ht_chain[ht_nchain++] = i;
            return;
        }
        if (d->obj[i].cls == JW_ENKO) {
            ht_n = 0;
            ht_nreg = 0;
            hatch_circle(&d->obj[i]);
        } else if (d->obj[i].cls == JW_SEN) {
            if (!hatch_ring(d, i)) {
                ht_n = 0;
                ht_nreg = 0;
            }
        }
        return;
    }
    if (current == JW_CMD_KYOKUSEN) {
        if (button > 1 || !d)
            return;
        /* (R)Read: CZukeiKyokuSen の右 FUN_006b5740 は、サイン・２次で基準線を
           拾う段（[0xac] が 1）だけ左 FUN_006b4690 をそのまま呼び、ほかは
           FUN_00451eb0 で読めた点を左に渡す（読めなければ何もしない）。
           逆コンパイルの読み、原典では押していない */
        if (button == 1 && !((cv_mode == 1689 || cv_mode == 1690) && !cv_base)) {
            double rx, ry;

            if (!jw_read(d, v, x, y, &rx, &ry))
                return;
            x = rx;
            y = ry;
        }
        if (cv_mode == 1689 || cv_mode == 1690) {
            curve_point(d, v, x, y);
            return;
        }
        if (cv_n < CV_MAX) {
            cv_x[cv_n] = x;
            cv_y[cv_n] = y;
            cv_n++;
        }
        return;
    }
    if (current == JW_CMD_SEKIEN) {
        /* (R) reads a point in place of an element, 「読取点をﾏｳｽ(R)で」
           (FUN_007078e0 -> FUN_00707a50: the element is left null and the
           read point kept; nothing read, nothing happens).  With a radius
           the right button also places the circle, by the cursor, once a
           point is there to be read. */
        int i = -1, pt = button != 0;
        double rx = x, ry = y;

        if (!d)
            return;
        if (pt && !jw_read(d, v, x, y, &rx, &ry))
            return;
        if (sek_step == 0) {
            if (!pt) {
                i = jw_pick(d, v, x, y, 3);
                if (i < 0
                    || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                    return;
            }
            sek_a = i;
            sek_apt = pt;
            sek_ax = rx;
            sek_ay = ry;
            sek_step = 1;
            return;
        }
        if (sek_step == 1) {
            if (!pt) {
                i = jw_pick_tie(d, v, x, y, 3, 1);
                if (i < 0 || i == sek_a
                    || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                    return;
            }
            /* with a radius, a pair that leaves no place is turned away
               then and there: the left button waits for another second,
               the right one starts over (FUN_00707130 / FUN_00707a50) */
            if (sek_radius(d) > 0.0 && sek_count(d, i, pt, rx, ry) < 1) {
                if (pt) {
                    sek_step = 0;
                    sek_a = sek_b = -1;
                }
                return;
            }
            sek_b = i;
            sek_bpt = pt;
            sek_bx = rx;
            sek_by = ry;
            sek_step = 2;
            return;
        }
        if (sek_radius(d) <= 0.0) {
            /* an empty 半径: the third element settles it, and it is drawn
               the moment that is picked */
            if (!pt) {
                i = jw_pick_tie(d, v, x, y, 3, 1);
                if (i < 0 || (!sek_apt && i == sek_a)
                    || (!sek_bpt && i == sek_b))
                    return;
            }
            sekien3(d, i, pt, rx, ry);
        } else {
            sekien(d, x, y);
        }
        sek_step = 0;                   /* ready for the next pair */
        sek_a = sek_b = -1;
        return;
    }
    if (current == JW_CMD_SESSEN) {
        int i;
        /* (R): CZukeiSessen の右 FUN_00704680 は、円を拾う段（+0xb4 が
           0・1・2）では左 FUN_00703f90 をそのまま呼び、点の段では
           FUN_00451eb0 で読めた点を左に渡す（読めなければ何もしない）。
           逆コンパイルの読み、原典では押していない */
        if (button > 1 || !d)
            return;
        if (ses_mode == 1691 || ses_mode == 1692) {
            if (button != 0)
                return;
            sesline(d, v, x, y);
            return;
        }
        if (ses_mode == 1690) {         /* 点→円: the point, then the circle */
            if (ses_step == 0) {
                if (button == 1) {      /* (R)Read */
                    double rx, ry;

                    if (!jw_read(d, v, x, y, &rx, &ry))
                        return;
                    x = rx;
                    y = ry;
                }
                ses_x = x;
                ses_y = y;
                ses_step = 1;
                return;
            }
            i = jw_pick(d, v, x, y, 3);
            if (i >= 0 && d->obj[i].cls == JW_ENKO)
                tensen(d, i, ses_x, ses_y, x, y);
            ses_step = 0;
            return;
        }
        if (ses_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_ENKO)
                return;
            ses_a = i;
            ses_x = x;          /* the side of this circle that was pointed at */
            ses_y = y;
            ses_step = 1;
            return;
        }
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != ses_a && d->obj[i].cls == JW_ENKO)
            sessen(d, ses_a, i, x, y);
        ses_step = 0;           /* ready for the next pair */
        ses_a = -1;
        return;
    }
    if (current == JW_CMD_NISEN) {
        int i;
        double rx, ry;

        if ((button != 0 && button != 1) || !d)
            return;
        if (button == 1) {
            /* (R)Read（案内 5401/5402）。原典 CZukei2Sen の右 (slot 11,
               FUN_00626b20) は始点・終点のとき 6・7 に移り、マウスが動いて
               から slot 6 (FUN_006236b0) が FUN_00451eb0 で点を読む。読めな
               ければ元の状態のまま、読めればその点を始点・終点に。基準線
               待ち (state 1) では読んだ点で左 (FUN_00625680) を呼ぶ。
               逆コンパイルの読み、原典では押していない。 */
            if (!jw_read(d, v, x, y, &rx, &ry))
                return;
            x = rx;
            y = ry;
        }
        if (nisen_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN || !nisen_gap(d))
                return;
            nisen_obj = i;
            nisen_step = 1;
            return;
        }
        if (nisen_step == 1) {
            nisen_x = x;
            nisen_y = y;
            nisen_step = 2;
            return;
        }
        if (nisen_obj >= 0 && nisen_obj < d->nobj)
            nisen(d, x, y, 0);
        nisen_step = 0;         /* ready for the next line to run along */
        nisen_obj = -1;
        nisen_chain = 0;
        return;
    }
    if (current == JW_CMD_BUNKATSU) {
        int i;
        double rx, ry;

        if (!d)
            return;
        if (corner_step == 0 && bk_rr_n > 0) {
            /* 連続点分割の途中（string 5819/5820「次点指示 (L)free (R)Read
               同一点指示で終了」）。(L) はその位置そのもの（原典 FUN_00764910）、
               (R) は読めた点（FUN_00765710、読めなければ何もしない）。2 点
               以上あって直前の点と同じ点（FUN_00436970、1e-7）なら閉じて
               分割する。でなければ点を足す（個数 < 2001 の間だけ増え、
               それ以上は最後の点を置き換える）。同じ点でも 1 点目のときは
               閉じずに足す（原典の枝のとおり）。
               (RR) の右ダブルクリックで連続線を拾う枝（DAT_00a0cc70==1、
               FUN_00410380）もあるが、10.03.6 の機械語にはこの旗を 1 にする
               書き込みが一つも無く（0 を書く 5 か所だけ）、tools/jwdraw.ps1 の
               RR でも何も起きなかったので写さない。 */
            double px = x, py = y;

            if (button == 1) {
                if (!jw_read(d, v, x, y, &rx, &ry))
                    return;
                px = rx;
                py = ry;
            } else if (button != 0) {
                return;
            }
            if (bk_rr_n > 1 && fabs(py - bk_rr_y[bk_rr_n]) < 1e-7
                && fabs(px - bk_rr_x[bk_rr_n]) < 1e-7) {
                bk_rr_finish(d);
                return;
            }
            if (bk_rr_n < BK_RR_MAX)
                bk_rr_n++;
            bk_rr_x[bk_rr_n] = px;
            bk_rr_y[bk_rr_n] = py;
            return;
        }
        if (corner_step == 0) {
            if (button == 0) {
                /* 線・円（Ａ）指示 ﾏｳｽ(L)（string 5357。線だけだったのを
                   円にも広げる） */
                i = jw_pick(d, v, x, y, 3);
                if (i < 0 || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                    return;
                corner_obj = i;
                corner_x = x;
                corner_y = y;
                bk_a_enko = d->obj[i].cls == JW_ENKO;
                bk_gyaku = bk_senchou = 0;      /* FUN_00764910: Ａを指すと戻る */
                corner_step = 1;
                return;
            }
            if (button == 1) {
                /* 分割始点指示 ﾏｳｽ(R)（string 5357。点だけに効く ── 線の端・
                   CDataTen・交点の jw_read、円周 1/4 点は原典で試して拾わな
                   かった） */
                if (!jw_read(d, v, x, y, &rx, &ry))
                    return;
                bk_px = rx;
                bk_py = ry;
                corner_obj = -1;
                corner_step = 1;
            }
            return;
        }
        if (corner_step == 1) {
            if (corner_obj >= 0) {
                /* 線・円（Ａ）済み: 線【B】／円【B】指示 ﾏｳｽ(L)（同じ種類、
                   string 5358/5359）か 分割終点指示 ﾏｳｽ(R)（点 E、
                   「E から A への同じ扇」） */
                if (button == 0) {
                    i = jw_pick_tie(d, v, x, y, 3, 1);
                    if (i >= 0 && i != corner_obj
                        && d->obj[i].cls == d->obj[corner_obj].cls) {
                        if (d->obj[corner_obj].cls == JW_SEN) {
                            if (bk_waritsuke_on())      /* 割付 */
                                waritsuke(d, corner_obj, i, corner_x, corner_y, x, y);
                            else
                                bunkatsu(d, corner_obj, i, corner_x, corner_y, x, y);
                        } else {
                            bk_circle_fan(d, corner_obj, i);
                        }
                    }
                    bk_gyaku = bk_senchou = 0;  /* FUN_007668f0 の終わり */
                    corner_step = 0;
                    return;
                }
                if (button == 1) {
                    if (!jw_read(d, v, x, y, &rx, &ry))
                        return;
                    if (d->obj[corner_obj].cls == JW_SEN)
                        bk_fan_from_line(d, corner_obj, rx, ry);
                    else
                        bk_circle_lerp(d, &d->obj[corner_obj], 0.0, 0.0, 0, rx, ry);
                    corner_step = 0;
                }
                return;
            }
            /* 始点 Ｐ 済み: 線・円【B】指示 ﾏｳｽ(L)、分割終点指示 ﾏｳｽ(R)（点）、
               円全周分割 ﾏｳｽ(R)（円そのものを指示、string 5361） */
            if (button == 0) {
                i = jw_pick(d, v, x, y, 3);
                if (i < 0)
                    return;
                if (d->obj[i].cls == JW_SEN)
                    bk_fan_line(d, bk_px, bk_py, i);
                else if (d->obj[i].cls == JW_ENKO)
                    bk_fan_circle_pt(d, bk_px, bk_py, i);
                else
                    return;
                corner_step = 0;
                return;
            }
            if (button == 1) {
                /* 点が拾えればそれを第二点に（円の上の CDataTen も、こちら
                   が勝つ ── tools/jwdraw.ps1 実測、2026-10-13: 円の上に置いた
                   点を踏むと ２点間分割 の方へ進んだ）。何も読めなければ
                   円そのものかどうかを見て 円全周分割。 */
                if (jw_read(d, v, x, y, &rx, &ry)) {
                    if (fabs(ry - bk_py) < 1e-7 && fabs(rx - bk_px) < 1e-7) {
                        /* 始点と同じ点をもう一度 (R) ── 連続点分割 (RR) に入る
                           （原典 FUN_00765710 state 2: FUN_00436970(+0x100, 点) が
                           真なら +0x138=1・点 1 に控えて state 0。tools/bkprobe.sh
                           で (R)(R) のあと (L) を足すと 5820 が出るのを実測） */
                        bk_rr_n = 1;
                        bk_rr_x[1] = rx;
                        bk_rr_y[1] = ry;
                        corner_step = 0;
                        return;
                    }
                    bk_p2x = rx;
                    bk_p2y = ry;
                    corner_step = 2;
                    return;
                }
                i = jw_pick(d, v, x, y, 3);
                if (i >= 0 && d->obj[i].cls == JW_ENKO) {
                    bk_full_circle(d, bk_px, bk_py, i, x, y);
                    corner_step = 0;
                }
                /* 何も拾えない (R) は 何もしない（始点はそのまま、ファジング s23_6） */
            }
            return;
        }
        if (corner_step == 2) {
            /* 始点＋第二点 済み（状態 3、string 5360）: 分割する線・円を
               指示 ﾏｳｽ(L) か ２点間分割 ﾏｳｽ(R) */
            if (button == 0) {
                i = jw_pick(d, v, x, y, 3);
                if (i < 0)
                    return;
                if (d->obj[i].cls == JW_SEN)
                    bk_two_point_line(d, bk_px, bk_py, bk_p2x, bk_p2y, i);
                else if (d->obj[i].cls == JW_ENKO)
                    bk_two_point_circle(d, bk_px, bk_py, bk_p2x, bk_p2y, i, x, y);
                else
                    return;
                corner_step = 0;
                return;
            }
            if (button == 1) {
                bk_two_point_plain(d, bk_px, bk_py, bk_p2x, bk_p2y);
                corner_step = 0;
            }
            return;
        }
        return;
    }
    if (current == JW_CMD_KIGOU) {
        const jw_senkigou *sg = sk_cat >= 0 ? jw_sk_load(sk_cat) : 0;
        const jw_sk_item *it;
        int i;

        if (!d || !sg || sk_item < 0 || sk_item >= sg->nitem || button > 1)
            return;
        it = &sg->item[sk_item];
        if (sk_step == 4) {
            /* (L) 確定。打った文字（なければスキップ）で次の文字の行へ。
               (R) 文字貼付は まだ */
            char typed[sizeof line_buf + 1];
            int made;

            if (button != 0)
                return;
            memcpy(typed, line_buf, (size_t)line_n);
            typed[line_n] = 0;
            made = jw_sk_input(d, sg, &sk_run, typed);
            if (sk_op_at >= 0 && sk_op_at < nop)
                op[sk_op_at].n += made;
            line_n = 0;
            line_gen++;
            if (!sk_run.active) {
                sk_step = 0;
                sk_chain(sg);
            }
            sk_goto_cmd();
            return;
        }
        if (sk_step == 0 && it->need_l1) {
            if (button != 0)
                return;
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            sk_o1 = i;
            sk_c1x = x;
            sk_c1y = y;
            if (it->need_l2)
                sk_step = 1;
            else if (it->pointers >= 1)
                sk_step = 2;
            else {
                sk_step = 0;
                sk_place(d);
            }
            return;
        }
        if (sk_step == 1) {
            if (button != 0)
                return;
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == sk_o1 || d->obj[i].cls != JW_SEN)
                return;
            sk_o2 = i;
            sk_c2x = x;
            sk_c2y = y;
            sk_step = 0;
            sk_place(d);
            return;
        }
        if (button == 1) {      /* (R)Read: 読める点に吸わせる */
            double sxr, syr;

            if (!jw_read(d, v, x, y, &sxr, &syr))
                return;
            x = sxr;
            y = syr;
        }
        if (sk_step == 3) {
            sk_c1x = x;
            sk_c1y = y;
            sk_step = 0;
            sk_place(d);
            return;
        }
        sk_px = x;
        sk_py = y;
        if (it->mouse && !it->need_l1) {
            sk_step = 3;
            return;
        }
        sk_step = 0;
        sk_place(d);
        return;
    }
    if (TG_IS3(current)) {
        if (!d || tg_cat < 0 || button > 1)
            return;
        if (button == 1) {      /* (R)Read: 読める点に吸わせる。なければ何も起きない */
            double sxr, syr;

            if (!jw_read(d, v, x, y, &sxr, &syr))
                return;
            x = sxr;
            y = syr;
        }
        tg_place3(d, x, y);
        return;
    }
    if (TG_IS(current)) {
        int i;
        if (!d || tg_cat < 0)
            return;
        if (tg_step == 0 && button == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            if (tg_wall(d->obj[i].d[0], d->obj[i].d[1], d->obj[i].d[2],
                        d->obj[i].d[3]))
                tg_step = 1;
            return;
        }
        if (tg_step == 0) {             /* (R): 二点間の始点 */
            tg_ax = x;
            tg_ay = y;
            tg_step = 2;
            return;
        }
        if (tg_step == 2) {             /* 二点目 */
            if (tg_wall(tg_ax, tg_ay, x, y))
                tg_step = 1;
            else
                tg_step = 0;
            return;
        }
        tg_place(d, x, y);              /* 位置 */
        tg_step = 0;
        return;
    }
    if (current == JW_CMD_MENTORI) {
        int i;
        if (!d)
            return;
        if (button != 0) {
            /* (R) 線切断 -- コーナーと同じ FUN_00636ee0。幅は 面取 のバーの
               切断間隔 1413（実寸 2096）。逆コンパイルの読み、原典では押していない */
            line_cut_r(d, v, x, y, 1413);
            return;
        }
        if (corner_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            corner_obj = i;
            corner_x = x;
            corner_y = y;
            corner_step = 2;
            return;
        }
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != corner_obj)
            mentori(d, corner_obj, corner_x, corner_y, i, x, y);
        corner_step = 0;
        return;
    }
    if (current == JW_CMD_CORNER) {
        int i;
        if (!d)
            return;
        if (button != 0) {
            /* (R) 線切断 (CZukeiCorner's slot 11, FUN_00636ee0 -- read off
               the decompile, not asked of the original): the line or arc
               under the click is cut there, a 切断間隔 wide.  The width is
               the bar's 1411 (FUN_004cacd0 → DAT_00a0cc58), on the paper,
               or in real size over the write group's scale when 実寸 (2096)
               is ticked; FUN_00471e40 / FUN_004702f0 then take out the
               piece from half the width before the click to half after --
               along a line, across an arc's tangent -- and with no width
               the element is split in two there.  A line picked as the
               first of the corner stays picked. */
            line_cut_r(d, v, x, y, 1411);
            return;
        }
        if (corner_step == 0) {
            /* a line or an arc; a whole circle is refused (FUN_0063aa60,
               string 5207 -- 逆コンパイルの読み、原典では押していない) */
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO)
                || (d->obj[i].cls == JW_ENKO && corner_whole(&d->obj[i])))
                return;
            corner_obj = i;
            corner_x = x;
            corner_y = y;
            corner_step = 2;    /* CZukeiCorner's own numbering */
            return;
        }
        /* the second pick flips view+0x82bc, so a tie goes the other way and
           the same line is not found twice */
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && d->obj[i].cls == JW_ENKO && corner_whole(&d->obj[i]))
            return;             /* refused, 線【A】 stays picked (slot 9's mode 2) */
        if (i >= 0 && i != corner_obj)
            corner(d, corner_obj, corner_x, corner_y, i, x, y);
        corner_step = 0;
        return;
    }
    if (current == JW_CMD_SHOUKYO) {
        /* 「線・円マウス(L)部分消し　図形マウス(R)消去」 -- string 10111,
         * the original's own words, and driving it bears them out: a right
         * click on one side of a rectangle in Jw_cad leaves 49 lines of 50,
         * and that side is the one that goes.  The left button takes a piece
         * out of a line instead, through a three-step selection
         * (CZukeiShoukyo's vtable slot 9, its +0x21c going 0 to 3): the
         * element, then the two ends of the piece -- cut_step below.
         *
         * Which element: the one the highlight would be on, and that is
         * found with FUN_0044a270's mode 0 (CZukeiShoukyo's slot 11, the one
         * that runs as the mouse moves). */
        int i;
        if (!d)
            return;
        if (shk_sel) {
            /* 範囲選択消去: 範囲選択と同じ二点の箱（ハッチの 範囲選択 と同じ形） */
            if (shk_sel == 1 || shk_sel == 3) {
                if (button != 0)
                    return;     /* (R) の連続線選択はしていない */
                if (shk_sel == 1)
                    sel_clear(d);
                sel_x0 = sel_x1 = x;
                sel_y0 = sel_y1 = y;
                shk_sel = 2;
                return;
            }
            sel_x1 = x;
            sel_y1 = y;
            sel_box(d, button != 0);
            shk_sel = jw_cmd_sel_count(d) > 0 ? 3 : 1;
            return;
        }
        if (button == 1) {
            i = jw_pick(d, v, x, y, 0);
            if (i >= 0)
                erase(d, i, op_new());
            cut_step = 0;
            return;
        }
        /* the left button: pick, then the two ends of the piece */
        if (cut_step == 0 && button == 0 && jw_cmd_bar_check(1324) > 0) {
            /* 節間消し: 一手目で実行（FUN_0070f1c0 → FUN_0070fc60 → FUN_00712f00） */
            i = jw_pick(d, v, x, y, 3);
            if (i >= 0)
                setsukan(d, i, x, y);
            return;
        }
        if (cut_step == 0) {
            /* FUN_0070dc20 picks with mode 3, which is the one that leaves
               points alone -- there is no piece of a point to take out. */
            cut_obj = jw_pick(d, v, x, y, 3);
            if (cut_obj >= 0)
                cut_step = 1;
            return;
        }
        if (cut_step == 1) {
            cut_x = x;
            cut_y = y;
            cut_step = 2;
            return;
        }
        if (cut_obj >= 0 && cut_obj < d->ndrawn) {
            if (d->obj[cut_obj].cls == JW_ENKO)
                cut_arc(d, cut_obj, cut_x, cut_y, x, y);
            else
                cut_line(d, cut_obj, cut_x, cut_y, x, y);
        }
        cut_step = 0;
        return;
    }
    if (current == JW_CMD_SEN && jw_cmd_bar_check(1351) > 0) {
        /* 線の ＜ (1351): not a way of drawing a line at all.  Ticking it
         * makes the original say 「線・弧の端部を指示してください。
         * (L)書込線色・線種  (R)寸法設定線色・線種」 (string 5518,
         * which FUN_004efbb0 is handed when the box goes on), so a click
         * picks a line that is already there and puts an arrowhead on the
         * end nearer to it -- 3 long at plus and minus 15 degrees, the same
         * as every other arrow here.
         *
         * This has to come before the read below: that prompt has no
         * (R)Read in it, and the right button here means the dimension pen
         * rather than a point to snap to. */
        int i = d ? jw_pick(d, v, x, y, 3) : -1;
        const jw_obj *o;
        double ax, ay, bx, by, wx, wy, wl, k;

        if (i < 0 || d->obj[i].cls != JW_SEN)
            return;
        o = &d->obj[i];
        if ((x - o->d[0]) * (x - o->d[0]) + (y - o->d[1]) * (y - o->d[1])
            <= (x - o->d[2]) * (x - o->d[2]) + (y - o->d[3]) * (y - o->d[3])) {
            ax = o->d[0]; ay = o->d[1]; bx = o->d[2]; by = o->d[3];
        } else {
            ax = o->d[2]; ay = o->d[3]; bx = o->d[0]; by = o->d[1];
        }
        /* the legs run from the tip towards the other end, the way every
           arrowhead here does -- read off the original's own drawing */
        wx = bx - ax;
        wy = by - ay;
        wl = sqrt(wx * wx + wy * wy);
        if (wl <= 0.0)
            return;
        wx /= wl;
        wy /= wl;
        for (k = 1.0; k >= -1.0; k -= 2.0) {
            double a = k * sun_yaang * PI / 180.0;
            double ca = cos(a), sa = sin(a);
            jw_obj *n = jw_add(d, JW_SEN);
            if (!n)
                break;
            if (button != 0) {          /* (R) uses the dimension pen */
                n->color = sun_sencol;
                n->ltype = 1;
            }
            n->d[0] = ax;
            n->d[1] = ay;
            n->d[2] = ax + sun_yalen * (wx * ca - wy * sa);
            n->d[3] = ay + sun_yalen * (wx * sa + wy * ca);
        }
        op_push(2);
        return;
    }
    if (button == 1) {
        /* Every prompt ends "(L)free  (R)Read": the right button takes the
         * nearest read point instead of where the mouse is, and when there
         * is nothing to read the click does nothing at all -- Jw_cad places
         * no point either (右クリックを端点から 11 画素離すと何も起きない). */
        double sxr, syr;
        if (!d || !jw_read(d, v, x, y, &sxr, &syr))
            return;
        x = sxr;
        y = syr;
    }
    if (current == JW_CMD_ZUKEI) {
        /* 図形読込: the figure hangs on the cursor and a point puts it
           down.  It stays on it, so another point puts down another. */
        figure_place(d, x, y);
        return;
    }
    if (current == JW_CMD_TEN) {
        /* CZukeiTen の slot 9 (FUN_00732730) は三つに分かれます ——
           +0x140 が立っていれば 仮点消去、+0x148 が立っていれば 交点
           （その中で +0x148 が 1 と 2 を行き来して（Ａ）【Ｂ】を拾い、
           拾えなければ **0 を返して段を進めません**）、どちらでも
           なければ点を置く。 */
        if (!d)
            return;
        if (ten_del) {                  /* 仮点消去 */
            int i = pick_kariten(d, v, x, y);

            if (i >= 0)
                erase(d, i, op_new());
            return;
        }
        if (ten_cross) {                /* 交点 */
            int i = jw_pick(d, v, x, y, 3);

            if (i < 0 || (d->obj[i].cls != JW_SEN
                          && d->obj[i].cls != JW_ENKO))
                return;                 /* 拾えなければ段は進みません */
            if (ten_cross == 1) {
                ten_a = i;
                ten_cross = 2;
                return;
            }
            if (ten_a >= 0 && ten_a < d->ndrawn && ten_a != i) {
                double cx, cy;

                if (cross_point(d, ten_a, i, x, y, &cx, &cy)) {
                    jw_obj *o = jw_add(d, JW_TEN);

                    if (o) {
                        o->d[0] = cx;
                        o->d[1] = cy;
                        o->n = 0;       /* 交点に落ちるのは実点 */
                        op_push(1);
                    }
                }
            }
            ten_a = -1;
            ten_cross = 1;
            return;
        }
        {
            jw_obj *o = jw_add(d, JW_TEN);

            if (o) {
                o->d[0] = x;
                o->d[1] = y;
                /* 1323 仮点 を押していれば kind=1 -- 原典に訊いた値 */
                o->n = jw_cmd_bar_check(1323) > 0 ? 1 : 0;
                op_push(1);
            }
        }
        return;
    }
    if (current == JW_CMD_RENZOKU && jw_cmd_bar_check(2492) > 0) {
        /* 連続弧: three points make the first arc, and each
         * click after that adds one that leaves the last tangentially
         * and ends where the click is.  Clicking the same point again
         * ends the chain, which is what the prompt says.
         *
         * The original was given (300,300) (400,250) (500,300) and then
         * (600,350), and wrote two arcs of radius 76.5306: the first
         * through the three points, the second from the first's end
         * through the fourth point, leaving along the same tangent and
         * curving the other way (decomp/res/renarc_*.jww,
         * tools/probe100.sh).
         *
         * Three points in a line have not been asked, so nothing is
         * laid for them and the chain goes on. */
        if (!d)
            return;
        ra_commit(d);
        if (ra_step == 0) {
            ra_jx = x;
            ra_jy = y;
            ra_step = 1;
            ra_have = 0;
        } else if (ra_step == 1) {
            ra_mx = x;
            ra_my = y;
            ra_step = 2;
        } else if (fabs(x - ra_jx) < 1e-9 && fabs(y - ra_jy) < 1e-9) {
            ra_step = 0;        /* the same point again: that is the end */
            ra_flip = 0;        /* slot 4 (FUN_006db060) が +0x460 も落とす */
        } else if (!ra_have) {
            double cx, cy;

            if (three_circle(ra_jx, ra_jy, ra_mx, ra_my, x, y, &cx, &cy)) {
                double a0 = atan2(ra_jy - cy, ra_jx - cx);
                double am = atan2(ra_my - cy, ra_mx - cx);
                double a1 = atan2(y - cy, x - cx);
                int ccw = turn_pos(am - a0) < turn_pos(a1 - a0);

                if (ren_arc_add(d, cx, cy, ra_jx, ra_jy, x, y, ccw))
                    ra_have = 1;
            }
            ra_jx = x;
            ra_jy = y;
        } else {
            /* the centre is along the old radius, at whatever distance
               brings the circle through the new point */
            double dx = ra_jx - x, dy = ra_jy - y;
            double dot = ra_ux * dx + ra_uy * dy;

            if (fabs(dot) > 1e-12) {
                double t = -(dx * dx + dy * dy) / (2.0 * dot);
                double cx = ra_jx + t * ra_ux, cy = ra_jy + t * ra_uy;
                /* and it must set off the way the last one arrived:
                   going round counter-clockwise, the way out of the
                   start is the radius turned a quarter turn left */
                double vx = -(ra_jy - cy), vy = ra_jx - cx;
                int ccw = vx * ra_dx + vy * ra_dy > 0.0;

                /* 弧反転 (1067): FUN_006dc260 は掃きの向き (+1/-1) を
                   +0x460 が立っていれば裏返し、FUN_0040b250 でその向きへ
                   掃きを寄せ直す —— 中心と両端はそのままで、同じ円の
                   反対回りの弧になる。逆コンパイルの読み、原典では
                   押していない。 */
                if (ra_flip)
                    ccw = !ccw;

                ren_arc_add(d, cx, cy, ra_jx, ra_jy, x, y, ccw);
            }
            ra_jx = x;
            ra_jy = y;
        }
        tx = x;
        ty = y;
        return;
    }
    if (current == JW_CMD_RENZOKU) {
        /* (R) reading the point before the last one puts nothing in (fuzz
           case 14: the last click 4.5 px from the one before it, then R) */
        if (button == 1 && step == 3 && fabs(x - sx) < 1e-9 && fabs(y - sy) < 1e-9)
            return;
        if (step == 0) {
            sx = x;
            sy = y;
            rn_sx = x;
            rn_sy = y;
            step = 2;
        } else if (step == 2) {
            rx = x;
            ry = y;
            step = 3;
        } else {
            if (d) {
                double t = renzoku_edge(d);
                if (t > 0.0) {
                    renzoku_round(d, t, x, y);
                } else {
                    jw_obj *o = jw_add(d, JW_SEN);
                    if (o) {
                        o->d[0] = sx;
                        o->d[1] = sy;
                        o->d[2] = rx;
                        o->d[3] = ry;
                        op_push(1);
                    }
                    rn_sx = rx;
                    rn_sy = ry;
                }
            }
            sx = rx;
            sy = ry;
            rx = x;
            ry = y;
        }
        tx = x;
        ty = y;
        return;
    }
    if (current == JW_CMD_ENKO && jw_cmd_bar_check(1320) > 0
        && jw_cmd_bar_check(1321) <= 0) {  /* CZukeiEnko slot 8: 3点指示 (+0xaf4) が半円 (+0xaf0) に勝つ */
        /* 半円: two clicks give the ends of the diameter and the third says
         * which side it bulges.  The original wrote the centre at their
         * middle, the radius at half their distance, the start at 0, the
         * tilt at the angle of the first click from the centre, and the
         * sweep at +pi or -pi -- the sign following which side the third
         * click was on. */
        if (en_step == 0) {
            sx = x;
            sy = y;
            tx = x;
            ty = y;
            en_step = 1;
            return;
        }
        if (en_step == 1) {
            en_r = x;
            en_a0 = y;
            tx = x;
            ty = y;
            en_step = 2;
            return;
        }
        if (d) {
            double cx = (sx + en_r) / 2.0, cy = (sy + en_a0) / 2.0;
            double ux = sx - cx, uy = sy - cy;
            double r = sqrt(ux * ux + uy * uy);
            double cross = ux * (y - cy) - uy * (x - cx);
            if (r > 0.0) {
                jw_obj *o = jw_add(d, JW_ENKO);
                if (o) {
                    o->d[0] = cx;
                    o->d[1] = cy;
                    o->d[2] = r;
                    o->d[3] = 0.0;
                    o->d[4] = cross >= 0.0 ? PI : -PI;
                    o->d[5] = atan2(uy, ux);
                    o->d[6] = 1.0;
                    o->n = 0;
                    op_push(1);
                }
            }
        }
        en_step = 0;
        tracking = 0;
        return;
    }
    if (current == JW_CMD_ENKO && jw_cmd_bar_check(1321) > 0) {
        /* ３点指示: the circle through three clicked points.  The original,
         * given three, wrote the circle round them -- centre 54.262391,
         * -63.787172 and radius 102.046022 for the three this was read
         * from -- with the start at 0 and a whole turn, like any circle. */
        if (en_step == 0) {
            sx = x;
            sy = y;
            tx = x;
            ty = y;
            en_step = 1;
            esc_3pt = 0;
            return;
        }
        if (en_step == 1) {
            en_r = x;           /* the second point, kept until the third */
            en_a0 = y;
            tx = x;
            ty = y;
            en_step = 2;
            return;
        }
        if (d) {
            double bx = en_r, by = en_a0;
            double ax = sx, ay = sy;
            double d1 = 2.0 * (ax * (by - y) + bx * (y - ay) + x * (ay - by));
            if (d1 != 0.0) {
                double a2 = ax * ax + ay * ay, b2 = bx * bx + by * by;
                double c2 = x * x + y * y;
                double cx = (a2 * (by - y) + b2 * (y - ay) + c2 * (ay - by)) / d1;
                double cy = (a2 * (x - bx) + b2 * (ax - x) + c2 * (bx - ax)) / d1;
                jw_obj *o = jw_add(d, JW_ENKO);
                if (o) {
                    o->d[0] = cx;
                    o->d[1] = cy;
                    o->d[2] = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
                    o->d[3] = 0.0;
                    o->d[4] = 2 * PI;
                    o->d[5] = 0.0;
                    o->d[6] = 1.0;
                    o->n = 1;
                    /* **円弧 (1318) も押してあれば、環ではなく弧**です。
                     * 原典に両方押させて三点を取らせると、一点目から
                     * 二点目までの、三点目を通る側の弧が出ました
                     * （`tools/barsweep.sh`、`decomp/res/bsw_32773_1321.jww`
                     * は中心 59.540816,150.306122・半径 218.085390・
                     * 始角 -2.353713・掃き 0.638538）。 */
                    if (jw_cmd_bar_check(1318) > 0) {
                        double a1 = atan2(ay - cy, ax - cx);
                        double a2a = atan2(by - cy, bx - cx);
                        double a3 = atan2(y - cy, x - cx);
                        double w = a2a - a1, w3 = a3 - a1;

                        while (w <= -PI) w += 2.0 * PI;
                        while (w > PI) w -= 2.0 * PI;
                        while (w3 <= -PI) w3 += 2.0 * PI;
                        while (w3 > PI) w3 -= 2.0 * PI;
                        /* 三点目が挟まっていなければ、反対回り */
                        if ((w > 0.0) != (w3 > 0.0) || fabs(w3) > fabs(w))
                            w += w > 0.0 ? -2.0 * PI : 2.0 * PI;
                        o->d[3] = a1;
                        o->d[4] = w;
                        o->n = 0;       /* 弧は n=0 で出ていました */
                    }
                    op_push(1);
                    esc_3pt = 1;
                }
            }
        }
        en_step = 0;
        tracking = 0;
        return;
    }
    if (current == JW_CMD_ENKO && jw_cmd_bar_check(1318) > 0) {
        /* 円弧: centre, then radius and start, then the end.
         *
         * 扁平率 (1412) and 傾き (1413) work here as they do on a whole
         * circle, and both the start and the sweep are then in the
         * **ellipse's own parameter**, not in the angle on the paper:
         * the original, given 扁平率 0.5 and a drag of (122.24, -61.22)
         * from the centre, wrote a = 173.169 and the start -0.785398,
         * which is atan2(dy/ratio, dx), and then swept in the same
         * parameter (tools/probe57.sh's en_afl, probe59.sh's afl2).
         *
         * **Which way round it goes is the original's own mouse, not
         * its arithmetic.**  Five arcs were asked for and three came
         * back swept the shorter way while two came back the same arc
         * plus or minus a whole turn -- the original tracks the pointer
         * while it waits for the third click and adds up what it sees,
         * and a posted click gives it one jump instead of a path.  The
         * port cannot reproduce a path it was never told, so it takes
         * the shorter way, which is what three of the five did. */
        double ratio = en_ratio(jw_cmd_box(1412));
        double tilt = box_angle(1413);
        double ct = cos(tilt), st = sin(tilt);
        double dx = x - sx, dy = y - sy;
        double u = dx * ct + dy * st;
        double v = (-dx * st + dy * ct) / (ratio > 0.0 ? ratio : 1.0);

        if (en_step == 0) {
            sx = x;
            sy = y;
            tx = x;
            ty = y;
            en_step = 1;
            esc_arc = 0;
            return;
        }
        if (en_step == 1) {
            en_r = sqrt(u * u + v * v);
            en_a0 = atan2(v, u);
            tx = x;
            ty = y;
            if (en_r > 0.0) {
                en_step = 2;
                return;
            }
            en_step = 0;
            return;
        }
        if (d) {
            double a = atan2(v, u) - en_a0;
            jw_obj *o;
            while (a <= -PI)
                a += 2 * PI;
            while (a > PI)
                a -= 2 * PI;
            o = jw_add(d, JW_ENKO);
            if (o) {
                o->d[0] = sx;
                o->d[1] = sy;
                o->d[2] = en_r;
                o->d[3] = en_a0;
                o->d[4] = a;
                o->d[5] = tilt;
                o->d[6] = ratio > 0.0 ? ratio : 1.0;
                o->n = 0;
                en_kihon_shift(&o->d[0], &o->d[1], &o->d[2], dx, dy, u, v,
                               box_mm(d, 1411), ratio > 0.0 ? ratio : 1.0, tilt);
                op_push(1);
                esc_arc = 1;
            }
        }
        en_step = 0;
        tracking = 0;
        return;
    }
    if (current != JW_CMD_SEN && current != JW_CMD_ENKO
        && current != JW_CMD_KUKEI)
        return;
    if (step == 0) {
        sx = x;
        sy = y;
        tx = x;
        ty = y;
        esc_rearm = 0;
        /* One click is a whole circle when its radius is already known, so
           this one falls through to the drawing below instead of waiting
           for a second point. */
        if (!(current == JW_CMD_ENKO && box_mm(d, 1411) > 0.0)) {
            step = 2;
            return;
        }
    }
    if (d) {
        jw_obj tmp[JW_CMD_MAXFIG];
        int n = figure(d, tmp, JW_CMD_MAXFIG, x, y), k, put = 0;
        for (k = 0; k < n; k++) {
            jw_obj *o = jw_add(d, tmp[k].cls);
            int i;
            if (!o)
                break;
            for (i = 0; i < 8; i++)
                o->d[i] = tmp[k].d[i];
            o->n = tmp[k].n;
            /* jw_add fills in the writing pen and the layer, and that is
               what a line or a circle wants.  What the figure set on top of
               it comes over here: the flags always, and the pen only for a
               text it built itself (線's 寸法値), because blank() gives
               every figure colour 2 and line type 1 and copying those would
               throw the writing pen away. */
            o->flags = (unsigned short)(o->flags | tmp[k].flags);
            if (tmp[k].text >= 0)
                o->text = tmp[k].text;
            if (tmp[k].face >= 0)
                o->face = tmp[k].face;
            if (tmp[k].cls == JW_MOJI) {
                o->color = tmp[k].color;
                o->ltype = tmp[k].ltype;
                o->width = tmp[k].width;
            }
            /* the ● of 線's 1348 is written with line type 1, whatever
               the writing pen is set to -- read off the original's own file,
               where the line came out type 2 and the point type 1 */
            if (tmp[k].cls == JW_TEN) {
                o->ltype = tmp[k].ltype;
                o->color = tmp[k].color;
            }
            /* 任意色: pen 10 is Jw_cad's "any colour", and the RGB rides in
               the trailing long, which is copied above */
            if (tmp[k].color == 10)
                o->color = 10;
            put++;
        }
        op_push(put);
    }
    step = 0;
    tracking = 0;
    esc_rearm = 1;
    esc_cmd = current;
    esc_x = sx;
    esc_y = sy;
}

/* ---------------------------------------------------------------------------
 * 画像編集 (33013, CZukeiGazou, 0x80f5)
 *
 * What was read off the original -- tools/img1.sh, img3.sh, imgref.sh run it;
 * the answers it gave are decomp/res/img_*.jww; tests/image_test.c holds the
 * port to them; tmp/image_report.md has the log and the original's help.
 *
 * A picture is a CDataMoji whose text begins "^@BM" (src/image.h).  The bar
 * has five modes of which one is ticked at a time -- フィット 1345,
 * トリミング 1335, トリミング解除 1336, 移動 1337 (what it comes up in) and
 * 透過色設定 1339 -- and two ticks of their own: 回転する 1346, which only
 * lives while フィット is ticked, and 相対パス 1338.  Unticking the ticked
 * one leaves none.
 *
 *   画像挿入   the front end asks for a file; then 基準点 (the picture's lower
 *              left, 100 mm wide, shaped like the file) -- and the mode in
 *              force carries on from there
 *   移動       click a picture (the topmost one under the point), click where
 *              the point you clicked should go
 *   フィット   two points on a picture (a rectangle's corners, or with 回転する
 *              two points of the picture), then two points of the sheet: the
 *              picture is scaled by the long side of the first rectangle onto
 *              the second, the centres meeting -- or, turning, the first point
 *              onto the first and the second towards the second
 *   トリミング two corners; what is inside stays (kept in the picture's own
 *              frame if it is turned)
 *   解除       click a trimmed picture
 *   同梱/分離  a question, the work, and a report
 *   透過色     click a picture; a dialog (template 391) asks for R G B
 */
enum {
    GZ_FIT = 1345, GZ_TURN = 1346, GZ_TRIM = 1335, GZ_UNTRIM = 1336,
    GZ_MOVE = 1337, GZ_REL = 1338, GZ_TP = 1339
};

static int gz_mode = GZ_MOVE;           /* the ticked mode, 0 for none */
static int gz_turn, gz_rel;
static int gz_step;                     /* how far the mode's clicks are */
static int gz_at = -1;                  /* the picture a click picked */
static double gz_x[4], gz_y[4];         /* the points taken */
static int gz_need_file;                /* 画像挿入 was pressed */
static int gz_ins;                      /* a file is read: the 基準点 is next */
static char gz_ins_name[260];
static int gz_ins_w, gz_ins_h;
static int gz_ask_kind;                 /* a message box wanted: 1 OK/キャンセル, 2 OK */
static int gz_ask_what;                 /* 1 同梱 2 分離 */
static char gz_ask_text[560];
static int gz_tp_ask, gz_tp_at = -1, gz_tp_c[3];
static char gz_doc_dir[260], gz_doc_name[160];

/* a name copied into a field of `cap` bytes, cut if it is longer and the rest
   of the field cleared (what strncpy did, without its warning) */
static void gz_cpy(char *dst, size_t cap, const char *src)
{
    size_t n = strlen(src);

    if (n > cap - 1)
        n = cap - 1;
    memcpy(dst, src, n);
    memset(dst + n, 0, cap - n);
}
static struct { char name[300]; unsigned char *b; long n; } gz_out[64];
static int gz_nout;
static int gz_out_ready;               /* a 画像分離 left files for the front end */

void jw_cmd_gazou_doc(const char *dir, const char *name)
{
    strncpy(gz_doc_dir, dir ? dir : "", sizeof gz_doc_dir - 1);
    gz_doc_dir[sizeof gz_doc_dir - 1] = 0;
    strncpy(gz_doc_name, name ? name : "", sizeof gz_doc_name - 1);
    gz_doc_name[sizeof gz_doc_name - 1] = 0;
}

static int gz_midway(void)
{
    return gz_step != 0 || gz_ins;
}

/* What 移動 shows while a picture is picked and the place is being chosen
 * (the original's shot, decomp/res img: tools/imgref.sh's ghost): the picture
 * as a dashed outline where the click would put it, a line from the point
 * taken to the cursor, a big circle on the point and a small one on the
 * cursor -- the help says "移動元の位置が大きめの仮円で、マウスの位置が小さめの
 * 仮円".  The circles are the same size on the screen whatever the zoom, which
 * is why the last click's scale is kept. */
static double gz_mmpp = 0.612244898;

static int gz_pending(jw_drawing *d, jw_obj *o, int max)
{
    jw_obj *c;

    if (!d || gz_mode != GZ_MOVE || gz_step != 1 || gz_at < 0 || gz_at >= d->ndrawn || !tracking
        || max < 4)
        return 0;
    o[0] = d->obj[gz_at];
    o[0].sel = 0;
    o[0].flags = (unsigned short)(o[0].flags & ~2u);
    jw_obj_move(&o[0], tx - gz_x[0], ty - gz_y[0]);
    blank(&o[1]);
    o[1].cls = JW_SEN;
    o[1].d[0] = gz_x[0];
    o[1].d[1] = gz_y[0];
    o[1].d[2] = tx;
    o[1].d[3] = ty;
    c = &o[2];
    blank(c);
    c->cls = JW_ENKO;
    c->d[0] = gz_x[0];
    c->d[1] = gz_y[0];
    c->d[2] = 9.0 * gz_mmpp;
    c->d[4] = 2 * PI;
    c->d[6] = 1.0;
    c->n = 1;
    c = &o[3];
    blank(c);
    c->cls = JW_ENKO;
    c->d[0] = tx;
    c->d[1] = ty;
    c->d[2] = 5.0 * gz_mmpp;
    c->d[4] = 2 * PI;
    c->d[6] = 1.0;
    c->n = 1;
    return 4;
}

static void gz_reset(void)
{
    gz_step = 0;
    gz_at = -1;
    gz_ins = 0;
    gz_ask_kind = 0;
    gz_tp_ask = 0;
}

int jw_cmd_gazou_mode(void)
{
    return gz_mode;
}

int jw_cmd_gazou_check(int id)
{
    switch (id) {
    case GZ_FIT: case GZ_TRIM: case GZ_UNTRIM: case GZ_MOVE: case GZ_TP:
        return gz_mode == id;
    case GZ_TURN:
        return gz_turn;
    case GZ_REL:
        return gz_rel;
    }
    return -1;
}

int jw_cmd_gazou_enabled(int id)
{
    if (id == GZ_TURN || id == 2558)
        return gz_mode == GZ_FIT && !gz_ins;
    /* while a file is read and its 基準点 is awaited, the five modes sleep and
       the buttons do not (the bar read in that state) */
    if (gz_ins)
        return !(id == GZ_FIT || id == GZ_TRIM || id == GZ_UNTRIM || id == GZ_MOVE);
    return 1;
}

int jw_cmd_gazou_file(void)
{
    int r = gz_need_file;

    gz_need_file = 0;
    return r;
}

/* The picture under a point: the last one in the drawing that has it. */
static int gz_find(const jw_drawing *d, double x, double y)
{
    int i;

    for (i = d->ndrawn - 1; i >= 0; i--) {
        const jw_obj *o = &d->obj[i];
        jw_pic p;

        if (o->cls != JW_MOJI || !ika_editable(d, o) || !jw_pic_parse(d, o, &p))
            continue;
        if (jw_pic_hit(o, &p, x, y))
            return i;
    }
    return -1;
}

/* A file was picked.  `path` is what goes into the text (the front end has
   already made it relative if 相対パス is ticked: see jw_cmd_gazou_relative),
   `b` its bytes, which go into the store under that name. */
int jw_cmd_gazou_insert(jw_drawing *d, const char *path, const unsigned char *b, long n)
{
    jw_img im;
    char rel[300];

    (void)d;
    if (!path || !*path)
        return 0;
    if (gz_rel && gz_doc_dir[0] && !strncmp(path, gz_doc_dir, strlen(gz_doc_dir))) {
        const char *q = path + strlen(gz_doc_dir);

        if (*q == '\\' || *q == '/')
            q++;
        strncpy(rel, q, sizeof rel - 1);
        rel[sizeof rel - 1] = 0;
        path = rel;
    }
    strncpy(gz_ins_name, path, sizeof gz_ins_name - 1);
    gz_ins_name[sizeof gz_ins_name - 1] = 0;
    jw_img_put(gz_ins_name, b, n);
    gz_ins_w = gz_ins_h = 0;
    if (jw_img_decode(b, n, &im)) {
        gz_ins_w = im.w;
        gz_ins_h = im.h;
        jw_img_free(&im);
    }
    gz_step = 0;
    gz_at = -1;
    gz_ins = 1;
    return 1;
}

int jw_cmd_gazou_inserting(void)
{
    return gz_ins;
}

/* the message box the last press wants.  1: OK and キャンセル, 2: OK only */
int jw_cmd_gazou_ask(const char **text)
{
    if (!gz_ask_kind)
        return 0;
    if (text)
        *text = gz_ask_text;
    return gz_ask_kind;
}

static void gz_info(const char *fmt, int n)
{
    snprintf(gz_ask_text, sizeof gz_ask_text, fmt, n);
    gz_ask_kind = 2;
    gz_ask_what = 0;
}

/* 画像同梱: every picture that is still a file becomes "%temp%<name>" and its
   bytes -- as a BMP, whatever they were -- go into the drawing */
static int gz_embed(jw_drawing *d)
{
    int i, count = 0;
    op_t *rec = 0;

    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        jw_pic p;
        const unsigned char *b;
        long n;
        char nm[300], key[330];
        double base;

        if (!jw_pic_parse(d, o, &p) || !strncmp(p.name, "%temp%", 6))
            continue;
        b = jw_img_bytes(p.name, &n);
        if (!b)
            continue;
        jw_img_embed_name(p.name, nm, sizeof nm);
        snprintf(key, sizeof key, "%%temp%%%s", nm);
        if (b[0] == 'B' && b[1] == 'M')
            jw_img_put(key, b, n);
        else {
            jw_img im;
            long bn;
            unsigned char *bm;

            if (!jw_img_decode(b, n, &im))
                continue;
            bm = jw_img_bmp(&im, &bn);
            jw_img_free(&im);
            if (!bm)
                continue;
            jw_img_put(key, bm, bn);
            free(bm);
        }
        if (!rec)
            rec = op_new();
        op_keep(rec, d, i, 0);
        base = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
        gz_cpy(p.name, sizeof p.name, key);
        if (p.nfield < 9)
            p.nfield = 9;
        jw_pic_write(d, o, &p, o->d[0], o->d[1], base);
        count++;
    }
    return count;
}

static int gz_separate(jw_drawing *d)
{
    int i, count = 0, k;
    char folder[480], rel[200];

    for (k = 0; k < gz_nout; k++) {
        free(gz_out[k].b);
        gz_out[k].b = 0;
    }
    gz_nout = 0;
    snprintf(rel, sizeof rel, "%s\x81\x60\x95\xaa\x97\xa3\x89\xe6\x91\x9c", gz_doc_name);
    if (gz_doc_dir[0])
        snprintf(folder, sizeof folder, "%s\\%s", gz_doc_dir, rel);
    else
        snprintf(folder, sizeof folder, "%s", rel);
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        jw_pic p;
        const unsigned char *b;
        long n;
        double base;
        char path[820];
        op_t *rec = 0;

        if (!jw_pic_parse(d, o, &p) || strncmp(p.name, "%temp%", 6))
            continue;
        b = jw_img_bytes(p.name, &n);
        if (!b)
            continue;
        for (k = 0; k < gz_nout; k++)
            if (!strcmp(gz_out[k].name, p.name + 6))
                break;
        if (k == gz_nout && gz_nout < 64) {
            gz_cpy(gz_out[k].name, sizeof gz_out[k].name, p.name + 6);
            gz_out[k].b = (unsigned char *)malloc((size_t)n);
            if (gz_out[k].b)
                memcpy(gz_out[k].b, b, (size_t)n);
            gz_out[k].n = n;
            gz_nout++;
        }
        rec = op_new();
        op_keep(rec, d, i, 0);
        if (gz_rel)
            snprintf(path, sizeof path, "%s\\%s", rel, p.name + 6);
        else
            snprintf(path, sizeof path, "%s\\%s", folder, p.name + 6);
        gz_cpy(p.name, sizeof p.name, path);
        if (p.nfield < 9)
            p.nfield = 9;
        base = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
        jw_pic_write(d, o, &p, o->d[0], o->d[1], base);
        count++;
    }
    if (gz_nout > 0)
        gz_out_ready = 1;
    return count;
}

int jw_cmd_gazou_out_ready(void)
{
    int r = gz_out_ready;

    gz_out_ready = 0;
    return r;
}

void jw_cmd_gazou_answer(jw_drawing *d, int ok)
{
    int what = gz_ask_what, n;

    gz_ask_kind = 0;
    if (!ok || !what || !d)
        return;
    if (what == 1) {
        n = gz_embed(d);
        gz_info(JW_STR_10161, n);
    } else {
        n = gz_separate(d);
        gz_info(JW_STR_10169, n);
    }
}

int jw_cmd_gazou_out(int i, const char **name, const unsigned char **b, long *n)
{
    if (i < 0 || i >= gz_nout)
        return 0;
    *name = gz_out[i].name;
    *b = gz_out[i].b;
    *n = gz_out[i].n;
    return 1;
}

int jw_cmd_gazou_tp_ask(int *r, int *g, int *b)
{
    if (!gz_tp_ask)
        return 0;
    *r = gz_tp_c[0];
    *g = gz_tp_c[1];
    *b = gz_tp_c[2];
    return 1;
}

void jw_cmd_gazou_tp_set(jw_drawing *d, int r, int g, int b)
{
    gz_tp_ask = 0;
    if (r < 0 || !d || gz_tp_at < 0 || gz_tp_at >= d->ndrawn) {
        gz_tp_at = -1;                  /* cancelled, or nothing to put it on */
        return;
    }
    {
        op_t *rec = op_new();

        op_keep(rec, d, gz_tp_at, 0);
    }
    jw_pic_set_transparent(d, &d->obj[gz_tp_at], r < 0 ? 0 : r > 255 ? 255 : r,
                           g < 0 ? 0 : g > 255 ? 255 : g, b < 0 ? 0 : b > 255 ? 255 : b);
    gz_tp_at = -1;
}

/* a press on one of the bar's buttons; 1 when it was one of ours */
static int gz_bar(jw_drawing *d, int id)
{
    switch (id) {
    case 2557:                          /* 画像挿入 */
        gz_need_file = 1;
        gz_step = 0;
        return 1;
    case 2559:                          /* 画像同梱 */
        gz_ask_kind = 1;
        gz_ask_what = 1;
        snprintf(gz_ask_text, sizeof gz_ask_text, "%s", JW_STR_10160);
        return 1;
    case 2561:                          /* 同梱画像分離 */
        if (!gz_doc_name[0]) {
            gz_ask_kind = 2;
            gz_ask_what = 0;
            snprintf(gz_ask_text, sizeof gz_ask_text, "%s", JW_STR_10168);
            return 1;
        }
        gz_ask_kind = 1;
        gz_ask_what = 2;
        {
            char f[480];

            if (gz_doc_dir[0])
                snprintf(f, sizeof f, "%s\\%s\x81\x60\x95\xaa\x97\xa3\x89\xe6\x91\x9c", gz_doc_dir, gz_doc_name);
            else
                snprintf(f, sizeof f, "%s\x81\x60\x95\xaa\x97\xa3\x89\xe6\x91\x9c", gz_doc_name);
            snprintf(gz_ask_text, sizeof gz_ask_text, JW_STR_10167, f);
        }
        return 1;
    case GZ_TURN:
        if (gz_mode == GZ_FIT)
            gz_turn = !gz_turn;
        gz_step = 0;
        return 1;
    case GZ_REL:
        gz_rel = !gz_rel;
        return 1;
    case GZ_FIT: case GZ_TRIM: case GZ_UNTRIM: case GZ_MOVE: case GZ_TP:
        gz_mode = id;                   /* one of five: the ticked one stays ticked */
        gz_step = 0;
        gz_at = -1;
        gz_ins = 0;
        return 1;
    }
    (void)d;
    return 0;
}

const char *jw_cmd_gazou_prompt(void)
{
    if (gz_ins)
        return JW_STR_5409;
    switch (gz_mode) {
    case GZ_FIT:
        return gz_step == 0 ? JW_STR_10149 : gz_step == 1 ? JW_STR_10150
             : gz_step == 2 ? JW_STR_10151 : JW_STR_10152;
    case GZ_TRIM:
        return gz_step == 0 ? JW_STR_10147 : JW_STR_10148;
    case GZ_UNTRIM:
        return JW_STR_10153;
    case GZ_TP:
        return JW_STR_10171;
    }
    return gz_step == 0 ? JW_STR_10154 : JW_STR_10155;
}

static void gz_point(jw_drawing *d, const jw_view *v, double x, double y, int button)
{
    int at;

    if (!d || button > 1)
        return;
    if (v && v->mmpp > 0.0)
        gz_mmpp = v->mmpp;
    if (button == 1) {                  /* (R) read: a point of the drawing, or nothing */
        double rx, ry;

        if (!jw_read(d, v, x, y, &rx, &ry))
            return;
        x = rx;
        y = ry;
    }
    if (gz_ins) {                       /* 基準点 of a picture just read */
        jw_obj *o = jw_pic_new(d, gz_ins_name, gz_ins_w, gz_ins_h, x, y, 100.0);

        gz_ins = 0;
        if (o) {
            jw_pic pp;

            if (!gz_ins_w && jw_pic_parse(d, o, &pp)) {
                pp.nfield = 1;          /* a file that would not read: ",100" */
                jw_pic_write(d, o, &pp, x, y, 0.0);
            }
            op_push(1);
        }
        gz_step = 0;
        return;
    }
    switch (gz_mode) {
    case GZ_MOVE:
        if (gz_step == 0) {
            at = gz_find(d, x, y);
            if (at < 0)
                return;
            gz_at = at;
            gz_x[0] = x;
            gz_y[0] = y;
            gz_step = 1;
            return;
        }
        if (gz_at >= 0 && gz_at < d->ndrawn) {
            jw_obj *o = &d->obj[gz_at];
            op_t *rec = op_new();

            op_keep(rec, d, gz_at, 0);
            jw_obj_move(o, x - gz_x[0], y - gz_y[0]);
        }
        gz_step = 0;
        gz_at = -1;
        return;
    case GZ_FIT:
        if (gz_step == 0) {
            at = gz_find(d, x, y);
            if (at < 0)
                return;
            gz_at = at;
            gz_x[0] = x;
            gz_y[0] = y;
            gz_step = 1;
            return;
        }
        if (gz_step == 1 || gz_step == 3) {
            /* the second point: a rectangle's other corner has to differ
               in both ways, a turned fit's only has to be somewhere else */
            double ax = gz_x[gz_step - 1], ay = gz_y[gz_step - 1];

            if (gz_turn ? (x == ax && y == ay) : (x == ax || y == ay))
                return;
            gz_x[gz_step] = x;
            gz_y[gz_step] = y;
            if (gz_step == 1) {
                gz_step = 2;
                return;
            }
            if (gz_at >= 0 && gz_at < d->ndrawn) {
                jw_obj *o = &d->obj[gz_at];
                jw_obj was = *o;
                op_t *rec = op_new();

                op_keep(rec, d, gz_at, 0);
                if (!(gz_turn ? jw_pic_fit_turn(d, o, gz_x[0], gz_y[0], gz_x[1], gz_y[1],
                                               gz_x[2], gz_y[2], gz_x[3], gz_y[3])
                              : jw_pic_fit_box(d, o, gz_x[0], gz_y[0], gz_x[1], gz_y[1],
                                              gz_x[2], gz_y[2], gz_x[3], gz_y[3])))
                    *o = was;
            }
            gz_step = 0;
            gz_at = -1;
            return;
        }
        gz_x[2] = x;                    /* step 2: where the first goes */
        gz_y[2] = y;
        gz_step = 3;
        return;
    case GZ_TRIM:
        if (gz_step == 0) {
            at = gz_find(d, x, y);
            if (at < 0)
                return;
            gz_at = at;
            gz_x[0] = x;
            gz_y[0] = y;
            gz_step = 1;
            return;
        }
        if (x == gz_x[0] || y == gz_y[0])
            return;
        if (gz_at >= 0 && gz_at < d->ndrawn) {
            jw_obj *o = &d->obj[gz_at];
            jw_obj was = *o;
            op_t *rec = op_new();

            op_keep(rec, d, gz_at, 0);
            if (!jw_pic_trim(d, o, gz_x[0], gz_y[0], x, y))
                *o = was;
        }
        gz_step = 0;
        gz_at = -1;
        return;
    case GZ_UNTRIM:
        at = gz_find(d, x, y);
        if (at < 0)
            return;
        {
            jw_obj *o = &d->obj[at];
            jw_obj was = *o;
            op_t *rec = op_new();

            op_keep(rec, d, at, 0);
            if (!jw_pic_untrim(d, o))
                *o = was;
        }
        return;
    case GZ_TP:
        at = gz_find(d, x, y);
        if (at < 0)
            return;
        {
            jw_pic p;
            const jw_img *im;

            jw_pic_parse(d, &d->obj[at], &p);
            gz_tp_c[0] = p.r;
            gz_tp_c[1] = p.g;
            gz_tp_c[2] = p.b;
            if (button == 1 && (im = jw_img_get(p.name)) != 0) {
                /* (R) 色読込: the colour of the picture under the point */
                double lx, ly, a = jw_pic_angle(&d->obj[at], &p);
                int sc, sr;

                lx = cos(a) * (x - d->obj[at].d[0]) + sin(a) * (y - d->obj[at].d[1]);
                ly = -sin(a) * (x - d->obj[at].d[0]) + cos(a) * (y - d->obj[at].d[1]);
                sc = (int)floor(p.x * im->w + lx * im->w * p.c / p.w);
                sr = (int)floor(im->h - (p.y * im->w + ly * im->w * p.c / p.w));
                if (sc >= 0 && sc < im->w && sr >= 0 && sr < im->h) {
                    gz_tp_c[0] = im->rgb[((size_t)sr * im->w + sc) * 3];
                    gz_tp_c[1] = im->rgb[((size_t)sr * im->w + sc) * 3 + 1];
                    gz_tp_c[2] = im->rgb[((size_t)sr * im->w + sc) * 3 + 2];
                }
            }
            gz_tp_at = at;
            gz_tp_ask = 1;
        }
        return;
    }
}

/* ---- 文字の 範囲選択 (2407): 文書・外部エディタ・貼付・SJIS/UTF8 -------------
   tmp/spec_gaibu/B_moji_hani.md.  What the original does with the picked
   texts is read here as functions of the drawing and the text; the front end
   brings the file names, the editor and the clipboard. */

/* 1 = SJIS (CP932), 0 = UTF8: the 1092 button, DAT_00a0b458, MOJI\OutSJIS */
static int moji_sjis = 1;

int jw_moji_sjis(void)
{
    return moji_sjis;
}

void jw_moji_sjis_set(int on)
{
    moji_sjis = on != 0;
}

int jw_moji_sjis_toggle(void)
{
    return moji_sjis = !moji_sjis;
}

/* the picked texts, in the order the original writes them: layer group,
   layer, then the upper row first and the left one first in a row */
static const jw_drawing *ms_d;

static int ms_cmp(const void *pa, const void *pb)
{
    const jw_obj *a = &ms_d->obj[*(const int *)pa];
    const jw_obj *b = &ms_d->obj[*(const int *)pb];

    if (a->lgroup != b->lgroup)
        return a->lgroup < b->lgroup ? -1 : 1;
    if (a->layer != b->layer)
        return a->layer < b->layer ? -1 : 1;
    if (a->d[1] > b->d[1] + 1e-7)
        return -1;
    if (a->d[1] < b->d[1] - 1e-7)
        return 1;
    if (a->d[0] != b->d[0])
        return a->d[0] < b->d[0] ? -1 : 1;
    return *(const int *)pa < *(const int *)pb ? -1 : 1;
}

/* indices of the picked texts, sorted; the caller frees */
static int *ms_list(const jw_drawing *d, int *n)
{
    int i, k = 0, *l;

    *n = 0;
    if (!d || d->ndrawn <= 0)
        return 0;
    l = (int *)malloc((size_t)d->ndrawn * sizeof *l);
    if (!l)
        return 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].sel && d->obj[i].cls == JW_MOJI)
            l[k++] = i;
    ms_d = d;
    qsort(l, (size_t)k, sizeof *l, ms_cmp);
    *n = k;
    return l;
}

int jw_cmd_moji_count(const jw_drawing *d)
{
    int n, *l = ms_list(d, &n);

    free(l);
    return n;
}

/* UTF-16 units out as UTF-8 */
static long ms_put8(unsigned char *b, const unsigned short *w, long wn)
{
    long j, len = 0;

    for (j = 0; j < wn; j++) {
        unsigned c = w[j];

        if (c >= 0xd800 && c < 0xdc00 && j + 1 < wn)
            c = 0x10000 + ((c - 0xd800) << 10) + (w[++j] - 0xdc00u);
        if (c < 0x80)
            b[len++] = (unsigned char)c;
        else if (c < 0x800) {
            b[len++] = (unsigned char)(0xc0 | (c >> 6));
            b[len++] = (unsigned char)(0x80 | (c & 63));
        } else if (c < 0x10000) {
            b[len++] = (unsigned char)(0xe0 | (c >> 12));
            b[len++] = (unsigned char)(0x80 | ((c >> 6) & 63));
            b[len++] = (unsigned char)(0x80 | (c & 63));
        } else {
            b[len++] = (unsigned char)(0xf0 | (c >> 18));
            b[len++] = (unsigned char)(0x80 | ((c >> 12) & 63));
            b[len++] = (unsigned char)(0x80 | ((c >> 6) & 63));
            b[len++] = (unsigned char)(0x80 | (c & 63));
        }
    }
    return len;
}

/* A text out as a file: one text a line, CRLF.  UTF8 gets a BOM, SJIS stays
   as the drawing holds it.  `doc` is 文書込, which also drops a trailing ^m. */
static int ms_out(const jw_drawing *d, int doc, unsigned char **out, long *n)
{
    int k, i, *l = ms_list(d, &k);
    long cap, len = 0;
    unsigned char *b;

    *out = 0;
    *n = 0;
    if (!l || k <= 0) {
        free(l);
        return 0;
    }
    cap = 3;
    for (i = 0; i < k; i++)
        cap += (long)strlen(jw_str(d, d->obj[l[i]].text)) * 3 + 4;
    b = (unsigned char *)malloc((size_t)cap + 1);
    if (!b) {
        free(l);
        return 0;
    }
    if (!moji_sjis) {
        b[len++] = 0xef;
        b[len++] = 0xbb;
        b[len++] = 0xbf;
    }
    for (i = 0; i < k; i++) {
        const char *s = jw_str(d, d->obj[l[i]].text);
        long sl = (long)strlen(s);

        if (doc && sl > 2 && s[sl - 2] == '^' && s[sl - 1] == 'm')
            sl -= 2;
        if (moji_sjis) {
            memcpy(b + len, s, (size_t)sl);
            len += sl;
        } else {
            unsigned short *w = (unsigned short *)malloc((size_t)(sl + 1) * 2);

            if (!w)
                break;
            len += ms_put8(b + len, w, jw_to_utf16(s, sl, w, sl + 1));
            free(w);
        }
        b[len++] = '\r';
        b[len++] = '\n';
    }
    free(l);
    *out = b;
    *n = len;
    return 1;
}

/* 外部エディタ: what goes into TEMP.TXT */
int jw_cmd_moji_edit_text(const jw_drawing *d, unsigned char **out, long *n)
{
    return ms_out(d, 0, out, n);
}

/* 文書 (1070): the file the picked texts are written to.  The picking is
   let go of afterwards and the drawing is not changed. */
int jw_cmd_moji_doc(jw_drawing *d, unsigned char **out, long *n)
{
    int ok = ms_out(d, 1, out, n);

    if (ok)
        sel_clear(d);
    return ok;
}

/* Is it valid UTF-8 with something above ASCII in it? */
static int ms_is_utf8(const unsigned char *b, long n)
{
    long j = 0;
    int hi = 0;

    while (j < n) {
        unsigned c = b[j++];
        int more = c < 0x80 ? 0 : (c & 0xe0) == 0xc0 ? 1 : (c & 0xf0) == 0xe0 ? 2
                 : (c & 0xf8) == 0xf0 ? 3 : -1;

        if (more < 0)
            return 0;
        if (more)
            hi = 1;
        while (more-- > 0)
            if (j >= n || (b[j++] & 0xc0) != 0x80)
                return 0;
    }
    return hi;
}

/* The lines of a file as CP932 strings, each ended by a NUL.  A BOM says
   UTF-16LE or UTF-8; with none, valid UTF-8 with more than ASCII in it is
   taken as such when the setting is UTF8, and the rest is CP932.  A CR before
   the LF is dropped. */
static char *ms_lines(const unsigned char *b, long n, int *nl)
{
    unsigned short *w = (unsigned short *)malloc((size_t)(n + 2) * 2);
    char *cp = (char *)malloc((size_t)n * 2 + 8), *r;
    long wn = 0, on = 0, i, q = 0, s = 0;
    int k = 0, open = 0, utf8 = 0;

    *nl = 0;
    if (!w || !cp) {
        free(w);
        free(cp);
        return 0;
    }
    if (n >= 2 && b[0] == 0xff && b[1] == 0xfe) {
        for (i = 2; i + 1 < n; i += 2)
            w[wn++] = (unsigned short)(b[i] | (b[i + 1] << 8));
        on = jw_from_utf16(w, wn, cp, n * 2 + 4);
    } else {
        if (n >= 3 && b[0] == 0xef && b[1] == 0xbb && b[2] == 0xbf) {
            utf8 = 1;
            s = 3;
        } else if (!moji_sjis && ms_is_utf8(b, n)) {
            utf8 = 1;
        }
        if (utf8) {
            for (i = s; i < n;) {
                unsigned c = b[i++], v;
                int more = c < 0x80 ? 0 : (c & 0xe0) == 0xc0 ? 1 : (c & 0xf0) == 0xe0 ? 2 : 3;

                v = more == 0 ? c : more == 1 ? c & 31 : more == 2 ? c & 15 : c & 7;
                while (more-- > 0 && i < n)
                    v = (v << 6) | (b[i++] & 63u);
                if (v >= 0x10000) {
                    v -= 0x10000;
                    w[wn++] = (unsigned short)(0xd800 + (v >> 10));
                    w[wn++] = (unsigned short)(0xdc00 + (v & 1023));
                } else
                    w[wn++] = (unsigned short)v;
            }
            on = jw_from_utf16(w, wn, cp, n * 2 + 4);
        } else {
            memcpy(cp, b, (size_t)n);
            on = n;
        }
    }
    free(w);
    if (on > n * 2 + 4)
        on = n * 2 + 4;
    r = (char *)malloc((size_t)on + 2);
    if (!r) {
        free(cp);
        return 0;
    }
    for (i = 0; i < on; i++) {
        if (cp[i] == '\n') {
            r[q++] = 0;
            k++;
            open = 0;
        } else if (cp[i] != '\r') {
            r[q++] = cp[i];
            open = 1;
        }
    }
    if (open) {
        r[q++] = 0;
        k++;
    }
    r[q] = 0;
    free(cp);
    *nl = k;
    return r;
}

/* 外部エディタ and 貼付: the lines of the file go back onto the picked texts,
   in the same order.  A line replaces a text, an empty one (or none left)
   erases it, and lines past the last text become new ones below it.
   Returns how many elements changed, were erased or were made; 0 if the file
   holds no line at all. */
int jw_cmd_moji_apply(jw_drawing *d, const unsigned char *b, long n)
{
    int nl, k, i, *l, changed = 0, made = 0, ng = 0, *gone;
    char *lines, *p;
    op_t *o;

    if (!d)
        return 0;
    lines = ms_lines(b, n, &nl);
    l = ms_list(d, &k);
    if (!lines || !l || k <= 0 || nl <= 0) {
        free(lines);
        free(l);
        return 0;
    }
    o = op_new();
    gone = (int *)malloc((size_t)k * sizeof *gone);
    p = lines;
    for (i = 0; i < k; i++) {
        jw_obj *t = &d->obj[l[i]];
        const char *line = i < nl ? p : "";

        if (i < nl)
            p += strlen(p) + 1;
        if (!*line) {
            gone[ng++] = l[i];
            continue;
        }
        op_keep(o, d, l[i], 0);
        {
            double dx = t->d[2] - t->d[0], dy = t->d[3] - t->d[1];
            double len = sqrt(dx * dx + dy * dy), want;

            t->text = jw_add_str(d, line);
            want = jw_coord_text_len(d, t);
            if (len > 0.0) {
                t->d[2] = t->d[0] + dx / len * want;
                t->d[3] = t->d[1] + dy / len * want;
            }
        }
        changed++;
    }
    /* the lines that are left over: new texts under the last one */
    if (nl > k) {
        jw_obj last = d->obj[l[k - 1]];
        double dx = last.d[2] - last.d[0], dy = last.d[3] - last.d[1];
        double len = sqrt(dx * dx + dy * dy), ux = len > 0 ? dx / len : 1.0,
               uy = len > 0 ? dy / len : 0.0, pitch = txt_pitch() / 2.0;
        int j;

        for (j = k; j < nl; j++) {
            jw_obj *nw = jw_add(d, JW_MOJI);
            double want;

            if (!nw)
                break;
            *nw = last;
            nw->face = last.face >= 0 ? jw_add_str(d, jw_str(d, last.face)) : -1;
            nw->text = jw_add_str(d, p);
            p += strlen(p) + 1;
            nw->d[0] = last.d[0] + uy * pitch * (j - k + 1);
            nw->d[1] = last.d[1] - ux * pitch * (j - k + 1);
            nw->d[2] = nw->d[0] + ux * len;
            nw->d[3] = nw->d[1] + uy * len;
            want = jw_coord_text_len(d, nw);
            nw->d[2] = nw->d[0] + ux * want;
            nw->d[3] = nw->d[1] + uy * want;
            made++;
        }
    }
    /* erase, highest first so the numbers stay true */
    {
        int a, c;

        for (a = 0; a < ng; a++)
            for (c = a + 1; c < ng; c++)
                if (gone[c] > gone[a]) {
                    int t = gone[a];

                    gone[a] = gone[c];
                    gone[c] = t;
                }
        for (a = 0; a < ng; a++) {
            op_keep(o, d, gone[a], 1);
            jw_remove(d, gone[a]);
        }
    }
    if (o)
        o->n = made;
    sel_clear(d);
    free(gone);
    free(l);
    free(lines);
    return changed + ng + made;
}

/* ---- 外部変形 (0x8091): the script's steps, one prompt at a time ------------
   tmp/spec_gaibu/A_gaibu_henkei.md 5.  The front end picks the BAT and hands
   it over (jw_cmd_gaibu_load); the steps are walked here -- a range through
   範囲選択, points and picked elements by clicks, typed values and item
   numbers by keys -- and when the last is in, the front end is asked to run it
   (jw_cmd_gaibu_ready).  Not carried over: the rubber line to the last point,
   the 15-degree rounding, hhp<n>ln lines before picked elements. */
#define GB_CMD 0x8091
enum { GB_NONE = 0, GB_ITEM = 1, GB_STEPS = 2, GB_READY = 3 };
static jw_gscript *gb_sc;
static jw_gaibu gb_hdr;
static char *gb_bat;
static long gb_batn;
static int gb_state, gb_i, gb_item, gb_back, gb_keep, gb_want;
static double gb_xy[200][2];
static char gb_val[200][128];
static char gb_buf[128];
static double gb_ox, gb_oy;
static int gb_org;
static char gb_err[96];
static int gb_pick[200];

/* a UTF-8 literal as the CP932 the port draws with */
static const char *u8cp(const char *u)
{
    static char out[4][256];
    static int k;
    unsigned short w[256];
    long wn = 0;
    char *o = out[k++ & 3];

    while (*u && wn < 250) {
        unsigned c = (unsigned char)*u++;

        if (c >= 0xe0) {
            c = ((c & 15) << 12) | ((unsigned char)u[0] & 63) << 6 | ((unsigned char)u[1] & 63);
            u += 2;
        } else if (c >= 0xc0) {
            c = ((c & 31) << 6) | ((unsigned char)u[0] & 63);
            u++;
        }
        w[wn++] = (unsigned short)c;
    }
    o[jw_from_utf16(w, wn, o, 254)] = 0;
    return o;
}

static void gb_free(void)
{
    free(gb_sc);
    free(gb_bat);
    gb_sc = 0;
    gb_bat = 0;
    gb_state = GB_NONE;
    gb_back = 0;
    gb_org = 0;
    gb_err[0] = 0;
}

/* on to the next step that has to be asked */
static void gb_step(jw_drawing *d)
{
    while (++gb_i < gb_sc->nsteps) {
        const jw_gstep *st = &gb_sc->step[gb_i];

        gb_buf[0] = 0;
        switch (st->type) {
        case JW_GS_END:
            gb_state = GB_READY;
            return;
        case JW_GS_RANGE:
            if (d && jw_cmd_sel_count(d) > 0)
                continue;               /* what is picked already is the range */
            gb_keep = 1;
            jw_cmd_set(JW_CMD_HANI);
            gb_keep = 0;
            gb_back = 1;
            return;
        case JW_GS_CHOICE:
        case JW_GS_CHOICE_LR:
            if (!st->nitems)
                continue;
            return;
        default:
            return;
        }
    }
    gb_state = GB_READY;
}

static void gb_begin_steps(jw_drawing *d)
{
    gb_sc = (jw_gscript *)calloc(1, sizeof *gb_sc);
    if (!gb_sc)
        return;
    jw_gaibu_script(gb_bat, gb_batn, gb_item, gb_sc);
    memset(gb_xy, 0, sizeof gb_xy);
    memset(gb_val, 0, sizeof gb_val);
    memset(gb_pick, -1, sizeof gb_pick);
    gb_org = 0;
    gb_i = -1;
    gb_state = GB_STEPS;
    if (gb_sc->all && d) {              /* #h4: everything that can be read */
        int i;

        for (i = 0; i < d->ndrawn; i++) {
            d->obj[i].sel = 1;
            d->obj[i].flags = (unsigned short)(d->obj[i].flags | 2u);
        }
    }
    gb_step(d);
}

/* the BAT the front end picked.  0 if it is not one for Jw_cad. */
int jw_cmd_gaibu_load(jw_drawing *d, const char *bat, long n)
{
    jw_gaibu h;

    if (!jw_gaibu_header(bat, n, &h))
        return 0;
    gb_free();
    gb_hdr = h;
    gb_bat = (char *)malloc((size_t)n + 1);
    if (!gb_bat)
        return 0;
    memcpy(gb_bat, bat, (size_t)n);
    gb_bat[n] = 0;
    gb_batn = n;
    gb_item = 0;
    if (!gb_keep) {
        gb_keep = 1;
        jw_cmd_set(GB_CMD);
        gb_keep = 0;
    }
    if (h.nitems > 0)
        gb_state = GB_ITEM;             /* 項目を選択してください */
    else
        gb_begin_steps(d);
    return 1;
}

int jw_cmd_gaibu_active(void)
{
    return current == GB_CMD && gb_state != GB_NONE;
}

/* 1 once the last step is answered; the front end runs the BAT */
int jw_cmd_gaibu_ready(void)
{
    return current == GB_CMD && gb_state == GB_READY;
}

/* the 基準点 an #0 gave, if it did */
int jw_cmd_gaibu_origin(double *x, double *y)
{
    if (!gb_org || gb_state == GB_NONE)
        return 0;
    *x = gb_ox;
    *y = gb_oy;
    return 1;
}

/* what the run is made of */
int jw_cmd_gaibu_session(const char **bat, long *bn, int *item,
                         const double (**xy)[2], char (**val)[128])
{
    if (!gb_bat)
        return 0;
    *bat = gb_bat;
    *bn = gb_batn;
    *item = gb_item;
    *xy = (const double (*)[2])gb_xy;
    *val = gb_val;
    return 1;
}

/* the run is over (or given up): back to asking for a BAT */
void jw_cmd_gaibu_done(void)
{
    gb_free();
    gb_want = 0;
}

/* a click with no BAT in hand asks the front end for one again */
int jw_cmd_gaibu_want_bat(void)
{
    int w = gb_want;

    gb_want = 0;
    return w;
}

static const char *gb_prompt(void)
{
    static char b[400];
    const jw_gstep *st;

    if (gb_state == GB_NONE)
        return u8cp("操作を続けてください。");
    if (gb_state == GB_ITEM) {
        int k, n = 0;

        n = snprintf(b, sizeof b, "%s %s", gb_hdr.title, u8cp("項目を選んで番号を押してください: "));
        for (k = 0; k < gb_hdr.nitems && n < (int)sizeof b - 80; k++)
            n += snprintf(b + n, sizeof b - (size_t)n, "%d.%s ", k + 1, gb_hdr.item[k]);
        return b;
    }
    if (gb_state == GB_READY)
        return u8cp("実行します。");
    st = &gb_sc->step[gb_i];
    if (gb_err[0]) {
        snprintf(b, sizeof b, "%s", gb_err);
        return b;
    }
    switch (st->type) {
    case JW_GS_RANGE:
        return st->prompt;
    case JW_GS_POINT:
    case JW_GS_LINE:
    case JW_GS_CIRCLE:
    case JW_GS_TEXT:
        if (st->number)
            snprintf(b, sizeof b, "No.%d %s", st->n, st->prompt[0] ? st->prompt : u8cp("点を指示してください。 (L)free (R)Read"));
        else
            snprintf(b, sizeof b, "%s", st->prompt[0] ? st->prompt : u8cp("点を指示してください。 (L)free (R)Read"));
        return b;
    case JW_GS_INPUT:
    case JW_GS_INPUT_IME:
        snprintf(b, sizeof b, "%s %s_", st->prompt, gb_buf);
        return b;
    case JW_GS_CHOICE:
    case JW_GS_CHOICE_LR: {
        int k, n = snprintf(b, sizeof b, "%s ", st->prompt);

        for (k = 0; k < st->nitems; k++)
            n += snprintf(b + n, sizeof b - (size_t)n, "%d.%s ", k + 1, st->item[k]);
        snprintf(b + n, sizeof b - (size_t)n, "%s", u8cp("（マウス左クリックでスキップします）"));
        return b;
    }
    case JW_GS_ARGS:
    case JW_GS_ARGS_IME:
        return u8cp("操作を続けてください。 Enter で実行");
    }
    return u8cp("操作を続けてください。");
}

/* a click while the steps are on */
static void gb_click(jw_drawing *d, const jw_view *v, double x, double y, int button)
{
    const jw_gstep *st;
    int k;

    if (gb_state == GB_NONE) {
        gb_want = 1;                    /* 選び直し */
        return;
    }
    if (gb_state != GB_STEPS || !d)
        return;
    st = &gb_sc->step[gb_i];
    gb_err[0] = 0;
    switch (st->type) {
    case JW_GS_POINT: {
        int pk;

        if (button == 1) {              /* (R)Read: an end, a point or a crossing */
            double rx, ry;

            if (!jw_read(d, v, x, y, &rx, &ry))
                return;                 /* nothing to read: nothing happens */
            x = rx;
            y = ry;
        }

        /* a rubber line "/" before this point: its direction goes to a
           multiple of 15 degrees (FUN_00665740) */
        for (pk = gb_i - 1; pk >= 0; pk--)
            if (gb_sc->step[pk].type == JW_GS_POINT || gb_sc->step[pk].type == JW_GS_LINE
                || gb_sc->step[pk].type == JW_GS_CIRCLE || gb_sc->step[pk].type == JW_GS_TEXT)
                break;
        if (pk >= 0 && gb_sc->step[pk].type == JW_GS_POINT && gb_sc->step[pk].mode == 2) {
            double dx = x - gb_xy[pk][0], dy = y - gb_xy[pk][1];
            double len = sqrt(dx * dx + dy * dy);
            double a = floor(atan2(dy, dx) * 180.0 / 3.141592653589793 / 15.0 + 0.5) * 15.0;

            if (len > 0.0) {
                x = gb_xy[pk][0] + len * cos(a * 3.141592653589793 / 180.0);
                y = gb_xy[pk][1] + len * sin(a * 3.141592653589793 / 180.0);
            }
        }
        gb_xy[gb_i][0] = x;
        gb_xy[gb_i][1] = y;
        if (st->n == 0) {
            gb_ox = x;
            gb_oy = y;
            gb_org = 1;
        }
        break;
    }
    case JW_GS_LINE:
    case JW_GS_CIRCLE:
    case JW_GS_TEXT:
        k = jw_pick(d, v, x, y, 0);
        if (k < 0 || k >= d->ndrawn
            || d->obj[k].cls != (st->type == JW_GS_LINE ? JW_SEN
                                 : st->type == JW_GS_CIRCLE ? JW_ENKO : JW_MOJI)) {
            if (st->type == JW_GS_LINE)
                snprintf(gb_err, sizeof gb_err, "%s", u8cp("直線ではありません。"));
            else if (st->type == JW_GS_CIRCLE)
                snprintf(gb_err, sizeof gb_err, "%s", u8cp("円ではありません"));
            return;
        }
        gb_xy[gb_i][0] = x;
        gb_xy[gb_i][1] = y;
        gb_pick[gb_i] = k;
        break;
    case JW_GS_CHOICE:
    case JW_GS_CHOICE_LR:
    case JW_GS_INPUT:
    case JW_GS_INPUT_IME:
    case JW_GS_ARGS:
    case JW_GS_ARGS_IME:
        break;                          /* the click skips */
    default:
        return;
    }
    gb_step(d);
}

/* a key while the steps are on.  1 if it was theirs. */
int jw_cmd_gaibu_key(jw_drawing *d, int c)
{
    const jw_gstep *st;
    size_t n;

    if (current != GB_CMD || gb_state == GB_NONE || gb_state == GB_READY)
        return 0;
    if (c == 27) {
        gb_free();
        gb_want = 0;
        return 1;
    }
    if (gb_state == GB_ITEM) {
        if (c >= '1' && c <= '9' && c - '0' <= gb_hdr.nitems) {
            gb_item = c - '0';
            gb_begin_steps(d);
        }
        return 1;
    }
    st = &gb_sc->step[gb_i];
    switch (st->type) {
    case JW_GS_INPUT:
    case JW_GS_INPUT_IME:
        n = strlen(gb_buf);
        if (c == 13) {
            snprintf(gb_val[gb_i], sizeof gb_val[0], "%s", gb_buf);
            gb_step(d);
        } else if (c == 8) {
            if (n)
                gb_buf[n - 1] = 0;
        } else if (c >= 32 && n + 1 < sizeof gb_buf) {
            gb_buf[n] = (char)c;
            gb_buf[n + 1] = 0;
        }
        return 1;
    case JW_GS_CHOICE:
    case JW_GS_CHOICE_LR:
        if (c >= '1' && c <= '9' && c - '0' <= st->nitems) {
            snprintf(gb_val[gb_i], sizeof gb_val[0], "%d", c - '0');
            gb_step(d);
            return 1;
        }
        if (c == 32 || c == 13) {
            gb_step(d);                 /* none chosen */
            return 1;
        }
        return 1;
    case JW_GS_ARGS:
    case JW_GS_ARGS_IME:
        if (c == 13)
            gb_step(d);
        return 1;
    }
    return 0;
}

/* the elements the steps picked, named by their point's number: for the
   writer's hhp<n>ln / ci / ch lines.  num[i] is -1 for an element not picked. */
int jw_cmd_gaibu_tags(const jw_drawing *d, int *num, char *kind, int max)
{
    int i, k, n = 0;

    if (!gb_sc || !d)
        return 0;
    for (i = 0; i < max && i < d->ndrawn; i++)
        num[i] = -1;
    for (k = 0; k < gb_sc->nsteps; k++) {
        const jw_gstep *st = &gb_sc->step[k];

        if (st->type != JW_GS_LINE && st->type != JW_GS_CIRCLE && st->type != JW_GS_TEXT)
            continue;
        if (gb_pick[k] < 0 || gb_pick[k] >= max || gb_pick[k] >= d->ndrawn)
            continue;
        num[gb_pick[k]] = st->n;
        kind[gb_pick[k]] = st->type == JW_GS_LINE ? 'l' : st->type == JW_GS_CIRCLE ? 'c' : 'h';
        n++;
    }
    return n;
}

/* 外部変形: the rubber line from the last point to the cursor, for a point
   whose "-" or "/" asked for one (the next point of a "/" one is held to 15
   degrees, and the line shows it).  Nought when there is none to show. */
int jw_cmd_gaibu_preview(const jw_drawing *d, jw_drawing *out)
{
    static jw_drawing pv;
    static int inited;
    int pk;
    double x, y, px, py;
    jw_obj *o;

    if (!d || !out || current != 0x8091 || gb_state != 2 || !gb_sc || !tracking)
        return 0;
    if (gb_sc->step[gb_i].type != JW_GS_POINT)
        return 0;
    for (pk = gb_i - 1; pk >= 0; pk--)
        if (gb_sc->step[pk].type == JW_GS_POINT)
            break;
    if (pk < 0 || !gb_sc->step[pk].mode)
        return 0;
    px = gb_xy[pk][0];
    py = gb_xy[pk][1];
    x = tx;
    y = ty;
    if (gb_sc->step[pk].mode == 2) {
        double dx = x - px, dy = y - py, len = sqrt(dx * dx + dy * dy);
        double a = floor(atan2(dy, dx) * 180.0 / PI / 15.0 + 0.5) * 15.0;

        if (len > 0.0) {
            x = px + len * cos(a * PI / 180.0);
            y = py + len * sin(a * PI / 180.0);
        }
    }
    if (!inited) {
        memset(&pv, 0, sizeof pv);
        inited = 1;
    }
    {
        jw_obj *ob = pv.obj;
        int c = pv.cobj;
        char *pl = pv.pool;
        int cp = pv.cpool;

        pv = *d;
        pv.obj = ob;
        pv.cobj = c;
        pv.pool = pl;
        pv.cpool = cp;
        pv.nobj = pv.ndrawn = 0;
        pv.npool = 0;
    }
    o = jw_add(&pv, JW_SEN);
    if (!o)
        return 0;
    o->d[0] = px;
    o->d[1] = py;
    o->d[2] = x;
    o->d[3] = y;
    *out = pv;
    return 1;
}

/* The clipboard's 図形 as bytes, for a front end that puts it on the system
   clipboard (so a copy can be pasted in another window) and takes one back. */
int jw_cmd_clip_get(const unsigned char **b, long *n)
{
    if (!clip || clip_n <= 0)
        return 0;
    *b = clip;
    *n = clip_n;
    return 1;
}

int jw_cmd_clip_set(const unsigned char *b, long n)
{
    unsigned char *c;

    if (!b || n <= 0)
        return 0;
    c = (unsigned char *)malloc((size_t)n);
    if (!c)
        return 0;
    memcpy(c, b, (size_t)n);
    free(clip);
    clip = c;
    clip_n = n;
    return 1;
}

/* ---- 手書線 (1774) -------------------------------------------------------------
   CZukeiRenzokuSen with its flag at +0x780 set (the bar's 手書線 box; FUN_006d7ca0 and
   FUN_006da8b0 and slot 9, read in decomp/byclass/CZukeiRenzokuSen.c):

     * the left button going down notes the point and where the mouse is on the
       screen (+0x3f, +0x40 = the pixel), clears the count (+0x3e) and starts the
       drag (state 3);
     * every mouse move during it asks FUN_006df0f0 for a segment: if the mouse is
       5 pixels or more away from where it was last noted, **in x or in y**
       (|dx| < 5 and |dy| < 5 does nothing), a line goes in from the last point to
       this one (FUN_00450860 with the write pen), the count goes up and the
       noted pixel is this one;
     * the button coming up asks once more, and ends the stroke (state 0).

   So a stroke is a chain of straight lines, one wherever the mouse has gone five
   pixels -- there is no smoothing or fitting into arcs.  (The original's undo takes
   what was put in as one step: the port does too.)  Not seen in the original, which
   could not be driven by a drag: whether the lines join their ends exactly (they do
   here: each starts where the last one ended) and whether the stroke can be undone
   in one press. */
static double fh_px, fh_py;             /* the last point */
static int fh_sx, fh_sy;                /* the pixel it was noted at */
static int fh_made;
/* The stroke's step: opened with its first line and grown with every one after
   it, so that 戻る at any moment takes back exactly what the stroke has drawn
   (tests/cmdfuzz_test.c: a step must undo to the state just before the action
   that made it -- a stroke left by switching commands used to be pushed then,
   with lines drawn before it).  If anything else took a step meanwhile, the
   next line opens a new one. */
static int fh_op = -1;
static unsigned fh_gen;

static void fh_count(void)
{
    if (fh_op >= 0 && fh_op == nop - 1 && op[fh_op].gen == fh_gen && !op[fh_op].after) {
        op[fh_op].n++;
        return;
    }
    op_push(1);
    fh_op = nop - 1;
    fh_gen = nop > 0 ? op[nop - 1].gen : 0;
}

static void fh_press(jw_drawing *d, const jw_view *v, double x, double y)
{
    fh_px = x;
    fh_py = y;
    fh_sx = jw_sx(v, x);
    fh_sy = jw_sy(v, y);
    fh_made = 0;
    fh_state = 1;
    fh_op = -1;
    (void)d;
}

/* FUN_006df0f0: one sample.  Returns 1 if it put a line in. */
static int fh_sample(jw_drawing *d, const jw_view *v, double x, double y)
{
    int sx = jw_sx(v, x), sy = jw_sy(v, y);
    jw_obj *o;

    if (abs(sx - fh_sx) < 5 && abs(sy - fh_sy) < 5)
        return 0;
    o = jw_add(d, JW_SEN);
    if (!o)
        return 0;
    o->d[0] = fh_px;
    o->d[1] = fh_py;
    o->d[2] = x;
    o->d[3] = y;
    fh_px = x;
    fh_py = y;
    fh_sx = sx;
    fh_sy = sy;
    fh_made++;
    fh_count();
    return 1;
}

int jw_cmd_freehand(void)
{
    return fh_state;
}

/* the mouse moved while the button is down */
int jw_cmd_drag(jw_drawing *d, const jw_view *v, double x, double y)
{
    if (!fh_state || !d || current != JW_CMD_RENZOKU)
        return 0;
    return fh_sample(d, v, x, y);
}

/* the left button came up */
int jw_cmd_release(jw_drawing *d, const jw_view *v, double x, double y)
{
    int r;

    if (!fh_state || !d || current != JW_CMD_RENZOKU)
        return 0;
    fh_sample(d, v, x, y);
    fh_state = 0;
    r = fh_made > 0;
    fh_made = 0;
    fh_op = -1;
    return r;
}
