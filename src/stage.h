#ifndef OPENSTG_STAGE_H
#define OPENSTG_STAGE_H
#include "openstg.h"

void InitStage();
void StartStage();

typedef struct{
    unsigned long hiscore;
    unsigned long score;
    unsigned short power;
    unsigned char live;
    unsigned short point;
}score;
#endif
