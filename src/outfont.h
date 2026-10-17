/* Outline (TrueType) fonts for text the drawing sets in a face of ours.
 *
 * Jw_cad draws a text with whatever Windows font the text names; the port
 * cannot ship those, so every text is drawn with the Shinonome bitmap font
 * (src/fontx.h) -- and that stays exactly so for the faces of the original
 * (ＭＳ ゴシック and the rest), which the pixel tests hold to the original.
 *
 * A text whose face is one of the names below is drawn from an outline font
 * instead, rasterised with src/stb_truetype.h:
 *
 *     IPAexGothic    IPAexゴシック          IPA Font License v1.0
 *     IPAexMincho    IPAex明朝              IPA Font License v1.0
 *     BIZ UDGothic   BIZ UDゴシック         SIL OFL 1.1
 *
 * The files (the .ttf files in fonts/, subset to what CP932 holds; font/PROVENANCE.md)
 * are not in the program.  A native build reads them from a fonts/ or
 * font/ directory beside the exe (or JW_FONTS); the browser asks the page
 * for them (jw_font_pending / jw_font_put in src/main_wasm.c), and until one
 * has arrived -- or if it never does -- the bitmap font draws the text.
 */
#ifndef JW_OUTFONT_H
#define JW_OUTFONT_H

#include "fb.h"
#include "view.h"

#define JW_NOUTFONT 3

/* 斜体: a point h above the baseline moves h * JW_TEXT_ITALIC along the run
   (the 0.3256 FUN_00481d50 widens an italic text's box by).  太字: the
   letters are thickened across by the height * JW_TEXT_BOLD.  Both fonts,
   outline and bitmap, use them (src/outfont.c has the reading). */
#define JW_TEXT_ITALIC 0.3256
#define JW_TEXT_BOLD (1.0 / 24.0)

int jw_outfont_count(void);
/* the face name as a drawing stores it (CP932, in fact ASCII) */
const char *jw_outfont_name(int i);
/* the file the browser fetches / the native build reads */
const char *jw_outfont_file(int i);

/* Which of ours a stored face name is, or -1 (also for "" and the
   original's own faces).  Case does not matter; the Japanese spellings
   IPAexゴシック, IPAex明朝 and BIZ UDゴシック are taken too. */
int jw_outfont_find(const char *face);

/* Whether font i can draw now.  The first call asks for it: a native build
   reads the file at once, the browser build marks it wanted. */
int jw_outfont_ready(int i);

/* Where the native build looks first, besides ./fonts, ./font, ../fonts. */
void jw_outfont_dir(const char *dir);

/* The browser's side.  pending() answers the index of a font that has been
   asked for and not yet handed over, once, or -1; put() takes the file
   (copied), fail() gives up on that font.  put() answers 1 if it parses. */
int jw_outfont_pending(void);
int jw_outfont_put(int i, const unsigned char *data, long len);
void jw_outfont_fail(int i);
/* bumps whenever a font arrives, so the page knows to repaint */
int jw_outfont_gen(void);

/* One run, the way jw_text_run lays it out (src/text.c) but with the
   advances of the characters themselves -- a half-width one takes half the
   cell -- and the gap the file's two ends leave.  `style` is the text's
   10000s digit: 1 italic, 2 bold.  Returns 0 if font i cannot draw. */
int jw_outfont_run(fb_t *fb, const jw_view *v, int i, const char *s,
                   double x0, double y0, double x1, double y1,
                   double cw, double ch, unsigned int col, int tate,
                   int style, int prop);

/* Outline fonts for the original's own faces too.  Off, only the three names
   above use them and every other text is the bitmap font -- which is what
   the pixel tests against the original want, so that is the library's
   default; the browser and native front ends (main_wasm.c, main_win32.c)
   switch it on.  On, ＭＳ ゴシック, ＭＳ Ｐゴシック, a text with no face and
   anything unknown is IPAexGothic, and 明朝 faces are IPAexMincho; a Ｐ face
   sets each letter at its own advance (*prop bit 0).  BIZ UD… faces are BIZ
   UDGothic.  Arial, Times New Roman, Century and a few more Latin faces are
   two fonts that are never listed (index JW_NOUTFONT, JW_NOUTFONT + 1:
   fonts/jwsubsans.ttf, jwsubserif.ttf), sized the way Windows sizes the
   face, with IPAex for their Japanese letters; *prop then also says which
   face (bits 8 and up) and must be handed to jw_outfont_run as it is.  The
   bitmap font still draws while a file is loading or if it cannot be had. */
void jw_outfont_enable(int on);
int jw_outfont_enabled(void);
/* the outline font a stored face is drawn with, or -1 for the bitmap one */
int jw_outfont_resolve(const char *face, int *prop);

/* 字の長さ、間隔 0.01 のときの FUN_00493410 の枝 (src/outfont.c の読みの
   コメント参照; 逆コンパイルの読み、原典では押していない).  `cw` を幅
   (mm) として、`s` を `face` の字形の実際の advance で測った長さを
   *out に書いて 1 を返す; フォントが未読込みなら 0 (呼び手は従来の
   固定幅の式へ戻ること)。GDI は呼ばない。 */
int jw_outfont_text_width(const char *face, const char *s, double cw, double *out);

#endif
