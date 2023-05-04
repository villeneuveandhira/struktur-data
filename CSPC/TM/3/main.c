/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 3
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    char nama[99];
    char tgl_Masuk[99];
    char jumlah[99];
    list L;
    createList(&L);
    printf("Data Kebun Binatang\n");

    printf("===================\n");
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addFirst(nama, tgl_Masuk, jumlah, &L);
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addLast(nama, tgl_Masuk, jumlah, &L);
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addAfter(L.first, nama, tgl_Masuk, jumlah, &L);
    printElement(L);

    printf("===================\n");
    delAfter(L.data[L.first].next, &L);
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addAfter(L.first, nama, tgl_Masuk, jumlah, &L);
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addAfter(L.data[L.tail].prev, nama, tgl_Masuk, jumlah, &L);
    delFirst(&L);
    printElement(L);

    printf("===================\n");
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addFirst(nama, tgl_Masuk, jumlah, &L);
    scanf("%s %s %s", &nama, &tgl_Masuk, &jumlah);
    addAfter(L.data[L.first].next, nama, tgl_Masuk, jumlah, &L);
    delLast(&L);
    printElement_Reverse(L);

    printf("===================\n");
    delAll(&L);
    printElement(L);

    return 0;
}