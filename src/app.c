#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "ui.h"
#include "draw.h"
#include "view.h"
#include "cmd.h"
#include "gen/layout.h"
#include "gen/cmds.h"
#include "gen/newjww.h"

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
    int id;

    if (button == 0 && (id = ui_bar_hit(x, y)) != 0
        && jw_cmd_bar(have_drawing ? &drawing : 0, id))
        return 1;
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

/* Typing changes what is on the screen, so the picture is made again here.
   A front end that forgets to would show nothing until something else --
   a mouse move, say -- happened to redraw. */
int app_key(int c)
{
    if (jw_cmd() != JW_CMD_MOJI)
        return 0;
    jw_cmd_key(c);
    app_paint();
    return 1;
}

int app_compose(int c)
{
    if (jw_cmd() != JW_CMD_MOJI)
        return 0;
    if (c < 0)
        jw_cmd_compose_clear();
    else
        jw_cmd_compose_key(c);
    app_paint();
    return 1;
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
    {   /* the range box and the selection being dragged both follow the
           mouse, so the window has to be told to paint again */
        double a, b, c, e;
        if (jw_cmd_sel_box(&a, &b, &c, &e) || jw_cmd_sel_ghost(&a, &b))
            return 1;
    }
    return jw_cmd_pending(have_drawing ? &drawing : 0, o,
                          JW_CMD_MAXFIG) > 0;
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

/* The drawing the original has open before anything is loaded.  It is not
 * built here: it is Jw_cad's own.  Started with no file and told to save at
 * once, in the reference environment (tools/refenv.sh), it writes
 * decomp/res/new.jww, and tools/mknew.py bakes that into src/gen/newjww.c.
 * Reading it back gives the sixteen layer groups, the pen table, the line
 * types, the hatch and dimension settings and the ten text styles exactly as
 * the original has them -- and the file header with them, so a drawing begun
 * from nothing can be saved and read again in Jw_cad.  Its status line reads
 * "A-2  S=1/100  [0-0]", which is what docs/ref_start.png shows.
 *
 * The file is not quite empty: it carries six hidden text records Jw_cad
 * keeps its printer and view settings in ("Printer_Orientation = 0" and so
 * on).  Those are made when a drawing is written, not held in the document
 * -- FUN_005707f0 writes them and FUN_00572880 reads them back into the
 * settings -- so the six are dropped here and the new drawing is empty, the
 * way the original's is: its layer bar shows every layer with nothing on it.
 * The port does not write them back, which loses nothing but the settings
 * the original would have put in the file. */
void app_new(void)
{
    jw_drawing d;

    if (!jw_parse(&d, jw_new_jww, jw_new_jww_len)) {
        last_error = d.error;   /* only reachable if the bake went wrong */
        jw_free(&d);
        return;
    }
    d.nobj = 0;
    d.ndrawn = 0;
    if (have_drawing)
        jw_free(&drawing);
    drawing = d;
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
            && (n = jw_cmd_pending(&drawing, o, JW_CMD_MAXFIG)) > 0) {
            jw_drawing one = drawing;
            ui_view_rect(fb.w, fb.h, &view.clip);
            one.obj = o;
            one.nobj = one.ndrawn = n;
            jw_draw(&fb, &view, &one);
        }
    }
    if (view_ready && have_drawing) {
        double a, b, e, f;
        ui_view_rect(fb.w, fb.h, &view.clip);
        if (jw_cmd_sel_box(&a, &b, &e, &f))
            jw_draw_box(&fb, &view, a, b, e, f);
        if (jw_cmd_sel_ghost(&a, &b))
            jw_draw_sel(&fb, &view, &drawing, a, b);
    }
    /* the 文字 command's box goes over the drawing */
    if (jw_cmd() == JW_CMD_MOJI)
        ui_textbox(&fb, jw_cmd_line(), jw_cmd_compose());
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
