/* Writing an SFC -- 「SFC形式で保存」 (menu 32976).
 *
 * orig/common_lib.dll only does the low-level part21 encoding (its exports
 * are SXFopen_part21/SXFwrite_next_feature/SXFwrite_table/...,
 * decomp/byclass/_unassigned.c:205264-205309 -- the GetProcAddress list the
 * original's CSxfFile constructor FUN_005daa80 builds,
 * decomp/byclass/_unassigned.c:205173).  The feature *text* itself --
 * "line_feature(...)", "sfig_org_feature(...)" and so on -- is built by the
 * original (jw_win.exe) itself, in one big function, FUN_005e6670
 * (decomp/byclass/_unassigned.c:211565, CMiniDoc::Serialize's SXF-writing
 * branch calls it at decomp/byclass/CMiniDoc.c:1343-1345): the literal
 * strings "POLYLINE" and "SFIG_LOCATE" that this function writes through a
 * `(**(code**)(obj+0x4c158))(name, ...)` call are right there in it
 * (decomp/byclass/_unassigned.c:212461,212558 -- lines 897 and 994 of the
 * function's own body).  So what follows is the shape of the files it
 * produces, which RESUME.md sets out.  The three things that took the
 * longest to see:
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
 *
 * ブロックの参照 (JW_LIST/JW_BLOCK): 2026-10-19、FUN_005e6670 の中を読み
 * 直して実装した。原典実機では確認できていない（nokori.md の既存の記録
 * どおり、原典に SFC を書き出させても ENTITIES 相当へ進む前に切れる）ので
 * 以下はすべて逆コンパイルの読みだけに基づく（原典では押していない）:
 *
 *   * ブロックの参照 (CDataBlock) の SXF 書き手はその vtable slot[4]
 *     FUN_0049b930 (decomp/byclass/CDataBlock.c:333-442): 自分の定義
 *     (list[0]) を数字にした figure 名 "-%03d-%s" を作り (FUN_0049aa30 を
 *     "-GLay-%x-%s" と同じ形で呼ぶ、行 391)、SFIG_LOCATE を一つ書く
 *     (行 431)。参照の倍率 (d[2],d[3]) に 参照自身の層グループの縮尺を掛け、
 *     定義 (JW_LIST) 自身の層グループの縮尺で割っている (行 414-428 の
 *     `dVar1*dVar2 / *(... + iVar4*8)`、iVar4 は定義側の `(**(+0x28))()` --
 *     層グループの番号を返す呼び出し) -- 定義の figure が「定義の層グルー
 *     プの縮尺の逆数」で置かれる (下のグループの sfig_locate_feature と
 *     同じ約束) ことと対になる換算。local_144 (FUN_0042afb0 の戻り、
 *     層・ペンから作る小さい整数) が -999 なら SFIG_LOCATE を書かない
 *     (行 429) -- dxf.c の find_def<0 の飛ばしと同じ役目の「定義が無い
 *     （壊れたファイル）なら書かない」節に見える。SFIG_LOCATE の実引数の
 *     正確な並び（位置・回転・倍率 X・Y がどの枠に入るか）はスタック上の
 *     構造体 (local_154/local_158、FUN_004efde0 が作る) 越しに渡っていて
 *     Ghidra がフィールドごとに分解していないため読み切れず、既存のグルー
 *     プの sfig_locate_feature ('色/層', 名前, x, y, 角, 倍率X, 倍率Y の
 *     7 引数) と同じ並びだろうという推定で実装した。
 *   * ブロックの定義 (JW_LIST) 自身の SXF 書き手は vtable slot[4] を持た
 *     ない (decomp/byclass/CDataList.c に CDataList[4] が無い -- CData の
 *     既定を継ぐ) ので、FUN_005e6670 自身が「定義の一覧を直接歩く」節を
 *     持つ: list[1] (+0x6c) が 0 でない定義だけ (decomp/byclass/
 *     _unassigned.c:212350 前後、dxf.c の block_name の注が言う
 *     CDataList::WriteDxf の同じ旗と同じ役目)、名前 "-%03d-%s" を作って
 *     (行 212356) 図形を開き (kind-2、`(**(+0x4c164))(2)`)、その CObList の
 *     メンバを一つずつ「自分の vtable+0x10 を呼ぶ」だけで書く (行
 *     212361-212363 の `(**(*member+0x10))()`) -- これは通常の要素
 *     (JW_SEN・JW_ENKO・...) を書く経路と同じ仕組みで、メンバの中に
 *     ネストしたブロック参照があれば 同じ CDataBlock[4] が再帰的に呼ばれる
 *     （入れ子の SFIG_LOCATE）。移植は want_colour 等で色・線種・幅の表を
 *     作る時点と、要素を書く switch を write_elem_feature() にまとめて
 *     ブロック定義のメンバにも同じ関数を適用する形にした。定義の figure
 *     の中は dxf.c の write_entity と同じ約束（紙の半幅・半高を足さない
 *     が、メンバ自身の層グループの縮尺はそのまま掛ける）とした -- SXF の
 *     決まった書き方を確認する手段が無いため、DXF 側の確認済みの約束を
 *     SXF でも成り立つ最も近い読みとして採った、未確認の類推。
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
static void ang(char *t, size_t cap, double v)
{
    double whole = fabs(v);
    int digits = 1, p;

    /* `whole` is counted as a double: a damaged file can hold 1e300 here,
       and turning that into an int to count its digits is undefined.  The
       same number then wants three hundred characters of "%.0f", which is
       what used to be written into a thirty-two byte frame -- found with
       -fsanitize=address over twenty fuzz seeds (tools/asan.sh). */
    if (!(whole < 1e300))
        whole = 1e300;
    while (whole >= 10.0) {
        whole /= 10.0;
        digits++;
    }
    p = 15 - digits;
    if (p < 0)
        p = 0;
    /* sixteen characters whatever the number is: digits + '.' + places --
       unless the number is far too big for the format, and then as much of
       it as fits */
    snprintf(t, cap, "%.*f", p, v);
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

