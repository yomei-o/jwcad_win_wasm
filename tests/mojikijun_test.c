/* 文字基点設定 -- the dialog, against the original's own.
 *
 *   tests/mojikijun_test.exe tests/out/mojikijun.png
 *
 * docs/ref_mojikijun.png is that dialog painted into a bitmap by Jw_cad
 * itself (tools/probe62.sh's last run, the same `dlg:b` step tools/gen.sh
 * uses for the others).  This puts the port's up in the same state and
 * writes it out to be scored against that picture; tools/check.sh does the
 * scoring, with the text left out of it.
 *
 * The nine radios are the part that does something: each one moves where a
 * placed text lands, and tests/mojidraw_test.c holds the port to the
 * original for all nine.  Here what is checked is that pressing one picks
 * it and that OK takes the dialog down.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include <math.h>
#include "../src/view.h"
#include "../src/gen/bars.h"
#include "../src/gen/mojikijun.h"
#include "png.h"

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

static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_mojikijun_rect(1264, 741, &r);
    for (i = 0; i < JW_NMOJIKIJUN; i++)
        if (jw_mojikijun[i].id == id) {
            *x = r.x + JW_MK_BORDER + jw_mojikijun[i].x
                 + jw_mojikijun[i].w / 2;
            *y = r.y + JW_MK_CAPTION + jw_mojikijun[i].y
                 + jw_mojikijun[i].h / 2;
            return;
        }
    *x = *y = -1;
}

static void press_bar(int id)
{
    int i, k;

    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != (unsigned)jw_cmd())
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int x = c->x + c->w / 2, y = c->y + c->h / 2;
            if (c->id != id || ui_bar_hit(x, y) != id)
                continue;
            app_press(x, y, 0);
            return;
        }
    }
    ck(0, "その釦がバーに無い");
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    ck(app_command(0x8026) != 0, "文字 を出す");
    ck(!app_mojikijun_open(), "基点のダイアログはまだ出ていない");
    press_bar(1064);
    ck(app_mojikijun_open() != 0, "基点 を押すと出る");
    ck(jw_cmd_moji_base_now() == 2, "出たときの基点は 左下");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_mojikijun_rect(fb->w, fb->h, &r);
        px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
        if (px) {
            for (j = 0; j < r.h; j++)
                for (i = 0; i < r.w; i++)
                    px[j * r.w + i] = fb->px[(size_t)(r.y + j) * fb->w
                                             + r.x + i];
            png_rgb(argv[1], r.w, r.h, px);
            free(px);
            printf("     wrote %s, %dx%d\n", argv[1], r.w, r.h);
        }
    }

    /* every one of the nine picks itself */
    for (i = 0; i < 9; i++) {
        char what[64];

        ctl(1689 + i, &x, &y);
        app_press(x, y, 0);
        sprintf(what, "  %d 番目を押すとそれが選ばれる", i);
        ck(jw_cmd_moji_base_now() == i, what);
        ck(app_mojikijun_open() != 0, "  ダイアログは出たまま");
    }

    /* the six ずれ boxes take typing, which the port could not do
       at all until now.  They are dead until ずれ使用 is on
       -- the original refuses to be driven into them before the tick
       (tools/probe70.sh) -- and what goes in them is what the drawing
       then uses (tests/mojidraw_test.c holds that to the original). */
    {
        static const struct { int id; int across, n; const char *v; } Z[6] = {
            { 2004, 1, 0, "5" },  { 2005, 1, 1, "6.5" }, { 2006, 1, 2, "-7" },
            { 2009, 0, 0, "3" },  { 2008, 0, 1, "0.25" }, { 2007, 0, 2, "8" }
        };
        int k;

        ck(jw_cmd_moji_zure_now() == 0, "ずれ使用 is off");
        ctl(2004, &x, &y);
        app_press(x, y, 0);
        app_key('5');
        ck(jw_cmd_moji_zure_get(1, 0) == 0.0,
           "  ずれ使用 の前は打ち込めない");
        ctl(1323, &x, &y);
        app_press(x, y, 0);
        ck(jw_cmd_moji_zure_now() != 0, "ずれ使用 を入れる");
        for (k = 0; k < 6; k++) {
            char what[80];
            const char *t;
            int c2;

            ctl(Z[k].id, &x, &y);
            app_press(x, y, 0);
            for (c2 = 0; Z[k].v[c2]; c2++)
                app_key((unsigned char)Z[k].v[c2]);
            t = jw_cmd_moji_zure_box(Z[k].id);
            sprintf(what, "  %d に %s が入る", Z[k].id, Z[k].v);
            ck(t && !strcmp(t, Z[k].v)
               && jw_cmd_moji_zure_get(Z[k].across, Z[k].n) == atof(Z[k].v),
               what);
        }
        /* backspace rubs one out, and the number follows */
        ctl(2004, &x, &y);
        app_press(x, y, 0);
        app_key('0');
        ck(jw_cmd_moji_zure_get(1, 0) == 50.0, "  打ち足せる");
        app_key(8);
        ck(jw_cmd_moji_zure_get(1, 0) == 5.0, "  一字消せる");
        app_key(8);
        ck(jw_cmd_moji_zure_get(1, 0) == 0.0, "  空にすると 0");
        /* and the dialog still paints */
        app_paint();
        for (k = 0; k < 6; k++)
            jw_cmd_moji_zure_at(Z[k].across, Z[k].n, 0.0);
        ctl(1323, &x, &y);
        app_press(x, y, 0);
        ck(jw_cmd_moji_zure_now() == 0, "ずれ使用 を戻す");
    }

    /* OK takes it down and keeps the last one */
    ctl(1691, &x, &y);                  /* back to 左下 */
    app_press(x, y, 0);
    ctl(1, &x, &y);
    app_press(x, y, 0);
    ck(!app_mojikijun_open(), "OK で閉じる");
    ck(jw_cmd_moji_base_now() == 2, "選んだものは残る");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
