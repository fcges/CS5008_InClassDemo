#include <stdio.h>
#include <stdlib.h>
#include "SSTMin.h"

int main() {
    graph_t* graph = createGraph(5, 7);
    if (graph == NULL) {
        printf("Fail to create graph!");
        return 1;
    }
    //edge AB
    graph->edges[0]->start = 0;
    graph->edges[0]->des = 1;
    graph->edges[0]->weight = 5;
    //edge AC
    graph->edges[1]->start = 0;
    graph->edges[1]->des = 2;
    graph->edges[1]->weight = 2;
    //edge BC
    graph->edges[2]->start = 1;
    graph->edges[2]->des = 2;
    graph->edges[2]->weight = 4;
    //edge BD
    graph->edges[3]->start = 1;
    graph->edges[3]->des = 3;
    graph->edges[3]->weight = 9;
    //edge CD
    graph->edges[4]->start = 2;
    graph->edges[4]->des = 3;
    graph->edges[4]->weight = 3;
    //edge CE
    graph->edges[5]->start = 2;
    graph->edges[5]->des = 4;
    graph->edges[5]->weight = 15;
    //edge DE
    graph->edges[6]->start = 3;
    graph->edges[6]->des = 4;
    graph->edges[6]->weight = 12;
    
    edge_t** subTree = spanningSubTree(graph);
    if (subTree == NULL) {
        printf("Fail to generate subTree!");
        return 1;
    }

    //print result
    printf("Result:\n");
    for (int i = 0; i < graph->nodeCount - 1; i++) {
        printf("%d -> %d weight: %d\n", (subTree[i]->start), (subTree[i]->des), (subTree[i]->weight));
    }
    //free
    free(subTree);
    freeGraph(graph);
    return 0;
}