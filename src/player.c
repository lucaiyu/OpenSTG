#include "openstg.h"


Player *InitPlayer(int x, int y, Image *tex) {
    Player *pplayer = malloc(sizeof(Player));
    if (pplayer == NULL) {
        logStr("could not alloc memory!", PANIC);
        exit(-1);
    }
    pplayer->x = x;
    pplayer->y = y;
    pplayer->u = 0;
    pplayer->v = 0;
    pplayer->power = 0;
    pplayer->frame = 0;//anm frame
    pplayer->tmp = 0;//frame slow factor
    pplayer->speed = 4;
    pplayer->butimer = 0;
    pplayer->temp = false;//is mode transfer? usage:init anm when mode switch
    pplayer->slowmode = false;
    pplayer->touchframe = false;
    pplayer->movement = 0;//anm mode 0:NORMAL 1:LEFT 2:RIGHT
    pplayer->tex = LoadTextureFromImage(*tex);
    return pplayer;
}

static void updatepower(Player *pplayer) {
    if (scoreIn->power < 100) {
        pplayer->power = 0;
    }
    if (scoreIn->power >= 100 && scoreIn->power < 200) {
        pplayer->power = 1;
    }
    if (scoreIn->power >= 200 && scoreIn->power < 400) {
        pplayer->power = 2;
    }
    if (scoreIn->power >= 400) {
        pplayer->power = 3;
    }
}

static void render(Player *pplayer) {
    DrawTextureRec(pplayer->tex, (Rectangle) {pplayer->u, pplayer->v, 32, 48}, (Vector2) {pplayer->x, pplayer->y},
                   WHITE);
    if (pplayer->slowmode == true) {
        DrawCircle(pplayer->x+16, pplayer->y+24, 3, WHITE);
    }
    if (pplayer->power == 1) {
        DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                       (Rectangle) {pplayer->x + 15, pplayer->y - 20, 15, 15}, (Vector2) {7, 7}, timer % 100 * 3.6,
                       WHITE);
        return;
    }
    if (pplayer->power == 2) {
        if (pplayer->slowmode == false) {
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 16 + 45, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x - 16 - 15, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            return;
        } else {
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 16 + 25, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x - 16 + 5, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            return;
        }

    }
    if (pplayer->power == 3) {
        if (pplayer->slowmode == false) {
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 15 + 20, pplayer->y - 20, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 15 - 20, pplayer->y - 20, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 16 + 45, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x - 16 - 15, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            return;
        } else {
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 15 + 10, pplayer->y - 10, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 15 - 10, pplayer->y - 10, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x + 16 + 25, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            DrawTexturePro(pplayer->tex, (Rectangle) {81, 145, 15, 15},
                           (Rectangle) {pplayer->x - 16 + 5, pplayer->y + 24, 15, 15}, (Vector2) {7, 7},
                           timer % 100 * 3.6, WHITE);
            return;
        }
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
        addBullet(InitBullet(pplayer->x + 16 + 5, pplayer->y + 48, 0, -1, 0, -1, &PL00, (Rectangle) {194, 145, 11, 62},
                             0));
        addBullet(InitBullet(pplayer->x - 16 + 15, pplayer->y + 48, 0, -1, 0, -1, &PL00, (Rectangle) {194, 145, 11, 62},
                             0));
        if (pplayer->power >= 1) {
            addBullet(InitBullet(pplayer->x + 16 + 15, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                 (Rectangle) {207, 145, 6, 54}, 0));
            addBullet(
                    InitBullet(pplayer->x - 16 + 5, pplayer->y + 48, 0, -1, 0, -1, &PL00, (Rectangle) {207, 145, 6, 54},
                               0));
        }
        if (pplayer->power >= 2) {
            if (pplayer->slowmode == false) {
                addBullet(InitBullet(pplayer->x + 16 + 35, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
                addBullet(InitBullet(pplayer->x - 16 - 15, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
            } else {
                addBullet(InitBullet(pplayer->x + 16 + 5, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
                addBullet(InitBullet(pplayer->x - 16 + 15, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
            }

        }
        if (pplayer->power >= 10) {
            if (pplayer->slowmode == false) {
                addBullet(InitBullet(pplayer->x + 16 + 25, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
                addBullet(InitBullet(pplayer->x - 16 - 5, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
                addBullet(InitBullet(pplayer->x + 16 + 45, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
                addBullet(InitBullet(pplayer->x - 16 - 25, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
            } else {
                addBullet(InitBullet(pplayer->x - 16 - 5, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
                addBullet(InitBullet(pplayer->x + 16 + 25, pplayer->y + 48, 0, -1, 0, -1, &PL00,
                                     (Rectangle) {207, 145, 6, 54}, 0));
            }

        }

        pplayer->butimer = 0;
    } else {
        pplayer->butimer++;
    }
}

static void spellcard(Player *pplayer) {
    if (scoreIn->power > 99) {
        scoreIn->power -= 100;
        // TODO
        //launch spellcard
    }
}

static void ctrl(Player *pplayer) {
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        pplayer->speed = 2;
        pplayer->slowmode = true;
    } else {
        pplayer->speed = 4;
        pplayer->slowmode = false;
    }
    if (IsKeyPressed(KEY_X)) {
        spellcard(pplayer);
    }
    if (IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)) {
        pplayer->temp = true;
        pplayer->movement = 0;
    }
    if (IsKeyPressed(KEY_LEFT)) {
        pplayer->temp = true;
        pplayer->movement = 1;
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        pplayer->temp = true;
        pplayer->movement = 2;
    }
    if (IsKeyDown(KEY_Z)) {
        shoot(pplayer);
    }
    if (pplayer->x > 32 && IsKeyDown(KEY_LEFT)) {
        pplayer->x -= pplayer->speed;
    }
    if (pplayer->x < 384 && IsKeyDown(KEY_RIGHT)) {
        pplayer->x += pplayer->speed;
    }
    if (pplayer->y > 16 && IsKeyDown(KEY_UP)) {
        pplayer->y -= pplayer->speed;
    }
    if (pplayer->y < 480 - 16 - 48 && IsKeyDown(KEY_DOWN)) {
        pplayer->y += pplayer->speed;
    }
}


void pltick(Player *pplayer) {
    updatepower(pplayer);
    ctrl(pplayer);
    anm(pplayer);
    render(pplayer);
}