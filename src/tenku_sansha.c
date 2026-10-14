/* tenku_sansha.c -- see tenku_sansha.h.
 *
 * Source: Jw_win.exe 10.03.6, FUN_00740440 (the 三斜 branch, `iStack_20138 == 0`)
 * and its callees; the tags [D addr] name the address the rule was read at.
 *
 * WHAT THE ORIGINAL DOES (all of it is reproduced here, except where marked [G]):
 *
 *  1. Collect (FUN_0073b870/0073c0c0/0073d240/0073cde0).  Every line (ltype != 9)
 *     whose ends carry height texts (flag 0x80, within 0.001 manhattan, same layer
 *     and group) becomes 3-D lines, per drawing line, in drawing order:
 *       - a ground edge (z = bottom at both ends) when both ends have two values,
 *       - the top edge,
 *       - a vertical (top -> bottom, zero length in plan) at end 0 and at end 1,
 *         each only if that end's text has not been used before (the text carries
 *         a "used" mark: 2nd and later lines get the count negated, no vertical).
 *     A single positive height h is turned into two values (top = h + level - plane,
 *     bottom = min(-plane,0)); "t,b" gives both; a single negative one is |h|.
 *     Lines that cross z = 0 are split there (FUN_0073cde0).
 *  2. FUN_00740440 stage B: a line is flagged "ground" (cmd 0x44 = 1) if both ends
 *     are lower than 1e-7 or its plan is radial (|cross| < 1e-7); a line whose
 *     middle coincides with the viewpoint is dropped; the ends are swapped so that
 *     the azimuth grows (the swap is in place); then an exchange sort by the
 *     area of the 3-D triangle (viewpoint, end0, end1), largest first (ground /
 *     dropped lines key 0); then lines lying in one plane with the viewpoint are
 *     merged (0x741553..0x741c70; decoded, but no sample has one  [G]).
 *  3. Stage C: each line becomes pieces (2-D segments, relative to the circle
 *     centre, id = line number, ground flag, the line's colour/ltype): the
 *     projected polyline over the grid of multiples of 2 deg of the azimuth
 *     (az0 < a < az1, absolute multiples), a radial line gets one piece.
 *  4. Sweep over 360000 rays of 0.001 deg starting at the first ray that hits no
 *     piece: per ray the nearest non-ground piece (ground pieces count as R);
 *     a run opens when the nearest piece is nearer than the farthest hit (some
 *     sky behind), changes id or closes; the end of a run is refined by 8 bisection
 *     steps between the last piece and the new one.
 *  5. Each run is cut into n = int(span/maxdiv)+1 equal angles; per angle the
 *     nearest point of the run's pieces; per interval the chord is moved out
 *     parallel until it touches the skyline (the point of the chord, sampled
 *     every 0.1/maxdiv, farthest from the chord), +0.001, and the two rays are cut
 *     with it: that is the triangle O,F,N of the table (底辺 = |OF| of the farther,
 *     高さ = distance of the nearer N from line OF).
 *  6. The table (rows of 50, header, frame lines), the summary lines and the
 *     skyline pieces (non-ground ones, last) are written.
 *
 * cmd+0xf0 (dialog 0xfe4) is a mode switch that also picks the strings: 0 = 基準建物用
 * (tangent triangles, [n], 切り上げ), 1 = 計画建物用 (plain chords, <n>, 切り捨て); the two
 * diagrams of orig/天空率表.jww are one of each, which is why they differ in the details.
 *
 * Verified against orig/天空率表.jww (two diagrams, object for object, to 1e-13 mm, strings,
 * colours, line types, flags): see tests/tenku_sansha_test.c.  Not covered by a sample:
 * the exe's own number format (see HK_SANSHA_EXE), the 2nd table page, rings, 等距離射影,
 * 南方向補正, 測定面高さ <> 0 and the plane merge.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tenku_sansha.h"

#define PI 3.14159265358979323846

/* CP932, octal escapes (never run into a following digit) */
#define S_SANSHA   "\216O\216\316\214v\216Z"
#define S_MAXDIV   "\215\305\221\345\225\252\212\204\212p"
#define S_RTXT     "\223V\213\363\220}\224\274\214a(R) = "
#define S_ZUSUN    "(\220}\220\241mm)"
#define S_COL_NO   "\216O\212p\214` No.^3"
#define S_COL_BASE "\222\352\225\323(mm)"
#define S_COL_H    "\215\202\202\263(mm)"
#define S_COL_AREA "\226\312\220\317(mm^u2)"
#define S_SUM      "\216O\216\316\226\312\220\317\215\207\214v"
#define S_SECTOR   "\220\356\214`\226\312\220\317"
#define S_LP       "\201i"
#define S_ANGLE    "\220\356\214`\222\206\220S\212p"
#define S_DEGH     "\337"
#define S_RP       "\201j"
#define S_HCIRC    "\220\205\225\275\211~\216\313\211e\226\312\220\317"
#define S_CIRCAREA "\223V\213\363\220}\211~\226\312\220\317"
#define S_SKYRATE  "\223V\213\363\227\246"
#define S_ROUNDUP  "\220\330\202\350\217\343\202\260"
#define S_ARROWUP  "\201\252"
#define S_ROUNDDN  "\220\330\202\350\216\314\202\304"
#define S_ARROWDN  "\201\253"
#define S_SOKUTENN "\221\252\222\350\223_"
#define S_SHASHAEI "\220\263\216\313\211e"
#define S_SOKUTEIMEN "\221\252\222\350\226\312\215\202\202\263"
#define S_MEMORI   "\226\332\220\267\212\324\212u "
#define S_DEG      "\201\213"
#define S_ZENSP    " \201@"
#define S_LABEL_PLAN "\201s\214v\211\346\214\232\225\250\227p\201t"
#define S_LABEL_BASE "\201y\212\356\217\200\214\232\225\250\227p\201z"
#define S_FACE     "\202l\202r \203S\203V\203b\203N"

#define MAXRUN 3601           /* auStack_18ff4[]: 0xe11 entries */
#define MAXTRI 3600

/* ------------------------------------------------------------------ */
/* small geometry: the frame class (FUN_005f97f0..) and the line/line  */
/* intersection FUN_004619b0                                           */
/* ------------------------------------------------------------------ */
typedef struct { double ox, oy, c, s, len; int valid; } frame;

static void frame_set(frame *f, double ox, double oy, double tx, double ty)
{
    double dx = tx - ox, dy = ty - oy;

    f->ox = ox;
    f->oy = oy;
    if (fabs(dx) + fabs(dy) >= 1e-07) {
        f->len = sqrt(dx * dx + dy * dy);
        f->c = dx / f->len;
        f->s = dy / f->len;
        f->valid = 1;
    } else {
        f->c = 1.0;
        f->s = 0.0;
        f->len = 1.0;
        f->valid = 0;
    }
}
static double f_along(const frame *f, double x, double y)   /* FUN_005f8b60(1,..) */
{
    return (x - f->ox) * f->c + (y - f->oy) * f->s;
}
static double f_perp(const frame *f, double x, double y)    /* FUN_005f8c20(1,..) */
{
    return (y - f->oy) * f->c - (x - f->ox) * f->s;
}
static void f_global(const frame *f, double u, double v, double *x, double *y)
{
    *x = f->c * u - f->s * v + f->ox;                        /* FUN_005f8b60(0), 5f8ce0 */
    *y = f->c * v + f->s * u + f->oy;
}

/* FUN_004619b0: A = line 1 (x0,y0,x1,y1), B = line 2; infinite lines.  The output
 * is preset to 9.99e12 like the original. */
static int isect(double a0x, double a0y, double a1x, double a1y,
                 double b0x, double b0y, double b1x, double b1y, double *ox, double *oy)
{
    double dx1 = a1x - a0x, dy1 = a1y - a0y, dx2 = b1x - b0x, dy2 = b1y - b0y;
    double c1 = (b0y - a0y) * dx1 - (b0x - a0x) * dy1;
    double c2 = (b1y - a0y) * dx1 - (b1x - a0x) * dy1;
    double t;

    *ox = 9990000000000.0;
    *oy = 9990000000000.0;
    if (!(fabs(c1 - c2) > 1e-07))
        return 0;
    if (!(fabs(c1) <= fabs(c1 - c2) * 10000000000.0))
        return 0;
    t = c1 / (c1 - c2);
    *ox = dx2 * t + b0x;
    *oy = dy2 * t + b0y;
    if (!(fabs(*ox) + fabs(*oy) <= 139778713.93879598))
        return 0;
    if (a0x == a1x) *ox = a0x;
    if (a0y == a1y) *oy = a0y;
    if (b0x == b1x) *ox = b0x;
    if (b0y == b1y) *oy = b0y;
    return 1;
}

/* ------------------------------------------------------------------ */
/* output objects                                                      */
/* ------------------------------------------------------------------ */
typedef struct {
    int cls, color, ltype, flags, n, width;
    double d[8];
    char text[320];
    int has_text;
} oo;

typedef struct { oo *a; int n, cap; } obuf;

static oo *ob_new(obuf *b, int cls)
{
    oo *o;

    if (b->n >= b->cap) {
        int nc = b->cap ? b->cap * 2 : 1024;
        oo *na = (oo *)realloc(b->a, (size_t)nc * sizeof(oo));

        if (!na)
            return 0;
        b->a = na;
        b->cap = nc;
    }
    o = &b->a[b->n++];
    memset(o, 0, sizeof *o);
    o->cls = cls;
    return o;
}

typedef struct {
    obuf b;
    const hk_sansha_opts *o;
    double cx, cy;          /* circle centre (cmd+0xd0/0xd8) */
    double px, py;          /* measuring point */
    double R;
    double tw, th, tsp;
    int sz;
    int tcol;               /* text colour override (0 = the option's) */
} octx;

