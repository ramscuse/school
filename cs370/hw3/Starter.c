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

#include "Starter.h"

int runProgram(char program[], char input[], char name[]) {
    int pid = fork();
    if (pid==0) {
        execlp(program,program,input,name,NULL);
    } else if (pid > 0) {
        int status;
        wait(&status);
        int result = WEXITSTATUS(status);
        return result;
    } else {
        printf("Starter[%d] : Their was a problem forking!", getpid());
        return 0;
    }
    return 1;
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Starter[%d] : Not enough or too many arguements!\n",getpid());
        return 1;
    }

    char input[16];

    int fd[2];
    if (pipe(fd) != 0) {
        printf("Starter[%d] : Error when using pipe\n",getpid());
        return 2;
    }

    int pid = fork();
    if (pid == -1) {
        printf("Starter[%d] : Their was a problem forking!", getpid());
        return 3;
    } else if(pid == 0) {
        close(fd[0]);
        char passwrite[20];
        sprintf(passwrite, "%d", fd[1]);
        execlp("./CharacterReader", "./CharacterReader", argv[1], passwrite, NULL);
        close(fd[1]);
        return 0;
    } else {
        close(fd[1]);
        int status;
        wait(&status);
        int result = WEXITSTATUS(status);
        if (result == -1) {
            return 4;
        }        
        read(fd[0], input, sizeof(input));
        printf("Starter[%d] : Contents read from the read end pipe: %s\n", getpid(), input);
        close(fd[0]);
    }

    char shm_nameFibb[] = "SharedMemFibb"; char shm_namePrime[] = "SharedMemPrime"; char shm_nameTotal[] = "SharedMemTotal";

    int shmFibb_fd = shm_open(shm_nameFibb, O_CREAT | O_RDWR, 0666);
    int shmPrime_fd = shm_open(shm_namePrime, O_CREAT | O_RDWR, 0666);
    int shmTotal_fd = shm_open(shm_nameTotal, O_CREAT | O_RDWR, 0666);

    int SIZE = 32;
    ftruncate(shmFibb_fd,SIZE);
    ftruncate(shmPrime_fd,SIZE);
    ftruncate(shmTotal_fd,SIZE);

    char *shmptrFibb = (char*) mmap(0,SIZE,PROT_READ,MAP_SHARED,shmFibb_fd,0);
    printf("Starter[%d] : Created shared memory \"%s\" with FD: %d\n",getpid(),shm_nameFibb,shmFibb_fd);
    char *shmptrPrime = (char*) mmap(0,SIZE,PROT_READ,MAP_SHARED,shmPrime_fd,0);
    printf("Starter[%d] : Created shared memory \"%s\" with FD: %d\n",getpid(),shm_namePrime,shmPrime_fd);
    char *shmptrTotal = (char*) mmap(0,SIZE,PROT_READ,MAP_SHARED,shmTotal_fd,0);
    printf("Starter[%d] : Created shared memory \"%s\" with FD: %d\n",getpid(),shm_nameTotal,shmTotal_fd);

    int f = runProgram("./Fibb",input,shm_nameFibb);
    int p = runProgram("./Prime",input,shm_namePrime);
    int t = runProgram("./Total",input,shm_nameTotal);

    printf("Starter[%d] : Fibb last number: %s\n",getpid(),shmptrFibb);
    printf("Starter[%d] : Prime last number: %s\n",getpid(),shmptrPrime);
    printf("Starter[%d] : Total last number: %s\n\n",getpid(),shmptrTotal);

    return 0;
}
