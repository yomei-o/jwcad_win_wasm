/* Write a drawing out as DXF, the way the original does.
 *
 * Jw_cad's DXF形式で保存 (32961) writes an AC1009 (R12) ASCII DXF with CRLF
 * line endings.  What is in it was read off the ones it wrote -- see
 * RESUME.md and tools/mkdxf.py:
 *
 *   HEADER    $ACADVER .. $LTSCALE, with the sheet and the scale in it
 *   TABLES    VPORT, then LTYPE and STYLE (the same bytes every time, so
 *             they are carried in src/gen/dxf.h), then LAYER, which is the
 *             drawing's own
 *   BLOCKS    empty -- but only because the three drawings this was read
 *             off none of them carried a ブロック reference.  2026-10-19,
 *             tools/jwdraw.ps1 export:32961 on decomp/res/blktxt_base.jww
 *             (a block reference, mirrored four ways, round a 定義 of five
 *             字 and some lines/circles/points/solids) wrote a real BLOCKS
 *             section instead: one BLOCK "-000-BLK" with the 定義's own
 *             elements at their own, unmirrored, local coordinates (its
 *             TEXT entities keep their original group-50 angles 0,30,90,
 *             150,300 regardless of the reference), and four INSERT
 *             entities in ENTITIES -- one per reference -- carrying the
 *             insertion point and group 41/42 (x/y scale, e.g. -1/1) that
 *             do the mirroring.  So "BLOCKS empty" is not a general rule;
 *             it only held for block-free drawings.  This writer does not
 *             implement BLOCK/INSERT at all yet (see the ENTITIES loop
 *             below, which walks d->ndrawn and has no JW_BLOCK case): a
 *             ブロック reference's contents -- mirrored or not -- are
 *             simply absent from today's DXF output, a bigger, separate
 *             gap than the mirrored-字 question nokori.md asks about
 *             (nokori.md 2-2, 反転した参照の中の字).  tmp/orig_blktxt.dxf
 *             (kept out of git; reproduce with the command above) is the
 *             measurement.
 *   ENTITIES  LINE, CIRCLE, ARC, POINT, TEXT, SOLID
 *
 * Coordinates are (the paper point + half the sheet) times the scale of the
 * layer group the element is on.  Every line of three drawings came out on
 * that rule with nothing left over.
 *
 * Numbers are written the shortest way that reads back the same -- the
 * original writes 56433.59268365219 with sixteen digits and
 * 31301.545376575129 with seventeen, which is neither %.16g nor %.17g.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"
#include "cp932.h"
#include "text.h"
#include "d25view.h"
#include "gen/dxf.h"

/* --- a growing buffer --------------------------------------------------- */

typedef struct {
    unsigned char *b;
    long n, cap;
    int bad;
    int utf8;                   /* 2214: 字を UTF-8 で（下の str_）       */
} buf_t;

static void put(buf_t *o, const void *p, long n)
{
    if (o->bad)
        return;
    if (o->n + n > o->cap) {
        long c = o->cap ? o->cap * 2 : 65536;
        unsigned char *q;

        while (c < o->n + n)
            c *= 2;
        q = (unsigned char *)realloc(o->b, (size_t)c);
        if (!q) {
            o->bad = 1;
            return;
        }
        o->b = q;
        o->cap = c;
    }
    memcpy(o->b + o->n, p, (size_t)n);
    o->n += n;
}

static void puts_(buf_t *o, const char *s)
{
    put(o, s, (long)strlen(s));
}

/* --- the pieces of a DXF ------------------------------------------------ */

/* "%3d\r\n" -- every group code is written in three columns. */
static void code(buf_t *o, int c)
{
    char t[16];

    sprintf(t, "%3d\r\n", c);
    puts_(o, t);
}

/* 2214 UTF-8: 原典の字の書き手 FUN_004a7e90 は DAT_00a0eee0 が立っていれば
   符号頁を 0 (CP_ACP = Shift-JIS) から 0xfde9 (65001 = UTF-8) に替えて
   WideCharToMultiByte する（0x4a7ed2）。字ごとに 1000 バイトまで */
