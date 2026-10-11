/* 線記号変形 (32869) の記号データを読んで、図面に置く。src/senkigou.h を見て
 * ください。読み方は DAT のおわりの「データの説明」、置き方は原典に押させた
 * 答え（decomp/res/sk_*.jww）から。 */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "senkigou.h"
#include "tategu.h"
#include "cmd.h"

#define SK_PI 3.14159265358979323846

/* ------------------------------------------------------- 読む ---------- */

static int is_num_tok(const char *t)
{
    char *e;

    if (!*t)
        return 0;
    (void)strtod(t, &e);
    return e != t && *e == 0;
}

/* 空白で区切って次の語を取り出す。`"` で始まる所は語にしない */
static const char *next_tok(const char *s, char *out, size_t cap)
{
    size_t n = 0;

    while (*s == ' ' || *s == '\t')
        s++;
    if (!*s || *s == '"')
        return 0;
    while (*s && *s != ' ' && *s != '\t' && *s != '"') {
        if (n + 1 < cap)
            out[n++] = *s;
        s++;
    }
    out[n] = 0;
    return s;
}

/* 一行を行に。分類できなければ -1。fac 等は読みながら畳む倍率 */
static int parse_row(const char *line, jw_sk_row *r, double *fac, int *turn,
                     int *real)
{
    char tk[96];
    double nums[24];
    int nn = 0, cls = JW_SK_LINE;
    const char *s = line, *q;
    char letter[16] = "";
    int after_letter = 0;
    double lnums[8];
    int ln = 0;

    memset(r, 0, sizeof *r);
    r->flat = 1.0;
    while ((s = next_tok(s, tk, sizeof tk)) != 0) {
        {
            char *ne;
            double v = strtod(tk, &ne);
            int glued = ne != tk && *ne && (unsigned char)*ne >= 0x80;

            /* 「0　　線端を…」のように 数に 全角の説明が くっついていても 数は数 */
            if (is_num_tok(tk) || glued) {
                if (letter[0]) {
                    if (ln < 8)
                        lnums[ln++] = v;
                } else if (nn < 24)
                    nums[nn++] = v;
                if (glued)
                    break;
                continue;
            }
        }
        if (!letter[0] && nn >= 3 && !after_letter &&
            (((tk[0] == 'e' || tk[0] == 'E' || tk[0] == 'c' || tk[0] == 'f') && !tk[1]) ||
             (tk[0] == 'a' && tk[1] >= '1' && tk[1] <= '7' && !tk[2]))) {
            snprintf(letter, sizeof letter, "%s", tk);
            after_letter = 1;
            continue;
        }
        break;                          /* 説明の文 */
    }
    if (nn < 1)
        return -1;
    r->c1 = (int)nums[0];
    r->c2 = nn > 1 ? (int)nums[1] : 0;
    r->fac = *fac;
    r->turn180 = *turn;
    r->real = *real;

    /* 特別な行 */
    if (r->c1 == 700 || r->c1 == 800) {
        double v = nn > 1 ? nums[1] : 1.0;

        *fac = fabs(v) > 0.0 ? fabs(v) : 1.0;
        *turn = v < 0.0;
        *real = r->c1 == 800;
        return -2;
    }
    if (r->c1 == 500) {
        r->cls = JW_SK_ORIGIN500;
        r->v = nn > 1 ? nums[1] : 0.0;
        r->w = nn > 2 ? nums[2] : 0.0;
        return JW_SK_ORIGIN500;
    }
    if (r->c1 == 750 || r->c1 == 751) {
        r->cls = JW_SK_DIR75;
        return JW_SK_DIR75;
    }
    if (r->c1 >= 760 && r->c1 <= 768) {
        r->cls = JW_SK_MOUSE;
        r->v = nn > 1 ? nums[1] : 0.0;
        r->w = nn > 2 ? nums[2] : 0.0;
        return JW_SK_MOUSE;
    }
    if (r->c1 == 10000) {
        r->cls = JW_SK_NEXT;
        return JW_SK_NEXT;
    }
    if (r->c1 == 11400 || r->c1 == 12930) {
        r->cls = JW_SK_CMD;
        return JW_SK_CMD;
    }

    /* 座標の行 */
    if (nn < 6)
        return -1;
    r->x0 = nums[2];
    r->y0 = nums[3];
    r->x1 = nums[4];
    r->y1 = nums[5];
    if (nn > 6)
        r->color = (int)nums[6];
    if (nn > 7) {
        int v = (int)nums[7];

        r->ltype = v % 100;
        r->width = v / 100;
        r->kind = v;
    }
    if (nn > 8) {
        r->layer = (int)nums[8];
        r->have_layer = 1;
    }
    r->have_color = nn > 6;

    q = strchr(line, '"');
    if (r->color == 10000 && q) {
        const char *f;

        cls = JW_SK_TEXTROW;
        q++;
        f = strchr(q, '"');             /* 文字列の終わりの " */
        {
            size_t m = f ? (size_t)(f - q) : strlen(q);

            while (m > 0 && (q[m - 1] == '\r' || q[m - 1] == '\n' || q[m - 1] == ' '))
                m--;
            if (m >= sizeof r->text)
                m = sizeof r->text - 1;
            memcpy(r->text, q, m);
            r->text[m] = 0;
        }
        if (f && f[1] == '+') {         /* "数字"+増分 */
            const char *g = f + 2;

            r->have_inc = 1;
            r->inc = 1;
            if (*g == '(')
                g++;
            if (*g == '-' || *g == '+' || isdigit((unsigned char)*g))
                r->inc = (int)strtol(g, 0, 10);
        } else if (f && f[1] == '$' && f[2] == '<') {
            const char *g = strchr(f + 3, '>');
            size_t m = g ? (size_t)(g - (f + 3)) : 0;

            if (m >= sizeof r->font)
                m = sizeof r->font - 1;
            memcpy(r->font, f + 3, m);
            r->font[m] = 0;
            r->slant = g && g[1] == '/';
        }
    } else if (r->color == 30000) {
        cls = JW_SK_POINT;
        if (letter[0] == 'c') {
            r->marker = 1;
            r->marker_c = ln > 0 ? (int)lnums[0] : 0;
        }
    } else if (letter[0] == 'e' || letter[0] == 'E') {
        cls = JW_SK_ARC;
        r->r = ln > 0 ? lnums[0] : 0.0;
        if (ln > 1)
            r->flat = lnums[1];
    } else if (letter[0] == 'a') {
        cls = JW_SK_SOLID;
        r->solid = letter[1] - '0';
        if (r->solid == 1) {
            int k;

            for (k = 0; k < 4 && k < ln; k++)
                r->a[k] = lnums[k];
            if (ln > 4)
                r->rgb = (unsigned int)lnums[4];
        } else {
            r->r = ln > 0 ? lnums[0] : 0.0;
            r->flat = ln > 1 ? lnums[1] : 1.0;
            r->tilt = ln > 2 ? lnums[2] : 0.0;
            r->inner = ln > 3 ? lnums[3] : 0.0;
            if (ln > 4)
                r->rgb = (unsigned int)lnums[4];
        }
    }
    if (r->c1 >= 14000 && r->c1 < 15000)
        cls = JW_SK_DIMROW;
    r->cls = cls;
    return cls;
}

