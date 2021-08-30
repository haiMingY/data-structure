#include <stdio.h>
#include "list_node.h"
#include "doubly_linked_list.h"
int main(int argc, char const *argv[])
{
    /* code */
    printf("DoublyLinkedList \n");
    DoublyLinkedList *list = initList();
    push(list, 0);
    push(list, 1);
    push(list, 2);
    push(list, 3);
    printList(list);
    int *n = (int *)pop(list);
    printf("pop value = %d \n", *n);
    printf("pop address = %p \n", n);
    // printf("pop value = %p\n", n);
    printList(list);
    return 0;
}
