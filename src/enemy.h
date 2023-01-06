#ifndef OPENSTG_ENEMY_H
#define OPENSTG_ENEMY_H

#include "openstg.h"

typedef struct {
    Vector2 pos;
    Rectangle src;
    Texture2D tex;
    Vector2 initial;
    Vector2 goal1;
    Vector2 goal2;
    Vector2 goal3;
    Vector2 finalize;
    unsigned char goal_stage;
}enemy;
enemy * initEnemy(Vector2 initial_pos, Vector2 goal1, Vector2 goal2, Vector2 goal3, Vector2 finalize, Image *tex, Rectangle uvwh);
#endif
