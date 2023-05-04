/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
Graf Jalur Langsung Tak Langsung (gjltl22)
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
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

/*procedures or functions*/
void createEmpty(graph *G);
void addNode(char c, graph *G);
void addLane(node *begin, node *goal, int w);
node *findNode(char c, graph G);
void pathing(node *awal, char (*path)[][100], int *i, int *j, int *iterasi, int *flag, char tAwal, char tAkhir);