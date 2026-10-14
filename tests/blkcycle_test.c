/* Blocks that refer to themselves, and blocks nested deeper than anything the
   original's samples have: every writer, the picture, the picker and 範囲選択
   must come back (no crash, no endless recursion). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

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
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

/* put the drawing through everything that walks blocks */
static void walk(jw_drawing *d, const char *what)
{
    unsigned char *x = 0, *y = 0;
    long xn = 0, yn = 0;
    int ok = 1, i;
    rect_t r;
    const fb_t *fb;
    char msg[160];

    if (!jw_write(d, &x, &xn) || !x)
        ok = 0;
    sprintf(msg, "%s: the .jww is written", what);
    ck(ok, msg);
    if (ok && app_open(x, xn)) {
        app_paint();
        fb = app_fb();
        ui_view_rect(fb->w, fb->h, &r);
        jw_cmd_set(JW_CMD_HANI);
        app_press(r.x + 50, r.y + 50, 0);
        app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
        app_paint();
        app_command(32787);
        app_command(57634);             /* コピー */
        app_command(32909);             /* ブロック解除 */
        app_command(32853);             /* ブロック化 */
        app_command(32918);             /* 図形移動 */
        for (i = 0; i < 5; i++)
            app_press(r.x + 100 + i * 150, r.y + 200, 0);
        app_paint();
        free(y);
        y = 0;
        app_save_dxf(&y, &yn);
        free(y);
        y = 0;
        app_save_sfc("t.sfc", &y, &yn);
        free(y);
        y = 0;
        app_save_jwc(&y, &yn);
        free(y);
        sprintf(msg, "%s: opened, drawn, picked, saved as DXF, SFC and JWC", what);
        ck(1, msg);
    } else if (ok) {
        sprintf(msg, "%s: the writer's file is read back", what);
        ck(0, msg);
    }
    free(x);
}

int main(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/bt_nest2.jww", &n);
    jw_drawing d;
    int i, list = -1, refs = 0, depth;

    app_resize(1264, 741);
    ck(b != 0, "bt_nest2.jww is there");

    /* every reference inside a definition now points back at that definition */
    memset(&d, 0, sizeof d);
    ck(jw_parse(&d, b, n), "it reads");
    for (i = d.ndrawn; i < d.nobj; i++) {
        if (d.obj[i].cls == JW_LIST)
            list = d.obj[i].list[0];
        else if (d.obj[i].cls == JW_BLOCK && list >= 0) {
            d.obj[i].block = list;
            refs++;
        }
    }
    printf("     %d references turned back on their own block\n", refs);
    walk(&d, "self-referring");
    jw_free(&d);

    /* and a chain: each definition's reference points at the next one, the last at the first */
    memset(&d, 0, sizeof d);
    jw_parse(&d, b, n);
    {
        int ids[64], k = 0, c = 0;

        for (i = d.ndrawn; i < d.nobj && k < 64; i++)
            if (d.obj[i].cls == JW_LIST)
                ids[k++] = d.obj[i].list[0];
        for (i = d.ndrawn; i < d.nobj; i++) {
            if (d.obj[i].cls == JW_LIST)
                c = 0;
            else if (d.obj[i].cls == JW_BLOCK && k > 0)
                d.obj[i].block = ids[(c++ + 1) % k];
        }
    }
    walk(&d, "round a loop");
    jw_free(&d);

    /* a chain of references to a missing definition */
    memset(&d, 0, sizeof d);
    jw_parse(&d, b, n);
    for (i = 0; i < d.nobj; i++)
        if (d.obj[i].cls == JW_BLOCK)
            d.obj[i].block = 99999;
    walk(&d, "to a block that is not there");
    jw_free(&d);
    (void)depth;
    free(b);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
