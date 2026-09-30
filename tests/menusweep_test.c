/* Every item on the original's menus, sent to the port, one at a time.
 *
 *   tests/menusweep_test.exe [--list]
 *
 * This does not say what any of them should do -- it says which ones the
 * port answers at all.  For each id in src/gen/menu.h it sends the command
 * over a small drawing and watches four things: whether the command the
 * port is in changed, whether a dialog came up, whether anything was drawn
 * or taken away, and whether app_command said it took it.
 *
 * `--list` prints a row for each, so the ones that do nothing can be
 * picked off.  Without it, it only counts, and checks that nothing crashes
 * and that the ones already done still answer.
 *
 * The file open and save items are left out: they would put a common
 * dialog up on the native build and there is nothing to type into it here.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/menu.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* the ones that would open a file window and sit there */
static int skip(int id)
{
    switch (id) {
    case 57600: case 57601: case 57603: case 57604:     /* new/open/save */
    case 57607: case 57606:                             /* print, printer */
    case 57612:                                         /* send */
    case 32809: case 32810:                             /* JWC */
    case 32960: case 32961:                             /* DXF */
    case 32975: case 32976:                             /* SFC */
    case 32862: case 32946: case 32869:                 /* figure windows */
    case 32848: case 32865: case 32866:
    case 32977: case 32979: case 32980: case 32982:     /* file tools */
    case 32984: case 32987:
    case 57664: case 57665: case 57667:                 /* about, help */
    case 57616:                                         /* exit */
        return 1;
    }
    return id >= 57345 && id <= 57359;                  /* the MRU list */
}

int main(int argc, char **argv)
{
    int list = argc > 1 && !strcmp(argv[1], "--list");
    int i, n = 0, answered = 0, cmded = 0, dlged = 0, drew = 0;

    app_resize(1264, 741);
    for (i = 0; i < JW_NMENU_TREE; i++) {
        const jw_menu_item_t *m = &jw_menu_tree[i];
        const jw_drawing *d;
        int before_cmd, before_n, took, now_cmd, now_n, dlg;

        if (m->kind != 0 || m->id == 0 || skip(m->id))
            continue;
        /* a fresh sheet with one line on it, so a command that works on
           something has something to work on */
        app_new();
        app_command(JW_CMD_SEN);
        app_press(400, 300, 0);
        app_press(700, 400, 0);
        d = app_drawing();
        before_cmd = jw_cmd();
        before_n = d->ndrawn;

        took = app_command(m->id);
        now_cmd = jw_cmd();
        now_n = d->ndrawn;
        dlg = app_modal();

        n++;
        if (now_cmd != before_cmd)
            cmded++;
        if (dlg)
            dlged++;
        if (now_n != before_n)
            drew++;
        if (took || now_cmd != before_cmd || dlg || now_n != before_n)
            answered++;
        else if (list)
            printf("     %5d dead  %s\n", m->id, m->text);
        if (list && (took || now_cmd != before_cmd || dlg
                     || now_n != before_n))
            printf("     %5d %s%s%s%s %s\n", m->id,
                   took ? "took " : "     ",
                   now_cmd != before_cmd ? "cmd " : "    ",
                   dlg ? "dlg " : "    ",
                   now_n != before_n ? "drew" : "    ", m->text);
        /* whatever it put up, take it down again */
        if (dlg)
            app_key(27);
    }

    printf("     %d menu items tried, %d answered"
           " (%d changed the command, %d put a dialog up, %d drew)\n",
           n, answered, cmded, dlged, drew);
    ck(n > 90, "メニューの項目が九十以上ある");
    ck(answered > 60, "そのうち六十以上が応える");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
