/* 日影図 (32943)・２．５D (32937) の高さの文字: 原典に押させた答え decomp/res/hk_*.jww（tools/hkprobe.sh）との突き合わせ。
   post は 押す点（r を頭に付けると右）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/tategu.h"

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        fclose(f);
        return 0;
    }
    fclose(f);
    return b;
}

typedef struct {
    const char *name; int cmd; const char *pre, *post;
} sc_t;

static const sc_t sc[] = {
    { "a1", 32943, "", "b:10;310,400;790,400;550,400;" },
    { "a5h", 32943, "300,300;600,300;300,330;600,330;300,360;600,360;300,430;600,430;300,460;600,460;300,490;600,490;300,520;600,520;300,550;600,550;", "b:3*4;310,300;b:10..5;310,330;b:10 , 0;310,360;b:0.5;310,430;b:-5;310,460;b:1/3;310,490;b:12;310,520;b:abc;310,550;" },
    { "a6e", 32943, "300,400;350,200;", "n:1;350,200;" },
    { "a6er", 32943, "300,400;350,200;", "n:1;r350,200;" },
    { "a6b", 32943, "500,500;600,400;", "n:1;500,500;" },
    { "a6c", 32943, "500,500;600,400;", "n:1;600,400;" },
    { "b1", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1064;B:1065;" },
    { "b3", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1064;B:1066;" },
    { "t1", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1064;B:1069;700,650;" },
    { "k2", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1066;700,200;760,200;B:1065;750,650;" },
    { "t2", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1064;B:1070;700,650;" },
    { "t3", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1064;B:1071;700,650;" },
    { "s1", 32971, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;",
      "b:10;405,300;595,300;595,500;405,500;B:1064;500,600;900,300;" },
    { "c1", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:2436=1;B:1064;B:1065;" },
    { "c2", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:2436=2;B:1064;B:1065;" },
    { "c3", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1323;B:1064;B:1065;" },
    { "c4", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:1493=40;B:1064;B:1065;" },
    { "c5", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:1493=50;B:1064;B:1065;" },
    { "c6", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:1493=60;B:1064;B:1065;" },
    { "c7", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;D:10;B:1064;B:1065;" },
    { "i1", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1065;B:1066;" },
    { "c8", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:2436=2;B:1064;B:1066;" },
    { "c9", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;D:12;B:1064;B:1065;" },
    { "i3", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1065;B:1068;" },
    { "i4", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;x:2436=2;B:1065;B:1067;" },
    { "i5", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1065;B:1071;B:1066;" },
    { "i6", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1323;B:1065;B:1065;" },
    { "i7", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1065;B:1072;450,350;650,450;B:1066;" },
    { "u1", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;n:1;300,600;B:1064;T:10.5;" },
    { "w1", 32943, "400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;300,650;300,600;",
      "b:10;405,300;595,300;595,500;405,500;B:1085;700,650;" },
    { "a5d", 32937, "300,300;600,300;300,330;600,330;300,360;600,360;300,430;600,430;300,460;600,460;300,490;600,490;300,520;600,520;300,550;600,550;", "b:v10;310,300;b:10h;310,330;b:3*4;310,360;b:10..5;310,430;b:10,0;310,460;b:g5;310,490;b:T1;310,520;" },
};


/* 先に引く線は 線の命令では斜めが水平・垂直に寄せられるので、図面に直に足す
   （押した画素 → mm は 壁（300,400）→（800,400）が 150.612 まで伸びる比） */
static void addlines(jw_drawing *d, const char *s)
{
    while (*s) {
        int a, b, c, e, n = 0;
        jw_obj *o;

        if (sscanf(s, "%d,%d;%d,%d%n", &a, &b, &c, &e, &n) != 4)
            break;
        o = jw_add(d, JW_SEN);
        o->d[0] = (a - 300) / 1.633333333 - 155.510204;
        o->d[1] = -34.897959 - (b - 400) / 1.633333333;
        o->d[2] = (c - 300) / 1.633333333 - 155.510204;
        o->d[3] = -34.897959 - (e - 400) / 1.633333333;
        s += n;
        while (*s == ';' || *s == ' ')
            s++;
    }
}

