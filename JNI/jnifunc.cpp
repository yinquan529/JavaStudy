#include "JniFuncMain.h"

JNIEXPORT jobject JNICALL Java_JniFuncMain_createJniObject(JNIEnv *env, jclass clazz) {
    jclass targetClass;
    jmethodID mid;
    jobject newObject;
    jstring hellstr;
    jfieldID fid;
    jint staticIntField;
    jint result;

    fid = env->GetStaticFieldID(clazz, "staticIntField","I");
    staticIntField = env->GetStaticIntField(clazz,fid);
    printf("[CPP] get JniFuncMain class's staticfield value\n");
    printf("JniFuncMain.staticIntField = %d\n",staticIntField);

    targetClass = env->FindClass("JniTest");

    mid = env->GetMethodID(targetClass, "<init>","(I)V");

    printf("[CPP] JniTeset object generate\n");

    newObject = env->NewObject(targetClass, mid,100);

    mid = env->GetMethodID(targetClass, "callByNative","(I)I");
    result = env->CallIntMethod(newObject,mid,200);

    fid = env->GetFieldID(targetClass, "intField","I");
    printf("[CPP] set JniTest obect's intField value is 200\n");
    env->SetIntField(newObject,fid,result);

    return newObject;
}
