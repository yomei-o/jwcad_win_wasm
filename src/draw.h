/* Drawing a .jww into the framebuffer. */
#ifndef JW_DRAW_H
#define JW_DRAW_H

#include "fb.h"
#include "jww.h"
#include "view.h"

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d);
/* ブロックツリーで選んだ参照を選択色で描く。path は d->obj の添字を外側から */
void jw_draw_hl(const jw_drawing *d, const int *path, int n);
int  jw_draw_hl_n(void);
const int *jw_draw_hl_path(void);

/* The selection being dragged: every picked element drawn again dx,dy away,
   in the colour a picked element has.  What it shows is what a click will
   make. */
void jw_draw_sel(fb_t *fb, const jw_view *v, const jw_drawing *d,
                 double dx, double dy);
/* The range box, in the colour the original draws it (src/gen/pens.h). */
void jw_draw_box(fb_t *fb, const jw_view *v,
                 double x0, double y0, double x1, double y1);

/* one bit of a line type's pattern, for drawing a sample of it */
int jw_ltype_bit(int ltype, int i);

/* 基本設定 の 線種 タブ（線種 2〜9）: パターンはレジストリ・タブの字と同じ
   上の桁から（Line\Type_0n の値そのまま）、単位 1〜32 ドット、画面のピッチ
   1〜16。範囲の外は 0 を返して何も変えない。jw_ltype_get は今の値（線種 1
   は 0xffffffff・32・1 のまま変えられない） */
int jw_ltype_set(int ltype, unsigned int pattern, int unit, int pitch);
void jw_ltype_get(int ltype, unsigned int *pattern, int *unit, int *pitch);

/* 基本設定 の 色・画面 の、図面に属さない色の行（13 グレー・
   15 選択色・16 仮表示色）。行番号は原典の CGamenPage の受け手
   FUN_004c4af0 に渡るものと同じです。 */
unsigned int jw_row_rgb(int row);
int jw_row_rgb_set(int row, unsigned int rgb);

/* 基本設定 一般: 画像･ソリッドを最初に描画 (2405), 透過属性 (2860), 逆順描画 (2444) -- see src/draw.c */
extern int jw_draw_images_first;
extern int jw_draw_transparent;
extern int jw_draw_reverse;
extern int jw_draw_texts_last;   /* 1887 文字を最後に描画 (on by default) */
/* 画面倍率・文字表示 の【文字枠】を表示する (2104, DAT_00a0c794): 文字の
   字に加えて その枠も描く。画面だけで、印刷は描かない（app が描く間だけ立てる） */
extern int jw_draw_textframe;

#endif
