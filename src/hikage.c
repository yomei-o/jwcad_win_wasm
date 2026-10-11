/* hikage_core.c -- see hikage_core.h for the provenance tags. */
#include "hikage.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.141592653589793

/* ------------------------------------------------------------------ */
/* 1. sun                                                              */
/* ------------------------------------------------------------------ */

void hk_sun_init(hk_sun *s, double lat_deg, double dec_deg)
{
    /* [D 0x00542070]  cos = FUN_008f8eb0, sin = FUN_008f8f00 */
    double lat = lat_deg * 0.0174533, dec = dec_deg * 0.0174533;
    double cphi = cos(lat), sphi = sin(lat), cdel = cos(dec), sdel = sin(dec);
    s->c3 = cdel;                 /* *param_3 */
    s->c4 = cphi * cdel;          /* *param_4 */
    s->c5 = sphi / cphi;          /* *param_5 = tan(lat) */
    s->c6 = sdel / cphi;          /* *param_6 */
    s->c7 = sphi * sdel;          /* *param_7 */
}

double hk_sun_sin_alt(const hk_sun *s, int t_sec)
{
    return cos((double)t_sec * 7.272205e-05) * s->c4 + s->c7;
}

int hk_sun_shadow(const hk_sun *s, int t_sec, double *x, double *y)
{
    /* [D 0x00542180] */
    double w = (double)t_sec * 7.272205e-05;
    double sa = cos(w) * s->c4 + s->c7;
    if (fabs(sa) < 1e-07) { *x = 0.0; *y = 0.0; return 1; }
    {
        double k = 1.0 / sa;
        *x = sin(w) * s->c3 * k;
        *y = s->c5 - s->c6 * k;
    }
    return 1;
}

int hk_wall_sun_side(double lat_deg, double dec_deg, int t_sec, double wall_dx, double wall_dy,
                     double *mult, double *sa, double *ca)
{
    double lat = lat_deg * PI / 180.0, dec = dec_deg * PI / 180.0;
    double sl = sin(lat), cl = cos(lat), sd = sin(dec), cd = cos(dec);
    double w = (double)t_sec * 7.272205e-05;
    double s_alt = sl * sd + cl * cd * cos(w);
    double c_alt = sqrt(1.0 - s_alt * s_alt), v;
    *mult = 1.0 / (s_alt / c_alt);
    *sa = sin(w) * cd / c_alt;
    *ca = (s_alt * sl - sd) / (c_alt * cl);
    v = wall_dx * *ca * 100.0 - wall_dy * *sa * 100.0;
    return v < 0.0 ? -1 : (v <= 0.001 ? 0 : 1);
}

double hk_shadow_mult(double x, double y) { return sqrt(x * x + y * y); }

double hk_shadow_az_deg(double x, double y)
{
    /* [D 0x00694840] FUN_008f8d00(-x, y): atan2(-x, y) */
    return atan2(-x, y) * 180.0 / PI;
}

void hk_fmt_angle(char *out, int outsz, int flip, int mode, double v)
{
    /* [D 0x00694520] */
    double a = v <= 0.0 ? -v : v;
    int sign;
    if (!flip) sign = v < 0.0 ? -1 : 1;
    else       sign = v > 0.0 ? -1 : 1;
    if (mode == 0) {
        int m = (int)(a * 60.0 + 0.5);
        snprintf(out, (size_t)outsz, "%c%d\xEF\xBE\x9F%02d'", sign < 1 ? '-' : ' ', m / 60, m % 60);
    } else if (mode == 1) {
        int s = (int)(a * 3600.0 + 0.5);
        int r = s % 3600;
        snprintf(out, (size_t)outsz, "%c%d\xEF\xBE\x9F%02d'%02d\"", sign < 1 ? '-' : ' ', s / 3600, r / 60, r % 60);
    } else {
        snprintf(out, (size_t)outsz, "%c%.2lf\xEF\xBE\x9F", sign < 1 ? '-' : ' ', a);
    }
}

void hk_fmt_hour_label(char *out, int outsz, double hour)
{
    if ((int)(hour * 1000.0) % 10 > 0)      snprintf(out, (size_t)outsz, "%.3lf", hour);
    else if ((int)(hour * 100.0) % 10 > 0)  snprintf(out, (size_t)outsz, "%.2lf", hour);
    else                                    snprintf(out, (size_t)outsz, "%.1lf", hour);
}

