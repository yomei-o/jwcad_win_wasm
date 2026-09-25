#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "pick.h"
#include "text.h"

#define TWO_PI 6.283185307179586
/* The arc's own "is this a whole circle" constant is a hair under 2 pi --
   6.283185207179586, a 2 where 2 pi has a 3.  It is written out here because
   that is what the binary holds, not because it is a better number. */
#define NEARLY_TWO_PI 6.283185207179586

static double ab(double v)
{
    /* The original writes `if (v <= 0.0) v = -v;`, which turns -0.0 into 0.0
       the same way fabs does. */
    return v <= 0.0 ? -v : v;
}

double jw_pick_tol(const jw_view *v)
{
    return (double)(int)(10.0 * 10.0) / 10.0 / v->scale;
}

typedef struct {
    double x0, x1, y0, y1;      /* view+0x8ee8, +0x8ef8, +0x8ef0, +0x8f00 */
    double tol;                 /* view+0x8ed0 */
    double d;                   /* view+0x8ee0, what the class leaves behind */
} box_t;

/* CDataSen, FUN_0042c100 */
static int dist_sen(box_t *b, const jw_obj *o, double px, double py)
{
    double ax = o->d[0], ay = o->d[1], bx = o->d[2], by = o->d[3];
    double dx, dy, adx, ady, e, lo, hi;

    /* The box test is the original's, endpoint by endpoint and loose: it
       only asks that one end is not past each side, so a long line whose
       ends straddle the box on both axes gets through. */
    if (!(b->x0 <= ax || b->x0 <= bx))
        return 0;
    if (!(ax <= b->x1 || bx <= b->x1))
        return 0;
    if (!(b->y0 <= ay || b->y0 <= by))
        return 0;
    if (!(ay <= b->y1 || by <= b->y1))
        return 0;

    dx = bx - ax;
    dy = by - ay;
    adx = ab(dx);
    ady = ab(dy);
    if (adx <= ady) {
        if (dy == 0.0)
            e = ab(px - ax) + ab(py - ay);      /* a line of no length */
        else
            e = px - ((py - ay) * dx / dy + ax);
    } else {
        e = py - ((px - ax) * dy / dx + ay);
    }
    e = ab(e);

    /* past an end, the overshoot is added on -- along whichever axis the
       line runs the further */
    if (adx <= ady) {
        lo = ay;
        hi = by;
        if (hi < lo) {
            hi = ay;
            lo = by;
        }
        if (py < lo)
            e += ab(py - lo);
        if (hi < py)
            e += ab(py - hi);
    } else {
        lo = ax;
        hi = bx;
        if (hi < lo) {
            hi = ax;
            lo = bx;
        }
        if (px < lo)
            e += ab(px - lo);
        if (hi < px)
            e += ab(px - hi);
    }
    if (e > b->tol)
        return 0;
    b->d = e;
    return 1;
}

/* CDataTen, FUN_0042d990 */
static int dist_ten(box_t *b, const jw_obj *o, double px, double py)
{
    double x = o->d[0], y = o->d[1], e;

    if (!(b->x0 <= x && x <= b->x1 && b->y0 <= y && y <= b->y1))
        return 0;
    e = ab(px - x) + ab(py - y);
    if (e > b->tol)
        return 0;
    /* what it reports is half what it measured, so a point beats a line
       through it even when both are the same distance away */
    b->d = e / 2.0;
    return 1;
}

/* CDataEnko, FUN_0042b7d0 */
static int dist_enko(box_t *b, const jw_obj *o, double px, double py)
{
    double cx = o->d[0], cy = o->d[1], r = o->d[2];
    double start = o->d[3], sweep = o->d[4], tilt = o->d[5], flat = o->d[6];
    double rr, ex, ey, e, dist, a;

    rr = r <= r * flat ? r * flat : r;
    if (cx + rr < b->x0 || (b->x1 <= cx - rr && cx - rr != b->x1)
        || cy + rr < b->y0 || (b->y1 <= cy - rr && cy - rr != b->y1))
        return 0;

    ex = px - cx;
    ey = py - cy;
    if (ab(ex) + ab(ey) < 1e-07)
        return 0;
    if (ab(tilt) > 1e-07) {
        double c = cos(tilt), s = sin(tilt), t = s * ey;
        ey = c * ey - s * ex;
        ex = c * ex + t;
    }
    if (ab(flat - 1.0) > 1e-07) {
        ey = ey / flat;
        if (ab(ex) < r && flat < 1.0) {
            double q = sqrt(r * r - ex * ex);
            if (ey < 0.0)
                q = -q;
            ey = (ey - q) * flat + q;
        }
    }
    e = ab(sqrt(ex * ex + ey * ey) - r);
    dist = e;

    if (ab(sweep) < NEARLY_TWO_PI) {
        double aa, to_end, to_start;
        if (sweep == 0.0)
            return 0;
        a = atan2(ey, ex) - start;
        /* FUN_0040b250: bring it round into the sweep's own direction */
        if (sweep > 0.0)
            while (a < 0.0)
                a += TWO_PI;
        if (sweep < 0.0)
            while (a > 0.0)
                a -= TWO_PI;
        while (a > TWO_PI)
            a -= TWO_PI;
        while (a < -TWO_PI)
            a += TWO_PI;
        aa = ab(a);
        if (ab(sweep) < aa) {
            /* outside the sweep: add the way round to the nearer end */
            to_start = ab(TWO_PI - aa);
            to_end = ab(ab(sweep) - aa);
            dist = r * (to_end <= to_start ? to_end : to_start) + e;
        }
    }
    if (dist > b->tol)
        return 0;
    b->d = dist;
    return 1;
}

