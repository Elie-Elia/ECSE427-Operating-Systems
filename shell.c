#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

int parseInput(char ui[]) {
    char tmp[200]; int a,b;
    char *words[100]; int w=0; // wordsIdx
    int wordscounter=0;
    for (int i=0;i<1000 && ui[i] != '\0';i++){
        if (ui[i] == ' '){
            wordscounter++;
        }
    }
    for(a=0; ui[a]==' ' && a<1000; a++); // skip white spaces
    while(ui[a] != '\0' && a<1000) {
        for(b=0; ui[a]!='\0' && ui[a]!=' ' && ui[a] != '\r' && ui[a]!='\n' && a<1000; a++, b++){
            tmp[b] = ui[a]; // extract a word
        }
        tmp[b] = '\0';
        words[w] = strdup(tmp);
        a++; w++;
    }
    return interpreter(words,wordscounter+1); // assumes: cmd switches args
}


int main() {
    char prompt[100] = {'$','\0'}; // prompts can be modified
    char userInput[1000]; // user's input stored here
    int errorCode = 0; // zero means no error, default


    printf("Welcome to the Elie Elia shell!\n");
    printf("Version 1.0 Created January 2020\n");
    while(1) { // 1 means true, infinite
        printf("%s",prompt);
        fgets(userInput, 999, stdin); // limit input to array size
        errorCode = parseInput(userInput);
        if (errorCode == -1) {
            printf("Bye!");
            exit(99);// ignore all other errors
        }
        if (errorCode == 1){
            printf("Unknown Command \n");
        }
    }
}