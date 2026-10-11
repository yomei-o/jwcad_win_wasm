/* tenku.c -- see tenku.h.
 *
 * What was learned from the answer decomp/res/hk_s1.jww (box 122.449 mm square,
 * height text 10 m, scale 1/100, point 61.2 mm south of the box, R = 25):
 *   - circle (cls ENKO, col2 lt1, n=1 = whole circle) first;
 *   - then, per 3-D line in drawing order, the line's projection as a polyline
 *     of n = int(azimuth span in degrees)+1 equal-length (in plan) pieces,
 *     r = R cos(el), traversed in the direction of INCREASING azimuth;
 *     after the polyline, a single piece "ground circle -> top" (r = R to
 *     R cos(el)) for each end of the line that has not been done before
 *     (first end, then second end);
 *   - last the one text "正射影 　測定面高さ = 0.000 m" (col1, size class,
 *     centred on the circle, 3.75 mm below it).
 * Everything else (ring/radial scale, point mark, "測定点 No.n", hatch, the
 * 天空率 text) is taken from the first diagram of orig/天空率表.jww.
 */
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "tenku.h"

#define PI 3.14159265358979323846

/* CP932 literals; a hex escape never runs into a following hex digit because
 * every literal is cut with a quote there. */
#define S_SHASHAEI   "\x90\xb3\x8e\xcb\x89\x65"            /* 正射影 */
#define S_TOUKYORI   "\x93\x99\x8b\x97\x97\xa3\x8e\xcb\x89\x65" /* 等距離射影 */
#define S_SOKUTEI    "\x91\xaa\x92\xe8"                      /* 測定 */
#define S_SOKUTEIMEN "\x91\xaa\x92\xe8\x96\xca\x8d\x82\x82\xb3" /* 測定面高さ */
#define S_SOKUTENN   "\x91\xaa\x92\xe8\x93\x5f"              /* 測定点 */
#define S_MEMORI     "\x96\xda\x90\xb7\x8a\xd4\x8a\x75"      /* 目盛間隔 */
#define S_TENKURITSU "\x93\x56\x8b\xf3\x97\xa6"              /* 天空率 */
#define S_ZEN        "\x81\x40"                              /* U+3000 */
#define S_DEG        "\x81\x8b"                              /* ° */
#define S_FACE       "\x82\x6c\x82\x72\x20\x83\x53\x83\x56\x83\x62\x83\x4e"

void hk_tenku_opts_default(hk_tenku_opts *o)
{
    memset(o, 0, sizeof *o);
    o->R = 25.0;
    o->number = 1;
    o->show_plane = 1;
    o->size_class = 2;
}

/* ------------------------------------------------------------------ */
/* collecting the wire frame                                           */
/* ------------------------------------------------------------------ */
int jw_tenku_collect(const jw_drawing *d, double plane_m, hk_edge3 *e, int max)
{
    int i, j, n = 0;
    double scale0 = -1.0;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *l = &d->obj[i];
        int end[2], k, found;
        double h[2], z[2], base, sc;

        if (l->cls != JW_SEN || l->color == 9 || l->ltype == 9)
            continue;
        if (l->lgroup > 15 || l->layer > 15)
            continue;
        if (d->group[l->lgroup].layer[l->layer].state == 0 ||
            d->group[l->lgroup].state == 0)
            continue;
        found = 0;
        for (k = 0; k < 2; k++) {
            double ex = l->d[2 * k], ey = l->d[2 * k + 1];

            end[k] = -1;
            for (j = 0; j < d->ndrawn; j++) {
                const jw_obj *t = &d->obj[j];
                double v1, v2;
                char buf[256];
                const char *s;

                if (t->cls != JW_MOJI || !(t->flags & 0x80) || t->text < 0)
                    continue;
                if (t->layer != l->layer || t->lgroup != l->lgroup)
                    continue;
                if (fabs(t->d[0] - ex) > 0.01 || fabs(t->d[1] - ey) > 0.01)
                    continue;
                s = jw_str(d, t->text);
                strncpy(buf, s, sizeof buf - 1);
                buf[sizeof buf - 1] = 0;
                if (hk_parse_height_text(buf, &v1, &v2) < 1)
                    continue;
                end[k] = j;
                h[k] = v1;
                break;
            }
            if (end[k] >= 0)
                found++;
        }
        if (found < 2)
            continue;
        sc = d->group[l->lgroup].scale;
        if (sc <= 0.0)
            sc = 1.0;
        if (scale0 < 0.0)
            scale0 = sc;
        else if (fabs(scale0 - sc) > 1e-9)
            return -1;
        base = hk_level_from_name(jw_str(d, d->group[l->lgroup].name)) +
               hk_level_from_name(jw_str(d, d->group[l->lgroup].layer_name[l->layer]));
        for (k = 0; k < 2; k++)
            z[k] = hk_vertex_z_mm(h[k], base, plane_m, sc);
        if (n >= max)
            break;
        e[n].x0 = l->d[0];
        e[n].y0 = l->d[1];
        e[n].z0 = z[0];
        e[n].x1 = l->d[2];
        e[n].y1 = l->d[3];
        e[n].z1 = z[1];
        n++;
    }
    return n;
}

