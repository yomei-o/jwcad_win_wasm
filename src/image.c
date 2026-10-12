/* Pictures: BMP, PNG, JPEG by hand, and the store.  See image.h. */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "image.h"

/* ---------------------------------------------------------------- BMP */

static unsigned rd16(const unsigned char *p) { return p[0] | p[1] << 8; }
static unsigned rd32(const unsigned char *p)
{
    return p[0] | p[1] << 8 | p[2] << 16 | (unsigned)p[3] << 24;
}

static int shift_of(unsigned m, int *bits)
{
    int s = 0, n = 0;
    if (!m) { *bits = 0; return 0; }
    while (!(m & 1)) { m >>= 1; s++; }
    while (m & 1) { m >>= 1; n++; }
    *bits = n;
    return s;
}

static int dec_bmp(const unsigned char *b, long n, jw_img *img)
{
    unsigned off, hs, comp = 0, ncol = 0;
    int w, h, bpp, top = 0, x, y;
    unsigned char pal[256][3];
    unsigned mask[3] = { 0xff0000, 0xff00, 0xff };
    long stride;
    unsigned char *o;
    int i;

    if (n < 26 || b[0] != 'B' || b[1] != 'M')
        return 0;
    off = rd32(b + 10);
    hs = rd32(b + 14);
    if (hs == 12) {
        w = rd16(b + 18);
        h = rd16(b + 20);
        bpp = rd16(b + 24);
    } else if (hs >= 40 && n >= 14 + 40) {
        w = (int)rd32(b + 18);
        h = (int)rd32(b + 22);
        bpp = rd16(b + 28);
        comp = rd32(b + 30);
        ncol = rd32(b + 46);
    } else
        return 0;
    if (h < 0) { top = 1; h = -h; }
    if (w <= 0 || h <= 0 || w > 30000 || h > 30000)
        return 0;
    if (bpp != 1 && bpp != 4 && bpp != 8 && bpp != 16 && bpp != 24 && bpp != 32)
        return 0;
    if (comp != 0 && comp != 1 && comp != 2 && comp != 3)
        return 0;
    if (bpp <= 8) {
        long po = 14 + (long)hs;
        int ent = hs == 12 ? 3 : 4;
        if (!ncol || ncol > (1u << bpp))
            ncol = 1u << bpp;
        for (i = 0; i < (int)ncol; i++) {
            if (po + (i + 1) * ent > n) return 0;
            pal[i][0] = b[po + i * ent + 2];
            pal[i][1] = b[po + i * ent + 1];
            pal[i][2] = b[po + i * ent];
        }
        for (; i < 256; i++) pal[i][0] = pal[i][1] = pal[i][2] = 0;
    }
    if (comp == 3 && (bpp == 16 || bpp == 32) && hs >= 40 && n >= 14 + 40 + 12) {
        mask[0] = rd32(b + 54);
        mask[1] = rd32(b + 58);
        mask[2] = rd32(b + 62);
    } else if (bpp == 16) {
        mask[0] = 0x7c00; mask[1] = 0x3e0; mask[2] = 0x1f;
    }
    o = (unsigned char *)malloc((size_t)w * h * 3);
    if (!o) return 0;
    memset(o, 0, (size_t)w * h * 3);
    if (comp == 1 || comp == 2) {
        /* RLE8 / RLE4 */
        const unsigned char *p = b + off, *e = b + n;
        x = 0; y = 0;
        while (p + 1 < e && y < h) {
            int c = p[0], v = p[1];
            p += 2;
            if (c) {
                for (i = 0; i < c; i++) {
                    int idx = comp == 1 ? v : (i & 1 ? v & 15 : v >> 4);
                    if (x < w) {
                        unsigned char *q = o + ((size_t)(top ? y : h - 1 - y) * w + x) * 3;
                        q[0] = pal[idx][0]; q[1] = pal[idx][1]; q[2] = pal[idx][2];
                    }
                    x++;
                }
            } else if (v == 0) { x = 0; y++; }
            else if (v == 1) break;
            else if (v == 2) { if (p + 1 >= e) break; x += p[0]; y += p[1]; p += 2; }
            else {
                int cnt = v, bytes = comp == 1 ? v : (v + 1) / 2;
                for (i = 0; i < cnt && p + (comp == 1 ? i : i / 2) < e; i++) {
                    int idx = comp == 1 ? p[i] : (i & 1 ? p[i / 2] & 15 : p[i / 2] >> 4);
                    if (x < w) {
                        unsigned char *q = o + ((size_t)(top ? y : h - 1 - y) * w + x) * 3;
                        q[0] = pal[idx][0]; q[1] = pal[idx][1]; q[2] = pal[idx][2];
                    }
                    x++;
                }
                p += bytes + (bytes & 1);
            }
        }
        img->w = w; img->h = h; img->rgb = o;
        return 1;
    }
    stride = (((long)w * bpp + 31) / 32) * 4;
    if ((long)off + stride * (h - 1) + ((long)w * bpp + 7) / 8 > n) {
        free(o);
        return 0;
    }
    for (y = 0; y < h; y++) {
        const unsigned char *r = b + off + stride * y;
        unsigned char *q = o + (size_t)(top ? y : h - 1 - y) * w * 3;
        for (x = 0; x < w; x++, q += 3) {
            if (bpp == 24) {
                q[0] = r[x * 3 + 2]; q[1] = r[x * 3 + 1]; q[2] = r[x * 3];
            } else if (bpp == 32 || bpp == 16) {
                unsigned v = bpp == 32 ? rd32(r + x * 4) : rd16(r + x * 2);
                int k;
                if (bpp == 32 && comp == 0) {
                    q[0] = (v >> 16) & 255; q[1] = (v >> 8) & 255; q[2] = v & 255;
                } else {
                    for (k = 0; k < 3; k++) {
                        int nb, s = shift_of(mask[k], &nb);
                        unsigned c = nb ? (v & mask[k]) >> s : 0;
                        q[k] = nb == 0 ? 0 : nb >= 8 ? (unsigned char)(c >> (nb - 8))
                                                     : (unsigned char)(c * 255 / ((1u << nb) - 1));
                    }
                }
            } else {
                int idx;
                if (bpp == 8) idx = r[x];
                else if (bpp == 4) idx = (x & 1) ? r[x / 2] & 15 : r[x / 2] >> 4;
                else idx = (r[x / 8] >> (7 - (x & 7))) & 1;
                q[0] = pal[idx][0]; q[1] = pal[idx][1]; q[2] = pal[idx][2];
            }
        }
    }
    img->w = w; img->h = h; img->rgb = o;
    return 1;
}