/* ------------------------------------------------------------------ */
/* 2. texts                                                            */
/* ------------------------------------------------------------------ */

int hk_parse_height_text(const char *s, double *h1, double *h2)
{
    char buf[256];
    int j = 0;
    char *e;
    *h1 = 0.0;
    *h2 = -9.0;
    for (; *s && j < 255; s++)
        if (*s != ' ') buf[j++] = *s;
    buf[j] = 0;
    if (j == 0) return -1;
    *h1 = strtod(buf, &e);
    if (e == buf) { *h1 = 0.0; return 0; }
    if (*e != ',') return 1;
    {
        char *e2;
        double v = strtod(e + 1, &e2);
        if (e2 == e + 1) return 1;
        *h2 = v;
    }
    return 2;
}

double hk_level_from_name(const char *name)
{
    if (strlen(name) > 3 && name[0] == '#' && name[1] == 'l' && name[2] == 'v')
        return strtod(name + 3, NULL);
    return 0.0;
}

double hk_vertex_z_mm(double h, double base_m, double plane_m, double scale_den)
{
    double z = ((h <= 0.0 ? -h : h) + base_m - plane_m) * 1000.0 / scale_den;
    return z > 0.0 ? z : 0.0;
}

double hk_north_deg(double ex, double ey, double ox, double oy)
{
    double a = atan2(oy - ey, ox - ex) * 180.0 / PI + 90.0;
    if (a > 180.0) a -= 360.0;
    if (a <= -180.0) a += 360.0;
    return a;
}

void hk_rot(double x, double y, double deg, double *ox, double *oy)
{
    double a = deg * PI / 180.0, c = cos(a), s = sin(a);
    double rx = x * c - y * s, ry = x * s + y * c;
    *ox = rx; *oy = ry;
}

/* ------------------------------------------------------------------ */
/* 3. shadow polygons                                                  */
/* ------------------------------------------------------------------ */

int hk_build_quads(const hk_edge *e, int n, double sx, double sy, hk_quad *q)
{
    int i;
    for (i = 0; i < n; i++) {
        q[i].p[0] = e[i].a;
        q[i].p[1] = e[i].b;
        q[i].p[2].x = e[i].b.x + e[i].zb_mm * sx;
        q[i].p[2].y = e[i].b.y + e[i].zb_mm * sy;
        q[i].p[3].x = e[i].a.x + e[i].za_mm * sx;
        q[i].p[3].y = e[i].a.y + e[i].za_mm * sy;
    }
    return n;
}

static int in_poly4(const hk_quad *q, double x, double y)
{
    int i, c = 0;
    for (i = 0; i < 4; i++) {
        const hk_pt *p1 = &q->p[i], *p2 = &q->p[(i + 1) & 3];
        if ((p1->y > y) != (p2->y > y)) {
            double xi = p1->x + (y - p1->y) * (p2->x - p1->x) / (p2->y - p1->y);
            if (xi > x) c = !c;
        }
    }
    return c;
}

int hk_point_in_quads(const hk_quad *q, int n, double px, double py)
{
    int i;
    for (i = 0; i < n; i++)
        if (in_poly4(&q[i], px, py)) return 1;
    return 0;
}

#define MAXPIECE 20000

/* parameter of the intersection of p->q with r->s, or -1 */
static double seg_t(hk_pt p, hk_pt q, hk_pt r, hk_pt s)
{
    double d1x = q.x - p.x, d1y = q.y - p.y, d2x = s.x - r.x, d2y = s.y - r.y;
    double den = d1x * d2y - d1y * d2x, t, u;
    if (fabs(den) < 1e-12) return -1.0;
    t = ((r.x - p.x) * d2y - (r.y - p.y) * d2x) / den;
    u = ((r.x - p.x) * d1y - (r.y - p.y) * d1x) / den;
    if (t >= -1e-9 && t <= 1 + 1e-9 && u >= -1e-9 && u <= 1 + 1e-9)
        return t < 0 ? 0 : t > 1 ? 1 : t;
    return -1.0;
}

static double dist(hk_pt a, hk_pt b) { return hypot(a.x - b.x, a.y - b.y); }

static int cmp_d(const void *a, const void *b)
{
    double x = *(const double *)a, y = *(const double *)b;
    return x < y ? -1 : x > y;
}

