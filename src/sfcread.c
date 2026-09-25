/* Reading an SFC -- 「SFCファイルを開く」 (menu 32975).
 *
 * SFC is SXF level 2 in its feature mode: a STEP part 21 wrapper whose data
 * section is a run of comments, each holding one feature.
 *
 *     /_*SXF
 *     #470 = line_feature('1','7','1','11','66100.0','71400.0',...)
 *     SXF*_/
 *
 * The original does not write these itself -- orig/common_lib.dll does, and
 * the original only hands it numbers -- but reading one is its own work, and
 * this follows what it makes of a file rather than what the standard says.
 * What it makes of one was read off by having it open files made here and
 * save them again (RESUME.md has the table):
 *
 *   * The elements go inside a 図形: the SFC names one with
 *     sfig_org_feature, and sfig_locate_feature says where it sits and how
 *     big.  So a drawing read from an SFC is one reference plus one
 *     definition, and the definition keeps the SFC's own coordinates.
 *   * A colour number k becomes 任意色 100+k, a line type k becomes
 *     任意線種 30+k, and a width becomes hundredths of a millimetre.
 *   * A layer number is the layer, in group 0.
 *
 * Lines, arcs, circles, points, polylines and texts are read; fills (which
 * is how a solid comes) and dimensions are not yet.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "text.h"

#define PI 3.14159265358979323846

/* The face a text comes in with, whatever the file's own font table says:
   the original's default, 「MS ゴシック」 in full width. */
#define JW_SFC_FACE "\x82\x6c\x82\x72 \x83\x53\x83\x56\x83\x62\x83\x4e"

#define NAME 128
#define NARG 24
#define NCOL 260
#define NFONT 64
#define NWIDTH 64
#define NLAYER 64

typedef struct {
    const unsigned char *b;
    long n, p;

    char name[NAME];            /* the feature just read                   */
    char arg[NARG][NAME];
    int narg;

    jw_drawing *d;

    unsigned int colour[NCOL];  /* colour k, as a COLORREF                 */
    int ncolour;
    double width[NWIDTH];       /* width k, in millimetres                 */
    int nwidth;
    int nfont;                  /* how many user line types so far         */

    struct {
        char name[NAME];
        int state;
    } lay[NLAYER];
    int nlay;

    double sheet_w, sheet_h;
    double loc_x, loc_y, loc_a, loc_sx, loc_sy;
    int have_loc;
    char fig[NAME];             /* the name sfig_org_feature gave           */
    int fig_flag;

    int list_at;                /* where the definition went, -1 until then */
} sfcr;

/* -------------------------------------------------------------- the lexer */

/* The next feature, or 0 at the end.  A feature is `#<n> = <name>(<args>)`
   inside a /_*SXF ... SXF*_/ comment; an argument is a string, quoted with
   `'` or with `\'` when it is a name rather than a number. */
static int feature(sfcr *r)
{
    long i;
    int k;

    for (;;) {
        /* to the next comment */
        while (r->p + 5 <= r->n && memcmp(r->b + r->p, "/*SXF", 5))
            r->p++;
        if (r->p + 5 > r->n)
            return 0;
        r->p += 5;
        /* the name runs to the bracket */
        while (r->p < r->n && (r->b[r->p] == '\r' || r->b[r->p] == '\n'
                               || r->b[r->p] == ' '))
            r->p++;
        /* a file that stops right after the comment opener leaves p at the
           end here, and the test below would read the byte after it */
        if (r->p >= r->n)
            return 0;
        if (r->b[r->p] != '#')
            continue;
        while (r->p < r->n && r->b[r->p] != '=')
            r->p++;
        r->p++;
        while (r->p < r->n && r->b[r->p] == ' ')
            r->p++;
        for (i = 0; r->p < r->n && r->b[r->p] != '(' && i < NAME - 1; i++)
            r->name[i] = (char)r->b[r->p++];
        r->name[i] = 0;
        if (r->p >= r->n)
            return 0;
        r->p++;                 /* past the bracket */
        r->narg = 0;
        for (k = 0; k < NARG; k++) {
            int esc;

            while (r->p < r->n && (r->b[r->p] == ',' || r->b[r->p] == ' '))
                r->p++;
            if (r->p >= r->n || r->b[r->p] == ')')
                break;
            esc = r->b[r->p] == '\\';
            if (esc)
                r->p++;         /* which can put p on the end */
            if (r->p >= r->n || r->b[r->p] != '\'')
                break;
            r->p++;
            for (i = 0; r->p < r->n && i < NAME - 1; i++) {
                if (r->b[r->p] == '\'')
                    break;
                if (esc && r->b[r->p] == '\\' && r->p + 1 < r->n
                    && r->b[r->p + 1] == '\'')
                    break;
                r->arg[k][i] = (char)r->b[r->p++];
            }
            r->arg[k][i] = 0;
            if (r->p < r->n && r->b[r->p] == '\\')
                r->p++;
            if (r->p < r->n && r->b[r->p] == '\'')
                r->p++;
            r->narg++;
        }
        return 1;
    }
}

