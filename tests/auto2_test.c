/* AUTO モード (32915) の線編集: 原典に押させた答え decomp/res/au_*.jww（tools/autoprobe.sh）との突き合わせ。
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
    const char *name, *pre, *post;
} sc_t;

static const sc_t sc[] = {
    { "b8", "", "500,400;450,400;600,400;" },
    { "b8up", "", "500,400;550,300;450,400;" },
    { "b9", "", "500,400;450,400;450,400;" },
    { "b10", "", "500,400;850,400;900,400;" },
    { "b10m", "", "500,400;200,400;250,400;" },
    { "b10off", "", "500,400;850,300;900,300;" },
    { "b13", "500,200;500,600;", "350,400;500,250;" },
    { "b13r", "500,200;500,600;", "650,400;500,250;" },
    { "b13nc", "900,200;900,600;", "350,400;900,250;" },
    { "b15", "", "500,400;r650,400;" },
    { "b16", "500,200;500,600;", "350,400;r500,250;" },
    { "b17", "", "500,400;r700,550;" },
    { "b18", "650,200;650,600;750,200;750,600;", "500,400;450,400;r700,400;" },
    { "b19", "", "500,400;450,400;r800,400;" },
    { "r5", "", "r300,400;600,300;" },
    { "p1", "", "400,300;600,300;" },
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
        int nd = a->cls == JW_SEN ? 4 : a->cls == JW_ENKO ? 7
               : a->cls == JW_SOLID ? 8 : 4;
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
        snprintf(path, sizeof path, "decomp/res/au_%s.jww", sc[k].name);
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
        if (jw_cmd_bar_check(1333) > 0)       /* 原典は 水平・垂直 を切って押している */
            jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
        app_command(32915);
        clicks(&r, sc[k].post);
        if (same(&ref, app_drawing(), sc[k].name, argc > 1))
            fails++;
        else
            printf("ok   %s\n", sc[k].name);
    }
    printf(fails ? "SOME BAD (%d)\n" : "all ok\n", fails);
    return fails != 0;
}
