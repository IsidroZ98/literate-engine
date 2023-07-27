class Bird extends Animal {
    public Bird(String breed, int numberOfLegs, double weight) {
        super(breed, numberOfLegs, weight);
    }

    public void displayInformation() {
        System.out.println("Bird Breed: " + getBreed());
        System.out.println("Number of Legs: " + getNumberOfLegs());
        System.out.println("Weight: " + getWeight() + " kg");
    }

    public void flying() {
        System.out.println("This bird is currently flying.");
    }
}