static double num(sfcr *r, int k)
{
    return k < r->narg ? atof(r->arg[k]) : 0.0;
}

static int inum(sfcr *r, int k)
{
    return k < r->narg ? atoi(r->arg[k]) : 0;
}

/* A name into fixed room; anything longer is cut. */
static void copy_name(char *dst, const char *src)
{
    int i;

    for (i = 0; i < NAME - 1 && src[i]; i++)
        dst[i] = src[i];
    dst[i] = 0;
}

static int is(sfcr *r, const char *s)
{
    return !strcmp(r->name, s);
}

/* ------------------------------------------------------------ the tables */

/* The sixteen colours and fifteen line types SXF names, in the order
   orig/common_lib.dll keeps them -- which is the order their numbers run
   in, whatever order a file happens to write them in. */
static const char *const COLOUR[16] = {
    "black", "red", "green", "blue", "yellow", "magenta", "cyan", "white",
    "deeppink", "brown", "orange", "lightgreen", "lightblue", "lavender",
    "lightgray", "darkgray"
};
/* The fifteen line types SXF names are, in that same order, the drawing's
   own 任意線種 1 to 15 -- so nothing has to be done for one of those: an
   element names its line type by number, and 任意線種 k is line type 30+k.
   Only one the file defines itself has to be put in. */

static void table(sfcr *r)
{
    if (is(r, "pre_defined_colour_feature")) {
        int i;

        if (r->ncolour < NCOL - 1) {
            r->ncolour++;
            /* the drawing's own 任意色 1 to 16 are these very colours,
               under these very names, so it is the table to read */
            r->colour[r->ncolour] = 0;
            for (i = 0; i < 16; i++)
                if (!strcmp(r->arg[0], COLOUR[i]))
                    r->colour[r->ncolour] = r->d->xcolor[i + 1];
        }
    } else if (is(r, "user_defined_colour_feature")) {
        if (r->ncolour < NCOL - 1) {
            /* the file gives red, green and blue; a drawing keeps a
               COLORREF, which is the other way round */
            unsigned rr = (unsigned)inum(r, 0) & 0xff;
            unsigned gg = (unsigned)inum(r, 1) & 0xff;
            unsigned bb = (unsigned)inum(r, 2) & 0xff;

            r->ncolour++;
            r->colour[r->ncolour] = (bb << 16) | (gg << 8) | rr;
        }
    } else if (is(r, "user_defined_font_feature")) {
        /* the fifteen SXF knows are numbered by name; one the file defines
           follows them, from 17 -- 16 is never used.  Its dashes come as
           one string, `(a,b,c,d)`. */
        int k = 17 + r->nfont++, i, m = inum(r, 1);
        const char *p = r->arg[2];

        if (k < 33) {
            if (m > 10)
                m = 10;
            r->d->sxf[k].n = m;
            for (i = 1; i <= m; i++) {
                while (*p && *p != '(' && *p != ',')
                    p++;
                if (*p)
                    p++;
                r->d->sxf[k].pat[i] = atof(p);
            }
            if (k > r->d->sxf_n)
                r->d->sxf_n = k;
        }
    } else if (is(r, "width_feature")) {
        /* the nine SXF knows are 1 to 9 and one of its own starts at 11 */
        int k = r->nwidth + 1;

        if (k == 10)
            k = 11;
        if (k < NWIDTH) {
            r->width[k] = num(r, 0);
            r->nwidth = k;
        }
    } else if (is(r, "layer_feature")) {
        if (r->nlay < NLAYER - 1) {
            r->nlay++;
            copy_name(r->lay[r->nlay].name, r->arg[0]);
            r->lay[r->nlay].state = inum(r, 1);
        }
    } else if (is(r, "drawing_sheet_feature")) {
        r->sheet_w = num(r, 3);
        r->sheet_h = num(r, 4);
    } else if (is(r, "sfig_org_feature")) {
        copy_name(r->fig, r->arg[0]);
        r->fig_flag = inum(r, 1);
    } else if (is(r, "sfig_locate_feature")) {
        r->loc_x = num(r, 2);
        r->loc_y = num(r, 3);
        r->loc_a = num(r, 4);
        r->loc_sx = num(r, 5);
        r->loc_sy = num(r, 6);
        r->have_loc = 1;
    }
}

/* ---------------------------------------------------------- the elements */