static void clicks(rect_t *r, const char *s)
{
    while (*s) {
        int x = 0, y = 0, n = 0, rt = 0;

        if (s[0] == 'b' && s[1] == ':') {
            char buf[40];
            int bn = 0;

            s += 2;
            while (*s && *s != ';' && bn < 38)
                buf[bn++] = *s++;
            buf[bn] = 0;
            jw_cmd_box_put(1491, buf);
            while (*s == ';')
                s++;
            continue;
        }
        if (s[0] == 'B' && s[1] == ':') {       /* バーの釦 */
            jw_cmd_bar((jw_drawing *)app_drawing(), atoi(s + 2));
            while (*s && *s != ';')
                s++;
            while (*s == ';')
                s++;
            continue;
        }
        if (s[0] == 'x' && s[1] == ':') {       /* x:<箱の番号>=<文字> */
            char buf[40];
            int id = atoi(s + 2), bn = 0;

            while (*s && *s != '=' && *s != ';')
                s++;
            if (*s == '=')
                s++;
            while (*s && *s != ';' && bn < 38)
                buf[bn++] = *s++;
            buf[bn] = 0;
            jw_cmd_box_put(id, buf);
            while (*s == ';')
                s++;
            continue;
        }
        if (s[0] == 'D' && s[1] == ':') {       /* 任意時期の 日赤緯 */
            jw_cmd_hikage_dec(s + 2);
            while (*s && *s != ';')
                s++;
            while (*s == ';')
                s++;
            continue;
        }
        if (s[0] == 'T' && s[1] == ':') {       /* 時間指定の窓に 時間を入れて OK */
            jw_cmd_hikage_time((jw_drawing *)app_drawing(), s + 2);
            while (*s && *s != ';')
                s++;
            while (*s == ';')
                s++;
            continue;
        }
        if (s[0] == 'n' && s[1] == ':') {       /* 真北の釦 */
            jw_cmd_bar((jw_drawing *)app_drawing(), 1068);
            s += 2;
            while (*s && *s != ';')
                s++;
            while (*s == ';')
                s++;
            continue;
        }
        if (*s == 'r') {
            rt = 1;
            s++;
        }
        if (sscanf(s, "%d,%d%n", &x, &y, &n) != 2)
            break;
        app_press(r->x + x, r->y + y, rt);
        s += n;
        while (*s == ';' || *s == ' ')
            s++;
    }
}

/* 白紙の図面が持っている「Printer_…」の文字は数えない（置き場所が原典と違うだけ） */
static int junk(const jw_obj *o)
{
    return o->cls == JW_MOJI && o->d[0] == 0.0 && o->d[1] == -1000.0;
}

static int g_skipn = 4;
static const char *g_skip;     /* この文字を持つ要素の 組（id）は 比べない（正午の すれすれの場合） */

static int collect(const jw_drawing *d, const jw_obj **out)
{
    int i, n = 0, skip = -1;

    if (g_skip) {                       /* 日影の組は 時間ごとに続き番号。五つ目（12 時）を除く */
        int lo = 1 << 30;

        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].id > 0 && d->obj[i].id < lo)
                lo = d->obj[i].id;
        if (lo < (1 << 30))
            skip = lo + g_skipn;
    }
    for (i = 0; i < d->ndrawn && n < 2048; i++)
        if (!junk(&d->obj[i]) && !(skip > 0 && d->obj[i].id == skip))
            out[n++] = &d->obj[i];
    return n;
}

static double g_tol = 2e-3;
static int g_loose;           /* 等時間: 格子の数え方の 1 の違いで 点が動く。長さの合計・外枠・本数で見る */
static int g_slack;           /* 原典の整数の走査と 格子点が 0.001 mm 以内で食い違う点の数 */   /* 日影の外形は 原典の走査線の量子化で 0.01 mm ほどずれる */

