/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

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

void add_First(char nama[], char jenis_kelamin[], char asal_buku[], list* L) {
    elemen* baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.jenis_kelamin, jenis_kelamin);
    strcpy(baru->kontainer.asal_buku, asal_buku);
    if ((*L).first == NULL) {
        baru->next = NULL;
    } else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void add_After(elemen* prev, char nama[], char jenis_kelamin[], char asal_buku[], list* L) {
    elemen* baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.jenis_kelamin, jenis_kelamin);
    strcpy(baru->kontainer.asal_buku, asal_buku);
    if (prev->next == NULL) {
        baru->next = NULL;
    } else {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void add_Last(char nama[], char jenis_kelamin[], char asal_buku[], list* L) {
    if ((*L).first == NULL) {
        /*jika List Kosong.*/
        add_First(nama, jenis_kelamin, asal_buku, L);
    } else {
        /*list tidak kosong,
        mencari elemen terakhir list*/
        elemen* prev = (*L).first;
        while (prev->next != NULL) {
            /*iterasi*/
            prev = prev->next;
        }
        add_After(prev, nama, jenis_kelamin, asal_buku, L);
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
            printf("%s - %s - %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.jenis_kelamin, tunjuk->kontainer.asal_buku);
            /*iterasi*/
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    } else {
        /*proses List Kosong.*/
        printf("List Kosong.\n");
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