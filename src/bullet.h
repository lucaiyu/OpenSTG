#ifndef OPENSTG_BULLET_H
#define OPENSTG_BULLET_H
#include <raylib.h>
typedef struct{
    short x;
    short y;
    short dx;
    short dy;
    short d2x;
    short d2y;
    short d3x;
    short d3y;
    short rotate;
    bool trash;
    Rectangle src;
    Texture2D tex;
}bullet;
enum BULLETTYPE{
    LASER=1, ROCKET, RING, CIRCLE, RICE, TOWER, SMALL, CRYSTAL, SQUARE, AMMO, DARK, STAR, ROUND
};
enum SPECBULLETTYPE{
    XXLSTAR=14, XXLRING, BUTTERFLY, KNIFE, XXLRICE, SUN, XXXLRING
};
bullet * InitBullet(short x, short y, short dx, short dy, short d2x, short d2y, short d3x, short d3y, Image *tex, short u, short v, short w, short h, short rotate);
void butick(bullet *pb);
#endif
