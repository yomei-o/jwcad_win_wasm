/* 包絡処理 -- against what the original welded.
 *
 *   tests/houraku_test.exe
 *
 * Each case draws the same lines on a new drawing that the original was
 * given (decomp/res/new.jww, which src/gen/newjww.c is baked from), puts
 * the same box round them, and holds the result up against the drawing the
 * original saved.  The clicks are the screen ones tools/refanswers.sh
 * sends, so the box lands on the same paper coordinates.
 *
 * The lines are compared as a set, either way round, to 1e-6: the original
 * does not keep them in any order the port could follow.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

/* the same line, either way round -- or, for an arc, the same seven numbers */
static int same(const jw_obj *a, const jw_obj *b)
{
    if (a->cls != b->cls)
        return 0;
    if (a->cls == JW_ENKO) {
        int i;

        for (i = 0; i < 7; i++)
            if (!near(a->d[i], b->d[i]))
                return 0;
        return 1;
    }
    return (near(a->d[0], b->d[0]) && near(a->d[1], b->d[1])
            && near(a->d[2], b->d[2]) && near(a->d[3], b->d[3]))
        || (near(a->d[0], b->d[2]) && near(a->d[1], b->d[3])
            && near(a->d[2], b->d[0]) && near(a->d[3], b->d[1]));
}

/* a line or an arc: the two the weld may touch */
static int drawn(const jw_obj *o)
{
    return o->cls == JW_SEN || o->cls == JW_ENKO;
}

typedef struct {
    const char *name;
    const char *answer;
    const char *base;           /* the drawing to start from, 0 for a new one */
    const int *clicks;          /* pairs: the lines */
    int nclick;
    const int *circles;         /* pairs: centre and a point on the rim */
    int ncircle;
    int bx0, by0, bx1, by1;     /* the box */
    int erase;                  /* the second corner with the right button */
} hcase;

static void one(const hcase *c)
{
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    int i, j, nr = 0, nm = 0, bad = 0;

    printf("%s\n", c->name);
    memset(&ref, 0, sizeof ref);
    b = slurp(c->answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", c->answer);
        fails++;
        free(b);
        return;
    }
    free(b);

    if (c->base) {
        b = slurp(c->base, &n);
        if (!b || !app_open(b, n)) {
            printf("BAD  cannot open %s\n", c->base);
            fails++;
            free(b);
            jw_free(&ref);
            return;
        }
        free(b);
    } else {
        app_new();
    }
    {   /* the clicks are the view's own, as tools/jwdraw.ps1 sends them,
           so where the view sits in the window has to be added */
        const fb_t *fb = app_fb();
        rect_t r;

        ui_view_rect(fb->w, fb->h, &r);
        jw_cmd_set(JW_CMD_SEN);
        for (i = 0; i + 1 < c->nclick; i += 2)
            app_press(r.x + c->clicks[i], r.y + c->clicks[i + 1], 0);
        for (i = 0; i + 1 < c->ncircle; i += 2) {
            if (i == 0)
                jw_cmd_set(JW_CMD_ENKO);
            app_press(r.x + c->circles[i], r.y + c->circles[i + 1], 0);
        }
        jw_cmd_set(JW_CMD_HOURAKU);
        app_press(r.x + c->bx0, r.y + c->by0, 0);
        app_press(r.x + c->bx1, r.y + c->by1, c->erase);
    }
    d = app_drawing();

    for (i = 0; i < ref.ndrawn; i++)
        if (drawn(&ref.obj[i]))
            nr++;
    for (i = 0; i < d->ndrawn; i++)
        if (drawn(&d->obj[i]))
            nm++;
    if (nm != nr) {
        printf("     %d lines, the original made %d\n", nm, nr);
        bad = 1;
    }
    for (i = 0; i < d->ndrawn && !bad; i++) {
        if (!drawn(&d->obj[i]))
            continue;
        for (j = 0; j < ref.ndrawn; j++)
            if (drawn(&ref.obj[j]) && same(&d->obj[i], &ref.obj[j]))
                break;
        if (j == ref.ndrawn) {
            printf("     ours has (%.4f %.4f)-(%.4f %.4f), the original "
                   "has no such line\n", d->obj[i].d[0], d->obj[i].d[1],
                   d->obj[i].d[2], d->obj[i].d[3]);
            bad = 1;
        }
    }
    if (bad) {
        printf("     the original's:\n");
        for (j = 0; j < ref.ndrawn; j++)
            if (drawn(&ref.obj[j]))
                printf("       (%.4f %.4f)-(%.4f %.4f)\n", ref.obj[j].d[0],
                       ref.obj[j].d[1], ref.obj[j].d[2], ref.obj[j].d[3]);
        printf("     ours:\n");
        for (j = 0; j < d->ndrawn; j++)
            if (drawn(&d->obj[j]))
                printf("       (%.4f %.4f)-(%.4f %.4f)\n", d->obj[j].d[0],
                       d->obj[j].d[1], d->obj[j].d[2], d->obj[j].d[3]);
    }
    ck(!bad, "  the same lines as the original's");
    jw_free(&ref);
}

