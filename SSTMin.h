typedef struct Edge {
    //start node index (start with 0)
    int start;
    //destination node index
    int des;
    //weight of the edge
    int weight;
} edge_t;

typedef struct Graph {
    int nodeCount;
    int edgeCount;
    //Array of edges
    edge_t** edges;
} graph_t;

graph_t* createGraph(int nodeC, int edgeC) {
    if (nodeC == 0) {
        return NULL;
    }
    edge_t** edgesArray = malloc(sizeof(edge_t) * edgeC);
    if (edgesArray == NULL) {
        return NULL;
    } 
    graph_t* graph = malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }
    graph->edgeCount = edgeC;
    graph->nodeCount = nodeC;
    graph->edges = edgesArray;
}

edge_t* spanningSubTree (graph_t* graph);
void freeGraph (graph_t* graph);