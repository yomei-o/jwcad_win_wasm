/* 座標ファイル (32895) -- writing one.
 *
 * The bar of that command has ファイル名設定 (which puts Windows' own
 * 「開く」 box up), ファイル読込 and ファイル書込.  書込 asks for a range
 * and then writes what is picked as lines of text, CRLF ended:
 *
 *     lg0            the write layer group
 *     ly8            the write layer, in hex
 *     lc2            the write colour
 *     lt1            the write line type
 *     lw17           the pen width that colour is drawn at
 *     cn0 20 20 0 1  the 文字種 in force -- width, height, spacing, colour
 *     cn"$<ＭＳ ゴシック>
 *     #              and that is the end of the head
 *
 * then one line per element, with a state line before it whenever the state
 * it needs is not the one in force:
 *
 *      x1 y1 x2 y2                    a line (note the leading space)
 *     ci cx cy r a0 a1 ratio tilt     an arc, angles in degrees
 *     ci cx cy r                      a whole circle
 *     pt x y                          a point
 *     sl x1 y1 x2 y2 x3 y3 [x4 y4]    a solid, three corners or four
 *
 * **The coordinates are real-world millimetres from a point of the drawing's
 * own**: `(paper - origin) * the scale of the write group`, where the origin
 * is the very point ブロック化 puts a block at -- the average of one point
 * per element (jw_cmd_block_point).  That was read off three files the
 * original wrote, from three different drawings, and it matches to nine
 * decimals each time.  The numbers go out at %.15g, which is what 条件設定's
 * 「有効桁」 means (it can also be told to write 0 to 5 decimals instead).
 *
 * `lc` and `pn` are **two states**: a point takes its colour from `pn` and
 * everything else from `lc`, so a solid after a point writes `lc` again even
 * when the point had the same colour.  `lw` is shared, and a solid does not
 * touch it.
 *
 * A text is `<kw> x y dx dy "the text`, where (dx, dy) is the vector to the
 * far end of its baseline and the word says what it belongs to: **`cz` for
 * a dimension's (bit 128 of the flags at +0x44), `ck` for one that came
 * with a figure (bit 64) and `ch` for a text of its own (neither)**.  Before
 * it comes the 文字種: `cn<k>` for one of the ten, kept as a state and
 * followed by `cc0`, or `cn0 w h sp colour` for 任意サイズ, which is
 * written out again before every text.  A text carries its own number in
 * `n`, and that is what decides which of the two it gets.
 *
 * **The texts come last.**  Test5's elements run lines, texts, lines,
 * texts, and its file has all 46 lines and then all 43 texts, so the writer
 * makes two passes.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

#define PI 3.14159265358979323846

/* the face the original names in the head, whatever the drawing carries */
#define JW_COORD_FACE "\x82\x6c\x82\x72 \x83\x53\x83\x56\x83\x62\x83\x4e"

typedef struct {
    char *b;
    long n, cap;
    int bad;
} cbuf;

static void put(cbuf *w, const char *s, long n)
{
    if (w->bad)
        return;
    if (w->n + n > w->cap) {
        long cap = w->cap ? w->cap * 2 : 4096;
        char *nb;

        while (cap < w->n + n)
            cap *= 2;
        nb = (char *)realloc(w->b, (size_t)cap);
        if (!nb) {
            w->bad = 1;
            return;
        }
        w->b = nb;
        w->cap = cap;
    }
    memcpy(w->b + w->n, s, (size_t)n);
    w->n += n;
}

static void puts_(cbuf *w, const char *s)
{
    put(w, s, (long)strlen(s));
}

/* one line, CRLF ended */
static void line(cbuf *w, const char *s)
{
    puts_(w, s);
    put(w, "\r\n", 2);
}

/* a number the way the original writes one */
static void num(cbuf *w, double v)
{
    char t[64];

    sprintf(t, " %.15g", v);
    puts_(w, t);
}

/* Where the drawing's own numbers go: real millimetres from the origin. */
typedef struct {
    double ox, oy, scale;
} cmap;

static double mx(const cmap *m, double x) { return (x - m->ox) * m->scale; }
static double my(const cmap *m, double y) { return (y - m->oy) * m->scale; }

