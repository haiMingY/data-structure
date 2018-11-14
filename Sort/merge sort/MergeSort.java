import java.util.Arrays;

/**
 * MergeSort
 */
public class MergeSort {

    public static void sort(int arr[]) {
        int temp[] = new int[arr.length];
        // mergeUp(arr, temp, 0, arr.length - 1);
        mergeDown(arr, temp);
    }

    public static void mergeUp(int arr[], int temp[], int left, int right) { //自底向上
        if (left < right) {
            int center = (left + right) >> 1;
            mergeUp(arr, temp, left, center);
            mergeUp(arr, temp, center + 1, right);
            merge(arr, temp, left, center, right);
        }
    }

    public static void mergeDown(int arr[], int temp[]) { //自顶
        int n = arr.length;
        for (int sz = 1; sz < n; sz += sz) {
            for (int lo = 0; lo < n - sz; lo += sz + sz) {
                merge(arr, temp, lo, lo + sz - 1, Math.min(n - 1, lo + sz + sz - 1));
            }
        }
    }

    public static void merge(int arr[], int temp[], int left, int mid, int right) {
        int rightPos = mid + 1;
        int tempPos = left;
        int nums = right - left + 1;
        while (left <= mid && rightPos <= right) {
            if (arr[left] <= arr[rightPos]) {
                temp[tempPos++] = arr[left++];
            } else {
                temp[tempPos++] = arr[rightPos++];
            }
        }

        while (left <= mid) {
            temp[tempPos++] = arr[left++];
        }
        while (rightPos <= right) {
            temp[tempPos++] = arr[rightPos++];
        }

        for (int i = 0; i < nums; i++) {
            arr[right] = temp[right];
            right--;
        }
    }

    public static void main(String[] args) {
        int arr[] = SortTemp.create();
        long startTime = System.currentTimeMillis();
        sort(arr);
        long endTime = System.currentTimeMillis();
        System.out.println("用时:"+   (endTime-  startTime)+ "ms");
        // System.out.println(Arrays.toString(arr));
    }
}