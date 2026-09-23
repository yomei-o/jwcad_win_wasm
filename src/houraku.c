/* 包絡処理 (0x804e) -- welding what a box catches into one outline.
 *
 * This follows the original's own worker (FUN_0067f210, 19,431 bytes), which
 * RESUME.md walks through.  The short of it:
 *
 *   1. take the lines the box catches, of the line types the bar's four
 *      checkboxes name, and deal with them one (line type, colour, layer,
 *      layer group) at a time -- lines of different pens are never welded
 *      together;
 *   2. join the ones that lie on the same straight line into one, even when
 *      there is a gap between them;
 *   3. mark each one by where its ends fall: both in the box, one in, or
 *      neither;
 *   4. **pass A** -- the ones with an end in the box are drawn out (or cut
 *      back) to the furthest crossings with the other lines' *straight
 *      lines*, as far as the box reaches.  This is what makes a wall's end
 *      cap run out to meet another's;
 *   5. then each is cut at the crossings where another line properly passes
 *      from one side to the other -- a line that only touches does not
 *      count -- and the middle is dropped.  For one wholly inside the box,
 *      a piece whose end carries such a crossing goes too, which is how a
 *      wall that is crossed at both ends disappears.
 *
 * Only straight lines are done here; the original also welds arcs.
 */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

#define EPS 1e-7

typedef struct {
    double ax, ay, bx, by;      /* the two ends, as they stand */
    int at;                     /* the element it came from */
    int where;                  /* 0 both ends in, 1 one end in, 2 neither */
    int gone;                   /* joined into another one */
} hl;

typedef struct {
    double x0, y0, x1, y1;
} hbox;

/* the length of a line, and its unit direction */
static double dirof(const hl *l, double *ux, double *uy)
{
    double dx = l->bx - l->ax, dy = l->by - l->ay;
    double n = sqrt(dx * dx + dy * dy);

    if (n < 1e-12) {
        *ux = 1.0;
        *uy = 0.0;
        return 0.0;
    }
    *ux = dx / n;
    *uy = dy / n;
    return n;
}

/* how far along l a point is, and how far off it */
static double along(const hl *l, double x, double y)
{
    double ux, uy;

    dirof(l, &ux, &uy);
    return (x - l->ax) * ux + (y - l->ay) * uy;
}

static double offof(const hl *l, double x, double y)
{
    double ux, uy;

    dirof(l, &ux, &uy);
    return (x - l->ax) * uy - (y - l->ay) * ux;
}

/* Where two straight lines cross, whether or not it is on either piece.
   0 when they are parallel.  (The original's FUN_006850f0.) */
static int cross(const hl *a, const hl *b, double *px, double *py)
{
    double d0 = (b->ay - a->ay) * (a->bx - a->ax)
                - (b->ax - a->ax) * (a->by - a->ay);
    double d1 = (b->by - a->ay) * (a->bx - a->ax)
                - (b->bx - a->ax) * (a->by - a->ay);
    double t;

    if (d0 == d1)
        return 0;               /* parallel, or both on the line */
    t = d0 / (d0 - d1);
    *px = (b->bx - b->ax) * t + b->ax;
    *py = (b->by - b->ay) * t + b->ay;
    if (b->ax == b->bx)
        *px = b->ax;
    if (b->ay == b->by)
        *py = b->ay;
    return 1;
}

/* Does b properly pass from one side of a's straight line to the other?
   Touching it with an end does not count -- that is what tells a wall that
   is crossed from one that merely meets another. */
static int straddles(const hl *a, const hl *b)
{
    double d0 = offof(a, b->ax, b->ay), d1 = offof(a, b->bx, b->by);

    return (d0 <= -EPS || d1 <= -EPS) && (EPS <= d0 || EPS <= d1);
}

static int inbox(const hbox *w, double x, double y)
{
    return w->x0 < x && x < w->x1 && w->y0 < y && y < w->y1;
}

/* How far along l the box reaches, following l's straight line: the
   original clips against the four edges and keeps the outermost two. */
