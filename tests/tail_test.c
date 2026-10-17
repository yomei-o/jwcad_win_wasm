/* 状態行の末尾を、原典で測った答え（tools/jwdraw.ps1 の read:59393）と比べる。
 *
 *   tests/tail_test.exe
 *
 * 1264x741 の窓で decomp/res/new.jww を開き、線を一本引いて 複線 (32800) でその線を拾い、
 * マウスを動かしたときの末尾。原典は 小数 3 桁を切り捨てて出す（四捨五入でなく）:
 *   線の下 4 画素 244.897、12 画素 734.693、28 画素 1,714.285、30 画素 1,836.734、
 *   55 画素 3,367.346、65 画素 3,979.591、80 画素 4,897.959
 * ハッチ (32874) で 三本の線を拾うと  【 0 】< 1 >・【 1 】< 2 >・【 2 】< 3 >、
 * 範囲選択 (1067) → 枠 → 選択確定 (1120) のあとは 【 3 】、その次の線で 【 3 】< 1 >、
 * 範囲選択が済んだ段の問いは 「追加・除外図形指示 … Enter-範囲確定 ShiftEnter-基点変更」。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

static int fails;

static void ck(int ok, const char *what)
{
    if (!ok) {
        printf("BAD  %s\n", what);
        fails++;
    }
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
        fclose(f);
        return 0;
    }
    fclose(f);
    return b;
}

static rect_t R;

static int start(void)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n);

    if (!b) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        return 0;
    }
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    free(b);
    ui_view_rect(app_fb()->w, app_fb()->h, &R);
    return 1;
}

static void line(int x1, int y1, int x2, int y2)
{
    app_command(32771);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    app_press(R.x + x1, R.y + y1, 0);
    app_press(R.x + x2, R.y + y2, 0);
}

static void tail_is(int dy, const char *want)
{
    char what[96];
    const char *st;
    size_t n = strlen(want);

    app_move(R.x + 450, R.y + 300 + dy);
    st = jw_cmd_status(app_drawing());
    snprintf(what, sizeof what, "複線の末尾 %d 画素 -> %s", dy, want);
    ck(strlen(st) > n && !strcmp(st + strlen(st) - n, want), what);
}

int main(void)
{
    const char *st;

    if (!start())
        return 1;
    line(300, 300, 600, 300);
    app_command(32800);
    app_press(R.x + 450, R.y + 300, 0);
    tail_is(4, "244.897");
    tail_is(12, "734.693");
    tail_is(28, "1,714.285");
    tail_is(30, "1,836.734");
    tail_is(55, "3,367.346");
    tail_is(65, "3,979.591");
    tail_is(80, "4,897.959");

    if (!start())
        return 1;
    line(300, 300, 500, 300);
    line(500, 300, 400, 450);
    line(400, 450, 300, 300);
    app_command(32874);
    app_press(R.x + 400, R.y + 300, 0);
    st = jw_cmd_status(app_drawing());
    ck(strstr(st, "\x81y 0 \x81z   < 1 >") != 0, "ハッチ 一本 【 0 】 < 1 >");
    app_press(R.x + 450, R.y + 375, 0);
    st = jw_cmd_status(app_drawing());
    ck(strstr(st, "\x81y 1 \x81z   < 2 >") != 0, "  二本 【 1 】 < 2 >");
    app_press(R.x + 350, R.y + 375, 0);
    st = jw_cmd_status(app_drawing());
    ck(strstr(st, "\x81y 2 \x81z   < 3 >") != 0, "  三本 【 2 】 < 3 >");

    if (!start())
        return 1;
    line(300, 300, 500, 300);
    line(500, 300, 400, 450);
    line(400, 450, 300, 300);
    app_command(32874);
    jw_cmd_bar((jw_drawing *)app_drawing(), 1067);
    app_press(R.x + 250, R.y + 250, 0);
    app_press(R.x + 550, R.y + 500, 0);
    ck(strstr(jw_cmd_status(app_drawing()), "ShiftEnter") != 0
       && strstr(jw_cmd_status(app_drawing()), "Enter-") != 0,
       "ハッチの範囲選択が済んだ段は 追加・除外図形指示 と Enter・ShiftEnter");
    jw_cmd_bar((jw_drawing *)app_drawing(), 1120);
    st = jw_cmd_status(app_drawing());
    ck(strstr(st, "\x81y 3 \x81z") != 0 && !strstr(st, "< "), "選択確定のあと 【 3 】");
    app_press(R.x + 400, R.y + 300, 0);
    st = jw_cmd_status(app_drawing());
    ck(strstr(st, "\x81y 3 \x81z   < 1 >") != 0, "  次の線で 【 3 】 < 1 >");

    printf("%s tail\n", fails ? "BAD " : "ok  ");
    return fails != 0;
}
