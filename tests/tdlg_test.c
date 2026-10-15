/* Dialogs from the original's own templates.
 *
 *   tests/tdlg_test.exe
 *
 * src/gen/dlgtpl.h lays the templates in decomp/res/dialog.txt out in pixels
 * with Windows' MapDialogRect sum (tools/mkdlgtpl.py).  Whether that sum is
 * the original's is something the original has already answered: ten of its
 * dialogs were read off it control by control (tools/jwdraw.ps1's `dlg:`
 * step, decomp/res/<name>.txt), and each of them is one of the templates.
 * So first every one of those is held to the template -- the client area
 * and the rectangle of every control that has an id of its own.
 *
 * Then the dialogs the port puts up from a template: each command opens
 * one, it paints, a check toggles, typing goes into an edit box, and Esc,
 * OK and the × take it down.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/ui.h"
#include "../src/cmd.h"

static int fails;
static void press_ctl(int id, int button);

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* Controls the original sizes for itself once the dialog is up, so that
   only where they are comes from the template.  線属性's eighteen pen and
   line-type buttons are its own button class, and every one of them came
   out 54x16 where the template says 53x17 or 53x18 -- at exactly the
   template's place. */
static int sized_at_run(const char *name, int id)
{
    if (!strcmp(name, "zoku"))
        return (id >= 1401 && id <= 1409) || (id >= 2449 && id <= 2457);
    return 0;
}

/* and one it moves as well: combo 1423, in both dialogs that have it.
   寸法設定's came out at 143,30 107 wide where the template puts it at
   144,30 133 wide, and 書込み文字種変更's at 84,26 156 wide where the
   template says 77,27 149 -- the same control, set up by the same code. */
static int moved_at_run(const char *name, int id)
{
    return (!strcmp(name, "sunpodlg") || !strcmp(name, "moji"))
           && id == 1423;
}

/* one capture against one template */
static void against(const char *name, int tpl)
{
    char path[128], line[512], msg[160];
    FILE *f;
    int t = ui_tdlg_find(tpl), cw = 0, ch = 0, n = 0, bad = 0, missing = 0;
    rect_t dr;

    snprintf(path, sizeof path, "decomp/res/%s.txt", name);
    f = fopen(path, "rb");
    if (!f || t < 0) {
        snprintf(msg, sizeof msg, "%s: the capture and template %d are there",
                 name, tpl);
        ck(0, msg);
        if (f)
            fclose(f);
        return;
    }
    ui_tdlg_rect(1264, 741, t, &dr);
    while (fgets(line, sizeof line, f)) {
        char cls[64];
        int id, x, y, w, h, i;
        rect_t r;

        if (!strncmp(line, "=== dialog", 10)) {
            const char *c = strstr(line, "client ");
            if (c)
                sscanf(c, "client %dx%d", &cw, &ch);
            continue;
        }
        if (sscanf(line, "%63[^|]|%d|%d|%d|%d|%d|", cls, &id, &x, &y, &w,
                   &h) != 6 || id == 65535)
            continue;
        i = ui_tdlg_index(t, id);
        if (i < 0) {
            missing++;
            continue;
        }
        ui_tdlg_ctl_rect(1264, 741, t, i, &r);
        r.x -= dr.x + 8;
        r.y -= dr.y + 31;
        n++;
        /* a closed combo's height is the font's, not the template's */
        if (moved_at_run(name, id))
            ;                   /* where the original put it itself */
        else if (r.x != x || r.y != y
            || (!sized_at_run(name, id)
                && (r.w != w || (strcmp(cls, "ComboBox") && r.h != h)))) {
            if (bad < 3)
                printf("     %s %s %d: template %d,%d %dx%d, original %d,%d %dx%d\n",
                       name, cls, id, r.x, r.y, r.w, r.h, x, y, w, h);
            bad++;
        }
    }
    fclose(f);
    snprintf(msg, sizeof msg, "%s (template %d): client %dx%d as the original's",
             name, tpl, cw, ch);
    ck(dr.w - 16 == cw && dr.h - 39 == ch, msg);
    snprintf(msg, sizeof msg, "  and all %d controls with an id on its pixel"
             " (%d differ, %d not in the template)", n, bad, missing);
    ck(n > 0 && bad == 0, msg);
}

static void opens(int cmd, int tpl, const char *what)
{
    char msg[160];
    int t, i, n, k;

    app_new();
    ck(app_command(cmd) == 1 && app_modal() && app_tdlg_tpl() == tpl, what);
    t = app_tdlg_open();
    app_paint();
    n = ui_tdlg_n(t);
    /* a check toggles, and an edit box takes typing */
    for (i = 0; i < n; i++) {
        int id, kind, flags;
        rect_t r;

        ui_tdlg_ctl(t, i, &id, &kind, &flags);
        if (!(flags & 1) || (flags & 2))
            continue;
        if (kind == UI_TC_CHECK) {
            int was = app_tdlg_on(i);

            ui_tdlg_ctl_rect(1264, 741, t, i, &r);
            app_press(r.x + 4, r.y + r.h / 2, 0);
            snprintf(msg, sizeof msg, "  its check %d turns over when pressed", id);
            ck(app_tdlg_on(i) == !was, msg);
            break;
        }
    }
    for (i = 0; i < n; i++) {
        int id, kind, flags;
        rect_t r;

        ui_tdlg_ctl(t, i, &id, &kind, &flags);
        if (kind != UI_TC_EDIT || !(flags & 1) || (flags & 2))
            continue;
        ui_tdlg_ctl_rect(1264, 741, t, i, &r);
        app_press(r.x + 3, r.y + r.h / 2, 0);
        for (k = 0; k < 10; k++)
            app_key(8);
        app_key('4');
        app_key('2');
        snprintf(msg, sizeof msg, "  its edit box %d takes what is typed", id);
        ck(!strcmp(app_tdlg_text(i), "42"), msg);
        break;
    }
    app_key(27);
    ck(!app_modal(), "  and Esc takes it down");
    /* and the x in its caption */
    app_command(cmd);
    {
        rect_t r;

        ui_tdlg_rect(1264, 741, t, &r);
        app_press(r.x + r.w - 23, r.y + 15, 0);
        ck(!app_modal(), "  so does the x");
    }
}

