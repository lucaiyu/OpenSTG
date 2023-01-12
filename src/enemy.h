#ifndef OPENSTG_ENEMY_H
#define OPENSTG_ENEMY_H

#include "openstg.h"

typedef struct{
    short x;
    short y;
    unsigned char dx;
    unsigned char sy;
    short health;
    short bonus;
    unsigned char *item_drop_array;
    Rectangle src;
    unsigned char frame;
    unsigned char type;
    void(*p[5])(void);
}enemy;

#endif
