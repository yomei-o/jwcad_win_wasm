/* 複線の 両側複線 (1068)・留線付両側複線 (1069) を 範囲選択のあとに押したとき。
 *
 *   tests/fksel_test.exe
 *
 * 原典で測った答え: decomp/res/fksel/<名前>.jww（作り方は tools/fksel.sh）。
 * どれも 新しい図面（1/100）に 線を引き、cmd:32787 の範囲選択で全部を囲み、cmd:32800（複線）、
 * 間隔 (1411) と 留線出 (1412) を打って 1068 か 1069 を押した結果で、先頭の nsrc 本が元の線、
 * そのあとが 原典の足した線（足した順）。ここでは 元の線をそのまま選んで同じことをして、
 * 足した線の本数・順・座標が 1e-9 で合うかを見る。cases.txt の行: 名前|釦|間隔|留線出|元の本数。
 *
 * 読み: src/cmd.c の fk_sel_both の注（FUN_0065e9e0・FUN_006568a0 を objdump で読んだ）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
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

static int run_case(const char *name, int btn, const char *gap, const char *tome, int nsrc)
{
    char path[200], msg[200];
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    int i, ok = 1, before, nexp, ng;
    static int gi[4096];

    snprintf(path, sizeof path, "decomp/res/fksel/%s.jww", name);
    b = slurp(path, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no %s\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    /* 新しい図面には 字が 6 つ入っている（jwdump が伏せるもの）。線・円だけ数える。
       先頭の nsrc 個が元、残りが原典の足したもの */
    for (ng = 0, i = 0; i < ref.ndrawn && ng < 4096; i++)
        if (ref.obj[i].cls == JW_SEN || ref.obj[i].cls == JW_ENKO)
            gi[ng++] = i;
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_TEN);
    for (i = 0; i < nsrc && i < ng; i++) {
        jw_obj *o = jw_add(d, ref.obj[gi[i]].cls);

        if (!o) {
            ok = 0;
            break;
        }
        memcpy(o->d, ref.obj[gi[i]].d, sizeof o->d);
        o->n = ref.obj[gi[i]].n;
        o->sel = 1;
    }
    jw_cmd_bar(d, 0);                   /* 図面を命令に渡す（last_dr） */
    jw_cmd_set(JW_CMD_FUKUSEN);
    before = d->ndrawn;
    type_box(1411, gap);
    if (*tome)
        type_box(1412, tome);
    jw_cmd_bar(d, btn);
    nexp = ng - nsrc;
    snprintf(msg, sizeof msg, "%s: %d 本（原典 %d 本）", name, d->ndrawn - before, nexp);
    if (d->ndrawn - before != nexp) {
        ck(0, msg);
        jw_free(&ref);
        return 0;
    }
    for (i = 0; i < nexp; i++) {
        const jw_obj *a = &d->obj[before + i], *r = &ref.obj[gi[nsrc + i]];
        int k;

        if (a->cls != r->cls) {
            ok = 0;
            printf("     %d cls %d, the original's %d\n", i, a->cls, r->cls);
            continue;
        }
        for (k = 0; k < (a->cls == JW_SEN ? 4 : 7); k++)
            if (!(fabs(a->d[k] - r->d[k]) < 1e-9)) {
                ok = 0;
                printf("     %d d[%d] ours %.9f, the original's %.9f\n", i, k, a->d[k], r->d[k]);
            }
    }
    snprintf(msg, sizeof msg, "%s: 原典の足した線と同じ（順も座標も）", name);
    ck(ok, msg);
    jw_free(&ref);
    return ok;
}

int main(void)
{
    FILE *f = fopen("decomp/res/fksel/cases.txt", "r");
    char line[300];
    int ran = 0;

    app_resize(1264, 741);
    if (!f) {
        printf("BAD  no decomp/res/fksel/cases.txt\n");
        return 1;
    }
    while (fgets(line, sizeof line, f)) {
        char *p[5];
        int k = 0;
        char *s = line;

        if (line[0] == '#' || line[0] == '\n')
            continue;
        p[k] = s;
        for (; *s && k < 4; s++)
            if (*s == '|') {
                *s = 0;
                p[++k] = s + 1;
            }
        for (s = p[k]; *s; s++)
            if (*s == '\n' || *s == '\r')
                *s = 0;
        if (k < 4)
            continue;
        run_case(p[0], atoi(p[1]), p[2], p[3], atoi(p[4]));
        ran++;
        jw_cmd_set(JW_CMD_TEN);
        type_box(1411, "");
    }
    fclose(f);
    ck(ran > 0, "cases ran");
    return fails ? 1 : 0;
}
