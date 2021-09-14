#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define parent(i) abs(i - 1) / 2
#define left(i) 2 * i + 1
#define right(i) 2 * i + 2

struct Heap;
typedef struct Heap *heap;

struct Heap
{
    unsigned int capacity;
    unsigned int size;
    /* data */
    int *arr;
};
// 初始一个堆
heap init_heap(int capacity);
// 创建堆
void build_max_heap(int arr[], int size);
// 下滤
void perDown(int *arr, int size, int i);
// 堆不是空
int isEmpty(heap h);
// 堆是不是满的
int isFull(heap h);
// 插入
void insert(int data, heap h);

// 删除最大值

void deleteMax(heap h);

// 堆排序
void heapSort(int arr[], int size);

// 打印

void printHeap(heap h);
void printArr(int arr[], int size);
void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
};

heap init_heap(int capacity)
{
    heap h = (heap)malloc(sizeof(struct Heap));
    if (h == NULL)
    {
        puts("error: init heap");
        exit(EXIT_FAILURE);
    }
    h->capacity = capacity;
    h->size = 0;
    h->arr = (int *)malloc(sizeof(int *) * (capacity + 1));
    return h;
};
// 堆不是空
int isEmpty(heap h)
{
    return h->size == 0;
};
// 堆是不是满的
int isFull(heap h)
{
    return h->size >= h->capacity;
};
// 插入
void insert(int data, heap h)
{
    int i;

    if (isFull(h))
    {
        printf("heap is full \n");
        return;
    }
    for (i = h->size++; i >= 1 && h->arr[parent(i)] < data; i = parent(i))

    {

        h->arr[i] = h->arr[parent(i)];
    }
    h->arr[i] = data;
}
// 删除最大值

void deleteMax(heap h)
{
    int i, child;
    if (isEmpty(h))
    {
        printf("heap is empty \n");
        return;
    }
    int max = h->arr[0];
    int last = h->arr[h->size - 1];
    h->size--;
    for (i = 0; left(i) < h->size; i = child)
    {
        child = left(i);
        if (child != h->size && h->arr[child + 1] > h->arr[child])
        {
            child++;
        }

        if (last < h->arr[child])
        {
            h->arr[i] = h->arr[child];
        }
        else
        {
            break;
        }
    }
    h->arr[i] = last;
};
void printArr(int arr[], int size)
{
    printf("{\n");
    for (size_t i = 0; i < size; i++)
    {

        printf("%lu : %d \n", i, arr[i]);
    }
    printf("}\n");
}
// 创建堆
void build_max_heap(int arr[], int size)
{

    for (int i = size / 2; i >= 0; i--)
    {
        /* code */
        perDown(arr, size, i);
    }
};

void perDown(int *arr, int size, int i)
{
    int leftIndex = left(i);
    int rightIndex = right(i);
    int largest = i;
    if (rightIndex < size && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }
    if (leftIndex < size && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }
    if (i != largest)
    {
        swap(&arr[i], &arr[largest]);
        perDown(arr, size, largest);
    }
};

// 堆排序
void heapSort(int arr[], int size)
{
    build_max_heap(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        /* code */
        swap(&arr[0], &arr[i]);
        perDown(arr, i, 0);
    }
};

// 打印

void printHeap(heap h)
{
    if (h != NULL)
    {
        printf("heap capacity  = %d\n heap size = %d \n", h->capacity, h->size);
        for (size_t i = 0; i < h->size; i++)
        {
            /* code */
            printf("heap %lu -------> %d \n", i, h->arr[i]);
        }
    }
};
#endif //HEAP_H