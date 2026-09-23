#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "cp932.h"

/* CArchive, reading.  Every read is bounds checked; a short file sets `bad`
 * and every later read returns zero, so the caller only has to test once. */
typedef struct {
    const unsigned char *b;
    long n, o;
    int bad;
} ar_t;

static const unsigned char *ar_raw(ar_t *a, long n)
{
    const unsigned char *p;

    if (a->bad || n < 0 || a->o + n > a->n) {
        a->bad = 1;
        return 0;
    }
    p = a->b + a->o;
    a->o += n;
    return p;
}

static unsigned ar_b(ar_t *a)
{
    const unsigned char *p = ar_raw(a, 1);
    return p ? p[0] : 0;
}

static unsigned ar_w(ar_t *a)
{
    const unsigned char *p = ar_raw(a, 2);
    return p ? (unsigned)p[0] | ((unsigned)p[1] << 8) : 0;
}

static int ar_l(ar_t *a)
{
    const unsigned char *p = ar_raw(a, 4);
    return p ? (int)((unsigned)p[0] | ((unsigned)p[1] << 8)
                     | ((unsigned)p[2] << 16) | ((unsigned)p[3] << 24)) : 0;
}

static double ar_d(ar_t *a)
{
    const unsigned char *p = ar_raw(a, 8);
    double v = 0.0;

    if (p)
        memcpy(&v, p, 8);       /* the file is little-endian IEEE, as we are */
    return v;
}

static void ar_skipd(ar_t *a, int n)
{
    while (n-- > 0)
        ar_d(a);
}

static void ar_skipl(ar_t *a, int n)
{
    while (n-- > 0)
        ar_l(a);
}

/* MFC's ReadStringLength: the count, and whether the text is UTF-16. */
static long ar_strlen(ar_t *a, int *unicode)
{
    unsigned n = ar_b(a);

    *unicode = 0;
    if (n < 0xff)
        return n;
    n = ar_w(a);
    if (n == 0xfffe) {
        *unicode = 1;
        n = ar_b(a);
        if (n < 0xff)
            return n;
        n = ar_w(a);
    }
    if (n == 0xffff)
        return (long)(unsigned)ar_l(a);
    return n;
}

/* A string in the pool is a flag byte, the CP932 text, and a NUL; the offset
   handed out points at the text, so the flag is the byte before it.  The flag
   says the file held it as UTF-16, which is how version 700 writes every
   string, and it has to go back out that way. */
static int pool_put(jw_drawing *d, const unsigned char *s, long n, int unicode)
{
    long need, m;
    int off;

    m = unicode ? jw_from_utf16((const unsigned short *)s, n, 0, 0) : n;
    need = m + 2;
    if (d->npool + need > d->cpool) {
        int c = d->cpool ? d->cpool * 2 : 4096;
        char *p;
        while (c < d->npool + need)
            c *= 2;
        p = (char *)realloc(d->pool, (size_t)c);
        if (!p)
            return -1;
        d->pool = p;
        d->cpool = c;
    }
    d->pool[d->npool++] = (char)unicode;
    off = d->npool;
    if (unicode)
        jw_from_utf16((const unsigned short *)s, n, d->pool + off, m);
    else
        memcpy(d->pool + off, s, (size_t)n);
    d->npool = off + (int)m;
    d->pool[d->npool++] = 0;
    return off;
}

static int ar_s(ar_t *a, jw_drawing *d)
{
    int unicode;
    long n = ar_strlen(a, &unicode);
    const unsigned char *p = ar_raw(a, unicode ? n * 2 : n);

    if (!p)
        return -1;
    return pool_put(d, p, n, unicode);
}

/* ---------------------------------------------------------------- header */