int jw_sk_parse(jw_senkigou *s, const char *b, long n)
{
    long i = 0;
    int in_item = 0, head_seen = 0;
    double fac = 1.0;
    int turn = 0, real = 0;
    jw_sk_item *it = 0;

    if (!s || !b)
        return 0;
    memset(s, 0, sizeof *s);
    while (i < n) {
        char line[512];
        const char *p;
        long j = i;
        size_t len;

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

        p = line;
        while (*p == ' ' || *p == '\t')
            p++;
        if (*p == '#') {
            if (!s->title[0] && !head_seen) {
                size_t m = strlen(p + 1);

                if (m >= sizeof s->title)
                    m = sizeof s->title - 1;
                memcpy(s->title, p + 1, m);
                s->title[m] = 0;
            }
            continue;
        }
        if (!*p)
            continue;
        if (!head_seen) {               /* 件数 */
            if (!isdigit((unsigned char)*p))
                continue;
            s->want = atoi(p);
            head_seen = 1;
            continue;
        }
        if (!in_item) {
            const char *a;

            if (*p == '=')                  /* 「データの説明」から先は説明文 */
                break;
            if (s->nitem >= JW_SK_ITEMS)
                break;
            if (s->nitem == 0 && !head_seen)
                continue;
            if (!isdigit((unsigned char)*p))
                continue;
            if (atoi(p) >= 990 && atoi(p) <= 999)       /* 最初の「999」（区切り） */
                continue;
            it = &s->item[s->nitem++];
            memset(it, 0, sizeof *it);
            it->pointers = atoi(p);
            it->first = s->nrow;
            it->show = 1.0;
            a = p;
            while (*a && *a != ' ' && *a != '\t')
                a++;
            while (*a == ' ' || *a == '\t')
                a++;
            {
                size_t m = strlen(a);

                while (m > 0 && (a[m - 1] == ' ' || a[m - 1] == '\t'))
                    m--;
                if (m >= sizeof it->name)
                    m = sizeof it->name - 1;
                memcpy(it->name, a, m);
                it->name[m] = 0;
            }
            fac = 1.0;
            turn = real = 0;
            in_item = 1;
            continue;
        }
        {
            jw_sk_row *r;
            int k;
            double d0 = atof(p);

            /* 区切り: 990〜999。そのうしろの数は表示倍率の追加 */
            if (isdigit((unsigned char)*p) && d0 >= 990.0 && d0 <= 999.0) {
                it->show = (d0 - 989.0) / 10.0;
                if (it->show > 1.0)
                    it->show = 1.0;
                it->n = s->nrow - it->first;
                in_item = 0;
                it = 0;
                continue;
            }
            if (s->nrow >= JW_SK_ALLROWS)
                continue;
            r = &s->row[s->nrow];
            k = parse_row(line, r, &fac, &turn, &real);
            if (k < 0)
                continue;
            switch (r->cls) {
            case JW_SK_MOUSE:
                it->mouse = r->c1;
                it->mx = r->v;
                it->my = r->w;
                break;
            case JW_SK_DIR75:
                it->dir75 = r->c1;
                break;
            case JW_SK_NEXT:
                it->next = r->c2;
                break;
            case JW_SK_CMD:
                it->cmd = r->c1;
                break;
            case JW_SK_LINE:
            case JW_SK_ARC:
            case JW_SK_TEXTROW:
            case JW_SK_POINT:
            case JW_SK_SOLID: {
                int a = r->c1 >= 300 && r->c1 < 400 ? -1 : r->c1 % 100;
                int b2 = r->c2 >= 300 && r->c2 < 400 ? -1 : r->c2 % 100;

                /* 線のときだけ制御コード 10・20 が線を指示する意味 */
                if (r->cls == JW_SK_LINE || r->cls == JW_SK_TEXTROW ||
                    r->cls == JW_SK_POINT) {
                    if (a == 10 || b2 == 10)
                        it->need_l1 = 1;
                    if (a == 20 || b2 == 20)
                        it->need_l2 = 1;
                }
                break;
            }
            default:
                break;
            }
            s->nrow++;
        }
    }
    if (in_item && it)
        it->n = s->nrow - it->first;
    return s->nitem;
}

