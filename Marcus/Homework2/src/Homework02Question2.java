import java.io.*;
import java.util.*;

public class Homework02Question2 {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            Random random = new Random();

            try {
                PrintWriter writer = new PrintWriter("ships.txt");

                for (int i = 1; i <= 10; i++) {
                    String shipType = random.nextBoolean() ? "CruiseShip" : "CargoShip";
                    String shipName = "ship-" + i;

                    System.out.print("Enter the year for " + shipType + " " + shipName + ": ");
                    int shipYear = scanner.nextInt();

                    if (shipType.equals("CruiseShip")) {
                        int maxPassengers = random.nextInt(401) + 100;
                        if (maxPassengers > 500) {
                            maxPassengers = 500; 
                        }
                        writer.println(shipType + "," + shipName + "," + shipYear + "," + maxPassengers);
                    } else {
                        int cargoCapacity = random.nextInt(101) + 50; 
                        writer.println(shipType + "," + shipName + "," + shipYear + "," + cargoCapacity);
                    }
                }
                writer.close();

                BufferedReader reader = new BufferedReader(new FileReader("ships.txt"));
                String line;
                System.out.println("\n Ship Info:");
                System.out.println("=================");
                System.out.printf("%-15s %-15s %-15s %-20s %-20s%n", "Ship Type", "Ship Name", "Year", "Cargo Capacity(in tons)", "Max Passengers (100-500)");

                while ((line = reader.readLine()) != null) {
                    String[] parts = line.split(",");
                    String shipType = parts[0];
                    String shipName = parts[1];
                    int shipYear = Integer.parseInt(parts[2]);

                    if (shipType.equals("CruiseShip")) {
                        int maxPassengers = Integer.parseInt(parts[3]);
                        if (maxPassengers > 500) {
                            maxPassengers = 500; 
                        }
                        System.out.printf("%-15s %-15s %-15d %-20s %-20d%n", shipType, shipName, shipYear, "N/A", maxPassengers);
                    } else {
                        int cargoCapacity = Integer.parseInt(parts[3]);
                        if (cargoCapacity > 150) {
                            cargoCapacity = 150;
                        }
                        System.out.printf("%-15s %-15s %-15d %-20d %-20s%n", shipType, shipName, shipYear, cargoCapacity, "N/A");
                    }
                }
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (NumberFormatException e) {
            e.printStackTrace();
        }
    }
}

