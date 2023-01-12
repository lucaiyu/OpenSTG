#include "openstg.h"



score *scoreIn;

void initScore(score *scoreIn){  //GAME SETTINGS
    scoreIn->difficultly = EASY;
    scoreIn->score = 0;
    scoreIn->power = 0;
    scoreIn->hiscore = 0;
    scoreIn->live = 2;
    scoreIn->point = 0;
}



void StartStage() {
    logStr("Initializing stages\n", INFO);
    ldtex();
    scoreIn = (score*) malloc(sizeof(scoreIn));
    initScore(scoreIn);
    InitStage01();
    startStage01();
}
