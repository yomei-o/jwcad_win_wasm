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
    hk_pt *drop_pt = (hk_pt *)malloc(sizeof(hk_pt) * 2 * MAXPIECE);
    int np = 0, i, j, k, m, changed, ndrop = 0;
    double *ts = (double *)malloc(sizeof(double) * (size_t)(4 * n + 8));
    if (!q || !pc || !ts || !drop_pt) { free(q); free(pc); free(ts); free(drop_pt); return 0; }
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
            if (on) {
                if (ndrop < 2 * MAXPIECE) { drop_pt[ndrop++] = pc[i].a; drop_pt[ndrop++] = pc[i].b; }
            } else
                pc[w++] = pc[i];
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
        /* 原典は 鎖を「いちばん下（y 最小）、同じなら いちばん右（x 最大）」の頂点から回して書く。
           建物の平面の辺（書かない）も そのまわりの一周には入っている。
           その頂点が 鎖の途中なら そこから始め、前の部分を あとに回す [V c2・c8（夏）] */
        {
            hk_pt S;
            int have = 0, c0, c1;

            for (i = 0; i < 2 * np + ndrop; i++) {
                hk_pt p = i < 2 * np ? (i & 1 ? pc[i / 2].b : pc[i / 2].a) : drop_pt[i - 2 * np];
                if (!have || p.y < S.y - 1e-6 || (fabs(p.y - S.y) <= 1e-6 && p.x > S.x + 1e-6)) {
                    S = p;
                    have = 1;
                }
            }
            for (c0 = 0; have && c0 < cnt; c0 = c1) {
                hk_seg tmp[1024];
                int len, r = -1;

                for (c1 = c0 + 1; c1 < cnt && !chain_start[c1]; c1++)
                    ;
                len = c1 - c0;
                for (k = 1; k < len; k++)
                    if (dist(out[c0 + k].a, S) < 1e-6) { r = k; break; }
                if (r > 0 && len <= 1024) {
                    memcpy(tmp, out + c0, sizeof(hk_seg) * (size_t)len);
                    for (k = 0; k < len; k++) {
                        out[c0 + k] = tmp[(k + r) % len];
                        chain_start[c0 + k] = (k == 0);
                    }
                    /* 開いた鎖は 平面の辺を書かなかったところで 切れたまま（別の鎖）。閉じた輪なら 一本 */
                    if (dist(tmp[len - 1].b, tmp[0].a) > 1e-6)
                        chain_start[c0 + len - r] = 1;
                }
            }
        }
        free(q); free(pc); free(ts); free(drop_pt);
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

/* 日影図の 等時間 (CZukeiKage2): 測定格子に 影になった標本の数を数え、その等高線を引く。
 *
 * 原典のデコンパイルから起こした（FUN_0054a0b0 = 格子と数え上げ、FUN_0069b4c0 = 既定の範囲、
 * FUN_00545810 = 建物のまわりの印、FUN_00548b30 = 等高線の追跡）。仕様の要点:
 *
 *  * 範囲は 建物の外枠（真北に合わせて回した枠）の 中心まわりに、影の届く長さ + 5 mm を足し、
 *    用紙の半分の大きさ（中心から ±用紙/2）で切る。
 *  * 格子は 30000 点まで（辺が 50 以上のあいだ）、1 点の間隔は 精度の 2 mm（60 秒）以上。
 *  * 標本は 12 時の前後 ±4 時間（9～15時 なら ±3 時間）を 精度の秒数ごと、半区間ずらして。
 *    各標本で 影の中にある格子点に 1 を足す。建物の中と その左右・上の 1 点は 10001 の印。
 *  * 等高線は 水準 level*3600/精度 - 0.1 を横切る辺をたどる。四角の 4 隅の平均（対角の大きいほう）
 *    の 中心点を 間にはさむ折れ線。印の点（>= 10000）に触れる四角では線を引かない。
 */


typedef struct {
    int nx, ny;
    double dx, dy, ox, oy;
    int *v;                 /* (行 - 1) * (nx + 1) + 列、行・列は 1 から */
    double T;
    double cx, cy, north;
    hk_isoseg *out;
    int nout, maxout;
    /* 追跡の状態 */
    int e0, bc;
    double best;
} grid_t;