/* text width in half-width units, "^d" removes d+2, "^u"/"^l" removes 2  [G for other codes] */
static double text_width(const octx *c, const char *s)
{
    int n = 0;
    const unsigned char *p = (const unsigned char *)s;
    double w;

    while (*p) {
        if (*p == '^' && p[1]) {
            if (p[1] >= '0' && p[1] <= '9') {
                n -= p[1] - '0';
                p += 2;
                continue;
            }
            if (p[1] == 'u' || p[1] == 'l') {
                p += 2;
                continue;
            }
        }
        n++;
        p++;
    }
    if (n < 1)
        return 0.0;
    if (n == 1)
        return c->tw / 2.0;
    w = (c->tw + c->tsp) * 0.5 * (double)n - c->tsp * 0.5;
    return w;
}

/* FUN_00479550: text on the baseline (x0,y0)->(x1,y1).  align: 2 left at the start,
 * 0 centred on the middle, 1 left at the end, -1 right-justified at the start,
 * -2 right-justified at the end.  Coordinates are absolute. */
static int ob_text(octx *c, const char *s, double x0, double y0, double x1, double y1, int align)
{
    double dx = x1 - x0, dy = y1 - y0, L, th, cs, sn, anchor = 0.0, w, sx, sy, off = 0.0;
    int flag = 1, la = 0;
    oo *o;

    if (fabs(dx) <= 1e-07 && fabs(dy) <= 1e-07)
        return 0;
    L = sqrt(dx * dx + dy * dy);
    th = atan2(dy, dx);
    cs = cos(th);
    sn = sin(th);
    switch (align) {
    case -1: anchor = 0.0; flag = 3; la = 2; break;
    case 0:  anchor = L / 2.0; flag = 2; la = 1; break;
    case 1:  anchor = L; flag = 1; la = 0; break;
    case 2:  anchor = 0.0; flag = 1; la = 0; break;
    case -2: anchor = L; flag = 3; la = 2; break;
    }
    w = text_width(c, s);
    sx = cs * anchor + x0;
    sy = sn * anchor + y0;
    off = -w * (double)la / 2.0;
    o = ob_new(&c->b, JW_MOJI);
    if (!o)
        return -1;
    o->d[0] = sx + cs * off;
    o->d[1] = sy + sn * off;
    o->d[2] = cs * w + o->d[0];
    o->d[3] = sn * w + o->d[1];
    o->d[4] = c->tw;
    o->d[5] = c->th;
    o->d[6] = c->tsp;
    o->d[7] = th * 180.0 / PI;
    o->ltype = flag;
    o->color = c->tcol ? c->tcol : c->o->text_color;
    o->n = c->sz;
    strncpy(o->text, s, sizeof o->text - 1);
    o->has_text = 1;
    return 1;
}

/* table text: 479c40 with the end point on the same baseline (y), 10000 mm away */
static int ob_cell(octx *c, const char *s, double x, double y, int align)
{
    return ob_text(c, s, x, y, 10000.0, y, align);
}

/* FUN_0073e770: a radial/chord/height line given relative to the circle centre
 * (FUN_0073cb80 adds the centre; a zero length line is dropped) */
static int ob_rline(octx *c, double x0, double y0, double x1, double y1)
{
    oo *o;

    if (fabs(x1 - x0) < 1e-07 && fabs(y1 - y0) < 1e-07)
        return 0;
    o = ob_new(&c->b, JW_SEN);
    if (!o)
        return -1;
    o->d[0] = x0 + c->cx;
    o->d[1] = y0 + c->cy;
    o->d[2] = x1 + c->cx;
    o->d[3] = y1 + c->cy;
    o->color = c->o->line_color;
    o->ltype = 1;
    o->flags = 0x20;
    return 1;
}

/* FUN_0073e900: the table frame, absolute coordinates, colour DAT_00a0bec0/10 */
static int ob_aline(octx *c, double x0, double y0, double x1, double y1)
{
    oo *o = ob_new(&c->b, JW_SEN);

    if (!o)
        return -1;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    o->color = c->o->table_color;
    o->ltype = 1;
    o->flags = 0x20;
    return 1;
}

static int ob_circle(octx *c, double cx, double cy, double r, int col, int lt)
{
    oo *o = ob_new(&c->b, JW_ENKO);

    if (!o)
        return -1;
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = 0.0;
    o->d[4] = 6.283185307179586;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    o->d[7] = 0.0;
    o->n = 1;
    o->color = col;
    o->ltype = lt;
    return 1;
}

static int ob_ground_line(octx *c, double x0, double y0, double x1, double y1, int col, int lt)
{
    oo *o = ob_new(&c->b, JW_SEN);

    if (!o)
        return -1;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    o->color = col;
    o->ltype = lt;
    return 1;
}

/* ------------------------------------------------------------------ */
/* 3-D lines (FUN_0073d240 ...)                                        */
/* ------------------------------------------------------------------ */
typedef struct {
    double x0, y0, z0, x1, y1, z1;
    int f44, f48;
    int color, ltype;
    double key;
} l3;

typedef struct { l3 *a; int n, cap; } l3buf;

/* FUN_0073d240 */
static int add3d(l3buf *b, double x0, double y0, double x1, double y1, double z0, double z1,
                 int color, int ltype)
{
    l3 *l;

    if (fabs(x0 - x1) < 1e-07 && fabs(y0 - y1) < 1e-07 && fabs(z0 - z1) < 1e-07)
        return 0;
    if (b->n >= b->cap) {
        int nc = b->cap ? b->cap * 2 : 256;
        l3 *na = (l3 *)realloc(b->a, (size_t)nc * sizeof(l3));

        if (!na)
            return -1;
        b->a = na;
        b->cap = nc;
    }
    l = &b->a[b->n++];
    l->x0 = x0;
    l->y0 = y0;
    l->x1 = x1;
    l->y1 = y1;
    l->z0 = z0;
    l->z1 = z1;
    l->f44 = (z0 <= 1e-07 && z1 <= 1e-07) ? 1 : 0;
    l->f48 = 0;
    l->color = color;
    l->ltype = ltype;
    l->key = 0.0;
    return 1;
}

/* FUN_0073cde0: a line that crosses z = 0 is split there */
static int add3d_split(l3buf *b, double x0, double y0, double x1, double y1, double z0, double z1,
                       int color, int ltype)
{
    if (fabs(x0 - x1) < 1e-07 && fabs(y0 - y1) < 1e-07)
        return add3d(b, x0, y0, x1, y1, z0, z1, color, ltype);
    if (fabs(z0 - z1) >= 1e-07 && (z0 <= -1e-07 || z1 <= -1e-07) &&
        (z0 >= 1e-07 || z1 >= 1e-07)) {
        double t = (0.0 - z0) / (z1 - z0);
        double mx = x0 + (x1 - x0) * t, my = y0 + (y1 - y0) * t;
        int r1 = add3d(b, x0, y0, mx, my, z0, 0.0, color, ltype);
        int r2 = add3d(b, mx, my, x1, y1, 0.0, z1, color, ltype);

        if (r1 < 0 || r2 < 0)
            return -1;
        return r1 + r2;
    }
    return add3d(b, x0, y0, x1, y1, z0, z1, color, ltype);
}

/* FUN_0073dc40 for one end: parse the height text; returns the count (0 = none).
 * v[0] = top, v[1] = bottom, both already in drawing mm (k = 1000/scale). */
static int parse_end(const char *s, double level, double base, double k, double *top, double *bot)
{
    char buf[256], *p, *e;
    double v[12];
    int n = 0, j = 0, i;

    for (i = 0; s[i] && j < (int)sizeof buf - 1; i++)
        if (s[i] != ' ')
            buf[j++] = s[i];
    buf[j] = 0;
    p = buf;
    while (n < 12) {
        v[n] = strtod(p, &e);
        if (e == p)
            break;
        n++;
        p = e;
        if (*p == ',')
            p++;
        else
            break;
    }
    if (n <= 0)
        return 0;
    {
        double d8 = v[0], d0 = n > 1 ? v[1] : 0.0;

        if (n > 1) {
            n = 2;
            d8 += base;
            d0 += base;
            d8 -= level;
            d0 -= level;
        }
        if (n == 1) {
            if (0.0 <= d8) {
                d8 = (d8 + base) - level;
                d0 = -level;
                if (0.0 < d0)
                    d0 = 0.0;
                n = 2;
            } else {
                d8 = -d8 + base;
                d8 -= level;
                n = 1;
            }
        }
        *top = d8 * k;
        *bot = d0 * k;
    }
    return n;
}

static double write_scale(const jw_drawing *d)
{
    int g, wg = 0;
    double sc;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    sc = d->group[wg].scale;
    return sc > 0.0 ? sc : 1.0;
}

