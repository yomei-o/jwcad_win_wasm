/* ダイアログの見出しの × ——  押せること、無い窓では押せないこと。
 *
 *   tests/dlgclose_test.exe
 *
 * 移植は十二のダイアログの見出しに × を**描いていた**のに、どの
 * `ui_*_hit` もそこを拾っていませんでした。原典に訊いた答えは
 * `tools/probe116.sh`・`probe117.sh`・`probe118.sh` にあります:
 *
 * * 押せる所は WM_NCHITTEST が HTCLOSE と答える矩形で、窓座標の
 *   x = W-43..W-9・y = 8..29（縮尺・基本設定・寸法設定で同じ）
 * * **レイヤ設定 (32808) と 軸角・目盛・オフセット (32842) には ×
 *   がありません** —— HTCLOSE が出ず、PrintWindow の絵にも写って
 *   いません
 * * 押すと **キャンセル と同じ**です。縮尺の分母に 2 を打ってから ×
 *   で閉じると縮尺は変わらず、OK なら変わりました
 *
 * なので当たり判定はキャンセル釦の id である 2 を返します。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/bars.h"
#include "../src/gen/shakudo.h"

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
    ck(0, "その釦がバーに無い");
}

/* the middle of where the original answers HTCLOSE */
static void cross_at(const rect_t *r, int *x, int *y)
{
    *x = r->x + r->w - 26;
    *y = r->y + 18;
}

static void a_range(void)
{
    rect_t v;

    ui_view_rect(1264, 741, &v);
    app_press(v.x + 100, v.y + 100, 0);
    app_press(v.x + v.w - 4, v.y + v.h - 4, 1);
}

int main(void)
{
    unsigned char *b;
    long n;
    rect_t r;
    int x, y;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    /* -------------------------------------------- the ten that have one */
    app_command(32944);
    ui_shakudo_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_shakudo_open(), "縮尺・読取 が出る");
    ck(ui_shakudo_hit(1264, 741, x, y) == 2, "  × はキャンセルを返す");
    app_press(x, y, 0);
    ck(!app_shakudo_open(), "  × で閉じる");

    app_command(32891);
    ui_kihon_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_kihon_open(), "基本設定 が出る");
    app_press(x, y, 0);
    ck(!app_kihon_open(), "  × で閉じる");

    app_command(32925);
    ui_sunpodlg_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_sunpodlg_open(), "寸法設定 が出る");
    app_press(x, y, 0);
    ck(!app_sunpodlg_open(), "  × で閉じる");

    app_command(32811);
    ui_bairitsu_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_bairitsu_open(), "画面倍率 が出る");
    app_press(x, y, 0);
    ck(!app_bairitsu_open(), "  × で閉じる");

    app_command(0x8026);                /* 文字 */
    press_bar(1064);
    ui_mojikijun_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_mojikijun_open(), "文字基点設定 が出る");
    app_press(x, y, 0);
    ck(!app_mojikijun_open(), "  × で閉じる");

    press_bar(1843);
    ui_moji_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_moji_open(), "書込み文字種変更 が出る");
    app_press(x, y, 0);
    ck(!app_moji_open(), "  × で閉じる");

    app_command(JW_CMD_HANI);
    a_range();
    press_bar(1069);
    ui_zokusel_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_zokusel_open(), "属性選択 が出る");
    app_press(x, y, 0);
    ck(!app_zokusel_open(), "  × で閉じる");

    press_bar(1070);
    ui_zokuhen_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_zokuhen_open(), "属性変更 が出る");
    app_press(x, y, 0);
    ck(!app_zokuhen_open(), "  × で閉じる");

    app_command(JW_CMD_HANI);
    a_range();
    app_command(JW_CMD_BLOCK);
    ui_blkname_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_blkname_open(), "ブロック名 が出る");
    app_press(x, y, 0);
    ck(!app_blkname_open(), "  × で閉じる");

    /* ブロック編集 wants a drawing that already holds one */
    b = slurp("decomp/res/blkmake.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/blkmake.jww\n");
        return 1;
    }
    free(b);
    jw_cmd_set(JW_CMD_HANI);
    a_range();
    app_command(JW_CMD_BLOCK_EDIT);
    ui_blkedit_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_blkedit_open(), "ブロック編集 が出る");
    app_press(x, y, 0);
    ck(!app_blkedit_open(), "  × で閉じる");

    /* ------------------------------------------- the two that have none */
    app_command(32808);
    ui_layerdlg_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_layerdlg_open(), "レイヤ設定 が出る");
    ck(ui_layerdlg_hit(1264, 741, x, y) != 2,
       "  × の所は何も返さない（原典に × が無い）");
    app_press(x, y, 0);
    ck(app_layerdlg_open(), "  押しても閉じない");
    app_press(0, 0, 0);                 /* outside: still modal, so shut it */
    app_key(27);

    app_command(32842);
    ui_jikkaku_rect(1264, 741, &r);
    cross_at(&r, &x, &y);
    ck(app_jikkaku_open(), "軸角・目盛・オフセット が出る");
    ck(ui_jikkaku_hit(1264, 741, x, y) != 2,
       "  × の所は何も返さない（原典に × が無い）");
    app_press(x, y, 0);
    ck(app_jikkaku_open(), "  押しても閉じない");
    app_key(27);

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
