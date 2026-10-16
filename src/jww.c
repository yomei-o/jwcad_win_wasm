#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jww.h"
#include "gen/pens.h"
#include "cp932.h"
#include "image.h"

/* CArchive, reading.  Every read is bounds checked; a short file sets `bad`
 * and every later read returns zero, so the caller only has to test once. */
typedef struct {
    const unsigned char *b;
    long n, o;
    int bad;
    int fig;                    /* reading a 図形 (.jws) rather than a .jww */
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
    unsigned char *own = 0;

    /* the text may be one that is in the pool already (a copy of a string): the pool
       moves when it grows, so take it out first */
    if (d->pool && n > 0 && (const char *)s >= d->pool && (const char *)s < d->pool + d->cpool) {
        own = (unsigned char *)malloc((size_t)n);
        if (!own)
            return -1;
        memcpy(own, s, (size_t)n);
        s = own;
    }
    m = unicode ? jw_from_utf16(s, n, 0, 0) : n;
    need = m + 2;
    if (d->npool + need > d->cpool) {
        int c = d->cpool ? d->cpool * 2 : 4096;
        char *p;
        while (c < d->npool + need)
            c *= 2;
        p = (char *)realloc(d->pool, (size_t)c);
        if (!p) {
            free(own);
            return -1;
        }
        d->pool = p;
        d->cpool = c;
    }
    d->pool[d->npool++] = (char)unicode;
    off = d->npool;
    if (unicode)
        jw_from_utf16(s, n, d->pool + off, m);
    else
        memcpy(d->pool + off, s, (size_t)n);
    d->npool = off + (int)m;
    d->pool[d->npool++] = 0;
    free(own);
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

/* The sheet sizes, straight out of the original's own tables at 0x009ffbb8
 * (width) and 0x009ffc58 (height), indexed by the number the header keeps:
 * A0..A4, then B4..B6, then 2A..5A, then the three metric rolls.
 */
void jw_paper_set(jw_drawing *d, int n)
{
    static const struct { double w, h; } SHEET[] = {
        { 1189, 841 }, { 841, 594 }, { 594, 420 }, { 420, 297 },
        { 297, 210 }, { 514, 364 }, { 364, 257 }, { 257, 182 },
        { 1682, 1189 }, { 2378, 1682 }, { 3364, 2378 }, { 4756, 3364 },
        { 10000, 7073 }, { 50000, 35366 }, { 100000, 70732 },
    };
    int k = n;

    d->paper_size = n;
    if (k < 0 || k >= (int)(sizeof SHEET / sizeof SHEET[0]))
        k = 2;
    d->paper_hw = SHEET[k].w / 2.0;
    d->paper_hh = SHEET[k].h / 2.0;
}

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
        d->off_paper = a->o;
        jw_paper_set(d, ar_l(a));
        ar_l(a);
        for (g = 0; g < 16; g++) {
            jw_group *gr = &d->group[g];
            d->off_group[g] = a->o;
            gr->state = ar_l(a);
            gr->write_layer = ar_l(a);
            d->off_scale[g] = a->o;
            gr->scale = ar_d(a);
            gr->c = v > 0xd3 ? ar_l(a) : 0;
            d->off_layer[g] = a->o;
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
        int mm = ar_l(a);

        if (mm < 0)
            mm = -(mm + 1);     /* -v-1、INT_MIN でもあふれない形で */
        if (mm >= 10)
            mm -= 10;
        d->mesh_mode = mm;
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
            unsigned rgb = ((c & 0xff) << 16) | (c & 0xff00)
                           | ((c >> 16) & 0xff);
            int w = ar_l(a);

            /* **The tenth is the grey, not pen 9.**  CMiniDoc's reader
               puts this one in slot 13 (`if (i == 9) k = 0xd;`), which
               is the 色・画面 page's グレー row.  Pen 9 keeps what the
               settings hold -- the original's own window shows ff80ff
               for it (tools/probe149.sh, button 1120) while its グレー
               row shows the c0c0c0 that is in the file. */
            if (i == 9) {
                d->gray_rgb = rgb;
                d->gray_width = w;
            } else {
                d->pen_rgb[i] = rgb;
                d->pen_width[i] = w;
            }
        }
        d->pen_rgb[9] = jw_default_pen_rgb[9];
        d->pen_width[9] = jw_default_pen_width[9];
        for (i = 0; i < 10; i++) {
            unsigned c = (unsigned)ar_l(a);
            d->print_rgb[i] = c;
            d->print_width[i] = ar_l(a);
            /* and a double each: the point radius in millimetres that
               FUN_00424200 would draw a 仮点 with (doc+0x6948).  Not used
               yet -- see "仮点の形" in docs/notes-pixels.md. */
            ar_d(a);
        }
        /* 線種 2..9・ランダム線 11..15・倍長線種 16..19 の表。原典の読み手
           （CMiniDoc の Serialize、DAT_00a0cab0 = Pen\File が立てば
           doc+0x2fc4.. に入れる）と同じ並び: パターン・単位・画面ピッチ・
           プリンタピッチ、ランダム線は パターン・振れ幅・画面ピッチ・
           プリンタの振れ幅・プリンタピッチ。効かせるのは src/draw.c の
           jw_ltype_from（開いたとき、src/app.c） */
        for (i = 2; i < 0x14; i++) {
            if (i == 10)
                continue;
            d->lt[i].pat = (unsigned)ar_l(a);
            if (i >= 0xb && i < 0x10) {
                d->lt[i].ran = ar_l(a);
                d->lt[i].pitch = ar_l(a);
                d->lt[i].prran = ar_l(a);
            } else {
                d->lt[i].unit = ar_l(a);
                d->lt[i].pitch = ar_l(a);
            }
            d->lt[i].prpit = ar_l(a);
        }
        d->lt_have = 1;
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
    { "CDataSunpou", JW_SUNPOU },
    { "CData3DSen",   JW_3DSEN   },
    { "CData3DEnko",  JW_3DENKO  },
    { "CData3DSolid", JW_3DSOLID },
};
#define NCLASSES ((int)(sizeof CLASSES / sizeof CLASSES[0]))

