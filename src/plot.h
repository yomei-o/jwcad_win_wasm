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

#endif
