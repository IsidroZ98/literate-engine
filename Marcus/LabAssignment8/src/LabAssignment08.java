/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 08
// <Marcus Gutierrez> 
/////////////////////////
import java.io.*;
import java.util.Scanner;

public class LabAssignment08 {
    public static void main(String[] args) {
        try {
            try (Scanner scanner = new Scanner(System.in)) {
                PrintWriter writer = new PrintWriter(new FileWriter("credentials.txt"));

                while (true) {
                    System.out.println("Program start. ");
                    System.out.print("\nUsername: ");
                    String username = scanner.nextLine();

                    System.out.print("Password: ");
                    String password = scanner.nextLine();

                    writer.println(username + "\t" + password);
                    writer.flush();

                    System.out.print("Do you want to input another username and password? (Y/N): ");
                    String input = scanner.nextLine();
                    if (input.equalsIgnoreCase("N")) {
                        break;
                    }
                }

                writer.close();
            }
            BufferedReader fileReader = new BufferedReader(new FileReader("credentials.txt"));
            String line;
            System.out.println("List of usernames and passwords: \n");
            while ((line = fileReader.readLine()) != null) {
                String[] credentials = line.split("\t");
                System.out.println("Username: " + credentials[0] + "         Password: " + credentials[1]);
            }
            fileReader.close();
            System.out.println("\nProgram end.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

