/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 12A
// <Marcus Gutierrez> 
/////////////////////////

package com.example;

import javafx.application.Application;
import javafx.stage.Stage;

public class App extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        PrimaryController primaryController = new PrimaryController(primaryStage);
        primaryController.showPrimaryWindow();
    }
}
