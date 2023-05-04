/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Tengah Semester
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    char kodeP[50];
    char namaP[50];
} perusahan;
typedef struct {
    char kodeO[50];
    char namaO[50];
    int bulan;
    int tahun;
    char jenis[20];
} obat;
typedef struct eClm *columnAddress;
typedef struct eClm {
    obat container_col;
    columnAddress next_col;
} eColumn;
typedef struct eR *rowAddress;
typedef struct eR {
    perusahan container;
    eColumn *col;
    rowAddress next;
} eRow;
typedef struct {
    eRow *first;
} list;

/*procedure or function*/
// list
void createList(list *L);
int countElementB(list L);
int countElementK(eRow L);
// add
void addFirstB(char kodeP[], char namaP[], list *L);
void addFirstK(char kodeO[], char namaO[], int bulan, int tahun, char jenis[], eRow *L);
void addAfterB(eRow *prev, char kodeP[], char namaP[]);
void addAfterK(eColumn *prev, char kodeO[], char namaO[], int bulan, int tahun, char jenis[]);
void addLastB(char kodeP[], char namaP[], list *L);
void addLastK(char kodeO[], char namaO[], int bulan, int tahun, char jenis[], eRow *L);
// del
void delFirstK(eRow *L);
void delAfterK(eColumn *prev);
void delLastK(eRow *L);
void delAllK(eRow *L);
void delFirstB(list *L);
void delAfterB(eRow *prev);
void delLastB(list *L);
void delAllB(list *L);
// print
void printElement(list L);
// other
eRow *searchRow(char kodeP[], list L);
void searchCopy(int bulan, int tahun, list *L);