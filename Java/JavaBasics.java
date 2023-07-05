import java.util.Scanner;

public class JavaBasics {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); //Take user input
        System.out.println("Enter Username: ");

        String userName = sc.nextLine();  //Reads user input
        System.out.println("Username is: " + userName);

        Scanner myobj = new Scanner(System.in);
        System.out.println("Enter Age: ");
        
        int age = myobj.nextInt();

        System.out.println("Age is "+age);
    }
}