/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 6
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    char nama[99];
    int harga;
} food;
typedef struct elmt *elmtAddress;
typedef struct elmt {
    food container;
    elmtAddress next;
} element;
typedef struct {
    element *top;
} stack;

/*procedures || functions*/
void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void popMove(stack *S, stack *dest);
void printStack(stack S);