#define V(g, c, r) ((g)->v[((r) - 1) * ((g)->nx + 1) + (c)])

static int iabs(int a) { return a < 0 ? -a : a; }

static double fx(const grid_t *g, double p1, double p2, int p4, int p5)
{
    return (double)p4 * g->dx + g->ox + (p1 * g->dx * (g->T - (double)p5)) / (p2 - (double)p5);
}

static double fy(const grid_t *g, double p1, double p2, int p4, int p5)
{
    return (double)p4 * g->dy + g->oy + (p1 * g->dy * (g->T - (double)p5)) / (p2 - (double)p5);
}

static void to_world(const grid_t *g, double x, double y, double *wx, double *wy)
{
    double rx, ry;

    hk_rot(x, y, g->north, &rx, &ry);
    *wx = rx + g->cx;
    *wy = ry + g->cy;
}

/* 線を一本（FUN_0053f880）。返り値 1 = 引いた */
static int emit(grid_t *g, int valid, double x0, double y0, double x1, double y1, int rowkey)
{
    hk_isoseg *s;

    if (!valid || (x0 == x1 && y0 == y1))
        return 0;
    if (g->nout >= g->maxout)
        return 0;
    s = &g->out[g->nout];
    to_world(g, x0, y0, &s->x0, &s->y0);
    to_world(g, x1, y1, &s->x1, &s->y1);
    s->label = 0;
    g->nout++;
    g->e0++;
    if (g->best < (double)rowkey) {
        g->best = (double)rowkey;
        g->bc = g->nout;                /* 1 から（0 は無し） */
    }
    return 1;
}

static void flush(grid_t *g, int need)
{
    if (g->e0 > need && g->bc) {
        g->out[g->bc - 1].label = 1;
        g->out[g->bc - 1].label_at = g->nout;
    }
    g->bc = 0;
    g->e0 = 0;
    g->best = -9e40;
}

/* 一本の等高線を スタートの辺（(c1,r1)-(c2,r2)）から たどる。FUN_00548b30 の中身 */
static void follow(grid_t *g, int d8, int dc, int i7, int i10)
{
    int a8 = d8, a4 = dc, b0 = i7, b4 = i10;
    int n9c = iabs(V(g, a8, a4)), na0 = iabs(V(g, b0, b4));
    int ac = b0 - a8, b8 = b4 - a4;
    double x13c = fx(g, (double)ac, (double)na0, a8, n9c);
    double y144 = fy(g, (double)b8, (double)na0, a4, n9c);
    int valid;

    do {
        int cc = iabs(V(g, a8 + ac - b8, a4 + ac + b8));
        int d0 = iabs(V(g, a8 - b8, a4 + ac));
        int s5, s4, s8, s6, i9;
        double c134, dv1, dv2;

        if (n9c < 10000 && na0 < 10000 && cc < 10000 && d0 < 10000)
            valid = 1;
        else {
            valid = 0;
            flush(g, 20);
        }
        s6 = a4;
        s5 = a8;
        s4 = b0;
        s8 = b4;
        i9 = na0 + d0 < n9c + cc ? n9c + cc : na0 + d0;
        c134 = (double)i9 / 2.0;
        a8 = b0;
        b0 = s5;
        a4 = b4;
        b4 = s6;
        n9c = iabs(V(g, s4, s8));
        na0 = iabs(V(g, b0, b4));
        ac = b0 - a8;
        b8 = b4 - a4;
        if ((c134 - g->T) * ((double)na0 - g->T) < 0.0) {
            do {
                int m4 = b0, m8 = b4;

                a8 = b0;
                a4 = b4;
                b0 = b0 + b8;
                b4 = b4 - ac;
                n9c = iabs(V(g, m4, m8));
                na0 = iabs(V(g, b0, b4));
                ac = b0 - a8;
                b8 = b4 - a4;
                dv1 = fx(g, (double)(ac + b8) / 2.0, c134, a8, n9c);
                dv2 = fy(g, (double)(b8 - ac) / 2.0, c134, a4, n9c);
                emit(g, valid, x13c, y144, dv1, dv2, a4);
                y144 = dv2;
                x13c = dv1;
            } while (0.0 <= ((double)n9c - g->T) * ((double)na0 - g->T));
        } else {
            do {
                dv1 = fx(g, (double)(ac + b8) / 2.0, c134, a8, n9c);
                dv2 = fy(g, (double)(b8 - ac) / 2.0, c134, a4, n9c);
                emit(g, valid, x13c, y144, dv1, dv2, a4);
                b0 = a8;
                b4 = a4;
                a8 = a8 + b8;
                a4 = a4 - ac;
                n9c = iabs(V(g, a8, a4));
                na0 = iabs(V(g, b0, b4));
                ac = b0 - a8;
                b8 = b4 - a4;
                y144 = dv2;
                x13c = dv1;
            } while (0.0 <= ((double)n9c - g->T) * ((double)na0 - g->T));
        }
        {                               /* 通った 2 点に 印（負）を付ける */
            int *p = &V(g, a8, a4);

            *p = -iabs(*p);
            p = &V(g, b0, b4);
            *p = -iabs(*p);
        }
        dv1 = fx(g, (double)ac, (double)na0, a8, n9c);
        dv2 = fy(g, (double)b8, (double)na0, a4, n9c);
        emit(g, valid, x13c, y144, dv1, dv2, a4);
        y144 = dv2;
        x13c = dv1;
    } while (0 < a8 - b8 && a8 - b8 <= g->nx && 0 < a4 + ac && a4 + ac <= g->ny &&
             (a8 != d8 || a4 != dc || b0 != i7 || b4 != i10));
    if (g->e0 > 10)
        flush(g, 0);
}

