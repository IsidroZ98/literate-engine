class Cat extends Animal {
    public Cat(String breed, int numberOfLegs, double weight) {
        super(breed, numberOfLegs, weight);
    }

    public void displayInformation() {
        System.out.println("Cat Breed: " + getBreed());
        System.out.println("Number of Legs: " + getNumberOfLegs());
        System.out.println("Weight: " + getWeight() + " kg");
    }

    public void purring() {
        System.out.println("This cat is currently purring.");
    }
}