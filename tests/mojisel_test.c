/* 文字の 範囲選択 (2407): 文書, 外部エディタ / 貼付 and SJIS/UTF8 as functions of
 * the picked texts (tmp/spec_gaibu/B_moji_hani.md). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
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

static void pick_all(void)
{
    const fb_t *fb = app_fb();
    rect_t r;

    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);   /* (R): texts too */
}

static int load(void)
{
    long n;
    unsigned char *b = slurp("orig/Test5.jww", &n);
    int ok = b && app_open(b, n);

    free(b);
    return ok;
}

static int texts(const jw_drawing *d)
{
    int i, k = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI)
            k++;
    return k;
}

static int lines(const unsigned char *b, long n)
{
    long i;
    int k = 0;

    for (i = 0; i < n; i++)
        if (b[i] == '\n')
            k++;
    return k;
}

int main(void)
{
    unsigned char *o = 0, *o8 = 0;
    long on = 0, o8n = 0;
    int k, t0, r;
    jw_drawing *d;

    app_resize(1264, 741);
    ck(load(), "Test5 opens");
    d = app_drawing();
    t0 = texts(d);
    pick_all();
    k = jw_cmd_moji_count(d);
    ck(k > 0 && k <= t0, "texts are picked");

    ck(jw_moji_sjis() == 1, "SJIS is the default");
    ck(jw_cmd_moji_edit_text(d, &o, &on) && lines(o, on) == k, "SJIS: one line a text");
    ck(on >= 2 && o[on - 2] == '\r' && o[on - 1] == '\n', "  CRLF");
    ck(jw_moji_sjis_toggle() == 0 && jw_moji_sjis() == 0, "1092 switches to UTF8");
    ck(jw_cmd_moji_edit_text(d, &o8, &o8n) && lines(o8, o8n) == k, "UTF8: one line a text");
    ck(o8[0] == 0xef && o8[1] == 0xbb && o8[2] == 0xbf, "  with a BOM");

    /* handed back unchanged, in either coding, nothing changes */
    ck(jw_cmd_moji_apply(d, o8, o8n) == k && texts(d) == t0, "UTF8 file back unchanged: same texts");
    pick_all();
    jw_moji_sjis_set(1);
    ck(jw_cmd_moji_apply(d, o, on) == k && texts(d) == t0, "SJIS file back unchanged: same texts");

    /* edited: first line changed, second emptied, one line added */
    {
        const char *edit = "ABC\r\n\r\nxyz\r\n";
        unsigned char *e, *o2 = 0;
        long en, o2n = 0, i, nl = 0;
        const unsigned char *p = o;

        /* keep lines 3..k as they were */
        for (i = 0; i < on && nl < 2; i++)
            if (o[i] == '\n')
                nl++;
        en = (long)strlen(edit) - 5 + (on - i) + 5;
        e = (unsigned char *)malloc((size_t)(strlen(edit) + (size_t)on + 16));
        memcpy(e, edit, 7);
        memcpy(e + 7, o + i, (size_t)(on - i));
        memcpy(e + 7 + (on - i), "xyz\r\n", 5);
        en = 7 + (on - i) + 5;
        (void)p;
        pick_all();
        r = jw_cmd_moji_apply(d, e, en);
        ck(r == (k - 1) + 1 + 1, "edit: changed + erased + new");
        if (r != k + 1)
            printf("     r=%d k=%d\n", r, k);
        ck(texts(d) == t0, "  one erased, one made: same number");
        pick_all();
        ck(jw_cmd_moji_edit_text(d, &o2, &o2n) && lines(o2, o2n) == k, "  and they list again");
        ck(strstr((char *)o2, "ABC") != 0 && strstr((char *)o2, "xyz") != 0, "  with the new words");
        free(o2);
        free(e);
    }
    /* undo takes it all back in one step */
    jw_cmd_undo(d);
    ck(texts(d) == t0, "元に戻す: back to the original count");

    pick_all();
    {
        unsigned char *doc = 0;
        long dn = 0;

        ck(jw_cmd_moji_doc(d, &doc, &dn) && dn > 0, "文書 writes the file");
        ck(jw_cmd_moji_count(d) == 0, "  and lets the picking go");
        free(doc);
    }
    free(o);
    free(o8);

    /* the walk: 文字, 範囲選択 (2407), a box, Enter */
    {
        const fb_t *fb = app_fb();
        rect_t rc;

        ui_view_rect(fb->w, fb->h, &rc);
        jw_cmd_set(JW_CMD_MOJI);
        ck(jw_cmd_bar_enabled(d, 1070) <= 0, "nothing picked: 文書 is not there");
        ck(jw_cmd_bar(d, 2407) && jw_cmd() == JW_CMD_HANI, "2407 enters the range selection");
        ck(strstr(jw_cmd_prompt(), "�y�����z") != 0, "  with the 【文字】 prompt (5429)");
        app_press(rc.x + 100, rc.y + 100, 0);
        app_press(rc.x + rc.w - 4, rc.y + rc.h - 4, 1);
        ck(app_key(13) && jw_cmd() == JW_CMD_MOJI, "Enter settles it and goes back to 文字");
        ck(jw_cmd_moji_ready() && jw_cmd_moji_count(d) > 0, "  texts picked");
        ck(jw_cmd_sel_count(d) == jw_cmd_moji_count(d), "  and nothing but texts");
        ck(jw_cmd_bar_enabled(d, 1070) == 1 && jw_cmd_bar_enabled(d, 1065) == 1
           && jw_cmd_bar_label(1069) && !strcmp(jw_cmd_bar_label(1069), "SJIS"), "  貼付 and 文書 are there, 文読 gives way to the SJIS/UTF8 switch");
        app_press(rc.x + 300, rc.y + 300, 0);
        ck(!jw_cmd_moji_ready() && jw_cmd_sel_count(d) == 0, "a click on the drawing lets them go");
        jw_cmd_set(JW_CMD_MOJI);
        ck(jw_cmd_bar(d, 1067) && jw_cmd() == JW_CMD_HANI, "外部エディタ with nothing picked asks for a range");
        app_press(rc.x + 100, rc.y + 100, 0);
        app_press(rc.x + rc.w - 4, rc.y + rc.h - 4, 1);
        app_key(13);
        ck(app_take_action() == JW_ACT_MOJI_EDIT, "  and goes on once it is settled");
    }
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
