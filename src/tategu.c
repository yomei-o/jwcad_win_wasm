/* 建具のデータ（`JW_OPT*.DAT`）を読む。src/tategu.h の頭の注を見てください。
 *
 * 行の取り方は原典の `FUN_005aa870` に合わせてあります —— 先頭の空白を
 * 飛ばし、`#` で始まる行と空行は読み飛ばし、残りを
 *
 *     " %lg %lg %lg %lg %lg %lg %d %ld %x %x %lg %lg %lg %lg %ld"
 *
 * で一度に取る。ここでは必要な十五個のうち前の九個までを使います
 * （残りが何かは原典の説明にも出てきません）。
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tategu.h"
#include "cmd.h"
#include "text.h"
#include "gen/tgdat.inc"

/* 一行ぶんの数。何個取れたかを返します。 */
static int scan_nums(const char *s, double *d, int max)
{
    int n = 0;

    while (n < max) {
        char *end;
        double v;

        while (*s == ' ' || *s == '\t')
            s++;
        if (!*s || *s == '"' || *s == '&')
            break;
        v = strtod(s, &end);
        if (end == s)
            break;
        d[n++] = v;
        s = end;
    }
    return n;
}

/* 九番目のレイヤだけは 16 進で読みます（原典の %x）。 */
static int scan_hex_at(const char *s, int which, int *out)
{
    int n = 0;

    for (;;) {
        char *end;

        while (*s == ' ' || *s == '\t')
            s++;
        if (!*s || *s == '"' || *s == '&')
            return 0;
        if (n == which) {
            long v = strtol(s, &end, 16);

            if (end == s)
                return 0;
            *out = (int)v;
            return 1;
        }
        (void)strtod(s, &end);
        if (end == s)
            return 0;
        s = end;
        n++;
    }
}

/* 円弧の 'E' と、そのあとの角度・扇形。説明の 13 */
static void scan_arc(const char *s, jw_tg_part *p)
{
    const char *e = s;

    while (*e) {
        if ((*e == 'E' || *e == 'e')
            && (e == s || e[-1] == ' ' || e[-1] == '\t')
            && (e[1] == ' ' || e[1] == '\t' || e[1] == 0
                || e[1] == '\r' || e[1] == '\n')) {
            double d[2];
            int k = scan_nums(e + 1, d, 2);

            p->arc = 1;
            if (k > 0)
                p->sweep = d[0];
            if (k > 1)
                p->sector = (int)d[1];
            return;
        }
        e++;
    }
}

/* 文字: `"…"` のあとに `$<フォント名>` と、斜体なら `/`。説明の 15 */
static void scan_text(const char *s, jw_tg_part *p)
{
    const char *a = strchr(s, '"'), *b;
    size_t k;

    if (!a)
        return;
    a++;
    b = strchr(a, '"');
    if (!b)
        b = a + strlen(a);
    k = (size_t)(b - a);
    if (k >= sizeof p->text)
        k = sizeof p->text - 1;
    memcpy(p->text, a, k);
    p->text[k] = 0;
    if (*b != '"')
        return;
    b++;
    if (b[0] == '$' && b[1] == '<') {
        const char *c = strchr(b + 2, '>');

        if (c) {
            k = (size_t)(c - (b + 2));
            if (k >= sizeof p->font)
                k = sizeof p->font - 1;
            memcpy(p->font, b + 2, k);
            p->font[k] = 0;
            /* フォント名のあとの / は斜体、そのあとの ! は太字 */
            if (c[1] == '/') {
                p->italic = 1;
                if (c[2] == '!')
                    p->bold = 1;
            } else if (c[1] == '!') {
                p->bold = 1;
            }
        }
    }
}

static const char *skip_space(const char *s)
{
    while (*s == ' ' || *s == '\t')
        s++;
    return s;
}

