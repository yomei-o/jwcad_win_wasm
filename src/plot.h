/* Printing: the drawing as a PDF or a PNG.
 *
 * The browser has no printer and the native build has no print dialog, so
 * the port hands the person the two things a print is for: a PDF to send
 * to a printer and a PNG to look at.  jwcad_dos_wasm does the same.
 *
 * **The page is the sheet, one to one.**  That is not a guess: the
 * original was made to print, with Microsoft Print To PDF as the printer,
 * and the PDF it wrote was measured (tools/probe29.sh .. probe33.sh).
 *
 *   ファイル > 印刷 (57607) puts up the Windows printer dialog; OK takes
 *   the original into a print mode whose command bar has 印刷 (L) on
 *   1065, and pressing that asks where to put the file.
 *
 *   A line drawn 61.2245 by 30.6122 mm on the sheet came out of that PDF
 *   231.36 by 115.68 units on a 96 dpi page -- 61.2245 by 30.6122 mm.
 *   **One to one.**  Its position says where the sheet goes: the line ran
 *   from (-33.06,-4.29) to (28.16,-34.90) in sheet millimetres and landed
 *   at (71.92,152.76) and (133.14,183.37) from the top left of an A4
 *   page, which is 105,148.5 -- the **middle of the page** -- plus those
 *   two, with y the other way up.  A longer line came back clipped to the
 *   page exactly, so nothing is scaled to fit: what does not reach the
 *   paper is simply not printed.
 *
 * The port has no printer to take the paper size from, so its page is the
 * drawing's own 用紙 -- which is the one page that never clips.
 *
 * Three more things came out of that PDF, and they are the original's own
 * answers rather than choices made here:
 *
 *   the ink     `0 0 0 RG`, black.  カラー印刷 (1343) on the print bar is
 *               **off** as the bar comes up, so a print is black unless
 *               it is asked for in colour, and then the colours are the
 *               drawing's own printing pens (+0x24 in the header, which
 *               src/jww.c reads into print_rgb) and not the screen ones.
 *   the width   `0.640 w` at 96 dpi is 0.1693 mm, and the drawing's
 *               print_width for that pen is 2: 2 dots at 300 dpi is
 *               0.1693 mm exactly.  So a pen's printed width is its
 *               print_width in three-hundredths of an inch.
 *   the ends    `1 J 1 j` -- round caps and round joins.
 *
 * Four more, from printing tools/mkpoints.c's drawing twice, black and
 * in colour (tools/probe35.sh, probe36.sh, decomp/res/print_points.txt):
 *
 *   the ninth   **neither 補助線 (line type 9) nor 補助線色 (colour 9)
 *               is printed** -- nine lines went to the printer each way
 *               and eight came back each way
 *   the colours カラー印刷 prints the drawing's print_rgb: 線色1 water
 *               blue, 線色4 yellow, 線色7 the colour of a duck's wing
 *   a point     only the kind whose trailing long is **0** prints, and it
 *               prints as five short strokes making a dot a third of a
 *               millimetre across.  Swapping the two kinds over moved the
 *               dot with the long and not with the place, so it is the
 *               long that decides
 *   a solid     `h B*` -- closed, filled **and** stroked, at the pen's
 *               own width, with its four corners in the order they are
 *               stored
 */
#ifndef JW_PLOT_H
#define JW_PLOT_H

#include "jww.h"

/* The page, in millimetres: the drawing's own sheet. */
void jw_plot_paper(const jw_drawing *d, double *wide, double *tall);

/* A one-page PDF of the drawing, malloc'd; null if there was no memory.
 * `colour` prints the drawing's printing pens instead of black, which is
 * what カラー印刷 does.  Japanese goes in as CP932 through the
 * 90ms-RKSJ-H encoding of one of PDF's own CJK fonts, so nothing has to
 * be embedded. */
unsigned char *jw_plot_pdf(const jw_drawing *d, int colour, long *len);

/* And a PNG, `dpmm` pixels to the millimetre (4 is a readable A2).  This
 * one goes through the port's own src/draw.c, so what comes out is the
 * screen's picture at whatever size is asked for -- the same arcs, the
 * same dashes, the same glyphs -- with the printing pens in place of the
 * screen ones and white paper under it. */
unsigned char *jw_plot_png(const jw_drawing *d, double dpmm, int colour,
                           long *len);

