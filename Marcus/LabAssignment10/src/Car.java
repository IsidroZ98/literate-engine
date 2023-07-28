public class Car {
    String make; 
    String model;
    double price; 
    int mileage;

    public void display() {
        System.out.printf("Make: %s", make); 
        System.out.printf("Model: %s", model); 
        System.out.printf("Price: %.2f", price); 
        System.out.printf("Mileage  %d", mileage);
    }
}