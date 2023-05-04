/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 7
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

void createEmpty(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q) {
    int result = 0;
    if (Q.first == NULL) {
        result = 1;
    }
    return result;
}

int countElement(queue Q) {
    int result = 0;
    if (Q.first != NULL) {
        element *point;
        point = Q.first;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

void add(char nama[], int nilai, queue *Q) {
    element *new;
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nama, nama);
    new->container.nilai = nilai;
    new->next = NULL;
    if ((*Q).first == NULL) {
        (*Q).first = new;
    } else {
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

void addPriority(char nama[], int nilai, int prior, queue *Q) {
    element *new;
    element *point = (*Q).first;
    int i = 0;
    while ((i < prior - 2) && (point != NULL)) {
        point = point->next;
        i++;
    }
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nama, nama);
    new->container.nilai = nilai;
    new->next = NULL;
    if (prior == 1) {
        if ((*Q).first == NULL) {
            (*Q).first = new;
        } else {
            new->next = point;
            (*Q).first = new;
        }
    } else {
        if (prior > countElement(*Q)) {
            (*Q).last->next = new;
        } else {
            new->next = point->next;
            point->next = new;
        }
    }
    if (new->next == NULL) {
        (*Q).last = new;
    }
    new = NULL;
}

void del(queue *src, queue *dest) {
    if ((*src).first != NULL) {
        element *del = (*src).first;
        if (countElement(*src) == 1) {
            (*src).first = NULL;
            (*src).last = NULL;
        } else {
            (*src).first = (*src).first->next;
            del->next = NULL;
        }
        add(del->container.nama, del->container.nilai, dest);
        free(del);
    }
}

void printQueue(queue Q) {
    if (Q.first != NULL) {
        element *point = Q.first;
        while (point != NULL) {
            printf("%s %d\n", point->container.nama, point->container.nilai);
            point = point->next;
        }
    }
}
