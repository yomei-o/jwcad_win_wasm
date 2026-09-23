/* Writing a .jww back out.
 *
 * The header goes back exactly as it came in -- src/jww.c keeps a copy,
 * because it understands only part of what is in there and anything it
 * invented would be wrong.  What this builds is the two CObList that follow
 * it: the drawing, then the block definitions.
 *
 * CArchive numbers classes and objects together as it goes, which is what
 * makes the tags work: 0xffff introduces a class (schema, then its name),
 * 0x8000 | n refers back to one, and every object read or written takes the
 * next number too.  That is the same bookkeeping src/jww.c does when
 * reading, mirrored.
 *
 * The test for all this is tools/../tests/write_test.c: read one of the
 * sample drawings and write it again, and the bytes have to come back
 * identical.
 */
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "cp932.h"

typedef struct {
    unsigned char *b;
    long n, cap;
    int bad;
} wbuf;

static void w_raw(wbuf *w, const void *p, long n)
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
    memcpy(w->b + w->n, p, (size_t)n);
    w->n += n;
}

static void w_b(wbuf *w, unsigned v)
{
    unsigned char c = (unsigned char)v;
    w_raw(w, &c, 1);
}

static void w_w(wbuf *w, unsigned v)
{
    unsigned char c[2];
    c[0] = (unsigned char)v;
    c[1] = (unsigned char)(v >> 8);
    w_raw(w, c, 2);
}

static void w_l(wbuf *w, long v)
{
    unsigned char c[4];
    unsigned u = (unsigned)v;
    c[0] = (unsigned char)u;
    c[1] = (unsigned char)(u >> 8);
    c[2] = (unsigned char)(u >> 16);
    c[3] = (unsigned char)(u >> 24);
    w_raw(w, c, 4);
}

static void w_d(wbuf *w, double v)
{
    w_raw(w, &v, 8);
}

/* CArchive::WriteCount: a word, or 0xffff and a dword when it will not fit */
static void w_count(wbuf *w, long n)
{
    if (n < 0xffff) {
        w_w(w, (unsigned)n);
    } else {
        w_w(w, 0xffff);
        w_l(w, n);
    }
}

/* MFC's WriteStringLength: the count as a byte, or 0xff and a word, or that
   and 0xffff and a dword. */
static void w_strlen(wbuf *w, long n)
{
    if (n < 0xff) {
        w_b(w, (unsigned)n);
    } else if (n < 0xffff) {
        w_b(w, 0xff);
        w_w(w, (unsigned)n);
    } else {
        w_b(w, 0xff);
        w_w(w, 0xffff);
        w_l(w, n);
    }
}

/* CString.  Up to version 600 that is CP932 bytes; version 700 puts every
   string in as UTF-16, behind MFC's 0xff 0xfffe marker.  Which one this
   string came in as is remembered with it, so it goes back the same. */
static void w_str(wbuf *w, const char *s, int wide)
{
    long n = s ? (long)strlen(s) : 0;

    if (!wide) {
        w_strlen(w, n);
        w_raw(w, s, n);
        return;
    }
    {
        long m = jw_to_utf16(s, n, 0, 0), i;
        unsigned short *u = (unsigned short *)malloc((size_t)(m ? m : 1) * 2);
        if (!u) {
            w->bad = 1;
            return;
        }
        jw_to_utf16(s, n, u, m);
        w_b(w, 0xff);
        w_w(w, 0xfffe);
        w_strlen(w, m);
        for (i = 0; i < m; i++)
            w_w(w, u[i]);
        free(u);
    }
}

static const char *CLASS_NAME[JW_NCLASS] = {
    "CDataSen", "CDataEnko", "CDataTen", "CDataMoji", "CDataSolid",
    "CDataBlock", "CDataList"
};

/* CData::Serialize, the store side of FUN_0042e690 */
static void w_base(wbuf *w, int v, const jw_obj *o)
{
    if (v > 0x13)
        w_l(w, o->id);
    w_b(w, o->ltype);
    w_w(w, o->color);
    if (v > 0x15e)
        w_w(w, o->width);
    w_w(w, o->layer);
    w_w(w, o->lgroup);
    if (v > 0x13)
        w_w(w, o->flags);
}

