#pragma once

#include "LinkListNode.h"
struct LinkList
{
    struct LinkListNode *head;
    struct LinkListNode *tail;
    int size;
};

struct LinkList *create_list();                  // 创建链表
int push(struct LinkList *list, int value);      //链表末尾添加
int pop(struct LinkList *list); //链表末尾移除

int unshift(struct LinkList *list, int value); //链表头部添加
int shift(struct LinkList *list);              //链表头部移除

int insertAfter(struct LinkList *list, int value, int pos);
int insertBefore(struct LinkList *list, int value, int pos);

void reverse(struct LinkList *list); //链表翻转

void printList(struct LinkList *list); //打印链表

static struct LinkListNode * findTailPrevNode(struct LinkList *list); //查看倒数第二个节点
