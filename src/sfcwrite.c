/* Writing an SFC -- 「SFC形式で保存」 (menu 32976).
 *
 * The original does not write these itself: orig/common_lib.dll does, and
 * the original only hands it numbers.  So what this follows is the shape of
 * the files it produces, which RESUME.md sets out.  The three things that
 * took the longest to see:
 *
 *   * A feature's number is its place in SXF's own list, not the order the
 *     file happens to write them in.  Colours are numbered black 1, red 2,
 *     green 3 ... and line types continuous 1, dashed 2 ... whatever order
 *     they come out in.
 *   * A 線色 is matched by its *printing* colour, and a 線幅 by its width in
 *     screen dots turned into millimetres (dots * 25.4/300) and then held
 *     against the nine SXF knows, within a tenth-and-a-half.  Anything that
 *     does not match gets an entry of its own, colours from 17 and widths
 *     from 11 -- 10 and 16 are never used.
 *   * Every layer group is a 図形 of its own, drawn at 1/its scale, and the
 *     elements of a group come before the sfig_org_feature that closes it.
 *
 * Solids are not written yet: the original turns one into a composite curve
 * and a fill, and those are a piece of their own.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

#define PI 3.14159265358979323846

/* The sixteen colours SXF names, in the order the original writes them --
   which is not the order they are numbered in, so each carries its number. */
static const struct { const char *name; int num; } COLOUR[16] = {
    { "red", 2 },        { "deeppink", 9 },  { "green", 3 },
    { "black", 1 },      { "blue", 4 },      { "yellow", 5 },
    { "magenta", 6 },    { "cyan", 7 },      { "white", 8 },
    { "brown", 10 },     { "orange", 11 },   { "lightgreen", 12 },
    { "lightblue", 13 }, { "lavender", 14 }, { "lightgray", 15 },
    { "darkgray", 16 }
};

/* and the fifteen line types, the same way */
static const struct { const char *name; int num; } FONT[15] = {
    { "long dashed double-dotted", 5 },
    { "continuous", 1 },
    { "double-dashed double-dotted", 13 },
    { "dashed", 2 },
    { "dashed spaced", 3 },
    { "long dashed dotted", 4 },
    { "long dashed triplicate-dotted", 6 },
    { "dotted", 7 },
    { "chain", 8 },
    { "chain double dash", 9 },
    { "dashed dotted", 10 },
    { "double-dashed dotted", 11 },
    { "dashed double-dotted", 12 },
    { "dashed triplicate-dotted", 14 },
    { "double-dashed triplicate-dotted", 15 }
};

/* the nine widths SXF knows, in millimetres */
static const double WIDTH[9] = {
    0.13, 0.18, 0.25, 0.35, 0.5, 0.7, 1.0, 1.4, 2.0
};

/* how far a width may be off one of those and still count as it, in per
   cent: the 一致率 of 基本設定, which the registry keeps as
   PenWidthTolerance */
#define WIDTH_TOL 15.0

/* 線種 1 to 8 are these SXF line types.  The registry keeps it as
   HKCU\Software\Jw_cad\jw_win\SXF\WriteLType; this is its default. */
static const int WRITE_LTYPE[8] = { 1, 7, 3, 2, 10, 8, 12, 9 };

/* 線色 9 -- 補助線 -- does not use its printing colour.  It comes out as a
   colour of its own, which is the 補助線 colour of 基本設定. */
#define AUX_R 240
#define AUX_G 180
#define AUX_B 180

typedef struct {
    unsigned char *b;
    long n, cap;
    int bad;
    int num;                    /* the number the next feature gets */
} sbuf;

static void put(sbuf *w, const char *s, long n)
{
    if (w->bad)
        return;
    if (w->n + n > w->cap) {
        long c = w->cap ? w->cap * 2 : 65536;
        unsigned char *q;

        while (c < w->n + n)
            c *= 2;
        q = (unsigned char *)realloc(w->b, (size_t)c);
        if (!q) {
            w->bad = 1;
            return;
        }
        w->b = q;
        w->cap = c;
    }
    memcpy(w->b + w->n, s, (size_t)n);
    w->n += n;
}

static void puts_(sbuf *w, const char *s)
{
    put(w, s, (long)strlen(s));
}

/* One feature, in the comment the format wraps them in. */
static void feature(sbuf *w, const char *body)
{
    char head[32];

    /* an empty line goes before each one rather than after, so that the
       last is followed straight by ENDSEC */
    sprintf(head, "\r\n/*SXF\r\n#%d = ", w->num);
    puts_(w, head);
    puts_(w, body);
    puts_(w, "\r\nSXF*/\r\n");
    w->num += 10;
}

