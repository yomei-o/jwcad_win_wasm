/* 建具のデータ（`JW_OPT*.DAT`）を読む。
 *
 * 建具平面 (32848)・建具断面 (32866)・建具立面 (32865) が使う、
 * パラメトリックな建具（図形）の定義です。**書式は原典の作者が書いた
 * ものがそのまま `orig/JW_OPT1.DAT` の 338〜626 行に入っています**
 * （「ＪＷ＿ＣＡＤ　パラメトリック建具データ説明」）。デコンパイルの
 * 読み（`FUN_005aa870` の scanf と `FUN_005aac30` の組み立て）とも
 * 食い違いません。要約は docs/notes-formats.md にあります。
 *
 * ここは**読むだけ**です。読んだものをどう伸ばして図面に置くかは
 * まだ入っていません（伸縮則は上の説明の 4・5 にあります）。
 */
#include "jww.h"

#ifndef JW_TATEGU_H
#define JW_TATEGU_H

#define JW_TG_PARTS   512       /* 一枚ぶんの部材の上限（余裕をみて） */
/* 説明には「それぞれの最大建具（図形）数は１６まで」とありますが、
   同梱の `JW_OPT1.DAT` の頭には 24 と書いてあって、実際それだけ
   入っています。16 は一覧に出る数の話でしょう。ここは余裕をみます。 */
#define JW_TG_ITEMS    64
#define JW_TG_TEXT     64
#define JW_TG_FONT     40
#define JW_TG_NAME     64

/* 線色の欄に入る目印。説明の 14・15 */
#define JW_TG_MOJI  10000
#define JW_TG_TEN   30000

typedef struct {
    int b0, b1;                 /* 始点・終点のブロック番号 */
    double x0, y0, x1, y1;      /* そのブロックの原点から、mm */
    int color;                  /* 線色 1..6、JW_TG_MOJI、JW_TG_TEN、0 で書込み */
    int ltype;                  /* 線種 1..9、0 で書込み */
    int width;                  /* 線幅 1/100mm。線種の百の位から */
    int layer;                  /* レイヤ 0..15、-1 で書込み */
    int layer_raw;              /* 原文のまま。桁で意味が変わります */
    int plain;                  /* 包絡で建具として扱わない（レイヤ 2 桁以上） */
    int loose;                  /* 建具属性も外す（レイヤ 3 桁） */
    int arc;                    /* 'E' があれば 1 */
    int dim;                    /* 行の最後が &m（長さを寸法図形にする） */
    double scale3;              /* 立面の 700 の倍率（なければ 1） */
    int circ_w;                 /* 立面の 750 1: 円の半径の比が 横の内法に対して */
    double sweep;               /* 円弧の角度（度、左回りが +） */
    int sector;                 /* 扇形の指定。一の位 0..3、十の位 1 でシザリング */
    int kind;                   /* 点なら実点種類、文字なら文字種類（原文のまま） */
    char text[JW_TG_TEXT];      /* 文字（CP932） */
    char font[JW_TG_FONT];      /* "$<…> のフォント名（CP932） */
    int italic;                 /* フォント名のあとの / */
    int bold;                   /* その次の ! */
    int hidden;                 /* ブロック 0 の行より後（仮表示に出ない） */
} jw_tg_part;

typedef struct {
    char name[JW_TG_NAME];      /* ブロック数の後ろに書かれた札（CP932） */
    int nblock;                 /* ブロック数。2 以上 */
    int has_s;                  /* S 行があったか */
    double base_mikomi;         /* 見込の基準。S 行が無ければ 70 */
    double base_wakuhaba;       /* 枠幅の基準。S 行が無ければ 25 */
    /* S 行の三つ目。1.5 より大きいと「芯ずれ＝（内出−外出）／２」の
       自動計算と、建具反転と同時の左右反転（JW_OPT1C.DAT の注）。 */
    int s_flip;
    int s_third;                /* S 行の三つ目が 0 でない（基準厚の (A)） */
    int has_w;
    double uchinori;            /* W 行の内法の初期値 */
    double show;                /* 区切りの 990..999 → 0.1..1.0 */
    double fix_mikomi;          /* 区切りの後ろに書かれた固定値。0 なら無し */
    double fix_wakuhaba;
    int first, n;               /* parts[] のどこからいくつか */
} jw_tg_item;

typedef struct {
    char title[JW_TG_NAME];     /* 一行目の # に続く札 */
    int want;                   /* その次の行の「建具（図形）の数」 */
    int kind;                   /* 1 平面・2 断面・3 立面・4 線記号（jw_tategu_load が入れる） */
    int nitem;
    jw_tg_item item[JW_TG_ITEMS];
    int npart;
    jw_tg_part part[JW_TG_PARTS];
} jw_tategu;

/* `b` は CP932 のままの中身。読めた建具の数を返します（0 なら駄目）。 */
int jw_tategu_parse(jw_tategu *t, const char *b, long n);

/* ------------------------------------------------ 置くときの形 ------ */

enum { JW_TG_LINE, JW_TG_ARC, JW_TG_POINT, JW_TG_TEXT_O };

typedef struct {
    int cls;                    /* 上の四つ */
    double x0, y0, x1, y1;      /* 線は両端、円弧は中心と始点、点は位置、
                                   文字は始点と終点（向きを決めます） */
    double sweep;               /* 円弧の角度（度、左回りが +） */
    int sector;
    int color, ltype, width, layer;
    int plain, loose;
    int dim;
    int kind;                   /* 実点種類・文字種類（原文のまま） */
    const char *text, *font;
    int italic, bold;
} jw_tg_out;

