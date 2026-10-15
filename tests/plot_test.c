/* 印刷 -- the PDF and the PNG, against the PDF the original printed.
 *
 *   tests/plot_test.exe [tests/out/plot.pdf tests/out/plot.png]
 *
 * decomp/res/print_small.txt is what came out of the original when it was
 * made to print (tools/probe29.sh .. probe33.sh): ファイル > 印刷 puts up
 * the Windows printer dialog, OK takes it into a print mode whose bar has
 * 印刷 (L) on 1065, and the printer here is Microsoft Print To PDF, so
 * what it wrote is a PDF that can be read.
 *
 * The drawing was a new A-2 sheet with one line on it, from
 * (-33.0612,-4.2857) to (28.1633,-34.8980) in sheet millimetres, and the
 * printer's page was A4, 210 x 297.  What the original put on that page:
 *
 *     0.750000 0 0 -0.750000 0 841.920044 cm   96 dpi, y downwards
 *     0 0 0 RG        black
 *     1 J  1 j        round caps, round joins
 *     0.640 w         the width
 *     271.839996 577.440002 m  503.200012 693.119995 l  S
 *
 * and four things come out of those numbers, which this checks first:
 *
 *   one to one   the line is 231.36 by 115.68 units at 96 dpi, which is
 *                61.2245 by 30.6122 mm -- the length it has on the sheet
 *   centred      its start is 71.92, 152.76 mm from the top left of the
 *                page, and the page's middle is 105, 148.5: the sheet's
 *                own (-33.0612, -4.2857) with y the other way up
 *   the width    0.640 units at 96 dpi is 0.1693 mm, and the drawing's
 *                print_width for that pen is 2: 2/300 of an inch
 *   black        カラー印刷 is off as the print bar comes up
 *
 * Then the port is made to print the same line and held to the same four.
 * Its page is the sheet rather than a printer's paper -- there is no
 * printer to ask -- so what is compared is the place on the page relative
 * to the middle, which is what the original's own numbers fix.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/plot.h"
#include "../src/view.h"

static int fails;

/* The printer's dot: the original writes every coordinate as a whole
   multiple of a six hundredth of an inch (src/plot.c's DOT_PT). */
static int on_dot(double v)
{
    double k = v / (72.0 / 600.0);

    return fabs(k - (double)(long)(k + (k < 0 ? -0.5 : 0.5))) < 1e-3;
}

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cknear(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.4f / %.4f)\n", ok ? "ok" : "BAD", what, got, want);
    if (!ok)
        fails++;
}

/* what the original printed, read off decomp/res/print_small.txt */
#define O_X0   271.839996           /* device units, 96 dpi, y downwards */
#define O_Y0   577.440002
#define O_X1   503.200012
#define O_Y1   693.119995
#define O_W      0.640              /* the line width, same units */
#define O_PAGE_W 595.32001          /* the page, in points */
#define O_PAGE_H 841.92004
#define SHEET_X0 (-33.0612)         /* the line, in sheet millimetres */
#define SHEET_Y0  (-4.2857)
#define SHEET_X1  28.1633
#define SHEET_Y1 (-34.8980)

/* find "<x> <y> m" and "<x> <y> l" in a content stream */
static int two_points(const char *s, double *x0, double *y0,
                      double *x1, double *y1)
{
    const char *m = strstr(s, " m ");
    const char *l;
    const char *p;

    if (!m)
        return 0;
    for (p = m; p > s && p[-1] != '\n'; p--)
        ;
    if (sscanf(p, "%lf %lf m %lf %lf l", x0, y0, x1, y1) == 4)
        return 1;
    l = strstr(m, " l");
    return l && sscanf(p, "%lf %lf", x0, y0) == 2
        && sscanf(m + 3, "%lf %lf", x1, y1) == 2;
}

/* the first line of a PDF, in millimetres from the page's middle */
static int pdf_line(const jw_drawing *d, const jw_plot_frame *f, double mm2pt,
                    double *x0, double *y0, double *x1, double *y1)
{
    double wide, tall;
    long n = 0;
    unsigned char *b = jw_plot_pdf_at(d, f, &n);
    char *t;
    int ok;

    if (!b)
        return 0;
    t = (char *)malloc((size_t)n + 1);
    memcpy(t, b, (size_t)n);
    t[n] = 0;
    ok = two_points(t, x0, y0, x1, y1);
    free(t);
    free(b);
    jw_plot_paper(d, &wide, &tall);
    *x0 = *x0 / mm2pt - wide / 2.0;
    *x1 = *x1 / mm2pt - wide / 2.0;
    *y0 = *y0 / mm2pt - tall / 2.0;
    *y1 = *y1 / mm2pt - tall / 2.0;
    return ok;
}

