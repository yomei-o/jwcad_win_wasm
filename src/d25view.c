/* ２．５D (32937) の 透視図・鳥瞰図・アイソメ（src/d25view.h の頭を見よ）。
 *
 * どれも逆コンパイルの読み、原典では押していない。原典の答え（.jww）は無い。
 * 名前の対応:
 *   バー C25DDialog: +0xb8 段 (m_mode)、+0xc0 (m) (m_mm)、+0xc8/+0xd0 回転角間隔・
 *     移動間隔 (箱 1412)、+0xd8 縮尺、+0xe0 回転角 (b_ang)、+0xe8/+0xf0 透視の
 *     高さ・距離、+0xf8/+0x100 鳥瞰の高さ・距離、+0x108 アイソメの見下ろし角、
 *     +0xc10 面固定 (1323)
 *   文書 doc: +0x82ec 段、+0x8300 視点の横 (eye_x)、+0x8308/+0x8310 視点の
 *     奥・高さ、+0x8318 回転角、+0x8320 見下ろし角、+0x8328 画角の焦点距離、
 *     +0x8330..+0x8340 立体の真ん中、+0x8358..+0x8360 初めの値を入れた旗、
 *     +0x8368..+0x83a0 段ごとの控え
 *   CZukei25D: +0xc0 鳥瞰の縦のずれ (eye_dy)、+0x340 高さの倍 (k_unit)、
 *     +0x348 焦点距離の既定、+0x350/+0x358 立体の半径・高さ
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "d25view.h"
#include "cmd.h"

#define PI 3.14159265358979323846

typedef struct {
    double p[6];                /* x1 y1 z1 x2 y2 z2（CData3DSen +0x68..+0x90） */
    unsigned char ltype;
    unsigned short color, layer, lgroup;
} d25_line;

static d25_line *ln;
static int nln, cln;

static int m_mode, m_mm;
static double b_ang = -45.0, b_ph = 200.0, b_pd = -2000.0, b_bh = 2000.0, b_bd = -2000.0;
static double b_iso;            /* 0x404317 の前: atan2(1, √2) 度 */
static double b_scale = 100.0;
static int init1, init2, init3;
static double s1h, s1d, s1a, s2h, s2d, s2a, s3p, s3a;
static double eye_x, eye_dy;
static double cx, cy, cz;
static double f_half, r_xy, r_z, k_unit;
static int snap[16 * 17];       /* 立体を組んだときのレイヤの状態（slot 5 の見比べ） */

static double iso_angle(void)
{
    return atan2(1.0, sqrt(2.0)) * 180.0 / PI;
}

int jw_d25_mode(void)
{
    return m_mode;
}

int jw_d25_mm(void)
{
    return m_mm;
}

void jw_d25_leave(void)
{
    m_mode = 0;
}

void jw_d25_forget(void)
{
    m_mode = 0;
    init1 = init2 = init3 = 0;
}

