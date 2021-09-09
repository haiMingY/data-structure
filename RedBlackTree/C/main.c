#include <stdio.h>
#include "RedBlackTree.h"
int main(int argc, char const *argv[])
{
    /* code */

    RBTree tree = init_rbtree();
    insert(tree, 1);
    insert(tree, 2);
    insert(tree, 3);
    insert(tree, 4);
    insert(tree, 5);
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, 8);
    insert(tree, 9);

    print(tree->nil, tree->root);
    delete(tree,8);
    delete(tree,9);
    print(tree->nil, tree->root);
    return 0;
}
