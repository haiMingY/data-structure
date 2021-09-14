
#include <stdio.h>

void quickSort(int arr[], int size);

void qSort(int *arr, int start, int end);
void qSort2(int *arr, int start, int end);
int partition(int *arr, int start, int end);

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
};

void printArr(int arr[], int start, int size)
{
    for (size_t i = start; i < size; i++)
    {
        printf("data = %d \n", arr[i]);
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {10, 63, 52, 45, 85, 41, 32, 96};
    int size = sizeof(arr) / sizeof(*arr);
    quickSort(arr, size);
    printArr(arr, 0, size);

    return 0;
}

void quickSort(int *arr, int size)
{
    qSort2(arr, 0, size - 1);
};

void qSort(int *arr, int start, int end)
{
    if (start < end)
    {
        printArr(arr, 0, end);
        puts("=================================");
    }
};

void qSort2(int *arr, int start, int end)
{
    if (start < end)
    {
        printArr(arr, start, end);
        puts("===================");
        int q = partition(arr, start, end);
        qSort2(arr, start, q - 1);
        qSort2(arr, q + 1, end);
    }
};

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int i = start;
    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[i]);
    return i;
};