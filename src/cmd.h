/* Which command the user is in, and what it is waiting for.
 *
 * The original keeps the current command as one id in the view, at +0x8564,
 * and every toolbar button's ON_UPDATE_COMMAND_UI handler is the same three
 * lines (FUN_00511c20):
 *
 *     pCmdUI->SetCheck(view->current == id);
 *
 * so a button is drawn pressed exactly when it is the command in force.
 * Entering a command (FUN_004fdba0 -> FUN_004fdc40) remembers the old one at
 * +0x8568, stores the new one at +0x8564 and clears the command's own state.
 */
#ifndef JW_CMD_H
#define JW_CMD_H

#include "jww.h"
#include "view.h"

/* The ids are the resource ids the toolbars send; src/gen/cmds.h has the one
   for each button on the screen. */
enum {
    JW_CMD_SEN = 0x8003,            /* 線 -- the one the original starts in */
    JW_CMD_TEN = 0x8011,            /* 点 */
    JW_CMD_KUKEI = 0x8004,          /* 矩形 -- CZukeiSen's other mode */
    JW_CMD_ENKO = 0x8005,           /* 円 */
    JW_CMD_RENZOKU = 0x8073,        /* 連続線。連続弧 (2492) を入れると
                                       直線でなく接しながら弧を繋ぎます
                                       (tests/renarc_test.c) */
    JW_CMD_SHOUKYO = 0x801a,        /* 消去 */
    JW_CMD_CORNER = 0x8012,         /* コーナー処理 */
    JW_CMD_SHINSHUKU = 0x8017,      /* 線伸縮 */
    JW_CMD_FUKUSEN = 0x8020,        /* 複線 */
    JW_CMD_ZOKUSEI = 0x80a3,        /* 属性取得 */
    JW_CMD_ZOKUHEN = 0x80b8,        /* 属性変更 */
    JW_CMD_MOJI = 0x8026,           /* 文字 */
    JW_CMD_HANI = 0x8013,           /* 範囲選択 -- CZukeiSentaku */
    JW_CMD_FUKUSHA = 0x8024,        /* 複写 -- CZukeiFukusha */
    JW_CMD_IDOU = 0x8096,           /* 移動 -- the same class */
    JW_CMD_PARAM = 0x8082,          /* パラメトリック変形 (32898) -- CZukeiParametric */
    JW_CMD_SUNPO = 0x804f,          /* 寸法 -- CZukeiSunpo */
    JW_CMD_SOKUTEI = 0x8081,        /* 測定 (32897) */
    JW_CMD_KYORITEN = 0x80a2,       /* 距離指定点 (32930) */
    JW_CMD_TAKAKU = 0x807e,         /* 多角形 -- CZukeiTakakukei */
    JW_CMD_MENTORI = 0x805b,        /* 面取 -- CZukeiCorner's other half */
    JW_CMD_BUNKATSU = 0x8063,       /* 分割 -- CZukeiBunkatsu */
    JW_CMD_TENKU = 0x80cb,          /* 天空図 (32971) */
    JW_CMD_HIKAGE = 0x80af,         /* 日影図 (32943) */
    JW_CMD_25D = 0x80a9,            /* ２．５D (32937) */
    JW_CMD_AUTO = 0x8093,           /* AUTOモード (32915) */
    JW_CMD_TATEGU = 0x8050,         /* 建具平面 (32848) */
    JW_CMD_TATEGU_DAN = 0x8062,     /* 建具断面 (32866) */
    JW_CMD_TATEGU_RITSU = 0x8061,   /* 建具立面 (32865) */
    JW_CMD_KIGOU = 0x8065,          /* 線記号変形 (32869) */
    JW_CMD_NISEN = 0x807c,          /* ２線 -- the menu resource and the
                                       toolbar cell both say 0x807c; it
                                       was 0x805c here, which is not a
                                       command at all, so the button and
                                       the menu never reached this and
                                       the bar fell back to 線's.  The
                                       tests set it by name, so they did
                                       not notice. */
    JW_CMD_CHUSHIN = 0x8069,        /* 中心線 -- CZukeiChuushinSen */
    JW_CMD_SESSEN = 0x8066,         /* 接線 -- 円→円 only so far */
    JW_CMD_SEKIEN = 0x8068,         /* 接円 -- two lines and a radius */
    JW_CMD_KYOKUSEN = 0x808c,       /* 曲線 -- all four kinds: サイン、
                                       ２次、スプライン、ベジェ (tests/curve_test.c) */
    JW_CMD_HOURAKU = 0x804e,        /* 包絡処理 -- CZukeiHouraku */
    JW_CMD_HATCH = 0x806a,          /* ハッチ -- 1線・２線・３線・┬┴┬・図形。
                                       図形 lays down what 範囲選択 picked and
                                       選択図形登録 (1068) registered, on a
                                       lattice fixed to the drawing's origin
                                       (tests/hatchfig_test.c) */
    JW_CMD_SEIRI = 0x808e,          /* データ整理 -- CZukeiSeiri */
    JW_CMD_BLOCK = 0x8055,          /* ブロック化 -- CZukeiBlock */
    JW_CMD_BLOCK_FREE = 0x808d,     /* ブロック解除 */
    JW_CMD_BLOCK_ATTR = 0x80ca,     /* ブロック属性 */
    JW_CMD_BLOCK_EDIT = 0x80da,     /* ブロック編集 */
    JW_CMD_BLOCK_DONE = 0x80d9,     /* ブロック編集終了 */
    JW_CMD_ZUKEI = 0x805e,          /* 図形読込 -- CZukeiZukei */
    JW_CMD_ZUKEIREG = 0x80b2,       /* 図形登録 -- it takes a range of its
                                       own, and the point after 選択確定 is
                                       the 基準点 */
    JW_CMD_GAZOU = 0x80f5,          /* 画像編集 (33013) */
    JW_CMD_UNDO = 0xe12b,           /* 戻る */
    JW_CMD_REDO = 0xe12c            /* 進む */
};

