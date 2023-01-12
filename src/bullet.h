#ifndef OPENSTG_BULLET_H
#define OPENSTG_BULLET_H

#include "openstg.h"

typedef struct {
    short x;
    short y;
    short dx;
    short dy;
    short d2x;
    short d2y;
    short rotate;
    Rectangle src;
    Texture2D tex;
} bullet;
enum BULLETTYPE {
    LASER=1, RING, NOR, RICE, EARRING, CRYSTAL, SMALL, SRING, EBIGX, KNIFE, FLAME, SMALLX, BIGX
};

bullet * InitBullet(short x, short y, short dx, short dy, short d2x, short d2y, Image *tex, Rectangle src, short rotate);

void butick(bullet *pb);

#endif
