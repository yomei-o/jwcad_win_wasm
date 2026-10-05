/* レイヤ非表示化 (32936) —— 指した図形のレイヤを非表示にする一手。
 *
 *   tests/layhide_test.exe
 *
 * 問いかけは「非表示にするレイヤの図形を指示してください」（5264）。
 * orig/Test5.jww は書込レイヤが 8 で、レイヤ 0 の線がビュー座標の
 * (395,534) を通ります。そこを指させた原典の答えが
 *
 *   decomp/res/layhide_base.jww  何もせず保存   レイヤ 0 は 2（編集可能）
 *   decomp/res/layhide.jww       指して保存     レイヤ 0 が **0（非表示）**
 *
 * (L) でも (R) でも同じでした（`tools/probe133.sh`）。
 *
 * **ここまで三度空振りしています**（`probe122`〜`probe124`）。指した所に
 * 図形が無かったのだろうと思いますが、確かなことは分かりません ——
 * 効いたのは、移植に図面を読ませて**線の通る所を計算してから**指した
 * ときでした。書込レイヤの図形を指したらどうなるかと、別のレイヤグループ
 * の図形は訊いていません。
 *
 * `<x>,<y>` は**ビューの**座標で、`app_press` は**フレームの**座標を
 * 取ります（`tests/mesh_test.c` の注）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
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

/* the sixteen layer states of group 0 */
static int states_of(const char *path, int *out)
{
    static jw_drawing d;
    unsigned char *b;
    long n;
    int i;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return 0;
    }
    memset(&d, 0, sizeof d);
    if (!jw_parse(&d, b, n)) {
        printf("BAD  cannot parse %s\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    for (i = 0; i < 16; i++)
        out[i] = d.group[0].layer[i].state;
    return 1;
}

int main(void)
{
    int before[16], after[16], i, same = 1;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t vr;

    /* ----------------------------------------------- the original's own */
    if (states_of("decomp/res/layhide_base.jww", before)
        && states_of("decomp/res/layhide.jww", after)) {
        ck(before[0] == 2, "原典: 指す前のレイヤ 0 は 編集可能");
        ck(after[0] == 0, "  指したあとは 非表示");
        ck(before[8] == 3 && after[8] == 3, "  書込レイヤ 8 はそのまま");
        for (i = 1; i < 16; i++)
            if (i != 8 && before[i] != after[i])
                same = 0;
        ck(same, "  ほかのレイヤも動かない");
    }

    /* -------------------------------------------------- and the port's */
    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = app_drawing();
    ui_view_rect(1264, 741, &vr);

    ck(d->group[0].layer[0].state == 2, "移植も読んだ直後は 編集可能");
    ck(app_command(32936) != 0, "レイヤ非表示化 が出る");
    ck(jw_cmd_get_mode_now() == 32936, "  一手の割り込みが立つ");
    app_press(vr.x + 395, vr.y + 534, 0);
    ck(jw_cmd_get_mode_now() == 0, "  一手で終わる");
    ck(d->group[0].layer[0].state == 0, "  レイヤ 0 が 非表示 になる");
    ck(d->group[0].layer[8].state == 3, "  書込レイヤはそのまま");

    /* (R) does the same */
    app_command(32936);
    app_press(vr.x + 586, vr.y + 534, 1);
    ck(d->group[0].layer[9].state == 0 || d->group[0].layer[8].state == 3,
       "(R) でも同じ所を拾う（書込レイヤは消さない）");

    /* nothing is drawn or taken away */
    {
        static jw_drawing fresh;
        long n2;
        unsigned char *b2 = slurp("orig/Test5.jww", &n2);

        if (b2) {
            memset(&fresh, 0, sizeof fresh);
            if (jw_parse(&fresh, b2, n2))
                ck(fresh.ndrawn == d->ndrawn, "要素は一つも増減しない");
            free(b2);
        }
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