static double write_scale(const jw_drawing *d)
{
    int g, wg = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

/* swscanf の %lg 一つ: 符号・数字・小数点・指数。読めなければ 0 */
static int scan_num(const char **pp, double *v)
{
    const char *p = *pp, *q = p;
    char buf[80];
    int dig = 0;
    size_t n;

    if (*q == '+' || *q == '-')
        q++;
    while (*q >= '0' && *q <= '9') {
        q++;
        dig = 1;
    }
    if (*q == '.') {
        q++;
        while (*q >= '0' && *q <= '9') {
            q++;
            dig = 1;
        }
    }
    if (!dig)
        return 0;
    if (*q == 'e' || *q == 'E') {
        const char *r = q + 1;

        if (*r == '+' || *r == '-')
            r++;
        if (*r >= '0' && *r <= '9') {
            while (*r >= '0' && *r <= '9')
                r++;
            q = r;
        }
    }
    n = (size_t)(q - p);
    if (n >= sizeof buf)
        n = sizeof buf - 1;
    memcpy(buf, p, n);
    buf[n] = 0;
    *v = strtod(buf, 0);
    *pp = q;
    return 1;
}

/* "%lg,%lg,..." の読み: 読めた数（空なら -1、swscanf の EOF） */
static int scan_list(const char *s, double *v, int max)
{
    int n = 0;

    if (!*s)
        return -1;
    while (n < max && scan_num(&s, &v[n])) {
        n++;
        if (*s != ',')
            break;
        s++;
    }
    return n;
}

/* FUN_0045d240: 名前が "#lv" で始まり 4 字以上なら その後ろの %lg */
static double name_lv(const jw_drawing *d, int off)
{
    const char *s = off >= 0 ? jw_str(d, off) : 0;
    double v = 0.0;

    if (s && s[0] == '#' && s[1] == 'l' && s[2] == 'v' && strlen(s) > 3) {
        const char *p = s + 3;

        scan_num(&p, &v);
    }
    return v;
}

/* FUN_006208a0: 文字の 空白を抜いて "%lg,%lg,..."、数に +0x340 を掛ける。
   *kind は末尾の字: v V → 1、h H → 2、t → 20、T → 21、d → 30、D → 31 */
static int text_vals(const jw_drawing *d, const jw_obj *t, double *h, double *dp, int *kind)
{
    const char *s = t->text >= 0 ? jw_str(d, t->text) : "";
    char buf[512];
    double v[12];
    size_t i, n = 0;
    int r;

    *kind = 0;
    for (i = 0; s[i] && n + 1 < sizeof buf; i++)
        if (s[i] != ' ')
            buf[n++] = s[i];
    buf[n] = 0;
    memset(v, 0, sizeof v);
    r = scan_list(buf, v, 12);
    *h = v[0] * k_unit;
    *dp = v[1] * k_unit;
    if (r > 0 && n > 0) {
        char c = buf[n - 1];

        if (c == 'v' || c == 'V')
            *kind = 1;
        if (c == 'h' || c == 'H')
            *kind = 2;
        if (c == 't')
            *kind = 20;
        if (c == 'T')
            *kind = 21;
        if (c == 'd')
            *kind = 30;
        if (c == 'D')
            *kind = 31;
    }
    return r;
}

/* FUN_0042dd10: 書ける層（状態 3）で、要素の旗 1 が無い */
static int editable(const jw_drawing *d, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15;
    int gs = d->group[g].state, ls = d->group[g].layer[l].state;

    gs = gs == 0 ? 0 : gs == 1 ? 1 : 3;
    ls = ls == 0 ? 0 : ls == 1 ? 1 : 3;
    return (gs & ls) == 3 && !(o->flags & 1);
}

static void add_line(const jw_obj *src, const double p[6])
{
    if (nln == cln) {
        int c = cln ? cln * 2 : 64;
        d25_line *q = (d25_line *)realloc(ln, (size_t)c * sizeof *q);

        if (!q)
            return;
        ln = q;
        cln = c;
    }
    memcpy(ln[nln].p, p, sizeof ln[nln].p);
    ln[nln].ltype = src->ltype;
    ln[nln].color = src->color;
    ln[nln].layer = src->layer;
    ln[nln].lgroup = src->lgroup;
    nln++;
}

static void take_snap(const jw_drawing *d, int *s)
{
    int g, l;

    for (g = 0; g < 16; g++) {
        s[g * 17] = d->group[g].state;
        for (l = 0; l < 16; l++)
            s[g * 17 + 1 + l] = d->group[g].layer[l].state;
    }
}

/* ---- 勾配の文字 t T d D（FUN_00613c10 の 0x613f31.. と FUN_0061c770）。
 * 逆コンパイルの読み（引数の落ちた所は objdump の命令で読んだ）、原典では押していない。
 * 線の端に 0.001 以内で置いた同じレイヤの字の数 v0..v4（FUN_006208a0 の
 * +0x418..+0x438、終点は +0x4c8..）: v0 高さ・v1 幅（ここまで ×+0x340）、
 * v2 縦の幅（×+0x340 は FUN_0061c770 が掛ける）、v3 刻みの角、v4 回し。
 * d D は 幅・縦の幅を √2 倍、回しを v3、刻みを 90°（四角の筒）。字の終点が 線の
 * 内へ向いていなければ（その端から他の端への向きに 写した長さ < 0）回しを負に。
 * 筒は 両端の断面（半径 |v1|/2、縦は |v2|/2 との比が 0.01..10 ならその比、刻み
 * 360/v3（1..120 でなければ 15°、三つ以上）を 3・4・5・7・8 角は 30・45・54・
 * 12.857143・22.5° ずらす）を v4 だけ回し、勾配の面（端の高さ v0 を結ぶ面）に
 * 立てて 線の上に置く。線は 真ん中の線（線種 5）、刻みごとに 両端を結ぶ線、
 * T・D の端は 断面の辺。刻みの多い方を始点にする（入れ替えれば回しは負に）。
 * 刻みが違えば 終点の側は 近い刻みへ。両端とも幅が 1e-7 未満なら 筒にしない。
 * 入れていないもの: 字の無い端の v2..v4 は 原典では前の字の値が残る（移植は 0）。 */
static void grad_vals(const jw_drawing *d, const jw_obj *t, double *g);
static int grad_tube(const jw_obj *o, double base, int k1, int k2, const double *g1,
                     const double *g2);
static void gx_pair(const jw_obj *src, double *p, unsigned fl, int has4, double p4);

/* 線を一本: 勾配の補助線で起こしてから（FUN_006109b0）底上げを足す */
static void put_line(const jw_obj *o, const double *p0, unsigned fl, double b1, double b2)
{
    double p[6];

    memcpy(p, p0, sizeof p);
    gx_pair(o, p, fl, 0, 0.0);
    p[2] += b1;
    p[5] += b2;
    add_line(o, p);
}

/* 一本の線を立体に（FUN_00613c10。勾配の文字 t T d D は上の grad_tube、
   勾配の補助線 FUN_006129c0 / FUN_006109b0 は put_line → gx_pair。
   +0x48 の旗: 端の字が v V h H（kind 1・2）なら 始点 1・終点 2、h H は さらに
   始点 4・終点 8。縦の線は 始点なら 3（h H は 0xf）、終点も同じ（local_64dc・64e0）） */
static void one_line(const jw_drawing *d, const jw_obj *o, unsigned char *used,
                     double base, int lh, double lh_h)
{
    double h1 = 0.0, d1 = 0.0, h2 = 0.0, d2 = 0.0, p[6], q[6];
    double g[2][5];                     /* 勾配の数（+0x418.. / +0x4c8..） */
    int n1 = 0, n2 = 0, k1 = 0, k2 = 0, t1 = -1, t2 = -1, ec = 0, f0 = 0, j;
    unsigned fl = 0, vs = 0, ve = 0;

    memset(g, 0, sizeof g);

    for (j = 0; j < d->ndrawn; j++) {
        const jw_obj *t = &d->obj[j];
        double ex, ey;
        int e;

        if (t->cls != JW_MOJI || t->sub || t->layer != o->layer || t->lgroup != o->lgroup)
            continue;
        for (e = 0; e < 2; e++) {
            double hh, dd;
            int kind, n;

            ex = t->d[0] - o->d[2 * e];
            ey = t->d[1] - o->d[2 * e + 1];
            if (sqrt(ex * ex + ey * ey) > 0.001)
                continue;
            n = text_vals(d, t, &hh, &dd, &kind);
            grad_vals(d, t, g[e]);
            if (kind < 20) {
                if (n > 2)
                    n = 2;
                if (kind > 0) {         /* 0x613d.. の +0x48 */
                    fl |= e == 0 ? 1u : 2u;
                    if (e == 0)
                        vs |= 3;
                    else
                        ve |= 3;
                    if (kind == 2) {
                        fl |= e == 0 ? 4u : 8u;
                        if (e == 0)
                            vs |= 0xf;
                        else
                            ve |= 0xf;
                    }
                }
            } else {
                double ux = o->d[2 - 2 * e] - o->d[2 * e], uy = o->d[3 - 2 * e] - o->d[2 * e + 1];
                double ul = sqrt(ux * ux + uy * uy);

                if (e == 0)
                    k1 = kind;
                else
                    k2 = kind;
                if (kind >= 30) {       /* d D: 四角の筒 */
                    g[e][1] *= sqrt(2.0);
                    g[e][2] *= sqrt(2.0);
                    g[e][4] = g[e][3];
                    g[e][3] = 90.0;
                }
                /* FUN_005f8940（この端から他の端へ）と FUN_005f8be0(1, 字の終点) */
                if (fabs(ux) + fabs(uy) < 1e-07)
                    ux = 1.0, uy = 0.0, ul = 1.0;
                if ((t->d[2] - o->d[2 * e]) * ux / ul + (t->d[3] - o->d[2 * e + 1]) * uy / ul < 0.0)
                    g[e][4] = -g[e][4];
            }
            if (used[j])
                n = -n;
            used[j] = 1;
            if (e == 0) {
                n1 = n;
                h1 = hh;
                d1 = dd;
                t1 = j;
            } else {
                n2 = n;
                h2 = hh;
                d2 = dd;
                t2 = j;
            }
        }
    }
    if ((k1 >= 20 || k2 >= 20) && grad_tube(o, base, k1, k2, g[0], g[1]))
        return;
    if (n1 == 0 && lh) {
        n1 = 2;
        h1 = lh_h;
        d1 = 0.0;
    }
    if (n2 == 0 && lh) {
        n2 = 2;
        h2 = lh_h;
        d2 = 0.0;
    }
    /* 日影の高さの文字（旗 0x80）で数が一つ: 地面からの壁にする */
    if (t1 >= 0 && (d->obj[t1].flags & 0x80) && abs(n1) == 1) {
        if (h1 >= 0.0) {
            n1 = n1 < 1 ? -2 : 2;
            d1 = base < -1e-07 ? 0.0 : -base;
        } else {
            ec = 1;
            h1 = -h1;
        }
    }
    if (t2 >= 0 && (d->obj[t2].flags & 0x80) && abs(n2) == 1) {
        if (h2 >= 0.0) {
            n2 = n2 < 1 ? -2 : 2;
            d2 = base < -1e-07 ? 0.0 : -base;
        } else {
            f0 = 1;
            h2 = -h2;
        }
    }
    p[0] = o->d[0];
    p[1] = o->d[1];
    p[3] = o->d[2];
    p[4] = o->d[3];
    if ((abs(n1) == 2 && abs(n2) == 2) || (n1 == 0 && n2 == 0)) {
        /* 奥行の線（文字が無ければ 0 の高さの線） */
        p[2] = abs(n1) == 2 ? d1 : 0.0;
        p[5] = abs(n2) == 2 ? d2 : 0.0;
        put_line(o, p, fl, ec ? 0.0 : base, f0 ? 0.0 : base);
    }
    if (n1 != 0 || n2 != 0) {           /* 高さの線 */
        p[2] = h1;
        p[5] = h2;
        put_line(o, p, fl, base, base);
    }
    if (n1 > 1 && fabs(h1 - d1) > 1e-07) {     /* 始点の縦の線 */
        q[0] = q[3] = o->d[0];
        q[1] = q[4] = o->d[1];
        q[2] = h1;
        q[5] = d1;
        put_line(o, q, vs, base, ec ? 0.0 : base);
    }
    if (n2 > 1 && fabs(h2 - d2) > 1e-07) {     /* 終点の縦の線 */
        q[0] = q[3] = o->d[2];
        q[1] = q[4] = o->d[3];
        q[2] = h2;
        q[5] = d2;
        put_line(o, q, ve, base, f0 ? 0.0 : base);
    }
}

/* ---- 円弧の立体（FUN_0061e030）。逆コンパイルの読み、原典では押していない。
 * 中心に 0.001 以内で置いた同じレイヤの文字（初めの一つ）を
 * "%lg,…" 十二まで読む（FUN_006208a0 の 3）: v0 高さ、v1 奥行（ここまで ×+0x340）、
 * v2 刻みの角（度。負なら輪を描かない、1 より小さければ 15、数が二つ未満なら 5）、
 * v3 v4 上の輪の中心のずれ（×+0x340）、v5 上の輪の半径（×+0x340）、v6 上の輪の
 * 短径（扁平率は v6/v5、数が 7 以上のとき）、v7 ねじれの角（度、|v7| > 1 で螺旋）、
 * v8 v9 v10 二本目の螺旋の 半径のずれ・高さのずれ（×+0x340）・角のずれ（度）。
 * 文字が無く レイヤ名が #lh なら 二つ（高さ #lh、奥行 0）。
 * 輪は 刻みごとの線（FUN_00621ce0 で底上げを足す）、数が二つ以上なら上の輪と
 * 刻みごとの縦の線（全円でなければ始めの縦の線も）。アイソメ（段 3、元レイヤの
 * 旗 +0x338 は移植に無いので 0）で 螺旋でなく 刻みが正なら 輪は 線でなく楕円
 * （FUN_00619710 → CData3DEnko、描き FUN_0043dd30 は アイソメでだけ描く）。
 * 末尾 g G（kind 10）の球は arc_sphere。入れていないもの:
 * 扁平率 0.1 で 高さ ≥ 1000 m の弧（勾配の補助線を仮に作る 0x61e9xx）。勾配の
 * 補助線の写しは gx_pair（線は字の v h で旗 3・0xf、楕円は旗 0 とした） */
typedef struct {
    double c[3], r, flat, tilt, a0, sw;     /* 中心・半径・扁平率・傾き・始めの角・開き */
    int full;
    int gen;                    /* 勾配の補助線で起こした: 点 = c + U cos t + V sin t */
    double U[3], V[3];
    unsigned char ltype;
    unsigned short color, layer, lgroup;
} d25_ell;

static d25_ell *el;
static int nel, cel;

static void add_ell(const jw_obj *src, const d25_ell *e)
{
    if (nel == cel) {
        int c = cel ? cel * 2 : 16;
        d25_ell *q = (d25_ell *)realloc(el, (size_t)c * sizeof *q);

        if (!q)
            return;
        el = q;
        cel = c;
    }
    el[nel] = *e;
    el[nel].ltype = src->ltype;
    el[nel].color = src->color;
    el[nel].layer = src->layer;
    el[nel].lgroup = src->lgroup;
    nel++;
}

/* FUN_005f9a30 の回し（ラジアン、0 と ±1 の丸め）と FUN_005f8b60・8c20 の 0 */
typedef struct {
    double x, y, c, s;
} d25_rot;

static void rot_set(d25_rot *t, double x, double y, double rad)
{
    t->x = x;
    t->y = y;
    t->c = cos(rad);
    t->s = sin(rad);
    if (fabs(t->c) < 1e-15 || fabs(t->s) == 1.0)
        t->c = 0.0;
    if (fabs(t->s) < 1e-15 || fabs(t->c) == 1.0)
        t->s = 0.0;
}

static void rot_pt(const d25_rot *t, double u, double v, double *x, double *y)
{
    *x = t->c * u - t->s * v + t->x;
    *y = t->c * v + t->s * u + t->y;
}

/* ---- 勾配の補助線（FUN_006129c0 で控え、FUN_006109b0 で起こす）。
 * 逆コンパイルの読み（落ちた置き場と ECX は objdump の命令で読んだ）、原典では押していない。
 * FUN_006129c0（FUN_00617f70 の 0x6187e8、組む前）: グループ名が「#k」で始まれば
 * +0x8e0[グループ] = 1（FUN_00617f70 のグループの段、名の初めの二字が 0x23 0x6b）。
 * レイヤごとに 書ける線（FUN_0042dd10）で 線種 9 かつ 線色 5（#k なら どの色でも）の
 * 最後の一本を +0x99e0、線色 6・線種 9 を +0x119e0、線色 5・6 の点（CDataTen）を
 * +0xa9e0・+0x189e0 に。色 5 の線は 長さ 0 なら捨て、点が無ければ 向きを x 正（x が
 * 0 なら y 正）にそろえて 起点 +0xb9e0 は 始点（逆にしたら終点）、点があれば 起点は
 * その点で 点に遠い端へ向ける。角 +0xf9e0 は atan2 の度。左下 +0x199e0 は 色 6 の
 * 点、無ければ そのレイヤの 書ける 線（線種 9 を除く、CDataSen 0x9fe024）の両端と
 * 円弧（CDataEnko 0x9fe040）の中心の x・y の最小（無ければ 0）。色 6 の線は 長さ 0 なら
 * 捨て、角 +0x129e0 は 既定 90、|dy| ≥ 0.001 なら 向きを y 正（y が 0 なら x 正）に
 * そろえた atan2 の度、起点 +0x149e0 は 始点（逆なら終点）。
 * FUN_006109b0（二点 +0x68.. と +0x80..）: #k なら 二点を 起点・角の座標に戻し
 * （FUN_005f92e0、-0x1b0）左下を 0 に。X = x − 左下x、Y = y − 左下y、Z = −z。
 * 色 6 の線があり #k でなく、(両端の Y ≥ y6 − 1e-7 か、弧・楕円では 中心の y − 左下y ≥
 * y6 − 1e-7) で 角 a6 が 1..179 かつ 90 から 1e-7 より離れれば Z += (Y − y6)·cos a6 / sin a6。
 * 旗 1（2 は終点）なら この端は 4 が無ければ a6 の回し（-0x150、原点）で
 * (Y − y6, −Z) を写して Z = x + (色 6 の起点x − 左下x)、Y = y + (起点y − 左下y)、
 * 4 があれば h = (90° − a6)/2 で Y −= Z·2 sin h cos h、Z −= Z·2 sin² h（Z は寄せる前）。
 * 最後に 起点まわりに角だけ回し（-0x180）: (x, y) = 起点 + R(X, Z)、z = Y。
 * 底上げ（+0x19e0）は 呼び手が この後に足す。 */
typedef struct {
    int on;                     /* +0x99e0 */
    d25_rot r5;                 /* +0xb9e0 起点・+0xf9e0 角 */
    double llx, lly;            /* +0x199e0 */
    int has6;                   /* +0x119e0 */
    double a6, sx6, sy6;        /* +0x129e0・+0x149e0 */
} d25_gx;

static d25_gx gx[16][16];
static int gk[16];              /* +0x8e0 */

static void gx_setup(const jw_drawing *d)
{
    static const jw_obj *r5[16][16], *r6[16][16], *t5[16][16], *t6[16][16];
    int g, l, i;

    memset(gx, 0, sizeof gx);
    memset(r5, 0, sizeof r5);
    memset(r6, 0, sizeof r6);
    memset(t5, 0, sizeof t5);
    memset(t6, 0, sizeof t6);
    for (g = 0; g < 16; g++) {
        const char *s = d->group[g].name >= 0 ? jw_str(d, d->group[g].name) : 0;

        gk[g] = s && s[0] == '#' && s[1] == 'k';
    }
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (o->sub || o->lgroup > 15 || o->layer > 15 || !editable(d, o))
            continue;
        if (o->cls == JW_SEN) {
            if ((o->color == 5 || gk[o->lgroup]) && o->ltype == 9)
                r5[o->lgroup][o->layer] = o;
            if (o->color == 6 && o->ltype == 9)
                r6[o->lgroup][o->layer] = o;
        } else if (o->cls == JW_TEN) {
            if (o->color == 5)
                t5[o->lgroup][o->layer] = o;
            if (o->color == 6)
                t6[o->lgroup][o->layer] = o;
        }
    }
    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++) {
            d25_gx *x = &gx[g][l];
            const jw_obj *a = r5[g][l], *b = r6[g][l];
            double dx, dy, ox, oy, mx, my;

            if (!a)
                continue;
            dx = a->d[2] - a->d[0];
            dy = a->d[3] - a->d[1];
            if (fabs(dx) < 1e-07 && fabs(dy) < 1e-07)
                continue;
            if (!t5[g][l]) {
                int neg = fabs(dx) > 1e-07 ? dx < -1e-07 : dy < 0.0;

                if (neg) {
                    dx = -dx;
                    dy = -dy;
                }
                ox = a->d[neg ? 2 : 0];
                oy = a->d[neg ? 3 : 1];
            } else {
                const jw_obj *t = t5[g][l];
                double e1 = hypot(a->d[0] - t->d[0], a->d[1] - t->d[1]);
                double e2 = hypot(a->d[2] - t->d[0], a->d[3] - t->d[1]);

                if (e2 < e1) {
                    dx = -dx;
                    dy = -dy;
                }
                ox = t->d[0];
                oy = t->d[1];
            }
            x->on = 1;
            rot_set(&x->r5, ox, oy, atan2(dy, dx) * 180.0 / PI * PI / 180.0);
            if (t6[g][l]) {
                x->llx = t6[g][l]->d[0];
                x->lly = t6[g][l]->d[1];
            } else {
                mx = my = 9e21;
                for (i = 0; i < d->ndrawn; i++) {
                    const jw_obj *o = &d->obj[i];

                    if (o->sub || o->lgroup != g || o->layer != l || !editable(d, o))
                        continue;
                    if (o->cls == JW_SEN && o->ltype != 9) {
                        mx = fmin(mx, fmin(o->d[0], o->d[2]));
                        my = fmin(my, fmin(o->d[1], o->d[3]));
                    } else if (o->cls == JW_ENKO) {
                        mx = fmin(mx, o->d[0]);
                        my = fmin(my, o->d[1]);
                    }
                }
                x->llx = mx > 9e20 ? 0.0 : mx;
                x->lly = my > 9e20 ? 0.0 : my;
            }
            x->a6 = 90.0;
            if (b) {
                dx = b->d[2] - b->d[0];
                dy = b->d[3] - b->d[1];
                if (fabs(dx) < 1e-07 && fabs(dy) < 1e-07)
                    continue;
                x->has6 = 1;
                if (fabs(dy) >= 0.001) {
                    int neg = fabs(dy) > 1e-07 ? dy < -1e-07 : dx < 0.0;

                    if (neg) {
                        dx = -dx;
                        dy = -dy;
                    }
                    x->a6 = atan2(dy, dx) * 180.0 / PI;
                    x->sx6 = b->d[neg ? 2 : 0];
                    x->sy6 = b->d[neg ? 3 : 1];
                }
            }
        }
}

/* FUN_006109b0 の本体。lean は 寄せるか（-1 なら 両端と has4・p4 から決める） */
static void gx_xf(const jw_obj *src, double *p, unsigned fl, int has4, double p4, int lean)
{
    const d25_gx *x;
    double llx, lly, X1, Y1, Z1, X2, Y2, Z2;
    int k;

    if (src->lgroup > 15 || src->layer > 15)
        return;
    x = &gx[src->lgroup][src->layer];
    if (!x->on)
        return;
    k = gk[src->lgroup];
    llx = x->llx;
    lly = x->lly;
    if (k) {                            /* FUN_005f92e0 */
        int e;

        for (e = 0; e < 2; e++) {
            double u = p[3 * e] - x->r5.x, v = p[3 * e + 1] - x->r5.y;

            p[3 * e] = u * x->r5.c + v * x->r5.s;
            p[3 * e + 1] = v * x->r5.c - u * x->r5.s;
        }
        llx = lly = 0.0;
    }
    X1 = p[0] - llx;
    Y1 = p[1] - lly;
    Z1 = -p[2];
    X2 = p[3] - llx;
    Y2 = p[4] - lly;
    Z2 = -p[5];
    if (x->has6 && !k) {
        double y6 = x->sy6 - lly, e = y6 - 1e-07;

        if (lean < 0)
            lean = (e <= Y1 && e <= Y2) || (has4 && e <= p4 - lly);
        if (lean && x->a6 >= 1.0 && x->a6 <= 179.0 && fabs(x->a6 - 90.0) > 1e-07) {
            double t = x->a6 * PI / 180.0, h = (PI / 2.0 - t) / 2.0;
            double ch = cos(h), sh = sin(h), nz1, nz2, u, v;
            double sx = x->sx6 - llx, sy = x->sy6 - lly;
            d25_rot r6;

            nz1 = (Y1 - y6) * cos(t) / sin(t) + Z1;
            nz2 = (Y2 - y6) * cos(t) / sin(t) + Z2;
            rot_set(&r6, 0.0, 0.0, x->a6 * PI / 180.0);
            if (fl & 1) {
                if (!(fl & 4)) {
                    rot_pt(&r6, Y1 - y6, -Z1, &u, &v);
                    nz1 = u + sx;
                    Y1 = v + sy;
                } else {
                    Y1 -= Z1 * sh * 2.0 * ch;
                    nz1 -= Z1 * sh * 2.0 * sh;
                }
            }
            if (fl & 2) {
                if (!(fl & 8)) {
                    rot_pt(&r6, Y2 - y6, -Z2, &u, &v);
                    nz2 = u + sx;
                    Y2 = v + sy;
                } else {
                    nz2 -= Z2 * sh * 2.0 * sh;
                    Y2 -= Z2 * sh * 2.0 * ch;
                }
            }
            Z1 = nz1;
            Z2 = nz2;
        }
    }
    rot_pt(&x->r5, X1, Z1, &p[0], &p[1]);
    p[2] = Y1;
    rot_pt(&x->r5, X2, Z2, &p[3], &p[4]);
    p[5] = Y2;
}

