/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 9
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // declaration
    tree T;
    tree T2;
    data temp[100];
    char s[100][20];
    int i, count, mark = 0;

    // input
    for (i = 0; i < 9; i++) {
        scanf("%s %d", &temp[i].nama, &temp[i].nilai);
    }
    scanf("%s", &s[0]);

    // 1
    printf("Step 1:\n================\n");
    makeTree(temp[0], &T);
    addChild(temp[1], T.root);
    addChild(temp[2], T.root);
    addChild(temp[3], T.root);
    addChild(temp[4], T.root->child);
    addChild(temp[5], T.root->child);

    count = 0;
    nNode(T.root, &count);
    printTreePreOrder(T.root, &mark, count);
    mark = 0;
    printf("\n");
    printTreePostOrder(T.root, &mark, count);
    mark = 0;
    printf("\n");

    delChild(T.root->child->child->sibling->container.nama, T.root->child->child->sibling->container.nilai, T.root->child);

    count = 0;
    nNode(T.root, &count);
    printTreePreOrder(T.root, &mark, count);
    mark = 0;
    printf("\n");
    printTreePostOrder(T.root, &mark, count);
    mark = 0;
    printf("\n");

    addChild(temp[6], T.root->child->sibling);
    addChild(temp[7], T.root->child->sibling);
    addChild(temp[8], T.root->child->sibling->sibling);
    count = 0;
    nNode(T.root, &count);
    printTreePreOrder(T.root, &mark, count);
    printf("\n");

    // 2
    printf("Step 2:\n================\n");
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }

    // 3
    printf("Step 3:\n================\n");
    simpul *find = NULL;
    find = findSimpul(s[0], T.root->child->child);
    if (find != NULL) {
        printf("%s ditemukan\n", s[0]);
    } else {
        printf("%s tidak ditemukan\n", s[0]);
    }
    find = NULL;
    find = findSimpul(s[0], T.root->child->sibling);
    if (find != NULL) {
        printf("%s ditemukan\n", s[0]);
    } else {
        printf("%s tidak ditemukan\n", s[0]);
    }
    find = NULL;
    find = findSimpul(s[0], T.root);
    if (find != NULL) {
        printf("%s ditemukan\n", s[0]);
    } else {
        printf("%s tidak ditemukan\n", s[0]);
    }

    return 0;
}