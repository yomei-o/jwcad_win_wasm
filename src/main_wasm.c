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
#include "ui.h"

/* The page hands over the whole canvas; the client is what is left under
   the caption and the menu bar the port draws for it. */
EMSCRIPTEN_KEEPALIVE int jw_resize(int w, int h)
{
    h -= app_chrome_h();
    if (h < 1)
        h = 1;
    if (!app_resize(w, h))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE int jw_chrome_h(void)
{
    return app_chrome_h();
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

/* Which box on the command bar is taking typing, if any.  The page has to
   know: while one is, the keys are its business and not the drawing's. */
EMSCRIPTEN_KEEPALIVE int jw_box_focus(void)
{
    return jw_cmd_box_focus();
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

/* The same for what an IME is still converting: -1 clears it, otherwise one
   UTF-16 unit is added. */
EMSCRIPTEN_KEEPALIVE int jw_compose_u(int c)
{
    unsigned short u;
    char buf[4];
    long m, i;

    if (c < 0)
        return app_compose(-1);
    u = (unsigned short)c;
    m = jw_from_utf16(&u, 1, buf, sizeof buf);
    for (i = 0; i < m && i < (long)sizeof buf; i++)
        app_compose((unsigned char)buf[i]);
    return 1;
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

/* What the caption says: the page hands over the name of the file it just
   opened, in UTF-16, and the port puts " - jw_win" after it. */
EMSCRIPTEN_KEEPALIVE void jw_name(const unsigned short *s, int n)
{
    char buf[128];
    long m = jw_from_utf16(s, n, buf, sizeof buf - 1);

    if (m < 0)
        m = 0;
    buf[m] = 0;
    app_title(buf);
    app_paint();
}

EMSCRIPTEN_KEEPALIVE int jw_press(int x, int y, int button)
{
    int redraw;

    /* the canvas carries the chrome as well, so the client starts lower */
    y -= app_chrome_h();
    if (y < 0) {
        /* on the caption or the menu bar: a name there opens its popup */
        redraw = app_chrome_press(x, y + app_chrome_h());
        if (redraw)
            app_paint();
        return redraw;
    }
    redraw = app_press(x, y, button);

    switch (app_take_action()) {
    case JW_ACT_OPEN:
        return 2;
    case JW_ACT_SAVE:
    case JW_ACT_SAVE_AS:
        return 3;
    case JW_ACT_SAVE_FIG:
        return 4;               /* 図形登録: the figure wants a name */
    case JW_ACT_SAVE_COORD:
        return 5;               /* 座標ファイル: so does that one */
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

/* 「DXFファイルを開く」: a DXF goes into whatever is open, so the page
   hands the bytes over the same way it hands over a .jww. */
EMSCRIPTEN_KEEPALIVE int jw_open_dxf(unsigned char *b, int n)
{
    if (!app_open_dxf(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 図形読込 (32862): the original puts up a file window of its own, so the
   page picks the .jws and hands the bytes over.  The figure then hangs on
   the cursor and the next press puts it down. */
EMSCRIPTEN_KEEPALIVE int jw_figure(unsigned char *b, int n)
{
    if (!app_figure(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 図形登録 (32946) the other way: once the 基準点 has been clicked the
   press hands back 4, and the page calls this for the bytes to download. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_fig(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_figure_save(&saved, &saved_n))
        return 0;
    return saved;
}

/* 座標ファイル (32895): the command hands back 5 from a press, and the page
   calls this for the text to download. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_coord(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_coord_save(&saved, &saved_n))
        return 0;
    return saved;
}

/* 「SFCファイルを開く」, the same way. */
EMSCRIPTEN_KEEPALIVE int jw_open_sfc(unsigned char *b, int n)
{
    if (!app_open_sfc(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 「JWCファイルを開く」, the same way. */
EMSCRIPTEN_KEEPALIVE int jw_open_jwc(unsigned char *b, int n)
{
    if (!app_open_jwc(b, n))
        return 0;
    app_paint();
    return 1;
}

/* The same, as DXF: the page offers it as a second download. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_dxf(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_dxf(&saved, &saved_n))
        return 0;
    return saved;
}

/* The same, as SFC.  The name it is being saved under goes in the file, so
   the page passes it in. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_sfc(const char *name)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_sfc(name, &saved, &saved_n))
        return 0;
    return saved;
}

/* The same, as JWC. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_jwc(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_jwc(&saved, &saved_n))
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
    y -= app_chrome_h();
    if (y < 0) {
        if (!app_chrome_move(x, y + app_chrome_h()))
            return 0;
        app_paint();
        return 1;
    }
    if (!app_move(x, y))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE int jw_width(void)  { return app_fb()->w; }
EMSCRIPTEN_KEEPALIVE int jw_height(void)
{
    return app_fb()->h + app_chrome_h();
}
EMSCRIPTEN_KEEPALIVE unsigned char *jw_rgba(void) { return app_rgba(); }

int main(void)
{
    /* the browser has no window of its own, so the port draws one */
    app_chrome(1);
    app_new();
    jw_resize(1264, 741 + JW_CHROME_H);
    return 0;
}
