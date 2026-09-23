/* Reading a DXF -- 「DXFファイルを開く」 (menu 32960).
 *
 * The original's reader is CDxfFile::Read (0x0049f4d0): a loop over group
 * code and value pairs, with one function per section and one per kind of
 * entity.  This follows it.  What it does is not what a careful reader of
 * the DXF specification would do, and the differences are the point -- a
 * port that tidied them up would not put the same drawing on the screen:
 *
 *   * The scale is not in the DXF.  It is worked out from how wide the
 *     drawing is against the sheet the document is already set to, and
 *     rounded to one of the scales a person would have chosen (1/100,
 *     1/200, ...).  Everything is then placed around the middle of those
 *     extents (FUN_004a2ce0).
 *   * A colour number is looked up in a table of 256 colours the original
 *     builds when it starts (src/gen/aci.h), matched against the drawing's
 *     eight *printing* pens and its 任意色, and when nothing matches
 *     exactly a new 任意色 is made.  The new one is stored with its red and
 *     blue swapped, so asking twice for the same colour makes two entries
 *     (FUN_0049da00).
 *   * A layer called `_0-0_名前` goes to group 0, layer 0, under the name
 *     `_名前` -- and a layer whose name does not say where it belongs is
 *     put after the last one, so where a drawing from somewhere else lands
 *     depends on the order its LAYER table is in (FUN_004a40b0).
 *   * A line type is matched by its dash pattern rather than its name
 *     (FUN_0049e380), so a DXF whose DASHED1 is not jw's 点線1 comes in as
 *     a new 任意線種.
 *
 * TEXT, MTEXT, POLYLINE, LWPOLYLINE, INSERT, HATCH, DIMENSION and ELLIPSE
 * are not read yet; the entities that are are LINE, ARC, CIRCLE, POINT and
 * SOLID.
 */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "gen/aci.h"

#define PI 3.14159265358979323846

#define NAME 128        /* as much of a name as is kept */
#define NLAYER 256
#define NLTYPE 100

typedef struct {
    const unsigned char *b;
    long n, p;

    int code;                   /* the group code just read, -1 at the end */
    char str[NAME];             /* its value as text                       */
    double num;                 /* and as a number                         */

    jw_drawing *d;

    /* the sheet the entities land on */
    double cx, cy, scale;
    double ext[4];              /* $EXTMIN.x, .y, $EXTMAX.x, .y            */
    int has_ext;

    /* the layers, as the LAYER table and the entities between them make
       them: a name, the line type and colour to fall back on */
    struct {
        char name[NAME];
        int ltype, color;
    } lay[NLAYER];
    /* The original keeps one number for both how many layers there are and
       which one the LAYER table is filling (0x1b78), so a record that says
       where it belongs moves the count with it. */
    int nlay;

    struct {
        char name[NAME];
        int code;               /* what FUN_0049e380 made of its pattern   */
    } lt[NLTYPE];
    int nlt;

    unsigned int col[357];      /* 1..10 the printing pens, 101.. the rest */
    int ncol;
} dxfr;

/* ------------------------------------------------------------- the lexer */

/* One line, without its ending.  DXF is CRLF but a reader that insists on it
   is no use on a file that has been through a text tool. */
static int line(dxfr *r, char *out, int max)
{
    int i = 0;

    if (r->p >= r->n)
        return 0;
    while (r->p < r->n && r->b[r->p] != '\n' && r->b[r->p] != '\r') {
        if (i < max - 1)
            out[i++] = (char)r->b[r->p];
        r->p++;
    }
    out[i] = 0;
    if (r->p < r->n && r->b[r->p] == '\r')
        r->p++;
    if (r->p < r->n && r->b[r->p] == '\n')
        r->p++;
    return 1;
}

/* FUN_004a10a0: the next pair.  Both forms are kept because the original
   keeps both -- a string field is read as text and a number field as a
   double, and which one an entity looks at is the entity's business. */