/* the collector (FUN_0073b870 + FUN_0073c0c0), in drawing order */
static int collect3d(const jw_drawing *d, const hk_sansha_opts *o, l3buf *out)
{
    int i, j, ntx = 0, wg = 0, g;
    int *tx = 0;
    unsigned char *used = 0;
    double k, scale0, level = o->t.plane_m;
    int ret = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    scale0 = d->group[wg].scale;
    if (scale0 <= 0.0)
        scale0 = 1.0;
    k = 1000.0 / scale0;
    tx = (int *)malloc((size_t)(d->ndrawn + 1) * sizeof(int));
    used = (unsigned char *)calloc((size_t)(d->ndrawn + 1), 1);
    if (!tx || !used) {
        free(tx);
        free(used);
        return -1;
    }
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *t = &d->obj[i];

        if (t->cls != JW_MOJI || t->text < 0)
            continue;
        if ((t->flags & 0x40) || !(t->flags & 0x80))
            continue;
        if (t->layer > 15 || t->lgroup > 15)
            continue;
        {
            double sc = d->group[t->lgroup].scale;

            if (sc <= 0.0)
                sc = 1.0;
            if (fabs(sc - scale0) > 1e-9) {
                ret = -1;
                goto done;
            }
        }
        tx[ntx++] = i;
    }
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *l = &d->obj[i];
        int n0 = 0, n1 = 0;
        double top0 = 0, bot0 = 0, top1 = 0, bot1 = 0, base;

        if (l->cls != JW_SEN || l->ltype == 9)
            continue;
        if (l->lgroup > 15 || l->layer > 15)
            continue;
        if (d->group[l->lgroup].layer[l->layer].state == 0 || d->group[l->lgroup].state == 0)
            continue;
        if (fabs(l->d[0] - l->d[2]) + fabs(l->d[1] - l->d[3]) < 1e-07)
            continue;
        base = hk_level_from_name(jw_str(d, d->group[l->lgroup].name)) +
               hk_level_from_name(jw_str(d, d->group[l->lgroup].layer_name[l->layer]));
        for (j = 0; j < ntx; j++) {
            const jw_obj *t = &d->obj[tx[j]];
            double tt, bb;
            int c;

            if (t->layer != l->layer || t->lgroup != l->lgroup)
                continue;
            if (fabs(l->d[0] - t->d[0]) + fabs(l->d[1] - t->d[1]) <= 0.001) {
                c = parse_end(jw_str(d, t->text), level, base, k, &tt, &bb);
                if (c) {
                    if (used[tx[j]])
                        c = -c;
                    used[tx[j]] = 1;
                    n0 = c;
                    top0 = tt;
                    bot0 = bb;
                }
            }
            if (fabs(l->d[2] - t->d[0]) + fabs(l->d[3] - t->d[1]) <= 0.001) {
                c = parse_end(jw_str(d, t->text), level, base, k, &tt, &bb);
                if (c) {
                    if (used[tx[j]])
                        c = -c;
                    used[tx[j]] = 1;
                    n1 = c;
                    top1 = tt;
                    bot1 = bb;
                }
            }
        }
        if (n0 == 0 && n1 == 0)
            continue;
        if (abs(n0) == 2 && abs(n1) == 2)
            if (add3d_split(out, l->d[0], l->d[1], l->d[2], l->d[3], bot0, bot1, l->color, l->ltype) < 0)
                { ret = -1; goto done; }
        if (add3d_split(out, l->d[0], l->d[1], l->d[2], l->d[3], top0, top1, l->color, l->ltype) < 0)
            { ret = -1; goto done; }
        if (n0 > 1 && fabs(top0 - bot0) > 1e-07)
            if (add3d_split(out, l->d[0], l->d[1], l->d[0], l->d[1], top0, bot0, l->color, l->ltype) < 0)
                { ret = -1; goto done; }
        if (n1 > 1 && fabs(top1 - bot1) > 1e-07)
            if (add3d_split(out, l->d[2], l->d[3], l->d[2], l->d[3], top1, bot1, l->color, l->ltype) < 0)
                { ret = -1; goto done; }
    }
done:
    free(tx);
    free(used);
    return ret;
}

/* ------------------------------------------------------------------ */
/* stage B                                                             */
/* ------------------------------------------------------------------ */
static double tri_area3(double px, double py, const l3 *l)
{
    double ax = l->x0 - px, ay = l->y0 - py, az = l->z0;
    double bx = l->x1 - px, by = l->y1 - py, bz = l->z1;
    double cx = ay * bz - az * by, cy = az * bx - ax * bz, cz = ax * by - ay * bx;
    double n = sqrt(cx * cx + cy * cy + cz * cz);

    return n > 1e-9 ? 0.5 * n : 0.0;
}

static void stage_b(l3 *a, int n, double px, double py)
{
    int i, j;

    for (i = 0; i < n; i++) {
        l3 *l = &a[i];
        double mx, my, perp, t;
        frame f;

        l->f44 = 0;
        l->f48 = 0;
        mx = (l->x0 + l->x1) / 2.0;
        my = (l->y0 + l->y1) / 2.0;
        frame_set(&f, px, py, mx, my);
        if (!f.valid) {
            l->f48 = 1;
            continue;
        }
        perp = f_perp(&f, l->x1, l->y1);
        if (1e-07 > perp) {
            t = l->x0; l->x0 = l->x1; l->x1 = t;
            t = l->y0; l->y0 = l->y1; l->y1 = t;
            t = l->z0; l->z0 = l->z1; l->z1 = t;
        }
        if (1e-07 > fabs(perp)) {
            l->f44 = 1;
            continue;
        }
        if (1e-07 > l->z0 && 1e-07 > l->z1)
            l->f44 = 1;
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++) {
            double k1 = 0.0, k2 = 0.0;

            if (a[i].f44 == 0 && a[i].f48 == 0)
                k1 = tri_area3(px, py, &a[i]);
            if (a[j].f44 == 0 && a[j].f48 == 0)
                k2 = tri_area3(px, py, &a[j]);
            if (k1 < k2) {
                l3 t = a[i];

                a[i] = a[j];
                a[j] = t;
            }
        }
}

/* [D 0x741553..0x741c70] merge the lines that lie in one plane with the viewpoint: a normal
 * line A (after the sort) swallows every later normal line B whose azimuth range overlaps or
 * touches A's and whose ends lie within |2 * nz|/scale of the plane (V, A.p0, A.p1) -- the
 * 3-D frame FUN_005f9450 is an orthonormal one (rotation about z, tilt, roll), so the
 * coordinate it calls z is the signed distance from that plane.  A takes B's far end(s), B is
 * dropped (f48 = 1) and the scan starts again.  Not covered by the sample  [G: unverified]. */
static int plane_of(double px, double py, const l3 *a, double n[3])
{
    double ax = a->x0 - px, ay = a->y0 - py, az = a->z0;
    double bx = a->x1 - px, by = a->y1 - py, bz = a->z1;
    double nn, la;

    if (ax * ax + ay * ay < 1e-07)
        return 0;
    n[0] = ay * bz - az * by;
    n[1] = az * bx - ax * bz;
    n[2] = ax * by - ay * bx;
    nn = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    la = ax * ax + ay * ay + az * az;
    if (la < 1e-07 || nn * nn / la < 1e-07)
        return 0;
    n[0] /= nn;
    n[1] /= nn;
    n[2] /= nn;
    return 1;
}

static void stage_b3(l3 *a, int cnt, double px, double py, double scale)
{
    int i, j;

    for (i = 0; i < cnt; i++) {
        double nv[3], tol, ox0, oy0, ox1, oy1;
        frame f1, f2;
        int changed;

        if (a[i].f44 || a[i].f48)
            continue;
        if (!plane_of(px, py, &a[i], nv))
            continue;
        /* the distance of (P1 + 2 in z) from the plane, over the scale of the current group */
        tol = fabs(((a[i].x1 - px) * nv[0] + (a[i].y1 - py) * nv[1] + (a[i].z1 + 2.0) * nv[2]) / scale);
        do {
            changed = 0;
            ox0 = a[i].x0; oy0 = a[i].y0; ox1 = a[i].x1; oy1 = a[i].y1;
            frame_set(&f1, px, py, ox0, oy0);
            frame_set(&f2, px, py, ox1, oy1);
            for (j = i + 1; j < cnt; j++) {
                l3 *b = &a[j];
                double c0, c1, d0, d1, e0, e1;

                if (b->f44 || b->f48)
                    continue;
                c0 = f_perp(&f1, b->x0, b->y0);
                c1 = f_perp(&f1, b->x1, b->y1);
                if (-1e-07 > c0 && -1e-07 > c1)
                    continue;
                d0 = f_perp(&f2, b->x0, b->y0);
                d1 = f_perp(&f2, b->x1, b->y1);
                if (d0 > 1e-07 && d1 > 1e-07)
                    continue;
                e0 = (b->x0 - px) * nv[0] + (b->y0 - py) * nv[1] + b->z0 * nv[2];
                e1 = (b->x1 - px) * nv[0] + (b->y1 - py) * nv[1] + b->z1 * nv[2];
                if (fabs(e0) > tol || fabs(e1) > tol)
                    continue;
                if (0.0 > c0) {
                    a[i].x0 = b->x0;
                    a[i].y0 = b->y0;
                    a[i].z0 = b->z0;
                }
                if (d1 > 0.0) {
                    a[i].x1 = b->x1;
                    a[i].y1 = b->y1;
                    a[i].z1 = b->z1;
                }
                b->f48 = 1;
                changed = 1;
                break;
            }
        } while (changed);
    }
}

/* ------------------------------------------------------------------ */
/* stage C: pieces                                                     */
/* ------------------------------------------------------------------ */
typedef struct {
    double x0, y0, x1, y1;
    int ground, id, color, ltype;
} piece;

typedef struct { piece *a; int n, cap; } pbuf;

static int add_piece(pbuf *b, double x0, double y0, double x1, double y1, int ground, int id,
                     int color, int ltype)
{
    piece *p;

    if (b->n >= b->cap) {
        int nc = b->cap ? b->cap * 2 : 2048;
        piece *na = (piece *)realloc(b->a, (size_t)nc * sizeof(piece));

        if (!na)
            return -1;
        b->a = na;
        b->cap = nc;
    }
    p = &b->a[b->n++];
    p->x0 = x0;
    p->y0 = y0;
    p->x1 = x1;
    p->y1 = y1;
    p->ground = ground;
    p->id = id;
    p->color = color;
    p->ltype = ltype;
    return 0;
}

static void proj(const octx *c, double x, double y, double h, double *ox, double *oy)
{
    hk_tenkuu_project(c->px, c->py, x, y, h, c->R, c->o->t.equidist, c->o->t.mirror,
                      c->o->t.mirror_off, ox, oy);
}

/* az of (dx,dy) as stage C computes it: 1001 if the point is the viewpoint */
static double az_of(double dx, double dy)
{
    double az = 1001.0, a;

    if (fabs(dx) > 1e-07 || fabs(dy) > 1e-07) {
        az = atan2(dy, dx);
        a = fabs(az);
        if (fabs(a - PI) <= 1e-07)
            az = PI;
    }
    return az;
}

