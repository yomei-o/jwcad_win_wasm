/* 範囲選択, 複写 and 移動.
 *
 *   tests/sel_test.exe [drawing.jww]
 *
 * What the original does, and what is checked here:
 *   - two clicks make a box and everything inside it whole is picked, with
 *     bit 1 of the element's flags -- the same flag the original writes, and
 *     the same rule: a line that only crosses the box is left alone.  Both
 *     came out of driving Jw_cad over Test5 and reading the file it saved;
 *   - the second click's button decides the texts: (L) leaves them out,
 *     (R) takes them (string 5326);
 *   - 選択確定 (the bar's button 1120) takes 基準点 from the mouse, and then
 *     every click leaves a copy that far away -- three clicks in the
 *     original left three copies, at one, two and three times the step;
 *   - 移動 moves the picked elements instead of copying them;
 *   - 元に戻る takes either back.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int nsel(void)
{
    return jw_cmd_sel_count(app_drawing());
}

/* how many elements of the drawing sit whole inside the screen box */
static int inside(int x0, int y0, int x1, int y1, int with_text)
{
    const jw_drawing *d = app_drawing();
    const jw_view *v = app_view();
    double a0 = v->ox + (x0 - v->bx) / v->scale;
    double a1 = v->ox + (x1 - v->bx) / v->scale;
    double b0 = v->oy + (v->by - y1) / v->scale;
    double b1 = v->oy + (v->by - y0) / v->scale;
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++) {
        double p0, q0, p1, q1;
        if (d->obj[i].cls == JW_MOJI && !with_text)
            continue;
        jw_obj_box(&d->obj[i], &p0, &q0, &p1, &q1);
        if (p0 >= a0 && p1 <= a1 && q0 >= b0 && q1 <= b1)
            n++;
    }
    return n;
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
    const char *path = argc > 1 ? argv[1] : "orig/Test5.jww";
    const jw_drawing *d;
    FILE *f = fopen(path, "rb");
    unsigned char *b;
    long n;
    int before, i, moved = 0;
    double ox = 0, oy = 0;

    if (!app_resize(1264, 741)) {
        printf("BAD  out of memory\n");
        return 1;
    }
    if (!f) {
        printf("BAD  cannot open %s\n", path);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
        printf("BAD  cannot read %s\n", path);
        return 1;
    }
    fclose(f);
    if (!app_open(b, n)) {
        printf("BAD  %s: %s\n", path, app_error());
        return 1;
    }
    free(b);

    /* 複写 starts by asking for a range */
    jw_cmd_set(JW_CMD_FUKUSHA);
    ck(jw_cmd() == JW_CMD_FUKUSHA, "複写 is the command");
    ck(nsel() == 0, "and nothing is picked yet");
    app_move(300, 200);
    app_press(300, 200, 0);
    app_move(900, 600);
    ck(nsel() == 0, "one corner picks nothing on its own");
    {   /* the box is shown while it is being dragged */
        double a, b2, c, e;
        ck(jw_cmd_sel_box(&a, &b2, &c, &e), "and the box is drawn meanwhile");
    }
    app_press(900, 600, 0);
    ck(nsel() > 0, "the second corner picks what is inside it");
    ck(nsel() == inside(300, 200, 900, 600, 0),
       "everything that fits in it whole, and nothing else");
    ck(inside(300, 200, 900, 600, 1) > inside(300, 200, 900, 600, 0)
       ? nsel() < inside(300, 200, 900, 600, 1) : 1,
       "the texts inside it are left out -- (L)文字を除く");

    /* the same box with the right button takes the texts too */
    {
        int with_l = nsel();
        jw_cmd_set(JW_CMD_FUKUSHA);
        ck(nsel() == with_l, "entering a command leaves the selection alone");
        app_move(300, 200);
        app_press(300, 200, 0);
        ck(nsel() == 0, "starting a new box is what drops it");
        app_move(900, 600);
        app_press(900, 600, 1);
        ck(nsel() == inside(300, 200, 900, 600, 1),
           "(R) on the second corner takes the texts as well");
        ck(nsel() >= with_l, "which is at least as many as (L) took");
    }

    /* 選択確定 and then two copies */
    jw_cmd_set(JW_CMD_FUKUSHA);
    app_move(300, 200);
    app_press(300, 200, 0);
    app_move(900, 600);
    app_press(900, 600, 0);
    d = app_drawing();
    before = d->ndrawn;
    ck(jw_cmd_bar_enabled(d, 1120) == 1, "選択確定 comes alive");
    /* and the press goes through the bar the way a click does: 選択確定 is
       at 491,5 89x24 on 複写's bar (src/gen/bars.h, read off the original) */
    ck(ui_bar_hit(491 + 44, 5 + 12) == 1120, "its button is where it is drawn");
    app_move(500, 400);                 /* 基準点 -- the mouse is here */
    ck(app_press(491 + 44, 5 + 12, 0) == 1, "and pressing it is taken");
    {
        double dx, dy;
        app_move(600, 450);
        ck(jw_cmd_sel_ghost(&dx, &dy), "the selection follows the mouse");
    }
    {   /* remember where the first picked element was */
        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].flags & 2) {
                ox = d->obj[i].d[0];
                oy = d->obj[i].d[1];
                break;
            }
    }
    app_move(600, 450);
    app_press(600, 450, 0);
    d = app_drawing();
    ck(d->ndrawn == before + nsel(), "a click copies every picked element");
    {
        const jw_view *v = app_view();
        double dx = (600 - 500) / v->scale, dy = -(450 - 400) / v->scale;
        const jw_obj *o = &d->obj[before];
        ck(fabs(o->d[0] - (ox + dx)) < 1e-9 && fabs(o->d[1] - (oy + dy)) < 1e-9,
           "as far from it as the click is from 基準点");
        ck(!(o->flags & 2), "the copy itself is not picked");
    }
    {   /* a second click, measured from the same 基準点 */
        int was = d->ndrawn;
        const jw_view *v = app_view();
        double dx = (700 - 500) / v->scale, dy = -(500 - 400) / v->scale;
        app_move(700, 500);
        app_press(700, 500, 0);
        d = app_drawing();
        ck(d->ndrawn == was + nsel(), "a second click leaves a second copy");
        ck(fabs(d->obj[was].d[0] - (ox + dx)) < 1e-9
           && fabs(d->obj[was].d[1] - (oy + dy)) < 1e-9,
           "twice as far, because 基準点 has not moved");
    }
    {   /* 元に戻る takes the last copy back */
        int was = d->ndrawn, k = nsel();
        jw_cmd_undo((jw_drawing *)d);
        d = app_drawing();
        ck(d->ndrawn == was - k, "元に戻る takes a whole copy back");
    }

    /* 移動 puts the picked elements somewhere else */
    jw_cmd_set(JW_CMD_IDOU);
    app_move(300, 200);
    app_press(300, 200, 0);
    app_move(900, 600);
    app_press(900, 600, 0);
    d = app_drawing();
    before = d->ndrawn;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].flags & 2) {
            ox = d->obj[i].d[0];
            oy = d->obj[i].d[1];
            moved = i;
            break;
        }
    app_move(500, 400);
    jw_cmd_bar((jw_drawing *)d, 1120);
    app_move(650, 470);
    app_press(650, 470, 0);
    d = app_drawing();
    ck(d->ndrawn == before, "移動 adds nothing");
    {
        const jw_view *v = app_view();
        double dx = (650 - 500) / v->scale, dy = -(470 - 400) / v->scale;
        ck(fabs(d->obj[moved].d[0] - (ox + dx)) < 1e-9
           && fabs(d->obj[moved].d[1] - (oy + dy)) < 1e-9,
           "it moves them by the same distance");
        ck((d->obj[moved].flags & 2) != 0, "and they stay picked");
    }
    jw_cmd_undo((jw_drawing *)d);
    d = app_drawing();
    ck(fabs(d->obj[moved].d[0] - ox) < 1e-9
       && fabs(d->obj[moved].d[1] - oy) < 1e-9, "元に戻る puts them back");

    /* 範囲選択 settles a range and 消去 empties it -- what the original
       does when the two are used one after the other */
    {
        int was, k, j, btn = -1, bx, by;
        jw_cmd_set(JW_CMD_HANI);
        app_move(300, 200);
        app_press(300, 200, 0);
        app_move(900, 600);
        app_press(900, 600, 0);
        k = nsel();
        ck(k > 0, "範囲選択 picks a range of its own");
        app_move(500, 400);
        ck(jw_cmd_bar((jw_drawing *)d, 1120) == 1, "and it can be settled");
        ck(nsel() == k, "which leaves the same elements picked");
        d = app_drawing();
        was = d->ndrawn;
        for (j = 0; j < JW_NBUTTONS; j++)
            if (jw_btn_cmd[j] == JW_CMD_SHOUKYO)
                btn = j;
        ck(btn >= 0, "消去 has a button");
        bx = jw_buttons[btn].x + BTN_W / 2;
        by = jw_buttons[btn].y + BTN_H / 2;
        app_press(bx, by, 0);
        d = app_drawing();
        ck(d->ndrawn == was - k, "pressing 消去 takes the whole range out");
        ck(nsel() == 0, "and nothing is left picked");
        jw_cmd_undo((jw_drawing *)d);
        d = app_drawing();
        ck(d->ndrawn == was, "元に戻る brings every one of them back");
    }

    /* 選択解除 */
    jw_cmd_set(JW_CMD_HANI);
    app_move(300, 200);
    app_press(300, 200, 0);
    app_move(900, 600);
    app_press(900, 600, 0);
    ck(nsel() > 0, "a range to drop again");
    ck(jw_cmd_bar((jw_drawing *)d, 1067) == 1, "選択解除 can be pressed");
    ck(nsel() == 0, "and nothing is picked after it");

    /* 範囲外選択 (1334): the box takes what lies wholly outside it, texts
       and all.  The original was given the same box on Test5 and then 消去,
       and decomp/res/selout.jww is what was left. */
    {
        jw_drawing ref;
        unsigned char *b2;
        long n2;
        const jw_drawing *d2;
        int k, nr = 0, nm = 0;

        memset(&ref, 0, sizeof ref);
        b2 = slurp("decomp/res/selout.jww", &n2);
        if (!b2 || !jw_parse(&ref, b2, n2)) {
            printf("BAD  cannot read decomp/res/selout.jww -- drive the "
                   "original first\n");
            fails++;
        } else {
            const fb_t *fb = app_fb();
            rect_t r;

            free(b2);
            b2 = slurp("orig/Test5.jww", &n2);
            if (b2 && app_open(b2, n2)) {
                free(b2);
                ui_view_rect(fb->w, fb->h, &r);
                jw_cmd_set(JW_CMD_HANI);
                ck(jw_cmd_bar((jw_drawing *)app_drawing(), 1334) == 1,
                   "範囲外選択 can be pressed");
                ck(jw_cmd_bar_check(1334) == 1, "and goes down");
                app_press(r.x + 250, r.y + 250, 0);
                app_press(r.x + 850, r.y + 550, 0);
                ck(nsel() > 0, "the box picks what is outside it");
                app_command(JW_CMD_SHOUKYO);
                d2 = app_drawing();
                for (k = 0; k < ref.ndrawn; k++)
                    if (ref.obj[k].cls == JW_SEN || ref.obj[k].cls == JW_MOJI)
                        nr++;
                for (k = 0; k < d2->ndrawn; k++)
                    if (d2->obj[k].cls == JW_SEN || d2->obj[k].cls == JW_MOJI)
                        nm++;
                /* the original leaves six memo texts of its own behind */
                ck(nm == nr - 6, "and 消去 leaves what the original left");
                if (nm != nr - 6)
                    printf("     ours %d, the original's %d (less its six "
                           "memos)\n", nm, nr - 6);
            }
            jw_free(&ref);
        }
    }

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