static void gx_pair(const jw_obj *src, double *p, unsigned fl, int has4, double p4)
{
    gx_xf(src, p, fl, has4, p4, -1);
}

/* 楕円（FUN_00619710）: 中心と 二つの軸の端を起こし、軸を U V に。寄せるかは
   中心で決める（原典は 軸の端の組ごと。中心が y6 より下で組が分かれる所は違いうる） */
static void gx_ell(const jw_obj *src, double *c, double *U, double *V, int *gen)
{
    double a[6], b[6], e = 0.0;
    const d25_gx *x;
    int j, lean;

    *gen = 0;
    if (src->lgroup > 15 || src->layer > 15 || !gx[src->lgroup][src->layer].on)
        return;
    x = &gx[src->lgroup][src->layer];
    if (x->has6 && !gk[src->lgroup])
        e = x->sy6 - x->lly - 1e-07;
    lean = src->d[1] - x->lly >= e
        || (c[1] - x->lly >= e && c[1] + U[1] - x->lly >= e && c[1] + V[1] - x->lly >= e);
    for (j = 0; j < 3; j++) {
        a[j] = c[j];
        a[3 + j] = c[j] + U[j];
        b[j] = c[j] + V[j];
        b[3 + j] = c[j];
    }
    gx_xf(src, a, 0, 1, src->d[1], lean);
    gx_xf(src, b, 0, 1, src->d[1], lean);
    for (j = 0; j < 3; j++) {
        c[j] = a[j];
        U[j] = a[3 + j] - a[j];
        V[j] = b[j] - a[j];
    }
    *gen = 1;
}

static void grad_vals(const jw_drawing *d, const jw_obj *t, double *g)
{
    const char *s = t->text >= 0 ? jw_str(d, t->text) : "";
    char buf[512];
    double v[12];
    size_t i, n = 0;

    for (i = 0; s[i] && n + 1 < sizeof buf; i++)
        if (s[i] != ' ')
            buf[n++] = s[i];
    buf[n] = 0;
    memset(v, 0, sizeof v);
    scan_list(buf, v, 12);
    g[0] = v[0] * k_unit;
    g[1] = v[1] * k_unit;
    g[2] = v[2];
    g[3] = v[3];
    g[4] = v[4];
}

/* FUN_005f97f0: 二点の向き。短すぎれば (1,0) で 0 */
static int dir_set(d25_rot *t, double *len, double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1, dy = y2 - y1;

    t->x = x1;
    t->y = y1;
    if (fabs(dx) + fabs(dy) >= 1e-07) {
        *len = sqrt(dx * dx + dy * dy);
        t->c = dx / *len;
        t->s = dy / *len;
        return 1;
    }
    t->c = 1.0;
    t->s = 0.0;
    *len = 1.0;
    return 0;
}

/* 刻みの角と ずらし */
static int grad_step(double *step, double *off)
{
    int n;

    if (*step < 1.0 || *step > 120.0)
        *step = 15.0;
    n = (int)(360.0 / *step);
    if (n < 3)
        n = 3;
    *step = 360.0 / (double)n;
    *off = n == 3 ? 30.0 : n == 4 ? 45.0 : n == 5 ? 54.0 : n == 7 ? 12.857143 : n == 8 ? 22.5 : 0.0;
    return n;
}

static int pt_differ(const double *a, const double *b)
{
    return fabs(a[0] - b[0]) > 1e-07 || fabs(a[1] - b[1]) > 1e-07 || fabs(a[2] - b[2]) > 1e-07;
}

static void add_pts(const jw_obj *src, const double *a, const double *b)
{
    double p[6];

    memcpy(p, a, 3 * sizeof *p);
    memcpy(p + 3, b, 3 * sizeof *p);
    add_line(src, p);
}

/* FUN_0061c770: 勾配の筒。筒にしなければ 0（ふつうの線へ） */
static int grad_tube(const jw_obj *o, double base, int k1, int k2, const double *g1,
                     const double *g2)
{
    static double tab[400];
    double x1 = o->d[0], y1 = o->d[1], x2 = o->d[2], y2 = o->d[3];
    double h1 = g1[0], h2 = g2[0], rs = fabs(g1[1]) * 0.5, re = fabs(g2[1]) * 0.5;
    double vs = fabs(g1[2] * k_unit), ve = fabs(g2[2] * k_unit), ks = 1.0, ke = 1.0;
    double ss = g1[3], se = g2[3], os, oe, as = g1[4], ae = g2[4], llen, elen, th, w;
    double ps[3], pe[3], qs[3] = { 0, 0, 0 }, qe[3] = { 0, 0, 0 }, fe[3] = { 0, 0, 0 };
    d25_rot ra, rb, rl, rel;
    jw_obj mid;
    int ns, ne, es = k1 % 10, ee = k2 % 10, i;

    if (rs < 1e-07 && re < 1e-07)
        return 0;
    if (rs < 1e-07)
        rs = 1e-07;
    else if ((w = vs * 0.5 / rs) >= 0.01 && w <= 10.0)
        ks = w;
    if (re < 1e-07)
        re = 1e-07;
    else if ((w = ve * 0.5 / re) >= 0.01 && w <= 10.0)
        ke = w;
    ns = grad_step(&ss, &os);
    ne = grad_step(&se, &oe);
    if (ns < ne) {                      /* 刻みの多い方を始点に */
        int t;
#define SW(a, b) (w = (a), (a) = (b), (b) = w)
        SW(x1, x2);
        SW(y1, y2);
        SW(h1, h2);
        SW(rs, re);
        SW(ks, ke);
        SW(ss, se);
        SW(os, oe);
        SW(as, ae);
#undef SW
        as = -as;
        ae = -ae;
        t = ns, ns = ne, ne = t;
        t = es, es = ee, ee = t;
    }
    for (i = 0; i <= ne && i < 400; i++)
        tab[i] = (double)i * se - oe;
    rot_set(&ra, 0.0, 0.0, as * PI / 180.0);
    rot_set(&rb, 0.0, 0.0, -ae * PI / 180.0);
    if (!dir_set(&rl, &llen, x1, y1, x2, y2))
        return 0;
    if (!dir_set(&rel, &elen, 0.0, h1, llen, h2))
        return 0;
    mid = *o;                           /* 真ん中の線は 線種 5 */
    mid.ltype = 5;
    ps[0] = x1, ps[1] = y1, ps[2] = h1 + base;
    pe[0] = x2, pe[1] = y2, pe[2] = h2 + base;
    add_pts(&mid, ps, pe);
    for (th = 0.0; th <= 360.0000001; th += ss) {
        double ts = th - os, te = ts, ax, ay, bx, by, us, ue, zs, ze;

        if (ns != ne) {
            double best = 9e+20;

            for (i = 0; i <= ne && i < 400; i++)
                if (fabs(tab[i] - ts) <= best) {
                    best = fabs(tab[i] - ts);
                    te = tab[i];
                }
        }
        rot_pt(&ra, rs * cos(ts * PI / 180.0), rs * sin(ts * PI / 180.0) * ks, &ax, &ay);
        rot_pt(&rb, re * cos(te * PI / 180.0), re * sin(te * PI / 180.0) * ke, &bx, &by);
        rot_pt(&rel, 0.0, ay, &us, &zs);
        rot_pt(&rel, elen, by, &ue, &ze);
        rot_pt(&rl, us, ax, &ps[0], &ps[1]);
        ps[2] = zs + base;
        rot_pt(&rl, ue, bx, &pe[0], &pe[1]);
        pe[2] = ze + base;
        if (th > 1e-07) {
            add_pts(o, ps, pe);
            if (es && pt_differ(ps, qs))
                add_pts(o, ps, qs);
            if (ee && pt_differ(pe, qe))
                add_pts(o, qe, pe);
        }
        memcpy(qs, ps, sizeof qs);
        memcpy(qe, pe, sizeof qe);
        if (th < 1e-07)
            memcpy(fe, pe, sizeof fe);
    }
    if (ee && pt_differ(fe, qe))
        add_pts(o, fe, pe);
    return 1;
}

/* FUN_00621ce0: 底上げを足して線を一本 */
static unsigned arc_fl;          /* FUN_00621ce0 の param_8: 字 v V → 3、h H → 0xf */

static void arc_seg(const jw_obj *o, double base, double x1, double y1, double z1, double x2,
                    double y2, double z2)
{
    double p[6];

    p[0] = x1;
    p[1] = y1;
    p[2] = z1;
    p[3] = x2;
    p[4] = y2;
    p[5] = z2;
    gx_pair(o, p, arc_fl, 1, o->d[1]);
    p[2] += base;
    p[5] += base;
    add_line(o, p);
}

static void arc_ell(const jw_obj *o, double base, double cx0, double cy0, double z, double r,
                    double flat, double tilt, double a0, double sw, int full)
{
    d25_ell e;

    e.c[0] = cx0;
    e.c[1] = cy0;
    e.c[2] = z;
    e.U[0] = cos(tilt) * r;
    e.U[1] = sin(tilt) * r;
    e.U[2] = 0.0;
    e.V[0] = -sin(tilt) * r * flat;
    e.V[1] = cos(tilt) * r * flat;
    e.V[2] = 0.0;
    gx_ell(o, e.c, e.U, e.V, &e.gen);
    e.c[2] += base;
    e.r = r;
    e.flat = flat;
    e.tilt = tilt;
    e.a0 = a0;
    e.sw = sw;
    e.full = full;
    add_ell(o, &e);
}

static double wrap_pi(double a)
{
    if (a > PI)
        a -= 2.0 * PI;
    if (a <= -PI)
        a += 2.0 * PI;
    return a;
}

/* 球（末尾 g G、kind 10）。逆コンパイルの読み、原典では押していない。
 * FUN_00620ef0（アイソメ以外）: 円弧の 半径 R・扁平率 K・傾き を取り、刻み（1 未満・90 超は 15）を 90/整数 に直し、
 * 角 a = 0, s, 2s.. (< 179.9999999) の輪を 点 0..360 を刻みで 線に: 輪 A（a = 0 から）
 * (R cos d, R K sin d cos a, R K sin d sin a)、輪 B（a = s から）(R cos a, R K sin a sin d, R K sin a cos d)。
 * 点は FUN_00621ac0 で (x,z) を v1 度（y 軸の回り）、次に (x,y) を傾き（z 軸の回り）だけ回し、
 * 中心 (cx, cy) と 高さ v0 + 底上げを足して つなぐ。
 * FUN_0061af10（アイソメ段 3）: 同じ輪を 楕円（CData3DEnko）で: 輪 A は 中心 0、U = (R,0,0)、
 * V = (0, R K sin a, R K cos a)（原典は 四隅 (±R, ±s, ±c) を置く）。輪 B は 中心 (R cos a,0,0)、
 * U = (0, R K sin a, 0)、V = (0, 0, R K sin a)。同じ回しを足す */
static void sph_xf(const d25_rot *ra, const d25_rot *rt, double x, double y, double z, double *ox,
                   double *oy, double *oz)
{
    double x1, z1;

    rot_pt(ra, x, z, &x1, &z1);
    rot_pt(rt, x1, y, ox, oy);
    *oz = z1;
}

static void sph_ell(const jw_obj *o, const d25_rot *ra, const d25_rot *rt, double cx, double cy,
                    double zz, const double c0[3], const double u0[3], const double v0[3])
{
    d25_ell e;
    double t[3];

    memset(&e, 0, sizeof e);
    sph_xf(ra, rt, c0[0], c0[1], c0[2], &t[0], &t[1], &t[2]);
    e.c[0] = t[0] + cx;
    e.c[1] = t[1] + cy;
    e.c[2] = zz + t[2];
    sph_xf(ra, rt, u0[0], u0[1], u0[2], &e.U[0], &e.U[1], &e.U[2]);
    sph_xf(ra, rt, v0[0], v0[1], v0[2], &e.V[0], &e.V[1], &e.V[2]);
    e.gen = 1;
    e.full = 1;
    e.sw = 2.0 * PI;
    add_ell(o, &e);
}

