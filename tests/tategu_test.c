/* 建具のデータ（`JW_OPT*.DAT`）を読めるか。
 *
 *   tests/tategu_test.exe
 *
 * 書式は**原典の作者が書いたもの**がそのまま `orig/JW_OPT1.DAT` の
 * 338〜626 行に入っています（「ＪＷ＿ＣＡＤ　パラメトリック建具データ
 * 説明」）。その説明に出てくるデータ例と、同梱の四枚を読ませて突き
 * 合わせます。要約は docs/notes-formats.md。
 *
 * **これは読むところまで**です。読んだものをどう伸ばして図面に置くかは
 * まだありません（建具平面 32848 は移植に影も形もありません）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/tategu.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    if (b)
        b[*n] = 0;
    fclose(f);
    return b;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

int main(void)
{
    static jw_tategu t;
    char *b;
    long n;

    /* ------------------------------------------- 説明のデータ例 ----- */
    /* 原典の説明の「データ例１」そのもの。ブロック数 3、部材 a が
       ①と①の (-25,70)-(0,70)、部材 b が ①と② の (20,47)-(-17,47)。 */
    {
        static const char SAMPLE[] =
            "#\x8c\x9f\x8b\xef\n"       /* #建具 -- 一行目が札 */
            "#\n"
            "2\n"
            "999\n"
            "3  \x96\x4c\x91\xa2\n"     /* ブロック数と札 */
            "1 1 -25 0 0 0\n"
            "1 1 -25 70 0 70\n"
            "1 2 20 47 -17 47\n"
            "0\n"
            "3 3 -20 11 15 11 2 1 A\n"
            "999\n"
            "2 \n"
            "S 100 50\n"
            "W 1700\n"
            "2 2 0 90 10 90 10000 102 -11   \"\x88\xf8\"$<\x82l\x82r>/\n"
            "2 2 0 0 0 0 30000 1 -11\n"
            "1 1 0 0 10 0 3 2001 1A E 90 18\n"
            "995\n";

        ck(jw_tategu_parse(&t, SAMPLE, (long)sizeof SAMPLE - 1) == 2,
           "説明のデータ例が二件読める");
        ck(t.want == 2, "  頭の「建具の数」");
        ck(t.item[0].nblock == 3, "  一件目はブロック三つ");
        ck(t.item[0].n == 4, "  部材四本");
        ck(near(t.item[0].show, 1.0), "  区切り 999 なら一覧は等倍");
        ck(t.part[1].b0 == 1 && t.part[1].b1 == 1
           && near(t.part[1].x0, -25.0) && near(t.part[1].y0, 70.0)
           && near(t.part[1].x1, 0.0) && near(t.part[1].y1, 70.0),
           "  部材ａ: ブロック①①、(-25,70)-(0,70)");
        ck(t.part[2].b0 == 1 && t.part[2].b1 == 2
           && near(t.part[2].x0, 20.0) && near(t.part[2].y0, 47.0)
           && near(t.part[2].x1, -17.0),
           "  部材ｂ: ブロック①②、(20,47)-(-17,47)");
        ck(!t.part[2].hidden && t.part[3].hidden,
           "  「0」だけの行から先は仮表示に出ない");
        ck(t.part[3].color == 2 && t.part[3].ltype == 1
           && t.part[3].layer == 0xa,
           "  線色２・線種１・レイヤＡ");

        /* 二件目 */
        ck(t.item[1].has_s && near(t.item[1].base_mikomi, 100.0)
           && near(t.item[1].base_wakuhaba, 50.0),
           "  S 行で見込 100・枠幅 50");
        ck(t.item[1].has_w && near(t.item[1].uchinori, 1700.0),
           "  W 行で内法 1700");
        ck(near(t.item[1].show, 0.6), "  区切り 995 なら一覧は 0.6 倍");
        {
            const jw_tg_part *p = &t.part[t.item[1].first];

            ck(p->color == JW_TG_MOJI && p->kind == 102,
               "  文字は線色 10000、文字種類はそのまま");
            ck(!strcmp(p->text, "\x88\xf8") && p->italic,
               "    中身と斜体");
            ck(p->plain, "    レイヤ -11 で包絡の建具性質が外れる");
            p++;
            ck(p->color == JW_TG_TEN && p->kind == 1,
               "  点は線色 30000、線種が実点種類");
            p++;
            ck(p->ltype == 1 && p->width == 20,
               "  線種 2001 は線種 1・線幅 20");
            ck(p->arc && near(p->sweep, 90.0) && p->sector == 18,
               "  E のあとが角度と扇形の指定");
        }
    }

    /* ------------------------------------------- 同梱の四枚 --------- */
    {
        /* 説明が覆うのは ①建具平面 (OPT1) と ②建具断面 (OPT2) です。
           OPT3 は札のない別物、OPT4 は「建築」の記号で、件の頭が
           ブロック数 0 から始まります。そちらは読めることだけ見ます。 */
        static const struct { const char *path; int tategu; } F[] = {
            { "orig/JW_OPT1.DAT", 1 }, { "orig/JW_OPT2.DAT", 1 },
            { "orig/JW_OPT3.DAT", 0 }, { "orig/JW_OPT4.DAT", 0 }
        };
        int i;

        for (i = 0; i < 4; i++) {
            b = slurp(F[i].path, &n);
            if (!b) {
                printf("BAD  cannot read %s\n", F[i].path);
                fails++;
                continue;
            }
            {
                int k = jw_tategu_parse(&t, b, n);

                printf("     %-18s %2d items, %3d parts, title [%s]\n",
                       F[i].path, k, t.npart, t.title);
                ck(k > 0, "  読めた");
                ck(k == t.want, "  頭に書かれた件数ぶん読めた");
                if (F[i].tategu) {
                    int j, bad = 0;

                    for (j = 0; j < t.nitem; j++)
                        if (t.item[j].nblock < 2)
                            bad++;
                    ck(bad == 0, "  建具なのでどの件もブロック二つ以上");
                }
            }
            free(b);
        }
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