/* ------------------------------------------------------------------ */
/* object makers                                                       */
/* ------------------------------------------------------------------ */
static int style_n(const jw_drawing *d, double cw, double ch)
{
    int i;

    for (i = 0; i < 10; i++)
        if (d->style[i].w == cw && d->style[i].h == ch && d->style[i].sp == 0.0)
            return i + 1;
    return 0;
}

static jw_obj *add_line(jw_drawing *d, double x0, double y0, double x1, double y1,
                        int col, int lt, int fl)
{
    jw_obj *o = jw_add(d, JW_SEN);

    if (!o)
        return 0;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    if (col) {
        o->color = (unsigned short)col;
        o->ltype = (unsigned char)lt;
    }
    o->flags = (unsigned short)fl;
    return o;
}

static jw_obj *add_circle(jw_drawing *d, double cx, double cy, double r, int col, int lt)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    if (!o)
        return 0;
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = 0.0;
    o->d[4] = 6.283185307179586;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    o->d[7] = 0.0;
    o->n = 1;
    if (col) {
        o->color = (unsigned short)col;
        o->ltype = (unsigned char)lt;
    }
    return o;
}

/* width of a CP932 string in half-width units */
static int halves(const char *s)
{
    int n = 0;

    while (*s) {
        unsigned char c = (unsigned char)*s;

        if ((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc)) {
            n += 2;
            s += s[1] ? 2 : 1;
        } else {
            n++;
            s++;
        }
    }
    return n;
}

/* a text starting at (x,y) running right; centred on cx when centred */
static jw_obj *add_text(jw_drawing *d, const char *s, double x, double y, int centred,
                        double size, int col, int lt)
{
    jw_obj *o = jw_add(d, JW_MOJI);
    double w = halves(s) * size / 2.0;

    if (!o)
        return 0;
    if (centred)
        x -= w / 2.0;
    o->color = (unsigned short)col;
    o->ltype = (unsigned char)lt;
    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = x + w;
    o->d[3] = y;
    o->d[4] = size;
    o->d[5] = size;
    o->d[6] = 0.0;
    o->d[7] = 0.0;
    o->n = style_n(d, size, size);
    o->text = jw_add_str(d, s);
    o->face = jw_add_str(d, S_FACE);
    return o;
}

/* ------------------------------------------------------------------ */
static void proj(const hk_tenku_opts *o, double px, double py, double cx, double cy,
                 double x, double y, double h, double *ox, double *oy)
{
    hk_tenkuu_project(px, py, x, y, h, o->R, o->equidist, o->mirror, o->mirror_off, ox, oy);
    *ox += cx;
    *oy += cy;
}

static double radius_of(const hk_tenku_opts *o, double el)
{
    return o->equidist ? o->R * (1.0 - el / (PI / 2.0)) : o->R * cos(el);
}

static double az_of(double px, double py, double x, double y)
{
    return atan2(y - py, x - px);
}

static int same_xy(const hk_edge3 *a, int ea, const hk_edge3 *b, int eb)
{
    double ax = ea ? a->x1 : a->x0, ay = ea ? a->y1 : a->y0;
    double bx = eb ? b->x1 : b->x0, by = eb ? b->y1 : b->y0;

    return fabs(ax - bx) < 0.01 && fabs(ay - by) < 0.01;
}

