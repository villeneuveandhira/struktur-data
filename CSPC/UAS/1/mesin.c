/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
Pohon Biner Bagi Angka (pbba22)
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// to make space in between node
int counter = 0;

/*make tree*/
void makeTree(int num, int div, tree *T) {
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->container.num = num;
    newNode->container.div = div;
    newNode->right = NULL;
    newNode->left = NULL;
    (*T).root = newNode;
    newNode = NULL;
}

/*add left*/
void addLeft(int num, int div, node *root) {
    // if sub-tree->left is empty
    if (root->left == NULL) {
        node *newNode;
        newNode = (node *)malloc(sizeof(node));
        newNode->container.num = num;
        newNode->container.div = div;
        newNode->right = NULL;
        newNode->left = NULL;
        root->left = newNode;
    }
}

/*add right*/
void addRight(int num, int div, node *root) {
    // if sub-tree->right is empty
    if (root->right == NULL) {
        node *newNode;
        newNode = (node *)malloc(sizeof(node));
        newNode->container.num = num;
        newNode->container.div = div;
        newNode->right = NULL;
        newNode->left = NULL;
        root->right = newNode;
    }
}

/*in order*/
void printTreeInOrder(node *root) {
    // jika pohon tidak kosong
    if (root != NULL) {
        printTreeInOrder(root->left);
        // untuk spasi
        if (counter != 0) {
            printf(" ");
        }
        printf("%d", root->container.num);
        counter++;
        printTreeInOrder(root->right);
    }
}

/*add process*/
void addTree(node *root) {
    // jika pohon tidak kosong
    if (root != NULL) {
        // init
        int angka, pembagi, result = 0;
        node *newNode = root;
        // set int from data
        angka = newNode->container.num;
        pembagi = newNode->container.div;
        // dividing
        result = angka / pembagi;
        // pembagian berhenti jika sudah lebih kecil dari 1
        if (result > 0) {
            // jika ganjil add left
            if (result % 2 != 0) {
                addLeft(result, pembagi, root);
            }
            // jika genap add right
            else if (result % 2 == 0) {
                addRight(result, pembagi, root);
            }
        }
        // recursive
        addTree(root->left);
        addTree(root->right);
    }
}