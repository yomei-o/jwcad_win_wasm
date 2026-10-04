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
#include "../src/gen/bars.h"
#include "../src/gen/layerdlg.h"

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

/* The same rubbish, but through **every** number box of **every** bar.
 *
 * `rubbish_in_the_boxes` above only pokes 矩形's two, and that was enough to
 * find one: `999999999999999999999` in 寸法 came out of the layer group's
 * scale as 5e12 and made a rectangle whose corners were past what
 * `jw_numbers_sane` lets a drawing hold -- so it could no longer be written
 * out and read back.  A box takes any run of digits, dots, minuses and
 * commas, so there is nothing to stop the same thing anywhere else.
 *
 * `src/gen/bars.h` is the original's own list of what is on each bar, so
 * the sweep is over the real set rather than a hand-written one.  The
 * second-stage bars (cmd = 100000 + id, the one a command puts up once a
 * range is settled) are skipped: they cannot be entered by command alone.
 */
#include "../src/gen/bars.h"

static void rubbish_in_every_box(void)
{
    static const char *JUNK[] = {
        "abc", "-", ".", ",", "--", "1e9999", "999999999999999999999",
        "99999999999999999999999999999999999999999", "-999999999999999999999",
        "0", "-5", "0.000000000000001", ""
    };
    jw_drawing *d = fresh();
    int bad = 0, boxes = 0, i, j, k;

    for (i = 0; i < (int)(sizeof jw_bars / sizeof jw_bars[0]); i++) {
        const jw_bar_t *b = &jw_bars[i];

        if (b->cmd >= 100000)
            continue;
        for (j = 0; j < b->n; j++) {
            if (b->c[j].kind != JW_CTL_COMBO || b->c[j].id == 0xffff)
                continue;
            boxes++;
            for (k = 0; k < (int)(sizeof JUNK / sizeof JUNK[0]); k++) {
                int was, m, q;

                jw_cmd_set(JW_CMD_TEN);         /* leave whatever was running */
                jw_cmd_set((unsigned short)b->cmd);
                type_box(b->c[j].id, JUNK[k]);
                was = d->ndrawn;
                for (m = 0; m < 5; m++)
                    jw_cmd_point(d, app_view(), -30.0 + m * 17.0,
                                 -30.0 - m * 11.0, 0);
                app_key(27);
                if (d->ndrawn < was) {
                    printf("     バー %u の箱 %u に「%s」で要素が減った\n",
                           b->cmd, b->c[j].id, JUNK[k]);
                    bad++;
                }
                for (q = was; q < d->ndrawn; q++)
                    for (m = 0; m < 8; m++) {
                        double v = d->obj[q].d[m];
                        if (!(v > -1e12 && v < 1e12)) {
                            printf("     バー %u の箱 %u に「%s」→ d[%d] = %g\n",
                                   b->cmd, b->c[j].id, JUNK[k], m, v);
                            bad++;
                            m = 8;
                            q = d->ndrawn;
                        }
                    }
                type_box(b->c[j].id, "");
            }
        }
    }
    printf("     （バー %d 本の数値箱 %d 個 × %d 通り）\n",
           (int)(sizeof jw_bars / sizeof jw_bars[0]), boxes,
           (int)(sizeof JUNK / sizeof JUNK[0]));
    ck(!bad, "  どの箱に何を打っても、図面が持てない数は出てこない");
}

/* Every button and every checkbox of every bar, pressed at four different
 * moments: before any click, after one, after three, and twice over.
 *
 * `buttons_at_the_wrong_time` below does eleven of them by hand.  The
 * number boxes taught the lesson: sweeping the real set out of
 * `src/gen/bars.h` found four more commands with the same hole that the
 * hand-written list had missed.  So this walks the lot.
 *
 * What it watches is the one thing every command must obey: nothing the
 * drawing gains is a number the drawing could not hold (`jw_numbers_sane`:
 * every coordinate inside +/-1e12).  It does **not** watch the element
 * count -- plenty of commands take elements away on purpose, and the sweep
 * said so at once: 包絡処理's 実線 (bar 32846, control 1338) swallowed 243
 * lines, which is exactly what 包絡 is for.
 *
 * It runs last, because a tick it leaves set would change what a later
 * command draws.
 */
