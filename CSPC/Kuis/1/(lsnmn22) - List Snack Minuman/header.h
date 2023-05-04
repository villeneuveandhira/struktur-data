/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor _
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*struct*/
typedef struct {
    char type[101];
    char name[101];
    int price;
} perusahaan;
typedef struct elmt* element_Address;
typedef struct elmt {
    perusahaan data;
    element_Address next;
} element;
typedef struct {
    element* first;
} list;

/*procedure OR function*/
// List
void create_List(list* L);
int count_Element(list L);
// add
void add_First(char type[], char name[], int price, list* L);
void add_After(element* prev, char type[], char name[], int price, list* L);
void add_Last(char type[], char name[], int price, list* L);
// delete
void del_First(list* L);
void del_After(element* prev, list* L);
void del_Last(list* L);
void del_All(list* L);
// print
void print_Element(list L);
// other
element* get_Address(char type[], list L);
element* get_Last(list L);
element* get_Prev(element* point, list L);
void swap(element* A, element* B, list* L1, list* L2);