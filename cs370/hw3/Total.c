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

#include "Total.h"

int main (int argc, char* argv[]) {
    if (!(argc == 2 || argc == 3)) {
        printf("Total[%d] : Not enough arguements for %s\n",getpid(),argv[0]);
        return -1;
    }

    int num = atoi(argv[1]);
    int res = Total(num);

    if (argc == 3) {
        int SIZE = 32;
        int shmTotal_fd = shm_open(argv[2], O_RDWR, 0666);
        void *shmptrTotal = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shmTotal_fd,0);

        sprintf((char*)shmptrTotal,"%d",res);
        shm_unlink(argv[2]);
        return 0;
    }

    return res;
}

int Total(int n) {
    if (n<=0) {
        printf("Sum[%d] : To use Sum, n must be greater than 0\n",getpid());
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Total[%d] : Sum = %d\n",getpid(),sum);
    return sum;
}
