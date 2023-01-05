#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>


#include "openstg.h"


Player *InitPlayer(int x, int y, Image *tex) {
    Player *pplayer = malloc(sizeof(Player));
    if(pplayer == NULL){
        logStr("could not alloc memory!", PANIC);
        exit(-1);
    }
    pplayer->x = x;
    pplayer->y = y;
    pplayer->u = 0;
    pplayer->v = 0;
    pplayer->frame = 0;//anm frame
    pplayer->tmp = 0;//frame slow factor
    pplayer->speed = 2;
    pplayer->butimer = 0;
    pplayer->temp = false;//is mode transfer? usage:init anm when mode switch
    pplayer->movement = 0;//anm mode 0:NORMAL 1:LEFT 2:RIGHT
    pplayer->tex = LoadTextureFromImage(*tex);
    return pplayer;
}

void render(Player *pplayer) {
    DrawTextureRec(pplayer->tex, (Rectangle) {pplayer->u, pplayer->v, 32, 48}, (Vector2) {pplayer->x, pplayer->y},
                   WHITE);
}

void updateTex(Player *pplayer, Image *tex) {
    UnloadTexture(pplayer->tex);
    pplayer->tex = LoadTextureFromImage(*tex);
}

void anm(Player *pplayer) {
    if (pplayer->movement == 0) {
        pplayer->tmp++;
        if (pplayer->tmp == 10) {
            pplayer->tmp = 0;
            pplayer->frame++;
        }
        if (pplayer->frame > 7) {
            pplayer->frame = 0;
        }
        pplayer->u = 32 * pplayer->frame;
        pplayer->v = 0;
    }
    if (pplayer->movement == 1) {
        if (pplayer->temp == true) {
            pplayer->temp = false;
            pplayer->frame = 0;
            pplayer->tmp = 0;
            pplayer->u = 32 * pplayer->frame;
            pplayer->v = 48;
        } else {
            pplayer->tmp++;
            pplayer->tmp++;
            if (pplayer->tmp == 10) {
                pplayer->tmp = 0;
                pplayer->frame++;
            }
            if (pplayer->frame > 7) {
                pplayer->frame = 4;
            }
            pplayer->u = 32 * pplayer->frame;
            pplayer->v = 48;
        }
    }
    if (pplayer->movement == 2) {
        if (pplayer->temp == true) {
            pplayer->temp = false;
            pplayer->frame = 0;
            pplayer->tmp = 0;
            pplayer->u = 32 * pplayer->frame;
            pplayer->v = 96;
        } else {
            pplayer->tmp++;
            pplayer->tmp++;
            if (pplayer->tmp == 10) {
                pplayer->tmp = 0;
                pplayer->frame++;
            }
            if (pplayer->frame > 7) {
                pplayer->frame = 4;
            }
            pplayer->u = 32 * pplayer->frame;
            pplayer->v = 96;
        }
    }
}

void shoot(Player *pplayer) {
    if (pplayer->butimer == 5) {
        //addBullet(InitBullet(pplayer->x+11, pplayer->y-52, 0, -1, 0, -1, 0, 0, &PL00, 194, 145, 10, 63, -90));
        addBullet(InitBullet(pplayer->x+7, pplayer->y-17, 0, -1, 0, -1, 0, 0, &BULLET[0], 15, 15, 16, 17, 0));
        //addBullet(InitBullet(pplayer->x + 10, pplayer->y - 52, 0, -1, 0, -1, 0, 0, &PL00, 215, 145, 12, 55));
        pplayer->butimer = 0;
    } else {
        pplayer->butimer++;
    }
}

void ctrl(Player *pplayer) {
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        pplayer->speed = 1;
    } else {
        pplayer->speed = 4;
    }
    if (IsKeyPressed(KEY_LEFT)) {
        pplayer->temp = true;
        pplayer->movement = 1;
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        pplayer->temp = true;
        pplayer->movement = 2;
    }
    if (IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)) {
        pplayer->movement = 0;
    }
    if (IsKeyDown(KEY_Z)) {
        shoot(pplayer);
    }
    if (pplayer->x <= 0) {
        pplayer->x++;
    }
    if (pplayer->x >= 384 - 32) {
        pplayer->x--;
    }
    if (pplayer->y <= 0) {
        pplayer->y++;
    }
    if (pplayer->y >= 480 - 48) {
        pplayer->y--;
    }
    if (!(pplayer->x < 0 || pplayer->x > 384 - 32)) {
        if (IsKeyDown(KEY_LEFT)) {
            pplayer->x -= pplayer->speed;
            return;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            pplayer->x += pplayer->speed;
            return;
        }
    }
    if (!(pplayer->y < 0 || pplayer->y > 480 - 48)) {
        if (IsKeyDown(KEY_UP)) {
            pplayer->y -= pplayer->speed;
            return;
        }
        if (IsKeyDown(KEY_DOWN)) {
            pplayer->y += pplayer->speed;
            return;
        }
    }
}

void pltick(Player *pplayer) {
    render(pplayer);
    ctrl(pplayer);
    anm(pplayer);
}

void pldestroy(Player *pplayer) {
    free(pplayer);
    pplayer = NULL;
}
