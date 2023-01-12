#include <raylib.h>

#include "openstg.h"

int main(){
    SetTraceLogLevel(LOG_WARNING);
    logStr("Initializing openstg engine\n", INFO);
    InitAudioDevice();
	InitWindow(640,480,"STG");
	SetTargetFPS(60);
    StartStage();
	CloseWindow();
    CloseAudioDevice();
	return 0;
}