import java.util.Scanner;

public class HomeworkAssignment01Question2 {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the number of floors in the hotel: ");
            int numberOfFloors = scanner.nextInt();

            int totalRooms = 0;
            int totalOccupiedRooms = 0;

            for (int floor = 1; floor <= numberOfFloors; floor++) {
                System.out.print("Enter the number of rooms on floor " + floor + ": ");
                int numberOfRooms = scanner.nextInt();
                totalRooms += numberOfRooms;

                System.out.print("Enter the number of occupied rooms on floor " + floor + ": ");
                int numberOfOccupiedRooms = scanner.nextInt();
                totalOccupiedRooms += numberOfOccupiedRooms;
            }

            int vacantRooms = totalRooms - totalOccupiedRooms;
            double occupancyRate = (double) totalOccupiedRooms / totalRooms * 100;

            System.out.println("\nHotel Summary:");
            System.out.println("Total Rooms: " + totalRooms);
            System.out.println("Occupied Rooms: " + totalOccupiedRooms);
            System.out.println("Vacant Rooms: " + vacantRooms);
            System.out.printf("Occupancy Rate: %.2f%%\n", occupancyRate);
        }
    }
}