/* highest elevation along the ray of azimuth az.  Like hk_skyline_el but an
 * edge covers [0,1) of its length, so that a vertex shared by two edges is
 * counted once (the original's hatch at az 90 deg of 天空率表 No.10 shows the
 * end u = 1 does not count). */
static double ray_el(const hk_edge3 *e, int n, double px, double py, double az)
{
    double dx = cos(az), dy = sin(az), best = -1.0;
    int i;

    for (i = 0; i < n; i++) {
        double ex = e[i].x1 - e[i].x0, ey = e[i].y1 - e[i].y0;
        double den = dx * ey - dy * ex, s, u, z, el;

        if (fabs(den) < 1e-12)
            continue;
        s = ((e[i].x0 - px) * ey - (e[i].y0 - py) * ex) / den;
        u = ((e[i].x0 - px) * dy - (e[i].y0 - py) * dx) / den;
        if (s <= 0 || u < 0 || u >= 1.0)
            continue;
        z = e[i].z0 + (e[i].z1 - e[i].z0) * u;
        if (z < 0)
            z = 0;
        el = atan2(z, s);
        if (el > best)
            best = el;
    }
    return best;
}

/* the skyline: every edge as a polyline, then the verticals */
static int skyline(jw_drawing *d, const hk_tenku_opts *o, const hk_edge3 *e, int n,
                   double px, double py, double cx, double cy)
{
    int i, k, added = 0;

    for (i = 0; i < n; i++) {
        double x0 = e[i].x0, y0 = e[i].y0, z0 = e[i].z0;
        double x1 = e[i].x1, y1 = e[i].y1, z1 = e[i].z1;
        double cross = (x0 - px) * (y1 - py) - (y0 - py) * (x1 - px);

        if (z0 <= 1e-7 && z1 <= 1e-7)
            goto verticals;                 /* lies on the ground circle */
        if (cross <= 0.0) {                 /* azimuth must increase; a line pointing
                                               straight at the point runs far -> near */
            double t;

            t = x0; x0 = x1; x1 = t;
            t = y0; y0 = y1; y1 = t;
            t = z0; z0 = z1; z1 = t;
        }
        {
            double a0 = az_of(px, py, x0, y0), a1 = az_of(px, py, x1, y1);
            double span = a1 - a0, ax, ay;
            int seg, s;

            while (span > PI) span -= 2 * PI;
            while (span < -PI) span += 2 * PI;
            span = fabs(span) * 180.0 / PI;
            seg = (int)(span + 1e-6) + 1;
            proj(o, px, py, cx, cy, x0, y0, z0, &ax, &ay);
            for (s = 1; s <= seg; s++) {
                double t = (double)s / (double)seg, bx, by;

                proj(o, px, py, cx, cy, x0 + (x1 - x0) * t, y0 + (y1 - y0) * t,
                     z0 + (z1 - z0) * t, &bx, &by);
                if (!add_line(d, ax, ay, bx, by, 0, 0, 0))
                    return -1;
                added++;
                ax = bx;
                ay = by;
            }
        }
verticals:
        for (k = 0; k < 2; k++) {
            double vx = k ? e[i].x1 : e[i].x0, vy = k ? e[i].y1 : e[i].y0;
            double vz = k ? e[i].z1 : e[i].z0, gx, gy, tx, ty;
            int j, e2, seen = 0;

            if (vz <= 1e-7)
                continue;
            for (j = 0; j <= i && !seen; j++)
                for (e2 = 0; e2 < 2; e2++) {
                    if (j == i && (e2 >= k))
                        break;
                    if (same_xy(&e[i], k, &e[j], e2))
                        seen = 1;
                }
            if (seen)
                continue;
            proj(o, px, py, cx, cy, vx, vy, 0.0, &gx, &gy);
            proj(o, px, py, cx, cy, vx, vy, vz, &tx, &ty);
            if (!add_line(d, gx, gy, tx, ty, 0, 0, 0))
                return -1;
            added++;
        }
    }
    return added;
}

