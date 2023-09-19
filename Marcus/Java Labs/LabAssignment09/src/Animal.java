class Animal {
    private String breed;
    private int numberOfLegs;
    private double weight;

    public Animal(String breed, int numberOfLegs, double weight) {
        this.breed = breed;
        this.numberOfLegs = numberOfLegs;
        this.weight = weight;
    }

    public String getBreed() {
        return breed;
    }

    public int getNumberOfLegs() {
        return numberOfLegs;
    }

    public double getWeight() {
        return weight;
    }

    public void sleeping() {
        System.out.println("This animal is currently sleeping.");
    }
}
