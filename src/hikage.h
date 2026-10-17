/* hikage_core.h -- pure computations behind Jw_cad 10.03.6 日影図 (CZukeiHikage /
 * CZukeiKage1..3) and 天空図 (CZukeiTenkuu).  No UI, no document access.
 *
 * Provenance tags used in the comments:
 *   [D addr]  read from the decompilation (function address)
 *   [V sample] cross-checked against a drawing written by the ORIGINAL program
 *             (orig/日影図.jww, orig/天空率表.jww) -- see hikage_core_test.c
 *   [G]       guess / not bit-exact
 *
 * All lengths in the "drawing unit" of the .jww (paper mm); heights in metres
 * unless a name ends in _mm (= drawing units, i.e. (m)*1000/scale_den).
 */
#ifndef HIKAGE_CORE_H
#define HIKAGE_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------ */
/* 1. sun / shadow vector                                              */
/* ------------------------------------------------------------------ */
typedef struct { double c3, c4, c5, c6, c7; } hk_sun;

/* [D 0x00542070][V sample] lat/dec in degrees; NOTE the constant 0.0174533
 * (not pi/180). */
void hk_sun_init(hk_sun *s, double lat_deg, double dec_deg);

/* [D 0x00542180][V sample] t_sec = seconds from solar noon (negative before
 * noon).  Unit-height shadow tip offset in the TRUE-NORTH frame (x = east,
 * y = north).  Returns 1; (0,0) when |sin(alt)| < 1e-7. */
int hk_sun_shadow(const hk_sun *s, int t_sec, double *x, double *y);

/* Solar altitude is asin(cos(w)*c4 + c7), w = t_sec * 7.272205e-05. [D 0x00542180] */
double hk_sun_sin_alt(const hk_sun *s, int t_sec);

/* [D 0x0053ea50] used by the 壁面 mode: exact pi/180 (NOT 0.0174533 as in hk_sun_*):
 * mult = cot(alt) (shadow length multiplier), (sa,ca) = unit horizontal direction terms
 * sin(w)*cos(dec)/cos(alt) and (sin(alt)sin(lat)-sin(dec))/(cos(alt)cos(lat)); returns
 * sign of (wall_dx*ca - wall_dy*sa)*100: -1 if < 0, 0 if <= 0.001, else 1.  [G: sign meaning] */
int hk_wall_sun_side(double lat_deg, double dec_deg, int t_sec, double wall_dx, double wall_dy,
                     double *mult, double *sa, double *ca);

/* [D 0x00541130] 壁面日影: 壁の線 (x0,y0)-(x1,y1) に対し 建物の高さの字の点 (px,py) がどちら側か。
 * 距離は FUN_005f8c20(1,…) = (y−y0)cos − (x−x0)sin（線の向きの単位ベクトル）、|d| < 0.1 は数えない。
 * 数えた点が無ければ -1（原典は 0x1599「データが不適当」）、全部が同じ側なら 0、
 * 両側にあれば 1（原典は 0x159b「作図する方向を マウスで指示」へ）。 */
int hk_wall_sides(double x0, double y0, double x1, double y1,
                  const double *px, const double *py, int n);
/* 同じで、最初に数えた点の側（1 = 左・-1 = 右・0 = 無し）も返す。原典は 片側のとき 左（> 0）なら
 * 壁の線の始点と終点を入れ替える（FUN_00541130 の末尾）。 */
int hk_wall_sides_ex(double x0, double y0, double x1, double y1,
                     const double *px, const double *py, int n, int *first);

/* 壁面日影（逆コンパイルの読み、原典では押していない）。壁は 向きを決めたあとの線で、
 * 建物（影を落とす側）は 右（FUN_005f8c20 の距離 < 0）、壁の立面は 左へ倒して書く。
 *   [D 0x00542310] 模型を作るとき FUN_005f9950 で壁の枠（始点・単位の向き・長さ）を作り、
 *                  辺ごとに FUN_005415e0 で 壁で切る。切った点（印 -1）は 組ごとに
 *                  壁に沿った位置の順につなぐ（閉じる辺）。
 *   [D 0x0053fee0] 時刻ごとに 壁の面に日が当たるか（ux*sy*100 − uy*sx*100 > 1e-5）を見て、
 *                  当たらなければ その時刻は 線を書かない（等時間は 全部の格子に 1、指定点は 影）。
 *                  外形の点は FUN_00545fc0 で 壁の立面へ移し、壁を横切る辺は 壁の上で切る。
 *   [D 0x0053f880] 線は FUN_0053e800 で 壁の左（立面の側）と 壁の両端の間に切る。 */
