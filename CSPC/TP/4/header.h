/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 4
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// struct
typedef struct smp *alamatsimpul;
typedef struct smp {
    char container[101];
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;
typedef struct {
    simpul *root;
} tree;

// procedures or functions
void makeTree(char pohon[], tree *T);
void addChild(char pohon[], simpul *root);
void delAll(simpul *root);
void delChild(char nama[], simpul *root);
simpul *findSimpul(char nama[], simpul *root);
void printTreePreOrder(simpul *root, int lvl);