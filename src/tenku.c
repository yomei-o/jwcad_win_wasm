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
#include <stdlib.h>
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
#define S_TENKUHI    "\x93\x56\x8b\xf3\x94\xe4"              /* 天空比 */
#define S_SUIHEIEN   "\x90\x85\x95\xbd\x89\x7e\x8e\xcb\x89\x65\x96\xca\x90\xcf" /* 水平円射影面積 */
#define S_HANKYU     "\x94\xbc\x8b\x85\x8e\xcb\x89\x65\x95\x5c\x96\xca\x90\xcf" /* 半球射影表面積 */
#define S_KAKKO0     "\x81\x79"                              /* 【 */
#define S_KAKKO1     "\x81\x7a"                              /* 】 */
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
    return jw_tenku_collect2(d, plane_m, e, NULL, max);
}

/* 下端は FUN_0073dc40 (_unassigned.c 302760〜): 値が二つなら 二つ目 + 高さの基準 − 測定面、
   一つで 0 以上なら −測定面（正なら 0 に切る）、一つで負なら 下端なし（壁を立てない）。
   原典の +0xbc==4 の枝（測定面を引かない）は 天空図では通らない（hk_s11 の 測定高 1.5 が
   上端から引かれている）。 */
int jw_tenku_collect2(const jw_drawing *d, double plane_m, hk_edge3 *e, hk_tenku_base *bb, int max)
{
    int i, j, n = 0;
    double scale0 = -1.0;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *l = &d->obj[i];
        int end[2], k, found, cnt[2] = { 0, 0 };
        double h[2], h2[2] = { 0.0, 0.0 }, z[2], base, sc;

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
                if ((cnt[k] = hk_parse_height_text(buf, &v1, &v2)) < 1)
                    continue;
                end[k] = j;
                h[k] = v1;
                h2[k] = v2;
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
        if (bb) {
            double zb[2];
            int w[2];

            for (k = 0; k < 2; k++) {
                if (cnt[k] >= 2) {
                    zb[k] = (h2[k] + base - plane_m) * 1000.0 / sc;
                    w[k] = 1;
                } else if (h[k] >= 0.0) {
                    zb[k] = (-plane_m > 0.0 ? 0.0 : -plane_m) * 1000.0 / sc;
                    w[k] = 1;
                } else {
                    zb[k] = 0.0;
                    w[k] = 0;
                }
            }
            bb[n].zb0 = zb[0];
            bb[n].zb1 = zb[1];
            bb[n].wall0 = w[0];
            bb[n].wall1 = w[1];
            bb[n].lay = l->layer;
            bb[n].grp = l->lgroup;
        }
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

/* 測定点表示: 測定点に 点 と「No.n」 */
static void point_mark(jw_drawing *d, const hk_tenku_opts *o, double px, double py,
                       double size)
{
    char buf[32];
    jw_obj *t = jw_add(d, JW_TEN);

    if (t) {
        t->d[0] = px;
        t->d[1] = py;
    }
    snprintf(buf, sizeof buf, "No.%d", o->number);
    add_text(d, buf, px, py, 0, size, 1, 1);
}

/* ------------------------------------------------------------------ */
/* 太陽軌跡 (1325) —— 原典 FUN_0073ea50（_unassigned.c 302825〜303172、
   機械語 0x73ea50〜0x7400b0）。答えは decomp/res/hk_s5（南方向補正 点いたまま）・
   s6（南方向補正 切）・s7（10分間隔点表示）・s8（四季）                     */
/* ------------------------------------------------------------------ */
#define S_SUN_SP     " \x81\x40"                             /* 0x14b4 " 　" */
#define S_TOUJI      "\x93\x7e\x8e\x8a"                      /* 0x15cf 冬至 */
#define S_SHUNSHU    "\x8f\x74\x8f\x48\x95\xaa"              /* 0x15d0 春秋分 */
#define S_GESHI      "\x89\xc4\x8e\x8a"                      /* 0x15d1 夏至 */
#define S_TAIYOU     " \x91\xbe\x97\x7a\x88\xca\x92\x75"     /* 0x1658 " 太陽位置" */
#define S_HANDEG     "\xdf"                                  /* 0x1833 ﾟ */
#define S_IDO        "\x88\xdc\x93\x78"                      /* 0x15d4 緯度 */

static jw_obj *add_ten(jw_drawing *d, double x, double y, int col)
{
    jw_obj *t = jw_add(d, JW_TEN);

    if (t) {
        t->d[0] = x;
        t->d[1] = y;
        t->color = (unsigned short)col;
        t->ltype = 1;
    }
    return t;
}

/* 文字を (x,y) から 角度 deg の向きに置き直す（add_text は水平に置く） */
static void turn_text(jw_obj *t, double x, double y, double deg)
{
    double w, a = deg * PI / 180.0, c = cos(a), s = sin(a);

    if (!t)
        return;
    w = hypot(t->d[2] - t->d[0], t->d[3] - t->d[1]);
    if (fabs(c) < 1e-12)
        c = 0.0;
    if (fabs(s) < 1e-12)
        s = 0.0;
    while (deg > 180.0)
        deg -= 360.0;
    while (deg <= -180.0)
        deg += 360.0;
    t->d[0] = x;
    t->d[1] = y;
    t->d[2] = x + c * w;
    t->d[3] = y + s * w;
    t->d[7] = deg;
}

/* 時刻の字（"8"／"16"、9～15時 なら "9"／"15"、0x95bd2c・0x95bd30・0x97b23c・0x97b244）は
   点の上 1.0（FUN_00479c40 の 1.0）に、時刻の数字の真ん中が点に来るように置く。
   季節の字は 南方向補正 なしなら 初めの字、ありなら 終わりの字に付く（+0x190 を見る、
   0x73f805・0x73faa9）。南方向補正 なしでは字も 真北 の角度に回る（local_3b4 = +0x198、
   原典 hk_s21 で −90°）。原典 hk_s5・s6・s21 */
static void sun_label(jw_drawing *d, const char *num, const char *season, double x, double y,
                      double size, double deg)
{
    char buf[96];
    double half = strlen(num) * size / 4.0, a = deg * PI / 180.0;
    jw_obj *t;

    snprintf(buf, sizeof buf, "%s%s", num, season ? season : "");
    t = add_text(d, buf, x, y, 0, size, 1, 1);
    turn_text(t, x - cos(a) * half - sin(a) * 1.0, y - sin(a) * half + cos(a) * 1.0, deg);
}

static void sun_path(jw_drawing *d, const hk_tenku_opts *o, double px, double py,
                     double cx, double cy, double size)
{
    double phi = o->lat * PI / 180.0, dec, L = (o->north - 90.0) * PI / 180.0;
    double turn = o->mirror ? 0.0 : o->north;   /* local_3b4: 南方向補正 なしなら 真北 で回す */
    int span = o->sun_n15 ? 180 : 240, k;
    static const char *const nsew[4] = { "E", "N", "W", "S" };   /* 0x95bd50・bd7c・bd74・955184 */

    while (L > PI)
        L -= 2 * PI;
    while (L <= -PI)
        L += 2 * PI;
    if (o->shiki)
        dec = -23.45;
    else {
        dec = o->dec;
        if (dec > 23.45)
            dec = 23.45;
        if (dec < -23.45)
            dec = -23.45;
    }
    for (;;) {
        char season[64];
        double ad = fabs(dec), dr = dec * PI / 180.0, lx = 0, ly = 0;
        int t, step = 0;

        /* 季節の字: " 　" + 冬至／春秋分／夏至（任意の日赤緯は【%lgﾟ】） + " 太陽位置" */
        if (ad <= 1e-7)
            snprintf(season, sizeof season, S_SUN_SP S_SHUNSHU S_TAIYOU);
        else if (ad < 23.449999899999998) {
            /* 任意の日赤緯: 【 %lg ﾟ 】（0x1b5e・0x95590c・0x1833・0x1b58）。原典の答えはまだ無い */
            char nb[32];

            snprintf(nb, sizeof nb, "%g", dec);
            snprintf(season, sizeof season, S_SUN_SP S_KAKKO0 "%s" S_HANDEG S_KAKKO1 S_TAIYOU, nb);
        } else
            snprintf(season, sizeof season, S_SUN_SP "%s" S_TAIYOU, dec >= 0.0 ? S_GESHI : S_TOUJI);
        for (t = -span; t <= span; t += 10) {
            double h = -(t * 0.25 * PI / 180.0);
            double sa = sin(phi) * sin(dr) + cos(phi) * cos(dr) * cos(h), c2 = 1.0 - sa * sa;
            double x, y;

            if (fabs(c2) >= 1e-7) {
                double ca = sqrt(c2), al = atan2(sa, ca);
                double az = atan2(cos(dr) * sin(h) / ca, (sin(phi) * sa - sin(dr)) / (cos(phi) * ca)) + L;

                /* 測定点から 100 の所・高さ tanα·100 の点を FUN_00733e40 で射影。
                   地平線の下（α < 0）の点も 原典は描く（FUN_0073cb20 は常に 1）が、
                   その射影がどうなるかは原典に確認が要る（移植は高さ 0 に切る） */
                proj(o, px, py, cx, cy, px + cos(az) * 100.0, py + sin(az) * 100.0,
                     tan(al) * 100.0, &x, &y);
            } else {
                x = cx;             /* 天頂（原典は前の点を写すだけ。確認が要る） */
                y = cy;
            }
            if (step == 0)
                sun_label(d, o->sun_n15 ? "9" : "8", o->mirror ? NULL : season, x, y, size, turn);
            else
                add_line(d, lx, ly, x, y, 5, 1, 0);
            if (step % 60 == 0)
                add_ten(d, x, y, 5);
            else if (o->sun10)
                add_ten(d, x, y, 1);
            lx = x;
            ly = y;
            step += 10;
        }
        sun_label(d, o->sun_n15 ? "15" : "16", o->mirror ? season : NULL, lx, ly, size, turn);
        if (!o->shiki || dec > 1.0)
            break;
        dec += 23.45;
    }
    /* 方位: 円から 2 の線と E/N/W/S（0x73ff30〜）。南方向補正 では E と W を入れ替え、
       なしでは 真北 の角度だけ回す（原典 hk_s5・s6・s18・s21） */
    for (k = 0; k < 4; k++) {
        double a = k * PI / 2.0 + turn * PI / 180.0, ux = cos(a - PI / 2.0), uy = sin(a - PI / 2.0);
        double tx = cx + cos(a) * (o->R + 2.0), ty = cy + sin(a) * (o->R + 2.0), w = size / 2.0;
        int m = k;

        if (o->mirror && (k == 0 || k == 2))
            m = 2 - k;
        add_line(d, cx + cos(a) * o->R, cy + sin(a) * o->R, tx, ty, 0, 0, 0);
        turn_text(add_text(d, nsew[m], tx, ty, 0, size, 1, 2), tx - ux * w / 2.0, ty - uy * w / 2.0,
                  k * 90.0 + turn - 90.0);
    }
}

/* 「緯度 = 36°」（FUN_00748da0 の 0x74af0b〜: 0x15d4 + " = %lg"（0x979128）+ 0x1834「°」） */
static void sun_lat_text(jw_drawing *d, const hk_tenku_opts *o, double cx, double y, double size)
{
    char buf[64];

    snprintf(buf, sizeof buf, S_IDO " = %g" S_DEG, o->lat);
    add_text(d, buf, cx, y, 1, size, 1, 2);
}

/* ------------------------------------------------------------------ */
/* 天空率の計算 —— 原典 FUN_00748da0 の写し                              */
/* ------------------------------------------------------------------ */
/* 三次元の線（原典の CData3DSen、doc の +0x1e4 の並び）。FUN_0073c0c0 が 一本の
   平面の線から 下端の線・上端の線・始点の縦線・終点の縦線 の順に作る。 */
typedef struct {
    double x0, y0, z0, x1, y1, z1;
    int lay, grp, bno;
} tn_l3;

/* 射影した線分（原典 FUN_0042de90 で作る CDataSen。+0x190 と +0x21c の並び）。
   座標は 円の中心を原点・半径 50（+0xa8）の図の上 */
typedef struct {
    double x0, y0, x1, y1;
    int ground, bno;
} tn_seg;

#define TN_A8 50.0

typedef struct {
    tn_l3 *c;
    int nc, cap;
} tn_list3;

/* FUN_0073d240: 平面で長さが無く 高さも同じなら作らない。両端の z が 1e-7 以下なら
   +0x44 = 1（地面の線） */
static void tn_add3(tn_list3 *L, double x0, double y0, double z0, double x1, double y1, double z1,
                    int lay, int grp)
{
    if (fabs(x0 - x1) < 1e-7 && fabs(y0 - y1) < 1e-7 && fabs(z0 - z1) < 1e-7)
        return;
    if (L->nc >= L->cap) {
        int nc = L->cap ? L->cap * 2 : 64;
        tn_l3 *p = (tn_l3 *)realloc(L->c, (size_t)nc * sizeof *p);

        if (!p)
            return;
        L->c = p;
        L->cap = nc;
    }
    L->c[L->nc].x0 = x0; L->c[L->nc].y0 = y0; L->c[L->nc].z0 = z0;
    L->c[L->nc].x1 = x1; L->c[L->nc].y1 = y1; L->c[L->nc].z1 = z1;
    L->c[L->nc].lay = lay;
    L->c[L->nc].grp = grp;
    L->c[L->nc].bno = 0;
    L->nc++;
}

/* FUN_0073cde0: 平面で長さのある線が 高さ 0 をまたぐなら そこで二つに切る */
static void tn_add3_split(tn_list3 *L, double x0, double y0, double z0, double x1, double y1,
                          double z1, int lay, int grp)
{
    int flat = fabs(x0 - x1) < 1e-7 && fabs(y0 - y1) < 1e-7;

    if (!flat && fabs(z0 - z1) >= 1e-7 && (z0 <= -1e-7 || z1 <= -1e-7) &&
        (1e-7 <= z0 || 1e-7 <= z1)) {
        /* P = (P1 − P0) / (z1 − z0) * (0 − z0) + P0 （498b00・498b90・4989e0・498a70） */
        double mx = (x1 - x0) / (z1 - z0) * (0.0 - z0) + x0;
        double my = (y1 - y0) / (z1 - z0) * (0.0 - z0) + y0;

        tn_add3(L, x0, y0, z0, mx, my, 0.0, lay, grp);
        tn_add3(L, mx, my, 0.0, x1, y1, z1, lay, grp);
        return;
    }
    tn_add3(L, x0, y0, z0, x1, y1, z1, lay, grp);
}

/* FUN_0073e550: 同じ層・グループで 端を共有する線に同じ建物番号を付ける（再帰） */
static void tn_flood(tn_list3 *L, double x, double y, int lay, int grp, int no)
{
    int i;

    for (i = 0; i < L->nc; i++) {
        tn_l3 *c = &L->c[i];

        if (c->bno >= 1 || c->lay != lay || c->grp != grp)
            continue;
        if (fabs(x - c->x0) < 1e-7 && fabs(y - c->y0) < 1e-7) {          /* FUN_00436970 */
            c->bno = no;
            tn_flood(L, c->x1, c->y1, lay, grp, no);
        } else if (fabs(x - c->x1) < 1e-7 && fabs(y - c->y1) < 1e-7) {
            c->bno = no;
            tn_flood(L, c->x0, c->y0, lay, grp, no);
        }
    }
}

/* FUN_00733e40（中心を原点、半径 +0xa8 = 50） */
static void tn_proj50(const hk_tenku_opts *o, double px, double py, double x, double y, double z,
                      double *ox, double *oy)
{
    double dx = x - px, dy = y - py, az, d, el, r;

    if (z < 0.0)
        z = 0.0;
    if (fabs(dx) < 1e-7 && fabs(dy) < 1e-7) {
        *ox = 0.0;
        *oy = 0.0;
        return;
    }
    az = atan2(dy, dx);
    d = sqrt(dx * dx + dy * dy);
    el = atan2(z, d);
    if (!o->equidist)
        r = cos(el) * TN_A8;
    else
        r = (1.0 - el / 1.5707963267948966) * TN_A8;
    if (o->mirror)
        az = 3.141592653589793 - (az - o->mirror_off);
    for (; 3.141592653589793 < az; az -= 6.283185307179586) { }
    for (; az <= -3.141592653589793; az += 6.283185307179586) { }
    *ox = cos(az) * r;
    *oy = sin(az) * r;
}

typedef struct {
    tn_seg *s;
    int n, cap;
} tn_segs;

static void tn_push(tn_segs *S, double x0, double y0, double x1, double y1, int g, int bno)
{
    if (S->n >= S->cap) {
        int nc = S->cap ? S->cap * 2 : 256;
        tn_seg *p = (tn_seg *)realloc(S->s, (size_t)nc * sizeof *p);

        if (!p)
            return;
        S->s = p;
        S->cap = nc;
    }
    S->s[S->n].x0 = x0;
    S->s[S->n].y0 = y0;
    S->s[S->n].x1 = x1;
    S->s[S->n].y1 = y1;
    S->s[S->n].ground = g;
    S->s[S->n].bno = bno;
    S->n++;
}

/* FUN_004619b0（線 と 線）: 光線 (0,0)-(ex,ey) と 線分の延長の交点。平行なら 0 */
static int tn_isect(double ex, double ey, const tn_seg *s, double *ox, double *oy)
{
    double f0 = s->x1 - s->x0, f1 = s->y1 - s->y0;
    double d4 = (s->y0 - 0.0) * ex - (s->x0 - 0.0) * ey;
    double d5 = (s->y1 - 0.0) * ex - (s->x1 - 0.0) * ey, t;

    if (!(1e-7 < fabs(d4 - d5)) || !(fabs(d4) <= fabs(d4 - d5) * 10000000000.0))
        return 0;
    t = d4 / (d4 - d5);
    *ox = f0 * t + s->x0;
    *oy = f1 * t + s->y0;
    if (fabs(*ox) + fabs(*oy) > 139778713.93879598)
        return 0;
    if (0.0 == ex)
        *ox = 0.0;
    if (0.0 == ey)
        *oy = 0.0;
    if (s->x0 == s->x1)
        *ox = s->x0;
    if (s->y0 == s->y1)
        *oy = s->y0;
    return 1;           /* 原典は線分の外なら 2 を返すが、呼び手は 0 か否かしか見ない */
}

double jw_tenku_ratio(const hk_tenku_opts *o, const hk_edge3 *e, const hk_tenku_base *b, int n,
                      double px, double py, double cx, double cy,
                      double *area, double *hidden, double *hx, int maxh, int *nh)
{
    tn_list3 L = { 0, 0, 0 };
    tn_segs A = { 0, 0, 0 }, B = { 0, 0, 0 };
    int i, k, nb = 0, N, hstep, bdb8 = o->precise ? 1000 : 100;
    double dt, bd30, bd50 = 0.0, b8, pct, *mn = 0, *mx = 0;
    const double becc = 0.017453292519943295;   /* 1°（DAT_00a0bebc が正のとき） */

    if (nh)
        *nh = 0;
    /* 1. 三次元の線（FUN_0073c0c0 の順: 下端・上端・始点の縦・終点の縦） */
    for (i = 0; i < n; i++) {
        double zb0 = b ? b[i].zb0 : 0.0, zb1 = b ? b[i].zb1 : 0.0;
        int w0 = b ? b[i].wall0 : 1, w1 = b ? b[i].wall1 : 1;
        int lay = b ? b[i].lay : 0, grp = b ? b[i].grp : 0;

        if (fabs(e[i].x0 - e[i].x1) + fabs(e[i].y0 - e[i].y1) < 1e-7)   /* FUN_0043acd0 < 1e-7 */
            continue;
        if (w0 && w1)
            tn_add3_split(&L, e[i].x0, e[i].y0, zb0, e[i].x1, e[i].y1, zb1, lay, grp);
        tn_add3_split(&L, e[i].x0, e[i].y0, e[i].z0, e[i].x1, e[i].y1, e[i].z1, lay, grp);
        if (w0 && fabs(e[i].z0 - zb0) > 1e-7)
            tn_add3(&L, e[i].x0, e[i].y0, e[i].z0, e[i].x0, e[i].y0, zb0, lay, grp);
        if (w1 && fabs(e[i].z1 - zb1) > 1e-7)
            tn_add3(&L, e[i].x1, e[i].y1, e[i].z1, e[i].x1, e[i].y1, zb1, lay, grp);
    }
    /* 2. 建物番号（306133〜306178）。1000 を超えると原典は 0x159a を出して止める */
    for (i = 0; i < L.nc; i++)
        if (L.c[i].bno < 1) {
            L.c[i].bno = ++nb;
            tn_flood(&L, L.c[i].x0, L.c[i].y0, L.c[i].lay, L.c[i].grp, nb);
            tn_flood(&L, L.c[i].x1, L.c[i].y1, L.c[i].lay, L.c[i].grp, nb);
        }
    /* 3. 一本ずつ 射影した折れ線（A: +0x190）と 両端を結ぶ弦（B: +0x21c）。306259〜306503 */
    for (i = 0; i < L.nc; i++) {
        tn_l3 c = L.c[i];
        double mxx = (c.x0 + c.x1) / 2.0, myy = (c.y0 + c.y1) / 2.0;
        double fx = mxx - px, fy = myy - py, a18 = 1001.0, a08 = 1001.0, span;
        double sx, sy, ex, ey, bx, by, qx, qy, qz, stx, sty, stz;
        int ground, seg, s;

        /* 中心 → 中点 の向きの右（または上）に終点があれば 入れ替える（FUN_005f8c20 < 1e-7） */
        if (1e-7 <= fabs(fx) + fabs(fy)) {
            double len = sqrt(fx * fx + fy * fy), co = fx / len, si = fy / len;

            if ((c.y1 - py) * co - (c.x1 - px) * si < 1e-7) {
                double t;

                t = c.x0; c.x0 = c.x1; c.x1 = t;
                t = c.y0; c.y0 = c.y1; c.y1 = t;
                t = c.z0; c.z0 = c.z1; c.z1 = t;
            }
        }
        {
            double d22 = c.x0 - px, d23 = c.y0 - py, d24 = c.x1 - px, d25 = c.y1 - py;

            if (1e-7 < fabs(d22) || 1e-7 < fabs(d23)) {
                a18 = atan2(d23, d22);
                if ((fabs(a18) - 3.141592653589793 <= 0.0 ? -(fabs(a18) - 3.141592653589793)
                                                          : fabs(a18) - 3.141592653589793) <= 1e-7)
                    a18 = 3.141592653589793;
            }
            if (1e-7 < fabs(d24) || 1e-7 < fabs(d25)) {
                a08 = atan2(d25, d24);
                if ((fabs(a08) - 3.141592653589793 <= 0.0 ? -(fabs(a08) - 3.141592653589793)
                                                          : fabs(a08) - 3.141592653589793) <= 1e-7)
                    a08 = 3.141592653589793;
            }
        }
        if (1000.0 <= a18 || 1000.0 <= a08)
            a18 = a08 = 0.0;
        else if (1e-7 <= fabs(a18 - a08)) {
            if (a08 < a18)
                a08 += 6.283185307179586;
        } else
            a08 = a18;
        span = fabs(a08 - a18);
        ground = c.z0 < 1e-7 && c.z1 < 1e-7;
        seg = (int)((a08 - a18) / becc) + 1;
        if (ground || seg < 1)
            seg = 1;
        stx = (c.x1 - c.x0) / (double)seg;
        sty = (c.y1 - c.y0) / (double)seg;
        stz = (c.z1 - c.z0) / (double)seg;
        tn_proj50(o, px, py, c.x0, c.y0, c.z0, &sx, &sy);
        bx = sx;
        by = sy;
        qx = c.x0;
        qy = c.y0;
        qz = c.z0;
        for (s = 1; s < seg; s++) {
            qx += stx;
            qy += sty;
            qz += stz;
            tn_proj50(o, px, py, qx, qy, qz, &ex, &ey);
            tn_push(&A, sx, sy, ex, ey, ground, c.bno);
            sx = ex;
            sy = ey;
        }
        tn_proj50(o, px, py, c.x1, c.y1, c.z1, &ex, &ey);
        tn_push(&A, sx, sy, ex, ey, ground, c.bno);
        if (!ground && 1e-7 <= span)
            tn_push(&B, bx, by, ex, ey, 0, c.bno);
    }
    /* 4. 光線ごとに 建物の [最小,最大] 半径（306944〜307113） */
    N = bdb8 * 360;
    dt = 6.283185307179586 / (double)N;
    hstep = (bdb8 / 10) * 20;      /* 塗りは 2° ごと（DAT_00a0bebc = 20 と読める。hk_s2 の答え） */
    mn = (double *)malloc((size_t)(nb + 2) * sizeof *mn);
    mx = (double *)malloc((size_t)(nb + 2) * sizeof *mx);
    b8 = o->R >= 0.4 ? o->R / TN_A8 : 1.0;
    for (i = 0; mn && mx && i < N; i++) {
        double ang = (double)i * dt, ex = cos(ang) * TN_A8, ey = sin(ang) * TN_A8;
        double co = 1.0, si = 0.0, gmin = 9e+20, gmax = -9e+20, ox, oy;
        int found = 0, nslot;

        if (1e-7 <= fabs(ex) + fabs(ey)) {                     /* FUN_005f97f0 */
            double len = sqrt(ex * ex + ey * ey);

            co = ex / len;
            si = ey / len;
        }
        for (k = 0; k < B.n && !found; k++) {
            const tn_seg *s = &B.s[k];

            if (0.0 < (co * s->y0 - si * s->x0) * (co * s->y1 - si * s->x1))
                continue;
            if (co * s->x0 + si * s->y0 < 0.0 && co * s->x1 + si * s->y1 < 0.0)
                continue;
            if (!tn_isect(ex, ey, s, &ox, &oy))
                continue;
            if (co * ox + si * oy < 1e-7)
                continue;
            found = 1;
        }
        if (!found)
            continue;
        for (k = 1; k <= nb; k++) {
            mx[k] = -9e+20;
            mn[k] = 9e+20;
            /* 測定点が建物の中（原典 0x1659/0x165a の問い）で「はい」なら mn = 0。
               問いの判定（306693〜306819）は写していない。原典に確認が要る */
        }
        for (k = 0; k < A.n; k++) {
            const tn_seg *s = &A.s[k];
            double r;

            if (!((co * s->y0 - si * s->x0) * (co * s->y1 - si * s->x1) <= 0.0))
                continue;
            if (!tn_isect(ex, ey, s, &ox, &oy))
                continue;
            r = co * ox + si * oy;
            if (!(1e-7 <= r))
                continue;
            if (s->ground)
                r = TN_A8;
            if (r < gmin)
                gmin = r;
            if (gmax < r)
                gmax = r;
            if (r < mn[s->bno])
                mn[s->bno] = r;
            if (mx[s->bno] < r)
                mx[s->bno] = r;
        }
        if (!(gmin < gmax - 1e-7))
            continue;
        /* 重なる区間をまとめる（307021〜307052） */
        nslot = 0;
        for (k = 1; k <= nb; k++) {
            int more, j;

            if (!(mn[k] < mx[k]))
                continue;
            nslot++;
            mx[nslot] = mx[k];
            mn[nslot] = mn[k];
            more = 1;
            while (more) {
                more = 0;
                for (j = k + 1; j <= nb; j++)
                    if ((mn[nslot] - 1e-7 < mx[j] || mn[nslot] - 1e-7 == mx[j]) &&
                        mn[j] <= mx[nslot] + 1e-7) {
                        if (mx[nslot] < mx[j])
                            mx[nslot] = mx[j];
                        if (mn[j] < mn[nslot])
                            mn[nslot] = mn[j];
                        more = 1;
                        mx[j] = -9e+20;
                        mn[j] = 9e+20;
                    }
            }
        }
        for (k = 1; k <= nslot; k++) {
            double lo = mn[k], hi = mx[k];

            if (!(lo < hi - 1e-7))
                continue;
            if (!o->equidist)
                bd50 = ((dt * hi * hi) / 2.0 + bd50) - (dt * lo * lo) / 2.0;
            else {
                double z = (lo / TN_A8) * 1.5707963267948966, z1 = (hi / TN_A8) * 1.5707963267948966;
                double w = dt * TN_A8, prev = sin(z) * w, acc = 0.0;

                while (z < z1 - 1e-7) {
                    double zp = z, v;

                    z += 0.0017453292519943296;
                    if (z1 < z)
                        z = z1;
                    v = sin(z) * w;
                    acc = ((v + prev) * (z - zp) * TN_A8) / 2.0 + acc;
                    prev = v;
                }
                bd50 += acc;
            }
            if (hx && nh && i % hstep == 0 && *nh < maxh) {     /* 塗りの線 (307083〜307107) */
                double *h = hx + 4 * *nh;

                h[0] = co * lo * b8 + cx;
                h[1] = si * lo * b8 + cy;
                h[2] = co * hi * b8 + cx;
                h[3] = si * hi * b8 + cy;
                (*nh)++;
            }
        }
    }
    free(mn);
    free(mx);
    free(L.c);
    free(A.s);
    free(B.s);
    /* 5. 面積と率（307115〜307148） */
    bd30 = !o->equidist ? TN_A8 * 3.141592653589793 * TN_A8 : TN_A8 * 6.283185307179586 * TN_A8;
    bd30 = b8 * b8 * bd30;
    bd50 = b8 * b8 * bd50;
    pct = ((bd30 - bd50) * 100.0) / bd30;
    if (!o->precise) {
        if (24.99 < pct && pct < 25.01) pct = 25.0;
        if (49.99 < pct && pct < 50.01) pct = 50.0;
        if (74.99 < pct && pct < 75.01) pct = 75.0;
        pct = (double)(int)(100.0 * pct + 0.5) / 100.0;
    } else {
        if (24.999 < pct && pct < 25.001) pct = 25.0;
        if (49.999 < pct && pct < 50.001) pct = 50.0;
        if (74.999 < pct && pct < 75.001) pct = 75.0;
        pct = (double)(int)(1000.0 * pct + 0.5) / 1000.0;
    }
    if (area)
        *area = bd30;
    if (hidden)
        *hidden = bd50;
    return pct;
}

int jw_tenku_draw_edges(jw_drawing *d, const hk_tenku_opts *o,
                        const hk_edge3 *e, int n,
                        double px, double py, double cx, double cy, double *pct)
{
    return jw_tenku_draw_edges2(d, o, e, NULL, n, px, py, cx, cy, pct);
}

/* 目盛の円と放射線の線種: 30° の倍数は 1、10° の倍数は 4、ほかは 2（5°・15°…、原典 hk_rg1〜rg5） */
static int tick_ltype(double a)
{
    if (fabs(fmod(a + 1e-9, 30.0)) < 2e-9)
        return 1;
    if (fabs(fmod(a + 1e-9, 10.0)) < 2e-9)
        return 4;
    return 2;
}

int jw_tenku_draw_edges2(jw_drawing *d, const hk_tenku_opts *o,
                         const hk_edge3 *e, const hk_tenku_base *bb, int n,
                         double px, double py, double cx, double cy, double *pct)
{
    int start = d->ndrawn, i, slot = 1, r;
    double size = o->size_class == 2 || o->size_class < 1 ? 2.5 : 2.5;
    double ty = cy - o->R - 3.75;
    char buf[160];
    double v = 100.0, area = 0.0, hid = 0.0, *hx = 0;
    int nh = 0;

    if (o->calc || pct) {
        /* 天空率は 原典と同じ 射影した折れ線 × 光線 の足し上げ（jw_tenku_ratio、FUN_00748da0） */
        hx = (double *)malloc(4 * 4096 * sizeof *hx);
        v = jw_tenku_ratio(o, e, bb, n, px, py, cx, cy, &area, &hid, hx, hx ? 4096 : 0, &nh);
        if (pct)
            *pct = v;
    }
    add_circle(d, cx, cy, o->R, 0, 0);
    if (o->interval > 0.0) {
        double a;
        int k;

        for (a = o->interval; a < 90.0 - 1e-9; a += o->interval) {
            add_circle(d, cx, cy, radius_of(o, a * PI / 180.0), 1, tick_ltype(a));
        }
        for (k = 0; k * o->interval < 360.0 - 1e-9; k++) {
            double ang = k * o->interval, rad = ang * PI / 180.0;
            add_line(d, cx, cy, cx + o->R * cos(rad), cy + o->R * sin(rad), 1, tick_ltype(ang), 0);
        }
    }
    if (o->sun) {
        /* 太陽軌跡 は円のすぐあと、建物の線の前（原典 hk_s5）。字の段は (2.5 + 2) 下がり
           （FUN_0073ea50 の +0x1b90 −= 字の高さ + 2）、一段目に「緯度 = 36°」。
           目盛・天空率計算・測定点表示 と一緒のときの並びは 原典に確認が要る */
        sun_path(d, o, px, py, cx, cy, size);
        ty -= size + 2.0;
    }
    if (o->show_point && o->calc)
        point_mark(d, o, px, py, size);
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
        if (o->sun) {
            /* 「緯度 = 36°」は 測定点 No.n の字のあと、測定面の字の前（原典 hk_s15・s16。
               天空率計算 と 測定点表示 を両方入れたときは 原典に確認が要る） */
            sun_lat_text(d, o, cx, ty - 3.75 * (slot - 1), size);
            slot++;
        }
        if (o->show_plane) {
            snprintf(buf, sizeof buf, "%s " S_ZEN S_SOKUTEIMEN " = %.3f m",
                     o->equidist ? "[" S_TOUKYORI "]" : S_SHASHAEI, o->plane_m);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        /* 塗り: 2° ごとの光線で 隠れる区間（まとめた区間ごとに一本、307083〜307107） */
        for (i = 0; i < nh; i++)
            add_line(d, hx[4 * i], hx[4 * i + 1], hx[4 * i + 2], hx[4 * i + 3], 1, 1, 0x20);
        if (o->show_area) {
            /* 射影面積表示 (1324): 二つの面積を %.6lg（高精度は %.7lg）で丸めて読み直し、
               " %.15lg" で書く（307149〜307234）。率が 50 なら 隠れる面積 = 全体/2、
               0 なら 全体（丸めた全体から）。字は 0x1b5e「【」0x1664「水平円射影面積」
               （等距離は 0x1665「半球射影表面積」）" ," 0x1b58「】」。原典 hk_s4 */
            char t1[64], t2[64];
            const char *fmt = o->precise ? "%.7g" : "%.6g";

            snprintf(t1, sizeof t1, fmt, area);
            area = strtod(t1, NULL);
            if (fabs(v - 50.0) < 1e-7)
                hid = area / 2.0;
            if (v < 1e-7)
                hid = area;
            snprintf(t2, sizeof t2, fmt, hid);
            hid = strtod(t2, NULL);
            snprintf(buf, sizeof buf, S_KAKKO0 "%s %.15g , %.15g" S_KAKKO1,
                     o->equidist ? S_HANKYU : S_SUIHEIEN, area, hid);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        /* 等距離では 0x1653「[天空比]」（307174〜307185。原典の答えはまだ無い） */
        snprintf(buf, sizeof buf, "%s = %.*f %%", o->equidist ? "[" S_TENKUHI "]" : S_TENKURITSU,
                 o->precise ? 3 : 2, v);
        add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
        r = skyline(d, o, e, n, px, py, cx, cy);
        if (r < 0) {
            free(hx);
            return -1;
        }
    } else {
        /* [hk_s1] circle, skyline, then the texts.  測定点表示 の点と「No.n」は
           skyline のあと、文字の前（原典 hk_s9） */
        r = skyline(d, o, e, n, px, py, cx, cy);
        if (r < 0) {
            free(hx);
            return -1;
        }
        if (o->show_point)
            point_mark(d, o, px, py, size);
        if (o->show_point) {
            if (o->interval > 0.0)
                snprintf(buf, sizeof buf, S_SOKUTENN " No.%d " S_ZEN S_MEMORI " %g" S_DEG,
                         o->number, o->interval);
            else
                snprintf(buf, sizeof buf, S_SOKUTENN " No.%d", o->number);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        if (!o->show_point && o->interval > 0.0) {
            /* 目盛間隔 は 測定点表示がなければ 単独の字（「目盛間隔 10゜」、5 は「 5」と桁を揃える、hk_s28・iv*） */
            snprintf(buf, sizeof buf, S_MEMORI " %2g" S_DEG, o->interval);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
        if (o->sun) {
            /* 「緯度 = 36°」は 測定点 No.n の字のあと、測定面の字の前（原典 hk_s15・s16。
               天空率計算 と 測定点表示 を両方入れたときは 原典に確認が要る） */
            sun_lat_text(d, o, cx, ty - 3.75 * (slot - 1), size);
            slot++;
        }
        if (o->show_plane) {
            snprintf(buf, sizeof buf, "%s " S_ZEN S_SOKUTEIMEN " = %.3f m",
                     o->equidist ? "[" S_TOUKYORI "]" : S_SHASHAEI, o->plane_m);
            add_text(d, buf, cx, ty - 3.75 * (slot - 1), 1, size, 1, 2);
            slot++;
        }
    }
    free(hx);
    return d->ndrawn - start;
}

int jw_tenku_draw(jw_drawing *d, const hk_tenku_opts *o,
                  double px, double py, double cx, double cy, double *pct)
{
    static hk_edge3 e[1000];
    static hk_tenku_base b[1000];
    int n = jw_tenku_collect2(d, o->plane_m, e, b, 1000);

    if (n < 1)
        return n < 0 ? -1 : -2;
    return jw_tenku_draw_edges2(d, o, e, b, n, px, py, cx, cy, pct);
}

/* ------------------------------------------------------------------ */
/* 天空率比較計算 (1066)。原典の答え tools/tnbatch4.sh → decomp/res/hk_tc1〜tc3。 */
#define S_SANSHAKEI  "\x8e\x4f\x8e\xce\x8c\x76\x8e\x5a"      /* 0x1672 三斜計算 */
#define S_LT         "\x81\x83"                              /* 0x16a5 ＜ */
#define S_EQ         "\x81\x81"                              /* 0x180b ＝ */

int jw_tenku_cmp_parse(const char *s, double *val, int *dec, int *sansha)
{
    /* FUN_0074e1c0: 天空率 (0x1652)・"="（0x95bbfc）・"%"（0x95bc08）の位置が
       どれも 0 以上で、% が = より後。= の次から % の前までを取り、後ろの空白を落とし、
       "."（0x95bcc4）の後ろの桁数を数える。等距離の「[天空比]」は 天空率 を含まないので
       ここで落ちる（原典に確認が要る） */
    const char *t = strstr(s, S_TENKURITSU), *eq, *pc, *dot;
    char buf[64];
    size_t n;

    if (!t)
        return 0;
    eq = strchr(s, '=');
    pc = strchr(s, '%');
    if (!eq || !pc || pc <= eq)
        return 0;
    n = (size_t)(pc - eq - 1);
    if (n >= sizeof buf)
        n = sizeof buf - 1;
    memcpy(buf, eq + 1, n);
    buf[n] = 0;
    while (n > 0 && buf[n - 1] == ' ')
        buf[--n] = 0;
    if (n == 0)
        return 0;
    *val = atof(buf);
    dot = strchr(buf, '.');
    *dec = dot ? (int)(n - (size_t)(dot - buf) - 1) : 0;
    if (sansha && strstr(s, S_SANSHAKEI))
        *sansha = 1;
    return 1;
}

void jw_tenku_cmp_write(jw_drawing *d, double plan, double cmp, int dec, int sansha,
                        double ax, double ay, double bx, double by, double x, double y)
{
    /* FUN_00737bf0（_unassigned.c 300962〜） */
    double diff = fabs(plan) - fabs(cmp), dx = ax - bx, dy = ay - by;
    double th, ang, w, h, sp, cx, cy, ox, oy, a, b;
    int col, n = 3;
    char buf[64];
    jw_obj *o;

    /* 二つの字が横に並ぶ（|dy| < |dx| − 1e-7）なら 字は 90°、記号は 0°／180°。
       縦に並ぶなら 字は 0°、記号は 90°／−90°（hk_tc1〜tc3 は縦だけ。横は原典に確認が要る） */
    if (fabs(dy) < fabs(dx) - 1e-7) {
        th = 90.0;
        ang = 180.0;
        if (0.0 <= dx ? 0.0 < diff : diff < 0.0)
            ang = 0.0;
    } else {
        th = 0.0;
        ang = 90.0;
        if (dy <= 0.0 ? 0.0 < diff : diff < 0.0)
            ang = -90.0;
    }
    /* 文字種は DAT_00a0beb8 / 100（1〜10 でなければ 3）。移植は 3 に決め打ち（原典に確認が要る） */
    w = d->style[n - 1].w;
    h = d->style[n - 1].h;
    sp = d->style[n - 1].sp;
    col = d->style[n - 1].color;
    /* 許し: DAT_00a0bec4 / 10 が 1 以上で 三斜計算 でなければ n/1000（既定 0.02）。
       そうでなければ 差 ≤ 1e-7 で 文字種 0・色 8。hk_tc1（−0.06）・tc3（0）は 色 8、
       tc2（+0.06）は 文字種 3 のまま。どちらの枝かは答えから分からない（原典に確認が要る） */
    (void)sansha;
    if (diff <= 1e-7) {
        n = 0;
        col = 8;
    }
    /* 数値: 桁 3 未満は %.2lf、ほかは %.3lf。左中に置く（hk_tc1: 原点は (x, y − h/2)） */
    snprintf(buf, sizeof buf, dec < 3 ? "%.2f" : "%.3f", diff);
    a = th * PI / 180.0;
    o = jw_add(d, JW_MOJI);
    if (!o)
        return;
    {
        int k = halves(buf);
        double len = k * w / 2.0 + (k > 1 ? (k - 1) * sp / 2.0 : 0.0);

        ox = x + h / 2.0 * sin(a);
        oy = y - h / 2.0 * cos(a);
        o->color = (unsigned short)col;
        o->ltype = 4;
        o->d[0] = ox;
        o->d[1] = oy;
        o->d[2] = ox + len * (fabs(cos(a)) < 1e-12 ? 0.0 : cos(a));
        o->d[3] = oy + len * (fabs(sin(a)) < 1e-12 ? 0.0 : sin(a));
        o->d[4] = w;
        o->d[5] = h;
        o->d[6] = sp;
        o->d[7] = th;
        o->n = n;
        o->text = jw_add_str(d, buf);
        o->face = jw_add_str(d, S_FACE);
    }
    /* 記号: 中心は 結果の位置から 2.2 × 幅 だけ 字の向きの逆へ。そこから 記号の向き ang に
       応じた角へ（0x738630〜0x7387f0）。|差| < 1e-7 なら ＝、ほかは ＜ */
    cx = x - 2.2 * w * cos(a);
    cy = y - 2.2 * w * sin(a);
    a = w / 2.0;
    b = h / 2.0;
    {
        double p = a, q = b;            /* local_6578, local_6570 */

        if (-0.1 < ang) {
            p = -b;
            q = a;
        }
        q = -q;
        if (89.0 < ang) {
            p = -a;
            q = b;
        }
        if (179.0 < ang) {
            p = b;
            q = a;
        }
        ox = cx + q;
        oy = cy + p;
    }
    o = jw_add(d, JW_MOJI);
    if (!o)
        return;
    {
        double r = ang * PI / 180.0, c = cos(r), s = sin(r);

        if (fabs(c) < 1e-12)
            c = 0.0;
        if (fabs(s) < 1e-12)
            s = 0.0;
        o->color = (unsigned short)col;
        o->ltype = 5;
        o->d[0] = ox;
        o->d[1] = oy;
        o->d[2] = ox + c * w;
        o->d[3] = oy + s * w;
        o->d[4] = w;
        o->d[5] = h;
        o->d[6] = sp;
        o->d[7] = ang;
        o->n = n;
        o->text = jw_add_str(d, fabs(diff) < 1e-7 ? S_EQ : S_LT);
        o->face = jw_add_str(d, S_FACE);
    }
}
