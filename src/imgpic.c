/* Picture elements: the text "^@BM..." and what 画像編集 does to it (the
 * numbers were read off the original; see tools/img*.sh and tmp/image_report.md),
 * plus gzip for the pictures a drawing carries inside it. */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "image.h"

#define PI 3.14159265358979323846

/* ------------------------------------------------------------ gzip out */

static unsigned long crc_tab[256];

static unsigned long crc32_of(const unsigned char *p, long n)
{
    unsigned long c = 0xffffffffUL;
    long i;
    if (!crc_tab[1]) {
        unsigned long k, j;
        for (k = 0; k < 256; k++) {
            unsigned long v = k;
            for (j = 0; j < 8; j++) v = v & 1 ? 0xedb88320UL ^ (v >> 1) : v >> 1;
            crc_tab[k] = v;
        }
    }
    for (i = 0; i < n; i++) c = crc_tab[(c ^ p[i]) & 255] ^ (c >> 8);
    return c ^ 0xffffffffUL;
}

typedef struct { unsigned char *b; long n, cap; unsigned long acc; int nacc; int bad; } bw_t;

static void bw_bits(bw_t *w, unsigned v, int n)
{
    w->acc |= (unsigned long)v << w->nacc;
    w->nacc += n;
    while (w->nacc >= 8) {
        if (w->n == w->cap) {
            long c = w->cap ? w->cap * 2 : 4096;
            unsigned char *q = (unsigned char *)realloc(w->b, (size_t)c);
            if (!q) { w->bad = 1; return; }
            w->b = q;
            w->cap = c;
        }
        w->b[w->n++] = (unsigned char)(w->acc & 255);
        w->acc >>= 8;
        w->nacc -= 8;
    }
}

static void bw_huff(bw_t *w, unsigned code, int n)     /* Huffman codes go out MSB first */
{
    unsigned r = 0;
    int i;
    for (i = 0; i < n; i++) r |= ((code >> i) & 1) << (n - 1 - i);
    bw_bits(w, r, n);
}

static void put_lit(bw_t *w, int c)
{
    if (c < 144) bw_huff(w, (unsigned)(0x30 + c), 8);
    else if (c < 256) bw_huff(w, (unsigned)(0x190 + c - 144), 9);
    else if (c < 280) bw_huff(w, (unsigned)(c - 256), 7);
    else bw_huff(w, (unsigned)(0xc0 + c - 280), 8);
}

static const short LB[] = { 3,4,5,6,7,8,9,10,11,13,15,17,19,23,27,31,35,43,51,59,67,83,99,115,131,163,195,227,258,259 };
static const short LE[] = { 0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0 };
static const int DB[] = { 1,2,3,4,5,7,9,13,17,25,33,49,65,97,129,193,257,385,513,769,1025,1537,2049,3073,4097,6145,8193,12289,16385,24577,32769 };
static const short DE[] = { 0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13 };

/* Fixed-Huffman deflate behind a hash of three bytes.  It does not have to
   come out as zlib would write it, only be read back by anybody's inflate. */
