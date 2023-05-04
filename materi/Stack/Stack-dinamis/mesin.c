#include "header.h"

void createEmpty(stack *S) {
    (*S).top = NULL;
}

int isEmpty(stack S) {
    int result = 0;
    if (S.top == NULL) {
        result = 1;
    }
    return result;
}

int countElement(stack S) {
    int result = 0;
    if (S.top != NULL) {
        element *point;
        point = S.top;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

void push(char nim[], char nama[], float nilai, stack *S) {
    element *point;
    point = (element *)malloc(sizeof(element));
    strcpy(point->container.nim, nim);
    strcpy(point->container.nama, nama);
    point->container.nilai = nilai;
    if ((*S).top == NULL) {
        point->next = NULL;
    } else {
        point->next = (*S).top;
    }
    (*S).top = point;
    point = NULL;
}

void pop(stack *S) {
    if ((*S).top != NULL) {
        element *del = (*S).top;
        if (countElement(*S) == 1) {
            (*S).top == NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        del->next = NULL;
        free(del);
    } else {
        printf("stack kosong\n");
    }
}

element *popS(stack *S) {
    if ((*S).top != NULL) {
        element *del = (*S).top;
        if (countElement(*S) == 1) {
            (*S).top == NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        del->next = NULL;
        return del;
    } else {
        printf("stack kosong\n");
        return NULL;
    }
}

void printStack(stack S) {
    if (S.top != NULL) {
        printf("------isi stack------\n");
        element *point = S.top;
        int i = 1;
        while (point != NULL) {
            printf("=================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", point->container.nim);
            printf("nama : %s\n", point->container.nama);
            printf("nilai : %f\n", point->container.nilai);
            point = point->next;
            i++;
        }
        printf("---------------------\n");
    } else {
        printf("stack kosong\n");
    }
}