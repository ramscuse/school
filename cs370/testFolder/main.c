#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[]) {
    int id = fork();
    int id2;
    if (id !=0) 
        id2 = fork();
    printf("%d %d\n",id,getppid());
    printf("%d %d\n",id2,getppid());
}