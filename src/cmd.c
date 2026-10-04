#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cmd.h"
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

/* コーナー処理: the first line, and where it was clicked.  CZukeiCorner
   keeps the same in +0x204 (0, then 2 once a line is down, then 3). */
static int corner_step;
static int corner_obj;
static double corner_x, corner_y;
/* 面取 works the same way and keeps its pick in the same three */

/* 線伸縮: the line, while its end is being moved. */
static int stretch_step;
static int stretch_obj;

/* 文字: what has been typed but not placed yet.  The original wants it that
   way round -- type into its floating box first, then click where it goes;
   pressing Enter does not place anything. */
static char line_buf[256];
static int line_n;
static int line_lead_next;      /* the last byte taken was a lead byte */
static int line_drop_trail;     /* a lead byte was refused: drop its trail */
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
        || c == JW_CMD_SEIRI || c == JW_CMD_ZUKEIREG;
}
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
/* 接円: the two elements picked, then a click that says which of the four
   circles of that radius is wanted -- the status line counts them 【 4 − n 】. */
static int sek_a = -1, sek_b = -1, sek_step;
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
static int nisen_flip;          /* 間隔反転 (1064) */
static int nisen_obj = -1, nisen_step;
static double nisen_x, nisen_y;

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
static struct { unsigned short cmd, id; char t[16]; } box[] = {
    { JW_CMD_SEN, 1411, "" },           /* 線の傾き */
    { JW_CMD_SEN, 1412, "" },           /* 線の寸法（長さ） */
    { JW_CMD_KUKEI, 1411, "" },         /* 矩形の傾き */
    { JW_CMD_KUKEI, 1413, "" },         /* 矩形の寸法 "横,縦" */
    { JW_CMD_TAKAKU, 1411, "1000" },    /* 寸法      */
    { JW_CMD_TAKAKU, 1413, "5" },       /* 角数      */
    { JW_CMD_TAKAKU, 1414, "0" },       /* 底辺角度  */
    { JW_CMD_MENTORI, 1411, "" },       /* 面取の寸法 -- empty to start with,
                                           the way the original's is */
    { JW_CMD_BUNKATSU, 1411, "" },      /* 分割数, likewise */
    { JW_CMD_NISEN, 1412, "" },         /* ２線の間隔, "a,b"         */
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

/* 寸法 の 小数桁 (1061): how many places the value is written to.  The
 * button cycles them, and the original's own drawings say the cycle is
 * 2 -> 3 -> 0 -> 1 -> 2 (the settings start at 2, which is what
 * JW_SUN_DECIMALS carries).  The text's width word carries it as well:
 * 0x2043 for two places, 0x3043 for three, 0x0043 for none, 0x1043 for one
 * -- (places << 12) | 0x43. */
static int sun_keta = -1;

/* how many places the value is written to, for whoever draws the button */
int jw_cmd_sunpo_decimals(void);

static int sun_decimals(void)
{
    return sun_keta < 0 ? JW_SUN_DECIMALS : sun_keta;
}

int jw_cmd_sunpo_decimals(void)
{
    return sun_decimals();
}


/* 寸法 の 半径 (1065): one click on a circle instead of two points on a
 * line.  0 is the ordinary two-point dimension. */
static int sun_radius;          /* 1 = 半径, 2 = 直径 */

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
static struct { unsigned cmd; unsigned short id; char t[16]; }
    xbox[JW_NBARSTATE];
static int nxbox;

/* Which bar is up: the command's own, or the one it puts up once a range is
   settled -- 複写・移動・データ整理 each have a second one, filed under
   100000 + the command the way tools/bars2.ps1 writes it. */
static unsigned bar_cmd(void)
{
    return sel_step == 3 ? 100000u + (unsigned)current : (unsigned)current;
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

/* 多角形 (CZukeiTakakukei).  The bar's 中心→頂点指定 is the mode it starts
 * in, and with a 寸法 in the box one click on the centre draws the whole
 * thing -- which is what the original does: a click left a regular pentagon
 * behind, and another click left a second one.
 */

static void sel_free(void);

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
                                   it (which go back a different way) */
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

static void op_drop(op_t *o)
{
    free(o->item);
    free(o->after);
    free(o->back);
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

/* A number typed into a command bar box, in paper millimetres.
 *
 * The boxes hold real-world lengths, so what goes on the paper is that over
 * the scale of the layer group being written to: the original, given 1000 in
 * 矩形's 寸法 on a 1/200 group, drew a square 5 mm across.  Returns 0 when
 * the box is empty or the drawing is not there, which is what tells the
 * command to work the free way instead.
 */
static double box_mm(const jw_drawing *d, int id)
{
    const char *t = jw_cmd_box(id);
    double v;
    int i, wg = 0;

    if (!t || !*t || !d)
        return 0.0;
    v = atof(t);
    if (v <= 0.0)
        return 0.0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        v /= d->group[wg].scale;
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
static int tail_kind;           /* 0 none, 1 線, 2 矩形, 3 円 */
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
static int ra_step;             /* 0 none, 1 after the start, 2 running */
static int ra_have;             /* an arc is laid, so ra_u is good */
static double ra_jx, ra_jy;     /* where the chain has got to */
static double ra_mx, ra_my;     /* the middle point of the first arc */
static double ra_ux, ra_uy;     /* out of the last centre, through the join */
static double ra_dx, ra_dy;     /* and the way the last arc was going there */

/* 包絡処理: the first corner of the box, and whether it has been given */
static int hou_step;
static double hou_x, hou_y;

/* The font name Jw_cad writes with a new text.  It is whatever its font box
   has, and every text in the drawings to hand has this one; the port draws
   with a bitmap font of its own and has no font list to choose from. */
#define JW_MOJI_FACE "lr SVbN" 

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
        } else if (jw_cmd_bar_check(1324) > 0) {
            o->d[2] = x;
            o->d[3] = jw_cmd_bar_check(1325) > 0 ? y - len : y + len;
        } else {
            o->d[2] = x + len;
            o->d[3] = y;
        }
    }
    o->d[4] = cw;
    o->d[5] = ch;
    o->d[6] = sp;
    o->d[7] = 0.0;
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

void jw_cmd_set(int id)
{
    prev = current;
    if (id == JW_CMD_SEN && prev == JW_CMD_SEN)
        hv = !hv;
    /* FUN_004fdc40: the new command's state starts empty. */
    current = id;
    step = 0;
    en_step = 0;
    hou_step = 0;
    sel_outside = 0;
    sel_cut = 0;
    sel_keep = sel_sub = 0;
    comp_n = 0;
    cut_step = 0;
    corner_step = 0;
    stretch_step = 0;
    para_step = 0;
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
    ra_step = ra_have = 0;      /* and neither is a 連続弧 part way through */
    if (id == JW_CMD_SUNPO) {
        sun_step = 0;
        sun_chi = sun_chi_done = sun_enshu = 0;
        /* 一括処理 is dead again until a dimension has been drawn */
        ika_step = ika_live = ika_ntog = 0;
        ika_lt = -1;
    }
    tail_kind = 0;              /* and the status line's readout with it */
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
    sel_flip = sel_base_wait = sel_dir = 0;
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
    step = 0;
    en_step = 0;
    hou_step = 0;
    cut_step = 0;
    corner_step = 0;
    stretch_step = 0;
    para_step = 0;
    tracking = 0;
    nisen_step = 0;
    nisen_obj = -1;
    ses_step = 0;
    ses_a = -1;
    sek_step = 0;
    sek_a = sek_b = -1;
    chu_step = 0;
    chu_a = chu_b = -1;
    cv_n = 0;
    ht_n = 0;
    ht_nchain = 0;
    sun_step = sun_chi ? 5 : sun_enshu ? 7 : sun_radius ? 2 : 0;
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

    return step != 0 || en_step != 0 || hou_step != 0 || cut_step != 0
           || corner_step != 0 || stretch_step != 0 || para_step != 0
           || nisen_step != 0 || ses_step != 0 || sek_step != 0
           || chu_step != 0 || cv_n != 0 || ht_n != 0 || ht_nchain != 0
           || sun_step != sun_rest;
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
void jw_cmd_back(void)
{
    if (current == JW_CMD_CHUSHIN && chu_step > 0) {
        chu_step--;
        if (chu_step < 2)
            chu_b = -1;
        if (chu_step < 1)
            chu_a = -1;
        tracking = 0;
        return;
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
        return;
    }
    /* ２線 (CZukei2Sen, slot 16 at 0x00624150): the end point's state 3
       goes back to 2, the start point's, and 2 back to 1, the line --
       the port's nisen_step 2 and 1 */
    if (current == JW_CMD_NISEN && nisen_step > 0) {
        nisen_step--;
        if (nisen_step < 1)
            nisen_obj = -1;
        tracking = 0;
        return;
    }
    /* 分割 (CZukeiBunkatsu) goes from its state 2 straight back to 0, which
       is the start; so does the rest, as far as anyone has read */
    jw_cmd_escape();
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
        if (it->removed == 2) {
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
    }
    return p;
}

const char *jw_cmd_prompt(void)
{
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
        return JW_STR_5345;
    }
    switch (current) {
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
        return JW_STR_5376;
    case JW_CMD_MOJI:
        if (ren_step)
            return ren_step == 1 ? JW_STR_5473
                   : ren_step == 3 ? JW_STR_5311 : JW_STR_5474;
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
        return para_step == 0 ? JW_STR_5305 : JW_STR_5366;
    case JW_CMD_SHINSHUKU:
        /* FUN_00717df0: 0x14d8 while its state is 0, 0x14da once a line is
           picked.  (Its states 3 and 4 are the 基準線 variant, where the end
           goes to another line instead of to a point; not done here.) */
        return stretch_step == 0 ? JW_STR_5336 : JW_STR_5338;
    case JW_CMD_BUNKATSU:
        /* 分割 is not コーナー: it has its own pair.  CZukeiBunkatsu's
           FUN_007614c0 puts up 0x14ed while its state is 0 or 1 -- 「線・円
           （Ａ）指示　ﾏｳｽ(L)　分割始点指示　ﾏｳｽ(R)　連続点分割 (RR)」 --
           and once one is picked (state 2) it asks for the second: 0x14ee
           「□　線【B】指示…」 when what was picked is a CDataSen, 0x14ef
           「○　円【B】指示…」 when it is a CDataEnko.  (Its state 3 is
           ２点間分割 and shows 0x14f0, and 連続点分割 shows 0x16bb and
           0x16bc; the port's 分割 takes two lines and reaches neither.) */
        return corner_step == 0 ? JW_STR_5357 : JW_STR_5358;
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
           two while a radius is in the box; that tail is not added here.) */
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
            return ht_sel == 2 ? JW_STR_5326 : JW_STR_5383;
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
        /* 5383 while the box has no first corner, 5326 while it is being
           dragged, then 5314 基準点 and 5307/5311 for where it goes. */
        if (sel_step == 1)
            return JW_STR_5326;
        /* 整理 places nothing, so 「複写先の点」 was never its line.
           CZukeiSeiri's FUN_006e62c0 asks FUN_0044fcd0 whether the
           selection is empty: if not it puts up 0x152c 「実行項目を指示
           してください。（実行中マウスクリックで中断）」 -- which is where
           the port's 整理 stands once the selection is settled. */
        if (sel_step == 3 && current == JW_CMD_SEIRI)
            return JW_STR_5420;
        if (sel_step == 3)
            return current != JW_CMD_SEIRI && range_moves()
                   ? JW_STR_5311 : JW_STR_5307;
        if (sel_step == 2)
            return JW_STR_5314;
        return JW_STR_5383;
    case JW_CMD_TAKAKU:
        /* 「中心点を指示してください (L)free (R)Read」 */
        return JW_STR_5309;
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
        p = sun_step == 2 ? JW_STR_5331 : JW_STR_5332;
        if (!sun_enshu && !sun_kaku)
            return p;
        snprintf(tail, sizeof tail, "%s%s%s", p, JW_STR_6159,
                 sun_enshu ? JW_STR_6158 : JW_STR_6157);
        return tail;
    }
    case JW_CMD_ENKO:
        /* CZukeiEnko asks for the centre first and then a point the circle
           goes through.  It leads with 円位置 instead only when a radius has
           been typed into its command bar, which there is nowhere to do
           yet. */
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
    jw_obj *o;

    if (r < 1e-9)
        return 0;
    if (!ccw)
        sw -= 2.0 * PI;
    o = jw_add(d, JW_ENKO);
    if (!o)
        return 0;
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = a0;
    o->d[4] = sw;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
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
static int sen_value(const jw_drawing *d, jw_obj *o, int max)
{
    double dx, dy, len, ux, uy, vx, vy, cw, ch, sp, tw = 0.0;
    char txt[64];
    const char *p;
    int i, wg = 0, nch = 0;

    if (jw_cmd_bar_check(1350) <= 0 || !d || max < 2)
        return 1;
    dx = o->d[2] - o->d[0];
    dy = o->d[3] - o->d[1];
    len = sqrt(dx * dx + dy * dy);
    if (len <= 0.0)
        return 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    i = JW_SUN_MOJINO - 1;
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
        return 1;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    blank(&o[1]);
    o[1].cls = JW_MOJI;
    o[1].color = (unsigned short)d->style[i].color;
    o[1].ltype = 2;
    o[1].width = 0;
    o[1].flags = (unsigned short)(o[1].flags | JW_SUN_TEXT_FLAGS);
    {
        double mx = (o->d[0] + o->d[2]) / 2.0 + JW_SUN_HANARE * vx;
        double my = (o->d[1] + o->d[3]) / 2.0 + JW_SUN_HANARE * vy;
        o[1].d[0] = mx - tw / 2.0 * ux;
        o[1].d[1] = my - tw / 2.0 * uy;
        o[1].d[2] = mx + tw / 2.0 * ux;
        o[1].d[3] = my + tw / 2.0 * uy;
    }
    o[1].d[4] = cw;
    o[1].d[5] = ch;
    o[1].d[6] = sp;
    o[1].d[7] = 0.0;
    o[1].n = JW_SUN_MOJINO;
    o[1].text = jw_add_str((jw_drawing *)d, txt);
    o[1].face = jw_add_str((jw_drawing *)d, JW_MOJI_FACE);
    return 2;
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
            double a = k * JW_SUN_ARROW_ANG * PI / 180.0;
            double ca = cos(a), sa = sin(a);
            if (n >= max)
                break;
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].ltype = o[0].ltype;
            o[n].color = o[0].color;
            o[n].d[0] = px;
            o[n].d[1] = py;
            o[n].d[2] = px + JW_SUN_ARROW_LEN * (wx * ca - wy * sa);
            o[n].d[3] = py + JW_SUN_ARROW_LEN * (wx * sa + wy * ca);
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
                 * trailing long is the RGB.  The original's own default,
                 * with nothing picked in the colour button, is 0x808080. */
                o->color = 10;
                o->n = 0x808080;
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

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
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
    const char *sz = jw_cmd_box(1411);
    int wg = 0, i;
    op_t *rec;
    jw_obj *n;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    dist = box_num(sz, 0.0);
    if (dist <= 0.0)
        return;                 /* no size typed in: nothing to cut */
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        dist /= d->group[wg].scale;
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
    px = ix + pux * dist;
    py = iy + puy * dist;
    qx = ix + qux * dist;
    qy = iy + quy * dist;

    rec = op_new();
    op_keep(rec, d, a, 0);
    op_keep(rec, d, b, 0);
    {   /* cut end first, then the end that stays */
        double kpx = cp < tp ? p->d[0] : p->d[2];
        double kpy = cp < tp ? p->d[1] : p->d[3];
        double kqx = cq < tq ? q->d[0] : q->d[2];
        double kqy = cq < tq ? q->d[1] : q->d[3];
        p->d[0] = px; p->d[1] = py; p->d[2] = kpx; p->d[3] = kpy;
        q->d[0] = qx; q->d[1] = qy; q->d[2] = kqx; q->d[3] = kqy;
    }
    n = jw_add(d, JW_SEN);
    if (n) {
        n->d[0] = px;
        n->d[1] = py;
        n->d[2] = qx;
        n->d[3] = qy;
        /* the new line belongs to the same step as the two that were cut,
           so one press of 元に戻る takes the whole chamfer back */
        if (rec)
            rec->n = 1;
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
 * A negative 分割数 is 逆分割 (it sets +0x7e98), whose gaps grow or shrink
 * along the way; that is not done here, and nor is an empty box, which
 * FUN_0058cc80 may read as 0 and so as 1.01 -- that has not been asked.
 * (This used to take the box through atoi and refuse anything outside
 * 2..1000, so 2.5 drew one line at the half and 5000 drew nothing.)
 */
static void bunkatsu(jw_drawing *d, int a, int b)
{
    const jw_obj *p = &d->obj[a], *q = &d->obj[b];
    const char *ns = jw_cmd_box(1411);
    double n = box_num(ns, 0.0);
    int k, count, made = 0;
    double ax0, ay0, ax1, ay1, bx0, by0, bx1, by1;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    if (!ns || !*ns || n <= 0.0)
        return;
    if (n <= 1.01) {
        char t[16];

        n = 1.01;
        snprintf(t, sizeof t, "%.2f", n);
        box_put(1411, t);
    }
    if (n > 10000.0) {
        box_put(1411, "10000");
        return;
    }
    count = (int)n - 1;
    if (n - (int)n > 1e-07)
        count++;
    ax0 = p->d[0]; ay0 = p->d[1]; ax1 = p->d[2]; ay1 = p->d[3];
    bx0 = q->d[0]; by0 = q->d[1]; bx1 = q->d[2]; by1 = q->d[3];
    for (k = 1; k <= count; k++) {
        double t = (double)k / n;
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
static int nisen_gap(const jw_drawing *d)
{
    const char *t = jw_cmd_box(1412);
    const char *p;
    int wg = 0, i;
    double s;

    if (!t || !*t)
        return 0;
    nisen_a = box_num(t, 0.0);
    p = strchr(t, ',');
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

static void nisen(jw_drawing *d, double x, double y)
{
    const jw_obj *o = &d->obj[nisen_obj];
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double len = sqrt(dx * dx + dy * dy), ux, uy, vx, vy;
    double s0, s1, t0, made = 0;
    int k;

    if (len == 0.0)
        return;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    /* the two points, along the line the pair runs on */
    s0 = (nisen_x - o->d[0]) * ux + (nisen_y - o->d[1]) * uy;
    s1 = (x - o->d[0]) * ux + (y - o->d[1]) * uy;
    t0 = (o->d[0]) * 0.0;       /* the line itself is the zero of the offset */
    (void)t0;
    for (k = 0; k < 2; k++) {
        /* 間隔反転 (1064) turns the pair over: the original left the two
           numbers in the box alone when it was pressed, so what it reverses
           is which side each of them goes */
        double off = k ? nisen_b : -nisen_a;
        jw_obj *n;
        if (nisen_flip)
            off = -off;
        n = jw_add(d, JW_SEN);
        if (!n)
            break;
        n->d[0] = o->d[0] + ux * s0 + vx * off;
        n->d[1] = o->d[1] + uy * s0 + vy * off;
        n->d[2] = o->d[0] + ux * s1 + vx * off;
        n->d[3] = o->d[1] + uy * s1 + vy * off;
        made++;
    }
    op_push((int)made);
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
static int chushin_line(const jw_drawing *d, double *px, double *py,
                        double *ux, double *uy)
{
    const jw_obj *p = &d->obj[chu_a], *q = &d->obj[chu_b];
    double adx = p->d[2] - p->d[0], ady = p->d[3] - p->d[1];
    double bdx = q->d[2] - q->d[0], bdy = q->d[3] - q->d[1];
    double alen = sqrt(adx * adx + ady * ady);
    double blen = sqrt(bdx * bdx + bdy * bdy);
    double den, t;

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

static void chushin(jw_drawing *d, double x, double y)
{
    double px, py, ux, uy, t0, t1;
    jw_obj *o;

    if (chu_a < 0 || chu_b < 0 || chu_a >= d->nobj || chu_b >= d->nobj)
        return;
    if (d->obj[chu_a].cls != JW_SEN || d->obj[chu_b].cls != JW_SEN)
        return;
    if (!chushin_line(d, &px, &py, &ux, &uy))
        return;
    t0 = (chu_x - px) * ux + (chu_y - py) * uy;
    t1 = (x - px) * ux + (y - py) * uy;
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
    if (zh_type) {
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
    double nx, ny, k;           /* a line: n.point == k */
    double cx, cy, r;           /* a circle */
} sek_el;

static int sek_elem(const jw_obj *o, sek_el *e)
{
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
    if (o->cls == JW_ENKO && o->d[2] > 0.0) {
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
    double r = box_num(sz, 0.0);
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

static void sekien(jw_drawing *d, int a, int b, double x, double y)
{
    sek_el p, q;
    double px[SEK_MAX], py[SEK_MAX], r, bestd = 0;
    int i, n, best = -1;

    if (a < 0 || b < 0 || a >= d->nobj || b >= d->nobj || a == b)
        return;
    if (!sek_elem(&d->obj[a], &p) || !sek_elem(&d->obj[b], &q))
        return;
    r = sek_radius(d);
    if (r <= 0.0)
        return;                 /* no radius typed in: nothing to draw */
    n = sek_places(&p, &q, r, px, py);
    for (i = 0; i < n; i++) {
        double e = (px[i] - x) * (px[i] - x) + (py[i] - y) * (py[i] - y);

        if (best < 0 || e < bestd) {
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
 * three.  With three lines that is the one inside the triangle they make, and
 * the original draws it the moment the third is picked -- no placing click,
 * and where each line was picked makes no difference (three runs pointed at
 * quite different parts of the same three lines all came back with the same
 * circle, decomp/res/sek3.jww).  Of the four circles that touch three lines
 * the inside one is the smallest, which is what this takes.
 */
static void sekien3(jw_drawing *d, int a, int b, int c, double x, double y)
{
    sek_el e[3];
    double best = 0, bx = 0, by = 0;
    int i, s1, s2, s3, have = 0;

    (void)x;
    (void)y;
    if (a < 0 || b < 0 || c < 0 || a >= d->nobj || b >= d->nobj
        || c >= d->nobj || a == b || b == c || a == c)
        return;
    if (!sek_elem(&d->obj[a], &e[0]) || !sek_elem(&d->obj[b], &e[1])
        || !sek_elem(&d->obj[c], &e[2]))
        return;
    for (i = 0; i < 3; i++)
        if (e[i].circle)
            return;             /* circles are not done here */
    /* n_i.C - s_i r = k_i, three equations in Cx, Cy and r */
    for (s1 = -1; s1 <= 1; s1 += 2)
        for (s2 = -1; s2 <= 1; s2 += 2)
            for (s3 = -1; s3 <= 1; s3 += 2) {
                double m[3][4], t;
                int row, col, piv;

                m[0][0] = e[0].nx; m[0][1] = e[0].ny; m[0][2] = -(double)s1;
                m[1][0] = e[1].nx; m[1][1] = e[1].ny; m[1][2] = -(double)s2;
                m[2][0] = e[2].nx; m[2][1] = e[2].ny; m[2][2] = -(double)s3;
                m[0][3] = e[0].k; m[1][3] = e[1].k; m[2][3] = e[2].k;
                for (col = 0; col < 3; col++) {
                    piv = col;
                    for (row = col + 1; row < 3; row++)
                        if (fabs(m[row][col]) > fabs(m[piv][col]))
                            piv = row;
                    if (fabs(m[piv][col]) < 1e-12)
                        break;
                    if (piv != col)
                        for (i = 0; i < 4; i++) {
                            t = m[col][i];
                            m[col][i] = m[piv][i];
                            m[piv][i] = t;
                        }
                    for (row = 0; row < 3; row++) {
                        if (row == col)
                            continue;
                        t = m[row][col] / m[col][col];
                        for (i = col; i < 4; i++)
                            m[row][i] -= t * m[col][i];
                    }
                }
                if (col < 3)
                    continue;   /* two of them are parallel */
                t = m[2][3] / m[2][2];          /* the radius */
                if (t <= 1e-9 || (have && t >= best))
                    continue;
                have = 1;
                best = t;
                bx = m[0][3] / m[0][0];
                by = m[1][3] / m[1][1];
            }
    if (!have)
        return;
    i = sek_draw(d, bx, by, best);
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

static void sel_mirror(jw_drawing *d, const jw_obj *axis);

static void sel_clear(jw_drawing *d)
{
    int i;

    if (d)
        for (i = 0; i < d->nobj; i++) {
            d->obj[i].flags = (unsigned short)(d->obj[i].flags & ~2u);
            d->obj[i].sel = 0;
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

int jw_cmd_block_editing(void)
{
    return blkedit_on;
}

void jw_cmd_block_done(void)
{
    blkedit_on = 0;
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
            return blkedit_on;
        }
    return 0;
}

void jw_cmd_block_take(jw_drawing *d, int from)
{
    int at, n, i;
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

            while (last > want) {
                jw_obj t = d->obj[last - 1];

                d->obj[last - 1] = d->obj[last];
                d->obj[last] = t;
                last--;
            }
        }
        d->obj[at].n++;
    }
    /* The definition's own count changed, so 元に戻る has to know it -- and
       it has to be told where the definition sits *now*, because taking the
       elements out of the drawing moved it.  ndef takes the new ones off
       the end of the array, which is where they are when the block being
       edited is the last definition: the only case there is an answer for. */
    if (rec) {
        op_item *it = op_keep(rec, d, at, 0);

        if (it)
            it->was = was;
        rec->n -= n;
        if (rec->n < 0)
            rec->n = 0;
        rec->ndef += n;
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
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_BLOCK && d->obj[i].sel
            && d->obj[i].block == blkedit_num) {
            op_keep(rec, d, i, 0);
            d->obj[i].block = num_new;
            break;
        }
    blkedit_num = num_new;
    return 1;
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
    case JW_BLOCK: return (mask & JW_ZOK_BLOCK) != 0;
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

    if (!d || n <= 0 || !tracking)
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
    base_x = tx;
    base_y = ty;
    /* 範囲選択 has nothing to place: confirming there only settles what is
       picked, and it is the next command that does something with it. */
    sel_step = current == JW_CMD_HANI ? 4 : 3;
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
    op_t *o;
    int i, n = 0;

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

static void sel_place(jw_drawing *d, double x, double y)
{
    double dx = x - base_x, dy = y - base_y;
    double sc = sel_scale(), ang = sel_turn();
    int i;

    if (!d || sel_n <= 0)
        return;
    switch (sel_dir) {          /* 任意方向 squares the move off */
    case 1: dy = 0.0; break;
    case 2: dx = 0.0; break;
    case 3:
        if ((dx < 0 ? -dx : dx) >= (dy < 0 ? -dy : dy))
            dy = 0.0;
        else
            dx = 0.0;
        break;
    }
    if (range_moves()) {
        op_t *o = op_new();
        for (i = 0; i < sel_n; i++) {
            int at = sel_at[i];
            if (at >= d->nobj)
                continue;
            op_keep(o, d, at, 0);
            d->obj[at] = sel_was[i];
            jw_obj_xform(&d->obj[at], base_x, base_y, sc, ang, dx, dy);
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
    if (sel_step != 3 || sel_n <= 0 || !tracking)
        return 0;
    *dx = tx - base_x;
    *dy = ty - base_y;
    return 1;
}

/* Whether a tick box on the bar is ticked, for the ones the port works: -1
   means "not one of them, use what the original came up with". */
int jw_cmd_bar_check(int id)
{
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
    switch (id) {
    case 1120:
        /* 寸法 has 実行 here, and it is alive at exactly one
           place: 一括処理's third prompt.  tools/probe45.sh read
           the button at all five stages of the walk and it went
           58010f00, 58010f00, 58010f00, **50010f00**, 58010f00. */
        if (current == JW_CMD_SUNPO)
            return ika_step == 3;
        return sel_step == 2 && jw_cmd_sel_count(d) > 0;   /* 選択確定 */
    case 1064:                  /* 連続 -- not done */
        return 0;
    case 1065:                  /* 前範囲, and 追加範囲 once a box is in */
        return sel_step == 2;
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
            sun_step = 2;
            return 1;
        }
        if (id == 1066) {       /* 直径 */
            sun_radius = 2;
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
    case 1065:                  /* 追加範囲 -- the next box adds to it */
        if (sel_step != 2)
            return 0;           /* 前範囲 before that, which is not done */
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
        if (sel_step == 2) {    /* 除外範囲: the next box takes away */
            sel_keep = 1;
            sel_sub = 1;
            sel_step = 0;
            return 1;
        }
        for (i = 0; i < d->ndrawn; i++) {
            d->obj[i].flags = (unsigned short)(d->obj[i].flags | 2u);
            d->obj[i].sel = 1;
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
        { JW_CMD_SEN, 1351, { 1348, 1349, 1350 } }
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

int jw_cmd_bar(jw_drawing *d, int id)
{
    unsigned char *on;

    if (bar_press(d, id))
        return 1;
    /* Anything the command itself does not act on, and that the original has
       as a checkbox there: its tick moves whatever the command makes of it,
       so the port's does too. */
    if (current == JW_CMD_SUNPO && id == 1070) {
        sun_prog = !sun_prog;
        return 1;
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
        if (!t || !*t)
            return 1;
        a = box_num(t, 0.0);
        p = strchr(t, ',');
        b = p ? box_num(p + 1, 0.0) : a;
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
        int base = id == 1064 ? para_last : para_obj;
        int k;

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
                if (!k)
                    para_last = (int)(o - d->obj);
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

int jw_cmd_box_focus(void)
{
    return box_focus;
}

void jw_cmd_box_click(int id)
{
    box_focus = jw_cmd_box(id) ? id : 0;
}

int jw_cmd_box_key(int ch)
{
    char *t = box_focus ? box_slot(bar_cmd(), box_focus) : 0;

    if (t) {
        int n = (int)strlen(t);
        if (ch == 13 || ch == 27) {         /* Enter, Esc: done */
            box_focus = 0;
            return 1;
        }
        if (ch == 8) {                      /* backspace */
            if (n)
                t[n - 1] = 0;
            return 1;
        }
        /* ２線's box holds two numbers with a comma between them */
        if ((ch >= '0' && ch <= '9') || ch == '.' || ch == '-' || ch == ',') {
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
static void takaku(jw_drawing *d, double cx, double cy)
{
    const char *sz = jw_cmd_box(1411), *ns = jw_cmd_box(1413);
    const char *ang = jw_cmd_box(1414);
    double r = box_num(sz, 0.0), a0 = box_num(ang, 0.0);
    int n = ns ? atoi(ns) : 0, i, wg = 0, made = 0;

    if (n < 3 || n > 1000 || r <= 0.0)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        r /= d->group[wg].scale;
    a0 = (a0 - 90.0 - 180.0 / n) * PI / 180.0;
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
    char txt[64], val[64];
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
    o->color = JW_SUN_SEN_COLOR;
    o->ltype = 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = ex;
    o->d[3] = ey;

    for (k = 0; k < 16; k++)
        if (d->group[k].state == 3)
            wg = k;
    si = JW_SUN_MOJINO - 1;
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
        double mx = (cx + ex) / 2.0 - uy * JW_SUN_HANARE;
        double my = (cy + ey) / 2.0 + ux * JW_SUN_HANARE;
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
            o->n = JW_SUN_MOJINO;
            o->text = jw_add_str(d, txt);
            o->face = jw_add_str(d, JW_MOJI_FACE);
        }
    }
    for (k = 0; k < 2; k++) {
        o = jw_add(d, JW_TEN);
        if (!o)
            break;
        o->color = JW_SUN_TEN_COLOR;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
        o->d[0] = k ? ex : cx;
        o->d[1] = k ? ey : cy;
        o->n = 0;
    }
    op_push(4);
}

/* 寸法値 (1069): the value on its own, between the two points given. */
static void sunpo_value(jw_drawing *d, double x0, double y0,
                        double x1, double y1)
{
    double dx = x1 - x0, dy = y1 - y0, len = sqrt(dx * dx + dy * dy);
    double ux, uy, vx, vy, cw, ch, sp, tw = 0.0, mx, my;
    char txt[64];
    const char *p;
    int i, wg = 0, nch = 0;
    jw_obj *o;

    if (len <= 0.0)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    i = JW_SUN_MOJINO - 1;
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
        return;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    mx = (x0 + x1) / 2.0 + JW_SUN_HANARE * vx;
    my = (y0 + y1) / 2.0 + JW_SUN_HANARE * vy;
    o = jw_add(d, JW_MOJI);
    if (!o)
        return;
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
    o->n = JW_SUN_MOJINO;
    o->text = jw_add_str(d, txt);
    o->face = jw_add_str(d, JW_MOJI_FACE);
    op_push(1);
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

    i = JW_SUN_MOJINO - 1;
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
        double px = sun_ox + (r2 + JW_SUN_HANARE) * cos(mid);
        double py = sun_oy + (r2 + JW_SUN_HANARE) * sin(mid);
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
            o->n = JW_SUN_MOJINO;
            o->text = jw_add_str(d, txt);
            o->face = jw_add_str(d, JW_MOJI_FACE);
            made++;
        }
    }

    /* the arc */
    o = jw_add(d, JW_ENKO);
    if (!o)
        return;
    o->color = JW_SUN_SEN_COLOR;
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
        o->color = JW_SUN_TEN_COLOR;
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
        o->color = JW_SUN_HIKI_COLOR;
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
    o->color = JW_SUN_SEN_COLOR;
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
            o->color = JW_SUN_TEN_COLOR;
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
                    double aa = k * JW_SUN_ARROW_ANG * PI / 180.0;
                    double ca = cos(aa), sa = sin(aa);
                    o = jw_add(d, JW_SEN);
                    if (!o)
                        break;
                    o->ltype = 1;
                    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
                    o->d[0] = x1;
                    o->d[1] = y1;
                    o->d[2] = x1 + JW_SUN_ARROW_LEN * (wx * ca - wy * sa);
                    o->d[3] = y1 + JW_SUN_ARROW_LEN * (wx * sa + wy * ca);
                    made++;
                }
            }
        }
    } else if (!sun_arrows()) {
        for (i = 0; i < 2; i++) {
            o = jw_add(d, JW_TEN);
            if (!o)
                break;
            o->color = JW_SUN_TEN_COLOR;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
            o->d[0] = i ? x1 : x0;
            o->d[1] = i ? y1 : y0;
            o->n = 0;
            made++;
        }
    } else {
        double alen = JW_SUN_ARROW_LEN;
        double aang = JW_SUN_ARROW_ANG * PI / 180.0;
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
    for (i = 0; th != tl + JW_SUN_TSUKIDASHI && i < 2; i++) {
        double s = i ? s1 : s0;
        o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->color = JW_SUN_HIKI_COLOR;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
        o->d[0] = s * ux + (tl + JW_SUN_TSUKIDASHI) * vx;
        o->d[1] = s * uy + (tl + JW_SUN_TSUKIDASHI) * vy;
        o->d[2] = s * ux + th * vx;
        o->d[3] = s * uy + th * vy;
        made++;
    }

    /* 寸法値 -- 文字種 MOJINO, centred on the line and HANARE above it */
    i = JW_SUN_MOJINO - 1;
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
        double mid = (s0 + s1) / 2.0, t = tl + JW_SUN_HANARE;
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
                double px = (s1 - JW_SUN_HANARE) * ux + t * vx;
                double py = (s1 - JW_SUN_HANARE) * uy + t * vy;
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
            o->n = JW_SUN_MOJINO;
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
    o->color = JW_SUN_SEN_COLOR;
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
            o->color = JW_SUN_TEN_COLOR;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
            o->d[0] = k ? x1 : x0;
            o->d[1] = k ? y1 : y0;
            o->n = 0;
            made++;
        }
        for (k = 0; th != tl + JW_SUN_TSUKIDASHI && k < 2; k++) {
            double s = k ? s1 : s0;
            if (!want[k])
                continue;
            o = jw_add(d, JW_SEN);
            if (!o)
                break;
            o->color = JW_SUN_HIKI_COLOR;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
            o->d[0] = s * ux + (tl + JW_SUN_TSUKIDASHI) * vx;
            o->d[1] = s * uy + (tl + JW_SUN_TSUKIDASHI) * vy;
            o->d[2] = s * ux + th * vx;
            o->d[3] = s * uy + th * vy;
            made++;
        }
    }

    i = JW_SUN_MOJINO - 1;
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
    t = tl + JW_SUN_HANARE;
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
    o->n = JW_SUN_MOJINO;
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

/* one click while a 取得 is on; 1 if it was swallowed */
static int get_click(jw_drawing *d, const jw_view *v,
                     double x, double y, int button)
{
    int two = get_mode == 32940 || get_mode == 32933
              || get_mode == 32934;
    int i;

    if (!d)
        return 1;
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
    if (i < 0 || d->obj[i].cls != JW_SEN)
        return 1;
    {
        const jw_obj *o = &d->obj[i];
        double a = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]);

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

/* A double left click.  Only 連 wants one -- it is how the original says
   「移動（LL)」 -- and everywhere else it is just a left click. */
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
    jw_cmd_point(d, v, x, y, 0);
}

void jw_cmd_point(jw_drawing *d, const jw_view *v,
                  double x, double y, int button)
{
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
           Only line-crosses-line is done for 《交点》. */
        if (read_pick < 0) {
            int i = jw_pick(d, v, x, y, 1);

            if (i < 0 || (d->obj[i].cls != JW_SEN
                          && d->obj[i].cls != JW_ENKO))
                return;
            read_pick = i;
            return;
        }
        if (d->obj[read_pick].cls == JW_ENKO) {
            const jw_obj *o = &d->obj[read_pick];
            double dx = x - o->d[0], dy = y - o->d[1];
            double len = sqrt(dx * dx + dy * dy);

            read_pick = -1;
            read_mode = 0;
            if (len <= 0.0)
                return;
            x = o->d[0] + o->d[2] * dx / len;
            y = o->d[1] + o->d[2] * dy / len;
            button = 0;
        } else {
            const jw_obj *o = &d->obj[read_pick];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = dx * dx + dy * dy, t;
            int j = jw_pick(d, v, x, y, 1), had = read_pick;

            read_pick = -1;
            read_mode = 0;
            if (len <= 0.0)
                return;
            /* 《交点》: a second line under the click wins over the foot of
               the perpendicular.  Driving the original bears it out -- two
               lines crossing at (-3.463557, 37.233236) and a click on the
               second gave exactly that (decomp/res/snapcross.jww). */
            if (j >= 0 && j != had && d->obj[j].cls == JW_SEN) {
                const jw_obj *q = &d->obj[j];
                double ex = q->d[2] - q->d[0], ey = q->d[3] - q->d[1];
                double den = dx * ey - dy * ex;

                if (den != 0.0) {
                    double u = ((q->d[0] - o->d[0]) * ey
                                - (q->d[1] - o->d[1]) * ex) / den;

                    x = o->d[0] + u * dx;
                    y = o->d[1] + u * dy;
                    button = 0;
                    goto placed;
                }
            }
            t = ((x - o->d[0]) * dx + (y - o->d[1]) * dy) / len;
            x = o->d[0] + t * dx;
            y = o->d[1] + t * dy;
            button = 0;
        }
placed:
        ;
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
            if (button != 0 && !jw_read(d, v, x, y, &x, &y))
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
            return;
        }
        if (sun_kaku || sun_enshu)
            sunpo_angle(d, rx, ry);
        else
            sunpo_make(d, rx, ry);
        sun_step = 2;           /* ready for the next one */
        return;
    }
    if (range_cmd(current)) {
        switch (sel_step) {
        case 0:
            if (button != 0)    /* (R) picks a 連続線, which is not done */
                return;
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
            sel_step = jw_cmd_sel_count(d) > 0 ? 2 : 0;
            return;
        case 2:
            /* another box, on top of what is already picked */
            if (button != 0)
                return;
            sel_x0 = sel_x1 = x;
            sel_y0 = sel_y1 = y;
            sel_step = 1;
            return;
        default:
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
        jw_obj tmp, *o;

        if (button != 0 || !d || line_n == 0)
            return;
        if (!moji(d, &tmp, x, y))
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
        i = jw_pick(d, v, x, y, button ? 1 : 3);
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
        if (button != 0 || !d)
            return;
        if (para_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            para_obj = i;
            para_step = 1;
            return;
        }
        if (para_step == 1) {
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
                if (typed <= 0.0) {
                    para_step = 2;
                    return;
                }
                para_off = para_off < 0.0 ? -typed : typed;
            }
            /* and with one, this click was the direction: fall through */
        }
        para_step = 0;
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
            para_last = (int)(o - d->obj);
            op_push(1);
        }
        return;
    }
    if (current == JW_CMD_SHINSHUKU) {
        /* Pick a line, then say where its end should go.  Which end moves is
         * settled by the second point, not the first: clicking the left half
         * of a line in Jw_cad and then a point past its right end moves the
         * right end.  The point is dropped on to the line first, the same
         * way a partial erase drops its two.  A tie goes to the first end. */
        int i;
        if (button != 0 || !d)
            return;             /* (R) is 線切断, (RR) 基準線指定 */
        if (stretch_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            stretch_obj = i;
            stretch_step = 1;
            return;
        }
        stretch_step = 0;
        i = stretch_obj;
        if (i >= 0 && i < d->ndrawn && d->obj[i].cls == JW_SEN) {
            jw_obj *o = &d->obj[i];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len2 = dx * dx + dy * dy, t, nx, ny;
            if (len2 < 1e-14)
                return;
            t = ((x - o->d[0]) * dx + (y - o->d[1]) * dy) / len2;
            nx = o->d[0] + t * dx;
            ny = o->d[1] + t * dy;
            op_keep(op_new(), d, i, 0);
            if (fabs(t) <= fabs(t - 1.0)) {
                o->d[0] = nx;
                o->d[1] = ny;
            } else {
                o->d[2] = nx;
                o->d[3] = ny;
            }
        }
        return;
    }
    if (current == JW_CMD_CHUSHIN) {
        int i;
        if (button != 0 || !d)
            return;             /* (R) reads a point, which is not done */
        if (chu_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            chu_a = i;
            chu_step = 1;
            return;
        }
        if (chu_step == 1) {
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == chu_a || d->obj[i].cls != JW_SEN)
                return;
            chu_b = i;
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
                if (button != 0)
                    return;     /* (R) picks a 連続線, which is not done */
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
        if (button != 0 || !d)
            return;
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
        int i;
        if (button != 0 || !d)
            return;
        if (sek_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                return;
            sek_a = i;
            sek_step = 1;
            return;
        }
        if (sek_step == 1) {
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == sek_a
                || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                return;
            sek_b = i;
            sek_step = 2;
            return;
        }
        if (sek_radius(d) <= 0.0) {
            /* an empty 半径: the third element settles it, and it is drawn
               the moment that is picked */
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == sek_a || i == sek_b)
                return;
            sekien3(d, sek_a, sek_b, i, x, y);
        } else {
            sekien(d, sek_a, sek_b, x, y);
        }
        sek_step = 0;                   /* ready for the next pair */
        sek_a = sek_b = -1;
        return;
    }
    if (current == JW_CMD_SESSEN) {
        int i;
        if (button != 0 || !d)
            return;
        if (ses_mode == 1691 || ses_mode == 1692) {
            sesline(d, v, x, y);
            return;
        }
        if (ses_mode == 1690) {         /* 点→円: the point, then the circle */
            if (ses_step == 0) {
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
        if (button != 0 || !d)
            return;
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
            nisen(d, x, y);
        nisen_step = 0;         /* ready for the next line to run along */
        nisen_obj = -1;
        return;
    }
    if (current == JW_CMD_BUNKATSU) {
        int i;
        if (button != 0 || !d)
            return;
        if (corner_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            corner_obj = i;
            corner_step = 2;
            return;
        }
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != corner_obj)
            bunkatsu(d, corner_obj, i);
        corner_step = 0;
        return;
    }
    if (current == JW_CMD_MENTORI) {
        int i;
        if (button != 0 || !d)
            return;
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
        if (button != 0 || !d)
            return;             /* (R) is 線切断, which is not done here */
        if (corner_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
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
         * (CZukeiShoukyo's vtable slot 9, its +0x21c going 0 to 3), which is
         * not done here.
         *
         * Which element: the one the highlight would be on, and that is
         * found with FUN_0044a270's mode 0 (CZukeiShoukyo's slot 11, the one
         * that runs as the mouse moves). */
        int i;
        if (!d)
            return;
        if (button == 1) {
            i = jw_pick(d, v, x, y, 0);
            if (i >= 0)
                erase(d, i, op_new());
            cut_step = 0;
            return;
        }
        /* the left button: pick, then the two ends of the piece */
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
            double a = k * JW_SUN_ARROW_ANG * PI / 180.0;
            double ca = cos(a), sa = sin(a);
            jw_obj *n = jw_add(d, JW_SEN);
            if (!n)
                break;
            if (button != 0) {          /* (R) uses the dimension pen */
                n->color = JW_SUN_SEN_COLOR;
                n->ltype = 1;
            }
            n->d[0] = ax;
            n->d[1] = ay;
            n->d[2] = ax + JW_SUN_ARROW_LEN * (wx * ca - wy * sa);
            n->d[3] = ay + JW_SUN_ARROW_LEN * (wx * sa + wy * ca);
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
        /* CZukeiTen: one point and it is placed.  Its own prompt never
           changes while it waits (FUN_004efbb0(0x1500)). */
        if (d) {
            jw_obj *o = jw_add(d, JW_TEN);
            if (o) {
                o->d[0] = x;
                o->d[1] = y;
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
        } else if (!ra_have) {
            double cx, cy;

            if (three_circle(ra_jx, ra_jy, ra_mx, ra_my, x, y, &cx, &cy)) {
                double a0 = atan2(ra_jy - cy, ra_jx - cx);
                double am = atan2(ra_my - cy, ra_mx - cx);
                double a1 = atan2(y - cy, x - cx);
                int ccw = turn_pos(am - a0) < turn_pos(a1 - a0);

                if (ren_arc_add(d, cx, cy, ra_jx, ra_jy, x, y, ccw)) {
                    ra_have = 1;
                    op_push(1);
                }
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

                if (ren_arc_add(d, cx, cy, ra_jx, ra_jy, x, y, ccw))
                    op_push(1);
            }
            ra_jx = x;
            ra_jy = y;
        }
        tx = x;
        ty = y;
        return;
    }
    if (current == JW_CMD_RENZOKU) {
        if (step == 0) {
            sx = x;
            sy = y;
            step = 2;
        } else if (step == 2) {
            rx = x;
            ry = y;
            step = 3;
        } else {
            if (d) {
                jw_obj *o = jw_add(d, JW_SEN);
                if (o) {
                    o->d[0] = sx;
                    o->d[1] = sy;
                    o->d[2] = rx;
                    o->d[3] = ry;
                    op_push(1);
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
    if (current == JW_CMD_ENKO && jw_cmd_bar_check(1320) > 0) {
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
                    op_push(1);
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
                op_push(1);
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
}
