#include <raylib.h>
#include <stdio.h>
#include "openstg.h"
Image PL00;
Image PL01;
Image BULLET[2];


//load texture into RAM
void ldtex(){
	logStr("Loading resources\n", INFO);
    PL00 = LoadImage("assets/TEX/player00.png");
    PL01 = LoadImage("assets/TEX/player01.png");
    BULLET[0] = LoadImage("assets/TEX/etama3.png");
    BULLET[1] = LoadImage("assets/TEX/etama4.png");
    logStr("resources loaded\n", INFO);
}