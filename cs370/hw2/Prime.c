#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Prime.h"

int main (int argc, char* argv[]) {
    if (argc != 2) {
	printf("Prime[%d] : Not enough arguements for %s\n",getpid(),argv[0]);
	return 0;
    }
    int num = atoi(argv[1]);
    int res = Prime(num);
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
