#include <raylib.h>
#include <stdio.h>
#include "openstg.h"
Image PL00;
Image PL01;
Image BULLET[4];
Image VOID;


//load texture into RAM
void ldtex(){
	logStr("Loading resources\n", INFO);
    PL00 = LoadImage("assets/pl00.png");
    PL01 = LoadImage("assets/pl01.png");
    VOID = LoadImage("assets/void.png");
    BULLET[0] = LoadImage("assets/etama.png");
    BULLET[1] = LoadImage("assets/etama2.png");
    BULLET[2] = LoadImage("assets/etama3.png");
    BULLET[3] = LoadImage("assets/etama6.png");
    logStr("resources loaded\n", INFO);
}