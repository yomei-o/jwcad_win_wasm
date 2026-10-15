/* Pictures for 画像編集 (33013): BMP, PNG and JPEG decoded by hand, no
 * library, and the little store the browser build keeps their bytes in.
 *
 * A picture in a .jww is not a class of its own.  It is a CDataMoji whose text
 * begins "^@BM" (FUN_00486f60 tests exactly that with Left(4)) and goes on
 *
 *     ^@BM<file>,<w>,<h>,<x>,<y>,<c>,<d>,<R>,<G>,<B>
 *
 * with w and h the size on the paper in millimetres, x y c the part of the
 * picture that shows (see jw_pic_parse), d a turn and R G B the transparent
 * colour (255,255,255 is "none" unless the 透過色設定 box was ticked).  The
 * baseline of the text is the picture's bottom edge, which is why the file
 * keeps a start point and an end that only says how long the text is.
 */
#ifndef JW_IMAGE_H
#define JW_IMAGE_H

#include "jww.h"

typedef struct {
    int w, h;
    unsigned char *rgb;         /* w*h*3, top row first */
} jw_img;

/* Decode BMP / PNG / JPEG by looking at the first bytes.  0 if it is none of
   them or is damaged; on success the caller frees img->rgb. */
int  jw_img_decode(const unsigned char *b, long n, jw_img *img);
void jw_img_free(jw_img *img);

/* The store.  `name` is whatever the text says (a path in either style of
   slash); the bytes are copied.  Lookup tries the whole name and then the
   last component, so a drawing moved to another machine still finds a
   picture that was handed over by name. */
void jw_img_put(const char *name, const unsigned char *b, long n);
const unsigned char *jw_img_bytes(const char *name, long *n);
/* a way for a front end that has files to fetch the bytes; the result is
   malloc'd and handed to the store.  Called when the name is not there. */
typedef unsigned char *(*jw_img_loader)(const char *name, long *n);
void jw_img_set_loader(jw_img_loader f);
/* decoded, cached; NULL if the picture cannot be found or read */
const jw_img *jw_img_get(const char *name);
void jw_img_forget(void);

/* gzip, for the pictures a drawing carries inside it.  jw_gzip writes a
   valid but not zlib-identical stream.  jw_img_put_gz keeps the gzip a
   drawing was read with so that saving again writes the same bytes. */
int  jw_gunzip(const unsigned char *g, long n, unsigned char **out, long *on);
int  jw_gzip(const unsigned char *p, long n, unsigned char **out, long *on);
int  jw_img_put_gz(const char *name, const unsigned char *g, long n);
int  jw_img_gz(const char *name, unsigned char **out, long *n);
/* a picture as a 24 bit BMP (caller frees) */
unsigned char *jw_img_bmp(const jw_img *im, long *n);
/* "C:\prog\a.bmp" -> "C__prog_a_bmp.bmp" */
void jw_img_embed_name(const char *path, char *out, int cap);

/* the picture elements of a drawing */
typedef struct {
    char name[260];             /* CP932 */
    double w, h;                /* the size shown, mm of paper             */
    double x, y, c;             /* what is cut: left, bottom, and width, each in
                                   whole-picture widths; 0,0,1 is all      */
    double d;                   /* the fourth number: a turn, in radians   */
    int r, g, b;                /* transparent colour                      */
    int nfield;                 /* how many numbers the text carried       */
} jw_pic;

/* 1 if `o` is a picture, filling *p; the text is the original's
   "^@BM%s,%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d". */
int  jw_pic_parse(const jw_drawing *d, const jw_obj *o, jw_pic *p);
/* the text for a picture */
void jw_pic_format(const jw_pic *p, char *out, int cap);
int  jw_is_pic(const jw_drawing *d, const jw_obj *o);

/* where the picture's lower left is, its turn in radians, the four corners
   (lower left, lower right, upper right, upper left), and whether a point of
   the sheet is on it */
double jw_pic_angle(const jw_obj *o, const jw_pic *p);
void jw_pic_corners(const jw_obj *o, const jw_pic *p, double *x, double *y);
int  jw_pic_hit(const jw_obj *o, const jw_pic *p, double px, double py);
/* rewrite an element as the picture `p` with its lower left at (ox,oy); the
   baseline of the text runs `base_deg` degrees */
void jw_pic_write(jw_drawing *d, jw_obj *o, const jw_pic *p, double ox, double oy,
                  double base_deg);
/* a new one, `w` mm wide and shaped like an image of aw x ah pixels */
jw_obj *jw_pic_new(jw_drawing *d, const char *name, int aw, int ah, double x, double y,
                   double w);
/* 画像フィット (with and without 回転する), トリミング, 解除, 透過色 */
int  jw_pic_fit_box(jw_drawing *d, jw_obj *o, double ax1, double ay1, double ax2,
                    double ay2, double bx1, double by1, double bx2, double by2);
int  jw_pic_fit_turn(jw_drawing *d, jw_obj *o, double ax1, double ay1, double ax2,
                     double ay2, double bx1, double by1, double bx2, double by2);
int  jw_pic_trim(jw_drawing *d, jw_obj *o, double ax1, double ay1, double ax2, double ay2);
int  jw_pic_untrim(jw_drawing *d, jw_obj *o);
int  jw_pic_set_transparent(jw_drawing *d, jw_obj *o, int r, int g, int b);

/* ほかの命令から（src/imgpic.c の末尾の注）。`t` が画像の字なら w・h を k 倍
   した字を out に（FUN_0048f7f0。小さすぎれば 0）。jw_pic_xform は
   jw_obj_xform(o, ..., sc, ang, ...) のあとに呼び、`was` は掛ける前の要素:
   画像の w・h・角度を直し、字の大きさを戻す。画像でなければ 0 */
int  jw_pic_text_scaled(const char *t, double k, char *out, int cap);
int  jw_pic_xform(jw_drawing *d, jw_obj *o, const jw_obj *was, double sc, double ang);

#endif
