#pragma once
struct til_context;
#include"func.h"

//execute til code with the parameter ... 
//@return the exit code of the til code
int tileval(char *code,int argc,char **argv);

char *skip_object(char *start);
#define find_char()
struct til_context{
    uint64_t func_count;
    struct func *functions;
    uint64_t version;
};