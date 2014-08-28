class Priority implements Runnable {
    int cout;
    Thread thrd;
    static boolean stop = false;
    static String currentName;

    Priority(String name) {
        thrd = new Thread(this,name);
        count = 0;
        currentName = name;
    }

    public void run() {
        System.out.println(thrd.getName()+"starting.");
        do {
            count++;
            if (!currentName.
        }
    }
}
class PriorityDemo {
    public static void main(String args[]) {
    }
}
