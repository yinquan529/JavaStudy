#include <jni.h>

int main() {
    JNIEnv *env;
    JavaVM *vm;
    JavaVMInitArgs vm_args;
    JavaVMOption options[1];
    jint res;
    jclass cls;
    jmethodID mid;
    jstring jstr;
    jclass stringClass;
    jobjectArray args;

    options[0].optionString = "-Djava.class.path=.";
    vm_args.version = JNI_VERSION_1_8;
    vm_args.options = options;
    vm_args.nOptions = 1;
    vm_args.ignoreUnrecognized = JNI_TRUE;

    res = JNI_CreateJavaVM(&vm, (void**)&env,&vm_args);
    cls = (*env)->FindClass(env, "InvocationApiTest");

    mid=(*env)->GetStaticMethodID(env,cls,"main","(Ljava/lang/String;)V");

    jstr = (*env)->NewStringUTF(env,"Hello Invocation API!!");
    stringClass = (*env)->FindClass(env,"java/lang/String");
    args = (*env)->NewObjectArray(env,1,stringClass,jstr);

    (*env)->CallStaticVoidMethod(env,cls,mid,args);

    (*vm)->DestroyJavaVM(vm);
}
