#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Fibb.h"

int main (int argc, char* argv[]) {
    //printf("this:%d parent:%d\n",getpid(),getppid());
    if (argc != 2) {
	    printf("Fibb[%d] : Not enough or too many arguements to run %s\n",getpid(),argv[0]);
	    return 0;
    }
    int input = atoi(argv[1]);
    printf("Fibb[%d] : The number of terms in fibonacii sequence are %d\n",getpid(),input);
    int res = Fibb(input);
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
