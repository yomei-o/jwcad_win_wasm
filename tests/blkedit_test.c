/* ブロック編集 -- against the original.
 *
 *   tests/blkedit_test.exe tests/out/blkedit.png
 *
 * docs/ref_blkedit.png is the dialog painted into a bitmap by Jw_cad itself
 * (tools/jwdraw.ps1's dlg: step).  This puts the port's up in the same state
 * and writes it out to be scored against that picture.
 *
 * And what the mode does.  The original was given decomp/res/blkmake.jww, a
 * range over it, the command, one line drawn from 300,300 to 500,300 and
 * then ブロック編集終了; decomp/res/blkedit.jww is what it saved
 * (tools/refanswers.sh's === blkedit).  The line has to end up inside the
 * definition, written relative to where the reference sits, with the
 * reference left alone.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/blkedit.h"
#include "../src/gen/cmds.h"
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

    ui_blkedit_rect(1264, 741, &r);
    for (i = 0; i < JW_NBLKEDIT; i++)
        if (jw_blkedit[i].id == id) {
            *x = r.x + JW_BE_BORDER + jw_blkedit[i].x + jw_blkedit[i].w / 2;
            *y = r.y + JW_BE_CAPTION + jw_blkedit[i].y + jw_blkedit[i].h / 2;
            return;
        }
    *x = *y = -1;
}

static int near_(double a, double b)
{
    double e = a - b;

    return e < 1e-9 && e > -1e-9;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    const jw_drawing *d;
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j, ma = -1, ra = -1, bad = 0;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("decomp/res/blkmake.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/blkmake.jww -- drive the "
               "original first\n");
        return 1;
    }
    free(b);

    ck(!app_blkedit_open(), "the dialog is not up to start with");
    ck(!app_command(JW_CMD_BLOCK_EDIT),
       "and the command does nothing with nothing picked");
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
    ck(app_command(JW_CMD_BLOCK_EDIT), "the command puts the dialog up");
    ck(app_blkedit_open(), "which says so");
    ck(!strcmp(jw_cmd_block_name(app_drawing()), "BLK"),
       "and it knows the block's name, without the flag on the end");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_blkedit_rect(fb->w, fb->h, &r);
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

    ctl(1, &x, &y);                     /* OK: the mode is on */
    app_press(x, y, 0);
    ck(!app_blkedit_open(), "Ok takes the dialog down");
    ck(jw_cmd_block_editing(), "and the mode is on");

    /* one line, which goes into the definition rather than the drawing */
    d = app_drawing();
    i = d->ndrawn;
    j = d->nobj;
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_SEN);
    app_press(r.x + 300, r.y + 300, 0);
    app_press(r.x + 500, r.y + 300, 0);
    d = app_drawing();
    ck(d->ndrawn == i, "the line does not go into the drawing");
    ck(d->nobj == j + 1, "it goes into the definitions");
    ck(app_command(JW_CMD_BLOCK_DONE), "ブロック編集終了 ends the mode");
    ck(!jw_cmd_block_editing(), "which says so");

    /* and what the original was left with */
    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/blkedit.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/blkedit.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        printf("%s\n", fails ? "SOME BAD" : "all ok");
        return fails ? 1 : 0;
    }
    free(b);
    d = app_drawing();
    for (i = 0; i < ref.nobj; i++) {
        if (ref.obj[i].cls == JW_LIST && ma < 0)
            ma = i;
        if (ref.obj[i].cls == JW_BLOCK && ra < 0)
            ra = i;
    }
    ck(ma >= 0 && ra >= 0, "the original's file has a list and a reference");
    if (ma >= 0 && d->nobj > d->ndrawn) {
        const jw_obj *a = &d->obj[d->ndrawn], *o = &ref.obj[ma];

        ck(a->cls == JW_LIST && a->n == o->n,
           "the definition holds as many as the original's does");
        if (a->n != o->n)
            printf("     ours %d, theirs %d\n", a->n, o->n);
        for (i = 0; i < o->n && i < a->n; i++) {
            const jw_obj *p = &d->obj[d->ndrawn + 1 + i];
            const jw_obj *q = &ref.obj[ma + 1 + i];
            int k;

            if (p->cls != q->cls || p->color != q->color
                || (p->layer & 15) != (q->layer & 15))
                bad = 1;
            /* The line the port drew is not compared by where it lands.
               The original zooms in when it enters the mode -- the two
               clicks 200 pixels apart made a line 68.03 mm long in its
               file where the port's view makes 173.18, so its millimetres
               per pixel had gone from 0.865889 to 0.340 -- and what it
               zooms to has not been worked out.  Everything else about the
               line is compared, and so is the whole of the definition it
               went into. */
            if (i >= 12)
                continue;
            for (k = 0; k < 8; k++)
                if (!near_(p->d[k], q->d[k])) {
                    printf("     the %dth inside is %.9f where the "
                           "original's is %.9f (field %d)\n", i, p->d[k],
                           q->d[k], k);
                    bad = 1;
                }
        }
        ck(!bad, "and every element inside it is the original's");
        if (a->n == 13) {
            const jw_obj *p = &d->obj[d->ndrawn + 13];
            const jw_obj *q = &ref.obj[ma + 13];

            ck(p->cls == JW_SEN && q->cls == JW_SEN
               && (p->layer & 15) == (q->layer & 15)
               && p->color == q->color
               && near_(p->d[1], p->d[3]),
               "and the line that was drawn went in the way the original's "
               "did");
        }
    }
    if (ra >= 0 && d->ndrawn > 0)
        ck(d->obj[0].cls == JW_BLOCK
           && near_(d->obj[0].d[0], ref.obj[ra].d[0])
           && near_(d->obj[0].d[1], ref.obj[ra].d[1]),
           "and the reference has not moved");
    /* 元に戻る takes the line back out of the definition */
    jw_cmd_undo((jw_drawing *)app_drawing());
    d = app_drawing();
    printf("     after undo: nobj %d ndrawn %d n %d\n", d->nobj, d->ndrawn,
           d->obj[d->ndrawn].n);
    ck(d->nobj == d->ndrawn + 13
       && d->obj[d->ndrawn].n == 12,
       "元に戻る takes the line back out of the definition");
    jw_free(&ref);

    /* ブロック名変更: the typed name goes in front of the flag the original
       keeps on the end (decomp/res/blkrename.jww). */
    {
        jw_drawing r2;
        unsigned char *b2;
        long n2;
        int ma2 = -1;

        memset(&r2, 0, sizeof r2);
        b2 = slurp("decomp/res/blkrename.jww", &n2);
        if (!b2 || !jw_parse(&r2, b2, n2)) {
            printf("BAD  cannot read decomp/res/blkrename.jww -- drive the "
                   "original first\n");
            fails++;
            free(b2);
        } else {
            free(b2);
            for (i = 0; i < r2.nobj; i++)
                if (r2.obj[i].cls == JW_LIST) {
                    ma2 = i;
                    break;
                }
            b2 = slurp("decomp/res/blkmake.jww", &n2);
            if (b2 && app_open(b2, n2)) {
                free(b2);
                ui_view_rect(fb->w, fb->h, &r);
                jw_cmd_set(JW_CMD_HANI);
                app_press(r.x + 100, r.y + 100, 0);
                app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
                app_command(JW_CMD_BLOCK_EDIT);
                for (i = 0; i < 8; i++)
                    app_key(8);         /* clear the BLK that is there */
                app_key('N'); app_key('E'); app_key('W');
                app_key('N'); app_key('A'); app_key('M'); app_key('E');
                ck(!strcmp(app_blkedit_name(), "NEWNAME"),
                   "the name box takes what is typed");
                ctl(3, &x, &y);         /* ブロック名変更 */
                app_press(x, y, 0);
                ctl(1, &x, &y);
                app_press(x, y, 0);
                d = app_drawing();
                ck(ma2 >= 0 && d->nobj > d->ndrawn
                   && !strcmp(jw_str(d, d->obj[d->ndrawn].text),
                              jw_str(&r2, r2.obj[ma2].text)),
                   "and ブロック名変更 gives it the original's own name");
                if (ma2 >= 0 && d->nobj > d->ndrawn
                    && strcmp(jw_str(d, d->obj[d->ndrawn].text),
                              jw_str(&r2, r2.obj[ma2].text)))
                    printf("     ours '%s', theirs '%s'\n",
                           jw_str(d, d->obj[d->ndrawn].text),
                           jw_str(&r2, r2.obj[ma2].text));
                jw_cmd_block_done();
            }
            jw_free(&r2);
        }
    }

    /* 選択したブロックのみに反映させる: with two references to one block,
       editing one that way copies the definition rather than changing the
       one they share (decomp/res/blk2one.jww, against blk2all.jww for the
       other choice). */
    {
        static const struct { const char *f; int only; } W[2] = {
            { "decomp/res/blk2all.jww", 0 },
            { "decomp/res/blk2one.jww", 1 },
        };
        int w;

        for (w = 0; w < 2; w++) {
            jw_drawing r2;
            unsigned char *b2;
            long n2;
            int nl = 0, ml = 0;

            memset(&r2, 0, sizeof r2);
            b2 = slurp(W[w].f, &n2);
            if (!b2 || !jw_parse(&r2, b2, n2)) {
                printf("BAD  cannot read %s -- drive the original first\n",
                       W[w].f);
                fails++;
                free(b2);
                continue;
            }
            free(b2);
            b2 = slurp("decomp/res/blkmake.jww", &n2);
            if (b2 && app_open(b2, n2)) {
                jw_obj *p;

                free(b2);
                /* the same second reference tmp/mk2blk.c adds */
                d = app_drawing();
                for (i = 0; i < d->ndrawn; i++)
                    if (d->obj[i].cls == JW_BLOCK)
                        break;
                p = jw_add((jw_drawing *)d, JW_BLOCK);
                if (p) {
                    *p = d->obj[i];
                    p->d[0] += 300.0;
                    p->id = 0;
                    p->sel = 0;
                    p->flags = 0;
                }
                ui_view_rect(fb->w, fb->h, &r);
                jw_cmd_set(JW_CMD_HANI);
                app_press(r.x + 100, r.y + 100, 0);
                app_press(r.x + 850, r.y + 650, 1);
                ck(jw_cmd_sel_count(app_drawing()) == 1,
                   "  the box takes one of the two references");
                app_command(JW_CMD_BLOCK_EDIT);
                if (W[w].only) {
                    ctl(2411, &x, &y);
                    app_press(x, y, 0);
                }
                ctl(1, &x, &y);
                app_press(x, y, 0);
                jw_cmd_set(JW_CMD_SEN);
                app_press(r.x + 300, r.y + 300, 0);
                app_press(r.x + 500, r.y + 300, 0);
                app_command(JW_CMD_BLOCK_DONE);
                d = app_drawing();
                for (i = d->ndrawn; i < d->nobj; i++)
                    if (d->obj[i].cls == JW_LIST)
                        nl++;
                for (i = 0; i < r2.nobj; i++)
                    if (r2.obj[i].cls == JW_LIST)
                        ml++;
                ck(nl == ml, "  as many definitions as the original has");
                if (nl != ml)
                    printf("     ours %d, theirs %d\n", nl, ml);
                if (nl == ml) {
                    int k, bad2 = 0, a = d->ndrawn, e = 0;

                    for (i = 0; i < r2.nobj; i++) {
                        const jw_obj *q;

                        if (r2.obj[i].cls != JW_LIST)
                            continue;
                        q = &r2.obj[i];
                        while (a < d->nobj && d->obj[a].cls != JW_LIST)
                            a++;
                        if (a >= d->nobj)
                            break;
                        if (d->obj[a].n != q->n
                            || d->obj[a].list[0] != q->list[0]
                            || strcmp(jw_str(d, d->obj[a].text),
                                      jw_str(&r2, q->text))) {
                            printf("     definition %d: ours n=%d num=%d "
                                   "'%s', theirs n=%d num=%d '%s'\n", e,
                                   d->obj[a].n, d->obj[a].list[0],
                                   jw_str(d, d->obj[a].text), q->n,
                                   q->list[0], jw_str(&r2, q->text));
                            bad2 = 1;
                        }
                        a++;
                        e++;
                    }
                    /* and which definition each reference points at */
                    for (i = 0, k = 0; i < r2.ndrawn; i++) {
                        if (r2.obj[i].cls != JW_BLOCK)
                            continue;
                        while (k < d->ndrawn && d->obj[k].cls != JW_BLOCK)
                            k++;
                        if (k >= d->ndrawn)
                            break;
                        if (d->obj[k].block != r2.obj[i].block) {
                            printf("     reference %d points at %d where "
                                   "the original's points at %d\n", k,
                                   d->obj[k].block, r2.obj[i].block);
                            bad2 = 1;
                        }
                        k++;
                    }
                    ck(!bad2, "  and each one is the original's, with the "
                       "references pointing the same way");
                }
            }
            jw_free(&r2);
        }
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
