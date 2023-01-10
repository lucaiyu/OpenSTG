#ifndef OPENSTG_POINTHANDLE_H
#define OPENSTG_POINTHANDLE_H

typedef struct pnode{
    point *current;
    struct pnode *next;
}pointNode;

void addPoint(point *pp);
void deletep(point *pb);
void loopp();

#endif
