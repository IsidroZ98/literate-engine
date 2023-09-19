package com.example;

import java.awt.Desktop;  
import java.io.*;  
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class GUI extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        // Load the FXML file
        FXMLLoader loader = new FXMLLoader(getClass().getResource("primary.fxml"));
        Parent root = loader.load();

        // Create a scene
        Scene scene = new Scene(root, 800, 600);

        // Set the scene and show the stage
        primaryStage.setScene(scene);
        primaryStage.setTitle("FXML Example");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
