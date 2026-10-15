/* 埋め込み文字（%ff・=F・&J・%SS など）の置き換え。
 *
 * 原典の文字の描き手 FUN_00481d50 は、刷っているとき（FUN_0042dc90）・
 * 印刷の命令の中（doc+0x8558）・基本設定 一般(2) 2531「プリンタ出力時の
 * 埋め込み文字を画面にも変換表示する」（DAT_00a0bc40、OK FUN_005d02e0 が
 * +0x59c から）のどれかのとき、長さ 2〜8 バイトで 1 字目が = _ $ % & の字を
 * FUN_00490050 に渡して置き換える（0x485797〜）。何をどう置くかは
 * src/umekomi.c の注。逆コンパイルの読み、原典では押していない。
 *
 * 字はみな CP932。
 */
#ifndef JW_UMEKOMI_H
#define JW_UMEKOMI_H

#include <time.h>

#include "jww.h"

/* 図面のありか（doc+0x16d8 の代わり）。dir は "" でもよい（ブラウザ）、
   name は拡張子付き（"無題" のときは "" にする）。CP932 */
void jw_umekomi_doc(const char *dir, const char *name);
/* ファイルの保存日時（「=」「_」が使う）。0 なら分からない（置き換えない） */
void jw_umekomi_saved(time_t t);
time_t jw_umekomi_saved_at(void);
/* 試験用: 今の時刻をこれに固定する（0 で本当の時刻に戻す） */
void jw_umekomi_clock(time_t t);
/* 2531 が入っているか（画面にも置き換える） */
extern int jw_umekomi_screen;

/* s を置き換えたもの（静的な置き場）か、置き換えないなら s そのもの。
   printing は刷っているとき 1（%SP・%sp の倍率の補正の枝） */
const char *jw_umekomi_text(const jw_drawing *d, const jw_obj *o,
                            const char *s, int printing);
/* src/draw.c の jw_draw_text_subst に入れる形 */
const char *jw_umekomi_print_hook(const jw_drawing *d, const jw_obj *o,
                                  const char *s);
const char *jw_umekomi_screen_hook(const jw_drawing *d, const jw_obj *o,
                                   const char *s);

#endif
