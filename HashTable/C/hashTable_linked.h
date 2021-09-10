// hash table 分离链式法
#ifndef HASH_TABLE_LINKED_H
#define HASH_TABLE_LINKED_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int Index;

struct Entry;
struct HashTable;

typedef struct Entry *entry;
typedef struct HashTable *table;

struct Entry
{
    int data;
    char *key;
    entry next;
};
//
struct HashTable
{
    /* data */
    int tableSize;
    entry *list;
};
// 哈希函数
Index hash(const char *key, const int tableSize);

// 创建节点
entry createEntry(char *key, const int data);
// 初始化hash table
table initTable(unsigned int size);
// 销毁表
void destroyTable(table h);

// 查找
int find(char *key, table h);            //查找数据
entry findEntry(char *key, table h);     // 查找entry
entry findPrevEntry(char *key, table h); //查找给定key的前一个entry;
// 插入

void insert(char *key, int data, table h);

// 删除
void removeEntry(char *key, table h);

// 打印table
void printTable(table h);

Index hash(const char *key, const int tableSize)
{

    unsigned int hashVal = 0;
    while (*key != '\0')
        hashVal = (hashVal << 5) + *key++;
    return hashVal % tableSize;
}

entry createEntry(char *key, const int data)
{
    entry node = (entry)malloc(sizeof(struct Entry));
    if (node == NULL)
    {
        printf("error: createEntry mem fail! \n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->key = key;
    node->next = NULL;
    return node;
};
// 初始化hash table
table initTable(unsigned int size)
{
    table h;
    h = (table)malloc(sizeof(struct HashTable));
    if (h == NULL)
    {
        printf("error: initTable mem fail! \n");
        exit(EXIT_FAILURE);
    }
    h->tableSize = size;
    h->list = (entry *)malloc(sizeof(entry) * h->tableSize);
    if (h->list == NULL)
    {
        printf("error: initTable list mem fail! \n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        /* code */
        h->list[i] = createEntry(NULL, -1);
    }
    return h;
};

// 插入

void insert(char *key, int data, table h)
{
    if (h == NULL || key == NULL)
        return;
    entry node;
    Index idx = hash(key, h->tableSize);
    printf("insert hash key = %s,hash value = %d \n", key, idx);
    node = h->list[idx];
    if (node->next == NULL)
    {
        node->next = createEntry(key, data);
    }
    else
    {
        node = node->next;
        while (node->next && strcmp(node->key, key) != 0)
        {
            /* code */
            node = node->next;
        }
        if (strcmp(node->key, key) == 0)
        {
            node->data = data;
        }
        else
        {
            node->next = createEntry(key, data);
        }
    }
};

// 查找
int find(char *key, table h)
{

    entry node = findEntry(key, h);
    if (node != NULL && strcmp(node->key, key) == 0)
    {
        return node->data;
    }

    return -1;
};

entry findPrevEntry(char *key, table h)
{
    if (h == NULL || key == NULL)
        return NULL;
    Index idx = hash(key, h->tableSize);

    entry node = h->list[idx];

    if (node == NULL || node->next == NULL)
    {
        return NULL;
    }
    while (node && node->next && strcmp(node->next->key, key) != 0)
    {
        node = node->next;
        /* code */
    }
    return node;
};
entry findEntry(char *key, table h)
{
    entry node = findPrevEntry(key, h);
    if (node != NULL)
        return node->next;
    return NULL;
};
// 删除
void removeEntry(char *key, table h)
{
    entry node = findPrevEntry(key, h);
    if (node != NULL)
    {
        entry temp = node->next;
        node->next = temp->next;
        free(temp);
        temp = NULL;
    }
};
// 销毁表
void destroyTable(table h)
{
    if (h != NULL)
    {
        for (size_t i = 0; i < h->tableSize; i++)
        {
            entry node = h->list[i];
            entry temp;
            while (node != NULL)
            {
                temp = node;
                node = node->next;
                free(temp);
                /* code */
            }
        }
        free(h->list);
        free(h);
        h = NULL;
    }
};
void printTable(table h)
{
    if (h == NULL)
        return;
    for (size_t i = 0; i < h->tableSize; i++)
    {
        printf("---------------------------print table row = %lu\n", i);
        entry node = h->list[i];
        if (node->next != NULL)
        {
            node = node->next;
            while (node)
            {
                printf("{ %s : %d } \n", node->key, node->data);
                /* code */
                node = node->next;
            }
        }
    }
};

#endif //HASH_TABLE_LINKED_H