/* the button with this id on the bar now up, pressed where it is */
static int press_bar_id(int id)
{
    int x, y;

    for (y = 0; y < 60; y += 2)
        for (x = 0; x < 1264; x += 2)
            if (ui_bar_hit(x, y) == id) {
                app_press(x, y, 0);
                return 1;
            }
    return 0;
}

/* 複写 with its range settled: the second bar's 作図属性 (1070) puts up
   作図属性設定, template 342 -- not the range selection's 属性変更, which
   is the first bar's 1070 */
static void copy_attributes(void)
{
    static const int CMD[2] = { 32804, 32918 };
    int k;

    for (k = 0; k < 2; k++) {
        const jw_view *v;

        app_new();
        app_command(32771);             /* 線 */
        app_press(400, 300, 0);
        app_press(600, 400, 0);
        app_command(CMD[k]);
        app_press(300, 200, 0);         /* a box round it */
        app_press(700, 500, 0);
        app_move(500, 350);
        ck(press_bar_id(1120), k ? "移動: 選択確定 is on the bar"
                                 : "複写: 選択確定 is on the bar");
        ck(press_bar_id(1070) && app_modal() && app_tdlg_tpl() == 342,
           "  and the next bar's 作図属性 puts up 作図属性設定");
        app_key(27);
        ck(!app_modal(), "  which Esc takes down");
        (void)v;
    }
}

/* 作図属性設定's 書込み ticks: what 複写 puts down takes the write layer and
   colour instead of its own.  The decompilation's reading (FUN_00653fe0),
   not asked of the original. */
static void copy_takes_write_attributes(void)
{
    jw_drawing *d;
    const jw_obj *o;
    int n;

    app_new();
    app_command(32771);                 /* 線, on layer 0 in colour 2 */
    app_press(400, 300, 0);
    app_press(600, 400, 0);
    app_command(32804);                 /* 複写 */
    app_press(300, 200, 0);
    app_press(700, 500, 0);
    app_move(500, 350);
    press_bar_id(1120);
    press_bar_id(1070);
    ck(app_tdlg_tpl() == 342, "作図属性設定 is up for the ticks");
    press_ctl(1323, 0);                 /* 書込み線色 */
    press_ctl(1326, 0);                 /* 書込みレイヤグループ */
    press_ctl(1325, 0);                 /* 書込み【レイヤ】, which takes it off */
    ck(app_tdlg_on(ui_tdlg_index(app_tdlg_open(), 1325))
       && !app_tdlg_on(ui_tdlg_index(app_tdlg_open(), 1326)),
       "  書込み【レイヤ】 takes 書込みレイヤグループ off");
    press_ctl(1, 0);
    ck(!app_modal() && jw_cmd_zuzoku(1) && jw_cmd_zuzoku(2)
       && !jw_cmd_zuzoku(0) && !jw_cmd_zuzoku(3), "  OK keeps the ticks");
    d = (jw_drawing *)app_drawing();
    d->group[0].write_layer = 5;
    d->write_ltype = 1;
    d->write_color = 6;
    n = d->ndrawn;
    app_press(800, 300, 0);             /* where the copy goes */
    o = &d->obj[d->ndrawn - 1];
    ck(d->ndrawn == n + 1 && o->layer == 5 && o->color == 6 && o->ltype == 1,
       "  and the copy goes onto the write layer in the write colour");
    ck(d->obj[0].layer == 0 && d->obj[0].color != 6,
       "  while the line it was copied from keeps its own");
    press_bar_id(1070);
    ck(app_tdlg_tpl() == 342
       && app_tdlg_on(ui_tdlg_index(app_tdlg_open(), 1323)),
       "  opened again it has them ticked");
    press_ctl(1064, 0);                 /* ◇元レイヤ・元線色・元線種 */
    ck(!app_modal() && !jw_cmd_zuzoku(1) && !jw_cmd_zuzoku(2),
       "  and ◇元レイヤ・元線色・元線種 takes them all off and closes");
}

/* 属性選択's ブロック名指定 (2412) puts ブロック名を指定して選択 (340) up
   on top of it; Esc takes down the one on top, and the one under it is
   still there */
static void block_name_over_zokusel(void)
{
    rect_t v;
    int x, y, found = 0;

    app_new();
    app_command(32771);
    app_press(400, 300, 0);
    app_press(600, 400, 0);
    app_command(32787);                         /* 範囲選択 */
    ui_view_rect(1264, 741, &v);
    app_press(v.x + 100, v.y + 100, 0);
    app_press(v.x + v.w - 100, v.y + v.h - 100, 1);
    ck(press_bar_id(1069) && app_zokusel_open(), "範囲選択's ＜属性選択＞ is up");
    for (y = 0; y < 741 && !found; y++)
        for (x = 0; x < 1264 && !found; x++)
            if (ui_zokusel_hit(1264, 741, x, y) == 2412) {
                app_press(x + 3, y + 3, 0);
                found = 1;
            }
    ck(found && app_tdlg_tpl() == 340 && app_zokusel_open(),
       "  ticking ブロック名指定 puts ブロック名を指定して選択 over it");
    app_key(27);
    ck(app_tdlg_open() < 0 && app_zokusel_open(),
       "  Esc takes that one down and leaves 属性選択 up");
    app_key(27);
    ck(!app_modal(), "  and the next Esc takes 属性選択 down too");
}

/* press the control with this id in the dialog from a template that is up */
static void press_ctl(int id, int button)
{
    int t = app_tdlg_open(), i = t >= 0 ? ui_tdlg_index(t, id) : -1;
    rect_t r;

    if (i < 0 || !ui_tdlg_ctl_rect(1264, 741, t, i, &r))
        return;
    app_press(r.x + r.w / 2, r.y + r.h / 2, button);
}

