#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MEM {
    char *var;
    char *value;
}mem;

mem memory[1000];

int store(char *variable, char *value){

    for (int i=0;i<1000;i++) {
        if (memory[i].var == NULL) {
            memory[i].var = strdup(variable);
            memory[i].value = strdup(value);
            return 0;
        }
        if (strcmp(memory[i].var,variable) == 0){
            memory[i].value=strdup(value);
            return 0;
        }
    }
}

int display(char *variable){
    for (int i=0;i<1000;i++){
        if (memory[i].var==NULL){
            printf("Variable does not exist \n");
            return 0;
        }
        if (strcmp(memory[i].var,variable)==0){
            printf("%s \n",memory[i].value);
            return 0;
        }
    }

}
