/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 06 
// <Marcus Gutierrez> 
/////////////////////////
package LabAssignment6; 

public class Car {
    String make; 
    String model; 
    int year; 
    
    public Car(String make, String model, int year) 
    {
        this.make = make; 
        this.model = model; 
        this.year = year; 
    }
        public String getMake() {
            return make; 
        }
        public String getModel() {
            return model; 
        }
        public int getYear() {
            return year; 
        }
}