/* the open cross: two level lines and two upright ones */
static const int CROSS[] = {
    200, 300, 800, 300,  200, 340, 800, 340,
    480, 150, 480, 500,  520, 150, 520, 500
};
/* the same walls closed at both ends */
static const int SHUT[] = {
    200, 300, 800, 300,  800, 300, 800, 340,
    800, 340, 200, 340,  200, 340, 200, 300,
    480, 150, 520, 150,  520, 150, 520, 500,
    520, 500, 480, 500,  480, 500, 480, 150
};

/* a closed level wall, and the upright pair open */
static const int WALL[] = {
    200, 300, 800, 300,  800, 300, 800, 340,
    800, 340, 200, 340,  200, 340, 200, 300
};
static const int WALL_PAIR[] = {
    200, 300, 800, 300,  800, 300, 800, 340,
    800, 340, 200, 340,  200, 340, 200, 300,
    480, 150, 480, 500,  520, 150, 520, 500
};
/* the same, with the upright pair capped at the top only */
static const int WALL_U[] = {
    200, 300, 800, 300,  800, 300, 800, 340,
    800, 340, 200, 340,  200, 340, 200, 300,
    480, 150, 480, 500,  520, 150, 520, 500,
    480, 150, 520, 150
};
/* two closed rectangles side by side, not touching */
static const int APART[] = {
    200, 200, 400, 200,  400, 200, 400, 300,
    400, 300, 200, 300,  200, 300, 200, 200,
    600, 200, 800, 200,  800, 200, 800, 300,
    800, 300, 600, 300,  600, 300, 600, 200
};
/* a level wall, open, with a circle through it */
static const int WALL_OPEN[] = {
    200, 300, 800, 300,  200, 340, 800, 340
};
static const int ONE_CIRCLE[] = { 500, 320, 500, 220 };

/* the closed wall with one line straight through it */
static const int WALL_ONE[] = {
    200, 300, 800, 300,  800, 300, 800, 340,
    800, 340, 200, 340,  200, 340, 200, 300,
    500, 150, 500, 500
};

/* One 元に戻る has to put the drawing back exactly as it was, however many
   lines the weld changed, added or took out. */