typedef struct hk_wall_s {
    double x0, y0, x1, y1;      /* 壁（文書の座標） */
    double ux, uy, len;         /* 単位の向きと長さ（FUN_005f97f0） */
    double north, ox, oy;       /* 模型の枠: 真北の角度で回し、いちばん下の頂点が原点（±2000 の検査） */
    int ends;                   /* 切った点が 壁の端の 0.1 以内（原典 +0x4a528） */
    int flag;                   /* 文書 +0x83d8（jwf の FLG_1 の二つ目、ふつう 0） */
} hk_wall;

void hk_wall_init(hk_wall *w, double x0, double y0, double x1, double y1, double north);
/* その時刻に 壁の面に日が当たるか（FUN_0053fee0 の入口）。(sx,sy) は 文書の向きの影 */
int hk_wall_lit(const hk_wall *w, double sx, double sy);
/* FUN_00545fc0: 地面の影の点を 壁の立面へ。*side は 壁の左の距離 × 壁の長さ（> 1 なら移す） */
void hk_wall_lift(const hk_wall *w, double sx, double sy, double px, double py,
                  double *ox, double *oy, double *side);
/* lift の逆: 立面の点 (x,y) が どの地面の点の影か（指定点・等時間の数え上げ） */
void hk_wall_unlift(const hk_wall *w, double sx, double sy, double x, double y,
                    double *px, double *py);
/* FUN_0053f880 の 壁の切り取り（FUN_0053e800 を 3 回）。残れば 1。tol は 端の許し（ふつう 100） */
int hk_wall_cut(const hk_wall *w, double tol, double *x0, double *y0, double *x1, double *y1);

/* [D 0x00694840][V sample]  影倍率 = hypot(x,y); azimuth (deg, as printed in the
 * 方位角倍率図) = atan2(-x, y) in degrees. */
double hk_shadow_mult(double x, double y);
double hk_shadow_az_deg(double x, double y);

/* [D 0x00694520][V sample] "-53ﾟ20'" formatting.  mode 0 = deg + minutes,
 * 1 = deg min sec, 2 = "%.2lf".  flip=1 for the azimuth table (sign '-' when
 * v > 0, i.e. before noon), flip=0 means '-' when v < 0.  out is UTF-8 here
 * (the original writes the half-width semi-voiced mark U+FF9F). */
void hk_fmt_angle(char *out, int outsz, int flip, int mode, double v);

/* [D 0x0053edd0] label of the hour lines: "%.1lf", or "%.2lf" if
 * (int)(v*100)%10 > 0, or "%.3lf" if (int)(v*1000)%10 > 0. [V sample "9.25"] */
void hk_fmt_hour_label(char *out, int outsz, double hour);

/* ------------------------------------------------------------------ */
/* 2. height texts, layer levels, north                                */
/* ------------------------------------------------------------------ */

/* [D 0x00542310 call site 0x542974: swscanf(s,"%lg,%lg")] after deleting every
 * ' ' (0x20).  Returns the scanf count (0,1,2; -1 for an empty string = EOF).
 * *h1 defaults to 0.0, *h2 defaults to -9.0 (DAT_009682f0). */
int hk_parse_height_text(const char *s, double *h1, double *h2);

/* [D 0x0045d240] "#lv<number>" layer / layer-group name -> level in metres, 0
 * if the name does not start with "#lv" (and is longer than 3). */
double hk_level_from_name(const char *name);

/* [D 0x00542310 @0x542a00-0x542a50] vertex height in drawing units:
 *   z = (|h| + base - plane_m) * 1000 / scale_den, clamped to >= 0.
 * base = level(group name) + level(layer name). */
double hk_vertex_z_mm(double h, double base_m, double plane_m, double scale_den);

/* [D 0x00692820 mode 4/5][V sample 15.000000] North angle from a picked line:
 * the end nearest to the click is E; the vector from E to the other end is
 * (dx,dy); north = atan2(dy,dx)*180/pi + 90, wrapped into (-180,180]. */
double hk_north_deg(double ex, double ey, double ox, double oy);

/* rotate (x,y) CCW by deg (the shadow vector is rotated by the north angle) [V sample] */
void hk_rot(double x, double y, double deg, double *ox, double *oy);

/* ------------------------------------------------------------------ */
/* 3. shadow of a wire-frame building                                  */
/* ------------------------------------------------------------------ */
typedef struct { double x, y; } hk_pt;
/* heights relative to the measuring plane。za_mm・zb_mm は 両端の上の高さ（+0x7e98）、
 * ba_mm・bb_mm は 下の高さ（+0xbde0。浮いた建物。0 は地面）。 */
