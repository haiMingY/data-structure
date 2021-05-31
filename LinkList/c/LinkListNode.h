#pragma once

#include <stdlib.h>

struct LinkListNode
{
    int data;
    struct LinkListNode *next;
};

struct LinkListNode *create_llnode(const int value);