static void press_everything(void)
{
    jw_drawing *d = fresh();
    int base = d->ndrawn, ctls = 0, bad = 0, i, j, when;

    for (i = 0; i < (int)(sizeof jw_bars / sizeof jw_bars[0]); i++) {
        const jw_bar_t *b = &jw_bars[i];

        if (b->cmd >= 100000)
            continue;
        for (j = 0; j < b->n; j++) {
            int kind = b->c[j].kind;
            unsigned id = b->c[j].id;

            if (kind != JW_CTL_BUTTON && kind != JW_CTL_CHECK)
                continue;
            if (id == 0xffff)
                continue;
            ctls++;
            for (when = 0; when < 4; when++) {
                int was, k, q, m;

                jw_cmd_set(JW_CMD_TEN);
                jw_cmd_set((unsigned short)b->cmd);
                was = d->ndrawn;
                for (k = 0; k < when; k++)
                    jw_cmd_point(d, app_view(), -20.0 + k * 13.0,
                                 -20.0 - k * 9.0, 0);
                jw_cmd_bar(d, (int)id);
                if (when == 3)
                    jw_cmd_bar(d, (int)id);
                for (k = 0; k < 3; k++)
                    jw_cmd_point(d, app_view(), 15.0 + k * 11.0,
                                 -45.0 - k * 7.0, 0);
                app_key(27);
                for (q = was; q < d->ndrawn && bad < 20; q++)
                    for (m = 0; m < 8; m++) {
                        double v = d->obj[q].d[m];
                        if (!(v > -1e12 && v < 1e12)) {
                            printf("     bar %u ctl %u (when %d): d[%d] = %g\n",
                                   b->cmd, id, when, m, v);
                            bad++;
                            m = 8;
                            q = d->ndrawn;
                        }
                    }
            }
            if (d->ndrawn > base + 4000)
                d = fresh();        /* keep the drawing from growing forever */
        }
    }
    printf("     (%d controls x 4 moments)\n", ctls);
    ck(!bad, "  any button or tick, pressed at any moment, keeps the drawing sane");
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

    /* 新規 (or opening another drawing) throws away the 進む side too.
       It used to keep it: two steps undone, a new drawing, and 進む put
       the old drawing's lines into the new one -- and a step that had
       erased something came back with its record freed, so the 戻る
       after it fell over (tests/cmdfuzz_test.c, seed 2). */
    d = fresh();
    n0 = d->ndrawn;
    for (k = 0; k < 3; k++) {
        jw_cmd_point(d, app_view(), -40.0 + k * 10.0, -40.0, 0);
        jw_cmd_point(d, app_view(), -40.0 + k * 10.0, -10.0, 0);
    }
    jw_cmd_set(JW_CMD_SHOUKYO);
    jw_cmd_point(d, app_view(), -40.0, -25.0, 1);   /* (R) erases one */
    jw_cmd_undo(d);
    jw_cmd_undo(d);
    ck(jw_cmd_can_redo(), "  two steps undone can be redone");
    d = fresh();
    n0 = d->ndrawn;
    ck(!jw_cmd_can_redo() && !jw_cmd_can_undo(),
       "  but not once another drawing is opened");
    for (k = 0; k < 4; k++)
        jw_cmd_redo(d);
    for (k = 0; k < 4; k++)
        jw_cmd_undo(d);
    ck(d->ndrawn == n0, "  and 進む and 戻る there leave the new one alone");
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

/* 寸法 の 設定 (1071) opens the 寸法設定 dialog -- pressed on the
   original, that is the window that came up. */
static void dim_setup_button(void)
{
    jw_drawing *d = fresh();
    int i, k, pressed = 0;

    (void)d;
    jw_cmd_set(0x804f);
    for (i = 0; i < JW_NBARS && !pressed; i++) {
        if (jw_bars[i].cmd != 0x804fu)
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int x = c->x + c->w / 2, y = c->y + c->h / 2;
            if (c->id != 1071 || ui_bar_hit(x, y) != 1071)
                continue;
            app_press(x, y, 0);
            pressed = 1;
            break;
        }
    }
    ck(pressed, "寸法バーの 設定 釦が押せる");
    ck(app_sunpodlg_open(), "  寸法設定が開く");
    app_key(27);
}

