/////////////////////////
// CSCI 3326.01
// Summer II 2023
// Lab Assignment 05 Part 1
// <Marcus Gutierrez> 
/////////////////////////
public class LabAssignment05Part1 {
    public static void main(String[] args) {
        char[] array1 = new char[5];
        char[] array2 = {'a', 'e', 'i', 'o', 'u'};

        array1[0] = 'a';
        array1[1] = 'b';
        array1[2] = 'c';
        array1[3] = 'd';
        array1[4] = 'e';

        for (int i = 0; i < 5; i++) {
            if (array1[i] == array2[i]) {
                System.out.println("1 ");
            } else {
                System.out.println("0 ");
            }
        }
    }
}