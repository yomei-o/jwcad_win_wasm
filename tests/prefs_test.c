/* 設定が起動をまたいで残ること。
 *
 *   tests/prefs_test.exe
 *
 * 表側（src/main_win32.c・index.html）は閉じるときに二つを書き、起動で読む:
 *
 *   .jwf（app_save_env / app_open_env）—— 寸法設定 の数の箱と 文字基点設定
 *       のずれも MOFST・S_STR1・S_SET1..3 の行に入るようにした（src/cmd.c
 *       env_sunpo_line、行の並びは原典の .jwf の読み手 FUN_00529070）
 *   レジストリの代わり（app_prefs_write / app_prefs_read）—— 基本設定 の
 *       箱の字と押し釦、寸法設定 の押し釦
 *
 * ここは「書いて、値を変えて、読み直すと書いたときの値に戻る」を見る。
 * 起動し直しは、読み直す前に別の値を入れて OK することで代える。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/kihon.h"

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
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

static void ctl_i(int tab, int i, int *x, int *y)
{
    rect_t r;
    const jw_kh_t *c = &jw_kihon_tabs[tab].c[i];

    ui_kihon_rect(1264, 741, &r);
    *x = r.x + JW_KH_BORDER + c->x + c->w / 2;
    *y = r.y + JW_KH_CAPTION + c->y + c->h / 2;
}

static int ctl_index(int tab, int id)
{
    int i;

    for (i = 0; i < jw_kihon_tabs[tab].n; i++)
        if (jw_kihon_tabs[tab].c[i].id == id)
            return i;
    return -1;
}

static void press_ctl(int tab, int id)
{
    int x, y;

    ctl_i(tab, ctl_index(tab, id), &x, &y);
    app_press(x, y, 0);
}

static void tab_at(int t)
{
    rect_t r;
    int x, y;

    ui_kihon_rect(1264, 741, &r);
    x = r.x + JW_KH_BORDER + JW_KH_TAB_X
        + (jw_kihon_tab_at[t] + jw_kihon_tab_at[t + 1]) / 2;
    y = r.y + JW_KH_CAPTION + JW_KH_TAB_Y + JW_KH_TAB_ROW / 2;
    app_press(x, y, 0);
}

static const char *box(int tab, int id)
{
    int i;

    for (i = 0; i < jw_kihon_tabs[tab].n; i++)
        if (jw_kihon_tabs[tab].c[i].id == id
            && (jw_kihon_tabs[tab].c[i].kind == JW_KH_EDIT
                || jw_kihon_tabs[tab].c[i].kind == JW_KH_COMBO))
            return app_kihon_text(tab, i, 0, 0);
    return 0;
}

static void type(const char *t)
{
    while (*t)
        app_key((unsigned char)*t++);
}

static int is(const char *a, const char *b)
{
    return a && !strcmp(a, b);
}

/* the line of the .jwf that starts with key */
static int env_line(const unsigned char *b, long n, const char *key, char *out,
                    size_t cap)
{
    const char *p = (const char *)b, *end = p + n;
    size_t kl = strlen(key);

    while (p < end) {
        const char *nl = memchr(p, '\n', (size_t)(end - p));
        size_t ll = nl ? (size_t)(nl - p) : (size_t)(end - p);

        if (ll > kl && !memcmp(p, key, kl) && (p[kl] == ' ' || p[kl] == '=')) {
            if (ll >= cap)
                ll = cap - 1;
            memcpy(out, p, ll);
            out[ll] = 0;
            if (ll && out[ll - 1] == '\r')
                out[ll - 1] = 0;
            return 1;
        }
        p = nl ? nl + 1 : end;
    }
    return 0;
}

static int sbox(int id, const char *want)
{
    char t[32];

    return jw_cmd_sunpo_box(id, t, (int)sizeof t) && !strcmp(t, want);
}

