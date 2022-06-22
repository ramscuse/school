#include <jni.h>
#include <stdio.h>
#include "JNIDemo.h"


JNIEXPORT jint JNICALL Java_JNIDemo_sum(JNIEnv * env, jclass j_class, jintArray j_arr){
    jint *arr = (*env)->GetIntArrayElements(env, j_arr, 0);
    jint size = (*env)->GetArrayLength(env, j_arr);

    printf("C: in sum method\n");
    jint sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}
