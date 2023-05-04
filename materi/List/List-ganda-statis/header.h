#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    char nilai[2];
} nilaiMatKul;
typedef struct {
    nilaiMatKul kontainer;
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

void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(int prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);

void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list L);

void swap(list *L);