int main(void)
{
    unsigned char *b, *env = 0, *pf = 0, *pf2 = 0;
    long n, envn = 0, pfn = 0, pf2n = 0;
    char line[512];
    int i, chk = -1, chk_on = 0, x, y;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    /* ------------------------------------------- .jwf: 寸法設定・ずれ --- */
    ck(app_save_env("a.jwf", &env, &envn), "既定のまま .jwf を書く");
    ck(env_line(env, envn, "S_SET3", line, sizeof line)
       && !strcmp(line, "S_SET3 =     5.00   10.00    0.00    5.00    3.00    5.00 "),
       "  S_SET3 は型（env_new.jwf）のまま");
    ck(env_line(env, envn, "MOFST", line, sizeof line)
       && !strcmp(line, "MOFST =     0  -1.0   0.0   1.0  -1.0   0.0   1.0     0 "),
       "  MOFST も型のまま");
    free(env);

    jw_cmd_sunpo_box_set(1475, "0.75");     /* 寸法線と文字の間隔 */
    jw_cmd_sunpo_box_set(1477, "2.5");      /* 矢印の長さ */
    jw_cmd_sunpo_box_set(1481, "20");       /* 矢印の角度 */
    jw_cmd_sunpo_box_set(1479, "1.25");     /* 引出線の突出寸法 */
    jw_cmd_sunpo_box_set(1488, "4");        /* 文字種類 */
    jw_cmd_sunpo_box_set(1489, "3");        /* 寸法線色 */
    jw_cmd_sunpo_box_set(2083, "5");        /* 引出線色 */
    jw_cmd_sunpo_box_set(1473, "6");        /* 矢印・点色 */
    jw_cmd_sunpo_box_set(2080, "7");        /* 逆矢印の突出寸法 */
    jw_cmd_sunpo_box_set(1482, "6");
    jw_cmd_sunpo_box_set(1483, "11");
    jw_cmd_sunpo_box_set(1484, "1");
    jw_cmd_sunpo_box_set(1485, "4");
    jw_cmd_sunpo_box_set(1486, "2.123");    /* 型の桁で書けない数 */
    jw_cmd_sunpo_box_set(2082, "1.5");      /* 累進の基点円の半径 */
    jw_cmd_moji_zure(1);
    jw_cmd_moji_zure_at(1, 0, -2.5);
    jw_cmd_moji_zure_at(0, 0, 3);           /* 上 = Y3 */
    jw_cmd_moji_zure_at(0, 2, -4);          /* 下 = Y1 */
    ck(app_save_env("a.jwf", &env, &envn), "値を変えて .jwf を書く");
    ck(env_line(env, envn, "S_SET3", line, sizeof line)
       && !strcmp(line, "S_SET3 =     6.00   11.00    1.00    4.00   2.123    7.00 "),
       "  S_SET3 = 指定1・2・指示点 と 逆矢印");
    printf("     %s\n", line);
    ck(env_line(env, envn, "S_SET2", line, sizeof line)
       && !strcmp(line, "S_SET2 =     2.50   20.00       0    1.50       0         "),
       "  S_SET2 = 矢印の長さ・角度・基点円の半径");
    printf("     %s\n", line);
    ck(env_line(env, envn, "S_SET1", line, sizeof line)
       && !strncmp(line, "S_SET1 =        3       5       6       0    1.25", 49),
       "  S_SET1 = 色三つ・端部・突出");
    printf("     %s\n", line);
    ck(env_line(env, envn, "S_STR1", line, sizeof line)
       && !strncmp(line, "S_STR1 =        4       2    0.75       0       0    \"", 54),
       "  S_STR1 = 文字種・小数桁・間隔、書体はそのまま");
    printf("     %s\n", line);
    ck(env_line(env, envn, "MOFST", line, sizeof line)
       && !strcmp(line, "MOFST =     1  -2.5   0.0   1.0  -4.0   0.0   3.0     0 "),
       "  MOFST = ずれ使用・横・縦（Y1 が下）");
    printf("     %s\n", line);

    /* 起動し直しの代わり: 別の値にしてから読む */
    jw_cmd_sunpo_box_set(1475, "9");
    jw_cmd_sunpo_box_set(1477, "9");
    jw_cmd_sunpo_box_set(1488, "1");
    jw_cmd_sunpo_box_set(1489, "1");
    jw_cmd_sunpo_box_set(2080, "9");
    jw_cmd_sunpo_box_set(1486, "9");
    jw_cmd_sunpo_box_set(2082, "9");
    jw_cmd_moji_zure(0);
    jw_cmd_moji_zure_at(1, 0, 9);
    jw_cmd_moji_zure_at(0, 2, 9);
    ck(app_open_env(env, envn), "それを読み直す");
    ck(sbox(1475, "0.75") && sbox(1477, "2.5") && sbox(1481, "20")
       && sbox(1479, "1.25"), "  間隔・矢印・突出 が戻る");
    ck(sbox(1488, "4") && sbox(1489, "3") && sbox(2083, "5") && sbox(1473, "6"),
       "  文字種類・色 が戻る");
    ck(sbox(2080, "7") && sbox(1482, "6") && sbox(1483, "11") && sbox(1484, "1")
       && sbox(1485, "4") && sbox(1486, "2.123") && sbox(2082, "1.5"),
       "  逆矢印・指定1・2・指示点・基点円 が戻る");
    ck(jw_cmd_moji_zure_now() == 1, "  ずれ使用 が戻る");
    ck(jw_cmd_moji_zure_get(1, 0) == -2.5 && jw_cmd_moji_zure_get(0, 2) == -4.0
       && jw_cmd_moji_zure_get(0, 0) == 3.0, "  ずれ の数が戻る");
    ck(is(jw_cmd_moji_zure_box(2004), "-2.5") && is(jw_cmd_moji_zure_box(2007), "-4"),
       "  ずれ の箱の字も");
    {
        unsigned char *again = 0;
        long an = 0;

        ck(app_save_env("a.jwf", &again, &an) && an == envn
           && !memcmp(again, env, (size_t)an), "  書き直すと同じ .jwf");
        free(again);
    }
    free(env);
    {   /* 小数桁 と 端部 は バーの釦。.jwf から */
        const char *t = "S_STR1 =        2       3    0.50       0       0 \r\n"
                        "S_SET1 =        1       1       1       2    0.00 \r\n";

        app_open_env((const unsigned char *)t, (long)strlen(t));
        ck(jw_cmd_sunpo_decimals() == 3 && jw_cmd_sunpo_arrows() == 2,
           "  小数桁 3・端部 逆矢印 を .jwf から");
        t = "S_STR1 =        0       9    0.50 \r\nS_SET1 =        1       1       1       7 \r\n";
        app_open_env((const unsigned char *)t, (long)strlen(t));
        ck(jw_cmd_sunpo_decimals() == 3 && jw_cmd_sunpo_arrows() == 2 && sbox(1488, "1"),
           "  範囲の外は入らない（文字種 0 は 1、原典の読み手のとおり）");
    }

    /* ------------------------------- レジストリの代わり: 基本設定 --- */
    for (i = 0; i < jw_kihon_tabs[0].n; i++)
        if (jw_kihon_tabs[0].c[i].kind == JW_KH_CHECK
            && jw_kihon_tabs[0].c[i].id > 0 && jw_kihon_tabs[0].c[i].id != 2112) {
            chk = i;
            break;
        }
    ck(chk >= 0, "一般(1) に押し釦がある");
    ck(app_command(32891), "基本設定");
    press_ctl(0, 1788);
    type("300");
    ctl_i(0, chk, &x, &y);
    app_press(x, y, 0);
    tab_at(2);
    press_ctl(2, 1572);                     /* 線色 1 の 緑: 図面の持ち物 */
    type("100");
    tab_at(0);
    press_ctl(0, 1);                        /* OK */
    ck(!app_kihon_open(), "  OK");
    ck(app_prefs_write(&pf, &pfn), "残す字を書く");
    b = (unsigned char *)malloc((size_t)pfn + 1);
    memcpy(b, pf, (size_t)pfn);
    b[pfn] = 0;
    printf("%s", (char *)b);
    ck(strstr((char *)b, "T0.1788.0=300\n") != 0, "  画面横寸法 300");
    sprintf(line, "C0.%d.0=", jw_kihon_tabs[0].c[chk].id);
    {
        const char *q = strstr((char *)b, line);

        chk_on = !jw_kihon_tabs[0].c[chk].on;
        ck(q && q[strlen(line)] == (chk_on ? '1' : '0'), "  押した押し釦");
    }
    ck(!strstr((char *)b, "T2.1572."), "  図面のペンは書かない（図面が勝つ）");
    ck(!strstr((char *)b, "T0.1052."), "  既定のままの箱は書かない");
    free(b);

    /* 別の値にして OK し、残したものを読み直す */
    app_command(32891);
    press_ctl(0, 1788);
    type("500");
    ctl_i(0, chk, &x, &y);
    app_press(x, y, 0);
    press_ctl(0, 1);
    app_command(32891);
    ck(is(box(0, 1788), "500"), "別の値 500 で OK");
    press_ctl(0, 2);                        /* キャンセル */
    ck(app_prefs_read(pf, pfn) >= 2, "残した字を読む");
    app_command(32891);
    ck(is(box(0, 1788), "300"), "  画面横寸法 が 300 に戻る");
    press_ctl(0, 2);
    ck(app_prefs_write(&pf2, &pf2n) && pf2n == pfn && !memcmp(pf, pf2, (size_t)pfn),
       "  書き直すと同じ字");
    free(pf2);
    pf2 = 0;

    /* 字の逃がし: CP932 の二バイトと \ */
    {
        const char *t = "# x\r\n[KIHON]\r\nT0.1052.0=D:\\x8a\\xdb\\\\a b\r\n[SUNPODLG]\r\n";

        ck(app_prefs_read((const unsigned char *)t, (long)strlen(t)) == 1,
           "外部エディタ に二バイトと \\ の字を読む");
        app_command(32891);
        ck(is(box(0, 1052), "D:\x8a\xdb\\a b"), "  そのまま箱に出る");
        press_ctl(0, 2);
        ck(app_prefs_write(&pf2, &pf2n), "  書くと");
        b = (unsigned char *)malloc((size_t)pf2n + 1);
        memcpy(b, pf2, (size_t)pf2n);
        b[pf2n] = 0;
        ck(strstr((char *)b, "T0.1052.0=D:\\x8a\\xdb\\\\a b\n") != 0, "  同じ逃がし");
        free(b);
        free(pf2);
        pf2 = 0;
    }

    /* 寸法設定 の押し釦 */
    {
        int k, id = -1, nth = 0;
        char t[128];

        for (k = 0; k < ui_sunpodlg_n(); k++)
            if (ui_sunpodlg_id(k) > 0 && !ui_sunpodlg_on(k)) {
                id = ui_sunpodlg_id(k);
                break;
            }
        for (i = 0; i < k; i++)
            if (ui_sunpodlg_id(i) == id)
                nth++;
        sprintf(t, "[SUNPODLG]\nC%d.%d=1\n", id, nth);
        ck(id > 0 && app_prefs_read((const unsigned char *)t, (long)strlen(t)) == 1,
           "寸法設定 の押し釦を読む");
        ck(app_prefs_write(&pf2, &pf2n), "  書く");
        b = (unsigned char *)malloc((size_t)pf2n + 1);
        memcpy(b, pf2, (size_t)pf2n);
        b[pf2n] = 0;
        ck(strstr((char *)b, t + 11) != 0, "  同じ行が出る");
        free(b);
        free(pf2);
    }

    /* 壊れた字でも落ちない */
    {
        unsigned char junk[4096];
        unsigned s = 12345;
        int r;

        for (r = 0; r < 200; r++) {
            for (i = 0; i < (int)sizeof junk; i++) {
                s = s * 1103515245u + 12345u;
                junk[i] = (unsigned char)(r & 1 ? "[KIHON]T0.=\\x\n9C-1"[(s >> 16) % 18]
                                                : (s >> 16));
            }
            app_prefs_read(junk, (long)sizeof junk);
            app_open_env(junk, (long)sizeof junk);
        }
        ck(1, "でたらめな字を 200 回読んでも落ちない");
    }
    free(pf);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