static void put_utf8(buf_t *o, const char *v)
{
    long n = (long)strlen(v), m, i;
    unsigned short *w;

    m = jw_to_utf16(v, n, 0, 0);
    w = (unsigned short *)malloc((size_t)(m > 0 ? m : 1) * sizeof *w);
    if (!w) {
        o->bad = 1;
        return;
    }
    m = jw_to_utf16(v, n, w, m);
    for (i = 0; i < m; i++) {
        unsigned long u = w[i];
        unsigned char t[4];
        int k = 0;

        if (u >= 0xd800 && u < 0xdc00 && i + 1 < m && w[i + 1] >= 0xdc00 &&
            w[i + 1] < 0xe000) {
            u = 0x10000 + ((u - 0xd800) << 10) + (w[i + 1] - 0xdc00);
            i++;
        }
        if (u < 0x80)
            t[k++] = (unsigned char)u;
        else if (u < 0x800) {
            t[k++] = (unsigned char)(0xc0 | (u >> 6));
            t[k++] = (unsigned char)(0x80 | (u & 0x3f));
        } else if (u < 0x10000) {
            t[k++] = (unsigned char)(0xe0 | (u >> 12));
            t[k++] = (unsigned char)(0x80 | ((u >> 6) & 0x3f));
            t[k++] = (unsigned char)(0x80 | (u & 0x3f));
        } else {
            t[k++] = (unsigned char)(0xf0 | (u >> 18));
            t[k++] = (unsigned char)(0x80 | ((u >> 12) & 0x3f));
            t[k++] = (unsigned char)(0x80 | ((u >> 6) & 0x3f));
            t[k++] = (unsigned char)(0x80 | (u & 0x3f));
        }
        put(o, t, k);
    }
    free(w);
}

static void str_(buf_t *o, int c, const char *v)
{
    code(o, c);
    if (o->utf8)
        put_utf8(o, v);
    else
        puts_(o, v);
    puts_(o, "\r\n");
}

/* an integer value, in five columns: that is how 62 and 70..78 come out */
static void int5(buf_t *o, int c, int v)
{
    char t[24];

    code(o, c);
    sprintf(t, "%5d\r\n", v);
    puts_(o, t);
}

/* Seventeen significant digits, **cut off** rather than rounded, with the
 * trailing zeros taken off afterwards.  That is what the original does, and
 * it is not what %.17g does: the double behind 36433.5937382171468925 comes
 * out of printf as ...147 but the original writes ...146, and
 * 31301.5453765751299215 keeps all seventeen where printf would round it to
 * sixteen.  Cutting fits all three of those and everything else in four
 * drawings' worth of DXF.
 */
static void number(char *t, double v)
{
    char b[64];
    const char *p, *e;
    char *o = t;
    int sig = 0, seen = 0, dot = 0;

    sprintf(b, "%.20g", v);
    e = strpbrk(b, "eE");
    for (p = b; *p && p != e; p++) {
        if (*p == '-' || *p == '+') {
            *o++ = *p;
            continue;
        }
        if (*p == '.') {
            dot = 1;
            *o++ = '.';
            continue;
        }
        if (*p < '0' || *p > '9') {
            *o++ = *p;
            continue;
        }
        if (*p != '0')
            seen = 1;
        if (sig < 17) {
            *o++ = *p;
            if (seen)
                sig++;
        } else if (!dot) {
            *o++ = '0';         /* keep the size, lose the digit */
        } else {
            break;              /* the rest of the fraction goes */
        }
    }
    *o = 0;
    if (strchr(t, '.')) {       /* trailing zeros, and a bare point */
        o = t + strlen(t) - 1;
        while (o > t && *o == '0')
            *o-- = 0;
        if (*o == '.')
            *o = 0;
    }
    if (e)
        strcat(t, e);
}

static void real(buf_t *o, int c, double v)
{
    char t[48];

    code(o, c);
    number(t, v);
    puts_(o, t);
    puts_(o, "\r\n");
}

/* Radians to degrees, dividing before multiplying: the original's own order.
   The other way round is a bit out in the last place -- a text of Test5.jww
   comes to -100.00000067721585 this way and ...84 the other. */
static double deg(double rad)
{
    return rad / 3.14159265358979323846 * 180.0;
}

/* --- the drawing's own numbers ------------------------------------------ */

/* The scale of a layer group, as a number to multiply paper millimetres by:
   a 1/200 drawing has 200 here. */
static double group_scale(const jw_drawing *d, int g)
{
    double s = g >= 0 && g < 16 ? d->group[g].scale : 1.0;

    return s > 0.0 ? s : 1.0;
}

static int write_group(const jw_drawing *d)
{
    int g, wg = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    return wg;
}

