#include "tilerr.h"
static void (*callback_func)(const char*,unsigned long,const char *);
void set_tilerr_callback(void (*callback)(const char*,unsigned long,const char *)){
    callback_func = callback;
}
void trigger_tilerr(const char* error,unsigned long line,const char *file){
    callback_func(error,line,file);
}