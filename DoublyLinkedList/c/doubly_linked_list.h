#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H


#include <stdio.h>

struct list_node
{
    /* data */
    int data;
    struct list_node *next;
    struct list_node *prev;
};

struct list_node *create_node(const int data);

struct list_node *create_node(const int data)
{
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    return node;
}

typedef struct doubly_linked_list
{
    struct list_node *head;
    struct list_node *tail;
    int length; //长度
} DoublyLinkedList;

// 初始化list
DoublyLinkedList *initList();
// 将一个元素添加到链表的末尾，并返回该链表的新长度
int push(DoublyLinkedList *list, const int data);
// 删除最后一个元素，并返回该元素的值
void *pop(DoublyLinkedList *list);

struct list_node *getNode(int pos); // 获取指定位置的节点

void removeNode(DoublyLinkedList *list, int pos); //删除指定位置的元素

void reverse(DoublyLinkedList *list);// 翻转链表

//打印链表
void printList(DoublyLinkedList *list);

// 初始化
DoublyLinkedList *initList()
{
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
};

int push(DoublyLinkedList *list, const int data)
{
    struct list_node *node = create_node(data);
    if (list->tail == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->length += 1;
    return list->length;
};
// 删除最后一个元素，并返回该元素的值
void *pop(DoublyLinkedList *list)
{
    if (list->tail != NULL)
    {
        struct list_node *node = list->tail;
        if (list->tail == list->head)
        {
            list->head = list->tail = NULL;
            list->length = 0;
        }
        else
        {
            list->tail = node->prev;
            list->tail->next = NULL;
        }
        int data = node->data;
        free(node);
        list->length -= 1;
        int *p = &data;
        return p;
    }
    return NULL;
};
// 删除指定元素
void removeNode(DoublyLinkedList *list, int pos)
{
    if (list != NULL && pos < list->length)
    {
        struct list_node *prev = list->head;
        struct list_node *tail = list->tail;

        if (pos == 0 && list->head == list->tail)
        {
            list->head = list->tail = NULL;
            free(prev);
        }
        else if (pos == 0)
        {
            list->head = list->head->next;
            list->head->prev = NULL;
            free(prev);
        }
        else if (pos == list->length - 1)
        {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
            free(tail);
        }
        else
        {
            // 找到删除元素的前一个节点
            while (pos-- != 1)
            {
                prev = prev->next;
                /* code */
            }
            struct list_node *temp = prev->next;
            prev->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = prev;
            }
            free(temp);
            temp = NULL;
        }
        prev = tail = NULL;
        list->length--;
    }
};
// 翻转链表
void reverse(DoublyLinkedList *list)
{
    struct list_node *head = list->head;
    list->tail = head;
    struct list_node *prev = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->prev = next;
        head->next = prev;
        prev = head;
        head = next;
        /* code */
    }
    list->head = prev;
};

// 打印
void printList(DoublyLinkedList *list)
{
    struct list_node *temp = list->head;
    printf("--------------------------正序打印 length = %d\n", list->length);
    while (temp != NULL)
    {
        printf("----data = %d\n", temp->data);
        temp = temp->next;
        /* code */
    }
    printf("--------------------------倒序打印\n");
    temp = list->tail;
    while (temp != NULL)
    {
        printf("----data = %d\n", temp->data);
        temp = temp->prev;
        /* code */
    }
    puts("-------------------------------------------------------");
}
#endif //DOUBLY_LINKED_LIST_H