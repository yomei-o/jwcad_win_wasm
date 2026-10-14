/* Saving must not change the drawing in memory, and a save followed by an open must
   settle: the same elements, the same bytes, round after round.  (tmp/features_wasm/cdp_save.js
   once saw six more elements after a reopen; this is where that is pinned down.)

   app_save puts the six hidden settings records every file Jw_cad writes ends with on for
   the write when the drawing does not hold them (a 新規 drawing), and takes them off again. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
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

static int hidden(const jw_drawing *d)
{
    int i, k = 0;

    for (i = 0; i < d->ndrawn; i++)
        k += d->obj[i].cls == JW_MOJI && d->obj[i].d[1] == -1000.0;
    return k;
}

/* save the open drawing and open it again, three rounds: nothing may change after the first */
static void rounds(const char *what, int expect_added)
{
    const jw_drawing *d = app_drawing();
    unsigned char *s1 = 0, *s2 = 0, *s3 = 0, *sb = 0;
    long n1 = 0, n2 = 0, n3 = 0, nb = 0;
    int c0 = d->ndrawn, nobj0 = d->nobj, h0 = hidden(d), c1, c2, o1, o2;
    char msg[240];

    sprintf(msg, "%s: it saves", what);
    ck(app_save(&s1, &n1), msg);
    ck(d->ndrawn == c0 && d->nobj == nobj0 && hidden(d) == h0,
       "  and saving leaves the drawing in memory as it was");
    ck(app_save_backup(&sb, &nb) && d->ndrawn == c0 && d->nobj == nobj0 && nb == n1 && !memcmp(sb, s1, (size_t)n1),
       "  the autosave copy is the same bytes and leaves it as it was too");
    free(sb);
    ck(app_open(s1, n1), "  the saved file opens");
    c1 = d->ndrawn;
    o1 = d->nobj;
    printf("     %s: before %d drawn / %d in all, %d hidden; reopened %d / %d, %d hidden\n", what, c0, nobj0, h0, c1, o1, hidden(d));
    sprintf(msg, "  it has %d more drawn elements than before (expected %d), %d more in all", c1 - c0, expect_added, o1 - nobj0);
    ck(c1 - c0 == expect_added && o1 - nobj0 == expect_added, msg);
    ck(app_save(&s2, &n2) && n2 == n1 && !memcmp(s1, s2, (size_t)n1), "  saved again: the same bytes");
    ck(app_open(s2, n2), "  opened again");
    c2 = d->ndrawn;
    o2 = d->nobj;
    ck(c2 == c1 && o2 == o1, "  with exactly the same number of elements");
    ck(app_save(&s3, &n3) && n3 == n1 && !memcmp(s1, s3, (size_t)n1), "  and a third save is the same bytes again");
    free(s1);
    free(s2);
    free(s3);
}

static void open_file(const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    char msg[200];

    sprintf(msg, "%s opens", path);
    ck(b && app_open(b, n), msg);
    free(b);
}

int main(void)
{
    const fb_t *fb;
    rect_t r;

    app_resize(1264, 741);
    fb = app_fb();
    ui_view_rect(fb->w, fb->h, &r);

    /* As the front ends start: with a drawing begun by 新規, which is also what leaves the six
       records for app_save to put on when a drawing lacks them. */
    app_new();

    /* A version 600 sample has none of the six hidden records.  The original, saving one,
       writes them: decomp/res/mentori.jww is Test5 (89 drawn) after a command, saved by the
       original, and carries them (see tests/bunkatsu_test.c's base).  So the first round
       adds exactly six -- that is the file's own, not a leak -- and from then on nothing. */
    open_file("orig/Test1.jww");
    ck(hidden(app_drawing()) == 0, "Test1.jww holds none of them");
    rounds("Test1.jww", 6);
    ck(hidden(app_drawing()) == 6, "  and now the drawing opened from the save holds the six");
    rounds("  and the round after", 0);

    open_file("orig/Test5.jww");
    {
        int c0 = app_drawing()->ndrawn;

        rounds("Test5.jww", 6);
        printf("     Test5 had %d drawn, now %d\n", c0, app_drawing()->ndrawn);
    }

    /* files the original itself wrote (version 700) have them already */
    open_file("decomp/res/new.jww");
    rounds("new.jww", 0);
    open_file("decomp/res/mentori.jww");
    rounds("mentori.jww (the original's save of Test5)", 0);
    open_file("decomp/res/bt_nest2.jww");
    rounds("bt_nest2.jww", 0);

    /* a sample drawn on before it is saved (tmp/features_wasm/cdp_save.js drew two lines and
       saw the six on reopening: that is this) */
    open_file("orig/Test1.jww");
    app_command(JW_CMD_SEN);
    app_press(r.x + 300, r.y + 300, 0);
    app_press(r.x + 500, r.y + 380, 0);
    app_press(r.x + 300, r.y + 400, 0);
    app_press(r.x + 520, r.y + 450, 0);
    rounds("Test1.jww with two lines", 6);
    app_press(r.x + 350, r.y + 500, 0);
    app_press(r.x + 560, r.y + 520, 0);
    rounds("  and one more line after it", 0);

    /* a drawing begun with 新規: the file gets the six too */
    app_new();
    app_command(JW_CMD_SEN);
    app_press(r.x + 200, r.y + 200, 0);
    app_press(r.x + 400, r.y + 300, 0);
    ck(app_drawing()->ndrawn == 1, "a new drawing with one line");
    rounds("the new drawing", 6);

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
