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

/* A press on one of the two grids at the bottom right.
 *
 * What each button does was read off the original: Test5 was opened, cells
 * were pressed and the file saved, and the states in it say
 *
 *   left  -- steps the cell round 編集可(2) -> 非表示(0) -> 表示のみ(1) ->
 *            編集可, and does nothing at all on the one being written to
 *            (three presses on layer 6 brought it back where it started,
 *            and one on the write layer changed nothing);
 *   right -- makes it the one written to (3), and the one that was drops
 *            to 編集可.
 *
 * The group grid behaves the same way. */
static int press_layer(int g, int n, int button)
{
    jw_group *grp;
    int i, wg = 0;

    if (!have_drawing)
        return 0;
    for (i = 0; i < 16; i++)
        if (drawing.group[i].state == 3)
            wg = i;
    grp = &drawing.group[wg];
    if (button != 0) {
        if (g == 0) {
            grp->layer[grp->write_layer & 15].state = 2;
            grp->layer[n].state = 3;
            grp->write_layer = n;
        } else {
            drawing.group[wg].state = 2;
            drawing.group[n].state = 3;
        }
        return 1;
    }
    {
        int *st = g == 0 ? &grp->layer[n].state : &drawing.group[n].state;
        if (*st == 3)
            return 0;
        *st = *st == 2 ? 0 : *st == 0 ? 1 : 2;
    }
    return 1;
}

/* 線属性 (0x8027): the dialog is up, and what it has picked so far.  The
 * original applies them when Ok is pressed and drops them on キャンセル. */
static int zoku_open, zoku_color, zoku_ltype;

int app_zoku_open(void)
{
    return zoku_open;
}

static int press_zoku(int x, int y)
{
    int id = ui_zoku_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id >= 1401 && id <= 1409)
        zoku_color = id - 1400;
    else if (id >= 2449 && id <= 2457)
        zoku_ltype = id - 2448;
    else if (id == 1) {                 /* Ok */
        if (have_drawing) {
            drawing.write_color = (unsigned short)zoku_color;
            drawing.write_ltype = (unsigned char)zoku_ltype;
        }
        zoku_open = 0;
    } else if (id == 2) {               /* キャンセル */
        zoku_open = 0;
    }
    return 1;
}

int app_press(int x, int y, int button)
{
    int k = hit_button(x, y);
    int id, g, n;

    if (zoku_open)
        return press_zoku(x, y);

    if ((g = ui_layer_hit(x, y, &n)) >= 0)
        return press_layer(g, n, button);

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
            /* 消去 with a settled range in hand empties it at once */
            if (cmd == JW_CMD_SHOUKYO && have_drawing)
                jw_cmd_sel_erase(&drawing);
            return 1;
        }
        /* an action: it runs, and never becomes "the command" */
        if (cmd == JW_CMD_UNDO && jw_cmd_can_undo()) {
            jw_cmd_undo(have_drawing ? &drawing : 0);
            return 1;
        }
        if (cmd == 0x8027) {            /* 線属性 */
            zoku_color = have_drawing && drawing.write_color
                         ? drawing.write_color : 2;
            zoku_ltype = have_drawing && drawing.write_ltype
                         ? drawing.write_ltype : 1;
            zoku_open = 1;
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
    if (zoku_open)
        ui_zoku(&fb, have_drawing ? &drawing : 0, zoku_color, zoku_ltype);
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
