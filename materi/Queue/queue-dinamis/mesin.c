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

void add(char nim[], char nama[], float nilai, queue *Q) {
    element *new;
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nim, nim);
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

void del(queue *Q) {
    if ((*Q).first != NULL) {
        element *del = (*Q).first;
        if (countElement(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        } else {
            (*Q).first = (*Q).first->next;
            del->next = NULL;
        }
        free(del);
    }
}

void printQueue(queue Q) {
    if (Q.first != NULL) {
        printf("------isi queue------\n");
        element *point = Q.first;
        int i = 1;
        while (point != NULL) {
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", point->container.nim);
            printf("nama : %s\n", point->container.nama);
            printf("nilai : %f\n", point->container.nilai);
            point = point->next;
            i++;
        }
        printf("---------------------\n");
    } else {
        printf("queue kosong\n");
    }
}