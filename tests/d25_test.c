/* ２．５D (32937) の (L) 設定・変更: 線の端に「高さ , 奥行」の文字が付く
   （原典 decomp/res/p197_h1.jww）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

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
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n)
        return 0;
    fclose(f);
    return b;
}

int main(void)
{
    long n, rn;
    unsigned char *b = slurp("decomp/res/new.jww", &n);
    unsigned char *rb = slurp("decomp/res/p197_h1.jww", &rn);
    jw_drawing ref;
    const jw_drawing *d;
    rect_t r;
    const jw_obj *a, *m;
    int k, fails = 0;

    if (!b || !rb)
        return 1;
    memset(&ref, 0, sizeof ref);
    jw_parse(&ref, rb, rn);
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32771);
    app_press(r.x + 300, r.y + 400, 0);
    app_press(r.x + 800, r.y + 400, 0);
    app_command(32937);
    app_press(r.x + 300, r.y + 400, 0);
    d = app_drawing();
    if (d->ndrawn < 2 || ref.ndrawn < 2) {
        printf("BAD  文字が付かない\n");
        return 1;
    }
    a = &ref.obj[1];
    m = &d->obj[d->ndrawn - 1];
    if (m->cls != JW_MOJI || m->color != a->color || m->ltype != a->ltype ||
        m->flags != a->flags || m->n != a->n) {
        printf("BAD  属性 cls%d col%d lt%d fl%x\n", m->cls, m->color, m->ltype, m->flags);
        fails++;
    }
    for (k = 0; k < 6; k++)
        if (fabs(a->d[k] - m->d[k]) > 2e-3) {
            printf("BAD  d[%d] 原典 %.4f・移植 %.4f\n", k, a->d[k], m->d[k]);
            fails++;
        }
    if (strcmp(jw_str(&ref, a->text), jw_str(d, m->text))) {
        printf("BAD  文字\n");
        fails++;
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