/* ------------------------------------------------------------ inflate */

typedef struct {
    const unsigned char *p;
    long n, pos;
    unsigned long bits;
    int nbits;
    unsigned char *out;
    long on, ocap;
    int bad;
} inf_t;

typedef struct {
    short count[16];
    short sym[320];
} huff_t;

static int getbits(inf_t *s, int need)
{
    unsigned long v = s->bits;
    while (s->nbits < need) {
        if (s->pos >= s->n) { s->bad = 1; return 0; }
        v |= (unsigned long)s->p[s->pos++] << s->nbits;
        s->nbits += 8;
    }
    s->bits = v >> need;
    s->nbits -= need;
    return (int)(v & ((1UL << need) - 1));
}

static int hdecode(inf_t *s, const huff_t *h)
{
    int code = 0, first = 0, index = 0, len;
    for (len = 1; len <= 15; len++) {
        int cnt;
        code |= getbits(s, 1);
        if (s->bad) return -1;
        cnt = h->count[len];
        if (code - cnt < first)
            return h->sym[index + (code - first)];
        index += cnt;
        first += cnt;
        first <<= 1;
        code <<= 1;
    }
    return -1;
}

static void hbuild(huff_t *h, const unsigned char *len, int n)
{
    short offs[16];
    int i;
    memset(h->count, 0, sizeof h->count);
    for (i = 0; i < n; i++) h->count[len[i]]++;
    h->count[0] = 0;
    offs[1] = 0;
    for (i = 1; i < 15; i++) offs[i + 1] = offs[i] + h->count[i];
    for (i = 0; i < n; i++)
        if (len[i]) h->sym[offs[len[i]]++] = (short)i;
}

static int oput(inf_t *s, int c)
{
    if (s->on >= s->ocap) {
        long nc = s->ocap ? s->ocap * 2 : 65536;
        unsigned char *q = (unsigned char *)realloc(s->out, nc);
        if (!q) { s->bad = 1; return 0; }
        s->out = q;
        s->ocap = nc;
    }
    s->out[s->on++] = (unsigned char)c;
    return 1;
}

static const short LBASE[] = { 3,4,5,6,7,8,9,10,11,13,15,17,19,23,27,31,35,43,51,59,67,83,99,115,131,163,195,227,258 };
static const short LEXT[] = { 0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0 };
static const short DBASE[] = { 1,2,3,4,5,7,9,13,17,25,33,49,65,97,129,193,257,385,513,769,1025,1537,2049,3073,4097,6145,8193,12289,16385,24577 };
static const short DEXT[] = { 0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13 };

static int codes(inf_t *s, const huff_t *lc, const huff_t *dc)
{
    for (;;) {
        int sym = hdecode(s, lc);
        if (sym < 0) return 0;
        if (sym < 256) {
            if (!oput(s, sym)) return 0;
        } else if (sym == 256)
            return 1;
        else {
            int len, dist;
            sym -= 257;
            if (sym >= 29) return 0;
            len = LBASE[sym] + getbits(s, LEXT[sym]);
            sym = hdecode(s, dc);
            if (sym < 0 || sym >= 30) return 0;
            dist = DBASE[sym] + getbits(s, DEXT[sym]);
            if (s->bad || dist > s->on) return 0;
            while (len--) {
                if (!oput(s, s->out[s->on - dist])) return 0;
            }
        }
    }
}

static int inflate_at(const unsigned char *p, long n, long start, unsigned char **out, long *on)
{
    inf_t s;
    int last;
    memset(&s, 0, sizeof s);
    s.p = p;
    s.n = n;
    if (n < start) return 0;
    s.pos = start;              /* past the zlib or gzip header */
    do {
        int type;
        last = getbits(&s, 1);
        type = getbits(&s, 2);
        if (s.bad) break;
        if (type == 0) {
            unsigned len;
            s.bits = 0; s.nbits = 0;
            if (s.pos + 4 > s.n) { s.bad = 1; break; }
            len = s.p[s.pos] | s.p[s.pos + 1] << 8;
            s.pos += 4;
            if (s.pos + len > s.n) { s.bad = 1; break; }
            while (len--) oput(&s, s.p[s.pos++]);
        } else if (type == 1) {
            huff_t lc, dc;
            unsigned char l[320];
            int i;
            for (i = 0; i < 144; i++) l[i] = 8;
            for (; i < 256; i++) l[i] = 9;
            for (; i < 280; i++) l[i] = 7;
            for (; i < 288; i++) l[i] = 8;
            hbuild(&lc, l, 288);
            for (i = 0; i < 30; i++) l[i] = 5;
            hbuild(&dc, l, 30);
            if (!codes(&s, &lc, &dc)) s.bad = 1;
        } else if (type == 2) {
            static const unsigned char ORD[19] = { 16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15 };
            unsigned char l[320];
            huff_t lc, dc, cc;
            int nlen = getbits(&s, 5) + 257, ndist = getbits(&s, 5) + 1;
            int ncode = getbits(&s, 4) + 4, i = 0;
            if (nlen > 286 || ndist > 30) { s.bad = 1; break; }
            memset(l, 0, sizeof l);
            for (i = 0; i < ncode; i++) l[ORD[i]] = (unsigned char)getbits(&s, 3);
            hbuild(&cc, l, 19);
            i = 0;
            memset(l, 0, sizeof l);
            while (i < nlen + ndist && !s.bad) {
                int sym = hdecode(&s, &cc);
                if (sym < 0) { s.bad = 1; break; }
                if (sym < 16) l[i++] = (unsigned char)sym;
                else {
                    int rep, v = 0;
                    if (sym == 16) {
                        if (!i) { s.bad = 1; break; }
                        v = l[i - 1];
                        rep = 3 + getbits(&s, 2);
                    } else if (sym == 17) rep = 3 + getbits(&s, 3);
                    else rep = 11 + getbits(&s, 7);
                    if (i + rep > nlen + ndist) { s.bad = 1; break; }
                    while (rep--) l[i++] = (unsigned char)v;
                }
            }
            if (s.bad) break;
            hbuild(&lc, l, nlen);
            hbuild(&dc, l + nlen, ndist);
            if (!codes(&s, &lc, &dc)) s.bad = 1;
        } else
            s.bad = 1;
    } while (!last && !s.bad);
    if (s.bad) {
        free(s.out);
        return 0;
    }
    *out = s.out;
    *on = s.on;
    return 1;
}

