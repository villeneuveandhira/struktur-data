/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor _
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void createlist(list *L) {
    (*L).first = -1;
    int i;

    for (i = 0; i < 10; i++) {
        (*L).data[i].next = -2;
    }
}

int countelemen(list L) {
    int hasil = 0;
    if (L.first != -1) {
        int hitung;
        hitung = L.first;

        while (hitung != -1) {
            {
                hasil++;

                hitung = L.data[hitung].next;
            }
        }
        return hasil;
    }
}
int emptyelemen(list L) {
    int hasil = -1;

    if (countelemen(L) < 10) {
        int ketemu = 0;

        int i = 0;
        while ((ketemu == 0) && (i < 10)) {
            if (L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            } else {
                i++;
            }
        }
    }
    return hasil;
}

void addfirst(char nim[], char nama[], char nilai[], list *L) {
    if (countelemen(*L) < 10) {
        int baru = emptyelemen(*L);
        strcpy((*L).data[baru].conta.nim, nim);
        strcpy((*L).data[baru].conta.nama, nama);
        strcpy((*L).data[baru].conta.nilai, nilai);

        if ((*L).first == -1) {
            (*L).data[baru].next = -1;
        } else {
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    } else {
        printf("sudah tidak dpt ditambah\n");
    }
}

void addafter(int prev, char nim[], char nama[], char nilai[], list *L) {
    if (countelemen(*L) < 10) {
        int baru = emptyelemen(*L);
        strcpy((*L).data[baru].conta.nim, nim);
        strcpy((*L).data[baru].conta.nama, nama);
        strcpy((*L).data[baru].conta.nilai, nilai);

        if ((*L).data[prev].next == -1) {
            (*L).data[baru].next = -1;
        } else {
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    } else {
        printf("sudah tidak dpt ditambah\n");
    }
}

void addlast(char nim[], char nama[], char nilai[], list *L) {
    if ((*L).first == -1) {
        addfirst(nim, nama, nilai, L);
    } else {
        if (countelemen(*L) < 10) {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            }
            addafter(prev, nim, nama, nilai, L);
        } else {
            printf("sudah tidak dpt ditambah\n");
        }
    }
}

void delfirst(list *L) {
    if ((*L).first != -1) {
        int hapus = (*L).first;
        if (countelemen(*L) == 1) {
            (*L).first = -1;
        } else {
            (*L).first = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    } else {
        printf("list kosong\n");
    }
}

void delafter(int prev, list *L) {
    int hapus = (*L).data[prev].next;

    if (hapus != -1) {
        if ((*L).data[hapus].next == -1) {
            (*L).data[prev].next = -1;
        } else {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void dellast(list *L) {
    if ((*L).first != -1) {
        if (countelemen(*L) == 1) {
            delfirst(L);
        } else {
            int hapus = (*L).first;
            int prev;
            while ((*L).data[hapus].next != -1) {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            delafter(prev, L);
        }
    } else {
        printf("list kosong\n");
    }
}

void printelemen(list L) {
    if (L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1) {
            printf("Element ke : %d\n", i);
            printf("NIM     : %s\n", L.data[tunjuk].conta.nim);
            printf("Nama    : %s\n", L.data[tunjuk].conta.nama);
            printf("Nilai   : %s\n", L.data[tunjuk].conta.nilai);
            printf("NEXT    : %d\n", L.data[tunjuk].next);
            printf("----------------------------------------------------------------\n");

            tunjuk = L.data[tunjuk].next;
            i++;
        }
    } else {
        printf("list kosong\n");
    }
}

void delall(list *L) {
    int i;
    for (i = countelemen(*L); i >= 1; i--) {
        dellast(L);
    }
}