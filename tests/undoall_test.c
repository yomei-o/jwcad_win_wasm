/* Do, undo, redo -- for every command, on random geometry, compared exactly.
 *
 *   tests/undoall_test.exe [seeds]        (default 6 seeds per command)
 *
 * For each command the toolbar (and the menu-only list) offers, and each of
 * a few seeds: a drawing of random lines, circles, arcs and points (some of
 * them awkward -- no length, radius 0, coordinates near 1e11) is made, the
 * command entered, and forty random actions taken: presses aimed at the
 * drawing's own points and presses at random pixels, keys, moves, a few
 * Enters and Escs.  Every action that took an undo step is then checked:
 *
 *   - 戻る gives back the drawing as it was, byte for byte (the element array
 *     as a whole, and how many are drawn);
 *   - 進む brings back the same elements the action made -- compared as a set,
 *     because the original puts the redone ones back at the front of the
 *     drawing, which is what the port does too;
 *   - and a second 戻る gives the first state again.
 *
 * A command that holds something by its place in the drawing across a 戻る
 * or 進む shows up here as a difference. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"

static unsigned long rng = 88172645463325252UL;
static unsigned nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 7;
    rng ^= rng << 17;
    return (unsigned)(rng >> 16);
}
static double frand(double lo, double hi) { return lo + (hi - lo) * (nextr() % 100001) / 100000.0; }

static int fails, checks, noundo;

typedef struct { double k[12]; } fp_t;

static int fp_cmp(const void *a, const void *b)
{
    const fp_t *x = (const fp_t *)a, *y = (const fp_t *)b;
    int i;

    for (i = 0; i < 12; i++) {
        if (x->k[i] < y->k[i]) return -1;
        if (x->k[i] > y->k[i]) return 1;
    }
    return 0;
}

static fp_t *fingerprint(const jw_drawing *d, int *n)
{
    fp_t *f;
    int i, j;

    *n = d ? d->nobj : 0;
    if (*n <= 0)
        return 0;
    f = (fp_t *)malloc((size_t)*n * sizeof *f);
    for (i = 0; f && i < *n; i++) {
        for (j = 0; j < 8; j++)
            f[i].k[j] = d->obj[i].d[j];
        f[i].k[8] = d->obj[i].cls;
        f[i].k[9] = d->obj[i].color;
        f[i].k[10] = d->obj[i].ltype;
        f[i].k[11] = d->obj[i].layer;
    }
    if (f)
        qsort(f, (size_t)*n, sizeof *f, fp_cmp);
    return f;
}

typedef struct { jw_obj *obj; int nobj, ndrawn; fp_t *fp; } snap_t;

static void take(snap_t *s, const jw_drawing *d)
{
    s->nobj = d->nobj;
    s->ndrawn = d->ndrawn;
    s->obj = 0;
    if (d->nobj > 0) {
        s->obj = (jw_obj *)malloc((size_t)d->nobj * sizeof *s->obj);
        memcpy(s->obj, d->obj, (size_t)d->nobj * sizeof *s->obj);
    }
    s->fp = 0;
    {
        int n;
        s->fp = fingerprint(d, &n);
    }
}

static void drop(snap_t *s) { free(s->obj); free(s->fp); s->obj = 0; s->fp = 0; }

static int same_exact(const snap_t *s, const jw_drawing *d)
{
    return s->nobj == d->nobj && s->ndrawn == d->ndrawn
           && (s->nobj == 0 || !memcmp(s->obj, d->obj, (size_t)s->nobj * sizeof *s->obj));
}

static int same_set(const snap_t *s, const jw_drawing *d)
{
    int n, ok;
    fp_t *f;

    if (s->nobj != d->nobj || s->ndrawn != d->ndrawn)
        return 0;
    f = fingerprint(d, &n);
    ok = n == 0 || (f && s->fp && !memcmp(f, s->fp, (size_t)n * sizeof *f));
    free(f);
    return ok;
}

static void make_drawing(void)
{
    static const unsigned char *none;
    int i, n = 8 + (int)(nextr() % 20);
    jw_drawing *d;

    (void)none;
    app_new();
    app_resize(1264, 741);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < n; i++) {
        unsigned k = nextr() % 10;
        jw_obj *o;

        if (k < 5) {
            o = jw_add(d, JW_SEN);
            o->d[0] = frand(-150, 150); o->d[1] = frand(-100, 100);
            o->d[2] = k == 0 ? o->d[0] : frand(-150, 150);
            o->d[3] = k == 0 ? o->d[1] : frand(-100, 100);
        } else if (k < 7) {
            o = jw_add(d, JW_ENKO);
            o->d[0] = frand(-150, 150); o->d[1] = frand(-100, 100);
            o->d[2] = k == 5 ? 0.0 : frand(1, 80);
            if (nextr() & 1) {
                o->d[3] = frand(0, 6.28); o->d[4] = frand(0.1, 6.0);
            } else {
                o->d[3] = 0; o->d[4] = 6.283185307179586; o->n = 1;
            }
            o->d[6] = 1.0;
        } else if (k < 9) {
            o = jw_add(d, JW_TEN);
            o->d[0] = frand(-150, 150); o->d[1] = frand(-100, 100);
        } else {
            o = jw_add(d, JW_SEN);          /* an awkward one */
            o->d[0] = frand(-9e10, 9e10); o->d[1] = frand(-9e10, 9e10);
            o->d[2] = o->d[0] + 1e-9; o->d[3] = o->d[1];
        }
    }
    app_fit();
}

