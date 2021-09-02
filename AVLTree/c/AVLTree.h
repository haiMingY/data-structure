#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
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

// 再平衡 通过旋转让AVL 树再度平衡
AVLTree rebalance(const int data, AVLTree node);

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

static int maxNumber(const int a, const int b)
{
    return a > b ? a : b;
};

static int getMaxHeight(AVLTree node)
{
    return maxNumber(height(node->left), height(node->right)) + 1;
}

// 递归查找左节点 为最小
AVLTree findMin(AVLTree tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->left == NULL)
        return tree;
    return findMin(tree->left);
}
// 循环查找右节点 为最大
AVLTree findMax(AVLTree tree)
{
    if (tree != NULL)
    {
        while (tree->right != NULL)
        {
            tree = tree->right;
        }
    }
    return tree;
}
// 左旋转（LL旋转）
AVLTree rotateLeft(AVLTree node)
{
    // 拿出右子树节点
    AVLTree rightNode = node->right;
    assert(rightNode != NULL);
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
    assert(leftNode != NULL);
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
    assert(node != NULL && node->left != NULL);
    // 先对当前旋转节点的左子树节点进行左旋转 并将返回值赋值给左子树
    node->left = rotateLeft(node->left);
    // 再对当前旋转节点进行右旋转
    return rotateRight(node);
}
// 右左旋转（RL旋转）
AVLTree rotateRightLeft(AVLTree node)
{
    assert(node != NULL && node->right != NULL);
    // 先对当前旋转节点的右子树节点进行右旋转 并将返回值赋值给右子树
    node->right = rotateRight(node->right);
    // 再对当前旋转节点进行左旋转
    return rotateLeft(node);
}
// 再平衡 通过旋转让AVL 树再度平衡
AVLTree rebalance(const int data, AVLTree node)
{
    if (node == NULL)
        return NULL;
    // 两颗子树的高度差不大于1，则该节点是平衡的

    // 左子树的高度大于右子树的高度 并且差值大于1 节点不平衡
    if (height(node->left) - height(node->right) > 1)
    {
        // 当前插入的值小于 左子树的值 说明 这个新节点插入到了左子树的左子树节点的位置 进行右旋转
        if (data < node->left->data)
        {

            node = rotateRight(node);
        }
        else // 否则就是插入了 左子树的右子树节点位置 进行左右旋转
        {
            node = rotateLeftRight(node);
        }
    }
    // 右子树的高度大于左子树的高度 并且差值大于1 节点不平衡
    else if (height(node->right) - height(node->left) > 1)
    {
        // 当前插入的值大于 右子树的值 说明 这个新节点插入到了 右子树的右子树的位置 进行左旋转
        if (data > node->right->data)
        {
            node = rotateLeft(node);
        }
        else // 否则就是在右子树的左子树位置 进行右左旋转
        {
            node = rotateRightLeft(node);
        }
    }
    return node;
};
AVLTree insert(const int data, AVLTree tree)
{
    if (tree == NULL)
    {
        tree = createAvlNode(data);
    }
    else if (data < tree->data)
    { //比当前节点小 插入左子树中
        tree->left = insert(data, tree->left);
    }
    else if (data > tree->data)
    {
        // 比当前节点的值大，插入右子树中
        tree->right = insert(data, tree->right);
    }
    // 再平衡
    tree = rebalance(data, tree);
    tree->height = getMaxHeight(tree);
    return tree;
}

AVLTree deleteNode(const int data, AVLTree tree)
{
    if (tree == NULL)
        return NULL;

    if (tree->data > data)
    {
        // 小于当前节点值 去左子树节点查找
        tree->left = deleteNode(data, tree->left);
    }
    else if (tree->data < data)
    {
        // 大于当前节点值 右去子树节点查找
        tree->right = deleteNode(data, tree->right);
    }
    else if (tree->left && tree->right)
    {
        // 找到右子树最小的节点，替换当前节点
        AVLTree temp = findMin(tree->right);
        tree->data = temp->data;
        // 再将最小节点删除
        tree->right = deleteNode(temp->data, tree->right);
    }
    else
    {
        AVLTree temp = tree;
        if (tree->left == NULL)
        {
            tree = tree->right;
        }
        else if (tree->right == NULL)
        {
            tree = tree->left;
        }
        free(temp);
    }
    // 再平衡
    tree = rebalance(data, tree);
    return tree;
};

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