/* ------------------------------------------------ 埋め込んだ DAT ------- */

const jw_senkigou *jw_sk_load(int idx)
{
    static jw_senkigou cur;
    static int have = -1;
    const jw_tgdat *g;

    if (have == idx)
        return &cur;
    g = jw_tgdat_get(idx);
    if (!g || g->kind != 4)
        return 0;
    if (jw_sk_parse(&cur, (const char *)g->data, g->len) <= 0)
        return 0;
    have = idx;
    return &cur;
}

/* ------------------------------------------------- 図面に置く ---------- */

typedef struct {
    const jw_sk_pose *p;
    double rho1, rho2;          /* 線１の角度・線２の向きから 90° 引いた角度 */
    double rho;                 /* 弧の傾き: 線１があれば線１、なければ線２、なければ軸角 */
    double th1, th2;            /* 記号の中で、線１・線２の向きの角度（10・20 の行の始点→終点） */
    double oyx, oyy;            /* 斜交座標（04）の +y が世界で向く（長さつき） */
    int mirror;                 /* 線１と線２で作る座標が左手系 */
    double msx, msy;            /* 倍率位置から決まる倍率 */
    jw_sk_txt *lt;              /* 前に置いた文字（呼び手の持ち物） */
    int *cmd;                   /* ほかのコマンドの行に来たらその番号を入れる */
} sk_ctx;

static double norm_pi(double a)
{
    while (a > SK_PI + 1e-9)
        a -= 2.0 * SK_PI;
    while (a <= -SK_PI + 1e-9)
        a += 2.0 * SK_PI;
    return a;
}

/* 制御コードの下二桁。11 は 01（線１の角度に追従）と同じに働く
   （111 01 の行が 線１ が逆向きのとき 180° 回って出る） */
static int sk_code(int c)
{
    int k = c % 100;

    if (c >= 300 && c < 400)            /* 前の文字の基準点（300 台） */
        return c;
    return k == 11 ? 1 : k;
}

/* 制御コードで、行の座標 (rx, ry) が世界のどこか。kx,ky は行にかかる倍率
   （700・800・コントロールバーの倍率）、sg は 180° 回すときの -1 */
static void sk_map(const sk_ctx *c, const jw_sk_item *it, int code, int is_end,
                   double rx, double ry, double kx, double ky, double sg,
                   double *wx, double *wy)
{
    const jw_sk_pose *p = c->p;
    double ca, sa, x = rx * kx * sg, y = ry * ky * sg;

    if (code >= 300 && code < 400) {
        /* 前に置いた文字の枠のその基準点（一の位 0 左下 1 中下 2 右下 3 左中 4 中中
           5 右中 6 左上 7 中上 8 右上）が 座標の原点。十の位 1 は X だけ、2 は Y だけ
           文字の基準点を使い、あとは記号の原点 */
        const jw_sk_txt *t = c->lt;
        int ones = code % 10, tens = code / 10 % 10;
        double fx = (ones % 3) * 0.5, fy = (ones / 3) * 0.5;
        double ux = 1.0, uy = 0.0, rpx = p->ox, rpy = p->oy, ex, ey;

        if (t && t->valid) {
            ux = t->ux;
            uy = t->uy;
            rpx = t->sx + ux * fx * t->w - uy * fy * t->h;
            rpy = t->sy + uy * fx * t->w + ux * fy * t->h;
        }
        ex = rpx - p->ox;
        ey = rpy - p->oy;
        if (tens == 1) {                /* X だけ */
            double along = ex * ux + ey * uy;

            *wx = p->ox + ux * (along + x) - uy * y;
            *wy = p->oy + uy * (along + x) + ux * y;
        } else if (tens == 2) {         /* Y だけ */
            double across = -ex * uy + ey * ux;

            *wx = p->ox + ux * x - uy * (across + y);
            *wy = p->oy + uy * x + ux * (across + y);
        } else {
            *wx = rpx + ux * x - uy * y;
            *wy = rpy + uy * x + ux * y;
        }
        return;
    }
    switch (code % 100) {
    case 5:
        /* 倍率位置: 指示点からの差が倍率をかけたもの */
        x = rx * c->msx * sg;
        y = ry * c->msy * sg;
        break;
    case 6:
        /* 指定座標と基準点の差を、倍率位置（基準点に倍率をかけたところ）からの差にする */
        x = (rx - it->mx) * kx * sg + it->mx * c->msx;
        y = (ry - it->my) * ky * sg + it->my * c->msy;
        break;
    case 1:
        *wx = p->ox + x * p->u1x - y * p->u1y;
        *wy = p->oy + x * p->u1y + y * p->u1x;
        return;
    case 2:
        /* 記号の中で線２が th2 の向きに描いてあるので、それを 世界の線２の向きに回す */
        ca = cos(c->rho2);
        sa = sin(c->rho2);
        *wx = p->ox + x * ca - y * sa;
        *wy = p->oy + x * sa + y * ca;
        return;
    case 4:
        *wx = p->ox + x * p->u1x + y * c->oyx;
        *wy = p->oy + x * p->u1y + y * c->oyy;
        return;
    case 10:
        if (!p->have1)
            break;                      /* 線を押さなかった: 位置からの座標 */
        /* 線の端そのもの（座標は 長さの向きだけで、ずれは付けない。C の「[45°] 排水」で
           20 の x が ±8 でも 線は ずれなかった） */
        *wx = is_end ? p->e1x : p->s1x;
        *wy = is_end ? p->e1y : p->s1y;
        return;
    case 20:
        if (!p->have2)
            break;
        *wx = is_end ? p->e2x : p->s2x;
        *wy = is_end ? p->e2y : p->s2y;
        return;
    default:
        break;
    }
    ca = cos(p->axis);
    sa = sin(p->axis);
    *wx = p->ox + x * ca - y * sa;
    *wy = p->oy + x * sa + y * ca;
}

