#include "func.h"
#include "til.h"
#include "tilerr.h"
#include <string.h>
#include <stdlib.h>

char *parse_arg(char *arg_start){
    char *current = strlen(arg_start) + arg_start;
    while (*(current--) != ' ')if (current< arg_start)
    trigger_tilerr("no type for arg",3,"idk");
    current ++;
    *current = '\0';
    return current +1;
}

//parse an function
char *parse_func(char *dec_start,char *dec_end,struct til_context *context){
    char *current = dec_start;
    uint64_t name_len = 0;
    while (*(current++) != '('){
        if(current >= dec_end){
            trigger_tilerr("wrong function declaration",3,"idk");
            return dec_end;
        }
        name_len ++;
    }
    char *func_name = malloc(name_len + 1);
    memcpy(func_name,dec_start,name_len);
    func_name[name_len] = '\0';
    current = func_name + name_len;

    while (*(current--)!=' ')if (current<dec_start) 
    trigger_tilerr("no return type",3,"idk");
    current ++;

    *current = '\0';
    char *return_type = func_name;
    func_name = current + 1;
    
    //add the function to the context
    context->func_count ++;
    printf("size : %lu",context->func_count * sizeof(struct func *));
    context->functions = realloc(context->functions,(context->func_count * sizeof(struct func *)));
    struct func *curfunc = &(context->functions[context->func_count - 1]);
    curfunc->name = func_name;
    curfunc->return_type = return_type;
    curfunc->argc = 0;

    curfunc->argn = malloc(1);
    curfunc->argt = malloc(1);
    /*
    while (*(current++) != '(');
    char *arg_start = current;
    while (*((current++)-1) != ')'){/*
        if(*current == ',' || *current == ')'){
            current = '\0';
            curfunc->argc ++;
            curfunc->argn = realloc(curfunc->argn,sizeof(char *) * curfunc->argc);
            curfunc->argt = realloc(curfunc->argt,sizeof(char *) * curfunc->argc);
            curfunc->argn[curfunc->argc - 1] = parse_arg(arg_start);
            curfunc->argt[curfunc->argc - 1] = arg_start;
            arg_start = current + 1;
        }
    }*/
    

    return skip_object(dec_end);
}