/* --- entities ----------------------------------------------------------- */

/* line type 1..9 -> the name in the LTYPE table */
static const char *const LTYPE[9] = {
    "CONTINUOUS", "DASHED1", "DASHED2", "DASHED3", "CENTER1",
    "CENTER2", "PHANTOM1", "PHANTOM2", "DOT"
};

/* pen 1..9 -> the DXF colour number, read out of the original by drawing one
   line in each pen and asking it for a DXF (tools/mkpens.c) */
static const short COLOUR[9] = { 132, 18, 92, 52, 212, 5, 136, 230, 211 };

static const char *ltype_name(const jw_obj *o)
{
    int t = o->ltype % 100;

    return LTYPE[t >= 1 && t <= 9 ? t - 1 : 0];
}

/* Colour 10 is 「任意色」 and carries its own RGB in the trailing long.  The
 * original puts it on the nearest of AutoCAD's first nine colours: the 79
 * solids of Ａマンション平面例.jww are 0xc0c0c0 and came out as 9, which is
 * that palette's light grey exactly. */
static int colour_any(unsigned int rgb)
{
    static const unsigned int ACI[9] = {
        0xff0000, 0xffff00, 0x00ff00, 0x00ffff, 0x0000ff,
        0xff00ff, 0xffffff, 0x808080, 0xc0c0c0
    };
    int best = 7, i;
    long bd = 0;

    for (i = 0; i < 9; i++) {
        long dr = (long)((ACI[i] >> 16) & 0xff) - (long)((rgb >> 16) & 0xff);
        long dg = (long)((ACI[i] >> 8) & 0xff) - (long)((rgb >> 8) & 0xff);
        long db = (long)(ACI[i] & 0xff) - (long)(rgb & 0xff);
        long d = dr * dr + dg * dg + db * db;

        if (i == 0 || d < bd) {
            bd = d;
            best = i + 1;
        }
    }
    return best;
}

static int colour_of(const jw_obj *o)
{
    int c = o->color;

    if (c == 10) {
        unsigned int n = (unsigned int)o->n;

        /* the file keeps it as a COLORREF, 0x00bbggrr */
        return colour_any(((n & 0xff) << 16) | (n & 0xff00)
                          | ((n >> 16) & 0xff));
    }
    return COLOUR[c >= 1 && c <= 9 ? c - 1 : 1];
}

/* `_<group>-<layer>_<name>`, with the layer as one hex digit.
 *
 * A space in the name becomes an underscore, a full-width one too -- and
 * that is the only change: the original left the 中黒 of 「測定位置・表示枠」
 * and the 全角ハイフン of 「計画建物－天空率」 alone, while 「　屋 根」 came out
 * as `__屋_根`. */
static void name_conv(const char *nm, char *out, int k, int n)
{
    out[k] = 0;
    if (!nm)
        return;
    while (*nm && k < n - 2) {
        unsigned char c = (unsigned char)nm[0];

        if (c == 0x81 && (unsigned char)nm[1] == 0x40) {
            out[k++] = '_';             /* the full-width space */
            nm += 2;
        } else if (c == ' ') {
            out[k++] = '_';
            nm++;
        } else if (jw_is_lead(c) && nm[1]) {
            out[k++] = nm[0];
            out[k++] = nm[1];
            nm += 2;
        } else {
            out[k++] = *nm++;
        }
    }
    out[k] = 0;
}

/* 2203 レイヤ名に番号を付加する（DAT_00a0eed0、CDxfPage +0xcc）。原典の
 * レイヤ名の作り FUN_0049dea0: 番号を付けないのは、切で しかも 名前（直した
 * あと）が空でなく、グループ順に それより前の 16×16 のどのレイヤ（物の無い
 * ものも）とも同じ名前でないとき（0x49e044。比べは FUN_00414010）。そう
 * でなければ「_%1x-%1x_」を頭に。直し方は FUN_0049d480 で、全角・半角の
 * 空白と **( )** を '_' にする。移植の直し方（name_conv）は ( ) をそのまま
 * にしている（既定の書き出しを変えないため、ここでは触らない）。 */
