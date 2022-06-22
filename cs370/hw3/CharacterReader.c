#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main (int argc, char* argv[]) {
    if (!(argc == 2 || argc == 3)) {
        printf("Not enough or too many arguements!\n");
        return -1;
    }

    FILE *inputFile;    
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Could not open %s\n",argv[1]);
        return -1;
    }
    int sum = 0;
    char line[256];
    while(fgets(line, 256, inputFile)) {
        int num = atoi(line);
        sum += num;
    }
    fclose(inputFile);

    if(argc == 3) {
        char number[20];
        sprintf(number, "%d", sum);
        int fdw = atoi(argv[2]);
        write(fdw, number, strlen(number)+1);
    }
    
    return sum;
}
