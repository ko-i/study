import com.carp.Employee;

import static java.lang.System.*;

public class PackageTest {
    
    public static void main(String[] args) {
        Employee e = new Employee("Carl Cracker", 75000, 1987, 12, 15);

        e.raiseSalary(5);

        System.out.println("name = " + e.getName() + ", salary = " + e.getSalary() + ", hireDay = " + e.getHireDay());

    }

}