static jw_obj *obj_new(jw_drawing *d)
{
#ifdef JW_ALWAYS_MOVE
    /* A debugging build (tools/asanone.sh with JW_MOVE=1): the element array
       is moved to a fresh block on every addition and the old one freed, so a
       pointer into it that is kept across a jw_add / obj_new is a use after
       free that AddressSanitizer reports at once, rather than a crash only
       when the array happens to cross a power of two. */
    if (d->obj && d->cobj > 0) {
        int c = d->nobj == d->cobj ? d->cobj * 2 : d->cobj;
        jw_obj *p = (jw_obj *)malloc((size_t)c * sizeof *p);

        if (!p)
            return 0;
        memcpy(p, d->obj, (size_t)d->nobj * sizeof *p);
        free(d->obj);
        d->obj = p;
        d->cobj = c;
    }
#endif
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
static void read_body(ar_t *a, jw_drawing *d, int v, jw_obj *o, lctx *L);

/* CDataSunpou::Serialize (0x0042f110): the figure's own CData fields, then
   its parts' Serialize one after another with no class tags between them --
   CDataSen (the dimension line, +0x68), CDataMoji (the value, +0xd0) and,
   past version 419, a ushort and CDataSen, CDataSen, CDataTen x4.  The
   second group is not in the order of their addresses (0x230 and 0x318 are
   last), which is what the decompilation says and what the sample the
   original wrote (decomp/res/p169_dimfig.jww) bears out to the byte.

   What they are is read off the sizes (0x68 is a CDataSen, 0xd0 a CDataMoji,
   0x80 a CDataTen) and off that sample, where the four last come out as
   four 35-byte points and the next object's class tag is where it ends. */
static const unsigned char SUN_CLS[8] = {
    JW_SEN, JW_MOJI, JW_SEN, JW_SEN, JW_TEN, JW_TEN, JW_TEN, JW_TEN
};

static void read_sunpou(ar_t *a, jw_drawing *d, lctx *L)
{
    jw_obj head;
    int v = d->version, nm = v > 0x1a3 ? 8 : 2, k, first = d->nobj;
    unsigned short us = 0;

    memset(&head, 0, sizeof head);
    head.text = head.face = -1;
    read_base(a, v, &head);
    for (k = 0; k < nm && !a->bad; k++) {
        jw_obj *o;

        if (k == 2)
            us = (unsigned short)ar_w(a);
        o = obj_new(d);
        if (!o) {
            a->bad = 1;
            break;
        }
        o->cls = SUN_CLS[k];
        read_base(a, v, o);
        read_body(a, d, v, o, L);
        o->sub = (unsigned char)(k + 1);
        {
            int q;
            for (q = 0; q < 8; q++)
                if (!(o->d[q] > -1e12 && o->d[q] < 1e12)) {
                    d->error = "a coordinate that cannot be";
                    a->bad = 1;
                    break;
                }
        }
        if (k == 0) {
            /* the figure's own CData fields ride on the first part */
            o->list[0] = us;
            o->list[1] = head.id;
            o->list[2] = (int)((unsigned)head.flags
                               | ((unsigned)head.layer << 16));
            o->mark = (int)((unsigned)head.ltype | ((unsigned)head.color << 8)
                            | ((unsigned)(head.lgroup & 0xff) << 24));
            o->turn = head.width;
        }
    }
    if (nm > 2 && d->nobj > first)
        d->obj[first].list[0] = us;   /* the ushort is read after part two */
}

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
        /* The original brings the start angle into (-pi, pi], and marks a
           whole circle as one, as it reads a **drawing**.  tools/mkgeom.c
           writes an arc starting at 3pi/2; every file the original has
           written from it since -- decomp/res/zhlayer.jww and
           decomp/res/figreg.jws both -- carries -pi/2 there instead, to the
           bit, so it is one subtraction rather than an atan2 (pi itself is
           left alone, and the sweep is never touched).  The flag is the one
           at +0x90 of CDataEnko, which makes the drawing code take the sweep
           as 2pi whatever it says; mkgeom leaves it at 0 on an arc that goes
           all the way round and the original's own copy has it at 1.

           **Not on a figure.**  CDataEnko::Serialize (0x0042e7f0) reads its
           seven doubles and the flag and touches none of them, so neither of
           these is part of the record itself: they are a pass over what was
           just loaded, and the 341 figures Jw_cad ships are the evidence
           that a .jws does not get it -- 106 of them carry an angle outside
           (-pi, pi] or a 2pi sweep with the flag at 0, and with this left
           alone every one of the 341 is written back byte for byte.  Where
           exactly the drawing gets its pass is still not found (it is not in
           CJw_winDoc::Serialize either); until it is, this is what the files
           say. */
        /* A damaged file can carry 1e300 in an angle, and the walk below
           steps one turn at a time -- which would take longer than the
           machine will live.  Nothing the original writes is more than a
           turn or two out, so this far out means the record was read with
           the wrong shape and the rest of the file is guesswork anyway.
           (tests/fuzz_test.c found this by handing the reader a drawing
           with one byte changed.) */
        if (!(o->d[3] > -1e6 && o->d[3] < 1e6)
            || !(o->d[4] > -1e6 && o->d[4] < 1e6)) {
            d->error = "an arc with an angle that cannot be";
            a->bad = 1;
            break;
        }
        if (!a->fig) {
            while (o->d[3] > 3.141592653589793)
                o->d[3] -= 6.283185307179586;
            while (o->d[3] <= -3.141592653589793)
                o->d[3] += 6.283185307179586;
            if (o->d[4] >= 6.283185307179586 || o->d[4] <= -6.283185307179586)
                o->n = 1;
        }
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
    case JW_3DSEN:
        for (i = 0; i < 6; i++)
            o->d[i] = ar_d(a);
        break;
    case JW_3DENKO:
        for (i = 0; i < 7; i++)
            o->d[i] = ar_d(a);
        break;
    case JW_3DSOLID:
        for (i = 0; i < 8; i++)
            o->d[i] = ar_d(a);
        for (i = 0; i < 4; i++)
            o->e[i] = ar_d(a);
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
        if (cls == JW_SUNPOU) {
            read_sunpou(a, d, L);
            continue;
        }
        o = obj_new(d);
        if (!o) {
            a->bad = 1;
            break;
        }
        o->cls = (unsigned char)cls;
        read_base(a, d->version, o);
        {   /* a definition reads its own elements inside read_body, which can move
               the array: find this one again by its place afterwards */
            int oi = (int)(o - d->obj);

            read_body(a, d, d->version, o, L);
            o = &d->obj[oi];
        }
        /* A damaged file can leave 1e300 in a coordinate, and the writers
           put coordinates through printf's %f into buffers of a couple of
           hundred bytes -- 1e300 is three hundred and nine digits, and the
           first thing it overruns is the stack.  Nothing a drawing holds is
           anywhere near this; a number this big means the record was read
           with the wrong shape.  (tests/fuzz_test.c found it by writing
           every damaged drawing back out again.) */
        {
            int k;
            for (k = 0; k < 12; k++) {
                double x = k < 8 ? o->d[k] : o->e[k - 8];
                if (!(x > -1e12 && x < 1e12)) {
                    d->error = "a coordinate that cannot be";
                    a->bad = 1;
                    break;
                }
            }
        }
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
        if ((o->ltype == 101 || o->ltype == 111)) {  /* a 円ソリッド: a circle's box */
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
    /* ブロックの参照は基点 d[0],d[1] だけ。d[2],d[3] は倍率、d[4] は角
       （原典の移動 FUN_0046bdf0 の CDataBlock の枝 FUN_0046ba40 は +0x68・
       +0x70 の基点だけを動かす。逆コンパイルの読み、原典では押していない） */
    case JW_BLOCK:
        o->d[0] += dx;
        o->d[1] += dy;
        return;
    case JW_SOLID:
        if ((o->ltype == 101 || o->ltype == 111)) {  /* a 円ソリッド moves by its centre */
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
    case JW_BLOCK: n = 1; break;    /* 基点だけ。倍率と角は下で */
    /* a 円ソリッド has a centre where the others have four corners */
    case JW_SOLID: n = (o->ltype == 101 || o->ltype == 111) ? 1 : 4; break;
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
    } else if (o->cls == JW_BLOCK) {
        /* CDataBlock (Serialize 0x0049b2c0): d[0],d[1] 基点 (+0x68,+0x70)、
           d[2],d[3] 倍率 x・y (+0x78,+0x80)、d[4] 角 (+0x88)。原典の倍率
           FUN_00465c40 の CDataBlock の枝 FUN_00464870 は基点を写して
           +0x78・+0x80 に倍率を掛け、回転 FUN_0046d5b0 の枝 FUN_0046d050 は
           +0x88 に角を足して基点を回す。逆コンパイルの読み、原典では押して
           いない */
        o->d[2] *= sc;
        o->d[3] *= sc;
        o->d[4] += ang;
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
    case JW_BLOCK: n = 1; break;    /* 基点だけ。倍率と角は下で */
    /* a 円ソリッド has a centre where the others have four corners */
    case JW_SOLID: n = (o->ltype == 101 || o->ltype == 111) ? 1 : 4; break;
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
    } else if (o->cls == JW_BLOCK) {
        /* 原典の反転は 倍率の関数で裏返す。FUN_00653fe0 は基準線の角を
           (-90°,90°] に寄せ、45° 未満なら その角 a で 倍率 (1,-1)、でなければ
           a = 角∓90° で (-1,1) にして（+0xfca8・+0xfcb0・+0xfcc0）、
           FUN_00653e10 → 倍率 FUN_00465c40 → CDataBlock の枝 FUN_00464870 の
           -x == y の枝が 基点を写し、+0x78・+0x80（d[2],d[3]）に x・y を掛け、
           角 +0x88 を a で折り返す（角 - (角 - a)*2）。角が a と 1e-7 未満なら
           角はそのまま。逆コンパイルの読み、原典では押していない */
        const double pi = 3.141592653589793;
        double a = phi, sx = 1.0, sy = -1.0;

        if (a > pi / 2)
            a -= pi;
        if (a <= -pi / 2)
            a += pi;
        if (fabs(a) >= pi / 4) {
            a += a > 0.0 ? -pi / 2 : pi / 2;
            sx = -1.0;
            sy = 1.0;
        }
        if (fabs(a) < 1e-7)
            a = 0.0;
        if (o->d[2] == 0.0)     /* 移植の読みの 0 は 1（y は x と同じ） */
            o->d[2] = 1.0;
        if (o->d[3] == 0.0)
            o->d[3] = o->d[2];
        o->d[2] *= sx;
        o->d[3] *= sy;
        if (fabs(o->d[4] - a) >= 1e-7)
            o->d[4] -= (o->d[4] - a) * 2.0;
    }
}

/* 反転した参照（倍率 x・y の符号が違う。原典の反転は FUN_00464870 で
 * (1,-1) か (-1,1) を掛ける）は R(角)・diag(x,y) を 裏返し diag(1,-1) と
 * 等倍に分けて写す。diag(-s,s) は 180° 回した diag(s,-s)。x・y の大きさが
 * 違うもの（回っていない参照に x・y 違いの倍率を掛けたとき、回した参照なら
 * 定義を作り直したあと、jw_block_scale_xy）は 原典の描画 FUN_0042b460 が
 * 段ごとに 倍率 FUN_00465c40（角 0・原点・x・y）・回転・移動 を掛けるので、
 * 複写・移動の x・y 違いの倍率と同じ jw_obj_xform_xy で写す（円は楕円に）。
 * 逆コンパイルの読み、原典では押していない。
 */
void jw_obj_blkput(jw_obj *o, const jw_obj *ref)
{
    double sx = ref->d[2] != 0.0 ? ref->d[2] : 1.0;
    double sy = ref->d[3] != 0.0 ? ref->d[3] : sx;
    double ang = ref->d[4];

    if (fabs(sx) != fabs(sy)) {
        jw_obj_xform_xy(o, 0.0, 0.0, sx, sy, 0.0, ang, ref->d[0], ref->d[1]);
        return;
    }
    if (sx * sy < 0.0) {
        jw_obj_mirror(o, 0.0, 0.0, 1.0, 0.0);
        if (sx < 0.0) {
            sx = -sx;
            ang += 3.141592653589793;
        }
    }
    jw_obj_xform(o, 0.0, 0.0, sx, ang, ref->d[0], ref->d[1]);
}

/* ブロックの参照 o に 軸角 ax の向きで x・y 違いの倍率 (sx, sy) を (cx, cy)
 * まわりに掛ける。原典の倍率 FUN_00465c40 の CDataBlock の枝 FUN_00464870:
 *   |倍率| が 1e-5〜1e5 の外なら何もしない。x・y とも 1 との差が 1e-7 未満でも
 *   何もしない。基点 +0x68 は 軸の向きの枠（FUN_005f9a30 → FUN_005f92e0、
 *   戻すのは FUN_005f8ce0）で x・y を掛ける。そのうえで
 *   (1) 角 +0x88 と ax の差が 1e-7 未満・CDataHenkei の +4 が 0 でない・
 *       x == y のどれかなら 倍率 +0x78・+0x80 に x・y を掛けるだけ
 *   (2) -x == y（反転）なら 掛けて、角を ax で折り返す（jw_obj_mirror と同じ）
 *   (3) ほか（回した参照に x・y 違い）は 定義を作り直す: 新しい CDataList
 *       （FUN_004996f0。名前 ""・+0x78 = 4 なので 書くと "@@SfigorgFlag@@4"、
 *       +0x6c = 0）に 参照の写し（slot 5）を一つ入れる。写しは 基点 (0,0)・
 *       角 = 角 − ax・倍率は元のまま、つまり 元の定義を R(角−ax)·diag(元の倍率)
 *       で置いたもの。同じ中身の定義（CDataList の slot 7 FUN_0049bdb0: 名前と
 *       +0x78 が同じで 要素が順に等しい。参照どうしは FUN_0049bc40 が +0x28・
 *       色・レイヤ・グループ・基点・倍率・角・指す定義 を比べる）が 定義の並び
 *       （FUN_0040c0e0）にあればそれを指し、新しいほうは捨てる。無ければ
 *       並びの末尾へ（FUN_00570770 = AddTail）。参照は 倍率 (x, y)・角 0 に
 *       してから ax 回す（FUN_0046d050）ので 角は ax。
 * CDataHenkei の +4 は 複写・移動（FUN_00653e10）・描画（FUN_0042b460）・
 * ブロック解除（FUN_00458440）とも FUN_00464040 で 0 にした局所のもの
 * なので (1) の その条件は 移植では見ない（逆アセンブルで確認）。
 * 移植の違い: 定義の番号 list[0] は 原典では -1 のまま並びに入る（書くときの
 * 番号の振り方は読んでいない）が、移植の参照は番号で定義を指すので
 * ブロック化と同じく 今ある最大＋1。時刻 list[2] は今。指す定義が同じかは
 * 番号で比べる（原典は定義の時刻と中身）。d が 0 なら (3) は作れないので
 * (1) と同じにする（仮表示。仮表示はもともと参照の中身を描かない）。
 * 末尾に足した要素の数（0 か 2）を返す。o が d->obj の中を指していても
 * o を書き終えてから足すが、足したあと d->obj は動いていることがある。
 * 逆コンパイルの読み、原典では押していない。
 */
int jw_block_scale_xy(jw_drawing *d, jw_obj *o, double cx, double cy,
                      double sx, double sy, double ax)
{
    double ca = cos(ax), sa = sin(ax);
    double x = o->d[0] - cx, y = o->d[1] - cy, u, w;
    jw_obj m;
    jw_obj *l;
    int i, num = -1;

    if (!(fabs(sx) >= 1e-5 && fabs(sy) >= 1e-5 && fabs(sx) <= 1e5
          && fabs(sy) <= 1e5))
        return 0;
    if (fabs(sx - 1.0) < 1e-7 && fabs(sy - 1.0) < 1e-7)
        return 0;
    if (o->d[2] == 0.0)         /* 移植の読みの 0 は 1（y は x と同じ） */
        o->d[2] = 1.0;
    if (o->d[3] == 0.0)
        o->d[3] = o->d[2];
    u = (ca * x + sa * y) * sx;
    w = (-sa * x + ca * y) * sy;
    o->d[0] = cx + ca * u - sa * w;
    o->d[1] = cy + sa * u + ca * w;
    if (fabs(o->d[4] - ax) < 1e-7 || sx == sy || !d) {
        o->d[2] *= sx;
        o->d[3] *= sy;
        return 0;
    }
    if (-sx == sy) {
        o->d[2] *= sx;
        o->d[3] *= sy;
        o->d[4] -= (o->d[4] - ax) * 2.0;
        return 0;
    }
    /* (3) 定義を作り直す。写しは 基点 (0,0)・角 − ax・倍率はそのまま */
    m = *o;
    m.d[0] = m.d[1] = 0.0;
    m.d[4] = o->d[4] - ax;
    m.sel = m.was_sel = 0;
    m.flags = (unsigned short)(m.flags & ~2u);
    m.id = 0;
    for (i = d->ndrawn; i + 1 < d->nobj; i++) {
        const jw_obj *e = &d->obj[i + 1];
        const char *nm, *q;

        l = &d->obj[i];
        if (l->cls != JW_LIST || l->n != 1)
            continue;
        nm = jw_str(d, l->text);
        q = strstr(nm, "@@SfigorgFlag@@");
        if (q ? (q != nm || atoi(q + 15) != 4) : *nm != 0)
            continue;           /* 名前 "" と +0x78 = 4 でない */
        if (e->cls == JW_BLOCK && e->ltype == m.ltype && e->color == m.color
            && e->layer == m.layer && e->lgroup == m.lgroup
            && e->d[0] == m.d[0] && e->d[1] == m.d[1] && e->d[2] == m.d[2]
            && e->d[3] == m.d[3] && e->d[4] == m.d[4] && e->block == m.block) {
            num = l->list[0];
            break;
        }
    }
    o->d[2] = sx;
    o->d[3] = sy;
    o->d[4] = ax;
    if (num >= 0) {
        o->block = num;
        return 0;
    }
    for (i = d->ndrawn, num = 0; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] >= num)
            num = d->obj[i].list[0] + 1;
    o->block = num;             /* o はここまで（この先 d->obj が動く） */
    l = jw_add_def(d, JW_LIST);
    if (!l)
        return 0;
    l->n = 1;
    l->list[0] = num;
    l->list[1] = 0;
    l->list[2] = (int)time(0);
    l->text = jw_add_str(d, "@@SfigorgFlag@@4");
    l = jw_add_def(d, JW_BLOCK);
    if (!l) {
        jw_remove(d, d->nobj - 1);
        return 0;
    }
    *l = m;
    return 2;
}

