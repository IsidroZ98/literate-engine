import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CBear {
    private static Map<String, Integer> foodCalories = new HashMap<>();

    public static void main(String[] args) {
        initializeFoodCalories();

        displayAvailableFoodTypes();

        try (
        Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter food type (comma-separated if multiple): ");
            String userInput = scanner.nextLine();

            int totalCalories = calculateTotalCalories(userInput);
            System.out.println("Total Calories: " + totalCalories);
        }
    }
// need to add bigger variety of foods and foods must be in lowercase // 
    public static void initializeFoodCalories() {
        foodCalories.put("grilled chicken", 182);
        foodCalories.put("chicken breast", 231);
        foodCalories.put("fried chicken", 320);
        foodCalories.put("chicken tenders", 185);
    }

    public static void displayAvailableFoodTypes() {
        System.out.println("Available Food Types:");
        for (String foodType : foodCalories.keySet()) {
            System.out.println("- " + foodType);
        }
    }

    public static int calculateTotalCalories(String userInput) {
        int totalCalories = 0;

        // Split the user input into individual food types
        String[] foodTypes = userInput.split(",");

        // Calculate total calories based on user input
        for (String foodType : foodTypes) {
            String trimmedFoodType = foodType.trim().toLowerCase();
            if (foodCalories.containsKey(trimmedFoodType)) {
                totalCalories += foodCalories.get(trimmedFoodType);
            } else {
                System.out.println("Warning: Food type '" + foodType + "' Invalid input, cannot find food");
            }
        }

        return totalCalories;
    }
}
