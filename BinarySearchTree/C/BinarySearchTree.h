#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode BinaryTreeNode;
typedef BinaryTreeNode *PtrNode;
typedef BinaryTreeNode *Position;
typedef BinaryTreeNode *SearchTree;

struct TreeNode
{
    /* data */
    int data;
    PtrNode left;
    PtrNode right;
};
PtrNode createTreeNode(const int data)
{
    PtrNode node;
    node = (PtrNode)malloc(sizeof(node));
    if (node == NULL)
    {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    node->left = node->right = NULL;
    node->data = data;
    return node;
};

// 查找指定数据的节点
Position find(int x, SearchTree tree);
// 获取最小节点
Position findMin(SearchTree tree);
// 获取最大节点
Position findMax(SearchTree tree);
// 插入
SearchTree insert(int x, SearchTree tree);
// 删除指定元素
SearchTree deleteEl(int x, SearchTree tree);

Position find(int x, SearchTree tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (x < tree->data)
    {
        return find(x, tree->left);
    }
    else if (x > tree->data)
    {
        return find(x, tree->right);
    }
    return tree;
}
// 递归查找左节点 为最小
Position findMin(SearchTree tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->left == NULL)
        return tree;
    return findMin(tree->left);
}
// 循环查找右节点 为最大
Position findMax(SearchTree tree)
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
// 插入数据
SearchTree insert(int data, SearchTree tree)
{
    if (tree == NULL)
    {
        tree = createTreeNode(data);
    }
    else if (tree->data < data)
    {
        tree->right = insert(data, tree->right);
    }
    else if (tree->data > data)
    {
        tree->left = insert(data, tree->left);
    }
    return tree;
}

void inOrder(PtrNode node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf(" node data = %d\n", node->data);
        inOrder(node->right);
    }
}

SearchTree deleteEl(int x, SearchTree tree)
{
    Position temp;
    if (tree != NULL)
    {
        // 二分查找
        if (tree->data > x)
        {
            tree->left = deleteEl(x, tree->left);
        }
        else if (tree->data < x)
        {
            tree->right = deleteEl(x, tree->right);
        }
        // 要删除的节点 两个子节点都不为空
        else if (tree->left && tree->right)
        {
            /* 找到最小的右侧子节点 替换到当前位置 */
            temp = findMin(tree->right);
            tree->data = temp->data;
            // 再将最小节点的删除
            tree->right = deleteEl(tree->data, tree->right);
        }
        else
        {
            // 这里可能是只有一个节点或者0个节点
            temp = tree;
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
    }
    return tree;
}