static int inflate_z(const unsigned char *p, long n, unsigned char **out, long *on)
{
    return inflate_at(p, n, 2, out, on);
}

/* ---------------------------------------------------------------- PNG */

static unsigned be32(const unsigned char *p)
{
    return (unsigned)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3];
}

static int paeth(int a, int b, int c)
{
    int p = a + b - c, pa = abs(p - a), pb = abs(p - b), pc = abs(p - c);
    return pa <= pb && pa <= pc ? a : pb <= pc ? b : c;
}

static int dec_png(const unsigned char *b, long n, jw_img *img)
{
    static const unsigned char SIG[8] = { 137, 80, 78, 71, 13, 10, 26, 10 };
    long pos = 8, idl = 0, idcap = 0;
    unsigned char *idat = 0, *raw = 0, *o = 0, pal[256][3], trns[256];
    int w = 0, h = 0, depth = 0, ct = 0, il = 0, npal = 0, i, ok = 0;
    long rawn = 0;
    int bpp, chan;
    long stride;
    unsigned char *cur, *prev, *pix;
    int pass, x, y;

    if (n < 33 || memcmp(b, SIG, 8)) return 0;
    memset(trns, 255, sizeof trns);
    while (pos + 12 <= n) {
        unsigned len = be32(b + pos);
        const unsigned char *t = b + pos + 4, *d = b + pos + 8;
        if ((long)len > n - pos - 12) break;
        if (!memcmp(t, "IHDR", 4) && len >= 13) {
            w = (int)be32(d); h = (int)be32(d + 4);
            depth = d[8]; ct = d[9]; il = d[12];
        } else if (!memcmp(t, "PLTE", 4)) {
            npal = len / 3 > 256 ? 256 : len / 3;
            for (i = 0; i < npal; i++) { pal[i][0] = d[i * 3]; pal[i][1] = d[i * 3 + 1]; pal[i][2] = d[i * 3 + 2]; }
        } else if (!memcmp(t, "tRNS", 4) && ct == 3) {
            for (i = 0; i < (int)len && i < 256; i++) trns[i] = d[i];
        } else if (!memcmp(t, "IDAT", 4)) {
            if (idl + (long)len > idcap) {
                unsigned char *q;
                idcap = (idl + len) * 2;
                q = (unsigned char *)realloc(idat, idcap);
                if (!q) { free(idat); return 0; }
                idat = q;
            }
            memcpy(idat + idl, d, len);
            idl += len;
        } else if (!memcmp(t, "IEND", 4))
            break;
        pos += 12 + len;
    }
    if (w <= 0 || h <= 0 || w > 30000 || h > 30000 || !idat) goto done;
    if (ct != 0 && ct != 2 && ct != 3 && ct != 4 && ct != 6) goto done;
    if (depth != 1 && depth != 2 && depth != 4 && depth != 8 && depth != 16) goto done;
    if (!inflate_z(idat, idl, &raw, &rawn)) goto done;
    chan = ct == 0 ? 1 : ct == 2 ? 3 : ct == 3 ? 1 : ct == 4 ? 2 : 4;
    bpp = (chan * depth + 7) / 8;
    o = (unsigned char *)calloc((size_t)w * h, 3);
    if (!o) goto done;
    {
        long rp = 0;
        /* Adam7 passes; a plain image is one pass over everything */
        static const int X0[7] = { 0,4,0,2,0,1,0 }, Y0[7] = { 0,0,4,0,2,0,1 };
        static const int DX[7] = { 8,8,4,4,2,2,1 }, DY[7] = { 8,8,8,4,4,2,2 };
        for (pass = 0; pass < (il ? 7 : 1); pass++) {
            int pw = il ? (w - X0[pass] + DX[pass] - 1) / DX[pass] : w;
            int ph = il ? (h - Y0[pass] + DY[pass] - 1) / DY[pass] : h;
            if (pw <= 0 || ph <= 0) continue;
            stride = ((long)pw * chan * depth + 7) / 8;
            if (rp + (stride + 1) * ph > rawn) goto done;
            prev = (unsigned char *)calloc(stride, 1);
            pix = (unsigned char *)malloc(stride);
            if (!prev || !pix) { free(prev); free(pix); goto done; }
            for (y = 0; y < ph; y++) {
                int f = raw[rp++];
                cur = raw + rp;
                rp += stride;
                if (f > 4) { free(prev); free(pix); goto done; }
                for (x = 0; x < stride; x++) {
                    int a = x >= bpp ? pix[x - bpp] : 0, bb = prev[x],
                        c = x >= bpp ? prev[x - bpp] : 0, v = cur[x];
                    switch (f) {
                    case 1: v += a; break;
                    case 2: v += bb; break;
                    case 3: v += (a + bb) >> 1; break;
                    case 4: v += paeth(a, bb, c); break;
                    }
                    pix[x] = (unsigned char)v;
                }
                memcpy(prev, pix, stride);
                for (x = 0; x < pw; x++) {
                    int ox = il ? X0[pass] + x * DX[pass] : x;
                    int oy = il ? Y0[pass] + y * DY[pass] : y;
                    unsigned char *q = o + ((size_t)oy * w + ox) * 3;
                    int v[4], k;
                    for (k = 0; k < chan; k++) {
                        if (depth == 8) v[k] = pix[x * chan + k];
                        else if (depth == 16) v[k] = pix[(x * chan + k) * 2];
                        else {
                            long bit = ((long)x * chan + k) * depth;
                            int sh = 8 - depth - (int)(bit & 7);
                            v[k] = (pix[bit >> 3] >> sh) & ((1 << depth) - 1);
                            if (ct != 3) v[k] = v[k] * 255 / ((1 << depth) - 1);
                        }
                    }
                    if (ct == 3) {
                        int ix = v[0] < npal ? v[0] : 0;
                        int al = trns[v[0] & 255];
                        q[0] = (unsigned char)((pal[ix][0] * al + 255 * (255 - al)) / 255);
                        q[1] = (unsigned char)((pal[ix][1] * al + 255 * (255 - al)) / 255);
                        q[2] = (unsigned char)((pal[ix][2] * al + 255 * (255 - al)) / 255);
                    } else if (ct == 0 || ct == 4) {
                        int al = ct == 4 ? v[1] : 255;
                        int g = (v[0] * al + 255 * (255 - al)) / 255;
                        q[0] = q[1] = q[2] = (unsigned char)g;
                    } else {
                        int al = ct == 6 ? v[3] : 255;
                        q[0] = (unsigned char)((v[0] * al + 255 * (255 - al)) / 255);
                        q[1] = (unsigned char)((v[1] * al + 255 * (255 - al)) / 255);
                        q[2] = (unsigned char)((v[2] * al + 255 * (255 - al)) / 255);
                    }
                }
            }
            free(prev);
            free(pix);
        }
    }
    ok = 1;
done:
    free(idat);
    free(raw);
    if (!ok) { free(o); return 0; }
    img->w = w; img->h = h; img->rgb = o;
    return 1;
}

