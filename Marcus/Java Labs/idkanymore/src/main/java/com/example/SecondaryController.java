/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 12A
// <Marcus Gutierrez> 
/////////////////////////

package com.example;

import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class SecondaryController {
    private Stage primaryStage;
    private String name, food, media;
    private Label resultLabel;

    public SecondaryController(Stage primaryStage, String name, String food, String media) {
        this.primaryStage = primaryStage;
        this.name = name;
        this.food = food;
        this.media = media;
    }

    public void showResultWindow() {
        VBox root = new VBox(10);
        root.setPrefSize(800, 600);
        root.setStyle("-fx-background-color: #f4f4f4;");

        String resultText = "Thank you for answering all the questions, " +name+
                ". It is true that " +food+ " is a delicious food item. " +
                "Well, guess you better get back on " +media + " now.";

        resultLabel = new Label(resultText);
        Button goBackButton = new Button("Go Back");
        goBackButton.setOnAction(e -> goBackToPrimary());

        root.getChildren().addAll(resultLabel, goBackButton);

        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
    }

    private void goBackToPrimary() {
        PrimaryController primaryController = new PrimaryController(primaryStage);
        primaryController.showPrimaryWindow();
    }
}
