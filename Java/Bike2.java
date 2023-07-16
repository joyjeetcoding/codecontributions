// Runtime Polymorphism

class vehicle {
    void run()
    {
        System.out.println("Vehicle is running");
    }
}

class Bike2 extends vehicle {
    void run()
    {
        System.out.println("Bike is running");
    }

    public static void main(String[] args) {
        Bike2 obj = new Bike2();
        obj.run();
    }
}