/* 行ごとの属性を要素に */
static void sk_attr(jw_obj *e, const jw_sk_row *r, const jw_sk_pose *p)
{
    int h = r->c1 / 100 % 10;
    const jw_obj *base = r->c1 < 10000 && h == 1 ? &p->attr1
                       : r->c1 < 10000 && h == 2 ? &p->attr2 : 0;

    if (base) {
        e->color = base->color;
        e->ltype = base->ltype;
        e->width = base->width;
        e->layer = base->layer;
        e->lgroup = base->lgroup;
    }
    /* 行に線色・線種があれば、それが勝つ（H04: 110 の行の「4 1」が色 4 になった） */
    if (r->have_color) {
        if (r->color > 0 && r->color <= 9)
            e->color = (unsigned short)r->color;
        if (r->ltype > 0)
            e->ltype = (unsigned char)r->ltype;
        if (r->width > 0)
            e->width = (unsigned short)r->width;
    }
}

static int sk_line(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                   const jw_sk_row *r)
{
    const jw_sk_pose *p = c->p;
    double kx = r->fac * p->sx * (r->real ? 1.0 / p->gscale : 1.0);
    double ky = r->fac * p->sy * (r->real ? 1.0 / p->gscale : 1.0);
    double ax[2], ay[2];
    int k1 = sk_code(r->c1), k2 = sk_code(r->c2);
    jw_obj *e;
    double sg = r->turn180 ? -1.0 : 1.0;

    if (k1 == 8 || k1 == 9 || k2 == 8 || k2 == 9)
        return 0;
    sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &ax[0], &ay[0]);
    sk_map(c, it, k2, 1, r->x1, r->y1, kx, ky, sg, &ax[1], &ay[1]);
    if (fabs(ax[0] - ax[1]) < 1e-9 && fabs(ay[0] - ay[1]) < 1e-9)
        return 0;                       /* 長さのない線は置かない */
    e = jw_add(d, JW_SEN);
    if (!e)
        return 0;
    e->d[0] = ax[0];
    e->d[1] = ay[0];
    e->d[2] = ax[1];
    e->d[3] = ay[1];
    sk_attr(e, r, p);
    return 1;
}

static int sk_arc(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                  const jw_sk_row *r)
{
    const jw_sk_pose *p = c->p;
    double kx = r->fac * p->sx * (r->real ? 1.0 / p->gscale : 1.0);
    double ky = r->fac * p->sy * (r->real ? 1.0 / p->gscale : 1.0);
    double sg = r->turn180 ? -1.0 : 1.0;
    int k1 = sk_code(r->c1), ones = r->c2 % 10, tens = r->c2 / 10 % 10;
    double cx, cy, rr, ws, we, tilt, sa, sw, flat;
    int full;
    jw_obj *e;
    double base_rho, thb;
    int mir, flipx, flipy;

    if (k1 == 8 || k1 == 9)
        return 0;
    sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &cx, &cy);
    {
        int k2m = sk_code(r->c2);
        double fx = (k2m == 5 || k2m == 6) ? c->msx : kx;
        double fy = (k2m == 5 || k2m == 6) ? c->msy : ky;

        rr = fabs(r->r) * fabs(fx);
        flat = rr > 0.0 ? fabs(r->r) * (r->r < 0.0 ? r->flat : 1.0) * fabs(fy) / rr : 1.0;
        flipx = fx * sg < 0.0;
        flipy = fy * sg < 0.0;
    }
    full = fabs(r->y1 - r->x1 - 360.0) < 1e-9 || (r->x1 == 0 && r->y1 == 360);

    /* 弧の角度。中心の取り方と同じ座標のまま、c2 の下一桁で線に追従する */
    if (ones == 0) {
        base_rho = p->axis;
        thb = 0.0;
        mir = 0;
    } else {
        base_rho = c->rho;
        thb = p->have1 ? c->th1 : p->have2 ? c->th2 : 0.0;
        mir = c->mirror && tens == 1;
    }
    {
        double ts = r->x1 * SK_PI / 180.0, te = r->y1 * SK_PI / 180.0;

        /* 倍率が マイナス の向きは 鏡（X が − なら 180° から引く、Y が − なら − を付ける）。
           片方だけなら向きが逆になるので 始点と終点を入れ替える */
        if (flipx) {
            ts = SK_PI - ts;
            te = SK_PI - te;
        }
        if (flipy) {
            ts = -ts;
            te = -te;
        }
        if (flipx != flipy) {
            double t = ts;

            ts = te;
            te = t;
        }
        ws = mir ? base_rho + 2.0 * thb - ts : base_rho + ts;
        we = mir ? base_rho + 2.0 * thb - te : base_rho + te;
        if (ones == 2 || ones == 4) {   /* 始点が線２に追従 */
            ws = mir ? c->rho2 + 2.0 * c->th2 - ts : c->rho2 + ts;
        }
        if (ones == 3 || ones == 4)     /* 終点 */
            we = mir ? c->rho2 + 2.0 * c->th2 - te : c->rho2 + te;
        if (mir) {                      /* 向きが逆になるので始点と終点が入れ替わる */
            double t = ws;

            ws = we;
            we = t;
        }
    }
    tilt = base_rho;
    if (full) {
        sa = 0.0;
        sw = 2.0 * SK_PI;
    } else {
        sa = norm_pi(ws - tilt);
        sw = we - ws;
        while (sw <= 1e-9)
            sw += 2.0 * SK_PI;
        while (sw > 2.0 * SK_PI + 1e-9)
            sw -= 2.0 * SK_PI;
    }
    e = jw_add(d, JW_ENKO);
    if (!e)
        return 0;
    e->d[0] = cx;
    e->d[1] = cy;
    e->d[2] = rr;
    e->d[3] = sa;
    e->d[4] = sw;
    e->d[5] = norm_pi(tilt);
    e->d[6] = flat;
    e->d[7] = 0.0;
    e->n = full ? 1 : 0;
    sk_attr(e, r, p);
    return 1;
}