typedef struct { hk_pt a, b; double za_mm, zb_mm, ba_mm, bb_mm; } hk_edge;
typedef struct { hk_pt p[4]; } hk_quad;

/* swept quad of every edge: a, b, b + zb*s, a + za*s   (s = rotated shadow
 * vector per drawing-unit of height) [V sample: all 20 N0.x lines + 18 outlines] */
int  hk_build_quads(const hk_edge *e, int n, double sx, double sy, hk_quad *q);
int  hk_point_in_quads(const hk_quad *q, int n, double px, double py);

/* One time of 日影図 (button 日影図): the boundary of the union of the quads,
 * minus the pieces that lie on a plan edge of the building, merged into maximal
 * straight runs, oriented clockwise (shadow region on the right hand) and
 * chained.  Writes segments into out[] grouped in chains: chain_start[i]=1 for
 * the first segment of every chain.  Returns the number of segments.
 * [V sample: the 18 outlines of 日影図.jww reproduce within 0.02 mm] The chain
 * start vertex of the original is the tangent vertex where the shadow leaves
 * the footprint; ordering (not geometry) is [G] for several buildings. */
typedef struct { hk_pt a, b; } hk_seg;
int  hk_outline(const hk_edge *e, int n, double sx, double sy,
                hk_seg *out, int *chain_start, int maxout);
/* FUN_005415e0 と 閉じる辺。out に 切った辺を書き、数を返す。原典の札で終わるときは
 * -5534（0x159e「壁面線が建物通過」）か -5532（0x159c「中庭等、建物を分割してください」）。
 * 模型の枠の原点（w->ox, oy）と w->ends もここで決める。 */
int hk_wall_clip(hk_wall *w, const hk_edge *in, int n, hk_edge *out, int maxout);
/* 壁面日影の 一時刻: 外形の線を 壁の立面へ移して切る（FUN_0053fee0 の壁の枝と FUN_0053f880）。
 * lab[k] = 1 は 時刻の文字を付ける線（数えが 0 から 1 になった線: 原典は 線が切り捨てられるか
 * 鎖が切れると 数えを 0 に戻し、壁のときは 1 本目に付ける）。返り値は 線の数、日が当たらなければ 0。 */
int  hk_wall_segs(const hk_wall *w, double sx, double sy, const hk_seg *in, const int *chain_start,
                  int n, hk_seg *out, int *lab, int maxout);

/* Index (1-based, within the chain) of the segment that carries the hour label:
 * 2 if hour <= 12.0 else 3 (this[0x1291f], [D 0x0053edd0]). [V sample] */
int  hk_label_segment_index(double hour);

/* Position of the label on a segment (a->b), text width w:
 *   start = a + u*(len-w)/2 + n*0.5, end = start + u*w,   u = unit dir, n = (-uy,ux)
 * angle = atan2(uy,ux).  [D 0x005459b0][V sample "8.0"] */
void hk_label_place(hk_pt a, hk_pt b, double w, hk_pt *start, hk_pt *end, double *angle_deg);

/* ------------------------------------------------------------------ */
/* 4. 指定点 (Kage3): shadow time list of a measuring point            */
/* ------------------------------------------------------------------ */
typedef struct { int start, end; } hk_interval;   /* seconds from noon */

/* in[i] = point in shadow at t = tbegin + i*step (i = 0..n-1, last t == tend).
 * Implements the interval bookkeeping of FUN_005470d0: an interval opens at the
 * first shadowed sample, closes at the first lit sample (or tend); afterwards
 * each start is moved back by one step unless it equals tbegin or touches the
 * previous interval.  [D 0x005470d0][V sample: 20 points]
 * Returns the number of intervals (<= maxiv). */
int hk_intervals(const unsigned char *in, int n, int tbegin, int step,
                 hk_interval *iv, int maxiv);

/* "N0.<no> [h:mm'] (hh:mm')-(hh:mm') ..." exactly as written into the drawing
 * (step >= 60 s: minutes only; step < 60: with seconds).  no_total is the
 * sequence number (first_no - 1 + index) [D 0x005470d0][V sample] */
void hk_fmt_n0_line(char *out, int outsz, int no, const hk_interval *iv, int niv, int step);

