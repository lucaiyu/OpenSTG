#include "openstg.h"

enemy * initenemy(short x, short y, unsigned char type, short health, short bonus, unsigned char*item_drop_array, void(*p[5])(void)){
    enemy *pe = (enemy*) malloc(sizeof(enemy));
    pe->x = x;
    pe->y = y;
    pe->type = type;
    pe->item_drop_array = item_drop_array;
    for(int i=0;i<5;i++){
        pe->p[i] = p[i];
    }
}