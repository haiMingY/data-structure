/**
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

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
    // 哨兵节点
    RBNode nil;
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

// 删除
void delete (RBTree tree, const int data);

// 将child 置换到 node 的位置
void transplant(RBTree tree, RBNode node, RBNode child);
// 二叉树插入
RBNode bs_insert(RBNode node, RBNode root, RBNode parent, RBNode nil);
// 查找
RBNode find(RBTree tree, RBNode node, const int data);
RBNode findMin(RBTree tree, RBNode node);
// 红黑树 修复
void rbtree_insert_fix_up(RBTree tree, RBNode node);
void rbtree_delete_fix_up(RBTree tree, RBNode node);

RBTree init_rbtree()
{
    RBTree tree;
    tree = (RBTree)malloc(sizeof(struct RedBlackTree));
    if (tree == NULL)
    {
        printf("red black tree init error : 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    tree->nil = createNode(-1);
    tree->nil->color = BLACK;
    return tree;
}

// 创建节点

RBNode createNode(const int data)
{
    RBNode node = (RBNode)malloc(sizeof(struct RedBlackNode));
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
    if (leftNode->right != tree->nil)
    {
        leftNode->right->parent = node;
    }
    // 将左节点的父节点指向 当前旋转节点的父节点
    leftNode->parent = node->parent;

    if (node->parent == tree->nil)
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
    if (rightNode->left != tree->nil)
    {
        rightNode->left->parent = node;
    }
    rightNode->parent = node->parent;
    if (node->parent == tree->nil)
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
        node->left = node->parent = node->right = tree->nil;
        tree->root = bs_insert(node, tree->root, tree->nil, tree->nil);
        rbtree_insert_fix_up(tree, node);
    }
};

// 二叉树插入
RBNode bs_insert(RBNode node, RBNode root, RBNode parent, RBNode nil)
{
    if (root == NULL || root == nil)
    {

        node->parent = parent;
        return node;
    }
    if (root->data > node->data)
    {
        root->left = bs_insert(node, root->left, root, nil);
    }
    else if (root->data < node->data)
    {
        root->right = bs_insert(node, root->right, root, nil);
    }
    return root;
};

// 查找

RBNode find(RBTree tree, RBNode node, const int data)
{
    if (node == NULL || tree == NULL || node == tree->nil)
        return NULL;

    if (node->data > data)
    {
        return find(tree, node->left, data);
    }
    else if (node->data < data)
    {
        return find(tree, node->right, data);
    }
    else
    {
        return node;
    }
}
// 查找最小的节点
RBNode findMin(RBTree tree, RBNode node)
{
    while (node && node != tree->nil && node->left != tree->nil)
    {
        node = node->left;
    }
    return node;
};
// 将child 置换到 node 的位置
void transplant(RBTree tree, RBNode node, RBNode child)
{
    if (tree == NULL || node == NULL)
        return;
    if (node->parent == tree->nil)
    {
        tree->root = child;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = child;
    }
    else
    {
        node->parent->right = child;
    }
    if (child != NULL)
    {
        child->parent = node->parent;
    }
};

// 删除
void delete (RBTree tree, const int data)
{
    RBNode node = find(tree, tree->root, data);
    RBNode temp = node;
    Color originalColor = temp->color;
    RBNode x;
    if (node->left == tree->nil)
    {
        x = node->right;
        transplant(tree, node, node->right);
    }
    else if (node->right == tree->nil)
    {
        x = node->left;
        transplant(tree, node, node->left);
    }
    else
    {
        temp = findMin(tree, node->right);
        originalColor = temp->color;
        x = temp->right;
        if (temp->parent == node)
        {
            if (x)
            {

                x->parent = temp;
            }
        }
        else
        {
            transplant(tree, temp, temp->right);
            temp->right = node->right;
            temp->right->parent = temp;
        }
        transplant(tree, node, temp);
        temp->left = node->left;
        node->left->parent = temp;
        temp->color = node->color;
    }
    if (originalColor == BLACK)
    {
        rbtree_delete_fix_up(tree, x);
    }
};

// 红黑树 修复
void rbtree_insert_fix_up(RBTree tree, RBNode node)
{
    // 当node->parent的颜色为黑色时或者node是根节点时（因为node为根节点是只有可能违反第二条性质，但在代码最后有将根节点标记为黑色）终止循环
    while (node != tree->root && node->parent->color == RED)
    {
        // node->parent 是node祖父的节点的左子树
        if (node->parent == node->parent->parent->left)
        {
            // 所以它的叔叔节点就是其祖父节点的右子树
            RBNode rightNode = node->parent->parent->right;
            //对应情况1 node的父节点和node的叔叔节点都是红色
            if (rightNode->color == RED)
            {
                // 将node 节点的父节点和叔叔节点都标记为黑色
                node->parent->color = BLACK;
                rightNode->color = BLACK;
                // 将node 的祖父节点标记为红色
                node->parent->parent->color = RED;
                // 用node 的祖父节点开始新的循环
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
        else
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
void rbtree_delete_fix_up(RBTree tree, RBNode node)
{
    while (node && node != tree->root && node->color == BLACK)
    {
        if (node == node->parent->left)
        {
            RBNode brother = node->parent->right;
            if (brother->color == RED)
            {
                brother->color = BLACK;
                node->parent->color = RED;
                rotate_left(tree, node->parent);
                brother = node->parent->right;
            }
            if (brother->left->color == BLACK && brother->right->color == BLACK)
            {
                brother->color = RED;
                node = node->parent;
            }
            else if (brother->right->color == BLACK)
            {
                brother->left->color = BLACK;
                brother->color = RED;
                rotate_right(tree, brother);
                brother = node->parent->right;
            }
            brother->color = node->parent->color;
            node->parent->color = BLACK;
            brother->right->color = BLACK;
            rotate_left(tree, node->parent);
        }
        else
        {
            RBNode brother = node->parent->left;
            if (brother->color == RED)
            {
                brother->color = BLACK;
                node->parent->color = RED;
                rotate_right(tree, node->parent);
                brother = node->parent->left;
            }
            if (brother->left->color == BLACK && brother->right->color == BLACK)
            {
                brother->color = RED;
                node = node->parent;
            }
            else if (brother->left->color == BLACK)
            {
                brother->right->color = BLACK;
                brother->color = RED;
                rotate_left(tree, brother);
                brother = node->parent->left;
            }
            brother->color = node->parent->color;
            node->parent->color = BLACK;
            brother->left->color = BLACK;
            rotate_right(tree, node->parent);
        }
        node = tree->root;
    }
};

void print(RBNode nil, RBNode node)
{
    if (node != NULL && node != nil)
    {
        printf("-----data = %d\n", node->data);
        print(nil, node->left);
        print(nil, node->right);
    }
}
#endif //RED_BLACK_TREE_H