/* press a control of the レイヤ設定 dialog where it is drawn */
static void press_ld(int id)
{
    rect_t r;
    int i;

    ui_layerdlg_rect(1264, 741, &r);
    for (i = 0; i < JW_NLAYERDLG; i++) {
        const jw_ld_t *z = &jw_layerdlg[i];
        if (z->id != id)
            continue;
        app_press(r.x + JW_LD_BORDER + z->x + z->w / 2,
                  r.y + JW_LD_CAPTION + z->y + z->h / 2, 0);
        return;
    }
}

/* レイヤ設定: the status line's third box opens it, and its sixteen
   buttons pick the layer being written to. */
static void layer_dialog(void)
{
    jw_drawing *d = fresh();
    int g, wg = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    ck(app_command(32829) == 1, "ステータスのレイヤの箱でレイヤ設定が開く");
    /* it is modal: a digit does not reach the bar behind */
    app_key('7');
    ck(!jw_cmd_box(1412) || !*jw_cmd_box(1412),
       "  出ている間は数字が入力欄へ行かない");
    app_key(27);
    ck(d->group[wg].state == 3, "  Esc で閉じても書込グループはそのまま");

    /* 全レイヤ非表示・全レイヤ編集・一括, against the files the original
       left after pressing each of them */
    {
        static const struct { const char *file; int id; const char *what; }
        B[8] = {
            { "decomp/res/lay_all_hide.jww",  1073, "全レイヤ非表示" },
            { "decomp/res/lay_hide_edit.jww", 2000, "  そのあと全レイヤ編集で戻る" },
            { "decomp/res/lay_ikkatsu.jww",   1141, "一括 一回" },
            { "decomp/res/lay_ikk2.jww",      1141, "  二回" },
            { "decomp/res/lay_ikk3.jww",      1141, "  三回" },
            { "decomp/res/lay_btn_l.jww",     1063, "レイヤの釦を一つ押すとそのレイヤだけ回る" },
            /* the checkbox first, then the button it changes */
            { 0,                              1524, 0 },
            { "decomp/res/lay_1524_hide.jww", 1073,
              "表示のみにするチェックを入れると全レイヤ非表示が表示のみになる" }
        };
        int c;
        app_command(32808);
        for (c = 0; c < 8; c++) {
            unsigned char *b;
            long n;
            jw_drawing ref;
            int i, k, ok = 1;

            if (!B[c].file) {           /* just press it, nothing to compare */
                press_ld(B[c].id);
                continue;
            }
            b = slurp(B[c].file, &n);
            if (!b || !jw_parse(&ref, b, n)) {
                printf("BAD  no %s\n", B[c].file);
                fails++;
                free(b);
                continue;
            }
            free(b);
            press_ld(B[c].id);
            for (i = 0; i < 16; i++) {
                if (d->group[i].state != ref.group[i].state)
                    ok = 0;
                for (k = 0; k < 16; k++)
                    if (d->group[i].layer[k].state != ref.group[i].layer[k].state)
                        ok = 0;
            }
            ck(ok, B[c].what);
            jw_free(&ref);
        }
        app_key(27);
    }
}

/* 一文字コマンド: each letter enters the command the original enters.
   Asked of it by sending the key to its frame and reading the command bar
   that came up (tools/keysweep.sh). */
