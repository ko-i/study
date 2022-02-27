package arrayList;

import java.util.ArrayList;

public class ArrayListTest {

    public static void main(String[] args) {
        ArrayList<Employee> staff = new ArrayList<>();

        staff.add(new Employee("CC", 75000, 1987, 12, 15));
        staff.add(new Employee("BB", 50000, 1989, 10, 1));
        staff.add(new Employee("TT", 75000, 1987, 12, 15));

        for (Employee e: staff) {
            e.raiseSalary(5);
        }

        for (Employee e: staff) {
            System.out.println(e);
        }
    }
}