/* 倍率が X と Y で違うとき（ﾏｳｽ倍率 1069、src/cmd.c の fk_xform_xy から）の
 * 一つの要素。軸角 ax の向きで X・Y に sx・sy を掛け、ang 回して (dx, dy)
 * ずらす。原典は要素の種類ごとの
 * FUN_00465c40（線 FUN_004686e0・円弧 FUN_00464fd0・点 FUN_00469fa0・文字
 * FUN_00466e30 ほか）。円・円弧は楕円になる（中心とともに 半径・扁平率・傾き・
 * 始角を写した楕円の軸で取り直す。裏返しなら向きを逆に）。文字は 文字も倍率
 * (1328) の切のときの FUN_00465f40 と同じく 置く点だけ移して大きさは変えない
 * （文字も倍率 の入の枝 FUN_00466e30 の残りは読み切っていない）。
 * 等倍（sx == sy > 0）なら jw_obj_xform そのまま。逆コンパイルの読み、原典では
 * 押していない */
static void xy_map(double c, double s, double ca, double sa, double sx,
                   double sy, double *x, double *y)
{
    /* R(ang) R(ax) diag(sx, sy) R(-ax) */
    double u = ca * *x + sa * *y, w = -sa * *x + ca * *y, px, py;

    u *= sx;
    w *= sy;
    px = ca * u - sa * w;
    py = sa * u + ca * w;
    *x = c * px - s * py;
    *y = s * px + c * py;
}