/* A ブロック参照 (JW_BLOCK) の block が指す定義 (JW_LIST) を返す、-1 なら
   無い（壊れたファイル）。src/dxf.c の find_def と同じ探し方: jw_drawing
   の並びは d->ndrawn 本の描画済みのあと定義が続く（jw_drawing の冒頭の
   コメント）。 */
static int find_block_def(const jw_drawing *d, int blk)
{
    int i;

    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] == blk)
            return i;
    return -1;
}

/* ブロックの定義 (JW_LIST) が figure として出る名前 "-%03d-%s"：数字は
   list[0]（CDataBlock::WriteSXF, decomp/byclass/CDataBlock.c:391 の
   `*(local_148[0x25] + 0x68)` と同じ場所、src/dxf.c の block_name の
   注にある通り +0x68 = list[0]）、文字は グループの sfig_org_feature の
   名前と同じ 先頭の ASCII だけ・最大 8 文字（FUN_005e6670 が グループの
   "-GLay-%x-%s" と同じ FUN_0049aa30 の呼び方でこれを作っており、DXF の
   block_name のような ( )・空白の変換は別の関数 FUN_0049d480 の仕事
   （CDataList::WriteDxf、decomp/byclass/CDataList.c:207 でだけ呼ばれる）
   なので SXF 側では通らないと読んだ）。 */
