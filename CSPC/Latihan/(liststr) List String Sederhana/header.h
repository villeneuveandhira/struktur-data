#include <malloc.h>
#include <stdio.h>
#include <string.h>

// vaiable struct declaration
typedef struct {
    char str[99];
} input;
typedef struct elmt* alamatelmt;
typedef struct elmt {
    input container;
    alamatelmt next;
} element;
typedef struct {
    element* first;
} list;

// procedure or funciton declaration
void create_List(list* L);
int count_Element(list L);
void add_First(char str[], list* L);
void print_Element(list L);