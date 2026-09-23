/* Writing a JWC -- 「JWC形式で保存」 (menu 32810).
 *
 * The other half of src/jwcread.c, and it follows the same table: four
 * 200-byte lines of text, 1,621 bytes of settings, and then the records --
 * lines, arcs, texts, the run of text the texts point into, and points.
 * A coordinate is
 *
 *     (millimetres on the paper + half the sheet) * 518 / the sheet's width
 *
 * as a 32-bit float, and an angle is a whole degree.
 *
 * Everything in the head that does not belong to the drawing is baked from
 * one the original wrote (src/gen/jwc.h, made by tools/mkjwc.py).  Five
 * fields of the first line are not understood -- tools/mkjwc.py says which
 * -- and are carried over from that file; the last of them is where the
 * drawing sits on screen, which moves by one for every turn of the wheel.
 *
 * A JWC has no solids: the original writes the outline of one as lines,
 * after all the lines the drawing itself has, and that is what this does.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "gen/jwc.h"

#define PI 3.14159265358979323846

typedef struct {
    unsigned char *b;
    long n, cap;
    int bad;
} jbuf;

static void put(jbuf *w, const void *p, long n)
{
    if (w->bad)
        return;
    if (w->n + n > w->cap) {
        long want = (w->n + n) * 2 + 4096;
        unsigned char *t = (unsigned char *)realloc(w->b, (size_t)want);

        if (!t) {
            w->bad = 1;
            return;
        }
        w->b = t;
        w->cap = want;
    }
    memcpy(w->b + w->n, p, (size_t)n);
    w->n += n;
}

static void put_f(jbuf *w, double v)
{
    float f = (float)v;

    put(w, &f, 4);
}

static void put_l(jbuf *w, int v)
{
    unsigned char t[4];

    t[0] = (unsigned char)v;
    t[1] = (unsigned char)(v >> 8);
    t[2] = (unsigned char)(v >> 16);
    t[3] = (unsigned char)(v >> 24);
    put(w, t, 4);
}

static void put_s(jbuf *w, int v)
{
    unsigned char t[2];

    t[0] = (unsigned char)v;
    t[1] = (unsigned char)(v >> 8);
    put(w, t, 2);
}

static void put_b(jbuf *w, int v)
{
    unsigned char c = (unsigned char)v;

    put(w, &c, 1);
}

/* One of the 200-byte lines: the text, a NUL, spaces, and a newline in the
   last byte, which is how the original leaves them. */
static void line200(unsigned char *at, const char *s)
{
    size_t k = strlen(s);

    if (k > 198)
        k = 198;
    memcpy(at, s, k);
    at[k] = 0;
    memset(at + k + 1, ' ', 199 - (k + 1));
    at[199] = '\n';
}

/* Replace the nth field (counting from one) of a comma-separated line. */
static void field(char *line, int nth, const char *val)
{
    char out[256];
    const char *p = line;
    int i = 1;
    size_t k = 0;

    out[0] = 0;
    while (*p && i < nth) {
        if (*p == ',')
            i++;
        if (k < sizeof out - 1)
            out[k++] = *p;
        p++;
    }
    out[k] = 0;
    if (i != nth)
        return;
    strncat(out, val, sizeof out - strlen(out) - 1);
    while (*p && *p != ',')
        p++;
    strncat(out, p, sizeof out - strlen(out) - 1);
    strcpy(line, out);
}

/* An angle in whole degrees, brought into 0..359. */
static int deg(double rad)
{
    double v = rad / PI * 180.0;
    int k;

    while (v < 0.0)
        v += 360.0;
    while (v >= 360.0)
        v -= 360.0;
    k = (int)(v + 0.5);
    return k % 360;
}

/* Which 文字種 a text is written as.  One that has a number keeps it; one
   that carries its own size (文字種 0, 任意) has to be given one, and the
   original gives it the last of the ten that is no taller than the text --
   which is 2 for the 2.5mm texts of Test5.jww and 10 for its 20mm ones. */
static int style_of(const jw_drawing *d, const jw_obj *o)
{
    int i, best = 1;

    if (o->n >= 1 && o->n <= 10)
        return o->n;
    for (i = 0; i < 10; i++)
        if (d->style[i].h <= o->d[5] + 1e-9)
            best = i + 1;
    return best;
}

/* How wide a text is in its 文字種: a full-width letter takes the 文字種's
   width plus its spacing, a half-width one takes half of that, and the last
   letter's spacing is not counted.  The original writes the far end of a
   text worked out this way rather than the one the drawing holds, which
   matters when the text carried its own size and has been given a 文字種
   instead -- Test5.jww's 20mm texts come out at 文字種 10's 10mm.  */
