/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 3
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    char tgl_Masuk[99];
    char jumlah[99];
} info_Hewan;
typedef struct {
    info_Hewan kontainer;
    int prev;
    int next;
} elemen;
typedef struct {
    int first;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);

void addFirst(char nama[], char tgl_Masuk[], char jumlah[], list *L);
void addAfter(int prev, char nama[], char tgl_Masuk[], char jumlah[], list *L);
void addLast(char nama[], char tgl_Masuk[], char jumlah[], list *L);

void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list L);
void printElement_Reverse(list L);