static int deflate_fixed(const unsigned char *p, long n, bw_t *w)
{
    static int head[1 << 15];
    int *prev = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    long i = 0, k;

    if (!prev) return 0;
    for (k = 0; k < (1 << 15); k++) head[k] = -1;
    bw_bits(w, 1, 1);
    bw_bits(w, 1, 2);
    while (i < n) {
        int best = 0, bd = 0;
        if (i + 2 < n) {
            unsigned h = (unsigned)(p[i] << 10 ^ p[i + 1] << 5 ^ p[i + 2]) & 0x7fff;
            int c = head[h], tries = 32;
            while (c >= 0 && i - c <= 32768 && tries--) {
                int l = 0;
                while (l < 258 && i + l < n && p[c + l] == p[i + l]) l++;
                if (l > best) { best = l; bd = (int)(i - c); if (l == 258) break; }
                c = prev[c];
            }
        }
        if (best >= 3) {
            int ls = 0, ds = 0;
            while (LB[ls + 1] <= best) ls++;
            put_lit(w, 257 + ls);
            bw_bits(w, (unsigned)(best - LB[ls]), LE[ls]);
            while (DB[ds + 1] <= bd) ds++;
            bw_huff(w, (unsigned)ds, 5);
            bw_bits(w, (unsigned)(bd - DB[ds]), DE[ds]);
            for (k = 0; k < best; k++, i++) {
                if (i + 2 < n) {
                    unsigned h = (unsigned)(p[i] << 10 ^ p[i + 1] << 5 ^ p[i + 2]) & 0x7fff;
                    prev[i] = head[h];
                    head[h] = (int)i;
                }
            }
        } else {
            if (i + 2 < n) {
                unsigned h = (unsigned)(p[i] << 10 ^ p[i + 1] << 5 ^ p[i + 2]) & 0x7fff;
                prev[i] = head[h];
                head[h] = (int)i;
            }
            put_lit(w, p[i]);
            i++;
        }
    }
    put_lit(w, 256);
    if (w->nacc) bw_bits(w, 0, 8 - w->nacc);
    free(prev);
    return !w->bad;
}

int jw_gzip(const unsigned char *p, long n, unsigned char **out, long *on)
{
    bw_t w;
    static const unsigned char H[10] = { 0x1f, 0x8b, 8, 0, 0, 0, 0, 0, 0, 0x0a };
    unsigned long c = crc32_of(p, n);
    int i;

    memset(&w, 0, sizeof w);
    for (i = 0; i < 10; i++) bw_bits(&w, H[i], 8);
    if (!deflate_fixed(p, n, &w)) { free(w.b); return 0; }
    for (i = 0; i < 4; i++) bw_bits(&w, (unsigned)(c >> (8 * i)) & 255, 8);
    for (i = 0; i < 4; i++) bw_bits(&w, (unsigned)((unsigned long)n >> (8 * i)) & 255, 8);
    if (w.bad) { free(w.b); return 0; }
    *out = w.b;
    *on = w.n;
    return 1;
}

/* A picture as a 24-bit BMP -- what the original files a 同梱 picture as,
   whatever it came in as. */
unsigned char *jw_img_bmp(const jw_img *im, long *n)
{
    long stride = ((long)im->w * 3 + 3) & ~3L, total = 54 + stride * im->h, sz = stride * im->h;
    unsigned char *b = (unsigned char *)calloc((size_t)total, 1);
    int x, y;

    if (!b) return 0;
    b[0] = 'B'; b[1] = 'M';
    b[2] = (unsigned char)total; b[3] = (unsigned char)(total >> 8);
    b[4] = (unsigned char)(total >> 16); b[5] = (unsigned char)(total >> 24);
    b[10] = 54; b[14] = 40;
    b[18] = (unsigned char)im->w; b[19] = (unsigned char)(im->w >> 8);
    b[20] = (unsigned char)(im->w >> 16);
    b[22] = (unsigned char)im->h; b[23] = (unsigned char)(im->h >> 8);
    b[24] = (unsigned char)(im->h >> 16);
    b[26] = 1; b[28] = 24;
    b[34] = (unsigned char)sz; b[35] = (unsigned char)(sz >> 8);
    b[36] = (unsigned char)(sz >> 16); b[37] = (unsigned char)(sz >> 24);
    b[38] = b[42] = 0x13; b[39] = b[43] = 0x0b;
    for (y = 0; y < im->h; y++)
        for (x = 0; x < im->w; x++) {
            const unsigned char *s = im->rgb + ((size_t)y * im->w + x) * 3;
            unsigned char *d = b + 54 + stride * (im->h - 1 - y) + x * 3;
            d[0] = s[2]; d[1] = s[1]; d[2] = s[0];
        }
    *n = total;
    return b;
}

/* "C:\prog\a.bmp" -> "C__prog_a_bmp.bmp": what a picture is called once it
   is inside the drawing, and in the folder 同梱画像分離 makes.  Asked of the
   original with C:\prog\claude2\jwcad_win_wasm\tmp\img\t1.bmp. */