/* --------------------------------------------------------------- JPEG */

typedef struct {
    unsigned char bits[17];
    unsigned char val[256];
    int look[65536 >> 6];       /* unused, kept simple: decode bit by bit */
    int mincode[17], maxcode[18], valptr[17];
} jh_t;

typedef struct {
    int id, h, v, tq, td, ta;
    int bw, bh;                 /* blocks across / down, padded to the MCU */
    short *coef;                /* bw*bh*64 */
    int pred;
} jc_t;

typedef struct {
    const unsigned char *p;
    long n, pos;
    unsigned long buf;
    int cnt;
    int eobrun;
    int hit;                    /* a marker was met */
} jr_t;

static const unsigned char ZZ[64] = {
    0,1,8,16,9,2,3,10,17,24,32,25,18,11,4,5,12,19,26,33,40,48,41,34,27,20,13,6,7,14,21,28,
    35,42,49,56,57,50,43,36,29,22,15,23,30,37,44,51,58,59,52,45,38,31,39,46,53,60,61,54,47,55,62,63 };

static void jh_make(jh_t *h)
{
    int code = 0, k = 0, l;
    for (l = 1; l <= 16; l++) {
        h->valptr[l] = k;
        h->mincode[l] = code;
        code += h->bits[l];
        k += h->bits[l];
        h->maxcode[l] = h->bits[l] ? code - 1 : -1;
        code <<= 1;
    }
}

static int jr_bit(jr_t *r)
{
    if (!r->cnt) {
        int c = 0;
        if (r->hit || r->pos >= r->n) { r->hit = 1; c = 0; }
        else {
            c = r->p[r->pos++];
            if (c == 0xff) {
                int c2 = r->pos < r->n ? r->p[r->pos] : 0xd9;
                if (c2 == 0) r->pos++;
                else { r->pos--; r->hit = 1; c = 0; }
            }
        }
        r->buf = c;
        r->cnt = 8;
    }
    r->cnt--;
    return (int)((r->buf >> r->cnt) & 1);
}

static int jr_bits(jr_t *r, int n)
{
    int v = 0;
    while (n--) v = v << 1 | jr_bit(r);
    return v;
}

static int jr_huff(jr_t *r, const jh_t *h)
{
    int code = 0, l;
    for (l = 1; l <= 16; l++) {
        code = code << 1 | jr_bit(r);
        if (h->maxcode[l] >= 0 && code <= h->maxcode[l] && code >= h->mincode[l])
            return h->val[h->valptr[l] + code - h->mincode[l]];
    }
    return 0;
}

static int jext(int v, int n)
{
    return n && v < (1 << (n - 1)) ? v - (1 << n) + 1 : v;
}

static void jidct(const short *in, const unsigned short *q, unsigned char *out, int stride)
{
    static float cs[8][8];
    static int init;
    float t[64], u[64];
    int x, y, k, i;
    if (!init) {
        for (x = 0; x < 8; x++)
            for (k = 0; k < 8; k++)
                cs[x][k] = (float)((k ? 1.0 : 1.0 / sqrt(2.0)) * 0.5 * cos((2 * x + 1) * k * 3.14159265358979323846 / 16));
        init = 1;
    }
    for (i = 0; i < 64; i++) t[i] = (float)in[i] * q[i];
    /* t is in natural order: row v, column u */
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; x++) {
            float s = 0;
            for (k = 0; k < 8; k++) s += cs[x][k] * t[y * 8 + k];
            u[y * 8 + x] = s;
        }
    for (x = 0; x < 8; x++)
        for (y = 0; y < 8; y++) {
            float s = 0;
            int v;
            for (k = 0; k < 8; k++) s += cs[y][k] * u[k * 8 + x];
            v = (int)floor(s + 128.5f);
            out[y * stride + x] = (unsigned char)(v < 0 ? 0 : v > 255 ? 255 : v);
        }
}

