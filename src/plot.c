/* jw_plot_* -- see src/plot.h for what the original was asked and what it
 * answered. */
#include "plot.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "fb.h"
#include "png.h"
#include "view.h"

#define PI 3.14159265358979323846

void jw_plot_paper(const jw_drawing *d, double *wide, double *tall)
{
    double hw = d && d->paper_hw > 0.0 ? d->paper_hw : 297.0;
    double hh = d && d->paper_hh > 0.0 ? d->paper_hh : 210.0;

    if (wide)
        *wide = hw * 2.0;
    if (tall)
        *tall = hh * 2.0;
}

/* A pen's printed width in millimetres: its print_width is in dots at 300
 * to the inch.  Measured off the original's own PDF -- print_width 2 came
 * out 0.640 units on a 96 dpi page, which is 0.1693 mm, and 2 * 25.4/300
 * is 0.1693 mm. */
static double pen_mm(const jw_drawing *d, int pen)
{
    int w = d && pen >= 1 && pen <= 9 ? d->print_width[pen] : 1;

    if (w < 1)
        w = 1;
    return w * 25.4 / 300.0;
}

/* And its colour.  The file keeps a COLORREF, 0x00bbggrr. */
static void pen_rgb(const jw_drawing *d, int pen, int colour,
                    double *r, double *g, double *b)
{
    unsigned c;

    if (!colour || !d) {
        *r = *g = *b = 0.0;
        return;
    }
    c = d->print_rgb[pen >= 1 && pen <= 9 ? pen : 2];
    *r = (c & 0xff) / 255.0;
    *g = ((c >> 8) & 0xff) / 255.0;
    *b = ((c >> 16) & 0xff) / 255.0;
}

/* The nine line types as a PDF dash array, in millimetres.
 *
 * Nothing on screen says what a dash is on paper: src/draw.c counts a line
 * type in **pixels** (jw_mm_per_bit is 0), so the print had to say.  Nine
 * lines, one of each type, went through the original's own printer
 * (tools/probe34.sh, tmp/mkdash.c) and came back **not** as a dash array
 * but as one `m ... l S` for every dash, which is just as good to measure.
 * These are the runs that came out, in millimetres, counted over the whole
 * two hundred of each line:
 *
 *   点線1    1.693 on   1.693 off
 *   点線2    3.429      3.429        (and 3.471 as often, either way of
 *                                     the same rounding)
 *   点線3    5.165      1.736
 *   一点鎖1  8.932      1.778   1.778 on   1.778 off
 *   一点鎖2 23.199      1.778   1.778      1.778
 *   二点鎖1  7.154      1.778   0.889      1.778   0.889   1.778
 *   二点鎖2 21.421      1.778   0.889      1.778   0.889   1.778
 *
 * and **補助線 (9) did not print at all** -- eight rows came back out of
 * the nine that went in, which is what a construction line is for.
 *
 * **And the phase: every one of them starts in the middle of a dash.**
 * The part dash each line began with was read off that same PDF and it
 * is half the full one every time, to the rounding the original works
 * to (its dash ends all land on multiples of a 600th of an inch):
 *
 *   type   first dash   half of         type   first dash   half of
 *   2      0.847 mm     1.693           6     11.600       23.199
 *   3      1.693        3.429           7      3.556        7.154
 *   4      2.582        5.165           8     10.710       21.421
 *   5      4.446        8.932
 *
 * which in PDF is a dash phase of half the first element.  The original
 * also ends every dashed line with a **zero length stroke at the far
 * end**, which with its own `1 J` round cap is a dot of the pen's width;
 * jw_plot_pdf writes that too, because a dash array alone would leave
 * the end bare whenever the line runs out in a gap.
 */
/* The runs of each line type, in millimetres, on and off in turn.  The
 * line starts half way through the first of them.  Nought for a solid
 * line and for 補助線, which is not printed at all. */