static void read_header(ar_t *a, jw_drawing *d)
{
    int v, g, l, i;

    d->version = v = ar_l(a);
    d->name = v > 0x40 ? ar_s(a, d) : -1;

    if (v > 9) {
        /* The sheet is an index, not a size: 0 is A0 and 4 is A4, and the
         * status line of the original spells it "A-3".  An earlier reading
         * took the last two doubles of the 0x3d block for the sheet's corner
         * because they are -297,-210 in Test1.jww -- which is the A2 corner,
         * but only by coincidence: they are zero in most drawings. */
        /* Straight out of the original's own tables, at 0x009ffbb8 (width)
         * and 0x009ffc58 (height), indexed by this very field: A0..A4, then
         * B4..B6, then 2A..5A, then the three metric rolls. */
        static const struct { double w, h; } SHEET[] = {
            { 1189, 841 }, { 841, 594 }, { 594, 420 }, { 420, 297 },
            { 297, 210 }, { 514, 364 }, { 364, 257 }, { 257, 182 },
            { 1682, 1189 }, { 2378, 1682 }, { 3364, 2378 }, { 4756, 3364 },
            { 10000, 7073 }, { 50000, 35366 }, { 100000, 70732 },
        };
        int n;
        d->paper_size = ar_l(a);
        n = d->paper_size;
        if (n < 0 || n >= (int)(sizeof SHEET / sizeof SHEET[0]))
            n = 2;
        d->paper_hw = SHEET[n].w / 2.0;
        d->paper_hh = SHEET[n].h / 2.0;
        ar_l(a);
        for (g = 0; g < 16; g++) {
            jw_group *gr = &d->group[g];
            gr->state = ar_l(a);
            gr->write_layer = ar_l(a);
            d->off_scale[g] = a->o;
            gr->scale = ar_d(a);
            gr->c = v > 0xd3 ? ar_l(a) : 0;
            for (l = 0; l < 16; l++) {
                gr->layer[l].state = ar_l(a);
                gr->layer[l].state2 = v > 0xd3 ? ar_l(a) : 0;
            }
        }
    }
    if (v > 0xd3) {
        ar_skipl(a, 1 + 13 + 5 + 1 + 1);
    }
    if (v > 0x3b)
        ar_skipd(a, 2);
    if (v > 0xc9) {
        ar_d(a);
        ar_l(a);
    }
    if (v > 0x3d) {
        ar_l(a);
        /* 目盛: the least spacing it will draw at, across, down, and where
           the grid starts.  See jw_drawing. */
        d->mesh_min = ar_d(a);
        d->mesh_ix = ar_d(a);
        d->mesh_iy = ar_d(a);
        d->mesh_ox = ar_d(a);
        d->mesh_oy = ar_d(a);
    }
    if (v > 0x3f) {
        d->off_names = a->o;
        for (g = 0; g < 16; g++)
            for (l = 0; l < 16; l++)
                d->group[g].layer_name[l] = ar_s(a, d);
        for (g = 0; g < 16; g++)
            d->group[g].name = ar_s(a, d);
        d->end_names = a->o;
    }
    if (v > 99) {
        ar_skipd(a, 2);
        ar_l(a);
    }
    if (v > 100) {
        ar_d(a);
        if (v > 299)
            ar_skipd(a, 2);
        ar_l(a);
    }
    if (v > 199) {
        ar_skipd(a, 6);
        if (v < 300) {
            ar_skipd(a, 12);
        } else {
            for (i = 0; i < 10; i++) {
                ar_skipd(a, 3);
                ar_l(a);
            }
        }
        ar_skipd(a, 11);
    }
    if (v > 200) {
        for (i = 0; i < 10; i++) {
            unsigned c = (unsigned)ar_l(a);
            /* COLORREF is 0x00bbggrr; the framebuffer wants 0x00rrggbb */
            d->pen_rgb[i] = ((c & 0xff) << 16) | (c & 0xff00)
                            | ((c >> 16) & 0xff);
            d->pen_width[i] = ar_l(a);
        }
        for (i = 0; i < 10; i++) {
            unsigned c = (unsigned)ar_l(a);
            d->print_rgb[i] = c;
            d->print_width[i] = ar_l(a);
            ar_d(a);
        }
        for (i = 2; i < 10; i++)
            ar_skipl(a, 4);
        for (i = 0xb; i < 0x10; i++)
            ar_skipl(a, 5);
        for (i = 0x10; i < 0x14; i++)
            ar_skipl(a, 4);
        ar_skipl(a, 2);
        if (v > 0xd8)
            ar_skipl(a, 9);
        if (v >= 0xdf) {
            ar_skipl(a, 5);
            ar_skipd(a, 5);
        }
        if (v >= 0xe1)
            ar_skipd(a, 4);
        if (v > 0xe1)
            ar_skipl(a, 2);
        if (v > 0x1a3) {
            d->off_ctab = a->o;
            for (i = 0; i < 0x101; i++) {     /* the 任意色 */
                d->xcolor[i] = (unsigned)ar_l(a);
                d->xcolor_rest[i].pair = ar_l(a);
            }
            /* Their names.  How many are in use is not a number in the file
               -- the ones that are have a name, and a DXF's colours are
               added after the last of them. */
            d->xcolor_n = 0;
            for (i = 0; i < 0x101; i++) {
                int name = ar_s(a, d);
                if (name >= 0 && jw_str(d, name)[0])
                    d->xcolor_n = i;
                d->xcolor_rest[i].name = name;
                d->xcolor_rest[i].rgb2 = (unsigned)ar_l(a);
                d->xcolor_rest[i].b = ar_l(a);
                d->xcolor_rest[i].w = ar_d(a);
            }
            d->end_ctab = a->o;
            for (i = 0; i < 0x21; i++)
                ar_skipl(a, 4);
            d->off_sxf = a->o;
            d->sxf_n = 0;
            for (i = 0; i < 0x21; i++) {      /* the 任意線種 */
                int j, name = ar_s(a, d);
                if (name >= 0 && jw_str(d, name)[0])
                    d->sxf_n = i;
                d->sxf[i].name = name;
                d->sxf[i].n = ar_l(a);
                for (j = 0; j < 10; j++)
                    d->sxf[i].pat[j + 1] = ar_d(a);
            }
            d->end_sxf = a->o;
        }
    }
    /* FUN_004eee80: the hatch and dimension settings, read from
     * CJw_winDoc::Serialize just before the object list. */
    if (v > 0x14) {
        /* the ten text styles, then the one in force */
        for (i = 0; i < 10; i++) {
            d->style[i].w = ar_d(a);
            d->style[i].h = ar_d(a);
            d->style[i].sp = ar_d(a);
            d->style[i].color = ar_l(a);
        }
        d->cur_style.w = ar_d(a);
        d->cur_style.h = ar_d(a);
        d->cur_style.sp = ar_d(a);
        d->cur_style.color = ar_l(a);
        ar_l(a);
        ar_skipd(a, 2);
    }
    if (v > 0xd5) {
        ar_l(a);
        ar_skipd(a, 6);
    }
}