/* 倍率位置から決まる倍率。基準点 (bx,by) を記号の座標で。mode は 760〜768 */
static void sk_mouse(const jw_sk_item *it, const jw_sk_pose *p, double *sx,
                     double *sy)
{
    double dx = p->mx - p->ox, dy = p->my - p->oy;
    double bx = it->mx, by = it->my;
    double ca = cos(-p->axis), sa = sin(-p->axis);
    double rx = dx * ca - dy * sa, ry = dx * sa + dy * ca;
    double fx = bx != 0.0 ? rx / bx : 1.0, fy = by != 0.0 ? ry / by : 1.0;
    double l = sqrt(rx * rx + ry * ry), lb = sqrt(bx * bx + by * by);

    switch (it->mouse) {
    case 761:
        fy = fx;
        break;
    case 762:
        fx = fy;
        break;
    case 763:
        fy = fabs(fx);
        break;
    case 764:
        fx = fabs(fy);
        break;
    case 765:
        fx = fabs(fx);
        fy = fabs(fy);
        break;
    case 766:
        fx = fy = lb > 0.0 ? l / lb : 1.0;
        break;
    case 767:
        fx = fy = fabs(fx) > fabs(fy) ? fabs(fx) : fabs(fy);
        break;
    case 768:
        if (fx < 0.0)
            fy = -fy;
        break;
    default:
        break;
    }
    *sx = fx;
    *sy = fy;
}

/* ソリッド（a1〜a7）。原典に A30 と A19〜A29 を押させた答え（sk_a30_lp など）から:
 *  a1 四角・三角・線: 四つの角を [A B B' A'] の順に（A'≠0・B'≠0 の四角、
 *     B'＝0 なら 三角 (A B A' A')、A'＝0 なら (A B B' B')、どちらも 0 なら 線 (A B B B)）。
 *     A'・B' は 辺 A→B を X 軸にした座標で、A・B から
 *  a2〜a7 円ソリッド: 線種 a2 a3 a4 → 101、a5 → 105、a6 → 106、a7 → 111。
 *     d[7] は a2 全周 100・a2 部分 0・a3 5・a4 −1・a5 a6 は内円の半径・a7 100。
 *     始角は 0〜2π のまま、傾きは枠の向き + 行の傾き */
