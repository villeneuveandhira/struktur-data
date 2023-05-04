#include "header.h"

void createEmpty(stack *S) {
    (*S).top = -1;
}

int isEmpty(stack S) {
    int result = 0;
    if (S.top == -1) {
        result = 1;
    }
    return result;
}

int isFull(stack S) {
    int result = 0;
    if (S.top == 9) {
        result = 1;
    }
    return result;
}

void push(char nim[], char nama[], float nilai, stack *S) {
    if (isFull(*S) == 1) {
        printf("stack penuh\n");
    } else {
        if (isEmpty(*S) == 1) {
            (*S).top = 0;
            strcpy((*S).data[0].nim, nim);
            strcpy((*S).data[0].nama, nama);
            (*S).data[0].nilai = nilai;
        } else {
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].nim, nim);
            strcpy((*S).data[(*S).top].nama, nama);
            (*S).data[(*S).top].nilai = nilai;
        }
    }
}

void pop(stack *S) {
    if ((*S).top == 0) {
        (*S).top = -1;
    } else {
        if ((*S).top != -1) {
            (*S).top = (*S).top - 1;
        }
    }
    /*else if ((*S).top == -1)
    {
        (*S).top -= 1;
        (*S).top = (*S).top - 1;
    }*/
    /*else
    {
        if ((*S).top == -1)
        {
            (*S).top--;
            (*S).top -= 1;
        }
    }*/
}

void printStack(stack S) {
    if (S.top != -1) {
        printf("------isi stack------\n");
        int i;
        for (i = S.top; i >= 0; i--) {
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", S.data[i].nim);
            printf("nama : %s\n", S.data[i].nama);
            printf("nilai : %f\n", S.data[i].nilai);
        }
        printf("---------------------\n");
    } else {
        printf("stack kosong\n");
    }
}