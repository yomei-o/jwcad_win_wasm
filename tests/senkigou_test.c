/* 線記号変形 (32869): 原典に置かせた答え（decomp/res/sk_*.jww、
   tools/skprobe.sh と tools/skbatch*.sh）と、同じ押し方で置いた結果を比べる。
   押し方は 壁（300,400）→（800,400）を引き、pre の線を引き、記号を選んで、
   post の点を順に押す。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/tategu.h"
#include "../src/senkigou.h"

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
    const char *name;
    char file;                  /* 'A'〜'J' */
    int item;                   /* 1 から */
    const char *pre;            /* 先に引く線（二点ずつ） */
    const char *post;           /* 記号を選んだあとに押す点 */
} sc_t;

static const sc_t sc[] = {
    { "a01_l", 'A', 1, "", "450,400;" },
    { "a01_r", 'A', 1, "", "700,400;" },
    { "a01_sl", 'A', 1, "300,700;700,500;", "350,675;" },
    { "a02_lp", 'A', 2, "", "450,400;500,470;" },
    { "a02_rev", 'A', 2, "", "700,400;500,470;" },
    { "a02_sl", 'A', 2, "300,700;700,500;", "400,650;500,600;" },
    { "a03_pp", 'A', 3, "", "500,450;560,500;" },
    { "a03_x", 'A', 3, "", "500,450;600,430;" },
    { "a03_x2", 'A', 3, "", "500,450;460,470;" },
    { "a04_lp", 'A', 4, "", "450,400;500,470;" },
    { "a05_cr", 'A', 5, "600,500;600,300;", "400,400;600,350;" },
    { "a05_sw", 'A', 5, "600,500;600,300;", "600,350;400,400;" },
    { "a05_rb", 'A', 5, "600,500;600,300;", "700,400;600,450;" },
    { "a05_lb", 'A', 5, "600,500;600,300;", "400,400;600,450;" },
    { "a05_sl", 'A', 5, "500,500;700,300;", "400,400;650,350;" },
    { "a06_cr", 'A', 6, "600,500;600,300;", "400,400;600,350;" },
    { "a06_nc", 'A', 6, "600,500;600,450;", "400,400;600,470;" },
    { "a06_sl", 'A', 6, "500,500;700,300;", "400,400;650,350;" },
    { "a07_l", 'A', 7, "", "450,400;" },
    { "a08_lp", 'A', 8, "", "450,400;500,470;" },
    { "a08_rev", 'A', 8, "", "700,400;500,470;" },
    { "a09_lp", 'A', 9, "", "450,400;500,470;" },
    { "a10_p", 'A', 10, "", "500,450;" },
    { "a11_c", 'A', 11, "800,400;800,200;", "700,400;800,300;" },
    { "a11_cd", 'A', 11, "800,400;800,600;", "700,400;800,500;" },
    { "a11_rl", 'A', 11, "300,400;300,200;", "400,400;300,300;" },
    { "a11_rd", 'A', 11, "300,400;300,600;", "400,400;300,500;" },
    { "a11_sl", 'A', 11, "500,500;700,300;", "400,400;650,350;" },
    { "a12_c", 'A', 12, "800,400;800,200;", "700,400;800,300;" },
    { "a13_c", 'A', 13, "800,400;800,200;", "700,400;800,300;" },
    { "a14_c", 'A', 14, "800,400;800,200;", "700,400;800,300;" },
    { "a15_bar", 'A', 15, "", "500,450;" },
    { "a15_tl", 'A', 15, "", "500,450;t:XY;700,300;" },
    { "a15_def", 'A', 15, "", "500,450;700,300;" },
    { "a16_def", 'A', 16, "", "500,450;700,300;" },
    { "a16_ty", 'A', 16, "", "500,450;t:AB;700,300;" },
    { "a18_e3", 'A', 18, "", "500,450;700,300;700,300;700,300;" },
    { "a18_abc", 'A', 18, "", "500,450;t:A;700,300;t:B;700,300;t:C;700,300;" },
    { "a18_aee", 'A', 18, "", "500,450;t:A;700,300;700,300;700,300;" },
    { "a18_ea", 'A', 18, "", "500,450;700,300;t:B;700,300;" },
    { "e01_f", 'E', 1, "", "450,400;500,470;" },
    { "g07_f", 'G', 7, "", "450,400;500,470;" },
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
        int x = 0, y = 0, n = 0;

        if (s[0] == 't' && s[1] == ':') {       /* 文字を打つ（; まで） */
            s += 2;
            while (*s && *s != ';') {
                int rk = app_key((unsigned char)*s);

                if (getenv("SKDUMP"))
                    printf("  key %c -> %d line [%s] cmd %x\n", *s, rk, jw_cmd_line(), jw_cmd());
                s++;
            }
            while (*s == ';' || *s == ' ')
                s++;
            continue;
        }
        if (sscanf(s, "%d,%d%n", &x, &y, &n) != 2)
            break;
        app_press(r->x + x, r->y + y, 0);
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

static int collect(const jw_drawing *d, const jw_obj **out)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < 512; i++)
        if (!junk(&d->obj[i]))
            out[n++] = &d->obj[i];
    return n;
}