int  jw_cmd(void);                  /* the current command */
void jw_cmd_set(int id);            /* enter a command */
int  jw_cmd_bar_radio(int id);      /* ラジオの点き具合: 1・0・-1（持っていない） */
int  jw_cmd_takaku_pos(void);       /* 多角形 の 中央 (1068): 0 中央・1 頂点・2 辺 */
int  jw_cmd_bunkatsu_hojo(void);    /* 分割: 逆分割・線長割合・馬目地の釦が出ているとき 1 */
void jw_cmd_flush(jw_drawing *d);
/* 建具平面: 建具選択の窓を出してほしいときは 1（読むと戻る）。選んだら
   jw_cmd_tategu_choose。catalog は src/tategu.h の jw_tgdat の番号 */
int  jw_cmd_tategu_need_pick(void);
void jw_cmd_tategu_choose(int catalog, int item);
/* 線の長さの寸法値（「線の寸法値」と同じ書き方）を `t` に作る。1 で作った */
int  jw_cmd_dim_value(const jw_drawing *d, const jw_obj *line, jw_obj *t);
int  jw_cmd_tategu_need_ref(void);     /* 基準点選択の窓を出してほしいとき 1（読むと戻る） */
int  jw_cmd_tategu_ref(void);          /* 選ばれている ○（0〜14、1689 からの順） */
void jw_cmd_tategu_set_ref(int idx);
const char *jw_cmd_bar_label(int id);   /* 釦の字が動くもの。無ければ 0 */
int  jw_cmd_hikage_ask(void);        /* 日影図 時間指定: 作図時間の窓を出してほしいとき 1・等時間の時間指定 2（読むと戻る） */
int  jw_cmd_hikage_time(jw_drawing *d, const char *txt);
/* 日影図の 季節で 任意時期 を選んだあとの 日赤緯の窓の答え（-23.45～23.45）。範囲外は 0 */
int  jw_cmd_hikage_dec(const char *txt);
int  jw_cmd_hikage_level(jw_drawing *d, const char *txt);   /* 等時間の 時間指定の答え（1 - 8） */
int  jw_cmd_hikage_answer(jw_drawing *d, int kind, const char *txt);
int  jw_cmd_kigou_need_pick(void);   /* 線記号変形: 記号の選択窓を出してほしいとき 1（読むと戻る） */
void jw_cmd_kigou_choose(int catalog, int item);
int  jw_cmd_kigou_catalog(void);
int  jw_cmd_text_mode(void);
int  jw_cmd_dim_text(jw_drawing *d, double x0, double y0, double x1, double y1);   /* 二点の間の寸法値 */          /* 文字を打つ箱が出ているとき 1 */
int  jw_cmd_kigou_item(void);
int  jw_cmd_tategu_catalog(void);       /* いま選んでいるもの。無ければ -1 */
int  jw_cmd_tategu_item(void);   /* 連続線 の手前の線を図面へ */
void jw_cmd_reset(void);            /* back to how it starts, for a new drawing */

/* The 文字 command's line, as CP932 bytes.  Jw_cad wants the text typed
   first and then the place clicked, so this is what has been typed so far. */
const char *jw_cmd_line(void);
void jw_cmd_key(int c);             /* a character, or 8 for backspace */

/* 斜体 and 太字, the two checkboxes of the 書込み文字種変更 dialog.  A text
 * written with them on carries 10000 and 20000 in its trailing long, on top
 * of whichever 文字種 it is: the original wrote 10000 for 斜体, 20000 for
 * 太字 and 30000 for both, all at 任意サイズ (decomp/res/moji{ital,bold,
 * both}.jww), and 3 for 文字種[ 3] on its own.
 */
void jw_cmd_moji_style(int italic, int bold);
int  jw_cmd_moji_italic(void);
int  jw_cmd_moji_bold(void);
/* the face a new text is written with (CP932), and setting it */
const char *jw_cmd_moji_face(void);
void jw_cmd_moji_face_set(const char *face);

/* What an IME is still converting, shown after the line but not part of it.
   The original's box is a real edit control and shows it as a matter of
   course; this port draws its own box, so it has to be told. */
const char *jw_cmd_compose(void);
void jw_cmd_compose_clear(void);
void jw_cmd_compose_key(int c);

/* 軸角 -- the angle the sheet's own axes are turned to, in degrees.  It is
 * typed into the 軸角・目盛・オフセット dialog (32842) and Ok applies it;
 * from then on 水平・垂直 snaps to it and to it plus ninety rather than to
 * flat and upright.  The original bears it out to the last digit: with 30
 * set, a drag that came out at -2.862 degrees without it made a line at
 * exactly 30 (decomp/res/jikkaku30.jww), as far along the axis as the drag
 * reached.
 */
double jw_cmd_axis(void);
/* 寸法の小数桁, for the button that shows it */
int jw_cmd_sunpo_decimals(void);
/* 寸法の端部が矢印かどうか */
int jw_cmd_sunpo_arrows(void);
void   jw_cmd_set_axis(double deg);