static void next(dxfr *r)
{
    char c[64];

    r->code = -1;
    r->str[0] = 0;
    r->num = 0.0;
    if (!line(r, c, sizeof c))
        return;
    r->code = atoi(c);
    if (!line(r, r->str, NAME))
        r->code = -1;
    else
        r->num = atof(r->str);
}

/* Names are kept in fixed room; anything longer is cut. */
static void copy_name(char *dst, const char *src)
{
    int i;

    for (i = 0; i < NAME - 1 && src[i]; i++)
        dst[i] = src[i];
    dst[i] = 0;
}

static int is(dxfr *r, int code, const char *s)
{
    return r->code == code && !strcmp(r->str, s);
}

/* ------------------------------------------------------------- the paper */

static double put_x(dxfr *r, double v) { return (v - r->cx) / r->scale; }
static double put_y(dxfr *r, double v) { return (v - r->cy) / r->scale; }
static double put_l(dxfr *r, double v) { return v / r->scale; }

/* ------------------------------------------------------------ the colour */

static unsigned swap_rb(unsigned v)
{
    return ((v & 0xff) << 16) | (v & 0xff00) | ((v >> 16) & 0xff);
}

/* FUN_0049da00 with a colour number (group code 62). */
static int colour(dxfr *r, int aci, int raw)
{
    unsigned want = raw ? (unsigned)aci : JW_ACI[aci & 0xff];
    int best = 0, bestd = 999999, i;

    for (i = 1; i <= r->ncol; i++) {
        unsigned t;
        int dist;

        if (i == 9)
            i = 101;            /* 9 and 10 are not offered, 11..100 unused */
        t = r->col[i];
        dist = abs((int)((t >> 16) & 0xff) - (int)((want >> 16) & 0xff))
             + abs((int)((t >> 8) & 0xff) - (int)((want >> 8) & 0xff))
             + abs((int)(t & 0xff) - (int)(want & 0xff));
        if (dist < bestd) {
            bestd = dist;
            best = i;
            if (!dist)
                break;
        }
    }
    if (bestd && r->ncol < 356) {
        r->ncol++;
        /* stored the other way round from the table it was matched against,
           which is why the same colour twice makes two entries */
        r->col[r->ncol] = swap_rb(want);
        best = r->ncol;
    }
    return best;
}

/* --------------------------------------------------------- the line type */

/* The nine line types the original writes for its own, read off the LTYPE
   table of orig/DXF_HDR.DAT -- which is what it puts in every DXF it makes,
   so a DXF it wrote matches these exactly.  Slot 0 is 実線, which has no
   pattern at all. */
static const struct { int n; double pat[9]; } STD[9] = {
    { 0, { 0 } },
    { 2, { 0, 1.25, 1.25 } },
    { 2, { 0, 2.5, 2.5 } },
    { 2, { 0, 3.75, 1.25 } },
    { 4, { 0, 6.25, 1.25, 1.25, 1.25 } },
    { 4, { 0, 12.5, 2.5, 2.5, 2.5 } },
    { 6, { 0, 3.25, 1.25, 1.25, 1.25, 1.25, 1.25 } },
    { 6, { 0, 10.0, 2.5, 1.25, 2.5, 1.25, 2.5 } },
    { 2, { 0, 0.625, 1.875 } },
};

/* How far out a pattern may be and still count as one the drawing already
   has, in per cent.  The original keeps it in 基本設定 (DAT_00a0eef8). */
#define LTYPE_TOL 20

/* FUN_0049e380: which line type has this pattern.  The original looks
   through its 任意線種 (1..32) and then its own nine (41..49) and takes the
   one whose lengths differ least in proportion; when even that is more than
   一致率 out it makes a 任意線種 of its own -- unless all 32 are taken, and
   then the nearest one has to do. */
