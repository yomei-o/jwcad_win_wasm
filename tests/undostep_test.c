/* One step forward and one step back, command by command.
 *
 *   tests/undostep_test.exe
 *
 * tests/cmdfuzz_test.c watches every step its random walk takes and undoes
 * it at once, but a random walk finishes the drawing commands -- 点, 文字,
 * 線 -- and hardly ever the ones that change what is already there: in
 * eight walks of three thousand actions it completed 複写 twice, コーナー
 * three times and 面取 twice.  Those are the ones whose 戻る has the most
 * to do (it puts erased elements back where they stood and changed ones
 * back as they were), so here each of them is walked through on purpose.
 *
 * The drawing is made here, small and known: two horizontal lines 40 apart,
 * a vertical one standing on the upper of them, and two circles below.
 * For each command:
 *
 *   - the walk has to take exactly one step (the undo stack one deeper) and
 *     change the drawing -- otherwise the walk is wrong, not the command,
 *     and it says so;
 *   - one 戻る has to give back the drawing **exactly**, element for
 *     element and in the same order (an erased element goes back where it
 *     was, so the order -- what is drawn on top of what -- is part of it);
 *   - one 進む has to bring back the same elements the step made.  Not in
 *     the same order: the original puts a step that only added elements
 *     back at the front (jw_cmd_redo), so this compares them sorted.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static jw_drawing *d;

static void at(double x, double y, int button)
{
    jw_cmd_point(d, app_view(), x, y, button);
}

static void box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

/* the small drawing every command starts from.  It is drawn on the 新規
   sheet, which is 1/100: what goes into a box is in real units, so a
   20 mm radius is typed as 2000 */
static void setup(void)
{
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar(d, 1333);            /* 水平・垂直 off */
    box(1412, "");
    at(-100.0, 0.0, 0);                 /* L1, the lower horizontal */
    at(100.0, 0.0, 0);
    at(-100.0, 40.0, 0);                /* L3, the upper one */
    at(100.0, 40.0, 0);
    at(20.0, 10.0, 0);                  /* L2, standing up through L3 */
    at(20.0, 100.0, 0);
    jw_cmd_set(JW_CMD_ENKO);
    at(60.0, -60.0, 0);                 /* C1, radius 20 */
    at(80.0, -60.0, 0);
    at(-60.0, -60.0, 0);                /* C2, radius 15 */
    at(-45.0, -60.0, 0);
    jw_cmd_set(JW_CMD_TEN);
}

typedef struct {
    jw_obj *obj;
    int nobj, ndrawn;
} snap_t;

static void take(snap_t *s)
{
    s->nobj = d->nobj;
    s->ndrawn = d->ndrawn;
    s->obj = (jw_obj *)malloc((size_t)(s->nobj ? s->nobj : 1) * sizeof *s->obj);
    if (s->obj && s->nobj)
        memcpy(s->obj, d->obj, (size_t)s->nobj * sizeof *s->obj);
}

static int same_exactly(const snap_t *s)
{
    return d->nobj == s->nobj && d->ndrawn == s->ndrawn
           && (!s->nobj
               || !memcmp(d->obj, s->obj, (size_t)s->nobj * sizeof *s->obj));
}

static int key_cmp(const void *a, const void *b)
{
    const jw_obj *x = (const jw_obj *)a, *y = (const jw_obj *)b;
    int i;

    if (x->cls != y->cls)
        return x->cls < y->cls ? -1 : 1;
    for (i = 0; i < 8; i++)
        if (x->d[i] != y->d[i])
            return x->d[i] < y->d[i] ? -1 : 1;
    if (x->color != y->color)
        return x->color < y->color ? -1 : 1;
    if (x->ltype != y->ltype)
        return x->ltype < y->ltype ? -1 : 1;
    if (x->layer != y->layer)
        return x->layer < y->layer ? -1 : 1;
    return 0;
}

/* the same elements, whatever their order */
static int same_elements(const snap_t *s)
{
    jw_obj *a, *b;
    int i, ok = 1;

    if (d->nobj != s->nobj)
        return 0;
    if (!s->nobj)
        return 1;
    a = (jw_obj *)malloc((size_t)s->nobj * sizeof *a);
    b = (jw_obj *)malloc((size_t)s->nobj * sizeof *b);
    if (!a || !b) {
        free(a);
        free(b);
        return 0;
    }
    memcpy(a, s->obj, (size_t)s->nobj * sizeof *a);
    memcpy(b, d->obj, (size_t)s->nobj * sizeof *b);
    qsort(a, (size_t)s->nobj, sizeof *a, key_cmp);
    qsort(b, (size_t)s->nobj, sizeof *b, key_cmp);
    for (i = 0; i < s->nobj && ok; i++)
        ok = !key_cmp(&a[i], &b[i]);
    free(a);
    free(b);
    return ok;
}

typedef void (*walk_fn)(void);

/* A walk that has to set something up before the click that takes the
   step -- 複写 and 移動 make and settle a selection first -- calls this
   just before that click.  The selection is not the step's: 戻る takes the
   copy back and leaves what was picked picked, so the drawing to compare
   with is the one as it stood then. */
