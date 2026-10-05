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

#include "../src/app.h"
#include "../src/ui.h"
#include "../src/cmd.h"

static int fails;

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

    app_press(x - 2, y - 2, 1);
    press_ctl(1161, 0);
    app_key(27);
    t = jw_cmd_box(1411);
    ck(!app_modal() && t && !strcmp(t, "-205 , 7"),
       "  and Esc leaves the box as it was");
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

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
