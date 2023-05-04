/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 2 nomor 2
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

void add(char nama[], int urut, int smt, queue *Q) {
    element *new;
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nama, nama);
    new->container.urut = urut;
    new->container.smt = smt;
    new->next = NULL;
    if ((*Q).first == NULL) {
        (*Q).first = new;
    } else {
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

void addPriority(char nama[], int prior, int smt, queue *Q) {
    element *new;
    element *point = (*Q).first;
    int i = 0;
    while ((i < prior - 2) && (point != NULL)) {
        point = point->next;
        i++;
    }
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nama, nama);
    new->container.urut = prior;
    new->container.smt = smt;
    new->next = NULL;
    if (prior == 1) {
        if ((*Q).first == NULL) {
            (*Q).first = new;
        } else {
            new->next = point;
            (*Q).first = new;
        }
    } else {
        if ((*Q).first == NULL) {
            (*Q).first = new;
        } else if (prior > countElement(*Q)) {
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

void del(queue *src) {
    if ((*src).first != NULL) {
        element *del = (*src).first;
        if (countElement(*src) == 1) {
            (*src).first = NULL;
            (*src).last = NULL;
        } else {
            (*src).first = (*src).first->next;
            del->next = NULL;
        }
        free(del);
    }
}

void printQueue(queue Q) {
    if (Q.first != NULL) {
        element *point = Q.first;
        while (point != NULL) {
            printf("%s %d %d\n", point->container.nama, point->container.urut, point->container.smt);
            point = point->next;
        }
    } else {
        printf("queue kosong\n");
    }
}

void move(queue *src, queue *dest, int n) {
    element *point;
    for (int i = 0; i < n; i++) {
        point = (*src).first;
        add(point->container.nama, point->container.urut, point->container.smt, dest);
        del(src);
    }
}