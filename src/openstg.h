#ifndef OPENSTG_OPENSTG_H
#define OPENSTG_OPENSTG_H
#include <raylib.h>//master header

typedef unsigned char BYTE;//typedef
typedef unsigned short WORD;
typedef unsigned int DWORD;

extern Image PL00;//global var def
extern Image PL01;
extern Image BULLET[2];
extern Music bgms[17];

#include "danmaku.h"//header inc
#include "bullet.h"
#include "player.h"
#include "resman.h"
#include "stage.h"
#include "logger.h"



#endif
