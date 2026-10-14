/* A long session: open, draw, edit, undo, save in every format, paint, over and
   over.  The memory the process holds must level off -- a leak shows as a line
   that keeps climbing.  Windows only (it reads the working set).
     tests/leak_test.exe [rounds [v]]                                           */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

static double mb(void)
{
    PROCESS_MEMORY_COUNTERS pm;

    GetProcessMemoryInfo(GetCurrentProcess(), &pm, sizeof pm);
    return pm.WorkingSetSize / 1048576.0;
}

static void round_of(const unsigned char *b, long n, int k)
{
    const fb_t *fb = app_fb();
    rect_t r;
    unsigned char *o = 0;
    long on = 0;
    int i;

    app_open(b, n);
    app_paint();
    ui_view_rect(fb->w, fb->h, &r);
    app_command(JW_CMD_SEN);
    for (i = 0; i < 20; i++) {
        app_press(r.x + 60 + (i * 37 + k) % (r.w - 120), r.y + 60 + (i * 53) % (r.h - 120), 0);
        app_press(r.x + 90 + (i * 41) % (r.w - 120), r.y + 80 + (i * 29 + k) % (r.h - 120), 0);
    }
    app_command(JW_CMD_KUKEI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + 300, r.y + 250, 0);
    app_command(32806);                         /* 文字 */
    app_command(32787);                         /* 範囲選択 */
    app_press(r.x + 20, r.y + 20, 0);
    app_press(r.x + r.w - 5, r.y + r.h - 5, 1);
    app_key(13);
    app_command(57634);                         /* コピー */
    app_command(57637);                         /* 貼り付け */
    app_press(r.x + 200, r.y + 200, 0);
    app_command(32794);                         /* 消去 */
    for (i = 0; i < 30; i++)
        jw_cmd_undo(app_drawing());
    for (i = 0; i < 10; i++)
        jw_cmd_redo(app_drawing());
    app_zoom(2.0, r.x + 300, r.y + 300);
    app_paint();
    app_zoom(0.5, r.x + 300, r.y + 300);
    app_paint();
    if (app_save(&o, &on))
        free(o);
    o = 0;
    if (app_save_dxf(&o, &on))
        free(o);
    o = 0;
    if (app_save_sfc("t.sfc", &o, &on))
        free(o);
    o = 0;
    if (app_save_jwc(&o, &on))
        free(o);
    o = 0;
    if (app_coord_save(&o, &on))
        free(o);
    app_new();
}

int main(int argc, char **argv)
{
    int rounds = argc > 1 ? atoi(argv[1]) : 60, k, bad = 0;
    long n;
    unsigned char *b = slurp("orig/Test1.jww", &n);
    double m0 = 0, mid = 0, end;

    app_resize(1264, 741);
    for (k = 0; k < rounds; k++) {
        round_of(b, n, k);
        if (k == 9)
            m0 = mb();                          /* warmed up */
        if (k == rounds / 2)
            mid = mb();
        if (argc > 2 || k % 20 == 19)
            printf("     round %3d: %.1f MB\n", k + 1, mb());
    }
    end = mb();
    printf("     warm %.1f MB, half way %.1f MB, end %.1f MB\n", m0, mid, end);
    if (end - m0 > 40.0 + 0.2 * (rounds - 10)) {
        printf("BAD  the working set climbs: %.1f MB over %d rounds\n", end - m0, rounds - 10);
        bad = 1;
    }
    printf("%s\n", bad ? "FAILED" : "all ok");
    free(b);
    return bad;
}