static const char *ctl_text(int id)
{
    int t = app_tdlg_open();

    return t >= 0 ? app_tdlg_text(ui_tdlg_index(t, id)) : "";
}

/* A right press on a bar's box puts up 数値入力 (314).  Its sums are the
   decompilation's, not asked of the original: a column holds one digit of
   its place and the number is their sum, ± turns it over, 「，」 goes on to
   a second number, a right press on a digit is OK as well, and OK writes
   it back into the box. */
static void keypad(void)
{
    int x, y, hit = 0;
    const char *t;

    app_new();
    app_command(0x807e);                        /* 多角形 */
    for (y = 0; y < 60 && !hit; y += 2)
        for (x = 0; x < 1264 && !hit; x += 2)
            if (ui_bar_hit(x, y) == 1411) {
                app_press(x, y, 1);
                hit = 1;
            }
    ck(hit && app_tdlg_tpl() == 314,
       "a right press on 多角形's 寸法 puts up 数値入力");
    app_paint();
    t = ctl_text(1764);
    ck(!strcmp(t, "1000"), "  showing what the box holds");
    press_ctl(1200, 0);                         /* 200 */
    press_ctl(1209, 0);                         /* 3,000 */
    press_ctl(1160, 0);                         /* 8 */
    press_ctl(1186, 0);                         /* 0.7 */
    press_ctl(1201, 0);                         /* 400, over the 200 */
    t = ctl_text(1764);
    ck(!strcmp(t, "3408.7"), "  each column holds one digit, and they add up");
    press_ctl(1, 0);
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "3408.7"),
       "  and OK writes the sum into the box");

    app_press(x - 2, y - 2, 1);
    ck(app_tdlg_tpl() == 314, "the table comes up again");
    press_ctl(1157, 0);                         /* 5 */
    press_ctl(1172, 0);                         /* ± */
    press_ctl(1199, 1);                         /* 200, with the right button */
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "-205"),
       "  ± turns it over, and a right press on a digit is OK as well");

    app_press(x - 2, y - 2, 1);
    press_ctl(1174, 0);                         /* 「，」 */
    press_ctl(1159, 0);                         /* 7 */
    ck(!strcmp(ctl_text(1765), "7"), "  「，」 goes on to a second number");
    app_key(13);
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "-205 , 7"),
       "  which Enter writes after the first, as the original's two-number "
       "boxes have it");

    /* 電卓: 12 × 3 ＝ は 36 で、上の数値にもなり、OK で箱へ（FUN_005d57e0・005d5e40） */
    jw_cmd_box_put(1411, "1000");
    app_press(x - 2, y - 2, 1);
    press_ctl(1441, 0);                         /* １ */
    press_ctl(1442, 0);                         /* ２ */
    ck(!strcmp(ctl_text(1772), "12"), "  the calculator takes 12");
    press_ctl(1453, 0);                         /* × */
    press_ctl(1443, 0);                         /* ３ */
    press_ctl(1451, 0);                         /* ＝ */
    ck(!strcmp(ctl_text(1770), "36") && !strcmp(ctl_text(1764), "36")
       && !strcmp(ctl_text(1772), "0"),
       "  12 × 3 ＝ is 36, and it becomes the number above");
    press_ctl(1, 0);
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "36"), "  which OK writes into the box");
    app_press(x - 2, y - 2, 1);
    press_ctl(1445, 0);                         /* ５ */
    press_ctl(1452, 0);                         /* ÷ */
    press_ctl(1440, 0);                         /* ０ (no leading zero: nothing) */
    press_ctl(1451, 0);                         /* ＝: ÷ by nothing */
    ck(!strcmp(ctl_text(1771), "E"), "  ÷ 0 shows E");
    press_ctl(1460, 0);                         /* ＡＣ */
    ck(!strcmp(ctl_text(1770), "0") && !strcmp(ctl_text(1771), " "), "  and ＡＣ clears it");
    press_ctl(1444, 0);                         /* ４ */
    press_ctl(1456, 0);                         /* √ */
    ck(!strcmp(ctl_text(1764), "2"), "  √4 is 2");
    app_key(27);

    /* 二つの長い数も 切れずに戻る（箱の字は 15 文字までだった） */
    jw_cmd_box_put(1411, "12345.678,98765.432");
    app_press(x - 2, y - 2, 1);
    app_key(13);
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "12345.678 , 98765.432"),
       "  two long numbers come back whole");

    app_press(x - 2, y - 2, 1);
    press_ctl(1161, 0);
    app_key(27);
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "12345.678 , 98765.432"),
       "  and Esc leaves the box as it was");
}

/* the control with this id in 属性選択, pressed */
static int press_zokusel_id(int id)
{
    int x, y;

    for (y = 0; y < 741; y++)
        for (x = 0; x < 1264; x++)
            if (ui_zokusel_hit(1264, 741, x, y) == id) {
                app_press(x + 3, y + 3, 0);
                return 1;
            }
    return 0;
}

/* a block named `name` made of the line in the box (x0,y0)-(x1,y1) */
static void make_block(int x0, int y0, int x1, int y1, const char *name)
{
    app_command(32787);                 /* 範囲選択 */
    app_press(x0, y0, 0);
    app_press(x1, y1, 1);
    app_command(32853);                 /* ブロック化 */
    while (*name)
        app_key(*name++);
    app_key(13);
}

/* ブロック名指定 with a name: 属性選択 keeps the references to that block
   and drops the others.  That OK ticks ブロック指定 as well and anything
   else takes ブロック名指定 off is FUN_00609a10's; matching the name whole
   is the port's guess. */
