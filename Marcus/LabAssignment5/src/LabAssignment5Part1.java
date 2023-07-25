public class LabAssignment5Part1 {
    public static void main(String[] args) {
        char[] array1 = new char[5];
        char[] array2 = {'a', 'e', 'i', 'o', 'u'}; 

        array1[0] = 'a';
        array1[1] = 'b';
        array1[2] = 'c';
        array1[3] = 'd';
        array1[4] = 'e';

        System.out.println("Comparing arrays at the same index:");
        System.out.println("Index\tArray1\tArray2\tResult");

        for (int i = 0; i < 5; i++) {
            boolean areEqual = array1[i] == array2[i];
            System.out.println(i + "\t\t" + array1[i] + "\t\t" + array2[i] + "\t\t" + (areEqual ? "1" : "0"));
        }
    }
}
