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

graph_t* createGraph(int nodeC, int edgeC);
edge_t** spanningSubTree (graph_t* graph);
void freeGraph (graph_t* graph);