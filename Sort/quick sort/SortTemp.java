/**
 * Util
 */
public class SortTemp {
    private static final int MAX = 12345678;
    public static int[] create() {
        int arr[] = new int[MAX];
        for (int i = 0; i < MAX; i++) {
            arr[i] = (int) (Math.random() * 100000000 + 1);
        }
        return arr;
    }
    public static void swap(int a[], int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void print(int arr[]) {
        for (int var : arr) {
            System.out.print("----number:" + var + ", ");
        }
        System.out.println();
    }
}