/* The same number as the original would have: an angle goes through a
   32-bit float on its way out, which is why 150 degrees comes back as
   149.999984741211 and not 150. */
static double f32(double v)
{
    float f = (float)v;

    return (double)f;
}

/* A number in the sixteen characters the format uses for an angle: as many
   places after the point as leave room for what is in front of it. */
static void ang(char *t, double v)
{
    int whole = (int)fabs(v), digits = 1, p;

    while (whole >= 10) {
        whole /= 10;
        digits++;
    }
    p = 15 - digits;
    if (p < 0)
        p = 0;
    /* sixteen characters whatever the number is: digits + '.' + places */
    sprintf(t, "%.*f", p, v);
}

/* ------------------------------------------------------- what is in use */

#define MAXCOL 64
#define MAXWID 64
#define MAXLAY 256

typedef struct {
    const jw_drawing *d;
    sbuf w;

    /* the colour and width each 線色 comes out as, worked out once */
    int colour[11];
    int width[11];
    unsigned int ucol[MAXCOL];  /* the colours of our own, in order */
    int nucol;
    double uwid[MAXWID];        /* and the widths */
    int nuwid;
    int font9;                  /* the number 線種 9 got, 0 if unused */

    /* every (group, layer) that carries something, numbered from one */
    struct { int g, l; } lay[MAXLAY];
    int nlay;
    int auxlay;                 /* the 補助線 layer, numbered the same way */
} sfcw;

/* Which SXF colour a COLORREF is, or 0. */
static int colour_num(unsigned int rgb, const jw_drawing *d)
{
    int i;

    for (i = 1; i <= 16; i++)
        if (d->xcolor[i] == rgb)
            return i;
    return 0;
}

/* Which SXF width a length in millimetres is, or 0. */
static int width_num(double mm)
{
    int i, best = 0;
    double bd = 1e9;

    for (i = 0; i < 9; i++) {
        double e = fabs(mm - WIDTH[i]) / WIDTH[i] * 100.0;

        if (e < bd) {
            bd = e;
            best = i + 1;
        }
    }
    return bd <= WIDTH_TOL ? best : 0;
}

/* The number this 線色 comes out as, making an entry of our own if it has
   to.  線色 9 is the 補助線 one and never matches. */
static int want_colour(sfcw *s, int pen)
{
    unsigned int rgb;
    int i, num;

    if (pen < 1 || pen > 10)
        pen = 1;
    if (s->colour[pen])
        return s->colour[pen];
    if (pen == 9) {
        rgb = ((unsigned)AUX_B << 16) | ((unsigned)AUX_G << 8) | AUX_R;
        num = 0;
    } else {
        /* the session's tables hold pen 10, the drawing's print tables only
           0..9 -- the same range coord.c's pen_w() guards */
        rgb = pen < 10 ? s->d->print_rgb[pen] : 0;
        num = colour_num(rgb, s->d);
    }
    if (!num) {
        for (i = 0; i < s->nucol; i++)
            if (s->ucol[i] == rgb)
                break;
        if (i == s->nucol && s->nucol < MAXCOL)
            s->ucol[s->nucol++] = rgb;
        num = 17 + i;
    }
    s->colour[pen] = num;
    return num;
}

static int want_width(sfcw *s, int pen)
{
    double mm;
    int i, num;

    if (pen < 1 || pen > 10)
        pen = 1;
    if (s->width[pen])
        return s->width[pen];
    /* the printing pen's width is in screen dots, and one dot is a three
       hundredth of an inch */
    mm = (pen < 10 ? (double)s->d->print_width[pen] : 0.0) * 25.4 / 300.0;
    num = width_num(mm);
    if (!num) {
        for (i = 0; i < s->nuwid; i++)
            if (fabs(s->uwid[i] - mm) < 1e-9)
                break;
        if (i == s->nuwid && s->nuwid < MAXWID)
            s->uwid[s->nuwid++] = mm;
        num = 11 + i;
    }
    s->width[pen] = num;
    return num;
}

/* The number this line type comes out as. */
static int want_font(sfcw *s, int lt)
{
    if (lt >= 1 && lt <= 8)
        return WRITE_LTYPE[lt - 1];
    if (lt == 9) {
        s->font9 = 17;
        return 17;
    }
    return 1;
}

