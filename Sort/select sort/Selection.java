/**
 * Selection
 */
public class Selection {

    public static void sort(int a[]) {
        int len = a.length;
        for (int i = 0; i < len; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (a[j] < a[min]) {
                    min = j;
                }
            }
            if (min != i) {
                SortTemp.swap(a, i, min);
            }
        }
    }

    public static void main(String[] args) {

        int arr[] = SortTemp.create();
        // print(arr);
        long start = System.currentTimeMillis();
        sort(arr);
        long end = System.currentTimeMillis();
        SortTemp.print(arr);
        System.out.println("用时:"+    (end - start)+"ms");

    }
}