static void block_fig_name(const jw_drawing *d, int def_i, char *out, int cap)
{
    const char *nm = jw_str(d, d->obj[def_i].text);
    int k = 0;

    while (nm[k] && (unsigned char)nm[k] < 0x80 && k < 8)
        k++;
    snprintf(out, (size_t)cap, "-%03d-%.*s", d->obj[def_i].list[0], k, nm);
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

/* One drawn element (not a JW_LIST/JW_BLOCK) as the feature(s) it is,
 * exactly what used to be the body of jw_sfc_write's per-group loop over
 * d->obj[0..d->ndrawn) -- pulled out so a ブロックの定義 (JW_LIST) can write
 * its own members the same way, through the same CData[4]-style virtual
 * dispatch FUN_005e6670 uses for both (see the comment at the top of this
 * file).  (hw, hh) is the paper origin the caller measures from: (d->paper_hw,
 * d->paper_hh) for an ordinary group, (0, 0) for an element inside a block
 * definition's own figure -- the same convention src/dxf.c's write_entity
 * uses for a BLOCK's members, carried over here without a way to check it
 * against the original's SXF output (see the top-of-file comment).  `sc` is
 * the scale this element's own layer group multiplies by, same as always.
 */
static void write_elem_feature(sfcw *s, const jw_drawing *d, const jw_obj *o,
                               double hw, double hh, double sc,
                               int *nfill, int *fill)
{
    char t[1024], a[32], b[32], c[32];
    int lay, col, fon, wid;

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

        /* jw_prefold first: a drawing may hold 1e12 radians, and a
           turn at a time would never get there.  See src/jww.h. */
        s0 = jw_prefold(s0, 360.0);
        s1 = jw_prefold(s1, 360.0);
        while (s0 < 0.0) s0 += 360.0;
        while (s0 >= 360.0) s0 -= 360.0;
        while (s1 < 0.0) s1 += 360.0;
        while (s1 >= 360.0) s1 -= 360.0;
        ang(a, sizeof a, s0);
        ang(b, sizeof b, s1);
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

            t0 = jw_prefold(t0, 360.0);
            t1 = jw_prefold(t1, 360.0);
            tu = jw_prefold(tu, 360.0);
            while (t0 < 0.0) t0 += 360.0;
            while (t0 >= 360.0) t0 -= 360.0;
            while (t1 < 0.0) t1 += 360.0;
            while (t1 >= 360.0) t1 -= 360.0;
            while (tu < 0.0) tu += 360.0;
            while (tu >= 360.0) tu -= 360.0;
            ang(a, sizeof a, t0);
            ang(b, sizeof b, t1);
            ang(c, sizeof c, tu);
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
        ang(a, sizeof a, 0.0);
        ang(b, sizeof b, 1.0);
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
        ang(a, sizeof a, deg);
        ang(b, sizeof b, 0.0);
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

            s0 = jw_prefold(s0, 360.0);
            s1 = jw_prefold(s1, 360.0);
            while (s0 < 0.0) s0 += 360.0;
            while (s0 >= 360.0) s0 -= 360.0;
            while (s1 < 0.0) s1 += 360.0;
            while (s1 >= 360.0) s1 -= 360.0;
            if (whole) {
                double half = s0 + 180.0;

                while (half >= 360.0) half -= 360.0;
                ang(a, sizeof a, s0);
                ang(b, sizeof b, half);
                snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                           "'%.6f','%.6f','0','%s','%s')", lay, col,
                        fon, wid, cx, cy, r, a, b);
                feature(&s->w, t);
                ang(a, sizeof a, half);
                ang(b, sizeof b, s0);
                snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                           "'%.6f','%.6f','0','%s','%s')", lay, col,
                        fon, wid, cx, cy, r, a, b);
                feature(&s->w, t);
            } else {
                double e0 = s0 * PI / 180.0, e1 = s1 * PI / 180.0;

                ang(a, sizeof a, s0);
                ang(b, sizeof b, s1);
                snprintf(t, sizeof t, "arc_feature('%d','%d','%d','%d','%.6f',"
                           "'%.6f','%.6f','%d','%s','%s')", lay, col,
                        fon, wid, cx, cy, r, sw < 0.0, a, b);
                feature(&s->w, t);
                /* and the chord back, from where it ends to where
                   it starts */
                snprintf(xs, sizeof xs, "(%.6f,%.6f)",
                         cx + r * cos(e1), cx + r * cos(e0));
                snprintf(ys, sizeof ys, "(%.6f,%.6f)",
                         cy + r * sin(e1), cy + r * sin(e0));
                snprintf(t, sizeof t, "polyline_feature('%d','%d','%d','%d',"
                           "'2','%s','%s')", lay, col, fon, wid,
                        xs, ys);
                feature(&s->w, t);
            }
            solid_end(s, nfill, fill, lay, col, fon, wid);
            break;
        }
        {   /* the four corners, the last three backwards */
            static const int K[5] = { 0, 3, 2, 1, 0 };
            int q, nx = 0, ny = 0;

            /* one corner of a damaged solid can be 1e300, which
               "%.6f" spells in three hundred characters, so every
               piece is measured against what is left */
            for (q = 0; q < 5; q++) {
                int room = (int)sizeof xs - nx - 2;
                if (room <= 0)
                    break;
                nx += snprintf(xs + nx, (size_t)room,
                               q ? ",%.6f" : "(%.6f",
                               (o->d[K[q] * 2] + hw) * sc);
                if (nx > (int)sizeof xs - 2)
                    nx = (int)sizeof xs - 2;
                room = (int)sizeof ys - ny - 2;
                if (room <= 0)
                    break;
                ny += snprintf(ys + ny, (size_t)room,
                               q ? ",%.6f" : "(%.6f",
                               (o->d[K[q] * 2 + 1] + hh) * sc);
                if (ny > (int)sizeof ys - 2)
                    ny = (int)sizeof ys - 2;
            }
            strcpy(xs + nx, ")");
            strcpy(ys + ny, ")");
        }
        snprintf(t, sizeof t, "polyline_feature('%d','%d','%d','%d','5','%s',"
                   "'%s')", lay, col, fon, wid, xs, ys);
        feature(&s->w, t);
        solid_end(s, nfill, fill, lay, col, fon, wid);
        break;
    }
    default:
        break;
    }
}

