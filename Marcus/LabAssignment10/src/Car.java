public class Car {
    String make; 
    String model;
    double price; 
    int mileage;

        void display() {
        System.out.printf("Make: %s\n", make); 
        System.out.printf("Model: %s\n", model); 
        System.out.printf("Price: $%.2f\n", price); 
        System.out.printf("Mileage:  %d\n", mileage);
    }
}