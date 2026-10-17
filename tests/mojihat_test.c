/* 字の長さの「^m」・特殊文字の引き算 (FUN_004935b0(1))。
 *
 *   tests/mojihat_test.exe
 *
 * 原典で測った答えと突き合わせる（tools/mprobe.sh で 文字 を 文字種 3,4,0.5 で置いたもの
 * decomp/res/moji_hat_a.jww と、6,6,1 に 属性変更 (32952) したもの moji_hat_b.jww）:
 * 「ABCDE^m」「ABCD^m」「ABCDE」「ABC^m」「ABCDEFG^3」「ABCD^3」「ABCDE^3^m」
 * 「ABCDEFGH^m」「AB^3^3」。末尾の ^m は数えず、末尾の ^数字 は 2 字ぶん引いたうえ
 * 数字だけ（長さに余裕があれば）さらに引く。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/outfont.h"

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

static void against(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing d;
    int i, k = 0, ok = 1;

    b = slurp(path, &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < d.ndrawn; i++) {
        const jw_obj *o = &d.obj[i];
        double len, want;
        const char *t;

        if (o->cls != JW_MOJI || o->text < 0 || o->d[1] == -1000.0)
            continue;
        t = jw_str(&d, o->text);
        len = hypot(o->d[2] - o->d[0], o->d[3] - o->d[1]);
        want = jw_cmd_moji_run(t, o->d[4], o->d[6]);
        if (fabs(len - want) > 1e-9) {
            printf("     %s: 原典 %.9g 移植 %.9g\n", t, len, want);
            ok = 0;
        }
        k++;
    }
    printf("%s: 字 %d 本\n", what, k);
    ck(k >= 4 && ok, "  長さが 原典と同じ");
}

int main(void)
{
    against("decomp/res/moji_hat_a.jww", "置いたとき（文字種 3,4,0.5）");
    against("decomp/res/moji_hat_b.jww", "属性変更のあと（6,6,1）");
    ck(fabs(jw_cmd_moji_run("ABCDE", 3.0, 0.5) - 8.5) < 1e-9, "素の「ABCDE」は 8.5");
    ck(fabs(jw_cmd_moji_run("ABCDE^m", 3.0, 0.5) - 8.5) < 1e-9, "末尾の ^m は数えない");
    ck(fabs(jw_cmd_moji_run("ABCDEFG^3", 3.0, 0.5) - 6.75) < 1e-9, "「ABCDEFG^3」は 4 字");
    ck(fabs(jw_cmd_moji_run("ABCD^3", 3.0, 0.5) - 6.75) < 1e-9,
       "「ABCD^3」は 4 字（長さが足りなければ 数字は引かない）");

    /* 間隔 0.01: FUN_00493410（書体の幅を GDI で測る枝、decomp/decomp/
     * all_004894cd.c:5299-5368・5374-5387、src/cmd.c jw_cmd_moji_run の
     * 注・src/outfont.c jw_outfont_text_width の注）。GDI は呼ばず、
     * fonts/jwsubgothic.ttf・jwsubmincho.ttf の実際の字形（stb_truetype の
     * advance）を使うので、ブラウザ版でも同じ数になる。期待値は
     * jw_outfont_text_width をそのまま使う probe（/tmp/probe_w.c 相当）で
     * 読んだ、fonts/ のファイルからの実測。 */
    {
        double out, got;

        ck(jw_outfont_text_width(0, "ABCDE", 3.0, &out)
           && fabs(out - 10.1206054688) < 1e-6,
           "字形の幅（既定 = IPAexGothic）: 「ABCDE」3mm 幅は 10.1206055mm");
        got = jw_cmd_moji_run_face("ABCDE", 3.0, 0.01, 0, 0);
        ck(fabs(got - out) < 1e-9,
           "間隔 0.01（横字・既定書体）は jw_outfont_text_width と同じ値");
        ck(jw_outfont_text_width("IPAexMincho", "ABCDE", 3.0, &out)
           && fabs(out - 10.9482421875) < 1e-6,
           "  IPAexMincho を指せばその字形で測る");
        got = jw_cmd_moji_run_face("ABCDE", 3.0, 0.01, "IPAexMincho", 0);
        ck(fabs(got - out) < 1e-9, "  jw_cmd_moji_run_face も同じ");

        /* 固定幅の式（間隔 0.01 でも、縦字なら FUN_00493410 を呼ばない:
           decomp/decomp/all_004894cd.c:5383-5387, +0x44 & 0x20 != 0 の枝は
           0.01 の比較より前で return する） */
        got = jw_cmd_moji_run_face("ABCDE", 3.0, 0.01, 0, 1);
        ck(fabs(got - 7.52) < 1e-9,
           "  だが縦字なら固定幅の式のまま（(3.01)*2.5 - 0.005 = 7.52）、"
           "字形の幅 10.12... とは違う値");
        ck(fabs(got - out) > 0.1,
           "  （実際に違う値であることを確かめる）");

        /* jw_cmd_moji_run（3 引数、既存の呼び手向け）は 書体 NULL・横字のまま
           同じ枝を通る */
        got = jw_cmd_moji_run("ABCDE", 3.0, 0.01);
        ck(jw_outfont_text_width(0, "ABCDE", 3.0, &out) && fabs(got - out) < 1e-9,
           "jw_cmd_moji_run も 間隔 0.01 で同じ枝を通る（書体は既定）");
    }
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