static int ltype_match(dxfr *r, int n, const double *pat)
{
    int best = 0, bestd = 99999, i, k;

    if (!n)
        return 1;
    for (i = 1; i < 0x3d; i++) {
        const double *q;
        double sum = 0.0, tot = 0.0;
        int dist;

        if (i == 0x21)
            i = 0x29;
        if (i >= 0x29) {
            if (i > 0x31 || STD[i - 0x29].n != n)
                continue;
            q = STD[i - 0x29].pat;
        } else {
            if (r->d->sxf[i].n != n)
                continue;
            q = r->d->sxf[i].pat;
        }
        for (k = 1; k <= n; k++) {
            tot += pat[k];
            sum += fabs(pat[k] - q[k]);
        }
        dist = tot < 0.001 ? 999999999 : (int)(sum / tot * 100.0 + 0.5);
        if (dist < bestd) {
            bestd = dist;
            best = i;
        }
    }
    if (bestd > LTYPE_TOL && r->d->sxf_n < 32) {
        k = ++r->d->sxf_n;
        r->d->sxf[k].n = n;
        for (i = 1; i <= n; i++)
            r->d->sxf[k].pat[i] = pat[i];
        best = k;
    }
    return best;
}

/* FUN_0049e2d0: the line type an entity's name asks for.  The numbers the
   table keeps are the original's internal ones -- its own nine are 41..49
   and the 任意線種 are 1..32 -- and this is how they come out as the number
   an element carries. */
static int ltype_of(dxfr *r, const char *name)
{
    int i, n;

    for (i = 0; i < r->nlt; i++)
        if (!strcmp(name, r->lt[i].name))
            break;
    if (i == r->nlt)
        return 1;
    n = r->lt[i].code;
    if (n < 0x29) {
        if (n > 1)
            n += 0x1e;
    } else {
        n -= 0x28;
    }
    return n;
}

/* ------------------------------------------------------------ the layers */

/* `_<group>-<layer>_<name>`: where the original writes which of its 16 by 16
   layers something is on.  Returns the name without it, and says where the
   two digits pointed, or -1 when the name is not of that shape. */
static const char *layer_split(const char *name, int *at)
{
    *at = -1;
    if (name[0] == '_' && name[2] == '-' && name[4] == '_') {
        int g = name[1] >= '0' && name[1] <= '9' ? name[1] - '0' : 99;
        int l = name[3] >= '0' && name[3] <= '9' ? name[3] - '0' : 99;

        if (g < 16 && l < 16) {
            *at = g * 16 + l;
            return name + 5;
        }
    }
    return name;
}

/* FUN_0049e160: which layer this name is.  A name no LAYER record left
   behind makes a further layer, which is what happens to a drawing from
   somewhere else whose layers the LAYER table did not name. */
static int layer_of(dxfr *r, const char *name)
{
    int i, at;

    name = layer_split(name, &at);
    for (i = 0; i < r->nlay; i++)
        if (!strcmp(name, r->lay[i].name))
            return i;
    if (r->nlay >= NLAYER)
        return 0;
    i = r->nlay++;
    copy_name(r->lay[i].name, name);
    r->lay[i].ltype = 0;
    r->lay[i].color = 0;
    return i;
}

/* ---------------------------------------------------------- the sections */

