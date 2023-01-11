#include "openstg.h"


Player *pplayer;
unsigned long timer;
score *scoreIn;

void initScore(score *scoreIn){
    scoreIn->score = 0;
    scoreIn->power = 0;
    scoreIn->hiscore = 0;
    scoreIn->live = 2;
    scoreIn->point = 0;
}



void InitStage() {
    logStr("Initializing stage\n", INFO);
    timer = 0;
    ldtex();
    pplayer = InitPlayer(320, 240, &PL00);
    buhead = NULL;
    phead = NULL;
    scoreIn = (score*) malloc(sizeof(scoreIn));
    initScore(scoreIn);
    PlayMusicStream(bgms[5]);
}


static void renderbak(){
    DrawTexture(bak[0], 32, 16, GRAY);
    DrawTexture(bak[0], 32+256, 16, GRAY);
    DrawTexture(bak[0], 32, 16+256, GRAY);
    DrawTexture(bak[0], 32+256, 16+256, GRAY);
}



void StartStage() {
    while (!WindowShouldClose()) {
        if(timer%60==0){
            addPoint(initPoint(240, 50, BPOWER, &BULLET[1], (Rectangle){48, 208, 16, 16}));
        }
        UpdateMusicStream(bgms[5]);
        timer++;
        BeginDrawing();
        ClearBackground(BLACK);
        renderbak();
        loopbu();
        loopp();
        renderUI();
        pltick(pplayer);
        EndDrawing();
    }
}