static void block_name_narrows(void)
{
    const jw_drawing *d;
    rect_t v;
    int i, n = 0, which = -1;

    app_new();
    app_command(32771);
    app_press(400, 300, 0);
    app_press(450, 320, 0);
    app_press(700, 300, 0);
    app_press(750, 320, 0);
    make_block(380, 280, 470, 340, "A");
    make_block(680, 280, 770, 340, "B");
    d = app_drawing();
    for (i = 0; i < d->ndrawn; i++)
        n += d->obj[i].cls == JW_BLOCK;
    ck(n == 2, "two blocks, A and B, to pick from");
    app_command(32787);
    ui_view_rect(1264, 741, &v);
    app_press(v.x + 20, v.y + 20, 0);
    app_press(v.x + v.w - 20, v.y + v.h - 20, 1);
    ck(jw_cmd_sel_count(d) == 2, "  a box round both picks both");
    press_bar_id(1069);
    press_zokusel_id(2412);
    ck(app_tdlg_tpl() == 340, "  ブロック名指定 asks for the name");
    {   /* its box drops the drawing's blocks, sorted: A is the first row */
        int t = app_tdlg_open(), c = ui_tdlg_index(t, 2435), x, y, got = 0;

        press_ctl(2435, 0);
        for (y = 0; y < 741 && !got; y++)
            for (x = 0; x < 1264 && !got; x++)
                if (ui_tdlg_drop_hit(1264, 741, t, c, 2, x, y) == 0) {
                    app_press(x, y, 0);
                    got = 1;
                }
        ck(got && !strcmp(app_tdlg_text(c), "A"),
           "  its box lists the blocks, and the first row is A");
    }
    app_key(13);
    ck(app_tdlg_open() < 0 && app_zokusel_open(),
       "  Enter takes the small one down, 属性選択 stays");
    for (i = 0; i < ui_zokusel_n(); i++)
        if (ui_zokusel_id(i) == 1802)
            which = i;
    ck(which >= 0 && app_zokusel_on()[which],
       "  and ブロック指定 has been ticked with it");
    press_zokusel_id(1);
    n = 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].sel) {
            n++;
            which = i;
        }
    ck(n == 1 && d->obj[which].cls == JW_BLOCK,
       "  OK leaves the one block picked");
    {   /* and it is A's: the reference whose definition is named A */
        int k, ok = 0;

        for (k = d->ndrawn; k < d->nobj; k++)
            if (d->obj[k].cls == JW_LIST
                && d->obj[k].list[0] == d->obj[which].block)
                ok = !strncmp(jw_str(d, d->obj[k].text), "A", 1)
                     && jw_str(d, d->obj[k].text)[1] != 'B';
        ck(ok, "  and it is the one named A");
    }

    /* キャンセル takes ブロック名指定 back off */
    app_command(32787);
    app_press(v.x + 20, v.y + 20, 0);
    app_press(v.x + v.w - 20, v.y + v.h - 20, 1);
    press_bar_id(1069);
    press_zokusel_id(2412);
    app_key(27);
    for (i = 0, which = -1; i < ui_zokusel_n(); i++)
        if (ui_zokusel_id(i) == 2412)
            which = i;
    ck(app_tdlg_open() < 0 && which >= 0 && !app_zokusel_on()[which],
       "  Esc there takes ブロック名指定 back off");
    app_key(27);
}

/* ブロック解除 of two references at once, then 戻る: the drawing comes back
   exactly, order and all (each reference's members went where it was, two
   places, which one add_at could not say -- cmdfuzz seed 715 on Test5) */
static void free_two_then_undo(void)
{
    jw_drawing *d;
    jw_obj *was;
    int n, nd, same;
    rect_t v;

    /* the two references with a line between them, so that their members
       go in at two places apart */
    app_new();
    app_command(32771);
    app_press(400, 300, 0);
    app_press(450, 320, 0);
    app_press(700, 300, 0);
    app_press(750, 320, 0);
    make_block(380, 280, 470, 340, "A");
    app_command(32771);
    app_press(550, 450, 0);
    app_press(600, 470, 0);
    make_block(680, 280, 770, 340, "B");
    d = (jw_drawing *)app_drawing();
    app_command(32787);
    ui_view_rect(1264, 741, &v);
    app_press(v.x + 20, v.y + 20, 0);
    app_press(v.x + v.w - 20, v.y + v.h - 20, 1);
    n = d->nobj;
    nd = d->ndrawn;
    was = (jw_obj *)malloc((size_t)n * sizeof *was);
    memcpy(was, d->obj, (size_t)n * sizeof *was);
    app_command(32909);                 /* ブロック解除 */
    {
        int q, nb = 0;

        for (q = 0; q < d->ndrawn; q++)
            nb += d->obj[q].cls == JW_BLOCK;
        ck(nb == 0 && memcmp(d->obj, was, (size_t)nd * sizeof *was) != 0,
           "ブロック解除 of two references takes both apart");
    }
    jw_cmd_undo(d);
    same = d->nobj == n && d->ndrawn == nd && !memcmp(d->obj, was, (size_t)n * sizeof *was);
    ck(same, "  and 戻る brings the drawing back exactly, order and all");
    free(was);
}

/* コーナー の (R) 線切断 (FUN_00636ee0 → FUN_00471e40 / FUN_004702f0, read
   off the decompile -- 原典では押していない): the line under the click is cut
   there, as wide as the bar's 切断間隔 (1411), and 戻る puts it back */
static int near_(double a, double b) { return a - b < 1e-9 && b - a < 1e-9; }

