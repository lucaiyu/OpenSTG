#include "openstg.h"
#include <stdlib.h>

enemy * initEnemy(Vector2 initial_pos, Vector2 goal1, Vector2 goal2, Vector2 goal3, Vector2 finalize, Image *tex, Rectangle uvwh){
    enemy *ep = (enemy*) malloc(sizeof(enemy));
    ep->pos = initial_pos;
    ep->goal1 = goal1;
    ep->goal2 = goal2;
    ep->goal3 = goal3;
    ep->finalize = finalize;
    ep->tex = LoadTextureFromImage(*tex);
    ep->src = uvwh;
    ep->goal_stage = 0;
}
static void render(enemy *ep){
    DrawTextureRec(ep->tex, ep->src, ep->pos, WHITE);
}