int jw_tategu_parse(jw_tategu *t, const char *b, long n)
{
    long i = 0;
    int in_item = 0, hidden = 0, head_seen = 0, circ_w = 0;
    double scale3 = 1.0;                /* 立面の 700（部材寸法の倍率）・750（円の半径の比） */
    jw_tg_item *it = 0;

    if (!t || !b)
        return 0;
    memset(t, 0, sizeof *t);
    while (i < n) {
        char line[512];
        const char *s;
        long j = i;
        size_t len;
        double d[16];
        int k;

        while (j < n && b[j] != '\n' && b[j] != '\r')
            j++;
        len = (size_t)(j - i);
        if (len >= sizeof line)
            len = sizeof line - 1;
        memcpy(line, b + i, len);
        line[len] = 0;
        i = j;
        while (i < n && (b[i] == '\n' || b[i] == '\r'))
            i++;

        s = skip_space(line);
        if (*s == '#') {                /* 一行目の # だけが札 */
            if (!t->title[0] && !head_seen) {
                size_t m = strlen(s + 1);

                if (m >= sizeof t->title)
                    m = sizeof t->title - 1;
                memcpy(t->title, s + 1, m);
                t->title[m] = 0;
            }
            continue;
        }
        if (!*s)
            continue;

        if (*s == 'S' || *s == 's') {   /* 見込・枠幅の基準。説明の 5 */
            if (it) {
                k = scan_nums(s + 1, d, 3);
                it->has_s = 1;
                it->base_mikomi = k > 0 ? d[0] : 100.0;
                it->base_wakuhaba = k > 1 ? d[1] : 100.0;
                /* 三つ目は芯ずれの自動計算と反転の指定。原典の読み手は
                   1.5 より大きいかどうかで見ています */
                it->s_flip = k > 2 && d[2] > 1.5;
                it->s_third = k > 2 && d[2] > 0.5;
            }
            continue;
        }
        if (*s == 'W' || *s == 'w') {   /* 内法の初期値。説明の 6 */
            if (it) {
                k = scan_nums(s + 1, d, 1);
                it->has_w = 1;
                it->uchinori = k > 0 ? d[0] : 0.0;
            }
            continue;
        }

        k = scan_nums(s, d, 16);
        if (k < 1)
            continue;

        if (!head_seen) {               /* 建具（図形）の数 */
            t->want = (int)d[0];
            head_seen = 1;
            continue;
        }

        /* 区切り: 990〜999。そのあとに見込・枠幅を書くと固定になります */
        if (d[0] >= 990.0 && d[0] <= 9999.0) {
            if (in_item && it) {
                double v = d[0] > 999.0 ? 999.0 : d[0];

                it->show = (v - 989.0) / 10.0;
                if (it->show > 1.0)
                    it->show = 1.0;
                if (k > 1)
                    it->fix_mikomi = d[1];
                if (k > 2)
                    it->fix_wakuhaba = d[2];
            }
            in_item = 0;
            it = 0;
            hidden = 0;
            continue;
        }

        if (!in_item) {                 /* 一件の頭: ブロック数と札 */
            const char *p2;

            /* **頭に書かれた件数ぶんで止めます。**同梱のファイルは
               どれも末尾に説明文が続いていて、その中の例が数字で
               始まるので、止めないとそこまで読んでしまいます。 */
            if (t->want > 0 && t->nitem >= t->want)
                break;
            if (t->nitem >= JW_TG_ITEMS)
                break;
            it = &t->item[t->nitem++];
            memset(it, 0, sizeof *it);
            it->nblock = (int)d[0];
            it->base_mikomi = 70.0;     /* S 行が無いときの基準。説明の 4 */
            it->base_wakuhaba = 25.0;
            it->first = t->npart;
            scale3 = 1.0;
            circ_w = 0;
            /* 二個以上の空白のあとが札 */
            p2 = s;
            while (*p2 && *p2 != ' ' && *p2 != '\t')
                p2++;
            if (p2[0] && p2[1] && (p2[0] == ' ' || p2[0] == '\t')
                && (p2[1] == ' ' || p2[1] == '\t')) {
                const char *q = skip_space(p2);
                size_t m = strlen(q);

                while (m > 0 && (q[m - 1] == ' ' || q[m - 1] == '\t'))
                    m--;
                if (m >= sizeof it->name)
                    m = sizeof it->name - 1;
                memcpy(it->name, q, m);
                it->name[m] = 0;
            }
            in_item = 1;
            hidden = 0;
            continue;
        }

        /* 「0」だけの行: これ以降は仮表示に出ない。説明の 11 */
        if (k == 1 && d[0] == 0.0) {
            hidden = 1;
            continue;
        }
        /* 立面の 500（一覧の位置ずらし）・700（倍率）・750（円の半径の比の向き）。
           ブロック番号の欄に 500・700・750 を書いて、そのあとに数が続く */
        if (in_item && it && k >= 2 && k < 6 &&
            (d[0] == 500.0 || d[0] == 700.0 || d[0] == 750.0)) {
            if (d[0] == 700.0 && d[1] > 0.0)
                scale3 = d[1];
            else if (d[0] == 750.0)
                circ_w = d[1] == 1.0;
            continue;
        }
        if (k < 6)                      /* 部材には座標が要ります */
            continue;
        if (t->npart >= JW_TG_PARTS)
            continue;
        {
            jw_tg_part *p = &t->part[t->npart++];

            memset(p, 0, sizeof *p);
            p->b0 = (int)d[0];
            p->b1 = (int)d[1];
            p->x0 = d[2];
            p->y0 = d[3];
            p->x1 = d[4];
            p->y1 = d[5];
            p->scale3 = scale3;
            p->circ_w = circ_w;
            p->layer = -1;
            p->layer_raw = -1;
            p->hidden = hidden;
            if (k > 6)
                p->color = (int)d[6];
            if (k > 7) {
                int v = (int)d[7];

                if (p->color == JW_TG_MOJI || p->color == JW_TG_TEN)
                    p->kind = v;        /* 文字種類・実点種類はそのまま */
                else {
                    p->ltype = v % 100;
                    p->width = v / 100; /* 百の位から上が線幅。説明の 7 */
                }
            }
            {
                int v = 0;

                /* レイヤだけは 16 進なので、十進で数えた個数には
                   入っていないことがあります（`A` は strtod で読め
                   ません）。位置で取り直します。 */
                if (scan_hex_at(s, 8, &v)) {
                    p->layer_raw = v;
                    if (v < 0) {
                        p->layer = -1;
                        /* -11 のような書き方で包絡の建具性質が外れます */
                        if (v <= -0x11)
                            p->plain = 1;
                    } else {
                        p->layer = v & 0xf;
                        if (v > 0xf)
                            p->plain = 1;
                        if (v > 0xff)
                            p->loose = 1;
                    }
                }
            }
            scan_arc(s, p);
            if (p->color != JW_TG_MOJI && strstr(s, "&m"))
                p->dim = 1;
            if (p->color == JW_TG_MOJI)
                scan_text(s, p);
            it->n = t->npart - it->first;
        }
    }
    return t->nitem;
}