static void corner_cut(void)
{
    jw_drawing *d;
    jw_obj *o;
    int i, n;
    rect_t v;

    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
    o = jw_add(d, JW_ENKO);
    o->d[0] = 0; o->d[1] = 200; o->d[2] = 50; o->d[3] = 0; o->d[4] = 2 * 3.141592653589793; o->d[5] = 0; o->d[6] = 1;
    app_fit();
    ui_view_rect(1264, 741, &v);
    app_command(32786);
    jw_cmd_box_put(1411, "");
    jw_cmd_point(d, app_view(), 40, 0, 1);
    ck(d->ndrawn == 3 && near_(d->obj[0].d[2], 40) && near_(d->obj[2].d[0], 40)
       && near_(d->obj[2].d[2], 100), "コーナー (R): 間隔が空なら 線はそこで二つに");
    jw_cmd_box_put(1411, "10");
    jw_cmd_point(d, app_view(), 70, 0, 1);
    n = 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN && near_(d->obj[i].d[1], 0)
            && ((near_(d->obj[i].d[0], 40) && near_(d->obj[i].d[2], 65))
                || (near_(d->obj[i].d[0], 75) && near_(d->obj[i].d[2], 100))))
            n++;
    ck(n == 2, "  切断間隔 10 なら 65 から 75 が抜ける");
    jw_cmd_point(d, app_view(), 50, 200, 1);
    o = &d->obj[1];
    if (!(o->cls == JW_ENKO && near_(o->d[4], 2 * 3.141592653589793 - 2 * atan(5.0 / 50.0))))
        printf("     arc %g sweep %.12f\n", o->d[3], o->d[4]);
    ck(o->cls == JW_ENKO && near_(o->d[4], 2 * 3.141592653589793 - 2 * atan(5.0 / 50.0)),
       "  円も 接線の向きに間隔のぶん抜けて弧になる");
    n = d->ndrawn;
    jw_cmd_undo(d);
    ck(d->obj[1].d[4] == 2 * 3.141592653589793, "  戻るで 円に戻る");
    jw_cmd_box_put(1411, "");
    (void)v;
    (void)n;
}

/* コーナー (L)(L) に円弧 (FUN_0046abe0 → FUN_0045fa30 / FUN_0044cfb0、
   逆コンパイルの読み -- 原典では押していない): 線と弧、弧と弧が 拾った側を
   残して交点まで切れる／伸びる。全円は拾わない。戻るで二つとも戻る */
static int nearq(double a, double b) { return fabs(a - b) < 1e-6; }

static jw_obj *add_arc(jw_drawing *d, double cx, double cy, double r, double st, double sw)
{
    jw_obj *o = jw_add(d, JW_ENKO);
    o->d[0] = cx; o->d[1] = cy; o->d[2] = r; o->d[3] = st; o->d[4] = sw;
    o->d[5] = 0; o->d[6] = 1;
    return o;
}

static void corner_arcs(void)
{
    const double P = 3.141592653589793;
    jw_drawing *d;
    jw_obj *o, was[3];
    int ok;

    /* 線 と 弧: 線の先 (40,30) で弧の始点が動く（拾った 45° 側が残る） */
    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN);
    o->d[0] = -200; o->d[1] = 30; o->d[2] = -100; o->d[3] = 30;
    add_arc(d, 0, 0, 50, 0, P / 2);
    app_fit();
    app_command(32786);
    memcpy(was, d->obj, 2 * sizeof *was);
    jw_cmd_point(d, app_view(), -110, 30, 0);
    jw_cmd_point(d, app_view(), 50 * cos(P / 4), 50 * sin(P / 4), 0);
    ok = nearq(d->obj[0].d[0], -200) && nearq(d->obj[0].d[2], 40) && nearq(d->obj[0].d[3], 30)
         && nearq(d->obj[1].d[3], atan2(30, 40)) && nearq(d->obj[1].d[4], P / 2 - atan2(30, 40));
    if (!ok)
        printf("     line %g,%g-%g,%g arc %.9f %.9f\n", d->obj[0].d[0], d->obj[0].d[1],
               d->obj[0].d[2], d->obj[0].d[3], d->obj[1].d[3], d->obj[1].d[4]);
    ck(ok, "コーナー 線と弧: 線は (40,30) まで伸び 弧は始点がそこへ");
    jw_cmd_undo(d);
    ck(!memcmp(d->obj, was, 2 * sizeof *was), "  戻るで 線も弧も戻る");

    /* 弧の終わりの先の交点: 終わりに近い所を拾えば 終わりが伸びる */
    app_new();
    d = (jw_drawing *)app_drawing();
    add_arc(d, 0, 0, 50, 0, P / 4);
    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 100; o->d[2] = 0; o->d[3] = 200;
    app_fit();
    app_command(32786);
    jw_cmd_point(d, app_view(), 50 * cos(P * 40 / 180), 50 * sin(P * 40 / 180), 0);
    jw_cmd_point(d, app_view(), 0, 110, 0);
    ok = nearq(d->obj[0].d[3], 0) && nearq(d->obj[0].d[4], P / 2)
         && nearq(d->obj[1].d[1], 50) && nearq(d->obj[1].d[3], 200);
    if (!ok)
        printf("     arc %.9f %.9f line %g,%g-%g,%g\n", d->obj[0].d[3], d->obj[0].d[4],
               d->obj[1].d[0], d->obj[1].d[1], d->obj[1].d[2], d->obj[1].d[3]);
    ck(ok, "  弧が先から: 弧の終わりが 90° まで伸び 線は (0,50) から");

    /* 弧 と 弧: 二つの拾いの中点に近い (30,40) */
    app_new();
    d = (jw_drawing *)app_drawing();
    add_arc(d, 0, 0, 50, 0, P);
    add_arc(d, 60, 0, 50, 0, P);
    app_fit();
    app_command(32786);
    memcpy(was, d->obj, 2 * sizeof *was);
    jw_cmd_point(d, app_view(), 50 * cos(P * 5 / 6), 50 * sin(P * 5 / 6), 0);
    jw_cmd_point(d, app_view(), 60 + 50 * cos(P / 6), 50 * sin(P / 6), 0);
    ok = nearq(d->obj[0].d[3], atan2(40, 30)) && nearq(d->obj[0].d[4], P - atan2(40, 30))
         && nearq(d->obj[1].d[3], 0) && nearq(d->obj[1].d[4], atan2(40, -30));
    if (!ok)
        printf("     arcs %.9f %.9f / %.9f %.9f\n", d->obj[0].d[3], d->obj[0].d[4],
               d->obj[1].d[3], d->obj[1].d[4]);
    ck(ok, "  弧と弧: どちらも (30,40) まで、拾った側が残る");
    jw_cmd_undo(d);
    ck(!memcmp(d->obj, was, 2 * sizeof *was), "  戻るで 弧が二つとも戻る");

    /* 全円は 線【A】にも【B】にもならない */
    app_new();
    d = (jw_drawing *)app_drawing();
    add_arc(d, 0, 0, 50, 0, 2 * P)->n = 1;
    o = jw_add(d, JW_SEN);
    o->d[0] = -200; o->d[1] = 30; o->d[2] = -100; o->d[3] = 30;
    app_fit();
    app_command(32786);
    memcpy(was, d->obj, 2 * sizeof *was);
    jw_cmd_point(d, app_view(), 50, 0, 0);
    jw_cmd_point(d, app_view(), -110, 30, 0);
    jw_cmd_point(d, app_view(), 0, 50, 0);
    ok = !memcmp(d->obj, was, 2 * sizeof *was);
    jw_cmd_escape();
    ck(ok, "  全円は拾わない（5207 円です。切断で弧にしてください。）");
