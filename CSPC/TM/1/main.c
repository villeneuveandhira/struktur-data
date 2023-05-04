/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    list L;
    char nama[99];
    char level[99];
    char asal_video_game[99];
    createlist(&L);

    scanf("%s %s %s", &nama, &level, &asal_video_game);
    addfirst(nama, level, asal_video_game, &L);
    scanf("%s %s %s", &nama, &level, &asal_video_game);
    addfirst(nama, level, asal_video_game, &L);
    scanf("%s %s %s", &nama, &level, &asal_video_game);
    addafter(L.first, nama, level, asal_video_game, &L);
    printelemen(L);
    printf("--------------------\n");

    dellast(&L);
    scanf("%s %s %s", &nama, &level, &asal_video_game);
    addafter(L.data[L.first].next, nama, level, asal_video_game, &L);
    scanf("%s %s %s", &nama, &level, &asal_video_game);
    addlast(nama, level, asal_video_game, &L);
    printelemen(L);
    printf("--------------------\n");

    delafter(L.data[L.first].next, &L);
    delfirst(&L);
    dellast(&L);
    printelemen(L);
    printf("--------------------\n");

    dellast(&L);
    printelemen(L);
    printf("--------------------\n");

    return 0;
}