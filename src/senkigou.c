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
        if (is_num_tok(tk)) {
            if (letter[0]) {
                if (ln < 8)
                    lnums[ln++] = strtod(tk, 0);
            } else if (nn < 24)
                nums[nn++] = strtod(tk, 0);
            continue;
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
        f = strstr(q, "\"$<");
        {
            size_t m = f ? (size_t)(f - q) : strlen(q);

            while (m > 0 && (q[m - 1] == '\r' || q[m - 1] == '\n' || q[m - 1] == ' '))
                m--;
            if (m >= sizeof r->text)
                m = sizeof r->text - 1;
            memcpy(r->text, q, m);
            r->text[m] = 0;
        }
        if (f) {
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

            if (s->want > 0 && s->nitem >= s->want)
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
            case JW_SK_LINE:
            case JW_SK_ARC:
            case JW_SK_TEXTROW:
            case JW_SK_POINT:
            case JW_SK_SOLID: {
                int a = r->c1 % 100, b2 = r->c2 % 100;

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
    int mirror;                 /* 線１と線２で作る座標が左手系 */
    double msx, msy;            /* 倍率位置から決まる倍率 */
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

    switch (code % 100) {
    case 5:
        /* 倍率位置: 指示点からの差が倍率をかけたもの */
        x = rx * c->msx * sg;
        y = ry * c->msy * sg;
        break;
    case 6: {
        /* 指定座標と基準点の差を、倍率位置からの差にする */
        double ma = cos(p->axis), mb = sin(p->axis);
        double dx = p->mx - p->ox, dy = p->my - p->oy;
        double mxs = dx * ma + dy * mb, mys = -dx * mb + dy * ma;

        x = (rx - it->mx) * kx * sg + mxs;
        y = (ry - it->my) * ky * sg + mys;
        break;
    }
    case 1:
        *wx = p->ox + x * p->u1x - y * p->u1y;
        *wy = p->oy + x * p->u1y + y * p->u1x;
        return;
    case 2:
        /* x は 線２に直角（線２の向きから 90° 戻した向き）、y が線２の向き */
        *wx = p->ox + x * p->u2y + y * p->u2x;
        *wy = p->oy - x * p->u2x + y * p->u2y;
        return;
    case 4:
        *wx = p->ox + x * p->u1x + y * p->u2x;
        *wy = p->oy + x * p->u1y + y * p->u2y;
        return;
    case 10:
        if (is_end) {
            *wx = p->e1x - y * p->u1y;
            *wy = p->e1y + y * p->u1x;
        } else {
            *wx = p->s1x - y * p->u1y;
            *wy = p->s1y + y * p->u1x;
        }
        return;
    case 20:
        if (is_end) {
            *wx = p->e2x + x * p->u2y;
            *wy = p->e2y - x * p->u2x;
        } else {
            *wx = p->s2x + x * p->u2y;
            *wy = p->s2y - x * p->u2x;
        }
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

    if (r->c1 < 10000 && h == 1) {
        e->color = p->attr1.color;
        e->ltype = p->attr1.ltype;
        e->width = p->attr1.width;
        e->layer = p->attr1.layer;
        e->lgroup = p->attr1.lgroup;
        return;
    }
    if (r->c1 < 10000 && h == 2) {
        e->color = p->attr2.color;
        e->ltype = p->attr2.ltype;
        e->width = p->attr2.width;
        e->layer = p->attr2.layer;
        e->lgroup = p->attr2.lgroup;
        return;
    }
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
    double cx, cy, rr, ws, we, tilt, sa, sw;
    int full;
    jw_obj *e;
    double base_rho;
    int mir;

    if (k1 == 8 || k1 == 9)
        return 0;
    sk_map(c, it, k1, 0, r->x0, r->y0, kx, ky, sg, &cx, &cy);
    rr = fabs(r->r) * (kx + ky) / 2.0;
    full = fabs(r->y1 - r->x1 - 360.0) < 1e-9 || (r->x1 == 0 && r->y1 == 360);

    /* 弧の角度。中心の取り方と同じ座標のまま、c2 の下一桁で線に追従する */
    if (ones == 0) {
        base_rho = p->axis;
        mir = 0;
    } else {
        base_rho = c->rho1;
        mir = c->mirror && tens == 1;
        if (!p->have1)
            base_rho = c->rho2;
    }
    {
        double ts = r->x1 * SK_PI / 180.0, te = r->y1 * SK_PI / 180.0;

        if (r->turn180) {
            ts += SK_PI;
            te += SK_PI;
        }
        ws = mir ? base_rho - ts : base_rho + ts;
        we = mir ? base_rho - te : base_rho + te;
        if (ones == 2 || ones == 4) {   /* 始点が線２に追従 */
            ws = mir ? c->rho2 + SK_PI - ts : c->rho2 + ts;
        }
        if (ones == 3 || ones == 4)     /* 終点 */
            we = mir ? c->rho2 + SK_PI - te : c->rho2 + te;
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
    e->d[6] = r->r < 0.0 ? r->flat : 1.0;
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

/* 文字入力の行か（20000・21000・25000・26000 台）。22000 台は入力をスキップした
   ときの文字で、それ自体は置かない */
static int is_input_row(const jw_sk_row *r)
{
    return r->cls == JW_SK_TEXTROW && r->c1 >= 20000 && r->c1 < 22000;
}

static int is_skip_row(const jw_sk_row *r)
{
    return r->cls == JW_SK_TEXTROW && r->c1 >= 22000 && r->c1 < 23000;
}

static void sk_context(sk_ctx *c, const jw_sk_item *it, const jw_sk_pose *p)
{
    memset(c, 0, sizeof *c);
    c->p = p;
    c->rho1 = atan2(p->u1y, p->u1x);
    c->rho2 = atan2(p->u2y, p->u2x) - SK_PI / 2.0;
    c->mirror = p->have1 && p->have2 &&
                p->u1x * p->u2y - p->u1y * p->u2x < 0.0;
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
    return jw_tg_text(d, &o, wx, wy, 0);
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
                const jw_sk_pose *p, jw_sk_run *r)
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
    sk_context(&c, it, &r->pose);
    r->next = sk_rows(d, &c, it, s, 0, &made);
    r->active = r->next < it->n;
    return made;
}

const char *jw_sk_prompt(const jw_senkigou *s, const jw_sk_run *r)
{
    const jw_sk_item *it = &s->item[r->item];

    return r->active ? s->row[it->first + r->next].text : "";
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
    sk_context(&c, it, &r->pose);
    if (!typed || !typed[0]) {          /* 入力をスキップ: スキップの行の文字を、この行の位置に */
        text = "";
        for (k = 0; k < it->n; k++)
            if (is_skip_row(&s->row[it->first + k])) {
                text = s->row[it->first + k].text;
                break;
            }
    }
    made += sk_text(d, &c, it, row, text);
    r->next = sk_rows(d, &c, it, s, r->next + 1, &made);
    r->active = r->next < it->n;
    return made;
}

int jw_sk_put(jw_drawing *d, const jw_senkigou *s, int item, const jw_sk_pose *p)
{
    jw_sk_run r;
    int made = jw_sk_start(d, s, item, p, &r);

    while (r.active)
        made += jw_sk_input(d, s, &r, "");
    return made;
}
