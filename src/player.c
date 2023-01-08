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
    pplayer->power = 3;
    pplayer->frame = 0;//anm frame
    pplayer->tmp = 0;//frame slow factor
    pplayer->speed = 2;
    pplayer->butimer = 0;
    pplayer->temp = false;//is mode transfer? usage:init anm when mode switch
    pplayer->movement = 0;//anm mode 0:NORMAL 1:LEFT 2:RIGHT
    pplayer->tex = LoadTextureFromImage(*tex);
    return pplayer;
}

static void render(Player *pplayer) {
        DrawTextureRec(pplayer->tex, (Rectangle) {pplayer->u, pplayer->v, 32, 48}, (Vector2) {pplayer->x, pplayer->y},
                       WHITE);
        if(pplayer->power == 1){
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x+15, pplayer->y-20, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            return;
        }
        if(pplayer->power == 2){
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x+16+45, pplayer->y+24, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x-16-15, pplayer->y+24, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            return;
        }
        if(pplayer->power == 3){
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x+15+20, pplayer->y-20, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x+15-20, pplayer->y-20, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x+16+45, pplayer->y+24, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle){81, 145, 15, 15}, (Rectangle){pplayer->x-16-15, pplayer->y+24, 15, 15}, (Vector2){7, 7}, timer%100*3.6, WHITE);
            return;
        }

}
static void anm(Player *pplayer) {
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
                pplayer->frame = 3;
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
                pplayer->frame = 3;
            }
            pplayer->u = 32 * pplayer->frame;
            pplayer->v = 96;
        }
    }
}

static void shoot(Player *pplayer) {
    if (pplayer->butimer == 5) {
        addBullet(InitBullet(pplayer->x+16+5, pplayer->y+48, 0, -1, 0, -1, &PL00, (Rectangle){194, 145, 11, 62}, 0));
        addBullet(InitBullet(pplayer->x-16+15, pplayer->y+48, 0, -1, 0, -1, &PL00, (Rectangle){194, 145, 11, 62}, 0));
        if(pplayer->power >= 1){
            addBullet(InitBullet(pplayer->x+16+5, pplayer->y+48, 0, -1, 0, -1, &PL00, (Rectangle){207, 145, 6, 54}, 0));
            addBullet(InitBullet(pplayer->x-16+15, pplayer->y+48, 0, -1, 0, -1, &PL00, (Rectangle){207, 145, 6, 54}, 0));
        }
        if(pplayer->power >=3){
            addBullet(InitBullet(pplayer->x+16+45, pplayer->y+48, 0, -1, 0, -1, &PL00, (Rectangle){207, 145, 6, 54}, 0));
            addBullet(InitBullet(pplayer->x-16-15, pplayer->y+48, 0, -1, 0, -1, &PL00, (Rectangle){207, 145, 6, 54}, 0));
        }

        pplayer->butimer = 0;
    } else {
        pplayer->butimer++;
    }
}

static void ctrl(Player *pplayer) {
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