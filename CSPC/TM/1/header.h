/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

#define TOTAL 5

typedef struct {
    char nama[99];
    char level[99];
    char asal_video_game[99];
} karakter;
typedef struct {
    karakter kontainer;
    int next;
} element;
typedef struct {
    int first;
    element data[5];
} list;

void createlist(list *L);
int countelement(list L);
int emptyelemen(list L);
void addfirst(char nama[], char level[], char asal_video_game[], list *L);
void addafter(int prev, char nama[], char level[], char asal_video_game[], list *L);
void addlast(char nama[], char level[], char asal_video_game[], list *L);
void delfirst(list *L);
void delafter(int prev, list *L);
void dellast(list *L);
void printelemen(list L);