#include "helloworld.h"
#include <stdio.h>


JNIEXPORT void JNICALL Java_helloworld_printHello (JNIEnv *env, jobject obj) {
    printf("Hello World!\n");
    return;
}


JNIEXPORT void JNICALL Java_helloworld_printString (JNIEnv *env, jobject obj, jstring string) {
    const char *str = (*env)->GetStringUTFChars(env,string,0);
    printf("%s!\n",str);

    return;
}