static void xy_ellipse(double c, double s, double ca, double sa, double sx,
                       double sy, double *r, double *flat, double *tilt,
                       double *start, double sweep)
{
    double f = *flat > 0.0 ? *flat : 1.0;
    double ct = cos(*tilt), st = sin(*tilt);
    double a = ct * *r, cc = st * *r;          /* 第 1 列 R(tilt)(r, 0) */
    double b = -st * *r * f, dd = ct * *r * f; /* 第 2 列 R(tilt)(0, rf) */
    double E, F, G, H, Q, R, s1, s2, a1, a2;

    xy_map(c, s, ca, sa, sx, sy, &a, &cc);
    xy_map(c, s, ca, sa, sx, sy, &b, &dd);
    /* [[a b] [cc dd]] = R(phi) diag(s1, s2) R(theta) */
    E = (a + dd) / 2.0;
    F = (a - dd) / 2.0;
    G = (cc + b) / 2.0;
    H = (cc - b) / 2.0;
    Q = sqrt(E * E + H * H);
    R = sqrt(F * F + G * G);
    s1 = Q + R;
    s2 = Q - R;
    a1 = atan2(G, F);
    a2 = atan2(H, E);
    if (s1 < 1e-12)
        return;
    *r = s1;
    *tilt = (a2 + a1) / 2.0;
    *flat = fabs(s2) / s1;
    if (s2 >= 0.0)
        *start = *start + (a2 - a1) / 2.0;
    else
        *start = -(*start + (a2 - a1) / 2.0) - sweep;
}

