/* Esc lets go of the points a command has taken, in every command that
 * takes any.
 *
 *   tests/esc_test.exe
 *
 * The original does this: its status line goes back.  In 矩形 a first click
 * turns 「始点を指示してください」 into 「◆　　終点を指示してください」
 * and Esc turns it back; in 円 「中心点」 becomes 「円位置」 and back; in
 * 寸法 「引出し線の始点」 becomes 「寸法線の位置」 and back.  (The key has
 * to be sent to the *frame* to see this: a driven session never gives the
 * view the focus, which is why an earlier look said Esc did nothing.)
 *
 * The rule this checks is the one that holds for every command: after Esc,
 * the command asks for what it asked for when it was entered.
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

/* every command that takes points before it draws */
static const struct { unsigned short cmd; const char *name; } CMD[] = {
    { 0x8003, "線" },
    { 0x8004, "矩形" },
    { 0x8005, "円" },
    { 0x8011, "点" },
    { 0x8073, "連続線" },
    { 0x8012, "コーナー処理" },
    { 0x8017, "線伸縮" },
    { 0x8020, "複線" },
    { 0x804f, "寸法" },
    { 0x807e, "多角形" },
    { 0x805b, "面取" },
    { 0x8063, "分割" },
    { 0x807c, "２線" },
    { 0x8069, "中心線" },
    { 0x8066, "接線" },
    { 0x8068, "接円" },
    { 0x808c, "曲線" },
    { 0x806a, "ハッチ" },
    { 0x804e, "包絡処理" },
    { 0x8013, "範囲選択" },
    { 0x8024, "複写" },
    { 0x8096, "移動" },
};

int main(void)
{
    unsigned char *b;
    long n;
    jw_drawing *d;
    int c, moved = 0;

    app_resize(1264, 741);
    for (c = 0; c < (int)(sizeof CMD / sizeof CMD[0]); c++) {
        char first[256], after[256], later[256];
        const char *p;
        int k;

        b = slurp("orig/Test5.jww", &n);
        if (!b || !app_open(b, n)) {
            printf("BAD  cannot open orig/Test5.jww\n");
            return 1;
        }
        free(b);
        d = (jw_drawing *)app_drawing();
        app_fit();
        jw_cmd_set(0x8011);             /* by way of 点, so 線 does not flip */
        jw_cmd_set(CMD[c].cmd);
        p = jw_cmd_prompt();
        strncpy(first, p ? p : "", sizeof first - 1);
        first[sizeof first - 1] = 0;

        /* a few clicks, enough for any of them to have taken something */
        for (k = 0; k < 2; k++)
            jw_cmd_point(d, app_view(), -40.0 + k * 20.0, -40.0 - k * 15.0, 0);
        p = jw_cmd_prompt();
        strncpy(after, p ? p : "", sizeof after - 1);
        after[sizeof after - 1] = 0;

        app_key(27);
        p = jw_cmd_prompt();
        strncpy(later, p ? p : "", sizeof later - 1);
        later[sizeof later - 1] = 0;

        if (strcmp(first, after))
            moved++;
        if (strcmp(first, later))
            printf("     %s: asks [%s] to start with, [%s] after the clicks,\n"
                   "     and [%s] after Esc\n", CMD[c].name, first, after, later);
        ck(!strcmp(first, later),
           CMD[c].name);
    }
    ck(moved > 0, "and the clicks did move some of them along");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