/* The first four arguments every drawn feature carries. */
static jw_obj *place(sfcr *r, int cls)
{
    jw_obj *o = jw_add(r->d, cls);
    int w = inum(r, 3);

    if (!o)
        return 0;
    o->layer = (unsigned short)(inum(r, 0) & 0xf);
    o->lgroup = 0;
    o->color = (unsigned short)(100 + inum(r, 1));
    o->ltype = (unsigned char)(30 + inum(r, 2));
    o->width = (unsigned short)(w > 0 && w < NWIDTH
                                ? (int)(r->width[w] * 100.0 + 0.5) : 0);
    return o;
}

/* How many half-widths a CP932 string comes to, and how much of the gap
   between letters it carries: a whole-width letter is two half-widths and
   takes a whole gap, a half-width one takes half.  The original counts it
   this way when it places a text of its own (src/cmd.c), and an SFC gives
   the whole width rather than the width of a letter, so this is what turns
   one into the other. */
static void measure(const char *s, double sp, double *half, double *gap)
{
    int nb = 0, first = 1;

    *gap = 0.0;
    while (*s) {
        int wide = jw_is_lead((unsigned char)s[0]) && s[1];

        if (!first)
            *gap += wide ? sp : sp / 2.0;
        first = 0;
        nb += wide ? 2 : 1;
        s += wide ? 2 : 1;
    }
    *half = (double)nb;
}

static void element(sfcr *r)
{
    jw_obj *o;

    if (is(r, "polyline_feature")) {
        /* layer, colour, line type, width, how many corners, then the two
           coordinates as one string each -- and it comes apart into lines */
        int n = inum(r, 4), i;
        const char *px = r->arg[5], *py = r->arg[6];
        double x0 = 0, y0 = 0, x1, y1;

        for (i = 0; i < n; i++) {
            while (*px && *px != '(' && *px != ',')
                px++;
            while (*py && *py != '(' && *py != ',')
                py++;
            if (*px)
                px++;
            if (*py)
                py++;
            x1 = atof(px);
            y1 = atof(py);
            if (i > 0) {
                o = place(r, JW_SEN);
                if (!o)
                    return;
                o->d[0] = x0;
                o->d[1] = y0;
                o->d[2] = x1;
                o->d[3] = y1;
            }
            x0 = x1;
            y0 = y1;
        }
    } else if (is(r, "text_string_feature")) {
        /* layer, colour, which font, the words, the place, the height, how
           wide the whole of it is, the gap between letters, the turn, the
           slant, and two more this does not use */
        double x = num(r, 4), y = num(r, 5), h = num(r, 6);
        double total = num(r, 7), sp = num(r, 8), ang = num(r, 9);
        double half = 0, gap = 0;

        o = jw_add(r->d, JW_MOJI);
        if (!o)
            return;
        o->layer = (unsigned short)(inum(r, 0) & 0xf);
        o->lgroup = 0;
        o->color = (unsigned short)(100 + inum(r, 1));
        o->ltype = 1;
        o->width = 0;
        measure(r->arg[3], sp, &half, &gap);
        o->d[0] = x;
        o->d[1] = y;
        o->d[2] = x + total * cos(ang * PI / 180.0);
        o->d[3] = y + total * sin(ang * PI / 180.0);
        o->d[4] = half > 0.0 ? (total - gap) * 2.0 / half : h;
        o->d[5] = h;
        o->d[6] = sp;
        o->d[7] = ang;
        o->n = 3;               /* 文字種 3, whatever the size */
        o->text = jw_add_str(r->d, r->arg[3]);
        o->face = jw_add_str(r->d, JW_SFC_FACE);
    } else if (is(r, "line_feature")) {
        o = place(r, JW_SEN);
        if (o) {
            o->d[0] = num(r, 4);
            o->d[1] = num(r, 5);
            o->d[2] = num(r, 6);
            o->d[3] = num(r, 7);
        }
    } else if (is(r, "circle_feature")) {
        o = place(r, JW_ENKO);
        if (o) {
            o->d[0] = num(r, 4);
            o->d[1] = num(r, 5);
            o->d[2] = num(r, 6);
            o->d[3] = 0.0;
            o->d[4] = 2.0 * PI;
            o->d[5] = 0.0;
            o->d[6] = 1.0;
            o->n = 1;           /* a whole circle */
        }
    } else if (is(r, "arc_feature")) {
        o = place(r, JW_ENKO);
        if (o) {
            /* the eighth says which way round it goes, and the last two
               are where it starts and where it ends, in degrees.  The
               start is kept as it is -- an arc that starts at 270 stays at
               270, unlike one read from a DXF -- and the sweep is how far
               it goes, the other way round when the eighth says so. */
            int back = inum(r, 7);
            double a0 = num(r, 8), a1 = num(r, 9), sw;

            sw = back ? a0 - a1 : a1 - a0;
            /* bounded, so a damaged file cannot spin here */
            while (sw < 0.0 && sw > -1e9)
                sw += 360.0;
            while (sw >= 360.0 && sw < 1e9)
                sw -= 360.0;
            if (back)
                sw = -sw;
            o->d[0] = num(r, 4);
            o->d[1] = num(r, 5);
            o->d[2] = num(r, 6);
            o->d[3] = a0 / 180.0 * PI;
            o->d[4] = sw / 180.0 * PI;
            o->d[5] = 0.0;
            o->d[6] = 1.0;
        }
    } else if (is(r, "point_marker_feature")) {
        /* A point has no line type or width: layer, colour, the place, then
           which marker, how far round and how big.  It comes in as a
           任意点 -- line type 100 -- which is what carries those three. */
        o = jw_add(r->d, JW_TEN);
        if (o) {
            o->layer = (unsigned short)(inum(r, 0) & 0xf);
            o->lgroup = 0;
            o->color = (unsigned short)(100 + inum(r, 1));
            o->ltype = 100;
            o->width = 0;
            o->d[0] = num(r, 2);
            o->d[1] = num(r, 3);
            o->n = 0;
            o->mark = -inum(r, 4);
            o->turn = num(r, 5);
            o->size = num(r, 6);
        }
    }
}

