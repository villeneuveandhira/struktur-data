/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 4
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void createList(list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L) {
    int hasil = 0;
    if (L.first != NULL) {
        elemen *bantu;

        bantu = L.first;
        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nama[], char nim[], char darah[], list *L) {
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->container.nama, nama);
    strcpy(baru->container.nim, nim);
    strcpy(baru->container.darah, darah);
    if ((*L).first == NULL) {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    } else {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *before, char nama[], char nim[], char darah[], list *L) {
    if (before != NULL) {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->container.nama, nama);
        strcpy(baru->container.nim, nim);
        strcpy(baru->container.darah, darah);
        if (before->next == NULL) {
            baru->next = NULL;
            (*L).tail = baru;
        } else {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen *after, char nama[], char nim[], char darah[], list *L) {
    if (after != NULL) {
        if (after == L->first) {
            addFirst(nama, nim, darah, L);
        } else {
            addAfter(after->prev, nama, nim, darah, L);
        }
    }
}

void addLast(char nama[], char nim[], char darah[], list *L) {
    if ((*L).first == NULL) {
        addFirst(nama, nim, darah, L);
    } else {
        addAfter((*L).tail, nama, nim, darah, L);
    }
}

void delFirst(list *L) {
    if ((*L).first != NULL) {
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        } else {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L) {
    elemen *hapus = before->next;
    if (hapus != NULL) {
        if (hapus->next == NULL) {
            L->tail = before;
            before->next = NULL;
        } else {
            before->next = hapus->next;
            hapus->next->prev = before;
        }
        hapus->prev = NULL;
        hapus->next = NULL;
    }
}

void delLast(list *L) {
    if ((*L).first != NULL) {
        if (countElement(*L) == 1) {
            delFirst(L);
        } else {
            delAfter((*L).tail->prev, L);
        }
    } else {
        printf("List Kosong\n");
    }
}

void delAll(list *L) {
    if (countElement(*L) != 0) {
        int i;
        for (i = countElement(*L); i >= 1; i--) {
            delLast(L);
        }
    }
}

void printElement(list L) {
    if (L.first != NULL) {
        elemen *bantu = L.first;
        int i = 1;
        while (bantu != NULL) {
            printf("%s %s %s\n", bantu->container.nama, bantu->container.nim, bantu->container.darah);
            bantu = bantu->next;
            i = i + 1;
        }
    } else {
        printf("List Kosong\n");
    }
}

void printElement_Reverse(list L) {
    if (L.tail != NULL) {
        elemen *bantu = L.tail;
        int i = 1;
        while (bantu != NULL) {
            printf("%s %s %s\n", bantu->container.nama, bantu->container.nim, bantu->container.darah);
            bantu = bantu->prev;
            i = i + 1;
        }
    } else {
        printf("List Kosong\n");
    }
}