/* An angle in degrees, brought into [0, 360). */
static double deg(double rad)
{
    double a = rad * 180.0 / PI;

    while (a < 0.0)
        a += 360.0;
    while (a >= 360.0)
        a -= 360.0;
    return a;
}

/* The width a colour is written at.  It is the **printer** pen table, in
 * dots at 300 to the inch, turned into hundredths of a millimetre: colours
 * 1..5 of Test5 came out 8, 17, 25, 34 and 42, which is 1..5 dots times
 * 25.4/3.  The index is the colour itself, not one less -- the port's table
 * starts one entry before Jw_cad's 線色1.
 */
static int pen_w(const jw_drawing *d, int col)
{
    int dots = col >= 0 && col < 10 ? d->print_width[col] : 0;
    double w = dots * 25.4 / 3.0 + 0.5;

    /* a damaged file can hold any int in there, and turning a double that
       does not fit an int into one is undefined -- found by reading the
       cut-down copies with -fsanitize=undefined (tools/asan.sh) */
    if (w < 0.0)
        return 0;
    if (w > 2147483000.0)
        return 2147483000;
    return (int)w;
}

int jw_write_coord(const jw_drawing *d, double ox, double oy,
                   unsigned char **out, long *n)
{
    cbuf w;
    cmap m;
    char t[128];
    int i, g, wg = 0, wl, lc = -1, pn = -1, lt = -1, lw = -1, ly = -1;
    int cn = -1;                /* the numbered 文字種 in force, -1 none */

    *out = 0;
    *n = 0;
    if (!d)
        return 0;
    memset(&w, 0, sizeof w);
    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    wl = d->group[wg].write_layer & 15;
    m.ox = ox;
    m.oy = oy;
    m.scale = d->group[wg].scale;
    if (m.scale <= 0.0)
        m.scale = 1.0;

    sprintf(t, "lg%x", wg);                     line(&w, t);
    sprintf(t, "ly%x", wl);                     line(&w, t);
    lc = d->write_color ? d->write_color : 2;
    lt = d->write_ltype ? d->write_ltype : 1;
    sprintf(t, "lc%d", lc);                     line(&w, t);
    sprintf(t, "lt%d", lt);                     line(&w, t);
    lw = pen_w(d, lc);
    sprintf(t, "lw%d", lw);                     line(&w, t);
    sprintf(t, "cn0 %.15g %.15g %.15g %d", d->cur_style.w, d->cur_style.h,
            d->cur_style.sp, d->cur_style.color);
    line(&w, t);
    line(&w, "cn\"$<" JW_COORD_FACE ">");
    line(&w, "#");
    ly = wl;

    /* Two passes: **everything but the texts first, then the texts**.  That
       is the order the original's own file comes out in -- Test5's elements
       run lines, texts, lines, texts, and its file has all 46 lines and then
       all 43 texts. */
    for (i = 0; i < 2 * d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i % d->ndrawn];
        int col = o->color, wid, pass = i / d->ndrawn;

        if (!o->sel)
            continue;
        if ((o->cls == JW_MOJI) != pass)
            continue;
        if (o->cls != JW_SEN && o->cls != JW_ENKO && o->cls != JW_TEN
            && o->cls != JW_SOLID && o->cls != JW_MOJI)
            continue;                   /* blocks are not done */
        wid = pen_w(d, col);
        if ((o->layer & 15) != ly) {
            ly = o->layer & 15;
            sprintf(t, "ly%x", ly);     line(&w, t);
        }
        if (o->cls == JW_MOJI) {
            /* The 文字種 in force.  A text carries its own number in `n`
               -- 0 is 任意サイズ -- and that is what goes out: `cn<k>` for
               one of the ten, kept as a state and followed by `cc0`, or
               `cn0 w h sp col`, which is written out again before every
               text rather than kept. */
            int hit = o->n >= 1 && o->n <= 10 ? o->n : 0;

            if (hit) {
                if (hit != cn) {
                    cn = hit;
                    sprintf(t, "cn%d", cn);         line(&w, t);
                    line(&w, "cc0");
                }
            } else {
                cn = -1;
                sprintf(t, "cn0 %.15g %.15g %.15g %d", o->d[4], o->d[5],
                        o->d[6], o->color);
                line(&w, t);
            }
        } else if (o->cls == JW_TEN) {
            if (col != pn) {
                pn = col;
                sprintf(t, "pn%d", pn); line(&w, t);
            }
            if (wid != lw) {
                lw = wid;
                sprintf(t, "lw%d", lw); line(&w, t);
            }
        } else if (o->cls == JW_SOLID) {
            if (col != lc) {
                lc = col;
                sprintf(t, "lc%d", lc); line(&w, t);
            }
        } else {
            if (col != lc) {
                lc = col;
                sprintf(t, "lc%d", lc); line(&w, t);
            }
            if (o->ltype != lt) {
                lt = o->ltype;
                sprintf(t, "lt%d", lt); line(&w, t);
            }
            if (wid != lw) {
                lw = wid;
                sprintf(t, "lw%d", lw); line(&w, t);
            }
        }
        switch (o->cls) {
        case JW_SEN:
            num(&w, mx(&m, o->d[0]));
            num(&w, my(&m, o->d[1]));
            num(&w, mx(&m, o->d[2]));
            num(&w, my(&m, o->d[3]));
            put(&w, "\r\n", 2);
            break;
        case JW_ENKO: {
            double a0 = o->d[3], sw = o->d[4];

            puts_(&w, "ci");
            num(&w, mx(&m, o->d[0]));
            num(&w, my(&m, o->d[1]));
            num(&w, o->d[2] * m.scale);
            if (!(o->n == 1 || sw >= 2 * PI || sw <= -2 * PI)) {
                /* anticlockwise, so a sweep that runs the other way is
                   written as the other end round */
                double s = sw < 0.0 ? a0 + sw : a0;
                double e = sw < 0.0 ? a0 : a0 + sw;

                num(&w, deg(s));
                num(&w, deg(e));
                num(&w, o->d[6]);
                num(&w, deg(o->d[5]) == 0.0 ? 0.0 : deg(o->d[5]));
            }
            put(&w, "\r\n", 2);
            break;
        }
        case JW_TEN:
            puts_(&w, "pt");
            num(&w, mx(&m, o->d[0]));
            num(&w, my(&m, o->d[1]));
            put(&w, "\r\n", 2);
            break;
        case JW_MOJI: {
            /* Which of the three words a text goes out under follows the
               bits at +0x44: 128 is a dimension's, 64 one that came with a
               figure, and nothing at all is a text of its own. */
            const char *kw = (o->flags & 128) ? "cz"
                           : (o->flags & 64) ? "ck" : "ch";

            puts_(&w, kw);
            num(&w, mx(&m, o->d[0]));
            num(&w, my(&m, o->d[1]));
            num(&w, (o->d[2] - o->d[0]) * m.scale);
            num(&w, (o->d[3] - o->d[1]) * m.scale);
            puts_(&w, " \"");
            puts_(&w, jw_str(d, o->text));
            put(&w, "\r\n", 2);
            break;
        }
        case JW_SOLID: {
            int k, np = 4;

            if (o->d[4] == o->d[6] && o->d[5] == o->d[7])
                np = 3;
            puts_(&w, "sl");
            for (k = 0; k < np; k++) {
                num(&w, mx(&m, o->d[k * 2]));
                num(&w, my(&m, o->d[k * 2 + 1]));
            }
            put(&w, "\r\n", 2);
            break;
        }
        default:
            break;
        }
    }
    if (w.bad) {
        free(w.b);
        return 0;
    }
    *out = (unsigned char *)w.b;
    *n = w.n;
    return 1;
}

