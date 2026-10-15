/* レイヤ設定 -- the dialog, against five pictures of the original's own.
 *
 *   tests/layerdlg_test.exe tests/out/layerdlg
 *
 * The original painted each of those pictures itself (tools/probe11.sh and
 * tools/probe12.sh drive it; docs/ref_layerdlg*.png are the results), all
 * of them over orig/Test5.jww:
 *
 *   ref_layerdlg.png             as the drawing comes -- group 0 is the
 *                                write group, layer 8 the write layer
 *   ref_layerdlg_hidden.png      一括 (1141) pressed once: 非表示
 *   ref_layerdlg_shown.png       and twice: 表示のみ
 *   ref_layerdlg_emptywrite.png  the empty layer 5 made the write layer
 *   ref_layerdlg_emptygroup.png  the empty group 1 made the write group
 *
 * The last two are the same drawing with three longs patched in its header,
 * which is what this does here as well rather than keeping two more files:
 * the write group index, the group's state and the layer's state.  They are
 * worth having because the original draws a different picture on a layer
 * with nothing on it, and only an empty write layer and an empty write
 * group show the last two of the eight.
 *
 * This puts the port's dialog up in each of those five states and writes it
 * out; tools/check.sh scores each against its picture, with the text left
 * out of it (docs/layerdlg_textareas.txt).
 *
 * It is a tab control, the only one anything here draws: the sixteen layer
 * groups sit on it eight to a row, 8..F above and 0..7 below, and the one
 * being written to is the cell that is bigger and open at the bottom.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/layerdlg.h"
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

/* the longs in the header that say who is being written to.  At 31 is the
 * write group index, and from 35 come sixteen groups of 148 bytes each: a
 * state, the write layer, the scale (eight), a colour, and then sixteen
 * layers of a state and a second state. */
#define H_WGROUP 31
#define H_GROUP  35
#define H_STRIDE 148
#define H_LAYER  (H_GROUP + 20)         /* the first layer's state */

static void put_l(unsigned char *p, int v)
{
    p[0] = (unsigned char)v;
    p[1] = (unsigned char)(v >> 8);
    p[2] = (unsigned char)(v >> 16);
    p[3] = (unsigned char)(v >> 24);
}

static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_layerdlg_rect(1264, 741, &r);
    for (i = 0; i < JW_NLAYERDLG; i++)
        if (jw_layerdlg[i].id == id) {
            *x = r.x + JW_LD_BORDER + jw_layerdlg[i].x + jw_layerdlg[i].w / 2;
            *y = r.y + JW_LD_CAPTION + jw_layerdlg[i].y
                 + jw_layerdlg[i].h / 2;
            return;
        }
    *x = *y = -1;
}

static void press(int id)
{
    int x, y;

    ctl(id, &x, &y);
    if (x >= 0)
        app_press(x, y, 0);
}

/* put the dialog up over the bytes given and write the picture out */
static void shot(const unsigned char *b, long n, const char *path,
                 int ikkatsu, const char *what)
{
    const fb_t *fb = app_fb();
    rect_t r;
    unsigned int *px;
    int i, j;

    if (!app_open((unsigned char *)b, n)) {
        ck(0, what);
        return;
    }
    ck(app_command(32808), what);
    while (ikkatsu-- > 0)
        press(1141);
    app_paint();
    ui_layerdlg_rect(fb->w, fb->h, &r);
    px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
    if (px) {
        for (j = 0; j < r.h; j++)
            for (i = 0; i < r.w; i++)
                px[j * r.w + i] = fb->px[(size_t)(r.y + j) * fb->w + r.x + i];
        png_rgb(path, r.w, r.h, px);
        free(px);
    }
    press(1);                           /* OK */
    ck(!app_layerdlg_open(), "  OK で閉じる");
}

/* the names, 戻す and 1323.  Read off the decompilation (CBN_EDITCHANGE
 * FUN_005615f0 / FUN_00561690, 戻す FUN_00560eb0, the status line's
 * "[%X-%X]%s" in FUN_0050ede0), not pressed in the original. */
