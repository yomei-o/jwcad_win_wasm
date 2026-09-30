/* Points, solids and a coloured line, for the original to print.
 *
 *   gcc -O2 -Isrc -o tmp/mkpoints.exe tools/mkpoints.c <the port's sources>
 *   ./tmp/mkpoints.exe          writes tmp/points.jww
 *   sh tools/probe35.sh         has the original print it
 *
 * What a 実点 or a 仮点 comes out as on paper is not on the screen (there
 * it is a ring of pixels or one dot), and neither is what カラー印刷 does
 * with the printing pens.  The print has to say.
 */
#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "jww.h"
int main(void){
    jw_drawing *d; unsigned char *b; long n; FILE*f; int i;
    jw_obj *o;
    app_resize(1264,741); app_new();
    d=(jw_drawing*)app_drawing();
    /* a 実点 (the trailing long is 1) and a 仮点 (0), well apart */
    for(i=0;i<2;i++){
        o=jw_add(d,JW_TEN); if(!o) return 1;
        o->color=2; o->ltype=1; o->layer=0; o->lgroup=0;
        o->d[0]=-80.0+i*40.0; o->d[1]=60.0;
#ifdef JW_SWAP_POINTS
        o->n=i;                 /* the other way round, for probe36 */
#else
        o->n=1-i;
#endif
    }
    /* one line of each pen, so カラー印刷 can be read off */
    for(i=1;i<=9;i++){
        o=jw_add(d,JW_SEN); if(!o) return 1;
        o->color=(unsigned short)i; o->ltype=1; o->layer=0; o->lgroup=0;
        o->d[0]=-80.0; o->d[1]=20.0-i*10.0;
        o->d[2]= 80.0; o->d[3]=20.0-i*10.0;
    }
    /* and a solid, to see whether a fill prints filled */
    o=jw_add(d,JW_SOLID);
    if(o){
        o->color=4; o->ltype=1; o->layer=0; o->lgroup=0;
        o->d[0]=-80; o->d[1]=-80; o->d[2]=-40; o->d[3]=-80;
        o->d[4]=-40; o->d[5]=-60; o->d[6]=-80; o->d[7]=-60;
    }
    if(!app_save(&b,&n)) return 1;
    f=fopen("tmp/points.jww","wb"); fwrite(b,1,n,f); fclose(f);
    printf("tmp/points.jww %ld bytes, %d objects\n", n, d->ndrawn);
    return 0;
}
