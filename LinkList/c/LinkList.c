
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkList.h"

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
    while (curr!=NULL)
    {
        /* code */
        printf("data = %d\n", curr->data);
        curr = curr->next;
    }
};

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
        struct LinkListNode *prevNode = findTailPrevNode(list);
        assert(prevNode != NULL);
        list->tail = prevNode;
        prevNode->next = NULL;
        break;
    }
    list->size--;
    free(node);
    return 0;
}

static struct LinkListNode *findTailPrevNode(struct LinkList *list)
{
    assert(list != NULL);
    struct LinkListNode *curr = list->head;
    while (curr != NULL && curr->next != NULL && curr->next->next != NULL)
    {
        curr = curr->next;
        /* code */
    };
    if (curr->next == list->tail)
    {
        return curr;
    }
    return NULL;
}