int jw_tenku_draw_edges(jw_drawing *d, const hk_tenku_opts *o,
                        const hk_edge3 *e, int n,
                        double px, double py, double cx, double cy, double *pct)
{
    int start = d->ndrawn, i, slot = 1, r;
    double size = o->size_class == 2 || o->size_class < 1 ? 2.5 : 2.5;
    double ty = cy - o->R - 3.75;
    char buf[160];
    double v = 100.0;

    if (o->calc || pct) {
        v = hk_sky_ratio(e, n, px, py, o->precise ? 360000 : 36000, o->equidist);
        v = hk_sky_round(v, o->precise);
        if (pct)
            *pct = v;
    }
    add_circle(d, cx, cy, o->R, 0, 0);
    if (o->interval > 0.0) {
        double a;
        int k;

        for (a = o->interval; a < 90.0 - 1e-9; a += o->interval) {
            int major = fabs(fmod(a + 1e-9, 30.0)) < 2e-9;

            add_circle(d, cx, cy, radius_of(o, a * PI / 180.0), 1, major ? 1 : 4);
        }
        for (k = 0; k * o->interval < 360.0 - 1e-9; k++) {
            double ang = k * o->interval, rad = ang * PI / 180.0;
            int major = fabs(fmod(ang + 1e-9, 30.0)) < 2e-9;

            add_line(d, cx, cy, cx + o->R * cos(rad), cy + o->R * sin(rad), 1, major ? 1 : 4, 0);
        }
    }
    if (o->show_point) {
        jw_obj *t = jw_add(d, JW_TEN);

        if (t) {
            t->d[0] = px;
            t->d[1] = py;
        }
        snprintf(buf, sizeof buf, "No.%d", o->number);
        add_text(d, buf, px, py, 0, size, 1, 1);
    }
    if (o->calc) {
        /* [sample] texts, then the hatch, then the 天空率 text, then the skyline */
        if (o->show_point) {
            if (o->interval > 0.0)
                snprintf(buf, sizeof buf, S_SOKUTENN " No.%d " S_ZEN S_MEMORI " %g" S_DEG,
                         o->number, o->interval);
            else
                snprintf(buf, sizeof buf, S_SOKUTENN " No.%d", o->number);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        if (o->show_plane) {
            snprintf(buf, sizeof buf, "%s " S_ZEN S_SOKUTEIMEN " = %.3f m",
                     o->equidist ? S_TOUKYORI : S_SHASHAEI, o->plane_m);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        for (i = 0; i < 180; i++) {
            double az = i * 2.0 * PI / 180.0, el = ray_el(e, n, px, py, az), rr;

            if (el <= 0.0)
                continue;
            rr = radius_of(o, el);
            add_line(d, cx + rr * cos(az), cy + rr * sin(az),
                     cx + o->R * cos(az), cy + o->R * sin(az), 1, 1, 0x20);
        }
        snprintf(buf, sizeof buf, S_TENKURITSU " = %.*f %%", o->precise ? 3 : 2, v);
        add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
        r = skyline(d, o, e, n, px, py, cx, cy);
        if (r < 0)
            return -1;
    } else {
        /* [hk_s1] circle, skyline, then the texts */
        r = skyline(d, o, e, n, px, py, cx, cy);
        if (r < 0)
            return -1;
        if (o->show_point) {
            if (o->interval > 0.0)
                snprintf(buf, sizeof buf, S_SOKUTENN " No.%d " S_ZEN S_MEMORI " %g" S_DEG,
                         o->number, o->interval);
            else
                snprintf(buf, sizeof buf, S_SOKUTENN " No.%d", o->number);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        if (o->show_plane) {
            snprintf(buf, sizeof buf, "%s " S_ZEN S_SOKUTEIMEN " = %.3f m",
                     o->equidist ? S_TOUKYORI : S_SHASHAEI, o->plane_m);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
    }
    return d->ndrawn - start;
}

int jw_tenku_draw(jw_drawing *d, const hk_tenku_opts *o,
                  double px, double py, double cx, double cy, double *pct)
{
    hk_edge3 e[1000];
    int n = jw_tenku_collect(d, o->plane_m, e, 1000);

    if (n < 1)
        return n < 0 ? -1 : -2;
    return jw_tenku_draw_edges(d, o, e, n, px, py, cx, cy, pct);
}
