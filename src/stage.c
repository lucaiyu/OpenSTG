#include "openstg.h"

#define DEBUG


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
    scoreIn->point = 0;
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
    point *pp1 = initPoint(100, 30, POWER, &BULLET[0], (Rectangle){2, 2, 12, 12});
    point *pp2 = initPoint(120, 30, SCORE, &BULLET[0], (Rectangle){18, 2, 12, 12});
    point *pp3 = initPoint(140, 30, BPOWER, &BULLET[0], (Rectangle){32, 0, 16, 16});
    point *pp4 = initPoint(160, 30, SC, &BULLET[0], (Rectangle){48, 0, 16, 16});
    point *pp5 = initPoint(180, 30, FPOWER, &BULLET[0], (Rectangle){64, 0, 16, 16});
    point *pp6 = initPoint(200, 30, ONEUP, &BULLET[0], (Rectangle){80, 0, 16, 16});
    while (!WindowShouldClose()) {
        UpdateMusicStream(bgms[5]);
        timer++;
        BeginDrawing();
        ClearBackground(BLACK);
        renderUI();
        renderbak();
        loopbu();
        ptick(pp1);
        ptick(pp2);
        ptick(pp3);
        ptick(pp4);
        ptick(pp5);
        ptick(pp6);
        pltick(pplayer);
        EndDrawing();
    }
}