static int dec_jpg(const unsigned char *b, long n, jw_img *img)
{
    unsigned short qt[4][64];
    jh_t dc[4], ac[4];
    jc_t comp[4];
    int ncomp = 0, w = 0, h = 0, prog = 0, ri = 0, hmax = 1, vmax = 1;
    int mcux = 0, mcuy = 0, i, ok = 0, adobe = -1;
    long pos = 2;
    unsigned char *plane[4] = { 0, 0, 0, 0 };
    unsigned char *o = 0;
    int seen_sof = 0;

    if (n < 4 || b[0] != 0xff || b[1] != 0xd8) return 0;
    memset(comp, 0, sizeof comp);
    memset(qt, 0, sizeof qt);
    memset(dc, 0, sizeof dc);
    memset(ac, 0, sizeof ac);
    while (pos + 4 <= n) {
        int m, len;
        if (b[pos] != 0xff) { pos++; continue; }
        m = b[pos + 1];
        if (m == 0xff || m == 0 || (m >= 0xd0 && m <= 0xd7) || m == 0x01) { pos += m == 0xff ? 1 : 2; continue; }
        if (m == 0xd9) break;
        len = b[pos + 2] << 8 | b[pos + 3];
        if (len < 2 || pos + 2 + len > n) goto done;
        {
            const unsigned char *d = b + pos + 4;
            int dl = len - 2;
            if (m == 0xdb) {
                while (dl > 0) {
                    int pq = d[0] >> 4, tq = d[0] & 15, k;
                    d++; dl--;
                    if (tq > 3) goto done;
                    for (k = 0; k < 64; k++) {
                        if (pq) { if (dl < 2) goto done; qt[tq][ZZ[k]] = d[0] << 8 | d[1]; d += 2; dl -= 2; }
                        else { if (dl < 1) goto done; qt[tq][ZZ[k]] = d[0]; d++; dl--; }
                    }
                }
            } else if (m == 0xc4) {
                while (dl >= 17) {
                    int tc = d[0] >> 4, th = d[0] & 15, k, tot = 0;
                    jh_t *t;
                    if (th > 3) goto done;
                    t = tc ? &ac[th] : &dc[th];
                    t->bits[0] = 0;
                    for (k = 1; k <= 16; k++) { t->bits[k] = d[k]; tot += d[k]; }
                    if (tot > 256 || 17 + tot > dl) goto done;
                    memcpy(t->val, d + 17, tot);
                    jh_make(t);
                    d += 17 + tot; dl -= 17 + tot;
                }
            } else if (m == 0xc0 || m == 0xc1 || m == 0xc2) {
                prog = m == 0xc2;
                if (d[0] != 8 || dl < 6) goto done;
                h = d[1] << 8 | d[2];
                w = d[3] << 8 | d[4];
                ncomp = d[5];
                if (w <= 0 || h <= 0 || w > 30000 || h > 30000 || (ncomp != 1 && ncomp != 3 && ncomp != 4)) goto done;
                if (dl < 6 + 3 * ncomp) goto done;
                for (i = 0; i < ncomp; i++) {
                    comp[i].id = d[6 + i * 3];
                    comp[i].h = d[7 + i * 3] >> 4;
                    comp[i].v = d[7 + i * 3] & 15;
                    comp[i].tq = d[8 + i * 3] & 3;
                    if (comp[i].h < 1 || comp[i].h > 4 || comp[i].v < 1 || comp[i].v > 4) goto done;
                    if (comp[i].h > hmax) hmax = comp[i].h;
                    if (comp[i].v > vmax) vmax = comp[i].v;
                }
                mcux = (w + 8 * hmax - 1) / (8 * hmax);
                mcuy = (h + 8 * vmax - 1) / (8 * vmax);
                for (i = 0; i < ncomp; i++) {
                    comp[i].bw = mcux * comp[i].h;
                    comp[i].bh = mcuy * comp[i].v;
                    comp[i].coef = (short *)calloc((size_t)comp[i].bw * comp[i].bh * 64, sizeof(short));
                    if (!comp[i].coef) goto done;
                }
                seen_sof = 1;
            } else if (m == 0xc3 || (m >= 0xc5 && m <= 0xcf && m != 0xc8 && m != 0xcc)) {
                goto done;      /* lossless, arithmetic, hierarchical */
            } else if (m == 0xdd) {
                ri = d[0] << 8 | d[1];
            } else if (m == 0xee && dl >= 12 && !memcmp(d, "Adobe", 5)) {
                adobe = d[11];
            } else if (m == 0xda) {
                int ns = d[0], ss, se, ah, al, ci[4], k;
                jr_t r;
                int mcu, total, mx = 0;
                if (!seen_sof || ns < 1 || ns > 4 || dl < 1 + ns * 2 + 3) goto done;
                for (k = 0; k < ns; k++) {
                    int id = d[1 + k * 2], j;
                    for (j = 0; j < ncomp; j++) if (comp[j].id == id) break;
                    if (j == ncomp) goto done;
                    ci[k] = j;
                    comp[j].td = d[2 + k * 2] >> 4 & 3;
                    comp[j].ta = d[2 + k * 2] & 3;
                }
                ss = d[1 + ns * 2]; se = d[2 + ns * 2];
                ah = d[3 + ns * 2] >> 4; al = d[3 + ns * 2] & 15;
                if (!prog) { ss = 0; se = 63; ah = al = 0; }
                if (se > 63 || ss > se) goto done;
                memset(&r, 0, sizeof r);
                r.p = b; r.n = n; r.pos = pos + 2 + len;
                for (k = 0; k < ncomp; k++) comp[k].pred = 0;
                r.eobrun = 0;
                if (ns == 1) {
                    jc_t *c = &comp[ci[0]];
                    int bw = (((w * c->h + hmax - 1) / hmax) + 7) / 8, bh = (((h * c->v + vmax - 1) / vmax) + 7) / 8;
                    total = bw * bh;
                    (void)mx;
                    for (mcu = 0; mcu < total; mcu++) {
                        int bx = mcu % bw, by = mcu / bw;
                        short *blk;
                        if (ri && mcu && mcu % ri == 0) {
                            r.cnt = 0; r.hit = 0;
                            if (r.pos + 1 < n && b[r.pos] == 0xff && b[r.pos + 1] >= 0xd0 && b[r.pos + 1] <= 0xd7) r.pos += 2;
                            for (k = 0; k < ncomp; k++) comp[k].pred = 0;
                            r.eobrun = 0;
                        }
                        blk = c->coef + ((size_t)by * c->bw + bx) * 64;
                        goto_block:;
                        {
                            const jh_t *td = &dc[c->td], *ta = &ac[c->ta];
                            if (!prog) {
                                int t = jr_huff(&r, td), diff = t ? jext(jr_bits(&r, t), t) : 0, kk;
                                c->pred += diff;
                                blk[0] = (short)c->pred;
                                for (kk = 1; kk < 64;) {
                                    int rs = jr_huff(&r, ta), rr = rs >> 4, s = rs & 15;
                                    if (!s) { if (rr == 15) { kk += 16; continue; } break; }
                                    kk += rr;
                                    if (kk > 63) break;
                                    blk[ZZ[kk]] = (short)jext(jr_bits(&r, s), s);
                                    kk++;
                                }
                            } else if (ss == 0) {
                                if (!ah) {
                                    int t = jr_huff(&r, td), diff = t ? jext(jr_bits(&r, t), t) : 0;
                                    c->pred += diff;
                                    blk[0] = (short)(c->pred * (1 << al));
                                } else if (jr_bit(&r))
                                    blk[0] |= (short)(1 << al);
                            } else if (!ah) {
                                int kk;
                                if (r.eobrun > 0) r.eobrun--;
                                else {
                                    for (kk = ss; kk <= se;) {
                                        int rs = jr_huff(&r, ta), rr = rs >> 4, s = rs & 15;
                                        if (!s) {
                                            if (rr < 15) { r.eobrun = (1 << rr) - 1 + (rr ? jr_bits(&r, rr) : 0); break; }
                                            kk += 16;
                                            continue;
                                        }
                                        kk += rr;
                                        if (kk > 63) break;
                                        blk[ZZ[kk]] = (short)(jext(jr_bits(&r, s), s) * (1 << al));
                                        kk++;
                                    }
                                }
                            } else {
                                /* refinement of AC */
                                int kk = ss, p1 = 1 << al, m1 = -1 * (1 << al);
                                if (r.eobrun <= 0) {
                                    for (; kk <= se; kk++) {
                                        int rs = jr_huff(&r, ta), rr = rs >> 4, s = rs & 15, val = 0;
                                        if (!s) {
                                            if (rr < 15) { r.eobrun = (1 << rr) + (rr ? jr_bits(&r, rr) : 0); break; }
                                        } else
                                            val = jr_bit(&r) ? p1 : m1;
                                        for (; kk <= se; kk++) {
                                            short *cf = &blk[ZZ[kk]];
                                            if (*cf) {
                                                if (jr_bit(&r) && !(*cf & p1))
                                                    *cf = (short)(*cf >= 0 ? *cf + p1 : *cf + m1);
                                            } else {
                                                if (--rr < 0) break;
                                            }
                                        }
                                        if (val && kk <= 63) blk[ZZ[kk]] = (short)val;
                                    }
                                }
                                if (r.eobrun > 0) {
                                    for (; kk <= se; kk++) {
                                        short *cf = &blk[ZZ[kk]];
                                        if (*cf && jr_bit(&r) && !(*cf & p1))
                                            *cf = (short)(*cf >= 0 ? *cf + p1 : *cf + m1);
                                    }
                                    r.eobrun--;
                                }
                            }
                        }
                    }
                } else {
                    for (mcu = 0; mcu < mcux * mcuy; mcu++) {
                        int mx2 = mcu % mcux, my = mcu / mcux;
                        if (ri && mcu && mcu % ri == 0) {
                            r.cnt = 0; r.hit = 0;
                            if (r.pos + 1 < n && b[r.pos] == 0xff && b[r.pos + 1] >= 0xd0 && b[r.pos + 1] <= 0xd7) r.pos += 2;
                            for (k = 0; k < ncomp; k++) comp[k].pred = 0;
                            r.eobrun = 0;
                        }
                        for (k = 0; k < ns; k++) {
                            jc_t *c = &comp[ci[k]];
                            int yy, xx;
                            for (yy = 0; yy < c->v; yy++)
                                for (xx = 0; xx < c->h; xx++) {
                                    short *blk = c->coef + ((size_t)(my * c->v + yy) * c->bw + mx2 * c->h + xx) * 64;
                                    const jh_t *td = &dc[c->td], *ta = &ac[c->ta];
                                    if (!prog) {
                                        int t = jr_huff(&r, td), diff = t ? jext(jr_bits(&r, t), t) : 0, kk;
                                        c->pred += diff;
                                        blk[0] = (short)c->pred;
                                        for (kk = 1; kk < 64;) {
                                            int rs = jr_huff(&r, ta), rr = rs >> 4, s = rs & 15;
                                            if (!s) { if (rr == 15) { kk += 16; continue; } break; }
                                            kk += rr;
                                            if (kk > 63) break;
                                            blk[ZZ[kk]] = (short)jext(jr_bits(&r, s), s);
                                            kk++;
                                        }
                                    } else if (!ah) {
                                        int t = jr_huff(&r, td), diff = t ? jext(jr_bits(&r, t), t) : 0;
                                        c->pred += diff;
                                        blk[0] = (short)(c->pred * (1 << al));
                                    } else if (jr_bit(&r))
                                        blk[0] |= (short)(1 << al);
                                }
                        }
                    }
                }
                /* skip to the next marker */
                pos = r.pos;
                while (pos + 1 < n && !(b[pos] == 0xff && b[pos + 1] != 0 && !(b[pos + 1] >= 0xd0 && b[pos + 1] <= 0xd7)))
                    pos++;
                continue;
            }
        }
        pos += 2 + len;
    }
    if (!seen_sof) goto done;
    /* IDCT into planes at full component resolution, then upsample */
    for (i = 0; i < ncomp; i++) {
        jc_t *c = &comp[i];
        int bx, by;
        plane[i] = (unsigned char *)malloc((size_t)c->bw * 8 * c->bh * 8);
        if (!plane[i]) goto done;
        for (by = 0; by < c->bh; by++)
            for (bx = 0; bx < c->bw; bx++)
                jidct(c->coef + ((size_t)by * c->bw + bx) * 64, qt[c->tq],
                      plane[i] + (size_t)by * 8 * c->bw * 8 + bx * 8, c->bw * 8);
    }
    o = (unsigned char *)malloc((size_t)w * h * 3);
    if (!o) goto done;
    {
        int x, y;
        int ycc = ncomp == 3 ? (adobe != 0) : (ncomp == 4 && adobe == 2);
        for (y = 0; y < h; y++)
            for (x = 0; x < w; x++) {
                int v[4], k;
                unsigned char *q = o + ((size_t)y * w + x) * 3;
                for (k = 0; k < ncomp; k++) {
                    jc_t *c = &comp[k];
                    if (c->h == hmax && c->v == vmax) {
                        v[k] = plane[k][(size_t)y * c->bw * 8 + x];
                    } else {
                        /* libjpeg's "fancy" upsampling is a triangle filter: the
                           samples sit in the middle of what they stand for and a
                           pixel is the linear mix of the two nearest, edges
                           repeated */
                        int vw = (w * c->h + hmax - 1) / hmax, vh = (h * c->v + vmax - 1) / vmax;
                        double fx = (x + 0.5) * c->h / hmax - 0.5, fy = (y + 0.5) * c->v / vmax - 0.5;
                        int x0 = (int)floor(fx), y0 = (int)floor(fy);
                        double ax = fx - x0, ay = fy - y0, s;
                        int xa = x0 < 0 ? 0 : x0 >= vw ? vw - 1 : x0, xb = x0 + 1 < 0 ? 0 : x0 + 1 >= vw ? vw - 1 : x0 + 1;
                        int ya = y0 < 0 ? 0 : y0 >= vh ? vh - 1 : y0, yb = y0 + 1 < 0 ? 0 : y0 + 1 >= vh ? vh - 1 : y0 + 1;
                        size_t rs = (size_t)c->bw * 8;

                        s = (1 - ay) * ((1 - ax) * plane[k][ya * rs + xa] + ax * plane[k][ya * rs + xb])
                          + ay * ((1 - ax) * plane[k][yb * rs + xa] + ax * plane[k][yb * rs + xb]);
                        v[k] = (int)(s + 0.5);
                    }
                }
                if (ncomp == 1) q[0] = q[1] = q[2] = (unsigned char)v[0];
                else {
                    float R, G, B;
                    if (ncomp == 4) {
                        /* CMYK / YCCK, Adobe style (inverted) */
                        if (ycc) {
                            float Y = (float)v[0], cb = v[1] - 128.f, cr = v[2] - 128.f;
                            R = Y + 1.402f * cr; G = Y - 0.344136f * cb - 0.714136f * cr; B = Y + 1.772f * cb;
                            R = 255 - R; G = 255 - G; B = 255 - B;
                            v[0] = (int)(R < 0 ? 0 : R > 255 ? 255 : R);
                            v[1] = (int)(G < 0 ? 0 : G > 255 ? 255 : G);
                            v[2] = (int)(B < 0 ? 0 : B > 255 ? 255 : B);
                        }
                        q[0] = (unsigned char)(v[0] * v[3] / 255);
                        q[1] = (unsigned char)(v[1] * v[3] / 255);
                        q[2] = (unsigned char)(v[2] * v[3] / 255);
                    } else if (ycc) {
                        float Y = (float)v[0], cb = v[1] - 128.f, cr = v[2] - 128.f;
                        R = Y + 1.402f * cr; G = Y - 0.344136f * cb - 0.714136f * cr; B = Y + 1.772f * cb;
                        q[0] = (unsigned char)(R < 0 ? 0 : R > 255 ? 255 : (int)(R + 0.5f));
                        q[1] = (unsigned char)(G < 0 ? 0 : G > 255 ? 255 : (int)(G + 0.5f));
                        q[2] = (unsigned char)(B < 0 ? 0 : B > 255 ? 255 : (int)(B + 0.5f));
                    } else {
                        q[0] = (unsigned char)v[0]; q[1] = (unsigned char)v[1]; q[2] = (unsigned char)v[2];
                    }
                }
            }
    }
    ok = 1;
done:
    for (i = 0; i < 4; i++) { free(comp[i].coef); free(plane[i]); }
    if (!ok) { free(o); return 0; }
    img->w = w; img->h = h; img->rgb = o;
    return 1;
}

