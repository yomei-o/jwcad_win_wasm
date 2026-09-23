/* Write a drawing out as DXF, the way the original does.
 *
 * Jw_cad's DXF形式で保存 (32961) writes an AC1009 (R12) ASCII DXF with CRLF
 * line endings.  What is in it was read off the ones it wrote -- see
 * RESUME.md and tools/mkdxf.py:
 *
 *   HEADER    $ACADVER .. $LTSCALE, with the sheet and the scale in it
 *   TABLES    VPORT, then LTYPE and STYLE (the same bytes every time, so
 *             they are carried in src/gen/dxf.h), then LAYER, which is the
 *             drawing's own
 *   BLOCKS    empty
 *   ENTITIES  LINE, CIRCLE, ARC, POINT, TEXT, SOLID
 *
 * Coordinates are (the paper point + half the sheet) times the scale of the
 * layer group the element is on.  Every line of three drawings came out on
 * that rule with nothing left over.
 *
 * Numbers are written the shortest way that reads back the same -- the
 * original writes 56433.59268365219 with sixteen digits and
 * 31301.545376575129 with seventeen, which is neither %.16g nor %.17g.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "text.h"
#include "gen/dxf.h"

/* --- a growing buffer --------------------------------------------------- */

typedef struct {
    unsigned char *b;
    long n, cap;
    int bad;
} buf_t;

static void put(buf_t *o, const void *p, long n)
{
    if (o->bad)
        return;
    if (o->n + n > o->cap) {
        long c = o->cap ? o->cap * 2 : 65536;
        unsigned char *q;

        while (c < o->n + n)
            c *= 2;
        q = (unsigned char *)realloc(o->b, (size_t)c);
        if (!q) {
            o->bad = 1;
            return;
        }
        o->b = q;
        o->cap = c;
    }
    memcpy(o->b + o->n, p, (size_t)n);
    o->n += n;
}

static void puts_(buf_t *o, const char *s)
{
    put(o, s, (long)strlen(s));
}

/* --- the pieces of a DXF ------------------------------------------------ */

/* "%3d\r\n" -- every group code is written in three columns. */
static void code(buf_t *o, int c)
{
    char t[16];

    sprintf(t, "%3d\r\n", c);
    puts_(o, t);
}

static void str_(buf_t *o, int c, const char *v)
{
    code(o, c);
    puts_(o, v);
    puts_(o, "\r\n");
}

/* an integer value, in five columns: that is how 62 and 70..78 come out */
static void int5(buf_t *o, int c, int v)
{
    char t[24];

    code(o, c);
    sprintf(t, "%5d\r\n", v);
    puts_(o, t);
}

/* Seventeen significant digits, **cut off** rather than rounded, with the
 * trailing zeros taken off afterwards.  That is what the original does, and
 * it is not what %.17g does: the double behind 36433.5937382171468925 comes
 * out of printf as ...147 but the original writes ...146, and
 * 31301.5453765751299215 keeps all seventeen where printf would round it to
 * sixteen.  Cutting fits all three of those and everything else in four
 * drawings' worth of DXF.
 */
static void number(char *t, double v)
{
    char b[64];
    const char *p, *e;
    char *o = t;
    int sig = 0, seen = 0, dot = 0;

    sprintf(b, "%.20g", v);
    e = strpbrk(b, "eE");
    for (p = b; *p && p != e; p++) {
        if (*p == '-' || *p == '+') {
            *o++ = *p;
            continue;
        }
        if (*p == '.') {
            dot = 1;
            *o++ = '.';
            continue;
        }
        if (*p < '0' || *p > '9') {
            *o++ = *p;
            continue;
        }
        if (*p != '0')
            seen = 1;
        if (sig < 17) {
            *o++ = *p;
            if (seen)
                sig++;
        } else if (!dot) {
            *o++ = '0';         /* keep the size, lose the digit */
        } else {
            break;              /* the rest of the fraction goes */
        }
    }
    *o = 0;
    if (strchr(t, '.')) {       /* trailing zeros, and a bare point */
        o = t + strlen(t) - 1;
        while (o > t && *o == '0')
            *o-- = 0;
        if (*o == '.')
            *o = 0;
    }
    if (e)
        strcat(t, e);
}

