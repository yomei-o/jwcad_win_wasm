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

#include "tategu.h"

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
            if (c[1] == '/')
                p->italic = 1;
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
    int in_item = 0, hidden = 0, head_seen = 0;
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
            if (p->color == JW_TG_MOJI)
                scan_text(s, p);
            it->n = t->npart - it->first;
        }
    }
    return t->nitem;
}