static void arc_sphere(const jw_obj *o, double base, double h, double rotv, double stp)
{
    double R = o->d[2], K = o->d[6] > 0.0 ? o->d[6] : 1.0, s, a, d, td;
    double zz = h + base, cx = o->d[0], cy = o->d[1];
    d25_rot ra, rt;
    int m, pass;

    if (R < 1e-07)
        return;
    if (stp < 1.0 || stp > 90.0)
        stp = 15.0;
    m = (int)(90.0 / stp);
    if (m < 1)
        m = 1;
    s = 90.0 / m;
    td = o->d[5] * 180.0 / PI;
    rot_set(&rt, 0.0, 0.0, td * PI / 180.0);
    rot_set(&ra, 0.0, 0.0, rotv * PI / 180.0);
    for (pass = 0; pass < 2; pass++) {
        for (a = pass ? s : 0.0; a < 179.9999999; a += s) {
            double ca = cos(a * PI / 180.0), sa = sin(a * PI / 180.0);

            if (m_mode == 3) {
                double c0[3] = {0, 0, 0}, u0[3], v0[3];

                if (!pass) {
                    u0[0] = R; u0[1] = 0; u0[2] = 0;
                    v0[0] = 0; v0[1] = sa * R * K; v0[2] = ca * R * K;
                } else {
                    c0[0] = ca * R;
                    u0[0] = 0; u0[1] = sa * R * K; u0[2] = 0;
                    v0[0] = 0; v0[1] = 0; v0[2] = sa * R * K;
                }
                sph_ell(o, &ra, &rt, cx, cy, zz, c0, u0, v0);
            } else {
                double q[6], px = 0, py = 0, pz = 0;

                for (d = 0.0; d <= 360.0000001; d += s) {
                    double cd = cos(d * PI / 180.0), sd = sin(d * PI / 180.0), x, y, z;
                    double X, Y, Z;

                    if (!pass) {
                        x = cd * R;
                        y = sd * R * K * ca;
                        z = sd * R * K * sa;
                    } else {
                        x = ca * R;
                        y = sd * (sa * R * K);
                        z = cd * (sa * R * K);
                    }
                    sph_xf(&ra, &rt, x, y, z, &X, &Y, &Z);
                    X += cx;
                    Y += cy;
                    Z += zz;
                    if (d > 1e-07) {
                        q[0] = px; q[1] = py; q[2] = pz;
                        q[3] = X; q[4] = Y; q[5] = Z;
                        add_line(o, q);
                    }
                    px = X;
                    py = Y;
                    pz = Z;
                }
            }
        }
    }
}

static void one_arc(const jw_drawing *d, const jw_obj *o, double base, int lh, double lh_h)
{
    double v[12], h, dd, step, a0, sw, rb, rt, fb, ft, tcx, tcy, da;
    d25_rot tb, tt;
    int n = 0, kind = 0, j, rings, full, cnt, i;

    if (o->d[2] < 1e-07)
        return;
    full = o->n == 1;
    sw = o->d[4];
    if (fabs(sw) < 1e-07 && !full)
        return;
    memset(v, 0, sizeof v);
    for (j = 0; j < d->ndrawn; j++) {
        const jw_obj *t = &d->obj[j];
        double ex, ey;

        if (t->cls != JW_MOJI || t->sub || t->layer != o->layer || t->lgroup != o->lgroup)
            continue;
        ex = t->d[0] - o->d[0];
        ey = t->d[1] - o->d[1];
        if (sqrt(ex * ex + ey * ey) > 0.001)
            continue;
        {
            const char *s = t->text >= 0 ? jw_str(d, t->text) : "";
            char buf[512], c;
            size_t q, m = 0;

            for (q = 0; s[q] && m + 1 < sizeof buf; q++)
                if (s[q] != ' ')
                    buf[m++] = s[q];
            buf[m] = 0;
            n = scan_list(buf, v, 12);
            c = m ? buf[m - 1] : 0;
            if (n > 0 && m > 0 && (c == 'g' || c == 'G'))
                kind = 10;
            if (n > 0 && m > 0 && (c == 'v' || c == 'V'))
                kind = 1;
            if (n > 0 && m > 0 && (c == 'h' || c == 'H'))
                kind = 2;
        }
        break;
    }
    if (kind == 10) {
        /* 球: 高さ v0、回し v1（度、生の値）、刻み v2。読み直して確認（FUN_00620ef0 の
           呼び側 0x61e5xx）: 刻みは 数が足りなくても 5 にはならず 0 のまま渡り、
           FUN_00620ef0 の 1 未満 → 15 になる（ふつうの弧の「n < 2 は 5」は 球の呼びより
           後ろの枝）。v[] は 0 で始めてあるので 数が 3 未満なら v[2] = 0 */
        arc_sphere(o, base, v[0] * k_unit, v[1], v[2]);
        return;
    }
    arc_fl = kind == 0 ? 0u : kind == 2 ? 0xfu : 3u;
    if (n < 0)
        n = 0;
    v[0] *= k_unit;
    v[1] *= k_unit;
    if (n == 0 && lh) {
        n = 2;
        v[0] = lh_h;
        v[1] = 0.0;
    }
    h = v[0];
    dd = v[1];
    rings = v[2] >= 0.0;
    step = fabs(v[2]);
    if (step < 1.0)
        step = 15.0;
    if (n < 2)
        step = 5.0;
    a0 = o->d[3];
    if (sw < 0.0) {
        a0 = wrap_pi(a0 + sw);
        sw = -sw;
    }
    if (full || sw > 6.283185207179586) {
        full = 1;
        a0 = 0.0;
        sw = 2.0 * PI;
    }
    rb = rt = o->d[2];
    fb = ft = o->d[6] > 0.0 ? o->d[6] : 1.0;
    tcx = o->d[0];
    tcy = o->d[1];
    if (n > 3) {
        tcx += v[3] * k_unit;
        tcy += v[4] * k_unit;
    }
    if (n > 5) {
        if (n != 6 && v[5] >= 1e-07)
            ft = v[6] / v[5];
        rt = v[5] * k_unit;
    }
    rot_set(&tb, o->d[0], o->d[1], o->d[5]);
    rot_set(&tt, tcx, tcy, o->d[5]);
    if (rings && m_mode == 3 && n < 8) {
        rings = 0;
        arc_ell(o, base, o->d[0], o->d[1], h, rb, fb, o->d[5], a0, sw, full);
        if (n > 1)
            arc_ell(o, base, tcx, tcy, dd, rt, ft, o->d[5], a0, sw, full);
    }
    cnt = (int)(sw / (step * PI / 180.0) + 0.5);
    if (cnt < 1)
        cnt = 1;
    da = sw / cnt;
    if (fabs(v[7]) > 1.0) {
        /* 螺旋: 角 v7 を 刻みで割り、高さ・中心・半径・扁平率を 一刻みずつ */
        double dz, dx, dy, dr, df, R = v[8] * k_unit, Z = v[9] * k_unit;
        double A = v[10] * PI / 180.0, r = rb, f = fb, ox = 0.0, oy = 0.0, z = h, a = a0;

        cnt = (int)(fabs(v[7]) / step + 0.5);
        if (cnt < 1)
            cnt = 1;
        da = (v[7] / cnt) * PI / 180.0;
        dz = (dd - h) / cnt;
        dx = v[3] * k_unit / cnt;
        dy = v[4] * k_unit / cnt;
        dr = (rt - rb) / cnt;
        df = (ft - fb) / cnt;
        for (i = 1; i <= cnt; i++) {
            double b = a + da, r2 = r + dr, f2 = f + df, ox2 = ox + dx, oy2 = oy + dy;
            double z2 = z + dz, px, py, qx, qy, sx, sy, ux, uy;

            rot_pt(&tb, r * cos(a), r * sin(a) * f, &px, &py);
            rot_pt(&tb, r2 * cos(b), r2 * sin(b) * f2, &qx, &qy);
            px += ox;
            py += oy;
            qx += ox2;
            qy += oy2;
            if (rings)
                arc_seg(o, base, px, py, z, qx, qy, z2);
            if (n > 8) {
                rot_pt(&tb, (r + R) * cos(a + A), (r + R) * sin(a + A) * f, &sx, &sy);
                rot_pt(&tb, (r2 + R) * cos(b + A), (r2 + R) * sin(b + A) * f2, &ux, &uy);
                sx += ox;
                sy += oy;
                ux += ox2;
                uy += oy2;
                if (rings)
                    arc_seg(o, base, sx, sy, z + Z, ux, uy, z2 + Z);
                if (i == 1 && !full)
                    arc_seg(o, base, px, py, z, sx, sy, z + Z);
                arc_seg(o, base, qx, qy, z2, ux, uy, z2 + Z);
            }
            a = b;
            r = r2;
            f = f2;
            ox = ox2;
            oy = oy2;
            z = z2;
        }
        return;
    }
    for (i = 1; i <= cnt; i++) {
        double a = a0, b = a + da, x1, y1, x2, y2, x3, y3, x4, y4;

        a0 = b;                         /* 0x6650 に一刻みずつ足す */
        rot_pt(&tb, rb * cos(a), rb * sin(a) * fb, &x1, &y1);
        rot_pt(&tb, rb * cos(b), rb * sin(b) * fb, &x2, &y2);
        if (rings)
            arc_seg(o, base, x1, y1, h, x2, y2, h);
        if (n > 1) {
            rot_pt(&tt, rt * cos(a), rt * sin(a) * ft, &x3, &y3);
            rot_pt(&tt, rt * cos(b), rt * sin(b) * ft, &x4, &y4);
            if (rings)
                arc_seg(o, base, x3, y3, dd, x4, y4, dd);
            if (i == 1 && !full)
                arc_seg(o, base, x1, y1, h, x3, y3, dd);
            arc_seg(o, base, x2, y2, h, x4, y4, dd);
        }
    }
}

/* ---- ソリッドの面（FUN_00615f90 → CData3DSolid）。逆コンパイルの読み、原典では
 * 押していない。四隅（+8 +0x18 +0x68 +0x78）それぞれに 0.001 以内で置いた 同じ
 * レイヤの文字を "%lg,%lg,…"（FUN_006208a0 の 0、v/h の印だけ）で読み、四つとも数が
 * 二つ以上なら 二段（高さの面と奥行の面）、そうでなければ 高さの面だけ。文字が
 * 一つも無く レイヤ名が #lh なら 四隅とも 高さ #lh・奥行 0 の二段（#lh が 0 なら
 * 一段）。面は 底上げを足した 平らでない四角で、色はソリッドの色。
 * 描き（CData3DSolid の slot 15 → FUN_0043f7a0）は 四隅を線と同じに写し、透視・
 * 鳥瞰は 奥行 1 で切って（五角になれば 二つ目の (0,3,4,4)）、塗りのソリッドとして
 * 描く。面は線より先に組まれ 先に描かれるので（リストの後ろへ足す FUN_004142e0）、
 * 隠れるのは 先の面が 後の面に 塗られるところだけ。裏の面を落とす +0x518 は
 * ソリッドの面では 0（円ソリッドの帯だけ 立つ）。
 * 壁（FUN_00438f50 が 1: p3 p4 が p1p2 の線の上、0x6160d8）は p3 := p2・p4 := p1 に
 * 置き換え（FUN_004988c0 二つ）、一・二隅に 数が二つ以上なら 三・四隅の高さを その奥行にして
 * 一段。#lh の後ろの v V（旗 1）・h H（旗 2）は FUN_00457e50 = wcschr（四文字目から）で
 * +0x89e0 に、字の末尾の v h が 後から 旗を上書きし、旗 2 は 一段目、旗 1 は 二段目を
 * 作らない（段が一つなら 0）。四隅の字の v h は 二組の線（P1P2・P3P4）の +0x48 の旗
 * （隅 1・3 に 1・4、隅 2・4 に 2・8）として gx_pair へ。勾配の面（+0x99e0）は 一段
 * （#lh の字なしの道は除く）。面が 8 の字・潰れ・平らでない（FUN_0061bc30）なら +0x5d を
 * 立て、手前（奥行 1）より 後ろに かかる面は 切らずに 描かない（FUN_0043f7a0）。
 * 勾配の補助線は gx_pair */
typedef struct {
    double p[4][3];
    unsigned char ltype;
    unsigned short color, layer, lgroup;
    int n;
    int cull;                   /* +0x518（FUN_0043f7a0: 表向きでない面は 描かない） */
    int nocut;                  /* +0x5d（FUN_0061bc30 が 0 でない面: 手前で切らず 捨てる） */
} d25_face;

static d25_face *fc;
static int nfc, cfc;

/* FUN_0061bc30（FUN_00615f90 の 0x616dce）。四隅 P1..P4（x y z。z は 底上げ・勾配の前の
 * 高さ）を 二本の 3D 線 P1P2・P3P4 で受け、0 でないとき 面の +0x5d を立てる。
 * 逆コンパイルの読み（x86 の命令で 5f88f0・5f8b60・5f8c20・5f97f0 の引数を確かめた）、
 * 原典では押していない。
 *   平面 (x,y) で 隣り合う三点の外積 (x[i+1]-x[i])(y[i+2]-y[i]) - (x[i+2]-x[i])(y[i+1]-y[i])
 *     （i=0..3、点は P1 P2 P3 P4 P1 P2）が 1e-7 以上離れたものの 二つ目以降が 0 以下なら 1。
 *   P1P2 が 平面で 一点なら 2。P3P4 が 一点なら 0。
 *   P1P2 の線に対する P3・P4 の 沿い u・横 v（FUN_005f8b60・FUN_005f8c20 の 旗 1）。
 *     |v3| か |v4| が 1e-7 より小さければ 0。
 *   k = (z2-z1)/P1P2 の長さ。(0,u3 k)→(v3, z3-z1) の線（FUN_005f97f0）の 原点 y を u4 k
 *     に替えて、点 (v4, z4-z1) までの 横 が 1e-7 より大きければ -2。なければ 0（平らな面）。 */
