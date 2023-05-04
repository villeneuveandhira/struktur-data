/*
Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan remedial dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    char nama[99];
    int banyak;
} peserta;
typedef struct {
    char namaBahan[99];
    int berat;
} bahan;
typedef struct eKlm* alamatKolom;
typedef struct eKlm {
    bahan container_Kol;
    alamatKolom next_Kol;
} eKolom;
typedef struct eBr* alamatBaris;
typedef struct eBr {
    peserta container;
    eKolom* col;
    alamatBaris next;
} eBaris;
typedef struct {
    eBaris* first;
} list;

void create_List(list* L);
int countElement_Baris(list L);
int countElemen_Kolom(eBaris L);
void addFirst_Baris(char nama[], int banyak, list* L);
void addFirst_Kolom(char namaBahan[], int berat, eBaris* L);
void addAfter_Baris(eBaris* prev, char nama[], int banyak);
void addAfter_Kolom(eKolom* prev, char namaBahan[], int berat);
void addLast_Baris(char nama[], int banyak, list* L);
void addLast_Kolom(char namaBahan[], int berat, eBaris* L);
void delFirst_Kolom(eBaris* L);
void delAfter_Kolom(eKolom* prev);
void delLast_Kolom(eBaris* L);
void delAll_Kolom(eBaris* L);
void delFirst_Baris(list* L);
void delAfter_Baris(eBaris* prev);
void delLast_Baris(list* L);
void dellAll_Baris(list* L);
void print_Element(list L);
eBaris* findData(char nama[], list L);
eKolom* findBahan(char nama[], eBaris* peserta);
void move(eBaris* point, eKolom* data, char nama[], char namaBahan[], list* L);
// void searchCopy(char cari[], char namaBahan[], list* L);