/* --------------------------------------------------------------- objects */

static const struct {
    const char *name;
    int cls;
} CLASSES[] = {
    { "CDataSen",   JW_SEN   },
    { "CDataEnko",  JW_ENKO  },
    { "CDataTen",   JW_TEN   },
    { "CDataMoji",  JW_MOJI  },
    { "CDataSolid", JW_SOLID },
    { "CDataBlock",  JW_BLOCK },
    { "CDataList",   JW_LIST  },
};
#define NCLASSES ((int)(sizeof CLASSES / sizeof CLASSES[0]))

static jw_obj *obj_new(jw_drawing *d)
{
    if (d->nobj == d->cobj) {
        int c = d->cobj ? d->cobj * 2 : 256;
        jw_obj *p = (jw_obj *)realloc(d->obj, (size_t)c * sizeof *p);
        if (!p)
            return 0;
        d->obj = p;
        d->cobj = c;
    }
    memset(&d->obj[d->nobj], 0, sizeof d->obj[0]);
    d->obj[d->nobj].text = d->obj[d->nobj].face = -1;
    return &d->obj[d->nobj++];
}

static void read_base(ar_t *a, int v, jw_obj *o)
{
    if (v > 0x13)
        o->id = ar_l(a);
    o->ltype = (unsigned char)ar_b(a);
    o->color = (unsigned short)ar_w(a);
    if (v > 0x15e)
        o->width = (unsigned short)ar_w(a);
    o->layer = (unsigned short)ar_w(a);
    o->lgroup = (unsigned short)ar_w(a);
    if (v > 0x13)
        o->flags = (unsigned short)ar_w(a);
}

