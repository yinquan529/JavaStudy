class helloworld {

    native void printHello();
    native void printString(String str);

    static { System.load("/home/yinnotebook/work/JavaStudy/JNI/libhelloworld.so"); }

    public static void main(String args[]) {
        helloworld myJNI = new helloworld();

        myJNI.printHello();
        myJNI.printString("Hello World from printString fun");
    }
}