/* The extents, and the scale and middle they settle (FUN_004a2ce0). */
static void head(dxfr *r)
{
    double v[4];
    int i;

    while (r->code >= 0 && !is(r, 0, "ENDSEC")) {
        if (r->code == 9 && (!strcmp(r->str, "$EXTMIN")
                             || !strcmp(r->str, "$EXTMAX"))) {
            int max = r->str[5] == 'A';     /* $EXTMAX rather than $EXTMIN */
            double x = 0, y = 0;

            for (next(r); r->code >= 0 && r->code != 9 && r->code != 0;
                 next(r)) {
                if (r->code == 10)
                    x = r->num;
                if (r->code == 20)
                    y = r->num;
            }
            r->ext[max ? 2 : 0] = x;
            r->ext[max ? 3 : 1] = y;
            r->has_ext = 1;
            continue;
        }
        next(r);
    }
    if (!r->has_ext || (r->ext[0] == 0.0 && r->ext[2] == 0.0))
        return;
    for (i = 0; i < 4; i++)
        v[i] = r->ext[i];
    r->cx = (v[0] + v[2]) / 2.0;
    r->cy = (v[1] + v[3]) / 2.0;
    {
        /* how many millimetres of paper the drawing is asking for, rounded
           to a scale a person would have picked */
        double w = fabs(v[0] - v[2]) / (r->d->paper_hw * 2.0), dec, k;

        if (w < 0.11)
            r->scale = 0.1;
        else if (w < 0.16)
            r->scale = 0.125;
        else if (w < 0.22)
            r->scale = 0.2;
        else if (w < 0.4)
            r->scale = 0.25;
        else if (w < 0.7)
            r->scale = 0.5;
        else {
            dec = w < 9.0 ? 1.0 : w < 90.0 ? 10.0 : w < 900.0 ? 100.0
                : w < 9000.0 ? 1000.0 : w < 90000.0 ? 10000.0 : 100000.0;
            k = floor(w / dec + 0.5);
            if (k == 9.0)
                k = 8.0;
            if (k > 10.0)
                k = 10.0;
            r->scale = k * dec;
        }
    }
    for (i = 0; i < 16; i++)
        r->d->group[i].scale = r->scale;
}

/* The LTYPE table (FUN_004a3650). */
static void ltypes(dxfr *r)
{
    while (r->code >= 0 && !is(r, 0, "ENDSEC") && !is(r, 0, "ENDTAB")) {
        char name[NAME];
        double pat[11];
        int n = 0, seen = 0, i;

        if (!is(r, 0, "LTYPE")) {
            next(r);
            continue;
        }
        name[0] = 0;
        for (i = 0; i < 11; i++)
            pat[i] = 0.0;
        do {
            next(r);
            if (r->code == 2)
                copy_name(name, r->str);
            if (r->code == 0x49) {
                n = (int)r->num;
                if (n > 8)
                    n = 8;
            }
            if (r->code == 0x31 && ++seen < 9) {
                pat[seen] = fabs(r->num);
                if (pat[seen] == 0.0)
                    pat[seen] = 0.01;
            }
        } while (r->code > 0);
        /* an odd number of lengths: the last is folded into the first */
        if (n & 1) {
            pat[1] += pat[n];
            n--;
        }
        if (r->nlt < NLTYPE) {
            copy_name(r->lt[r->nlt].name, name);
            r->lt[r->nlt].code = ltype_match(r, n, pat);
            r->nlt++;
        }
    }
}

/* The LAYER table (FUN_004a40b0). */
static void layers(dxfr *r)
{
    while (r->code >= 0 && !is(r, 0, "ENDSEC") && !is(r, 0, "ENDTAB")) {
        if (!is(r, 0, "LAYER")) {
            next(r);
            continue;
        }
        if (r->nlay > 0xff)
            r->nlay = 0xff;
        do {
            next(r);
            if (r->code == 2) {
                int at;
                const char *nm = layer_split(r->str, &at);

                if (at >= 0)
                    r->nlay = at;
                copy_name(r->lay[r->nlay].name, nm);
            }
            if (r->code == 6)
                r->lay[r->nlay].ltype = ltype_of(r, r->str);
            if (r->code == 0x3e)
                r->lay[r->nlay].color = colour(r, (int)r->num, 0);
            if (r->code == 0x1a4)
                r->lay[r->nlay].color = colour(r, (int)r->num, 1);
        } while (r->code > 0);
        r->nlay++;
    }
}