static int stage_c(const octx *c, l3 *a, int n, pbuf *pb)
{
    double step = c->o->step_tenth < 0 || c->o->step_tenth > 0
                      ? (double)abs(c->o->step_tenth) * 0.0017453292519943296
                      : 0.03490658503988659;
    int i, id = 0;

    for (i = 0; i < n; i++) {
        l3 *l = &a[i];
        double x0, y0, z0, x1, y1, z1, mx, my, perp, az0, az1;
        int radial, ground;
        double q0x, q0y, q1x, q1y, prx, pry;
        frame f;

        if (l->f48)
            continue;
        x0 = l->x0; y0 = l->y0; z0 = l->z0;
        x1 = l->x1; y1 = l->y1; z1 = l->z1;
        mx = (x0 + x1) / 2.0;
        my = (y0 + y1) / 2.0;
        frame_set(&f, c->px, c->py, mx, my);
        if (f.valid) {
            perp = f_perp(&f, x1, y1);
            if (1e-07 > perp) {
                double t;

                t = x0; x0 = x1; x1 = t;
                t = y0; y0 = y1; y1 = t;
                t = z0; z0 = z1; z1 = t;
            }
        }
        az0 = az_of(x0 - c->px, y0 - c->py);
        az1 = az_of(x1 - c->px, y1 - c->py);
        if (1000.0 <= az0 || 1000.0 <= az1) {
            az0 = 0.0;
            az1 = 0.0;
        } else if (fabs(az0 - az1) < 1e-07) {
            az1 = az0;
        } else if (az1 < az0) {
            az1 += 2 * PI;
        }
        radial = fabs(az1 - az0) < 1e-07;
        ground = (1e-07 > z0 && 1e-07 > z1);
        proj(c, x0, y0, z0, &q0x, &q0y);
        id++;
        prx = q0x;
        pry = q0y;
        if (!radial) {
            int kk = (int)(az0 / step) - 1;
            double a2 = (double)kk * step, div10 = step / 10.0;

            for (; a2 < az1 - div10; a2 += step) {
                double ex, ey, hx, hy, qx, qy, z, d1, d2;

                if (az0 + div10 > a2)
                    continue;
                ex = cos(a2) * c->R + c->px;
                ey = sin(a2) * c->R + c->py;
                /* the plan line is the object's own (already swapped by stage B) */
                if (!isect(c->px, c->py, ex, ey, l->x0, l->y0, l->x1, l->y1, &hx, &hy))
                    continue;
                d1 = sqrt((l->x1 - l->x0) * (l->x1 - l->x0) + (l->y1 - l->y0) * (l->y1 - l->y0));
                d2 = sqrt((hx - l->x0) * (hx - l->x0) + (hy - l->y0) * (hy - l->y0));
                z = (l->z1 - l->z0) * d2 / d1 + l->z0;
                proj(c, hx, hy, z, &qx, &qy);
                if (add_piece(pb, prx, pry, qx, qy, ground, id, l->color, l->ltype) < 0)
                    return -1;
                prx = qx;
                pry = qy;
            }
        }
        proj(c, x1, y1, z1, &q1x, &q1y);
        if (add_piece(pb, prx, pry, q1x, q1y, ground, id, l->color, l->ltype) < 0)
            return -1;
    }
    return 0;
}

/* ------------------------------------------------------------------ */
/* the sweep and the fans                                              */
/* ------------------------------------------------------------------ */
typedef struct {
    octx *c;
    const piece *pc;
    int npc;
    int runl[MAXRUN + 4];
    int rc;                          /* [20014] pieces in the open run */
    int cnt;                         /* [20008] triangles */
    double base[MAXTRI + 4], hgt[MAXTRI + 4], prv[MAXTRI + 4];
    double total;                    /* [20248] sum of the run angles */
    double maxdiv_rad, dt, cw, ch, R;
    int first;                       /* [200a4] */
    int err;
    /* speed only: the pieces that can be hit by a forward ray of a given azimuth (0.5 deg
       buckets, ascending piece order, so every loop sees the same pieces in the same order) */
    int *bstart, *bidx;
} sweep;

#define NBK 720

/* azimuth interval [lo, lo+wid] in which a forward ray can cross the piece; wid = 2pi: any */
static void piece_span(const piece *p, double *lo, double *wid)
{
    double a0, a1, d;

    *lo = 0.0;
    *wid = 2.0 * PI;
    if (fabs(p->x0) + fabs(p->y0) < 1e-6 || fabs(p->x1) + fabs(p->y1) < 1e-6)
        return;
    a0 = atan2(p->y0, p->x0);
    a1 = atan2(p->y1, p->x1);
    d = a1 - a0;
    while (d > PI)
        d -= 2.0 * PI;
    while (d <= -PI)
        d += 2.0 * PI;
    if (fabs(d) > PI - 1e-3)
        return;
    if (d >= 0.0) {
        *lo = a0;
        *wid = d;
    } else {
        *lo = a1;
        *wid = -d;
    }
    while (*lo < 0.0)
        *lo += 2.0 * PI;
    while (*lo >= 2.0 * PI)
        *lo -= 2.0 * PI;
}

static int build_buckets(sweep *w)
{
    const double bw = 2.0 * PI / NBK, mg = 1e-5;
    int j, b, pass, tot = 0;
    int *pos;

    w->bstart = (int *)calloc(NBK + 2, sizeof(int));
    pos = (int *)calloc(NBK + 2, sizeof(int));
    if (!w->bstart || !pos) {
        free(pos);
        return -1;
    }
    for (pass = 0; pass < 2; pass++) {
        if (pass == 1) {
            for (b = 0; b < NBK; b++) {
                int t = w->bstart[b];

                w->bstart[b] = tot;
                tot += t;
            }
            w->bstart[NBK] = tot;
            w->bidx = (int *)malloc((size_t)(tot + 1) * sizeof(int));
            if (!w->bidx) {
                free(pos);
                return -1;
            }
            memcpy(pos, w->bstart, (size_t)(NBK + 1) * sizeof(int));
        }
        for (j = 0; j < w->npc; j++) {
            double lo, wid;
            int b0, b1, k;

            piece_span(&w->pc[j], &lo, &wid);
            if (wid >= 2.0 * PI - 1e-9) {
                b0 = 0;
                b1 = NBK - 1;
            } else {
                b0 = (int)floor((lo - mg) / bw);
                b1 = (int)floor((lo + wid + mg) / bw);
                if (b1 - b0 >= NBK) {
                    b0 = 0;
                    b1 = NBK - 1;
                }
            }
            for (k = b0; k <= b1; k++) {
                int bb = ((k % NBK) + NBK) % NBK;

                if (pass == 0)
                    w->bstart[bb]++;
                else
                    w->bidx[pos[bb]++] = j;
            }
        }
    }
    free(pos);
    return 0;
}

/* the pieces a forward ray of azimuth ang can hit, in piece order */
static int cand(const sweep *w, double ang, const int **l)
{
    double a = fmod(ang, 2.0 * PI);
    int b;

    if (a < 0.0)
        a += 2.0 * PI;
    b = (int)(a / (2.0 * PI / NBK));
    if (b >= NBK)
        b = NBK - 1;
    *l = w->bidx + w->bstart[b];
    return w->bstart[b + 1] - w->bstart[b];
}

/* any piece hit by the ray?  (first scan and the "hit" test of the sweep) */
static int any_hit(const sweep *w, const frame *F, double ex, double ey, double ang)
{
    const int *lst;
    int jj, nc = cand(w, ang, &lst);

    for (jj = 0; jj < nc; jj++) {
        const piece *p = &w->pc[lst[jj]];
        double c0 = F->c * p->y0 - F->s * p->x0, c1 = F->c * p->y1 - F->s * p->x1, hx, hy;

        if (c0 * c1 > 0.0)
            continue;
        if (F->c * p->x0 + F->s * p->y0 < 0.0 && F->c * p->x1 + F->s * p->y1 < 0.0)
            continue;
        if (!isect(0.0, 0.0, ex, ey, p->x0, p->y0, p->x1, p->y1, &hx, &hy))
            continue;
        if (F->c * hx + F->s * hy < 1e-07)
            continue;
        return 1;
    }
    return 0;
}

static double mydist(double ax, double ay, double bx, double by)
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

/* FUN_00462070 with the ray through (rx,ry): the point of the circle (radius R, centre
 * O) in that direction.  0 if the ray is degenerate. */
static int circle_point(double rx, double ry, double R, double *ox, double *oy)
{
    frame f;

    frame_set(&f, 0.0, 0.0, rx, ry);
    if (!f.valid)
        return 0;
    *ox = f.c * R;
    *oy = f.s * R;
    return 1;
}

