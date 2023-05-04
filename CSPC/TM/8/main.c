/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 8
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // binary tree
    tree T;

    // input
    char temp[14];
    for (int i = 0; i < 14; i++) {
        scanf(" %c", &temp[i]);
    }

    // add node(s)
    makeTree(temp[0], &T);
    addLeft(temp[1], T.root);
    addRight(temp[2], T.root);
    addLeft(temp[3], T.root->right);
    addRight(temp[4], T.root->left);
    addRight(temp[5], T.root->right);
    addLeft(temp[6], T.root->left->right);
    addRight(temp[7], T.root->right->left);
    addRight(temp[8], T.root->left->right);
    addRight(temp[9], T.root->right->right);
    addLeft(temp[10], T.root->right->right);
    addLeft(temp[11], T.root->left->right->left);
    addLeft(temp[12], T.root->right->left->right);
    addRight(temp[13], T.root->right->left->right);

    // process
    printf("Pre Order:\n");
    printTree(T.root, 1);
    printf("\n");

    delLeft(T.root->left->right->left);

    printf("In Order:\n");
    printTree(T.root, 2);
    printf("\n");

    delRight(T.root->right->right);

    printf("Post Order:\n");
    printTree(T.root, 3);
    printf("\n");

    return 0;
}