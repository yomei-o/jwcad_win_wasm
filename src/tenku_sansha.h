/* tenku_sansha.h -- what the ORIGINAL 三斜 command (天空図 bar, check 1329,
 * FUN_00740440 of Jw_win.exe 10.03.6) writes into the drawing for the two
 * clicks 測定点 and 円中心.  Pure: it depends only on the jw_drawing types,
 * src/hikage.h and src/tenku.h (the option block, the same one the 天空図
 * command uses); nothing of cmd.c.
 *
 * How it was recovered (details in the comment at the top of tenku_sansha.c):
 *   - the algorithm is read from the decompile + the disassembly of
 *     FUN_00740440 and its callees;
 *   - the numbers are cross-checked against orig/天空率表.jww, which holds two
 *     三斜 diagrams (基準建物用 on layer 13 of group 0, 計画建物用 on layer 5):
 *     all 211 + 152 objects reproduce (class, coordinates to 1e-13 mm, colour,
 *     line type, flags, size class, text, font) -- tests/tenku_sansha_test.c.
 *   - cmd+0xf0 (dialog 0xfe4) is a mode switch that also picks the label and
 *     the brackets: 0 = 基準建物用 (tangent triangles, [n], 切り上げ), 1 = 計画建物用
 *     (plain chords, <n>, 切り捨て); the sample holds one diagram of each.
 *
 * THE SAMPLE IS NOT FROM THE SAME PROGRAM VERSION as the exe in orig/: the
 * decompiled exe prints 底辺/高さ with "%9.3lf" of values rounded UP to 0.001,
 * cuts the areas the same way, prints the percentage with 3 decimals and adds a
 * 切り上げ↑ line (1.5 lines under the formula, the 天空率 line another 1.5); the
 * sample prints 5 decimals, rounds to the nearest, 2 decimals, has no such line and
 * puts the 天空率 line 2.0 lines under the formula.  Everything else (geometry,
 * order, positions, colours, line types, flags, every other string) is identical.
 * `style` selects between the two; HK_SANSHA_SAMPLE reproduces the sample
 * object for object, HK_SANSHA_EXE is what the decompile says Jw_win.exe 10.03.6
 * writes (not verifiable against a file).
 */
#ifndef TENKU_SANSHA_H
#define TENKU_SANSHA_H

#include "jww.h"
#include "hikage.h"
#include "tenku.h"

#define HK_SANSHA_EXE    0   /* what the decompile of Jw_win.exe 10.03.6 writes */
#define HK_SANSHA_SAMPLE 1   /* what orig/天空率表.jww contains                 */

typedef struct {
    hk_tenku_opts t;     /* R, plane_m, equidist, mirror(+off), interval, size_class,
                            show_point (name text + point), number.  `calc` ignored.  */
    double maxdiv;       /* 最大分割角 in degrees (combo 2210); default 10 */
    int style;           /* HK_SANSHA_EXE / HK_SANSHA_SAMPLE; default EXE   */
    int simple;          /* cmd+0xf0 (dialog 0xfe4): 1 = plain chords, no tangent shift; 0 */
    int cut_down;        /* cmd+0x25f8: 0 切り上げ (round up, exe style), 1 切り捨て      */
    char label[48];      /* CP932: 建物 label in front of 三斜計算, default 《計画建物用》 */
    char br_open[8];     /* CP932: before the triangle number, default "<"                 */
    char br_close[8];    /* after it, default ">"                                          */
    char name[40];       /* the point's name text; "" = no point/name (default "No.1")     */
    int line_color;      /* DAT_00a0bec0 % 10: radial/chord/height lines, default 1        */
    int table_color;     /* DAT_00a0bec0 / 10: the table's frame lines, default 1          */
    int point_color;     /* DAT_00a0b428: circle and point, default 2                      */
    int text_color;      /* DAT_00a0b918[size_class]: all texts, default 1                 */
    double tw, th, tsp;  /* DAT_00a0b4f8/b658/b7b8[size_class]: char width, height, spacing */
    int conf;            /* 建物位置確認表 (2114): default 0 */
    int calc;            /* 三斜計算 (1329): 0 = the circle and the projected lines only (default 1) */
    int step_tenth;      /* DAT_00a0bebc < 0: |value| tenths of a degree for the 2 deg grid
                            of the projected polylines; 0 = the default 2 degrees          */
} hk_sansha_opts;

/* defaults: mode 0 (基準建物用), R = 100, maxdiv 10, name "No.1", exe style */
void hk_sansha_opts_default(hk_sansha_opts *o);
/* switch mode 0 / 1: sets simple, cut_down, label and the brackets together (as the dialog does) */
void hk_sansha_opts_set_mode(hk_sansha_opts *o, int simple);

/* Draw the diagram for the 3-D wire frame in d (height texts, same collection as
 * jw_tenku_collect plus the ground edges and verticals the original makes).
 * (px,py) = measuring point, (cx,cy) = circle centre, both drawing mm.  Appends
 * the objects to d in the order the original writes them.  If pct != NULL it
 * receives the 天空率 as the table prints it.  Returns the number of objects
 * appended; -1 failure (several scales / out of memory / too many triangles),
 * -2 no usable height data, -3 the buildings cover the whole circle. */
int jw_tenku_sansha_draw_ex(jw_drawing *d, const hk_sansha_opts *o,
                            double px, double py, double cx, double cy, double *pct);

/* same with the option block of jw_tenku_draw and the defaults for the rest */
int jw_tenku_sansha_draw(jw_drawing *d, const hk_tenku_opts *o,
                         double px, double py, double cx, double cy, double *pct);

#endif