/* CArchive numbers classes and objects together as it reads, and a
   definition's own list is read in the middle of the list that holds it, so
   the numbering is one run through the lot.  This is that run. */
typedef struct {
    short *load;                /* -1 for an object, the class for a class */
    int n, max;                 /* how many, and how many the array holds  */
} lctx;

/* Room for one more entry in the numbering.  It grows because there is no
   bound on it: a drawing of a hundred thousand elements numbers every one. */
static int lctx_room(lctx *L)
{
    if (L->n >= L->max) {
        int c = L->max ? L->max * 2 : 4096;
        short *p = (short *)realloc(L->load, (size_t)c * sizeof *p);

        if (!p)
            return 0;
        L->load = p;
        L->max = c;
    }
    return 1;
}

static void read_objs(ar_t *a, jw_drawing *d, lctx *L, long n);

static void read_body(ar_t *a, jw_drawing *d, int v, jw_obj *o, lctx *L)
{
    int i;

    switch (o->cls) {
    case JW_SEN:
        for (i = 0; i < 4; i++)
            o->d[i] = ar_d(a);
        break;
    case JW_ENKO:
        for (i = 0; i < 7; i++)
            o->d[i] = ar_d(a);
        o->n = ar_l(a);
        break;
    case JW_TEN:
        o->d[0] = ar_d(a);
        o->d[1] = ar_d(a);
        if (v > 0x15)
            o->n = ar_l(a);
        if (v == 0xfc || (v > 299 && o->ltype == 100)) {
            o->mark = ar_l(a);
            o->turn = ar_d(a);
            o->size = ar_d(a);
        }
        break;
    case JW_MOJI:
        for (i = 0; i < 4; i++)
            o->d[i] = ar_d(a);
        if (v > 0x13)
            o->n = ar_l(a);
        o->d[4] = ar_d(a);
        o->d[5] = ar_d(a);
        if (v > 0x13)
            o->d[6] = ar_d(a);
        o->d[7] = ar_d(a);
        if (v > 0x27)
            o->face = ar_s(a, d);
        o->text = ar_s(a, d);
        break;
    case JW_SOLID:
        for (i = 0; i < 8; i++)
            o->d[i] = ar_d(a);
        if (o->color == 10)
            o->n = ar_l(a);
        break;
    case JW_BLOCK:
        /* CDataBlock::Serialize (0x0049b2c0): where it sits, how big it is
           each way, which way round, and which definition it stands for */
        for (i = 0; i < 5; i++)
            o->d[i] = ar_d(a);
        o->block = ar_l(a);
        break;
    case JW_LIST: {
        /* CDataList::Serialize (0x0049b410): three numbers, a name, and
           then the elements of the definition itself.  They are kept in the
           same array, straight after this one, and o->n says how many. */
        int at = (int)(o - d->obj);
        long m;

        for (i = 0; i < 3; i++)
            o->list[i] = ar_l(a);
        o->text = ar_s(a, d);
        m = ar_w(a);
        if (m == 0xffff)
            m = (long)(unsigned)ar_l(a);
        read_objs(a, d, L, m);
        d->obj[at].n = (int)m;
        break;
    }
    }
}

