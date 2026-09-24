/* 軸角・目盛・オフセット -- the dialog and the axis angle, against the
 * original.
 *
 *   tests/jikkaku_test.exe tests/out/jikkaku.png
 *
 * docs/ref_jikkaku.png is that dialog painted into a bitmap by Jw_cad
 * itself.  This puts the port's up in the same state and writes it out to
 * be scored against that picture.
 *
 * And what the angle does.  The original was given 30 in the 軸角 combo and
 * Ok, then a line dragged with 水平・垂直 on; decomp/res/jikkaku30.jww is
 * what it saved.  The line came out at exactly 30 degrees, as far along the
 * axis as the drag reached.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/jikkaku.h"
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

/* the middle of one of the dialog's controls, in client pixels */
static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_jikkaku_rect(1264, 741, &r);
    for (i = 0; i < JW_NJIKKAKU; i++)
        if (jw_jikkaku[i].id == id) {
            *x = r.x + JW_JK_BORDER + jw_jikkaku[i].x + jw_jikkaku[i].w / 2;
            *y = r.y + JW_JK_CAPTION + jw_jikkaku[i].y + jw_jikkaku[i].h / 2;
            return;
        }
    *x = *y = -1;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    const jw_drawing *d;
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j, at = -1;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        return 1;
    }
    free(b);

    ck(!app_jikkaku_open(), "the dialog is not up to start with");
    ck(app_command(32842), "軸角・目盛・オフセット puts it up");
    ck(app_jikkaku_open(), "which says so");
    ck(jw_cmd_axis() == 0.0, "and the axis is flat to start with");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_jikkaku_rect(fb->w, fb->h, &r);
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

    /* 30 into the 軸角 box, and Ok */
    app_key('3');
    app_key('0');
    ck(!strcmp(app_jikkaku_angle(), "030")
       || !strcmp(app_jikkaku_angle(), "30"),
       "the box takes what is typed");
    ctl(1, &x, &y);
    app_press(x, y, 0);
    ck(!app_jikkaku_open(), "Ok takes it down");
    ck(jw_cmd_axis() == 30.0, "and the axis is turned to 30");

    /* and a line drawn with 水平・垂直 follows it */
    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/jikkaku30.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/jikkaku30.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        printf("%s\n", fails ? "SOME BAD" : "all ok");
        return fails ? 1 : 0;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN)
            at = i;
    ck(at >= 0, "the original's line is in the answer");
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_SEN);
    if (!jw_cmd_hv())
        jw_cmd_set(JW_CMD_SEN);         /* pressing 線 again flips 水平・垂直 */
    ck(jw_cmd_hv(), "水平・垂直 is on");
    app_press(r.x + 300, r.y + 300, 0);
    app_press(r.x + 700, r.y + 320, 0);
    d = app_drawing();
    if (at >= 0 && d->ndrawn > 0) {
        const jw_obj *o = &d->obj[d->ndrawn - 1];
        double a = atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
        const jw_obj *q = &ref.obj[at];
        double qa = atan2(q->d[3] - q->d[1], q->d[2] - q->d[0]) * 180.0 / PI;

        double e = a - qa, f = (o->d[2] - o->d[0]) - (q->d[2] - q->d[0]);

        printf("     ours %.9f degrees, the original's %.9f\n", a, qa);
        ck(o->cls == JW_SEN && e < 1e-9 && e > -1e-9,
           "and the line comes out along the axis, as the original's did");
        ck(f < 1e-9 && f > -1e-9,
           "and reaches as far along it as the original's did");
    }
    jw_cmd_set_axis(0.0);
    jw_free(&ref);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
