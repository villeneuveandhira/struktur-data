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
void copyTree(node *root1, node **root2);
int isEqual(node *root1, node *root2);
int heightTree(node *root);
void printTreeLevelOrder(node *root, int level);