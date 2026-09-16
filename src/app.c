#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "ui.h"
#include "draw.h"
#include "view.h"
#include "cmd.h"
#include "gen/layout.h"
#include "gen/cmds.h"
#include "gen/pens.h"

static fb_t fb;
static jw_view view;
static int view_ready;
static jw_drawing drawing;
static int have_drawing;
static int have_file;      /* 上書 is grey until there is one */
static int action;         /* what the front end has been asked to do */
static const char *last_error = "";
static unsigned char *rgba;
static int rgba_n;

void app_fit(void)
{
    rect_t r;

    if (!fb.px)
        return;
    ui_view_rect(fb.w, fb.h, &r);
    jw_view_fit(&view, &r, have_drawing ? drawing.paper_hw : 297.0,
                have_drawing ? drawing.paper_hh : 210.0);
    view_ready = 1;
}

/* Zoom about a point on the screen, so what is under it stays put. */
void app_zoom(double factor, int sx, int sy)
{
    double wx, wy;

    if (!view_ready || factor <= 0.0)
        return;
    wx = view.ox + (sx - view.bx) / view.scale;
    wy = view.oy + (view.by - sy) / view.scale;
    view.scale *= factor;
    view.ox = wx - (sx - view.bx) / view.scale;
    view.oy = wy + (view.by - sy) / view.scale;
}

void app_pan(int dx, int dy)
{
    if (!view_ready)
        return;
    view.ox -= dx / view.scale;
    view.oy += dy / view.scale;
}

const jw_view *app_view(void)
{
    return &view;
}

/* Which toolbar button is under the point, or -1.  The buttons are all the
   same size and their corners are in layout.h. */
static int hit_button(int x, int y)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++) {
        const jw_btn_t *b = &jw_buttons[k];
        if (x >= b->x && x < b->x + BTN_W && y >= b->y && y < b->y + BTN_H)
            return k;
    }
    return -1;
}

static int in_view(int x, int y)
{
    rect_t r;

    if (!fb.px)
        return 0;
    ui_view_rect(fb.w, fb.h, &r);
    return x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h;
}

/* Screen pixels back to paper millimetres -- the other way round from
   FUN_004b6d60. */
static void to_paper(int x, int y, double *px, double *py)
{
    *px = view.ox + (x - view.bx) / view.scale;
    *py = view.oy + (view.by - y) / view.scale;
}

int app_press(int x, int y, int button)
{
    int k = hit_button(x, y);

    if (k >= 0) {
        int cmd = jw_btn_cmd[k];
        if (button != 0
            || ui_button_state(k, have_file, jw_cmd_can_undo()) == 1)
            return 0;           /* a disabled button does nothing */
        if (jw_btn_mode[k] || cmd == JW_CMD_ZOKUSEI) {
            /* 属性取得 is not a mode in the drawn sense -- the original has
               no ON_UPDATE_COMMAND_UI for it, so its button is never shown
               pressed -- but it does become the command: the click after it
               is what picks the element to take the pen from. */
            jw_cmd_set(cmd);
            return 1;
        }
        /* an action: it runs, and never becomes "the command" */
        if (cmd == JW_CMD_UNDO && jw_cmd_can_undo()) {
            jw_cmd_undo(have_drawing ? &drawing : 0);
            return 1;
        }
        if (cmd == 57600) {             /* 新規 (ID_FILE_NEW) */
            app_new();
            return 1;
        }
        if (cmd == 57601) {             /* 開く (ID_FILE_OPEN) */
            action = JW_ACT_OPEN;
            return 0;
        }
        if (cmd == 57603) {             /* 上書 (ID_FILE_SAVE) */
            action = JW_ACT_SAVE;
            return 0;
        }
        if (cmd == 57604) {             /* 名前を付けて保存 (ID_FILE_SAVE_AS) */
            action = JW_ACT_SAVE_AS;
            return 0;
        }
        return 0;
    }
    if (view_ready && in_view(x, y)) {
        double mx, my;
        to_paper(x, y, &mx, &my);
        jw_cmd_point(have_drawing ? &drawing : 0, &view, mx, my, button);
        return 1;
    }
    return 0;
}

int app_take_action(void)
{
    int a = action;

    action = JW_ACT_NONE;
    return a;
}

int app_save(unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_write(&drawing, out, n);
}

int app_move(int x, int y)
{
    double mx, my;
    jw_obj o[JW_CMD_MAXFIG];

    if (!view_ready || !in_view(x, y))
        return 0;
    to_paper(x, y, &mx, &my);
    jw_cmd_track(mx, my);
    return jw_cmd_pending(o, JW_CMD_MAXFIG) > 0;
}