static void undo_case(const hcase *c)
{
    const jw_drawing *d;
    jw_obj *was;
    int i, n, bad = 0;

    printf("%s, and then 元に戻る\n", c->name);
    app_new();
    {
        const fb_t *fb = app_fb();
        rect_t r;

        ui_view_rect(fb->w, fb->h, &r);
        jw_cmd_set(JW_CMD_SEN);
        for (i = 0; i + 1 < c->nclick; i += 2)
            app_press(r.x + c->clicks[i], r.y + c->clicks[i + 1], 0);
        d = app_drawing();
        n = d->ndrawn;
        was = (jw_obj *)malloc((size_t)n * sizeof *was);
        if (!was)
            return;
        memcpy(was, d->obj, (size_t)n * sizeof *was);
        jw_cmd_set(JW_CMD_HOURAKU);
        app_press(r.x + c->bx0, r.y + c->by0, 0);
        app_press(r.x + c->bx1, r.y + c->by1, c->erase);
    }
    d = app_drawing();
    ck(d->ndrawn != n || memcmp(was, d->obj, (size_t)n * sizeof *was) != 0,
       "  the weld changed something");
    ck(jw_cmd_can_undo(), "  and left something to undo");
    jw_cmd_undo((jw_drawing *)app_drawing());
    d = app_drawing();
    if (d->ndrawn != n)
        bad = 1;
    for (i = 0; i < n && !bad; i++)
        if (d->obj[i].cls != was[i].cls || !same(&d->obj[i], &was[i]))
            bad = 1;
    if (bad)
        printf("     %d elements after the undo, %d before\n", d->ndrawn, n);
    ck(!bad, "  元に戻る puts every line back where it was");
    free(was);
}

int main(void)
{
    static const hcase C[] = {
        { "the open cross, the box round the crossing only",
          "decomp/res/houraku1.jww", 0, CROSS, 16, 0, 0, 450, 270, 560, 380, 0 },
        { "the open cross, the box round all of it",
          "decomp/res/houraku2.jww", 0, CROSS, 16, 0, 0, 150, 100, 850, 550, 0 },
        { "the closed cross, the box round the crossing only",
          "decomp/res/houraku3.jww", 0, SHUT, 32, 0, 0, 450, 270, 560, 380, 0 },
        { "the closed cross, the box round all of it",
          "decomp/res/houraku4.jww", 0, SHUT, 32, 0, 0, 150, 100, 850, 550, 0 },
        { "the open cross, the box round the upright pair only",
          "decomp/res/houraku5.jww", 0, CROSS, 16, 0, 0, 300, 120, 700, 530, 0 },
        { "a closed wall and an open pair through it",
          "decomp/res/houraku6.jww", 0, WALL_PAIR, 24, 0, 0, 150, 100, 850, 550, 0 },
        { "the same with the pair capped at the top",
          "decomp/res/houraku7.jww", 0, WALL_U, 28, 0, 0, 150, 100, 850, 550, 0 },
        { "two closed rectangles that do not touch",
          "decomp/res/houraku8.jww", 0, APART, 32, 0, 0, 150, 150, 850, 350, 0 },
        { "a closed wall with one line through it",
          "decomp/res/houraku9.jww", 0, WALL_ONE, 20, 0, 0, 150, 100, 850, 550, 0 },
        { "範囲内消去: the open cross, a box in the middle",
          "decomp/res/houraku10.jww", 0, CROSS, 16, 0, 0, 450, 270, 560, 380, 1 },
        { "範囲内消去: the closed cross, a wider box",
          "decomp/res/houraku11.jww", 0, SHUT, 32, 0, 0, 300, 120, 700, 530, 1 },
        /* and a real drawing, where the box catches a great deal but
           nothing of the same pen crosses anything of its own: the original
           leaves it alone, and so must the port */
        { "a real drawing, a box over the middle",
          "decomp/res/houraku12.jww",
          "orig/\x82\x60\x83}\x83\x93\x83V\x83\x87\x83\x93\x95\xbd\x96\xca\x97\xe1.jww",
          0, 0, 0, 0, 400, 250, 700, 450, 0 },
        /* a circle through a wall: the original welds lines and nothing
           else, so it leaves all three alone */
        { "a circle through a wall", "decomp/res/houraku13.jww", 0,
          WALL_OPEN, 8, ONE_CIRCLE, 4, 350, 170, 650, 470, 0 },
    };
    (void)WALL;
    int i;

    app_resize(1264, 741);
    for (i = 0; i < (int)(sizeof C / sizeof C[0]); i++)
        one(&C[i]);
    /* and that one press takes the whole of it back */
    undo_case(&C[3]);           /* the closed cross, which loses four lines */
    undo_case(&C[9]);           /* and a 範囲内消去, which cuts them */
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
