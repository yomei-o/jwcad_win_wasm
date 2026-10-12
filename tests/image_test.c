/* 画像編集 (33013) -- against the files the original wrote.
 *
 *   tests/image_test.exe
 *
 * decomp/res/img_*.jww are the original's own answers (tools/imgref.sh
 * regenerates them; they are Test: 新規.jww plus one picture, 40x30 pixels,
 * put in and edited the way the name says).  Each case does the same to a new
 * drawing here and holds the picture element it makes against the original's:
 * its text and its numbers.  The files that carry pictures inside them are
 * read and written back byte for byte, and the pictures are decoded from
 * BMP, PNG and JPEG and drawn.
 *
 * The clicks of those runs were pixels of the original's drawing area; P()
 * turns them back into millimetres (0.6122449 a pixel, (400,300) being
 * (-94.2857, 26.3265)).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/draw.h"
#include "../src/image.h"
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

static void P(double px, double py, double *x, double *y)
{
    *x = -94.2857142857 + (px - 400) * 30.0 / 49.0;
    *y = 26.3265306122 - (py - 300) * 30.0 / 49.0;
}

/* the 40 by 30 pattern of tmp/img/t1.bmp */
static unsigned char *mk_bmp(int w, int h, long *n)
{
    long stride = ((long)w * 3 + 3) & ~3L, total = 54 + stride * h;
    unsigned char *b = (unsigned char *)calloc((size_t)total, 1);
    int x, y;

    b[0] = 'B'; b[1] = 'M';
    b[2] = (unsigned char)total; b[3] = (unsigned char)(total >> 8); b[4] = (unsigned char)(total >> 16);
    b[10] = 54; b[14] = 40;
    b[18] = (unsigned char)w; b[19] = (unsigned char)(w >> 8);
    b[22] = (unsigned char)h; b[23] = (unsigned char)(h >> 8);
    b[26] = 1; b[28] = 24;
    for (y = 0; y < h; y++)
        for (x = 0; x < w; x++) {
            unsigned char *p = b + 54 + stride * y + x * 3;
            p[0] = (unsigned char)((x * 6) & 255);
            p[1] = (unsigned char)((y * 8) & 255);
            p[2] = ((x / 5 + y / 5) % 2) ? 128 : 0;
        }
    *n = total;
    return b;
}

static const char *PIC1 = "C:\\prog\\claude2\\jwcad_win_wasm\\tmp\\img\\t1.bmp";
static const char *PIC2 = "C:\\prog\\claude2\\jwcad_win_wasm\\tmp\\img\\s200x100.bmp";

static jw_drawing *fresh(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);

    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        exit(1);
    }
    free(b);
    app_fit();
    jw_cmd_reset();
    jw_img_forget();
    return (jw_drawing *)app_drawing();
}

static void put_pic(const char *path)
{
    long n;
    unsigned char *b = path == PIC2 ? mk_bmp(200, 100, &n) : mk_bmp(40, 30, &n);

    jw_cmd_gazou_insert((jw_drawing *)app_drawing(), path, b, n);
    free(b);
}

static void click(double px, double py)
{
    double x, y;

    P(px, py, &x, &y);
    jw_cmd_point((jw_drawing *)app_drawing(), app_view(), x, y, 0);
}

static void bar(int id)
{
    jw_cmd_bar((jw_drawing *)app_drawing(), id);
}

/* tick a mode (or a tick) if it is not */
static void want(int id, int on)
{
    if ((jw_cmd_bar_check(id) == 1) != on)
        bar(id);
}

/* the n-th picture of a drawing */
static const jw_obj *pic_of(const jw_drawing *d, int nth)
{
    int i;

    for (i = 0; i < d->ndrawn; i++)
        if (jw_is_pic(d, &d->obj[i]) && nth-- == 0)
            return &d->obj[i];
    return 0;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-4;
}

/* the command, in the state a run of the original starts in: 移動, no turn, no 相対パス */
static void enter(void)
{
    app_command(33013);
    if (jw_cmd_bar_check(1346) == 1) {
        want(1345, 1);
        bar(1346);
    }
    want(1337, 1);
    want(1338, 0);
}

static jw_drawing ref;
static jw_obj ghost_buf[16];

