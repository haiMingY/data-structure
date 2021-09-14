#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *arr, int size);

void mSort(int *arr, int start, int end, int *temp);

void merge(int *arr, int start, int end, int center, int *temp);

void printArr(int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        /* code */
        printf("%d \n", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 6, 89, 21, 225, 44, 336, 551, 42, 47, 6, 98, 67, 45, 1};
    int size = sizeof(arr) / sizeof(*arr);
    mergeSort(arr, size);
    printArr(arr, size);
    return 0;
}

void mergeSort(int *arr, int size)
{
    int *temp = malloc(sizeof(int) * size);
    if (temp != NULL)
    {

        mSort(arr, 0, size - 1, temp);
        free(temp);
    }
};

void mSort(int *arr, int start, int end, int *temp)
{
    if (start < end)
    {
        int center = (start + end) >> 1;
        mSort(arr, start, center, temp);
        mSort(arr, center + 1, end, temp);
        merge(arr, start, end, center + 1, temp);
    }
};

void merge(int *arr, int start, int end, int center, int *temp)
{
    printf(" start = %d end = %d center = %d \n", start, end, center);

    int leftEnd = center - 1;
    int index = start;
    int total = end - start;
    while (start <= leftEnd && center <= end)
    {
        if (arr[start] <= arr[center])
        {
            temp[index++] = arr[start++];
        }
        else
        {
            temp[index++] = arr[center++];
        }
    }
    while (start <= leftEnd)
    {
        temp[index++] = arr[start++];
    }
    while (center <= end)
    {
        temp[index++] = arr[center++];
    }
    for (size_t i = 0; i <= total; i++, end--)
    {
        arr[end] = temp[end];
    }
};