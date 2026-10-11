/* AUTOモード: 何もないところで二点 → 線が一本（原典 tools/probe196 と同じ）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

int main(void)
{
    FILE *f = fopen("decomp/res/new.jww", "rb");
    unsigned char *b;
    long n;
    rect_t r;
    const jw_drawing *d;
    int before, fails = 0;

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    d = app_drawing();
    before = d->ndrawn;
    app_command(32915);
    app_press(r.x + 400, r.y + 400, 0);
    app_press(r.x + 600, r.y + 400, 0);
    if (jw_cmd() != JW_CMD_AUTO || d->ndrawn != before + 1 ||
        d->obj[d->ndrawn - 1].cls != JW_SEN) {
        printf("BAD  線が一本できません (cmd %x, %d -> %d)\n", jw_cmd(),
               before, d->ndrawn);
        fails++;
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
