/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void createlist(list *L) {
    (*L).first = -1;
    int i;

    for (i = 0; i < TOTAL; i++) {
        (*L).data[i].next = -2;
    }
}

int countelement(list L) {
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

    if (countelement(L) < TOTAL) {
        int ketemu = 0;

        int i = 0;
        while ((ketemu == 0) && (i < TOTAL)) {
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

void addfirst(char nama[], char level[], char asal_video_game[], list *L) {
    if (countelement(*L) < TOTAL) {
        int baru = emptyelemen(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.asal_video_game, asal_video_game);

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

void addafter(int prev, char nama[], char level[], char asal_video_game[], list *L) {
    if (countelement(*L) < TOTAL) {
        int baru = emptyelemen(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.asal_video_game, asal_video_game);

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

void addlast(char nama[], char level[], char asal_video_game[], list *L) {
    if ((*L).first == -1) {
        addfirst(nama, level, asal_video_game, L);
    } else {
        if (countelement(*L) < TOTAL) {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            }
            addafter(prev, nama, level, asal_video_game, L);
        } else {
            printf("sudah tidak dpt ditambah\n");
        }
    }
}

void delfirst(list *L) {
    if ((*L).first != -1) {
        int hapus = (*L).first;
        if (countelement(*L) == 1) {
            (*L).first = -1;
        } else {
            (*L).first = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    } else {
        printf("List Kosong.\n");
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
        if (countelement(*L) == 1) {
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
        printf("List Kosong.\n");
    }
}

void printelemen(list L) {
    if (L.first != -1) {
        int tunjuk = L.first;
        int i = 1;
        while (tunjuk != -1) {
            printf("- %s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.level, L.data[tunjuk].kontainer.asal_video_game);
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    } else {
        printf("List Kosong.\n");
    }
}