/* ------------------------------------------------------ reading one -----
 * 座標ファイル's ファイル読込 turns the file into a **図形**: the prompt
 * becomes 「【図形】の複写位置を指示してください」 and the bar is 図形読込's,
 * with 倍率 and 回転角.  So this only reads the text into a drawing of its
 * own, in the file's own real millimetres with every layer group at 1, and
 * the figure machinery places it -- the scale that then falls out is
 * 1 / the write group's, which is what the original does (a file written
 * from a 1/200 drawing came back into a 1/100 one at half the size).
 *
 * The file's (0, 0) is where the click goes.
 *
 * `lw` becomes the element's own width -- the elements that came back
 * carried 8, 17, 25, 34 and 42 -- except on a solid, which gets none.
 */
static const char *eat_line(const char *p, const char *end, char *buf,
                            int cap)
{
    int n = 0;

    while (p < end && *p != '\r' && *p != '\n') {
        if (n < cap - 1)
            buf[n++] = *p;
        p++;
    }
    buf[n] = 0;
    while (p < end && (*p == '\r' || *p == '\n'))
        p++;
    return p;
}

/* the numbers of a line, space separated */
static int nums(const char *s, double *v, int max)
{
    int n = 0;

    while (*s && n < max) {
        char *e;
        double d;

        while (*s == ' ' || *s == '\t')
            s++;
        if (!*s)
            break;
        d = strtod(s, &e);
        if (e == s)
            break;
        v[n++] = d;
        s = e;
    }
    return n;
}