static void one_letter_commands(void)
{
    static const struct { char k; int cmd; const char *what; } T[19] = {
        { 'a', 0x8026, "文字" }, { 'b', 0x8004, "矩形" },
        { 'c', 0x8024, "図形複写" }, { 'd', 0x801a, "消去" },
        { 'e', 0x8005, "円弧" }, { 'f', 0x8020, "複線" },
        { 'h', 0x8003, "線" }, { 'k', 0x808c, "曲線" },
        { 'l', 0x8073, "連続線" }, { 'm', 0x8096, "図形移動" },
        { 'o', 0x8066, "接線" }, { 'q', 0x804e, "包絡処理" },
        { 'r', 0x805b, "面取" }, { 's', 0x804f, "寸法" },
        { 't', 0x8017, "伸縮" }, { 'v', 0x8012, "コーナー処理" },
        { 'w', 0x807c, "２線" }, { 'x', 0x806a, "ハッチ" },
        { 'y', 0x8013, "範囲選択" }
    };
    int i, bad = 0;

    fresh();
    for (i = 0; i < 19; i++) {
        jw_cmd_set(0x8003);
        app_key(T[i].k);
        if (jw_cmd() != T[i].cmd) {
            printf("     %c went to %#x, not %#x (%s)\n", T[i].k, jw_cmd(),
                   T[i].cmd, T[i].what);
            bad++;
        }
    }
    ck(!bad, "一文字コマンドが十九とも原典と同じコマンドに入る");
    /* Shift つきは別の割り付け */
    {
        static const struct { char k; int cmd; } S[13] = {
            { 'B', 0x8003 }, { 'D', 0x8005 }, { 'F', 0x8011 }, { 'G', 0x804f },
            { 'M', 0x8017 }, { 'N', 0x805b }, { 'O', 0x801a }, { 'Q', 0x8096 },
            { 'R', 0x8066 }, { 'S', 0x8068 }, { 'W', 0x807e }, { 'X', 0x808c },
            { 'Y', 0x804e }
        };
        int k, wrong = 0;
        for (k = 0; k < 13; k++) {
            jw_cmd_set(0x8004);
            app_key(S[k].k);
            if (jw_cmd() != S[k].cmd) {
                printf("     %c went to %#x, not %#x\n", S[k].k, jw_cmd(),
                       S[k].cmd);
                wrong++;
            }
        }
        ck(!wrong, "Shift つきの十三も原典と同じコマンドに入る");
    }
    /* and a letter is text while 文字 is in force, not a command */
    jw_cmd_set(0x8026);
    app_key('b');
    ck(jw_cmd() == 0x8026, "  文字の中では文字のまま");
    jw_cmd_set(0x8003);
}

/* ダイアログの箱にも出鱈目を打つ。
 *
 * rubbish_in_every_box() が回るのは命令バーの箱で、ダイアログの箱は
 * その網の外にいた。そこから図面の数に届くのは三つある：縮尺の
 * 分子と分母（`src/app.c` の `sk_apply` が割る）、軸角
 * （`jw_cmd_set_axis`）、文字の任意サイズの三箱。どの箱も数字と
 * `.` と `-` しか受け付けないので、投げるのもその範囲でいちばん
 * 意地の悪いものにする。
 *
 * 見るのは数の正気だけ。要素の数はダイアログが変えてよい。 */
static void rubbish_in_every_dialog(void)
{
    /* ダイアログを出す命令（src/app.c の app_command） */
    static const unsigned short D[] = {
        32891,                  /* 基本設定 */
        32808, 32829,           /* レイヤ */
        32944, 32825, 32827,    /* 縮尺・読取 */
        32842, 32843,           /* 軸角・目盛・オフセット */
        32925,                  /* 寸法設定 */
        32811, 32844            /* 画面倍率・文字表示 */
    };
    static const char *JUNK[] = {
        "999999999999999", "0.000000000001", "0", "0.0", "-", ".",
        "..", "-0", "1.2.3", "----", "99999999999999999999", ""
    };
    int i, j, bad = 0;
    int nd = (int)(sizeof D / sizeof D[0]);
    int nj = (int)(sizeof JUNK / sizeof JUNK[0]);

    for (i = 0; i < nd; i++)
        for (j = 0; j < nj; j++) {
            jw_drawing *d = fresh();
            const char *s;
            int k;

            if (!app_command(D[i]) || !app_modal())
                continue;
            for (k = 0; k < 24; k++)
                app_key(8);
            for (s = JUNK[j]; *s; s++)
                app_key((unsigned char)*s);
            app_key(13);                /* Enter is Ok */
            app_key(27);                /* Esc if it is still up */
            /* and now draw with whatever it left behind.  通すのは窓の
               画素からの道（app_press）で、打った寸法はそこで縮尺に
               割られる —— 縮尺の分母に馬鹿を入れた効きめが出るのは
               この経路だけ。 */
            jw_cmd_set(JW_CMD_TEN);
            jw_cmd_set(JW_CMD_KUKEI);
            type_box(1413, "100");
            type_box(1411, "100");
            app_press(400, 300, 0);
            app_press(700, 450, 0);
            type_box(1413, "");
            type_box(1411, "");
            app_press(400, 300, 0);
            app_press(700, 450, 0);
            for (k = 0; k < d->ndrawn; k++) {
                int m;

                for (m = 0; m < 8; m++) {
                    double v = d->obj[k].d[m];

                    if (!(v > -1e12 && v < 1e12)) {
                        if (!bad)
                            printf("     %d に \"%s\" -> [%d].d[%d] = %g\n",
                                   D[i], JUNK[j], k, m, v);
                        bad++;
                    }
                }
            }
        }
    ck(!bad, "  ダイアログの箱に出鱈目を打っても図面が持てない数にならない");
}

