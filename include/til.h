#pragma once

//execute til code with the parameter ... 
//@return the exit code of the til code
int tileval(char *code,int argc,char **argv);

char *skip_object(char *start);
#define find_char()