/* Whether 線's 水平・垂直 is on.  Pressing 線 while already in 線 flips it,
   which is all that arm of FUN_004fdc40 does when the command before was 線
   as well; with it on a line keeps whichever way the drag went further. */
int  jw_cmd_hv(void);

/* The left-hand text of the status line, in CP932.  Each command puts its
   own prompt there as it goes (FUN_004efbb0 with a string id). */
const char *jw_cmd_prompt(void);

/* the same with the original's own readout on the end: the angle and
   length of the line, the W and H of the rectangle, the radius of the
   circle -- see the note by tail_set in src/cmd.c */
const char *jw_cmd_status(const jw_drawing *d);

/* A click in the drawing area, in paper millimetres.  `button` is 0 for the
   left and 1 for the right. */
/* A click in the drawing area.  `button` is 0 for the left and 1 for the
   right; the view is needed because 消去 has to work out what is under the
   point, and how near "under" is depends on the zoom. */
void jw_cmd_point(jw_drawing *d, const jw_view *v,
                  double x, double y, int button);

/* A **double** left click, which the original writes (LL).  Two things
 * want one: 文字 の 連 -- a double click there picks the text to move, and
 * the click after it says where its start goes (tools/probe110.sh) -- and
 * ２線's 基準線変更 at its start and end points.  Anywhere else it is an
 * ordinary left click. */
void jw_cmd_point_ll(jw_drawing *d, const jw_view *v, double x, double y);

/* The mouse moved to here, in paper millimetres. */
void jw_cmd_track(double x, double y);

/* Undoing.  The view enables 元に戻る when there is something to undo --
   its ON_UPDATE_COMMAND_UI (FUN_00511a50) is Enable(list is not empty) --
   and the button is greyed out on docs/ref_start.png because there is not.
   What this can take back is the elements the commands here have added. */
int  jw_cmd_can_undo(void);
void jw_cmd_undo(jw_drawing *d);
/* 進む (0xe12c) -- one press puts one undone step back.  The original was
 * given three lines, two 戻る and then one and two 進む, and came back with
 * two lines and then three (tools/probe107.sh). */
int  jw_cmd_can_redo(void);
int  jw_cmd_undo_depth(void);   /* how many steps 戻る can take back */
/* 基本設定 一般(1) の Undo の回数（1〜100、既定 100）: 戻る で戻れる段の
   上限。超えた分は古いほうから捨てる（範囲外は何もしない）。捨てるのは
   クリック（jw_cmd_point）のあとと jw_cmd_undo_trim（表側が 戻る の前に
   呼ぶ）。src/cmd.c */
void jw_cmd_undo_limit(int n);
int  jw_cmd_undo_limit_get(void);
void jw_cmd_undo_trim(void);
unsigned jw_cmd_edit_stamp(void);   /* 0 untouched; else the last step done */
int  jw_cmd_midway(void);       /* a point down or an element picked */
/* 戻る taken by the command itself.  It answers 1 when it took the
   press and 0 when it did not, the way each command's vtable slot 16
   does -- 寸法 at its first two points is one that does not. */
int  jw_cmd_back(jw_drawing *d);
void jw_cmd_redo(jw_drawing *d);

/* Esc: let go of the points the command has taken so far, staying in the
   command.  The original does this -- its status line goes back from
   「終点を指示してください」 to 「始点を指示してください」. */
void jw_cmd_escape(void);
/* the Esc key itself: steps the command back a stage (see cmd.c) */
void jw_cmd_esc_key(jw_drawing *d);
/* Enter: 範囲確定 in the 追加・除外 stage of 複写・移動・整理.  1 if it took it. */
int jw_cmd_enter_key(jw_drawing *d);
int jw_cmd_numpos_enter(jw_drawing *d);   /* 複写・移動の 数値位置 (1413) で置く */
/* Shift+Enter: the same stage's 範囲確定 + 基点変更 together, 複写・移動
   only.  Neither front end calls this yet (see the note on the
   definition) -- it exists so the logic can be tested ahead of the
   keyboard plumbing. */
int jw_cmd_shift_enter_key(jw_drawing *d);

/* Space: turn 水平・垂直 over, which is what the original does with it. */
void jw_cmd_space(void);

/* The elements the command is part way through, if any: how many, filled in
   ready to draw (a rectangle is four lines).  They are worked out the same
   way as the ones that get added, so what is shown is what will be made. */
#define JW_CMD_MAXFIG 16        /* 多重円's rings; a rectangle is four */
int  jw_cmd_pending(jw_drawing *d, jw_obj *o, int max);

/* 範囲選択, and the two commands built on it.
 *
 * Which elements are selected is kept where the original keeps it: bit 1 of
 * the element's own flags at +0x44, which is why a drawing saved with a
 * selection still has it when it is opened again.
 *
 * A press on one of the command bar's buttons comes here by its control id
 * -- 1120 選択確定, 1067 選択解除, 1066 全選択 -- which is how the original
 * dispatches them too.  Returns 1 when the screen has to be redrawn. */
