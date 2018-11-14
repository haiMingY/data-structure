/**
 * Insertion
 */
public class Insertion {

    private static void sort(int arr[]) {
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) { //重后向前找小于它的数,找到就交换
                SortTemp.swap(arr, j, j - 1);
                j--;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = SortTemp.create();
        long start = System.currentTimeMillis();
        sort(arr);
        long end = System.currentTimeMillis();
        SortTemp.print(arr);
        System.out.println("用时:"+    (end - start)+"ms");
    }
}