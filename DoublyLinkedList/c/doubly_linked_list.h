#pragma once
#include <stdio.h>

#include "list_node.h"

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
