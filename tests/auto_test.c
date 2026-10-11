/* AUTOモード: 何もないところで二点 → 線が一本（原典 tools/probe196 と同じ）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

int main(void)
{
    FILE *f = fopen("decomp/res/new.jww", "rb");
    unsigned char *b;
    long n;
    rect_t r;
    const jw_drawing *d;
    int before, fails = 0;

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    d = app_drawing();
    before = d->ndrawn;
    app_command(32915);
    app_press(r.x + 400, r.y + 400, 0);
    app_press(r.x + 600, r.y + 400, 0);
    if (jw_cmd() != JW_CMD_AUTO || d->ndrawn != before + 1 ||
        d->obj[d->ndrawn - 1].cls != JW_SEN) {
        printf("BAD  線が一本できません (cmd %x, %d -> %d)\n", jw_cmd(),
               before, d->ndrawn);
        fails++;
    }

    {   /* R で線を押すと 複線。方向を押すと AUTO に戻る（p196_a3） */
        jw_drawing ref;
        unsigned char *rb;
        long rn, k;
        int ri = 0, mi = 0, j;
        FILE *rf = fopen("decomp/res/p196_a3.jww", "rb");
        const jw_obj *ra[64], *ma[64];

        fseek(rf, 0, SEEK_END);
        rn = ftell(rf);
        fseek(rf, 0, SEEK_SET);
        rb = (unsigned char *)malloc((size_t)rn);
        if (fread(rb, 1, (size_t)rn, rf) != (size_t)rn)
            return 1;
        fclose(rf);
        memset(&ref, 0, sizeof ref);
        jw_parse(&ref, rb, rn);
        app_new();
        app_resize(1264, 741);
        app_open(b, n);
        d = app_drawing();
        app_command(32771);
        app_press(r.x + 300, r.y + 400, 0);
        app_press(r.x + 800, r.y + 400, 0);
        app_command(32915);
        app_press(r.x + 550, r.y + 400, 1);
        if (jw_cmd() != JW_CMD_FUKUSEN) {
            printf("BAD  R で線を押しても 複線にならない\n");
            fails++;
        }
        app_press(r.x + 650, r.y + 300, 0);       /* 原典はここで「作図する方向」を問う */
        for (k = 0; k < ref.ndrawn && ri < 64; k++)
            if (ref.obj[k].cls == JW_SEN)
                ra[ri++] = &ref.obj[k];
        for (k = 0; k < d->ndrawn && mi < 64; k++)
            if (d->obj[k].cls == JW_SEN)
                ma[mi++] = &d->obj[k];
        if (ri != mi) {
            printf("BAD  線 原典 %d・移植 %d\n", ri, mi);
            fails++;
        } else {
            for (k = 0; k < ri; k++)
                for (j = 0; j < 4; j++)
                    if (fabs(ra[k]->d[j] - ma[k]->d[j]) > 2e-3) {
                        printf("BAD  %ld.d[%d] 原典 %.4f・移植 %.4f\n", k, j,
                               ra[k]->d[j], ma[k]->d[j]);
                        fails++;
                    }
        }
    }
    {   /* L で線を押す → 部分消し（三回押し）。AUTO に戻る（p196_a6） */
        jw_drawing ref;
        unsigned char *rb;
        long rn, k;
        int ri = 0, mi = 0, j;
        FILE *rf = fopen("decomp/res/p196_a6.jww", "rb");
        const jw_obj *ra[64], *ma[64];

        fseek(rf, 0, SEEK_END);
        rn = ftell(rf);
        fseek(rf, 0, SEEK_SET);
        rb = (unsigned char *)malloc((size_t)rn);
        if (fread(rb, 1, (size_t)rn, rf) != (size_t)rn)
            return 1;
        fclose(rf);
        memset(&ref, 0, sizeof ref);
        jw_parse(&ref, rb, rn);
        app_new();
        app_resize(1264, 741);
        app_open(b, n);
        d = app_drawing();
        app_command(32771);
        app_press(r.x + 300, r.y + 400, 0);
        app_press(r.x + 800, r.y + 400, 0);
        app_command(32915);
        app_press(r.x + 450, r.y + 400, 0);
        app_press(r.x + 400, r.y + 400, 0);
        app_press(r.x + 650, r.y + 400, 0);
        if (jw_cmd() != JW_CMD_AUTO) {
            printf("BAD  部分消しのあと AUTO に戻らない\n");
            fails++;
        }
        for (k = 0; k < ref.ndrawn && ri < 64; k++)
            if (ref.obj[k].cls == JW_SEN)
                ra[ri++] = &ref.obj[k];
        for (k = 0; k < d->ndrawn && mi < 64; k++)
            if (d->obj[k].cls == JW_SEN)
                ma[mi++] = &d->obj[k];
        if (ri != mi) {
            printf("BAD  部分消し 線 原典 %d・移植 %d\n", ri, mi);
            fails++;
        } else {
            for (k = 0; k < ri; k++)
                for (j = 0; j < 4; j++)
                    if (fabs(ra[k]->d[j] - ma[k]->d[j]) > 2e-3) {
                        printf("BAD  %ld.d[%d] 原典 %.4f・移植 %.4f\n", k, j,
                               ra[k]->d[j], ma[k]->d[j]);
                        fails++;
                    }
        }
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