static int dash_mm(int type, double *out)
{
    static const double P2[] = { 1.693, 1.693 };
    static const double P3[] = { 3.429, 3.429 };
    static const double P4[] = { 5.165, 1.736 };
    static const double P5[] = { 8.932, 1.778, 1.778, 1.778 };
    static const double P6[] = { 23.199, 1.778, 1.778, 1.778 };
    static const double P7[] = { 7.154, 1.778, 0.889, 1.778, 0.889, 1.778 };
    static const double P8[] = { 21.421, 1.778, 0.889, 1.778, 0.889, 1.778 };
    const double *s;
    int n, i;

    switch (type) {
    case 2: s = P2; n = 2; break;
    case 3: s = P3; n = 2; break;
    case 4: s = P4; n = 2; break;
    case 5: s = P5; n = 4; break;
    case 6: s = P6; n = 4; break;
    case 7: s = P7; n = 6; break;
    case 8: s = P8; n = 6; break;
    default: return 0;
    }
    for (i = 0; i < n; i++)
        out[i] = s[i];
    return n;
}

/* The ninth of either is not printed.  Nine lines of one colour and nine
   line types went to the printer and eight came back (tools/probe34.sh);
   nine lines of one type and nine colours went and eight came back
   (tools/probe35.sh).  補助線 and 補助線色 are for working with, not for
   paper. */
static int prints(const jw_obj *o)
{
    return (o->ltype % 100) != 9 && o->color != 9;
}

/* ------------------------------------------------------------------ buf --
 * The PDF is built up in one of these.
 */
typedef struct {
    unsigned char *p;
    long n, cap;
} Buf;

static int buf_room(Buf *b, long more)
{
    unsigned char *q;

    if (b->n + more <= b->cap)
        return 1;
    while (b->cap < b->n + more)
        b->cap = b->cap ? b->cap * 2 : 8192;
    q = (unsigned char *)realloc(b->p, (size_t)b->cap);
    if (!q)
        return 0;
    b->p = q;
    return 1;
}

static void buf_put(Buf *b, const char *s, long n)
{
    if (n < 0)
        n = (long)strlen(s);
    if (!buf_room(b, n))
        return;
    memcpy(b->p + b->n, s, (size_t)n);
    b->n += n;
}

static void buf_f(Buf *b, const char *fmt, ...)
{
    char line[512];
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vsnprintf(line, sizeof line, fmt, ap);
    va_end(ap);
    if (n > 0)
        buf_put(b, line, n);
}

/* ------------------------------------------------------------------ pdf -- */

typedef struct {
    Buf *b;
    const jw_drawing *d;
    double mm2pt;
    double hw, hh;              /* half the sheet: the middle is the origin */
    int colour;
    int pen, type;              /* what the graphics state is set to */
} Pdf;

/* The printer's dot.  **Every number the original writes into a PDF is
 * a whole multiple of a six hundredth of an inch** -- all 948 of them
 * in decomp/res/print_dash.txt, the 60 in print_points.txt and the
 * four in print_small.txt, with not one off the grid.  So it rasterises
 * to its printer's 600 dots to the inch before it writes, and that is
 * why its dashes wobble by a dot: the same 線種 comes out 3.429 in one
 * place and 3.471 in the next. */
#define DOT_PT (72.0 / 600.0)

static double snap_(double v)
{
    return floor(v / DOT_PT + 0.5) * DOT_PT;
}

static double px_(const Pdf *p, double x)
{
    return snap_((x + p->hw) * p->mm2pt);
}

static double py_(const Pdf *p, double y)
{
    return snap_((y + p->hh) * p->mm2pt);
}

/* One run of a polyline, written the way the original writes it: **no
 * dash array**, an `m ... l S` for every dash, and every end on the
 * printer's dot.  A dash array cannot say what the original says,
 * because the snapping makes no two of its dashes quite the same
 * length.
 *
 * The points are in the drawing's millimetres.  The line starts half
 * way through the first run of the pattern -- all seven dashed types
 * began with exactly half a dash (RESUME, 刻みの位相)
 * -- and a dashed
 * line ends with a stroke of no length at its far end, which the `1 J`
 * round cap paints as a dot of the pen's width.  Each of the seven
 * rows the original printed carries exactly one of those. */
/* Where [0, len] of the segment from (x0,y0) along (dx,dy) is on the page,
 * give or take `m` millimetres: Liang-Barsky against the sheet, which runs
 * from -hw to hw and -hh to hh.  0 if none of it is. */
