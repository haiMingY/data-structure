
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkList.h"

int LT(int i, int pos)
{
    return i < pos;
}

int LTEQ(int i, int pos)
{
    return i <= pos;
}

struct LinkList *create_list()
{
    struct LinkList *l = (struct LinkList *)malloc(sizeof(struct LinkList));
    l->size = 0;
    l->head = NULL;
    return l;
};

void printList(struct LinkList *list)
{
    assert(list != NULL);
    struct LinkListNode *curr = list->head;
    while (curr != NULL)
    {
        /* code */
        printf("data = %d\n", curr->data);
        curr = curr->next;
    }
    printf("list size = %d \n", list->size);
};
// 尾部添加
int push(struct LinkList *list, int value)
{
    assert(list != NULL);
    struct LinkListNode *node = create_llnode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    list->size += 1;

    return 0;
};
// 尾部移除
int pop(struct LinkList *list)
{
    assert(list != NULL);
    if (list->tail == NULL && list->head == NULL)
        return EXIT_FAILURE;
    struct LinkListNode *node = list->tail;
    switch (list->size)
    {
    case 1:
        list->tail = list->head = NULL;
        break;
    case 2:
        list->tail = list->head;
        list->tail->next = NULL;
        break;
    default:
        struct LinkListNode *prevNode = findNodeByPos(list, list->size - 2, LTEQ);
        assert(prevNode != NULL);
        list->tail = prevNode;
        prevNode->next = NULL;
        break;
    }
    list->size--;
    free(node);
    return 0;
}

// 头部添加
int unshift(struct LinkList *list, int value)
{
    assert(list != NULL);
    struct LinkListNode *node = create_llnode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }

    list->size += 1;
    return 0;
}

// 头部移除
int shift(struct LinkList *list)
{
    assert(list != NULL);
    if (list->head == NULL)
        return 0;
    struct LinkListNode *node = list->head;
    if (list->size == 1)
    {
        list->head = list->tail = NULL;
    }
    list->head = node->next;
    if (node != NULL)
        free(node);
    list->size--;
    return 0;
}
//链表翻转
void reverse(struct LinkList *list)
{
    assert(list != NULL);
    struct LinkListNode *curr = list->head;
    struct LinkListNode *next = NULL, *prev = NULL;
    while (curr != NULL)
    {
        // 保存下一个指针
        next = curr->next;
        // 将 curr 节点的next 指针指向 prev 指针
        curr->next = prev;
        // 将当前节点 指向 prev 指针
        prev = curr;
        curr = next; // 指向下一个节点
    }
    list->head = prev;
}
//递归链表翻转
void reverseByRecursion(struct LinkList *list)
{
    assert(list != NULL && list->head != NULL);
    list->head = _recursion(list->head);
}

struct LinkListNode *_recursion(struct LinkListNode *node)
{
    if (node->next == NULL)
        return node;
    struct LinkListNode *temp = _recursion(node->next);
    node->next->next = node;
    node->next = NULL;
    return temp;
}

// 将数据插入制定位置之后
int insertAfter(struct LinkList *list, int value, int pos)
{
    assert(list != NULL);
    assert(list->size > pos);
    struct LinkListNode *node = create_llnode(value);
    struct LinkListNode *curr = findNodeByPos(list, pos, LT);
    if (curr != NULL)
    {
        node->next = curr->next;
        curr->next = node;
        list->size++;
    }
    else
    {
        free(node);
    }

    return 0;
}
// 将数据插入制定位置之后
int insertBefore(struct LinkList *list, int value, int pos)
{
    assert(list != NULL);
    assert(list->size > pos);
    struct LinkListNode *node = create_llnode(value);
    struct LinkListNode *curr = findNodeByPos(list, pos - 1, LT);
    if (curr != NULL)
    {
        node->next = curr->next;
        curr->next = node;
        list->size++;
    }
    else
    {
        free(node);
    }

    return 0;
}
//移除某一位置的节点
int removeNode(struct LinkList *list, int pos)
{
    assert(list != NULL);
    assert(pos < list->size);
    struct LinkListNode *curr = findNodeByPos(list, pos - 1, LT);
    struct LinkListNode *temp = curr->next;
    curr->next = temp->next;
    free(temp);
    temp = NULL;
    return 0;
};
struct LinkListNode *findNodeByPos(struct LinkList *list, int pos, compare com)
{
    struct LinkListNode *curr = list->head;
    for (size_t i = 0; com(i, pos) && curr != NULL; i++)
    {
        /* code */
        curr = curr->next;
    }
    return curr;
}
//获取中间节点使用双指针
int findMiddleByDubblePoint(struct LinkList *list)
{
    struct LinkListNode *onePtr = list->head;
    struct LinkListNode *twoPtr = list->head;
    while (twoPtr != NULL && twoPtr->next != NULL)
    {
        onePtr = onePtr->next;
        twoPtr = twoPtr->next->next;
    }
    printf(" find mid dp num = %d\n", onePtr->data);
    return 0;
}
//获取中间节点使用length
int findMiddleByLength(struct LinkList *list)
{
    int middle = list->size >> 1;
    struct LinkListNode *curr = list->head;
    for (size_t i = 0; i < middle; i++)
    {
        /* code */
        curr = curr->next;
    }
    printf(" find mid len  num = %d\n", curr->data);
    return 0;
}