/* --------------------------------------------- 伸ばして並べる ------- */

/* その端がどこへ行くか。`b` はブロック番号（1 から）。 */
static double map_x(const jw_tg_item *it, int kind, int b, double x,
                    double wakuhaba, double uchinori)
{
    int last = it->nblock;
    double org, k;

    if (b < 1)
        b = 1;
    if (b > last)
        b = last;
    /* ブロックの原点: ① が 0、最後が 内法、中間はその等分。
       説明の「部材構成例」の図のとおりです */
    org = last > 1 ? uchinori * (double)(b - 1) / (double)(last - 1) : 0.0;

    if (it->base_wakuhaba <= 0.0)
        return org + x;
    /* 建具断面は下枠（左ブロック）が動かない。説明の 4・5 の 1) と、
       原典の答え（p190_32866_*、p191_*） */
    if (kind == 2 && b == 1)
        return org + x;
    if (kind == 3)              /* 立面の幅は伸びない（枠は 35 のまま） */
        return org + x;
    k = wakuhaba / it->base_wakuhaba;
    if (it->has_s) {
        /* 説明の 5-1): 枠幅の基準を基準に平均に伸縮。
           5-2): 中間ブロックは動きません */
        if (b == 1 || b == last)
            x *= k;
    } else {
        /* 説明の 4): 25mm を基準に、左ブロックでは -20 以下、
           右ブロックでは 20 以上の端だけ。枠幅が 20 以下なら全部 */
        if (wakuhaba <= 20.0) {
            if (b == 1 || b == last)
                x *= k;
        } else if (b == 1) {
            if (x < -20.0)
                x *= k;
        } else if (b == last) {
            if (x > 20.0)
                x *= k;
        }
    }
    return org + x;
}

/* 建具立面の Y。データの高さは 10000 が 内法の高さで、千の位で四捨五入した
   ところ（0・3000・5000・7000・10000 …）が 高さの 0・0.3・0.5・0.7・1 倍に
   動き、そこからのずれ（-37・40・9960・10035 …）は mm のまま。
   原典に 内法の高さを 1000・1700・2400・4000 で置かせた答え（p192_*） */
static double map_y3(const jw_tg_item *it, double y, double height,
                     double scale)
{
    /* 縦内法は 10 分割（`s N` があれば N 分割）。1000 単位に四捨五入した値が
       その分割の位置（0 が下、1000×分割数 が上）、-500 以上 500 未満の
       残りは mm のまま（700 の倍率だけ掛かる）。
       原典の答え: 高さ 1000・1700・2400・4000（p192_*）と 階段の `s 14` など */
    double n = it->has_s && it->base_mikomi > 0.0 ? it->base_mikomi : 10.0;
    double a = floor(y / 1000.0 + 0.5) * 1000.0;

    if (a < 0.0)
        a = 0.0;
    return (y - a) * scale + a / (n * 1000.0) * height;
}

