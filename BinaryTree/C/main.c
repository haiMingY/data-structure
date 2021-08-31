#include <stdio.h>
#include "BinaryTree.h"
int main(int argc, char const *argv[])
{
    /* code */
    printf("hello \n");

    PtrNode node = NULL;
    if (node == NULL)
    {
        puts("----------null");
    }
    node = insert(node,6);
    insert(node,5);
    insert(node,0);
    insert(node,3);
    insert(node,8);
    insert(node,7);
    insert(node,10);
    insert(node,11);
    insert(node,2);
    levelorder(node);
    return 0;
}