void jw_obj_xform_xy(jw_obj *o, double cx, double cy, double sx, double sy,
                     double ax, double ang, double dx, double dy)
{
    double c = cos(ang), s = sin(ang);
    double ca = cos(ax), sa = sin(ax);
    int i, n;

    if (fabs(sx - sy) < 1e-12 && sx > 0.0) {
        jw_obj_xform(o, cx, cy, sx, ang, dx, dy);
        return;
    }
    if (o->cls == JW_BLOCK) {
        /* 図面が無いので 定義は作り直さない（jw_block_scale_xy の d が 0） */
        jw_block_scale_xy(0, o, cx, cy, sx, sy, ax);
        jw_obj_xform(o, cx, cy, 1.0, ang, dx, dy);
        return;
    }
    if (o->cls == JW_MOJI) {
        double x = o->d[0] - cx, y = o->d[1] - cy;
        double ex = o->d[2] - o->d[0], ey = o->d[3] - o->d[1];

        xy_map(c, s, ca, sa, sx, sy, &x, &y);
        o->d[0] = cx + x + dx;
        o->d[1] = cy + y + dy;
        o->d[2] = o->d[0] + c * ex - s * ey;
        o->d[3] = o->d[1] + s * ex + c * ey;
        return;
    }
    if (o->cls == JW_ENKO) {
        xy_ellipse(c, s, ca, sa, sx, sy, &o->d[2], &o->d[6], &o->d[5],
                   &o->d[3], o->d[4]);
        n = 1;
    } else if (o->cls == JW_SOLID && (o->ltype == 101 || o->ltype == 111)) {
        /* 円ソリッド: 半径 d[2]・扁平 d[3]・傾き d[4]・始角 d[5]・開き d[6] */
        xy_ellipse(c, s, ca, sa, sx, sy, &o->d[2], &o->d[3], &o->d[4],
                   &o->d[5], o->d[6]);
        n = 1;
    } else if (o->cls == JW_TEN)
        n = 1;
    else if (o->cls == JW_SOLID)
        n = 4;
    else
        n = 2;
    for (i = 0; i < n; i++) {
        double x = o->d[i * 2] - cx, y = o->d[i * 2 + 1] - cy;

        xy_map(c, s, ca, sa, sx, sy, &x, &y);
        o->d[i * 2] = cx + x + dx;
        o->d[i * 2 + 1] = cy + y + dy;
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
    int i;

    memset(d, 0, sizeof *d);
    d->off_names = d->end_names = -1;
    d->off_ctab = d->end_ctab = -1;
    d->off_sxf = d->end_sxf = -1;
    a.b = b;
    a.n = n;
    a.o = 0;
    a.bad = 0;
    a.fig = 0;

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
         * embedded image files (FUN_00575010, the arm guarded by 0x275 <
         * version): a count, then that many pictures.  Read off a drawing
         * the original saved with 画像同梱. */
        d->nimage = ar_l(&a);
        /* each: its name with ".gz" on the end (a CString), the length, and
           the gzip of the picture file.  The drawing's pictures point at them
           as "%temp%<name>" (see tmp/image_report.md). */
        if (d->nimage < 0 || d->nimage > 100000)
            a.bad = 1;
        for (i = 0; i < d->nimage && !a.bad; i++) {
            int uni;
            long nm = ar_strlen(&a, &uni);
            const unsigned char *np = ar_raw(&a, uni ? nm * 2 : nm);
            unsigned len = (unsigned)ar_l(&a);
            const unsigned char *gp;
            char name[300];

            if (!np)
                break;
            if (uni)
                nm = jw_from_utf16(np, nm, name + 6, (long)sizeof name - 8);
            else {
                if (nm > (long)sizeof name - 8)
                    nm = (long)sizeof name - 8;
                memcpy(name + 6, np, (size_t)nm);
            }
            memcpy(name, "%temp%", 6);
            name[6 + nm] = 0;
            if (nm > 3 && !strcmp(name + 6 + nm - 3, ".gz"))
                name[6 + nm - 3] = 0;
            gp = ar_raw(&a, (long)len);
            if (!gp)
                break;
            jw_img_put_gz(name, gp, (long)len);
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

/* A 図形 file (.jws).  The header is a fixed 452 bytes -- see jww.h -- and
 * what follows it is the same list of elements a .jww carries.  The version
 * matters to the element reader (it decides which fields a record has), so
 * it is taken out of the header rather than left at zero.
 */
int jw_parse_jws(jw_drawing *d, const unsigned char *b, long n,
                 double *bx, double *by)
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
    a.fig = 1;

    sig = ar_raw(&a, 8);
    if (!sig || memcmp(sig, "JwsData.", 8)) {
        d->error = "not a .jws";
        return 0;
    }
    a.o = 0xc8;                         /* past the memo */
    d->version = ar_l(&a);
    {
        double x = ar_d(&a), y = ar_d(&a);
        if (bx)
            *bx = x;
        if (by)
            *by = y;
    }
    {   /* the sixteen layer-group scales, which say what the figure was
           drawn at */
        int g;
        for (g = 0; g < 16; g++)
            d->group[g].scale = ar_d(&a);
    }
    if (a.bad) {
        d->error = "the file ends in the middle of the header";
        return 0;
    }
    a.o = 0x1c4;                        /* the tables in between are not read */
    /* The fields above end at 0x15c, so a file that stops between there and
       0x1c4 gets this far with nothing to complain about -- and the header
       is copied whole, off the end of the file. */
    if (n < a.o) {
        d->error = "the file ends in the middle of the header";
        return 0;
    }
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
        /* A .jww carries a second list for its block definitions; a figure
           written by 図形登録 has one too, empty.  Some of the ones Jw_cad
           ships have not got it at all, so it is only read when there is
           anything left to read it from. */
        if (d->version > 0x13 && a.o < a.n && !a.bad)
            read_objs(&a, d, L, -1);
        lctx_free(L);
    }
    if (a.bad) {
        if (!d->error)
            d->error = "the figure ends in the middle of a record";
        return 0;
    }
    if (a.o != n) {
        d->error = "the parse did not land on the end of the figure";
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

/* the same, for a string that is to go out as UTF-16 (version 700 keeps
   every one of its strings that way) */
int jw_add_str_w(jw_drawing *d, const char *s, int wide)
{
    long n = (long)strlen(s);

    if (!wide)
        return pool_put(d, (const unsigned char *)s, n, 0);
    {
        unsigned short *u = (unsigned short *)malloc((size_t)(n + 1) * 2);
        long m;
        int off;

        if (!u)
            return -1;
        m = jw_to_utf16(s, n, u, n + 1);
        off = pool_put(d, (const unsigned char *)u, m, 1);
        free(u);
        return off;
    }
}

int jw_round_solid(const jw_obj *o, jw_obj *arc)
{
    if (o->cls != JW_SOLID || (o->ltype != 101 && o->ltype != 111))
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

/* Are all the numbers ones a drawing could hold?  The writers put every
   coordinate through printf's %f into buffers of a couple of hundred bytes,
   and 1e300 is three hundred and nine digits -- the first thing it overruns
   is the stack.  Millimetres on a sheet never reach 1e12, so anything past
   that came out of a damaged file.  The .jww reader checks each record as it
   goes; the readers for the text formats call this at the end.
   (tests/fuzz_test.c found the overrun, in src/sfcwrite.c.) */
int jw_numbers_sane(const jw_drawing *d)
{
    int i, k;

    for (i = 0; i < d->nobj; i++)
        for (k = 0; k < 8; k++)
            if (!(d->obj[i].d[k] > -1e12 && d->obj[i].d[k] < 1e12))
                return 0;
    return 1;
}

const char *jw_str(const jw_drawing *d, int off)
{
    /* A figure has no pool at all -- jw_parse_jws never reads a name -- and
       a drawing that came in damaged can carry an offset past the end of
       one.  Both used to walk off into nothing the moment something asked
       for the text: writing a figure out as SFC reads the layer group's
       name, which is offset 0 of a pool that is not there.
       (tests/fuzz_test.c found it.) */
    if (off < 0 || !d->pool || off >= d->npool)
        return "";
    return d->pool + off;
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
