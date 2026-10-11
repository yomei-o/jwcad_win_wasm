/* 同梱の JW_OPT*.DAT の全部の建具を、平面・断面・立面のどれの置き方でも
   置いてみて、落ちないこと・何か置けること（線記号を除く）を見る。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tategu.h"
#include "../src/jww.h"

int main(void)
{
    int i, k, bad = 0, total = 0;
    static jw_drawing d;
    unsigned char *b;
    long n;
    FILE *f = fopen("decomp/res/new.jww", "rb");

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    for (i = 0; jw_tgdat_get(i); i++) {
        const jw_tategu *t = jw_tategu_load(i);

        if (!t)
            continue;
        for (k = 0; k < t->nitem; k++) {
            jw_tg_pose p;
            int made;

            memset(&d, 0, sizeof d);
            jw_parse(&d, b, n);
            memset(&p, 0, sizeof p);
            p.mikomi = 70; p.wakuhaba = 35; p.uchinori = 1700; p.height = 2400;
            p.scale = 100; p.ux = 1;
            made = jw_tategu_put(&d, t, k, &p);
            total++;
            if (made <= 0 && t->item[k].n > 0) {
                printf("BAD  file %d item %d: nothing placed\n", i, k + 1);
                bad++;
            }
        }
    }
    printf("%s (%d items)\n", bad ? "SOME BAD" : "all ok", total);
    return bad != 0;
}