static void box_range(const hl *l, const hbox *w, double *lo, double *hi)
{
    double cx[5], cy[5];
    int i;

    cx[0] = cx[3] = cx[4] = w->x0;
    cx[1] = cx[2] = w->x1;
    cy[0] = cy[1] = w->y0;
    cy[2] = cy[3] = w->y1;
    cy[4] = w->y0;
    *lo = 2e22;
    *hi = -2e22;
    for (i = 0; i < 4; i++) {
        hl e;
        double d0, d1, px, py, t;

        e.ax = cx[i];
        e.ay = cy[i];
        e.bx = cx[i + 1];
        e.by = cy[i + 1];
        d0 = offof(l, e.ax, e.ay);
        d1 = offof(l, e.bx, e.by);
        if (d0 * d1 > 0.0)
            continue;           /* the edge stays on one side */
        if (!cross(l, &e, &px, &py))
            continue;
        t = along(l, px, py);
        if (t > *hi)
            *hi = t;
        if (t < *lo)
            *lo = t;
    }
}

static void point_at(const hl *l, double t, double *x, double *y)
{
    double ux, uy;

    dirof(l, &ux, &uy);
    *x = l->ax + ux * t;
    *y = l->ay + uy * t;
}

/* Two lines are the same straight line when both of one's ends sit on the
   other.  The original joins them whether or not they overlap. */
static int same_line(const hl *a, const hl *b)
{
    return fabs(offof(a, b->ax, b->ay)) < EPS
           && fabs(offof(a, b->bx, b->by)) < EPS;
}

/* Which side of the edge p0->p1 a point falls on: the original's own test,
   and its "outside" is where this comes out negative. */
static double side(double ex0, double ey0, double ex1, double ey1,
                   double px, double py)
{
    return (py - ey0) * (ex1 - ex0) - (px - ex0) * (ey1 - ey0);
}

/* ------------------------------------------------------------------ */

static void emit(jw_hou_out **out, int *n, int *cap, int at,
                 double x0, double y0, double x1, double y1, int drop)
{
    jw_hou_out *p;

    if (*n == *cap) {
        int c = *cap ? *cap * 2 : 32;

        p = (jw_hou_out *)realloc(*out, (size_t)c * sizeof *p);
        if (!p)
            return;
        *out = p;
        *cap = c;
    }
    p = &(*out)[(*n)++];
    p->at = at;
    p->x0 = x0;
    p->y0 = y0;
    p->x1 = x1;
    p->y1 = y1;
    p->drop = drop;
}

