/* 等角度分割 on two lines that are parallel but for a hair: the crossing is
 * 1e13 away, and the lines drawn from it used to come out with coordinates
 * of 3e15 (found by fail_test's press_everything). Whatever it draws has to
 * be a number a drawing can hold.
 */
#include <stdio.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
int main(void)
{
    jw_drawing *d;
    jw_obj *o;
    int i, bad = 0;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_SEN); o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
    o = jw_add(d, JW_SEN); o->d[0] = 0; o->d[1] = 10; o->d[2] = 100; o->d[3] = 10.0000000001;
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_BUNKATSU);
    jw_cmd_bar(d, 1690);
    jw_cmd_point(d, app_view(), 50, 0, 0);
    jw_cmd_point(d, app_view(), 50, 10, 0);
    for (i = 0; i < d->nobj; i++) {
        int m;
        for (m = 0; m < 4; m++)
            if (!(d->obj[i].d[m] > -1e12 && d->obj[i].d[m] < 1e12)) {
                printf("BAD  element %d has d[%d] = %g\n", i, m, d->obj[i].d[m]);
                bad++;
            }
    }
    printf("%d elements\n", d->nobj);
    printf(bad || !jw_numbers_sane(d) ? "failed\n" : "all passed\n");
    return bad != 0;
}
