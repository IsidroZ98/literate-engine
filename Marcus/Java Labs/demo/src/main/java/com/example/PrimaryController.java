package com.example;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class PrimaryController {

    @FXML
    private TextField nameTextField;
    @FXML
    private TextField foodTextField;
    @FXML
    private TextField mediaTextField;
    @FXML
    private Button submitButton;

    @FXML
    private void handleSubmitButton() {
        String name = nameTextField.getText();
        String food = foodTextField.getText();
        String media = mediaTextField.getText();

        try {
            FXMLLoader secondaryLoader = new FXMLLoader(getClass().getResource("secondary.fxml"));
            Scene secondaryScene = new Scene(secondaryLoader.load(), 800, 600);

            SecondaryController secondaryController = secondaryLoader.getController();
            secondaryController.updateLabels(name, food, media);

            Stage secondaryStage = new Stage();
            secondaryStage.setTitle("Lab Assignment 12A - Responses");
            secondaryStage.setScene(secondaryScene);
            secondaryStage.show();

            Stage primaryStage = (Stage) submitButton.getScene().getWindow();
            primaryStage.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    } 
}
