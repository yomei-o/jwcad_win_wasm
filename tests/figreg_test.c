/* 図形登録 (32946) -- against the original, byte for byte.
 *
 *   tests/figreg_test.exe
 *
 * The original was opened on tmp/geom.jww (tools/mkgeom.c's twelve
 * elements), given 図形登録, a range over the lot, 選択確定, and the base
 * point clicked at (400, 300) in the view.  decomp/res/figreg.jws is the
 * figure it wrote.
 *
 * The port is given the same range and the same point, and what it writes
 * has to be that file to the byte -- the 452-byte header and the element
 * list both.
 */
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

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b, *mine = 0, *ref;
    long n, mn = 0, rn;
    rect_t r;
    int i;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("tmp/geom.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open tmp/geom.jww -- run tools/refanswers.sh\n");
        return 1;
    }
    free(b);

    ui_view_rect(fb->w, fb->h, &r);
    ck(app_command(32946), "図形登録 starts");
    ck(jw_cmd() == JW_CMD_ZUKEIREG, "and it is the command in force");
    app_press(r.x + 100, r.y + 80, 0);
    app_press(r.x + 1000, r.y + 640, 0);
    ck(jw_cmd_sel_count(app_drawing()) == 12, "the range takes all twelve");
    app_move(r.x + 400, r.y + 300);
    ck(jw_cmd_bar((jw_drawing *)app_drawing(), 1120), "選択確定 settles it");
    ck(jw_cmd_sel_stage() == 3, "  which the bar follows");
    app_press(r.x + 400, r.y + 300, 0);
    ck(app_take_action() == JW_ACT_SAVE_FIG,
       "and the 基準点 asks the front end for a file");
    ck(app_figure_save(&mine, &mn), "which writes the figure");

    if (argc > 1 && mine) {             /* for looking at, when it differs */
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(mine, 1, (size_t)mn, f);
            fclose(f);
            printf("     wrote %s, %ld bytes\n", argv[1], mn);
        }
    }
    ref = slurp("decomp/res/figreg.jws", &rn);
    if (!ref) {
        printf("BAD  cannot read decomp/res/figreg.jws -- drive the "
               "original first\n");
        free(mine);
        printf("SOME BAD\n");
        return 1;
    }
    ck(mn == rn, "  as long as the original's");
    if (mn != rn)
        printf("     ours %ld bytes, theirs %ld\n", mn, rn);
    if (mine && mn == rn) {
        for (i = 0; i < rn; i++)
            if (mine[i] != ref[i]) {
                printf("     first differs at 0x%x: %02x, the original's "
                       "%02x\n", i, mine[i], ref[i]);
                break;
            }
        ck(i == rn, "  and the same byte for byte");
    }
    free(mine);
    free(ref);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
