#include <stdio.h>
#include "queue.h"
int main(int argc, char const *argv[])
{
    /* code */
    const int size = 1e3;

    queue q = queue_new();
    int i = 10;
    int a = 20;
    int aa = 26;
    int a1 = 201;
    int a2 = 202;
    int a3 = 203;
    int a4 = 204;
    int a5 = 205;
    int a6 = 206;
    int a7 = 207;
    int a8 = 208;
    int a9 = 209;
    enqueue(q, &i);
    enqueue(q, &a);
    enqueue(q, &aa);
    enqueue(q, &a1);
    enqueue(q, &a2);
    enqueue(q, &a3);
    enqueue(q, &a4);
    enqueue(q, &a5);
    enqueue(q, &a6);
    enqueue(q, &a7);
    enqueue(q, &a8);
    enqueue(q, &a9);

    while (!isEmpty(q))
    {
        int *m = dequeue(q);
        printf(" dequeue value = %d \n", *m);
    }

    return 0;
}