static double map_y(const jw_tg_item *it, double y, double mikomi)
{
    if (it->base_mikomi <= 0.0)
        return y;
    return y * mikomi / it->base_mikomi;
}

/* ブロック番号 10001〜（内出）・20001〜（外出）は、ふつうのブロック
   （下三桁）の x に、壁の厚みの外へ出す y のずれを足したもの。11001 のように
   上の桁が 1 のものも内出。原典に訊いた答え（p187_C*・p188_*）:
   内出の面は芯から 内出 だけ内、外出の面は芯から 外出 だけ外で、データの
   y = -70（内）・95（外）がそのときの面の位置 */
static int tg_blk(int b)
{
    return b >= 10000 ? b % 1000 : b;
}

static double tg_dy(const jw_tg_item *it, int b, double mikomi,
                    double uchide, double sotode)
{
    if (b >= 20000)             /* データの 見込の基準＋枠幅の基準 が外の面 */
        return mikomi / 2.0 + sotode - (it->base_mikomi + it->base_wakuhaba);
    if (b >= 10000)             /* データの -見込の基準 が内の面 */
        return mikomi / 2.0 - uchide + it->base_mikomi;
    return 0.0;
}

int jw_tategu_place(const jw_tategu *t, int item, double mikomi,
                    double wakuhaba, double uchinori,
                    jw_tg_out *out, int max)
{
    return jw_tategu_place_io(t, item, mikomi, wakuhaba, uchinori,
                              TG_IO_DEFAULT, TG_IO_DEFAULT, out, max);
}

int jw_tategu_place_io(const jw_tategu *t, int item, double mikomi,
                       double wakuhaba, double uchinori,
                       double uchide, double sotode,
                       jw_tg_out *out, int max)
{
    const jw_tg_item *it;
    int i, n = 0;

    if (!t || !out || item < 0 || item >= t->nitem)
        return 0;
    it = &t->item[item];
    /* 区切りの後ろに書かれた固定値があれば、そちらが勝ちます（説明の 10） */
    if (it->fix_mikomi > 0.0)
        mikomi = it->fix_mikomi;
    if (it->fix_wakuhaba > 0.0)
        wakuhaba = it->fix_wakuhaba;

    for (i = 0; i < it->n && n < max; i++) {
        const jw_tg_part *p = &t->part[it->first + i];
        jw_tg_out *o = &out[n];

        memset(o, 0, sizeof *o);
        o->x0 = map_x(it, t->kind, tg_blk(p->b0),
                      t->kind == 3 && p->scale3 > 0.0 ? p->x0 * p->scale3 : p->x0,
                      wakuhaba, uchinori);
        o->y0 = (t->kind == 3 ? map_y3(it, p->y0, mikomi, p->scale3 > 0.0 ? p->scale3 : 1.0) : map_y(it, p->y0, mikomi))
                + tg_dy(it, p->b0, mikomi, uchide, sotode);
        o->x1 = map_x(it, t->kind, tg_blk(p->b1),
                      t->kind == 3 && p->scale3 > 0.0 ? p->x1 * p->scale3 : p->x1,
                      wakuhaba, uchinori);
        o->y1 = (t->kind == 3 ? map_y3(it, p->y1, mikomi, p->scale3 > 0.0 ? p->scale3 : 1.0) : map_y(it, p->y1, mikomi))
                + tg_dy(it, p->b1, mikomi, uchide, sotode);
        o->color = p->color;
        o->ltype = p->ltype;
        o->width = p->width;
        o->layer = p->layer;
        o->plain = p->plain;
        o->loose = p->loose;
        o->dim = p->dim;
        o->kind = p->kind;
        o->text = p->text[0] ? p->text : 0;
        o->font = p->font[0] ? p->font : 0;
        o->italic = p->italic;
        o->bold = p->bold;
        if (p->color == JW_TG_TEN) {
            o->cls = JW_TG_POINT;
            o->color = 0;               /* 30000 は目印なので色ではありません */
        } else if (p->color == JW_TG_MOJI) {
            o->cls = JW_TG_TEXT_O;
            o->color = 0;
        } else if (p->arc) {
            o->cls = JW_TG_ARC;
            o->sweep = p->sweep;
            o->sector = p->sector;
        } else {
            o->cls = JW_TG_LINE;
        }
        n++;
    }
    return n;
}

/* --------------------------------------------- 図面の要素にする ----- */