static int same(const jw_drawing *ref, const jw_drawing *d, const char *name,
                int verbose)
{
    const jw_obj *ra[2048], *ma[2048];
    int i, j, bad = 0, nbad = 0, rn = collect(ref, ra), mn = collect(d, ma);

    if (g_loose) {
        double lr = 0, lm = 0, x0r = 1e9, x1r = -1e9, y0r = 1e9, y1r = -1e9, x0m = 1e9, x1m = -1e9, y0m = 1e9, y1m = -1e9;
        int sr = 0, sm = 0, pass;

        for (pass = 0; pass < 2; pass++) {
            const jw_obj **a = pass ? ma : ra;
            int cnt = pass ? mn : rn, top = 0;

            for (i = 0; i < cnt; i++)
                if (a[i]->id > top)
                    top = a[i]->id;
            for (i = 0; i < cnt; i++)
                if (a[i]->cls == JW_SEN && a[i]->id == top) {
                    double len = hypot(a[i]->d[2] - a[i]->d[0], a[i]->d[3] - a[i]->d[1]);

                    for (j = 0; j < 4; j += 2) {
                        double *lo_x = pass ? &x0m : &x0r, *hi_x = pass ? &x1m : &x1r;
                        double *lo_y = pass ? &y0m : &y0r, *hi_y = pass ? &y1m : &y1r;

                        if (a[i]->d[j] < *lo_x) *lo_x = a[i]->d[j];
                        if (a[i]->d[j] > *hi_x) *hi_x = a[i]->d[j];
                        if (a[i]->d[j + 1] < *lo_y) *lo_y = a[i]->d[j + 1];
                        if (a[i]->d[j + 1] > *hi_y) *hi_y = a[i]->d[j + 1];
                    }
                    if (pass) { lm += len; sm++; } else { lr += len; sr++; }
                }
        }
        if (abs(sr - sm) > 4 || fabs(lr - lm) > 2e-3 * lr || fabs(x0r - x0m) > 0.3 || fabs(x1r - x1m) > 0.3 ||
            fabs(y0r - y0m) > 0.3 || fabs(y1r - y1m) > 0.3 || abs(rn - mn) > 5) {
            printf("BAD  %s: 線 原典 %d 本 長さ %.2f・移植 %d 本 長さ %.2f  枠 x %.2f..%.2f／%.2f..%.2f y %.2f..%.2f／%.2f..%.2f\n",
                   name, sr, lr, sm, lm, x0r, x1r, x0m, x1m, y0r, y1r, y0m, y1m);
            return 1;
        }
        return 0;
    }

    if (rn != mn) {
        printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
        if (!verbose)
            return 1;
        bad = 1;
    }
    for (i = 0; i < rn && i < mn; i++) {
        const jw_obj *a = ra[i], *m = ma[i];
        int nd = a->cls == JW_SEN ? 4 : a->cls == JW_ENKO ? 7
               : a->cls == JW_SOLID ? 8 : 4;
        int ok = 1;

        if (a->cls != m->cls) {
            printf("     %d: 種類 原典 %d・移植 %d\n", i, a->cls, m->cls);
            bad = 1;
            continue;
        }
        for (j = 0; j < nd; j++)
            if (fabs(a->d[j] - m->d[j]) > g_tol) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, j, a->d[j],
                       m->d[j]);
            }
        if (a->color != m->color || a->ltype != m->ltype || a->width != m->width ||
            a->layer != m->layer || a->flags != m->flags || a->n != m->n) {
            ok = 0;
            printf("     %d: 属性 原典 col%d lt%d w%d ly%d fl%x n%d・移植 col%d lt%d w%d ly%d fl%x n%d\n",
                   i, a->color, a->ltype, a->width, a->layer, a->flags, a->n,
                   m->color, m->ltype, m->width, m->layer, m->flags, m->n);
        }
        if (a->cls == JW_MOJI && (fabs(a->d[7] - m->d[7]) > 2e-3 || fabs(a->d[4] - m->d[4]) > 2e-3)) {
            ok = 0;
            printf("     %d: 角度 原典 %.3f・移植 %.3f\n", i, a->d[7], m->d[7]);
        }
        if (a->cls == JW_MOJI && a->text >= 0 && m->text >= 0 &&
            (strcmp(jw_str(ref, a->text), jw_str(d, m->text)) ||
             strcmp(jw_str(ref, a->face), jw_str(d, m->face)))) {
            ok = 0;
            printf("     %d: 文字 原典 [%s]・移植 [%s]\n", i, jw_str(ref, a->text),
                   jw_str(d, m->text));
        }
        if (!ok) {
            bad = 1;
            nbad++;
        }
    }
    if (bad && rn == mn && nbad <= g_slack)
        return 0;
    if (bad)
        printf("BAD  %s\n", name);
    return bad;
}

