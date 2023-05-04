/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    list L;
    char nama[99];
    char jenis_kelamin[99];
    char asal_buku[99];
    create_List(&L);

    printf("--------------------\n");
    scanf("%s %s %s", &nama, &jenis_kelamin, &asal_buku);
    add_Last(nama, jenis_kelamin, asal_buku, &L);
    scanf("%s %s %s", &nama, &jenis_kelamin, &asal_buku);
    add_First(nama, jenis_kelamin, asal_buku, &L);
    scanf("%s %s %s", &nama, &jenis_kelamin, &asal_buku);
    add_After(L.first->next, nama, jenis_kelamin, asal_buku, &L);
    print_Element(L);
    printf("--------------------\n");

    del_After(L.first->next, &L);
    del_First(&L);
    print_Element(L);
    printf("--------------------\n");

    scanf("%s %s %s", &nama, &jenis_kelamin, &asal_buku);
    add_Last(nama, jenis_kelamin, asal_buku, &L);
    scanf("%s %s %s", &nama, &jenis_kelamin, &asal_buku);
    add_First(nama, jenis_kelamin, asal_buku, &L);
    del_Last(&L);
    print_Element(L);
    printf("--------------------\n");

    del_All(&L);
    print_Element(L);
    printf("--------------------\n");

    scanf("%s %s %s", &nama, &jenis_kelamin, &asal_buku);
    add_Last(nama, jenis_kelamin, asal_buku, &L);
    print_Element(L);
    printf("--------------------\n");

    return 0;
}