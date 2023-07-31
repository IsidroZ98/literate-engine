/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Homework Assignment 01
// <Marcus Gutierrez> 
/////////////////////////
import java.text.DecimalFormat;
import java.util.Scanner;

public class HomeworkAssignment01Question1 {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numberOfDays;
            do {
                System.out.print("Enter the number of days worked (must be at least 1): ");
                numberOfDays = scanner.nextInt();
            } while (numberOfDays < 1);

            DecimalFormat dollarFormat = new DecimalFormat("$0.00");

            double salaryInPennies = 0.01; 
            double totalPayInPennies = 0;

            System.out.println("Day \t Salary (in pennies) \t Total Pay (in pennies)");

            for (int day = 1; day <= numberOfDays; day++) {
                totalPayInPennies += salaryInPennies;
                System.out.println(day + "\t" + dollarFormat.format(salaryInPennies) + "\t \t \t" + dollarFormat.format(totalPayInPennies));
                salaryInPennies *= 2; 
            }

            double totalPayInDollars = totalPayInPennies;
            System.out.println("Total Pay: " + dollarFormat.format(totalPayInDollars));
        }
    }
}
