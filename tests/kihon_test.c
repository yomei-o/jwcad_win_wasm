/* 基本設定 -- the dialog, against the original's own.
 *
 *   tests/kihon_test.exe tests/out/kihon.png
 *
 * docs/ref_kihon1.png .. 8.png are that dialog painted into bitmaps by
 * Jw_cad itself, one per tab (tools/jwdraw.ps1's dlgat: step, which clicks
 * the strip before it reads the dialog -- the original does not build a
 * tab's controls until it is shown).  This walks the port's through the
 * same eight and writes each one out to be scored against its picture;
 * tools/check.sh does the scoring, with the text and the tab strip left out
 * of it.
 *
 * What the boxes mean has not been worked out, so pressing one only makes
 * it go down or up, and OK and キャンセル both just close the dialog.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/kihon.h"
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

/* the middle of one of the showing tab's controls, in client pixels */
static void ctl(int tab, int id, int *x, int *y)
{
    rect_t r;
    const jw_kh_t *c = jw_kihon_tabs[tab].c;
    int i;

    ui_kihon_rect(1264, 741, &r);
    for (i = 0; i < jw_kihon_tabs[tab].n; i++)
        if (c[i].id == id) {
            *x = r.x + JW_KH_BORDER + c[i].x + c[i].w / 2;
            *y = r.y + JW_KH_CAPTION + c[i].y + c[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* what the box shows: the nth one with that id in the tab */
static const char *box(int tab, int id, int nth)
{
    int i;

    for (i = 0; i < jw_kihon_tabs[tab].n; i++)
        if (jw_kihon_tabs[tab].c[i].id == id
            && (jw_kihon_tabs[tab].c[i].kind == JW_KH_EDIT
                || jw_kihon_tabs[tab].c[i].kind == JW_KH_COMBO)
            && nth-- == 0)
            return app_kihon_text(tab, i, 0, 0);
    return 0;
}

static int is(const char *a, const char *b)
{
    return a && !strcmp(a, b);
}

static void type(const char *t)
{
    while (*t)
        app_key((unsigned char)*t++);
}

/* the middle of one of the tabs */
static void tab_at(int t, int *x, int *y)
{
    rect_t r;

    ui_kihon_rect(1264, 741, &r);
    *x = r.x + JW_KH_BORDER + JW_KH_TAB_X
         + (jw_kihon_tab_at[t] + jw_kihon_tab_at[t + 1]) / 2;
    *y = r.y + JW_KH_CAPTION + JW_KH_TAB_Y + JW_KH_TAB_ROW / 2;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j, t;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    ck(!app_kihon_open(), "the dialog is not up to start with");
    ck(app_command(32891), "基本設定 puts it up");
    ck(app_kihon_open(), "which says so");
    ck(ui_kihon_ntabs() == 8, "it has eight tabs");

    /* one picture per tab */
    for (t = 0; t < ui_kihon_ntabs(); t++) {
        if (t) {
            tab_at(t, &x, &y);
            app_press(x, y, 0);
        }
        ck(app_kihon_tab() == t, "  the tab that was pressed is showing");
        app_paint();
        if (argc > 1) {
            unsigned int *px;
            char path[256];
            const char *dot = strrchr(argv[1], '.');
            int len = dot ? (int)(dot - argv[1]) : (int)strlen(argv[1]);

            sprintf(path, "%.*s%d%s", len, argv[1], t + 1, dot ? dot : "");
            ui_kihon_rect(fb->w, fb->h, &r);
            px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
            if (px) {
                for (j = 0; j < r.h; j++)
                    for (i = 0; i < r.w; i++)
                        px[j * r.w + i] =
                            fb->px[(size_t)(r.y + j) * fb->w + r.x + i];
                png_rgb(path, r.w, r.h, px);
                free(px);
                printf("     wrote %s\n", path);
            }
        }
    }

    /* a box goes down and comes up again */
    tab_at(0, &x, &y);
    app_press(x, y, 0);
    for (i = 0; i < jw_kihon_tabs[0].n; i++)
        if (jw_kihon_tabs[0].c[i].id == 2860)   /* 透過属性, starts ticked */
            break;
    ck(i < jw_kihon_tabs[0].n, "透過属性 is one of the boxes");
    ctl(0, 2860, &x, &y);
    app_press(x, y, 0);
    app_paint();
    ck(1, "and pressing it does not fall over");
    app_press(x, y, 0);

    ctl(0, 2, &x, &y);                  /* キャンセル */
    app_press(x, y, 0);
    ck(!app_kihon_open(), "キャンセル takes it down");

    /* ------------------------------------- 箱の字: 原典の既定 --------
       src/gen/kihonval.h（tools/mkkihonval.py、レジストリの控えから）と、
       図面の持ち物（色・画面 のペン、文字 の文字種）は図面から */
    {
        const jw_drawing *dw = app_drawing();
        char want[32];

        ck(app_command(32891), "基本設定 をもう一度");
        ck(is(box(0, 1052, 0), "C:\\WINDOWS\\NOTEPAD.EXE"), "外部エディタ");
        ck(is(box(0, 1788, 0), "246"), "画面横寸法 246（Screen\\SizeX）");
        ck(is(box(0, 1934, 0), "100"), "Undo の回数 100");
        ck(is(box(1, 1953, 0), "900"), "マークジャンプ 900");
        ck(is(box(3, 1001, 1), "-  --  --  --  --  --  --  --  -"),
           "線種 2 の型 99999999");
        ck(is(box(3, 1001, 9), "'',,'',,','',,',','',,'',,',',',"),
           "ランダム線 1 の型 ccb2b32a");
        ck(is(box(3, 1777, 0), "4"), "線種 2 の 1パターン 4");
        ck(is(box(5, 2364, 0), "5") && is(box(5, 2393, 0), "-83"),
           "AUTO の 左AM 0時 5・右PM 7時 -83");
        ck(is(box(6, 2004, 0), "5") && is(box(6, 2042, 0), "155")
           && is(box(6, 2064, 0), "76"), "KEY の A 5・Shift+E 155・スペース 76");
        ck(is(box(7, 2443, 0), "15") && is(box(7, 2323, 0), "7")
           && is(box(7, 2315, 0), "dotted"), "SXF の 15・7 dotted");
        ck(is(box(4, 1001, 2), "XY"), "Alt は XY");
        sprintf(want, "%u", (dw->pen_rgb[1] >> 16) & 255u);
        ck(is(box(2, 1571, 0), want), "線色 1 の 赤 は図面のペン");
        ck(is(box(2, 1571, 0), "0") && is(box(2, 1572, 0), "192")
           && is(box(2, 1573, 0), "192"), "  写しの 0 192 192");
        ck(is(box(2, 1640, 0), "255") && is(box(2, 1644, 0), "0"),
           "  仮表示色 255 0 0");
        sprintf(want, "%g", dw->style[1].w);
        ck(is(box(4, 2471, 0), want), "文字種 2 の 横 は図面の文字種");

        /* typing: the first key replaces, OK keeps it */
        ctl(0, 1788, &x, &y);
        app_press(x, y, 0);
        type("300");
        ck(is(box(0, 1788, 0), "300"), "画面横寸法 に 300 と打つ");
        tab_at(2, &x, &y);
        app_press(x, y, 0);
        ctl(2, 1572, &x, &y);
        app_press(x, y, 0);
        type("100");
        tab_at(4, &x, &y);
        app_press(x, y, 0);
        ctl(4, 2470, &x, &y);
        app_press(x, y, 0);
        type("3.5");
        app_key(8);
        type("75");
        ck(is(box(4, 2470, 0), "3.75"), "  一字消して打ち足す");
        ctl(4, 1, &x, &y);              /* OK */
        app_press(x, y, 0);
        ck(!app_kihon_open(), "OK で閉じる");
        ck(((dw->pen_rgb[1] >> 8) & 255u) == 100, "  線色 1 の 緑 が図面に 100");
        ck(dw->style[0].w == 3.75, "  文字種 1 の 横 が図面に 3.75");
        app_command(32891);
        ck(is(box(0, 1788, 0), "300"), "  開き直しても 300");
        ck(is(box(2, 1572, 0), "100"), "  緑 も 100");
        /* キャンセル drops it */
        ctl(0, 1788, &x, &y);
        app_press(x, y, 0);
        type("1");
        ctl(0, 2, &x, &y);
        app_press(x, y, 0);
        app_command(32891);
        ck(is(box(0, 1788, 0), "300"), "キャンセル なら打ったものは捨てる");
        /* Enter is OK */
        ctl(0, 1049, &x, &y);
        app_press(x, y, 0);
        type("15");
        app_key(13);
        ck(!app_kihon_open(), "Enter は OK");
        app_command(32891);
        ck(is(box(0, 1049, 0), "15"), "  オートセーブ 15 が残る");
        /* a number out of range leaves the drawing's value alone */
        tab_at(2, &x, &y);
        app_press(x, y, 0);
        ctl(2, 1572, &x, &y);
        app_press(x, y, 0);
        type("300");
        ctl(2, 1, &x, &y);
        app_press(x, y, 0);
        ck(((dw->pen_rgb[1] >> 8) & 255u) == 100, "  256 以上の色は入らない");
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
