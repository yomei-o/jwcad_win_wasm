/* The menu the browser build draws for itself.
 *
 *   tests/menu_test.exe [tests/out/menu.png]
 *
 * The native window's menu is Windows' own -- src/main_win32.c hands it the
 * tree and it does the rest -- so there is nothing to check there beyond
 * "it built".  The browser has no window, so the port draws the popup itself,
 * and this is what says it works: the right names come out of the right
 * places, a submenu opens where its parent is, and pressing an item arrives
 * at app_command() as the id the original's own menu resource gives it.
 *
 * The picture it leaves is for looking at, not for scoring.  Like the caption
 * and the window frame, a popup is a themed window on the original -- rounded,
 * shadowed, in a font the port has no licence to -- so pixels cannot match.
 * What is copied from the original is the measurements: tools/jwdraw.ps1's
 * `menu:` step opened all seven of its popups and they came back 22 rows an
 * item, 9 a separator, 3 of border, at y = -1 of the frame's client.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/menu.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* The nth name on the bar, in the chrome's own coordinates. */
static int name_x(int i)
{
    return jw_menu[i].x + 4;
}

#define MENU_Y (JW_CAPTION_H + JW_MENU_H / 2)

/* Find an entry of the tree by command id. */
static int by_id(int id)
{
    int i;

    for (i = 0; i < JW_NMENU_TREE; i++)
        if (jw_menu_tree[i].id == id && jw_menu_tree[i].kind == 0)
            return i;
    return -1;
}

/* Where that entry's row is on the screen, once its popup is open: walk the
   popup and count rows the way ui.c does. */
static int row_mid(int top, int want, int *outx)
{
    int y = JW_POPUP_BORDER, i, n = -1, seen = 0;

    *outx = jw_menu[top].x - 8 + JW_POPUP_TEXT_X;
    for (i = 0; i < JW_NMENU_TREE; i++) {
        if (jw_menu_tree[i].depth == 0) {
            n++;
            seen = n == top;
            continue;
        }
        if (!seen || jw_menu_tree[i].depth != 1)
            continue;
        if (i == want)
            return y + JW_POPUP_ITEM_H / 2;
        y += jw_menu_tree[i].kind == 2 ? JW_POPUP_SEP_H : JW_POPUP_ITEM_H;
    }
    return -1;
}

int main(int argc, char **argv)
{
    const char *out = argc > 1 ? argv[1] : "tests/out/menu.png";
    const fb_t *fb;
    int i, x, y;

    app_new();
    app_chrome(1);
    if (!app_resize(1264, 741)) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }

    ck(ui_popup_top() < 0, "nothing is open to start with");

    /* 表示(V) is the third name, and its popup is the short one: seven items
       and no separators, which is what the original's came back as. */
    ck(app_chrome_press(name_x(2), MENU_Y) == 1, "pressing 表示 opens it");
    ck(ui_popup_top() == 2, "and it is the one that is open");
    ck(app_chrome_press(name_x(2), MENU_Y) == 1, "pressing it again is taken");
    ck(ui_popup_top() < 0, "and shuts it");

    /* ファイル(F) -- 新規作成 is in it, and pressing it starts a drawing. */
    ck(app_chrome_press(name_x(0), MENU_Y) == 1, "ファイル opens");
    i = by_id(57600);                   /* 新規作成 */
    ck(i >= 0, "新規作成 is in the tree");
    y = row_mid(0, i, &x);
    ck(y > 0, "and its row is in the open popup");
    ck(ui_popup_in(x, y), "which is inside the popup");
    ck(ui_popup_hit(x, y) == i, "the point lands on it");
    ck(ui_popup_press(x, y) == 57600, "and pressing it gives the original's id");

    /* app_press is the way in for the browser: it runs the item and shuts the
       menu, the same click doing nothing else. */
    {
        const jw_drawing *d;
        jw_cmd_set(JW_CMD_ENKO);
        ck(app_press(x, y, 0) == 1, "app_press takes it");
        ck(ui_popup_top() < 0, "the menu is shut afterwards");
        d = app_drawing();
        ck(d && d->ndrawn == 0, "新規作成 left an empty drawing");
    }

    /* A press away from an open popup shuts it and does nothing else: the
       command must not change, and the drawing must not be touched. */
    ck(app_chrome_press(name_x(0), MENU_Y) == 1, "ファイル opens again");
    jw_cmd_set(JW_CMD_SEN);
    ck(app_press(1100, 600, 0) == 1, "a press outside is taken");
    ck(ui_popup_top() < 0, "and shuts the menu");
    ck(jw_cmd() == JW_CMD_SEN, "without changing the command");
    ck(app_drawing()->ndrawn == 0, "or drawing anything");

    /* A submenu: ファイル has ファイル操作 in it, which opens rather than runs. */
    ck(app_chrome_press(name_x(0), MENU_Y) == 1, "ファイル opens once more");
    for (i = 0; i < JW_NMENU_TREE; i++)
        if (jw_menu_tree[i].depth == 1 && jw_menu_tree[i].kind == 1)
            break;
    ck(i < JW_NMENU_TREE, "it has a submenu in it");
    y = row_mid(0, i, &x);
    ck(ui_popup_press(x, y) == 0, "pressing that runs nothing");
    {
        /* its children are now reachable, off to the right of the parent */
        int child = i + 1;
        ck(jw_menu_tree[child].depth == 2, "the submenu has children");
        ck(ui_popup_hit(x, y) == i, "and the parent is still under the point");
    }

    /* The picture, with 設定 open, for looking at. */
    ck(app_chrome_press(name_x(4), MENU_Y) == 1, "設定 opens for the picture");
    app_paint();
    fb = app_fb();
    if (!png_rgb(out, fb->w, fb->h, fb->px)) {
        fprintf(stderr, "cannot write %s\n", out);
        return 1;
    }
    printf("     wrote %s (%dx%d)\n", out, fb->w, fb->h);

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
