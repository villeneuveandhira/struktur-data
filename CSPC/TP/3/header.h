/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 3
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    int harga;
    char nama[99];
    int kalori;
} data;
typedef struct elmt *elmtAddress;
typedef struct elmt {
    data container;
    elmtAddress next;
} element;
typedef struct {
    element *top;
} stack;

/*procedures OR functions*/
void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(int harga, char nama[], int kalori, stack *S);
void pop(stack *S);
void popMove(stack *S, stack *satu, stack *dua, int n);
void printStack_Pedas(stack S);
void printStack_Manis(stack S);