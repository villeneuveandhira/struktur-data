/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 2 nomor 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
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

int isFull(stack S, int flag) {
    int result = 0;
    if (flag == 0) {
        if (S.top == 50) {
            result = 1;
        }
    } else {
        if (S.top == 10) {
            result = 1;
        }
    }
    return result;
}

void push(char nama[], char kounter[], char daerah[], stack *S, int flag) {
    if (isFull(*S, flag) == 1) {
        printf("stack penuh\n");
    } else {
        if (isEmpty(*S) == 1) {
            (*S).top = 0;
            strcpy((*S).data[0].nama, nama);
            strcpy((*S).data[0].kounter, kounter);
            strcpy((*S).data[0].daerah, daerah);
        } else {
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].kounter, kounter);
            strcpy((*S).data[(*S).top].daerah, daerah);
        }
    }
}

void pop(stack *S) {
    if ((*S).top == 0) {
        (*S).top = -1;
    } else {
        if ((*S).top != -1) {
            (*S).top--;
        }
    }
}

void popAll(stack *S) {
    for (int i = (*S).top; i >= 0; i--) {
        pop(S);
    }
}

void printStack(stack S[], int n) {
    for (int x = 0; x < n; x++) {
        if (S[x].top != -1) {
            printf("stack %s\n", S[x].data[0].daerah);
            for (int i = 0; i <= S[x].top; i++) {
                printf("- %s %s %s\n", S[x].data[i].nama, S[x].data[i].kounter, S[x].data[i].daerah);
            }
            if (x < n - 1) {
                printf("\n");
            }
        } else {
            printf("stack kosong\n");
        }
    }
}

void move(stack *src, stack *dest, int m, int n, char nama[]) {
    for (int x = (*src).top; x >= 0; x--) {
        if (strcmp((*src).data[x].daerah, nama) == 0) {
            push((*src).data[x].nama, (*src).data[x].kounter, (*src).data[x].daerah, dest, 1);
        }
    }
}