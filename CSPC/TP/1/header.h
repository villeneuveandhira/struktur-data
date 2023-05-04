/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

// library
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// declaration
typedef struct {
    char title[99];
    char artist[99];
    int no;
} lagu;
typedef struct elmt* elmt_Address;
typedef struct elmt {
    lagu container;
    elmt_Address next;
} element;
typedef struct {
    element* first;
} list;

// procedure or function declaration
void create_List(list* L);
int count_Element(list L);
void add_First(char title[], char artist[], int no, list* L);
void print_Element(list L);
void sorting(list* L, int x, int y);