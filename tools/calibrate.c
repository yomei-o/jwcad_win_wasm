/* Sweep the view fit against the reference screens.
 *
 *   tools/calibrate.exe tmp/refs tmp
 *
 * Loads every sample and its reference once, then scores the drawing area
 * for each (inset, dx, dy) in turn.  Text is left out of the count -- the
 * glyphs cannot match -- but the box each text sits in is, so a text put in
 * the wrong place still shows up.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/draw.h"
#include "../src/ui.h"
#include "../src/view.h"

#define NSAMP 15

static unsigned char *refpx[NSAMP];
static int refw[NSAMP], refh[NSAMP];
static unsigned char *bytes[NSAMP];
static long nbytes[NSAMP];

static int load_ppm(const char *p, unsigned char **out, int *w, int *h)
{
    FILE *f = fopen(p, "rb");
    char m[3];
    int mx;
    if (!f)
        return 0;
    if (fscanf(f, "%2s %d %d %d", m, w, h, &mx) != 4) {
        fclose(f);
        return 0;
    }
    fgetc(f);
    *out = (unsigned char *)malloc((size_t)*w * *h * 3);
    fread(*out, 1, (size_t)*w * *h * 3, f);
    fclose(f);
    return 1;
}

static int ink(int i, int x, int y)
{
    const unsigned char *q;
    if (x < 0 || y < 0 || x >= refw[i] || y >= refh[i])
        return 0;
    q = refpx[i] + ((size_t)y * refw[i] + x) * 3;
    return !(q[0] == 255 && q[1] == 255 && q[2] == 255);
}

/* one sample, with the view already set up */
static long score(int i, unsigned char *mask)
{
    const jw_drawing *d = app_drawing();
    const jw_view *v = app_view();
    const fb_t *fb = app_fb();
    rect_t r;
    long bad = 0;
    int x, y, k;

    ui_view_rect(fb->w, fb->h, &r);

    memset(mask, 0, (size_t)fb->w * fb->h);
    for (k = 0; k < d->ndrawn; k++) {
        const jw_obj *o = &d->obj[k];
        int x0, y0, x1, y1, pad, xx, yy;
        if (o->cls != JW_MOJI)
            continue;
        x0 = jw_sx(v, o->d[0] < o->d[2] ? o->d[0] : o->d[2]);
        x1 = jw_sx(v, o->d[0] > o->d[2] ? o->d[0] : o->d[2]);
        y0 = jw_sy(v, o->d[1] > o->d[3] ? o->d[1] : o->d[3]);
        y1 = jw_sy(v, o->d[1] < o->d[3] ? o->d[1] : o->d[3]);
        pad = (int)(o->d[5] * v->scale) + 4;
        for (yy = y0 - pad; yy <= y1 + pad; yy++)
            for (xx = x0 - pad; xx <= x1 + pad; xx++)
                if (xx >= 0 && yy >= 0 && xx < fb->w && yy < fb->h)
                    mask[(size_t)yy * fb->w + xx] = 1;
    }
    for (y = r.y; y < r.y + r.h; y++)
        for (x = r.x; x < r.x + r.w; x++) {
            int a, b;
            if (mask[(size_t)y * fb->w + x])
                continue;
            a = ink(i, x, y);
            b = fb->px[(size_t)y * fb->w + x] != 0xffffff;
            if (a != b)
                bad++;
        }
    return bad;
}

int main(int argc, char **argv)
{
    const char *refdir = argc > 1 ? argv[1] : "tmp/refs";
    const char *jwwdir = argc > 2 ? argv[2] : "tmp";
    unsigned char *mask;
    double inset, dx, dy;
    double best = 1e18, binset = 2, bdx = 0, bdy = 0;
    int bopen = 1;
    int i;
    char path[512];

    app_resize(1264, 741);
    mask = (unsigned char *)malloc(1264 * 741);
    for (i = 0; i < NSAMP; i++) {
        FILE *f;
        snprintf(path, sizeof path, "%s/d%02d.ppm", refdir, i + 1);
        if (!load_ppm(path, &refpx[i], &refw[i], &refh[i])) {
            fprintf(stderr, "cannot read %s\n", path);
            return 1;
        }
        snprintf(path, sizeof path, "%s/d%02d.jww", jwwdir, i + 1);
        f = fopen(path, "rb");
        if (!f) {
            fprintf(stderr, "cannot read %s\n", path);
            return 1;
        }
        fseek(f, 0, SEEK_END);
        nbytes[i] = ftell(f);
        fseek(f, 0, SEEK_SET);
        bytes[i] = (unsigned char *)malloc((size_t)nbytes[i]);
        fread(bytes[i], 1, (size_t)nbytes[i], f);
        fclose(f);
    }

    /* jw_fit_dx and jw_round_x shift the same way, so only the rounding
     * bias is swept. */
    for (jw_line_open = 0; jw_line_open <= 1; jw_line_open++)
    for (inset = 1.0; inset <= 2.55; inset += 0.5)
        for (dx = 0.1; dx <= 0.85; dx += 0.1)
            for (dy = 0.1; dy <= 0.85; dy += 0.1) {
                long tot = 0;
                jw_fit_inset = inset;
                jw_round_x = dx;
                jw_round_y = dy;
                for (i = 0; i < NSAMP; i++) {
                    if (!app_open(bytes[i], nbytes[i]))
                        continue;
                    app_paint();
                    tot += score(i, mask);
                }
                printf("inset %.1f dx %+.1f dy %+.1f : %ld\n", inset, dx, dy, tot);
                fflush(stdout);
                if ((double)tot < best) {
                    best = (double)tot;
                    binset = inset;
                    bdx = dx;
                    bdy = dy;
                    bopen = jw_line_open;
                }
            }
    printf("best: inset %.1f dx %+.1f dy %+.1f : %.0f\n", binset, bdx, bdy, best);
    return 0;
}
