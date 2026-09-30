/* A base line with five verticals crossing it, for 寸法の一括処理.
 *
 *   gcc -O2 -Isrc -o tmp/mkikkatsu.exe tools/mkikkatsu.c <the port's srcs>
 *   ./tmp/mkikkatsu.exe         writes tmp/ikkatsu.jww
 *   sh tools/probe39.sh         has the original dimension them all
 *
 * 一括処理 asks for a 始線 and a 終線 (tools/probe38.sh read the status
 * line), so it wants a row of lines to work along -- which is what a wall
 * with openings in it looks like.
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
    /* the wall: one long horizontal */
    o=jw_add(d,JW_SEN); if(!o) return 1;
    o->color=2; o->ltype=1; o->d[0]=-100; o->d[1]=0; o->d[2]=100; o->d[3]=0;
    /* five verticals across it, unevenly spaced */
    {
        static const double X[5] = { -100.0, -55.0, -20.0, 40.0, 100.0 };
        for(i=0;i<5;i++){
            o=jw_add(d,JW_SEN); if(!o) return 1;
            o->color=2; o->ltype=1;
            o->d[0]=X[i]; o->d[1]=-20.0; o->d[2]=X[i]; o->d[3]=20.0;
        }
    }
#ifdef JW_IKKATSU_MORE
    /* a diagonal that crosses the wall between two of them, and a short
       vertical that does not reach it, to see which ones 一括処理 takes */
    o=jw_add(d,JW_SEN);
    if(o){ o->color=2; o->ltype=1;
           o->d[0]=0.0; o->d[1]=-20.0; o->d[2]=20.0; o->d[3]=20.0; }
    o=jw_add(d,JW_SEN);
    if(o){ o->color=2; o->ltype=1;
           o->d[0]=70.0; o->d[1]=-20.0; o->d[2]=70.0; o->d[3]=-10.0; }
#endif
    if(!app_save(&b,&n)) return 1;
    f=fopen("tmp/ikkatsu.jww","wb"); fwrite(b,1,n,f); fclose(f);
    printf("tmp/ikkatsu.jww %ld bytes, %d objects\n", n, d->ndrawn);
    return 0;
}
