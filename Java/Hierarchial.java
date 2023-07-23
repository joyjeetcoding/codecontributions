class Animal {
    void eat() {
        System.out.println("Eating...");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Barking...");
    }
}

class Cat extends Animal {
    void meow() {
        System.out.println("Meow...");
    }
}

class Hierarchial {
    public static void main(String[] args) {
        Cat c = new Cat();
        Dog d = new Dog();
        c.meow();
        c.eat();
        d.eat();
    }
}