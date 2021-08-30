#include <stdio.h>
// #include <Windows.h>
#include "LinkList.h"
int main(int argc, char const *argv[])
{
    // DWORD start, end;
    // start = GetTickCount();
    /* code */
    struct LinkList *list = create_list();

    // for (size_t i = 0; i < 2e6; i++)
    // {
    //     /* code */
    //     push(list, i);
    // }
    // end = GetTickCount();
    // printf("time= %lu\n", end - start);
    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 5);

    insertAfter(list, 4, 2);
    insertBefore(list, 6, 2);
    insertBefore(list, 7, 3);
    insertBefore(list, 8, list->size - 1);
    // printList(list);
    // pop(list);
    printList(list);

    // findMiddleByDubblePoint(list);
    // findMiddleByLength(list);
    // removeNode(list, 4);
    reverseByRecursion(list);
    printList(list);
    // puts("print after \n");
    return 0;
}