static void w_body(wbuf *w, const jw_drawing *d, int v, const jw_obj *o)
{
    int i;

    switch (o->cls) {
    case JW_SEN:
        for (i = 0; i < 4; i++)
            w_d(w, o->d[i]);
        break;
    case JW_ENKO:
        for (i = 0; i < 7; i++)
            w_d(w, o->d[i]);
        w_l(w, o->n);
        break;
    case JW_TEN:
        w_d(w, o->d[0]);
        w_d(w, o->d[1]);
        if (v > 0x15)
            w_l(w, o->n);
        if (v == 0xfc || (v > 299 && o->ltype == 100)) {
            w_l(w, o->mark);        /* 任意点 */
            w_d(w, o->turn);
            w_d(w, o->size);
        }
        break;
    case JW_MOJI:
        for (i = 0; i < 4; i++)
            w_d(w, o->d[i]);
        if (v > 0x13)
            w_l(w, o->n);
        w_d(w, o->d[4]);
        w_d(w, o->d[5]);
        if (v > 0x13)
            w_d(w, o->d[6]);
        w_d(w, o->d[7]);
        if (v > 0x27)
            w_str(w, jw_str(d, o->face), jw_str_wide(d, o->face));
        w_str(w, jw_str(d, o->text), jw_str_wide(d, o->text));
        break;
    case JW_SOLID:
        for (i = 0; i < 8; i++)
            w_d(w, o->d[i]);
        if (o->color == 10)
            w_l(w, o->n);
        break;
    case JW_BLOCK:
        for (i = 0; i < 5; i++)
            w_d(w, o->d[i]);
        w_l(w, o->block);
        break;
    case JW_LIST:
        for (i = 0; i < 3; i++)
            w_l(w, o->list[i]);
        w_str(w, jw_str(d, o->text), jw_str_wide(d, o->text));
        /* the elements of the definition go here, in the list's own count
           and sharing the numbering -- w_objs does that part */
        break;
    }
}

/* How many elements this one takes with it: a definition carries its own,
   straight after it in the array. */
static int w_span(const jw_drawing *d, int i)
{
    int n = 1, k;

    if (d->obj[i].cls == JW_LIST)
        for (k = 0; k < d->obj[i].n; k++)
            n += w_span(d, i + n);
    return n;
}

/* The objects of one list, with their class tags.  `seen` and `nload` are
   the numbering, which a definition's own list carries on rather than
   starting again. */
static void w_objs(wbuf *w, const jw_drawing *d, int from, int to,
                   int *seen, int *nload)
{
    int i;

    for (i = from; i < to; ) {
        const jw_obj *o = &d->obj[i];
        int c = o->cls;

        if (c < 0 || c >= JW_NCLASS) {
            w->bad = 1;
            return;
        }
        if (!seen[c]) {
            w_w(w, 0xffff);
            w_w(w, d->schema[c]);
            w_w(w, (unsigned)strlen(CLASS_NAME[c]));
            w_raw(w, CLASS_NAME[c], (long)strlen(CLASS_NAME[c]));
            seen[c] = (*nload)++;   /* the class takes a number */
        } else if (seen[c] > 0x3ffe) {
            /* too big to say in a word: MFC's wBigObjectTag and a long */
            w_w(w, 0x7fff);
            w_l(w, (long)((unsigned long)seen[c] | 0x80000000UL));
        } else {
            w_w(w, 0x8000u | (unsigned)seen[c]);
        }
        (*nload)++;                 /* and so does the object */
        w_base(w, d->version, o);
        w_body(w, d, d->version, o);
        if (c == JW_LIST) {
            int span = w_span(d, i);

            w_count(w, o->n);
            w_objs(w, d, i + 1, i + span, seen, nload);
            i += span;
        } else {
            i++;
        }
    }
}

/* One CObList: the count, then the objects.  A definition's elements are
   kept in the same array straight after it, so they are not counted here.
   The numbering runs through both lists, not through one. */
