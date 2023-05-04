/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 6
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
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

void push(char nama[], int harga, stack *S) {
    element *point;
    point = (element *)malloc(sizeof(element));
    strcpy(point->container.nama, nama);
    point->container.harga = harga;
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
            (*S).top = NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        del->next = NULL;
        free(del);
    }
}

void popMove(stack *S, stack *dest) {
    if ((*S).top != NULL) {
        element *del = (*S).top;
        if (countElement(*S) == 1) {
            (*S).top = NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        push(del->container.nama, del->container.harga, dest);
        del->next = NULL;
        free(del);
    }
}

void printStack(stack S) {
    if (S.top != NULL) {
        element *point = S.top;
        int i = 1;
        while (point != NULL) {
            printf("%d. %s\n", i, point->container.nama);
            point = point->next;
            i++;
        }
    } else {
        printf("- Stack Kosong\n");
    }
}