static double dist_line(hk_pt p, hk_pt a, hk_pt b)
{
    double ex = b.x - a.x, ey = b.y - a.y, l = hypot(ex, ey);
    if (l < 1e-12) return dist(p, a);
    return fabs((p.x - a.x) * ey - (p.y - a.y) * ex) / l;
}

int hk_outline(const hk_edge *e, int n, double sx, double sy,
               hk_seg *out, int *chain_start, int maxout)
{
    hk_quad *q = (hk_quad *)malloc(sizeof(hk_quad) * (size_t)(n > 0 ? n : 1));
    hk_seg *pc = (hk_seg *)malloc(sizeof(hk_seg) * MAXPIECE);
    int np = 0, i, j, k, m, changed;
    double *ts = (double *)malloc(sizeof(double) * (size_t)(4 * n + 8));
    if (!q || !pc || !ts) { free(q); free(pc); free(ts); return 0; }
    hk_build_quads(e, n, sx, sy, q);

    /* 1. split every quad side at every crossing and keep the pieces with exactly
     *    one side inside the union (= boundary of the union) */
    for (i = 0; i < n; i++)
        for (k = 0; k < 4; k++) {
            hk_pt a = q[i].p[k], b = q[i].p[(k + 1) & 3];
            int nt = 2;
            if (dist(a, b) < 1e-9) continue;
            ts[0] = 0.0; ts[1] = 1.0;
            for (j = 0; j < n; j++)
                for (m = 0; m < 4; m++) {
                    double t = seg_t(a, b, q[j].p[m], q[j].p[(m + 1) & 3]);
                    if (t > 1e-9 && t < 1 - 1e-9 && nt < 4 * n + 6) ts[nt++] = t;
                }
            qsort(ts, (size_t)nt, sizeof(double), cmp_d);
            for (m = 0; m + 1 < nt; m++) {
                hk_pt p, r, mid;
                double L, nx, ny, ee = 1e-5;
                int i1, i2;
                p.x = a.x + (b.x - a.x) * ts[m];     p.y = a.y + (b.y - a.y) * ts[m];
                r.x = a.x + (b.x - a.x) * ts[m + 1]; r.y = a.y + (b.y - a.y) * ts[m + 1];
                L = dist(p, r);
                if (L < 1e-9) continue;
                mid.x = (p.x + r.x) / 2; mid.y = (p.y + r.y) / 2;
                nx = -(r.y - p.y) / L; ny = (r.x - p.x) / L;
                i1 = hk_point_in_quads(q, n, mid.x + nx * ee, mid.y + ny * ee);
                i2 = hk_point_in_quads(q, n, mid.x - nx * ee, mid.y - ny * ee);
                if (i1 != i2 && np < MAXPIECE) {
                    /* orient with the union on the right hand side */
                    if (i2) { /* inside is on the right (-n side) */
                        pc[np].a = p; pc[np].b = r;
                    } else {
                        pc[np].a = r; pc[np].b = p;
                    }
                    np++;
                }
            }
        }

    /* 2. drop duplicates (coincident quad sides) */
    {
        int w = 0;
        for (i = 0; i < np; i++) {
            int dup = 0;
            for (j = 0; j < w; j++)
                if (dist(pc[i].a, pc[j].a) < 1e-6 && dist(pc[i].b, pc[j].b) < 1e-6) { dup = 1; break; }
            if (!dup) pc[w++] = pc[i];
        }
        np = w;
    }
    /* 3. drop pieces lying on a plan edge of the building (already drawn) */
    {
        int w = 0;
        for (i = 0; i < np; i++) {
            int on = 0;
            for (j = 0; j < n; j++)
                if (dist(e[j].a, e[j].b) > 1e-9 &&
                    dist_line(pc[i].a, e[j].a, e[j].b) < 1e-5 &&
                    dist_line(pc[i].b, e[j].a, e[j].b) < 1e-5) { on = 1; break; }
            if (!on) pc[w++] = pc[i];
        }
        np = w;
    }
    /* 4. merge head-to-tail collinear pieces */
    do {
        changed = 0;
        for (i = 0; i < np && !changed; i++)
            for (j = 0; j < np && !changed; j++) {
                double v1x, v1y, v2x, v2y;
                if (i == j) continue;
                if (dist(pc[i].b, pc[j].a) >= 1e-6) continue;
                v1x = pc[i].b.x - pc[i].a.x; v1y = pc[i].b.y - pc[i].a.y;
                v2x = pc[j].b.x - pc[j].a.x; v2y = pc[j].b.y - pc[j].a.y;
                if (fabs(v1x * v2y - v1y * v2x) < 1e-6 * hypot(v1x, v1y) * hypot(v2x, v2y) &&
                    v1x * v2x + v1y * v2y > 0) {
                    pc[i].b = pc[j].b;
                    pc[j] = pc[np - 1];
                    np--;
                    changed = 1;
                }
            }
    } while (changed);

    /* 5. chain: start from pieces whose start is nobody's end */
    {
        int *used = (int *)calloc((size_t)(np > 0 ? np : 1), sizeof(int));
        int cnt = 0;
        for (i = 0; i < np && used; i++) {
            int has_pred = 0;
            if (used[i]) continue;
            for (j = 0; j < np; j++)
                if (j != i && dist(pc[j].b, pc[i].a) < 1e-6) { has_pred = 1; break; }
            if (has_pred) continue;
            for (k = i; k >= 0 && cnt < maxout; ) {
                int nxt = -1;
                used[k] = 1;
                out[cnt] = pc[k];
                chain_start[cnt] = (k == i);
                cnt++;
                for (j = 0; j < np; j++)
                    if (!used[j] && dist(pc[k].b, pc[j].a) < 1e-6) { nxt = j; break; }
                k = nxt;
            }
        }
        /* closed loops (no start): emit the rest */
        for (i = 0; i < np && used; i++) {
            if (used[i]) continue;
            for (k = i; k >= 0 && cnt < maxout; ) {
                int nxt = -1;
                used[k] = 1;
                out[cnt] = pc[k];
                chain_start[cnt] = (k == i);
                cnt++;
                for (j = 0; j < np; j++)
                    if (!used[j] && dist(pc[k].b, pc[j].a) < 1e-6) { nxt = j; break; }
                k = nxt;
            }
        }
        free(used);
        free(q); free(pc); free(ts);
        return cnt;
    }
}

