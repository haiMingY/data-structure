
#include <stdlib.h>
#include "doubly_linked_list.h"

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