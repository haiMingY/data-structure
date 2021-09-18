#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
struct adjacency_matrix;
typedef struct adjacency_matrix *graph;

struct adjacency_matrix
{
    // 存储数据的矩阵指针
    int **matrixs;
    // 矩阵的大小
    int size;
};

// 创建一个邻接矩阵 size 矩阵的大小

graph createGraph(const int size);

// 添加 顶点 u 和顶点v 的边
void addEdge(graph g, int u, int v);

// 检测是不是边
int isEdge(graph g, int u, int v);

// 检测参数
int checkEdgeParams(graph g, int u, int v);

// 广度优先搜索
void bfs(const graph g, int vertex);

// 深度优先搜索 辅助函数
void dfs_internal(const graph g, int vertex, int *visited);
// 深度优先搜索
void dfs(const graph g, int vertex);

// 打印邻接矩阵
void printGraph(const graph g);

// 销毁
void destroy(graph g);

int *intdup(int value)
{
    int *dup = (int *)malloc(sizeof(int));
    *dup = value;
    return dup;
}
graph createGraph(const int size)
{

    graph set = (graph)malloc(sizeof(struct adjacency_matrix));
    int **matrixs = (int **)malloc(sizeof(int *) * size);
    if (set == NULL || matrixs == NULL)
    {
        printf("malloc error : createGraph \n");
        exit(EXIT_FAILURE);
    }
    set->size = size;
    set->matrixs = matrixs;
    for (int i = 0; i < size; i++)
    {
        matrixs[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            matrixs[i][j] = 0;
        }
    }

    return set;
};
// 添加 顶点 u 和顶点v 的边
void addEdge(graph g, int u, int v)
{
    if (checkEdgeParams(g, u, v))

    {
        g->matrixs[u - 1][v - 1] = 1;
        g->matrixs[v - 1][u - 1] = 1;
    }
};
// 检测参数
int checkEdgeParams(graph g, int u, int v)
{
    return g != NULL && g->size >= u && g->size >= v & u > 0 && v > 0;
}

// 检测是不是边
int isEdge(graph g, int u, int v)
{
    if (g != NULL && g->size > u && g->size > v & u >= 0 && v >= 0)
    {
        return g->matrixs[u][v];
    }
    return 0;
};
// 打印邻接矩阵
void printGraph(const graph g)
{
    if (g != NULL)
    {
        for (size_t i = 0; i < g->size; i++)
        {
            for (size_t j = 0; j < g->size; j++)
            {
                /* code */
                printf("%d  ", g->matrixs[i][j]);
            }
            printf("\n");
        }
    }
};
// 深度优先搜索 辅助函数
void dfs_internal(const graph g, int vertex, int *visited)
{
    if (visited[vertex - 1])
        return;
    visited[vertex - 1] = 1;
    printf("-----vertex = %d \n", vertex);
    for (int i = 0; i < g->size; i++)
    {
        if (!visited[i] && isEdge(g, vertex - 1, i))
        {
            dfs_internal(g, i + 1, visited);
        }
    }
};
// 深度优先搜索
void dfs(const graph g, int vertex)
{
    int *visited = (int *)malloc(sizeof(int) * g->size);
    memset(visited, 0, sizeof(int) * g->size);
    dfs_internal(g, vertex, visited);
    free(visited);
};
// 广度优先搜索
void bfs(const graph g, int vertex)
{
    if (g != NULL)
    {
        int *visited = (int *)malloc(sizeof(int) * g->size);
        memset(visited, 0, sizeof(int) * g->size);

        queue q = queue_new();
        enqueue(q, intdup(vertex));
        while (!isEmpty(q))
        {
            int *v = (int *)dequeue(q);
            int row = *v - 1;
            if (!visited[row])
            {
                visited[row] = 1;

                printf("-----vertex = %d \n", *v);

                for (int i = 0; i < g->size; i++)
                {
                    if (!visited[i] && isEdge(g, row, i))
                    {
                        enqueue(q, intdup(i + 1));
                    }
                }
            }
            free(v);
        }
        queue_free(q);
        q = NULL;
        free(visited);
    }
};
// 销毁
void destroy(graph g)
{
    if (g != NULL)
    {
        for (size_t i = 0; i < g->size; i++)
        {
            free(g->matrixs[i]);
        }
        free(g->matrixs);
        free(g);
    }
};

#endif //GRAPH_H