import java.util.Scanner;

public class Retirement {
    
    
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);

        System.out.print("How much money do u need 2 retire? ");
        double goal = in.nextDouble();

        System.out.print("How much money will u contribute every year? ");
        double payment = in.nextDouble();

        System.out.print("Interest rate in %: ");
        double interestRate = in.nextDouble();

        double balance = 0;
        int years = 0;

        while (balance < goal) {
            balance += payment;
            balance += balance * interestRate / 100;
            years += 1;
        }

        System.out.println("u can retire in " + years + " years.");
        in.close();
    }
}