static int on_page(const Pdf *p, double x0, double y0, double dx, double dy,
                   double len, double m, double *t0, double *t1)
{
    double lo = 0.0, hi = len;
    double P[4], Q[4];
    int i;

    P[0] = -dx; Q[0] = x0 - (-p->hw - m);
    P[1] = dx;  Q[1] = (p->hw + m) - x0;
    P[2] = -dy; Q[2] = y0 - (-p->hh - m);
    P[3] = dy;  Q[3] = (p->hh + m) - y0;
    for (i = 0; i < 4; i++) {
        if (P[i] == 0.0) {
            if (Q[i] < 0.0)
                return 0;
        } else {
            double t = Q[i] / P[i];

            if (P[i] < 0.0) {
                if (t > lo)
                    lo = t;
            } else if (t < hi) {
                hi = t;
            }
        }
    }
    if (lo >= hi)
        return 0;
    *t0 = lo;
    *t1 = hi;
    return 1;
}

/* Move the pattern on by `dist` without drawing any of it.  `left` is what
 * is left of entry k, and `on` whether k is a dash.  Whole cycles are taken
 * off by arithmetic -- a cycle is the pattern once, or twice when it has an
 * odd number of entries, since only then are dash and gap back where they
 * were -- so the length of what is skipped costs nothing. */
static void dash_skip(const double *pat, int np, double dist,
                      int *k, double *left, int *on)
{
    double cycle = 0.0;
    int i;

    if (dist < *left) {
        *left -= dist;
        return;
    }
    dist -= *left;
    *k = (*k + 1) % np;
    *on = !*on;
    *left = pat[*k];
    for (i = 0; i < np; i++)
        cycle += pat[i];
    if (np % 2)
        cycle *= 2.0;
    if (cycle > 0.0 && dist > cycle)
        dist = fmod(dist, cycle);
    while (dist >= *left && *left > 0.0) {
        dist -= *left;
        *k = (*k + 1) % np;
        *on = !*on;
        *left = pat[*k];
    }
    *left -= dist;
}

static void stroke_run(Pdf *p, const double *mx, const double *my,
                       int n, int type)
{
    double pat[8], at, left;
    int np = dash_mm(type, pat), k = 0, i, on = 1, open = 0;

    if (n < 2)
        return;
    if (np <= 0) {              /* solid: one stroke the whole way */
        buf_f(p->b, "%.2f %.2f m", px_(p, mx[0]), py_(p, my[0]));
        for (i = 1; i < n; i++)
            buf_f(p->b, " %.2f %.2f l", px_(p, mx[i]), py_(p, my[i]));
        buf_put(p->b, " S\n", -1);
        return;
    }
    left = pat[0] / 2.0;
    for (i = 0; i + 1 < n; i++) {
        double x0 = mx[i], y0 = my[i];
        double dx = mx[i + 1] - x0, dy = my[i + 1] - y0;
        double len = sqrt(dx * dx + dy * dy), t0, t1;

        if (len < 1e-12)
            continue;
        dx /= len;
        dy /= len;
        /* Only the part on the sheet is walked dash by dash; the rest just
           moves the pattern on.  A dashed line a thousand kilometres long
           -- the drawing may hold coordinates up to 1e12 -- used to be
           written out a dash at a time, and the PDF never finished.  The
           10 mm to spare keeps the cut ends, and the pen's round caps,
           off the paper. */
        if (!on_page(p, x0, y0, dx, dy, len, 10.0, &t0, &t1)) {
            if (open) {
                buf_put(p->b, " S\n", -1);
                open = 0;
            }
            dash_skip(pat, np, len, &k, &left, &on);
            continue;
        }
        if (t0 > 0.0) {
            if (open) {
                buf_put(p->b, " S\n", -1);
                open = 0;
            }
            dash_skip(pat, np, t0, &k, &left, &on);
        }
        at = t0;
        while (at < t1) {
            double step = t1 - at < left ? t1 - at : left;

            if (on) {
                if (!open) {
                    buf_f(p->b, "%.2f %.2f m ",
                          px_(p, x0 + dx * at), py_(p, y0 + dy * at));
                    open = 1;
                }
                buf_f(p->b, "%.2f %.2f l",
                      px_(p, x0 + dx * (at + step)),
                      py_(p, y0 + dy * (at + step)));
            }
            at += step;
            left -= step;
            if (left <= 1e-12) {
                if (on && open) {
                    buf_put(p->b, " S\n", -1);
                    open = 0;
                }
                k = (k + 1) % np;
                left = pat[k];
                on = !on;
            }
        }
        if (t1 < len) {
            if (open) {
                buf_put(p->b, " S\n", -1);
                open = 0;
            }
            dash_skip(pat, np, len - t1, &k, &left, &on);
        }
    }
    if (open)
        buf_put(p->b, " S\n", -1);
    /* and the dot at the far end */
    buf_f(p->b, "%.2f %.2f m %.2f %.2f l S\n",
          px_(p, mx[n - 1]), py_(p, my[n - 1]),
          px_(p, mx[n - 1]), py_(p, my[n - 1]));
}

