#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Total.h"

int main (int argc, char* argv[]) {
    if (argc != 2) {
	printf("Total[%d] : Not enough or too many arguements to run %s\n",getpid(),argv[0]);
	return 0;
    }
    int num = atoi(argv[1]);
    int res = Total(num);
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
