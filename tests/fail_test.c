/* The ways a person gets it wrong, and what the port does about them.
 *
 *   tests/fail_test.exe
 *
 * Drawing is not a straight line of correct steps.  People click on nothing,
 * press Esc half way, press the same button twice, type letters into a box
 * that wants a number, start one command and leave for another, and undo
 * what they just did.  None of that should leave the port confused, and none
 * of it should put anything in the drawing that was not asked for.
 *
 * What this checks, over and over: the element count only moves when it
 * should, and the command still works afterwards.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

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

static jw_drawing *fresh(void)
{
    unsigned char *b;
    long n;

    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        exit(1);
    }
    free(b);
    app_fit();
    return (jw_drawing *)app_drawing();
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

/* every command, entered and left again without drawing anything */
static void enter_and_leave(void)
{
    static const unsigned short CMD[] = {
        0x8003, 0x8004, 0x8005, 0x8011, 0x8073, 0x8012, 0x8017, 0x8020,
        0x804f, 0x807e, 0x805b, 0x8063, 0x807c, 0x8069, 0x8066, 0x8068,
        0x808c, 0x806a, 0x804e, 0x8013, 0x8024, 0x8096, 0x80a3, 0x80b8,
        0x808e, 0x8026
    };
    jw_drawing *d = fresh();
    int n0 = d->ndrawn, i, j, bad = 0;

    for (i = 0; i < (int)(sizeof CMD / sizeof CMD[0]); i++) {
        jw_cmd_set(CMD[i]);
        jw_cmd_point(d, app_view(), 1e5, 1e5, 0);
        for (j = 0; j < 3; j++)
            app_key(27);
        if (d->ndrawn < n0)
            bad++;
    }
    ck(!bad, "失敗系: no command loses elements when it is entered and left");
}

/* clicking where there is nothing, in the commands that need something */
static void click_on_nothing(void)
{
    static const unsigned short CMD[] = {
        0x8020, 0x8012, 0x8017, 0x8069, 0x805b, 0x8063, 0x807c, 0x8066,
        0x8068, 0x804e, 0x80b8, 0x801a
    };
    jw_drawing *d = fresh();
    int n0 = d->ndrawn, i, k, bad = 0;

    for (i = 0; i < (int)(sizeof CMD / sizeof CMD[0]); i++) {
        jw_cmd_set(CMD[i]);
        for (k = 0; k < 6; k++)
            jw_cmd_point(d, app_view(), 1e6 + k, -1e6 - k, 0);
        if (d->ndrawn != n0)
            bad++;
    }
    ck(!bad, "  clicking far from anything draws nothing at all");
}

/* Esc between every pair of clicks of a three-point command */
static void escape_everywhere(void)
{
    jw_drawing *d = fresh();
    int n0 = d->ndrawn, cut, bad = 0, i;

    for (cut = 0; cut < 4; cut++) {
        int k;
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_ENKO);
        if (jw_cmd_bar_check(1318) == 0)
            jw_cmd_bar(d, 1318);
        for (k = 0; k < 4; k++) {
            if (k == cut)
                app_key(27);
            jw_cmd_point(d, app_view(), -40.0 + k * 13.0, -40.0 - k * 7.0, 0);
        }
        app_key(27);
        jw_cmd_bar(d, 1318);
    }
    for (i = n0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_ENKO && !(d->obj[i].d[2] > 0.0))
            bad++;
    ck(!bad, "  Esc at any point leaves no half-made element behind");
}

/* a box that wants a number, given everything else */
static void rubbish_in_the_boxes(void)
{
    static const char *JUNK[] = { "abc", "-", ".", ",", "--", "1e9999",
                                  "999999999999999999999", "0", "-5", "" };
    jw_drawing *d = fresh();
    int n0 = d->ndrawn, i, bad = 0;

    for (i = 0; i < (int)(sizeof JUNK / sizeof JUNK[0]); i++) {
        int was = d->ndrawn;
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_KUKEI);
        type_box(1413, JUNK[i]);
        type_box(1411, JUNK[i]);
        jw_cmd_point(d, app_view(), -30.0, -30.0, 0);
        jw_cmd_point(d, app_view(), 10.0, -60.0, 0);
        if (d->ndrawn != was && d->ndrawn != was + 4)
            bad++;
        else {
            int k, j;
            for (k = was; k < d->ndrawn; k++)
                for (j = 0; j < 4; j++) {
                    double v = d->obj[k].d[j];
                    if (!(v > -1e12 && v < 1e12))
                        bad++;
                }
        }
    }
    type_box(1413, "");
    type_box(1411, "");
    ck(!bad, "  rubbish in a number box never makes a rubbish element");
    ck(d->ndrawn >= n0, "  and never loses what was there");
}

