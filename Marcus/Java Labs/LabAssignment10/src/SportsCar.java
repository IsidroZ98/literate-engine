class SportsCar extends Car {
    boolean hasAccessories; 
        @Override
        void display() {
        super.display(); 
        System.out.printf("Has Accessories?: ", hasAccessories); 
    }
}