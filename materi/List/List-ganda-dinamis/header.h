#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[99];
    char nama[99];
    char nilai[99];
} nilaiMatKul;
typedef struct elmt *elmt_Address;
typedef struct elmt {
    nilaiMatKul container;
    elmt_Address prev;
    elmt_Address next;
} element;
typedef struct {
    element *first;
    element *tail;
} list;

void create_List(list *L);
int count_Element(list L);

void add_First(char nim[], char nama[], char nilai[], list *L);
void add_After(element *before, char nim[], char nama[], char nilai[], list *L);
void add_Last(char nim[], char nama[], char nilai[], list *L);

void del_First(list *L);
void del_After(element *before, list *L);
void del_Last(list *L);
void del_All(list *L);

void print_Element(list L);

void swap(list *L);