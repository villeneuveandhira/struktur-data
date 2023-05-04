/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 4
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    char nim[99];
    char darah[99];
} gol_Darah;
typedef struct elmt *alamatelmt;
typedef struct elmt {
    gol_Darah container;
    alamatelmt prev;
    alamatelmt next;
} elemen;
typedef struct {
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);

void addFirst(char nama[], char nim[], char darah[], list *L);
void addAfter(elemen *before, char nama[], char nim[], char darah[], list *L);
void addBefore(elemen *after, char nama[], char nim[], char darah[], list *L);
void addLast(char nama[], char nim[], char darah[], list *L);

void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list L);
void printElement_Reverse(list L);