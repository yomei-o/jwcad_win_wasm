/* Nine lines, one of each 線種, for the original to print.
 *
 *   gcc -O2 -Isrc -o tmp/mkdash.exe tools/mkdash.c <the port's sources>
 *   ./tmp/mkdash.exe            writes tmp/dash.jww
 *   sh tools/probe34.sh         has the original print it
 *
 * What a dash is in millimetres is nowhere on the screen -- src/draw.c
 * counts a line type in pixels -- so the print has to say.  It does:
 * eight rows come back out of the nine that go in, because 補助線 is not
 * printed, and every dash is written out as its own m/l/S.
 */
#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "jww.h"
int main(void){
    jw_drawing *d; unsigned char *b; long n; FILE*f; int i;
    app_resize(1264,741); app_new();
    d=(jw_drawing*)app_drawing();
    for(i=1;i<=9;i++){
        jw_obj*o=jw_add(d,JW_SEN);
        if(!o) break;
        o->color=2; o->ltype=(unsigned char)i; o->layer=0; o->lgroup=0;
        o->d[0]=-100.0; o->d[1]=100.0-i*20.0;
        o->d[2]= 100.0; o->d[3]=100.0-i*20.0;
    }
    if(!app_save(&b,&n)) return 1;
    f=fopen("tmp/dash.jww","wb"); fwrite(b,1,n,f); fclose(f);
    printf("tmp/dash.jww %ld bytes, %d objects\n", n, d->ndrawn);
    return 0;
}
