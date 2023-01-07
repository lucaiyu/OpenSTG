#include "openstg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bullet * InitBullet(short x, short y, short dx, short dy, short d2x, short d2y, Image *tex, Rectangle src, short rotate){
    bullet *pb = (bullet*)malloc(sizeof(bullet));
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
    pb->rotate = rotate;
    pb->trash = false;
    pb->src = src;
    pb->tex = LoadTextureFromImage(*tex);
    return pb;
}
static void delta(bullet *pb){
    pb->dx+=pb->d2x;
    pb->dy+=pb->d2y;
    pb->x+=pb->dx;
    pb->y+=pb->dy;
}
static void render(bullet *pb){
    DrawTexturePro(pb->tex, pb->src,(Rectangle){pb->x, pb->y, pb->src.width, pb->src.height} ,(Vector2){0, pb->src.height},
                   pb->rotate, WHITE);
}
static void check(bullet *pb){
    if(pb->x<0||pb->x>384||pb->y<0||pb->y>480){
        pb->trash = true;
    }
}
void butick(bullet *pb){
    if(pb->trash == false){
        delta(pb);
        render(pb);
        check(pb);
    }
}

