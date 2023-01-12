#ifndef OPENSTG_STAGE_H
#define OPENSTG_STAGE_H
#include "openstg.h"

void StartStage();
void StartStage();

typedef struct{
    unsigned char difficultly;
    unsigned long hiscore;
    unsigned long score;
    unsigned short power;
    unsigned char live;
    unsigned short point;
}score;

enum difficultly{
    EASY=1, NORMAL, HARD, LUNATIC, EXTRA
};
#endif
