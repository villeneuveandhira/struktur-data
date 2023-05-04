/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 2 nomor 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    char kounter[99];
    char daerah[99];
} data;
typedef struct {
    int top;
    data data[51];
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S, int flag);
void push(char nim[], char nama[], char kota[], stack *S, int flag);
void pop(stack *S);
void popAll(stack *S);
void printStack(stack S[], int n);
void move(stack *src, stack *dest, int m, int n, char nama[]);