static double text_len(const jw_drawing *d, const jw_obj *o, int style)
{
    const unsigned char *s = (const unsigned char *)jw_str(d, o->text);
    double w = d->style[style - 1].w, sp = d->style[style - 1].sp;
    double half = 0.0;

    while (*s) {
        if ((*s >= 0x81 && *s <= 0x9f) || (*s >= 0xe0 && *s <= 0xfc)) {
            if (s[1])
                s++;
            half += 2.0;
        } else {
            half += 1.0;
        }
        s++;
    }
    if (half <= 0.0)
        return 0.0;
    /* Test5's JWC comes out byte for byte the original's with this, and it
       does have 文字種 with a gap between the letters -- so this is the rule
       here, whatever the .jww reader does to a text's baseline (which is a
       different sum again: see RESUME.md). */
    return half / 2.0 * (w + sp) - sp;
}

/* the four corners of a solid, closed, and how many sides that makes */
static int corners(const jw_obj *o, double *x, double *y)
{
    int n = 4, i;

    for (i = 0; i < 4; i++) {
        x[i] = o->d[i * 2];
        y[i] = o->d[i * 2 + 1];
    }
    if (x[3] == x[2] && y[3] == y[2])
        n = 3;                  /* a triangle keeps its last corner twice */
    return n;
}

