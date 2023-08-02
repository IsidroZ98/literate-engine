/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 04 Part 1
// <Marcus Gutierrez> 
/////////////////////////

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import java.util.Random;

public class PrimaryController {
    @FXML
    public Label playerChoiceLabel;
    @FXML
    public Label computerChoiceLabel;
    @FXML
    public Label resultLabel;

    @FXML
    public void initialize() {

    }

    @FXML
    public void onChoiceButtonClick(ActionEvent event) {
        int playerChoice = Integer.parseInt(((Button) event.getSource()).getId());
        Random random = new Random();
        int computerChoice = random.nextInt(3) + 1;


        playerChoiceLabel.setText(" Player's choice: \n" + getChoiceString(playerChoice));
        computerChoiceLabel.setText(" Computer's choice: \n" + getChoiceString(computerChoice));


        String result = "";
        if (playerChoice == computerChoice) {
            result = " It's a tie! GG's ";
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            result = " YOU WON! ";
        } else {
            result = " You lose! :( ";
        }
        resultLabel.setText(" Result: " + result);
    }

    public String getChoiceString(int choice) {
        switch (choice) {
            case 1:
                return " Rock";
            case 2:
                return " Paper";
            case 3:
                return " Scissors";
            default:
                return " DISQUALIFIED ";
        }
    }
}
