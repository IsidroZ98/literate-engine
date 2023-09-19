class SelectionSort {
    public static void sortArray(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int smolIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[smolIndex]) {
                    smolIndex = j;
                }
            }
            int temp = arr[smolIndex];
            arr[smolIndex] = arr[i];
            arr[i] = temp;
        }
    }
}
