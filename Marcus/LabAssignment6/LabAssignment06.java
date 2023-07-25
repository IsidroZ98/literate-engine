package LabAssignment6;

public class LabAssignment06 {
    public static void main(String[] args) {
        Car myCar = new Car("Nissan", "GTR", 2022);

        System.out.println("Make: " + myCar.getMake());
        System.out.println("Model: " + myCar.getModel());
        System.out.println("Year: " + myCar.getYear());
    }
}