static void state(Pdf *p, int pen, int type)
{
    if (pen != p->pen) {
        double r, g, b;

        pen_rgb(p->d, pen, p->colour, &r, &g, &b);
        buf_f(p->b, "%.3f %.3f %.3f RG\n%.3f %.3f %.3f rg\n%.3f w\n",
              r, g, b, r, g, b, pen_mm(p->d, pen) * p->mm2pt);
        p->pen = pen;
    }
    /* no dash array: stroke_run writes every dash itself */
    p->type = type;
}

static int type_of(const jw_obj *o)
{
    int t = o->ltype % 100;

    return t >= 1 && t <= 9 ? t : 1;
}

static void pdf_obj(Pdf *p, const jw_obj *o, int depth);

/* the members of a definition, carried by a reference to it */
static void pdf_block(Pdf *p, const jw_obj *ref, int depth)
{
    const jw_drawing *d = p->d;
    int i, at = -1;

    if (depth > 8)
        return;
    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] == ref->block) {
            at = i;
            break;
        }
    if (at < 0)
        return;
    for (i = at + 1; i < d->nobj && i <= at + d->obj[at].n; i++) {
        jw_obj o = d->obj[i];

        if (o.cls == JW_LIST)
            break;
        if (o.cls == JW_BLOCK) {
            o.d[0] = o.d[0] * ref->d[2] + ref->d[0];
            o.d[1] = o.d[1] * ref->d[3] + ref->d[1];
            o.d[2] *= ref->d[2];
            o.d[3] *= ref->d[3];
            o.d[4] += ref->d[4];
            pdf_block(p, &o, depth + 1);
            continue;
        }
        jw_obj_xform(&o, 0.0, 0.0, ref->d[2], ref->d[4],
                     ref->d[0], ref->d[1]);
        pdf_obj(p, &o, depth);
    }
}

