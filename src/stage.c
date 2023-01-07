#include "openstg.h"
#include <raylib.h>

#include <stdio.h>
#include <stdlib.h>

#define BULLET_BUFFER 65535
Player *pplayer;
bullet **ebp;
int esp;
int len;

unsigned long timer;

void clearstage(){
    esp = 0;
}

void addBullet(bullet *pb) {
    esp++;
    if(esp>=len){
        ebp = (bullet**) realloc(ebp, (len+BULLET_BUFFER)*sizeof(bullet*));
        if(ebp == NULL){
            logStr("could not alloc memory!", PANIC);
            exit(-1);
        }
        len = len+BULLET_BUFFER;
    }
    ebp[esp-1] = pb;
}

void InitStage() {
    logStr("Initializing stage\n", INFO);
    ebp = (bullet**) malloc(BULLET_BUFFER*sizeof(bullet*));
    if(ebp == NULL){
        logStr("could not alloc memory!", PANIC);
        exit(-1);
    }
    len = BULLET_BUFFER;
    timer = 0;
    esp = 0;
    ldtex();
    pplayer = InitPlayer(320, 240, &PL01);
}

void loopbu() {
    for (int i = 0; i < esp; i++) {
        if (ebp[i]!=NULL) {
            butick(ebp[i]);
        }
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