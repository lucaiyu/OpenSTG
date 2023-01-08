#include "openstg.h"

void rendernum(int num, Vector2 dst){
    if(num < 0 || num > 9){
        return;
    }
    Texture2D asciiTex = LoadTextureFromImage(ui[1]);
    DrawTextureRec(asciiTex, (Rectangle){num*16, 48, 16, 16}, dst, WHITE);
}

static void renderKey(){
    Texture2D uiTex = LoadTextureFromImage(ui[0]);
    DrawTextureRec(uiTex, (Rectangle){0, 191, 60, 17}, (Vector2){433, 61}, WHITE);
    DrawTextureRec(uiTex, (Rectangle){0, 206, 30, 20}, (Vector2){433, 85}, WHITE);
    DrawTextureRec(uiTex, (Rectangle){0, 176, 47, 16}, (Vector2){433, 122}, WHITE);
    DrawTextureRec(uiTex, (Rectangle){0, 160, 43, 16}, (Vector2){433, 146}, WHITE);
    DrawTextureRec(uiTex, (Rectangle){34, 210, 46, 13}, (Vector2){433, 187}, WHITE);
    DrawTextureRec(uiTex, (Rectangle){34, 225, 41, 14}, (Vector2){433, 206}, WHITE);
    DrawTextureRec(uiTex, (Rectangle){49, 160, 15, 15}, (Vector2){433, 227}, WHITE);
    for(int i = 0; i < scoreIn->live; i++){
        DrawTextureRec(uiTex, (Rectangle){32, 241, 15, 15}, (Vector2){497+17*i, 123}, WHITE);
    }
    for(int i = 0; i < scoreIn->bomb; i++){
        DrawTextureRec(uiTex, (Rectangle){48, 241, 15, 15}, (Vector2){497+17*i, 147}, WHITE);
    }
}

static void renderPower(){
    Texture2D uiTex = LoadTextureFromImage(ui[0]);

    if(scoreIn->power<128){
        if(scoreIn->power>=100){
            rendernum(scoreIn->power/100%10, (Vector2){497, 187});
            rendernum(scoreIn->power/10%10, (Vector2){497+15, 187});
            rendernum(scoreIn->power%10, (Vector2){497+15+15, 187});
        }
        if(scoreIn->power<100&&scoreIn->power>9){
            rendernum(scoreIn->power/10%10, (Vector2){497, 187});
            rendernum(scoreIn->power%10, (Vector2){497+15, 187});
        } else{
            rendernum(scoreIn->power, (Vector2){497, 187});
        }
    } else{
        DrawTextureRec(uiTex, (Rectangle){65, 244, 41, 12}, (Vector2){499, 189}, WHITE);
        scoreIn->power = 128;
    }
}

static void renderGraze(){
    if(scoreIn->graze>999){
        if(scoreIn->graze>9999){
            scoreIn->graze = 9999;
        }
        rendernum(scoreIn->graze/1000%10, (Vector2){497, 206});
        rendernum(scoreIn->graze/100%10, (Vector2){497+15, 206});
        rendernum(scoreIn->graze/10%10, (Vector2){497+15+15, 206});
        rendernum(scoreIn->graze%10, (Vector2){497+15+15+15, 206});
        return;
    }
    if(scoreIn->graze>99&&scoreIn->graze<1000){
        rendernum(scoreIn->graze/100%10, (Vector2){497, 206});
        rendernum(scoreIn->graze/10%10, (Vector2){497+15, 206});
        rendernum(scoreIn->graze%10, (Vector2){497+15+15, 206});
        return;
    }
    if(scoreIn->graze>9&&scoreIn->graze<100){
        rendernum(scoreIn->graze/10%10, (Vector2){497, 206});
        rendernum(scoreIn->graze%10, (Vector2){497+15, 206});
        return;
    } else{
        rendernum(scoreIn->graze%10, (Vector2){497, 206});
        return;
    }
}

static void renderPoint(){
    if(scoreIn->point>999){
        if(scoreIn->point>9999){
            scoreIn->point = 9999;
        }
        rendernum(scoreIn->point/1000%10, (Vector2){497, 227});
        rendernum(scoreIn->point/100%10, (Vector2){497+15, 227});
        rendernum(scoreIn->point/10%10, (Vector2){497+15+15, 227});
        rendernum(scoreIn->point%10, (Vector2){497+15+15+15, 227});
        return;
    }
    if(scoreIn->graze>99&&scoreIn->point<1000){
        rendernum(scoreIn->point/100%10, (Vector2){497, 227});
        rendernum(scoreIn->point/10%10, (Vector2){497+15, 227});
        rendernum(scoreIn->point%10, (Vector2){497+15+15, 227});
        return;
    }
    if(scoreIn->graze>9&&scoreIn->point<100){
        rendernum(scoreIn->point/10%10, (Vector2){497, 227});
        rendernum(scoreIn->point%10, (Vector2){497+15, 227});
        return;
    } else{
        rendernum(scoreIn->point%10, (Vector2){497, 227});
        return;
    }
}
void renderUI(){
    renderKey();
    renderGraze();
    renderPoint();
    renderPower();
}