int  jw_cmd_bar(jw_drawing *d, int id);
/* 同じ釦の右押し。右押しに意味のある釦（印刷の 基準点・図形読込の 90ﾟ毎）だけ受けて 1 */
int  jw_cmd_bar_r(jw_drawing *d, int id);
/* Whether that button is there to be pressed, for the drawing of the bar. */
int  jw_cmd_bar_check(int id);
/* 接円 (32872) の 接楕円 (1065) の間: 型（10 ３点指示・20 菱形内接・30 平行四辺内接・
   50 ３点半楕円）、型を選ぶ前は -1、接楕円でなければ 0。逆コンパイルの読み、
   原典では押していない（src/cmd.c の sde_ の塊の前の注） */
int  jw_cmd_setsudaen(void);
int  jw_cmd_tenku_ask(void);                     /* 測定点が建物の内側: 問いを出すか（一度だけ 1） */
void jw_cmd_tenku_answer(jw_drawing *d, int ans);
int  jw_cmd_tenku_north_ask(void);               /* 太陽軌跡で真北が無い: 問いを出すか（一度だけ 1） */
void jw_cmd_tenku_north_answer(jw_drawing *d, int ok);   /* 1 OK（上向きで描く）・0 キャンセル */   /* 1 はい・0 いいえ・-1 キャンセル */
int  jw_cmd_hikage_pv_on(void);                 /* 日影図の 確認 の窓が開いているか */
double jw_cmd_hikage_pv_az(void);               /* その方位角（度。コンパスの向き） */
int  jw_cmd_hikage_preview(const jw_drawing *d, const jw_view *v, jw_drawing *out);   /* 窓の中身（線の数） */
void jw_cmd_renzoku_reset(void);       /* 連続線の 基準角度・基点 を素に戻す（試験用） */
void jw_cmd_sansha_reset(void);        /* 三斜のつまみ（1689/1690・1329・2114）を初めに戻す（試験用） */
/* The label 任意方向 is carrying (CP932): it cycles X, Y, XY and back. */
const char *jw_cmd_dir_text(void);
int  jw_cmd_bar_enabled(const jw_drawing *d, int id);

/* The range box while its second corner is being chosen: the original draws
   it in red (Pen/Color11) over the drawing. */
int  jw_cmd_sel_box(double *x0, double *y0, double *x1, double *y1);
/* 範囲を取る命令の段: 1 始点待ち、2 終点待ち、0 それ以外（クロスラインカーソル 2437 が見る） */
int  jw_cmd_range_phase(void);
/* How far the selection has been dragged from 基準点, once it is being
   placed.  The selected elements are drawn a second time that far away, so
   what will be made is what is shown. */
int  jw_cmd_sel_ghost(double *dx, double *dy);
/* パラメトリック変形 の仮表示: 選んだ要素を いまのマウスの位置で変形したもの
   （枠に端点だけ入った線は その端点だけ動く）。1 なら out に入れた */
int  jw_cmd_param_preview(const jw_drawing *d, jw_drawing *out);
/* How many elements are selected. */
int  jw_cmd_sel_count(const jw_drawing *d);
/* Take the settled selection out of the drawing, which is what entering 消去
   with one in hand does.  Returns 1 if anything went. */
int  jw_cmd_sel_erase(jw_drawing *d);

/* 属性選択 -- narrow what is picked to the kinds ticked in the 1069 dialog,
 * or with 除外 to everything but those.  The mask is JW_ZOK_*; a mask of
 * nothing leaves the selection as it was.  Returns how many are left.
 */
enum {
    JW_ZOK_SEN   = 1,           /* 直線指定   1812 */
    JW_ZOK_ENKO  = 2,           /* 円指定     2434 */
    JW_ZOK_TEN   = 4,           /* 実点指定   2430 */
    JW_ZOK_MOJI  = 8,           /* 文字指定   1804 */
    JW_ZOK_SOLID = 16,          /* ソリッド図形指定 2433 */
    JW_ZOK_HOJO  = 32,          /* 補助線指定 2431 */
    JW_ZOK_BLOCK = 64           /* ブロック図形指定 1802 */
};
/* `color` and `ltype` are 指定【線色】指定 and 指定 線種 指定: ticking
 * either and pressing OK puts the **線属性 dialog** up, and what is picked
 * there is what the filter means.  That is where the "指定" came from.
 * 0 for one means it was not asked for.
 */
int  jw_cmd_zokusel(jw_drawing *d, int mask, int exclude, int color,
                    int ltype);
/* the block name ブロック名指定 narrows ブロック指定 to, "" for none */
void jw_cmd_zokusel_name(const char *name);

/* 属性変更 (範囲選択's 1070) -- the same dialog with its other half showing.
 * Only the two that could be driven are done: 書込【レイヤ】に変更 moves
 * everything picked to the write layer (twelve elements on layer 0 came back
 * on layer 8, decomp/res/zhlayer.jww) and 書込レイヤグループに変更 does the
 * same for the group.  指定【線色】に変更 and 指定 線種 に変更 changed
 * nothing at all when they were driven, the same way the 指定【線色】指定
 * filter matches everything -- where the "指定" one comes from is still not
 * known.  Returns how many elements were changed.
 */
/* `to_color` and `to_ltype` come from the same 線属性 dialog, which
 * 指定【線色】に変更 and 指定 線種 に変更 put up on OK.  The colour goes on
 * everything picked; the line type reaches lines and arcs only.
 */
int  jw_cmd_zokuhen_range(jw_drawing *d, int to_layer, int to_group,
                          int to_color, int to_ltype);

