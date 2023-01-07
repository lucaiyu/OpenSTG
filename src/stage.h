#ifndef OPENSTG_STAGE_H
#define OPENSTG_STAGE_H


#include "openstg.h"

void InitStage();
void StartStage();
void addBullet(bullet *pb);

typedef struct node{
    bullet *current;
    struct node *next;
}bulletNode;
#endif
