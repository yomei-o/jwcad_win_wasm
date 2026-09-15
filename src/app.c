#include <stdlib.h>

#include "app.h"
#include "ui.h"
#include "draw.h"
#include "view.h"

static fb_t fb;
static jw_view view;
static int view_ready;
static jw_drawing drawing;
static int have_drawing;
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
    wx = (sx - view.cx) / view.scale;
    wy = (view.cy - sy) / view.scale;
    view.scale *= factor;
    view.cx = sx - wx * view.scale;
    view.cy = sy + wy * view.scale;
}

void app_pan(int dx, int dy)
{
    if (!view_ready)
        return;
    view.cx += dx;
    view.cy += dy;
}

const jw_view *app_view(void)
{
    return &view;
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
    last_error = "";
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
             view_ready ? view.scale / (96.0 / 25.4 * 2.0) : 0.0);
    if (have_drawing) {
        if (!view_ready)
            app_fit();
        ui_view_rect(fb.w, fb.h, &view.clip);
        jw_draw(&fb, &view, &drawing);
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
