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
 * The phase is not reproduced here: the original starts its pattern from
 * somewhere of its own and the first dash of every line came out a part
 * one.  The lengths are what matter on paper.
 */
static const char *dash_of(int type)
{
    switch (type) {
    case 2: return "[1.693 1.693] 0";
    case 3: return "[3.429 3.429] 0";
    case 4: return "[5.165 1.736] 0";
    case 5: return "[8.932 1.778 1.778 1.778] 0";
    case 6: return "[23.199 1.778 1.778 1.778] 0";
    case 7: return "[7.154 1.778 0.889 1.778 0.889 1.778] 0";
    case 8: return "[21.421 1.778 0.889 1.778 0.889 1.778] 0";
    default: return "[] 0";
    }
}

/* 補助線 is not printed: nine lines went to the printer and eight came
   back. */
static int prints(const jw_obj *o)
{
    return (o->ltype % 100) != 9;
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

static double px_(const Pdf *p, double x)
{
    return (x + p->hw) * p->mm2pt;
}

static double py_(const Pdf *p, double y)
{
    return (y + p->hh) * p->mm2pt;
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
    if (type != p->type) {
        buf_f(p->b, "%s d\n", dash_of(type));
        p->type = type;
    }
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
    case JW_SEN:
        state(p, pen, type_of(o));
        buf_f(p->b, "%.2f %.2f m %.2f %.2f l S\n",
              px_(p, o->d[0]), py_(p, o->d[1]),
              px_(p, o->d[2]), py_(p, o->d[3]));
        break;
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
        for (i = 0; i <= n; i++) {
            double t = a0 + sw * i / n;
            double ux = r * cos(t), uy = r * flat * sin(t);
            double x = cx + ux * ct - uy * st;
            double y = cy + ux * st + uy * ct;
            buf_f(p->b, "%.2f %.2f %s\n", px_(p, x), py_(p, y),
                  i ? "l" : "m");
        }
        buf_put(p->b, "S\n", -1);
        break;
    }
    case JW_TEN: {
        /* A 実点 wears a ring on screen and a 仮点 is one dot.  Neither is
           a millimetre of anything, so what goes on paper is a small cross
           -- the same thing jwcad_dos_wasm draws.  The original was not
           asked about this one. */
        const double a = 0.4;

        state(p, pen, 1);
        buf_f(p->b, "%.2f %.2f m %.2f %.2f l S\n",
              px_(p, o->d[0] - a), py_(p, o->d[1]),
              px_(p, o->d[0] + a), py_(p, o->d[1]));
        buf_f(p->b, "%.2f %.2f m %.2f %.2f l S\n",
              px_(p, o->d[0]), py_(p, o->d[1] - a),
              px_(p, o->d[0]), py_(p, o->d[1] + a));
        break;
    }
    case JW_SOLID: {
        /* four corners, and the fourth is the third again on a triangle */
        state(p, pen, 1);
        buf_f(p->b, "%.2f %.2f m %.2f %.2f l %.2f %.2f l %.2f %.2f l f\n",
              px_(p, o->d[0]), py_(p, o->d[1]),
              px_(p, o->d[2]), py_(p, o->d[3]),
              px_(p, o->d[6]), py_(p, o->d[7]),
              px_(p, o->d[4]), py_(p, o->d[5]));
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
    /* and 補助線 is not printed: the class is put out of draw.c's reach
       rather than the element taken out, so the block definitions past the
       drawn ones keep the places they are referred to by */
    own = (jw_obj *)malloc((size_t)(d->nobj > 0 ? d->nobj : 1) * sizeof *own);
    if (own) {
        memcpy(own, d->obj, (size_t)d->nobj * sizeof *own);
        for (i = 0; i < d->nobj; i++)
            if ((own[i].ltype % 100) == 9)
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
