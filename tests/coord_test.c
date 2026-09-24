/* 座標ファイル (32895) の ファイル書込 -- against the original, byte for byte.
 *
 *   tests/coord_test.exe
 *
 * The original was opened on tmp/geom.jww (tools/mkgeom.c's twelve
 * elements), given 座標ファイル, a file name through ファイル名設定, then
 * ファイル書込 with 全選択 and 選択確定.  decomp/res/coord.txt is what it
 * wrote -- 843 bytes of text.
 *
 * The point everything is measured from is the one ブロック化 uses: the
 * average of one point per element.  See src/coord.c.
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
        free(b);
        return 1;
    }
    free(b);

    /* everything picked, the way 全選択 leaves it */
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
    ck(jw_cmd_sel_count(app_drawing()) == 12, "a range over all twelve");

    ck(app_command(32895), "座標ファイル asks the front end for a name");
    ck(app_take_action() == JW_ACT_SAVE_COORD, "  which is the action");
    ck(app_coord_save(&mine, &mn), "and it writes the file");

    if (argc > 1 && mine) {
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(mine, 1, (size_t)mn, f);
            fclose(f);
            printf("     wrote %s, %ld bytes\n", argv[1], mn);
        }
    }
    ref = slurp("decomp/res/coord.txt", &rn);
    if (!ref) {
        printf("BAD  cannot read decomp/res/coord.txt -- drive the original "
               "first\n");
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