/* 小物（逆コンパイルの読み、原典では押していない）:
 *   面取 の (R) 線切断（FUN_00636ee0、幅は 面取 のバーの 1413）
 *   接線 点→円 の点 (R)Read（FUN_00704680）、曲線 の (R)Read（FUN_006b5740）
 *   消去 の 範囲選択消去 1066・連続範囲選択消去 1067（FUN_0070e760・
 *   FUN_0070e8f0、実行は Enter）と 節間消し 1324（FUN_00712f00） */
static int count_cls(const jw_drawing *d, int cls)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        n += d->obj[i].cls == cls;
    return n;
}

static int has_line(const jw_drawing *d, double x0, double y0, double x1, double y1)
{
    int i;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (o->cls != JW_SEN)
            continue;
        if ((near_(o->d[0], x0) && near_(o->d[1], y0) && near_(o->d[2], x1) && near_(o->d[3], y1))
            || (near_(o->d[0], x1) && near_(o->d[1], y1) && near_(o->d[2], x0) && near_(o->d[3], y0)))
            return 1;
    }
    return 0;
}

static jw_obj *add_line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    return o;
}

static void komono(void)
{
    jw_drawing *d;
    jw_obj *o;
    int i, n, ok;

    /* 面取 (R): 切断間隔は 1413。1411（面取の寸法）は見ない */
    app_new();
    d = (jw_drawing *)app_drawing();
    add_line(d, 0, 0, 100, 0);
    add_line(d, 0, 300, 0, 400);        /* 画面を広げるだけ */
    app_fit();
    app_command(32859);
    jw_cmd_box_put(1411, "30");
    jw_cmd_box_put(1413, "10");
    jw_cmd_point(d, app_view(), 50, 0, 1);
    ck(has_line(d, 0, 0, 45, 0) && has_line(d, 55, 0, 100, 0),
       "面取 (R): 切断間隔 1413 のぶん 45 から 55 が抜ける");
    jw_cmd_box_put(1413, "");
    jw_cmd_point(d, app_view(), 20, 0, 1);
    ck(has_line(d, 0, 0, 20, 0) && has_line(d, 20, 0, 45, 0),
       "  空なら そこで二つに");
    jw_cmd_box_put(1411, "");

    /* 接線 点→円: 点の段の (R) は読んだ点 */
    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_ENKO);
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 50; o->d[3] = 0; o->d[4] = 2 * 3.141592653589793; o->d[5] = 0; o->d[6] = 1;
    add_line(d, 100, 0, 100, 50);
    app_fit();
    app_command(32870);
    jw_cmd_bar(d, 1690);
    n = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.3, 0.2, 1);
    jw_cmd_point(d, app_view(), 25, 43.3, 0);
    ok = d->ndrawn == n + 1 && d->obj[n].cls == JW_SEN
         && d->obj[n].d[0] == 100.0 && d->obj[n].d[1] == 0.0
         && near_(d->obj[n].d[2], 25) && fabs(d->obj[n].d[3] - 43.30127018922193) < 1e-9;
    if (!ok && d->ndrawn > n)
        printf("     %g %g %g %g\n", d->obj[n].d[0], d->obj[n].d[1], d->obj[n].d[2], d->obj[n].d[3]);
    ck(ok, "接線 点→円 (R)Read: 線の端 (100,0) から接線");

    /* 曲線 スプライン: (R) は読んだ点 */
    app_new();
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < 3; i++) {
        o = jw_add(d, JW_TEN);
        o->d[0] = 50.0 * i;
        o->d[1] = i == 1 ? 30.0 : 0.0;
    }
    app_fit();
    app_command(32908);
    jw_cmd_bar(d, 1691);
    jw_cmd_box_put(1411, "4");
    jw_cmd_point(d, app_view(), 0.2, -0.3, 1);
    jw_cmd_point(d, app_view(), 50.3, 29.8, 1);
    jw_cmd_point(d, app_view(), 99.7, 0.2, 1);
    n = d->ndrawn;
    jw_cmd_bar(d, 1800);
    ok = d->ndrawn > n && d->obj[n].d[0] == 0.0 && d->obj[n].d[1] == 0.0
         && d->obj[d->ndrawn - 1].d[2] == 100.0 && d->obj[d->ndrawn - 1].d[3] == 0.0;
    ck(ok, "曲線 (R)Read: スプラインは読んだ点 (0,0) から (100,0) まで");

    /* 消去 範囲選択消去 (1066) */
    app_new();
    d = (jw_drawing *)app_drawing();
    add_line(d, 0, 0, 10, 0);
    add_line(d, 0, 5, 10, 5);
    add_line(d, 100, 0, 110, 0);
    add_line(d, 100, 100, 110, 100);
    app_fit();
    app_command(32794);
    ck(jw_cmd_bar(d, 1066) != 0, "消去 1066: 範囲選択消去に入る");
    jw_cmd_point(d, app_view(), -5, -5, 0);
    jw_cmd_point(d, app_view(), 20, 10, 0);
    ck(jw_cmd_sel_count(d) == 2, "  箱で二本選ぶ");
    jw_cmd_enter_key(d);
    ck(d->ndrawn == 2 && has_line(d, 100, 0, 110, 0) && has_line(d, 100, 100, 110, 100),
       "  Enter で消える");
    jw_cmd_point(d, app_view(), 105, 100, 1);
    ck(d->ndrawn == 1, "  そのあと (R) は元の消去（1066 は一回きり）");
    jw_cmd_undo(d);
    jw_cmd_undo(d);
    ck(d->ndrawn == 4, "  戻る二つで 四本に");

    /* 連続範囲選択消去 (1067) */
    ck(jw_cmd_bar(d, 1067) != 0, "消去 1067: 連続範囲選択消去に入る");
    jw_cmd_point(d, app_view(), -5, -5, 0);
    jw_cmd_point(d, app_view(), 20, 10, 0);
    jw_cmd_enter_key(d);
    jw_cmd_point(d, app_view(), 95, -5, 0);
    jw_cmd_point(d, app_view(), 120, 10, 0);
    jw_cmd_enter_key(d);
    ck(d->ndrawn == 1 && has_line(d, 100, 100, 110, 100), "  箱を二つ続けて消せる");
    jw_cmd_esc_key(d);

    /* 節間消し (1324) */
    app_new();
    d = (jw_drawing *)app_drawing();
    add_line(d, 0, 0, 100, 0);
    add_line(d, 30, -10, 30, 10);
    add_line(d, 70, -10, 70, 10);
    o = jw_add(d, JW_ENKO);
    o->d[0] = 0; o->d[1] = 200; o->d[2] = 50; o->d[3] = 0; o->d[4] = 2 * 3.141592653589793; o->d[5] = 0; o->d[6] = 1;
    add_line(d, -100, 200, 100, 200);
    app_fit();
    app_command(32794);
    jw_cmd_bar(d, 1324);
    ck(jw_cmd_bar_check(1324) > 0, "消去 節間消し 1324 が入る");
    jw_cmd_point(d, app_view(), 50, 0, 0);
    ck(has_line(d, 0, 0, 30, 0) && has_line(d, 70, 0, 100, 0) && !has_line(d, 0, 0, 100, 0),
       "  拾った点の両側の交わり 30 と 70 のあいだが消える");
    jw_cmd_point(d, app_view(), 10, 0, 0);
    ck(!has_line(d, 0, 0, 30, 0) && has_line(d, 70, 0, 100, 0),
       "  端と交わりのあいだは そのまま消える");
    jw_cmd_point(d, app_view(), 0, 250, 0);
    o = 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_ENKO)
            o = &d->obj[i];
    ok = o && fabs(fabs(o->d[4]) - 3.141592653589793) < 1e-9
         && fabs(o->d[3] - 3.141592653589793) < 1e-9;
    if (o && !ok)
        printf("     arc %.12f %.12f\n", o->d[3], o->d[4]);
    ck(ok, "  円は 上の半分（交わり 0° と 180° のあいだ）が消えて 180° からの半円に");
    jw_cmd_point(d, app_view(), 0, 150, 0);
    ck(count_cls(d, JW_ENKO) == 0, "  残った半円は 両端まで消えて無くなる");
    jw_cmd_undo(d);
    ck(count_cls(d, JW_ENKO) == 1, "  戻るで半円が戻る");
    jw_cmd_bar(d, 1324);
}

