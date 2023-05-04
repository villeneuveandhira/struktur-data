/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 3
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // variable declaration
    stack S, Pedas, Manis;
    int n, i;
    data makanan;

    // setup stack
    createEmpty(&S);
    createEmpty(&Pedas);
    createEmpty(&Manis);

    // input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %s %d", &makanan.harga, &makanan.nama, &makanan.kalori);
        push(makanan.harga, makanan.nama, makanan.kalori, &S);
    }
    // filtering element
    popMove(&S, &Pedas, &Manis, n);

    // output
    printStack_Pedas(Pedas);
    printf("\n");
    printStack_Manis(Manis);

    return 0;
}