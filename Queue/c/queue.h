#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// 队列
struct Queue;
struct QueueNode;
typedef void *queueValue;
typedef struct QueueNode *queueNode;
typedef struct Queue *queue;

struct QueueNode
{
    queueValue data;
    queueNode next;
    queueNode prev;
};

struct Queue
{
    queueNode tail;
    queueNode head;
    unsigned int length;
    /* data */
};

// 创建一个新的队列
queue queue_new();
// 创建一个节点
queueNode queue_node_new(queueValue value);

// 释放队列
void queue_free(queue q);

// 是不是为空
int isEmpty(queue q);

// 入队列
void enqueue(queue q, queueValue value);

// 出队列
queueValue dequeue(queue q);

// 创建一个新的队列
queue queue_new()
{
    queue q = (queue)malloc(sizeof(struct Queue));
    if (q == NULL)
    {
        puts("queue_new malloc error!");
        exit(EXIT_FAILURE);
    }
    q->head = q->tail = NULL;
    q->length = 0;
    return q;
};
// 创建一个节点
queueNode queue_node_new(queueValue value)
{
    queueNode q = (queueNode)malloc(sizeof(struct QueueNode));
    if (q == NULL)
    {
        puts("queue_node_new malloc error!");
        exit(EXIT_FAILURE);
    }
    q->next = q->prev = NULL;
    q->data = value;
    return q;
}
// 释放队列
void queue_free(queue q)
{
    if (q != NULL)
    {
        queueNode temp;
        while (q->head)
        {
            temp = q->head;
            q->head = q->head->next;
            free(temp);
        }
        free(q);
    }
};
// 是不是为空
int isEmpty(queue q)
{
    return q == NULL || q->length == 0;
};

// 入队列
void enqueue(queue q, queueValue value)
{
    if (q != NULL)
    {
        queueNode node = queue_node_new(value);
        if (q->head == NULL)
        {
            q->head = q->tail = node;
        }
        else
        {
            q->tail->next = node;
            node->prev = q->tail;
            q->tail = node;
        }

        q->length++;
    }
};

// 出队列
queueValue dequeue(queue q)
{
    if (q != NULL && q->length)
    {
        queueNode node = q->head;
        q->head = node->next;

        if (q->head == NULL)
        {
            q->tail = NULL;
        }
        else
        {
            q->head->prev = NULL;
        }

        queueValue v = node->data;
        free(node);
        q->length--;
        return v;
    }
    return NULL;
};

void printQueue(queue q)
{
    if (q)
    {
        queueNode n = q->head;
        while (n)
        {
            printf(" queue value = %d \n", *(int *)n->data);
            /* code */
            n = n->next;
        }
    }
}
#endif // QUEUE_H