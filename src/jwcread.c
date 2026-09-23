/* Reading a JWC -- 「JWCファイルを開く」 (menu 32809).
 *
 * JWC is what Jw_cad wrote before Windows: a short run of text at the top
 * and raw records after it.  The writer is in the original at 0x00521f..,
 * but Ghidra makes little of it, so this was read instead by having the
 * original write one out of a drawing whose contents were known
 * (tools/mkgeom.c) and holding the bytes up against them.  RESUME.md has
 * the table this follows.
 *
 * The one thing worth knowing up front: a JWC measures in 518ths of the
 * sheet's width, whatever the sheet is, so a coordinate is
 *
 *     (millimetres on the paper + half the sheet) * 518 / the sheet's width
 *
 * as a 32-bit float -- and the sheet is the one the drawing being opened is
 * already set to, not anything in the file.  A file that says A3 opens the
 * same as one that says A1.
 *
 * Solids do not exist in a JWC: the original writes the outline of one as
 * lines, so that is what comes back.  Angles are whole degrees.
 */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

#define PI 3.14159265358979323846

/* Where the records begin.  Everything between the three lines of text and
   here is settings of a fixed size in this version of the format. */
#define JWC_ELEM 0x975
#define JWC_CSV  0xc8

static double f32(const unsigned char *b)
{
    float v;

    memcpy(&v, b, 4);
    return (double)v;
}

static int i32(const unsigned char *b)
{
    return (int)((unsigned)b[0] | ((unsigned)b[1] << 8)
                 | ((unsigned)b[2] << 16) | ((unsigned)b[3] << 24));
}

static int i16(const unsigned char *b)
{
    return (short)((unsigned short)(b[0] | (b[1] << 8)));
}

/* An angle in whole degrees, brought into -180 to 180 the way the original
   leaves a start angle. */
static double fold(double deg)
{
    while (deg > 180.0)
        deg -= 360.0;
    while (deg <= -180.0)
        deg += 360.0;
    return deg * PI / 180.0;
}

int jw_jwc_read(jw_drawing *d, const unsigned char *b, long n)
{
    double unit, half_w, half_h;
    long at, pool;
    int count[4] = { 0, 0, 0, 0 }, i, k;
    const unsigned char *p;

    if (n < JWC_ELEM || memcmp(b, "jw_cad(c)data", 13))
        return 0;

    /* the four counts at the head of the first line: lines, arcs, texts,
       points, in the order the records themselves come in */
    p = b + JWC_CSV;
    for (i = 0; i < 4; i++) {
        int v = 0, sign = 1;

        while (*p == ' ')
            p++;
        if (*p == '-') {
            sign = -1;
            p++;
        }
        while (*p >= '0' && *p <= '9')
            v = v * 10 + (*p++ - '0');
        count[i] = v * sign;
        if (*p == ',')
            p++;
        if (count[i] < 0 || count[i] > 1000000)
            return 0;
    }

    half_w = d->paper_hw;
    half_h = d->paper_hh;
    if (half_w <= 0.0)
        return 0;
    unit = half_w * 2.0 / 518.0;

    while (d->nobj > 0)
        jw_remove(d, d->nobj - 1);

    at = JWC_ELEM;
    for (k = 0; k < count[0]; k++) {          /* lines */
        jw_obj *o;

        if (at + 22 > n)
            return 0;
        o = jw_add(d, JW_SEN);
        if (!o)
            return 0;
        o->d[0] = f32(b + at) * unit - half_w;
        o->d[1] = f32(b + at + 4) * unit - half_h;
        o->d[2] = f32(b + at + 8) * unit - half_w;
        o->d[3] = f32(b + at + 12) * unit - half_h;
        o->ltype = b[at + 16];
        o->color = b[at + 17];
        o->layer = b[at + 18];
        o->lgroup = 0;
        o->width = 0;
        at += 22;
    }
    for (k = 0; k < count[1]; k++) {          /* arcs and circles */
        jw_obj *o;
        double a0, a1;

        if (at + 32 > n)
            return 0;
        o = jw_add(d, JW_ENKO);
        if (!o)
            return 0;
        a0 = (double)i32(b + at + 16);
        a1 = (double)i32(b + at + 20);
        o->d[0] = f32(b + at) * unit - half_w;
        o->d[1] = f32(b + at + 4) * unit - half_h;
        o->d[2] = f32(b + at + 8) * unit;
        o->d[3] = fold(a0);
        o->d[4] = a1 == a0 ? 2.0 * PI
                : (a1 - a0 < 0.0 ? a1 - a0 + 360.0 : a1 - a0) * PI / 180.0;
        o->d[5] = fold((double)i16(b + at + 24));
        o->d[6] = (double)i32(b + at + 12) / 10000.0;
        o->n = a1 == a0;                      /* a whole circle */
        o->ltype = b[at + 26];
        o->color = b[at + 27];
        o->layer = b[at + 28];
        o->lgroup = 0;
        o->width = 0;
        at += 32;
    }
    pool = at + (long)count[2] * 24;
    for (k = 0; k < count[2]; k++) {          /* texts */
        jw_obj *o;
        long off;
        int style;

        if (at + 24 > n)
            return 0;
        o = jw_add(d, JW_MOJI);
        if (!o)
            return 0;
        o->d[0] = f32(b + at) * unit - half_w;
        o->d[1] = f32(b + at + 4) * unit - half_h;
        o->d[2] = f32(b + at + 8) * unit - half_w;
        o->d[3] = f32(b + at + 12) * unit - half_h;
        /* the low three bytes point into the strings that follow */
        off = (long)(b[at + 16] | (b[at + 17] << 8) | (b[at + 18] << 16));
        style = b[at + 20];
        o->n = style;
        o->layer = b[at + 21];
        o->lgroup = 0;
        o->ltype = 1;
        o->width = 0;
        /* a JWC text carries no size and no colour of its own: they are the
           文字種's, out of the drawing being opened into */
        if (style >= 1 && style <= 10) {
            o->d[4] = d->style[style - 1].w;
            o->d[5] = d->style[style - 1].h;
            o->d[6] = d->style[style - 1].sp;
            o->color = (unsigned short)d->style[style - 1].color;
        } else {
            o->d[4] = o->d[5] = 2.5;
            o->d[6] = 0.0;
            o->color = 1;
        }
        o->d[7] = 0.0;
        if (pool + off < n) {
            const char *s = (const char *)b + pool + off;
            long m = 0;

            while (pool + off + m < n && s[m])
                m++;
            if (pool + off + m < n)
                o->text = jw_add_str(d, s);
        }
        at += 24;
    }
    /* one NUL-terminated string per text, and then the points */
    at = pool;
    for (k = 0; k < count[2]; k++) {
        while (at < n && b[at])
            at++;
        if (at < n)
            at++;
    }
    for (k = 0; k < count[3]; k++) {          /* points */
        jw_obj *o;

        if (at + 12 > n)
            break;
        o = jw_add(d, JW_TEN);
        if (!o)
            return 0;
        o->d[0] = f32(b + at) * unit - half_w;
        o->d[1] = f32(b + at + 4) * unit - half_h;
        o->n = b[at + 8];
        o->ltype = 1;
        o->color = b[at + 9];
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        at += 12;
    }
    return 1;
}