/* Large numbers in every box, and then every button on the bar pressed.
 *
 * rubbish_in_every_box() watches what the numbers come out as; this watches
 * how long it takes.  A count typed into a box -- rings, 分割数, a number of
 * lines -- is a loop bound, and 曲線 was found taking a nine-digit one at
 * its word and adding lines for minutes (huge_curve below).  So every box
 * of every bar gets a few large numbers, the drawing gets five clicks on
 * what is already there, and every button and tick on the bar is pressed
 * (作図実行 among them); the whole of it for one box has to be done in two
 * seconds and add no more than 200000 elements. */
#include <time.h>
static void big_numbers_everywhere(void)
{
    static const char *BIG[] = { "99999999", "2147483647", "1000000" };
    jw_drawing *d = fresh();
    int bad = 0, boxes = 0, i, j, k, worst_ms = 0;

    for (i = 0; i < (int)(sizeof jw_bars / sizeof jw_bars[0]); i++) {
        const jw_bar_t *b = &jw_bars[i];

        if (b->cmd >= 100000)
            continue;
        for (j = 0; j < b->n; j++) {
            if (b->c[j].kind != JW_CTL_COMBO || b->c[j].id == 0xffff)
                continue;
            boxes++;
            for (k = 0; k < (int)(sizeof BIG / sizeof BIG[0]); k++) {
                int was, m, q, ms;
                clock_t t0;

                d = fresh();
                jw_cmd_set(JW_CMD_TEN);
                jw_cmd_set((unsigned short)b->cmd);
                type_box(b->c[j].id, BIG[k]);
                was = d->ndrawn;
                t0 = clock();
                for (m = 0; m < 5; m++) {
                    const jw_obj *o = &d->obj[(m * 7) % (d->ndrawn ? d->ndrawn : 1)];

                    jw_cmd_point(d, app_view(), o->d[0], o->d[1], m & 1);
                }
                for (q = 0; q < b->n; q++)
                    if (b->c[q].kind == JW_CTL_BUTTON
                        || b->c[q].kind == JW_CTL_CHECK)
                        jw_cmd_bar(d, b->c[q].id);
                app_key(27);
                ms = (int)((clock() - t0) * 1000.0 / CLOCKS_PER_SEC);
                if (ms > worst_ms)
                    worst_ms = ms;
                if (ms > 2000 || d->ndrawn - was > 200000) {
                    printf("     バー %u の箱 %u に「%s」: %d ms, %d 要素増\n",
                           b->cmd, b->c[j].id, BIG[k], ms, d->ndrawn - was);
                    bad++;
                }
                type_box(b->c[j].id, "");
            }
        }
    }
    printf("     （数値箱 %d 個 × %d 通り、いちばん遅くて %d ms）\n", boxes,
           (int)(sizeof BIG / sizeof BIG[0]), worst_ms);
    ck(!bad, "  どの箱に大きな数を入れて釦を全部押しても、二秒以内で終わる");
}

/* 戻る with a command part way through.  The original's 戻る asks the
   command first (FUN_00504100, vtable +0x40) and takes a step off the
   drawing only when the command had nothing of its own: so with the first
   point of a line down, 戻る lets go of that point and leaves the lines
   alone.  The port took the last line off and kept the point -- and a
   command that had picked an element kept its index, which after the undo
   could mean another element. */