/* the triangles of one run: the run's pieces are w->runl[1..w->rc] */
static void fan(sweep *w, double vsx, double vsy, double ex, double ey, double pendx, double pendy,
                int s_neg)
{
    octx *c = w->c;
    const hk_sansha_opts *o = c->o;
    double aa = atan2(vsy, vsx), ab = atan2(ey, ex), D, step;
    double pprx = 0.0, ppry = 0.0, pcx = 0.0, pcy = 0.0, lastx = 9990000000000.0, lasty = 9990000000000.0;
    double R = w->R;
    int n, kk;

    if (aa > ab)
        ab += 2.0 * PI;
    D = ab - aa;
    w->total += D;
    n = (int)(D / w->maxdiv_rad) + 1;
    step = D / (double)n;
    if (w->rc < 1)
        return;
    for (kk = 0; kk <= n; kk++) {
        double rex, rey, mind, d1x, d1y;
        double ppx, ppy, pcx2, pcy2;       /* [19010], [19020] */
        frame F;
        int lo = 1, hi = w->rc, i;

        if (kk == 0) {
            rex = vsx;
            rey = vsy;
            if (w->first) {
                double cx0, cy0;

                if (!circle_point(rex, rey, R, &cx0, &cy0))
                    continue;
                if (ob_rline(c, 0.0, 0.0, cx0, cy0) < 0) { w->err = 1; return; }
                w->first = 0;
            }
        } else if (kk == n && s_neg) {
            double cx0, cy0;

            rex = pendx;
            rey = pendy;
            if (!circle_point(rex, rey, R, &cx0, &cy0))
                continue;
            if (ob_rline(c, 0.0, 0.0, cx0, cy0) < 0) { w->err = 1; return; }
        } else {
            double ang = (double)kk * step + aa;

            rex = cos(ang) * R;
            rey = sin(ang) * R;
        }
        frame_set(&F, 0.0, 0.0, rex, rey);
        if (!F.valid)
            continue;
        mind = 9e+20;
        if (kk == 0)
            hi = 1;
        if (kk == n)
            lo = w->rc;
        for (i = lo; i <= hi; i++) {
            const piece *p = &w->pc[w->runl[i]];
            double hx, hy, dd;

            if (kk != 0 && kk != n) {
                double c0 = F.c * p->y0 - F.s * p->x0, c1 = F.c * p->y1 - F.s * p->x1;

                if (c0 * c1 > 0.0)
                    continue;
            }
            if (!isect(0.0, 0.0, rex, rey, p->x0, p->y0, p->x1, p->y1, &hx, &hy))
                continue;
            dd = F.c * hx + F.s * hy;
            if (mind > dd) {
                mind = dd;
                pcx = hx;
                pcy = hy;
            }
        }
        ppx = pprx;
        ppy = ppry;
        pcx2 = pcx;
        pcy2 = pcy;
        pprx = pcx;
        ppry = pcy;
        if (kk > 0 && mydist(ppx, ppy, pcx2, pcy2) < 1e-07)
            continue;
        if (!o->simple) {
            double t = 0.05, maxgap = 0.0, tx = ppx, ty = ppy, d, d2, u1x, u1y, u2x, u2y;
            frame F3;

            if (kk == 0)
                continue;
            while (0.95 > t) {
                double qx, qy, dq, mn, dd;
                frame F2;
                int j;

                t += w->dt;
                qx = ppx + t * (pcx2 - ppx);
                qy = ppy + t * (pcy2 - ppy);
                frame_set(&F2, 0.0, 0.0, qx, qy);
                if (!F2.valid)
                    continue;
                if (!isect(0.0, 0.0, qx, qy, ppx, ppy, pcx2, pcy2, &lastx, &lasty))
                    continue;
                dq = F2.c * lastx + F2.s * lasty;
                mn = 9e+20;
                for (j = 1; j <= w->rc; j++) {
                    const piece *p = &w->pc[w->runl[j]];
                    double c0 = F2.c * p->y0 - F2.s * p->x0, c1 = F2.c * p->y1 - F2.s * p->x1;
                    int ok;

                    if (c0 * c1 > 0.0)
                        continue;
                    ok = isect(0.0, 0.0, qx, qy, p->x0, p->y0, p->x1, p->y1, &lastx, &lasty);
                    if (!ok)
                        continue;
                    dd = F2.c * lastx + F2.s * lasty;
                    if (mn > dd)
                        mn = dd;
                }
                if (mn > 8e+20)
                    continue;
                dd = mn - dq;
                if (dd > maxgap) {
                    maxgap = dd;
                    tx = lastx;
                    ty = lasty;
                }
            }
            frame_set(&F3, pcx2, pcy2, ppx, ppy);
            if (!F3.valid)
                continue;
            d = f_perp(&F3, tx, ty);
            d2 = d + 0.001;
            f_global(&F3, 0.0, d2, &u1x, &u1y);
            f_global(&F3, F3.len, d2, &u2x, &u2y);
            if (!isect(0.0, 0.0, ppx, ppy, u1x, u1y, u2x, u2y, &d1x, &d1y))
                continue;
            ppx = d1x;
            ppy = d1y;
            if (!isect(0.0, 0.0, pcx2, pcy2, u1x, u1y, u2x, u2y, &d1x, &d1y))
                continue;
            pcx2 = d1x;
            pcy2 = d1y;
            if (ob_rline(c, 0.0, 0.0, ppx, ppy) < 0 || ob_rline(c, 0.0, 0.0, pcx2, pcy2) < 0) {
                w->err = 1;
                return;
            }
        } else {
            if (ob_rline(c, 0.0, 0.0, pcx2, pcy2) < 0) { w->err = 1; return; }
            if (kk == 0)
                continue;
        }
        /* LAB_00745dae: chord, then the triangle's height and label */
        {
            double fx, fy, nx, ny, along, perp, footx, footy, t, lx, ly, v;
            frame F5, F6;
            char lab[64];

            if (ob_rline(c, ppx, ppy, pcx2, pcy2) < 0) { w->err = 1; return; }
            if (pcx2 * pcx2 + pcy2 * pcy2 > ppx * ppx + ppy * ppy) {
                fx = pcx2; fy = pcy2; nx = ppx; ny = ppy;
            } else {
                fx = ppx; fy = ppy; nx = pcx2; ny = pcy2;
            }
            frame_set(&F5, 0.0, 0.0, fx, fy);
            if (!F5.valid)
                continue;
            along = f_along(&F5, nx, ny);
            perp = f_perp(&F5, nx, ny);
            f_global(&F5, along, 0.0, &footx, &footy);
            if (ob_rline(c, nx, ny, footx, footy) < 0) { w->err = 1; return; }
            w->cnt++;
            if (w->cnt > 0xe10) {
                w->err = 2;
                return;
            }
            w->base[w->cnt] = F5.len;
            w->hgt[w->cnt] = perp;
            frame_set(&F6, pcx2, pcy2, 0.0, 0.0);
            if (!F6.valid) {
                w->prv[w->cnt] = 1.0;
                continue;
            }
            t = f_along(&F6, nx, ny) + w->cw;
            if (w->cnt > 1) {
                if (fabs(perp) < w->ch * 1.2) {
                    v = F6.len - t;
                    if (w->prv[w->cnt - 1] > v - w->cw * 2.0 && v > w->prv[w->cnt - 1] - w->cw * 2.0) {
                        v = w->prv[w->cnt - 1] - w->cw * 2.0;
                        if (v > w->cw * 3.0)
                            t = F6.len - v;
                    }
                }
            }
            w->prv[w->cnt] = F6.len - t;
            f_global(&F6, t, 0.0, &lx, &ly);
            if (fabs(lx - 0.0) < 1e-07 && fabs(ly - 0.0) < 1e-07)
                continue;
            snprintf(lab, sizeof lab, "%s%d%s", o->br_open, w->cnt, o->br_close);
            if (ob_text(c, lab, lx + c->cx, ly + c->cy, c->cx, c->cy, 2) < 0) {
                w->err = 1;
                return;
            }
        }
    }
}

/* the whole sweep.  Returns 0, or <0 on error */
static int do_sweep(sweep *w)
{
    octx *c = w->c;
    const double step_s = 1.7453292519943296e-05;
    const int N = 360000;
    double a_start = 0.0, ang;
    int S = 0, i, curId, curPiece;
    double vsx = 0, vsy = 0, ehx = 0, ehy = 0, pendx = 0, pendy = 0;
    double tol = w->R / 100000000000000.0, R = w->R;

    if (build_buckets(w) < 0)
        return -5;

    for (ang = 0.0; ang <= 6.283185307179586; ang += step_s) {
        frame F;
        double ex = cos(ang) * R, ey = sin(ang) * R;

        frame_set(&F, 0.0, 0.0, ex, ey);
        if (!any_hit(w, &F, ex, ey, ang)) {
            a_start = ang;
            break;
        }
    }
    if (6.283185307179586 <= ang)
        return -3;
    memset(w->runl, 0xff, sizeof w->runl);
    w->first = 1;
    for (i = 1; i <= N; i++) {
        double a = (double)i * step_s + a_start;
        double ex = cos(a) * R, ey = sin(a) * R, mn, mx, p0cx = 0, p0cy = 0;
        frame F;
        const int *lst;
        int j, jj, nc, hit;

        frame_set(&F, 0.0, 0.0, ex, ey);
        hit = any_hit(w, &F, ex, ey, a);
        if (!hit && S < 1) {
            S = 0;
            continue;
        }
        mn = 9e+20;
        mx = -9e+20;
        curId = 0;
        curPiece = -1;
        (void)p0cx;
        (void)p0cy;
        nc = cand(w, a, &lst);
        for (jj = 0; jj < nc; jj++) {
            const piece *p;
            double c0, c1, hx, hy, dist;

            j = lst[jj];
            p = &w->pc[j];
            c0 = F.c * p->y0 - F.s * p->x0;
            c1 = F.c * p->y1 - F.s * p->x1;
            if (c0 * c1 > 0.0)
                continue;
            if (!isect(0.0, 0.0, ex, ey, p->x0, p->y0, p->x1, p->y1, &hx, &hy))
                continue;
            dist = F.c * hx + F.s * hy;
            if (dist < 1e-07)
                continue;
            if (p->ground)
                dist = R;
            if (mn - tol > dist && R - 1e-07 > dist) {
                mn = dist;
                curId = p->id;
                curPiece = j;
                if (S == 0) {
                    vsx = p->x0;
                    vsy = p->y0;
                }
                ehx = hx;
                ehy = hy;
                pendx = p->x1;
                pendy = p->y1;
            }
            if (dist > mx)
                mx = dist;
        }
        if (mx - 1e-07 <= mn) {
            if (S <= 0) {
                S = 0;
                w->first = 1;
                continue;
            }
            S = -S;
        }
        if (S == 0) {
            w->rc = 0;
            S = curId;
            w->first = 1;
        }
        if (curId == S) {
            if (w->runl[w->rc] != curPiece) {
                w->rc++;
                w->runl[w->rc] = curPiece;
            }
            if (w->rc > 0xe10)
                return -4;
            continue;
        }
        /* the run is over (id changed, or no sky behind any more) */
        if (curId > 0) {
            double dh = step_s / 2.0, am = a - dh;
            int it;

            w->runl[w->rc + 1] = curPiece;
            for (it = 1; it <= 8; it++) {
                double rx = cos(am) * R, ry = sin(am) * R, m2 = 9e+20;
                int curK = 0, k, pcn = -1;
                frame F2;

                frame_set(&F2, 0.0, 0.0, rx, ry);
                for (k = 0; k < 2; k++) {
                    const piece *p;
                    double c0, c1, hx, hy, dist;

                    pcn = w->runl[w->rc + k];
                    if (k == 0 && w->rc == 0)
                        pcn = -1;
                    if (pcn < 0)
                        break;
                    p = &w->pc[pcn];
                    c0 = F2.c * p->y0 - F2.s * p->x0;
                    c1 = F2.c * p->y1 - F2.s * p->x1;
                    if (c0 * c1 > 0.0)
                        continue;
                    if (!isect(0.0, 0.0, rx, ry, p->x0, p->y0, p->x1, p->y1, &hx, &hy))
                        continue;
                    dist = F2.c * hx + F2.s * hy;
                    if (dist < m2 - tol) {
                        curK = k;
                        m2 = dist;
                        ehx = hx;
                        ehy = hy;
                    }
                }
                if (pcn >= 0) {
                    dh = dh / 2.0;
                    if (curK == 0)
                        am += dh;
                    else
                        am -= dh;
                }
            }
        }
        if (S < 0) {
            ehx = pendx;
            ehy = pendy;
        } else if (curId > 0) {
            S = curId;
        }
        fan(w, vsx, vsy, ehx, ehy, pendx, pendy, S < 0);
        if (w->err)
            return -4;
        if (curId > 0) {
            vsx = ehx;
            vsy = ehy;
        }
        w->rc = 0;
    }
    (void)c;
    return 0;
}