/* A ブロック参照 (JW_BLOCK) as the one SFIG_LOCATE feature CDataBlock's own
 * SXF writer (vtable slot[4], FUN_0049b930, decomp/byclass/CDataBlock.c:
 * 333-442) puts out for it -- see the citation at the top of this file for
 * what is, and is not, read off that function.  (hw, hh, sc) are the same
 * paper-origin/scale this reference's own group uses for an ordinary
 * element. */
static void write_block_ref_feature(sfcw *s, const jw_drawing *d,
                                    const jw_obj *o, double hw, double hh,
                                    double sc)
{
    char t[1024], name[160], a[32], b[32], c[32];
    int def_i, lay;
    double sx, sy, defsc, scx, scy;

    def_i = find_block_def(d, o->block);
    if (def_i < 0)
        return;                  /* a damaged file: nothing to point at,
                                     same as FUN_0049b930's -999 skip and
                                     src/dxf.c's find_def<0 skip */
    lay = want_layer(s, o);
    block_fig_name(d, def_i, name, (int)sizeof name);
    sx = o->d[2] != 0.0 ? o->d[2] : 1.0;   /* 0 means 1, jw_block_scale_xy */
    sy = o->d[3] != 0.0 ? o->d[3] : sx;    /* 0 means "same as x" */
    defsc = d->group[d->obj[def_i].lgroup & 15].scale;
    if (!(defsc > 0.0))
        defsc = 1.0;
    /* CDataBlock::WriteSXF divides the reference's own (scale * its own
       group's scale) by the *definition's* group's scale
       (decomp/byclass/CDataBlock.c:414-428) -- the figure the SFIG_LOCATE
       names was itself written at 1/defsc, the same convention the group
       sfig_locate_feature below uses for a layer group's own figure. */
    scx = sx * sc / defsc;
    scy = sy * sc / defsc;
    ang(a, sizeof a, f32(o->d[4] / PI * 180.0));
    ang(b, sizeof b, scx);
    ang(c, sizeof c, scy);
    snprintf(t, sizeof t, "sfig_locate_feature('%d',\\'%s\\','%.6f','%.6f',"
               "'%s','%s','%s')", lay, name,
            (o->d[0] + hw) * sc, (o->d[1] + hh) * sc, a, b, c);
    feature(&s->w, t);
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

    /* which layers carry something, in group and layer order -- including
       a ブロックの定義 (list[1] != 0) の own members, which get written as
       ordinary features inside the figure that stands for the block (see
       the top-of-file comment); members of a definition that is itself
       never referenced (list[1] == 0) are not */
    for (g = 0; g < 16; g++) {
        int l;

        for (l = 0; l < 16; l++) {
            int k, hit = 0;

            for (k = 0; k < d->ndrawn; k++)
                if ((d->obj[k].lgroup & 15) == g && (d->obj[k].layer & 15) == l
                    && d->obj[k].color != 9 && d->obj[k].ltype != 9
                    && jw_text_drawn(&d->obj[k])) {
                    hit = 1;
                    break;
                }
            if (!hit)
                for (k = d->ndrawn; k < d->nobj; k++) {
                    const jw_obj *def = &d->obj[k];
                    int m;

                    if (def->cls != JW_LIST || def->list[1] == 0)
                        continue;
                    for (m = k + 1; m < d->nobj && m <= k + def->n; m++) {
                        const jw_obj *o = &d->obj[m];

                        if (o->cls == JW_LIST)
                            break;
                        if (o->cls != JW_BLOCK
                            && (o->lgroup & 15) == g && (o->layer & 15) == l
                            && o->color != 9 && o->ltype != 9
                            && jw_text_drawn(o)) {
                            hit = 1;
                            break;
                        }
                    }
                    if (hit)
                        break;
                }
            if (hit && s->nlay < MAXLAY) {
                s->lay[s->nlay].g = g;
                s->lay[s->nlay].l = l;
                s->nlay++;
            }
        }
    }
    s->auxlay = s->nlay + 1;

    /* what the elements ask for, so the tables can be written first --
       again including the used block definitions' own members */
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (o->cls == JW_LIST || o->cls == JW_BLOCK || !jw_text_drawn(o))
            continue;
        want_colour(s, o->color);
        want_font(s, o->ltype);
        if (o->cls != JW_TEN && o->cls != JW_MOJI)
            want_width(s, o->color);
    }
    for (i = d->ndrawn; i < d->nobj; i++) {
        const jw_obj *def = &d->obj[i];
        int k;

        if (def->cls != JW_LIST || def->list[1] == 0)
            continue;
        for (k = i + 1; k < d->nobj && k <= i + def->n; k++) {
            const jw_obj *o = &d->obj[k];

            if (o->cls == JW_LIST)
                break;
            if (o->cls == JW_BLOCK || !jw_text_drawn(o))
                continue;
            want_colour(s, o->color);
            want_font(s, o->ltype);
            if (o->cls != JW_TEN && o->cls != JW_MOJI)
                want_width(s, o->color);
        }
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

    /* ------------------------------------------- the block definitions --
       FUN_005e6670's own "walk the definitions, list[1] != 0 only" loop
       (see the top-of-file comment); each used definition becomes its own
       figure, named "-%03d-%s", holding its members written exactly like
       ordinary elements -- the same write_elem_feature() the per-group
       loop below uses, through the same "virtual write" the original's
       CData[4] dispatch is.  Written before the per-group section so a
       later sfig_locate_feature (from a block reference on some layer
       group) can name a figure that already exists in the file, same as
       the group figures below are written before the figures-and-the-rest
       section that places them. */
    fill = (int *)malloc((size_t)(d->nobj + 1) * 2 * sizeof *fill);
    if (!fill) {
        free(s);
        return 0;
    }
    for (i = d->ndrawn; i < d->nobj; i++) {
        const jw_obj *def = &d->obj[i];
        int k, nfill = 0, any = 0;
        char name[160];

        if (def->cls != JW_LIST || def->list[1] == 0)
            continue;
        for (k = i + 1; k < d->nobj && k <= i + def->n; k++) {
            const jw_obj *o = &d->obj[k];
            double sc;

            if (o->cls == JW_LIST)
                break;
            if (o->cls == JW_BLOCK) {
                /* a nested block reference: CDataBlock[4] recursively
                   writes its own SFIG_LOCATE regardless of which figure
                   is being written (top-of-file comment) */
                sc = d->group[o->lgroup & 15].scale;
                if (!(sc > 0.0))
                    sc = 1.0;
                write_block_ref_feature(s, d, o, 0.0, 0.0, sc);
                any = 1;
                continue;
            }
            if (!jw_text_drawn(o))
                continue;
            sc = d->group[o->lgroup & 15].scale;
            if (!(sc > 0.0))
                sc = 1.0;
            /* src/dxf.c's write_entity comment: a block's own members are
               written at (0, 0) -- no paper half-width/-height -- but
               still times their own layer group's scale, same as any
               other element; applied here to SXF for lack of a way to
               check it against the original (same top-of-file caveat) */
            write_elem_feature(s, d, o, 0.0, 0.0, sc, &nfill, fill);
            any = 1;
        }
        for (k = 0; k < nfill; k++) {
            snprintf(t, sizeof t, "fill_area_style_colour_feature('%d','%d','%d','0',"
                       "'()')", fill[k * 2], fill[k * 2 + 1], k + 1);
            feature(&s->w, t);
        }
        if (any) {
            block_fig_name(d, i, name, (int)sizeof name);
            snprintf(t, sizeof t, "sfig_org_feature(\\'%s\\','1')", name);
            feature(&s->w, t);
        }
    }

    /* ----------------------------------------------------- the elements */
    for (g = 0; g < 16; g++) {
        double sc = d->group[g].scale > 0.0 ? d->group[g].scale : 1.0;
        int any = 0, nfill = 0;

        for (i = 0; i < d->ndrawn; i++) {
            const jw_obj *o = &d->obj[i];
            double hw = d->paper_hw, hh = d->paper_hh;

            if ((o->lgroup & 15) != g || o->cls == JW_LIST)
                continue;
            if (o->cls == JW_BLOCK) {
                write_block_ref_feature(s, d, o, hw, hh, sc);
                any = 1;
                continue;
            }
            if (!jw_text_drawn(o))
                continue;       /* a text with no length is not written */
            any = 1;
            write_elem_feature(s, d, o, hw, hh, sc, &nfill, fill);
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
                && jw_text_drawn(&d->obj[i]))
                any = 1;
        if (!any)
            continue;
        while (nm[k] && (unsigned char)nm[k] < 0x80 && k < 8)
            k++;
        ang(a, sizeof a, 0.0);
        ang(b, sizeof b, 1.0 / sc);
        ang(c, sizeof c, 1.0 / sc);
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
