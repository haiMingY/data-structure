#include <stdlib.h>
#include <assert.h>

#include "list_node.h"

struct list_node *create_node(const int data)
{
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    return node;
}