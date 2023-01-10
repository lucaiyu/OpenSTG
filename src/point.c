#include "openstg.h"

point * initPoint(short x, short y, unsigned char type, Image *tex, Rectangle src){
    point *pp = (point *) malloc(sizeof(point));
    pp->x = x;
    pp->y = y;
    pp->dy = 0;
    pp->type = type;
    pp->src = src;
    pp->trash = false;
    pp->tex = LoadTextureFromImage(*tex);
    return pp;
}

static void move(point *pp){
    pp->y+=pp->dy;
    if(pp->dy<5){
        pp->dy = pp->dy+0.1;
    }
}

static void render(point *pp){
    DrawTextureRec(pp->tex, pp->src, (Vector2){pp->x, pp->y}, WHITE);
}

static void check(point *pp){
    if(pp->x<0+16||pp->x>433||pp->y<-32||pp->y>480-8) {
        deletep(pp);
    }
    if(collision((Rectangle){pp->x, pp->y, pp->src.width, pp->src.height}, (Rectangle){pplayer->x, pplayer->y, 32, 48})){
        switch (pp->type) {
            case 1:{
                scoreIn->power+=1;
                pp->trash = true;
                break;
            }
            case 2:{
                scoreIn->point++;
                pp->trash = true;
                break;
            }
            case 3:{
                scoreIn->power+=8;
                pp->trash = true;
                break;
            }
            case 4:{
                scoreIn->bomb++;
                pp->trash = true;
                break;
            }
            case 5:{
                scoreIn->power=128;
                pp->trash = true;
                break;
            }
            case 6:{
                scoreIn->live++;
                pp->trash = true;
                break;
            }
        }
    }
}
void ptick(point *pp){
    if(!pp->trash){
        check(pp);
        render(pp);
        move(pp);
    }
}