int main(int argc, char **argv)
{
    int fails = 0;
    size_t k;

    for (k = 0; k < sizeof sc / sizeof sc[0]; k++) {
        char path[96];
        long n, rn;
        unsigned char *b = slurp("decomp/res/new.jww", &n), *rb;
        jw_drawing ref;
        rect_t r;

        if (argc > 1 && strcmp(argv[1], sc[k].name))
            continue;
        snprintf(path, sizeof path, "decomp/res/hk_%s.jww", sc[k].name);
        rb = slurp(path, &rn);
        if (!rb || !b) {
            printf("BAD  %s が読めません\n", path);
            fails++;
            continue;
        }
        memset(&ref, 0, sizeof ref);
        jw_parse(&ref, rb, rn);
        free(rb);
        app_new();
        app_resize(1264, 741);
        app_open(b, n);
        free(b);
        ui_view_rect(app_fb()->w, app_fb()->h, &r);
        app_command(32771);
        addlines((jw_drawing *)app_drawing(), sc[k].pre);
        if (sc[k].name[1] == '1' && sc[k].name[0] == 'a')
            addlines((jw_drawing *)app_drawing(), "300,400;800,400;");
        app_command(sc[k].cmd);
        if (sc[k].cmd == 32943) {               /* 条件は 試験のあいだ持ち越さない */
            jw_cmd_box_put(1493, "36");
            jw_cmd_box_put(2436, "");
            if (jw_cmd_bar_check(1323) > 0)
                jw_cmd_bar((jw_drawing *)app_drawing(), 1323);
        }
        clicks(&r, sc[k].post);
        if (getenv("HKREF")) {
            int q;

            for (q = 0; q < ref.ndrawn; q++)
                if (!junk(&ref.obj[q]))
                    printf("  ref %d id%d cls%d %.3f %.3f %.3f %.3f\n", q, ref.obj[q].id, ref.obj[q].cls,
                           ref.obj[q].d[0], ref.obj[q].d[1], ref.obj[q].d[2], ref.obj[q].d[3]);
        }
        if (getenv("HKDUMP")) {
            const jw_drawing *dd = app_drawing();
            int q;

            for (q = 0; q < dd->ndrawn; q++)
                if (!junk(&dd->obj[q]))
                    printf("  post %d id%d cls%d %.3f %.3f %.3f %.3f\n", q, dd->obj[q].id, dd->obj[q].cls,
                           dd->obj[q].d[0], dd->obj[q].d[1], dd->obj[q].d[2], dd->obj[q].d[3]);
        }
        g_tol = sc[k].name[0] == 'b' || sc[k].name[0] == 'c' ? 0.02 : 2e-3;
        if (sc[k].name[0] == 't' || sc[k].name[0] == 'k' || sc[k].name[0] == 's' || sc[k].name[0] == 'u' || sc[k].name[0] == 'w' || sc[k].name[0] == 'i')
            g_tol = 0.02;
        g_slack = sc[k].name[0] == 'i' ? 4 : 0;
        g_loose = sc[k].name[0] == 'i' && strcmp(sc[k].name, "i1");
        g_skip = sc[k].name[0] == 'b' || sc[k].name[0] == 'c' ? "12.0" : 0;
        g_skipn = !strcmp(sc[k].name, "b3") || !strcmp(sc[k].name, "c8") ? 8 : !strcmp(sc[k].name, "c3") || !strcmp(sc[k].name, "c5") || !strcmp(sc[k].name, "c6") ? 3 : 4;
        if (same(&ref, app_drawing(), sc[k].name, argc > 1))
            fails++;
        else
            printf("ok   %s\n", sc[k].name);
    }
    printf(fails ? "SOME BAD (%d)\n" : "all ok\n", fails);
    return fails != 0;
}
