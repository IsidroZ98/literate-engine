import java.util.Scanner; 

public class BearClaw {
    public static void main(String []args) {
        try (Scanner input = new Scanner(System.in)) {
            int test = 0; 
            if (test == 5) {
                System.out.println("Yes the numbers are the same");
            } else {
                System.out.println("The numbers are not the same so print any number you think of and type it here: "); 
                String userInp = input.nextLine();
                System.out.println("you really chose, " + userInp + , "as your number ?"); 
            }
        }
    }
}