/* 図形読込 (32862).  The original puts up a file window of its own -- not a
 * common dialog -- and once a .jws is picked the figure hangs on the cursor
 * until a point is clicked.  The port has no file window, so the front end
 * hands the bytes over here; that enters the command, and the next point
 * places the figure.  Returns 0 if the file is not a figure.
 *
 * What the original does with it, read out of decomp/res/figin.jww (Test5,
 * whose write group is at 1/200, given the 1/100 figure decomp/res/fig.jws):
 *
 *   * the figure is scaled by **its own layer-group scale over the write
 *     group's** -- 100/200, so the 6mm box came in 3mm wide.  The figure
 *     keeps the size it stands for on the ground, not on the paper.
 *   * the base point in the .jws header lands on the clicked point.
 *   * colour and line type come with the figure; the layer and the layer
 *     group are the drawing's write ones (the figure's own layer 4 became
 *     layer 8).
 */
int  jw_cmd_figure_load(jw_drawing *d, const unsigned char *b, long n);
int  jw_cmd_figure_ready(void);

/* 伸縮・消去の 一括処理 (1064) の途中か（バーに 処理実行 1065 を出す） */
int  jw_cmd_ikkatsu(void);

/* The figure as it hangs off the cursor before the point that puts it
 * down.  The original paints it the whole time, in 仮表示, where the
 * click would put it, and goes on painting it after one has been placed
 * (tools/probe80.sh, probe81.sh, probe83.sh).  Nought when there is no
 * figure or the mouse has not moved yet; otherwise *out is a drawing
 * ready for jw_draw -- it borrows the figure's elements and string pool
 * and must not outlive the next call. */
int  jw_cmd_figure_preview(const jw_drawing *d, jw_drawing *out);
int  jw_cmd_tategu_preview(const jw_drawing *d, jw_drawing *out);   /* 建具の仮表示 */

/* 座標ファイル (32895) の ファイル読込 -- the same, from the text file. */
int  jw_cmd_coord_load(jw_drawing *d, const unsigned char *b, long n);

/* The 倍率 and 回転角 of its bar, which the next placement goes down at.
 * Driving the original with 倍率 2 and 回転角 30 put the figure down at
 * click + R(30) * 2 * (scale ratio) * (point - base point), to six places
 * (decomp/res/figin2.jww).  Reading a figure puts them back at 1 and 0.
 */
void jw_cmd_figure_at(double mag, double deg);

/* 図形登録 (32946): the elements picked by a range go out as a .jws, with
 * (bx, by) -- the 基準点 the command asks for after 選択確定 -- in its
 * header.  The caller frees *out.  Returns 0 if it could not.
 */
/* 切り取り・コピー・貼り付け.  The original's clipboard is a 図形 --
   貼り付け puts up 図形読込's own command -- so these go through the
   same .jws the 図形 calls above do. */
/* 文字の 基点 (1064): 0..8 for 左上 左中 左下 中上 中中 中下
   右上 右中 右下, which is the order of the dialog's own radios
   1689..1697.  It comes up on 2 -- 左下. */
/* 文読 (1069): the bytes of a text file, in place of the original's
   own 「開く」.  The lines then go down from the next click, 行間 apart
   -- which is **twice** what that box holds, in millimetres of paper. */
int  jw_cmd_text_load(jw_drawing *d, const unsigned char *b, long n);
int  jw_cmd_text_ready(void);

void jw_cmd_moji_base(int n);
int  jw_cmd_moji_base_now(void);
/* ずれ使用 (1323) and the six boxes beside it: `across` picks the
   横ずれ row of three (左中右) or the 縦ずれ one (上中下), in
   millimetres of paper.  The text's start moves by minus each of them. */
void jw_cmd_moji_zure(int on);
int  jw_cmd_moji_zure_now(void);
void jw_cmd_moji_zure_at(int across, int n, double v);
double jw_cmd_moji_zure_get(int across, int n);
/* and the six boxes of the dialog as text, which is what is typed into
 * them and what is painted in them.  The ids are 2004/2005/2006 across
 * (左中右) and 2009/2008/2007 down (上中下). */
const char *jw_cmd_moji_zure_box(int id);
int  jw_cmd_moji_zure_key(int id, int c);
/* 下線作図 (1327)・上線作図 (1328)・左右縦線 (1329) on the
   same dialog: the lines ruled round a text as it is placed. */
void jw_cmd_moji_rule(int which, int on);
int  jw_cmd_moji_rule_now(int which);

int  jw_cmd_clip_copy(jw_drawing *d, int cut);
int  jw_cmd_clip_has(void);
int  jw_cmd_clip_paste(jw_drawing *d);

int  jw_cmd_figure_save(const jw_drawing *d, double bx, double by,
                        unsigned char **out, long *n);

/* Whether the last point was 図形登録's 基準点, which is the moment the
   front end has to ask for a file name.  Says so once and forgets. */
int  jw_cmd_figure_base(double *x, double *y);

/* 中心点取得 (33016) and the other one-shot read modes of the 設定 menu.
 * The next point is not where it was clicked: the status line spells the
 * rule out -- 「線・円指示で線・円の中心点　　　読取点指示で２点間中心」.
 * Pointing at a line gives its middle, at a circle or arc its centre; two
 * read points give the point half way between them.  It lasts for one point
 * and then goes off.  0 is none.
 */
/* 33016 中心点取得, 33028 円周1/4点取得 (the nearest of the picked circle's
 * four quarter points) and 33017 線上点 (pick a line, then the next point is
 * dropped onto it at right angles; (L) on another line or circle gives
 * their crossing, (R) a read point -- FUN_0076fae0, read off the decompile).
 */
