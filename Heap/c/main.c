#include <stdio.h>
#include "heap.h"
int main(int argc, char const *argv[])
{
    printf("heap \n");
    heap h = init_heap(70);
    insert(20, h);
    insert(60, h);
    insert(50, h);
    insert(63, h);
    insert(23, h);
    insert(93, h);
    printHeap(h);
    deleteMax(h);
    printHeap(h);
    deleteMax(h);
    printHeap(h);
    int arr[16] = {6, 8, 95, 14, 20, 36, 741, 62, 54, 968, 1233, 45, 1552, 67, 52, 62};
    heapSort(arr, 16);

    // printArr(arr,16);
    return 0;
}
