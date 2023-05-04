/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 2 nomor 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    int urut;
    int smt;
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
void add(char nama[], int urut, int smt, queue *Q);
void addPriority(char nama[], int urut, int smt, queue *Q);
void del(queue *src);
void printQueue(queue Q);
void move(queue *src, queue *dest, int n);