static void undo_part_way(void)
{
    jw_drawing *d = fresh();
    int n0, k;

    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    for (k = 0; k < 3; k++) {
        jw_cmd_point(d, app_view(), -40.0 + k * 10.0, -40.0, 0);
        jw_cmd_point(d, app_view(), -40.0 + k * 10.0, -10.0, 0);
    }
    n0 = d->ndrawn;
    jw_cmd_point(d, app_view(), 50.0, 50.0, 0);      /* a first point down */
    ck(jw_cmd_midway(), "  線 with its first point down is part way");
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == n0 && !jw_cmd_midway(),
       "  戻る lets go of the point and leaves the lines alone");
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == n0 - 1, "  and the next 戻る takes the last line off");

    jw_cmd_set(JW_CMD_CHUSHIN);
    jw_cmd_point(d, app_view(), -40.0, -25.0, 0);    /* one line picked */
    ck(jw_cmd_midway(), "  中心線 with one line picked is part way");
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == n0 - 1 && !jw_cmd_midway(),
       "  戻る drops the pick, not a line");

    /* 中心線 steps back one pick a press (FUN_0063d5f0: 3 -> 2 -> 1) */
    jw_cmd_point(d, app_view(), -40.0, -25.0, 0);
    jw_cmd_point(d, app_view(), -30.0, -25.0, 0);    /* two lines picked */
    app_command(JW_CMD_UNDO);
    ck(jw_cmd_midway() && d->ndrawn == n0 - 1,
       "  with two lines picked, 戻る drops only the second");
    app_command(JW_CMD_UNDO);
    ck(!jw_cmd_midway() && d->ndrawn == n0 - 1, "  and the next the first");

    /* 進む in the middle of a command: the step goes back at the front of
       the drawing, every element moves along one, and the line 中心線 had
       picked has to be the same line afterwards -- the original holds the
       element, not its place */
    {
        int k, before;

        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_SEN);
        jw_cmd_point(d, app_view(), 60.0, 0.0, 0);   /* a line to undo */
        jw_cmd_point(d, app_view(), 60.0, 30.0, 0);
        jw_cmd_set(JW_CMD_TEN);
        app_command(JW_CMD_UNDO);                     /* now 進む can redo it */
        before = d->ndrawn;
        jw_cmd_set(JW_CMD_CHUSHIN);
        jw_cmd_point(d, app_view(), -40.0, -25.0, 0); /* x = -40 */
        app_command(JW_CMD_REDO);
        jw_cmd_point(d, app_view(), -30.0, -25.0, 0); /* x = -30 */
        jw_cmd_point(d, app_view(), -35.0, -45.0, 0);
        jw_cmd_point(d, app_view(), -35.0, -5.0, 0);
        k = d->ndrawn - 1;
        ck(d->ndrawn == before + 2 && d->obj[k].cls == JW_SEN
           && d->obj[k].d[0] > -35.01 && d->obj[k].d[0] < -34.99
           && d->obj[k].d[2] > -35.01 && d->obj[k].d[2] < -34.99,
           "  中心線 still uses the line it picked after a 進む in between");
        jw_cmd_set(JW_CMD_TEN);
    }

    /* ２線 and 接円 step back one at a time too */
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_NISEN);
    n0 = d->ndrawn + 1;                 /* (so n0 - 1 is the count now) */
    type_box(1412, "500");
    jw_cmd_point(d, app_view(), -40.0, -25.0, 0);    /* the line */
    jw_cmd_point(d, app_view(), -40.0, -40.0, 0);    /* the start */
    app_command(JW_CMD_UNDO);
    ck(jw_cmd_midway(), "  ２線: 戻る after the start point keeps the line");
    app_command(JW_CMD_UNDO);
    ck(!jw_cmd_midway() && d->ndrawn == n0 - 1, "    and the next drops it");
    type_box(1412, "");

    jw_cmd_set(JW_CMD_CHUSHIN);
    jw_cmd_point(d, app_view(), -40.0, -25.0, 0);
    app_new();
    ck(!jw_cmd_midway(), "  and 新規 drops a pick made in the last drawing");
    jw_cmd_set(JW_CMD_TEN);
}

/* The text line holds 254 bytes, and a character of two bytes comes as two
   keys.  It used to take a lead byte into the last free place and refuse
   the trail after it, so 253 letters and then あ left the text ending in
   half a character. */