static int sk_solid(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                    const jw_sk_row *r)
{
    const jw_sk_pose *p = c->p;
    double kx = r->fac * p->sx * (r->real ? 1.0 / p->gscale : 1.0);
    double ky = r->fac * p->sy * (r->real ? 1.0 / p->gscale : 1.0);
    double sg = r->turn180 ? -1.0 : 1.0;
    int k1 = sk_code(r->c1), k2 = sk_code(r->c2);
    jw_obj *e;

    if (k1 == 8 || k1 == 9)
        return 0;
    e = jw_add(d, JW_SOLID);
    if (!e)
        return 0;
    if (r->color == 10) {
        e->color = 10;
        e->n = (int)r->rgb;
    } else if (r->color > 0 && r->color <= 9) {
        e->color = (unsigned short)r->color;
    }
    if (r->solid == 1) {
        double wx[4], wy[4], ux, uy, l;
        double fx = (k1 == 5 || k1 == 6 || k2 == 5 || k2 == 6) ? c->msx : kx;
        double fy = (k1 == 5 || k1 == 6 || k2 == 5 || k2 == 6) ? c->msy : ky;
        int i;

        sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &wx[0], &wy[0]);
        sk_map(c, it, k2, 1, r->x1, r->y1, kx, ky, sg, &wx[1], &wy[1]);
        ux = wx[1] - wx[0];
        uy = wy[1] - wy[0];
        l = sqrt(ux * ux + uy * uy);
        if (l > 1e-9) {
            ux /= l;
            uy /= l;
        } else {
            ux = cos(p->axis);
            uy = sin(p->axis);
        }
        {
            double ax = r->a[0] * fx * sg, ay = r->a[1] * fy * sg;
            double bx = r->a[2] * fx * sg, by = r->a[3] * fy * sg;
            int a0 = r->a[0] != 0.0 || r->a[1] != 0.0;
            int b0 = r->a[2] != 0.0 || r->a[3] != 0.0;
            double ap[2], bp[2];

            ap[0] = wx[0] + ax * ux - ay * uy;
            ap[1] = wy[0] + ax * uy + ay * ux;
            bp[0] = wx[1] + bx * ux - by * uy;
            bp[1] = wy[1] + bx * uy + by * ux;
            if (a0 && b0) {
                wx[2] = bp[0]; wy[2] = bp[1]; wx[3] = ap[0]; wy[3] = ap[1];
            } else if (a0) {
                wx[2] = wx[3] = ap[0]; wy[2] = wy[3] = ap[1];
            } else if (b0) {
                wx[2] = wx[3] = bp[0]; wy[2] = wy[3] = bp[1];
            } else {
                wx[2] = wx[3] = wx[1]; wy[2] = wy[3] = wy[1];
            }
        }
        e->ltype = 1;
        for (i = 0; i < 4; i++) {
            e->d[i * 2] = wx[i];
            e->d[i * 2 + 1] = wy[i];
        }
        return 1;
    }
    {
        double cx, cy, rx, ry, sa, sw, tilt, rho, ws, we;
        double fx = (k2 == 5 || k2 == 6) ? c->msx : kx;
        double fy = (k2 == 5 || k2 == 6) ? c->msy : ky;
        int full = fabs(r->y1 - r->x1 - 360.0) < 1e-9, ones = r->c2 % 10;
        int mir = c->mirror && r->c2 / 10 % 10 == 1;

        sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &cx, &cy);
        rho = ones == 0 ? p->axis : c->rho;
        rx = fabs(r->r) * fabs(fx);
        ry = fabs(r->r) * r->flat * fabs(fy);
        ws = (mir ? -1.0 : 1.0) * r->x1 * SK_PI / 180.0;
        we = (mir ? -1.0 : 1.0) * r->y1 * SK_PI / 180.0;
        if (mir) {
            double t = ws;

            ws = we;
            we = t;
        }
        sa = ws;
        sw = we - ws;
        while (sa < 0.0)
            sa += 2.0 * SK_PI;
        while (sa >= 2.0 * SK_PI - 1e-9)
            sa -= 2.0 * SK_PI;
        while (sw <= 1e-9)
            sw += 2.0 * SK_PI;
        if (full) {
            sa = 0.0;
            sw = 2.0 * SK_PI;
        }
        tilt = rho + r->tilt * SK_PI / 180.0;
        e->ltype = 101;
        e->d[0] = cx;
        e->d[1] = cy;
        e->d[2] = rx;
        e->d[3] = rx > 0.0 ? ry / rx : 1.0;
        e->d[4] = norm_pi(tilt);
        e->d[5] = sa;
        e->d[6] = sw;
        switch (r->solid) {
        case 2:
            e->d[7] = full ? 100.0 : 0.0;
            break;
        case 3:
            e->d[7] = 5.0;
            break;
        case 4:
            e->d[7] = -1.0;
            break;
        case 5:
            e->ltype = 105;
            e->d[7] = r->inner * r->fac;
            break;
        case 6:
            e->ltype = 106;
            e->d[7] = r->inner * r->fac;
            break;
        default:
            e->ltype = 111;
            e->d[7] = 100.0;
            break;
        }
    }
    return 1;
}

/* 寸法値記入コード: 二点の間の長さを、寸法の値の書き方で（14010 は線１の両端など） */
static int sk_dimrow(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                     const jw_sk_row *r)
{
    const jw_sk_pose *p = c->p;
    double kx = r->fac * p->sx * (r->real ? 1.0 / p->gscale : 1.0);
    double ky = r->fac * p->sy * (r->real ? 1.0 / p->gscale : 1.0);
    double sg = r->turn180 ? -1.0 : 1.0, ax[2], ay[2];
    int n;

    sk_map(c, it, sk_code(r->c1), 0, r->x0, r->y0, kx, ky, sg, &ax[0], &ay[0]);
    sk_map(c, it, sk_code(r->c2), 1, r->x1, r->y1, kx, ky, sg, &ax[1], &ay[1]);
    n = jw_cmd_dim_text(d, ax[0], ay[0], ax[1], ay[1]);
    if (n > 0 && d->ndrawn > 0)
        d->obj[d->ndrawn - 1].layer = 15;
    return n;
}

/* 実点・点マーカー。種類は行の値だが 原典が n に何を入れるかは答えを見て決める */
static int sk_point(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                    const jw_sk_row *r)
{
    const jw_sk_pose *p = c->p;
    double kx = r->fac * p->sx * (r->real ? 1.0 / p->gscale : 1.0);
    double ky = r->fac * p->sy * (r->real ? 1.0 / p->gscale : 1.0);
    double sg = r->turn180 ? -1.0 : 1.0, wx, wy;
    int k1 = sk_code(r->c1);
    jw_obj *e;

    if (k1 == 8 || k1 == 9)
        return 0;
    sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &wx, &wy);
    e = jw_add(d, JW_TEN);
    if (!e)
        return 0;
    e->d[0] = wx;
    e->d[1] = wy;
    /* 行の「線種」の欄は 点の色、レイヤはレイヤ（B16 の 5・2 が 色 5・レイヤ 2 になった） */
    if (r->kind >= 1 && r->kind <= 9)
        e->color = (unsigned short)r->kind;
    if (r->have_layer && r->layer >= 0 && r->layer <= 15)
        e->layer = (unsigned short)r->layer;
    if (r->marker) {
        e->ltype = 100;
        e->mark = r->marker_c;
        e->size = r->x1;
        e->turn = r->y1 * SK_PI / 180.0;
    }
    return 1;
}