int hk_label_segment_index(double hour) { return hour > 12.0 ? 3 : 2; }

void hk_label_place(hk_pt a, hk_pt b, double w, hk_pt *start, hk_pt *end, double *angle_deg)
{
    double dx = b.x - a.x, dy = b.y - a.y, len = hypot(dx, dy), ux, uy, d;
    if (len < 1e-12) { ux = 1; uy = 0; } else { ux = dx / len; uy = dy / len; }
    d = (len - w) / 2.0;
    start->x = ux * d - uy * 0.5 + a.x;
    start->y = ux * 0.5 + uy * d + a.y;
    end->x = ux * (d + w) - uy * 0.5 + a.x;
    end->y = ux * 0.5 + uy * (d + w) + a.y;
    *angle_deg = atan2(uy, ux) * 180.0 / PI;
}

/* ------------------------------------------------------------------ */
/* 4. intervals                                                        */
/* ------------------------------------------------------------------ */

int hk_intervals(const unsigned char *in, int n, int tbegin, int step,
                 hk_interval *iv, int maxiv)
{
    int i, k = 0, open = 0, t, tend = tbegin + (n - 1) * step;
    for (i = 0; i < n; i++) {
        t = tbegin + i * step;
        if (in[i]) {
            if (!open && k < maxiv) { iv[k].start = t; iv[k].end = tend; k++; open = 1; }
        } else if (open) {
            iv[k - 1].end = t;
            open = 0;
        }
    }
    /* [D 0x005470d0 @0x547a..] move every start back by one step unless it is the
     * very first sample or it touches the end of the previous interval */
    for (i = 0; i < k; i++) {
        int shift = step;
        if (i > 0 && iv[i].start <= iv[i - 1].end) shift = 0;
        if (iv[i].start > tbegin) iv[i].start -= shift;
    }
    return k;
}

