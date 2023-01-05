#ifndef OPENSTG_LOGGER_H
#define OPENSTG_LOGGER_H

enum LOG_LEVEL{
    DEBUG=1, INFO, WARN, ERROR, PANIC
};
void initLogger(const char *file);
void logStr(char *log, int level);

#endif
