/* 範囲選択 (32787) の 文字位置･集計 (1071).
 *
 *   tests/mojipos_test.exe
 *
 * 逆コンパイルの読み（CZukeiSentaku の 32 番 FUN_006fbc40、クリックの
 * FUN_006feba0 → 並べ直し FUN_00477000・文字集計 FUN_00700560）、原典では
 * 押していない.  選んだ文字を指した点から 行間 ごとに上から並べ直し、
 * 集計書込 なら同じ字の数を数えた一覧を書く.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/gen/prompts.h"

static int fails;
static jw_drawing *d;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b) { return fabs(a - b) < 1e-9; }

/* 2 wide and 2 tall, no spacing: a run of 1 per half-width character */
static void text(double x, double y, const char *s)
{
    jw_obj *o = jw_add(d, JW_MOJI);
    double run = (double)strlen(s);

    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = x + run;
    o->d[3] = y;
    o->d[4] = 2.0;
    o->d[5] = 2.0;
    o->d[6] = 0.0;
    o->n = 0;
    o->text = jw_add_str(d, s);
}

static const jw_obj *at(int k) { return &d->obj[d->ndrawn - 3 + k]; }

static const char *str(const jw_obj *o) { return jw_str(d, o->text); }

/* three texts and a line, all in the box: picked with (R) so the texts
   come in too */
static void setup(const char *a, const char *b, const char *c)
{
    jw_obj *l;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    l = jw_add(d, JW_SEN);
    l->d[0] = -10.0;
    l->d[1] = -10.0;
    l->d[2] = 10.0;
    l->d[3] = -10.0;
    text(0.0, 10.0, a);
    text(5.0, 20.0, b);
    text(-5.0, 0.0, c);
    d->style[1].w = 3.0;
    d->style[1].h = 3.0;
    d->style[1].sp = 0.5;
    d->style[1].color = 4;
    app_fit();
    jw_cmd_set(JW_CMD_HANI);
    jw_cmd_point(d, app_view(), -50.0, -50.0, 0);
    jw_cmd_point(d, app_view(), 50.0, 50.0, 1);
}