static void real(buf_t *o, int c, double v)
{
    char t[48];

    code(o, c);
    number(t, v);
    puts_(o, t);
    puts_(o, "\r\n");
}

/* Radians to degrees, dividing before multiplying: the original's own order.
   The other way round is a bit out in the last place -- a text of Test5.jww
   comes to -100.00000067721585 this way and ...84 the other. */
static double deg(double rad)
{
    return rad / 3.14159265358979323846 * 180.0;
}

/* --- the drawing's own numbers ------------------------------------------ */

/* The scale of a layer group, as a number to multiply paper millimetres by:
   a 1/200 drawing has 200 here. */
static double group_scale(const jw_drawing *d, int g)
{
    double s = g >= 0 && g < 16 ? d->group[g].scale : 1.0;

    return s > 0.0 ? s : 1.0;
}

static int write_group(const jw_drawing *d)
{
    int g, wg = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    return wg;
}

/* --- entities ----------------------------------------------------------- */

/* line type 1..9 -> the name in the LTYPE table */
static const char *const LTYPE[9] = {
    "CONTINUOUS", "DASHED1", "DASHED2", "DASHED3", "CENTER1",
    "CENTER2", "PHANTOM1", "PHANTOM2", "DOT"
};

/* pen 1..9 -> the DXF colour number, read out of the original by drawing one
   line in each pen and asking it for a DXF (tools/mkpens.c) */
static const short COLOUR[9] = { 132, 18, 92, 52, 212, 5, 136, 230, 211 };

static const char *ltype_name(const jw_obj *o)
{
    int t = o->ltype % 100;

    return LTYPE[t >= 1 && t <= 9 ? t - 1 : 0];
}

/* Colour 10 is 「任意色」 and carries its own RGB in the trailing long.  The
 * original puts it on the nearest of AutoCAD's first nine colours: the 79
 * solids of Ａマンション平面例.jww are 0xc0c0c0 and came out as 9, which is
 * that palette's light grey exactly. */
static int colour_any(unsigned int rgb)
{
    static const unsigned int ACI[9] = {
        0xff0000, 0xffff00, 0x00ff00, 0x00ffff, 0x0000ff,
        0xff00ff, 0xffffff, 0x808080, 0xc0c0c0
    };
    int best = 7, i;
    long bd = 0;

    for (i = 0; i < 9; i++) {
        long dr = (long)((ACI[i] >> 16) & 0xff) - (long)((rgb >> 16) & 0xff);
        long dg = (long)((ACI[i] >> 8) & 0xff) - (long)((rgb >> 8) & 0xff);
        long db = (long)(ACI[i] & 0xff) - (long)(rgb & 0xff);
        long d = dr * dr + dg * dg + db * db;

        if (i == 0 || d < bd) {
            bd = d;
            best = i + 1;
        }
    }
    return best;
}

static int colour_of(const jw_obj *o)
{
    int c = o->color;

    if (c == 10) {
        unsigned int n = (unsigned int)o->n;

        /* the file keeps it as a COLORREF, 0x00bbggrr */
        return colour_any(((n & 0xff) << 16) | (n & 0xff00)
                          | ((n >> 16) & 0xff));
    }
    return COLOUR[c >= 1 && c <= 9 ? c - 1 : 1];
}

/* `_<group>-<layer>_<name>`, with the layer as one hex digit.
 *
 * A space in the name becomes an underscore, a full-width one too -- and
 * that is the only change: the original left the 中黒 of 「測定位置・表示枠」
 * and the 全角ハイフン of 「計画建物－天空率」 alone, while 「　屋 根」 came out
 * as `__屋_根`. */
static void layer_name(const jw_drawing *d, int g, int l, char *out, int n)
{
    const char *nm = jw_str(d, d->group[g].layer_name[l]);
    int k;

    k = sprintf(out, "_%x-%x_", g & 15, l & 15);
    if (!nm)
        return;
    while (*nm && k < n - 2) {
        unsigned char c = (unsigned char)nm[0];

        if (c == 0x81 && (unsigned char)nm[1] == 0x40) {
            out[k++] = '_';             /* the full-width space */
            nm += 2;
        } else if (c == ' ') {
            out[k++] = '_';
            nm++;
        } else if (jw_is_lead(c) && nm[1]) {
            out[k++] = nm[0];
            out[k++] = nm[1];
            nm += 2;
        } else {
            out[k++] = *nm++;
        }
    }
    out[k] = 0;
}

