package LabAssignment6;

public class LabAssignment06 {
    public static void main(String[] args) {
        Car myCar = new Car("Honda", "Civic", 2017);

        System.out.println("Make: " + myCar.getMake());
        System.out.println("Model: " + myCar.getModel());
        System.out.println("Year: " + myCar.getYear());
    }
}