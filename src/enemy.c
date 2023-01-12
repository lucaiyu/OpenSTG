#include "openstg.h"

enemy* initenemy(short x, short y, unsigned char type, short health, short bonus, unsigned char*item_drop_array, void(*p[5])()){
    enemy *pe = (enemy*) malloc(sizeof(enemy));
    if(pe == NULL){
        logStr("could not alloc memory!", PANIC);
        exit(-1);
    }
    pe->x = x;
    pe->y = y;
    pe->type = type;
    pe->frame = 1;
    pe->item_drop_array = item_drop_array;
    //for(int i=0;i<5;i++){
        //pe->p[i] = p[i];
    //}

    if(pe->type<=4){
        pe->src = (Rectangle){0, pe->type*32-32, 32, 32};
        return pe;
    }
    if(pe->type>4&&pe->type<=8){
        pe->src = (Rectangle){0, pe->type*32-32+256, 32, 32};
        return pe;
    }
    if(pe->type==9){
        pe->src = (Rectangle){0, 384, 64, 64};
        return pe;
    }
    return pe;
}

static void render(enemy *pe){
    DrawTextureRec(ENEMY, pe->src, (Vector2){pe->x, pe->y}, WHITE);
}

static void testmove(enemy *pe){
    /*
    static _Bool direction = false;
    if(direction){
        pe->x-=5;
        if(pe->x<100){
            direction =  false;
        }
    }
    if(!direction){
        pe->x+=5;
        if(pe->x>300){
            direction =  true;
        }
    }
     */
    if(timer%60==0){
        bullet *bu = InitBullet(pe->x+8, pe->y+32, 0, 1, 0, 0, &BULLET[0], (Rectangle){96, 48, 16, 16}, 0);
        if(bu == NULL){
            return;
        }
        addBullet(bu);
    }
}

static void anm(enemy *pe){
    if(pe->frame>12){
        pe->frame=1;
    }
    pe->src = (Rectangle){pe->frame*32-32, pe->type*32-32, 32, 32};
}

void tickene(enemy *pe){
    anm(pe);
    testmove(pe);
    render(pe);
}