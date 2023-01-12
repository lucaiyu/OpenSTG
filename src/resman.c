#include "openstg.h"

Image PL00;
Image PL01;
Image BULLET[4];
Texture2D ui[2];
Texture2D bak[1];
Texture2D title[1];
Music bgms[18];


//load texture into RAM
void ldtex(){
	logStr("Loading resources\n", INFO);
    PL00 = LoadImage("assets/player/pl00/pl00.png");
    PL01 = LoadImage("assets/player/pl01/pl01.png");
    BULLET[0] = LoadImage("assets/bullet/etama.png");
    BULLET[1] = LoadImage("assets/bullet/etama2.png");
    BULLET[2] = LoadImage("assets/bullet/etama3.png");
    BULLET[3] = LoadImage("assets/bullet/etama6.png");
    ui[0] = LoadTexture("assets/front/front00.png");
    ui[1] = LoadTexture("assets/ascii/ascii.png");
    bak[0] = LoadTexture("assets/background/stg1bg.png");
    title[0] = LoadTexture("assets/front/st01logo.png");
    bgms[0] = LoadMusicStream("assets/BGM/th10_1.mp3");
    bgms[1] = LoadMusicStream("assets/BGM/th10_2.mp3");
    bgms[2] = LoadMusicStream("assets/BGM/th10_3.mp3");
    bgms[3] = LoadMusicStream("assets/BGM/th10_4.mp3");
    bgms[4] = LoadMusicStream("assets/BGM/th10_5.mp3");
    bgms[5] = LoadMusicStream("assets/BGM/th10_6.mp3");
    bgms[6] = LoadMusicStream("assets/BGM/th10_7.mp3");
    bgms[7] = LoadMusicStream("assets/BGM/th10_8.mp3");
    bgms[8] = LoadMusicStream("assets/BGM/th10_9.mp3");
    bgms[9] = LoadMusicStream("assets/BGM/th10_10.mp3");
    bgms[10] = LoadMusicStream("assets/BGM/th10_11.mp3");
    bgms[11] = LoadMusicStream("assets/BGM/th10_12.mp3");
    bgms[12] = LoadMusicStream("assets/BGM/th10_13.mp3");
    bgms[13] = LoadMusicStream("assets/BGM/th10_14.mp3");
    bgms[14] = LoadMusicStream("assets/BGM/th10_15.mp3");
    bgms[15] = LoadMusicStream("assets/BGM/th10_16.mp3");
    bgms[16] = LoadMusicStream("assets/BGM/th10_17.mp3");
    bgms[17] = LoadMusicStream("assets/BGM/th10_18.mp3");
    for(int i = 0; i < 17; i++){
        bgms[i].looping = true;
    }
    logStr("resources loaded\n", INFO);
}