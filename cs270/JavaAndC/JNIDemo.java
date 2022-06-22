public class JNIDemo{

    static { 
        System.loadLibrary("sum");
    }

    private static native int sum(int[] x);

    private static native void link();

    private static void print(String s){
        System.out.println("Java: received message: " + s);
    }

    public static void main(String[] args){
        int x[] = {1, 2, 3, 4};

        System.out.println("Java: sum() returned: " + sum(x));

        link();
    }
}
