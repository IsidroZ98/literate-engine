/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 12A
// <Marcus Gutierrez> 
/////////////////////////

package com.example; 

import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class PrimaryController {
    private Stage primaryStage;
    private TextField nameField, foodField, mediaField;
    private Label nameLabel, foodLabel, mediaLabel;

    public PrimaryController(Stage primaryStage) {
        this.primaryStage = primaryStage;
        primaryStage.setTitle("Lab Assignment 12A");
    }

    public void showPrimaryWindow() {
        VBox root = new VBox(10);
        root.setPrefSize(800, 600);
        root.setStyle("-fx-background-color: #f4f4f4;");

        nameLabel = new Label("What is your name?");
        nameField = new TextField();
        foodLabel = new Label("What is your favorite food item?");
        foodField = new TextField();
        mediaLabel = new Label("What is your favorite social media platform?");
        mediaField = new TextField();

        Button submitButton = new Button("Submit");
        submitButton.setOnAction(e -> showResultWindow());

        root.getChildren().addAll(nameLabel, nameField, foodLabel, foodField, mediaLabel, mediaField, submitButton);

        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void showResultWindow() {
        String name = nameField.getText();
        String food = foodField.getText();
        String media = mediaField.getText();

        SecondaryController secondaryController = new SecondaryController(primaryStage, name, food, media);
        secondaryController.showResultWindow();
    }
}
