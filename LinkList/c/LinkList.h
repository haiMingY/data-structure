#pragma once

typedef int compare(int, int);

#include "LinkListNode.h"
struct LinkList
{
    struct LinkListNode *head;
    struct LinkListNode *tail;
    int size;
};

struct LinkList *create_list();             // 创建链表
int push(struct LinkList *list, int value); //链表末尾添加
int pop(struct LinkList *list);             //链表末尾移除

int unshift(struct LinkList *list, int value); //链表头部添加
int shift(struct LinkList *list);              //链表头部移除

int insertAfter(struct LinkList *list, int value, int pos);
int insertBefore(struct LinkList *list, int value, int pos);

int removeNode(struct LinkList *list, int pos); //移除某一位置的节点

void reverse(struct LinkList *list); //链表翻转

void printList(struct LinkList *list); //打印链表

int findMiddleByLength(struct LinkList *list);                                   //获取中间节点使用length
int findMiddleByDubblePoint(struct LinkList *list);                              //获取中间节点使用双指针
struct LinkListNode *findNodeByPos(struct LinkList *list, int pos, compare com); //查找节点
int LT(int i, int pos);
int LTEQ(int i, int pos);
