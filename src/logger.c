#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void initLogger(const char *file){
	return;
}
void logStr(char *log, int level){//e.g. Mon Aug 13 08:23:14 2012 [PANIC] could not alloc memory!
    char *slevel;
    switch (level) {
        case 1: {
            slevel = "[DEBUG] ";
            break;
        }
        case 2:{
            slevel = "[INFO] ";
            break;
        }
        case 3:{
            slevel = "[WARN] ";
            break;
        }
        case 4:{
            slevel = "[ERROR] ";
            break;
        }
        case 5:{
            slevel = "[PANIC] ";
            break;
        }
    }
    time_t curtime;
    char *scurtime;
    time(&curtime);
    scurtime = ctime(&curtime);
    char *tmp;
    tmp = strcat(scurtime, slevel);
    char *temp;
    temp = strcat(tmp, log);
    printf("%s", temp);
}