static void frame_is(jw_drawing *d, double x0, double y0, double x1, double y1,
                     const char *what)
{
    jw_obj o[JW_CMD_MAXFIG];
    int n = jw_cmd_pending(d, o, JW_CMD_MAXFIG);
    char buf[160];

    ck(n == 4, what);
    if (n != 4)
        return;
    snprintf(buf, sizeof buf, "  枠 (%.0f,%.0f)-(%.0f,%.0f)", x0, y0, x1, y1);
    ck(fabs(o[0].d[0] - x0) < 1e-9 && fabs(o[0].d[1] - y0) < 1e-9
       && fabs(o[0].d[2] - x1) < 1e-9 && fabs(o[1].d[3] - y1) < 1e-9
       && fabs(o[3].d[2] - x0) < 1e-9 && fabs(o[3].d[3] - y0) < 1e-9, buf);
    if (!(fabs(o[0].d[0] - x0) < 1e-9 && fabs(o[1].d[3] - y1) < 1e-9))
        printf("     (%.3f,%.3f)-(%.3f,%.3f)\n", o[0].d[0], o[0].d[1],
               o[0].d[2], o[1].d[3]);
}

/* 印刷の命令（印刷範囲を設定 0x8053、CZukeiPrintHanni）。逆コンパイルの読み
   （src/plot.h の注）どおりに動くか。原典では押していない */
