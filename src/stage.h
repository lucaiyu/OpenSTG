#ifndef OPENSTG_STAGE_H
#define OPENSTG_STAGE_H
#include "openstg.h"

void InitStage();
void StartStage();

typedef struct{
    unsigned long hiscore;
    unsigned long score;
    unsigned char power;
    unsigned char live;
    unsigned char bomb;
    unsigned short point;
    unsigned short graze;
}score;
#endif