/* One batch of the same pen and layer. */
static void weld(hl *l, int n, const hbox *w,
                 jw_hou_out **out, int *no, int *cap)
{
    int i, j;

    /* ---- the ones on the same straight line become one -------------- */
    for (i = 0; i < n; i++) {
        if (l[i].gone)
            continue;
        for (j = i + 1; j < n; j++) {
            double t0, t1, lo, hi, len, ux, uy;

            if (l[j].gone || !same_line(&l[i], &l[j]))
                continue;
            len = dirof(&l[i], &ux, &uy);
            t0 = along(&l[i], l[j].ax, l[j].ay);
            t1 = along(&l[i], l[j].bx, l[j].by);
            lo = t0 < t1 ? t0 : t1;
            hi = t0 < t1 ? t1 : t0;
            if (lo < 0.0)
                point_at(&l[i], lo, &l[i].ax, &l[i].ay);
            if (hi > len)
                point_at(&l[i], hi, &l[i].bx, &l[i].by);
            l[j].gone = 1;
            emit(out, no, cap, l[j].at, 0, 0, 0, 0, 1);
        }
    }

    /* ---- where each one's ends fall --------------------------------- */
    for (i = 0; i < n; i++) {
        int in0, in1;

        if (l[i].gone)
            continue;
        in0 = inbox(w, l[i].ax, l[i].ay);
        in1 = inbox(w, l[i].bx, l[i].by);
        if (in0 && in1) {
            l[i].where = 0;
        } else if (in0 || in1) {
            l[i].where = 1;
            if (in0) {          /* the end that is in the box goes second */
                double x = l[i].ax, y = l[i].ay;

                l[i].ax = l[i].bx;
                l[i].ay = l[i].by;
                l[i].bx = x;
                l[i].by = y;
            }
        } else {
            l[i].where = 2;
        }
    }

    /* ---- pass A: out to the furthest crossings the box reaches ------ */
    for (i = 0; i < n; i++) {
        double lo, hi, tmin = 2e22, tmax = -2e22;

        if (l[i].gone || l[i].where == 2)
            continue;
        box_range(&l[i], w, &lo, &hi);
        for (j = 0; j < n; j++) {
            double px, py, t;

            if (j == i || l[j].gone)
                continue;
            if (!cross(&l[i], &l[j], &px, &py))
                continue;
            t = along(&l[i], px, py);
            if (tmax < t && t < hi)
                tmax = t;
            if (l[i].where == 0 && t < tmin && lo < t)
                tmin = t;
        }
        if (l[i].where == 0) {
            if (tmin < tmax - EPS) {
                double x0, y0, x1, y1;

                point_at(&l[i], tmin, &x0, &y0);
                point_at(&l[i], tmax, &x1, &y1);
                l[i].ax = x0;
                l[i].ay = y0;
                l[i].bx = x1;
                l[i].by = y1;
            }
        } else if (EPS < tmax) {
            point_at(&l[i], tmax, &l[i].bx, &l[i].by);
        }
    }

    /* ---- and then each is cut where another properly crosses -------- */
    for (i = 0; i < n; i++) {
        double ux, uy, len, tmin, tmax;
        int keep0 = 1, keep1 = 1, cut;

        if (l[i].gone)
            continue;
        len = dirof(&l[i], &ux, &uy);
        tmin = len;
        tmax = 0.0;
        for (j = 0; j < n; j++) {
            double px, py, t;

            if (j == i || l[j].gone)
                continue;
            if (!straddles(&l[i], &l[j]))
                continue;
            if (!cross(&l[i], &l[j], &px, &py))
                continue;
            t = along(&l[i], px, py);
            if (l[i].where == 2) {
                if (t < -EPS || t > len + EPS)
                    continue;
                if (t < tmin)
                    tmin = t;
                if (tmax < t)
                    tmax = t;
                continue;
            }
            if (l[i].where == 0) {
                if (fabs(t) <= EPS)
                    keep0 = 0;
                if (fabs(t - len) <= EPS)
                    keep1 = 0;
            } else if (fabs(t - len) <= EPS) {
                keep1 = 0;
            }
            if (t < tmin && EPS < t)
                tmin = t;
            if (tmax < t && t < len - EPS)
                tmax = t;
        }
        cut = l[i].where == 2 ? tmin <= tmax - EPS
            : l[i].where == 1 ? tmin < len - EPS
            : tmin <= tmax + EPS;
        if (!cut) {
            emit(out, no, cap, l[i].at, l[i].ax, l[i].ay, l[i].bx, l[i].by, 0);
            continue;
        }
        {
            double x0, y0, x1, y1;
            int any = 0;

            point_at(&l[i], tmin, &x0, &y0);
            point_at(&l[i], tmax, &x1, &y1);
            if ((l[i].where != 0 || keep0) && tmin > EPS) {
                emit(out, no, cap, l[i].at, l[i].ax, l[i].ay, x0, y0, 0);
                any = 1;
            }
            if ((l[i].where == 2 || keep1) && tmax < len - EPS) {
                emit(out, no, cap, l[i].at, x1, y1, l[i].bx, l[i].by, 0);
                any = 1;
            }
            if (!any)
                emit(out, no, cap, l[i].at, 0, 0, 0, 0, 1);
        }
    }
}

/* 範囲内消去 -- the right button on the second corner.  Every line the box
 * catches loses the part inside it and keeps what sticks out, which is the
 * arm of the original that runs when its 0x420 is 1: each line is clipped
 * against the four edges, and the two ends that were cut off are what comes
 * back.  A line wholly inside the box keeps nothing.
 */