/* CDataSolid, FUN_0042c630.
 *
 * The four corners are the eight doubles in the order the file holds them
 * (CDataSolid::Serialize writes +8, +0x10, +0x18, +0x20, +0x68, +0x70,
 * +0x78, +0x80, which is the order it read them in).  Near a corner the
 * answer is the Manhattan distance to it; otherwise each of the four sides
 * is measured the way a line is, but with no allowance for running past an
 * end -- a solid is only picked along its outline, not beyond it.
 *
 * The whole of this is behind `line type < 100`.  Loading normalises the
 * type to 1 for everything from 10 to 99 and for the "any colour" pen, so
 * what is left above 100 is the round solid, whose measure is somewhere
 * else and is not read out yet. */
static int dist_solid(box_t *b, const jw_obj *o, double px, double py)
{
    const double *c = o->d;
    int k;

    if (o->ltype >= 100 && o->color != 10)
        return 0;
    if (!(b->x0 <= c[0] || b->x0 <= c[2] || b->x0 <= c[4] || b->x0 <= c[6]))
        return 0;
    if (!(c[0] <= b->x1 || c[2] <= b->x1 || c[4] <= b->x1 || c[6] <= b->x1))
        return 0;
    if (!(b->y0 <= c[1] || b->y0 <= c[3] || b->y0 <= c[5] || b->y0 <= c[7]))
        return 0;
    if (!(c[1] <= b->y1 || c[3] <= b->y1 || c[5] <= b->y1 || c[7] <= b->y1))
        return 0;

    for (k = 0; k < 4; k++) {
        double m = ab(px - c[2 * k]) + ab(py - c[2 * k + 1]);
        if (m < b->tol) {
            b->d = m;
            return 1;
        }
    }
    for (k = 0; k < 4; k++) {
        double ax = c[2 * k], ay = c[2 * k + 1];
        double dx = c[(2 * k + 2) & 7] - ax, dy = c[(2 * k + 3) & 7] - ay;
        double e;
        if (ab(dx) <= ab(dy)) {
            if (dy == 0.0)
                e = ab(px - ax) + ab(py - ay);
            else
                e = px - ((py - ay) * dx / dy + ax);
        } else {
            e = py - ((px - ax) * dy / dx + ay);
        }
        e = ab(e);
        if (e < b->tol) {
            b->d = e;
            return 1;
        }
    }
    return 0;
}

/* CDataMoji, FUN_0048a1e0.
 *
 * It does not measure the text at all: it builds a CDataSen for each of the
 * four sides of the box the text sits in and asks that line how far away the
 * point is (FUN_0042c100, four times, returning on the first that answers).
 * The sides are walked the same way the 矩形 command lays its four out --
 * along the run, up, back, down.
 *
 * The original gets the box's width from the font (FUN_0048efe0 measures the
 * string); here it is the distance between the two ends the file stores,
 * which is what the run is drawn between, and the only width that can be
 * right when the glyphs are a different typeface. */
