class CruiseShip extends Ship {
    public int maxPassengers;

    public CruiseShip(String name, int year, int maxPassengers) {
        super(name, year);
        this.maxPassengers = maxPassengers;
    }

    public int getMaxPassengers() {
        return maxPassengers;
    }

    public void setMaxPassengers(int maxPassengers) {
        this.maxPassengers = maxPassengers;
    }
}