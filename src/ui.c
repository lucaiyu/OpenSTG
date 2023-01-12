#include "openstg.h"

static void rendernum(int num, Vector2 dst){
    if(num < 0 || num > 9){
        return;
    }
    DrawTextureRec(ui[0], (Rectangle){338+num*16, 0, 16, 20}, dst, WHITE);
}

static void rendersnum(int num, Vector2 dst){
    if(num < 0 || num > 9){
        return;
    }
    DrawTextureRec(ui[0], (Rectangle){272+num*8, 80, 8, 9}, dst, WHITE);
}

static void renderKey(){
    DrawTextureRec(ui[0], (Rectangle){256, 0, 64, 21}, (Vector2){432, 49}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){271, 21, 49, 19}, (Vector2){448, 75}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){266, 41, 54, 20}, (Vector2){444, 106}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){266, 62, 54, 18}, (Vector2){444, 129}, WHITE);
    for(int i = 0; i < scoreIn->live; i++){
        DrawTextureRec(ui[0], (Rectangle){496, 2, 16, 16}, (Vector2){515+12*i, 108}, WHITE);
    }
}

static void renderPower(){
    if(scoreIn->power>=500){
        scoreIn->power = 500;
        DrawTextureRec(ui[0], (Rectangle){352, 22, 41, 18}, (Vector2){516, 130}, WHITE);
        return;
    }
    unsigned char master = ((int)scoreIn->power/100)%10;
    unsigned char slave1 = ((int)scoreIn->power/10)%10;
    unsigned char slave2 = scoreIn->power%10;
    rendernum(master, (Vector2){516, 130});
    DrawTextureRec(ui[0], (Rectangle){339, 33, 6, 6}, (Vector2){530, 142}, WHITE);
    rendersnum(slave1, (Vector2){537, 139});
    rendersnum(slave2, (Vector2){545, 139});
}
static void rendercur(){
    DrawTextureRec(ui[0], (Rectangle){32, 0, 224, 480}, (Vector2){640-224, 0}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){0, 0, 32, 513}, (Vector2){0, 0}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){32, 480, 352, 16}, (Vector2){64, 0}, WHITE);
    DrawTextureRec(ui[0], (Rectangle){32, 496, 352, 16}, (Vector2){64, 480-16}, WHITE);
}

static void renderhiscore(){
    if(scoreIn->hiscore>999999999){
        scoreIn->hiscore = 999999999;
    }
    BYTE bits = 9;
    while (true){
        int tmp = (int)(scoreIn->hiscore/ pow(10, bits))%10;
        if(tmp == 0){
            break;
        }
        bits++;
    }
    for (int i = 0; i < bits; i++){
        int tmp = (int)(scoreIn->hiscore/ pow(10, i))%10;
        rendernum(tmp, (Vector2){516+(bits-1)*12-i*12, 49});
    }
}

static void renderscore(){
    if(scoreIn->score>999999999){
        scoreIn->score = 999999999;
    }
    BYTE bits = 9;
    while (true){
        int tmp = (int)(scoreIn->score/ pow(10, bits))%10;
        if(tmp == 0){
            break;
        }
        bits++;
    }
    for (int i = 0; i < bits; i++){
        int tmp = (int)(scoreIn->score/ pow(10, i))%10;
        rendernum(tmp, (Vector2){516+(bits-1)*12-i*12, 75});
    }
}

static void renderdiff(){
    switch (scoreIn->difficultly) {
        case 1:{
            DrawTextureRec(ui[0], (Rectangle){277, 304, 37, 15}, (Vector2){499, 27}, WHITE);
            return;
        }
        case 2:{
            DrawTextureRec(ui[0], (Rectangle){264, 320, 65, 15}, (Vector2){499, 27}, WHITE);
            return;
        }
        case 3:{
            DrawTextureRec(ui[0], (Rectangle){275, 336, 44, 16}, (Vector2){499, 27}, WHITE);
            return;
        }
        case 4:{
            DrawTextureRec(ui[0], (Rectangle){265, 352, 63, 15}, (Vector2){499, 27}, WHITE);
            return;
        }
        case 5:{
            DrawTextureRec(ui[0], (Rectangle){274, 368, 49, 16}, (Vector2){499, 27}, WHITE);
            return;
        }
    }
}
void renderUI(){
    rendercur();
    renderKey();
    renderdiff();
    renderhiscore();
    renderscore();
    renderPower();
}