/* ------------------------------------------------------------ the rest */

int jw_img_decode(const unsigned char *b, long n, jw_img *img)
{
    img->w = img->h = 0;
    img->rgb = 0;
    if (!b || n < 4) return 0;
    if (b[0] == 'B' && b[1] == 'M') return dec_bmp(b, n, img);
    if (b[0] == 137 && b[1] == 'P') return dec_png(b, n, img);
    if (b[0] == 0xff && b[1] == 0xd8) return dec_jpg(b, n, img);
    return 0;
}

void jw_img_free(jw_img *img)
{
    free(img->rgb);
    img->rgb = 0;
}

typedef struct {
    char *name;
    unsigned char *bytes;
    long n;
    jw_img img;
    int tried;
    unsigned char *gz;          /* the gzip the file held it as, kept so that a
                                   drawing opened and saved again writes the
                                   same bytes back */
    long ngz;
} slot_t;

static slot_t *slots;
static int nslot, cslot;
static jw_img_loader loader;

static const char *base_of(const char *s)
{
    const char *p = s, *q = s;
    for (; *p; p++) {
        if ((unsigned char)*p >= 0x81 && (unsigned char)*p <= 0x9f ||
            (unsigned char)*p >= 0xe0 && (unsigned char)*p <= 0xfc) {
            if (p[1]) p++;
            continue;
        }
        if (*p == '\\' || *p == '/' || *p == ':') q = p + 1;
    }
    return q;
}

