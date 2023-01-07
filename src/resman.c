#include <raylib.h>
#include "openstg.h"
Image PL00;
Image PL01;
Image BULLET[2];
Music bgms[17];


//load texture into RAM
void ldtex(){
	logStr("Loading resources\n", INFO);
    PL00 = LoadImage("assets/TEX/player00.png");
    PL01 = LoadImage("assets/TEX/player01.png");
    BULLET[0] = LoadImage("assets/TEX/etama3.png");
    BULLET[1] = LoadImage("assets/TEX/etama4.png");
    bgms[0] = LoadMusicStream("assets/BGM/th06_01.wav");
    bgms[1] = LoadMusicStream("assets/BGM/th06_02.wav");
    bgms[2] = LoadMusicStream("assets/BGM/th06_03.wav");
    bgms[3] = LoadMusicStream("assets/BGM/th06_04.wav");
    bgms[4] = LoadMusicStream("assets/BGM/th06_05.wav");
    bgms[5] = LoadMusicStream("assets/BGM/th06_06.wav");
    bgms[6] = LoadMusicStream("assets/BGM/th06_07.wav");
    bgms[7] = LoadMusicStream("assets/BGM/th06_08.wav");
    bgms[8] = LoadMusicStream("assets/BGM/th06_09.wav");
    bgms[9] = LoadMusicStream("assets/BGM/th06_10.wav");
    bgms[10] = LoadMusicStream("assets/BGM/th06_11.wav");
    bgms[11] = LoadMusicStream("assets/BGM/th06_12.wav");
    bgms[12] = LoadMusicStream("assets/BGM/th06_13.wav");
    bgms[13] = LoadMusicStream("assets/BGM/th06_14.wav");
    bgms[14] = LoadMusicStream("assets/BGM/th06_15.wav");
    bgms[15] = LoadMusicStream("assets/BGM/th06_16.wav");
    bgms[16] = LoadMusicStream("assets/BGM/th06_17.wav");
    for(int i = 0; i < 17; i++){
        bgms[i].looping = true;
    }
    logStr("resources loaded\n", INFO);
}