/* 指定点の グラフ（グラフ作図 (1071) で 文書 +0x83dc が立つとき、FUN_0069da00 が 行ごとに描く）。
 * (ox, oy) はその行の字の基点、ang は角（度）。線は FUN_0069cf20: 局所の (秒, r) を
 * 原点 = 基点の 1 下・x = 秒 × 0.6 / 60 で写し、長さ 1e-7 以下は書かない。
 *   色 1: 0 と -2 の横二本（8 時間 = 288、9～15時なら 6 時間）、時の目盛 0.5 ～ -2.5
 *   色 3: 壁に日が当たらない帯（wall のとき w1～w2 秒、正午から）: 縦二本と -2/3・-4/3 の横
 *   色 4: 影の区間ごとに 縦二本と 0 ～ -2 を 10 刻みの横（帯の中は帯の外へ寄せ、空なら書かない）
 * 返すのは線の数（<= maxg）。[D 0x0069da00 0x69dc4e〜0x69e4e9・0x0069cf20] */
typedef struct { double x0, y0, x1, y1; int color; } hk_gline;
int hk_point_graph(double ox, double oy, double ang, int n15, const hk_interval *iv, int niv,
                   int wall, int w1, int w2, hk_gline *g, int maxg);

/* ------------------------------------------------------------------ */
/* 5. 等時間 (Kage2) helpers                                           */
/* ------------------------------------------------------------------ */
/* contour threshold on the per-cell count of shadowed samples:
 *   level_hours*3600/step - 0.1   [D 0x00548b30] [V sample: totals on the iso lines] */
double hk_iso_threshold(double level_hours, int step_sec);

/* 等時間の 等高線（src/hkiso.c）。線は 世界座標で、label = 1 の線に 水準の文字を付ける。
 * step = 精度の秒数（既定 60）、level = 時間（2.0 など）、sheet = 用紙の大きさ（mm）。 */
typedef struct { double x0, y0, x1, y1; int label; int label_at; } hk_isoseg;   /* label_at: 何本目まで書いたあとに 文字を書くか */
typedef struct {
    double lat, dec, north, level, sheet_w, sheet_h;
    int n15, step;
    int range;                  /* 1: 範囲指定（世界の 4 隅 rx・ry） */
    double rx[4], ry[4];
    const hk_wall *wall;        /* 壁面日影（NULL = 無し）。数えは 立面の点を地面へ戻して、線は 壁で切る */
} hk_iso_in;
int hk_iso(const hk_edge *e, int ne, const hk_iso_in *in, hk_isoseg *out, int maxout);

/* ------------------------------------------------------------------ */
/* 6. 天空図 / 天空率                                                  */
/* ------------------------------------------------------------------ */
typedef struct { double x0, y0, z0, x1, y1, z1; } hk_edge3;  /* z in drawing units above the plane */

/* [D 0x00733e40] projection of a 3-D point seen from P=(px,py) to the diagram
 * (centre at origin, radius R).  equidist=0: r = R*cos(el); 1: r = R*(1-el/(pi/2)).
 * azimuth = atan2(dy,dx).  The doc's north is NOT applied here (only the optional
 * 南方向補正 mirror: az = pi - (az - off) when mirror != 0). */
void hk_tenkuu_project(double px, double py, double x, double y, double h,
                       double R, int equidist, int mirror, double off,
                       double *ox, double *oy);

/* highest elevation (rad) of the wire-frame along azimuth az seen from P;
 * returns -1 if no edge is crossed. */
double hk_skyline_el(const hk_edge3 *e, int n, double px, double py, double az);

/* 天空率 in percent by azimuth sweep: nsteps azimuth samples (the original: 36000,
 * 360000 with 高精度).  equidist=0: 1 - (1/2pi) * integral sin^2(el) dtheta
 * (orthographic: area of the projected disc);  equidist=1:
 * 1 - (1/2pi) * integral sin(el) dtheta (area on the hemisphere).
 * [D 0x00748da0][V sample ortho: 91.34 89.53 86.49 84.19 82.86 82.43] */
double hk_sky_ratio(const hk_edge3 *e, int n, double px, double py,
                    int nsteps, int equidist);

/* the original rounds the percentage to 2 (3 with 高精度) decimals with a
 * snap to 25/50/75 within +-0.01 (0.001): [D 0x00748da0 @0x74cb..] */
double hk_sky_round(double pct, int precise);

/* [D 0x00737bf0] 天空率比較: D = |plan| - |base| ; text = "%.2lf" (decimals<3) or
 * "%.3lf"; relation sign '<' (id 0x16a5) if |D| >= 1e-7 else '='(0x180b).  OK/NG
 * mark only when the tolerance option is set: tol = (DAT_00a0bec4/10)/1000 (out of
 * range [0.001,1] -> 0.02): "OK" is replaced by "NG" when D <= tol+1e-7. [G sign] */
int hk_compare_ok(double plan_pct, double base_pct, double tol);

#ifdef __cplusplus
}
#endif
#endif
