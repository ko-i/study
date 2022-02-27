package interfaces;

import java.util.Arrays;

public class EmployeeSortTest {
    
    public static void main(String[] args) {
        
        Employee[] staff = new Employee[3];

        staff[0] = new Employee("CC", 75000, 1987, 12, 15);
        staff[1] = new Employee("BB", 50000, 1989, 10, 1);
        staff[2] = new Employee("TT", 75000, 1987, 12, 15);

        Arrays.sort(staff);

        for (Employee e: staff) {
            System.out.println("name=" + e.getName() + ", salary=" + e.getSalary());
        }
    }
}
