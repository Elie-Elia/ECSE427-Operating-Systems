#include <string.h>
#include <stdio.h>
#include "shell.h"
#include "shellmemory.h"
#include <stdlib.h>

int help(){
    printf("help                        Displays all commands \n");
    printf("quit                        Exits/terminates the shell with Bye! \n");
    printf("set VAR STRING              Assigns a value to shell memory \n");
    printf("print VAR                   Displays the STRING assigned to VAR \n");
    printf("run                         Executes the file \n");
    return 0;
}

int script(char *words[]) {
    int errCode = 0;
    char line[1000];
    FILE *p = fopen(words[1],"rt"); // the program is in a file
    if (p==NULL){
        printf("Script not found \n");
        return 0;
    }
    fgets(line,999,p);
    while(!feof(p)) {
        line[strlen(line) - 1] = '\0';
        strtok(line, "\r");
        errCode = parseInput(line); // which calls interpreter()
        if (errCode != 0) {
            fclose(p);
            if (errCode == -1) return 0;
            return errCode;
        }

        fgets(line,999,p);
    }
    fclose(p);
    return errCode;
}

int set(char* words[], int wordCount){
    char *val = (char*) malloc(sizeof(char) *1000);
    val[0] = '\0';
    int i=2;
    while (i < wordCount){
        strcat(val, " ");
        strcat(val,words[i]);
        i++;
    }
    return store(words[1],val+1);
}

int print(char *words[]){
    return display(words[1]);

}

int interpreter(char *words[], int wordCount) { // assumes: cmd switchs args
// assumes: words[0] is cmd

    int errCode = 0;
    if ((strcmp(words[0], "print")) == 0) errCode = print(words);
    else if ((strcmp(words[0], "run")) == 0) errCode = script(words);
    else if ((strcmp(words[0], "set")) == 0) errCode = set(words, wordCount);
    else if ((strcmp(words[0],"help")) == 0) {
        errCode = help();
    }
    else if ((strcmp(words[0],"quit"))==0) errCode = -1;
    else if (*words[0] == ' ' || *words[0] == '\n'  || *words[0] == '\0'){
        errCode=0;
        return errCode;
    }
    else {
        errCode=1;
    }
    return errCode;
}