void jw_img_embed_name(const char *path, char *out, int cap)
{
    int k = 0;
    const char *p;

    for (p = path; *p && k < cap - 5; p++) {
        unsigned char c = (unsigned char)*p;
        if ((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc)) {
            out[k++] = *p;
            if (p[1] && k < cap - 5) out[k++] = *++p;
            continue;
        }
        out[k++] = (c == '\\' || c == '/' || c == ':' || c == '.' || c == ' ' ||
                    c == '*' || c == '?' || c == '"' || c == '<' || c == '>' || c == '|')
                       ? '_' : *p;
    }
    memcpy(out + k, ".bmp", 5);
}

/* ------------------------------------------------------- the text */

static int num(const char *s, double *v)
{
    char *e;
    if (!*s) return 0;
    *v = strtod(s, &e);
    return e != s && !*e;
}

int jw_is_pic(const jw_drawing *d, const jw_obj *o)
{
    const char *t;
    if (o->cls != JW_MOJI || o->text < 0) return 0;
    t = jw_str(d, o->text);
    return t[0] == '^' && t[1] == '@' && t[2] == 'B' && t[3] == 'M';
}

static int pic_parse_str(const char *t, jw_pic *p);

int jw_pic_parse(const jw_drawing *d, const jw_obj *o, jw_pic *p)
{
    if (!jw_is_pic(d, o)) return 0;
    return pic_parse_str(jw_str(d, o->text) + 4, p);
}

/* the text after "^@BM" */
static int pic_parse_str(const char *t, jw_pic *p)
{
    char buf[400];
    char *tok[10];
    double v[10];
    int nt = 0, nv = 0, i;
    char *c;

    memset(p, 0, sizeof *p);
    p->r = p->g = p->b = 255;
    p->c = 1.0;
    strncpy(buf, t, sizeof buf - 1);
    buf[sizeof buf - 1] = 0;
    /* numbers off the end: at most nine of them */
    for (;;) {
        double x;
        c = strrchr(buf, ',');
        if (!c || nt >= 9 || !num(c + 1, &x)) break;
        v[nt] = x;
        tok[nt++] = c;
        *c = 0;
    }
    strncpy(p->name, buf, sizeof p->name - 1);
    p->name[sizeof p->name - 1] = 0;
    p->nfield = nt;
    nv = nt;
    for (i = 0; i < nv; i++) {
        double x = v[nv - 1 - i];
        switch (i) {
        case 0: p->w = x; break;
        case 1: p->h = x; break;
        case 2: p->x = x; break;
        case 3: p->y = x; break;
        case 4: p->c = x; break;
        case 5: p->d = x; break;
        case 6: p->r = (int)x; break;
        case 7: p->g = (int)x; break;
        case 8: p->b = (int)x; break;
        }
    }
    if (nv == 1) p->h = p->w;
    if (nv == 0) { p->w = p->h = 100.0; }
    if (!(p->c > 0.0)) p->c = 1.0;
    (void)tok;
    return 1;
}

void jw_pic_format(const jw_pic *p, char *out, int cap)
{
    if (p->nfield <= 1 && p->w == p->h)
        snprintf(out, (size_t)cap, "^@BM%s,%g", p->name, p->w);
    else if (p->nfield <= 2)
        snprintf(out, (size_t)cap, "^@BM%s,%g,%g", p->name, p->w, p->h);
    else
        snprintf(out, (size_t)cap, "^@BM%s,%g,%g,%g,%g,%g,%g,%d,%d,%d", p->name,
                 p->w, p->h, p->x, p->y, p->c, p->d, p->r, p->g, p->b);
}

/* ------------------------------------------------------ geometry */

double jw_pic_angle(const jw_obj *o, const jw_pic *p)
{
    (void)o;
    return p->nfield >= 6 ? p->d * PI / 180.0 : 0.0;
}

/* corners, lower left first and then round: the picture's box in the sheet */
void jw_pic_corners(const jw_obj *o, const jw_pic *p, double *x, double *y)
{
    double a = jw_pic_angle(o, p), c = cos(a), s = sin(a);
    double ox = o->d[0], oy = o->d[1];

    x[0] = ox;                       y[0] = oy;
    x[1] = ox + c * p->w;            y[1] = oy + s * p->w;
    x[2] = ox + c * p->w - s * p->h; y[2] = oy + s * p->w + c * p->h;
    x[3] = ox - s * p->h;            y[3] = oy + c * p->h;
}