int jw_tategu_objs(jw_drawing *d, const jw_tg_out *o, int n,
                   double ox, double oy)
{
    int i, made = 0;

    if (!d || !o)
        return 0;
    for (i = 0; i < n; i++) {
        const jw_tg_out *p = &o[i];
        jw_obj *e;

        switch (p->cls) {
        case JW_TG_LINE:
            e = jw_add(d, JW_SEN);
            if (!e)
                return made;
            e->d[0] = ox + p->x0;
            e->d[1] = oy + p->y0;
            e->d[2] = ox + p->x1;
            e->d[3] = oy + p->y1;
            break;
        case JW_TG_POINT:
            e = jw_add(d, JW_TEN);
            if (!e)
                return made;
            e->d[0] = ox + p->x0;
            e->d[1] = oy + p->y0;
            /* 線種の欄が実点種類。説明の 14 */
            e->n = p->kind;
            break;
        case JW_TG_ARC: {
            double dx = p->x1 - p->x0, dy = p->y1 - p->y0;
            double r = sqrt(dx * dx + dy * dy);

            if (r <= 0.0)
                continue;
            e = jw_add(d, JW_ENKO);
            if (!e)
                return made;
            e->d[0] = ox + p->x0;       /* 中心 */
            e->d[1] = oy + p->y0;
            e->d[2] = r;
            e->d[3] = atan2(dy, dx);    /* 始点の角 */
            e->d[4] = p->sweep * 3.14159265358979323846 / 180.0;
            e->d[5] = 0.0;
            e->d[6] = 1.0;
            e->n = 0;
            break;
        }
        default:
            /* 文字はまだです —— 文字種類の桁で基点と縦書きが変わり、
               フォントも付くので、そこは原典に訊いてからにします */
            continue;
        }
        if (p->color > 0)
            e->color = (unsigned short)p->color;
        if (p->ltype > 0)
            e->ltype = (unsigned char)p->ltype;
        if (p->layer >= 0)
            e->layer = (unsigned char)p->layer;
        made++;
    }
    return made;
}

/* ---------------------------------------- 埋め込んだ JW_OPT*.DAT ----- */

int jw_tgdat_count(int kind)
{
    int i, n = 0;

    for (i = 0; i < tgdat_n; i++)
        if (tgdat_list[i].kind == kind)
            n++;
    return n;
}

int jw_tgdat_index(int kind, int k)
{
    int i;

    for (i = 0; i < tgdat_n; i++)
        if (tgdat_list[i].kind == kind && k-- == 0)
            return i;
    return -1;
}

const jw_tgdat *jw_tgdat_get(int idx)
{
    return idx >= 0 && idx < tgdat_n ? &tgdat_list[idx] : 0;
}

const jw_tategu *jw_tategu_load(int idx)
{
    static jw_tategu t;
    static int have = -1;

    if (idx < 0 || idx >= tgdat_n)
        return 0;
    if (have != idx) {
        memset(&t, 0, sizeof t);
        have = -1;
        if (jw_tategu_parse(&t, (const char *)tgdat_list[idx].data,
                            tgdat_list[idx].len) <= 0)
            return 0;
        t.kind = tgdat_list[idx].kind;
        have = idx;
    }
    return &t;
}

/* ----------------------------------------- 図面に置く（平面） -------- */

#define TG_PI 3.14159265358979323846

/* 部材の属性を要素に写す */
static void tg_attr(jw_obj *e, const jw_tg_out *o, unsigned short flags,
                    int width_too)
{
    e->flags = flags;
    if (o->color > 0)
        e->color = (unsigned short)o->color;
    if (o->ltype > 0)
        e->ltype = (unsigned char)o->ltype;
    if (width_too && o->width > 0)
        e->width = (unsigned short)o->width;
    if (o->layer >= 0)
        e->layer = (unsigned short)o->layer;
}

/* 寸法図形（行の最後の &m）。原典が JW_OPT1.DAT の [1] で作ったもの
   （p185_i1）: 線（太さと色はデータの、旗は建具の 0x9000 に寸法の 0x2000）・
   寸法値（「線の寸法値」と同じ。cmd.c）・空の線二本・空の点四つ。
   頭の線種・線色は書込みの 1・2（mark = 513）、頭の旗は 0x3000 */