/* 文字を一つ置く。始点・終点 (wx[0],wy[0])・(wx[1],wy[1]) が向きを決める。
 * flags は要素の旗（建具は 0x2000、線記号は 0）。返すのは入れた数（0 か 1） */
int jw_tg_text(jw_drawing *d, const jw_tg_out *o, const double *wx,
               const double *wy, unsigned short flags);

/* 一件を、指定の 見込・枠幅・内法 で伸ばして並べます。
 *
 * 座標の原点は**ブロック①の原点**（左の枠幅と内法の境目）で、
 * Y は下が 0、上が 見込 です。伸縮則は原典の説明の 4・5 のとおり:
 *
 *   Y    見込の基準（S 行が無ければ 70mm）を基準に平均に伸縮
 *   X    S 行があれば枠幅の基準で平均に伸縮。無ければ 25mm を基準に、
 *        左ブロックでは x < -20、右ブロックでは x > 20 の端だけ（-20・20 ちょうどは動かない）。
 *        ただし枠幅が 20 以下なら全部が伸縮
 *        中間ブロックは動きません
 *   位置 ブロック① が 0、ブロック⑬（最後）が 内法、中間はその等分
 *
 * 返すのは並べた部材の数。`max` に入りきらなければそこまでです。
 */
int jw_tategu_place(const jw_tategu *t, int item, double mikomi,
                    double wakuhaba, double uchinori,
                    jw_tg_out *out, int max);
/* 内出・外出（壁の外へ出す額縁・水切の寸法）つき */
#define TG_IO_DEFAULT 75.0
int jw_tategu_place_io(const jw_tategu *t, int item, double mikomi,
                       double wakuhaba, double uchinori,
                       double uchide, double sotode,
                       jw_tg_out *out, int max);


/* ---------------------------------------- 埋め込んだ JW_OPT*.DAT ----- */

typedef struct {
    int kind;                   /* 1 平面・2 断面・3 立面・4 線記号 */
    const char *name;           /* 【建具平面A】 (CP932) */
    const char *title;          /* 一行目の # のあと (CP932) */
    const unsigned char *data;
    long len;
} jw_tgdat;

/* `kind` の種類のファイルが何枚あるか、その k 枚目が全体の何番か */
int jw_tgdat_count(int kind);
int jw_tgdat_index(int kind, int k);
const jw_tgdat *jw_tgdat_get(int idx);
/* 全体の idx 番目を読んで返す（一枚だけ覚えておく）。読めなければ 0 */
const jw_tategu *jw_tategu_load(int idx);

/* ----------------------------------------- 図面に置く（平面） -------- */

typedef struct {
    double mikomi, wakuhaba, uchinori, shinzure;    /* mm（実寸） */
    double uchide, sotode;      /* 内出・外出。have_io が 0 なら 75 */
    int have_io;
    /* 建具立面: 内法は幅（uchinori）と高さ（height）。基準点は 横（0 左・1 中・2 右）
       と 縦（0 下・1 中・2 上）の内法の角。ux,uy を回して 角度 にする */
    double height;
    int ref_h, ref_v;
    /* 平面・断面の 基準点変更（基準点選択の窓）: 列 0 左外・1 左内・2 中央・3 右内・
       4 右外、行 0 上・1 中・2 下。have_ref が 0 なら 左内の中（置き方のまま） */
    int have_ref, ref_col, ref_row;
    int flip_lr, flip_io;       /* 左右反転・内外反転 */
    double scale;               /* 紙 = 実寸 / scale */
    double ox, oy;              /* ブロック①の原点（紙 mm） */
    double ux, uy;              /* 内法の向き（単位ベクトル）。Y はその左 */
} jw_tg_pose;

/* 建具 `item` を置く。原典に建具平面を [5]・円弧つきの [7]・[13] などで
 * 置かせた答えに合わせてあります（tests/tategu2_test.c）:
 * 点は (ox,oy) + (x·u + (y − 見込/2 + 芯ずれ)·v)/scale、
 * 左右反転は x → 内法 − x、内外反転は y → 見込 − y（円弧の振りは符号が替わる）、
 * 円弧は 始角 0・傾き＝始点の向きで書き、扇形の指定（一の位 1 始点の線・
 * 2 終点の線・3 両方・5〜7 線だけ・8 前の二つの円弧の終点を結ぶ線）は
 * 円弧のあとに線で足す。**文字と寸法 (&m) はまだ**。
 * 返すのは入れた要素の数。 */
int jw_tategu_put(jw_drawing *d, const jw_tategu *t, int item,
                  const jw_tg_pose *p);

#endif

/* 並べたものを図面の要素にする。
 *
 * `ox`・`oy` は**ブロック①の原点**を図面のどこに置くか。向きは
 * そのままで、回転も反転もしません。
 *
 * **どこに置くのかは原典に訊けていません。**原典は「建具位置を指示して
 * ください」(string 5346) と訊いてきますが、その点が図形のどこに来るのか
 * を測るには建具を一つ置かせる必要があり、選択窓が駆動できないので
 * まだです（docs/notes-formats.md）。だからここは**置き場所を引数で
 * もらう**だけにしてあります。
 *
 * 色・線種・レイヤが 0 や -1 のものは図面の書込み属性になります。
 * 返すのは入れた要素の数。
 */
int jw_tategu_objs(jw_drawing *d, const jw_tg_out *o, int n,
                   double ox, double oy);
