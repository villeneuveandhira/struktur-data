/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 4
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    char nama[99];
    char nim[99];
    char darah[99];
    list L;
    createList(&L);

    printf("Data Golongan Darah\n");
    printf("===================\n");

    scanf("%s %s %s", &nama, &nim, &darah);
    addLast(nama, nim, darah, &L);
    scanf("%s %s %s", &nama, &nim, &darah);
    addFirst(nama, nim, darah, &L);
    scanf("%s %s %s", &nama, &nim, &darah);
    addBefore(L.first->next, nama, nim, darah, &L);
    printElement(L);
    printf("===================\n");

    scanf("%s %s %s", &nama, &nim, &darah);
    addAfter(L.first->next, nama, nim, darah, &L);
    delAfter(L.first, &L);
    scanf("%s %s %s", &nama, &nim, &darah);
    addAfter(L.first, nama, nim, darah, &L);
    scanf("%s %s %s", &nama, &nim, &darah);
    addBefore(L.tail, nama, nim, darah, &L);
    delFirst(&L);
    printElement(L);
    printf("===================\n");

    delLast(&L);
    delAfter(L.first, &L);
    scanf("%s %s %s", &nama, &nim, &darah);
    addLast(nama, nim, darah, &L);
    printElement_Reverse(L);
    printf("===================\n");

    delAll(&L);
    printElement(L);

    return 0;
}