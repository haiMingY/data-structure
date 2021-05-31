
#include "LinkListNode.h"

struct LinkListNode *create_llnode(const int value)
{
    struct LinkListNode *node = (struct LinkListNode *)malloc(sizeof(struct LinkListNode));
    node->data = value;
    node->next = NULL;
    return node;
};