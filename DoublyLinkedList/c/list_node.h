#pragma once

struct list_node
{
    /* data */
    int data;
    struct list_node *next;
    struct list_node *prev;
};

struct list_node *create_node(const int data);
