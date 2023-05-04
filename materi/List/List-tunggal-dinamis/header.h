#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    char nilai[2];
} nilai_Matkul;
typedef struct elmt* alamatelmt;
typedef struct elmt {
    nilai_Matkul kontainer;
    alamatelmt next;
} elemen;
typedef struct {
    elemen* first;
} list;

void create_List(list* L);
int count_Element(list L);
void add_First(char nim[], char nama[], char nilai[], list* L);
void add_After(elemen* prev, char nim[], char nama[], char nilai[], list* L);
void add_Last(char nim[], char nama[], char nilai[], list* L);
void del_First(list* L);
void del_After(elemen* prev, list* L);
void del_Last(list* L);
void print_Element(list L);
void del_All(list* L);