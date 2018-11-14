import java.util.Arrays;

/**
 * quickSort
 */
public class quickSort {

    private static void sort(int arr[]) {
        qSort(arr, 0, arr.length - 1);
    }

    private static void qSort(int arr[], int start, int end) {
        if (start < end) {
            int left = start, right = end;
            int mid = (start + end) >> 1;
            SortTemp.swap(arr, left, mid);
            int temp = arr[left];
            while (left < right) {
                while (left < right && arr[right] <= temp) {
                    right--;
                }
                arr[left] = arr[right];
                while (left < right && arr[left] >= temp) {
                    left++;
                }
                arr[right] = arr[left];
            }
            arr[left] = temp;
            qSort(arr, start, left - 1);
            qSort(arr, left + 1, end);
        }
    }

    public static void main(String[] args) {
        int arr[] = SortTemp.create();
        long startTime = System.currentTimeMillis();
        sort(arr);
        long endTime = System.currentTimeMillis();
        System.out.println("用时:"+ (endTime-startTime)+ " ms");
        // System.out.println(Arrays.toString(arr));
    }
}