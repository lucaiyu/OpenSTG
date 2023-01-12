#ifndef OPENSTG_OPENSTG_H
#define OPENSTG_OPENSTG_H
#include <raylib.h>//master header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>



typedef unsigned char BYTE;//typedef
typedef unsigned short WORD;
typedef unsigned int DWORD;

#include "ui.h"//header inc
#include "point.h"
#include "pointhandle.h"
#include "bullet.h"
#include "bullethandle.h"
#include "player.h"
#include "enemy.h"
#include "resman.h"
#include "stage.h"
#include "logger.h"
#include "util.h"

#include "test/std01.h"


extern Image PL00;//global var def
extern Image PL01;
extern Image BULLET[4];
extern Music bgms[18];
extern score *scoreIn;
extern Texture2D ui[2];
extern Texture2D bak[1];
extern Texture2D title[1];
extern Texture2D ENEMY;
extern unsigned long timer;
extern Player *pplayer;
extern bulletNode *buhead;
extern pointNode *phead;


#endif
