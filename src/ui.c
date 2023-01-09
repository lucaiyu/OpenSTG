#include <math.h>
#include "openstg.h"
#include <stdio.h>

void rendernum(int num, Vector2 dst){
    if(num < 0 || num > 9){
        return;
    }
    DrawTextureRec(ui[1], (Rectangle){num*16, 48, 16, 16}, dst, WHITE);
}

static void renderKey(){
    DrawTextureRec(ui[0], (Rectangle){0, 191, 60, 17}, (Vector2){433, 61}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){0, 206, 30, 20}, (Vector2){433, 85}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){0, 176, 47, 16}, (Vector2){433, 122}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){0, 160, 43, 16}, (Vector2){433, 146}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){34, 210, 46, 13}, (Vector2){433, 187}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){34, 225, 41, 14}, (Vector2){433, 206}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){49, 160, 15, 15}, (Vector2){433, 227}, WHITE);
    for(int i = 0; i < scoreIn->live; i++){
        DrawTextureRec(ui[0], (Rectangle){32, 241, 15, 15}, (Vector2){497+17*i, 123}, WHITE);
    }
    for(int i = 0; i < scoreIn->bomb; i++){
        DrawTextureRec(ui[0], (Rectangle){48, 241, 15, 15}, (Vector2){497+17*i, 147}, WHITE);
    }
}

static void renderPower(){
    BYTE bits=4;
    if(scoreIn->power<128){
        while (true){
            int tmp = (int)(scoreIn->power/ pow(10, bits))%10;
            if(tmp == 0){
                break;
            }
            bits++;
        }
        for (int i = 0; i < bits; i++){
            int tmp = (int)(scoreIn->power/ pow(10, i))%10;
            rendernum(tmp, (Vector2){497+(bits-1)*15-i*15, 187});
        }
    } else{
        DrawTextureRec(ui[0], (Rectangle){65, 244, 41, 12}, (Vector2){499, 189}, WHITE);
        scoreIn->power = 128;
    }
}

static void renderGraze(){
    if(scoreIn->graze>9999){
        scoreIn->graze = 9999;
    }
    BYTE bits =4;
    while (true){
        int tmp = (int)(scoreIn->graze/ pow(10, bits))%10;
        if(tmp == 0){
            break;
        }
        bits++;
    }
    for (int i = 0; i < bits; i++){
        int tmp = (int)(scoreIn->graze/ pow(10, i))%10;
        rendernum(tmp, (Vector2){497+(bits-1)*15-i*15, 206});
    }
}

static void renderPoint(){
    if(scoreIn->point>9999){
        scoreIn->point = 9999;
    }
    BYTE bits = 4;
    while (true){
        int tmp = (int)(scoreIn->point/ pow(10, bits))%10;
        if(tmp == 0){
            break;
        }
        bits++;
    }
    for (int i = 0; i < bits; i++){
        int tmp = (int)(scoreIn->point/ pow(10, i))%10;
        rendernum(tmp, (Vector2){497+(bits-1)*15-i*15, 227});
    }
}
void renderUI(){
    renderKey();
    renderGraze();
    renderPower();
    renderPoint();
}