static void print_command(double mm2pt)
{
    const double DOT = 25.4 / 600.0;
    jw_drawing *d;
    jw_plot_frame f;
    double x0, y0, x1, y1;
    int n0;

    jw_pr_reset();
    app_new();
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);

        o->color = 2;
        o->ltype = 1;
        o->d[0] = 10.0;
        o->d[1] = 0.0;
        o->d[2] = 20.0;
        o->d[3] = 0.0;
    }

    /* 刷り方: 枠の中心が紙の中心、倍率、回転は ９０° で −π/2 */
    memset(&f, 0, sizeof f);
    f.cx = 10.0;
    f.scale = 2.0;
    ck(pdf_line(d, &f, mm2pt, &x0, &y0, &x1, &y1), "印刷: 枠の中心 (10,0)・倍率 2 で刷れる");
    cknear(x0, 0.0, DOT, "  線の始まりは紙の中心");
    cknear(x1, 20.0, DOT, "  長さは倍率 2 で 20");
    cknear(y1, 0.0, DOT, "  y はそのまま");
    f.rot = 1;
    ck(pdf_line(d, &f, mm2pt, &x0, &y0, &x1, &y1), "印刷: ９０°回転");
    cknear(x1, 0.0, DOT, "  ９０° は −π/2 回す: 右向きの線が下向きに（x）");
    cknear(y1, -20.0, DOT, "  （y）");
    f.rot = 2;
    ck(pdf_line(d, &f, mm2pt, &x0, &y0, &x1, &y1), "印刷: －９０°回転");
    cknear(y1, 20.0, DOT, "  －９０° は +π/2: 上向きに");
    f.rot = 0;
    f.scale = 1.0;
    f.cx = 0.0;
    ck(pdf_line(d, &f, mm2pt, &x0, &y0, &x1, &y1) && fabs(x0 - 10.0) <= DOT,
       "印刷: 素の枠は今までどおり用紙そのまま");

    /* 命令に入る */
    app_command(57607);
    ck(jw_cmd() == JW_PRINT_CMD, "印刷 (57607) で 印刷範囲を設定 (0x8053) に入る");
    ck(strcmp(jw_cmd_prompt(),
              "\x88\xf3\x8d\xfc\x94\xcd\x88\xcd\x82\xf0\x8am\x94" "F\x82\xb5\x82\xc4"
              "\x82\xad\x82\xbe\x82\xb3\x82\xa2\x81" "B(L)\x88\xf3\x8d\xfc (R)\x95\xcf\x8dX") == 0,
       "  「印刷範囲を確認してください。(L)印刷 (R)変更」（5334）");
    ck(app_take_action() == JW_ACT_NONE, "  入っただけでは刷らない");
    /* A-2 は 594 x 420: 半分は 297 と 210 */
    frame_is(d, -297, -210, 297, 210, "  枠は用紙（倍率 100%）");
    ck(jw_cmd_box(1411) && jw_pr_scale_of(jw_cmd_box(1411)) == 1.0,
       "  倍率の箱は 100% (A4→A4,A3→A3)");
    ck(strcmp(jw_cmd_bar_label(1066), "\x8d\xb6\x81" "E\x89\xba") == 0,
       "  基準点は 左・下");
    ck(strcmp(jw_cmd_bar_label(1070), "\x89\xf1\x93] \x81@\x82O\x81\x8b") == 0,
       "  回転は「回転 　０°」");
    ck(jw_cmd_bar_enabled(d, 1067) == 0 && jw_cmd_bar_enabled(d, 1069) == 0
       && jw_cmd_bar_enabled(d, 1065) != 0,
       "  プリンタの設定・出力方法設定 は押せない（窓が無い）、印刷 (L) は押せる");

    /* 回転 */
    jw_cmd_bar(d, 1070);
    ck(strcmp(jw_cmd_bar_label(1070), "\x82X\x82O\x81\x8b\x89\xf1\x93]") == 0,
       "回転: 押すと「９０°回転」");
    frame_is(d, -210, -297, 210, 297, "  枠の縦横が入れ替わる");
    jw_cmd_bar(d, 1070);
    ck(strcmp(jw_cmd_bar_label(1070), "\x81|\x82X\x82O\x81\x8b\x89\xf1\x93]") == 0,
       "  もう一度で「－９０°回転」");
    jw_cmd_bar(d, 1070);
    ck(strcmp(jw_cmd_bar_label(1070), "\x89\xf1\x93] \x81@\x82O\x81\x8b") == 0,
       "  三度目で ０° に戻る");

    /* 倍率 */
    jw_cmd_box_put(1411, " 50% (A2\x81\xa8" "A4,A1\x81\xa8" "A3)");
    frame_is(d, -594, -420, 594, 420, "倍率 50%: 枠は倍の大きさ");
    jw_cmd_box_put(1411, "141% (A4\x81\xa8" "A3,A3\x81\xa8" "A2)");
    /* (int)(297 / 1.41421356) = 210, (int)(210 / 1.41421356) = 148 */
    frame_is(d, -210, -148, 210, 148, "倍率 141%: 半分は 297/√2・210/√2 を整数に切ったもの");
    jw_cmd_box_put(1411, "30");
    jw_pr_settings(&f);
    cknear(f.scale, 0.3, 1e-12, "打ち込んだ数は % の任意倍率");
    jw_cmd_box_put(1411, "100% (A4\x81\xa8" "A4,A3\x81\xa8" "A3)");

    /* (R) 変更 → 枠がマウスに付く → (L) で決める */
    jw_cmd_point(d, 0, 5.0, 5.0, 1);
    ck(jw_pr_stage() == 1
       && strcmp(jw_cmd_prompt(),
                 "\x88\xf3\x8d\xfc\x94\xcd\x88\xcd\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4"
                 "\x82\xad\x82\xbe\x82\xb3\x82\xa2\x81" "B(L)free (R)Read") == 0,
       "(R) で「印刷範囲を指示してください。(L)free (R)Read」（5335）");
    frame_is(d, -297, -210, 297, 210, "  枠はマウスが動くまでそのまま");
    jw_cmd_track(100.0, 50.0);
    frame_is(d, 100, 50, 694, 470, "  左・下 がマウスに付いて動く");
    jw_cmd_bar(d, 1066);
    ck(strcmp(jw_cmd_bar_label(1066), "\x92\x86\x81" "E\x89\xba") == 0,
       "  基準点を押すと 中・下");
    frame_is(d, -197, 50, 397, 470, "  中・下 がマウスに付く");
    jw_cmd_point(d, 0, 100.0, 50.0, 0);
    ck(jw_pr_stage() == 0, "  (L) で決まって 確認 に戻る");
    ck(app_take_action() == JW_ACT_NONE, "  決めるだけでは刷らない");
    frame_is(d, -197, 50, 397, 470, "  枠はそこに止まる");
    jw_pr_settings(&f);
    cknear(f.cx, 100.0, 1e-9, "  中心 x");
    cknear(f.cy, 260.0, 1e-9, "  中心 y");

    /* 戻る・Esc は 指示 から 確認 へ */
    jw_cmd_bar(d, 1064);
    ck(jw_pr_stage() == 1, "範囲変更 (R) (1064) で 指示 へ");
    ck(jw_cmd_back(d) == 1 && jw_pr_stage() == 0, "  戻る で 確認 へ（枠は動かない）");
    frame_is(d, -197, 50, 397, 470, "  枠はもとのまま");

    /* 枠書込 */
    n0 = d->ndrawn;
    jw_cmd_bar(d, 1068);
    ck(d->ndrawn == n0 + 4, "枠書込 (1068) で 四本の線が図面に");
    if (d->ndrawn == n0 + 4)
        ck(d->obj[n0].cls == JW_SEN && fabs(d->obj[n0].d[0] + 197.0) < 1e-9
           && fabs(d->obj[n0 + 2].d[1] - 470.0) < 1e-9,
           "  枠の線（左下から 右下・右上・左上）");
    jw_cmd_undo(d);
    ck(d->ndrawn == n0, "  戻るで消える");

    /* カラー印刷 と 刷る */
    jw_cmd_bar(d, 1343);
    ck(jw_cmd_bar_check(1343) > 0, "カラー印刷 (1343) が入る");
    jw_cmd_point(d, 0, 0.0, 0.0, 0);
    ck(app_take_action() == JW_ACT_PLOT, "確認 で (L) すると 刷る");
    ck(app_take_action() == JW_ACT_NONE, "  一度だけ");
    jw_pr_settings(&f);
    ck(f.colour == 1 && f.rot == 0 && f.scale == 1.0, "  刷る設定にカラー印刷");
    jw_cmd_bar(d, 1065);
    ck(app_take_action() == JW_ACT_PLOT, "印刷 (L) (1065) でも刷る");
    jw_cmd_bar(d, 1064);
    jw_cmd_bar(d, 1065);
    ck(app_take_action() == JW_ACT_NONE, "  指示 の段では 1065 は刷らない（slot 26）");
    jw_cmd_escape();
    ck(jw_pr_stage() == 0, "  Esc で 確認 へ");
    jw_cmd_bar(d, 1343);
    jw_cmd_set(JW_CMD_SEN);
    jw_pr_reset();
}

