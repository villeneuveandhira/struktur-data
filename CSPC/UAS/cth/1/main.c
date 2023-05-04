/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
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
    insertTree(T.root);

    /*output*/
    printTreeInOrder(T.root);

    /*
    tree T;
    data number;
    int flag = 0;

    scanf("%d %d", &number.one, &number.two);

    makeTree(number.one, number.two, &T);
    addTree(T.root, &flag);

    printTreePreOrder(T.root);
    printf("\n");
    */

    return 0;
}