/* ------------------------------------------------------------------ */
/* numbers as the program prints them                                  */
/* ------------------------------------------------------------------ */
static double q3(const hk_sansha_opts *o, double v)         /* FUN_0073cd70 */
{
    int iv = (int)(v * 1000.0);

    if (o->cut_down == 0 && (double)iv < v * 1000.0)
        iv++;
    return (double)iv / 1000.0;
}

/* sprintf then sscanf("%lg") back, as the original does after every number */
static double reparse(const char *s)
{
    double v = 0.0;

    sscanf(s, "%lg", &v);
    return v;
}

static void table_frame(octx *c, int rows, int flag, double X0, double ye, double cw, double ch)
{
    double xl = X0 - cw, top = ch * 1.25 + ye, bot = (ye - ch * 1.5 * (double)rows) - ch * 0.25;
    double x, xlast;
    int i;

    ob_aline(c, xl, top, xl, bot - (double)flag * 1.5 * ch);
    x = cw * 4.0 + xl;
    ob_aline(c, x, top, x, bot);
    x = cw * 11.0 + xl;
    ob_aline(c, x, top, x, bot);
    x = cw * 19.0 + xl;
    ob_aline(c, x, top, x, bot - (double)flag * 1.5 * ch);
    xlast = cw * 26.0 + xl;
    ob_aline(c, xlast, top, xlast, bot - (double)flag * 1.5 * ch);
    for (i = 0; i <= rows + 1 + flag; i++) {
        double y = top - ch * 1.5 * (double)i;

        ob_aline(c, xl, y, xlast, y);
    }
}

/* the rings of 目盛間隔 (FUN_00738f00): as tenku.c writes them [V sample] */
static double ring_radius(const hk_sansha_opts *o, double R, double el)
{
    return o->t.equidist ? R * (1.0 - el / (PI / 2.0)) : R * cos(el);
}

static void rings(octx *c)
{
    const hk_sansha_opts *o = c->o;
    double a, R = c->R;
    int k;

    for (a = o->t.interval; a < 90.0 - 1e-9; a += o->t.interval) {
        int major = fabs(fmod(a + 1e-9, 30.0)) < 2e-9;

        ob_circle(c, c->cx, c->cy, ring_radius(o, R, a * PI / 180.0), 1, major ? 1 : 4);
    }
    for (k = 0; k * o->t.interval < 360.0 - 1e-9; k++) {
        double ang = k * o->t.interval, rad = ang * PI / 180.0;
        int major = fabs(fmod(ang + 1e-9, 30.0)) < 2e-9;

        ob_ground_line(c, c->cx, c->cy, c->cx + R * cos(rad), c->cy + R * sin(rad), 1, major ? 1 : 4);
    }
}

/* ------------------------------------------------------------------ */
/* options                                                             */
/* ------------------------------------------------------------------ */
/* cmd+0xf0 (dialog 0xfe4) picks the mode AND the strings: 0 = 基準建物用 (tangent triangles,
 * [n], round up), 1 = 計画建物用 (plain chords, <n>, round down); cmd+0x25f8 follows it. */
void hk_sansha_opts_set_mode(hk_sansha_opts *o, int simple)
{
    o->simple = simple ? 1 : 0;
    o->cut_down = o->simple;
    if (o->simple) {
        strcpy(o->label, S_LABEL_PLAN);
        strcpy(o->br_open, "<");
        strcpy(o->br_close, ">");
    } else {
        strcpy(o->label, S_LABEL_BASE);
        strcpy(o->br_open, "[");
        strcpy(o->br_close, "]");
    }
}

void hk_sansha_opts_default(hk_sansha_opts *o)
{
    memset(o, 0, sizeof *o);
    hk_tenku_opts_default(&o->t);
    o->t.R = 100.0;
    o->t.show_point = 1;
    o->maxdiv = 10.0;
    o->calc = 1;
    o->conf = 0;
    o->style = HK_SANSHA_EXE;
    hk_sansha_opts_set_mode(o, 0);
    strcpy(o->name, "No.1");
    o->line_color = 1;
    o->table_color = 1;
    o->point_color = 2;
    o->text_color = 1;
    o->tw = 2.5;
    o->th = 2.5;
    o->tsp = 0.0;
}

/* ------------------------------------------------------------------ */
/* 建物位置確認表 (2114) -- FUN_00734920 (and its caller's first line)  */
/* ------------------------------------------------------------------ */
#define S_CONFNAME "\214\232\225\250\210\312\222u\212m\224F\225\134"
#define S_C_POS    "\210\312\222u"
#define S_C_PLAN   "\224z\222u\220}"
#define S_C_SKY    "\223V\213\363\220}"
#define S_C_DIST   "\213\227\227\243"
#define S_C_HGT    "\215\202\202\263"
#define S_C_AZ     "\225\373\210\312\212p"
#define S_C_ELEV   "\213\302\212p:h"
#define S_C_UREAL  "(\216\300\220\241m)"
#define S_C_UDEG   "(\337)"

static int ob_text_col(octx *c, const char *s, double x, double y, int align, int col)
{
    int n;

    (void)col;
    if (align == 0)             /* centred in a box 20 wide (FUN_00479c40's x ± 10) */
        n = ob_text(c, s, x - 10.0, y, x + 10.0, y, 0);
    else
        n = ob_cell(c, s, x, y, align);
    c->tcol = 0;
    return n;
}

/* FUN_007400a0: nothing on the plan between the viewpoint and the point hides it.  A non-ground
 * 3-D line hides it when it straddles the sight line, is not wholly behind the viewpoint and
 * crosses the line nearer than the point. */
static int conf_visible(const l3 *a, int n, double px, double py, double X, double Y)
{
    double dx = X - px, dy = Y - py, dist = sqrt(dx * dx + dy * dy), ux, uy;
    int i;

    if (dist < 1e-9)
        return 1;
    ux = dx / dist;
    uy = dy / dist;
    for (i = 0; i < n; i++) {
        const l3 *e = &a[i];
        double ax = e->x0 - px, ay = e->y0 - py, bx = e->x1 - px, by = e->y1 - py;
        double ca, cb, s, ix, iy, along;

        if (e->z0 <= 1e-07 && e->z1 <= 1e-07)
            continue;
        ca = ux * ay - uy * ax;
        cb = ux * by - uy * bx;
        if (ca * cb > 1e-07)
            continue;
        if (ux * ax + uy * ay < 0.0 && ux * bx + uy * by < 0.0)
            continue;
        if (fabs(ca - cb) < 1e-12)
            continue;
        s = ca / (ca - cb);
        ix = ax + s * (bx - ax);
        iy = ay + s * (by - ay);
        along = ux * ix + uy * iy;
        if (along < 0.0 || dist - 1e-07 <= along)
            continue;
        return 0;
    }
    return 1;
}

typedef struct { double x, y, z; } cpt;

/* the corner points of the buildings, as FUN_00734920 collects them: each end of every non-ground
 * line once (the first of equal ones), but not the foot of a line that rises from it; then an
 * exchange sort: higher first, then smaller y, then smaller x */
static int conf_points(const l3 *a, int n, cpt *out, int max)
{
    unsigned char *u0 = (unsigned char *)calloc((size_t)n + 1, 1);
    unsigned char *u1 = (unsigned char *)calloc((size_t)n + 1, 1);
    int i, j, k, m = 0;

    if (!u0 || !u1) {
        free(u0);
        free(u1);
        return 0;
    }
    for (i = 0; i < n && m < max; i++) {
        double z0 = a[i].z0, z1 = a[i].z1;

        if (z0 <= 1e-07 && z1 <= 1e-07)
            continue;
        for (k = 0; k < 2 && m < max; k++) {
            double x = k ? a[i].x1 : a[i].x0, y = k ? a[i].y1 : a[i].y0, z = k ? z1 : z0;
            int foot = 0;

            if (k ? u1[i] : u0[i])
                continue;
            for (j = 0; j < n; j++) {
                if (fabs(a[j].x0 - x) < 1e-07 && fabs(a[j].y0 - y) < 1e-07 && fabs(a[j].z0 - z) < 1e-07) {
                    u0[j] = 1;
                    if (z < 1e-07 && z < a[j].z1 - 1e-07)
                        foot++;
                }
                if (fabs(a[j].x1 - x) < 1e-07 && fabs(a[j].y1 - y) < 1e-07 && fabs(a[j].z1 - z) < 1e-07) {
                    u1[j] = 1;
                    if (z < 1e-07 && z < a[j].z0 - 1e-07)
                        foot += 2;
                }
            }
            if (!foot) {
                out[m].x = x;
                out[m].y = y;
                out[m].z = z;
                m++;
            }
        }
    }
    for (i = 0; i < m; i++) {
        int best = i;

        for (j = i + 1; j < m; j++) {
            const cpt *b = &out[best];

            /* the original updates its "current" copy when it finds a better one, so this is
               a plain selection sort (hk_sa8: the four corners come out front-left,
               front-right, back-left, back-right) */
            if (fabs(b->z - out[j].z) >= 1e-07) {
                if (b->z < out[j].z)
                    best = j;
            } else if (fabs(b->y - out[j].y) >= 1e-07) {
                if (out[j].y < b->y)
                    best = j;
            } else if (out[j].x < b->x && fabs(b->x - out[j].x) > 0.0) {
                best = j;
            }
        }
        if (best != i) {
            cpt tmp = out[i];

            out[i] = out[best];
            out[best] = tmp;
        }
    }
    free(u0);
    free(u1);
    return m;
}

