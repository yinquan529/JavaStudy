class MyThread implements Runnable {
    Thread thrd;

    MyThread(String name) {
        thrName = name;
    }

    public void run() {
        System.out.println(thrName + " starting.");

        try{
            for ( int count = 0; count < 10; count ++ ) {
                Thread.sleep(40);
                System.out.println("In " + thrName + ", count is " + count);
            }
        }
        catch(InterruptedException exc) {
            System.out.println(thrName + " interrupted.");
        }
        System.out.println(thrName +" terminating.");
    }
}

class UseThreads {
    public static void main(String args[]) {
        System.out.println("Main thread starting.");

        MyThread mt = new MyThread("Child #1");

        Thread newThrd = new Thread(mt);

        newThrd.start();

        for ( int i = 0; i < 50; i++) {
            System.out.print(".");

            try{
                Thread.sleep(100);
            }
            catch(InterruptedException exc) {
                System.out.println("Main thread interrupted.");
            }
        }

        System.out.println("Main thread ending.");
    }
}