/* hold our nth picture against the original's file */
static int same_pic(const char *what, const char *file, int nth)
{
    long n;
    unsigned char *b = slurp(file, &n);
    const jw_drawing *d = app_drawing();
    const jw_obj *a, *r;
    int i, ok;
    char msg[200];

    if (!b) {
        printf("BAD  %s: cannot read %s (tools/imgref.sh)\n", what, file);
        fails++;
        return 0;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", what, ref.error);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    a = pic_of(d, nth);
    r = pic_of(&ref, nth);
    if (!a || !r) {
        snprintf(msg, sizeof msg, "%s: both have a picture (ours %p, theirs %p)", what, (void *)a, (void *)r);
        ck(0, msg);
        return 0;
    }
    {   /* the same words, the numbers to a millionth: the original's own float
           noise (1.06581e-14 for a nought) is not something to copy */
        jw_pic pa, pr;

        jw_pic_parse(d, a, &pa);
        jw_pic_parse(&ref, r, &pr);
        ok = !strcmp(pa.name, pr.name) && pa.nfield == pr.nfield && near(pa.w, pr.w) && near(pa.h, pr.h)
             && near(pa.x, pr.x) && near(pa.y, pr.y) && near(pa.c, pr.c) && near(pa.d, pr.d)
             && pa.r == pr.r && pa.g == pr.g && pa.b == pr.b;
        if (ok && strcmp(jw_str(d, a->text), jw_str(&ref, r->text)) && !strstr(jw_str(&ref, r->text), "e-1"))
            ok = 0;                     /* and the text itself, but for that noise */
    }
    snprintf(msg, sizeof msg, "%s: the text", what);
    ck(ok, msg);
    if (!ok)
        printf("     ours   %s\n     theirs %s\n", jw_str(d, a->text), jw_str(&ref, r->text));
    ok = 1;
    for (i = 0; i < 8; i++) {
        /* the far end of the baseline is as long as the text, so it moves
           with the noise the original puts in a number (1.06581e-14) */
        if ((i == 2 || i == 3) && strstr(jw_str(&ref, r->text), "e-1"))
            continue;
        if (!near(a->d[i], r->d[i]))
            ok = 0;
    }
    snprintf(msg, sizeof msg, "%s: the baseline, the size and the turn", what);
    ck(ok, msg);
    if (!ok) {
        printf("     ours  ");
        for (i = 0; i < 8; i++)
            printf(" %.4f", a->d[i]);
        printf("\n     theirs");
        for (i = 0; i < 8; i++)
            printf(" %.4f", r->d[i]);
        printf("\n");
    }
    ok = a->ltype == r->ltype && a->color == r->color && a->layer == r->layer
         && a->lgroup == r->lgroup && a->flags == r->flags && a->n == r->n;
    snprintf(msg, sizeof msg, "%s: pen, layer and flags", what);
    ck(ok, msg);
    jw_free(&ref);
    return 1;
}


/* The original's picture of its window against ours, over the picture and a
   margin round it.  The shot is the whole window (1280 x 800, an 8 pixel
   frame and 51 rows of caption and menu above the client), ours the
   client: so (8,51) apart. */
/* The clicks that made the original's pictures were pixels of its window, and
   a point on the very edge of a pixel falls on one side or the other by the
   last bit of the arithmetic.  So the pixel check takes the places off the
   original's own file (the number of every picture is the same in both). */
static void adopt(const char *jww)
{
    long n;
    unsigned char *b = slurp(jww, &n);
    jw_drawing r;
    jw_drawing *d = (jw_drawing *)app_drawing();
    int i, k = 0;

    if (!b || !jw_parse(&r, b, n)) {
        free(b);
        return;
    }
    free(b);
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = pic_of(&r, k);

        if (!jw_is_pic(d, &d->obj[i]))
            continue;
        if (o)
            memcpy(d->obj[i].d, o->d, 4 * sizeof o->d[0]);
        k++;
    }
    jw_free(&r);
}

