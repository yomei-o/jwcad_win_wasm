/* The browser front end.
 *
 * The page only ever calls jw_resize and then putImageData on what
 * jw_rgba() points at: no canvas drawing, no WebGL.  Every pixel comes from
 * the same src/ui.c the native build uses.
 *
 *   sh tools/build_wasm.sh     -> jwcad.js + jwcad.wasm
 */
#include <emscripten/emscripten.h>

#include <stdlib.h>

#include "app.h"
#include "cp932.h"
#include "cmd.h"

EMSCRIPTEN_KEEPALIVE int jw_resize(int w, int h)
{
    if (!app_resize(w, h))
        return 0;
    app_paint();
    return 1;
}

/* The page hands over the bytes of a .jww it read itself: nothing is
 * uploaded anywhere, and the build carries no drawings of its own. */
EMSCRIPTEN_KEEPALIVE int jw_open(const unsigned char *b, int n)
{
    if (!app_open(b, n))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE const char *jw_error(void) { return app_error(); }

EMSCRIPTEN_KEEPALIVE int jw_nobj(void)
{
    const jw_drawing *d = app_drawing();
    return d ? d->nobj : 0;
}

EMSCRIPTEN_KEEPALIVE void jw_zoom(double factor, int sx, int sy)
{
    app_zoom(factor, sx, sy);
    app_paint();
}

EMSCRIPTEN_KEEPALIVE void jw_pan(int dx, int dy)
{
    app_pan(dx, dy);
    app_paint();
}

EMSCRIPTEN_KEEPALIVE void jw_fit(void)
{
    app_fit();
    app_paint();
}

/* A click: on a toolbar button it changes the command, in the drawing area
   it gives the command a point. */
/* Returns 1 when the page should repaint, or what the button asked the page
   to do: 2 to pick a file to open, 3 to hand one back to be saved. */
/* A character for the 文字 command, in CP932.  The page converts what the
   browser gives it (UTF-16, and a whole run at a time when an IME finishes)
   with jw_from_utf16 before calling this. */
/* Which command is in force, so the page can tell when to put its hidden
   input where the 文字 box is and keep it focused. */
EMSCRIPTEN_KEEPALIVE int jw_cmd_id(void)
{
    return jw_cmd();
}

EMSCRIPTEN_KEEPALIVE int jw_key(int c)
{
    return app_key(c);
}

/* One UTF-16 unit from the page, converted here.  This is the way the page
   sends what an IME gives it: it needs no memory of its own on the wasm
   side, so there is nothing to get wrong about heap views or malloc. */
EMSCRIPTEN_KEEPALIVE int jw_key_u(int c)
{
    unsigned short u = (unsigned short)c;
    char buf[4];
    long m = jw_from_utf16(&u, 1, buf, sizeof buf), i;

    for (i = 0; i < m && i < (long)sizeof buf; i++)
        app_key((unsigned char)buf[i]);
    return m > 0;
}

/* UTF-16 straight from the page, converted here. */
EMSCRIPTEN_KEEPALIVE int jw_text_in(const unsigned short *s, int n)
{
    char buf[512];
    long m = jw_from_utf16(s, n, buf, sizeof buf), i;

    for (i = 0; i < m && i < (long)sizeof buf; i++)
        app_key((unsigned char)buf[i]);
    return m > 0;
}

EMSCRIPTEN_KEEPALIVE int jw_press(int x, int y, int button)
{
    int redraw = app_press(x, y, button);

    switch (app_take_action()) {
    case JW_ACT_OPEN:
        return 2;
    case JW_ACT_SAVE:
    case JW_ACT_SAVE_AS:
        return 3;
    }
    if (redraw)
        app_paint();
    return redraw;
}

/* The drawing as a .jww, for the page to hand to the browser as a download.
   jw_saved_len() is how long it is; the page copies it out and then calls
   jw_saved_free(). */
static unsigned char *saved;
static long saved_n;

EMSCRIPTEN_KEEPALIVE unsigned char *jw_save(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save(&saved, &saved_n))
        return 0;
    return saved;
}

EMSCRIPTEN_KEEPALIVE int jw_saved_len(void) { return (int)saved_n; }

EMSCRIPTEN_KEEPALIVE void jw_saved_free(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
}

EMSCRIPTEN_KEEPALIVE int jw_move(int x, int y)
{
    if (!app_move(x, y))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE int jw_width(void)  { return app_fb()->w; }
EMSCRIPTEN_KEEPALIVE int jw_height(void) { return app_fb()->h; }
EMSCRIPTEN_KEEPALIVE unsigned char *jw_rgba(void) { return app_rgba(); }

int main(void)
{
    app_new();
    jw_resize(1264, 741);
    return 0;
}
