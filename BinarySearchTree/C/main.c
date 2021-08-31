#include <stdio.h>
#include "BinarySearchTree.h"
int main(int argc, char const *argv[])
{
    /* code */

    PtrNode node = NULL;
    node = insert(52, node);
    insert(60, node);
    insert(70, node);
    insert(62, node);
    insert(6, node);
    insert(160, node);
    insert(46, node);
    insert(20, node);
    insert(80, node);
    insert(41, node);
    insert(96, node);
    insert(30, node);

    SearchTree n = findMin(node);
    printf("min data = %d\n", n->data);
    n = findMax(node);
    printf("max data = %d\n", n->data);
    inOrder(node);
    puts("---------------------------");
    deleteEl(52,node);
    inOrder(node);
    return 0;
}
