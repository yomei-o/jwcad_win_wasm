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
    int show_area;      /* 射影面積表示 (1324): 「【水平円射影面積 A , H】」 (calc のときだけ) */
    /* 太陽軌跡 (1325)、FUN_0073ea50。原典 hk_s5〜s8 */
    int sun;            /* 太陽軌跡を描く */
    int sun10;          /* 10分間隔点表示 (2113): 10 分ごとに点（色 1） */
    int shiki;          /* 四季 (2115): 冬至・春秋分・夏至 の三本 */
    int sun_n15;        /* 9～15時（doc+0x83d0）: ±180 分、字は 9 と 15 */
    double lat;         /* 緯度（doc+0x83c0）、度 */
    double dec;         /* 日赤緯（doc+0x83c8）、度。±23.45 に切る */
    int inside_yes;     /* 測定点が建物の内側のときの問い（0x1659）に「はい」: その建物の最小半径を 0 に */
    double north;       /* 真北（doc+0x1b80、旗 0x40 の数の字）、度。無ければ 0（上向き扱い） */
} hk_tenku_opts;

/* 稜線ごとの 壁の下端（原典 FUN_0073dc40 / FUN_0073c0c0）。jw_tenku_collect2 が
   高さの文字から作る。NULL を渡す口では 両端とも 地面（下端 0）から立つ壁とみなす。 */
typedef struct {
    double zb0, zb1;    /* 下端の高さ（図面の単位、測定面から）。負は地面と同じ扱い */
    int wall0, wall1;   /* その端の文字が下端を持つ（値が二つ、または一つで 0 以上） */
    int lay, grp;       /* 層と層グループ（建物は 同じ層・同じグループで端がつながる線） */
} hk_tenku_base;

/* 天空率の計算（原典 FUN_00748da0 の後半、_unassigned.c 306880〜307169）。
   area / hidden は 射影面積表示 に出す二つ（丸める前）、戻り値は 天空率 %（丸めた後）。
   hx[] には 塗りの線（2° ごとの光線で 隠れる区間）を (x0,y0,x1,y1) で max 本まで返す。 */
double jw_tenku_ratio(const hk_tenku_opts *o, const hk_edge3 *e, const hk_tenku_base *b, int n,
                      double px, double py, double cx, double cy,
                      double *area, double *hidden, double *hx, int maxh, int *nh);

/* 測定点が建物の内側か線の上にあるか（原典の問い 0x1659 を出す条件。FUN_00748da0 306693〜306819） */
int jw_tenku_inside(const hk_tenku_opts *o, const hk_edge3 *e, const hk_tenku_base *b, int n,
                    double px, double py);

/* 三次元の線（下端・上端・縦）を x0,y0,z0,x1,y1,z1,建物番号 の 7 つずつ out に。日影図の 確認 の窓 */
int jw_tenku_lines3(const jw_drawing *d, double plane_m, double *out, int max);

/* The state the probe hk_s1 was taken in. */
void hk_tenku_opts_default(hk_tenku_opts *o);

/* Collect the 3-D wire frame the original builds from the height texts
 * (flags 0x80 at both ends of a line, same layer and group).  Heights are in
 * drawing units above the measuring plane.  Returns the number of edges
 * (<= max); -1 if layer groups of different scale are involved (message
 * 0x1596 in the original). */
int jw_tenku_collect(const jw_drawing *d, double plane_m, hk_edge3 *e, int max);
/* the same, also filling b[] (may be NULL) with the wall bottoms and layer/group */
int jw_tenku_collect2(const jw_drawing *d, double plane_m, hk_edge3 *e, hk_tenku_base *b, int max);

/* Draw the diagram for the given wire frame.  (px,py) is the measuring point,
 * (cx,cy) the circle centre, both in drawing mm.  Appends to d the objects the
 * original writes, in its order.  If pct != NULL it receives the 天空率 in
 * percent (rounded the way the original does).  Returns the number of objects
 * appended, or -1 on failure. */
int jw_tenku_draw_edges(jw_drawing *d, const hk_tenku_opts *o,
                        const hk_edge3 *e, int n,
                        double px, double py, double cx, double cy, double *pct);
/* the same with the wall bottoms (b may be NULL) */
int jw_tenku_draw_edges2(jw_drawing *d, const hk_tenku_opts *o,
                         const hk_edge3 *e, const hk_tenku_base *b, int n,
                         double px, double py, double cx, double cy, double *pct);

/* jw_tenku_collect + jw_tenku_draw_edges.  Returns -2 when there is no
 * usable height data (the original: message 0x1592 / 0x1599, nothing drawn). */
int jw_tenku_draw(jw_drawing *d, const hk_tenku_opts *o,
                  double px, double py, double cx, double cy, double *pct);

/* 天空率比較計算 (1066)。CZukeiTenkuu の +0xbc = 5 の歩み（FUN_00739bd0 の 0x1b0 = 0/1/2）。
 * 字「… 天空率 … = 数値 … %」から数値と小数の桁を読む（FUN_0074e1c0）。天空率でなければ 0
 * （原典は 0x16a4「天空率ではありません」）。三斜計算 の字なら *sansha = 1（+0x82c）。 */
int jw_tenku_cmp_parse(const char *s, double *val, int *dec, int *sansha);
/* 結果を書く（FUN_00737bf0）。(ax,ay)・(bx,by) は 計画・比較 の字の位置、(x,y) は 結果の位置
 * （数値左中）。差 |計画| − |比較| を %.2lf（桁 3 以上なら %.3lf）で、その前に ＜ か ＝ を置く。 */
void jw_tenku_cmp_write(jw_drawing *d, double plan, double cmp, int dec, int sansha,
                        double ax, double ay, double bx, double by, double x, double y);

#endif
