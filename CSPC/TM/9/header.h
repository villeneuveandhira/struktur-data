/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 9
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    int nilai;
} data;
typedef struct smp *alamatsimpul;
typedef struct smp {
    data container;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;
typedef struct {
    simpul *root;
} tree;

void makeTree(data pohon, tree *T);
void addChild(data pohon, simpul *root);
void delAll(simpul *root);
void delChild(char nama[], int nilai, simpul *root);
simpul *findSimpul(char nama[], simpul *root);
void nNode(simpul *root, int *n);
void printTreePreOrder(simpul *root, int *mark, int n);
void printTreePostOrder(simpul *root, int *mark, int n);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);