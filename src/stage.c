#include "openstg.h"


Player *pplayer;
bulletNode *head;
unsigned long timer;
score *scoreIn;

void initScore(score *scoreIn){
    scoreIn->score = 0;
    scoreIn->power = 0;
    scoreIn->bomb = 3;
    scoreIn->graze = 0;
    scoreIn->hiscore = 0;
    scoreIn->live = 2;
}

void addBullet(bullet *pb) {
    if(head == NULL){
        head = (bulletNode*) malloc(sizeof(bulletNode));
        head->current = pb;
        head->next = NULL;
    } else{
        bulletNode *cur = head;
        while (cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = (bulletNode*) malloc(sizeof(bulletNode));
        cur->next->current = pb;
        cur->next->next = NULL;
    }
}

void InitStage() {
    logStr("Initializing stage\n", INFO);
    timer = 0;
    ldtex();
    pplayer = InitPlayer(320, 240, &PL00);
    head = NULL;
    scoreIn = (score*) malloc(sizeof(scoreIn));
    initScore(scoreIn);
    PlayMusicStream(bgms[5]);
}

static void loopbu() {
    bulletNode *cur = head;
    while (cur!=NULL){
        butick(cur->current);
        cur=cur->next;
    }
}

static void renderbak(){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 29; j++){
            DrawTextureRec(bak[0], (Rectangle){0, 0, 16, 16}, (Vector2){16+i*16, 8+j*16}, GRAY);
        }
    }
}

void delete(bullet *pb){
    if(pb == NULL){
        return;
    }
    bulletNode *cur = head;
    while (cur!=NULL&&cur->next->next!=NULL){
        if(cur->next->current == pb){
            cur->next = cur->next->next;
            break;
        }
        cur=cur->next;
    }
}

void StartStage() {
    while (!WindowShouldClose()) {
        UpdateMusicStream(bgms[5]);
        timer++;
        BeginDrawing();
        ClearBackground(BLACK);
        renderUI();
        renderbak();
        loopbu();
        pltick(pplayer);
        EndDrawing();
    }
}
