#include <stdio.h>
#include <stdlib.h>
#include "til.h"

int main(int argc,char **argv){
    if(argc == 1){
        perror("not engouth args \n");
        return EXIT_FAILURE;
    }

    int ecode = EXIT_SUCCESS;

    FILE *file = fopen(argv[1],"r");
    if(file == NULL){
        perror("can't open file\n");
        ecode = EXIT_FAILURE;
        goto ex;
    }
    fseek(file,0,SEEK_END);
    unsigned long file_size = ftell(file);
    fseek(file,0,SEEK_SET);

    char *buffer = malloc(file_size);
    if(buffer == NULL){
        perror("out of memory\n");
        ecode = EXIT_FAILURE;
        goto closefd;
    }
    fread(buffer,file_size,1,file);

    tileval(buffer,0,NULL);

    freebuf:
    free(buffer);
    closefd:
    fclose(file);
    ex:
    return ecode;
}