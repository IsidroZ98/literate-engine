import java.io.*;

public class LabAssignment08 {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter writer = new PrintWriter(new FileWriter("credentials.txt"));

            while (true) {
                System.out.println("Program start. ");
                System.out.print("Username: (or 'exit' to stop): ");
                String username = reader.readLine();
                
                if (username.equalsIgnoreCase("exit")) {
                    break;
                }
                
                System.out.print("Password: ");
                String password = reader.readLine();
                
                writer.println(username + "\t" + password);
                writer.flush();
                
                System.out.print("Do you want to input another username and password? (Y/N): ");
                String input = reader.readLine();
                if (input.equalsIgnoreCase("N")) {
                    break;
                }
            }
            writer.close();

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