static int dist_moji(box_t *b, const jw_drawing *d, const jw_obj *o,
                     double px, double py)
{
    double x0 = o->d[0], y0 = o->d[1];
    double dx = o->d[2] - x0, dy = o->d[3] - y0;
    double len = sqrt(dx * dx + dy * dy), cw = o->d[4], ch = o->d[5];
    double ux, uy, vx, vy;
    jw_obj e;
    int k;

    if (ch <= 0.0)
        return 0;
    if (len < 1e-9) {
        /* the same fall-back the drawing uses: with both ends in one place
           the run is as wide as its characters make it */
        ux = 1.0;
        uy = 0.0;
        len = jw_text_count(jw_str(d, o->text)) * cw;
    } else {
        ux = dx / len;
        uy = dy / len;
    }
    vx = -uy;
    vy = ux;
    e = *o;
    e.cls = JW_SEN;
    for (k = 0; k < 4; k++) {
        /* corner k and corner k+1, round the box */
        static const int au[4] = {0, 1, 1, 0}, av[4] = {0, 0, 1, 1};
        int j = (k + 1) & 3;
        e.d[0] = x0 + au[k] * len * ux + av[k] * ch * vx;
        e.d[1] = y0 + au[k] * len * uy + av[k] * ch * vy;
        e.d[2] = x0 + au[j] * len * ux + av[j] * ch * vx;
        e.d[3] = y0 + au[j] * len * uy + av[j] * ch * vy;
        if (dist_sen(b, &e, px, py))
            return 1;
    }
    return 0;
}

/* Which layers can be picked from: only the ones that are editable.  That is
   the same state src/draw.c calls 3, the one the original draws normally. */
static int editable(const jw_drawing *d, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15;
    int gs = d->group[g].state, ls = d->group[g].layer[l].state;

    gs = gs == 0 ? 0 : gs == 1 ? 1 : 3;
    ls = ls == 0 ? 0 : ls == 1 ? 1 : 3;
    return (gs & ls) == 3 && !(o->flags & 1);
}

/* One candidate read point, kept if it is the nearest so far.
 *
 * The measure is in screen pixels, not millimetres of paper, and it is
 * rounded to whole ones.  What was measured off Jw_cad is a clean boundary
 * on whole pixels -- (7,3) and (10,0) away from a corner read, (6,5) and
 * (11,0) do not -- and carrying the ten pixels into paper millimetres puts
 * the (10,0) case four ulps the wrong side of the line.  So the ten is kept
 * where it was measured, and the distance is brought back to it. */
typedef struct {
    const jw_view *v;
    double x, y;
    int d, got;
    double px, py;
} read_t;

#define JW_READ_PX 10

static void offer(read_t *r, double x, double y)
{
    double s = r->v->scale;
    /* jw_px_round, not a bare cast: the drawing may put the point 1e12 away
       and the view may be scaled up, and the cast is undefined when the
       product will not fit.  See src/view.h. */
    int m = jw_px_round(ab(x - r->px) * s + 0.5)
          + jw_px_round(ab(y - r->py) * s + 0.5);

    if (m > JW_READ_PX || (r->got && m >= r->d))
        return;
    r->x = x;
    r->y = y;
    r->d = m;
    r->got = 1;
}

/* Where an arc starts and ends.  A whole circle has no ends -- Jw_cad does
   not read one, even at the angle its sweep starts from. */
static int arc_ends(const jw_obj *o, double *ex, double *ey)
{
    double cx = o->d[0], cy = o->d[1], r = o->d[2];
    double a0 = o->d[3], sweep = o->d[4], tilt = o->d[5], flat = o->d[6];
    double c = cos(tilt), s = sin(tilt);
    int k;

    if (sweep == 0.0 || ab(sweep) >= NEARLY_TWO_PI)
        return 0;
    if (flat <= 0.0)
        flat = 1.0;
    for (k = 0; k < 2; k++) {
        double t = a0 + (k ? sweep : 0.0);
        double u = r * cos(t), w = flat * r * sin(t);
        ex[k] = cx + u * c - w * s;
        ey[k] = cy + u * s + w * c;
    }
    return 2;
}

/* Is that angle inside the arc's sweep?  Measured the way FUN_0042b7d0
   measures it: the offset from the start, brought round the sweep's way. */
static int arc_has(const jw_obj *o, double t)
{
    double sweep = o->d[4], a = t - o->d[3];

    if (sweep == 0.0 || ab(sweep) >= NEARLY_TWO_PI)
        return 1;
    if (sweep > 0.0)
        while (a < 0.0)
            a += TWO_PI;
    if (sweep < 0.0)
        while (a > 0.0)
            a -= TWO_PI;
    while (a > TWO_PI)
        a -= TWO_PI;
    while (a < -TWO_PI)
        a += TWO_PI;
    return ab(a) <= ab(sweep);
}

/* Where a segment crosses an arc.  Both are brought into the arc's own frame
   -- turned back by its tilt and unsquashed by its flattening -- where it is
   a plain circle; the two roots then give the points on the segment. */
