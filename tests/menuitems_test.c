/* The 表示 and ファイル menu items that had done nothing, held to what the
 * original does with them (tools/jwdraw.ps1, 2026-10-12; tmp/menu_report.md):
 *
 *   Direct2D (33037)        a switch; ANTIALIAS (33041) is greyed until it is on
 *   ブロックツリー半透明化 (32995)  a switch; turning it on asks 透過率
 *   ダイアログボックス (32953)  asks "...初期状態にします。 よろしいですか？"
 *   タグジャンプ (32967)    greyed until one text is picked; then asks the
 *                            front end for the file the text names
 *   SPEED Data 入力 (33032)  greyed: the SPEED program is not there
 *
 *   tests/menuitems_test.exe
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

int main(void)
{
    const fb_t *fb;
    jw_drawing *d;
    jw_obj *o;

    app_resize(1264, 741);
    fb = app_fb();
    app_new();
    app_paint();

    /* Direct2D and ANTIALIAS */
    ck(!(app_menu_state(33037) & 1), "Direct2D starts unticked");
    ck(app_menu_state(33041) & 2, "ANTIALIAS is greyed with Direct2D off");
    ck(!app_command(33041), "and does nothing then");
    ck(app_command(33037) && (app_menu_state(33037) & 1),
       "Direct2D ticks");
    ck(!(app_menu_state(33041) & 2) && !(app_menu_state(33041) & 1),
       "which wakes ANTIALIAS");
    ck(app_command(33041) && (app_menu_state(33041) & 1),
       "ANTIALIAS ticks");
    app_command(33037);
    ck(!(app_menu_state(33037) & 1) && (app_menu_state(33041) & 2),
       "Direct2D off greys ANTIALIAS again");

    /* ブロックツリー半透明化 */
    ck(!(app_menu_state(32995) & 1), "半透明化 starts off");
    ck(app_command(32995) && (app_menu_state(32995) & 1),
       "turning it on ticks it");
    ck(app_tdlg_tpl() == 384, "and asks 透過率");
    app_key('1');
    app_key('2');
    app_key('8');
    app_key(13);
    ck(!app_tdlg_open() || app_tdlg_tpl() != 384, "Enter ends it");
    ck(app_menu_state(32995) & 1, "and it stays on");
    app_command(32988);                 /* the tree, seen through */
    app_paint();
    ck(app_blktree_open(), "the tree comes up with it on");
    app_command(32995);
    ck(!(app_menu_state(32995) & 1) && app_tdlg_tpl() != 384,
       "turning it off asks nothing");
    app_paint();

    /* ダイアログボックス */
    {
        rect_t w0, w1;

        app_command(32988);
        app_blktree_win(&w0);
        ck(app_command(32953) && app_modal(), "ダイアログボックス asks");
        app_key(27);
        ck(!app_modal(), "Esc says no");
        ck(app_command(32953), "again");
        app_key(13);
        ck(!app_modal(), "Enter says yes");
        app_blktree_win(&w1);
        ck(w0.x == w1.x && w0.y == w1.y,
           "and the tree window goes back where it first appears");
    }

    /* タグジャンプ */
    ck(app_menu_state(32967) & 2, "タグジャンプ is greyed with nothing picked");
    ck(!app_command(32967), "and does nothing");
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_MOJI);
    ck(o != 0, "a text is added");
    if (o) {
        o->text = jw_add_str(d, "tagtarget.jww");
        o->sel = 1;
        ck(!(app_menu_state(32967) & 2), "picked, it wakes up");
        ck(app_command(32967), "and takes the command");
        ck(app_take_action() == JW_ACT_TAG
           && !strcmp(app_tag_name(), "tagtarget.jww"),
           "the front end is asked for the file the text names");
        o = jw_add(d, JW_SEN);
        if (o)
            o->sel = 1;
        ck(app_menu_state(32967) & 2, "with a second thing picked it is greyed");
    }

    /* SPEED Data 入力 */
    ck((app_menu_state(33032) & 2) && !app_command(33032),
       "SPEED Data 入力 is greyed and does nothing");

    (void)fb;
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