/* ------------------------------------------------------------------ read */

int jw_sfc_read(jw_drawing *d, const unsigned char *b, long n)
{
    sfcr *r = (sfcr *)calloc(1, sizeof *r);
    int i, at, first;
    jw_obj *o;

    if (!r)
        return 0;
    r->b = b;
    r->n = n;
    r->d = d;
    r->loc_sx = r->loc_sy = 1.0;
    r->list_at = -1;
    if (n < 16 || memcmp(b, "ISO-10303-21;", 13)) {
        free(r);
        return 0;
    }

    while (d->nobj > 0)
        jw_remove(d, d->nobj - 1);
    for (i = 0; i < 16; i++) {
        int l;

        for (l = 0; l < 16; l++)
            d->group[i].layer_name[l] = -1;
    }

    /* The definition goes in first, so that everything the file draws lands
       inside it; the reference to it is added at the end, in front. */
    o = jw_add(d, JW_LIST);
    if (!o) {
        free(r);
        return 0;
    }
    at = (int)(o - d->obj);
    first = d->nobj;

    while (feature(r)) {
        table(r);
        element(r);
    }

    /* what the tables settled */
    if (r->sheet_w > 0.0 && r->sheet_h > 0.0) {
        d->paper_hw = r->sheet_w / 2.0;
        d->paper_hh = r->sheet_h / 2.0;
    }
    for (i = 0; i < 16; i++)
        d->group[i].scale = 1.0;
    for (i = 1; i <= r->nlay && i < 16; i++) {
        d->group[0].layer_name[i] = jw_add_str(d, r->lay[i].name);
        d->group[0].layer[i].state = r->lay[i].state ? 1 : 0;
    }
    for (i = 1; i <= r->ncolour && i <= 256; i++) {
        d->xcolor[i] = r->colour[i];
        d->xcolor_rest[i].rgb2 = r->colour[i];
    }
    /* The loop above stops at 256 because that is how many the drawing
       holds; the count has to stop there too.  A file may define up to
       NCOL-1 = 259 of them, and a count of 257 or more outlives this
       reader: src/dxfread.c sets `ncol = 100 + xcolor_n` and then walks
       `col[1 .. ncol]`, which is only 357 long.  So an SFC with more than
       256 colours, followed by a DXF, read past the end of that table. */
    if (r->ncolour > d->xcolor_n)
        d->xcolor_n = r->ncolour > 256 ? 256 : r->ncolour;

    d->obj[at].n = d->nobj - first;
    d->obj[at].list[0] = 0;
    d->obj[at].list[1] = r->fig_flag;
    d->obj[at].list[2] = 0;
    {
        char nm[NAME * 2];

        sprintf(nm, "%s@@SfigorgFlag@@%d", r->fig, r->fig_flag);
        d->obj[at].text = jw_add_str(d, nm);
    }
    d->obj[at].ltype = 1;
    d->obj[at].color = 2;
    d->obj[at].layer = 1;
    d->obj[at].lgroup = 0;
    /* the definition and its elements are not part of the drawing */
    d->ndrawn = 0;

    /* and the reference: at the corner of the sheet, shrunk by what
       sfig_locate_feature said */
    o = jw_add(d, JW_BLOCK);
    if (o) {
        o->ltype = 65;
        o->color = 2;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = -d->paper_hw + r->loc_x;
        o->d[1] = -d->paper_hh + r->loc_y;
        o->d[2] = r->loc_sx;
        o->d[3] = r->loc_sy;
        o->d[4] = r->loc_a / 180.0 * PI;
        o->block = 0;
    }
    free(r);
    if (!jw_numbers_sane(d)) {
        d->error = "a coordinate that cannot be";
        return 0;
    }
    return 1;
}
