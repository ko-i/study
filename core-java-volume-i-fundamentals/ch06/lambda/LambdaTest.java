package lambda;

import java.util.Arrays;
import java.util.Date;

import javax.swing.JOptionPane;
import javax.swing.Timer;

public class LambdaTest {

    public static void main(String[] args) {
        
        String[] planets = new String[] {
            "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"
        };

        System.out.println(Arrays.toString(planets));

        System.out.println("Sorted in dictionary order:");
        Arrays.sort(planets);
        System.out.println(Arrays.toString(planets));

        System.out.println("Sorted by length:");
        Arrays.sort(planets, (a, b) -> a.length() - b.length());
        System.out.println(Arrays.toString(planets));

        Timer t = new Timer(3000, event -> System.out.println("The time is " + new Date()));
        t.start();

        JOptionPane.showMessageDialog(null, "Quit program?");

        System.exit(0);
    }
    
}
