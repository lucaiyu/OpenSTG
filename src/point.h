#ifndef OPENSTG_POINT_H
#define OPENSTG_POINT_H
#include "openstg.h"

typedef struct {
    short x;
    short y;
    unsigned char dy;
    unsigned char type;
    unsigned char value;
    Texture2D tex;
    Rectangle src;
}point;
enum type{
    power=1, blue, bpower, bomb, full, oneUP,
};
#endif
