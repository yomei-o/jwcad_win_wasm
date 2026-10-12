/* ブロックツリー (32988) -- against the original.
 *
 *   tests/btree_test.exe [tests/out/btree.png]
 *
 * The original was driven with tools/jwdraw.ps1 (the tshot:, tree, tsel:,
 * texp: steps) over two drawings made from decomp/res/blkmake.jww:
 *
 *   decomp/res/bt_two.jww    two references to one block BLK
 *   decomp/res/bt_nest2.jww  OUTER (two references to BLK) and LN (a line)
 *
 * What it listed, which buttons did what, and the .jww it saved afterwards
 * are the answers (tools/btprobe.sh runs them again):
 *
 *   bt_edit_all    選択BLK編集 on a block, the box off, one line drawn, ended
 *   bt_edit_one    the same with 選択したブロックのみに… ticked
 *   bt_edit_outer  OUTER edited: BLK, LN, OUTER -- the edited one goes last
 *   bt_edit_inner  a BLK inside OUTER: LN, BLK, OUTER -- inner then outer
 *   bt_rename_ln   BLK名変更 on LN
 *   bt_rename_outer  the same on OUTER
 *
 * The line the port draws is not compared by where it lands: the original
 * zooms in when it enters the mode (see tests/blkedit_test.c).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/draw.h"
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

static int load(const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    int ok;

    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return 0;
    }
    ok = app_open(b, n);
    free(b);
    return ok;
}

/* the window's pieces, where the original had them (client + 8, 31) */
static void win_at(int dx, int dy, int *x, int *y)
{
    rect_t w;

    app_blktree_win(&w);
    *x = w.x + 8 + dx;
    *y = w.y + 31 + dy;
}

static void press_btn(int id)
{
    static const struct { int id, x, y; } B[4] = {
        { 2545, 40, 16 }, { 2546, 130, 16 }, { 2548, 210, 16 },
        { 2547, 20, 40 } };
    int i, x, y;

    for (i = 0; i < 4; i++)
        if (B[i].id == id) {
            win_at(B[i].x, B[i].y, &x, &y);
            app_press(x, y, 0);
        }
}

/* row k of the tree: its folder (or its box with box=1) */
static void row_at(int k, int depth, int box, int *x, int *y)
{
    int ix = 2 + 19 * (depth + 1);

    win_at(box ? ix - 11 : ix + 24, 54 + 2 + 16 * k + 8, x, y);
}

static void press_row(int k, int box, int button)
{
    const ui_btrow_t *r = app_blktree_row(k);
    int x, y;

    if (!r)
        return;
    row_at(k, r->depth, box, &x, &y);
    app_press(x, y, button);
}

static void tree_is(const char *what, int n, const char *const *names)
{
    char msg[160];
    int i, ok = app_blktree_n() == n;

    for (i = 0; ok && i < n; i++) {
        const ui_btrow_t *r = app_blktree_row(i);

        ok = r && !strcmp(r->text, names[i]);
    }
    sprintf(msg, "the tree lists %s", what);
    ck(ok, msg);
    if (!ok) {
        printf("     ours:");
        for (i = 0; i < app_blktree_n(); i++)
            printf(" [%s]", app_blktree_row(i)->text);
        printf("\n");
    }
}

/* two files hold the same blocks: order, numbers, names, counts, and
   every element of a definition that is not the one drawn since */
