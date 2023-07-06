class Person {
    String name;
    int age;

    void walk(int steps)
    {
        System.out.println(name + " is walked " + steps);
    }
}

public class hello {
    public static void main(String[] args) {
        Person p1 = new Person();
        p1.age = 24;
        p1.name = "Joy";

        System.out.println(p1.age + " " + p1.name);
        p1.walk(7);
    }
}

