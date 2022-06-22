#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int * myArray = (int*) malloc(200 * sizeof(int));
	int * myPointer = malloc(sizeof(int));
	*myPointer = 20;
	free(myArray);
	free(myPointer);
	return 0;
}
