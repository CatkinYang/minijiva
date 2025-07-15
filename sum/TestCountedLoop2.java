public class TestCountedLoop2 {
    public int sum(int limit) {
        int ss = 0;
        for (int i = 0; i < limit; i++) {
            ss += i;
        }
        return ss;
    }

    int foo(int a, int b, int c) {
       int ret = bar(b, a);
       return ret + c;
    }

    int bar(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        TestCountedLoop2 t = new TestCountedLoop2();
        //for (int i = 0; i < 30; i++) {
            int ret = t.sum(1000);
        //    assert ret == 499500;
        //}
    }
}
