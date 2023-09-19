module com.example {
    requires transitive java.compiler; 
    requires javafx.controls;
    requires javafx.fxml;

    opens com.example to javafx.fxml;
    exports com.example;
}
