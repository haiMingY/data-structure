#include <stdio.h>
#include "LinkList.h"
int main(int argc, char const *argv[])
{
    /* code */
    struct LinkList *list = create_list();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 5);
    push(list, 4);
    printList(list);
    puts("print after \n");
    pop(list);
    printList(list);
    puts("print after \n");
    pop(list);
    printList(list);
    puts("print after \n");
    pop(list);
    printList(list);
    puts("print after \n");
    pop(list);
    printList(list);
    puts("print after \n");
    pop(list);
    printList(list);
    puts("print after \n");
    return 0;
}
