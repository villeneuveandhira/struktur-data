#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatKul;
typedef struct elmt *elmtAddress;
typedef struct elmt {
    nilaiMatKul container;
    elmtAddress next;
} element;
typedef struct {
    element *first;
    element *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char[], char[], float, queue *Q);
void del(queue *Q);
void printQueue(queue Q);