/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 5
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char label[99];
    char code[99];
} box;
typedef struct {
    char nama[99];
} barang;
typedef struct eKlm *alamatKolom;
typedef struct eKlm {
    barang kontainer_kol;
    alamatKolom next_kol;
} eKolom;
typedef struct eBr *alamatBaris;
typedef struct eBr {
    box kontainer;
    eKolom *col;
    alamatBaris next;
} eBaris;
typedef struct {
    eBaris *first;
} list;

/*procedure or function*/
// list
void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
// add
void addFirstB(char label[], char code[], list *L);
void addFirstK(char nama[], eBaris *L);
void addAfterB(eBaris *prev, char label[], char code[]);
void addAfterK(eKolom *prev, char nama[]);
void addLastB(char label[], char code[], list *L);
void addLastK(char nama[], eBaris *L);
// del
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
// print
void printElement(list L);