/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
Pohon Biner Bagi Angka (pbba22)
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>

/*struct*/
typedef struct {
    // angka dan pembagi
    int num;
    int div;
} data;
typedef struct nd *nodeAddress;
typedef struct nd {
    data container;
    nodeAddress right;
    nodeAddress left;
} node;
typedef struct {
    node *root;
} tree;

/*procedures or function*/
void makeTree(int num, int div, tree *T);
void addLeft(int num, int div, node *root);
void addRight(int num, int div, node *root);
void printTreeInOrder(node *root);
void addTree(node *root);