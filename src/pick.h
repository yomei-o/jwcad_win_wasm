/* Finding the element under the mouse -- FUN_0044a270 and each class's
 * vtable slot 0x44.
 *
 * The search is over a square box round the point, `jw_pick_tol` millimetres
 * of paper either way, and what each class hands back is not a Euclidean
 * distance but its own measure: a line gives the offset along whichever axis
 * it runs least, a point gives half its Manhattan distance, an arc gives how
 * far off the radius it is plus, once past an end, the arc length round to
 * that end.  Mixing those is what makes Jw_cad prefer a point to a line that
 * passes through it, so they are kept exactly as the original computes them.
 */
#ifndef JW_PICK_H
#define JW_PICK_H

#include "jww.h"
#include "view.h"

/* How far from an element still counts, in millimetres of paper.
 *
 *   view+0x8ed8   the radius in screen pixels, 10 by default (004f7f50) and
 *                 settable from 5 to 30 (the S_COMM line of the settings)
 *   view+0x8ed0   that turned into paper millimetres, which is what the
 *                 classes compare against:
 *                     trunc(px * 10) scaled for the display's dpi, / 10,
 *                     * screen millimetres per pixel / the zoom
 *
 * At 96 dpi the dpi step is the identity, so it comes to px / scale.
 */
double jw_pick_tol(const jw_view *v);

/* The mode is FUN_0044a270's first argument: 0 and 2 let a point win over
   anything else, 1 and 3 do not, and 3 (図形消去's) leaves points to be
   found only when nothing else is.  Returns an index into d->obj, or -1. */
int jw_pick(const jw_drawing *d, const jw_view *v, double x, double y,
            int mode);

/* The same, with the original's view+0x82bc: with it clear the first of two
   equally near elements wins, with it set the last one does.  コーナー処理
   flips it for its second pick, so picking twice in the same place gives the
   other line (CZukeiCorner's vtable slot 9). */
int jw_pick_tie(const jw_drawing *d, const jw_view *v, double x, double y,
                int mode, int last_wins);

/* The point the right button reads -- the "(R)Read" every prompt ends with.
 *
 * What counts as a read point was taken from Jw_cad by putting points with
 * the 点 command and reading the file back: the ends of a line, an existing
 * 点, and where two lines cross are all read; the middle of a line, the
 * centre of a circle and a whole circle's own start point are not.  Near
 * enough means a Manhattan distance of ten screen pixels -- (7,3) and (10,0)
 * away both read, (6,5) and (11,0) do not, which rules out a round tolerance.
 *
 * Returns 0 and leaves *rx, *ry alone when there is nothing to read, and the
 * click then does nothing at all, which is what the original does too.
 */
int jw_read(const jw_drawing *d, const jw_view *v, double x, double y,
            double *rx, double *ry);

#endif