/* where a point is in the picture's own frame: along it and up it, in mm */
static void local_of(const jw_obj *o, const jw_pic *p, double px, double py,
                     double *lx, double *ly)
{
    double a = jw_pic_angle(o, p), c = cos(a), s = sin(a);
    double dx = px - o->d[0], dy = py - o->d[1];

    *lx = c * dx + s * dy;
    *ly = -s * dx + c * dy;
}

int jw_pic_hit(const jw_obj *o, const jw_pic *p, double px, double py)
{
    double lx, ly;

    local_of(o, p, px, py, &lx, &ly);
    return lx >= 0.0 && lx <= p->w && ly >= 0.0 && ly <= p->h;
}

/* The element's own fields, as the original leaves them: the text, the size
   of its characters (reduced so that the text is no longer than the picture
   is wide), where its baseline ends, and the turn kept at +0x...7. */
void jw_pic_write(jw_drawing *d, jw_obj *o, const jw_pic *p, double ox, double oy,
                  double base_deg)
{
    char buf[400];
    double cw, len, a;
    int units;
    const char *q;

    jw_pic_format(p, buf, sizeof buf);
    o->text = jw_add_str_w(d, buf, d->version > 0x275);
    units = 0;
    for (q = buf; *q; q++) units++;
    cw = 2.0;
    /* a turned picture's text keeps its full size (r6 of tools/imgref.sh) */
    if (units > 0 && p->w > 0.0 && !(p->nfield >= 6 && p->d != 0.0)) {
        double lim = floor(20.0 * p->w / units) / 10.0;
        if (lim < cw) cw = lim;
    }
    if (cw < 0.0) cw = 0.0;
    len = units * cw / 2.0;
    a = base_deg * PI / 180.0;
    o->d[0] = ox;
    o->d[1] = oy;
    o->d[2] = ox + cos(a) * len;
    o->d[3] = oy + sin(a) * len;
    o->d[4] = cw;
    o->d[5] = 2.0;
    o->d[6] = 0.0;
    {
        double t = p->nfield >= 6 ? p->d : 0.0;
        t = fmod(t, 360.0);
        if (t < 0.0) t += 360.0;
        o->d[7] = t;
    }
}

/* A picture put in: lower left at (x,y), `w` mm wide, shaped like its image
   (aw by ah in pixels).  ",100,75" is what the original writes. */
jw_obj *jw_pic_new(jw_drawing *d, const char *name, int aw, int ah, double x, double y,
                   double w)
{
    jw_obj *o = jw_add(d, JW_MOJI);
    jw_pic p;

    if (!o) return 0;
    memset(&p, 0, sizeof p);
    strncpy(p.name, name, sizeof p.name - 1);
    p.w = w;
    p.h = aw > 0 ? w * ah / aw : w;
    p.c = 1.0;
    p.r = p.g = p.b = 255;
    p.nfield = 2;
    o->color = 1;
    o->ltype = 1;
    o->n = 0;
    o->face = jw_add_str_w(d, "\x82l\x82r \x83S\x83V\x83" "b\x83N", d->version > 0x275);
    jw_pic_write(d, o, &p, x, y, 0.0);
    return o;
}

/* 画像フィット without 回転する: the rectangle with corners a1 a2 on the
   picture is made to fit the one with corners b1 b2 -- by the long side of
   the first -- and the centres land on each other. */
