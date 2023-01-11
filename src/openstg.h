#ifndef OPENSTG_OPENSTG_H
#define OPENSTG_OPENSTG_H
#include <raylib.h>//master header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>



#include "ui.h"//header inc
#include "point.h"
#include "pointhandle.h"
#include "bullet.h"
#include "bullethandle.h"
#include "player.h"
#include "resman.h"
#include "stage.h"
#include "logger.h"
#include "util.h"


typedef unsigned char BYTE;//typedef
typedef unsigned short WORD;
typedef unsigned int DWORD;

extern Image PL00;//global var def
extern Image PL01;
extern Image BULLET[4];
extern Music bgms[18];
extern unsigned long timer;//GLOBAL TIMER(TPS)
extern score *scoreIn;
extern Texture2D ui[2];
extern Texture2D bak[1];
extern Player *pplayer;
extern bulletNode *buhead;
extern pointNode * phead;


#endif
