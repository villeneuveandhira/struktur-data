/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
Pohon Biner Bagi Angka (pbba22)
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    /*init*/
    tree T;
    data angka;

    /*input*/
    scanf("%d %d", &angka.num, &angka.div);

    makeTree(angka.num, angka.div, &T);
    addTree(T.root);

    /*output*/
    printTreeInOrder(T.root);
    printf("\n");

    return 0;
}