static int tg_dimension(jw_drawing *d, const jw_tg_out *o, unsigned short flags,
                        const double *wx, const double *wy)
{
    int k, first;

    if (!jw_add(d, JW_SEN))
        return -1;
    first = d->ndrawn - 1;
    for (k = 2; k <= 8; k++)
        if (!jw_add(d, k == 2 ? JW_MOJI : k <= 4 ? JW_SEN : JW_TEN))
            return k - 2 + 1 > 0 ? 1 : -1;
    {
        jw_obj *e = &d->obj[first];

        e->d[0] = wx[0];
        e->d[1] = wy[0];
        e->d[2] = wx[1];
        e->d[3] = wy[1];
        tg_attr(e, o, (unsigned short)(flags | 0x2000u), 1);
        e->mark = 513;
        e->list[2] = 0x3000;
        jw_cmd_dim_value(d, e, &d->obj[first + 1]);
    }
    for (k = 1; k <= 8; k++)
        d->obj[first + k - 1].sub = (unsigned char)k;
    return 8;
}

/* 文字。始点座標が置く位置（文字種類の百の位 1..8 が、その位置が文字の
   どこに当たるか: 1 中下 2 右下 3 左中 4 中中 5 右中 6 左上 7 中上 8 右上、
   0 は左下）で、始点から終点への向きが文字の角度。千の位 1 は縦書き。
   [1] の「引き違い」（p185_i1）は 701: 中上。

   下二桁は 文字種の番号（1 から。大きさ・色・間隔はその文字種）。原典の
   答え（p185_i1 の 701、立面の D11 の 403・D13 の 103）から:
     ltype = 百の位 + 1、旗 = 0x2000、
     n = 10000 × （斜体 1 + 太字 2）+ 文字種の番号、
     d[7] = 基線の角度（度）、書体は $<…> か 既定。 */
static int tg_text(jw_drawing *d, const jw_tg_out *o, const double *wx,
                   const double *wy)
{
    double dx = wx[1] - wx[0], dy = wy[1] - wy[0], l = sqrt(dx * dx + dy * dy);
    double ux = 1.0, uy = 0.0, vx, vy, cw, ch, sp, w = 0.0, ax, ay;
    int h = (o->kind / 100) % 10, tate = (o->kind / 1000) % 10, nch = 0;
    int sn = o->kind % 100;
    const char *q;
    jw_obj *e;
    char face[JW_TG_FONT + 8];

    if (sn < 1 || sn > 10)
        sn = 1;
    if (!o->text || !o->text[0] || d->style[sn - 1].w <= 0.0 ||
        d->style[sn - 1].h <= 0.0)
        return 0;
    if (l > 1e-9) {
        ux = dx / l;
        uy = dy / l;
    }
    vx = -uy;
    vy = ux;
    cw = d->style[sn - 1].w;
    ch = d->style[sn - 1].h;
    sp = d->style[sn - 1].sp;
    for (q = o->text; *q; ) {
        int wide = jw_is_lead((unsigned char)q[0]) && q[1];

        if (nch)
            w += wide ? sp : sp / 2;
        w += wide ? cw : cw / 2;
        q += wide ? 2 : 1;
        nch++;
    }
    ax = h == 0 ? 0.0 : (h == 1 || h == 4 || h == 7) ? w / 2.0
       : (h == 2 || h == 5 || h == 8) ? w : 0.0;
    ay = h == 0 || h == 1 || h == 2 ? 0.0
       : (h == 3 || h == 4 || h == 5) ? ch / 2.0 : ch;
    e = jw_add(d, JW_MOJI);
    if (!e)
        return 0;
    e->color = (unsigned short)d->style[sn - 1].color;
    e->ltype = (unsigned char)(h + 1);
    e->n = 10000 * ((o->italic ? 1 : 0) + (o->bold ? 2 : 0)) + sn;
    e->flags = (unsigned short)(0x2000 | (tate ? 0x20 : 0));
    e->d[0] = wx[0] - ax * ux - ay * vx;
    e->d[1] = wy[0] - ax * uy - ay * vy;
    e->d[2] = e->d[0] + w * ux;
    e->d[3] = e->d[1] + w * uy;
    e->d[4] = cw;
    e->d[5] = ch;
    e->d[6] = sp;
    e->d[7] = atan2(uy, ux) * 180.0 / TG_PI;
    if (fabs(e->d[7]) < 1e-9)
        e->d[7] = 0.0;
    e->text = jw_add_str(d, o->text);
    snprintf(face, sizeof face, "%s", o->font && o->font[0] ? o->font : "\x82l\x82r \x83S\x83V\x83" "b\x83N");
    e->face = jw_add_str(d, face);
    return 1;
}

