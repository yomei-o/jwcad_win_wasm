/* 座標ファイル (32895) -- against the original, both ways.
 *
 *   tests/coord_test.exe
 *
 * **Writing.**  The original was given 座標ファイル, a file name through
 * ファイル名設定, then ファイル書込 with 全選択 and 選択確定.  Two drawings
 * were put through it: tools/mkgeom.c's twelve (lines, arcs, a whole circle,
 * points and solids) and Test5 (lines and 43 texts of three different
 * kinds).  decomp/res/coord.txt and decomp/res/coord2.txt are what it wrote.
 *
 * **Reading.**  ファイル読込 makes a 図形 of the file -- the prompt becomes
 * 「【図形】の複写位置を指示してください」 -- and its (0, 0) goes where it is
 * clicked.  decomp/res/coordin.jww and coordin2.jww are the two files read
 * into a blank sheet at (400, 300).
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

/* What the original wrote from `src`, byte for byte. */
static void writes(const char *src, const char *answer)
{
    const fb_t *fb = app_fb();
    unsigned char *b, *mine = 0, *ref;
    long n, mn = 0, rn;
    rect_t r;
    int i;

    printf("%s -> %s\n", src, answer);
    b = slurp(src, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open %s\n", src);
        free(b);
        fails++;
        return;
    }
    free(b);
    /* everything picked, the way 全選択 leaves it */
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
    ck(jw_cmd_sel_count(app_drawing()) > 0, "  a range over the drawing");
    ck(app_command(32895), "  座標ファイル asks the front end for a name");
    ck(app_take_action() == JW_ACT_SAVE_COORD, "  which is the action");
    ck(app_coord_save(&mine, &mn), "  and it writes the file");
    ref = slurp(answer, &rn);
    if (!ref) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        free(mine);
        fails++;
        return;
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
}

/* And the same file read back into a blank sheet. */
static void reads(const char *file, const char *answer)
{
    const fb_t *fb = app_fb();
    const jw_drawing *d;
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int i, j, bad = 0;

    printf("%s -> %s\n", file, answer);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        free(b);
        fails++;
        return;
    }
    free(b);
    b = slurp(file, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", file);
        fails++;
        return;
    }
    ck(app_coord(b, n), "  the file is read as a figure");
    free(b);
    ck(jw_cmd() == JW_CMD_ZUKEI, "  which enters 図形読込");
    ui_view_rect(fb->w, fb->h, &r);
    app_press(r.x + 400, r.y + 300, 0);
    d = app_drawing();

    memset(&ref, 0, sizeof ref);
    b = slurp(answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        fails++;
        free(b);
        return;
    }
    free(b);
    for (i = 0, j = 0; i < ref.ndrawn && j < d->ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p;
        int k;

        if (!jw_text_drawn(q))
            continue;
        while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
            j++;
        if (j >= d->ndrawn)
            break;
        p = &d->obj[j++];
        if (p->cls != q->cls || p->color != q->color || p->ltype != q->ltype
            || p->width != q->width || p->n != q->n
            || p->flags != q->flags || (p->layer & 15) != (q->layer & 15)) {
            printf("     the %dth is cls=%d col=%d lt=%d w=%d n=%d fl=%d "
                   "lay=%d where the original's is cls=%d col=%d lt=%d w=%d "
                   "n=%d fl=%d lay=%d\n", i, p->cls, p->color, p->ltype,
                   p->width, p->n, p->flags, p->layer & 15, q->cls, q->color,
                   q->ltype, q->width, q->n, q->flags, q->layer & 15);
            bad = 1;
            continue;
        }
        if (p->cls == JW_MOJI
            && strcmp(jw_str(d, p->text), jw_str(&ref, q->text))) {
            printf("     the %dth reads [%s], the original's [%s]\n", i,
                   jw_str(d, p->text), jw_str(&ref, q->text));
            bad = 1;
            continue;
        }
        for (k = 0; k < 8; k++) {
            double a = p->d[k], c = q->d[k];

            if (p->cls == JW_ENKO && k == 3) {
                /* The port holds the angle the file gave (270 degrees); the
                   original held it too and wrote it into the .jww, but
                   **reading** one brings it into (-pi, pi], so the answer
                   comes back as -90.  See RESUME.md. */
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
    jw_free(&ref);
}

int main(void)
{
    app_resize(1264, 741);
    writes("tmp/geom.jww", "decomp/res/coord.txt");
    writes("orig/Test5.jww", "decomp/res/coord2.txt");
    reads("decomp/res/coord.txt", "decomp/res/coordin.jww");
    reads("decomp/res/coord2.txt", "decomp/res/coordin2.jww");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
