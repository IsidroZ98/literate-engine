class SportsCar extends Car {
    boolean hasAccessories; 
@Override
    public void display() {
        super.display(); 
        System.out.printf("Has Accessories: ", hasAccessories); 
    }
}