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

    /* and the other way: ファイル読込 makes a 図形 of the same file, whose
       (0, 0) lands on the click.  decomp/res/coordin.jww is the original's,
       read into a blank sheet -- which is at 1/100, so what was written out
       of a 1/200 drawing comes back half the size. */
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        free(b);
        printf("SOME BAD\n");
        return 1;
    }
    free(b);
    b = slurp("decomp/res/coord.txt", &n);
    if (!b) {
        printf("BAD  cannot read decomp/res/coord.txt\n");
        printf("SOME BAD\n");
        return 1;
    }
    ck(app_coord(b, n), "the file is read back as a figure");
    free(b);
    ck(jw_cmd() == JW_CMD_ZUKEI, "  which enters 図形読込");
    ui_view_rect(fb->w, fb->h, &r);
    app_press(r.x + 400, r.y + 300, 0);
    {
        const jw_drawing *d = app_drawing();
        jw_drawing rf;
        int j, bad = 0;

        memset(&rf, 0, sizeof rf);
        b = slurp("decomp/res/coordin.jww", &n);
        if (!b || !jw_parse(&rf, b, n)) {
            printf("BAD  cannot read decomp/res/coordin.jww -- drive the "
                   "original first\n");
            fails++;
            free(b);
            printf("SOME BAD\n");
            return 1;
        }
        free(b);
        for (i = 0, j = 0; i < rf.ndrawn && j < d->ndrawn; i++) {
            const jw_obj *q = &rf.obj[i], *p;
            int k;

            if (!jw_text_drawn(q))
                continue;
            while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
                j++;
            if (j >= d->ndrawn)
                break;
            p = &d->obj[j++];
            if (p->cls != q->cls || p->color != q->color
                || p->ltype != q->ltype || p->width != q->width
                || (p->layer & 15) != (q->layer & 15)) {
                printf("     the %dth is cls=%d col=%d lt=%d w=%d lay=%d "
                       "where the original's is cls=%d col=%d lt=%d w=%d "
                       "lay=%d\n", i, p->cls, p->color, p->ltype, p->width,
                       p->layer & 15, q->cls, q->color, q->ltype, q->width,
                       q->layer & 15);
                bad = 1;
                continue;
            }
            for (k = 0; k < 8; k++) {
                double a = p->d[k], c = q->d[k];

                if (p->cls == JW_ENKO && k == 3) {
                    /* The port holds the angle the file gave (270 degrees);
                       the original held it too and wrote it into the .jww,
                       but **reading** one brings it into (-pi, pi], so the
                       answer comes back as -90.  See RESUME.md. */
                    while (a > 3.141592653589793)
                        a -= 6.283185307179586;
                    while (c > 3.141592653589793)
                        c -= 6.283185307179586;
                }
                if (a - c > 1e-6 || c - a > 1e-6) {
                    printf("     the %dth's d[%d] is %.6f, the original's "
                           "%.6f\n", i, k, p->d[k], q->d[k]);
                    bad = 1;
                }
            }
        }
        ck(!bad, "  and every element is the original's, to six places");
        jw_free(&rf);
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
