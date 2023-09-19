/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 16
// <Marcus Gutierrez> 
/////////////////////////

public class LabAssignment16 {
    private static int addition (int n)
    {
        if(n == 1)
        return 1;

        return n + addition(n - 1);
    }
public static void main(String []args) {

    int outcome1 = addition(10);
    System.out.println("The sum of numbers from 1 to 10 is " + outcome1);

    int outcome2 = addition(25);
    System.out.println("The sum of numbers from 1 to 25 is " + outcome2);

    int outcome3 = addition(100);
    System.out.println("The sum of numbers from 1 to 100 is " + outcome3);
}
}