/* CObList::Serialize, then CArchive's tagged objects.  Classes and objects
 * share one numbering: 0xffff introduces a class, 0x8000 refers back to one,
 * anything else refers back to an object already read.  `n` of -1 means the
 * count has not been read yet, which is how a definition's own list comes.
 *
 * Past 0x3ffe entries MFC cannot say the number in a word any more, so it
 * writes 0x7fff and then a long, with 0x80000000 on it for a class
 * (CArchive::ReadObject's wBigObjectTag).  A drawing has to be fairly large
 * before that happens -- none of the fifteen samples gets there, and the
 * first one to hand that did was an SFC import of 84,645 elements, which
 * this reader used to give up on. */
static void read_objs(ar_t *a, jw_drawing *d, lctx *L, long n)
{
    int i;

    if (n < 0) {
        n = ar_w(a);
        if (n == 0xffff)
            n = (long)(unsigned)ar_l(a);
    }
    for (i = 0; i < n && !a->bad; i++) {
        unsigned tag = ar_w(a);
        unsigned long big = 0;
        int isclass, cls = -1;
        jw_obj *o;

        if (tag == 0)
            continue;
        if (tag == 0x7fff) {
            big = (unsigned long)(unsigned)ar_l(a);
            isclass = (big & 0x80000000UL) != 0;
            big &= 0x7fffffffUL;
        } else {
            isclass = (tag & 0x8000) != 0;
            big = tag & 0x7fff;
        }
        if (tag == 0xffff) {
            unsigned len;
            const unsigned char *nm;
            int k;
            unsigned schema = (unsigned)ar_w(a);
            len = ar_w(a);
            nm = ar_raw(a, (long)len);
            if (!nm)
                break;
            for (k = 0; k < NCLASSES; k++)
                if (strlen(CLASSES[k].name) == len
                    && !memcmp(CLASSES[k].name, nm, len))
                    cls = CLASSES[k].cls;
            if (cls < 0) {
                /* Say which one: the reader knows the five element classes
                 * the shipped drawings use, but a real drawing can also hold
                 * dimensions (CDataSunpou), blocks and 3D elements, and
                 * those are nested objects this does not walk yet. */
                static char why[64];
                unsigned k = len < 40 ? len : 40;
                memcpy(why, "unknown element class ", 22);
                memcpy(why + 22, nm, k);
                why[22 + k] = 0;
                d->error = why;
                a->bad = 1;
                break;
            }
            if (cls >= 0 && cls < JW_NCLASS)
                d->schema[cls] = (unsigned short)schema;
            if (!lctx_room(L)) {
                a->bad = 1;
                break;
            }
            L->load[L->n++] = (short)cls;
        } else if (isclass) {
            unsigned long ix = big;
            if (ix >= (unsigned long)L->n) {
                a->bad = 1;
                break;
            }
            cls = L->load[ix];
        } else {
            continue;           /* a second reference to an object we have */
        }
        if (!lctx_room(L)) {
            a->bad = 1;
            break;
        }
        L->load[L->n++] = -1;
        o = obj_new(d);
        if (!o) {
            a->bad = 1;
            break;
        }
        o->cls = (unsigned char)cls;
        read_base(a, d->version, o);
        read_body(a, d, d->version, o, L);
    }
}

/* The numbering runs through the whole file, not through one list: the
   block definitions refer back to a class the drawing itself introduced. */
static lctx *lctx_new(void)
{
    lctx *L = (lctx *)malloc(sizeof *L);

    if (!L)
        return 0;
    L->load = 0;
    L->n = 1;                   /* the numbering is one based */
    L->max = 0;
    if (!lctx_room(L)) {
        free(L);
        return 0;
    }
    L->load[0] = -1;
    return L;
}

static void lctx_free(lctx *L)
{
    if (L) {
        free(L->load);
        free(L);
    }
}