int jw_dxf_write(const jw_drawing *d, unsigned char **out, long *n)
{
    buf_t o;
    double hw, hh, sc;
    int i, g, l, wg, nlayer = 0;
    char name[128];
    char used[16][16];

    if (!d || !out || !n)
        return 0;
    memset(&o, 0, sizeof o);
    hw = d->paper_hw;
    hh = d->paper_hh;
    wg = write_group(d);
    sc = group_scale(d, wg);

    /* HEADER and VPORT, with the eight numbers of this drawing in them */
    {
        double v[8];

        v[0] = 2 * hw * sc;             /* $EXTMAX x */
        v[1] = 2 * hh * sc;             /* $EXTMAX y */
        v[2] = v[0];                    /* $LIMMAX   */
        v[3] = v[1];
        v[4] = sc;                      /* $LTSCALE  */
        v[5] = hw * sc;                 /* the viewport's centre */
        v[6] = hh * sc;
        v[7] = 2 * hh * sc;             /* and its height */
        for (i = 0; i < JW_DXF_NPRO; i++) {
            put(&o, jw_dxf_pro[i].b, jw_dxf_pro[i].n);
            if (i < 8) {
                char t[48];

                number(t, v[i]);
                puts_(&o, t);
                puts_(&o, "\r\n");
            }
        }
    }

    /* LTYPE and STYLE, the same in every drawing */
    put(&o, jw_dxf_tables, JW_DXF_NTABLES);

    /* LAYER: every group and layer that has something on it, and ADD_LINE */
    memset(used, 0, sizeof used);
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *e = &d->obj[i];

        if (e->lgroup < 16 && e->layer < 16 && !used[e->lgroup][e->layer]) {
            used[e->lgroup][e->layer] = 1;
            nlayer++;
        }
    }
    str_(&o, 0, "TABLE");
    str_(&o, 2, "LAYER");
    int5(&o, 70, nlayer + 1);
    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++) {
            if (!used[g][l])
                continue;
            layer_name(d, g, l, name, (int)sizeof name);
            str_(&o, 0, "LAYER");
            str_(&o, 2, name);
            int5(&o, 70, 64);
            int5(&o, 62, 7);
            str_(&o, 6, "CONTINUOUS");
        }
    str_(&o, 0, "LAYER");
    str_(&o, 2, "ADD_LINE");
    int5(&o, 70, 64);
    int5(&o, 62, 7);
    str_(&o, 6, "CONTINUOUS");
    str_(&o, 0, "ENDTAB");
    str_(&o, 0, "ENDSEC");

    /* BLOCKS: nothing in it */
    str_(&o, 0, "SECTION");
    str_(&o, 2, "BLOCKS");
    str_(&o, 0, "ENDSEC");

    /* ENTITIES */
    str_(&o, 0, "SECTION");
    str_(&o, 2, "ENTITIES");
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *e = &d->obj[i];
        double s = group_scale(d, e->lgroup);
        double x0, y0, x1, y1;

        /* a 補助線 goes on the layer the original keeps for them */
        if ((e->ltype % 100) == 9)
            strcpy(name, "ADD_LINE");
        else
            layer_name(d, e->lgroup & 15, e->layer & 15, name,
                       (int)sizeof name);
        x0 = (e->d[0] + hw) * s;
        y0 = (e->d[1] + hh) * s;
        x1 = (e->d[2] + hw) * s;
        y1 = (e->d[3] + hh) * s;
        switch (e->cls) {
        case JW_SEN:
            str_(&o, 0, "LINE");
            str_(&o, 8, name);
            str_(&o, 6, ltype_name(e));
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 11, x1);
            real(&o, 21, y1);
            break;
        case JW_ENKO: {
            double r = e->d[2] * s, a0 = e->d[3], sw = e->d[4];
            int full;

            if (e->d[6] != 1.0) {
                /* DXF R12 has no ellipse, so the original walks it in ten
                 * degree steps of the parameter and writes a line for each,
                 * with a short one at the end.  Read off the twelve of
                 * Ａマンション平面例.jww: every vertex sits at a0 + k * 10
                 * degrees. */
                double flat = e->d[6], tilt = e->d[5];
                double ct = cos(tilt), st = sin(tilt);
                double step = sw < 0.0 ? -10.0 : 10.0;
                double endt = deg(sw), px = 0, py = 0;
                int k;

                /* every ten degrees of the parameter, and then the end --
                   always, even when the last step landed on it, which is why
                   a whole turn finishes with a line that goes nowhere */
                for (k = 0; ; k++) {
                    double t = (double)k * step;
                    int last = (step > 0.0) ? t > endt : t < endt;
                    double a, ux, uy, qx, qy;

                    if (last)
                        t = endt;
                    a = a0 + t * 3.14159265358979323846 / 180.0;
                    ux = e->d[2] * cos(a);
                    uy = e->d[2] * flat * sin(a);
                    /* the centre is put on the sheet first and the ellipse's
                       own offsets are scaled on their own */
                    qx = (e->d[0] + hw) * s + (ux * ct - uy * st) * s;
                    qy = (e->d[1] + hh) * s + (ux * st + uy * ct) * s;
                    if (k == 0) {
                        px = qx; /* the first line is a point: the original
                                    starts with its pen already there */
                        py = qy;
                    }
                    str_(&o, 0, "LINE");
                    str_(&o, 8, name);
                    str_(&o, 6, ltype_name(e));
                    int5(&o, 62, colour_of(e));
                    real(&o, 10, px);
                    real(&o, 20, py);
                    real(&o, 11, qx);
                    real(&o, 21, qy);
                    px = qx;
                    py = qy;
                    if (last || k > 4000)
                        break;
                }
                break;
            }
            /* a whole turn is a CIRCLE, however the drawing writes it:
               some of them keep 2 pi in the sweep rather than nothing */
            full = sw == 0.0 || sw >= 6.283185 || sw <= -6.283185;
            str_(&o, 0, full ? "CIRCLE" : "ARC");
            str_(&o, 8, name);
            str_(&o, 6, ltype_name(e));
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 40, r);
            if (!full) {
                /* The tilt turns the whole arc; each part is turned into
                   degrees on its own, which is where the last digit of
                   184.58407592773437 comes from */
                double d0 = deg(a0) + deg(e->d[5]);
                double d1 = deg(a0) + deg(sw) + deg(e->d[5]);

                /* a DXF arc always runs anticlockwise, so a negative sweep
                   comes out the other way round and both ends are brought
                   into 0..360 -- the original wrote 270 and 0 where the
                   drawing has 0 and -90 */
                if (sw < 0.0) {
                    double t = d0;

                    d0 = d1;
                    d1 = t;
                }
                while (d0 < 0.0) d0 += 360.0;
                while (d0 >= 360.0) d0 -= 360.0;
                while (d1 < 0.0) d1 += 360.0;
                while (d1 >= 360.0) d1 -= 360.0;
                real(&o, 50, d0);
                real(&o, 51, d1);
            }
            break;
        }
        case JW_TEN:
            str_(&o, 0, "POINT");
            str_(&o, 8, name);
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            break;
        case JW_MOJI: {
            double dx = e->d[2] - e->d[0], dy = e->d[3] - e->d[1];
            double ang = deg(atan2(dy, dx));

            str_(&o, 0, "TEXT");
            str_(&o, 8, name);
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 40, e->d[5] * s);
            real(&o, 41, e->d[5] != 0.0 ? e->d[4] / e->d[5] : 1.0);
            real(&o, 50, ang);
            str_(&o, 1, jw_str(d, e->text));
            break;
        }
        case JW_SOLID:
            str_(&o, 0, "SOLID");
            str_(&o, 8, name);
            str_(&o, 6, ltype_name(e));
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 11, x1);
            real(&o, 21, y1);
            /* DXF wants the last two corners the other way round -- the
               bowtie order a SOLID is drawn in */
            real(&o, 12, (e->d[6] + hw) * s);
            real(&o, 22, (e->d[7] + hh) * s);
            real(&o, 13, (e->d[4] + hw) * s);
            real(&o, 23, (e->d[5] + hh) * s);
            break;
        default:
            break;
        }
    }
    str_(&o, 0, "ENDSEC");
    str_(&o, 0, "EOF");

    if (o.bad) {
        free(o.b);
        return 0;
    }
    *out = o.b;
    *n = o.n;
    return 1;
}
