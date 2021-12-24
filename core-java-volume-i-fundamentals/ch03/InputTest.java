import java.util.Scanner;

public class InputTest {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("What's ur name? ");
        String name = in.nextLine();

        System.out.print("How old r u? ");
        int age = in.nextInt();

        System.out.println("Hello " + name +". Next year, u'll b " + (age + 1));

        in.close();
    }
}