/* the table, the dots on the diagram and the centre mark.  Result < 0 on failure.
 * Layout and numbers read off decomp/res/hk_sa3.jww / hk_sa4.jww (the original's own answer) and
 * FUN_00734920: y runs down from the circle's bottom (R + 1.5 th), columns are at multiples of
 * the character pitch cw from x0c, centred texts are in colour 2 and right-justified ones in 3. */
static int conf_table(octx *c, const l3 *raw, int nraw, double scale)
{
    const hk_sansha_opts *o = c->o;
    double th = c->th, cw = c->tw + c->tsp, sp = c->tsp, cx = c->cx, cy = c->cy, R = c->R;
    double x0c, C[7], y, yt, yh1, xl, xr, ybot, ycur;
    char tb[256], nb[64];
    cpt *pts;
    int np, i, k, rows = 0;
    oo *t;

    y = cy - R - th * 1.5;
    snprintf(tb, sizeof tb, S_SHASHAEI S_ZENSP S_SOKUTEIMEN " = %.3f m", o->t.plane_m);
    if (ob_text_col(c, tb, cx, y, 0, 2) < 0)
        return -1;
    y -= th * 2.0;
    snprintf(tb, sizeof tb, S_CONFNAME S_ZENSP S_RTXT "%.3f" S_ZUSUN, R);
    if (ob_text_col(c, tb, cx, y, 0, 2) < 0)
        return -1;
    y -= th * 1.5;
    if (ob_text_col(c, o->label, cx, y, 0, 2) < 0)
        return -1;
    x0c = cx - (cw * 47.0 - sp) / 4.0 - cw;
    C[1] = cw * 3.0 - sp / 2.0 + x0c;
    C[2] = cw * 7.5 - sp / 2.0 + x0c;
    C[3] = cw * 12.0 - sp / 2.0 + x0c;
    C[4] = cw * 16.5 - sp / 2.0 + x0c;
    C[5] = cw * 21.0 - sp / 2.0 + x0c;
    C[6] = cw * 25.5 - sp / 2.0 + x0c;
    y -= th * 1.5;
    ycur = y;                                   /* the header row (cmd+0x1bd0) */
    if (ob_text_col(c, S_C_POS, C[1] - cw / 2.0, y, -1, 3) < 0 ||
        ob_text_col(c, S_C_PLAN, C[2], y, 0, 2) < 0 ||
        ob_text_col(c, S_C_SKY, C[5] - cw / 2.0, y, -1, 3) < 0)
        return -1;
    y -= th * 1.5;
    if (ob_text_col(c, "No.", C[1] - cw / 2.0, y, -1, 3) < 0 ||
        ob_text_col(c, S_C_DIST, C[2] - cw * 0.75, y, -1, 3) < 0 ||
        ob_text_col(c, S_C_HGT, C[3] - cw * 0.75, y, -1, 3) < 0 ||
        ob_text_col(c, S_C_AZ, C[4] - cw / 2.0, y, -1, 3) < 0 ||
        ob_text_col(c, S_C_ELEV, C[5] - cw / 2.0, y, -1, 3) < 0 ||
        ob_text_col(c, "R*cos(h)", C[6], y, -1, 3) < 0)
        return -1;
    y -= th * 1.2;
    if (ob_text_col(c, S_C_UREAL, C[2], y, -1, 3) < 0 ||
        ob_text_col(c, S_C_UREAL, C[3], y, -1, 3) < 0 ||
        ob_text_col(c, S_C_UDEG, C[4] - cw / 2.0, y, -1, 3) < 0 ||
        ob_text_col(c, S_C_UDEG, C[5] - cw / 2.0, y, -1, 3) < 0 ||
        ob_text_col(c, S_ZUSUN, C[6], y, -1, 3) < 0)
        return -1;

    pts = (cpt *)malloc(2000 * sizeof *pts);
    if (!pts)
        return -1;
    np = conf_points(raw, nraw, pts, 2000);
    for (i = 0; i < np; i++) {
        double dx = pts[i].x - c->px, dy = pts[i].y - c->py, dist = sqrt(dx * dx + dy * dy);
        double az = atan2(dy, dx), h = atan2(pts[i].z, dist), rc = cos(h) * R, X, Y;

        if (az < 0.0)
            az += 2.0 * PI;
        if (!conf_visible(raw, nraw, c->px, c->py, pts[i].x, pts[i].y))
            continue;
        rows++;
        y -= th * 1.5;
        snprintf(nb, sizeof nb, "(%d)", i + 1);
        if (ob_text_col(c, nb, C[1], y, -1, 3) < 0)
            goto fail;
        snprintf(nb, sizeof nb, "%.3f", dist * 0.001 * scale);
        if (ob_text_col(c, nb, C[2], y, -1, 3) < 0)
            goto fail;
        snprintf(nb, sizeof nb, "%.3f", pts[i].z * 0.001 * scale);
        if (ob_text_col(c, nb, C[3], y, -1, 3) < 0)
            goto fail;
        snprintf(nb, sizeof nb, "%.3f", az * 180.0 / PI);
        if (ob_text_col(c, nb, C[4], y, -1, 3) < 0)
            goto fail;
        snprintf(nb, sizeof nb, "%.3f", h * 180.0 / PI);
        if (ob_text_col(c, nb, C[5], y, -1, 3) < 0)
            goto fail;
        snprintf(nb, sizeof nb, "%.3f", rc);
        if (ob_text_col(c, nb, C[6], y, -1, 3) < 0)
            goto fail;
        X = cx + rc * cos(az);
        Y = cy + rc * sin(az);
        t = ob_new(&c->b, JW_TEN);
        if (!t)
            goto fail;
        t->d[0] = X;
        t->d[1] = Y;
        t->color = 3;
        t->ltype = 1;
        snprintf(nb, sizeof nb, "(%d)", i + 1);
        if (ob_text_col(c, nb, X, Y, 0, 2) < 0)
            goto fail;
        (void)k;
    }
    free(pts);
    /* the frame */
    xl = x0c - cw / 4.0;
    xr = C[6] + cw / 4.0;
    yt = ycur + th * 1.25;
    yh1 = ycur - th * 0.25;
    ybot = yh1 - th * 2.7;
    if (ob_aline(c, xl, yt, xr, yt) < 0 || ob_aline(c, C[1] + cw / 4.0, yh1, xr, yh1) < 0 ||
        ob_aline(c, xl, ybot, xr, ybot) < 0)
        return -1;
    for (i = 1; i <= rows; i++) {
        ybot -= th * 1.5;
        if (ob_aline(c, xl, ybot, xr, ybot) < 0)
            return -1;
    }
    if (ob_aline(c, xl, yt, xl, ybot) < 0 || ob_aline(c, C[1] + cw / 4.0, yt, C[1] + cw / 4.0, ybot) < 0 ||
        ob_aline(c, C[2] + cw / 4.0, yh1, C[2] + cw / 4.0, ybot) < 0 ||
        ob_aline(c, C[3] + cw / 4.0, yt, C[3] + cw / 4.0, ybot) < 0 ||
        ob_aline(c, C[4] + cw / 4.0, yh1, C[4] + cw / 4.0, ybot) < 0 ||
        ob_aline(c, C[5] + cw / 4.0, yh1, C[5] + cw / 4.0, ybot) < 0 ||
        ob_aline(c, xr, yt, xr, ybot) < 0)
        return -1;
    /* the centre mark */
    t = ob_new(&c->b, JW_TEN);
    if (!t)
        return -1;
    t->d[0] = cx;
    t->d[1] = cy;
    t->color = 3;
    t->ltype = 1;
    /* the cross only without 三斜計算 (hk_sa3 has it, hk_sa4 does not) */
    if (!o->calc && (ob_aline(c, cx - 1.5, cy, cx + 1.5, cy) < 0 || ob_aline(c, cx, cy - 1.5, cx, cy + 1.5) < 0))
        return -1;
    return rows;
fail:
    free(pts);
    return -1;
}