static int face_split(const double p[4][3])
{
    double ox = p[0][0], oy = p[0][1], dx, dy, len, u3, v3, u4, v4, k, a0, a1, a2, a3, bx, by;
    int i, seen = 0;

    for (i = 0; i < 4; i++) {
        const double *a = p[i], *b = p[(i + 1) & 3], *c = p[(i + 2) & 3];
        double cr = (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]);

        if (fabs(cr) >= 1e-07) {
            if (cr <= 0.0 && seen)
                return 1;
            seen = 1;
        }
    }
    if (fabs(p[1][1] - p[0][1]) < 1e-07 && fabs(p[1][0] - p[0][0]) < 1e-07)
        return 2;
    if (fabs(p[3][1] - p[2][1]) < 1e-07 && fabs(p[3][0] - p[2][0]) < 1e-07)
        return 0;
    dx = p[1][0] - ox;
    dy = p[1][1] - oy;
    len = sqrt(dx * dx + dy * dy);
    dx /= len;
    dy /= len;
    u3 = (p[2][0] - ox) * dx + (p[2][1] - oy) * dy;
    v3 = (p[2][1] - oy) * dx - (p[2][0] - ox) * dy;
    u4 = (p[3][0] - ox) * dx + (p[3][1] - oy) * dy;
    v4 = (p[3][1] - oy) * dx - (p[3][0] - ox) * dy;
    if (fabs(v3) < 1e-07 || fabs(v4) < 1e-07)
        return 0;
    k = (p[1][2] - p[0][2]) / len;
    a0 = 0.0;                           /* 線の原点 x */
    a1 = u3 * k;                        /* 原点 y（後で u4 k） */
    a2 = v3 - a0;
    a3 = (p[2][2] - p[0][2]) - a1;
    {
        double l2 = sqrt(a2 * a2 + a3 * a3);

        if (fabs(a2) + fabs(a3) < 1e-07) {
            a2 = 1.0;
            a3 = 0.0;
        } else {
            a2 /= l2;
            a3 /= l2;
        }
    }
    a1 = u4 * k;
    bx = v4 - a0;
    by = (p[3][2] - p[0][2]) - a1;
    return fabs(by * a2 - bx * a3) > 1e-07 ? -2 : 0;
}

static void one_solid(const jw_drawing *d, const jw_obj *o, double base, int lh, double lh_h,
                      int lhf)
{
    double hv[4] = { 0 }, dv[4] = { 0 }, cxy[4][2];
    int cnt[4] = { 0 }, c, j, lvl, i, wall = 0;
    unsigned fb[2] = { 0, 0 };          /* 四隅の字の v h の旗（0x6164xx: 1・4 と 2・8、二組） */

    for (c = 0; c < 4; c++) {
        cxy[c][0] = o->d[2 * c];
        cxy[c][1] = o->d[2 * c + 1];
    }
    {
        double ax = cxy[1][0] - cxy[0][0], ay = cxy[1][1] - cxy[0][1];

        if (sqrt(ax * ax + ay * ay) < 1e-07)
            return;
        /* FUN_00438f50: p3 p4 が p1p2 の線の上なら 1（壁）。FUN_00615f90 の 0x6160d8 は
           p3 := p2、p4 := p1 に置き換える（FUN_004988c0 の二つ。四隅の字の読みもその後） */
        {
            double l = sqrt(ax * ax + ay * ay);
            double c3 = ((cxy[2][0] - cxy[0][0]) * ay - (cxy[2][1] - cxy[0][1]) * ax) / l;
            double c4 = ((cxy[3][0] - cxy[0][0]) * ay - (cxy[3][1] - cxy[0][1]) * ax) / l;

            if (fabs(c3) < 1e-07 && fabs(c4) < 1e-07) {
                wall = 1;
                cxy[2][0] = cxy[1][0];
                cxy[2][1] = cxy[1][1];
                cxy[3][0] = cxy[0][0];
                cxy[3][1] = cxy[0][1];
            }
        }
    }
    for (j = 0; j < d->ndrawn; j++) {
        const jw_obj *t = &d->obj[j];

        if (t->cls != JW_MOJI || t->sub || t->layer != o->layer || t->lgroup != o->lgroup)
            continue;
        for (c = 0; c < 4; c++) {
            double ex = t->d[0] - cxy[c][0], ey = t->d[1] - cxy[c][1], hh, dd;
            int kind;

            if (sqrt(ex * ex + ey * ey) > 0.001)
                continue;
            cnt[c] = text_vals(d, t, &hh, &dd, &kind);
            hv[c] = hh;
            dv[c] = dd;
            if (kind) {
                lhf = kind;             /* 字の末尾が 旗を 上書き（[ebp-0x6c74] = kind） */
                fb[c >> 1] |= (c & 1) ? 2u : 1u;
                if (kind == 2)
                    fb[c >> 1] |= (c & 1) ? 8u : 4u;
            }
        }
    }
    lvl = 1;
    if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0 && lh) {
        lvl = fabs(lh_h) < 1e-07 ? 1 : 2;
        for (c = 0; c < 4; c++) {
            hv[c] = lh_h;
            dv[c] = 0.0;
        }
    } else {
        if (cnt[0] > 1 && cnt[1] > 1 && cnt[2] > 1 && cnt[3] > 1)
            lvl = 2;
        if (gx[o->lgroup][o->layer].on)
            lvl = 1;                    /* +0x99e0（勾配の面）は 一段 */
    }
    /* 壁で 一・二隅に 数が二つ以上: 三・四隅の高さを 奥行にして 一段（0x6161xx の後、
       in_ECX+0x4c8 = +0x4d0・+0x578 = +0x580） */
    if (cnt[0] > 1 && cnt[1] > 1 && wall) {
        hv[2] = dv[2];
        hv[3] = dv[3];
        lvl = 1;
    }
    if (lvl < 2)
        lhf = 0;                        /* #lh の後ろの v/h の旗は 二段のときだけ（local_6c78） */
    for (i = 1; i <= lvl; i++) {
        d25_face f;

        if ((i == 1 && lhf == 2) || (i == 2 && lhf == 1))
            continue;
        if (nfc == cfc) {
            int m = cfc ? cfc * 2 : 16;
            d25_face *q = (d25_face *)realloc(fc, (size_t)m * sizeof *q);

            if (!q)
                return;
            fc = q;
            cfc = m;
        }
        for (c = 0; c < 4; c++) {
            f.p[c][0] = cxy[c][0];
            f.p[c][1] = cxy[c][1];
            f.p[c][2] = i == 1 ? hv[c] : dv[c];
        }
        /* 勾配の補助線（FUN_00615f90 の 0x616dxx: 二点の組 二つを FUN_006109b0、旗 0・
           param_3 0。組は 1-2・3-4 と読んだ） */
        gx_pair(o, &f.p[0][0], fb[0], 0, 0.0);
        gx_pair(o, &f.p[2][0], fb[1], 0, 0.0);
        for (c = 0; c < 4; c++)
            f.p[c][2] += base;
        f.ltype = o->ltype;
        f.color = o->color;
        f.layer = o->layer;
        f.lgroup = o->lgroup;
        f.n = o->n;
        {
            double q[4][3];

            for (c = 0; c < 4; c++) {
                q[c][0] = cxy[c][0];
                q[c][1] = cxy[c][1];
                q[c][2] = i == 1 ? hv[c] : dv[c];
            }
            f.nocut = face_split(q) != 0;
            f.cull = 0;
        }
        fc[nfc++] = f;
    }
}

/* ---- 円ソリッド（線種 100 以上の CDataSolid、FUN_0060e6d0）。逆コンパイルの読み
 * （落ちた this と 立体の四隅の置き場 +0x258 +0x270 +0x288 +0x2a0 は x86 の命令で読んだ）、
 * 原典では押していない。
 * FUN_00437050（円ソリッドを円弧に）: 中心 (d0,d1)・半径 |d2|・扁平 |d3|・傾き d4・
 * 始め d5・開き d6。d7 < 10 かつ |d6| ≤ 2π なら 部分: 種別 0、4 < d7 < 6 なら 1（弓形）、
 * d7 ≤ -0.5 で 線種 < 110 で 0.001744 < |d6| < π/2 なら -1（円外側）。それ以外は 全円
 * （始め 0・開き 2π、種別 2）。線種 > 109 なら 種別に 10 を足す（輪郭だけ）。
 * 線種 105・106 は 輪: 内側の半径（+0xa0）は 8 つ目の値（d[7]、FUN_0042ebf0 が +0xa0 に
 * 移し +0x80 を 0 に）。種別 100・200。面の道（扁平が 1 でない・透視図・n>7）は
 * 内側の A・外側の A・外側の B・内側の B の帯、扁平 1 のアイソメの楕円の道は 外側だけ。
 * 字（中心から 0.001 以内、同じレイヤの 最初の文字）を FUN_006208a0 で読み、数 n・
 * 末尾の種別。n=0 かつ #lh なら (#lh, 0) の二つ。
 *   段 L: n ≥ 8 は 1、n 4..7 は 2（二段目は 中心 += (v3,v4)・n>5 で 半径 v5・n>6 で
 *   扁平 v6/半径）、n 2..3 は 2、#lh の字なしは |#lh| ≥ 1e-7 なら 2。勾配の面（+0x99e0）は 1。
 *   種別 10..99（輪郭）は n < 2 で 奥行 = 高さ・型 1、n ≥ 2 で 型 2、どちらも 一段。
 *   段が 1 つなら 旗（#lh の後ろの v h・字の末尾の v h）は 0。
 * 立体を作る道: 型 2・立体が アイソメ（+0x82ec が 3）でない・n > 7 のどれかなら 面を、
 * そうでなければ 楕円（FUN_00619710）を 一段目（旗が 2 でなければ）・二段目（段 2・
 * 扁平 ≥ 0.01・半径 > 1e-7・旗が 1 でなければ）の高さに 置く。
 * 面の道: 一段ごとに（扁平 ≥ 0.01・半径 > 1e-7 の間）弧を 刻み（v2 の絶対値、1 未満は 15、
 * n < 2 は 5）で割り、一刻みごとに 型 0 は 中心・A・B・B の扇（種別 1 は 弦の真ん中が
 * 中心、-1 は 両端の接線の交点）、型 1・2 は 一段目の A・B と 二段目（要素 2 の中心・半径・
 * 扁平）の B・A（高さは 奥行）の帯。型 2 で v2 が負なら 裏の面を落とす +0x518。
 * 勾配は 二組（P1P2・P3P4）を 字の末尾の旗（0 でなければ 3、h は 0xf）、has4 で
 * 中心の y。面の線種は 原典の初期値を読んでいない ので 1。 */
static void cs_face(const jw_obj *o, double base, const double q[4][3], int cull, unsigned fl)
{
    d25_face f;
    int c;

    if (nfc == cfc) {
        int m = cfc ? cfc * 2 : 16;
        d25_face *r = (d25_face *)realloc(fc, (size_t)m * sizeof *r);

        if (!r)
            return;
        fc = r;
        cfc = m;
    }
    for (c = 0; c < 4; c++) {
        f.p[c][0] = q[c][0];
        f.p[c][1] = q[c][1];
        f.p[c][2] = q[c][2];
    }
    gx_xf(o, &f.p[0][0], fl, 1, o->d[1], -1);
    gx_xf(o, &f.p[2][0], fl, 1, o->d[1], -1);
    for (c = 0; c < 4; c++)
        f.p[c][2] += base;
    f.ltype = 1;
    f.color = o->color;
    f.layer = o->layer;
    f.lgroup = o->lgroup;
    f.n = o->n;
    f.cull = cull;
    f.nocut = 0;
    fc[nfc++] = f;
}

