package com.example;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class App extends Application {

    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("primary.fxml"));

        Scene scene = new Scene(root, 800, 600);

        primaryStage.setTitle("Lab Assignment 12A");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void showPrimaryStage() {
    }
}