/* ------------------------------------------------------------------ */
/* the command                                                         */
/* ------------------------------------------------------------------ */
int jw_tenku_sansha_draw_ex(jw_drawing *d, const hk_sansha_opts *o,
                            double px, double py, double cx, double cy, double *pct)
{
    octx c;
    l3buf lb;
    pbuf pb;
    sweep *w = 0;
    int ret = 0, i, rc, nout;
    char tb[1100], nb1[64], nb2[64], nb3[64];
    double cw, ch, ye, Y, X0, sumA = 0.0, sect, diffv, circ, pctv;
    int rows_in_page = 0, k;
    l3 *raw = 0;
    int nraw = 0;

    memset(&c, 0, sizeof c);
    memset(&lb, 0, sizeof lb);
    memset(&pb, 0, sizeof pb);
    c.o = o;
    c.cx = cx;
    c.cy = cy;
    c.px = px;
    c.py = py;
    c.R = o->t.R;
    c.tw = o->tw;
    c.th = o->th;
    c.tsp = o->tsp;
    c.sz = o->t.size_class > 0 ? o->t.size_class : 2;
    cw = o->tw + o->tsp;                  /* [20028] */
    ch = o->th;                           /* [20058] */

    rc = collect3d(d, o, &lb);
    if (rc < 0) { ret = -1; goto out; }
    if (lb.n < 1) { ret = -2; goto out; }
    if (o->conf) {                         /* 建物位置確認表 reads the lines as collected */
        raw = (l3 *)malloc((size_t)lb.n * sizeof(l3));
        if (!raw) { ret = -1; goto out; }
        memcpy(raw, lb.a, (size_t)lb.n * sizeof(l3));
        nraw = lb.n;
    }
    stage_b(lb.a, lb.n, px, py);
    stage_b3(lb.a, lb.n, px, py, write_scale(d));
    if (stage_c(&c, lb.a, lb.n, &pb) < 0) { ret = -1; goto out; }

    /* the circle, the rings, the point and its name */
    if (ob_circle(&c, cx, cy, c.R, o->point_color, 1) < 0) { ret = -1; goto out; }
    if (o->t.interval >= 1.0)
        rings(&c);
    if (o->name[0]) {
        oo *t = ob_new(&c.b, JW_TEN);

        if (!t) { ret = -1; goto out; }
        t->d[0] = px;
        t->d[1] = py;
        t->color = o->point_color;
        t->ltype = 1;
        if (ob_text(&c, o->name, px, py, px + 100.0, py, 2) < 0) { ret = -1; goto out; }
    }

    if (o->conf && conf_table(&c, raw, nraw, write_scale(d)) < 0) { ret = -1; goto out; }
    if (!o->calc)
        goto pieces;                   /* 三斜計算 が切: 円と 投影の線だけ（原典 hk_sa1） */
    w = (sweep *)calloc(1, sizeof *w);
    if (!w) { ret = -1; goto out; }
    w->c = &c;
    w->pc = pb.a;
    w->npc = pb.n;
    w->maxdiv_rad = o->maxdiv * PI / 180.0;
    w->dt = 0.1 / o->maxdiv;
    w->cw = cw;
    w->ch = ch;
    w->R = c.R;
    rc = do_sweep(w);
    if (rc < 0) { ret = rc == -3 ? -3 : -1; goto out; }

    /* header texts */
    ye = cy + ch * 37.5;
    if (w->cnt < 50)
        ye -= (double)(50 - w->cnt) * ch * 0.75;
    X0 = cx + c.R + cw * 2.0;
    Y = ye + ch * 2.0;
    snprintf(tb, sizeof tb, "%s" S_SANSHA S_ZENSP S_ZENSP " " S_MAXDIV " = %g" S_DEG, o->label, o->maxdiv);
    ob_cell(&c, tb, X0, Y, 2);
    Y += ch * 1.5;
    snprintf(tb, sizeof tb, S_RTXT "%.3f" S_ZUSUN, c.R);
    ob_cell(&c, tb, X0, Y, 2);
    Y += ch * 1.5;
    snprintf(tb, sizeof tb, S_SHASHAEI S_ZENSP S_SOKUTEIMEN " = %.3f m", o->t.plane_m);
    ob_cell(&c, tb, X0, Y, 2);
    if (o->name[0]) {
        Y += ch * 1.5;
        if (o->t.interval >= 1.0)
            snprintf(tb, sizeof tb, S_SOKUTENN " %s" S_ZENSP S_MEMORI "%g" S_DEG, o->name, o->t.interval);
        else
            snprintf(tb, sizeof tb, S_SOKUTENN " %s", o->name);
        ob_cell(&c, tb, X0, Y, 2);
    }

    /* the table */
    Y = ye;
    for (k = 1; k <= w->cnt; k++) {
        double xx, bv, hv, av;

        if (k % 50 == 1) {
            if (k != 1) {
                table_frame(&c, rows_in_page, 0, X0, ye, cw, ch);
                Y = ye;
                X0 = cw * 30.0 + X0;
            }
            rows_in_page = 0;
            xx = X0 - cw * 0.5;
            ob_cell(&c, S_COL_NO, xx, Y, 2);
            xx = cw * 9.5 + xx;
            ob_cell(&c, S_COL_BASE, xx, Y, -1);
            xx = cw * 7.0 + xx;
            ob_cell(&c, S_COL_H, xx, Y, -1);
            xx = cw * 8.0 + xx;
            ob_cell(&c, S_COL_AREA, xx, Y, -1);
        }
        rows_in_page++;
        xx = X0;
        Y -= ch * 1.5;
        snprintf(tb, sizeof tb, "%s%d%s", o->br_open, k, o->br_close);
        ob_cell(&c, tb, cw * 2.5 + xx, Y, -1);
        xx = cw * 9.0 + xx;
        bv = fabs(w->base[k]);
        hv = fabs(w->hgt[k]);
        if (o->style == HK_SANSHA_SAMPLE) {
            snprintf(nb2, sizeof nb2, "%9.5f", bv);
            ob_cell(&c, nb2, xx, Y, -1);
            xx = cw * 7.0 + xx;
            snprintf(nb3, sizeof nb3, "%9.5f", hv);
            ob_cell(&c, nb3, xx, Y, -1);
            bv = reparse(nb2);
            hv = reparse(nb3);
            av = 0.5 * bv * hv;
        } else {
            bv = q3(o, bv);
            snprintf(nb2, sizeof nb2, "%9.3f", bv);
            ob_cell(&c, nb2, xx, Y, -1);
            bv = reparse(nb2);
            xx = cw * 7.0 + xx;
            hv = q3(o, hv);
            snprintf(nb3, sizeof nb3, "%9.3f", hv);
            ob_cell(&c, nb3, xx, Y, -1);
            hv = reparse(nb3);
            av = q3(o, 0.5 * bv * hv);
        }
        xx = cw * 8.0 + xx;
        snprintf(nb1, sizeof nb1, "%8.3f", av);
        ob_cell(&c, nb1, xx, Y, -1);
        av = reparse(nb1);
        sumA += av;
    }
    table_frame(&c, rows_in_page, 1, X0, ye, cw, ch);

    /* summary */
    {
        double xl = cw * 16.0 + X0, xv;
        const char *np = o->name[0] ? o->name : "";

        Y -= ch * 1.5;
        ob_cell(&c, S_SUM, xl, Y, -1);
        xv = cw * 8.0 + xl;
        snprintf(nb1, sizeof nb1, "%7.3f", sumA);
        ob_cell(&c, nb1, xv, Y, -1);
        if (o->style == HK_SANSHA_SAMPLE)
            sect = c.R * c.R * w->total / 2.0;
        else
            sect = q3(o, (c.R * c.R * w->total) / 2.0);
        Y -= ch * 2.0;
        snprintf(tb, sizeof tb, S_SECTOR S_LP S_ANGLE " = %7.3f" S_DEGH S_RP "^1", w->total * 180.0 / PI);
        ob_cell(&c, tb, xl, Y, -1);
        snprintf(nb1, sizeof nb1, "%7.3f", sect);
        ob_cell(&c, nb1, cw * 8.0 + xl, Y, -1);
        sect = reparse(nb1);
        diffv = sect - sumA;
        Y -= ch * 1.5;
        ob_cell(&c, S_SECTOR " - " S_SUM " = " S_HCIRC "^8", xl, Y, -1);
        snprintf(nb2, sizeof nb2, "%.3f", diffv);             /* nb2 = the difference's text */
        ob_cell(&c, nb2, cw * 8.0 + xl, Y, -1);
        diffv = reparse(nb2);
        circ = c.R * c.R * PI;
        if (o->style != HK_SANSHA_SAMPLE)
            circ = q3(o, circ);
        Y -= ch * 1.5;
        snprintf(tb, sizeof tb, "%s%s" S_CIRCAREA, np, np[0] ? S_ZENSP : "");
        ob_cell(&c, tb, xl, Y, -1);
        snprintf(nb1, sizeof nb1, "%.3f", circ);              /* nb1 = the circle's text */
        ob_cell(&c, nb1, cw * 8.0 + xl, Y, -1);
        circ = reparse(nb1);
        Y -= ch * 1.5;
        if (o->style == HK_SANSHA_SAMPLE) {
            pctv = ((circ - diffv) * 100.0) / circ;
            snprintf(nb3, sizeof nb3, "%.2f", pctv);          /* nb3 = the percentage's text */
        } else {
            pctv = q3(o, ((circ - diffv) * 100.0) / circ);
            snprintf(nb3, sizeof nb3, "%.3f", pctv);
        }
        snprintf(tb, sizeof tb, "(%s - %s) / %s * 100 = %s", nb1, nb2, nb1, nb3);
        ob_cell(&c, tb, X0, Y, 2);
        if (o->style != HK_SANSHA_SAMPLE) {
            Y -= ch * 1.5;
            snprintf(tb, sizeof tb, S_ZENSP "%s", o->cut_down == 0 ? S_ROUNDUP S_ARROWUP : S_ROUNDDN S_ARROWDN);
            ob_cell(&c, tb, X0, Y, 2);
        }
        Y -= ch * (o->style == HK_SANSHA_SAMPLE ? 2.0 : 1.5);   /* the sample's older version: 2.0 */
        snprintf(tb, sizeof tb, "%.47s" S_ZENSP S_SANSHA S_ZENSP S_ZENSP " " S_SKYRATE " = %s %%", o->label, nb3);
        ob_cell(&c, tb, X0, Y, 2);
        if (pct)
            *pct = reparse(nb3);
    }

    /* the skyline pieces, last (non-ground ones, in creation order) */
pieces:
    for (i = 0; i < pb.n; i++) {
        const piece *p = &pb.a[i];
        oo *t;

        if (p->ground)
            continue;
        if (fabs(p->x1 - p->x0) < 1e-07 && fabs(p->y1 - p->y0) < 1e-07)
            continue;
        t = ob_new(&c.b, JW_SEN);
        if (!t) { ret = -1; goto out; }
        t->d[0] = p->x0 + cx;
        t->d[1] = p->y0 + cy;
        t->d[2] = p->x1 + cx;
        t->d[3] = p->y1 + cy;
        t->color = p->color;
        t->ltype = p->ltype;
    }

    /* into the drawing */
    nout = 0;
    for (i = 0; i < c.b.n; i++) {
        const oo *s = &c.b.a[i];
        jw_obj *t = jw_add(d, s->cls);

        if (!t) { ret = -1; goto out; }
        memcpy(t->d, s->d, sizeof t->d);
        t->color = (unsigned short)s->color;
        t->ltype = (unsigned char)s->ltype;
        t->flags = (unsigned short)s->flags;
        t->width = 0;
        t->n = s->n;
        if (s->cls == JW_MOJI) {
            t->text = jw_add_str(d, s->text);
            t->face = jw_add_str(d, S_FACE);
        }
        nout++;
    }
    ret = nout;
out:
    free(raw);
    free(c.b.a);
    free(lb.a);
    free(pb.a);
    if (w) {
        free(w->bstart);
        free(w->bidx);
    }
    free(w);
    return ret;
}

int jw_tenku_sansha_draw(jw_drawing *d, const hk_tenku_opts *t,
                         double px, double py, double cx, double cy, double *pct)
{
    hk_sansha_opts o;

    hk_sansha_opts_default(&o);
    o.t = *t;
    if (o.t.show_point)
        snprintf(o.name, sizeof o.name, "No.%d", o.t.number);
    else
        o.name[0] = 0;
    return jw_tenku_sansha_draw_ex(d, &o, px, py, cx, cy, pct);
}
