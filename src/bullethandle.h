#ifndef OPENSTG_BULLETHANDLE_H
#define OPENSTG_BULLETHANDLE_H



typedef struct bunode{
    bullet *current;
    struct bunode *next;
}bulletNode;


void addBullet(bullet *pb);
void deletebu(bullet *pb);
void loopbu();
#endif
