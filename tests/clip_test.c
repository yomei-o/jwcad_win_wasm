/* 切り取り・コピー・貼り付け -- against the original's own pastes.
 *
 *   tests/clip_test.exe
 *
 * The original was driven (tools/probe56.sh, probe58.sh): an L of two
 * lines, a 範囲選択 box round it, コピー, and then 貼り付け at three
 * different places, and twice more with 倍率 2 and 回転角 90 on the bar
 * that 貼り付け puts up -- which is 図形読込's own bar.
 *
 *   decomp/res/clip_here.jww    pasted at view 400,500
 *   decomp/res/clip_right.jww   at 800,500
 *   decomp/res/clip_up.jww      at 400,200
 *   decomp/res/clip_mag2.jww    at 400,500 with 倍率 2
 *   decomp/res/clip_rot90.jww   at 400,500 with 回転角 90
 *   decomp/res/clip_cut.jww     切り取り: the drawing came back empty
 *
 * All five pastes fit
 *
 *     pasted = click + turn(scale * (original - B))
 *
 * with one B throughout, so B belongs to the copy and not to the click.
 * For this L it is (-94.2857, -19.5918): the average of the two lines'
 * own middles, and **not** the middle of the box round them.
 *
 * The L is built here by hand rather than clicked, so that what is being
 * compared is that rule and not the port's range picking.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"

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

/* the original's view: 49 pixels to 30 mm, its paper origin at 554,343 */
#define ORIG_PPM (49.0 / 30.0)
static double sheet_x(double px) { return (px - 554.0) / ORIG_PPM; }
static double sheet_y(double py) { return (343.0 - py) / ORIG_PPM; }

static int port_x(double mm)
{
    const jw_view *v = app_view();
    return v->bx + (int)floor((mm - v->ox) / v->mmpp + 0.5);
}

static int port_y(double mm)
{
    const jw_view *v = app_view();
    return v->by - (int)floor((mm - v->oy) / v->mmpp + 0.5);
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (i = 0; s[i]; i++)
        jw_cmd_box_key((unsigned char)s[i]);
    jw_cmd_box_key(13);
}

/* the L the original was given, in paper millimetres, and the two lines
   it pasted are the ones that carry no selection mark */
static const double L[2][4] = {
    { -155.51, -34.898,  89.3878, -34.898 },
    { -155.51, -34.898, -155.51,   26.3265 },
};

/* the two that were pasted: the original marks the ones it copied **from**
   with bit 2 of the flags (they are still selected in its saved file), and
   in the port they are simply the ones added after the two built by hand */
static int pasted_of(jw_drawing *d, const jw_obj **out, int max, int theirs)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++) {
        const jw_obj *o = &d->obj[i];
        if (o->cls != JW_SEN)
            continue;
        if (theirs ? !(o->flags & 2u) : i >= 2)
            out[n++] = o;
    }
    return n;
}

typedef struct {
    const char *answer, *what;
    int px, py;
    const char *box, *val;
} run_t;

static const run_t RUNS[] = {
    { "decomp/res/clip_here.jww",  "そこへ貼る",       400, 500, 0, 0 },
    { "decomp/res/clip_right.jww", "右へ貼る",         800, 500, 0, 0 },
    { "decomp/res/clip_up.jww",    "上へ貼る",         400, 200, 0, 0 },
    { "decomp/res/clip_mag2.jww",  "倍率 2 で貼る",    400, 500, "1431", "2" },
    { "decomp/res/clip_rot90.jww", "回転角 90 で貼る", 400, 500, "1412", "90" },
};

int main(void)
{
    static jw_drawing theirs;
    unsigned char *b;
    long n;
    int k;

    app_resize(1264, 741);
    for (k = 0; k < (int)(sizeof RUNS / sizeof RUNS[0]); k++) {
        const run_t *r = &RUNS[k];
        const jw_obj *a[4], *c[4];
        jw_drawing *d;
        int na, nc, i;

        printf("-- %s\n", r->what);
        b = slurp(r->answer, &n);
        if (!b) {
            printf("BAD  %s が読めない\n", r->answer);
            fails++;
            continue;
        }
        memset(&theirs, 0, sizeof theirs);
        if (!jw_parse(&theirs, b, n)) {
            printf("BAD  %s が開けない\n", r->answer);
            fails++;
            free(b);
            continue;
        }
        free(b);

        app_new();
        d = (jw_drawing *)app_drawing();
        for (i = 0; i < 2; i++) {
            jw_obj *o = jw_add(d, JW_SEN);
            if (!o)
                break;
            o->d[0] = L[i][0];
            o->d[1] = L[i][1];
            o->d[2] = L[i][2];
            o->d[3] = L[i][3];
            o->sel = 1;
        }
        ck(jw_cmd_clip_copy(d, 0) != 0, "  コピーが通る");
        ck(jw_cmd_clip_has() != 0, "  クリップボードに入る");
        ck(jw_cmd_clip_paste(d) != 0, "  貼り付けが 図形 を出す");
        ck(jw_cmd() == (int)JW_CMD_ZUKEI, "  出るのは 図形読込 の命令");
        /* 倍率 and 回転角 live on the 図形 bar, and that bar
           has not been taken off the original yet (src/gen/bars.h has no
           32862), so there is nothing to type into: the two are set
           through the call the front end would make. */
        if (r->box)
            jw_cmd_figure_at(atoi(r->box) == 1431 ? atof(r->val) : 1.0,
                             atoi(r->box) == 1412 ? atof(r->val) : 0.0);
        app_press(port_x(sheet_x(r->px)), port_y(sheet_y(r->py)), 0);

        na = pasted_of(&theirs, a, 4, 1);
        nc = pasted_of(d, c, 4, 0);
        ck(na == 2, "  原典は二本置いた");
        ck(nc == na, "  移植も同じ数だけ置く");
        for (i = 0; i < na && i < nc; i++) {
            char msg[160];
            int j, ok = 1;
            for (j = 0; j < 4; j++)
                if (fabs(a[i]->d[j] - c[i]->d[j]) > 0.35)
                    ok = 0;
            sprintf(msg, "  %d 本目 (%.4f,%.4f)-(%.4f,%.4f)", i,
                    a[i]->d[0], a[i]->d[1], a[i]->d[2], a[i]->d[3]);
            ck(ok, msg);
            if (!ok)
                printf("     移植は (%.4f,%.4f)-(%.4f,%.4f)\n",
                       c[i]->d[0], c[i]->d[1], c[i]->d[2], c[i]->d[3]);
        }
        jw_free(&theirs);
    }

    /* 切り取り takes the selection away */
    {
        jw_drawing *d;
        int i;

        printf("-- 切り取り\n");
        app_new();
        d = (jw_drawing *)app_drawing();
        for (i = 0; i < 2; i++) {
            jw_obj *o = jw_add(d, JW_SEN);
            if (!o)
                break;
            o->d[0] = L[i][0];
            o->d[1] = L[i][1];
            o->d[2] = L[i][2];
            o->d[3] = L[i][3];
            o->sel = 1;
        }
        ck(jw_cmd_clip_copy(d, 1) != 0, "  切り取りが通る");
        ck(jw_cmd_clip_has() != 0, "  クリップボードには残る");
        ck(d->ndrawn == 0, "  図面からは消える");
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
