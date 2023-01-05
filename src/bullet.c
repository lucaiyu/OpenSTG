#include "openstg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bullet * InitBullet(short x, short y, short dx, short dy, short d2x, short d2y, short d3x, short d3y, Image *tex, short u, short v, short w, short h, short rotate){
    bullet *pb = malloc(sizeof(bullet));
    if(pb == NULL){
        logStr("could not alloc memory!", PANIC);
        exit(-1);
    }
    pb->x = x;
    pb->y = y;
    pb->dx = dx;
    pb->dy = dy;
    pb->d2x = d2x;
    pb->d2y = d2y;
    pb->d3x = d3x;
    pb->d3y = d3y;
    pb->rotate = rotate;
    pb->trash = false;
    pb->src = (Rectangle){u, v, w, h};
    pb->tex = LoadTextureFromImage(*tex);
    return pb;
}
void delta(bullet *pb){
    pb->d2x+=pb->d3x;
    pb->d2y+=pb->d3y;
    pb->dx+=pb->d2x;
    pb->dy+=pb->d2y;
    pb->x+=pb->dx;
    pb->y+=pb->dy;
}
void burender(bullet *pb){
    DrawTexturePro(pb->tex, pb->src,(Rectangle){pb->x, pb->y, pb->src.width, pb->src.height} ,(Vector2){0, pb->src.height/2}, pb->rotate, WHITE);
}
void budestroy(bullet *pb){
    free(pb);
    pb = NULL;
}
void check(bullet *pb){
    if(pb->x<0||pb->x>384||pb->y<0||pb->y>480){
        pb->trash = true;
    }
}
void butick(bullet *pb){
    if(pb->trash == false){
        delta(pb);
        burender(pb);
        check(pb);
    }
}

