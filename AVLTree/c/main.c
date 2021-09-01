#include <stdio.h>

#include "AVLTree.h"

int main(int argc, char const *argv[])
{
    /* code */
    AVLTree tree = NULL;
    tree = insert(60, tree);
    insert(50, tree);
    insert(20, tree);
    insert(80, tree);
    insert(90, tree);
    insert(70, tree);
    insert(55, tree);
    insert(10, tree);
    insert(40, tree);
    insert(35, tree);
    printTree(tree, 0);
    return 0;
}
