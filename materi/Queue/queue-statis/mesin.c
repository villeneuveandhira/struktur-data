#include "header.h"

void createEmpty(queue *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q) {
    int result = 0;
    if (Q.first == -1) {
        result = 1;
    }
    return result;
}

int isFull(queue Q) {
    int result = 0;
    if (Q.last == 9) {
        result = 1;
    }
    return result;
}

void add(char nim[], char nama[], float nilai, queue *Q) {
    if (isEmpty(*Q) == 1) {
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].nilai = nilai;
    } else {
        if (isFull(*Q) != 1) {
            (*Q).last = (*Q).last + 1;
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
            (*Q).data[(*Q).last].nilai = nilai;
        } else {
            printf("queue penuh\n");
        }
    }
}

void del(queue *Q) {
    if ((*Q).last == 0) {
        (*Q).first = -1;
        (*Q).last = -1;
    } else {
        for (int i = ((*Q).first + 1); i <= (*Q).last; i++) {
            strcpy((*Q).data[i - 1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i - 1].nama, (*Q).data[i].nama);
            (*Q).data[i - 1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last = (*Q).last - 1;
    }
}

void printQueue(queue Q) {
    if (Q.first != -1) {
        printf("------isi queue------\n");
        for (int i = Q.last; i >= Q.first; i--) {
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", Q.data[i].nim);
            printf("nama : %s\n", Q.data[i].nama);
            printf("nilai : %f\n", Q.data[i].nilai);
        }
        printf("--------------------\n");
    } else {
        printf("queue kosong\n");
    }
}