/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[99];
    char jenis_kelamin[99];
    char asal_buku[99];
} karakter;
typedef struct elmt* alamatelmt;
typedef struct elmt {
    karakter kontainer;
    alamatelmt next;
} elemen;
typedef struct {
    elemen* first;
} list;

void create_List(list* L);
int count_Element(list L);
void add_First(char nama[], char jenis_kelamin[], char asal_buku[], list* L);
void add_After(elemen* prev, char nama[], char jenis_kelamin[], char asal_buku[], list* L);
void add_Last(char nama[], char jenis_kelamin[], char asal_buku[], list* L);
void del_First(list* L);
void del_After(elemen* prev, list* L);
void del_Last(list* L);
void print_Element(list L);
void del_All(list* L);