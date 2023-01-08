#ifndef OPENSTG_STAGE_H
#define OPENSTG_STAGE_H


#include "openstg.h"

void InitStage();
void StartStage();
void addBullet(bullet *pb);
void delete(bullet *pb);

typedef struct{
    unsigned long hiscore;
    unsigned long score;
    unsigned char power;
    unsigned char live;
    unsigned char bomb;
    unsigned char graze;
}score;

typedef struct node{
    bullet *current;
    struct node *next;
}bulletNode;
#endif
