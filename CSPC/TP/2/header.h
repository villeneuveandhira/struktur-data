/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    char nama[99];
    int tgl_masuk;
    char kode[99];
} barang;
typedef struct elmt *elmt_Address;
typedef struct elmt {
    barang container;
    elmt_Address prev;
    elmt_Address next;
} element;
typedef struct {
    element *first;
    element *tail;
} list;

/*procedure OR function*/
// list
void create_List(list *L);
int count_Element(list L);
// add
void add_First(char nama[], int tgl_masuk, char kode[], list *L);
void add_After(element *before, char nama[], int tgl_masuk, char kode[], list *L);
void add_Last(char nama[], int tgl_masuk, char kode[], list *L);
// del
void del_First(list *L);
void del_After(element *before, list *L);
void del_Last(list *L);
// print
void print_Delete(list *L);
void print_Element(list L);
// sorting
void sort_Kode(list *L);
void sort_Tgl(list *L);