/* undo everything, twice over */
static void undo_past_the_start(void)
{
    jw_drawing *d = fresh();
    int n0 = d->ndrawn, k;

    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    for (k = 0; k < 3; k++) {
        jw_cmd_point(d, app_view(), -40.0 + k * 10.0, -40.0, 0);
        jw_cmd_point(d, app_view(), -40.0 + k * 10.0, -10.0, 0);
    }
    ck(d->ndrawn == n0 + 3, "  three lines drawn");
    for (k = 0; k < 20; k++)
        jw_cmd_undo(d);
    ck(d->ndrawn == n0, "  undo takes them all back and then stops");
    ck(!jw_cmd_can_undo(), "  and says there is nothing left to undo");
}

/* pressing the bar's buttons when the command is not ready for them */
static void buttons_at_the_wrong_time(void)
{
    static const struct { unsigned short cmd, id; } B[] = {
        { 0x8013, 1120 }, { 0x8013, 1067 }, { 0x8024, 1120 }, { 0x8096, 1120 },
        { 0x806a, 1148 }, { 0x808e, 1120 }, { 0x804f, 1120 }, { 0x804f, 1065 },
        { 0x808c, 1800 }, { 0x8005, 1064 }, { 0x807e, 1068 }
    };
    jw_drawing *d = fresh();
    int n0 = d->ndrawn, i, bad = 0;

    for (i = 0; i < (int)(sizeof B / sizeof B[0]); i++) {
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(B[i].cmd);
        jw_cmd_bar(d, B[i].id);
        jw_cmd_bar(d, B[i].id);
        if (d->ndrawn < n0)
            bad++;
    }
    ck(!bad, "  a bar button pressed too early takes nothing away");
}

/* A dialog is up: nothing behind it hears the keyboard.
 *
 * Every one of the port's windows stands for a modal dialog of the
 * original's, and while one is on the screen the drawing and its command bar
 * are out of reach.  A press outside was already ignored; a key was not, and
 * a digit landed in whichever box the bar behind had the caret in. */
static void keys_under_a_dialog(void)
{
    static const struct { int cmd; const char *what; } D[3] = {
        { 32843, "軸角・目盛・オフセット" },
        { 32811, "画面倍率・文字表示" },
        { 32891, "基本設定" }
    };
    int i;

    for (i = 0; i < 3; i++) {
        jw_drawing *d = fresh();
        int n0;
        char msg[96];

        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_SEN);
        type_box(1412, "");
        jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
        n0 = d->ndrawn;
        if (!app_command(D[i].cmd)) {
            sprintf(msg, "%s は開かない", D[i].what);
            ck(0, msg);
            continue;
        }
        app_key('7');
        app_key('7');
        sprintf(msg, "%s が出ている間は数字が入力欄へ行かない", D[i].what);
        ck(!jw_cmd_box(1412) || !*jw_cmd_box(1412), msg);
        app_key(27);                    /* Esc shuts it */
        type_box(1412, "7");
        sprintf(msg, "%s は Esc で閉じ、入力欄が戻る", D[i].what);
        ck(jw_cmd_box(1412) && !strcmp(jw_cmd_box(1412), "7"), msg);
        ck(d->ndrawn == n0, "  その間に何も描かれない");
        type_box(1412, "");
    }
}

/* 縮尺・読取: the box at the right of the status line opens it, the two
   boxes take a scale and Ok applies it to the group being written to. */
static void scale_dialog(void)
{
    jw_drawing *d = fresh();
    int g, wg = 0, i;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    ck(app_command(32827) == 1, "ステータスの縮尺の箱で縮尺・読取が開く");
    /* while it is up the drawing hears nothing */
    for (i = 0; i < 8; i++)
        app_key(8);
    app_key('5');
    app_key('0');
    app_key(13);                        /* Enter is Ok */
    ck(d->group[wg].scale == 50.0, "  1/50 を打って書込レイヤグループに入る");
    /* and it is shut: the bar hears the keyboard again */
    type_box(1412, "7");
    ck(jw_cmd_box(1412) && !strcmp(jw_cmd_box(1412), "7"),
       "  Ok のあとは入力欄が戻る");
    type_box(1412, "");
    /* the menu's own item opens the same one, and キャンセル leaves it */
    ck(app_command(32944) == 1, "メニューの縮尺・読取も同じものを開く");
    app_key(27);
    ck(d->group[wg].scale == 50.0, "  Esc では変わらない");
}

int main(void)
{
    app_resize(1264, 741);
    enter_and_leave();
    click_on_nothing();
    escape_everywhere();
    rubbish_in_the_boxes();
    undo_past_the_start();
    buttons_at_the_wrong_time();
    keys_under_a_dialog();
    scale_dialog();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