static void pdf_obj(Pdf *p, const jw_obj *o, int depth)
{
    const int pen = o->color >= 1 && o->color <= 9 ? o->color : 2;

    switch (o->cls) {
    case JW_SEN: {
        double mx[2], my[2];

        state(p, pen, type_of(o));
        mx[0] = o->d[0];
        my[0] = o->d[1];
        mx[1] = o->d[2];
        my[1] = o->d[3];
        stroke_run(p, mx, my, 2, type_of(o));
        break;
    }
    case JW_ENKO: {
        /* the same parametrisation src/draw.c walks: centre, radius, the
           angle it starts at, how far it sweeps, the tilt of the long axis
           and how flat it is */
        double cx = o->d[0], cy = o->d[1], r = o->d[2];
        double a0 = o->d[3], sw = o->d[4], tilt = o->d[5], flat = o->d[6];
        double ct, st;
        int i, n;

        if (r <= 0.0)
            break;
        if (flat <= 0.0)
            flat = 1.0;
        if (sw == 0.0)
            sw = 2.0 * PI;
        ct = cos(tilt);
        st = sin(tilt);
        /* one chord every two degrees, and never fewer than eight */
        n = (int)(fabs(sw) / (2.0 * PI / 180.0)) + 1;
        if (n < 8)
            n = 8;
        if (n > 720)
            n = 720;
        state(p, pen, type_of(o));
        {
            double *mx = (double *)malloc((size_t)(n + 1) * 2
                                          * sizeof(double));

            if (!mx)
                break;
            for (i = 0; i <= n; i++) {
                double t = a0 + sw * i / n;
                double ux = r * cos(t), uy = r * flat * sin(t);

                mx[i] = cx + ux * ct - uy * st;
                mx[n + 1 + i] = cy + ux * st + uy * ct;
            }
            stroke_run(p, mx, mx + n + 1, n + 1, type_of(o));
            free(mx);
        }
        break;
    }
    case JW_TEN: {
        /* A dot, and a small one.  The original was asked
           (tools/probe35.sh put a point with a 1 in its trailing long
           and one with a 0 on a sheet and printed it): **only the one
           with the 0 came out**, as five short strokes 0.132 mm wide a
           twenty-fourth of a millimetre apart, the middle three 0.212
           long and the outer two 0.127 -- a filled dot a third of a
           millimetre across.  These are those five, in millimetres from
           the point. */
        static const double ROW[5][2] = {
            { -0.0847, 0.0635 }, { -0.0423, 0.1058 }, { 0.0, 0.1058 },
            {  0.0423, 0.1058 }, { 0.0847, 0.0635 }
        };
        double r, g, b;
        int k;

        if (o->n != 0)
            break;                      /* the other kind does not print */
        pen_rgb(p->d, pen, p->colour, &r, &g, &b);
        buf_f(p->b, "q %.3f %.3f %.3f RG %.3f w [] 0 d\n", r, g, b,
              0.1323 * p->mm2pt);
        for (k = 0; k < 5; k++)
            buf_f(p->b, "%.2f %.2f m %.2f %.2f l S\n",
                  px_(p, o->d[0] - ROW[k][1]), py_(p, o->d[1] + ROW[k][0]),
                  px_(p, o->d[0] + ROW[k][1]), py_(p, o->d[1] + ROW[k][0]));
        buf_put(p->b, "Q\n", -1);
        p->pen = -1;
        p->type = -1;
        break;
    }
    case JW_SOLID: {
        /* Four corners in the order they are stored, closed, and then
           **filled and stroked** -- the original wrote `h B*` for one,
           with the pen's own width (tools/probe35.sh).  A triangle has
           its fourth corner on top of its third. */
        state(p, pen, 1);
        buf_f(p->b,
              "%.2f %.2f m %.2f %.2f l %.2f %.2f l %.2f %.2f l h B*\n",
              px_(p, o->d[0]), py_(p, o->d[1]),
              px_(p, o->d[2]), py_(p, o->d[3]),
              px_(p, o->d[4]), py_(p, o->d[5]),
              px_(p, o->d[6]), py_(p, o->d[7]));
        break;
    }
    case JW_MOJI: {
        /* The cell, not just the size: a text carries its character
           width (d[4]), height (d[5]) and spacing (d[6]), and Jw_cad
           lays a full-width character out d[4] wide whatever the font
           thinks.  A CJK font's full-width glyph is one em, so the size
           is the height and the horizontal scale is width over height;
           the spacing goes in as Tc, which PDF scales the same way, so
           it is divided by that scale first. */
        const char *s = jw_str((jw_drawing *)p->d, o->text);
        double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
        double dir = (dx != 0.0 || dy != 0.0) ? atan2(dy, dx) : 0.0;
        double h = o->d[5] > 0.0 ? o->d[5] : 3.0;
        double cw = o->d[4] > 0.0 ? o->d[4] : h;
        double sp = o->d[6];
        double th = cw / h;
        double r, g, b;
        int i;

        if (!s || !*s)
            break;
        pen_rgb(p->d, pen, p->colour, &r, &g, &b);
        buf_f(p->b, "q %.3f %.3f %.3f rg BT /F1 %.2f Tf %.2f Tz %.3f Tc\n",
              r, g, b, h * p->mm2pt, th * 100.0,
              th > 0.0 ? sp / th * p->mm2pt : 0.0);
        buf_f(p->b, "%.4f %.4f %.4f %.4f %.2f %.2f Tm\n",
              cos(dir), sin(dir), -sin(dir), cos(dir),
              px_(p, o->d[0]), py_(p, o->d[1]));
        buf_put(p->b, "<", -1);
        for (i = 0; s[i]; i++)
            buf_f(p->b, "%02X", (unsigned char)s[i]);
        buf_put(p->b, "> Tj ET Q\n", -1);
        p->pen = -1;                    /* the q/Q put the state back */
        p->type = -1;
        break;
    }
    case JW_BLOCK:
        pdf_block(p, o, depth + 1);
        break;
    default:
        break;
    }
}

