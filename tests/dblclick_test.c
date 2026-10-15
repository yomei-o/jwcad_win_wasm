/* 画面の (L) 二つが (LL) になるか -- 表側（ネイティブもブラウザも）は
 * ダブルクリックを別に送らず、app_press を同じ所へ二度呼ぶだけです。
 * app.c がそれを jw_cmd_point_ll に直すのは ２線（tests/workflow_test.c）
 * のほかに、文字 の 連 の 移動（LL) と 曲線 の スプラインの 連結する線・
 * 弧指示（LL)。どちらも同じ手順を jw_cmd_point / jw_cmd_point_ll で直に
 * 踏んだ図面と、要素が一つ残らず同じになることを見ます。
 *
 *   tests/dblclick_test.exe
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static jw_drawing *fresh(void)
{
    app_resize(1264, 741);
    app_new();
    app_fit();
    return (jw_drawing *)app_drawing();
}

static double mx(int x) { const jw_view *v = app_view(); return v->ox + (x - v->bx) / v->scale; }
static double my(int y) { const jw_view *v = app_view(); return v->oy + (v->by - y) / v->scale; }

static void click(int x, int y)
{
    app_move(x, y);
    app_press(x, y, 0);
    app_release(x, y, 0);
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

/* the elements a run left behind, kept to set against the other run */
static jw_obj kept[64];
static char kept_text[64][32];
static int nkept;

static void keep(const jw_drawing *d)
{
    int i;

    nkept = 0;
    for (i = 0; i < d->ndrawn && nkept < 64; i++, nkept++) {
        kept[nkept] = d->obj[i];
        kept_text[nkept][0] = 0;
        if (d->obj[i].cls == JW_MOJI)
            snprintf(kept_text[nkept], sizeof kept_text[0], "%s", jw_str(d, d->obj[i].text));
    }
}

static int same(const jw_drawing *d)
{
    int i, k;

    if (d->ndrawn != nkept)
        return 0;
    for (i = 0; i < nkept; i++) {
        if (d->obj[i].cls != kept[i].cls)
            return 0;
        for (k = 0; k < 4; k++)
            if (fabs(d->obj[i].d[k] - kept[i].d[k]) > 1e-9)
                return 0;
        if (d->obj[i].cls == JW_MOJI
            && strcmp(jw_str(d, d->obj[i].text), kept_text[i]) != 0)
            return 0;
    }
    return 1;
}

/* 文字を二つ（AB を (400,300)、CD を (400,400)）置いて 連 を入れる */
static jw_drawing *two_texts(void)
{
    jw_drawing *d = fresh();

    app_command(JW_CMD_MOJI);
    jw_cmd_moji_base(2);
    app_key('A');
    app_key('B');
    jw_cmd_point(d, app_view(), mx(400), my(300), 0);
    app_key('C');
    app_key('D');
    jw_cmd_point(d, app_view(), mx(400), my(400), 0);
    jw_cmd_bar(d, 1068);
    return d;
}

static void ren(void)
{
    jw_drawing *d;
    int n;

    printf("文字 の 連 の 移動（LL):\n");
    d = two_texts();
    ck(strcmp(jw_cmd_prompt(), JW_STR_5473) == 0, "  連 が入る（5473）");
    app_move(405, 300);
    jw_cmd_point_ll(d, app_view(), mx(405), my(300));
    ck(strcmp(jw_cmd_prompt(), JW_STR_5311) == 0, "  直の (LL) で 移動先 を問う（5311）");
    app_move(700, 500);
    jw_cmd_point(d, app_view(), mx(700), my(500), 0);
    keep(d);
    n = nkept;

    d = two_texts();
    app_move(405, 300);
    app_press(405, 300, 0);
    app_release(405, 300, 0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5474) == 0, "  画面の一つ目は普通の (L)（字を拾う）");
    app_press(405, 300, 0);
    app_release(405, 300, 0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5311) == 0, "  同じ所の二つ目で (LL) に（5311）");
    click(700, 500);
    ck(n > 0 && same(d), "  直に踏んだのと同じ図面");

    printf("文字 の 連 の 連結（L) は今までどおり:\n");
    d = two_texts();
    jw_cmd_point(d, app_view(), mx(405), my(300), 0);
    jw_cmd_point(d, app_view(), mx(405), my(400), 0);
    keep(d);
    d = two_texts();
    click(405, 300);
    click(405, 400);
    ck(same(d), "  離れた二つの (L) は (LL) にならない");
}

/* 線を一本、(600,350) を通るように */
static jw_drawing *one_line(void)
{
    jw_drawing *d = fresh();
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = mx(600) - 40.0;
    o->d[1] = my(350) - 25.0;
    o->d[2] = mx(600) + 40.0;
    o->d[3] = my(350) + 25.0;
    app_command(JW_CMD_KYOKUSEN);
    type_box(1411, "4");
    return d;
}

static void curve(void)
{
    jw_drawing *d;
    int before;

    printf("曲線 の 連結する線・弧指示（LL):\n");
    d = one_line();
    ck(jw_cmd_bar_radio(1691) == 1, "  スプライン（1691）で入る");
    before = d->ndrawn;
    app_move(300, 300);
    jw_cmd_point(d, app_view(), mx(300), my(300), 0);
    app_move(450, 200);
    jw_cmd_point(d, app_view(), mx(450), my(200), 0);
    app_move(600, 350);
    jw_cmd_point_ll(d, app_view(), mx(600), my(350));
    jw_cmd_bar(d, 1800);
    ck(d->ndrawn > before, "  直に踏むと曲線が出る");
    keep(d);

    d = one_line();
    click(300, 300);
    click(450, 200);
    click(600, 350);
    app_press(600, 350, 0);
    app_release(600, 350, 0);
    jw_cmd_bar(d, 1800);
    ck(same(d), "  画面の (L) 二つで同じ曲線（線に連結）");

    printf("曲線 の 普通の (L) は今までどおり:\n");
    d = one_line();
    app_move(300, 300);
    jw_cmd_point(d, app_view(), mx(300), my(300), 0);
    app_move(450, 200);
    jw_cmd_point(d, app_view(), mx(450), my(200), 0);
    app_move(600, 350);
    jw_cmd_point(d, app_view(), mx(600), my(350), 0);
    jw_cmd_bar(d, 1800);
    keep(d);
    d = one_line();
    click(300, 300);
    click(450, 200);
    click(600, 350);
    jw_cmd_bar(d, 1800);
    ck(same(d), "  一つずつの (L) は直に渡したのと同じ");
}

/* コピー・切り取りは表側に クリップボードへ を頼む（JW_ACT_CLIP_PUT） */
static void clip(void)
{
    jw_drawing *d;

    printf("コピー・切り取りのあと:\n");
    d = fresh();
    app_take_action();
    ck(app_command(57634) == 0 && app_take_action() == JW_ACT_NONE,
       "  何も選んでいなければ頼まない");
    {
        jw_obj *o = jw_add(d, JW_SEN);

        o->d[0] = mx(300);
        o->d[1] = my(300);
        o->d[2] = mx(500);
        o->d[3] = my(300);
    }
    app_command(JW_CMD_HANI);
    click(250, 250);
    click(550, 350);
    ck(app_command(57634) && app_take_action() == JW_ACT_CLIP_PUT,
       "  選んでいれば JW_ACT_CLIP_PUT");
}

int main(void)
{
    ren();
    curve();
    clip();
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails != 0;
}
