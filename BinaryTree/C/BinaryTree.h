#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode BinaryTreeNode;
typedef BinaryTreeNode *PtrNode;
struct TreeNode
{
    /* data */
    int data;
    PtrNode left;
    PtrNode right;
};

// 二叉树
typedef struct _BinaryTree BinaryTree;
struct _BinaryTree
{
    /* data */
    PtrNode root;
};
// 插入
PtrNode insert(PtrNode node, const int data);
// 后序遍历
void postOrder(PtrNode node);
// 先序遍历
void preOrder(PtrNode node);
// 中序遍历
void inOrder(PtrNode node);
// 层序遍历 也是 BFS
void levelorder(PtrNode node);
// 打印当前层级
void currentLevel(PtrNode node, int level);

// 获取高度
int height(PtrNode node);
PtrNode createTreeNode(const int data)
{
    PtrNode node;
    node = (PtrNode)malloc(sizeof(node));
    if (node == NULL)
    {
        printf("BinaryTreeNode 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    node->left = node->right = NULL;
    node->data = data;
    return node;
};

// 创建树

BinaryTree *createBinaryTree()
{
    BinaryTree *tree;
    tree = (BinaryTree *)malloc(sizeof(tree));
    if (tree == NULL)
    {
        printf("BinaryTree 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

// 插入数据
PtrNode insert(PtrNode node, const int data)
{

    if (node == NULL)
    {
        node = createTreeNode(data);
    }
    else if (node->data < data)
    {
        node->right = insert(node->right, data);
    }
    else if (node->data > data)
    {
        node->left = insert(node->left, data);
    }
    return node;
}

// 后续遍历
void postOrder(PtrNode node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf(" node data = %d\n", node->data);
    }
};
// 先序遍历
void preOrder(PtrNode node)
{
    if (node != NULL)
    {
        printf(" node data = %d\n", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}
// 中序遍历
void inOrder(PtrNode node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf(" node data = %d\n", node->data);
        inOrder(node->right);
    }
}
// 层序遍历
void levelorder(PtrNode node)
{
    int h = height(node);
    int i;
    for (i = 0; i < h; i++)
    {
        /* code */
        currentLevel(node, i);
    }
}

void currentLevel(PtrNode node, int level)
{
    if (node != NULL)
    {
        if (level == 1)
        {
            printf("level order data = %d\n", node->data);
        }
        else if (level > 1)
        {

            currentLevel(node->left, level - 1);
            currentLevel(node->right, level - 1);
        }
    }
};

int height(PtrNode node)
{
    if (node == NULL)
    {
        return 0;
    };
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    // 获取较大的值
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}