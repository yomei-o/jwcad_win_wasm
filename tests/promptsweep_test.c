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
#include "../src/gen/prompts.h"

static int fails_g, nck;

static void ck(int ok, const char *what)
{
    nck++;
    if (!ok) {
        printf("BAD  %s\n", what);
        fails_g++;
    }
}

static int is(const char *prompt, const char *str)
{
    return prompt && !strncmp(prompt, str, strlen(str) < 16 ? strlen(str) : 16);
}

/* Esc steps a command back one stage a press, as the original does
 * (tools/escprobe.sh; tmp/esc_report.md).  Two lines are drawn, then: */
static void esc_stages(void)
{
    jw_drawing *d;
    int k;
    static const int RANGE[3] = { JW_CMD_HANI, JW_CMD_FUKUSHA, JW_CMD_IDOU };

    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, app_view(), 10, 10, 0);
    jw_cmd_point(d, app_view(), 60, 10, 0);
    jw_cmd_point(d, app_view(), 10, 20, 0);
    jw_cmd_point(d, app_view(), 60, 20, 0);

    /* 範囲選択・複写・移動: second corner -> first corner; a made selection
       -> back to the second corner with the selection let go and the first
       corner kept; a confirmed one (複写・移動) -> the selection, kept. */
    for (k = 0; k < 3; k++) {
        char first[256];

        jw_cmd_set(RANGE[k]);
        strncpy(first, jw_cmd_prompt(), sizeof first - 1);
        first[sizeof first - 1] = 0;
        jw_cmd_point(d, app_view(), 0, 0, 0);
        ck(is(jw_cmd_prompt(), JW_STR_5326), "range: first corner asks for the second");
        app_key(27);
        ck(!strcmp(jw_cmd_prompt(), first), "range: Esc at the second corner is the first prompt again");
        ck(jw_cmd_sel_stage() == 0, "range: ... and the stage is 0");
        jw_cmd_point(d, app_view(), 0, 0, 0);
        jw_cmd_point(d, app_view(), 100, 50, 0);
        ck(jw_cmd_sel_count(d) == 2 && jw_cmd_sel_stage() == 2, "range: a box takes the two lines");
        app_key(27);
        ck(jw_cmd_sel_count(d) == 0, "range: Esc after the box lets go of the selection");
        ck(is(jw_cmd_prompt(), JW_STR_5326) && jw_cmd_sel_stage() == 1, "range: ... back at the second corner");
        jw_cmd_point(d, app_view(), 100, 50, 0);       /* the first corner was kept */
        ck(jw_cmd_sel_count(d) == 2, "range: the kept first corner closes the same box");
        if (RANGE[k] != JW_CMD_HANI) {
            jw_cmd_track(30, 5);
            jw_cmd_bar(d, 1120);                        /* 選択確定 */
            ck(jw_cmd_sel_stage() == 3, "range: 選択確定 is placing");
            app_key(27);
            ck(jw_cmd_sel_stage() == 2 && jw_cmd_sel_count(d) == 2,
               "range: Esc while placing is back to the selection, still picked");
            app_key(27);
            ck(jw_cmd_sel_count(d) == 0 && jw_cmd_sel_stage() == 1, "range: the next lets go of it");
        }
        if (RANGE[k] == JW_CMD_HANI) {          /* no placing stage: the box is the last */
            app_key(27);
            ck(jw_cmd_sel_count(d) == 0 && jw_cmd_sel_stage() == 1, "range: Esc lets go of 範囲選択's selection");
        }
        app_key(27);
        ck(!strcmp(jw_cmd_prompt(), first) && jw_cmd_sel_stage() == 0, "range: and the last is the first prompt");
    }

    /* 測定: the prompt says 始点 again but the chain goes on */
    jw_cmd_set(JW_CMD_SOKUTEI);
    jw_cmd_point(d, app_view(), 0, 0, 0);
    jw_cmd_point(d, app_view(), 30, 0, 0);
    ck(is(jw_cmd_prompt(), JW_STR_5323), "測定: after a point it asks for the next");
    {
        char before[300];
        const char *st;

        strncpy(before, jw_cmd_status(d), sizeof before - 1);
        before[sizeof before - 1] = 0;
        app_key(27);
        ck(is(jw_cmd_prompt(), JW_STR_5320), "測定: Esc asks for 始点 again");
        jw_cmd_point(d, app_view(), 30, 40, 0);
        st = jw_cmd_status(d);
        ck(is(jw_cmd_prompt(), JW_STR_5323), "測定: and the next click is a 次の点 once more");
        ck(strcmp(before, st) != 0, "測定: ... that adds to the total (the chain went on)");
    }

    /* 消去 (部分消し): 終点 -> 始点 -> the line */
    jw_cmd_set(JW_CMD_SHOUKYO);
    ck(is(jw_cmd_prompt(), JW_STR_10111), "消去: starts at the line");
    jw_cmd_point(d, app_view(), 30, 10.2, 0);
    ck(is(jw_cmd_prompt(), JW_STR_10112), "消去: line picked, 始点");
    jw_cmd_point(d, app_view(), 20, 10, 0);
    ck(is(jw_cmd_prompt(), JW_STR_10113), "消去: 終点");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_10112), "消去: Esc -> 始点");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_10111), "消去: Esc -> the line");

    /* 線: Esc right after a finished line takes its first point back */
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, app_view(), 10, 10, 0);
    jw_cmd_point(d, app_view(), 60, 10, 0);
    ck(d->nobj == 1, "線: one line");
    app_key(27);
    ck(jw_cmd_midway(), "線: Esc after a finished line re-arms its first point");
    jw_cmd_point(d, app_view(), 40, 10, 0);
    ck(d->nobj == 2 && d->obj[1].d[0] == 10.0 && d->obj[1].d[1] == 10.0,
       "線: the next click draws from that same start");
    app_key(27);                        /* that one was finished too, so again */
    ck(jw_cmd_midway(), "線: any finished line can be re-armed");
    app_key(27);
    ck(!jw_cmd_midway(), "線: and the next press lets go");
    jw_cmd_point(d, app_view(), 5, 5, 0);
    app_key(27);
    jw_cmd_point(d, app_view(), 50, 50, 0);
    app_key(27);
    jw_cmd_point(d, app_view(), 70, 70, 0);
    ck(d->nobj == 2, "線: Esc after a first click lets go of it (nothing drawn)");
}