/* A solid's curves are wrapped in a composite curve, and after the group's
 * elements comes one fill_area_style_colour_feature for each of them saying
 * it is filled -- which is the only thing that tells an SXF reader the
 * outline is not just an outline.  This writes the composite and remembers
 * what the fill will need.
 */
static void solid_end(sfcw *s, int *nfill, int *fill, int lay, int col,
                      int fon, int wid)
{
    char t[128];

    snprintf(t, sizeof t, "composite_curve_org_feature('%d','%d','%d','1')",
            col, fon, wid);
    feature(&s->w, t);
    fill[*nfill * 2] = lay;
    fill[*nfill * 2 + 1] = col;
    (*nfill)++;
}

/* Which of the layers in use this element is on, numbered from one. */
static int want_layer(sfcw *s, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15, i;

    if (o->color == 9 || o->ltype == 9)
        return s->auxlay;
    for (i = 0; i < s->nlay; i++)
        if (s->lay[i].g == g && s->lay[i].l == l)
            return i + 1;
    return 1;
}

int jw_sfc_write(const jw_drawing *d, const char *name, const char *stamp,
                 unsigned char **out, long *n)
{
    sfcw *s = (sfcw *)calloc(1, sizeof *s);
    char t[1024], a[32], b[32], c[32];
    int *fill;                  /* the layer and colour of each solid */
    int i, g;

    *out = 0;
    *n = 0;
    if (!s)
        return 0;
    s->d = d;
    s->w.num = 10;

    /* which layers carry something, in group and layer order */
    for (g = 0; g < 16; g++) {
        int l;

        for (l = 0; l < 16; l++) {
            int k;

            for (k = 0; k < d->ndrawn; k++)
                if ((d->obj[k].lgroup & 15) == g && (d->obj[k].layer & 15) == l
                    && d->obj[k].color != 9 && d->obj[k].ltype != 9
                    && jw_text_drawn(&d->obj[k]))
                    break;
            if (k < d->ndrawn && s->nlay < MAXLAY) {
                s->lay[s->nlay].g = g;
                s->lay[s->nlay].l = l;
                s->nlay++;
            }
        }
    }
    s->auxlay = s->nlay + 1;

    /* what the elements ask for, so the tables can be written first */
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (o->cls == JW_LIST || o->cls == JW_BLOCK || !jw_text_drawn(o))
            continue;
        want_colour(s, o->color);
        want_font(s, o->ltype);
        if (o->cls != JW_TEN && o->cls != JW_MOJI)
            want_width(s, o->color);
    }

    /* ------------------------------------------------------- the header */
    snprintf(t, sizeof t, "ISO-10303-21;\r\nHEADER;\r\n"
               "FILE_DESCRIPTION(('SCADEC level2 feature_mode'),\r\n"
               "        '2;1');\r\nFILE_NAME('%s',\r\n        '%s',\r\n"
               "        (''),\r\n        (''),\r\n"
               "        'SCADEC_API_Ver3.30',\r\n        'Jw_cad',\r\n"
               "        '');\r\nFILE_SCHEMA(('ASSOCIATIVE_DRAUGHTING'));\r\n"
               "ENDSEC;\r\nDATA;\r\n", name, stamp);
    puts_(&s->w, t);

    /* ------------------------------------------------------- the tables */
    for (i = 0; i < 16; i++) {
        snprintf(t, sizeof t, "pre_defined_colour_feature(\\'%s\\')", COLOUR[i].name);
        feature(&s->w, t);
    }
    for (i = 0; i < s->nucol; i++) {
        unsigned int v = s->ucol[i];

        snprintf(t, sizeof t, "user_defined_colour_feature('%u','%u','%u')",
                v & 0xff, (v >> 8) & 0xff, (v >> 16) & 0xff);
        feature(&s->w, t);
    }
    for (i = 0; i < 15; i++) {
        snprintf(t, sizeof t, "pre_defined_font_feature(\\'%s\\')", FONT[i].name);
        feature(&s->w, t);
    }
    if (s->font9) {
        /* 線種 9, the one the original calls dot9 */
        snprintf(t, sizeof t, "user_defined_font_feature(\\'dot9\\','4',"
                   "'(0.124000,0.876000,0.124000,0.876000)')");
        feature(&s->w, t);
    }
    for (i = 0; i < 9; i++) {
        snprintf(t, sizeof t, "width_feature('%.6f')", WIDTH[i]);
        feature(&s->w, t);
    }
    for (i = 0; i < s->nuwid; i++) {
        snprintf(t, sizeof t, "width_feature('%.6f')", s->uwid[i]);
        feature(&s->w, t);
    }
    {   /* a text names a font, so there has to be one if there are texts */
        int face = -1;

        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_MOJI && d->obj[i].face >= 0
                && jw_text_drawn(&d->obj[i])) {
                face = d->obj[i].face;
                break;
            }
        if (face >= 0) {
            snprintf(t, sizeof t, "text_font_feature(\\'%s\\')", jw_str(d, face));
            feature(&s->w, t);
        }
    }

    /* ----------------------------------------------------- the elements */
    fill = (int *)malloc((size_t)(d->ndrawn + 1) * 2 * sizeof *fill);
    if (!fill) {
        free(s);
        return 0;
    }
    for (g = 0; g < 16; g++) {
        double sc = d->group[g].scale > 0.0 ? d->group[g].scale : 1.0;
        int any = 0, nfill = 0;

        for (i = 0; i < d->ndrawn; i++) {
            const jw_obj *o = &d->obj[i];
            double hw = d->paper_hw, hh = d->paper_hh;
            int lay, col, fon, wid;

            if ((o->lgroup & 15) != g || o->cls == JW_LIST
                || o->cls == JW_BLOCK)
                continue;
            if (!jw_text_drawn(o))
                continue;       /* a text with no length is not written */
            any = 1;
            lay = want_layer(s, o);
            col = want_colour(s, o->color);
            fon = want_font(s, o->ltype);
            wid = want_width(s, o->color);
            switch (o->cls) {
            case JW_SEN:
                snprintf(t, sizeof t, "line_feature('%d','%d','%d','%d','%.6f','%.6f',"
                           "'%.6f','%.6f')", lay, col, fon, wid,
                        (o->d[0] + hw) * sc, (o->d[1] + hh) * sc,
                        (o->d[2] + hw) * sc, (o->d[3] + hh) * sc);
                feature(&s->w, t);
                break;
            case JW_ENKO: {
                /* The angles are worked out the way the original's come
                   out: the start and the sweep each go through a 32-bit
                   float in degrees, and the end is their sum -- which is
                   why an arc that sweeps to 325.700927 is written as
                   325.700912.  The turn is part of the start. */
                double sw = o->d[4];
                double s0 = f32((o->d[3] + o->d[5]) / PI * 180.0);
                double s1 = s0 + sw / PI * 180.0;
                int whole = sw >= 2.0 * PI - 1e-9 || sw <= -2.0 * PI + 1e-9;
                double cx = (o->d[0] + hw) * sc, cy = (o->d[1] + hh) * sc;

                while (s0 < 0.0) s0 += 360.0;
                while (s0 >= 360.0) s0 -= 360.0;
                while (s1 < 0.0) s1 += 360.0;
                while (s1 >= 360.0) s1 -= 360.0;
                ang(a, s0);
                ang(b, s1);
                if (o->d[6] != 1.0) {
                    /* Squashed: a whole one is an ellipse and a part of one
                       is an ellipse_arc.  Here the turn is a field of its
                       own, so the two ends are the angles **before** it is
                       turned -- unlike a round arc, where the turn is part
                       of the start.  The order is the turn, which way round
                       it goes, and then the two ends. */
                    double maj = o->d[2] * sc, min_ = o->d[2] * o->d[6] * sc;
                    double t0 = f32(o->d[3] / PI * 180.0);
                    double t1 = t0 + sw / PI * 180.0;
                    double tu = f32(o->d[5] / PI * 180.0);

                    while (t0 < 0.0) t0 += 360.0;
                    while (t0 >= 360.0) t0 -= 360.0;
                    while (t1 < 0.0) t1 += 360.0;
                    while (t1 >= 360.0) t1 -= 360.0;
                    while (tu < 0.0) tu += 360.0;
                    while (tu >= 360.0) tu -= 360.0;
                    ang(a, t0);
                    ang(b, t1);
                    ang(c, tu);
                    if (whole)
                        snprintf(t, sizeof t, "ellipse_feature('%d','%d','%d','%d',"
                                   "'%.6f','%.6f','%.6f','%.6f','%s')",
                                lay, col, fon, wid, cx, cy, maj, min_, c);
                    else
                        snprintf(t, sizeof t, "ellipse_arc_feature('%d','%d','%d','%d',"
                                   "'%.6f','%.6f','%.6f','%.6f','%d','%s',"
                                   "'%s','%s')", lay, col, fon, wid, cx, cy,
                                maj, min_, sw < 0.0, c, a, b);
                } else if (whole) {
                    snprintf(t, sizeof t, "circle_feature('%d','%d','%d','%d','%.6f',"
                               "'%.6f','%.6f')", lay, col, fon, wid,
                            cx, cy, o->d[2] * sc);
                } else {
                    snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                               "'%.6f','%.6f','%d','%s','%s')", lay, col,
                            fon, wid, cx, cy, o->d[2] * sc, sw < 0.0, a, b);
                }
                feature(&s->w, t);
                break;
            }
            case JW_TEN:
                ang(a, 0.0);
                ang(b, 1.0);
                snprintf(t, sizeof t, "point_marker_feature('%d','%d','%.6f','%.6f',"
                           "'3','%s','%s')", lay, col,
                        (o->d[0] + hw) * sc, (o->d[1] + hh) * sc, a, b);
                feature(&s->w, t);
                break;
            case JW_MOJI: {
                double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
                double len = sqrt(dx * dx + dy * dy);
                double deg = atan2(dy, dx) / PI * 180.0;

                while (deg < 0.0)
                    deg += 360.0;
                while (deg >= 360.0)
                    deg -= 360.0;
                ang(a, deg);
                ang(b, 0.0);
                snprintf(t, sizeof t, "text_string_feature('%d','%d','1',\\'%s\\',"
                           "'%.6f','%.6f','%.6f','%.6f','%.6f','%s','%s',"
                           "'1','1')", lay, col, jw_str(d, o->text),
                        (o->d[0] + hw) * sc, (o->d[1] + hh) * sc,
                        o->d[5] * sc, len * sc, o->d[6] * sc, a, b);
                feature(&s->w, t);
                break;
            }
            case JW_SOLID: {
                /* A solid is written as the outline of what it fills, with
                 * nothing saying it is filled -- the original writes no
                 * fill_area_style of its own for one.  Four corners come out
                 * as a closed polyline of five points, the first corner and
                 * then the other three backwards; a 円ソリッド comes out as
                 * its rim, a whole one split into two halves and a part of
                 * one closed by the chord between its ends.
                 * decomp/res/rsolid.sfc is the original doing all three.
                 */
                jw_obj round;
                char xs[256], ys[256];

                if (jw_round_solid(o, &round)) {
                    double cx = (round.d[0] + hw) * sc, cy = (round.d[1] + hh) * sc;
                    double r = round.d[2] * sc, sw = round.d[4];
                    double s0 = f32((round.d[3] + round.d[5]) / PI * 180.0);
                    double s1 = s0 + sw / PI * 180.0;
                    int whole = sw >= 2.0 * PI - 1e-9 || sw <= -2.0 * PI + 1e-9;

                    while (s0 < 0.0) s0 += 360.0;
                    while (s0 >= 360.0) s0 -= 360.0;
                    while (s1 < 0.0) s1 += 360.0;
                    while (s1 >= 360.0) s1 -= 360.0;
                    if (whole) {
                        double half = s0 + 180.0;

                        while (half >= 360.0) half -= 360.0;
                        ang(a, s0);
                        ang(b, half);
                        snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                                   "'%.6f','%.6f','0','%s','%s')", lay, col,
                                fon, wid, cx, cy, r, a, b);
                        feature(&s->w, t);
                        ang(a, half);
                        ang(b, s0);
                        snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                                   "'%.6f','%.6f','0','%s','%s')", lay, col,
                                fon, wid, cx, cy, r, a, b);
                        feature(&s->w, t);
                    } else {
                        double e0 = s0 * PI / 180.0, e1 = s1 * PI / 180.0;

                        ang(a, s0);
                        ang(b, s1);
                        snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                                   "'%.6f','%.6f','%d','%s','%s')", lay, col,
                                fon, wid, cx, cy, r, sw < 0.0, a, b);
                        feature(&s->w, t);
                        /* and the chord back, from where it ends to where
                           it starts */
                        sprintf(xs, "(%.6f,%.6f)", cx + r * cos(e1),
                                cx + r * cos(e0));
                        sprintf(ys, "(%.6f,%.6f)", cy + r * sin(e1),
                                cy + r * sin(e0));
                        snprintf(t, sizeof t, "polyline_feature('%d','%d','%d','%d',"
                                   "'2','%s','%s')", lay, col, fon, wid,
                                xs, ys);
                        feature(&s->w, t);
                    }
                    solid_end(s, &nfill, fill, lay, col, fon, wid);
                    break;
                }
                {   /* the four corners, the last three backwards */
                    static const int K[5] = { 0, 3, 2, 1, 0 };
                    int q, nx = 0, ny = 0;

                    for (q = 0; q < 5; q++) {
                        nx += sprintf(xs + nx, q ? ",%.6f" : "(%.6f",
                                      (o->d[K[q] * 2] + hw) * sc);
                        ny += sprintf(ys + ny, q ? ",%.6f" : "(%.6f",
                                      (o->d[K[q] * 2 + 1] + hh) * sc);
                    }
                    strcpy(xs + nx, ")");
                    strcpy(ys + ny, ")");
                }
                snprintf(t, sizeof t, "polyline_feature('%d','%d','%d','%d','5','%s',"
                           "'%s')", lay, col, fon, wid, xs, ys);
                feature(&s->w, t);
                solid_end(s, &nfill, fill, lay, col, fon, wid);
                break;
            }
            default:
                break;
            }
        }
        /* What says the solids are filled, one line each, after all the
           elements of the group: which layer, which colour, and which of
           the composite curves above it is the fill of, counted from one. */
        for (i = 0; i < nfill; i++) {
            snprintf(t, sizeof t, "fill_area_style_colour_feature('%d','%d','%d','0',"
                       "'()')", fill[i * 2], fill[i * 2 + 1], i + 1);
            feature(&s->w, t);
        }
        if (any) {
            /* the name carries the group's own name as far as its first
               character that is not plain ASCII */
            const char *nm = jw_str(d, d->group[g].name);
            int k = 0;

            while (nm[k] && (unsigned char)nm[k] < 0x80 && k < 8)
                k++;
            snprintf(t, sizeof t, "sfig_org_feature(\\'-GLay-%x-%.*s\\','1')", g, k, nm);
            feature(&s->w, t);
        }
    }

    free(fill);

    /* ------------------------------------------- the figures and the rest */
    for (g = 0; g < 16; g++) {
        double sc = d->group[g].scale > 0.0 ? d->group[g].scale : 1.0;
        const char *nm = jw_str(d, d->group[g].name);
        int k = 0, any = 0;

        for (i = 0; i < d->ndrawn; i++)
            if ((d->obj[i].lgroup & 15) == g && d->obj[i].cls != JW_LIST
                && d->obj[i].cls != JW_BLOCK && jw_text_drawn(&d->obj[i]))
                any = 1;
        if (!any)
            continue;
        while (nm[k] && (unsigned char)nm[k] < 0x80 && k < 8)
            k++;
        ang(a, 0.0);
        ang(b, 1.0 / sc);
        ang(c, 1.0 / sc);
        snprintf(t, sizeof t, "sfig_locate_feature('0',\\'-GLay-%x-%.*s\\','%.6f',"
                   "'%.6f','%s','%s','%s')", g, k, nm, 0.0, 0.0, a, b, c);
        feature(&s->w, t);
    }
    snprintf(t, sizeof t, "drawing_sheet_feature(\\'sheet\\','%d','1','%d','%d')",
            d->paper_size, (int)(d->paper_hw * 2.0 + 0.5),
            (int)(d->paper_hh * 2.0 + 0.5));
    feature(&s->w, t);
    for (i = 0; i < s->nlay; i++) {
        /* a layer that cannot be seen says so, and a layer in a group that
           is turned off cannot be seen either */
        int g2 = s->lay[i].g, l2 = s->lay[i].l;

        const char *ln = jw_str(d, d->group[g2].layer_name[l2]);
        char fall[16];

        if (!ln[0]) {           /* a layer with no name is called after it */
            sprintf(fall, "_%x-%x_", g2, l2);
            ln = fall;
        }
        snprintf(t, sizeof t, "layer_feature(\\'%s\\','%d')", ln,
                d->group[g2].state != 0 && d->group[g2].layer[l2].state != 0);
        feature(&s->w, t);
    }
    /* the layer the original adds for whatever is 補助線 */
    snprintf(t, sizeof t, "layer_feature(\\'\x95\xe2\x8f\x95\x90\xfc\\','0')");
    feature(&s->w, t);

    puts_(&s->w, "ENDSEC;\r\nEND-ISO-10303-21;\r\n");
    if (s->w.bad) {
        free(s->w.b);
        free(s);
        return 0;
    }
    *out = s->w.b;
    *n = s->w.n;
    free(s);
    return 1;
}