/* The defaults are CData's constructor, FUN_0041f2d0 in the original:
 *
 *     +0x28 = 1            line type, 実線
 *     +0x2a = 2            colour
 *     +0x2c = 0            width
 *     +0x2e = doc[0x24ec + doc[0x256c] * 4]     the write layer
 *     +0x2f = doc[0x256c]                       the write layer group
 *
 * A command then puts its own pen over the first two before it hands the
 * element to the document; where that pen is kept has not been traced yet,
 * so what comes out here is the constructor's.
 */
jw_obj *jw_add(jw_drawing *d, int cls)
{
    jw_obj *o = obj_new(d);
    int g, wg = 0;

    if (!o)
        return 0;
    /* obj_new appends; the drawn elements come before the block definitions,
       so move it up if there are any */
    if (d->nobj - 1 > d->ndrawn) {
        jw_obj tmp = *o;
        memmove(&d->obj[d->ndrawn + 1], &d->obj[d->ndrawn],
                (size_t)(d->nobj - 1 - d->ndrawn) * sizeof *o);
        d->obj[d->ndrawn] = tmp;
        o = &d->obj[d->ndrawn];
    }
    d->ndrawn++;
    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    o->cls = (unsigned char)cls;
    o->ltype = d->write_ltype ? d->write_ltype : 1;
    o->color = d->write_ltype ? d->write_color : 2;
    o->width = d->write_ltype ? d->write_width : 0;
    o->layer = (unsigned short)(d->group[wg].write_layer & 15);
    o->lgroup = (unsigned short)wg;
    o->flags = 0;
    o->text = o->face = -1;
    return o;
}

void jw_obj_box(const jw_obj *o, double *x0, double *y0,
                double *x1, double *y1)
{
    switch (o->cls) {
    case JW_ENKO: {
        /* the whole circle the arc belongs to: the flattening at +6 makes
           an ellipse, and the wider of the two half axes is the reach */
        double a = o->d[2], b = o->d[6] > 0.0 ? o->d[2] * o->d[6] : o->d[2];
        if (b > a)
            a = b;
        *x0 = o->d[0] - a;
        *y0 = o->d[1] - a;
        *x1 = o->d[0] + a;
        *y1 = o->d[1] + a;
        return;
    }
    case JW_TEN:
        *x0 = *x1 = o->d[0];
        *y0 = *y1 = o->d[1];
        return;
    case JW_SOLID: {
        int i;
        if (o->ltype == 101) {  /* a 円ソリッド: a circle's box */
            double a = o->d[2];
            *x0 = o->d[0] - a;
            *y0 = o->d[1] - a;
            *x1 = o->d[0] + a;
            *y1 = o->d[1] + a;
            return;
        }
        *x0 = *x1 = o->d[0];
        *y0 = *y1 = o->d[1];
        for (i = 1; i < 4; i++) {
            double px = o->d[i * 2], py = o->d[i * 2 + 1];
            if (px < *x0) *x0 = px;
            if (px > *x1) *x1 = px;
            if (py < *y0) *y0 = py;
            if (py > *y1) *y1 = py;
        }
        return;
    }
    default:                    /* a line, and a text by its two ends */
        *x0 = o->d[0] < o->d[2] ? o->d[0] : o->d[2];
        *x1 = o->d[0] < o->d[2] ? o->d[2] : o->d[0];
        *y0 = o->d[1] < o->d[3] ? o->d[1] : o->d[3];
        *y1 = o->d[1] < o->d[3] ? o->d[3] : o->d[1];
        return;
    }
}

void jw_obj_move(jw_obj *o, double dx, double dy)
{
    int i;

    switch (o->cls) {
    case JW_ENKO:
    case JW_TEN:
        o->d[0] += dx;
        o->d[1] += dy;
        return;
    case JW_SOLID:
        if (o->ltype == 101) {  /* a 円ソリッド moves by its centre */
            o->d[0] += dx;
            o->d[1] += dy;
            return;
        }
        for (i = 0; i < 4; i++) {
            o->d[i * 2] += dx;
            o->d[i * 2 + 1] += dy;
        }
        return;
    default:
        o->d[0] += dx;
        o->d[1] += dy;
        o->d[2] += dx;
        o->d[3] += dy;
        return;
    }
}