static void one_csolid(const jw_drawing *d, const jw_obj *o, double base, int lh, double lh_h,
                       int lhf)
{
    double v[12], cxo = o->d[0], cyo = o->d[1], r, flat, tilt, a0, sw, d7 = o->d[7];
    double inner = 0.0, ein_r = 0.0, ein_f = 0.0;    /* 輪（線種 105・106）の内側 */
    double ec[3][2], er[3], ef[3];      /* 要素 1・2（段ごとの 中心・半径・扁平） */
    int kind, n = 0, tk = 0, j, L, mode, i, lvl, rings_neg;
    d25_rot rot;
    jw_obj fake;
    unsigned fl;

    r = fabs(o->d[2]);
    flat = fabs(o->d[3]);
    tilt = o->d[4];
    a0 = o->d[5];
    sw = o->d[6];
    if (o->ltype == 105 || o->ltype == 106) {
        /* FUN_0042ebf0（読み込み、0x42ec6f..）: 線種 i・j は +0xa0（内側の半径）= 8 つ目の値、
           +0x80 は 0。0 は 「d7 < 10」なので 部分の円（開きが 2π 以内なら） */
        inner = d7;
        d7 = 0.0;
    }
    if (d7 < 10.0 && fabs(sw) <= 6.283185207179586) {
        kind = 0;
        if (d7 > 4.0 && d7 < 6.0)
            kind = 1;
        if (d7 <= -0.5 && o->ltype < 110 && fabs(sw) > 0.001744 && fabs(sw) < 1.5707964267948966)
            kind = -1;
    } else {
        a0 = 0.0;
        sw = 2.0 * PI;
        kind = 2;
    }
    if (o->ltype > 109)
        kind += 10;
    if (o->ltype == 105)                /* FUN_00437050 の 0x4373a3.. */
        kind = 100;
    if (o->ltype == 106)
        kind = 200;
    if (r < 1e-07 || fabs(sw) < 1e-07)
        return;
    if (sw < 0.0) {
        a0 = wrap_pi(a0 + sw);
        sw = -sw;
    }
    memset(v, 0, sizeof v);
    for (j = 0; j < d->ndrawn; j++) {
        const jw_obj *t = &d->obj[j];
        double ex, ey;

        if (t->cls != JW_MOJI || t->sub || t->layer != o->layer || t->lgroup != o->lgroup)
            continue;
        ex = t->d[0] - cxo;
        ey = t->d[1] - cyo;
        if (sqrt(ex * ex + ey * ey) > 0.001)
            continue;
        {
            const char *s = t->text >= 0 ? jw_str(d, t->text) : "";
            char buf[512], c;
            size_t q, m = 0;

            for (q = 0; s[q] && m + 1 < sizeof buf; q++)
                if (s[q] != ' ')
                    buf[m++] = s[q];
            buf[m] = 0;
            n = scan_list(buf, v, 12);
            c = m ? buf[m - 1] : 0;
            if (n > 0 && m > 0) {
                if (c == 'v' || c == 'V')
                    tk = 1;
                if (c == 'h' || c == 'H')
                    tk = 2;
                if (c == 't')
                    tk = 20;
                if (c == 'T')
                    tk = 21;
                if (c == 'd')
                    tk = 30;
                if (c == 'D')
                    tk = 31;
            }
        }
        break;
    }
    if (n < 0)
        n = 0;
    if (tk)
        lhf = tk;
    /* 扁平率 0.1 で 高さ ≥ 1000 m は 描かない（0x60edb2） */
    if (fabs(flat - 0.1) < 1e-07 && v[0] >= 999.9999999)
        return;
    v[0] *= k_unit;
    v[1] *= k_unit;
    ec[1][0] = ec[2][0] = cxo;
    ec[1][1] = ec[2][1] = cyo;
    er[1] = er[2] = r;
    ef[1] = ef[2] = flat;
    L = 1;
    if (n == 0 && lh) {
        L = fabs(lh_h) < 1e-07 ? 1 : 2;
        n = 2;
        v[0] = lh_h;
        v[1] = 0.0;
    } else {
        if (n < 8) {
            if (n < 4) {
                if (n > 1)
                    L = 2;
            } else {
                L = 2;
                ec[2][0] += v[3] * k_unit;
                if (n > 4)
                    ec[2][1] += v[4] * k_unit;
                if (n > 5)
                    er[2] = v[5] * k_unit;
                if (n > 6 && er[2] > 1e-07)
                    ef[2] = v[6] * k_unit / er[2];
            }
        } else
            L = 1;
        if (gx[o->lgroup][o->layer].on)
            L = 1;
    }
    rings_neg = v[2] < 0.0;
    mode = 0;
    if (kind > 9 && kind < 100) {
        if (n < 2) {
            v[1] = v[0];
            mode = 1;
        } else
            mode = 2;
        L = 1;
    }
    if (L < 2)
        lhf = 0;
    fl = tk == 0 ? 0u : tk == 2 ? 0xfu : 3u;
    fake = *o;
    fake.cls = JW_ENKO;
    fake.ltype = 1;
    fake.color = o->color < 10 ? o->color : 1;
    if (kind > 99) {
        /* FUN_00437050 の 0x4373f1..: 内側の弧は 外と同じ（中心・傾き・始め・開き）で
           半径 |+0xa0|、扁平は 105 なら 外と同じ、106 なら (R·扁平 − (R − 内側)) / 内側
           （0 より小さければ 0） */
        ein_r = fabs(inner);
        ein_f = flat;
        if (kind > 199) {
            ein_f = (r * flat - (r - inner)) / inner;
            if (ein_f < 0.0)
                ein_f = 0.0;
        }
    }
    /* 輪は 扁平が 1 でないと（1±1e-7）面の道（0x60efc7..）。1 の円は 楕円の道で 外側だけ
       （内側の楕円を FUN_00619710 が どう置くかは 読んでいない） */
    if (mode == 2 || m_mode != 3 || n > 7 ||
        (kind > 99 && (flat >= 1.0000001 || flat <= 0.9999999))) {
        double step = fabs(v[2]), cc[2], z, da;
        int segs;

        if (step < 1.0)
            step = 15.0;
        if (n < 2)
            step = 5.0;
        segs = (int)(sw / (step * PI / 180.0) + 0.5);
        if (segs < 1)
            segs = 1;
        da = sw / segs;
        for (lvl = 1; lvl <= L && flat >= 0.01 && r > 1e-07; lvl++) {
            double a = a0;

            z = lvl == 1 ? v[0] : v[1];
            cc[0] = ec[lvl][0];
            cc[1] = ec[lvl][1];
            if (kind % 10 == 1) {       /* FUN_0043af40: 弦の真ん中（部分のときだけ） */
                d25_rot re;
                double p0x = r * cos(a0), p0y = r * sin(a0) * flat;
                double p1x = r * cos(a0 + sw), p1y = r * sin(a0 + sw) * flat, x0, y0, x1, y1;

                if (2.0 * PI - fabs(sw) > 1e-07) {
                    rot_set(&re, cxo, cyo, tilt);
                    rot_pt(&re, p0x, p0y, &x0, &y0);
                    rot_pt(&re, p1x, p1y, &x1, &y1);
                    if (fabs(x1 - x0) > 1e-07 || fabs(y1 - y0) > 1e-07) {
                        cc[0] = (x0 + x1) / 2.0;
                        cc[1] = (y0 + y1) / 2.0;
                    }
                }
            }
            if (kind == -1) {           /* FUN_0043a8d0: 両端の接線の交点 */
                double t0 = a0, t1 = a0 + sw;
                double x0 = r * cos(t0), y0 = r * flat * sin(t0);
                double x1 = r * cos(t1), y1 = r * flat * sin(t1);
                double dx0 = -r * sin(t0), dy0 = r * flat * cos(t0);
                double dx1 = -r * sin(t1), dy1 = r * flat * cos(t1);
                double den = dx0 * dy1 - dy0 * dx1;

                if (den != 0.0) {
                    double u = ((x1 - x0) * dy1 - (y1 - y0) * dx1) / den, qx, qy;
                    d25_rot re;

                    qx = x0 + u * dx0;
                    qy = y0 + u * dy0;
                    rot_set(&re, cxo, cyo, tilt);
                    rot_pt(&re, qx, qy, &cc[0], &cc[1]);
                }
            }
            rot_set(&rot, ec[lvl][0], ec[lvl][1], tilt);
            for (i = 1; i <= segs; i++) {
                double b = a + da, ax, ay, bx, by, q[4][3];
                d25_rot r2;

                rot_pt(&rot, er[lvl] * cos(a), er[lvl] * sin(a) * ef[lvl], &ax, &ay);
                rot_pt(&rot, er[lvl] * cos(b), er[lvl] * sin(b) * ef[lvl], &bx, &by);
                if (kind > 99) {        /* 輪: 内側の A → 外側の A → 外側の B → 内側の B（高さは 段の） */
                    double ia, ib, ja, jb;

                    rot_pt(&rot, ein_r * cos(a), ein_r * sin(a) * ein_f, &ia, &ib);
                    rot_pt(&rot, ein_r * cos(b), ein_r * sin(b) * ein_f, &ja, &jb);
                    q[0][0] = ia; q[0][1] = ib; q[0][2] = z;
                    q[1][0] = ax; q[1][1] = ay; q[1][2] = z;
                    q[2][0] = bx; q[2][1] = by; q[2][2] = z;
                    q[3][0] = ja; q[3][1] = jb; q[3][2] = z;
                } else if (mode == 0) {
                    q[0][0] = cc[0]; q[0][1] = cc[1]; q[0][2] = z;
                    q[1][0] = ax; q[1][1] = ay; q[1][2] = z;
                    q[2][0] = bx; q[2][1] = by; q[2][2] = z;
                    q[3][0] = bx; q[3][1] = by; q[3][2] = z;
                } else {
                    double a2x, a2y, b2x, b2y;

                    rot_set(&r2, ec[2][0], ec[2][1], tilt);
                    rot_pt(&r2, er[2] * cos(a), er[2] * sin(a) * ef[2], &a2x, &a2y);
                    rot_pt(&r2, er[2] * cos(b), er[2] * sin(b) * ef[2], &b2x, &b2y);
                    q[0][0] = ax; q[0][1] = ay; q[0][2] = z;
                    q[1][0] = bx; q[1][1] = by; q[1][2] = z;
                    q[2][0] = b2x; q[2][1] = b2y; q[2][2] = v[1];
                    q[3][0] = a2x; q[3][1] = a2y; q[3][2] = v[1];
                }
                cs_face(o, base, q, mode > 1 && rings_neg, fl);
                a = b;
            }
        }
    } else {
        if (lhf != 2)
            arc_ell(&fake, base, ec[1][0], ec[1][1], v[0], er[1], ef[1], tilt, a0, sw,
                    kind % 10 == 2);
        if (L == 2 && flat >= 0.01 && r > 1e-07 && lhf != 1)
            arc_ell(&fake, base, ec[2][0], ec[2][1], v[1], er[2], ef[2], tilt, a0, sw,
                    kind % 10 == 2);
    }
}

/* FUN_00617f70: 立体を組み、真ん中と半径を出す。線が無ければ 0 */
static int build(const jw_drawing *d)
{
    double base[16][16], lhh[16][16];
    int lh[16][16], lhf[16][16], g, l, i;
    unsigned char *used;

    nln = 0;
    nel = 0;
    nfc = 0;
    take_snap(d, snap);
    k_unit = 1.0 / write_scale(d);
    if (!m_mm)
        k_unit *= 1000.0;
    gx_setup(d);                        /* FUN_006129c0（0x6187e8） */
    for (g = 0; g < 16; g++) {
        double gv = name_lv(d, d->group[g].name);

        for (l = 0; l < 16; l++) {
            int off = d->group[g].layer_name[l];
            const char *s = off >= 0 ? jw_str(d, off) : 0;

            base[g][l] = (gv + name_lv(d, off)) * k_unit;
            lh[g][l] = 0;
            lhf[g][l] = 0;
            lhh[g][l] = 0.0;
            if (s && s[0] == '#' && s[1] == 'l' && s[2] == 'h' && strlen(s) > 3) {
                const char *p = s + 3;
                double v = 0.0;

                scan_num(&p, &v);
                lh[g][l] = 1;
                lhh[g][l] = v * k_unit;
                /* +0x89e0（0x6185d8..）: 五文字目からに v V なら 1、h H なら 2（後のが勝つ）。
                   FUN_00457e50 は wcschr */
                if (strlen(s) > 4) {
                    if (strchr(s + 4, 'v') || strchr(s + 4, 'V'))
                        lhf[g][l] = 1;
                    if (strchr(s + 4, 'h') || strchr(s + 4, 'H'))
                        lhf[g][l] = 2;
                }
            }
        }
    }
    /* ソリッドが先（0x6188xx）: グループ・レイヤの順に、そのレイヤの書ける要素から */
    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++)
            for (i = 0; i < d->ndrawn; i++) {
                const jw_obj *o = &d->obj[i];

                if (o->cls != JW_SOLID || o->sub || o->lgroup != g || o->layer != l
                    || !editable(d, o))
                    continue;
                if (o->ltype >= 100)    /* 円ソリッド（FUN_0060e6d0） */
                    one_csolid(d, o, base[g][l], lh[g][l], lhh[g][l], lhf[g][l]);
                else
                    one_solid(d, o, base[g][l], lh[g][l], lhh[g][l], lhf[g][l]);
            }
    used = (unsigned char *)calloc((size_t)(d->ndrawn > 0 ? d->ndrawn : 1), 1);
    if (!used)
        return 0;
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double dx, dy;

        if ((o->cls != JW_SEN && o->cls != JW_ENKO) || o->sub || o->layer > 15
            || o->lgroup > 15 || o->ltype == 9 || !editable(d, o))
            continue;
        if (o->cls == JW_ENKO) {        /* FUN_0061e030 */
            one_arc(d, o, base[o->lgroup][o->layer], lh[o->lgroup][o->layer],
                    lhh[o->lgroup][o->layer]);
            continue;
        }
        dx = o->d[2] - o->d[0];
        dy = o->d[3] - o->d[1];
        if (sqrt(dx * dx + dy * dy) < 1e-07)
            continue;
        one_line(d, o, used, base[o->lgroup][o->layer], lh[o->lgroup][o->layer],
                 lhh[o->lgroup][o->layer]);
    }
    free(used);
    if (!nln && !nel && !nfc)
        return 0;
    cx = cy = cz = 0.0;
    for (i = 0; i < nln; i++) {
        cx += (ln[i].p[0] + ln[i].p[3]) / 2.0;
        cy += (ln[i].p[1] + ln[i].p[4]) / 2.0;
        cz += (ln[i].p[2] + ln[i].p[5]) / 2.0;
    }
    /* 楕円（CData3DEnko）は中心を一つと数える（原典は要素の囲みの真ん中
       FUN_00498a70。移植は線の中点の平均と同じ扱いにした） */
    for (i = 0; i < nel; i++) {
        cx += el[i].c[0];
        cy += el[i].c[1];
        cz += el[i].c[2];
    }
    for (i = 0; i < nfc; i++) {        /* 面は 四隅の平均を一つと数える */
        int c;

        for (c = 0; c < 4; c++) {
            cx += fc[i].p[c][0] / 4.0;
            cy += fc[i].p[c][1] / 4.0;
            cz += fc[i].p[c][2] / 4.0;
        }
    }
    cx /= nln + nel + nfc;
    cy /= nln + nel + nfc;
    cz /= nln + nel + nfc;
    if (m_mode < 3)
        cz = 0.0;
    r_xy = r_z = -1e21;
    for (i = 0; i < nln; i++) {
        int e;

        for (e = 0; e < 2; e++) {
            double x = ln[i].p[3 * e] - cx, y = ln[i].p[3 * e + 1] - cy;
            double z = ln[i].p[3 * e + 2] - cz, r = sqrt(x * x + y * y);

            if (r > r_xy)
                r_xy = r;
            if (z > r_z)
                r_z = z;
        }
    }
    for (i = 0; i < nel; i++) {
        double x = el[i].c[0] - cx, y = el[i].c[1] - cy, z = el[i].c[2] - cz;
        double r = sqrt(x * x + y * y) + el[i].r * (el[i].flat > 1.0 ? el[i].flat : 1.0);

        if (r > r_xy)
            r_xy = r;
        if (z > r_z)
            r_z = z;
    }
    for (i = 0; i < nfc; i++) {
        int c;

        for (c = 0; c < 4; c++) {
            double x = fc[i].p[c][0] - cx, y = fc[i].p[c][1] - cy, z = fc[i].p[c][2] - cz;

            if (sqrt(x * x + y * y) > r_xy)
                r_xy = sqrt(x * x + y * y);
            if (z > r_z)
                r_z = z;
        }
    }
    return 1;
}

