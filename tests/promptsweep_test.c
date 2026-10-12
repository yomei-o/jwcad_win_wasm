/* Every command id, entered, has to leave a prompt on the status line, and
 * Esc on entry must leave nothing half done.  Also 図形登録, whose prompt
 * used to stay on 範囲選択's after 選択確定.
 *   tests/promptsweep_test.exe [-v]
 */
#include <stdio.h>
#include <string.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

int main(int argc, char **argv)
{
    int id, fails = 0, n = 0, v = argc > 1;
    jw_drawing *d;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, app_view(), 10, 10, 0);
    jw_cmd_point(d, app_view(), 60, 10, 0);
    app_command(32946);                         /* 図形登録 */
    jw_cmd_point(d, app_view(), 0, 0, 0);
    jw_cmd_track(30, 5);
    jw_cmd_point(d, app_view(), 80, 20, 0);
    jw_cmd_bar(d, 1120);
    if (d->nobj != 1 || jw_cmd_sel_stage() != 3) {
        printf("BAD  図形登録 setup: nobj %d stage %d\n", d->nobj, jw_cmd_sel_stage());
        fails++;
    } else if (!strstr(jw_cmd_prompt(), "\x8a\xee\x8f\x80\x93\x5f")) {    /* 基準点 */
        printf("BAD  図形登録 after 選択確定 does not ask for the 基準点: [%s]\n",
               jw_cmd_prompt());
        fails++;
    }

    for (id = 0x8000; id < 0x8120; id++) {
        const char *p;
        app_new();
        app_command(id);
        if (app_modal()) { app_key(27); continue; }
        if (jw_cmd() != id) continue;       /* not a command of ours */
        n++;
        p = jw_cmd_prompt();
        if (v) printf("%04x %s\n", id, p ? p : "(null)");
        if (!p || !*p) { printf("BAD  command %04x has no prompt\n", id); fails++; }
        jw_cmd_escape();
        if (jw_cmd_midway()) { printf("BAD  command %04x midway right after Esc on entry\n", id); fails++; }
        if (!jw_numbers_sane(app_drawing())) { printf("BAD  %04x insane\n", id); fails++; }
    }
    printf("%d commands entered\n", n);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