/* How long a text's baseline is, from its own size: half-widths over two,
 * times width plus spacing, less one spacing.  **A text read out of a
 * coordinate file gets its far end worked out this way rather than from the
 * (dx, dy) the file gives** -- that is only a direction.  Reading Test5's
 * file into a 1/100 sheet bears it out: its 20mm texts, whose dx says 400mm
 * once it has been divided by the new scale, came out 200mm long, which is
 * ten letters of 20; and the 2.5mm ones came out 7.5 and 13.75 long, which
 * is what six and eleven half-width letters make.
 */
double jw_coord_text_len(const jw_drawing *d, const jw_obj *o)
{
    const unsigned char *s = (const unsigned char *)jw_str(d, o->text);
    double half = 0.0;

    while (s && *s) {
        if ((*s >= 0x81 && *s <= 0x9f) || (*s >= 0xe0 && *s <= 0xfc)) {
            if (s[1])
                s++;
            half += 2.0;
        } else {
            half += 1.0;
        }
        s++;
    }
    if (half <= 0.0)
        return 0.0;
    return half / 2.0 * (o->d[4] + o->d[6]) - o->d[6];
}

int jw_parse_coord(jw_drawing *d, const jw_drawing *host,
                   const unsigned char *b, long n)
{
    const char *p = (const char *)b, *end = (const char *)b + n;
    char t[512];
    int lc = 2, pn = 2, lt = 1, lw = 0, ly = 0, head = 1, g;
    /* the 文字種 in force: 0 is 任意サイズ, and then cw/chh/csp/ccol hold
       what the `cn0` line gave */
    int cn = 0, ccol = 1;
    double cw = 2.0, chh = 2.0, csp = 0.0;

    memset(d, 0, sizeof *d);
    d->off_names = d->end_names = -1;
    d->off_ctab = d->end_ctab = -1;
    d->off_sxf = d->end_sxf = -1;
    d->version = 700;
    for (g = 0; g < 16; g++)
        d->group[g].scale = 1.0;
    while (p < end) {
        double v[16];
        int k;
        jw_obj *o;

        p = eat_line(p, end, t, (int)sizeof t);
        if (!t[0])
            continue;
        if (t[0] == '#') {
            head = 0;
            continue;
        }
        if (t[0] == 'l' && t[1] == 'y') { ly = (int)strtol(t + 2, 0, 16); continue; }
        if (t[0] == 'l' && t[1] == 'g') { continue; }
        if (t[0] == 'l' && t[1] == 'c') { lc = atoi(t + 2); continue; }
        if (t[0] == 'l' && t[1] == 't') { lt = atoi(t + 2); continue; }
        if (t[0] == 'l' && t[1] == 'w') { lw = atoi(t + 2); continue; }
        if (t[0] == 'p' && t[1] == 'n') { pn = atoi(t + 2); continue; }
        if (t[0] == 'c' && t[1] == 'n') {
            if (t[2] == '"')
                continue;               /* the font name */
            cn = atoi(t + 2);
            if (cn >= 1 && cn <= 10 && host) {
                cw = host->style[cn - 1].w;
                chh = host->style[cn - 1].h;
                csp = host->style[cn - 1].sp;
                ccol = host->style[cn - 1].color;
            } else if (cn == 0) {
                double v2[4];

                if (nums(t + 3, v2, 4) == 4) {
                    cw = v2[0];
                    chh = v2[1];
                    csp = v2[2];
                    /* jw_whole: the colour came out of the file through
                       atof(), so it may be 1e300 and the cast undefined */
                    ccol = jw_whole(v2[3]);
                }
            }
            continue;
        }
        if (t[0] == 'c' && t[1] == 'c') { continue; }   /* always 0 so far */
        if (head)
            continue;
        if (t[0] == 'c' && (t[1] == 'z' || t[1] == 'k' || t[1] == 'h')) {
            /* a text: x y dx dy "the text.  Which word it came under says
               what it belongs to, and reading one always adds bit 8. */
            const char *q = strchr(t, '"');

            if (!q || nums(t + 2, v, 4) < 4)
                continue;
            o = jw_add(d, JW_MOJI);
            if (!o)
                return 0;
            o->d[0] = v[0];
            o->d[1] = v[1];
            o->d[2] = v[0] + v[2];
            o->d[3] = v[1] + v[3];
            o->d[4] = cw;
            o->d[5] = chh;
            o->d[6] = csp;
            o->color = (unsigned short)ccol;
            o->ltype = 1;
            o->width = 0;
            o->n = cn;
            o->flags = (unsigned short)(t[1] == 'z' ? 128
                                        : t[1] == 'k' ? 64 : 0);
            o->text = jw_add_str(d, q + 1);
        } else if (t[0] == 'c' && t[1] == 'i') {
            k = nums(t + 2, v, 8);
            if (k < 3)
                continue;
            o = jw_add(d, JW_ENKO);
            if (!o)
                return 0;
            o->d[0] = v[0];
            o->d[1] = v[1];
            o->d[2] = v[2];
            if (k >= 5) {
                double a0 = v[3] * PI / 180.0, a1 = v[4] * PI / 180.0;
                double sw = a1 - a0;

                while (sw < 0.0)
                    sw += 2 * PI;
                o->d[3] = a0;
                o->d[4] = sw;
                o->d[5] = k >= 7 ? v[6] * PI / 180.0 : 0.0;
                o->d[6] = k >= 6 ? v[5] : 1.0;
            } else {
                o->d[3] = 0.0;
                o->d[4] = 2 * PI;
                o->d[5] = 0.0;
                o->d[6] = 1.0;
                o->n = 1;
            }
            o->color = (unsigned short)lc;
            o->ltype = (unsigned char)lt;
            o->width = (unsigned short)lw;
        } else if (t[0] == 'p' && t[1] == 't') {
            if (nums(t + 2, v, 2) < 2)
                continue;
            o = jw_add(d, JW_TEN);
            if (!o)
                return 0;
            o->d[0] = v[0];
            o->d[1] = v[1];
            o->color = (unsigned short)pn;
            o->ltype = (unsigned char)lt;
            o->width = (unsigned short)lw;
        } else if (t[0] == 's' && t[1] == 'l') {
            k = nums(t + 2, v, 8);
            if (k < 6)
                continue;
            o = jw_add(d, JW_SOLID);
            if (!o)
                return 0;
            for (g = 0; g < 8; g++)
                o->d[g] = g < k ? v[g] : v[k - 2 + (g & 1)];
            o->color = (unsigned short)lc;
            o->ltype = (unsigned char)lt;
            o->width = 0;               /* a solid takes no lw */
        } else if (t[0] == ' ' || t[0] == '-' || (t[0] >= '0' && t[0] <= '9')) {
            if (nums(t, v, 4) < 4)
                continue;
            o = jw_add(d, JW_SEN);
            if (!o)
                return 0;
            o->d[0] = v[0];
            o->d[1] = v[1];
            o->d[2] = v[2];
            o->d[3] = v[3];
            o->color = (unsigned short)lc;
            o->ltype = (unsigned char)lt;
            o->width = (unsigned short)lw;
        } else {
            continue;                   /* cn2, cc0, cz -- not read yet */
        }
        d->obj[d->ndrawn - 1].layer = (unsigned short)ly;
        d->obj[d->ndrawn - 1].lgroup = 0;
        /* Everything read out of a coordinate file carries bit 8 of the
           flags at +0x44 -- the original's own read-back has it on every
           line and every text. */
        d->obj[d->ndrawn - 1].flags |= 8;
    }
    return d->ndrawn > 0;
}