static void trace(grid_t *g)
{
    int c0, nx = g->nx, ny = g->ny, k;
    int ds[5] = { 0, 2, ny, 1, 1 }, de[5] = { 0, ny, ny, ny - 1, ny - 1 };
    int doff[5] = { 0, -1, 0, 1, 0 };
    int es[5] = { 0, 1, 2, nx, 1 }, ee[5] = { 0, 1, nx, nx, nx - 1 };
    int eoff[5] = { 0, 0, -1, 0, 1 };

    g->e0 = 0;
    g->bc = 0;
    g->best = -9e40;
    for (c0 = 1; c0 < 5; c0++)
        for (int dc = ds[c0]; dc <= de[c0]; dc++) {
            int i10 = dc + doff[c0];

            for (int d8 = es[c0]; d8 <= ee[c0]; d8++) {
                int i7 = d8 + eoff[c0];
                int v1 = V(g, d8, dc), v2 = V(g, i7, i10);
                double a1 = (double)iabs(v1), a2 = (double)iabs(v2);

                if ((a1 - g->T) * (a2 - g->T) < 0.0 && (v1 > 0 || v2 > 0))
                    follow(g, d8, dc, i7, i10);
            }
        }
    for (k = 1; k < (nx + 1) * ny; k++)
        g->v[k] = iabs(g->v[k]);
}

/* 辺の集まりを 偶奇で見て (px,py) が 建物の平面の中か */
static int inside_plan(const hk_edge *e, int n, double px, double py)
{
    int q, in = 0;

    for (q = 0; q < n; q++) {
        double ax = e[q].a.x, ay = e[q].a.y, bx = e[q].b.x, by = e[q].b.y;

        if ((ay > py) != (by > py) && px < ax + (py - ay) * (bx - ax) / (by - ay))
            in = !in;
    }
    return in;
}