static int cross_arc(const jw_obj *l, const jw_obj *a, read_t *r)
{
    double cx = a->d[0], cy = a->d[1], rad = a->d[2];
    double tilt = a->d[5], flat = a->d[6] > 0.0 ? a->d[6] : 1.0;
    double c = cos(tilt), s = sin(tilt);
    double px[2], py[2], dx, dy, qa, qb, qc, disc, sq;
    int k, n = 0;

    for (k = 0; k < 2; k++) {
        double ex = l->d[k * 2] - cx, ey = l->d[k * 2 + 1] - cy;
        px[k] = c * ex + s * ey;
        py[k] = (c * ey - s * ex) / flat;
    }
    dx = px[1] - px[0];
    dy = py[1] - py[0];
    qa = dx * dx + dy * dy;
    if (qa < 1e-18)
        return 0;
    qb = 2.0 * (px[0] * dx + py[0] * dy);
    qc = px[0] * px[0] + py[0] * py[0] - rad * rad;
    disc = qb * qb - 4.0 * qa * qc;
    if (disc < 0.0)
        return 0;
    sq = sqrt(disc);
    for (k = 0; k < 2; k++) {
        double t = (-qb + (k ? sq : -sq)) / (2.0 * qa);
        double lx, ly;
        if (t < 0.0 || t > 1.0)
            continue;
        if (!arc_has(a, atan2(py[0] + t * dy, px[0] + t * dx)))
            continue;
        lx = l->d[0] + t * (l->d[2] - l->d[0]);
        ly = l->d[1] + t * (l->d[3] - l->d[1]);
        offer(r, lx, ly);
        n++;
        if (sq == 0.0)
            break;
    }
    return n;
}

/* Where two round arcs cross.  A squashed one is left alone: its crossings
   are not a circle problem any more, and nothing here needs them yet. */
static int cross_arcs(const jw_obj *a, const jw_obj *b, read_t *r)
{
    double dx, dy, dd, t, h, mx, my, ux, uy;
    int k, n = 0;

    if ((a->d[6] != 0.0 && a->d[6] != 1.0) || (b->d[6] != 0.0 && b->d[6] != 1.0))
        return 0;
    dx = b->d[0] - a->d[0];
    dy = b->d[1] - a->d[1];
    dd = sqrt(dx * dx + dy * dy);
    if (dd < 1e-09 || dd > a->d[2] + b->d[2]
        || dd < ab(a->d[2] - b->d[2]))
        return 0;
    t = (a->d[2] * a->d[2] - b->d[2] * b->d[2] + dd * dd) / (2.0 * dd);
    h = a->d[2] * a->d[2] - t * t;
    h = h <= 0.0 ? 0.0 : sqrt(h);
    ux = dx / dd;
    uy = dy / dd;
    mx = a->d[0] + t * ux;
    my = a->d[1] + t * uy;
    for (k = 0; k < 2; k++) {
        double px = mx + (k ? -h : h) * -uy;
        double py = my + (k ? -h : h) * ux;
        if (!arc_has(a, atan2(py - a->d[1], px - a->d[0]))
            || !arc_has(b, atan2(py - b->d[1], px - b->d[0])))
            continue;
        offer(r, px, py);
        n++;
        if (h == 0.0)
            break;
    }
    return n;
}

/* Where two segments cross, if they really do. */
static int cross(const jw_obj *a, const jw_obj *b, double *x, double *y)
{
    double ax = a->d[0], ay = a->d[1], adx = a->d[2] - ax, ady = a->d[3] - ay;
    double bx = b->d[0], by = b->d[1], bdx = b->d[2] - bx, bdy = b->d[3] - by;
    double den = adx * bdy - ady * bdx, s, t;

    if (den == 0.0)
        return 0;
    s = ((bx - ax) * bdy - (by - ay) * bdx) / den;
    t = ((bx - ax) * ady - (by - ay) * adx) / den;
    if (s < 0.0 || s > 1.0 || t < 0.0 || t > 1.0)
        return 0;
    *x = ax + s * adx;
    *y = ay + s * ady;
    return 1;
}