/* Whether an element is shown at all: the same three-way answer src/draw.c
   works out, folded to shown or not. */
static int shown_(const jw_drawing *d, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15;

    if (d->group[g].state == 0 || d->group[g].layer[l].state == 0)
        return 0;
    return 1;
}

unsigned char *jw_plot_pdf(const jw_drawing *d, int colour, long *len)
{
    Buf out, body;
    Pdf p;
    double wide, tall;
    long off[9], i, xref;
    char head[320];

    if (!d || !len)
        return 0;
    memset(&out, 0, sizeof out);
    memset(&body, 0, sizeof body);
    jw_plot_paper(d, &wide, &tall);

    p.b = &body;
    p.d = d;
    p.mm2pt = 72.0 / 25.4;
    p.hw = wide / 2.0;
    p.hh = tall / 2.0;
    p.colour = colour;
    p.pen = -1;
    p.type = -1;
    /* 1 J 1 j -- round caps and round joins, which is what the original's
       own PDF asks for */
    buf_put(&body, "1 J\n1 j\n", -1);
    for (i = 0; i < d->ndrawn; i++)
        if (shown_(d, &d->obj[i]) && prints(&d->obj[i]))
            pdf_obj(&p, &d->obj[i], 0);

    buf_put(&out, "%PDF-1.4\n", -1);
    off[1] = out.n;
    buf_put(&out, "1 0 obj<</Type/Catalog/Pages 2 0 R>>endobj\n", -1);
    off[2] = out.n;
    buf_put(&out, "2 0 obj<</Type/Pages/Kids[3 0 R]/Count 1>>endobj\n", -1);
    off[3] = out.n;
    sprintf(head, "3 0 obj<</Type/Page/Parent 2 0 R/MediaBox[0 0 %.2f %.2f]"
            "/Resources<</Font<</F1 5 0 R>>>>/Contents 4 0 R>>endobj\n",
            wide * p.mm2pt, tall * p.mm2pt);
    buf_put(&out, head, -1);
    off[4] = out.n;
    sprintf(head, "4 0 obj<</Length %ld>>stream\n", body.n);
    buf_put(&out, head, -1);
    buf_put(&out, (const char *)body.p, body.n);
    buf_put(&out, "endstream endobj\n", -1);
    off[5] = out.n;
    /* A CID font with one of PDF's own CJK encodings: CP932 goes in as it
       stands and nothing has to be embedded. */
    buf_put(&out, "5 0 obj<</Type/Font/Subtype/Type0/BaseFont/Ryumin-Light"
            "/Encoding/90ms-RKSJ-H/DescendantFonts[6 0 R]>>endobj\n", -1);
    off[6] = out.n;
    buf_put(&out, "6 0 obj<</Type/Font/Subtype/CIDFontType0"
            "/BaseFont/Ryumin-Light"
            "/CIDSystemInfo<</Registry(Adobe)/Ordering(Japan1)/Supplement 2>>"
            "/FontDescriptor 7 0 R/DW 1000>>endobj\n", -1);
    off[7] = out.n;
    buf_put(&out, "7 0 obj<</Type/FontDescriptor/FontName/Ryumin-Light"
            "/Flags 6/FontBBox[-170 -331 1024 903]/ItalicAngle 0"
            "/Ascent 903/Descent -331/CapHeight 709/StemV 69>>endobj\n", -1);

    xref = out.n;
    buf_put(&out, "xref\n0 8\n0000000000 65535 f \n", -1);
    for (i = 1; i <= 7; i++) {
        sprintf(head, "%010ld 00000 n \n", off[i]);
        buf_put(&out, head, -1);
    }
    sprintf(head, "trailer<</Size 8/Root 1 0 R>>\nstartxref\n%ld\n%%%%EOF\n",
            xref);
    buf_put(&out, head, -1);
    free(body.p);
    *len = out.n;
    return out.p;
}