int jw_tategu_put(jw_drawing *d, const jw_tategu *t, int item,
                  const jw_tg_pose *p)
{
    static jw_tg_out out[JW_TG_PARTS];
    int n, i, made = 0;
    double mik = p->mikomi, vx = -p->uy, vy = p->ux;
    int mirror = (p->flip_lr != 0) != (p->flip_io != 0);
    double shin = p->shinzure;
    double ex[2] = { 0.0, 0.0 }, ey[2] = { 0.0, 0.0 };     /* 前の円弧の終点 */
    const jw_tg_item *it;

    if (!d || !t || item < 0 || item >= t->nitem || p->scale <= 0.0)
        return 0;
    it = &t->item[item];
    if (t->kind == 3)
        mik = p->height;        /* 立面は 内法の高さ */
    else if (it->fix_mikomi > 0.0)
        mik = it->fix_mikomi;
    if (t->kind == 3)
        shin = 0.0;
    else if (it->s_flip)        /* 芯ずれ＝（内出−外出）／２ */
        shin = ((p->have_io ? p->uchide : TG_IO_DEFAULT) -
                (p->have_io ? p->sotode : TG_IO_DEFAULT)) / 2.0;
    n = jw_tategu_place_io(t, item, t->kind == 3 ? p->height : p->mikomi,
                           p->wakuhaba, p->uchinori,
                           p->have_io ? p->uchide : TG_IO_DEFAULT,
                           p->have_io ? p->sotode : TG_IO_DEFAULT,
                           out, JW_TG_PARTS);
    for (i = 0; i < n; i++) {
        const jw_tg_out *o = &out[i];
        double x[2] = { o->x0, o->x1 }, y[2] = { o->y0, o->y1 };
        double wx[2], wy[2];
        int k;
        unsigned short flags = 0x9000;

        if (o->plain)
            flags = 0x1000;
        if (o->loose)
            flags = 0;
        for (k = 0; k < 2; k++) {
            double lx = x[k], ly = y[k];

            if (t->kind == 3) {
                /* 立面の 横反転・縦反転 は 基準点のまわりの鏡
                   （p192_n4_fh・p192_n4_fv）。基準点の移動はそのあと */
                if (p->flip_lr)
                    lx = -lx;
                if (p->flip_io)
                    ly = -ly;
            } else {
                if (p->flip_lr)
                    lx = p->uchinori - lx;
                if (p->flip_io)
                    ly = mik - ly;
            }
            if (t->kind == 3) {
                lx -= p->ref_h * p->uchinori / 2.0;
                ly -= p->ref_v * mik / 2.0;
            } else {
                ly += shin - mik / 2.0;
            }
            wx[k] = p->ox + (lx * p->ux + ly * vx) / p->scale;
            wy[k] = p->oy + (lx * p->uy + ly * vy) / p->scale;
        }
        if (o->cls == JW_TG_LINE && o->dim) {
            int k2 = tg_dimension(d, o, flags, wx, wy);

            if (k2 < 0)
                return made;
            made += k2;
        } else if (o->cls == JW_TG_LINE) {
            jw_obj *e = jw_add(d, JW_SEN);

            if (!e)
                return made;
            e->d[0] = wx[0];
            e->d[1] = wy[0];
            e->d[2] = wx[1];
            e->d[3] = wy[1];
            tg_attr(e, o, flags, 1);
            made++;
        } else if (o->cls == JW_TG_TEXT_O) {
            if (tg_text(d, o, wx, wy))
                made++;
        } else if (o->cls == JW_TG_POINT) {
            jw_obj *e = jw_add(d, JW_TEN);

            if (!e)
                return made;
            e->d[0] = wx[0];
            e->d[1] = wy[0];
            /* 原典の答え（p192_D13、「実点 5」）: 線種 1・色 = 実点種類・n 0・旗 0x80 */
            e->ltype = 1;
            e->color = (unsigned short)(o->kind > 0 ? o->kind : 1);
            e->n = 0;
            e->flags = 0x80;
            made++;
        } else if (o->cls == JW_TG_ARC) {
            int code = o->sector % 10;
            double sw = o->sweep * TG_PI / 180.0 * (mirror ? -1.0 : 1.0);
            double sx = wx[1] - wx[0], sy = wy[1] - wy[0];
            double r = sqrt(sx * sx + sy * sy), a = atan2(sy, sx);
            double endx, endy;
            double st3 = 0.0;
            int k3 = 0;
            jw_obj *e;

            {   /* 建具立面の 円・円弧: (x1,y1) は 始角・終角（度。0,0 なら一周）、
                   E のあとの数が半径（mm。負なら 内法の高さに対する割合）。
                   原典の答え（p192_n11_h2400、p192_D5/D6/D7）。円弧の中心は
                   (x0,y0)。始角は d[3]、振りは d[4]、傾きは 0 */
                const jw_tg_part *q0 = &t->part[it->first + i];

                if (t->kind == 3 && q0->sweep != 0.0) {
                    double sc3 = q0->scale3 > 0.0 ? q0->scale3 : 1.0;
                    /* 負の半径は 内法の縦（750 1 なら横）に対する割合。
                       そのあとの数（sector）は mm のまま足す（p192_D9） */
                    double rmm = (q0->sweep > 0.0 ? q0->sweep * sc3
                                  : -q0->sweep * (q0->circ_w ? p->uchinori : mik))
                                 + q0->sector;
                    double s0, w0, rot = atan2(p->uy, p->ux);

                    if (q0->x1 == 0.0 && q0->y1 == 0.0) {
                        s0 = 0.0;
                        w0 = 2.0 * TG_PI;
                    } else {
                        s0 = q0->x1 * TG_PI / 180.0;
                        w0 = (q0->y1 - q0->x1) * TG_PI / 180.0;
                        while (w0 <= 0.0)
                            w0 += 2.0 * TG_PI;
                    }
                    if (p->flip_lr)
                        s0 = TG_PI - s0 - w0;
                    if (p->flip_io)
                        s0 = -s0 - w0;
                    st3 = s0 + rot;
                    while (st3 > TG_PI + 1e-9)      /* 始角は (-π, π] で持つ */
                        st3 -= 2.0 * TG_PI;
                    while (st3 <= -TG_PI + 1e-9)
                        st3 += 2.0 * TG_PI;
                    r = rmm / p->scale;
                    a = 0.0;
                    sw = w0;
                    code = 0;
                    k3 = 1;
                    wx[1] = wx[0] + r;
                    wy[1] = wy[0];
                }
            }
            endx = wx[0] + r * cos(a + sw);
            endy = wy[0] + r * sin(a + sw);

            if (code == 8) {
                /* 前の二つの円弧の終点どうしを結ぶ。x0,y0 が二つ前の終点から、
                   x1,y1 が一つ前の終点からのずれ（向きだけ置き換える） */
                const jw_tg_part *q = &t->part[it->first + i];
                double ax0 = q->x0, ay0 = q->y0, ax1 = q->x1, ay1 = q->y1;

                if (p->flip_lr) { ax0 = -ax0; ax1 = -ax1; }
                if (p->flip_io) { ay0 = -ay0; ay1 = -ay1; }
                e = jw_add(d, JW_SEN);
                if (!e)
                    return made;
                e->d[0] = ex[0] + (ax0 * p->ux + ay0 * vx) / p->scale;
                e->d[1] = ey[0] + (ax0 * p->uy + ay0 * vy) / p->scale;
                e->d[2] = ex[1] + (ax1 * p->ux + ay1 * vx) / p->scale;
                e->d[3] = ey[1] + (ax1 * p->uy + ay1 * vy) / p->scale;
                tg_attr(e, o, flags, 1);
                made++;
                continue;
            }
            if (r > 0.0 && code < 4) {
                e = jw_add(d, JW_ENKO);
                if (!e)
                    return made;
                e->d[0] = wx[0];
                e->d[1] = wy[0];
                e->d[2] = r;
                e->d[3] = k3 ? st3 : 0.0;
                e->d[4] = sw;
                e->d[5] = k3 ? 0.0 : a;
                e->d[6] = 1.0;
                e->n = 0;
                tg_attr(e, o, flags, 1);
                /* 円弧の旗は線と違う: 原典は どの円弧にも 0x80 を置いた
                   （平面 [7]・[8]、断面 [15]・[16]）。建具の 0x9000 は付かない */
                e->flags = 0x80;
                made++;
            }
            if (r > 0.0) {
                for (k = 0; k < 2; k++) {
                    int want = k == 0
                        ? (code == 1 || code == 3 || code == 5 || code == 7)
                        : (code == 2 || code == 3 || code == 6 || code == 7);

                    if (!want)
                        continue;
                    e = jw_add(d, JW_SEN);
                    if (!e)
                        return made;
                    e->d[0] = wx[0];
                    e->d[1] = wy[0];
                    e->d[2] = k == 0 ? wx[1] : endx;
                    e->d[3] = k == 0 ? wy[1] : endy;
                    tg_attr(e, o, flags, 1);
                    made++;
                }
            }
            ex[0] = ex[1];
            ey[0] = ey[1];
            ex[1] = endx;
            ey[1] = endy;
        }
    }
    return made;
}
