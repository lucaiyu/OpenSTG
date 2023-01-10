#include "openstg.h"

pointNode * phead;

void addPoint(point *pp) {
    if(phead == NULL){
        phead = (pointNode *) malloc(sizeof(pointNode));
        phead->current = pp;
        phead->next = NULL;
    } else{
        pointNode *cur = phead;
        while (cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = (pointNode *) malloc(sizeof(pointNode));
        cur->next->current = pp;
        cur->next->next = NULL;
    }
}

void deletep(point *pb){
    if(pb == NULL){
        return;
    }
    pointNode *cur = phead;
    while (cur!=NULL&&cur->next->next!=NULL){
        if(cur->next->current == pb){
            cur->next = cur->next->next;
            break;
        }
        cur=cur->next;
    }
}

void loopp() {
    pointNode *cur = phead;
    while (cur!=NULL){
        ptick(cur->current);
        cur=cur->next;
    }
}