/* 文字入力の行か（20000・21000・25000・26000 台）。22000 台は入力をスキップした
   ときの文字で、それ自体は置かない */
static int is_input_row(const jw_sk_row *r)
{
    return r->cls == JW_SK_TEXTROW &&
           ((r->c1 >= 20000 && r->c1 < 22000) || (r->c1 >= 25000 && r->c1 < 27000));
}

/* 25000・26000 台は 打たない（NULL）と そこで以降の行を置くのをやめる */
static int is_loop_row(const jw_sk_row *r)
{
    return r->c1 >= 25000 && r->c1 < 27000;
}

static int is_skip_row(const jw_sk_row *r)
{
    return r->cls == JW_SK_TEXTROW && r->c1 >= 22000 && r->c1 < 23000;
}

static void sk_context(sk_ctx *c, const jw_sk_item *it, const jw_sk_pose *p,
                       jw_sk_txt *lt, int *cmd, const jw_sk_row *s_rows)
{
    memset(c, 0, sizeof *c);
    c->p = p;
    c->lt = lt;
    c->cmd = cmd;
    c->th1 = 0.0;
    c->th2 = SK_PI / 2.0;
    {
        int k, f1 = 0, f2 = 0;

        for (k = 0; k < it->n && !(f1 && f2); k++) {
            const jw_sk_row *r = &s_rows[k];
            double sg0 = r->turn180 ? -1.0 : 1.0;
            double dx = (r->x1 - r->x0) * sg0, dy = (r->y1 - r->y0) * sg0;

            if (r->cls != JW_SK_LINE || (fabs(dx) < 1e-9 && fabs(dy) < 1e-9))
                continue;
            if (!f1 && (r->c1 % 100 == 10 || r->c2 == 10)) {
                c->th1 = atan2(dy, dx);
                f1 = 1;
            }
            if (!f2 && (r->c1 % 100 == 20 || r->c2 == 20)) {
                c->th2 = atan2(dy, dx);
                f2 = 1;
            }
        }
    }
    c->rho1 = atan2(p->u1y, p->u1x) - c->th1;
    c->rho2 = atan2(p->u2y, p->u2x) - c->th2;
    {
        /* 斜交座標: 記号の +x が u1、記号の th2 の向きが u2 になるように */
        double sn = sin(c->th2), cs = cos(c->th2);

        if (fabs(sn) < 1e-9)
            sn = 1.0;
        c->oyx = (p->u2x - cs * p->u1x) / sn;
        c->oyy = (p->u2y - cs * p->u1y) / sn;
        c->mirror = p->have1 && p->have2 &&
                    (p->u1x * p->u2y - p->u1y * p->u2x) * sn < 0.0;
    }
    c->rho = p->have1 ? c->rho1 : p->have2 ? c->rho2 : p->axis;
    c->msx = c->msy = 1.0;
    if (it->mouse && p->have_m)
        sk_mouse(it, p, &c->msx, &c->msy);
}

/* 文字の行。text は置く文字（行の文字ではなく、打った文字・スキップの文字） */
static int sk_text(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                   const jw_sk_row *r, const char *text)
{
    const jw_sk_pose *p = c->p;
    double kx = r->fac * p->sx * (r->real ? 1.0 / p->gscale : 1.0);
    double ky = r->fac * p->sy * (r->real ? 1.0 / p->gscale : 1.0);
    double sg = r->turn180 ? -1.0 : 1.0;
    int k1 = sk_code(r->c1), k2 = sk_code(r->c2);
    double wx[2], wy[2];
    jw_tg_out o;

    if (!text || !text[0] || k1 == 8 || k1 == 9)
        return 0;
    sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &wx[0], &wy[0]);
    sk_map(c, it, k2, 1, r->x1, r->y1, kx, ky, sg, &wx[1], &wy[1]);
    memset(&o, 0, sizeof o);
    o.cls = JW_TG_TEXT_O;
    o.kind = r->kind;
    o.text = text;
    o.font = r->font[0] ? r->font : 0;
    o.italic = r->slant;
    {
        int n = jw_tg_text(d, &o, wx, wy, 0);

        if (n > 0 && c->lt && d->ndrawn > 0) {
            const jw_obj *e = &d->obj[d->ndrawn - 1];
            double ux = e->d[2] - e->d[0], uy = e->d[3] - e->d[1];
            double l = sqrt(ux * ux + uy * uy);

            c->lt->valid = 1;
            c->lt->sx = e->d[0];
            c->lt->sy = e->d[1];
            c->lt->w = l;
            c->lt->h = e->d[5];
            c->lt->ux = l > 1e-9 ? ux / l : 1.0;
            c->lt->uy = l > 1e-9 ? uy / l : 0.0;
        }
        return n;
    }
}

