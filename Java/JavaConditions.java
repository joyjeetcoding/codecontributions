import java.util.Scanner;

public class JavaConditions {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int age;
        age = sc.nextInt();

        if(age >= 18) {
            System.out.println("Eligible to vote");
        }

        else
        {
            System.out.println("Not Eligible");
        }
    }
}