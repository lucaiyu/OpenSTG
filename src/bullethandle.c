#include "openstg.h"


bulletNode *buhead;

void addBullet(bullet *pb) {
    if(buhead == NULL){
        buhead = (bulletNode*) malloc(sizeof(bulletNode));
        buhead->current = pb;
        buhead->next = NULL;
    } else{
        bulletNode *cur = buhead;
        while (cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = (bulletNode*) malloc(sizeof(bulletNode));
        cur->next->current = pb;
        cur->next->next = NULL;
    }
}

void deletebu(bullet *pb){
    /*
    if(pb == NULL){
        return;
    }
    bulletNode *cur = buhead;
    while (cur!=NULL&&cur->next->next!=NULL){
        if(cur->next->current == pb){
            cur->next = cur->next->next;
            break;
        }
        cur=cur->next;
    }
     */
    return;
}

void loopbu() {
    bulletNode *cur = buhead;
    while (cur!=NULL){
        butick(cur->current);
        cur=cur->next;
    }
}