/* 行 from から、文字入力の行か終わりまで置く。止まった行の番号（なければ n）を返す */
static int sk_rows(jw_drawing *d, const sk_ctx *c, const jw_sk_item *it,
                   const jw_senkigou *s, int from, int *made)
{
    int k;

    for (k = from; k < it->n; k++) {
        const jw_sk_row *r = &s->row[it->first + k];

        if (is_input_row(r))
            return k;
        switch (r->cls) {
        case JW_SK_LINE:
            *made += sk_line(d, c, it, r);
            break;
        case JW_SK_ARC:
            *made += sk_arc(d, c, it, r);
            break;
        case JW_SK_SOLID:
            *made += sk_solid(d, c, it, r);
            break;
        case JW_SK_POINT:
            *made += sk_point(d, c, it, r);
            break;
        case JW_SK_DIMROW:
            *made += sk_dimrow(d, c, it, r);
            break;
        case JW_SK_CMD:                 /* ほかのコマンドへ。残りの行はそのあと（ここでは置かない） */
            if (c->cmd)
                *c->cmd = r->c1;
            return it->n;
        case JW_SK_TEXTROW:
            if (!is_skip_row(r))
                *made += sk_text(d, c, it, r, r->text);
            break;
        default:
            break;
        }
    }
    return it->n;
}

int jw_sk_start(jw_drawing *d, const jw_senkigou *s, int item,
                const jw_sk_pose *p, jw_sk_run *r, jw_sk_hist *hist)
{
    const jw_sk_item *it;
    sk_ctx c;
    int made = 0;

    memset(r, 0, sizeof *r);
    if (!d || !s || item < 0 || item >= s->nitem)
        return 0;
    it = &s->item[item];
    r->pose = *p;
    r->item = item;
    r->hist = hist;
    sk_context(&c, it, &r->pose, &r->lt, &r->cmd, &s->row[it->first]);
    r->next = sk_rows(d, &c, it, s, 0, &made);
    r->active = r->next < it->n;
    return made;
}

/* 末尾の数字に増分を足す（なければ 0 に足したものを付ける）。原典では
   全角の数字は数字と見られず、「１」は「１1」「１2」…と増える
   （decomp/res/sk_a19_x4.jww）。数字の桁（0 詰め）はそのまま */
static void sk_inc_text(const char *prev, int inc, char *out, size_t cap)
{
    size_t n = strlen(prev), e = n, b;
    long v = 0;
    int width = 0;
    char num[24];

    while (e > 0 && prev[e - 1] >= '0' && prev[e - 1] <= '9')
        e--;
    b = e;
    {
        size_t i;

        for (i = b; i < n; i++)
            v = v * 10 + (prev[i] - '0');
        width = (int)(n - b);
    }
    v += inc;
    snprintf(num, sizeof num, "%0*ld", width, v);
    snprintf(out, cap, "%.*s%s", (int)b, prev, num);
}

/* 止まっている行の、打たなければ置かれる文字 */
static const char *sk_default(const jw_senkigou *s, const jw_sk_run *r,
                              const jw_sk_row *row, int k, char *buf, size_t cap)
{
    (void)s;
    if (row->have_inc && r->hist && k < JW_SK_HIST && (*r->hist)[k][0]) {
        sk_inc_text((*r->hist)[k], row->inc, buf, cap);
        return buf;
    }
    return row->text;
}

const char *jw_sk_prompt(const jw_senkigou *s, const jw_sk_run *r)
{
    static char buf[JW_SK_TEXT];
    const jw_sk_item *it = &s->item[r->item];

    if (!r->active)
        return "";
    return sk_default(s, r, &s->row[it->first + r->next], r->next, buf, sizeof buf);
}

int jw_sk_input(jw_drawing *d, const jw_senkigou *s, jw_sk_run *r,
                const char *typed)
{
    const jw_sk_item *it = &s->item[r->item];
    const jw_sk_row *row;
    sk_ctx c;
    int made = 0, k;
    const char *text = typed;

    if (!r->active)
        return 0;
    row = &s->row[it->first + r->next];
    sk_context(&c, it, &r->pose, &r->lt, &r->cmd, &s->row[it->first]);
    if ((!typed || !typed[0]) && is_loop_row(row)) {
        r->active = 0;                  /* NULL: 以降の処理終了 */
        r->next = it->n;
        return 0;
    }
    if (!typed || !typed[0]) {          /* 入力をスキップ: スキップの行の文字を、この行の位置に */
        char dbuf[JW_SK_TEXT];

        text = "";
        if (row->c1 >= 21000 && row->c1 < 22000) {  /* 文字変更: 変更しなければ行の文字（増分つきなら前の文字に増分） */
            snprintf(r->tmp, sizeof r->tmp, "%s",
                     sk_default(s, r, row, r->next, dbuf, sizeof dbuf));
            text = r->tmp;
        } else
            for (k = 0; k < it->n; k++)
                if (is_skip_row(&s->row[it->first + k])) {
                    text = s->row[it->first + k].text;
                    break;
                }
    }
    made += sk_text(d, &c, it, row, text);
    if (row->have_inc && r->hist && r->next < JW_SK_HIST)
        snprintf((*r->hist)[r->next], JW_SK_TEXT, "%s", text);
    r->next = sk_rows(d, &c, it, s, r->next + 1, &made);
    r->active = r->next < it->n;
    return made;
}

int jw_sk_put(jw_drawing *d, const jw_senkigou *s, int item, const jw_sk_pose *p)
{
    jw_sk_run r;
    int made = jw_sk_start(d, s, item, p, &r, 0);

    while (r.active)
        made += jw_sk_input(d, s, &r, "");
    return made;
}