static void w_list(wbuf *w, const jw_drawing *d, int from, int to,
                   int *seen, int *nload)
{
    int i, n = 0;

    for (i = from; i < to; i += w_span(d, i))
        n++;
    w_count(w, n);
    w_objs(w, d, from, to, seen, nload);
}

/* The three blocks of the header that hold names, written out of the
   drawing rather than copied out of the bytes it came in as.  A name is not
   a fixed size, so one that has changed length would push everything after
   it along; the numbers that sit beside the names go through here too. */
static void w_names(wbuf *w, const jw_drawing *d)
{
    int g, l;

    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++)
            w_str(w, jw_str(d, d->group[g].layer_name[l]),
                  jw_str_wide(d, d->group[g].layer_name[l]));
    for (g = 0; g < 16; g++)
        w_str(w, jw_str(d, d->group[g].name),
              jw_str_wide(d, d->group[g].name));
}

static void w_ctab(wbuf *w, const jw_drawing *d)
{
    int i;

    for (i = 0; i < 257; i++) {
        w_l(w, (long)d->xcolor[i]);
        w_l(w, d->xcolor_rest[i].pair);
    }
    for (i = 0; i < 257; i++) {
        w_str(w, jw_str(d, d->xcolor_rest[i].name),
              jw_str_wide(d, d->xcolor_rest[i].name));
        w_l(w, (long)d->xcolor_rest[i].rgb2);
        w_l(w, d->xcolor_rest[i].b);
        w_d(w, d->xcolor_rest[i].w);
    }
}

static void w_sxf(wbuf *w, const jw_drawing *d)
{
    int i, j;

    for (i = 0; i < 33; i++) {
        w_str(w, jw_str(d, d->sxf[i].name), jw_str_wide(d, d->sxf[i].name));
        w_l(w, d->sxf[i].n);
        for (j = 0; j < 10; j++)
            w_d(w, d->sxf[i].pat[j + 1]);
    }
}

/* The header: everything but those three blocks goes back exactly as it came
   in -- there is far more in there than this understands -- and the layer
   group scales are put in where they sit, which is before any of them.  A
   drawing that was only read and written again comes out identical, which is
   what tests/write_test.c is for. */
static void w_head(wbuf *w, const jw_drawing *d)
{
    struct { long off, end; void (*put)(wbuf *, const jw_drawing *); } part[3];
    long at = 0;
    int i, g, np = 0;

    if (d->off_names >= 0) {
        part[np].off = d->off_names;
        part[np].end = d->end_names;
        part[np++].put = w_names;
    }
    if (d->off_ctab >= 0) {
        part[np].off = d->off_ctab;
        part[np].end = d->end_ctab;
        part[np++].put = w_ctab;
    }
    if (d->off_sxf >= 0) {
        part[np].off = d->off_sxf;
        part[np].end = d->end_sxf;
        part[np++].put = w_sxf;
    }
    for (i = 0; i < np; i++) {
        w_raw(w, d->head + at, part[i].off - at);
        part[i].put(w, d);
        at = part[i].end;
    }
    w_raw(w, d->head + at, d->nhead - at);
    /* The scales come earlier in the header than any name does, so they are
       still where the file had them. */
    for (g = 0; g < 16 && !w->bad; g++)
        if (d->off_scale[g] > 0 && (np == 0 || d->off_scale[g] + 8 <= part[0].off))
            memcpy(w->b + d->off_scale[g], &d->group[g].scale, 8);
}

int jw_write(const jw_drawing *d, unsigned char **out, long *n)
{
    wbuf w;

    *out = 0;
    *n = 0;
    if (!d->head || d->nhead <= 0)
        return 0;
    memset(&w, 0, sizeof w);
    w_head(&w, d);
    {
        int seen[JW_NCLASS], nload = 1, i;

        for (i = 0; i < JW_NCLASS; i++)
            seen[i] = 0;
        w_list(&w, d, 0, d->ndrawn, seen, &nload);
        w_list(&w, d, d->ndrawn, d->nobj, seen, &nload);
    }
    if (d->version > 0x275)
        w_l(&w, d->nimage);     /* the embedded image count, always 0 here */
    if (w.bad) {
        free(w.b);
        return 0;
    }
    *out = w.b;
    *n = w.n;
    return 1;
}