/* Scale about (cx, cy) by `sc`, turn by `ang` radians, then shift by
 * (dx, dy).  This is what 複写 and 移動 do with the bar's 倍率 and 回転角:
 * the original's copy of a rectangle at 倍率 2, 回転角 30 came out exactly
 * at  click + R(30) * 2 * (point - 基準点), to four decimals.
 *
 * A circle carries its own start angle and tilt, so those turn with it and
 * its radius takes the scale; a text turns about its own start.
 */
void jw_obj_xform(jw_obj *o, double cx, double cy, double sc, double ang,
                  double dx, double dy)
{
    double c = cos(ang), s = sin(ang);
    int i, n;

    switch (o->cls) {
    case JW_ENKO: n = 1; break;
    case JW_TEN:  n = 1; break;
    /* a 円ソリッド has a centre where the others have four corners */
    case JW_SOLID: n = o->ltype == 101 ? 1 : 4; break;
    default: n = 2; break;
    }
    for (i = 0; i < n; i++) {
        double x = (o->d[i * 2] - cx) * sc, y = (o->d[i * 2 + 1] - cy) * sc;

        o->d[i * 2] = cx + x * c - y * s + dx;
        o->d[i * 2 + 1] = cy + x * s + y * c + dy;
    }
    if (o->cls == JW_ENKO) {
        o->d[2] *= sc;          /* the radius */
        o->d[3] += ang;         /* where the arc starts */
        o->d[5] += ang;         /* and which way it leans */
    } else if (o->cls == JW_MOJI) {
        o->d[4] *= sc;          /* the size and the spacing */
        o->d[5] *= sc;
        o->d[6] *= sc;
    }
}

/* Mirror about the line through (px, py) along the unit vector (ux, uy) --
 * 複写・移動's 反転, which asks for a 基準線 and flips the selection across
 * it.  A rectangle mirrored about a upright line in the original came back
 * with every corner across it and the ends of each line still in their own
 * order, which is what mirroring each point in place does.
 *
 * An arc's start angle goes to twice the line's angle less its far end, and
 * its sweep keeps its sign, so it covers the same points the other way
 * round; the tilt of an ellipse turns the same way.
 */
void jw_obj_mirror(jw_obj *o, double px, double py, double ux, double uy)
{
    double phi = atan2(uy, ux);
    int i, n;

    switch (o->cls) {
    case JW_ENKO: n = 1; break;
    case JW_TEN:  n = 1; break;
    /* a 円ソリッド has a centre where the others have four corners */
    case JW_SOLID: n = o->ltype == 101 ? 1 : 4; break;
    default: n = 2; break;
    }
    for (i = 0; i < n; i++) {
        double x = o->d[i * 2] - px, y = o->d[i * 2 + 1] - py;
        double t = x * ux + y * uy;

        o->d[i * 2] = px + 2 * t * ux - x;
        o->d[i * 2 + 1] = py + 2 * t * uy - y;
    }
    if (o->cls == JW_ENKO) {
        double sweep = o->d[4] == 0.0 ? 0.0 : o->d[4];

        o->d[3] = 2 * phi - (o->d[3] + sweep);
        o->d[5] = 2 * phi - o->d[5];
    } else if (o->cls == JW_MOJI) {
        /* 文字方向補正無 is what the left button asks for, so the text goes
           with the flip as it is */
    }
}

jw_obj *jw_add_def(jw_drawing *d, int cls)
{
    jw_obj *o = obj_new(d);

    if (!o)
        return 0;
    o->cls = (unsigned char)cls;
    o->ltype = 1;
    o->color = 1;
    o->text = o->face = -1;
    return o;
}

