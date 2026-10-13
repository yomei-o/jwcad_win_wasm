/* Esc inside the 寸法 submodes 角度・円周・半径・直径・寸法値 (1068・1067・
 * 1065・1066・1069).
 *
 *   tests/sunpoesc_test.exe
 *
 * Read off the original with tools/jwdraw.ps1's raw:f,256/257,27,0 (WM_KEYDOWN/
 * UP VK_ESCAPE to the frame) -- RESUME.md 2026-10-13.  The rule, for every
 * one of the five: before the submode has drawn anything (the origin/circle
 * prompt, or any of the four-point walk's stages 0..3, or 寸法値's own first
 * point), Esc does not step back one stage -- it drops the submode **whole**
 * and lands back in the plain two-point kind at its own first stage (角度's
 * and 円周's "（左回り）" tail disappears, and so does the fact that 半径/
 * 直径 ask for a circle at all).  Only the single press right after a
 * dimension has actually been made steps back into redoing its last point,
 * keeping the submode.  半径/直径 draw whole on one click and so never have
 * a middle to back out of: before the first one Esc drops it; after the
 * first one Esc does nothing (jw_cmd_escape's own sun_step reset is already
 * a no-op for it, since sun_step stays 2 whichever way).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/bars.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void press_bar(int id)
{
    int i, k;

    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != (unsigned)jw_cmd())
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int x = c->x + c->w / 2, y = c->y + c->h / 2;
            if (c->id != id || ui_bar_hit(x, y) != id)
                continue;
            app_press(x, y, 0);
            return;
        }
    }
    ck(0, "  その釦がバーに無い");
}

static const char *prompt(void)
{
    const char *p = jw_cmd_prompt();
    return p ? p : "";
}

int main(void)
{
    char base_first[256];

    app_resize(1264, 741);
    app_new();

    /* three lines to read points off */
    ck(app_command(JW_CMD_SEN) != 0, "線 を出す");
    app_press(379, 335, 0); app_press(778, 335, 0);
    app_press(379, 435, 0); app_press(778, 435, 0);
    app_press(979, 335, 0); app_press(1079, 335, 0);
    app_key(27);                                /* out of 線 again */

    ck(app_command(JW_CMD_SUNPO) != 0, "寸法 を出す");
    strncpy(base_first, prompt(), sizeof base_first - 1);
    base_first[sizeof base_first - 1] = 0;

    /* 角度 (1068): before the origin is picked */
    press_bar(1068);
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "角度: 原点も打たないうちの Esc は平の二点寸法に戻す");

    /* 角度: origin picked, step0 (leader) unmade */
    press_bar(1068);
    app_press(600, 435, 0);                      /* 原点 */
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "角度: 原点だけ打った Esc も戻す（歩み 0）");

    /* 角度: leader placed, step1 (position) unmade */
    press_bar(1068);
    app_press(600, 435, 0);
    app_press(650, 400, 0);                      /* 引出し線の始点 */
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "角度: 引出し線まで打った Esc も戻す（歩み 1）");

    /* 角度: position placed, step2 (measured start) unmade */
    press_bar(1068);
    app_press(600, 435, 0);
    app_press(650, 400, 0);
    app_press(650, 370, 0);                      /* 寸法線の位置 */
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "角度: 寸法線の位置まで打った Esc も戻す（歩み 2）");

    /* 角度: measured start read, step3 (measured end) unmade -- the jump
       is bigger than one stage, and it still lands on the same place */
    press_bar(1068);
    app_press(600, 435, 0);
    app_press(650, 400, 0);
    app_press(650, 370, 0);
    app_press(379, 335, 1);                      /* (R) 寸法の始点: a line end */
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "角度: 寸法の始点まで読んだ Esc も戻す（歩み 3）");

    /* 角度: a complete one, then Esc steps back into redoing the last
       point -- the submode itself stays */
    press_bar(1068);
    app_press(600, 435, 0);
    app_press(650, 400, 0);
    app_press(650, 370, 0);
    app_press(379, 335, 1);
    app_press(778, 335, 1);                      /* (R) 寸法の終点 */
    ck(prompt()[0] != 0 && strcmp(prompt(), base_first) != 0,
       "角度: 描けた（「次へ」の案内）");
    app_key(27);
    ck(strcmp(prompt(), base_first) != 0,
       "角度: 描いた直後の Esc は角度のまま戻る（平の二点寸法には落ちない）");
    /* the press right after *that* one is back to square one: unmade again */
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "角度: そのまた次の Esc は（もう未完成なので）まるごと手放す");

    /* 円周 (1067): a circle is needed first */
    ck(app_command(JW_CMD_ENKO) != 0, "円 を出す（円周の的）");
    app_press(979, 480, 0); app_press(1029, 480, 0);
    app_key(27);
    ck(app_command(JW_CMD_SUNPO) != 0, "寸法 に戻る");
    press_bar(1067);
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "円周: 円も指示しないうちの Esc も平の二点寸法に戻す");

    /* 寸法値 (1069): before the first point, and after one unmade point */
    press_bar(1069);
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "寸法値: 何も打たないうちの Esc も戻す");
    press_bar(1069);
    app_press(379, 335, 1);
    app_key(27);
    ck(!strcmp(prompt(), base_first),
       "寸法値: 一点目だけの Esc も戻す");
    /* and complete one, to see the submode survive its own graceful step */
    press_bar(1069);
    app_press(379, 335, 1);
    app_press(778, 335, 1);
    ck(prompt()[0] != 0 && strcmp(prompt(), base_first) != 0,
       "寸法値: 描けた");
    app_key(27);
    ck(strcmp(prompt(), base_first) != 0,
       "寸法値: 描いた直後の Esc は寸法値のまま戻る");

    /* 半径 (1065): before any circle, and after one */
    {
        char radius_prompt[256];

        press_bar(1065);
        app_key(27);
        ck(!strcmp(prompt(), base_first),
           "半径: 円を指示しないうちの Esc は平の二点寸法に戻す");

        press_bar(1065);
        strncpy(radius_prompt, prompt(), sizeof radius_prompt - 1);
        radius_prompt[sizeof radius_prompt - 1] = 0;
        app_press(1029, 480, 0);                 /* on the circle drawn above */
        ck(!strcmp(prompt(), radius_prompt),
           "半径: 描いても同じ案内のまま（次の円を待つだけ）");
        app_key(27);
        ck(!strcmp(prompt(), radius_prompt),
           "半径: 描いたあとの Esc は何もしない（同じ案内のまま）");
    }

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
