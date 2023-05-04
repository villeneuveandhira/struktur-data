/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 10
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp {
    char container;
    alamatsimpul next;
    alamatjalur arc;
} simpul;
typedef struct jlr {
    int container_lane;
    alamatjalur next_lane;
    simpul *goal;
} lane;
typedef struct
{
    simpul *first;
} graph;

void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *awal, simpul *goal, int beban);
simpul *findSimpul(char c, graph G);
void delJalur(char goal, simpul *awal);
void delAll(simpul *awal);
void delSimpul(char c, graph *G);
void printGraph(graph G);