/* ------------------------------------------------------------------ png --
 * Through the port's own src/draw.c, so the picture is the screen's: the
 * same arcs, the same dashes, the same glyphs.  What changes is the paper
 * (white, not the screen's ground), the pens (the drawing's printing ones)
 * and the widths (print_width, turned into pixels).
 */
unsigned char *jw_plot_png(const jw_drawing *d, double dpmm, int colour,
                           long *len)
{
    jw_drawing paper;
    jw_view v;
    rect_t r;
    fb_t fb;
    double wide, tall;
    unsigned char *rgb, *png;
    jw_obj *own = 0;
    double was_bit;
    long i, n;
    int w, h, k;

    if (!d || !len || dpmm <= 0.0)
        return 0;
    jw_plot_paper(d, &wide, &tall);
    w = (int)(wide * dpmm + 0.5);
    h = (int)(tall * dpmm + 0.5);
    if (w < 1 || h < 1 || (double)w * h > 64e6)
        return 0;
    if (!fb_init(&fb, w, h))
        return 0;

    r.x = 0;
    r.y = 0;
    r.w = w;
    r.h = h;
    /* the sheet, one to one at dpmm pixels to the millimetre, its middle
       in the middle of the page -- which is where the original puts it */
    v.scale = dpmm;
    v.mmpp = 1.0 / dpmm;
    v.ox = 0.0;
    v.oy = 0.0;
    v.bx = w / 2;
    v.by = h / 2;
    v.clip = r;

    paper = *d;
    /* one bit of a line type's pattern, in millimetres of paper.  On
       screen a bit is one pixel; on paper the original's 点線1 came out
       1.693 on and 1.693 off over four bits, which is ten dots of a 300
       dpi printer to the bit.  The other types' pitches are a little
       different from each other -- see dash_of -- so this is the one that
       fits 点線1 exactly and the rest closely. */
    was_bit = jw_mm_per_bit;
    jw_mm_per_bit = 10.0 * 25.4 / 300.0;
    for (k = 0; k < 10; k++) {
        unsigned c = d->print_rgb[k];
        int px = (int)(pen_mm(d, k) * dpmm + 0.5);

        paper.pen_rgb[k] = colour
            ? (((c & 0xff) << 16) | (c & 0xff00) | ((c >> 16) & 0xff))
            : 0x000000u;
        paper.pen_width[k] = px < 1 ? 1 : px;
    }
    /* the grid is a screen thing, not a printed one */
    paper.mesh_ix = paper.mesh_iy = 0.0;
    /* and what does not print -- 補助線, 補助線色, and the kind of point
       whose trailing long is not 0 -- is put out of draw.c's reach rather
       than taken out, so the block definitions past the drawn ones keep
       the places they are referred to by */
    own = (jw_obj *)malloc((size_t)(d->nobj > 0 ? d->nobj : 1) * sizeof *own);
    if (own) {
        memcpy(own, d->obj, (size_t)d->nobj * sizeof *own);
        for (i = 0; i < d->nobj; i++)
            if (!prints(&own[i]) || (own[i].cls == JW_TEN && own[i].n != 0))
                own[i].cls = JW_NCLASS;
        paper.obj = own;
    }
    fb_fill(&fb, 0, 0, w, h, 0xffffffu);
    jw_draw(&fb, &v, &paper);
    jw_mm_per_bit = was_bit;
    free(own);

    n = (long)w * h;
    rgb = (unsigned char *)malloc((size_t)n * 3);
    if (!rgb) {
        fb_free(&fb);
        return 0;
    }
    for (i = 0; i < n; i++) {
        unsigned int c = fb.px[i];
        rgb[i * 3] = (unsigned char)(c >> 16);
        rgb[i * 3 + 1] = (unsigned char)(c >> 8);
        rgb[i * 3 + 2] = (unsigned char)c;
    }
    fb_free(&fb);
    png = png_encode(rgb, w, h, len);
    free(rgb);
    return png;
}
