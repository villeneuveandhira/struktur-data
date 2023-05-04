/*
Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// global variable
extern int max[201];

/*struct*/
typedef struct {
    char name[201];
    char num[201];
    char parent[201];
    int value;
    int idx;
    int flag;
    char component[201][201];
} data;
typedef struct nd *ndAddress;
typedef struct nd {
    data container;
    ndAddress sibling;
    ndAddress child;
} node;
typedef struct {
    node *root;
} tree;

/*procedures or functions*/
// tree
void makeTree(char name[], char num[], char parent[], int value, int idx, int flag, char comp[][201], tree *T);
// add tree
void addChild(char name[], char num[], char parent[], int value, int idx, int flag, char comp[][201], node *root);
// del tree
void delAll(node *root);
void delChild(char str[], node *root);
// other
node *findNode(char str[], node *root);
void distance(int total);
void printTreePreOrder(node *root, int count, int lvl);
void split(char str[], char cw[], char temp[]);
int toInt(char *str);
void depth(int deep, node *root);
void mark(int value, node *root);
void delMark(int idx, char list[][201], node *root);