/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 5
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>

/*struct*/
typedef struct nd *nodeAddress;
typedef struct ln *laneAddress;
typedef struct nd {
    char container;
    int visited;
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

/*procedures or functions*/
void createEmpty(graph *G);
node *findNode(char c, graph G);
void addNode(char c, graph *G);
void addLane(node *begin, node *goal, int w);
void findPath(graph G, node *begin, char path[], int index, int visited[], char endPath, int range);