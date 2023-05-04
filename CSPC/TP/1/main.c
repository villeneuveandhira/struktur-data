/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    /* create list */
    list L;
    create_List(&L);

    /* variable declaration */
    char title[99];
    char artist[99];
    int no;
    char sort[99];
    char type[99];

    /* input user */
    do {  // looping as long as the title is not '-'
        scanf("%s", &title);
        if (strcmp(title, "-") != 0) {
            scanf("%s %d", &artist, &no);
            add_First(title, artist, no, &L);  // add at the beginning of the list
        }
    } while (strcmp(title, "-") != 0);
    scanf("%s", &sort);  // sorting title or number
    scanf("%s", &type);  // ascending or descending

    /*
        sorting (list, x, y);
        x :
            0 = judul
            1 = nomor
        y :
            0 = ascending
            1 = descending
    */
    if (strcmp(sort, "judul") == 0) {
        if (strcmp(type, "asc") == 0) {
            sorting(&L, 0, 0);
        } else if (strcmp(type, "desc") == 0) {
            sorting(&L, 0, 1);
        }
    } else if (strcmp(sort, "nomor") == 0) {
        if (strcmp(type, "asc") == 0) {
            sorting(&L, 1, 0);
        } else if (strcmp(type, "desc") == 0) {
            sorting(&L, 1, 1);
        }
    }

    return 0;
}