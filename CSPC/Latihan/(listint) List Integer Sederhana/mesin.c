#include "header.h"

void create_List(list* L) {
    (*L).first = NULL;
}

int count_Element(list L) {
    int result = 0;
    if (L.first != NULL) {
        element* point;
        point = L.first;  // init
        while (point != NULL) {
            result = result + 1;
            point = point->next;
        }
    }
    return result;
}

void add_First(int angka, list* L) {
    element* new;
    new = (element*)malloc(sizeof(element));
    new->container.angka = angka;

    if ((*L).first == NULL) {
        new->next = NULL;
    } else {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void print_Element(list L) {
    if (L.first != NULL) {
        /*init*/
        element* point = L.first;
        int i = 1;
        while (point != NULL) {
            printf("%d\n", point->container.angka);
            point = point->next;
            i++;
        }
    }
}