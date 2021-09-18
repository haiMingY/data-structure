/**
 * 邻接表 
 * 
 * 
 * 
 */

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#define vertex_exist(vertex, value)              \
    if (vertex == NULL)                          \
    {                                            \
        printf("%s vertex is not exist", value); \
        return;                                  \
    }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

struct adjacency_list;
struct adjacency_list_node;
struct adjacency_list_edge;
typedef struct adjacency_list *graph;
typedef struct adjacency_list_node *vertex;
typedef struct adjacency_list_edge *edge;
typedef void *value;
struct adjacency_list
{
    // 顶点个数
    unsigned int vertex_size;
    // 总边数
    unsigned int edge_size;
    // 表的大小
    unsigned int length;
    // 下一个节点
    vertex *head;
};
struct adjacency_list_node
{
    // 值
    value data;
    // 边数
    unsigned int edge_size;
    // 顶点的边
    edge edges;
    // 下一个节点
    vertex next;
    // 已经遍历
    short visited;
};

struct adjacency_list_edge
{
    double weight;

    // 目标节点
    vertex dest;
    // 下一个 边
    edge next;
};

char *char_dup(char value)
{
    char *dup = (char *)malloc(sizeof(char));
    *dup = value;
    return dup;
}

void checkMemory(value any, const char *s)
{
    if (any == NULL)
    {
        printf("%s\n", s);
        exit(EXIT_FAILURE);
    }
};

int hash(const char *key, const int size);

// 生成 邻接表
graph graph_new_list(unsigned int const length);
// 生成顶点节点
vertex vertex_new(value v);
// 生成边
edge edge_new(vertex dest);
// 添加顶点
void addVertex(graph g, value v);
// 添加边
void addEdge(graph g, value src, value dest);

// 查找顶点
vertex findVertex(graph g, value vertex);

void reset_visited(graph g);

// 深度优先搜索
void dfs(graph g, value vertex);
// 深度优先搜索 辅助函数
void dfs_internal(graph g, vertex v);

// 广度优先收所
void bfs(graph g, value v);

// 打印边
void printEdge(edge e);
// 哈希
int hash(const char *key, const int size)
{

    return *key % size;
};
// 生成 邻接表
graph graph_new_list(unsigned int const length)
{
    graph g = (graph)malloc(sizeof(struct adjacency_list));
    checkMemory(g, "graph_new_list memory error ");
    g->edge_size = 0;
    g->vertex_size = 0;
    g->length = length;
    g->head = malloc(sizeof(struct adjacency_list_node) * length);
    checkMemory(g->head, "graph_new_list memory error ");
    return g;
};
// 生成顶点节点
vertex vertex_new(value v)
{
    vertex v_node = (vertex)malloc(sizeof(struct adjacency_list_node));
    checkMemory(v_node, "vertex_new memory error ");
    v_node->data = v;
    v_node->visited = 0;
    return v_node;
};

// 生成边
edge edge_new(vertex dest)
{
    edge e = (edge)malloc(sizeof(struct adjacency_list_edge));
    checkMemory(e, "edge_new memory error ");
    e->dest = dest;
    e->next = NULL;
    e->weight = 0;
    return e;
};

// 添加顶点
void addVertex(graph g, value v)
{
    if (g != NULL)
    {
        vertex newVertex = vertex_new(v);
        int index = hash(v, g->length);
        if (g->head[index] == NULL)
        {
            g->head[index] = newVertex;

            g->vertex_size++;
        }
        else
        {
            printf("%s hash value = %d is extised\n", v, index);
        }
    }
};

// 添加边
void addEdge(graph g, value src, value dest)
{
    if (g != NULL && g->head != NULL)
    {
        int srcIndex = hash(src, g->length);
        int destIndex = hash(dest, g->length);
        vertex srcVertex = g->head[srcIndex], destVertex = g->head[destIndex];

        vertex_exist(srcVertex, src);
        vertex_exist(destVertex, dest);

        edge e = edge_new(destVertex);
        if (srcVertex->edges == NULL)
        {
            srcVertex->edges = e;
        }
        else
        {
            edge tempEdge = srcVertex->edges;
            while (tempEdge->next)
            {
                tempEdge = tempEdge->next;
            }
            tempEdge->next = e;
        }
        srcVertex->edge_size++;
        g->edge_size++;
    }
};
// 查找顶点
vertex findVertex(graph g, value v)
{
    if (g != NULL)
    {
        int index = hash(v, g->length);
        return g->head[index];
    }

    return NULL;
};
// 重置 visited 字段的字为0
void reset_visited(graph g)
{
    if (g != NULL)
    {
        for (size_t i = 0; i < g->length; i++)
        {
            if (g->head[i])
            {

                g->head[i]->visited = 0;
            }
        }
    }
};
// 深度优先搜索
void dfs(graph g, value v)
{
    vertex current = findVertex(g, v);
    if (current == NULL)
    {
        puts("not find vertex");
        return;
    }
    dfs_internal(g, current);
    reset_visited(g);
};
// 深度优先搜索 辅助函数
void dfs_internal(graph g, vertex v)
{
    v->visited = 1;
    edge temp = v->edges;
    printf("dfs current vertex = %s \n", v->data);
    while (temp)
    {
        if (!temp->dest->visited)
        {
            dfs_internal(g, temp->dest);
        }
        temp = temp->next;
    }
};
// 广度优先收所
void bfs(graph g, value v)
{
    vertex current = findVertex(g, v);
    if (current == NULL)
    {
        puts("not find vertex");
        return;
    }

    queue q = queue_new();
    enqueue(q, current);

    while (!isEmpty(q))
    {
        vertex v = dequeue(q);
        if (!v->visited)
        {

            v->visited = 1;
            printf("bfs current value = %s \n", v->data);
            edge e = v->edges;
            while (e)
            {
                if (!e->dest->visited)
                {
                    enqueue(q, e->dest);
                }
                e = e->next;
            }
        }
    }
    queue_free(q);
    reset_visited(g);
};
void printGraph(graph g)
{
    if (g != NULL)
    {
        printf("total vertex size = %d ; total edge size = %d \n", g->vertex_size, g->edge_size);
        for (size_t i = 0; i < g->length; i++)
        {
            vertex temp = g->head[i];
            if (!temp)
                continue;
            printf("index:%lu === %s => ", i, temp->data);
            edge e = temp->edges;
            while (e)
            {
                if (e->dest != NULL)
                {

                    printf("%s ", e->dest->data);
                }
                e = e->next;
            }

            printf("\n");
            temp = temp->next;
        }
    }
}
#endif //ADJACENCY_LIST_H