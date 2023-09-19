/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 15
// <Marcus Gutierrez> 
/////////////////////////

public class LabAssignment15 {

    public static void main(String[] args) {
        int[] unsortedArray = {8, 10, -2, 38, -1, 0, 0, 3};

        System.out.print("UNSORTED:");
        for (int num : unsortedArray) {
            System.out.print(" " + num);
        }
        System.out.println();

        SelectionSort.sortArray(unsortedArray);

        System.out.print("SORTED:");
        for (int num : unsortedArray) {
            System.out.print(" " + num);
        }
        System.out.println();
    }
}