void jw_cmd_read_mode(int mode);
int  jw_cmd_read_mode_now(void);

/* 設定 > 角度取得 and 設定 > 長さ取得: the next click or two gives a
   number that then stands in for the 傾き or the 寸法 box until the
   command is left. */
void jw_cmd_get_mode(int mode);
int  jw_cmd_get_mode_now(void);

/* 測定 (32897): which of the four 〜測定 is chosen (the button's id),
   whether the unit is mm rather than ｍ, and 小数桁 as 0..4 or 5 for F. */
int  jw_cmd_sokutei_mode(void);
int  jw_cmd_sokutei_mm(void);
int  jw_cmd_sokutei_dms(void);   /* 角度測定 の 1069: 度分秒 */
int  jw_cmd_sokutei_dp(void);

/* 寸法設定 (32925): the boxes that are wired up, by the id each one
   carries on the dialog.  jw_cmd_sunpo_box fills `out` with what the box
   should show and answers 1; the ones that are not done yet answer 0 and
   are drawn empty.  See the 寸法設定 note in src/cmd.c for what each one
   was measured to do. */
/* 任意色（ソリッドの色 10）。窓とのやりとりは 0x00rrggbb で、
   中では原典と同じ COLORREF のまま持っています。 */
unsigned int jw_cmd_any_color(void);
void jw_cmd_any_color_set(unsigned int rgb);

int  jw_cmd_sunpo_box(int id, char *out, int n);
void jw_cmd_sunpo_box_set(int id, const char *t);
/* 寸法設定 のチェックボックスとラジオ。jw_cmd_sunpo_chk は 点いていれば 1、
   消えていれば 0、繋いでいない id は -1。ラジオは選ばれているかどうか。
   jw_cmd_sunpo_chk_set はラジオなら on のときだけ その一つを選ぶ。
   jw_cmd_sunpo_radio_group はラジオの組の頭の id（ラジオでなければ 0） */
int  jw_cmd_sunpo_chk(int id);
void jw_cmd_sunpo_chk_set(int id, int on);
int  jw_cmd_sunpo_radio_group(int id);
/* 寸法 の ＝ (1060): 0 ふつう、1 ＝(1)、2 ＝(2)、3 －。jw_cmd_sunpo_move は
   基準点のあとの「ﾏｳｽ移動で確定」をマウスの動きで進め、進めば 1 */
int  jw_cmd_sunpo_eq(void);
int  jw_cmd_sunpo_move(const jw_view *v, double x, double y);
int  jw_cmd_get_kata(double *deg);
int  jw_cmd_get_naga(double *mm);
/* 間隔取得 (32948): the perpendicular distance from a point to a line,
 * which is what 複線 then copies by.  Nought if none has been taken. */
int  jw_cmd_get_kankaku(double *out);

/* How far a range command has got: 0 nothing, 1 the first corner is in, 2 a
   range is picked, 3 it is settled (4 for 範囲選択, which stops there).  The
   bar for a command changes at 3, so the drawing of it has to know. */
int  jw_cmd_sel_stage(void);

/* ブロック化 -- turn what is picked into a definition of that name and put
 * one reference to it in their place.  Returns how many went in, 0 if it
 * could not.  `prefer_layer` is the dialog's 元データのレイヤを優先する.
 */
int  jw_cmd_block_make(jw_drawing *d, const char *name, int prefer_layer);
/* Where a block made of what is picked would go: the average of one point
   per element.  Returns 0 if nothing is picked. */
int  jw_cmd_block_point(const jw_drawing *d, double *x, double *y);
/* ブロック解除 -- put back the elements of every reference that is picked,
   and drop a definition nothing refers to any more.  Returns how many
   references were undone. */
int  jw_cmd_block_free(jw_drawing *d);
/* ブロック属性 -- the only thing its dialog can change is 元データのレイヤを
   優先する, which is bit 64 of a reference's own line type.  Returns how
   many references it was put on or taken off. */
int  jw_cmd_block_attr(jw_drawing *d, int prefer_layer);

/* ブロック編集 -- while it is on, whatever is drawn goes into the picked
 * block's definition instead of into the drawing, so it shows up through
 * every reference to it at once.  jw_cmd_block_edit starts it on the first
 * reference that is picked (0 if none is), jw_cmd_block_done ends it, and
 * jw_cmd_block_take moves anything added since `from` into the definition.
 */
int  jw_cmd_sel_text(const jw_drawing *d, char *out, int cap);
int  jw_cmd_block_edit(jw_drawing *d);
/* ブロックツリー: a node is the place of a reference in d->obj; -1 is the
   root.  Names are the definition's, without the @@SfigorgFlag@@n. */
const char *jw_bt_name(const jw_drawing *d, int ref);
int  jw_bt_kids(const jw_drawing *d, int parent, int *out, int max);
int  jw_bt_has_kids(const jw_drawing *d, int ref);
/* the same on the reference at the end of a path of places in d->obj,
   outermost first (ブロックツリー) */
int  jw_cmd_block_edit_path(jw_drawing *d, const int *path, int n);
int  jw_cmd_block_rename_path(jw_drawing *d, const int *path, int n,
                              const char *name);
void jw_cmd_block_done(void);
int  jw_cmd_block_editing(void);
/* The name of the block being edited, for the dialog. */
const char *jw_cmd_block_name(const jw_drawing *d);
void jw_cmd_block_take(jw_drawing *d, int from);
/* ブロック名変更: the name the dialog's box holds becomes the block's, with
   the @@SfigorgFlag@@4 the original puts on the end. */