static void tables(dxfr *r)
{
    while (r->code >= 0 && !is(r, 0, "ENDSEC")) {
        if (is(r, 0, "TABLE")) {
            next(r);
            if (is(r, 2, "LTYPE"))
                ltypes(r);
            else if (is(r, 2, "LAYER"))
                layers(r);
            continue;
        }
        next(r);
    }
}

/* --------------------------------------------------------- the entities */

/* What an entity ends up carrying: the line type and colour it named, or
   the ones its layer has, and which of the drawing's layers it lands on. */
typedef struct {
    int ltype, color, layer;
} attr;

static void attr_start(attr *a)
{
    a->ltype = -1;
    a->color = -1;
    a->layer = 0;
}

/* The four group codes every entity shares. */
static int attr_take(dxfr *r, attr *a)
{
    switch (r->code) {
    case 8: {
        int i = layer_of(r, r->str);

        a->layer = i;
        if (a->ltype == -1)
            a->ltype = r->lay[i].ltype;
        if (a->color == -1)
            a->color = r->lay[i].color;
        return 1;
    }
    case 6:
        a->ltype = ltype_of(r, r->str);
        return 1;
    case 0x3e:
        a->color = colour(r, (int)r->num, 0);
        return 1;
    case 0x1a4:
        a->color = colour(r, (int)r->num, 1);
        return 1;
    }
    return 0;
}

static jw_obj *place(dxfr *r, int cls, const attr *a)
{
    jw_obj *o = jw_add(r->d, cls);

    if (!o)
        return 0;
    /* a DXF that said nothing about either leaves the element the pen
       jw_add gave it, which is the one the document is writing with */
    if (a->ltype > 0)
        o->ltype = (unsigned char)a->ltype;
    if (a->color > 0)
        o->color = (unsigned short)a->color;
    o->width = 0;
    o->layer = (unsigned short)(a->layer & 0xf);
    o->lgroup = (unsigned short)((a->layer >> 4) & 0xf);
    return o;
}

static void ent_line(dxfr *r)
{
    double x[2] = { 0, 0 }, y[2] = { 0, 0 };
    jw_obj *o;
    attr a;

    attr_start(&a);
    for (next(r); r->code > 0; next(r)) {
        if (attr_take(r, &a))
            continue;
        switch (r->code) {
        case 10: x[0] = put_x(r, r->num); break;
        case 20: y[0] = put_y(r, r->num); break;
        case 11: x[1] = put_x(r, r->num); break;
        case 21: y[1] = put_y(r, r->num); break;
        }
    }
    o = place(r, JW_SEN, &a);
    if (o) {
        o->d[0] = x[0];
        o->d[1] = y[0];
        o->d[2] = x[1];
        o->d[3] = y[1];
    }
}

static void ent_arc(dxfr *r, int circle)
{
    double cx = 0, cy = 0, rad = 0, a0 = 0, sweep = 2.0 * PI;
    jw_obj *o;
    attr a;

    attr_start(&a);
    for (next(r); r->code > 0; next(r)) {
        if (attr_take(r, &a))
            continue;
        switch (r->code) {
        case 10: cx = put_x(r, r->num); break;
        case 20: cy = put_y(r, r->num); break;
        case 40: rad = put_l(r, r->num); break;
        case 0x32: a0 = r->num; break;
        case 0x33: {
            double s = r->num - a0;

            while (s > 360.0)
                s -= 360.0;
            while (s < 0.0)
                s += 360.0;
            sweep = s / 180.0 * PI;
            a0 = a0 / 180.0 * PI;
            break;
        }
        }
    }
    if (circle) {
        a0 = 0.0;
        sweep = 2.0 * PI;
    }
    /* the start angle comes back between -180 and 180 degrees: an arc the
       original wrote as starting at 270 is stored as -90 */
    while (a0 > PI)
        a0 -= 2.0 * PI;
    while (a0 < -PI)
        a0 += 2.0 * PI;
    o = place(r, JW_ENKO, &a);
    if (o) {
        o->d[0] = cx;
        o->d[1] = cy;
        o->d[2] = rad;
        o->d[3] = a0;
        o->d[4] = sweep;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        o->n = circle;          /* the whole-circle flag */
    }
}

