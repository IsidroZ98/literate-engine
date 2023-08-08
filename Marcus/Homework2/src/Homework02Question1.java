/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Homework Assignment 02
// <Marcus Gutierrez> 
/////////////////////////
import java.io.*;
import java.util.*;

public class Homework02Question1 {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int grammarPoints, spellingPoints, lengthPoints, contentPoints;

            do {
                System.out.print("Enter points for Grammar (1-100): ");
                grammarPoints = scanner.nextInt();
                System.out.print("Enter points for Spelling (1-100): ");
                spellingPoints = scanner.nextInt();
                System.out.print("Enter points for Correct length (1-100): ");
                lengthPoints = scanner.nextInt();
                System.out.print("Enter points for Content (1-100): ");
                contentPoints = scanner.nextInt();
            } while (grammarPoints + spellingPoints + lengthPoints + contentPoints != 100);

            Essay essay = new Essay(grammarPoints, spellingPoints, lengthPoints, contentPoints);
            essay.calculateScore();
            essay.generateRandomPoints();

            try {
                PrintWriter writer = new PrintWriter("essay_scores.txt");
                writer.println("Grammar Points: " + grammarPoints);
                writer.println("Spelling Points: " + spellingPoints);
                writer.println("Correct Length Points: " + lengthPoints);
                writer.println("Content Points: " + contentPoints);
                writer.println("Total Score: " + essay.getScore());
                writer.println("Letter Grade: " + essay.getGrade());
                writer.close();
                System.out.println("Essay scores saved to 'essay_scores.txt'.");

                Scanner reader = new Scanner(new File("essay_scores.txt"));
                while (reader.hasNextLine()) {
                    System.out.println(reader.nextLine());
                }
                reader.close();
            } catch (IOException e) {

            }
        }
    }
}

class Essay extends GradedActivity {
    private int grammarPoints;
    private int spellingPoints;
    private int lengthPoints;
    private int contentPoints;

    public Essay(int grammarPoints, int spellingPoints, int lengthPoints, int contentPoints) {
        this.grammarPoints = grammarPoints;
        this.spellingPoints = spellingPoints;
        this.lengthPoints = lengthPoints;
        this.contentPoints = contentPoints;
    }

    public void calculateScore() {
        double total = grammarPoints + spellingPoints + lengthPoints + contentPoints;
        super.setScore(total);
    }

    public void generateRandomPoints() {
        java.util.Random random = new java.util.Random();
        int randomGrammar = random.nextInt(grammarPoints + 1);
        int randomSpelling = random.nextInt(spellingPoints + 1);
        int randomLength = random.nextInt(lengthPoints + 1);
        int randomContent = random.nextInt(contentPoints + 1);

        System.out.println("Random Grammar Points: " + randomGrammar);
        System.out.println("Random Spelling Points: " + randomSpelling);
        System.out.println("Random Correct Length Points: " + randomLength);
        System.out.println("Random Content Points: " + randomContent);

        double total = randomGrammar + randomSpelling + randomLength + randomContent;
        super.setScore(total);
    }
}