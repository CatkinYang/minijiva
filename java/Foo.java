class Bar{
    int bar(int a, int b) {
        return a + b;
    }
}

public class Foo {
    public int split(int a, int b) {
        int ret = 0;
        if (a>b) ret =a;
        else ret = b;
        return ret;
    }

    int foo(int a, int b, int c) {
        Bar aBar = new Bar();
        int ret = aBar.bar(b, a);
        return ret + c;
    }


    public static void main(String[] args) {
        Foo f = new Foo();
        //for (int i = 0; i < 30; i++) {
            int ret = f.split(5, 8);
        //    assert ret == 8;
        //}
    }
}
