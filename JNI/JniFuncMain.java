class JniTest {
    private int intField;

    public JniTest(int num) {
        intField = num;
        System.out.println("[Java] Invoke JniTest object's consruction: intField="+intField);
    }

    public int callByNative(int num) {
        System.out.println("[Java] JniTest object's callByNative("+num+") invoke");
        return num;
    }

    public void callTest() {
        System.out.println("[Java] JniTest object's callTest() method invoke: intField="+intField);
    }
}
public class JniFuncMain {
    private static int staticIntField = 300;

    static { System.load("/home/yinnotebook/work/JavaStudy/JNI/libjnifunc.so"); }

    public static native JniTest createJniObject();

    public static void main(String[] args) {
        System.out.println("[Java] createJniObject() invoke the locale method");
        JniTest jniObj = createJniObject();

        jniObj.callTest();
    }
}
