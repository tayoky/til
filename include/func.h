#pragma once
#include "stdint.h"
struct func{
    char *name;
    char *return_type;
    uint64_t argc;
    char **argn;
    char **argt;
    char *pointer;
};
#include "til.h"
char *parse_func(char *dec_start,char *dec_end,struct til_context *context);