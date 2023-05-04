/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 8
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int counter = 0;

void makeTree(char c, tree *T) {
    node *new;
    new = (node *)malloc(sizeof(node));
    new->container = c;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
    new = NULL;
}

void addRight(char c, node *root) {
    if (root->right == NULL) {
        node *new;
        new = (node *)malloc(sizeof(node));
        new->container = c;
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    } else {
        printf("can't add.\n");
    }
}

void addLeft(char c, node *root) {
    if (root->left == NULL) {
        node *new;
        new = (node *)malloc(sizeof(node));
        new->container = c;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    } else {
        printf("can't add.\n");
    }
}

void delAll(node *root) {
    if (root != NULL) {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(node *root) {
    if (root != NULL) {
        if (root->right != NULL) {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(node *root) {
    if (root != NULL) {
        if (root->left != NULL) {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(node *root) {
    if (root != NULL) {
        if (counter != 0) {
            printf(" - ");
        }
        printf("%c", root->container);
        counter++;
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(node *root) {
    if (root != NULL) {
        printTreeInOrder(root->left);
        if (counter != 0) {
            printf(" - ");
        }
        printf("%c", root->container);
        counter++;
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(node *root) {
    if (root != NULL) {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        if (counter != 0) {
            printf(" - ");
        }
        printf("%c", root->container);
        counter++;
    }
}

void printTree(node *root, int x) {
    counter = 0;
    if (x == 1) {
        printTreePreOrder(root);
    } else if (x == 2) {
        printTreeInOrder(root);
    } else {
        printTreePostOrder(root);
    }
}