static void ent_point(dxfr *r)
{
    double x = 0, y = 0;
    jw_obj *o;
    attr a;

    attr_start(&a);
    for (next(r); r->code > 0; next(r)) {
        if (attr_take(r, &a))
            continue;
        if (r->code == 10)
            x = put_x(r, r->num);
        if (r->code == 20)
            y = put_y(r, r->num);
    }
    o = place(r, JW_TEN, &a);
    if (o) {
        o->d[0] = x;
        o->d[1] = y;
    }
}

static void ent_solid(dxfr *r)
{
    double p[8];
    jw_obj *o;
    attr a;
    int i;

    for (i = 0; i < 8; i++)
        p[i] = 0.0;
    attr_start(&a);
    for (next(r); r->code > 0; next(r)) {
        if (attr_take(r, &a))
            continue;
        if (r->code >= 10 && r->code <= 13)
            p[(r->code - 10) * 2] = put_x(r, r->num);
        if (r->code >= 20 && r->code <= 23)
            p[(r->code - 20) * 2 + 1] = put_y(r, r->num);
    }
    o = place(r, JW_SOLID, &a);
    if (o) {
        /* the third and fourth corners the other way round again, which is
           how the original wrote them (src/dxf.c) */
        o->d[0] = p[0];
        o->d[1] = p[1];
        o->d[2] = p[2];
        o->d[3] = p[3];
        o->d[4] = p[6];
        o->d[5] = p[7];
        o->d[6] = p[4];
        o->d[7] = p[5];
    }
}

/* Anything that is not read yet: step over it to the next entity. */
static void ent_skip(dxfr *r)
{
    for (next(r); r->code > 0; next(r))
        ;
}

static void entities(dxfr *r)
{
    while (r->code >= 0 && !is(r, 0, "ENDSEC")) {
        if (r->code != 0) {
            next(r);
            continue;
        }
        if (!strcmp(r->str, "LINE"))
            ent_line(r);
        else if (!strcmp(r->str, "ARC"))
            ent_arc(r, 0);
        else if (!strcmp(r->str, "CIRCLE"))
            ent_arc(r, 1);
        else if (!strcmp(r->str, "POINT"))
            ent_point(r);
        else if (!strcmp(r->str, "SOLID"))
            ent_solid(r);
        else
            ent_skip(r);
    }
}

/* ------------------------------------------------------------------ read */

int jw_dxf_read(jw_drawing *d, const unsigned char *b, long n)
{
    dxfr *r = (dxfr *)calloc(1, sizeof *r);
    int i;

    if (!r)
        return 0;
    r->b = b;
    r->n = n;
    r->d = d;
    r->scale = d->group[0].scale;
    if (r->scale <= 0.0)
        r->scale = 1.0;
    for (i = 0; i < 10; i++)
        r->col[i] = d->print_rgb[i];
    for (i = 0; i <= 256; i++)
        r->col[100 + i] = d->xcolor[i];
    r->ncol = 100 + d->xcolor_n;

    /* what was drawn goes; the block definitions go with it */
    while (d->nobj > 0)
        jw_remove(d, d->nobj - 1);

    next(r);
    while (r->code >= 0) {
        if (is(r, 0, "EOF"))
            break;
        if (is(r, 0, "SECTION")) {
            next(r);
            if (is(r, 2, "HEADER"))
                head(r);
            else if (is(r, 2, "TABLES"))
                tables(r);
            else if (is(r, 2, "ENTITIES"))
                entities(r);
            continue;
        }
        next(r);
    }
    for (i = 0; i <= 256; i++)
        d->xcolor[i] = r->col[100 + i];
    d->xcolor_n = r->ncol - 100;
    /* the layer names the import settled on, for whoever writes the file */
    free(r);
    return 1;
}
