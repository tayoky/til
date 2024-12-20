#include "til.h"
#include "stdlib.h"
#include "func.h"
#include <stdio.h>

void init_context(struct til_context *context){
    context->func_count = 0;
    context->functions = malloc(sizeof(struct func *));
    context->version = 1;
}

int tileval(char *code,int argc,char **argv){
    //fist let find the list of all function
    //and global object

    struct til_context context;
    init_context(&context);

    char *pointer = code;
    char *obj_start = pointer;
    while(*(pointer++)){
        if((*pointer) == ';'){
            /*process global object*/;
            obj_start = pointer + 1;
        }
        if((*pointer) == ')'){
            /*process function*/;
            pointer = parse_func(obj_start,pointer,&context);
            obj_start = pointer + 1;
        }
        if(((*pointer) == ' ' || (*pointer) == '\n') && obj_start == pointer)obj_start ++;
    }
}

char *skip_object(char *start){
    //first find the { and after skip unttil }
    //if find { skip recusively using this function
    char *current = start;
    while ((*current) != '{'){
       current++;
       if(!(*current))return NULL;
    }

    while ((*current) != '}'){
       current++;
       if(!(*current))return NULL;
       if(*(current) == '{') current = skip_object(current);
    }
    current ++;return current;
}
