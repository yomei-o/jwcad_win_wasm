/* A 32-bit framebuffer and the handful of primitives the frame needs.
 *
 * Everything the port draws goes through here, so the native build and the
 * WASM build produce the same pixels by construction: the only difference
 * between them is who hands the finished buffer to the screen.
 *
 * Pixels are 0x00RRGGBB.  The top-left is (0,0).
 */
#ifndef JW_FB_H
#define JW_FB_H

typedef struct {
    int w, h;
    unsigned int *px;
} fb_t;

typedef struct {
    int x, y, w, h;
} rect_t;

int  fb_init(fb_t *fb, int w, int h);
void fb_free(fb_t *fb);

void fb_fill(fb_t *fb, int x, int y, int w, int h, unsigned int c);
void fb_hline(fb_t *fb, int x, int y, int n, unsigned int c);
void fb_vline(fb_t *fb, int x, int y, int n, unsigned int c);

/* One-pixel rectangle outline, top/left in tl and bottom/right in br --
 * the shape every 3D edge in the UI is made of. */
void fb_edge(fb_t *fb, int x, int y, int w, int h,
             unsigned int tl, unsigned int br);

/* Blit one cell of a toolbar strip.
 *
 * `cell` counts from 0 across the strip.  The four colours MFC remaps when it
 * loads a toolbar bitmap are substituted on the way out: black, dark grey,
 * light grey and white become the current button colours.  Everything else
 * (the blue of the attribute buttons, say) is passed through.
 */
struct jw_bitmap;
void fb_blit_cell(fb_t *fb, const struct jw_bitmap *bm, int cell, int cw,
                  int x, int y);
void fb_blit_cell_ex(fb_t *fb, const struct jw_bitmap *bm, int cell, int cw,
                     int x, int y, int transparent);

#endif
