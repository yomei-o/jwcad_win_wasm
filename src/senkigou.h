/* 線記号変形 (32869) の記号データ（`JW_OPT4*.DAT`）を読んで、図面に置く。
 *
 * 書き方は DAT のおわりにある「データの説明」（原典自身が書いたもの）に
 * 全部あります（DAT をそのまま読んでください）。ここはそれを読み取る側と、
 * 指示した線・位置から図形を作る側です。原典に置かせた答えは
 * tools/skprobe.sh（decomp/res/sk_*.jww）、合わせる試験は
 * tests/senkigou_test.c。
 *
 * 一件（一つの記号）は 頭の一行（指示回数 と 名前）、そのあとの行たち、
 * 区切り（990〜999）。行は 制御コード（１）（２）と 座標 などの並び。
 * **指示のしかたは頭の数ではなく、行に 10・20 が出てくるかで決まります**
 * （10 があれば線１、20 があれば線２を指示。線１だけで頭が 0 なら線を
 * 押すだけ、1 以上なら線を押してから位置）。 */
#ifndef JW_SENKIGOU_H
#define JW_SENKIGOU_H

#include "jww.h"

#define JW_SK_ITEMS 64
#define JW_SK_NAME 48
#define JW_SK_TEXT 128

enum {
    JW_SK_LINE,                 /* 線 */
    JW_SK_ARC,                  /* 円・円弧・楕円 */
    JW_SK_TEXTROW,              /* 文字 */
    JW_SK_POINT,                /* 実点・点マーカー */
    JW_SK_SOLID,                /* ソリッド（a1〜a7） */
    JW_SK_ORIGIN500,            /* 500 座標原点（一覧の絵のずらし） */
    JW_SK_DIR75,                /* 750・751 指示線と指示点の間隔が倍率 */
    JW_SK_MOUSE,                /* 760〜768 倍率位置を指示する */
    JW_SK_NEXT,                 /* 10000 次の記号（c2 が番号、10000 なら選び直し） */
    JW_SK_CMD                   /* 11400・12930 ほかのコマンド */
};

typedef struct {
    int cls;
    int c1, c2;                 /* 制御コード。特別な行は c1 が番号 */
    double x0, y0, x1, y1;      /* 線: 始点・終点 / 円: 中心 x0,y0 と 始角 x1・終角 y1 */
    double v, w;                /* 760〜768 の基準点 / 500 のずれ */
    int color, ltype, width, layer;
    int have_color, have_layer;
    double r, flat, tilt, inner;/* 円: 半径（負なら楕円）・扁平率・傾き・内円 */
    int solid;                  /* a1〜a7 の数 */
    double a[4];                /* ソリッド: A' B' の座標 */
    unsigned int rgb;
    int kind;                   /* 文字種類・実点の種類 */
    int marker, marker_c;       /* 点マーカー */
    char text[JW_SK_TEXT];      /* 文字（CP932） */
    char font[48];
    int slant;
    double fac;                 /* この行にかかる倍率（700 800 を畳んだもの） */
    int turn180;                /* 倍率がマイナス: 向きを逆に */
    int real;                   /* 800 で作った行（縮尺で割る） */
} jw_sk_row;

typedef struct {
    int pointers;               /* 指示回数 */
    char name[JW_SK_NAME];
    double show;                /* 一覧の表示倍率（99* の *） */
    int first, n;
    int need_l1, need_l2;       /* 制御コード 10 / 20 が出てくるか */
    int mouse;                  /* 760〜768 があればその番号、なければ 0 */
    double mx, my;
    int dir75;                  /* 750・751 */
} jw_sk_item;

#define JW_SK_ALLROWS 4096

typedef struct {
    char title[48];
    int nitem, nrow, want;
    jw_sk_item item[JW_SK_ITEMS];
    jw_sk_row row[JW_SK_ALLROWS];
} jw_senkigou;

/* DAT 一枚を読む。件数を返す */
int jw_sk_parse(jw_senkigou *s, const char *b, long n);
/* 埋め込んだ JW_OPT4*.DAT（全体の idx 番目）を読んで返す（一枚だけ覚える） */
const jw_senkigou *jw_sk_load(int idx);

/* ----------------------------------------- 図面に置く ---------------- */

typedef struct {
    double ox, oy;              /* 記号の原点 */
    int have1, have2;           /* 線１・線２を指したか */
    int obj1, obj2;             /* 消す線の番号（図面の中の） */
    double u1x, u1y;            /* 線１に沿って記号の +x が向く単位ベクトル */
    double u2x, u2y;            /* 線２に沿って記号の +y が向く単位ベクトル */
    double s1x, s1y, e1x, e1y;  /* 線１の始点・終点（向きをそろえたもの） */
    double s2x, s2y, e2x, e2y;
    jw_obj attr1, attr2;        /* 線１・線２の線色・線種・太さ・レイヤ */
    int have_m;                 /* 倍率位置を指したか */
    double mx, my;              /* 倍率位置 */
    double sx, sy;              /* コントロールバーの 倍率 */
    double axis;                /* 作図角度の既定（水平か軸角、ラジアン） */
    double gscale;              /* 書込グループの縮尺 */
    double dist;                /* 750・751: 指示線と指示点の間隔 */
} jw_sk_pose;

/* 置く。消す線の番号は d 側で消えるので呼び手が先に処理すること。
   作った要素の数を返す */
int jw_sk_put(jw_drawing *d, const jw_senkigou *s, int item, const jw_sk_pose *p);

#endif
