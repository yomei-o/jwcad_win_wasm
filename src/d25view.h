/* ２．５D (32937) の 透視図 (1064)・鳥瞰図 (1065)・アイソメ (1066) と (m) (1067)。
 *
 * 逆コンパイルの読み、原典では押していない（原典の答えは無い）。
 *
 * 原典は CZukei25D（vftable 0x9778a8）と バーの C25DDialog（0x955760）:
 *   釦 1064/1065/1066 → FUN_00404f50(1/2/3) でバーを替え、0x1401 → slot 25
 *   FUN_00611340（立体を組む FUN_00617f70、視点の初めの値）。画面は
 *   view+0x859c が立つあいだ 図面の代わりに slot 5 FUN_00617640 が描く
 *   （FUN_0043ecc0 が三次元の線を二次元へ写す）。
 *   ≪ (1121) → slot 27 で平面に戻る、作図 (1122) → slot 26 FUN_006119c0 で
 *   写した線を書込みレイヤへ、左右上下前後 (1123..1128) → FUN_00404ee0、
 *   等角 (1129) FUN_00406420、初期値／０，０ (1084) FUN_00406520、
 *   (L)(R) は slot 9/11 FUN_00615650（視点を横へ）。
 *
 * 立体は 線と 線の端の「高さ , 奥行」の文字から組む（FUN_00613c10）:
 * 高さの線・奥行の線・両端の縦の線。レイヤ名・グループ名の #lv（底上げ）と
 * #lh（文字の無い線の高さ）も読む。
 */
#ifndef JW_D25VIEW_H
#define JW_D25VIEW_H

#include "jww.h"

/* いまの段: 0 平面（文字の設定）、1 透視図、2 鳥瞰図、3 アイソメ（バー +0xb8） */
int  jw_d25_mode(void);
/* 命令を離れる・新規: 平面へ（初めの値の旗 doc+0x8358.. は forget で落とす） */
void jw_d25_leave(void);
void jw_d25_forget(void);
/* (m) (1067): 高さ・移動間隔を mm で読む（バー +0xc0、字は " [mm] "） */
int  jw_d25_mm(void);

/* バーの釦。1 で受けた。*made に 作図 が図面に足した線の数 */
int  jw_d25_bar(jw_drawing *d, int id, int *made);
/* バーの替わり: 9016 = 透視図・鳥瞰図、9017 = アイソメ。持たない id は -1 */
int  jw_d25_bar_check(int id);
const char *jw_d25_label(int id);
/* 立体の画面での (L)(R)。1 で受けた */
int  jw_d25_click(const jw_drawing *d, double x, double y, int button);
/* 原典の矢印キー（← → ↑ ↓ PageUp PageDown、0x25.. の仮想キー）。1 で受けた。
   表側は app_arrow_key（src/app.c）が 立体の画面のときここへ回す */
int  jw_d25_key(const jw_drawing *d, int vk);
/* 状況の行（CP932）: 【２．５Ｄ】測定位置 と 角・高さ・距離 */
const char *jw_d25_prompt(const jw_drawing *d);

/* 画面の絵: d の頭（層・ペン）を写した out（obj は空）に、写した線と
   補助線を入れる。線の数を返す */
int  jw_d25_view(const jw_drawing *d, jw_drawing *out);

/* 押した時の Shift・Ctrl（作図の 元レイヤ・間引き）。cmd.c の jw_cmd_keymods が渡す */
void jw_d25_keymods(int shift, int ctrl);

/* 試験用: 組んだ立体の線の数と i 本目（x1 y1 z1 x2 y2 z2） */
int  jw_d25_nline(void);
int  jw_d25_line(int i, double p[6]);
/* 試験用: アイソメの円弧の楕円（CData3DEnko）の数 */
int  jw_d25_nell(void);
/* 試験用: ソリッドから作った面（CData3DSolid）の数 */
int  jw_d25_nface(void);
/* 試験用: i 番目の面の 四隅（3D、底上げ・勾配の面の gx_xf を 既に適用した後の値） */
int  jw_d25_face(int i, double p[12]);
/* 2554 の DXF出力（src/dxf.c の jw_d25_dxf_write）用: i 番目の面の
   射影前の四隅（x y z、底上げ済み・gx_pair/gx_xf を適用する前の値） */
int  jw_d25_face3(int i, double p[12]);
/* i 番目の面の ltype・color・layer・lgroup */
int  jw_d25_face_meta(int i, int *ltype, int *color, int *layer, int *lgroup);
/* 試験用: 視点などのつまみ（バー +0xe0 +0xe8 +0xf0 +0xf8 +0x100 +0x108） */
void jw_d25_knobs(double k[6]);

/* 2554（≪ 1121〜1129 のバーで「DXF出力」）: 立体の面を 3DFACE として
   DXF へ書く。jw_d25_bar が 2554 を受けた時に 呼ぶ（既に段に入っている
   ことが 前提、すなわち jw_d25_view と同じ fc[] を 読む）。下の
   src/dxf.c の jw_d25_dxf_write に 出典のコメントがある */
int  jw_d25_dxf_write(const jw_drawing *d, unsigned char **out, long *n);

#endif