static int same(const char *a, const char *b)
{
    for (; *a && *b; a++, b++) {
        int x = *a == '/' ? '\\' : *a, y = *b == '/' ? '\\' : *b;
        if ((unsigned char)x < 0x80 && (unsigned char)y < 0x80) {
            if (x >= 'A' && x <= 'Z') x += 32;
            if (y >= 'A' && y <= 'Z') y += 32;
        }
        if (x != y) return 0;
    }
    return *a == *b;
}

static slot_t *find(const char *name)
{
    int i;
    const char *bn = base_of(name);
    for (i = 0; i < nslot; i++)
        if (same(slots[i].name, name)) return &slots[i];
    for (i = 0; i < nslot; i++)
        if (same(base_of(slots[i].name), bn) && !strchr(slots[i].name, '\\') && !strchr(slots[i].name, '/'))
            return &slots[i];
    return 0;
}

void jw_img_put(const char *name, const unsigned char *b, long n)
{
    slot_t *s = find(name);
    if (s && same(s->name, name)) {
        free(s->bytes);
        free(s->gz);
        s->gz = 0;
        s->ngz = 0;
        jw_img_free(&s->img);
    } else {
        if (nslot == cslot) {
            cslot = cslot ? cslot * 2 : 8;
            slots = (slot_t *)realloc(slots, cslot * sizeof *slots);
        }
        s = &slots[nslot++];
        s->name = (char *)malloc(strlen(name) + 1);
        strcpy(s->name, name);
        s->gz = 0;
        s->ngz = 0;
    }
    s->bytes = (unsigned char *)malloc(n > 0 ? n : 1);
    memcpy(s->bytes, b, n);
    s->n = n;
    s->img.rgb = 0;
    s->tried = 0;
}

