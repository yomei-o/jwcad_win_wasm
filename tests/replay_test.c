/* Replay a jwdraw-style step string against the port, for tools/difffuzz.py.
 *
 *   tmp/replay.exe run  "cmd:32771;300,300;700,300" out.jww
 *   tmp/replay.exe dump file.jww            (normalized object list)
 *
 * Steps (';' separated): cmd:<id>  x,y  r<x>,<y>  m<x>,<y>  pb:<id> btn:<id>
 * off:<id>  ch:<id>,<text>  chr:<id>,<text>; wait:, dlgoff, read:, stat ... are ignored.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;
    if (!f) return 0;
    fseek(f, 0, SEEK_END); *n = ftell(f); fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) { fclose(f); return 0; }
    fclose(f);
    return b;
}

static int junk(const jw_drawing *d, const jw_obj *o)
{
    const char *s;
    if (o->cls != JW_MOJI || o->text < 0) return 0;
    s = jw_str(d, o->text);
    return !strncmp(s, "Printer_", 8) || !strncmp(s, "View_D", 6) || !strncmp(s, "Draw_B", 6);
}

static int dump(const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    jw_drawing d;
    int i, k;
    if (!b) { puts("nofile"); return 1; }
    memset(&d, 0, sizeof d);
    if (!jw_parse(&d, b, n)) { puts("bad"); return 1; }
    for (i = 0; i < d.ndrawn; i++) {
        const jw_obj *o = &d.obj[i];
        if (junk(&d, o)) continue;
        printf("cls%d sub%d lt%d col%d w%d lay%d grp%d fl%x n%d d=", o->cls, o->sub, o->ltype,
               o->color, o->width, o->layer, o->lgroup, o->flags & ~2u, o->n);
        for (k = 0; k < 8; k++) printf("%.4f ", fabs(o->d[k]) < 5e-5 ? 0.0 : o->d[k]);
        if (o->text >= 0) printf("text[%s]", jw_str(&d, o->text));
        printf("\n");
    }
    return 0;
}

/* 一押し。原典は PostMessage の座標を ビューの外でもそのまま点として受ける
   （fuzz ケース 6: 円の二点目が y=700、ビューの高さ 686 の外）。本物の
   マウスでは起きないので 移植の app_press は外を捨てる。ここでは外の点だけ
   紙の座標にして jw_cmd_point に直接渡し、原典の受け方に合わせる */
static void press(const rect_t *r, int x, int y, int button)
{
    if (x >= 0 && y >= 0 && x < r->w && y < r->h) {
        app_press(r->x + x, r->y + y, button);
        return;
    }
    {
        const jw_view *v = app_view();
        double px = v->ox + (r->x + x - v->bx) / v->scale;
        double py = v->oy + (v->by - (r->y + y)) / v->scale;

        jw_cmd_point((jw_drawing *)app_drawing(), v, px, py, button);
    }
}

static int run(const char *steps, const char *out)
{
    long n;
    unsigned char *b = slurp("decomp/res/new.jww", &n), *o;
    rect_t r;
    const char *s = steps;

    if (!b) { fprintf(stderr, "no new.jww\n"); return 2; }
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    free(b);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    while (*s) {
        char tok[256];
        int tn = 0, id = 0, x, y, nn;
        while (*s && *s != ';' && tn < 255) tok[tn++] = *s++;
        tok[tn] = 0;
        while (*s == ';') s++;
        if (!strncmp(tok, "cmd:", 4)) {
            app_command(atoi(tok + 4));
        } else if (!strncmp(tok, "mm:", 3) && sscanf(tok + 3, "%d,%d", &x, &y) == 2) {
            app_move(r.x + x, r.y + y);      /* 実カーソルを動かす（状態行の末尾が読む。m は何もしない） */
        } else if (!strncmp(tok, "read:", 5)) {
            /* 状態行を stderr へ（原典の read:59393 と見比べる用。図面には触れない） */
            fprintf(stderr, "read: [%s]\n", jw_cmd_status(app_drawing()));
        } else if (!strncmp(tok, "pb:", 3) || !strncmp(tok, "btn:", 4)) {
            jw_cmd_bar((jw_drawing *)app_drawing(), atoi(strchr(tok, ':') + 1));
        } else if (!strncmp(tok, "off:", 4)) {
            id = atoi(tok + 4);
            if (jw_cmd_bar_check(id) > 0) jw_cmd_bar((jw_drawing *)app_drawing(), id);
        } else if (!strncmp(tok, "ch:", 3) || !strncmp(tok, "chr:", 4)) {
            char *p = strchr(tok, ':') + 1;
            id = atoi(p);
            p = strchr(p, ',');
            if (p) { jw_cmd_box_put(id, p + 1); jw_cmd_box_sum(id); }   /* 原典は箱を使う所で式を読む（原典で測った: s30+1・//0.5・3m） */
        } else if (!strncmp(tok, "type:", 5)) {
            /* tools/jwdraw.ps1 の type:<字>（文字の箱に打って Enter）と
               type::<字>（Enter なし） */
            const char *p = tok + 5;
            int enter = *p != ':';

            if (!enter)
                p++;
            while (*p)
                app_key((unsigned char)*p++);
            if (enter)
                app_key(13);
        } else if (tok[0] == 'm' && sscanf(tok + 1, "%d,%d%n", &x, &y, &nn) == 2) {
            (void)x; (void)y;   /* 原典の m は 実カーソルを動かすだけで ビューの WM_MOUSEMOVE は来ない（fuzz 28〜39）*/
        } else if (tok[0] == 'r' && sscanf(tok + 1, "%d,%d%n", &x, &y, &nn) == 2) {
            press(&r, x, y, 1);
        } else if (sscanf(tok, "%d,%d%n", &x, &y, &nn) == 2) {
            press(&r, x, y, 0);
        }
    }
    if (!app_save(&o, &n)) { fprintf(stderr, "save failed\n"); return 3; }
    {
        FILE *f = fopen(out, "wb");
        fwrite(o, 1, (size_t)n, f);
        fclose(f);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc >= 3 && !strcmp(argv[1], "dump")) return dump(argv[2]);
    if (argc >= 4 && !strcmp(argv[1], "run")) return run(argv[2], argv[3]);
    fprintf(stderr, "usage: replay run <steps> <out.jww> | replay dump <jww>\n");
    return 1;
}
