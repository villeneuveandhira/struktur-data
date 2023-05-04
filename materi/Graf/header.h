#include <malloc.h>
#include <stdio.h>

typedef struct nd *nodeAddress;
typedef struct ln *laneAddress;
typedef struct nd {
    char container;
    nodeAddress next;
    laneAddress arc;
} node;
typedef struct ln {
    int container_lane;
    laneAddress next_lane;
    node *goal;
} lane;
typedef struct {
    node *first;
} graph;

void createEmpty(graph *G);
void addNode(char c, graph *G);
void addLane(node *begin, node *goal, int w);
node *findNode(char c, graph G);
void delLane(char ctujuan, node *begin);
void delAll(node *begin);
void delNode(char c, graph *G);
void printGraph(graph G);