static void layer_name(const jw_drawing *d, int g, int l, char *out, int n,
                       int numbered)
{
    char mine[128], other[128];
    int g2, l2, dup = 0;

    name_conv(jw_str(d, d->group[g].layer_name[l]), mine, 0, (int)sizeof mine);
    if (!numbered && mine[0]) {
        for (g2 = 0; g2 <= g && !dup; g2++)
            for (l2 = 0; l2 < 16; l2++) {
                if (g2 == g && l2 == l)
                    break;
                name_conv(jw_str(d, d->group[g2].layer_name[l2]), other, 0,
                          (int)sizeof other);
                if (!strcmp(other, mine)) {
                    dup = 1;
                    break;
                }
            }
        if (!dup) {
            snprintf(out, (size_t)n, "%s", mine);
            return;
        }
    }
    name_conv(jw_str(d, d->group[g].layer_name[l]), out,
              sprintf(out, "_%x-%x_", g & 15, l & 15), n);
}

/* 既定（原典の既定の箱）: 番号 入・点を円で 切・Shift-JIS */
int jw_dxf_write(const jw_drawing *d, unsigned char **out, long *n)
{
    jw_dxf_opt opt;

    opt.point_circle = 0;
    opt.layer_number = 1;
    opt.utf8 = 0;
    return jw_dxf_write_opt(d, &opt, out, n);
}

/* 基本設定 DXF・SXF・JWC タブ（CDxfPage、DDX FUN_004a9d90・OK FUN_004a9a90）
 * の箱のうち DXF 書き出し（点 FUN_00429a10・レイヤ名 FUN_0049dea0・字の
 * 書き手 FUN_004a7e90）が読むのは
 * 2202（DAT_00a0eed4）・2203（eed0）・2214（eee0）の三つだけ。
 * 2205 Shift-JIS（eedc）は 2214 の対の印で、書き手は読まない。
 * 2200 図面範囲を読取る（eec8）・2199 色を初期化する（eee4）は DXF 読込み、
 * 2207 背景色と同じ色を反転（eee8）は SXF 読込み、2208 補助線を出力しない
 * （eeec）は SXF 書き出し FUN_005e6670（0x5e72b0）が読むもので、DXF の
 * 書き出しは読まない（補助線は いつも ADD_LINE に出る）。
 * 2204 JWW2DXFConv.dll は 外の DLL に任せる道で 移植には無い。 */
