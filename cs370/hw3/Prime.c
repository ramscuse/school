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

#include "Prime.h"

int main (int argc, char* argv[]) {
    if (!(argc == 2 || argc == 3)) {
        printf("Prime[%d] : Not enough arguements for %s\n",getpid(),argv[0]);
        return -1;
    }

    int num = atoi(argv[1]);
    int res = Prime(num);

    if (argc == 3) {
        int SIZE = 32;
        int shmPrime_fd = shm_open(argv[2], O_RDWR, 0666);
        void *shmptrPrime = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shmPrime_fd,0);

        sprintf((char*)shmptrPrime,"%d",res);
        shm_unlink(argv[2]);
        return 0;
    }

    return res;
}

int Prime(int n) {
    if (n<=0) {
        printf("Prime[%d] : To use Prime, n must be greater than 0\n",getpid());
        return 0;
    }
    if (n==1) {
        printf("Prime[%d] : The first prime number is:\n2\n",getpid());
        return 2;
    }
    printf("Prime[%d] : The first %d prime numbers are:\n2",getpid(),n);
    int count = 3;
    int i = 2;
    while (i <= n) {
        int flag = 1;
        for (int j =2; j <= count-1; j++) {
            if (count%j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf(", %d", count);
            i++;
        }
        count++;
    }
    printf("\n");
    return count - 1;
}