void jw_remove(jw_drawing *d, int i)
{
    if (i < 0 || i >= d->nobj)
        return;
    memmove(&d->obj[i], &d->obj[i + 1],
            (size_t)(d->nobj - 1 - i) * sizeof d->obj[0]);
    d->nobj--;
    if (i < d->ndrawn)
        d->ndrawn--;
}

int jw_parse(jw_drawing *d, const unsigned char *b, long n)
{
    ar_t a;
    const unsigned char *sig;

    memset(d, 0, sizeof *d);
    d->off_names = d->end_names = -1;
    d->off_ctab = d->end_ctab = -1;
    d->off_sxf = d->end_sxf = -1;
    a.b = b;
    a.n = n;
    a.o = 0;
    a.bad = 0;

    sig = ar_raw(&a, 8);
    if (!sig || memcmp(sig, "JwwData.", 8)) {
        d->error = "not a .jww";
        return 0;
    }
    read_header(&a, d);
    /* everything up to here goes back out untouched when the drawing is
       saved: the reader understands only part of it */
    d->nhead = a.o;
    d->head = (unsigned char *)malloc((size_t)d->nhead);
    if (d->head)
        memcpy(d->head, b, (size_t)d->nhead);
    {
        lctx *L = lctx_new();

        if (!L) {
            d->error = "out of memory";
            return 0;
        }
        read_objs(&a, d, L, -1);
        d->ndrawn = d->nobj;
        if (d->version > 0x13)
            read_objs(&a, d, L, -1);    /* the block definitions */
        lctx_free(L);
    }
    if (d->version > 0x275) {
        /* Jw_cad 10 writes version 700, and after the two lists it puts the
         * embedded image files: a count, then that many names, each unpacked
         * into %temp% (FUN_00575010, the arm guarded by 0x275 < version).
         * Every drawing to hand has none of them, and what one of those
         * records holds has not been read out of the binary, so rather than
         * guess at it the parse stops. */
        d->nimage = ar_l(&a);
        if (d->nimage != 0 && !a.bad) {
            d->error = "the drawing has embedded images, which are not read yet";
            return 0;
        }
    }
    if (a.bad) {
        if (!d->error)
            d->error = "the file ends in the middle of a record";
        return 0;
    }
    if (a.o != n) {
        d->error = "the parse did not land on the end of the file";
        return 0;
    }
    return 1;
}

int jw_add_str(jw_drawing *d, const char *s)
{
    long n = 0;
    const char *p = s;

    while (*p++)
        n++;
    return pool_put(d, (const unsigned char *)s, n, 0);
}

int jw_round_solid(const jw_obj *o, jw_obj *arc)
{
    if (o->cls != JW_SOLID || o->ltype != 101)
        return 0;
    *arc = *o;
    arc->cls = JW_ENKO;
    arc->ltype = 1;
    arc->d[0] = o->d[0];        /* the centre */
    arc->d[1] = o->d[1];
    arc->d[2] = o->d[2];        /* the radius */
    arc->d[3] = o->d[5];        /* where it starts */
    arc->d[4] = o->d[6];        /* how far it goes */
    arc->d[5] = o->d[4];        /* the turn */
    arc->d[6] = o->d[3] > 0.0 ? o->d[3] : 1.0;      /* how flat */
    arc->d[7] = 0.0;
    return 1;
}

int jw_text_drawn(const jw_obj *o)
{
    return o->cls != JW_MOJI || o->d[0] != o->d[2] || o->d[1] != o->d[3];
}

const char *jw_str(const jw_drawing *d, int off)
{
    return off < 0 ? "" : d->pool + off;
}

int jw_str_wide(const jw_drawing *d, int off)
{
    return off > 0 ? d->pool[off - 1] : 0;
}

void jw_free(jw_drawing *d)
{
    free(d->head);
    d->head = 0;
    free(d->obj);
    free(d->pool);
    memset(d, 0, sizeof *d);
}
