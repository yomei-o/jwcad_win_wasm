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

/* 斜体: a point h above the baseline moves h * JW_TEXT_ITALIC along the run.
 * FUN_00481d50 (decomp/decomp/all_00401000.c:66276-68211) only tells us
 * that it widens an italic text's box by 0.3256 of the height it rises
 * (nokori.md "書体"); it does not say GDI slants the glyphs by exactly that
 * much.  2026-10-19: measured directly, with real Windows GDI, what
 * CreateFontW(lfItalic=1) actually does to ＭＳ ゴシック and ＭＳ 明朝 --
 * the two faces of the original's own that carry no italic of their own,
 * the same two the exe sets with it (tools/gdifont.c, which calls GDI with
 * the exact CreateFontW argument list FUN_0048b130 uses, read at
 * decomp/decomp/all_004894cd.c:1116-1119, on an in-memory bitmap -- no
 * window, nothing captured from a screen).  Drawing "III" at nHeight
 * -30/-60/-100/-200/-400 and comparing the horizontal centre of the topmost
 * ink row against the bottommost gives a slope (dx of lean per dy of rise)
 * of 0.336-0.341 for ＭＳ ゴシック and 0.336-0.350 for ＭＳ 明朝 (closer to
 * 0.34 at the larger, less quantised sizes) -- consistently a little more
 * than 0.3256, not the same number.  0.34 is what real GDI does; kept here
 * in place of the box-widening guess.
 *
 * 太字: FUN_0048b130 passes lfWeight 700 on a face with no bold of its own
 * (same two faces).  Measured the same way (tools/gdifont.c), the extra
 * stroke width GDI's synthesised bold puts on a single stem ('I', also
 * checked against 'H') is not a fixed fraction of the cell height -- it is
 * almost always exactly +1 device pixel at every size from 12 to 64 device
 * px (the sizes this port mostly draws text at: tests/font_test.c's ch=8mm
 * at 0.25mm/px is 32px), and only grows past that at much larger sizes
 * (+3px by 100px, +4px by 200px, +6-7px by 400px, both faces, both
 * letters) -- nowhere close to the height/24 "smear across" a Wine-style
 * guess gives (height/24 would be +1.25px already at 30px, +16.7px by
 * 400px, 2-3x too much).  jw_text_bold_mm below is a least-squares line
 * through the 100/200/400px points (slope 0.018) floored at 1 device
 * pixel, which matches the small-size run flat and comes within a pixel or
 * two of the large-size one; GDI's own rounding/hinting is not a smooth
 * function of size, so no formula fits it exactly, but this is grounded in
 * what GDI does rather than borrowed from Wine's font engine.  Both fonts,
 * outline and bitmap, use them (src/outfont.c has the reading). */
#define JW_TEXT_ITALIC 0.34
#define JW_TEXT_BOLD_K 0.018
/* `ch` is the cell height in paper mm (its sign carried through unchanged,
   as src/text.c's caller relies on); `mmpp` the view's paper mm per device
   pixel.  Returns the 太字 smear distance in mm: ch's magnitude in device
   px times JW_TEXT_BOLD_K, floored at 1 device px, with ch's own sign. */
double jw_text_bold_mm(double ch, double mmpp);

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
/* For the tests: the font's own ascent/descent/units-per-em (stbtt_GetFontVMetrics,
   head.unitsPerEm). 0 if i is not ready. */
int jw_outfont_vmetrics(int i, int *asc, int *desc, int *upem);
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
   UDGothic.  Arial, Times New Roman, Century, Courier New, Calibri and a
   few more Latin faces are four fonts that are never listed (index
   JW_NOUTFONT .. JW_NOUTFONT + 3: fonts/jwsubsans.ttf, jwsubserif.ttf,
   jwsubmono.ttf, jwsubcalibri.ttf), sized the way Windows sizes the face,
   with IPAex for their Japanese letters; *prop then also says which face
   (bits 8 and up) and must be handed to jw_outfont_run as it is.  The
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
