/* Every drawing command, driven the way a person drives it.
 *
 *   tests/hand_test.exe [--list]
 *
 * The other tests reach into the command layer.  This one has only what a
 * person has: the toolbar button, the boxes on the command bar, and clicks
 * in the drawing area -- app_press, app_key, app_move and nothing else.
 *
 * For each command it presses the button, gives it up to six clicks on the
 * drawing that is open, and asks two things:
 *
 *   * does the button put that command in force, and
 *   * does the drawing grow?
 *
 * A command that cannot be driven this way is one a person cannot use, so
 * the list it prints is the list of what is left to do.  Commands that only
 * change something (属性取得) or need a dialog are named below and only
 * have to answer the first question.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"
#include "../src/view.h"

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

/* the toolbar button for a command, pressed the way a mouse presses it */
static int press_button(int cmd)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == cmd) {
            app_press(jw_buttons[k].x + BTN_W / 2,
                      jw_buttons[k].y + BTN_H / 2, 0);
            return 1;
        }
    return 0;
}

static const struct {
    unsigned short cmd;
    const char *name;
    int draws;              /* 1: a plain clicker can drive it.  0: it
                               needs a recipe of its own -- two lines that
                               meet, a circle to take a tangent of, 作図実行
                               at the end -- and has its own test for that
                               (tests/mentori_test.c and the rest). */
} CMD[] = {
    { 0x8003, "線",         1 },
    { 0x8004, "矩形",       1 },
    { 0x8005, "円",         1 },
    { 0x8011, "点",         1 },
    { 0x8073, "連続線",     1 },
    { 0x8012, "コーナー処理", 0 },
    { 0x8017, "線伸縮",     0 },
    { 0x801a, "消去",       0 },
    { 0x8020, "複線",       1 },
    { 0x8026, "文字",       1 },
    { 0x804f, "寸法",       0 },
    { 0x807e, "多角形",     1 },
    { 0x805b, "面取",       0 },
    { 0x8063, "分割",       0 },
    { 0x807c, "２線",       0 },
    { 0x8069, "中心線",     0 },
    { 0x8066, "接線",       0 },
    { 0x8068, "接円",       0 },
    { 0x808c, "曲線",       0 },
    { 0x806a, "ハッチ",     0 },
    { 0x804e, "包絡処理",   0 },
    { 0x8013, "範囲選択",   0 },
    { 0x8024, "複写",       0 },
    { 0x8096, "移動",       0 },
    { 0x80a3, "属性取得",   0 },
    { 0x80b8, "属性変更",   0 },
    { 0x808e, "データ整理", 0 }
};

int main(int argc, char **argv)
{
    int list = argc > 1 && !strcmp(argv[1], "--list");
    int c, drove = 0, could = 0;
    unsigned char *b;
    long n;

    app_resize(1264, 741);
    for (c = 0; c < (int)(sizeof CMD / sizeof CMD[0]); c++) {
        jw_drawing *d;
        int before, k, grew, np = 0;
        int PT[8][2];

        b = slurp("orig/Test5.jww", &n);
        if (!b || !app_open(b, n)) {
            printf("BAD  cannot open orig/Test5.jww\n");
            return 1;
        }
        free(b);
        d = (jw_drawing *)app_drawing();
        app_fit();
        if (!press_button(CMD[c].cmd)) {
            printf("BAD  %s has no button on the toolbar\n", CMD[c].name);
            fails++;
            continue;
        }
        if (jw_cmd() != CMD[c].cmd) {
            printf("BAD  %s: its button does not put it in force\n",
                   CMD[c].name);
            fails++;
            continue;
        }
        could++;
        /* the points to click: the middles and the ends of the lines that
           are already in the drawing, in screen pixels.  A command that has
           to pick something needs somewhere real to pick, and the middle of
           an empty view is not it. */
        {
            const jw_view *v = app_view();
            int i, ch = JW_CHROME_H, pass;
            /* two passes: the middles of the lines first, which is where a
               command that picks one wants the mouse, and then their ends,
               which are the points 読取 can find.  Both are what a person
               aims at. */
            for (pass = 0; pass < 2 && np < 8; pass++)
                for (i = 0; i < d->ndrawn && np < 8; i++) {
                    const jw_obj *o = &d->obj[i];
                    double x, y;
                    if (o->cls != JW_SEN)
                        continue;
                    if (pass == 0) {
                        x = (o->d[0] + o->d[2]) / 2.0;
                        y = (o->d[1] + o->d[3]) / 2.0;
                    } else {
                        x = o->d[0];
                        y = o->d[1];
                    }
                    PT[np][0] = jw_sx(v, x);
                    PT[np][1] = jw_sy(v, y) + ch;
                    if (PT[np][0] > 80 && PT[np][0] < 1100
                        && PT[np][1] > ch && PT[np][1] < 700)
                        np++;
                }
        }
        if (np < 3) {
            printf("BAD  %s: nothing in the drawing to click on\n", CMD[c].name);
            fails++;
            continue;
        }
        if (CMD[c].cmd == 0x8026) {     /* 文字 wants something typed first */
            app_key('A');
            app_key('B');
        }
        before = d->ndrawn;
        for (k = 0; k < np && k < 8; k++) {
            app_move(PT[k][0], PT[k][1]);
            app_press(PT[k][0], PT[k][1], 0);
        }
        grew = d->ndrawn != before;
        if (grew)
            drove++;
        else if (CMD[c].draws && list)
            printf("     %s draws nothing from six clicks\n", CMD[c].name);
        if (CMD[c].draws)
            ck(grew, CMD[c].name);
    }
    printf("ok   %d of %d commands take their button, %d of them draw\n",
           could, (int)(sizeof CMD / sizeof CMD[0]), drove);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
