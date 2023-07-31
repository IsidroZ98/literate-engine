/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Homework Assignment 01
// <Marcus Gutierrez> 
/////////////////////////
import java.util.Random;
import java.util.Scanner;

public class HomeworkAssignment01Question3 {
    public static void main(String []args) {
        try (Scanner scanner = new Scanner(System.in)) 
        {
            Random random = new Random();

            int minNumber = 1;
            int maxNumber = random.nextInt(11) * 10 + 50;

            int maxTries = maxNumber / 10; 

            System.out.println("The minimum number can be as low as 1 or as high as 150. Depending on the random generated number set you receive.\n");
            System.out.println("Guess a number between " + minNumber + " and " + maxNumber);
            System.out.println("You have " + maxTries + " tries to guess the correct number.");

            int randomNumber = random.nextInt(maxNumber - minNumber + 1) + minNumber;
            int numberOfTries = 0;

            while (numberOfTries < maxTries) {
                System.out.print("Please enter your guess: ");
                int userGuess = scanner.nextInt();
                numberOfTries++;

                if (userGuess == randomNumber) {
                    System.out.println("Congratulations! You guessed the number correctly in " + numberOfTries + " tries.");
                    return;
                } else if (userGuess > randomNumber) {
                    System.out.println("Too high, try again.");
                } else {
                    System.out.println("Too low, try again.");
                }
            }

            System.out.println("You failed, the number was: " + randomNumber);
        }
    }
}