int main(void)
{
    char want[256];
    const jw_obj *o;
    int before;

    printf("1071 に入る:\n");
    setup("ABC", "AB", "ABCD");
    ck(jw_cmd_sel_count(d) == 4, "  枠の (R) で 線一本と文字三つ");
    ck(jw_cmd_bar_enabled(d, 1071) == 1, "  範囲が決まると 文字位置･集計 が生きる");
    ck(jw_cmd_bar(d, 1071) == 1 && jw_cmd_mp_on(), "  押すと 文字位置 のバー");
    ck(jw_cmd_bar_check(9020) > 0, "  バーは 9020（bars9.txt）");
    ck(jw_cmd_sel_count(d) == 3 && !d->obj[0].sel, "  線は選択から外れる");
    snprintf(want, sizeof want, "%s%s", JW_STR_6238, JW_STR_6177);
    ck(jw_cmd_bar_label(1072) && !strcmp(jw_cmd_bar_label(1072), want),
       "  1072 の字は 基点(左下)");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5352), "  プロンプトは 5352");
    ck(jw_cmd_box(1418) && !strcmp(jw_cmd_box(1418), "0 , 0"), "  行間の箱は 0 , 0");
    ck(jw_cmd_bar_enabled(d, 1122) == 0 && jw_cmd_bar_enabled(d, 1115) == 0,
       "  ﾌｧｲﾙ出力・文字検索 は移植に無いので死ぬ");

    printf("行間 10・基点 左下:\n");
    jw_cmd_box_put(1418, "10 , 0");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(d->ndrawn == before, "  数は変わらない（消して置き直す）");
    ck(!strcmp(str(at(0)), "AB") && !strcmp(str(at(1)), "ABC")
       && !strcmp(str(at(2)), "ABCD"), "  上の字から順に末尾へ");
    ck(near(at(0)->d[0], 100.0) && near(at(0)->d[1], 50.0)
       && near(at(0)->d[2], 102.0) && near(at(0)->d[3], 50.0), "  一つ目は指した点から");
    ck(near(at(1)->d[0], 100.0) && near(at(1)->d[1], 40.0)
       && near(at(1)->d[2], 103.0), "  二つ目は 10 下");
    ck(near(at(2)->d[0], 100.0) && near(at(2)->d[1], 30.0)
       && near(at(2)->d[2], 104.0), "  三つ目は 20 下");
    ck(!jw_cmd_mp_on() && jw_cmd_sel_count(d) == 0, "  バーは戻り、選択は放される");
    ck(!strcmp(jw_cmd_box(1418) ? jw_cmd_box(1418) : "", "10 , 0"), "  箱は 10 , 0 のまま");
    jw_cmd_undo(d);
    ck(near(at(2)->d[0], -5.0) && near(at(2)->d[1], 0.0) && !strcmp(str(at(2)), "ABCD"),
       "  戻すと元の所");

    printf("基点 中中:\n");
    setup("ABC", "AB", "ABCD");
    jw_cmd_bar(d, 1071);
    jw_cmd_mp_base(4);
    snprintf(want, sizeof want, "%s%s", JW_STR_6238, JW_STR_6181);
    ck(!strcmp(jw_cmd_bar_label(1072), want), "  1072 の字は 基点(中中)");
    ck(!strcmp(jw_cmd_box(1418), "10 , 0"), "  箱は前の 10 , 0 で出る");
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(near(at(0)->d[0], 99.0) && near(at(0)->d[1], 49.0), "  AB は半分の長さと高さ戻る");
    ck(near(at(1)->d[0], 98.5) && near(at(1)->d[1], 39.0), "  ABC も");
    jw_cmd_mp_base(2);

    printf("行間 0: 縦はそのまま:\n");
    setup("ABC", "AB", "ABCD");
    jw_cmd_bar(d, 1071);
    jw_cmd_box_put(1418, "0 , 0");
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(near(at(0)->d[0], 100.0) && near(at(0)->d[1], 20.0)
       && near(at(1)->d[1], 10.0) && near(at(2)->d[1], 0.0), "  横だけ揃う");

    /* FUN_00477000 の 文字数 n の流し込み（0x47746a〜0x47818c）と
       FUN_0047da20 の切り方。幅は 2n（全角 2・半角 1） */
    printf("行間 10・文字数 2 で流し込む:\n");
    setup("ABC", "AB", "ABCD");
    jw_cmd_bar(d, 1071);
    jw_cmd_box_put(1418, "10 , 2");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(d->ndrawn == before, "  AB+ABC+ABCD が 4 ずつで三つ");
    ck(!strcmp(str(at(0)), "ABAB") && !strcmp(str(at(1)), "CABC")
       && !strcmp(str(at(2)), "D"), "  ABAB / CABC / D");
    ck(near(at(0)->d[1], 50.0) && near(at(1)->d[1], 40.0) && near(at(2)->d[1], 30.0)
       && near(at(0)->d[2], 104.0) && near(at(2)->d[2], 101.0), "  行間ごとに、長さは新しい字で");
    ck(!strcmp(jw_cmd_box(1418), "10 , 2"), "  箱は 10 , 2 のまま");
    jw_cmd_undo(d);
    ck(d->ndrawn == before && !strcmp(str(at(2)), "ABCD") && near(at(2)->d[0], -5.0),
       "  戻すと元の三つ");

    printf("\"^m\" で切る:\n");
    setup("X", "AB^mCD", "Y");
    jw_cmd_bar(d, 1071);
    jw_cmd_box_put(1418, "10 , 10");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    o = &d->obj[d->ndrawn - 2];
    ck(d->ndrawn == before - 1, "  三つ消して二つ");
    ck(!strcmp(str(o), "AB^m") && !strcmp(str(o + 1), "CDXY"),
       "  \"^m\" までで一つ、残りは後ろと繋がる");
    ck(near(o->d[1], 50.0) && near(o[1].d[1], 40.0), "  10 下へ");

    printf("全角と行頭禁則:\n");
    /* あいう。え（SJIS）、文字数 3 = 幅 6: 「。」は前の行に入る */
    setup("P", "\x82\xa0\x82\xa2\x82\xa4\x81\x42\x82\xa6", "Q");
    jw_cmd_bar(d, 1071);
    jw_cmd_box_put(1418, "10 , 3");
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    o = &d->obj[d->ndrawn - 2];
    ck(!strcmp(str(o), "\x82\xa0\x82\xa2\x82\xa4\x81\x42")
       && !strcmp(str(o + 1), "\x82\xa6PQ"), "  あいう。 / えPQ");
    setup("P", "A\x82\xa0\x82\xa2", "Q");
    jw_cmd_bar(d, 1071);
    jw_cmd_box_put(1418, "10 , 2");
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    o = &d->obj[d->ndrawn - 2];
    ck(!strcmp(str(o), "A\x82\xa0") && !strcmp(str(o + 1), "\x82\xa2PQ"),
       "  全角が幅をまたぐならその字の前で切る");
    jw_cmd_box_put(1418, "10 , 0");

    printf("軸角 90:\n");
    setup("ABC", "AB", "ABCD");
    jw_cmd_set_axis(90.0);
    jw_cmd_bar(d, 1071);
    jw_cmd_box_put(1418, "10 , 0");
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(!strcmp(str(at(0)), "ABCD") && !strcmp(str(at(2)), "AB"), "  枠の上（左）から");
    ck(near(at(0)->d[0], 100.0) && near(at(0)->d[1], 50.0)
       && near(at(0)->d[2], 100.0) && near(at(0)->d[3], 54.0)
       && near(at(0)->d[7], 90.0), "  一つ目は上向きに");
    ck(near(at(1)->d[0], 110.0) && near(at(1)->d[1], 50.0), "  二つ目は 10 右");
    jw_cmd_set_axis(0.0);

    printf("集計書込:\n");
    setup("A", "B", "A");
    jw_cmd_bar(d, 1071);
    jw_cmd_mp_sum_cfg_set(2, 0, 0, 0, 0, 0, "", "");
    jw_cmd_box_put(1418, "0 , 0");
    jw_cmd_mp_sum_set(1);
    ck(jw_cmd_mp_sum(), "  入る");
    ck(!strcmp(jw_cmd_box(1418), "5 , 0"), "  行間 0 なら 5 に");
    snprintf(want, sizeof want, "%s%s", JW_STR_5318, JW_STR_5472);
    ck(!strcmp(jw_cmd_prompt(), want), "  プロンプトは 5318 + 5472");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(d->ndrawn == before + 2, "  字ごとに一つ足す（元は残る）");
    o = &d->obj[d->ndrawn - 2];
    ck(!strcmp(str(o), "2   A") && !strcmp(str(o + 1), "1   B"), "  数・空白・字、字の順");
    ck(near(o->d[0], 100.0) && near(o->d[1], 50.0) && near(o[1].d[1], 45.0),
       "  行間 5 で並ぶ");
    ck(near(o->d[4], 3.0) && near(o->d[6], 0.5) && o->color == 4 && o->n == 2,
       "  書込文字種 2 の大きさと色");
    /* (3 + 0.5) / 2 * 5 - 0.25 */
    ck(near(o->d[2], 100.0 + 8.5), "  長さは新しい字で");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  戻すと消える");

    printf("集計: 数の多い順・後に書く・書かない:\n");
    setup("B", "A", "B");
    jw_cmd_bar(d, 1071);
    ck(!jw_cmd_mp_sum(), "  1071 は集計書込を切る");
    jw_cmd_mp_sum_cfg_set(2, 0, 0, 0, 0, 0, "", "");
    jw_cmd_mp_sum_set(1);
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    o = &d->obj[d->ndrawn - 2];
    ck(!strcmp(str(o), "1   A") && !strcmp(str(o + 1), "2   B"), "  ソート 切: 字の順");
    setup("B", "A", "B");
    jw_cmd_bar(d, 1071);
    jw_cmd_mp_sum_cfg_set(2, 0, 1, 0, 1, 0, "", "");
    jw_cmd_mp_sum_set(1);
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    o = &d->obj[d->ndrawn - 2];
    ck(!strcmp(str(o), "B 2") && !strcmp(str(o + 1), "A 1"), "  ソート 入・後に書く");
    setup("B", "A", "B");
    jw_cmd_bar(d, 1071);
    jw_cmd_mp_sum_cfg_set(2, 0, 1, 0, 0, 1, "", "");
    jw_cmd_mp_sum_set(1);
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    o = &d->obj[d->ndrawn - 2];
    ck(!strcmp(str(o), "B") && !strcmp(str(o + 1), "A"), "  書かない");
    jw_cmd_mp_sum_cfg_set(2, 0, 0, 0, 0, 0, "", "");

    printf("文字が無い・戻る:\n");
    app_new();
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *l = jw_add(d, JW_SEN);

        l->d[0] = -10.0;
        l->d[2] = 10.0;
    }
    app_fit();
    jw_cmd_set(JW_CMD_HANI);
    jw_cmd_point(d, app_view(), -50.0, -50.0, 0);
    jw_cmd_point(d, app_view(), 50.0, 50.0, 1);
    ck(jw_cmd_bar(d, 1071) == 1 && !jw_cmd_mp_on() && jw_cmd_notice_id() == 5522,
       "  線だけなら 5522 で入らない");
    setup("ABC", "AB", "ABCD");
    jw_cmd_bar(d, 1071);
    ck(jw_cmd_back(d) && !jw_cmd_mp_on() && jw_cmd_sel_count(d) == 0,
       "  戻る でバーも選択も戻る");
    setup("ABC", "AB", "ABCD");
    jw_cmd_bar(d, 1071);
    jw_cmd_set(JW_CMD_HANI);
    ck(!jw_cmd_mp_on(), "  命令を選び直すと消える");

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