int main(int argc, char **argv)
{
    const double u2mm = 25.4 / 96.0;    /* the original's device units */
    const double mm2pt = 72.0 / 25.4;
    jw_drawing *d;
    unsigned char *pdf, *png;
    long plen, glen;
    double wide, tall, x0, y0, x1, y1;
    char *text;

    /* --- the rule, out of the original's own numbers ----------------- */
    /* The sheet coordinates above are worked back from where the two
       clicks landed, so they are only good to a hundredth of a
       millimetre; the rule they are being held to -- one to one, the
       sheet's middle on the page's middle -- is pinned far tighter than
       the 0.03 allowed here. */
    cknear((O_X1 - O_X0) * u2mm, SHEET_X1 - SHEET_X0, 0.03,
           "原典: 印刷は横も原寸");
    cknear((O_Y1 - O_Y0) * u2mm, -(SHEET_Y1 - SHEET_Y0), 0.03,
           "原典: 縦も原寸（y は逆向き）");
    cknear(O_X0 * u2mm, O_PAGE_W / mm2pt / 2.0 + SHEET_X0, 0.03,
           "原典: 用紙の中心が紙の中心に来る（x）");
    cknear(O_Y0 * u2mm, O_PAGE_H / mm2pt / 2.0 - SHEET_Y0, 0.03,
           "原典: 同じく y");
    cknear(O_W * u2mm, 2.0 * 25.4 / 300.0, 5e-4,
           "原典: 太さは print_width の 300dpi ドット");

    /* --- and the port, printing the same line ------------------------ */
    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);
        ck(o != 0, "線を一本置く");
        if (!o)
            return 1;
        o->color = 2;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = SHEET_X0;
        o->d[1] = SHEET_Y0;
        o->d[2] = SHEET_X1;
        o->d[3] = SHEET_Y1;
    }
    jw_plot_paper(d, &wide, &tall);
    cknear(wide, 594.0, 1e-9, "頁は用紙の幅（A-2）");
    cknear(tall, 420.0, 1e-9, "頁は用紙の高さ");

    pdf = jw_plot_pdf(d, 0, &plen);
    ck(pdf != 0 && plen > 400, "PDF が出る");
    if (!pdf)
        return 1;
    text = (char *)malloc((size_t)plen + 1);
    memcpy(text, pdf, (size_t)plen);
    text[plen] = 0;
    {
        char want[128];
        sprintf(want, "/MediaBox[0 0 %.2f %.2f]", wide * mm2pt, tall * mm2pt);
        ck(strstr(text, want) != 0, "  MediaBox は用紙そのもの");
        if (!strstr(text, want))
            printf("     %s がない\n", want);
    }
    ck(strstr(text, "1 J\n1 j\n") != 0, "  丸い端と丸い角（原典と同じ）");
    ck(strstr(text, "0.000 0.000 0.000 RG") != 0, "  墨で刷る");
    {
        char want[64];
        sprintf(want, "%.3f w", 2.0 * 25.4 / 300.0 * mm2pt);
        ck(strstr(text, want) != 0, "  太さも原典と同じ");
        if (!strstr(text, want))
            printf("     %s がない\n", want);
    }
    if (two_points(text, &x0, &y0, &x1, &y1)) {
        /* Half a printer's dot either way: both the original and the port
           round every coordinate to a six hundredth of an inch, which is
           0.0423 mm, so a point can sit 0.0212 off and a length -- two
           rounded ends -- 0.0423 (src/plot.c's DOT_PT). */
        const double DOT = 25.4 / 600.0;

        cknear(x0 / mm2pt - wide / 2.0, SHEET_X0, DOT / 2.0 + 1e-6,
               "  始点は用紙の中心から測って同じところ（x）");
        cknear(y0 / mm2pt - tall / 2.0, SHEET_Y0, DOT / 2.0 + 1e-6,
               "  同じく y");
        cknear((x1 - x0) / mm2pt, SHEET_X1 - SHEET_X0, DOT + 1e-6,
               "  長さも原寸（x）");
        cknear((y1 - y0) / mm2pt, SHEET_Y1 - SHEET_Y0, DOT + 1e-6,
               "  同じく y");
    } else {
        ck(0, "  PDF から線が読み取れる");
    }
    if (argc > 1) {
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(pdf, 1, (size_t)plen, f);
            fclose(f);
            printf("     wrote %s (%ld bytes)\n", argv[1], plen);
        }
    }
    free(text);
    free(pdf);

    /* the nine line types: eight dash arrays and no 補助線, which is
       what came back from the original's own printer (probe34.sh, and
       decomp/res/print_dash.txt).

       The phase on each is half the first dash, because the original
       starts every dashed line in the **middle** of a dash: its own PDF
       writes each dash as its own stroke, and the part one each line
       begins with came to 0.847, 1.693, 2.582, 4.446, 11.600, 3.556 and
       10.710 mm -- half of 1.693, 3.429, 5.165, 8.932, 23.199, 7.154 and
       21.421 in that order (tmp/orig_dash.pdf, read again). */
    {
        /* The runs of each type, in millimetres, and how many strokes the
           original's own printer made of each 200 mm line.  Both came off
           decomp/res/print_dash.txt. */
        static const struct {
            int strokes;                /* dashes, and the end dot */
            double first;               /* the part dash it starts with */
            double run[6];              /* on, off, on, off ... */
            int nrun;
        } WANT[7] = {
            { 61, 0.847, { 1.693, 1.693 }, 2 },
            { 31, 1.693, { 3.429, 3.429 }, 2 },
            { 31, 2.582, { 5.165, 1.736 }, 2 },
            { 30, 4.446, { 8.932, 1.778, 1.778, 1.778 }, 4 },
            { 16, 11.600, { 23.199, 1.778, 1.778, 1.778 }, 4 },
            { 44, 3.556, { 7.154, 1.778, 0.889, 1.778, 0.889, 1.778 }, 6 },
            { 23, 10.710, { 21.421, 1.778, 0.889, 1.778, 0.889, 1.778 }, 6 }
        };
        jw_drawing *e;
        unsigned char *q;
        long qn;
        char *t;
        int i, ok = 1;

        app_new();
        e = (jw_drawing *)app_drawing();
        for (i = 1; i <= 9; i++) {
            jw_obj *o = jw_add(e, JW_SEN);
            if (!o)
                break;
            o->color = 2;
            o->ltype = (unsigned char)i;
            o->layer = 0;
            o->lgroup = 0;
            o->d[0] = -100.0;
            o->d[1] = 100.0 - i * 20.0;
            o->d[2] = 100.0;
            o->d[3] = 100.0 - i * 20.0;
        }
        q = jw_plot_pdf(e, 0, &qn);
        ck(q != 0, "九つの線種を刷る");
        if (q) {
            double ys[16], xs0[2048], xs1[2048];
            int row[16], nrow = 0, nseg = 0, bad = 0;
            double seg_y[2048];
            const char *r;

            t = (char *)malloc((size_t)qn + 1);
            memcpy(t, q, (size_t)qn);
            t[qn] = 0;
            /* every stroke the port wrote, and the row it is on */
            for (r = t; (r = strstr(r, " m ")) != 0; ) {
                double x0, y0, x1, y1;
                const char *s2 = r;

                while (s2 > t && s2[-1] != '\n')
                    s2--;
                if (sscanf(s2, "%lf %lf m %lf %lf l", &x0, &y0, &x1, &y1) == 4
                    && nseg < 2048) {
                    xs0[nseg] = x0;
                    xs1[nseg] = x1;
                    seg_y[nseg] = y0;
                    nseg++;
                    /* and every number has to be on the printer's dot */
                    if (!on_dot(x0) || !on_dot(y0) || !on_dot(x1)
                        || !on_dot(y1))
                        bad++;
                }
                r += 3;
            }
            ck(bad == 0, "  どの数も 600 分の一インチの倍数");
            if (bad)
                printf("     %d 個が格子から外れている\n", bad);
            for (i = 0; i < nseg; i++) {
                int k;

                for (k = 0; k < nrow; k++)
                    if (ys[k] > seg_y[i] - 1e-6 && ys[k] < seg_y[i] + 1e-6)
                        break;
                if (k == nrow && nrow < 16) {
                    ys[nrow] = seg_y[i];
                    row[nrow++] = 0;
                }
                if (k < 16)
                    row[k]++;
            }
            ck(nrow == 8, "  引いた九本のうち刷られるのは八本（補助線は出ない）");
            if (nrow != 8)
                printf("     %d 行出ている\n", nrow);
            /* the rows come out in the order they were drawn: 実線 first,
               then the seven dashed ones */
            ok = 1;
            for (i = 0; i < 7 && i + 1 < nrow; i++)
                if (row[i + 1] != WANT[i].strokes) {
                    printf("     %d 本目: %d 筆、原典は %d 筆\n",
                           i + 2, row[i + 1], WANT[i].strokes);
                    ok = 0;
                }
            ck(ok, "  刻みの数が原典と同じ");
            /* and the first dash of each is half the full one */
            ok = 1;
            {
                int at = row[0];

                for (i = 0; i < 7 && at < nseg; i++) {
                    double got = (xs1[at] - xs0[at]) * 25.4 / 72.0;

                    if (got < WANT[i].first - 0.05
                        || got > WANT[i].first + 0.05) {
                        printf("     %d 本目の最初の刻み %.3f、原典は %.3f\n",
                               i + 2, got, WANT[i].first);
                        ok = 0;
                    }
                    at += row[i + 1];
                }
            }
            ck(ok, "  どれも刻みの真ん中から始まる");
            free(t);
            free(q);
        }
        app_new();
        d = (jw_drawing *)app_drawing();
        {
            jw_obj *o = jw_add(d, JW_SEN);
            if (o) {
                o->color = 2;
                o->ltype = 1;
                o->d[0] = SHEET_X0;
                o->d[1] = SHEET_Y0;
                o->d[2] = SHEET_X1;
                o->d[3] = SHEET_Y1;
            }
        }
    }

    /* points, colours and a solid: tools/probe35.sh printed
       tools/mkpoints.c's drawing twice, once black and once with
       カラー印刷 ticked, and decomp/res/print_points.txt is the second.
       Four things came out of it. */
    {
        jw_drawing *e;
        unsigned char *q;
        long qn;
        char *t;
        int i;

        app_new();
        e = (jw_drawing *)app_drawing();
        for (i = 0; i < 2; i++) {       /* one point of each kind */
            jw_obj *o = jw_add(e, JW_TEN);
            if (!o)
                break;
            o->color = 2;
            o->ltype = 1;
            o->d[0] = -80.0 + i * 40.0;
            o->d[1] = 60.0;
            o->n = 1 - i;
        }
        for (i = 1; i <= 9; i++) {      /* one line of each colour */
            jw_obj *o = jw_add(e, JW_SEN);
            if (!o)
                break;
            o->color = (unsigned short)i;
            o->ltype = 1;
            o->d[0] = -80.0;
            o->d[1] = 20.0 - i * 10.0;
            o->d[2] = 80.0;
            o->d[3] = 20.0 - i * 10.0;
        }
        {
            jw_obj *o = jw_add(e, JW_SOLID);
            if (o) {
                o->color = 4;
                o->ltype = 1;
                o->d[0] = -80; o->d[1] = -80;
                o->d[2] = -40; o->d[3] = -80;
                o->d[4] = -40; o->d[5] = -60;
                o->d[6] = -80; o->d[7] = -60;
            }
        }
        q = jw_plot_pdf(e, 1, &qn);     /* カラー印刷 */
        ck(q != 0, "点と色と塗りを刷る");
        if (q) {
            int n = 0;
            const char *r;
            t = (char *)malloc((size_t)qn + 1);
            memcpy(t, q, (size_t)qn);
            t[qn] = 0;
            /* the widths are print_width in 300 dpi dots */
            ck(strstr(t, "0.240 w") != 0, "  太さは print_width のドット数");
            /* the colours are print_rgb */
            ck(strstr(t, "0.000 1.000 1.000 RG") != 0, "  線色1 は水色");
            ck(strstr(t, "1.000 1.000 0.000 RG") != 0, "  線色4 は黄");
            ck(strstr(t, "0.000 0.502 0.502 RG") != 0, "  線色7 は鴨の羽色");
            /* 補助線色 (9) does not print: nine lines in, eight out */
            r = t;
            while ((r = strstr(r, " m ")) != 0) {
                n++;
                r += 3;
            }
            ck(n == 8 + 5 + 1,
               "  線は八本、点は一つ（五筆）、塗りが一つ");
            if (n != 14)
                printf("     %d 本出ている\n", n);
            ck(strstr(t, "h B*") != 0, "  塗りは塗って縁もなぞる");
            free(t);
            free(q);
        }
        app_new();
        d = (jw_drawing *)app_drawing();
        {
            jw_obj *o = jw_add(d, JW_SEN);
            if (o) {
                o->color = 2;
                o->ltype = 1;
                o->d[0] = SHEET_X0;
                o->d[1] = SHEET_Y0;
                o->d[2] = SHEET_X1;
                o->d[3] = SHEET_Y1;
            }
        }
    }

    png = jw_plot_png(d, 2.0, 0, &glen);
    ck(png != 0 && glen > 100, "PNG も出る");
    if (png) {
        ck(png[0] == 0x89 && png[1] == 'P' && png[2] == 'N' && png[3] == 'G',
           "  PNG の印がある");
        if (argc > 2) {
            FILE *f = fopen(argv[2], "wb");
            if (f) {
                fwrite(png, 1, (size_t)glen, f);
                fclose(f);
                printf("     wrote %s (%ld bytes)\n", argv[2], glen);
            }
        }
        free(png);
    }

    /* A dashed line far longer than the sheet.  The drawing may hold
       coordinates up to 1e12, and the PDF used to be written a dash at a
       time along the whole of it -- a 1e9 mm line had not finished after
       two minutes.  Only the part on the sheet is walked now; the rest
       moves the pattern on by arithmetic, so the dashes that are on the
       sheet are the same ones as before (checked stroke for stroke against
       the old writer while this was made). */
    {
        jw_drawing *dd;
        jw_obj *o;
        unsigned char *pdf;
        long plen = 0;
        int lt;

        app_new();
        dd = (jw_drawing *)app_drawing();
        for (lt = 2; lt <= 9; lt++) {
            o = jw_add(dd, JW_SEN);
            o->ltype = (unsigned char)lt;
            o->color = 2;
            o->d[0] = -1e9;
            o->d[1] = lt * 5.0;
            o->d[2] = 1e9;
            o->d[3] = lt * 5.0;
        }
        pdf = jw_plot_pdf(dd, 0, &plen);
        ck(pdf != 0 && plen > 0 && plen < 2000000,
           "線種のついた 1e9 mm の線八本も、PDF はすぐ書ける（用紙の上の破線だけ）");
        free(pdf);
    }
    print_command(mm2pt);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
