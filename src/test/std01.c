#include "../openstg.h"

unsigned long long eflags;
Player *pplayer;
unsigned long timer;
enemy *pe;

static void renderbak(){
    DrawTexture(bak[0], 32, 16, GRAY);
    DrawTexture(bak[0], 32+256, 16, GRAY);
    DrawTexture(bak[0], 32, 16+256, GRAY);
    DrawTexture(bak[0], 32+256, 16+256, GRAY);
}



void InitStage01() {
    logStr("Loading stage01\n", INFO);
    timer = 0;
    eflags = 0x00000000;
    pplayer = InitPlayer(320, 240, &PL00);
    unsigned char tmp;
    void(*p[5])() = {NULL, NULL, NULL, NULL, NULL};
    pe = initenemy(120, 120, 1, 0, 0, &tmp, p);
    buhead = NULL;
    phead = NULL;
    PlayMusicStream(bgms[13]);
}

static void drawTitle(){
    if(eflags&0x00000001){
        return;
    }
    if(timer>=12*60){
        eflags|=0x00000001;
        return;
    }
    if(timer>=10*60){
        unsigned short alpha = 720 -timer;
        if(alpha<=10){
            alpha = 0;
        }
        DrawTextureRec(title[0], (Rectangle){0, 0, 75, 360}, (Vector2){208, 40}, (Color){255, 255, 255, alpha*2});
        DrawTextureRec(title[0], (Rectangle){0, 465, 128, 47}, (Vector2){285, 331}, (Color){255, 255, 255, alpha*2});
        return;
    }
    if(timer>=7*60&&timer<10*60){
        unsigned short alpha = timer-420;
        if(alpha*3>=256){
            alpha = 85;
        }
        DrawTextureRec(title[0], (Rectangle){0, 0, 75, 360}, (Vector2){208, 40}, (Color){255, 255, 255, alpha*3});
    }
    if(timer>=8*60&&timer<10*60){
        unsigned short alpha = timer-480;
        if(alpha*51>=256){
            alpha=5;
        }
        DrawTextureRec(title[0], (Rectangle){0, 465, 128, 47}, (Vector2){285, 331}, (Color){255, 255, 255, alpha*51});
    }
}
static void loopdraw(){
    ClearBackground(BLACK);
    renderbak();
    loopbu();
    loopp();
    pltick(pplayer);
    tickene(pe);
    renderUI();
    drawTitle();
}



void startStage01(){
    while (!WindowShouldClose()) {
        BeginDrawing();
        UpdateMusicStream(bgms[13]);
        timer++;
        loopdraw();
        EndDrawing();
    }
}