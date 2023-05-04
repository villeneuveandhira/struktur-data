#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
} mahasiswa;
typedef struct {
    char kode[10];
    char nilai[2];
} matKul;
typedef struct eKlm* alamatKolom;
typedef struct eKlm {
    matKul container_Kol;
    alamatKolom next_Kol;
} eKolom;
typedef struct eBr* alamatBaris;
typedef struct eBr {
    mahasiswa container;
    eKolom* col;
    alamatBaris next;
} eBaris;
typedef struct {
    eBaris* first;
} list;

void create_List(list* L);
int countElement_Baris(list L);
int countElemen_Kolom(eBaris L);
void addFirst_Baris(char nim[], char nama[], list* L);
void addFirst_Kolom(char kode[], char nilai[], eBaris* L);
void addAfter_Baris(eBaris* prev, char nim[], char nama[]);
void addAfter_Kolom(eKolom* prev, char kode[], char nilai[]);
void addLast_Baris(char nim[], char nama[], list* L);
void addLast_Kolom(char kode[], char nilai[], eBaris* L);
void delFirst_Kolom(eBaris* L);
void delAfter_Kolom(eKolom* prev);
void delLast_Kolom(eBaris* L);
void delAll_Kolom(eBaris* L);
void delFirst_Baris(list* L);
void delAfter_Baris(eBaris* prev);
void delLast_Baris(list* L);
void dellAll_Baris(list* L);
void print_Element(list L);
