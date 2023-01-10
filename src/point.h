#ifndef OPENSTG_POINT_H
#define OPENSTG_POINT_H
#include "openstg.h"

typedef struct {
    short x;
    short y;
    float dy;
    unsigned char type;
    Texture2D tex;
    Rectangle src;
    _Bool trash;
}point;
enum TYPE{
    POWER=1, SCORE, BPOWER, SC, FPOWER, ONEUP,
}type;

point * initPoint(short x, short y, unsigned char type, Image *tex, Rectangle src);
void ptick(point *pp);
#endif
