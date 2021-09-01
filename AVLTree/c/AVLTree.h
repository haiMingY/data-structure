#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct AVLNode;
typedef struct AVLNode *AvlNode;
typedef struct AVLNode *AVLTree;

// 创建节点
AVLTree createAvlNode(const int data);

// 查找指定数据的节点
AvlNode find(const int data, const AVLTree tree);
// 查找最小节点
AvlNode findMin(const AVLTree tree);
// 查找最大节点
AvlNode findMax(const AVLTree tree);
// 插入数据
AVLTree insert(const int data, AVLTree tree);
// 删除
AVLTree deleteNode(const int data, AVLTree tree);

// 旋转
// 左旋转（LL旋转）
AVLTree rotateLeft(AVLTree node);
// 右旋转（RR旋转）
AVLTree rotateRight(AVLTree node);
// 右左旋转（RL旋转）
AVLTree rotateRightLeft(AVLTree node);
// 左右旋转（LR旋转）
AVLTree rotateLeftRight(AVLTree node);

// 节点 struct
struct AVLNode
{
    /* data */
    int data;
    int height;
    AVLTree left;
    AVLTree right;
};

AVLTree createAvlNode(const int data)
{
    printf("--------------%d sizeof %lu\n", data, sizeof(AVLTree));
    AVLTree node = (AVLTree)malloc(sizeof(AVLTree));
    if (node == NULL)
    {
        printf("createAvlNode 内存分配出错！\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
};
// 获取avl树的高度
static int height(AvlNode node)
{

    if (node == NULL)
        return -1;
    return node->height;
}

static int max(int a, int b)
{
    return a > b ? a : b;
}

static int getMaxHeight(AVLTree node)
{
    return max(height(node->left), height(node->right)) + 1;
}

// 左旋转（LL旋转）
AVLTree rotateLeft(AVLTree node)
{
    // 拿出右子树节点
    AVLTree rightNode = node->right;
    // 将右子树的左子树赋值给当前旋转节点的有右节点
    node->right = rightNode->left;
    //将 当前旋转节点赋值给右子树的左节点
    rightNode->left = node;

    // 重新设置高度
    node->height = getMaxHeight(node);
    rightNode->height = getMaxHeight(rightNode);

    //完成旋转 将右子树返回
    return rightNode;
}
// 右旋转（RR旋转）
AVLTree rotateRight(AVLTree node)
{ // 拿出左子树节点
    AVLTree leftNode = node->left;
    // 将左子树的右子树节点赋值给当前旋转节点的左侧节点
    node->left = leftNode->right;
    // 将当前旋转节点赋值给左子树的右侧节点
    leftNode->right = node;
    // 重新设置高度
    node->height = getMaxHeight(node);
    leftNode->height = getMaxHeight(leftNode);
    // 完成旋转 将左子树节点返回
    return leftNode;
};

// 左右旋转（LR旋转）
AVLTree rotateLeftRight(AVLTree node)
{
    // 先对当前旋转节点的左子树节点进行左旋转 并将返回值赋值给左子树
    node->left = rotateLeft(node->left);
    // 再对当前旋转节点进行右旋转
    return rotateRight(node);
}
// 右左旋转（RL旋转）
AVLTree rotateRightLeft(AVLTree node)
{
    // 先对当前旋转节点的右子树节点进行右旋转 并将返回值赋值给右子树
    node->right = rotateRight(node->right);
    // 再对当前旋转节点进行左旋转
    return rotateLeft(node);
}

AVLTree insert(const int data, AVLTree tree)
{
    printf("--------insert\n");
    if (tree == NULL)
    {
        tree = createAvlNode(data);
    }
    else if (data < tree->data)
    { //比当前节点小 插入左子树中
        tree->left = insert(data, tree->left);

        // 两颗子树的高度差不大于1，则该节点是平衡的
        if (height(tree->left) - height(tree->right) > 1)
        {
            if (data < tree->left->data)
            {
                tree = rotateLeft(tree);
            }
            else
            {
                tree = rotateLeftRight(tree);
            }
        }
    }
    else if (data > tree->data)
    {
        // 比当前节点的值大，插入右子树中
        tree->right = insert(data, tree->right);
        if (height(tree->right) - height(tree->left) > 1)
        {
            if (data > tree->right->data)
            {
                tree = rotateRight(tree);
            }
            else
            {
                tree = rotateRightLeft(tree);
            }
        }
    }

    tree->height = getMaxHeight(tree);
    return tree;
}

void printTree(AVLTree tree, int level)
{
    if (tree != NULL)
    {
        printTree(tree->left, level + 1);
        printf("node data = %d, height = %d , level = %d\n", tree->data, tree->height, level);
        printTree(tree->right, level + 1);
    }
}

#endif //AVL_TREE_H