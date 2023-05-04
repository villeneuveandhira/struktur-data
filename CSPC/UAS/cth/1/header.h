/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>

/*struct*/
typedef struct {
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
void delAll(node *root);
void delRight(node *root);
void delLeft(node *root);
void printTreePreOrder(node *root);
void printTreeInOrder(node *root);
void printTreePostOrder(node *root);
void copyTree(node *root1, node **root2);
int isEqual(node *root1, node *root2);
int heightTree(node *root);
void printTreeLevelOrder(node *root, int level);
void addTree(node *root, int *flag);
void insertTree(node *root);