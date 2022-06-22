#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Executer.h"

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Not enough or too many arguements!\n");
        return 0;
    }
    
    char* source = argv[0];
    int seed = atoi(argv[1]);

    srand(seed);
    printf("[Starter]: With seed: %d\n",seed);
    
    double running_ratio = (double)get_running_ratio();
    printf("[Starter]: Running ratio: %f\n", running_ratio);

    return 0;
}