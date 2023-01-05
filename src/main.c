#include <raylib.h>
#include <stdio.h>

#include "openstg.h"

int main(){
    SetTraceLogLevel(LOG_WARNING);
    logStr("Initializing openstg engine\n", INFO);
	InitWindow(640,480,"STG");
	SetTargetFPS(60);
    InitStage();
    StartStage();
	CloseWindow();
	return 0;
}