static snap_t pre;
static int marked;

static void mark(void)
{
    free(pre.obj);
    take(&pre);
    marked = 1;
}

static void one(const char *name, int cmd, walk_fn walk)
{
    snap_t before, after;
    int depth;
    char msg[160];

    setup();
    jw_cmd_set(cmd);
    take(&before);
    depth = jw_cmd_undo_depth();
    marked = 0;
    walk();
    if (marked) {
        free(before.obj);
        before = pre;
        pre.obj = 0;
    }
    if (jw_cmd_undo_depth() != depth + 1 || same_exactly(&before)) {
        snprintf(msg, sizeof msg, "%s: the walk takes one step (it took %d,"
                 " and the drawing %s)", name, jw_cmd_undo_depth() - depth,
                 same_exactly(&before) ? "did not change" : "changed");
        ck(0, msg);
        free(before.obj);
        return;
    }
    take(&after);
    jw_cmd_undo(d);
    snprintf(msg, sizeof msg, "%s: one 戻る gives the drawing back exactly"
             " (%d elements)", name, before.nobj);
    ck(same_exactly(&before), msg);
    jw_cmd_redo(d);
    snprintf(msg, sizeof msg, "  and one 進む brings back the %d it had",
             after.nobj);
    ck(same_elements(&after), msg);
    /* and the 戻る after that 進む: wherever 進む put the step's elements,
       this has to take back that step and nothing else */
    jw_cmd_undo(d);
    ck(same_exactly(&before), "  and a second 戻る gives it back exactly again");
    free(before.obj);
    free(after.obj);
}

static void w_corner(void)   { at(-50.0, 0.0, 0); at(20.0, 70.0, 0); }
static void w_mentori(void)  { box(1411, "5"); at(-50.0, 40.0, 0); at(20.0, 70.0, 0); }
static void w_shinshuku(void){ at(80.0, 0.0, 0); at(150.0, 0.0, 0); }
static void w_fukusen(void)  { box(1411, "1000"); at(-50.0, 0.0, 0); at(-50.0, -20.0, 0); at(-50.0, -20.0, 0); }
static void w_erase(void)    { at(-50.0, 40.0, 1); }
static void w_cut(void)      { at(-50.0, 0.0, 0); at(-80.0, 0.0, 0); at(-20.0, 0.0, 0); }
static void w_bunkatsu(void) { box(1411, "4"); at(-50.0, 0.0, 0); at(-50.0, 40.0, 0); }
static void w_chushin(void)
{
    at(-50.0, 0.0, 0);
    at(-50.0, 40.0, 0);
    at(-100.0, 20.0, 0);
    at(100.0, 20.0, 0);
}
static void w_sekien(void)   { box(1411, "2000"); at(-50.0, 40.0, 0); at(20.0, 70.0, 0); at(45.0, 65.0, 0); }
static void w_sessen(void)   { at(80.0, -60.0, 0); at(-45.0, -60.0, 0); }
static void w_nisen(void)    { box(1412, "5"); at(-50.0, 0.0, 0); at(-80.0, 0.0, 0); at(80.0, 0.0, 0); }
static void w_houraku(void)  { at(10.0, 5.0, 0); at(30.0, 45.0, 0); }
static void w_zokuhen(void)  { at(-50.0, 0.0, 0); }
static void w_sen(void)      { at(-90.0, 80.0, 0); at(-10.0, 90.0, 0); }

/* 複写 and 移動: a box round the two horizontals, 選択確定, then where
   the selection goes */
static void w_range_and_place(void)
{
    at(-120.0, -10.0, 0);
    at(120.0, 50.0, 0);
    jw_cmd_track(0.0, 20.0);            /* the cursor is on the drawing */
    jw_cmd_bar(d, 1120);
    mark();
    at(30.0, 120.0, 0);                 /* where it goes */
}

int main(void)
{
    app_resize(1264, 741);

    one("コーナー", JW_CMD_CORNER, w_corner);
    one("面取", JW_CMD_MENTORI, w_mentori);
    one("伸縮", JW_CMD_SHINSHUKU, w_shinshuku);
    one("複線", JW_CMD_FUKUSEN, w_fukusen);
    one("消去 (R)", JW_CMD_SHOUKYO, w_erase);
    one("消去 部分消し", JW_CMD_SHOUKYO, w_cut);
    one("分割", JW_CMD_BUNKATSU, w_bunkatsu);
    one("中心線", JW_CMD_CHUSHIN, w_chushin);
    one("接円", JW_CMD_SEKIEN, w_sekien);
    one("接線", JW_CMD_SESSEN, w_sessen);
    one("２線", JW_CMD_NISEN, w_nisen);
    one("包絡", JW_CMD_HOURAKU, w_houraku);
    one("属性変更", JW_CMD_ZOKUHEN, w_zokuhen);
    one("複写", JW_CMD_FUKUSHA, w_range_and_place);
    one("移動", JW_CMD_IDOU, w_range_and_place);
    one("線", JW_CMD_SEN, w_sen);

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