void hk_fmt_n0_line(char *out, int outsz, int no, const hk_interval *iv, int niv, int step)
{
    int i, total = 0, len;
    char tmp[64];
    for (i = 0; i < niv; i++) {
        total += iv[i].end - iv[i].start;
        if (iv[i].end == iv[i].start) total++;
    }
    len = snprintf(out, (size_t)outsz, no < 10 ? "N0.%d " : "N0.%d", no);
    if (step < 60)
        len += snprintf(out + len, (size_t)(outsz - len), "  [%2d:%02d'%02d\"]", total / 3600, (total / 60) % 60, total % 60);
    else
        len += snprintf(out + len, (size_t)(outsz - len), "  [%2d:%02d']", total / 3600, (total / 60) % 60);
    for (i = 0; i < niv && len < outsz - 40; i++) {
        int s = iv[i].start + 14400, e = iv[i].end + 14400;   /* 0x3840 */
        if (step < 60)
            snprintf(tmp, sizeof tmp, "  (%2d:%02d'%02d\")-(%2d:%02d'%02d\")",
                     s / 3600 + 8, (s / 60) % 60, s % 60, e / 3600 + 8, (e / 60) % 60, e % 60);
        else
            snprintf(tmp, sizeof tmp, "  (%2d:%02d')-(%2d:%02d')",
                     s / 3600 + 8, (s / 60) % 60, e / 3600 + 8, (e / 60) % 60);
        len += snprintf(out + len, (size_t)(outsz - len), "%s", tmp);
    }
}

/* ------------------------------------------------------------------ */
/* 5. iso                                                              */
/* ------------------------------------------------------------------ */
double hk_iso_threshold(double level_hours, int step_sec)
{
    return level_hours * 3600.0 / (double)step_sec - 0.1;
}

/* ------------------------------------------------------------------ */
/* 6. 天空図                                                           */
/* ------------------------------------------------------------------ */

void hk_tenkuu_project(double px, double py, double x, double y, double h,
                       double R, int equidist, int mirror, double off,
                       double *ox, double *oy)
{
    double dx = x - px, dy = y - py, az, d, el, r;
    if (h < 0.0) h = 0.0;
    if (fabs(dx) < 1e-07 && fabs(dy) < 1e-07) { *ox = 0; *oy = 0; return; }
    az = atan2(dy, dx);
    d = sqrt(dx * dx + dy * dy);
    el = atan2(h, d);
    r = equidist ? (1.0 - el / 1.5707963267948966) * R : cos(el) * R;
    if (mirror) az = PI - (az - off);
    for (; az > PI; az -= 2 * PI) { }
    for (; az <= -PI; az += 2 * PI) { }
    *ox = cos(az) * r;
    *oy = sin(az) * r;
}

double hk_skyline_el(const hk_edge3 *e, int n, double px, double py, double az)
{
    double dx = cos(az), dy = sin(az), best = -1.0;
    int i;
    for (i = 0; i < n; i++) {
        double ex = e[i].x1 - e[i].x0, ey = e[i].y1 - e[i].y0;
        double den = dx * ey - dy * ex, s, u, z, el;
        if (fabs(den) < 1e-12) continue;
        s = ((e[i].x0 - px) * ey - (e[i].y0 - py) * ex) / den;
        u = ((e[i].x0 - px) * dy - (e[i].y0 - py) * dx) / den;
        if (s <= 0 || u < 0 || u > 1) continue;
        z = e[i].z0 + (e[i].z1 - e[i].z0) * u;
        if (z < 0) z = 0;
        el = atan2(z, s);
        if (el > best) best = el;
    }
    return best;
}

double hk_sky_ratio(const hk_edge3 *e, int n, double px, double py,
                    int nsteps, int equidist)
{
    double tot = 0.0;
    int k;
    for (k = 0; k < nsteps; k++) {
        double az = (double)k * 2.0 * PI / (double)nsteps;   /* [D 0x00748da0] cos(i*dtheta), i from 0 */
        double el = hk_skyline_el(e, n, px, py, az);
        if (el <= 0) continue;
        tot += equidist ? sin(el) : sin(el) * sin(el) / 2.0;
    }
    if (equidist) return 100.0 * (1.0 - tot * (2.0 * PI / (double)nsteps) / (2.0 * PI));
    return 100.0 * (1.0 - tot * (2.0 * PI / (double)nsteps) / PI);
}

double hk_sky_round(double pct, int precise)
{
    double d = precise ? 1000.0 : 100.0, w = precise ? 0.001 : 0.01;
    int i;
    for (i = 25; i <= 75; i += 25)
        if (pct > i - w && pct < i + w) pct = (double)i;
    return (double)(int)(d * pct + 0.5) / d;
}

int hk_compare_ok(double plan_pct, double base_pct, double tol)
{
    double d = fabs(plan_pct) - fabs(base_pct);
    return d > tol + 1e-07;
}