int app_resize(int w, int h)
{
    if (w < 1)
        w = 1;
    if (h < 1)
        h = 1;
    if (fb.w == w && fb.h == h)
        return 1;
    fb_free(&fb);
    if (!fb_init(&fb, w, h))
        return 0;
    free(rgba);
    rgba_n = w * h * 4;
    rgba = (unsigned char *)malloc((size_t)rgba_n);
    if (!rgba)
        return 0;
    /* the bars keep their size, so the drawing area grows: refit */
    app_fit();
    return 1;
}

/* The drawing the original has open before anything is loaded.  Its status
 * line in docs/ref_start.png reads "A-2  S=1/100  [0-0]" and its layer bars
 * show every layer and group available with 0 written to, which is what this
 * builds.  The pens are the ones the original keeps in its own settings
 * (src/gen/pens.h) -- a drawing read from a file brings its own. */
void app_new(void)
{
    static const struct { double w, h; } SHEET[] = {
        { 1189, 841 }, { 841, 594 }, { 594, 420 }, { 420, 297 },
        { 297, 210 }, { 514, 364 }, { 364, 257 }, { 257, 182 },
        { 1682, 1189 }, { 2378, 1682 }, { 3364, 2378 }, { 4756, 3364 },
        { 10000, 7073 }, { 50000, 35366 }, { 100000, 70732 },
    };
    int g, l, i;

    if (have_drawing)
        jw_free(&drawing);
    memset(&drawing, 0, sizeof drawing);
    drawing.version = 600;
    drawing.name = -1;
    drawing.paper_size = JW_NEW_PAPER;
    drawing.paper_hw = SHEET[JW_NEW_PAPER].w / 2.0;
    drawing.paper_hh = SHEET[JW_NEW_PAPER].h / 2.0;
    for (g = 0; g < 16; g++) {
        /* 3 is "this is the one being written to", 2 is "editable" -- the
           two values every sample drawing uses for the rest. */
        drawing.group[g].state = g == 0 ? 3 : 2;
        drawing.group[g].write_layer = JW_NEW_LAYER;
        drawing.group[g].scale = JW_NEW_SCALE;
        drawing.group[g].name = -1;
        for (l = 0; l < 16; l++) {
            drawing.group[g].layer[l].state = l == JW_NEW_LAYER ? 3 : 2;
            drawing.group[g].layer_name[l] = -1;
        }
    }
    for (i = 0; i < 10; i++) {
        drawing.pen_rgb[i] = jw_default_pen_rgb[i];
        drawing.pen_width[i] = jw_default_pen_width[i];
    }
    have_drawing = 1;
    have_file = 0;
    last_error = "";
    jw_cmd_reset();
    app_fit();
}

int app_open(const unsigned char *b, long n)
{
    jw_drawing d;

    if (!jw_parse(&d, b, n)) {
        last_error = d.error;
        jw_free(&d);
        return 0;
    }
    if (have_drawing)
        jw_free(&drawing);
    drawing = d;
    have_drawing = 1;
    have_file = 1;
    last_error = "";
    jw_cmd_reset();
    app_fit();
    return 1;
}

const char *app_error(void)
{
    return last_error;
}

const jw_drawing *app_drawing(void)
{
    return have_drawing ? &drawing : 0;
}

void app_paint(void)
{
    int i, n;

    if (!fb.px)
        return;
    ui_paint(&fb, have_drawing ? &drawing : 0,
             view_ready ? view.scale * JW_SCREEN_MM_PER_PX : 0.0,
             have_file, jw_cmd_can_undo());
    if (have_drawing) {
        if (!view_ready)
            app_fit();
        ui_view_rect(fb.w, fb.h, &view.clip);
        jw_draw(&fb, &view, &drawing);
    }
    {
        /* The element the command is part way through.  The original draws
           its provisional figure through a raster op (it has a SetROP2
           wrapper at FUN_0079f1b8) which has not been traced yet, so this
           just draws the element that is about to exist. */
        jw_obj o[JW_CMD_MAXFIG];
        int n;
        if (view_ready && have_drawing
            && (n = jw_cmd_pending(o, JW_CMD_MAXFIG)) > 0) {
            jw_drawing one = drawing;
            ui_view_rect(fb.w, fb.h, &view.clip);
            one.obj = o;
            one.nobj = one.ndrawn = n;
            jw_draw(&fb, &view, &one);
        }
    }
    if (!rgba)
        return;
    n = fb.w * fb.h;
    for (i = 0; i < n; i++) {
        unsigned int c = fb.px[i];
        rgba[4 * i + 0] = (unsigned char)(c >> 16);
        rgba[4 * i + 1] = (unsigned char)(c >> 8);
        rgba[4 * i + 2] = (unsigned char)c;
        rgba[4 * i + 3] = 255;
    }
}

const fb_t *app_fb(void)
{
    return &fb;
}

unsigned char *app_rgba(void)
{
    return rgba;
}