int jw_dxf_write_opt(const jw_drawing *d, const jw_dxf_opt *opt,
                     unsigned char **out, long *n)
{
    buf_t o;
    double hw, hh, sc;
    int i, g, l, wg, nlayer = 0, numbered;
    char name[128];
    char used[16][16];

    if (!d || !out || !n || !opt)
        return 0;
    memset(&o, 0, sizeof o);
    o.utf8 = opt->utf8 != 0;
    numbered = opt->layer_number != 0;
    hw = d->paper_hw;
    hh = d->paper_hh;
    wg = write_group(d);
    sc = group_scale(d, wg);

    /* HEADER and VPORT, with the eight numbers of this drawing in them */
    {
        double v[8];

        v[0] = 2 * hw * sc;             /* $EXTMAX x */
        v[1] = 2 * hh * sc;             /* $EXTMAX y */
        v[2] = v[0];                    /* $LIMMAX   */
        v[3] = v[1];
        v[4] = sc;                      /* $LTSCALE  */
        v[5] = hw * sc;                 /* the viewport's centre */
        v[6] = hh * sc;
        v[7] = 2 * hh * sc;             /* and its height */
        for (i = 0; i < JW_DXF_NPRO; i++) {
            put(&o, jw_dxf_pro[i].b, jw_dxf_pro[i].n);
            if (i < 8) {
                char t[48];

                number(t, v[i]);
                puts_(&o, t);
                puts_(&o, "\r\n");
            }
        }
    }

    /* LTYPE and STYLE, the same in every drawing */
    put(&o, jw_dxf_tables, JW_DXF_NTABLES);

    /* LAYER: every group and layer that has something on it, and ADD_LINE */
    memset(used, 0, sizeof used);
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *e = &d->obj[i];

        if (!jw_text_drawn(e))
            continue;           /* and so its layer is not named either */
        if (e->lgroup < 16 && e->layer < 16 && !used[e->lgroup][e->layer]) {
            used[e->lgroup][e->layer] = 1;
            nlayer++;
        }
    }
    str_(&o, 0, "TABLE");
    str_(&o, 2, "LAYER");
    int5(&o, 70, nlayer + 1);
    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++) {
            if (!used[g][l])
                continue;
            layer_name(d, g, l, name, (int)sizeof name, numbered);
            str_(&o, 0, "LAYER");
            str_(&o, 2, name);
            int5(&o, 70, 64);
            int5(&o, 62, 7);
            str_(&o, 6, "CONTINUOUS");
        }
    str_(&o, 0, "LAYER");
    str_(&o, 2, "ADD_LINE");
    int5(&o, 70, 64);
    int5(&o, 62, 7);
    str_(&o, 6, "CONTINUOUS");
    str_(&o, 0, "ENDTAB");
    str_(&o, 0, "ENDSEC");

    /* BLOCKS: nothing in it -- see the file header's 2026-10-19 note.  A
       ブロック reference's definition (real BLOCK/INSERT, in the original)
       is not written here; neither is its content as flattened entities
       (the way src/plot.c's pdf_block does for PDF).  Left as found. */
    str_(&o, 0, "SECTION");
    str_(&o, 2, "BLOCKS");
    str_(&o, 0, "ENDSEC");

    /* ENTITIES */
    str_(&o, 0, "SECTION");
    str_(&o, 2, "ENTITIES");
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *e = &d->obj[i];
        double s = group_scale(d, e->lgroup);
        double x0, y0, x1, y1;
        jw_obj round;

        /* A 円ソリッド comes out as the bare CIRCLE or ARC of its rim: the
           original drops the fill, and writes no line closing a part of a
           circle either -- decomp/res/rsolid.dxf has the two of them as one
           CIRCLE and one ARC and nothing else. */
        if (jw_round_solid(e, &round))
            e = &round;
        /* a text with no length to it is not written at all */
        if (!jw_text_drawn(e))
            continue;
        /* a 補助線 goes on the layer the original keeps for them */
        if ((e->ltype % 100) == 9)
            strcpy(name, "ADD_LINE");
        else
            layer_name(d, e->lgroup & 15, e->layer & 15, name,
                       (int)sizeof name, numbered);
        x0 = (e->d[0] + hw) * s;
        y0 = (e->d[1] + hh) * s;
        x1 = (e->d[2] + hw) * s;
        y1 = (e->d[3] + hh) * s;
        switch (e->cls) {
        case JW_SEN:
            str_(&o, 0, "LINE");
            str_(&o, 8, name);
            str_(&o, 6, ltype_name(e));
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 11, x1);
            real(&o, 21, y1);
            break;
        case JW_ENKO: {
            double r = e->d[2] * s, a0 = e->d[3], sw = e->d[4];
            int full;

            if (e->d[6] != 1.0) {
                /* DXF R12 has no ellipse, so the original walks it in ten
                 * degree steps of the parameter and writes a line for each,
                 * with a short one at the end.  Read off the twelve of
                 * Ａマンション平面例.jww: every vertex sits at a0 + k * 10
                 * degrees. */
                double flat = e->d[6], tilt = e->d[5];
                double ct = cos(tilt), st = sin(tilt);
                double step = sw < 0.0 ? -10.0 : 10.0;
                double endt = deg(sw), px = 0, py = 0;
                int k;

                /* every ten degrees of the parameter, and then the end --
                   always, even when the last step landed on it, which is why
                   a whole turn finishes with a line that goes nowhere */
                for (k = 0; ; k++) {
                    double t = (double)k * step;
                    int last = (step > 0.0) ? t > endt : t < endt;
                    double a, ux, uy, qx, qy;

                    if (last)
                        t = endt;
                    a = a0 + t * 3.14159265358979323846 / 180.0;
                    ux = e->d[2] * cos(a);
                    uy = e->d[2] * flat * sin(a);
                    /* the centre is put on the sheet first and the ellipse's
                       own offsets are scaled on their own */
                    qx = (e->d[0] + hw) * s + (ux * ct - uy * st) * s;
                    qy = (e->d[1] + hh) * s + (ux * st + uy * ct) * s;
                    if (k == 0) {
                        px = qx; /* the first line is a point: the original
                                    starts with its pen already there */
                        py = qy;
                    }
                    str_(&o, 0, "LINE");
                    str_(&o, 8, name);
                    str_(&o, 6, ltype_name(e));
                    int5(&o, 62, colour_of(e));
                    real(&o, 10, px);
                    real(&o, 20, py);
                    real(&o, 11, qx);
                    real(&o, 21, qy);
                    px = qx;
                    py = qy;
                    if (last || k > 4000)
                        break;
                }
                break;
            }
            /* a whole turn is a CIRCLE, however the drawing writes it:
               some of them keep 2 pi in the sweep rather than nothing */
            full = sw == 0.0 || sw >= 6.283185 || sw <= -6.283185;
            str_(&o, 0, full ? "CIRCLE" : "ARC");
            str_(&o, 8, name);
            str_(&o, 6, ltype_name(e));
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 40, r);
            if (!full) {
                /* The tilt turns the whole arc; each part is turned into
                   degrees on its own, which is where the last digit of
                   184.58407592773437 comes from */
                double d0 = deg(a0) + deg(e->d[5]);
                double d1 = deg(a0) + deg(sw) + deg(e->d[5]);

                /* a DXF arc always runs anticlockwise, so a negative sweep
                   comes out the other way round and both ends are brought
                   into 0..360 -- the original wrote 270 and 0 where the
                   drawing has 0 and -90 */
                if (sw < 0.0) {
                    double t = d0;

                    d0 = d1;
                    d1 = t;
                }
                /* jw_prefold first: the drawing may hold 1e12 radians and
                   a turn at a time would never get there.  See src/jww.h. */
                d0 = jw_prefold(d0, 360.0);
                d1 = jw_prefold(d1, 360.0);
                while (d0 < 0.0) d0 += 360.0;
                while (d0 >= 360.0) d0 -= 360.0;
                while (d1 < 0.0) d1 += 360.0;
                while (d1 >= 360.0) d1 -= 360.0;
                real(&o, 50, d0);
                real(&o, 51, d1);
            }
            break;
        }
        case JW_TEN:
            /* 2202 点を円で出力する（DAT_00a0eed4）: 点の書き手
               FUN_00429a10 は「POINT」の代わりに「CIRCLE」と書き、同じ
               8・62・10・20 のあとに 40 = 0.4 × 縮尺（FUN_004a93a0） */
            str_(&o, 0, opt->point_circle ? "CIRCLE" : "POINT");
            str_(&o, 8, name);
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            if (opt->point_circle)
                real(&o, 40, 0.4 * s);
            break;
        case JW_MOJI: {
            double dx = e->d[2] - e->d[0], dy = e->d[3] - e->d[1];
            double ang = deg(atan2(dy, dx));

            str_(&o, 0, "TEXT");
            str_(&o, 8, name);
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 40, e->d[5] * s);
            real(&o, 41, e->d[5] != 0.0 ? e->d[4] / e->d[5] : 1.0);
            real(&o, 50, ang);
            str_(&o, 1, jw_str(d, e->text));
            break;
        }
        case JW_SOLID:
            str_(&o, 0, "SOLID");
            str_(&o, 8, name);
            str_(&o, 6, ltype_name(e));
            int5(&o, 62, colour_of(e));
            real(&o, 10, x0);
            real(&o, 20, y0);
            real(&o, 11, x1);
            real(&o, 21, y1);
            /* DXF wants the last two corners the other way round -- the
               bowtie order a SOLID is drawn in */
            real(&o, 12, (e->d[6] + hw) * s);
            real(&o, 22, (e->d[7] + hh) * s);
            real(&o, 13, (e->d[4] + hw) * s);
            real(&o, 23, (e->d[5] + hh) * s);
            break;
        default:
            break;
        }
    }
    str_(&o, 0, "ENDSEC");
    str_(&o, 0, "EOF");

    if (o.bad) {
        free(o.b);
        return 0;
    }
    *out = o.b;
    *n = o.n;
    return 1;
}

