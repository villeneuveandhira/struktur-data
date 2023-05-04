#include "header.h"

// procedure to create list
void create_List(list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

// function to count element
int count_Element(list L) {
    int result = 0;
    if (L.first != NULL) {
        element *point;
        point = L.first;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

// procedure for add first
void add_First(char nim[], char nama[], char nilai[], list *L) {
    element *new;
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nim, nim);
    strcpy(new->container.nama, nama);
    strcpy(new->container.nilai, nilai);
    if ((*L).first == NULL) {
        new->prev = NULL;
        new->next = NULL;
        (*L).tail = new;
    } else {
        new->prev = (*L).first;
        new->next = NULL;
        (*L).first->prev = new;
    }
    (*L).first = new;
    new = NULL;
}

// procedure for add after
void add_After(element *before, char nim[], char nama[], char nilai[], list *L) {
    if (before != NULL) {
        element *new;
        new = (element *)malloc(sizeof(element));
        strcpy(new->container.nim, nim);
        strcpy(new->container.nama, nama);
        strcpy(new->container.nilai, nilai);
        if (before->next == NULL) {
            new->next = NULL;
            (*L).tail = new;
        } else {
            new->next = before->next;
            new->next->prev = new;
        }
        new->prev = before;
        before->next = new;
        new = NULL;
    }
}

// procedure for add last
void add_Last(char nim[], char nama[], char nilai[], list *L) {
    if ((*L).first == NULL) {
        add_First(nim, nama, nilai, L);
    } else {
        add_After((*L).tail, nim, nama, nilai, L);
    }
}

// procedure for del first
void del_First(list *L) {
    if ((*L).first != NULL) {
        element *del = (*L).first;
        if (countElement(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        } else {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            del->next = NULL;
        }
        free(del);
    }
}

// procedure for del after
void del_After(element *before, list *L) {
    element *del = before->next;
    if (del != NULL) {
        if (del->next == NULL) {
            L->tail = before;
            before->next = NULL;
        } else {
            before->next = del->next;
            del->next->prev = before;
        }
        del->prev = NULL;
        del->next = NULL;
    }
}

// procedure for del last
void del_Last(list *L) {
    if ((*L).first != NULL) {
        if (countElement(*L) == 1) {
            del_First(L);
        } else {
            del_After((*L).tail->prev, L);
        }
    } else {
        printf("List Kosong.\n");
    }
}

// procedure for del all
void del_All(list *L) {
    if (countElement(*L) != 0) {
        for (int i = countElement(*L); i >= 1; i--) {
            del_Last(L);
        }
    }
}

// procedure to print list
void print_Element(list L) {
    if (L.first != NULL) {
        element *point = L.first;
        int i = 1;
        while (point != NULL) {
            printf("element ke : %d\n", i);
            printf("nim : %s\n", point->container.nim);
            printf("nama : %s\n", point->container.nama);
            printf("nilai : %s\n", point->container.nilai);
            printf("------------\n");
            point = point->next;
            i = i + 1;
        }
    } else {
        printf("List Kosong.\n");
    }
}

void swap(list *L) {
    element *depan = (*L).first;
    element *belakang = (*L).tail;
    nilaiMatKul temp;

    for (int i = 0; i < countElement(*L) / 2; i++) {
        strcpy(temp.nama, depan->container.nama);
        strcpy(temp.nim, depan->container.nim);
        strcpy(temp.nilai, depan->container.nilai);

        strcpy(depan->container.nim, belakang->container.nim);
        strcpy(depan->container.nama, belakang->container.nama);
        strcpy(depan->container.nilai, belakang->container.nilai);

        strcpy(belakang->container.nilai, temp.nilai);
        strcpy(belakang->container.nama, temp.nama);
        strcpy(belakang->container.nim, temp.nim);

        depan = depan->next;
        belakang = belakang->prev;
    }
}