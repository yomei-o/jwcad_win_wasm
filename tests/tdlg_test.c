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

    printf("-- the dialogs put up from a template\n");
    opens(59392, 273, "表示 > ツールバー puts up ツールバーの表示");
    opens(32995, 384, "表示 > ブロックツリー半透明化 puts up its 透過率");
    opens(57664, 100, "ヘルプ > バージョン情報");
    opens(32977, 368, "ファイル一括変換");
    opens(32979, 373, "ファイル名変更 puts up 名称変更");

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
