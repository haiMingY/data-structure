#include <stdio.h>
// #include "adjacency_matrix.h"
#include "adjacency_list.h"

int main(int argc, char const *argv[])
{

    // graph g = createGraph(6);
    // addEdge(g, 1, 2);
    // addEdge(g, 1, 4);
    // addEdge(g, 2, 5);
    // addEdge(g, 3, 5);
    // addEdge(g, 3, 6);
    // addEdge(g, 4, 2);
    // addEdge(g, 5, 4);
    // addEdge(g, 6, 6);
    // addEdge(g, 6, 4);

    // printGraph(g);
    // dfs(g, 5);
    // puts("=================");
    // bfs(g, 6);

    graph g = graph_new_list(10);
    addVertex(g, char_dup('A'));
    addVertex(g, char_dup('B'));
    addVertex(g, char_dup('C'));
    addVertex(g, char_dup('D'));
    addVertex(g, char_dup('E'));
    addVertex(g, char_dup('F'));
    addVertex(g, char_dup('G'));
    addVertex(g, char_dup('H'));
    addEdge(g, char_dup('A'), char_dup('B'));
    addEdge(g, char_dup('A'), char_dup('D'));
    addEdge(g, char_dup('A'), char_dup('F'));
    addEdge(g, char_dup('B'), char_dup('C'));
    addEdge(g, char_dup('B'), char_dup('E'));
    addEdge(g, char_dup('C'), char_dup('D'));
    addEdge(g, char_dup('C'), char_dup('E'));
    addEdge(g, char_dup('C'), char_dup('F'));
    addEdge(g, char_dup('D'), char_dup('B'));
    addEdge(g, char_dup('D'), char_dup('G'));
    addEdge(g, char_dup('F'), char_dup('G'));
    addEdge(g, char_dup('E'), char_dup('A'));
    addEdge(g, char_dup('E'), char_dup('D'));
    addEdge(g, char_dup('G'), char_dup('A'));
    addEdge(g, char_dup('G'), char_dup('E'));
    printGraph(g);

    puts("=========================");
    dfs(g,char_dup('C'));

    puts("==========================");
    bfs(g,char_dup('C'));
    return 0;
}
