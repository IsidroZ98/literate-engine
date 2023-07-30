/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 09
// <Marcus Gutierrez> 
/////////////////////////

public class LabAssignment09 {
    public static void main(String[] args) {
        System.out.println("Showing information about this cat..."); 
        Cat cat = new Cat("Ocelot", 4, 30.0);
        System.out.println("The cat is a " + cat.getBreed() + ", has 4 leg(s) , and weighs " + cat.getWeight() + " pound(s).");
        cat.purring();
        cat.sleeping();

        System.out.println("\nShowing information about this bird...");

        Bird bird = new Bird("Parakeet", 2, 0.1);
        System.out.println("The bird is a(n) " + bird.getBreed() + " has 2 leg(s), and weighs " + bird.getWeight() + " pound(s).");
        bird.flying();
    }
}