int jw_pic_fit_box(jw_drawing *d, jw_obj *o, double ax1, double ay1, double ax2, double ay2,
                   double bx1, double by1, double bx2, double by2)
{
    jw_pic p;
    double sw = fabs(ax2 - ax1), sh = fabs(ay2 - ay1);
    double dw = fabs(bx2 - bx1), dh = fabs(by2 - by1), s;
    double sx = (ax1 + ax2) / 2, sy = (ay1 + ay2) / 2, tx = (bx1 + bx2) / 2, ty = (by1 + by2) / 2;
    double ox, oy;

    if (!jw_pic_parse(d, o, &p)) return 0;
    if (sw <= 1e-9 && sh <= 1e-9) return 0;
    s = sw >= sh ? dw / sw : dh / sh;
    if (!(s > 0.0)) return 0;
    ox = tx + s * (o->d[0] - sx);
    oy = ty + s * (o->d[1] - sy);
    p.w *= s;
    p.h *= s;
    if (p.nfield < 6) p.nfield = 9;
    p.nfield = 9;
    jw_pic_write(d, o, &p, ox, oy, p.d);
    return 1;
}

/* with 回転する: two points of the picture go to two points of the sheet --
   a scaling and a turn */
int jw_pic_fit_turn(jw_drawing *d, jw_obj *o, double ax1, double ay1, double ax2, double ay2,
                    double bx1, double by1, double bx2, double by2)
{
    jw_pic p;
    double la = hypot(ax2 - ax1, ay2 - ay1), lb = hypot(bx2 - bx1, by2 - by1), s, rot, c, sn;
    double dx, dy, ox, oy, deg;

    if (!jw_pic_parse(d, o, &p)) return 0;
    if (la <= 1e-9 || lb <= 1e-9) return 0;
    s = lb / la;
    rot = atan2(by2 - by1, bx2 - bx1) - atan2(ay2 - ay1, ax2 - ax1);
    c = cos(rot);
    sn = sin(rot);
    dx = o->d[0] - ax1;
    dy = o->d[1] - ay1;
    ox = bx1 + s * (c * dx - sn * dy);
    oy = by1 + s * (sn * dx + c * dy);
    deg = (p.nfield >= 6 ? p.d : 0.0) + rot * 180.0 / PI;
    deg = fmod(deg, 360.0);
    if (deg > 180.0) deg -= 360.0;
    if (deg <= -180.0) deg += 360.0;
    p.d = deg;
    p.w *= s;
    p.h *= s;
    p.nfield = 9;
    jw_pic_write(d, o, &p, ox, oy, deg);
    return 1;
}

/* トリミング: keep the part inside the rectangle with corners a1 a2 (in the
   picture's own frame), clipped to what shows now. */
int jw_pic_trim(jw_drawing *d, jw_obj *o, double ax1, double ay1, double ax2, double ay2)
{
    jw_pic p;
    double l1x, l1y, l2x, l2y, x0, x1, y0, y1, full, a, c, s;
    double ox, oy;

    if (!jw_pic_parse(d, o, &p)) return 0;
    local_of(o, &p, ax1, ay1, &l1x, &l1y);
    local_of(o, &p, ax2, ay2, &l2x, &l2y);
    x0 = l1x < l2x ? l1x : l2x;
    x1 = l1x < l2x ? l2x : l1x;
    y0 = l1y < l2y ? l1y : l2y;
    y1 = l1y < l2y ? l2y : l1y;
    if (x0 < 0.0) x0 = 0.0;
    if (y0 < 0.0) y0 = 0.0;
    if (x1 > p.w) x1 = p.w;
    if (y1 > p.h) y1 = p.h;
    if (x1 < x0 || y1 < y0) return 0;
    full = p.w / p.c;                 /* the whole picture's width, mm */
    a = jw_pic_angle(o, &p);
    c = cos(a);
    s = sin(a);
    ox = o->d[0] + c * x0 - s * y0;
    oy = o->d[1] + s * x0 + c * y0;
    p.x += x0 / full;
    p.y += y0 / full;
    p.c = (x1 - x0) / full;
    p.w = x1 - x0;
    p.h = y1 - y0;
    p.nfield = 9;
    p.d = fmod(fmod(p.d, 360.0) + 360.0, 360.0);       /* trimming writes it as 0..360 */
    /* the original leaves the baseline running along the sheet's x here
       however the picture is turned; only the angle at +0x...7 follows */
    jw_pic_write(d, o, &p, ox, oy, 0.0);
    return 1;
}