static void act(void)
{
    const jw_drawing *d = app_drawing();
    const jw_view *v = app_view();
    unsigned r = nextr() % 100;

    if (r < 40 && d && v && d->ndrawn > 0) {
        const jw_obj *o = &d->obj[nextr() % (unsigned)d->ndrawn];
        int w = (int)(nextr() % 3);
        double x = w == 1 ? o->d[2] : w == 2 ? (o->d[0] + o->d[2]) / 2 : o->d[0];
        double y = w == 1 ? o->d[3] : w == 2 ? (o->d[1] + o->d[3]) / 2 : o->d[1];

        app_press(jw_sx(v, x), jw_sy(v, y), (int)(nextr() % 2));
    } else if (r < 70)
        app_press((int)(nextr() % 1264), (int)(nextr() % 741), (int)(nextr() % 2));
    else if (r < 85)
        app_move((int)(nextr() % 1264), (int)(nextr() % 741));
    else if (r < 92)
        app_key(13);
    else if (r < 96)
        app_key(27);
    else
        app_key("0123456789.-"[nextr() % 12]);
}

int main(int argc, char **argv)
{
    int seeds = argc > 1 ? atoi(argv[1]) : 6;
    static const unsigned short MENU_ONLY[] = { 32912, 32936, 32938, 32941, 32962, 32825, 32820, 32905 };
    int ci, sd, st, ncmd = JW_NBUTTONS + (int)(sizeof MENU_ONLY / sizeof MENU_ONLY[0]);

    for (ci = 0; ci < ncmd; ci++) {
        int cmd = ci < JW_NBUTTONS ? jw_btn_cmd[ci] : MENU_ONLY[ci - JW_NBUTTONS];
        int bad_here = 0, c0 = checks;

        for (sd = 0; sd < seeds && bad_here < 3; sd++) {
            rng = 1234567UL * (unsigned long)(ci + 1) + 7919UL * (unsigned long)sd + 1UL;
            make_drawing();
            app_command(cmd);
            for (st = 0; st < 40; st++) {
                jw_drawing *d = (jw_drawing *)app_drawing();
                int depth0 = jw_cmd_undo_depth();
                int can_redo0 = jw_cmd_can_redo();
                snap_t before, after;

                take(&before, d);
                act();
                d = (jw_drawing *)app_drawing();
                if (can_redo0 || jw_cmd_undo_depth() != depth0 + 1) {
                    drop(&before);
                    continue;           /* no step taken (or something to redo: skip) */
                }
                take(&after, d);
                jw_cmd_undo(d);
                checks++;
                if (!same_exact(&before, d)) {
                    printf("BAD  command %d seed %d step %d: 戻る does not give the drawing back"
                           " (%d/%d elements before, %d/%d after)\n", cmd, sd, st,
                           before.nobj, before.ndrawn, d->nobj, d->ndrawn);
                    fails++;
                    bad_here++;
                }
                jw_cmd_redo(d);
                if (!same_set(&after, d)) {
                    printf("BAD  command %d seed %d step %d: 進む does not bring the same elements back"
                           " (%d/%d expected, %d/%d)\n", cmd, sd, st, after.nobj, after.ndrawn,
                           d->nobj, d->ndrawn);
                    fails++;
                    bad_here++;
                }
                jw_cmd_undo(d);
                if (!same_exact(&before, d)) {
                    printf("BAD  command %d seed %d step %d: the second 戻る does not give the drawing back\n",
                           cmd, sd, st);
                    fails++;
                    bad_here++;
                }
                jw_cmd_redo(d);
                drop(&before);
                drop(&after);
                if (bad_here)
                    break;
            }
        }
        if (checks - c0 < 3)
            printf("note: command %d took a step only %d times in %d seeds\n", cmd, checks - c0, seeds);
    }
    (void)0;
    printf("%d commands x %d seeds, %d undo/redo pairs compared, %d bad\n", ncmd, seeds, checks, fails);
    (void)noundo;
    return fails != 0;
}
