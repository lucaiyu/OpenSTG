#include "openstg.h"
#include <raylib.h>

#include <stdio.h>
#include <stdlib.h>

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
        scoreIn->graze+=10;
        scoreIn->point+=10;
        if(timer%5==0){
            scoreIn->power++;
        }
        timer++;
        BeginDrawing();
        loopbu();
        pltick(pplayer);
        renderUI();
        ClearBackground((Color){25, 25, 36});
        EndDrawing();
    }
}