static int same_blocks(const jw_drawing *a, const jw_drawing *b, int skip_new,
                       const char **why)
{
    int i, j;

    /* The original puts the references first when it saves, wherever they
       were laid down; so only the order they come in is compared. */
    {
        int ka = 0, kb = 0;

        for (;;) {
            while (ka < a->ndrawn && a->obj[ka].cls != JW_BLOCK)
                ka++;
            while (kb < b->ndrawn && b->obj[kb].cls != JW_BLOCK)
                kb++;
            if ((ka < a->ndrawn) != (kb < b->ndrawn)) {
                *why = "how many references";
                return 0;
            }
            if (ka >= a->ndrawn)
                break;
            if (a->obj[ka].block != b->obj[kb].block) {
                *why = "a reference points elsewhere";
                return 0;
            }
            ka++;
            kb++;
        }
    }
    if (a->nobj != b->nobj) {
        *why = "nobj";
        return 0;
    }
    for (i = a->ndrawn; i < a->nobj; i++) {
        const jw_obj *p = &a->obj[i], *q = &b->obj[i];

        if (p->cls != q->cls) {
            *why = "a class";
            return 0;
        }
        if (p->cls == JW_LIST) {
            if (p->list[0] != q->list[0] || p->n != q->n
                || strcmp(jw_str(a, p->text), jw_str(b, q->text))) {
                *why = "a definition's number, count or name";
                return 0;
            }
        } else if (p->cls == JW_BLOCK) {
            if (p->block != q->block) {
                *why = "a nested reference";
                return 0;
            }
        } else if (!skip_new || p->cls != JW_SEN
                   || p->d[1] != p->d[3] || 1) {
            /* a plain member: the colour and layer */
            if (p->color != q->color) {
                *why = "a member's colour";
                return 0;
            }
        }
        (void)j;
    }
    return 1;
}

static const jw_drawing *ref_open(jw_drawing *ref, const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);

    memset(ref, 0, sizeof *ref);
    if (!b || !jw_parse(ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    return ref;
}

/* one line, from 300,300 to 500,300, into whatever the edit is on, and the
   edit ended */
static void draw_line_and_end(void)
{
    rect_t r;
    const fb_t *fb = app_fb();

    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_SEN);
    app_press(r.x + 300, r.y + 300, 0);
    app_press(r.x + 500, r.y + 300, 0);
    app_command(JW_CMD_BLOCK_DONE);
}