int hk_iso(const hk_edge *e, int ne, const hk_iso_in *in, hk_isoseg *out, int maxout)
{
    grid_t g;
    hk_sun sun;
    double xmin = 1e30, xmax = -1e30, ymin = 1e30, ymax = -1e30, maxz = 0.0;
    double hx, hy, mult, sa, ca, d8, f0, len2, c, s;
    double lo_x, hi_x, lo_y, hi_y, w, h, asp, dxs, dys, pitch;
    double cl_lo, cl_hi, cl_top;
    int i, j, k, nx, ny, t, t0, t1, nsamp, step = in->step > 0 ? in->step : 60;
    int *val = 0, np;
    hk_quad *qd;

    if (ne < 1)
        return 0;
    for (i = 0; i < ne; i++) {
        double px[2] = { e[i].a.x, e[i].b.x }, py[2] = { e[i].a.y, e[i].b.y };

        for (j = 0; j < 2; j++) {
            if (px[j] < xmin) xmin = px[j];
            if (px[j] > xmax) xmax = px[j];
            if (py[j] < ymin) ymin = py[j];
            if (py[j] > ymax) ymax = py[j];
        }
        if (e[i].za_mm > maxz) maxz = e[i].za_mm;
        if (e[i].zb_mm > maxz) maxz = e[i].zb_mm;
    }
    memset(&g, 0, sizeof g);
    g.north = in->north;
    g.cx = (xmin + xmax) / 2.0;
    g.cy = (ymin + ymax) / 2.0;
    /* 外枠を 真北に合わせて回した 半分の大きさ */
    c = cos(in->north * PI / 180.0);
    s = sin(in->north * PI / 180.0);
    hx = hy = 0.0;
    for (i = 0; i < 4; i++) {
        double qx = (i & 1 ? xmax : xmin) - g.cx, qy = (i & 2 ? ymax : ymin) - g.cy;
        double lx = qx * c + qy * s, ly = -qx * s + qy * c;

        if (fabs(lx) > hx) hx = fabs(lx);
        if (fabs(ly) > hy) hy = fabs(ly);
    }
    /* 影の届く長さ: 9:00（-10800 秒）と 正午 */
    hk_wall_sun_side(in->lat, in->dec, -10800, 0.0, 0.0, &mult, &sa, &ca);
    len2 = maxz * mult;
    d8 = fabs(len2 * sa);
    f0 = fabs(len2 * ca);
    hk_wall_sun_side(in->lat, in->dec, 0, 0.0, 0.0, &mult, &sa, &ca);
    len2 = maxz * mult;
    if (fabs(len2 * sa) > d8) d8 = fabs(len2 * sa);
    if (fabs(len2 * ca) > f0) f0 = fabs(len2 * ca);
    lo_x = -hx - d8 - 5.0;
    hi_x = hx + d8 + 5.0;
    lo_y = -hy - 5.0;
    hi_y = hy + f0 + 5.0;
    /* 用紙の半分で切る（回した枠の中心は 原点） */
    {
        double sw = in->sheet_w / 2.0, sh = in->sheet_h / 2.0;
        double cxs[4] = { -sw, sw, sw, -sw }, cys[4] = { sh, sh, -sh, -sh };

        cl_lo = 1e30;
        cl_hi = -1e30;
        cl_top = -1e30;
        for (i = 0; i < 4; i++) {
            double qx = cxs[i] - g.cx, qy = cys[i] - g.cy;
            double lx = qx * c + qy * s, ly = -qx * s + qy * c;

            if (lx < cl_lo) cl_lo = lx;
            if (lx > cl_hi) cl_hi = lx;
            if (ly > cl_top) cl_top = ly;
        }
    }
    if (lo_x < cl_lo) lo_x = cl_lo;
    if (hi_x > cl_hi) hi_x = cl_hi;
    if (hi_y > cl_top) hi_y = cl_top;
    if (in->range) {                     /* 範囲指定: 4 隅を 回した枠に直して 最小・最大 */
        lo_x = lo_y = 1e30;
        hi_x = hi_y = -1e30;
        for (i = 0; i < 4; i++) {
            double qx = in->rx[i] - g.cx, qy = in->ry[i] - g.cy;
            double lx = qx * c + qy * s, ly = -qx * s + qy * c;

            if (lx < lo_x) lo_x = lx;
            if (lx > hi_x) hi_x = lx;
            if (ly < lo_y) lo_y = ly;
            if (ly > hi_y) hi_y = ly;
        }
    }
    /* 格子 */
    w = hi_x - lo_x;
    h = hi_y - lo_y;
    if (w < 50.0) w = 50.0;
    if (h < 50.0) h = 50.0;
    asp = h / w;
    nx = (int)sqrt(30000.0 / asp);
    ny = (int)((double)nx * asp);
    while (30000 < (nx + 1) * ny) {
        if (50 < nx) nx--;
        if (50 < ny) ny--;
    }
    dxs = w / (double)nx;
    dys = h / (double)ny;
    pitch = step == 180 ? 5.0 : step == 60 ? 2.0 : step == 20 ? 0.75 : step == 10 ? 0.5
          : step == 4 ? 0.2 : step == 2 ? 0.1 : 10.0;
    if (dxs <= pitch && dxs != pitch) {
        dxs = pitch;
        nx = (int)(w / dxs);
    }
    if (dys <= pitch && dys != pitch) {
        dys = pitch;
        ny = (int)(h / dys);
    }
    g.nx = nx;
    g.ny = ny;
    g.dx = dxs;
    g.dy = dys;
    g.ox = lo_x;
    g.oy = lo_y;
    val = (int *)calloc((size_t)(nx + 1) * (size_t)ny + 2, sizeof(int));
    qd = (hk_quad *)malloc(sizeof(hk_quad) * (size_t)ne);
    if (!val || !qd) {
        free(val);
        free(qd);
        return 0;
    }
    g.v = val;
    g.out = out;
    g.maxout = maxout;
    g.T = in->level * 3600.0 / (double)step - 0.1;

    /* 建物の平面の中と そのまわり（左右 1 点・上 1 段）に 印 */
    for (j = 1; j <= ny; j++)
        for (i = 1; i <= nx; i++) {
            double lx = g.ox + (double)i * g.dx, ly = g.oy + (double)j * g.dy, wx, wy;

            to_world(&g, lx, ly, &wx, &wy);
            if (inside_plan(e, ne, wx, wy))
                V(&g, i, j) = 1;
        }
    for (j = 1; j <= ny; j++)
        for (i = 1; i <= nx; i++) {
            int idx = (j - 1) * (nx + 1) + i;

            if (val[idx] == 0) {
                if (i < nx && val[idx + 1] == 1)
                    val[idx] = 2;
                if (1 < i && val[idx - 1] == 1)
                    val[idx] = 2;
                if (1 < j && (val[idx - nx] == 1 || val[idx - nx] == 2))
                    val[idx] = 3;
            }
        }
    for (j = 1; j <= ny; j++)
        for (i = 1; i <= nx; i++)
            if (V(&g, i, j))
                V(&g, i, j) = 10001;

    /* 数え上げ */
    hk_sun_init(&sun, in->lat, in->dec);
    t1 = in->n15 ? 0x2a30 : 0x3840;
    t0 = step / 2 - t1;
    nsamp = 0;
    np = 0;
    for (t = t0; t <= t1; t += step) {
        double x, y, sx, sy;

        hk_sun_shadow(&sun, t, &x, &y);
        hk_rot(x, y, in->north, &sx, &sy);
        hk_build_quads(e, ne, sx, sy, qd);
        /* 原典は 影の先の点を 0.01 mm の整数に切り捨てて 走査する（0 に向かって） */
        for (i = 0; i < ne; i++)
            for (j = 2; j < 4; j++) {
                qd[i].p[j].x = (double)(long)(qd[i].p[j].x * 100.0) / 100.0;
                qd[i].p[j].y = (double)(long)(qd[i].p[j].y * 100.0) / 100.0;
            }
        for (j = 1; j <= ny; j++)
            for (i = 1; i <= nx; i++) {
                double lx = g.ox + (double)i * g.dx, ly = g.oy + (double)j * g.dy, wx, wy;

                to_world(&g, lx, ly, &wx, &wy);
                if (hk_point_in_quads(qd, ne, wx, wy))
                    V(&g, i, j)++;
            }
        nsamp++;
    }
    (void)k;
    (void)np;
    (void)nsamp;
    trace(&g);
    free(val);
    free(qd);
    return g.nout;
}