int jw_jwc_write(const jw_drawing *d, unsigned char **out, long *n)
{
    jbuf w;
    unsigned char head[JWC_HEAD_N];
    char csv[256], num[64];
    double hw = d->paper_hw, hh = d->paper_hh, unit;
    int nline = 0, narc = 0, ntext = 0, npoint = 0, i, pool = 0;
    const char *name;

    *out = 0;
    *n = 0;
    if (hw <= 0.0)
        return 0;
    unit = 518.0 / (hw * 2.0);
    memset(&w, 0, sizeof w);
    memcpy(head, JWC_HEAD, JWC_HEAD_N);

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double x[4], y[4];
        jw_obj round;

        if (!jw_text_drawn(o))
            continue;           /* a text with no length is not written */
        switch (o->cls) {
        case JW_SEN:   nline++; break;
        case JW_ENKO:  narc++; break;
        case JW_MOJI:
            ntext++;
            pool += (int)strlen(jw_str(d, o->text)) + 1;
            break;
        case JW_TEN:   npoint++; break;
        case JW_SOLID:
            /* a 円ソリッド is one arc and no lines at all -- the original
               does not even close a part of a circle in a JWC */
            if (jw_round_solid(o, &round))
                narc++;
            else
                nline += corners(o, x, y);
            break;
        default: break;
        }
    }

    /* the drawing's name, two lines of 32 bytes */
    name = jw_str(d, d->name);
    {
        int k = 0, j;

        for (j = 0; j < 32 && name[k]; j++, k++) {
            head[JWC_NAME + j] = (unsigned char)name[k];
            if (name[k] == '\n') {
                k++;
                break;
            }
        }
        for (j = 0; j < 32 && name[k]; j++, k++)
            head[JWC_NAME + 32 + j] = (unsigned char)name[k];
    }

    /* the first line: the four counts and the scale */
    strncpy(csv, JWC_CSV1_TEXT, sizeof csv - 1);
    csv[sizeof csv - 1] = 0;
    sprintf(num, "%d", nline);
    field(csv, 1, num);
    sprintf(num, "%d", narc);
    field(csv, 2, num);
    sprintf(num, "%d", ntext);
    field(csv, 3, num);
    sprintf(num, "%d", npoint);
    field(csv, 4, num);
    sprintf(num, "%g", d->group[0].scale > 0.0 ? d->group[0].scale : 1.0);
    field(csv, 10, num);
    line200(head + JWC_CSV1, csv);

    /* the third: how long the run of text is */
    strncpy(csv, JWC_CSV3_TEXT, sizeof csv - 1);
    csv[sizeof csv - 1] = 0;
    sprintf(num, "4000:%04x", (unsigned)pool);
    field(csv, 2, num);
    line200(head + JWC_CSV3, csv);

    /* the sixteen layer group scales */
    for (i = 0; i < 16; i++) {
        float f = (float)(d->group[i].scale > 0.0 ? d->group[i].scale : 1.0);

        memcpy(head + JWC_SCALES + i * 4, &f, 4);
    }
    put(&w, head, JWC_HEAD_N);

    for (i = 0; i < d->ndrawn; i++) {   /* the lines the drawing has */
        const jw_obj *o = &d->obj[i];

        if (o->cls != JW_SEN)
            continue;
        put_f(&w, (o->d[0] + hw) * unit);
        put_f(&w, (o->d[1] + hh) * unit);
        put_f(&w, (o->d[2] + hw) * unit);
        put_f(&w, (o->d[3] + hh) * unit);
        put_b(&w, o->ltype);
        put_b(&w, o->color);
        put_b(&w, o->layer & 15);
        put_b(&w, 0);
        put_s(&w, 0);
    }
    for (i = 0; i < d->ndrawn; i++) {   /* and the outline of each solid */
        const jw_obj *o = &d->obj[i];
        double x[4], y[4];
        int k, m;

        if (o->cls != JW_SOLID || o->ltype == 101)
            continue;
        m = corners(o, x, y);
        for (k = 0; k < m; k++) {
            int e = (k + 1) % m;

            put_f(&w, (x[k] + hw) * unit);
            put_f(&w, (y[k] + hh) * unit);
            put_f(&w, (x[e] + hw) * unit);
            put_f(&w, (y[e] + hh) * unit);
            put_b(&w, o->ltype);
            put_b(&w, o->color);
            put_b(&w, o->layer & 15);
            put_b(&w, 0);
            put_s(&w, 0);
        }
    }
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        jw_obj round;
        int a0, a1;

        if (jw_round_solid(o, &round))
            o = &round;
        else if (o->cls != JW_ENKO)
            continue;
        /* the start is where the sweep begins when it runs the other way,
           because a JWC arc always goes anticlockwise */
        if (o->d[4] >= 2.0 * PI - 1e-9 || o->d[4] <= -2.0 * PI + 1e-9) {
            a0 = a1 = deg(o->d[3]);
        } else if (o->d[4] < 0.0) {
            a0 = deg(o->d[3] + o->d[4]);
            a1 = deg(o->d[3]);
        } else {
            a0 = deg(o->d[3]);
            a1 = deg(o->d[3] + o->d[4]);
        }
        put_f(&w, (o->d[0] + hw) * unit);
        put_f(&w, (o->d[1] + hh) * unit);
        put_f(&w, o->d[2] * unit);
        put_l(&w, (int)(o->d[6] * 10000.0 + 0.5));
        put_l(&w, a0);
        put_l(&w, a1);
        put_s(&w, (short)deg(o->d[5]));
        put_b(&w, o->ltype);
        put_b(&w, o->color);
        put_b(&w, o->layer & 15);
        put_b(&w, 0);
        put_s(&w, 0);
    }
    {                           /* the texts, and then what they say */
        int off = 0;

        for (i = 0; i < d->ndrawn; i++) {
            const jw_obj *o = &d->obj[i];
            int st;
            double dx, dy, len, far, x1, y1;

            if (o->cls != JW_MOJI || !jw_text_drawn(o))
                continue;
            st = style_of(d, o);
            dx = o->d[2] - o->d[0];
            dy = o->d[3] - o->d[1];
            far = sqrt(dx * dx + dy * dy);
            len = text_len(d, o, st);
            if (far > 1e-12) {
                x1 = o->d[0] + dx / far * len;
                y1 = o->d[1] + dy / far * len;
            } else {
                x1 = o->d[0] + len;
                y1 = o->d[1];
            }
            put_f(&w, (o->d[0] + hw) * unit);
            put_f(&w, (o->d[1] + hh) * unit);
            put_f(&w, (x1 + hw) * unit);
            put_f(&w, (y1 + hh) * unit);
            put_b(&w, off);
            put_b(&w, off >> 8);
            put_b(&w, off >> 16);
            put_b(&w, 0x40);
            put_b(&w, st);
            put_b(&w, o->layer & 15);
            put_b(&w, o->flags);
            put_b(&w, 0);
            off += (int)strlen(jw_str(d, o->text)) + 1;
        }
        for (i = 0; i < d->ndrawn; i++) {
            const jw_obj *o = &d->obj[i];
            const char *s;

            if (o->cls != JW_MOJI || !jw_text_drawn(o))
                continue;
            s = jw_str(d, o->text);
            put(&w, s, (long)strlen(s) + 1);
        }
    }
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (o->cls != JW_TEN)
            continue;
        put_f(&w, (o->d[0] + hw) * unit);
        put_f(&w, (o->d[1] + hh) * unit);
        put_b(&w, o->n);
        put_b(&w, o->color);
        put_s(&w, 0);
    }
    /* The names at the end are fields of a fixed width, not a run of
       strings: every layer of every group gets eight bytes, and then every
       group gets sixteen.  That is 2,304 bytes whatever the drawing. */
    {
        unsigned char tail[16 * 16 * 8 + 16 * 16];
        int g, l;

        memset(tail, 0, sizeof tail);
        for (g = 0; g < 16; g++)
            for (l = 0; l < 16; l++) {
                const char *s = jw_str(d, d->group[g].layer_name[l]);
                size_t k = strlen(s);

                if (k > 7)
                    k = 7;      /* eight bytes, and one of them a NUL */
                memcpy(tail + g * 128 + l * 8, s, k);
            }
        for (g = 0; g < 16; g++) {
            const char *s = jw_str(d, d->group[g].name);
            size_t k = strlen(s);

            if (k > 15)
                k = 15;
            memcpy(tail + 16 * 16 * 8 + g * 16, s, k);
        }
        put(&w, tail, (long)sizeof tail);
    }
    if (w.bad) {
        free(w.b);
        return 0;
    }
    *out = w.b;
    *n = w.n;
    return 1;
}
