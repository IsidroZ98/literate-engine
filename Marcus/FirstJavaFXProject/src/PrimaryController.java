import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import java.util.Random;

public class PrimaryController {
    @FXML
    private Label playerChoiceLabel;
    @FXML
    private Label computerChoiceLabel;
    @FXML
    private Label resultLabel;

    @FXML
    private void initialize() {

    }

    @FXML
    private void onChoiceButtonClick(ActionEvent event) {
        int playerChoice = Integer.parseInt(((Button) event.getSource()).getId());
        Random random = new Random();
        int computerChoice = random.nextInt(3) + 1;


        playerChoiceLabel.setText("Player's choice: " + getChoiceString(playerChoice));
        computerChoiceLabel.setText("Computer's choice: " + getChoiceString(computerChoice));


        String result = "";
        if (playerChoice == computerChoice) {
            result = "It's a tie!";
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            result = "You won!";
        } else {
            result = "You lose!";
        }
        resultLabel.setText("Result: " + result);
    }

    private String getChoiceString(int choice) {
        switch (choice) {
            case 1:
                return "Rock";
            case 2:
                return "Paper";
            case 3:
                return "Scissors";
            default:
                return "DISQUALIFIED, YOU DID NOT INPUT 1, 2, OR 3.";
        }
    }
}