/* The stages the original has between the box and the work, and 寸法・複線・円弧
   one press at a time (tools/stagecmp.sh, tmp/stage_report.md). */
static void stage_prompts(void)
{
    jw_drawing *d;
    int k, i;
    static const int RANGE[3] = { JW_CMD_HANI, JW_CMD_FUKUSHA, JW_CMD_IDOU };

    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, app_view(), 10, 10, 0);
    jw_cmd_point(d, app_view(), 60, 10, 0);
    jw_cmd_point(d, app_view(), 10, 20, 0);
    jw_cmd_point(d, app_view(), 60, 20, 0);
    for (k = 0; k < 3; k++) {
        jw_cmd_set(RANGE[k]);
        jw_cmd_point(d, app_view(), 0, 0, 0);
        ck(is(jw_cmd_prompt(), JW_STR_5326) && strstr(jw_cmd_prompt(), JW_STR_5762),
           "stage: second corner prompt has the (LL)(RR) tail");
        jw_cmd_point(d, app_view(), 100, 50, 0);
        ck(is(jw_cmd_prompt(), JW_STR_5325) && jw_cmd_sel_stage() == 2, "stage: box made -> 追加・除外");
        ck((strstr(jw_cmd_prompt(), JW_STR_5828) != 0) == (RANGE[k] != JW_CMD_HANI),
           "stage: Enter-範囲確定 only for copy and move");
        ck((strstr(jw_cmd_prompt(), JW_STR_5829) != 0) == (RANGE[k] != JW_CMD_HANI),
           "stage: ShiftEnter-基点変更 only for copy and move");
        jw_cmd_point(d, app_view(), 30, 10, 0);          /* on the first line: takes it away */
        ck(jw_cmd_sel_count(d) == 1, "stage: a click on a picked line lets go of it");
        jw_cmd_point(d, app_view(), 30, 10, 0);
        ck(jw_cmd_sel_count(d) == 2, "stage: and picks it again");
        jw_cmd_point(d, app_view(), 80, 40, 0);
        jw_cmd_point(d, app_view(), 90, 45, 0);
        ck(jw_cmd_sel_count(d) == 2 && jw_cmd_sel_stage() == 2, "stage: clicks on nothing do nothing, two make no box");
        if (RANGE[k] != JW_CMD_HANI) {
            jw_cmd_track(30, 5);
            ck(jw_cmd_enter_key(d) && jw_cmd_sel_stage() == 3, "stage: Enter confirms the range");
        }
        jw_cmd_escape();
        if (RANGE[k] != JW_CMD_HANI) {
            /* ShiftEnter: the same 範囲確定, but the click right after it is
               spent on 基点変更's new 基準点 instead of placing anything --
               jw_win's own hint (JW_STR_5829) said as much, and this is the
               one way left to tell it apart from plain Enter at the C level
               until a front end actually sends it (RESUME.md 2026-10-13).
               Escaped before a real placement click, so the two lines this
               whole sweep shares are never actually moved or copied. */
            int before;

            jw_cmd_set(RANGE[k]);
            jw_cmd_point(d, app_view(), 0, 0, 0);
            jw_cmd_point(d, app_view(), 100, 50, 0);
            jw_cmd_track(30, 5);
            ck(jw_cmd_shift_enter_key(d) && jw_cmd_sel_stage() == 3,
               "stage: ShiftEnter confirms the range too");
            before = d->ndrawn;
            jw_cmd_point(d, app_view(), 70, 30, 0);
            ck(jw_cmd_sel_stage() == 3 && d->ndrawn == before,
               "stage: ...and the click right after is the new 基準点, not a placement");
            jw_cmd_escape();
        }
        /* a box that catches nothing stays in the stage */
        jw_cmd_set(RANGE[k]);
        jw_cmd_point(d, app_view(), 200, 200, 0);
        jw_cmd_point(d, app_view(), 210, 210, 0);
        ck(jw_cmd_sel_stage() == 2 && jw_cmd_sel_count(d) == 0, "stage: an empty box stays in 追加・除外");
        jw_cmd_point(d, app_view(), 30, 10, 0);
        ck(jw_cmd_sel_count(d) == 1, "stage: and a click adds a line to it");
        app_key(27);
        ck(jw_cmd_sel_stage() == 1, "stage: Esc is back at the second corner");
        jw_cmd_escape();
    }

    /* 寸法: a dimension in -> 終点 -> 始点 -> 寸法線の位置 -> 引出し線 */
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_point(d, app_view(), 10, 40, 0);
    jw_cmd_point(d, app_view(), 12, 42, 0);
    ck(is(jw_cmd_prompt(), JW_STR_5331), "寸法: 始点");
    jw_cmd_point(d, app_view(), 10, 10, 1);
    jw_cmd_point(d, app_view(), 60, 10, 1);
    ck(is(jw_cmd_prompt(), JW_STR_5333), "寸法: a dimension is in, 連続入力");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5332), "寸法: Esc -> 終点");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5331), "寸法: Esc -> 始点");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5330), "寸法: Esc -> 寸法線の位置");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5329), "寸法: Esc -> 引出し線の始点");

    /* 複線 */
    jw_cmd_set(JW_CMD_FUKUSEN);
    ck(is(jw_cmd_prompt(), JW_STR_5305), "複線: pick");
    jw_cmd_point(d, app_view(), 30, 10, 0);
    ck(is(jw_cmd_prompt(), JW_STR_5312), "複線: line picked -> interval or position");
    jw_cmd_point(d, app_view(), 30, 15, 0);
    ck(is(jw_cmd_prompt(), JW_STR_5310), "複線: position given -> direction");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5312), "複線: Esc -> interval");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5305), "複線: Esc -> pick");

    /* 円弧: 中心点 -> 始点 -> 終点, Esc walks back, and after a finished arc
       the first press is the 終点 again */
    jw_cmd_set(JW_CMD_ENKO);
    jw_cmd_bar(d, 1318);
    ck(is(jw_cmd_prompt(), JW_STR_5309), "円弧: 中心点");
    jw_cmd_point(d, app_view(), 100, 100, 0);
    ck(is(jw_cmd_prompt(), JW_STR_5304), "円弧: 始点");
    jw_cmd_point(d, app_view(), 120, 100, 0);
    ck(is(jw_cmd_prompt(), JW_STR_5321), "円弧: 終点");
    i = d->nobj;
    jw_cmd_point(d, app_view(), 100, 120, 0);
    ck(d->nobj == i + 1 && is(jw_cmd_prompt(), JW_STR_5309), "円弧: made, back to 中心点");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5321), "円弧: Esc after it -> 終点 again");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5304), "円弧: Esc -> 始点");
    app_key(27);
    ck(is(jw_cmd_prompt(), JW_STR_5309), "円弧: Esc -> 中心点");
}

int main(int argc, char **argv)
{
    int id, fails = 0, n = 0, v = argc > 1;
    jw_drawing *d;

    app_resize(1264, 741);
    esc_stages();                               /* before anything leaves state behind */
    stage_prompts();
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
    fails += fails_g;
    printf("%d commands entered, %d Esc-stage checks\n", n, nck);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
