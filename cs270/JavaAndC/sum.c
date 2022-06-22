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

JNIEXPORT void JNICALL Java_JNIDemo_link(JNIEnv * env, jobject class){
    printf("C: accessing callback method\n");
    jmethodID j_print = (*env)->GetStaticMethodID(env, class, "print", "(Ljava/lang/String;)V");

    jstring j_string = (*env)->NewStringUTF(env, "Hello from C");

    (*env)->CallStaticVoidMethod(env, class, j_print, j_string);
}
