/* tenku.h -- what the ORIGINAL 天空図 command (32971) writes into the drawing
 * for the two clicks 測定点 and 円中心.  Pure: no dependence on cmd.c, only on
 * the jw_drawing types and on src/hikage.h (hk_tenkuu_project, hk_skyline_el,
 * hk_sky_ratio ...).
 *
 * Verified against decomp/res/hk_s1.jww (正射影, defaults, one 200 px box of
 * height 10 m, point (500,600) px, centre (900,300) px) -- every object -- and,
 * for the calc/point-display variant, against the first diagram of
 * orig/天空率表.jww (see tests/tenku_test.c).
 */
#ifndef TENKU_H
#define TENKU_H

#include "jww.h"
#include "hikage.h"

typedef struct {
    double plane_m;     /* 測定高 (bar 1492), metres; default 0 */
    double R;           /* 天空図の半径 mm (bar 1493 is the radius -- 原典 hk_s11); default 25 */
    int equidist;       /* 0 正射影 (1064), 1 等距離射影 (1065) */
    int mirror;         /* 南方向補正 (1326) */
    double mirror_off;  /* its offset, radians; 0 */
    double interval;    /* 目盛間隔 in degrees (combo 2209); 0 = none (hk_s1) */
    int calc;           /* 天空率計算 (1323): hatch + 天空率 text, texts first */
    int precise;        /* 高精度 (1327): 360000 steps, 3 decimals */
    int show_point;     /* 測定点表示 (2215/2216): marker, "No.n", "測定点 No.n" */
    int number;         /* the point number n of "No.n" (first = 1) */
    int show_plane;     /* 測定面高表示 (1328): the "正射影 　測定面高さ = .." text */
    int size_class;     /* text size class (doc+0x83ac); 2 = 2.5 mm */
    int base_group;     /* unused, reserved */
} hk_tenku_opts;

/* The state the probe hk_s1 was taken in. */
void hk_tenku_opts_default(hk_tenku_opts *o);

/* Collect the 3-D wire frame the original builds from the height texts
 * (flags 0x80 at both ends of a line, same layer and group).  Heights are in
 * drawing units above the measuring plane.  Returns the number of edges
 * (<= max); -1 if layer groups of different scale are involved (message
 * 0x1596 in the original). */
int jw_tenku_collect(const jw_drawing *d, double plane_m, hk_edge3 *e, int max);

/* Draw the diagram for the given wire frame.  (px,py) is the measuring point,
 * (cx,cy) the circle centre, both in drawing mm.  Appends to d the objects the
 * original writes, in its order.  If pct != NULL it receives the 天空率 in
 * percent (rounded the way the original does).  Returns the number of objects
 * appended, or -1 on failure. */
int jw_tenku_draw_edges(jw_drawing *d, const hk_tenku_opts *o,
                        const hk_edge3 *e, int n,
                        double px, double py, double cx, double cy, double *pct);

/* jw_tenku_collect + jw_tenku_draw_edges.  Returns -2 when there is no
 * usable height data (the original: message 0x1592 / 0x1599, nothing drawn). */
int jw_tenku_draw(jw_drawing *d, const hk_tenku_opts *o,
                  double px, double py, double cx, double cy, double *pct);

#endif