/* The command bars, against their templates.  A bar is a child dialog 462
   units wide, laid out by the same sum, and the strip puts it 6 pixels in
   and 5 down.  For every bar the port read off the original
   (src/gen/bars.h), the bar template whose controls match it best is taken
   and every control with an id is held to it. */
#include "../src/gen/bars.h"
static void bars_against_templates(void)
{
    int b, all = 0, bad = 0, unmatched = 0;
    char msg[200];

    for (b = 0; b < JW_NBARS; b++) {
        const jw_bar_t *bar = &jw_bars[b];
        int t, best = -1, best_hit = -1, best_n = 0, k;

        for (t = 0; t < ui_tdlg_count(); t++) {
            int hit = 0, n = 0;

            if (!ui_tdlg_is_bar(t))
                continue;
            for (k = 0; k < bar->n; k++) {
                const jw_ctl_t *c = &bar->c[k];
                int i = c->id == 0xffff ? -1 : ui_tdlg_index(t, c->id);
                rect_t r;

                if (i < 0)
                    continue;
                n++;
                ui_tdlg_ctl_xy(t, i, &r);
                if (r.x + 6 == c->x && r.y + 5 == c->y && r.w == c->w)
                    hit++;
            }
            if (hit > best_hit) {
                best_hit = hit;
                best = t;
                best_n = n;
            }
        }
        for (k = 0; k < bar->n; k++)
            if (bar->c[k].id != 0xffff)
                all++;
        if (best < 0 || best_n == 0) {
            unmatched++;
            continue;
        }
        if (best_hit != best_n) {
            if (bad < 6)
                printf("     bar %u: template %d matches %d of %d\n", bar->cmd,
                       ui_tdlg_tpl(best), best_hit, best_n);
            bad += best_n - best_hit;
        }
    }
    snprintf(msg, sizeof msg, "the %d command bars sit on their templates' pixels"
             " (%d of %d controls differ, %d bars with no template)",
             JW_NBARS, bad, all, unmatched);
    ck(bad == 0, msg);
}