/* slot 25 FUN_00611340: 段に入る */
static void enter(const jw_drawing *d, int mode)
{
    double paper = d ? d->paper_hh * 2.0 : 420.0, q;

    m_mode = mode;
    if (d)
        build(d);
    else
        nln = 0;
    q = (double)(int)(paper * 2.0 / 10.0);
    if (q < 1.0)
        q = 1.0;
    q *= 10.0;
    f_half = q / 2.0;
    b_scale = d ? write_scale(d) : 1.0;
    if (mode == 1) {
        if (!init1) {
            init1 = 1;
            s1h = (m_mm ? 2.0 : 2000.0) / b_scale;
            s1d = -q;
            s1a = -45.0;
        }
        b_ph = s1h;
        b_pd = s1d;
        b_ang = s1a;
    } else if (mode == 2) {
        if (!init2) {
            init2 = 1;
            s2h = q;
            s2d = -q;
            s2a = -45.0;
        }
        b_bh = s2h;
        b_bd = s2d;
        b_ang = s2a;
    } else if (mode == 3) {
        if (!init3) {
            init3 = 1;
            s3p = iso_angle();
            s3a = -45.0;
        }
        b_iso = s3p;
        b_ang = s3a;
    }
    eye_x = 0.0;
    eye_dy = 0.0;
}

typedef struct {
    double c, s, pc, ps, ex, ey, ez, f;
} d25_cam;

/* FUN_005f9a30 の 0 と ±1 の丸め */
static void cs_of(double deg, double *c, double *s)
{
    double a = deg * PI / 180.0;

    *c = cos(a);
    *s = sin(a);
    if (fabs(*c) < 1e-15 || fabs(*s) == 1.0)
        *c = 0.0;
    if (fabs(*s) < 1e-15 || fabs(*c) == 1.0)
        *s = 0.0;
}

/* slot 5 FUN_00617640 の前半: つまみを控えに写し、視点と焦点距離を決める */
static void prepare(const jw_drawing *d, d25_cam *k)
{
    int now[16 * 17];
    double pitch;

    if (d) {
        take_snap(d, now);
        if (memcmp(now, snap, sizeof now))
            build(d);
    }
    if (b_iso > 90.0)
        b_iso = 90.0;
    if (b_iso < -90.0)
        b_iso = -90.0;
    pitch = b_iso;
    k->ex = eye_x;
    k->ey = k->ez = 0.0;
    if (m_mode == 1) {
        s1a = b_ang;
        s1h = b_ph;
        k->ez = s1h;
        s1d = b_pd;
        k->ey = s1d;
        pitch = 0.0;
    } else if (m_mode == 2) {
        s2a = b_ang;
        s2h = b_bh;
        k->ez = s2h;
        s2d = b_bd;
        k->ey = s2d;
        pitch = atan2(k->ez, -k->ey) * 180.0 / PI;
        k->ez += eye_dy;
    } else if (m_mode == 3) {
        s3a = b_ang;
        s3p = pitch;
    }
    if (jw_cmd_bar_check(1323) <= 0 || m_mode > 2)
        k->f = f_half;
    else {
        double r = r_xy;

        k->f = sqrt(k->ey * k->ey + k->ez * k->ez);
        if (m_mode == 2)
            r = sqrt(r_xy * r_xy + r_z * r_z);
        if (k->f < r * 2.0)
            k->f = r * 2.0;
    }
    if (pitch > 90.0)
        pitch = 90.0;
    if (pitch < -90.0)
        pitch = -90.0;
    cs_of(b_ang, &k->c, &k->s);
    cs_of(pitch, &k->pc, &k->ps);
}

/* FUN_0043ecc0: 三次元の線を画面の二次元へ。視点の後ろなら 0（+0x5e が立つ） */
static int project(const d25_cam *k, const double *p, double *o)
{
    double x1 = (p[0] - cx) * k->c + (p[1] - cy) * k->s;
    double y1 = (p[1] - cy) * k->c - (p[0] - cx) * k->s;
    double x2 = (p[3] - cx) * k->c + (p[4] - cy) * k->s;
    double y2 = (p[4] - cy) * k->c - (p[3] - cx) * k->s;
    double z1 = p[2], z2 = p[5];

    if (m_mode == 3) {
        o[0] = x1;
        o[1] = (z1 - cz) * k->pc + y1 * k->ps;
        o[2] = x2;
        o[3] = (z2 - cz) * k->pc + y2 * k->ps;
        return 1;
    }
    if (m_mode == 1 || m_mode == 2) {
        double ey = k->ey, ez = k->ez, d1, d2, f, X1 = x1, X2 = x2;

        if (m_mode == 2) {
            double a1 = y1 * k->pc - (z1 - cz) * k->ps;
            double a2 = y2 * k->pc - (z2 - cz) * k->ps;
            double e1 = ey * k->pc - (ez - cz) * k->ps;

            z1 = (z1 - cz) * k->pc + y1 * k->ps;
            z2 = (z2 - cz) * k->pc + y2 * k->ps;
            ez = (ez - cz) * k->pc + ey * k->ps;
            y1 = a1;
            y2 = a2;
            ey = e1;
        }
        z1 -= ez;
        z2 -= ez;
        d1 = y1 - ey;
        d2 = y2 - ey;
        if (d1 < 1.0 && d2 < 1.0)
            return 0;
        if (d1 < 1.0) {
            double dy = y2 - y1, t;

            if (fabs(dy) < 1.0)
                return 0;
            t = ((ey + 1.0) - y1) / dy;
            X1 = (X2 - X1) * t + X1;
            z1 = (z2 - z1) * t + z1;
            d1 = 1.0;
        }
        if (d2 < 1.0) {
            double dy = y1 - y2, t;

            if (fabs(dy) < 1.0)
                return 0;
            t = ((ey + 1.0) - y2) / dy;
            X2 = (X1 - X2) * t + X2;
            z2 = (z1 - z2) * t + z2;
            d2 = 1.0;
        }
        f = k->f < 0.0 ? 0.0 : k->f;
        o[0] = (X1 - k->ex) * (f / d1);
        o[1] = z1 * (f / d1);
        o[2] = (X2 - k->ex) * (f / d2);
        o[3] = z2 * (f / d2);
        return 1;
    }
    o[0] = x1;
    o[1] = y1;
    o[2] = x2;
    o[3] = y2;
    return 1;
}

/* FUN_0043f7a0: 面の四隅を写す。透視・鳥瞰は 奥行 1 で切る（原典は 見える隅から
   回して 辺ごとに 1 の所へ寄せる 0x44071b..。移植は 同じ結果の 辺ごとの切り）。
   写した点の数（0 なら見えない、3〜5） */
static int project_face(const d25_cam *k, const d25_face *f, double o[5][2])
{
    double X[4], D[4], Z[4], px[8], pd[8], pz[8], ff;
    int c, m = 0;

    for (c = 0; c < 4; c++) {
        double x = f->p[c][0] - cx, y = f->p[c][1] - cy, z = f->p[c][2];
        double x1 = x * k->c + y * k->s, y1 = y * k->c - x * k->s;

        if (m_mode == 3) {
            o[c][0] = x1;
            o[c][1] = (z - cz) * k->pc + y1 * k->ps;
            continue;
        }
        {
            double ey = k->ey, ez = k->ez;

            if (m_mode == 2) {
                double a1 = y1 * k->pc - (z - cz) * k->ps, e1 = ey * k->pc - (ez - cz) * k->ps;

                z = (z - cz) * k->pc + y1 * k->ps;
                ez = (ez - cz) * k->pc + ey * k->ps;
                y1 = a1;
                ey = e1;
            }
            X[c] = x1;
            D[c] = y1 - ey;
            Z[c] = z - ez;
        }
    }
    if (m_mode == 3)
        return 4;
    if (D[0] < 1.0 && D[1] < 1.0 && D[2] < 1.0 && D[3] < 1.0)
        return 0;
    if (f->nocut && (D[0] < 1.0 || D[1] < 1.0 || D[2] < 1.0 || D[3] < 1.0))
        return 0;                       /* +0x5d: FUN_0043f7a0 の 0x4407xx は 切らずに 捨てる */
    for (c = 0; c < 4; c++) {
        int n = (c + 1) & 3;

        if (D[c] >= 1.0) {
            px[m] = X[c];
            pd[m] = D[c];
            pz[m] = Z[c];
            m++;
        }
        if ((D[c] >= 1.0) != (D[n] >= 1.0)) {
            double dd = D[n] - D[c], t;

            if (fabs(dd) < 1e-12)
                continue;
            t = (1.0 - D[c]) / dd;
            px[m] = X[c] + (X[n] - X[c]) * t;
            pd[m] = 1.0;
            pz[m] = Z[c] + (Z[n] - Z[c]) * t;
            m++;
        }
    }
    if (m < 3)
        return 0;
    if (m > 5)
        m = 5;
    ff = k->f < 0.0 ? 0.0 : k->f;
    for (c = 0; c < m; c++) {
        o[c][0] = (px[c] - k->ex) * (ff / pd[c]);
        o[c][1] = pz[c] * (ff / pd[c]);
    }
    if (m == 3) {
        o[3][0] = o[2][0];
        o[3][1] = o[2][1];
    }
    return m;
}

/* 面を塗りのソリッドで（五角は 二つ目に (0,3,4,4)、0x2b8）。足した数 */
static int put_face(jw_drawing *out, const d25_cam *k, const d25_face *f, int attr)
{
    double o[5][2];
    int m = project_face(k, f, o), made = 0, part;

    if (!m)
        return 0;
    if (f->cull) {                      /* FUN_0043f7a0 の 0x518: P4→P1 の線の 左に P2 が 無ければ 描かない */
        double dx = o[0][0] - o[3][0], dy = o[0][1] - o[3][1], ln = fabs(dx) + fabs(dy), dist;

        if (ln >= 1e-07) {
            ln = sqrt(dx * dx + dy * dy);
            dx /= ln;
            dy /= ln;
        } else {
            dx = 1.0;
            dy = 0.0;
        }
        dist = (o[1][1] - o[3][1]) * dx - (o[1][0] - o[3][0]) * dy;
        if (dist < 0.0)
            return 0;
    }
    for (part = 0; part < (m == 5 ? 2 : 1); part++) {
        static const int A[2][4] = { { 0, 1, 2, 3 }, { 0, 3, 4, 4 } };
        jw_obj *s = jw_add(out, JW_SOLID);
        int c;

        if (!s)
            break;
        for (c = 0; c < 4; c++) {
            s->d[2 * c] = o[A[part][c]][0];
            s->d[2 * c + 1] = o[A[part][c]][1];
        }
        s->ltype = f->ltype;
        s->color = f->color;
        s->n = f->n;
        s->width = 0;
        if (attr) {
            s->layer = f->layer;
            s->lgroup = f->lgroup;
        }
        made++;
    }
    return made;
}

static jw_obj *put(jw_drawing *out, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(out, JW_SEN);

    if (!o)
        return 0;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    o->width = 0;
    return o;
}

/* 楕円（CData3DEnko）の写し: 描くのは アイソメだけ（FUN_0043dd30 は 段 1・2 で 0）。
   原典は 囲みの四隅・端・中心を写して楕円に合わせ直す（FUN_00443fd0）。
   アイソメの写しは平らな一次の写像なので、移植は 楕円の行列を写して
   特異値に分けて同じ楕円を出す。潰れたら（短径が 0）線にする（0x490） */
static jw_obj *put_ell(jw_drawing *out, const d25_cam *k, const d25_ell *e)
{
    double ct = cos(e->tilt), st = sin(e->tilt);
    /* 楕円の点 − 中心 = R(tilt) diag(r, r·flat) (cos t, sin t) を写す */
    double m00 = k->c, m01 = k->s, m10 = -k->s * k->ps, m11 = k->c * k->ps;
    double b00 = ct * e->r, b01 = -st * e->r * e->flat, b10 = st * e->r, b11 = ct * e->r * e->flat;
    /* 勾配の補助線で起こした楕円は 軸 U V（z も）をそのまま写す */
    double p = e->gen ? m00 * e->U[0] + m01 * e->U[1] : m00 * b00 + m01 * b10;
    double q = e->gen ? m00 * e->V[0] + m01 * e->V[1] : m00 * b01 + m01 * b11;
    double r = e->gen ? m10 * e->U[0] + m11 * e->U[1] + k->pc * e->U[2] : m10 * b00 + m11 * b10;
    double t = e->gen ? m10 * e->V[0] + m11 * e->V[1] + k->pc * e->V[2] : m10 * b01 + m11 * b11;
    double E = (p + t) / 2, F = (p - t) / 2, G = (r + q) / 2, H = (r - q) / 2;
    double Q = sqrt(E * E + H * H), R = sqrt(F * F + G * G), sx = Q + R, sy = Q - R;
    double a1 = atan2(G, F), a2 = atan2(H, E), th = (a2 - a1) / 2, ph = (a2 + a1) / 2;
    double cp[3], o[4], X, Y, a0;
    jw_obj *s;

    cp[0] = e->c[0];
    cp[1] = e->c[1];
    cp[2] = e->c[2];
    {
        double pp[6];

        memcpy(pp, cp, sizeof cp);
        memcpy(pp + 3, cp, sizeof cp);
        project(k, pp, o);
    }
    X = o[0];
    Y = o[1];
    if (sx < 1e-12 || fabs(sy) < sx * 1e-9) {
        /* 潰れた楕円: 長軸の上の 弧の範囲 */
        double lo = 1e300, hi = -1e300, u[4];
        int nu = 0, j;

        if (e->full) {
            lo = -1.0;
            hi = 1.0;
        } else {
            double b = e->a0 + th, w = e->sw;

            u[nu++] = cos(b);
            u[nu++] = cos(b + w);
            for (j = -2; j <= 4; j++) {
                double z = j * PI;

                if (z > b && z < b + w)
                    u[nu < 4 ? nu++ : 3] = cos(z);
            }
            for (j = 0; j < nu; j++) {
                if (u[j] < lo)
                    lo = u[j];
                if (u[j] > hi)
                    hi = u[j];
            }
        }
        s = put(out, X + cos(ph) * sx * lo, Y + sin(ph) * sx * lo, X + cos(ph) * sx * hi,
                Y + sin(ph) * sx * hi);
    } else {
        s = jw_add(out, JW_ENKO);
        if (!s)
            return 0;
        if (sy > 0.0)
            a0 = e->a0 + th;
        else
            a0 = -(e->a0 + e->sw + th);
        s->d[0] = X;
        s->d[1] = Y;
        s->d[2] = sx;
        s->d[3] = e->full ? 0.0 : wrap_pi(a0);
        s->d[4] = e->sw;
        s->d[5] = ph;
        s->d[6] = fabs(sy) / sx;
        s->n = e->full;
        s->width = 0;
    }
    if (s) {
        s->ltype = e->ltype;
        s->color = e->color;
    }
    return s;
}