static void names(const unsigned char *b, long n)
{
    jw_drawing *d;
    jw_drawing r;
    unsigned char *out = 0;
    long m = 0;
    const char *t;
    int g, w, k, ok;

    if (!app_open((unsigned char *)b, n)) {
        ck(0, "open");
        return;
    }
    d = (jw_drawing *)app_drawing();
    for (g = 0, k = 0; k < 16; k++)
        if (d->group[k].state == 3)
            g = k;
    w = d->group[g].write_layer & 15;

    app_command(32808);
    press(1838);
    for (k = 0; k < 20; k++)
        app_key(8);
    app_key('A');
    app_key('b');
    app_key(0x88);                      /* 一 (0x88ea), a byte at a time */
    app_key(0xea);
    ck(!strcmp(jw_str(d, d->group[g].name), "Ab\x88\xea"),
       "グループ名を打つとそのまま名前になる");
    press(1839);
    for (k = 0; k < 20; k++)
        app_key(8);
    app_key('x');
    app_key('1');
    ck(!strcmp(jw_str(d, d->group[g].layer_name[w]), "x1"),
       "レイヤ名は書込レイヤの名前");
    app_key(8);
    ck(!strcmp(jw_str(d, d->group[g].layer_name[w]), "x"), "  後退で消える");
    ck(!strcmp(jw_str(d, d->group[g].name), "Ab\x88\xea"), "  グループ名はそのまま");

    /* 戻す: greyed until 全レイヤ非表示 has something to take back */
    d->group[g].c = 0;
    d->group[g].layer[2].state = 2;
    d->group[g].layer[2].state2 = 0;
    press(2001);
    ck(d->group[g].layer[2].state == 2, "戻す は初め押せない");
    press(1073);
    ck(d->group[g].layer[2].state == 0, "全レイヤ非表示");
    press(2001);
    ck(d->group[g].layer[2].state == 2, "  戻す で戻る");
    ck(d->group[g].layer[w].state == 3, "  書込レイヤは 3");
    press(1073);
    press(2001);
    press(2001);
    ck(d->group[g].layer[2].state == 2, "  二度目の 戻す は何もしない");

    /* 一括 sets them all to one state */
    d->group[g].layer[2].state = 0;
    d->group[g].layer[3].state = 1;
    press(1141);
    ok = 1;
    for (k = 0; k < 16; k++)
        if (k != w && d->group[g].layer[k].state2 != 2 && d->group[g].layer[k].state != 0)
            ok = 0;
    ck(ok, "一括 はみな同じ状態にする");

    /* 1323, then OK: the group's name is on the status line */
    press(1323);
    press(1);
    ck(!app_layerdlg_open(), "  OK で閉じる");

    ck(jw_write(d, &out, &m) && out, "保存できる");
    if (out && jw_parse(&r, out, m)) {
        ck(!strcmp(jw_str(&r, r.group[g].name), "Ab\x88\xea"), "  グループ名が残る");
        ck(!strcmp(jw_str(&r, r.group[g].layer_name[w]), "x"), "  レイヤ名も残る");
        jw_free(&r);
    } else
        ck(0, "  読み直せる");
    free(out);

    /* the status line's layer box differs with 1323 on and off; the
       check is kept for the next time the dialog comes up, so pressing it
       again there turns it off */
    {
        static unsigned int on[70 * 17];
        const fb_t *fb = app_fb();
        int x, y, diff = 0;

        app_paint();
        for (y = 0; y < 17; y++)
            for (x = 0; x < 70; x++)
                on[y * 70 + x] = fb->px[(size_t)(724 + y) * fb->w + 1084 + x];
        app_command(32808);
        press(1323);                    /* off again */
        press(1);
        app_paint();
        for (y = 0; y < 17; y++)
            for (x = 0; x < 70; x++)
                if (on[y * 70 + x] != fb->px[(size_t)(724 + y) * fb->w + 1084 + x])
                    diff = 1;
        ck(diff, "1323 でステータスのレイヤの箱にグループ名が出る");
    }
    (void)t;
    (void)ok;
}

int main(int argc, char **argv)
{
    const char *pre = argc > 1 ? argv[1] : "tests/out/layerdlg";
    const jw_drawing *d;
    unsigned char *b, *p;
    char path[256];
    long n;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b) {
        printf("BAD  cannot read orig/Test5.jww\n");
        return 1;
    }

    sprintf(path, "%s.png", pre);
    shot(b, n, path, 0, "レイヤ (32808) が出す");
    d = app_drawing();
    ck(d && d->group[0].state == 3, "  書込みグループは 0");
    ck(d && !strcmp(jw_str((jw_drawing *)d, d->group[0].name),
                    "\x88\xea\x94\xca\x90\x7d"), "  グループ名は 一般図");

    sprintf(path, "%s_hidden.png", pre);
    shot(b, n, path, 1, "一括 を一度押すと 非表示");
    sprintf(path, "%s_shown.png", pre);
    shot(b, n, path, 2, "もう一度で 表示のみ");

    /* the empty layer 5 as the write layer */
    p = (unsigned char *)malloc((size_t)n);
    memcpy(p, b, (size_t)n);
    put_l(p + H_GROUP + 4, 5);                  /* group 0's write layer */
    put_l(p + H_LAYER + 8 * 8, 2);              /* layer 8 is not it now */
    put_l(p + H_LAYER + 8 * 5, 3);              /* layer 5 is */
    sprintf(path, "%s_emptywrite.png", pre);
    shot(p, n, path, 0, "何も描かれていないレイヤが書込みレイヤ");
    free(p);

    /* and the empty group 1 as the write group */
    p = (unsigned char *)malloc((size_t)n);
    memcpy(p, b, (size_t)n);
    put_l(p + H_WGROUP, 1);
    put_l(p + H_GROUP, 2);                      /* group 0 is not it now */
    put_l(p + H_GROUP + H_STRIDE, 3);           /* group 1 is */
    sprintf(path, "%s_emptygroup.png", pre);
    shot(p, n, path, 0, "何も描かれていないグループが書込みグループ");
    d = app_drawing();
    ck(d && d->group[1].state == 3, "  書込みグループは 1");
    free(p);

    names(b, n);

    free(b);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
