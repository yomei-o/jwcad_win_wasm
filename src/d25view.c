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

/* 一本の線を立体に（FUN_00613c10。勾配の文字 t T d D と 勾配の補助線
   FUN_006129c0 / FUN_006109b0 / FUN_0061c770 は入れていない） */
static void one_line(const jw_drawing *d, const jw_obj *o, unsigned char *used,
                     double base, int lh, double lh_h)
{
    double h1 = 0.0, d1 = 0.0, h2 = 0.0, d2 = 0.0, p[6], q[6];
    int n1 = 0, n2 = 0, k1 = 0, k2 = 0, t1 = -1, t2 = -1, ec = 0, f0 = 0, j;

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
            if (kind < 20) {
                if (n > 2)
                    n = 2;
            } else if (e == 0)
                k1 = kind;
            else
                k2 = kind;
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
    if (k1 >= 20 || k2 >= 20)
        return;                         /* 勾配（FUN_0061c770）は入れていない */
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
        p[2] = (abs(n1) == 2 ? d1 : 0.0) + (ec ? 0.0 : base);
        p[5] = (abs(n2) == 2 ? d2 : 0.0) + (f0 ? 0.0 : base);
        add_line(o, p);
    }
    if (n1 != 0 || n2 != 0) {           /* 高さの線 */
        p[2] = h1 + base;
        p[5] = h2 + base;
        add_line(o, p);
    }
    if (n1 > 1 && fabs(h1 - d1) > 1e-07) {     /* 始点の縦の線 */
        q[0] = q[3] = o->d[0];
        q[1] = q[4] = o->d[1];
        q[2] = h1 + base;
        q[5] = d1 + (ec ? 0.0 : base);
        add_line(o, q);
    }
    if (n2 > 1 && fabs(h2 - d2) > 1e-07) {     /* 終点の縦の線 */
        q[0] = q[3] = o->d[2];
        q[1] = q[4] = o->d[3];
        q[2] = h2 + base;
        q[5] = d2 + (f0 ? 0.0 : base);
        add_line(o, q);
    }
}

/* FUN_00617f70: 立体を組み、真ん中と半径を出す。線が無ければ 0 */
static int build(const jw_drawing *d)
{
    double base[16][16], lhh[16][16];
    int lh[16][16], g, l, i;
    unsigned char *used;

    nln = 0;
    take_snap(d, snap);
    k_unit = 1.0 / write_scale(d);
    if (!m_mm)
        k_unit *= 1000.0;
    for (g = 0; g < 16; g++) {
        double gv = name_lv(d, d->group[g].name);

        for (l = 0; l < 16; l++) {
            int off = d->group[g].layer_name[l];
            const char *s = off >= 0 ? jw_str(d, off) : 0;

            base[g][l] = (gv + name_lv(d, off)) * k_unit;
            lh[g][l] = 0;
            lhh[g][l] = 0.0;
            if (s && s[0] == '#' && s[1] == 'l' && s[2] == 'h' && strlen(s) > 3) {
                const char *p = s + 3;
                double v = 0.0;

                scan_num(&p, &v);
                lh[g][l] = 1;
                lhh[g][l] = v * k_unit;
            }
        }
    }
    used = (unsigned char *)calloc((size_t)(d->ndrawn > 0 ? d->ndrawn : 1), 1);
    if (!used)
        return 0;
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double dx, dy;

        if (o->cls != JW_SEN || o->sub || o->layer > 15 || o->lgroup > 15
            || o->ltype == 9 || !editable(d, o))
            continue;
        dx = o->d[2] - o->d[0];
        dy = o->d[3] - o->d[1];
        if (sqrt(dx * dx + dy * dy) < 1e-07)
            continue;
        one_line(d, o, used, base[o->lgroup][o->layer], lh[o->lgroup][o->layer],
                 lhh[o->lgroup][o->layer]);
    }
    free(used);
    if (!nln)
        return 0;
    cx = cy = cz = 0.0;
    for (i = 0; i < nln; i++) {
        cx += (ln[i].p[0] + ln[i].p[3]) / 2.0;
        cy += (ln[i].p[1] + ln[i].p[4]) / 2.0;
        cz += (ln[i].p[2] + ln[i].p[5]) / 2.0;
    }
    if (nln > 0) {
        cx /= nln;
        cy /= nln;
        cz /= nln;
    }
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

int jw_d25_view(const jw_drawing *d, jw_drawing *out)
{
    d25_cam k;
    int i, n = 0;

    if (!m_mode || !d || !out)
        return 0;
    prepare(d, &k);
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

/* slot 26 FUN_006119c0: 写した線を書込みレイヤへ（線種・線色は元の線、線幅は 0）。
   視点の後ろの線は書かず 5384「作図されない部分があります」 */
static int write_out(jw_drawing *d)
{
    d25_cam k;
    int i, made = 0, hidden = 0;

    prepare(d, &k);
    for (i = 0; i < nln; i++) {
        double o[4];
        jw_obj *s;

        if (!project(&k, ln[i].p, o)) {
            hidden = 1;
            continue;
        }
        s = put(d, o[0], o[1], o[2], o[3]);
        if (!s)
            break;
        s->ltype = ln[i].ltype;
        s->color = ln[i].color;
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