/* ２．５D（32937）の DXF出力（2554）-- CZukei25D の「DXF出力」釦。
 *
 * 出典（2026-10-18、全文読んだ）:
 *   command 2554 は `all_005c7556.c:34264` の 19 バイトの飛び先
 *   `FUN_006126b0`（0 callers 表示だが 間接のバーの表の飛び先、他の
 *   command から 同じ形で 006125c0→FUN_0060b020 などへ飛ぶのと 同じ並び）
 *   を経て `FUN_006172c0`（884 バイト、`all_005c7556.c:35960`・
 *   `all_00599e67.c:58282`、1 caller）を 呼ぶ。中身:
 *     FUN_00617f70()       -- 立体を組み直す（port の build()、
 *                              `src/d25view.c:1814` に 既に 出典あり）
 *     FUN_007b3573(...)    -- 「名前を付けて保存」のダイアログ
 *                              （フィルタ "Dxf|*.DXF|"）
 *     FUN_0049c2c0(doc,flag,uVar2)
 *                          -- CDxfFile を構築（普通の 2D の DXF書き出し
 *                              と同じクラス、コンストラクタは
 *                              `all_004894cd.c:11467`）
 *     local_32b4 = 1; FUN_004a7410(); local_32b4 = 0;
 *                          -- HEADER/TABLES/BLOCKS/ENTITIES/ENDSEC を
 *                              書く（`all_004894cd.c:17243`）。local_32b4
 *                              はこの関数自身のスタックの並びと数が
 *                              一致せず（0x9d94 台の変数の後に 0x32b4 が
 *                              来ている）、何を指しているか 確認できて
 *                              いない。
 *   ENTITIES を書く `FUN_004a7970`（`all_004894cd.c:17449`）は、
 *   CDxfFile の `in_ECX[0x1b2]` が 立っていれば（この関数の中では
 *   立てていない。どこで立つかも 読み切れていない）通常の CData の
 *   一覧（`FUN_00572030`/`FUN_00572100`）の代わりに `FUN_00572c70`/
 *   `FUN_00572cd0` -- `FUN_00617f70`（build()）が 範囲を読むのに使う
 *   のと 同じ「3D の面・線・楕円の一覧」を 歩き、各要素の 自分の
 *   WriteDxf（vtable+0xc）を呼ぶだけ。
 *
 *   CData3DSolid（port の d25_face、ソリッドの面）の WriteDxf は
 *   `FUN_00441c10`（decomp/byclass/CData3DSolid.c:85-131）。全文読んだ
 *   結果、確実なのは:
 *     文字列 "3DFACE" を group 0 に書く
 *     四隅 x y z を 10/20/30・11/21/31・12/22/32・13/23/33 の組で、
 *     +0x258.. +0x2b0 の 12 個の double（3つずつ）から そのまま書く
 *       -- これは d25_face.p3（射影前の生の 3D 座標、`one_solid`/
 *          `cs_face` の gx_pair/gx_xf の 直前の値、下の
 *          jw_d25_face3）と 同じ並びのはず
 *     8（レイヤ名）・6（線種名）を 書く（FUN_0049dea0・FUN_0049dcf0 の
 *       呼び方が 変数の使い回しで 読みにくく、色（62）をどこで書くかは
 *       確認できなかった）
 *     最後に group 70（FUN_004a7e10(0x46)、辺の見え消し旗）を 書く。
 *       実際の値（旗の立て方）は 確認できていない。
 *
 *   CData3DSen（線）・CData3DEnko（楕円）の WriteDxf は 読んでいない
 *   （時間の都合）。したがって この port は 面（d25_face、ソリッドの
 *   4 面体・円ソリッドの面）だけを 3DFACE で書き、立体の輪郭線や
 *   アイソメの楕円（ln[]・el[]）は まだ 書かない。
 *
 *   HEADER の $EXTMIN/$EXTMAX 等は 原典では 立体の実際の範囲（build()
 *   が 計算する cx/cy/cz・r_x/r_y/r_z に 相当する値）から 来るはずだが、
 *   その式を読み切る時間が無く、ここでは 通常の 2D 書き出し
 *   （jw_dxf_write_opt）と 同じ 用紙基準の式を そのまま使っている――
 *   確認できていない 近似。
 *
 *   座標の単位: d25_face.p3 の x・y は 元の CDataSolid の d[] と同じ
 *   （紙の mm）、z は build() が #lv/#lh の文字から 作った高さで、
 *   どちらも 同じ縮尺を掛けてよいという 確証は無い。ここでは 他の
 *   entity と同じ「(値＋半紙)×層の縮尺」を x・y に、z には 半紙を
 *   加えず 同じ層の縮尺だけを 掛ける、という 等方な近似にした――
 *   未確認。
 *
 *   原典が 書いた 2.5D の DXF サンプルは decomp/res に一つも無く
 *   （2.5D は原典を動かして確かめる手段が無い）、バイト一致で固定する
 *   試験は作れない。tests/d25_test.c には 構造だけを固定した試験が
 *   ある。
 */
