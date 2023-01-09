#include "openstg.h"

point * initPoint(short x, short y, unsigned char type, unsigned char value, Image *tex, Rectangle src){
    point *pp = (point *) malloc(sizeof(point));
    pp->x = x;
    pp->y = y;
    pp->dy = 0;
    pp->type = type;
    pp->value = value;
    pp->src = src;
    pp->tex = LoadTextureFromImage(*tex);
    return pp;
}

static void move(point *pp){
    pp->y+=pp->dy;
    pp->dy = (unsigned char)pp->dy+0.1;
}

static void render(point *pp){
    DrawTextureRec(pp->tex, pp->src, (Vector2){pp->x, pp->y}, WHITE);
}

static void check(point *pp){
    if(pp->x<0+16||pp->x>433||pp->y<0+75||pp->y>480-8) {
        pp->x = 1000;
        pp->y = 1000;
        pp->dy = 0;
    }
}
void tick(point *pp){
    check(pp;)
    move(pp);
    render(pp);
}