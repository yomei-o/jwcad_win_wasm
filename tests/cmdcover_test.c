/* Which command ids the port answers: `cmdcover_test.exe id id ...` (or a file
   of ids with -f) prints "id took|dead" for each, sent over a small sheet the
   way tests/menusweep_test.c does.  tools/mkcoverage.sh uses it for the menu
   items that are not on the port's main menu (the original's pop-up menus).
   Without arguments it only checks that a few known ones answer. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

static int try_id(int id, int *how)
{
    const jw_drawing *d;
    int bc, bn, took, nc, nn, dlg;

    app_new();
    app_command(JW_CMD_SEN);
    app_press(400, 300, 0);
    app_press(700, 400, 0);
    d = app_drawing();
    bc = jw_cmd();
    bn = d->ndrawn;
    took = app_command(id);
    nc = jw_cmd();
    nn = d->ndrawn;
    dlg = app_modal();
    *how = (took ? 1 : 0) | (nc != bc ? 2 : 0) | (dlg ? 4 : 0) | (nn != bn ? 8 : 0);
    if (dlg)
        app_key(27);
    app_take_action();
    return *how != 0;
}

int main(int argc, char **argv)
{
    int i, how, bad = 0;

    app_resize(1264, 741);
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            int id = atoi(argv[i]);

            printf("%d %s\n", id, try_id(id, &how) ? "took" : "dead");
        }
        return 0;
    }
    bad += !try_id(JW_CMD_SEN, &how);
    bad += !try_id(32787, &how);        /* 範囲選択 */
    printf("%s\n", bad ? "SOME BAD" : "all ok");
    return bad != 0;
}
