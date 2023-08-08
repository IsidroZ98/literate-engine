package pancake.lab12;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

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

        // Show the secondary controller and pass data
        // Hint: You'll need to implement this part
    }
}