int jw_read(const jw_drawing *d, const jw_view *v, double x, double y,
            double *rx, double *ry)
{
    read_t r;
    int near[64], nnear = 0;
    int narc[32], nnarc = 0;
    int i, j;

    memset(&r, 0, sizeof r);
    r.v = v;
    r.px = x;
    r.py = y;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double ex[2], ey[2];
        if (!editable(d, o))
            continue;
        switch (o->cls) {
        case JW_SEN:
            offer(&r, o->d[0], o->d[1]);
            offer(&r, o->d[2], o->d[3]);
            break;
        case JW_TEN:
            offer(&r, o->d[0], o->d[1]);
            break;
        case JW_ENKO:
            if (arc_ends(o, ex, ey)) {
                offer(&r, ex[0], ey[0]);
                offer(&r, ex[1], ey[1]);
            }
            break;
        default:
            break;
        }
        /* keep the lines and arcs that run near the point, for the
           crossings */
        {
            box_t b;
            double t = jw_pick_tol(v);
            b.tol = t;
            b.x0 = x - t;
            b.x1 = x + t;
            b.y0 = y - t;
            b.y1 = y + t;
            b.d = 0;
            if (o->cls == JW_SEN
                && nnear < (int)(sizeof near / sizeof near[0])
                && dist_sen(&b, o, x, y))
                near[nnear++] = i;
            if (o->cls == JW_ENKO
                && nnarc < (int)(sizeof narc / sizeof narc[0])
                && dist_enko(&b, o, x, y))
                narc[nnarc++] = i;
        }
    }
    /* Where two of those cross. */
    for (i = 0; i < nnear; i++) {
        for (j = i + 1; j < nnear; j++) {
            double cx, cy;
            if (cross(&d->obj[near[i]], &d->obj[near[j]], &cx, &cy))
                offer(&r, cx, cy);
        }
        for (j = 0; j < nnarc; j++)
            cross_arc(&d->obj[near[i]], &d->obj[narc[j]], &r);
    }
    for (i = 0; i < nnarc; i++)
        for (j = i + 1; j < nnarc; j++)
            cross_arcs(&d->obj[narc[i]], &d->obj[narc[j]], &r);
    if (!r.got)
        return 0;
    *rx = r.x;
    *ry = r.y;
    return 1;
}

int jw_pick(const jw_drawing *d, const jw_view *v, double x, double y,
            int mode)
{
    return jw_pick_tie(d, v, x, y, mode, 0);
}

int jw_pick_tie(const jw_drawing *d, const jw_view *v, double x, double y,
                int mode, int last_wins)
{
    box_t b;
    double best = 1e99, best_ten = 1e99;
    int hit = -1, i;

    b.tol = jw_pick_tol(v);
    b.x0 = x - b.tol;
    b.x1 = x + b.tol;
    b.y0 = y - b.tol;
    b.y1 = y + b.tol;
    b.d = 1e99;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        int ok, taken = 0;
        double e;

        if (!editable(d, o))
            continue;
        switch (o->cls) {
        case JW_SEN:
            ok = dist_sen(&b, o, x, y);
            break;
        case JW_TEN:
            ok = dist_ten(&b, o, x, y);
            break;
        case JW_ENKO:
            ok = dist_enko(&b, o, x, y);
            break;
        case JW_SOLID:
            ok = dist_solid(&b, o, x, y);
            break;
        default:
            /* Text is not looked at in this pass, the way the original's
             * loop steps over CDataMoji; it gets a pass of its own below. */
            ok = 0;
            break;
        }
        if (!ok)
            continue;
        e = b.d;

        /* Modes 0 and 2 let a point win outright, on its own tally. */
        if ((mode == 0 || mode == 2) && o->cls == JW_TEN) {
            if (e < best_ten) {
                best_ten = e;
                best = e;
                hit = i;
            }
            taken = 1;
        }
        /* Mode 3 -- 図形消去's -- passes points over here entirely. */
        if (taken || (mode == 3 && o->cls == JW_TEN))
            continue;
        if (o->id != 0)
            e += 1e-06;         /* an element in a group comes second */
        if (last_wins ? e <= best + 1e-07 : e < best - 1e-07) {
            best = e;
            hit = i;
        }
    }

    /* Then text, but only when nothing else came near enough: the original
     * runs this second pass when *param_4 is still empty or the best it found
     * is no closer than the tolerance, and only for modes under 1.  It keeps
     * the nearest, with no nudges and a plain "closer than" test. */
    if (mode < 1 && (hit < 0 || b.tol <= best)) {
        double tbest = 1e99;
        int thit = -1;
        for (i = 0; i < d->ndrawn; i++) {
            const jw_obj *o = &d->obj[i];
            if (o->cls != JW_MOJI || !editable(d, o))
                continue;
            if (dist_moji(&b, d, o, x, y) && b.d < tbest) {
                tbest = b.d;
                thit = i;
            }
        }
        if (thit >= 0)
            hit = thit;
    }
    return hit;
}