/* ------------------------------------------------------------------------
 * 印刷の命令 —— 印刷範囲を設定 (32851 = 0x8053、CZukeiPrintHanni)。
 * 逆コンパイルの読み、原典では押していない（印刷は Windows の印刷の窓を
 * 通らないと入らないので、無人では駆動していない）。
 *
 * 原典の 印刷 (57607) は OnPreparePrinting（FUN_0050be70）で印刷の窓を出し、
 * OK なら FUN_004fdba0(0x8053) でこの命令に入る。入るとき FUN_004fccb0 が
 * プリンタの GetDeviceCaps(HORZSIZE/VERTSIZE)（mm の整数）を doc+0x8f08/0x8f0c
 * に取る。移植にはプリンタが無いので、紙は図面の用紙（jw_plot_paper）。
 *
 * 枠（slot 8 FUN_006d2cb0）: 半幅 = (int)((紙の幅/2 の整数割り) / 倍率)、
 * 半高も同じ。回転 (+0x3030) が 0 でなければ縦横を入れ替える。四本の線は
 * 左下 → 右下 → 右上 → 左上 → 左下。基準点 (+0x3048、0..8 = 左・下 中・下
 * 右・下 左・中 … 右・上) は 枠のどこがマウスに付くか: 左なら中心から −半幅、
 * 中なら 0、右なら +半幅（縦も 下・中・上 で同じ）。
 *
 * 段 (+0x8560):
 *   0「印刷範囲を確認してください。(L)印刷 (R)変更」（5334）—— 枠は中心
 *     (+0x3038/+0x3040) に止まっている。(L) は slot 9 が 1 を返して slot 3
 *     → slot 26 で印刷。(R)（slot 11）は 枠の基準点にマウスを置いて段 1 へ。
 *   1「印刷範囲を指示してください。(L)free (R)Read」（5335）—— 枠の基準点が
 *     マウスに付いて動く。(L) はその点、(R) は読取点（FUN_00451eb0）で 中心を
 *     決めて段 0 へ。戻る (slot 16) は段 0 へ戻すだけ。
 *
 * バー（DIALOG 291、decomp/res/bars8.txt）:
 *   1065 印刷 (L)     slot 26。段 0 のときだけ刷る
 *   1064 範囲変更 (R) slot 25。段を 0 にしてマウスの所で (R) を送る ＝ 段 1 へ
 *   1066 基準点       左で 次（8 の次は 0、FUN_00550280）。字は 5222..5230。
 *                     右押しで 左・下 に戻す（FUN_00550310）のは、移植のバーが
 *                     釦の右押しを命令へ渡さないので入れていない
 *   1411 倍率         200% 141% 100% 71% 50% 35% 25%（DLGINIT 291）と
 *                     任意倍率。倍率は 2・√2・1・1/√2・0.5・1/(2√2)・0.25
 *                     （FUN_005adde0 が 1e-5 で突き合わせる値）
 *   1070 回転         slot 31。0 → 1 → 2 → 0。字は「回転 　０°」「９０°回転」
 *                     「－９０°回転」（5772..5776、FUN_005ae8a0）
 *   1343 カラー印刷   刷る前に doc+0x8288 へ（FUN_006d4920）
 *   1068 枠書込       slot 29。枠の四本を図面に書く
 *   1067 プリンタの設定・1069 出力方法設定 はブラウザでは窓が無いので押せない。
 *                     ネイティブは jw_pr_dialogs(1) で押せ、窓は src/prnative.h
 *
 * 刷り方: 回転は 刷るときだけ（FUN_0044b760 が IsPrinting のとき
 * FUN_00452e30）、要素を 枠の中心のまわりに ９０° なら −π/2、−９０° なら
 * +π/2 回して描く（FUN_0046d5b0）。紙の中心に 枠の中心が来て、倍率を掛ける
 * （倍率 1・中心 0 で 用紙の中心が紙の中心に来るのは原典の PDF で測った。
 * それ以外の倍率と中心は読み）。線幅・線種の刻みは プリント出力形式 の
 * 「線幅も倍率」(1330、既定は切) が入っているときだけ倍率を掛ける（窓は
 * ネイティブの src/prnative.h、値は jw_pr_opt）。点の大きさは掛けない。
 */
#define JW_PRINT_CMD 0x8053

