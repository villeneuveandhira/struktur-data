/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 8
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>

typedef struct nd *nodeAddress;
typedef struct nd {
    char container;
    nodeAddress right;
    nodeAddress left;
} node;
typedef struct {
    node *root;
} tree;

void makeTree(char c, tree *T);
void addRight(char c, node *root);
void addLeft(char c, node *root);
void delAll(node *root);
void delRight(node *root);
void delLeft(node *root);
void printTreePreOrder(node *root);
void printTreeInOrder(node *root);
void printTreePostOrder(node *root);
void printTree(node *root, int x);