int jw_d25_view(const jw_drawing *d, jw_drawing *out)
{
    d25_cam k;
    int i, n = 0;

    if (!m_mode || !d || !out)
        return 0;
    prepare(d, &k);
    for (i = 0; i < nfc; i++)          /* 面が先（組んだ順に描く） */
        n += put_face(out, &k, &fc[i], 1);
    for (i = 0; m_mode == 3 && i < nel; i++) {
        jw_obj *s = put_ell(out, &k, &el[i]);

        if (!s)
            break;
        s->layer = el[i].layer;
        s->lgroup = el[i].lgroup;
        n++;
    }
    for (i = 0; i < nln; i++) {
        double o[4];
        jw_obj *s;

        if (!project(&k, ln[i].p, o))
            continue;
        s = put(out, o[0], o[1], o[2], o[3]);
        if (!s)
            break;
        s->ltype = ln[i].ltype;
        s->color = ln[i].color;
        s->layer = ln[i].layer;
        s->lgroup = ln[i].lgroup;
        n++;
    }
    if (m_mode == 1 || m_mode == 2) {
        /* 補助線（線種 9・色 9）の 縦の軸と 地平線。原典は ±1e21、移植は ±1e7
           で切る（画面の線の描き方に大きすぎる） */
        const double far = 1e7;
        double hy = m_mode == 1 ? 0.0 : eye_dy;
        jw_obj *s = put(out, 0.0, -far, 0.0, far);

        if (s) {
            s->ltype = 9;
            s->color = 9;
            n++;
        }
        s = put(out, -far, hy, far, hy);
        if (s) {
            s->ltype = 9;
            s->color = 9;
            n++;
        }
    }
    return n;
}

/* 押した時の Shift・Ctrl（原典 DAT_00a0cc6c・DAT_00a0cc74、jw_cmd_keymods が渡す） */
static int km_shift, km_ctrl;

void jw_d25_keymods(int shift, int ctrl)
{
    km_shift = shift != 0;
    km_ctrl = ctrl != 0;
}

/* FUN_006194a0（逆コンパイルの読み、原典では押していない）: 作図に Ctrl を押していた
 * （FUN_006119c0 の +0xb4、Shift も押していれば 0）ときの 線の間引き。長さが 0
 * （x1=x2 かつ y1=y2、差 1e-7 未満）の線は 書かず、図面の線（CDataSen、先頭から 2001
 * 本まで）に 同じ端の線（向きは逆でも）があれば 書かない。 */
static int sen_thin(const jw_drawing *d, double x0, double y0, double x1, double y1)
{
    int i, cnt = 0;

    if (fabs(x1 - x0) < 1e-07 && fabs(y1 - y0) < 1e-07)
        return 1;
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *t = &d->obj[i];

        if (t->cls != JW_SEN)
            continue;
        if (2000 < cnt)
            return 0;
        cnt++;
        if ((fabs(t->d[0] - x0) < 1e-07 && fabs(t->d[1] - y0) < 1e-07 &&
             fabs(t->d[2] - x1) < 1e-07 && fabs(t->d[3] - y1) < 1e-07) ||
            (fabs(t->d[0] - x1) < 1e-07 && fabs(t->d[1] - y1) < 1e-07 &&
             fabs(t->d[2] - x0) < 1e-07 && fabs(t->d[3] - y0) < 1e-07))
            return 1;
    }
    return 0;
}

/* slot 26 FUN_006119c0: 写した線を書込みレイヤへ（線種・線色は元の線、線幅は 0）。
   視点の後ろの線は書かず 5384「作図されない部分があります」 */
static int write_out(jw_drawing *d)
{
    d25_cam k;
    int i, made = 0, hidden = 0;
    /* FUN_006119c0（逆コンパイルの読み、原典では押していない）: Shift と Ctrl を
       一緒に押した作図は FUN_00615ca0 が 書く層を 元の線の層（+0x2e）にする
       （押さなければ 書込みレイヤ、グループはいつも 書込みの）。Ctrl だけなら 線の間引き */
    int keep = km_shift && km_ctrl, thin = km_ctrl && !km_shift;

    prepare(d, &k);
    for (i = 0; i < nfc; i++) {        /* 面はソリッドで（FUN_006119c0 の 0x6119xx） */
        int first = d->ndrawn;
        int m = put_face(d, &k, &fc[i], 0);

        if (!m && m_mode != 3)
            hidden = 1;
        made += m;
        if (keep)
            for (; first < d->ndrawn; first++)
                d->obj[first].layer = (unsigned short)fc[i].layer;
    }
    for (i = 0; m_mode == 3 && i < nel; i++) { /* 楕円は弧で（FUN_006119c0 の +0x390） */
        jw_obj *s = put_ell(d, &k, &el[i]);

        if (s) {
            if (keep)
                s->layer = (unsigned short)el[i].layer;
            made++;
        }
    }
    for (i = 0; i < nln; i++) {
        double o[4];
        jw_obj *s;

        if (!project(&k, ln[i].p, o)) {
            hidden = 1;
            continue;
        }
        if (thin && sen_thin(d, o[0], o[1], o[2], o[3]))
            continue;
        s = put(d, o[0], o[1], o[2], o[3]);
        if (!s)
            break;
        s->ltype = ln[i].ltype;
        s->color = ln[i].color;
        if (keep)
            s->layer = (unsigned short)ln[i].layer;
        made++;
    }
    m_mode = 0;
    if (hidden)
        jw_cmd_notice(5384, "\x8d\xec\x90}\x82\xb3\x82\xea\x82\xc8\x82\xa2\x95\x94\x95\xaa"
                            "\x82\xaa\x82\xa0\x82\xe8\x82\xdc\x82\xb7");
    return made;
}

/* 箱 1412「回転角間隔 ， 移動間隔」（FUN_00407390 / FUN_00407310）: 0.001 より小さければ 0.001 */
static void steps(double *ang, double *mov)
{
    const char *t = jw_cmd_box(1412);
    double v[2] = { 5.0, 10.0 };
    int n = 0;

    if (t) {
        char buf[128];
        size_t i, m = 0;

        for (i = 0; t[i] && m + 1 < sizeof buf; i++)
            if (t[i] != ' ')
                buf[m++] = t[i];
        buf[m] = 0;
        n = scan_list(buf, v, 2);
        if (n == 1)
            v[1] = v[0];
        if (n <= 0) {
            v[0] = 5.0;
            v[1] = 10.0;
        }
    }
    *ang = v[0] < 0.001 ? 0.001 : v[0];
    *mov = v[1] < 0.001 ? 0.001 : v[1];
}

static double wrap180(double a)
{
    if (a > 180.0)
        a -= 360.0;
    if (a <= -180.0)
        a += 360.0;
    return a;
}

static double clamp90(double a)
{
    return a > 90.0 ? 90.0 : a < -90.0 ? -90.0 : a;
}

/* FUN_00404ee0 の 0xd..0x12（左 右 上 下 前 後） */
static void arrow(int code)
{
    double sa, sm, mv;

    steps(&sa, &sm);
    mv = sm / b_scale;
    if (!m_mm)
        mv *= 1000.0;
    switch (code) {
    case 0xd:                           /* FUN_00405e10 */
        b_ang = wrap180(b_ang - sa);
        break;
    case 0xe:                           /* FUN_004060c0 */
        b_ang = wrap180(b_ang + sa);
        break;
    case 0xf:                           /* FUN_00407020 */
        if (m_mode == 1)
            b_ph += mv;
        else if (m_mode == 2)
            b_bh += mv;
        else
            b_iso = clamp90(b_iso + sa);
        break;
    case 0x10:                          /* FUN_00406e90 */
        if (m_mode == 1)
            b_ph -= mv;
        else if (m_mode == 2)
            b_bh -= mv;
        else
            b_iso = clamp90(b_iso - sa);
        break;
    case 0x11:                          /* FUN_00406020 */
        if (m_mode == 1)
            b_pd += mv;
        else if (m_mode == 2)
            b_bd += mv;
        break;
    case 0x12:                          /* FUN_00407180 */
        if (m_mode == 1)
            b_pd -= mv;
        else if (m_mode == 2)
            b_bd -= mv;
        break;
    }
}

int jw_d25_bar(jw_drawing *d, int id, int *made)
{
    if (made)
        *made = 0;
    if (!m_mode) {
        switch (id) {
        case 1064:                      /* 透視図 FUN_004064d0 */
        case 1065:                      /* 鳥瞰図 FUN_004065c0 */
        case 1066:                      /* アイソメ FUN_00406610 */
            enter(d, id - 1063);
            return 1;
        case 1067:                      /* (m) FUN_00406660 */
            m_mm = !m_mm;
            return 1;
        }
        return 0;
    }
    switch (id) {
    case 1121:                          /* ≪ → slot 27 */
        m_mode = 0;
        return 1;
    case 1122:                          /* 作図 → slot 26 */
        if (!d)
            return 1;
        if (made)
            *made = write_out(d);
        else
            write_out(d);
        return 1;
    case 2554:                          /* DXF出力: 移植に無い */
        return 1;
    case 1123: case 1124: case 1125: case 1126: case 1127: case 1128:
        if (m_mode == 3 && (id == 1127 || id == 1128))
            return 1;                   /* アイソメには 前・後 が出ていない */
        arrow(id - 1123 + 0xd);
        return 1;
    case 1129:                          /* 等角 FUN_00406420 */
        if (m_mode == 3) {
            b_ang = -45.0;
            b_iso = iso_angle();
        }
        return 1;
    case 1084:                          /* 初期値（透視・鳥瞰）・０，０（アイソメ） */
        if (m_mode == 1 || m_mode == 2) {
            if (m_mode == 1)            /* slot 24 FUN_006112d0 → slot 25 */
                init1 = 0;
            else
                init2 = 0;
            enter(d, m_mode);
        } else {
            b_ang = 0.0;
            b_iso = 0.0;
        }
        return 1;
    case 1412:
        return 1;
    }
    return 0;
}

int jw_d25_bar_check(int id)
{
    if (id == 9016)
        return m_mode == 1 || m_mode == 2;
    if (id == 9017)
        return m_mode == 3;
    return -1;
}

const char *jw_d25_label(int id)
{
    if (id == 1067 && !m_mode)
        return m_mm ? " [mm] " : "( m )";
    return 0;
}

int jw_d25_click(const jw_drawing *d, double x, double y, int button)
{
    (void)d;
    if (!m_mode || button < 0 || button > 1)
        return 0;
    /* slot 9 FUN_00615650（(R) の slot 11 も段があればここへ） */
    if (m_mode == 1)
        eye_x += x;
    else if (m_mode == 2) {
        eye_x += x;
        eye_dy = y;
    }
    return 1;
}

int jw_d25_key(const jw_drawing *d, int vk)
{
    (void)d;
    if (!m_mode)
        return 0;
    switch (vk) {
    case 0x25:                          /* ← slot 37 */
        arrow(0xd);
        return 1;
    case 0x27:                          /* → slot 38 */
        arrow(0xe);
        return 1;
    case 0x26:                          /* ↑ slot 39 */
        arrow(m_mode < 3 ? 0x11 : 0xf);
        return 1;
    case 0x28:                          /* ↓ slot 40 */
        arrow(m_mode < 3 ? 0x12 : 0x10);
        return 1;
    case 0x21:                          /* PageUp slot 41 */
        arrow(0xf);
        return 1;
    case 0x22:                          /* PageDown slot 42 */
        arrow(0x10);
        return 1;
    }
    return 0;
}

/* slot 6 FUN_0060dea0: 5520「【２．５Ｄ】測定位置」と つまみ */
const char *jw_d25_prompt(const jw_drawing *d)
{
    static char buf[256];
    static const char HEAD[] = "\x81y\x82Q\x81" "D\x82T\x82" "c\x81z\x91\xaa\x92\xe8\x88\xca\x92u";
    static const char DEG[] = "\x81\x8b", HDEG[] = "\xdf";

    (void)d;
    if (m_mode == 1 || m_mode == 2) {
        double h = (m_mode == 1 ? b_ph : b_bh) * b_scale;
        double l = (m_mode == 1 ? b_pd : b_bd) * b_scale;

        if (!m_mm)
            snprintf(buf, sizeof buf, "%s %.3f(%s)  %.1f(m)   %.1f(m)", HEAD, b_ang, DEG,
                     h / 1000.0, l / 1000.0);
        else
            snprintf(buf, sizeof buf, "%s %.3f(%s)  %.1f(mm)   %.1f(mm)", HEAD, b_ang, HDEG,
                     h, l);
    } else
        snprintf(buf, sizeof buf, "%s %.3f(%s)  %.3f(%s)", HEAD, b_ang, HDEG,
                 clamp90(b_iso), HDEG);
    return buf;
}

int jw_d25_nline(void)
{
    return nln;
}

int jw_d25_nell(void)
{
    return nel;
}

int jw_d25_nface(void)
{
    return nfc;
}

int jw_d25_line(int i, double p[6])
{
    if (i < 0 || i >= nln)
        return 0;
    memcpy(p, ln[i].p, sizeof ln[i].p);
    return 1;
}

void jw_d25_knobs(double k[6])
{
    k[0] = b_ang;
    k[1] = b_ph;
    k[2] = b_pd;
    k[3] = b_bh;
    k[4] = b_bd;
    k[5] = b_iso;
}