int jw_pic_untrim(jw_drawing *d, jw_obj *o)
{
    jw_pic p;
    double full, a, c, s, ox, oy;

    if (!jw_pic_parse(d, o, &p)) return 0;
    if (p.nfield < 6 || (p.x == 0.0 && p.y == 0.0 && p.c == 1.0)) return 0;
    full = p.w / p.c;
    a = jw_pic_angle(o, &p);
    c = cos(a);
    s = sin(a);
    ox = o->d[0] - c * p.x * full + s * p.y * full;
    oy = o->d[1] - s * p.x * full - c * p.y * full;
    {   /* the whole picture is as tall as its file says; without the file
           the best that can be done is to scale the part that is left */
        const jw_img *im = jw_img_get(p.name);

        p.h = im && im->w > 0 ? full * im->h / im->w : p.h / p.c;
    }
    p.w = full;
    p.x = p.y = 0.0;
    p.c = 1.0;
    p.nfield = 9;
    p.d = fmod(fmod(p.d, 360.0) + 360.0, 360.0);
    jw_pic_write(d, o, &p, ox, oy, 0.0);
    return 1;
}

int jw_pic_set_transparent(jw_drawing *d, jw_obj *o, int r, int g, int b)
{
    jw_pic p;
    double base;

    if (!jw_pic_parse(d, o, &p)) return 0;
    p.r = r; p.g = g; p.b = b;
    p.nfield = 9;
    base = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
    jw_pic_write(d, o, &p, o->d[0], o->d[1], base);
    return 1;
}

/* ------------------------------------------- ほかの命令が画像をどう扱うか
 *
 * 原典で画像を画像として見ているのは、文字列を "^@BM" で読む FUN_0048efe0
 * （とその包み FUN_0048f790）を呼ぶ所だけで、それは 描画・拾い・読取点・
 * 再描画の範囲・倍率・回転・JWC/JWS の読み書き・SXF（.tif だけ）・図形・
 * 画像編集 そのもの。範囲選択・消去・複写・移動（ずらし）・反転・ブロック化・
 * DXF・SFC の文字 は どれも呼ばないので、画像は ただの文字 として扱われる。
 * 逆コンパイルの読み、原典では押していない。 */

/* "^@BM..." の w・h を k 倍した字。原典の FUN_0048f7f0: 名前のあとの数を
   "%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d" で読み、読めた数が 3 より少なければ
   "^@BM%s,%lg,%lg"、そうでなければ九つで書き直す。新しい w か h が 0.001
   より小さければ何もしない（0 を返す）。名前が "d:\data\030806\" で始まる
   ときの作者の試し（1000×1000 にして始点を (-420,-270) へ）は入れない */
int jw_pic_text_scaled(const char *t, double k, char *out, int cap)
{
    jw_pic p;
    double w, h;

    if (!t || t[0] != '^' || t[1] != '@' || t[2] != 'B' || t[3] != 'M')
        return 0;
    pic_parse_str(t + 4, &p);
    w = p.w * k;
    h = p.h * k;
    if (!(w >= 0.001) || !(h >= 0.001))
        return 0;
    if (p.nfield < 3)
        snprintf(out, (size_t)cap, "^@BM%s,%g,%g", p.name, w, h);
    else
        snprintf(out, (size_t)cap, "^@BM%s,%g,%g,%g,%g,%g,%g,%d,%d,%d", p.name, w, h,
                 p.x, p.y, p.c, p.d, p.r, p.g, p.b);
    return 1;
}

/* 字の長さ（半角 1、全角 2 を数え、字の幅＋間隔 の半分ずつ、最後の間隔は
   数えない） */
static double pic_text_len(const char *s, double cw, double sp)
{
    const unsigned char *q = (const unsigned char *)s;
    double half = 0.0;

    while (*q) {
        if ((*q >= 0x81 && *q <= 0x9f) || (*q >= 0xe0 && *q <= 0xfc)) {
            if (q[1])
                q++;
            half += 2.0;
        } else {
            half += 1.0;
        }
        q++;
    }
    return half > 0.0 ? half / 2.0 * (cw + sp) - sp : 0.0;
}