int  jw_cmd_block_rename(jw_drawing *d, const char *name);
/* 選択したブロックのみに反映させる: the definition is copied for the one
   reference being edited, so that editing it leaves the others alone.  The
   copy is numbered after the last one and named <name>(<number>). */
int  jw_cmd_block_split(jw_drawing *d);

/* 寸法's direction in degrees: what the 傾き box (1411) says, which the command bar's
   0ﾟ/90ﾟ button (id 1059) swaps between 0 and 90 and a typed number sets to anything. */
int  jw_cmd_sunpo_angle(void);

/* The boxes on the command bar that can be typed into -- 多角形's 寸法,
   角数 and 底辺角度 so far.  The text of one, or NULL if the port does not
   keep that box; `focus` is the one being typed into, 0 for none. */
const char *jw_cmd_box(int id);
int  jw_cmd_box_focus(void);
void jw_cmd_box_click(int id);      /* a press on one: it takes the typing */
int  jw_cmd_box_key(int c);         /* a character; 1 if it was taken */
int  jw_cmd_box_put(int id, const char *v);  /* replace one's text */

/* 作図属性設定's four ticks for 複写・移動: 0 書込み線種, 1 書込み線色,
   2 書込み【レイヤ】, 3 書込みレイヤグループ */
/* 基本設定 2446「[レイヤ非表示化]を[表示のみレイヤ化]にする」 */
void jw_cmd_layhide_shown(int on);
/* 基本設定 1522「表示のみレイヤも属性取得」 */
void jw_cmd_get_shown_too(int on);
/* 基本設定 2100「線長取得で円を指示したとき、円半径取得を円周長取得にする」 */
void jw_cmd_get_arc_length(int on);
/* 基本設定 2466「文字コマンドのとき文字位置指示後に文字入力を行う」 */
void jw_cmd_moji_point_first(int on);
/* 基本設定 2094「複線のとき、数値入力後の[Enter]キーで連続複線にする」: 立って
   いれば 複線 で元を拾い間隔を打ったあとの Enter が、マウスの側へその間隔で写し、
   写しを次の元にする（Enter を押すたびに一本）。写したら 1 */
void jw_cmd_fukusen_enter_on(int on);
/* 基本設定 一般(2) 2525: 箱の式の一つの \ を 1000 に（\\ は x のまま断る） */
void jw_cmd_yen_m(int on);
int  jw_cmd_fukusen_enter(jw_drawing *d, const jw_view *v);
int  jw_cmd_zuzoku(int k);
void jw_cmd_zuzoku_set(int k, int on);
/* 図形読込の 作図属性 (1067): 同じ四つ（0 書込線種・1 書込線色・2 書込レイヤ・
   3 書込グループ）を図形の分として。既定は 書込レイヤ・書込グループ */
int  jw_cmd_fzoku(int k);
void jw_cmd_fzoku_set(int k, int on);

/* 設定 > 環境設定ファイル: 書出し (the original's file with what the drawing
   holds put in) and 読込み (what it holds taken back).  The caller frees
   *out. */
int  jw_env_write(const jw_drawing *d, const char *name, unsigned char **out,
                  long *n);
int  jw_env_read(jw_drawing *d, const unsigned char *b, long n);


/* 画像編集 (33013) -- see the block at the end of src/cmd.c.  The front end
 * hands a file over with jw_cmd_gazou_insert when jw_cmd_gazou_file says 画像挿入
 * was pressed; shows the message box jw_cmd_gazou_ask wants and answers it
 * with jw_cmd_gazou_answer; and puts the 透過色 dialog up when
 * jw_cmd_gazou_tp_ask says so. */
int  jw_cmd_gazou_file(void);               /* 1 once after 画像挿入 */
int  jw_cmd_gazou_insert(jw_drawing *d, const char *path, const unsigned char *b, long n);
int  jw_cmd_gazou_inserting(void);          /* a file read, the 基準点 is next */
int  jw_cmd_gazou_ask(const char **text);   /* 1 OK+キャンセル, 2 OK only, 0 none */
void jw_cmd_gazou_answer(jw_drawing *d, int ok);
int  jw_cmd_gazou_tp_ask(int *r, int *g, int *b);
void jw_cmd_gazou_tp_set(jw_drawing *d, int r, int g, int b);
int  jw_cmd_gazou_check(int id);
int  jw_cmd_gazou_enabled(int id);
int  jw_cmd_gazou_mode(void);
const char *jw_cmd_gazou_prompt(void);
/* where the drawing is, for 相対パス and 同梱画像分離 (CP932; dir "" if unknown) */
void jw_cmd_gazou_doc(const char *dir, const char *name);
/* what 同梱画像分離 wrote: the files for the front end to put in the folder */
int  jw_cmd_gazou_out(int i, const char **name, const unsigned char **b, long *n);
int  jw_cmd_gazou_out_ready(void);          /* 1 once after a 画像分離 left files */


/* 外部変形 (32913): put what the program wrote to JWC_TEMP.TXT into the
   drawing (see jw_gaibu_read in jww.h).  Returns the elements made, -2 if the
   program did not run, -1 if the text is not readable. */
int  jw_cmd_gaibu_commit(jw_drawing *d, const unsigned char *b, long n,
                         double ox, double oy, jw_gaibu_out *out);

