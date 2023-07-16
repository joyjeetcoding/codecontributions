// Method overloading

class helper {
    static int multiply(int a, int b) {
        return a * b;
    }

    static int multiply(int a, int b, int c) {
        return a * b * c;
    }
}

public class GFG {
    public static void main(String[] args) {
        System.out.println(helper.multiply(2, 4));
        System.out.println(helper.multiply(2, 7, 3));
    }
}

