#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Starter.h"

int runProgram(char program[], char input[]) {
    int pid = fork();
    if (pid==0) {
        execlp(program,program,input,NULL);
    } else if (pid > 0) {
        printf("Stater[%d] : Forked with process ID %d.\n",getpid(),pid);
        int status;
        printf("Stater[%d] : Waiting for process ID %d.\n",getpid(),pid);
        wait(&status);
        int result = WEXITSTATUS(status);
        printf("Starter[%d] : Child process %d returned %d\n",getpid(), pid, result);
        return result;
    } else {
        printf("Starter[%d] : Their was a problem forking!", getpid());
        return 0;
    }
    return 1;
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Not enough or too many arguements!\n");
        return 0;
    }

    FILE *inputFile;
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Could not open %s\n",argv[1]);
        return 0;
    }
    printf("\n");
    char line[256];
    while(fgets(line, 256, inputFile)){
        int f = runProgram("./Fibb",line);
        int p = runProgram("./Prime",line);
        int t = runProgram("./Total",line);
        printf("Fibb: %d\nPrime: %d\nTotal: %d\n\n",f,p,t);
    }
    fclose(inputFile);
    return 0;
}