void jw_img_set_loader(jw_img_loader f)
{
    loader = f;
}

const unsigned char *jw_img_bytes(const char *name, long *n)
{
    slot_t *s = find(name);
    if (!s && loader) {
        long ln = 0;
        unsigned char *b = loader(name, &ln);
        if (b) {
            jw_img_put(name, b, ln);
            free(b);
            s = find(name);
        }
    }
    if (!s) return 0;
    if (n) *n = s->n;
    return s->bytes;
}

const jw_img *jw_img_get(const char *name)
{
    slot_t *s;
    if (!jw_img_bytes(name, 0)) return 0;
    s = find(name);
    if (!s) return 0;
    if (!s->img.rgb && !s->tried) {
        s->tried = 1;
        jw_img_decode(s->bytes, s->n, &s->img);
    }
    return s->img.rgb ? &s->img : 0;
}

/* A gzip file's content.  0 when it is not one or is damaged. */
int jw_gunzip(const unsigned char *g, long n, unsigned char **out, long *on)
{
    long pos = 10;
    int flg;
    if (n < 18 || g[0] != 0x1f || g[1] != 0x8b || g[2] != 8) return 0;
    flg = g[3];
    if (flg & 4) { if (pos + 2 > n) return 0; pos += 2 + (g[pos] | g[pos + 1] << 8); }
    if (flg & 8) { while (pos < n && g[pos]) pos++; pos++; }
    if (flg & 16) { while (pos < n && g[pos]) pos++; pos++; }
    if (flg & 2) pos += 2;
    if (pos >= n) return 0;
    return inflate_at(g, n - 8, pos, out, on);
}

/* A drawing was read and held this picture, gzipped: keep the bytes it came
   in as, so that saving the drawing again writes the same ones. */
int jw_img_put_gz(const char *name, const unsigned char *g, long n)
{
    unsigned char *raw;
    long rn;
    slot_t *s;
    if (!jw_gunzip(g, n, &raw, &rn)) return 0;
    jw_img_put(name, raw, rn);
    free(raw);
    s = find(name);
    if (s) {
        s->gz = (unsigned char *)malloc((size_t)n);
        if (s->gz) { memcpy(s->gz, g, (size_t)n); s->ngz = n; }
    }
    return 1;
}

/* The gzip for a picture in the store: what it came in as, or a fresh one.
   The caller frees *out. */
int jw_img_gz(const char *name, unsigned char **out, long *n)
{
    slot_t *s = find(name);
    if (!s || !s->bytes) return 0;
    if (s->gz) {
        *out = (unsigned char *)malloc((size_t)s->ngz);
        if (!*out) return 0;
        memcpy(*out, s->gz, (size_t)s->ngz);
        *n = s->ngz;
        return 1;
    }
    return jw_gzip(s->bytes, s->n, out, n);
}

void jw_img_forget(void)
{
    int i;
    for (i = 0; i < nslot; i++) {
        free(slots[i].name);
        free(slots[i].bytes);
        free(slots[i].gz);
        jw_img_free(&slots[i].img);
    }
    free(slots);
    slots = 0;
    nslot = cslot = 0;
}