static int same(const jw_drawing *ref, const jw_drawing *d, const char *name,
                int verbose)
{
    const jw_obj *ra[512], *ma[512];
    int i, j, bad = 0, rn = collect(ref, ra), mn = collect(d, ma);

    if (rn != mn) {
        printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
        if (!verbose)
            return 1;
        bad = 1;
    }
    for (i = 0; i < rn && i < mn; i++) {
        const jw_obj *a = ra[i], *m = ma[i];
        int nd = a->cls == JW_SEN ? 4 : a->cls == JW_ENKO ? 7 : 4;
        int ok = 1;

        if (a->cls != m->cls) {
            printf("     %d: 種類 原典 %d・移植 %d\n", i, a->cls, m->cls);
            bad = 1;
            continue;
        }
        for (j = 0; j < nd; j++)
            if (fabs(a->d[j] - m->d[j]) > 2e-3) {
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
        if (a->cls == JW_MOJI && a->text >= 0 && m->text >= 0 &&
            (strcmp(jw_str(ref, a->text), jw_str(d, m->text)) ||
             strcmp(jw_str(ref, a->face), jw_str(d, m->face)))) {
            ok = 0;
            printf("     %d: 文字 原典 [%s]・移植 [%s]\n", i, jw_str(ref, a->text),
                   jw_str(d, m->text));
        }
        if (!ok)
            bad = 1;
    }
    if (bad)
        printf("BAD  %s\n", name);
    return bad;
}

int main(int argc, char **argv)
{
    size_t k;
    int fails = 0;

    for (k = 0; k < sizeof sc / sizeof sc[0]; k++) {
        char path[96];
        long n, rn;
        unsigned char *b = slurp("decomp/res/new.jww", &n), *rb;
        jw_drawing ref;
        rect_t r;
        int idx = jw_tgdat_index(4, sc[k].file - 'A');

        if (argc > 1 && strcmp(argv[1], sc[k].name))
            continue;
        snprintf(path, sizeof path, "decomp/res/sk_%s.jww", sc[k].name);
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
        clicks(&r, "300,400;800,400;");
        addlines((jw_drawing *)app_drawing(), sc[k].pre);
        if (getenv("SKDUMP")) {
            const jw_drawing *dd = app_drawing();
            int q;

            for (q = 0; q < dd->ndrawn; q++)
                if (!junk(&dd->obj[q]))
                    printf("  pre %d cls%d %.3f %.3f %.3f %.3f\n", q, dd->obj[q].cls,
                           dd->obj[q].d[0], dd->obj[q].d[1], dd->obj[q].d[2],
                           dd->obj[q].d[3]);
        }
        app_command(32869);
        jw_cmd_kigou_choose(idx, sc[k].item - 1);
        clicks(&r, sc[k].post);
        if (getenv("SKDUMP")) {
            const jw_drawing *dd = app_drawing();
            int q;

            for (q = 0; q < dd->ndrawn; q++)
                if (!junk(&dd->obj[q]))
                    printf("  post %d cls%d %.3f %.3f %.3f %.3f\n", q, dd->obj[q].cls,
                           dd->obj[q].d[0], dd->obj[q].d[1], dd->obj[q].d[2],
                           dd->obj[q].d[3]);
        }
        if (same(&ref, app_drawing(), sc[k].name, argc > 1)) {
            fails++;
        } else
            printf("ok   %s\n", sc[k].name);
    }
    printf(fails ? "SOME BAD (%d)\n" : "all ok\n", fails);
    return fails != 0;
}
