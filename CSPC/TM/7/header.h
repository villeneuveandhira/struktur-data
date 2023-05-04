/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 7
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    int nilai;
} data;
typedef struct elmt *elmtAddress;
typedef struct elmt {
    data container;
    elmtAddress next;
} element;
typedef struct {
    element *first;
    element *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], int nilai, queue *Q);
void addPriority(char nama[], int nilai, int prior, queue *Q);
void del(queue *src, queue *dest);
void printQueue(queue Q);