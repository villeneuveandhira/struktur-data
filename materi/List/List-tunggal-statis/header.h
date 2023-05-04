/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor _
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*Library*/
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    char nim[10];
    char nama[50];
    char nilai[2];
} inidiganti;
typedef struct {
    inidiganti conta;
    int next;
} elemen;
typedef struct {
    int first;
    elemen data[10];
} list;