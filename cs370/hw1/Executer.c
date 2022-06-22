#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Executer.h"

//int generator(int rand) {
//    return ((rand % (upper_bound - lower_bound) + lower_bound));
//}

float get_running_ratio() {
    float totalSumOfAverages = 0;
    int maxCount = 0; 
    int maxIteration = 0;

    int totalIterations = get_iteration_no(rand());
    printf("[Executor]: Number of iterations is %d\n", totalIterations);

    char* array;
    for (int i = 0; i < totalIterations; i++) {
        int size = get_arr_size(rand());
        array = malloc(sizeof(char) * size);
        for (int j =0; j < size; j++) {
            *(array + j) = get_arr_val(rand());
        }
        int maxCountCopy = maxCount;
        totalSumOfAverages += ratio(array, size, &maxCount);
        if (maxCount != maxCountCopy) {
            maxIteration = i + 1;
        }
        free(array);
    }

    printf("[Executor]: Iteration with maximum vowel count is %d\n", maxIteration);
    return totalSumOfAverages / (float) totalIterations;
}

int get_iteration_no(int rand) {
    return ((rand % (100 - 50) + 50));
}

int get_arr_size(int rand) {
    int size = ((rand % (150 - 100) + 100));
    return size;
}

char get_arr_val(int rand) {
    char letter = (char) ((rand % (91 - 65) + 65));
    return letter;
}

float ratio(char *arr, int size, int *maxCountPointer) {
    int count = 0;
    for (int i =0; i < size; i++) {
        char let = *(arr+i);
        if (let == 'A' || let == 'E' || let == 'I' || let == 'O' || let == 'U') {
            count += 1;
        }
    }
    if (count > *maxCountPointer) {
        *maxCountPointer = count;
    }
    float ratio = (float)count/(size-count);
    return ratio;
}
