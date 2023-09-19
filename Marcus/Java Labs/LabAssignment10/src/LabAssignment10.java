/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 10
// <Marcus Gutierrez> 
/////////////////////////

public class LabAssignment10 {
    public static void main(String []args) {
        SportsCar sportsCar = new SportsCar(); 

        sportsCar.make = "Dodge";
        sportsCar.model = "Charger"; 
        sportsCar.price = 75000.00;
        sportsCar.mileage = 7500;  
        sportsCar.hasAccessories = false;  

        MiniVanCar miniVanCar = new MiniVanCar(); 
        miniVanCar.make = "Kia"; 
        miniVanCar.model = "Carnival"; 
        miniVanCar.price = 21500.99; 
        miniVanCar.mileage = 56138; 
        miniVanCar.hasAutomaticSlidingDoor = true; 

        sportsCar.display(); 
        System.out.println("false\n");
        
        miniVanCar.display(); 
        System.out.println("true"); 
        
    }
} 