static void compare_with(const char *answer, int skip_new, const char *what)
{
    jw_drawing ref;
    const char *why = "";
    char msg[200];
    int ok;

    if (!ref_open(&ref, answer))
        return;
    ok = same_blocks(app_drawing(), &ref, skip_new, &why);
    sprintf(msg, "%s comes out as the original's file does", what);
    ck(ok, msg);
    if (!ok)
        printf("     (%s)\n", why);
    jw_free(&ref);
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    static const char *const two[3] = { "", "BLK", "BLK" };
    static const char *const nest0[3] = { "", "LN", "OUTER" };
    static const char *const nest1[5] = { "", "LN", "OUTER", "BLK", "BLK" };
    int x, y;

    app_resize(1264, 741);
    fb = app_fb();

    /* ---- what it lists, two references to one block */
    if (!load("decomp/res/bt_two.jww"))
        return 1;
    ck(!app_blktree_open(), "the tree is not up to start with");
    ck(app_command(32988), "表示 > ブロックツリー puts it up");
    ck(app_blktree_open(), "which says so");
    ck(jw_cmd() == JW_CMD_HANI, "and the command is 範囲選択");
    tree_is("a nameless root and the two", 3, two);
    ck(app_blktree_row(0)->open && app_blktree_row(0)->kids
       && !app_blktree_row(1)->kids, "the root is open; a plain block has no box");
    ck(jw_draw_hl_n() == 0, "nothing is picked");

    /* ---- picking one draws it picked, and does not pick it for the drawing */
    app_paint();
    press_row(1, 0, 0);
    ck(app_blktree_row(1)->sel && !app_blktree_row(2)->sel,
       "a press on a row picks it");
    app_paint();
    ck(jw_draw_hl_n() == 1 && jw_draw_hl_path()[0] == 0,
       "the first reference is the one drawn picked");
    ck(jw_cmd_sel_count(app_drawing()) == 0 && !app_drawing()->obj[0].sel,
       "though the drawing has nothing picked");
    ck(!app_command(JW_CMD_BLOCK_FREE) && app_drawing()->ndrawn == 8,
       "so ブロック解除 does nothing, and the tree stays up");
    ck(app_blktree_open(), "(a command that only acts leaves it up)");

    /* ---- 同名BLK全検索 */
    press_btn(2545);
    ck(app_blktree_found() == 2, "同名BLK全検索 finds both");
    ck(app_blktree_row(1)->bold && app_blktree_row(2)->bold,
       "and sets them in bold");
    ck(!app_blktree_row(1)->sel && app_blktree_row(2)->sel,
       "the last one found is the one picked");
    app_paint();
    if (argc > 1) {
        rect_t w;
        unsigned int *px;
        int i, j;

        app_blktree_win(&w);
        px = (unsigned int *)malloc((size_t)w.w * w.h * sizeof *px);
        if (px) {
            for (j = 0; j < w.h; j++)
                for (i = 0; i < w.w; i++)
                    px[j * w.w + i] = fb->px[(size_t)(w.y + j) * fb->w
                                             + w.x + i];
            png_rgb(argv[1], w.w, w.h, px);
            free(px);
            printf("     wrote %s, %dx%d\n", argv[1], w.w, w.h);
        }
    }

    /* ---- a press in the drawing puts it away, and so does a command */
    {
        rect_t r;

        ui_view_rect(fb->w, fb->h, &r);
        app_press(r.x + 50, r.y + 50, 0);
        ck(!app_blktree_open(), "a press in the drawing takes it down");
        ck(jw_draw_hl_n() == 0, "and the pick with it");
    }
    app_command(32988);
    app_command(32771);
    ck(!app_blktree_open(), "so does a command that sets the command");

    /* ---- 選択BLK編集, with the box off and on */
    ck(load("decomp/res/bt_two.jww"), "again");
    app_command(32988);
    press_row(1, 0, 0);
    press_btn(2546);
    ck(!app_blktree_open() && jw_cmd_block_editing(),
       "選択BLK編集 starts ブロック編集 and the tree goes");
    draw_line_and_end();
    compare_with("decomp/res/bt_edit_all.jww", 1, "editing every BLK");

    ck(load("decomp/res/bt_two.jww"), "again");
    app_command(32988);
    press_row(1, 0, 0);
    press_btn(2547);
    ck(app_blktree_all(), "the box ticks");
    press_btn(2546);
    draw_line_and_end();
    compare_with("decomp/res/bt_edit_one.jww", 1,
                 "editing the picked BLK only");

    /* ---- a block inside a block */
    ck(load("decomp/res/bt_nest2.jww"), "the nested drawing");
    app_command(32988);
    tree_is("LN and OUTER under the root, sorted by name", 3, nest0);
    ck(app_blktree_row(2)->kids && !app_blktree_row(2)->open,
       "OUTER has a box, shut");
    press_row(2, 1, 0);
    tree_is("the two BLK under OUTER once its box is pressed", 5, nest1);
    ck(app_blktree_row(2)->open, "which is open now");
    press_row(3, 0, 0);
    app_paint();
    ck(jw_draw_hl_n() == 2, "the picked BLK is on a path of two");
    press_btn(2546);
    draw_line_and_end();
    compare_with("decomp/res/bt_edit_inner.jww", 1,
                 "editing a BLK inside OUTER");

    ck(load("decomp/res/bt_nest2.jww"), "the nested drawing again");
    app_command(32988);
    press_row(2, 0, 0);
    press_btn(2546);
    draw_line_and_end();
    compare_with("decomp/res/bt_edit_outer.jww", 1, "editing OUTER");

    /* ---- ブロック名変更 */
    ck(load("decomp/res/bt_nest2.jww"), "the nested drawing once more");
    app_command(32988);
    press_row(1, 0, 0);
    press_btn(2548);
    ck(app_blkname_open(), "ブロック名変更 asks for a name");
    {
        const char *t = "NEWLN";

        while (*t)
            app_key(*t++);
        app_key(13);
    }
    ck(!app_blkname_open(), "Enter ends it");
    ck(app_blktree_open(), "the tree is still up");
    ck(!strcmp(app_blktree_row(1)->text, "NEWLN") && app_blktree_row(1)->bold
       && app_blktree_row(1)->sel && app_blktree_found() == 1,
       "with the new name found, bold and picked");
    compare_with("decomp/res/bt_rename_ln.jww", 1, "renaming LN");

    ck(load("decomp/res/bt_nest2.jww"), "the nested drawing, the last time");
    app_command(32988);
    press_row(2, 0, 0);
    press_btn(2548);
    {
        const char *t = "NEWOUT";

        while (*t)
            app_key(*t++);
        app_key(13);
    }
    ck(!strcmp(app_blktree_row(2)->text, "NEWOUT"),
       "OUTER is NEWOUT, and sorts after LN");
    compare_with("decomp/res/bt_rename_outer.jww", 1, "renaming OUTER");

    (void)x;
    (void)y;
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
