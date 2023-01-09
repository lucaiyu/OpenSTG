#ifndef OPENSTG_PLAYER_H
#define OPENSTG_PLAYER_H
#include <raylib.h>

typedef struct
{
    short x;
    short y;
    short u;
    short v;
    short frame;
    short butimer;
    short tmp;
    unsigned char power;
    _Bool temp;
    _Bool slowmode;
    _Bool touchframe;
    short speed;
    short movement;
    Texture2D tex;
}Player;
Player * InitPlayer(int x, int y, Image *tex);
void pltick(Player *pplayer);

#endif
