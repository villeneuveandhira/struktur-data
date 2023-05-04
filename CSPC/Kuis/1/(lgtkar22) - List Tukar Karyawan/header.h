/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    int id;
    char nama[51];
    char bagian[101];
} karyawan;
typedef struct {
    karyawan container;
    int prev;
    int next;
} element;
typedef struct {
    int first;
    int tail;
    element data[100];
} list;

/*procedure OR function*/
// List
void create_List(list *L);
int count_Element(list L);
int empty_Element(list L);
// add
void add_First(int id, char nama[], char bagian[], list *L);
void add_After(int prev, int id, char nama[], char bagian[], list *L);
void add_Last(int id, char nama[], char bagian[], list *L);
// delete
void del_First(list *L);
void del_After(int prev, list *L);
void del_Last(list *L);
void del_All(list *L);
// print
void print_Element(list L);
// other
void swap(list *L1, list *L2);