/* 線上点・交点取得 (33017) の二つ目（CSunpouZukeiKa の 20 番目 FUN_0076fae0、
   逆コンパイルの読み -- 原典では押していない): (L) で拾った別の線・円との
   交点（クリックに近い方）、(R) は読取点。どちらも最初の要素へ落とす */
static int seg_is(const jw_obj *o, double x0, double y0, double x1, double y1)
{
    return o->cls == JW_SEN && nearq(o->d[0], x0) && nearq(o->d[1], y0)
           && nearq(o->d[2], x1) && nearq(o->d[3], y1);
}

static void senjou_cross(void)
{
    const double P = 3.141592653589793;
    jw_drawing *d;
    jw_obj *o;
    int n;

    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN);
    o->d[0] = -100; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
    add_arc(d, 0, 0, 50, 0, 2 * P)->n = 1;
    app_fit();
    app_command(0x8003);
    n = d->ndrawn;
    jw_cmd_point(d, app_view(), 50, 80, 0);
    app_command(33017);
    jw_cmd_point(d, app_view(), 80, 0, 0);
    jw_cmd_point(d, app_view(), 50 * cos(P / 9), 50 * sin(P / 9), 0);
    ck(d->ndrawn == n + 1 && seg_is(&d->obj[n], 50, 80, 50, 0),
       "線上点 (L) 円の上: 線と円の交点のうちクリックに近い (50,0)");
    app_command(33017);
    jw_cmd_point(d, app_view(), 80, 0, 0);
    jw_cmd_point(d, app_view(), 50, 80, 1);
    jw_cmd_point(d, app_view(), 50, -80, 0);
    ck(d->ndrawn == n + 2 && seg_is(&d->obj[n + 1], 50, 0, 50, -80),
       "  (R) は読取点 (50,80) を線へ落として (50,0)");
    app_command(33017);
    jw_cmd_point(d, app_view(), 0, 50, 0);
    jw_cmd_point(d, app_view(), -30, 0, 0);
    jw_cmd_point(d, app_view(), -50, -80, 0);
    if (!(d->ndrawn == n + 3 && seg_is(&d->obj[n + 2], -50, 0, -50, -80)))
        printf("     %d %g,%g-%g,%g\n", d->ndrawn - n, d->obj[d->ndrawn - 1].d[0],
               d->obj[d->ndrawn - 1].d[1], d->obj[d->ndrawn - 1].d[2], d->obj[d->ndrawn - 1].d[3]);
    ck(d->ndrawn == n + 3 && seg_is(&d->obj[n + 2], -50, 0, -50, -80),
       "  円を拾って (L) 線の上: 交点 (-50,0)");
}

/* 中心線の 中心線寸法 (1412): 箱があれば 始点から箱の長さ（÷縮尺）だけ、
   終点の側へ（FUN_0063cc50 の読み、原典では押していない） */
static void chushin_len(void)
{
    jw_drawing *d;
    jw_obj *o;
    double s = 1.0, len;
    int i, n;

    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 200; o->d[3] = 0;
    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 100; o->d[2] = 200; o->d[3] = 100;
    app_fit();
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3 && d->group[i].scale > 0.0)
            s = d->group[i].scale;
    len = 30.0 / s;
    app_command(0x8069);
    jw_cmd_box_put(1412, "-30");
    n = d->ndrawn;
    jw_cmd_point(d, app_view(), 100, 0, 0);
    jw_cmd_point(d, app_view(), 100, 100, 0);
    jw_cmd_point(d, app_view(), 20, 50, 0);
    jw_cmd_point(d, app_view(), 150, 50, 0);
    ck(d->ndrawn == n + 1 && seg_is(&d->obj[n], 20, 50, 20 + len, 50),
       "中心線寸法 -30: 始点から 30÷縮尺 だけ 終点の側へ");
    jw_cmd_point(d, app_view(), 20, 50, 0);
    jw_cmd_point(d, app_view(), 10, 50, 0);
    ck(d->ndrawn == n + 2 && seg_is(&d->obj[n + 1], 20, 50, 20 - len, 50),
       "  終点が逆なら 逆へ");
    jw_cmd_box_put(1412, "");
    jw_cmd_point(d, app_view(), 20, 50, 0);
    jw_cmd_point(d, app_view(), 150, 50, 0);
    ck(d->ndrawn == n + 3 && seg_is(&d->obj[n + 2], 20, 50, 150, 50),
       "  空なら 終点まで（従来どおり）");
}

int main(void)
{
    static const struct { const char *name; int tpl; } CAP[] = {
        { "shakudo", 277 }, { "jikkaku", 282 }, { "sunpodlg", 311 },
        { "bairitsu", 312 }, { "zoku", 271 }, { "blkname", 335 },
        { "blkedit", 354 }, { "layerdlg", 269 }, { "zokusel", 317 },
        { "zokuhen", 317 }, { "moji", 270 }, { "mojikijun", 276 },
    };
    unsigned i;

    app_resize(1264, 741);
    printf("-- the templates against what the original's own windows were\n");
    for (i = 0; i < sizeof CAP / sizeof CAP[0]; i++)
        against(CAP[i].name, CAP[i].tpl);

    bars_against_templates();
    printf("-- the dialogs put up from a template\n");
    opens(59392, 273, "表示 > ツールバー puts up ツールバーの表示");
    opens(32995, 384, "表示 > ブロックツリー半透明化 puts up its 透過率");
    opens(57664, 100, "ヘルプ > バージョン情報");
    opens(32977, 368, "ファイル一括変換");
    opens(32979, 371, "ファイル名変更 puts up ファイル選択");
    opens(32980, 371, "ファイル削除 puts up ファイル選択");
    opens(32984, 371, "ファイル属性変更 puts up ファイル選択");
    copy_attributes();
    block_name_over_zokusel();
    keypad();
    copy_takes_write_attributes();
    block_name_narrows();
    free_two_then_undo();
    corner_cut();
    corner_arcs();
    senjou_cross();
    chushin_len();
    komono();

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