int jw_d25_dxf_write(const jw_drawing *d, unsigned char **out, long *n)
{
    buf_t o;
    double hw, hh, sc;
    int i, g, l, wg, nlayer = 0, numbered, nf;
    char name[128];
    char used[16][16];

    if (!d || !out || !n)
        return 0;
    memset(&o, 0, sizeof o);
    o.utf8 = 0;
    numbered = 1;
    hw = d->paper_hw;
    hh = d->paper_hh;
    wg = write_group(d);
    sc = group_scale(d, wg);

    /* HEADER/VPORT: 2D の書き出しと同じ式（上のコメントの通り、2.5D 固有の
       範囲の式は未確認の近似） */
    {
        double v[8];

        v[0] = 2 * hw * sc;
        v[1] = 2 * hh * sc;
        v[2] = v[0];
        v[3] = v[1];
        v[4] = sc;
        v[5] = hw * sc;
        v[6] = hh * sc;
        v[7] = 2 * hh * sc;
        for (i = 0; i < JW_DXF_NPRO; i++) {
            put(&o, jw_dxf_pro[i].b, jw_dxf_pro[i].n);
            if (i < 8) {
                char t[48];

                number(t, v[i]);
                puts_(&o, t);
                puts_(&o, "\r\n");
            }
        }
    }

    /* LTYPE と STYLE: 2D の書き出しと同じ、変わらない並び */
    put(&o, jw_dxf_tables, JW_DXF_NTABLES);

    /* LAYER: 面が持つ層だけ（通常の 2D と同じ組立て） */
    memset(used, 0, sizeof used);
    nf = jw_d25_nface();
    for (i = 0; i < nf; i++) {
        int ltype, color, layer, lgroup;

        if (!jw_d25_face_meta(i, &ltype, &color, &layer, &lgroup))
            continue;
        if (lgroup < 16 && layer < 16 && !used[lgroup][layer]) {
            used[lgroup][layer] = 1;
            nlayer++;
        }
    }
    str_(&o, 0, "TABLE");
    str_(&o, 2, "LAYER");
    int5(&o, 70, nlayer + 1);
    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++) {
            if (!used[g][l])
                continue;
            layer_name(d, g, l, name, (int)sizeof name, numbered);
            str_(&o, 0, "LAYER");
            str_(&o, 2, name);
            int5(&o, 70, 64);
            int5(&o, 62, 7);
            str_(&o, 6, "CONTINUOUS");
        }
    str_(&o, 0, "LAYER");
    str_(&o, 2, "ADD_LINE");
    int5(&o, 70, 64);
    int5(&o, 62, 7);
    str_(&o, 6, "CONTINUOUS");
    str_(&o, 0, "ENDTAB");
    str_(&o, 0, "ENDSEC");

    /* BLOCKS: 空 */
    str_(&o, 0, "SECTION");
    str_(&o, 2, "BLOCKS");
    str_(&o, 0, "ENDSEC");

    /* ENTITIES: 面だけを 3DFACE で（上のコメントの通り、線・楕円は未対応） */
    str_(&o, 0, "SECTION");
    str_(&o, 2, "ENTITIES");
    for (i = 0; i < nf; i++) {
        double p[12], s;
        int ltype, color, layer, lgroup, c;
        jw_obj fake;

        if (!jw_d25_face3(i, p) || !jw_d25_face_meta(i, &ltype, &color, &layer, &lgroup))
            continue;
        memset(&fake, 0, sizeof fake);
        fake.ltype = (unsigned short)ltype;
        fake.color = (unsigned short)color;
        s = group_scale(d, lgroup);
        if ((ltype % 100) == 9)
            strcpy(name, "ADD_LINE");
        else
            layer_name(d, lgroup & 15, layer & 15, name, (int)sizeof name, numbered);
        str_(&o, 0, "3DFACE");
        str_(&o, 8, name);
        str_(&o, 6, ltype_name(&fake));
        int5(&o, 62, colour_of(&fake));
        for (c = 0; c < 4; c++) {
            static const int gx[4] = { 10, 11, 12, 13 };
            static const int gy[4] = { 20, 21, 22, 23 };
            static const int gz[4] = { 30, 31, 32, 33 };

            real(&o, gx[c], (p[c * 3 + 0] + hw) * s);
            real(&o, gy[c], (p[c * 3 + 1] + hh) * s);
            real(&o, gz[c], p[c * 3 + 2] * s);
        }
    }
    str_(&o, 0, "ENDSEC");
    str_(&o, 0, "EOF");

    if (o.bad) {
        free(o.b);
        return 0;
    }
    *out = o.b;
    *n = o.n;
    return 1;
}
