public class LabAssignment10 {
    public static void main(String []args) {
        SportsCar sportsCar = new SportsCar(); 

        sportsCar.make = "Dodge";
        sportsCar.model = "Charger"; 
        sportsCar.price = "$75000.00"; // use decimal because it is a double
        sportsCar.mileage = "7500";  
        sportsCar.hasAccessories = true; 

        MiniVanCar miniVanCar = new MiniVanCar(); 
        miniVanCar.make = "Kia"; 
        miniVanCar.model = "Carnival"; 
        miniVanCar.price = "$ 21500.99"; 
        miniVanCar.mileage = "56138"; 
        miniVanCar.hasAutomaticSlidingDoor = true; 

        sportsCar.display(); 
        System.out.println(); 
        miniVanCar.display(); 
    }
}