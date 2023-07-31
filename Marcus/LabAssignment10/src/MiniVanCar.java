class MiniVanCar extends Car {
    boolean hasAutomaticSlidingDoor; 
        @Override
        void display() {
        super.display(); 
        System.out.printf("Has Automatic Sliding Door?: ", hasAutomaticSlidingDoor); 
    }
}