static void erase_in(const hl *l, int n, const hbox *w,
                     jw_hou_out **out, int *no, int *cap)
{
    double cx[5], cy[5];
    int i, k;

    cx[0] = cx[3] = cx[4] = w->x0;
    cx[1] = cx[2] = w->x1;
    cy[0] = cy[1] = w->y0;
    cy[2] = cy[3] = w->y1;
    cy[4] = w->y0;
    for (i = 0; i < n; i++) {
        double ax = l[i].ax, ay = l[i].ay, bx = l[i].bx, by = l[i].by;
        int cut0 = 0, cut1 = 0;

        for (k = 0; k < 4; k++) {
            hl e, m;
            double px, py, t, len, ux, uy;

            e.ax = cx[k];
            e.ay = cy[k];
            e.bx = cx[k + 1];
            e.by = cy[k + 1];
            m.ax = l[i].ax;
            m.ay = l[i].ay;
            m.bx = l[i].bx;
            m.by = l[i].by;
            if (!straddles(&m, &e))
                continue;       /* the edge stays on one side of the line */
            if (!cross(&m, &e, &px, &py))
                continue;
            /* and the crossing has to be on the line itself, not out on
               its continuation -- the original leaves that to the rect
               test it does when it gathers the lines */
            len = dirof(&m, &ux, &uy);
            t = along(&m, px, py);
            if (t < -EPS || t > len + EPS)
                continue;
            if (side(e.ax, e.ay, e.bx, e.by, bx, by) < 0.0) {
                bx = px;
                by = py;
                cut1 = 1;
            }
            if (side(e.ax, e.ay, e.bx, e.by, ax, ay) < 0.0) {
                ax = px;
                ay = py;
                cut0 = 1;
            }
        }
        if (!cut0 && !cut1) {
            /* it never met an edge: either it is all in the box, and goes,
               or it is nowhere near it and is left alone */
            if (inbox(w, (l[i].ax + l[i].bx) / 2, (l[i].ay + l[i].by) / 2))
                emit(out, no, cap, l[i].at, 0, 0, 0, 0, 1);
            else
                emit(out, no, cap, l[i].at, l[i].ax, l[i].ay,
                     l[i].bx, l[i].by, 0);
            continue;
        }
        if (cut1)
            emit(out, no, cap, l[i].at, bx, by, l[i].bx, l[i].by, 0);
        if (cut0)
            emit(out, no, cap, l[i].at, l[i].ax, l[i].ay, ax, ay, 0);
    }
}

int jw_houraku(const jw_drawing *d, double x0, double y0, double x1,
               double y1, const int *ltypes, int nltype, int erase,
               jw_hou_out **outp)
{
    hbox w;
    hl *l;
    int *used;
    int i, k, n = 0, no = 0, cap = 0;
    jw_hou_out *out = 0;

    *outp = 0;
    if (!d || d->ndrawn <= 0)
        return 0;
    w.x0 = x0 < x1 ? x0 : x1;
    w.x1 = x0 < x1 ? x1 : x0;
    w.y0 = y0 < y1 ? y0 : y1;
    w.y1 = y0 < y1 ? y1 : y0;
    if (w.x1 - w.x0 < 1e-9 || w.y1 - w.y0 < 1e-9)
        return 0;

    l = (hl *)calloc((size_t)d->ndrawn, sizeof *l);
    used = (int *)calloc((size_t)d->ndrawn, sizeof *used);
    if (!l || !used) {
        free(l);
        free(used);
        return 0;
    }
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double a, b, c, e;

        if (o->cls != JW_SEN)
            continue;
        /* Only what is on the **write layer** takes part.  The original's
           gather says so plainly (FUN_0042dd10 lets an element through only
           when its layer's state is 3), and it is why a box over a real
           drawing's walls does nothing: they are on layers that are merely
           editable. */
        {
            int g = o->lgroup & 15, la = o->layer & 15;

            if (d->group[g].state != 3 || d->group[g].layer[la].state != 3)
                continue;
        }
        for (k = 0; k < nltype; k++)
            if (ltypes[k] == (int)o->ltype)
                break;
        if (k == nltype)
            continue;
        jw_obj_box(o, &a, &b, &c, &e);
        if (c < w.x0 || a > w.x1 || e < w.y0 || b > w.y1)
            continue;           /* nowhere near the box */
        l[n].ax = o->d[0];
        l[n].ay = o->d[1];
        l[n].bx = o->d[2];
        l[n].by = o->d[3];
        l[n].at = i;
        n++;
    }
    if (erase) {                /* 範囲内消去 takes them all at once */
        erase_in(l, n, &w, &out, &no, &cap);
        free(l);
        free(used);
        *outp = out;
        return no;
    }
    /* one batch of the same pen and layer at a time */
    {
        hl *batch = (hl *)calloc((size_t)n + 1, sizeof *batch);

        for (i = 0; batch && i < n; i++) {
            int nb = 0, j;
            const jw_obj *a;

            if (used[i])
                continue;
            a = &d->obj[l[i].at];
            for (j = i; j < n; j++) {
                const jw_obj *b = &d->obj[l[j].at];

                if (used[j] || b->ltype != a->ltype || b->color != a->color
                    || b->layer != a->layer || b->lgroup != a->lgroup)
                    continue;
                batch[nb++] = l[j];
                used[j] = 1;
            }
            weld(batch, nb, &w, &out, &no, &cap);
        }
        free(batch);
    }
    free(l);
    free(used);
    *outp = out;
    return no;
}
