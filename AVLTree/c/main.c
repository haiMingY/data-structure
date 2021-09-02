#include <stdio.h>

#include "AVLTree.h"

int main(int argc, char const *argv[])
{
    /* code */
    AVLTree tree = NULL;
    int size = 16;
    int arr[16] = {70, 80, 90, 20, 10, 50, 60, 40, 30, 1, 8, 47, 95, 150, 635, 101};

    for (size_t i = 0; i < size; i++)
    {
        /* code */
        tree = insert(arr[i], tree);
    }

    printTree(tree, 0);
    puts("0000000000000000000000000000000000");
    tree = deleteNode(70, tree);
    puts("------------------------------delete");
    tree = deleteNode(80, tree);
    puts("------------------------------delete");
    printTree(tree, 0);
    return 0;
}
