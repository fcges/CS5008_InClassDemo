#include <stdlib.h>
#include "SSTMin.h"

//function to compare two edge by their weight (used for qsort)
int compareByWeight (const void* a1, const void* b1) {
    edge_t* a = *(edge_t**)a1;
    edge_t* b = *(edge_t**)b1;
    return a->weight - b->weight;
}

void unionParents(int targetRoot, int changeRoot, int* parents, int length) {
    for (int i = 0; i < length; i++) {
        if (parents[i] == changeRoot) {
            parents[i] = targetRoot;
        }
    }
}

edge_t** spanningSubTree (graph_t* graph) {
    if (graph == NULL || graph->nodeCount < 2) {
        return NULL;
    }
    edge_t** subTree = malloc((graph->nodeCount - 1) * sizeof(edge_t*));
    if (subTree == NULL) {
        return NULL;
    }
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
            //set destination group's parent root as start node's group's parent root
            unionParents(parents[currEdge->start], parents[currEdge->des], parents, graph->nodeCount);
            //add edge to the result
            subTree[subIndex] = currEdge;
            subIndex++;
        }
        //end subtree generation
        if (subIndex == graph->nodeCount - 1) {
            break;
        }
    }
    return subTree;
}

graph_t* createGraph(int nodeC, int edgeC) {
    if (nodeC == 0) {
        return NULL;
    }
    graph_t* graph = malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }
    graph->edgeCount = edgeC;
    graph->nodeCount = nodeC;
    graph->edges = malloc(edgeC * sizeof(edge_t*));
    if (graph->edges == NULL) {
        free(graph);
        return NULL;
    }
    for (int i = 0; i < edgeC; i++) {
        graph->edges[i] = malloc(sizeof(edge_t));
        if (graph->edges[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(graph->edges[j]);
            }
            free(graph->edges);
            free(graph);
            return NULL;
        }
    }
    return graph;
}

void freeGraph(graph_t* graph) {
    if (graph == NULL) {
        return;
    }
    for (int i = 0; i < graph->edgeCount; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}