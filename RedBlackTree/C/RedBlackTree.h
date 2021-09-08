#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct RedBlackNode;
struct RedBlackTree;
typedef struct RedBlackNode *RBNode;
typedef struct RedBlackTree *RBTree;

// 颜色
typedef enum Color
{
    RED,
    BLACK
} Color;

// 红黑树节点
struct RedBlackNode
{
    /* data */
    int data;
    // 左子树
    RBNode left;
    // 右子树
    RBNode right;
    // 父节点
    RBNode parent;
    // 颜色
    Color color;
};

struct RedBlackTree
{
    /* data */
    RBNode root;
};

// 创建节点
RBNode createNode(const int data);
// 初始化一颗红黑树
RBTree init_rbtree();

// 左旋
void rotate_left(RBTree tree, RBNode node);
// 右旋
void rotate_right(RBTree tree, RBNode node);

// 插入
void insert(RBTree tree, const int data);

// 二叉树插入
RBNode bs_insert(RBNode node, RBNode root, RBNode parent);

// 红黑树 修复
void rbtree_fix_up(RBTree tree, RBNode node);

RBTree init_rbtree()
{
    RBTree tree = (RBTree)malloc(sizeof(RBTree));
    if (tree == NULL)
    {
        printf("red black tree init error : 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

// 创建节点

RBNode createNode(const int data)
{
    RBNode node = (RBNode)malloc(sizeof(RBNode));
    if (node == NULL)
    {
        printf("createNode error : 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    //创建新节点 颜色 初始化为红色
    node->color = RED;
    node->data = data;
    node->left = node->right = node->parent = NULL;
    return node;
}

// 右旋
void rotate_right(RBTree tree, RBNode node)
{
    // 获取当前旋转节点的左节点
    RBNode leftNode = node->left;
    // 将获取到的左节点的右节点赋值给当前旋转节点的左节点
    node->left = leftNode->right;

    // 如果右节点不为空的化 将右节点的父节点执行 当前旋转节点 node
    if (leftNode->right != NULL)
    {
        leftNode->right->parent = node;
    }
    if (node->parent == NULL)
    { //说明是根节点
        tree->root = leftNode;
    }
    else if (node == node->parent->left)
    {
        // 说明node 是其父节点的左孩子
        node->parent->left = leftNode;
    }
    else
    {
        // node是其父节点的右孩子
        node->parent->right = leftNode;
    }
    // 将 node  设置为其左孩子的右子树
    leftNode->right = node;
    // 将node的父节点指向 left 节点
    node->parent = leftNode;
};

// 左旋 和右旋是相反的
void rotate_left(RBTree tree, RBNode node)
{
    RBNode rightNode = node->right;
    node->right = rightNode->left;
    if (rightNode->left != NULL)
    {
        rightNode->left->parent = node;
    }
    if (node->parent == NULL)
    {
        tree->root = rightNode;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = rightNode;
    }
    else
    {
        node->parent->left = rightNode;
    }

    rightNode->left = node;
    node->parent = rightNode;
};

// 插入
void insert(RBTree tree, const int data)
{

    if (tree != NULL)
    {
        RBNode node = createNode(data);
        tree->root = bs_insert(node, tree->root, NULL);
    }
};

// 二叉树插入
RBNode bs_insert(RBNode node, RBNode root, RBNode parent)
{
    if (root == NULL)
    {

        node->parent = parent;
        return node;
    }
    if (root->data > node->data)
    {
        root->left = bs_insert(node, root->left, root);
    }
    else if (root->data < node->data)
    {
        root->right = bs_insert(node, root->right, root);
    }
    return root;
};

// 红黑树 修复
void rbtree_fix_up(RBTree tree, RBNode node)
{
    while (node != tree->root && node->parent != NULL && node->parent->color == RED)
    {
        puts("===================");
        if (node->parent->parent == NULL)
            return;
        // 左子树
        if (node->parent == node->parent->parent->left)
        {
            RBNode rightNode = node->parent->parent->right;
            if (rightNode->color == RED)
            {
                node->parent->color = BLACK;
                rightNode->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {

                if (node == node->parent->right)
                {
                    node = node->parent;
                    rotate_left(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotate_right(tree, node->parent->parent);
            }
        }
        else if (node->parent == node->parent->parent->right)
        {
            // 右子树

            RBNode leftNode = node->parent->parent->left;
            if (leftNode->color == RED)
            {
                node->parent->color = BLACK;
                leftNode->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rotate_right(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotate_left(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
};

void print(RBNode node)
{
    if (node!=NULL)
    {
        print(node->left);
        printf("-----data = %d\n", node->data);
        print(node->right);
    }
}
#endif //RED_BLACK_TREE_H