static void text_full_of_kanji(void)
{
    static const int PRE[3] = { 251, 252, 253 };
    int p, i;

    for (p = 0; p < 3; p++) {
        const char *l;
        int n, whole = 1;

        jw_cmd_set(JW_CMD_MOJI);
        for (i = 0; i < 300; i++)
            jw_cmd_key(8);
        for (i = 0; i < PRE[p]; i++)
            jw_cmd_key('a');
        jw_cmd_key(0x82);               /* あ */
        jw_cmd_key(0xa0);
        jw_cmd_key(0x82);               /* い */
        jw_cmd_key(0xa2);
        l = jw_cmd_line();
        n = (int)strlen(l);
        for (i = 0; i < n; i++)
            if ((unsigned char)l[i] == 0x82) {
                if (i + 1 >= n)
                    whole = 0;
                i++;
            }
        ck(whole && n <= 254, PRE[p] == 251 ? "  文字の行が埋まっても、二バイトの字が半分で切れない（251 字のあと）"
                            : PRE[p] == 252 ? "    （252 字のあと）" : "    （253 字のあと）");
        for (i = 0; i < 300; i++)
            jw_cmd_key(8);
    }
    jw_cmd_set(JW_CMD_TEN);
}

/* Zooming in on a drawing with text in it.  Every character used to be
   sampled up to (w + h)^2 times whether it was on the window or not, so a
   repaint of Test7 at 256 times took ten seconds (src/text.c, glyph).
   With the cells off the window skipped it is a tenth of a second; two
   seconds here leaves room for a slow machine. */
static void zoomed_in_paint(void)
{
    unsigned char *b;
    long n;
    int k, worst = 0;

    b = slurp("orig/Test7.jww", &n);
    if (!b || !app_open(b, n)) {
        free(b);
        ck(0, "  orig/Test7.jww opens");
        return;
    }
    free(b);
    app_fit();
    for (k = 0; k < 12; k++) {
        clock_t t0 = clock();
        int ms;

        app_paint();
        ms = (int)((clock() - t0) * 1000.0 / CLOCKS_PER_SEC);
        if (ms > worst)
            worst = ms;
        app_zoom(2.0, 500 + k * 20, 300 + k * 10);
    }
    printf("     （4096 倍まで、いちばん遅い描き直しで %d ms）\n", worst);
    ck(worst < 2000, "  文字のある図面を拡大しても、描き直しは二秒以内");
}

/* 曲線's スプライン and ベジェ make (points - 1) * 分割数 lines, and a huge
   分割数 used to be taken at its word: nine digits had it adding lines for
   minutes until memory ran out.  It now draws the whole curve or nothing. */
static void huge_curve(void)
{
    static const int MODE[2] = { 1691, 1692 };
    int m;

    for (m = 0; m < 2; m++) {
        jw_drawing *d = fresh();
        int n0 = d->ndrawn, k;

        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_KYOKUSEN);
        jw_cmd_bar(d, MODE[m]);
        type_box(1411, "999999999");
        jw_cmd_point(d, app_view(), -50.0, 0.0, 0);
        jw_cmd_point(d, app_view(), 0.0, 40.0, 0);
        jw_cmd_point(d, app_view(), 50.0, 0.0, 0);
        jw_cmd_bar(d, 1800);            /* 作図実行 */
        ck(d->ndrawn == n0, m ? "  ベジェ with 分割数 999999999 draws nothing"
                              : "  スプライン with 分割数 999999999 draws nothing");
        type_box(1411, "10");
        jw_cmd_point(d, app_view(), -50.0, 0.0, 0);
        jw_cmd_point(d, app_view(), 0.0, 40.0, 0);
        jw_cmd_point(d, app_view(), 50.0, 0.0, 0);
        jw_cmd_bar(d, 1800);
        k = d->ndrawn - n0;
        ck(k > 0 && k <= 20, "  and the same three points with 10 still draw");
        type_box(1411, "");
    }
}

int main(void)
{
    app_resize(1264, 741);
    enter_and_leave();
    click_on_nothing();
    escape_everywhere();
    rubbish_in_the_boxes();
    rubbish_in_every_box();
    undo_past_the_start();
    buttons_at_the_wrong_time();
    keys_under_a_dialog();
    scale_dialog();
    dim_setup_button();
    layer_dialog();
    one_letter_commands();
    rubbish_in_every_dialog();
    huge_curve();
    undo_part_way();
    text_full_of_kanji();
    zoomed_in_paint();
    big_numbers_everywhere();
    press_everything();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
