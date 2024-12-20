#include "til.h"
#include "stdlib.h"

int tileval(char *code,int argc,char **argv){
    //fist let find the list of all function
    //and global object
    char *pointer = code;
    char *obj_start = pointer;
    while(*(pointer++)){
        if((*pointer) == ';'){
            /*process global object*/;
            obj_start = pointer + 1;
        }
        if((*pointer) == ')'){
            /*process function*/;
            obj_start = pointer + 1;
        }
        if((*pointer) == ' ' && obj_start == pointer)obj_start ++;
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
    current ++;
}