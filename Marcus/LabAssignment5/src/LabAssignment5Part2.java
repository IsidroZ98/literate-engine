import java.util.Random;

public class LabAssignment5Part2 {
    public static void main(String[] args) {
        char[][] gameBoard = new char[5][5];
        int totalSpaces = gameBoard.length * gameBoard[0].length;
        int remainingSpaces = totalSpaces;
        int x = 2;
        int y = 0;

        for (int i = 0; i < gameBoard.length; i++) {
            for (int j = 0; j < gameBoard[i].length; j++) {
                gameBoard[i][j] = '*';
            }
        }

        gameBoard[x][y] = '@';

        Random random = new Random();

        while (remainingSpaces > (totalSpaces / 2)) {
            for (int i = 0; i < gameBoard.length; i++) {
                for (int j = 0; j < gameBoard[i].length; j++) {
                    System.out.print(gameBoard[i][j] + " ");
                }
                System.out.println();
            }
            System.out.println();

            int direction = random.nextInt(4); 

            gameBoard[x][y] = ' ';

            switch (direction) {
                case 0: // Move up
                    if (x > 0) {
                        x--;
                    }
                    break;
                case 1:
                    if (x < gameBoard.length - 1) {
                        x++;
                    }
                    break;
                case 2: 
                    if (y > 0) {
                        y--;
                    }
                    break;
                case 3: 
                    if (y < gameBoard[0].length - 1) {
                        y++;
                    }
                    break;
            }
            gameBoard[x][y] = '@';

            remainingSpaces--;

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
