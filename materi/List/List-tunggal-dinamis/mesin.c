#include "header.h"

void create_List(list* L) {
    (*L).first = NULL;
}

int count_Element(list L) {
    int hasil = 0;

    if (L.first != NULL) {
        /*list tidak kosong*/
        elemen* tunjuk;

        /*init*/
        tunjuk = L.first;
        while (tunjuk != NULL) {
            /*proses*/
            hasil = hasil + 1;
            /*iterasi*/
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void add_First(char nim[], char nama[], char nilai[], list* L) {
    elemen* baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);
    if ((*L).first == NULL) {
        baru->next = NULL;
    } else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void add_After(elemen* prev, char nim[], char nama[], char nilai[], list* L) {
    elemen* baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);
    if (prev->next == NULL) {
        baru->next = NULL;
    } else {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void add_Last(char nim[], char nama[], char nilai[], list* L) {
    if ((*L).first == NULL) {
        /*jika list kosong*/
        add_First(nim, nama, nilai, L);
    } else {
        /*list tidak kosong,
        mencari elemen terakhir list*/
        elemen* prev = (*L).first;
        while (prev->next != NULL) {
            /*iterasi*/
            prev = prev->next;
        }
        add_After(prev, nim, nama, nilai, L);
    }
}

void del_First(list* L) {
    if ((*L).first != NULL) {
        /*list tidak kosong*/
        elemen* hapus = (*L).first;
        if (count_Element(*L) == 1) {
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void del_After(elemen* prev, list* L) {
    elemen* hapus = prev->next;
    if (hapus != NULL) {
        if (hapus->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void del_Last(list* L) {
    if ((*L).first != NULL) {
        /*list tidak kosong*/
        if (count_Element(*L) == 1) {
            /*list terdiri dari satu elemen*/
            del_First(L);
        } else {
            /*mencari elemen terakhir list*/
            elemen* last = (*L).first;
            elemen* prev;
            while (last->next != NULL) {
                /*iterasi*/
                prev = last;
                last = last->next;
            }
            del_After(prev, L);
        }
    }
}

void print_Element(list L) {
    if (L.first != NULL) {
        /*list tidak kosong*/
        /*init*/
        elemen* tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL) {
            /*proses*/
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", tunjuk->kontainer.nim);
            printf("nama : %s\n", tunjuk->kontainer.nama);
            printf("nilai : %s\n", tunjuk->kontainer.nilai);
            printf("------------\n");
            /*iterasi*/
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    } else {
        /*proses list kosong*/
        printf("list kosong\n");
    }
}

void del_All(list* L) {
    if (count_Element(*L) != 0) {
        int i;
        for (i = count_Element(*L); i >= 1; i--) {
            /*proses menghapus elemen list*/
            del_Last(L);
        }
    }
}