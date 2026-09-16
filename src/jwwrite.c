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
    "CDataSen", "CDataEnko", "CDataTen", "CDataMoji", "CDataSolid"
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
    }
}

/* One CObList: the count, then the objects with their class tags. */
static void w_list(wbuf *w, const jw_drawing *d, int from, int to)
{
    int seen[JW_NCLASS];
    int nload = 1;
    int i;

    for (i = 0; i < JW_NCLASS; i++)
        seen[i] = 0;
    w_count(w, to - from);
    for (i = from; i < to; i++) {
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
            seen[c] = nload++;      /* the class takes a number */
        } else {
            w_w(w, 0x8000u | (unsigned)seen[c]);
        }
        nload++;                    /* and so does the object */
        w_base(w, d->version, o);
        w_body(w, d, d->version, o);
    }
}

int jw_write(const jw_drawing *d, unsigned char **out, long *n)
{
    wbuf w;

    *out = 0;
    *n = 0;
    if (!d->head || d->nhead <= 0)
        return 0;
    memset(&w, 0, sizeof w);
    w_raw(&w, d->head, d->nhead);
    w_list(&w, d, 0, d->ndrawn);
    w_list(&w, d, d->ndrawn, d->nobj);
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