/* (-180, 180] へ。1e-7 以下は 0（FUN_0046d800） */
static double pic_fold180(double a)
{
    while (a > 180.0)
        a -= 360.0;
    while (a <= -180.0)
        a += 360.0;
    return fabs(a) <= 1e-7 ? 0.0 : a;
}

/* 倍率・回転のあとの画像。jw_obj_xform(o, ..., sc, ang, ...) を掛けたあとに
 * 呼ぶ（`was` は掛ける前）。原典の要素ごとの倍率 FUN_00465c40 → 文字
 * FUN_00466e30／FUN_00465f40 と 回転 FUN_0046d5b0 → FUN_0046e210 →
 * FUN_0046d800 の画像の枝:
 *   倍率: 1 との差が 1e-7 未満なら何もしない。画像なら w・h を
 *     max(倍率x, 倍率y)（符号つきの大きいほう）倍して FUN_0048f7f0 で書き直し、
 *     字の大きさは保つ（「文字サイズ変更」(DAT_00a0cb58) が入っていても
 *     画像は保つ側へ回す）。終点は 始点 ＋ 新しい字の長さ を 画像の角度 の向きへ。
 *   回転: |角| < 1e-7 なら何もしない。字の角度 (+0xd0) は 足して (-180,180]、
 *     画像なら FUN_0048fb30 が 文字列の角度（六つ目の数）に 度で足して
 *     （丸めない）九つの形で書き直す（w か h が 0.001 未満なら書き直さない）。
 * 移植の jw_obj_xform は字の大きさも掛けるので、それを戻してから。
 * 逆コンパイルの読み、原典では押していない。0 なら画像ではない。 */
int jw_pic_xform(jw_drawing *d, jw_obj *o, const jw_obj *was, double sc, double ang)
{
    jw_pic p;
    char buf[400];
    const char *t;
    int scaled = fabs(sc - 1.0) >= 1e-7, turned = fabs(ang) >= 1e-7;
    double dir, deg7, len, k;

    if (!jw_pic_parse(d, o, &p))
        return 0;
    if (!scaled && !turned)
        return 1;
    o->d[4] = was->d[4];
    o->d[5] = was->d[5];
    o->d[6] = was->d[6];
    /* 掛けたあとの基線の向き。長さ 0 なら字の角度 */
    if (hypot(o->d[2] - o->d[0], o->d[3] - o->d[1]) > 1e-12)
        dir = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
    else
        dir = o->d[7] + (turned ? ang * 180.0 / PI : 0.0);
    deg7 = o->d[7];     /* 掛けた直後の +0xd0（反転の参照は 入れ替えて基線の角に済み） */
    if (scaled && fabs(sc) >= 1e-5 && fabs(sc) <= 1e5
        && jw_pic_text_scaled(jw_str(d, o->text), sc, buf, (int)sizeof buf)) {
        o->text = jw_add_str_w(d, buf, d->version > 0x275);
        jw_pic_parse(d, o, &p);
        /* FUN_0048f7f0 は 終点を画像の角度へ引き直し、+0xd0 をその角度に */
        deg7 = pic_fold180(p.d);
        dir = p.d + (turned ? ang * 180.0 / PI : 0.0);
    }
    if (turned) {
        deg7 = pic_fold180(deg7 + ang * 180.0 / PI);
        if (p.w >= 0.001 && p.h >= 0.001) {
            snprintf(buf, sizeof buf, "^@BM%s,%g,%g,%g,%g,%g,%g,%d,%d,%d", p.name, p.w, p.h,
                     p.x, p.y, p.c, p.d + ang * 180.0 / PI, p.r, p.g, p.b);
            o->text = jw_add_str_w(d, buf, d->version > 0x275);
        }
    }
    o->d[7] = deg7;
    t = jw_str(d, o->text);
    len = pic_text_len(t, o->d[4], o->d[6]);
    k = dir * PI / 180.0;
    o->d[2] = o->d[0] + cos(k) * len;
    o->d[3] = o->d[1] + sin(k) * len;
    return 1;
}
