/* decomp/res/blkmake.jww の定義に 字を五つ入れ、20 の参照（角 0°・30°・90°・200°・-60° ×
 * 倍率の符号 (-1,1)・(1,-1)・(-1,-1)・(1,1)）を碁盤に並べた図面。回った参照の中の字・縦書きの字を
 * 原典のブロック解除 (32909) に訊くため（tools/mkblktxt.c の続き）。
 *
 *   gcc -O2 -Isrc -o tmp/mkblktxt2.exe tools/mkblktxt2.c src/jww.c \
 *       src/image.c src/imgpic.c src/jwwrite.c src/cp932.c
 *   ./tmp/mkblktxt2.exe decomp/res/blkmake.jww tmp/blkrot_h.jww h     横書き（角 0・30・90・150・-60）
 *   （v の後ろに 幅 高さ 間隔 長さ [n] を足せる。n は 字数 1〜5）\n *   ./tmp/mkblktxt2.exe decomp/res/blkmake.jww tmp/blkrot_v.jww v     縦書き（+0x44 の 0x20、角 -90・0・90・180・-45）
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

static const double PI = 3.141592653589793;

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    int i, at = -1, ref = -1, k, vert = argc > 3 && argv[3][0] == 'v';
    static const double hdeg[5] = { 0, 30, 90, 150, -60 };
    static const double vdeg[5] = { -90, 0, 90, 180, -45 };
    static const double ang[5] = { 0, 30, 90, 200, -60 };
    static const double sgn[4][2] = { { -1, 1 }, { 1, -1 }, { -1, -1 }, { 1, 1 } };
    const double *deg = vert ? vdeg : hdeg;
    double SZ = 3.0, W = 3.0, H = 3.0, SP = 0.5, LEN = SZ * 1.0833333333333333;

    if (argc > 7) {                     /* 幅 高さ 間隔 長さ */
        W = atof(argv[4]);
        H = atof(argv[5]);
        SP = atof(argv[6]);
        LEN = atof(argv[7]);
    }
    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("%s: %s\n", argv[1], d.error);
        return 1;
    }
    for (i = 0; i < d.ndrawn; i++)
        if (d.obj[i].cls == JW_BLOCK) {
            ref = i;
            break;
        }
    for (i = d.ndrawn; i < d.nobj; i++)
        if (d.obj[i].cls == JW_LIST) {
            at = i;
            break;
        }
    if (ref < 0 || at < 0 || d.obj[at].n < 5)
        return 1;
    for (k = 0; k < 5; k++) {
        char s[16];
        jw_obj *o = &d.obj[at + 1 + k];
        double a = deg[k] * PI / 180.0, len = LEN, x0 = 0.0, y0 = 10.0 * k;

        sprintf(s, "T%d", k);
        if (argc > 8) {                 /* 字数を k+1 に（長さが字数に依るかを見る） */
            memcpy(s, "ABCDE", 6);
            s[k + 1] = 0;
        }
        memset(o, 0, sizeof *o);
        o->cls = JW_MOJI;
        o->ltype = 1;
        o->color = 2;
        o->d[0] = x0;
        o->d[1] = y0;
        o->d[2] = x0 + len * cos(a);
        o->d[3] = y0 + len * sin(a);
        o->d[4] = W;
        o->d[5] = H;
        o->d[6] = SP;
        o->d[7] = deg[k];
        o->text = jw_add_str(&d, s);
        o->face = -1;
        if (vert)
            o->flags |= 0x20;
    }
    for (k = 1; k < 20; k++) {
        jw_obj *o = jw_add(&d, JW_BLOCK);

        if (!o)
            return 1;
        *o = d.obj[ref];
        o->id = 0;
        o->sel = 0;
        o->flags = 0;
    }
    for (k = 0; k < 20; k++) {
        jw_obj *o = k ? &d.obj[d.ndrawn - 20 + k] : &d.obj[ref];
        int r = k / 4, c = k % 4;

        o->d[0] += 60.0 * c - 100.0;
        o->d[1] += 50.0 * r - 120.0;
        o->d[2] = sgn[c][0];
        o->d[3] = sgn[c][1];
        o->d[4] = ang[r] * PI / 180.0;
    }
    if (!jw_write(&d, &w, &m))
        return 1;
    f = fopen(argv[2], "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m)
        return 1;
    fclose(f);
    return 0;
}
