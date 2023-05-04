/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 4
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    /* declaration */
    tree T;                                     // for tree
    char que[101], str1[101], str2[101];        // for input string
    int stop = 0, last = 0, i, n = 1, lvl = 0;  // for counter

    /* input */
    // menerima input hingga "DONE"
    while (stop == 0) {
        scanf("%s", &que);
        // selama query bukan "DONE"
        if (strcmp(que, "DONE;") != 0) {
            // MAKETREE pohon; : buat tree dengan nama pohon
            if (strcmp(que, "MAKETREE") == 0) {
                scanf("%s", &str1);
                last = strlen(str1);
                str1[last - 1] = '\0';
                makeTree(str1, &T);
            }
            // CHILD anak ortu; : buat child anak dari root ortu
            else if (strcmp(que, "CHILD") == 0) {
                scanf("%s %s", &str1, &str2);
                last = strlen(str2);
                str2[last - 1] = '\0';
                simpul *find = NULL;
                find = findSimpul(str2, T.root);
                if (find != NULL) {
                    addChild(str1, find);
                }
            }
            // DELLCHILD anak ortu; : hapus node anak dari root ortu
            else if (strcmp(que, "DELLCHILD") == 0) {
                scanf("%s %s", &str1, &str2);
                last = strlen(str2);
                str2[last - 1] = '\0';
                simpul *find = NULL;
                find = findSimpul(str2, T.root);
                if (find != NULL) {
                    delChild(str1, find);
                }
            }
            // PREORDER; : cetak tree preorder
            else if (strcmp(que, "PREORDER;") == 0) {
                printf("Output %d:\n", n);
                printf("=========\n");
                printTreePreOrder(T.root, lvl);
                n++;
            }
            stop = 0;
        }
        // DONE; : menutup query inputan
        else if (strcmp(que, "DONE;") == 0) {
            stop = 1;
        }
        // kondisi tetap menerima masukkan selain daftar query
        else {
            stop = 0;
        }
    }
    printf("=========\n");

    return 0;
}