/* 文字の 範囲選択 (2407): the picked texts as a file (文書, 外部エディタ's TEMP.TXT),
   the lines of a file put back onto them (外部エディタ, 貼付), and the 1092
   switch between SJIS and UTF8 (1 = SJIS).  See src/cmd.c. */
int  jw_moji_sjis(void);
void jw_moji_sjis_set(int on);
int  jw_moji_sjis_toggle(void);
int  jw_cmd_moji_count(const jw_drawing *d);
int  jw_cmd_moji_edit_text(const jw_drawing *d, unsigned char **out, long *n);
int  jw_cmd_moji_doc(jw_drawing *d, unsigned char **out, long *n);
int  jw_cmd_moji_apply(jw_drawing *d, const unsigned char *b, long n);

int  jw_cmd_moji_ready(void);               /* texts picked (2407 done) */
/* コピー・切り取りが控えた選んだ字（UTF-8、BOM 付き、一行一字）、貼付 (1065) が
   それを使う（控えが空なら -1、表側がクリップボードから）、文字を出るときの選択の扱い */
int  jw_cmd_moji_clip(const unsigned char **b, long *n);
int  jw_cmd_moji_paste(jw_drawing *d);
void jw_cmd_moji_leave(jw_drawing *d, int id);
int  jw_cmd_moji_go(void);                  /* 外部エディタ was waiting for the range */

/* 外部変形's steps: the front end hands over the BAT, the command walks the
   script, and says when the run can start (see the end of src/cmd.c) */
int  jw_cmd_gaibu_load(jw_drawing *d, const char *bat, long n);
int  jw_cmd_gaibu_active(void);
int  jw_cmd_gaibu_ready(void);
int  jw_cmd_gaibu_key(jw_drawing *d, int c);
int  jw_cmd_gaibu_origin(double *x, double *y);
int  jw_cmd_gaibu_session(const char **bat, long *bn, int *item,
                          const double (**xy)[2], char (**val)[128]);
void jw_cmd_gaibu_done(void);
int  jw_cmd_gaibu_want_bat(void);

int  jw_cmd_gaibu_tags(const jw_drawing *d, int *num, char *kind, int max);

int  jw_cmd_gaibu_preview(const jw_drawing *d, jw_drawing *out);   /* the rubber line */

int  jw_cmd_clip_get(const unsigned char **b, long *n);
int  jw_cmd_clip_set(const unsigned char *b, long n);

/* 連続線 の 手書線 (1774): the button down is jw_cmd_point; while it is held, each move
   goes to jw_cmd_drag (a line for every 5 pixels the mouse has gone) and the button
   coming up to jw_cmd_release.  Both return 1 when the picture changed. */
int  jw_cmd_freehand(void);
int  jw_cmd_drag(jw_drawing *d, const jw_view *v, double x, double y);
int  jw_cmd_release(jw_drawing *d, const jw_view *v, double x, double y);

/* 伸縮: the right pressed once on a line or arc, the mouse moving more than 2
   pixels cuts it there (線切断).  1 when the drawing changed. */
int  jw_cmd_stretch_move(jw_drawing *d, const jw_view *v, double x, double y);

/* 札（知らせ）: 原典の FUN_005168b0(文字列番号, 押した画素 +0x8f24/+0x8f28, 0, 0)。
   命令が「計算できません」「図形がありません」などを出すところで呼ぶ。`s` は
   その番号の文（CP932、src/gen/prompts.h の JW_STR_<番号>）。JW_NOTICE(5205) と
   書けば番号と文が揃う。出たものは次に押すか、命令を替えるか、マウスが札の上に
   乗るまで残る（消すのは app.c と jw_cmd_set、描くのは ui_notice）。
   jw_cmd_notice_id は出ている札の番号（無ければ 0）、_seq は出すたびに一つ進む。
   逆コンパイルの読み、原典では押していない（src/cmd.c の jw_cmd_notice の注）。 */
void jw_cmd_notice(int id, const char *s);
#define JW_NOTICE(n) jw_cmd_notice((n), JW_STR_##n)
int  jw_cmd_notice_id(void);
const char *jw_cmd_notice_text(void);
unsigned jw_cmd_notice_seq(void);
void jw_cmd_notice_clear(void);

/* 範囲選択 (32787) の 文字位置･集計 (1071)。逆コンパイルの読み、原典では押して
   いない（src/cmd.c の mp_enter の前の注）。jw_cmd_mp_on は そのバー（9020）が
   出ているか。基点 (1072) は 文字基点設定 の窓で選ぶ 0..8（jw_cmd_moji_base と
   同じ並び、既定 2 = 左下）。集計書込 (1121) は 文字集計設定 (351) の OK で
   jw_cmd_mp_sum_set(1)、もう一度押すと切れる。_cfg は その窓の値
   （書込文字種 1..10、区切り 0..2、ソート、ブロック名、後に書く、書かない、
   文頭・文末の追加文字） */
int  jw_cmd_mp_on(void);
int  jw_cmd_mp_base_now(void);
void jw_cmd_mp_base(int n);
int  jw_cmd_mp_sum(void);
void jw_cmd_mp_sum_set(int on);
void jw_cmd_mp_sum_cfg(int *shu, int *tab, int *sort, int *block,
                       int *back, int *non, const char **pre,
                       const char **post);
void jw_cmd_mp_sum_cfg_set(int shu, int tab, int sort, int block, int back,
                           int non, const char *pre, const char *post);

#endif
