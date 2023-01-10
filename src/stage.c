#include "openstg.h"


Player *pplayer;
unsigned long timer;
score *scoreIn;

void initScore(score *scoreIn){
    scoreIn->score = 0;
    scoreIn->power = 0;
    scoreIn->bomb = 3;
    scoreIn->graze = 0;
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
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 29; j++){
            DrawTextureRec(bak[0], (Rectangle){0, 0, 16, 16}, (Vector2){16+i*16, 8+j*16}, GRAY);
        }
    }
}



void StartStage() {
    while (!WindowShouldClose()) {
        if(timer%60 == 0){
            addPoint(initPoint(120, 120, 1, &BULLET[0], (Rectangle){2, 2, 12, 12}));
        }
        UpdateMusicStream(bgms[5]);
        timer++;
        BeginDrawing();
        ClearBackground(BLACK);
        renderUI();
        renderbak();
        loopbu();
        loopp();
        pltick(pplayer);
        EndDrawing();
    }
}
