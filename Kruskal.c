#include <stdlib.h>
#include "SSTMin.h"

//function to compare two edge by their weight (used for qsort)
int compareByWeight (edge_t* a, edge_t* b) {
    return a->weight > b->weight;
}

edge_t* spanningSubTree (graph_t* graph) {
    if (graph == NULL || graph->nodeCount < 2) {
        return;
    }
    edge_t* subTree[graph->nodeCount - 1];
    //index of the result subtree
    int subIndex = 0;
    //sort the edges by their weight
    qsort(graph->edges, graph->edgeCount, sizeof(graph->edges[0]), compareByWeight);
    //create and initialize parent nodes for each node in the graph (set their parent node as themselves)
    int parents[graph->nodeCount];
    for (int i = 0; i < graph->nodeCount; i++) {
        parents[i] = i;
    }
    edge_t* currEdge;
    //Check every sorted edge and add them to result if valid
    for (int i = 0; i < graph->edgeCount; i++) {
        currEdge = graph->edges[i];
        if (parents[currEdge->start] != parents[currEdge->des]) {
            //set destination node's parent as start node
            parents[currEdge->des] = currEdge->start;
            //add edge to the result
            subTree[subIndex] = currEdge;
            subIndex++;
        }
        //end subtree generation
        if (subIndex == graph->nodeCount) {
            break;
        }
    }
    return subTree;
}

void freeGraph(graph_t* graph) {
    if (graph == NULL) {
        return;
    }
    for (int i = 0; i < graph->edgeCount; i++) {
        free(graph->edges[i]);
    }
    free(graph);
}