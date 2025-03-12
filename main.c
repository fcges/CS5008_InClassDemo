#include <stdio.h>
#include <stdlib.h>
#include "SSTMin.h"

int main() {
    graph_t* graph = createGraph(5, 7);
    //edge AB
    graph->edges[0]->start = 0;
    graph->edges[0]->des = 1;
    graph->edges[0]->weight = 5;
}