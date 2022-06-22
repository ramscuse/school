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

#include "Fibb.h"

int main (int argc, char* argv[]) {
    if (!(argc == 2 || argc == 3)) {
        printf("Fibb[%d] : Not enough arguements for %s\n",getpid(),argv[0]);
        return -1;
    }

    int input = atoi(argv[1]);
    int res = Fibb(input);

    if (argc == 3) {
        int SIZE = 32;
        int shmFibb_fd = shm_open(argv[2], O_RDWR, 0666);
        void *shmptrFibb = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shmFibb_fd,0);

        sprintf((char*)shmptrFibb,"%d",res);
        shm_unlink(argv[2]);
        return 0;
    }

    return res;
}

int Fibb(int n) {
    if (n<=0) {
        printf("Fibb[%d] : To use Fibb, n must be greater than 0\n",getpid());
        return 0;
    }
    if (n==1) {
        printf("Fibb[%d] : The first number of the Fibonacci Series is:\n0\n",getpid());
        return 0;
    }
    if (n==2) {
        printf("Fibb[%d] : The first 2 numbers of the Fibonacci Series are:\n0, 1\n",getpid());
        return 1;
    }
    printf("Fibb[%d] : The first %d numbers of the Fibonacci sequence are:\n", getpid(), n);
    int n1 = 0;
    int n2 = 1;
    printf("0, 1");
    for (int i = 2; i < n; i++) {
        int n3 = n1 + n2;
        printf(", %d", n3);
        n1 = n2;
        n2 = n3;
    }
    printf("\n");
    return n2;
}