typedef struct {
    double cx, cy;      /* 枠の中心（用紙の mm）: 紙の中心に来る */
    double scale;       /* 倍率 */
    int rot;            /* 0 ０°、1 ９０°（−π/2 回す）、2 −９０°（+π/2） */
    int colour;         /* カラー印刷 */
    /* プリント出力形式（DIALOG 344）から。jw_pr_settings が埋める */
    int wscale;         /* 1330 線幅も倍率: 線幅と線種の刻みにも倍率を掛ける */
    int by;             /* 連続出力: 0 しない、1 レイヤごと (1324)、2 レイヤグループごと (1323) */
    int keep1;          /* 1325・1326: 共通（表示のみ）を表示のみのまま */
    int page;           /* PNG で刷る頁（連続出力のとき。0 から） */
} jw_plot_frame;

/* 連続出力の頁の数（f が 0 か 連続出力でなければ 1。刷る頁が無ければ 0） */
int jw_plot_npages(const jw_drawing *d, const jw_plot_frame *f);

/* プリント出力形式（DIALOG 344）の箱の値。id はその箱の id
 * （1323〜1331・1333・2113・2114）。1064・1065 は持たない。既定はみな 0 */
int  jw_pr_opt(int id);
void jw_pr_set_opt(int id, int v);
void jw_pr_new_doc(void);               /* 新規: 1323〜1326 を 0 に（FUN_004d20c0） */

/* 枠と倍率と回転のとおりに刷る。f が 0 なら上の二つと同じ */
unsigned char *jw_plot_pdf_at(const jw_drawing *d, const jw_plot_frame *f,
                              long *len);
unsigned char *jw_plot_png_at(const jw_drawing *d, const jw_plot_frame *f,
                              double dpmm, long *len);

/* いまの印刷の設定（命令の外でも、最後に決めた枠・倍率・回転・カラー印刷） */
void jw_pr_settings(jw_plot_frame *f);

/* 命令の側（src/cmd.c が呼ぶ） */
void jw_pr_enter(void);
int  jw_pr_stage(void);                 /* 0 確認、1 指示 */
/* クリック。button 0 左・1 右。read_ok は (R) で読取点が取れたか（rx, ry）。
   刷ることになったら 1 */
int  jw_pr_click(const jw_drawing *d, double x, double y, int button,
                 int read_ok, double rx, double ry);
void jw_pr_track(double x, double y);
int  jw_pr_bar(const jw_drawing *d, int id);   /* 受けたら 1 */
int  jw_pr_bar_r(int id);               /* 釦の右押し。受けたら 1 */
int  jw_pr_enabled(int id);
const char *jw_pr_label(int id);        /* 字の動く釦。無ければ 0 */
const char *jw_pr_prompt(void);
int  jw_pr_back(void);                  /* 段 1 → 0 なら 1 */
int  jw_pr_frame(const jw_drawing *d, double *x0, double *y0,
                 double *x1, double *y1);
int  jw_pr_write_frame(jw_drawing *d);  /* 枠書込: 足した線の数 */
int  jw_pr_want(void);                  /* 刷る頼み（読むと消える） */
double jw_pr_scale_of(const char *box); /* 倍率の箱の字から倍率（0 は読めない） */
void jw_pr_reset(void);                 /* 試験用: 素に戻す */

/* 印刷の窓のある表側（ネイティブ）のため。jw_pr_dialogs(1) で
 * プリンタの設定 (1067)・出力方法設定 (1069) が押せるようになり、押すと
 * jw_pr_ask がその id を返す（読むと消える。原典 FUN_005aeaf0 は
 * ID_FILE_PRINT_SETUP 0xe106、FUN_005aeb40 は プリント出力形式 DIALOG 344）。
 * jw_pr_entered は命令に入ったら一度 1（原典は入る前に印刷の窓、
 * OnPreparePrinting FUN_0050be70）。jw_pr_printer_paper は選んだプリンタの
 * GetDeviceCaps(HORZSIZE/VERTSIZE) の mm（0 で図面の用紙に戻す。原典
 * FUN_004fccb0 が doc+0x8f08/0x8f0c に取るもの）で、枠と刷る紙がそれになる */
void jw_pr_dialogs(int on);
int  jw_pr_ask(void);
int  jw_pr_entered(void);
void jw_pr_printer_paper(double w, double h);
void jw_pr_paper(const jw_drawing *d, double *wide, double *tall);  /* 刷る紙の mm */

#endif
