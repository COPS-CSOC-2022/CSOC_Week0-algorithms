public class countInversion {
    static int array[] = new int[] { 5, 6, 80, 75, 3 };

    static int invCount(int n) {
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (array[i] > array[j]) {
                    m++;
                }
            }
        }

        return m;
    }

    public static void main(String args[]) {
        int inversion_count = invCount(array.length);

        System.out.println("Total number of inversions are : " + inversion_count);
    }
}