static int shot_diff(const char *what, const char *png, int allow)
{
    long n;
    unsigned char *b = slurp(png, &n);
    jw_img im;
    const fb_t *fb;
    int x, y, x0 = 1 << 20, y0 = 1 << 20, x1 = -1, y1 = -1, bad = 0, tot = 0;
    char msg[200];

    if (!b || !jw_img_decode(b, n, &im)) {
        printf("BAD  %s: cannot read %s\n", what, png);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    {
        char jf[200];
        char *dot;

        snprintf(jf, sizeof jf, "%s", png);
        dot = strrchr(jf, '.');
        strcpy(dot, ".jww");
        adopt(jf);
    }
    app_paint();
    fb = app_fb();
    for (y = 90; y < 760; y++)
        for (x = 90; x < 1180; x++) {
            const unsigned char *q = im.rgb + ((size_t)y * im.w + x) * 3;

            if (q[0] != 255 || q[1] != 255 || q[2] != 255) {
                if (x < x0) x0 = x;
                if (x > x1) x1 = x;
                if (y < y0) y0 = y;
                if (y > y1) y1 = y;
            }
        }
    for (y = y0 - 3; y <= y1 + 3; y++)
        for (x = x0 - 3; x <= x1 + 3; x++) {
            const unsigned char *q = im.rgb + ((size_t)y * im.w + x) * 3;
            unsigned int theirs = (unsigned)q[0] << 16 | (unsigned)q[1] << 8 | q[2];
            unsigned int ours = fb->px[(size_t)(y - 51) * fb->w + (x - 8)] & 0xffffffu;

            tot++;
            if (theirs != ours)
                bad++;
        }
    snprintf(msg, sizeof msg, "%s: the pixels of the picture (%d of %d differ, at most %d)", what, bad, tot, allow);
    ck(bad <= allow, msg);
    if (bad > allow) {      /* where each one's picture is, in the window's own pixels */
        int a0 = 1 << 20, b0 = 1 << 20, a1 = -1, b1 = -1;

        for (y = y0 - 3; y <= y1 + 3; y++)
            for (x = x0 - 3; x <= x1 + 3; x++)
                if ((fb->px[(size_t)(y - 51) * fb->w + (x - 8)] & 0xffffffu) != 0xffffffu) {
                    if (x < a0) a0 = x;
                    if (x > a1) a1 = x;
                    if (y < b0) b0 = y;
                    if (y > b1) b1 = y;
                }
        printf("     theirs %d..%d x %d..%d, ours %d..%d x %d..%d\n", x0, x1, y0, y1, a0, a1, b0, b1);
    }
    jw_img_free(&im);
    return bad;
}

static int pic_count(const jw_drawing *d)
{
    int i, k = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (jw_is_pic(d, &d->obj[i]))
            k++;
    return k;
}

int main(void)
{
    jw_drawing *d;
    long n;
    unsigned char *b;

    app_resize(1264, 741);

    /* ---- the command and its bar ---- */
    d = fresh();
    ck(app_command(33013) && jw_cmd() == JW_CMD_GAZOU, "画像編集 enters the command");
    ck(app_menu_state(33013) == 1, "and the menu item is ticked");
    ck(jw_cmd_bar_check(1337) == 1 && jw_cmd_bar_check(1345) == 0, "it comes up in 移動");
    ck(jw_cmd_bar_enabled(d, 1346) == 0, "回転する sleeps until フィット is ticked");
    ck(!strcmp(jw_cmd_prompt(), "\x88\xda\x93\xae\x82\xb7\x82\xe9\x89\xe6\x91\x9c\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4\x89\xba\x82\xb3\x82\xa2\x81" "B  (L)free  (R)Read"),
       "and asks for the picture to move");
    bar(1345);
    ck(jw_cmd_bar_check(1345) == 1 && jw_cmd_bar_check(1337) == 0 && jw_cmd_bar_enabled(d, 1346) == 1,
       "ticking フィット unticks 移動 and wakes 回転する");
    bar(1345);
    ck(jw_cmd_bar_check(1345) == 1, "ticking the ticked mode again leaves it ticked (they are one of five)");
    bar(2557);
    ck(jw_cmd_gazou_file() == 1 && jw_cmd_gazou_file() == 0, "画像挿入 asks the front end for a file, once");

    /* ---- 挿入 ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    ck(jw_cmd_gazou_inserting() && jw_cmd_bar_enabled(d, 1337) == 0 && jw_cmd_bar_enabled(d, 2559) == 1,
       "a file read: the modes sleep until the 基準点");
    click(400, 300);
    same_pic("画像挿入", "decomp/res/img_ins.jww", 0);
    shot_diff("画像挿入", "decomp/res/img_ins.png", 0);
    ck(pic_count(d) == 1 && jw_cmd_can_undo(), "one picture, and it can be undone");
    jw_cmd_undo(d);
    ck(pic_count(d) == 0, "戻る takes it out");

    /* ---- 移動 ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    click(250, 350);                    /* off the picture: nothing */
    ck(jw_cmd_midway() == 0, "a click off every picture picks nothing");
    click(330, 380);
    ck(jw_cmd_midway() == 1, "a click on it picks it");
    click(500, 200);
    same_pic("移動", "decomp/res/img_move.jww", 0);

    /* ---- トリミング と 解除 ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    bar(1335);
    click(330, 380);
    click(430, 300);
    same_pic("トリミング", "decomp/res/img_trim.jww", 0);
    shot_diff("トリミング", "decomp/res/img_trim.png", 1000);   /* one column short at the right */
    bar(1336);
    click(380, 340);
    same_pic("トリミング解除", "decomp/res/img_untrim.jww", 0);

    {   /* trims of other sizes: which part of the file shows, and the box it is stretched over */
        static const double R[5][4] = { { 320, 390, 450, 290 }, { 305, 395, 325, 385 }, { 310, 300, 460, 395 },
                                        { 350, 360, 400, 320 }, { 301, 399, 462, 279 } };
        int k;
        char nm[80], fn[80];

        for (k = 0; k < 5; k++) {
            d = fresh();
            enter();
            put_pic(PIC1);
            click(300, 400);
            bar(1335);
            click(R[k][0], R[k][1]);
            click(R[k][2], R[k][3]);
            snprintf(fn, sizeof fn, "decomp/res/img_tr%d.jww", k + 1);
            snprintf(nm, sizeof nm, "トリミング %d", k + 1);
            same_pic(nm, fn, 0);
            snprintf(fn, sizeof fn, "decomp/res/img_tr%d.png", k + 1);
            shot_diff(nm, fn, k == 1 ? 60 : 0);   /* the second is a row short at the top */
        }
    }

    /* ---- フィット ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    bar(1345);
    click(330, 380); click(430, 300); click(100, 150); click(300, 50);
    same_pic("画像フィット (X)", "decomp/res/img_fitx.jww", 0);
    shot_diff("画像フィット (X)", "decomp/res/img_fitx.png", 9000);   /* half off the top: the original draws from a pixel or two higher in this window */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    bar(1345);
    click(330, 300); click(380, 390); click(100, 100); click(250, 300);
    same_pic("画像フィット (Y)", "decomp/res/img_fity.jww", 0);
    {
        static const char *RO[3] = { "decomp/res/img_rot1.jww", "decomp/res/img_rot2.jww", "decomp/res/img_rot3.jww" };
        static const double PT[3][4] = { { 200, 200, 300, 300 }, { 300, 200, 200, 200 }, { 300, 300, 200, 400 } };
        int k;
        char nm[60];

        for (k = 0; k < 3; k++) {
            d = fresh();
            enter();
            bar(1345);
            bar(1346);
            put_pic(PIC1);
            click(300, 400);
            click(310, 390); click(410, 390); click(PT[k][0], PT[k][1]); click(PT[k][2], PT[k][3]);
            snprintf(nm, sizeof nm, "画像フィット 回転する %d", k + 1);
            same_pic(nm, RO[k], 0);
            if (k == 0)
                shot_diff(nm, "decomp/res/img_rot1.png", 2500);   /* PlgBlt takes its corners as whole pixels */
        }
    }
    d = fresh();
    enter();
    bar(1345);
    bar(1346);
    put_pic(PIC1);
    click(300, 400);
    click(310, 390); click(410, 390); click(200, 200); click(300, 300);
    bar(1345);
    bar(1335);
    click(250, 200); click(300, 250);
    same_pic("回した画像のトリミング", "decomp/res/img_rtrim.jww", 0);

    /* ---- 透過色, 相対パス ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    bar(1339);
    click(380, 340);
    {
        int r, g, bl;

        ck(jw_cmd_gazou_tp_ask(&r, &g, &bl) && r == 255 && g == 255 && bl == 255,
           "a click on a picture in 透過色設定 asks, with the colour it has");
    }
    jw_cmd_gazou_tp_set(d, 255, 0, 128);
    same_pic("透過色設定", "decomp/res/img_trans.jww", 0);

    d = fresh();
    enter();
    jw_cmd_gazou_doc("C:\\prog\\claude2\\jwcad_win_wasm\\tmp", "rect");
    bar(1338);
    put_pic(PIC1);
    click(300, 400);
    same_pic("相対パス", "decomp/res/img_rel.jww", 0);

    /* ---- 移動 hangs the picture off the cursor ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    click(330, 380);
    {
        double x, y;

        P(510, 260, &x, &y);
        jw_cmd_track(x, y);
        ck(jw_cmd_pending(d, ghost_buf, 16) == 4, "a picked picture shows a ghost: outline, line and two circles");
        shot_diff("移動の仮表示", "decomp/res/img_ghost.png", 1200);   /* the circles' sizes and the cursor's own pixel are guesses */
    }

    /* ---- the pictures lie over the lines, and white lets them show ---- */
    d = fresh();
    jw_cmd_set(JW_CMD_SEN);
    click(250, 340);
    click(500, 340);
    app_command(33013);
    put_pic(PIC1);
    click(300, 400);
    shot_diff("線の上の画像", "decomp/res/img_lines.png", 300);   /* the line is a pixel off in this window */
    jw_img_forget();

    /* ---- 二枚: the one on top is picked ---- */
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    put_pic(PIC2);
    click(350, 420);
    click(400, 380);
    click(600, 300);
    same_pic("二枚のうち上のものを移動 (1)", "decomp/res/img_two.jww", 0);
    same_pic("二枚のうち上のものを移動 (2)", "decomp/res/img_two.jww", 1);

    /* ---- 同梱 ---- */
    b = slurp("decomp/res/img_embed.jww", &n);
    if (b) {
        jw_drawing e;
        unsigned char *out = 0;
        long m = 0;

        jw_img_forget();
        ck(jw_parse(&e, b, n), "a drawing with a picture inside reads");
        ck(jw_write(&e, &out, &m) && m == n && !memcmp(out, b, (size_t)n),
           "and writes back to the same bytes");
        {
            const jw_obj *o = pic_of(&e, 0);
            jw_pic p;
            const jw_img *im;

            ck(o && jw_pic_parse(&e, o, &p) && !strncmp(p.name, "%temp%C__prog_", 14), "its text names %temp%...");
            im = o ? jw_img_get(p.name) : 0;
            ck(im && im->w == 40 && im->h == 30, "and the picture inside it is 40 by 30");
            ck(im && im->rgb[0] == 128 && im->rgb[1] == 8 * 29 && im->rgb[2] == 0, "with the right pixels");
        }
        free(out);
        jw_free(&e);
        free(b);
    } else {
        printf("BAD  cannot read decomp/res/img_embed.jww\n");
        fails++;
    }
    d = fresh();
    enter();
    put_pic(PIC1);
    click(300, 400);
    bar(2559);
    {
        const char *t = 0;

        ck(jw_cmd_gazou_ask(&t) == 1 && t && strstr(t, "\x82\xe6\x82\xeb\x82\xb5\x82\xa2\x82\xc5\x82\xb7\x82\xa9"), "画像同梱 asks first");
        jw_cmd_gazou_answer(d, 1);
        ck(jw_cmd_gazou_ask(&t) == 2 && t && strstr(t, "1\x8c\xc2\x82\xcc\x89\xe6\x91\x9c"), "then says how many went in");
        jw_cmd_gazou_answer(d, 0);
        ck(jw_cmd_gazou_ask(&t) == 0, "and that is all");
    }
    {
        long m = 0, n2 = 0;
        unsigned char *out = 0;
        const unsigned char *g;
        const jw_obj *o = pic_of(d, 0);
        jw_pic p;
        unsigned char *raw = 0;
        long rn = 0;

        ck(o && jw_pic_parse(d, o, &p) &&
           !strcmp(p.name, "%temp%C__prog_claude2_jwcad_win_wasm_tmp_img_t1_bmp.bmp"),
           "同梱 renames the picture the way the original does");
        ck(jw_write(d, &out, &m), "the drawing writes with it inside");
        {
            jw_drawing back;

            jw_img_forget();
            ck(jw_parse(&back, out, m), "and reads again");
            g = jw_img_bytes(p.name, &n2);
            ck(g && n2 == 3654, "with the same 3654 bytes of picture");
            (void)raw; (void)rn;
            jw_free(&back);
        }
        free(out);
    }
    fresh();

    /* ---- 同梱画像分離 ---- */
    b = slurp("decomp/res/img_sep.jww", &n);
    {
        jw_drawing *dd = fresh();
        long m;
        unsigned char *e = slurp("decomp/res/img_embed.jww", &m);
        const char *t = 0, *nm = 0;
        const unsigned char *ob = 0;
        long on = 0;

        ck(e && app_open(e, m), "a drawing with a picture inside opens");
        free(e);
        dd = (jw_drawing *)app_drawing();
        jw_cmd_reset();
        enter();
        bar(2561);
        jw_cmd_gazou_doc("", "");
        bar(2561);
        ck(jw_cmd_gazou_ask(&t) == 2, "画像分離 on a drawing with no name says to save it first");
        jw_cmd_gazou_answer(dd, 0);
        jw_cmd_gazou_doc("C:\\prog\\claude2\\jwcad_win_wasm\\tmp", "rect");
        bar(2561);
        ck(jw_cmd_gazou_ask(&t) == 1 && t && strstr(t, "C:\\prog\\claude2\\jwcad_win_wasm\\tmp\\rect"), "画像分離 asks, naming the folder");
        jw_cmd_gazou_answer(dd, 1);
        ck(jw_cmd_gazou_ask(&t) == 2 && t && strstr(t, "1\x8c\xc2\x82\xcc\x89\xe6\x91\x9c"), "and says how many went out");
        jw_cmd_gazou_answer(dd, 0);
        ck(jw_cmd_gazou_out(0, &nm, &ob, &on) && on == 3654 && !strcmp(nm, "C__prog_claude2_jwcad_win_wasm_tmp_img_t1_bmp.bmp"),
           "the picture is handed over to be put in the folder");
        if (b) {
            jw_drawing r2;

            if (jw_parse(&r2, b, n)) {
                const jw_obj *o = pic_of(&r2, 0), *a = pic_of(dd, 0);

                ck(o && a && !strcmp(jw_str(&r2, o->text), jw_str(dd, a->text)),
                   "and the text names the folder as the original's does");
                if (o && a && strcmp(jw_str(&r2, o->text), jw_str(dd, a->text)))
                    printf("     ours   %s\n     theirs %s\n", jw_str(dd, a->text), jw_str(&r2, o->text));
                jw_free(&r2);
            }
        } else {
            printf("BAD  cannot read decomp/res/img_sep.jww\n");
            fails++;
        }
    }
    free(b);

    /* ---- the decoders: python tools/mkimgs.py makes the files and what Pillow reads in them ---- */
    {
        static const char *F[] = { "rgb24.bmp", "pal8.bmp", "mono.bmp", "rgb.png", "pal.png", "grayp.png",
                                   "rgba.png", "q95.jpg", "q80_420.jpg", "q80_422.jpg", "prog.jpg", "gray.jpg" };
        int k;

        for (k = 0; k < (int)(sizeof F / sizeof F[0]); k++) {
            char path[100], rgbp[100], msg[160];
            long fn, rn;
            unsigned char *fb, *rb;
            jw_img im;
            char *dot;

            snprintf(path, sizeof path, "tmp/img/dec_%s", F[k]);
            strcpy(rgbp, path);
            dot = strrchr(rgbp, '.');
            strcpy(dot, ".rgb");
            fb = slurp(path, &fn);
            rb = slurp(rgbp, &rn);
            if (!fb || !rb) {
                printf("skip %s (python tools/mkimgs.py)\n", path);
                free(fb);
                free(rb);
                continue;
            }
            if (jw_img_decode(fb, fn, &im)) {
                long i, tot = 0, mx = 0, cnt = (long)im.w * im.h * 3;
                int same = im.w == rb[0] + rb[1] * 256 && im.h == rb[2] + rb[3] * 256;

                for (i = 0; same && i < cnt; i++) {
                    long df = labs((long)im.rgb[i] - rb[4 + i]);

                    tot += df;
                    if (df > mx)
                        mx = df;
                }
                if (strstr(F[k], ".jpg")) {   /* a different IDCT and chroma upsampling */
                    snprintf(msg, sizeof msg, "%s decodes (mean error %.2f, worst %ld)", F[k],
                             same ? (double)tot / cnt : -1.0, mx);
                    ck(same && (double)tot / cnt < 4.0, msg);
                } else {
                    snprintf(msg, sizeof msg, "%s decodes exactly", F[k]);
                    ck(same && mx == 0, msg);
                }
                jw_img_free(&im);
            } else {
                snprintf(msg, sizeof msg, "%s decodes", F[k]);
                ck(0, msg);
            }
            free(fb);
            free(rb);
        }
    }
    {   /* gzip: what is written is read by anyone's inflate, and by ours */
        unsigned char data[5000], *g = 0, *u = 0;
        long gn = 0, un = 0, i;

        for (i = 0; i < (long)sizeof data; i++)
            data[i] = (unsigned char)((i * 7) ^ (i / 13));
        ck(jw_gzip(data, sizeof data, &g, &gn) && gn > 18 && jw_gunzip(g, gn, &u, &un) && un == (long)sizeof data
           && !memcmp(u, data, sizeof data), "gzip and back");
        free(g);
        free(u);
    }

    printf("\n%s\n", fails ? "SOME BAD" : "all ok");
    return fails != 0;
}
