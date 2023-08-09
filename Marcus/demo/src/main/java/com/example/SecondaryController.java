package com.example;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class SecondaryController {

    @FXML
    private Label nameLabel;
    @FXML
    private Label foodLabel;
    @FXML
    private Label mediaLabel;
    @FXML
    private Button goBackButton;

    public void updateLabels(String name, String food, String media) {
        nameLabel.setText("Thank you for answering all the questions, " + name + ".");
        foodLabel.setText("It is true that " + food + " is a delicious food item.");
        mediaLabel.setText("Well, guess you better get back on " + media + " now.");
    }

    @FXML
    private void handleGoBackButton() {
        App.showPrimaryStage();
        Stage secondaryStage = (Stage) goBackButton.getScene().getWindow();
        secondaryStage.close();
    }
}
