#include <stdio.h>

#include "AVLTree.h"

int main(int argc, char const *argv[])
{
    /* code */
    AVLTree tree = NULL;
    int arr[] = {70, 80, 90, 20, 10, 50, 60, 40, 30};

    for (size_t i = 0; i < 9; i++)
    {
        /* code */
        tree = insert(arr[i], tree);
    }

    printTree(tree, 0);
    return 0;
}
