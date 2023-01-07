#include "openstg.h"
#include <raylib.h>

#include <stdio.h>
#include <stdlib.h>

Player *pplayer;
bulletNode *head;
unsigned long timer;

void addBullet(bullet *pb) {
    if(head == NULL){
        head = (bulletNode*) malloc(sizeof(bulletNode));
        head->current = pb;
        head->next = NULL;
        return;
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
}

void loopbu() {
    bulletNode *cur = head;
    while (cur!=NULL&&cur->next!=NULL&&cur->current!=NULL){
        butick(cur->current);
        cur=cur->next;
    }
}

void StartStage() {
    while (!WindowShouldClose()) {
        timer++;
        BeginDrawing();
        loopbu();
        pltick(pplayer);
        ClearBackground(BLACK);
        EndDrawing();
    }
}