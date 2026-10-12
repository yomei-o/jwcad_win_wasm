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
typedef struct { hk_pt a, b; double za_mm, zb_mm; } hk_edge;  /* heights relative to the measuring plane */
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
